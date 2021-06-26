## 初识/proc目录
/proc目录下的内容可以分成三类：
    - 以数字命名的目录；
    - 以普通英文字符命名的目录；
    - 普通文件
    - 符号链接文件；

## 数字命名的目录

## 普通英文字符命名的目录

## 普通文件

- buddyinfo:Linux内核内存管理，将物理页面划分为几类。
    ```shell
    [root@TenCloud proc]# cat buddyinfo 
    Node 0, zone      DMA     20      6      9      9      9      4      4      2      4      0      0 
    Node 0, zone    DMA32  11712   5624    839    384    137     46     37     25      5      0      0 
    ```
- cgroups:用来对一组进程所占用的资源做限制、统计、隔离.
- cmdline:

## 符号链接文件