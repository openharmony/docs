# Toggle

组件提供勾选框样式、状态按钮样式及开关样式。

>  **说明：**
>
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

仅当ToggleType为Button时可包含子组件。


## 接口

Toggle(options: { type: ToggleType, isOn?: boolean })

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数:**

| 参数名 | 参数类型 | 必填   | 参数描述           |
| ---- | ---------- | -----| -------------- |
| type | [ToggleType](#toggletype枚举说明) | 是   | 开关的样式。<br/>默认值：ToggleType.Switch。 |
| isOn | boolean    | 否   | 开关是否打开，true：打开，false：关闭。<br/>默认值：false<br />从API version 10开始，该参数支持[$$](../../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |


## ToggleType枚举说明

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称       | 描述                 |
| -------- | ---------------- |
| Checkbox | 提供单选框样式。<br>**说明：**<br/>API version 11开始，Checkbox默认样式由圆角方形变为圆形。<br/>[通用属性margin](ts-universal-attributes-size.md)的默认值为：<br>{<br>&nbsp;top: '14px',<br>&nbsp;right: '14px',<br>&nbsp;bottom: '14px',<br>&nbsp;left: '14px'<br> }。<br/>默认尺寸为:<br>{width:'20vp', height:'20vp'}。|
| Button   | 提供状态按钮样式，如果子组件有文本设置，则相应的文本内容会显示在按钮内部。<br/>默认尺寸为:高为28vp，宽无默认值。       |
| Switch   | 提供开关样式。<br>**说明：**<br/>[通用属性margin](ts-universal-attributes-size.md)默认值为：<br>{<br/>&nbsp;top: '6px',<br/>&nbsp;right: '14px',<br/>&nbsp;bottom: '6px',<br/>&nbsp;left: '14px'<br/> }。<br/>默认尺寸为:<br>{width:'36vp', height:'20vp'}。|

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

### selectedColor

selectedColor(value: ResourceColor)

设置组件打开状态的背景颜色。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                     |
| ------ | ------------------------------------------ | ---- | ------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | 组件打开状态的背景颜色。<br/>默认值：'#ff007dff' |

### switchPointColor

switchPointColor(color: ResourceColor)

设置Switch类型的圆形滑块颜色。仅对type为ToggleType.Switch生效。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                       | 必填 | 说明                       |
| ------ | ------------------------------------------ | ---- | -------------------------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | 是   | Switch类型的圆形滑块颜色。<br/>默认值：'#ffffffff' |

### switchStyle<sup>12+</sup>

switchStyle(value: SwitchStyle)

设置Switch类型的样式。仅对type为ToggleType.Switch生效。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                | 必填 | 说明             |
| ------ | --------------------------------------------------- | ---- | ---------------- |
| value  | [SwitchStyle<sup>12+</sup>](#switchstyle12对象说明) | 否   | Switch样式风格。 |

### SwitchStyle<sup>12+</sup>对象说明

| 名称              | 类型                                        | 必填 | 说明                               |
| ----------------- | ------------------------------------------- | ---- | ---------------------------------- |
| pointRadius       | number \|  [Resource](ts-types.md#resource) | 否   | 设置Switch类型的圆形滑块半径。     |
| unselectedColor   | [ResourceColor](ts-types.md#resourcecolor)  | 否   | 设置Switch类型关闭状态的背景颜色。 |
| pointColor        | [ResourceColor](ts-types.md#resourcecolor)  | 否   | 设置Switch类型的圆形滑块颜色。     |
| trackBorderRadius | number \|  [Resource](ts-types.md#resource) | 否   | 设置Switch类型的滑轨的圆角。       |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

### onChange

onChange(callback:&nbsp;(isOn:&nbsp;boolean)&nbsp;=&gt;&nbsp;void)

开关状态切换时触发该事件。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| isOn   | boolean | 是   | 为true时，代表状态从关切换为开。false时，代表状态从开切换为关。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ToggleExample {
  build() {
    Column({ space: 10 }) {
      Text('type: Switch').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Switch, isOn: false })
          .selectedColor('#007DFF')
          .switchPointColor('#FFFFFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Switch, isOn: true })
          .selectedColor('#007DFF')
          .switchPointColor('#FFFFFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Checkbox').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Checkbox, isOn: false })
          .size({ width: 20, height: 20 })
          .selectedColor('#007DFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })

        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .size({ width: 20, height: 20 })
          .selectedColor('#007DFF')
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
      }

      Text('type: Button').fontSize(12).fontColor(0xcccccc).width('90%')
      Flex({ justifyContent: FlexAlign.SpaceEvenly, alignItems: ItemAlign.Center }) {
        Toggle({ type: ToggleType.Button, isOn: false }) {
          Text('status button').fontColor('#182431').fontSize(12)
        }.width(106)
        .selectedColor('rgba(0,125,255,0.20)')
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })

        Toggle({ type: ToggleType.Button, isOn: true }) {
          Text('status button').fontColor('#182431').fontSize(12)
        }.width(106)
        .selectedColor('rgba(0,125,255,0.20)')
        .onChange((isOn: boolean) => {
          console.info('Component status:' + isOn)
        })
      }
    }.width('100%').padding(24)
  }
}
```

![toggle](figures/toggle.gif)
