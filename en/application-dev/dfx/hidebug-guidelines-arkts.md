# Using HiDebug (ArkTS)

HiDebug provides APIs for system debugging, which allow you to obtain the information of static heap memory (native heap) and proportional set size (PSS) occupied by the application process, export VM memory slices, and collect VM CPU profiling data.

## Available APIs

| API                            | Description                                                        |
| ---------------------------------- | ------------------------------------------------------------ |
| hidebug.getNativeHeapSize          | Obtains the size of heap memory (including the allocator metadata) held by a process, which is measured by the memory allocator.|
| hidebug.getNativeHeapAllocatedSize | Obtains the size of the heap memory allocated to a process service, which is measured by the memory allocator.              |
| hidebug.getNativeHeapFreeSize      | Obtains the size of the cache memory held by the memory allocator.                          |
| hidebug.getPss                     | Obtains the size of the physical memory actually used by the application process.                        |
| hidebug.getVss                     | Obtains the virtual set size used by the application process.                              |
| hidebug.getSharedDirty             | Obtains the size of the shared dirty memory of a process.                                  |
| hidebug.getPrivateDirty            | Obtains the size of the private dirty memory of a process.                                  |
| hidebug.getCpuUsage                | Obtains the CPU usage of a process.                                       |
| hidebug.dumpJsHeapData             | Exports the heap data.                                              |
| hidebug.startJsCpuProfiling        | Starts the VM profiling method.                               |
| hidebug.stopJsCpuProfiling         | Stops the VM profiling method.                               |
| hidebug.getAppVMMemoryInfo         | Obtains VM memory information.                                        |
| hidebug.getAppThreadCpuUsage       | Obtains the CPU usage of application threads.                                   |
| hidebug.startAppTraceCapture       | Starts application trace collection.                                         |
| hidebug.stopAppTraceCapture        | Stops application trace collection.                                         |
| hidebug.getAppMemoryLimit          | Obtains the memory limit of the application process.                                  |
| hidebug.getSystemCpuUsage          | Obtains the CPU usage of the system.                                 |
| hidebug.setAppResourceLimit        | Sets the number of FDs, number of threads, JS memory, or native memory limit of the application.  |
| hidebug.getAppNativeMemInfo        | Obtains the memory information of the application process.                                      |
| hidebug.getSystemMemInfo           | Obtains system memory information.                                          |
| hidebug.getVMRuntimeStats          | Obtains all system GC statistics.                                    |
| hidebug.getVMRuntimeStat           | Obtains the specified system GC statistics based on parameters.                          |
| hidebug.getGraphicsMemory          | Obtains the size of the GPU memory asynchronously.                   |
| hidebug.getGraphicsMemorySync      | Obtains the size of the GPU memory synchronously.                   |

For details about how to use HiDebug, see the API Reference (../reference/apis-performance-analysis-kit/js-apis-hidebug.md).

## How to Develop

The following describes how to add a button in the application and click the button to call the hidebug APIs.

1. Create a project, with **Empty Ability** as the template.

2. On the project configuration page, set **Model** to **Stage**.

3. In the **Project** window, click **entry &gt; src &gt; main &gt; ets &gt; pages** to open the **Index.ets** file.

   The following shows how to add **hidebug.getSystemCpuUsage()** to call the hidebug APIs. For details about how to use other APIs, see [API Reference](../reference/apis-performance-analysis-kit/js-apis-hidebug.md).

   ```ts
   import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';
   function testHidebug(event?: ClickEvent) {
     hilog.info(0x0000, "testTag", `getCurrentCpuUsage ${hidebug.getSystemCpuUsage()}`);
   }
   ```

   Add a click event to the **Text** component. The sample code is as follows:

   ```ts
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'

     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testHidebug);// Add a click event.
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

4. Run the project on a real device and click "Hello World" on the app/service.

5. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria to **testTag**.
   Then, the CPU usage logs obtained using **hidebug.getSystemCpuUsage()** are displayed in the window.
   ```Text
	06-25 19:50:27.485 24645-24645/com.example.myapplication I A00000/testTag: getCurrentCpuUsage 0.10164512338425381
   ```

<!--RP1-->
<!--RP1End-->
