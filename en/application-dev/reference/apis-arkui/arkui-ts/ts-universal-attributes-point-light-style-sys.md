# Point Light Style (System API)

You can apply a point light style to components.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The point light style is only available for the following components: **\<Image>**, **\<Column>**, **\<Flex>**, **\<Row>**, **\<Stack>**

## PointLightStyle

You apply a point light style by setting the light source that emits illumination and the components to be illuminated.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type                                                   | Mandatory| Description                                                        |
| ----------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| lightSource | [LightSource](#lightsource)                         | No  | Light source. The light source affects the surrounding components that are marked as illuminable and creates light effects on those components.<br>Default value: none|
| illuminated | [IlluminatedType](ts-appendix-enums-sys.md#illuminatedtype) | No  | Whether the current component can be illuminated by the light source and the illuminated type.<br>Default value: **IlluminatedType.NONE**|
| bloom       | number                                                      | No  | Luminous intensity of the component. The recommended value range is 0-1.<br>Default value: **0**       |

## LightSource

Each component allows for one light source.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name               | Type                                  | Mandatory| Description                                                    |
| ------------------- | ------------------------------------------ | ---- | -------------------------------------------------------- |
| positionX           | [Dimension](ts-types.md#dimension10)       | Yes  | X-coordinate of the light source relative to the current component.                             |
| positionY           | [Dimension](ts-types.md#dimension10)       | Yes  | Y-coordinate of the light source relative to the current component.                             |
| positionZ           | [Dimension](ts-types.md#dimension10)       | Yes  | Height of the light source. The higher the light source, the broader the light distribution.                      |
| intensity           | number                                     | Yes  | Intensity of the light source. The recommended value range is 0-1. When the intensity is **0**, the light source does not emit light.|
| color<sup>12+</sup> | [ResourceColor](ts-types.md#resourcecolor) | No  | Light source color.<br>Default value: **Color.White**                      |

## Example

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
