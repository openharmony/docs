# @ohos.hidebug (Debug调试)

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

使用hidebug，可以获取应用内存的使用情况，包括应用进程的静态堆内存（native heap）信息、应用进程内存占用PSS（Proportional Set Size）信息等；可以完成虚拟机内存切片导出，虚拟机CPU Profiling采集等操作。

## 导入模块

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
```

## hidebug.getNativeHeapSize

getNativeHeapSize(): bigint

获取内存分配器统计的进程持有的堆内存大小（含分配器元数据）。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                        |
| ------ | --------------------------- |
| bigint | 内存分配器统计的进程持有的堆内存大小（含分配器元数据），单位为Byte。 |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapSize: bigint = hidebug.getNativeHeapSize();
```

## hidebug.getNativeHeapAllocatedSize

getNativeHeapAllocatedSize(): bigint

获取内存分配器统计的进程业务分配的堆内存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                              |
| ------ | --------------------------------- |
| bigint | 返回内存分配器统计的进程业务分配的堆内存大小，单位为Byte。 |


**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapAllocatedSize: bigint = hidebug.getNativeHeapAllocatedSize();
```

## hidebug.getNativeHeapFreeSize

getNativeHeapFreeSize(): bigint

获取内存分配器持有的缓存内存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                            |
| ------ | ------------------------------- |
| bigint | 返回内存分配器持有的缓存内存大小，单位为Byte。 |

**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapFreeSize: bigint = hidebug.getNativeHeapFreeSize();
```

## hidebug.getPss

getPss(): bigint

获取应用进程实际使用的物理内存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| bigint | 返回应用进程实际使用的物理内存大小，单位为KB。 |

**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let pss: bigint = hidebug.getPss();
```

## hidebug.getVss<sup>11+<sup>

getVss(): bigint

获取应用进程虚拟耗用内存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                                     |
| ------ | ---------------------------------------- |
| bigint | 返回应用进程虚拟耗用内存大小，单位为KB。 |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let vss: bigint = hidebug.getVss();
```

## hidebug.getSharedDirty

getSharedDirty(): bigint

获取进程的共享脏内存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| bigint | 返回进程的共享脏内存大小，单位为KB。 |


**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let sharedDirty: bigint = hidebug.getSharedDirty();
```

## hidebug.getPrivateDirty<sup>9+<sup>

getPrivateDirty(): bigint

获取进程的私有脏内存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| bigint | 返回进程的私有脏内存大小，单位为KB。 |

**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let privateDirty: bigint = hidebug.getPrivateDirty();
```

## hidebug.getCpuUsage<sup>9+<sup>

getCpuUsage(): number

获取进程的CPU使用率。

如占用率为50%，则返回0.5。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 获取进程的CPU使用率。 |


**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let cpuUsage: number = hidebug.getCpuUsage();
```

## hidebug.getServiceDump<sup>9+<sup>

getServiceDump(serviceid : number, fd : number, args : Array\<string>) : void

获取系统服务信息。

**需要权限**: ohos.permission.DUMP，仅系统应用可申请。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| serviceid | number | 是   | 基于该用户输入的service id获取系统服务信息。|
| fd | number | 是   | 文件描述符，该接口会往该fd中写入数据。|
| args | Array\<string> | 是   | 系统服务的Dump接口所对应的参数列表。|

**错误码：**

以下错误码的详细介绍请参见[Hidebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed,Possible causes:1.the parameter type error 2.the args parameter is not string array  |
| 11400101 | ServiceId invalid. The system ability does not exist.                                           |

**示例：**

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
    console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
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
    console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
fileIo.closeSync(file);
```

## hidebug.startJsCpuProfiling<sup>9+</sup>

startJsCpuProfiling(filename : string) : void

启动虚拟机Profiling方法跟踪，`startJsCpuProfiling()`方法的调用需要与`stopJsCpuProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | 是   | 用户自定义的profiling文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.json`文件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed,Parameter type error                        |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

