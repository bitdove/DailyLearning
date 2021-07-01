# 笔试
选择题、编程题、简答题、行测、性格测试
## 简答题
- WiFi卡顿，TCP单播先卡后流畅
- 程序出现的问题
  ```c
  void GetMemory(char *p){
    p = (char*)malloc(100);
  }

  void Test(void){
    char *str = NULL;
    GetMemory(str);
    strcpy(str, "hello world");
    printf("%s\n", str);
  }
  ```
> 程序会崩溃。
> - 因为GetMemory函数的形参为char类型的指针，属于值传递。在Test函数内调用GetMemory(str)时，实际上做的是p = str; p = (char*)malloc(100);str并没有变化，始终指向NULL，那么在strcpy时，由于没有给str分配地址空间，复制时会出现崩溃；
> - malloc分配可能会失败，应该进行判断；
> - malloc分配的内存没有释放。

- 进程线程的异同点
> 相同点：
## 编程题
- 环形链表II
  ```c++
  ListNode* hasCycle(ListNode *head){
	  if(head == nullptr)
	  	return nullptr;
	  ListNode* slow = head;
	  ListNode* fast = head;
	  do{
		  if(fast == nullptr || fast->next == nullptr)
			return false;
		  slow = slow->next;
		  fast = fast->next->next;
	  }while(slow != fast);
	  ListNode* ptr = head;
	  while(ptr != slow){
		  ptr = ptr->next;
		  slow = slow->next;
	  }
	  return ptr;
  }
  ```
- 两个排序数组找中位数
  ```c++
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    const int m = nums1.size();
    const int n = nums2.size();

  }
  ```
# 面试
- TCP和UDP应用场景
	> TCP全称传输控制协议，是面向连接的可靠的流式传输协议。所以常用于对网络通讯质量有较高要求的时候，比如：要求通信数据完整性，则应该选用TCP协议，如文件传输等，具体到应用层协议，比如HTTP、HTTPS、FTP等传输文件的协议，POP、SMTP等邮件传输的协议；
	> UDP是一种无连接且不保证可靠性的协议。对当前网络通讯质量要求不高，而要求网络通讯速度尽量的快，这时就使用UDP，比如视频通话、语音通话。
- 宏，实现数据交换
  > #define SWAP(x,y) {x = x+y; y = x-y; x = x - y;}
- 引用的优点
- C++模版类
- 插入排序、快速排序
- DNS
- TIME_WAIT
  > TIME_WAIT是TCP连接中主动发起关闭的一方在彻底关闭前要经历的一个状态。TIME_WAIT的时间是2MSL。
  > TIME_WAIT的原因有两个:
  > - 确保客户端能响应服务端重传的FIN的报文段；服务器第一次发送FIN报文段，客户端收到后响应ACK报文段，但是这个ACK有可能丢失，服务端迟迟收不到，就会重传FIN报文段，如果没有TIME_WAIT状态，即客户端在第一次发送ACK后就彻底关闭连接，那服务端重传的FIN报文段发送到客户端之后，客户端会响应一个重置报文段而不是ACK，那么服务端就没办法可靠的进入CLOSED状态。而有了TIME_WAIT状态，在这期间，客户端依然维持着连接状态，对于重传来的FIN，客户端可以响应ACK，从而可靠的关闭TCP连接。
  > - 允许老的分组在网络中消逝。一对TCP连接是由四元组（srcIP,srcPort,destIP,destPort）所确定。在TCP连接的传输过程中，可能会有一些分组在网络中迷失，如果没有TIME_WAIT状态，即直接关闭连接。那如果再以相同的四元组重建连接，这些旧连接中迷路的分组可能被新的客户端/服务端误认为是新连接的分组而接收并交付，从而产生混乱。有了TIME_WAIT状态，可以确保本次连接中的分组全部在网络中消逝，不会影响新连接。在TIME_WAIT期间，该四元组被定义为不可使用状态，无法以同样的四元组建立新连接。
  > - 为什么是2MSL？MSL是Maximun Segment Lifetime,即最大报文段生存时间。它代表了任何报文段在被丢弃前在网络中被允许存在的最长时间。RFC中规定MSL为2分钟，但常见的实现中MSL为30秒、1分钟、2分钟。这一数值是可以修改的。
