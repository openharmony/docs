# ArkWeb_WebMessagePortAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## Overview

Defines a native API struct of the post message. Before calling this API, you are advised to use [ARKWEB_MEMBER_MISSING](capi-arkweb-type-h.md#macros) to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 12

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| size_t size | Size of the struct.|


### Member Functions

| Name                                                                                                                                                                                             | Description        |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------|
| [ArkWeb_ErrorCode (\*postMessage)(const ArkWeb_WebMessagePortPtr webMessagePort, const char* webTag, const ArkWeb_WebMessagePtr webMessage)](#postmessage)                                      | Sends a message to the HTML page.|
| [void (\*close)(const ArkWeb_WebMessagePortPtr webMessagePort, const char* webTag)](#close)                                                                                                     | Closes a message port.   |
| [void (\*setMessageEventHandler)(const ArkWeb_WebMessagePortPtr webMessagePort, const char* webTag, ArkWeb_OnMessageEventHandler messageEventHandler, void* userData)](#setmessageeventhandler) | Sets a callback for receiving HTML messages.          |

## Member Function Description

### postMessage()

```
ArkWeb_ErrorCode (*postMessage)(const ArkWeb_WebMessagePortPtr webMessagePort, const char* webTag, const ArkWeb_WebMessagePtr webMessage)
```

**Description**

Sends a message to the HTML page.

**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md) webMessagePort | Pointer to the message port.|
|  const char* webTag | Name of the **Web** component.|
|  const [ArkWeb_WebMessagePtr](capi-web-arkweb-webmessage8h.md) webMessage | Message to send.|

**Returns**

| Type                                                              | Description                                                                                  |
|------------------------------------------------------------------|--------------------------------------------------------------------------------------|
| [ArkWeb_ErrorCode](capi-arkweb-error-code-h.md#arkweb_errorcode) | [ARKWEB_SUCCESS](capi-arkweb-error-code-h.md#arkweb_errorcode): The operation is successful.<br>[ARKWEB_INVALID_PARAM](capi-arkweb-error-code-h.md#arkweb_errorcode): The parameter is invalid.<br>[ARKWEB_INIT_ERROR](capi-arkweb-error-code-h.md#arkweb_errorcode): The initialization fails because the **Web** component bound to **webTag** is not found.|

### close()

```
void (*close)(const ArkWeb_WebMessagePortPtr webMessagePort, const char* webTag)
```

**Description**

Closes a message port.

**Parameters**

| Name| Description|
| -- | -- |
| const [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md) webMessagePort | Pointer to the message port.|

### setMessageEventHandler()

```
void (*setMessageEventHandler)(const ArkWeb_WebMessagePortPtr webMessagePort, const char* webTag,
        ArkWeb_OnMessageEventHandler messageEventHandler, void* userData)
```

**Description**

Closes a message port.

**Parameters**

| Name                                                                                                   | Description                  |
|--------------------------------------------------------------------------------------------------------|----------------------|
| const [ArkWeb_WebMessagePortPtr](capi-web-arkweb-webmessageport8h.md) webMessagePort                       | Pointer to the message port.|
| const char* webTag                                                                                     |  Name of the **Web** component.                    |
| [ArkWeb_OnMessageEventHandler](capi-arkweb-type-h.md#arkweb_onmessageeventhandler) messageEventHandler | Callback used to handle messages.                    |
| void* userData                                                                                         | User-defined data.                    |
