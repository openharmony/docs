# Using AVPlayer for Audio Playback (C/C++)

The AVPlayer is used to play raw media assets in an end-to-end manner. In this topic, you will learn how to use the AVPlayer to play a complete piece of music.


The full playback process includes creating an **AVPlayer** instance, setting the media asset to play, setting playback parameters (volume, speed, and focus mode), controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the instance.


During application development, you can use the callback function of the AVPlayer to obtain the playback process information. If the application performs an operation when the AVPlayer is not in the given state, the system may throw an exception or generate other undefined behavior.


**Figure 1** Playback state transition 
![Playback status change](figures/playback-status-change-ndk.png)

For details about the states, see [AVPlayerState](../reference/native-apis/_a_v_player.md#avplayerstate-1). When the AVPlayer is in the **prepared**, **playing**, **paused**, or **completed** state, the playback engine is working and a large amount of RAM is occupied. If your application does not need to use the AVPlayer, call **OH_AVPlayer_Reset()** or **OH_AVPlayer_Release()** to release the instance.

## How to Develop
Link the dynamic library in the CMake script.
```
target_link_libraries(sample PUBLIC libavplayer.so)
```

You can use C/C++ APIs related to audio playback by including the header files [avplayer.h](../reference/native-apis/avplayer__base_8h.md), [avpalyer_base.h](../reference/native-apis/avplayer__base_8h.md), and [native_averrors.h](../reference/native-apis/native__averrors_8h.md).
Read [AVPlayer](../reference/native-apis/_a_v_player.md) for the API reference.

1. Call **OH_AVPlayer_Create()** to create an **AVPlayer** instance. The AVPlayer is the **idle** state.

2. Call **OH_AVPlayer_SetPlayerCallback()** to set the events to listen for, which will be used in the full-process scenario. The table below lists the supported events.
   | Event Type| Description|
   | -------- | -------- |
   | OH_AVPlayerOnInfo | Mandatory; used to listen for AVPlayer process information.|
   | OH_AVPlayerOnError | Mandatory; used to listen for AVPlayer errors.|

3. Call **OH_AVPlayer_SetURLSource()** to set the media asset URL. The AVPlayer enters the **initialized** state.

4. Call **OH_AVPlayer_Prepare()** to switch the AVPlayer to the **prepared** state. In this state, you can obtain the duration of the media asset to play and set the volume.

5. Call **OH_AVPlayer_Play()**, **OH_AVPlayer_Pause()**, **OH_AVPlayer_Seek()**, and **OH_AVPlayer_Stop()** to perform audio playback control as required.

6. (Optional) Call **OH_AVPlayer_Reset()** to reset the AVPlayer. The AVPlayer enters the **idle** state again and you can change the media asset URL.

7. Call **OH_AVPlayer_Release()** to switch the AVPlayer to the **released** state. Now your application exits the playback.

## Example

```c
#include "napi/native_api.h"
#include <multimedia/player_framework/avplayer.h>
#include <multimedia/player_framework/avplayer_base.h>
#include <multimedia/player_framework/native_averrors.h>
void OnInfo(OH_AVPlayer *player, AVPlayerOnInfoType type, int32_t extra)
{
    switch (type) {
       case AV_INFO_TYPE_SEEKDONE:
       // do something
           break;
       case AV_INFO_TYPE_STATE_CHANGE:
       // do something
           break;
       case AV_INFO_TYPE_SPEEDDONE:
       // do something
           break;
       case AV_INFO_TYPE_POSITION_UPDATE:
       // do something
           break;
       case AV_INFO_TYPE_BITRATE_COLLECT:
       // do something
           break;
       case AV_INFO_TYPE_INTERRUPT_EVENT:
       // do something
           break;
       case AV_INFO_TYPE_RESOLUTION_CHANGE:
       // do something
           break;
       case AV_INFO_TYPE_TRACKCHANGE:
       // do something
           break;
       case AV_INFO_TYPE_SUBTITLE_UPDATE: {
       // do something
           break;
       }
       case INFO_TYPE_TRACK_INFO_UPDATE: {
       // do something
           break;
       }
       default:
           break;
    }
}

void OnError(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg)
{
    // do something
}

int main()
{
    // Create an AVPlayer instance.
    OH_AVPlayer *player = OH_AVPlayer_Create();
    AVPlayerCallback callback;
    callback.onInfo = OnInfo;
    callback.onError = OnError;
    // Set the callback to listen for process information.
    int32_t ret = OH_AVPlayer_SetPlayerCallback(player, callback);
    if (ret != AV_ERR_OK) {
    // Exception processing.
    }
    const char *path = "/data/test/mp3_48000Hz_64kbs_mono.mp3";
    // Set the URL.
    int32_t ret = OH_AVPlayer_SetURLSource(player, path);
    if (ret != AV_ERR_OK) {
    // Exception processing.
    }
    // Prepare resources.
    int32_t ret = OH_AVPlayer_Prepare(player);
    if (ret != AV_ERR_OK) {
    // Exception processing.
    }
    // Play the media asset.
    int32_t ret = OH_AVPlayer_Play(player);
    if (ret != AV_ERR_OK) {
    // Exception processing.
    }
    // Stop the playback.
    int32_t ret = OH_AVPlayer_Stop(player);
    if (ret != AV_ERR_OK) {
    // Exception processing.
    }
    // Release the instance.
    int32_t ret = OH_AVPlayer_Release(player);
    if (ret != AV_ERR_OK) {
    // Exception processing.
    }
}
```

 <!--no_check--> 