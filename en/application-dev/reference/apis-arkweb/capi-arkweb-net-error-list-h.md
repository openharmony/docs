# arkweb_net_error_list.h
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## Overview

The **arkweb_error_code.h** file declares the error codes of the ArkWeb network protocol stack.

**Library**: libohweb.so

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

**Related module**: [Web](capi-web.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ArkWeb_NetError](#arkweb_neterror) | ArkWeb_NetError | Enumerates the error codes of the ArkWeb network protocol stack.|

## Enum Description

### ArkWeb_NetError

```
enum ArkWeb_NetError
```

**Description**

Enumerates the error codes of the ArkWeb network protocol stack.

**System capability**: SystemCapability.Web.Webview.Core

**Since**: 12

| Enumerated Value| Description|
| -- | -- |
| ARKWEB_NET_OK = 0 | The operation is normal.|
| ARKWEB_ERR_IO_PENDING = -1 | The asynchronous I/O operation is pending. This usually does not mean a fatal error. Typically, this error is generated as a notification to wait for an external notification indicating that the I/O operation is finally completed.|
| ARKWEB_ERR_FAILED = -2 | The operation fails.|
| ARKWEB_ERR_ABORTED = -3 | The operation is aborted (due to user operation).|
| ARKWEB_ERR_INVALID_ARGUMENT = -4 | The parameter is invalid.|
| ARKWEB_ERR_INVALID_HANDLE = -5 | The handle or file descriptor is invalid.|
| ARKWEB_ERR_FILE_NOT_FOUND = -6 | The file or directory cannot be found.|
| ARKWEB_ERR_TIMED_OUT = -7 | The operation times out.|
| ARKWEB_ERR_FILE_TOO_LARGE = -8 | The file is too large.|
| ARKWEB_ERR_UNEXPECTED = -9 | An unexpected error occurs. This may be caused by programming errors or invalid assumptions.|
| ARKWEB_ERR_ACCESS_DENIED = -10 | Access to non-network resources is denied.|
| ARKWEB_ERR_NOT_IMPLEMENTED = -11 | The operation fails because the feature is not implemented.|
| ARKWEB_ERR_INSUFFICIENT_RESOURCES = -12 | Resources are insufficient to complete the operation.|
| ARKWEB_ERR_OUT_OF_MEMORY = -13 | A memory overflow occurs.|
| ARKWEB_ERR_UPLOAD_FILE_CHANGED = -14 | The file fails to be loaded because its modification time is not as expected.|
| ARKWEB_ERR_SOCKET_NOT_CONNECTED = -15 | The socket is not connected.|
| ARKWEB_ERR_FILE_EXISTS = -16 | The file already exists.|
| ARKWEB_ERR_FILE_PATH_TOO_LONG = -17 | The file path or file name is too long.|
| ARKWEB_ERR_FILE_NO_SPACE = -18 | The disk space is insufficient.|
| ARKWEB_ERR_FILE_VIRUS_INFECTED = -19 | The file is infected.|
| ARKWEB_ERR_BLOCKED_BY_CLIENT = -20 | The request is blocked by the client.|
| ARKWEB_ERR_NETWORK_CHANGED = -21 | The network changes.|
| ARKWEB_ERR_BLOCKED_BY_ADMINISTRATOR = -22 | The request is blocked by the URL blocking list configured by the domain administrator.|
| ARKWEB_ERR_SOCKET_CONNECTED = -23 | The socket is connected.|
| ARKWEB_ERR_UPLOAD_STREAM_REWIND_NOT_SUPPORTED = -25 | The upload stream must be rewound for retry or redirection, but the upload fails because rewinding is not supported.|
| ARKWEB_ERR_CONTEXT_SHUT_DOWN = -26 | The request fails because **URLRequestContext** is shut down or being shut down.|
| ARKWEB_ERR_BLOCKED_BY_RESPONSE = -27 | The request is blocked by response from headers such as X-Frame-Options, Content Security Policy, and Cross Origin Resource Policy.|
| ARKWEB_ERR_CLEARTEXT_NOT_PERMITTED = -29 | The request is blocked because some or all cleartext requests are not permitted by the system policy.|
| ARKWEB_ERR_BLOCKED_BY_CSP = -30 | The request is blocked by the Content Security Policy.|
| ARKWEB_ERR_H2_OR_QUIC_REQUIRED = -31 | The request is blocked because there is no H/2 or QUIC session.|
| ARKWEB_ERR_BLOCKED_BY_ORB = -32 | The request is blocked by Cross-Origin Read Blocking (CORB) or ORB.|
| ARKWEB_ERR_CONNECTION_CLOSED = -100 | The connection is closed, which corresponds to **TCP FIN**.|
| ARKWEB_ERR_CONNECTION_RESET = -101 | The connection is reset, which corresponds to **TCP RST**.|
| ARKWEB_ERR_CONNECTION_REFUSED = -102 | The connection is refused.|
| ARKWEB_ERR_CONNECTION_ABORTED = -103 | The connection is aborted because the ACK for sending data is not received. This may include FIN packets.|
| ARKWEB_ERR_CONNECTION_FAILED = -104 | The connection failed.|
| ARKWEB_ERR_NAME_NOT_RESOLVED = -105 | The domain name cannot be resolved.|
| ARKWEB_ERR_INTERNET_DISCONNECTED = -106 | The Internet is disconnected.|
| ARKWEB_ERR_SSL_PROTOCOL_ERROR = -107 | An SSL protocol error occurs.|
| ARKWEB_ERR_ADDRESS_INVALID = -108 | The IP address or port number is invalid (for example, IP address 0 or port 0 cannot be connected).|
| ARKWEB_ERR_ADDRESS_UNREACHABLE = -109 | The IP address cannot be accessed. This means that there is no route to the specified host or network.|
| ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NEEDED = -110 | The server needs SSL client authentication certificate.|
| ARKWEB_ERR_TUNNEL_CONNECTION_FAILED = -111 | The tunnel connection failed to be established through the proxy.|
| ARKWEB_ERR_NO_SSL_VERSIONS_ENABLED = -112 | No SSL protocol version is enabled.|
| ARKWEB_ERR_SSL_VERSION_OR_CIPHER_MISMATCH = -113 | The client and server do not support the common SSL protocol version or cipher suite.|
| ARKWEB_ERR_SSL_RENEGOTIATION_REQUESTED = -114 | The server requests re-negotiation (re-handshake).|
| ARKWEB_ERR_PROXY_AUTH_UNSUPPORTED = -115 | The proxy requests authentication for establishing a tunnel, but the method used is not supported.|
| ARKWEB_ERR_BAD_SSL_CLIENT_AUTH_CERT = -117 | The SSL handshake fails because the client certificate is incorrect or missing.|
| ARKWEB_ERR_CONNECTION_TIMED_OUT = -118 | The connection times out.|
| ARKWEB_ERR_HOST_RESOLVER_QUEUE_TOO_LARGE = -119 | There are too many DNS resolutions to be processed, and one of the requests in the queue is terminated.|
| ARKWEB_ERR_SOCKS_CONNECTION_FAILED = -120 | The connection between the target host and the SOCKS proxy server failed.|
| ARKWEB_ERR_SOCKS_CONNECTION_HOST_UNREACHABLE = -121 | The SOCKS proxy server cannot connect to the target host because the target host is unreachable.|
| ARKWEB_ERR_ALPN_NEGOTIATION_FAILED = -122 | The request of ALPN failed.|
| ARKWEB_ERR_SSL_NO_RENEGOTIATION = -123 | The peer sent an **SSL no_regregation** alert message.|
| ARKWEB_ERR_WINSOCK_UNEXPECTED_WRITTEN_BYTES = -124 | Winsock sometimes reports unexpected written bytes. This may be caused by LSP damage.|
| ARKWEB_ERR_SSL_DECOMPRESSION_FAILURE_ALERT = -125 | The SSL peer sent us a fatal **decompression_failure** alert. This usually occurs when the peer falsely considers that it supports **DEFLATE** and selects it.|
| ARKWEB_ERR_SSL_BAD_RECORD_MAC_ALERT = -126 | The SSL peer sent us a fatal **BAD_RECORD_MAC** alert. This usually occurs on the server cannot support **DEFLATE** normally.|
| ARKWEB_ERR_PROXY_AUTH_REQUESTED = -127 | The proxy requests authentication for establishing a tunnel.|
| ARKWEB_ERR_PROXY_CONNECTION_FAILED = -130 | The connection to the proxy server fails. This is because an error occurs when the host resolves the name or connects its socket to the proxy server. Note that this does not include errors during the **HTTP CONNECT**.|
| ARKWEB_ERR_MANDATORY_PROXY_CONFIGURATION_FAILED = -131 | The mandatory proxy configuration failed. Currently, this means that a mandatory PAC script cannot be obtained, parsed, or executed.|
| ARKWEB_ERR_PRECONNECT_MAX_SOCKET_LIMIT = -133 | The maximum socket limit of the socket pool is reached during pre-connect. No more sockets need to be pre-connected.|
| ARKWEB_ERR_SSL_CLIENT_AUTH_PRIVATE_KEY_ACCESS_DENIED = -134 | The access to the private key of the SSL client certificate is denied.|
| ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_NO_PRIVATE_KEY = -135 | The SSL client certificate does not have a private key.|
| ARKWEB_ERR_PROXY_CERTIFICATE_INVALID = -136 | The certificate provided by the HTTPS proxy is invalid.|
| ARKWEB_ERR_NAME_RESOLUTION_FAILED = -137 | The name (DNS) resolution failed.|
| ARKWEB_ERR_NETWORK_ACCESS_DENIED = -138 | The access to the network is denied. This error is distinguished from errors that are likely to be caused by firewalls and other errors caused by denied access. For details, see **ERR_ACCESS_DENIED**.|
| ARKWEB_ERR_TEMPORARILY_THROTTLED = -139 | The request is temporarily throttled to avoid DDoS attacks.|
| ARKWEB_ERR_HTTPS_PROXY_TUNNEL_RESPONSE_REDIRECT = -140 | The request for creating an SSL tunnel connection through the HTTPS proxy receives a 302 (temporary redirection) response. The response body may contain the description of the failure cause.|
| ARKWEB_ERR_SSL_CLIENT_AUTH_SIGNATURE_FAILED = -141 | The **CertificateVerify** data of the SSL client authentication handshake cannot be signed using the private key of the client certificate.|
| ARKWEB_ERR_MSG_TOO_BIG = -142 | The message is too big to transfer. (For example, the UDP message exceeds the size limit).|
| ARKWEB_ERR_WS_PROTOCOL_ERROR = -145 | The WebSocket protocol is incorrect. This indicates that the connection is terminating due to a frame format error or other protocol violation.|
| ARKWEB_ERR_ADDRESS_IN_USE = -147 | The address is in use.|
| ARKWEB_ERR_SSL_HANDSHAKE_NOT_COMPLETED = -148 | The operation failed because the SSL handshake is not completed.|
| ARKWEB_ERR_SSL_BAD_PEER_PUBLIC_KEY = -149 | The public key of the SSL peer is invalid.|
| ARKWEB_ERR_SSL_PINNED_KEY_NOT_IN_CERT_CHAIN = -150 | The certificate does not match the built-in public key Pins of the host name. Pin is set in **net/http/transport_security_state.cc**, and it is required that one of a set of public keys exist on the path from the leaf node to the root node.|
| ARKWEB_ERR_CLIENT_AUTH_CERT_TYPE_UNSUPPORTED = -151 | The server requests the client certificate, but the request does not contain any of the certificates we support.|
| ARKWEB_ERR_SSL_DECRYPT_ERROR_ALERT = -153 | The SSL peer sent us a fatal **DECRYPT_ERROR** alert. This usually occurs when the peer cannot verify the signature (in **CertificateVerify** or **ServerKeyExchange**) or verify the **Finished** message.|
| ARKWEB_ERR_WS_THROTTLE_QUEUE_TOO_LARGE = -154 | There are too many **WebSocketJob** instances to be processed. Therefore, new tasks are not pushed to the queue.|
| ARKWEB_ERR_SSL_SERVER_CERT_CHANGED = -156 | During the renegotiation, the SSL server certificate is changed.|
| ARKWEB_ERR_SSL_UNRECOGNIZED_NAME_ALERT = -159 | The SSL server sends us a fatal **unrecognized_name** alert.|
| ARKWEB_ERR_SOCKET_SET_RECEIVE_BUFFER_SIZE_ERROR = -160 | The size of the socket receive buffer cannot be set as requested.|
| ARKWEB_ERR_SOCKET_SET_SEND_BUFFER_SIZE_ERROR = -161 | The size of the socket send buffer cannot be set as requested.|
| ARKWEB_ERR_SOCKET_RECEIVE_BUFFER_SIZE_UNCHANGEABLE = -162 |**setsockopt** returns a success code, but the socket's receive buffer size cannot be set to the requested value.|
| ARKWEB_ERR_SOCKET_SEND_BUFFER_SIZE_UNCHANGEABLE = -163 | **setsockopt** returns a success code, but the socket's send buffer size cannot be set to the requested value.|
| ARKWEB_ERR_SSL_CLIENT_AUTH_CERT_BAD_FORMAT = -164 | The client certificate cannot be imported into the SSL library from the platform store.|
| ARKWEB_ERR_ICANN_NAME_COLLISION = -166 | When a host name is resolved to an IP address list, the IPv4 address **127.0.53.53** is included. This is a special IP address recommended by ICANN. It is used to indicate a name conflict and remind administrators of potential problems.|
| ARKWEB_ERR_SSL_SERVER_CERT_BAD_FORMAT = -167 | The SSL server provides a certificate that cannot be decoded. This is not a certificate error code because no **X509Certificate** object is available. This error is fatal.|
| ARKWEB_ERR_CT_STH_PARSING_FAILED = -168 | Certificate Transparency: The received **Signed Tree Head** cannot be parsed.|
| ARKWEB_ERR_CT_STH_INCOMPLETE = -169 | Certificate transparency: The received **Signed Tree Head** can be successfully parsed into JSON, but some fields are missing.|
| ARKWEB_ERR_UNABLE_TO_REUSE_CONNECTION_FOR_PROXY_AUTH = -170 | The connection to send proxy authentication credentials cannot be reused before **AuthController** is start. The caller should reconnect the **AuthController**. This error is only used internally in the network stack.|
| ARKWEB_ERR_CT_CONSISTENCY_PROOF_PARSING_FAILED = -171 | Certificate transparency: The received consistency proof cannot be parsed.|
| ARKWEB_ERR_SSL_OBSOLETE_CIPHER = -172 | The SSL server requires an obsolete cipher suite. In one or two version updates after this cipher suite is removed, as a rollback policy, this error is temporarily signaled and then the rollback policy is removed.|
| ARKWEB_ERR_WS_UPGRADE = -173 | This error code is used to cancel the **URLRequest** when the WebSocket handshake is successful and the connection has been upgraded.|
| ARKWEB_ERR_READ_IF_READY_NOT_IMPLEMENTED = -174 |  The socket **ReadIfReady** is not implemented. This error should not be seen by the user because the normal **Read** method will be used as an alternative.|
| ARKWEB_ERR_NO_BUFFER_SPACE = -176 | No socket buffer space is available.|
| ARKWEB_ERR_SSL_CLIENT_AUTH_NO_COMMON_ALGORITHMS = -177 | There is no common signing algorithm between the private key of the client certificate and the preferences of the server.|
| ARKWEB_ERR_EARLY_DATA_REJECTED = -178 | The server rejected TLS 1.3 Early Data. This error will be received before any data is returned from the socket. Early Data should be disabled and the request should be retried.|
| ARKWEB_ERR_WRONG_VERSION_ON_EARLY_DATA = -179 | The server responds with TLS 1.2 or earlier when TLS 1.3 Early Data is provided. This is an internal error code to solve the backward compatibility problem between Early Data and TLS 1.2.|
| ARKWEB_ERR_TLS13_DOWNGRADE_DETECTED = -180 | The server negotiated an earlier version when TLS 1.3 is supported.|
| ARKWEB_ERR_SSL_KEY_USAGE_INCOMPATIBLE = -181 |  The server's certificate has a keyUsage extension that is incompatible with the negotiated TLS key exchange method.|
| ARKWEB_ERR_INVALID_ECH_CONFIG_LIST = -182 | The **ECHConfigList** obtained through DNS cannot be resolved.|
| ARKWEB_ERR_ECH_NOT_NEGOTIATED = -183 | **Encrypted Client Hello (ECH)** is enabled, but the server cannot decrypt the encrypted **ClientHello**.|
| ARKWEB_ERR_ECH_FALLBACK_CERTIFICATE_INVALID = -184 | **Encrypted Client Hello (ECH)** is enabled, but the server cannot decrypt the encrypted **ClientHello** and does not provide a certificate valid for the public name.|
| ARKWEB_ERR_CERT_COMMON_NAME_INVALID = -200 | The server responds with a certificate whose common name does not match the host name. The possible causes are: 1. The attacker redirects the traffic to its server and presents a certificate that they know the private key.|
| ARKWEB_ERR_CERT_DATE_INVALID = -201 | The server responds with a certificate, but according to the host clock, the certificate does not take effect or is expired. The possible causes are: 1. The attacker provides an old certificate and obtains the private key.2. The server is incorrectly configured and no valid certificate is provided.3. The host clock is wrong.|
| ARKWEB_ERR_CERT_AUTHORITY_INVALID = -202 | The server responds with a certificate signed by an authority that we do not trust. The possible causes are: 1. The attacker replaces the real certificate with a certificate that contains its public key and is signed by its associates.|
| ARKWEB_ERR_CERT_CONTAINS_ERRORS = -203 | The certificate returned by the server contains an error, which cannot be rectified. MSDN describes this error as "The SSL certificate contains an error". Note: It is not clear how this error differs from **ERR_CERT_INVALID**.|
| ARKWEB_ERR_CERT_NO_REVOCATION_MECHANISM = -204 | The certificate does not have a revocation mechanism. In other words, this certificate cannot be revoked.|
| ARKWEB_ERR_CERT_UNABLE_TO_CHECK_REVOCATION = -205 | Revocation information for this website's security certificate is not available. The possible causes are: 1. The attacker has cracked the private key in the certificate and prevented the host from finding out that the certificate is revoked.2. The certificate is not revoked, but the revocation server is busy or unavailable.|
| ARKWEB_ERR_CERT_REVOKED = -206 | The certificate responded by the server is revoked. This error could but not should be ignored.|
| ARKWEB_ERR_CERT_INVALID = -207 | The server responds with an invalid certificate. This error cannot be rectified. MSDN describes this error as follows: "The SSL certificate is invalid." |
| ARKWEB_ERR_CERT_WEAK_SIGNATURE_ALGORITHM = -208 | The server responds with a certificate signed using a weak signing algorithm.|
| ARKWEB_ERR_CERT_NON_UNIQUE_NAME = -210 | The host name specified in the certificate is not unique.|
| ARKWEB_ERR_CERT_WEAK_KEY = -211 | The server responds with a certificate containing a weak key (for example, a too small RSA key).|
| ARKWEB_ERR_CERT_NAME_CONSTRAINT_VIOLATION = -212 | The **DNS** name declared in the certificate violates the name constraint.|
| ARKWEB_ERR_CERT_VALIDITY_TOO_LONG = -213 | The validity period of the certificate is too long.|
| ARKWEB_ERR_CERTIFICATE_TRANSPARENCY_REQUIRED = -214 | Certificate Transparency is required, but the server does not provide CT information that complies with the policy.|
| ARKWEB_ERR_CERT_SYMANTEC_LEGACY = -215 | The certificate is linked to an old Symantec certificate or its subsidiaries that are no longer trusted.|
| ARKWEB_ERR_CERT_KNOWN_INTERCEPTION_BLOCKED = -217 |The certificate is intercepted by an entity other than the device owner.|
| ARKWEB_ERR_SSL_OBSOLETE_VERSION_OR_CIPHER = -218 | The connection uses an obsolete version of SSL/TLS or an encryption algorithm.|
| ARKWEB_ERR_CERT_END = -219 | The error immediately follows the last certificate error code.|
| ARKWEB_ERR_INVALID_URL = -300 | The URL is invalid.|
| ARKWEB_ERR_DISALLOWED_URL_SCHEME = -301 | The URL scheme is not allowed.|
| ARKWEB_ERR_UNKNOWN_URL_SCHEME = -302 | The URL scheme is unknown.|
| ARKWEB_ERR_INVALID_REDIRECT = -303 | An invalid URL redirection occurs when a URL is loaded.|
| ARKWEB_ERR_TOO_MANY_REDIRECTS = -310 | Too many URL redirections occurred when a URL is being loaded.|
| ARKWEB_ERR_UNSAFE_REDIRECT = -311 | An insecure URL redirection occurs when a URL is loaded (for example, redirection to **file://** is considered insecure).|
| ARKWEB_ERR_UNSAFE_PORT = -312 | The port number of the URL to be loaded is unsafe.|
| ARKWEB_ERR_INVALID_RESPONSE = -320 | The response from the server is invalid.|
| ARKWEB_ERR_INVALID_CHUNKED_ENCODING = -321 | The chunked encoding is invalid.|
| ARKWEB_ERR_METHOD_UNSUPPORTED = -322 | The server does not support the request method.|
| ARKWEB_ERR_UNEXPECTED_PROXY_AUTH = -323 | The response value is **407**, indicating proxy authentication is required, but the host does not send the request to the proxy.|
| ARKWEB_ERR_EMPTY_RESPONSE = -324 | The server closes the connection and does not response.|
| ARKWEB_ERR_RESPONSE_HEADERS_TOO_BIG = -325 | The response headers are too big.|
| ARKWEB_ERR_PAC_SCRIPT_FAILED = -327 | The PAC script failed.|
| ARKWEB_ERR_REQUEST_RANGE_NOT_SATISFIABLE = -328 | The response code is 416, indicating the server cannot meet the request range.|
| ARKWEB_ERR_MALFORMED_IDENTITY = -329 | The identity is malformed.|
| ARKWEB_ERR_CONTENT_DECODING_FAILED = -330 | The content decoding of the response body failed.|
| ARKWEB_ERR_NETWORK_IO_SUSPENDED = -331 | The operation failed because all network I/Os are suspended.|
| ARKWEB_ERR_SYN_REPLY_NOT_RECEIVED = -332 | FLIP data is received before **SYN_REPLY** is received on the flow.|
| ARKWEB_ERR_ENCODING_CONVERSION_FAILED = -333 | The response failed to be converted to the target encoding.|
| ARKWEB_ERR_UNRECOGNIZED_FTP_DIRECTORY_LISTING_FORMAT = -334 | The server sent an unrecognized FTP directory listing format.|
| ARKWEB_ERR_NO_SUPPORTED_PROXIES = -336 | There are no supported proxies in the list provided.|
| ARKWEB_ERR_HTTP2_PROTOCOL_ERROR = -337 | An HTTP/2 protocol error occurs.|
| ARKWEB_ERR_INVALID_AUTH_CREDENTIALS = -338 | The HTTP authentication credentials are invalid.|
| ARKWEB_ERR_UNSUPPORTED_AUTH_SCHEME = -339 | The HTTP authentication scheme is not supported.|
| ARKWEB_ERR_ENCODING_DETECTION_FAILED = -340 | The encoding detection failed.|
| ARKWEB_ERR_MISSING_AUTH_CREDENTIALS = -341 | (GSSAPI) The Kerberos credentials of HTTP authentication are missing.|
| ARKWEB_ERR_UNEXPECTED_SECURITY_LIBRARY_STATUS = -342 | The SSPI or GSSAPI status code is unexpected.|
| ARKWEB_ERR_MISCONFIGURED_AUTH_ENVIRONMENT = -343 | The authentication environment is misconfigured. (For example, the KDC cannot be found or the principal is unknown).|
| ARKWEB_ERR_UNDOCUMENTED_SECURITY_LIBRARY_STATUS = -344 | The SSPI or GSSAPI status code is undocumented.|
| ARKWEB_ERR_RESPONSE_BODY_TOO_BIG_TO_DRAIN = -345 | The HTTP response body is too big to drain.|
| ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_LENGTH = -346 | Multiple Content-Length response headers are included in an HTTP response.|
| ARKWEB_ERR_INCOMPLETE_HTTP2_HEADERS = -347 | The HTTP/2 response headers are incomplete. Therefore, more frames are needed to complete them.|
| ARKWEB_ERR_PAC_NOT_IN_DHCP = -348 | The PAC URL configuration cannot be retrieved from DHCP. This may indicate that the retrieving failed, or that the PAC URL is not configured in DHCP.|
| ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_DISPOSITION = -349 | Multiple **Content-Disposition** headers are included in an HTTP response.|
| ARKWEB_ERR_RESPONSE_HEADERS_MULTIPLE_LOCATION = -350 | Multiple **Location** headers are included in an HTTP response.|
| ARKWEB_ERR_HTTP2_SERVER_REFUSED_STREAM = -351 | The HTTP/2 server rejects the request without processing it and sends a **GOAWAY** frame with the error code **NO_ERROR** and a **Last-Stream-ID** lower than the stream ID of the request.|
| ARKWEB_ERR_HTTP2_PING_FAILED = -352 | The HTTP/2 server does not respond to the **PING**.|
| ARKWEB_ERR_CONTENT_LENGTH_MISMATCH = -354 | When the connection is closed, the number of bytes transmitted in the HTTP response body is less than the number of bytes advertised in the **Content-Length** header.|
| ARKWEB_ERR_INCOMPLETE_CHUNKED_ENCODING = -355 | The HTTP response body is transmitted using chunked encoding, and the terminated zero-length block is not sent when the connection is closed.|
| ARKWEB_ERR_QUIC_PROTOCOL_ERROR = -356 | A QUIC protocol error occurs.|
| ARKWEB_ERR_RESPONSE_HEADERS_TRUNCATED = -357 | The HTTP response headers are truncated by the end of file (EOF).|
| ARKWEB_ERR_QUIC_HANDSHAKE_FAILED = -358 | The QUIC encryption handshake failed. This means that the server cannot read any requests, so they may be resent.|
| ARKWEB_ERR_HTTP2_INADEQUATE_TRANSPORT_SECURITY = -360 | The transport security is inadequate to HTTP/2.|
| ARKWEB_ERR_HTTP2_FLOW_CONTROL_ERROR = -361 | The peer violates HTTP/2 flow control.|
| ARKWEB_ERR_HTTP2_FRAME_SIZE_ERROR = -362 | The peer sends an HTTP/2 frame with an incorrect size.|
| ARKWEB_ERR_HTTP2_COMPRESSION_ERROR = -363 | The decoding or encoding of the compressed HTTP/2 response header information failed.|
| ARKWEB_ERR_PROXY_AUTH_REQUESTED_WITH_NO_CONNECTION = -364 | The proxy authentication of a request does not have a valid client socket handle.|
| ARKWEB_ERR_HTTP_1_1_REQUIRED = -365 | The HTTP/2 session receives an **HTTP_1_1_REQUIRED** error code.|
| ARKWEB_ERR_PROXY_HTTP_1_1_REQUIRED = -366 | The **HTTP_1_1_REQUIRED** error code is received when the HTTP/2 session proxy is used.|
| ARKWEB_ERR_PAC_SCRIPT_TERMINATED = -367 | The PAC script has been terminated and must be reloaded.|
| ARKWEB_ERR_INVALID_HTTP_RESPONSE = -370 | The server should return an **HTTP/1.x** response. But it returns an **HTTP/0.9** response.|
| ARKWEB_ERR_CONTENT_DECODING_INIT_FAILED = -371 | The content decoding fails to be initialized.|
| ARKWEB_ERR_HTTP2_RST_STREAM_NO_ERROR_RECEIVED = -372 | An **HTTP/2 RST_STREAM** frame with **NO_ERROR** is received. This error should be handled internally by HTTP/2 and should not exceed the SpdyStream layer.|
| ARKWEB_ERR_HTTP2_PUSHED_STREAM_NOT_AVAILABLE = -373 | The pushed stream claimed by the request is not available.|
| ARKWEB_ERR_HTTP2_CLAIMED_PUSHED_STREAM_RESET_BY_SERVER = -374 | The claimed pushed stream is reset by the server. In this case, the request should be retried.|
| ARKWEB_ERR_TOO_MANY_RETRIES = -375 | There are too many retries due to invalid authentication or certificate.|
| ARKWEB_ERR_HTTP2_STREAM_CLOSED = -376 | An HTTP/2 frame is received on the closed stream.|
| ARKWEB_ERR_HTTP2_CLIENT_REFUSED_STREAM = -377 | The client refuses an HTTP/2 stream.|
| ARKWEB_ERR_HTTP2_PUSHED_RESPONSE_DOES_NOT_MATCH = -378 | Based on the matched URL and request header, an HTTP/2 pushed stream is received by the request, but the pushed response header does not match the request.|
| ARKWEB_ERR_HTTP_RESPONSE_CODE_FAILURE = -379 | The server returns a non-2xx HTTP response code.|
| ARKWEB_ERR_QUIC_UNKNOWN_CERT_ROOT = -380 | The certificate displayed on the QUIC connection is not linked to a known root certificate, and the connected original server is not in the list of domain names that allow unknown root certificates.|
| ARKWEB_ERR_QUIC_GOAWAY_REQUEST_CAN_BE_RETRIED = -381 | A **GOAWAY** frame has been received, indicating that the request has not been processed and therefore can be safely retried on a different connection.|
| ARKWEB_ERR_TOO_MANY_ACCEPT_CH_RESTARTS = -382 | **ACCEPT_CH_RESTARTS** has been triggered too many times.|
| ARKWEB_ERR_INCONSISTENT_IP_ADDRESS_SPACE = -383 | In the same request, the IP address space of the remote endpoint is different from the previous one. Cache entries for any affected requests should be marked as invalid.|
| ARKWEB_ERR_CACHED_IP_ADDRESS_SPACE_BLOCKED_BY_LOCAL_NETWORK_ACCESS_POLICY = -384 | The cached IP address space of the remote endpoint is blocked by a local network access policy.|
| ARKWEB_ERR_CACHE_MISS = -400 | The entry for the request is not in the cache.|
| ARKWEB_ERR_CACHE_READ_FAILURE = -401 | The entry cannot be read from the cache.|
| ARKWEB_ERR_CACHE_WRITE_FAILURE = -402 | The entry cannot be written to the cache.|
| ARKWEB_ERR_CACHE_OPERATION_UNSUPPORTED = -403 | The entry does not support this operation.|
| ARKWEB_ERR_CACHE_OPEN_FAILURE = -404 | The cache could not open this entry.|
| ARKWEB_ERR_CACHE_CREATE_FAILURE = -405 | The cache could not create this entry.|
| ARKWEB_ERR_CACHE_RACE = -406 | Multiple transactions are competing to create disk cache entries.|
| ARKWEB_ERR_CACHE_CHECKSUM_READ_FAILURE = -407 | The cache could not read the checksum on the entry.|
| ARKWEB_ERR_CACHE_CHECKSUM_MISMATCH = -408 | An entry with an invalid checksum is found in the cache.|
| ARKWEB_ERR_CACHE_LOCK_TIMEOUT = -409 | The HTTP cache contains an error code.|
| ARKWEB_ERR_CACHE_AUTH_FAILURE_AFTER_READ = -410 | A challenge is received after the transaction reads some data, but the credentials are unavailable.|
| ARKWEB_ERR_CACHE_ENTRY_NOT_SUITABLE = -411 | An internal non-standard error code used for the HTTP cache.|
| ARKWEB_ERR_CACHE_DOOM_FAILURE = -412 | The cache cannot delete this entry.|
| ARKWEB_ERR_CACHE_OPEN_OR_CREATE_FAILURE = -413 | The cache cannot open or create the entry.|
| ARKWEB_ERR_INSECURE_RESPONSE = -501 | The server response is insecure (for example, there is a certificate error).|
| ARKWEB_ERR_NO_PRIVATE_KEY_FOR_CERT = -502 | The client certificate failed to be imported because the user's key database does not have a private key.|
| ARKWEB_ERR_ADD_USER_CERT_FAILED = -503 | The certificate failed to be added to the OS certificate database.|
| ARKWEB_ERR_INVALID_SIGNED_EXCHANGE = -504 | The signed exchange is invalid.|
| ARKWEB_ERR_INVALID_WEB_BUNDLE = -505 | The web bundle resources are invalid.|
| ARKWEB_ERR_TRUST_TOKEN_OPERATION_FAILED = -506 | The request for performing the Trust Tokens protocol operation failed. The possible causes include prerequisite failure, internal error, and bad response.|
| ARKWEB_ERR_TRUST_TOKEN_OPERATION_SUCCESS_WITHOUT_SENDING_REQUEST = -507 | When processing an operation execution request related to the Trust Tokens protocol, the system performs the Trust Tokens operation in the request, but does not send the request to the specified destination.|
| ARKWEB_ERR_FTP_FAILED = -601 | The FTP control connection command failed. If possible, replace this error code with a more specific one.|
| ARKWEB_ERR_FTP_SERVICE_UNAVAILABLE = -602 | The server cannot support the request. This is a temporary error. The FTP response code is 421.|
| ARKWEB_ERR_FTP_TRANSFER_ABORTED = -603 | The server aborts the transfer. The FTP response code is 426.|
| ARKWEB_ERR_FTP_FILE_BUSY = -604 | The file is in use, or some other temporary errors occur when the file is opened. The FTP response code is 450.|
| ARKWEB_ERR_FTP_SYNTAX_ERROR = -605 | The server rejects the command from the host due to a syntax error. The FTP response code is 500 or 501.|
| ARKWEB_ERR_FTP_COMMAND_UNSUPPORTED = -606 | The server does not support the command. The FTP response code is 502 or 504.|
| ARKWEB_ERR_FTP_BAD_COMMAND_SEQUENCE = -607 | The server rejects the commands from the host because the host does not send the commands in the correct sequence. The FTP response code is 503.|
| ARKWEB_ERR_PKCS12_IMPORT_BAD_PASSWORD = -701 | The **PKCS \#12** file cannot be imported because the password is incorrect.|
| ARKWEB_ERR_PKCS12_IMPORT_FAILED = -702 | The **PKCS \#12** file cannot be imported due to other errors.|
| ARKWEB_ERR_IMPORT_CA_CERT_NOT_CA = -703 | The CA certificate cannot be imported because it is not a real CA certificate.|
| ARKWEB_ERR_IMPORT_CERT_ALREADY_EXISTS = -704 | The certificate cannot be imported because it already exists in the database.|
| ARKWEB_ERR_IMPORT_CA_CERT_FAILED = -705 | The CA failed to be imported due to other errors.|
| ARKWEB_ERR_IMPORT_SERVER_CERT_FAILED = -706 | The server certificate failed to be imported due to some internal errors.|
| ARKWEB_ERR_PKCS12_IMPORT_INVALID_MAC = -707 | The **PKCS \#12** file failed to be imported because the message authentication code (MAC) is invalid.|
| ARKWEB_ERR_PKCS12_IMPORT_INVALID_FILE = -708 | The **PKCS \#12** file failed to be imported because the file is invalid or corrupted.|
| ARKWEB_ERR_PKCS12_IMPORT_UNSUPPORTED = -709 | The **PKCS \#12** file failed to be imported due to its unsupported features.|
| ARKWEB_ERR_KEY_GENERATION_FAILED = -710 | The key generation failed.|
| ARKWEB_ERR_PRIVATE_KEY_EXPORT_FAILED = -712 | The private key failed to be exported.|
| ARKWEB_ERR_SELF_SIGNED_CERT_GENERATION_FAILED = -713 | The self-signed certificate failed to be generated.|
| ARKWEB_ERR_CERT_DATABASE_CHANGED = -714 | The certificate database is changed.|
| ARKWEB_ERR_CERT_VERIFIER_CHANGED = -716 | The certificate verifier configuration is changed.|
| ARKWEB_ERR_DNS_MALFORMED_RESPONSE = -800 | The DNS resolver receives a response that the format is incorrect.|
| ARKWEB_ERR_DNS_SERVER_REQUIRES_TCP = -801 | The DNS server requires TCP.|
| ARKWEB_ERR_DNS_SERVER_FAILED = -802 | The DNS server failed. This error code is returned for all of the following errors: 1 - Format error - The name server cannot interpret the query. 2 - Server failure - The name server cannot process the query due to its own problems. 3 - Not supported - The name server does not support the query type of the request.|
| ARKWEB_ERR_DNS_TIMED_OUT = -803 | The DNS transaction timed out.|
| ARKWEB_ERR_DNS_CACHE_MISS = -804 | The entry is not found in the cache or other local sources.|
| ARKWEB_ERR_DNS_SEARCH_EMPTY = -805 | The suffix search list rule prevents the resolution of a given host name.|
| ARKWEB_ERR_DNS_SORT_ERROR = -806 | Addresses are not sorted according to RFC 3484.|
| ARKWEB_ERR_DNS_SECURE_RESOLVER_HOSTNAME_RESOLUTION_FAILED = -808 | The host name of the DNS-over-HTTPS server cannot be resolved.|
| ARKWEB_ERR_DNS_NAME_HTTPS_ONLY = -809 | DNS has identified that the request is prohibited due to insecure connections (HTTP/WS). The application should handle this error like HTTP redirection, redirecting the connection to secure HTTPS or WSS.|
| ARKWEB_ERR_DNS_REQUEST_CANCELED = -810 | All DNS requests related to this task are canceled.|
| ARKWEB_ERR_DNS_NO_MATCHING_SUPPORTED_ALPN = -811 | The host name resolution of the HTTPS record is not resolved using the ALPN value of the supported protocol.|
