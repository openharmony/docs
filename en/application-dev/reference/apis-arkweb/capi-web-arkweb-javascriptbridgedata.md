# ArkWeb_JavaScriptBridgeData

## Overview

Defines the JavaScript Bridge data.

**Since**: 12

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| const uint8_t* buffer | Pointer to the data to be transferred. Only the String and ArrayBuffer types can be transferred from the frontend. Other types will be serialized by JSON and then transferred as the String type.|
| size_t size | Length of the data to be transferred.|
