# Media Subsystem Changelog

## cl.multimedia.1 OH_AVPlayerOnError Deprecated

**Access Level**

Public API

**Reason for Change**

The NDK interface is optimized, and the **userData** parameter is added to the callback.

**Change Impact**

This change is a non-compatible change.

Before change: Applications call **OH_AVPlayerOnError** to receive errors through a callback.

After change: Applications call **OH_AVPlayerOnErrorCallback** to receive errors through a callback.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.38

**Adaptation Guide**

Refer to the following example of **OH_AVPlayerOnErrorCallback** for adaptation.
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
## cl.multimedia.2 OH_AVPlayerOnInfo Deprecated

**Access Level**

Public API

**Reason for Change**

The original callback can pass only **extra** of the int32_t type. Some information, such as the width, height, and available bit rate array, cannot be reported. A new callback is introduced to report **infoBody** of the OH_AVFormat type. More information now can be passed.

**Change Impact**

This change is a non-compatible change.

Before change: Applications call **OH_AVPlayerOnInfo** to receive information through a callback.

After change: Applications call **OH_AVPlayerOnInfoCallback** to receive information through a callback.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.38

**Adaptation Guide**

Use **OH_AVPlayerOnInfoCallback** and **OH_AVPlayer_SetOnInfoCallback** to replace the original information callback.

