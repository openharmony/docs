# Rect

矩形绘制组件。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


## 接口

Rect(value:{options?: {width:  number&nbsp;|&nbsp;string ,height:  number&nbsp;|&nbsp;string ,radius?:  number&nbsp;|&nbsp;string | Array&lt;Length&gt;} | {width:  number&nbsp;|&nbsp;string ,height:  number&nbsp;|&nbsp;string ,radiusWidth?:  number&nbsp;|&nbsp;string ,radiusHeight?:  number&nbsp;|&nbsp;string }})

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| width | string&nbsp;\|&nbsp;number | 是 | 宽度。 |
| height | string&nbsp;\|&nbsp;number | 是 | 高度。 |
| radius | string&nbsp;\|&nbsp;number&nbsp;\|&nbsp;Array&lt;Length&gt; | 否 | 圆角半径，支持分别设置四个角的圆角度数。 |
| radiusWidth | string&nbsp;\|&nbsp;number | 否 | 圆角宽度。 |
| radiusHeight | string&nbsp;\|&nbsp;number | 否 | 圆角高度。 |


## 属性

| 参数名称 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| width | [Length](../../ui/ts-types.md#length) | 否 | 宽度。 |
| height | [Length](../../ui/ts-types.md#length) | 否 | 高度。 |
| radiusWidth | [Length](../../ui/ts-types.md#length) | 否 | 圆角的宽度，仅设置宽时宽高一致。 |
| radiusHeight | [Length](../../ui/ts-types.md#length) | 否 | 圆角的高度，仅设置高时宽高一致。 |
| radius | [Length](../../ui/ts-types.md#length)&nbsp;\|&nbsp;Array&lt;[Length](../../ui/ts-types.md#length)&gt; | 否 | 圆角大小。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct RectExample {
  build() {
    Column({ space: 5 }) {
      Text('normal').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // 绘制90% * 50矩形
      Rect({ width: '90%', height: 50 })
      // 绘制90% * 50矩形
      Rect().width('90%').height(50)

      Text('with rounded corners').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // 绘制90% * 50矩形, 圆角宽高20
      Rect({ width: '90%', height: 50 }).radiusHeight(20).radiusWidth(20)
      // 绘制90% * 50矩形, 圆角宽高20
      Rect({ width: '90%', height: 50 }).radius(20)
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001174264386](figures/zh-cn_image_0000001174264386.png)
