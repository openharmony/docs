# 点击控制
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--SE: @piggyguy-->
<!--TSE: @songyanhong-->
<!--deprecated_code_no_check-->

设置组件是否可以响应点击事件、触摸事件等手指交互事件。

>  **说明：**
>
>  从API version 9开始，该模块不再维护，建议使用[hitTestBehavior](ts-universal-attributes-hit-test-behavior.md)替代。
>
>  从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## touchable<sup>(deprecated)</sup>

touchable(value: boolean): T

设置当前组件是否可以响应点击事件、触摸事件等手指交互事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型| 必填 | 说明                    |
| ----------- | -------- | ----- | ------------------------ |
| value   | boolean  |  否   |设置当前组件是否可以响应点击事件、触摸事件等手指交互事件。<br>默认值：true，可以响应交互事件。设置为false时，不可以响应交互事件。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct TouchAbleExample {
  @State text1: string = ''
  @State text2: string = ''

  build() {
    Stack() {
      Rect()
        .fill(Color.Gray).width(150).height(150)
        .onClick(() => {
          console.info(this.text1 = 'Rect Clicked')
        })
        .overlay(this.text1, { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      Ellipse()
        .fill(Color.Pink).width(150).height(80)
        .touchable(false) // 点击Ellipse区域，不会打印 “Ellipse Clicked”
        .onClick(() => {
          console.info(this.text2 = 'Ellipse Clicked')
        })
        .overlay(this.text2, { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
    }.margin(100)
  }
}
```

![zh-cn_image_0000001189624550](figures/zh-cn_image_0000001189624550.gif)
