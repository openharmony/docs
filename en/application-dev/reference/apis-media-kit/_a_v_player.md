# AVPlayer


## Overview

The AVPlayer module provides APIs related to media playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [avplayer.h](avplayer_8h.md) | Declares the AVPlayer APIs. You can use the native AVPlayer APIs to play a media asset.| 
| [avplayer_base.h](avplayer__base_8h.md) | Declares the structs and enums of the AVPlayer.| 


### Structs

| Name| Description| 
| -------- | -------- |
| [AVPlayerCallback](_a_v_player_callback.md) | Defines all the callback function pointers of an **OH_AVPlayer** instance.| 


### Types

| Name| Description| 
| -------- | -------- |
| [AVPlayerState](#avplayerstate) | Defines an enum that enumerates the AVPlayer states.| 
| [AVPlayerSeekMode](#avplayerseekmode) | Defines an enum that enumerates the seek modes of the AVPlayer.| 
| [AVPlaybackSpeed](#avplaybackspeed) | Defines an enum that enumerates the playback speeds of the AVPlayer.| 
| [AVPlayerOnInfoType](#avplayeroninfotype) | Defines an enum that enumerates the types of messages received by the AVPlayer.| 
| (\*[OH_AVPlayerOnInfo](#oh_avplayeroninfo)) (OH_AVPlayer \*player, [AVPlayerOnInfoType](#avplayeroninfotype) type, int32_t extra) | Defines the callback when the AVPlayer receives a message.| 
| (\*[OH_AVPlayerOnError](#oh_avplayeronerror)) (OH_AVPlayer \*player, int32_t errorCode, const char \*errorMsg) | Defines the callback when an error occurs in the AVPlayer. This type is available in API version 9 or later.| 
| [AVPlayerCallback](#avplayercallback) | Defines all the callback function pointers of an **OH_AVPlayer** instance.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [AVPlayerState](#avplayerstate) {<br>AV_IDLE = 0, AV_INITIALIZED = 1, AV_PREPARED = 2, AV_PLAYING = 3,<br>AV_PAUSED = 4, AV_STOPPED = 5, AV_COMPLETED = 6, AV_RELEASED = 7,<br>AV_ERROR = 8<br>} | Enumerates the AVPlayer states.| 
| [AVPlayerSeekMode](#avplayerseekmode) { AV_SEEK_NEXT_SYNC = 0, AV_SEEK_PREVIOUS_SYNC } | Enumerates the seek modes of the AVPlayer.| 
| [AVPlaybackSpeed](#avplaybackspeed) {<br>AV_SPEED_FORWARD_0_75_X, AV_SPEED_FORWARD_1_00_X, AV_SPEED_FORWARD_1_25_X, AV_SPEED_FORWARD_1_75_X,<br>AV_SPEED_FORWARD_2_00_X<br>} | Enumerates the playback speeds of the AVPlayer.| 
| [AVPlayerOnInfoType](#avplayeroninfotype) {<br>AV_INFO_TYPE_SEEKDONE = 0, AV_INFO_TYPE_SPEEDDONE = 1, AV_INFO_TYPE_BITRATEDONE = 2, AV_INFO_TYPE_EOS = 3,<br>AV_INFO_TYPE_STATE_CHANGE = 4, AV_INFO_TYPE_POSITION_UPDATE = 5, AV_INFO_TYPE_MESSAGE = 6, AV_INFO_TYPE_VOLUME_CHANGE = 7,<br>AV_INFO_TYPE_RESOLUTION_CHANGE = 8, AV_INFO_TYPE_BUFFERING_UPDATE = 9, AV_INFO_TYPE_BITRATE_COLLECT = 10, AV_INFO_TYPE_INTERRUPT_EVENT = 11,<br>AV_INFO_TYPE_DURATION_UPDATE = 12, AV_INFO_TYPE_IS_LIVE_STREAM = 13, AV_INFO_TYPE_TRACKCHANGE = 14, AV_INFO_TYPE_TRACK_INFO_UPDATE = 15,<br>AV_INFO_TYPE_SUBTITLE_UPDATE = 16<br>} | Enumerates the types of messages received by the AVPlayer.| 


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_AVPlayer_Create](#oh_avplayer_create) (void) | Creates an **OH_AVPlayer** instance.| 
| [OH_AVPlayer_SetURLSource](#oh_avplayer_seturlsource) (OH_AVPlayer \*player, const char \*url) | Sets the HTTP URL of a media source to be played by an AVPlayer.  | 
| [OH_AVPlayer_SetFDSource](#oh_avplayer_setfdsource) (OH_AVPlayer \*player, int32_t fd, int64_t offset, int64_t size) | Sets the file descriptor of a media source to be played by an AVPlayer.| 
| [OH_AVPlayer_Prepare](#oh_avplayer_prepare) (OH_AVPlayer \*player) | Prepares the playback environment and buffers media data.| 
| [OH_AVPlayer_Play](#oh_avplayer_play) (OH_AVPlayer \*player) | Starts playback.| 
| [OH_AVPlayer_Pause](#oh_avplayer_pause) (OH_AVPlayer \*player) | Pauses playback.| 
| [OH_AVPlayer_Stop](#oh_avplayer_stop) (OH_AVPlayer \*player) | Stops playback.| 
| [OH_AVPlayer_Reset](#oh_avplayer_reset) (OH_AVPlayer \*player) | Restores the AVPlayer to the initial state.| 
| [OH_AVPlayer_Release](#oh_avplayer_release) (OH_AVPlayer \*player) | Asynchronously releases an **OH_AVPlayer** instance.| 
| [OH_AVPlayer_ReleaseSync](#oh_avplayer_releasesync) (OH_AVPlayer \*player) | Synchronously releases an **OH_AVPlayer** instance.| 
| [OH_AVPlayer_SetVolume](#oh_avplayer_setvolume) (OH_AVPlayer \*player, float leftVolume, float rightVolume) | Sets the volume for an AVPlayer.| 
| [OH_AVPlayer_Seek](#oh_avplayer_seek) (OH_AVPlayer \*player, int32_t mSeconds, [AVPlayerSeekMode](#avplayerseekmode) mode) | Seeks to a playback position.| 
| [OH_AVPlayer_GetCurrentTime](#oh_avplayer_getcurrenttime) (OH_AVPlayer \*player, int32_t \*currentTime) | Obtains the playback position, in milliseconds.| 
| [OH_AVPlayer_GetVideoWidth](#oh_avplayer_getvideowidth) (OH_AVPlayer \*player, int32_t \*videoWidth) | Obtains the video width.| 
| [OH_AVPlayer_GetVideoHeight](#oh_avplayer_getvideoheight) (OH_AVPlayer \*player, int32_t \*videoHeight) | Obtains the video height.| 
| [OH_AVPlayer_SetPlaybackSpeed](#oh_avplayer_setplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](#avplaybackspeed) speed) | Sets the playback speed for an AVPlayer.| 
| [OH_AVPlayer_GetPlaybackSpeed](#oh_avplayer_getplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](#avplaybackspeed) \*speed) | Obtains the playback speed of an AVPlayer.| 
| [OH_AVPlayer_SelectBitRate](#oh_avplayer_selectbitrate) (OH_AVPlayer \*player, uint32_t bitRate) | Sets the bit rate used by an HLS player.| 
| [OH_AVPlayer_SetVideoSurface](#oh_avplayer_setvideosurface) (OH_AVPlayer \*player, OHNativeWindow \*window) | Sets a playback window.| 
| [OH_AVPlayer_GetDuration](#oh_avplayer_getduration) (OH_AVPlayer \*player, int32_t \*duration) | Obtains the total duration of a media file, in milliseconds.| 
| [OH_AVPlayer_GetState](#oh_avplayer_getstate) (OH_AVPlayer \*player, [AVPlayerState](#avplayerstate) \*state) | Obtains the AVPlayer state.| 
| [OH_AVPlayer_IsPlaying](#oh_avplayer_isplaying) (OH_AVPlayer \*player) | Checks whether an AVPlayer is playing.| 
| [OH_AVPlayer_IsLooping](#oh_avplayer_islooping) (OH_AVPlayer \*player) | Checks whether an AVPlayer is looping.| 
| [OH_AVPlayer_SetLooping](#oh_avplayer_setlooping) (OH_AVPlayer \*player, bool loop) | Enables loop playback.| 
| [OH_AVPlayer_SetPlayerCallback](#oh_avplayer_setplayercallback) (OH_AVPlayer \*player, [AVPlayerCallback](_a_v_player_callback.md) callback) | Sets a callback for an AVPlayer.| 
| [OH_AVPlayer_SelectTrack](#oh_avplayer_selecttrack) (OH_AVPlayer \*player, int32_t index) | Selects an audio or subtitle track.| 
| [OH_AVPlayer_DeselectTrack](#oh_avplayer_deselecttrack) (OH_AVPlayer \*player, int32_t index) | Deselects an audio or subtitle track.| 
| [OH_AVPlayer_GetCurrentTrack](#oh_avplayer_getcurrenttrack) (OH_AVPlayer \*player, int32_t trackType, int32_t \*index) | Obtains the currently valid track.| 


### Variables

| Name| Description| 
| -------- | -------- |
| [AVPlayerCallback::onInfo](#oninfo) | Defines the AVPlayer process information. For details, see [OH_AVPlayerOnInfo](oh_avplayeroninfo).| 
| [AVPlayerCallback::onError](#onerror) | Defines the AVPlayer error information. For details, see [OH_AVPlayerOnError](_oh_avplayeronerror).| 


## Type Description


### AVPlaybackSpeed

```
typedef enum AVPlaybackSpeedAVPlaybackSpeed
```

**Description**

Defines an enum that enumerates the playback speeds of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


### AVPlayerCallback

```
typedef struct AVPlayerCallbackAVPlayerCallback
```

**Description**

Defines all the callback function pointers of an **OH_AVPlayer** instance. To ensure the normal running of **OH_AVPlayer**, you must register the instance of this struct with the **OH_AVPlayer** instance and process the information reported by the callback functions.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


### AVPlayerOnInfoType

```
typedef enum AVPlayerOnInfoTypeAVPlayerOnInfoType
```

**Description**

Defines an enum that enumerates the types of messages received by the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


### AVPlayerSeekMode

```
typedef enum AVPlayerSeekModeAVPlayerSeekMode
```

**Description**

Defines an enum that enumerates the seek modes of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


### AVPlayerState

```
typedef enum AVPlayerStateAVPlayerState
```

**Description**

Defines an enum that enumerates the AVPlayer states.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11


### OH_AVPlayerOnError

```
typedef void(* OH_AVPlayerOnError) (OH_AVPlayer *player, int32_t errorCode, const char *errorMsg)
```

**Description**

Defines the callback when an error occurs in the AVPlayer. This type is available in API version 9 or later.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| errorCode | Error code.| 
| errorMsg | Pointer to an error message.| 


### OH_AVPlayerOnInfo

```
typedef void(* OH_AVPlayerOnInfo) (OH_AVPlayer *player, AVPlayerOnInfoType type, int32_t extra)
```

**Description**

Defines the callback when the AVPlayer receives a message.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| type | Message type. For details, see [AVPlayerOnInfoType](#avplayeroninfotype).| 
| extra | Other information, such as the start time and position of the media file to play.| 


## Enum Description


### AVPlaybackSpeed

```
enum AVPlaybackSpeed
```

**Description**

Enumerates the playback speeds of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Value| Description| 
| -------- | -------- |
| AV_SPEED_FORWARD_0_75_X | Plays the video at 0.75 times the normal speed.| 
| AV_SPEED_FORWARD_1_00_X | Plays the video at the normal speed.| 
| AV_SPEED_FORWARD_1_25_X | Plays the video at 1.25 times the normal speed.| 
| AV_SPEED_FORWARD_1_75_X | Plays the video at 1.75 times the normal speed.| 
| AV_SPEED_FORWARD_2_00_X | Plays the video at 2.0 times the normal speed.| 


### AVPlayerOnInfoType

```
enum AVPlayerOnInfoType
```

**Description**

Enumerates the types of messages received by the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Value| Description| 
| -------- | -------- |
| AV_INFO_TYPE_SEEKDONE | Message returned when seeking to a playback position is complete.| 
| AV_INFO_TYPE_SPEEDDONE | Message returned when the playback speed setting is complete.| 
| AV_INFO_TYPE_BITRATEDONE | Message returned when the bit rate setting is complete.| 
| AV_INFO_TYPE_EOS | Message returned when the playback is complete.| 
| AV_INFO_TYPE_STATE_CHANGE | Message returned when the AVPlayer state changes.| 
| AV_INFO_TYPE_POSITION_UPDATE | Message returned when the playback position changes.| 
| AV_INFO_TYPE_MESSAGE | Message returned when the playback message is received.| 
| AV_INFO_TYPE_VOLUME_CHANGE | Message returned when the playback volume changes.| 
| AV_INFO_TYPE_RESOLUTION_CHANGE | Message returned when the video size is obtained for the first time or the video size is updated.| 
| AV_INFO_TYPE_BUFFERING_UPDATE | Message returned when multi-queue buffering changes.| 
| AV_INFO_TYPE_BITRATE_COLLECT | Message returned when the bit rate conflicts.| 
| AV_INFO_TYPE_INTERRUPT_EVENT | Message returned when the audio focus changes.| 
| AV_INFO_TYPE_DURATION_UPDATE | Message returned when the playback duration changes.| 
| AV_INFO_TYPE_IS_LIVE_STREAM | Message returned when live streams are played.| 
| AV_INFO_TYPE_TRACKCHANGE | Message returned when the track changes.| 
| AV_INFO_TYPE_TRACK_INFO_UPDATE | Message returned when the subtitle track information changes.| 
| AV_INFO_TYPE_SUBTITLE_UPDATE | Message returned when the subtitle information changes.| 


### AVPlayerSeekMode

```
enum AVPlayerSeekMode
```

**Description**

Enumerates the seek modes of the AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Value| Description| 
| -------- | -------- |
| AV_SEEK_NEXT_SYNC | Seeks to the next key frame at the specified position.| 
| AV_SEEK_PREVIOUS_SYNC | Seeks to the previous key frame at the specified position.| 


### AVPlayerState

```
enum AVPlayerState
```

**Description**

Enumerates the AVPlayer states.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

| Value| Description| 
| -------- | -------- |
| AV_IDLE | The AVPlayer is idle.| 
| AV_INITIALIZED | The AVPlayer is initialized.| 
| AV_PREPARED | The AVPlayer is ready for playback.| 
| AV_PLAYING | The AVPlayer is playing.| 
| AV_PAUSED | The AVPlayer is paused.| 
| AV_STOPPED | The AVPlayer is stopped.| 
| AV_COMPLETED | The AVPlayer finishes playing.| 
| AV_RELEASED | The AVPlayer is released.| 
| AV_ERROR | An error occurs.| 


## Function Description


### OH_AVPlayer_Create()

```
OH_AVPlayer* OH_AVPlayer_Create (void )
```

**Description**

Creates an **OH_AVPlayer** instance.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Returns**

Returns the pointer to an **OH_AVPlayer** instance.


### OH_AVPlayer_DeselectTrack()

```
OH_AVErrCode OH_AVPlayer_DeselectTrack (OH_AVPlayer * player, int32_t index )
```

**Description**

Deselects an audio or subtitle track.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| index | Index of the track.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_GetCurrentTime()

```
OH_AVErrCode OH_AVPlayer_GetCurrentTime (OH_AVPlayer * player, int32_t * currentTime )
```

**Description**

Obtains the playback position, in milliseconds.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| currentTime | Pointer to the playback position.| 

**Returns**

Returns **AV_ERR_OK** if the playback position is obtained; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_GetCurrentTrack()

```
OH_AVErrCode OH_AVPlayer_GetCurrentTrack (OH_AVPlayer * player, int32_t trackType, int32_t * index )
```

**Description**

Obtains the currently valid track.

You can set the track to the prepared, playing, paused, or completed state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| trackType | Track type.| 
| index | Pointer to the index of the track.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_GetDuration()

```
OH_AVErrCode OH_AVPlayer_GetDuration (OH_AVPlayer * player, int32_t * duration )
```

**Description**

Obtains the total duration of a media file, in milliseconds.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| duration | Pointer to the total duration.| 

**Returns**

Returns **AV_ERR_OK** if the total duration is obtained; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_GetPlaybackSpeed()

```
OH_AVErrCode OH_AVPlayer_GetPlaybackSpeed (OH_AVPlayer * player, AVPlaybackSpeed * speed )
```

**Description**

Obtains the playback speed of an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| speed | Pointer to the playback speed. For details, see [AVPlaybackSpeed](#avplaybackspeed).| 

**Returns**

Returns **AV_ERR_OK** if the playback speed is obtained; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_GetState()

```
OH_AVErrCode OH_AVPlayer_GetState (OH_AVPlayer * player, AVPlayerState * state )
```

**Description**

Obtains the AVPlayer state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| state | Pointer to the state.| 

**Returns**

Returns **AV_ERR_OK** if the state is obtained; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_GetVideoHeight()

```
OH_AVErrCode OH_AVPlayer_GetVideoHeight (OH_AVPlayer * player, int32_t * videoHeight )
```

**Description**

Obtains the video height.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| videoHeights | Pointer to the video height.| 

**Returns**

Returns **AV_ERR_OK** if the video height is obtained; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_GetVideoWidth()

```
OH_AVErrCode OH_AVPlayer_GetVideoWidth (OH_AVPlayer * player, int32_t * videoWidth )
```

**Description**

Obtains the video width.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| videoWidth | Pointer to the video width.| 

**Returns**

Returns **AV_ERR_OK** if the video width is obtained; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_IsLooping()

```
bool OH_AVPlayer_IsLooping (OH_AVPlayer * player)
```

**Description**

Checks whether an AVPlayer is looping.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **true** if the AVPlayer is looping; returns **false** otherwise.


### OH_AVPlayer_IsPlaying()

```
bool OH_AVPlayer_IsPlaying (OH_AVPlayer * player)
```

**Description**

Checks whether an AVPlayer is playing.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **true** if the AVPlayer is playing; returns **false** otherwise.


### OH_AVPlayer_Pause()

```
OH_AVErrCode OH_AVPlayer_Pause (OH_AVPlayer * player)
```

**Description**

Pauses playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the playback is paused; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_Play()

```
OH_AVErrCode OH_AVPlayer_Play (OH_AVPlayer * player)
```

**Description**

Starts playback.

This function must be called after **Prepare**. In other words, you can call this function when the AVPlayer is in the prepared state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the playback starts; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_Prepare()

```
OH_AVErrCode OH_AVPlayer_Prepare (OH_AVPlayer * player)
```

**Description**

Prepares the playback environment and buffers media data.

This function must be called after **SetSource**.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the playback environment is prepared; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_Release()

```
OH_AVErrCode OH_AVPlayer_Release (OH_AVPlayer * player)
```

**Description**

Asynchronously releases an **OH_AVPlayer** instance.

The asynchronous function ensures the performance, but cannot ensure that the surface buffer of the playback window is released. You must ensure the lifecycle of the playback window.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the AVPlayer is released; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_ReleaseSync()

```
OH_AVErrCode OH_AVPlayer_ReleaseSync (OH_AVPlayer * player)
```

**Description**

Synchronously releases an **OH_AVPlayer** instance.

The synchronous function ensures that the surface buffer of the playback window is released, with a long time (when the engine is not idle). Therefore, you need to design an asynchronous mechanism.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the AVPlayer is released; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_Reset()

```
OH_AVErrCode OH_AVPlayer_Reset (OH_AVPlayer * player)
```

**Description**

Restores the AVPlayer to the initial state.

After the function is called, you can call **SetSource** to set the media source to play, and then call **Prepare** and **Play** in sequence.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the AVPlayer is reset; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_Seek()

```
OH_AVErrCode OH_AVPlayer_Seek (OH_AVPlayer * player, int32_t mSeconds, AVPlayerSeekMode mode )
```

**Description**

Seeks to a playback position.

This function can be used when the AVPlayer is in the playing or paused state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| mSeconds | Position to seek to, in ms.| 
| mode | Seek mode. For details, see [AVPlayerSeekMode](#avplayerseekmode).| 


### OH_AVPlayer_SelectBitRate()

```
OH_AVErrCode OH_AVPlayer_SelectBitRate (OH_AVPlayer * player, uint32_t bitRate )
```

**Description**

Sets the bit rate used by an HLS player,

in bit/s. This function is valid only for HLS network streams. By default, the player selects a proper bit rate and speed based on the network connection. You can set a bit rate available in the valid bit rates reported in **INFO_TYPE_BITRATE_COLLECT**. The player selects a bit rate that is lower than or closest to the specified bit rate for playback. When ready, you can query the selected bit rate.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| bitRate | Bit rate, in kbit/s.| 

**Returns**

Returns **AV_ERR_OK** if the setting is successful; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_SelectTrack()

```
OH_AVErrCode OH_AVPlayer_SelectTrack (OH_AVPlayer * player, int32_t index )
```

**Description**

Selects an audio or subtitle track.

By default, the first audio stream with data is played, and the subtitle track is not played. After the setting takes effect, the original track becomes invalid. Set the subtitle track to the prepared, playing, paused, or completed state, and set the audio track to the prepared state.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| index | Index of the track.| 

**Returns**

Returns **AV_ERR_OK** if a track is selected; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_SetFDSource()

```
OH_AVErrCode OH_AVPlayer_SetFDSource (OH_AVPlayer * player, int32_t fd, int64_t offset, int64_t size )
```

**Description**

Sets the file descriptor of a media source to be played by an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| fd | File descriptor of the media source.| 
| offset | Offset of the media source in the file descriptor.| 
| size | Size of the media source.| 

**Returns**

Returns **AV_ERR_OK** if the setting is successful; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_SetLooping()

```
OH_AVErrCode OH_AVPlayer_SetLooping (OH_AVPlayer * player, bool loop )
```

**Description**

Enables loop playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| loop | Whether to enable loop playback.| 

**Returns**

Returns **AV_ERR_OK** if the setting is successful; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_SetPlaybackSpeed()

```
OH_AVErrCode OH_AVPlayer_SetPlaybackSpeed (OH_AVPlayer * player, AVPlaybackSpeed speed )
```

**Description**

Sets the playback speed for an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| speed | Playback speed. For details, see [AVPlaybackSpeed](#avplaybackspeed).| 


### OH_AVPlayer_SetPlayerCallback()

```
OH_AVErrCode OH_AVPlayer_SetPlayerCallback (OH_AVPlayer * player, AVPlayerCallback callback )
```

**Description**

Sets a callback for an AVPlayer.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| callback | Callback.| 

**Returns**

Returns **AV_ERR_OK** if the setting is successful; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_SetURLSource()

```
OH_AVErrCode OH_AVPlayer_SetURLSource (OH_AVPlayer * player, const char * url )
```

**Description**

Sets the HTTP URL of a media source to be played by an AVPlayer.  

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| url | URL of the media source.| 

**Returns**

Returns **AV_ERR_OK** if the setting is successful; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_SetVideoSurface()

```
OH_AVErrCode OH_AVPlayer_SetVideoSurface (OH_AVPlayer * player, OHNativeWindow * window )
```

**Description**

Sets a playback window.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| window | Pointer to an **OHNativeWindow** instance.| 


### OH_AVPlayer_SetVolume()

```
OH_AVErrCode OH_AVPlayer_SetVolume (OH_AVPlayer * player, float leftVolume, float rightVolume )
```

**Description**

Sets the volume for an AVPlayer.

This function can be used when the AVPlayer is in the playing or paused state. The value **0** means that the AVPlayer is muted, and **1** means that the original volume is used.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 
| leftVolume | Target volume of the left channel.| 
| rightVolume | Target volume of the right channel.| 

**Returns**

Returns **AV_ERR_OK** if the setting is successful; returns an error code defined in **native_averrors.h** otherwise.


### OH_AVPlayer_Stop()

```
OH_AVErrCode OH_AVPlayer_Stop (OH_AVPlayer * player)
```

**Description**

Stops playback.

**System capability**: SystemCapability.Multimedia.Media.AVPlayer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| player | Pointer to an **OH_AVPlayer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the AVPlayer is stopped; returns an error code defined in **native_averrors.h** otherwise.


## Variable Description


### onError

```
OH_AVPlayerOnError AVPlayerCallback::onError
```

**Description**

Defines the AVPlayer error information. For details, see [OH_AVPlayerOnError](_oh_avplayeronerror).


### onInfo

```
OH_AVPlayerOnInfo AVPlayerCallback::onInfo
```

**Description**

Defines the AVPlayer process information. For details, see [OH_AVPlayerOnInfo](oh_avplayeroninfo).
