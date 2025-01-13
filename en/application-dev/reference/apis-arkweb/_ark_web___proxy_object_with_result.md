# ArkWeb_ProxyObjectWithResult


## Overview

Defines a proxy object.

**Since**: 14

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [objName](#objname) | Pointer to the object name to be injected. | 
| const [ArkWeb_ProxyMethodWithResult](_ark_web___proxy_method_with_result.md) \* [methodList](#methodlist) | Pointer to the method struct array of an injected object. | 
| size_t [size](#size) | Length of the method struct array. | 


## Member Variable Description


### methodList

```
const ArkWeb_ProxyMethodWithResult* ArkWeb_ProxyObjectWithResult::methodList
```
**Description**

Pointer to the method struct array of an injected object.


### objName

```
const char* ArkWeb_ProxyObjectWithResult::objName
```
**Description**

Pointer to the object name to be injected.


### size

```
size_t ArkWeb_ProxyObjectWithResult::size
```
**Description**

Length of the method struct array.
