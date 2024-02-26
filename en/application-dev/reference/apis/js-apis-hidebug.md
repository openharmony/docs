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

Obtains the total heap memory size of this application.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| bigint | Total heap memory size of the application, in bytes.|

**Example**
  ```ts
  let nativeHeapSize: bigint = hidebug.getNativeHeapSize();
  ```

## hidebug.getNativeHeapAllocatedSize

getNativeHeapAllocatedSize(): bigint

Obtains the allocated heap memory size of this application.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                             |
| ------ | --------------------------------- |
| bigint | Allocated heap memory of the application, in bytes.|


**Example**
  ```ts
  let nativeHeapAllocatedSize: bigint = hidebug.getNativeHeapAllocatedSize();
  ```

## hidebug.getNativeHeapFreeSize

getNativeHeapFreeSize(): bigint

Obtains the free heap memory size of this application.

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                           |
| ------ | ------------------------------- |
| bigint | Free heap memory size of the application, in bytes.|

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

## hidebug.getAppNativeMemory<sup>12<sup>

getAppNativeMemory(): NativeMemInfo

Obtains the application process native meminfo


**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                                    |
| ------ | ---------------------------------------- |
| [NativeMemInfo](#nativeMemInfo) | Size of the memory actually used by the application process|

**Example**

  ```ts
let nativeMemInfo: NativeMemInfo = hidebug.getAppNativeMemory();

hilog.info(0x0000, 'testTag', 'pss = %{public}d', nativeMemInfo.pss);

hilog.info(0x0000, 'testTag', 'vss = %{public}d', nativeMemInfo.vss);

hilog.info(0x0000, 'testTag', 'rss = %{public}d', nativeMemInfo.rss);

hilog.info(0x0000, 'testTag', 'sharedDirty = %{public}d', nativeMemInfo.sharedDirty);

hilog.info(0x0000, 'testTag', 'privateDirty = %{public}d', nativeMemInfo.privateDirty);

hilog.info(0x0000, 'testTag', 'sharedClean = %{public}d', nativeMemInfo.sharedClean);

hilog.info(0x0000, 'testTag', 'privateClean = %{public}d', nativeMemInfo.privateClean);
  ```
## NativeMemInfo

Size of the memory actually used by the application process

**System capability**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name      | Type   | Mandatory | Description         |
| --------- | ------ | ---- | ------------ |
| pss    | bigint |  Yes  | process proportional set size memory, in KB     |
| vss    | bigint |  Yes  | virtual set size memory, in KB     |
| rss    | bigint |  Yes  | resident set size, in KB     |
| sharedDirty    | bigint |  Yes  | the size of the shared dirty memory, in KB     |
| privateDirty   | bigint |  Yes  | the size of the private dirty memory, in KB     |
| sharedClean    | bigint |  Yes  | the size of the shared clean memory, in KB     |
| privateClean   | bigint |  Yes  | the size of the private clean memory, in KB     |

## hidebug.getSysMemory<sup>12<sup>

getSysMemory(): SysMemInfo

Obtains the memory info of system

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                                    |
| ------ | ---------------------------------------- |
| [SysMemInfo](#sysMemInfo) | Size of system memory |

**Example**

  ```ts
let sysMemInfo: SysMemInfo = hidebug.getSysMemory();

hilog.info(0x0000, 'testTag', 'memTotal = %{public}d', sysMemInfo.memTotal);

hilog.info(0x0000, 'testTag', 'memFree = %{public}d', sysMemInfo.memFree);

hilog.info(0x0000, 'testTag', 'memAvailable = %{public}d', sysMemInfo.memAvailable);
  ```
## SysMemInfo

Size of the memory actually used by the application process

**System capability**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name      | Type   | Mandatory | Description         |
| --------- | ------ | ---- | ------------ |
| memTotal    | bigint |  Yes  | memory total, in kibibytes     |
| memFree    | bigint |  Yes  | memory free, in kibibytes     |
| memAvailable    | bigint |  Yes  | memory available, in kibibytes    |

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

**Required permissions**: ohos.permission.DUMP

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| serviceid | number | Yes  | Obtains the system service information based on the specified service ID.|
| fd | number | Yes  | File descriptor to which data is written by the API.|
| args | Array\<string> | Yes  | Parameter list corresponding to the **Dump** API of the system service.|

**Error codes**

For details about the error codes, see [HiDebug Error Codes](../errorcodes/errorcode-hiviewdfx-hidebug.md).

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md).

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

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | Yes  | User-defined profile name. The `filename.json` file is generated in the `files` directory of the application based on the specified `filename`.|

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md).

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

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [hidebug.startJsCpuProfiling](#hidebugstartjscpuprofiling9).

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

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [hidebug.stopJsCpuProfiling](#hidebugstopjscpuprofiling9).

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

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [hidebug.dumpJsHeapData](#hidebugdumpjsheapdata9).

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

## hidebug.getAppVMMemoryInfo<sup>12+<sup>

getAppVMMemoryInfo(): VMMemoryInfo

Obtains the memory info of application virutal machine.

**System capability** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type         | Description                                 |
| -------------| ---------------------------------------     |
| VMMemoryInfo | For details.see VMMemoryInfo                |

**Example**

  ```ts
let vmMemory: VMMemoryInfo = hidebug.getAppVMMemoryInfo();
hilog.info(0x0000, "example", "totalHeap = %{public}d", vmMemory.totalHeap);
hilog.info(0x0000, "example", "heapUsed = %{public}d", vmMemory.heapUsed);
hilog.info(0x0000, "example", "allArraySize = %{public}d", vmMemory.allArraySize);
  ```

## hidebug.getAppThreadCpuUsage<sup>12+<sup>

getAppThreadCpuUsage(): ThreadCpuUsage[]

Obtain CPU usage of application threads

**System capability** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type             | Description                                                       |
| -----------------| ------------------------------------------------------------------|
| ThreadCpuUsage[] | An array containing ThreadCpuUsage,For details.see ThreadCpuUsage |

**Example**

  ```ts
let appThreadCpuUsage = hidebug.getAppThreadCpuUsage();
for (let ii = 0; ii < appThreadCpuUsage.length; ii++) {
    hilog.info(0x0000, "example", "threadId=%{public}d, cpuUsage=%{public}f", appThreadCpuUsage[ii].threadId,
    appThreadCpuUsage[ii].cpuUsage);
}
  ```

## hidebug.startAppTraceCapture<sup>12+</sup>

startAppTraceCapture(tags : string[], flag: TraceFlag, limitSize: number) : string

Start application trace collection, startAppTraceCapture() method needs to correspond one-to-one with the call
to the stopCaptureAppTrace() method,Open first and then close. It is strictly prohibited to use sequences
such as' start ->start ->stop ',' start ->stop ->stop ',' start ->start ->stop ->stop '

**System capability** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Parameters**

| Name     | Type     | Mandatory | Description                                                                        |
| -------- | ------   | --------- | -----------------------------------------------------------------------------------|
| tags     | number[] | Yes       | The tag type of trace, specific tag types can be found below                       |
| flag     |TraceFlag | Yes       | Flag type of trace, MAIN_THREAD only collects trace from the main thread, ALL_THREAD collects all thread traces |
| limitSize| number   | Yes       | Enable trace file size limit in Bytes                                              |

**Return value**

| Type             | Description                                                       |
| -----------------| ------------------------------------------------------------------|
| string           | Return trace file name path                                       |

**Example**

```ts
let tags = [hidebug.tags.ABILITY_MANAGER, hidebug.tags.ACE];
let flag = hidebug.TraceFlag.MAIN_THREAD;
let limitSize = 1024 * 1024;
let fileName = hidebug.startAppTraceCapture(tags, flag, limitSize);
// code block
// ...
// code block
hidebug.stopAppTraceCapture();
```

## hidebug.stopAppTraceCapture<sup>12+</sup>

stopAppTraceCapture() : void

Stop application trace collection, startAppTraceCapture() method needs to correspond one-to-one with the call
to the stopAppTraceCapture() method,Open first and then close. It is strictly prohibited to use sequences
such as' start ->start ->stop ',' start ->stop ->stop ',' start ->start ->stop ->stop '

**System capability:** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Example**

```ts
let tags = [hidebug.tags.ABILITY_MANAGER, hidebug.tags.ACE];
let flag = hidebug.TraceFlag.MAIN_THREAD;
let limitSize = 1024 * 1024;
let fileName = hidebug.startAppTraceCapture(tags, flag, limitSize);
// code block
// ...
// code block
hidebug.stopAppTraceCapture();
```

## hidebug.getAppMemoryLimit<sup>12+</sup>

getAppMemoryLimit() : MemoryLimit

Get application process memory limit

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| [MemoryLimit](#memorylimit) | application process memory limit|

**Example**

```ts
 let appMemoryLimit:hidebug.MemoryLimit = hidebug.getAppMemoryLimit();
```
## MemoryLimit

application process memory limit

**System capability**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name      | Type   | Mandatory | Description         |
| --------- | ------ | ---- | ------------ |
| rssLimit    | bigint |  Yes  | the limit of the application process’s resident set, in bytes     |
| vssLimit  | bigint |  Yes  | the limit of the process’s virtual memory, in bytes       |
| vmHeapLimit | bigint |  Yes  | the limit of the js vm heap size of current thread, in bytes       |

## VMMemoryInfo

the memory info of application virtual machine

**System capability** SystemCapability.HiviewDFX.HiProfiler.HiDebug

| name               | Type    | Readable | Writable | Description                                        |
| -------------------| ------- | ---------| -------- | ---------------------------------------------------|
| totalHeap          | bigint  | Yes      | No       | heap total size of current virutal machine         |
| heapUsed           | bigint  | Yes      | No       | heap used size of current virutal machine          |
| allArraySize          | bigint  | Yes      | No       | all array object size of current virutal machine   |

## ThreadCpuUsage

Describe thread CPU usage

**System capability:** SystemCapability.HiviewDFX.HiProfiler.HiDebug

| Name               | Type    | Readable | Writable | Description                         |
| -------------------| ------- | -------- | -------- | ----------------------------------- |
| threadId           | number  | Yes      | No       | thread ID                           |
| cpuUsage           | number  | Yes      | No       | Thread CPU usage rate               |

## tags

Tag type constant describing trace

| Name                     | Type    |  Description                              |
| -------------------------| ------- |  ---------------------------------------- |
| ABILITY_MANAGER          | number  |  Ability Manager tag                      |
| ACE                      | number  |  ACE development framework tag            |
| ARK                      | number  |  ARK tag                                  |
| BLUETOOTH                | number  |  Bluetooth tag                            |
| COMMON_LIBRARY           | number  |  Common library subsystem tag             |
| DISTRIBUTED_HARDWARE_DEVICE_MANAGER           | number  |  Distributed hardware devicemanager tag   |
| DISTRIBUTED_AUDIO        | number  |  Distributed audio tag                    |
| DISTRIBUTED_CAMERA       | number  |  Distributed camera tag                   |
| DISTRIBUTED_DATA         | number  |  Distributed data manager module tag      |
| DISTRIBUTED_HARDWARE_FRAMEWORK | number  |  Distributed hardware fwk tag             |
| DISTRIBUTED_INPUT        | number  |  Distributed input tag                    |
| DISTRIBUTED_SCREEN       | number  |  Distributed screen tag                   |
| DISTRIBUTED_SCHEDULE     | number  |  Distributed schedule tag                 |
| FFRT                     | number  |  Ffrt tasks                               |
| FILE_MANAGEMENT          | number  |  File management tag                      |
| GLOBAL_RESOURCE_MANAGER  | number  |  Global resource manager tag              |
| GRAPHICS                 | number  |  Graphic module tag                       |
| HDF                      | number  |  HDF subsystem tag                        |
| MISC                     | number  |  MISC module tag                          |
| MUTIMODAL_INPUT          | number  |  Multimodal module tag                    |
| NET                      | number  |  Net tag                                  |
| NOTIFICATION             | number  |  Notification module tag                  |
| NWEB                     | number  |  NWeb tag                                 |
| OHOS                     | number  |  OHOS generic tag                         |
| POWER                    | number  |  Power manager tag                        |
| RPC                      | number  |  RPC and IPC tag                          |
| SAMGR                    | number  |  SA tag                                   |
| WINDOW_MANAGER           | number  |  Window manager tag                       |
| AUDIO                    | number  |  Audio module tag                         |
| CAMERA                   | number  |  Camera module tag                        |
| IMAGE                    | number  |  Image module tag                         |
| MEDIA                    | number  |  Media module tag                         |