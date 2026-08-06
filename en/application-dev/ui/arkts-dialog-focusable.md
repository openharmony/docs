# Dialog Box Focus Policy

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @houguobiao-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=b8421fa94775fa4bceb1b522857b705478302935 translatedAt=2026-07-30T11:31:25.130Z pushedAt=2026-07-30T12:15:42.846Z -->

The focus strategy of ArkUI dialog boxes can be configured to determine whether to interrupt the user's current operation and shift focus to the newly opened dialog box. If the dialog box is set not to acquire focus, it will not interrupt the user's current operation when it appears. For example, when a user is entering text in a text box, a newly opened dialog box will not close the soft keyboard, and focus will remain on the text box.

Since API version 19, the [focusable](../reference/apis-arkui/js-apis-promptAction.md#basedialogoptions11) parameter can be used to control whether a dialog box acquires focus.

## Constraints

The [openCustomDialog](arkts-uicontext-custom-dialog.md) and [CustomDialog](arkts-common-components-custom-dialog.md) APIs support managing whether the dialog gains focus through the **focusable** parameter.

> **NOTE**
> 
> Only dialog boxes that are displayed on top of the current window can acquire focus.

## Creating a Non-Focusable Dialog Box

> **NOTE**
> 
> For details about the variables, see [Example](#example).

1. Initialize a dialog box content area containing a **Text** component.

    <!-- @[dialog_focus_text](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/customdialog/dialogboxfocuspolicy/DialogFocusStrategy.ets) -->

    ``` TypeScript
    @State dialogIdIndex: number = 0;
    // Configure the resource whose name is 'dialog_message' and value is a non-empty string in the resources\base\element\string.json file.
    private message: string =
      this.getUIContext().getHostContext()?.resourceManager.getStringByNameSync('dialog_message') as string;
    // Stores all timer IDs for delayed dialog closing. Cleared when the page is destroyed.
    private timerIdList: number[] = [];
    // Marks whether the page has been destroyed. Dialog closing logic will not execute after destruction.
    private isPageDestroy: boolean = false;
    
    /**
     * Page destroy lifecycle: Clear all timers to prevent exceptions caused by delayed pop-up closure and avoid memory leaks.
     */
    aboutToDisappear(): void {
      this.isPageDestroy = true;
      // Iterates through and clears all unexecuted timers.
      this.timerIdList.forEach(timerId => {
        clearTimeout(timerId);
      });
      this.timerIdList = [];
    }
    
    @Builder
    customDialogComponent() {
      Column({ space: 5 }) {
        Text(this.message + this.dialogIdIndex)
          .fontSize(30)
      }
      .height(200)
      .padding(5)
      .justifyContent(FlexAlign.SpaceBetween)
    }
    ```

2. Create a **TextInput** component. In its **onChange** event function, obtain the [PromptAction](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md) object by calling the [getPromptAction](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#getpromptaction) API of [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md). Then, use this object to call the [openCustomDialog](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialog12) API and set the [focusable](../reference/apis-arkui/js-apis-promptAction.md#basedialogoptions11) parameter to **false** to create the dialog box.

    <!-- @[dialog_focus_text_input](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/customdialog/dialogboxfocuspolicy/DialogFocusStrategy.ets) -->

    ``` TypeScript
    TextInput()
      .onChange(() => {
        this.dialogIdIndex++;
        this.getUIContext().getPromptAction().openCustomDialog({
          builder: () => {
            this.customDialogComponent();
          },
          focusable: false
        })
        .then((dialogId: number) => {
          // Create a delayed close timer.
          const timerId = setTimeout(() => {
            // Skip the close logic if the page has been destroyed.
            if (this.isPageDestroy) {
              return;
            }
            try {
              this.getUIContext().getPromptAction().closeCustomDialog(dialogId);
            } catch (error) {
              console.error('closeCustomDialog error');
            }
            // Remove the completed timer record after closing the dialog box.
            const idx = this.timerIdList.findIndex(item => item === timerId);
            if (idx > -1) {
              this.timerIdList.splice(idx, 1);
            }
          }, 3000);
          // Save the timer ID for unified cleanup when the page is destroyed.
          this.timerIdList.push(timerId);
        })
        .catch(() => {
          console.error('openCustomDialog failed');
        });
      })
    ```

## Example

This example demonstrates how to achieve the following effect: When the user is entering text in the text box, the newly opened dialog box will not close the soft keyboard, and focus will remain on the text box.

<!-- @[dialog_focus](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/customdialog/dialogboxfocuspolicy/DialogFocusStrategy.ets) -->

``` TypeScript
@Entry
@Component
export struct Index {
  @State dialogIdIndex: number = 0;
  // Configure the resource whose name is 'dialog_message' and value is a non-empty string in the resources\base\element\string.json file.
  private message: string =
    this.getUIContext().getHostContext()?.resourceManager.getStringByNameSync('dialog_message') as string;
  // Array that stores all dialog delayed-close timer IDs for unified cleanup when the page is destroyed.
  private timerIdList: number[] = [];
  // Marks whether the page has been destroyed. After destruction, the dialog close logic is no longer executed.
  private isPageDestroy: boolean = false;

  /**
   * Page destroy lifecycle: Clear all timers to prevent exceptions caused by delayed pop-up closure and avoid memory leaks.
   */
  aboutToDisappear(): void {
    this.isPageDestroy = true;
    // Traverse and clear all unexecuted timers.
    this.timerIdList.forEach(timerId => {
      clearTimeout(timerId);
    });
    this.timerIdList = [];
  }

  @Builder
  customDialogComponent() {
    Column({ space: 5 }) {
      Text(this.message + this.dialogIdIndex)
        .fontSize(30)
    }
    .height(200)
    .padding(5)
    .justifyContent(FlexAlign.SpaceBetween)
  }


  build() {
    NavDestination() {
      Column({ space: 5 }) {
        TextInput()
          .onChange(() => {
            this.dialogIdIndex++;
            this.getUIContext().getPromptAction().openCustomDialog({
              builder: () => {
                this.customDialogComponent();
              },
              focusable: false
            })
            .then((dialogId: number) => {
              // Create a delayed-close timer.
              const timerId = setTimeout(() => {
                // Skip the close logic if the page has been destroyed.
                if (this.isPageDestroy) {
                  return;
                }
                try {
                  this.getUIContext().getPromptAction().closeCustomDialog(dialogId);
                } catch (error) {
                  console.error('closeCustomDialog error');
                }
                // Remove the completed timer record after closing the dialog.
                const idx = this.timerIdList.findIndex(item => item === timerId);
                if (idx > -1) {
                  this.timerIdList.splice(idx, 1);
                }
              }, 3000);
              // Save the timer ID for unified cleanup when the page is destroyed.
              this.timerIdList.push(timerId);
            })
            .catch(() => {
              console.error('openCustomDialog failed');
            });
          })
      }.width('100%')
    }
  }
}
```

![dialog-focusable-demo1](figures/dialog-focusable-demo1.gif)