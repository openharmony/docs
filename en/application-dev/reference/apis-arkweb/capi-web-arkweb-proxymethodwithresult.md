# ArkWeb_ProxyMethodWithResult

## Overview

Defines a proxy method to be injected.

**Since**: 18

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Total

### Member Variables

| Name                                                                                                                     | Description|
|-------------------------------------------------------------------------------------------------------------------------| -- |
| const char* methodName                                                                                                  | Pointer to the method name to be injected.|
| [ArkWeb_OnJavaScriptProxyCallbackWithResult](capi-arkweb-type-h.md#arkweb_onjavascriptproxycallbackwithresult) callback | Callback used when a proxy method is invoked.|
| void* userData                                                                                                          | Pointer to the user data used in a callback.|
