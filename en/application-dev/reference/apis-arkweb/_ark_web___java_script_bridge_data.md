# ArkWeb_JavaScriptBridgeData


## Overview

Defines the JavaScript Bridge data.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const uint8_t \* [buffer](#buffer) | Pointer to the data to be transferred. Only the String and ArrayBuffer types can be transferred from the frontend. Other types will be serialized by JSON and then transferred as the String type. | 
| size_t [size](#size) | Length of the data to be transferred. | 


## Member Variable Description


### buffer

```
const uint8_t* ArkWeb_JavaScriptBridgeData::buffer
```
**Description**

Pointer to the data to be transferred. Only the String and ArrayBuffer types can be transferred from the frontend. Other types will be serialized by JSON and then transferred as the String type.


### size

```
size_t ArkWeb_JavaScriptBridgeData::size
```
**Description**

Length of the data to be transferred.
