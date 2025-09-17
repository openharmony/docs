# AVSession Provider (C/C++)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

The OHAVSession module provides C APIs to implement an AVSession provider. An audio and video application needs to access the AVSession service as a provider in order to display media information in the controller (for example, Media Controller) and respond to playback control commands delivered by the controller.

## Prerequisites

To use [OHAVSession](../../reference/apis-avsession-kit/capi-native-avsession-h.md) to implement media sessions, add the corresponding header files.

### Linking the Dynamic Libraries in the CMake Script

``` cmake
target_link_libraries(entry PUBLIC libohavsession.so)
```

### Including Header Files

```cpp
#include <multimedia/av_session/native_avmetadata.h>
#include <multimedia/av_session/native_avsession.h>
#include <multimedia/av_session/native_avsession_errors.h>
```

## How to Develop

To access a local session with the NDK, perform the following steps:
1. Create a session and activate the media. Specifically, pass the session type (specified by **AVSession_Type**), custom tag, bundle name, and ability name.

   ```c++
   OH_AVSession* avsession;
   OH_AVSession_Create(SESSION_TYPE_AUDIO, "testsession", "com.example.application",   "MainAbility", &avsession);
   OH_AVSession_Activate(avsession);
   ```
 
   **AVSession_Type** can be set to any of the following types:
 
   - SESSION_TYPE_AUDIO
   - SESSION_TYPE_VIDEO
   - SESSION_TYPE_VOICE_CALL 
   - SESSION_TYPE_VIDEO_CALL


2. Set the metadata of the media asset to be played.

   To set metadata, use **OH_AVMetadataBuilder** to construct specific data, generate an OH_AVMetadata instance, and then call the APIs of **OH_AVMetadata** to set the asset.

   The code snippet below shows how to call **OH_AVMetadataBuilder** to construct metadata:

   ```c++
   // Create an OH_AVMetadataBuilder.
   OH_AVMetadataBuilder* builder;
   OH_AVMetadataBuilder_Create(&builder);
   
   OH_AVMetadata* ohMetadata;
   OH_AVMetadataBuilder_SetTitle(builder, "Anonymous title");
   OH_AVMetadataBuilder_SetArtist(builder, "Anonymous artist");
   OH_AVMetadataBuilder_SetAuthor(builder, "Anonymous author");
   OH_AVMetadataBuilder_SetAlbum(builder, "Anonymous album");
   OH_AVMetadataBuilder_SetWriter(builder, "Anonymous writer");
   OH_AVMetadataBuilder_SetComposer(builder, "Anonymous composer");
   OH_AVMetadataBuilder_SetDuration(builder, 3600);
   // MediaImageUri can only be set to a network address.
   OH_AVMetadataBuilder_SetMediaImageUri(builder, "https://xxx.xxx.xx");
   OH_AVMetadataBuilder_SetSubtitle(builder, "Anonymous subtitle");
   OH_AVMetadataBuilder_SetDescription(builder, "For somebody");
   // Lyric can only be set to the lyric content. (The application must combine the lyric content into a string.)
   OH_AVMetadataBuilder_SetLyric(builder, "balabala");
   OH_AVMetadataBuilder_SetAssetId(builder, "000");
   OH_AVMetadataBuilder_SetSkipIntervals(builder, SECONDS_30);
   OH_AVMetadataBuilder_SetDisplayTags(builder,  AVSESSION_DISPLAYTAG_AUDIO_VIVID);
   
   /**
    * Generate an AVMetadata object.
    */
   OH_AVMetadataBuilder_GenerateAVMetadata(builder, &ohMetadata);

   /**
    * Set the AVMetadata object.
    */
   OH_AVSession_SetAVMetadata(avsession, ohMetadata);
   ```
   
   When the AVMetadata is no longer needed, call **OH_AVMetadataBuilder_Destroy** to destroy it and do not use it anymore.
   
   ```c++
   OH_AVMetadata_Destroy(ohMetadata);
   OH_AVMetadataBuilder_Destroy(builder);
   ```

