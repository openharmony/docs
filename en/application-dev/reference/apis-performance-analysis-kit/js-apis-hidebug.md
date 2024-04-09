# @ohos.hidebug (HiDebug)

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The **hidebug** module provides APIs for you to obtain the memory usage of an application, including the static heap memory (native heap) and proportional set size (PSS) occupied by the application process. You can also export VM memory slices and collect VM CPU profiling data.

## Modules to Import

```ts
import hidebug from '@ohos.hidebug';
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
| 11400101 | the service id is invalid                                           |
| 401 | the parameter check failed                                            |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import fs from '@ohos.file.fs';
import hidebug from '@ohos.hidebug';
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

export default class HidebugTest extends UIAbility {
  public testfunc() {
    let applicationContext: common.Context | null = null;
    try {
      applicationContext = this.context.getApplicationContext();
    } catch (error) {
      console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
    }

    let filesDir: string = applicationContext!.filesDir;
    let path: string = filesDir + "/serviceInfo.txt";
    console.info("output path: " + path);
    let file = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    let serviceId: number = 10;
    let args: Array<string> = new Array("allInfo");

    try {
      hidebug.getServiceDump(serviceId, file.fd, args);
    } catch (error) {
      console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
    }
    fs.closeSync(file);
  }
}

let t = new HidebugTest();
t.testfunc();
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
| 401 | the parameter check failed                                            |

**Example**

```ts
import hidebug from '@ohos.hidebug';
import { BusinessError } from '@ohos.base';

