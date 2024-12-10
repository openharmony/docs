# 事件错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 1500001 want中Action为空

**错误信息**
The action field in the want parameter is null.

**错误描述**
发送事件的`want`中的`Action`属性为空时系统会产生此错误码。

**可能原因**
发送事件的`want`中的`Action`属性为空。

**处理步骤**
检查传入`want`的`Action`属性是否为空。

##  1500002 沙箱应用无法发送公共事件

**错误信息**
A sandbox application cannot send common events.

**错误描述**
沙箱应用无法发送公共事件。

**可能原因**
事件发送方应用为沙箱应用，发送事件会被拦截。

**处理步骤**
沙箱应用无法发送公共事件，发送公共事件前确认是否为沙箱应用。

##  1500003 事件发送频率过高

**错误信息**
Too many common events are sent in a short period of time.

**错误描述**
应用发送事件过于频繁。

**可能原因**
短时间内应用发送过多事件。

**处理步骤**
检查应用是否过于频繁地发送事件。

##  1500004 无法发送系统公共事件

**错误信息**
A third-party application cannot send system common events.

**错误描述**
当前应用无法发送系统公共事件。

**可能原因**
非系统应用或非系统服务发送系统公共事件。

**处理步骤**
确认当前应用是否为系统应用，或当前服务是否为系统服务。

##  1500005 未找到订阅者

**错误信息**
The subscriber is not found.

**错误描述**
找不到订阅者。

**可能原因**
订阅者被删除。

**处理步骤**
检查是否有重复取消订阅。

##  1500006 无效userId

**错误信息**
Invalid userId.

**错误描述**
无效的userId。

**可能原因**
和系统`userId`不一致或不是系统应用或系统服务进程。

**处理步骤**
1. 检查当前`userId`是否和系统`userId`一致。
2. 检查当前应用是否为系统应用或系统服务。

##  1500007 IPC请求发送失败

**错误信息**
Failed to send the message to the common event service.

**错误描述**
`IPC`发送请求失败。

**可能原因**
没有成功创建连接对象。

**处理步骤**
请勿频繁建立链接，稍后重新尝试。

##  1500008 公共事件服务端初始化失败

**错误信息**
Failed to initialize the common event service.

**错误描述**
服务端发生错误。

**可能原因**
服务端处理数据时发现业务异常。

**处理步骤**
稍后重新尝试。

##  1500009 获取系统参数失败

**错误信息**
Failed to obtain system parameters.

**错误描述**
处理业务时系统发生异常，如获取系统当前时间失败。

**可能原因**
系统故障，获取系统当前时间发生异常。

**处理步骤**
稍后重新尝试。
