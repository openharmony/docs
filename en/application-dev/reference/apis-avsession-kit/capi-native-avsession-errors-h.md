# native_avsession_errors.h
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the playback control error codes.

**File to include**: <multimedia/av_session/native_avsession_errors.h>

**Library**: libohavsession.so

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Since**: 13

**Related module**: [OHAVSession](capi-ohavsession.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AVSession_ErrCode](#avsession_errcode) | AVSession_ErrCode | Enumerates the playback control error codes.|

## Enums

### AVSession_ErrCode

```
enum AVSession_ErrCode
```

**Description**

Enumerates the playback control error codes.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| AV_SESSION_ERR_SUCCESS = 0 | The operation is successful.|
| AV_SESSION_ERR_INVALID_PARAMETER = 401 | Parameter check fails.|
| AV_SESSION_ERR_SERVICE_EXCEPTION = 6600101 | The session server is abnormal.|
| AV_SESSION_ERR_CODE_SESSION_NOT_EXIST = 6600102 | The session does not exist.|
| AV_SESSION_ERR_CODE_COMMAND_INVALID = 6600105 | The session command is invalid.|
| AV_SESSION_ERR_CODE_SESSION_INACTIVE = 6600106 | The session is not activated.|
| AV_SESSION_ERR_CODE_MESSAGE_OVERLOAD = 6600107 | Too many commands or messages.|
