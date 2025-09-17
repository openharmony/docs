# ArkWeb_ProxyObject
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## Overview

Defines a proxy object to be injected.

**Since**: 12

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Total

### Member Variables

| Name                                      | Description|
|------------------------------------------| -- |
| const char* objName                      | Pointer to the object name to be injected.|
| const [ArkWeb_ProxyMethod](capi-web-arkweb-proxymethod.md)* methodList | Pointer to the method struct array of an object to be injected.|
| size_t size                              | Length of the method struct array.|
