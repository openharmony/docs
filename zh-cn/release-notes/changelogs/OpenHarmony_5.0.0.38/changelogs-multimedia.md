# 媒体子系统Changelog

## cl.multimedia.1 AVMetadata.hdrType 只读属性补齐

**访问级别**

公开接口。

**变更原因**

补充标记hdrType字段为readonly属性，对齐JsDoc描述。

**变更影响**

该变更为不兼容变更。
若对AVMetadata.hdrType进行过赋值的代码，会在编译时报错。之前的版本虽然赋值成功，但无法生效。建议删除赋值的代码。

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

|            接口声明            |               变更前                 |            变更后             |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| hdrType | 可赋值，不生效 | readonly, 不可赋值 |

**适配指导**

开发者需将使用@ohos.multimedia.media.d.ts模块中对AVMetadata.hdrType赋值的代码行删除。

## cl.multimedia.2 OH_AVPlayerOnError 废弃AVPlayer NDK错误回调接口

**访问级别**

公开接口。

**变更原因**

优化ndk接口，回调增加userData参数。

**变更影响**

该变更为不兼容变更。

变更前：应用使用OH_AVPlayerOnError接收错误信息回调。

变更后：应用使用OH_AVPlayerOnErrorCallback接收错误信息回调。

**起始 API Level**

11

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**适配指导**

下面是使用新的 OH_AVPlayerOnErrorCallback 的Sample代码.
```
struct MyPlayer 
{
    const char* url;
    int32_t errorCode;
}

void PlayerErrorCallback(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg, void *userData)
{
    MyPlayer* myPlayer = (MyPlayer*)userData;
    myPlayer->errorCode = errorCode;
}

void PlayerInfoCallback(OH_AVPlayer *player, AVPlayerOnInfoType type, OH_AVFormat* infoBody, void *userData)
{
    if (type == AV_INFO_TYPE_STATE_CHANGE) {
        int32_t state, reason;
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_STATE, &state);
        OH_AVFormat_GetIntValue(infoBody, OH_PLAYER_STATE_CHANGED_REASON, &reason);
        // use state reason
    }
}

int main()
{
    MyPlayer myPlayer;
    myPlayer.url = "http://localhost/test.mp4";
    OH_AVPlayer* player = OH_AVPlayer_Create();
    OH_AVPlayer_SetOnErrorCallback(player, PlayerErrorCallback, &myPlayer);
    OH_AVPlayer_SetOnInfoCallback(player, PlayerInfoCallback, &myPlayer);
    OH_AVPlayer_SetURLSource(player, myPlayer.url);
    OH_AVPlayer_Prepare(player);
    OH_AVPlayer_Play(player);
    Sleep(10000);
    OH_AVPlayer_Stop(player);
    OH_AVPlayer_Release(player);
}

```
## cl.multimedia.3 OH_AVPlayerOnInfo 废弃AVPlayer NDK信息回调接口

**访问级别**

公开接口。

**变更原因**

原来的回调接口，只能传递int32_t类型的extra额外信息，有些信息无法上报，比如宽高，可用的bitrate数组等。因此增加新的回调接口，上报OH_AVFormat类型的infoBody，可传递更多信息。

**变更影响**

该变更为不兼容变更。

变更前：应用使用OH_AVPlayerOnInfo接收信息回调。

变更后：应用使用OH_AVPlayerOnInfoCallback接收信息回调。

**起始 API Level**

11

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**适配指导**

使用新的 OH_AVPlayerOnInfoCallback和OH_AVPlayer_SetOnInfoCallback代替原来的信息回调。
Sample代码参见前面 OH_AVPlayerOnErrorCallback 的Sample代码。

## cl.multimedia.4 AVPlayerCallback 废弃AVPlayer NDK AVPlayerCallback回调接口

**访问级别**

公开接口。

**变更原因**

AVPlayerCallback 结果的两个成员OH_AVPlayerOnInfo、OH_AVPlayerOnError废弃，它也不需要了。

**变更影响**

该变更为不兼容变更。

变更前：应用使用OH_AVPlayerOnInfo、OH_AVPlayerOnError、AVPlayerCallback、OH_AVPlayer_SetPlayerCallback接收信息和错误回调。

变更后：应用使用OH_AVPlayerOnInfoCallback、OH_AVPlayerOnErrorCallback,OH_AVPlayer_SetOnInfoCallback，OH_AVPlayer_SetOnErrorCallback接收信息和错误回调。

**起始 API Level**

11

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**适配指导**

使用新的 OH_AVPlayerOnInfoCallback，OH_AVPlayerOnErrorCallback和OH_AVPlayer_SetOnInfoCallback,OH_AVPlayer_SetOnErrorCallback代替原来的信息和错误回调。
Sample代码参见前面 OH_AVPlayerOnErrorCallback 的Sample代码。

## cl.multimedia.5 OH_AVPlayer_SetPlayerCallback 废弃AVPlayer NDK OH_AVPlayer_SetPlayerCallback接口

**访问级别**

公开接口。

**变更原因**

原来的回调接口，只能传递int32_t类型的extra额外信息，有些信息无法上报，比如宽高，可用的bitrate数组等。因此增加新的回调接口，上报OH_AVFormat类型的infoBody，可传递更多信息。
老的接口 OH_AVPlayerOnInfo、OH_AVPlayerOnError、AVPlayerCallback已废弃，OH_AVPlayer_SetPlayerCallback也不再需要了。

**变更影响**

该变更为不兼容变更。

变更前：应用使用OH_AVPlayerOnInfo、OH_AVPlayerOnError、AVPlayerCallback、OH_AVPlayer_SetPlayerCallback接收信息和错误回调。

变更后：应用使用OH_AVPlayerOnInfoCallback、OH_AVPlayerOnErrorCallback,OH_AVPlayer_SetOnInfoCallback，OH_AVPlayer_SetOnErrorCallback接收信息和错误回调。

**起始 API Level**

11

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**适配指导**

使用新的 OH_AVPlayerOnInfoCallback，OH_AVPlayerOnErrorCallback和OH_AVPlayer_SetOnInfoCallback,OH_AVPlayer_SetOnErrorCallback代替原来的信息和错误回调。
Sample代码参见前面 OH_AVPlayerOnErrorCallback 的Sample代码。
