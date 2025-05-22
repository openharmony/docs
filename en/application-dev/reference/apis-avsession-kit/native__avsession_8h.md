# native_avsession.h


## Overview

The **native_avsession.h** file declares the AVSession definition, which can be used to set metadata, playback state, and other information.

**Library**: libohavsession.so

**File to include**: &lt;multimedia/av_session/native_avsession.h&gt;

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Since**: 13

**Related module**: [OHAVSession](_o_h_a_v_session.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [AVSession_PlaybackPosition](_a_v_session___playback_position.md) | Describes the information related to the playback position.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [AVSession_PlaybackPosition](_a_v_session___playback_position.md) [AVSession_PlaybackPosition](_o_h_a_v_session.md#avsession_playbackposition) | Defines a struct for the information related to the playback position.| 
| typedef enum [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) | Defines an enum for the playback control commands.| 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnCommand](_o_h_a_v_session.md#oh_avsessioncallback_oncommand)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) command, void \*userData) | Defines a callback for a common playback control command.| 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnFastForward](_o_h_a_v_session.md#oh_avsessioncallback_onfastforward)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, uint32_t seekTime, void \*userData) | Defines a callback for the fast-forward operation.| 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnRewind](_o_h_a_v_session.md#oh_avsessioncallback_onrewind)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, uint32_t seekTime, void \*userData) | Defines a callback for the rewind operation.| 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnSeek](_o_h_a_v_session.md#oh_avsessioncallback_onseek)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, uint64_t seekTime, void \*userData) | Defines a callback for the seek operation.| 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnSetLoopMode](_o_h_a_v_session.md#oh_avsessioncallback_onsetloopmode)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, [AVSession_LoopMode](_o_h_a_v_session.md#avsession_loopmode) curLoopMode, void \*userData) | Defines a callback for the operation of setting the loop mode.| 
| typedef [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result)(\* [OH_AVSessionCallback_OnToggleFavorite](_o_h_a_v_session.md#oh_avsessioncallback_ontogglefavorite)) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*session, const char \*assetId, void \*userData) | Defines a callback for the operation of favoriting a media asset.| 
| typedef struct [OH_AVSession](_o_h_a_v_session.md#oh_avsession) [OH_AVSession](_o_h_a_v_session.md#oh_avsession) | Defines a struct for the playback control session object.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [AVSession_Type](_o_h_a_v_session.md#avsession_type) {<br>SESSION_TYPE_AUDIO = 0,<br>SESSION_TYPE_VIDEO = 1,<br>SESSION_TYPE_VOICE_CALL = 2,<br>SESSION_TYPE_VIDEO_CALL = 3 } | Enumerates the session types.| 
| [AVSession_PlaybackState](_o_h_a_v_session.md#avsession_playbackstate) {<br>PLAYBACK_STATE_INITIAL = 0,<br>PLAYBACK_STATE_PREPARING = 1,<br>PLAYBACK_STATE_PLAYING = 2,<br>PLAYBACK_STATE_PAUSED = 3,<br>PLAYBACK_STATE_FAST_FORWARDING = 4,<br>PLAYBACK_STATE_REWINDED = 5,<br>PLAYBACK_STATE_STOPPED = 6,<br>PLAYBACK_STATE_COMPLETED = 7,<br>PLAYBACK_STATE_RELEASED = 8,<br>PLAYBACK_STATE_ERROR = 9,<br>PLAYBACK_STATE_IDLE = 10,<br>PLAYBACK_STATE_BUFFERING = 11,<br>PLAYBACK_STATE_MAX = 12<br>} | Enumerates the media playback states.| 
| [AVSession_LoopMode](_o_h_a_v_session.md#avsession_loopmode) {<br>LOOP_MODE_SEQUENCE = 0,<br>LOOP_MODE_SINGLE = 1,<br>LOOP_MODE_LIST = 2,<br>LOOP_MODE_SHUFFLE = 3,<br>LOOP_MODE_CUSTOM = 4<br>} | Enumerates the loop modes of media playback.| 
| [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) {<br>CONTROL_CMD_INVALID = -1,<br>CONTROL_CMD_PLAY = 0,<br>CONTROL_CMD_PAUSE = 1,<br>CONTROL_CMD_STOP = 2,<br>CONTROL_CMD_PLAY_NEXT = 3,<br>CONTROL_CMD_PLAY_PREVIOUS = 4<br>} | Enumerates the playback control commands.| 
| [AVSessionCallback_Result](_o_h_a_v_session.md#avsessioncallback_result) {<br>AVSESSION_CALLBACK_RESULT_SUCCESS = 0,<br>AVSESSION_CALLBACK_RESULT_FAILURE = -1 } | Enumerates the callback execution results.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_Create](_o_h_a_v_session.md#oh_avsession_create) ([AVSession_Type](_o_h_a_v_session.md#avsession_type) sessionType, const char \*sessionTag, const char \*bundleName, const char \*abilityName, [OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*\*avsession) | Creates a session object.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_Destroy](_o_h_a_v_session.md#oh_avsession_destroy) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession) | Destroys a session object.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_Activate](_o_h_a_v_session.md#oh_avsession_activate) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession) | Activates a session.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_Deactivate](_o_h_a_v_session.md#oh_avsession_deactivate) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession) | Deactivates a session.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_GetSessionType](_o_h_a_v_session.md#oh_avsession_getsessiontype) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_Type](_o_h_a_v_session.md#avsession_type) \*sessionType) | Obtains the session type.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_GetSessionId](_o_h_a_v_session.md#oh_avsession_getsessionid) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, const char \*\*sessionId) | Obtains the session ID.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetAVMetadata](_o_h_a_v_session.md#oh_avsession_setavmetadata) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVMetadata](_o_h_a_v_session.md#oh_avmetadata) \*avmetadata) | Sets media metadata.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetPlaybackState](_o_h_a_v_session.md#oh_avsession_setplaybackstate) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_PlaybackState](_o_h_a_v_session.md#avsession_playbackstate) playbackState) | Sets the playback state.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetPlaybackPosition](_o_h_a_v_session.md#oh_avsession_setplaybackposition) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_PlaybackPosition](_a_v_session___playback_position.md) \*playbackPosition) | Sets the playback position.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetFavorite](_o_h_a_v_session.md#oh_avsession_setfavorite) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, bool favorite) | Favorites or unfavorites the media asset.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_SetLoopMode](_o_h_a_v_session.md#oh_avsession_setloopmode) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_LoopMode](_o_h_a_v_session.md#avsession_loopmode) loopMode) | Sets the loop mode.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterCommandCallback](_o_h_a_v_session.md#oh_avsession_registercommandcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) command, [OH_AVSessionCallback_OnCommand](_o_h_a_v_session.md#oh_avsessioncallback_oncommand) callback, void \*userData) | Registers a callback for a common playback control command.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterCommandCallback](_o_h_a_v_session.md#oh_avsession_unregistercommandcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [AVSession_ControlCommand](_o_h_a_v_session.md#avsession_controlcommand) command, [OH_AVSessionCallback_OnCommand](_o_h_a_v_session.md#oh_avsessioncallback_oncommand) callback) | Unregisters the callback for a common playback control command.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterForwardCallback](_o_h_a_v_session.md#oh_avsession_registerforwardcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnFastForward](_o_h_a_v_session.md#oh_avsessioncallback_onfastforward) callback, void \*userData) | Registers a callback for the fast-forward operation.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterForwardCallback](_o_h_a_v_session.md#oh_avsession_unregisterforwardcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnFastForward](_o_h_a_v_session.md#oh_avsessioncallback_onfastforward) callback) | Unregisters the callback for the fast-forward operation.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterRewindCallback](_o_h_a_v_session.md#oh_avsession_registerrewindcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnRewind](_o_h_a_v_session.md#oh_avsessioncallback_onrewind) callback, void \*userData) | Registers a callback for the rewind operation.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterRewindCallback](_o_h_a_v_session.md#oh_avsession_unregisterrewindcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnRewind](_o_h_a_v_session.md#oh_avsessioncallback_onrewind) callback) | Unregisters the callback for the rewind operation.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterSeekCallback](_o_h_a_v_session.md#oh_avsession_registerseekcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSeek](_o_h_a_v_session.md#oh_avsessioncallback_onseek) callback, void \*userData) | Registers a callback for the seek operation.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterSeekCallback](_o_h_a_v_session.md#oh_avsession_unregisterseekcallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSeek](_o_h_a_v_session.md#oh_avsessioncallback_onseek) callback) | Unregisters the callback for the seek operation.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterSetLoopModeCallback](_o_h_a_v_session.md#oh_avsession_registersetloopmodecallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSetLoopMode](_o_h_a_v_session.md#oh_avsessioncallback_onsetloopmode) callback, void \*userData) | Registers a callback for the operation of setting the loop mode.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterSetLoopModeCallback](_o_h_a_v_session.md#oh_avsession_unregistersetloopmodecallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnSetLoopMode](_o_h_a_v_session.md#oh_avsessioncallback_onsetloopmode) callback) | Unregisters the callback for the operation of setting the loop mode.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_RegisterToggleFavoriteCallback](_o_h_a_v_session.md#oh_avsession_registertogglefavoritecallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnToggleFavorite](_o_h_a_v_session.md#oh_avsessioncallback_ontogglefavorite) callback, void \*userData) | Registers a callback for the operation of favoriting a media asset.| 
| [AVSession_ErrCode](_o_h_a_v_session.md#avsession_errcode) [OH_AVSession_UnregisterToggleFavoriteCallback](_o_h_a_v_session.md#oh_avsession_unregistertogglefavoritecallback) ([OH_AVSession](_o_h_a_v_session.md#oh_avsession) \*avsession, [OH_AVSessionCallback_OnToggleFavorite](_o_h_a_v_session.md#oh_avsessioncallback_ontogglefavorite) callback) | Unregisters the callback for the operation of favoriting a media asset.| 
