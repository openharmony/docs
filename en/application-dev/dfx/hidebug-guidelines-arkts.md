# Using HiDebug APIs (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--Designer: @kutcherzhou1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

The HiDebug ArkTS APIs are independent. You can call them to obtain debugging information. For details about how to call the APIs, see the examples in [@ohos.hidebug (HiDebug)](../reference/apis-performance-analysis-kit/js-apis-hidebug.md).

## How to Develop

This topic describes how to call the HiDebug ArkTS API to obtain the system CPU usage.

1. Use DevEco Studio to create a project and select **Empty Ability**.

2. In the **Project** window, click **entry** > **src** > **main** > **ets** > **pages** to open and edit the **Index.ets** file.

   ```typescript
   import { hidebug } from '@kit.PerformanceAnalysisKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   function testHiDebugArk () { // Implement the API as required.
     try {
       let ret = hidebug.getSystemCpuUsage();
       console.info(`TestTag getSystemCpuUsage: ${ret}`);
     } catch (error) {
       console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
     } 
   }
   
   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         Column() {
           Button("testHiDebugArk")
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .backgroundColor('#0D9FFB')
             .width('60%')
             .height('5%')
             // Add a click event.
             .onClick(testHiDebugArk);
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

3. Click **Run**, and then click the **testHiDebugArk** button on the device to trigger API calling.

4. If any logs are generated while the API is being called, open the **Log** window at the bottom of DevEco Studio to view them.

   ```Text
   06-02 16:53:22.538   31077-31077   A03D00/com.exa...ication/JSAPP  com.examp...lication  I     TestTag getSystemCpuUsage: 0.09963547995139732
   ```
