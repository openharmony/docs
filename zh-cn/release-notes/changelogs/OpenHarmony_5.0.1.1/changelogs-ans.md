# 事件通知子系统Changelog

## NotificationRequest中largeIcon属性的行为变更

**访问级别**

公开接口

**变更原因**

解决通知图标超大导致通知发布失败的问题。

**变更影响**

该变更为兼容性变更。

变更前：
当largeIcon超大时，通知会被拦截，导致发布失败。

变更后：
当largeIcon超大时，通知可以正常发布，不展示图标，只展示文本内容。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.1.1 版本开始。

**变更的接口/组件**
NotificationRequest的属性：largeIcon。

**适配指导**
无需适配，兼容性变更。
