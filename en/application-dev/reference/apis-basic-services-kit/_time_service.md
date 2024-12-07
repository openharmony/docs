# TimeService


## Overview

Enables the application to obtain the time and time zone information.

**Since**: 12


## Summary


### File

| Name| Description|
| -------- | -------- |
| [time_service.h](time__service_8h.md) | Declares the API for obtaining the time and time zone information. |


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [TimeService_ErrCode](#timeservice_errcode)[TimeService_ErrCode](#timeservice_errcode) | Enumerates the error codes.|


### Enums

| Name| Description|
| -------- | -------- |
| [TimeService_ErrCode](#timeservice_errcode) {<br>TIMESERVICE_ERR_OK = 0,<br>TIMESERVICE_ERR_INTERNAL_ERROR = 13000001,<br>TIMESERVICE_ERR_INVALID_PARAMETER = 13000002<br>} | Enumerates the error codes.|


### Functions

| Name| Description|
| -------- | -------- |
| [TimeService_ErrCode](#timeservice_errcode)[OH_TimeService_GetTimeZone](#oh_timeservice_gettimezone) (char \*timeZone, uint32_t len) | Returns the current system time zone. |


## Type Description


### TimeService_ErrCode

```
typedef enum TimeService_ErrCode TimeService_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 12


## Enum Description


### TimeService_ErrCode

```
enum TimeService_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| TIMESERVICE_ERR_OK | Obtains system parameters.|
| TIMESERVICE_ERR_INTERNAL_ERROR | Fails to obtain system parameters.|
| TIMESERVICE_ERR_INVALID_PARAMETER | Invalid parameter.|


## Function Description


### OH_TimeService_GetTimeZone()

```
TimeService_ErrCode OH_TimeService_GetTimeZone (char * timeZone, uint32_t len )
```

**Description**

Returns the current system time zone.

**System capability**: SystemCapability.MiscServices.Time

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| timeZone | A character array of time zone ID. If the time zone is obtained, the time zone ID string of the current system is written. Otherwise, an empty string is written. The string ends with **\0**. |
| len | Length of a character array of time zone ID without maximum limit. You are advised to apply for sufficient memory for at less 31 bytes. |

**Returns**

**TIMESERVICE_ERR_OK**: The system parameters are obtained.

**TIMESERVICE_ERR_INTERNAL_ERROR**: The system parameters fail to be obtained.

**TIMESERVICE_ERR_INVALID_PARAMETER**: The time zone is null or the length of the time zone name (excluding the end character **\0**) is greater than or equal to **len**.