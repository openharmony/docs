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
| [ARKWEB_MEMBER_MISSING](#arkweb_member_missing)(s, f)&nbsp;&nbsp;&nbsp;(![ARKWEB_MEMBER_EXISTS](#arkweb_member_exists)(s, f) \|\| !((s)-&gt;f)) | 当前结构体存在该成员变量则返回false，否则返回true。  | 


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