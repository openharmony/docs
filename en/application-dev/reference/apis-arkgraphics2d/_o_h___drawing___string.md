# OH_Drawing_String


## Overview

The OH_Drawing_String struct describes a string of characters encoded in UTF-16BE (big-endian mode).

**Since**: 14

**Related module**: [Drawing](_drawing.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t \* [strData](#strdata) | Pointer to a byte array that stores characters in the UTF-16BE (big-endian) encoding format. | 
| uint32_t [strLen](#strlen) | Actual length of the string that **strData** points to, in bytes. | 


## Member Variable Description


### strData

```
uint8_t* OH_Drawing_String::strData
```
**Description**

Pointer to a byte array that stores characters in the UTF-16BE (big-endian) encoding format.


### strLen

```
uint32_t OH_Drawing_String::strLen
```
**Description**

Actual length of the string that **strData** points to, in bytes.
