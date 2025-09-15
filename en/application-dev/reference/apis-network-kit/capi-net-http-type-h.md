# net_http_type.h
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## Overview

Defines the data structures for the C APIs of the HTTP request module.

**File to include**: <network/netstack/net_http_type.h>

**Library**: libnet_http.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20

**Related module**: [netstack](capi-netstack.md)

## Summary

### Structs

| Name| typedef Keyword| Description                                                                                     |
| -- | -- |-----------------------------------------------------------------------------------------|
| [Http_Buffer](capi-netstack-http-buffer.md) | Http_Buffer | Defines the HTTP buffer structure.                                                                             |
| [Http_HeaderValue](capi-netstack-http-headervalue.md) | Http_HeaderValue | Defines the type of a mapped value in a request or response header.                                                                       |
| [Http_HeaderEntry](capi-netstack-http-headerentry.md) | Http_HeaderEntry | Defines all key-value pairs in the request or response header.                                                                       |
| [Http_ClientCert](capi-netstack-http-clientcert.md) | Http_ClientCert | Defines the client certificate sent to a remote server, which will be used by the server to verify the identity of the client.                                                     |
| [Http_CustomProxy](capi-netstack-http-customproxy.md) | Http_CustomProxy | Defines the custom proxy configuration.                                                                             |
| [Http_Proxy](capi-netstack-http-proxy.md) | Http_Proxy | Defines the proxy configuration structure.                                                                               |
| [Http_PerformanceTiming](capi-netstack-http-performancetiming.md) | Http_PerformanceTiming | Defines the HTTP response timing information, which will be collected via [Http_Response.performanceTiming](capi-netstack-http-response.md#member-variables).|
| [Http_RequestOptions](capi-netstack-http-requestoptions.md) | Http_RequestOptions | Defines the structure of HTTP requests.                                                                        |
| [Http_Response](capi-netstack-http-response.md) | Http_Response | Defines the structure of HTTP responses.                                                                          |
| [Http_Request](capi-netstack-http-request.md) | Http_Request | Defines an HTTP request.                                                                             |
| [Http_EventsHandler](capi-netstack-http-eventshandler.md) | Http_EventsHandler | Defines the callback for various HTTP events.                                                                       |
| [Http_Headers](capi-netstack-http-headers.md) | Http_Headers | Defines the header of an HTTP request or response.                                                                       |

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Http_ErrCode](#http_errcode) | Http_ErrCode | Enumerates the error codes of an HTTP request.|
| [Http_ResponseCode](#http_responsecode) | Http_ResponseCode | Enumerates the result codes of an HTTP response.|
| [Http_AddressFamilyType](#http_addressfamilytype) | Http_AddressFamilyType | Defines the IP address family of the target domain name.|
| [Http_HttpProtocol](#http_httpprotocol) | Http_HttpProtocol | Enumerates HTTP protocol versions.|
| [Http_CertType](#http_certtype) | Http_CertType | Enumerates certificate types.|
| [Http_ProxyType](#http_proxytype) | Http_ProxyType | Enumerates proxy types.|

### Macros

| Name                              | Description                                                                                   |
|----------------------------------|---------------------------------------------------------------------------------------|
| OHOS_HTTP_MAX_PATH_LEN 128       | Defines the maximum path length of an HTTP request.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack  |
| OHOS_HTTP_MAX_STR_LEN 256        | Defines the maximum string length of an HTTP request.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack    |
| OHOS_HTTP_DNS_SERVER_NUM_MAX 3   | Defines the maximum number of DNS servers for an HTTP request.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack |
| NET_HTTP_METHOD_GET "GET"        | Sets the HTTP request method to GET.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack    |
| NET_HTTPMETHOD_HEAD "HEAD"       | Sets the HTTP request method to HEAD.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack   |
| NET_HTTPMETHOD_OPTIONS "OPTIONS" | Sets the HTTP request method to OPTIONS.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack|
| NET_HTTPMETHOD_TRACE "TRACE"     | Sets the HTTP request method to TRACE.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack  |
| NET_HTTPMETHOD_DELETE "DELETE"   | Sets the HTTP request method to DELETE.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack |
| NET_HTTP_METHOD_POST "POST"      | Sets the HTTP request method to POST.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack   |
| NET_HTTP_METHOD_PUT "PUT"        | Sets the HTTP request method to PUT.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack    |
| NET_HTTP_METHOD_PATCH "CONNECT"  | Sets the HTTP request method to CONNECT.<br>**Since**: 20<br>**System capability**: SystemCapability.Communication.NetStack|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*Http_ResponseCallback)(struct Http_Response *response, uint32_t errCode)](#http_responsecallback) | Http_ResponseCallback | Callback invoked when an HTTP response is received.|
| [typedef void (\*Http_OnDataReceiveCallback)(const char *data, size_t length)](#http_ondatareceivecallback) | Http_OnDataReceiveCallback | Callback invoked when data is received.|
| [typedef void (\*Http_OnProgressCallback)(uint64_t totalSize, uint64_t transferredSize)](#http_onprogresscallback) | Http_OnProgressCallback | Callback invoked during request/response data transmission.|
| [typedef void (\*Http_OnHeaderReceiveCallback)(Http_Headers *headers)](#http_onheaderreceivecallback) | Http_OnHeaderReceiveCallback | Callback invoked when an HTTP response header is received.|
| [typedef void (\*Http_OnVoidCallback)(void)](#http_onvoidcallback) | Http_OnVoidCallback | Callback invoked when a DataEnd or Cancel event is received.|

## Enum Description

### Http_ErrCode

```
enum Http_ErrCode
```

**Overview**

Enumerates the error codes of an HTTP request.

**Since**: 20

| Enum| Description|
| -- | -- |
| OH_HTTP_RESULT_OK = 0 | Request succeeded.|
| OH_HTTP_PARAMETER_ERROR = 401 | Invalid parameter.|
| OH_HTTP_PERMISSION_DENIED = 201 | Permission denied.|
| OH_HTTP_NETSTACK_E_BASE = 2300000 | Base error code offset.|
| OH_HTTP_UNSUPPORTED_PROTOCOL = (OH_HTTP_NETSTACK_E_BASE + 1) | Unsupported protocol.|
| OH_HTTP_INVALID_URL = (OH_HTTP_NETSTACK_E_BASE + 3) | Incorrect URL format.|
| OH_HTTP_RESOLVE_PROXY_FAILED = (OH_HTTP_NETSTACK_E_BASE + 5) | Failed to resolve the domain name of the proxy server.|
| OH_HTTP_RESOLVE_HOST_FAILED = (OH_HTTP_NETSTACK_E_BASE + 6) | Failed to resolve the domain name.|
| OH_HTTP_CONNECT_SERVER_FAILED = (OH_HTTP_NETSTACK_E_BASE + 7) | Failed to connect to the server.|
| OH_HTTP_INVALID_SERVER_RESPONSE = (OH_HTTP_NETSTACK_E_BASE + 8) | Invalid data returned by the server.|
| OH_HTTP_ACCESS_REMOTE_DENIED = (OH_HTTP_NETSTACK_E_BASE + 9) | Access to remote resources denied.|
| OH_HTTP_HTTP2_FRAMING_ERROR = (OH_HTTP_NETSTACK_E_BASE + 16) | Error detected at the HTTP2 framework layer.|
| OH_HTTP_TRANSFER_PARTIAL_FILE = (OH_HTTP_NETSTACK_E_BASE + 18) | Files partially transferred.|
| OH_HTTP_WRITE_DATA_FAILED = (OH_HTTP_NETSTACK_E_BASE + 23) | Failed to write the received data to the disk or application.|
| OH_HTTP_UPLOAD_FAILED = (OH_HTTP_NETSTACK_E_BASE + 25) | Failed to upload data.|
| OH_HTTP_OPEN_LOCAL_DATA_FAILED = (OH_HTTP_NETSTACK_E_BASE + 26) | Failed to open or read the local data in the file or application.|
| OH_HTTP_OUT_OF_MEMORY = (OH_HTTP_NETSTACK_E_BASE + 27) | Insufficient memory.|
| OH_HTTP_OPERATION_TIMEOUT = (OH_HTTP_NETSTACK_E_BASE + 28) | Operation timeout.|
| OH_HTTP_TOO_MANY_REDIRECTIONS = (OH_HTTP_NETSTACK_E_BASE + 47) | Number of redirections reaching the maximum.|
| OH_HTTP_SERVER_RETURNED_NOTHING = (OH_HTTP_NETSTACK_E_BASE + 52) | No content (header or data) returned by the server.|
| OH_HTTP_SEND_DATA_FAILED = (OH_HTTP_NETSTACK_E_BASE + 55) | Failed to send data via Bluetooth.|
| OH_HTTP_RECEIVE_DATA_FAILED = (OH_HTTP_NETSTACK_E_BASE + 56) | Failed to receive data.|
| OH_HTTP_SSL_CERTIFICATE_ERROR = (OH_HTTP_NETSTACK_E_BASE + 58) | Invalid local SSL certificate.|
| OH_HTTP_SSL_CIPHER_USED_ERROR = (OH_HTTP_NETSTACK_E_BASE + 59) | Specified cipher suite unavailable.|
| OH_HTTP_INVALID_SSL_PEER_CERT = (OH_HTTP_NETSTACK_E_BASE + 60) | Invalid SSL peer certificate or SSH remote key.|
| OH_HTTP_INVALID_ENCODING_FORMAT = (OH_HTTP_NETSTACK_E_BASE + 61) | Invalid HTTP encoding format.|
| OH_HTTP_FILE_TOO_LARGE = (OH_HTTP_NETSTACK_E_BASE + 63) | Maximum file size exceeded.|
| OH_HTTP_REMOTE_DISK_FULL = (OH_HTTP_NETSTACK_E_BASE + 70) | Remote disk fully occupied.|
| OH_HTTP_REMOTE_FILE_EXISTS = (OH_HTTP_NETSTACK_E_BASE + 73) | Remote file already exists.|
| OH_HTTP_SSL_CA_NOT_EXIST = (OH_HTTP_NETSTACK_E_BASE + 77) | SSL CA certificate inexistent or inaccessible.|
| OH_HTTP_REMOTE_FILE_NOT_FOUND = (OH_HTTP_NETSTACK_E_BASE + 78) | Remote file not found.|
| OH_HTTP_AUTHENTICATION_ERROR = (OH_HTTP_NETSTACK_E_BASE + 94) | Identity authentication error.|
| OH_HTTP_ACCESS_DOMAIN_NOT_ALLOWED = (OH_HTTP_NETSTACK_E_BASE + 998) | Access to the domain denied.|
| OH_HTTP_UNKNOWN_ERROR = (OH_HTTP_NETSTACK_E_BASE + 999) | Unknown error.|

### Http_ResponseCode

```
enum Http_ResponseCode
```

**Overview**

Enumerates the result codes of an HTTP response.

**Since**: 20

| Enum| Description|
| -- | -- |
| OH_HTTP_OK = 200 | Request succeeded.|
| OH_HTTP_CREATED = 201 | "Created." The request has been successfully sent and a new resource is created.|
| OH_HTTP_ACCEPTED = 202 | "Accepted." The request has been accepted for processing, but the processing has not been completed.|
| OH_HTTP_NOT_AUTHORITATIVE = 203 | "Non-Authoritative Information." The request was successfully processed, but the returned response body contains non-authoritative information.|
| OH_HTTP_NO_CONTENT = 204 | "No Content." The server has successfully fulfilled the request but there is no additional content to send in the response payload body.|
| OH_HTTP_RESET = 205 | "Reset Content." The server has successfully fulfilled the request and desires that the user agent reset the content.|
| OH_HTTP_PARTIAL = 206 | "Partial Content." The server has successfully fulfilled the partial GET request for a given resource.|
| OH_HTTP_MULT_CHOICE = 300 | "Multiple Choices." The requested resource corresponds to any one of a set of representations.|
| OH_HTTP_MOVED_PERM = 301 | "Moved Permanently." The requested resource has been assigned a new permanent URI and any future references to this resource will be redirected to this URI.|
| OH_HTTP_MOVED_TEMP = 302 | "Moved Temporarily." The requested resource is moved temporarily to a different URI.|
| OH_HTTP_SEE_OTHER = 303 | "See Other." The response to the request can be found under a different URI.|
| OH_HTTP_NOT_MODIFIED = 304 | "Not Modified." The client has performed a conditional GET request and access is allowed, but the content has not been modified.|
| OH_HTTP_USE_PROXY = 305 | "Use Proxy." The requested resource can only be accessed through the proxy.|
| OH_HTTP_BAD_REQUEST = 400 | "Bad Request." The request could not be understood by the server due to incorrect syntax.|
| OH_HTTP_UNAUTHORIZED = 401 | "Unauthorized." The request requires user authentication.|
| OH_HTTP_PAYMENT_REQUIRED = 402 | "Payment Required." This code is reserved for future use.|
| OH_HTTP_FORBIDDEN = 403 | "Forbidden." The server understands the request but refuses to process it.|
| OH_HTTP_NOT_FOUND = 404 | "Not Found." The server does not find anything matching the Request-URI.|
| OH_HTTP_BAD_METHOD = 405 | "Method Not Allowed." The method specified in the request is not allowed for the resource identified by the Request-URI.|
| OH_HTTP_NOT_ACCEPTABLE = 406 | "Not Acceptable." The server cannot fulfill the request according to the content characteristics of the request.|
| OH_HTTP_PROXY_AUTH = 407 | "Proxy Authentication Required." The request requires user authentication with the proxy.|
| OH_HTTP_CLIENT_TIMEOUT = 408 | "Request Timeout." The client fails to generate a request within the timeout period.|
| OH_HTTP_CONFLICT = 409 | "Conflict." The request cannot be fulfilled due to a conflict with the current state of the resource. Conflicts are most likely to occur in response to a PUT request.|
| OH_HTTP_GONE = 410 | "Gone." The requested resource has been deleted permanently and is no longer available.|
| OH_HTTP_LENGTH_REQUIRED = 411 | "Length Required." The server refuses to process the request without a defined Content-Length.|
| OH_HTTP_PRECON_FAILED = 412 | "Precondition Failed." The precondition in the request is incorrect.|
| OH_HTTP_ENTITY_TOO_LARGE = 413 | "Request Entity Too Large." The server refuses to process a request because the request entity is larger than the server is able to process.|
| OH_HTTP_REQ_TOO_LONG = 414 | "Request-URI Too Long." The Request-URI is too long for the server to process.|
| OH_HTTP_UNSUPPORTED_TYPE = 415 | "Unsupported Media Type." The server is unable to process the media format in the request.|
| OH_HTTP_RANGE_NOT_SATISFIABLE = 416 | "Range Not Satisfiable." The server cannot serve the requested ranges.|
| OH_HTTP_INTERNAL_ERROR = 500 | "Internal Server Error." The server encounters an unexpected error that prevents it from fulfilling the request.|
| OH_HTTP_NOT_IMPLEMENTED = 501 | "Not Implemented." The server does not support the function required to fulfill the request.|
| OH_HTTP_BAD_GATEWAY = 502 | "Bad Gateway." The server acting as a gateway or proxy receives an invalid response from the upstream server.|
| OH_HTTP_UNAVAILABLE = 503 | "Service Unavailable." The server is currently unable to process the request due to a temporary overload or system maintenance.|
| OH_HTTP_GATEWAY_TIMEOUT = 504 | "Gateway Timeout." The server acting as a gateway or proxy does not receive requests from the remote server within the timeout period.|
| OH_HTTP_VERSION = 505 | "HTTP Version Not Supported." The server does not support the HTTP protocol version used in the request. |

### Http_AddressFamilyType

```
enum Http_AddressFamilyType
```

**Overview**

Defines the IP address family of the target domain name.

**Since**: 20

| Enum| Description|
| -- | -- |
| HTTP_ADDRESS_FAMILY_DEFAULT = 0 | Default value. The system determines whether to use the IPv4 or IPv6 address of the target domain name.|
| HTTP_ADDRESS_FAMILY_ONLY_V4 = 1 | The system resolves only the IPv4 address of the target domain name and ignores the IPv6 address.|
| HTTP_ADDRESS_FAMILY_ONLY_V6 = 2 | The system resolves only the IPv6 address of the target domain name and ignores the IPv4 address.|

### Http_HttpProtocol

```
enum Http_HttpProtocol
```

**Overview**

Enumerates HTTP protocol versions.

**Since**: 20

| Enum| Description|
| -- | -- |
| OH_HTTP_NONE = 0 | Following cURL protocol version.|
| OH_HTTP1_1 | HTTP 1.1 version.|
| OH_HTTP2 | HTTP 2 version.|
| OH_HTTP3 | HTTP 3 version.|

### Http_CertType

```
enum Http_CertType
```

**Overview**

Enumerates certificate types.

**Since**: 20

| Enum| Description|
| -- | -- |
| OH_HTTP_PEM = 0 | PEM certificate.|
| OH_HTTP_DER = 1 | DER certificate.|
| OH_HTTP_P12 = 2 | P12 certificate.|

### Http_ProxyType

```
enum Http_ProxyType
```

**Overview**

Enumerates proxy types.

**Since**: 20

| Enum| Description|
| -- | -- |
| HTTP_PROXY_NOT_USE | No proxy.|
| HTTP_PROXY_SYSTEM | The system proxy is used.|
| HTTP_PROXY_CUSTOM | The custom proxy is used.|


## Function Description

### Http_ResponseCallback()

```
typedef void (*Http_ResponseCallback)(struct Http_Response *response, uint32_t errCode)
```

**Overview**

Callback invoked when an HTTP response is received.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [struct Http_Response](capi-netstack-http-response.md) *response | Pointer to the HTTP response. For details, see [Http_Response](capi-netstack-http-response.md).|
|  uint32_t errCode | Response code.|

### Http_OnDataReceiveCallback()

```
typedef void (*Http_OnDataReceiveCallback)(const char *data, size_t length)
```

**Overview**

Callback invoked when data is received.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *data | Response body.|
| size_t length | Length of the response body.|

### Http_OnProgressCallback()

```
typedef void (*Http_OnProgressCallback)(uint64_t totalSize, uint64_t transferredSize)
```

**Overview**

Callback invoked during request/response data transmission.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| uint64_t totalSize | Total data size.|
| uint64_t transferredSize | Size of transferred data.|

### Http_OnHeaderReceiveCallback()

```
typedef void (*Http_OnHeaderReceiveCallback)(Http_Headers *headers)
```

**Overview**

Callback invoked when an HTTP response header is received.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Http_Headers](capi-netstack-http-headers.md) *headers | Pointer to the received request header. For details, see [Http_Headers](capi-netstack-http-headers.md).|

### Http_OnVoidCallback()

```
typedef void (*Http_OnVoidCallback)(void)
```

**Overview**

Callback invoked when a DataEnd or Cancel event is received.

**Since**: 20
