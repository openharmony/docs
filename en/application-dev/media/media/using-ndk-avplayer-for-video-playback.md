# Using AVPlayer to Play Video (C/C++)

The [AVPlayer](../../reference/apis-media-kit/_a_v_player.md#avplayer) is used to play raw media assets in an end-to-end manner. In this topic, you will learn how to use the AVPlayer to play a complete video.


The full playback process includes creating an AVPlayer instance, setting callback functions, setting the media asset to play, setting playback parameters (volume, speed, and focus mode), setting the playback window, controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the AVPlayer instance.


During application development, you can obtain the playback process information through the callbacks [OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfocallback) and [OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerrorcallback) of the AVPlayer. If the application performs an operation when the AVPlayer is not in the given state, the system may throw an exception or generate other undefined behavior.

**Figure 1** Playback state transition

![Playback status change](figures/playback-status-change-ndk.png)

For details about the states, see [AVPlayerState](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1). When the AVPlayer is in the **prepared**, **playing**, **paused**, or **completed** state, the playback engine is working and a large amount of RAM is occupied. If your application does not need to use the AVPlayer, call **OH_AVPlayer_Reset()** or **OH_AVPlayer_Release()** to release the instance.

## Development Tips

This topic describes only how to implement the playback of a media asset. In practice, background playback and playback conflicts may be involved. You can refer to the following description to handle the situation based on your service requirements.

- If you want the application to continue playing the media asset in the background or when the screen is off, use the [AVSession](../avsession/avsession-access-scene.md) and [continuous task](../../task-management/continuous-task.md) to prevent the playback from being forcibly interrupted by the system. Only ArkTS APIs are provided.
- If the media asset being played involves audio, the playback may be interrupted by other applications based on the system audio management policy. (For details, see [Processing Audio Interruption Events](../audio/audio-playback-concurrency.md).) It is recommended that the player application proactively listen for audio interruption events [AV_INFO_TYPE_INTERRUPT_EVENT](../../reference/apis-media-kit/_a_v_player.md#avplayeroninfotype-1) through [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback) and handle the events accordingly to avoid the inconsistency between the application status and the expected effect.
- When a device is connected to multiple audio output devices, the application can listen for audio output device changes [AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE](../../reference/apis-media-kit/_a_v_player.md#avplayeroninfotype-1) through [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback) and perform the processing accordingly.
- During the playback, an internal error may occur, for example, network data download failure or media service unavailability. You are advised to set an error callback through [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback) and handle the error based on the error type.
- Use [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback) and [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback) to set the information callback [OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfocallback) and error callback [OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerrorcallback), respectively. After [OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfocallback) is set, the callback [OH_AVPlayerOnInfo](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfo) set through [OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setplayercallback) is not executed. After [OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerrorcallback) is set, the callback [OH_AVPlayerOnError](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerror) set through [OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setplayercallback) is not executed.

## How to Develop
Link the dynamic library in the CMake script.
```
target_link_libraries(sample PUBLIC libavplayer.so)
```

To use [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback) and [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback) to set the information callback and error callback, link the following dynamic link library in the CMake script:
```
target_link_libraries(sample PUBLIC libnative_media_core.so)
```

To use system logging, include the following header file:
```
#include <hilog/log.h>
```

In addition, link the following dynamic link library in the CMake script:
```
target_link_libraries(sample PUBLIC libhilog_ndk.z.so)
```

You can use C/C++ APIs related to video playback by including the header files [avplayer.h](../../reference/apis-media-kit/avplayer_8h.md), [avpalyer_base.h](../../reference/apis-media-kit/avplayer__base_8h.md), and [native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md).
Read [AVPlayer](../../reference/apis-media-kit/_a_v_player.md) for the API reference.

1. Create an AVPlayer instance by calling [OH_AVPlayer_Create()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_create). The AVPlayer is initialized to the [AV_IDLE](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1) state.

2. Set callbacks to listen for events. Specifically, call [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback) and [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback) to set the information callback and error callback, which are used in the entire process scenario. The table below lists the supported events.
   | Event Type| Description|
   | -------- | -------- |
   | OH_AVPlayerOnInfoCallback | Mandatory; used to listen for AVPlayer process information.|
   | OH_AVPlayerOnErrorCallback | Mandatory; used to listen for AVPlayer errors.|

    The application can obtain more information from the callbacks set by calling [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback) and [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback). In addition, it can set **userData** to distinguish different AVPlayer instances.

3. Set the media asset. Specifically, call [OH_AVPlayer_SetURLSource()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_seturlsource) to set the URL of the media asset. The AVPlayer enters the [AV_INITIALIZED](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1) state.

4. (Optional) Set the audio stream type by calling [OH_AVPlayer_SetAudioRendererInfo()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setaudiorendererinfo).

5. (Optional) Set the audio interruption mode by calling [OH_AVPlayer_SetAudioInterruptMode()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setaudiointerruptmode).

6. Set the playback window by calling [OH_AVPlayer_SetVideoSurface()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setvideosurface). This function must be called after **SetSource** and before **Prepare**.

7. Prepare for the playback by calling [OH_AVPlayer_Prepare()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_prepare). The AVPlayer enters the [AV_PREPARED](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1) state. In this case, you can obtain the duration and set the volume.

8. (Optional) Set the audio effect mode of the AVPlayer by calling [OH_AVPlayer_SetAudioEffectMode()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setaudioeffectmode).

9. Control the playback. You can call [OH_AVPlayer_Play()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_play), [OH_AVPlayer_Pause()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_pause), [OH_AVPlayer_Seek()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_seek), and [OH_AVPlayer_Stop()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_stop) to trigger different control operations.

10. (Optional) Reset the media asset by calling [OH_AVPlayer_Reset()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_reset). The AVPlayer enters the [AV_IDLE](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1) state again and you can change the media asset URL.

11. Exit the playback. Specifically, call [OH_AVPlayer_Release()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_release) to destroy the instance. The AVPlayer enters the [AV_RELEASED](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1) state and exits the playback. Further actions on the AVPlayer instance may lead to undefined behavior, such as the process crashing or the application terminating unexpectedly.

## Sample Code

```c++
#include "napi/native_api.h"

#include <ace/xcomponent/native_interface_xcomponent.h>
#include <multimedia/player_framework/avplayer.h>
#include <multimedia/player_framework/avplayer_base.h>
#include <multimedia/player_framework/native_averrors.h>

#include <hilog/log.h>

#define LOG_MSG_TAG "AVPlayerNdk"
#define LOG(format, ...) ((void)OH_LOG_Print(LOG_APP, LOG_INFO, 0xFF00, LOG_MSG_TAG, format, ##__VA_ARGS__))
#define LOGE(format, ...) ((void)OH_LOG_Print(LOG_APP, LOG_ERROR, 0xFF00, LOG_MSG_TAG, format, ##__VA_ARGS__))

typedef struct DemoNdkPlayer {
    OH_AVPlayer *player = nullptr;
    char *url = nullptr;
    int32_t errorCode = AV_ERR_UNKNOWN;

    int32_t value = -1;
    int32_t state = -1;
    int32_t stateChangeReason = -1;
    AVPlayerState avState = AV_IDLE;
    AVPlaybackSpeed speed = AV_SPEED_FORWARD_1_00_X;

    float volume = 0.0;
    int64_t duration = -1;

    int32_t width = -1;
    int32_t height = -1;

    static OHNativeWindow *nativeWindow;

    AVPlayerBufferingType bufferType = AVPLAYER_BUFFERING_START;
    int32_t bufferValue = -1;

    uint32_t *bitRates = nullptr;
    size_t bitRatesSize = 0;
    uint32_t bitRate = 0;

    int32_t interruptType = -1;
    int32_t interruptForce = -1;
    int32_t interruptHint = -1;
} DemoNdkPlayer;

OHNativeWindow *DemoNdkPlayer::nativeWindow = nullptr;

void HandleStateChange(OH_AVPlayer *player, AVPlayerState state) {
    OH_AVErrCode ret;
    switch (state) {
        case AV_IDLE: // This state is reported upon a successful callback of OH_AVPlayer_Reset().
//            ret = OH_AVPlayer_SetURLSource(player, url); // Set the URL.
//            if (ret != AV_ERR_OK) {
//            // Handle the exception.
//        }
            break;
        case AV_INITIALIZED:
            ret = OH_AVPlayer_SetVideoSurface(player, DemoNdkPlayer::nativeWindow); // Set the video playback surface.
            LOG("OH_AVPlayer_SetVideoSurface ret:%d", ret);
            ret = OH_AVPlayer_Prepare(player); // This state is reported when the AVPlayer sets the playback source.
            if (ret != AV_ERR_OK) {
            // Handle the exception.
            }
            break;
        case AV_PREPARED:
//            ret = OH_AVPlayer_SetAudioEffectMode(player, EFFECT_NONE); // Set the audio effect mode.
//            if (ret != AV_ERR_OK) {
//            // Handle the exception.   
//            }  
            ret = OH_AVPlayer_Play(player); // Call OH_AVPlayer_Play() to start playback.
            if (ret != AV_ERR_OK) {
            // Handle the exception.
            }
            break;
        case AV_PLAYING:
//            ret = OH_AVPlayer_Pause(player); // Call OH_AVPlayer_Pause() to pause the playback.
//            if (ret != AV_ERR_OK) {
//            // Handle the exception.
//            }
            break;
        case AV_PAUSED:
//            ret = OH_AVPlayer_Play(player); // Call OH_AVPlayer_Play() again to start playback.
//            if (ret != AV_ERR_OK) {
//            // Handle the exception.
//            }
           break;
        case AV_STOPPED:
            ret = OH_AVPlayer_Release(player); // Call OH_AVPlayer_Reset() to reset the AVPlayer state.
            if (ret != AV_ERR_OK) {
            // Handle the exception.
            }
            break;
        case AV_COMPLETED:
            ret = OH_AVPlayer_Stop(player);// Call OH_AVPlayer_Stop() to stop the playback.
            if (ret != AV_ERR_OK) {
            // Handle the exception.
            }
            break;
        default:
            break;
    }
}

void OHAVPlayerOnInfoCallback(OH_AVPlayer *player, AVPlayerOnInfoType type, OH_AVFormat *infoBody, void *userData) {
    OH_AVErrCode ret;
    int32_t value = -1;

    DemoNdkPlayer *demoNdkPlayer = reinterpret_cast<DemoNdkPlayer *>(userData);
    if (demoNdkPlayer == nullptr || player == nullptr) {
        LOGE("OHAVPlayerOnInfoCallback demoNdkPlayer is nullptr");
        return;
    }
    switch (type) {
    case AV_INFO_TYPE_STATE_CHANGE:
        LOG("AVPlayerOnInfoType AV_INFO_TYPE_STATE_CHANGE");
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_STATE, &demoNdkPlayer->state);
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_STATE_CHANGE_REASON, &demoNdkPlayer->stateChangeReason);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_STATE_CHANGE  state: %d ,stateChangeReason: %d",
            demoNdkPlayer->state, demoNdkPlayer->stateChangeReason);
        demoNdkPlayer->avState = static_cast<AVPlayerState>(demoNdkPlayer->state);
        HandleStateChange(player, demoNdkPlayer->avState);
        break;
    case AV_INFO_TYPE_SEEKDONE:
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_SEEK_POSITION, &value);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_SEEKDONE value: %d", value);
        break;
    case AV_INFO_TYPE_SPEEDDONE:
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_PLAYBACK_SPEED, &value);
        demoNdkPlayer->speed = static_cast<AVPlaybackSpeed>(value);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_SPEEDDONE value: %d", value);
        break;
    case AV_INFO_TYPE_BITRATEDONE:
        // Currently, OH_AVFormat does not support storage of data of the uint32_t type or custom type.
        // Obtain the data of the int32_t type and forcibly convert the data to the corresponding type.
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_BITRATE, &value);
        demoNdkPlayer->bitRate = static_cast<uint32_t>(value);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_BITRATEDONE value: %d", value);
        break;
    case AV_INFO_TYPE_EOS:
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_EOS");
        break;
    case AV_INFO_TYPE_POSITION_UPDATE:
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_CURRENT_POSITION, &value);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_POSITION_UPDATE value: %d", value);
        break;
    case AV_INFO_TYPE_MESSAGE:
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_MESSAGE_TYPE, &value);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_MESSAGE value: %d", value);
        break;
    case AV_INFO_TYPE_VOLUME_CHANGE:
        OH_AVFormat_GetFloatValue(infoBody, OH_PLAYER_VOLUME, &demoNdkPlayer->volume);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_VOLUME_CHANGE value: %f", demoNdkPlayer->volume);
        break;
    case AV_INFO_TYPE_RESOLUTION_CHANGE:
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_VIDEO_WIDTH, &demoNdkPlayer->width);
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_VIDEO_HEIGHT, &demoNdkPlayer->height);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_RESOLUTION_CHANGE width: %d, height: %d",
            demoNdkPlayer->width, demoNdkPlayer->height);
        break;
    case AV_INFO_TYPE_BUFFERING_UPDATE:
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_BUFFERING_TYPE, &value);
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_BUFFERING_VALUE, &demoNdkPlayer->bufferValue);
        demoNdkPlayer->bufferType = static_cast<AVPlayerBufferingType>(value);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_BUFFERING_UPDATE bufferType: %d, bufferValue: %d",
            value, demoNdkPlayer->bufferValue);
        break;
    case AV_INFO_TYPE_BITRATE_COLLECT: {
        uint8_t *bitRates = nullptr;
        size_t size = 0;
        OH_AVFormat_GetBuffer(infoBody, OH_PLAYER_BITRATE_ARRAY, &bitRates, &size);
        demoNdkPlayer->bitRatesSize = size / sizeof(uint32_t);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_BITRATE_COLLECT bytes size: %zu, size: %zu",
            size, demoNdkPlayer->bitRatesSize );
        if (demoNdkPlayer->bitRatesSize <= 0) {
            LOGE("OHAVPlayerOnInfoCallback AV_INFO_TYPE_BITRATE_COLLECT invalid bitRatesSize");
            return;
        }
        demoNdkPlayer->bitRates = new uint32_t[demoNdkPlayer->bitRatesSize];
        if (demoNdkPlayer->bitRates == nullptr || bitRates == nullptr) {
            LOGE("OHAVPlayerOnInfoCallback AV_INFO_TYPE_BITRATE_COLLECT bitRates is nullptr");
            return;
        }
        memcpy((void *)(demoNdkPlayer->bitRates), (void *)bitRates, demoNdkPlayer->bitRatesSize * sizeof(uint32_t));
        for (size_t i = 0; i < demoNdkPlayer->bitRatesSize; i++) {
            LOGE("OHAVPlayerOnInfoCallback AV_INFO_TYPE_BITRATE_COLLECT bitRates[%zu]: %zu",
                i, *(demoNdkPlayer->bitRates + i));
        }
        break;
    }
    case AV_INFO_TYPE_INTERRUPT_EVENT:
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_AUDIO_INTERRUPT_TYPE, &demoNdkPlayer->interruptType);
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_AUDIO_INTERRUPT_FORCE, &demoNdkPlayer->interruptForce);
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_AUDIO_INTERRUPT_HINT, &demoNdkPlayer->interruptHint);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_INTERRUPT_EVENT interruptType: %d, interruptForce: %d"
            ", interruptHint: %d", demoNdkPlayer->interruptType, demoNdkPlayer->interruptForce,
            demoNdkPlayer->interruptHint);
        break;
    case AV_INFO_TYPE_DURATION_UPDATE:
        OH_AVFormat_GetLongValue(infoBody, OH_PLAYER_DURATION, &demoNdkPlayer->duration);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_DURATION_UPDATE value: %lld", demoNdkPlayer->duration);
        break;
    case AV_INFO_TYPE_IS_LIVE_STREAM:
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_IS_LIVE_STREAM, &value);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_IS_LIVE_STREAM value: %d", value);
        break;
    case AV_INFO_TYPE_TRACKCHANGE:
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_TRACKCHANGE value: %d", value);
        break;
    case AV_INFO_TYPE_TRACK_INFO_UPDATE:
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_TRACK_INFO_UPDATE value: %d", value);
        break;
    case AV_INFO_TYPE_SUBTITLE_UPDATE:
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_SUBTITLE_UPDATE value: %d", value);
        break;
    case AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE:
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_AUDIO_DEVICE_CHANGE_REASON, &value);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE value: %d", value);
        break;
    default:
        break;
    }
}

void OHAVPlayerOnErrorCallback(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg, void *userData) {
    LOG("OHAVPlayerOnError errorCode: %d ,errorMsg: %s", errorCode, errorMsg == nullptr ? "unknown" : errorMsg);
    DemoNdkPlayer *demoNdkPlayer = reinterpret_cast<DemoNdkPlayer *>(userData);
    if (demoNdkPlayer == nullptr || player == nullptr) {
        LOGE("OHAVPlayerOnErrorCallback demoNdkPlayer or player is nullptr");
        return;
    }
    demoNdkPlayer->errorCode = errorCode;
    // do something
}

// Describe the mapped play method in the index.d.ts file and pass in a parameter of the string type.
// When calling the player method in the .ets file, pass in the file path testNapi.play("/data/test/test.mp4").
static napi_value Play(napi_env env, napi_callback_info info)
{
    OH_AVErrCode ret;
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    
    // Obtain the parameter type.
    napi_valuetype stringType;
    if (napi_ok != napi_typeof(env, args[0], &stringType)) {
        // Handle the exception.
        return nullptr;
    }
    
    // Verify the parameter.
    if (napi_null == stringType) {
        // Handle the exception.
        return nullptr;
    }
    
    // Obtain the length of the passed-in string.
    size_t length = 0;
    if (napi_ok != napi_get_value_string_utf8(env, args[0], nullptr, 0, &length)) {
        // Handle the exception.
        return nullptr;
    }
    
    // If "" is passed in, the result is directly returned.
    if (length == 0) {
        // Handle the exception.
        return nullptr;
    }
    
    // Read the passed-in string and place it in the buffer.
    char *url = new char[length + 1];
    if (napi_ok != napi_get_value_string_utf8(env, args[0], url, length + 1, &length)) {
        delete[] url;
        url = nullptr;
        // Handle the exception.
        return nullptr;
    }

    // Use the new function to set the information callback and error callback. Do not use OH_AVPlayer_SetPlayerCallback.
    // Release the object when it is no longer needed.
    OH_AVPlayer *player = OH_AVPlayer_Create();
    DemoNdkPlayer *demoNdkPlayer = new DemoNdkPlayer({
        .player = player,
        .url = url,
    });
    LOG("call OH_AVPlayer_SetPlayerOnInfoCallback");
    ret = OH_AVPlayer_SetOnInfoCallback(player, OHAVPlayerOnInfoCallback, demoNdkPlayer);
    LOG("OH_AVPlayer_SetPlayerOnInfoCallback ret:%d", ret);
    LOG("call OH_AVPlayer_SetPlayerOnErrorCallback");
    ret = OH_AVPlayer_SetOnErrorCallback(player, OHAVPlayerOnErrorCallback, demoNdkPlayer);
    LOG("OH_AVPlayer_SetPlayerOnErrorCallback ret:%d", ret);

    if (ret != AV_ERR_OK) {
    // Handle the exception.
    }
    ret = OH_AVPlayer_SetURLSource(player, url); // Set the URL.
    if (ret != AV_ERR_OK) {
    // Handle the exception.
    }
    // Set the audio stream type.
    OH_AudioStream_Usage streamUsage = OH_AudioStream_Usage::AUDIOSTREAM_USAGE_UNKNOWN;
    ret = OH_AVPlayer_SetAudioRendererInfo(player, streamUsage);
    if (ret != AV_ERR_OK) {
    // Handle the exception.   
    }
    // Set the audio interruption mode.
    OH_AudioInterrupt_Mode interruptMode = OH_AudioInterrupt_Mode::AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT;
    ret = OH_AVPlayer_SetAudioInterruptMode(player, interruptMode);
    if (ret != AV_ERR_OK) {
    // Handle the exception.   
    }
    napi_value value;
    napi_create_int32(env, 0, &value);
    return value;
}

// Define the surface callback.
void OnSurfaceCreatedCB(OH_NativeXComponent *component, void *window) {
    LOG("OnSurfaceCreatedCB...");
    // Obtain an OHNativeWindow instance.
    OHNativeWindow * nativeWindow = static_cast<OHNativeWindow *>(window);
    DemoNdkPlayer::nativeWindow = nativeWindow;
    // ...
}

void OnSurfaceDestroyedCB(OH_NativeXComponent *component, void *window) {
    LOG("OnSurfaceDestroyedCB...");
    // Obtain an OHNativeWindow instance.
    OHNativeWindow * nativeWindow = static_cast<OHNativeWindow *>(window);
    // ...
}

void Export(napi_env env, napi_value exports) {
    if ((env == nullptr) || (exports == nullptr)) {
        LOG("Export: env or exports is null");
        return;
    }
    napi_value exportInstance = nullptr;
    if (napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &exportInstance) != napi_ok) {
        LOG("Export: napi_get_named_property fail");
        return;
    }
    OH_NativeXComponent *nativeXComponent = nullptr;
    if (napi_unwrap(env, exportInstance, reinterpret_cast<void **>(&nativeXComponent)) != napi_ok) {
        LOG("Export: napi_unwrap fail");
        return;
    }
    char idStr[OH_XCOMPONENT_ID_LEN_MAX + 1] = {'\0'};
    uint64_t idSize = OH_XCOMPONENT_ID_LEN_MAX + 1;
    if (OH_NativeXComponent_GetXComponentId(nativeXComponent, idStr, &idSize) != OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
        LOG("OH_NativeXComponent_GetXComponentId fail");
        return;
    }
    LOG("call Export surfaceID=%s", idStr);
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        { "Play", nullptr, Play, nullptr, nullptr, nullptr, napi_default, nullptr }
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);

    Export(env, exports);
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
