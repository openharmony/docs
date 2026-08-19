# Subwindow Development

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4; @qinliwen0417-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=58ff40ad92758153f7b55166a9e6e0a0e9be5d28 translatedAt=2026-07-10T07:16:14.296Z pushedAt=2026-07-13T07:55:55.258Z -->

## When to Use

A subwindow is the most basic type of auxiliary window, used to provide auxiliary functions or display additional information.

> **NOTE**
> 
> - In the non-[freeform window](freeform-window-overview.md#freeform-window) state, a subwindow is displayed only within the bounds of the app's main window.
> - In the [freeform window](freeform-window-overview.md#freeform-window) state, a subwindow can be displayed beyond the bounds of the app's main window.

## How to Develop

1. Create an app subwindow using the [createSubWindow()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#createsubwindow9-1) or [createSubWindowWithOptions()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#createsubwindowwithoptions11) API. After creation, the subwindow defaults to [immersive layout](immersive-window-feature.md#immersive-layout).

   Starting from API version 26.0.0, when creating a subwindow using [createSubWindowWithOptions()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#createsubwindowwithoptions11), you can set **zLevelAboveParentLoosened** in [SubWindowOptions](../reference/apis-arkui/arkts-apis-window-i.md#subwindowoptions11) to **true**. The subwindow created in this way is called an independent subwindow.

   In the [freeform window](freeform-window-overview.md#freeform-window) state, an independent subwindow does not follow the main window's foreground/background switching and is only destroyed together with the main window. The independent subwindow and the main window can adjust their z-order by clicking.

   <!-- @[create_subWindow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   let windowStage_: window.WindowStage | undefined = undefined;
   let subWindowClass: window.Window | undefined = undefined;
   // ...
         // Get windowStage.
         windowStage_ = AppStorage.get('windowStage');
         // Create an app subwindow.
         if (windowStage_ == null) {
           console.error('Failed to create the subwindow. Cause: windowStage_ is null');
         } else {
           // 1. Create a subwindow using the createSubWindow API.
           windowStage_.createSubWindow('SubWindow', (err, data) => {
             if (err?.code) {
               console.error('Failed to create the subwindow. Cause: ' + JSON.stringify(err));
             }
             subWindowClass = data;
             if (!subWindowClass) {
               console.error('sub_windowClass is null');
               return;
             }
             console.info('Succeeded in creating the subwindow. Data: ' + JSON.stringify(data));
             // ...
           })
   ```

   <!-- @[create_independent_subWindow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   let independentWindowClass: window.Window | undefined = undefined;
   // ...
       // Obtain windowStage.
       windowStage_ = AppStorage.get('windowStage');
       // 1. Create an independent subwindow.
       // ...
           let options : window.SubWindowOptions = {
             title: 'IndependentSubWindow',
             decorEnabled: true,
             zLevelAboveParentLoosened: true  // For an independent subwindow, zLevelAboveParentLoosened must be set to true.
           };
           let promise = windowStage_.createSubWindowWithOptions('IndependentSubWindow', options);
           promise.then((data: window.Window | undefined) => {
             independentWindowClass = data;
             if (!independentWindowClass) {
               console.error('independent_sub_windowClass is null');
               return;
             }
             console.info(`Succeeded in creating the subwindow. Data: ${JSON.stringify(data)}`);
             // ...
             });
   ```

2. Set subwindow attributes.

   - After the subwindow is created, you can change its size, position, and other attributes, as well as set properties such as the window background color and brightness based on the app's needs.

   - Before calling [showWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#showwindow9-1), it is recommended to set the size and position of the subwindow.

   - If the size of the subwindow is not set, the following behavior occurs after calling [showWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#showwindow9-1):

      - In the [freeform window](freeform-window-overview.md#freeform-window) state, the default subwindow size is the size of the current physical screen.

      - In the non-[freeform window](freeform-window-overview.md#freeform-window) state, the default subwindow size is the size of the main window.

   Take setting the attributes of an independent subwindow as an example. The sample code is as follows:

   <!-- @[independent_subWindow_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   // 2. After the subwindow is created, set its position, size, and related attributes.
   independentWindowClass.moveWindowTo(100, 100, (err) => {
     if (err?.code) {
       console.error('Failed to move the window. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in moving the window.');
     if (!independentWindowClass) {
       console.error('independent_windowClass is null');
       return;
     }
     independentWindowClass.resize(1000, 500, (err) => {
       if (err?.code) {
         console.error('Failed to change the window size. Cause:' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in changing the window size.');
     });
   });
   ```

3. Load and display the specific content of the subwindow.

   Load and display the specific content of the subwindow through the [setUIContent()](../reference/apis-arkui/arkts-apis-window-Window.md#setuicontent9-1) and [showWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#showwindow9-1) APIs.

   Take loading and displaying the specific content of an independent subwindow as an example. The sample code is as follows:

   <!-- @[independent_subWindow_uiContent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   // 3. Load the corresponding target page for the subwindow.
   independentWindowClass.setUIContent('pages/IndependentSubWindow', (err) => {
     if (err?.code) {
       console.error('Failed to load the content. Cause:' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in loading the content.');
     if (!independentWindowClass) {
       console.error('independent_windowClass is null');
       return;
     }
     // Show the subwindow.
     independentWindowClass.showWindow((err) => {
       if (err?.code) {
         console.error('Failed to show the window. Cause: ' + JSON.stringify(err));
         return;
       }
       console.info('Succeeded in showing the window.');
     });
   ```

4. Destroy the subwindow.

   When certain subwindows are no longer needed, you can destroy them using the [destroyWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#destroywindow9-1) API based on the specific implementation logic.

   The following takes destroying an independent subwindow as an example. The sample code is as follows:

   <!-- @[destroy_independent_subWindow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/AuxiliaryWindowSample/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   // 4. Destroy the subwindow. When the subwindow is no longer needed, you can destroy it using destroy based on the specific implementation logic.
   independentWindowClass.destroyWindow((err) => {
     if (err?.code) {
       console.error('Failed to destroy the window. Cause: ' + JSON.stringify(err));
       return;
     }
     console.info('Succeeded in destroying the window.');
   });
   ```