# Multimedia Subsystem Changelog

## cl.multimedia.1 	AVErrorCode Enumerated Value Changed

**Access Level**

Public API

**Reason for Change**

The player reports only one IO error code. To help developers better understand the cause of the playback failure, IO-related errors are refined.

**Change Impact**

This change is a non-compatible change.

Before change: The application maintains the same rule for reporting error codes when using the involved APIs, and any API that encounters IO errors will return the values they originally had.

After change: Upon encountering IO-related network errors, the playback framework provides more detailed error codes. As a result, the return values for APIs that encounter IO errors will differ, and you need to adapt to the new error code reporting rules.
|                       API                       |           Before Change           |           After Change        |
| :--------------------------------------------------: | :------------------------------: | :---------------------------: |
| AVPlayer.on(type: 'error', callback: ErrorCallback)  |        AVERR_IO = 5400103        |     In the network scenario, the original error code is deprecated, and the error codes 5411001 to 5411011 are used. The error codes in other scenarios remain unchanged.    |
| void (*OH_AVPlayerOnErrorCallback)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg) |        AV_ERR_IO = 4        |     In the network scenario, the original error code is deprecated, and the error codes 5411001 to 5411011 are used. The error codes in other scenarios remain unchanged.     |

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.52

**Key API/Component Changes**

1. API in [@ohos.multimedia.media.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.multimedia.media.d.ts):
AVPlayer.on(type: 'error', callback: ErrorCallback)

2. API in [avplayer_base.h](https://gitee.com/openharmony/interface_sdk_c/blob/master/multimedia/player_framework/avplayer_base.h):
void (*OH_AVPlayerOnErrorCallback)(OH_AVPlayer *player, int32_t errorCode, const char *errorMsg)

**Adaptation Guide**

Add error codes 5411001 to 5411011 in your code to listen for IO-related errors.

For details, see [Media Error Codes](../../../application-dev/reference/apis-media-kit/errorcode-media.md).
