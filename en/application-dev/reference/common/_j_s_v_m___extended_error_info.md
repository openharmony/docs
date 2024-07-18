# JSVM_ExtendedErrorInfo


## Overview

Extended error information.

**Starting Version:** 11

**Related Module:** [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| const char * [errorMessage](#errormessage)                   | A UTF-8 encoded string containing the description of the exception. |
| void * [engineReserved](#enginereserved)                     | Detailed exception information specific to the VM. This feature has not yet been implemented for any VM. |
| uint32_t [engineErrorCode](#engineerrorcode)                 | Exception code specific to the VM. This feature has not yet been implemented for any VM. |
| [JSVM_Status](_j_s_v_m.md#jsvm_status) [errorCode](#errorcode) | The JSVM-API status code from the last exception.            |


## Description of Struct Member Variables


### engineErrorCode

```
uint32_t JSVM_ExtendedErrorInfo::engineErrorCode
```
**Description**
Exception code specific to the VM. This feature has not yet been implemented for any VM.


### engineReserved

```
void* JSVM_ExtendedErrorInfo::engineReserved
```
**Description**
Detailed exception information specific to the VM. This feature has not yet been implemented for any VM.


### errorCode

```
JSVM_Status JSVM_ExtendedErrorInfo::errorCode
```
**Description**
The JSVM-API status code from the last exception.


### errorMessage

```
const char* JSVM_ExtendedErrorInfo::errorMessage
```
**Description**
A UTF-8 encoded string containing the description of the exception.