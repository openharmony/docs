# 半模态转场 (系统接口)

通过bindSheet属性为组件绑定半模态页面，在组件插入时可通过设置自定义或默认的内置高度确定半模态大小。

>  **说明：**
>
>  从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  不支持路由跳转。
>
> 本文仅介绍当前模块的系统接口，其他公开接口参见[bindSheet](./ts-universal-attributes-sheet-transition.md#bindsheet)。

## SheetOptions

配置半模态页面的可选属性。继承自[BindOptions](./ts-universal-attributes-sheet-transition.md#bindoptions)。

| 名称              | 类型                                       | 必填   | 描述              |
| --------------- | ---------------------------------------- | ---- | --------------- |
| offset<sup>14+</sup>       | [Position](ts-types.md#position) | 是    | 当半模态为底部弹窗时，支持设置底部间距。不支持设置半模态页面的切换高度档位。 <br/> 默认值：x轴为0vp，y轴坐标为0vp。<br/>**系统接口：** 此接口为系统接口。<br/> **系统能力：** SystemCapability.ArkUI.ArkUI.Full|