# Enums

> **说明：**
>
> 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## MessageLevel

ConsoleMessage的信息级别。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称    | 值 | 说明    |
| ----- | -- | ---- |
| Debug | 1 | 调试级别。 |
| Error | 4 | 错误级别。 |
| Info  | 2 | 消息级别。 |
| Log   | 5 | 日志级别。 |
| Warn  | 3 | 警告级别。 |

## MixedMode

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 值 | 说明                                 |
| ---------- | -- | ---------------------------------- |
| All        | 0 | 宽松模式：允许加载HTTP和HTTPS混合内容。所有不安全的内容都可以被加载。 |
| Compatible | 1 | 兼容模式：混合内容兼容性模式，部分不安全的内容可能被加载。           |
| None       | 2 | 严格模式：不允许加载HTTP和HTTPS混合内容。               |

## HitTestType

 **系统能力：** SystemCapability.Web.Webview.Core

| 名称            | 值 | 说明                       |
| ------------- | -- | ------------------------ |
| EditText      | 0 | 可编辑的区域。                  |
| Email         | 1 | 电子邮件地址。                  |
| HttpAnchor    | 2 | 超链接，其src为http。           |
| HttpAnchorImg | 3 | 带有超链接的图片，其中超链接的src为http。 |
| Img           | 4 | HTML::img标签。             |
| Map           | 5 | 地理地址。                    |
| Phone         | 6 | 电话号码。                    |
| Unknown       | 7 | 未知内容。                    |

## CacheMode

**系统能力：** SystemCapability.Web.Webview.Core

| 名称      | 值 | 说明                                   |
| ------- | -- | ------------------------------------ |
| Default<sup>9+</sup> | 0 | 优先使用未过期cache加载资源，无效或无cache时从网络获取。 |
| None    | 1 | 优先使用cache(含过期)加载资源，无cache时从网络获取。     |
| Online  | 2 | 强制从网络获取最新资源，不使用任何cache。               |
| Only    | 3 | 仅使用本地cache加载资源。                        |


## OverScrollMode<sup>11+</sup>

设置Web的过滚动模式为关闭或开启。

 **系统能力：** SystemCapability.Web.Webview.Core

| 名称     | 值 | 说明          |
| ------ | -- | ----------- |
| NEVER  | 0 | Web过滚动模式关闭。 |
| ALWAYS | 1 | Web过滚动模式开启。 |

## BlurOnKeyboardHideMode<sup>14+</sup>

设置手动收起软键盘时Web元素是否失焦。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 名称     | 值 | 说明          |
| ------ | -- | ----------- |
| SILENT  | 0 | 软键盘收起时Web组件失焦功能关闭，当用户手动收起软键盘时焦点仍在文本框。 |
| BLUR | 1 | 软键盘收起时Web组件失焦功能开启，当用户手动收起软键盘时，焦点会从文本框转移到Web的body上，文本框失焦。 |

## WebDarkMode<sup>9+</sup>

Web深色模式的配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称   | 值 | 说明           |
| ---- | -- | ------------ |
| Off  | 0 | Web深色模式关闭。   |
| On   | 1 | Web深色模式开启。   |
| Auto | 2 | Web深色模式跟随系统。 |

## WebCaptureMode<sup>10+</sup>

Web屏幕捕获模式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明      |
| ----------- | -- | ------- |
| HOME_SCREEN | 0 | 主屏捕获模式。 |

## ThreatType<sup>11+</sup>

定义网站风险类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 值 | 说明                   |
| ---------------- | -- | ----------------------|
| THREAT_ILLEGAL  | 0 | 非法网站。              |
| THREAT_FRAUD    | 1 | 欺诈网站。              |
| THREAT_RISK     | 2 | 存在安全风险的网站。      |
| THREAT_WARNING  | 3 | 涉嫌包含不健康内容的网站。 |

## RenderExitReason<sup>9+</sup>

onRenderExited接口返回的渲染进程退出的具体原因。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                         | 值 | 说明                |
| -------------------------- | -- | ----------------- |
| ProcessAbnormalTermination | 0 | 渲染进程异常退出。         |
| ProcessWasKilled           | 1 | 收到SIGKILL，或被手动终止。 |
| ProcessCrashed             | 2 | 渲染进程崩溃退出，如段错误。    |
| ProcessOom                 | 3 | 程序内存不足。           |
| ProcessExitUnknown         | 4 | 其他原因。             |

