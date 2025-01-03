# ArkWeb_JavaScriptValueAPI


## Overview

Defines the native ArkWeb **JavaScriptValue** API. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 14

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| size_t [size](#size) | Size of the struct. |
| [ArkWeb_JavaScriptValuePtr](_web.md#arkweb_javascriptvalueptr)(\* [createJavaScriptValue](#createjavascriptvalue) )([ArkWeb_JavaScriptValueType](_web.md#arkweb_javascriptvaluetype) type, void \*data, size_t dataLength) | Pointer to **createJavaScriptValue**, which is returned to HTML. |


## Member Variable Description


### createJavaScriptValue

```
ArkWeb_JavaScriptValuePtr(* ArkWeb_JavaScriptValueAPI::createJavaScriptValue) (ArkWeb_JavaScriptValueType type, void *data, size_t dataLength)
```
**Description**

Pointer to **createJavaScriptValue**, which is returned to HTML.

**Parameters**

| Name| Description|
| -------- | -------- |
| type | Type of the JavaScript value. |
| data | Data of JavaScript values. |
| dataLength | Data length of JavaScript values. |

**Returns**

The created JavaScript value.


### size

```
size_t ArkWeb_JavaScriptValueAPI::size
```
**Description**

Size of the struct.

<!--no_check-->