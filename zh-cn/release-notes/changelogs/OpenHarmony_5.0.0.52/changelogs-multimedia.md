# multimedia子系统变更说明

## cl.multimedia.1 	AVErrorCode枚举值变更

**访问级别**

公开接口

**变更原因**

播放器当前上报的IO错误码只有一个，导致应用在故障时难以进行问题定界，本次细化了IO相关错误，提升生态应用友好度。

**变更影响**

该变更为不兼容变更。
变更前：应用使用到该接口时，API version 13及以下上报规则保持不变，涉及到IO返回错误的接口返回原有的值。
变更后：播放框架返回IO类网络错误时，对应的错误码会细化，涉及到IO返回错误的接口返回值会有变化，用户升级到API version 14需要适配新的错误码上报规则。
|                       接口声明                        |           API13及以下            |           API14及以上         |
| :--------------------------------------------------: | :------------------------------: | :---------------------------: |
| AVPlayer.on(type: 'error', callback: ErrorCallback)  |        AVERR_IO = 5400103        |     新增返回5411001 ~ 5411011     |
| void (*OH_AVPlayerOnErrorCallback)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg) |        AV_ERR_IO = 4        |     新增返回5411001 ~ 5411011     |

**起始 API Level**

9

**变更发生的版本**

从OpenHarmony SDK 5.0.0.48开始。

**变更的接口/组件**

1. [@ohos.multimedia.media.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.multimedia.media.d.ts)中接口：
AVPlayer.on(type: 'error', callback: ErrorCallback)。

2. [avplayer_base.h](https://gitee.com/openharmony/interface_sdk_c/blob/master/multimedia/player_framework/avplayer_base.h)中接口：
void (*OH_AVPlayerOnErrorCallback)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg)。

**适配指导**

新API版本中，应用监听IO相关错误时，需新增5411001 ~ 5411011内的错误码监听。

参考[Media错误码说明文档](../../../application-dev/reference/apis-media-kit/errorcode-media.md)。