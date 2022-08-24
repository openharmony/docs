# 显隐控制

控制组件是否可见。

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性


| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| visibility | [Visibility](ts-appendix-enums.md#visibility) | Visibility.Visible | 控制当前组件显示或隐藏。注意，即使组件处于隐藏状态，在页面刷新时仍存在重新创建过程，因此当对性能有严格要求时建议使用[条件渲染](../../ui/ts-rending-control-syntax-if-else.md)代替。|


## 示例

```ts
// xxx.ets
@Entry
@Component
struct VisibilityExample {
  build() {
    Column() {
      Column() {
        Text('Visible').fontSize(9).width('90%').fontColor(0xCCCCCC)
        Row().visibility(Visibility.Visible).width('90%').height(80).backgroundColor(0xAFEEEE)

        Text('None').fontSize(9).width('90%').fontColor(0xCCCCCC)
        // 隐藏不参与占位
        Row().visibility(Visibility.None).width('90%').height(80).backgroundColor(0xAFEEEE)

        Text('Hidden').fontSize(9).width('90%').fontColor(0xCCCCCC)
        // 隐藏参与占位
        Row().visibility(Visibility.Hidden).width('90%').height(80).backgroundColor(0xAFEEEE)
      }.width('90%').border({ width: 1 })
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001174104390](figures/zh-cn_image_0000001174104390.gif)
