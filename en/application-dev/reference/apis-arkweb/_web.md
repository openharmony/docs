# Web


## Overview

This module provides error codes for the exceptions of ArkWeb NDK APIs, 

APIs for injecting objects and executing JavaScript code, 

APIs for intercepting ArkWeb requests,

and error codes for the ArkWeb network protocol stack.

In addition, ArkWeb capabilities on the native side are also provided, such as refreshing web page, executing JavaScript, and registering callback.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [arkweb_error_code.h](arkweb__error__code_8h.md) | Declares the error codes of the ArkWeb NDK APIs. | 
| [arkweb_interface.h](arkweb__interface_8h.md) | Provides ArkWeb APIs for obtaining native APIs and the basic native API types. | 
| [arkweb_net_error_list.h](arkweb__net__error__list_8h.md) | Declares the error codes of the ArkWeb network protocol stack. | 
| [arkweb_scheme_handler.h](arkweb__scheme__handler_8h.md) | Declares the APIs used to intercept requests from ArkWeb. | 
| [arkweb_type.h](arkweb__type_8h.md) | Defines the common types of ArkWeb on the native side. | 
| [native_interface_arkweb.h](native__interface__arkweb_8h.md) | Declares APIs used to inject objects and execute JavaScript code. | 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) | Defines the basic native API types. | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) | Defines the basic structure of JavaScript Bridge data. | 
| struct&nbsp;&nbsp;[ArkWeb_JavaScriptObject](_ark_web___java_script_object.md) | Defines an injected JavaScript object. | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyMethod](_ark_web___proxy_method.md) | Defines an injected proxy method. | 
| struct&nbsp;&nbsp;[ArkWeb_ProxyObject](_ark_web___proxy_object.md) | Defines an injected proxy object. | 
| struct&nbsp;&nbsp;[ArkWeb_ControllerAPI](_ark_web___controller_a_p_i.md) | Defines a native API struct of the **Web** controller. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM. | 
| struct&nbsp;&nbsp;[ArkWeb_ComponentAPI](_ark_web___component_a_p_i.md) | Defines a native API struct of the **Web** component. | 
| struct&nbsp;&nbsp;[ArkWeb_WebMessagePortAPI](_ark_web___web_message_port_a_p_i.md) | Defines a native API struct of the post message. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM. | 
| struct&nbsp;&nbsp;[ArkWeb_WebMessageAPI](_ark_web___web_message_a_p_i.md) | Defines a native API struct of the post message data. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM. | 
| struct&nbsp;&nbsp;[ArkWeb_CookieManagerAPI](_ark_web___cookie_manager_a_p_i.md) | Defines a native **CookieManager** API of ArkWeb. Before calling an API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM. | 


### Macros

