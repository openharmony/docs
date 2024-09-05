# SaveButton
 
The **SaveButton** security component allows you to obtain temporary storage permission from the user by their touching the button, eliminating the need for a permission request dialog box.

> **NOTE**
>
> This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

### SaveButton

SaveButton()

Creates a Save button with an icon, text, and background.

You may want to learn the [restrictions on security component styles](../../../security/AccessToken/security-component-overview.md#constraints) to avoid authorization failures caused by incompliant styles.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### SaveButton

SaveButton(options:SaveButtonOptions)

Creates a Save button that contains the specified elements.

You may want to learn the [restrictions on security component styles](../../../security/AccessToken/security-component-overview.md#constraints) to avoid authorization failures caused by incompliant styles.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [SaveButtonOptions](#savebuttonoptions) | Yes| Creates a Save button that contains the specified elements.|

## SaveButtonOptions

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| icon | [SaveIconStyle](#saveiconstyle) | No| Icon style of the Save button.<br>If this parameter is not specified, no icon is contained. Either **icon** or **text**, or both, must be set.|
| text | [SaveDescription](#savedescription) | No| Text on the Save button.<br>If this parameter is not specified, no text is contained. Either **icon** or **text**, or both, must be set.|
| buttonType | [ButtonType](ts-basic-components-button.md#buttontype) | No| Background type of the Save button.<br>If this parameter is not specified, the system uses a capsule-type button as the Save button.|

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
| DOWNLOAD | 0 | The text on the Save button is **Download**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DOWNLOAD_FILE | 1 | The text on the Save button is **Download File**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SAVE | 2 | The text on the Save button is **Save**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SAVE_IMAGE | 3 | The text on the Save button is **Save Image**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SAVE_FILE | 4 | The text on the Save button is **Save File**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| DOWNLOAD_AND_SHARE | 5 | The text on the Save button is **Download and Share**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| RECEIVE | 6 | The text on the Save button is **Receive**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| CONTINUE_TO_RECEIVE | 7 | The text on the Save button is **Continue**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SAVE_TO_GALLERY<sup>12+</sup> | 8 | The text on the Save button is **Save to Gallery**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| EXPORT_TO_GALLERY<sup>12+</sup> | 9 | The text on the Save button is **Export**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| QUICK_SAVE_TO_GALLERY<sup>12+</sup> | 10 | The text on the Save button is **Quick Save**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| RESAVE_TO_GALLERY<sup>12+</sup> | 11 | The text on the Save button is **Resave**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## SaveButtonOnClickResult

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value| Description|
| -------- | -------- | -------- |
| SUCCESS | 0 | The Save button is touched successfully.|
| TEMPORARY_AUTHORIZATION_FAILED | 1 | Temporary authorization fails after the Save button is touched.|

## Attributes

This component can only inherit the [universal attributes of security components](ts-securitycomponent-attributes.md).

## Events

Only the following events are supported.

### onClick

onClick(event: (event: ClickEvent, result: SaveButtonOnClickResult) =&gt; void)

Called when a click event occurs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                  | Mandatory| Description                  |
|------------|------|-------|---------|
| event  | [ClickEvent](ts-universal-events-click.md#clickevent) |Yes|See **ClickEvent**.|
| result | [SaveButtonOnClickResult](#savebuttononclickresult)| Yes| Authorization result. The authorization is effective for 10 seconds. This means that, a specific media library API can be called, an unlimited number of times, within 10 seconds of the touch. If the API is not called within the 10 seconds, the authorization fails.|

## Example

```ts
// xxx.ets
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { fileIo } from '@kit.CoreFileKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column({space:10}) {
        // Create a default Save button with an icon, text, and background.
        SaveButton().onClick(async (event:ClickEvent, result:SaveButtonOnClickResult) => {
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
              console.error("error is "+ JSON.stringify(error));
            }
          }
        })
        // Whether the button has an icon, text, and background depends on whether the corresponding parameter is passed in. If buttonType is not passed in, the button uses the ButtonType.Capsule settings.
        SaveButton({icon:SaveIconStyle.FULL_FILLED})
        // This button only has the icon and background. If the alpha value of the most significant eight bits of the background color is less than 0x1A, the system forcibly adjusts the alpha value to 0xFF.
        SaveButton({icon:SaveIconStyle.FULL_FILLED, buttonType:ButtonType.Capsule})
          .backgroundColor(0x10007dff)
        // The button has an icon, text, and background. If the alpha value of the most significant eight bits of the background color is less than 0x1A, the system forcibly adjusts the alpha value to 0xFF.
        SaveButton({icon:SaveIconStyle.FULL_FILLED, text:SaveDescription.DOWNLOAD, buttonType:ButtonType.Capsule})
        // Create a button with an icon, text, and background. If the set width is less than the minimum allowed, the button's text will wrap to guarantee full text display.
        SaveButton({icon:SaveIconStyle.FULL_FILLED, text:SaveDescription.DOWNLOAD, buttonType:ButtonType.Capsule})
          .fontSize(16)
          .width(30)
        // Create a button with an icon, text, and background. If the set width is less than the minimum allowed, the button's text will wrap to guarantee full text display.
        SaveButton({icon:SaveIconStyle.FULL_FILLED, text:SaveDescription.DOWNLOAD, buttonType:ButtonType.Capsule})
          .fontSize(16)
          .size({width: 30, height: 30})
        // Create a button with an icon, text, and background. If the set width is less than the minimum allowed, the button's text will wrap to guarantee full text display.
        SaveButton({icon:SaveIconStyle.FULL_FILLED, text:SaveDescription.DOWNLOAD, buttonType:ButtonType.Capsule})
          .fontSize(16)
          .constraintSize({minWidth: 0, maxWidth: 30, minHeight: 0, maxHeight: 30})
      }.width('100%')
    }.height('100%')
  }
}
```

![en-us_image_0000001643320073](figures/en-us_image_0000001643320073.png)
