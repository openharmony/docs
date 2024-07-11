# 禁用控制

组件是否可交互，可交互状态下响应[点击事件](ts-universal-events-click.md)、[触摸事件](ts-universal-events-touch.md)、[拖拽事件](ts-universal-events-drag-drop.md)、[按键事件](ts-universal-events-key.md)、[焦点事件](ts-universal-focus-event.md)和[鼠标事件](ts-universal-mouse-key.md)。

>  **说明：**
>
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  禁用控制属性只能在按下时生效，已经在交互过程中，更改enabled属性不生效。

## enabled

enabled(value: boolean)

设置组件是否可交互。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 值为true表示组件可交互，响应点击等操作。<br/>值为false表示组件不可交互，不响应点击等操作。<br/>默认值：true |


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
