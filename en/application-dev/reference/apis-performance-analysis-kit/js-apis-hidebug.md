# @ohos.hidebug (HiDebug)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

This module provides multiple methods for debugging and profiling applications. With these methods, you can obtain memory, CPU, GPU, and GC data, collect process trace and profiler data, and dump VM heap snapshots. Since most APIs of this module are both performance-consuming and time-consuming, and are defined based on the HiDebug module, you are advised to use these APIs only during the application debugging and profiling phases. If the APIs are required in other scenarios, evaluate the impact of the APIs on application performance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
```

## hidebug.getNativeHeapSize

getNativeHeapSize(): bigint

Obtains the total number of bytes occupied by the total space (**uordblks** + **fordblks**, which are obtained from **mallinfo**) held by a process, which is measured by the memory allocator.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                                        |
| ------ |--------------------------------------------|
| bigint | Size of the memory occupied by the total space held by the process, in bytes.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapSize: bigint = hidebug.getNativeHeapSize();
```

## hidebug.getNativeHeapAllocatedSize

getNativeHeapAllocatedSize(): bigint

Obtains the total number of bytes occupied by the total allocated space (**uordblks**, which is obtained from **mallinfo**) held by a process, which is measured by the memory allocator.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                             |
| ------ | --------------------------------- |
| bigint | Size of the memory occupied by the total allocated space held by the process, in bytes.|


**Example**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapAllocatedSize: bigint = hidebug.getNativeHeapAllocatedSize();
```

## hidebug.getNativeHeapFreeSize

getNativeHeapFreeSize(): bigint

Obtains the total number of bytes occupied by the total free space (**fordblks**, which is obtained from **mallinfo**) held by a process, which is measured by the memory allocator.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                           |
| ------ | ----------------------------- |
| bigint | Size of the memory occupied by the total free space held by the process, in bytes.|

**Example**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapFreeSize: bigint = hidebug.getNativeHeapFreeSize();
```

## hidebug.getPss

getPss(): bigint

Obtains the size of the physical memory actually used by the application process. This API is implemented by summing up the values of **Pss** and **SwapPss** in the **/proc/{pid}/smaps_rollup** node.

> **NOTE**
> 
> Reading the **/proc/{pid}/smaps_rollup** node is time-consuming. Therefore, you are advised not to use this API in the main thread. You can use this API in the asynchronous thread started by calling [@ohos.taskpool](../apis-arkts/js-apis-taskpool.md) or [@ohos.worker](../apis-arkts/js-apis-worker.md) to avoid frame freezing.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| bigint | Size of the physical memory actually used by the application process, in KB.|

**Example**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let pss: bigint = hidebug.getPss();
```

## hidebug.getVss<sup>11+</sup>

getVss(): bigint

Obtains the virtual set size used by the application process. This API is implemented by multiplying the value of **size** (number of memory pages) in the **/proc/{pid}/statm** node by the page size (4 KB per page).

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                                    |
| ------ | ---------------------------------------- |
| bigint | Virtual set size used by the application process, in KB.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let vss: bigint = hidebug.getVss();
```

## hidebug.getSharedDirty

getSharedDirty(): bigint

Obtains the size of the shared dirty memory of a process. This API is implemented by reading the value of **Shared_Dirty** in the **/proc/{pid}/smaps_rollup** node.

> **NOTE**
> 
> Reading the **/proc/{pid}/smaps_rollup** node is time-consuming. Therefore, you are advised not to use this API in the main thread. You can use this API in the asynchronous thread started by calling [@ohos.taskpool](../apis-arkts/js-apis-taskpool.md) or [@ohos.worker](../apis-arkts/js-apis-worker.md) to avoid frame freezing.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| bigint | Size of the shared dirty memory of the process, in KB.|


**Example**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let sharedDirty: bigint = hidebug.getSharedDirty();
```

## hidebug.getPrivateDirty<sup>9+</sup>

getPrivateDirty(): bigint

Obtains the size of the private dirty memory of a process. This API is implemented by reading the value of **Private_Dirty** in the **/proc/{pid}/smaps_rollup** node.

> **NOTE**
>
> Reading the **/proc/{pid}/smaps_rollup** node is time-consuming. Therefore, you are advised not to use this API in the main thread. You can use this API in the asynchronous thread started by calling [@ohos.taskpool](../apis-arkts/js-apis-taskpool.md) or [@ohos.worker](../apis-arkts/js-apis-worker.md) to avoid frame freezing.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| bigint | Size of the private dirty memory of the process, in KB.|

**Example**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let privateDirty: bigint = hidebug.getPrivateDirty();
```

## hidebug.getCpuUsage<sup>9+</sup>

getCpuUsage(): number

Obtains the CPU usage of a process.

For example, if the CPU usage is **50%**, **0.5** is returned.

> **NOTE**
>
> This API involves cross-process communication and takes a long time. To avoid performance problems, you are advised not to call this API in the main thread.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | CPU usage of the process.|


**Example**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let cpuUsage: number = hidebug.getCpuUsage();
```

## hidebug.getServiceDump<sup>9+</sup>

getServiceDump(serviceid: number, fd: number, args: Array\<string>) : void

Obtains system service information.

**Required permissions**: ohos.permission.DUMP (available only for system applications)

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                        |
| -------- | ------ | ---- |----------------------------|
| serviceid | number | Yes  | Service ID used to obtain system service information.|
| fd | number | Yes  | File descriptor to which data is written by the API.        |
| args | Array&lt;string&gt; | Yes  | Parameter list of the **Dump** API of the system service.          |

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed,Possible causes:1.the parameter type error 2.the args parameter is not string array.  |
| 11400101 | ServiceId invalid. The system ability does not exist.                                           |

**Example**

<!--code_no_check-->
```ts
import { fileIo } from '@kit.CoreFileKit';
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let fileFd = -1;
try {
  // Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
  let path: string = this.getUIContext().getHostContext()!.filesDir + "/serviceInfo.txt";
  console.info("output path: " + path);
  fileFd = fileIo.openSync(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE).fd;
  let serviceId: number = 10;
  let args: Array<string> = new Array("allInfo");
  hidebug.getServiceDump(serviceId, fileFd, args);
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}

