# Using HiDebug APIs (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @leiguangyu-->
<!--Designer: @mgce1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=44da34c75e0877dd26e067a23f1dc0303066fdbb translatedAt=2026-07-31T01:29:12.416Z pushedAt=2026-07-31T07:06:14.705Z -->

HiDebug ArkTS APIs are self-contained and can be called directly when debugging information is needed. For details about how to call these APIs, refer to the examples in [@ohos.hidebug](../reference/apis-performance-analysis-kit/js-apis-hidebug.md).

## How to Develop

This topic describes how to call the HiDebug ArkTS API to obtain the system CPU usage.

1. Use DevEco Studio to create a project and select **Empty Ability**.

2. In the **Project** window, click **entry** > **src** > **main** > **ets** > **pages** to open the **Index.ets** file.

   Import the required dependencies.

   <!-- @[TestHidebugArk_Import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';
   ```

   Define the test method.

   <!-- @[TestHidebugArk_Function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   function testHiDebugArk () { // Implement the API as required.
     try {
       hilog.info(0x0000, 'testTag', `getSystemCpuUsage: ${hidebug.getSystemCpuUsage()}`);
     } catch (error) {
       hilog.info(0x0000, 'testTag', `error code: ${(error as BusinessError).code},
         error msg: ${(error as BusinessError).message}`);
     }
   }
   ```

   Add a button to trigger the API call.

   <!-- @[TestHidebugArk_Button](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/HiDebugTool/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   Button('testHiDebugArk')
     .type(ButtonType.Capsule)
     .margin({
       top: 20
     })
     .backgroundColor('#0D9FFB')
     .width('60%')
     .height('5%')
     // Add a click event.
     .onClick(testHiDebugArk);
   ```

3. Click **Run**, and then click the **testHiDebugArk** button on the device to trigger API calling.

4. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria to **testTag** to view related logs.

   ```Text
   10-22 15:46:04.587   19261-19261   A00000/com.sam...gtool/testTag  com.sampl...ebugtool  I     getSystemCpuUsage: 0.2878989952876323
   ```