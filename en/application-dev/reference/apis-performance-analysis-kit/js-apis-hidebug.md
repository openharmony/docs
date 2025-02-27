# @ohos.hidebug (HiDebug)

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The **hidebug** module provides APIs for you to obtain the memory usage of an application, including the static heap memory (native heap) and proportional set size (PSS) occupied by the application process. You can also export VM memory slices and collect VM CPU profiling data.

## Modules to Import

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
```

## hidebug.getNativeHeapSize

getNativeHeapSize(): bigint

Obtains the size of heap memory (including the allocator metadata) held by a process, which is measured by the memory allocator.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| bigint | Size of the heap memory (including the allocator metadata) held by the process, in bytes.|

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapSize: bigint = hidebug.getNativeHeapSize();
```

## hidebug.getNativeHeapAllocatedSize

getNativeHeapAllocatedSize(): bigint

Obtains the size of the heap memory allocated to a process service, which is measured by the memory allocator.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                             |
| ------ | --------------------------------- |
| bigint | Size of the heap memory allocated to a process service, in bytes.|


**Example**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapAllocatedSize: bigint = hidebug.getNativeHeapAllocatedSize();
```

## hidebug.getNativeHeapFreeSize

getNativeHeapFreeSize(): bigint

Obtains the size of the cache memory held by the memory allocator.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                           |
| ------ | ------------------------------- |
| bigint | Size of the cache memory held by the memory allocator, in bytes.|

**Example**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapFreeSize: bigint = hidebug.getNativeHeapFreeSize();
```

## hidebug.getPss

getPss(): bigint

Obtains the size of the physical memory actually used by the application process.

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

## hidebug.getVss<sup>11+<sup>

getVss(): bigint

Obtains the virtual set size used by the application process.

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

Obtains the size of the shared dirty memory of a process.

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

## hidebug.getPrivateDirty<sup>9+<sup>

getPrivateDirty(): bigint

Obtains the size of the private dirty memory of a process.

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

## hidebug.getCpuUsage<sup>9+<sup>

getCpuUsage(): number

Obtains the CPU usage of a process.

For example, if the CPU usage is **50%**, **0.5** is returned.

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

## hidebug.getServiceDump<sup>9+<sup>

getServiceDump(serviceid : number, fd : number, args : Array\<string>) : void

Obtains system service information.

**Required permissions**: ohos.permission.DUMP (available only for system applications)

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| serviceid | number | Yes  | Obtains the system service information based on the specified service ID.|
| fd | number | Yes  | File descriptor to which data is written by the API.|
| args | Array\<string> | Yes  | Parameter list corresponding to the **Dump** API of the system service.|

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed,Possible causes:1.the parameter type error 2.the args parameter is not string array  |
| 11400101 | ServiceId invalid. The system ability does not exist.                                           |

**Example**

```ts
import { fileIo } from '@kit.CoreFileKit';
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let applicationContext: common.Context | null = null;
try {
  let context = getContext() as common.UIAbilityContext;
  applicationContext = context.getApplicationContext();
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}

let filesDir: string = applicationContext!.filesDir;
let path: string = filesDir + "/serviceInfo.txt";
console.info("output path: " + path);
let file = fileIo.openSync(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
let serviceId: number = 10;
let args: Array<string> = new Array("allInfo");

try {
  hidebug.getServiceDump(serviceId, file.fd, args);
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
fileIo.closeSync(file);
```

## hidebug.startJsCpuProfiling<sup>9+</sup>

startJsCpuProfiling(filename : string) : void

Starts the profiling method. `startJsCpuProfiling()` and `stopJsCpuProfiling()` are called in pairs. `startJsCpuProfiling()` always occurs before `stopJsCpuProfiling()`; that is, calling the functions in the sequence similar to the following is prohibited: `start->start->stop`, `start->stop->stop`, and `start->start->stop->stop`.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | Yes  | User-defined profile name. The `filename.json` file is generated in the `files` directory of the application based on the specified `filename`.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed,Parameter type error                        |

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

