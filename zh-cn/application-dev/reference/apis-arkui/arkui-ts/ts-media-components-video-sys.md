# Video (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sd-wu-->
<!--SE: @sunbees-->
<!--TSE: @liuli0427-->

用于播放视频文件并控制其播放状态的组件。 

> **说明：**
>
> 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[Video](ts-media-components-video.md)。

## 属性

### surfaceBackgroundColor<sup>15+</sup>

surfaceBackgroundColor(color: ColorMetrics)

设置Video组件中surfacenode的背景色。

**系统接口：** 此接口为系统接口

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 |       类型    | 必填 |           说明                |
| ------ | ------------ | ---- | ---------------------------- |
| color  | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | 是   | 设置Video组件中surfacenode的背景色，仅支持黑色和透明色两种。其他颜色设置将默认为黑色。<br/>默认值：Color.Black |
