# Netstack


## Overview

Provides C APIs for the network protocol stack module.

**Since**: 11


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [net_ssl_c.h](net__ssl__c_8h.md) | Defines C APIs for the SSL/TLS certificate chain verification module.| 
| [net_ssl_c_type.h](net__ssl__c__type_8h.md) | Defines data structures for the C APIs of the SSL/TLS certificate chain verification module.| 
| [net_websocket.h](net__websocket_8h.md) | Defines C APIs for the WebSocket client module.| 
| [net_websocket_type.h](net__websocket__type_8h.md) | Defines data structures for the C APIs of the WebSocket client module.| 


### Structs

| Name| Description|
| -------- | -------- |
| [NetStack_CertBlob](_net_stack___cert_blob.md) | Certificate data structure.|
| [NetStack_CertificatePinning](_net_stack___certificate_pinning.md) | Data structure of the certificate lock information.|
| [NetStack_Certificates](_net_stack___certificates.md) | Data structure of the certificate information.|
| [WebSocket_CloseResult](_web_socket___close_result.md) | Parameters for the connection closure received by the WebSocket client. |
| [WebSocket_CloseOption](_web_socket___close_option.md) | Parameters for the proactive connection closure initiated by the WebSocket client. |
| [WebSocket_ErrorResult](_web_socket___error_result.md) | Parameters for the connection error received by the WebSocket client. |
| [WebSocket_OpenResult](_web_socket___open_result.md) | Parameters for the connection success received by the WebSocket client. |
| [WebSocket_Header](_web_socket___header.md) | Header linked list added to the WebSocket client. |
| [WebSocket_RequestOptions](_web_socket___request_options.md) | Parameters for the connection between the WebSocket client and server. |
| [WebSocket](_web_socket.md) | WebSocket client structure. |


### Types

