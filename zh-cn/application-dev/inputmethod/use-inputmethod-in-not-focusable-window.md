# 不可获焦窗口中输入框与输入法交互指南

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy1984-->
<!--Adviser: @zhang_yixin13-->

## 场景介绍

应用获得焦点是使用输入法的必要条件，开发者需要正确处理焦点以确保输入法的正常工作。

例如，在应用开发中，开发者可以通过[setWindowFocusable](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowfocusable9)，将创建的窗口的可获焦属性设置为false（如悬浮窗、辅助交互窗口等），并希望在该窗口中绘制输入框（如[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)、[TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md)或[自绘输入框](use-inputmethod-in-custom-edit-box.md)）以支持用户输入，即拉起系统键盘进行输入操作。

## 系统限制

当通过[setWindowFocusable](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowfocusable9)将窗口设置为不可获焦时，系统侧会对该窗口施加限制。由于窗口无焦点，输入事件（如按键信息）无法被窗口正确接收和处理，输入内容无法同步到该窗口中的输入框，导致输入框与键盘交互异常。

## 推荐方案

若需要在不可获焦窗口中绘制输入框，并希望能够与键盘正常交互，建议按照以下方式开发（以[TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md)为例）：

1. 在主窗中创建一个子窗，设置其初始为不可获焦窗口。

   可达到效果：点击主窗输入组件，弹出子窗，焦点仍然在主窗的输入框上。

   ```ts
   // Index.ets实现主窗的布局内容
   import { window } from '@kit.ArkUI';
   
   @Entry
   @Component
   struct Index {
     async createSubWindow() {
       try {
         // 1.创建子窗并设置子窗id
         let windowStage: window.WindowStage | undefined = AppStorage.get('windowStage');
         if (windowStage == null) {
           console.error('Failed to get windowStage');
           return;
         }
         let options: window.SubWindowOptions = { title: 'title', decorEnabled: true };
         let subWindow = await windowStage?.createSubWindowWithOptions('mySubWindow', options);
         const subWindowId: number | undefined = subWindow?.getWindowProperties().id;
         AppStorage.setOrCreate('subWindowId', subWindowId);
         // 2.设置子窗为不可获焦
         subWindow?.resize(500, 500);
         subWindow?.setUIContent("pages/SubWindowIndex");
         subWindow?.setWindowFocusable(false);
         // 3.显示子窗
         subWindow?.showWindow();
       } catch (exception) {
         console.error(`Failed to create the subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
       }
     }
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
         TextInput({ placeholder: '点击创建并显示子窗' })
           .onClick(() => {
             this.createSubWindow();
           })
       }
     }
   }
   ```

2. 当用户点击子窗中的输入框组件时，可以先通过[setWindowFocusable](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowfocusable9)将子窗设置为可获焦，然后通过[shiftAppWindowFocus](../reference/apis-arkui/arkts-apis-window-f.md#windowshiftappwindowfocus11)将焦点窗口从主窗切换为子窗，即可在子窗的输入框中正常使用输入法。

   ```ts
   // SubWindowIndex.ets实现子窗的布局内容
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
         // 1.将子窗口设置为可获焦
         subWindow?.setWindowFocusable(true);
         // 2.将焦点切换到子窗口
         const mainWindowId: number = AppStorage.get('mainWindowId') || 0;
         const subWindowId: number = AppStorage.get('subWindowId') || 0;
         await window.shiftAppWindowFocus(mainWindowId, subWindowId);
       } catch (exception) {
         console.error(`Failed to shift focus to subWindow. Cause code: ${exception.code}, message: ${exception.message}`);
       }
     }
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
         TextInput({ placeholder: '这是一个输入组件' })
           .onClick(() => {
             // 用户点击子窗的输入组件，切换焦点至子窗
             this.shiftFocusToSubWindow();
           })
       }
     }
   }
   ```

3. 当用户重新点击子窗中的非输入框组件时，可以通过[setWindowFocusable](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowfocusable9)将子窗重新设置为不可获焦，焦点窗口即可恢复至主窗。

   ```ts
   // SubWindowIndex.ets实现子窗的布局内容
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
         // 1.将子窗口设置为可获焦
         subWindow?.setWindowFocusable(true);
         // 2.将焦点切换到子窗口
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
         // 将子窗口设置为不可获焦
         subWindow?.setWindowFocusable(false);
       } catch (exception) {
         console.error(`Failed to shift focus to main window. Cause code: ${exception.code}, message: ${exception.message}`);
       }
     }
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
         TextInput({ placeholder: '这是一个输入组件' })
           .onClick(() => {
             // 点击子窗输入组件时，切换焦点至子窗口
             this.shiftFocusToSubWindow();
           })
         Button('这是一个普通组件')
           .onClick(() => {
             // 点击子窗非输入组件时，可切换焦点回主窗口
             this.shiftFocusToMainWindow();
           })
       }
     }
   }
   ```
