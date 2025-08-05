# Dialog Box Focus Policy
The focus strategy of ArkUI dialog boxes can be configured to determine whether to interrupt the user's current operation and shift focus to the newly opened dialog box. If the dialog box is set not to acquire focus, it will not interrupt the user's current operation when it appears. For example, when a user is entering text in a text box, a newly opened dialog box will not close the soft keyboard, and focus will remain on the text box.

Since API version 19, the [focusable](../reference/apis-arkui/js-apis-promptAction.md#basedialogoptions11) parameter can be used to control whether a dialog box acquires focus.

## Constraints

The [openCustomDialog](arkts-uicontext-custom-dialog.md) and [CustomDialog](arkts-common-components-custom-dialog.md) APIs support management focus acquisition through the **focusable** parameter.

> **NOTE**
> 
> Only dialog boxes that are displayed on top of the current window can acquire focus.

## Creating a Non-Focusable Dialog Box

> **NOTE**
> 
> For details about the variables, see [Example](#example).

1. Initialize a dialog box content area containing a **Text** component.

  ```ts
  private message = 'Dialog box'
  @State dialogIdIndex: number = 0
  @Builder customDialogComponent() {
    Column({ space: 5 }) {
      Text(this.message + this.dialogIdIndex)
        .fontSize(30)
    }
    .height(200)
    .padding(5)
    .justifyContent(FlexAlign.SpaceBetween)
  }
  ```

2. Create a **TextInput** component. In its **onChange** event function, obtain the [PromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#promptaction) object by calling the [getPromptAction](../reference/apis-arkui/js-apis-arkui-UIContext.md#getpromptaction) API of [UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext). Then, use this object to call the [openCustomDialog](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialog12) API and set the [focusable](../reference/apis-arkui/js-apis-promptAction.md#basedialogoptions11) parameter to **false** to create the dialog box.

  ```ts
  TextInput()
    .onChange(() => {
      this.dialogIdIndex++
      this.getUIContext().getPromptAction().openCustomDialog({
        builder: () => {
          this.customDialogComponent()
        },
        focusable: false
      }).then((dialogId: number) => {
        setTimeout(() => {
          this.getUIContext().getPromptAction().closeCustomDialog(dialogId);
        }, 3000)
      })
    })
  ```

## Example
This example demonstrates how to achieve the following effect: When the user is entering text in the text box, the newly opened dialog box will not close the soft keyboard, and focus will remain on the text box.
  ```ts
  @Entry
  @Component
  export struct Index {
    private message = 'Dialog box'
    @State dialogIdIndex: number = 0
    @Builder customDialogComponent() {
      Column({ space: 5 }) {
        Text(this.message + this.dialogIdIndex)
          .fontSize(30)
      }
      .height(200)
      .padding(5)
      .justifyContent(FlexAlign.SpaceBetween)
    }

    build() {
      Column({ space: 5 }) {
        TextInput()
          .onChange(() => {
            this.dialogIdIndex++
            this.getUIContext().getPromptAction().openCustomDialog({
              builder: () => {
                this.customDialogComponent()
              },
              focusable: false
            }).then((dialogId: number) => {
              setTimeout(() => {
                this.getUIContext().getPromptAction().closeCustomDialog(dialogId);
              }, 3000)
            })
          })
      }.width('100%')
    }
  }
  ```
![dialog-focusable-demo1](figures/dialog-focusable-demo1.gif)
