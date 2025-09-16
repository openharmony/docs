# @ohos.web.netErrorList(The List of ArkWeb Network Protocol Stack Errors)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

Provides a list of ArkWeb network protocol stack errors.

The error codes of the ArkWeb network protocol stack are mapped to the Chromium error codes in <!--RP1-->net_error_list.h<!--RP1End-->.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { WebNetErrorList } from '@kit.ArkWeb';
```

## WebNetErrorList

Provides a list of ArkWeb network protocol stack errors.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Value| Description                                     |
| ------------- | -- |----------------------------------------- |
|NET_OK | 0 |  The access is normal. |
|ERR_IO_PENDING | -1 | The asynchronous I/O operation is pending.|
|ERR_FAILED | -2 | A common error occurs.|
|ERR_ABORTED | -3 | The operation is aborted.|
|ERR_INVALID_ARGUMENT | -4 | The parameter is invalid.|
|ERR_INVALID_HANDLE | -5 | The handle of the file descriptor is invalid.|
|ERR_FILE_NOT_FOUND | -6 | The file is not found.|
|ERR_TIMED_OUT | -7 | The operation times out.|
|ERR_FILE_TOO_LARGE | -8 | The file is too large.|
|ERR_UNEXPECTED | -9 | The problem is not expected or specifically handled.|
|ERR_ACCESS_DENIED | -10 | The access to resources other than the network is denied.|
|ERR_NOT_IMPLEMENTED | -11 | The operation fails because the function is not implemented.|
|ERR_INSUFFICIENT_RESOURCES | -12 | The resources required for system or program execution are insufficient.|
|ERR_OUT_OF_MEMORY | -13 | A memory overflow occurs.|
|ERR_UPLOAD_FILE_CHANGED | -14 | The file cannot be uploaded because the file modification time is not as expected.|
|ERR_SOCKET_NOT_CONNECTED | -15 | The socket is disconnected.|
|ERR_FILE_EXISTS | -16 | The file already exists.|
|ERR_FILE_PATH_TOO_LONG | -17 | The file path or file name is too long.|
|ERR_FILE_NO_SPACE | -18 | The disk space is insufficient. |
|ERR_FILE_VIRUS_INFECTED | -19 | The file contains viruses.|
|ERR_BLOCKED_BY_CLIENT | -20 | The request is blocked by the client.|
|ERR_NETWORK_CHANGED | -21 | The network is changed.|
|ERR_BLOCKED_BY_ADMINISTRATOR | -22 | The request is blocked by the administrator.|
|ERR_SOCKET_CONNECTED | -23 | The socket is already connected.|
|ERR_UPLOAD_STREAM_REWIND_NOT_SUPPORTED | -25 | The stream rewinding is not supported.|
|ERR_CONTEXT_SHUT_DOWN | -26 | The request fails because the context is closed.|
|ERR_BLOCKED_BY_RESPONSE | -27 | The request is blocked by response from headers such as X-Frame-Options, Content Security Policy, and Cross Origin Resource Policy.|
|ERR_CLEARTEXT_NOT_PERMITTED | -29 | The request fails because cleartext is not permitted by the system policy.|
|ERR_BLOCKED_BY_CSP | -30 | The request is blocked by the Content Security Policy.|
|ERR_H2_OR_QUIC_REQUIRED | -31 |  The request is blocked because there is no H/2 or QUIC session.|
|ERR_BLOCKED_BY_ORB | -32 | The request is blocked by CORB or ORB.|
|ERR_CONNECTION_CLOSED | -100 |  The connection has been closed.|
|ERR_CONNECTION_RESET | -101 |  The connection is reset.|
|ERR_CONNECTION_REFUSED | -102 | The connection is refused.|
|ERR_CONNECTION_ABORTED | -103 | The connection times out because the ACK message for sending data is not received. This may contain a FIN packet.|
|ERR_CONNECTION_FAILED | -104 |  The connection failed.|
|ERR_NAME_NOT_RESOLVED | -105 |  The domain name cannot be resolved.|
|ERR_INTERNET_DISCONNECTED | -106 | The Internet is disconnected.|
|ERR_SSL_PROTOCOL_ERROR | -107 | The SSL protocol is incorrect.|
|ERR_ADDRESS_INVALID | -108 |  The IP address or port number is invalid (for example, IP address 0 or port 0 cannot be connected).|
|ERR_ADDRESS_UNREACHABLE | -109 |  The IP address is unreachable. This means that there is no route to the specified host or network.|
|ERR_SSL_CLIENT_AUTH_CERT_NEEDED | -110 |  The server specifies that the client needs to provide an SSL certificate for authentication.|
|ERR_TUNNEL_CONNECTION_FAILED | -111 |  The tunnel connection to the proxy cannot be established.|
|ERR_NO_SSL_VERSIONS_ENABLED | -112 | No version of the SSL protocol is supported.|
|ERR_SSL_VERSION_OR_CIPHER_MISMATCH | -113 | The client and server do not support the common SSL protocol version or cipher suite.|
|ERR_SSL_RENEGOTIATION_REQUESTED | -114 | The server requests renegotiation (rehandshake).|
|ERR_PROXY_AUTH_UNSUPPORTED | -115 | The proxy requests authentication when the method for tunnel connection is not supported.|
|ERR_BAD_SSL_CLIENT_AUTH_CERT | -117 | The SSL client certificate is incorrect.|
|ERR_CONNECTION_TIMED_OUT | -118 | The connection times out.|
|ERR_HOST_RESOLVER_QUEUE_TOO_LARGE | -119 | The request in the queue is aborted because there are too many pending DNS resolutions.|
|ERR_SOCKS_CONNECTION_FAILED | -120 |  The connection between the SOCKS proxy server and the target host fails to be established.   |
|ERR_SOCKS_CONNECTION_HOST_UNREACHABLE | -121 | The domain name of the SOCKS proxy server is unreachable.|
|ERR_ALPN_NEGOTIATION_FAILED | -122 | The request for negotiating the standby protocol fails.|
|ERR_SSL_NO_RENEGOTIATION | -123 | The server sends an **SSL no_regregation** alert message.|
|ERR_WINSOCK_UNEXPECTED_WRITTEN_BYTES | -124 | Winsock sometimes reports that more data is written than is passed. This may be caused by LSP damage.|
|ERR_SSL_DECOMPRESSION_FAILURE_ALERT | -125 | The SSL peer sent a decompression failure alert to the local end. This usually occurs when the peer mistakenly believes that it supports DEFLATE compression.|
|ERR_SSL_BAD_RECORD_MAC_ALERT | -126 | The SSL peer sent a **bad_record_mac** alert to the local end. This may occur on a server that is not support DELEGATE.|
|ERR_PROXY_AUTH_REQUESTED | -127 | The proxy requests authentication for tunnel establishment.|
|ERR_PROXY_CONNECTION_FAILED | -130 | The connection to the proxy server cannot be established. This is because an error occurs when resolving the domain name or connecting to the socket. Note that this does not include failures during the HTTP CONNECT.|
|ERR_MANDATORY_PROXY_CONFIGURATION_FAILED | -131 |  The forcible proxy configuration cannot be used. Currently, this means that a mandatory PAC script cannot be obtained, parsed, or executed.|
|ERR_PRECONNECT_MAX_SOCKET_LIMIT | -133 | The limit of the socket pool is exceeded during pre-connection. Therefore, you do not need to try to pre-connect more sockets.|
|ERR_SSL_CLIENT_AUTH_PRIVATE_KEY_ACCESS_DENIED | -134 |  The access to the private key of the SSL client certificate is denied.|
|ERR_SSL_CLIENT_AUTH_CERT_NO_PRIVATE_KEY | -135 | The SSL client certificate does not have a private key.|
|ERR_PROXY_CERTIFICATE_INVALID | -136 |  The certificate provided by the HTTPS proxy is invalid.|
|ERR_NAME_RESOLUTION_FAILED | -137 | The domain name resolution (DNS) failed.|
|ERR_NETWORK_ACCESS_DENIED | -138 | The network is disabled.|
|ERR_TEMPORARILY_THROTTLED | -139 | This request was canceled due to throttling to avoid DDoS.|
|ERR_HTTPS_PROXY_TUNNEL_RESPONSE_REDIRECT | -140 |  The request for creating an SSL tunnel connection through the HTTPS proxy receives 302. (The response may contain the description of the request failure cause.)|
|ERR_SSL_CLIENT_AUTH_SIGNATURE_FAILED | -141 | The private key of the client certificate cannot be used to sign the CertificateVerify data in SSL handshake process.|
|ERR_MSG_TOO_BIG | -142 | The message is too large to be transmitted. (For example, UDP messages exceed the size threshold).|
|ERR_WS_PROTOCOL_ERROR | -145 | The WebSocket protocol is incorrect. This error indicates that the connection is being terminated due to a frame format error or a conflict with other protocols.|
|ERR_ADDRESS_IN_USE | -147 | The address is already in use.|
|ERR_SSL_HANDSHAKE_NOT_COMPLETED | -148 | The operation failed because the SSL handshake is not complete.|
|ERR_SSL_BAD_PEER_PUBLIC_KEY | -149 | The SSL public key is incorrect.|
|ERR_SSL_PINNED_KEY_NOT_IN_CERT_CHAIN | -150 | The received certificate does not match the public key specified by the built-in domain name.|
|ERR_CLIENT_AUTH_CERT_TYPE_UNSUPPORTED | -151 | The server's request for a client certificate is not supported by the local host.|
|ERR_SSL_DECRYPT_ERROR_ALERT | -153 | The SSL peer sent a **decrypt_error** alert to the local end. This error usually occurs when the peer cannot verify the signature (in CertificateVerify or ServerKeyExchange) or validate the Finished message.|
|ERR_WS_THROTTLE_QUEUE_TOO_LARGE | -154 | There are too many suspended WebSocketJob instances. Therefore, new Job instances are not pushed to the queue.|
|ERR_SSL_SERVER_CERT_CHANGED | -156 | The SSL server certificate is changed during renegotiation.|
|ERR_SSL_UNRECOGNIZED_NAME_ALERT | -159 | The SSL server sent a fatal unknown alert to the local end.|
|ERR_SOCKET_SET_RECEIVE_BUFFER_SIZE_ERROR | -160 | The receive buffer size of the socket is not set as requested.|
|ERR_SOCKET_SET_SEND_BUFFER_SIZE_ERROR | -161 | The send buffer size of the socket is not set as requested.|
|ERR_SOCKET_RECEIVE_BUFFER_SIZE_UNCHANGEABLE | -162 | The **setsockopt()** returned a success code, but the receive buffer size of the socket is not set as requested.|
|ERR_SOCKET_SEND_BUFFER_SIZE_UNCHANGEABLE | -163 | The **setsockopt()** returned a success code, but the send buffer size of the socket is not set as requested.|
|ERR_SSL_CLIENT_AUTH_CERT_BAD_FORMAT | -164 | The client certificate cannot be imported into the SSL library from the platform store.|
|ERR_ICANN_NAME_COLLISION | -166 | The host name is resolved to an IP address list containing the IPv4 address 127.0.53.53. This is a special IP address recommended by ICANN. It is used to indicate that there is a name conflict and remind administrators of potential problems.|
|ERR_SSL_SERVER_CERT_BAD_FORMAT | -167 | The SSL server provides a certificate that cannot be decoded. This is not a certificate error code because no X509Certificate object is available. This error is fatal.|
|ERR_CT_STH_PARSING_FAILED | -168 | The Certificate Transparency failed to parse the signed tree head.|
|ERR_CT_STH_INCOMPLETE | -169 | The Certificate Transparency parsed signed tree head successfully, but some information is missing.|
|ERR_UNABLE_TO_REUSE_CONNECTION_FOR_PROXY_AUTH | -170 | The attempt to re-send proxy authentication credentials failed because the AuthController has not generated the credentials yet. The caller should reconnect the AuthController.|
|ERR_CT_CONSISTENCY_PROOF_PARSING_FAILED | -171 | The Certificate Transparency failed to parse the consistency proof.|
|ERR_SSL_OBSOLETE_CIPHER | -172 | The SSL server requires an unsupported cipher suite, which has been deleted. This error will immediately occurs in a rollback of one or two versions after the cipher suite is deleted, after which the rollback will be deleted.|
|ERR_WS_UPGRADE | -173 | The WebSocket handshake is completed, the connection has been upgraded, and the URLRequest is canceled.|
|ERR_READ_IF_READY_NOT_IMPLEMENTED | -174 | The ReadIfReady of socket is not implemented. |
|ERR_NO_BUFFER_SPACE | -176 | No socket buffer space is available.|
|ERR_SSL_CLIENT_AUTH_NO_COMMON_ALGORITHMS | -177 | There is no common signature algorithm between the private key of the local end certificate and the preferences of the server.|
|ERR_EARLY_DATA_REJECTED | -178 | TLS 1.3 early data is rejected by the server. This error will be received before any data is returned from the socket. Retry the request when early data is disabled.|
|ERR_WRONG_VERSION_ON_EARLY_DATA | -179 | The TLS 1.3 early data version is incorrect.|
|ERR_TLS13_DOWNGRADE_DETECTED | -180 | TLS 1.3 is enabled, but an earlier version has been negotiated. This error indicates that it supports TLS 1.3. This is part of the security check in TLS 1.3, but it may also indicate that the user is using a problematic TLS-terminating proxy.|
|ERR_SSL_KEY_USAGE_INCOMPATIBLE | -181 | The server's certificate has a keyUsage extension that is incompatible with the negotiated TLS key exchange method.|
|ERR_INVALID_ECH_CONFIG_LIST | -182 | The ECHConfigList obtained through DNS cannot be resolved.|
|ERR_ECH_NOT_NEGOTIATED | -183 | ECH is enabled, but the server cannot decrypt ClientHello.|
|ERR_ECH_FALLBACK_CERTIFICATE_INVALID | -184 | ECH is enabled, the server cannot decrypt ClientHello message, and no certificate valid for the public name is provided.|
|ERR_CERT_COMMON_NAME_INVALID | -200 | The public name of the certificate used by the server in response does not match the host name. This may mean: 1. The attacker has redirected local traffic to their server and provided a certificate with a private key. 2. The server is incorrectly configured and uses an incorrect certificate to respond. 3. The user is on the wireless network and is redirected to the login page of the network. 4. The operating system uses the DNS search suffix, and the server does not have a certificate with such abbreviated name in the address box.|
|ERR_CERT_DATE_INVALID | -201 | The certificate has expired. This may mean: 1. The attacker provides an old certificate that they have obtained the private key. 2. The server is incorrectly configured and no valid certificate is provided. 3. The clock of the device is incorrect.|
|ERR_CERT_AUTHORITY_INVALID | -202 | The CA is not trusted. This may mean: 1. The attacker replaces a real certificate with a certificate that contains its public key and is signed by its cousin. 2. The server operator has a valid certificate from a CA that the local end does not know but should trust. 3. The server provides a self-signed certificate that cannot defend against active attackers.|
|ERR_CERT_CONTAINS_ERRORS | -203 | The certificate contains errors.|
|ERR_CERT_NO_REVOCATION_MECHANISM | -204 |There is no revocation mechanism for this certificate.|
|ERR_CERT_UNABLE_TO_CHECK_REVOCATION | -205 | Revocation information for this website's security certificate is not available. This may mean: 1. The attacker compromises the private key in the certificate and prevents the local end from discovering that the certificate has been revoked. 2. The certificate is not revoked, but the revocation server is busy or unavailable.|
|ERR_CERT_REVOKED | -206 | The certificate is revoked. The local end can ignore this error, but it should not do this.|
|ERR_CERT_INVALID | -207 |  The certificate is invalid. |
|ERR_CERT_WEAK_SIGNATURE_ALGORITHM | -208 | The server responds with a certificate signed with a weak signature algorithm.|
|ERR_CERT_NON_UNIQUE_NAME | -210 |  The domain name specified in the certificate is not unique.|
|ERR_CERT_WEAK_KEY | -211 | The server responds with a certificate that contains a weak key (for example, a small RSA key).|
|ERR_CERT_NAME_CONSTRAINT_VIOLATION | -212 | The certificate name constraint is violated.|
|ERR_CERT_VALIDITY_TOO_LONG | -213 | The certificate validity period is too long.|
|ERR_CERTIFICATE_TRANSPARENCY_REQUIRED | -214 |  The server does not provide Certificate Transparency information required for this connection.|
|ERR_CERT_SYMANTEC_LEGACY | -215 | The certificate is linked to the old Symantec directory that is no longer trusted.|
|ERR_CERT_KNOWN_INTERCEPTION_BLOCKED | -217 | The certificate is used for interception by an entity other than the device owner.|
|ERR_SSL_OBSOLETE_VERSION_OR_CIPHER | -218 | The connection uses an outdated version of SSL/TLS or password.|
|ERR_CERT_END | -219 | This error follows the previous error code.|
|ERR_INVALID_URL | -300 | The URL is invalid.|
|ERR_DISALLOWED_URL_SCHEME | -301 |  The URL scheme is not allowed to be used.|
|ERR_UNKNOWN_URL_SCHEME | -302 | The URL scheme is unknown.|
|ERR_INVALID_REDIRECT | -303 | The attempt to load a URL causes a redirection to an invalid URL.|
|ERR_TOO_MANY_REDIRECTS | -310 | There are too many redirections.|
|ERR_UNSAFE_REDIRECT | -311 | The redirection is unsafe.|
|ERR_UNSAFE_PORT | -312 | The port is unsafe.|
|ERR_INVALID_RESPONSE | -320 | The response is invalid.|
|ERR_INVALID_CHUNKED_ENCODING | -321 | The chunked encoding is invalid.|
|ERR_METHOD_UNSUPPORTED | -322 |	The method is not supported.|
|ERR_UNEXPECTED_PROXY_AUTH | -323 | The proxy authentication is unexpected.|
|ERR_EMPTY_RESPONSE | -324 | The response is empty.|
|ERR_RESPONSE_HEADERS_TOO_BIG | -325 | The value of response headers is too large.|
|ERR_PAC_SCRIPT_FAILED | -327 | The pac script is incorrect.|
|ERR_REQUEST_RANGE_NOT_SATISFIABLE | -328 | The request range cannot be met.|
|ERR_MALFORMED_IDENTITY | -329 | The identity used for authentication is invalid.|
|ERR_CONTENT_DECODING_FAILED | -330 | The response content failed to be decoded.|
|ERR_NETWORK_IO_SUSPENDED | -331 | The operation failed because all network I/Os are suspended.|
|ERR_SYN_REPLY_NOT_RECEIVED | -332 |	The **FLIP** data is received when **SYN_REPLY** is not received on the stream.|
|ERR_ENCODING_CONVERSION_FAILED | -333 | The response failed to be converted to the target encoding.|
|ERR_UNRECOGNIZED_FTP_DIRECTORY_LISTING_FORMAT | -334 | The format of the FTP directory list cannot be recognized.|
|ERR_NO_SUPPORTED_PROXIES | -336 | There is no supported proxy.|
|ERR_HTTP2_PROTOCOL_ERROR | -337 | The HTTP/2 protocol occurs error.|
|ERR_INVALID_AUTH_CREDENTIALS | -338 | The authentication credentials are invalid.|
|ERR_UNSUPPORTED_AUTH_SCHEME | -339 | The authentication scheme is not supported.|
|ERR_ENCODING_DETECTION_FAILED | -340 | The encoding detection failed.|
|ERR_MISSING_AUTH_CREDENTIALS | -341 | The authentication credentials are missing.|
|ERR_UNEXPECTED_SECURITY_LIBRARY_STATUS | -342 |	The security library status is unexpected.|
|ERR_MISCONFIGURED_AUTH_ENVIRONMENT | -343 | The authentication environment is incorrectly configured.|
|ERR_UNDOCUMENTED_SECURITY_LIBRARY_STATUS | -344 | The security library status is undocumented.|
|ERR_RESPONSE_BODY_TOO_BIG_TO_DRAIN | -345 | The response body is too big.|
|ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_LENGTH | -346 | The response has multiple Content-Length headers. |
|ERR_INCOMPLETE_HTTP2_HEADERS | -347 | The HTTP/2 headers are incomplete.|
|ERR_PAC_NOT_IN_DHCP | -348 | The PAC is not in DHCP.|
|ERR_RESPONSE_HEADERS_MULTIPLE_CONTENT_DISPOSITION | -349 | The response has multiple Content-Disposition headers.|
|ERR_RESPONSE_HEADERS_MULTIPLE_LOCATION | -350 | The response headers are in multiple locations.|
|ERR_HTTP2_SERVER_REFUSED_STREAM | -351 | The HTTP/2 server refuses the stream.|
|ERR_HTTP2_PING_FAILED | -352 |  The HTTP/2 ping failed.|
|ERR_CONTENT_LENGTH_MISMATCH | -354 | When the connection is closed, the number of bytes transmitted in the HTTP response body is less than the number of bytes advertised in the Content-Length header.|
|ERR_INCOMPLETE_CHUNKED_ENCODING | -355 | The HTTP response body is transmitted using chunked encoding, but the zero-length chunk is not sent to terminate the encoding when the connection is closed.|
|ERR_QUIC_PROTOCOL_ERROR | -356 | A QUIC protocol error occurs.|
|ERR_RESPONSE_HEADERS_TRUNCATED | -357 | The HTTP headers are truncated by the end of file (EOF).|
|ERR_QUIC_HANDSHAKE_FAILED | -358 | The QUIC encryption handshake failed. This means that the server cannot read any requests, so they may be resent.|
|ERR_HTTP2_INADEQUATE_TRANSPORT_SECURITY | -360 | The transport security is inadequate to HTTP/2.|
|ERR_HTTP2_FLOW_CONTROL_ERROR | -361 | The peer violates HTTP/2 flow control.|
|ERR_HTTP2_FRAME_SIZE_ERROR | -362 | The peer sends an HTTP/2 frame of an incorrect size.|
|ERR_HTTP2_COMPRESSION_ERROR | -363 | The decoding or encoding of the compressed HTTP/2 headers failed.|
|ERR_PROXY_AUTH_REQUESTED_WITH_NO_CONNECTION | -364 | The requested proxy authentication does not have a valid client socket handle.|
|ERR_HTTP_1_1_REQUIRED | -365 | The HTTP/2 session receives an **HTTP_1_1_REQUIRED** error code.|
|ERR_PROXY_HTTP_1_1_REQUIRED | -366 | The **HTTP_1_1_REQUIRED** error code is received when the HTTP/2 session proxy is used.|
|ERR_PAC_SCRIPT_TERMINATED | -367 | The PAC script has been terminated and must be reloaded.|
|ERR_INVALID_HTTP_RESPONSE | -370 | The server should return an **HTTP/1.x** response. But it returns an **HTTP/0.9** response.|
|ERR_CONTENT_DECODING_INIT_FAILED | -371 | The content decoding failed to be initialized.|
|ERR_HTTP2_RST_STREAM_NO_ERROR_RECEIVED | -372 | An **HTTP/2 RST_STREAM** frame with **NO_ERROR** is received. This error should be handled internally by HTTP/2 and should not exceed the SpdyStream layer.|
|ERR_HTTP2_PUSHED_STREAM_NOT_AVAILABLE | -373 | The pushed stream claimed by the request is not available.|
|ERR_HTTP2_CLAIMED_PUSHED_STREAM_RESET_BY_SERVER | -374 | The claimed pushed stream is reset by the server. In this case, the request should be retried.|
|ERR_TOO_MANY_RETRIES | -375 | The number of HTTP transaction retries is too large due to invalid authentication or certificate.|
|ERR_HTTP2_STREAM_CLOSED | -376 | An HTTP/2 frame is received on the closed stream.|
|ERR_HTTP2_CLIENT_REFUSED_STREAM | -377 | The client refuses an HTTP/2 stream.|
|ERR_HTTP2_PUSHED_RESPONSE_DOES_NOT_MATCH | -378 | Based on the matched URL and request header, an HTTP/2 push stream is received by the request, but the pushed response header does not match the request.|
|ERR_HTTP_RESPONSE_CODE_FAILURE | -379 | The server returns a **non-2xx** HTTP response code.|
|ERR_QUIC_UNKNOWN_CERT_ROOT | -380 | The certificate displayed on the QUIC connection is not linked to a known root certificate, and the connected original server is not in the list of domain names that allow unknown root certificates.|
|ERR_QUIC_GOAWAY_REQUEST_CAN_BE_RETRIED | -381 | A **GOAWAY** frame has been received, indicating that the request has not been processed and therefore can be safely retried on a different connection.|
|ERR_TOO_MANY_ACCEPT_CH_RESTARTS | -382 | The **ACCEPT_CH_RESTARTS** has been triggered too many times.|
| | -383 | In the same request, the IP address space of the remote endpoint is different from the previous one. Cache entries for any affected requests should be marked as invalid.|
|ERR_CACHED_IP_ADDRESS_SPACE_BLOCKED_BY_LOCAL_NETWORK_ACCESS_POLICY | -384 | The cached IP address space of the remote endpoint is blocked by a local network access policy.|
|ERR_CACHE_MISS | -400 |	There is no requested entry in the cache.|
|ERR_CACHE_READ_FAILURE | -401 | The data cannot be read from the disk cache.|
|ERR_CACHE_WRITE_FAILURE | -402 | The data cannot be written to the disk cache.|
|ERR_CACHE_OPERATION_UNSUPPORTED | -403 | The entry does not support this operation.|
|ERR_CACHE_OPEN_FAILURE | -404 | The disk cache could not open this entry.|
|ERR_CACHE_CREATE_FAILURE | -405 | The disk cache could not create this entry.|
|ERR_CACHE_RACE | -406 | Multiple transactions are competing to create disk cache entries.|
|ERR_CACHE_CHECKSUM_READ_FAILURE | -407 | The cache could not read the checksum on the entry.|
|ERR_CACHE_CHECKSUM_MISMATCH | -408 | An entry with an invalid checksum is found in the cache.|
|ERR_CACHE_LOCK_TIMEOUT | -409 | The HTTP cache contains error code.|
|ERR_CACHE_AUTH_FAILURE_AFTER_READ | -410 | A challenge is received after the transaction reads some data, but the credentials are unavailable.|
|ERR_CACHE_ENTRY_NOT_SUITABLE | -411 | The entry is not suitable for the cache.|
|ERR_CACHE_DOOM_FAILURE | -412 | The disk cache cannot delete this entry.|
|ERR_CACHE_OPEN_OR_CREATE_FAILURE | -413 | The disk cache could not open or create this entry.|
|ERR_INSECURE_RESPONSE | -501 | The response from the server is insecure (for example, there is a certificate error).|
|ERR_NO_PRIVATE_KEY_FOR_CERT | -502 | The client certificate failed to be imported because the user's key database does not have a private key.|
|ERR_ADD_USER_CERT_FAILED | -503 | The certificate failed to be added to the operating system database.|
|ERR_INVALID_SIGNED_EXCHANGE | -504 |The signed exchange is invalid.|
|ERR_INVALID_WEB_BUNDLE | -505 | The Web Bundle resources are invalid.|
|ERR_TRUST_TOKEN_OPERATION_FAILED | -506 | The request for performing the Trust Tokens protocol operation failed. The possible causes include prerequisite failure, internal error, and bad response.|
|ERR_TRUST_TOKEN_OPERATION_SUCCESS_WITHOUT_SENDING_REQUEST | -507 | When processing an operation execution request related to the Trust Tokens protocol, the system performs the Trust Tokens operation in the request, but does not send the request to the specified destination.|
|ERR_FTP_FAILED | -601 | The FTP control connection command failed.|
|ERR_FTP_SERVICE_UNAVAILABLE | -602 | The server cannot meet the request. This is a temporary error. The FTP response code is 421.|
|ERR_FTP_TRANSFER_ABORTED | -603 | The server has aborted the transfer. The FTP response code is 426.|
|ERR_FTP_FILE_BUSY | -604 | The file is in use, or some other temporary error occurs when the file is opened. The FTP response code is 450.|
|ERR_FTP_SYNTAX_ERROR | -605 | The server rejects the command from the local end due to a syntax error. The FTP response code is 500 or 501.|
|ERR_FTP_COMMAND_UNSUPPORTED | -606 | The server does not support the command sent by the local end. The FTP response code is 502 or 504.|
|ERR_FTP_BAD_COMMAND_SEQUENCE | -607 | The server rejects the commands from the local end because the local end does not send the commands in the correct sequence. The FTP response code is 503.|
|ERR_PKCS12_IMPORT_BAD_PASSWORD | -701 | The **PKCS #12** file cannot be imported because the password is incorrect.|
|ERR_PKCS12_IMPORT_FAILED | -702 | The **PKCS #12** file cannot be imported due to other errors.|
|ERR_IMPORT_CA_CERT_NOT_CA | -703 | The CA certificate cannot be imported because it is not a real CA certificate.|
|ERR_IMPORT_CERT_ALREADY_EXISTS | -704 | The certificate cannot be imported because it already exists in the database.|
|ERR_IMPORT_CA_CERT_FAILED | -705 | The CA failed to be imported due to other errors.|
|ERR_IMPORT_SERVER_CERT_FAILED | -706 | The server certificate failed to be imported due to some internal errors.|
|ERR_PKCS12_IMPORT_INVALID_MAC | -707 | The **PKCS #12** file failed to be imported because the message authentication code (MAC) is invalid.|
|ERR_PKCS12_IMPORT_INVALID_FILE | -708 | The **PKCS #12** file failed to be imported because the file is invalid or corrupted.|
|ERR_PKCS12_IMPORT_UNSUPPORTED | -709 | The **PKCS #12** file failed to be imported because the feature is not supported.|
|ERR_KEY_GENERATION_FAILED | -710 | The key generation failed.|
|ERR_PRIVATE_KEY_EXPORT_FAILED | -712 | The private key failed to be exported.|
|ERR_SELF_SIGNED_CERT_GENERATION_FAILED | -713 | The self-signed certificate generation failed.|
|ERR_CERT_DATABASE_CHANGED | -714 | The certificate database is changed.|
|ERR_CERT_VERIFIER_CHANGED | -716 | The certificate verifier configuration is changed.|
|ERR_DNS_MALFORMED_RESPONSE | -800 | The DNS resolver receives a response that the format is incorrect.|
|ERR_DNS_SERVER_REQUIRES_TCP | -801 | The DNS server requires TCP.|
|ERR_DNS_SERVER_FAILED | -802 | The DNS server failed. This error code is returned for all the following cases: 1-Incorrect format: The name server cannot interpret the query with an incorrect format. 2-Server failure: The name server cannot process the query due to its own problems. 3-Not Implemented: The name server does not support the query type of the request. 4-Rejection: The name server refuses to perform the specified operation for policy reasons.|
|ERR_DNS_TIMED_OUT | -803 | The DNS transaction times out.|
|ERR_DNS_CACHE_MISS | -804 | The entry is not found in the cache or other local sources.|
|ERR_DNS_SEARCH_EMPTY | -805 | The suffix search list rule prevents the resolution of a given host name.|
|ERR_DNS_SORT_ERROR | -806 |	Addresses are not sorted according to RFC 3484.|
|ERR_DNS_SECURE_RESOLVER_HOSTNAME_RESOLUTION_FAILED | -808 | The host name of the DNS-over-HTTPS server cannot be resolved.|
|ERR_DNS_NAME_HTTPS_ONLY | -809 | DNS has identified that the request is prohibited due to insecure connections (HTTP/WS). The application should handle this error like HTTP redirection, redirecting the connection to secure HTTPS or WSS.|
|ERR_DNS_REQUEST_CANCELED | -810 | All DNS requests related to this task are canceled.|
|ERR_DNS_NO_MATCHING_SUPPORTED_ALPN | -811 | The host name resolution of the HTTPS record is not resolved using the ALPN value of the supported protocol.|
