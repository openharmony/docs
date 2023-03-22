# 禁用控制

组件是否可交互，可交互状态下响应[点击事件](ts-universal-events-click.md)、[触摸事件](ts-universal-events-touch.md)、[拖拽事件](ts-universal-events-drag-drop.md)、[按键事件](ts-universal-events-key.md)、[焦点事件](ts-universal-focus-event.md)和[鼠标事件](ts-universal-mouse-key.md)。

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性


| 名称    | 参数类型 | 描述                                                         |
| ------- | -------- | ------------------------------------------------------------ |
| enabled | boolean  | 值为true表示组件可交互，响应点击等操作。<br>值为false表示组件不可交互，不响应点击等操作。<br>默认值：true<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct EnabledExample {
  
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // 点击没有反应
      Button('disable').enabled(false).backgroundColor(0x317aff).opacity(0.4)
      Button('enable').backgroundColor(0x317aff)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001219982713](figures/zh-cn_image_0000001219982713.gif)
