# Notification


## 概述

描述Notification向应用提供通知服务的能力。

**系统能力：** SystemCapability.Notification.Notification

**起始版本：** 13


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [notification.h](notification_8h.md) | 声明通知服务相关的API。<br/>**引用文件**：&lt;NotificationKit/notification.h&gt;<br/>**库**：libohnotification.so|


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_Notification_IsNotificationEnabled](#oh_notification_isnotificationenabled)| 查询当前应用通知使能状态。 |

## 函数说明

### OH_Notification_IsNotificationEnabled

```cpp
bool OH_Notification_IsNotificationEnabled(void)
```

**描述**

查询当前应用通知使能状态。

**起始版本：** 13

**返回：**

返回查询结果，true表示当前应用已使能通知，false表示当前应用未使能通知。
