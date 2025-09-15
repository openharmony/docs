# Http_Response
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## Overview

Defines the structure of HTTP responses.

**Since**: 20

**Related module**: [netstack](capi-netstack.md)

**Header file**: [net_http_type.h](capi-net-http-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [Http_Buffer](capi-netstack-http-buffer.md) body | HTTP response data. For details, see [Http_Buffer](capi-netstack-http-buffer.md).|
| [Http_ResponseCode](capi-net-http-type-h.md#http_responsecode) responseCode | HTTP response code. For details, see [Http_ResponseCode](capi-net-http-type-h.md#http_responsecode).|
| [Http_Headers](capi-netstack-http-headers.md) *headers | Pointer to the HTTP response header. For details, see [Http_Headers](capi-netstack-http-headers.md).|
| char *cookies | Pointer to the HTTP response cookies.|
| [Http_PerformanceTiming](capi-netstack-http-performancetiming.md) *performanceTiming | Pointer to the HTTP response timing. For details, see [Http_PerformanceTiming](capi-netstack-http-performancetiming.md).|


### Member Functions

| Name| Description|
| -- | -- |
| [void (\*destroyResponse)(struct Http_Response **response)](#destroyresponse) | Callback function for destroying an HTTP response.|

## Member Function Description

### destroyResponse()

```
void (*destroyResponse)(struct Http_Response **response)
```

**Description**

Callback function for destroying an HTTP response.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| struct [Http_Response](capi-netstack-http-response.md) **response | Pointer to the HTTP response to be destroyed. For details, see [Http_Response](capi-netstack-http-response.md).|
