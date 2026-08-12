# Dialog Window Development Guide

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4; @qinliwen0417-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=58ff40ad92758153f7b55166a9e6e0a0e9be5d28 translatedAt=2026-07-10T07:15:17.949Z pushedAt=2026-07-13T11:32:26.585Z -->

A dialog window is used to temporarily display critical information or guide users to complete specific actions (such as saving information). It interrupts the user's current operation flow and requires a response before other operations can continue. It is typically used in scenarios where important information needs to be conveyed to the user.

## How to Develop

1. Create a dialog window.

   Create a dialog window (**TYPE_DIALOG**) through the [window.createWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowcreatewindow9-1) API.

   <!-- @[dialog_window](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   let dialogWindowClass: window.Window | undefined = undefined;
   // ...
       // 1. Create a modal window.
       let context1: common.UIAbilityContext | undefined = AppStorage.get<common.UIAbilityContext>('context');
       let config: window.Configuration = {
         name: 'dialogWindow', windowType: window.WindowType.TYPE_DIALOG, ctx: context1 as common.BaseContext
       };
       window.createWindow(config, (err, data) => {
         if (err?.code) {
           console.error('Failed to create the dialogWindow. Cause: ' + JSON.stringify(err));
           return;
         }
         console.info('Succeeded in creating the dialogWindow. Data: ' + JSON.stringify(data));
         dialogWindowClass = data;
         // ...
       });
   ```

2. Set dialog window attributes.

   - After the dialog window is created, you can change its size, position, and other attributes, as well as set properties such as window background color and brightness based on app requirements.

   - Before calling [showWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#showwindow9), it is recommended to set the size and position of the dialog window.

   <!-- @[dialog_window_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   // 2. After the modal window is created, set its position, size, and related attributes.
   dialogWindowClass.moveWindowTo(100, 100, (err) => {
     if (err?.code) {
       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in moving the window.');
     if (!dialogWindowClass) {
       console.error('dialog_windowClass is null');
       return;
     }
     dialogWindowClass.resize(500, 500, (err) => {
       if (err?.code) {
         console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in changing the window size.');
     });
   });
   ```

3. Load and display the specific content of the window.

   Use the [setUIContent()](../reference/apis-arkui/arkts-apis-window-Window.md#setuicontent9) and [showWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#showwindow9) APIs to load and display the specific content of the dialog window.

   <!-- @[dialog_window_uiContent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   // 3. Load the corresponding target page for the modal window.
   dialogWindowClass.setUIContent('pages/DialogWindow', (err) => {
     if (err?.code) {
       console.error('Failed to load the content. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in loading the content.');
     // Display the modal window.
     (dialogWindowClass as window.Window).showWindow((err) => {
       if (err?.code) {
         console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in showing the window.');
     });
   });
   ```

4. Destroy the window.

   When the dialog window is no longer needed, you can use the [destroyWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#destroywindow9) API to destroy it based on your specific implementation logic.

   <!-- @[destroy_dialog_window](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/DialogWindow.ets) --> 

   ``` TypeScript
   // 4. Destroy the subwindow. When the subwindow is no longer needed, you can use destroy to destroy it based on your specific implementation logic.
   dialogWindowClass.destroyWindow((err: BusinessError) => {
     let errCode: number = err.code;
     if (errCode) {
       console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in destroying the window.');
   });
   ```