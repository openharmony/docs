# Using AVPlayer to Play Audio (C/C++)

The [AVPlayer](media-kit-intro.md#avplayer) is used to play raw media assets in an end-to-end manner. In this topic, you will learn how to use the AVPlayer to play a complete piece of music.


The full playback process includes creating an AVPlayer instance, setting callback functions, setting the media asset to play, setting playback parameters (volume, speed, and focus mode), controlling playback (play, pause, seek, and stop), resetting the playback configuration, and releasing the AVPlayer instance.


During application development, you can obtain the playback process information through the callbacks [OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeroninfocallback) and [OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeronerrorcallback) of the AVPlayer. If the application performs an operation when the AVPlayer is not in the given state, the system may throw an exception or generate other undefined behavior.

**Figure 1** Playback state transition

![Playback status change](figures/playback-status-change-ndk.png)

For details about the states, see [AVPlayerState](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate). When the AVPlayer is in the **prepared**, **playing**, **paused**, or **completed** state, the playback engine is working and a large amount of RAM is occupied. If your application does not need to use the AVPlayer, call **OH_AVPlayer_Reset()** or **OH_AVPlayer_Release()** to release the instance.

## Development Tips

This topic describes only how to implement the playback of a media asset. In practice, background playback and playback conflicts may be involved. You can refer to the following description to handle the situation based on your service requirements.

- If you want the application to continue playing the media asset in the background or when the screen is off, use the [AVSession](../avsession/avsession-access-scene.md) and [continuous task](../../task-management/continuous-task.md) to prevent the playback from being forcibly interrupted by the system. Only ArkTS APIs are provided.
- If the media asset being played involves audio, the playback may be interrupted by other applications based on the system audio management policy. (For details, see [Processing Audio Interruption Events](../audio/audio-playback-concurrency.md).) It is recommended that the player application proactively listen for audio interruption events [AV_INFO_TYPE_INTERRUPT_EVENT](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayeroninfotype) through [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback) and handle the events accordingly to avoid the inconsistency between the application status and the expected effect.
- When a device is connected to multiple audio output devices, the application can listen for audio output device changes [AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayeroninfotype) through [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback) and perform the processing accordingly.
- During the playback, an internal error may occur, for example, network data download failure or media service unavailability. You are advised to set an error callback through [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback) and handle the error based on the error type.
- Use [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback) and [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback) to set the information callback [OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeroninfocallback) and error callback [OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeronerrorcallback), respectively. After[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeroninfocallback) is set, the callback [OH_AVPlayerOnInfo](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeroninfo) set through [OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setplayercallback) is not executed. After [OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeronerrorcallback) is set, the callback[OH_AVPlayerOnError](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeronerror) set through [OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setplayercallback) is not executed.

## How to Develop
Link the following dynamic library in the CMake script:
```
target_link_libraries(sample PUBLIC libavplayer.so)
```

To use [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback) and [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback) to set the information callback and error callback, link the following dynamic link library in the CMake script:
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

You can use C/C++ APIs related to audio playback by including the header files [avplayer.h](../../reference/apis-media-kit/capi-avplayer-h.md), [avpalyer_base.h](../../reference/apis-media-kit/capi-avplayer-base-h.md), and [native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md).

Read [AVPlayer](../../reference/apis-media-kit/capi-avplayer.md) for the API reference.

1. Create an AVPlayer instance by calling [OH_AVPlayer_Create()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_create). The AVPlayer is initialized to the [AV_IDLE](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate) state.

2. Set callbacks to listen for events. Specifically, call [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback) and [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback) to set the information callback and error callback, which are used in the entire process scenario. The table below lists the supported events.
   | Event Type| Description|
   | -------- | -------- |
   | OH_AVPlayerOnInfoCallback | Mandatory; used to listen for AVPlayer process information.|
   | OH_AVPlayerOnErrorCallback | Mandatory; used to listen for AVPlayer errors.|

    The application can obtain more information from the callbacks set by calling [OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback) and [OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback). In addition, it can set **userData** to distinguish different AVPlayer instances.

3. Set the media asset. Specifically, call [OH_AVPlayer_SetURLSource()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_seturlsource) to set the URL of the media asset. The AVPlayer enters the [AV_INITIALIZED](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate) state.

4. (Optional) Set the audio stream type by calling [OH_AVPlayer_SetAudioRendererInfo()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setaudiorendererinfo).

5. (Optional) Set the audio interruption mode by calling [OH_AVPlayer_SetAudioInterruptMode()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setaudiointerruptmode).

6. Prepare for the playback by calling [OH_AVPlayer_Prepare()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_prepare). The AVPlayer enters the [AV_PREPARED](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate) state. In this case, you can obtain the duration and set the volume.

7. (Optional) Set the audio effect mode of the AVPlayer by calling [OH_AVPlayer_SetAudioEffectMode()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setaudioeffectmode).

8. Control the playback. You can call [OH_AVPlayer_Play()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_play), [OH_AVPlayer_Pause()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_pause), [OH_AVPlayer_Seek()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_seek), and [OH_AVPlayer_Stop()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_stop) to trigger different control operations.

9. (Optional) Reset the media asset by calling [OH_AVPlayer_Reset()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_reset). The AVPlayer enters the [AV_IDLE](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate) state again and you can change the media asset URL.

10. Exit the playback. Specifically, call [OH_AVPlayer_Release()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_release) to destroy the instance. The AVPlayer enters the [AV_RELEASED](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate) state and exits the playback. Further actions on the AVPlayer instance may lead to undefined behavior, such as the process crashing or the application terminating unexpectedly.

## Running the Sample Project

1. Create a project, download the [sample project](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerNDKAudio), and copy the following resources of the sample project to the corresponding directories.
    ```
    AVPlayerNDKAudio
    entry/src/main/ets/
    └── pages
        └── Index.ets (playback page)
    entry/src/main/
    ├── cpp
    │   ├── types
    │   │   └── libentry
    │   │       └── Index.d.ts (JavaScript mapping of NDK functions)
    │ ├── CMakeLists.txt (CMake script)
    │   └── napi_init.cpp (NDK functions)
    └── resources
        ├── base
        │   ├── element
        │   │   ├── color.json
        │   │   ├── float.json
        │   │   └── string.json
        │   └── media
        │       ├── ic_video_play.svg (play button image resource)
        │       └── ic_video_pause.svg (pause button image resource)
        └── rawfile
            └── test_01.mp3 (audio resource)
    ```
2. Compile and run the project.

## Development Example

```c++
#include "napi/native_api.h"
#include <js_native_api.h>
#include <multimedia/player_framework/avplayer.h>
#include "multimedia/player_framework/avplayer_base.h"
#include "multimedia/player_framework/native_averrors.h"
#include <string>
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <hilog/log.h>

...

void OHAVPlayerOnInfoCallback(OH_AVPlayer *player, AVPlayerOnInfoType type, OH_AVFormat *infoBody, void *userData) {
    int32_t ret;
    int32_t value = -1;

    int32_t state = -1;
    int32_t stateChangeReason = -1;
    AVPlayerState avState = AV_IDLE;

    float volume = 0.0;

    int32_t width = -1;
    int32_t height = -1;

    int32_t bufferType = -1;
    int32_t bufferValue = -1;

    uint8_t *bitRates;
    size_t size;

    int32_t interruptType = -1;
    int32_t interruptForce = -1;
    int32_t interruptHint = -1;
    switch (type) {
    case AV_INFO_TYPE_STATE_CHANGE:
        LOG("AVPlayerOnInfoType AV_INFO_TYPE_STATE_CHANGE");
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_STATE, &state);
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_STATE_CHANGE_REASON, &stateChangeReason);
        LOG("OHAVPlayerOnInfoCallback AV_INFO_TYPE_STATE_CHANGE  state: %{public}d ,stateChangeReason: %{public}d", 
            state, stateChangeReason);
        avState = static_cast<AVPlayerState>(state);
        switch (avState) {
        case AV_IDLE: // This state is reported upon a successful callback of OH_AVPlayer_Reset().
            LOG("AVPlayerState  AV_IDLE");
            break;
        case AV_INITIALIZED: {
            LOG("AVPlayerState  AV_INITIALIZED");
            auto context = SampleManager::GetInstance();
            ret = OH_AVPlayer_SetVideoSurface(player, context->nativeWindow_);
            LOG("OH_AVPlayer_SetVideoSurface ret:%{public}d", ret);
            ret = OH_AVPlayer_Prepare(player); // This state is reported when the AVPlayer sets the playback source.
            if (ret != AV_ERR_OK) {
                // Handle the exception.
                LOG("player  %{public}s", "OH_AVPlayer_Prepare Err");
            }
        } break;
        case AV_PREPARED:
            LOG("AVPlayerState AV_PREPARED");
            ret = OH_AVPlayer_SetAudioEffectMode(player, EFFECT_NONE); // Set the audio effect mode.
            LOG("OH_AVPlayer_SetAudioEffectMode ret:%{public}d", ret);
            ret = OH_AVPlayer_Play(player); // Call OH_AVPlayer_Play() to start playback.
            LOG("OH_AVPlayer_Play ret:%{public}d", ret);
            break;
        case AV_PLAYING:
            LOG("AVPlayerState AV_PLAYING");
            break;
        case AV_PAUSED:
            LOG("AVPlayerState AV_PAUSED");
            break;
        case AV_STOPPED:
            LOG("AVPlayerState AV_STOPPED");
            break;
        case AV_COMPLETED:
            LOG("AVPlayerState AV_COMPLETED");
            break;
        case AV_ERROR:
            LOG("AVPlayerState AV_ERROR");
            break;
        case AV_RELEASED:
            LOG("AVPlayerState AV_RELEASED");
            break;
        default:
            break;
        }
        break;
    ...
    default:
        break;
    }
}
void OHAVPlayerOnErrorCallback(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg, void *userData) {
    LOG("OHAVPlayerOnErrorCallback errorCode: %{public}d ,errorMsg: %{public}s", errorCode, errorMsg);
}
static napi_value NAPI_Global_Setup(napi_env env, napi_callback_info info) {

    LOG("Call NAPI AVPlayer setup");
    size_t argc = 4;
    napi_value args[4] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    // Obtain the parameter type.
    napi_valuetype stringType;
    if (napi_ok != napi_typeof(env, args[0], &stringType)) {
        // Handle the exception.
        LOG("Parameter exception");
        return nullptr;
    }
    // Verify the parameter.
    if (napi_null == stringType) {
        // Handle the exception.
        LOG("Parameter exception: null");
        return nullptr;
    }
    // Obtain the length of the passed-in string.
    size_t length = 0;
    if (napi_ok != napi_get_value_string_utf8(env, args[0], nullptr, 0, &length)) {
        // Handle the exception.
        LOG("Abnormal parameter length");
        return nullptr;
    }
    // If "" is passed in, the result is directly returned.
    if (length == 0) {
        // Handle the exception.
        LOG("Null parameter");
        return nullptr;
    }
    // Read the passed-in string and place it in the buffer.
    char *url = new char[length + 1];
    if (napi_ok != napi_get_value_string_utf8(env, args[0], url, length + 1, &length)) {
        delete[] url;
        url = nullptr;
        // Handle the exception.
        LOG("URL error");
        return nullptr;
    }
    int pType;
    napi_get_value_int32(env, args[1], &pType);
    LOG("fd type %{public}d", pType);
    int pOffset;
    napi_get_value_int32(env, args[2], &pOffset);
    LOG("fd size %{public}d", pOffset);
    int pSize;
    napi_get_value_int32(env, args[3], &pSize);
    LOG("fd size %{public}d", pSize);
    
    // Create an AVPlayer instance.
    if(SampleManager::GetInstance()->player_) {
        OH_AVPlayer_Release(SampleManager::GetInstance()->player_);
    }
    OH_AVPlayer *player = OH_AVPlayer_Create();
    SampleManager::GetInstance()->SetAVPlayer(player);
    // Set the callback to listen for process information.
    LOG("call OH_AVPlayer_SetPlayerOnInfoCallback");
    int32_t ret = OH_AVPlayer_SetOnInfoCallback(player, OHAVPlayerOnInfoCallback, nullptr);
    LOG("OH_AVPlayer_SetPlayerOnInfoCallback ret:%{public}d", ret);
    LOG("call OH_AVPlayer_SetPlayerOnErrorCallback");
    ret = OH_AVPlayer_SetOnErrorCallback(player, OHAVPlayerOnErrorCallback, nullptr);
    LOG("OH_AVPlayer_SetPlayerOnErrorCallback ret:%{public}d", ret);
    {
        LOG("player %{public}s  >> fd: %{public}d offset: %{public}d fileSize: %{public}d", 
            url, pType, pOffset, pSize);
        LOG("call %{public}s", "OH_AVPlayer_SetFDSource");
        ret = OH_AVPlayer_SetFDSource(player, pType, pOffset, pSize);
        LOG("OH_AVPlayer_SetFDSource ret:%{public}d", ret);
    }
    // Set the audio stream type.
    LOG("call %{public}s", "OH_AVPlayer_SetAudioRendererInfo");
    OH_AudioStream_Usage streamUsage = OH_AudioStream_Usage::AUDIOSTREAM_USAGE_UNKNOWN;
    ret = OH_AVPlayer_SetAudioRendererInfo(player, streamUsage);
    LOG("OH_AVPlayer_SetAudioRendererInfo ret:%{public}d", ret);
    // Set the audio interruption mode.
    LOG("call OH_AVPlayer_SetAudioInterruptMode");
    OH_AudioInterrupt_Mode interruptMode = OH_AudioInterrupt_Mode::AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT;
    ret = OH_AVPlayer_SetAudioInterruptMode(player, interruptMode);
    LOG("OH_AVPlayer_SetAudioInterruptMode ret:%{public}d", ret);
    napi_value value;
    napi_create_int32(env, 0, &value);
    return value;
}
static napi_value NAPI_Global_Play(napi_env env, napi_callback_info info) {
    int ret = -1;
    auto context = SampleManager::GetInstance();
    if (context->player_ != NULL) {
        ret = OH_AVPlayer_Play(context->player_);
        LOG("OH_AVPlayer_Play ret:%{public}d", ret);
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, ret, &value);
    return value;
}
static napi_value NAPI_Global_SetSpeed(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int speed_code;
    napi_get_value_int32(env, args[0], &speed_code);
    int ret = -1;
    auto context = SampleManager::GetInstance();
    if (context->player_ != NULL) {
        switch (speed_code) {...}
        LOG("OH_AVPlayer_SetPlaybackSpeed ret:%{public}d", ret);
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, ret, &value);
    return value;
}
static napi_value NAPI_Global_GetSpeed(napi_env env, napi_callback_info info) {
    auto context = SampleManager::GetInstance();
    AVPlaybackSpeed speed;
    if (context->player_ != NULL) {
        OH_AVPlayer_GetPlaybackSpeed(context->player_, &speed);
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, speed, &value);
    return value;
}
static napi_value NAPI_Global_Pause(napi_env env, napi_callback_info info) {
    int ret = 100;
    auto context = SampleManager::GetInstance();
    if (context->player_ != NULL) {
        ret = OH_AVPlayer_Pause(context->player_);
        LOG("OH_AVPlayer_Pause ret:%{public}d", ret);
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, ret, &value);
    return value;
}
static napi_value NAPI_Global_Seek(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2] = {nullptr};
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int seekValue;
    napi_get_value_int32(env, args[0], &seekValue);
    int mode;
    napi_get_value_int32(env, args[1], &mode);
    auto context = SampleManager::GetInstance();
    if (context->player_ != NULL) {
        int ret;
        switch (mode) {...}
        LOG("OH_AVPlayer_Seek ret:%{public}d", ret);
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, 0, &value);
    return value;
}
static napi_value NAPI_Global_GetDuration(napi_env env, napi_callback_info info) {
    auto context = SampleManager::GetInstance();
    int ret;
    int32_t duration;
    if (context->player_ != NULL) {
        ret = OH_AVPlayer_GetDuration(context->player_, &duration);
        if (ret != AV_ERR_OK) {
            LOG("OH_AVPlayer_GetDuration fail");
        }
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, duration, &value);
    return value;
}
static napi_value NAPI_Global_GetCurrentTime(napi_env env, napi_callback_info info) {
    auto context = SampleManager::GetInstance();
    int ret;
    int32_t currentTime;
    if (context->player_ != NULL) {
        ret = OH_AVPlayer_GetCurrentTime(context->player_, &currentTime);
        if (ret != AV_ERR_OK) {
            LOG("OH_AVPlayer_GetCurrentTime fail");
        }
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, currentTime, &value);
    return value;
}
static napi_value NAPI_Global_GetVideoHeight(napi_env env, napi_callback_info info) {
    int ret = -1;
    auto context = SampleManager::GetInstance();
    if (context->player_ != NULL) {
        int32_t videoHeight;
        ret = OH_AVPlayer_GetVideoHeight(context->player_, &videoHeight);
        LOG("OH_AVPlayer_GetVideoHeight ret:%{public}d videoHeight: %{public}d ", ret, videoHeight);
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, ret, &value);
    return value;
}
static napi_value NAPI_Global_GetVideoWidth(napi_env env, napi_callback_info info) {
    int ret = -1;
    auto context = SampleManager::GetInstance();
    if (context->player_ != NULL) {
        int32_t videoWidth;
        ret = OH_AVPlayer_GetVideoWidth(context->player_, &videoWidth);
        LOG("OH_AVPlayer_GetVideoWidth ret:%{public}d videoWidth: %{public}d ", ret, videoWidth);
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, ret, &value);
    return value;
}
static napi_value NAPI_Global_Release(napi_env env, napi_callback_info info) {
    int ret = -1;
    auto context = SampleManager::GetInstance();
    if (context->player_ != NULL) {
        ret = OH_AVPlayer_Release(context->player_);
        LOG("OH_AVPlayer_Release ret:%{public}d", ret);
    } else {
        LOG("no found Player Instances");
    }
    napi_value value;
    napi_create_int32(env, ret, &value);
    return value;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"setup", nullptr, NAPI_Global_Setup, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"play", nullptr, NAPI_Global_Play, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"setSpeed", nullptr, NAPI_Global_SetSpeed, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getSpeed", nullptr, NAPI_Global_GetSpeed, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"pause", nullptr, NAPI_Global_Pause, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"seek", nullptr, NAPI_Global_Seek, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getDuration", nullptr, NAPI_Global_GetDuration, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getCurrentTime", nullptr, NAPI_Global_GetCurrentTime, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getVideoHeight", nullptr, NAPI_Global_GetVideoHeight, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"getVideoWidth", nullptr, NAPI_Global_GetVideoWidth, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"release", nullptr, NAPI_Global_Release, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    SampleManager::GetInstance()->Export(env, exports);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
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
