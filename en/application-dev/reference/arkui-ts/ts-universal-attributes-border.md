# Border

You can set border styles for components.
>  **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> The border of a component is displayed above the content of its child components since API version 9.

## Required Permissions

None

## Attributes


| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| border | BorderOptions | - | Unified border style.|
| borderStyle | BorderStyle | &nbsp;BorderStyle.Solid | Border style of an element.|
| borderWidth | Length | 0 | Border width of an element.|
| borderColor | Color | - | Border color of an element.|
| borderRadius | Length | 0 | Border radius of an element.|

- BorderOptions
  | Name| Type| Default Value| Mandatory| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | width | [Length](../../ui/ts-types.md) | 0 | No| Border width.|
  | color | [ResourceColor](../../ui/ts-types.md) | 'Black' | No| Border color.|
  | radius | [Length](../../ui/ts-types.md) | 0 | No| Border radius.|
  | style | BorderStyle | BorderStyle.Solid | No| Border style.|


- BorderStyle enums
  | Name| Description|
  | -------- | -------- |
  | Dotted | Dotted border. The radius of a dot is half of **borderWidth**.|
  | Dashed | Dashed border.|
  | Solid | Solid border.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct BorderExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround, alignItems: ItemAlign.Center }) {
      // Dashed border
      Text('dashed')
        .borderStyle(BorderStyle.Dashed).borderWidth(5).borderColor(0xAFEEEE).borderRadius(10)
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
      // Dotted border
      Text('dotted')
        .border({ width: 5, color: 0x317AF7, radius: 10, style: BorderStyle.Dotted })
        .width(120).height(120).textAlign(TextAlign.Center).fontSize(16)
    }.width('100%').height(150)
  }
}
```

![en-us_image_0000001211898466](figures/en-us_image_0000001211898466.gif)
