## 概述
epoll全称eventpoll，是Linux内核实现IO多路复用的一种机制。IO 多路复用的意思是在一个操作里同时监听多个文件描述符，在其中一个或多个文件描述符可用的时候返回，然后对其进行读写操作。epoll是select和poll的升级版，相较于这两个前辈，epoll改进了工作方式，因此它更加高效。
- 对于待检测集合，select/poll是基于线性方式处理的，epoll是基于**红黑树**来管理待检测集合的；
- select/poll每次都会线性扫描整个待检测集合，集合越大速度越慢，epoll使用的是回调机制，效率高，处理效率也不会随着检测集合的变大而下降；
- select/poll工作过程中存在内核空间与用户空间数据的频繁拷贝问题，在epoll中内核和用户区使用的是共享内存（基于mmap内存映射区实现），省去了不必要的内存拷贝。
- 程序员需要对select和poll返回的集合进行判断才能知道哪些文件描述符是就绪的，通过epoll可以直接得到已就绪的文件描述符集合，无需再次检测；
- 使用 epoll 没有最大文件描述符的限制，仅受系统中进程能打开的最大文件数目限制。

当多路复用的文件数量庞大、IO流量频繁的时候，一般不太适合使用select和poll，这种情况下select和poll表现较差，推荐使用 epoll。

## epoll API
在epoll中一共提供是三个API函数，分别处理不同的操作，函数原型如下：
```c
#include <sys/epoll.h>

// 创建epoll实例，通过一棵红黑树管理待检测集合
int epoll_create(int size);

// 管理红黑树上的文件描述符(添加、修改、删除)
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

// 检测epoll红黑树中是否有就绪的文件描述符
int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);
```

select/poll低效的原因之一是将 “添加/维护待检测任务” 和 “阻塞进程/线程” 两个步骤合二为一。每次调用 select 都需要这两步操作，然而大多数应用场景中，需要监视的socket个数相对固定，并不需要每次都修改。epoll将这两个操作分开，先用 epoll_ctl()维护等待队列，再调用epoll_wait()阻塞进程（解耦），从而使epoll的效率得到了提升。


epoll_create() 函数的作用是创建一个红黑树模型的实例，用于管理待检测的文件描述符的集合。
```c
int epoll_create(int size);
```
- 函数参数 size：在 Linux 内核 2.6.8 版本以后，这个参数是被忽略的，只需要指定一个大于 0 的数值就可以了。
- 函数返回值：
    - 失败：返回 - 1;
    - 成功：返回一个有效的文件描述符，通过这个文件描述符就可以访问创建的 epoll 实例了。

epoll_ctl() 函数的作用是管理红黑树实例上的节点，可以进行添加、删除、修改操作。
```c
// 联合体, 多个变量共用同一块内存        
typedef union epoll_data {
 	void        *ptr;
	int          fd;	// 通常情况下使用这个成员, 和epoll_ctl的第三个参数相同即可
	uint32_t     u32;
	uint64_t     u64;
} epoll_data_t;

struct epoll_event {
	uint32_t     events;      /* Epoll events */
	epoll_data_t data;        /* User data variable */
};
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
```
- 函数参数
    - epfd：epoll_create()函数的返回值，通过这个参数找到epoll实例；
    - op：这是一个枚举值，控制通过该函数执行什么操作
        - EPOLL_CTL_ADD：往epoll模型中添加新的节点；
        - EPOLL_CTL_MOD：修改epoll模型中已经存在的节点；
        - EPOLL_CTL_DEL：删除epoll模型中的指定的节点。
    - fd：文件描述符，即要添加/修改/删除的文件描述符。
    - event：epoll事件，用来修饰第三个参数对应的文件描述符，指定检测这个文件描述符的什么事件
        - events：委托epoll检测的事件
            - EPOLLIN：读事件，接收数据，检测读缓冲区，如果有数据该文件描述符就绪；
            - EPOLLOUT：写事件，发送数据，检测写缓冲区，如果可写该文件描述符就绪；
            - EPOLLERR：异常事件。
        - data：用户数据变量，这是一个联合体类型，通常情况下使用里边的fd成员，用于存储待检测的文件描述符的值，在调用epoll_wait()函数的时候这个值会被传出。
- 函数返回值：
    - 失败：返回-1；
    - 成功：返回0。

epoll_wait()函数的作用是检测创建的epoll实例中有没有就绪的文件描述符。
```c
int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);
```
- 函数参数
    - epfd：epoll_create()函数的返回值，通过这个参数找到epoll实例；
    - events：传出参数，这是一个结构体数组的地址，里边存储了已就绪的文件描述符的信息；
    - maxevents：修饰第二个参数events，为结构体数组的容量（元素个数）；
    - timeout：检测的epoll实例中没有已就绪的文件描述符时，该函数阻塞的时长，单位毫秒
        - 0：函数不阻塞，不管 epoll 实例中有没有就绪的文件描述符，函数被调用后都直接返回；
        - 大于0：如果 epoll 实例中没有已就绪的文件描述符，函数阻塞对应的毫秒数再返回；
        - -1：函数一直阻塞，直到 epoll 实例中有已就绪的文件描述符之后才解除阻塞。
- 函数返回值：
    - 成功：
        - 等于0：没有检测到满足条件的文件描述符；
        - 大于0：检测到的已就绪的文件描述符的总个数。
    - 失败：返回-1。

## 使用epoll
