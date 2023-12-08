# CheckboxGroup

多选框群组，用于控制多选框全选或者不全选状态。

>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## 接口

CheckboxGroup(options?: { group?: string })

创建多选框群组，可以控制群组内的Checkbox全选或者不全选，group值相同的Checkbox和CheckboxGroup为同一群组。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数:**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| group | string | 否 | 群组名称。<br/>**说明：** <br/>多个相同群组名称的CheckboxGroup，仅第一个CheckboxGroup生效。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| selectAll | boolean | 设置是否全选。<br/>默认值：false，若同组的[Checkbox](ts-basic-components-checkbox.md)设置了select属性，则Checkbox的优先级高。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>若同组的[Checkbox](ts-basic-components-checkbox.md)显式设置了select属性，则Checkbox的优先级高。<br />从API version 10开始，该属性支持[$$](../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |
| selectedColor | [ResourceColor](ts-types.md#resourcecolor) | 设置被选中或部分选中状态的颜色。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| unselectedColor<sup>10+</sup> | [ResourceColor](ts-types.md#resourcecolor) | 设置非选中状态边框颜色。 |
| mark<sup>10+</sup> | [MarkStyle](#markstyle10对象说明) | 多选框内部图标样式。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称 | 功能描述 |
| -------- | -------- |
| onChange (callback: (event: [CheckboxGroupResult](#checkboxgroupresult对象说明)) => void ) |CheckboxGroup的选中状态或群组内的Checkbox的选中状态发生变化时，触发回调。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。|

## CheckboxGroupResult对象说明

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称     | 类型   | 描述      |
| ------ | ------ | ------- |
| name   | Array&lt;string&gt; | 群组内所有被选中的多选框名称。 |
| status | [SelectStatus](#selectstatus枚举说明) | 选中状态。 |

## SelectStatus枚举说明

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称  | 描述 |
| ----- | -------------------- |
| All   | 群组多选择框全部选择。 |
| Part  | 群组多选择框部分选择。 |
| None  | 群组多选择框全部没有选择。 |

## MarkStyle<sup>10+</sup>对象说明

| 名称        | 类型                                       | 必填 | 默认值      | 描述                                                         |
| ----------- | ------------------------------------------ | ---- | ----------- | ------------------------------------------------------------ |
| strokeColor | [ResourceColor](ts-types.md#resourcecolor) | 否   | Color.White | 内部图标颜色。                                               |
| size        | number&nbsp;\|&nbsp;string                 | 否   | -           | 内部图标大小，单位vp。默认大小与多选框群组组件宽度设置值一致。<br />不支持百分比形式设置。当设置为非法值时，按照默认值处理。 |
| strokeWidth | number&nbsp;\|&nbsp;string                 | 否   | 2           | 内部图标粗细，单位vp。不支持百分比形式设置。当设置为非法值时，按照默认值处理。 |

## 示例

### 示例1

```ts
// xxx.ets
@Entry
@Component
struct CheckboxExample {
  build() {
    Scroll() {
      Column() {
        // 全选按钮
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          CheckboxGroup({ group: 'checkboxGroup' })
            .selectedColor('#007DFF')
            .onChange((itemName: CheckboxGroupResult) => {
              console.info("checkbox group content" + JSON.stringify(itemName))
            })
          Text('Select All').fontSize(14).lineHeight(20).fontColor('#182431').fontWeight(500)
        }

        // 选项1
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })
            .selectedColor('#007DFF')
            .shape(CheckBoxShape.ROUNDED_SQUARE)
            .onChange((value: boolean) => {
              console.info('Checkbox1 change is' + value)
            })
          Text('Checkbox1').fontSize(14).lineHeight(20).fontColor('#182431').fontWeight(500)
        }.margin({ left: 36 })

        // 选项2
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          Checkbox({ name: 'checkbox2', group: 'checkboxGroup' })
            .selectedColor('#007DFF')
            .shape(CheckBoxShape.ROUNDED_SQUARE)
            .onChange((value: boolean) => {
              console.info('Checkbox2 change is' + value)
            })
          Text('Checkbox2').fontSize(14).lineHeight(20).fontColor('#182431').fontWeight(500)
        }.margin({ left: 36 })

        // 选项3
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          Checkbox({ name: 'checkbox3', group: 'checkboxGroup' })
            .selectedColor('#007DFF')
            .shape(CheckBoxShape.ROUNDED_SQUARE)
            .onChange((value: boolean) => {
              console.info('Checkbox3 change is' + value)
            })
          Text('Checkbox3').fontSize(14).lineHeight(20).fontColor('#182431').fontWeight(500)
        }.margin({ left: 36 })
      }
    }
  }
}
```
![checkboxGroup](figures/checkboxGroup.gif)

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
          CheckboxGroup({ group: 'checkboxGroup' })
            .selectedColor(Color.Orange)
            .onChange((itemName: CheckboxGroupResult) => {
              console.info("checkbox group content" + JSON.stringify(itemName))
            })
            .mark({
              strokeColor:Color.Black,
              size: 40,
              strokeWidth: 5
            })
            .unselectedColor(Color.Red)
            .width(30)
            .height(30)
          Text('Select All').fontSize(20)
        }.margin({right:15})
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
        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
          Checkbox({ name: 'checkbox3', group: 'checkboxGroup' })
            .selectedColor(0x39a2db)
            .shape(CheckBoxShape.ROUNDED_SQUARE)
            .onChange((value: boolean) => {
              console.info('Checkbox3 change is' + value)
            })
            .width(30)
            .height(30)
          Text('Checkbox3').fontSize(20)
        }
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![checkboxGroup](figures/checkboxGroup2.gif)

