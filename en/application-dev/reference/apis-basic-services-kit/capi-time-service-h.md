# time_service.h

## Overview

Declares the APIs for obtaining the time and time zone.

**Library**: libtime_service_ndk.so

**System capability**: SystemCapability.MiscServices.Time

**Since**: 12

**Related module**: [TimeService](capi-timeservice.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [TimeService_ErrCode](#timeservice_errcode) | TimeService_ErrCode | Enumerates the error codes.|

### Functions

| Name| Description|
| -- | -- |
| [TimeService_ErrCode OH_TimeService_GetTimeZone(char *timeZone, uint32_t len)](#oh_timeservice_gettimezone) | Obtains the current system time zone.|

## Enum Description

### TimeService_ErrCode

```
enum TimeService_ErrCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| TIMESERVICE_ERR_OK = 0 | Operation successful.|
| TIMESERVICE_ERR_INTERNAL_ERROR = 13000001 | Failed to obtain system parameters. |
| TIMESERVICE_ERR_INVALID_PARAMETER = 13000002 | Invalid parameter.|


## Function Description

### OH_TimeService_GetTimeZone()

```
TimeService_ErrCode OH_TimeService_GetTimeZone(char *timeZone, uint32_t len)
```

**Description**

Obtains the current system time zone.

**System capability**: SystemCapability.MiscServices.Time

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| char *timeZone | Pointer to the string array of time zone IDs. If the timezone is obtained, its ID is written. Otherwise, an empty string is written. The string ends with **\0**.|
| uint32_t len | Length of a string array of time zone IDs without maximum limit. You are advised to apply for sufficient memory for at less 31 bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [TimeService_ErrCode](#timeservice_errcode) | Returns [TIMESERVICE_ERR_OK](capi-time-service-h.md#timeservice_errcode) if the operation is successful;<br>returns [TIMESERVICE_ERR_INTERNAL_ERROR](capi-time-service-h.md#timeservice_errcode) if the system parameters fail to be obtained;<br>returns [TIMESERVICE_ERR_INVALID_PARAMETER](capi-time-service-h.md#timeservice_errcode) if **timeZone** is a null pointer or the length of the time zone name (excluding the end character **\0**) is greater than or equal to the value of **len**. |
