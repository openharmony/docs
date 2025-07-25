# @ohos.hidebug (Debug调试)

为应用提供多种以供调试、调优的方法。包括但不限于内存、CPU、GPU、GC等相关数据的获取，进程trace、profiler采集，VM堆快照转储等。由于该模块的接口大多比较耗费性能，接口调用较为耗时，且基于HiDebug模块定义，该模块内的接口仅建议在应用调试、调优阶段使用。若需要在其他场景使用时，请认真评估所需调用的接口对应用性能的影响。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
```

## hidebug.getNativeHeapSize

getNativeHeapSize(): bigint

获取内存分配器统计的进程持有的普通块所占用的总字节数。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                                         |
| ------ |--------------------------------------------|
| bigint | 内存分配器统计的进程持有的普通块所占用内存的大小（含分配器元数据），单位为Byte。 |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapSize: bigint = hidebug.getNativeHeapSize();
```

## hidebug.getNativeHeapAllocatedSize

getNativeHeapAllocatedSize(): bigint

获取内存分配器统计的进程持有的已使用的普通块所占用的总字节数。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                              |
| ------ | --------------------------------- |
| bigint | 返回内存分配器统计的进程持有的已使用的普通块所占用内存大小，单位为Byte。 |


**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapAllocatedSize: bigint = hidebug.getNativeHeapAllocatedSize();
```

## hidebug.getNativeHeapFreeSize

getNativeHeapFreeSize(): bigint

获取内存分配器统计的进程持有的空闲的普通块所占用的总字节数。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                            |
| ------ | ----------------------------- |
| bigint | 返回内存分配器统计的进程持有的空闲的普通块所占用内存大小，单位为Byte。 |

**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapFreeSize: bigint = hidebug.getNativeHeapFreeSize();
```

## hidebug.getPss

getPss(): bigint

获取应用进程实际使用的物理内存大小。接口实现方式：读取/proc/{pid}/smaps_rollup节点中的Pss与SwapPss值并求和。

> **注意：**
> 
> 由于/proc/{pid}/smaps_rollup的读取耗时较长，建议不要在主线程中使用该接口，可通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程以避免应用出现卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| bigint | 返回应用进程实际使用的物理内存大小，单位为KB。 |

**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let pss: bigint = hidebug.getPss();
```

## hidebug.getVss<sup>11+</sup>

getVss(): bigint

获取应用进程虚拟耗用内存大小。接口实现方式：读取/proc/{pid}/statm节点中的size值（内存页数），vss = size * 页大小（4K/页）。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

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

获取进程的共享脏内存大小。接口实现方式：读取/proc/{pid}/smaps_rollup节点中的Shared_Dirty值。

> **注意：**
> 
> 由于/proc/{pid}/smaps_rollup的读取耗时较长，建议不要在主线程中使用该接口，可通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程以避免应用出现卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| bigint | 返回进程的共享脏内存大小，单位为KB。 |


**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let sharedDirty: bigint = hidebug.getSharedDirty();
```

## hidebug.getPrivateDirty<sup>9+</sup>

getPrivateDirty(): bigint

获取进程的私有脏内存大小。读取/proc/{pid}/smaps_rollup中的Private_Dirty值。

> **注意：**
>
> 由于/proc/{pid}/smaps_rollup的读取耗时较长，建议不要在主线程中使用该接口，可通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程以避免应用出现卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| bigint | 返回进程的私有脏内存大小，单位为KB。 |

**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let privateDirty: bigint = hidebug.getPrivateDirty();
```

## hidebug.getCpuUsage<sup>9+</sup>

getCpuUsage(): number

获取进程的CPU使用率。

如占用率为50%，则返回0.5。

> **注意：**
>
> 由于该接口涉及跨进程通信，耗时较长，为了避免引入性能问题，建议不要在主线程中直接调用该接口。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 获取进程的CPU使用率。 |


**示例：**
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let cpuUsage: number = hidebug.getCpuUsage();
```

## hidebug.getServiceDump<sup>9+</sup>

getServiceDump(serviceid: number, fd: number, args: Array\<string>) : void

获取系统服务信息。

**需要权限**：ohos.permission.DUMP，仅系统应用可申请。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                         |
| -------- | ------ | ---- |----------------------------|
| serviceid | number | 是   | 基于用户输入的service id获取系统服务信息。 |
| fd | number | 是   | 文件描述符，接口会向该fd写入数据。         |
| args | Array&lt;string&gt; | 是   | 系统服务的dump接口参数列表。           |

