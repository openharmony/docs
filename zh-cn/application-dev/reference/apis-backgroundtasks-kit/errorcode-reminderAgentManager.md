# reminderAgentManager错误码

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 1700001 通知使能未开启

**错误信息**

Notification is not enabled.

**错误描述**

当调用发布提醒接口时，不允许应用发送通知。

**可能原因**

1. 未申请通知使能权限。
2. 通知使能被关闭。

**处理步骤**

1. 申请通知使能权限弹窗[Notification.requestEnableNotification](../apis-notification-kit/js-apis-notification.md#notificationrequestenablenotification8)。
2. 检查通知使能是否被关闭。

## 1700002 提醒数量超出限制

**错误信息**

The number of reminders exceeds the limit.

**错误描述**

当调用发布提醒接口时，提醒数量超出最大限制。

**可能原因**
<!--RP1-->
1. 从API version10开始，单个普通应用提醒数量不超过30个，单个系统应用提醒数量不超过10000个。API version 9及之前的版本，单个应用提醒数量均不超过30个。
2. 从API version10开始，所有应用提醒数量总和不超过12000个。API version 9及之前的版本，提醒数量总和不超过2000个。

**处理步骤**

删除不必要的提醒。
<!--RP1End-->
## 1700003 提醒不存在

**错误信息**

The reminder does not exist.

**错误描述**

当调用取消提醒接口时，未找到对应的提醒。

**可能原因**

1. 提醒已过期。
2. 提醒已被删除。

**处理步骤**

1. 检查提醒是否有效。
2. 检查提醒是否已被删除。

## 1700004 包名不存在

**错误信息**

The bundle name does not exist.

**错误描述**

未找到传入的包名信息。

**可能原因**

1. 包名不正确。
2. 应用未安装。

**处理步骤**

检查应用包名是否存在。

## 1700007 参数错误

**错误信息**

If the input parameter is not a valid parameter.

**错误描述**

输入参数不是有效参数。

**可能原因**

参数不符合规则。

**处理步骤**

请检查必选参数是否传入，或者传入的参数类型是否错误。对于参数校验失败，阅读参数规格约束，按照可能原因进行排查。