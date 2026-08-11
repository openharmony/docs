# Integrating the Lyrics Component

<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend@devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=f289f9b7f512c60afced71d0967cd3e528360476 translatedAt=2026-08-10T03:45:58.915Z pushedAt=2026-08-10T06:45:47.943Z -->

Starting from API version 23, the system provides the lyrics component feature. The lyrics component is displayed as a floating window on the system desktop, supporting lyrics content display, component hiding, component locking, and other operations. Apps are not currently supported to customize the component style. This document describes the development steps for app access to the lyrics component.

## How to Develop

1. Call the [isDesktopLyricSupported](../../reference/apis-avsession-kit/arkts-apis-avsession-f.md#avsessionisdesktoplyricsupported23) API to check whether the system/device supports the lyrics component capability. If the callback returns `true`, the lyrics component capability is supported.

2. Create an [AVSession instance](../avsession/avsession-access-scene.md#creating-avsession), and fill in LRC-format lyrics data through [setting metadata information](avsession-access-scene.md#setting-metadata-information), including time tags and corresponding lyrics text. For lyrics data that does not conform to the LRC format, the system may encounter parsing errors, resulting in failure to display the lyrics content.

3. Call the [enableDesktopLyric](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#enabledesktoplyric23) API to enable the lyrics component by passing `true` as the parameter.

4. After the lyrics component is enabled, it is hidden (not displayed) by default. The app can proactively show or hide the lyrics component through the following APIs:

   **Set visibility:** Call the [setDesktopLyricVisible](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setdesktoplyricvisible23) API to set whether the lyrics component is displayed.

   **Query visibility:** Call the [isDesktopLyricVisible](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#isdesktoplyricvisible23) API to query whether the lyrics component is currently displayed.

5. After the lyrics component is enabled, it is in the unlocked state by default. You can use APIs to actively lock or unlock the lyrics component. The specific APIs are as follows:

   **Set lock state:** Call the [setDesktopLyricState](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setdesktoplyricstate23) API to set whether the lyrics window is locked (which restricts operations such as dragging and configuring the lyrics window).

   **Query lock state:** Call the [getDesktopLyricState](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#getdesktoplyricstate23) API to query the current lock state of the lyrics component.

6. The app can listen for changes in the visibility and locked state of the lyrics component through callbacks provided by the system. The specific APIs are as follows:

   **Listen for whether the lyrics component is visible:** Call [onDesktopLyricVisibilityChanged](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#ondesktoplyricvisibilitychanged23). The callback returns the result. The value **true** indicates that the lyrics component is visible, and **false** indicates that it is not visible. To cancel this listener, use the [offDesktopLyricVisibilityChanged](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#offdesktoplyricvisibilitychanged23) API.

   **Listen for whether the lyrics component is locked:** Call [onDesktopLyricStateChanged](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#ondesktoplyricstatechanged23). The callback returns the result. The value **true** indicates that the lyrics component is locked, and **false** indicates that it is not locked. To cancel this listener, use the [offDesktopLyricStateChanged](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#offdesktoplyricstatechanged23) API.

   > **NOTE**
   >
   > Ensure that the AVSession object is not reclaimed by the system or released by the app during background playback. Otherwise, the lyrics component may behave abnormally.

   <!-- @[setAVSessionInformation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AVSessionProvider/entry/src/main/ets/pages/DesktopLyric.ets) -->

   ``` TypeScript
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'hello world';
     // ...
   
     build() {
       Column() {
         // ...
         Text(this.message)
           .onClick(async () => {
             console.info(`DesktopLyric set start`);
             let context = this.getUIContext().getHostContext() as Context;
             // Assume a session has been created. For details about how to create a session, see the previous example.
             let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');
   
             // Whether the system supports the lyrics component.
             let isDesktopLyricSupported: boolean = false;
             try {
               isDesktopLyricSupported = await AVSessionManager.isDesktopLyricSupported();
             } catch (err) {
               console.error(`Failed to get isDesktopLyricSupported. Code: ${err.code}, message: ${err.message}`);
             }
             if (!isDesktopLyricSupported) {
               return;
             }
   
             try {
               // Enable the lyrics component.
               await session.enableDesktopLyric(true);
             } catch (err) {
               console.error(`enableDesktopLyric err. Code: ${err.code}, message: ${err.message}`);
             }
   
             try {
               // Listen for whether the lyrics component is displayed.
               session.onDesktopLyricVisibilityChanged((isVisible: boolean) => {
                 console.info(`onDesktopLyricVisibilityChanged changed: ${isVisible}`)
               });
             } catch (err) {
               console.error(`onDesktopLyricVisibilityChanged err. Code: ${err.code}, message: ${err.message}`);
             }
   
             try {
               // Listen for the locked state of the lyrics component.
               session.onDesktopLyricStateChanged((state) => {
                 console.info(`onDesktopLyricStateChanged changed: ${state.isLocked}`)
               });
             } catch (err) {
               console.error(`onDesktopLyricStateChanged err. Code: ${err.code}, message: ${err.message}`);
             }
   
             try {
               // Show or hide the lyrics component. The lyrics component is hidden by default after being enabled.
               await session.setDesktopLyricVisible(true);
             } catch (err) {
               console.error(`setDesktopLyricVisible err. Code: ${err.code}, message: ${err.message}`);
             }
   
             try {
               // Lock or unlock the lyrics component. After the lyrics component is enabled, it is unlocked by default.
               await session.setDesktopLyricState({isLocked: true});
             } catch (err) {
               console.error(`setDesktopLyricState err. Code: ${err.code}, message: ${err.message}`);
             }
   
             console.info(`DesktopLyric set done`);
           })
       }
       .width('100%')
       .height('100%')
     }
   }
   ```