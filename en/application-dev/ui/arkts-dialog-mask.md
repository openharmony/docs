# Popup Mask Control
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @houguobiao-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

You can customize not only the content of popups but also their mask behavior. This topic introduces ArkUI's popup mask control capabilities, including dismiss-on-click behavior, mask area, mask color, and mask animations.

## Limitations

ArkUI provides various popup types with different mask customization capabilities as detailed below.

|         API & Component         |autoCancel|maskRect|isModal|immersiveMode|
| ----------------- | ------ |------ |------ |------ |
|[openCustomDialog](arkts-uicontext-custom-dialog.md)|Supported|Supported|Supported|Supported|
|[openCustomDialogWithController](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialogwithcontroller18)|Supported|Supported|Supported|Supported|
|[presentCustomDialog](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#presentcustomdialog18)|Supported|Supported|Supported|Supported|
|[updateCustomDialog](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#updatecustomdialog12)|Supported|Not supported|Not supported|Not supported|
|[CustomDialog](arkts-common-components-custom-dialog.md)|Supported|Supported|Supported|Supported|
|[showDialog](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#showdialog)|Not supported|Supported|Supported|Supported|
|[showAlertDialog](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showalertdialog)|Supported|Supported|Supported|Supported|
|[showActionSheet](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showactionsheet)|Supported|Supported|Supported|Supported|
|[showActionMenu](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#showactionmenu11)|Not supported|Not supported|Supported|Supported|
|[showDatePickerDialog](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showdatepickerdialog)|Not supported|Supported|Not supported|Not supported|
|[CalendarPickerDialog](../reference/apis-arkui/arkui-ts/ts-methods-calendarpicker-dialog.md)|Not supported|Not supported|Not supported|Not supported|
|[showTimePickerDialog](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showtimepickerdialog)|Not supported|Supported|Not supported|Not supported|
|[showTextPickerDialog](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showtextpickerdialog)|Not supported|Supported|Not supported|Not supported|

> **NOTE**
> 
> - **autoCancel**: controls whether clicking the mask dismisses the popup.
>
> - **maskRect**: customizes the mask size and position. Events within the mask area are blocked.
>
> - **isModal**: specifies whether the popup is a modal. Non-modal popups have no mask and allow background interactions, while modal popups have a mask and block background interactions.
>
> - **immersiveMode**: extends the mask to the status and navigation bars when **levelMode** is set to **LevelMode.EMBEDDED**.

| API & Component                                                   | maskColor | transition                                      | maskTransition |
| ------------------------------------------------------------ | --------- | ----------------------------------------------- | -------------- |
| [openCustomDialog](arkts-uicontext-custom-dialog.md)         | Supported     | Supported                                           | Supported          |
| [openCustomDialogWithController](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialogwithcontroller18) | Supported     | Supported                                           | Supported          |
| [presentCustomDialog](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#presentcustomdialog18) | Supported     | Supported                                           | Supported          |
| [updateCustomDialog](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#updatecustomdialog12) | Supported     | Not supported                                         | Not supported        |
| [CustomDialog](arkts-common-components-custom-dialog.md)     | Supported     | Not supported (use **openAnimation** and **closeAnimation**)| Not supported        |
| [showDialog](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#showdialog) | Not supported   | Not supported                                         | Not supported        |
| [showAlertDialog](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showalertdialog) | Not supported   | Supported                                           | Not supported        |
| [showActionSheet](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showactionsheet) | Not supported   | Supported                                           | Not supported        |
| [showActionMenu](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#showactionmenu11) | Not supported   | Not supported                                         | Not supported        |
| [showDatePickerDialog](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showdatepickerdialog) | Not supported   | Not supported                                         | Not supported        |
| [CalendarPickerDialog](../reference/apis-arkui/arkui-ts/ts-methods-calendarpicker-dialog.md) | Not supported   | Not supported                                         | Not supported        |
| [showTimePickerDialog](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showtimepickerdialog) | Not supported   | Not supported                                         | Not supported        |
| [showTextPickerDialog](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#showtextpickerdialog) | Not supported   | Not supported                                         | Not supported        |

> **NOTE**
>
> - **maskColor**: customizes the color of the popup mask.
>
> - **openAnimation**: customizes the popup entry animation, which also affects the mask animation. This API only supports simple animation settings and does not support complex animation customization.
>
> - **closeAnimation**: customizes the popup exit animation, which also affects the mask animation. This API only supports simple animation settings and does not support complex animation customization.
>
> - **transition**: customizes the popup entry and exit animation, which also affect the mask animation.
>
> - **maskTransition**: customizes the popup mask animation.


## Popup Mask Visibility Control

This section demonstrates the popup's mask visibility control capabilities through **autoCancel** and **isModal**.

Set **autoCancel** to **false** to disable the default behavior of dismissing the popup when the mask is touched.

```ts
// xxx.ets
  autoCancelOpt: promptAction.CustomDialogOptions = {
    builder: () => {
      this.myBuilder();
    },
    autoCancel: false,
  } as promptAction.CustomDialogOptions;

  Button("openCustomDialog autoCancel:false")
    .width('100%')
    .margin({ top: 10 })
    .onClick(() => {
      this.getUIContext().getPromptAction().openCustomDialog(this.autoCancelOpt)
    })
```
 ![dialog_mask_autoCancel](figures/dialog_mask_autoCancel.gif)

Set **isModal** to **false** to change the default modal popup to a non-modal popup.
```ts
// xxx.ets
modalOpt: promptAction.CustomDialogOptions = {
  builder: () => {
    this.myBuilder();
  },
  isModal: false,
} as promptAction.CustomDialogOptions;

Button("openCustomDialog isModal:false")
  .width('100%')
  .margin({ top: 10 })
  .onClick(() => {
    this.getUIContext().getPromptAction().openCustomDialog(this.modalOpt)
  })
```
 ![dialog_mask_modal](figures/dialog_mask_modal.PNG)


## Popup Mask Style Control

This example demonstrates the popup's mask style control capabilities using **maskRect**, **immersiveMode**, and **maskColor**.


Set **maskRect** and **maskColor** to set the mask area and mask color.

```ts
// xxx.ets
  maskOpt: promptAction.CustomDialogOptions = {
    builder: () => {
      this.myBuilder();
    },
    maskRect: {
      x: 0,
      y: 10,
      width: '100%',
      height: '90%'
    },
    maskColor: "#33AA0000"
  } as promptAction.CustomDialogOptions;

  Button("openCustomDialog maskOpt")
    .width('100%')
    .margin({ top: 10 })
    .onClick(() => {
      this.getUIContext().getPromptAction().openCustomDialog(this.maskOpt)
    })
```
 ![dialog_mask_mask](figures/dialog_mask_mask.PNG)


When **levelMode** is set to **LevelMode.EMBEDDED**, the following example shows how different **immersiveMode** values affect the mask's extension to the navigation bar and status bar.
```ts
// xxx.ets
  @State immersiveMode: ImmersiveMode = ImmersiveMode.DEFAULT;

  Button("openCustomDialog immersiveMode")
    .width('100%')
    .margin({ top: 10 })
    .onClick(() => {
      this.immersiveMode =
        this.immersiveMode == ImmersiveMode.DEFAULT ? ImmersiveMode.EXTEND : ImmersiveMode.DEFAULT;
      this.getUIContext().getPromptAction().openCustomDialog({
        builder: () => {
          this.myBuilder();
        },
        levelMode: LevelMode.EMBEDDED,
        immersiveMode: this.immersiveMode,
      })
    })
```
 ![dialog_mask_immersiveMode](figures/dialog_mask_immersiveMode.gif)

## Popup Mask Animation Control

This example demonstrates the popup's mask animation capabilities using **transition** and **maskTransition**.

Set **transition** to implement a unified animation for both the popup and its mask.
```ts
// xxx.ets
  transitionOpt: promptAction.CustomDialogOptions = {
    builder: () => {
      this.myBuilder();
    },
    transition: TransitionEffect.OPACITY.animation({ duration: 3000 })
  } as promptAction.CustomDialogOptions;

  Button("openCustomDialog transition")
    .width('100%')
    .margin({ top: 10 })
    .onClick(() => {
      this.getUIContext().getPromptAction().openCustomDialog(this.transitionOpt);
    })
```
 ![dialog_mask_transition](figures/dialog_mask_transition.gif)

Sets **maskTransition** to implement independent animation customization for the popup's mask.
```ts
// xxx.ets
  Button("openCustomDialog maskTransition")
    .width('100%')
    .margin({ top: 10 })
    .onClick(() => {
      this.getUIContext().getPromptAction().openCustomDialog({
        builder: () => {
          this.myBuilder();
        },
        maskTransition: TransitionEffect.OPACITY.animation({ duration: 2000 })
          .combine(TransitionEffect.rotate({ z: 1, angle: 180 })),
      });
    })
```
 ![dialog_mask_maskTransition](figures/dialog_mask_maskTransition.gif)

Although [CustomDialog](arkts-common-components-custom-dialog.md) does not support the **transition** API, the corresponding **openAnimation** and **closeAnimation** APIs can be used to customize the animation for opening and closing the popup. Example code is as follows:

```ts
// xxx.ets

@CustomDialog
@Component
struct CustomDialogExample {
  controller?: CustomDialogController;

  build() {
    Column() {
      Text("title")
        .margin(10)
        .fontSize(20)
      Button("button1")
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.controller?.close();
        })
      Button("button2")
        .margin(10)
        .fontSize(20)
        .onClick(() => {
          this.controller?.close();
        })
    }.width('100%')
    .height('50%')
  }
}

@Entry
@Component
struct Index {
  animationController: CustomDialogController | null
    = new CustomDialogController({
    builder: CustomDialogExample(),
    closeAnimation: { duration: 2000 },
    openAnimation: { duration: 2000 }
  });

  aboutToDisappear(): void {
    this.animationController = null;
  }

  build() {
    Column() {
      Button("CustomDialogController animate")
        .width('100%')
        .margin({ top: 10 })
        .onClick(() => {
          this.animationController?.open();
        })
    }
  }
}
```
 ![CustomDialogController](figures/dialog_mask_CustomDialogController.gif)


## Complete Sample Code

```ts
// xxx.ets
import { ImmersiveMode, LevelMode, promptAction } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State immersiveMode: ImmersiveMode = ImmersiveMode.DEFAULT;
  autoCancelOpt: promptAction.CustomDialogOptions = {
    builder: () => {
      this.myBuilder();
    },
    autoCancel: false,
  } as promptAction.CustomDialogOptions;
  modalOpt: promptAction.CustomDialogOptions = {
    builder: () => {
      this.myBuilder();
    },
    isModal: false,
  } as promptAction.CustomDialogOptions;
  maskOpt: promptAction.CustomDialogOptions = {
    builder: () => {
      this.myBuilder();
    },
    maskRect: {
      x: 0,
      y: 10,
      width: '100%',
      height: '90%'
    },
    maskColor: "#33AA0000"
  } as promptAction.CustomDialogOptions;
  transitionOpt: promptAction.CustomDialogOptions = {
    builder: () => {
      this.myBuilder();
    },
    transition: TransitionEffect.OPACITY.animation({ duration: 3000 })
  } as promptAction.CustomDialogOptions;

  @Builder
  myBuilder() {
    Column() {
      Text("title").margin(10).fontSize(20)
      Button("button1").margin(10).fontSize(20)
      Button("button2").margin(10).fontSize(20)
    }.width('100%').height('50%')
  }

  build() {
    Column() {
      Button("openCustomDialog autoCancel:false")
        .width('100%')
        .margin({ top: 10 })
        .onClick(() => {
          this.getUIContext().getPromptAction().openCustomDialog(this.autoCancelOpt)
        })
      Button("openCustomDialog isModal:false")
        .width('100%')
        .margin({ top: 10 })
        .onClick(() => {
          this.getUIContext().getPromptAction().openCustomDialog(this.modalOpt)
        })
      Button("openCustomDialog maskOpt")
        .width('100%')
        .margin({ top: 10 })
        .onClick(() => {
          this.getUIContext().getPromptAction().openCustomDialog(this.maskOpt)
        })
      Button("openCustomDialog transition")
        .width('100%')
        .margin({ top: 10 })
        .onClick(() => {
          this.getUIContext().getPromptAction().openCustomDialog(this.transitionOpt);
        })
      Button("openCustomDialog immersiveMode")
        .width('100%')
        .margin({ top: 10 })
        .onClick(() => {
          this.immersiveMode =
            this.immersiveMode == ImmersiveMode.DEFAULT ? ImmersiveMode.EXTEND : ImmersiveMode.DEFAULT;
          this.getUIContext().getPromptAction().openCustomDialog({
            builder: () => {
              this.myBuilder();
            },
            levelMode: LevelMode.EMBEDDED,
            immersiveMode: this.immersiveMode,
          })
        })
      Button("openCustomDialog maskTransition")
        .width('100%')
        .margin({ top: 10 })
        .onClick(() => {
          this.getUIContext().getPromptAction().openCustomDialog({
            builder: () => {
              this.myBuilder();
            },
            maskTransition: TransitionEffect.OPACITY.animation({ duration: 2000 })
              .combine(TransitionEffect.rotate({ z: 1, angle: 180 })),
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```
 ![openCustomDialog](figures/dialog_mask_openCustomDialog.gif)
