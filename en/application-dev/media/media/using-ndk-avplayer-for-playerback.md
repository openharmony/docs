# Using AVPlayer for Audio Playback (C/C++)

The AVPlayer is used to play raw media assets in an end-to-end manner. In this topic, you will learn how to use the AVPlayer to play a complete piece of music.


The full playback process includes creating an **AVPlayer** instance, setting the media asset to play, setting playback parameters (volume, speed, and focus mode), controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the instance.


During application development, you can use the callback function of the AVPlayer to obtain the playback process information. If the application performs an operation when the AVPlayer is not in the given state, the system may throw an exception or generate other undefined behavior.


**Figure 1** Playback state transition 
![Playback status change](figures/playback-status-change-ndk.png)

For details about the states, see [AVPlayerState](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1). When the AVPlayer is in the **prepared**, **playing**, **paused**, or **completed** state, the playback engine is working and a large amount of RAM is occupied. If your application does not need to use the AVPlayer, call **OH_AVPlayer_Reset()** or **OH_AVPlayer_Release()** to release the instance.

## Developer's Tips

This topic describes only how to implement the playback of a media asset. In practice, background playback and playback conflicts may be involved. You can refer to the following description to handle the situation based on your service requirements.

- If you want the application to continue playing the media asset in the background or when the screen is off, use the [AVSession](../avsession/avsession-access-scene.md) and [continuous task](../../task-management/continuous-task.md) to prevent the playback from being forcibly interrupted by the system. Only ArkTS APIs are provided.
- If the media asset being played involves audio, the playback may be interrupted by other applications based on the system audio management policy. (For details, see [Audio Playback Concurrency Policy](../audio/audio-playback-concurrency.md).) It is recommended that the player application proactively listen for audio interruption events [AV_INFO_TYPE_INTERRUPT_EVENT](../../reference/apis-media-kit/_a_v_player.md#avplayeroninfotype-1) through [OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setplayercallback) and handle the events accordingly to avoid the inconsistency between the application status and the expected effect.
- When a device is connected to multiple audio output devices, the application can listen for audio output device changes [AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE](../../reference/apis-media-kit/_a_v_player.md#avplayeroninfotype-1) through [OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setplayercallback) and perform the processing accordingly.

## How to Develop
Link the dynamic library in the CMake script.
```
target_link_libraries(sample PUBLIC libavplayer.so)
```

You can use C/C++ APIs related to audio playback by including the header files [avplayer.h](../../reference/apis-media-kit/avplayer__base_8h.md), [avpalyer_base.h](../../reference/apis-media-kit/avplayer__base_8h.md), and [native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md).
Read [AVPlayer](../../reference/apis-media-kit/_a_v_player.md) for the API reference.

1. Call **OH_AVPlayer_Create()** to create an **AVPlayer** instance. The AVPlayer is the **idle** state.

2. Call **OH_AVPlayer_SetPlayerCallback()** to set the events to listen for, which will be used in the full-process scenario. The table below lists the supported events.
   | Event Type | Description |
   | -------- | -------- |
   | OH_AVPlayerOnInfo | Mandatory; used to listen for AVPlayer process information. |
   | OH_AVPlayerOnError | Mandatory; used to listen for AVPlayer errors. |

3. Call **OH_AVPlayer_SetURLSource()** to set the media asset URL. The AVPlayer enters the **initialized** state.

4. (Optional) Call **OH_AVPlayer_SetAudioRendererInfo()** to set the audio stream type.

5. (Optional) Call **OH_AVPlayer_SetAudioInterruptMode()** to set the audio interruption mode.

6. Call **OH_AVPlayer_Prepare()** to switch the AVPlayer to the **prepared** state. In this state, you can obtain the duration of the media asset to play and set the volume.

7. (Optional) Call **OH_AVPlayer_SetAudioEffectMode()** to set the audio effect mode.

8. Call **OH_AVPlayer_Play()**, **OH_AVPlayer_Pause()**, **OH_AVPlayer_Seek()**, and **OH_AVPlayer_Stop()** to perform audio playback control as required.

9. (Optional) Call **OH_AVPlayer_Reset()** to reset the AVPlayer. The AVPlayer enters the **idle** state again and you can change the media asset URL.

10. Call **OH_AVPlayer_Release()** to switch the AVPlayer to the **released** state. Now your application exits the playback.

## Sample Code

```c
#include "napi/native_api.h"

#include <multimedia/player_framework/avplayer.h>
#include <multimedia/player_framework/avplayer_base.h>
#include <multimedia/player_framework/native_averrors.h>

static char *Url;

void OnInfo(OH_AVPlayer *player, AVPlayerOnInfoType type, int32_t extra)
{
    int32_t ret;
    switch (type) {
        case AV_INFO_TYPE_STATE_CHANGE:
            switch (extra) {
                case AV_IDLE: // This state is reported upon a successful callback of OH_AVPlayer_Reset().
//                    ret = OH_AVPlayer_SetURLSource(player, url); // Set the URL.
//                    if (ret != AV_ERR_OK) {
//                    // Exception processing.
//                    }
                    break;
                case AV_INITIALIZED: 
                    ret = OH_AVPlayer_Prepare(player); // This state is reported when the AVPlayer sets the playback source.
                    if (ret != AV_ERR_OK) {
                    // Exception processing.
                    }
                    break;
                case AV_PREPARED:            
//                    ret = OH_AVPlayer_SetAudioEffectMode(player, EFFECT_NONE); // Set the audio effect mode.
//                    if (ret != AV_ERR_OK) {
//                    // Exception handling.   
//                    }  
                    ret = OH_AVPlayer_Play(player); // Call OH_AVPlayer_Play() to start playback.
                    if (ret != AV_ERR_OK) {
                    // Exception processing.
                    }
                    break;
                case AV_PLAYING:  
//                    ret = OH_AVPlayer_Pause(player); //Call OH_AVPlayer_Pause() to pause the playback.
//                    if (ret != AV_ERR_OK) {
//                    // Exception processing.
//                    }
                    break;
                case AV_PAUSED:  
//                    ret = OH_AVPlayer_Play(player); // Call OH_AVPlayer_Play() again to start playback.
//                    if (ret != AV_ERR_OK) {
//                    // Exception processing.
//                    }
//                    break;
                case AV_STOPPED:  
                    ret = OH_AVPlayer_Release(player); // Call OH_AVPlayer_Reset() to reset the AVPlayer state.
                    if (ret != AV_ERR_OK) {
                    // Exception processing.
                    }
                    break;
                case AV_COMPLETED:  
                    ret = OH_AVPlayer_Stop(player);// Call OH_AVPlayer_Stop() to stop the playback.
                    if (ret != AV_ERR_OK) {
                    // Exception processing.
                    }
                    break;
                default:
                    break;
            }
            break;
        case AV_INFO_TYPE_POSITION_UPDATE:
        // do something
            break;
        default:
            break;
    }
}

void OnError(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg)
{
    // do something
}

// Describe the mapped play method in the index.d.ts file and pass in a parameter of the string type.
// When calling the player method in the .ets file, pass in the file path testNapi.play("/data/test/test.mp3").
static napi_value Play(napi_env env, napi_callback_info info)
{
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    
    // Obtain the parameter type.
    napi_valuetype stringType;
    if (napi_ok != napi_typeof(env, args[0], &stringType)) {
        // Exception processing.
        return nullptr;
    }
    
    // Verify the parameter.
    if (napi_null == stringType) {
        // Exception processing.
        return nullptr;
    }
    
    // Obtain the length of the passed-in string.
    size_t length = 0;
    if (napi_ok != napi_get_value_string_utf8(env, args[0], nullptr, 0, &length)) {
        // Exception processing.
        return nullptr;
    }
    
    // If "" is passed in, the result is directly returned.
    if (length == 0) {
        // Exception processing.
        return nullptr;
    }
    
    // Read the passed-in string and place it in the buffer.
    char *url = new char[length + 1];
    if (napi_ok != napi_get_value_string_utf8(env, args[0], url, length + 1, &length)) {
        delete[] url;
        url = nullptr;
        // Exception processing.
        return nullptr;
    }

    Url = url;
    
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
    ret = OH_AVPlayer_SetURLSource (player, url); // Set the URL.
    if (ret != AV_ERR_OK) {
    // Exception processing.
    }
    // Set the audio stream type.
    OH_AudioStream_Usage streamUsage = OH_AudioStream_Usage::AUDIOSTREAM_USAGE_UNKNOWN;
    ret = OH_AVPlayer_SetAudioRendererInfo(player, streamUsage);
    if (ret != AV_ERR_OK) {
    // Exception handling.   
    }
    // Set the audio interruption mode.
    OH_AudioInterrupt_Mode interruptMode = OH_AudioInterrupt_Mode::AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT;
    ret = OH_AVPlayer_SetAudioInterruptMode(player, interruptMode);
    if (ret != AV_ERR_OK) {
    // Exception handling.   
    }
    napi_value value;
    napi_create_int32(env, 0, &value);
    return value;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        { "play", nullptr, Play, nullptr, nullptr, nullptr, napi_default, nullptr }
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version =1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
```
