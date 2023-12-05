# 使用AVPlayer开发音频播放功能(C/C++)

使用AVPlayer可以实现端到端播放原始媒体资源，本开发指导将以完整地播放一首音乐作为示例，向开发者讲解AVPlayer音频播放相关功能。


播放的全流程包含：创建AVPlayer，设置播放资源，设置播放参数（音量/倍速/焦点模式），播放控制（播放/暂停/跳转/停止），重置，销毁资源。


在进行应用开发的过程中，开发者可以通过AVPlayer的callback主动获取播放过程信息。如果应用在音频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。


**图1** 播放状态变化示意图  
![Playback status change](figures/playback-status-change-ndk.png)

状态的详细说明请参考[AVPlayerState]。当播放处于prepared / playing / paused / completed状态时，播放引擎处于工作状态，这需要占用系统较多的运行内存。当客户端暂时不使用播放器时，调用reset()或release()回收内存资源，做好资源利用。

## 开发步骤及注意事项
在 CMake 脚本中链接动态库
```
target_link_libraries(sample PUBLIC libavplayer.so)
```

开发者通过引入[avplayer.h],[avpalyer_base.h]和[native_averrors.h](../reference/native-apis/native__averrors_8h.md)头文件，使用音频录制相关API。
详细的API说明请参考[AVPlayer API]。

1. 创建实例OH_AVPlayer_Create()，AVPlayer初始化idle状态。

2. 设置业务需要的监听事件OH_AVPlayer_SetPlayerCallback()，搭配全流程场景使用。支持的监听事件包括：
   | 事件类型 | 说明 |
   | -------- | -------- |
   | OH_AVPlayerOnInfo | 必要事件，监听播放器的过程信息。 |
   | OH_AVPlayerOnError | 必要事件，监听播放器的错误信息。 |

3. 设置资源：调用OH_AVPlayer_SetURLSource(),设置属性url，AVPlayer进入initialized状态。

4. 准备播放：调用OH_AVPlayer_Prepare()，AVPlayer进入prepared状态，此时可以获取时长，设置音量。

5. 音频播控：播放OH_AVPlayer_Play()，暂停OH_AVPlayer_Pause()，跳转OH_AVPlayer_Seek()，停止OH_AVPlayer_Stop() 等操作。

6. （可选）更换资源：调用OH_AVPlayer_Reset()重置资源，AVPlayer重新进入idle状态，允许更换资源url。

7. 退出播放：调用OH_AVPlayer_Release()销毁实例，AVPlayer进入released状态，退出播放。

## 示例
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
    // 创建播放实例
    OH_AVPlayer *player = OH_AVPlayer_Create();
    AVPlayerCallback callback;
    callback.onInfo = OnInfo;
    callback.onError = OnError;
    // 设置回调，监听信息
    int32_t ret = OH_AVPlayer_SetPlayerCallback(player, callback);
    if (ret != AV_ERR_OK) {
    // 处理异常
    }
    const char *path = "/data/test/mp3_48000Hz_64kbs_mono.mp3";
    // 设置url资源
    int32_t ret = OH_AVPlayer_SetURLSource(player, path);
    if (ret != AV_ERR_OK) {
    // 处理异常
    }
    // 准备资源
    int32_t ret = OH_AVPlayer_Prepare(player);
    if (ret != AV_ERR_OK) {
    // 处理异常
    }
    // 播放资源
    int32_t ret = OH_AVPlayer_Play(player);
    if (ret != AV_ERR_OK) {
    // 处理异常
    }
    // 停止播放
    int32_t ret = OH_AVPlayer_Stop(player);
    if (ret != AV_ERR_OK) {
    // 处理异常
    }
    // 释放资源
    int32_t ret = OH_AVPlayer_Release(player);
    if (ret != AV_ERR_OK) {
    // 处理异常
    }
}
```