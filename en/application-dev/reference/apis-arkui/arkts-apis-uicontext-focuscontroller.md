# Class (FocusController)

Provides capabilities to control focus, including features such as clearing, moving, and activating focus.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - In the following API examples, you must first use [getFocusController()](arkts-apis-uicontext-uicontext.md#getfocuscontroller12) in **UIContext** to obtain a **FocusController** instance, and then call the APIs using the obtained instance.

## clearFocus<sup>12+</sup>

clearFocus(): void

Clears the focus and forcibly moves the focus to the root container node of the page, causing other nodes in the focus chain to lose focus.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Example**

```ts
@Entry
@Component
struct ClearFocusExample {
  @State inputValue: string = '';
  @State btColor: Color = Color.Blue;

  build() {
    Column({ space: 20 }) {
      Column({ space: 5 }) {
        Button('button1')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(Color.Blue)
        Button('button2')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(this.btColor)
          .defaultFocus(true)
          .onFocus(() => {
            this.btColor = Color.Red;
          })
          .onBlur(() => {
            this.btColor = Color.Blue;
          })
        Button('clearFocus')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .backgroundColor(Color.Blue)
          .onClick(() => {
            this.getUIContext().getFocusController().clearFocus();
          })
      }
    }
    .width('100%')
    .height('100%')
  }
}
```

## requestFocus<sup>12+</sup>

requestFocus(key: string): void

Transfers focus to a component node by the component ID, which is effective immediately.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| key | string | Yes| [Component ID](arkui-ts/ts-universal-attributes-component-id.md) of the target node.|

**Error codes**

For details about the error codes, see [Focus Error Codes](errorcode-focus.md).

| ID| Error Message                                       |
| -------- | ----------------------------------------------- |
| 150001   | the component cannot be focused.                |
| 150002   | This component has an unfocusable ancestor.     |
| 150003   | the component is not on tree or does not exist. |

**Example**

```ts
@Entry
@Component
struct RequestExample {
  @State btColor: Color = Color.Blue;

  build() {
    Column({ space: 20 }) {
      Column({ space: 5 }) {
        Button('Button')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(this.btColor)
          .onFocus(() => {
            this.btColor = Color.Red;
          })
          .onBlur(() => {
            this.btColor = Color.Blue;
          })
          .id("testButton")

        Divider()
          .vertical(false)
          .width("80%")
          .backgroundColor(Color.Black)
          .height(10)

        Button('requestFocus')
          .width(200)
          .height(70)
          .onClick(() => {
            this.getUIContext().getFocusController().requestFocus("testButton");
          })

        Button('requestFocus fail')
          .width(200)
          .height(70)
          .onClick(() => {
            try {
              this.getUIContext().getFocusController().requestFocus("eee");
            } catch (error) {
              console.error('requestFocus failed code is ' + error.code + ' message is ' + error.message);
            }
          })
      }
    }
    .width('100%')
    .height('100%')
  }
}
```

## activate<sup>14+</sup>

activate(isActive: boolean, autoInactive?: boolean): void

Sets the [focus activation state](../../ui/arkts-common-events-focus-event.md) of this page.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| isActive| boolean| Yes| Whether to enter or exit the focus activation state.<br>The value **true** means to enter the focus activation state, and **false** means to exit the focus activation state.|
| autoInactive | boolean | No| Logic for exiting the focus activation state.<br>The value **true** means the focus activation state will be exited automatically when touch or mouse events are triggered, and **false** means the state is controlled solely by API calls.<br>Default value: **true**|

**Example**

```ts
// This example demonstrates how to enter the focus activation state when the page loading is completed. In this state, arrow keys can be used for focus navigation.
@Entry
@Component
struct ActivateExample {
  aboutToAppear() {
    this.getUIContext().getFocusController().activate(true, false);
  }

  aboutToDisappear() {
    this.getUIContext().getFocusController().activate(false);
  }

  build() {
    Row() {
      Button('Button1')
        .width(200)
        .height(70)
        .defaultFocus(true)

      Button('Button2')
        .width(200)
        .height(70)

      Button('Button3')
        .width(200)
        .height(70)
    }
    .padding(10)
    .justifyContent(FlexAlign.SpaceBetween)
    .width(800)
  }
}
```

## isActive<sup>20+</sup>

isActive(): boolean

Obtains the focus activation state of the UI instance.

For details about the focus activation state, see [Basic Concepts](../../ui/arkts-common-events-focus-event.md#basic-concepts).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type         | Description      |
| ------------  | --------- |
|  boolean  | Focus activation state of the UI instance. The value **true** means that the instance has entered the focus activation state, and **false** means that the instance has exited the focus activation state.|

**Example**

The following example verifies that **isActive()** returns the focus activation state of the UI instance.

```ts
@Entry
@Component
struct ClearFocusExample {
  @State inputValue: string = '';
  @State btColor: Color = Color.Blue;

  build() {
    Column({ space: 20 }) {
      Column({ space: 5 }) {
        Button('button1')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(Color.Blue)
          .onClick(()=> {
            console.log("button1 onClick");
            this.getUIContext().getFocusController().activate(true);
            console.log("focus status " + this.getUIContext().getFocusController().isActive());
          })
        Button('button2')
          .width(200)
          .height(70)
          .fontColor(Color.White)
          .focusOnTouch(true)
          .backgroundColor(this.btColor)
          .defaultFocus(true)
          .onClick(()=> {
            console.log("button2 onClick");
            this.getUIContext().getFocusController().activate(false);
            console.log("focus status " + this.getUIContext().getFocusController().isActive());
          })
          .onFocus(() => {
            this.btColor = Color.Red;
          })
          .onBlur(() => {
            this.btColor = Color.Blue;
          })
      }
    }
    .width('100%')
    .height('100%')
  }
}
```

## setAutoFocusTransfer<sup>14+</sup>

setAutoFocusTransfer(isAutoFocusTransfer: boolean): void

Sets whether the new page automatically obtains focus during page switching.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| isAutoFocusTransfer | boolean| Yes| Whether the new page automatically obtains focus during page switching using navigation components or APIs, such as [Router](js-apis-router.md#routerpushurldeprecated), [Navigation](arkui-ts/ts-basic-components-navigation.md), [Menu](arkui-ts/ts-basic-components-menu.md), [Dialog](arkui-ts/ohos-arkui-advanced-Dialog.md), and [Popup](arkui-ts/ohos-arkui-advanced-Popup.md). The value **true** means the new page automatically obtains focus, and **false** means the opposite. Default value: **true**.|

**Example**

```ts
@CustomDialog
struct CustomDialogExample {
  controller?: CustomDialogController;
  build() {
    Column() {
      Text('This is a custom dialog box')
        .fontSize(30)
        .height(100)
      Text('The dialog box should not automatically acquire focus')
        .fontSize(20)
        .height(100)
      Button('Close Dialog Box')
        .onClick(() => {
          if (this.controller != undefined) {
            this.getUIContext().getFocusController().setAutoFocusTransfer(true);
            this.controller.close();
          }
        })
        .margin(20)
    }
  }
}
@Entry
@Component
struct CustomDialogUser {
  dialogController: CustomDialogController | null = new CustomDialogController({
    builder: CustomDialogExample({
    }),
  });
  aboutToDisappear() {
    this.dialogController = null;
  }

  build() {
    Column() {
      Button('click me')
        .onClick(() => {
          if (this.dialogController != null) {
            this.getUIContext().getFocusController().setAutoFocusTransfer(false);
            this.dialogController.open();
          }
        }).backgroundColor(0x317aff)
    }.width('100%').margin({ top: 5 })
  }
}
```

## setKeyProcessingMode<sup>15+</sup>

setKeyProcessingMode(mode: KeyProcessingMode): void

Sets the mode for processing key events.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| mode | [KeyProcessingMode](./arkui-ts/ts-universal-attributes-focus.md#keyprocessingmode15)| Yes| Mode for processing key events.|

**Example**

```ts

// This example demonstrates how to set the focus behavior after the page is loaded.
@Entry
@Component
struct Index {

  aboutToAppear() {
    this.getUIContext().getFocusController().setKeyProcessingMode(KeyProcessingMode.ANCESTOR_EVENT);
  }

  build() {
    Row() {
      Row() {
        Button('Button1').id('Button1').onKeyEvent((event) => {
          console.log("Button1");
          return true;
        })
        Button('Button2').id('Button2').onKeyEvent((event) => {
          console.log("Button2");
          return true;
        })
      }
      .width('100%')
      .height('100%')
      .id('Row1')
      .onKeyEventDispatch((event) => {
        let context = this.getUIContext();
        context.getFocusController().requestFocus('Button1');
        return context.dispatchKeyEvent('Button1', event);
      })
    }
    .height('100%')
    .width('100%')
    .onKeyEventDispatch((event) => {
      if (event.type == KeyType.Down) {
        let context = this.getUIContext();
        context.getFocusController().requestFocus('Row1');
        return context.dispatchKeyEvent('Row1', event);
      }
      return true;
    })
  }
}
```
