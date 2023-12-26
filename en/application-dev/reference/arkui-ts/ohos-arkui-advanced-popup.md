# @ohos.arkui.advanced.Popup (Popup)

The popup component is used to display popups in a specific style.

>  **NOTE**
>
>  This component is supported since API version 11. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import { Popup , PopupOptions,PopupTextOptions, PopupButtonOptions, PopupIconOptions } from '@ohos.arkui.advanced.Popup';
```

##  Child Components

Not supported

## Popup

Popup(options: PopupOptions)

**Decorator**: @Builder

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type                         | Mandatory| Description                 |
| ------- | ----------------------------- | ---- | --------------------- |
| options | [PopupOptions](#popupoptions) | Yes  | Type of the popup.|

## PopupOptions

Defines the style parameters of the popup.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type      | Mandatory       | Description                           |
| ----------- | ---------- | ------| --------------------------------- |
| icon      | [PopupIconOptions](#popupiconoptions)                        | No  | Icon of the popup.                     |
| title     | [PopupTextOptions](#popuptextoptions)                        | No  | Title of the popup.                 |
| message   | [PopupTextOptions](#popuptextoptions)                        | Yes  | Content of the popup.                 |
| showClose | boolean                                                      | No  | Whether to show the close button.                 |
| onClose   | () => void                                                   | No  | Callback for the popup close button.         |
| buttons   | [[PopupButtonOptions](#popupbuttonoptions)?,[PopupButtonOptions](#popupbuttonoptions)?] | No  | Buttons of the popup. A maximum of two buttons can be set.|

## PopupTextOptions

Defines the text parameters of the popup.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type                                                        | Mandatory| Description              |
| ---------- | ------------------------------------------------------------ | ---- | ------------------ |
| text       | [ResourceStr](ts-types.md#resourcestr)                       | Yes  | Text content.    |
| fontSize   | number \| string \| [Resource](ts-types.md#resource)         | No  | Text font size.|
| fontColor  | [ResourceColor](ts-types.md#resourcecolor)                   | No  | Text font color.|
| fontWeight | number \| [FontWeight](ts-appendix-enums.md#fontweight)\| string | No  | Text font weight.|

## PopupButtonOptions

Defines the button attributes and events.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                                | Mandatory| Description                  |
| --------- | ---------------------------------------------------- | ---- | ---------------------- |
| text      | [ResourceStr](ts-types.md#resourcestr)               | Yes  | Text of the button.        |
| action    | () => void                                           | No  | Click callback of the button.   |
| fontSize  | number \| string \| [Resource](ts-types.md#resource) | No  | Font size of the button text.|
| fontColor | [ResourceColor](ts-types.md#resourcecolor)           | No  | Font color of the button text.|

##  PopupIconOptions

Defines the attributes of the icon (in the upper right corner).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name        | Type                                                        | Mandatory| Description              |
| ------------ | ------------------------------------------------------------ | ---- | ------------------ |
| image        | [PixelMap](../apis/js-apis-image.md#pixelmap7)\| [ResourceStr](ts-types.md#resourcestr)\| [DrawableDescriptor](../apis/js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | Yes  | Icon content.    |
| width        | [Dimension](ts-types.md#dimension10)                         | No  | Icon width.    |
| height       | [Dimension](ts-types.md#dimension10)                         | No  | Icon height.    |
| fillColor    | [ResourceColor](ts-types.md#resourcecolor)                   | No  | Icon fill color.|
| borderRadius | [Length](ts-types.md#length)\| [BorderRadiuses](ts-types.md#borderradiuses9) | No  | Rounded corner of the icon.    |

## Example  

```ts
// xxx.ets
import { Popup , PopupOptions,PopupTextOptions, PopupButtonOptions, PopupIconOptions } from '@ohos.arkui.advanced.Popup';

@Entry
@Component
struct PopupExample {

  build() {
    Row() {
      // Define the custom advanced component through popup.
      Popup({
        // Set the icon through PopupIconOptions.
        icon: {
          image: $r('app.media.icon'),
          width:32,
          height:32,
          fillColor:Color.White,
          borderRadius: 16,
        } as PopupIconOptions,
        // Set the text through PopupTextOptions.
        title: {
          text: 'This is a popup with PopupOptions',
          fontSize: 20,
          fontColor: Color.Black,
          fontWeight: FontWeight.Normal,

        } as PopupTextOptions,
        // Set the text through PopupTextOptions.
        message: {
          text: 'This is the message',
          fontSize: 15,
          fontColor: Color.Black,
          fontWeight: FontWeight.Normal,
        } as PopupTextOptions,
        showClose: false,
        onClose: () => {
          console.info('close Button click')
        },
        // Set the button through PopupButtonOptions.
        buttons: [{
          text: 'confirm',
          action: () => {
            console.info('confirm button click')
          },
          fontSize: 15,
          fontColor: Color.Black,

        },
          {
            text: 'cancel',
            action: () => {
              console.info('cancel button click')
            },
            fontSize: 15,
            fontColor: Color.Black,
          },] as [PopupButtonOptions?, PopupButtonOptions?],
      })
    }
    .width(300)
    .height(200)
    .borderWidth(2)
    .borderColor(Color.Red)
    .justifyContent(FlexAlign.Center)
  }
}
```

![](figures/popup_7.png)
