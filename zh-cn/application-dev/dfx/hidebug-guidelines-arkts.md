# HiDebug接口使用示例(ArkTS)

HiDebug ArkTS接口功能相对比较独立，在需要获取调试信息时直接调用即可，具体接口的调用方式请参考[API参考文档](../reference/apis-performance-analysis-kit/js-apis-hidebug.md)中的示例。

## 开发示例

本文以获取系统CPU使用率为例展示如何在工程中调用HiDebug ArkTS接口。

1. 使用DevEco Studio新建一个工程，选择“Empty Ability”。

2. 在Project窗口单击entry > src > main > ets > pages，打开工程中的Index.ets文件并编辑：

   ```
   import { JSON } from '@kit.ArkTS';
   import { hidebug } from '@kit.PerformanceAnalysisKit'
   
   function testHiDebugArk() {  // 按照需要调用的接口实现
     try {
       let ret = hidebug.getSystemCpuUsage();
       console.info(`TestTag getSystemCpuUsage: ${ret}`);
     } catch (err) {
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
             // 添加点击事件
             .onClick(testHiDebugArk);
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

3. 点击运行，在设备上点击“testHiDebugArk”按钮，触发接口调用。

4. 若接口调用存在日志输出，在DevEco Studio的底部，切换到“Log”窗口，即可查看接口调用的相关日志。

   ```
   06-02 16:53:22.538   31077-31077   A03D00/com.exa...ication/JSAPP  com.examp...lication  I     TestTag getSystemCpuUsage: 0.09963547995139732
   ```
