# Ellipse

椭圆绘制组件。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

ellipse(options?: {width: Length, height: Length})

**参数:**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| width | string \| number | 是 | 宽度。<br/>默认值：0 |
| height | string \| number | 是 | 高度。<br/>默认值：0 |

## 属性

仅支持以下属性：

| 参数名称 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| width | Length | 否 | 椭圆所在矩形的宽度。 |
| height | Length | 否 | 椭圆所在矩形的高度。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct EllipseExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // 在一个 150 * 80 的矩形框中绘制一个椭圆
      Ellipse({ width: 150, height: 80 })
      // 在一个 150 * 80 的矩形框中绘制一个椭圆
      Ellipse().width(150).height(80)
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001174104394](figures/zh-cn_image_0000001174104394.png)
