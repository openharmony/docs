# Dialog Controller
The dialog controller in ArkUI provides the capability to operate on a bound dialog box. Currently, it supports the close functionality. You can pass the controller into the dialog box content area to perform operations.

Since API version 18, you can set the [controller](../reference/apis-arkui/js-apis-promptAction.md#dialogcontroller18) parameter to bind the controller, and operate the dialog box through the controller.

## Constraints

Currently, the [openCustomDialogWithController](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialogwithcontroller18) and [presentCustomDialog](../reference/apis-arkui/js-apis-arkui-UIContext.md#presentcustomdialog18) APIs support binding dialog controllers through the **controller** parameter. The [getDialogController](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#getdialogcontroller18) API can obtain the dialog controller for the custom component where the dialog box is located.

> **NOTE**
> 
> A dialog controller can be bound to only one dialog box, and operations only affect that dialog box.
> When [getDialogController](../reference/apis-arkui/arkui-ts/ts-custom-component-api.md#getdialogcontroller18) is used to obtain the dialog controller, if the current custom component is not displayed in a dialog box, the result will be **undefined**.

## Creating a Dialog Box Controller with ComponentContent as Custom Content

> **NOTE**
> 
> For details about the variables, see [Example](#example).

1. Initialize a parameter class for the custom dialog box content area, which includes the dialog controller.

  ```ts
  class Params {
    public text: string = ''
    public dialogController: promptAction.CommonController = new promptAction.DialogController()
    constructor(text: string, dialogController: promptAction.CommonController) {
      this.text = text
      this.dialogController = dialogController
    }
  }
  ```

2. Initialize a custom dialog box content area that includes a button, which closes the dialog box using the dialog controller provided by the custom component.

  ```ts
  @Component
  struct MyComponent {
    build() {
      Column({ space: 5 }) {
        Button('Close Dialog Box: Using Built-in DialogController')
          .onClick(() => {
            let dialogController: promptAction.DialogController = this.getDialogController()
            if (dialogController !== undefined) {
              dialogController.close()
            }
          })
      }
    }
  }
  ```

3. Initialize another custom dialog box content area that includes a **Text** component and a button, which closes the dialog box using the externally passed dialog controller. This content area also includes the previous custom dialog box content area.

  ```ts
  @Builder
  function buildText(params: Params) {
    Column({ space: 5 }) {
      Text(params.text)
        .fontSize(30)
      if (params.dialogController !== undefined) {
        Button('Close Dialog Box: Using Externally Passed DialogController')
          .onClick(() => {
            params.dialogController.close()
          })
      }
      MyComponent()
    }
    .width(300)
    .height(200)
    .backgroundColor('#FFF0F0F0')
  }
  ```

4. Initialize a dialog controller and create a dialog box content entity object by setting the **controller** parameter. Finally, obtain a [PromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#promptaction) object through the [getPromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#getpromptaction) API of [UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext), and call the [openCustomDialogWithController](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialogwithcontroller18) API with the initialized content entity object and **controller** parameter to create the dialog box.

  ```ts
  let dialogController: promptAction.CommonController = new promptAction.DialogController()
  let contentNode: ComponentContent<Object> =
    new ComponentContent(this.getUIContext(), wrapBuilder(buildText), new Params(this.message, dialogController))
  this.getUIContext().getPromptAction().openCustomDialogWithController(
    contentNode, dialogController, this.baseDialogOptions).catch((err: BusinessError) => {
    console.error('openCustomDialogWithController error: ' + err.code + ' ' + err.message)
  })
  ```

## Creating a Dialog Box Controller with CustomBuilder as Custom Content

> **NOTE**
> 
> For details about the variables, see [Example](#example).

1. Initialize a custom dialog box content area that includes a **Text** component and a button, which closes the dialog box using the externally passed dialog controller.

  ```ts
  @Builder customDialogComponent(dialogController: promptAction.DialogController) {
    Column({ space: 5 }) {
      Text(this.message)
        .fontSize(30)
      if (dialogController !== undefined) {
        Button('Close Dialog Box: Using Externally Passed DialogController')
          .onClick(() => {
            dialogController.close()
          })
      }
    }
    .height(200)
    .padding(5)
    .justifyContent(FlexAlign.SpaceBetween)
    .backgroundColor('#FFF0F0F0')
  }
  ```

2. Initialize a dialog box controller and obtain a [PromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#promptaction) object through the [getPromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#getpromptaction) API of [UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext), and call the [presentCustomDialog](../reference/apis-arkui/js-apis-arkui-UIContext.md#presentcustomdialog18) API with the initialized content entity object and **controller** parameter to create the dialog box.

  ```ts
  let dialogController: promptAction.CommonController = new promptAction.DialogController()
  this.getUIContext().getPromptAction().presentCustomDialog(() => {
    this.customDialogComponent(dialogController)
  }, dialogController, this.dialogOptions).catch((err: BusinessError) => {
    console.error('presentCustomDialog error: ' + err.code + ' ' + err.message)
  })
  ```

## Creating a Dialog Box Controller with CustomBuilderWithId as Custom Content

> **NOTE**
> 
> For details about the variables, see [Example](#example).

1. Initialize a dialog box content area that includes a **Text** component, a button that closes the dialog box using the externally passed dialog ID, and a button that closes the dialog box using the externally passed dialog controller.

  ```ts
  @Builder customDialogComponentWithId(dialogId: number, dialogController: promptAction.DialogController) {
    Column({ space: 5 }) {
      Text(this.message)
        .fontSize(30)
      if (dialogId !== undefined) {
        Button('Close Dialog Box: Using DialogID')
          .onClick(() => {
            this.getUIContext().getPromptAction().closeCustomDialog(dialogId)
          })
      }
      if (dialogController !== undefined) {
        Button('Close Dialog Box: Using Externally Passed DialogController')
          .onClick(() => {
            dialogController.close()
          })
      }
    }
  }
  ```

2. Initialize a dialog box controller and obtain a [PromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#promptaction) object through the [getPromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#getpromptaction) API of [UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext), and call the [presentCustomDialog](../reference/apis-arkui/js-apis-arkui-UIContext.md#presentcustomdialog18) API with the initialized content entity object and **controller** parameter to create the dialog box.

  ```ts
  let dialogController: promptAction.CommonController = new promptAction.DialogController()
  this.getUIContext().getPromptAction().presentCustomDialog((dialogId: number) => {
    this.customDialogComponentWithId(dialogId, dialogController)
  }, dialogController, this.dialogOptions).catch((err: BusinessError) => {
    console.error('presentCustomDialog error: ' + err.code + ' ' + err.message)
  })
  ```

## Directly Obtaining the Dialog Box Controller in the CustomDialogController Content Area

> **NOTE**
> 
> For details about the variables, see [Example](#example).

1. Initialize a custom dialog box content area that includes a **Text** component and a button, which closes the dialog box using the dialog controller.

```ts
@CustomDialog
@Component
struct CustomDialogExample {
  controller?: CustomDialogController

  build() {
    Column({ space: 5 }) {
      Text('I am content')
        .fontSize(30)
      Button('Close Dialog Box: Using Built-in DialogController')
        .onClick(() => {
          let dialogController: PromptActionDialogController = this.getDialogController()
          if (dialogController !== undefined) {
            dialogController.close()
          }
        })
    }
    .height(200)
    .backgroundColor('#FFF0F0F0')
  }
}
```

2. Initialize a custom dialog box constructor and associate it with the custom dialog box content area.

  ```ts
  let customDialogController: CustomDialogController = new CustomDialogController({
    builder: CustomDialogExample(),
  })
  customDialogController.open()
  ```

## Example
The example demonstrates how to use both the externally passed dialog controller and the dialog controller provided by the custom component to close the dialog box within the custom dialog box content area.
  ```ts
  import { ComponentContent, promptAction } from '@kit.ArkUI'
  import { BusinessError } from '@kit.BasicServicesKit'

  class Params {
    public text: string = ''
    public dialogController: promptAction.CommonController = new promptAction.DialogController()
    constructor(text: string, dialogController: promptAction.CommonController) {
      this.text = text
      this.dialogController = dialogController
    }
  }

  @Component
  struct MyComponent {
    build() {
      Column({ space: 5 }) {
        Button('Close Dialog Box: Using Built-in DialogController')
          .onClick(() => {
            let dialogController: promptAction.DialogController = this.getDialogController()
            if (dialogController !== undefined) {
              dialogController.close()
            }
          })
      }
    }
  }

  @Builder
  function buildText(params: Params) {
    Column({ space: 5 }) {
      Text(params.text)
        .fontSize(30)
      if (params.dialogController !== undefined) {
        Button('Close Dialog Box: Using Externally Passed DialogController')
          .onClick(() => {
            params.dialogController.close()
          })
      }
      MyComponent()
    }
    .width(300)
    .height(200)
    .backgroundColor('#FFF0F0F0')
  }

  @CustomDialog
  @Component
  struct CustomDialogExample {
    controller?: CustomDialogController

    build() {
      Column({ space: 5 }) {
        Text('I am content')
          .fontSize(30)
        Button('Close Dialog Box: Using Built-in DialogController')
          .onClick(() => {
            let dialogController: PromptActionDialogController = this.getDialogController()
            if (dialogController !== undefined) {
              dialogController.close()
            }
          })
      }
      .height(200)
      .backgroundColor('#FFF0F0F0')
    }
  }

  @Entry
  @Component
  export struct Index {
    private message = 'Dialog box'
    @Builder customDialogComponent(dialogController: promptAction.DialogController) {
      Column({ space: 5 }) {
        Text(this.message)
          .fontSize(30)
        if (dialogController !== undefined) {
          Button('Close Dialog Box: Using Externally Passed DialogController')
            .onClick(() => {
              dialogController.close()
            })
        }
      }
      .height(200)
      .padding(5)
      .justifyContent(FlexAlign.SpaceBetween)
      .backgroundColor('#FFF0F0F0')
    }

    @Builder customDialogComponentWithId(dialogId: number, dialogController: promptAction.DialogController) {
      Column({ space: 5 }) {
        Text(this.message)
          .fontSize(30)
        if (dialogId !== undefined) {
          Button('Close Dialog Box: Using DialogID')
            .onClick(() => {
              this.getUIContext().getPromptAction().closeCustomDialog(dialogId)
            })
        }
        if (dialogController !== undefined) {
          Button('Close Dialog Box: Using Externally Passed DialogController')
            .onClick(() => {
              dialogController.close()
            })
        }
      }
    }

    private baseDialogOptions: promptAction.BaseDialogOptions = {
      isModal: false,
      autoCancel: false
    }

    private dialogOptions: promptAction.DialogOptions = {
      isModal: false,
      autoCancel: false
    }

    build() {
      Column({ space: 5 }) {
        Button('openCustomDialogWithController')
          .onClick(() => {
            let dialogController: promptAction.CommonController = new promptAction.DialogController()
            let contentNode: ComponentContent<Object> =
              new ComponentContent(this.getUIContext(), wrapBuilder(buildText), new Params(this.message, dialogController))
            this.getUIContext().getPromptAction().openCustomDialogWithController(
              contentNode, dialogController, this.baseDialogOptions).catch((err: BusinessError) => {
              console.error('openCustomDialogWithController error: ' + err.code + ' ' + err.message)
            })
          })
        Button('presentCustomDialog+CustomBuilder')
          .onClick(() => {
            let dialogController: promptAction.CommonController = new promptAction.DialogController()
            this.getUIContext().getPromptAction().presentCustomDialog(() => {
              this.customDialogComponent(dialogController)
            }, dialogController, this.dialogOptions).catch((err: BusinessError) => {
              console.error('presentCustomDialog error: ' + err.code + ' ' + err.message)
            })
          })
        Button('presentCustomDialog+CustomBuilderWithId')
          .onClick(() => {
            let dialogController: promptAction.CommonController = new promptAction.DialogController()
            this.getUIContext().getPromptAction().presentCustomDialog((dialogId: number) => {
              this.customDialogComponentWithId(dialogId, dialogController)
            }, dialogController, this.dialogOptions).catch((err: BusinessError) => {
              console.error('presentCustomDialog error: ' + err.code + ' ' + err.message)
            })
          })
        Button('CustomDialogController')
          .onClick(() => {
            let customDialogController: CustomDialogController = new CustomDialogController({
              builder: CustomDialogExample(),
            })
            customDialogController.open()
          })
      }.width('100%')
    }
  }
  ```

