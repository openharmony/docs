# Webview错误码
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @kurli1-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 17100001 WebviewController没有和具体的Web组件关联

**错误信息**

Init error. The WebviewController must be associated with a Web component.

**错误描述**

WebviewController尚未与具体Web组件关联，无法进行相应操作。

**可能原因**

WebviewController还没有和具体的Web组件关联。

**处理步骤**

请检查WebviewController对象是否已与Web组件关联，可以通过[onControllerAttached()](./arkts-basic-components-web-events.md#oncontrollerattached10)接口进行检查。<!--RP1--><!--RP1End-->


## 17100002 URL格式错误

**错误信息**

URL error. Possible causes: 1. No valid cookie found for the specified URL. 2. The webpage corresponding to the URL is invalid, or the URL length exceeds 2\*1024\*1024.

**错误描述**

URL错误，可能原因：

1. 未找到指定URL的有效Cookie。

2. 该URL对应的网页无效，或URL长度超过2\*1024\*1024。

**可能原因**

1. 未找到指定URL的有效Cookie。

2. 该URL对应的网页无效，或URL长度超过2\*1024\*1024。

**处理步骤**

请检查输入的URL是否正确且URL长度不超过2\*1024\*1024。


## 17100003 resource路径错误

**错误信息**

1. Invalid resource path or file type.
2. Calling a JS method that returns an empty ArrayBuffer via runJavaScript.

**错误描述**

1. resource路径错误。
2. 通过runJavaScript调用H5侧的方法，这个方法返回了空的ArrayBuffer。

**可能原因**

1. 资源路径下文件不存在或无法访问。
2. 通过runJavaScript调用H5侧的方法，这个方法返回了空的ArrayBuffer。

**处理步骤**

1. 请检查输入的resource路径是否正确。
2. 使用runJavaScriptExt接口替代runJavaScript接口。

## 17100004 功能开关未打开

**错误信息**

Function not enabled.

**错误描述**

功能开关未打开。

**可能原因**

相关功能未设置、开关未打开或错误调用。

**处理步骤**

请检查相关功能开关是否已配置打开，如该功能对应的XXXAccess是否配置为true，或检测当前接口是否支持并发。


## 17100005 cookie value格式错误

**错误信息**

The provided cookie value is invalid. It must follow the format specified in RFC 6265.

**错误描述**

cookie value格式错误。

**可能原因**

不支持的cookie value类型。

**处理步骤**

请检查输入的value是否正确。


## 17100006 无法注册message port回调

**错误信息**

Failed to register a message event for the port.

**错误描述**

无法注册message port回调。

**可能原因**

port可能已经关闭。

**处理步骤**

请检查port是否关闭。


## 17100008 删除不存在的JavaScriptProxy

**错误信息**

Failed to delete JavaScriptProxy because it does not exist.

**错误描述**

删除不存在的JavaScriptProxy。

**可能原因**

传入的JavaScriptProxy之前没有注册。

**处理步骤**

检查传入的JavaScriptProxy是否注册成功。


## 17100010 无法使用该端口发送消息

**错误信息**

Failed to post messages through the port.

**错误描述**

无法使用该端口发送消息。

**可能原因**

该端口已关闭，或者对端端口已关闭。

**处理步骤**

1. 请确认本端端口是否调用了close接口。

2. 请确认本端是否设置了port的onMessageEvent回调。


## 17100011 输入参数origin错误

**错误信息**

Invalid origin.The origin format must follow defined in RFC 6454.

**错误描述**

输入参数origin错误。origin格式必须遵循RFC 6454中定义的格式。

**可能原因**

1. 参数origin为空。

2. 参数origin不合法。

**处理步骤**

检查输入的参数。


## 17100012 无可获取的webstorage源

**错误信息**

Invalid web storage origin.

**错误描述**

无可获取的webstorage源。

**可能原因**

没有使用相关的JS数据库API。

**处理步骤**

1. 检查是否有使用JS数据库API。

2. 如果已经使用，检查调用失败原因，如databaseAccess开关是否打开。


## 17100013 预连接时，输入socket数目无效

**错误信息**

The number of sockets to be preconnected is invalid.

**错误描述**

预连接时，输入socket的数目是无效的。

**可能原因**

预连接时，输入socket的数目小于等于0，或者大于6。

**处理步骤**

检查输入的socket的数目范围是否大于0且小于等于6。


## 17100014 类型和值不匹配

**错误信息**

The type and value of the message do not match.

**错误描述**

消息的类型和值不匹配。

**可能原因**

获取消息的值和消息本身的类型不匹配。

**处理步骤**

需要根据消息的类型调用相应的接口来获取消息的值。举例：如获取到的类型是BOOLEAN，则需要调用GetBoolean接口来获取布尔值。


## 17100016 下载任务没有处于暂停状态

**错误信息**

The download task is not paused.

**错误描述**

下载任务没有处于暂停状态。

**可能原因**

在下载没有暂停的情况下调用了WebDownloadItem.resume。

**处理步骤**

下载并没有被暂停，不需要恢复。


## 17100018 没有设置一个委托类来接收下载状态

**错误信息**

No WebDownloadDelegate has been set yet.

**错误描述**

没有设置一个委托类来接收下载状态。

**可能原因**

没有设置委托类就调用了WebDownloadManager.resumeDownload。

**处理步骤**

先通过WebDownloadManager.setDownloadDelegate设置一个委托类。

## 17100019 下载还没开始

**错误信息**

The download task is not started yet.

**错误描述**

下载任务还未开始。

**可能原因**

下载任务还没开始，此时调用pause/resume是无效的。

**处理步骤**

需要在WebDownloadDelegate.onBeforeDownload中调用start('xxx')并指定下载路径。

## 17100020 注册自定义协议失败

**错误信息**

Failed to register custom schemes.

**错误描述**

注册自定义协议失败。

**可能原因**

在ArkWeb引擎初始化之后才设置自定义协议。

**处理步骤**

注册自定义协议需要在ArkWeb引擎初始化之前设置。

## 17100021 WebResourceHandler已经失效

**错误信息**

The resource handler is invalid.

**错误描述**

WebResourceHandler已经失效。

**可能原因**

1.对应的请求在WebSchemeHandler中没有拦截；

2.该请求拦截在构造返回体之前，因为某些原因已经请求结束；

3.该WebResourceHandler已经调用过didFinish和didFail。


**处理步骤**

请勿在以上所说的情况下调用WebResourceHandler的接口。

## 17100022 WebHttpBodyStream初始化失败

**错误信息**

Failed to initialize the HTTP body stream.

**错误描述**

WebHttpBodyStream数据初始化失败。

**可能原因**

发起的POST等类型的请求中，携带的数据不合法。例如里面数据流中有文件类型的数据，但是该文件路径不存在，则数据流初始化失败。

**处理步骤**

检查发起的POST等类型的请求中，携带的数据是否合法。

## 17100023 使用了不被允许的端口号

**错误信息**

The port number is not within the allowed range.

**错误描述**

使用的端口号不在允许的取值范围内。

**可能原因**

由于部分端口号（例如小于1024的端口号）作为熟知或系统端口，在操作系统上需要特权才能开启，因此禁止应用使用这些端口号。

**处理步骤**

检查使用的端口号是否在允许的取值范围内。

## 17100024 AIPageCommand格式错误

**错误信息**

Command format error. The command parameter does not conform to the JSON format requirements.

**错误描述**

AIPageCommand参数格式错误。

**可能原因**

调用[WebviewController.executeAIPageCommand](arkts-apis-webview-WebviewController.md#executeaipagecommand)时，传入的command参数不是合法的JSON对象字符串，或命令字段不符合格式要求。

**处理步骤**

检查command参数是否为合法的JSON对象字符串，并确认JSON对象中包含字符串类型的method字段。

## 17100101 使用了错误的网络错误码

**错误信息**

The errorCode is either ARKWEB_NET_OK or outside the range of error codes in WebNetErrorList.

**错误描述**

网络错误码为ARKWEB_NET_OK或者超出了WebNetErrorList中的错误码范围。

**可能原因**

使用的错误码不在[WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist)范围内，或者调用didFail接口时使用了NET_OK错误码。

**处理步骤**

检查使用的错误码是否在[WebNetErrorList](arkts-apis-netErrorList.md#webneterrorlist)范围内，或者调用didFail时是否使用了NET_OK错误码。
