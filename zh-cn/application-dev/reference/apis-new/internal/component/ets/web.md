# web    
提供具有网页显示能力的Web组件，[./apis/js-apis-webview.md)提供web控制能力。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## WebviewController    
## MessageLevel    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Debug | 0 | 调试级别。 |  
| Error | 1 | 错误级别。 |  
| Info | 2 | 消息级别。 |  
| Log | 3 | 日志级别。 |  
| Warn | 4 | 警告级别。 |  
    
## MixedMode    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| All | 0 | 允许加载HTTP和HTTPS混合内容。所有不安全的内容都可以被加载。 |  
| Compatible | 1 | 混合内容兼容性模式，部分不安全的内容可能被加载。 |  
| None | 2 | 不允许加载HTTP和HTTPS混合内容。 |  
    
## HitTestType    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| EditText | 0 | 可编辑的区域。 |  
| Email | 1 | 电子邮件地址。 |  
| HttpAnchor | 2 | 超链接，其src为http。 |  
| HttpAnchorImg | 3 | 带有超链接的图片，其中超链接的src为http。 |  
| Img | 4 | HTML::img标签。 |  
| Map | 5 | 地理地址。 |  
| Phone | 6 | 电话号码。 |  
| Unknown | 7 | 未知内容。 |  
    
## CacheMode    
使用未过期的cache加载资源，如果cache中无该资源则从网络中获取。    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Default<sup>(9+)</sup> | 0 |  |  
| None | 1 | 加载资源使用cache，如果cache中无该资源则从网络中获取。 |  
| Online | 2 | 加载资源不使用cache，全部从网络中获取。 |  
| Only | 3 | 只从cache中加载资源。 |  
    
## WebDarkMode<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Off | 0 | Web深色模式关闭。 |  
| On | 1 | Web深色模式开启。 |  
| Auto | 2 | Web深色模式跟随系统。 |  
    
## WebCaptureMode<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| HOME_SCREEN | 0 | 主屏捕获模式。 |  
    
## WebMediaOptions<sup>(10+)</sup>    
Web媒体策略的配置。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| resumeInterval<sup>(10+)</sup> | number | false | false | 被暂停的Web音频能够自动续播的有效期，单位：秒。最长有效期为60秒，由于近似值原因，该有效期可能存在一秒内的误差。 |  
| audioExclusive<sup>(10+)</sup> | boolean | false | false | 应用内多个Web实例的音频是否独占。 |  
    
## ScreenCaptureConfig<sup>(10+)</sup>    
Web屏幕捕获的配置。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| captureMode<sup>(10+)</sup> | WebCaptureMode | false | true | Web屏幕捕获模式。 |  
    
