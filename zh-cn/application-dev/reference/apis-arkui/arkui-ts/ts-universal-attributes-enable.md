# 禁用控制
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--SE: @piggyguy-->
<!--TSE: @songyanhong-->

组件可交互状态下响应[点击事件](ts-universal-events-click.md)、[触摸事件](ts-universal-events-touch.md)、[拖拽事件](ts-universal-events-drag-drop.md)、[按键事件](ts-universal-events-key.md)、[焦点事件](ts-universal-focus-event.md)、[鼠标事件](ts-universal-mouse-key.md)、[轴事件](ts-universal-events-axis.md)、[悬浮事件](ts-universal-events-hover.md)、[无障碍悬浮事件](ts-universal-accessibility-hover-event.md)、[手势事件](ts-gesture-settings.md)、[焦点轴事件](ts-universal-events-focus_axis.md)和[表冠事件](ts-universal-events-crown.md)。

>  **说明：**
>
>  从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  禁用控制属性仅在按下时生效，交互过程中更改enabled属性无效。

## enabled

enabled(value: boolean): T

设置组件是否可交互。当未设置enabled时，组件默认可交互。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 值为true表示组件可交互，响应点击等操作。<br/>值为false表示组件不可交互，不响应点击等操作。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## 示例

该示例通过enable设置按钮可交互性。

```ts
// xxx.ets
@Entry
@Component
struct EnabledExample {

  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // 点击时无响应
      Button('disable').enabled(false).backgroundColor(0x317aff).opacity(0.4)
      Button('enable').backgroundColor(0x317aff)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001219982713](figures/zh-cn_image_0000001219982713.gif)