3. Update the media playback status information.

   The information includes the playback state, playback position, playback speed, and favorite status. You can use the APIs to set the information.
   
   ```c++
   AVSession_ErrCode ret = AV_SESSION_ERR_SUCCESS;
   
   // Set the playback state, which is in the range [0,11].
   AVSession_PlaybackState state = PLAYBACK_STATE_PREPARING;
   ret = OH_AVSession_SetPlaybackState(avsession, state);
   
   // Set the playback position.
   AVSession_PlaybackPosition* playbackPosition = new  AVSession_PlaybackPosition;
   playbackPosition->elapsedTime = 1000;
   playbackPosition->updateTime = 16111150;
   ret = OH_AVSession_SetPlaybackPosition(avsession, playbackPosition);
   ```

4. Listen for playback control commands delivered by the controller, for example, Media Controller.

   > **NOTE**
   >
   > After the provider registers a listener for fixed playback control commands, the commands will be reflected in **getValidCommands()** of the controller. In other words, the controller determines that the command is valid and triggers the corresponding event as required. To ensure that the playback control commands delivered by the controller can be executed normally, the provider should not use a null implementation for listening.
   >
   > To avoid any exception, call the API to unregister the listener when the service ends.
 
   Currently, the following playback control commands are supported:
   - Play
   - Pause
   - Stop
   - Play previous
   - Play next
   - Rewind
   - Fast forward
   - Seek
   - Favorite
   
   ```c++
   // Register the callbacks for the commands of play, pause, stop, play previous, and play next.
   // CONTROL_CMD_PLAY = 0; play.
   // CONTROL_CMD_PAUSE = 1; pause.
   // CONTROL_CMD_STOP = 2; stop.
   // CONTROL_CMD_PLAY_NEXT = 3; play next.
   // CONTROL_CMD_PLAY_PREVIOUS = 4; play previous.
   AVSession_ControlCommand command = CONTROL_CMD_PLAY;
   OH_AVSessionCallback_OnCommand commandCallback = [](OH_AVSession* session, AVSession_ControlCommand command,
       void* userData) -> AVSessionCallback_Result
   {
       return AVSESSION_CALLBACK_RESULT_SUCCESS;
   };
   OH_AVSession_RegisterCommandCallback(avsession, command, commandCallback, (void *)(&userData));
   
   // Register the callback for the fast-forward operation.
   OH_AVSessionCallback_OnFastForward fastForwardCallback = [](OH_AVSession* session, uint32_t seekTime,
       void* userData) -> AVSessionCallback_Result
   {
       return AVSESSION_CALLBACK_RESULT_SUCCESS;
   };
   OH_AVSession_RegisterForwardCallback(avsession, fastForwardCallback, (void *)(&userData));
   ```
   The related callbacks are as follows:
  
   | API                                                        | Description        |
   | ------------------------------------------------------------ | ------------ |
   |OH_AVSession_RegisterCommandCallback(OH_AVSession* avsession, AVSession_ControlCommand   command, OH_AVSessionCallback_OnCommand callback, void* userData) | Registers a callback for a common playback control command, which can be play, pause, stop, play previous, or play next.    |
   |OH_AVSession_RegisterForwardCallback(OH_AVSession* avsession,   OH_AVSessionCallback_OnFastForward callback, void* userData) | Registers a callback for the fast-forward operation.  |
   |OH_AVSession_RegisterRewindCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnRewind   callback, void* userData) | Registers a callback for the rewind operation.    |
   |OH_AVSession_RegisterSeekCallback(OH_AVSession* avsession, OH_AVSessionCallback_OnSeek   callback, void* userData) | Registers a callback for the seek operation. |
   |OH_AVSession_RegisterToggleFavoriteCallback(OH_AVSession* avsession,   OH_AVSessionCallback_OnToggleFavorite callback, void* userData) | Registers a callback for the favorite operation. |
5. When the audio and video application exits and does not need to continue playback, cancel the listener and destroy the AVSession object. The example code is as follows:
 
   ```c++
   OH_AVSession_Destroy(avsession);
   ```

