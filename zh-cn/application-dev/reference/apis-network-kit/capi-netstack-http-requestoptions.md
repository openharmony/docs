# Http_RequestOptions
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## 概述

定义HTTP请求配置的结构体。

**起始版本：** 20

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_http_type.h](capi-net-http-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| const char *method | HTTP请求方法。 |
| uint32_t priority | HTTP请求优先级。 |
| [Http_Headers](capi-netstack-http-headers.md) *headers | HTTP请求头，指向Http_Headers的指针，参考[Http_Headers](capi-netstack-http-headers.md)。 |
| uint32_t readTimeout | 读取超时时间。 |
| uint32_t connectTimeout | 连接超时时间。 |
| [Http_HttpProtocol](capi-net-http-type-h.md#http_httpprotocol) httpProtocol | 使用的协议，参考[Http_HttpProtocol](capi-net-http-type-h.md#http_httpprotocol)。 |
| [Http_Proxy](capi-netstack-http-proxy.md) *httpProxy | 代理配置信息，表示是否使用代理，默认不使用代理，参考[Http_Proxy](capi-netstack-http-proxy.md)。 |
| const char *caPath | 证书路径，如果设置了此参数，系统将使用用户指定路径的CA证书（开发者需保证该路径下CA证书的可访问性），否则将使用系统预设CA证书。 |
| int64_t resumeFrom | 用于设置下载起始位置，该参数只能用于GET方法，不要用于其他。 |
| int64_t resumeTo | 用于设置下载结束位置，该参数只能用于GET方法，不要用于其他。 |
| [Http_ClientCert](capi-netstack-http-clientcert.md) *clientCert | 传输客户端证书配置信息，参考[Http_ClientCert](capi-netstack-http-clientcert.md)。 |
| const char *dnsOverHttps | 设置使用HTTPS协议的服务器进行DNS解析。 |
| [Http_AddressFamilyType](capi-net-http-type-h.md#http_addressfamilytype) addressFamily | 支持解析目标域名时限定地址类型，参考[Http_AddressFamilyType](capi-net-http-type-h.md#http_addressfamilytype)。 |


