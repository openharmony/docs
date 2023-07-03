# 菜单控制

为组件绑定弹出式菜单，弹出式菜单以垂直列表形式显示菜单项，可通过长按、点击或鼠标右键触发。

>  **说明：**
>
>  - 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  - CustomBuilder里不支持再使用bindMenu、bindContextMenu弹出菜单。多级菜单可使用[Menu组件](ts-basic-components-menu.md)。


## 属性


| 名称                           | 参数类型                                     | 描述                                       |
| ---------------------------- | ---------------------------------------- | ---------------------------------------- |
| bindMenu                     | content: Array<[MenuItem](#menuitem)&gt;&nbsp;\|&nbsp;[CustomBuilder](ts-types.md#custombuilder8),<br>options: [MenuOptions](#menuoptions10) | 给组件绑定菜单，点击后弹出菜单。弹出菜单项支持图标+文本排列和自定义两种功能。<br/>content: 必填，配置菜单项图标和文本的数组，或者自定义组件。<br/>options: 非必填，配置弹出菜单的参数。 |
| bindContextMenu<sup>8+</sup> | content:&nbsp;[CustomBuilder](ts-types.md#custombuilder8),<br>responseType:&nbsp;[ResponseType](ts-appendix-enums.md#responsetype8)<br>options: [ContextMenuOptions](#contextmenuoptions10) | 给组件绑定菜单，触发方式为长按或者右键点击，弹出菜单项需要自定义。<br/>responseType: 必填。菜单弹出条件，长按或者右键点击。<br/>options: 非必填，配置弹出菜单的参数。 |

## MenuItem

| 名称                 | 类型                                     | 必填   | 描述          |
| ------------------ | -------------------------------------- | ---- | ----------- |
| value              | string                                 | 是    | 菜单项文本。      |
| icon<sup>10+</sup> | [ResourceStr](ts-types.md#resourcestr) | 否    | 菜单项图标。      |
| action             | ()&nbsp;=&gt;&nbsp;void                | 是    | 点击菜单项的事件回调。 |

## MenuOptions<sup>10+</sup>

| 名称          | 类型                                       | 必填   | 描述                                       |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| title       | string                                   | 否    | 菜单标题。                                    |
| offset      | [Position](ts-types.md#position8)        | 否    | 菜单弹出位置的偏移量，不会导致菜单显示超出屏幕范围。               |
| placement   | [Placement](ts-appendix-enums.md#placement8) | 否    | 菜单组件优先显示的位置，当前位置显示不下时，会自动调整位置。<br/>**说明：**<br />placement值设置为undefined、null或没有设置此选项时，按默认值[BottomLeft](ts-appendix-enums.md#placement8)处理，相对父组件区域弹出。 |
| onAppear    | ()&nbsp;=&gt;&nbsp;void                  | 否    | 菜单弹出时的事件回调。                              |
| onDisappear | ()&nbsp;=&gt;&nbsp;void                  | 否    | 菜单消失时的事件回调。                              |

## ContextMenuOptions<sup>10+</sup>

| 名称          | 类型                                       | 必填   | 描述                                       |
| ----------- | ---------------------------------------- | ---- | ---------------------------------------- |
| offset      | [Position](ts-types.md#position8)        | 否    | 菜单弹出位置的偏移量，不会导致菜单显示超出屏幕范围。               |
| placement   | [Placement](ts-appendix-enums.md#placement8) | 否    | 菜单组件优先显示的位置，当前位置显示不下时，会自动调整位置。<br/>**说明：**<br />placement值设置为undefined、null或没有设置此选项时，按未设置placement处理，菜单跟随点击位置弹出。 |
| onAppear    | ()&nbsp;=&gt;&nbsp;void                  | 否    | 菜单弹出时的事件回调。                              |
| onDisappear | ()&nbsp;=&gt;&nbsp;void                  | 否    | 菜单消失时的事件回调。                              |

## 示例

### 示例1

普通菜单

```ts
// xxx.ets
@Entry
@Component
struct MenuExample {
  build() {
    Column() {
      Text('click for Menu')
    }
    .width('100%')
    .margin({ top: 5 })
    .bindMenu([
      {
        value: 'Menu1',
        action: () => {
          console.info('handle Menu1 select')
        }
      },
      {
        value: 'Menu2',
        action: () => {
          console.info('handle Menu2 select')
        }
      },
    ])
  }
}
```

![zh-cn_image_0000001174582862](figures/zh-cn_image_0000001174582862.gif)

### 示例2

自定义内容菜单

```ts
@Entry
@Component
struct MenuExample {
  @State listData: number[] = [0, 0, 0]

  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      ForEach(this.listData, (item, index) => {
        Column() {
          Row() {
            Image($r("app.media.icon")).width(20).height(20).margin({ right: 5 })
            Text(`Menu${index + 1}`).fontSize(20)
          }
          .width('100%')
          .height(30)
          .justifyContent(FlexAlign.Center)
          .align(Alignment.Center)
          .onClick(() => {
            console.info(`Menu${index + 1} Clicked!`)
          })

          if (index != this.listData.length - 1) {
            Divider().height(10).width('80%').color('#ccc')
          }
        }.padding(5).height(40)
      })
    }.width(100)
  }

  build() {
    Column() {
      Text('click for menu')
        .fontSize(20)
        .margin({ top: 20 })
        .bindMenu(this.MenuBuilder)
    }
    .height('100%')
    .width('100%')
    .backgroundColor('#f0f0f0')
  }
}
```

![zh-cn_image_0000001186807708](figures/zh-cn_image_0000001186807708.gif)

### 示例3

菜单(右键触发显示)

```ts
// xxx.ets
@Entry
@Component
struct ContextMenuExample {
  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('Test menu item 1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
      Divider().height(10)
      Text('Test menu item 2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)
    }.width(100)
  }
  
  build() {
    Column() {
      Text('rightclick for menu')
    }
    .width('100%')
    .margin({ top: 5 })
    .bindContextMenu(this.MenuBuilder, ResponseType.RightClick)
  }
}
```
