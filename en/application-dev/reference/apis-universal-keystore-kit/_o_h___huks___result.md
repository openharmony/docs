# OH_Huks_Result


## Overview

Defines the returned data, including a status code and related description.

**Since**: 9

**Related module**: [HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| int32_t [errorCode](#errorcode) | Status code. |
| const char \* [errorMsg](#errormsg) | Description of the status code. |
| uint8_t \* [data](#data) | Other data. |


## Member Variable Description


### data

```
uint8_t* OH_Huks_Result::data
```
**Description**

Other data returned.


### errorCode

```
int32_t OH_Huks_Result::errorCode
```
**Description**

Status code.


### errorMsg

```
const char* OH_Huks_Result::errorMsg
```
**Description**

Description of the status code.