# TapGesture

支持单击、双击和多次点击事件的识别。

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 接口

TapGesture(value?: { count?: number, fingers?: number })

**参数：**

| 参数名称 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| count | number | 否 | 识别的连续点击次数。当设置的值小于1或不设置时，会被转化为默认值。<br/>默认值：1<br/>**说明：**<br/>如配置多击，上一次抬起和下一次按下的超时时间为300毫秒。 |
| fingers | number | 否 | 触发点击的手指数，最小为1指，&nbsp;最大为10指。当设置小于1的值或不设置时，会被转化为默认值。<br/>默认值：1<br/>**说明：**<br/>1. 当配置多指时，第一根手指按下后300毫秒内未有足够的手指数按下，手势识别失败。<br/>2. 实际点击手指数超过配置值，手势识别成功。 |


## 事件

| 名称 | 功能描述 |
| -------- | -------- |
| onAction(event: (event?:&nbsp;[GestureEvent](ts-gesture-settings.md#gestureevent对象说明))&nbsp;=&gt;&nbsp;void) | Tap手势识别成功回调。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct TapGestureExample {
  @State value: string = ''

  build() {
    Column() {
      // 单指双击文本触发手势事件
      Text('Click twice').fontSize(28)
        .gesture(
        TapGesture({ count: 2 })
          .onAction((event?: GestureEvent) => {
            if (event) {
              this.value = JSON.stringify(event.fingerList[0])
            }
          })
        )
      Text(this.value)
    }
    .height(200)
    .width(300)
    .padding(20)
    .border({ width: 3 })
    .margin(30)
  }
}
```

![zh-cn_image_0000001174422900](figures/zh-cn_image_0000001174422900.gif)
