# 点击控制

设置组件是否可触摸。

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性


| **名称**    | **参数类型** | **默认值** | **描述**         |
| --------- | -------- | ------- | -------------- |
| touchable | boolean  | true    | 设置当前组件是否可以被触摸。 |


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
