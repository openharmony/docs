# ContainerSpan

As a child of the [Text](ts-basic-components-text.md) component, the **ContainerSpan** component is used to manage the background colors and rounded corners of multiple [Span](ts-basic-components-span.md) and [ImageSpan](ts-basic-components-imagespan.md) components in a unified manner.

> **NOTE**
>
> This component is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

This component can contain the [Span](ts-basic-components-span.md) and [ImageSpan](ts-basic-components-imagespan.md) child components.

## APIs

ContainerSpan()

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## Attributes

Only the following attributes are supported.

### textBackgroundStyle

textBackgroundStyle(style: TextBackgroundStyle)

Sets the text background style. If this attribute is not separately set for a child component, the child component inherits the settings from the component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                               | Mandatory| Description                                                        |
| ------ | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| style  | [TextBackgroundStyle](ts-basic-components-span.md#textbackgroundstyle11) | Yes  | Text background style.<br>Default value:<br>{<br>  color: Color.Transparent,<br>  radius: 0<br>} |

### attributeModifier<sup>12+</sup>

attributeModifier(modifier: AttributeModifier\<ContainerSpanAttribute>)

Creates an attribute modifier.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                               | Mandatory| Description                                                        |
| ------ | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| modifier  | [AttributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifiert)\<ContainerSpanAttribute> | Yes  | Modifier for dynamically setting attributes on the current component.|

## Events

The [universal events](ts-universal-events-click.md) are not supported.

## Example

This example demonstrates the effect of setting a background style for text using the **textBackgroundStyle** attribute.

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