## SslError<sup>9+</sup>

onSslErrorEventReceive接口返回的SSL错误的具体原因。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 值 | 说明          |
| ------------ | -- | ----------- |
| Invalid      | 0 | 一般错误。       |
| HostMismatch | 1 | 主机名不匹配。     |
| DateInvalid  | 2 | 证书日期无效。     |
| Untrusted    | 3 | 证书颁发机构不受信任。 |

## FileSelectorMode<sup>9+</sup>

文件选择器的模式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                   | 值 | 说明         |
| -------------------- | -- | ---------- |
| FileOpenMode         | 0 | 打开上传单个文件。  |
| FileOpenMultipleMode | 1 | 打开上传多个文件。  |
| FileOpenFolderMode   | 2 | 打开上传文件夹模式。 |
| FileSaveMode         | 3 | 文件保存模式。    |

## WebLayoutMode<sup>11+</sup>

Web布局模式的配置。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                 |
| ----------- | -- | ------------------ |
| NONE        | 0 | Web布局跟随系统。         |
| FIT_CONTENT | 1 | Web基于页面大小的自适应网页布局。 |

## RenderProcessNotRespondingReason<sup>12+</sup>

触发渲染进程无响应回调的原因。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| INPUT_TIMEOUT                  | 0 | 发送给渲染进程的input事件响应超时。   |
| NAVIGATION_COMMIT_TIMEOUT      | 1 | 新的网页加载导航响应超时。   |

## ProtectedResourceType<sup>9+</sup>

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                          | 值 | 说明            |
| --------------------------- | --------------- | ------------- |
| MidiSysex                   | TYPE_MIDI_SYSEX | MIDI SYSEX资源。<br>目前仅支持权限事件上报，MIDI设备的使用还未支持。 |
| VIDEO_CAPTURE<sup>10+</sup> | TYPE_VIDEO_CAPTURE | 视频捕获资源，例如相机。  |
| AUDIO_CAPTURE<sup>10+</sup> | TYPE_AUDIO_CAPTURE | 音频捕获资源，例如麦克风。 |
| SENSOR<sup>12+</sup>        | TYPE_SENSOR | 传感器资源，例如加速度传感器。 |

## ContextMenuSourceType<sup>9+</sup>

**系统能力：** SystemCapability.Web.Webview.Core

| 名称       | 值 | 说明         |
| --------- | -- |------------ |
| None      | 0 | 其他事件来源。 |
| Mouse     | 1 | 鼠标事件。   |
| LongPress | 2 | 长按事件。   |

## ContextMenuMediaType<sup>9+</sup>

**系统能力：** SystemCapability.Web.Webview.Core

| 名称    | 值 | 说明            |
| ----- | -- | ------------- |
| None  | 0 | 非特殊媒体或其他媒体类型。 |
| Image | 1 | 图片。           |
| Video<sup>20+</sup> | 2 | 视频。           |
| Audio<sup>20+</sup> | 3 | 音频。           |

## ContextMenuInputFieldType<sup>9+</sup>

输入框类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 值 | 说明                          |
| --------- | -- | --------------------------- |
| None      | 0 | 非输入框。                       |
| PlainText | 1 | 纯文本类型，包括text、search、email等。 |
| Password  | 2 | 密码类型。                       |
| Number    | 3 | 数字类型。                       |
| Telephone | 4 | 电话号码类型。                     |
| Other     | 5 | 其他类型。                       |

## NativeEmbedStatus<sup>11+</sup>

定义同层标签生命周期，当加载页面中有同层标签会触发CREATE，同层标签移动或者放大会触发UPDATE，退出页面会触发DESTROY。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| CREATE                        | 0 | 同层标签创建。   |
| UPDATE                        | 1 | 同层标签更新。   |
| DESTROY                       | 2 | 同层标签销毁。 |
| ENTER_BFCACHE<sup>12+</sup>   | 3 | 同层标签进入BFCache。   |
| LEAVE_BFCACHE<sup>12+</sup>   | 4 | 同层标签离开BFCache。 |

## ContextMenuEditStateFlags<sup>9+</sup>

