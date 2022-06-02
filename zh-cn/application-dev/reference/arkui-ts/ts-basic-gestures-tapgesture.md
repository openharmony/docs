# TapGesture

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 接口

TapGesture(options?: { count?: number, fingers?: number })

- 参数
  | 参数名称 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | count | number | 否 | 1 | 识别的连续点击次数。如果设置小于1，会被转化为默认值。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;如配置多击，上一次抬起和下一次按下的超时时间为300毫秒（ms）。 | 
  | fingers | number | 否 | 1 | 触发点击的最少手指数，最小为1指，&nbsp;最大为10指。<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**说明：**<br/>>&nbsp;1.&nbsp;当配置多指时，第一根手指按下后300毫秒（ms）内未有足够的手指数按下，手势识别失败。<br/>>&nbsp;<br/>>&nbsp;2.&nbsp;实际点击手指数超过配置值，手势识别失败。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- | 
| onAction((event?:&nbsp;[GestureEvent](ts-gesture-settings.md))&nbsp;=&gt;&nbsp;void) | Tap手势识别成功回调。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct TapGestureExample {
  @State value: string = ''

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Click twice')
      Text(this.value)
    }
    .height(200).width(300).padding(60).border({ width: 1 }).margin(30)
    .gesture(
      TapGesture({ count: 2 })
        .onAction(() => {
          this.value = 'TapGesture onAction'
        })
    )
  }
}
```

![zh-cn_image_0000001174422900](figures/zh-cn_image_0000001174422900.gif)