- 线程安全
- 三线程打印ABC
- 写程序找出内存泄露的位置
- 代码题：最长回文串
	```c
	int longestPalindrome(string s){
		unordered_map<char, int> count;
		int ans = 0;
		for(char c : s)
			++count[c];
		for(auto p : count){
			int v = p.second;
			ans += v / 2 * 2;
			if(v % 2 == 1 && ans % 2 == 0)
				++ans;
		}
		return ans;
	}
	```
- 代码题：青蛙跳台阶
	```c
	#include <stdio.h>
	long CalTotalOfMethods(int n){
		if(n < 3)
			return n;
		long preOne = 2;
		long preTwo = 1;
		long result = 0;
		for(int i = 3; i <= n; ++i){
			result = preOne + preTwo;
			preTwo = preOne;
			preOne = result;
		}
		return result;
	}
	int main(){
		int n;
		scanf("%d", &n);
		printf("%ld\n", CalTotalOfMethods(n));
	}
	```
- 智力题：20小球天平
	> 最少3次可以找出最轻的球。可以采用三分法。将20个球分成7，7，6三组。
	> - 第一次称7和7，若二者同重，说明轻的在6里；若二者不同重，则轻的在轻的7里；
	> - 第二次称。若是6，分为2，2，2，称2和2，同重在另一个2；不同重则在轻的2；若是7，分为2，2，3，称2和2，跟上边同理。
	> - 第三次称。若是2，分1，1，称一次就出来了；若是3，分为1，1，1，称一次也出来了。
- 智力题：AB抛硬币吃苹果，A吃到的概率。
	> 答案是2/3.
	> - 假设抛了一轮：1/2（A正）;
	> - 两轮：1/2（A反）*1/2（B反）*1/2（A正）=1/8；
	> - 三轮：1/2*1/2*1/2*1/2*1/2=1/32
	> - N轮：1/2的（2n-1）次方
	> - 加起来：是首项为1/2，公比为1/4的等比数列的前n项和：2/3.
- 智力题：多根不均匀的绳子，烧完需要1小时，问如何找到15分钟。
	> 用两根绳子。一根两头烧，另一根只点燃一头，当两头烧的那根烧完的瞬间，把另一根的另一头也点燃并开始计时，等这根烧完就是15分钟。
- 智力题：23个硬币10个朝上分两堆
  > 先将硬币分为两组，A组10个，B组13个，假设此时B组有x个朝上，那么A组有10-x个朝上。再将A组每个硬币翻转，此时A组有(10-(10-x))=x枚硬币朝上，和B组朝上的硬币数相等。
- 智力题：三个连续的大于6的整数，其中有两个质数，证明另一个数是6的倍数。
  > 三个连续的数，两个质数，说明数的排列只能是“奇偶奇”。一个数能被6整除，必然同时被2和3整除，偶数一定能被2整除，接下来证明中间的偶数一定能被3整除。三个连续的数，中间一定有一个数能被3整除，但是旁边两个数是质数，不可能整除3，只能偶数整除3，所以另一个数是6的倍数。
- 智力题：25匹马5个赛道最少几场可以找出最快的3匹马
  > 最少需要7场。
  > - 前五场：25匹马分为5组ABCDE，每组5匹。每组各赛一场排出组内名次。每组的后两名直接淘汰（10匹）。
  > - 第六场：每组的第一赛一把，假设比赛结果是A1>B1>C1>D1>E1,则D、E两组全部淘汰（6匹），C组d的第一才第三，所以C组除了C1也全部淘汰（2匹），B组第三名淘汰（1匹）。目前还剩6匹，A1肯定是总体第一，故只剩5匹；
  > - 第七场：剩下5匹赛一把，选出前二，与A1组成总体前三。
- 智力题：有1000瓶药水，其中一瓶是有毒的，老鼠喝掉药水后，毒性会在24小时后发作。那最少需要多少只老鼠，能够在24小时后找出哪一瓶有毒呢？
  > 答案是10只。本题可以用二进制和树的思想来解决。我们把1000瓶药水编号为0～999，并转为二进制，需要用10位二进制数（第1位～第10位），那么拿出10只小白鼠，编号为1～10；喝药水的规则为：编号为i的小白鼠，需要喝掉第i位为1的所有药水，每瓶喝1/10；24小时之后，根据10只老鼠的死活状态建立二叉树。即可找出哪一瓶有毒。