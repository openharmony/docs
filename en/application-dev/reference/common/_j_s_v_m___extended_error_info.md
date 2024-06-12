# JSVM_ExtendedErrorInfo


## Overview

Extended exception information.

**Since**: 11

Related module: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [errorMessage](#errormessage) | UTF8-encoded string, including exception description. | 
| void \* [engineReserved](#enginereserved) | Detailed exception information specific to the VM. Currently, this function is not implemented for any VM. | 
| uint32_t [engineErrorCode](#engineerrorcode) | VM-specific exception code. Currently, this function is not implemented for any VM. | 
| [JSVM_Status](_j_s_v_m.md#jsvm_status)[errorCode](#errorcode) | JSVM-API status code derived from the last exception. | 


## Member Variable Description


### engineErrorCode

```
uint32_t JSVM_ExtendedErrorInfo::engineErrorCode
```
**Description**
VM-specific exception code. Currently, this function is not implemented for any VM.


### engineReserved

```
void* JSVM_ExtendedErrorInfo::engineReserved
```
**Description**
Detailed exception information specific to the VM. Currently, this function is not implemented for any VM.


### errorCode

```
JSVM_Status JSVM_ExtendedErrorInfo::errorCode
```
**Description**
JSVM-API status code derived from the last exception.


### errorMessage

```
const char* JSVM_ExtendedErrorInfo::errorMessage
```
**Description**
UTF8-encoded string, including exception description.