## FullScreenExitHandler<sup>(9+)</sup>    
通知开发者Web组件退出全屏。示例代码参考[onFullScreenEnter事件](#onfullscreenenter9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### exitFullScreen<sup>(9+)</sup>    
通知开发者Web组件退出全屏。  
 **调用形式：**     
- exitFullScreen(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
## RenderExitReason<sup>(9+)</sup>    
onRenderExited接口返回的渲染进程退出的具体原因。    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ProcessAbnormalTermination | 0 | 渲染进程异常退出。 |  
| ProcessWasKilled | 1 | 收到SIGKILL，或被手动终止。 |  
| ProcessCrashed | 2 | 渲染进程崩溃退出，如段错误。 |  
| ProcessOom | 3 | 程序内存不足。 |  
| ProcessExitUnknown | 4 | 其他原因。 |  
    
## SslError<sup>(9+)</sup>    
onSslErrorEventReceive接口返回的SSL错误的具体原因。    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Invalid | 0 | 一般错误。 |  
| HostMismatch | 1 | 主机名不匹配。 |  
| DateInvalid | 2 | 证书日期无效。 |  
| Untrusted | 3 | 证书颁发机构不受信任。 |  
    
## FileSelectorMode<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FileOpenMode | 0 | 打开上传单个文件。 |  
| FileOpenMultipleMode | 1 | 打开上传多个文件。 |  
| FileOpenFolderMode | 2 | 打开上传文件夹模式。 |  
| FileSaveMode | 3 | 文件保存模式。 |  
    
## FileSelectorParam<sup>(9+)</sup>    
web组件获取文件对象。示例代码参考[onShowFileSelector事件](#onshowfileselector9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getTitle<sup>(9+)</sup>    
获取文件选择器标题。  
 **调用形式：**     
- getTitle(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回文件选择器标题。 |  
    
### getMode<sup>(9+)</sup>    
获取文件选择器的模式。  
 **调用形式：**     
- getMode(): FileSelectorMode  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| FileSelectorMode | 返回文件选择器的模式。 |  
    
### getAcceptType<sup>(9+)</sup>    
获取文件过滤类型。  
 **调用形式：**     
- getAcceptType(): Array\<string>  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 返回文件过滤类型。 |  
    
### isCapture<sup>(9+)</sup>    
获取是否调用多媒体能力。  
 **调用形式：**     
- isCapture(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回是否调用多媒体能力。 |  
    
## JsResult    
Web组件返回的弹窗确认或弹窗取消功能对象。示例代码参考[onAlert事件](#onalert)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### handleCancel    
通知Web组件用户取消弹窗操作。  
 **调用形式：**     
- handleCancel(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### handleConfirm    
通知Web组件用户确认弹窗操作。  
 **调用形式：**     
- handleConfirm(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### handlePromptConfirm<sup>(9+)</sup>    
通知Web组件用户确认弹窗操作及对话框内容。  
 **调用形式：**     
- handlePromptConfirm(result: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| result | string | true | 用户输入的对话框内容。 |  
    
## FileSelectorResult<sup>(9+)</sup>    
通知Web组件的文件选择结果。示例代码参考[onShowFileSelector事件](#onshowfileselector9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### handleFileList<sup>(9+)</sup>    
通知Web组件进行文件选择操作。  
 **调用形式：**     
- handleFileList(fileList: Array\<string>): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fileList | Array<string> | true | 需要进行操作的文件列表。 |  
    
## HttpAuthHandler<sup>(9+)</sup>    
Web组件返回的http auth认证请求确认或取消和使用缓存密码认证功能对象。示例代码参考[onHttpAuthRequest事件](#onhttpauthrequest9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### confirm<sup>(9+)</sup>    
使用用户名和密码进行HTTP认证操作。  
 **调用形式：**     
- confirm(userName: string, password: string): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userName | string | true | HTTP认证用户名。 |  
| password | string | true | HTTP认证密码。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 认证成功返回true，失败返回false。 |  
    
### cancel<sup>(9+)</sup>    
通知Web组件用户取消HTTP认证操作。  
 **调用形式：**     
- cancel(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### isHttpAuthInfoSaved<sup>(9+)</sup>    
通知Web组件用户使用服务器缓存的帐号密码认证。  
 **调用形式：**     
- isHttpAuthInfoSaved(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 存在密码认证成功返回true，其他返回false。 |  
    
## SslErrorHandler<sup>(9+)</sup>    
eb组件返回的SSL错误通知事件用户处理功能对象。示例代码参考[onSslErrorEventReceive事件](#onsslerroreventreceive9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### handleConfirm<sup>(9+)</sup>    
通知Web组件继续使用SSL证书。  
 **调用形式：**     
- handleConfirm(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### handleCancel<sup>(9+)</sup>    
通知Web组件取消此请求。  
 **调用形式：**     
- handleCancel(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
## ClientAuthenticationHandler<sup>(9+)</sup>    
Web组件返回的SSL客户端证书请求事件用户处理功能对象。示例代码参考[onClientAuthenticationRequest事件](#onclientauthenticationrequest9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### confirm<sup>(9+)</sup>    
通知Web组件使用指定的私钥和客户端证书链。  
 **调用形式：**     
- confirm(priKeyFile: string, certChainFile: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| priKeyFile | string | true | 存放私钥的文件，包含路径和文件名。 |  
| certChainFile | string | true | 存放证书链的文件，包含路径和文件名。 |  
    
### cancel<sup>(9+)</sup>    
通知Web组件取消相同host和port服务器发送的客户端证书请求事件。同时，相同host和port服务器的请求，不重复上报该事件。  
 **调用形式：**     
- cancel(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### ignore<sup>(9+)</sup>    
通知Web组件忽略本次请求。  
 **调用形式：**     
- ignore(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
## ProtectedResourceType<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MidiSysex | TYPE_MIDI_SYSEX | 目前仅支持权限事件上报，MIDI设备的使用还未支持。 |  
| VIDEO_CAPTURE<sup>(10+)</sup> | TYPE_VIDEO_CAPTURE | 视频捕获资源，例如相机。 |  
| AUDIO_CAPTURE<sup>(10+)</sup> | TYPE_AUDIO_CAPTURE | 音频捕获资源，例如麦克风。 |  
    
## PermissionRequest<sup>(9+)</sup>    
Web组件返回授权或拒绝权限功能的对象。示例代码参考[onPermissionRequest事件](#onpermissionrequest9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### deny<sup>(9+)</sup>    
拒绝网页所请求的权限。  
 **调用形式：**     
- deny(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getOrigin<sup>(9+)</sup>    
获取网页来源。  
 **调用形式：**     
- getOrigin(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 当前请求权限网页的来源。 |  
    
### getAccessibleResource<sup>(9+)</sup>    
获取网页所请求的权限资源列表，资源列表类型参考[ProtectedResourceType](#protectedresourcetype9枚举说明)。  
 **调用形式：**     
- getAccessibleResource(): Array\<string>  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 网页所请求的权限资源列表。 |  
    
### grant<sup>(9+)</sup>    
对网页访问的给定权限进行授权。  
 **调用形式：**     
- grant(resources: Array\<string>): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| resources | Array<string> | true | 授予网页请求的权限的资源列表。 |  
    
## ScreenCaptureHandler<sup>(10+)</sup>    
Web组件返回授权或拒绝屏幕捕获功能的对象。示例代码参考[onScreenCaptureRequest事件](#onscreencapturerequest10)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getOrigin<sup>(10+)</sup>    
获取网页来源。  
 **调用形式：**     
- getOrigin(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 当前请求权限网页的来源。 |  
    
### grant<sup>(10+)</sup>    
对网页访问的屏幕捕获操作进行授权。  
 **调用形式：**     
- grant(config: ScreenCaptureConfig): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | ScreenCaptureConfig | true | 屏幕捕获配置。 |  
    
### deny<sup>(10+)</sup>    
拒绝网页所请求的屏幕捕获操作。  
 **调用形式：**     
- deny(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
## DataResubmissionHandler<sup>(9+)</sup>    
通过DataResubmissionHandler可以重新提交表单数据或取消提交表单数据。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### resend<sup>(9+)</sup>    
重新发送表单数据。  
 **调用形式：**     
- resend(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ets  
  import web_webview from '@ohos.web.webview'  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: web_webview.WebviewController = new web_webview.WebviewController()  
    build() {  
      Column() {  
        Web({ src:'www.example.com', controller: this.controller })  
         .onDataResubmitted((event) => {  
          console.log('onDataResubmitted')  
          event.handler.resend();  
        })  
      }  
    }  
  }  
    
```    
  
    
### cancel<sup>(9+)</sup>    
取消重新发送表单数据。  
 **调用形式：**     
- cancel(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
## ControllerHandler<sup>(9+)</sup>    
设置用户新建web组件的的WebviewController对象。示例代码参考[onWindowNew事件](#onwindownew9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### setWebController<sup>(9+)</sup>    
设置WebviewController对象，如果不需要打开新窗口请设置为null。  
 **调用形式：**     
- setWebController(controller: WebviewController): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| controller | WebviewController | true | 新建web组件的WebviewController对象，如果不需要打开新窗口请设置为null。 |  
    
## ContextMenuSourceType<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | 其他事件来源。 |  
| Mouse | 1 | 鼠标事件。 |  
| LongPress | 2 | 长按事件。 |  
    
## ContextMenuMediaType<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | 非特殊媒体或其他媒体类型。 |  
| Image | 1 | 非特殊媒体或其他媒体类型。 |  
    
## ContextMenuInputFieldType<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| None | 0 | 非输入框。 |  
| PlainText | 1 | 纯文本类型，包括text、search、email等。 |  
| Password | 2 | 密码类型。 |  
| Number | 3 | 数字类型。 |  
| Telephone | 4 | 电话号码类型。 |  
| Other | 5 | 其他类型。 |  
    
## ContextMenuEditStateFlags<sup>(9+)</sup>    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 不可编辑。 |  
| CAN_CUT | 1 << 0 | 支持剪切。 |  
| CAN_COPY | 1 << 1 | 支持拷贝。 |  
| CAN_PASTE | 1 << 2 | 支持粘贴。 |  
| CAN_SELECT_ALL | 1 << 3 | 支持全选。 |  
    
## WebContextMenuParam<sup>(9+)</sup>    
实现长按页面元素或鼠标右键弹出来的菜单信息。示例代码参考[onContextMenuShow事件](#oncontextmenushow9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### x<sup>(9+)</sup>    
弹出菜单的x坐标。  
 **调用形式：**     
- x(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 显示正常返回非负整数，否则返回-1。 |  
    
### y<sup>(9+)</sup>    
弹出菜单的y坐标。  
 **调用形式：**     
- y(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 显示正常返回非负整数，否则返回-1。 |  
    
### getLinkUrl<sup>(9+)</sup>    
获取链接地址。  
 **调用形式：**     
- getLinkUrl(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 如果长按位置是链接，返回经过安全检查的url链接。 |  
    
### getUnfilteredLinkUrl<sup>(9+)</sup>    
获取链接地址。  
 **调用形式：**     
- getUnfilteredLinkUrl(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 如果长按位置是链接，返回原始的url链接。 |  
    
### getSourceUrl<sup>(9+)</sup>    
获取sourceUrl链接。  
 **调用形式：**     
- getSourceUrl(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 如果选中的元素有src属性，返回src的url。 |  
    
### existsImageContents<sup>(9+)</sup>    
是否存在图像内容。  
 **调用形式：**     
- existsImageContents(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 长按位置中有图片返回true，否则返回false。 |  
    
### getMediaType<sup>(9+)</sup>    
获取网页元素媒体类型。  
 **调用形式：**     
- getMediaType(): ContextMenuMediaType  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ContextMenuMediaType | 网页元素媒体类型。 |  
    
### getSelectionText<sup>(9+)</sup>    
获取选中文本。  
 **调用形式：**     
- getSelectionText(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 菜单上下文选中文本内容，不存在则返回空。 |  
    
### getSourceType<sup>(9+)</sup>    
获取菜单事件来源。  
 **调用形式：**     
- getSourceType(): ContextMenuSourceType  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ContextMenuSourceType | 菜单事件来源。 |  
    
### getInputFieldType<sup>(9+)</sup>    
获取网页元素输入框类型。  
 **调用形式：**     
- getInputFieldType(): ContextMenuInputFieldType  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ContextMenuInputFieldType | 输入框类型。 |  
    
### isEditable<sup>(9+)</sup>    
获取网页元素是否可编辑标识。  
 **调用形式：**     
- isEditable(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 网页元素可编辑返回true，不可编辑返回false。 |  
    
### getEditStateFlags<sup>(9+)</sup>    
获取网页元素可编辑标识。  
 **调用形式：**     
- getEditStateFlags(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 网页元素可编辑标识，参照[ContextMenuEditStateFlags](#contextmenueditstateflags9枚举说明)。 |  
    
## WebContextMenuResult<sup>(9+)</sup>    
实现长按页面元素或鼠标右键弹出来的菜单所执行的响应事件。示例代码参考[onContextMenuShow事件](#oncontextmenushow9)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### closeContextMenu<sup>(9+)</sup>    
不执行WebContextMenuResult其他接口操作时，需要调用此接口关闭菜单。  
 **调用形式：**     
- closeContextMenu(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### copyImage<sup>(9+)</sup>    
WebContextMenuParam有图片内容则复制图片。  
 **调用形式：**     
- copyImage(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### copy<sup>(9+)</sup>    
执行与此上下文菜单相关的拷贝操作。  
 **调用形式：**     
- copy(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### paste<sup>(9+)</sup>    
执行与此上下文菜单相关的粘贴操作。  
 **调用形式：**     
- paste(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### cut<sup>(9+)</sup>    
执行与此上下文菜单相关的剪切操作。  
 **调用形式：**     
- cut(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### selectAll<sup>(9+)</sup>    
执行与此上下文菜单相关的全选操作。  
 **调用形式：**     
- selectAll(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
## ConsoleMessage    
Web组件获取控制台信息对象。示例代码参考[onConsole事件](#onconsole)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getMessage    
获取ConsoleMessage的日志信息。  
 **调用形式：**     
- getMessage(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回ConsoleMessage的日志信息。 |  
    
### getSourceId    
获取网页源文件路径和名字。  
 **调用形式：**     
- getSourceId(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回网页源文件路径和名字。 |  
    
### getLineNumber    
获取ConsoleMessage的行数。  
 **调用形式：**     
- getLineNumber(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回ConsoleMessage的行数。 |  
    
### getMessageLevel    
获取ConsoleMessage的信息级别。  
 **调用形式：**     
- getMessageLevel(): MessageLevel  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MessageLevel | 返回ConsoleMessage的信息级别。 |  
    
## WebResourceRequest    
web组件获取资源请求对象。示例代码参考[onErrorReceive事件](#onerrorreceive)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getRequestHeader    
获取资源请求头信息。  
 **调用形式：**     
- getRequestHeader(): Array\<Header>  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<Header> | 返回资源请求头信息。 |  
    
### getRequestUrl    
获取资源请求的URL信息。  
 **调用形式：**     
- getRequestUrl(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回资源请求的URL信息。 |  
    
### isRequestGesture    
获取资源请求是否与手势（如点击）相关联。  
 **调用形式：**     
- isRequestGesture(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回资源请求是否与手势（如点击）相关联。 |  
    
### isMainFrame    
判断资源请求是否为主frame。  
 **调用形式：**     
- isMainFrame(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回资源请求是否为主frame。 |  
    
### isRedirect    
判断资源请求是否被服务端重定向。  
 **调用形式：**     
- isRedirect(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回资源请求是否被服务端重定向。 |  
    
### getRequestMethod<sup>(9+)</sup>    
获取请求方法。  
 **调用形式：**     
- getRequestMethod(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回请求方法。 |  
    
## WebResourceResponse    
web组件资源响应对象。示例代码参考[onHttpErrorReceive事件](#onhttperrorreceive)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getResponseData    
获取资源响应数据。  
 **调用形式：**     
- getResponseData(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回资源响应数据。 |  
    
### getResponseEncoding    
获取资源响应的编码。  
 **调用形式：**     
- getResponseEncoding(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回资源响应的编码。 |  
    
### getResponseMimeType    
获取资源响应的媒体（MIME）类型。  
 **调用形式：**     
- getResponseMimeType(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回资源响应的媒体（MIME）类型。 |  
    
### getReasonMessage    
获取资源响应的状态码描述。  
 **调用形式：**     
- getReasonMessage(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回资源响应的状态码描述。 |  
    
### getResponseHeader    
获取资源响应头。  
 **调用形式：**     
- getResponseHeader(): Array\<Header>  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<Header> | 返回资源响应头。 |  
    
### getResponseCode    
获取资源响应的状态码。  
 **调用形式：**     
- getResponseCode(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回资源响应的状态码。 |  
    
### setResponseData<sup>(9+)</sup>    
设置资源响应数据。  
 **调用形式：**     
- setResponseData(data: string | number | Resource)  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | string | true | 要设置的资源响应数据。string表示HTML格式的字符串。number表示文件句柄, 此句柄由系统的Web组件负责关闭。 Resource表示应用rawfile目录下文件资源。 |  
    
### setResponseEncoding<sup>(9+)</sup>    
设置资源响应的编码。  
 **调用形式：**     
- setResponseEncoding(encoding: string)  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| encoding | string | true | 要设置的资源响应的编码。 |  
    
### setResponseMimeType<sup>(9+)</sup>    
设置资源响应的媒体（MIME）类型。  
 **调用形式：**     
- setResponseMimeType(mimeType: string)  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mimeType | string | true | 要设置的资源响应的媒体（MIME）类型。 |  
    
### setReasonMessage<sup>(9+)</sup>    
设置资源响应的状态码描述。  
 **调用形式：**     
- setReasonMessage(reason: string)  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reason | string | true | 要设置的资源响应的状态码描述。 |  
    
### setResponseHeader<sup>(9+)</sup>    
设置资源响应头。  
 **调用形式：**     
- setResponseHeader(header: Array\<Header>)  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| header | Array<Header> | true | 要设置的资源响应头。 |  
    
### setResponseCode<sup>(9+)</sup>    
设置资源响应的状态码。  
 **调用形式：**     
- setResponseCode(code: number)  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code | number | true | 要设置的资源响应的状态码。 |  
    
### setResponseIsReady<sup>(9+)</sup>    
设置资源响应数据是否已经就绪。  
 **调用形式：**     
- setResponseIsReady(IsReady: boolean)  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| IsReady | boolean | true | 资源响应数据是否已经就绪。 |  
    
## Header    
Web组件返回的请求/响应头对象。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| headerKey | string | false | true | 请求/响应头的key。 |  
| headerValue | string | false | true | 请求/响应头的value。 |  
    
## WebResourceError    
web组件资源管理错误信息对象。示例代码参考[onErrorReceive事件](#onerrorreceive)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getErrorInfo    
获取加载资源的错误信息。  
 **调用形式：**     
- getErrorInfo(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回加载资源的错误信息。 |  
    
### getErrorCode    
获取加载资源的错误码。  
 **调用形式：**     
- getErrorCode(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回加载资源的错误码。 |  
    
## JsGeolocation    
Web组件返回授权或拒绝权限功能的对象。示例代码参考[onGeolocationShow事件](#ongeolocationshow)。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### invoke    
设置网页地理位置权限状态。  
 **调用形式：**     
- invoke(origin: string, allow: boolean, retain: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| origin | string | true | 指定源的字符串索引。 |  
| allow | boolean | true | 设置的地理位置权限状态。 |  
| retain | boolean | true | 是否允许将地理位置权限状态保存到系统中。可通过[GeolocationPermissions<sup>9+</sup>](../apis/js-apis-webview.md#geolocationpermissions)接口管理保存到系统的地理位置权限。 |  
    
## WebCookie    
通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有web组件共享一个WebCookie。通过controller方法中的getCookieManager方法可以获取WebCookie对象，进行后续的cookie管理操作。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### setCookie<sup>(deprecated)</sup>    
设置cookie，该方法为同步方法。设置成功返回true，否则返回false。  
从API version 9开始不再维护，建议使用[setCookie<sup>9+</sup>](../apis/js-apis-webview.md#setcookie)代替。  
 **调用形式：**     
- setCookie()  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebCookieManager#setCookie。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### saveCookie<sup>(deprecated)</sup>    
将当前存在内存中的cookie同步到磁盘中，该方法为同步方法。  
从API version 9开始不再维护，建议使用[saveCookieAsync<sup>9+</sup>](../apis/js-apis-webview.md#savecookieasync)代替。  
 **调用形式：**     
- saveCookie()  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebCookieManager#saveCookieAsync。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
## WebController<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.web.webview.webview.WebviewController替代。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### onInactive<sup>(deprecated)</sup>    
调用此接口通知Web组件进入未激活状态。  
从API version 9开始不再维护，建议使用[onInactive<sup>9+</sup>](../apis/js-apis-webview.md#oninactive)代替。  
 **调用形式：**     
- onInactive(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#onInactive。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('onInactive')  
          .onClick(() => {  
            this.controller.onInactive()  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### onActive<sup>(deprecated)</sup>    
调用此接口通知Web组件进入前台激活状态。  
从API version 9开始不再维护，建议使用[onActive<sup>9+</sup>](../apis/js-apis-webview.md#onactive)代替。  
 **调用形式：**     
- onActive(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#onActive。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('onActive')  
          .onClick(() => {  
            this.controller.onActive()  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### zoom<sup>(deprecated)</sup>    
调整当前网页的缩放比例。  
从API version 9开始不再维护，建议使用[zoom<sup>9+</sup>](../apis/js-apis-webview.md#zoom)代替。  
 **调用形式：**     
- zoom(factor: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#zoom。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| factor<sup>(deprecated)</sup> | number | true | 基于当前网页所需调整的相对缩放比例，正值为放大，负值为缩小。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
    @State factor: number = 1  
  
    build() {  
      Column() {  
        Button('zoom')  
          .onClick(() => {  
            this.controller.zoom(this.factor)  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### clearHistory<sup>(deprecated)</sup>    
删除所有前进后退记录。  
从API version 9开始不再维护，建议使用[clearHistory<sup>9+</sup>](../apis/js-apis-webview.md#clearhistory)代替。  
 **调用形式：**     
- clearHistory(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#clearHistory。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('clearHistory')  
          .onClick(() => {  
            this.controller.clearHistory()  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### runJavaScript<sup>(deprecated)</sup>    
异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。  
从API version 9开始不再维护，建议使用[runJavaScript<sup>9+</sup>](../apis/js-apis-webview.md#runjavascript)代替。  
 **调用形式：**     
- runJavaScript(options: { script: string, callback?: (result: string) => void })  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#runJavaScript。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | { script: string, callback?: (result: string) => void } | true |  |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
    @State webResult: string = ''  
    build() {  
      Column() {  
        Text(this.webResult).fontSize(20)  
        Web({ src: $rawfile('index.html'), controller: this.controller })  
        .javaScriptAccess(true)  
        .onPageEnd(() => {  
          this.controller.runJavaScript({  
            script: 'test()',  
            callback: (result: string)=> {  
              this.webResult = result  
              console.info(`The test() return value is: ${result}`)  
            }})  
          if (e) {  
            console.info('url: ', e.url)  
          }  
        })  
      }  
    }  
  }  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```html    
<!-- index.html -->  <!DOCTYPE html>  <html>    <meta charset="utf-8">    <body>        Hello world!    </body>    <script type="text/javascript">    function test() {        console.log('Ark WebComponent')        return "This value is from index.html"    }    </script>  </html>    
```    
  
    
### loadData<sup>(deprecated)</sup>    
baseUrl为空时，通过”data“协议加载指定的一段字符串。  
当baseUrl为”data“协议时，编码后的data字符串将被Web组件作为”data"协议加载。  
当baseUrl为“http/https"协议时，编码后的data字符串将被Web组件以类似loadUrl的方式以非编码字符串处理。  
从API version 9开始不再维护，建议使用[loadData<sup>9+</sup>](../apis/js-apis-webview.md#loaddata)代替。  
 **调用形式：**     
- loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string })  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#loadData。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string } | true |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('loadData')  
          .onClick(() => {  
            this.controller.loadData({  
              data: "<html><body bgcolor=\"white\">Source:source</body></html>",  
              mimeType: "text/html",  
              encoding: "UTF-8"  
            })  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### loadUrl<sup>(deprecated)</sup>    
使用指定的http头加载指定的URL。  
通过loadUrl注入的对象只在当前document有效，即通过loadUrl导航到新的页面会无效。  
而通过registerJavaScriptProxy注入的对象，在loadUrl导航到新的页面也会有效。  
从API version 9开始不再维护，建议使用[loadUrl<sup>9+</sup>](../apis/js-apis-webview.md#loadurl)代替。  
 **调用形式：**     
- loadUrl(options: { url: string | Resource, headers?: Array\<Header> })  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#loadUrl。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | { url: string \| Resource, headers?: Array<Header> } | true |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('loadUrl')  
          .onClick(() => {  
            this.controller.loadUrl({ url: 'www.example.com' })  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### refresh<sup>(deprecated)</sup>    
调用此接口通知Web组件刷新网页。  
从API version 9开始不再维护，建议使用[refresh<sup>9+</sup>](../apis/js-apis-webview.md#refresh)代替。  
 **调用形式：**     
- refresh()  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#refresh。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('refresh')  
          .onClick(() => {  
            this.controller.refresh()  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### stop<sup>(deprecated)</sup>    
停止页面加载。  
从API version 9开始不再维护，建议使用[stop<sup>9+</sup>](../apis/js-apis-webview.md#stop)代替。  
 **调用形式：**     
- stop()  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#stop。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('stop')  
          .onClick(() => {  
            this.controller.stop()  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### registerJavaScriptProxy<sup>(deprecated)</sup>    
注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。注册后，须调用[refresh](#refreshdeprecated)接口生效。  
从API version 9开始不再维护，建议使用[registerJavaScriptProxy<sup>9+</sup>](../apis/js-apis-webview.md#registerjavascriptproxy)代替。  
 **调用形式：**     
- registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string> })  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#registerJavaScriptProxy。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | { object: object, name: string, methodList: Array<string> } | true |  |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
  class TestObj {  
    constructor() {  
    }  
  
    test(): string {  
      return "ArkUI Web Component"  
    }  
  
    toString(): void {  
      console.log('Web Component toString')  
    }  
  }  
  
  @Entry  
  @Component  
  struct Index {  
    controller: WebController = new WebController()  
    testObj = new TestObj();  
    build() {  
      Column() {  
        Row() {  
          Button('Register JavaScript To Window').onClick(() => {  
            this.controller.registerJavaScriptProxy({  
              object: this.testObj,  
              name: "objName",  
              methodList: ["test", "toString"],  
            })  
          })  
        }  
        Web({ src: $rawfile('index.html'), controller: this.controller })  
          .javaScriptAccess(true)  
      }  
    }  
  }  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```html    
 <!-- index.html -->  <!DOCTYPE html>  <html>      <meta charset="utf-8">      <body>          Hello world!      </body>      <script type="text/javascript">      function htmlTest() {          str = objName.test("test function")          console.log('objName.test result:'+ str)      }  </script>  </html>    
```    
  
    
### deleteJavaScriptRegister<sup>(deprecated)</sup>    
删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。删除后立即生效，无须调用[refresh](#refreshdeprecated)接口。  
从API version 9开始不再维护，建议使用[deleteJavaScriptRegister<sup>9+</sup>](../apis/js-apis-webview.md#deletejavascriptregister)代替。  
 **调用形式：**     
- deleteJavaScriptRegister(name: string)  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#deleteJavaScriptRegister。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 注册对象的名称，可在网页侧JavaScript中通过此名称调用应用侧JavaScript对象。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
    @State name: string = 'Object'  
  
    build() {  
      Column() {  
        Button('deleteJavaScriptRegister')  
          .onClick(() => {  
            this.controller.deleteJavaScriptRegister(this.name)  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### getHitTest<sup>(deprecated)</sup>    
获取当前被点击区域的元素类型。  
从API version 9开始不再维护，建议使用[getHitTest<sup>9+</sup>](../apis/js-apis-webview.md#gethittest)代替。  
 **调用形式：**     
- getHitTest(): HitTestType  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#getHitTest。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| HitTestType | 被点击区域的元素类型。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('getHitTest')  
          .onClick(() => {  
            let hitType = this.controller.getHitTest()  
            console.log("hitType: " + hitType)  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### requestFocus<sup>(deprecated)</sup>    
使当前web页面获取焦点。  
从API version 9开始不再维护，建议使用[requestFocus<sup>9+</sup>](../apis/js-apis-webview.md#requestfocus)代替。  
 **调用形式：**     
- requestFocus()  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#requestFocus。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('requestFocus')  
          .onClick(() => {  
            this.controller.requestFocus()  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### accessBackward<sup>(deprecated)</sup>    
当前页面是否可后退，即当前页面是否有返回历史记录。  
从API version 9开始不再维护，建议使用[accessBackward<sup>9+</sup>](../apis/js-apis-webview.md#accessbackward)代替。  
 **调用形式：**     
- accessBackward(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#accessBackward。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 可以后退返回true,否则返回false。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('accessBackward')  
          .onClick(() => {  
            let result = this.controller.accessBackward()  
            console.log('result:' + result)  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### accessForward<sup>(deprecated)</sup>    
当前页面是否可前进，即当前页面是否有前进历史记录。  
从API version 9开始不再维护，建议使用[accessForward<sup>9+</sup>](../apis/js-apis-webview.md#accessforward)代替。  
 **调用形式：**     
- accessForward(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#accessForward。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 可以前进返回true,否则返回false。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('accessForward')  
          .onClick(() => {  
            let result = this.controller.accessForward()  
            console.log('result:' + result)  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### accessStep<sup>(deprecated)</sup>    
当前页面是否可前进或者后退给定的step步。  
从API version 9开始不再维护，建议使用[accessStep<sup>9+</sup>](../apis/js-apis-webview.md#accessstep)代替。  
 **调用形式：**     
- accessStep(step: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#accessStep。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| step<sup>(deprecated)</sup> | number | true | 要跳转的步数，正数代表前进，负数代表后退。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 页面是否前进或后退 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
    @State steps: number = 2  
  
    build() {  
      Column() {  
        Button('accessStep')  
          .onClick(() => {  
            let result = this.controller.accessStep(this.steps)  
            console.log('result:' + result)  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### backward<sup>(deprecated)</sup>    
按照历史栈，后退一个页面。一般结合accessBackward一起使用。  
从API version 9开始不再维护，建议使用[backward<sup>9+</sup>](../apis/js-apis-webview.md#backward)代替。  
 **调用形式：**     
- backward()  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#backward。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('backward')  
          .onClick(() => {  
            this.controller.backward()  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### forward<sup>(deprecated)</sup>    
按照历史栈，前进一个页面。一般结合accessForward一起使用。  
从API version 9开始不再维护，建议使用[forward<sup>9+</sup>](../apis/js-apis-webview.md#forward)代替。  
 **调用形式：**     
- forward()  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.web.webview.webview.WebviewController#forward。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
```ts  
  // xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('forward')  
          .onClick(() => {  
            this.controller.forward()  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
### getCookieManager<sup>(deprecated)</sup>    
获取web组件cookie管理对象。  
从API version 9开始不再维护，建议使用[getCookie](../apis/js-apis-webview.md#getcookie)代替。  
 **调用形式：**     
- getCookieManager(): WebCookie  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| WebCookie | web组件cookie管理对象，参考[WebCookie](#webcookiedeprecated)定义。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
  @Entry  
  @Component  
  struct WebComponent {  
    controller: WebController = new WebController()  
  
    build() {  
      Column() {  
        Button('getCookieManager')  
          .onClick(() => {  
            let cookieManager = this.controller.getCookieManager()  
          })  
        Web({ src: 'www.example.com', controller: this.controller })  
      }  
    }  
  }  
    
```    
  
    
## WebOptions  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| src | string \| Resource | false | true |  |  
| controller | WebController \| WebviewController | false | true |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Web(value: WebOptions)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(8+)</sup> | WebOptions | true |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| javaScriptAccess | null |  |  
| fileAccess | null |  |  
| domStorageAccess | null |  |  
| imageAccess | null |  |  
| mixedMode | null |  |  
| zoomAccess | null |  |  
| geolocationAccess | null |  |  
| javaScriptProxy | null |  |  
| password<sup>(deprecated)</sup> | null |  |  
| cacheMode | null |  |  
| darkMode<sup>9+</sup> | null |  |  
| forceDarkAccess<sup>9+</sup> | null |  |  
| mediaOptions<sup>10+</sup> | null |  |  
| tableData<sup>(deprecated)</sup> | null |  |  
| wideViewModeAccess<sup>(deprecated)</sup> | null |  |  
| overviewModeAccess | null |  |  
| textZoomAtio<sup>(deprecated)</sup> | null |  |  
| textZoomRatio<sup>9+</sup> | null |  |  
| databaseAccess | null |  |  
| initialScale<sup>9+</sup> | null |  |  
| userAgent<sup>(deprecated)</sup> | null |  |  
| mediaPlayGestureAccess<sup>9+</sup> | null |  |  
| multiWindowAccess<sup>9+</sup> | null |  |  
| webStandardFont<sup>9+</sup> | null |  |  
| webSerifFont<sup>9+</sup> | null |  |  
| webSansSerifFont<sup>9+</sup> | null |  |  
| webFixedFont<sup>9+</sup> | null |  |  
| webFantasyFont<sup>9+</sup> | null |  |  
| webCursiveFont<sup>9+</sup> | null |  |  
| defaultFixedFontSize<sup>9+</sup> | null |  |  
| defaultFontSize<sup>9+</sup> | null |  |  
| minFontSize<sup>9+</sup> | null |  |  
| minLogicalFontSize<sup>9+</sup> | null |  |  
| blockNetwork<sup>9+</sup> | null |  |  
| horizontalScrollBarAccess<sup>9+</sup> | null |  |  
| verticalScrollBarAccess<sup>9+</sup> | null |  |  
| pinchSmooth<sup>9+</sup> | null |  |  
| allowWindowOpenMethod<sup>10+</sup> | null |  |  
    
### onlineImageAccess<sup>(deprecated)</sup>    
onlineImageAccess(onlineImageAccess: boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| onlineImageAccess<sup>(8+)</sup> | boolean | true | 设置是否允许从网络加载图片资源。 |  
    
### onPageEnd<sup>(deprecated)</sup>    
onPageEnd(callback: (event?: {     /**      * The url of page.      *      * @syscap SystemCapability.Web.Webview.Core      * @crossplatform      * @since 10      */     url: string   }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onPageBegin<sup>(deprecated)</sup>    
onPageBegin(callback: (event?: {     /**      * The url of page.      *      * @syscap SystemCapability.Web.Webview.Core      * @crossplatform      * @since 10      */     url: string   }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onProgressChange<sup>(deprecated)</sup>    
onProgressChange(callback: (event?: { newProgress: number }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onTitleReceive<sup>(deprecated)</sup>    
onTitleReceive(callback: (event?: { title: string }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onGeolocationHide<sup>(deprecated)</sup>    
onGeolocationHide(callback: () => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onGeolocationShow<sup>(deprecated)</sup>    
onGeolocationShow(callback: (event?: { origin: string, geolocation: JsGeolocation }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onRequestSelected<sup>(deprecated)</sup>    
onRequestSelected(callback: () => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onAlert<sup>(deprecated)</sup>    
onAlert(callback: (event?: { url: string, message: string, result: JsResult }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onBeforeUnload<sup>(deprecated)</sup>    
onBeforeUnload(callback: (event?: { url: string, message: string, result: JsResult }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onConfirm<sup>(deprecated)</sup>    
onConfirm(callback: (event?: { url: string, message: string, result: JsResult }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onPrompt<sup>(deprecated)</sup>    
onPrompt(callback: (event?: { url: string, message: string, value: string, result: JsResult }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onConsole<sup>(deprecated)</sup>    
onConsole(callback: (event?: { message: ConsoleMessage }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onErrorReceive<sup>(deprecated)</sup>    
onErrorReceive(callback: (event?: {     /**      * The url of error event.      *      * @syscap SystemCapability.Web.Webview.Core      * @crossplatform      * @since 10      */     request: WebResourceRequest,     /**      * The information of error event.      *      * @syscap SystemCapability.Web.Webview.Core      * @crossplatform      * @since 10      */     error: WebResourceError   }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onHttpErrorReceive<sup>(deprecated)</sup>    
onHttpErrorReceive(callback: (event?: { request: WebResourceRequest,     response: WebResourceResponse }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onDownloadStart<sup>(deprecated)</sup>    
onDownloadStart(callback: (event?: { url: string, userAgent: string, contentDisposition: string, mimetype: string,     contentLength: number }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onRefreshAccessedHistory<sup>(deprecated)</sup>    
onRefreshAccessedHistory(callback: (event?: { url: string, isRefreshed: boolean }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onUrlLoadIntercept    
onUrlLoadIntercept(callback: (event?: { data: string | WebResourceRequest }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | (event?: { data: string \| WebResourceRequest }) => boolean | true |  |  
    
### onSslErrorReceive    
onSslErrorReceive(callback: (event?: { handler: Function, error: object }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | (event?: { handler: Function, error: object }) => void | true |  |  
    
### onShowFileSelector<sup>(deprecated)</sup>    
onShowFileSelector(callback: (event?: { result: FileSelectorResult,     fileSelector: FileSelectorParam }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onRenderExited    
onRenderExited(callback: (event?: { detail: object }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | (event?: { detail: object }) => boolean | true |  |  
    
### onFileSelectorShow    
onFileSelectorShow(callback: (event?: { callback: Function, fileSelector: object }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | (event?: { callback: Function, fileSelector: object }) => void | true |  |  
    
### onResourceLoad<sup>(deprecated)</sup>    
onResourceLoad(callback: (event: { url: string }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onFullScreenExit<sup>(deprecated)</sup>    
onFullScreenExit(callback: () => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onFullScreenEnter<sup>(deprecated)</sup>    
onFullScreenEnter(callback: (event: { handler: FullScreenExitHandler }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onScaleChange<sup>(deprecated)</sup>    
onScaleChange(callback: (event: { oldScale: number, newScale: number }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onHttpAuthRequest<sup>(deprecated)</sup>    
onHttpAuthRequest(callback: (event?: { handler: HttpAuthHandler, host: string, realm: string }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onInterceptRequest<sup>(deprecated)</sup>    
onInterceptRequest(callback: (event?: { request: WebResourceRequest }) => WebResourceResponse)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onPermissionRequest<sup>(deprecated)</sup>    
onPermissionRequest(callback: (event?: { request: PermissionRequest }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onScreenCaptureRequest<sup>(deprecated)</sup>    
onScreenCaptureRequest(callback: (event?: { handler: ScreenCaptureHandler }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onContextMenuShow<sup>(deprecated)</sup>    
onContextMenuShow(callback: (event?: { param: WebContextMenuParam, result: WebContextMenuResult }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onSearchResultReceive<sup>(deprecated)</sup>    
onSearchResultReceive(callback: (event?: { activeMatchOrdinal: number, numberOfMatches: number, isDoneCounting: boolean }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onScroll<sup>(deprecated)</sup>    
onScroll(callback: (event: { xOffset: number, yOffset: number }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onSslErrorEventReceive<sup>(deprecated)</sup>    
onSslErrorEventReceive(callback: (event: { handler: SslErrorHandler, error: SslError }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onClientAuthenticationRequest<sup>(deprecated)</sup>    
onClientAuthenticationRequest(callback: (event: {handler : ClientAuthenticationHandler, host : string, port : number,     keyTypes : Array<string>, issuers : Array<string>}) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onWindowNew<sup>(deprecated)</sup>    
onWindowNew(callback: (event: {isAlert: boolean, isUserTrigger: boolean, targetUrl: string,     handler: ControllerHandler}) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onWindowExit<sup>(deprecated)</sup>    
onWindowExit(callback: () => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onInterceptKeyEvent<sup>(deprecated)</sup>    
onInterceptKeyEvent(callback: (event: KeyEvent) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onTouchIconUrlReceived<sup>(deprecated)</sup>    
onTouchIconUrlReceived(callback: (event: {url: string,     precomposed: boolean}) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onFaviconReceived<sup>(deprecated)</sup>    
onFaviconReceived(callback: (event: { favicon: PixelMap }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onPageVisible<sup>(deprecated)</sup>    
onPageVisible(callback: (event: { url: string }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onDataResubmitted<sup>(deprecated)</sup>    
onDataResubmitted(callback: (event: { handler: DataResubmissionHandler }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onAudioStateChanged<sup>(deprecated)</sup>    
onAudioStateChanged(callback: (event: { playing: boolean }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onFirstContentfulPaint<sup>(deprecated)</sup>    
onFirstContentfulPaint(callback: (event?: { navigationStartTick: number,     firstContentfulPaintMs: number }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onLoadIntercept<sup>(deprecated)</sup>    
onLoadIntercept(callback: (event: { data: WebResourceRequest }) => boolean)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onControllerAttached<sup>(deprecated)</sup>    
onControllerAttached(callback: () => void)    
 **系统能力：** SystemCapability.Web.Webview.Core    
### onOverScroll<sup>(deprecated)</sup>    
onOverScroll(callback: (event: { xOffset: number, yOffset: number }) => void)    
 **系统能力：** SystemCapability.Web.Webview.Core  
