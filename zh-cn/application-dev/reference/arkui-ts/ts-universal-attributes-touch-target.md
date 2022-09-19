# 触摸热区设置

适用于支持通用点击事件、通用触摸事件、通用手势处理的组件。

>  **说明：**
>
>  从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性


| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| responseRegion | Array&lt;Rectangle&gt;&nbsp;\|&nbsp;Rectangle | 设置一个或多个触摸热区，包括位置和大小。<br/>默认值：<br/>{<br/>x：0,<br/>y：0,<br/>width：'100%',<br/>height：'100%'<br/>} |


### Rectangle对象说明
| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| x | [Length](ts-types.md) | 否 | 触摸点相对于组件本身左边沿的X坐标。<br/>默认值：0vp |
| y | [Length](ts-types.md) | 否 | 触摸点相对于组件本身左边沿的Y坐标。<br/>默认值：0vp |
| width | [Length](ts-types.md) | 否 | 触摸热区范围的宽度。<br/>默认值：100% |
| height | [Length](ts-types.md) | 否 | 触摸热区范围的高度。<br/>默认值：100% |

  >  **说明：**
  >
  >  x和y可以设置正负值百分比。当x设置为'100%'时表示热区往右偏移组件本身宽度大小，当x设置为'-100%'时表示热区往左偏移组件本身宽度大小。当y设置为'100%'时表示热区往下偏移组件本身高度大小，当y设置为'-100%'时表示热区往上偏移组件本身高度大小。
  >
  >  width和height只能设置正值百分比。width：'100%'表示热区宽度设置为该组件本身的宽度。比如组件本身宽度是100vp，那么'100%'表示热区宽度也为100vp。height：'100%'表示热区高度设置为该组件本身的高度。
  >
  >  百分比是相对于组件本身来度量的。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ResponseRegionExample {
  build() {
    Column() {
        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .selectedColor(0x39a2db)
          .backgroundColor(0xAFEEEE)
          .responseRegion({ x: 1.0, y: 1.0, width: 400, height: 400 })
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
    }.width('100%').margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001184400598](figures/zh-cn_image_0000001184400598.gif)
