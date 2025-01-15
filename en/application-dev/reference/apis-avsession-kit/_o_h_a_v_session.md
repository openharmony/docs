# OHAVSession


## Overview

The OHAVSession module defines the C APIs of the playback control module.

You can use OHAVSession to access AVSession as a provider. For details about the development guide and samples, see [AVSession Provider](../../media/avsession/using-ohavsession-developer.md).

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Since**: 13


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avmetadata.h](native__avmetadata_8h.md) | Declares the definitions of playback control metadata.| 
| [native_avsession.h](native__avsession_8h.md) | Declares the AVSession definition, which can be used to set metadata, playback state, and other information.| 
| [native_avsession_errors.h](native__avsession__errors_8h.md) | Declares the playback control error codes.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [AVSession_PlaybackPosition](_a_v_session___playback_position.md) | Describes the information related to the playback position.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct OH_AVMetadataBuilderStruct [OH_AVMetadataBuilder](#oh_avmetadatabuilder) | Defines a struct for the session metadata builder. The builder is used to construct session metadata.| 
| typedef struct OH_AVMetadataStruct [OH_AVMetadata](#oh_avmetadata) | Defines a struct for the session metadata. It is an AVMetadata instance set for a media asset.| 
| typedef struct [AVSession_PlaybackPosition](_a_v_session___playback_position.md) [AVSession_PlaybackPosition](#avsession_playbackposition) | Defines a struct for the information related to the playback position.| 
| typedef enum [AVSession_ControlCommand](#avsession_controlcommand) [AVSession_ControlCommand](#avsession_controlcommand) | Defines an enum for the playback control commands.| 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand)) ([OH_AVSession](#oh_avsession) \*session, [AVSession_ControlCommand](#avsession_controlcommand) command, void \*userData) | Defines a callback for a common playback control command.| 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward)) ([OH_AVSession](#oh_avsession) \*session, uint32_t seekTime, void \*userData) | Defines a callback for the fast-forward operation.| 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind)) ([OH_AVSession](#oh_avsession) \*session, uint32_t seekTime, void \*userData) | Defines a callback for the rewind operation.| 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek)) ([OH_AVSession](#oh_avsession) \*session, uint64_t seekTime, void \*userData) | Defines a callback for the seek operation.| 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode)) ([OH_AVSession](#oh_avsession) \*session, [AVSession_LoopMode](#avsession_loopmode) curLoopMode, void \*userData) | Defines a callback for the operation of setting the loop mode.| 
| typedef [AVSessionCallback_Result](#avsessioncallback_result)(\* [OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite)) ([OH_AVSession](#oh_avsession) \*session, const char \*assetId, void \*userData) | Defines a callback for the operation of favoriting a media asset.| 
| typedef struct [OH_AVSession](#oh_avsession) [OH_AVSession](#oh_avsession) | Defines a struct for the playback control session object.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [AVMetadata_Result](#avmetadata_result) {<br>AVMETADATA_SUCCESS = 0,<br>AVMETADATA_ERROR_INVALID_PARAM = 1,<br>AVMETADATA_ERROR_NO_MEMORY = 2 } | Enumerates the error codes related to metadata operations.| 
| [AVMetadata_SkipIntervals](#avmetadata_skipintervals) {<br>SECONDS_10 = 10,<br>SECONDS_15 = 15,<br>SECONDS_30 = 30 } | Enumerates the fast-forward or rewind intervals supported by the media session.| 
| [AVMetadata_DisplayTag](#avmetadata_displaytag) { AVSESSION_DISPLAYTAG_AUDIO_VIVID = 1 } | Enumerates the display tags of the media asset. The display tag is a special type identifier of the media audio source.| 
| [AVSession_Type](#avsession_type) {<br>SESSION_TYPE_AUDIO = 0,<br>SESSION_TYPE_VIDEO = 1,<br>SESSION_TYPE_VOICE_CALL = 2,<br>SESSION_TYPE_VIDEO_CALL = 3 } | Enumerates the session types.| 
| [AVSession_PlaybackState](#avsession_playbackstate) {<br>PLAYBACK_STATE_INITIAL = 0,<br>PLAYBACK_STATE_PREPARING = 1,<br>PLAYBACK_STATE_PLAYING = 2,<br>PLAYBACK_STATE_PAUSED = 3,<br>PLAYBACK_STATE_FAST_FORWARDING = 4,<br>PLAYBACK_STATE_REWINDED = 5,<br>PLAYBACK_STATE_STOPPED = 6,<br>PLAYBACK_STATE_COMPLETED = 7,<br>PLAYBACK_STATE_RELEASED = 8,<br>PLAYBACK_STATE_ERROR = 9,<br>PLAYBACK_STATE_IDLE = 10,<br>PLAYBACK_STATE_BUFFERING = 11,<br>PLAYBACK_STATE_MAX = 12<br>} | Enumerates the media playback states.| 
| [AVSession_LoopMode](#avsession_loopmode) {<br>LOOP_MODE_SEQUENCE = 0,<br>LOOP_MODE_SINGLE = 1,<br>LOOP_MODE_LIST = 2,<br>LOOP_MODE_SHUFFLE = 3,<br>LOOP_MODE_CUSTOM = 4<br>} | Enumerates the loop modes of media playback.| 
| [AVSession_ControlCommand](#avsession_controlcommand) {<br>CONTROL_CMD_INVALID = -1,<br>CONTROL_CMD_PLAY = 0,<br>CONTROL_CMD_PAUSE = 1,<br>CONTROL_CMD_STOP = 2,<br>CONTROL_CMD_PLAY_NEXT = 3,<br>CONTROL_CMD_PLAY_PREVIOUS = 4<br>} | Enumerates the playback control commands.| 
| [AVSessionCallback_Result](#avsessioncallback_result) {<br>AVSESSION_CALLBACK_RESULT_SUCCESS = 0,<br>AVSESSION_CALLBACK_RESULT_FAILURE = -1 } | Enumerates the callback execution results.| 
| [AVSession_ErrCode](#avsession_errcode) {<br>AV_SESSION_ERR_SUCCESS = 0,<br>AV_SESSION_ERR_INVALID_PARAMETER = 401,<br>AV_SESSION_ERR_SERVICE_EXCEPTION = 6600101,<br>AV_SESSION_ERR_CODE_SESSION_NOT_EXIST = 6600102,<br>AV_SESSION_ERR_CODE_COMMAND_INVALID = 6600105,<br>AV_SESSION_ERR_CODE_SESSION_INACTIVE = 6600106,<br>AV_SESSION_ERR_CODE_MESSAGE_OVERLOAD = 6600107<br>} | Enumerates the playback control error codes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_Create](#oh_avmetadatabuilder_create) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*\*builder) | Creates a metadata builder.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_Destroy](#oh_avmetadatabuilder_destroy) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder) | Destroys a metadata builder.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetAssetId](#oh_avmetadatabuilder_setassetid) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*assetId) | Sets the ID of the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetTitle](#oh_avmetadatabuilder_settitle) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*title) | Sets a title for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetArtist](#oh_avmetadatabuilder_setartist) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*artist) | Sets an artist for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetAuthor](#oh_avmetadatabuilder_setauthor) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*author) | Sets an author for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetAlbum](#oh_avmetadatabuilder_setalbum) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*album) | Sets an album name for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetWriter](#oh_avmetadatabuilder_setwriter) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*writer) | Sets a writer for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetComposer](#oh_avmetadatabuilder_setcomposer) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*composer) | Sets a composer for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetDuration](#oh_avmetadatabuilder_setduration) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, int64_t duration) | Sets the playback duration for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetMediaImageUri](#oh_avmetadatabuilder_setmediaimageuri) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*mediaImageUri) | Sets an image for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetSubtitle](#oh_avmetadatabuilder_setsubtitle) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*subtitle) | Sets a subtitle for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetDescription](#oh_avmetadatabuilder_setdescription) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*description) | Sets a description for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetLyric](#oh_avmetadatabuilder_setlyric) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, const char \*lyric) | Sets lyrics for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetSkipIntervals](#oh_avmetadatabuilder_setskipintervals) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, [AVMetadata_SkipIntervals](#avmetadata_skipintervals) intervals) | Sets the skip intervals for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_SetDisplayTags](#oh_avmetadatabuilder_setdisplaytags) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, int32_t tags) | Sets display tags for the media asset.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadataBuilder_GenerateAVMetadata](#oh_avmetadatabuilder_generateavmetadata) ([OH_AVMetadataBuilder](#oh_avmetadatabuilder) \*builder, [OH_AVMetadata](#oh_avmetadata) \*\*avMetadata) | Generates an **OH_AVMetadata** object.| 
| [AVMetadata_Result](#avmetadata_result) [OH_AVMetadata_Destroy](#oh_avmetadata_destroy) ([OH_AVMetadata](#oh_avmetadata) \*avMetadata) | Releases an **OH_AVMetadata** object.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_Create](#oh_avsession_create) ([AVSession_Type](#avsession_type) sessionType, const char \*sessionTag, const char \*bundleName, const char \*abilityName, [OH_AVSession](#oh_avsession) \*\*avsession) | Creates a session object.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_Destroy](#oh_avsession_destroy) ([OH_AVSession](#oh_avsession) \*avsession) | Destroys a session object.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_Activate](#oh_avsession_activate) ([OH_AVSession](#oh_avsession) \*avsession) | Activates a session.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_Deactivate](#oh_avsession_deactivate) ([OH_AVSession](#oh_avsession) \*avsession) | Deactivates a session.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_GetSessionType](#oh_avsession_getsessiontype) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_Type](#avsession_type) \*sessionType) | Obtains the session type.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_GetSessionId](#oh_avsession_getsessionid) ([OH_AVSession](#oh_avsession) \*avsession, const char \*\*sessionId) | Obtains the session ID.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetAVMetadata](#oh_avsession_setavmetadata) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVMetadata](#oh_avmetadata) \*avmetadata) | Sets media metadata.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetPlaybackState](#oh_avsession_setplaybackstate) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_PlaybackState](#avsession_playbackstate) playbackState) | Sets the playback state.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetPlaybackPosition](#oh_avsession_setplaybackposition) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_PlaybackPosition](_a_v_session___playback_position.md) \*playbackPosition) | Sets the playback position.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetFavorite](#oh_avsession_setfavorite) ([OH_AVSession](#oh_avsession) \*avsession, bool favorite) | Favorites or unfavorites the media asset.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_SetLoopMode](#oh_avsession_setloopmode) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_LoopMode](#avsession_loopmode) loopMode) | Sets a loop mode.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterCommandCallback](#oh_avsession_registercommandcallback) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_ControlCommand](#avsession_controlcommand) command, [OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand) callback, void \*userData) | Registers a callback for a common playback control command.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterCommandCallback](#oh_avsession_unregistercommandcallback) ([OH_AVSession](#oh_avsession) \*avsession, [AVSession_ControlCommand](#avsession_controlcommand) command, [OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand) callback) | Unregisters the callback for a common playback control command.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterForwardCallback](#oh_avsession_registerforwardcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward) callback, void \*userData) | Registers a callback for the fast-forward operation.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterForwardCallback](#oh_avsession_unregisterforwardcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward) callback) | Unregisters the callback for the fast-forward operation.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterRewindCallback](#oh_avsession_registerrewindcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind) callback, void \*userData) | Registers a callback for the rewind operation.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterRewindCallback](#oh_avsession_unregisterrewindcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind) callback) | Unregisters the callback for the rewind operation.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterSeekCallback](#oh_avsession_registerseekcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek) callback, void \*userData) | Registers a callback for the seek operation.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterSeekCallback](#oh_avsession_unregisterseekcallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek) callback) | Unregisters the callback for the seek operation.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterSetLoopModeCallback](#oh_avsession_registersetloopmodecallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode) callback, void \*userData) | Registers a callback for the operation of setting the loop mode.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterSetLoopModeCallback](#oh_avsession_unregistersetloopmodecallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode) callback) | Unregisters the callback for the operation of setting the loop mode.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_RegisterToggleFavoriteCallback](#oh_avsession_registertogglefavoritecallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite) callback, void \*userData) | Registers a callback for the operation of favoriting a media asset.| 
| [AVSession_ErrCode](#avsession_errcode) [OH_AVSession_UnregisterToggleFavoriteCallback](#oh_avsession_unregistertogglefavoritecallback) ([OH_AVSession](#oh_avsession) \*avsession, [OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite) callback) | Unregisters the callback for the operation of favoriting a media asset.| 


## Type Description


### AVSession_ControlCommand

```
typedef enum AVSession_ControlCommand AVSession_ControlCommand
```

**Description**

Defines an enum for the playback control commands.

**Since**: 13


### AVSession_PlaybackPosition

```
typedef struct AVSession_PlaybackPosition AVSession_PlaybackPosition
```

**Description**

Defines a struct for the information related to the playback position.

**Since**: 13


### OH_AVMetadata

```
typedef struct OH_AVMetadataStruct OH_AVMetadata
```

**Description**

Defines a struct for the session metadata. It is an AVMetadata instance set for a media asset.

**Since**: 13


### OH_AVMetadataBuilder

```
typedef struct OH_AVMetadataBuilderStruct OH_AVMetadataBuilder
```

**Description**

Defines a struct for the session metadata builder. The builder is used to construct session metadata.

**Since**: 13


### OH_AVSession

```
typedef struct OH_AVSession OH_AVSession
```

**Description**

Defines a struct for the playback control session object.

You can use **OH_AVSession_Create** to create such an object.

**Since**: 13


### OH_AVSessionCallback_OnCommand

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnCommand)(OH_AVSession* session, AVSession_ControlCommand command, void* userData)
```

**Description**

Defines a callback for a common playback control command.

**Since**: 13


### OH_AVSessionCallback_OnFastForward

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnFastForward)(OH_AVSession* session, uint32_t seekTime, void* userData)
```

**Description**

Defines a callback for the fast-forward operation.

**Since**: 13


### OH_AVSessionCallback_OnRewind

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnRewind)(OH_AVSession* session, uint32_t seekTime, void* userData)
```

**Description**

Defines a callback for the rewind operation.

**Since**: 13


### OH_AVSessionCallback_OnSeek

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnSeek)(OH_AVSession* session, uint64_t seekTime, void* userData)
```

**Description**

Defines a callback for the seek operation.

**Since**: 13


### OH_AVSessionCallback_OnSetLoopMode

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnSetLoopMode)(OH_AVSession* session, AVSession_LoopMode curLoopMode, void* userData)
```

**Description**

Defines a callback for the operation of setting the loop mode.

**Since**: 13


### OH_AVSessionCallback_OnToggleFavorite

```
typedef AVSessionCallback_Result (*OH_AVSessionCallback_OnToggleFavorite)(OH_AVSession* session, const char* assetId, void* userData)
```

**Description**

Defines a callback for the operation of favoriting a media asset.

**Since**: 13


## Enums


### AVMetadata_DisplayTag

```
enum AVMetadata_DisplayTag
```

**Description**

Enumerates the display tags of the media asset. The display tag is a special type identifier of the media audio source.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| AVSESSION_DISPLAYTAG_AUDIO_VIVID | AUDIO VIVID.| 


### AVMetadata_Result

```
enum AVMetadata_Result
```

**Description**

Enumerates the error codes related to metadata operations.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| AVMETADATA_SUCCESS | Operation successful.| 
| AVMETADATA_ERROR_INVALID_PARAM | Incorrect parameter.| 
| AVMETADATA_ERROR_NO_MEMORY | Insufficient memory.| 


### AVMetadata_SkipIntervals

```
enum AVMetadata_SkipIntervals
```

**Description**

Enumerates the fast-forward or rewind intervals supported by the media session.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| SECONDS_10 | The time is 10 seconds.| 
| SECONDS_15 | The time is 15 seconds.| 
| SECONDS_30 | The time is 30 seconds.| 


### AVSession_ControlCommand

```
enum AVSession_ControlCommand
```

**Description**

Enumerates the playback control commands.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| CONTROL_CMD_INVALID | Invalid control command.| 
| CONTROL_CMD_PLAY | Play command.| 
| CONTROL_CMD_PAUSE | Pause command.| 
| CONTROL_CMD_STOP | Stop command.| 
| CONTROL_CMD_PLAY_NEXT | Command for playing the next media asset.| 
| CONTROL_CMD_PLAY_PREVIOUS | Command for playing the previous media asset.| 


### AVSession_ErrCode

```
enum AVSession_ErrCode
```

**Description**

Enumerates the playback control error codes.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| AV_SESSION_ERR_SUCCESS | The operation is successful.| 
| AV_SESSION_ERR_INVALID_PARAMETER | Parameter check fails.| 
| AV_SESSION_ERR_SERVICE_EXCEPTION | The session server is abnormal.| 
| AV_SESSION_ERR_CODE_SESSION_NOT_EXIST | The session does not exist.| 
| AV_SESSION_ERR_CODE_COMMAND_INVALID | The session command is invalid.| 
| AV_SESSION_ERR_CODE_SESSION_INACTIVE | The session is not activated.| 
| AV_SESSION_ERR_CODE_MESSAGE_OVERLOAD | Command and message overflow.| 


### AVSession_LoopMode

```
enum AVSession_LoopMode
```

**Description**

Enumerates the loop modes of media playback.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| LOOP_MODE_SEQUENCE | Sequential playback.| 
| LOOP_MODE_SINGLE | Single loop.| 
| LOOP_MODE_LIST | Playlist loop.| 
| LOOP_MODE_SHUFFLE | Shuffle.| 
| LOOP_MODE_CUSTOM | Custom playback.| 


### AVSession_PlaybackState

```
enum AVSession_PlaybackState
```

**Description**

Enumerates the media playback states.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| PLAYBACK_STATE_INITIAL | Initial state.| 
| PLAYBACK_STATE_PREPARING | Ready.| 
| PLAYBACK_STATE_PLAYING | Playing.| 
| PLAYBACK_STATE_PAUSED | Paused.| 
| PLAYBACK_STATE_FAST_FORWARDING | Fast-forwarding.| 
| PLAYBACK_STATE_REWINDED | Rewinded.| 
| PLAYBACK_STATE_STOPPED | Stopped.| 
| PLAYBACK_STATE_COMPLETED | Playback complete.| 
| PLAYBACK_STATE_RELEASED | Released.| 
| PLAYBACK_STATE_ERROR | Error.| 
| PLAYBACK_STATE_IDLE | Idle.| 
| PLAYBACK_STATE_BUFFERING | Buffering.| 
| PLAYBACK_STATE_MAX | Maximum value. (Error code 401 is returned in this case.)| 


### AVSession_Type

```
enum AVSession_Type
```

**Description**

Enumerates the session types.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| SESSION_TYPE_AUDIO | Audio.| 
| SESSION_TYPE_VIDEO | Video.| 
| SESSION_TYPE_VOICE_CALL | Audio call.| 
| SESSION_TYPE_VIDEO_CALL | Video call.| 


### AVSessionCallback_Result

```
enum AVSessionCallback_Result
```

**Description**

Enumerates the callback execution results.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| AVSESSION_CALLBACK_RESULT_SUCCESS | The operation is successful.| 
| AVSESSION_CALLBACK_RESULT_FAILURE | The operation fails.| 


## Function Description


### OH_AVMetadata_Destroy()

```
AVMetadata_Result OH_AVMetadata_Destroy(OH_AVMetadata* avMetadata)
```

**Description**

Releases an **OH_AVMetadata** object.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avMetadata | Pointer to an **OH_AVMetadata** object.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**: **avMetadata** is a null pointer.


### OH_AVMetadataBuilder_Create()

```
AVMetadata_Result OH_AVMetadataBuilder_Create(OH_AVMetadataBuilder** builder)
```

**Description**

Creates a metadata builder.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Double pointer to the builder created.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**: **builder** is a null pointer.

**AVMETADATA_ERROR_NO_MEMORY**: There is no sufficient memory.


### OH_AVMetadataBuilder_Destroy()

```
AVMetadata_Result OH_AVMetadataBuilder_Destroy(OH_AVMetadataBuilder* builder)
```

**Description**

Destroys a metadata builder.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**: **builder** is a null pointer.


### OH_AVMetadataBuilder_GenerateAVMetadata()

```
AVMetadata_Result OH_AVMetadataBuilder_GenerateAVMetadata(OH_AVMetadataBuilder* builder, OH_AVMetadata** avMetadata)
```

**Description**

Generates an **OH_AVMetadata** object.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| avMetadata | Double pointer to the **OH_AVMetadata** object created.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_NO_MEMORY**: The memory is insufficient.

**AVMETADATA_ERROR_INVALID_PARAM**:

1. **builder** is a null pointer.

2. **avMetadata** is a null pointer.


### OH_AVMetadataBuilder_SetAlbum()

```
AVMetadata_Result OH_AVMetadataBuilder_SetAlbum(OH_AVMetadataBuilder* builder, const char* album)
```

**Description**

Sets an album name for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| album | Pointer to the album name.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:
1. **builder** is a null pointer.

2. **album** is a null pointer.


### OH_AVMetadataBuilder_SetArtist()

```
AVMetadata_Result OH_AVMetadataBuilder_SetArtist(OH_AVMetadataBuilder* builder, const char* artist)
```

**Description**

Sets an artist for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| artist | Pointer to the artist.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:
1. **builder** is a null pointer.

2. **artist** is a null pointer.


### OH_AVMetadataBuilder_SetAssetId()

```
AVMetadata_Result OH_AVMetadataBuilder_SetAssetId(OH_AVMetadataBuilder* builder, const char* assetId)
```

**Description**

Sets the ID of the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| assetId | Pointer to the asset ID.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:

1. **builder** is a null pointer.

2. **assetId** is a null pointer.


### OH_AVMetadataBuilder_SetAuthor()

```
AVMetadata_Result OH_AVMetadataBuilder_SetAuthor(OH_AVMetadataBuilder* builder, const char* author)
```

**Description**

Sets an author for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| author | Pointer to the author.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:

1. **builder** is a null pointer.

2. **author** is a null pointer.


### OH_AVMetadataBuilder_SetComposer()

```
AVMetadata_Result OH_AVMetadataBuilder_SetComposer(OH_AVMetadataBuilder* builder, const char* composer)
```

**Description**

Sets a composer for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| composer | Pointer to the composer.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:
1. **builder** is a null pointer.

2. **composer** is a null pointer.


### OH_AVMetadataBuilder_SetDescription()

```
AVMetadata_Result OH_AVMetadataBuilder_SetDescription(OH_AVMetadataBuilder* builder, const char* description)
```

**Description**

Sets a description for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| description | Pointer to the description.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:

1. **builder** is a null pointer.

2. **description** is a null pointer.


### OH_AVMetadataBuilder_SetDisplayTags()

```
AVMetadata_Result OH_AVMetadataBuilder_SetDisplayTags(OH_AVMetadataBuilder* builder, int32_t tags)
```

**Description**

Sets display tags for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| tags | Tags of the media asset displayed on the playback control page.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**: **builder** is a null pointer.


### OH_AVMetadataBuilder_SetDuration()

```
AVMetadata_Result OH_AVMetadataBuilder_SetDuration(OH_AVMetadataBuilder* builder, int64_t duration)
```

**Description**

Sets the playback duration for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| duration | Playback duration, in ms.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**: **builder** is a null pointer.


### OH_AVMetadataBuilder_SetLyric()

```
AVMetadata_Result OH_AVMetadataBuilder_SetLyric(OH_AVMetadataBuilder* builder, const char* lyric)
```

**Description**

Sets lyrics for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| lyric | Pointer to the lyrics in the lrc format.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:

1. **builder** is a null pointer.

2. **lyric** is a null pointer.


### OH_AVMetadataBuilder_SetMediaImageUri()

```
AVMetadata_Result OH_AVMetadataBuilder_SetMediaImageUri(OH_AVMetadataBuilder* builder, const char* mediaImageUri)
```

**Description**

Sets an image for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| mediaImageUri | Pointer to the URI of the image.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:

1. **builder** is a null pointer.

2. **mediaImageUri** is a null pointer.


### OH_AVMetadataBuilder_SetSkipIntervals()

```
AVMetadata_Result OH_AVMetadataBuilder_SetSkipIntervals(OH_AVMetadataBuilder* builder, AVMetadata_SkipIntervals intervals)
```

**Description**

Sets the skip intervals for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| intervals | Skip intervals.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:

1. **builder** is a null pointer.

2. **intervals** is invalid.


### OH_AVMetadataBuilder_SetSubtitle()

```
AVMetadata_Result OH_AVMetadataBuilder_SetSubtitle(OH_AVMetadataBuilder* builder, const char* subtitle)
```

**Description**

Sets a subtitle for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| subtitle | Pointer to the subtitle.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:

1. **builder** is a null pointer.

2. **subtitle** is a null pointer.


### OH_AVMetadataBuilder_SetTitle()

```
AVMetadata_Result OH_AVMetadataBuilder_SetTitle(OH_AVMetadataBuilder* builder, const char* title)
```

**Description**

Sets a title for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| title | Pointer to the title.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:
1. **builder** is a null pointer.

2. **title** is a null pointer.


### OH_AVMetadataBuilder_SetWriter()

```
AVMetadata_Result OH_AVMetadataBuilder_SetWriter(OH_AVMetadataBuilder* builder, const char* writer)
```

**Description**

Sets a writer for the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| builder | Pointer to an **OH_AVMetadataBuilder** instance.| 
| writer | Pointer to the writer.| 

**Returns**

Returns one of the following result codes defined in [AVMetadata_Result](#avmetadata_result):

**AVMETADATA_SUCCESS**: The function is executed successfully.

**AVMETADATA_ERROR_INVALID_PARAM**:
1. **builder** is a null pointer.

2. **writer** is a null pointer.


### OH_AVSession_Activate()

```
AVSession_ErrCode OH_AVSession_Activate(OH_AVSession* avsession)
```

**Description**

Activates a session.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_INVALID_PARAMETER**: **avsession** is a null pointer.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.


### OH_AVSession_Create()

```
AVSession_ErrCode OH_AVSession_Create(AVSession_Type sessionType, const char* sessionTag, const char* bundleName, const char* abilityName, OH_AVSession** avsession)
```

**Description**

Creates a session object.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| sessionType | Session type. For details about the available options, see [AVSession_Type](#avsession_type).| 
| sessionTag | Pointer to the session tag.| 
| bundleName | Pointer to the bundle name.| 
| abilityName | Pointer to the ability name.| 
| avsession | Double pointer to the session object created.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**link AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal or the session object already exists.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **sessionType** is invalid.

2. **sessionTag** is a null pointer.

3. **bundleName** is a null pointer.

4. **abilityName** is a null pointer.

5. **avsession** is a null pointer.


### OH_AVSession_Deactivate()

```
AVSession_ErrCode OH_AVSession_Deactivate(OH_AVSession* avsession)
```

**Description**

Deactivates a session.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_INVALID_PARAMETER**: **avsession** is a null pointer.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.


### OH_AVSession_Destroy()

```
AVSession_ErrCode OH_AVSession_Destroy(OH_AVSession* avsession)
```

**Description**

Destroys a session object.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_INVALID_PARAMETER**: **avsession** is a null pointer.


### OH_AVSession_GetSessionId()

```
AVSession_ErrCode OH_AVSession_GetSessionId(OH_AVSession* avsession, const char** sessionId)
```

**Description**

Obtains the session ID.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| sessionId | Double pointer to the session ID obtained.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal or an error occurs.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **sessionId** is a null pointer.


### OH_AVSession_GetSessionType()

```
AVSession_ErrCode OH_AVSession_GetSessionType(OH_AVSession* avsession, AVSession_Type* sessionType)
```

**Description**

Obtains the session type.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| sessionType | Pointer to the session type obtained.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal or an error occurs.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **sessionType** is a null pointer.


### OH_AVSession_RegisterCommandCallback()

```
AVSession_ErrCode OH_AVSession_RegisterCommandCallback(OH_AVSession* avsession, AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback, void* userData)
```

**Description**

Registers a callback for a common playback control command.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| command | Playback control command.| 
| callback | Callback to register, which is [OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand).| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_CODE_COMMAND_INVALID**: The playback control command is invalid.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_RegisterForwardCallback()

```
AVSession_ErrCode OH_AVSession_RegisterForwardCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnFastForward callback, void* userData)
```

**Description**

Registers a callback for the fast-forward operation.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to register, which issue [OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward).| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_RegisterRewindCallback()

```
AVSession_ErrCode OH_AVSession_RegisterRewindCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnRewind callback, void* userData)
```

**Description**

Registers a callback for the rewind operation.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to register, which is [OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind).| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_RegisterSeekCallback()

```
AVSession_ErrCode OH_AVSession_RegisterSeekCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSeek callback, void* userData)
```

**Description**

Registers a callback for the seek operation.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to register, which is [OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek).| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_RegisterSetLoopModeCallback()

```
AVSession_ErrCode OH_AVSession_RegisterSetLoopModeCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSetLoopMode callback, void* userData)
```

**Description**

Registers a callback for the operation of setting the loop mode.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to register, which is [OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode).| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_RegisterToggleFavoriteCallback()

```
AVSession_ErrCode OH_AVSession_RegisterToggleFavoriteCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnToggleFavorite callback, void* userData)
```

**Description**

Registers a callback for the operation of favoriting a media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to register, which is [OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite).| 
| userData | Pointer to the application data passed through the callback functions.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_SetAVMetadata()

```
AVSession_ErrCode OH_AVSession_SetAVMetadata(OH_AVSession* avsession, OH_AVMetadata* avmetadata)
```

**Description**

Sets media metadata.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| avmetadata | Pointer to the media metadata.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **avmetadata** is a null pointer.


### OH_AVSession_SetFavorite()

```
AVSession_ErrCode OH_AVSession_SetFavorite(OH_AVSession* avsession, bool favorite)
```

**Description**

Favorites or unfavorites the media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| favorite | Whether to favorite or unfavorite the media asset. The value **true** means to favorite the media asset, and **false** means the opposite.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**: **avsession** is a null pointer.


### OH_AVSession_SetLoopMode()

```
AVSession_ErrCode OH_AVSession_SetLoopMode(OH_AVSession* avsession, AVSession_LoopMode loopMode)
```

**Description**

Sets a loop mode.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| loopMode | Loop mode.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **loopMode** is invalid.


### OH_AVSession_SetPlaybackPosition()

```
AVSession_ErrCode OH_AVSession_SetPlaybackPosition(OH_AVSession* avsession, AVSession_PlaybackPosition* playbackPosition)
```

**Description**

Sets the playback position.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| playbackPosition | Pointer to the playback position.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **playbackPosition** is a null pointer.


### OH_AVSession_SetPlaybackState()

```
AVSession_ErrCode OH_AVSession_SetPlaybackState(OH_AVSession* avsession, AVSession_PlaybackState playbackState)
```

**Description**

Sets the playback state.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| playbackState | Playback state.| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **playbackState** is invalid.


### OH_AVSession_UnregisterCommandCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterCommandCallback(OH_AVSession* avsession, AVSession_ControlCommand command, OH_AVSessionCallback_OnCommand callback)
```

**Description**

Unregisters the callback for a common playback control command.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| command | Playback control command.| 
| callback | Callback to unregister, which is [OH_AVSessionCallback_OnCommand](#oh_avsessioncallback_oncommand).| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_CODE_COMMAND_INVALID**: The playback control command is invalid.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_UnregisterForwardCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterForwardCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnFastForward callback)
```

**Description**

Unregisters the callback for the fast-forward operation.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to unregister, which issue [OH_AVSessionCallback_OnFastForward](#oh_avsessioncallback_onfastforward).| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_UnregisterRewindCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterRewindCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnRewind callback)
```

**Description**

Unregisters the callback for the rewind operation.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to unregister, which is [OH_AVSessionCallback_OnRewind](#oh_avsessioncallback_onrewind).| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_UnregisterSeekCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterSeekCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSeek callback)
```

**Description**

Unregisters the callback for the seek operation.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to unregister, which is [OH_AVSessionCallback_OnSeek](#oh_avsessioncallback_onseek).| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_UnregisterSetLoopModeCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterSetLoopModeCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSetLoopMode callback)
```

**Description**

Unregisters the callback for the operation of setting the loop mode.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to unregister, which is [OH_AVSessionCallback_OnSetLoopMode](#oh_avsessioncallback_onsetloopmode).| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.


### OH_AVSession_UnregisterToggleFavoriteCallback()

```
AVSession_ErrCode OH_AVSession_UnregisterToggleFavoriteCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnToggleFavorite callback)
```

**Description**

Unregisters the callback for the operation of favoriting a media asset.

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| avsession | Pointer to a session object.| 
| callback | Callback to unregister, which is [OH_AVSessionCallback_OnToggleFavorite](#oh_avsessioncallback_ontogglefavorite).| 

**Returns**

Returns one of the following result codes defined in [AVSession_ErrCode](#avsession_errcode):

**AV_SESSION_ERR_SUCCESS**: The function is executed successfully.

**AV_SESSION_ERR_SERVICE_EXCEPTION**: The session service is abnormal.

**AV_SESSION_ERR_INVALID_PARAMETER**:

1. **avsession** is a null pointer.

2. **callback** is a null pointer.
