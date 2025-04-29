# 动态手势设置

动态设置组件绑定的手势，支持开发者在属性设置时使用if/else语法。

>  **说明：**
>
>  从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## gestureModifier

gestureModifier(modifier:&nbsp;GestureModifier)

动态设置组件绑定的手势。

>  **说明：**
>
>  gestureModifier不支持自定义组件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| modifier | [GestureModifier](#gesturemodifier-1) | 是   | 在当前组件上，动态设置组件绑定的手势，支持使用if/else语法。<br/>modifier: 手势修改器，开发者需要自定义class实现GestureModifier接口。 |

## GestureModifier

开发者需要自定义class实现GestureModifier接口。

### applyGesture
applyGesture(event: UIGestureEvent): void

组件需要绑定的手势。

开发者可根据需要自定义实现这个方法，对组件设置需要绑定的手势，支持使用if/else语法进行动态设置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数**：

| 参数名            | 类型                                        | 说明                                       |
| ------------- | ----------------------------------------  | ---------------------------------------- |
| event        | [UIGestureEvent](./ts-uigestureevent.md#uigestureevent) |  UIGestureEvent对象，用于设置组件需要绑定的手势。      |

## 示例

该示例通过gestureModifier动态设置组件绑定的手势。

```ts
// xxx.ets
class MyButtonModifier implements GestureModifier {
  supportDoubleTap: boolean = true

  applyGesture(event: UIGestureEvent): void {
    if (this.supportDoubleTap) {
      event.addGesture(
        new TapGestureHandler({ count: 2, fingers: 1 })
          .tag("aaa")
          .onAction((event: GestureEvent) => {
            console.log("button tap ")
          })
      )
    } else {
      event.addGesture(
        new PanGestureHandler()
          .onActionStart(()=>{
            console.log("Pan start");
          })
      )
    }
  }
}

@Entry
@Component
struct Index {
  @State modifier: MyButtonModifier = new MyButtonModifier()

  build() {
    Row() {
      Column() {
        Column()
          .gestureModifier(this.modifier)
          .width(500)
          .height(500)
          .backgroundColor(Color.Blue)
        Button('changeGesture')
          .onClick(() => {
            this.modifier.supportDoubleTap = !this.modifier.supportDoubleTap;
          })
          .margin({top: 10})
      }
      .width('100%')
    }
    .height('100%')
  }
}
```