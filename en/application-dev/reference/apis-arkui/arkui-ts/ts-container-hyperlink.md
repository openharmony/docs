# Hyperlink

The **Hyperlink** component implements a link from a location in the component to another location.

>  **NOTE**
>
>  - This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>  - This component must be used with the system browser.

## Required Permissions

If Internet access is required, you need to apply for the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../../security/AccessToken/declare-permissions.md).

## Child Components

This component can contain the [Image](ts-basic-components-image.md) child component.

## APIs

Hyperlink(address: string | Resource, content?: string | Resource)

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| address | string \| [Resource](ts-types.md#resource) | Yes| Web page to which the hyperlink is redirected.|
| content | string \| [Resource](ts-types.md#resource) | No| Text displayed in the hyperlink.<br>**NOTE**<br>If this component has child components, the hyperlink text is not displayed.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

### color

color(value: Color | number | string | Resource)

Sets the color of the hyperlink text.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description              |
| ------ | ------------------------------------------------------------ | ---- | ------------------ |
| value  | [Color](ts-appendix-enums.md#color) \| number \| string \| [Resource](ts-types.md#resource) | Yes  | Color of the hyperlink text<br>Default value: **'#ff007dff'**|

## Example

```ts
@Entry
@Component
struct HyperlinkExample {
  build() {
    Column() {
      Column() {
        Hyperlink('https://example.com/') {
          Image($r('app.media.bg'))
            .width(200)
            .height(100)
        }
      }

      Column() {
        Hyperlink('https://example.com/', 'Go to the developer website') {
        }
        .color(Color.Blue)
      }
    }.width('100%').height('100%').justifyContent(FlexAlign.Center)
  }
}
```

![hyperlink](figures/hyperlink.PNG)
