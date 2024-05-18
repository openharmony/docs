# Radio

单选框，提供相应的用户交互选择项。

>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

Radio(options: RadioOptions)

创建单选框组件。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                  | 必填 | 描述               |
| ------- | ------------------------------------- | ---- | ------------------ |
| options | [RadioOptions](#radiooptions对象说明) | 是   | 配置单选框的参数。 |

## RadioOptions对象说明

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string | 是 | 当前单选框的值。 <br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| group | string | 是 | 当前单选框的所属群组名称，相同group的Radio只能有一个被选中。<br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| indicatorType<sup>12+</sup> | [RadioIndicatorType](#radioindicatortype12枚举说明) | 否 | 配置单选框的选中样式。未设置时按照RadioIndicatorType.TICK进行显示。|
| indicatorBuilder<sup>12+</sup> | [CustomBuilder](ts-types.md#custombuilder8) | 否 | 配置单选框的选中样式为自定义组件。自定义组件与Radio组件为中心点对齐显示。indicatorBuilder设置为undefined时，按照RadioIndicatorType.TICK进行显示。|

## RadioIndicatorType<sup>12+</sup>枚举说明

| 名称            | 描述                             |
| --------------- | -------------------------------- |
| TICK            | 选中样式为系统默认TICK图标。  |
| DOT             | 选中样式为系统默认DOT图标。   |
| CUSTOM          | 选中样式为indicatorBuilder中的内容。|

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### checked

checked(value: boolean)

设置单选框的选中状态。

从API version 10开始，该属性支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                 |
| ------ | ------- | ---- | ------------------------------------ |
| value  | boolean | 是   | 单选框的选中状态。<br/>默认值：false |

### radioStyle<sup>10+</sup>

radioStyle(value?: RadioStyle)

设置单选框选中状态和非选中状态的样式。 

从API version 10开始，该接口支持在ArkTS组件中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                | 必填 | 说明                               |
| ------ | ----------------------------------- | ---- | ---------------------------------- |
| value  | [RadioStyle](#radiostyle10对象说明) | 否   | 单选框选中状态和非选中状态的样式。 |

## contentModifier<sup>12+</sup>

contentModifier(modifier: ContentModifier\<RadioConfiguration>)

定制Radio内容区的方法。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                          | 必填 | 说明                                             |
| ------ | --------------------------------------------- | ---- | ------------------------------------------------ |
| modifier  | [ContentModifier\<RadioConfiguration>](#radioconfiguration12对象说明) | 是   | 在Radio组件上，定制内容区的方法。<br/>modifier: 内容修改器，开发者需要自定义class实现ContentModifier接口。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

### onChange

onChange(callback: (isChecked: boolean) => void)

单选框选中状态改变时触发回调。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型    | 必填 | 说明                                                         |
| --------- | ------- | ---- | ------------------------------------------------------------ |
| isChecked | boolean | 是   | 单选框的状态。<br/>为true时，表示从未选中变为选中。为false时，表示从选中变为未选中。 |

## RadioStyle<sup>10+</sup>对象说明

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

| 名称                   | 类型                                       | 必填 | 默认值  | 描述                   |
| ---------------------- | ------------------------------------------ | ---- | ------- | ---------------------- |
| checkedBackgroundColor | [ResourceColor](ts-types.md#resourcecolor) | 否   | #007DFF | 开启状态底板颜色。     |
| uncheckedBorderColor   | [ResourceColor](ts-types.md#resourcecolor) | 否   | #182431 | 关闭状态描边颜色。     |
| indicatorColor         | [ResourceColor](ts-types.md#resourcecolor) | 否   | #FFFFFF | 开启状态内部圆饼颜色。从API version 12开始，indicatorType设置为RadioIndicatorType.TICK和RadioIndicatorType.DOT时，支持修改内部颜色。indicatorType设置为RadioIndicatorType.CUSTOM时，不支持修改内部颜色。 |

## RadioConfiguration<sup>12+</sup>对象说明

开发者需要自定义class实现ContentModifier接口。

| 参数名  | 类型    |    默认值      |  说明              |
| ------ | ------ | ------ |-------------------------------- |
| value | string | - |当前单选框的值。 |
| checked | boolean| false | 设置单选框的选中状态。|
| triggerChange |Callback\<boolean>| - |触发单选框选中状态变化。 |


## 示例
### 示例1 
设置开启状态底板颜色。
```ts
// xxx.ets
@Entry
@Component
struct RadioExample {
  build() {
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Column() {
        Text('Radio1')
        Radio({ value: 'Radio1', group: 'radioGroup' }).checked(true)
          .radioStyle({
            checkedBackgroundColor: Color.Pink
          })
          .height(50)
          .width(50)
          .onChange((isChecked: boolean) => {
            console.log('Radio1 status is ' + isChecked)
          })
      }
      Column() {
        Text('Radio2')
        Radio({ value: 'Radio2', group: 'radioGroup' }).checked(false)
          .radioStyle({
            checkedBackgroundColor: Color.Pink
          })
          .height(50)
          .width(50)
          .onChange((isChecked: boolean) => {
            console.log('Radio2 status is ' + isChecked)
          })
      }
      Column() {
        Text('Radio3')
        Radio({ value: 'Radio3', group: 'radioGroup' }).checked(false)
          .radioStyle({
            checkedBackgroundColor: Color.Pink
          })
          .height(50)
          .width(50)
          .onChange((isChecked: boolean) => {
            console.log('Radio3 status is ' + isChecked)
          })
      }
    }.padding({ top: 30 })
  }
}
```
![radio](figures/radio.gif)
### 示例2 
设置选中样式为图片。
```ts
// xxx.ets
@Entry
@Component
struct RadioExample {
  @Builder 
  indicatorBuilder() {
    Image($r("app.media.star"))
  }
  build() {
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Column() {
        Text('Radio1')
        Radio({ value: 'Radio1', group: 'radioGroup',
          indicatorType:RadioIndicatorType.TICK
        }).checked(true)
          .height(50)
          .width(80)
          .onChange((isChecked: boolean) => {
            console.log('Radio1 status is ' + isChecked)
          })
      }
      Column() {
        Text('Radio2')
        Radio({ value: 'Radio2', group: 'radioGroup',
          indicatorType:RadioIndicatorType.DOT
        }).checked(false)
          .height(50)
          .width(80)
          .onChange((isChecked: boolean) => {
            console.log('Radio2 status is ' + isChecked)
          })
      }
      Column() {
        Text('Radio3')
        Radio({ value: 'Radio3', group: 'radioGroup',
          indicatorType:RadioIndicatorType.CUSTOM,
          indicatorBuilder:()=>{this.indicatorBuilder()}
        }).checked(false)
          .height(50)
          .width(80)
          .onChange((isChecked: boolean) => {
            console.log('Radio3 status is ' + isChecked)
          })
      }
    }.padding({ top: 30 })
  }
}
```
![radio](figures/radio_2.gif)
### 示例3
设置自定义单选样式
```ts
class MyRadioStyle implements ContentModifier<RadioConfiguration> {
  type: number = 0
  selectedColor:Color = Color.Black

  constructor(numberType: number, colorType:Color) {
    this.type = numberType
    this.selectedColor = colorType
  }

  applyContent() : WrappedBuilder<[RadioConfiguration]>
  {
    return wrapBuilder(buildRadio)
  }
}

@Builder function buildRadio(config: RadioConfiguration) {
  Row({ space:30 }) {
    Circle({ width: 50, height: 50 })
      .stroke(Color.Black)
      .fill(config.checked ? (config.contentModifier as MyRadioStyle).selectedColor : Color.White)
    Button(config.checked ? "off" : "on")
      .width(100)
      .type(config.checked ? (config.contentModifier as MyRadioStyle).type : ButtonType.Normal)
      .backgroundColor(0xAABBCC)
      .onClick(()=>{
        if (config.checked) {
          config.triggerChange(false)
        } else {
          config.triggerChange(true)
        }
      })
  }
}

@Entry
@Component
struct refreshExample {
  build() {
    Column({ space: 50 }) {
      Row() {
        Radio({ value: 'Radio1', group: 'radioGroup' })
          .contentModifier(new MyRadioStyle(1, Color.Red))
          .checked(false)
          .width(300)
          .height(100)
      }
      Row() {
        Radio({ value: 'Radio2', group: 'radioGroup' })
          .checked(true)
          .width(300)
          .height(60)
          .contentModifier(new MyRadioStyle(2, Color.Red))
      }
    }
  }
}
```
![](figures/radio_3.gif)