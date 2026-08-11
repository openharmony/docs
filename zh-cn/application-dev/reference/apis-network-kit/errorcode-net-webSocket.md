# webSocket错误码

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)说明文档。

## 200 连接失败

**错误信息**

Websocket connect failed.

**错误描述**

WebSocket连接失败。

**可能原因**

1. 连接建立失败：可能是服务器拒绝客户端连接、协议出现问题导致握手失败或证书验证失败。

2. 链路异常断开：客户端或服务端断开连接时无正常状态码。

3. 握手阶段消息头处理异常：在添加header过程中发生错误。

4. 系统内部异常。

**处理步骤**

1. 检查协议是否有效、证书校验是否通过，重新连接。

2. 检查网络是否异常，或切换网络重新连接。

3. 检查添加header是否正确。

4. 如果问题仍然存在，收集完整日志后联系技术支持获取帮助。 

## 2302001 Websocket URL错误

**错误信息**

Websocket url error.

**错误描述**

WebSocket URL错误。

**可能原因**

未配置正确的URL。

**处理步骤**

1.检查URL是否为空或者未包含正确的协议（ws://或wss://）。

2.检查URL长度是否超过2048个字符。

## 2302002 Websocket 证书不存在

**错误信息**

Websocket certificate file does not exist.

**错误描述**

WebSocket 证书不存在。

**可能原因**

证书路径错误或未配置证书。

**处理步骤**

1.检查CA证书路径是否有效。

2.如指定了WebSocketRequestOptions.clientCert，请检查证书路径与私钥路径是否有效。


## 2302003 Websocket 连接已经存在

**错误信息**

Websocket connection already exists.

**错误描述**

WebSocket 连接已经存在。

**可能原因**

WebSocket 连接已经建立。

**处理步骤**

已建立websocket连接，无需重复调用WebSocket.connect进行建连，无其他处理步骤。

## 2302004 WebsocketServer 无法在指定的NIC（网络接口）上进行网络监听

**错误信息**

Can't listen to the given NIC.

**错误描述**

WebSocketServer无法在指定的NIC上进行网络监听。

**可能原因**

WebSocketServer服务器配置文件中的IP地址无效。

**处理步骤**

检查网络连接是否正常，检查IP地址有效性。

## 2302005 WebsocketServer 无法在指定的端口上进行网络监听

**错误信息**

Can't listen to the given Port.

**错误描述**

WebSocketServer无法在指定的端口上进行网络监听。

**可能原因**

WebSocketServer服务器配置文件中的端口号无效。

**处理步骤**

检查端口号的有效性。

## 2302007 WebsocketServer当前监听的端口已被占用

**错误信息**

Websocket port already occupied.

**错误描述**

WebsocketServer当前监听的端口已经被占用。

**可能原因**

指定的监听端口已被其他进程占用。

**处理步骤**

更换一个未被占用的端口。

## 2302998 不允许访问域名

**错误信息**

It is not allowed to access this domain.

**错误描述**

不允许访问此域名。

**可能原因**

元服务应用未正确配置服务器域名。

**处理步骤**

可参考[配置服务器域名](https://developer.huawei.com/consumer/cn/doc/atomic-guides/agc-help-harmonyos-server-domain)文档完成服务器域名相关配置。

## 2302999 内部错误

**错误信息**

Internal error.

**错误描述**

内部错误。

**可能原因**

空指针异常、内存分配异常等。

**处理步骤**

重启机器重试。