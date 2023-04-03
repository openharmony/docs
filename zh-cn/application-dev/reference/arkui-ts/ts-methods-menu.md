# 菜单

在页面范围内关闭通过[bindContextMenu](./ts-universal-attributes-menu.md#属性)属性绑定的菜单。

>  **说明：**
>
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## ContextMenu.close

|方法|描述|
|----|---|
| close(): void | 可以通过该方法在页面范围内关闭通过[bindContextMenu](./ts-universal-attributes-menu.md#属性)给组件绑定的菜单。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Button('Test ContextMenu1')
      Divider().strokeWidth(2).margin(5).color(Color.Black)
      Button('Test ContextMenu2')
      Divider().strokeWidth(2).margin(5).color(Color.Black)
      Button('Test ContextMenu3')
    }
    .width(200)
    .height(160)
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Column() {
        Text("Test ContextMenu")
          .fontSize(20)
          .width('100%')
          .height(500)
          .backgroundColor(0xAFEEEE)
          .textAlign(TextAlign.Center)
      }
      .bindContextMenu(this.MenuBuilder, ResponseType.LongPress)
      .onDragStart(()=>{
        // 拖拽时关闭菜单
        ContextMenu.close()
      })
    }
    .width('100%')
    .height('100%')
  }
}
```

![contextmenu_close.gif](figures/contextmenu_close.gif)