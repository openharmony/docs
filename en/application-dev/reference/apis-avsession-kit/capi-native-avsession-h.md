# native_avsession.h
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--SE: @ccfriend-->
<!--TSE: @chenmingxi1_huawei-->

## Overview

The file declares the AVSession definition, which can be used to set metadata, playback state, and other information.

**File to include**: <multimedia/av_session/native_avsession.h>

**Library**: libohavsession.so

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Since**: 13

**Related module**: [OHAVSession](capi-ohavsession.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AVSession_PlaybackPosition](capi-ohavsession-avsession-playbackposition.md) | AVSession_PlaybackPosition | Describes the information related to the playback position.|
| [OH_AVSession](capi-ohavsession-oh-avsession.md) | OH_AVSession | Defines a struct for the playback control session object. You can use **OH_AVSession_Create** to create such an object.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AVSession_Type](#avsession_type) | AVSession_Type | Enumerates the session types.|
| [AVSession_PlaybackState](#avsession_playbackstate) | AVSession_PlaybackState | Enumerates the media playback states.|
| [AVSession_LoopMode](#avsession_loopmode) | AVSession_LoopMode | Enumerates the loop modes of media playback.|
| [AVSession_ControlCommand](#avsession_controlcommand) | AVSession_ControlCommand | Enumerates the playback control commands.|
| [AVSessionCallback_Result](#avsessioncallback_result) | AVSessionCallback_Result | Enumerates the callback execution results.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef AVSessionCallback_Result (\*OH_AVSessionCallback_OnCommand)(OH_AVSession* session,AVSession_ControlCommand command, void* userData)](#oh_avsessioncallback_oncommand) | OH_AVSessionCallback_OnCommand | Defines a callback for a common playback control command.|
| [typedef AVSessionCallback_Result (\*OH_AVSessionCallback_OnFastForward)(OH_AVSession* session,uint32_t seekTime, void* userData)](#oh_avsessioncallback_onfastforward) | OH_AVSessionCallback_OnFastForward | Defines a callback for the fast-forward operation.|
| [typedef AVSessionCallback_Result (\*OH_AVSessionCallback_OnRewind)(OH_AVSession* session,uint32_t seekTime, void* userData)](#oh_avsessioncallback_onrewind) | OH_AVSessionCallback_OnRewind | Defines a callback for the rewind operation.|
| [typedef AVSessionCallback_Result (\*OH_AVSessionCallback_OnSeek)(OH_AVSession* session,uint64_t seekTime, void* userData)](#oh_avsessioncallback_onseek) | OH_AVSessionCallback_OnSeek | Defines a callback for the seek operation.|
| [typedef AVSessionCallback_Result (\*OH_AVSessionCallback_OnSetLoopMode)(OH_AVSession* session,AVSession_LoopMode curLoopMode, void* userData)](#oh_avsessioncallback_onsetloopmode) | OH_AVSessionCallback_OnSetLoopMode | Defines a callback for the operation of setting the loop mode.|
| [typedef AVSessionCallback_Result (\*OH_AVSessionCallback_OnToggleFavorite)(OH_AVSession* session,const char* assetId, void* userData)](#oh_avsessioncallback_ontogglefavorite) | OH_AVSessionCallback_OnToggleFavorite | Defines a callback for the operation of favoriting a media asset.|
| [AVSession_ErrCode OH_AVSession_Create(AVSession_Type sessionType, const char* sessionTag,const char* bundleName, const char* abilityName, OH_AVSession** avsession)](#oh_avsession_create) | - | Creates a session object.|
| [AVSession_ErrCode OH_AVSession_Destroy(OH_AVSession* avsession)](#oh_avsession_destroy) | - | Destroys a session object.|
| [AVSession_ErrCode OH_AVSession_Activate(OH_AVSession* avsession)](#oh_avsession_activate) | - | Activates a session.|
| [AVSession_ErrCode OH_AVSession_Deactivate(OH_AVSession* avsession)](#oh_avsession_deactivate) | - | Deactivates a session.|
| [AVSession_ErrCode OH_AVSession_GetSessionType(OH_AVSession* avsession, AVSession_Type* sessionType)](#oh_avsession_getsessiontype) | - | Obtains the session type.|
| [AVSession_ErrCode OH_AVSession_GetSessionId(OH_AVSession* avsession, const char** sessionId)](#oh_avsession_getsessionid) | - | Obtains the session ID.|
| [AVSession_ErrCode OH_AVSession_SetAVMetadata(OH_AVSession* avsession, OH_AVMetadata* avmetadata)](#oh_avsession_setavmetadata) | - | Sets media metadata.|
| [AVSession_ErrCode OH_AVSession_SetPlaybackState(OH_AVSession* avsession,AVSession_PlaybackState playbackState)](#oh_avsession_setplaybackstate) | - | Sets the playback state.|
| [AVSession_ErrCode OH_AVSession_SetPlaybackPosition(OH_AVSession* avsession,AVSession_PlaybackPosition* playbackPosition)](#oh_avsession_setplaybackposition) | - | Sets the playback position.|
| [AVSession_ErrCode OH_AVSession_SetFavorite(OH_AVSession* avsession, bool favorite)](#oh_avsession_setfavorite) | - | Favorites or unfavorites the media asset.|
| [AVSession_ErrCode OH_AVSession_SetLoopMode(OH_AVSession* avsession, AVSession_LoopMode loopMode)](#oh_avsession_setloopmode) | - | Sets a loop mode.|
| [AVSession_ErrCode OH_AVSession_RegisterCommandCallback(OH_AVSession* avsession,AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback, void* userData)](#oh_avsession_registercommandcallback) | - | Registers a callback for a common playback control command.|
| [AVSession_ErrCode OH_AVSession_UnregisterCommandCallback(OH_AVSession* avsession,AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback)](#oh_avsession_unregistercommandcallback) | - | Unregisters the callback for a common playback control command.|
| [AVSession_ErrCode OH_AVSession_RegisterForwardCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnFastForward callback, void* userData)](#oh_avsession_registerforwardcallback) | - | Registers a callback for the fast-forward operation.|
| [AVSession_ErrCode OH_AVSession_UnregisterForwardCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnFastForward callback)](#oh_avsession_unregisterforwardcallback) | - | Unregisters the callback for the fast-forward operation.|
| [AVSession_ErrCode OH_AVSession_RegisterRewindCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnRewind callback, void* userData)](#oh_avsession_registerrewindcallback) | - | Registers a callback for the rewind operation.|
| [AVSession_ErrCode OH_AVSession_UnregisterRewindCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnRewind callback)](#oh_avsession_unregisterrewindcallback) | - | Unregisters the callback for the rewind operation.|
| [AVSession_ErrCode OH_AVSession_RegisterSeekCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnSeek callback, void* userData)](#oh_avsession_registerseekcallback) | - | Registers a callback for the seek operation.|
| [AVSession_ErrCode OH_AVSession_UnregisterSeekCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnSeek callback)](#oh_avsession_unregisterseekcallback) | - | Unregisters the callback for the seek operation.|
| [AVSession_ErrCode OH_AVSession_RegisterSetLoopModeCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnSetLoopMode callback, void* userData)](#oh_avsession_registersetloopmodecallback) | - | Registers a callback for the operation of setting the loop mode.|
| [AVSession_ErrCode OH_AVSession_UnregisterSetLoopModeCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnSetLoopMode callback)](#oh_avsession_unregistersetloopmodecallback) | - | Unregisters the callback for the operation of setting the loop mode.|
| [AVSession_ErrCode OH_AVSession_RegisterToggleFavoriteCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnToggleFavorite callback, void* userData)](#oh_avsession_registertogglefavoritecallback) | - | Registers a callback for the operation of favoriting a media asset.|
| [AVSession_ErrCode OH_AVSession_UnregisterToggleFavoriteCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnToggleFavorite callback)](#oh_avsession_unregistertogglefavoritecallback) | - | Unregisters the callback for the operation of favoriting a media asset.|

## Enums

### AVSession_Type

```
enum AVSession_Type
```

**Description**

Enumerates the session types.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| SESSION_TYPE_AUDIO = 0 | Audio.|
| SESSION_TYPE_VIDEO = 1 | Video.|
| SESSION_TYPE_VOICE_CALL = 2 | Audio call.|
| SESSION_TYPE_VIDEO_CALL = 3 | Video call.|

### AVSession_PlaybackState

```
enum AVSession_PlaybackState
```

**Description**

Enumerates the media playback states.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| PLAYBACK_STATE_INITIAL = 0 | Initial state.|
| PLAYBACK_STATE_PREPARING = 1 | Ready.|
| PLAYBACK_STATE_PLAYING = 2 | Playing.|
| PLAYBACK_STATE_PAUSED = 3 | Paused.|
| PLAYBACK_STATE_FAST_FORWARDING = 4 | Fast-forwarding.|
| PLAYBACK_STATE_REWINDED = 5 | Rewinded.|
| PLAYBACK_STATE_STOPPED = 6 | Stopped.|
| PLAYBACK_STATE_COMPLETED = 7 | Playback complete.|
| PLAYBACK_STATE_RELEASED = 8 | Released.|
| PLAYBACK_STATE_ERROR = 9 | Error.|
| PLAYBACK_STATE_IDLE = 10 | Idle.|
| PLAYBACK_STATE_BUFFERING = 11 | Buffering.|
| PLAYBACK_STATE_MAX = 12 | Maximum value. (Error code 401 is returned in this case.)|

### AVSession_LoopMode

```
enum AVSession_LoopMode
```

**Description**

Enumerates the loop modes of media playback.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| LOOP_MODE_SEQUENCE = 0 | Sequential playback.|
| LOOP_MODE_SINGLE = 1 | Single loop.|
| LOOP_MODE_LIST = 2 | Playlist loop.|
| LOOP_MODE_SHUFFLE = 3 | Shuffle.|
| LOOP_MODE_CUSTOM = 4 | Custom playback.|

### AVSession_ControlCommand

```
enum AVSession_ControlCommand
```

**Description**

Enumerates the playback control commands.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| CONTROL_CMD_INVALID = -1 | Invalid control command.|
| CONTROL_CMD_PLAY = 0 | Play command.|
| CONTROL_CMD_PAUSE = 1 | Pause command.|
| CONTROL_CMD_STOP = 2 | Stop command.|
| CONTROL_CMD_PLAY_NEXT = 3 | Command for playing the next media asset.|
| CONTROL_CMD_PLAY_PREVIOUS = 4 | Command for playing the previous media asset.|

### AVSessionCallback_Result

```
enum AVSessionCallback_Result
```

**Description**

Enumerates the callback execution results.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| AVSESSION_CALLBACK_RESULT_SUCCESS = 0 | The operation is successful.|
| AVSESSION_CALLBACK_RESULT_FAILURE = -1 | The operation fails.|


## Function Description

### OH_AVSessionCallback_OnCommand()

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnCommand)(OH_AVSession* session,AVSession_ControlCommand command, void* userData)
```

**Description**

Defines a callback for a common playback control command.

**Since**: 13

### OH_AVSessionCallback_OnFastForward()

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnFastForward)(OH_AVSession* session,uint32_t seekTime, void* userData)
```

**Description**

Defines a callback for the fast-forward operation.

**Since**: 13

### OH_AVSessionCallback_OnRewind()

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnRewind)(OH_AVSession* session,uint32_t seekTime, void* userData)
```

**Description**

Defines a callback for the rewind operation.

**Since**: 13

### OH_AVSessionCallback_OnSeek()

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnSeek)(OH_AVSession* session,uint64_t seekTime, void* userData)
```

**Description**

Defines a callback for the seek operation.

**Since**: 13

### OH_AVSessionCallback_OnSetLoopMode()

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnSetLoopMode)(OH_AVSession* session,AVSession_LoopMode curLoopMode, void* userData)
```

**Description**

Defines a callback for the operation of setting the loop mode.

**Since**: 13

### OH_AVSessionCallback_OnToggleFavorite()

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnToggleFavorite)(OH_AVSession* session,const char* assetId, void* userData)
```

**Description**

Defines a callback for the operation of favoriting a media asset.

**Since**: 13

### OH_AVSession_Create()

```
AVSession_ErrCode OH_AVSession_Create(AVSession_Type sessionType, const char* sessionTag,const char* bundleName, const char* abilityName, OH_AVSession** avsession)
```

**Description**

Creates a session object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [AVSession_Type](capi-native-avsession-h.md#avsession_type) sessionType |  Session type. For details about the available options, see [AVSession_Type](capi-native-avsession-h.md#avsession_type).|
| const char* sessionTag |   Pointer to the session tag.|
| const char* bundleName |   Pointer to the bundle name.|
| const char* abilityName |  Pointer to the ability name.|
| [OH_AVSession](capi-ohavsession-oh-avsession.md)** avsession |    Double pointer to the session object created.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                 1. **sessionType** is invalid.<br>                                 2. **sessionTag** is nullptr.<br>                                 3. **bundleName** is nullptr.<br>                                 4. **abilityName** is nullptr.<br>                                 5. **avsession** is nullptr.|

### OH_AVSession_Destroy()

```
AVSession_ErrCode OH_AVSession_Destroy(OH_AVSession* avsession)
```

**Description**

Destroys a session object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_INVALID_PARAMETER**: **avsession** is nullptr.|

### OH_AVSession_Activate()

```
AVSession_ErrCode OH_AVSession_Activate(OH_AVSession* avsession)
```

**Description**

Activates a session.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_INVALID_PARAMETER**: **avsession** is nullptr.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.|

### OH_AVSession_Deactivate()

```
AVSession_ErrCode OH_AVSession_Deactivate(OH_AVSession* avsession)
```

**Description**

Deactivates a session.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_INVALID_PARAMETER**: **avsession** is nullptr.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.|

### OH_AVSession_GetSessionType()

```
AVSession_ErrCode OH_AVSession_GetSessionType(OH_AVSession* avsession, AVSession_Type* sessionType)
```

**Description**

Obtains the session type.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [AVSession_Type](capi-native-avsession-h.md#avsession_type)* sessionType | Pointer to the session type obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal or an error occurs.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **sessionType** is nullptr.|

### OH_AVSession_GetSessionId()

```
AVSession_ErrCode OH_AVSession_GetSessionId(OH_AVSession* avsession, const char** sessionId)
```

**Description**

Obtains the session ID.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| const char** sessionId | Double pointer to the session ID obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                 1. **avsession** is nullptr.<br>                                 2. **sessionId** is nullptr.|

### OH_AVSession_SetAVMetadata()

```
AVSession_ErrCode OH_AVSession_SetAVMetadata(OH_AVSession* avsession, OH_AVMetadata* avmetadata)
```

**Description**

Sets media metadata.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVMetadata](capi-ohavsession-oh-avmetadatastruct.md)* avmetadata | Pointer to the media metadata.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                 1. **avsession** is nullptr.<br>                                 2. **avmetadata** is nullptr.|

### OH_AVSession_SetPlaybackState()

```
AVSession_ErrCode OH_AVSession_SetPlaybackState(OH_AVSession* avsession,AVSession_PlaybackState playbackState)
```

**Description**

Sets the playback state.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [AVSession_PlaybackState](capi-native-avsession-h.md#avsession_playbackstate) playbackState | Playback state.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **playbackState** is invalid.|

### OH_AVSession_SetPlaybackPosition()

```
AVSession_ErrCode OH_AVSession_SetPlaybackPosition(OH_AVSession* avsession,AVSession_PlaybackPosition* playbackPosition)
```

**Description**

Sets the playback position.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [AVSession_PlaybackPosition](capi-ohavsession-avsession-playbackposition.md)* playbackPosition | Pointer to the playback position.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                 1. **avsession** is nullptr.<br>                                 2. **playbackPosition** is nullptr.|

### OH_AVSession_SetFavorite()

```
AVSession_ErrCode OH_AVSession_SetFavorite(OH_AVSession* avsession, bool favorite)
```

**Description**

Favorites or unfavorites the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| bool favorite | Whether to favorite or unfavorite the media asset. **true** means to favorite, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**: **avsession** is nullptr.|

### OH_AVSession_SetLoopMode()

```
AVSession_ErrCode OH_AVSession_SetLoopMode(OH_AVSession* avsession, AVSession_LoopMode loopMode)
```

**Description**

Sets a loop mode.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [AVSession_LoopMode](capi-native-avsession-h.md#avsession_loopmode) loopMode | Loop mode.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                   1. **avsession** is nullptr.<br>                                   2. **loopMode** is invalid.|

### OH_AVSession_RegisterCommandCallback()

```
AVSession_ErrCode OH_AVSession_RegisterCommandCallback(OH_AVSession* avsession,AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback, void* userData)
```

**Description**

Registers a callback for a common playback control command.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [AVSession_ControlCommand](capi-native-avsession-h.md#avsession_controlcommand) command |   Playback control command.|
| [OH_AVSessionCallback_OnCommand](capi-native-avsession-h.md#oh_avsessioncallback_oncommand) callback |  Callback for the control command.|
| void* userData |  Pointer to the application data passed through the callback functions.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_CODE_COMMAND_INVALID**: The playback control command is invalid.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_UnregisterCommandCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterCommandCallback(OH_AVSession* avsession,AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback)
```

**Description**

Unregisters the callback for a common playback control command.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [AVSession_ControlCommand](capi-native-avsession-h.md#avsession_controlcommand) command |   Playback control command.|
| [OH_AVSessionCallback_OnCommand](capi-native-avsession-h.md#oh_avsessioncallback_oncommand) callback |  Callback for the control command.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_CODE_COMMAND_INVALID**: The playback control command is invalid.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_RegisterForwardCallback()

```
AVSession_ErrCode OH_AVSession_RegisterForwardCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnFastForward callback, void* userData)
```

**Description**

Registers a callback for the fast-forward operation.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnFastForward](capi-native-avsession-h.md#oh_avsessioncallback_onfastforward) callback | Callback for the fast-forward operation.|
| void* userData | Pointer to the application data passed through the callback functions.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_UnregisterForwardCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterForwardCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnFastForward callback)
```

**Description**

Unregisters the callback for the fast-forward operation.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnFastForward](capi-native-avsession-h.md#oh_avsessioncallback_onfastforward) callback | Callback for the fast-forward operation.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_RegisterRewindCallback()

```
AVSession_ErrCode OH_AVSession_RegisterRewindCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnRewind callback, void* userData)
```

**Description**

Registers a callback for the rewind operation.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnRewind](capi-native-avsession-h.md#oh_avsessioncallback_onrewind) callback | Callback for the rewind operation.|
| void* userData | Pointer to the application data passed through the callback functions.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_UnregisterRewindCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterRewindCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnRewind callback)
```

**Description**

Unregisters the callback for the rewind operation.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnRewind](capi-native-avsession-h.md#oh_avsessioncallback_onrewind) callback | Callback for the rewind operation.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_RegisterSeekCallback()

```
AVSession_ErrCode OH_AVSession_RegisterSeekCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnSeek callback, void* userData)
```

**Description**

Registers a callback for the seek operation.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnSeek](capi-native-avsession-h.md#oh_avsessioncallback_onseek) callback | Callback for the seek operation.|
| void* userData | Pointer to the application data passed through the callback functions.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_UnregisterSeekCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterSeekCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnSeek callback)
```

**Description**

Unregisters the callback for the seek operation.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnSeek](capi-native-avsession-h.md#oh_avsessioncallback_onseek) callback | Callback for the seek operation.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_RegisterSetLoopModeCallback()

```
AVSession_ErrCode OH_AVSession_RegisterSetLoopModeCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnSetLoopMode callback, void* userData)
```

**Description**

Registers a callback for the operation of setting the loop mode.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnSetLoopMode](capi-native-avsession-h.md#oh_avsessioncallback_onsetloopmode) callback | Callback for the operation of setting the loop mode.|
| void* userData | Pointer to the application data passed through the callback functions.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_UnregisterSetLoopModeCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterSetLoopModeCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnSetLoopMode callback)
```

**Description**

Unregisters the callback for the operation of setting the loop mode.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnSetLoopMode](capi-native-avsession-h.md#oh_avsessioncallback_onsetloopmode) callback | Callback for the operation of setting the loop mode.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_RegisterToggleFavoriteCallback()

```
AVSession_ErrCode OH_AVSession_RegisterToggleFavoriteCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnToggleFavorite callback, void* userData)
```

**Description**

Registers a callback for the operation of favoriting a media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnToggleFavorite](capi-native-avsession-h.md#oh_avsessioncallback_ontogglefavorite) callback | Callback for the operation of favoriting a media asset.|
| void* userData | Pointer to the application data passed through the callback functions.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|

### OH_AVSession_UnregisterToggleFavoriteCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterToggleFavoriteCallback(OH_AVSession* avsession,OH_AVSessionCallback_OnToggleFavorite callback)
```

**Description**

Unregisters the callback for the operation of favoriting a media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSession](capi-ohavsession-oh-avsession.md)* avsession | Pointer to a session object.|
| [OH_AVSessionCallback_OnToggleFavorite](capi-native-avsession-h.md#oh_avsessioncallback_ontogglefavorite) callback | Callback for the operation of favoriting a media asset.|

**Returns**

| Type| Description|
| -- | -- |
| [AVSession_ErrCode](capi-native-avsession-errors-h.md#avsession_errcode) | **AV_SESSION_ERR_SUCCESS**: The function is executed successfully.<br> **AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.<br> **AV_SESSION_ERR_INVALID_PARAMETER**:<br>                                  1. **avsession** is nullptr.<br>                                  2. **callback** is nullptr.|
