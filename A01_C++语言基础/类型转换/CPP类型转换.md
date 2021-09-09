# 显示转换（强制类型转换）
形式如下：
```cpp
cast-name<type>(expression)
```
## static_cast
不包含底层const的对象，均可用static_cast
## const_cast
只改变对象的底层const
## reinterpret_cast
## dynamic_cast