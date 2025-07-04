# 自定义事件拦截

为组件提供自定义的事件拦截能力，开发者可根据事件在控件上按下时发生的位置，输入源等事件信息决定控件上的HitTestMode属性。

>  **说明：**
>
>  从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## onTouchIntercept

onTouchIntercept(callback: Callback<TouchEvent, HitTestMode>)

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名        | 参数类型                    | 必填  | 参数描述                          |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | Callback<[TouchEvent](ts-universal-events-touch.md#touchevent对象说明), [HitTestMode](ts-universal-attributes-hit-test-behavior.md#hittestmode枚举说明)> | 是     |  给组件绑定自定义事件拦截回调，并使能在做[触摸测试](../../../ui/arkts-interaction-basic-principles.md#触摸测试)时回调此函数。通过返回值设置组件的[触摸碰撞测试模式](ts-universal-attributes-hit-test-behavior.md)。 |


## 示例

该示例通过onTouchIntercept修改组件的HitTestMode属性。

```ts
// xxx.ets
@Entry
@Component
struct Index {
  isPolygon(event: TouchEvent) {
    return true;
  }

  build() {
    Row() {
      Column() {
        Text("hello world")
          .backgroundColor(Color.Blue)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            console.log("Text click");
          })
      }
      .width(400)
      .height(300)
      .backgroundColor(Color.Pink)
      .onClick(() => {
        console.log("Column click");
      })
      // 调用onTouchIntercept修改该组件的HitTestMode属性
      .onTouchIntercept((event: TouchEvent) => {
        console.log("OnTouchIntercept + " + JSON.stringify(event));
        // 使用touches时需要先校验是否为空
        if (event && event.touches) {
          let touches = event.touches;
          for(let i = 0; touches[i] != null; i++) {
            console.info('onTouchIntercept touches:', JSON.stringify(touches[i]));
          }
        }
        if (this.isPolygon(event)) {
          return HitTestMode.None;
        }
        return HitTestMode.Default;
      })
    }
    .width('100%')
  }
}
```
