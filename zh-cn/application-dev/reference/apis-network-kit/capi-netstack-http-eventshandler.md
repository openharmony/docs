# Http_EventsHandler
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## 概述

监听不同HTTP事件的回调函数。

**起始版本：** 20

**相关模块：** [netstack](capi-netstack.md)

**所在头文件：** [net_http_type.h](capi-net-http-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [Http_OnDataReceiveCallback](capi-net-http-type-h.md#http_ondatareceivecallback) onDataReceive | 收到响应体时的回调函数，参考[Http_OnDataReceiveCallback](capi-net-http-type-h.md#http_ondatareceivecallback)。 |
| [Http_OnProgressCallback](capi-net-http-type-h.md#http_onprogresscallback) onUploadProgress | 上传时调用的回调函数，参考[Http_OnProgressCallback](capi-net-http-type-h.md#http_onprogresscallback)。 |
| [Http_OnProgressCallback](capi-net-http-type-h.md#http_onprogresscallback) onDownloadProgress | 下载时调用的回调函数，参考[Http_OnProgressCallback](capi-net-http-type-h.md#http_onprogresscallback)。 |
| [Http_OnHeaderReceiveCallback](capi-net-http-type-h.md#http_onheaderreceivecallback) onHeadersReceive | 收到header时的回调函数，参考[Http_OnHeaderReceiveCallback](capi-net-http-type-h.md#http_onheaderreceivecallback)。 |
| [Http_OnVoidCallback](capi-net-http-type-h.md#http_onvoidcallback) onDataEnd | 传输结束时的回调函数，参考[Http_OnVoidCallback](capi-net-http-type-h.md#http_onvoidcallback)。 |
| [Http_OnVoidCallback](capi-net-http-type-h.md#http_onvoidcallback) onCanceled | 请求被取消时的回调函数，参考[Http_OnVoidCallback](capi-net-http-type-h.md#http_onvoidcallback)。 |


