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
| hidebug.getServiceDump             | Obtains system service information.                                          |
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
| hidebug.isDebugState               | Obtains the debugging state of an application process.                                    |
| hidebug.getGraphicsMemory          | Obtains the size of the GPU memory asynchronously.                   |
| hidebug.getGraphicsMemorySync      | Obtains the size of the GPU memory synchronously.                   |
| hidebug.dumpJsRawHeapData          | Dumps the original heap snapshot of the VM for the calling thread.                 |

For details about how to use HiDebug, see the API Reference (../reference/apis-performance-analysis-kit/js-apis-hidebug.md).

## How to Develop

The following describes how to add a button in the application and click the button to call the hidebug APIs.

1. Create a project, with **Empty Ability** as the template.

2. On the project configuration page, set **Model** to **Stage**.

3. In the **Project** window, click **entry &gt; src &gt; main &gt; ets &gt; pages** to open the **Index.ets** file.

   The following shows how to add **hidebug.getSystemCpuUsage()** to call the hidebug APIs. For details about how to use other APIs, see [API Reference](../reference/apis-performance-analysis-kit/js-apis-hidebug.md).

   ```ts
   import { hidebug } from '@kit.PerformanceAnalysisKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   function testHidebug(event?: ClickEvent) {
     try {
       console.info(`getSystemCpuUsage: ${hidebug.getSystemCpuUsage()}`)
     } catch (error) {
       console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
     }
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
	08-20 11:06:01.891   1948-1948     A03d00/JSAPP                    com.examp...lication  I     getSystemCpuUsage: 0.4722222222222222
   ```

<!--RP1-->
<!--RP1End-->
