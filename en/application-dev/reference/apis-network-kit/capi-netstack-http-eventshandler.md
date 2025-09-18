# Http_EventsHandler
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## Overview

Defines the callback for various HTTP events.

**Since**: 20

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_http_type.h](capi-net-http-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [Http_OnDataReceiveCallback](capi-net-http-type-h.md#http_ondatareceivecallback) onDataReceive | Callback invoked when a response body is received. For details, see [Http_OnDataReceiveCallback](capi-net-http-type-h.md#http_ondatareceivecallback).|
| [Http_OnProgressCallback](capi-net-http-type-h.md#http_onprogresscallback) onUploadProgress | Callback invoked when an upload is triggered. For details, see [Http_OnProgressCallback](capi-net-http-type-h.md#http_onprogresscallback).|
| [Http_OnProgressCallback](capi-net-http-type-h.md#http_onprogresscallback) onDownloadProgress | Callback invoked when a download is triggered. For details, see [Http_OnProgressCallback](capi-net-http-type-h.md#http_onprogresscallback).|
| [Http_OnHeaderReceiveCallback](capi-net-http-type-h.md#http_onheaderreceivecallback) onHeadersReceive | Callback invoked when a header is received. For details, see [Http_OnHeaderReceiveCallback](capi-net-http-type-h.md#http_onheaderreceivecallback).|
| [Http_OnVoidCallback](capi-net-http-type-h.md#http_onvoidcallback) onDataEnd | Callback invoked when the transmission is complete. For details, see [Http_OnVoidCallback](capi-net-http-type-h.md#http_onvoidcallback).|
| [Http_OnVoidCallback](capi-net-http-type-h.md#http_onvoidcallback) onCanceled | Callback invoked when the request is canceled. For details, see [Http_OnVoidCallback](capi-net-http-type-h.md#http_onvoidcallback).|
