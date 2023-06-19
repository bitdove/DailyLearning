gcc - GNU project C and C++ compiler
```shell
    gcc [-c|-S|-E] [-std=standard]
        [-g] [-pg] [-Olevel]
        [-Wwarn...] [-Wpedantic]
        [-Idir...] [-Ldir...]
        [-Dmacro[=defn]...] [-Umacro]
        [-foption...] [-mmachine-option...]
        [-o outfile] [@file] infile...
```
> Only the most useful options are listed here;
g++ accepts mostly the same options as gcc.

编译四阶段：预处理、编译、汇编、链接
# -E | -S | -c
- -E:进行到预处理为止；
- -S:进行到编译为止；
- -c:进行到汇编为止
# -std=standard
设置采用的语言标准,如-std=c99
# -g
加入调试信息
# -pg
生成额外的代码以写入适用于分析程序gprof的概要文件信息。
# -Olevel
使用编译优化级别level编译程序。level为1~3，级别越大优化效果越好，但编译时间越长。
