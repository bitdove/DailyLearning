# 数据结构与对象
Redis数据库里面的每个key-value都是由对象组成的：
- key总是一个字符串对象；
- value可以是字符串对象、列表对象、哈希对象、集合对象、有序集合对象中的一种。

如以下命令，创建了一个key和value均为字符串的键值对。
```sql
redis> SET msg "hello world"
OK
```
而以下命令将在数据库中创建一个key为字符串、value为列表对象的键值对：
```sql
redis> RPUSH numbers 1 3 5 7 9
(integer) 5
```

# 简单动态字符串SDS
Redis构建了一种名为Simple Dynamic String（SDS）的抽象类型，并将SDS作为Redis的默认字符串表示。