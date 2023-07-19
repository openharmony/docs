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
| type | [ToggleType](#toggletype枚举说明) | 是   | 开关的样式。 |
| isOn | boolean    | 否   | 开关是否打开，true：打开，false：关闭。<br/>默认值：false<br />从API version 10开始，该参数支持[$$](../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |


## ToggleType枚举说明

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称       | 描述                 |
| -------- | ---------------- |
| Checkbox | 提供单选框样式。<br>**说明：**<br/>[通用属性margin](ts-universal-attributes-size.md)的默认值为：<br>{<br>&nbsp;top: 14 px,<br>&nbsp;right: 14 px,<br>&nbsp;bottom: 14 px,<br>&nbsp;left: 14 px<br> } |
| Button   | 提供状态按钮样式，如果子组件有文本设置，则相应的文本内容会显示在按钮内部。       |
| Switch   | 提供开关样式。<br>**说明：**<br/>[通用属性margin](ts-universal-attributes-size.md)默认值为：<br>{<br/>&nbsp;top: 6px,<br/>&nbsp;right: 14px,<br/>&nbsp;bottom: 6 px,<br/>&nbsp;left: 14 px<br/> } |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称                | 参数                           | 参数描述                  |
| ---------------- | --------------------------- | ---------------------- |
| selectedColor    | [ResourceColor](ts-types.md#resourcecolor)  | 设置组件打开状态的背景颜色。 <br/>从API version 9开始，该接口支持在ArkTS卡片中使用。|
| switchPointColor | [ResourceColor](ts-types.md#resourcecolor)  | 设置Switch类型的圆形滑块颜色。<br/>**说明：**<br/>仅对type为ToggleType.Switch生效。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称 | 功能描述 |
| -------- | -------- |
| onChange(callback:&nbsp;(isOn:&nbsp;boolean)&nbsp;=&gt;&nbsp;void) | 开关状态切换时触发该事件。 <br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>isOn为true时，代表状态从关切换为开。isOn为false时，代表状态从开切换为关。 |


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
