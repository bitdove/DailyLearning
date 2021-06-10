## I/O多路复用
I/O多路复用使得程序能同时监听多个文件描述符，从而提高程序的性能。

> I:从文件到内存，即读;
> O:从内存到文件，即写。

Linux下实现I/O多路复用的系统调用主要有三个：
- select
- poll
- epoll

## 五种I/O模型

### 阻塞I/O
阻塞I/O即Blocking I/O（BIO）。
### 非阻塞I/O
非阻塞I/O即Non-blocking I/O（NIO）。
### I/O多路复用

### 信号驱动I/O

### 异步I/O

## select

> 主旨思想：
> 1. 首先要构造要监听的文件描述符列表；
> 2. 调用系统函数，监听该列表中的文件描述符，直到这些描述符中的一个或多个进行I/O操作时，该函数才返回。注意，该函数是阻塞的，且函数对文件描述符的检测是由内核完成；
> 3. 在返回时，它会告诉进程有多少描述符要进行I/O操作。

```c
//sizeof(fd_set) = 128 
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int select(int nfds, 
           fd_set *readfds, 
           fd_set *writefds,
           fd_set *exceptfds, 
           struct timeval *timeout);
    - 参数：
            - nfds：委托内核检测的最大文件描述符的值 + 1；
            - readfds：委托内核检测哪些文件描述符的读的属性；
            - writefds:委托内核检测哪些文件描述符的写的属性；
            - exceptfds：委托内核检测哪些文件描述符的异常的属性；
            - timeout：设置的超时时间。NULL为永久阻塞，知道检测到文件描述符有变化。
            - 返回值：
                - -1表示失败；
                - >0(n):表示有n个描述符发生变化。
//将fd对应的标志位置0
void FD_CLR(int fd, fd_set *set);
//判断fd对应的标志位是0还是1
int  FD_ISSET(int fd, fd_set *set);
//将fd的标志位置1
void FD_SET(int fd, fd_set *set);
//fd_set的比特位全部置0
void FD_ZERO(fd_set *set);
```

