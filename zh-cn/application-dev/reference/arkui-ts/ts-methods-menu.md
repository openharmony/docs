# 菜单

>  **说明：**
> 从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## ContextMenu.close
|方法|描述|
|----|---|
| close(): void | 可以通过该方法在页面范围内关闭通过[bindContextMenu](./ts-universal-attributes-menu.md#属性)给组件绑定的菜单。 |

- 示例
```
// xxx.ets
@Entry
  @Component
  struct Index {
    @Builder MenuBuilder(){
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Text('close')
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            ContextMenu.close();
          })
      }.height(400)
      .backgroundColor(Color.Pink)
  
    }
    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.Start }) {
        Column(){
          Text("Text")
        }.bindContextMenu(this.MenuBuilder, ResponseType.LongPress)
      }
      .width('100%')
      .height('100%')
    }
  }
```
