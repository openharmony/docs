# Menu控制

为组件绑定弹出式菜单，弹出式菜单以垂直列表形式显示菜单项，可通过长按、点击或鼠标右键触发。

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性


| 名称                           | 参数类型                                     | 默认值  | 描述                                 |
| ---------------------------- | ---------------------------------------- | ---- | ---------------------------------- |
| bindMenu                     | Array<MenuItem&gt;&nbsp;\|&nbsp;[CustomBuilder](../../ui/ts-types.md)<sup>8+</sup> | -    | 给组件绑定菜单，点击后弹出菜单。弹出菜单项支持文本和自定义两种功能。 |
| bindContextMenu<sup>8+</sup> | content:&nbsp;[CustomBuilder](../../ui/ts-types.md),<br>responseType:&nbsp;ResponseType | -    | 给组件绑定菜单，触发方式为长按或者右键点击，弹出菜单项需要自定义。  |


- MenuItem
  | 名称     | 类型                      | 描述          |
  | ------ | ----------------------- | ----------- |
  | value  | string                  | 菜单项文本。      |
  | action | ()&nbsp;=&gt;&nbsp;void | 点击菜单项的事件回调。 |

- ResponseType<sup>8+</sup>
  | 参数值        | 描述            |
  | ---------- | ------------- |
  | LongPress  | 通过长按触发菜单弹出。   |
  | RightClick | 通过鼠标右键触发菜单弹出。 |

## 示例

#### 普通菜单

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

#### 自定义内容菜单

```ts
// xxx.ets
import router from '@system.router';

@Entry
@Component
struct MenuExample {
  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('text1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)

      Divider().height(10)

      Text('text2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)

      Divider().height(10)

      Button('Next')
        .fontSize(20)
        .width(100)
        .height(50)
        .onClick(() => {
          router.push({ uri: 'pages/details' })
        })

    }.width(100)
  }

  build() {
    Column() {
      Text('click for menu')
    }
    .width('100%')
    .margin({ top: 5 })
    .bindMenu(this.MenuBuilder)
  }
}
```

![zh-cn_image_0000001186807708](figures/zh-cn_image_0000001186807708.gif)

#### 菜单(右键触发显示)

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