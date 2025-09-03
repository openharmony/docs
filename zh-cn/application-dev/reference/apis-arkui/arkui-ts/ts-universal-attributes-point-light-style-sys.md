# 点光源设置 (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

设置点光源样式。

>  **说明：**
>
>  从API Version 11开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  只有Image、Column、Flex、Row、Stack支持设置点光源。

## PointLightStyle

通过设置光源和被照亮的类型实现点光源照亮周围组件的UI效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 参数类型                                                    | 必填 | 描述                                                         |
| ----------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| lightSource | [LightSource](#lightsource对象说明)                         | 否   | 设置光源属性，光源会影响到周围标记为可以被照亮的组件，并在组件上产生光效。<br/>默认值：无光源 |
| illuminated | [IlluminatedType](ts-appendix-enums-sys.md#illuminatedtype) | 否   | 设置当前组件是否可以被光源照亮，以及被照亮的类型。<br/>默认值：IlluminatedType.NONE |
| bloom       | number                                                      | 否   | 设置组件的发光强度，建议取值范围为0-1。<br/>默认值：0        |

## LightSource对象说明

一个组件支持添加1个光源。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                | 参数类型                                   | 必填 | 描述                                                     |
| ------------------- | ------------------------------------------ | ---- | -------------------------------------------------------- |
| positionX           | [Dimension](ts-types.md#dimension10)       | 是   | 光源相对于当前组件的X坐标。                              |
| positionY           | [Dimension](ts-types.md#dimension10)       | 是   | 光源相对于当前组件的Y坐标。                              |
| positionZ           | [Dimension](ts-types.md#dimension10)       | 是   | 光源高度。光源越高，照射范围越大。                       |
| intensity           | number                                     | 是   | 光源强度，建议取值范围0-1。当光源强度为0时，光源不发光。 |
| color<sup>12+</sup> | [ResourceColor](ts-types.md#resourcecolor) | 否   | 光源颜色。<br/>默认值：Color.White                       |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State lightIntensity: number = 0;
  @State bloomValue: number = 0;

  build() {
    Row({ space: 20 }) {
      Flex()
        .pointLight({ illuminated: IlluminatedType.BORDER })
        .backgroundColor(0x307af7)
        .size({ width: 50, height: 50 })
        .borderRadius(25)

      Flex()
        .pointLight({
          lightSource: { intensity: this.lightIntensity, positionX: "50%", positionY: "50%", positionZ: 80 },
          bloom: this.bloomValue
        })
        .animation({ duration: 333 })
        .backgroundColor(0x307af7)
        .size({ width: 50, height: 50 })
        .borderRadius(25)
        .onTouch((event: TouchEvent) => {
          if (event.type === TouchType.Down) {
            this.lightIntensity = 2;
            this.bloomValue = 1;
          } else if (event.type === TouchType.Up || event.type === TouchType.Cancel) {
            this.lightIntensity = 0;
            this.bloomValue = 0;
          }
        })

      Flex()
        .pointLight({ illuminated: IlluminatedType.BORDER_CONTENT })
        .backgroundColor(0x307af7)
        .size({ width: 50, height: 50 })
        .borderRadius(25)
    }
    .justifyContent(FlexAlign.Center)
    .backgroundColor(Color.Black)
    .size({ width: '100%', height: '100%' })
  }
}
```
