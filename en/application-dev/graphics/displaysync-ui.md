# Requesting Frame Rates for UI Components

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @wh_qwe-->
<!--Designer: @wh_qwe-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=16524355bdde14dc65076cf14d0f9f697bcf747f translatedAt=2026-08-15T01:50:54.738Z pushedAt=2026-08-15T08:22:12.996Z -->

If you need to draw and update UI content at an independent frame rate, you can use **DisplaySync**. The frame rate for drawing content in an app can be controlled by a **DisplaySync** instance. For details, see [@ohos.graphics.displaySync (Variable Frame Rate)](../reference/apis-arkgraphics2d/js-apis-graphics-displaySync.md).

## How to Develop

The following example changes the font size of a text component at different frame rates to simulate the effect of different UI drawing frame rates.

1. Import the **DisplaySync** module.

   <!-- @[display_sync_by_ui_import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/CustomDrawDisplaySync.ets) -->

   ``` TypeScript
   import { displaySync } from '@kit.ArkGraphics2D';
   ```

2. Define and create a **DisplaySync** instance.

   <!-- @[display_sync_create_object](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/CustomDrawDisplaySync.ets) -->

   ``` TypeScript
   @Entry
   @Component
   struct Index {
     // ...
   
     private backDisplaySyncSlow: displaySync.DisplaySync | undefined = undefined;
     private backDisplaySyncFast: displaySync.DisplaySync | undefined = undefined;
     // ...
   }
   ```

3. Define two **\<Text>** components.

   <!-- @[display_sync_create_text_component](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/CustomDrawDisplaySync.ets) -->

   ``` TypeScript
   @State drawFirstSize: number = 25;
   @State drawSecondSize: number = 25;
   
   // ...
   
   @Builder
   doSomeRenderFirst() {
     Text('30')
       .fontSize(this.drawFirstSize)
   }
   
   @Builder
   doSomeRenderSecond() {
     Text('60')
       .fontSize(this.drawSecondSize)
   }
   ```

4. Set the expected frame rate range and register a subscription function through the **DisplaySync** instance.

   > **NOTE**
   >
   > The subscription function runs in the UI main thread. To avoid adverse impact on the performance, time-consuming operations related to the UI thread should not run in the subscription function.

   <!-- @[display_sync_frame_rate_setting_and_subscription_function_registration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/CustomDrawDisplaySync.ets) -->

   ``` TypeScript
   CreateDisplaySyncSlow() {
     let range: ExpectedFrameRateRange = {
       expected: 30,
       min: 0,
       max: 120
     };
   
     let draw30 = (intervalInfo: displaySync.IntervalInfo) => {
       if (this.isBigger_30) {
         this.drawFirstSize += 1;
         if (this.drawFirstSize > 150) {
           this.isBigger_30 = false;
         }
       } else {
         this.drawFirstSize -= 1;
         if (this.drawFirstSize < 25) {
           this.isBigger_30 = true;
         }
       }
     };
   
     this.backDisplaySyncSlow = displaySync.create();
     this.backDisplaySyncSlow.setExpectedFrameRateRange(range);
     this.backDisplaySyncSlow.on("frame", draw30);
   }
   ```

5. Start the per-frame callback.

   <!-- @[display_sync_start_per_frame_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/CustomDrawDisplaySync.ets) -->

   ``` TypeScript
   Button('Start')
     .id('CustomDrawStart')
     .fontSize(14)
     .fontWeight(500)
     .margin({ bottom: 10, left: 5 })
     .fontColor(Color.White)
     .onClick((): void => {
       if (this.backDisplaySyncSlow == undefined) {
         this.CreateDisplaySyncSlow();
       }
       if (this.backDisplaySyncFast == undefined) {
         this.CreateDisplaySyncFast();
       }
       if (this.backDisplaySyncSlow) {
         this.backDisplaySyncSlow.start();
       }
       if (this.backDisplaySyncFast) {
         this.backDisplaySyncFast.start();
       }
     })
     .width('20%')
     .height(40)
     .shadow(ShadowStyle.OUTER_DEFAULT_LG)
   ```

   > **NOTE**
   >
   > After **start()** is called, the **stop()** API must be performed and the **DisplaySync** instance must be set to null in the **aboutToDisappear** function to avoid memory leaks.

   <!-- @[display_sync_call_stop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/CustomDrawDisplaySync.ets) -->

   ``` TypeScript
   aboutToDisappear() {
     if (this.backDisplaySyncSlow) {
       this.backDisplaySyncSlow.stop();
       this.backDisplaySyncSlow = undefined;
     }
     if (this.backDisplaySyncFast) {
       this.backDisplaySyncFast.stop();
       this.backDisplaySyncFast = undefined;
     }
   }
   ```

6. Stop callback for each frame.

   <!-- @[display_sync_stop_per_frame_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/DisplaySync/entry/src/main/ets/DisplaySync/CustomDrawDisplaySync.ets) -->

   ``` TypeScript
   Button('Stop')
     .id('CustomDrawStop')
     .fontSize(14)
     .fontWeight(500)
     .margin({ bottom: 10, left: 5 })
     .fontColor(Color.White)
     .onClick((): void => {
       if (this.backDisplaySyncSlow) {
         this.backDisplaySyncSlow.stop();
       }
       if (this.backDisplaySyncFast) {
         this.backDisplaySyncFast.stop();
       }
     })
     .width('20%')
     .height(40)
     .shadow(ShadowStyle.OUTER_DEFAULT_LG)
   ```

<!--RP1-->

## Samples

- [DisplaySync (API14)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/DisplaySync)

<!--RP1End-->