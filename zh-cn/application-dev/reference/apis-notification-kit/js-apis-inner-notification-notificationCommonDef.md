# NotificationCommonDef
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

描述BundleOption信息，即指定应用的包信息。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## BundleOption

**系统能力**：SystemCapability.Notification.Notification

| 名称   | 类型   | 只读 | 可选 | 说明   |
| ------ | ------ | ----| -- |  ------ |
| bundle | string | 否  | 否 | 应用程序的名称。 |
| uid    | number | 否  | 是 | 应用程序的UID。从[ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md)获取，默认为0。 |