**错误码：**

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed,Possible causes:1.the parameter type error 2.the args parameter is not string array.  |
| 11400101 | ServiceId invalid. The system ability does not exist.                                           |

**示例：**

<!--code_no_check-->
```ts
import { fileIo } from '@kit.CoreFileKit';
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let fileFd = -1;
try {
  // 请在组件内获取context，确保this.getUiContext().getHostContext()返回结果为UIAbilityContext。
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

启动虚拟机Profiling方法跟踪，`startJsCpuProfiling(filename: string)`方法的调用需要与`stopJsCpuProfiling()`方法的调用一一对应，先开启后关闭，请避免重复开启或重复关闭的调用方式，否则会接口调用异常。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                               |
| -------- | ------ | ---- |--------------------------------------------------|
| filename | string | 是   | 用户自定义的采样结果输出的文件名，将在应用的`files`目录下生成以该参数命名的json文件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed,Parameter type error.                        |

**示例：**

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

停止虚拟机Profiling方法跟踪，`stopJsCpuProfiling()`方法的调用需要与`startJsCpuProfiling(filename: string)`方法的调用一一对应，先开启后关闭，请避免重复开启或重复关闭的调用方式，否则会接口调用异常。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**示例：**

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

虚拟机堆导出。

> **注意：**
>
> 由于虚拟机堆导出极其耗时，且该接口为同步接口，建议不要在上架版本中调用该接口，以避免应用卡死，影响用户体验。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                            |
| -------- | ------ | ---- | ----------------------------------------------- |
| filename | string | 是   | 用户自定义的采样结果输出的文件名，将在应用的`files`目录下生成以该参数命名的heapsnapshot文件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | the parameter check failed, Parameter type error.                      |

**示例：**

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

> **说明：**
> 
> 从 API Version 9 开始废弃，建议使用[hidebug.startJsCpuProfiling](#hidebugstartjscpuprofiling9)替代。

启动虚拟机Profiling方法跟踪，`startProfiling(filename: string)`方法的调用需要与`stopProfiling()`方法的调用一一对应，先开启后关闭，请避免重复开启或重复关闭的调用方式，否则会接口调用异常。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                             |
| -------- | ------ | ---- | ------------------------------------------------ |
| filename | string | 是   | 用户自定义的采样结果输出的文件名，将在应用的`files`目录下生成以该参数命名的json文件。 |

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
> 
> 从 API Version 9 开始废弃，建议使用[hidebug.stopJsCpuProfiling](#hidebugstopjscpuprofiling9)替代。

停止虚拟机Profiling方法跟踪，`stopProfiling()`方法的调用需要与`startProfiling(filename: string)`方法的调用一一对应，先开启后关闭，请避免重复开启或重复关闭的调用方式，否则会接口调用异常。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

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

dumpHeapData(filename: string) : void

> **说明：**
> 
> 从 API Version 9 开始废弃，建议使用[hidebug.dumpJsHeapData](#hidebugdumpjsheapdata9)替代。

虚拟机堆导出，生成`filename.heapsnapshot`文件。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                      |
| -------- | ------ | ---- |---------------------------------------------------------|
| filename | string | 是   | 用户自定义的虚拟机堆转储文件名，将在应用的`files`目录下生成以该参数命名的heapsnapshot文件。 |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.dumpHeapData("heap-20220216");
```

## hidebug.getAppVMMemoryInfo<sup>12+</sup>

getAppVMMemoryInfo(): VMMemoryInfo