停止虚拟机Profiling方法跟踪，`startJsCpuProfiling()`方法的调用需要与`stopJsCpuProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

虚拟机堆导出。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | 是   | 用户自定义的虚拟机堆文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.heapsnapshot`文件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed, Parameter type error                      |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  hidebug.dumpJsHeapData("heapData");
} catch (error) {
  console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.startProfiling<sup>(deprecated)</sup>

startProfiling(filename : string) : void

> **说明：**
> 从 API Version 9 开始废弃，建议使用[hidebug.startJsCpuProfiling](#hidebugstartjscpuprofiling9)替代。

启动虚拟机Profiling方法跟踪，`startProfiling()`方法的调用需要与`stopProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | 是   | 用户自定义的profiling文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.json`文件。 |

**示例：**

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

> **说明：**
> 从 API Version 9 开始废弃，建议使用[hidebug.stopJsCpuProfiling](#hidebugstopjscpuprofiling9)替代。

停止虚拟机Profiling方法跟踪，`stopProfiling()`方法的调用需要与`startProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**示例：**

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

> **说明：**
> 从 API Version 9 开始废弃，建议使用[hidebug.dumpJsHeapData](#hidebugdumpjsheapdata9)替代。

虚拟机堆导出。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| filename | string | 是   | 用户自定义的虚拟机堆文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.heapsnapshot`文件。 |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.dumpHeapData("heap-20220216");
```

## hidebug.getAppVMMemoryInfo<sup>12+</sup>

getAppVMMemoryInfo(): VMMemoryInfo

获取VM内存相关信息。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型         | 说明                                    |
| -------------| --------------------------------------- |
| [VMMemoryInfo](#vmmemoryinfo12) |  返回VM内存信息  |

**示例：**

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';

let vmMemory: hidebug.VMMemoryInfo = hidebug.getAppVMMemoryInfo();
hilog.info(0x0000, "example", "totalHeap = %{public}d", vmMemory.totalHeap);
hilog.info(0x0000, "example", "heapUsed = %{public}d", vmMemory.heapUsed);
hilog.info(0x0000, "example", "allArraySize = %{public}d", vmMemory.allArraySize);
```

## hidebug.getAppThreadCpuUsage<sup>12+</sup>

getAppThreadCpuUsage(): ThreadCpuUsage[]

获取应用线程CPU使用情况。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型             | 说明                                                        |
| -----------------| ------------------------------------------------------------|
| [ThreadCpuUsage](#threadcpuusage12)[] | 返回当前应用进程下所有ThreadCpuUsage数组 |



**示例：**

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';

let appThreadCpuUsage: hidebug.ThreadCpuUsage[] = hidebug.getAppThreadCpuUsage();
for (let ii = 0; ii < appThreadCpuUsage.length; ii++) {
    hilog.info(0x0000, "example", "threadId=%{public}d, cpuUsage=%{public}f", appThreadCpuUsage[ii].threadId,
    appThreadCpuUsage[ii].cpuUsage);
}
```

## hidebug.startAppTraceCapture<sup>12+</sup>

startAppTraceCapture(tags : number[], flag: TraceFlag, limitSize: number) : string

启动应用trace采集，'startAppTraceCapture()'方法的调用需要与'[stopAppTraceCapture()](#hidebugstopapptracecapture12)'方法的调用一一对应。

先开启后关闭，严禁使用'start->start->stop'，'start->stop->stop'，'start->start->stop->stop'等类似的顺序调用。

应用调用startAppTraceCapture接口启动采集trace，当采集的trace大小超过了limitSize，系统将自动调用stopAppTraceCapture接口停止采集，因此limitSize大小设置不当，将导致采集trace数据不足，无法满足故障分析。所以要求开发者根据实际情况，评估limitSize大小。

评估方法：limitSize = 预期trace采集时长 * trace单位流量。

预期trace采集时长：开发者根据分析的故障场景自行决定，单位秒。

trace单位流量：应用每秒产生的trace大小，系统推荐值为300Kb/s，建议开发者采用自身应用的实测值，单位Kb/秒。

trace单位流量实测方法：limitSize设置为最大值500M，调用startAppTraceCapture接口，在应用上操作N秒后，调用stopAppTraceCapture停止采集，然后查看trace大小S Kb。那么trace单位流量 = S/N。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                                                  |
| -------- | ------   | ---- | ------------------------------------------------------------------------------------- |
| tags     | number[] | 是   | 详情请见[tags](#tags12)                                                      |
| flag     | TraceFlag| 是   | 详情请见[TraceFlag](#traceflag12)          |
| limitSize| number   | 是   | 开启trace文件大小限制，单位为Byte，单个文件大小上限为500MB                                                       |

**返回值：**

| 类型             | 说明                                           |
| -----------------| -----------------------------------------------|
| string           | 返回trace文件名路径                            |

**错误码：**

以下错误码的详细介绍请参见[Hidebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small 2.The parameter is not within the enumeration type 3.The parameter type error or parameter order error|
| 11400102 | Capture trace already enabled.                                         |
| 11400103 | No write permission on the file.                                |
| 11400104 | Abnormal trace status.                                 |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

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

停止应用trace采集，在停止采集前，需要通过'[startAppTraceCapture()](#hidebugstartapptracecapture12)'方法开始采集。

先开启后关闭，严禁使用'start->start->stop'，'start->stop->stop'，'start->start->stop->stop'等类似的顺序调用。

调用startAppTraceCapture接口，如果没有合理传入limitSize参数，生成trace的大小大于传入的limitSize大小，系统内部会自动调用stopAppTraceCapture，再次手动调用stopAppTraceCapture就会抛出错误码11400105。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**错误码：**

以下错误码的详细介绍请参见[Hidebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | The status of the trace is abnormal                                |
| 11400105 |   No capture trace running                                       |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

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

获取应用程序进程内存限制。

**系统能力**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**

| 类型  | 说明                      |
| ------ | -------------------------- |
| [MemoryLimit](#memorylimit12) | 应用程序进程内存限制|

**示例**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let appMemoryLimit:hidebug.MemoryLimit = hidebug.getAppMemoryLimit();
```

## hidebug.getSystemCpuUsage<sup>12+</sup>

getSystemCpuUsage() : number

获取系统的CPU资源占用情况。

例如，当系统资源CPU占用为 **50%**，将返回**0.5**。

**系统能力**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**

| 类型     | 说明          |
|--------|-------------|
| number | 系统CPU资源占用情况。|

**错误码：**

以下错误码的详细介绍请参见[Hidebug-CpuUsage错误码](errorcode-hiviewdfx-hidebug-cpuusage.md)。

| 错误码ID | 错误信息                                            |
| ------- |-------------------------------------------------|
| 11400104 | The status of the system CPU usage is abnormal. |

**示例**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let cpuUsage: number = hidebug.getSystemCpuUsage();
```

## hidebug.setAppResourceLimit<sup>12+</sup>

setAppResourceLimit(type: string, value: number, enableDebugLog: boolean) : void

设置应用的fd数量、线程数量、js内存或者native内存资源限制。
**注意：** 当设置的开发者选项开关打开时,此功能有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                         |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type | string |  是  | 泄漏资源类型，共四种类型:pss_memory(native内存)、js_heap(js堆内存)、fd(文件描述符)或thread(线程) |
| value | number |  是  | 对应泄漏资源类型的最大值。范围：pss_memory类型`[1024, 4 * 1024 * 1024](单位：KB)`, js_heap类型`[85, 95](分配给JS堆内存上限的85%~95%)`, fd类型`[10, 10000]`, thread类型`[1, 1000]` |
| enableDebugLog | boolean |  是  | 是否启用外部调试日志，默认值为false，请仅在灰度版本中设置为true，因为收集调试日志会花费太多的cpu或内存 |

**错误码：**

以下错误码的详细介绍请参见[Hidebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small 2.The parameter is not in the specified type 3.The parameter type error or parameter order error  |
| 11400104 | Set limit failed due to remote exception |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let type: string = 'js_heap';
let value: number = 85;
let enableDebugLog: boolean = false;
hidebug.setAppResourceLimit(type, value, enableDebugLog);
```

## hidebug.getAppNativeMemInfo<sup>12+</sup>

getAppNativeMemInfo(): NativeMemInfo

获取应用进程内存信息。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型  | 说明                      |
| ------ | -------------------------- |
| [NativeMemInfo](#nativememinfo12) | 应用进程内存信息|

**示例**

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';

let nativeMemInfo: hidebug.NativeMemInfo = hidebug.getAppNativeMemInfo();

hilog.info(0x0000, 'testTag', "pss = %{public}d", nativeMemInfo.pss);

hilog.info(0x0000, 'testTag', "vss = %{public}d", nativeMemInfo.vss);

hilog.info(0x0000, 'testTag', "rss = %{public}d", nativeMemInfo.rss);

hilog.info(0x0000, 'testTag', "sharedDirty = %{public}d", nativeMemInfo.sharedDirty);

hilog.info(0x0000, 'testTag', "privateDirty = %{public}d", nativeMemInfo.privateDirty);

hilog.info(0x0000, 'testTag', "sharedClean = %{public}d", nativeMemInfo.sharedClean);

hilog.info(0x0000, 'testTag', "privateClean = %{public}d", nativeMemInfo.privateClean);
```

## hidebug.getSystemMemInfo<sup>12+</sup>

getSystemMemInfo(): SystemMemInfo

获取系统内存信息。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型  | 说明                      |
| ------ | -------------------------- |
| [SystemMemInfo](#systemmeminfo12) | 系统内存信息|

**示例**

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';

let systemMemInfo: hidebug.SystemMemInfo = hidebug.getSystemMemInfo();

hilog.info(0x0000, 'testTag', "totalMem = %{public}d", systemMemInfo.totalMem);

hilog.info(0x0000, 'testTag', "freeMem = %{public}d", systemMemInfo.freeMem);

hilog.info(0x0000, 'testTag', "availableMem = %{public}d", systemMemInfo.availableMem);
```

## hidebug.getVMRuntimeStats<sup>12+</sup>

getVMRuntimeStats(): GcStats

获取系统gc全部统计信息。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型                    | 说明       |
|-----------------------|----------|
| [GcStats](#gcstats12) | 系统GC统计信息。 |

**示例**

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';

let vMRuntimeStats: hidebug.GcStats = hidebug.getVMRuntimeStats();
hilog.info(0x0000, "testTag", `gc-count: ${vMRuntimeStats['ark.gc.gc-count']}`);
hilog.info(0x0000, "testTag", `gc-time: ${vMRuntimeStats['ark.gc.gc-time']}`);
hilog.info(0x0000, "testTag", `gc-bytes-allocated: ${vMRuntimeStats['ark.gc.gc-bytes-allocated']}`);
hilog.info(0x0000, "testTag", `gc-bytes-freed: ${vMRuntimeStats['ark.gc.gc-bytes-freed']}`);
hilog.info(0x0000, "testTag", `fullgc-longtime-count: ${vMRuntimeStats['ark.gc.fullgc-longtime-count']}`);
```

## hidebug.getVMRuntimeStat<sup>12+</sup>

getVMRuntimeStat(item : string): number

根据参数获取指定的系统gc统计信息。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明          |
| -------- | ------ | ---- |-------------|
| item | string | 是   | 需要获取GC信息的类型。 |

| 输入参数                         | 返回值说明          |
|------------------------------|----------------|
| ark.gc.gc-count | 当前线程的GC次数。     |
| ark.gc.gc-time | 当前线程触发的GC总耗时，以ms为单位。 |
| ark.gc.gc-bytes-allocated | 当前线程Ark虚拟机已分配的内存大小，以B为单位。|
| ark.gc.gc-bytes-freed | 当前线程GC成功回收的内存，以B为单位。 |
| ark.gc.fullgc-longtime-count | 当前线程超长fullGC次数。 |

**错误码：**

| 错误码ID | 错误信息                                                                                                       |
| ------- |------------------------------------------------------------------------------------------------------------|
| 401 | Possible causes:1. Invalid parameter, a string parameter required. 2. Invalid parameter, unknown property. |

**示例**

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';

hilog.info(0x0000, "testTag", `gc-count: ${hidebug.getVMRuntimeStat('ark.gc.gc-count')}`);
hilog.info(0x0000, "testTag", `gc-time: ${hidebug.getVMRuntimeStat('ark.gc.gc-time')}`);
hilog.info(0x0000, "testTag", `gc-bytes-allocated: ${hidebug.getVMRuntimeStat('ark.gc.gc-bytes-allocated')}`);
hilog.info(0x0000, "testTag", `gc-bytes-freed: ${hidebug.getVMRuntimeStat('ark.gc.gc-bytes-freed')}`);
hilog.info(0x0000, "testTag", `fullgc-longtime-count: ${hidebug.getVMRuntimeStat('ark.gc.fullgc-longtime-count')}`);
```

## MemoryLimit<sup>12+</sup>

应用程序进程内存限制。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称      | 类型   | 必填 | 说明         |
| --------- | ------ | ---- | ------------ |
| rssLimit    | bigint |  是  | 应用程序进程的驻留集的限制，以KB为单位     |
| vssLimit  | bigint |  是  | 进程的虚拟内存限制，以KB为单位       |
| vmHeapLimit | bigint |  是  | 当前线程的 JS VM 堆大小限制，以KB为单位      |
| vmTotalHeapSize | bigint |  是  | 当前进程的 JS 堆内存大小限制，以KB为单位      |

## VMMemoryInfo<sup>12+</sup>

描述VM内存信息。

**系统能力:** 以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称               | 类型    | 可读 | 可写 | 说明                                |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| totalHeap          | bigint  | 是   | 否   | 表示当前虚拟机的堆总大小，以KB为单位    |
| heapUsed           | bigint  | 是   | 否   | 表示当前虚拟机使用的堆大小，以KB为单位  |
| allArraySize       | bigint  | 是   | 否   | 表示当前虚拟机的所有数组对象大小，以KB为单位 |

## ThreadCpuUsage<sup>12+</sup>

描述线程CPU使用情况。

**系统能力:** 以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称               | 类型    | 可读 | 可写 | 说明                                |
| -------------------| ------- | ---- | ---- | ----------------------------------- |
| threadId           | number  | 是   | 否   | 线程号                           |
| cpuUsage           | number  | 是   | 否   | 线程CPU使用率                       |

## tags<sup>12+</sup>

描述支持/使用场景标签。

**系统能力:** 以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称                     | 类型    |  说明                                |
| -------------------------| ------- |  ----------------------------------- |
| ABILITY_MANAGER          | number  |  能力管理标签                         |
| ARKUI                    | number  |  ArkUI开发框架标签                    |
| ARK                      | number  |  JSVM虚拟机标签                       |
| BLUETOOTH                | number  |  蓝牙标签                            |
| COMMON_LIBRARY           | number  |  公共库子系统标签                     |
| DISTRIBUTED_HARDWARE_DEVICE_MANAGER | number  |  分布式硬件设备管理标签     |
| DISTRIBUTED_AUDIO        | number  |        分布式音频标签                 |
| DISTRIBUTED_CAMERA       | number  |  分布式相机标签                       |
| DISTRIBUTED_DATA         | number  |  分布式数据管理模块标签                |
| DISTRIBUTED_HARDWARE_FRAMEWORK | number  |  分布式硬件框架标签              |
| DISTRIBUTED_INPUT        | number  |  分布式输入标签                       |
| DISTRIBUTED_SCREEN       | number  |  分布式屏幕标签                       |
| DISTRIBUTED_SCHEDULER    | number  |  分布式调度器标签                     |
| FFRT                     | number  |  FFRT任务标签.                        |
| FILE_MANAGEMENT          | number  |  文件管理系统标签                     |
| GLOBAL_RESOURCE_MANAGER  | number  |  全局资源管理标签                     |
| GRAPHICS                 | number  |  图形模块标签                        |
| HDF                      | number  |  HDF子系统标签                       |
| MISC                     | number  |  MISC模块标签                        |
| MULTIMODAL_INPUT         | number  |  多模态输入模块标签                   |
| NET                      | number  |  网络标签                             |
| NOTIFICATION             | number  |  通知模块标签                         |
| NWEB                     | number  |  Nweb标签                            |
| OHOS                     | number  |  OHOS通用标签                         |
| POWER_MANAGER            | number  |  电源管理标签                         |
| RPC                      | number  |  RPC标签                             |
| SAMGR                    | number  |  系统能力管理标签                     |
| WINDOW_MANAGER           | number  |  窗口管理标签                         |
| AUDIO                    | number  |  音频模块标签                        |
| CAMERA                   | number  |  相机模块标签                        |
| IMAGE                    | number  |  图片模块标签                        |
| MEDIA                    | number  |  媒体模块标签                        |

## NativeMemInfo<sup>12+</sup>

描述应用进程内存信息。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称      | 类型   | 必填 | 说明         |
| --------- | ------ | ---- | ------------ |
| pss  | bigint |  是  | 实际占用的物理内存的大小(比例分配共享库占用的内存)，以KB为单位     |
| vss  | bigint |  是  | 占用虚拟内存大小(包括共享库所占用的内存)，以KB为单位       |
| rss  | bigint |  是  | 实际占用的物理内存的大小(包括共享库占用)，以KB为单位         |
| sharedDirty  | bigint |  是  | 共享脏内存的大小，以KB为单位      |
| privateDirty  | bigint |  是  | 专用脏内存的大小，以KB为单位      |
| sharedClean  | bigint |  是  | 共享干净内存的大小，以KB为单位      |
| privateClean  | bigint |  是  | 专用干净内存的大小，以KB为单位      |

## SystemMemInfo<sup>12+</sup>

描述系统内存信息。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称      | 类型   | 必填 | 说明         |
| --------- | ------ | ---- | ------------ |
| totalMem  | bigint |  是  | 系统总的内存，以KB为单位     |
| freeMem  | bigint |  是  | 系统空闲的内存，以KB为单位       |
| availableMem  | bigint |  是  | 系统可用的内存，以KB为单位      |

## TraceFlag<sup>12+</sup>

描述采集trace线程的类型。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称                         | 值 | 说明                    |
| --------------------------- |---| ----------------------- |
| MAIN_THREAD                 | 1 | 只采集当前应用主线程。|
| ALL_THREADS                 | 2 | 采集当前应用下所有线程。 |

## GcStats<sup>12+</sup>

type GcStats = Record&lt;string, number&gt;

用于存储GC统计信息的键值对。该类型不是多线程安全的，如果应用中存在多线程同时操作该类派生出的实例，注意加锁保护。

**系统能力：**  SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 类型      | 说明                          |
| -----------| ---------------------------- |
| Record&lt;string, number&gt;     | 表示值类型为Record键值对。     |

其中GcStats中可包含的键值信息如下：

| 参数名                     | 类型   | 说明                      |
|-------------------------| ------ |------------------------- |
| ark.gc.gc-count         | number |  当前线程的GC次数。|
| ark.gc.gc-time          | number |  当前线程触发的GC总耗时，以ms为单位。 |
| ark.gc.gc-bytes-allocated | number | 当前线程Ark虚拟机已分配的内存大小，以B为单位。 |
| ark.gc.gc-bytes-freed   | number | 当前线程GC成功回收的内存，以B为单位。|
| ark.gc.fullgc-longtime-count | number |  当前线程超长fullGC次数。 |

## hidebug.isDebugState<sup>12+</sup>

isDebugState(): boolean

获取应用进程被调试状态，如果应用进程的ark层或者native层处于被调试状态，则返回true，否则返回false。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型  | 说明                      |
| ------ | -------------------------- |
| boolean | 应用进程被调试状态|

**示例**

```ts
import { hidebug,hilog } from '@kit.PerformanceAnalysisKit';

hilog.info(0x000, "testTag", "isDebugState = %{public}s", hidebug.isDebugState())
```

## hidebug.getGraphicsMemory<sup>14+</sup>

getGraphicsMemory(): Promise&lt;number&gt;

使用异步方式，获取应用显存大小。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型                    | 说明                           |
|-----------------------|------------------------------|
| Promise&lt;number&gt; | promise对象，调用结束后返回应用显存大小，单位KB |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | Failed to get the application memory due to a remote exception. |

**示例**

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

hidebug.getGraphicsMemory().then((ret: number) => {
    hilog.info(0x000, "testTag", `graphicsMemory: ${ret}`)
}).catch((error: BusinessError) => {
    hilog.info(0x000, "testTag", `error code: ${error.code}, error msg: ${error.message}`);
})
```

## hidebug.getGraphicsMemorySync<sup>14+</sup>

getGraphicsMemorySync(): number

使用同步方式，获取应用显存大小。

**注意：** 该接口涉及多次跨进程通信，可能存在性能问题，推荐使用异步接口getGraphicsMemory。

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型  | 说明         |
| ------ |------------|
| number | 应用显存大小（KB） |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | Failed to get the application memory due to a remote exception. |

**示例**

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    hilog.info(0x000, "testTag", `graphicsMemory: ${hidebug.getGraphicsMemorySync()}`)
} catch (error) {
    hilog.info(0x000, "testTag", `error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```