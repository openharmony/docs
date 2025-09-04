# 状态管理V1装饰器参数
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ProvideOptions

[\@Provide](../../../ui/state-management/arkts-provide-and-consume.md)参数，用于配置\@Provide的支持重写，具体例子可见[\@Provide支持allowOverride参数](../../../ui/state-management/arkts-provide-and-consume.md#provide支持allowoverride参数)。

**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
|allowOverride|string|否|配置\@Provide支持重写。默认不支持重写。|
