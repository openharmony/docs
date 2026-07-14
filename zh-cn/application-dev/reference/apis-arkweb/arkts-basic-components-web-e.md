# Enums
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @kurli1-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

> **说明：**
>
> 该组件首批接口从API version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## MessageLevel

ConsoleMessage的信息级别。

> **说明：**
>
> - 在HTML5侧，调用console.log或console.info对应ConsoleMessage的信息级别都为MessageLevel.Info。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称    | 值 | 说明    |
| ----- | -- | ---- |
| Debug | 1 | 调试级别。 |
| Info  | 2 | 消息级别。 |
| Warn  | 3 | 警告级别。 |
| Error | 4 | 错误级别。 |
| Log   | 5 | 日志级别。<br/>**起始版本：** 8<br/> **废弃版本：** 26.0.0 |

## ConsoleMessageSource<sup>23+</sup>

ConsoleMessage的日志来源。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称            | 值 | 说明    |
| --------------- | -- | -------- |
| XML             | 0  | 由Web的 XML/HTML 解析器生成的日志（如 HTML 语法错误、XML 格式异常），比如HTML 标签未闭合导致的解析警告。 |
| JAVASCRIPT      | 1  | 执行JavaScript发生异常，比如 JS 语法错误、运行时异常。 |
| NETWORK         | 2  | 加载网页资源失败，比如资源（JS/CSS/ 图片）404 加载失败。 |
| CONSOLE_API     | 3  | 网页调用W3C console接口，比如console.warn，console.error。 |
| STORAGE         | 4  | 存储相关模块（LocalStorage、SessionStorage、IndexedDB、Cookie）生成的日志（如存储配额超限、操作异常）。 |
| RENDERING       | 5  | 渲染引擎（如 Blink）生成的日志（如 CSS 样式无效、布局异常、渲染性能警告）。 |
| SECURITY        | 6  | 违反网页安全策略，HTTPS 证书错误、混合内容（HTTP 资源在 HTTPS 页面加载）。 |
| OTHER           | 7  | 其它，比如Web扩展插件产生的日志。 |
| DEPRECATION     | 8  | 使用了过期语法，比如slider-vertical。 |
| WORKER          | 9  | service worker，shared worker里面的错误，比如service worker navigation preload预加载请求未完成前被中断。 |
| VIOLATION       | 10 | 违反规则，比如一段js执行超过50ms。 |
| INTERVENTION    | 11 | 当Web检测到某些可能危害用户体验、安全或性能的代码行为时，会主动介入并阻止或修改该行为，同时通过带有 kIntervention 的消息告知开发者。比如在没有用户交互的网页里面，触发DispatchBeforeUnload事件。 |
| RECOMMENDATION  | 12 | 检测到不符合Web安全最佳实践的代码行为，提供改进建议。比如当页面中使用了可能存在 XSS 风险的 API（如 innerHTML、eval() 等），但未遵循 Trusted Types 安全规范时。 |

## MixedMode

混合内容模式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称        | 值 | 说明                                 |
| ---------- | -- | ---------------------------------- |
| All        | 0 | 宽松模式：允许加载HTTP和HTTPS混合内容。所有不安全的内容都可以被加载。 |
| Compatible | 1 | 兼容模式：混合内容兼容性模式，部分不安全的内容可能被加载。           |
| None       | 2 | 严格模式：不允许加载HTTP和HTTPS混合内容。               |

## HitTestType<sup>(deprecated)</sup>

点击事件检测结果类型。

 **系统能力：** SystemCapability.Web.Webview.Core

