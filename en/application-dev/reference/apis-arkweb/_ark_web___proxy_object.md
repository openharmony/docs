# ArkWeb_ProxyObject


## Overview

Defines a proxy object.

**Since**: 12

**Related module**: [Web](_web.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [objName](#objname) | Pointer to the object name to be injected. | 
| const [ArkWeb_ProxyMethod](_ark_web___proxy_method.md) \* [methodList](#methodlist) | Pointer to the array of method structures of an injected object. | 
| size_t [size](#size) | Length of the method structure array. | 


## Member Variable Description


### methodList

```
const ArkWeb_ProxyMethod* ArkWeb_ProxyObject::methodList
```
**Description**

Pointer to the array of method structures of an injected object.


### objName

```
const char* ArkWeb_ProxyObject::objName
```
**Description**

Pointer to the object name to be injected.


### size

```
size_t ArkWeb_ProxyObject::size
```
**Description**

Length of the method structure array.
