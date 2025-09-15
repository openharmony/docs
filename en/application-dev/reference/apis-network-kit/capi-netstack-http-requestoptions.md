# Http_RequestOptions
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## Overview

Defines the structure of HTTP requests.

**Since**: 20

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_http_type.h](capi-net-http-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| const char *method | HTTP request method.|
| uint32_t priority | HTTP request priority.|
| [Http_Headers](capi-netstack-http-headers.md) *headers | Pointer to the HTTP request header. For details, see [Http_Headers](capi-netstack-http-headers.md).|
| uint32_t readTimeout | Read timeout duration.|
| uint32_t connectTimeout | Connection timeout duration.|
| [Http_HttpProtocol](capi-net-http-type-h.md#http_httpprotocol) httpProtocol | HTTP protocol. For details, see [Http_HttpProtocol](capi-net-http-type-h.md#http_httpprotocol).|
| [Http_Proxy](capi-netstack-http-proxy.md) *httpProxy | Pointer to the HTTP proxy configuration, which indicates whether to use a proxy. By default, proxy is not used. For details, see [Http_Proxy](capi-netstack-http-proxy.md).|
| const char *caPath | Certificate path. If the CA certificate path is set, the system uses the CA certificate in the specified path. Otherwise, the system uses the preset CA certificate.|
| int64_t resumeFrom | Download start position. This field can be used only for the GET method.|
| int64_t resumeTo | Download end position. This field can be used only for the GET method.|
| [Http_ClientCert](capi-netstack-http-clientcert.md) *clientCert | Pointer to the client certificate configuration. For details, see [Http_ClientCert](capi-netstack-http-clientcert.md).|
| const char *dnsOverHttps | HTTPS server for DNS resolution.|
| [Http_AddressFamilyType](capi-net-http-type-h.md#http_addressfamilytype) addressFamily | IP address family. For details, see [Http_AddressFamilyType](capi-net-http-type-h.md#http_addressfamilytype).|
