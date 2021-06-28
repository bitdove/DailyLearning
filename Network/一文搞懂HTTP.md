# Web及网络基础
HTTP：超文本传输协议
HTTP/0.9:没有正式标准，意味HTTP1.0之前的版本；
HTTP/1.0:初期标准，但至今仍被广泛应用；
HTTP/1.1:目前主流的HTTP版本
HTTP/2.0:
## URI 和 URL
URI：Uniform Resource Identifier 统一资源标识符
    http://user:pass@www.example.jp:80/dir/index.html?uid=1#ch1
    协议名- 认证      -服务器地址     -服务器端口号  -带层次的文件结构 
# 简单HTTP协议
    GET /index.htm HTTP/1.1
    HOST: hackr.jp

HTTP是无状态协议，对于发送过的请求或响应不做持久化处理。
使用HTTP协议，每当有新的请求发送时，就会有对应的新响应产生。协议本身并不保留之前一切的请求或响应报文的信息。

Cookie技术管理状态

## 方法
- GET：获取资源
- POST：传输实体的主体
- PUT：传输文件
- HEAD：获得响应报文首部
- DELETE：删除文件
- OPTIONS：询问支持的方法 (HTTP/1.1)
- TRACE：追踪路径 (HTTP/1.1)
- CONNECT：要求用隧道协议连接代理 (HTTP/1.1)

## 持久连接 Keep-alive
HTTP协议的初始版本中，每进行一次HTTP通信就要断开一次TCP连接。
持久连接的特点是，只要任意一端没有明确提出断开连接，则保持 TCP 连接状态。

在HTTP/1.1中，所有的连接默认都是持久连接，但在 HTTP/1.0 内并未标准化。

## 管线化请求
管线化技术出现后，不用等待响应亦可直接发送下一个请求。

## Cookie技术
Cookie 技术通过在请求和响应报文中写入Cookie信息来控制客户端的状态。

Cookie 会根据从服务器端发送的响应报文内的一个叫做 Set-Cookie 的首部字段信息，通知客户端保存 Cookie。当下次客户端再往该服务器发送请求时，客户端会自动在请求报文中加入 Cookie 值后发送出去。
服务器端发现客户端发送过来的 Cookie 后，会去检查究竟是从哪一个客户端发来的连接请求，然后对比服务器上的记录，最后得到之前的状态信息。

# HTTP报文


# HTTP状态码
# Web服务器
# HTTP首部
# HTTPS
# 认证
# HTTP2.0
# HTML
# Web攻击