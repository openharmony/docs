# Button

按钮组件，可快速创建不同样式的按钮。

>  **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 子组件

可以包含单个子组件。


## 接口

- Button(options?: {type?: ButtonType, stateEffect?: boolean})

  **表1** options参数说明
  
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | type | ButtonType | 否 | Capsule | 描述按钮风格。 |
  | stateEffect | boolean | 否 | true | 按钮按下时是否开启切换效果，当状态置为false时，点击效果关闭。 |


- Button(label?: string, options?: { type?: ButtonType, stateEffect?: boolean })

  使用文本内容创建相应的按钮组件，此时Button无法包含子组件。

  **表2** value参数说明
  
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | label | string | 否 | - | 按钮文本内容。 |
  | options | Object | 否 | - | 见options参数说明。 |


## 属性

| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| type | ButtonType | Capsule | 设置Button样式。 |
| stateEffect | boolean | true | 状态切换时是否开启切换效果，当状态置为false时，点击效果关闭。 |

- ButtonType枚举说明
  | 名称 | 描述 |
  | -------- | -------- |
  | Capsule | 胶囊型按钮（圆角默认为高度的一半）。 |
  | Circle | 圆形按钮。 |
  | Normal | 普通按钮（默认不带圆角）。 |

>  **说明：**
> - 按钮圆角通过[通用属性borderRadius设置](ts-universal-attributes-border.md)（不支持通过border接口设置圆角）。
> - 当按钮类型为Capsule时，borderRadius设置不生效，按钮圆角始终为高度的一半。
> - 当按钮类型为Circle时，borderRadius即为按钮半径，若未设置borderRadius按钮半径则为宽、高中较小值的一半。
> - 按钮文本通过[通用文本样式](ts-universal-attributes-text-style.md)进行设置。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ButtonExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Common button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Ok', { type: ButtonType.Normal, stateEffect: true }).borderRadius(8).backgroundColor(0x317aff).width(90)
        Button({ type: ButtonType.Normal, stateEffect: true }) {
          Row() {
            Image($r('app.media.loading')).width(20).height(20).margin({ left: 12 })
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })
          }.alignItems(VerticalAlign.Center)
        }.borderRadius(8).backgroundColor(0x317aff).width(90)
        Button('Disable', { type: ButtonType.Normal, stateEffect: false }).opacity(0.5)
          .borderRadius(8).backgroundColor(0x317aff).width(90)
      }

      Text('Capsule button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('Ok', { type: ButtonType.Capsule, stateEffect: true }).backgroundColor(0x317aff).width(90)
        Button({ type: ButtonType.Capsule, stateEffect: true }) {
          Row() {
            Image($r('app.media.loading')).width(20).height(20).margin({ left: 12 })
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })
          }.alignItems(VerticalAlign.Center).width(90)
        }.backgroundColor(0x317aff)
        .onClick((event: ClickEvent) => {
          AlertDialog.show({ message: 'The login is successful' })
        })
        Button('Disable', { type: ButtonType.Capsule, stateEffect: false }).opacity(0.5)
          .backgroundColor(0x317aff).width(90)
      }

      Text('Circle button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, wrap: FlexWrap.Wrap }) {
        Button({ type: ButtonType.Circle, stateEffect: true }) {
          Image($r('app.media.ic_public_app_filled')).width(20).height(20)
        }.width(55).height(55).backgroundColor(0x317aff)
        Button({ type: ButtonType.Circle, stateEffect: true }) {
          Image($r('app.media.ic_public_delete_filled')).width(30).height(30)
        }.width(55).height(55).margin({ left: 20 }).backgroundColor(0xF55A42)
      }
    }.height(400).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![zh-cn_image_0000001219864141](figures/zh-cn_image_0000001219864141.gif)
