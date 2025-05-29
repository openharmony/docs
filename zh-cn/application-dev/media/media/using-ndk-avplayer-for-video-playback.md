# 使用AVPlayer播放视频(C/C++)

使用[AVPlayer](../../reference/apis-media-kit/capi-avplayer.md)可以实现端到端播放原始媒体资源，本开发指导将以完整地播放一个视频作为示例，向开发者讲解AVPlayer视频播放相关功能。

播放的全流程包含：创建AVPlayer，设置回调监听函数，设置播放资源，设置播放参数（音量/倍速/焦点模式），设置播放窗口，播放控制（播放/暂停/跳转/停止），重置，销毁播放器实例。

在进行应用开发的过程中，开发者可以通过AVPlayer的信息监听回调函数[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeroninfocallback)和错误监听回调函数[OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeronerrorcallback)主动获取播放过程信息。如果应用在视频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。

**图1** 播放状态变化示意图  
![Playback status change](figures/playback-status-change-ndk.png)

状态的详细说明请参考[AVPlayerState](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate)。当播放处于prepared / playing / paused / completed状态时，播放引擎处于工作状态，这需要占用系统较多的运行内存。当客户端暂时不使用播放器时，调用reset()或release()回收内存资源，做好资源利用。

## 开发建议

当前指导仅介绍如何实现媒体资源播放，在应用开发过程中可能会涉及后台播放、播放冲突等情况，请根据实际需要参考以下说明。

- 如果要实现后台播放或熄屏播放，需要接入[AVSession（媒体会话）](../avsession/avsession-access-scene.md)和[申请长时任务](../../task-management/continuous-task.md)，避免播放被系统强制中断。此功能仅提供ArkTS API。
- 应用在播放过程中，若播放的媒体数据涉及音频，根据系统音频管理策略（参考[处理音频焦点事件](../audio/audio-playback-concurrency.md)），可能会被其他应用打断，建议通过[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback)主动监听音频打断事件[AV_INFO_TYPE_INTERRUPT_EVENT](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayeroninfotype)，根据其内容提示，做出相应的处理，避免出现应用状态与预期效果不一致的问题。
- 面对设备同时连接多个音频输出设备的情况，建议通过[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback)主动监听音频输出设备改变事件[AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayeroninfotype)，从而做出相应处理。
- 应用在播放过程中，系统内部可能异常，如网络数据下载失败、媒体服务死亡不可用等，建议通过[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback)接口设置错误监听回调函数，根据不同错误类型，做出相应处理，避免出现播放异常。
- 使用[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback)接口分别设置信息监听回调函数[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeroninfocallback)和错误监听回调函数[OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeronerrorcallback)。当应用成功设置信息监听回调函数[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeroninfocallback)后，不再执行通过[OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setplayercallback)设置的信息监听回调函数[OH_AVPlayerOnInfo](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeroninfo)；当应用成功设置错误监听回调函数[OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeronerrorcallback)后，不再执行通过[OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setplayercallback)设置的错误监听回调函数[OH_AVPlayerOnError](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeronerror)。

## 开发步骤及注意事项
在 CMake 脚本中链接动态库：
```
target_link_libraries(sample PUBLIC libavplayer.so)
```

使用[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback)接口设置信息监听回调函数和错误监听回调函数，需要在 CMake 脚本中链接如下动态库：
```
target_link_libraries(sample PUBLIC libnative_media_core.so)
```

开发者使用系统日志能力时，需引入如下头文件：
```
#include <hilog/log.h>
```

并需要在 CMake 脚本中链接如下动态库:
```
target_link_libraries(sample PUBLIC libhilog_ndk.z.so)
```

开发者通过引入[avplayer.h](../../reference/apis-media-kit/capi-avplayer-h.md)、[avpalyer_base.h](../../reference/apis-media-kit/capi-avplayer-base-h.md)和[native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md)头文件，使用视频播放相关API。
详细的API说明请参考[AVPlayer API](../../reference/apis-media-kit/capi-avplayer.md)。

1. 创建AVPlayer实例：调用[OH_AVPlayer_Create()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_create)，AVPlayer初始化为[AV_IDLE](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate)状态。

2. 设置回调监听函数：使用[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback)接口设置信息监听回调函数和错误监听回调函数，搭配全流程场景使用。支持的监听事件包括：
   | 事件类型 | 说明 |
   | -------- | -------- |
   | OH_AVPlayerOnInfoCallback | 必要事件，监听播放器的过程信息。 |
   | OH_AVPlayerOnErrorCallback | 必要事件，监听播放器的错误信息。 |

    应用使用[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setonerrorcallback)接口设置信息监听回调函数和错误监听回调函数，可以获取更多信息，还可以通过设置 userData 区分不同播放实例。

3. 设置资源：调用[OH_AVPlayer_SetURLSource()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_seturlsource)，设置属性url，AVPlayer进入[AV_INITIALIZED](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate)状态。

4. （可选）设置音频流类型：调用[OH_AVPlayer_SetAudioRendererInfo()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setaudiorendererinfo)，设置AVPlayer音频流类型。

5. （可选）设置音频打断模式：调用[OH_AVPlayer_SetAudioInterruptMode()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setaudiointerruptmode)，设置AVPlayer音频流打断模式。

6. 设置播放画面窗口：调用[OH_AVPlayer_SetVideoSurface()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setvideosurface)设置播放画面窗口。此函数必须在SetSource之后，Prepare之前调用。

