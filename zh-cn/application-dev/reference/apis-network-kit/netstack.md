# Netstack


## 概述

为网络协议栈模块提供C接口。

**起始版本：** 11


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [net_ssl_c.h](net__ssl__c_8h.md) | 为SSL/TLS证书链校验模块定义C接口。<br>**引用文件：** \<network\/netstack\/net_ssl\/net_ssl_c.h\> | 
| [net_ssl_c_type.h](net__ssl__c__type_8h.md) | 定义SSL/TLS证书链校验模块的C接口需要的数据结构。**引用文件：** \<network\/netstack\/net_ssl\/net_ssl_c_type.h\> | 
| [net_websocket.h](net__websocket_8h.md) | 为websocket客户端模块定义C接口。**引用文件：** \<network\/netstack\/net_websocket.h\> | 
| [net_websocket_type.h](net__websocket__type_8h.md) | 定义websocket客户端模块的C接口需要的数据结构。**引用文件：** \<network\/net_websocket_type.h\> | 


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [NetStack_CertBlob](_net_stack___cert_blob.md) | 证书数据结构体。 |
| [NetStack_CertificatePinning](_net_stack___certificate_pinning.md) | 证书锁定信息数据结构体。 |
| [NetStack_Certificates](_net_stack___certificates.md) | 证书信息数据结构体。 |
| [WebSocket_CloseResult](_web_socket___close_result.md) | websocket客户端来自服务端关闭的参数。  |
| [WebSocket_CloseOption](_web_socket___close_option.md) | websocket客户端主动关闭的参数。  |
| [WebSocket_ErrorResult](_web_socket___error_result.md) | websocket客户端来自服务端连接错误的参数。  |
| [WebSocket_OpenResult](_web_socket___open_result.md) | websocket客户端来自服务端连接成功的参数。  |
| [WebSocket_Header](_web_socket___header.md) | websocket客户端增加header头的链表节点。  |
| [WebSocket_RequestOptions](_web_socket___request_options.md) | websocket客户端和服务端建立连接的参数。  |
| [WebSocket](_web_socket.md) | websocket客户端结构体。  |


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| (\* [WebSocket_OnOpenCallback](#websocket_onopencallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_OpenResult](_web_socket___open_result.md) openResult) | websocket客户端接收open消息的回调函数定义。  | 
| (\* [WebSocket_OnMessageCallback](#websocket_onmessagecallback)) (struct [WebSocket](_web_socket.md) \*client, char \*data, uint32_t length) | websocket客户端接收数据的回调函数定义。  | 
| (\* [WebSocket_OnErrorCallback](#websocket_onerrorcallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_ErrorResult](_web_socket___error_result.md) errorResult) | websocket客户端接收error错误消息的回调函数定义。  | 
| (\* [WebSocket_OnCloseCallback](#websocket_onclosecallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_CloseResult](_web_socket___close_result.md) closeResult) | websocket客户端接收close消息的回调函数定义。  | 

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [NetStack_CertType](#netstack_certtype) { <br/>NetStack_CERT_TYPE_PEM = 0, <br/>NetStack_CERT_TYPE_DER = 1, <br/>NetStack_CERT_TYPE_INVALID <br/>} | 证书类型枚举。 |
| [WebSocket_ErrCode](#websocket_errcode) {<br/>WEBSOCKET_OK = 0, <br/>E_BASE = 1000, <br/>WEBSOCKET_CLIENT_NULL = (E_BASE + 1), <br/>WEBSOCKET_CLIENT_NOT_CREATED = (E_BASE + 2),<br/>WEBSOCKET_CONNECTION_ERROR = (E_BASE + 3), <br/>WEBSOCKET_CONNECTION_PARSE_URL_ERROR = (E_BASE + 5),<br/> WEBSOCKET_CONNECTION_NO_MEMORY = (E_BASE + 6), <br/>WEBSOCKET_CONNECTION_CLOSED_BY_PEER = (E_BASE + 7),<br/>WEBSOCKET_DESTROYED = (E_BASE + 8), <br/>WEBSOCKET_PROTOCOL_ERROR = (E_BASE + 9), <br/>WEBSOCKET_SEND_NO_MEMORY = (E_BASE + 10), <br/>WEBSOCKET_SEND_DATA_NULL = (E_BASE + 11),<br/>WEBSOCKET_DATA_LENGTH_EXCEEDED = (E_BASE + 12), <br/>WEBSOCKET_QUEUE_LENGTH_EXCEEDED = (E_BASE + 13),<br/> WEBSOCKET_NO_CLIENT_CONTEXT = (E_BASE + 14), <br/>WEBSOCKET_NO_HEADER_CONTEXT = (E_BASE + 15),<br/>WEBSOCKET_HEADER_EXCEEDED = (E_BASE + 16), <br/>WEBSOCKET_NO_CONNECTION = (E_BASE + 17), <br/>WEBSOCKET_NO_CONNECTION_CONTEXT = (E_BASE + 18)<br/>} | websocket错误码。  |
| [NetStack_CertificatePinningKind](#netstack_certificatepinningkind) {<br/>PUBLIC_KEY,<br/>} | 证书锁定类型。 |
| [NetStack_HashAlgorithm](#netstack_hashalgorithm) {<br/>SHA_256,<br/>} | 哈希算法类型。 |

### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_WebSocketClient_Constructor](#oh_websocketclient_constructor) ([WebSocket_OnOpenCallback](#websocket_onopencallback) onOpen, [WebSocket_OnMessageCallback](#websocket_onmessagecallback) onMessage, [WebSocket_OnErrorCallback](#websocket_onerrorcallback) onError, [WebSocket_OnCloseCallback](#websocket_onclosecallback) onclose) | Websocket客户端的构造函数。  |
| [OH_WebSocketClient_AddHeader](#oh_websocketclient_addheader) (struct [WebSocket](_web_socket.md) \*client, struct [WebSocket_Header](_web_socket___header.md) header) | 将header头信息添加到client客户端request中。  |
| [OH_WebSocketClient_Connect](#oh_websocketclient_connect) (struct [WebSocket](_web_socket.md) \*client, const char \*url, struct [WebSocket_RequestOptions](_web_socket___request_options.md) options) | 客户端连接服务端。  |
| [OH_WebSocketClient_Send](#oh_websocketclient_send) (struct [WebSocket](_web_socket.md) \*client, char \*data, size_t length) | 客户端向服务端发送数据。  |
| [OH_WebSocketClient_Close](#oh_websocketclient_close) (struct [WebSocket](_web_socket.md) \*client, struct [WebSocket_CloseOption](_web_socket___close_option.md) options) | 客户端主动关闭websocket连接。  |
| [OH_WebSocketClient_Destroy](#oh_websocketclient_destroy) (struct [WebSocket](_web_socket.md) \*client) | 释放websocket连接上下文和资源。  |
| [OH_NetStack_GetPinSetForHostName](#oh_netstack_getpinsetforhostname)(const char \*hostname, [NetStack_CertificatePinning](_net_stack___certificate_pinning.md) \*pin) | 获取证书锁定信息。 |
| [OH_NetStack_GetCertificatesForHostName](#oh_netstack_getcertificatesforhostname)(const char \*hostname, [NetStack_Certificates](_net_stack___certificates.md) \*certs) | 获取证书信息。 |
| [OH_Netstack_DestroyCertificatesContent](#oh_netstack_destroycertificatescontent)([NetStack_Certificates](_net_stack___certificates.md) \*certs) | 释放证书内容。 |

### 变量

| 名称 | 描述 |
| -------- | -------- |
| [NetStack_CertBlob::type](#type) | 证书类型。 |
| [NetStack_CertBlob::size](#size) | 证书内容长度。 |
| [NetStack_CertBlob::data](#data) | 证书内容。 |
| [NetStack_CertificatePinning::kind](#kind) | 证书锁定类型。 |
| [NetStack_CertificatePinning::hashAlgorithm](#hashalgorithm) | 哈希算法。 |
| [NetStack_CertificatePinning::publicKeyHash](#publickeyhash) | 哈希值。 |
| [NetStack_Certificates::content](#content) | 证书的PEM内容。 |
| [NetStack_Certificates::length](#length) | 证书数量。 |
| [WebSocket_CloseResult::code](#code-13) | 关闭值。  |
| [WebSocket_CloseResult::reason](#reason-13) | 关闭原因。  |
| [WebSocket_CloseOption::code](#code-23) | 关闭值。  |
| [WebSocket_CloseOption::reason](#reason-23) | 关闭原因。  |
| [WebSocket_ErrorResult::errorCode](#errorcode) | 错误码。  |
| [WebSocket_ErrorResult::errorMessage](#errormessage) | 错误的消息。  |
| [WebSocket_OpenResult::code](#code-33) | websocket客户端连接成功码。  |
| [WebSocket_OpenResult::reason](#reason-33) | websocket客户端连接原因。  |
| [WebSocket_Header::fieldName](#fieldname) | header头的字段名。  |
| [WebSocket_Header::fieldValue](#fieldvalue) | header头的字段内容。  |
| [WebSocket_Header](_web_socket___header.md) \* [WebSocket_Header::next](#next) | header头链表的next指针。  |
| [WebSocket_Header](_web_socket___header.md) \* WebSocket_RequestOptions::headers | header头信息。 |
| [WebSocket_OnOpenCallback](#websocket_onopencallback) [WebSocket::onOpen](#onopen) | 客户端接收连接消息的回调指针。  |
| [WebSocket_OnMessageCallback](#websocket_onmessagecallback) [WebSocket::onMessage](#onmessage) | 客户端接收消息的回调指针。  |
| [WebSocket_OnErrorCallback](#websocket_onerrorcallback) [WebSocket::onError](#onerror) | 客户端接收错误消息的回调指针。  |
| [WebSocket_OnCloseCallback](#websocket_onclosecallback) [WebSocket::onClose](#onclose) | 客户端接收关闭消息的回调指针。  |
| [WebSocket_RequestOptions](_web_socket___request_options.md) [WebSocket::requestOptions](#requestoptions) | 客户端建立连接请求内容。 |


## 类型定义说明


### WebSocket_OnCloseCallback

```
typedef void(* WebSocket_OnCloseCallback) (struct WebSocket *client, WebSocket_CloseResult closeResult)
```
**描述**
websocket客户端接收close消息的回调函数定义

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | websocket客户端  | 
| closeResult | websocket客户端接收关闭消息的内容  | 


### WebSocket_OnErrorCallback

```
typedef void(* WebSocket_OnErrorCallback) (struct WebSocket *client, WebSocket_ErrorResult errorResult)
```
**描述**
websocket客户端接收error错误消息的回调函数定义

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | websocket客户端  | 
| errorResult | websocket客户端接收连接错误消息的内容  | 


### WebSocket_OnMessageCallback

```
typedef void(* WebSocket_OnMessageCallback) (struct WebSocket *client, char *data, uint32_t length)
```
**描述**
websocket客户端接收数据的回调函数定义

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | websocket客户端  | 
| data | websocket客户端接收的数据  | 
| length | websocket客户端接收的数据长度  | 


### WebSocket_OnOpenCallback

```
typedef void(* WebSocket_OnOpenCallback) (struct WebSocket *client, WebSocket_OpenResult openResult)
```
**描述**
websocket客户端接收open消息的回调函数定义

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | websocket客户端  | 
| openResult | websocket客户端接收建立连接消息的内容  | 



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


### WebSocket_ErrCode

```
enum WebSocket_ErrCode
```
**描述**
websocket错误码

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| WEBSOCKET_OK  | 执行成功。 | 
| E_BASE  | 异常错误代码的基础。 | 
| WEBSOCKET_CLIENT_NULL  | websocket为空。 | 
| WEBSOCKET_CLIENT_NOT_CREATED  | websocket未创建。 | 
| WEBSOCKET_CONNECTION_ERROR  | websocket客户端连接错误。 | 
| WEBSOCKET_CONNECTION_PARSE_URL_ERROR  | websocket客户端连接参数解析错误。 | 
| WEBSOCKET_CONNECTION_NO_MEMORY  | websocket客户端连接时创建上下文无内存。 | 
| WEBSOCKET_CONNECTION_CLOSED_BY_PEER  | 初始化时候关闭。 | 
| WEBSOCKET_DESTROYED  | websocket连接被销毁。 | 
| WEBSOCKET_PROTOCOL_ERROR  | websocket客户端连接时候协议错误。 | 
| WEBSOCKET_SEND_NO_MEMORY  | websocket客户端发送数据时候没有足够内存。 | 
| WEBSOCKET_SEND_DATA_NULL  | websocket客户端发送数据为空。 | 
| WEBSOCKET_DATA_LENGTH_EXCEEDED  | websocket客户端发送数据长度超限制。 | 
| WEBSOCKET_QUEUE_LENGTH_EXCEEDED  | websocket客户端发送数据队列长度超限制。 | 
| WEBSOCKET_NO_CLIENT_CONTEXT  | websocket客户端上下文为空。 | 
| WEBSOCKET_NO_HEADER_CONTEXT  | websocket客户端header头异常。 | 
| WEBSOCKET_HEADER_EXCEEDED  | websocket客户端header头超过限制。 | 
| WEBSOCKET_NO_CONNECTION  | websocket客户端没有连接。 | 
| WEBSOCKET_NO_CONNECTION_CONTEXT  | websocket客户端没有连接上下文。 | 

### NetStack_CertificatePinningKind

```
enum NetStack_CertificatePinningKind
```

**描述**

证书锁定类型枚举。

**起始版本：** 12

| 枚举值     | 描述           |
| ---------- | -------------- |
| PUBLIC_KEY | 公钥锁定类型。 |

### NetStack_HashAlgorithm

```
enum NetStack_HashAlgorithm
```

**描述**

哈希算法。

**起始版本：** 12

| 枚举值  | 描述          |
| ------- | ------------- |
| SHA_256 | SHA-256算法。 |

## 函数说明


### OH_NetStack_VerifyCertification()

```
uint32_t OH_NetStack_VerifyCertification (const struct NetStack_CertBlob * cert, const struct NetStack_CertBlob * caCert )
```

**描述**

证书链校验接口。

**系统能力：** SystemCapability.Communication.NetStack

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

2305069 - 证书验证时发生错误调用或无效的参数.

### OH_NetStack_GetPinSetForHostName()

```
int32_t OH_NetStack_GetPinSetForHostName (const char * hostname, NetStack_CertificatePinning * pin)
```

**描述**

获取证书锁定信息。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 12

**参数:**

| 名称     | 描述                           |
| -------- | ------------------------------ |
| hostname | 主机名。                       |
| pin      | 用户接受证书锁定信息的结构体。 |

**返回：**

0 - 成功.

401- 参数设置错误.

2305999 - 内存错误.

### OH_NetStack_GetCertificatesForHostName()

```
int32_t OH_NetStack_GetCertificatesForHostName(const char * hostname, NetStack_Certificates * certs)
```

**描述**

获取证书信息。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 12

**参数:**

| 名称     | 描述                       |
| -------- | -------------------------- |
| hostname | 主机名。                   |
| certs    | 用户接受证书信息的结构体。 |

**返回：**

0 - 成功.

401- 参数设置错误.

2305999 - 内存错误.

### OH_Netstack_DestroyCertificatesContent()

```
void OH_Netstack_DestroyCertificatesContent(NetStack_Certificates * certs)
```

**描述**

释放证书内容(certs->content)，当NetStack_Certificates使用结束时调用此方法释放该结构体中证书的内存。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 12

**参数:**

| 名称  | 描述             |
| ----- | ---------------- |
| certs | 证书信息结构体。 |

### OH_WebSocketClient_AddHeader()

```
int OH_WebSocketClient_AddHeader (struct WebSocket * client, struct WebSocket_Header header )
```
**描述**
将header头信息添加到client客户端request中。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端指针。  | 
| header | header头信息。  | 

**返回：**

返回值为0表示执行成功。返回错细信息可以查看**OH_Websocket_ErrCode**。



### OH_WebSocketClient_Close()

```
int OH_WebSocketClient_Close (struct WebSocket * client, struct WebSocket_CloseOption options )
```
**描述**
客户端主动关闭websocket连接。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端。  | 
| url | 客户端要连接到服务端的地址。  | 
| options | 发起关闭连接的可选参数。  | 

**返回：**

返回值为0表示执行成功。返回错细信息可以查看**OH_Websocket_ErrCode**。

**Permission：**

ohos.permission.INTERNET


### OH_WebSocketClient_Connect()

```
int OH_WebSocketClient_Connect (struct WebSocket * client, const char * url, struct WebSocket_RequestOptions options )
```
**描述**
客户端连接服务端。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端指针。  | 
| url | 客户端要连接到服务端的地址。  | 
| options | 发起连接的可选参数。  | 

**返回：**

返回值为0表示执行成功。返回错细信息可以查看**OH_Websocket_ErrCode**。

**Permission：**

ohos.permission.INTERNET


### OH_WebSocketClient_Constructor()

```
struct WebSocket* OH_WebSocketClient_Constructor (WebSocket_OnOpenCallback onOpen, WebSocket_OnMessageCallback onMessage, WebSocket_OnErrorCallback onError, WebSocket_OnCloseCallback onclose )
```
**描述**
Websocket客户端的构造函数。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| onMessage | 客户端定义的接收消息的回调函数。  | 
| onClose | 客户端定义的关闭消息的回调函数。  | 
| onError | 客户端定义的错误消息的回调函数。  | 
| onOpen | 客户端定义的建立连接消息的回调函数。  | 

**返回：**

成功返回客户端指针，失败返回为NULL。



### OH_WebSocketClient_Destroy()

```
int OH_WebSocketClient_Destroy (struct WebSocket * client)
```
**描述**
释放websocket连接上下文和资源。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端。  | 

**返回：**

返回值为0表示执行成功。返回错细信息可以查看**OH_Websocket_ErrCode**。

**Permission：**

ohos.permission.INTERNET


### OH_WebSocketClient_Send()

```
int OH_WebSocketClient_Send (struct WebSocket * client, char * data, size_t length )
```
**描述**
客户端向服务端发送数据。

**系统能力：** SystemCapability.Communication.NetStack

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| client | 客户端。  | 
| data | 客户端发送的数据。  | 
| length | 客户端发送的数据长度。  | 

**返回：**

0 - 成功.

返回值为0表示执行成功。返回错细信息可以查看**OH_Websocket_ErrCode**。

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

### kind

```
enum NetStack_CertificatePinningKind NetStack_CertificatePinning::kind
```

**描述**

证书锁定类型。

### hashAlgorithm

```
enum NetStack_HashAlgorithm NetStack_CertificatePinning::hashAlgorithm
```

**描述**

哈希算法。

### publicKeyHash

```
char* NetStack_CertificatePinning::publicKeyHash
```

**描述**

哈希值。

### content

```
char** NetStack_Certificates::content
```

**描述**

证书的PEM内容。

### length

```
size_t NetStack_Certificates::length
```

**描述**

证书数量。

### code [1/3]

```
uint32_t WebSocket_CloseResult::code
```

**描述**

关闭值。


### code [2/3]

```
uint32_t WebSocket_CloseOption::code
```

**描述**

关闭值。


### code [3/3]

```
uint32_t WebSocket_OpenResult::code
```

**描述**

websocket客户端连接成功码。


### errorCode

```
uint32_t WebSocket_ErrorResult::errorCode
```

**描述**

错误码。


### errorMessage

```
const char* WebSocket_ErrorResult::errorMessage
```

**描述**

错误的消息。


### fieldName

```
const char* WebSocket_Header::fieldName
```

**描述**

header头的字段名。


### fieldValue

```
const char* WebSocket_Header::fieldValue
```

**描述**

header头的字段内容。


### next

```
struct WebSocket_Header* WebSocket_Header::next
```

**描述**

header头链表的next指针。


### onClose

```
WebSocket_OnCloseCallback WebSocket::onClose
```

**描述**

客户端接收关闭消息的回调指针。


### onError

```
WebSocket_OnErrorCallback WebSocket::onError
```

**描述**

客户端接收错误消息的回调指针。


### onMessage

```
WebSocket_OnMessageCallback WebSocket::onMessage
```

**描述**

客户端接收消息的回调指针。


### onOpen

```
WebSocket_OnOpenCallback WebSocket::onOpen
```

**描述**

客户端接收连接消息的回调指针。


### reason [1/3]

```
const char* WebSocket_CloseResult::reason
```

**描述**

关闭原因。


### reason [2/3]

```
const char* WebSocket_CloseOption::reason
```

**描述**

关闭原因。


### reason [3/3]

```
const char* WebSocket_OpenResult::reason
```

**描述**

websocket客户端连接原因。


### requestOptions

```
WebSocket_RequestOptions WebSocket::requestOptions
```

**描述**

客户端建立连接请求内容。