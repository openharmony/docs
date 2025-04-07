# XComponent

提供用于图形绘制和媒体数据写入的Surface，XComponent负责将其嵌入到视图中，支持应用自定义Surface位置和大小。

> **说明：**
>
> 该组件从API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[XComponent](ts-basic-components-xcomponent.md)。

## 接口

## XComponentOptions<sup>12+</sup>

定义XComponent的具体配置参数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型    | 必填 | 说明                   |
| -------- | ------- | ---- | ---------------------- |
| screenId<sup>17+</sup> | number | 否 | 给组件设置关联屏幕ID，通过此项可在组件上显示关联屏幕画面。 <br>
**系统接口：** 此接口为系统接口。<br>**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。|

  > **说明：**
  >
  > 仅type为SURFACE时有效。
  >
  > 不支持[ArkUI NDK接口](../../../ui/ndk-build-ui-overview.md)创建的XComponent组件。