For details about the sample code, see **Adaptation Guide** in [OH_AVPlayerOnError Deprecated](#clmultimedia1-oh_avplayeronerror-deprecated).

## cl.multimedia.3 AVPlayerCallback Deprecated

**Access Level**

Public API

**Reason for Change**

For **AVPlayerCallback**, its two members (**OH_AVPlayerOnInfo** and **OH_AVPlayerOnError**) are deprecated. Therefore, **AVPlayerCallback** is no longer needed.

**Change Impact**

This change is a non-compatible change.

Before change: Applications use **OH_AVPlayerOnInfo**, **OH_AVPlayerOnError**, **AVPlayerCallback**, and **OH_AVPlayer_SetPlayerCallback** to receive information and errors through callbacks.

After change: Applications use **OH_AVPlayerOnInfoCallback**, **OH_AVPlayerOnErrorCallback**, **OH_AVPlayer_SetOnInfoCallback**, and **OH_AVPlayer_SetOnErrorCallback** to receive information and errors through callbacks.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.38

**Adaptation Guide**

Use **OH_AVPlayerOnInfoCallback** and **OH_AVPlayer_SetOnInfoCallback** to replace the original information callbacks.

For details about the sample code, see **Adaptation Guide** in [OH_AVPlayerOnError Deprecated](#clmultimedia1-oh_avplayeronerror-deprecated).

## cl.multimedia.4 OH_AVPlayer_SetPlayerCallback Deprecated

**Access Level**

Public API

**Reason for Change**

The original callback can pass only **extra** of the int32_t type. Some information, such as the width, height, and available bit rate array, cannot be reported. A new callback is introduced to report **infoBody** of the OH_AVFormat type. More information now can be passed.

**OH_AVPlayerOnInfo**, **OH_AVPlayerOnError**, and **AVPlayerCallback** are deprecated, and therefore **OH_AVPlayer_SetPlayerCallback** is no longer needed.

**Change Impact**

This change is a non-compatible change.

Before change: Applications use **OH_AVPlayerOnInfo**, **OH_AVPlayerOnError**, **AVPlayerCallback**, and **OH_AVPlayer_SetPlayerCallback** to receive information and errors.

After change: Applications use **OH_AVPlayerOnInfoCallback**, **OH_AVPlayerOnErrorCallback**, **OH_AVPlayer_SetOnInfoCallback**, and **OH_AVPlayer_SetOnErrorCallback** to receive information and errors.

**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.38

**Adaptation Guide**

Use **OH_AVPlayerOnInfoCallback** and **OH_AVPlayer_SetOnInfoCallback** to replace the original information callbacks.

For details about the sample code, see **Adaptation Guide** in [OH_AVPlayerOnError Deprecated](#clmultimedia1-oh_avplayeronerror-deprecated).

## cl.multimedia.5 Event Names in ProfessionalPhotoSession.on/off Changed

**Access Level**

System API

**Reason for Change**

The event names are changed to comply with the HAMS specifications.

**Change Impact**

This change is a non-compatible change. 

If any of the following event listeners is used in the code, an error is reported during compilation: 

on(type: 'isoInfo', callback: AsyncCallback\<IsoInfo>): void  
off(type: 'isoInfo', callback?: AsyncCallback\<IsoInfo>): void  
on(type: 'exposureInfo', callback: AsyncCallback\<ExposureInfo>): void  
off(type: 'exposureInfo', callback?: AsyncCallback\<ExposureInfo>): void  
on(type: 'apertureInfo', callback: AsyncCallback\<ApertureInfo>): void  
off(type: 'apertureInfo', callback?: AsyncCallback\<ApertureInfo>): void  
on(type: 'luminationInfo', callback: AsyncCallback\<LuminationInfo>): void  
off(type: 'luminationInfo', callback?: AsyncCallback\<LuminationInfo>): void  


**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.38

**Key API/Component Changes**

|            API           |               Before Change                |            After Change            |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| on(type: 'isoInfo', callback: AsyncCallback\<IsoInfo>): void | type: 'isoInfo' | type: 'isoInfoChange' |
| off(type: 'isoInfo', callback?: AsyncCallback\<IsoInfo>): void | type: 'isoInfo' | type: 'isoInfoChange' |
| on(type: 'exposureInfo', callback: AsyncCallback\<ExposureInfo>): void | type: 'exposureInfo' | type: 'exposureInfoChange' |
| off(type: 'exposureInfo', callback?: AsyncCallback\<ExposureInfo>): void | type: 'exposureInfo' | type: 'exposureInfoChange' |
| on(type: 'apertureInfo', callback: AsyncCallback\<ApertureInfo>): void | type: 'apertureInfo' | type: 'apertureInfoChange' |
| off(type: 'apertureInfo', callback?: AsyncCallback\<ApertureInfo>): void | type: 'apertureInfo' | type: 'apertureInfoChange' |
| on(type: 'luminationInfo', callback: AsyncCallback\<LuminationInfo>): void | type: 'luminationInfo' | type: 'luminationInfoChange' |
| off(type: 'luminationInfo', callback?: AsyncCallback\<LuminationInfo>): void | type: 'luminationInfo' | type: 'luminationInfoChange' |

**Adaptation Guide**

Change the value of the **type** parameter to adapt to the new event names.

## cl.multimedia.6 Event Names in ProfessionalVideoSession.on/off Changed

**Access Level**

System API

**Reason for Change**

The event names are changed to comply with the HAMS specifications.

**Change Impact**

This change is a non-compatible change.

If any of the following event listeners is used in the code, an error is reported during compilation:

on(type: 'isoInfo', callback: AsyncCallback\<IsoInfo>): void  
off(type: 'isoInfo', callback?: AsyncCallback\<IsoInfo>): void  
on(type: 'exposureInfo', callback: AsyncCallback\<ExposureInfo>): void  
off(type: 'exposureInfo', callback?: AsyncCallback\<ExposureInfo>): void  
on(type: 'apertureInfo', callback: AsyncCallback\<ApertureInfo>): void  
off(type: 'apertureInfo', callback?: AsyncCallback\<ApertureInfo>): void  
on(type: 'luminationInfo', callback: AsyncCallback\<LuminationInfo>): void  
off(type: 'luminationInfo', callback?: AsyncCallback\<LuminationInfo>): void  


**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.38

**Key API/Component Changes**

|            API           |               Before Change                |            After Change            |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| on(type: 'isoInfo', callback: AsyncCallback\<IsoInfo>): void | type: 'isoInfo' | type: 'isoInfoChange' |
| off(type: 'isoInfo', callback?: AsyncCallback\<IsoInfo>): void | type: 'isoInfo' | type: 'isoInfoChange' |
| on(type: 'exposureInfo', callback: AsyncCallback\<ExposureInfo>): void | type: 'exposureInfo' | type: 'exposureInfoChange' |
| off(type: 'exposureInfo', callback?: AsyncCallback\<ExposureInfo>): void | type: 'exposureInfo' | type: 'exposureInfoChange' |
| on(type: 'apertureInfo', callback: AsyncCallback\<ApertureInfo>): void | type: 'apertureInfo' | type: 'apertureInfoChange' |
| off(type: 'apertureInfo', callback?: AsyncCallback\<ApertureInfo>): void | type: 'apertureInfo' | type: 'apertureInfoChange' |
| on(type: 'luminationInfo', callback: AsyncCallback\<LuminationInfo>): void | type: 'luminationInfo' | type: 'luminationInfoChange' |
| off(type: 'luminationInfo', callback?: AsyncCallback\<LuminationInfo>): void | type: 'luminationInfo' | type: 'luminationInfoChange' |

**Adaptation Guide**

Change the value of the **type** parameter to adapt to the new event names.
