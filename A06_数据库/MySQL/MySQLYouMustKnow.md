## 了解SQL

数据库：保存有组织的数据的容器。比喻：文件柜。

表：某种特定类型数据的结构化清单。

模式：关于数据库和表的布局及特性的信息。

列：表由列组成。

行：表中的一个记录。

主键：一列，其值可以唯一区分表中的每个行。

SQL:Structured Query Language,结构化查询语言。

##  MySQL

MySQL:一种数据库软件，基于客户机/服务器。
- mysql默认端口3306；
- 本地MySQL服务器叫localhost。

客户机：mysql命令行
- 命令输在mysql>之后；
- 命令由;或\g结束，仅按enter不执行命令；
- quit或exit退出。

## 使用MySQL

必须先使用USE关键字选择要操作的数据库，才能读取其中的数据。
```mysql
USE yourdb
```

SHOW命令
- 显示可用的数据库列表。
    ```mysql
    SHOW DATABASES;
    ```
- 显示一个数据库内的表的列表
    ```mysql
    SHOW TABLES;
    ```
- 显示表列
    ```mysql
    SHOW COLUMNS FROM tablename;
    或
    DESCRIBE tablename;
    ```

## 检索数据

> SQL语句不区分大小写。但是对SQL关键字使用大写，而对所有列和表名使用小写是一个好习惯，便于阅读和调试。

SELECT语句：从一个或多个表中检索信息。

在名为user的表中检索名为username的列
```mysql
SELECT username FROM user;
```

检索多个列名
```mysql
SELECT username, passwd FROM user;
```

使用通配符`*`检索所有列
```mysql
SELECT * FROM user;
```

## 检索不同的行

DISTINCT关键字，去重。
```mysql
SELECT DISTINCT vend_id FROM products;
```
> DISTINCT必须直接放在列名前面。检索多个列时，DISTINCT关键字对所有检索的列都有效。

## 限制结果
LIMIT关键字限制返回个数。

```mysql
SELECT prod_name FROM products LIMIT 5;
```

LIMIT 5,5表示返回从行5开始的5行。