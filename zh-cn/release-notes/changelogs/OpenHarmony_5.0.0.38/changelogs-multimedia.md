# 媒体子系统Changelog

## cl.multimedia.1 OH_AVPlayerOnError 废弃AVPlayer NDK错误回调接口

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

可参考以下OH_AVPlayerOnErrorCallback的示例进行适配。
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
## cl.multimedia.2 OH_AVPlayerOnInfo 废弃AVPlayer NDK信息回调接口

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
示例可参考参见上述[OH_AVPlayerOnError 废弃AVPlayer NDK错误回调接口](#clmultimedia1-oh_avplayeronerror-废弃avplayer-ndk错误回调接口)的适配指导。

## cl.multimedia.3 AVPlayerCallback 废弃AVPlayer NDK AVPlayerCallback回调接口

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

使用新的 OH_AVPlayerOnInfoCallback和OH_AVPlayer_SetOnInfoCallback代替原来的信息回调。
示例可参考参见上述[OH_AVPlayerOnError 废弃AVPlayer NDK错误回调接口](#clmultimedia1-oh_avplayeronerror-废弃avplayer-ndk错误回调接口)的适配指导。

## cl.multimedia.4 OH_AVPlayer_SetPlayerCallback 废弃AVPlayer NDK OH_AVPlayer_SetPlayerCallback接口

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

使用新的 OH_AVPlayerOnInfoCallback和OH_AVPlayer_SetOnInfoCallback代替原来的信息回调。
示例可参考参见上述[OH_AVPlayerOnError 废弃AVPlayer NDK错误回调接口](#clmultimedia1-oh_avplayeronerror-废弃avplayer-ndk错误回调接口)的适配指导。

## cl.multimedia.5 ProfessionalPhotoSession.on/off 函数事件名称变更

**访问级别**

系统接口。

**变更原因**

变更事件名称，对齐HAMS规范要求。

**变更影响**

该变更为不兼容变更。  
若使用了  
on(type: 'isoInfo', callback: AsyncCallback\<IsoInfo>): void  
off(type: 'isoInfo', callback?: AsyncCallback\<IsoInfo>): void  
on(type: 'exposureInfo', callback: AsyncCallback\<ExposureInfo>): void  
off(type: 'exposureInfo', callback?: AsyncCallback\<ExposureInfo>): void  
on(type: 'apertureInfo', callback: AsyncCallback\<ApertureInfo>): void  
off(type: 'apertureInfo', callback?: AsyncCallback\<ApertureInfo>): void  
on(type: 'luminationInfo', callback: AsyncCallback\<LuminationInfo>): void  
off(type: 'luminationInfo', callback?: AsyncCallback\<LuminationInfo>): void  
事件监听，会在编译时报错。

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

|            接口声明            |               变更前                 |            变更后             |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| on(type: 'isoInfo', callback: AsyncCallback\<IsoInfo>): void | type: 'isoInfo' | type: 'isoInfoChange' |
| off(type: 'isoInfo', callback?: AsyncCallback\<IsoInfo>): void | type: 'isoInfo' | type: 'isoInfoChange' |
| on(type: 'exposureInfo', callback: AsyncCallback\<ExposureInfo>): void | type: 'exposureInfo' | type: 'exposureInfoChange' |
| off(type: 'exposureInfo', callback?: AsyncCallback\<ExposureInfo>): void | type: 'exposureInfo' | type: 'exposureInfoChange' |
| on(type: 'apertureInfo', callback: AsyncCallback\<ApertureInfo>): void | type: 'apertureInfo' | type: 'apertureInfoChange' |
| off(type: 'apertureInfo', callback?: AsyncCallback\<ApertureInfo>): void | type: 'apertureInfo' | type: 'apertureInfoChange' |
| on(type: 'luminationInfo', callback: AsyncCallback\<LuminationInfo>): void | type: 'luminationInfo' | type: 'luminationInfoChange' |
| off(type: 'luminationInfo', callback?: AsyncCallback\<LuminationInfo>): void | type: 'luminationInfo' | type: 'luminationInfoChange' |

**适配指导**

开发者需要修改type参数的值，适配新的事件名称 。

## cl.multimedia.6 ProfessionalVideoSession.on/off 函数事件名称变更

**访问级别**

系统接口。

**变更原因**

变更事件名称，对齐HAMS规范要求。

**变更影响**

该变更为不兼容变更。  
若使用了  
on(type: 'isoInfo', callback: AsyncCallback\<IsoInfo>): void  
off(type: 'isoInfo', callback?: AsyncCallback\<IsoInfo>): void  
on(type: 'exposureInfo', callback: AsyncCallback\<ExposureInfo>): void  
off(type: 'exposureInfo', callback?: AsyncCallback\<ExposureInfo>): void  
on(type: 'apertureInfo', callback: AsyncCallback\<ApertureInfo>): void  
off(type: 'apertureInfo', callback?: AsyncCallback\<ApertureInfo>): void  
on(type: 'luminationInfo', callback: AsyncCallback\<LuminationInfo>): void  
off(type: 'luminationInfo', callback?: AsyncCallback\<LuminationInfo>): void  
事件监听，会在编译时报错。

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

|            接口声明            |               变更前                 |            变更后             |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| on(type: 'isoInfo', callback: AsyncCallback\<IsoInfo>): void | type: 'isoInfo' | type: 'isoInfoChange' |
| off(type: 'isoInfo', callback?: AsyncCallback\<IsoInfo>): void | type: 'isoInfo' | type: 'isoInfoChange' |
| on(type: 'exposureInfo', callback: AsyncCallback\<ExposureInfo>): void | type: 'exposureInfo' | type: 'exposureInfoChange' |
| off(type: 'exposureInfo', callback?: AsyncCallback\<ExposureInfo>): void | type: 'exposureInfo' | type: 'exposureInfoChange' |
| on(type: 'apertureInfo', callback: AsyncCallback\<ApertureInfo>): void | type: 'apertureInfo' | type: 'apertureInfoChange' |
| off(type: 'apertureInfo', callback?: AsyncCallback\<ApertureInfo>): void | type: 'apertureInfo' | type: 'apertureInfoChange' |
| on(type: 'luminationInfo', callback: AsyncCallback\<LuminationInfo>): void | type: 'luminationInfo' | type: 'luminationInfoChange' |
| off(type: 'luminationInfo', callback?: AsyncCallback\<LuminationInfo>): void | type: 'luminationInfo' | type: 'luminationInfoChange' |

**适配指导**

开发者需要修改type参数的值，适配新的事件名称 。