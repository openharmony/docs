# ArkWeb_JavaScriptObject


## Overview

Defines a JavaScript object.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const uint8_t \* [buffer](#buffer) | Pointer to the injected JavaScript code. | 
| size_t [size](#size) | The JavaScript code length. | 
| [ArkWeb_OnJavaScriptCallback](_web.md#arkweb_onjavascriptcallback) [callback](#callback) | Callback used when JavaScript execution is complete. | 
| void \* [userData](#userdata) | Pointer to the user data used in a callback. | 


## Member Variable Description


### buffer

```
const uint8_t* ArkWeb_JavaScriptObject::buffer
```
**Description**

Pointer to the injected JavaScript code.


### callback

```
ArkWeb_OnJavaScriptCallback ArkWeb_JavaScriptObject::callback
```
**Description**

Callback used when JavaScript execution is complete.


### size

```
size_t ArkWeb_JavaScriptObject::size
```
**Description**

The JavaScript code length.


### userData

```
void* ArkWeb_JavaScriptObject::userData
```
**Description**

Pointer to the user data used in a callback.
