# Blank

>  **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


空白填充组件，在容器主轴方向上，空白填充组件具有自动填充容器空余部分的能力。仅当父组件为Row/Column时生效。


## 权限列表

无


## 子组件

无


## 接口

Blank(min?:  Length)

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | min | Length | 否 | 0 | 空白填充组件在容器主轴上的最小大小。 | 


## 属性

| 名称 | 参数类型 | 默认值 | 描述 | 
| -------- | -------- | -------- | -------- |
| color | Color&nbsp;\|&nbsp;number&nbsp;\|&nbsp;string&nbsp;\|&nbsp;[Resource](../../ui/ts-types.md#resource类型) | 0x00000000 | 设置空白填充的填充颜色。 | 

>  **说明：**
> - 不支持通用属性方法。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct BlankExample {
  build() {
    Column() {
      Row() {
        Text('Bluetooth').fontSize(18)
        Blank()
        Toggle({ type: ToggleType.Switch })
      }.width('100%').backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })
    }.backgroundColor(0xEFEFEF).padding(20)
  }
}
```

竖屏状态

![zh-cn_image_0000001219662649](figures/zh-cn_image_0000001219662649.gif)

横屏状态

![zh-cn_image_0000001174104388](figures/zh-cn_image_0000001174104388.gif)
