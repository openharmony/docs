# @ohos.promptAction (Prompt)

The **PromptAction** module provides APIs for creating and showing toasts, dialog boxes, and action menus.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module cannot be used in the file declaration of the [UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md). In other words, the APIs of this module can be used only after a component instance is created; they cannot be called in the lifecycle of the UIAbility.
>
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](js-apis-arkui-UIContext.md#uicontext). Except for UI-less scenarios<!--Del--> such as [ServiceExtension](../../application-models/serviceextensionability.md)<!--DelEnd-->, it is recommended that you use the dialog APIs provided by **UIContext**.
>
> Since API version 10, you can use the [getPromptAction](js-apis-arkui-UIContext.md#getpromptaction) API in [UIContext](js-apis-arkui-UIContext.md#uicontext) to obtain the [PromptAction](js-apis-arkui-UIContext.md#promptaction) object associated with the current UI context.

## Modules to Import

```ts
import { promptAction } from '@kit.ArkUI';
```

## promptAction.showToast

showToast(options: ShowToastOptions): void

Shows a toast.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                   | Mandatory  | Description     |
| ------- | ------------------------------------- | ---- | ------- |
| options | [ShowToastOptions](#showtoastoptions) | Yes   | Toast options.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [promptAction Error Codes](errorcode-promptAction.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |

**Example**

```ts
import { promptAction } from '@kit.ArkUI'
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct toastExample {
  build() {
    Column() {
      Button('Show toast').fontSize(20)
        .onClick(() => {
          try {
            promptAction.showToast({
              message: 'Hello World',
              duration: 2000
            });
          } catch (error) {
            let message = (error as BusinessError).message
            let code = (error as BusinessError).code
            console.error(`showToast args error code is ${code}, message is ${message}`);
          };
        })
    }.height('100%').width('100%').justifyContent(FlexAlign.Center)
  }
}
```
Below is a toast in API version 11 and earlier versions.

![en-us_image_0001](figures/toast-api11.gif)

Below is a toast in API version 12 and later versions.

![en-us_image_0001](figures/toast-api12.gif)

## promptAction.openToast<sup>18+</sup>

openToast(options: ShowToastOptions): Promise&lt;number&gt;

Opens a toast. This API returns the toast ID.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description          |
| ------- | ------------------------------------------------------------ | ---- | -------------- |
| options | [ShowToastOptions](#showtoastoptions) | Yes  | Toast options.|

**Return value**

| Type            | Description                                |
| ---------------- | ------------------------------------ |
| Promise&lt;number&gt; | ID of the toast, which is required in **closeToast**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [promptAction Error Codes](errorcode-promptAction.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | Internal error.                                              |

**Example**

```ts
import { promptAction } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct toastExample {
  @State toastId: number = 0;

  build() {
    Column() {
      Button('Open Toast')
        .height(100)
        .type(ButtonType.Capsule)
        .onClick(() => {
          promptAction.openToast({
            message: 'Toast Message',
            duration: 10000,
          }).then((toastId: number) => {
            this.toastId = toastId;
          })
            .catch((error: BusinessError) => {
              console.error(`openToast error code is ${error.code}, message is ${error.message}`)
            })
        })
      Blank().height(50);
      Button('Close Toast')
        .height(100)
        .type(ButtonType.Capsule)
        .onClick(() => {
          try {
            promptAction.closeToast(this.toastId);
          } catch (error) {
            let message = (error as BusinessError).message;
            let code = (error as BusinessError).code;
            console.error(`CloseToast error code is ${code}, message is ${message}`);
          };
        })
    }.height('100%').width('100%').justifyContent(FlexAlign.Center)
  }
}
```

![toast-openclose](figures/toast-openclose.gif)

## promptAction.closeToast<sup>18+</sup>

closeToast(toastId: number): void

Closes a toast.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | ----------------------------- |
| toastId | number | Yes  | ID of the toast to close, which is returned by **openToast**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [promptAction Error Codes](errorcode-promptAction.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed. |
| 100001   | Internal error.                                              |

**Example**

See the example for [promptAction.openToaset18](#promptactionopentoast18).

## promptAction.showDialog

showDialog(options: ShowDialogOptions): Promise&lt;ShowDialogSuccessResponse&gt;

Shows a dialog box. This API uses a promise to return the result asynchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                     | Mandatory  | Description    |
| ------- | --------------------------------------- | ---- | ------ |
| options | [ShowDialogOptions](#showdialogoptions) | Yes   | Dialog box options.|

**Return value**

| Type                                      | Description      |
| ---------------------------------------- | -------- |
| Promise&lt;[ShowDialogSuccessResponse](#showdialogsuccessresponse)&gt; | Promise used to return the dialog box response result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [promptAction Error Codes](errorcode-promptAction.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |

**Example**

```ts
import { promptAction } from '@kit.ArkUI'

promptAction.showDialog({
  title: 'Title Info',
  message: 'Message Info',
  buttons: [
    {
      text: 'button1',
      color: '#000000'
    },
    {
      text: 'button2',
      color: '#000000'
    }
  ],
})
  .then(data => {
    console.info('showDialog success, click button: ' + data.index);
  })
  .catch((err: Error) => {
    console.info('showDialog error: ' + err);
  })
```

![en-us_image_0002](figures/en-us_image_0002.gif)

## promptAction.showDialog

showDialog(options: ShowDialogOptions, callback: AsyncCallback&lt;ShowDialogSuccessResponse&gt;):void

Shows a dialog box. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description          |
| -------- | ---------------------------------------- | ---- | ------------ |
| options  | [ShowDialogOptions](#showdialogoptions)  | Yes   | Dialog box options.|
| callback | AsyncCallback&lt;[ShowDialogSuccessResponse](#showdialogsuccessresponse)&gt; | Yes   | Callback used to return the dialog box response result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [promptAction Error Codes](errorcode-promptAction.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |

**Example**

```ts
import { promptAction } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  promptAction.showDialog({
    title: 'showDialog Title Info',
    message: 'Message Info',
    buttons: [
      {
        text: 'button1',
        color: '#000000'
      },
      {
        text: 'button2',
        color: '#000000'
      }
    ]
  }, (err, data) => {
    if (err) {
      console.info('showDialog err: ' + err);
      return;
    }
    console.info('showDialog success callback, click button: ' + data.index);
  });
} catch (error) {
  let message = (error as BusinessError).message
  let code = (error as BusinessError).code
  console.error(`showDialog args error code is ${code}, message is ${message}`);
};
```

![en-us_image_0004](figures/en-us_image_0004.gif)

When the **showInSubWindow** attribute is set to **true**, the toast can be displayed outside the window.

```ts
import { promptAction } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  promptAction.showDialog({
    title: 'showDialog Title Info',
    message: 'Message Info',
    isModal: true,
    showInSubWindow: true,
    buttons: [
      {
        text: 'button1',
        color: '#000000'
      },
      {
        text: 'button2',
        color: '#000000'
      }
    ]
  }, (err, data) => {
    if (err) {
      console.info('showDialog err: ' + err);
      return;
    }
    console.info('showDialog success callback, click button: ' + data.index);
  });
} catch (error) {
  let message = (error as BusinessError).message
  let code = (error as BusinessError).code
  console.error(`showDialog args error code is ${code}, message is ${message}`);
};
```

![en-us_image_0002_showinsubwindow](figures/en-us_image_0002_showinsubwindow.jpg)



## promptAction.showActionMenu

showActionMenu(options: ActionMenuOptions, callback: AsyncCallback&lt;ActionMenuSuccessResponse&gt;):void

Shows an action menu. This API uses a callback to return the result asynchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| options  | [ActionMenuOptions](#actionmenuoptions)  | Yes   | Action menu options.  |
| callback | AsyncCallback&lt;[ActionMenuSuccessResponse](#actionmenusuccessresponse)> | Yes   | Callback used to return the action menu response result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [promptAction Error Codes](errorcode-promptAction.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |

**Example**

```ts
import { promptAction } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  promptAction.showActionMenu({
    title: 'Title Info',
    buttons: [
      {
        text: 'item1',
        color: '#666666'
      },
      {
        text: 'item2',
        color: '#000000'
      },
    ]
  }, (err, data) => {
    if (err) {
      console.info('showActionMenu err: ' + err);
      return;
    }
    console.info('showActionMenu success callback, click button: ' + data.index);
  })
} catch (error) {
  let message = (error as BusinessError).message
  let code = (error as BusinessError).code
  console.error(`showActionMenu args error code is ${code}, message is ${message}`);
};
```

![en-us_image_0005](figures/en-us_image_0005.gif)

## promptAction.showActionMenu

showActionMenu(options: ActionMenuOptions): Promise&lt;ActionMenuSuccessResponse&gt;

Shows an action menu. This API uses a promise to return the result asynchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                                     | Mandatory  | Description     |
| ------- | --------------------------------------- | ---- | ------- |
| options | [ActionMenuOptions](#actionmenuoptions) | Yes   | Action menu options.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise&lt;[ActionMenuSuccessResponse](#actionmenusuccessresponse)&gt; | Promise used to return the action menu response result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [promptAction Error Codes](errorcode-promptAction.md).

| ID  | Error Message|
| --------- | ------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001    | Internal error. |

**Example**

```ts
import { promptAction } from '@kit.ArkUI';

promptAction.showActionMenu({
  title: 'showActionMenu Title Info',
  buttons: [
    {
      text: 'item1',
      color: '#666666'
    },
    {
      text: 'item2',
      color: '#000000'
    },
  ]
})
  .then(data => {
    console.info('showActionMenu success, click button: ' + data.index);
  })
  .catch((err: Error) => {
    console.info('showActionMenu error: ' + err);
  })
```

![en-us_image_0006](figures/en-us_image_0006.gif)

## promptAction.openCustomDialog<sup>11+</sup>

openCustomDialog(options: CustomDialogOptions): Promise&lt;number&gt;

Opens a custom dialog box.

<!--Del-->This API cannot be used in **ServiceExtension**.<!--DelEnd-->

**isModal = true** and **showInSubWindow = true** cannot be used at the same time.

By default, the width of the dialog box in portrait mode is the width of the window where it is located minus the left and right margins (40 vp for 2-in-1 devices and 16 vp for other devices), and the maximum width is 400 vp.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                         | Mandatory| Description              |
| ------- | --------------------------------------------- | ---- | ------------------ |
| options | [CustomDialogOptions](#customdialogoptions11) | Yes  | Content of the custom dialog box.|

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------- |
| Promise&lt;number&gt; | ID of the custom dialog box, which can be used in **closeCustomDialog**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [promptAction Error Codes](errorcode-promptAction.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001   | Internal error. |

**Example**

```ts
import { promptAction } from '@kit.ArkUI'
import { BusinessError } from '@kit.BasicServicesKit'

@Entry
@Component
struct Index {
  private customDialogComponentId: number = 0

  @Builder
  customDialogComponent() {
    Column() {
      Text('Dialog box').fontSize(30)
      Row({ space: 50 }) {
        Button("OK").onClick(() => {
          try {
            promptAction.closeCustomDialog(this.customDialogComponentId)
          } catch (error) {
            let message = (error as BusinessError).message;
            let code = (error as BusinessError).code;
            console.error(`closeCustomDialog error code is ${code}, message is ${message}`);
          }
        })
        Button("Cancel").onClick(() => {
          try {
            promptAction.closeCustomDialog(this.customDialogComponentId)
          } catch (error) {
            let message = (error as BusinessError).message;
            let code = (error as BusinessError).code;
            console.error(`closeCustomDialog error code is ${code}, message is ${message}`);
          }
        })
      }
    }.height(200).padding(5).justifyContent(FlexAlign.SpaceBetween)
  }

  build() {
    Row() {
      Column({ space: 20 }) {
        Text('In-component dialog box')
          .fontSize(30)
          .onClick(() => {
            promptAction.openCustomDialog({
              builder: () => {
                this.customDialogComponent()
              },
              onWillDismiss: (dismissDialogAction: DismissDialogAction) => {
                console.info("reason" + JSON.stringify(dismissDialogAction.reason))
                console.log("dialog onWillDismiss")
                if (dismissDialogAction.reason == DismissReason.PRESS_BACK) {
                  dismissDialogAction.dismiss()
                }
                if (dismissDialogAction.reason == DismissReason.TOUCH_OUTSIDE) {
                  dismissDialogAction.dismiss()
                }
              }
            }).then((dialogId: number) => {
              this.customDialogComponentId = dialogId
            })
              .catch((error: BusinessError) => {
                console.error(`openCustomDialog error code is ${error.code}, message is ${error.message}`)
              })
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}

```
This example demonstrates how to set styles of a dialog box, including the width, height, background color, and shadow.
```ts
import { promptAction, LevelMode, ImmersiveMode } from '@kit.ArkUI'

let customDialogId: number = 0

@Builder
function customDialogBuilder() {
  Column() {
    Text('Custom dialog Message').fontSize(10)
    Row() {
      Button("OK").onClick(() => {
        promptAction.closeCustomDialog(customDialogId)
      })
      Blank().width(50)
      Button("Cancel").onClick(() => {
        promptAction.closeCustomDialog(customDialogId)
      })
    }
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  @Builder
  customDialogComponent() {
    customDialogBuilder()
  }

  build() {
    Row() {
      Column() {
        Text(this.message).id("test_text")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            const node: FrameNode | null = this.getUIContext().getFrameNodeById("test_text") || null;
            promptAction.openCustomDialog({
              builder: () => {
                this.customDialogComponent()
              },
              keyboardAvoidMode: KeyboardAvoidMode.NONE,
              showInSubWindow: false,
              offset: { dx: 5, dy: 5 },
              backgroundColor: 0xd9ffffff,
              cornerRadius: 20,
              width: '80%',
              height: 200,
              borderWidth: 1,
              borderStyle: BorderStyle.Dashed, // borderStyle must be used with borderWidth in pairs.
              borderColor: Color.Blue, // borderColor must be used with borderWidth in pairs.
              shadow: ({
                radius: 20,
                color: Color.Grey,
                offsetX: 50,
                offsetY: 0
              }),
              levelMode: LevelMode.EMBEDDED,
              levelUniqueId: node?.getUniqueId(),
              immersiveMode: ImmersiveMode.DEFAULT,
            }).then((dialogId: number) => {
              customDialogId = dialogId
            })
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![en-us_image_0007](figures/en-us_image_0007.gif)

This example shows how to implement a dialog box on a page.
```ts
// Index.ets
import { promptAction, LevelMode, ImmersiveMode, router } from '@kit.ArkUI'

let customDialogId: number = 0

@Builder
function customDialogBuilder() {
  Column() {
    Text('Custom dialog Message').fontSize(10).height(100)
    Row() {
      Button("Next").onClick(() => {
        router.pushUrl({url: 'pages/Next'})
      })
      Blank().width(50)
      Button("Close").onClick(() => {
        promptAction.closeCustomDialog(customDialogId)
      })
    }
  }.padding(20)
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  @Builder
  customDialogComponent() {
    customDialogBuilder()
  }

  build() {
    Row() {
      Column() {
        Text(this.message).id("test_text")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            const node: FrameNode | null = this.getUIContext().getFrameNodeById("test_text") || null;
            promptAction.openCustomDialog({
              builder: () => {
                this.customDialogComponent()
              },
              levelMode: LevelMode.EMBEDDED,
              levelUniqueId: node?.getUniqueId(),
              immersiveMode: ImmersiveMode.DEFAULT,
            }).then((dialogId: number) => {
              customDialogId = dialogId
            })
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
```ts
// Next.ets
import { router } from '@kit.ArkUI'

@Entry
@Component
struct Next {
  @State message: string = 'Back'

  build() {
    Row() {
      Column() {
        Button(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            router.back()
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
![embedded_dialog](figures/embedded_dialog.gif)

## promptAction.closeCustomDialog<sup>11+</sup>

closeCustomDialog(dialogId: number): void

Closes the specified custom dialog box.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type  | Mandatory| Description                            |
| -------- | ------ | ---- | -------------------------------- |
| dialogId | number | Yes  | ID of the custom dialog box to close. It is returned from **openCustomDialog**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [promptAction Error Codes](errorcode-promptAction.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100001   | Internal error. |

**Example**

See the example of [promptAction.openCustomDialog](#promptactionopencustomdialog11).

## ShowToastOptions

Describes the options for showing the toast.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                   | Type                                                        | Mandatory| Description                                                        |
| ----------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| message                 | string \| [Resource](arkui-ts/ts-types.md#resource) | Yes  | Text to display.<br>**NOTE**<br>The default font is **'Harmony Sans'**. Other fonts are not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| duration                | number                                                       | No  | Duration that the toast will remain on the screen. The default value is 1500 ms. The value range is 1500 ms to 10000 ms. If a value less than 1500 ms is set, the default value is used. If the value greater than 10000 ms is set, the upper limit 10000 ms is used.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| bottom                  | string \| number                                   | No  | Distance from the bottom of the toast to the navigation bar. In **ToastShowMode.TOP_MOST** mode, if the soft keyboard is raised and the **bottom** value is too small, the toast will automatically avoid being blocked by the soft keyboard by moving up 80 vp above it. In **ToastShowMode.DEFAULT** mode, the toast will move up by the height of the soft keyboard.<br>Default value: **80vp**<br>**NOTE**<br>When there is no navigation bar at the bottom, **bottom** sets the distance from the bottom of the toast to the bottom of the window.<br>If the **alignment** property is set, **bottom** will not take effect.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| showMode<sup>11+</sup>  | [ToastShowMode](#toastshowmode11)                            | No  | Whether to show the toast above the application.<br>Default value: **ToastShowMode.DEFAULT**, which means to show the toast in the application.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| alignment<sup>12+</sup> | [Alignment](arkui-ts/ts-appendix-enums.md#alignment)         | No  | Alignment mode.<br>Default value: **undefined**, indicating bottom start<br>**Atomic service API**: This API can be used in atomic services since API version 12.        |
| offset<sup>12+</sup>    | [Offset](arkui-ts/ts-types.md#offset)                        | No  | Offset in the specified alignment mode.<br>Default value: **{ dx: 0, dy: 0 }**, indicating no offset<br>**NOTE**<br>Only values in the px unit are accepted. To use the vp unit, convert them to px first.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| backgroundColor<sup>12+</sup>    | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | Background color of the toast.<br>Default value: **Color.Transparent**<br>**NOTE**<br>When **backgroundColor** is set to a non-transparent color, **backgroundBlurStyle** must be set to **BlurStyle.NONE**; otherwise, the color display may not meet the expected effect.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| textColor<sup>12+</sup>    | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No  | Font color of the toast.<br>Default value: **Color.Black**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| backgroundBlurStyle<sup>12+</sup>    | [BlurStyle](arkui-ts/ts-universal-attributes-background.md#blurstyle9) | No  | Background blur style of the toast.<br>Default value: **BlurStyle.COMPONENT_ULTRA_THICK**<br>**NOTE**<br>Setting this parameter to **BlurStyle.NONE** disables the background blur. When **backgroundBlurStyle** is set to a value other than **NONE**, do not set **backgroundColor**. If you do, the color display may not produce the expected visual effect.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| shadow<sup>12+</sup>    | [ShadowOptions](arkui-ts/ts-universal-attributes-image-effect.md#shadowoptions) \| [ShadowStyle](arkui-ts/ts-universal-attributes-image-effect.md#shadowstyle10) | No  | Background shadow of the toast.<br>Default value: **ShadowStyle.OUTER_DEFAULT_MD**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| enableHoverMode<sup>14+</sup>    | boolean                       | No  | Whether to enable the hover state.<br>Default value: **false**, meaning not to enable the hover state.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| hoverModeArea<sup>14+</sup> | [HoverModeAreaType](arkui-ts/ts-appendix-enums.md#hovermodeareatype14)         | No  | Display area of the toast in the hover state.<br>Default value: **HoverModeAreaType.BOTTOM_SCREEN**, indicating that the toast is displayed in the lower half screen<br>**Atomic service API**: This API can be used in atomic services since API version 14.        |

## ToastShowMode<sup>11+</sup>

Describes the mode in which the toast is shown.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Value  | Description                  |
| -------- | ---- | ---------------------- |
| DEFAULT  | 0    | The toast is shown within the application.  |
| TOP_MOST | 1    | The toast is shown above the application.|

## ShowDialogOptions

Describes the options for showing the dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                             | Type                                                        | Mandatory| Description                                                        |
| --------------------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| title                             | string \| [Resource](arkui-ts/ts-types.md#resource) | No  | Title of the dialog box.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| message                           | string \| [Resource](arkui-ts/ts-types.md#resource) | No  | Text body.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| buttons                           | Array&lt;[Button](#button)&gt;                               | No  | Array of buttons in the dialog box. The array structure is {text:'button', color: '\#666666'}. More than one button is supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| alignment<sup>10+</sup>           | [DialogAlignment](arkui-ts/ts-methods-alert-dialog-box.md#dialogalignment) | No  | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default**<br>**NOTE**<br>If **showInSubWindow** is set to **true** in **UIExtension**, the dialog box is aligned with the host window based on **UIExtension**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| offset<sup>10+</sup>              | [Offset](arkui-ts/ts-types.md#offset)                        | No  | Offset of the dialog box based on the **alignment** settings.<br>Default value: **{ dx: 0 , dy: 0 }**<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| maskRect<sup>10+</sup>            | [Rectangle](arkui-ts/ts-methods-alert-dialog-box.md#rectangle8) | No  | Mask area of the dialog box. Events outside the mask area are transparently transmitted, and events within the mask area are not.<br>Default value: **{ x: 0, y: 0, width: '100%', height: '100%' }**<br>**NOTE**<br>**maskRect** does not take effect when **showInSubWindow** is set to **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| showInSubWindow<sup>11+</sup>     | boolean                                                      | No  | Whether to show the dialog box in a subwindow when it is not in the main window.<br>Default value: **false**, meaning the dialog box is displayed within the application, not in a separate subwindow<br>**NOTE**<br>A dialog box whose **showInSubWindow** attribute is **true** cannot trigger the display of another dialog box whose **showInSubWindow** attribute is also **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| isModal<sup>11+</sup>             | boolean                                                      | No  | Whether the dialog box is a modal. A modal dialog box has a mask applied, while a non-modal dialog box does not.<br>Default value: **true**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| backgroundColor<sup>12+</sup>     | [ResourceColor](arkui-ts/ts-types.md#resourcecolor)          | No  | Background color of the dialog box.<br>Default value: **Color.Transparent**<br>**NOTE**<br>When **backgroundColor** is set to a non-transparent color, **backgroundBlurStyle** must be set to **BlurStyle.NONE**; otherwise, the color display may not meet the expected effect.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| backgroundBlurStyle<sup>12+</sup> | [BlurStyle](arkui-ts/ts-universal-attributes-background.md#blurstyle9) | No  | Background blur style of the dialog box.<br>Default value: **BlurStyle.COMPONENT_ULTRA_THICK**<br>**NOTE**<br>Setting this parameter to **BlurStyle.NONE** disables the background blur. When **backgroundBlurStyle** is set to a value other than **NONE**, do not set **backgroundColor**. If you do, the color display may not produce the expected visual effect.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| backgroundBlurStyleOptions<sup>18+</sup> | [BackgroundBlurStyleOptions](arkui-ts/ts-universal-attributes-background.md#backgroundblurstyleoptions10) | No| Options for customizing the background blur style.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| backgroundEffect<sup>18+</sup> | [BackgroundEffectOptions](arkui-ts/ts-universal-attributes-background.md#backgroundeffectoptions11) | No| Options for customizing the background effect.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| shadow<sup>12+</sup>              | [ShadowOptions](arkui-ts/ts-universal-attributes-image-effect.md#shadowoptions) \| [ShadowStyle](arkui-ts/ts-universal-attributes-image-effect.md#shadowstyle10) | No  | Shadow of the dialog box.<br> Default value on 2-in-1 devices: **ShadowStyle.OUTER_FLOATING_MD** when the dialog box is focused and **ShadowStyle.OUTER_FLOATING_SM** otherwise<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| enableHoverMode<sup>14+</sup>     | boolean                                                      | No  | Whether to enable the hover state.<br>Default value: **false**, meaning not to enable the hover state.<br>**Atomic service API**: This API can be used in atomic services since API version 14.           |
| hoverModeArea<sup>14+</sup>       | [HoverModeAreaType](arkui-ts/ts-appendix-enums.md#hovermodeareatype14) | No  | Display area of the dialog box in the hover state.<br>Default value: **HoverModeAreaType.BOTTOM_SCREEN**<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| levelMode<sup>15+</sup>       | [LevelMode](#levelmode15) | No  | Display level of the dialog box.<br>**NOTE**<br>- Default value: **LevelMode.OVERLAY**<br>- This parameter takes effect only when **showInSubWindow** is set to **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| levelUniqueId<sup>15+</sup>       | number | No  | [Unique ID](js-apis-arkui-frameNode.md#getuniqueid12) of the node under the display level for the page-level dialog box.<br>**NOTE**<br>- This parameter takes effect only when **levelMode** is set to **LevelMode.EMBEDDED**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| immersiveMode<sup>15+</sup>       | [ImmersiveMode](#immersivemode15) | No  | Overlay effect for the page-level dialog box.<br>**NOTE**<br>- Default value: **ImmersiveMode.DEFAULT**<br>- This parameter takes effect only when **levelMode** is set to **LevelMode.EMBEDDED**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| levelOrder<sup>18+</sup>       | [LevelOrder](#levelorder18) | No  | Display order of the dialog box.<br>**NOTE**<br>- Default value: **LevelOrder.clamp(0)**<br>- Dynamic updating is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## ShowDialogSuccessResponse

Describes the dialog box response result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type  | Mandatory| Description                           |
| ----- | ------ | ---- | ------------------------------- |
| index | number | Yes  | Index of the selected button in the **buttons** array.|

## ActionMenuOptions

Describes the options for showing the action menu.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name                         | Type                                                        | Mandatory| Description                                                        |
| ----------------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| title                         | string \| [Resource](arkui-ts/ts-types.md#resource) | No  | Title of the dialog box.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| buttons                       | [[Button](#button),[Button](#button)?,[Button](#button)?,[Button](#button)?,[Button](#button)?,[Button](#button)?] | Yes  | Array of menu item buttons. The array structure is **{text:'button', color: '\#666666'}**. Up to six buttons are supported. If there are more than six buttons, only the first six buttons will be displayed.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| showInSubWindow<sup>11+</sup> | boolean                                                      | No  | Whether to show the dialog box in a subwindow when it is not in the main window.<br>Default value: **false**, indicating that the dialog box is not displayed in the subwindow<br>**NOTE**<br> - A dialog box whose **showInSubWindow** attribute is **true** cannot trigger the display of another dialog box whose **showInSubWindow** attribute is also **true**.<br> - If **showInSubWindow** is set to **true** in **UIExtension**, the dialog box is aligned with the host window based on **UIExtension**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| isModal<sup>11+</sup>         | boolean                                                      | No  | Whether the dialog box is a modal. A modal dialog box has a mask applied, while a non-modal dialog box does not.<br>Default value: **true**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| levelMode<sup>15+</sup>       | [LevelMode](#levelmode15) | No  | Display level of the dialog box.<br>**NOTE**<br>- Default value: **LevelMode.OVERLAY**<br>- This parameter takes effect only when **showInSubWindow** is set to **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| levelUniqueId<sup>15+</sup>       | number | No  | [Unique ID](js-apis-arkui-frameNode.md#getuniqueid12) of the node under the display level for the page-level dialog box.<br>**NOTE**<br>- This parameter takes effect only when **levelMode** is set to **LevelMode.EMBEDDED**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| immersiveMode<sup>15+</sup>       | [ImmersiveMode](#immersivemode15) | No  | Overlay effect for the page-level dialog box.<br>**NOTE**<br>- Default value: **ImmersiveMode.DEFAULT**<br>- This parameter takes effect only when **levelMode** is set to **LevelMode.EMBEDDED**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|

## ActionMenuSuccessResponse

Describes the action menu response result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type  | Mandatory| Description                                    |
| ----- | ------ | ---- | ---------------------------------------- |
| index | number | Yes  | Index of the selected button in the **buttons** array, starting from **0**.|

## DialogController<sup>18+</sup>

Implements a custom dialog box controller that inherits from [CommonController](#commoncontroller18).

It can be used as a member variable of **UIContext** to display custom dialog boxes. For specific usage, see the examples for [openCustomDialogWithController](js-apis-arkui-UIContext.md#opencustomdialogwithcontroller18) and [presentCustomDialog](js-apis-arkui-UIContext.md#presentcustomdialog18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## CommonController<sup>18+</sup>

Implements a common controller for managing components related to **promptAction**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### constructor
constructor()

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### close
close(): void

Closes the custom dialog box. If the dialog box is already closed, this API has no effect.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## LevelOrder<sup>18+</sup>

Defines the display order of a dialog box.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### clamp<sup>18+</sup>
static clamp(order: number): LevelOrder

Creates a dialog box level with the specified order.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| order | number | Yes  | Display order of the dialog box. The value range is [-100000.0, +100000.0]. Values outside this range are clamped to the nearest limit.|

**Return value**

| Type | Description   |
| ------ | ------ |
| [LevelOrder](#levelorder18) | Current instance.|

### getOrder<sup>18+</sup>
getOrder(): number

Obtains the display order of this dialog box.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type | Description   |
| ------ | ------ |
| number | Display order of the dialog box.|

## DialogOptions<sup>18+</sup>

Defines the options of the custom dialog box. This API extends [BaseDialogOptions](#basedialogoptions11).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| backgroundColor | [ResourceColor](arkui-ts/ts-types.md#resourcecolor)  | No| Background color of the dialog box.<br>Default value: **Color.Transparent**<br>**NOTE**<br>When **backgroundColor** is set to a non-transparent color, **backgroundBlurStyle** must be set to **BlurStyle.NONE**; otherwise, the color display may not meet the expected effect.|
| cornerRadius | [DialogOptionsCornerRadius](#dialogoptionscornerradius18) | No| Background corner radius of the dialog box.<br>You can set separate radiuses for the four rounded corners.<br>Default value: **{ topLeft: '32vp', topRight: '32vp', bottomLeft: '32vp', bottomRight: '32vp' }**<br> The radius of the rounded corners is subject to the component size. Its maximum value is half of the component width or height. If the value is negative, the default value is used.<br> When set to a percentage, the value defines the radius as a percentage of the parent component's width or height.|
| borderWidth | [DialogOptionsBorderWidth](#dialogoptionsborderwidth18) | No| Border width of the dialog box.<br>You can set the width for all four sides or set separate widths for individual sides.<br>Default value: **0**<br> When set to a percentage, the value defines the border width as a percentage of the parent dialog box's width.<br>If the left and right borders are greater than its width, or the top and bottom borders are greater than its height, the dialog box may not display as expected.|
| borderColor | [DialogOptionsBorderColor](#dialogoptionsbordercolor18) | No| Border color of the dialog box.<br>Default value: **Color.Black**<br> **borderColor** must be used with **borderWidth** in pairs.|
| borderStyle | [DialogOptionsBorderStyle](#dialogoptionsborderstyle18) | No| Border style of the dialog box.<br>Default value: **BorderStyle.Solid**<br> **borderStyle** must be used with **borderWidth** in pairs.|
| width | [Dimension](arkui-ts/ts-types.md#dimension10) | No  | Width of the dialog box.<br>**NOTE**<br>- Default maximum width of the dialog box: 400 vp<br>- When this parameter is set to a percentage, the reference width of the dialog box is the width of the window where the dialog box is located. You can decrease or increase the width as needed.|
| height | [Dimension](arkui-ts/ts-types.md#dimension10)  | No  | Height of the dialog box.<br>**NOTE**<br>- Default maximum height of the dialog box: 0.9 x (Window height – Safe area)<br>- When this parameter is set to a percentage, the reference height of the dialog box is the height of the window where the dialog box is located minus the safe area. You can decrease or increase the height as needed.|
| shadow | [DialogOptionsShadow](#dialogoptionsshadow18) | No| Shadow of the dialog box.<br>Default value on 2-in-1 devices: **ShadowStyle.OUTER_FLOATING_MD** when the dialog box is focused and **ShadowStyle.OUTER_FLOATING_SM** otherwise|
| backgroundBlurStyle | [BlurStyle](arkui-ts/ts-universal-attributes-background.md#blurstyle9)                 | No  | Background blur style of the dialog box.<br>Default value: **BlurStyle.COMPONENT_ULTRA_THICK**<br>**NOTE**<br>Setting this parameter to **BlurStyle.NONE** disables the background blur. When **backgroundBlurStyle** is set to a value other than **NONE**, do not set **backgroundColor**. If you do, the color display may not produce the expected visual effect.|

## DialogOptionsCornerRadius<sup>18+</sup>

type DialogOptionsCornerRadius = Dimension \| BorderRadiuses

Defines the allowed data types for specifying the background corner radius of a dialog box.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [Dimension](arkui-ts/ts-types.md#dimension10) | Length type used to represent a size unit.|
| [BorderRadiuses](arkui-ts/ts-types.md#borderradiuses9) | Type used to describe the corner radius of a component's border.|

## DialogOptionsBorderWidth<sup>18+</sup>

type DialogOptionsBorderWidth = Dimension \| EdgeWidths

Defines the allowed data types for specifying the background border width of a dialog box.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [Dimension](arkui-ts/ts-types.md#dimension10) | Length type used to represent a size unit.|
| [EdgeWidths](arkui-ts/ts-types.md#edgewidths9) | Type used to describe the edge width of a component in different directions.|

## DialogOptionsBorderColor<sup>18+</sup>

type DialogOptionsBorderColor = ResourceColor \| EdgeColors

Defines the allowed data types for specifying the background border color of a dialog box.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | Color type used to describe resource colors.|
| [EdgeColors](arkui-ts/ts-types.md#edgecolors9) | Type used to describe the border color for each edge of a component.|

## DialogOptionsBorderStyle<sup>18+</sup>

type DialogOptionsBorderStyle = BorderStyle \| EdgeStyles

Defines the allowed data types for specifying the background border style of a dialog box.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [BorderStyle](arkui-ts/ts-appendix-enums.md#borderstyle) | Type used to describe the border style of a component.|
| [EdgeStyles](arkui-ts/ts-types.md#edgestyles9) | Type used to describe the border style for each edge of a component.|

## DialogOptionsShadow<sup>18+</sup>

type DialogOptionsShadow = ShadowOptions \| ShadowStyle

Defines the allowed data types for specifying the background shadow of a dialog box.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type                                                        | Description                        |
| ------------------------------------------------------------ | ---------------------------- |
| [ShadowOptions](arkui-ts/ts-universal-attributes-image-effect.md#shadowoptions) | Type used to describe shadow attributes, including the blur radius, color, and offset along the x-axis and y-axis.|
| [ShadowStyle](arkui-ts/ts-universal-attributes-image-effect.md#shadowstyle10) | Type used to describe the shadow style.|

## CustomDialogOptions<sup>11+</sup>

Defines the options of a custom dialog box, which inherit from [BaseDialogOptions](#basedialogoptions11).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                                   | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| builder | [CustomBuilder](arkui-ts/ts-types.md#custombuilder8) | Yes | Content of the custom dialog box.<br>**NOTE**<br>The builder needs to be assigned an arrow function in the following format: () => { this.XXX() }, where XXX indicates the internal builder name.<br>If you are working with a global builder, you need to call it within a local builder within a component.<br>The aspect ratio of the root node of a builder is relative to the size of the dialog box container.<br>The aspect ratio of a non-root node is relative to the size of its parent node.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| backgroundColor <sup>12+</sup>| [ResourceColor](arkui-ts/ts-types.md#resourcecolor)  | No| Background color of the dialog box.<br>Default value: **Color.Transparent**<br>**NOTE**<br>When **backgroundColor** is set to a non-transparent color, **backgroundBlurStyle** must be set to **BlurStyle.NONE**; otherwise, the color display may not meet the expected effect.|
| cornerRadius<sup>12+</sup>| [Dimension](arkui-ts/ts-types.md#dimension10) \| [BorderRadiuses](arkui-ts/ts-types.md#borderradiuses9) | No| Radius of the rounded corners of the background.<br>You can set separate radiuses for the four rounded corners.<br>Default value: **{ topLeft: '32vp', topRight: '32vp', bottomLeft: '32vp', bottomRight: '32vp' }**<br> The radius of the rounded corners is subject to the component size. Its maximum value is half of the component width or height. If the value is negative, the default value is used.<br> When set to a percentage, the value defines the radius as a percentage of the parent component's width or height.|
| borderWidth<sup>12+</sup>| [Dimension](arkui-ts/ts-types.md#dimension10) \| [EdgeWidths](arkui-ts/ts-types.md#edgewidths9)  | No| Border width of the dialog box.<br>You can set the width for all four sides or set separate widths for individual sides.<br>Default value: **0**<br> When set to a percentage, the value defines the border width as a percentage of the parent dialog box's width.<br>If the left and right borders are greater than its width, or the top and bottom borders are greater than its height, the dialog box may not display as expected.|
| borderColor<sup>12+</sup> | [ResourceColor](arkui-ts/ts-types.md#resourcecolor) \| [EdgeColors](arkui-ts/ts-types.md#edgecolors9)  | No| Border color of the dialog box.<br>Default value: **Color.Black**<br> **borderColor** must be used with **borderWidth** in pairs.|
| borderStyle<sup>12+</sup> | [BorderStyle](arkui-ts/ts-appendix-enums.md#borderstyle) \| [EdgeStyles](arkui-ts/ts-types.md#edgestyles9)  | No| Border style of the dialog box.<br>Default value: **BorderStyle.Solid**<br> **borderStyle** must be used with **borderWidth** in pairs.|
| width<sup>12+</sup> | [Dimension](arkui-ts/ts-types.md#dimension10) | No  | Width of the dialog box.<br>**NOTE**<br>- Default maximum width of the dialog box: 400 vp<br>- When this parameter is set to a percentage, the reference width of the dialog box is the width of the window where the dialog box is located. You can decrease or increase the width as needed.|
| height<sup>12+</sup> | [Dimension](arkui-ts/ts-types.md#dimension10)  | No  | Height of the dialog box.<br>**NOTE**<br>- Default maximum height of the dialog box: 0.9 x (Window height – Safe area)<br>- When this parameter is set to a percentage, the reference height of the dialog box is the height of the window where the dialog box is located minus the safe area. You can decrease or increase the height as needed.|
| shadow<sup>12+</sup>| [ShadowOptions](arkui-ts/ts-universal-attributes-image-effect.md#shadowoptions) \| [ShadowStyle](arkui-ts/ts-universal-attributes-image-effect.md#shadowstyle10)   | No| Shadow of the dialog box.<br>Default value on 2-in-1 devices: **ShadowStyle.OUTER_FLOATING_MD** when the dialog box is focused and **ShadowStyle.OUTER_FLOATING_SM** otherwise|
| backgroundBlurStyle<sup>12+</sup> | [BlurStyle](arkui-ts/ts-universal-attributes-background.md#blurstyle9)                 | No  | Background blur style of the dialog box.<br>Default value: **BlurStyle.COMPONENT_ULTRA_THICK**<br>**NOTE**<br>Setting this parameter to **BlurStyle.NONE** disables the background blur. When **backgroundBlurStyle** is set to a value other than **NONE**, do not set **backgroundColor**. If you do, the color display may not produce the expected visual effect.|

## BaseDialogOptions<sup>11+</sup>

Defines the options of the dialog box.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name           | Type                                                        | Mandatory| Description                                                        |
| --------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| maskRect        | [Rectangle](arkui-ts/ts-methods-alert-dialog-box.md#rectangle8) | No  | Mask area.<br>Default value: **{ x: 0, y: 0, width: '100%', height: '100%' }**<br>**NOTE**<br>**maskRect** does not take effect when **showInSubWindow** is set to **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| alignment       | [DialogAlignment](arkui-ts/ts-methods-alert-dialog-box.md#dialogalignment) | No  | Alignment mode of the dialog box in the vertical direction.<br>Default value: **DialogAlignment.Default**<br>**NOTE**<br>If **showInSubWindow** is set to **true** in **UIExtension**, the dialog box is aligned with the host window based on **UIExtension**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| offset          | [Offset](arkui-ts/ts-types.md#offset)                     | No  | Offset of the dialog box based on the **alignment** settings.<br>Default value: **{ dx: 0 , dy: 0 }**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| isModal         | boolean                                                      | No  | Whether the dialog box is a modal. A modal dialog box has a mask applied, while a non-modal dialog box does not.<br>Default value: **true**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| showInSubWindow | boolean                                                      | No  | Whether to show the dialog box in a subwindow when it is not in the main window.<br>Default value: **false**, meaning the dialog box is displayed within the application, not in a separate subwindow<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| onWillDismiss<sup>12+</sup> | Callback<[DismissDialogAction](#dismissdialogaction12)> | No| Callback for interactive dismissal of the dialog box.<br>**NOTE**<br>1. If this callback is registered, the dialog box will not be dismissed immediately after the user touches the mask or the Back button, presses the Esc key, or swipes left or right on the screen. The **reason** parameter in the callback is used to determine whether the dialog box can be dismissed. The reason returned by the component does not support the value **CLOSE_BUTTON**.<br>2. In the **onWillDismiss** callback, another **onWillDismiss** callback is not allowed.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
|  autoCancel<sup>12+</sup> |       boolean                                   | No  | Whether to dismiss the dialog box when the mask is touched. The value **true** means to dismiss the dialog box when the mask is touched, and **false** means the opposite.<br>Default value: **true**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
|  maskColor<sup>12+</sup> |        [ResourceColor](arkui-ts/ts-types.md#resourcecolor) | No   | Mask color.<br>Default value: **0x33000000**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| transition<sup>12+</sup>          | [TransitionEffect](arkui-ts/ts-transition-animation-component.md#transitioneffect10) | No  | Transition effect for the entrance and exit of the dialog box.<br>**NOTE**<br> 1. If this parameter is not set, the default effect is used.<br> 2. Touching the Back button during the entrance animation pauses the entrance animation and starts the exit animation. The final effect is one obtained after the curves of the entrance and exit animations are combined.<br> 3. Touching the Back button during the exit animation does not affect the animation playback. Touching the Back button again closes the application.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| dialogTransition<sup>18+</sup>          | [TransitionEffect](arkui-ts/ts-transition-animation-component.md#transitioneffect10) | No  | Transition effect for the dialog box content. By default, there is no transition effect.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| maskTransition<sup>18+</sup>          | [TransitionEffect](arkui-ts/ts-transition-animation-component.md#transitioneffect10) | No  | Transition effect for the mask.<br>If not set, the transition effect matches the mask's display animation.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| onDidAppear<sup>12+</sup> | () => void | No| Event callback when the dialog box appears.<br>**NOTE**<br>1. The normal timing sequence is as follows: onWillAppear > onDidAppear > (onDateAccept/onCancel/onDateChange) > onWillDisappear > onDidDisappear.<br>2. You can set the callback event for changing the dialog box display effect in **onDidAppear**. The settings take effect next time the dialog box appears.<br>3. If the user dismisses the dialog box immediately after it appears, **onWillDisappear** is invoked before **onDidAppear**.<br>4. If the dialog box is dismissed before its entrance animation is finished, this callback is not invoked.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| onDidDisappear<sup>12+</sup> | () => void | No| Event callback when the dialog box disappears.<br>**NOTE**<br>The normal timing sequence is as follows: onWillAppear > onDidAppear > (onDateAccept/onCancel/onDateChange) > onWillDisappear > onDidDisappear.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| onWillAppear<sup>12+</sup> | () => void | No| Event callback when the dialog box is about to appear.<br>**NOTE**<br>1. The normal timing sequence is as follows: onWillAppear > onDidAppear > (onDateAccept/onCancel/onDateChange) > onWillDisappear > onDidDisappear.<br>2. You can set the callback event for changing the dialog box display effect in **onWillAppear**. The settings take effect next time the dialog box appears.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| onWillDisappear<sup>12+</sup> | () => void | No| Event callback when the dialog box is about to disappear.<br>**NOTE**<br>1. The normal timing sequence is as follows: onWillAppear > onDidAppear > (onDateAccept/onCancel/onDateChange) > onWillDisappear > onDidDisappear.<br>2. If the user dismisses the dialog box immediately after it appears, **onWillDisappear** is invoked before **onDidAppear**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| keyboardAvoidMode<sup>12+</sup> | [KeyboardAvoidMode](./arkui-ts/ts-types.md#keyboardavoidmode12) | No| How the dialog box avoids the soft keyboard when it is brought up.<br>Default value: **KeyboardAvoidMode.DEFAULT**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| enableHoverMode<sup>14+</sup>   | boolean | No  | Whether to enable the hover state.<br>Default value: **false**, meaning not to enable the hover state.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| hoverModeArea<sup>14+</sup>     | [HoverModeAreaType](arkui-ts/ts-appendix-enums.md#hovermodeareatype14) | No  | Display area of the dialog box in the hover state.<br>Default value: **HoverModeAreaType.BOTTOM_SCREEN**<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| backgroundBlurStyleOptions<sup>18+</sup> | [BackgroundBlurStyleOptions](arkui-ts/ts-universal-attributes-background.md#backgroundblurstyleoptions10) | No| Options for customizing the background blur style.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| backgroundEffect<sup>18+</sup> | [BackgroundEffectOptions](arkui-ts/ts-universal-attributes-background.md#backgroundeffectoptions11) | No| Options for customizing the background effect.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| keyboardAvoidDistance<sup>15+</sup>       | [LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12) | No  | Distance between the dialog box and the keyboard after keyboard avoidance is applied.<br>**NOTE**<br>- Default value: **16vp**<br>- Default unit: vp<br>- This parameter takes effect only when **keyboardAvoidMode** is set to **DEFAULT**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| levelMode<sup>15+</sup>       | [LevelMode](#levelmode15) | No  | Display level of the dialog box.<br>**NOTE**<br>- Default value: **LevelMode.OVERLAY**<br>- This parameter takes effect only when **showInSubWindow** is set to **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| levelUniqueId<sup>15+</sup>       | number | No  | [Unique ID](js-apis-arkui-frameNode.md#getuniqueid12) of the node under the display level for the page-level dialog box.<br>**NOTE**<br>- This parameter takes effect only when **levelMode** is set to **LevelMode.EMBEDDED**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| immersiveMode<sup>15+</sup>       | [ImmersiveMode](#immersivemode15) | No  | Overlay effect for the page-level dialog box.<br>**NOTE**<br>- Default value: **ImmersiveMode.DEFAULT**<br>- This parameter takes effect only when **levelMode** is set to **LevelMode.EMBEDDED**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| levelOrder<sup>18+</sup>       | [LevelOrder](#levelorder18) | No  | Display order of the dialog box.<br>**NOTE**<br>- Default value: **LevelOrder.clamp(0)**<br>- Dynamic updating is not supported.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| focusable<sup>18+</sup>       | boolean | No  | Whether the dialog box can gain focus.<br>Default value: **true**<br>**NOTE**<br>Only dialog boxes that are displayed on top of the current window can gain focus.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## DismissDialogAction<sup>12+</sup>

Provides information about the action to dismiss the dialog box.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### Attributes

| Name   | Type                                                        | Readable| Writable| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| dismiss | Callback&lt;void&gt;                                         | No  | No  | Callback for dismissing the dialog box. This API is called only when the dialog box needs to be exited.|
| reason  | [DismissReason](#dismissreason12) | No  | No  | Reason why the dialog box cannot be dismissed. You must specify whether to dismiss the dialog box for each of the listed actions.|

## DismissReason<sup>12+</sup>

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name         | Value  | Description                                                        |
| ------------- | ---- | ------------------------------------------------------------ |
| PRESS_BACK    | 0    | Touching the Back button, swiping left or right on the screen, or pressing the Esc key.                          |
| TOUCH_OUTSIDE | 1    | Touching the mask.                                              |
| CLOSE_BUTTON  | 2    | Touching the Close button.                                              |
| SLIDE_DOWN    | 3    | Sliding down.<br>**NOTE**<br>This API is effective only in [sheet transition](./arkui-ts/ts-universal-attributes-sheet-transition.md).|

## LevelMode<sup>15+</sup>

Enumerates the display level modes of the dialog box.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Value  | Description                                            |
| ------- | ---- | ------------------------------------------------ |
| OVERLAY | 0    | The dialog box is displayed at the root node level of the application window and remain visible during navigation.|
| EMBEDDED    | 1    | The dialog box is a child of the page's route/navigation and is hidden when the page is hidden.|

## ImmersiveMode<sup>15+</sup>

Enumerates the display area modes of the dialog box overlay within a page.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Value  | Description                                            |
| ------- | ---- | ------------------------------------------------ |
| DEFAULT | 0    | The dialog box overlay follows the layout constraints of its parent node.|
| EXTEND    | 1    | The dialog box overlay can extend to cover the status bar and navigation bar for a more immersive look.

## Button

Describes the menu item button in the action menu.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name   | Type                                      | Mandatory  | Description     |
| ----- | ---------------------------------------- | ---- | ------- |
| text  | string \| [Resource](arkui-ts/ts-types.md#resource)| Yes   | Button text.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| color | string \|  [Resource](arkui-ts/ts-types.md#resource) | Yes   | Text color of the button.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| primary<sup>12+</sup> | boolean | No   | Whether the button responds to the **Enter** key by default when the dialog box has focus and the **Tab** key is not pressed for sequential focus navigation. If there are multiple buttons, set this parameter to **true** for only one button. Otherwise, no button will respond. Multiple dialog boxes can automatically gain focus and respond to user interactions in a sequential manner.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
