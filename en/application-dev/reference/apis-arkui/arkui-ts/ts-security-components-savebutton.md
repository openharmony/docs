# SaveButton

The **SaveButton** security component represents a save button that allows you to obtain temporary storage permissions from users with a simple button touch, eliminating the need for a permission request dialog box.

> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

### SaveButton

SaveButton()

Creates a **SaveButton** component with an icon, text, and background.

You may want to learn the [restrictions on security component styles](../../../security/AccessToken/security-component-overview.md#constraints) to avoid authorization failures caused by incompliant styles.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### SaveButton

SaveButton(options: SaveButtonOptions)

Creates a **SaveButton** component that contains the specified elements.

You may want to learn the [restrictions on security component styles](../../../security/AccessToken/security-component-overview.md#constraints) to avoid authorization failures caused by incompliant styles.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [SaveButtonOptions](#savebuttonoptions) | Yes| Options for creating the **SaveButton** component.|

## SaveButtonOptions

Describes the icon, text, and other specific elements for the **SaveButton** component.

> **NOTE**
>
> - At least one of **icon** or **text** must be provided.<br>
> - If neither **icon** nor **text** is provided, the **options** parameter in [SaveButton](#savebutton-1) will not take effect, and the created **SaveButton** component will use the default style:
>
>   The default value of **SaveIconStyle** is **FULL_FILLED**.
>
>   The default style of **SaveDescription** is **DOWNLOAD**.
>
>   The default value of **ButtonType** is **Capsule**.
> - The **icon**, **text**, and **buttonType** parameters do not support dynamic modification.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | [SaveIconStyle](#saveiconstyle) | No| Icon style of the **SaveButton** component.<br>If this parameter is not specified, there is no icon.|
| text | [SaveDescription](#savedescription) | No| Text on the **SaveButton** component.<br>If this parameter is not specified, there is no text description.|
| buttonType | [ButtonType](ts-securitycomponent-attributes.md#buttontype) | No| Background type of the **SaveButton** component.<br>If this parameter is not specified, the system uses a capsule-type button as the **SaveButton** component.|

## SaveIconStyle

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| FULL_FILLED | 0 | Filled style icon.|
| LINES | 1 | Line style icon.|

## SaveDescription

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| DOWNLOAD | 0 | The text on the **SaveButton** component is **Download**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DOWNLOAD_FILE | 1 | The text on the **SaveButton** component is **Download file**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SAVE | 2 | The text on the **SaveButton** component is **Save**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SAVE_IMAGE | 3 | The text on the **SaveButton** component is **Save image**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SAVE_FILE | 4 | The text on the **SaveButton** component is **Save file**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DOWNLOAD_AND_SHARE | 5 | The text on the **SaveButton** component is **Download & share**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| RECEIVE | 6 | The text on the **SaveButton** component is **Receive**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| CONTINUE_TO_RECEIVE | 7 | The text on the **SaveButton** component is **Continue**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SAVE_TO_GALLERY<sup>12+</sup> | 8 | The text on the **SaveButton** component is **Save to Gallery**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| EXPORT_TO_GALLERY<sup>12+</sup> | 9 | The text on the **SaveButton** component is **Export**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| QUICK_SAVE_TO_GALLERY<sup>12+</sup> | 10 | The text on the **SaveButton** component is **Save to Gallery**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| RESAVE_TO_GALLERY<sup>12+</sup> | 11 | The text on the **SaveButton** component is **Save**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| SAVE_ALL<sup>18+</sup> | 12 | The text on the **SaveButton** component is **Save all**.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## SaveButtonOnClickResult

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| SUCCESS | 0 | The **SaveButton** component is touched successfully.|
| TEMPORARY_AUTHORIZATION_FAILED | 1 | Temporary authorization fails after the **SaveButton** component is touched.|

## SaveButtonCallback<sup>18+</sup>

type SaveButtonCallback = (event: ClickEvent, result: SaveButtonOnClickResult, error?: BusinessError&lt;void&gt;) =&gt; void

Triggered when the **SaveButton** component is clicked.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| event | [ClickEvent](ts-universal-events-click.md#clickevent) |Yes|See **ClickEvent**.|
| result | [SaveButtonOnClickResult](#savebuttononclickresult)| Yes| Authorization result. The authorization is effective for 10 seconds. This means that, a specific media library API can be called, an unlimited number of times, within 10 seconds of the touch. If the API is not called within the 10 seconds, the authorization fails.|
| error | [BusinessError&lt;void&gt;](../../apis-basic-services-kit/js-apis-base.md#businesserror) | No| Error code and message when the component is clicked.<br>Error code 0 indicates successful authorization.<br>Error code 1 indicates an internal system error.<br>Error code 2 indicates attribute setting errors, including but not limited to:<br>1. The font or icon size is too small.<br>2. The font or icon color is too similar to the background color.<br>3. The font or icon color is too transparent.<br>4. The padding is negative.<br>5. The component is obscured by other components or windows.<br>6. The text exceeds the background range.<br>7. The component exceeds the window or screen bounds.<br>8. The component size is too large.<br>9. The component text is truncated and not fully displayed.<br>10. Related attribute settings affect the display of security components.|

## Attributes

This component can only inherit the [universal attributes of security components](ts-securitycomponent-attributes.md).

## Events

Only the following events are supported.

### onClick

onClick(event: SaveButtonCallback)

Called when a click event occurs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| event | [SaveButtonCallback](#savebuttoncallback18) |Yes|See **SaveButtonCallback**.<br>In API versions 10 to 17, the parameter type is event: [ClickEvent](ts-universal-events-click.md#clickevent), result: [SaveButtonOnClickResult](#savebuttononclickresult)) => void.<br>Since API version 18, the parameter type changes into SaveButtonCallback.|

## Example

```ts
// xxx.ets
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  handleSaveButtonClick: SaveButtonCallback =
    async (event: ClickEvent, result: SaveButtonOnClickResult, error: BusinessError<void>) => {
      if (result == SaveButtonOnClickResult.SUCCESS) {
        try {
          const context = getContext(this);
          let helper = photoAccessHelper.getPhotoAccessHelper(context);
          // After onClick is triggered, the createAsset API can be called within 10 seconds to create an image file. After 10 seconds have elapsed, the permission to call createAsset is revoked.
          let uri = await helper.createAsset(photoAccessHelper.PhotoType.IMAGE, 'png');
          // Use the URI to open the file. The write process is not time bound.
          let file = await fileIo.open(uri, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
          // Write to the file.
          await fileIo.write(file.fd, "context");
          // Close the file.
          await fileIo.close(file.fd);
        } catch (error) {
          console.error("error is " + JSON.stringify(error));
        }
      } else {
        console.info("errCode: " + error.code);
        console.info("errMessage: " + error.message);
      }
    };

  build() {
    Row() {
      Column({ space: 10 }) {
        // Create a default button with an icon, text, and background.
        SaveButton().onClick((this.handleSaveButtonClick))
        // Whether the button has an icon, text, and background depends on whether the corresponding parameter is passed in. If buttonType is not passed in, the button uses the ButtonType.Capsule settings.
        SaveButton({ icon: SaveIconStyle.FULL_FILLED })
        // Create a button with only an icon and background. If the alpha value of the most significant eight bits of the background color is less than 0x1A, the system forcibly adjusts the alpha value to 0xFF.
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, buttonType: ButtonType.Capsule })
          .backgroundColor(0x10007dff)
        // Create a button with an icon, text, and background. If the alpha value of the most significant eight bits of the background color is less than 0x1A, the system forcibly adjusts the alpha value to 0xFF.
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, text: SaveDescription.DOWNLOAD, buttonType: ButtonType.Capsule })
        // Create a button with an icon, text, and background. If the set width is less than the minimum allowed, the button's text will wrap to guarantee full text display.
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, text: SaveDescription.DOWNLOAD, buttonType: ButtonType.Capsule })
          .fontSize(16)
          .width(30)
        // Create a button with an icon, text, and background. If the set width is less than the minimum allowed, the button's text will wrap to guarantee full text display.
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, text: SaveDescription.DOWNLOAD, buttonType: ButtonType.Capsule })
          .fontSize(16)
          .size({ width: 30, height: 30 })
        // Create a button with an icon, text, and background. If the set width is less than the minimum allowed, the button's text will wrap to guarantee full text display.
        SaveButton({ icon: SaveIconStyle.FULL_FILLED, text: SaveDescription.DOWNLOAD, buttonType: ButtonType.Capsule })
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

![en-us_image_0000001643320073](figures/en-us_image_0000001643320073.png)