try {
  hidebug.startJsCpuProfiling("cpu_profiling");
  // ...
  hidebug.stopJsCpuProfiling();
} catch (error) {
  console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.stopJsCpuProfiling<sup>9+</sup>

stopJsCpuProfiling() : void

Stops the profiling method. `startJsCpuProfiling()` and `stopJsCpuProfiling()` are called in pairs. `startJsCpuProfiling()` always occurs before `stopJsCpuProfiling()`; that is, calling the functions in the sequence similar to the following is prohibited: `start->start->stop`, `start->stop->stop`, and `start->start->stop->stop`.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Example**

```ts
import hidebug from '@ohos.hidebug';
import { BusinessError } from '@ohos.base';

try {
  hidebug.startJsCpuProfiling("cpu_profiling");
  // ...
  hidebug.stopJsCpuProfiling();
} catch (error) {
  console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
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
| 401 | the parameter check failed                                            |

**Example**

```ts
import hidebug from '@ohos.hidebug';
import { BusinessError } from '@ohos.base';

try {
  hidebug.dumpJsHeapData("heapData");
} catch (error) {
  console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
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
let vmMemory: hidebug.VMMemoryInfo = hidebug.getAppVMMemoryInfo();
hilog.info(0x0000, "example", "totalHeap = %{public}d", vmMemory.totalHeap);
hilog.info(0x0000, "example", "heapUsed = %{public}d", vmMemory.heapUsed);
hilog.info(0x0000, "example", "allArraySize = %{public}d", vmMemory.allArraySize);
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
let appThreadCpuUsage: hidebug.ThreadCpuUsage[] = hidebug.getAppThreadCpuUsage();
for (let ii = 0; ii < appThreadCpuUsage.length; ii++) {
    hilog.info(0x0000, "example", "threadId=%{public}d, cpuUsage=%{public}f", appThreadCpuUsage[ii].threadId,
    appThreadCpuUsage[ii].cpuUsage);
}
  ```

## hidebug.startAppTraceCapture<sup>12+</sup>

startAppTraceCapture(tags : number[], flag: TraceFlag, limitSize: number) : string

Starts application trace collection. **startAppTraceCapture()** and **[stopAppTraceCapture()](#hidebugstopapptracecapture12)** must be called in pairs.

**startAppTraceCapture()** always occurs before **stopAppTraceCapture()**; that is, calling the APIs in the sequence similar to the following is prohibited: start -> start -> stop, start -> stop -> stop, and start -> start -> stop -> stop.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type    | Mandatory| Description                                                                                 |
| -------- | ------   | ---- | ------------------------------------------------------------------------------------- |
| tags     | number[] | Yes  | For details, see [tags](#tags12).                                                     |
| flag     | TraceFlag| Yes  | For details, see [TraceFlag](#traceflag12).         |
| limitSize| number   | Yes  | Limit on the trace file size, in bytes. The maximum size of a single file is 500 MB.                                                      |

**Return value**

| Type            | Description                                          |
| -----------------| -----------------------------------------------|
| string           | Path of the trace file.                           |

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed                                            |
| 11400102 | Have already capture trace                                          |
| 11400103 | Without write permission on the file                                |
| 11400104 | The status of the trace is abnormal                                 |

**Example**

```ts
let tags: number[] = [hidebug.tags.ABILITY_MANAGER, hidebug.tags.ARKUI];
let flag: hidebug.TraceFlag = hidebug.TraceFlag.MAIN_THREAD;
let limitSize: number = 1024 * 1024;
let fileName: string = hidebug.startAppTraceCapture(tags, flag, limitSize);
// code block
// ...
// code block
hidebug.stopAppTraceCapture();
```

## hidebug.stopAppTraceCapture<sup>12+</sup>

stopAppTraceCapture() : void

Stops application trace collection. **startAppTraceCapture()** and **[stopAppTraceCapture()](#hidebugstopapptracecapture12)** must be called in pairs.

**startAppTraceCapture()** always occurs before **stopAppTraceCapture()**; that is, calling the APIs in the sequence similar to the following is prohibited: start -> start -> stop, start -> stop -> stop, and start -> start -> stop -> stop.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Error codes**

For details about the error codes, see [HiDebug Error Codes](errorcode-hiviewdfx-hidebug.md).

| ID| Error Message|
| ------- | ----------------------------------------------------------------- |
| 11400104 | The status of the trace is abnormal                                |
| 11400105 |   No capture trace running                                       |

**Example**

```ts
let tags: number[] = [hidebug.tags.ABILITY_MANAGER, hidebug.tags.ARKUI];
let flag: hidebug.TraceFlag = hidebug.TraceFlag.MAIN_THREAD;
let limitSize: number = 1024 * 1024;
let fileName: string = hidebug.startAppTraceCapture(tags, flag, limitSize);
// code block
// ...
// code block
hidebug.stopAppTraceCapture();
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
 let appMemoryLimit:hidebug.MemoryLimit = hidebug.getAppMemoryLimit();
```
## MemoryLimit<sup>12+</sup>

Defines the memory limit of the application process.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name     | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ------------ |
| rssLimit    | bigint |  Yes | Limit on the resident set size, in KB.    |
| vssLimit  | bigint |  Yes | Limit on the virtual memory size, in KB.      |
| vmHeapLimit | bigint |  Yes | Limit on the JS VM heap size of the calling thread, in KB.     |

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

## tags<sup>12+</sup>

Enumerates scenario tags.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name                    | Type   |  Description                               |
| -------------------------| ------- |  ----------------------------------- |
| ABILITY_MANAGER          | number  |  Capability management.                        |
| ARKUI                    | number  |  ArkUI development framework.                   |
| ARK                      | number  |  JSVM VM.                      |
| BLUETOOTH                | number  |  Bluetooth.                           |
| COMMON_LIBRARY           | number  |  Common library subsystem.                    |
| DISTRIBUTED_HARDWARE_DEVICE_MANAGER | number  |  Distributed hardware device management.    |
| DISTRIBUTED_AUDIO        | number  |        Distributed audio.                |
| DISTRIBUTED_CAMERA       | number  |  Distributed camera.                      |
| DISTRIBUTED_DATA         | number  |  Distributed data management.               |
| DISTRIBUTED_HARDWARE_FRAMEWORK | number  |  Distributed hardware framework.             |
| DISTRIBUTED_INPUT        | number  |  Distributed input.                      |
| DISTRIBUTED_SCREEN       | number  |  Distributed screen.                      |
| DISTRIBUTED_SCHEDULER    | number  |  Distributed scheduler.                    |
| FFRT                     | number  |  FFRT task.                       |
| FILE_MANAGEMENT          | number  |  File management system.                    |
| GLOBAL_RESOURCE_MANAGER  | number  |  Global resource management.                    |
| GRAPHICS                 | number  |  Graphics module.                       |
| HDF                      | number  |  HDF subsystem.                      |
| MISC                     | number  |  MISC module.                       |
| MULTIMODAL_INPUT         | number  |  Multimodal input module.                  |
| NET                      | number  |  Network.                            |
| NOTIFICATION             | number  |  Notification module.                        |
| NWEB                     | number  |  Nweb.                           |
| OHOS                     | number  |  OHOS.                        |
| POWER_MANAGER            | number  |  Power management.                        |
| RPC                      | number  |  RPC.                            |
| SAMGR                    | number  |  System capability management.                    |
| WINDOW_MANAGER           | number  |  Window management.                        |
| AUDIO                    | number  |  Audio module.                       |
| CAMERA                   | number  |  Camera module.                       |
| IMAGE                    | number  |  Image module.                       |
| MEDIA                    | number  |  Media module.                       |

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
| 11400104 | The status of the system cpu usage is abnormal. |

**Example**
  ```ts
  let cpuUsage: number = hidebug.getSystemCpuUsage();
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
let nativeMemInfo: hidebug.NativeMemInfo = hidebug.getAppNativeMemInfo();

hilog.info(0x0000, 'testTag', "pss = %{public}d", nativeMemInfo.pss);

hilog.info(0x0000, 'testTag', "vss = %{public}d", nativeMemInfo.vss);

hilog.info(0x0000, 'testTag', "rss = %{public}d", nativeMemInfo.rss);

hilog.info(0x0000, 'testTag', "sharedDirty = %{public}d", nativeMemInfo.sharedDirty);

hilog.info(0x0000, 'testTag', "privateDirty = %{public}d", nativeMemInfo.privateDirty);

hilog.info(0x0000, 'testTag', "sharedClean = %{public}d", nativeMemInfo.sharedClean);

hilog.info(0x0000, 'testTag', "privateClean = %{public}d", nativeMemInfo.privateClean);
```
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

## hidebug.getSystemMemInfo<sup>12+</sup>

getSystemMemInfo(): SystemMemInfo

Obtains system memory information.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type | Description                     |
| ------ | -------------------------- |
| [SystemMemInfo](#systemmeminfo12) | System memory iInformation.|

**Example**

```ts
let systemMemInfo: hidebug.SystemMemInfo = hidebug.getSystemMemInfo();

hilog.info(0x0000, 'testTag', "totalMem = %{public}d", systemMemInfo.totalMem);

hilog.info(0x0000, 'testTag', "freeMem = %{public}d", systemMemInfo.freeMem);

hilog.info(0x0000, 'testTag', "availableMem = %{public}d", systemMemInfo.availableMem);
```
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

| Name     | Description        |
| --------- | ------------ |
| MAIN_THREAD  | Only the main thread of the current application.    |
| ALL_THREADS |  All threads of the current application.  |

<!--no_check-->