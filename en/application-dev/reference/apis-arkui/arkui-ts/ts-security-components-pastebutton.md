# PasteButton

The **PasteButton** security component represents a paste button that allows you to obtain temporary pasteboard permissions from users with a simple button touch.

> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

### PasteButton

PasteButton()

Creates a **PasteButton** component with an icon, text, and background.

You may want to learn the [restrictions on security component styles](../../../security/AccessToken/security-component-overview.md#constraints) to avoid authorization failures caused by incompliant styles.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### PasteButton

PasteButton(options: PasteButtonOptions)

Creates a **PasteButton** component that contains the specified elements.

You may want to learn the [restrictions on security component styles](../../../security/AccessToken/security-component-overview.md#constraints) to avoid authorization failures caused by incompliant styles.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [PasteButtonOptions](#pastebuttonoptions) | Yes| Options for creating the **PasteButton** component.<br>Default value:<br>{<br>icon: PasteIconStyle.LINES,<br>text: PasteDescription.PASTE,<br>buttonType: ButtonType.Capsule <br>} |

## PasteButtonOptions

Describes the icon, text, and other specific elements for the **PasteButton** component.

> **NOTE**
>
> - At least one of **icon** or **text** must be provided.<br>
> - If neither **icon** nor **text** is provided, the **options** parameter in [PasteButton](#pastebutton-1) will not take effect, and the created **PasteButton** component will use the default style:
>
>   The default value of **PasteIconStyle** is **LINES**.
>
>   The default style of **PasteDescription** is **PASTE**.
>
>   The default value of **ButtonType** is **Capsule**.
> - The **icon**, **text**, and **buttonType** parameters do not support dynamic modification.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | [PasteIconStyle](#pasteiconstyle) | No| Icon style of the **PasteButton** component.<br>If this parameter is not specified, there is no icon.|
| text | [PasteDescription](#pastedescription) | No| Text on the **PasteButton** component.<br>If this parameter is not specified, there is no text description.|
| buttonType | [ButtonType](ts-securitycomponent-attributes.md#buttontype) | No| Background style of the **PasteButton** component.<br>If this parameter is not specified, the system uses a capsule-type button.|

## Attributes

This component can only inherit the [universal attributes of security components](ts-securitycomponent-attributes.md).

## PasteIconStyle

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| LINES | 0 | Line style icon.|

## PasteDescription

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| PASTE | 0 | The text on the **PasteButton** component is **Paste**.|

## PasteButtonOnClickResult

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| SUCCESS | 0 | The **PasteButton** component is touched successfully.|
| TEMPORARY_AUTHORIZATION_FAILED | 1 | Temporary authorization fails after the **PasteButton** component is touched.|

## PasteButtonCallback<sup>18+</sup>

type PasteButtonCallback = (event: ClickEvent, result: PasteButtonOnClickResult, error?: BusinessError&lt;void&gt;) =&gt; void

Triggered when the **PasteButton** component is clicked.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| event | [ClickEvent](ts-universal-events-click.md#clickevent) |Yes|See **ClickEvent**.|
| result | [PasteButtononClickResult](#pastebuttononclickresult)| Yes| Authorization result. After the authorization, the pasteboard content can be read.|
| error | [BusinessError&lt;void&gt;](../../apis-basic-services-kit/js-apis-base.md#businesserror) | No| Error code and message when the component is clicked.<br>Error code 0 indicates successful authorization.<br>Error code 1 indicates an internal system error.<br>Error code 2 indicates attribute setting errors, including but not limited to:<br>1. The font or icon size is too small.<br>2. The font or icon color is too similar to the background color.<br>3. The font or icon color is too transparent.<br>4. The padding is negative.<br>5. The component is obscured by other components or windows.<br>6. The text exceeds the background range.<br>7. The component exceeds the window or screen bounds.<br>8. The component size is too large.<br>9. The component text is truncated and not fully displayed.<br>10. Related attribute settings affect the display of security components.|

## Events

Only the following events are supported.

### onClick

onClick(event: PasteButtonCallback)

Called when a click event occurs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| event | [PasteButtonCallback](#pastebuttoncallback18) |Yes|See **PasteButtonCallback**.<br>In API versions 10 to 17, the parameter type is event: [ClickEvent](ts-universal-events-click.md#clickevent), result: [PasteButtononClickResult](#pastebuttononclickresult)) => void.<br>Since API version 18, the parameter type changes into PasteButtonCallback.|

## Example

```ts
// xxx.ets
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  handlePasteButtonClick: PasteButtonCallback =
    (event: ClickEvent, result: PasteButtonOnClickResult, error: BusinessError<void>) => {
      if (result == PasteButtonOnClickResult.SUCCESS) {
        console.info("success");
      } else {
        console.info("errCode: " + error.code);
        console.info("errMessage: " + error.message);
      }
    };

  build() {
    Row() {
      Column({ space: 10 }) {
        // Create a default button with an icon, text, and background.
        PasteButton().onClick(this.handlePasteButtonClick)
        // Whether an element is contained depends on whether the parameter corresponding to the element is specified. If buttonType is not passed in, the button uses the ButtonType.Capsule settings.
        PasteButton({ icon: PasteIconStyle.LINES })
        // Create a button with only an icon and background. If the alpha value of the most significant eight bits of the background color is less than 0x1A, the system forcibly adjusts the alpha value to 0xFF.
        PasteButton({ icon: PasteIconStyle.LINES, buttonType: ButtonType.Capsule })
          .backgroundColor(0x10007dff)
        // Create a button with an icon, text, and background. If the alpha value of the most significant eight bits of the background color is less than 0x1A, the system forcibly adjusts the alpha value to 0xFF.
        PasteButton({ icon: PasteIconStyle.LINES, text: PasteDescription.PASTE, buttonType: ButtonType.Capsule })
        // Create a button with an icon, text, and background. If the set width is less than the minimum allowed, the button's text will wrap to guarantee full text display.
        PasteButton({ icon: PasteIconStyle.LINES, text: PasteDescription.PASTE, buttonType: ButtonType.Capsule })
          .fontSize(16)
          .width(30)
        // Create a button with an icon, text, and background. If the set width is less than the minimum allowed, the button's text will wrap to guarantee full text display.
        PasteButton({ icon: PasteIconStyle.LINES, text: PasteDescription.PASTE, buttonType: ButtonType.Capsule })
          .fontSize(16)
          .size({ width: 30, height: 30 })
        // Create a button with an icon, text, and background. If the set width is less than the minimum allowed, the button's text will wrap to guarantee full text display.
        PasteButton({ icon: PasteIconStyle.LINES, text: PasteDescription.PASTE, buttonType: ButtonType.Capsule })
          .fontSize(16)
          .constraintSize({
            minWidth: 0,
            maxWidth: 30,
            minHeight: 0,
            maxHeight: 30
          })
      }.width('100%')
    }.height('100%')
  }
}
```

![en-us_image_0000001593677984](figures/en-us_image_0000001593677984.png)
