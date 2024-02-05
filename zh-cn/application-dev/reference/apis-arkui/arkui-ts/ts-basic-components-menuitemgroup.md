# MenuItemGroup

该组件用来展示菜单MenuItem的分组。

> **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

包含[MenuItem](ts-basic-components-menuitem.md)子组件。

## 接口

MenuItemGroup(value?: MenuItemGroupOptions)

**参数：**

| 参数  | 类型                                                                                   | 必填 | 参数描述                                    |
| ----- | -------------------------------------------------------------------------------------- | ---- | ------------------------------------------- |
| value | [MenuItemGroupOptions](ts-basic-components-menuitemgroup.md#menuitemgroupoptions类型说明) | 否   | 包含设置MenuItemGroup的标题和尾部显示信息。 |

## MenuItemGroupOptions类型说明

| 名称   | 类型                                                                                      | 必填 | 描述                          |
| ------ | ----------------------------------------------------------------------------------------- | ---- | ----------------------------- |
| header | [ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8) | 否   | 设置对应group的标题显示信息。 |
| footer | [ResourceStr](ts-types.md#resourcestr)&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8) | 否   | 设置对应group的尾部显示信息。 |

## 示例

详见[Menu组件示例](ts-basic-components-menu.md#示例)。