Stops the profiling method. `startJsCpuProfiling()` and `stopJsCpuProfiling()` are called in pairs. `startJsCpuProfiling()` always occurs before `stopJsCpuProfiling()`; that is, calling the functions in the sequence similar to the following is prohibited: `start->start->stop`, `start->stop->stop`, and `start->start->stop->stop`.

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

dumpJsHeapData(filename : string) : void

Exports the heap data.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | Yes  | User-defined heap file name. The `filename.heapsnapshot` file is generated in the `files` directory of the application based on the specified `filename`.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed, Parameter type error                      |

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

startProfiling(filename : string) : void

> **NOTE**
> This API is deprecated since API version 9. You are advised to use [hidebug.startJsCpuProfiling](#hidebugstartjscpuprofiling9).

Starts the profiling method. `startProfiling()` and `stopProfiling()` are called in pairs. `startProfiling()` always occurs before `stopProfiling()`; that is, calling the functions in the sequence similar to the following is prohibited: `start->start->stop`, `start->stop->stop`, and `start->start->stop->stop`.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | Yes  | User-defined profile name. The `filename.json` file is generated in the `files` directory of the application based on the specified `filename`.|

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
> This API is deprecated since API version 9. You are advised to use [hidebug.stopJsCpuProfiling](#hidebugstopjscpuprofiling9).

Stops the profiling method. `startProfiling()` and `stopProfiling()` are called in pairs. `startProfiling()` always occurs before `stopProfiling()`; that is, calling the functions in the sequence similar to the following is prohibited: `start->start->stop`, `start->stop->stop`, and `start->start->stop->stop`.

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

dumpHeapData(filename : string) : void

> **NOTE**
> This API is deprecated since API version 9. You are advised to use [hidebug.dumpJsHeapData](#hidebugdumpjsheapdata9).

Exports the heap data.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | Yes  | User-defined heap file name. The `filename.heapsnapshot` file is generated in the `files` directory of the application based on the specified `filename`.|

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
| [VMMemoryInfo](#vmmemoryinfo12) |  VM memory information. |

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

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type            | Description                                                       |
| -----------------| ------------------------------------------------------------|
| [ThreadCpuUsage](#threadcpuusage12)[] | CPU usage of all threads of the current application process.|



**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let appThreadCpuUsage: hidebug.ThreadCpuUsage[] = hidebug.getAppThreadCpuUsage();
for (let ii = 0; ii < appThreadCpuUsage.length; ii++) {
  console.info(`threadId=${appThreadCpuUsage[ii].threadId}, cpuUsage=${appThreadCpuUsage[ii].cpuUsage}`);
}
```

## hidebug.startAppTraceCapture<sup>12+</sup>

startAppTraceCapture(tags : number[], flag: TraceFlag, limitSize: number) : string

Starts automatic trace collection for a specified scope. This API is a supplement to the [hitrace](../../dfx/hitrace.md) module.
The performance consumption during trace collection increases with the collection scope. Therefore, before using this API, you are advised to run the **hitrace** command to capture trace logs and select the key scope of trace collection to improve the API performance.

**startAppTraceCapture()** and [stopAppTraceCapture ()](#hidebugstopapptracecapture12) must be called in pairs. Repeat calling of **startAppTraceCapture()** will cause exceptions. Trace collection consumes a lot of performance resources. Therefore, call **stopAppTraceCapture()** immediately after trace collection is complete.

When an application calls **startAppTraceCapture()** to collect trace data and the size of the data exceeds the value of **limitSize**, the system automatically calls **stopAppTraceCapture()** to stop trace collection. Therefore, if **limitSize** is set improperly, the collected trace data is insufficient for fault analysis. Therefore, you need to evaluate the value of **limitSize** as required.

Evaluation method: limitSize = Expected trace collection duration x Unit trace traffic.

Expected trace collection duration: You can determine the duration based on the fault scenario. The unit is second.

Unit trace traffic: The size of a trace generated by an application per second. The recommended value is 300 KB/s. You are advised to use the actual value of your application. The unit is KB/s.

To obtain the unit trace traffic, you can call **startAppTraceCapture()** with **limitSize** set to the maximum value 500 MB. After **N** seconds, call **stopAppTraceCapture()** to stop the collection and check the trace size (**S** KB). The unit trace traffic is S/N.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type    | Mandatory| Description                                |
| -------- | ------   | ---- |------------------------------------|
| tags     | number[] | Yes  | Scope for trace collection. For details, see [tags](#hidebugtags12).|
| flag     | TraceFlag| Yes  | For details, see [TraceFlag](#traceflag12).     |
| limitSize| number   | Yes  | Limit on the trace file size, in bytes. The maximum size of a single file is 500 MB.|

**Return value**

| Type            | Description                                          |
| -----------------| -----------------------------------------------|
| string           | Path of the trace file.                           |

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small 2.The parameter is not within the enumeration type 3.The parameter type error or parameter order error|
| 11400102 | Capture trace already enabled.                                         |
| 11400103 | No write permission on the file.                                |
| 11400104 | Abnormal trace status.                                 |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

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
| 11400104 | The status of the trace is abnormal                                |
| 11400105 |   No capture trace running                                       |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

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

Obtains the memory limit of the application process.

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

try {
  console.info(`getSystemCpuUsage: ${hidebug.getSystemCpuUsage()}`)
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.setAppResourceLimit<sup>12+</sup>

setAppResourceLimit(type: string, value: number, enableDebugLog: boolean) : void

Sets the number of FDs, number of threads, JS memory, or native memory limit of the application.
**NOTE**: This feature is available only after **Developer options** is enabled and the device is restarted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type | string |  Yes | Types of resource leakage: pss_memory (native memory) leak, js_heap (js heap memory) leak, fd (file descriptor) leak, and thread (thread) leak.|
| value | number |  Yes | The maximum value of a resource leakage type. Value range: pss_memory leak **[1024, 4 * 1024 * 1024] (in KB)**, js_heap memory leak **[85, 95]** (85% to 95% of the upper limit of the JS heap memory), fd leak [10, 10000], thread leak **[1, 1000]**|
| enableDebugLog | boolean |  Yes | Whether to enable debug log. The default value is **false**. Set this parameter to **true** only in the dark version because collecting debug logs consumes too much CPU or memory.|

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small 2.The parameter is not in the specified type 3.The parameter type error or parameter order error  |
| 11400104 | Set limit failed due to remote exception |

**Example**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

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

Obtains the memory information of the application process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

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

## hidebug.getSystemMemInfo<sup>12+</sup>

getSystemMemInfo(): SystemMemInfo

Obtains system memory information.

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

Obtains all system GC statistics.

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

getVMRuntimeStat(item : string): number

Obtains the specified system GC statistics based on parameters.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description         |
| -------- | ------ | ---- |-------------|
| item | string | Yes  | Item of the GC statistics to be obtained.|

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

| Name     | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ------------ |
| rssLimit    | bigint |  Yes | Limit on the resident set size, in KB.    |
| vssLimit  | bigint |  Yes | Limit on the virtual memory size, in KB.      |
| vmHeapLimit | bigint |  Yes | Limit on the JS VM heap size of the calling thread, in KB.     |
| vmTotalHeapSize | bigint |  Yes | Size limit of the JS heap memory of the process, in KB.     |

## VMMemoryInfo<sup>12+</sup>

Describes the VM memory information.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name              | Type   | Readable| Writable| Description                               |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| totalHeap          | bigint  | Yes  | No  | Total heap size of the current VM, in KB.   |
| heapUsed           | bigint  | Yes  | No  | Heap size used by the current VM, in KB. |
| allArraySize       | bigint  | Yes  | No  | Size of all array objects of the current VM, in KB.|

## ThreadCpuUsage<sup>12+</sup>

Describes the CPU usage of a thread.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name              | Type   | Readable| Writable| Description                               |
| -------------------| ------- | ---- | ---- | ----------------------------------- |
| threadId           | number  | Yes  | No  | Thread ID.                          |
| cpuUsage           | number  | Yes  | No  | CPU usage of the thread.                      |

## hidebug.tags<sup>12+</sup>

Enumerates the tags used in trace collection. You can use the [hitrace](../../dfx/hitrace.md) commands to capture the trace data of a specified tag for preview.

Note that the tag values are defined by the system and may change with the version upgrade. To avoid compatibility issues after the upgrade, use the tag names instead of the tag values in application development.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name                    | Type   | Read Only | Description                                        |
| -------------------------| ------- |-----|--------------------------------------------|
| ABILITY_MANAGER          | number  | Yes| Capability management. The corresponding command is **tagName:ability**.                 |
| ARKUI                    | number  | Yes| ArkUI development framework. The corresponding command is **tagName:ace**.               |
| ARK                      | number  | Yes| JSVM VM. The corresponding command is **tagName:ark**.                 |
| BLUETOOTH                | number  | Yes| Bluetooth. The corresponding command is **tagName:bluetooth**.                |
| COMMON_LIBRARY           | number  | Yes| Common library subsystem. The corresponding command is **tagName:commonlibrary**.        |
| DISTRIBUTED_HARDWARE_DEVICE_MANAGER | number  | Yes| Distributed hardware device management. The corresponding command is **tagName:devicemanager**.     |
| DISTRIBUTED_AUDIO        | number  | Yes| Distributed audio. The corresponding command is **tagName:daudio**.                |
| DISTRIBUTED_CAMERA       | number  | Yes| Distributed camera. The corresponding command is **tagName:dcamera**.               |
| DISTRIBUTED_DATA         | number  | Yes| Distributed data management. The corresponding command is **tagName:distributeddatamgr**.|
| DISTRIBUTED_HARDWARE_FRAMEWORK | number  | Yes| Distributed hardware framework. The corresponding command is **tagName:dhfwk**.                |
| DISTRIBUTED_INPUT        | number  | Yes| Distributed input. The corresponding command is **tagName:dinput**.                |
| DISTRIBUTED_SCREEN       | number  | Yes| Distributed screen. The corresponding command is **tagName:dscreen**.               |
| DISTRIBUTED_SCHEDULER    | number  | Yes| Distributed scheduler. The corresponding command is **tagName:dsched**.               |
| FFRT                     | number  | Yes| FFRT task. The corresponding command is **tagName:ffrt**.                 |
| FILE_MANAGEMENT          | number  | Yes| File management system. The corresponding command is **tagName:filemanagement**.       |
| GLOBAL_RESOURCE_MANAGER  | number  | Yes| Global resource management. The corresponding command is **tagName:gresource**.            |
| GRAPHICS                 | number  | Yes| Graphics module. The corresponding command is **tagName:graphic**.                |
| HDF                      | number  | Yes| HDF subsystem. The corresponding command is **tagName:hdf**.                  |
| MISC                     | number  | Yes| MISC module. The corresponding command is **tagName:misc**.                 |
| MULTIMODAL_INPUT         | number  | Yes| Multi-modal input module. The corresponding command is **tagName:multimodalinput**.     |
| NET                      | number  | Yes| Network. The corresponding command is **tagName:net**.                      |
| NOTIFICATION             | number  | Yes| Notification module. The corresponding command is **tagName:notification**.           |
| NWEB                     | number  | Yes| Nweb. The corresponding command is **tagName:nweb**.                   |
| OHOS                     | number  | Yes| OHOS. The corresponding command is **tagName:ohos**.                 |
| POWER_MANAGER            | number  | Yes| Power management. The corresponding command is **tagName:power**.                  |
| RPC                      | number  | Yes| RPC. The corresponding command is **tagName:rpc**.                     |
| SAMGR                    | number  | Yes| System capability management. The corresponding command is **tagName:samgr**.                |
| WINDOW_MANAGER           | number  | Yes| Window management. The corresponding command is **tagName:window**.                 |
| AUDIO                    | number  | Yes| Audio module. The corresponding command is **tagName:zaudio**.                 |
| CAMERA                   | number  | Yes| Camera module. The corresponding command is **tagName:zcamera**.                |
| IMAGE                    | number  | Yes| Image module. The corresponding command is **tagName:zimage**.                 |
| MEDIA                    | number  | Yes| Media module. The corresponding command is **tagName:zmedia**.                 |

## NativeMemInfo<sup>12+</sup>

Describes memory information of the application process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name     | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ------------ |
| pss  | bigint |  Yes | Size of the occupied physical memory (including the proportionally allocated memory occupied by the shared library), in KB.    |
| vss  | bigint |  Yes | Size of the occupied virtual memory (including the memory occupied by the shared library), in KB.      |
| rss  | bigint |  Yes | Size of the occupied physical memory (including the memory occupied by the shared library), in KB.        |
| sharedDirty  | bigint |  Yes | Size of the shared dirty memory, in KB.     |
| privateDirty  | bigint |  Yes | Size of the private dirty memory, in KB.     |
| sharedClean  | bigint |  Yes | Size of the shared clean memory, in KB.     |
| privateClean  | bigint |  Yes | Size of the private clean memory, in KB.     |

## SystemMemInfo<sup>12+</sup>

Describes the system memory information.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name     | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ------------ |
| totalMem  | bigint |  Yes | Total memory of the system, in KB.    |
| freeMem  | bigint |  Yes | Free memory of the system, in KB.      |
| availableMem  | bigint |  Yes | Available memory of the system, in KB.     |

## TraceFlag<sup>12+</sup>

Defines the type of the trace collection thread.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name                        | Value| Description                   |
| --------------------------- |---| ----------------------- |
| MAIN_THREAD                 | 1 | The main thread of the application.|
| ALL_THREADS                 | 2 | All threads of the application.|

## GcStats<sup>12+</sup>

type GcStats = Record&lt;string, number&gt;

Key-value pair format used to store GC statistics. This type is not multi-thread safe. If a **GcStats** instance is operated by multiple threads at the same time in an application, use the lock mechanism for the instance.

System capability: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Type     | Description                         |
| -----------| ---------------------------- |
| Record&lt;string, number&gt;     | Indicates the value is in **Record** key-value pair format.    |

**GcStats** contain the following key values:

| Name                    | Type  | Description                     |
|-------------------------| ------ |------------------------- |
| ark.gc.gc-count         | number |  Count of GC of the calling thread.|
| ark.gc.gc-time          | number |  GC time triggered by the calling thread, in milliseconds.|
| ark.gc.gc-bytes-allocated | number | Memory size allocated to the Ark VM of the calling thread, in bytes.|
| ark.gc.gc-bytes-freed   | number | Memory freed by the GC of the calling thread, in bytes.|
| ark.gc.fullgc-longtime-count | number |  Count of long fullGC of the calling thread.|

## hidebug.isDebugState<sup>12+</sup>

isDebugState(): boolean

Obtains whether an application process is being debugged. If the ark or native layer of the application process is being debugged, **true** is returned. Otherwise, **false** is returned.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type | Description                     |
| ------ | -------------------------- |
| boolean | Whether an application process is being debugged.|

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

Obtains the size of the GPU memory. This API uses a synchronous callback to return the result.

**Note**: This API involves multiple cross-process communications and may have performance problems. The asynchronous API **getGraphicsMemory** is recommended.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type | Description        |
| ------ |------------|
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
