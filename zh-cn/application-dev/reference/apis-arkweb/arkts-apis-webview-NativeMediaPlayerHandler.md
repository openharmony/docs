# Interface (NativeMediaPlayerHandler)

[CreateNativeMediaPlayerCallback](./arkts-apis-webview-t.md#createnativemediaplayercallback12) 回调函数的参数。
应用通过该对象，将播放器的状态报告给ArkWeb内核。

> **说明：**
>
> - 本模块接口从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## handleStatusChanged<sup>12+<sup>

handleStatusChanged(status: PlaybackStatus): void

当播放器的播放状态发生变化时，调用该方法将播放状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| status | [PlaybackStatus](./arkts-apis-webview-e.md#playbackstatus12) | 是 | 播放器的播放状态。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleVolumeChanged<sup>12+<sup>

handleVolumeChanged(volume: number): void

当播放器的音量发生变化时，调用该方法将音量通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| volume | number | 是 | 播放器的音量。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleMutedChanged<sup>12+<sup>

handleMutedChanged(muted: boolean): void

当播放器的静音状态发生变化时，调用该方法将静音状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| muted | boolean | 是 | 当前播放器是否静音。<br>true表示当前播放器静音，false表示当前播放器未静音。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handlePlaybackRateChanged<sup>12+<sup>

handlePlaybackRateChanged(playbackRate: number): void

当播放器的播放速度发生变化时，调用该方法将播放速度通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| playbackRate | number | 是 | 播放速率。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleDurationChanged<sup>12+<sup>

handleDurationChanged(duration: number): void

当播放器解析出媒体的总时长时，调用该方法将媒体的总时长通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| duration | number | 是 | 媒体的总时长。<br>单位：秒。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleTimeUpdate<sup>12+<sup>

handleTimeUpdate(currentPlayTime: number): void

当媒体的播放进度发生变化时，调用该方法将媒体的播放进度通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| currentPlayTime | number | 是 | 当前播放时间。单位： 秒。  |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleBufferedEndTimeChanged<sup>12+<sup>

handleBufferedEndTimeChanged(bufferedEndTime: number): void

当媒体的缓冲时长发生变化时，调用该方法将媒体的缓冲时长通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| bufferedEndTime | number | 是 | 媒体缓冲的时长。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleEnded<sup>12+<sup>

handleEnded(): void

当媒体播放结束时，调用该方法通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleNetworkStateChanged<sup>12+<sup>

handleNetworkStateChanged(state: NetworkState): void

当播放器的网络状态发生变化时，调用该方法将播放器的网络状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| state | [NetworkState](./arkts-apis-webview-e.md#networkstate12) | 是 | 播放器的网络状态。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleReadyStateChanged<sup>12+<sup>

handleReadyStateChanged(state: ReadyState): void

当播放器的缓存状态发生变化时，调用该方法将播放器的缓存状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| state | [ReadyState](./arkts-apis-webview-e.md#readystate12) | 是 | 播放器的缓存状态。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleFullscreenChanged<sup>12+<sup>

handleFullscreenChanged(fullscreen: boolean): void

当播放器的全屏状态发生变化时，调用该方法将播放器的全屏状态通知给 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| fullscreen | boolean | 是 | 是否全屏。<br>true表示全屏，false表示未全屏。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleSeeking<sup>12+<sup>

handleSeeking(): void

当播放器进入seek 状态时，调用该方法通知 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleSeekFinished<sup>12+<sup>

handleSeekFinished(): void

当播放器 seek 完成后，调用该方法通知 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleError<sup>12+<sup>

handleError(error: MediaError, errorMessage: string): void

当播放器发生错误时， 调用该方法通知 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| error | [MediaError](./arkts-apis-webview-e.md#mediaerror12) | 是 | 错误类型。 |
| errorMessage | string | 是 | 错误的详细描述。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## handleVideoSizeChanged<sup>12+<sup>

handleVideoSizeChanged(width: number, height: number): void

当播放器解析出视频的尺寸时， 调用该方法通知 ArkWeb 内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| width  | number | 是 | 视频的宽。 |
| height | number | 是 | 视频的高。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。