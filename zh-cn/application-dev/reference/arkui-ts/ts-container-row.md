# Row

沿水平方向布局容器。

>  **说明：**
>
>  该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 子组件

可以包含子组件。


## 接口

Row(value?:{space?: string&nbsp;|&nbsp;number})

**参数：**

| 参数名 | 参数类型                   | 必填 | 参数描述                                 |
| ------ | -------------------------- | ---- | ---------------------------------------- |
| space  | string&nbsp;\|&nbsp;number | 否   | 横向布局元素间距。<br/>默认值：0，单位vp |

## 属性

| 名称               | 参数类型                              | 默认值                  | 描述                |
| ---------------- | --------------------------------- | -------------------- | ----------------- |
| alignItems       | [VerticalAlign](ts-appendix-enums.md#verticalalign)    | VerticalAlign.Center | 在垂直方向上子组件的对齐格式。   |
| justifyContent<sup>8+</sup> | [FlexAlign](ts-appendix-enums.md#flexalign) | FlexAlign.Start      | 设置子组件在水平方向上的对齐格式。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct RowExample {
  build() {
    Column({ space: 5 }) {
      Text('space').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row({ space: 5 }) {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.width('90%').height(107).border({ width: 1 })

        Text('alignItems(Top)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.alignItems(VerticalAlign.Top).height('15%').border({ width: 1 })

        Text('alignItems(Center)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.alignItems(VerticalAlign.Center).height('15%').border({ width: 1 })

        Text('justifyContent(End)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.width('90%').border({ width: 1 }).justifyContent(FlexAlign.End)

        Text('justifyContent(Center)').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Row().width('30%').height(50).backgroundColor(0xAFEEEE)
          Row().width('30%').height(50).backgroundColor(0x00FFFF)
        }.width('90%').border({ width: 1 }).justifyContent(FlexAlign.Center)
    }.width('100%')
  }
}
```

![zh-cn_image_0000001174422908](figures/Row.png)
