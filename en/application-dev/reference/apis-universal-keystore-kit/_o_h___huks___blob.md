# OH_Huks_Blob


## Overview

Defines the struct of a binary large object (BLOB).

**Since**: 9

**Related module**: [HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| uint32_t [size](#size) | Size of the BLOB object. |
| uint8_t \* [data](#data) | Pointer to the memory in which the data is stored. |


## Member Variable Description


### data

```
uint8_t* OH_Huks_Blob::data
```
**Description**

Pointer to the memory in which the data is stored.


### size

```
uint32_t OH_Huks_Blob::size
```
**Description**

Size of the data.