| Name| Description| 
| -------- | -------- |
| (\* [WebSocket_OnOpenCallback](#websocket_onopencallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_OpenResult](_web_socket___open_result.md) openResult) | Callback invoked when the WebSocket client receives an **open** message. | 
| (\* [WebSocket_OnMessageCallback](#websocket_onmessagecallback)) (struct [WebSocket](_web_socket.md) \*client, char \*data, uint32_t length) | Callback invoked when the WebSocket client receives data. | 
| (\* [WebSocket_OnErrorCallback](#websocket_onerrorcallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_ErrorResult](_web_socket___error_result.md) errorResult) | Callback invoked when the WebSocket client receives an error message. | 
| (\* [WebSocket_OnCloseCallback](#websocket_onclosecallback)) (struct [WebSocket](_web_socket.md) \*client, [WebSocket_CloseResult](_web_socket___close_result.md) closeResult) | Callback invoked when the WebSocket client receives a **close** message. | 

### Enums

| Name| Description|
| -------- | -------- |
| [NetStack_CertType](#netstack_certtype) { <br>NetStack_CERT_TYPE_PEM = 0, <br>NetStack_CERT_TYPE_DER = 1, <br>NetStack_CERT_TYPE_INVALID <br>} | Certificate type enums.|
| [WebSocket_ErrCode](#websocket_errcode) {<br>WEBSOCKET_OK = 0, <br>E_BASE = 1000, <br>WEBSOCKET_CLIENT_NULL = (E_BASE + 1), <br>WEBSOCKET_CLIENT_NOT_CREATED = (E_BASE + 2),<br>WEBSOCKET_CONNECTION_ERROR = (E_BASE + 3), <br>WEBSOCKET_CONNECTION_PARSE_URL_ERROR = (E_BASE + 5),<br> WEBSOCKET_CONNECTION_NO_MEMORY = (E_BASE + 6), <br>WEBSOCKET_CONNECTION_CLOSED_BY_PEER = (E_BASE + 7),<br>WEBSOCKET_DESTROYED = (E_BASE + 8), <br>WEBSOCKET_PROTOCOL_ERROR = (E_BASE + 9), <br>WEBSOCKET_SEND_NO_MEMORY = (E_BASE + 10), <br>WEBSOCKET_SEND_DATA_NULL = (E_BASE + 11),<br>WEBSOCKET_DATA_LENGTH_EXCEEDED = (E_BASE + 12), <br>WEBSOCKET_QUEUE_LENGTH_EXCEEDED = (E_BASE + 13),<br> WEBSOCKET_NO_CLIENT_CONTEXT = (E_BASE + 14), <br>WEBSOCKET_NO_HEADER_CONTEXT = (E_BASE + 15),<br>WEBSOCKET_HEADER_EXCEEDED = (E_BASE + 16), <br>WEBSOCKET_NO_CONNECTION = (E_BASE + 17), <br>WEBSOCKET_NO_CONNECTION_CONTEXT = (E_BASE + 18)<br>} | WebSocket error codes. |
| [NetStack_CertificatePinningKind](#netstack_certificatepinningkind) {<br>PUBLIC_KEY,<br>} | Certificate lock type.|
| [NetStack_HashAlgorithm](#netstack_hashalgorithm) {<br>SHA_256,<br>} | Hash algorithm type.|

### Functions

| Name| Description|
| -------- | -------- |
| [OH_WebSocketClient_Constructor](#oh_websocketclient_constructor) ([WebSocket_OnOpenCallback](#websocket_onopencallback) onOpen, [WebSocket_OnMessageCallback](#websocket_onmessagecallback) onMessage, [WebSocket_OnErrorCallback](#websocket_onerrorcallback) onError, [WebSocket_OnCloseCallback](#websocket_onclosecallback) onclose) | Constructor used to create a **WebSocketClient** instance. |
| [OH_WebSocketClient_AddHeader](#oh_websocketclient_addheader) (struct [WebSocket](_web_socket.md) \*client, struct [WebSocket_Header](_web_socket___header.md) header) | Adds the header information to the client request. |
| [OH_WebSocketClient_Connect](#oh_websocketclient_connect) (struct [WebSocket](_web_socket.md) \*client, const char \*url, struct [WebSocket_RequestOptions](_web_socket___request_options.md) options) | Connects the client to the server. |
| [OH_WebSocketClient_Send](#oh_websocketclient_send) (struct [WebSocket](_web_socket.md) \*client, char \*data, size_t length) | Sends data from the client to the server. |
| [OH_WebSocketClient_Close](#oh_websocketclient_close) (struct [WebSocket](_web_socket.md) \*client, struct [WebSocket_CloseOption](_web_socket___close_option.md) options) | Lets the WebSocket client proactively close the connection. |
| [OH_WebSocketClient_Destroy](#oh_websocketclient_destroy) (struct [WebSocket](_web_socket.md) \*client) | Releases the context and resources of the WebSocket connection. |
| [OH_NetStack_GetPinSetForHostName](#oh_netstack_getpinsetforhostname)(const char \*hostname, [NetStack_CertificatePinning](_net_stack___certificate_pinning.md) \*pin) | Obtains the certificate lock information.|
| [OH_NetStack_GetCertificatesForHostName](#oh_netstack_getcertificatesforhostname)(const char \*hostname, [NetStack_Certificates](_net_stack___certificates.md) \*certs) | Obtains certificate information.|
| [OH_Netstack_DestroyCertificatesContent](#oh_netstack_destroycertificatescontent)([NetStack_Certificates](_net_stack___certificates.md) \*certs) | Releases the certificate content.|

### Variables

| Name| Description|
| -------- | -------- |
| [NetStack_CertBlob::type](#type) | Certificate type.|
| [NetStack_CertBlob::size](#size) | Certificate content length.|
| [NetStack_CertBlob::data](#data) | Certificate content.|
| [NetStack_CertificatePinning::kind](#kind) | Certificate lock type.|
| [NetStack_CertificatePinning::hashAlgorithm](#hashalgorithm) | Hash algorithm.|
| [NetStack_CertificatePinning::publicKeyHash](#publickeyhash) | Hash value.|
| [NetStack_Certificates::content](#content) | PEM content of the certificate.|
| [NetStack_Certificates::length](#length) | Number of certificates.|
| [WebSocket_CloseResult::code](#code-13) | Connection close code. |
| [WebSocket_CloseResult::reason](#reason-13) | Connection close reason for the WebSocket client. |
| [WebSocket_CloseOption::code](#code-23) | Connection close code. |
| [WebSocket_CloseOption::reason](#reason-23) | Connection close reason for the WebSocket client. |
| [WebSocket_ErrorResult::errorCode](#errorcode) | Error code. |
| [WebSocket_ErrorResult::errorMessage](#errormessage) | Error message. |
| [WebSocket_OpenResult::code](#code-33) | Connection success code for the WebSocket client. |
| [WebSocket_OpenResult::reason](#reason-33) | Connection reason for the WebSocket client. |
| [WebSocket_Header::fieldName](#fieldname) | Header field name. |
| [WebSocket_Header::fieldValue](#fieldvalue) | Header field content. |
| [WebSocket_Header](_web_socket___header.md) \* [WebSocket_Header::next](#next) | Next pointer of the header linked list. |
| [WebSocket_Header](_web_socket___header.md) \* WebSocket_RequestOptions::headers | Header information.|
| [WebSocket_OnOpenCallback](#websocket_onopencallback) [WebSocket::onOpen](#onopen) | Pointer to the callback invoked when the WebSocket client receives a connection message. |
| [WebSocket_OnMessageCallback](#websocket_onmessagecallback) [WebSocket::onMessage](#onmessage) | Pointer to the callback invoked when the WebSocket client receives a message. |
| [WebSocket_OnErrorCallback](#websocket_onerrorcallback) [WebSocket::onError](#onerror) | Pointer to the callback invoked when the WebSocket client receives an error message. |
| [WebSocket_OnCloseCallback](#websocket_onclosecallback) [WebSocket::onClose](#onclose) | Pointer to the callback invoked when the WebSocket client receives a **close** message. |
| [WebSocket_RequestOptions](_web_socket___request_options.md) [WebSocket::requestOptions](#requestoptions) | Content of the request for establishing a connection on the client.|


## Type Description


### WebSocket_OnCloseCallback

```
typedef void(* WebSocket_OnCloseCallback) (struct WebSocket *client, WebSocket_CloseResult closeResult)
```
**Description**
Callback invoked when the WebSocket client receives a **close** message.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| client | WebSocket client. | 
| closeResult | Content of the close message received by the WebSocket client. | 


### WebSocket_OnErrorCallback

```
typedef void(* WebSocket_OnErrorCallback) (struct WebSocket *client, WebSocket_ErrorResult errorResult)
```
**Description**
Callback invoked when the WebSocket client receives an error message.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| client | WebSocket client. | 
| errorResult | Content of the error message received by the WebSocket client. | 


### WebSocket_OnMessageCallback

```
typedef void(* WebSocket_OnMessageCallback) (struct WebSocket *client, char *data, uint32_t length)
```
**Description**
Callback invoked when the WebSocket client receives data.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| client | WebSocket client. | 
| data | Data received by the WebSocket client. | 
| length | Length of the data received by the WebSocket client. | 


### WebSocket_OnOpenCallback

```
typedef void(* WebSocket_OnOpenCallback) (struct WebSocket *client, WebSocket_OpenResult openResult)
```
**Description**
Callback invoked when the WebSocket client receives an **open** message.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| client | WebSocket client. | 
| openResult | Content of the connection setup message received by the WebSocket client. | 



## Enum Description


### NetStack_CertType

```
enum NetStack_CertType
```

**Description**

Certificate type enums.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| NetStack_CERT_TYPE_PEM | PEM certificate.| 
| NetStack_CERT_TYPE_DER | DER certificate.| 
| NetStack_CERT_TYPE_INVALID | Invalid certificate.| 


### WebSocket_ErrCode

```
enum WebSocket_ErrCode
```
**Description**
WebSocket error codes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| WEBSOCKET_OK  | Execution success.| 
| E_BASE  | Base error code.| 
| WEBSOCKET_CLIENT_NULL  | WebSocket is null.| 
| WEBSOCKET_CLIENT_NOT_CREATED  | WebSocket is not created.| 
| WEBSOCKET_CONNECTION_ERROR  | An error occurs while connecting the WebSocket client.| 
| WEBSOCKET_CONNECTION_PARSE_URL_ERROR  | An error occurs while parsing WebSocket connection parameters.| 
| WEBSOCKET_CONNECTION_NO_MEMORY  | The memory is insufficient for creating a context during WebSocket connection setup.| 
| WEBSOCKET_CONNECTION_CLOSED_BY_PEER  | The WebSocket connection is closed during initialization.| 
| WEBSOCKET_DESTROYED  | The WebSocket connection is destroyed.| 
| WEBSOCKET_PROTOCOL_ERROR  | An incorrect protocol is used for WebSocket connection.| 
| WEBSOCKET_SEND_NO_MEMORY  | The memory for the WebSocket client to send data is insufficient.| 
| WEBSOCKET_SEND_DATA_NULL  | The data sent by the WebSocket client is null.| 
| WEBSOCKET_DATA_LENGTH_EXCEEDED  | The length of the data sent by the WebSocket client exceeds the limit.| 
| WEBSOCKET_QUEUE_LENGTH_EXCEEDED  | The queue length of the data sent by the WebSocket client exceeds the limit.| 
| WEBSOCKET_NO_CLIENT_CONTEXT  | The context of the WebSocket client is null.| 
| WEBSOCKET_NO_HEADER_CONTEXT  | The header of the WebSocket client is abnormal.| 
| WEBSOCKET_HEADER_EXCEEDED  | The header of the WebSocket client exceeds the limit.| 
| WEBSOCKET_NO_CONNECTION  | The WebSocket client is not connected.| 
| WEBSOCKET_NO_CONNECTION_CONTEXT  | The WebSocket client does not have the connection context.| 

### NetStack_CertificatePinningKind

```
enum NetStack_CertificatePinningKind
```

**Description**

Enumerates certificate lock types.

**Since**: 12

| Value    | Description          |
| ---------- | -------------- |
| PUBLIC_KEY | Public key lock type.|

### NetStack_HashAlgorithm

```
enum NetStack_HashAlgorithm
```

**Description**

Hash algorithm.

**Since**: 12

| Value | Description         |
| ------- | ------------- |
| SHA_256 | SHA-256 algorithm.|

## Function Description


### OH_NetStack_VerifyCertification()

```
uint32_t OH_NetStack_VerifyCertification (const struct NetStack_CertBlob * cert, const struct NetStack_CertBlob * caCert )
```

**Description**

Verifies the certificate chain.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| cert | Certificate to be verified.| 
| caCert | Certificate specified by the user. If this parameter is left blank, the preset certificate is used for verification.| 

**Returns**

**0**: Success.

**2305001**: Unknown error.

**2305002**: Failed to obtain the issuer certificate.

**2305003**: Failed to obtain the certificate revocation list (CRL).

**2305004**: Failed to decrypt the certificate signature.

**2305005**: Failed to decrypt the CRL signature.

**2305006**: Failed to decode the issuer public key.

**2305007**: Failed to sign the certificate.

**2305008**: Failed to sign the CRL.

**2305009**: The certificate has not taken effect.

**2305010**: The certificate has expired.

**2305011**: The CRL has not taken effect.

**2305012**: The CRL has expired.

**2305023**: The certificate has been revoked.

**2305024**: The certificate authority (CA) is invalid.

**2305027**: The certificate is untrusted.

### OH_NetStack_GetPinSetForHostName()

```
int32_t OH_NetStack_GetPinSetForHostName (const char * hostname, NetStack_CertificatePinning * pin)
```

**Description**

Obtains the certificate lock information.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 12

**Parameters**

| Name    | Description                          |
| -------- | ------------------------------ |
| hostname | Host name.                      |
| pin      | Structure of the certificate lock information.|

**Returns**

**0**: Success.

**401**: Parameter error.

**2305999**: Memory error.

### OH_NetStack_GetCertificatesForHostName()

```
int32_t OH_NetStack_GetCertificatesForHostName(const char * hostname, NetStack_Certificates * certs)
```

**Description**

Obtains the certificate information.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 12

**Parameters**

| Name    | Description                      |
| -------- | -------------------------- |
| hostname | Host name.                  |
| certs    | Structure of the certificate information.|

**Returns**

**0**: Success.

**401**: Incorrect parameter settings.

**2305999**: Memory error.

### OH_Netstack_DestroyCertificatesContent()

```
void OH_Netstack_DestroyCertificatesContent(NetStack_Certificates * certs)
```

**Description**

Releases the certificate content. If **NetStack_Certificates** is no longer used, you can call this API to release the certificate content in it to free up memory space.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 12

**Parameters**

| Name | Description            |
| ----- | ---------------- |
| certs | Defines the certificate information structure.|

### OH_WebSocketClient_AddHeader()

```
int OH_WebSocketClient_AddHeader (struct WebSocket * client, struct WebSocket_Header header )
```
**Description**
Adds the header information to the client request.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| client | Pointer to the WebSocket client. | 
| header | Header information. | 

**Returns**

Returns **0** if the operation is successful. For details about error codes, see **OH_Websocket_ErrCode**.



### OH_WebSocketClient_Close()

```
int OH_WebSocketClient_Close (struct WebSocket * client, struct WebSocket_CloseOption options )
```
**Description**
Lets the WebSocket client proactively close the connection.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| client | WebSocket client. | 
| url | IP address for the WebSocket client to connect to the server. | 
| options | Optional parameters for the connection closure. | 

**Returns**

Returns **0** if the operation is successful. For details about error codes, see **OH_Websocket_ErrCode**.

**Required Permissions**

ohos.permission.INTERNET


### OH_WebSocketClient_Connect()

```
int OH_WebSocketClient_Connect (struct WebSocket * client, const char * url, struct WebSocket_RequestOptions options )
```
**Description**
Connects the WebSocket client to the server.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| client | Pointer to the WebSocket client. | 
| url | IP address for the WebSocket client to connect to the server. | 
| options | Optional parameters for connection. | 

**Returns**

Returns **0** if the operation is successful. For details about error codes, see **OH_Websocket_ErrCode**.

**Required Permissions**

ohos.permission.INTERNET


### OH_WebSocketClient_Constructor()

```
struct WebSocket* OH_WebSocketClient_Constructor (WebSocket_OnOpenCallback onOpen, WebSocket_OnMessageCallback onMessage, WebSocket_OnErrorCallback onError, WebSocket_OnCloseCallback onclose )
```
**Description**
Constructor used to create a **WebSocketClient** instance.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| onMessage | Callback invoked when the WebSocket client receives a message. | 
| onClose | Callback invoked when the WebSocket client receives a **close** message. | 
| onError | Callback invoked when the WebSocket client receives an **error** message. | 
| onOpen | Callback invoked when the WebSocket client receives an **open** message. | 

**Returns**

Returns the pointer to the WebSocket client if the operation is successful; returns NULL otherwise.



### OH_WebSocketClient_Destroy()

```
int OH_WebSocketClient_Destroy (struct WebSocket * client)
```
**Description**
Releases the context and resources of the WebSocket connection.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| client | WebSocket client. | 

**Returns**

Returns **0** if the operation is successful. For details about error codes, see **OH_Websocket_ErrCode**.

**Required Permissions**

ohos.permission.INTERNET


### OH_WebSocketClient_Send()

```
int OH_WebSocketClient_Send (struct WebSocket * client, char * data, size_t length )
```
**Description**
Sends data from the WebSocket client to the server.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| client | WebSocket client. | 
| data | Data sent by the WebSocket client. | 
| length | Length of the data sent by the WebSocket client. | 

**Returns**

 

Returns **0** if the operation is successful. For details about error codes, see **OH_Websocket_ErrCode**.

**Required Permissions**

ohos.permission.INTERNET

## Variable Description


### data

```
uint8_t* NetStack_CertBlob::data
```

**Description**

Certificate content.


### size

```
uint32_t NetStack_CertBlob::size
```

**Description**

Certificate content length.


### type

```
enum NetStack_CertType NetStack_CertBlob::type
```

**Description**

Certificate type.

### kind

```
enum NetStack_CertificatePinningKind NetStack_CertificatePinning::kind
```

**Description**

Certificate lock type.

### hashAlgorithm

```
enum NetStack_HashAlgorithm NetStack_CertificatePinning::hashAlgorithm
```

**Description**

Hash algorithm.

### publicKeyHash

```
char* NetStack_CertificatePinning::publicKeyHash
```

**Description**

Hash value.

### content

```
char** NetStack_Certificates::content
```

**Description**

PEM content of the certificate.

### length

```
size_t NetStack_Certificates::length
```

**Description**

Number of certificates.

### code [1/3]

```
uint32_t WebSocket_CloseResult::code
```

**Description**

Connection close code.


### code [2/3]

```
uint32_t WebSocket_CloseOption::code
```

**Description**

Connection close code.


### code [3/3]

```
uint32_t WebSocket_OpenResult::code
```

**Description**

Connection success code for the WebSocket client.


### errorCode

```
uint32_t WebSocket_ErrorResult::errorCode
```

**Description**

Error code.


### errorMessage

```
const char* WebSocket_ErrorResult::errorMessage
```

**Description**

Error message.


### fieldName

```
const char* WebSocket_Header::fieldName
```

**Description**

Header field name.


### fieldValue

```
const char* WebSocket_Header::fieldValue
```

**Description**

Header field content.


### next

```
struct WebSocket_Header* WebSocket_Header::next
```

**Description**

Next pointer of the header linked list.


### onClose

```
WebSocket_OnCloseCallback WebSocket::onClose
```

**Description**

Pointer to the callback invoked when the WebSocket client receives a close message.


### onError

```
WebSocket_OnErrorCallback WebSocket::onError
```

**Description**

Pointer to the callback invoked when the WebSocket client receives an error message.


### onMessage

```
WebSocket_OnMessageCallback WebSocket::onMessage
```

**Description**

Pointer to the callback invoked when the WebSocket client receives a message.


### onOpen

```
WebSocket_OnOpenCallback WebSocket::onOpen
```

**Description**

Pointer to the callback invoked when the WebSocket client receives a connection message.


### reason [1/3]

```
const char* WebSocket_CloseResult::reason
```

**Description**

Connection close reason for the WebSocket client.


### reason [2/3]

```
const char* WebSocket_CloseOption::reason
```

**Description**

Connection close reason for the WebSocket client.


### reason [3/3]

```
const char* WebSocket_OpenResult::reason
```

**Description**

Connection reason for the WebSocket client.


### requestOptions

```
WebSocket_RequestOptions WebSocket::requestOptions
```

**Description**

Options of the connection request.