获取VM内存相关信息。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型         | 说明                                    |
| -------------| --------------------------------------- |
| [VMMemoryInfo](#vmmemoryinfo12) | 返回VM内存信息。 |

**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let vmMemory: hidebug.VMMemoryInfo = hidebug.getAppVMMemoryInfo();
console.info(`totalHeap = ${vmMemory.totalHeap}, heapUsed = ${vmMemory.heapUsed},` +
  `allArraySize = ${vmMemory.allArraySize}` );
```

## hidebug.getAppThreadCpuUsage<sup>12+</sup>

getAppThreadCpuUsage(): ThreadCpuUsage[]

获取应用线程CPU使用情况。

> **注意：**
>
> 由于该接口涉及跨进程通信，耗时较长，为了避免引入性能问题，建议不要在主线程中直接调用该接口。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型             | 说明                                                        |
| -----------------| ------------------------------------------------------------|
| [ThreadCpuUsage](#threadcpuusage12)[] | 返回当前应用进程下所有ThreadCpuUsage数组。 |



**示例：**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let appThreadCpuUsage: hidebug.ThreadCpuUsage[] = hidebug.getAppThreadCpuUsage();
for (let i = 0; i < appThreadCpuUsage.length; i++) {
  console.info(`threadId=${appThreadCpuUsage[i].threadId}, cpuUsage=${appThreadCpuUsage[i].cpuUsage}`);
}
```

## hidebug.startAppTraceCapture<sup>12+</sup>

startAppTraceCapture(tags: number[], flag: TraceFlag, limitSize: number) : string

该接口补充了[hitrace](../../dfx/hitrace.md)功能，开发者可通过该接口完成指定范围的trace自动化采集。由于该接口中trace采集过程中消耗的性能与需要采集的范围成正相关，建议开发者在使用该接口前，通过hitrace命令抓取应用的trace日志，从中筛选出所需trace采集的关键范围，以提高该接口性能。

`startAppTraceCapture()`方法的调用需要与'[stopAppTraceCapture()](#hidebugstopapptracecapture12)'方法的调用一一对应，重复开启trace采集将导致接口调用异常，由于trace采集过程中会消耗较多性能，开发者应在完成采集后及时关闭。

应用调用startAppTraceCapture接口启动采集trace，当采集的trace大小超过了limitSize，系统将自动调用stopAppTraceCapture接口停止采集。因此limitSize大小设置不当，将导致生成trace数据不足，无法满足故障分析。所以要求开发者根据实际情况，评估limitSize大小。

评估方法：limitSize = 预期trace采集时长 * trace单位流量。

预期trace采集时长：开发者根据分析的故障场景自行决定，单位秒。

trace单位流量：应用每秒产生的trace大小，系统推荐值为300Kb/s，建议开发者采用自身应用的实测值，单位Kb/s。

trace单位流量实测方法：limitSize设置为最大值500M，调用startAppTraceCapture接口，在应用上操作N秒后，调用stopAppTraceCapture停止采集，然后查看trace大小S（Kb）。那么trace单位流量 = S/N（Kb/s）。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型     | 必填 | 说明                                 |
| -------- | ------   | ---- |------------------------------------|
| tags     | number[] | 是   | trace范围，详情请见[tags](#hidebugtags12)。   |
| flag     | TraceFlag| 是   | 详情请见[TraceFlag](#traceflag12)。        |
| limitSize| number   | 是   | 开启trace文件大小限制，单位为Byte，单个文件大小上限为500MB。 |

**返回值：**

| 类型             | 说明            |
| -----------------|---------------|
| string           | 返回trace文件名路径。 |

**错误码：**

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small 2.The parameter is not within the enumeration type 3.The parameter type error or parameter order error. |
| 11400102 | Capture trace already enabled.                                         |
| 11400103 | No write permission on the file.                                |
| 11400104 | Abnormal trace status.                                 |

**示例：**

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

停止应用trace采集。调用前，需先调用'[startAppTraceCapture()](#hidebugstartapptracecapture12)'方法开始采集。关闭前未开启或重复关闭会导致接口异常。

调用startAppTraceCapture接口，如果没有合理传入limitSize参数，生成trace的大小大于传入的limitSize大小，系统内部会自动调用stopAppTraceCapture，再次手动调用stopAppTraceCapture就会抛出错误码11400105。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**错误码：**

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | The status of the trace is abnormal.                                |
| 11400105 | No capture trace running.                                       |

**示例：**

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

获取应用程序进程的内存限制。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型  | 说明                      |
| ------ | -------------------------- |
| [MemoryLimit](#memorylimit12) | 应用程序进程内存限制。 |

**示例**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let appMemoryLimit:hidebug.MemoryLimit = hidebug.getAppMemoryLimit();
```

## hidebug.getSystemCpuUsage<sup>12+</sup>

getSystemCpuUsage() : number

获取系统的CPU资源占用情况。

例如，当系统资源CPU占用为50%时，将返回0.5。

> **注意：**
>
> 由于该接口涉及跨进程通信，耗时较长，为了避免引入性能问题，建议不要在主线程中直接调用该接口。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型     | 说明          |
|--------|-------------|
| number | 系统CPU资源占用情况。|

**错误码：**

以下错误码的详细介绍请参见[HiDebug-CpuUsage错误码](errorcode-hiviewdfx-hidebug-cpuusage.md)。

| 错误码ID | 错误信息                                            |
| ------- |-------------------------------------------------|
| 11400104 | The status of the system CPU usage is abnormal. |

**示例**
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

设置应用的文件描述符数量、线程数量、JS内存或Native内存资源限制。

主要应用场景在于构造内存泄漏故障，参见[订阅资源泄漏事件（ArkTS）](../../dfx/hiappevent-watcher-resourceleak-events-arkts.md)、[订阅资源泄漏事件（C/C++）](../../dfx/hiappevent-watcher-resourceleak-events-ndk.md)。

> **注意：**
>
> 当设置的开发者选项开关打开并重启设备后，此功能有效。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明                                                                                                                                                                      |
| -------- | ------ | ---- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| type | string |  是  | 泄漏资源类型，共四种：<br/>- pss_memory（native内存）<br/>- js_heap（js堆内存）<br/>- fd（文件描述符）<br/>- thread（线程）                                                                            |
| value | number |  是  | 对应泄漏资源类型的最大值，范围：<br/>- pss_memory类型：`[1024, 4 * 1024 * 1024]`（单位：KB）<br/>- js_heap类型：`[85, 95]`（分配给JS堆内存上限的85%~95%）<br/>- fd类型：`[10, 10000]`<br/>- thread类型：`[1, 1000]` |
| enableDebugLog | boolean |  是  | 是否启用外部调试日志。外部调试日志请仅在灰度版本（正式版本发布之前，先向一小部分用户推出的测试版本）中启用，因为收集调试日志会占用大量的cpu资源和内存资源，可能会引起应用流畅性问题。<br/>true：启用外部调试日志。<br/>false：禁用外部调试日志。                                     |

**错误码：**

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small 2.The parameter is not in the specified type 3.The parameter type error or parameter order error.  |
| 11400104 | Set limit failed due to remote exception. |

**示例：**

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

获取应用进程内存信息。读取/proc/{pid}/smaps_rollup和/proc/{pid}/statm节点的数据。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

> **注意：**
>
> 由于读取/proc/{pid}/smaps_rollup耗时较长，推荐使用异步接口[hidebug.getAppNativeMemInfoAsync](#hidebuggetappnativememinfoasync20)，以避免应用丢帧或卡顿。

**返回值：**

| 类型  | 说明                      |
| ------ | -------------------------- |
| [NativeMemInfo](#nativememinfo12) | 应用进程内存信息。 |

**示例**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeMemInfo: hidebug.NativeMemInfo = hidebug.getAppNativeMemInfo();
console.info(`pss: ${nativeMemInfo.pss}, vss: ${nativeMemInfo.vss}, rss: ${nativeMemInfo.rss}, ` +
  `sharedDirty: ${nativeMemInfo.sharedDirty}, privateDirty: ${nativeMemInfo.privateDirty}, ` +
  `sharedClean: ${nativeMemInfo.sharedClean}, privateClean: ${nativeMemInfo.privateClean}`);
```

## hidebug.getAppNativeMemInfoAsync<sup>20+</sup>

getAppNativeMemInfoAsync(): Promise&lt;NativeMemInfo&gt;

使用异步方式获取应用进程内存信息。读取/proc/{pid}/smaps_rollup和/proc/{pid}/statm节点的数据。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型                                               | 说明                      |
|--------------------------------------------------| -------------------------- |
| Promise&lt;[NativeMemInfo](#nativememinfo12)&gt; | promise对象，调用结束后返回应用进程内存信息。 |

**示例**

```ts
hidebug.getAppNativeMemInfoAsync().then((nativeMemInfo: hidebug.NativeMemInfo)=>{
  console.info(`pss: ${nativeMemInfo.pss}, vss: ${nativeMemInfo.vss}, rss: ${nativeMemInfo.rss}, ` +
    `sharedDirty: ${nativeMemInfo.sharedDirty}, privateDirty: ${nativeMemInfo.privateDirty}, ` +
    `sharedClean: ${nativeMemInfo.sharedClean}, privateClean: ${nativeMemInfo.privateClean}`);
});
```

## hidebug.getAppNativeMemInfoWithCache<sup>20+</sup>

getAppNativeMemInfoWithCache(forceRefresh?: boolean): NativeMemInfo

获取应用进程内存信息。与`getAppNativeMemInfo`接口相比，该接口使用了缓存机制，以提高性能。缓存的有效期为5分钟。

> **注意：**
>
> 由于读取 `/proc/{pid}/smaps_rollup` 比较耗时，建议不在主线程中使用该接口。可以通过 `@ohos.taskpool` 或 `@ohos.worker` 开启异步线程，以避免应用卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名                     | 类型      | 必填 | 说明                                                                                                     |
|-------------------------|---------|----|--------------------------------------------------------------------------------------------------------|
| forceRefresh         | boolean | 否  | 是否需要无视缓存有效性，强制更新缓存值。默认值：false。</br>true：直接获取当前内存数据并更新缓存值。</br>false：缓存有效时，直接返回缓存值，缓存失效时获取当前内存数据并更新缓存值。 |

**返回值：**

| 类型  | 说明                      |
| ------ | -------------------------- |
| [NativeMemInfo](#nativememinfo12) | 应用进程内存信息。 |

**示例**

```ts
let nativeMemInfo: hidebug.NativeMemInfo = hidebug.getAppNativeMemInfoWithCache();
console.info(`pss: ${nativeMemInfo.pss}, vss: ${nativeMemInfo.vss}, rss: ${nativeMemInfo.rss}, ` +
  `sharedDirty: ${nativeMemInfo.sharedDirty}, privateDirty: ${nativeMemInfo.privateDirty}, ` +
  `sharedClean: ${nativeMemInfo.sharedClean}, privateClean: ${nativeMemInfo.privateClean}`);
```

## hidebug.getSystemMemInfo<sup>12+</sup>

getSystemMemInfo(): SystemMemInfo

获取系统内存信息。读取/proc/meminfo节点的数据。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型  | 说明                      |
| ------ | -------------------------- |
| [SystemMemInfo](#systemmeminfo12) | 系统内存信息。 |

**示例**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let systemMemInfo: hidebug.SystemMemInfo = hidebug.getSystemMemInfo();

console.info(`totalMem: ${systemMemInfo.totalMem}, freeMem: ${systemMemInfo.freeMem}, ` +
  `availableMem: ${systemMemInfo.availableMem}`);
```

## hidebug.getVMRuntimeStats<sup>12+</sup>

getVMRuntimeStats(): GcStats

获取系统[GC](../../arkts-utils/gc-introduction.md)统计信息。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型                    | 说明       |
|-----------------------|----------|
| [GcStats](#gcstats12) | 系统GC统计信息。 |

**示例**

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

根据参数获取指定的系统[GC](../../arkts-utils/gc-introduction.md)统计信息。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数：**

| 参数名   | 类型   | 必填 | 说明          |
| -------- | ------ | ---- |-------------|
| item | string | 是   | 需要获取GC信息的类型。 |

**返回值：**

| 类型     | 说明                        |
|--------|---------------------------|
| number | 系统GC统计信息，根据传入的参数，返回相应的信息。 |

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

应用进程内存限制。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称      | 类型   | 只读 | 可选 | 说明         |
| --------- | ------ | --|----| ------------ |
| rssLimit    | bigint |  否  | 否  | 应用进程的驻留集的限制，以KB为单位。     |
| vssLimit  | bigint |  否  | 否  | 进程的虚拟内存限制，以KB为单位。       |
| vmHeapLimit | bigint |  否  | 否  | 当前线程的 JS VM 堆大小限制，以KB为单位。 |
| vmTotalHeapSize | bigint |  否  | 否  | 当前进程的 JS 堆内存大小限制，以KB为单位。  |

## VMMemoryInfo<sup>12+</sup>

VM内存信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称               | 类型    | 只读 | 可选 | 说明                                |
| -------------------| ------- | ---|----| ---------------------------------- |
| totalHeap          | bigint  | 否  | 否  | 表示当前虚拟机的堆总大小，以KB为单位。     |
| heapUsed           | bigint  | 否  | 否  | 表示当前虚拟机使用的堆大小，以KB为单位。    |
| allArraySize       | bigint  | 否  | 否  | 表示当前虚拟机的所有数组对象大小，以KB为单位。 |

## ThreadCpuUsage<sup>12+</sup>

线程的CPU使用情况。

**系统能力**：以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称               | 类型    | 只读 | 可选 | 说明                                |
| -------------------| ------- |----|----| ----------------------------------- |
| threadId           | number  | 否  | 否  | 线程号。      |
| cpuUsage           | number  | 否  | 否  | 线程CPU使用率。 |

## hidebug.tags<sup>12+</sup>

支持trace使用场景的标签，用户可通过[hitrace](../../dfx/hitrace.md)抓取指定标签的trace内容。

> **注意：**
>
> 以下标签实际值由系统定义，可能随版本升级而发生改变，为避免升级后出现兼容性问题，在生产中应直接使用标签名称而非标签数值。

**系统能力**：以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称                     | 类型    | 只读  | 说明                                         |
| -------------------------| ------- |-----|--------------------------------------------|
| ABILITY_MANAGER          | number  | 是 | 能力管理标签，hitrace命令行工具对应tagName:ability。                  |
| ARKUI                    | number  | 是 | ArkUI开发框架标签，hitrace命令行工具对应tagName:ace。                |
| ARK                      | number  | 是 | JSVM虚拟机标签，hitrace命令行工具对应tagName:ark。                  |
| BLUETOOTH                | number  | 是 | 蓝牙标签，hitrace命令行工具对应tagName:bluetooth。                 |
| COMMON_LIBRARY           | number  | 是 | 公共库子系统标签，hitrace命令行工具对应tagName:commonlibrary。         |
| DISTRIBUTED_HARDWARE_DEVICE_MANAGER | number  | 是 | 分布式硬件设备管理标签，hitrace命令行工具对应tagName:devicemanager。      |
| DISTRIBUTED_AUDIO        | number  | 是 | 分布式音频标签，hitrace命令行工具对应tagName:daudio。                 |
| DISTRIBUTED_CAMERA       | number  | 是 | 分布式相机标签，hitrace命令行工具对应tagName:dcamera。                |
| DISTRIBUTED_DATA         | number  | 是 | 分布式数据管理模块标签，hitrace命令行工具对应tagName:distributeddatamgr。 |
| DISTRIBUTED_HARDWARE_FRAMEWORK | number  | 是 | 分布式硬件框架标签，hitrace命令行工具对应tagName:dhfwk。                 |
| DISTRIBUTED_INPUT        | number  | 是 | 分布式输入标签，hitrace命令行工具对应tagName:dinput。                 |
| DISTRIBUTED_SCREEN       | number  | 是 | 分布式屏幕标签，hitrace命令行工具对应tagName:dscreen。                |
| DISTRIBUTED_SCHEDULER    | number  | 是 | 分布式调度器标签，hitrace命令行工具对应tagName:dsched。                |
| FFRT                     | number  | 是 | FFRT任务标签，hitrace命令行工具对应tagName:ffrt。                  |
| FILE_MANAGEMENT          | number  | 是 | 文件管理系统标签，hitrace命令行工具对应tagName:filemanagement。        |
| GLOBAL_RESOURCE_MANAGER  | number  | 是 | 全局资源管理标签，hitrace命令行工具对应tagName:gresource。             |
| GRAPHICS                 | number  | 是 | 图形模块标签，hitrace命令行工具对应tagName:graphic。                 |
| HDF                      | number  | 是 | HDF子系统标签，hitrace命令行工具对应tagName:hdf。                   |
| MISC                     | number  | 是 | MISC模块标签，hitrace命令行工具对应tagName:misc。                  |
| MULTIMODAL_INPUT         | number  | 是 | 多模态输入模块标签，hitrace命令行工具对应tagName:multimodalinput。      |
| NET                      | number  | 是 | 网络标签，hitrace命令行工具对应tagName:net。                       |
| NOTIFICATION             | number  | 是 | 通知模块标签，hitrace命令行工具对应tagName:notification。            |
| NWEB                     | number  | 是 | Nweb标签，hitrace命令行工具对应tagName:nweb。                    |
| OHOS                     | number  | 是 | OHOS通用标签，hitrace命令行工具对应tagName:ohos。                  |
| POWER_MANAGER            | number  | 是 | 电源管理标签，hitrace命令行工具对应tagName:power。                   |
| RPC                      | number  | 是 | RPC标签，hitrace命令行工具对应tagName:rpc。                      |
| SAMGR                    | number  | 是 | 系统能力管理标签，hitrace命令行工具对应tagName:samgr。                 |
| WINDOW_MANAGER           | number  | 是 | 窗口管理标签，hitrace命令行工具对应tagName:window。                  |
| AUDIO                    | number  | 是 | 音频模块标签，hitrace命令行工具对应tagName:zaudio。                  |
| CAMERA                   | number  | 是 | 相机模块标签，hitrace命令行工具对应tagName:zcamera。                 |
| IMAGE                    | number  | 是 | 图片模块标签，hitrace命令行工具对应tagName:zimage。                  |
| MEDIA                    | number  | 是 | 媒体模块标签，hitrace命令行工具对应tagName:zmedia。                  |

## NativeMemInfo<sup>12+</sup>

描述应用进程的内存信息。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称      | 类型   | 只读  | 可选 | 说明                                                                             |
| --------- | ------ | --|----|--------------------------------------------------------------------------------|
| pss  | bigint |  否  | 否  | 实际占用的物理内存大小(比例分配共享库占用的内存)，以KB为单位，计算方式：/proc/{pid}/smaps_rollup: Pss + SwapPss。 |
| vss  | bigint |  否  | 否  | 占用的虚拟内存大小(包括共享库所占用的内存)，以KB为单位，计算方式：/proc/{pid}/statm: size * 4。                |
| rss  | bigint |  否  | 否  | 实际占用的物理内存大小(包括共享库占用)，以KB为单位，计算方式：/proc/{pid}/smaps_rollup: Rss。                |
| sharedDirty  | bigint |  否  | 否  | 共享脏内存大小，以KB为单位，计算方式：/proc/{pid}/smaps_rollup: Shared_Dirty。                    |
| privateDirty  | bigint |  否  | 否  | 私有脏内存大小，以KB为单位，计算方式：/proc/{pid}/smaps_rollup: Private_Dirty。                   |
| sharedClean  | bigint |  否  | 否  | 共享净内存大小，以KB为单位，计算方式：/proc/{pid}/smaps_rollup: Shared_Clean。                    |
| privateClean  | bigint |  否  | 否  | 私有干净内存大小，以KB为单位，计算方式：/proc/{pid}/smaps_rollup: Private_Clean。                  |

## SystemMemInfo<sup>12+</sup>

描述系统内存信息，包括总内存、空闲内存和可用内存。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称      | 类型   | 只读  | 可选 | 说明                                              |
| --------- | ------ | ---- |---- |-------------------------------------------------|
| totalMem  | bigint |  否  |   否  |系统总的内存，以KB为单位，计算方式：/proc/meminfo: MemTotal      |
| freeMem  | bigint |  否  |   否  |系统空闲的内存，以KB为单位，计算方式：/proc/meminfo: MemFree      |
| availableMem  | bigint |  否  |   否  |系统可用的内存，以KB为单位，计算方式：/proc/meminfo: MemAvailable |

## TraceFlag<sup>12+</sup>

描述采集trace线程的类型，包括主线程和所有线程。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称                         | 值 | 说明                    |
| --------------------------- |---| ----------------------- |
| MAIN_THREAD                 | 1 | 只采集当前应用主线程。|
| ALL_THREADS                 | 2 | 采集当前应用下所有线程。 |

## GcStats<sup>12+</sup>

type GcStats = Record&lt;string, number&gt;

描述用于存储GC统计信息的键值对。该类型不支持多线程操作，如果应用中存在多线程同时访问，需加锁保护。

**系统能力**： SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 类型      | 说明                          |
| -----------| ---------------------------- |
| Record&lt;string, number&gt;     | 用于存储GC统计信息的键值对。     |

GcStats包含以下键值信息：

| 参数名                     | 类型   | 说明                      |
|-------------------------| ------ |------------------------- |
| ark.gc.gc-count         | number |  当前线程的GC次数。|
| ark.gc.gc-time          | number |  当前线程触发的GC总耗时，以ms为单位。 |
| ark.gc.gc-bytes-allocated | number | 当前线程Ark虚拟机已分配的内存大小，以B为单位。 |
| ark.gc.gc-bytes-freed   | number | 当前线程GC成功回收的内存，以B为单位。|
| ark.gc.fullgc-longtime-count | number |  当前线程超长fullGC次数。 |

## hidebug.isDebugState<sup>12+</sup>

isDebugState(): boolean

获取应用进程的调试状态。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型  | 说明                                                   |
| ------ |------------------------------------------------------|
| boolean | 应用进程的Ark层或Native层是否处于调试状态。true：处于调试状态。false：未处于调试状态。 |

**示例**

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

console.info(`isDebugState = ${hidebug.isDebugState()}`)
```

## hidebug.getGraphicsMemory<sup>14+</sup>

getGraphicsMemory(): Promise&lt;number&gt;

使用异步方式获取应用显存大小。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型                    | 说明                           |
|-----------------------|------------------------------|
| Promise&lt;number&gt; | promise对象，调用结束后返回应用显存大小，单位为KB。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | Failed to get the application memory due to a remote exception. |

**示例**

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

使用同步方式获取应用显存大小。

> **注意：**
>
> 由于该接口涉及多次跨进程通信，其耗时可能达到秒级。为了避免引入性能问题，建议不要在主线程调用该接口，推荐使用异步接口`getGraphicsMemory`。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值：**

| 类型  | 说明             |
| ------ |----------------|
| number | 应用显存大小，单位为KB。 |

**错误码：**

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | Failed to get the application memory due to a remote exception. |

**示例**

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

为当前线程转储虚拟机的原始堆快照，生成的rawheap文件路径将使用Promise进行异步回调。所生成的文件可通过[rawheap-translator工具](../../tools/rawheap-translator.md)将所生成文件转化为heapsnapshot文件进行解析。

> **注意：**
>
> 系统通过该接口转存快照会消耗大量资源，因此严格限制了调用频率和次数。处理完生成的文件后，请立即删除。
> 建议仅在应用的灰度版本中使用。在正式版本中不推荐使用，避免影响应用流畅性。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名                     | 类型      | 必填 | 说明                                          |
|-------------------------|---------|----|---------------------------------------------|
| needGC         | boolean | 否  | 转储堆快照前是否需要GC。true：需要GC。false：不需GC。默认值：true。 |

**返回值：**

| 类型  | 说明                                                                                                   |
| ------ |------------------------------------------------------------------------------------------------------|
| Promise&lt;string&gt; | Promise对象，返回生成的快照文件路径（[应用沙箱内路径](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)）。 |

**错误码：**

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID    | 错误信息 |
|----------| ----------------------------------------------------------------- |
| 11400106 | Quota exceeded. |
| 11400107 | Fork operation failed. |
| 11400108 | Failed to wait for the child process to finish. |
| 11400109 | Timeout while waiting for the child process to finish. |
| 11400110 | Disk remaining space too low. |
| 11400111 | Napi interface call exception. |
| 11400112 | Repeated data dump. |
| 11400113 | Failed to create dump file. |

**示例**

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

使能GWP-Asan，用于检测堆内存使用中的非法行为。

该接口主要用于动态配置并启用GWP-Asan，以适配应用自定义的GWP-Asan检测策略。配置在应用重新启动后生效。

更多关于GWP-Asan的说明，请参见[使用GWP-Asan检测内存错误](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-gwpasan-detection)。

> **说明**：
> 
> 1. 若设备运行期间已使能超过20个应用，调用该接口将会失败，并抛出错误码。
> 2. 为避免应用异常退出，请务必使用try-catch捕获异常。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型   | 必填 | 说明   |
|---------|---------|--------|-----|
|options | [GwpAsanOptions](#gwpasanoptions20) | 否 | GWP-Asan配置项。如果未进行设置，则会使用默认参数。|
|duration | number | 否 | GWP-Asan持续时间，默认7天，需要传入大于0的正整数。|

**错误码**：

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID    | 错误信息 |
|----------| ----------------------------------------------------------------- |
| 11400114 | The number of GWP-ASAN applications of this device overflowed after last boot. |

**示例**：

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
  console.info('Succeeded in enabling GWP-Asan.');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`Failed to enable GWP-Asan. Code: ${err.code}, message: ${err.message}`);
}
```
## GwpAsanOptions<sup>20+</sup>
GWP-Asan配置项。可用于配置是否使能、采样频率，以及最大分配的插槽数。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称         | 类型  | 只读  | 可选 | 说明 |
|--------------|------|-------|-------|-----|
|alwaysEnabled | boolean | 否  | 是 | true：100%使能GWP-Asan。<br/>false：1/128概率使能GWP-Asan。<br/> 默认值：false。|
|sampleRate    |number| 否  |是|GWP-Asan采样频率，默认值为2500，需要传入大于0的正整数，若传入小数则向上取整。<br/> 1/sampleRate的概率对分配的内存进行采样。|
|maxSimutaneousAllocations|number|否|是|最大分配的插槽数，默认值为1000，需要传入大于0的正整数，若传入小数则向上取整。<br/>当插槽用尽时，新分配的内存将不再受监控。<br/>释放已使用的内存后，其占用的插槽将自动复用，以便于后续内存的监控。|

## hidebug.disableGwpAsanGrayscale<sup>20+</sup>
disableGwpAsanGrayscale(): void

停止使能GWP-Asan。调用该接口将取消自定义配置，恢复默认参数[GwpAsanOptions](#gwpasanoptions20)。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.disableGwpAsanGrayscale();
```

## hidebug.getGwpAsanGrayscaleState<sup>20+</sup>
getGwpAsanGrayscaleState(): number

获取当前GWP-Asan剩余使能天数。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型 | 说明 |
|-----------|-------------|
| number    |获取当前GWP-Asan剩余使能天数。若当前未使能，返回值0。|

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let remainDays: number = hidebug.getGwpAsanGrayscaleState();
console.info(`remainDays: ${remainDays}`);
```
