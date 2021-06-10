## 查看Linux系统信息
- arch：显示处理器架构
- uname -a: 显示处理器架构及内核版本
- uname -r: 显示Linux内核版本
## 文件和目录
- cd
- pwd
- ls
- tree
- mkdir
- rm
- rmdir
- mv
- cp
- ln
- touch
## 文本处理
- find
- awk
- sed
- grep
## 磁盘相关
- df
- du
## 用户和群组
- useradd
- groupadd
- passwd
## 文件权限
- chmod
- chown
- chgrp
## 文件打包与压缩
- tar
- gzip
- bzip
## 包管理
- rpm
- yum
## 查看文件
- cat
- more
- less
- head
- tail
## 网络
- ping
- traceroute
- ifconfigq
- route
- hostname
- nslookup
- netstat
- tcpdump
## 进程
- top
- ps

# top
名字：
    top —— 显示Linux进程
概要：
    top -hv|-bcHiOSs -d secs -n max -u|U user -p pid -o fld -w [cols]
描述：
    top程序提供了系统的实时动态视图。它可以以列表形式显示系统进/线程的概要信息。
    -d 指定刷新时间