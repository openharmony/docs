# Input Box and Input Method Interaction in Non-Focusable Windows

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=3103aea9f27e22b8029f7224f57c27c4f91680cc translatedAt=2026-08-04T08:30:25.860Z pushedAt=2026-08-04T09:02:56.196Z -->

## When to Use

Before using an input method, its host application must have focus. You need to handle focus correctly to ensure the proper functioning of input methods.

For example, during application development, you can use [setWindowFocusable](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowfocusable9) to set the **focusable** property of the created window (such as floating window and auxiliary interaction window) to **false**, and draw an input box (such as [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md), [TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md), or a [custom edit box](use-inputmethod-in-custom-edit-box.md)) in the window to launch the system keyboard for inputs.

## System Restrictions

When a window is set to be non-focusable via [setWindowFocusable](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowfocusable9), the system imposes restrictions on it. Since the window is not focusable, input events (such as key information) cannot be correctly received and processed by the window. The input content cannot be synchronized to the input box in the window, resulting in abnormal interaction between the input box and the keyboard.

## Recommended Solution

If you need to draw an input box in a non-focusable window and expect the input box to interact with the keyboard, you are advised to develop the input box in the following way (using [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md) as an example):

1. Create a subwindow in the main window and set the subwindow to be non-focusable.

   Effect: When you tap the input component in the main window, the subwindow pops up, and the focus remains on the input box in the main window.

   ```ts
   // Index.ets implements the layout of the main window.
   import { window } from '@kit.ArkUI';
   
   @Entry
   @Component
   struct Index {
     async createSubWindow() {
       try {
         // 1. Create a subwindow and set the subwindow ID.
         let windowStage: window.WindowStage | undefined = AppStorage.get('windowStage');
         if (windowStage == null) {
           console.error('Failed to get windowStage');
           return;
         }
         let options: window.SubWindowOptions = { title: 'title', decorEnabled: true };
         let subWindow = await windowStage?.createSubWindowWithOptions('mySubWindow', options);
         if (!subWindow) {
          console.error('Failed to create subWindow');
          return;
         }
         const subWindowId: number | undefined = subWindow?.getWindowProperties().id;
         AppStorage.setOrCreate('subWindowId', subWindowId);
         // 2. Set the child window as non-focusable. true indicates that focus is allowed, and false indicates that focus is not allowed.
         subWindow?.resize(500, 500);
         subWindow?.setUIContent("pages/SubWindowIndex");
         subWindow?.setWindowFocusable(false);
         // 3. Display the subwindow.
         subWindow?.showWindow();
       } catch (exception) {
         console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
       }
     }
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
         TextInput({ placeholder: 'Tap to create and display the subwindow.' })
           .onClick(() => {
             this.createSubWindow();
           })
       }
     }
   }
   ```

2. When a user taps the input box component in the subwindow, you can set the subwindow to be focusable via [setWindowFocusable](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowfocusable9), and then switch the focus from the main window to the subwindow using [shiftAppWindowFocus](../reference/apis-arkui/arkts-apis-window-f.md#windowshiftappwindowfocus11). After this, the input method can be used normally in the input box of the subwindow.

   ```ts
   // SubWindowIndex.ets implements the layout of the subwindow.
   import { window } from '@kit.ArkUI';
   
   @Entry
   @Component
   struct SubWindowIndex {
     async shiftFocusToSubWindow() {
       try {
         let windowStage: window.WindowStage | undefined = AppStorage.get('windowStage');
         if (windowStage == null) {
           console.error('Failed to get the subwindow. Cause: windowStage is undefined');
           return;
         }
         let subWindowList: window.Window[] = await windowStage?.getSubWindow();
         let subWindow: window.Window = subWindowList[0];
         // 1. Set the subwindow to be focusable.
         subWindow?.setWindowFocusable(true);
         // 2. Switch the focus to the subwindow.
         const mainWindowId: number = AppStorage.get('mainWindowId') || 0;
         const subWindowId: number = AppStorage.get('subWindowId') || 0;
         await window.shiftAppWindowFocus(mainWindowId, subWindowId);
       } catch (exception) {
         console.error(`Failed to shift focus to subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
       }
     }
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
         TextInput({ placeholder: 'This is an input component.' })
           .onClick(() => {
             // The user taps the input component of the subwindow to focus.
             this.shiftFocusToSubWindow();
           })
       }
     }
   }
   ```

3. When the user taps a non-input component in the subwindow again, the subwindow can be reset to be non-focusable via [setWindowFocusable](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowfocusable9), and the main window will be focused.

   ```ts
   // SubWindowIndex.ets implements the layout of the subwindow.
   import { window } from '@kit.ArkUI';
   
   @Entry
   @Component
   struct SubWindowIndex {
     async shiftFocusToSubWindow() {
       try {
         let windowStage: window.WindowStage | undefined = AppStorage.get('windowStage');
         if (windowStage == null) {
           console.error('Failed to get the subwindow. Cause: windowStage is undefined');
           return;
         }
         let subWindowList: window.Window[] = await windowStage?.getSubWindow();
         let subWindow: window.Window = subWindowList[0];
         // 1. Set the subwindow to be focusable.
         subWindow?.setWindowFocusable(true);
         // 2. Switch the focus to the subwindow.
         const mainWindowId: number = AppStorage.get('mainWindowId') || 0;
         const subWindowId: number = AppStorage.get('subWindowId') || 0;
         await window.shiftAppWindowFocus(mainWindowId, subWindowId);
       } catch (exception) {
         console.error(`Failed to shift focus to subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
       }
     }
   
     async shiftFocusToMainWindow() {
       try {
         let windowStage: window.WindowStage | undefined = AppStorage.get('windowStage');
         if (windowStage == null) {
           console.error('Failed to get the subwindow. Cause: windowStage is undefined');
           return;
         }
         let subWindowList: window.Window[] = await windowStage?.getSubWindow();
         let subWindow: window.Window = subWindowList[0];
         // Set the child window to non-focusable. true means focus is allowed, and false means it is not.
         subWindow?.setWindowFocusable(false);
       } catch (exception) {
         console.error(`Failed to shift focus to main window. Cause code: ${exception.code}, message: ${exception.message}`);
       }
     }
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
         TextInput({ placeholder: 'This is an input component.' })
           .onClick(() => {
             // Tap the input component of the subwindow to focus.
             this.shiftFocusToSubWindow();
           })
         Button('Common Component')
           .onClick(() => {
             // Tap the non-input component of the subwindow to focus the main window.
             this.shiftFocusToMainWindow();
           })
       }
     }
   }
   ```