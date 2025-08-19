# Interface (NativeMediaPlayerBridge)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhangyao75477-->
<!--Designer: @qiu-gongkai-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

[CreateNativeMediaPlayerCallback](./arkts-apis-webview-t.md#createnativemediaplayercallback12) 回调函数的返回值类型。
接管网页媒体的播放器和 ArkWeb 内核之间的一个接口类。
ArkWeb 内核通过该接口类的实例对象来控制应用创建的用来接管网页媒体的播放器。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Interface首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## updateRect<sup>12+<sup>

updateRect(x: number, y: number, width: number, height: number): void

更新 surface 位置信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| x | number | 是 | surface 相对于 Web 组件的 x 坐标信息。 |
| y | number | 是 | surface 相对于 Web 组件的 y 坐标信息。 |
| width  | number | 是 | surface 的宽度。 |
| height | number | 是 | surface 的高度。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## play<sup>12+<sup>

play(): void

播放视频。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## pause<sup>12+<sup>

pause(): void

暂停播放。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## seek<sup>12+<sup>

seek(targetTime: number): void

播放跳转到某个时间点。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| targetTime | number | 是 | 播放跳转到的时间点。<br>单位：秒。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## setVolume<sup>12+<sup>

setVolume(volume: number): void

设置播放器音量值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| volume | number | 是 | 播放器的音量。<br>取值范围:[0, 1.0]，其中0表示静音，1.0表示最大音量。 |

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## setMuted<sup>12+<sup>

setMuted(muted: boolean): void

设置静音状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| muted | boolean | 是 | 是否静音。<br>true表示静音，false表示未静音。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## setPlaybackRate<sup>12+<sup>

setPlaybackRate(playbackRate: number): void

设置播放速度。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| playbackRate | number | 是 | 播放倍率。<br>取值范围: [0, 10.0]，其中1表示原速播放。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## release<sup>12+<sup>

release(): void

销毁播放器。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## enterFullscreen<sup>12+<sup>

enterFullscreen(): void

播放器进入全屏。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## exitFullscreen<sup>12+<sup>

exitFullscreen(): void

播放器退出全屏。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## resumePlayer<sup>12+<sup>

resumePlayer?(): void

通知应用重建应用内播放器，并恢复应用内播放器的状态信息。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## suspendPlayer<sup>12+<sup>

suspendPlayer?(type: SuspendType): void

通知应用销毁应用内播放器，并保存应用内播放器的状态信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| type | [SuspendType](./arkts-apis-webview-e.md#suspendtype12) | 是 | 播放器挂起类型。|

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。