> **说明：**
>
> 从API version9开始支持，从API version 21开始废弃。建议使用[WebHitTestType](./arkts-apis-webview-e.md#webhittesttype)替代。

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

缓存模式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称      | 值 | 说明                                   |
| ------- | -- | ------------------------------------ |
| Default<sup>9+</sup> | 0 | 优先使用未过期cache加载资源，无效或无cache时从网络获取。 |
| None    | 1 | 优先使用cache（含过期）加载资源，无cache时从网络获取。     |
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
| THREAT_NONE<sup>21+</sup>      | 4 | 安全检查通过，未发现任何风险。 |
| THREAT_UNPROCESSED<sup>21+</sup>  | 5 | 未进行安全检查。 |

## RenderExitReason<sup>9+</sup>

onRenderExited接口返回的渲染进程退出的具体原因。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                         | 值 | 说明                |
| -------------------------- | -- | ----------------- |
| ProcessAbnormalTermination | 0 | 渲染进程异常退出，可能原因包括：渲染进程启动超时、达到进程数量上限导致系统回收旧渲染进程、多个页签同时关闭等。     |
| ProcessWasKilled           | 1 | 收到SIGKILL，或被手动终止。 |
| ProcessCrashed             | 2 | 渲染进程崩溃退出，如段错误。    |
| ProcessOom                 | 3 | 程序内存不足。           |
| ProcessExitUnknown         | 4 | 其他原因，比如渲染进程孵化失败。        |

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

ProtectedResourceType 枚举定义了 Web 组件需要访问的受保护资源类型，用于控制MIDI、相机、麦克风、传感器等敏感资源的访问权限，帮助开发者在保护用户隐私的同时提供丰富的Web功能。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                          | 值 | 说明            |    可申请的权限          |
| --------------------------- | --------------- | ------------- |  ---------------------|
| MidiSysex                   | TYPE_MIDI_SYSEX | MIDI SYSEX资源。<br>目前仅支持权限事件上报，MIDI设备的使用还未支持。 | 暂不支持申请使用MIDI(Musical Instrument Digital Interface)设备相关权限。|
| VIDEO_CAPTURE<sup>10+</sup> | TYPE_VIDEO_CAPTURE | 视频捕获资源，例如相机。  | 相机权限：ohos.permission.CAMERA。|
| AUDIO_CAPTURE<sup>10+</sup> | TYPE_AUDIO_CAPTURE | 音频捕获资源，例如麦克风。 | 麦克风权限：ohos.permission.MICROPHONE。|
| SENSOR<sup>12+</sup>        | TYPE_SENSOR | 传感器资源，例如加速度传感器。 | 加速度传感器权限：ohos.permission.ACCELEROMETER、 <br>陀螺仪传感器权限：ohos.permission.GYROSCOPE。 |

## ContextMenuSourceType<sup>9+</sup>

触发上下文菜单的事件来源。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称       | 值 | 说明         |
| --------- | -- |------------ |
| None      | 0 | 其他事件来源。 |
| Mouse     | 1 | 鼠标事件。   |
| LongPress | 2 | 长按事件。   |

## ContextMenuMediaType<sup>9+</sup>

触发上下文菜单的网页元素类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称    | 值 | 说明            |
| ----- | -- | ------------- |
| None  | 0 | 其他非图片媒体类型。 |
| Image | 1 | 图片类型。           |

## ContextMenuDataMediaType<sup>22+</sup>
触发上下文菜单的网页元素类型（增强获取类型能力）。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称    | 值 | 说明            |
| ----- | -- | ------------- |
| NONE  | 0 | 默认值，表示当前上下文菜单不关联任何媒体类型（例如右键文本或空白区域）。|
| IMAGE | 1 | 图片类型。           |
| VIDEO | 2 | 视频类型。           |
| AUDIO | 3 | 音频类型。           |
| CANVAS| 4 | Canvas类型。           |

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

## NativeEmbedParamStatus<sup>21+</sup>

定义同层渲染object标签内嵌param元素的状态变化类型，当添加param元素时触发ADD，修改param元素属性触发UPDATE，删除param元素触发DELETE。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| ADD                           | 0 | 添加param元素。   |
| UPDATE                        | 1 | 更改param元素属性。   |
| DELETE                        | 2 | 删除param元素。 |

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
| ASYNC_RENDER                        | 0 | Web组件异步渲染模式，ArkWeb组件作为图形surface节点，独立送显，Web组件的高度最大规格不超过7,680 px（物理像素）。   |
| SYNC_RENDER                        | 1 | Web组件同步渲染模式，ArkWeb组件作为图形canvas节点，跟随系统组件一起送显，可以渲染更长的Web组件内容，Web组件的高度最大规格不超过500,000 px（物理像素）。   |

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
| RETURN_TO_UICONTEXT<sup>22+</sup> | 3 | Web组件的软键盘避让行为将跟随UIcontext设置的[KeyboardAvoidMode](../apis-arkui/arkts-apis-uicontext-e.md#keyboardavoidmode11)模式，Web组件不再处理组件的避让。 |

## WebElementType<sup>13+</sup>

网页元素信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 名称       | 值 | 说明              |
| --------- | -- | ----------------- |
| IMAGE     | 1 | 网页元素为图像类型。 |
| LINK<sup>20+</sup>     | 2 | 网页元素为超链接类型。 |
| TEXT<sup>21+</sup>     | 3 | 网页元素为文本或可编辑区域类型。 |

## WebResponseType<sup>13+</sup>

菜单的响应类型。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 名称            | 值 | 说明                |
| -------------- | -- | ------------------  |
| LONG_PRESS     | 1 | 通过长按触发菜单弹出。 |
| RIGHT_CLICK<sup>21+</sup>    | 2 | 通过鼠标右键触发菜单弹出。 |

## AudioSessionType<sup>20+</sup>

应用中 Web 音频类型，用于控制 Web 音频的音频流类型和行为，帮助开发者根据应用场景优化音频体验，如支持网页游戏声音与系统音乐同时播放。

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

## WebRotateEffect<sup>22+</sup>

组件旋转时，宽高动画过程中组件内容如何填充以适应新尺寸的方式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                       | 值 | 说明           |
| -------------------------- | -- | ------------- |
| TOPLEFT_EFFECT                    | 0 | 默认值，组件旋转时，保持动画终态的内容大小，并且内容始终与组件保持左上角对齐。 |
| RESIZE_COVER_EFFECT | 1 | 组件旋转时，保持动画终态内容的宽高比进行缩小或放大，使内容两边都大于或等于组件两边，且与组件保持中心对齐，显示内容的中间部分。 |

## WebBypassVsyncCondition<sup>20+</sup>

跳过渲染vsync条件。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                 |
| ----------- | -- | ------------------ |
| NONE        | 0 | 默认值，按vsync调度流程绘制。         |
| SCROLLBY_FROM_ZERO_OFFSET | 1 | 在使用scrollBy（只支持带滚动偏移量）且Web页面滚动偏移量为0，渲染流程跳过vsync调度直接绘制。 |

## PdfLoadResult<sup>20+</sup>

定义PDF页面的加载结果。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称             | 值    | 说明                                       |
| -------------- | ---- | ---------------------------------------- |
| LOAD_SUCCESS | 0 | PDF页面加载成功。    |
| PARSE_ERROR_FILE | 1 | PDF文件加载失败的错误码。 |
| PARSE_ERROR_FORMAT | 2 | PDF文件格式不支持的错误码。 |
| PARSE_ERROR_PASSWORD | 3 | PDF文件密码不正确的错误码。 |
| PARSE_ERROR_HANDLER | 4 | PDF文件处理失败的错误码。 |

## DetectedBlankScreenReason<sup>22+</sup>

白屏的具体原因。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                 |
| ----------- | -- | ------------------ |
| NO_CONTENTFUL_NODES        | 0 | 没有命中任何有内容的节点。<br>当检测策略为DETECTION_CONTENTFUL_NODES_SEVENTEEN时可能触发。         |
| SUB_THRESHOLD_CONTENTFUL_NODES | 1 | 命中有内容节点的数量小于等于阈值。<br>当检测策略为DETECTION_CONTENTFUL_NODES_SEVENTEEN，且开发者设置了节点数量阈值contentfulNodesCountThreshold时可能触发。 |

## BlankScreenDetectionMethod<sup>22+</sup>

白屏检测使用的检测策略的方法。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                 |
| ----------- | -- | ------------------ |
| DETECTION_CONTENTFUL_NODES_SEVENTEEN        | 0 | 以17点检测法进行页面检测。当检测点命中已经渲染了且有意义的节点，则认为有命中。有意义的节点指的是图片，视频和文字节点。<br>当无命中，或少于用户设置阈值命中时，则认为是白屏或者近似白屏。<br>其中，检测的17个点位包括：<br>中心点 (1个)： 位于页面的几何中心。<br>内部网格交点 (16个)：在页面区域内定义一个5×5 的均匀网格，这16个点即为页面内4条垂直等分线和4条水平等分线的交点。         |

## CredentialType<sup>22+</sup>

凭证类型。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                 |
| ----------- | -- | ------------------ |
| CREDENTIAL_USER        | 2 | 用户凭证。         |
| CREDENTIAL_APP        | 3 | 应用凭证。         |
| CREDENTIAL_UKEY        | 4 | ukey凭证。         |

## PinVerifyResult<sup>22+</sup>

PIN码认证结果。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称          | 值 | 说明                 |
| ----------- | -- | ------------------ |
| PIN_VERIFICATION_SUCCESS        | 0 | 成功。         |
| PIN_VERIFICATION_FAILED        | 1 | 失败。         |

## CameraCaptureState<sup>23+</sup>

定义摄像头使用状态的值，用于标识摄像头的当前工作状态，帮助开发者实时监控摄像头资源使用情况，优化资源管理和用户隐私保护。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称   | 值   | 说明         |
| ------ | ---- | ------------ |
| NONE   | 0    | 摄像头未工作。 |
| PAUSED | 1    | 摄像头暂停中。 |
| ACTIVE | 2    | 摄像头捕获中。 |

## MicrophoneCaptureState<sup>23+</sup>

定义麦克风使用状态的值，用于标识麦克风的当前工作状态，帮助开发者实时监控麦克风资源使用情况，优化资源管理和用户隐私保护。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称   | 值   | 说明         |
| ------ | ---- | ------------ |
| NONE   | 0    | 麦克风未工作。 |
| PAUSED | 1    | 麦克风暂停中。 |
| ACTIVE | 2    | 麦克风捕获中。 |

## NavigationPolicy<sup>23+</sup>

WebView中新窗口的打开方式。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                           | 值 | 说明           |
| ----------------------------- | -- | ------------ |
| NEW_POPUP                     | 0 | 在新弹窗中打开。   |
| NEW_WINDOW                    | 1 | 在新窗口中打开。   |
| NEW_BACKGROUND_TAB            | 2 | 在新标签页中以后台方式打开。 |
| NEW_FOREGROUND_TAB            | 3 | 在新标签页中以前台方式打开。 |

## ScrollDirectionalLockType

定义滑动方向锁定的场景类型。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称           | 值 | 说明                           |
| ------------- | -- | ------------------------------ |
| ALL           | 0  | 所有场景都支持滑动锁定。     |
| NESTED_SCROLL | 1  | 嵌套滚动场景下支持滑动锁定。 |

## ScrollbarLayoutPolicy

定义滚动条布局模式控制参数的枚举类型。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称    | 值  | 说明                                 |
| ------- | --- | ------------------------------------ |
| CONTENT | 0   | 滚动条左右布局模式跟随css设定。      |
| SYSTEM  | 1   | 滚动条左右布局模式跟随系统语种设定。 |

## AISessionType

支持的AI会话类型。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称                 | 值 | 说明        |
| ------------------ | - | --------- |
| TRANSLATOR         | 1 | 翻译模型。     |
| LANGUAGE_DETECTOR  | 2 | 语言检测模型。   |
| SUMMARIZER         | 3 | 内容摘要生成模型。 |
| WRITER             | 4 | 写作助手模型。   |
| REWRITER           | 5 | 内容改写助手模型。 |
| PROMPT             | 6 | 提示词模型。    |
| PROOFREADER        | 7 | 内容校对助手模型。 |

## AISessionResultType

AI会话操作的结果状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称      | 值 | 说明       |
| ------- | - | -------- |
| SUCCESS | 0 | 操作执行成功。  |
| FAILURE | 1 | 操作执行失败。  |
| RUNNING | 2 | 操作正在执行中。 |

## WebKeyboardAppearanceMode

WebView中输入法沉浸模式。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

| 名称 | 值 | 说明 |
| ------- | ----  | ------------------- |
| NONE_IMMERSIVE  | 0 |默认外观模式，不采用沉浸式风格。 |
| IMMERSIVE       | 1 |沉浸式模式，跟随系统。|
| LIGHT_IMMERSIVE | 2 |浅色沉浸式风格。                |
| DARK_IMMERSIVE  | 3 |深色沉浸式风格。                |
