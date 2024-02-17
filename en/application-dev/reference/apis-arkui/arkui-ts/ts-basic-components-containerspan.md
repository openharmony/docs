# ContainerSpan

As a child of the [\<Text>](ts-basic-components-text.md) component, the **\<ContainerSpan>** component is used to manage the background colors and rounded corners of multiple [\<Span>](ts-basic-components-span.md) and [\<ImageSpan>](ts-basic-components-imagespan.md) components in a unified manner.

> **NOTE**
>
> This component is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

This component can contain the [\<Span>](ts-basic-components-span.md) and [\<ImageSpan>](ts-basic-components-imagespan.md) child components.

## APIs

ContainerSpan()

## Attributes

Only the [TextBackgroundStyle](#textbackgroundstyle) attribute is supported.

| Name                                      | Type                                | Description                                                                                                                                               |
| ------------------------------------------ | ---------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------- |
| textBackgroundStyle | [TextBackgroundStyle](#textbackgroundstyle) | Text background style.<br>Default value:<br>{<br>  color: Color.Transparent,<br>  radius: 0<br>} <br>**NOTE**<br>If this attribute is not separately set for a child component, the child component inherits the settings from the component.|

## TextBackgroundStyle

| Name  | Type                                                                | Mandatory| Description        |
| ------ | ------------------------------------------------------------------------ | ---- | ------------ |
| color  | [ResourceColor](ts-types.md#resourcecolor)                                  | No  | Text background color.|
| radius | [Dimension](ts-types.md#dimension10) \| [BorderRadiuses](ts-universal-attributes-border.md#borderradiuses9) | No  | Rounded corner radius of the text background.|

## Events

The [universal events](ts-universal-events-click.md) are not supported.

## Example

### Example 1

```ts
// xxx.ets
@Component
@Entry
struct Index {
  build() {
    Column() {
      Text() {
        ContainerSpan() {
          ImageSpan($r('app.media.app_icon'))
            .width('40vp')
            .height('40vp')
            .verticalAlign(ImageSpanAlignment.CENTER)
          Span('   Hello World !   ').fontSize('16fp').fontColor(Color.White)
        }.textBackgroundStyle({color: "#7F007DFF", radius: "12vp"})
      }
    }.width('100%').alignItems(HorizontalAlign.Center)
  }
}
```

![imagespan](figures/container_span.png)