if (fileFd >= 0) {
  fileIo.closeSync(fileFd);
}
```

## hidebug.startJsCpuProfiling<sup>9+</sup>

startJsCpuProfiling(filename: string) : void

Starts the VM profiling method. **startJsCpuProfiling(filename: string)** and **stopJsCpuProfiling()** are called in pairs. **startJsCpuProfiling(filename: string)** always occurs before **stopJsCpuProfiling()**. You are advised not to call either of these methods repeatedly. Otherwise, an exception may occur.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                              |
| -------- | ------ | ---- |--------------------------------------------------|
| filename | string | Yes  | Custom file name of the sampling data. The .json file is generated in the **files** directory of the application based on the specified file name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed,Parameter type error.                        |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  hidebug.startJsCpuProfiling("cpu_profiling");
  // ...
  hidebug.stopJsCpuProfiling();
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.stopJsCpuProfiling<sup>9+</sup>

stopJsCpuProfiling() : void

Stops the VM profiling method. **stopJsCpuProfiling()** and **startJsCpuProfiling(filename: string)** are called in pairs. **startJsCpuProfiling()** always occurs before **stopJsCpuProfiling()**. You are advised not to call either of these methods repeatedly. Otherwise, an exception may occur.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  hidebug.startJsCpuProfiling("cpu_profiling");
  // ...
  hidebug.stopJsCpuProfiling();
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.dumpJsHeapData<sup>9+</sup>

dumpJsHeapData(filename: string) : void

Exports the heap data.

> **NOTE**
>
> Exporting the VM heap is time-consuming, and this API is a synchronous API. Therefore, you are advised not to call this API in the release version. Otherwise, the application screen may freeze, affecting user experience.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                           |
| -------- | ------ | ---- | ----------------------------------------------- |
| filename | string | Yes  | Custom file name of the sampling data. The .heapsnapshot file is generated in the **files** directory of the application based on the specified file name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed, Parameter type error.                      |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  hidebug.dumpJsHeapData("heapData");
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.startProfiling<sup>(deprecated)</sup>

startProfiling(filename: string) : void

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [hidebug.startJsCpuProfiling](#hidebugstartjscpuprofiling9).

Starts the VM profiling method. **startProfiling(filename: string)** and **stopProfiling()** are called in pairs. **startProfiling(filename: string)** always occurs before **stopProfiling()**. You are advised not to call either of these methods repeatedly. Otherwise, an exception may occur.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                            |
| -------- | ------ | ---- | ------------------------------------------------ |
| filename | string | Yes  | Custom file name of the sampling data. The .json file is generated in the **files** directory of the application based on the specified file name.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.startProfiling("cpuprofiler-20220216");
// code block
// ...
// code block
hidebug.stopProfiling();
```

## hidebug.stopProfiling<sup>(deprecated)</sup>