支持以按位或的方式使用此枚举。例如，如果需要同时支持CAN_CUT、CAN_COPY和CAN_SELECT_ALL，可使用CAN_CUT | CAN_COPY | CAN_SELECT_ALL或11。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称            | 值 | 说明     |
| -------------- | -- | -------- |
| NONE           | 0 | 不可编辑。 |
| CAN_CUT        | 1 << 0 | 支持剪切。 |
| CAN_COPY       | 1 << 1 | 支持拷贝。 |
| CAN_PASTE      | 1 << 2 | 支持粘贴。 |
| CAN_SELECT_ALL | 1 << 3 | 支持全选。 |

## WebNavigationType<sup>11+</sup>

定义navigation类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| UNKNOWN                       | 0 | 未知类型。   |
| MAIN_FRAME_NEW_ENTRY          | 1 | 主文档上产生的新的历史节点跳转。   |
| MAIN_FRAME_EXISTING_ENTRY     | 2 | 主文档上产生的到已有的历史节点的跳转。 |
| NAVIGATION_TYPE_NEW_SUBFRAME  | 4 | 子文档上产生的用户触发的跳转。 |
| NAVIGATION_TYPE_AUTO_SUBFRAME | 5 | 子文档上产生的非用户触发的跳转。 |

## RenderMode<sup>12+</sup>

定义Web组件的渲染方式，默认为异步渲染模式。

建议使用异步渲染模式，异步渲染模式有更好的性能和更低的功耗。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| ASYNC_RENDER                        | 0 | Web组件异步渲染模式，ArkWeb组件作为图形surface节点，独立送显，Web组件的宽度最大规格不超过7,680 px（物理像素）。   |
| SYNC_RENDER                        | 1 | Web组件同步渲染模式，ArkWeb组件作为图形canvas节点，跟随系统组件一起送显，可以渲染更长的Web组件内容，Web组件的宽度最大规格不超过500,000 px（物理像素）。   |

## ViewportFit<sup>12+</sup>

网页meta中viewport-fit配置的视口类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| AUTO                  | 0 | 默认值，整个网页可见。   |
| CONTAINS      | 1 | 初始布局视口和视觉视口为适应设备显示屏的最大矩形内。   |
| COVER      | 2| 初始布局视口和视觉视口为设备物理屏幕的外接矩形内。   |

## WebKeyboardAvoidMode<sup>12+</sup>

软键盘避让的模式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称               | 值 | 说明           |
| ------------------ | -- | ------------ |
| RESIZE_VISUAL      | 0 | 软键盘避让时，仅调整可视视口大小，不调整布局视口大小。   |
| RESIZE_CONTENT     | 1 | 默认值，软键盘避让时，同时调整可视视口和布局视口的大小。 |
| OVERLAYS_CONTENT   | 2 | 不调整任何视口大小，不会触发软键盘避让。   |

## WebElementType<sup>13+</sup>

网页元素信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 名称       | 值 | 说明              |
| --------- | -- | ----------------- |
| IMAGE     | 1 | 网页元素为图像类型。 |
| LINK<sup>20+</sup>     | 2 | 网页元素为超链接类型。 |

## WebResponseType<sup>13+</sup>

菜单的响应类型。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 名称            | 值 | 说明                |
| -------------- | -- | ------------------  |
| LONG_PRESS     | 1 | 通过长按触发菜单弹出。 |

## AudioSessionType<sup>20+</sup>

应用中Web音频类型。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 名称            | 值 | 说明                |
| -------------- | -- | ------------------  |
| AMBIENT     | 3 | 适用于网页游戏场景，支持Web游戏声音与系统音乐同时播放。对应系统音频流类型STREAM_USAGE_GAME。|

## GestureFocusMode<sup>20+</sup>

手势获焦的模式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                       | 值 | 说明           |
| -------------------------- | -- | ------------- |
| DEFAULT                    | 0 | 默认值，Web会在触摸按下屏幕时申请获焦，包括点击、长按、滑动、缩放等任何触摸屏幕的手势行为。 |
| GESTURE_TAP_AND_LONG_PRESS | 1 | Web只会在点击和长按手势事件生成时申请获焦，点击和长按在触摸抬起之后生成，滑动和缩放等手势行为不会获焦。 |

## WebBypassVsyncCondition<sup>20+</sup>

跳过渲染vsync条件。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                 |
| ----------- | -- | ------------------ |
| NONE        | 0 | 默认值，按vsync调度流程绘制。         |
| SCROLLBY_FROM_ZERO_OFFSET | 1 | 在使用scrollby（只支持带滚动偏移量）且Web页面滚动偏移量为0，渲染流程跳过vsync调度直接绘制。 |