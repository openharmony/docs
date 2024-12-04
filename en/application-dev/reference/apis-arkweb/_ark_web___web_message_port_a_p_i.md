# ArkWeb_WebMessagePortAPI


## Overview

Defines a native API struct of the post message. Before calling an API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| size_t [size](#size) | Size of the struct. |
| [ArkWeb_ErrorCode](_web.md#arkweb_errorcode)(\* [postMessage](#postmessage) )(const [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) webMessagePort, const char \*webTag, const [ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage) | Pointer to the function used to send the message to the HTML page. |
| void(\* [close](#close) )(const [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) webMessagePort, const char \*webTag) | Pointer to the function used to close the message port. |
| void(\* [setMessageEventHandler](#setmessageeventhandler) )(const [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) webMessagePort, const char \*webTag, [ArkWeb_OnMessageEventHandler](_web.md#arkweb_onmessageeventhandler) messageEventHandler, void \*userData) | Pointer to the callback used to set the HTML messages received. |


## Member Variable Description


### close

```
void(* ArkWeb_WebMessagePortAPI::close) (const ArkWeb_WebMessagePortPtr webMessagePort, const char *webTag)
```
**Description**

Pointer to the function used to close the message port.

**Parameters**

| Name| Description|
| -------- | -------- |
| webMessagePort | Pointer to the message port. |
| webTag | Name of the **Web** component. |


### postMessage

```
ArkWeb_ErrorCode(* ArkWeb_WebMessagePortAPI::postMessage) (const ArkWeb_WebMessagePortPtr webMessagePort, const char *webTag, const ArkWeb_WebMessagePtr webMessage)
```
**Description**

Pointer to the function used to send the message to the HTML page.

**Parameters**

| Name| Description|
| -------- | -------- |
| webMessagePort | Pointer to the message port. |
| webTag | Name of the **Web** component. |
| webMessage | Message to send. |

**Returns**

Returns [ARKWEB_SUCCESS](_web.md) if the operation is successful. Returns [ARKWEB_INVALID_PARAM](_web.md) if the parameter is invalid. Returns [ARKWEB_INIT_ERROR](_web.md) if the initialization fails, that is, the Web component bound to the WebTag is not found.


### setMessageEventHandler

```
void(* ArkWeb_WebMessagePortAPI::setMessageEventHandler) (const ArkWeb_WebMessagePortPtr webMessagePort, const char *webTag, ArkWeb_OnMessageEventHandler messageEventHandler, void *userData)
```
**Description**

Pointer to the callback used to set the HTML messages received.

**Parameters**

| Name| Description|
| -------- | -------- |
| webMessagePort | Pointer to the message port. |
| webTag | Name of the **Web** component. |
| messageEventHandler | Callback used to handle messages. |
| userData | User-defined data. |


### size

```
size_t ArkWeb_WebMessagePortAPI::size
```
**Description**

Size of the struct.
