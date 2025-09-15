# net_http.h
<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->
## Overview

Defines the APIs of the HTTP request module.

**File to include**: <network/netstack/net_http.h>

**Library**: libnet_http.so

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20

**Related module**: [netstack](capi-netstack.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [Http_Headers *OH_Http_CreateHeaders(void)](#oh_http_createheaders) | Creates an HTTP request or response header.|
| [void OH_Http_DestroyHeaders(Http_Headers **headers)](#oh_http_destroyheaders) | Destroys an HTTP request or response header.|
| [uint32_t OH_Http_SetHeaderValue(struct Http_Headers *headers, const char *name, const char *value)](#oh_http_setheadervalue) | Sets the key-value pairs of an HTTP request or response header.|
| [Http_HeaderValue *OH_Http_GetHeaderValue(Http_Headers *headers, const char *name)](#oh_http_getheadervalue) | Obtains the value of an HTTP request or response header based on the specified key.|
| [Http_HeaderEntry *OH_Http_GetHeaderEntries(Http_Headers *headers)](#oh_http_getheaderentries) | Obtains all key-value pairs from an HTTP request or response header.|
| [void OH_Http_DestroyHeaderEntries(Http_HeaderEntry **headerEntry)](#oh_http_destroyheaderentries) | Destroys all key-value pairs obtained from **OH_Http_GetHeaderEntries**.|
| [Http_Request *OH_Http_CreateRequest(const char *url)](#oh_http_createrequest) | Creates an HTTP request.|
| [int OH_Http_Request(Http_Request *request, Http_ResponseCallback callback, Http_EventsHandler handler)](#oh_http_request) | Initiates an HTTP request.|
| [void OH_Http_Destroy(struct Http_Request **request)](#oh_http_destroy) | Destroys an HTTP request.|

## Function Description

### OH_Http_CreateHeaders()

```
Http_Headers *OH_Http_CreateHeaders(void)
```

**Overview**

Creates an HTTP request or response header.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20

**Return value**

| Type                | Description|
|--------------------| -- |
| [Http_Headers](capi-netstack-http-headers.md) * | Pointer to the HTTP request or response header.|

### OH_Http_DestroyHeaders()

```
void OH_Http_DestroyHeaders(Http_Headers **headers)
```

**Overview**

Destroys an HTTP request or response header.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Http_Headers](capi-netstack-http-headers.md) **headers | HTTP request or response header to be destroyed. The header is generated using **OH_Http_CreateHeaders**.|

### OH_Http_SetHeaderValue()

```
uint32_t OH_Http_SetHeaderValue(struct Http_Headers *headers, const char *name, const char *value)
```

**Overview**

Sets the key-value pairs of an HTTP request or response header.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [struct Http_Headers](capi-netstack-http-headers.md) *headers | Pointer to **Http_Headers**.|
| const char *name | Key name.|
| const char *value | Key value.|

**Return value**

| Type| Description|
| -- | -- |
| uint32_t | A status code of the uint32_t type. <br>**0**: Success.<br> **401**: Parameter error.<br> **2300027**: Insufficient memory.|

### OH_Http_GetHeaderValue()

```
Http_HeaderValue *OH_Http_GetHeaderValue(Http_Headers *headers, const char *name)
```

**Overview**

Obtains the value of an HTTP request or response header based on the specified key.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Http_Headers](capi-netstack-http-headers.md) *headers | Pointer to **Http_Headers**.|
| const char *name | Key name.|

**Return value**

| Type                    | Description|
|------------------------| -- |
| [Http_HeaderValue](capi-netstack-http-headervalue.md) * | Pointer to **Http_HeaderValue**.|

### OH_Http_GetHeaderEntries()

```
Http_HeaderEntry *OH_Http_GetHeaderEntries(Http_Headers *headers)
```

**Overview**

Obtains all key-value pairs from an HTTP request or response header.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Http_Headers](capi-netstack-http-headers.md) *headers | Pointer to **Http_Headers**.|

**Return value**

| Type                    | Description|
|------------------------| -- |
| [Http_HeaderEntry](capi-netstack-http-headerentry.md) * | Pointer to **Http_HeaderEntry**.|

### OH_Http_DestroyHeaderEntries()

```
void OH_Http_DestroyHeaderEntries(Http_HeaderEntry **headerEntry)
```

**Overview**

Destroys all key-value pairs obtained from **OH_Http_GetHeaderEntries**.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Http_HeaderEntry](capi-netstack-http-headerentry.md) **headerEntry | Pointer to **Http_HeaderEntry**, which is obtained through **OH_Http_GetHeaderEntries**.|

### OH_Http_CreateRequest()

```
Http_Request *OH_Http_CreateRequest(const char *url)
```

**Overview**

Creates an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char *url | Request URL.|

**Return value**

| Type                | Description|
|--------------------| -- |
| [Http_Request](capi-netstack-http-request.md) * | Pointer to **Http_Request**.|

### OH_Http_Request()

```
int OH_Http_Request(Http_Request *request, Http_ResponseCallback callback, Http_EventsHandler handler)
```

**Overview**

Initiates an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

**Required permission**: ohos.permission.INTERNET

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Http_Request](capi-netstack-http-request.md) *request | Pointer to **Http_Request**.|
| [Http_ResponseCallback](capi-net-http-type-h.md#http_responsecallback) callback | HTTP response callback.|
| [Http_EventsHandler](capi-netstack-http-eventshandler.md) handler | HTTP event handler.|

**Return value**

| Type| Description|
| -- | -- |
| int | **0** if the operation is successful; an error code otherwise. For details about the error code description, see **Http_ErrCode**.<br> **Http_ResponseCallback** also carries **errCode**, indicating that the operation is successful but server communication is abnormal due to some reasons. For details, see **Http_ErrCode**.|

### OH_Http_Destroy()

```
void OH_Http_Destroy(struct Http_Request **request)
```

**Overview**

Destroys an HTTP request.

**System capability**: SystemCapability.Communication.NetStack

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [struct Http_Request](capi-netstack-http-request.md) **request | Pointer to **Http_Request**. For details, see [Http_Request](capi-netstack-http-request.md).|
