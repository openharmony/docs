# ArkWeb_ProxyMethod
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## Overview

Defines a proxy method to be injected.

**Since**: 12

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Summary

### Member Variables

| Name                                                                                                 | Description|
|-----------------------------------------------------------------------------------------------------| -- |
| const char* methodName                                                                              | Pointer to the method name to be injected.|
| [ArkWeb_OnJavaScriptProxyCallback](capi-arkweb-type-h.md#arkweb_onjavascriptproxycallback) callback | Callback used when a proxy method is executed.|
| void* userData                                                                                      | Pointer to the user data used in a callback.|
