# ArkWeb_JavaScriptValueAPI

## Overview

Defines the native ArkWeb **JavaScriptValue** API. Before calling the API, you are advised to use **ARKWEB_MEMBER_MISSING** to check whether the function struct has the corresponding pointer to avoid crash caused by mismatch between the SDK and the device ROM.

**Since**: 18

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| size_t size | Size of the struct.|

### Member Functions

| Name                                                                                                                     | Description|
|-------------------------------------------------------------------------------------------------------------------------|----|
| [ArkWeb_JavaScriptValuePtr (*createJavaScriptValue)(ArkWeb_JavaScriptValueType type, void* data, size_t dataLength)](#createjavascriptvalue) | Creates a JavaScript value to be returned to HTML.  |

## Member Function Description

### createJavaScriptValue()

```
ArkWeb_JavaScriptValuePtr (*createJavaScriptValue)(ArkWeb_JavaScriptValueType type, void* data, size_t dataLength)
```

**Description**

Creates a JavaScript value to be returned to HTML.

**Since**: 15

**Parameters**

| Name                            | Description|
|---------------------------------|----|
| ArkWeb_JavaScriptValueType type | Type of the JavaScript value.  |
| void* data                                | Pointer to the JavaScript value data.  |
| size_t dataLength                               | Length of the JavaScript value data.  |

**Returns**

| Type                           | Description|
|-------------------------------|----|
| [ArkWeb_JavaScriptValuePtr](capi-web-arkweb-javascriptvalue8h.md) | Created JavaScript value.  |
