# MenuItemGroup
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Armstrong15-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

该组件用来展示菜单MenuItem的分组。

> **说明：**
>
> 该组件从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

包含[MenuItem](ts-basic-components-menuitem.md)子组件。

## 接口

MenuItemGroup(value?: MenuItemGroupOptions)

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                  | 必填 | 说明                                        |
| ------ | ----------------------------------------------------- | ---- | ------------------------------------------- |
| value  | [MenuItemGroupOptions](#menuitemgroupoptions对象说明) | 否   | 包含设置MenuItemGroup的标题和尾部显示信息。 |

## MenuItemGroupOptions对象说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型                                                         | 只读 | 可选 | 说明                          |
| ------ | ------------------------------------------------------------ | ---- | ---- | ----------------------------- |
| header | [ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8) | 否   | 是   | 设置对应group的标题显示信息。 |
| footer | [ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8) | 否   | 是   | 设置对应group的尾部显示信息。 |

## 示例

详见[Menu组件示例](ts-basic-components-menu.md#示例)。
