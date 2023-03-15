# Webview错误码


## 17100001 WebviewController没有和具体的Web组件关联

**错误信息**

Init error. The WebviewController must be associated with a Web compoent.

**错误描述**

WebviewController还没有和具体的Web组件关联，无法进行相应的操作。

**处理步骤**

请检查WebviewController对象是否已与Web组件关联。


## 17100002 Url格式错误

**错误信息**

Invalid url.

**错误描述**

Url格式错误。

**处理步骤**

请检查输入的url是否正确。


## 17100003 resource路径错误

**错误信息**

Invalid resource path or file type.

**错误描述**

resource路径错误。

**可能原因**

资源路径下文件不存在或无法访问。

**处理步骤**

请检查输入的resource路径是否正确。


## 17100004 功能开关未打开

**错误信息**

Function not enable.

**错误描述**

功能开关未打开。

**处理步骤**

请检查相关功能开关是否已配置打开，如该功能对应的XXXAccess是否配置为true。


## 17100005 cookie value格式错误

**错误信息**

Invalid cookie value.

**错误描述**

cookie value格式错误。

**可能原因**

不支持的cookie value类型。

**处理步骤**

请检查输入的value是否正确。


## 17100006 无法注册message port回调

**错误信息**

Can not register message event using this port.

**错误描述**

无法注册message port回调。

**可能原因**

port可能已经关闭。

**处理步骤**

请检查port是否关闭。


## 17100007 无效的前进后退操作

**错误信息**

Invalid back or forward operation.

**错误描述**

无效的前进后退操作。

**可能原因**

1. 浏览历史记录被清除。

2. 没有前进或后退对应的浏览操作。

**处理步骤**

1. 是否调用clearHistory。

2. 实际操作中是否有浏览对应跳转的网页数。


## 17100008 删除不存在的javaScriptProxy

**错误信息**

Cannot delete JavaScriptProxy.

**错误描述**

删除不存在的javaScriptProxy。

**可能原因**

传入的javaScriptProxy之前没有注册。

**处理步骤**

检查传入的javaScriptProxy是否注册成功。


## 17100009 上一次的zoomin/out操作缩放失败

**错误信息**

Cannot zoom in or zoom out.

**错误描述**

上一次的zoomin/out操作缩放失败。

**可能原因**

已经达到最大或者最小缩放比例。

**处理步骤**

检查当前的页面比例是否已经达到最大或者最小的缩放尺寸。


## 17100010 无法使用该端口发送消息

**错误信息**

Cannot post message using this port.

**错误描述**

无法使用该端口发送消息。

**可能原因**

该端口已关闭，或者对端端口已关闭。

**处理步骤**

1. 请确认本端端口是否调用了close接口。

2. 请确认本端是否设置了port的onMessageEvent回调。


## 17100011 输入参数origin错误

**错误信息**

Invalid origin.

**错误描述**

输入参数origin错误。

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

2. 如果已经使用，检查调用失败原因，如databaseAccess开发是否打开。

