# OH_Huks_Result


## Overview

Defines the return data, including the result code and message.

**Since:**
9

**Related Modules:**

[HuksTypeApi](_huks_type_api.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [errorCode](#errorcode) | Result code.  | 
| [errorMsg](#errormsg) | Description of the result code.  | 
| [data](#data) | Other data returned.  | 


## Member Variable Description 


### data

  
```
uint8_t* OH_Huks_Result::data
```
**Description**<br>
Other data returned.


### errorCode

  
```
int32_t OH_Huks_Result::errorCode
```
**Description**<br>
Result code.


### errorMsg

  
```
const char* OH_Huks_Result::errorMsg
```
**Description**<br>
Description of the result code.