7. 准备播放：调用[OH_AVPlayer_Prepare()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_prepare)，AVPlayer进入[AV_PREPARED](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate)状态，此时可以获取时长，设置音量。

8. （可选）设置音频音效模式：调用[OH_AVPlayer_SetAudioEffectMode()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setaudioeffectmode)，设置AVPlayer音频音效模式。

9. 视频播控：播放[OH_AVPlayer_Play()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_play)，暂停[OH_AVPlayer_Pause()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_pause)，跳转[OH_AVPlayer_Seek()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_seek)，停止[OH_AVPlayer_Stop()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_stop)等操作。

10. （可选）更换资源：调用[OH_AVPlayer_Reset()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_reset)重置资源，AVPlayer重新进入[AV_IDLE](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate)状态，允许更换资源url。

11. 退出播放：调用[OH_AVPlayer_Release()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_release)销毁实例，AVPlayer进入[AV_RELEASED](../../reference/apis-media-kit/capi-avplayer-base-h.md#avplayerstate)状态，退出播放。之后再操作AVPlayer实例则行为未知，可能导致应用进程崩溃，应用闪退。

## 运行完整示例

1. 新建工程，下载[示例工程](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerNDKVideo)，并将示例工程的以下资源复制到对应目录。
    ```
    AVPlayerNDKVideo
    entry/src/main/ets/
    └── pages
        └── Index.ets (播放界面)
    entry/src/main/
    ├── cpp
    │   ├── types
    │   │   └── libentry
    │   │       └── Index.d.ts (NDK函数对应的js映射)
    │   ├── CMakeLists.txt (CMake脚本)
    │   └── napi_init.cpp  (NDK函数)
    └── resources
        ├── base
        │   ├── element
        │   │   ├── color.json
        │   │   ├── float.json
        │   │   └── string.json
        │   └── media
        │       ├── ic_video_play.svg  (播放键图片资源)
        │       └── ic_video_pause.svg (暂停键图片资源)
        └── rawfile
            └── test1.mp4 （视频资源）
    ```
2. 编译新建工程并运行。

## 开发示例

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
        case AV_IDLE: // 成功调用reset接口后触发该状态机上报
            LOG("AVPlayerState  AV_IDLE");
            break;
        case AV_INITIALIZED: {
            LOG("AVPlayerState  AV_INITIALIZED");
            auto context = SampleManager::GetInstance();
            ret = OH_AVPlayer_SetVideoSurface(player, context->nativeWindow_);
            LOG("OH_AVPlayer_SetVideoSurface ret:%{public}d", ret);
            ret = OH_AVPlayer_Prepare(player); // 设置播放源后触发该状态上报
            if (ret != AV_ERR_OK) {
                // 处理异常
                LOG("player  %{public}s", "OH_AVPlayer_Prepare Err");
            }
        } break;
        case AV_PREPARED:
            LOG("AVPlayerState AV_PREPARED");
            ret = OH_AVPlayer_SetAudioEffectMode(player, EFFECT_NONE); // 设置音频音效模式
            LOG("OH_AVPlayer_SetAudioEffectMode ret:%{public}d", ret);
            ret = OH_AVPlayer_Play(player); // 调用播放接口开始播放
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
    // 获取参数类型
    napi_valuetype stringType;
    if (napi_ok != napi_typeof(env, args[0], &stringType)) {
        // 处理异常
        LOG("参数异常");
        return nullptr;
    }
    // 参数校验
    if (napi_null == stringType) {
        // 处理异常
        LOG("参数异常 null");
        return nullptr;
    }
    // 获取传递的string长度
    size_t length = 0;
    if (napi_ok != napi_get_value_string_utf8(env, args[0], nullptr, 0, &length)) {
        // 处理异常
        LOG("参数长度异常");
        return nullptr;
    }
    // 如果传入的是""，则直接返回
    if (length == 0) {
        // 处理异常
        LOG("参数空字符");
        return nullptr;
    }
    // 读取传入的string放入buffer中
    char *url = new char[length + 1];
    if (napi_ok != napi_get_value_string_utf8(env, args[0], url, length + 1, &length)) {
        delete[] url;
        url = nullptr;
        // 处理异常
        LOG("url 异常");
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
    
    // 创建播放实例
    if(SampleManager::GetInstance()->player_) {
        OH_AVPlayer_Release(SampleManager::GetInstance()->player_);
    }
    OH_AVPlayer *player = OH_AVPlayer_Create();
    SampleManager::GetInstance()->SetAVPlayer(player);
    // 设置回调，监听信息
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
    // 设置音频流类型
    LOG("call %{public}s", "OH_AVPlayer_SetAudioRendererInfo");
    OH_AudioStream_Usage streamUsage = OH_AudioStream_Usage::AUDIOSTREAM_USAGE_UNKNOWN;
    ret = OH_AVPlayer_SetAudioRendererInfo(player, streamUsage);
    LOG("OH_AVPlayer_SetAudioRendererInfo ret:%{public}d", ret);
    // 设置音频流打断模式
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
        LOG("OH_AVPlayer_GetVideoHeight ret:%{public}d  videoHeight：%{public}d ", ret, videoHeight);
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
        LOG("OH_AVPlayer_GetVideoWidth ret:%{public}d  videoWidth：%{public}d ", ret, videoWidth);
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
