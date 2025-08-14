# ArkWeb_JavaScriptObject

## Overview

Defines a JavaScript object.

**Since**: 12

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Summary

### Member Variables

| Name                                                                                       | Description|
|-------------------------------------------------------------------------------------------| -- |
| const uint8_t* buffer                                                                     | Pointer to the injected JavaScript code.|
| size_t size                                                                               | Length of the JavaScript code.|
| [ArkWeb_OnJavaScriptCallback](capi-arkweb-type-h.md#arkweb_onjavascriptcallback) callback | Callback used when JavaScript execution is complete.|
| void* userData                                                                            | Pointer to the user data used in a callback.|
