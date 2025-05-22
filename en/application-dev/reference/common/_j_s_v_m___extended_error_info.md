# JSVM_ExtendedErrorInfo


## Overview

Extended error information.

**Since**: 11

**Related module**: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [errorMessage](#errormessage) | Character string encoded in UTF8 format, including the error description. | 
| void \* [engineReserved](#enginereserved) | Detailed error message specific to a VM. This function is not implemented for any VM yet. | 
| uint32_t [engineErrorCode](#engineerrorcode) | Error code specific to a VM. This function is not implemented for any VM yet. | 
| [JSVM_Status](_j_s_v_m.md#jsvm_status) [errorCode](#errorcode) | JSVM-API status code derived from the last error. | 


## Member Variable Description


### engineErrorCode

```
uint32_t JSVM_ExtendedErrorInfo::engineErrorCode
```
**Description**
Error code specific to a VM. This function is not implemented for any VM yet.


### engineReserved

```
void* JSVM_ExtendedErrorInfo::engineReserved
```
**Description**
Detailed error message specific to a VM. This function is not implemented for any VM yet.


### errorCode

```
JSVM_Status JSVM_ExtendedErrorInfo::errorCode
```
**Description**
JSVM-API status code derived from the last error.


### errorMessage

```
const char* JSVM_ExtendedErrorInfo::errorMessage
```
**Description**
Character string encoded in UTF8 format, including the error description.