stopProfiling() : void

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [hidebug.stopJsCpuProfiling](#hidebugstopjscpuprofiling9).

Stops the VM profiling method. **stopProfiling()** and **startProfiling(filename: string)** are called in pairs. **startProfiling(filename: string)** always occurs before **stopProfiling()**. You are advised not to call either of these methods repeatedly. Otherwise, an exception may occur.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.startProfiling("cpuprofiler-20220216");
// code block
// ...
// code block
hidebug.stopProfiling();
```

## hidebug.dumpHeapData<sup>(deprecated)</sup>

dumpHeapData(filename: string) : void

> **NOTE**
> 
> This API is deprecated since API version 9. You are advised to use [hidebug.dumpJsHeapData](#hidebugdumpjsheapdata9).

Exports the VM heap data and generates a **filename.heapsnapshot** file.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                     |
| -------- | ------ | ---- |---------------------------------------------------------|
| filename | string | Yes  | User-defined heap file name. The .heapsnapshot file is generated in the **files** directory of the application based on the specified file name.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.dumpHeapData("heap-20220216");
```

## hidebug.getAppVMMemoryInfo<sup>12+</sup>

getAppVMMemoryInfo(): VMMemoryInfo

Obtains VM memory information.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type        | Description                                   |
| -------------| --------------------------------------- |
| [VMMemoryInfo](#vmmemoryinfo12) | VM memory information.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let vmMemory: hidebug.VMMemoryInfo = hidebug.getAppVMMemoryInfo();
console.info(`totalHeap = ${vmMemory.totalHeap}, heapUsed = ${vmMemory.heapUsed},` +
  `allArraySize = ${vmMemory.allArraySize}` );
```

## hidebug.getAppThreadCpuUsage<sup>12+</sup>

getAppThreadCpuUsage(): ThreadCpuUsage[]

Obtains the CPU usage of application threads.

> **NOTE**
>
> This API involves cross-process communication and takes a long time. To avoid performance problems, you are advised not to call this API in the main thread.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type            | Description                                                       |
| -----------------| ------------------------------------------------------------|
| [ThreadCpuUsage](#threadcpuusage12)[] | CPU usage of all threads of the current application process.|



**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let appThreadCpuUsage: hidebug.ThreadCpuUsage[] = hidebug.getAppThreadCpuUsage();
for (let i = 0; i < appThreadCpuUsage.length; i++) {
  console.info(`threadId=${appThreadCpuUsage[i].threadId}, cpuUsage=${appThreadCpuUsage[i].cpuUsage}`);
}
```

## hidebug.startAppTraceCapture<sup>12+</sup>

startAppTraceCapture(tags: number[], flag: TraceFlag, limitSize: number) : string

Starts automatic trace collection in a specified scope. This API is a supplement to the [HiTrace](../../dfx/hitrace.md) module. The performance consumption during trace collection increases with the collection scope. Therefore, before using this API, you are advised to run the **hitrace** command to capture trace logs and select the key scope of trace collection to improve the API performance.

**startAppTraceCapture()** and [stopAppTraceCapture()](#hidebugstopapptracecapture12) must be called in pairs. Repeat calling of **startAppTraceCapture()** will cause exceptions. Trace collection consumes a lot of performance resources. Therefore, call **stopAppTraceCapture()** immediately after trace collection is complete.

When an application calls **startAppTraceCapture()** to collect trace data and the size of the data exceeds the value of **limitSize**, the system automatically calls **stopAppTraceCapture()** to stop trace collection. Therefore, if **limitSize** is set improperly, the generated trace data is insufficient for fault analysis. Therefore, you need to evaluate the value of **limitSize** as required.

Evaluation method: limitSize = Expected trace collection duration x Unit trace traffic.

Expected trace collection duration: You can determine the duration based on the fault scenario. The unit is second.

Unit trace traffic: The size of trace data generated by an application per second. The recommended value is 300 KB/s. You are advised to use the actual value of your application. The unit is KB/s.

To obtain the unit trace traffic of an application, you can call **startAppTraceCapture()** with **limitSize** set to the maximum value 500 MB. After **N** seconds, call **stopAppTraceCapture()** to stop the collection and check the size **S** (KB) of the trace data. The unit trace traffic is **S**/**N** (KB/s).

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type    | Mandatory| Description                                |
| -------- | ------   | ---- |------------------------------------|
| tags     | number[] | Yes  | Scope for trace collection. For details, see [tags](#hidebugtags12).  |
| flag     | TraceFlag| Yes  | For details, see [TraceFlag](#traceflag12).       |
| limitSize| number   | Yes  | Limit on the trace file size, in bytes. The maximum size of a single file is 500 MB.|

**Return value**

| Type            | Description           |
| -----------------|---------------|
| string           | Path of the trace file.|

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small 2.The parameter is not within the enumeration type 3.The parameter type error or parameter order error. |
| 11400102 | Capture trace already enabled.                                         |
| 11400103 | No write permission on the file.                                |
| 11400104 | Abnormal trace status.                                 |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tags: number[] = [hidebug.tags.ABILITY_MANAGER, hidebug.tags.ARKUI];
let flag: hidebug.TraceFlag = hidebug.TraceFlag.MAIN_THREAD;
let limitSize: number = 1024 * 1024;

try {
  let fileName: string = hidebug.startAppTraceCapture(tags, flag, limitSize);
  // code block
  // ...
  // code block
  hidebug.stopAppTraceCapture();
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.stopAppTraceCapture<sup>12+</sup>

stopAppTraceCapture() : void

Stops application trace collection. Use [startAppTraceCapture()](#hidebugstartapptracecapture12) to start collection before calling this API. If this API is called before trace collection or it is repeatedly called, an exception will occur.

If **startAppTraceCapture ()** is called without a properly specified **limitSize**, the size of the generated trace may exceed the **limitSize** value, causing the system to automatically call **stopAppTraceCapture()**. In this case, if **stopAppTraceCapture()** is called again, an error code 11400105 will be displayed.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 11400104 | The status of the trace is abnormal.                                |
| 11400105 | No capture trace running.                                       |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tags: number[] = [hidebug.tags.ABILITY_MANAGER, hidebug.tags.ARKUI];
let flag: hidebug.TraceFlag = hidebug.TraceFlag.MAIN_THREAD;
let limitSize: number = 1024 * 1024;
try {
  let fileName: string = hidebug.startAppTraceCapture(tags, flag, limitSize);
  // code block
  // ...
  // code block
  hidebug.stopAppTraceCapture();
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.getAppMemoryLimit<sup>12+</sup>

getAppMemoryLimit() : MemoryLimit

Obtains the memory limit of an application process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type | Description                     |
| ------ | -------------------------- |
| [MemoryLimit](#memorylimit12) | Memory limit of the application process.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let appMemoryLimit:hidebug.MemoryLimit = hidebug.getAppMemoryLimit();
```

## hidebug.getSystemCpuUsage<sup>12+</sup>

getSystemCpuUsage() : number

Obtains the CPU usage of the system.

For example, if the CPU usage of system resources is **50%**, **0.5** is returned.

> **NOTE**
>
> This API involves cross-process communication and takes a long time. To avoid performance problems, you are advised not to call this API in the main thread.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type    | Description         |
|--------|-------------|
| number | CPU usage of the system.|

**Error codes**

For details about the error codes, see [HiDebug CPU Usage Error Codes](errorcode-hiviewdfx-hidebug-cpuusage.md).

| ID| Error Message                                           |
| ------- |-------------------------------------------------|
| 11400104 | The status of the system CPU usage is abnormal. |

**Example**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  console.info(`getSystemCpuUsage: ${hidebug.getSystemCpuUsage()}`)
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.setAppResourceLimit<sup>12+</sup>

setAppResourceLimit(type: string, value: number, enableDebugLog: boolean) : void

Sets the number of FDs, number of threads, JS memory, or native memory limit of the application.

This API is used to construct a memory leak. For details, see [Subscribing to Resource Leak Events (ArkTS)](../../dfx/hiappevent-watcher-resourceleak-events-arkts.md) and [Subscribing to Resource Leak Events (C/C++)](../../dfx/hiappevent-watcher-resourceleak-events-ndk.md).

> **NOTE**
>
> This API is valid only when the **Developer options** is enabled.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                                                                                                                                     |
| -------- | ------ | ---- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| type | string |  Yes | Types of leak resources:<br>- pss_memory (native memory)<br>- js_heap (JavaScript heap memory)<br>- fd (file descriptor)<br>- thread (thread)                                                                           |
| value | number |  Yes | Value range of the maximum values of the leak resource types:<br>- pss_memory: **[1024, 4 x 1024 x 1024]** (Unit: KB)<br>- js_heap: **[85, 95]** (85% to 95% of the upper size limit of the JS heap memory)<br>- fd: **[10, 10000]**<br>- thread: **[1, 1000]**|
| enableDebugLog | boolean |  Yes | Whether to enable external debugging logs. Enable external debugging logs only in the grayscale version (test version released to a small number of users before the official version is released). Collecting debugging logs occupies a large number of CPU and memory resources, which may cause application smoothness problems.<br>The value **true** means to enable external debugging logs, and false means the opposite.<br>                                     |

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small 2.The parameter is not in the specified type 3.The parameter type error or parameter order error.  |
| 11400104 | Set limit failed due to remote exception. |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let type: string = 'js_heap';
let value: number = 85;
let enableDebugLog: boolean = false;
try {
  hidebug.setAppResourceLimit(type, value, enableDebugLog);
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.getAppNativeMemInfo<sup>12+</sup>

getAppNativeMemInfo(): NativeMemInfo

Obtains the memory information of the application process. This API is implemented by reading data from the **/proc/{pid}/smaps_rollup and /proc/{pid}/statm** node.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

> **NOTE**
>
> Reading the **/proc/{pid}/smaps_rollup** node takes a long time. You are advised to use the asynchronous API [hidebug.getAppNativeMemInfoAsync](#hidebuggetappnativememinfoasync20) to avoid frame loss or frame freezing.

**Return value**

| Type | Description                     |
| ------ | -------------------------- |
| [NativeMemInfo](#nativememinfo12) | Memory information of the application process.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeMemInfo: hidebug.NativeMemInfo = hidebug.getAppNativeMemInfo();
console.info(`pss: ${nativeMemInfo.pss}, vss: ${nativeMemInfo.vss}, rss: ${nativeMemInfo.rss}, ` +
  `sharedDirty: ${nativeMemInfo.sharedDirty}, privateDirty: ${nativeMemInfo.privateDirty}, ` +
  `sharedClean: ${nativeMemInfo.sharedClean}, privateClean: ${nativeMemInfo.privateClean}`);
```

## hidebug.getAppNativeMemInfoAsync<sup>20+</sup>

getAppNativeMemInfoAsync(): Promise&lt;NativeMemInfo&gt;

Obtains the memory information of an application process in asynchronous mode. This API is implemented by reading data from the **/proc/{pid}/smaps_rollup and /proc/{pid}/statm** node.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type                                              | Description                     |
|--------------------------------------------------| -------------------------- |
| Promise&lt;[NativeMemInfo](#nativememinfo12)&gt; | Promise used to return the application process memory information.|

**Example**

```ts
hidebug.getAppNativeMemInfoAsync().then((nativeMemInfo: hidebug.NativeMemInfo)=>{
  console.info(`pss: ${nativeMemInfo.pss}, vss: ${nativeMemInfo.vss}, rss: ${nativeMemInfo.rss}, ` +
    `sharedDirty: ${nativeMemInfo.sharedDirty}, privateDirty: ${nativeMemInfo.privateDirty}, ` +
    `sharedClean: ${nativeMemInfo.sharedClean}, privateClean: ${nativeMemInfo.privateClean}`);
});
```

## hidebug.getAppNativeMemInfoWithCache<sup>20+</sup>

getAppNativeMemInfoWithCache(forceRefresh?: boolean): NativeMemInfo

Obtains the memory information of the application process. This API uses the cache mechanism and has higher performance than the **getAppNativeMemInfo** API. The cache is valid for 5 minutes.

> **NOTE**
>
> Reading **/proc/{pid}/smaps_rollup** is time-consuming. Therefore, you are advised not to use this API in the main thread. You can use @ohos.taskpool or @ohos.worker to enable asynchronous threads to avoid application freezing.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name                    | Type     | Mandatory| Description                                                                                                    |
|-------------------------|---------|----|--------------------------------------------------------------------------------------------------------|
| forceRefresh         | boolean | No | Whether to ignore the cache validity and forcibly update the cache value. The default value is **false**.<br>The value **true** means to directly obtain the current memory data and update the cache value.<br>The value **false** means to directly return the cache value if the cache is valid and obtain the current memory data and update the cache value if the cache is invalid.|

**Return value**

| Type | Description                     |
| ------ | -------------------------- |
| [NativeMemInfo](#nativememinfo12) | Memory information of the application process.|

**Example**

```ts
let nativeMemInfo: hidebug.NativeMemInfo = hidebug.getAppNativeMemInfoWithCache();
console.info(`pss: ${nativeMemInfo.pss}, vss: ${nativeMemInfo.vss}, rss: ${nativeMemInfo.rss}, ` +
  `sharedDirty: ${nativeMemInfo.sharedDirty}, privateDirty: ${nativeMemInfo.privateDirty}, ` +
  `sharedClean: ${nativeMemInfo.sharedClean}, privateClean: ${nativeMemInfo.privateClean}`);
```

## hidebug.getSystemMemInfo<sup>12+</sup>

getSystemMemInfo(): SystemMemInfo

Obtains system memory information. This API is implemented by reading data from the **/proc/meminfo** node.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type | Description                     |
| ------ | -------------------------- |
| [SystemMemInfo](#systemmeminfo12) | System memory information.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let systemMemInfo: hidebug.SystemMemInfo = hidebug.getSystemMemInfo();

console.info(`totalMem: ${systemMemInfo.totalMem}, freeMem: ${systemMemInfo.freeMem}, ` +
  `availableMem: ${systemMemInfo.availableMem}`);
```

## hidebug.getVMRuntimeStats<sup>12+</sup>

getVMRuntimeStats(): GcStats

Obtains the system [GC](../../arkts-utils/gc-introduction.md) statistics.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type                   | Description      |
|-----------------------|----------|
| [GcStats](#gcstats12) | System GC statistics.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let vMRuntimeStats: hidebug.GcStats = hidebug.getVMRuntimeStats();
console.info(`gc-count: ${vMRuntimeStats['ark.gc.gc-count']}`);
console.info(`gc-time: ${vMRuntimeStats['ark.gc.gc-time']}`);
console.info(`gc-bytes-allocated: ${vMRuntimeStats['ark.gc.gc-bytes-allocated']}`);
console.info(`gc-bytes-freed: ${vMRuntimeStats['ark.gc.gc-bytes-freed']}`);
console.info(`fullgc-longtime-count: ${vMRuntimeStats['ark.gc.fullgc-longtime-count']}`);
```

## hidebug.getVMRuntimeStat<sup>12+</sup>

getVMRuntimeStat(item: string): number

Obtains the specified system [GC](../../arkts-utils/gc-introduction.md) statistics based on parameters.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description         |
| -------- | ------ | ---- |-------------|
| item | string | Yes  | Item of the GC statistics to be obtained.|

**Return value**

| Type    | Description                       |
|--------|---------------------------|
| number | System GC statistics returned based on the input parameters.|

| Input Parameter                        | Return Value Description         |
|------------------------------|----------------|
| ark.gc.gc-count | Count of GC of the calling thread.    |
| ark.gc.gc-time | GC time triggered by the calling thread, in milliseconds.|
| ark.gc.gc-bytes-allocated | Memory size allocated to the Ark VM of the calling thread, in bytes.|
| ark.gc.gc-bytes-freed | Memory freed by the GC of the calling thread, in bytes.|
| ark.gc.fullgc-longtime-count | Count of long fullGC of the calling thread.|

**Error codes**

| ID| Error Message                                                                                                      |
| ------- |------------------------------------------------------------------------------------------------------------|
| 401 | Possible causes:1. Invalid parameter, a string parameter required. 2. Invalid parameter, unknown property. |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  console.info(`gc-count: ${hidebug.getVMRuntimeStat('ark.gc.gc-count')}`);
  console.info(`gc-time: ${hidebug.getVMRuntimeStat('ark.gc.gc-time')}`);
  console.info(`gc-bytes-allocated: ${hidebug.getVMRuntimeStat('ark.gc.gc-bytes-allocated')}`);
  console.info(`gc-bytes-freed: ${hidebug.getVMRuntimeStat('ark.gc.gc-bytes-freed')}`);
  console.info(`fullgc-longtime-count: ${hidebug.getVMRuntimeStat('ark.gc.fullgc-longtime-count')}`);
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## MemoryLimit<sup>12+</sup>

Defines the memory limit of the application process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name     | Type  | Read Only| Optional| Description        |
| --------- | ------ | --|----| ------------ |
| rssLimit    | bigint |  No | No | Limit on the resident set size, in KB.    |
| vssLimit  | bigint |  No | No | Limit on the virtual memory size, in KB.      |
| vmHeapLimit | bigint |  No | No | Limit on the JS VM heap size of the calling thread, in KB.|
| vmTotalHeapSize | bigint |  No | No | Size limit of the JS heap memory of the process, in KB. |

## VMMemoryInfo<sup>12+</sup>

Describes the VM memory information.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name              | Type   | Read Only| Optional| Description                               |
| -------------------| ------- | ---|----| ---------------------------------- |
| totalHeap          | bigint  | No | No | Total heap size of the current VM, in KB.    |
| heapUsed           | bigint  | No | No | Heap size used by the current VM, in KB.   |
| allArraySize       | bigint  | No | No | Size of all array objects of the current VM, in KB.|

## ThreadCpuUsage<sup>12+</sup>

Describes the CPU usage of a thread.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name              | Type   | Read Only| Optional| Description                               |
| -------------------| ------- |----|----| ----------------------------------- |
| threadId           | number  | No | No | Thread ID.     |
| cpuUsage           | number  | No | No | CPU usage of the thread.|

## hidebug.tags<sup>12+</sup>

Enumerates the tags used in trace collection. You can use the [HiTrace](../../dfx/hitrace.md) commands to capture the trace data of a specified tag.

> **NOTE**
>
> The following tag values are defined by the system and may change with the version upgrade. To avoid compatibility issues after the upgrade, use the tag names instead of the tag values in application development.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name                    | Type   | Read Only | Description                                        |
| -------------------------| ------- |-----|--------------------------------------------|
| ABILITY_MANAGER          | number  | Yes| Capability management. The corresponding HiTrace command is **tagName:ability**.                 |
| ARKUI                    | number  | Yes| ArkUI development framework. The corresponding HiTrace command is **tagName:ace**.               |
| ARK                      | number  | Yes| JSVM VM. The corresponding HiTrace command is **tagName:ark**.                 |
| BLUETOOTH                | number  | Yes| Bluetooth. The corresponding HiTrace command is **tagName:bluetooth**.                |
| COMMON_LIBRARY           | number  | Yes| Common library subsystem. The corresponding HiTrace command is **tagName:commonlibrary**.        |
| DISTRIBUTED_HARDWARE_DEVICE_MANAGER | number  | Yes| Distributed hardware device management. The corresponding HiTrace command is **tagName:devicemanager**.     |
| DISTRIBUTED_AUDIO        | number  | Yes| Distributed audio. The corresponding HiTrace command is **tagName:daudio**.                |
| DISTRIBUTED_CAMERA       | number  | Yes| Distributed camera. The corresponding HiTrace command is **tagName:dcamera**.               |
| DISTRIBUTED_DATA         | number  | Yes| Distributed data management. The corresponding HiTrace command is **tagName:distributeddatamgr**.|
| DISTRIBUTED_HARDWARE_FRAMEWORK | number  | Yes| Distributed hardware framework. The corresponding HiTrace command is **tagName:dhfwk**.                |
| DISTRIBUTED_INPUT        | number  | Yes| Distributed input. The corresponding HiTrace command is **tagName:dinput**.                |
| DISTRIBUTED_SCREEN       | number  | Yes| Distributed screen. The corresponding HiTrace command is **tagName:dscreen**.               |
| DISTRIBUTED_SCHEDULER    | number  | Yes| Distributed scheduler. The corresponding HiTrace command is **tagName:dsched**.               |
| FFRT                     | number  | Yes| FFRT task. The corresponding HiTrace command is **tagName:ffrt**.                 |
| FILE_MANAGEMENT          | number  | Yes| File management system. The corresponding HiTrace command is **tagName:filemanagement**.       |
| GLOBAL_RESOURCE_MANAGER  | number  | Yes| Global resource management. The corresponding HiTrace command is **tagName:gresource**.            |
| GRAPHICS                 | number  | Yes| Graphics module. The corresponding HiTrace command is **tagName:graphic**.                |
| HDF                      | number  | Yes| HDF subsystem. The corresponding HiTrace command is **tagName:hdf**.                  |
| MISC                     | number  | Yes| MISC module. The corresponding HiTrace command is **tagName:misc**.                 |
| MULTIMODAL_INPUT         | number  | Yes| Multi-modal input module. The corresponding HiTrace command is **tagName:multimodalinput**.     |
| NET                      | number  | Yes| Network. The corresponding HiTrace command is **tagName:net**.                      |
| NOTIFICATION             | number  | Yes| Notification module. The corresponding HiTrace command is **tagName:notification**.           |
| NWEB                     | number  | Yes| Nweb. The corresponding HiTrace command is **tagName:nweb**.                   |
| OHOS                     | number  | Yes| OHOS. The corresponding HiTrace command is **tagName:ohos**.                 |
| POWER_MANAGER            | number  | Yes| Power management. The corresponding HiTrace command is **tagName:power**.                  |
| RPC                      | number  | Yes| RPC. The corresponding HiTrace command is **tagName:rpc**.                     |
| SAMGR                    | number  | Yes| System capability management. The corresponding HiTrace command is **tagName:samgr**.                |
| WINDOW_MANAGER           | number  | Yes| Window management. The corresponding HiTrace command is **tagName:window**.                 |
| AUDIO                    | number  | Yes| Audio module. The corresponding HiTrace command is **tagName:zaudio**.                 |
| CAMERA                   | number  | Yes| Camera module. The corresponding HiTrace command is **tagName:zcamera**.                |
| IMAGE                    | number  | Yes| Image module. The corresponding HiTrace command is **tagName:zimage**.                 |
| MEDIA                    | number  | Yes| Media module. The corresponding HiTrace command is **tagName:zmedia**.                 |

## NativeMemInfo<sup>12+</sup>

Describes memory information of the application process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name     | Type  | Read Only | Optional| Description                                                                            |
| --------- | ------ | --|----|--------------------------------------------------------------------------------|
| pss  | bigint |  No | No | Size of the occupied physical memory (including the proportionally allocated memory occupied by the shared library), in KB. The value of this parameter is obtained by summing up the values of **Pss** and **SwapPss** in the **/proc/{pid}/smaps_rollup** node.|
| vss  | bigint |  No | No |  Size of the occupied virtual memory (including the memory occupied by the shared library), in KB. The value of this parameter is obtained by multiplying the value of **size** in the **/proc/{pid}/statm** node by **4**.               |
| rss  | bigint |  No | No | Size of the occupied physical memory (including the memory occupied by the shared library), in KB. The value of this parameter is obtained by reading the value of **Rss** in the **/proc/{pid}/smaps_rollup** node.               |
| sharedDirty  | bigint |  No | No | Size of the shared dirty memory, in KB. The value of this parameter is obtained by reading the value of **Shared_Dirty** in the **/proc/{pid}/smaps_rollup** node.                   |
| privateDirty  | bigint |  No | No | Size of the private dirty memory, in KB. The value of this parameter is obtained by reading the value of **Private_Dirty** in the **/proc/{pid}/smaps_rollup** node.                  |
| sharedClean  | bigint |  No | No | Size of the shared clean memory, in KB. The value of this parameter is obtained by reading the value of **Shared_Clean** in the **/proc/{pid}/smaps_rollup** node.                   |
| privateClean  | bigint |  No | No | Size of the private clean memory, in KB. The value of this parameter is obtained by reading the value of **Private_Clean** in the **/proc/{pid}/smaps_rollup** node.                 |

## SystemMemInfo<sup>12+</sup>

Describes the system memory information, including the total memory, free memory, and available memory.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name     | Type  | Read Only | Optional| Description                                             |
| --------- | ------ | ---- |---- |-------------------------------------------------|
| totalMem  | bigint |  No |   No |Total memory of the system, in KB. The value of this parameter is obtained by reading the value of **MemTotal** in the **/proc/meminfo** node.     |
| freeMem  | bigint |  No |   No |Free memory of the system, in KB. The value of this parameter is obtained by reading the value of **MemFree** in the **/proc/meminfo** node.     |
| availableMem  | bigint |  No |   No |Available memory of the system, in KB. The value of this parameter is obtained by reading the value of **MemAvailable** in the **/proc/meminfo** node.|

## TraceFlag<sup>12+</sup>

Describes types of trace collection threads, including the main thread and all threads.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name                        | Value| Description                   |
| --------------------------- |---| ----------------------- |
| MAIN_THREAD                 | 1 | The main thread of the application.|
| ALL_THREADS                 | 2 | All threads of the application.|

## GcStats<sup>12+</sup>

type GcStats = Record&lt;string, number&gt;

Describes the key-value pair used to store GC statistics. This type does not support multi-thread operations. If this type is operated by multiple threads at the same time in an application, use a lock for it.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Type     | Description                         |
| -----------| ---------------------------- |
| Record&lt;string, number&gt;     | Key-value pair format used to store GC statistics.    |

GcStats contains the following information:

| Name                    | Type  | Description                     |
|-------------------------| ------ |------------------------- |
| ark.gc.gc-count         | number |  Count of GC of the calling thread.|
| ark.gc.gc-time          | number |  GC time triggered by the calling thread, in milliseconds.|
| ark.gc.gc-bytes-allocated | number | Memory size allocated to the Ark VM of the calling thread, in bytes.|
| ark.gc.gc-bytes-freed   | number | Memory freed by the GC of the calling thread, in bytes.|
| ark.gc.fullgc-longtime-count | number |  Count of long fullGC of the calling thread.|

## JsRawHeapTrimLevel<sup>20+</sup>

Enumerates the trimming levels of the heap snapshot.

**TRIM_LEVEL_2** takes a longer time than **TRIM_LEVEL_1**. The threshold for screen freezing is 6 seconds. With **TRIM_LEVEL_1**, the trim duration stays below this threshold. When switched to **TRIM_LEVEL_2**, the duration may exceed 6s, triggering an **APP_FREEZE** (screen freeze event) and causing the system to kill the application; the trim level then reverts to **TRIM_LEVEL_1**.

You are advised to use **TRIM_LEVEL_1** to ensure application stability and use **TRIM_LEVEL_2 **only when more complete trimming is required.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name        | Value  | Description                                                        |
| ------------ | ---- | ------------------------------------------------------------ |
| TRIM_LEVEL_1 | 0    | Level 1 trimming, mainly used for strings.                      |
| TRIM_LEVEL_2 | 1    | Level 2 trimming, which reduces the size of the object address identifier from 8 bytes to 4 bytes.|

## hidebug.isDebugState<sup>12+</sup>

isDebugState(): boolean

Obtains the debugging state of an application process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type | Description                                                  |
| ------ |------------------------------------------------------|
| boolean | Whether the Ark or native layer of the application process is in the debugging state. The value **true** indicates that the layer is in the debugging state, and **false** indicates the opposite.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

console.info(`isDebugState = ${hidebug.isDebugState()}`)
```

## hidebug.getGraphicsMemory<sup>14+</sup>

getGraphicsMemory(): Promise&lt;number&gt;

Obtains the size of the GPU memory. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type                   | Description                          |
|-----------------------|------------------------------|
| Promise&lt;number&gt; | Size of the GPU memory, in KB.|

**Error codes**

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 11400104 | Failed to get the application memory due to a remote exception. |

**Example**

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

hidebug.getGraphicsMemory().then((ret: number) => {
  console.info(`graphicsMemory: ${ret}`)
}).catch((error: BusinessError) => {
  console.error(`error code: ${error.code}, error msg: ${error.message}`);
})
```

## hidebug.getGraphicsMemorySync<sup>14+</sup>

getGraphicsMemorySync(): number

Obtains the size of the GPU memory synchronously.

> **NOTE**
>
> This API involves multiple cross-process communications, which may take seconds. To avoid performance problems, you are advised to use the asynchronous API **getGraphicsMemory** instead of this API in the main thread.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type | Description            |
| ------ |----------------|
| number | Size of the GPU memory, in KB.|

**Error codes**

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 11400104 | Failed to get the application memory due to a remote exception. |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  console.info(`graphicsMemory: ${hidebug.getGraphicsMemorySync()}`)
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.dumpJsRawHeapData<sup>18+</sup>

dumpJsRawHeapData(needGC?: boolean): Promise&lt;string&gt;

Dumps the original heap snapshot of the VM for the current thread. The API uses a promise to return the path of the .rawheap file. You can use [rawheap-translator](../../tools/rawheap-translator.md) to convert the generated file into a .heapsnapshot file for parsing.

> **NOTE**
>
> This API is resource-consuming. Therefore, the calling frequency and times are strictly limited. You need to delete the files immediately after processing them.
> You are advised to use this API only in the grayscale version of an application.  

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name                    | Type     | Mandatory| Description                                         |
|-------------------------|---------|----|---------------------------------------------|
| needGC         | boolean | No | Whether GC is required before storing heap snapshots. The value **true** indicates that GC is required, and **false** indicates the opposite. The default value is **true**.|

**Return value**

| Type | Description                                                                                                  |
| ------ |------------------------------------------------------------------------------------------------------|
| Promise&lt;string&gt; | Path of the generated snapshot file. ([Application Sandbox](../../file-management/app-sandbox-directory.md#application-file-directory-and-application-file-path))|

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID   | Error Message|
|----------| ----------------------------------------------------------------- |
| 11400106 | Quota exceeded. |
| 11400107 | Fork operation failed. |
| 11400108 | Failed to wait for the child process to finish. |
| 11400109 | Timeout while waiting for the child process to finish. |
| 11400110 | Disk remaining space too low. |
| 11400111 | Napi interface call exception. |
| 11400112 | Repeated data dump. |
| 11400113 | Failed to create dump file. |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';
hidebug.dumpJsRawHeapData().then((filePath: string) => {
  console.info(`dumpJsRawHeapData success and generated file path is ${filePath}`)
}).catch((error: BusinessError) => {
  console.error(`error code: ${error.code}, error msg: ${error.message}`);
})
```

## hidebug.enableGwpAsanGrayscale<sup>20+</sup>

enableGwpAsanGrayscale(options?: GwpAsanOptions, duration?: number): void

Enables GWP-Asan to detect illegal behaviors in heap memory usage.

This API is used to dynamically configure and enable GWP-Asan to adapt to the custom GWP-Asan detection policy. The configuration takes effect after the application is restarted.

For details about GWP-Asan, see [Using GWP-Asan to Detect Memory Errors](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-stability-gwpasan-detection).

> **NOTE**
> 
> 1. If more than 20 applications have been enabled during device running, this API will fail to be called and an error code will be thrown.
> 2. To prevent abnormal application exit, use **try-catch** to capture exceptions.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description  |
|---------|---------|--------|-----|
|options | [GwpAsanOptions](#gwpasanoptions20) | No| Configuration options of GWP-Asan. If no parameter is set, the default value is used.|
|duration | number | No| GWP-Asan duration. The default value is 7 days. The value must be a positive integer.|

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID   | Error Message|
|----------| ----------------------------------------------------------------- |
| 11400114 | The number of GWP-ASAN applications of this device overflowed after last boot. |

**Example**:

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let options: hidebug.GwpAsanOptions = {
  alwaysEnabled: true,
  sampleRate: 2500,
  maxSimutaneousAllocations: 5000,
};
let duration: number = 4;

try {
  hidebug.enableGwpAsanGrayscale(options, duration);
  console.info(`Succeeded in enabling GWP-Asan.`);
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`Failed to enable GWP-Asan. Code: ${err.code}, message: ${err.message}`);
}
```
## GwpAsanOptions<sup>20+</sup>
Defines configuration options of GWP-Asan. You can configure whether to enable GWP-Asan, the sampling frequency, and the maximum number of allocated slots.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name        | Type | Read Only | Optional| Description|
|--------------|------|-------|-------|-----|
|alwaysEnabled | boolean | No | Yes| Whether to always enable GWP-Asan. The value **true** means to always enable GWP-Asan.<br>The value **false** means to enable GWP-Asan at a probability of 1/128.<br> The default value is **false**.|
|sampleRate    |number| No |Yes|Sampling rate of GWP-Asan. The default value is **2500**. The value must be a positive integer greater than 0. If the value is a decimal, it is rounded up.<br> GWP-Asan performs sampling on the allocated memory at a probability of 1/**sampleRate**.|
|maxSimutaneousAllocations|number|No|Yes|Maximum number of allocated slots. The default value is **1000**. The value must be a positive integer greater than 0. If the value is a decimal, it is rounded up.<br>When the slots are used up, the newly allocated memory is no longer monitored.<br>After the used memory is released, the slots occupied by the memory are automatically reused to facilitate subsequent memory monitoring.|

## hidebug.disableGwpAsanGrayscale<sup>20+</sup>
disableGwpAsanGrayscale(): void

Disables GWP-Asan. This API is used to cancel the custom configuration and restore the default parameter [GwpAsanOptions](#gwpasanoptions20).

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Example**:

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.disableGwpAsanGrayscale();
```

## hidebug.getGwpAsanGrayscaleState<sup>20+</sup>
getGwpAsanGrayscaleState(): number

Obtains the number of remaining days for enabling GWP-Asan.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type| Description|
|-----------|-------------|
| number    |Number of remaining days for enabling GWP-Asan. If GWP-Asan is disabled, **0** is returned.|

**Example**:

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let remainDays: number = hidebug.getGwpAsanGrayscaleState();
console.info(`remainDays: ${remainDays}`);
```

## hidebug.setJsRawHeapTrimLevel<sup>20+</sup>

setJsRawHeapTrimLevel(level: JsRawHeapTrimLevel): void

Sets the trimming level of the original heap snapshot stored by the current process. Using **TRIM_LEVEL_2** for this API can effectively reduce the size of the heap snapshot file.

> **NOTE**
>
> The default trimming level is **TRIM_LEVEL_1**. If **TRIM_LEVEL_2** is set, you need to use [rawheap-translator](../../tools/rawheap-translator.md) since API version 20 to convert the .rawheap file to the .heapsnapshot file. Otherwise, the conversion may fail.
>
> This API affects the result of [dumpJsRawHeapData](#hidebugdumpjsrawheapdata18).

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name| Type                                       | Mandatory| Description                  |
| ------ | ------------------------------------------- | ---- | ---------------------- |
| level  | [JsRawHeapTrimLevel](#jsrawheaptrimlevel20) | Yes  | Trimming level for storing heap snapshots. The default value is **TRIM_LEVEL_1**.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

hidebug.setJsRawHeapTrimLevel(TRIM_LEVEL_2);
}
```
