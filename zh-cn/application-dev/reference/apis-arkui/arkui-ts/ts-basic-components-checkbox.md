# Checkbox

提供多选框组件，通常用于某选项的打开或关闭。

>  **说明：**
>
>  API version 11开始，Checkbox默认样式由圆角方形变为圆形。
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## 接口

Checkbox(options?: CheckboxOptions)

多选框组件。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                        | 必填 | 描述               |
| ------- | ------------------------------------------- | ---- | ------------------ |
| options | [CheckboxOptions](#checkboxoptions对象说明) | 否   | 配置复选框的参数。 |

## CheckboxOptions对象说明

| 名称  | 类型 | 必填  | 描述 |
| --------| --------| ------ | -------- |
| name    | string | 否 | 用于指定多选框名称。 |
| group   | string | 否 | 用于指定多选框所属群组的名称（即所属CheckboxGroup的名称）。<br/>**说明：** <br/>未配合使用[CheckboxGroup](ts-basic-components-checkboxgroup.md)组件时，此值无用。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### select

select(value: boolean)

设置多选框是否选中。

从API version 10开始，该属性支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 描述                               |
| ------ | ------- | ---- | ---------------------------------- |
| value  | boolean | 是   | 多选框是否选中。<br/>默认值：false |

### selectedColor

selectedColor(value: ResourceColor)

设置多选框选中状态颜色。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 描述                                                         |
| ------ | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 多选框选中状态颜色。<br/>默认值：$r('sys.color.ohos_id_color_text_primary_activated')。<br/>异常值按照默认值处理。 |

### unselectedColor<sup>10+</sup>

unselectedColor(value: ResourceColor)

设置多选框非选中状态边框颜色。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 描述                       |
| ------ | ------------------------------------------ | ---- | -------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 多选框非选中状态边框颜色。<br/>默认值：'#33ffffff'。 |

### mark<sup>10+</sup>

mark(value: MarkStyle)

设置多选框内部图标样式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 描述                 |
| ------ | --------------------------------- | ---- | -------------------- |
| value  | [MarkStyle](#markstyle10对象说明) | 是   | 多选框内部图标样式。 |

### shape<sup>11+</sup>

shape(value: CheckBoxShape)

设置CheckBox组件形状, 包括圆形和圆角方形。

**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 描述                                                         |
| ------ | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [CheckBoxShape](#checkboxshape11枚举类型说明) | 是   | CheckBox组件形状, 包括圆形和圆角方形。<br/>默认值：CheckBoxShape.CIRCLE |

## 事件

支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

### onChange

onChange(callback: (value: boolean) => void)

当选中状态发生变化时，触发该回调。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 描述                                              |
| ------ | ------- | ---- | ------------------------------------------------- |
| value  | boolean | 是   | 返回true时，表示已选中。返回false时，表示未选中。 |

## MarkStyle<sup>10+</sup>对象说明

| 名称        | 类型                                       | 必填 | 默认值      | 描述                                                         |
| ----------- | ------------------------------------------ | ---- | ----------- | ------------------------------------------------------------ |
| strokeColor | [ResourceColor](ts-types.md#resourcecolor) | 否   | Color.White | 内部图标颜色。                                               |
| size        | [Length](ts-types.md#length)               | 否   | -           | 内部图标大小，单位vp。默认大小与多选框组件宽度设置值一致。<br />不支持百分比形式设置。当设置为非法值时，按照默认值处理。 |
| strokeWidth | [Length](ts-types.md#length)               | 否   | 2           | 内部图标粗细，单位vp。不支持百分比形式设置。当设置为非法值时，按照默认值处理。 |

## CheckBoxShape<sup>11+</sup>枚举类型说明

| 枚举名称       | 枚举值 | 描述     |
| -------------- | ------ | -------- |
| CIRCLE         | 0      | 圆形     |
| ROUNDED_SQUARE | 1      | 圆角方形 |

## 示例

### 示例1

```ts
// xxx.ets
@Entry
@Component
struct CheckboxExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
        .select(true)
        .selectedColor(0xed6f21)
        .shape(CheckBoxShape.CIRCLE)
        .onChange((value: boolean) => {
          console.info('Checkbox1 change is' + value)
        })
      Checkbox({ name: 'checkbox2', group: 'checkboxGroup' })
        .select(false)
        .selectedColor(0x39a2db)
        .shape(CheckBoxShape.ROUNDED_SQUARE)
        .onChange((value: boolean) => {
          console.info('Checkbox2 change is' + value)
        })
    }
  }
}
```


![](figures/checkbox.gif)

### 示例2

```ts
// xxx.ets
@Entry
@Component
struct Index {

  build() {
    Row() {
      Column() {
        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
          Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
            .selectedColor(0x39a2db)
            .shape(CheckBoxShape.ROUNDED_SQUARE)
            .onChange((value: boolean) => {
              console.info('Checkbox1 change is'+ value)
            })
            .mark({
              strokeColor:Color.Black,
              size: 50,
              strokeWidth: 5
            })
            .unselectedColor(Color.Red)
            .width(30)
            .height(30)
          Text('Checkbox1').fontSize(20)
        }
        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
          Checkbox({ name: 'checkbox2', group: 'checkboxGroup' })
            .selectedColor(0x39a2db)
            .shape(CheckBoxShape.ROUNDED_SQUARE)
            .onChange((value: boolean) => {
              console.info('Checkbox2 change is' + value)
            })
            .width(30)
            .height(30)
          Text('Checkbox2').fontSize(20)
        }
      }
      .width('100%')
    }
    .height('100%')
  }
}
```


![](figures/checkbox2.gif)
