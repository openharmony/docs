# Interface (NativeMediaPlayerBridge)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhangyao75477-->
<!--Designer: @gzweioh-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

NativeMediaPlayerBridge 是[CreateNativeMediaPlayerCallback](./arkts-apis-webview-t.md#createnativemediaplayercallback12)回调函数的返回值类型，是接管网页媒体的播放器和 ArkWeb 内核之间的一个接口类。ArkWeb 内核通过该接口类的实例对象控制应用创建的用于接管网页媒体的播放器。该接口允许应用使用自定义的媒体播放器接管网页中的媒体内容播放，同时，该接口还支持播放器的挂起和恢复机制。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本Interface首批接口从API version 12开始支持。
>
> - 示例效果请以真机运行为准。

## updateRect<sup>12+</sup>

updateRect(x: number, y: number, width: number, height: number): void

向应用通知 surface 位置信息。当网页布局变化、页面滚动或播放区域发生改变时由 ArkWeb 内核回调此方法，应用需据此更新原生播放器渲染表面的位置和大小。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| x | number | 是 | surface相对于Web组件的x坐标信息。<br>单位：px。 |
| y | number | 是 | surface相对于Web组件的y坐标信息。<br>单位：px。 |
| width | number | 是 | surface的宽度。<br>单位：px。 |
| height | number | 是 | surface的高度。<br>单位：px。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## play<sup>12+</sup>

play(): void

播放媒体。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## pause<sup>12+</sup>

pause(): void

暂停播放。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## seek<sup>12+</sup>

seek(targetTime: number): void

跳转播放进度到指定时间点。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| targetTime | number | 是 | 播放跳转到的时间点，从媒体开始播放时计算。<br>单位：秒。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## setVolume<sup>12+</sup>

setVolume(volume: number): void

设置播放器音量值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| volume | number | 是 | 播放器的音量。<br>取值范围：[0, 1.0]，其中0表示静音，1.0表示最大音量。超出取值范围时，按边界值自动修正。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## setMuted<sup>12+</sup>

setMuted(muted: boolean): void

设置静音状态。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| muted | boolean | 是 | 是否静音。<br>true表示静音，false表示未静音。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## setPlaybackRate<sup>12+</sup>

setPlaybackRate(playbackRate: number): void

设置播放速率。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| playbackRate | number | 是 | 播放速率。<br>取值范围：[0, 10.0]，其中1表示原速播放。超出取值范围时，按边界值自动修正。 |

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## release<sup>12+</sup>

release(): void

销毁播放器。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## enterFullscreen<sup>12+</sup>

enterFullscreen(): void

使播放器进入全屏。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## exitFullscreen<sup>12+</sup>

exitFullscreen(): void

使播放器退出全屏。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## resumePlayer<sup>12+</sup>

resumePlayer?(): void

通知应用重建播放器，并恢复播放器的状态信息。在 suspendPlayer 挂起后，当需要恢复媒体播放时由 ArkWeb 内核触发，应用应依据已保存的状态信息重建播放器并恢复到挂起前的播放状态。仅与 suspendPlayer 成对出现。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。

## suspendPlayer<sup>12+</sup>

suspendPlayer?(type: SuspendType): void

通知应用销毁播放器，并保存播放器的状态信息。当系统资源需要释放或媒体播放需要临时挂起时由 ArkWeb 内核触发，应用应保存当前播放状态（如播放位置、音量等）以便后续恢复。仅与 resumePlayer 成对出现。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
|--------|------|------|------|
| type | [SuspendType](./arkts-apis-webview-e.md#suspendtype12) | 是 | 播放器挂起类型，用于指定播放器挂起的方式。不同 SuspendType 取值对应不同的挂起场景，应根据实际挂起需求选择合适的类型。|

**示例：**

完整示例代码参考[onCreateNativeMediaPlayer](./arkts-apis-webview-WebviewController.md#oncreatenativemediaplayer12)。
