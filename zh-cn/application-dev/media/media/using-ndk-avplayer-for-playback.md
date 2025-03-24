# 使用AVPlayer播放音频(C/C++)

使用[AVPlayer](media-kit-intro.md#avplayer)可以实现端到端播放原始媒体资源，本开发指导将以完整地播放一首音乐作为示例，向开发者讲解AVPlayer音频播放相关功能。


播放的全流程包含：创建AVPlayer，设置回调监听函数，设置播放资源，设置播放参数（音量/倍速/焦点模式），播放控制（播放/暂停/跳转/停止），重置，销毁播放器实例。


在进行应用开发的过程中，开发者可以通过AVPlayer的信息监听回调函数[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfocallback)和错误监听回调函数[OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerrorcallback)主动获取播放过程信息。如果应用在音频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。


**图1** 播放状态变化示意图  
![Playback status change](figures/playback-status-change-ndk.png)

状态的详细说明请参考[AVPlayerState](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1)。当播放处于prepared / playing / paused / completed状态时，播放引擎处于工作状态，这需要占用系统较多的运行内存。当客户端暂时不使用播放器时，调用reset()或release()回收内存资源，做好资源利用。

## 开发建议

当前指导仅介绍如何实现媒体资源播放，在应用开发过程中可能会涉及后台播放、播放冲突等情况，请根据实际需要参考以下说明。

- 如果要实现后台播放或熄屏播放，需要接入[AVSession（媒体会话）](../avsession/avsession-access-scene.md)和[申请长时任务](../../task-management/continuous-task.md)，避免播放被系统强制中断。此功能仅提供ArkTS API。
- 应用在播放过程中，若播放的媒体数据涉及音频，根据系统音频管理策略（参考[处理音频焦点事件](../audio/audio-playback-concurrency.md)），可能会被其他应用打断，建议通过[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback)主动监听音频打断事件[AV_INFO_TYPE_INTERRUPT_EVENT](../../reference/apis-media-kit/_a_v_player.md#avplayeroninfotype-1)，根据其内容提示，做出相应的处理，避免出现应用状态与预期效果不一致的问题。
- 面对设备同时连接多个音频输出设备的情况，建议通过[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback)主动监听音频输出设备改变事件[AV_INFO_TYPE_AUDIO_OUTPUT_DEVICE_CHANGE](../../reference/apis-media-kit/_a_v_player.md#avplayeroninfotype-1)，从而做出相应处理。
- 应用在播放过程中，系统内部可能异常，如网络数据下载失败、媒体服务死亡不可用等，建议通过[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback)接口设置错误监听回调函数，根据不同错误类型，做出相应处理，避免出现播放异常。
- 使用[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback)接口分别设置信息监听回调函数[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfocallback)和错误监听回调函数[OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerrorcallback)。当应用成功设置信息监听回调函数[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfocallback)后，不再执行通过[OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setplayercallback)设置的信息监听回调函数[OH_AVPlayerOnInfo](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfo)；当应用成功设置错误监听回调函数[OH_AVPlayerOnErrorCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerrorcallback)后，不再执行通过[OH_AVPlayer_SetPlayerCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setplayercallback)设置的错误监听回调函数[OH_AVPlayerOnError](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeronerror)。

## 开发步骤及注意事项
在 CMake 脚本中链接动态库：
```
target_link_libraries(sample PUBLIC libavplayer.so)
```

使用[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback)接口设置信息监听回调函数和错误监听回调函数，需要在 CMake 脚本中链接如下动态库：
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

开发者通过引入[avplayer.h](../../reference/apis-media-kit/avplayer_8h.md)、[avpalyer_base.h](../../reference/apis-media-kit/avplayer__base_8h.md)和[native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md)头文件，使用音频播放相关API。
详细的API说明请参考[AVPlayer API](../../reference/apis-media-kit/_a_v_player.md)。

1. 创建AVPlayer实例：调用[OH_AVPlayer_Create()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_create)，AVPlayer初始化为[AV_IDLE](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1)状态。

2. 设置回调监听函数：使用[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback)接口设置信息监听回调函数和错误监听回调函数，搭配全流程场景使用。支持的监听事件包括：
   | 事件类型 | 说明 |
   | -------- | -------- |
   | OH_AVPlayerOnInfoCallback | 必要事件，监听播放器的过程信息。 |
   | OH_AVPlayerOnErrorCallback | 必要事件，监听播放器的错误信息。 |

    应用使用[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback)、[OH_AVPlayer_SetOnErrorCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setonerrorcallback)接口设置信息监听回调函数和错误监听回调函数，可以获取更多信息，还可以通过设置 userData 区分不同播放实例。

3. 设置资源：调用[OH_AVPlayer_SetURLSource()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_seturlsource)，设置属性url，AVPlayer进入[AV_INITIALIZED](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1)状态。

4. （可选）设置音频流类型：调用[OH_AVPlayer_SetAudioRendererInfo()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setaudiorendererinfo)，设置AVPlayer音频流类型。

5. （可选）设置音频打断模式：调用[OH_AVPlayer_SetAudioInterruptMode()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setaudiointerruptmode)，设置AVPlayer音频流打断模式。

6. 准备播放：调用[OH_AVPlayer_Prepare()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_prepare)，AVPlayer进入[AV_PREPARED](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1)状态，此时可以获取时长，设置音量。

7. （可选）设置音频音效模式：调用[OH_AVPlayer_SetAudioEffectMode()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setaudioeffectmode)，设置AVPlayer音频音效模式。

8. 音频播控：播放[OH_AVPlayer_Play()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_play)，暂停[OH_AVPlayer_Pause()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_pause)，跳转[OH_AVPlayer_Seek()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_seek)，停止[OH_AVPlayer_Stop()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_stop)等操作。

9. （可选）更换资源：调用[OH_AVPlayer_Reset()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_reset)重置资源，AVPlayer重新进入[AV_IDLE](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1)状态，允许更换资源url。

10. 退出播放：调用[OH_AVPlayer_Release()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_release)销毁实例，AVPlayer进入[AV_RELEASED](../../reference/apis-media-kit/_a_v_player.md#avplayerstate-1)状态，退出播放。之后再操作AVPlayer实例则行为未知，可能导致应用进程崩溃，应用闪退。

## 完整示例

```c
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

    AVPlayerBufferingType bufferType = AVPLAYER_BUFFERING_START;
    int32_t bufferValue = -1;

    uint32_t *bitRates = nullptr;
    size_t bitRatesSize = 0;
    uint32_t bitRate = 0;

    int32_t interruptType = -1;
    int32_t interruptForce = -1;
    int32_t interruptHint = -1;
} DemoNdkPlayer;

void HandleStateChange(OH_AVPlayer *player, AVPlayerState state) {
    int32_t ret;
    switch (state) {
        case AV_IDLE: // 成功调用reset接口后触发该状态机上报
//            ret = OH_AVPlayer_SetURLSource(player, url); // 设置url
//            if (ret != AV_ERR_OK) {
//            // 处理异常
//        }
            break;
        case AV_INITIALIZED:
            ret = OH_AVPlayer_Prepare(player); //设置播放源后触发该状态上报
            if (ret != AV_ERR_OK) {
            // 处理异常
            }
            break;
        case AV_PREPARED:
//            ret = OH_AVPlayer_SetAudioEffectMode(player, EFFECT_NONE); // 设置音频音效模式
//            if (ret != AV_ERR_OK) {
//            //处理异常    
//            }  
            ret = OH_AVPlayer_Play(player); // 调用播放接口开始播放
            if (ret != AV_ERR_OK) {
            // 处理异常
            }
            break;
        case AV_PLAYING:
//            ret = OH_AVPlayer_Pause(player); //调用暂停接口暂停播放
//            if (ret != AV_ERR_OK) {
//            // 处理异常
//            }
            break;
        case AV_PAUSED:
//            ret = OH_AVPlayer_Play(player); // 再次播放接口开始播放
//            if (ret != AV_ERR_OK) {
//            // 处理异常
//            }
           break;
        case AV_STOPPED:
            ret = OH_AVPlayer_Release(player); //调用reset接口初始化avplayer状态
            if (ret != AV_ERR_OK) {
            // 处理异常
            }
            break;
        case AV_COMPLETED:
            ret = OH_AVPlayer_Stop(player);// 调用播放结束接口
            if (ret != AV_ERR_OK) {
            // 处理异常
            }
            break;
        default:
            break;
    }
}

void OHAVPlayerOnInfoCallback(OH_AVPlayer *player, AVPlayerOnInfoType type, OH_AVFormat *infoBody, void *userData) {
    int32_t ret;
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
        // 目前OH_AVFormat仅支持存储不支持存储uint32_t类型、自定义类型枚举数据
        // 需要通过int32_t类型数据获取，然后强转为对应类型数据。
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

// 调用播放方法时，需要在index.d.ts文件内描述映射的play方法，需要传入一个string类型的参数
// ets文件调用播放方法时，传入文件路径 testNapi.play("/data/test/test.mp3")
static napi_value Play(napi_env env, napi_callback_info info)
{
    int32_t ret = -1;
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    
    // 获取参数类型
    napi_valuetype stringType;
    if (napi_ok != napi_typeof(env, args[0], &stringType)) {
        // 处理异常
        return nullptr;
    }
    
    // 参数校验
    if (napi_null == stringType) {
        // 处理异常
        return nullptr;
    }
    
    // 获取传递的string长度
    size_t length = 0;
    if (napi_ok != napi_get_value_string_utf8(env, args[0], nullptr, 0, &length)) {
        // 处理异常
        return nullptr;
    }
    
    // 如果传入的是""，则直接返回
    if (length == 0) {
        // 处理异常
        return nullptr;
    }
    
    // 读取传入的string放入buffer中
    char *url = new char[length + 1];
    if (napi_ok != napi_get_value_string_utf8(env, args[0], url, length + 1, &length)) {
        delete[] url;
        url = nullptr;
        // 处理异常
        return nullptr;
    }

    // 通过新接口设置信息监听回调函数和错误监听回调函数，不用再调用OH_AVPlayer_SetPlayerCallback。
    // 业务播放实例不再使用后，再释放对象。
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
    // 处理异常
    }
    ret = OH_AVPlayer_SetURLSource(player, url); // 设置url
    if (ret != AV_ERR_OK) {
    // 处理异常
    }
    // 设置音频流类型
    OH_AudioStream_Usage streamUsage = OH_AudioStream_Usage::AUDIOSTREAM_USAGE_UNKNOWN;
    ret = OH_AVPlayer_SetAudioRendererInfo(player, streamUsage);
    if (ret != AV_ERR_OK) {
    //处理异常    
    }
    // 设置音频流打断模式
    OH_AudioInterrupt_Mode interruptMode = OH_AudioInterrupt_Mode::AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT;
    ret = OH_AVPlayer_SetAudioInterruptMode(player, interruptMode);
    if (ret != AV_ERR_OK) {
    //处理异常    
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