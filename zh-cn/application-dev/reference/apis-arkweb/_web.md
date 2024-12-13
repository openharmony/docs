# Web


## 概述

为ArkWeb NDK接口发生异常提供错误码。

提供注入对象和执行JavaScript代码的API接口。

提供用于拦截ArkWeb请求的API。

为ArkWeb网络协议栈提供错误码。

提供ArkWeb在Native侧的能力，如网页刷新、执行JavaScript、注册回调等。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [arkweb_error_code.h](arkweb__error__code_8h.md) | 声明ArkWeb NDK接口异常错误码。  | 
| [arkweb_interface.h](arkweb__interface_8h.md) | 提供ArkWeb在Native侧获取API的接口，及基础Native API类型。  | 
| [arkweb_net_error_list.h](arkweb__net__error__list_8h.md) | 声明ArkWeb网络协议栈错误码。  | 
| [arkweb_scheme_handler.h](arkweb__scheme__handler_8h.md) | 声明用于拦截来自ArkWeb的请求的API。  | 
| [arkweb_type.h](arkweb__type_8h.md) | 提供ArkWeb在Native侧的公共类型定义。  | 
| [native_interface_arkweb.h](native__interface__arkweb_8h.md) | 声明API接口供开发者使用注入对象和执行JavaScript代码等功能。  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) | 定义基础Native API类型。  | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) | 定义JavaScript Bridge数据的基础结构。  | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptObject](_ark_web___java_script_object.md) | 注入的JavaScript结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyMethod](_ark_web___proxy_method.md) | 注入的Proxy方法通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyMethodWithResult](_ark_web___proxy_method_with_result.md) | 注入的Proxy方法通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyObject](_ark_web___proxy_object.md) | 注入的Proxy对象通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyObjectWithResult](_ark_web___proxy_object_with_result.md) | 注入的Proxy对象通用结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_ControllerAPI](_ark_web___controller_a_p_i.md) | Controller相关的Native API结构体。 在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。  | 
| struct&nbsp;&nbsp;[ArkWeb_ComponentAPI](_ark_web___component_a_p_i.md) | Component相关的Native API结构体。  | 
| struct&nbsp;&nbsp;[ArkWeb_WebMessagePortAPI](_ark_web___web_message_port_a_p_i.md) | Post Message相关的Native API结构体。 在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。  | 
| struct&nbsp;&nbsp;[ArkWeb_WebMessageAPI](_ark_web___web_message_a_p_i.md) | Post Message数据相关的Native API结构体。 在调用接口前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。  | 
| struct&nbsp;&nbsp;[ArkWeb_CookieManagerAPI](_ark_web___cookie_manager_a_p_i.md) | 定义了ArkWeb原生CookieManager接口。 在调用接口之前，建议使用ARKWEB_MEMBER_MISSING检查函数结构体是否有对应的函数指针，避免SDK与设备ROM不匹配导致崩溃。  | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptValueAPI](_ark_web___java_script_value_a_p_i.md) | 定义了ArkWeb原生JavaScriptValue接口。 在调用接口之前，建议使用ARKWEB_MEMBER_MISSING检查函数结构体是否有对应的函数指针，避免SDK与设备ROM不匹配导致崩溃。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [ARKWEB_MEMBER_EXISTS](#arkweb_member_exists)(s, f)&nbsp;&nbsp;&nbsp;&nbsp;((intptr_t) &amp; ((s)-&gt;f) - (intptr_t)(s) + sizeof((s)-&gt;f) &lt;= \*reinterpret_cast&lt;size_t\*&gt;(s)) | 检查结构体中是否存在该成员变量。  | 
| [ARKWEB_MEMBER_MISSING](#arkweb_member_missing)(s, f)&nbsp;&nbsp;&nbsp;(\![ARKWEB_MEMBER_EXISTS](#arkweb_member_exists)(s, f) \|\| !((s)-&gt;f)) | 当前结构体存在该成员变量则返回false，否则返回true。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [ArkWeb_ErrorCode](#arkweb_errorcode) [ArkWeb_ErrorCode](#arkweb_errorcode) | 定义ArkWeb NDK接口异常错误码。  | 
| typedef enum [ArkWeb_NetError](#arkweb_neterror) [ArkWeb_NetError](#arkweb_neterror) | 定义ArkWeb网络协议栈错误码。  | 
| typedef enum [ArkWeb_CustomSchemeOption](#arkweb_customschemeoption) [ArkWeb_CustomSchemeOption](#arkweb_customschemeoption) | custom scheme的配置信息。  | 
| typedef enum [ArkWeb_ResourceType](#arkweb_resourcetype) [ArkWeb_ResourceType](#arkweb_resourcetype) | 请求的资源类型。  | 
| typedef struct ArkWeb_SchemeHandler_ [ArkWeb_SchemeHandler](#arkweb_schemehandler) | 该类用于拦截指定scheme的请求。  | 
| typedef struct ArkWeb_ResourceHandler_ [ArkWeb_ResourceHandler](#arkweb_resourcehandler) | 用于被拦截的URL请求。  | 
| typedef struct ArkWeb_Response_ [ArkWeb_Response](#arkweb_response) | 为被拦截的请求构造一个ArkWeb_Response。  | 
| typedef struct ArkWeb_ResourceRequest_ [ArkWeb_ResourceRequest](#arkweb_resourcerequest) | 对应内核的一个请求，可以通过OH_ArkWeb_ResourceRequest获取请求的URL、method、post data以及其他信息。  | 
| typedef struct ArkWeb_RequestHeaderList_ [ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) | 请求头列表。  | 
| typedef struct ArkWeb_HttpBodyStream_ [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) | 请求的上传数据。  | 
| typedef void(\* [ArkWeb_OnRequestStart](#arkweb_onrequeststart)) (const [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler, bool \*intercept) | 请求开始的回调，这将在IO线程上被调用。  | 
| typedef void(\* [ArkWeb_OnRequestStop](#arkweb_onrequeststop)) (const [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | 请求完成时的回调函数。  | 
| typedef void(\* [ArkWeb_HttpBodyStreamReadCallback](#arkweb_httpbodystreamreadcallback)) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, uint8_t \*buffer, int bytesRead) | 当OH_ArkWebHttpBodyStream_Read读取操作完成时的回调函数。  | 
| typedef void(\* [ArkWeb_HttpBodyStreamInitCallback](#arkweb_httpbodystreaminitcallback)) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_NetError](#arkweb_neterror) result) | ArkWeb_HttpBodyStream初始化操作完成时回调函数。  | 
| typedef enum [ArkWeb_WebMessageType](#arkweb_webmessagetype) [ArkWeb_WebMessageType](#arkweb_webmessagetype) | Post Message数据类型。  | 
| typedef enum [ArkWeb_JavaScriptValueType](#arkweb_javascriptvaluetype) [ArkWeb_JavaScriptValueType](#arkweb_javascriptvaluetype) | JavaScript数据类型。  | 
| typedef struct ArkWeb_WebMessage \* [ArkWeb_WebMessagePtr](#arkweb_webmessageptr) | Post Message数据结构体指针。  | 
| typedef struct ArkWeb_JavaScriptValue \* [ArkWeb_JavaScriptValuePtr](#arkweb_javascriptvalueptr) | JavaScript数据结构体指针。  | 
| typedef void(\* [ArkWeb_OnJavaScriptCallback](#arkweb_onjavascriptcallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*data, void \*userData) | 注入的JavaScript执行完成的回调。  | 
| typedef void(\* [ArkWeb_OnJavaScriptProxyCallback](#arkweb_onjavascriptproxycallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*dataArray, size_t arraySize, void \*userData) | Proxy方法被执行的回调。  | 
| typedef [ArkWeb_JavaScriptValuePtr](#arkweb_javascriptvalueptr)(\* [ArkWeb_OnJavaScriptProxyCallbackWithResult](#arkweb_onjavascriptproxycallbackwithresult)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*dataArray, size_t arraySize, void \*userData) | Proxy方法被执行的回调。  | 
| typedef void(\* [ArkWeb_OnComponentCallback](#arkweb_oncomponentcallback)) (const char \*webTag, void \*userData) | 组件事件通知相关的通用回调。  | 
| typedef struct ArkWeb_WebMessagePort \* [ArkWeb_WebMessagePortPtr](#arkweb_webmessageportptr) | Post Message端口结构体指针。  | 
| typedef void(\* [ArkWeb_OnMessageEventHandler](#arkweb_onmessageeventhandler)) (const char \*webTag, const [ArkWeb_WebMessagePortPtr](#arkweb_webmessageportptr) port, const [ArkWeb_WebMessagePtr](#arkweb_webmessageptr) message, void \*userData) | 处理HTML发送过来的Post Message数据。  | 
| typedef void(\* [NativeArkWeb_OnJavaScriptCallback](#nativearkweb_onjavascriptcallback)) (const char \*) | 定义执行JavaScript代码后返回结果的回调函数的类型。  | 
| typedef char \*(\* [NativeArkWeb_OnJavaScriptProxyCallback](#nativearkweb_onjavascriptproxycallback)) (const char \*\*argv, int32_t argc) | 定义注入对象的回调函数的类型。  | 
| typedef void(\* [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback)) (const char \*) | 定义Web组件可用时的回调函数的类型。  | 
| typedef void(\* [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback)) (const char \*) | 定义Web组件销毁时的回调函数的类型。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkWeb_ErrorCode](#arkweb_errorcode) {<br/>ARKWEB_SUCCESS = 0, ARKWEB_INIT_ERROR = 17100001, ARKWEB_ERROR_UNKNOWN = 17100100, ARKWEB_INVALID_PARAM = 17100101,<br/>ARKWEB_SCHEME_REGISTER_FAILED = 17100102, ARKWEB_INVALID_URL = 17100103, ARKWEB_INVALID_COOKIE_VALUE = 17100104<br/>} | 定义ArkWeb NDK接口异常错误码。  | 
| [ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) {<br/>ARKWEB_NATIVE_COMPONENT, ARKWEB_NATIVE_CONTROLLER, ARKWEB_NATIVE_WEB_MESSAGE_PORT, ARKWEB_NATIVE_WEB_MESSAGE,<br/>ARKWEB_NATIVE_COOKIE_MANAGER, ARKWEB_NATIVE_JAVASCRIPT_VALUE<br/>} | 定义Native API的类型枚举。  | 
| [ArkWeb_NetError](#arkweb_neterror) {<br/>ARKWEB_NET_OK = 0, ARKWEB_ERR_IO_PENDING = -1, ARKWEB_ERR_FAILED = -2, ARKWEB_ERR_ABORTED = -3,<br/>ARKWEB_ERR_INVALID_ARGUMENT = -4, ARKWEB_ERR_INVALID_HANDLE = -5, ARKWEB_ERR_FILE_NOT_FOUND = -6, ARKWEB_ERR_TIMED_OUT = -7,<br/>ARKWEB_ERR_FILE_TOO_LARGE = -8, ARKWEB_ERR_UNEXPECTED = -9, ARKWEB_ERR_ACCESS_DENIED = -10, ARKWEB_ERR_NOT_IMPLEMENTED = -11,<br/>ARKWEB_ERR_INSUFFICIENT_RESOURCES = -12, ARKWEB_ERR_OUT_OF_MEMORY = -13, ARKWEB_ERR_UPLOAD_FILE_CHANGED = -14, ARKWEB_ERR_SOCKET_NOT_CONNECTED = -15,<br/>ARKWEB_ERR_FILE_EXISTS = -16, ARKWEB_ERR_FILE_PATH_TOO_LONG = -17, ARKWEB_ERR_FILE_NO_SPACE = -18, ARKWEB_ERR_FILE_VIRUS_INFECTED = -19,<br/>ARKWEB_ERR_BLOCKED_BY_CLIENT = -20, ARKWEB_ERR_NETWORK_CHANGED = -21, ARKWEB_ERR_BLOCKED_BY_ADMINISTRATOR = -22, ARKWEB_ERR_SOCKET_CONNECTED = -23,<br/>ARKWEB_ERR_UPLOAD_STREAM_REWIND_NOT_SUPPORTED = -25, ARKWEB_ERR_CONTEXT_SHUT_DOWN = -26, ARKWEB_ERR_BLOCKED_BY_RESPONSE = -27, ARKWEB_ERR_CLEARTEXT_NOT_PERMITTED = -29,<br/>ARKWEB_ERR_BLOCKED_BY_CSP = -30, ARKWEB_ERR_H2_OR_QUIC_REQUIRED = -31, ARKWEB_ERR_BLOCKED_BY_ORB = -32, ARKWEB_ERR_CONNECTION_CLOSED = -100,<br/>ARKWEB_ERR_CONNECTION_RESET = -101, ARKWEB_ERR_CONNECTION_REFUSED = -102, ARKWEB_ERR_CONNECTION_ABORTED = -103, ARKWEB_ERR_CONNECTION_FAILED = -104,<br/>ARKWEB_ERR_NAME_NOT_RESOLVED = -105, ARKWEB_ERR_INTERNET_DISCONNECTED = -106, ARKWEB_ERR_SSL_PROTOCOL_ERROR = -107, ARKWEB_ERR_ADDRESS_INVALID = -108,<br/>ARKWEB_ERR_ADDRESS_UNREACHABLE = -109, ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NEEDED = -110, ARKWEB_ERR_TUNNEL_CONNECTION_FAILED = -111, ARKWEB_ERR_NO_SSL_VERSIONS_ENABLED = -112,<br/>ARKWEB_ERR_SSL_VERSION_OR_CIPHER_MISMATCH = -113, ARKWEB_ERR_SSL_RENEGOTIATION_REQUESTED = -114, ARKWEB_ERR_PROXY_AUTH_UNSUPPORTED = -115, ARKWEB_ERR_BAD_SSL_CLIENT_AUTH_CERT = -117,<br/>ARKWEB_ERR_CONNECTION_TIMED_OUT = -118, ARKWEB_ERR_HOST_RESOLVER_QUEUE_TOO_LARGE = -119, ARKWEB_ERR_SOCKS_CONNECTION_FAILED = -120, ARKWEB_ERR_SOCKS_CONNECTION_HOST_UNREACHABLE = -121,<br/>ARKWEB_ERR_ALPN_NEGOTIATION_FAILED = -122, ARKWEB_ERR_SSL_NO_RENEGOTIATION = -123, ARKWEB_ERR_WINSOCK_UNEXPECTED_WRITTEN_BYTES = -124, ARKWEB_ERR_SSL_DECOMPRESSION_FAILURE_ALERT = -125,<br/>ARKWEB_ERR_SSL_BAD_RECORD_MAC_ALERT = -126, ARKWEB_ERR_PROXY_AUTH_REQUESTED = -127, ARKWEB_ERR_PROXY_CONNECTION_FAILED = -130, ARKWEB_ERR_MANDATORY_PROXY_CONFIGURATION_FAILED = -131,<br/>ARKWEB_ERR_PRECONNECT_MAX_SOCKET_LIMIT = -133, ARKWEB_ERR_SSL_CLIENT_AUTH_PRIVATE_KEY_ACCESS_DENIED = -134, ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NO_PRIVATE_KEY = -135, ARKWEB_ERR_PROXY_CERTIFICATE_INVALID = -136,<br/>ARKWEB_ERR_NAME_RESOLUTION_FAILED = -137, ARKWEB_ERR_NETWORK_ACCESS_DENIED = -138, ARKWEB_ERR_TEMPORARILY_THROTTLED = -139, ARKWEB_ERR_HTTPS_PROXY_TUNNEL_RESPONSE_REDIRECT = -140,<br/>ARKWEB_ERR_SSL_CLIENT_AUTH_SIGNATURE_FAILED = -141, ARKWEB_ERR_MSG_TOO_BIG = -142, ARKWEB_ERR_WS_PROTOCOL_ERROR = -145, ARKWEB_ERR_ADDRESS_IN_USE = -147,<br/>ARKWEB_ERR_SSL_HANDSHAKE_NOT_COMPLETED = -148, ARKWEB_ERR_SSL_BAD_PEER_PUBLIC_KEY = -149, ARKWEB_ERR_SSL_PINNED_KEY_NOT_IN_CERT_CHAIN = -150, ARKWEB_ERR_CLIENT_AUTH_CERT_TYPE_UNSUPPORTED = -151,<br/>ARKWEB_ERR_SSL_DECRYPT_ERROR_ALERT = -153, ARKWEB_ERR_WS_THROTTLE_QUEUE_TOO_LARGE = -154, ARKWEB_ERR_SSL_SERVER_CERT_CHANGED = -156, ARKWEB_ERR_SSL_UNRECOGNIZED_NAME_ALERT = -159,<br/>ARKWEB_ERR_SOCKET_SET_RECEIVE_BUFFER_SIZE_ERROR = -160, ARKWEB_ERR_SOCKET_SET_SEND_BUFFER_SIZE_ERROR = -161, ARKWEB_ERR_SOCKET_RECEIVE_BUFFER_SIZE_UNCHANGEABLE = -162, ARKWEB_ERR_SOCKET_SEND_BUFFER_SIZE_UNCHANGEABLE = -163,<br/>ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_BAD_FORMAT = -164, ARKWEB_ERR_ICANN_NAME_COLLISION = -166, ARKWEB_ERR_SSL_SERVER_CERT_BAD_FORMAT = -167, ARKWEB_ERR_CT_STH_PARSING_FAILED = -168,<br/>ARKWEB_ERR_CT_STH_INCOMPLETE = -169, ARKWEB_ERR_UNABLE_TO_REUSE_CONNECTION_FOR_PROXY_AUTH = -170, ARKWEB_ERR_CT_CONSISTENCY_PROOF_PARSING_FAILED = -171, ARKWEB_ERR_SSL_OBSOLETE_CIPHER = -172,<br/>ARKWEB_ERR_WS_UPGRADE = -173, ARKWEB_ERR_READ_IF_READY_NOT_IMPLEMENTED = -174, ARKWEB_ERR_NO_BUFFER_SPACE = -176, ARKWEB_ERR_SSL_CLIENT_AUTH_NO_COMMON_ALGORITHMS = -177,<br/>ARKWEB_ERR_EARLY_DATA_REJECTED = -178, ARKWEB_ERR_WRONG_VERSION_ON_EARLY_DATA = -179, ARKWEB_ERR_TLS13_DOWNGRADE_DETECTED = -180, ARKWEB_ERR_SSL_KEY_USAGE_INCOMPATIBLE = -181,<br/>ARKWEB_ERR_INVALID_ECH_CONFIG_LIST = -182, ARKWEB_ERR_ECH_NOT_NEGOTIATED = -183, ARKWEB_ERR_ECH_FALLBACK_CERTIFICATE_INVALID = -184, ARKWEB_ERR_CERT_COMMON_NAME_INVALID = -200,<br/>ARKWEB_ERR_CERT_DATE_INVALID = -201, ARKWEB_ERR_CERT_AUTHORITY_INVALID = -202, ARKWEB_ERR_CERT_CONTAINS_ERRORS = -203, ARKWEB_ERR_CERT_NO_REVOCATION_MECHANISM = -204,<br/>ARKWEB_ERR_CERT_UNABLE_TO_CHECK_REVOCATION = -205, ARKWEB_ERR_CERT_REVOKED = -206, ARKWEB_ERR_CERT_INVALID = -207, ARKWEB_ERR_CERT_WEAK_SIGNATURE_ALGORITHM = -208,<br/>ARKWEB_ERR_CERT_NON_UNIQUE_NAME = -210, ARKWEB_ERR_CERT_WEAK_KEY = -211, ARKWEB_ERR_CERT_NAME_CONSTRAINT_VIOLATION = -212, ARKWEB_ERR_CERT_VALIDITY_TOO_LONG = -213,<br/>ARKWEB_ERR_CERTIFICATE_TRANSPARENCY_REQUIRED = -214, ARKWEB_ERR_CERT_SYMANTEC_LEGACY = -215, ARKWEB_ERR_CERT_KNOWN_INTERCEPTION_BLOCKED = -217, ARKWEB_ERR_SSL_OBSOLETE_VERSION_OR_CIPHER = -218,<br/>ARKWEB_ERR_CERT_END = -219, ARKWEB_ERR_INVALID_URL = -300, ARKWEB_ERR_DISALLOWED_URL_SCHEME = -301, ARKWEB_ERR_UNKNOWN_URL_SCHEME = -302,<br/>ARKWEB_ERR_INVALID_REDIRECT = -303, ARKWEB_ERR_TOO_MANY_REDIRECTS = -310, ARKWEB_ERR_UNSAFE_REDIRECT = -311, ARKWEB_ERR_UNSAFE_PORT = -312,<br/>ARKWEB_ERR_INVALID_RESPONSE = -320, ARKWEB_ERR_INVALID_CHUNKED_ENCODING = -321, ARKWEB_ERR_METHOD_UNSUPPORTED = -322, ARKWEB_ERR_UNEXPECTED_PROXY_AUTH = -323,<br/>ARKWEB_ERR_EMPTY_RESPONSE = -324, ARKWEB_ERR_RESPONSE_HEADERS_TOO_BIG = -325, ARKWEB_ERR_PAC_SCRIPT_FAILED = -327, ARKWEB_ERR_REQUEST_RANGE_NOT_SATISFIABLE = -328,<br/>ARKWEB_ERR_MALFORMED_IDENTITY = -329, ARKWEB_ERR_CONTENT_DECODING_FAILED = -330, ARKWEB_ERR_NETWORK_IO_SUSPENDED = -331, ARKWEB_ERR_SYN_REPLY_NOT_RECEIVED = -332,<br/>ARKWEB_ERR_ENCODING_CONVERSION_FAILED = -333, ARKWEB_ERR_UNRECOGNIZED_FTP_DIRECTORY_LISTING_FORMAT = -334, ARKWEB_ERR_NO_SUPPORTED_PROXIES = -336, ARKWEB_ERR_HTTP2_PROTOCOL_ERROR = -337,<br/>ARKWEB_ERR_INVALID_AUTH_CREDENTIALS = -338, ARKWEB_ERR_UNSUPPORTED_AUTH_SCHEME = -339, ARKWEB_ERR_ENCODING_DETECTION_FAILED = -340, ARKWEB_ERR_MISSING_AUTH_CREDENTIALS = -341,<br/>ARKWEB_ERR_UNEXPECTED_SECURITY_LIBRARY_STATUS = -342, ARKWEB_ERR_MISCONFIGURED_AUTH_ENVIRONMENT = -343, ARKWEB_ERR_UNDOCUMENTED_SECURITY_LIBRARY_STATUS = -344, ARKWEB_ERR_RESPONSE_BODY_TOO_BIG_TO_DRAIN = -345,<br/>ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_LENGTH = -346, ARKWEB_ERR_INCOMPLETE_HTTP2_HEADERS = -347, ARKWEB_ERR_PAC_NOT_IN_DHCP = -348, ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_DISPOSITION = -349,<br/>ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_LOCATION = -350, ARKWEB_ERR_HTTP2_SERVER_REFUSED_STREAM = -351, ARKWEB_ERR_HTTP2_PING_FAILED = -352, ARKWEB_ERR_CONTENT_LENGTH_MISMATCH = -354,<br/>ARKWEB_ERR_INCOMPLETE_CHUNKED_ENCODING = -355, ARKWEB_ERR_QUIC_PROTOCOL_ERROR = -356, ARKWEB_ERR_RESPONSE_HEADERS_TRUNCATED = -357, ARKWEB_ERR_QUIC_HANDSHAKE_FAILED = -358,<br/>ARKWEB_ERR_HTTP2_INADEQUATE_TRANSPORT_SECURITY = -360, ARKWEB_ERR_HTTP2_FLOW_CONTROL_ERROR = -361, ARKWEB_ERR_HTTP2_FRAME_SIZE_ERROR = -362, ARKWEB_ERR_HTTP2_COMPRESSION_ERROR = -363,<br/>ARKWEB_ERR_PROXY_AUTH_REQUESTED_WITH_NO_CONNECTION = -364, ARKWEB_ERR_HTTP_1_1_REQUIRED = -365, ARKWEB_ERR_PROXY_HTTP_1_1_REQUIRED = -366, ARKWEB_ERR_PAC_SCRIPT_TERMINATED = -367,<br/>ARKWEB_ERR_INVALID_HTTP_RESPONSE = -370, ARKWEB_ERR_CONTENT_DECODING_INIT_FAILED = -371, ARKWEB_ERR_HTTP2_RST_STREAM_NO_ERROR_RECEIVED = -372, ARKWEB_ERR_HTTP2_PUSHED_STREAM_NOT_AVAILABLE = -373,<br/>ARKWEB_ERR_HTTP2_CLAIMED_PUSHED_STREAM_RESET_BY_SERVER = -374, ARKWEB_ERR_TOO_MANY_RETRIES = -375, ARKWEB_ERR_HTTP2_STREAM_CLOSED = -376, ARKWEB_ERR_HTTP2_CLIENT_REFUSED_STREAM = -377,<br/>ARKWEB_ERR_HTTP2_PUSHED_RESPONSE_DOES_NOT_MATCH = -378, ARKWEB_ERR_HTTP_RESPONSE_CODE_FAILURE = -379, ARKWEB_ERR_QUIC_UNKNOWN_CERT_ROOT = -380, ARKWEB_ERR_QUIC_GOAWAY_REQUEST_CAN_BE_RETRIED = -381,<br/>ARKWEB_ERR_TOO_MANY_ACCEPT_CH_RESTARTS = -382, ARKWEB_ERR_INCONSISTENT_IP_ADDRESS_SPACE = -383, ARKWEB_ERR_CACHED_IP_ADDRESS_SPACE_BLOCKED_BY_LOCAL_NETWORK_ACCESS_POLICY = -384, ARKWEB_ERR_CACHE_MISS = -400,<br/>ARKWEB_ERR_CACHE_READ_FAILURE = -401, ARKWEB_ERR_CACHE_WRITE_FAILURE = -402, ARKWEB_ERR_CACHE_OPERATION_UNSUPPORTED = -403, ARKWEB_ERR_CACHE_OPEN_FAILURE = -404,<br/>ARKWEB_ERR_CACHE_CREATE_FAILURE = -405, ARKWEB_ERR_CACHE_RACE = -406, ARKWEB_ERR_CACHE_CHECKSUM_READ_FAILURE = -407, ARKWEB_ERR_CACHE_CHECKSUM_MISMATCH = -408,<br/>ARKWEB_ERR_CACHE_LOCK_TIMEOUT = -409, ARKWEB_ERR_CACHE_AUTH_FAILURE_AFTER_READ = -410, ARKWEB_ERR_CACHE_ENTRY_NOT_SUITABLE = -411, ARKWEB_ERR_CACHE_DOOM_FAILURE = -412,<br/>ARKWEB_ERR_CACHE_OPEN_OR_CREATE_FAILURE = -413, ARKWEB_ERR_INSECURE_RESPONSE = -501, ARKWEB_ERR_NO_PRIVATE_KEY_FOR_CERT = -502, ARKWEB_ERR_ADD_USER_CERT_FAILED = -503,<br/>ARKWEB_ERR_INVALID_SIGNED_EXCHANGE = -504, ARKWEB_ERR_INVALID_WEB_BUNDLE = -505, ARKWEB_ERR_TRUST_TOKEN_OPERATION_FAILED = -506, ARKWEB_ERR_TRUST_TOKEN_OPERATION_SUCCESS_WITHOUT_SENDING_REQUEST = -507,<br/>ARKWEB_ERR_FTP_FAILED = -601, ARKWEB_ERR_FTP_SERVICE_UNAVAILABLE = -602, ARKWEB_ERR_FTP_TRANSFER_ABORTED = -603, ARKWEB_ERR_FTP_FILE_BUSY = -604,<br/>ARKWEB_ERR_FTP_SYNTAX_ERROR = -605, ARKWEB_ERR_FTP_COMMAND_UNSUPPORTED = -606, ARKWEB_ERR_FTP_BAD_COMMAND_SEQUENCE = -607, ARKWEB_ERR_PKCS12_IMPORT_BAD_PASSWORD = -701,<br/>ARKWEB_ERR_PKCS12_IMPORT_FAILED = -702, ARKWEB_ERR_IMPORT_CA_CERT_NOT_CA = -703, ARKWEB_ERR_IMPORT_CERT_ALREADY_EXISTS = -704, ARKWEB_ERR_IMPORT_CA_CERT_FAILED = -705,<br/>ARKWEB_ERR_IMPORT_SERVER_CERT_FAILED = -706, ARKWEB_ERR_PKCS12_IMPORT_INVALID_MAC = -707, ARKWEB_ERR_PKCS12_IMPORT_INVALID_FILE = -708, ARKWEB_ERR_PKCS12_IMPORT_UNSUPPORTED = -709,<br/>ARKWEB_ERR_KEY_GENERATION_FAILED = -710, ARKWEB_ERR_PRIVATE_KEY_EXPORT_FAILED = -712, ARKWEB_ERR_SELF_SIGNED_CERT_GENERATION_FAILED = -713, ARKWEB_ERR_CERT_DATABASE_CHANGED = -714,<br/>ARKWEB_ERR_CERT_VERIFIER_CHANGED = -716, ARKWEB_ERR_DNS_MALFORMED_RESPONSE = -800, ARKWEB_ERR_DNS_SERVER_REQUIRES_TCP = -801, ARKWEB_ERR_DNS_SERVER_FAILED = -802,<br/>ARKWEB_ERR_DNS_TIMED_OUT = -803, ARKWEB_ERR_DNS_CACHE_MISS = -804, ARKWEB_ERR_DNS_SEARCH_EMPTY = -805, ARKWEB_ERR_DNS_SORT_ERROR = -806,<br/>ARKWEB_ERR_DNS_SECURE_RESOLVER_HOSTNAME_RESOLUTION_FAILED = -808, ARKWEB_ERR_DNS_NAME_HTTPS_ONLY = -809, ARKWEB_ERR_DNS_REQUEST_CANCELED = -810, ARKWEB_ERR_DNS_NO_MATCHING_SUPPORTED_ALPN = -811<br/>} | 定义ArkWeb网络协议栈错误码。  | 
| [ArkWeb_CustomSchemeOption](#arkweb_customschemeoption) {<br/>**OH_ARKWEB_SCHEME_OPTION_NONE** = 0, ARKWEB_SCHEME_OPTION_STANDARD = 1 &lt;&lt; 0, ARKWEB_SCHEME_OPTION_LOCAL = 1 &lt;&lt; 1, ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED = 1 &lt;&lt; 2,<br/>ARKWEB_SCHEME_OPTION_SECURE = 1 &lt;&lt; 3, ARKWEB_SCHEME_OPTION_CORS_ENABLED = 1 &lt;&lt; 4, ARKWEB_SCHEME_OPTION_CSP_BYPASSING = 1 &lt;&lt; 5, ARKWEB_SCHEME_OPTION_FETCH_ENABLED = 1 &lt;&lt; 6,<br/>ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED = 1 &lt;&lt; 7<br/>} | custom scheme的配置信息。  | 
| [ArkWeb_ResourceType](#arkweb_resourcetype) {<br/>MAIN_FRAME = 0, SUB_FRAME = 1, STYLE_SHEET = 2, SCRIPT = 3,<br/>IMAGE = 4, FONT_RESOURCE = 5, SUB_RESOURCE = 6, OBJECT = 7,<br/>MEDIA = 8, WORKER = 9, SHARED_WORKER = 10, PREFETCH = 11,<br/>FAVICON = 12, XHR = 13, PING = 14, SERVICE_WORKER = 15,<br/>CSP_REPORT = 16, PLUGIN_RESOURCE = 17, NAVIGATION_PRELOAD_MAIN_FRAME = 19, NAVIGATION_PRELOAD_SUB_FRAME = 20<br/>} | 请求的资源类型。  | 
| [ArkWeb_WebMessageType](#arkweb_webmessagetype) { ARKWEB_NONE = 0, ARKWEB_STRING, ARKWEB_BUFFER } | Post Message数据类型。  | 
| [ArkWeb_JavaScriptValueType](#arkweb_javascriptvaluetype) { ARKWEB_JAVASCRIPT_NONE = 0, ARKWEB_JAVASCRIPT_STRING, ARKWEB_JAVASCRIPT_BOOL } | JavaScript数据类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) \* [OH_ArkWeb_GetNativeAPI](#oh_arkweb_getnativeapi) ([ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) type) | 根据传入的API类型，获取对应的Native API结构体。  | 
| void [OH_ArkWebRequestHeaderList_Destroy](#oh_arkwebrequestheaderlist_destroy) ([ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) \*requestHeaderList) | 销毁ArkWeb_RequestHeaderList对象。  | 
| int32_t [OH_ArkWebRequestHeaderList_GetSize](#oh_arkwebrequestheaderlist_getsize) (const [ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) \*requestHeaderList) | 获取请求头列表的大小。  | 
| void [OH_ArkWebRequestHeaderList_GetHeader](#oh_arkwebrequestheaderlist_getheader) (const [ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) \*requestHeaderList, int32_t index, char \*\*key, char \*\*value) | 获取指定的请求头。  | 
| int32_t [OH_ArkWebResourceRequest_SetUserData](#oh_arkwebresourcerequest_setuserdata) ([ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, void \*userData) | 将一个用户数据设置到ArkWeb_ResourceRequest对象中。  | 
| void \* [OH_ArkWebResourceRequest_GetUserData](#oh_arkwebresourcerequest_getuserdata) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | 从ArkWeb_ResourceRequest获取用户数据。  | 
| void [OH_ArkWebResourceRequest_GetMethod](#oh_arkwebresourcerequest_getmethod) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, char \*\*method) | 获取请求的method。  | 
| void [OH_ArkWebResourceRequest_GetUrl](#oh_arkwebresourcerequest_geturl) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, char \*\*url) | 获取请求的url。  | 
| void [OH_ArkWebResourceRequest_GetHttpBodyStream](#oh_arkwebresourcerequest_gethttpbodystream) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*\*httpBodyStream) | 创建一个ArkWeb_HttpBodyStream，用于读取请求的上传数据。  | 
| void [OH_ArkWebResourceRequest_DestroyHttpBodyStream](#oh_arkwebresourcerequest_destroyhttpbodystream) ([ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | 销毁ArkWeb_HttpBodyStream对象。  | 
| int32_t [OH_ArkWebResourceRequest_GetResourceType](#oh_arkwebresourcerequest_getresourcetype) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | 获取请求的资源类型。  | 
| void [OH_ArkWebResourceRequest_GetFrameUrl](#oh_arkwebresourcerequest_getframeurl) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, char \*\*frameUrl) | 获取触发此请求的Frame的URL。  | 
| int32_t [OH_ArkWebHttpBodyStream_SetUserData](#oh_arkwebhttpbodystream_setuserdata) ([ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, void \*userData) | 将一个用户数据设置到ArkWeb_HttpBodyStream对象中。  | 
| void \* [OH_ArkWebHttpBodyStream_GetUserData](#oh_arkwebhttpbodystream_getuserdata) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | 从ArkWeb_HttpBodyStream获取用户数据。  | 
| int32_t [OH_ArkWebHttpBodyStream_SetReadCallback](#oh_arkwebhttpbodystream_setreadcallback) ([ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_HttpBodyStreamReadCallback](#arkweb_httpbodystreamreadcallback) readCallback) | 为OH_ArkWebHttpBodyStream_Read设置回调函数。  | 
| int32_t [OH_ArkWebHttpBodyStream_Init](#oh_arkwebhttpbodystream_init) ([ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_HttpBodyStreamInitCallback](#arkweb_httpbodystreaminitcallback) initCallback) | 初始化ArkWeb_HttpBodyStream。  | 
| void [OH_ArkWebHttpBodyStream_Read](#oh_arkwebhttpbodystream_read) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, uint8_t \*buffer, int bufLen) | 将请求的上传数据读取到buffer。  | 
| uint64_t [OH_ArkWebHttpBodyStream_GetSize](#oh_arkwebhttpbodystream_getsize) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | 获取httpBodyStream的大小。  | 
| uint64_t [OH_ArkWebHttpBodyStream_GetPosition](#oh_arkwebhttpbodystream_getposition) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | 获取httpBodyStream当前的读取位置。  | 
| bool [OH_ArkWebHttpBodyStream_IsChunked](#oh_arkwebhttpbodystream_ischunked) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | 获取httpBodyStream是否采用分块传输。  | 
| bool [OH_ArkWebHttpBodyStream_IsEof](#oh_arkwebhttpbodystream_iseof) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | 如果httpBodyStream中的所有数据都已被读取，则返回true。  | 
| bool [OH_ArkWebHttpBodyStream_IsInMemory](#oh_arkwebhttpbodystream_isinmemory) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | 如果httpBodyStream中的上传数据完全在内存中，并且所有读取请求都将同步成功，则返回true。  | 
| int32_t [OH_ArkWebResourceRequest_Destroy](#oh_arkwebresourcerequest_destroy) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | 销毁ArkWeb_ResourceRequest对象。  | 
| void [OH_ArkWebResourceRequest_GetReferrer](#oh_arkwebresourcerequest_getreferrer) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, char \*\*referrer) | 获取请求的Referrer。  | 
| void [OH_ArkWebResourceRequest_GetRequestHeaders](#oh_arkwebresourcerequest_getrequestheaders) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, [ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) \*\*requestHeaderList) | 获取请求的请求头列表OH_ArkWeb_RequestHeaderList。  | 
| bool [OH_ArkWebResourceRequest_IsRedirect](#oh_arkwebresourcerequest_isredirect) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | 判断这是否是一个重定向请求。  | 
| bool [OH_ArkWebResourceRequest_IsMainFrame](#oh_arkwebresourcerequest_ismainframe) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | 判断这是否是主框架文档资源的请求。  | 
| bool [OH_ArkWebResourceRequest_HasGesture](#oh_arkwebresourcerequest_hasgesture) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | 判断这是否是一个由用户手势触发的请求。  | 
| int32_t [OH_ArkWeb_RegisterCustomSchemes](#oh_arkweb_registercustomschemes) (const char \*scheme, int32_t option) | 将custom scheme注册到ArkWeb。  | 
| bool [OH_ArkWebServiceWorker_SetSchemeHandler](#oh_arkwebserviceworker_setschemehandler) (const char \*scheme, [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler) | 为指定scheme设置一个ArkWeb_SchemeHandler以拦截ServiceWorker触发的该scheme类型的请求。  | 
| bool [OH_ArkWeb_SetSchemeHandler](#oh_arkweb_setschemehandler) (const char \*scheme, const char \*webTag, [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler) | 为指定scheme设置一个ArkWeb_SchemeHandler以拦截该scheme类型的请求。  | 
| int32_t [OH_ArkWebServiceWorker_ClearSchemeHandlers](#oh_arkwebserviceworker_clearschemehandlers) () | 清除为ServiceWorker注册的SchemeHandler。  | 
| int32_t [OH_ArkWeb_ClearSchemeHandlers](#oh_arkweb_clearschemehandlers) (const char \*webTag) | 清除为指定web注册的SchemeHandler。  | 
| void [OH_ArkWeb_CreateSchemeHandler](#oh_arkweb_createschemehandler) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*\*schemeHandler) | 创建一个ArkWeb_SchemeHandler对象。  | 
| void [OH_ArkWeb_DestroySchemeHandler](#oh_arkweb_destroyschemehandler) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler) | 销毁一个ArkWeb_SchemeHandler对象。  | 
| int32_t [OH_ArkWebSchemeHandler_SetUserData](#oh_arkwebschemehandler_setuserdata) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, void \*userData) | 将一个用户数据设置到ArkWeb_SchemeHandler对象中。  | 
| void \* [OH_ArkWebSchemeHandler_GetUserData](#oh_arkwebschemehandler_getuserdata) (const [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler) | 从ArkWeb_SchemeHandler获取用户数据。  | 
| int32_t [OH_ArkWebSchemeHandler_SetOnRequestStart](#oh_arkwebschemehandler_setonrequeststart) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, [ArkWeb_OnRequestStart](#arkweb_onrequeststart) onRequestStart) | 为SchemeHandler设置OnRequestStart回调。  | 
| int32_t [OH_ArkWebSchemeHandler_SetOnRequestStop](#oh_arkwebschemehandler_setonrequeststop) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, [ArkWeb_OnRequestStop](#arkweb_onrequeststop) onRequestStop) | 为SchemeHandler设置OnRequestStop回调。  | 
| void [OH_ArkWeb_CreateResponse](#oh_arkweb_createresponse) ([ArkWeb_Response](#arkweb_response) \*\*response) | 为被拦截的请求创建一个ArkWeb_Response对象。  | 
| void [OH_ArkWeb_DestroyResponse](#oh_arkweb_destroyresponse) ([ArkWeb_Response](#arkweb_response) \*response) | 销毁一个ArkWeb_Response对象。  | 
| int32_t [OH_ArkWebResponse_SetUrl](#oh_arkwebresponse_seturl) ([ArkWeb_Response](#arkweb_response) \*response, const char \*url) | 设置经过重定向或由于HSTS而改变后的解析URL，设置后会触发跳转。  | 
| void [OH_ArkWebResponse_GetUrl](#oh_arkwebresponse_geturl) (const [ArkWeb_Response](#arkweb_response) \*response, char \*\*url) | 获取经过重定向或由于HSTS而更改后的解析URL。  | 
| int32_t [OH_ArkWebResponse_SetError](#oh_arkwebresponse_seterror) ([ArkWeb_Response](#arkweb_response) \*response, [ArkWeb_NetError](#arkweb_neterror) errorCode) | 给ArkWeb_Response对象设置一个错误码。  | 
| [ArkWeb_NetError](#arkweb_neterror) [OH_ArkWebResponse_GetError](#oh_arkwebresponse_geterror) (const [ArkWeb_Response](#arkweb_response) \*response) | 获取ArkWeb_Response的错误码。  | 
| int32_t [OH_ArkWebResponse_SetStatus](#oh_arkwebresponse_setstatus) ([ArkWeb_Response](#arkweb_response) \*response, int status) | 为ArkWeb_Response对象设置一个HTTP状态码。  | 
| int [OH_ArkWebResponse_GetStatus](#oh_arkwebresponse_getstatus) (const [ArkWeb_Response](#arkweb_response) \*response) | 获取ArkWeb_Response的HTTP状态码。  | 
| int32_t [OH_ArkWebResponse_SetStatusText](#oh_arkwebresponse_setstatustext) ([ArkWeb_Response](#arkweb_response) \*response, const char \*statusText) | 为ArkWeb_Response设置状态文本。  | 
| void [OH_ArkWebResponse_GetStatusText](#oh_arkwebresponse_getstatustext) (const [ArkWeb_Response](#arkweb_response) \*response, char \*\*statusText) | 获取ArkWeb_Response的状态文本。  | 
| int32_t [OH_ArkWebResponse_SetMimeType](#oh_arkwebresponse_setmimetype) ([ArkWeb_Response](#arkweb_response) \*response, const char \*mimeType) | 为ArkWeb_Response设置媒体类型。  | 
| void [OH_ArkWebResponse_GetMimeType](#oh_arkwebresponse_getmimetype) (const [ArkWeb_Response](#arkweb_response) \*response, char \*\*mimeType) | 获取ArkWeb_Response的媒体类型。  | 
| int32_t [OH_ArkWebResponse_SetCharset](#oh_arkwebresponse_setcharset) ([ArkWeb_Response](#arkweb_response) \*response, const char \*charset) | 为ArkWeb_Response设置字符集。  | 
| void [OH_ArkWebResponse_GetCharset](#oh_arkwebresponse_getcharset) (const [ArkWeb_Response](#arkweb_response) \*response, char \*\*charset) | 获取ArkWeb_Response的字符集。  | 
| int32_t [OH_ArkWebResponse_SetHeaderByName](#oh_arkwebresponse_setheaderbyname) ([ArkWeb_Response](#arkweb_response) \*response, const char \*name, const char \*value, bool overwrite) | 为ArkWeb_Response设置一个header。  | 
| void [OH_ArkWebResponse_GetHeaderByName](#oh_arkwebresponse_getheaderbyname) (const [ArkWeb_Response](#arkweb_response) \*response, const char \*name, char \*\*value) | 从ArkWeb_Response中获取header。  | 
| int32_t [OH_ArkWebResourceHandler_Destroy](#oh_arkwebresourcehandler_destroy) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler) | 销毁一个ArkWeb_ResourceHandler对象。  | 
| int32_t [OH_ArkWebResourceHandler_DidReceiveResponse](#oh_arkwebresourcehandler_didreceiveresponse) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler, const [ArkWeb_Response](#arkweb_response) \*response) | 将构造的响应头传递给被拦截的请求。  | 
| int32_t [OH_ArkWebResourceHandler_DidReceiveData](#oh_arkwebresourcehandler_didreceivedata) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler, const uint8_t \*buffer, int64_t bufLen) | 将构造的响应体传递给被拦截的请求。  | 
| int32_t [OH_ArkWebResourceHandler_DidFinish](#oh_arkwebresourcehandler_didfinish) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler) | 通知ArkWeb内核被拦截的请求已经完成，并且没有更多的数据可用。  | 
| int32_t [OH_ArkWebResourceHandler_DidFailWithError](#oh_arkwebresourcehandler_didfailwitherror) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler, [ArkWeb_NetError](#arkweb_neterror) errorCode) | 通知ArkWeb内核被拦截请求应该失败。  | 
| void [OH_ArkWeb_ReleaseString](#oh_arkweb_releasestring) (char \*string) | 释放由NDK接口创建的字符串  | 
| void [OH_ArkWeb_ReleaseByteArray](#oh_arkweb_releasebytearray) (uint8_t \*byteArray) | 释放由NDK接口创建的字节数组。  | 
| void [OH_NativeArkWeb_RunJavaScript](#oh_nativearkweb_runjavascript) (const char \*webTag, const char \*jsCode, [NativeArkWeb_OnJavaScriptCallback](#nativearkweb_onjavascriptcallback) callback) | 在当前显示页面的环境下，加载并执行一段JavaScript代码。  | 
| void [OH_NativeArkWeb_RegisterJavaScriptProxy](#oh_nativearkweb_registerjavascriptproxy) (const char \*webTag, const char \*objName, const char \*\*methodList, [NativeArkWeb_OnJavaScriptProxyCallback](#nativearkweb_onjavascriptproxycallback) \*callback, int32_t size, bool needRefresh) | 注册对象及函数名称列表。  | 
| void [OH_NativeArkWeb_UnregisterJavaScriptProxy](#oh_nativearkweb_unregisterjavascriptproxy) (const char \*webTag, const char \*objName) | 删除已注册的对象及其下的回调函数。  | 
| void [OH_NativeArkWeb_SetJavaScriptProxyValidCallback](#oh_nativearkweb_setjavascriptproxyvalidcallback) (const char \*webTag, [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback) callback) | 设置对象可注册时的回调函数。  | 
| [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback) [OH_NativeArkWeb_GetJavaScriptProxyValidCallback](#oh_nativearkweb_getjavascriptproxyvalidcallback) (const char \*webTag) | 获取已注册的对象可注册时的回调函数。  | 
| void [OH_NativeArkWeb_SetDestroyCallback](#oh_nativearkweb_setdestroycallback) (const char \*webTag, [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback) callback) | 设置组件销毁时的回调函数。  | 
| [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback) [OH_NativeArkWeb_GetDestroyCallback](#oh_nativearkweb_getdestroycallback) (const char \*webTag) | 获取已注册的组件销毁时的回调函数。  | 


## 宏定义说明


### ARKWEB_MEMBER_EXISTS

```
#define ARKWEB_MEMBER_EXISTS( s,  f )    ((intptr_t) & ((s)->f) - (intptr_t)(s) + sizeof((s)->f) <= *reinterpret_cast<size_t*>(s))
```
**描述：**

检查结构体中是否存在该成员变量。

**起始版本：** 12


### ARKWEB_MEMBER_MISSING

```
#define ARKWEB_MEMBER_MISSING( s,  f )   (!ARKWEB_MEMBER_EXISTS(s, f) || !((s)->f))
```
**描述：**

当前结构体存在该成员变量则返回false，否则返回true。

**起始版本：** 12


## 类型定义说明


### ArkWeb_CustomSchemeOption

```
typedef enum ArkWeb_CustomSchemeOption ArkWeb_CustomSchemeOption
```
**描述：**

custom scheme的配置信息。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_ErrorCode

```
typedef enum ArkWeb_ErrorCode ArkWeb_ErrorCode
```
**描述：**

定义ArkWeb NDK接口异常错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_HttpBodyStream

```
typedef struct ArkWeb_HttpBodyStream_ ArkWeb_HttpBodyStream
```
**描述：**

请求的上传数据。

使用OH_ArkWebHttpBodyStream_\*接口来读取上传的数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_HttpBodyStreamInitCallback

```
typedef void(* ArkWeb_HttpBodyStreamInitCallback) (const ArkWeb_HttpBodyStream *httpBodyStream, ArkWeb_NetError result)
```
**描述：**

ArkWeb_HttpBodyStream初始化操作完成时回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 
| result | 成功时返回ARKWEB_NET_OK，否则请参考[arkweb_net_error_list.h](arkweb__net__error__list_8h.md)。 | 

### ArkWeb_HttpBodyStreamReadCallback

```
typedef void(* ArkWeb_HttpBodyStreamReadCallback) (const ArkWeb_HttpBodyStream *httpBodyStream, uint8_t *buffer, int bytesRead)
```
**描述：**

当OH_ArkWebHttpBodyStream_Read读取操作完成时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 
| buffer | 接收数据的buffer。  | 
| bytesRead | OH_ArkWebHttpBodyStream_Read后的回调函数。如果bytesRead大于0，则表示buffer已填充了bytesRead大小的数据。 调用者可以从buffer中读取数据，如果OH_ArkWebHttpBodyStream_IsEOF为false，则调用者可以继续读取剩余的数据。 | 


### ArkWeb_JavaScriptValuePtr

```
typedef struct ArkWeb_JavaScriptValue* ArkWeb_JavaScriptValuePtr
```
**描述：**

JavaScript数据结构体指针。

**起始版本：** 14


### ArkWeb_JavaScriptValueType

```
typedef enum ArkWeb_JavaScriptValueType ArkWeb_JavaScriptValueType
```
**描述：**

JavaScript数据类型。

**起始版本：** 14


### ArkWeb_NetError

```
typedef enum ArkWeb_NetError ArkWeb_NetError
```
**描述：**

定义ArkWeb网络协议栈错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_OnComponentCallback

```
typedef void(* ArkWeb_OnComponentCallback) (const char *webTag, void *userData)
```
**描述：**

组件事件通知相关的通用回调。

**起始版本：** 12


### ArkWeb_OnJavaScriptCallback

```
typedef void(* ArkWeb_OnJavaScriptCallback) (const char *webTag, const ArkWeb_JavaScriptBridgeData *data, void *userData)
```
**描述：**

注入的JavaScript执行完成的回调。

**起始版本：** 12


### ArkWeb_OnJavaScriptProxyCallback

```
typedef void(* ArkWeb_OnJavaScriptProxyCallback) (const char *webTag, const ArkWeb_JavaScriptBridgeData *dataArray, size_t arraySize, void *userData)
```
**描述：**

Proxy方法被执行的回调。

**起始版本：** 12


### ArkWeb_OnJavaScriptProxyCallbackWithResult

```
typedef ArkWeb_JavaScriptValuePtr(* ArkWeb_OnJavaScriptProxyCallbackWithResult) (const char *webTag, const ArkWeb_JavaScriptBridgeData *dataArray, size_t arraySize, void *userData)
```
**描述：**

Proxy方法被执行的回调。

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件名称。  | 
| dataArray | 数组数据。  | 
| arraySize | 数组大小。  | 
| userData | 用户自定义的数据。 | 


### ArkWeb_OnMessageEventHandler

```
typedef void(* ArkWeb_OnMessageEventHandler) (const char *webTag, const ArkWeb_WebMessagePortPtr port, const ArkWeb_WebMessagePtr message, void *userData)
```
**描述：**

处理HTML发送过来的Post Message数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件名称。  | 
| port | Post Message端口。  | 
| message | Post Message数据。  | 
| userData | 用户自定义数据。 | 


### ArkWeb_OnRequestStart

```
typedef void(* ArkWeb_OnRequestStart) (const ArkWeb_SchemeHandler *schemeHandler, ArkWeb_ResourceRequest *resourceRequest, const ArkWeb_ResourceHandler *resourceHandler, bool *intercept)
```
**描述：**

请求开始的回调，这将在IO线程上被调用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler。  | 
| resourceRequest | 通过该对象获取请求的信息。  | 
| resourceHandler | 请求的ArkWeb_ResourceHandler。如果intercept设置为false，则不应使用它。  | 
| intercept | 如果为true，则会拦截请求；如果为false，则不会拦截。 | 


### ArkWeb_OnRequestStop

```
typedef void(* ArkWeb_OnRequestStop) (const ArkWeb_SchemeHandler *schemeHandler, const ArkWeb_ResourceRequest *resourceRequest)
```
**描述：**

请求完成时的回调函数。

这将在IO线程上被调用。

应该使用ArkWeb_ResourceRequest_Destroy销毁resourceRequest，

并使用ArkWeb_ResourceHandler_Destroy销毁在ArkWeb_OnRequestStart中接收到的ArkWeb_ResourceHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler。  | 
| resourceRequest | ArkWeb_ResourceRequest。 | 


### ArkWeb_RequestHeaderList

```
typedef struct ArkWeb_RequestHeaderList_ ArkWeb_RequestHeaderList
```
**描述：**

请求头列表。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_ResourceHandler

```
typedef struct ArkWeb_ResourceHandler_ ArkWeb_ResourceHandler
```
**描述：**

用于被拦截的URL请求。

可以通过ArkWeb_ResourceHandler发送自定义请求头以及自定义请求体。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_ResourceRequest

```
typedef struct ArkWeb_ResourceRequest_ ArkWeb_ResourceRequest
```
**描述：**

对应内核的一个请求，可以通过OH_ArkWeb_ResourceRequest获取请求的URL、method、post data以及其他信息。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_ResourceType

```
typedef enum ArkWeb_ResourceType ArkWeb_ResourceType
```
**描述：**

请求的资源类型。

这些常量与Chromium中的ResourceType的对应项相匹配，不应重新编号。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_Response

```
typedef struct ArkWeb_Response_ ArkWeb_Response
```
**描述：**

为被拦截的请求构造一个ArkWeb_Response。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_SchemeHandler

```
typedef struct ArkWeb_SchemeHandler_ ArkWeb_SchemeHandler
```
**描述：**

该类用于拦截指定scheme的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12


### ArkWeb_WebMessagePortPtr

```
typedef struct ArkWeb_WebMessagePort* ArkWeb_WebMessagePortPtr
```
**描述：**

Post Message端口结构体指针。

**起始版本：** 12


### ArkWeb_WebMessagePtr

```
typedef struct ArkWeb_WebMessage* ArkWeb_WebMessagePtr
```
**描述：**

Post Message数据结构体指针。

**起始版本：** 12


### ArkWeb_WebMessageType

```
typedef enum ArkWeb_WebMessageType ArkWeb_WebMessageType
```
**描述：**

Post Message数据类型。

**起始版本：** 12


### NativeArkWeb_OnDestroyCallback

```
typedef void(* NativeArkWeb_OnDestroyCallback) (const char *)
```
**描述：**

定义Web组件销毁时的回调函数的类型。

**起始版本：** 11


### NativeArkWeb_OnJavaScriptCallback

```
typedef void(* NativeArkWeb_OnJavaScriptCallback) (const char *)
```
**描述：**

定义执行JavaScript代码后返回结果的回调函数的类型。

**起始版本：** 11


### NativeArkWeb_OnJavaScriptProxyCallback

```
typedef char*(* NativeArkWeb_OnJavaScriptProxyCallback) (const char **argv, int32_t argc)
```
**描述：**

定义注入对象的回调函数的类型。

**起始版本：** 11


### NativeArkWeb_OnValidCallback

```
typedef void(* NativeArkWeb_OnValidCallback) (const char *)
```
**描述：**

定义Web组件可用时的回调函数的类型。

**起始版本：** 11


## 枚举类型说明


### ArkWeb_CustomSchemeOption

```
enum ArkWeb_CustomSchemeOption
```
**描述：**

custom scheme的配置信息。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKWEB_SCHEME_OPTION_STANDARD  | 如果设置了ARKWEB_SCHEME_OPTION_STANDARD，那么该scheme将被视为标准scheme来处理。 标准scheme需要遵守在RFC 1738第3.1节中定义的URL规范化和解析规则，该规则可以在 [http://www.ietf.org/rfc/rfc1738.txt](http://www.ietf.org/rfc/rfc1738.txt) 中找到。   | 
| ARKWEB_SCHEME_OPTION_LOCAL  | 如果设置了ARKWEB_SCHEME_OPTION_LOCAL，则将使用与“file” URL相同的安全规则来处理该scheme。   | 
| ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED  | 如果设置了ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED，则该scheme的请求只能由使用相同scheme加载的页面中发起。   | 
| ARKWEB_SCHEME_OPTION_SECURE  | 如果设置了ARKWEB_SCHEME_OPTION_SECURE，则将使用与“https” URL相同的安全规则来处理该scheme。   | 
| ARKWEB_SCHEME_OPTION_CORS_ENABLED  | 如果设置了ARKWEB_SCHEME_OPTION_CORS_ENABLED，则该scheme可以发送CORS请求。在大多数情况下，当设置了ARKWEB_SCHEME_OPTION_STANDARD时，应该设置此值。   | 
| ARKWEB_SCHEME_OPTION_CSP_BYPASSING  | 如果设置了ARKWEB_SCHEME_OPTION_CSP_BYPASSING，则该scheme可以绕过内容安全策略（CSP）检查。 在大多数情况下，当设置了ARKWEB_SCHEME_OPTION_STANDARD时，不应设置此值。   | 
| ARKWEB_SCHEME_OPTION_FETCH_ENABLED  | 如果设置了ARKWEB_SCHEME_OPTION_FETCH_ENABLED，则可以发起该scheme的FETCH API请求。   | 
| ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED  | 如果设置了ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED，则该scheme的js资源支持生成code cache。   | 


### ArkWeb_ErrorCode

```
enum ArkWeb_ErrorCode
```
**描述：**

定义ArkWeb NDK接口异常错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKWEB_SUCCESS  | 成功.   | 
| ARKWEB_INIT_ERROR  | 初始化失败.   | 
| ARKWEB_ERROR_UNKNOWN  | 未知错误。   | 
| ARKWEB_INVALID_PARAM  | 参数无效。   | 
| ARKWEB_SCHEME_REGISTER_FAILED  | 注册scheme的配置失败，应该在创建ArkWeb之前注册。   | 
| ARKWEB_INVALID_URL  | 无效的URL。   | 
| ARKWEB_INVALID_COOKIE_VALUE  | 无效的cookie值。   | 


### ArkWeb_JavaScriptValueType

```
enum ArkWeb_JavaScriptValueType
```
**描述：**

JavaScript数据类型。

**起始版本：** 14

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKWEB_JAVASCRIPT_NONE  | 错误数据。   | 
| ARKWEB_JAVASCRIPT_STRING  | 字符串数据类型。   | 
| ARKWEB_JAVASCRIPT_BOOL  | bool数据类型。   | 


### ArkWeb_NativeAPIVariantKind

```
enum ArkWeb_NativeAPIVariantKind
```
**描述：**

定义Native API的类型枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKWEB_NATIVE_COMPONENT  | component相关API类型。   | 
| ARKWEB_NATIVE_CONTROLLER  | controller相关API类型。   | 
| ARKWEB_NATIVE_WEB_MESSAGE_PORT  | webMessagePort相关API类型。   | 
| ARKWEB_NATIVE_WEB_MESSAGE  | webMessage相关API类型。   | 
| ARKWEB_NATIVE_COOKIE_MANAGER  | cookieManager相关API类型。   | 
| ARKWEB_NATIVE_JAVASCRIPT_VALUE  | JavaScriptValue相关接口类型。<br/>自从<br/>14 | 


### ArkWeb_NetError

```
enum ArkWeb_NetError
```
**描述：**

定义ArkWeb网络协议栈错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKWEB_NET_OK  | 正常。   | 
| ARKWEB_ERR_IO_PENDING  | 异步IO操作尚未完成。这通常并不表示致命错误。通常，这个错误将作为通知生成，以等待某个外部通知，表明IO操作最终已完成。   | 
| ARKWEB_ERR_FAILED  | 发生了通用故障。   | 
| ARKWEB_ERR_ABORTED  | 操作被中止（由于用户操作）。   | 
| ARKWEB_ERR_INVALID_ARGUMENT  | 该函数的参数不正确。   | 
| ARKWEB_ERR_INVALID_HANDLE  | 句柄或文件描述符无效。   | 
| ARKWEB_ERR_FILE_NOT_FOUND  | 文件或目录无法找到。   | 
| ARKWEB_ERR_TIMED_OUT  | 操作超时。   | 
| ARKWEB_ERR_FILE_TOO_LARGE  | 文件过大。   | 
| ARKWEB_ERR_UNEXPECTED  | 发生了一个意外的错误。这可能是由编程错误或无效的假设导致的。   | 
| ARKWEB_ERR_ACCESS_DENIED  | 访问除网络外的资源被拒绝。   | 
| ARKWEB_ERR_NOT_IMPLEMENTED  | 由于功能未实现，操作失败。   | 
| ARKWEB_ERR_INSUFFICIENT_RESOURCES  | 没有足够的资源来完成操作。   | 
| ARKWEB_ERR_OUT_OF_MEMORY  | 内存溢出。   | 
| ARKWEB_ERR_UPLOAD_FILE_CHANGED  | 文件上传失败，因为文件的修改时间与预期不同。   | 
| ARKWEB_ERR_SOCKET_NOT_CONNECTED  | socket未连接。   | 
| ARKWEB_ERR_FILE_EXISTS  | 文件已存在。   | 
| ARKWEB_ERR_FILE_PATH_TOO_LONG  | 文件路径或者文件名过长。   | 
| ARKWEB_ERR_FILE_NO_SPACE  | 磁盘上剩余空间不足。   | 
| ARKWEB_ERR_FILE_VIRUS_INFECTED  | 文件含有病毒。   | 
| ARKWEB_ERR_BLOCKED_BY_CLIENT  | 客户端选择阻止该请求。   | 
| ARKWEB_ERR_NETWORK_CHANGED  | 网络发生变化。   | 
| ARKWEB_ERR_BLOCKED_BY_ADMINISTRATOR  | 请求被域管理员配置的URL阻止列表所阻止。   | 
| ARKWEB_ERR_SOCKET_CONNECTED  | socket已连接。   | 
| ARKWEB_ERR_UPLOAD_STREAM_REWIND_NOT_SUPPORTED  | 由于重试或重定向，需要重新读取上传流，但上传流不支持该操作，因此上传失败。   | 
| ARKWEB_ERR_CONTEXT_SHUT_DOWN  | 请求失败，因为URLRequestContext正在关闭或已经关闭。   | 
| ARKWEB_ERR_BLOCKED_BY_RESPONSE  | 请求失败，因为响应不满足要求（例如“X-Frame-Options”和“Content Security Policy”检查以及“Cross Origin Resource Policy”）。   | 
| ARKWEB_ERR_CLEARTEXT_NOT_PERMITTED  | 由于系统策略禁止某些或所有明文请求，请求被阻止。   | 
| ARKWEB_ERR_BLOCKED_BY_CSP  | 请求被内容安全策略阻止。   | 
| ARKWEB_ERR_H2_OR_QUIC_REQUIRED  | 由于没有H/2或QUIC会话，请求被阻止。   | 
| ARKWEB_ERR_BLOCKED_BY_ORB  | 请求被CORB或ORB阻止。   | 
| ARKWEB_ERR_CONNECTION_CLOSED  | 连接已关闭（对应于TCP FIN）。   | 
| ARKWEB_ERR_CONNECTION_RESET  | 连接被重置（对应于TCP RST）。   | 
| ARKWEB_ERR_CONNECTION_REFUSED  | 连接尝试被拒绝。   | 
| ARKWEB_ERR_CONNECTION_ABORTED  | 由于未收到发送数据的ACK而导致连接超时。这可能包括未收到ACK的FIN数据包。   | 
| ARKWEB_ERR_CONNECTION_FAILED  | 连接尝试失败。   | 
| ARKWEB_ERR_NAME_NOT_RESOLVED  | 域名无法解析。   | 
| ARKWEB_ERR_INTERNET_DISCONNECTED  | 网络断开。   | 
| ARKWEB_ERR_SSL_PROTOCOL_ERROR  | 发生了SSL协议错误。   | 
| ARKWEB_ERR_ADDRESS_INVALID  | IP地址或端口号无效（例如，无法连接到IP地址0或端口0）。   | 
| ARKWEB_ERR_ADDRESS_UNREACHABLE  | IP地址无法访问。这通常意味着没有到达指定主机或网络的路由。   | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NEEDED  | 服务器请求SSL客户端身份验证的客户端证书。   | 
| ARKWEB_ERR_TUNNEL_CONNECTION_FAILED  | 无法通过代理建立隧道连接。   | 
| ARKWEB_ERR_NO_SSL_VERSIONS_ENABLED  | 未启用任何SSL协议版本。   | 
| ARKWEB_ERR_SSL_VERSION_OR_CIPHER_MISMATCH  | 客户端和服务器不支持通用的SSL协议版本或密码套件。   | 
| ARKWEB_ERR_SSL_RENEGOTIATION_REQUESTED  | 服务器请求重新协商（重新握手）。   | 
| ARKWEB_ERR_PROXY_AUTH_UNSUPPORTED  | 代理请求进行身份验证（用于建立隧道，但使用的方法不受支持）。   | 
| ARKWEB_ERR_BAD_SSL_CLIENT_AUTH_CERT  | SSL握手未能成功，原因是客户端证书不正确或缺失。   | 
| ARKWEB_ERR_CONNECTION_TIMED_OUT  | 连接尝试超时。   | 
| ARKWEB_ERR_HOST_RESOLVER_QUEUE_TOO_LARGE  | 有太多待处理的DNS解析，因此队列中的一个请求被中止了。   | 
| ARKWEB_ERR_SOCKS_CONNECTION_FAILED  | 为目标主机建立到SOCKS代理服务器的连接失败。   | 
| ARKWEB_ERR_SOCKS_CONNECTION_HOST_UNREACHABLE  | SOCKS代理服务器无法建立与目标主机的连接，因为该主机无法访问。   | 
| ARKWEB_ERR_ALPN_NEGOTIATION_FAILED  | 协商备用协议的请求失败。   | 
| ARKWEB_ERR_SSL_NO_RENEGOTIATION  | 对等端发送了SSL no_regregation警报消息。   | 
| ARKWEB_ERR_WINSOCK_UNEXPECTED_WRITTEN_BYTES  | Winsock有时会报告写入的数据多于传递的数据。这可能是由于LSP损坏。   | 
| ARKWEB_ERR_SSL_DECOMPRESSION_FAILURE_ALERT  | SSL对等端向我们发送了一个致命的decompression_failure警告。这通常发生在对等端错误地认为它支持DEFLATE压缩并选择它时。   | 
| ARKWEB_ERR_SSL_BAD_RECORD_MAC_ALERT  | SSL对等端向我们发送了一个致命的bad_record_mac警告。这通常发生在错误支持DEFLATE的服务器上。   | 
| ARKWEB_ERR_PROXY_AUTH_REQUESTED  | 代理请求身份验证（用于建立隧道）。   | 
| ARKWEB_ERR_PROXY_CONNECTION_FAILED  | 无法创建到代理服务器的连接。在解析其名称或将其套接字连接到代理服务器时发生错误。请注意，这不包括HTTP代理的实际“CONNECT”方法期间的失败。   | 
| ARKWEB_ERR_MANDATORY_PROXY_CONFIGURATION_FAILED  | 无法使用强制代理配置。目前，这意味着无法获取、解析或执行强制PAC脚本。   | 
| ARKWEB_ERR_PRECONNECT_MAX_SOCKET_LIMIT  | 在预连接时，我们已达到套接字池的最大套接字限制。我们不再尝试预连接更多套接字。   | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_PRIVATE_KEY_ACCESS_DENIED  | 使用SSL客户端证书的私钥的权限被拒绝。   | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NO_PRIVATE_KEY  | SSL客户端证书没有私钥。   | 
| ARKWEB_ERR_PROXY_CERTIFICATE_INVALID  | HTTPS代理提供的证书无效。   | 
| ARKWEB_ERR_NAME_RESOLUTION_FAILED  | 在尝试进行域名解析（DNS）时发生错误。   | 
| ARKWEB_ERR_NETWORK_ACCESS_DENIED  | 访问网络的权限被拒绝。这用于区分很可能是由防火墙导致的错误和其他访问被拒绝的错误。另请参阅ERR_ACCESS_DENIED。   | 
| ARKWEB_ERR_TEMPORARILY_THROTTLED  | 请求节流模块取消了此请求，以避免DDOS攻击。   | 
| ARKWEB_ERR_HTTPS_PROXY_TUNNEL_RESPONSE_REDIRECT  | 通过HTTPS代理创建SSL隧道连接的请求收到了302（临时重定向）响应。响应体可能包含请求失败原因的说明。   | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_SIGNATURE_FAILED  | 我们无法使用客户端证书的私钥签署SSL客户端身份验证握手的CertificateVerify数据。 可能导致这种情况的原因包括用户隐式或显式地拒绝访问私钥，私钥可能无法用于签名，密钥可能依赖于已无效的缓存句柄，或者CSP不允许签署任意数据。   | 
| ARKWEB_ERR_MSG_TOO_BIG  | 消息对于传输来说太大了。（例如，UDP消息超过了大小阈值）。   | 
| ARKWEB_ERR_WS_PROTOCOL_ERROR  | Websocket协议错误。表示由于帧格式错误或其他协议违规，我们正在终止连接。   | 
| ARKWEB_ERR_ADDRESS_IN_USE  | 当尝试绑定已使用的地址时返回。   | 
| ARKWEB_ERR_SSL_HANDSHAKE_NOT_COMPLETED  | 由于SSL握手尚未完成，操作失败。   | 
| ARKWEB_ERR_SSL_BAD_PEER_PUBLIC_KEY  | SSL对等方的公钥无效。   | 
| ARKWEB_ERR_SSL_PINNED_KEY_NOT_IN_CERT_CHAIN  | 证书与主机名的内置公钥Pins不匹配。Pin在net/http/transport_security_state.cc中设置，并且要求在从叶节点到根节点的路径上存在一组公钥中的一个。   | 
| ARKWEB_ERR_CLIENT_AUTH_CERT_TYPE_UNSUPPORTED  | 服务器请求客户端证书，但请求中未包含我们支持的任何类型。   | 
| ARKWEB_ERR_SSL_DECRYPT_ERROR_ALERT  | SSL对等端向我们发送了一个致命的decrypt_error警告。这通常发生在对等端无法正确验证签名（在CertificateVerify或ServerKeyExchange中）或验证Finished消息时。   | 
| ARKWEB_ERR_WS_THROTTLE_QUEUE_TOO_LARGE  | 待处理的WebSocketJob实例太多，因此新任务没有推送到队列中。   | 
| ARKWEB_ERR_SSL_SERVER_CERT_CHANGED  | 在重新协商过程中，SSL服务器证书发生了更改。   | 
| ARKWEB_ERR_SSL_UNRECOGNIZED_NAME_ALERT  | SSL服务器向我们发送了一个致命的unrecognized_name警告。   | 
| ARKWEB_ERR_SOCKET_SET_RECEIVE_BUFFER_SIZE_ERROR  | 无法按照请求设置套接字的接收缓冲区大小。   | 
| ARKWEB_ERR_SOCKET_SET_SEND_BUFFER_SIZE_ERROR  | 无法按照请求设置套接字的发送缓冲区大小。   | 
| ARKWEB_ERR_SOCKET_RECEIVE_BUFFER_SIZE_UNCHANGEABLE  | 尽管setsockopt返回成功代码，但无法将套接字的接收缓冲区大小设置为所请求的值。   | 
| ARKWEB_ERR_SOCKET_SEND_BUFFER_SIZE_UNCHANGEABLE  | 尽管setsockopt返回成功代码，但无法将套接字的发送缓冲区大小设置为所请求的值。   | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_BAD_FORMAT  | 无法将客户端证书从平台存储导入到SSL库中。   | 
| ARKWEB_ERR_ICANN_NAME_COLLISION  | 将主机名解析为IP地址列表时，包含了IPv4地址“127.0.53.53”。这是ICANN推荐的一个特殊IP地址，用于指示存在名称冲突，并提醒管理员注意潜在问题。   | 
| ARKWEB_ERR_SSL_SERVER_CERT_BAD_FORMAT  | SSL服务器提供了一个无法解码的证书。这不是一个证书错误代码，因为没有可用的X509Certificate对象。这个错误是致命的。   | 
| ARKWEB_ERR_CT_STH_PARSING_FAILED  | Certificate Transparency:收到的Signed Tree Head无法解析。   | 
| ARKWEB_ERR_CT_STH_INCOMPLETE  | 证书透明度：收到的已签名树头可以成功解析为JSON，但缺少某些字段。   | 
| ARKWEB_ERR_UNABLE_TO_REUSE_CONNECTION_FOR_PROXY_AUTH  | 在AuthController用于生成凭据之前，尝试重用连接以发送代理身份验证凭据失败。调用者应该使用新连接重新使用控制器。此错误仅由网络堆栈内部使用。   | 
| ARKWEB_ERR_CT_CONSISTENCY_PROOF_PARSING_FAILED  | 证书透明度：无法解析收到的一致性证明。   | 
| ARKWEB_ERR_SSL_OBSOLETE_CIPHER  | SSL服务器要求一个已被移除的不受支持的密码套件。在这个密码套件被移除后的一两个版本更新中，作为回退策略，这个错误将被临时发出信号，之后回退策略将被移除。   | 
| ARKWEB_ERR_WS_UPGRADE  | 当WebSocket握手成功完成并且连接已升级时，将使用此错误代码取消URLRequest。   | 
| ARKWEB_ERR_READ_IF_READY_NOT_IMPLEMENTED  | Socket ReadIfReady支持尚未实现。这个错误不应该被用户看到，因为正常的Read方法将作为备选方案使用。   | 
| ARKWEB_ERR_NO_BUFFER_SPACE  | 没有可用的套接字缓冲区空间。   | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_NO_COMMON_ALGORITHMS  | 我们的客户端证书私钥和服务器的首选项之间没有共同的签名算法。   | 
| ARKWEB_ERR_EARLY_DATA_REJECTED  | TLS 1.3 Early Data被服务器拒绝。这将在从套接字返回任何数据之前收到。应该禁用Early Data并重试请求。   | 
| ARKWEB_ERR_WRONG_VERSION_ON_EARLY_DATA  | 提供了TLS 1.3 Early Data，但服务器以TLS 1.2或更早版本进行响应。这是为了解决Early Data和TLS 1.2之间向后兼容问题的内部错误代码。 在套接字返回任何数据之前将收到此错误代码。应该禁用Early Data后重试请求。详情请参阅https://tools.ietf.org/html/rfc8446\#appendix-D.3。   | 
| ARKWEB_ERR_TLS13_DOWNGRADE_DETECTED  | 启用了TLS 1.3，但协商了一个较低版本，并且服务器返回了一个值，表明它支持TLS 1.3。 这是TLS 1.3安全检查的一部分，但也可能表明用户位于一个有问题的TLS终止代理之后，该代理错误地实现了TLS 1.2。（参见https://crbug.com/boringssl/226）   | 
| ARKWEB_ERR_SSL_KEY_USAGE_INCOMPATIBLE  | 服务器的证书有一个与协商的TLS密钥交换方法不兼容的keyUsage扩展。   | 
| ARKWEB_ERR_INVALID_ECH_CONFIG_LIST  | 通过DNS获取的ECHConfigList无法解析。   | 
| ARKWEB_ERR_ECH_NOT_NEGOTIATED  | 已启用ECH（Encrypted Client Hello，加密客户端Hello），但服务器无法解密加密的ClientHello。   | 
| ARKWEB_ERR_ECH_FALLBACK_CERTIFICATE_INVALID  | ECH（Encrypted Client Hello）已启用，但服务器无法解密加密的ClientHello，并且没有提供对公共名称有效的证书。   | 
| ARKWEB_ERR_CERT_COMMON_NAME_INVALID  | 服务器响应了一个证书，其通用名称与主机名不匹配。这可能意味着：1. 攻击者已将我们的流量重定向到他们的服务器，并呈现了一个他们知道私钥的证书。<br/>1. 服务器配置错误，响应了错误的证书。3. 用户处于无线网络中，被重定向到网络的登录页面。4. 操作系统使用了DNS搜索后缀，而服务器没有为地址栏中的缩写名称提供证书。  | 
| ARKWEB_ERR_CERT_DATE_INVALID  | 服务器以证书作为响应，但根据我们的时钟，该证书似乎尚未生效或已过期。这可能是以下情况之一：1. 攻击者提供了旧的证书，并设法获取了私钥。2. 服务器配置错误，没有提供有效的证书。3. 我们的时钟错误。   | 
| ARKWEB_ERR_CERT_AUTHORITY_INVALID  | 服务器回应了一个由我们不信任的机构签名的证书。这可能意味着：1. 攻击者已经将真实的证书替换为包含其公钥并由其同伙签名的证书。<br/>1. 服务器运营商拥有一个来自我们不了解但应该信任的CA的合法证书。3. 服务器正在展示一个自签名证书，这无法抵御活跃攻击者（但可以挫败被动攻击者）。  | 
| ARKWEB_ERR_CERT_CONTAINS_ERRORS  | 服务器返回的证书包含错误。此错误无法恢复。MSDN对此错误的描述如下："SSL证书包含错误。"注意：目前尚不清楚这与ERR_CERT_INVALID有何不同。 为了保持一致性，从现在开始，请使用ERR_CERT_INVALID代码代替此代码。   | 
| ARKWEB_ERR_CERT_NO_REVOCATION_MECHANISM  | 该证书没有用于确定其是否被吊销的机制。实际上，此证书无法被吊销。   | 
| ARKWEB_ERR_CERT_UNABLE_TO_CHECK_REVOCATION  | 此站点的安全证书的吊销信息不可用。这可能意味着：1. 攻击者已破解证书中的私钥，并阻止了我们尝试查明证书已被吊销的操作。2. 证书未被吊销，但吊销服务器繁忙或不可用。   | 
| ARKWEB_ERR_CERT_REVOKED  | 服务器响应的证书已被吊销。我们有能力忽略此错误，但这可能不是正确的做法。   | 
| ARKWEB_ERR_CERT_INVALID  | 服务器以无效的证书进行了响应。这个错误无法恢复。MSDN描述此错误如下："SSL证书无效。"   | 
| ARKWEB_ERR_CERT_WEAK_SIGNATURE_ALGORITHM  | 服务器使用弱签名算法签名的证书进行了响应。   | 
| ARKWEB_ERR_CERT_NON_UNIQUE_NAME  | 证书中指定的主机名不是唯一的。   | 
| ARKWEB_ERR_CERT_WEAK_KEY  | 服务器响应了一个包含弱密钥（例如，太小的RSA密钥）的证书。   | 
| ARKWEB_ERR_CERT_NAME_CONSTRAINT_VIOLATION  | 证书中声明的DNS名称违反了名称约束。   | 
| ARKWEB_ERR_CERT_VALIDITY_TOO_LONG  | 证书的有效期太长。   | 
| ARKWEB_ERR_CERTIFICATE_TRANSPARENCY_REQUIRED  | 此连接需要证书透明度，但服务器未提供符合策略的CT信息。   | 
| ARKWEB_ERR_CERT_SYMANTEC_LEGACY  | 证书链接到不再受信任的旧版Symantec根证书。   | 
| ARKWEB_ERR_CERT_KNOWN_INTERCEPTION_BLOCKED  | 已知该证书被除设备所有者之外的其他实体拦截。   | 
| ARKWEB_ERR_SSL_OBSOLETE_VERSION_OR_CIPHER  | 连接使用了SSL/TLS或加密算法的过时版本。   | 
| ARKWEB_ERR_CERT_END  | 紧接在最后一个证书错误代码之后的值。   | 
| ARKWEB_ERR_INVALID_URL  | URL无效。   | 
| ARKWEB_ERR_DISALLOWED_URL_SCHEME  | URL的scheme不被允许。   | 
| ARKWEB_ERR_UNKNOWN_URL_SCHEME  | 该URL的scheme未知。   | 
| ARKWEB_ERR_INVALID_REDIRECT  | 尝试加载一个URL导致重定向到一个无效的URL。   | 
| ARKWEB_ERR_TOO_MANY_REDIRECTS  | 尝试加载一个URL时发生了太多次重定向。   | 
| ARKWEB_ERR_UNSAFE_REDIRECT  | 尝试加载某个URL时出现了不安全的重定向（例如，重定向到file://被视为不安全）。   | 
| ARKWEB_ERR_UNSAFE_PORT  | 尝试加载带有不安全端口号的URL。   | 
| ARKWEB_ERR_INVALID_RESPONSE  | 服务器的响应无效。   | 
| ARKWEB_ERR_INVALID_CHUNKED_ENCODING  | 块传输编码中出现错误。   | 
| ARKWEB_ERR_METHOD_UNSUPPORTED  | 服务器不支持该请求方法。   | 
| ARKWEB_ERR_UNEXPECTED_PROXY_AUTH  | 响应是407（需要代理身份验证），但我们并没有将请求发送到代理。   | 
| ARKWEB_ERR_EMPTY_RESPONSE  | 服务器关闭了连接而没有发送任何数据。   | 
| ARKWEB_ERR_RESPONSE_HEADERS_TOO_BIG  | 响应的headers部分过大。   | 
| ARKWEB_ERR_PAC_SCRIPT_FAILED  | PAC脚本的执行失败。   | 
| ARKWEB_ERR_REQUEST_RANGE_NOT_SATISFIABLE  | 响应是416（请求的范围无法满足，服务器无法满足请求的范围）。   | 
| ARKWEB_ERR_MALFORMED_IDENTITY  | 用于身份验证的身份无效。   | 
| ARKWEB_ERR_CONTENT_DECODING_FAILED  | 响应体的内容解码失败。   | 
| ARKWEB_ERR_NETWORK_IO_SUSPENDED  | 一个操作无法完成，因为所有网络IO都已挂起。   | 
| ARKWEB_ERR_SYN_REPLY_NOT_RECEIVED  | 在流上未收到SYN_REPLY就接收到了FLIP数据。   | 
| ARKWEB_ERR_ENCODING_CONVERSION_FAILED  | 将响应转换为目标编码失败。   | 
| ARKWEB_ERR_UNRECOGNIZED_FTP_DIRECTORY_LISTING_FORMAT  | 服务器发送了一个我们无法理解的FTP目录列表格式。   | 
| ARKWEB_ERR_NO_SUPPORTED_PROXIES  | 提供的列表中没有任何受支持的代理。   | 
| ARKWEB_ERR_HTTP2_PROTOCOL_ERROR  | 存在一个HTTP/2协议错误。   | 
| ARKWEB_ERR_INVALID_AUTH_CREDENTIALS  | 在HTTP认证过程中无法建立凭据。   | 
| ARKWEB_ERR_UNSUPPORTED_AUTH_SCHEME  | 尝试了一种此计算机不支持的HTTP身份验证方案。   | 
| ARKWEB_ERR_ENCODING_DETECTION_FAILED  | 检测响应的编码失败。   | 
| ARKWEB_ERR_MISSING_AUTH_CREDENTIALS  | （GSSAPI）在HTTP身份验证期间没有可用的Kerberos凭据。   | 
| ARKWEB_ERR_UNEXPECTED_SECURITY_LIBRARY_STATUS  | 返回了一个意外但已记录的SSPI或GSSAPI状态码。   | 
| ARKWEB_ERR_MISCONFIGURED_AUTH_ENVIRONMENT  | 认证环境未正确设置（例如，找不到KDC或主体未知）。   | 
| ARKWEB_ERR_UNDOCUMENTED_SECURITY_LIBRARY_STATUS  | 返回了一个未记录的SSPI或GSSAPI状态码。   | 
| ARKWEB_ERR_RESPONSE_BODY_TOO_BIG_TO_DRAIN  | HTTP响应太大，无法完全读取。   | 
| ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_LENGTH  | HTTP响应包含了多个不同的Content-Length响应头。   | 
| ARKWEB_ERR_INCOMPLETE_HTTP2_HEADERS  | 已经接收到HTTP/2的响应头，但并非全部——缺失了状态码或版本等响应头，因此我们期望更多的帧来完成它们。   | 
| ARKWEB_ERR_PAC_NOT_IN_DHCP  | 无法从DHCP检索PAC URL配置。这可能表明检索DHCP配置失败，或者在DHCP中没有配置PAC URL。   | 
| ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_DISPOSITION  | HTTP响应包含多个Content-Disposition响应头。   | 
| ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_LOCATION  | HTTP响应包含了多个Location响应头。   | 
| ARKWEB_ERR_HTTP2_SERVER_REFUSED_STREAM  | HTTP/2服务器在未处理请求的情况下拒绝了请求，并发送了带有错误代码NO_ERROR和低于与请求对应的流ID的Last-Stream-ID的GOAWAY帧， 表明该请求尚未处理，或者发送了带有错误代码REFUSED_STREAM的RST_STREAM帧。客户端可以重试（在不同的连接上）。请参阅RFC7540第8.1.4节。   | 
| ARKWEB_ERR_HTTP2_PING_FAILED  | HTTP/2服务器未响应PING消息。   | 
| ARKWEB_ERR_CONTENT_LENGTH_MISMATCH  | 当连接关闭时，HTTP响应主体传输的字节数少于Content-Length头中公布的字节数。   | 
| ARKWEB_ERR_INCOMPLETE_CHUNKED_ENCODING  | HTTP响应体使用分块编码传输，但在连接关闭时，终止的零长度区块从未被发送。   | 
| ARKWEB_ERR_QUIC_PROTOCOL_ERROR  | 存在QUIC协议错误。   | 
| ARKWEB_ERR_RESPONSE_HEADERS_TRUNCATED  | HTTP响应头信息被文件结束符（EOF）截断。   | 
| ARKWEB_ERR_QUIC_HANDSHAKE_FAILED  | QUIC加密握手失败。这意味着服务器无法读取发送的任何请求，因此它们可能会被重新发送。   | 
| ARKWEB_ERR_HTTP2_INADEQUATE_TRANSPORT_SECURITY  | 传输安全性不适合HTTP/2版本。   | 
| ARKWEB_ERR_HTTP2_FLOW_CONTROL_ERROR  | 对等方违反了HTTP/2流控制。   | 
| ARKWEB_ERR_HTTP2_FRAME_SIZE_ERROR  | 对等方发送了大小不正确的HTTP/2帧。   | 
| ARKWEB_ERR_HTTP2_COMPRESSION_ERROR  | 压缩HTTP/2响应头信息的解码或编码失败。   | 
| ARKWEB_ERR_PROXY_AUTH_REQUESTED_WITH_NO_CONNECTION  | 请求的代理身份验证没有有效的客户端套接字句柄。   | 
| ARKWEB_ERR_HTTP_1_1_REQUIRED  | 在HTTP/2会话中收到HTTP_1_1_REQUIRED错误代码。   | 
| ARKWEB_ERR_PROXY_HTTP_1_1_REQUIRED  | 在通过HTTP/2会话代理时收到HTTP_1_1_REQUIRED错误代码。   | 
| ARKWEB_ERR_PAC_SCRIPT_TERMINATED  | PAC脚本已终止并必须重新加载。   | 
| ARKWEB_ERR_INVALID_HTTP_RESPONSE  | 服务器应返回HTTP/1.x响应，但未返回。而不是将其视为HTTP/0.9，返回此错误。   | 
| ARKWEB_ERR_CONTENT_DECODING_INIT_FAILED  | 初始化内容解码失败。   | 
| ARKWEB_ERR_HTTP2_RST_STREAM_NO_ERROR_RECEIVED  | 收到带有NO_ERROR错误代码的HTTP/2 RST_STREAM帧。此错误应由HTTP/2代码内部处理，而不应超过SpdyStream层。   | 
| ARKWEB_ERR_HTTP2_PUSHED_STREAM_NOT_AVAILABLE  | 请求声明的推送流不再可用。   | 
| ARKWEB_ERR_HTTP2_CLAIMED_PUSHED_STREAM_RESET_BY_SERVER  | 已声明推送的流，随后服务器将其重置。发生这种情况时，应该重试请求。   | 
| ARKWEB_ERR_TOO_MANY_RETRIES  | 由于身份验证或证书无效，重试次数过多。   | 
| ARKWEB_ERR_HTTP2_STREAM_CLOSED  | 在已关闭的流上收到一个HTTP/2帧。   | 
| ARKWEB_ERR_HTTP2_CLIENT_REFUSED_STREAM  | 客户端拒绝了一个HTTP/2流。   | 
| ARKWEB_ERR_HTTP2_PUSHED_RESPONSE_DOES_NOT_MATCH  | 基于匹配的URL和请求头，一个HTTP/2推送的流被请求所接收，但是推送的响应头并不匹配请求。   | 
| ARKWEB_ERR_HTTP_RESPONSE_CODE_FAILURE  | 服务器返回了非2xx的HTTP响应代码。   | 
| ARKWEB_ERR_QUIC_UNKNOWN_CERT_ROOT  | 在QUIC连接上展示的证书未链接到已知根证书，并且连接到的原始服务器不在允许未知根证书的域名列表中。   | 
| ARKWEB_ERR_QUIC_GOAWAY_REQUEST_CAN_BE_RETRIED  | 已接收到一个GOAWAY帧，表明请求未得到处理，因此可以安全地在不同的连接上重试。   | 
| ARKWEB_ERR_TOO_MANY_ACCEPT_CH_RESTARTS  | ACCEPT_CH重启已被触发太多次。   | 
| ARKWEB_ERR_INCONSISTENT_IP_ADDRESS_SPACE  | 在相同的请求期间，远程端点的IP地址空间与先前观察到的值不同。任何受影响的请求的缓存条目都应被标记为无效。   | 
| ARKWEB_ERR_CACHED_IP_ADDRESS_SPACE_BLOCKED_BY_LOCAL_NETWORK_ACCESS_POLICY  | 缓存的远程端点的IP地址空间被本地网络访问检查所阻止。   | 
| ARKWEB_ERR_CACHE_MISS  | 缓存中没有请求的条目。   | 
| ARKWEB_ERR_CACHE_READ_FAILURE  | 无法从磁盘缓存中读取。   | 
| ARKWEB_ERR_CACHE_WRITE_FAILURE  | 无法写入磁盘缓存。   | 
| ARKWEB_ERR_CACHE_OPERATION_UNSUPPORTED  | 此条目不支持此操作。   | 
| ARKWEB_ERR_CACHE_OPEN_FAILURE  | 磁盘缓存无法打开此条目。   | 
| ARKWEB_ERR_CACHE_CREATE_FAILURE  | 磁盘缓存无法创建此条目。   | 
| ARKWEB_ERR_CACHE_RACE  | 多个事务正在竞相创建磁盘缓存条目。   | 
| ARKWEB_ERR_CACHE_CHECKSUM_READ_FAILURE  | 缓存无法读取条目上的校验和记录。   | 
| ARKWEB_ERR_CACHE_CHECKSUM_MISMATCH  | 缓存发现一个具有无效校验和的条目。   | 
| ARKWEB_ERR_CACHE_LOCK_TIMEOUT  | HTTP缓存的内部错误代码。   | 
| ARKWEB_ERR_CACHE_AUTH_FAILURE_AFTER_READ  | 在事务读取某些数据后收到质询，但凭据不可用。   | 
| ARKWEB_ERR_CACHE_ENTRY_NOT_SUITABLE  | 针对HTTP缓存的一个内部使用的、非标准的错误代码。   | 
| ARKWEB_ERR_CACHE_DOOM_FAILURE  | 磁盘缓存无法删除此条目。   | 
| ARKWEB_ERR_CACHE_OPEN_OR_CREATE_FAILURE  | 磁盘缓存无法打开或创建此条目。   | 
| ARKWEB_ERR_INSECURE_RESPONSE  | 服务器的响应不安全（例如，存在证书错误）。   | 
| ARKWEB_ERR_NO_PRIVATE_KEY_FOR_CERT  | 尝试导入客户端证书失败，因为用户的密钥数据库缺少相应的私钥。   | 
| ARKWEB_ERR_ADD_USER_CERT_FAILED  | 向操作系统证书数据库添加证书时发生错误。   | 
| ARKWEB_ERR_INVALID_SIGNED_EXCHANGE  | 处理已签名的交换时发生错误。   | 
| ARKWEB_ERR_INVALID_WEB_BUNDLE  | 处理Web Bundle源时发生错误。   | 
| ARKWEB_ERR_TRUST_TOKEN_OPERATION_FAILED  | 执行Trust Tokens协议操作的请求失败（原因包括：预置条件失败、内部错误、不良响应）。   | 
| ARKWEB_ERR_TRUST_TOKEN_OPERATION_SUCCESS_WITHOUT_SENDING_REQUEST  | 在处理一个与Trust Tokens协议相关的操作执行请求时，系统能够执行该请求中的Trust Tokens操作，但并没有将请求发送到其指定的目的地。   | 
| ARKWEB_ERR_FTP_FAILED  | FTP控制连接命令失败的通用错误。如果可能的话，请使用或添加一个更具体的错误代码。   | 
| ARKWEB_ERR_FTP_SERVICE_UNAVAILABLE  | 服务器目前无法满足请求。这是一个临时错误。FTP响应代码421。   | 
| ARKWEB_ERR_FTP_TRANSFER_ABORTED  | 服务器已中止传输。FTP响应代码426。   | 
| ARKWEB_ERR_FTP_FILE_BUSY  | 文件正在使用中，或在打开文件时发生了一些其他临时错误条件。FTP响应代码450。   | 
| ARKWEB_ERR_FTP_SYNTAX_ERROR  | 由于语法错误，服务器拒绝了我们的命令。FTP响应代码500、501。   | 
| ARKWEB_ERR_FTP_COMMAND_UNSUPPORTED  | 服务器不支持我们发出的命令。FTP响应代码502、504。   | 
| ARKWEB_ERR_FTP_BAD_COMMAND_SEQUENCE  | 服务器拒绝了我们的命令，因为我们没有按照正确的顺序发出命令。FTP响应代码503。   | 
| ARKWEB_ERR_PKCS12_IMPORT_BAD_PASSWORD  | 由于密码不正确，PKCS \#12导入失败。   | 
| ARKWEB_ERR_PKCS12_IMPORT_FAILED  | 由于其他错误，PKCS \#12导入失败。   | 
| ARKWEB_ERR_IMPORT_CA_CERT_NOT_CA  | CA导入失败——不是CA证书。   | 
| ARKWEB_ERR_IMPORT_CERT_ALREADY_EXISTS  | 导入失败——数据库中已存在证书。   | 
| ARKWEB_ERR_IMPORT_CA_CERT_FAILED  | 由于其他错误，CA导入失败。   | 
| ARKWEB_ERR_IMPORT_SERVER_CERT_FAILED  | 由于某些内部错误，服务器证书导入失败。   | 
| ARKWEB_ERR_PKCS12_IMPORT_INVALID_MAC  | PKCS \#12导入失败，因为MAC（消息认证码）无效。   | 
| ARKWEB_ERR_PKCS12_IMPORT_INVALID_FILE  | PKCS \#12导入失败，因为文件无效或已损坏。   | 
| ARKWEB_ERR_PKCS12_IMPORT_UNSUPPORTED  | 由于不支持的特性，PKCS \#12导入失败。   | 
| ARKWEB_ERR_KEY_GENERATION_FAILED  | 密钥生成失败。   | 
| ARKWEB_ERR_PRIVATE_KEY_EXPORT_FAILED  | 无法导出私钥。   | 
| ARKWEB_ERR_SELF_SIGNED_CERT_GENERATION_FAILED  | 自签名证书生成失败。   | 
| ARKWEB_ERR_CERT_DATABASE_CHANGED  | 证书数据库已发生某种更改。   | 
| ARKWEB_ERR_CERT_VERIFIER_CHANGED  | 证书验证配置已发生某种更改。   | 
| ARKWEB_ERR_DNS_MALFORMED_RESPONSE  | DNS解析程序收到格式错误的响应。   | 
| ARKWEB_ERR_DNS_SERVER_REQUIRES_TCP  | DNS服务器需要TCP。   | 
| ARKWEB_ERR_DNS_SERVER_FAILED  | DNS服务器失败。对于以下所有错误情况，都会返回此错误：1 - 格式错误 - 名称服务器无法解释查询。 2 - 服务器故障 - 名称服务器由于自身问题无法处理这个查询。4 - 未实现 - 名称服务器不支持请求的查询类型。 5 - 拒绝 - 名称服务器出于策略原因拒绝执行指定的操作。   | 
| ARKWEB_ERR_DNS_TIMED_OUT  | DNS事务超时。   | 
| ARKWEB_ERR_DNS_CACHE_MISS  | 对于只查询本地源的查找，在缓存或其他本地源中未找到该条目。   | 
| ARKWEB_ERR_DNS_SEARCH_EMPTY  | 后缀搜索列表规则阻止了给定主机名的解析。   | 
| ARKWEB_ERR_DNS_SORT_ERROR  | 未能根据RFC3484对地址进行排序。   | 
| ARKWEB_ERR_DNS_SECURE_RESOLVER_HOSTNAME_RESOLUTION_FAILED  | 未能解析DNS-over-HTTPS服务器的主机名。   | 
| ARKWEB_ERR_DNS_NAME_HTTPS_ONLY  | DNS已识别请求因不安全的连接（http/ws）而被禁止。应用程序应该像处理HTTP重定向一样处理这个错误，将连接重定向到安全的https或wss。   | 
| ARKWEB_ERR_DNS_REQUEST_CANCELED  | 与此任务相关的所有DNS请求已被取消。   | 
| ARKWEB_ERR_DNS_NO_MATCHING_SUPPORTED_ALPN  | HTTPS记录的主机名解析预期未能使用受支持协议的ALPN值进行解析。   | 


### ArkWeb_ResourceType

```
enum ArkWeb_ResourceType
```
**描述：**

请求的资源类型。

这些常量与Chromium中的ResourceType的对应项相匹配，不应重新编号。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MAIN_FRAME  | 顶层页面。   | 
| SUB_FRAME  | Frame或Iframe。   | 
| STYLE_SHEET  | CSS样式表。   | 
| SCRIPT  | 外部脚本。   | 
| IMAGE  | 图片（jpg/gif/png/以及其他）。   | 
| FONT_RESOURCE  | 字体。   | 
| SUB_RESOURCE  | 其他子资源。如果实际类型未知，则是默认类型。   | 
| OBJECT  | 插件的Object（或embed）标签，或者插件请求的资源。   | 
| MEDIA  | 媒体资源。   | 
| WORKER  | 专用工作线程的主资源。   | 
| SHARED_WORKER  | 共享工作线程的主资源。   | 
| PREFETCH  | 明确的预取请求。   | 
| FAVICON  | 网站图标。   | 
| XHR  | XMLHttpRequest。   | 
| PING  | /sendBeacon的Ping请求。   | 
| SERVICE_WORKER  | service worker的主资源。   | 
| CSP_REPORT  | 内容安全策略违规报告。   | 
| PLUGIN_RESOURCE  | 插件请求的资源。   | 
| NAVIGATION_PRELOAD_MAIN_FRAME  | 触发service worker预热的主frame跳转请求。   | 
| NAVIGATION_PRELOAD_SUB_FRAME  | 触发service worker预热的子frame跳转请求。   | 


### ArkWeb_WebMessageType

```
enum ArkWeb_WebMessageType
```
**描述：**

Post Message数据类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKWEB_NONE  | 错误数据。   | 
| ARKWEB_STRING  | 字符串数据类型。   | 
| ARKWEB_BUFFER  | 字节流数据类型。   | 


## 函数说明


### OH_ArkWeb_ClearSchemeHandlers()

```
int32_t OH_ArkWeb_ClearSchemeHandlers (const char * webTag)
```
**描述：**

清除为指定web注册的SchemeHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的标签名称，用于标识某个唯一组件，由开发者来保证名称唯一性。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWeb_CreateResponse()

```
void OH_ArkWeb_CreateResponse (ArkWeb_Response ** response)
```
**描述：**

为被拦截的请求创建一个ArkWeb_Response对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | 返回创建的ArkWeb_Response。在不需要时使用OH_ArkWeb_DestoryResponse进行销毁。 | 


### OH_ArkWeb_CreateSchemeHandler()

```
void OH_ArkWeb_CreateSchemeHandler (ArkWeb_SchemeHandler ** schemeHandler)
```
**描述：**

创建一个ArkWeb_SchemeHandler对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| schemeHandler | 返回创建的ArkWeb_SchemeHandler。在不需要时使用OH_ArkWeb_DestoryschemeHandler销毁它。 | 


### OH_ArkWeb_DestroyResponse()

```
void OH_ArkWeb_DestroyResponse (ArkWeb_Response * response)
```
**描述：**

销毁一个ArkWeb_Response对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | 待销毁的ArkWeb_Response。 | 


### OH_ArkWeb_DestroySchemeHandler()

```
void OH_ArkWeb_DestroySchemeHandler (ArkWeb_SchemeHandler * schemeHandler)
```
**描述：**

销毁一个ArkWeb_SchemeHandler对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| schemeHandler | 待销毁的ArkWeb_SchemeHandler。 | 


### OH_ArkWeb_GetNativeAPI()

```
ArkWeb_AnyNativeAPI* OH_ArkWeb_GetNativeAPI (ArkWeb_NativeAPIVariantKind type)
```
**描述：**

根据传入的API类型，获取对应的Native API结构体。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | ArkWeb支持的Native API类型。  | 

**返回：**

根据传入的API类型，返回对应的Native API结构体指针，结构体第一个成员为当前结构体的大小。


### OH_ArkWeb_RegisterCustomSchemes()

```
int32_t OH_ArkWeb_RegisterCustomSchemes (const char * scheme, int32_t option )
```
**描述：**

将custom scheme注册到ArkWeb。

对于内置的HTTP、HTTPS、FILE、FTP、ABOUT和DATA协议，不应调用此函数。

此函数应在主线程上调用并且需要在内核初始化之前调用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheme | 待注册的scheme。  | 
| option | scheme的配置（行为）。  | 

**返回：**

如果返回0，表示成功；返回17100100，表示未知错误；返回17100101，表示参数无效；返回17100102，表示注册scheme的配置失败，应该在创建ArkWeb之前注册。


### OH_ArkWeb_ReleaseByteArray()

```
void OH_ArkWeb_ReleaseByteArray (uint8_t * byteArray)
```
**描述：**

释放由NDK接口创建的字节数组。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| byteArray | 待释放的字节数组。 | 


### OH_ArkWeb_ReleaseString()

```
void OH_ArkWeb_ReleaseString (char * string)
```
**描述：**

释放由NDK接口创建的字符串

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| string | 待释放的字符串。 | 


### OH_ArkWeb_SetSchemeHandler()

```
bool OH_ArkWeb_SetSchemeHandler (const char * scheme, const char * webTag, ArkWeb_SchemeHandler * schemeHandler )
```
**描述：**

为指定scheme设置一个ArkWeb_SchemeHandler以拦截该scheme类型的请求。

应该在创建BrowserContext之后设置SchemeHandler。

可以使用WebviewController.initializeWebEngine来初始化BrowserContext而无需创建ArkWeb。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheme | 需要被拦截的scheme。  | 
| webTag | Web组件的标签名称，用于标识某个唯一组件，由开发者来保证名称唯一性。  | 
| schemeHandler | 该scheme的拦截器ArkWeb_SchemeHandler。只有从指定web触发的请求才会通过这个schemeHandler进行通知。  | 

**返回：**

如果为指定scheme设置SchemeHandler成功，则返回true，否则返回false。


### OH_ArkWebHttpBodyStream_GetPosition()

```
uint64_t OH_ArkWebHttpBodyStream_GetPosition (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**描述：**

获取httpBodyStream当前的读取位置。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 

**返回：**

httpBodyStream当前的读取位置。如果httpBodyStream无效，则位置为0。


### OH_ArkWebHttpBodyStream_GetSize()

```
uint64_t OH_ArkWebHttpBodyStream_GetSize (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**描述：**

获取httpBodyStream的大小。

当数据以分块的形式传输或httpBodyStream无效时，始终返回0。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 

**返回：**

httpBodyStream的大小。


### OH_ArkWebHttpBodyStream_GetUserData()

```
void* OH_ArkWebHttpBodyStream_GetUserData (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**描述：**

从ArkWeb_HttpBodyStream获取用户数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 

**返回：**

设置的用户数据。


### OH_ArkWebHttpBodyStream_Init()

```
int32_t OH_ArkWebHttpBodyStream_Init (ArkWeb_HttpBodyStream * httpBodyStream, ArkWeb_HttpBodyStreamInitCallback initCallback )
```
**描述：**

初始化ArkWeb_HttpBodyStream。

在调用任何其他函数之前，必须调用此函数。该接口需要在IO线程调用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 
| initCallback | 初始化的回调函数。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebHttpBodyStream_IsChunked()

```
bool OH_ArkWebHttpBodyStream_IsChunked (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**描述：**

获取httpBodyStream是否采用分块传输。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 

**返回：**

如果采用分块传输则返回true;否则返回false。


### OH_ArkWebHttpBodyStream_IsEof()

```
bool OH_ArkWebHttpBodyStream_IsEof (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**描述：**

如果httpBodyStream中的所有数据都已被读取，则返回true。

对于分块传输类型的httpBodyStream，在第一次读取尝试之前返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 

**返回：**

如果所有数据都已被读取则返回true；否则返回false。


### OH_ArkWebHttpBodyStream_IsInMemory()

```
bool OH_ArkWebHttpBodyStream_IsInMemory (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**描述：**

如果httpBodyStream中的上传数据完全在内存中，并且所有读取请求都将同步成功，则返回true。

对于分块传输类型的数据，预期返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 

**返回：**

如果上传数据完全在内存中则返回true；否则返回false。


### OH_ArkWebHttpBodyStream_Read()

```
void OH_ArkWebHttpBodyStream_Read (const ArkWeb_HttpBodyStream * httpBodyStream, uint8_t * buffer, int bufLen )
```
**描述：**

将请求的上传数据读取到buffer。

buffer的大小必须大于bufLen。我们将从工作线程读取数据到buffer，因此在回调函数返回之前，不应在其他线程中使用buffer，以避免并发问题。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 
| buffer | 接收数据的buffer。  | 
| bufLen | 要读取的字节的大小。 | 


### OH_ArkWebHttpBodyStream_SetReadCallback()

```
int32_t OH_ArkWebHttpBodyStream_SetReadCallback (ArkWeb_HttpBodyStream * httpBodyStream, ArkWeb_HttpBodyStreamReadCallback readCallback )
```
**描述：**

为OH_ArkWebHttpBodyStream_Read设置回调函数。

OH_ArkWebHttpBodyStream_Read的结果将通过readCallback通知给调用者。

该回调函数将在与OH_ArkWebHttpBodyStream_Read相同的线程中运行。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 
| readCallback | OH_ArkWebHttpBodyStream_Read的回调函数。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebHttpBodyStream_SetUserData()

```
int32_t OH_ArkWebHttpBodyStream_SetUserData (ArkWeb_HttpBodyStream * httpBodyStream, void * userData )
```
**描述：**

将一个用户数据设置到ArkWeb_HttpBodyStream对象中。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream。  | 
| userData | 要设置的用户数据。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebRequestHeaderList_Destroy()

```
void OH_ArkWebRequestHeaderList_Destroy (ArkWeb_RequestHeaderList * requestHeaderList)
```
**描述：**

销毁ArkWeb_RequestHeaderList对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestHeaderList | 将被销毁的ArkWeb_RequestHeaderList。 | 

### OH_ArkWebRequestHeaderList_GetHeader()

```
void OH_ArkWebRequestHeaderList_GetHeader (const ArkWeb_RequestHeaderList * requestHeaderList, int32_t index, char ** key, char ** value )
```
**描述：**

获取指定的请求头。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestHeaderList | 请求头列表。  | 
| index | 请求头的索引。  | 
| key | 请求头的键（key）。调用者必须使用OH_ArkWeb_ReleaseString函数来释放这个字符串。  | 
| value | 请求头的值（value）。调用者必须使用OH_ArkWeb_ReleaseString函数来释放这个字符串。 | 


### OH_ArkWebRequestHeaderList_GetSize()

```
int32_t OH_ArkWebRequestHeaderList_GetSize (const ArkWeb_RequestHeaderList * requestHeaderList)
```
**描述：**

获取请求头列表的大小。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestHeaderList | 请求头的列表。  | 

**返回：**

请求头的大小。如果requestHeaderList无效，则为-1。


### OH_ArkWebResourceHandler_Destroy()

```
int32_t OH_ArkWebResourceHandler_Destroy (const ArkWeb_ResourceHandler * resourceHandler)
```
**描述：**

销毁一个ArkWeb_ResourceHandler对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceHandler | ArkWeb_ResourceHandler。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResourceHandler_DidFailWithError()

```
int32_t OH_ArkWebResourceHandler_DidFailWithError (const ArkWeb_ResourceHandler * resourceHandler, ArkWeb_NetError errorCode )
```
**描述：**

通知ArkWeb内核被拦截请求应该失败。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceHandler | 该请求的ArkWeb_ResourceHandler。  | 
| errorCode | 该请求的错误码。请参考[arkweb_net_error_list.h](arkweb__net__error__list_8h.md)。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResourceHandler_DidFinish()

```
int32_t OH_ArkWebResourceHandler_DidFinish (const ArkWeb_ResourceHandler * resourceHandler)
```
**描述：**

通知ArkWeb内核被拦截的请求已经完成，并且没有更多的数据可用。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceHandler | 该请求的ArkWeb_ResourceHandler。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResourceHandler_DidReceiveData()

```
int32_t OH_ArkWebResourceHandler_DidReceiveData (const ArkWeb_ResourceHandler * resourceHandler, const uint8_t * buffer, int64_t bufLen )
```
**描述：**

将构造的响应体传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceHandler | 该请求的ArkWeb_ResourceHandler。  | 
| buffer | 要发送的buffer数据。  | 
| bufLen | buffer的大小。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResourceHandler_DidReceiveResponse()

```
int32_t OH_ArkWebResourceHandler_DidReceiveResponse (const ArkWeb_ResourceHandler * resourceHandler, const ArkWeb_Response * response )
```
**描述：**

将构造的响应头传递给被拦截的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceHandler | 该请求的ArkWeb_ResourceHandler。  | 
| response | 该拦截请求的ArkWeb_Response。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResourceRequest_Destroy()

```
int32_t OH_ArkWebResourceRequest_Destroy (const ArkWeb_ResourceRequest * resourceRequest)
```
**描述：**

销毁ArkWeb_ResourceRequest对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResourceRequest_DestroyHttpBodyStream()

```
void OH_ArkWebResourceRequest_DestroyHttpBodyStream (ArkWeb_HttpBodyStream * httpBodyStream)
```
**描述：**

销毁ArkWeb_HttpBodyStream对象。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| httpBodyStream | 待销毁的httpBodyStream。 | 


### OH_ArkWebResourceRequest_GetFrameUrl()

```
void OH_ArkWebResourceRequest_GetFrameUrl (const ArkWeb_ResourceRequest * resourceRequest, char ** frameUrl )
```
**描述：**

获取触发此请求的Frame的URL。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 
| frameUrl | 触发此请求的Frame的URL。此函数将为URL字符串分配内存，并且调用者必须通过OH_ArkWeb_ReleaseString来释放该字符串。 | 


### OH_ArkWebResourceRequest_GetHttpBodyStream()

```
void OH_ArkWebResourceRequest_GetHttpBodyStream (const ArkWeb_ResourceRequest * resourceRequest, ArkWeb_HttpBodyStream ** httpBodyStream )
```
**描述：**

创建一个ArkWeb_HttpBodyStream，用于读取请求的上传数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 
| httpBodyStream | 请求的上传数据。此函数将为httpBodyStream分配内存， 调用者必须使用OH_ArkWebResourceRequest_DestroyHttpBodyStream释放httpBodyStream。 | 


### OH_ArkWebResourceRequest_GetMethod()

```
void OH_ArkWebResourceRequest_GetMethod (const ArkWeb_ResourceRequest * resourceRequest, char ** method )
```
**描述：**

获取请求的method。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 
| method | HTTP请求方法。此函数将为method字符串分配内存，调用者必须使用OH_ArkWeb_ReleaseString释放字符串。 | 


### OH_ArkWebResourceRequest_GetReferrer()

```
void OH_ArkWebResourceRequest_GetReferrer (const ArkWeb_ResourceRequest * resourceRequest, char ** referrer )
```
**描述：**

获取请求的Referrer。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 
| referrer | 请求的Referrer。此函数将为referrer字符串分配内存，调用者必须使用 OH_ArkWeb_ReleaseString 释放该字符串。 | 


### OH_ArkWebResourceRequest_GetRequestHeaders()

```
void OH_ArkWebResourceRequest_GetRequestHeaders (const ArkWeb_ResourceRequest * resourceRequest, ArkWeb_RequestHeaderList ** requestHeaderList )
```
**描述：**

获取请求的请求头列表OH_ArkWeb_RequestHeaderList。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 
| requestHeaderList | 请求的请求头列表。 | 


### OH_ArkWebResourceRequest_GetResourceType()

```
int32_t OH_ArkWebResourceRequest_GetResourceType (const ArkWeb_ResourceRequest * resourceRequest)
```
**描述：**

获取请求的资源类型。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 

**返回：**

请求的资源类型。如果resourceRequest无效，则为-1。


### OH_ArkWebResourceRequest_GetUrl()

```
void OH_ArkWebResourceRequest_GetUrl (const ArkWeb_ResourceRequest * resourceRequest, char ** url )
```
**描述：**

获取请求的url。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 
| url | 请求的URL。此函数将为URL字符串分配内存，调用者必须通过OH_ArkWeb_ReleaseString释放该字符串。 | 


### OH_ArkWebResourceRequest_GetUserData()

```
void* OH_ArkWebResourceRequest_GetUserData (const ArkWeb_ResourceRequest * resourceRequest)
```
**描述：**

从ArkWeb_ResourceRequest获取用户数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 

**返回：**

设置的用户数据。


### OH_ArkWebResourceRequest_HasGesture()

```
bool OH_ArkWebResourceRequest_HasGesture (const ArkWeb_ResourceRequest * resourceRequest)
```
**描述：**

判断这是否是一个由用户手势触发的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 

**返回：**

如果这是由用户手势触发的，则返回true；否则返回false。


### OH_ArkWebResourceRequest_IsMainFrame()

```
bool OH_ArkWebResourceRequest_IsMainFrame (const ArkWeb_ResourceRequest * resourceRequest)
```
**描述：**

判断这是否是主框架文档资源的请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 

**返回：**

如果这是来自主框架，则返回true；否则返回false。


### OH_ArkWebResourceRequest_IsRedirect()

```
bool OH_ArkWebResourceRequest_IsRedirect (const ArkWeb_ResourceRequest * resourceRequest)
```
**描述：**

判断这是否是一个重定向请求。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 

**返回：**

如果这是一个重定向，则返回true；否则返回false。


### OH_ArkWebResourceRequest_SetUserData()

```
int32_t OH_ArkWebResourceRequest_SetUserData (ArkWeb_ResourceRequest * resourceRequest, void * userData )
```
**描述：**

将一个用户数据设置到ArkWeb_ResourceRequest对象中。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest。  | 
| userData | 将要设置的用户数据。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResponse_GetCharset()

```
void OH_ArkWebResponse_GetCharset (const ArkWeb_Response * response, char ** charset )
```
**描述：**

获取ArkWeb_Response的字符集。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| charset | 返回ArkWeb_Response的字符集。此函数将为charset字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放字符串。 | 


### OH_ArkWebResponse_GetError()

```
ArkWeb_NetError OH_ArkWebResponse_GetError (const ArkWeb_Response * response)
```
**描述：**

获取ArkWeb_Response的错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 

**返回：**

ArkWeb_Response的错误码。


### OH_ArkWebResponse_GetHeaderByName()

```
void OH_ArkWebResponse_GetHeaderByName (const ArkWeb_Response * response, const char * name, char ** value )
```
**描述：**

从ArkWeb_Response中获取header。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| name | header的名称。  | 
| value | 返回header的值。此函数将为value字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放该字符串。 | 


### OH_ArkWebResponse_GetMimeType()

```
void OH_ArkWebResponse_GetMimeType (const ArkWeb_Response * response, char ** mimeType )
```
**描述：**

获取ArkWeb_Response的媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| mimeType | 返回ArkWeb_Response的媒体类型。此函数将为mimeType字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放该字符串。 | 


### OH_ArkWebResponse_GetStatus()

```
int OH_ArkWebResponse_GetStatus (const ArkWeb_Response * response)
```
**描述：**

获取ArkWeb_Response的HTTP状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 

**返回：**

ArkWeb_Response的HTTP状态码。如果ArkWeb_Response无效，则为-1。


### OH_ArkWebResponse_GetStatusText()

```
void OH_ArkWebResponse_GetStatusText (const ArkWeb_Response * response, char ** statusText )
```
**描述：**

获取ArkWeb_Response的状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| statusText | 返回ArkWeb_Response的状态文本。此函数将为statusText字符串分配内存，调用方必须通过OH_ArkWeb_ReleaseString释放该字符串。 | 


### OH_ArkWebResponse_GetUrl()

```
void OH_ArkWebResponse_GetUrl (const ArkWeb_Response * response, char ** url )
```
**描述：**

获取经过重定向或由于HSTS而更改后的解析URL。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| url | 解析后的URL。 | 


### OH_ArkWebResponse_SetCharset()

```
int32_t OH_ArkWebResponse_SetCharset (ArkWeb_Response * response, const char * charset )
```
**描述：**

为ArkWeb_Response设置字符集。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| charset | 请求的字符集。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResponse_SetError()

```
int32_t OH_ArkWebResponse_SetError (ArkWeb_Response * response, ArkWeb_NetError errorCode )
```
**描述：**

给ArkWeb_Response对象设置一个错误码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| errorCode | 失败请求的错误码。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResponse_SetHeaderByName()

```
int32_t OH_ArkWebResponse_SetHeaderByName (ArkWeb_Response * response, const char * name, const char * value, bool overwrite )
```
**描述：**

为ArkWeb_Response设置一个header。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| name | header的名称。  | 
| value | header的值。  | 
| overwirte | 如果为true，将覆盖现有的header，否则不覆盖。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResponse_SetMimeType()

```
int32_t OH_ArkWebResponse_SetMimeType (ArkWeb_Response * response, const char * mimeType )
```
**描述：**

为ArkWeb_Response设置媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| mimeType | 请求的媒体类型。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResponse_SetStatus()

```
int32_t OH_ArkWebResponse_SetStatus (ArkWeb_Response * response, int status )
```
**描述：**

为ArkWeb_Response对象设置一个HTTP状态码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| status | 请求的HTTP状态码。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResponse_SetStatusText()

```
int32_t OH_ArkWebResponse_SetStatusText (ArkWeb_Response * response, const char * statusText )
```
**描述：**

为ArkWeb_Response设置状态文本。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| statusText | 请求的状态文本。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebResponse_SetUrl()

```
int32_t OH_ArkWebResponse_SetUrl (ArkWeb_Response * response, const char * url )
```
**描述：**

设置经过重定向或由于HSTS而改变后的解析URL，设置后会触发跳转。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | ArkWeb_Response。  | 
| url | 解析后的URL。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebSchemeHandler_GetUserData()

```
void* OH_ArkWebSchemeHandler_GetUserData (const ArkWeb_SchemeHandler * schemeHandler)
```
**描述：**

从ArkWeb_SchemeHandler获取用户数据。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler。  | 

**返回：**

设置的用户数据。


### OH_ArkWebSchemeHandler_SetOnRequestStart()

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStart (ArkWeb_SchemeHandler * schemeHandler, ArkWeb_OnRequestStart onRequestStart )
```
**描述：**

为SchemeHandler设置OnRequestStart回调。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| schemeHandler | 该scheme的SchemeHandler。  | 
| onRequestStart | OnRequestStart回调函数。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebSchemeHandler_SetOnRequestStop()

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStop (ArkWeb_SchemeHandler * schemeHandler, ArkWeb_OnRequestStop onRequestStop )
```
**描述：**

为SchemeHandler设置OnRequestStop回调。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| schemeHandler | 该scheme的SchemeHandler。  | 
| onRequestStop | OnRequestStop回调函数。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebSchemeHandler_SetUserData()

```
int32_t OH_ArkWebSchemeHandler_SetUserData (ArkWeb_SchemeHandler * schemeHandler, void * userData )
```
**描述：**

将一个用户数据设置到ArkWeb_SchemeHandler对象中。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler。  | 
| userData | 要设置的用户数据。  | 

**返回：**

如果返回0，表示成功；返回17100101，表示参数无效。


### OH_ArkWebServiceWorker_ClearSchemeHandlers()

```
int32_t OH_ArkWebServiceWorker_ClearSchemeHandlers ()
```
**描述：**

清除为ServiceWorker注册的SchemeHandler。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**返回：**

如果返回0，表示成功。


### OH_ArkWebServiceWorker_SetSchemeHandler()

```
bool OH_ArkWebServiceWorker_SetSchemeHandler (const char * scheme, ArkWeb_SchemeHandler * schemeHandler )
```
**描述：**

为指定scheme设置一个ArkWeb_SchemeHandler以拦截ServiceWorker触发的该scheme类型的请求。

应该在创建BrowserContext之后设置SchemeHandler。

可以使用WebviewController.initializeWebEngine来初始化BrowserContext而无需创建ArkWeb。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scheme | 需要被拦截的scheme。  | 
| schemeHandler | 该scheme的拦截器ArkWeb_SchemeHandler。只有通过ServiceWorker触发的请求才会通过这个schemeHandler进行通知。  | 

**返回：**

如果为指定scheme设置SchemeHandler成功，则返回true，否则返回false。


### OH_NativeArkWeb_GetDestroyCallback()

```
NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback (const char * webTag)
```
**描述：**

获取已注册的组件销毁时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 

**返回：**

return 已注册的组件销毁时的回调函数。


### OH_NativeArkWeb_GetJavaScriptProxyValidCallback()

```
NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback (const char * webTag)
```
**描述：**

获取已注册的对象可注册时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 

**返回：**

return 已注册的对象可注册时的回调函数。


### OH_NativeArkWeb_RegisterJavaScriptProxy()

```
void OH_NativeArkWeb_RegisterJavaScriptProxy (const char * webTag, const char * objName, const char ** methodList, NativeArkWeb_OnJavaScriptProxyCallback * callback, int32_t size, bool needRefresh )
```
**描述：**

注册对象及函数名称列表。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| objName | 注入对象的名称。  | 
| methodList | 注入函数列表的名称。  | 
| callback | 注入的回调函数。  | 
| size | 注入的回调函数的个数。  | 
| needRefresh | 是否需要刷新页面。 | 


### OH_NativeArkWeb_RunJavaScript()

```
void OH_NativeArkWeb_RunJavaScript (const char * webTag, const char * jsCode, NativeArkWeb_OnJavaScriptCallback callback )
```
**描述：**

在当前显示页面的环境下，加载并执行一段JavaScript代码。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| jsCode | 一段JavaScript的代码脚本。  | 
| callback | 代码执行完后通知开发者结果的回调函数。 | 


### OH_NativeArkWeb_SetDestroyCallback()

```
void OH_NativeArkWeb_SetDestroyCallback (const char * webTag, NativeArkWeb_OnDestroyCallback callback )
```
**描述：**

设置组件销毁时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| callback | 组件销毁时的回调函数。 | 


### OH_NativeArkWeb_SetJavaScriptProxyValidCallback()

```
void OH_NativeArkWeb_SetJavaScriptProxyValidCallback (const char * webTag, NativeArkWeb_OnValidCallback callback )
```
**描述：**

设置对象可注册时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| callback | 对象可注册时的回调函数。 | 


### OH_NativeArkWeb_UnregisterJavaScriptProxy()

```
void OH_NativeArkWeb_UnregisterJavaScriptProxy (const char * webTag, const char * objName )
```
**描述：**

删除已注册的对象及其下的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webTag | Web组件的名称。  | 
| objName | 注入对象的名称。 | 
