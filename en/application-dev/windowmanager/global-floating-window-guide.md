# Global Floating Window Development

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4; @qinliwen0417-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=d92a834fa37fa220b93af036aac498daf001d662 translatedAt=2026-08-11T10:10:25.452Z pushedAt=2026-08-11T10:58:39.732Z -->

## When to Use

The global floating window has the ability to continue displaying in the foreground when the application's main window goes to the background, making it suitable for scenarios such as multi-person video calls and screen sharing.

The global floating window has a higher hierarchy level than all app main windows and sub-windows.

**Comparison between global floating window and float view:**

- Commonality: Both the global floating window and the [float view](../reference/apis-arkui/js-apis-floatView.md) are special auxiliary application windows that can remain displayed in the foreground even after the application's main window and corresponding UIAbility transition to the background.

- Differences:

  - You need to manage the global floating windows and implement UI rendering, with no unified UI or animation effects.

  - The float view is managed by the system, which renders a unified UI with more sophisticated and refined animation effects.

  - The float view supports combined use with the floating ball to implement more complex scenarios.

  - The global floating window is only supported on PC/2-in-1 devices.

  - The float view is supported on phones, tablets, and PC/2-in-1 devices.

- Applicable scenarios:

  - The global floating window is suitable for multi-person video calls and screen sharing scenarios.

  - The float view is suitable for scenarios where application content needs to be continuously displayed in an independent small window or quick operations need to be provided, such as stock tracking applications and mobile live streaming applications.<!--RP1--><!--RP1End-->

  - For other non-specified scenarios, such as video playback, video conferencing, and video calls, the PiP feature is recommended to present video content in a small window.<!--RP2--><!--RP2End-->

## Constraints

The global floating window is currently only supported on PC/2-in-1 devices.

## Prerequisites

To create a window of the **WindowType.TYPE_FLOAT** type, that is, a global floating window, you need to apply for the [ohos.permission.SYSTEM_FLOAT_WINDOW](../security/AccessToken/restricted-permissions.md#ohospermissionsystem_float_window) permission, which is a restricted permission. For details about how to apply, see [Requesting Restricted Permissions](../security/AccessToken/declare-permissions-in-acl.md).

<!--RP3-->
<!--RP3End-->

## How to Develop

1. Create a global floating window.

   Create a window of the global floating window type (**TYPE_FLOAT**) through the [window.createWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowcreatewindow9-1) API.

   <!-- @[floating_window](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   let floatWindowClass: window.Window | undefined = undefined;
   // ...
         // 1. Create a global floating window.
         let context: common.UIAbilityContext | undefined = AppStorage.get<common.UIAbilityContext>('context');
         let config: window.Configuration = {
           name: 'floatWindow', windowType: window.WindowType.TYPE_FLOAT, ctx: context as common.BaseContext
         };
         window.createWindow(config, (err, data) => {
           if (err?.code) {
             console.error('Failed to create the floatWindow. Cause: ' + JSON.stringify(err));
             return;
           }
           floatWindowClass = data;
           console.info('Succeeded in creating the floatWindow. Data: ' + JSON.stringify(data));
           // ...
         });
   ```

2. Set properties and perform other operations on the global floating window.

   After the global floating window is created, you can change its size, position, and other attributes. You can also set properties such as the background color and brightness of the global floating window based on application requirements.

   <!-- @[floating_window_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // 2. After the global floating window is created, set its position, size, and related properties.
   floatWindowClass.moveWindowTo(100, 100, (err) => {
     if (err?.code) {
       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in moving the window.');
     if (!floatWindowClass) {
       console.error('float_windowClass is null');
       return;
     }
     floatWindowClass.resize(600, 900, (err) => {
       if (err?.code) {
         console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in changing the window size.');
     });
   });
   ```

3. Load and display the specific content of the global floating window.

   Use the [setUIContent()](../reference/apis-arkui/arkts-apis-window-Window.md#setuicontent9-1) and [showWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#showwindow9-1) APIs to load and display the specific content of the global floating window.

   <!-- @[floating_window_uiContent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // 3. Load the corresponding target page for the global floating window.
   floatWindowClass.setUIContent('pages/FloatWindow', (err) => {
     if (err?.code) {
       console.error('Failed to load the content. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in loading the content.');
     // Show the global floating window.
     (floatWindowClass as window.Window).showWindow((err) => {
       if (err?.code) {
         console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in showing the window.');
     });
   });
   ```

4. Destroy the global floating window.

   When the global floating window is no longer needed, use the [destroyWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#destroywindow9-1) API to destroy it based on the specific implementation logic.

   <!-- @[destroy_floating_window](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // 4. Destroy the child window. When the child window is no longer needed, use destroy to destroy it based on the specific implementation logic.
   floatWindowClass.destroyWindow((err) => {
     if (err?.code) {
       console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in destroying the window.');
   });
   ```