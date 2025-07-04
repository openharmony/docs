# time_service.h


## Overview

Declares the API for obtaining the time and time zone information.

**Library**: libtime_service_ndk.so

**System capability**: SystemCapability.MiscServices.Time

**Since**: 12

**Related module**: [TimeService](_time_service.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
|[TimeService_ErrCode](_time_service.md#timeservice_errcode)| Enumerates the error codes.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [TimeService_ErrCode](_time_service.md#timeservice_errcode) {<br>TIMESERVICE_ERR_OK = 0,<br>TIMESERVICE_ERR_INTERNAL_ERROR = 13000001,<br>TIMESERVICE_ERR_INVALID_PARAMETER = 13000002<br>} | Enumerates the error codes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [TimeService_ErrCode](_time_service.md#timeservice_errcode) [OH_TimeService_GetTimeZone](_time_service.md#oh_timeservice_gettimezone) (char \*timeZone, uint32_t len) | Returns the current system time zone.| 
