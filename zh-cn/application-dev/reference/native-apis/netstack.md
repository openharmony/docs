# Netstack


## 概述

为网络协议栈模块提供c接口。

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [net_ssl_c.h](net__ssl__c_8h.md) | 为SSL/TLS证书链校验模块定义C接口。 | 
| [net_ssl_c_type.h](net__ssl__c__type_8h.md) | 定义SSL/TLS证书链校验模块的C接口需要的数据结构。 | 
| [net_websocket.h](net__websocket_8h.md) | 为websocket客户端模块定义C接口。 | 
| [net_websocket_type.h](net__websocket__type_8h.md) | 定义websocket客户端模块的C接口需要的数据结构。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [NetStack_CertBlob](_net_stack___cert_blob.md) | 证书数据结构体。 | 
| [OH_NetStack_WebsocketClient_CloseResult](_o_h___net_stack___websocket_client___close_result.md) | websocket客户端来自服务端关闭的参数。 | 
| [OH_NetStack_WebsocketClient_CloseOption](_o_h___net_stack___websocket_client___close_option.md) | websocket客户端主动关闭的参数。 | 
| [OH_NetStack_WebsocketClient_ErrorResult](_o_h___net_stack___websocket_client___error_result.md) | websocket客户端来自服务端连接错误的参数。 | 
| [OH_NetStack_WebsocketClient_OpenResult](_o_h___net_stack___websocket_client___open_result.md) | websocket客户端来自服务端连接成功的参数。 | 
| [OH_NetStack_WebsocketClient_Slist](_o_h___net_stack___websocket_client___slist.md) | websocket客户端增加header头的链表节点。 | 
| [OH_NetStack_WebsocketClient_RequestOptions](h___net_stack___websocket_client___request_options.md) | websocket客户端和服务端建立连接的参数。 | 
| [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) | websocket客户端结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| (\*[OH_NetStack_WebsocketClient_OnOpenCallback](#oh_netstack_websocketclient_onopencallback)) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, [OH_NetStack_WebsocketClient_OpenResult](_o_h___net_stack___websocket_client___open_result.md) openResult) | websocket客户端接收open消息的回调函数定义。 | 
| (\*[OH_NetStack_WebsocketClient_OnMessageCallback](#oh_netstack_websocketclient_onmessagecallback)) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, char \*data, uint32_t length) | websocket客户端接收数据的回调函数定义。 | 
| (\*[OH_NetStack_WebsocketClient_OnErrorCallback](#oh_netstack_websocketclient_onerrorcallback)) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, [OH_NetStack_WebsocketClient_ErrorResult](_o_h___net_stack___websocket_client___error_result.md) errorResult) | websocket客户端接收error错误消息的回调函数定义。 | 
| (\*[OH_NetStack_WebsocketClient_OnCloseCallback](#oh_netstack_websocketclient_onclosecallback)) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, [OH_NetStack_WebsocketClient_CloseResult](_o_h___net_stack___websocket_client___close_result.md) closeResult) | websocket客户端接收close消息的回调函数定义。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NetStack_CertType](#netstack_certtype) { <br/>NetStack_CERT_TYPE_PEM = 0, <br/>NetStack_CERT_TYPE_DER = 1, <br/>NetStack_CERT_TYPE_INVALID <br/>} | 证书类型枚举。 | 
| [OH_Websocket_ErrCode](#oh_websocket_errcode) {<br/>Websocket_OK = 0, <br/> E_BASE = 1000, WEBSOCKET_CLIENT_IS_NULL = (E_BASE + 1), <br/>WEBSOCKET_CLIENT_IS_NOT_CREAT = (E_BASE + 2),<br/>WEBSOCKET_CONNECTION_ERROR = (E_BASE + 3), <br/>WEBSOCKET_CONNECTION_PARSEURL_ERROR = (E_BASE + 5), <br/>WEBSOCKET_CONNECTION_NO_MEMOERY = (E_BASE + 6),<br/> WEBSOCKET_PEER_INITIATED_CLOSE = (E_BASE + 7),<br/>WEBSOCKET_DESTROY = (E_BASE + 8), <br/>WEBSOCKET_PROTOCOL_ERROR = (E_BASE + 9), <br/>WEBSOCKET_SEND_NO_MEMOERY_ERROR = (E_BASE + 10), <br/>WEBSOCKET_SEND_DATA_NULL = (E_BASE + 11),<br/>WEBSOCKET_DATA_LENGTH_EXCEEDS = (E_BASE + 12), <br/>WEBSOCKET_QUEUE_LENGTH_EXCEEDS = (E_BASE + 13), <br/>WEBSOCKET_ERROR_NO_CLIENTCONTEX = (E_BASE + 14), <br/>WEBSOCKET_ERROR_NO_HEADR_CONTEXT = (E_BASE + 15),<br/>WEBSOCKET_ERROR_NO_HEADR_EXCEEDS = (E_BASE + 16), <br/>WEBSOCKET_ERROR_HAVE_NO_CONNECT = (E_BASE + 17), <br/>WEBSOCKET_ERROR_HAVE_NO_CONNECT_CONTEXT = (E_BASE + 18)<br/>} | 错误码枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NetStack_VerifyCertification](#oh_netstack_verifycertification) (const struct [NetStack_CertBlob](_net_stack___cert_blob.md) \*cert, const struct [NetStack_CertBlob](_net_stack___cert_blob.md) \*caCert) | 证书链校验接口。 | 
| [OH_NetStack_WebsocketClient_Construct](#oh_netstack_websocketclient_construct) ([OH_NetStack_WebsocketClient_OnOpenCallback](#oh_netstack_websocketclient_onopencallback) OnOpen, [OH_NetStack_WebsocketClient_OnMessageCallback](#oh_netstack_websocketclient_onmessagecallback) onMessage, [OH_NetStack_WebsocketClient_OnErrorCallback](#oh_netstack_websocketclient_onerrorcallback) OnError, [OH_NetStack_WebsocketClient_OnCloseCallback](#oh_netstack_websocketclient_onclosecallback) onclose) | OH_NetStack_WebsocketClient客户端的构造函数。 | 
| [OH_NetStack_WebSocketClient_AddHeader](#oh_netstack_websocketclient_addheader) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, struct [OH_NetStack_WebsocketClient_Slist](_o_h___net_stack___websocket_client___slist.md) header) | 将header头信息添加到client客户端request中。 | 
| [OH_NetStack_WebSocketClient_Connet](#oh_netstack_websocketclient_connet) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, const char \*url, struct [OH_NetStack_WebsocketClient_RequestOptions](h___net_stack___websocket_client___request_options.md) options) | 客户端连接服务端。 | 
| [OH_NetStack_WebSocketClient_Send](#oh_netstack_websocketclient_send) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, char \*data, size_t length) | 客户端向服务端发送数据。 | 
| [OH_NetStack_WebSocketClient_Close](#oh_netstack_websocketclient_close) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client, struct [OH_NetStack_WebsocketClient_CloseOption](_o_h___net_stack___websocket_client___close_option.md) options) | 客户端主动关闭websocket连接。 | 
| [OH_NetStack_WebsocketClient_Destroy](#oh_netstack_websocketclient_destroy) (struct [OH_NetStack_WebsocketClient](_o_h___net_stack___websocket_client.md) \*client) | 释放websocket连接上下文和资源。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| [NetStack_CertBlob::type](#type) | 证书类型。 | 
| [NetStack_CertBlob::size](#size) | 证书内容长度。 | 
| [NetStack_CertBlob::data](#data) | 证书内容。 | 
| [OH_NetStack_WebsocketClient_CloseResult::code](#code-13) | 关闭的错误码。 | 
| [OH_NetStack_WebsocketClient_CloseResult::reason](#reason-13) | 关闭的错误原因。 | 
| [OH_NetStack_WebsocketClient_CloseOption::code](#code-23) | 关闭的错误码。 | 
| [OH_NetStack_WebsocketClient_CloseOption::reason](#reason-23) | 关闭的错误原因。 | 
| [OH_NetStack_WebsocketClient_ErrorResult::errorCode](#errorcode) | 错误码。 | 
| [OH_NetStack_WebsocketClient_ErrorResult::errorMessage](#errormessage) | 错误的消息。 | 
| [OH_NetStack_WebsocketClient_OpenResult::code](#code-33) | websocket客户端连接成功码。 | 
| [OH_NetStack_WebsocketClient_OpenResult::reason](#reason-33) | websocket客户端连接原因。 | 
| [OH_NetStack_WebsocketClient_Slist::FieldName](#fieldname) | header头的字段名。 | 
| [OH_NetStack_WebsocketClient_Slist::FieldValue](#fieldvalue) | header头的字段内容。 | 
| [OH_NetStack_WebsocketClient_Slist::next](#next) | header头链表的next指针。 | 
| OH_NetStack_WebsocketClient_RequestOptions::headers | header头信息。 | 
| [OH_NetStack_WebsocketClient::onOpen](#onopen) | 客户端接收连接消息的回调指针。 | 
| [OH_NetStack_WebsocketClient::onMessage](#onmessage) | 客户端接收消息的回调指针。 | 
| [OH_NetStack_WebsocketClient::onError](#onerror) | 客户端接收错误消息的回调指针。 | 
| [OH_NetStack_WebsocketClient::onClose](#onclose) | 客户端接收关闭消息的回调指针。 | 
| [OH_NetStack_WebsocketClient::RequestOptions](#requestoptions) | 客户端建立连接请求内容。 | 


## 类型定义说明


### OH_NetStack_WebsocketClient_OnCloseCallback

```
typedef void(* OH_NetStack_WebsocketClient_OnCloseCallback) (struct OH_NetStack_WebsocketClient *client, OH_NetStack_WebsocketClient_CloseResult closeResult)
```

**描述**

websocket客户端接收close消息的回调函数定义。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | websocket客户端。 | 
| closeResult | websocket客户端接收关闭消息的内容。 | 


### OH_NetStack_WebsocketClient_OnErrorCallback

```
typedef void(* OH_NetStack_WebsocketClient_OnErrorCallback) (struct OH_NetStack_WebsocketClient *client, OH_NetStack_WebsocketClient_ErrorResult errorResult)
```

**描述**

websocket客户端接收error错误消息的回调函数定义。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | websocket客户端。 | 
| errorResult | websocket客户端接收连接错误消息的内容。 | 


### OH_NetStack_WebsocketClient_OnMessageCallback

```
typedef void(* OH_NetStack_WebsocketClient_OnMessageCallback) (struct OH_NetStack_WebsocketClient *client, char *data, uint32_t length)
```

**描述**

websocket客户端接收数据的回调函数定义。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | websocket客户端。 | 
| data | websocket客户端接收的数据。 | 
| length | websocket客户端接收的数据长度。 | 


### OH_NetStack_WebsocketClient_OnOpenCallback

```
typedef void(* OH_NetStack_WebsocketClient_OnOpenCallback) (struct OH_NetStack_WebsocketClient *client, OH_NetStack_WebsocketClient_OpenResult openResult)
```

**描述**

websocket客户端接收open消息的回调函数定义。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | websocket客户端。 | 
| openResult | websocket客户端接收建立连接消息的内容。 | 



## 枚举类型说明


### NetStack_CertType

```
enum NetStack_CertType
```

**描述**

证书类型枚举。

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| NetStack_CERT_TYPE_PEM | PEM证书类型。 | 
| NetStack_CERT_TYPE_DER | DER证书类型。 | 
| NetStack_CERT_TYPE_INVALID | 错误证书类型。 | 


### OH_Websocket_ErrCode

```
enum OH_Websocket_ErrCode
```

| 枚举值 | 描述 | 
| -------- | -------- |
| Websocket_OK | 执行成功。 | 
| E_BASE | 异常错误代码的基础。 | 
| WEBSOCKET_CLIENT_IS_NULL | websocket为空。 | 
| WEBSOCKET_CLIENT_IS_NOT_CREAT | websocket未创建。 | 
| WEBSOCKET_CONNECTION_ERROR | websocket客户端连接错误。 | 
| WEBSOCKET_CONNECTION_PARSEURL_ERROR | websocket客户端连接参数解析错误。 | 
| WEBSOCKET_CONNECTION_NO_MEMOERY | websocket客户端连接时创建上下文无内存。 | 
| WEBSOCKET_PEER_INITIATED_CLOSE | 初始化时候关闭。 | 
| WEBSOCKET_DESTROY | websocket连接被销毁。 | 
| WEBSOCKET_PROTOCOL_ERROR | websocket客户端连接时候协议错误。 | 
| WEBSOCKET_SEND_NO_MEMOERY_ERROR | websocket客户端发送数据时候没有足够内存。 | 
| WEBSOCKET_SEND_DATA_NULL | websocket客户端发送数据为空。 | 
| WEBSOCKET_DATA_LENGTH_EXCEEDS | websocket客户端发送数据长度超限制。 | 
| WEBSOCKET_QUEUE_LENGTH_EXCEEDS | websocket客户端发送数据队列长度超限制。 | 
| WEBSOCKET_ERROR_NO_CLIENTCONTEX | websocket客户端上下文为空。 | 
| WEBSOCKET_ERROR_NO_HEADR_CONTEXT | websocket客户端header头异常。 | 
| WEBSOCKET_ERROR_NO_HEADR_EXCEEDS | websocket客户端header头超过限制。 | 
| WEBSOCKET_ERROR_HAVE_NO_CONNECT | websocket客户端没有连接。 | 
| WEBSOCKET_ERROR_HAVE_NO_CONNECT_CONTEXT | websocket客户端没有连接上下文。 | 


## 函数说明


### OH_NetStack_VerifyCertification()

```
uint32_t OH_NetStack_VerifyCertification (const struct NetStack_CertBlob * cert, const struct NetStack_CertBlob * caCert )
```

**描述**

证书链校验接口。

**系统能力：** SystemCapability.Communication.Netstack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cert | 用户传入的待校验证书。 | 
| caCert | 用户指定的证书，若为空则以系统预置证书进行校验。 | 

**返回：**

0 - 成功.

2305001 - 未指定的错误.

2305002 - 无法获取颁发者证书.

2305003 - 无法获取证书吊销列表（CRL）.

2305004 - 无法解密证书签名.

2305005 - 无法解密CRL签名.

2305006 - 无法解码颁发者公钥.

2305007 - 证书签名失败.

2305008 - CRL签名失败.

2305009 - 证书尚未生效.

2305010 - 证书已过期.

2305011 - CRL尚未有效.

2305012 - CRL已过期.

2305023 - 证书已被吊销.

2305024 - 证书颁发机构（CA）无效.

2305027 - 证书不受信任.

### OH_NetStack_WebSocketClient_AddHeader()

```
int OH_NetStack_WebSocketClient_AddHeader (struct OH_NetStack_WebsocketClient * client, struct OH_NetStack_WebsocketClient_Slist header )
```

**描述**

将header头信息添加到client客户端request中。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端指针。 | 
| header | header头信息。 | 

**返回：**

返回值为0表示执行成功。返回错细信息可以查看[OH_Websocket_ErrCode](#oh_websocket_errcode)。

**Permission：**

ohos.permission.INTERNET


### OH_NetStack_WebSocketClient_Close()

```
int OH_NetStack_WebSocketClient_Close (struct OH_NetStack_WebsocketClient * client, struct OH_NetStack_WebsocketClient_CloseOption options )
```

**描述**

客户端主动关闭websocket连接。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端。 | 
| url | 客户端要连接到服务端的地址。 | 
| options | 发起关闭连接的可选参数。 | 

**返回：**

返回值为0表示执行成功。返回错细信息可以查看[OH_Websocket_ErrCode](#oh_websocket_errcode)。

**Permission：**

ohos.permission.INTERNET


### OH_NetStack_WebSocketClient_Connet()

```
int OH_NetStack_WebSocketClient_Connet (struct OH_NetStack_WebsocketClient * client, const char * url, struct OH_NetStack_WebsocketClient_RequestOptions options )
```

**描述**

客户端连接服务端。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端指针。 | 
| url | 客户端要连接到服务端的地址。 | 
| options | 发起连接的可选参数。 | 

**返回：**

返回值为0表示执行成功。返回错细信息可以查看[OH_Websocket_ErrCode](#oh_websocket_errcode)。

**Permission：**

ohos.permission.INTERNET


### OH_NetStack_WebsocketClient_Construct()

```
struct OH_NetStack_WebsocketClient* OH_NetStack_WebsocketClient_Construct (OH_NetStack_WebsocketClient_OnOpenCallback OnOpen, OH_NetStack_WebsocketClient_OnMessageCallback onMessage, OH_NetStack_WebsocketClient_OnErrorCallback OnError, OH_NetStack_WebsocketClient_OnCloseCallback onclose )
```

**描述**

OH_NetStack_WebsocketClient客户端的构造函数。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| onMessage | 客户端定义的接收消息的回调函数。 | 
| onClose | 客户端定义的关闭消息的回调函数。 | 
| onError | 客户端定义的错误消息的回调函数。 | 
| onOpen | 客户端定义的建立连接消息的回调函数。 | 

**返回：**

成功返回客户端指针，失败返回为NULL。

**Permission：**

ohos.permission.INTERNET


### OH_NetStack_WebsocketClient_Destroy()

```
int OH_NetStack_WebsocketClient_Destroy (struct OH_NetStack_WebsocketClient * client)
```

**描述**

释放websocket连接上下文和资源。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端。 | 

**返回：**

返回值为0表示执行成功。返回错细信息可以查看[OH_Websocket_ErrCode](#oh_websocket_errcode)。

**Permission：**

ohos.permission.INTERNET


### OH_NetStack_WebSocketClient_Send()

```
int OH_NetStack_WebSocketClient_Send (struct OH_NetStack_WebsocketClient * client, char * data, size_t length )
```

**描述**

客户端向服务端发送数据。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端。 | 
| data | 客户端发送的数据。 | 
| length | 客户端发送的数据长度。 | 

**返回：**

0 - 成功

返回值为0表示执行成功。返回错细信息可以查看[OH_Websocket_ErrCode](#oh_websocket_errcode)。

**Permission：**

ohos.permission.INTERNET

## 变量说明


### data

```
uint8_t* NetStack_CertBlob::data
```

**描述**

证书内容。


### size

```
uint32_t NetStack_CertBlob::size
```

**描述**

证书内容长度。


### type

```
enum NetStack_CertType NetStack_CertBlob::type
```

**描述**

证书类型。


### code [1/3]

```
uint32_t OH_NetStack_WebsocketClient_CloseResult::code
```

**描述**

关闭的错误码。


### code [2/3]

```
uint32_t OH_NetStack_WebsocketClient_CloseOption::code
```

**描述**

关闭的错误码。


### code [3/3]

```
uint32_t OH_NetStack_WebsocketClient_OpenResult::code
```

**描述**

websocket客户端连接成功码。


### errorCode

```
uint32_t OH_NetStack_WebsocketClient_ErrorResult::errorCode
```

**描述**

错误码。


### errorMessage

```
const char* OH_NetStack_WebsocketClient_ErrorResult::errorMessage
```

**描述**

错误的消息。


### FieldName

```
const char* OH_NetStack_WebsocketClient_Slist::FieldName
```

**描述**

header头的字段名。


### FieldValue

```
const char* OH_NetStack_WebsocketClient_Slist::FieldValue
```

**描述**

header头的字段内容。


### next

```
struct OH_NetStack_WebsocketClient_Slist* OH_NetStack_WebsocketClient_Slist::next
```

**描述**

header头链表的next指针。


### onClose

```
OH_NetStack_WebsocketClient_OnCloseCallback OH_NetStack_WebsocketClient::onClose
```

**描述**

客户端接收关闭消息的回调指针。


### onError

```
OH_NetStack_WebsocketClient_OnErrorCallback OH_NetStack_WebsocketClient::onError
```

**描述**

客户端接收错误消息的回调指针。


### onMessage

```
OH_NetStack_WebsocketClient_OnMessageCallback OH_NetStack_WebsocketClient::onMessage
```

**描述**

客户端接收消息的回调指针。


### onOpen

```
OH_NetStack_WebsocketClient_OnOpenCallback OH_NetStack_WebsocketClient::onOpen
```

**描述**

客户端接收连接消息的回调指针。


### reason [1/3]

```
const char* OH_NetStack_WebsocketClient_CloseResult::reason
```

**描述**

关闭的错误原因。


### reason [2/3]

```
const char* OH_NetStack_WebsocketClient_CloseOption::reason
```

**描述**

关闭的错误原因。


### reason [3/3]

```
const char* OH_NetStack_WebsocketClient_OpenResult::reason
```

**描述**

websocket客户端连接原因。


### RequestOptions

```
OH_NetStack_WebsocketClient_RequestOptions OH_NetStack_WebsocketClient::RequestOptions
```

**描述**

客户端建立连接请求内容。
