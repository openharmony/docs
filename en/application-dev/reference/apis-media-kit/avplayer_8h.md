# avplayer.h


## Overview

The **avplayer.h** file declares the AVPlayer APIs. You can use the native AVPlayer APIs to play a media asset.

**Library**: libavplayer.so

**File to include**: <multimedia/player_framework/avplayer.h>

**Since**: 11

**Related module**: [AVPlayer](_a_v_player.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [MediaKeySession](_a_v_player.md#mediakeysession) [MediaKeySession](_a_v_player.md#mediakeysession) | Defines a struct for the media key session. | 
| typedef struct [DRM_MediaKeySystemInfo](_a_v_player.md#drm_mediakeysysteminfo) [DRM_MediaKeySystemInfo](_a_v_player.md#drm_mediakeysysteminfo) | Defines a struct for the media key system information. | 
| typedef void(\* [Player_MediaKeySystemInfoCallback](_a_v_player.md#player_mediakeysysteminfocallback)) (OH_AVPlayer \*player, [DRM_MediaKeySystemInfo](_a_v_player.md#drm_mediakeysysteminfo) \*mediaKeySystemInfo) | Defines a callback invoked when media key system information of the AVPlayer is updated. | 


### Functions

| Name| Description| 
| -------- | -------- |
| OH_AVPlayer \*[OH_AVPlayer_Create](_a_v_player.md#oh_avplayer_create) (void) | Creates an **OH_AVPlayer** instance.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetURLSource](_a_v_player.md#oh_avplayer_seturlsource) (OH_AVPlayer \*player, const char \*url) | Sets the HTTP URL of a media source to be played by an AVPlayer.  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetFDSource](_a_v_player.md#oh_avplayer_setfdsource) (OH_AVPlayer \*player, int32_t fd, int64_t offset, int64_t size) | Sets the file descriptor of a media source to be played by an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Prepare](_a_v_player.md#oh_avplayer_prepare) (OH_AVPlayer \*player) | Prepares the playback environment and buffers media data.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Play](_a_v_player.md#oh_avplayer_play) (OH_AVPlayer \*player) | Starts playback.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Pause](_a_v_player.md#oh_avplayer_pause) (OH_AVPlayer \*player) | Pauses playback.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Stop](_a_v_player.md#oh_avplayer_stop) (OH_AVPlayer \*player) | Stops playback.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Reset](_a_v_player.md#oh_avplayer_reset) (OH_AVPlayer \*player) | Restores the AVPlayer to the initial state.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Release](_a_v_player.md#oh_avplayer_release) (OH_AVPlayer \*player) | Asynchronously releases an **OH_AVPlayer** instance.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_ReleaseSync](_a_v_player.md#oh_avplayer_releasesync) (OH_AVPlayer \*player) | Synchronously releases an **OH_AVPlayer** instance.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetVolume](_a_v_player.md#oh_avplayer_setvolume) (OH_AVPlayer \*player, float leftVolume, float rightVolume) | Sets the volume for an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_Seek](_a_v_player.md#oh_avplayer_seek) (OH_AVPlayer \*player, int32_t mSeconds, [AVPlayerSeekMode](_a_v_player.md#avplayerseekmode) mode) | Seeks to a playback position.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetCurrentTime](_a_v_player.md#oh_avplayer_getcurrenttime) (OH_AVPlayer \*player, int32_t \*currentTime) | Obtains the playback position, in milliseconds.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetVideoWidth](_a_v_player.md#oh_avplayer_getvideowidth) (OH_AVPlayer \*player, int32_t \*videoWidth) | Obtains the video width.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetVideoHeight](_a_v_player.md#oh_avplayer_getvideoheight) (OH_AVPlayer \*player, int32_t \*videoHeight) | Obtains the video height.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetPlaybackSpeed](_a_v_player.md#oh_avplayer_setplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) speed) | Sets the playback speed for an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetPlaybackSpeed](_a_v_player.md#oh_avplayer_getplaybackspeed) (OH_AVPlayer \*player, [AVPlaybackSpeed](_a_v_player.md#avplaybackspeed) \*speed) | Obtains the playback speed of an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetAudioRendererInfo](_a_v_player.md#oh_avplayer_setaudiorendererinfo) (OH_AVPlayer \*player, OH_AudioStream_Usage streamUsage) | Sets the audio stream type for an AVPlayer. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetVolumeMode](_a_v_player.md#oh_avplayer_setvolumemode) (OH_AVPlayer \*player, [OH_AudioStream_VolumeMode](../apis-audio-kit/_o_h_audio.md#oh_audiostream_volumemode) volumeMode) | Sets the audio volume mode for an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetAudioInterruptMode](_a_v_player.md#oh_avplayer_setaudiointerruptmode) (OH_AVPlayer \*player, OH_AudioInterrupt_Mode interruptMode) | Sets the audio interruption mode for an AVPlayer. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetAudioEffectMode](_a_v_player.md#oh_avplayer_setaudioeffectmode) (OH_AVPlayer \*player, OH_AudioStream_AudioEffectMode effectMode) | Sets the audio effect mode for an AVPlayer. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SelectBitRate](_a_v_player.md#oh_avplayer_selectbitrate) (OH_AVPlayer \*player, uint32_t bitRate) | Sets the bit rate used by an HLS player.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetVideoSurface](_a_v_player.md#oh_avplayer_setvideosurface) (OH_AVPlayer \*player, OHNativeWindow \*window) | Sets a playback window.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetDuration](_a_v_player.md#oh_avplayer_getduration) (OH_AVPlayer \*player, int32_t \*duration) | Obtains the total duration of a media file, in milliseconds.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetState](_a_v_player.md#oh_avplayer_getstate) (OH_AVPlayer \*player, [AVPlayerState](_a_v_player.md#avplayerstate) \*state) | Obtains the AVPlayer state.| 
| bool [OH_AVPlayer_IsPlaying](_a_v_player.md#oh_avplayer_isplaying) (OH_AVPlayer \*player) | Checks whether an AVPlayer is playing.| 
| bool [OH_AVPlayer_IsLooping](_a_v_player.md#oh_avplayer_islooping) (OH_AVPlayer \*player) | Checks whether an AVPlayer is looping.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetLooping](_a_v_player.md#oh_avplayer_setlooping) (OH_AVPlayer \*player, bool loop) | Enables loop playback.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetPlayerCallback](_a_v_player.md#oh_avplayer_setplayercallback) (OH_AVPlayer \*player, [AVPlayerCallback](_a_v_player_callback.md) callback) | Sets a callback for an AVPlayer.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SelectTrack](_a_v_player.md#oh_avplayer_selecttrack) (OH_AVPlayer \*player, int32_t index) | Selects an audio or subtitle track.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_DeselectTrack](_a_v_player.md#oh_avplayer_deselecttrack) (OH_AVPlayer \*player, int32_t index) | Deselects an audio or subtitle track.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetCurrentTrack](_a_v_player.md#oh_avplayer_getcurrenttrack) (OH_AVPlayer \*player, int32_t trackType, int32_t \*index) | Obtains the currently valid track.| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetMediaKeySystemInfoCallback](_a_v_player.md#oh_avplayer_setmediakeysysteminfocallback) (OH_AVPlayer \*player, Player_MediaKeySystemInfoCallback callback) | Sets a callback to return the media key system information for an AVPlayer. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_GetMediaKeySystemInfo](_a_v_player.md#oh_avplayer_getmediakeysysteminfo) (OH_AVPlayer \*player, [DRM_MediaKeySystemInfo](../apis-drm-kit/_d_r_m___media_key_system_info.md) \*mediaKeySystemInfo) | Obtains the media key system information to create a media key session. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetDecryptionConfig](_a_v_player.md#oh_avplayer_setdecryptionconfig) (OH_AVPlayer \*player, [MediaKeySession](../apis-drm-kit/_drm.md#mediakeysession) \*mediaKeySession, bool secureVideoPath) | Sets the decryption information. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetOnInfoCallback](_a_v_player.md#oh_avplayer_setoninfocallback) (OH_AVPlayer \*player, [OH_AVPlayerOnInfoCallback](_a_v_player.md#oh_avplayeroninfocallback) callback, void \*userData) | Sets a callback for the event indicating that the AVPlayer receives a message. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVPlayer_SetOnErrorCallback](_a_v_player.md#oh_avplayer_setonerrorcallback) (OH_AVPlayer \*player, [OH_AVPlayerOnErrorCallback](_a_v_player.md#oh_avplayeronerrorcallback) callback, void \*userData) | Sets a callback for the event indicating that an error occurs in the AVPlayer. | 