| Name| Description| 
| -------- | -------- |
| [ARKWEB_MEMBER_EXISTS](#arkweb_member_exists)(s, f)&nbsp;&nbsp;&nbsp;&nbsp;((intptr_t) &amp; ((s)-&gt;f) - (intptr_t)(s) + sizeof((s)-&gt;f) &lt;= \*reinterpret_cast&lt;size_t\*&gt;(s)) | Checks whether the member variable exists in the struct. | 
| [ARKWEB_MEMBER_MISSING](#arkweb_member_missing)(s, f)&nbsp;&nbsp;&nbsp;(\![ARKWEB_MEMBER_EXISTS](#arkweb_member_exists)(s, f) \|\| !((s)-&gt;f)) | If the member variable exists in the struct, **false** is returned. Otherwise, **true** is returned. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [ArkWeb_ErrorCode](#arkweb_errorcode) [ArkWeb_ErrorCode](#arkweb_errorcode) | Defines an enum for the error codes of ArkWeb NDK APIs. | 
| typedef enum [ArkWeb_NetError](#arkweb_neterror) [ArkWeb_NetError](#arkweb_neterror) | Defines an enum for the error codes of the ArkWeb network protocol stack. | 
| typedef enum [ArkWeb_CustomSchemeOption](#arkweb_customschemeoption) [ArkWeb_CustomSchemeOption](#arkweb_customschemeoption) | Defines an enum for the custom scheme options. | 
| typedef enum [ArkWeb_ResourceType](#arkweb_resourcetype) [ArkWeb_ResourceType](#arkweb_resourcetype) | Defines an enum for the resource types. | 
| typedef struct ArkWeb_SchemeHandler_ [ArkWeb_SchemeHandler](#arkweb_schemehandler) | Defines a struct for the **SchemeHandler** of a specified scheme. | 
| typedef struct ArkWeb_ResourceHandler_ [ArkWeb_ResourceHandler](#arkweb_resourcehandler) | Defines a struct for the intercepted URL requests. | 
| typedef struct ArkWeb_Response_ [ArkWeb_Response](#arkweb_response) | Defines a struct for **ArkWeb_Response** for the intercepted request. | 
| typedef struct ArkWeb_ResourceRequest_ [ArkWeb_ResourceRequest](#arkweb_resourcerequest) | Defines a struct for resource request. Through **OH_ArkWeb_ResourceRequest**, you can obtain the URL, method, post data, and other information of the request. | 
| typedef struct ArkWeb_RequestHeaderList_ [ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) | Defines a struct for the request header list. | 
| typedef struct ArkWeb_HttpBodyStream_ [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) | Defines a struct for the uploaded data of the request. | 
| typedef void(\* [ArkWeb_OnRequestStart](#arkweb_onrequeststart)) (const [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler, bool \*intercept) | Defines a callback used to start the request on the I/O thread. | 
| typedef void(\* [ArkWeb_OnRequestStop](#arkweb_onrequeststop)) (const [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | Defines a callback used when the request is stopped. | 
| typedef void(\* [ArkWeb_HttpBodyStreamReadCallback](#arkweb_httpbodystreamreadcallback)) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, uint8_t \*buffer, int bytesRead) | Defines a callback used when **OH_ArkWebHttpBodyStream_Read** is complete. | 
| typedef void(\* [ArkWeb_HttpBodyStreamInitCallback](#arkweb_httpbodystreaminitcallback)) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_NetError](#arkweb_neterror) result) | Defines a callback used when **ArkWeb_HttpBodyStream** is initialized. | 
| typedef enum [ArkWeb_WebMessageType](#arkweb_webmessagetype) [ArkWeb_WebMessageType](#arkweb_webmessagetype) | Defines an enum for the data types of post message. | 
| typedef struct ArkWeb_WebMessage \* [ArkWeb_WebMessagePtr](#arkweb_webmessageptr) | Defines a struct for the pointer to the data struct of post message. | 
| typedef void(\* [ArkWeb_OnJavaScriptCallback](#arkweb_onjavascriptcallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*data, void \*userData) | Defines a callback used when the injected JavaScript is executed. | 
| typedef void(\* [ArkWeb_OnJavaScriptProxyCallback](#arkweb_onjavascriptproxycallback)) (const char \*webTag, const [ArkWeb_JavaScriptBridgeData](_ark_web___java_script_bridge_data.md) \*dataArray, size_t arraySize, void \*userData) | Defines a callback used when the proxy method is executed. | 
| typedef void(\* [ArkWeb_OnComponentCallback](#arkweb_oncomponentcallback)) (const char \*webTag, void \*userData) | Defines a callback used to return component event notification. | 
| typedef struct ArkWeb_WebMessagePort \* [ArkWeb_WebMessagePortPtr](#arkweb_webmessageportptr) | Defines a struct for the pointer to the message port struct. | 
| typedef void(\* [ArkWeb_OnMessageEventHandler](#arkweb_onmessageeventhandler)) (const char \*webTag, const [ArkWeb_WebMessagePortPtr](#arkweb_webmessageportptr) port, const [ArkWeb_WebMessagePtr](#arkweb_webmessageptr) message, void \*userData) | Defines a callback used to process the post message data sent by the HTML page. | 
| typedef void(\* [NativeArkWeb_OnJavaScriptCallback](#nativearkweb_onjavascriptcallback)) (const char \*) | Defines a callback used to return the result after the JavaScript code is executed. | 
| typedef char \*(\* [NativeArkWeb_OnJavaScriptProxyCallback](#nativearkweb_onjavascriptproxycallback)) (const char \*\*argv, int32_t argc) | Defines a callback of the injected object. | 
| typedef void(\* [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback)) (const char \*) | Defines a callback used when the **Web** component is valid. | 
| typedef void(\* [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback)) (const char \*) | Defines a callback used when the **Web** component is destroyed. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [ArkWeb_ErrorCode](#arkweb_errorcode) {<br>ARKWEB_SUCCESS = 0, ARKWEB_INIT_ERROR = 17100001, ARKWEB_ERROR_UNKNOWN = 17100100, ARKWEB_INVALID_PARAM = 17100101,<br>ARKWEB_SCHEME_REGISTER_FAILED = 17100102, ARKWEB_INVALID_URL = 17100103, ARKWEB_INVALID_COOKIE_VALUE = 17100104<br>} | Enumerates the error codes of ArkWeb NDK APIs. | 
| [ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) {<br>ARKWEB_NATIVE_COMPONENT, ARKWEB_NATIVE_CONTROLLER, ARKWEB_NATIVE_WEB_MESSAGE_PORT, ARKWEB_NATIVE_WEB_MESSAGE,<br>ARKWEB_NATIVE_COOKIE_MANAGER<br>} | Enumerates the native API types. | 
| [ArkWeb_NetError](#arkweb_neterror) {<br>ARKWEB_NET_OK = 0, ARKWEB_ERR_IO_PENDING = -1, ARKWEB_ERR_FAILED = -2, ARKWEB_ERR_ABORTED = -3,<br>ARKWEB_ERR_INVALID_ARGUMENT = -4, ARKWEB_ERR_INVALID_HANDLE = -5, ARKWEB_ERR_FILE_NOT_FOUND = -6, ARKWEB_ERR_TIMED_OUT = -7,<br>ARKWEB_ERR_FILE_TOO_LARGE = -8, ARKWEB_ERR_UNEXPECTED = -9, ARKWEB_ERR_ACCESS_DENIED = -10, ARKWEB_ERR_NOT_IMPLEMENTED = -11,<br>ARKWEB_ERR_INSUFFICIENT_RESOURCES = -12, ARKWEB_ERR_OUT_OF_MEMORY = -13, ARKWEB_ERR_UPLOAD_FILE_CHANGED = -14, ARKWEB_ERR_SOCKET_NOT_CONNECTED = -15,<br>ARKWEB_ERR_FILE_EXISTS = -16, ARKWEB_ERR_FILE_PATH_TOO_LONG = -17, ARKWEB_ERR_FILE_NO_SPACE = -18, ARKWEB_ERR_FILE_VIRUS_INFECTED = -19,<br>ARKWEB_ERR_BLOCKED_BY_CLIENT = -20, ARKWEB_ERR_NETWORK_CHANGED = -21, ARKWEB_ERR_BLOCKED_BY_ADMINISTRATOR = -22, ARKWEB_ERR_SOCKET_CONNECTED = -23,<br>ARKWEB_ERR_UPLOAD_STREAM_REWIND_NOT_SUPPORTED = -25, ARKWEB_ERR_CONTEXT_SHUT_DOWN = -26, ARKWEB_ERR_BLOCKED_BY_RESPONSE = -27, ARKWEB_ERR_CLEARTEXT_NOT_PERMITTED = -29,<br>ARKWEB_ERR_BLOCKED_BY_CSP = -30, ARKWEB_ERR_H2_OR_QUIC_REQUIRED = -31, ARKWEB_ERR_BLOCKED_BY_ORB = -32, ARKWEB_ERR_CONNECTION_CLOSED = -100,<br>ARKWEB_ERR_CONNECTION_RESET = -101, ARKWEB_ERR_CONNECTION_REFUSED = -102, ARKWEB_ERR_CONNECTION_ABORTED = -103, ARKWEB_ERR_CONNECTION_FAILED = -104,<br>ARKWEB_ERR_NAME_NOT_RESOLVED = -105, ARKWEB_ERR_INTERNET_DISCONNECTED = -106, ARKWEB_ERR_SSL_PROTOCOL_ERROR = -107, ARKWEB_ERR_ADDRESS_INVALID = -108,<br>ARKWEB_ERR_ADDRESS_UNREACHABLE = -109, ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NEEDED = -110, ARKWEB_ERR_TUNNEL_CONNECTION_FAILED = -111, ARKWEB_ERR_NO_SSL_VERSIONS_ENABLED = -112,<br>ARKWEB_ERR_SSL_VERSION_OR_CIPHER_MISMATCH = -113, ARKWEB_ERR_SSL_RENEGOTIATION_REQUESTED = -114, ARKWEB_ERR_PROXY_AUTH_UNSUPPORTED = -115, ARKWEB_ERR_BAD_SSL_CLIENT_AUTH_CERT = -117,<br>ARKWEB_ERR_CONNECTION_TIMED_OUT = -118, ARKWEB_ERR_HOST_RESOLVER_QUEUE_TOO_LARGE = -119, ARKWEB_ERR_SOCKS_CONNECTION_FAILED = -120, ARKWEB_ERR_SOCKS_CONNECTION_HOST_UNREACHABLE = -121,<br>ARKWEB_ERR_ALPN_NEGOTIATION_FAILED = -122, ARKWEB_ERR_SSL_NO_RENEGOTIATION = -123, ARKWEB_ERR_WINSOCK_UNEXPECTED_WRITTEN_BYTES = -124, ARKWEB_ERR_SSL_DECOMPRESSION_FAILURE_ALERT = -125,<br>ARKWEB_ERR_SSL_BAD_RECORD_MAC_ALERT = -126, ARKWEB_ERR_PROXY_AUTH_REQUESTED = -127, ARKWEB_ERR_PROXY_CONNECTION_FAILED = -130, ARKWEB_ERR_MANDATORY_PROXY_CONFIGURATION_FAILED = -131,<br>ARKWEB_ERR_PRECONNECT_MAX_SOCKET_LIMIT = -133, ARKWEB_ERR_SSL_CLIENT_AUTH_PRIVATE_KEY_ACCESS_DENIED = -134, ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NO_PRIVATE_KEY = -135, ARKWEB_ERR_PROXY_CERTIFICATE_INVALID = -136,<br>ARKWEB_ERR_NAME_RESOLUTION_FAILED = -137, ARKWEB_ERR_NETWORK_ACCESS_DENIED = -138, ARKWEB_ERR_TEMPORARILY_THROTTLED = -139, ARKWEB_ERR_HTTPS_PROXY_TUNNEL_RESPONSE_REDIRECT = -140,<br>ARKWEB_ERR_SSL_CLIENT_AUTH_SIGNATURE_FAILED = -141, ARKWEB_ERR_MSG_TOO_BIG = -142, ARKWEB_ERR_WS_PROTOCOL_ERROR = -145, ARKWEB_ERR_ADDRESS_IN_USE = -147,<br>ARKWEB_ERR_SSL_HANDSHAKE_NOT_COMPLETED = -148, ARKWEB_ERR_SSL_BAD_PEER_PUBLIC_KEY = -149, ARKWEB_ERR_SSL_PINNED_KEY_NOT_IN_CERT_CHAIN = -150, ARKWEB_ERR_CLIENT_AUTH_CERT_TYPE_UNSUPPORTED = -151,<br>ARKWEB_ERR_SSL_DECRYPT_ERROR_ALERT = -153, ARKWEB_ERR_WS_THROTTLE_QUEUE_TOO_LARGE = -154, ARKWEB_ERR_SSL_SERVER_CERT_CHANGED = -156, ARKWEB_ERR_SSL_UNRECOGNIZED_NAME_ALERT = -159,<br>ARKWEB_ERR_SOCKET_SET_RECEIVE_BUFFER_SIZE_ERROR = -160, ARKWEB_ERR_SOCKET_SET_SEND_BUFFER_SIZE_ERROR = -161, ARKWEB_ERR_SOCKET_RECEIVE_BUFFER_SIZE_UNCHANGEABLE = -162, ARKWEB_ERR_SOCKET_SEND_BUFFER_SIZE_UNCHANGEABLE = -163,<br>ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_BAD_FORMAT = -164, ARKWEB_ERR_ICANN_NAME_COLLISION = -166, ARKWEB_ERR_SSL_SERVER_CERT_BAD_FORMAT = -167, ARKWEB_ERR_CT_STH_PARSING_FAILED = -168,<br>ARKWEB_ERR_CT_STH_INCOMPLETE = -169, ARKWEB_ERR_UNABLE_TO_REUSE_CONNECTION_FOR_PROXY_AUTH = -170, ARKWEB_ERR_CT_CONSISTENCY_PROOF_PARSING_FAILED = -171, ARKWEB_ERR_SSL_OBSOLETE_CIPHER = -172,<br>ARKWEB_ERR_WS_UPGRADE = -173, ARKWEB_ERR_READ_IF_READY_NOT_IMPLEMENTED = -174, ARKWEB_ERR_NO_BUFFER_SPACE = -176, ARKWEB_ERR_SSL_CLIENT_AUTH_NO_COMMON_ALGORITHMS = -177,<br>ARKWEB_ERR_EARLY_DATA_REJECTED = -178, ARKWEB_ERR_WRONG_VERSION_ON_EARLY_DATA = -179, ARKWEB_ERR_TLS13_DOWNGRADE_DETECTED = -180, ARKWEB_ERR_SSL_KEY_USAGE_INCOMPATIBLE = -181,<br>ARKWEB_ERR_INVALID_ECH_CONFIG_LIST = -182, ARKWEB_ERR_ECH_NOT_NEGOTIATED = -183, ARKWEB_ERR_ECH_FALLBACK_CERTIFICATE_INVALID = -184, ARKWEB_ERR_CERT_COMMON_NAME_INVALID = -200,<br>ARKWEB_ERR_CERT_DATE_INVALID = -201, ARKWEB_ERR_CERT_AUTHORITY_INVALID = -202, ARKWEB_ERR_CERT_CONTAINS_ERRORS = -203, ARKWEB_ERR_CERT_NO_REVOCATION_MECHANISM = -204,<br>ARKWEB_ERR_CERT_UNABLE_TO_CHECK_REVOCATION = -205, ARKWEB_ERR_CERT_REVOKED = -206, ARKWEB_ERR_CERT_INVALID = -207, ARKWEB_ERR_CERT_WEAK_SIGNATURE_ALGORITHM = -208,<br>ARKWEB_ERR_CERT_NON_UNIQUE_NAME = -210, ARKWEB_ERR_CERT_WEAK_KEY = -211, ARKWEB_ERR_CERT_NAME_CONSTRAINT_VIOLATION = -212, ARKWEB_ERR_CERT_VALIDITY_TOO_LONG = -213,<br>ARKWEB_ERR_CERTIFICATE_TRANSPARENCY_REQUIRED = -214, ARKWEB_ERR_CERT_SYMANTEC_LEGACY = -215, ARKWEB_ERR_CERT_KNOWN_INTERCEPTION_BLOCKED = -217, ARKWEB_ERR_SSL_OBSOLETE_VERSION_OR_CIPHER = -218,<br>ARKWEB_ERR_CERT_END = -219, ARKWEB_ERR_INVALID_URL = -300, ARKWEB_ERR_DISALLOWED_URL_SCHEME = -301, ARKWEB_ERR_UNKNOWN_URL_SCHEME = -302,<br>ARKWEB_ERR_INVALID_REDIRECT = -303, ARKWEB_ERR_TOO_MANY_REDIRECTS = -310, ARKWEB_ERR_UNSAFE_REDIRECT = -311, ARKWEB_ERR_UNSAFE_PORT = -312,<br>ARKWEB_ERR_INVALID_RESPONSE = -320, ARKWEB_ERR_INVALID_CHUNKED_ENCODING = -321, ARKWEB_ERR_METHOD_UNSUPPORTED = -322, ARKWEB_ERR_UNEXPECTED_PROXY_AUTH = -323,<br>ARKWEB_ERR_EMPTY_RESPONSE = -324, ARKWEB_ERR_RESPONSE_HEADERS_TOO_BIG = -325, ARKWEB_ERR_PAC_SCRIPT_FAILED = -327, ARKWEB_ERR_REQUEST_RANGE_NOT_SATISFIABLE = -328,<br>ARKWEB_ERR_MALFORMED_IDENTITY = -329, ARKWEB_ERR_CONTENT_DECODING_FAILED = -330, ARKWEB_ERR_NETWORK_IO_SUSPENDED = -331, ARKWEB_ERR_SYN_REPLY_NOT_RECEIVED = -332,<br>ARKWEB_ERR_ENCODING_CONVERSION_FAILED = -333, ARKWEB_ERR_UNRECOGNIZED_FTP_DIRECTORY_LISTING_FORMAT = -334, ARKWEB_ERR_NO_SUPPORTED_PROXIES = -336, ARKWEB_ERR_HTTP2_PROTOCOL_ERROR = -337,<br>ARKWEB_ERR_INVALID_AUTH_CREDENTIALS = -338, ARKWEB_ERR_UNSUPPORTED_AUTH_SCHEME = -339, ARKWEB_ERR_ENCODING_DETECTION_FAILED = -340, ARKWEB_ERR_MISSING_AUTH_CREDENTIALS = -341,<br>ARKWEB_ERR_UNEXPECTED_SECURITY_LIBRARY_STATUS = -342, ARKWEB_ERR_MISCONFIGURED_AUTH_ENVIRONMENT = -343, ARKWEB_ERR_UNDOCUMENTED_SECURITY_LIBRARY_STATUS = -344, ARKWEB_ERR_RESPONSE_BODY_TOO_BIG_TO_DRAIN = -345,<br>ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_LENGTH = -346, ARKWEB_ERR_INCOMPLETE_HTTP2_HEADERS = -347, ARKWEB_ERR_PAC_NOT_IN_DHCP = -348, ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_DISPOSITION = -349,<br>ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_LOCATION = -350, ARKWEB_ERR_HTTP2_SERVER_REFUSED_STREAM = -351, ARKWEB_ERR_HTTP2_PING_FAILED = -352, ARKWEB_ERR_CONTENT_LENGTH_MISMATCH = -354,<br>ARKWEB_ERR_INCOMPLETE_CHUNKED_ENCODING = -355, ARKWEB_ERR_QUIC_PROTOCOL_ERROR = -356, ARKWEB_ERR_RESPONSE_HEADERS_TRUNCATED = -357, ARKWEB_ERR_QUIC_HANDSHAKE_FAILED = -358,<br>ARKWEB_ERR_HTTP2_INADEQUATE_TRANSPORT_SECURITY = -360, ARKWEB_ERR_HTTP2_FLOW_CONTROL_ERROR = -361, ARKWEB_ERR_HTTP2_FRAME_SIZE_ERROR = -362, ARKWEB_ERR_HTTP2_COMPRESSION_ERROR = -363,<br>ARKWEB_ERR_PROXY_AUTH_REQUESTED_WITH_NO_CONNECTION = -364, ARKWEB_ERR_HTTP_1_1_REQUIRED = -365, ARKWEB_ERR_PROXY_HTTP_1_1_REQUIRED = -366, ARKWEB_ERR_PAC_SCRIPT_TERMINATED = -367,<br>ARKWEB_ERR_INVALID_HTTP_RESPONSE = -370, ARKWEB_ERR_CONTENT_DECODING_INIT_FAILED = -371, ARKWEB_ERR_HTTP2_RST_STREAM_NO_ERROR_RECEIVED = -372, ARKWEB_ERR_HTTP2_PUSHED_STREAM_NOT_AVAILABLE = -373,<br>ARKWEB_ERR_HTTP2_CLAIMED_PUSHED_STREAM_RESET_BY_SERVER = -374, ARKWEB_ERR_TOO_MANY_RETRIES = -375, ARKWEB_ERR_HTTP2_STREAM_CLOSED = -376, ARKWEB_ERR_HTTP2_CLIENT_REFUSED_STREAM = -377,<br>ARKWEB_ERR_HTTP2_PUSHED_RESPONSE_DOES_NOT_MATCH = -378, ARKWEB_ERR_HTTP_RESPONSE_CODE_FAILURE = -379, ARKWEB_ERR_QUIC_UNKNOWN_CERT_ROOT = -380, ARKWEB_ERR_QUIC_GOAWAY_REQUEST_CAN_BE_RETRIED = -381,<br>ARKWEB_ERR_TOO_MANY_ACCEPT_CH_RESTARTS = -382, ARKWEB_ERR_INCONSISTENT_IP_ADDRESS_SPACE = -383, ARKWEB_ERR_CACHED_IP_ADDRESS_SPACE_BLOCKED_BY_LOCAL_NETWORK_ACCESS_POLICY = -384, ARKWEB_ERR_CACHE_MISS = -400,<br>ARKWEB_ERR_CACHE_READ_FAILURE = -401, ARKWEB_ERR_CACHE_WRITE_FAILURE = -402, ARKWEB_ERR_CACHE_OPERATION_UNSUPPORTED = -403, ARKWEB_ERR_CACHE_OPEN_FAILURE = -404,<br>ARKWEB_ERR_CACHE_CREATE_FAILURE = -405, ARKWEB_ERR_CACHE_RACE = -406, ARKWEB_ERR_CACHE_CHECKSUM_READ_FAILURE = -407, ARKWEB_ERR_CACHE_CHECKSUM_MISMATCH = -408,<br>ARKWEB_ERR_CACHE_LOCK_TIMEOUT = -409, ARKWEB_ERR_CACHE_AUTH_FAILURE_AFTER_READ = -410, ARKWEB_ERR_CACHE_ENTRY_NOT_SUITABLE = -411, ARKWEB_ERR_CACHE_DOOM_FAILURE = -412,<br>ARKWEB_ERR_CACHE_OPEN_OR_CREATE_FAILURE = -413, ARKWEB_ERR_INSECURE_RESPONSE = -501, ARKWEB_ERR_NO_PRIVATE_KEY_FOR_CERT = -502, ARKWEB_ERR_ADD_USER_CERT_FAILED = -503,<br>ARKWEB_ERR_INVALID_SIGNED_EXCHANGE = -504, ARKWEB_ERR_INVALID_WEB_BUNDLE = -505, ARKWEB_ERR_TRUST_TOKEN_OPERATION_FAILED = -506, ARKWEB_ERR_TRUST_TOKEN_OPERATION_SUCCESS_WITHOUT_SENDING_REQUEST = -507,<br>ARKWEB_ERR_FTP_FAILED = -601, ARKWEB_ERR_FTP_SERVICE_UNAVAILABLE = -602, ARKWEB_ERR_FTP_TRANSFER_ABORTED = -603, ARKWEB_ERR_FTP_FILE_BUSY = -604,<br>ARKWEB_ERR_FTP_SYNTAX_ERROR = -605, ARKWEB_ERR_FTP_COMMAND_UNSUPPORTED = -606, ARKWEB_ERR_FTP_BAD_COMMAND_SEQUENCE = -607, ARKWEB_ERR_PKCS12_IMPORT_BAD_PASSWORD = -701,<br>ARKWEB_ERR_PKCS12_IMPORT_FAILED = -702, ARKWEB_ERR_IMPORT_CA_CERT_NOT_CA = -703, ARKWEB_ERR_IMPORT_CERT_ALREADY_EXISTS = -704, ARKWEB_ERR_IMPORT_CA_CERT_FAILED = -705,<br>ARKWEB_ERR_IMPORT_SERVER_CERT_FAILED = -706, ARKWEB_ERR_PKCS12_IMPORT_INVALID_MAC = -707, ARKWEB_ERR_PKCS12_IMPORT_INVALID_FILE = -708, ARKWEB_ERR_PKCS12_IMPORT_UNSUPPORTED = -709,<br>ARKWEB_ERR_KEY_GENERATION_FAILED = -710, ARKWEB_ERR_PRIVATE_KEY_EXPORT_FAILED = -712, ARKWEB_ERR_SELF_SIGNED_CERT_GENERATION_FAILED = -713, ARKWEB_ERR_CERT_DATABASE_CHANGED = -714,<br>ARKWEB_ERR_CERT_VERIFIER_CHANGED = -716, ARKWEB_ERR_DNS_MALFORMED_RESPONSE = -800, ARKWEB_ERR_DNS_SERVER_REQUIRES_TCP = -801, ARKWEB_ERR_DNS_SERVER_FAILED = -802,<br>ARKWEB_ERR_DNS_TIMED_OUT = -803, ARKWEB_ERR_DNS_CACHE_MISS = -804, ARKWEB_ERR_DNS_SEARCH_EMPTY = -805, ARKWEB_ERR_DNS_SORT_ERROR = -806,<br>ARKWEB_ERR_DNS_SECURE_RESOLVER_HOSTNAME_RESOLUTION_FAILED = -808, ARKWEB_ERR_DNS_NAME_HTTPS_ONLY = -809, ARKWEB_ERR_DNS_REQUEST_CANCELED = -810, ARKWEB_ERR_DNS_NO_MATCHING_SUPPORTED_ALPN = -811<br>} | Enumerates the error codes of the ArkWeb network protocol stack. | 
| [ArkWeb_CustomSchemeOption](#arkweb_customschemeoption) {<br>**OH_ARKWEB_SCHEME_OPTION_NONE** = 0, ARKWEB_SCHEME_OPTION_STANDARD = 1 &lt;&lt; 0, ARKWEB_SCHEME_OPTION_LOCAL = 1 &lt;&lt; 1, ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED = 1 &lt;&lt; 2,<br>ARKWEB_SCHEME_OPTION_SECURE = 1 &lt;&lt; 3, ARKWEB_SCHEME_OPTION_CORS_ENABLED = 1 &lt;&lt; 4, ARKWEB_SCHEME_OPTION_CSP_BYPASSING = 1 &lt;&lt; 5, ARKWEB_SCHEME_OPTION_FETCH_ENABLED = 1 &lt;&lt; 6,<br>ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED = 1 &lt;&lt; 7<br>} | Enumerates the custom scheme options. | 
| [ArkWeb_ResourceType](#arkweb_resourcetype) {<br>MAIN_FRAME = 0, SUB_FRAME = 1, STYLE_SHEET = 2, SCRIPT = 3,<br>IMAGE = 4, FONT_RESOURCE = 5, SUB_RESOURCE = 6, OBJECT = 7,<br>MEDIA = 8, WORKER = 9, SHARED_WORKER = 10, PREFETCH = 11,<br>FAVICON = 12, XHR = 13, PING = 14, SERVICE_WORKER = 15,<br>CSP_REPORT = 16, PLUGIN_RESOURCE = 17, NAVIGATION_PRELOAD_MAIN_FRAME = 19, NAVIGATION_PRELOAD_SUB_FRAME = 20<br>} | Enumerates the resource types. | 
| [ArkWeb_WebMessageType](#arkweb_webmessagetype) { ARKWEB_NONE = 0, ARKWEB_STRING, ARKWEB_BUFFER } | Enumerates the data types of post message. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [ArkWeb_AnyNativeAPI](_ark_web___any_native_a_p_i.md) \* [OH_ArkWeb_GetNativeAPI](#oh_arkweb_getnativeapi) ([ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) type) | Obtains the native API struct based on the transferred API type. | 
| void [OH_ArkWebRequestHeaderList_Destroy](#oh_arkwebrequestheaderlist_destroy) ([ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) \*requestHeaderList) | Destroys an **ArkWeb_RequestHeaderList** object. | 
| int32_t [OH_ArkWebRequestHeaderList_GetSize](#oh_arkwebrequestheaderlist_getsize) (const [ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) \*requestHeaderList) | Obtains the size of a request header list. | 
| void [OH_ArkWebRequestHeaderList_GetHeader](#oh_arkwebrequestheaderlist_getheader) (const [ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) \*requestHeaderList, int32_t index, char \*\*key, char \*\*value) | Obtains a specified request header. | 
| int32_t [OH_ArkWebResourceRequest_SetUserData](#oh_arkwebresourcerequest_setuserdata) ([ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, void \*userData) | Sets user data to the **ArkWeb_ResourceRequest** object. | 
| void \* [OH_ArkWebResourceRequest_GetUserData](#oh_arkwebresourcerequest_getuserdata) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | Obtains user data from **ArkWeb_ResourceRequest**. | 
| void [OH_ArkWebResourceRequest_GetMethod](#oh_arkwebresourcerequest_getmethod) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, char \*\*method) | Obtains the method of a request. | 
| void [OH_ArkWebResourceRequest_GetUrl](#oh_arkwebresourcerequest_geturl) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, char \*\*url) | Obtains the URL of a request. | 
| void [OH_ArkWebResourceRequest_GetHttpBodyStream](#oh_arkwebresourcerequest_gethttpbodystream) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*\*httpBodyStream) | Creates an **ArkWeb_HttpBodyStream** to read the uploaded data of the request. | 
| void [OH_ArkWebResourceRequest_DestroyHttpBodyStream](#oh_arkwebresourcerequest_destroyhttpbodystream) ([ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | Destroys an **ArkWeb_HttpBodyStream** object. | 
| int32_t [OH_ArkWebResourceRequest_GetResourceType](#oh_arkwebresourcerequest_getresourcetype) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | Obtains the resource type of a request. | 
| void [OH_ArkWebResourceRequest_GetFrameUrl](#oh_arkwebresourcerequest_getframeurl) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, char \*\*frameUrl) | Obtains the URL of the frame that triggers the request. | 
| int32_t [OH_ArkWebHttpBodyStream_SetUserData](#oh_arkwebhttpbodystream_setuserdata) ([ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, void \*userData) | Sets user data to the **ArkWeb_HttpBodyStream** object. | 
| void \* [OH_ArkWebHttpBodyStream_GetUserData](#oh_arkwebhttpbodystream_getuserdata) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | Obtains user data from **ArkWeb_HttpBodyStream**. | 
| int32_t [OH_ArkWebHttpBodyStream_SetReadCallback](#oh_arkwebhttpbodystream_setreadcallback) ([ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_HttpBodyStreamReadCallback](#arkweb_httpbodystreamreadcallback) readCallback) | Sets a callback for **OH_ArkWebHttpBodyStream_Read**. | 
| int32_t [OH_ArkWebHttpBodyStream_Init](#oh_arkwebhttpbodystream_init) ([ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, [ArkWeb_HttpBodyStreamInitCallback](#arkweb_httpbodystreaminitcallback) initCallback) | Initializes **ArkWeb_HttpBodyStream**. | 
| void [OH_ArkWebHttpBodyStream_Read](#oh_arkwebhttpbodystream_read) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream, uint8_t \*buffer, int bufLen) | Exports upload data of the request to the buffer. | 
| uint64_t [OH_ArkWebHttpBodyStream_GetSize](#oh_arkwebhttpbodystream_getsize) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | Obtains the size of **httpBodyStream**. | 
| uint64_t [OH_ArkWebHttpBodyStream_GetPosition](#oh_arkwebhttpbodystream_getposition) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | Obtains the position of **httpBodyStream**. | 
| bool [OH_ArkWebHttpBodyStream_IsChunked](#oh_arkwebhttpbodystream_ischunked) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | Determines whether **httpBodyStream** is chunked to transfer. | 
| bool [OH_ArkWebHttpBodyStream_IsEof](#oh_arkwebhttpbodystream_iseof) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | Returns **true** if all data in **httpBodyStream** is read. | 
| bool [OH_ArkWebHttpBodyStream_IsInMemory](#oh_arkwebhttpbodystream_isinmemory) (const [ArkWeb_HttpBodyStream](#arkweb_httpbodystream) \*httpBodyStream) | Returns **true** if all the uploaded data in **httpBodyStream** is in memory and all read requests will be synchronized successfully. | 
| int32_t [OH_ArkWebResourceRequest_Destroy](#oh_arkwebresourcerequest_destroy) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | Destroys an **ArkWeb_ResourceRequest** object. | 
| void [OH_ArkWebResourceRequest_GetReferrer](#oh_arkwebresourcerequest_getreferrer) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, char \*\*referrer) | Obtains the **Referrer** of a request. | 
| void [OH_ArkWebResourceRequest_GetRequestHeaders](#oh_arkwebresourcerequest_getrequestheaders) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest, [ArkWeb_RequestHeaderList](#arkweb_requestheaderlist) \*\*requestHeaderList) | Obtains the **OH_ArkWeb_RequestHeaderList** of a request. | 
| bool [OH_ArkWebResourceRequest_IsRedirect](#oh_arkwebresourcerequest_isredirect) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | Determines whether a request is redirect. | 
| bool [OH_ArkWebResourceRequest_IsMainFrame](#oh_arkwebresourcerequest_ismainframe) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | Determines whether a request is from the main frame. | 
| bool [OH_ArkWebResourceRequest_HasGesture](#oh_arkwebresourcerequest_hasgesture) (const [ArkWeb_ResourceRequest](#arkweb_resourcerequest) \*resourceRequest) | Determines whether a request is triggered by the user gesture. | 
| int32_t [OH_ArkWeb_RegisterCustomSchemes](#oh_arkweb_registercustomschemes) (const char \*scheme, int32_t option) | Registers a custom scheme with the **ArkWeb**. | 
| bool [OH_ArkWebServiceWorker_SetSchemeHandler](#oh_arkwebserviceworker_setschemehandler) (const char \*scheme, [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler) | Sets an **ArkWeb_SchemeHandler** for a specified scheme to intercept requests of this scheme triggered by **ServiceWorker**. | 
| bool [OH_ArkWeb_SetSchemeHandler](#oh_arkweb_setschemehandler) (const char \*scheme, const char \*webTag, [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler) | Sets an **ArkWeb_SchemeHandler** for a specified scheme to intercept requests of this scheme. | 
| int32_t [OH_ArkWebServiceWorker_ClearSchemeHandlers](#oh_arkwebserviceworker_clearschemehandlers) () | Clears the **SchemeHandler** registered for **ServiceWorker**. | 
| int32_t [OH_ArkWeb_ClearSchemeHandlers](#oh_arkweb_clearschemehandlers) (const char \*webTag) | Clears the **SchemeHandler** registered for the specified web. | 
| void [OH_ArkWeb_CreateSchemeHandler](#oh_arkweb_createschemehandler) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*\*schemeHandler) | Creates an **ArkWeb_SchemeHandler** object. | 
| void [OH_ArkWeb_DestroySchemeHandler](#oh_arkweb_destroyschemehandler) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler) | Destroys an **ArkWeb_SchemeHandler** object. | 
| int32_t [OH_ArkWebSchemeHandler_SetUserData](#oh_arkwebschemehandler_setuserdata) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, void \*userData) | Sets a user data to the **ArkWeb_SchemeHandler** object. | 
| void \* [OH_ArkWebSchemeHandler_GetUserData](#oh_arkwebschemehandler_getuserdata) (const [ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler) | Obtains the user data from **ArkWeb_SchemeHandler**. | 
| int32_t [OH_ArkWebSchemeHandler_SetOnRequestStart](#oh_arkwebschemehandler_setonrequeststart) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, [ArkWeb_OnRequestStart](#arkweb_onrequeststart) onRequestStart) | Sets an **OnRequestStart** callback for **SchemeHandler**. | 
| int32_t [OH_ArkWebSchemeHandler_SetOnRequestStop](#oh_arkwebschemehandler_setonrequeststop) ([ArkWeb_SchemeHandler](#arkweb_schemehandler) \*schemeHandler, [ArkWeb_OnRequestStop](#arkweb_onrequeststop) onRequestStop) | Sets an **OnRequestStop** callback for **SchemeHandler**. | 
| void [OH_ArkWeb_CreateResponse](#oh_arkweb_createresponse) ([ArkWeb_Response](#arkweb_response) \*\*response) | Creates an **ArkWeb_Response** object for the intercepted request. | 
| void [OH_ArkWeb_DestroyResponse](#oh_arkweb_destroyresponse) ([ArkWeb_Response](#arkweb_response) \*response) | Destroys an **ArkWeb_Response** object. | 
| int32_t [OH_ArkWebResponse_SetUrl](#oh_arkwebresponse_seturl) ([ArkWeb_Response](#arkweb_response) \*response, const char \*url) | Sets the parsed URL that is redirected or changed due to HSTS. After the setting, redirection is triggered. | 
| void [OH_ArkWebResponse_GetUrl](#oh_arkwebresponse_geturl) (const [ArkWeb_Response](#arkweb_response) \*response, char \*\*url) | Obtains the parsed URL that is redirected or changed due to HSTS. | 
| int32_t [OH_ArkWebResponse_SetError](#oh_arkwebresponse_seterror) ([ArkWeb_Response](#arkweb_response) \*response, [ArkWeb_NetError](#arkweb_neterror) errorCode) | Sets an error code for the **ArkWeb_Response** object. | 
| [ArkWeb_NetError](#arkweb_neterror) [OH_ArkWebResponse_GetError](#oh_arkwebresponse_geterror) (const [ArkWeb_Response](#arkweb_response) \*response) | Obtains the error code of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetStatus](#oh_arkwebresponse_setstatus) ([ArkWeb_Response](#arkweb_response) \*response, int status) | Sets an HTTP status code for the **ArkWeb_Response** object. | 
| int [OH_ArkWebResponse_GetStatus](#oh_arkwebresponse_getstatus) (const [ArkWeb_Response](#arkweb_response) \*response) | Obtains the HTTP status code of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetStatusText](#oh_arkwebresponse_setstatustext) ([ArkWeb_Response](#arkweb_response) \*response, const char \*statusText) | Sets the status text for **ArkWeb_Response**. | 
| void [OH_ArkWebResponse_GetStatusText](#oh_arkwebresponse_getstatustext) (const [ArkWeb_Response](#arkweb_response) \*response, char \*\*statusText) | Obtains the status text of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetMimeType](#oh_arkwebresponse_setmimetype) ([ArkWeb_Response](#arkweb_response) \*response, const char \*mimeType) | Sets the mime type for **ArkWeb_Response**. | 
| void [OH_ArkWebResponse_GetMimeType](#oh_arkwebresponse_getmimetype) (const [ArkWeb_Response](#arkweb_response) \*response, char \*\*mimeType) | Obtains the mime type of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetCharset](#oh_arkwebresponse_setcharset) ([ArkWeb_Response](#arkweb_response) \*response, const char \*charset) | Sets the character set for **ArkWeb_Response**. | 
| void [OH_ArkWebResponse_GetCharset](#oh_arkwebresponse_getcharset) (const [ArkWeb_Response](#arkweb_response) \*response, char \*\*charset) | Obtains the character set of **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResponse_SetHeaderByName](#oh_arkwebresponse_setheaderbyname) ([ArkWeb_Response](#arkweb_response) \*response, const char \*name, const char \*value, bool overwrite) | Sets a header for **ArkWeb_Response**. | 
| void [OH_ArkWebResponse_GetHeaderByName](#oh_arkwebresponse_getheaderbyname) (const [ArkWeb_Response](#arkweb_response) \*response, const char \*name, char \*\*value) | Obtains the header from **ArkWeb_Response**. | 
| int32_t [OH_ArkWebResourceHandler_Destroy](#oh_arkwebresourcehandler_destroy) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler) | Destroys an **ArkWeb_ResourceHandler** object. | 
| int32_t [OH_ArkWebResourceHandler_DidReceiveResponse](#oh_arkwebresourcehandler_didreceiveresponse) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler, const [ArkWeb_Response](#arkweb_response) \*response) | Sends a response header for this request. | 
| int32_t [OH_ArkWebResourceHandler_DidReceiveData](#oh_arkwebresourcehandler_didreceivedata) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler, const uint8_t \*buffer, int64_t bufLen) | Sends a response body for this request. | 
| int32_t [OH_ArkWebResourceHandler_DidFinish](#oh_arkwebresourcehandler_didfinish) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler) | Notifies the ArkWeb kernel that the request is intercepted and that no more data is available. | 
| int32_t [OH_ArkWebResourceHandler_DidFailWithError](#oh_arkwebresourcehandler_didfailwitherror) (const [ArkWeb_ResourceHandler](#arkweb_resourcehandler) \*resourceHandler, [ArkWeb_NetError](#arkweb_neterror) errorCode) | Notifies the ArkWeb kernel that the intercepted request fails. | 
| void [OH_ArkWeb_ReleaseString](#oh_arkweb_releasestring) (char \*string) | Releases the string created by NDK APIs. | 
| void [OH_ArkWeb_ReleaseByteArray](#oh_arkweb_releasebytearray) (uint8_t \*byteArray) | Releases the byte array created by NDK APIs. | 
| void [OH_NativeArkWeb_RunJavaScript](#oh_nativearkweb_runjavascript) (const char \*webTag, const char \*jsCode, [NativeArkWeb_OnJavaScriptCallback](#nativearkweb_onjavascriptcallback) callback) | Runs a piece of JavaScript code in the displaying page. | 
| void [OH_NativeArkWeb_RegisterJavaScriptProxy](#oh_nativearkweb_registerjavascriptproxy) (const char \*webTag, const char \*objName, const char \*\*methodList, [NativeArkWeb_OnJavaScriptProxyCallback](#nativearkweb_onjavascriptproxycallback) \*callback, int32_t size, bool needRefresh) | Lists the registered objects and function names. | 
| void [OH_NativeArkWeb_UnregisterJavaScriptProxy](#oh_nativearkweb_unregisterjavascriptproxy) (const char \*webTag, const char \*objName) | Deletes a registered object and its callback. | 
| void [OH_NativeArkWeb_SetJavaScriptProxyValidCallback](#oh_nativearkweb_setjavascriptproxyvalidcallback) (const char \*webTag, [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback) callback) | Sets a callback used when an object is valid. | 
| [NativeArkWeb_OnValidCallback](#nativearkweb_onvalidcallback) [OH_NativeArkWeb_GetJavaScriptProxyValidCallback](#oh_nativearkweb_getjavascriptproxyvalidcallback) (const char \*webTag) | Obtains the callback used when a registered object is valid. | 
| void [OH_NativeArkWeb_SetDestroyCallback](#oh_nativearkweb_setdestroycallback) (const char \*webTag, [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback) callback) | Sets a callback used when a component is destroyed. | 
| [NativeArkWeb_OnDestroyCallback](#nativearkweb_ondestroycallback) [OH_NativeArkWeb_GetDestroyCallback](#oh_nativearkweb_getdestroycallback) (const char \*webTag) | Obtains the callback used when a registered component is destroyed. | 

## Macro Description


### ARKWEB_MEMBER_EXISTS

```
#define ARKWEB_MEMBER_EXISTS( s,  f )    ((intptr_t) & ((s)->f) - (intptr_t)(s) + sizeof((s)->f) <= *reinterpret_cast<size_t*>(s))
```
**Description**

Checks whether the member variable exists in the struct.

**Since**: 12


### ARKWEB_MEMBER_MISSING

```
#define ARKWEB_MEMBER_MISSING( s,  f )   (!ARKWEB_MEMBER_EXISTS(s, f) || !((s)->f))
```
**Description**

If the member variable exists in the struct, **false** is returned. Otherwise, **true** is returned.

**Since**: 12


## Type Description


### ArkWeb_CustomSchemeOption

```
typedef enum ArkWeb_CustomSchemeOption ArkWeb_CustomSchemeOption
```
**Description**

Defines an enum for the custom scheme options.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_ErrorCode

```
typedef enum ArkWeb_ErrorCode ArkWeb_ErrorCode
```
**Description**

Defines an enum for the error codes of ArkWeb NDK APIs.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_HttpBodyStream

```
typedef struct ArkWeb_HttpBodyStream_ ArkWeb_HttpBodyStream
```
**Description**

Defines a struct for the uploaded data of the request.

Use the **OH_ArkWebHttpBodyStream_\*** API to read the uploaded data.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_HttpBodyStreamInitCallback

```
typedef void(* ArkWeb_HttpBodyStreamInitCallback) (const ArkWeb_HttpBodyStream *httpBodyStream, ArkWeb_NetError result)
```
**Description**

Defines a callback used when **ArkWeb_HttpBodyStream** is initialized.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 
| result | If the operation is successful, **ARKWEB_NET_OK** is returned. Otherwise, see [arkweb_net_error_list.h](arkweb__net__error__list_8h.md).| 


### ArkWeb_HttpBodyStreamReadCallback

```
typedef void(* ArkWeb_HttpBodyStreamReadCallback) (const ArkWeb_HttpBodyStream *httpBodyStream, uint8_t *buffer, int bytesRead)
```
**Description**

Defines a callback used when **OH_ArkWebHttpBodyStream_Read** is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 
| buffer | Buffer for receiving data. | 
| bytesRead | Callback used when **OH_ArkWebHttpBodyStream_Read** is complete. If the value of **bytesRead** is greater than 0, the **buffer** is filled with data of the **bytesRead** size. The caller can read data from the **buffer**. If **OH_ArkWebHttpBodyStream_IsEOF** is false, the caller can continue to read the data left.| 


### ArkWeb_NetError

```
typedef enum ArkWeb_NetError ArkWeb_NetError
```
**Description**

Defines an enum for the error codes of the ArkWeb network protocol stack.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_OnComponentCallback

```
typedef void(* ArkWeb_OnComponentCallback) (const char *webTag, void *userData)
```
**Description**

Defines a callback used to return component event notification.

**Since**: 12


### ArkWeb_OnJavaScriptCallback

```
typedef void(* ArkWeb_OnJavaScriptCallback) (const char *webTag, const ArkWeb_JavaScriptBridgeData *data, void *userData)
```
**Description**

Defines a callback used when the injected JavaScript is executed.

**Since**: 12


### ArkWeb_OnJavaScriptProxyCallback

```
typedef void(* ArkWeb_OnJavaScriptProxyCallback) (const char *webTag, const ArkWeb_JavaScriptBridgeData *dataArray, size_t arraySize, void *userData)
```
**Description**

Defines a callback used when the proxy method is executed.

**Since**: 12


### ArkWeb_OnMessageEventHandler

```
typedef void(* ArkWeb_OnMessageEventHandler) (const char *webTag, const ArkWeb_WebMessagePortPtr port, const ArkWeb_WebMessagePtr message, void *userData)
```
**Description**

Defines a callback used to process the post message data sent by the HTML page.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| webTag | Name of the **Web** component. | 
| port | Post message port. | 
| message | Post message data. | 
| userData | User-defined data.| 


### ArkWeb_OnRequestStart

```
typedef void(* ArkWeb_OnRequestStart) (const ArkWeb_SchemeHandler *schemeHandler, ArkWeb_ResourceRequest *resourceRequest, const ArkWeb_ResourceHandler *resourceHandler, bool *intercept)
```
**Description**

Defines a callback used to start the request on the I/O thread.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler. | 
| resourceRequest | The object used to obtain the request information. | 
| resourceHandler | **ArkWeb_ResourceHandler** of the request. If **intercept** is set to **false**, this parameter should not be used. | 
| intercept | If the value is **true**, the request will be intercepted. If the value is **false**, the request will not be intercepted.| 


### ArkWeb_OnRequestStop

```
typedef void(* ArkWeb_OnRequestStop) (const ArkWeb_SchemeHandler *schemeHandler, const ArkWeb_ResourceRequest *resourceRequest)
```
**Description**

Defines a callback used when the request is stopped.

This callback is used on the IO thread.

The **resourceRequest** can be destroyed using **ArkWeb_ResourceRequest_Destroy**,

and **ArkWeb_ResourceHandler_Destroy** can be used to destroy the **ArkWeb_ResourceHandler** received in **ArkWeb_OnRequestStart**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler. | 
| resourceRequest | ArkWeb_ResourceRequest.| 


### ArkWeb_RequestHeaderList

```
typedef struct ArkWeb_RequestHeaderList_ ArkWeb_RequestHeaderList
```
**Description**

Defines a struct for the request header list.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_ResourceHandler

```
typedef struct ArkWeb_ResourceHandler_ ArkWeb_ResourceHandler
```
**Description**

Defines a struct for the intercepted URL requests.

You can use **ArkWeb_ResourceHandler** to send defined request headers and bodies.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_ResourceRequest

```
typedef struct ArkWeb_ResourceRequest_ ArkWeb_ResourceRequest
```
**Description**

Defines a struct for resource request. Through **OH_ArkWeb_ResourceRequest**, you can obtain the URL, method, post data, and other information of the request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_ResourceType

```
typedef enum ArkWeb_ResourceType ArkWeb_ResourceType
```
**Description**

Defines an enum for the resource types.

The resource types match the corresponding items of ResourceType in Chromium and should not be renumbered.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_Response

```
typedef struct ArkWeb_Response_ ArkWeb_Response
```
**Description**

Defines a struct for **ArkWeb_Response** for the intercepted request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_SchemeHandler

```
typedef struct ArkWeb_SchemeHandler_ ArkWeb_SchemeHandler
```
**Description**

Defines a struct for the **SchemeHandler** of a specified scheme.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12


### ArkWeb_WebMessagePortPtr

```
typedef struct ArkWeb_WebMessagePort* ArkWeb_WebMessagePortPtr
```
**Description**

Defines a struct for the pointer to the message port struct.

**Since**: 12


### ArkWeb_WebMessagePtr

```
typedef struct ArkWeb_WebMessage* ArkWeb_WebMessagePtr
```
**Description**

Defines a struct for the pointer to the data struct of post message.

**Since**: 12


### ArkWeb_WebMessageType

```
typedef enum ArkWeb_WebMessageType ArkWeb_WebMessageType
```
**Description**

Defines an enum for the data types of post message.

**Since**: 12


### NativeArkWeb_OnDestroyCallback

```
typedef void(* NativeArkWeb_OnDestroyCallback) (const char *)
```
**Description**

Defines a callback used when the **Web** component is destroyed.

**Since**: 11


### NativeArkWeb_OnJavaScriptCallback

```
typedef void(* NativeArkWeb_OnJavaScriptCallback) (const char *)
```
**Description**

Defines a callback used to return the result after the JavaScript code is executed.

**Since**: 11


### NativeArkWeb_OnJavaScriptProxyCallback

```
typedef char*(* NativeArkWeb_OnJavaScriptProxyCallback) (const char **argv, int32_t argc)
```
**Description**

Defines a callback of the injected object.

**Since**: 11


### NativeArkWeb_OnValidCallback

```
typedef void(* NativeArkWeb_OnValidCallback) (const char *)
```
**Description**

Defines a callback used when the **Web** component is valid.

**Since**: 11


## Enum Description


### ArkWeb_CustomSchemeOption

```
enum ArkWeb_CustomSchemeOption
```
**Description**

Enumerates the custom scheme options.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ARKWEB_SCHEME_OPTION_STANDARD  | If **ARKWEB_SCHEME_OPTION_STANDARD** is set, the scheme is processed as a standard scheme. The standard scheme must comply with the URL normalization and parsing rules defined in section 3.1 of RFC 1738. The rules can be found in [http://www.ietf.org/rfc/rfc1738.txt](http://www.ietf.org/rfc/rfc1738.txt). | 
| ARKWEB_SCHEME_OPTION_LOCAL  | If **ARKWEB_SCHEME_OPTION_LOCAL** is set, the scheme is processed using the same security rule as the file URL. | 
| ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED  | If **ARKWEB_SCHEME_OPTION_DISPLAY_ISOLATED** is set, the request of the scheme can be initiated only by the page loaded using the same scheme. | 
| ARKWEB_SCHEME_OPTION_SECURE  | If **ARKWEB_SCHEME_OPTION_SECURE** is set, the scheme is processed using the same security rule as the https URL. | 
| ARKWEB_SCHEME_OPTION_CORS_ENABLED  | If **ARKWEB_SCHEME_OPTION_CORS_ENABLED** is set, the scheme can send CORS requests. In most cases, this value should be set when **ARKWEB_SCHEME_OPTION_STANDARD** is set. | 
| ARKWEB_SCHEME_OPTION_CSP_BYPASSING  | If **ARKWEB_SCHEME_OPTION_CSP_BYPASSING** is set, the scheme can bypass the Content Security Policy (CSP) check. In most cases, this value should not be set when **ARKWEB_SCHEME_OPTION_STANDARD** is set. | 
| ARKWEB_SCHEME_OPTION_FETCH_ENABLED  | If **ARKWEB_SCHEME_OPTION_FETCH_ENABLED** is set, the FETCH API request of the scheme can be initiated. | 
| ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED  | If **ARKWEB_SCHEME_OPTION_CODE_CACHE_ENABLED** is set, the JS resources of the scheme support code cache. | 


### ArkWeb_ErrorCode

```
enum ArkWeb_ErrorCode
```
**Description**

Enumerates the error codes of ArkWeb NDK APIs.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ARKWEB_SUCCESS  |  Successful execution. | 
| ARKWEB_INIT_ERROR  |  Failed initialization. | 
| ARKWEB_ERROR_UNKNOWN  |  Unknown error. | 
| ARKWEB_INVALID_PARAM  |  Invalid parameter. | 
| ARKWEB_SCHEME_REGISTER_FAILED  |  The scheme configuration failed to be registered. You need to register the scheme before creating the ArkWeb. | 
| ARKWEB_INVALID_URL  |  Invalid URL. | 
| ARKWEB_INVALID_COOKIE_VALUE  |  Invalid cookie value. | 


### ArkWeb_NativeAPIVariantKind

```
enum ArkWeb_NativeAPIVariantKind
```
**Description**

Enumerates the native API types.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ARKWEB_NATIVE_COMPONENT  | API types of the Web component. | 
| ARKWEB_NATIVE_CONTROLLER  | API types of the Web controller. | 
| ARKWEB_NATIVE_WEB_MESSAGE_PORT  | API types of the web message port. | 
| ARKWEB_NATIVE_WEB_MESSAGE  | API types of the web message. | 
| ARKWEB_NATIVE_COOKIE_MANAGER  | API types of the cookie manager. | 


### ArkWeb_NetError

```
enum ArkWeb_NetError
```
**Description**

Enumerates the error codes of the ArkWeb network protocol stack.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ARKWEB_NET_OK  |  The operation is normal. | 
| ARKWEB_ERR_IO_PENDING  |  The asynchronous I/O operation is pending. This usually does not mean a fatal error. Typically, this error is generated as a notification to wait for an external notification indicating that the I/O operation is finally completed. | 
| ARKWEB_ERR_FAILED  |  The operation fails. | 
| ARKWEB_ERR_ABORTED  |  The operation is aborted (due to user operation). | 
| ARKWEB_ERR_INVALID_ARGUMENT  |  The parameter is invalid. | 
| ARKWEB_ERR_INVALID_HANDLE  |  The handle or file descriptor is invalid. | 
| ARKWEB_ERR_FILE_NOT_FOUND  |  The file or directory cannot be found. | 
| ARKWEB_ERR_TIMED_OUT  |  The operation timed out. | 
| ARKWEB_ERR_FILE_TOO_LARGE  |  The file is too large. | 
| ARKWEB_ERR_UNEXPECTED  |  An unexpected error occurs. This may be caused by programming errors or invalid assumptions. | 
| ARKWEB_ERR_ACCESS_DENIED  |  The access to resources other than the network is denied. | 
| ARKWEB_ERR_NOT_IMPLEMENTED  |  The operation fails because the function is not implemented. | 
| ARKWEB_ERR_INSUFFICIENT_RESOURCES  |  The resources are insufficient to complete the operation. | 
| ARKWEB_ERR_OUT_OF_MEMORY  |  A memory overflow occurs. | 
| ARKWEB_ERR_UPLOAD_FILE_CHANGED  |  The file fails to be loaded because the modification time of the file is not as expected. | 
| ARKWEB_ERR_SOCKET_NOT_CONNECTED  |  The socket is not connected. | 
| ARKWEB_ERR_FILE_EXISTS  |  The file already exists. | 
| ARKWEB_ERR_FILE_PATH_TOO_LONG  |  The file path or file name is too long. | 
| ARKWEB_ERR_FILE_NO_SPACE  |  The disk space is insufficient. | 
| ARKWEB_ERR_FILE_VIRUS_INFECTED  |  The file is infected. | 
| ARKWEB_ERR_BLOCKED_BY_CLIENT  |  The request is blocked by the client. | 
| ARKWEB_ERR_NETWORK_CHANGED  |  The network is changed. | 
| ARKWEB_ERR_BLOCKED_BY_ADMINISTRATOR  |  The request is blocked by the URL blocking list configured by the domain administrator. | 
| ARKWEB_ERR_SOCKET_CONNECTED  |  The socket is connected. | 
| ARKWEB_ERR_UPLOAD_STREAM_REWIND_NOT_SUPPORTED  |  The upload stream needs to be rewind due to retry or redirection. However, the uploading fails because the rewinding is not supported. | 
| ARKWEB_ERR_CONTEXT_SHUT_DOWN  |  The request failed because **URLRequestContext** is shut down or being shut down. | 
| ARKWEB_ERR_BLOCKED_BY_RESPONSE  |  The request is blocked by response from headers such as X-Frame-Options, Content Security Policy, and Cross Origin Resource Policy. | 
| ARKWEB_ERR_CLEARTEXT_NOT_PERMITTED  |  The request is blocked because some or all cleartext requests are not permitted by the system policy. | 
| ARKWEB_ERR_BLOCKED_BY_CSP  |  The request is blocked by the Content Security Policy. | 
| ARKWEB_ERR_H2_OR_QUIC_REQUIRED  |  The request is blocked because there is no H/2 or QUIC session. | 
| ARKWEB_ERR_BLOCKED_BY_ORB  |  The request is blocked by Cross-Origin Read Blocking (CORB) or ORB. | 
| ARKWEB_ERR_CONNECTION_CLOSED  |  The connection is closed, which is displayed as **TCP FIN**. | 
| ARKWEB_ERR_CONNECTION_RESET  |  The connection is reset, which is displayed as **TCP RST**. | 
| ARKWEB_ERR_CONNECTION_REFUSED  |  The connection is denied. | 
| ARKWEB_ERR_CONNECTION_ABORTED  |  The connection is aborted because the ACK for sending data is not received. This may include FIN packets. | 
| ARKWEB_ERR_CONNECTION_FAILED  |  The connection failed. | 
| ARKWEB_ERR_NAME_NOT_RESOLVED  |  The domain name cannot be resolved. | 
| ARKWEB_ERR_INTERNET_DISCONNECTED  |  The internet is disconnected. | 
| ARKWEB_ERR_SSL_PROTOCOL_ERROR  |  An SSL protocol error occurs. | 
| ARKWEB_ERR_ADDRESS_INVALID  |  The IP address or port number is invalid (for example, IP address 0 or port 0 cannot be connected). | 
| ARKWEB_ERR_ADDRESS_UNREACHABLE  |  The IP address is unreachable. This means that there is no route to the specified host or network. | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NEEDED  |  The server needs SSL client authentication certificate. | 
| ARKWEB_ERR_TUNNEL_CONNECTION_FAILED  |  The tunnel connection failed to be established through the proxy. | 
| ARKWEB_ERR_NO_SSL_VERSIONS_ENABLED  |  No SSL protocol version is enabled. | 
| ARKWEB_ERR_SSL_VERSION_OR_CIPHER_MISMATCH  |  The client and server do not support the common SSL protocol version or cipher suite. | 
| ARKWEB_ERR_SSL_RENEGOTIATION_REQUESTED  |  The server requests re-negotiation (re-handshake). | 
| ARKWEB_ERR_PROXY_AUTH_UNSUPPORTED  |  The proxy requests authentication used to establish a tunnel, but the method used is not supported. | 
| ARKWEB_ERR_BAD_SSL_CLIENT_AUTH_CERT  |  The SSL handshake fails because the client certificate is incorrect or missing. | 
| ARKWEB_ERR_CONNECTION_TIMED_OUT  |  The connection timed out. | 
| ARKWEB_ERR_HOST_RESOLVER_QUEUE_TOO_LARGE  |  The number of DNS resolutions is too large, so a request in the queue is aborted. | 
| ARKWEB_ERR_SOCKS_CONNECTION_FAILED  |  The connection between the target host and the SOCKS proxy server failed. | 
| ARKWEB_ERR_SOCKS_CONNECTION_HOST_UNREACHABLE  |  The SOCKS proxy server cannot be connected to the target host because the host is unreachable. | 
| ARKWEB_ERR_ALPN_NEGOTIATION_FAILED  |  The request of ALPN failed. | 
| ARKWEB_ERR_SSL_NO_RENEGOTIATION  |  The peer sent an **SSL_NO_RENEGOTIATION** alert message. | 
| ARKWEB_ERR_WINSOCK_UNEXPECTED_WRITTEN_BYTES  |  Winsock sometimes reports unexpected written bytes. This may be caused by LSP damage. | 
| ARKWEB_ERR_SSL_DECOMPRESSION_FAILURE_ALERT  |  The SSL peer sent us a fatal **DECOMPRESSION_FAILURE** alert. This usually occurs when the peer falsely considers that it supports **DEFLATE** and selects it. | 
| ARKWEB_ERR_SSL_BAD_RECORD_MAC_ALERT  |  The SSL peer sent us a fatal **BAD_RECORD_MAC** alert. This usually occurs on the server cannot support **DEFLATE** normally. | 
| ARKWEB_ERR_PROXY_AUTH_REQUESTED  |  The proxy requests authentication (used to establish a tunnel). | 
| ARKWEB_ERR_PROXY_CONNECTION_FAILED  |  The connection to the proxy server cannot be established. This is because an error occurs when the host resolves the name or connects its socket to the proxy server. Note that this does not include errors during the **HTTP CONNECT**. | 
| ARKWEB_ERR_MANDATORY_PROXY_CONFIGURATION_FAILED  |  The mandatory proxy configuration failed. Currently, this means that a mandatory PAC script cannot be obtained, parsed, or executed. | 
| ARKWEB_ERR_PRECONNECT_MAX_SOCKET_LIMIT  |  The maximum socket limit in the socket pool is reached when pre-connect. No more sockets need to be pre-connected. | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_PRIVATE_KEY_ACCESS_DENIED  |  The access to the private key of the SSL client certificate is denied. | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NO_PRIVATE_KEY  |  The SSL client certificate does not have a private key. | 
| ARKWEB_ERR_PROXY_CERTIFICATE_INVALID  |  The certificate provided by the HTTPS proxy is invalid. | 
| ARKWEB_ERR_NAME_RESOLUTION_FAILED  |  The name resolution (DNS) failed. | 
| ARKWEB_ERR_NETWORK_ACCESS_DENIED  |  The access to the network is denied. This error is distinguished from errors that are likely to be caused by firewalls and other errors whose access is denied. See **ERR_ACCESS_DENIED**. | 
| ARKWEB_ERR_TEMPORARILY_THROTTLED  |  The request is temporarily throttled to avoid DDoS attacks. | 
| ARKWEB_ERR_HTTPS_PROXY_TUNNEL_RESPONSE_REDIRECT  |  The request for creating an SSL tunnel connection through the HTTPS proxy receives a 302 (temporary redirection) response. The response body may contain the description of the failure cause. | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_SIGNATURE_FAILED  |  The CertificateVerify data of the SSL client authentication handshake cannot be signed using the private key of the client certificate. Possible reasons for this include that the user implicitly or explicitly denies access to the private key, the private key may not be available for signature, the key may rely on an invalid cache handle, or the CSP may not allow arbitrary data to be signed. | 
| ARKWEB_ERR_MSG_TOO_BIG  |  The message is too big to transfer. (for example, the UDP message exceeds the size limit). | 
| ARKWEB_ERR_WS_PROTOCOL_ERROR  |  The WebSocket protocol is incorrect. This indicates that the connection is terminating due to a frame format error or other protocol violation. | 
| ARKWEB_ERR_ADDRESS_IN_USE  |  The address is in use. | 
| ARKWEB_ERR_SSL_HANDSHAKE_NOT_COMPLETED  |  The operation failed because the SSL handshake is not completed. | 
| ARKWEB_ERR_SSL_BAD_PEER_PUBLIC_KEY  |  The public key of the SSL peer is invalid. | 
| ARKWEB_ERR_SSL_PINNED_KEY_NOT_IN_CERT_CHAIN  |  The certificate does not match the built-in public key Pins of the host name. Pin is set in **net/http/transport_security_state.cc**, and it is required that one of a set of public keys exist on the path from the leaf node to the root node. | 
| ARKWEB_ERR_CLIENT_AUTH_CERT_TYPE_UNSUPPORTED  |  The server requests the client certificate, but the request does not contain any of the certificates we support. | 
| ARKWEB_ERR_SSL_DECRYPT_ERROR_ALERT  |  The SSL peer sent us a fatal **DECRYPT_ERROR** alert. This usually occurs when the peer cannot verify the signature (in CertificateVerify or ServerKeyExchange) or verify the **Finished** message. | 
| ARKWEB_ERR_WS_THROTTLE_QUEUE_TOO_LARGE  |  There are too many WebSocketJob instances to be processed. Therefore, new tasks are not pushed to the queue. | 
| ARKWEB_ERR_SSL_SERVER_CERT_CHANGED  |  During the renegotiation, the SSL server certificate is changed. | 
| ARKWEB_ERR_SSL_UNRECOGNIZED_NAME_ALERT  |  The SSL server sends us a fatal UNRECOGNIZED_NAME alert. | 
| ARKWEB_ERR_SOCKET_SET_RECEIVE_BUFFER_SIZE_ERROR  |  The receive buffer size of the socket cannot be set as requested. | 
| ARKWEB_ERR_SOCKET_SET_SEND_BUFFER_SIZE_ERROR  |  The send buffer size of the socket cannot be set as requested. | 
| ARKWEB_ERR_SOCKET_RECEIVE_BUFFER_SIZE_UNCHANGEABLE  |  The setsockopt returns a success code, but the socket's receive buffer size cannot be set to the requested value. | 
| ARKWEB_ERR_SOCKET_SEND_BUFFER_SIZE_UNCHANGEABLE  |  The setsockopt returns a success code, but the socket's send buffer size cannot be set to the requested value. | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_BAD_FORMAT  |  The client certificate cannot be imported into the SSL library from the platform store. | 
| ARKWEB_ERR_ICANN_NAME_COLLISION  |  When a host name is resolved to an IP address list, the IPv4 address 127.0.53.53 is included. This is a special IP address recommended by ICANN. It is used to indicate that there is a name conflict and remind administrators of potential problems. | 
| ARKWEB_ERR_SSL_SERVER_CERT_BAD_FORMAT  |  The SSL server provides a certificate that cannot be decoded. This is not a certificate error code because no X509Certificate object is available. This error is fatal. | 
| ARKWEB_ERR_CT_STH_PARSING_FAILED  |  Certificate Transparency: The received **Signed Tree Head** cannot be parsed. | 
| ARKWEB_ERR_CT_STH_INCOMPLETE  |  Certificate transparency: The received **Signed Tree Head** can be successfully parsed into JSON, but some fields are missing. | 
| ARKWEB_ERR_UNABLE_TO_REUSE_CONNECTION_FOR_PROXY_AUTH  |  The connection to send proxy authentication credentials cannot be reused before AuthController is start. The caller should reconnect the AuthController. This error is only used internally in the network stack. | 
| ARKWEB_ERR_CT_CONSISTENCY_PROOF_PARSING_FAILED  |  Certificate transparency: The received proof of consistency cannot be parsed. | 
| ARKWEB_ERR_SSL_OBSOLETE_CIPHER  |  The SSL server requires an obsolete cipher suite. In one or two version updates after this cipher suite is removed, as a rollback policy, this error is temporarily signaled and then the rollback policy is removed. | 
| ARKWEB_ERR_WS_UPGRADE  |  This error code is used to cancel the URLRequest when the WebSocket handshake is successful and the connection has been upgraded. | 
| ARKWEB_ERR_READ_IF_READY_NOT_IMPLEMENTED  |  The **READ_IF_READY** of the socket is not implemented. This error should not be seen by the user because the normal **Read** method will be used as an alternative. | 
| ARKWEB_ERR_NO_BUFFER_SPACE  |  No socket buffer space is available. | 
| ARKWEB_ERR_SSL_CLIENT_AUTH_NO_COMMON_ALGORITHMS  |  There is no common signing algorithm between the private key of the local end certificate and the preferences of the server. | 
| ARKWEB_ERR_EARLY_DATA_REJECTED  |  The server rejected **TLS 1.3 Early Data**. This error will be received before any data is returned from the socket. **Early Data** should be disabled and the request should be retried. | 
| ARKWEB_ERR_WRONG_VERSION_ON_EARLY_DATA  |  The server responds with TLS 1.2 or earlier when TLS 1.3 Early Data is provided. This is an internal error code to solve the backward compatibility problem between Early Data and TLS 1.2. This error code will be received before the socket returns any data. Early Data should be disabled and the request should be retried. For details, see https://tools.ietf.org/html/rfc8446\#appendix-D.3. | 
| ARKWEB_ERR_TLS13_DOWNGRADE_DETECTED  |  The server negotiated an earlier version when TLS 1.3 is supported. This is part of the TLS 1.3 security check, but it may also indicate that the TLS termination proxy incorrectly implements TLS 1.2. (See https://crbug.com/boringssl/226.) | 
| ARKWEB_ERR_SSL_KEY_USAGE_INCOMPATIBLE  |  The server's certificate has a keyUsage extension that is incompatible with the negotiated TLS key exchange method. | 
| ARKWEB_ERR_INVALID_ECH_CONFIG_LIST  |  The **ECHConfigList** obtained through the DNS cannot be resolved. | 
| ARKWEB_ERR_ECH_NOT_NEGOTIATED  |  **Encrypted Client Hello (ECH)** is enabled, but the server cannot decrypt the encrypted **ClientHello**. | 
| ARKWEB_ERR_ECH_FALLBACK_CERTIFICATE_INVALID  |  **Encrypted Client Hello (ECH)** is enabled, but the server cannot decrypt the encrypted **ClientHello** and does not provide a certificate valid for the public name. | 
| ARKWEB_ERR_CERT_COMMON_NAME_INVALID  |  The server responds with a certificate whose common name does not match the host name. The possible causes are: 1. The attacker redirects the traffic to its server and presents a certificate that they know the private key.<br>1. The server is incorrectly configured and responds with an incorrect certificate.3. The user is on the wireless network and is redirected to the login page of the network.4. The operating system uses the **DNS** search suffix, but the server does not provide a certificate for the abbreviated name in the address bar. | 
| ARKWEB_ERR_CERT_DATE_INVALID  |  The server responds with a certificate, but according to the host clock, the certificate does not take effect or is expired. This may be one of the following: 1. The attacker provides an old certificate and obtains the private key.2. 2. The server is incorrectly configured and no valid certificate is provided.3. The host clock is wrong. | 
| ARKWEB_ERR_CERT_AUTHORITY_INVALID  |  The server responds with a certificate signed by an authority that we do not trust. The possible causes are: 1. The attacker replaces the real certificate with a certificate that contains its public key and is signed by its associates.<br>1. The server has a valid certificate from a CA that we do not know but should trust.3. The server presents a self-signed certificate, which cannot defend against active attackers but passive attackers. | 
| ARKWEB_ERR_CERT_CONTAINS_ERRORS  |  The certificate returned by the server contains an error. This error cannot be rectified. MSDN describes this error as "The SSL certificate contains an error". Note: It is not clear how this error differs from **ERR_CERT_INVALID**. To maintain consistency, replace this error with the **ERR_CERT_INVALID** code. | 
| ARKWEB_ERR_CERT_NO_REVOCATION_MECHANISM  |  The certificate does not have a revocation mechanism. In other words, this certificate cannot be revoked. | 
| ARKWEB_ERR_CERT_UNABLE_TO_CHECK_REVOCATION  |  Revocation information for this website's security certificate is not available. The possible causes are: 1. The attacker has cracked the private key in the certificate and prevented the host from finding out that the certificate is revoked.2. 2. The certificate is not revoked, but the revocation server is busy or unavailable. | 
| ARKWEB_ERR_CERT_REVOKED  |  The certificate responded by the server is revoked. This error could but not should be ignored. | 
| ARKWEB_ERR_CERT_INVALID  |  The server responds with an invalid certificate. This error cannot be rectified. MSDN describes this error as follows: "The SSL certificate is invalid."  | 
| ARKWEB_ERR_CERT_WEAK_SIGNATURE_ALGORITHM  |  The server responds with a certificate signed using a weak signing algorithm. | 
| ARKWEB_ERR_CERT_NON_UNIQUE_NAME  |  The host name specified in the certificate is not unique. | 
| ARKWEB_ERR_CERT_WEAK_KEY  |  The server responds with a certificate containing a weak key (for example, a too small RSA key). | 
| ARKWEB_ERR_CERT_NAME_CONSTRAINT_VIOLATION  |  The **DNS** suffix declared in the certificate violates the name constraint. | 
| ARKWEB_ERR_CERT_VALIDITY_TOO_LONG  |  The validity period of the certificate is too long. | 
| ARKWEB_ERR_CERTIFICATE_TRANSPARENCY_REQUIRED  |  The **Certificate Transparency** is required, but the server does not provide CT information that complies with the policy. | 
| ARKWEB_ERR_CERT_SYMANTEC_LEGACY  |  The certificate is linked to an old Symantec certificate or its subsidiaries that are no longer trusted. | 
| ARKWEB_ERR_CERT_KNOWN_INTERCEPTION_BLOCKED  |  It is known that the certificate is intercepted by an entity other than the device owner. | 
| ARKWEB_ERR_SSL_OBSOLETE_VERSION_OR_CIPHER  |  The connection uses an obsolete version of SSL/TLS or an encryption algorithm. | 
| ARKWEB_ERR_CERT_END  |  The error immediately follows the last certificate error code. | 
| ARKWEB_ERR_INVALID_URL  |  The URL is invalid. | 
| ARKWEB_ERR_DISALLOWED_URL_SCHEME  |  The scheme of the URL is not allowed. | 
| ARKWEB_ERR_UNKNOWN_URL_SCHEME  |  The scheme of the URL is unknown. | 
| ARKWEB_ERR_INVALID_REDIRECT  |  An invalid URL is redirected when loads a URL. | 
| ARKWEB_ERR_TOO_MANY_REDIRECTS  |  Too many URLs are redirected when loads a URL. | 
| ARKWEB_ERR_UNSAFE_REDIRECT  |  An insecure URL is redirected when loads a URL (for example, redirection to **file://** is insecure). | 
| ARKWEB_ERR_UNSAFE_PORT  |  The port number of the URL to be loaded is unsafe. | 
| ARKWEB_ERR_INVALID_RESPONSE  |  The response from the server is invalid. | 
| ARKWEB_ERR_INVALID_CHUNKED_ENCODING  |  The chunked encoding is invalid. | 
| ARKWEB_ERR_METHOD_UNSUPPORTED  |  The server does not support the request method. | 
| ARKWEB_ERR_UNEXPECTED_PROXY_AUTH  |  The response value is **407**, indicating proxy authentication is required, but the host does not send the request to the proxy. | 
| ARKWEB_ERR_EMPTY_RESPONSE  |  The server closes the connection and does not response. | 
| ARKWEB_ERR_RESPONSE_HEADERS_TOO_BIG  |  The response headers are too big. | 
| ARKWEB_ERR_PAC_SCRIPT_FAILED  |  The PAC script failed. | 
| ARKWEB_ERR_REQUEST_RANGE_NOT_SATISFIABLE  |  The response code is 416, indicating the server cannot meet the request range. | 
| ARKWEB_ERR_MALFORMED_IDENTITY  |  The identity is malformed. | 
| ARKWEB_ERR_CONTENT_DECODING_FAILED  |  The content decoding of the response body failed. | 
| ARKWEB_ERR_NETWORK_IO_SUSPENDED  |  The operation failed because all network I/Os are suspended. | 
| ARKWEB_ERR_SYN_REPLY_NOT_RECEIVED  |  FLIP data is received before **SYN_REPLY** is received on the flow. | 
| ARKWEB_ERR_ENCODING_CONVERSION_FAILED  |  The response failed to be converted to the target encoding. | 
| ARKWEB_ERR_UNRECOGNIZED_FTP_DIRECTORY_LISTING_FORMAT  |  The server sent an unrecognized FTP directory listing format. | 
| ARKWEB_ERR_NO_SUPPORTED_PROXIES  |  There are no supported proxies in the list provided. | 
| ARKWEB_ERR_HTTP2_PROTOCOL_ERROR  |  An HTTP/2 protocol error occurs. | 
| ARKWEB_ERR_INVALID_AUTH_CREDENTIALS  |  The HTTP authentication credentials are invalid. | 
| ARKWEB_ERR_UNSUPPORTED_AUTH_SCHEME  |  The HTTP authentication scheme is not supported. | 
| ARKWEB_ERR_ENCODING_DETECTION_FAILED  |  The encoding detection failed. | 
| ARKWEB_ERR_MISSING_AUTH_CREDENTIALS  |   (GSSAPI) There Kerberos credentials of HTTP authentication are missing. | 
| ARKWEB_ERR_UNEXPECTED_SECURITY_LIBRARY_STATUS  |  The SSPI or GSSAPI status code is unexpected. | 
| ARKWEB_ERR_MISCONFIGURED_AUTH_ENVIRONMENT  |  The authentication environment is misconfigured. (For example, the KDC cannot be found or the principal is unknown). | 
| ARKWEB_ERR_UNDOCUMENTED_SECURITY_LIBRARY_STATUS  |  The SSPI or GSSAPI status code is undocumented. | 
| ARKWEB_ERR_RESPONSE_BODY_TOO_BIG_TO_DRAIN  |  The HTTP response body is too big to drain. | 
| ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_LENGTH  |  Multiple Content-Length response headers are included in an HTTP response. | 
| ARKWEB_ERR_INCOMPLETE_HTTP2_HEADERS  |  The HTTP/2 response headers are incomplete. Therefore, more frames are needed to complete them. | 
| ARKWEB_ERR_PAC_NOT_IN_DHCP  |  The PAC URL configuration cannot be retrieved from DHCP. This may indicate that the retrieving failed, or that the PAC URL is not configured in DHCP. | 
| ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_DISPOSITION  |  Multiple **Content-Disposition** headers are included in an HTTP response. | 
| ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_LOCATION  |  Multiple **Location** headers are included in an HTTP response. | 
| ARKWEB_ERR_HTTP2_SERVER_REFUSED_STREAM  |  The HTTP/2 server rejects the request without processing it and sends a **GOAWAY** frame with an error code **NO_ERROR** and a **Last-Stream-ID** lower than the **Stream ID** of the request, or the **RST_STREAM** frame with the error code **REFUSED_STREAM** indicating that the request is not processed. The client can retry the request (on a different connection). For details, see "section 8.1.4 in RFC7540". | 
| ARKWEB_ERR_HTTP2_PING_FAILED  |  The HTTP/2 server does not respond to the **PING**. | 
| ARKWEB_ERR_CONTENT_LENGTH_MISMATCH  |  When the connection is closed, the number of bytes transmitted in the HTTP response body is less than the number of bytes advertised in the **Content-Length** header. | 
| ARKWEB_ERR_INCOMPLETE_CHUNKED_ENCODING  |  The HTTP response body is transmitted using chunked encoding, and the terminated zero-length block is not sent when the connection is closed. | 
| ARKWEB_ERR_QUIC_PROTOCOL_ERROR  |  A QUIC protocol error occurs. | 
| ARKWEB_ERR_RESPONSE_HEADERS_TRUNCATED  |  The HTTP response headers are truncated by the end of file (EOF). | 
| ARKWEB_ERR_QUIC_HANDSHAKE_FAILED  |  The QUIC encryption handshake failed. This means that the server cannot read any requests, so they may be resent. | 
| ARKWEB_ERR_HTTP2_INADEQUATE_TRANSPORT_SECURITY  |  The transport security is inadequate to HTTP/2. | 
| ARKWEB_ERR_HTTP2_FLOW_CONTROL_ERROR  |  The peer violates HTTP/2 flow control. | 
| ARKWEB_ERR_HTTP2_FRAME_SIZE_ERROR  |  The peer sends an HTTP/2 frame of an incorrect size. | 
| ARKWEB_ERR_HTTP2_COMPRESSION_ERROR  |  The decoding or encoding of the compressed HTTP/2 response headers failed. | 
| ARKWEB_ERR_PROXY_AUTH_REQUESTED_WITH_NO_CONNECTION  |  The proxy authentication of a request does not have a valid client socket handle. | 
| ARKWEB_ERR_HTTP_1_1_REQUIRED  |  The HTTP/2 session receives an **HTTP_1_1_REQUIRED** error code. | 
| ARKWEB_ERR_PROXY_HTTP_1_1_REQUIRED  |  The **HTTP_1_1_REQUIRED** error code is received when the HTTP/2 session proxy is used. | 
| ARKWEB_ERR_PAC_SCRIPT_TERMINATED  |  The PAC script has been terminated and must be reloaded. | 
| ARKWEB_ERR_INVALID_HTTP_RESPONSE  |  The server should return an **HTTP/1.x** response. But it returns an **HTTP/0.9** response. | 
| ARKWEB_ERR_CONTENT_DECODING_INIT_FAILED  |  The content decoding fails to be initialized. | 
| ARKWEB_ERR_HTTP2_RST_STREAM_NO_ERROR_RECEIVED  |  An **HTTP/2 RST_STREAM** frame with **NO_ERROR** is received. This error should be handled internally by HTTP/2 and should not exceed the SpdyStream layer. | 
| ARKWEB_ERR_HTTP2_PUSHED_STREAM_NOT_AVAILABLE  |  The pushed stream claimed by the request is not available. | 
| ARKWEB_ERR_HTTP2_CLAIMED_PUSHED_STREAM_RESET_BY_SERVER  |  The claimed pushed stream is reset by the server. In this case, the request should be retried. | 
| ARKWEB_ERR_TOO_MANY_RETRIES  |  There are too many retries due to invalid authentication or certificate. | 
| ARKWEB_ERR_HTTP2_STREAM_CLOSED  |  An HTTP/2 frame is received on the closed stream. | 
| ARKWEB_ERR_HTTP2_CLIENT_REFUSED_STREAM  |  The client refuses an HTTP/2 stream. | 
| ARKWEB_ERR_HTTP2_PUSHED_RESPONSE_DOES_NOT_MATCH  |  Based on the matched URL and request header, an HTTP/2 push stream is received by the request, but the pushed response header does not match the request. | 
| ARKWEB_ERR_HTTP_RESPONSE_CODE_FAILURE  |  The server returns a **non-2xx** HTTP response code. | 
| ARKWEB_ERR_QUIC_UNKNOWN_CERT_ROOT  |  The certificate displayed on the QUIC connection is not linked to a known root certificate, and the connected original server is not in the list of domain names that allow unknown root certificates. | 
| ARKWEB_ERR_QUIC_GOAWAY_REQUEST_CAN_BE_RETRIED  |  A **GOAWAY** frame has been received, indicating that the request has not been processed and therefore can be safely retried on a different connection. | 
| ARKWEB_ERR_TOO_MANY_ACCEPT_CH_RESTARTS  |  The **ACCEPT_CH_RESTARTS** has been triggered too many times. | 
| ARKWEB_ERR_INCONSISTENT_IP_ADDRESS_SPACE  |  In the same request, the IP address space of the remote endpoint is different from the previous one. Cache entries for any affected requests should be marked as invalid. | 
| ARKWEB_ERR_CACHED_IP_ADDRESS_SPACE_BLOCKED_BY_LOCAL_NETWORK_ACCESS_POLICY  |  The cached IP address space of the remote endpoint is blocked by a local network access policy. | 
| ARKWEB_ERR_CACHE_MISS  |  There is no entry of the request in the cache. | 
| ARKWEB_ERR_CACHE_READ_FAILURE  |  The entry cannot be read from the cache. | 
| ARKWEB_ERR_CACHE_WRITE_FAILURE  |  The entry cannot be written to the cache. | 
| ARKWEB_ERR_CACHE_OPERATION_UNSUPPORTED  |  The entry of the request is not supported by the cache. | 
| ARKWEB_ERR_CACHE_OPEN_FAILURE  |  The cache could not open this entry. | 
| ARKWEB_ERR_CACHE_CREATE_FAILURE  |  The cache could not create this entry. | 
| ARKWEB_ERR_CACHE_RACE  |  Multiple transactions are competing to create disk cache entries. | 
| ARKWEB_ERR_CACHE_CHECKSUM_READ_FAILURE  |  The cache could not read the checksum on the entry. | 
| ARKWEB_ERR_CACHE_CHECKSUM_MISMATCH  |  An entry with an invalid checksum is found in the cache. | 
| ARKWEB_ERR_CACHE_LOCK_TIMEOUT  |  The HTTP cache contains error code. | 
| ARKWEB_ERR_CACHE_AUTH_FAILURE_AFTER_READ  |  A challenge is received after the transaction reads some data, but the credentials are unavailable. | 
| ARKWEB_ERR_CACHE_ENTRY_NOT_SUITABLE  |  This error code is for internal, non-standard HTTP caching. | 
| ARKWEB_ERR_CACHE_DOOM_FAILURE  |  The cache cannot delete this entry. | 
| ARKWEB_ERR_CACHE_OPEN_OR_CREATE_FAILURE  |  The cache could not open or create this entry. | 
| ARKWEB_ERR_INSECURE_RESPONSE  |  The server response is insecure (for example, there is a certificate error). | 
| ARKWEB_ERR_NO_PRIVATE_KEY_FOR_CERT  |  The client certificate failed to be imported because the user's key database does not have a private key. | 
| ARKWEB_ERR_ADD_USER_CERT_FAILED  |  The certificate failed to be added to the operating system database. | 
| ARKWEB_ERR_INVALID_SIGNED_EXCHANGE  |  The signed exchange is invalid. | 
| ARKWEB_ERR_INVALID_WEB_BUNDLE  |  The Web Bundle resources are invalid. | 
| ARKWEB_ERR_TRUST_TOKEN_OPERATION_FAILED  |  The request for performing the Trust Tokens protocol operation failed. The possible causes include prerequisite failure, internal error, and bad response. | 
| ARKWEB_ERR_TRUST_TOKEN_OPERATION_SUCCESS_WITHOUT_SENDING_REQUEST  |  When processing an operation execution request related to the Trust Tokens protocol, the system performs the Trust Tokens operation in the request, but does not send the request to the specified destination. | 
| ARKWEB_ERR_FTP_FAILED  |  The FTP control connection command failed. If possible, replace this error code with a more specific one. | 
| ARKWEB_ERR_FTP_SERVICE_UNAVAILABLE  |  The server cannot support the request. This is a temporary error. The FTP response code is 421. | 
| ARKWEB_ERR_FTP_TRANSFER_ABORTED  |  The server aborts the transfer. The FTP response code is 426. | 
| ARKWEB_ERR_FTP_FILE_BUSY  |  The file is in use, or some other temporary error occurs when the file is opened. The FTP response code is 450. | 
| ARKWEB_ERR_FTP_SYNTAX_ERROR  |  The server rejects the command from the host due to a syntax error. The FTP response code is 500 or 501. | 
| ARKWEB_ERR_FTP_COMMAND_UNSUPPORTED  |  The server does not support the command. The FTP response code is 502 or 504. | 
| ARKWEB_ERR_FTP_BAD_COMMAND_SEQUENCE  |  The server rejects the commands from the host because the host does not send the commands in the correct sequence. The FTP response code is 503. | 
| ARKWEB_ERR_PKCS12_IMPORT_BAD_PASSWORD  |  The **PKCS \#12** file cannot be imported because the password is incorrect. | 
| ARKWEB_ERR_PKCS12_IMPORT_FAILED  |  The **PKCS \#12** file cannot be imported due to other errors. | 
| ARKWEB_ERR_IMPORT_CA_CERT_NOT_CA  |  The CA certificate cannot be imported because it is not a real CA certificate. | 
| ARKWEB_ERR_IMPORT_CERT_ALREADY_EXISTS  |  The certificate cannot be imported because it already exists in the database. | 
| ARKWEB_ERR_IMPORT_CA_CERT_FAILED  |  The CA failed to be imported due to other errors. | 
| ARKWEB_ERR_IMPORT_SERVER_CERT_FAILED  |  The server certificate failed to be imported due to some internal errors. | 
| ARKWEB_ERR_PKCS12_IMPORT_INVALID_MAC  |  The **PKCS \#12** file failed to be imported because the message authentication code (MAC) is invalid. | 
| ARKWEB_ERR_PKCS12_IMPORT_INVALID_FILE  |  The **PKCS \#12** file failed to be imported because the file is invalid or corrupted. | 
| ARKWEB_ERR_PKCS12_IMPORT_UNSUPPORTED  |  The **PKCS \#12** file failed to be imported due to its unsupported features. | 
| ARKWEB_ERR_KEY_GENERATION_FAILED  |  The key generation failed. | 
| ARKWEB_ERR_PRIVATE_KEY_EXPORT_FAILED  |  The private key failed to be exported. | 
| ARKWEB_ERR_SELF_SIGNED_CERT_GENERATION_FAILED  |  The self-signed certificate failed to be generated. | 
| ARKWEB_ERR_CERT_DATABASE_CHANGED  |  The certificate database is changed. | 
| ARKWEB_ERR_CERT_VERIFIER_CHANGED  |  The certificate verifier configuration is changed. | 
| ARKWEB_ERR_DNS_MALFORMED_RESPONSE  |  The DNS resolver receives a response that the format is incorrect. | 
| ARKWEB_ERR_DNS_SERVER_REQUIRES_TCP  |  The DNS server requires TCP. | 
| ARKWEB_ERR_DNS_SERVER_FAILED  |  The DNS server failed. This error is returned for all of the following cases: 1 - Format error - The name server cannot interpret the query. 2-Server failure: The name server cannot process the query due to its own problems. 3-Not Implemented: The name server does not support the query type of the request. 4-Rejection: The name server refuses to perform the specified operation for policy reasons. | 
| ARKWEB_ERR_DNS_TIMED_OUT  |  The DNS transaction timed out. | 
| ARKWEB_ERR_DNS_CACHE_MISS  |  The entry is not found in the cache or other local sources. | 
| ARKWEB_ERR_DNS_SEARCH_EMPTY  |  The suffix search list rule prevents the resolution of a given host name. | 
| ARKWEB_ERR_DNS_SORT_ERROR  |  Addresses are not sorted according to RFC 3484. | 
| ARKWEB_ERR_DNS_SECURE_RESOLVER_HOSTNAME_RESOLUTION_FAILED  |  The host name of the DNS-over-HTTPS server cannot be resolved. | 
| ARKWEB_ERR_DNS_NAME_HTTPS_ONLY  |  DNS has identified that the request is prohibited due to insecure connections (HTTP/WS). The application should handle this error like HTTP redirection, redirecting the connection to secure HTTPS or WSS. | 
| ARKWEB_ERR_DNS_REQUEST_CANCELED  |  All DNS requests related to this task are canceled. | 
| ARKWEB_ERR_DNS_NO_MATCHING_SUPPORTED_ALPN  |  The host name resolution of the HTTPS record is not resolved using the ALPN value of the supported protocol. | 

### ArkWeb_ResourceType

```
enum ArkWeb_ResourceType
```
**Description**

Enumerates the resource types.

The resource types match the corresponding items of ResourceType in Chromium and should not be renumbered.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| MAIN_FRAME  | Top-level page. | 
| SUB_FRAME  | Frame or Iframe. | 
| STYLE_SHEET  | CSS style sheet. | 
| SCRIPT  | External script. | 
| IMAGE  | images (jpg/gif/png/ and others). | 
| FONT_RESOURCE  | Fount resource. | 
| SUB_RESOURCE  | Other sub-resources. If the type is unknown, the default type is used. | 
| OBJECT  | The Object (or embedded) tag of the plug-in, or the resource requested by the plug-in. | 
| MEDIA  | Media resource | 
| WORKER  | Main resource of the dedicated worker thread. | 
| SHARED_WORKER  | Main resource of the share worker thread. | 
| PREFETCH  | Explicit prefetch request. | 
| FAVICON  | Website icon. | 
| XHR  | XMLHttpRequest. | 
| PING  | Ping request of **/sendBeacon**. | 
| SERVICE_WORKER  | Main resource of the service worker. | 
| CSP_REPORT  | Report of Content Security Policy violation. | 
| PLUGIN_RESOURCE  | Resource requested by the plug-in. | 
| NAVIGATION_PRELOAD_MAIN_FRAME  | Main frame redirection request that triggers service worker warm-up. | 
| NAVIGATION_PRELOAD_SUB_FRAME  | Subframe redirection request that triggers service worker warm-up. | 


### ArkWeb_WebMessageType

```
enum ArkWeb_WebMessageType
```
**Description**

Enumerates the data types of post message.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| ARKWEB_NONE  | Incorrect data. | 
| ARKWEB_STRING  | String data. | 
| ARKWEB_BUFFER  | Byte stream data. | 


## Function Description


### OH_ArkWeb_ClearSchemeHandlers()

```
int32_t OH_ArkWeb_ClearSchemeHandlers (const char * webTag)
```
**Description**

Clears the **SchemeHandler** registered for the specified web.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| webTag | Tag that uniquely identifies a **\<Web>** component. Ensure that it is unique. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWeb_CreateResponse()

```
void OH_ArkWeb_CreateResponse (ArkWeb_Response ** response)
```
**Description**

Creates an **ArkWeb_Response** object for the intercepted request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | Returns the created **ArkWeb_Response**. Use **OH_ArkWeb_DestoryResponse** to destroy it when it is not required.| 


### OH_ArkWeb_CreateSchemeHandler()

```
void OH_ArkWeb_CreateSchemeHandler (ArkWeb_SchemeHandler ** schemeHandler)
```
**Description**

Creates an **ArkWeb_SchemeHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| schemeHandler | Returns the created **ArkWeb_SchemeHandler**. You can use **OH_ArkWeb_DestoryschemeHandler** to destroy it when it is not needed.| 


### OH_ArkWeb_DestroyResponse()

```
void OH_ArkWeb_DestroyResponse (ArkWeb_Response * response)
```
**Description**

Destroys an **ArkWeb_Response** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | The **ArkWeb_Response** to be destroyed.| 


### OH_ArkWeb_DestroySchemeHandler()

```
void OH_ArkWeb_DestroySchemeHandler (ArkWeb_SchemeHandler * schemeHandler)
```
**Description**

Destroys an **ArkWeb_SchemeHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| schemeHandler | The **ArkWeb_SchemeHandler** to be destroyed.| 


### OH_ArkWeb_GetNativeAPI()

```
ArkWeb_AnyNativeAPI* OH_ArkWeb_GetNativeAPI (ArkWeb_NativeAPIVariantKind type)
```
**Description**

Obtains the native API struct based on the transferred API type.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| type | The native API types supported by ArkWeb. | 

**Returns**

The corresponding native API structure pointer is returned based on the input API type. The first member of the structure is the size of the current structure.


### OH_ArkWeb_RegisterCustomSchemes()

```
int32_t OH_ArkWeb_RegisterCustomSchemes (const char * scheme, int32_t option )
```
**Description**

Registers a custom scheme with the **ArkWeb**.

This function should not be called for built-in HTTP, HTTPS, FILE, FTP, ABOUT, and DATA protocols.

This function should be called on the main thread and before kernel initialization.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| scheme | Scheme to be registered. | 
| option | Scheme options. | 

**Returns**

If **0** is returned, the operation is successful. If **17100100** is returned, an unknown error occurs. If **17100101** is returned, the parameter is invalid. If **17100102** is returned, the configuration of the scheme fails to be registered. The scheme should be registered before the ArkWeb is created.


### OH_ArkWeb_ReleaseByteArray()

```
void OH_ArkWeb_ReleaseByteArray (uint8_t * byteArray)
```
**Description**

Releases the byte array created by NDK APIs.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| byteArray | Byte array to be released.| 


### OH_ArkWeb_ReleaseString()

```
void OH_ArkWeb_ReleaseString (char * string)
```
**Description**

Releases the string created by NDK APIs.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| string | Character string to be released.| 


### OH_ArkWeb_SetSchemeHandler()

```
bool OH_ArkWeb_SetSchemeHandler (const char * scheme, const char * webTag, ArkWeb_SchemeHandler * schemeHandler )
```
**Description**

Sets an **ArkWeb_SchemeHandler** for a specified scheme to intercept requests of this scheme.

The **SchemeHandler** should be set after **BrowserContext** is created.

You can use **WebviewController.initializeWebEngine** to initialize **BrowserContext** without creating the ArkWeb component.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| scheme | The scheme to be intercepted. | 
| webTag | Tag that uniquely identifies a **\<Web>** component. Ensure that it is unique. | 
| schemeHandler | The **ArkWeb_SchemeHandler** for this scheme. Only requests triggered from the specified web are notified through this **SchemeHandler**. | 

**Returns**

If the **SchemeHandler** is successfully set for the specified scheme, **true** is returned. Otherwise, **false** is returned.


### OH_ArkWebHttpBodyStream_GetPosition()

```
uint64_t OH_ArkWebHttpBodyStream_GetPosition (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**Description**

Obtains the position of **httpBodyStream**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 

**Returns**

The position of **httpBodyStream**. If **httpBodyStream** is invalid, the position value is **0**.


### OH_ArkWebHttpBodyStream_GetSize()

```
uint64_t OH_ArkWebHttpBodyStream_GetSize (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**Description**

Obtains the size of **httpBodyStream**.

When data is transmitted in blocks or **httpBodyStream** is invalid, **0** is always returned.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 

**Returns**

The size of **httpBodyStream**.


### OH_ArkWebHttpBodyStream_GetUserData()

```
void* OH_ArkWebHttpBodyStream_GetUserData (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**Description**

Obtains user data from **ArkWeb_HttpBodyStream**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 

**Returns**

Returns the user data.


### OH_ArkWebHttpBodyStream_Init()

```
int32_t OH_ArkWebHttpBodyStream_Init (ArkWeb_HttpBodyStream * httpBodyStream, ArkWeb_HttpBodyStreamInitCallback initCallback )
```
**Description**

Initializes **ArkWeb_HttpBodyStream**.

This function must be called before any other function is called. This API needs to be called in the I/O thread.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 
| initCallback | Callback used to initialize. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebHttpBodyStream_IsChunked()

```
bool OH_ArkWebHttpBodyStream_IsChunked (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**Description**

Determines whether **httpBodyStream** is chunked to transfer.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 

**Returns**

If **httpBodyStream** is chunked to transfer, **true** is returned. Otherwise, **false** is returned.


### OH_ArkWebHttpBodyStream_IsEof()

```
bool OH_ArkWebHttpBodyStream_IsEof (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**Description**

Returns **true** if all data in **httpBodyStream** is read.

Returns **false** before reading the chunked **httpBodyStream** the first time.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 

**Returns**

If all data has been read, **true** is returned. Otherwise, **false** is returned.


### OH_ArkWebHttpBodyStream_IsInMemory()

```
bool OH_ArkWebHttpBodyStream_IsInMemory (const ArkWeb_HttpBodyStream * httpBodyStream)
```
**Description**

Returns **true** if all the upload data in **httpBodyStream** is in memory and all read requests will be synchronized successfully.

Returns **false** if the data is chunked to transfer.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 

**Returns**

If all the uploaded data is stored in the memory, **true** is returned. Otherwise, **false** is returned.


### OH_ArkWebHttpBodyStream_Read()

```
void OH_ArkWebHttpBodyStream_Read (const ArkWeb_HttpBodyStream * httpBodyStream, uint8_t * buffer, int bufLen )
```
**Description**

Exports upload data of the request to the buffer.

The buffer size must be greater than the value of **bufLen**. The data from the worker thread is exported to the buffer. Therefore, before the callback returns, the buffer should not be used in other threads to avoid concurrency problems.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 
| buffer | Buffer for receiving data. | 
| bufLen | Size of the byte to be read.| 


### OH_ArkWebHttpBodyStream_SetReadCallback()

```
int32_t OH_ArkWebHttpBodyStream_SetReadCallback (ArkWeb_HttpBodyStream * httpBodyStream, ArkWeb_HttpBodyStreamReadCallback readCallback )
```
**Description**

Sets a callback for **OH_ArkWebHttpBodyStream_Read**.

The result of **OH_ArkWebHttpBodyStream_Read** is notified to the caller through **readCallback**.

This callback will run in the same thread as **OH_ArkWebHttpBodyStream_Read**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 
| readCallback | Callback of **OH_ArkWebHttpBodyStream_Read**. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebHttpBodyStream_SetUserData()

```
int32_t OH_ArkWebHttpBodyStream_SetUserData (ArkWeb_HttpBodyStream * httpBodyStream, void * userData )
```
**Description**

Sets user data to the **ArkWeb_HttpBodyStream** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | ArkWeb_HttpBodyStream. | 
| userData | The user data to be set. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebRequestHeaderList_Destroy()

```
void OH_ArkWebRequestHeaderList_Destroy (ArkWeb_RequestHeaderList * requestHeaderList)
```
**Description**

Destroys an **ArkWeb_RequestHeaderList** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestHeaderList | The **ArkWeb_RequestHeaderList** to be destroyed.| 


### OH_ArkWebRequestHeaderList_GetHeader()

```
void OH_ArkWebRequestHeaderList_GetHeader (const ArkWeb_RequestHeaderList * requestHeaderList, int32_t index, char ** key, char ** value )
```
**Description**

Obtains a specified request header.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestHeaderList | The request header list. | 
| index | The index of the request headers. | 
| key | The key of a request header. You should use the **OH_ArkWeb_ReleaseString** function to release the string. | 
| value | The value of a request header. You should use the **OH_ArkWeb_ReleaseString** function to release the string.| 


### OH_ArkWebRequestHeaderList_GetSize()

```
int32_t OH_ArkWebRequestHeaderList_GetSize (const ArkWeb_RequestHeaderList * requestHeaderList)
```
**Description**

Obtains the size of a request header list.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestHeaderList | The request header list. | 

**Returns**

The size of the request header. If **requestHeaderList** is invalid, the value is -1.


### OH_ArkWebResourceHandler_Destroy()

```
int32_t OH_ArkWebResourceHandler_Destroy (const ArkWeb_ResourceHandler * resourceHandler)
```
**Description**

Destroys an **ArkWeb_ResourceHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceHandler | ArkWeb_ResourceHandler. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResourceHandler_DidFailWithError()

```
int32_t OH_ArkWebResourceHandler_DidFailWithError (const ArkWeb_ResourceHandler * resourceHandler, ArkWeb_NetError errorCode )
```
**Description**

Notifies the ArkWeb kernel that the intercepted request fails.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceHandler | **ArkWeb_ResourceHandler** of the request. | 
| errorCode | The error code for a request. For details, see [arkweb_net_error_list.h](arkweb__net__error__list_8h.md). | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResourceHandler_DidFinish()

```
int32_t OH_ArkWebResourceHandler_DidFinish (const ArkWeb_ResourceHandler * resourceHandler)
```
**Description**

Notifies the ArkWeb kernel that the request is intercepted and that no more data is available.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceHandler | **ArkWeb_ResourceHandler** of the request. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResourceHandler_DidReceiveData()

```
int32_t OH_ArkWebResourceHandler_DidReceiveData (const ArkWeb_ResourceHandler * resourceHandler, const uint8_t * buffer, int64_t bufLen )
```
**Description**

Sends a response body to the intercepted request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceHandler | **ArkWeb_ResourceHandler** of the request. | 
| buffer | The buffer data to be sent. | 
| bufLen | The buffer size. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResourceHandler_DidReceiveResponse()

```
int32_t OH_ArkWebResourceHandler_DidReceiveResponse (const ArkWeb_ResourceHandler * resourceHandler, const ArkWeb_Response * response )
```
**Description**

Sends a response header to the intercepted request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceHandler | **ArkWeb_ResourceHandler** of the request. | 
| response | The **ArkWeb_Response** of the intercepted request. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResourceRequest_Destroy()

```
int32_t OH_ArkWebResourceRequest_Destroy (const ArkWeb_ResourceRequest * resourceRequest)
```
**Description**

Destroys an **ArkWeb_ResourceRequest** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResourceRequest_DestroyHttpBodyStream()

```
void OH_ArkWebResourceRequest_DestroyHttpBodyStream (ArkWeb_HttpBodyStream * httpBodyStream)
```
**Description**

Destroys an **ArkWeb_HttpBodyStream** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| httpBodyStream | The **httpBodyStream** to be destroyed.| 


### OH_ArkWebResourceRequest_GetFrameUrl()

```
void OH_ArkWebResourceRequest_GetFrameUrl (const ArkWeb_ResourceRequest * resourceRequest, char ** frameUrl )
```
**Description**

Obtains the URL of the frame that triggers the request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 
| frameUrl | The URL of the frame that triggers the request. This function allocates memory for the URL string. You should release the string using **OH_ArkWeb_ReleaseString**.| 


### OH_ArkWebResourceRequest_GetHttpBodyStream()

```
void OH_ArkWebResourceRequest_GetHttpBodyStream (const ArkWeb_ResourceRequest * resourceRequest, ArkWeb_HttpBodyStream ** httpBodyStream )
```
**Description**

Creates an **ArkWeb_HttpBodyStream** to read the uploaded data of the request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 
| httpBodyStream | The uploaded data of the request. This function allocates memory for **httpBodyStream**. You should use **OH_ArkWebResourceRequest_DestroyHttpBodyStream** to release **httpBodyStream**.| 


### OH_ArkWebResourceRequest_GetMethod()

```
void OH_ArkWebResourceRequest_GetMethod (const ArkWeb_ResourceRequest * resourceRequest, char ** method )
```
**Description**

Obtains the method of a request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 
| method | The method of an HTTP request. This function allocates memory for the **method** string. You should use **OH_ArkWeb_ReleaseString** to release the string.| 


### OH_ArkWebResourceRequest_GetReferrer()

```
void OH_ArkWebResourceRequest_GetReferrer (const ArkWeb_ResourceRequest * resourceRequest, char ** referrer )
```
**Description**

Obtains the **Referrer** of a request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 
| referrer | The **Referrer** of a request. This function allocates memory for the **Referrer** string. You should use **OH_ArkWeb_ReleaseString** to release the string.| 

### OH_ArkWebResourceRequest_GetRequestHeaders()

```
void OH_ArkWebResourceRequest_GetRequestHeaders (const ArkWeb_ResourceRequest * resourceRequest, ArkWeb_RequestHeaderList ** requestHeaderList )
```
**Description**

Obtains the **OH_ArkWeb_RequestHeaderList** of a request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 
| requestHeaderList | The list of request headers.| 


### OH_ArkWebResourceRequest_GetResourceType()

```
int32_t OH_ArkWebResourceRequest_GetResourceType (const ArkWeb_ResourceRequest * resourceRequest)
```
**Description**

Obtains the resource type of a request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 

**Returns**

Returns the resource type of the request. If **resourceRequest** is invalid, the value is -1.


### OH_ArkWebResourceRequest_GetUrl()

```
void OH_ArkWebResourceRequest_GetUrl (const ArkWeb_ResourceRequest * resourceRequest, char ** url )
```
**Description**

Obtains the URL of a request.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 
| url | The URL of a request. This function allocates memory for the URL string. You should release the string using **OH_ArkWeb_ReleaseString**.| 


### OH_ArkWebResourceRequest_GetUserData()

```
void* OH_ArkWebResourceRequest_GetUserData (const ArkWeb_ResourceRequest * resourceRequest)
```
**Description**

Obtains user data from **ArkWeb_ResourceRequest**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 

**Returns**

Returns the user data.


### OH_ArkWebResourceRequest_HasGesture()

```
bool OH_ArkWebResourceRequest_HasGesture (const ArkWeb_ResourceRequest * resourceRequest)
```
**Description**

Determines whether a request is triggered by the user gesture.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 

**Returns**

Returns **true** if this is triggered by a user gesture; otherwise returns false.


### OH_ArkWebResourceRequest_IsMainFrame()

```
bool OH_ArkWebResourceRequest_IsMainFrame (const ArkWeb_ResourceRequest * resourceRequest)
```
**Description**

Determines whether a request is from the main frame.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 

**Returns**

Returns **true** if this is from the main framework; otherwise returns **false**.


### OH_ArkWebResourceRequest_IsRedirect()

```
bool OH_ArkWebResourceRequest_IsRedirect (const ArkWeb_ResourceRequest * resourceRequest)
```
**Description**

Determines whether a request is redirect.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 

**Returns**

If this is a redirection, **true** is returned. Otherwise, **false** is returned.


### OH_ArkWebResourceRequest_SetUserData()

```
int32_t OH_ArkWebResourceRequest_SetUserData (ArkWeb_ResourceRequest * resourceRequest, void * userData )
```
**Description**

Sets user data to the **ArkWeb_ResourceRequest** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| resourceRequest | ArkWeb_ResourceRequest. | 
| userData | The user data to be set. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResponse_GetCharset()

```
void OH_ArkWebResponse_GetCharset (const ArkWeb_Response * response, char ** charset )
```
**Description**

Obtains the character set of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| charset | The character set of **ArkWeb_Response**. This function allocates memory for the **charset** string. You need to release the string using **OH_ArkWeb_ReleaseString**.| 


### OH_ArkWebResponse_GetError()

```
ArkWeb_NetError OH_ArkWebResponse_GetError (const ArkWeb_Response * response)
```
**Description**

Obtains the error code of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 

**Returns**

The error code of **ArkWeb_Response**.


### OH_ArkWebResponse_GetHeaderByName()

```
void OH_ArkWebResponse_GetHeaderByName (const ArkWeb_Response * response, const char * name, char ** value )
```
**Description**

Obtains the header from **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| name | The name of a header. | 
| value | The value of a header. This function allocates memory for the **value **string. You need to release the string using **OH_ArkWeb_ReleaseString**.| 


### OH_ArkWebResponse_GetMimeType()

```
void OH_ArkWebResponse_GetMimeType (const ArkWeb_Response * response, char ** mimeType )
```
**Description**

Obtains the mime type of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| mimeType | The mime type of **ArkWeb_Response**. This function allocates memory for the **mimeType** string. You need to release the string using **OH_ArkWeb_ReleaseString**.| 


### OH_ArkWebResponse_GetStatus()

```
int OH_ArkWebResponse_GetStatus (const ArkWeb_Response * response)
```
**Description**

Obtains the HTTP status code of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 

**Returns**

The HTTP status code of **ArkWeb_Response**. If **ArkWeb_Response** is invalid, the value is **-1**.


### OH_ArkWebResponse_GetStatusText()

```
void OH_ArkWebResponse_GetStatusText (const ArkWeb_Response * response, char ** statusText )
```
**Description**

Obtains the status text of **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| statusText | The status text of **ArkWeb_Response**. This function allocates memory for the **statusText** string. You need to release the string using **OH_ArkWeb_ReleaseString**.| 


### OH_ArkWebResponse_GetUrl()

```
void OH_ArkWebResponse_GetUrl (const ArkWeb_Response * response, char ** url )
```
**Description**

Obtains the parsed URL that is redirected or changed due to HSTS.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| url | The parsed URL.| 


### OH_ArkWebResponse_SetCharset()

```
int32_t OH_ArkWebResponse_SetCharset (ArkWeb_Response * response, const char * charset )
```
**Description**

Sets the character set for **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| charset | The character set of a request. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResponse_SetError()

```
int32_t OH_ArkWebResponse_SetError (ArkWeb_Response * response, ArkWeb_NetError errorCode )
```
**Description**

Sets an error code for the **ArkWeb_Response** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| errorCode | Error code of a failed request. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResponse_SetHeaderByName()

```
int32_t OH_ArkWebResponse_SetHeaderByName (ArkWeb_Response * response, const char * name, const char * value, bool overwrite )
```
**Description**

Sets a header for **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| name | The name of a header. | 
| value | The value of a header. | 
| overwirte | If the value is **true**, the existing header is overwritten. Otherwise, the existing header is not overwritten. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResponse_SetMimeType()

```
int32_t OH_ArkWebResponse_SetMimeType (ArkWeb_Response * response, const char * mimeType )
```
**Description**

Sets the mime type for **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| mimeType | The mime type of a request. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResponse_SetStatus()

```
int32_t OH_ArkWebResponse_SetStatus (ArkWeb_Response * response, int status )
```
**Description**

Sets an HTTP status code for the **ArkWeb_Response** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| status | The HTTP status code of a request. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResponse_SetStatusText()

```
int32_t OH_ArkWebResponse_SetStatusText (ArkWeb_Response * response, const char * statusText )
```
**Description**

Sets the status text for **ArkWeb_Response**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| statusText | The status text of a request. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebResponse_SetUrl()

```
int32_t OH_ArkWebResponse_SetUrl (ArkWeb_Response * response, const char * url )
```
**Description**

Sets the parsed URL that is redirected or changed due to HSTS. After the setting, redirection is triggered.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| response | ArkWeb_Response. | 
| url | The parsed URL. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebSchemeHandler_GetUserData()

```
void* OH_ArkWebSchemeHandler_GetUserData (const ArkWeb_SchemeHandler * schemeHandler)
```
**Description**

Obtains the user data from **ArkWeb_SchemeHandler**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler. | 

**Returns**

Returns the user data.


### OH_ArkWebSchemeHandler_SetOnRequestStart()

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStart (ArkWeb_SchemeHandler * schemeHandler, ArkWeb_OnRequestStart onRequestStart )
```
**Description**

Sets an **OnRequestStart** callback for **SchemeHandler**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| schemeHandler | The **SchemeHandler** for this scheme. | 
| onRequestStart | The callback function **OnRequestStart**. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebSchemeHandler_SetOnRequestStop()

```
int32_t OH_ArkWebSchemeHandler_SetOnRequestStop (ArkWeb_SchemeHandler * schemeHandler, ArkWeb_OnRequestStop onRequestStop )
```
**Description**

Sets an **OnRequestStop** callback for **SchemeHandler**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| schemeHandler | The **SchemeHandler** for this scheme. | 
| onRequestStop | The callback function **OnRequestStop**. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebSchemeHandler_SetUserData()

```
int32_t OH_ArkWebSchemeHandler_SetUserData (ArkWeb_SchemeHandler * schemeHandler, void * userData )
```
**Description**

Sets a user data to the **ArkWeb_SchemeHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| schemeHandler | ArkWeb_SchemeHandler. | 
| userData | The user data to be set. | 

**Returns**

If **0** is returned, the operation is successful. If **17100101** is returned, the parameter is invalid.


### OH_ArkWebServiceWorker_ClearSchemeHandlers()

```
int32_t OH_ArkWebServiceWorker_ClearSchemeHandlers ()
```
**Description**

Clears the **SchemeHandler** registered for **ServiceWorker**.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Returns**

If the operation is successful, **0** is returned; otherwise, an error code is returned.


### OH_ArkWebServiceWorker_SetSchemeHandler()

```
bool OH_ArkWebServiceWorker_SetSchemeHandler (const char * scheme, ArkWeb_SchemeHandler * schemeHandler )
```
**Description**

Sets an **ArkWeb_SchemeHandler** for a specified scheme to intercept requests of this scheme triggered by **ServiceWorker**.

The **SchemeHandler** should be set after **BrowserContext** is created.

You can use **WebviewController.initializeWebEngine** to initialize **BrowserContext** without creating the ArkWeb component.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| scheme | The scheme to be intercepted. | 
| schemeHandler | The **ArkWeb_SchemeHandler** for this scheme. Only requests triggered by the **ServiceWorker** are notified through this **schemeHandler**. | 

**Returns**

If the **SchemeHandler** is successfully set for the specified scheme, **true** is returned. Otherwise, **false** is returned.


### OH_NativeArkWeb_GetDestroyCallback()

```
NativeArkWeb_OnDestroyCallback OH_NativeArkWeb_GetDestroyCallback (const char * webTag)
```
**Description**

Obtains the callback used when a registered component is destroyed.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| webTag | The name of a \<Web> component. | 

**Returns**

Returns the callback used when a registered component is destroyed.


### OH_NativeArkWeb_GetJavaScriptProxyValidCallback()

```
NativeArkWeb_OnValidCallback OH_NativeArkWeb_GetJavaScriptProxyValidCallback (const char * webTag)
```
**Description**

Obtains the callback used when a registered object is valid.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| webTag | The name of a \<Web> component. | 

**Returns**

Returns the callback used when a registered object is valid.


### OH_NativeArkWeb_RegisterJavaScriptProxy()

```
void OH_NativeArkWeb_RegisterJavaScriptProxy (const char * webTag, const char * objName, const char ** methodList, NativeArkWeb_OnJavaScriptProxyCallback * callback, int32_t size, bool needRefresh )
```
**Description**

Lists the registered objects and function names.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| webTag | The name of a \<Web> component. | 
| objName | The name of the injected object. | 
| methodList | The name of the injected function list. | 
| callback | The injected callback function. | 
| size | The number of the injected callback functions. | 
| needRefresh | Whether a page need to be refreshed.| 


### OH_NativeArkWeb_RunJavaScript()

```
void OH_NativeArkWeb_RunJavaScript (const char * webTag, const char * jsCode, NativeArkWeb_OnJavaScriptCallback callback )
```
**Description**

Runs a piece of JavaScript code in the displaying page.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| webTag | The name of a \<Web> component. | 
| jsCode | A piece of JavaScript code script. | 
| callback | The callback used to notify the result after code is executed.| 


### OH_NativeArkWeb_SetDestroyCallback()

```
void OH_NativeArkWeb_SetDestroyCallback (const char * webTag, NativeArkWeb_OnDestroyCallback callback )
```
**Description**

Sets a callback used when a component is destroyed.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| webTag | The name of a \<Web> component. | 
| callback | The callback used when a component is destroyed.| 


### OH_NativeArkWeb_SetJavaScriptProxyValidCallback()

```
void OH_NativeArkWeb_SetJavaScriptProxyValidCallback (const char * webTag, NativeArkWeb_OnValidCallback callback )
```
**Description**

Sets a callback used when an object is valid.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| webTag | The name of a \<Web> component. | 
| callback | The callback used when an object is valid.| 


### OH_NativeArkWeb_UnregisterJavaScriptProxy()

```
void OH_NativeArkWeb_UnregisterJavaScriptProxy (const char * webTag, const char * objName )
```
**Description**

Deletes a registered object and its callback.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| webTag | The name of a \<Web> component. | 
| objName | The name of the injected object.| 
