# @ohos.hidebug (Debug调试)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @leiguangyu-->
<!--Designer: @mgce1-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

为应用提供多种调试、调优的方法，帮助开发者定位性能瓶颈、优化应用性能。主要功能包括：内存数据分析、CPU使用率监控、trace采集、profiler采集、VM堆快照转储。由于该模块的接口大多比较耗费性能，接口调用较为耗时，且基于HiDebug模块定义，该模块内的接口仅建议在应用调试、调优阶段使用。若需要在其他场景使用时，请认真评估所需调用的接口对应用性能的影响。

> **说明**：
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

**返回值**：

| 类型   | 说明                                         |
| ------ |--------------------------------------------|
| bigint | 内存分配器统计的进程持有的普通块所占用内存的大小（含分配器元数据），单位为Byte。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapSize: bigint = hidebug.getNativeHeapSize();
console.info(`nativeHeapSize = ${nativeHeapSize}`);
```

## hidebug.getNativeHeapAllocatedSize

getNativeHeapAllocatedSize(): bigint

获取内存分配器统计的进程持有的已使用的普通块所占用的总字节数。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型   | 说明                              |
| ------ | --------------------------------- |
| bigint | 返回内存分配器统计的进程持有的已使用的普通块所占用内存大小，单位为Byte。 |


**示例**：
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapAllocatedSize: bigint = hidebug.getNativeHeapAllocatedSize();
console.info(`nativeHeapAllocatedSize = ${nativeHeapAllocatedSize}`);
```

## hidebug.getNativeHeapFreeSize

getNativeHeapFreeSize(): bigint

获取内存分配器统计的进程持有的空闲的普通块所占用的总字节数。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型   | 说明                            |
| ------ | ----------------------------- |
| bigint | 返回内存分配器统计的进程持有的空闲的普通块所占用内存大小，单位为Byte。 |

**示例**：
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeHeapFreeSize: bigint = hidebug.getNativeHeapFreeSize();
console.info(`nativeHeapFreeSize = ${nativeHeapFreeSize}`);
```

## hidebug.getPss

getPss(): bigint

获取应用进程实际使用的物理内存大小。接口实现方式：读取/proc/{pid}/smaps_rollup节点中的Pss与SwapPss值并求和。

> **注意**：
> 
> 由于/proc/{pid}/smaps_rollup的读取耗时较长，建议不要在主线程中使用该接口，可通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程以避免应用出现卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型   | 说明                      |
| ------ | ------------------------- |
| bigint | 返回应用进程实际使用的物理内存大小，单位为KB。 |

**示例**：
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let pss: bigint = hidebug.getPss();
console.info(`pss = ${pss}`);
```

## hidebug.getVss<sup>11+</sup>

getVss(): bigint

获取应用进程占用的虚拟内存大小。接口实现方式：读取/proc/{pid}/statm节点中的size值（内存页数），vss = size * 页大小（4KB/页）。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型   | 说明                                     |
| ------ | ---------------------------------------- |
| bigint | 返回应用进程占用的虚拟内存大小，单位为KB。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let vss: bigint = hidebug.getVss();
console.info(`vss = ${vss}`);
```

## hidebug.getSharedDirty

getSharedDirty(): bigint

获取进程的共享脏内存大小。接口实现方式：读取/proc/{pid}/smaps_rollup节点中的Shared_Dirty值。

> **注意**：
> 
> 由于/proc/{pid}/smaps_rollup的读取耗时较长，建议不要在主线程中使用该接口，可通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程以避免应用出现卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型   | 说明                       |
| ------ | -------------------------- |
| bigint | 返回进程的共享脏内存大小，单位为KB。 |


**示例**：
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let sharedDirty: bigint = hidebug.getSharedDirty();
console.info(`sharedDirty = ${sharedDirty}`);
```

## hidebug.getPrivateDirty<sup>9+</sup>

getPrivateDirty(): bigint

获取进程的私有脏内存大小。读取/proc/{pid}/smaps_rollup中的Private_Dirty值。

> **注意**：
>
> 由于/proc/{pid}/smaps_rollup的读取耗时较长，建议不要在主线程中使用该接口，可通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程以避免应用出现卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型   | 说明                       |
| ------ | -------------------------- |
| bigint | 返回进程的私有脏内存大小，单位为KB。 |

**示例**：
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let privateDirty: bigint = hidebug.getPrivateDirty();
console.info(`privateDirty = ${privateDirty}`);
```

## hidebug.getCpuUsage<sup>9+</sup>

getCpuUsage(): number

获取进程的CPU使用率。

> **注意**：
>
> 由于该接口涉及跨进程通信，耗时较长，为了避免引入性能问题，建议不要在主线程中直接调用该接口。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型   | 说明                       |
| ------ | -------------------------- |
| number | 获取进程的CPU使用率。如占用率为50%，则返回0.5。 |


**示例**：
```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let cpuUsage: number = hidebug.getCpuUsage();
console.info(`cpuUsage = ${cpuUsage}`);
```

## hidebug.getServiceDump<sup>9+</sup>

getServiceDump(serviceid: number, fd: number, args: Array\<string>): void

获取系统服务信息。

**需要权限**：ohos.permission.DUMP，仅系统应用可申请。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型   | 必填 | 说明                         |
| -------- | ------ | ---- |----------------------------|
| serviceid | number | 是   | 系统服务ID，用于标识要获取信息的系统服务。取值由系统定义，取值范围[0, 255]。传入无效值时返回错误码401。 |
| fd | number | 是   | 文件描述符，接口会向该fd写入数据。传入无效文件描述符时返回错误码401。         |
| args | Array&lt;string&gt; | 是   | 系统服务的dump接口参数列表。string长度的最大值为254，超出部分将会被截断。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)与[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | The parameter check failed,Possible causes:1.the parameter type error. 2.the args parameter is not string array.  |
| 11400101 | ServiceId invalid. The system ability does not exist.                                           |

**示例**：

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

startJsCpuProfiling(filename: string): void

启动虚拟机Profiling方法跟踪，`startJsCpuProfiling(filename: string)`方法的调用需要与`stopJsCpuProfiling()`方法的调用一一对应，先开启后关闭，请避免重复开启或重复关闭的调用方式，否则会接口调用异常。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型   | 必填 | 说明                                               |
| -------- | ------ | ---- |--------------------------------------------------|
| filename | string | 是   | 用户自定义的采样结果输出的文件名，将在应用的`files`目录下生成以该参数命名的json文件。string长度的最大值为128。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | The parameter check failed,Parameter type error.                        |

**示例**：

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

stopJsCpuProfiling(): void

停止虚拟机Profiling方法跟踪，`stopJsCpuProfiling()`方法的调用需要与`startJsCpuProfiling(filename: string)`方法的调用一一对应，先开启后关闭，请避免重复开启或重复关闭的调用方式，否则会接口调用异常。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**示例**：

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

dumpJsHeapData(filename: string): void

虚拟机堆数据转储。

> **注意**：
>
> 由于虚拟机堆导出极其耗时，且该接口为同步接口，建议不要在上架版本中调用该接口，以避免应用冻屏，影响用户体验。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型   | 必填 | 说明                                            |
| -------- | ------ | ---- | ----------------------------------------------- |
| filename | string | 是   | 用户自定义的虚拟机堆数据转储输出的文件名，将在应用的`files`目录下生成以该参数命名的heapsnapshot文件。string长度的最大值为128字节。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | The parameter check failed, Parameter type error.                      |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  hidebug.dumpJsHeapData("heapData");
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.dumpJsHeapData<sup>24+</sup>

dumpJsHeapData(filename: string, needClean: boolean): void

虚拟机堆数据转储，支持清除nodeId缓存。

> **注意**：
>
> 由于虚拟机堆导出极其耗时，且该接口为同步接口，建议不要在上架版本中调用该接口，以避免应用冻屏，影响用户体验。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名   | 类型   | 必填 | 说明                                            |
| -------- | ------ | ---- | ----------------------------------------------- |
| filename | string | 是   | 用户自定义的虚拟机堆转储文件名，将在应用的files目录下生成fileName.heapsnapshot格式文件。string长度的最大值为128字节。 |
| needClean | boolean | 是  | 转储堆快照前是否需要清除nodeId缓存。true：需要清除；false：不需要清除。|

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  hidebug.dumpJsHeapData("heapData", true);
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.startProfiling<sup>(deprecated)</sup>

startProfiling(filename: string): void

> **说明**：
> 
> 从API version 8支持，从API version 9开始废弃，建议使用[hidebug.startJsCpuProfiling](#hidebugstartjscpuprofiling9)替代。

启动虚拟机Profiling方法跟踪，`startProfiling(filename: string)`方法的调用需要与`stopProfiling()`方法的调用一一对应，先开启后关闭，请避免重复开启或重复关闭的调用方式，否则会接口调用异常。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型   | 必填 | 说明                                             |
| -------- | ------ | ---- | ------------------------------------------------ |
| filename | string | 是   | 用户自定义的采样结果输出的文件名，将在应用的`files`目录下生成以该参数命名的json文件。string长度的最大值为128。|

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.startProfiling("cpuprofiler-20220216");
// code block
// ...
// code block
hidebug.stopProfiling();
```

## hidebug.stopProfiling<sup>(deprecated)</sup>

stopProfiling(): void

> **说明**：
> 
> 从API version 8支持，从API version 9开始废弃，建议使用[hidebug.stopJsCpuProfiling](#hidebugstopjscpuprofiling9)替代。

停止虚拟机Profiling方法跟踪，`stopProfiling()`方法的调用需要与`startProfiling(filename: string)`方法的调用一一对应，先开启后关闭，请避免重复开启或重复关闭的调用方式，否则会接口调用异常。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.startProfiling("cpuprofiler-20220216");
// code block
// ...
// code block
hidebug.stopProfiling();
```

## hidebug.dumpHeapData<sup>(deprecated)</sup>

dumpHeapData(filename: string): void

> **说明**：
> 
> 从API version 8支持，从API version 9开始废弃，建议使用[hidebug.dumpJsHeapData](#hidebugdumpjsheapdata9)替代。

虚拟机堆数据转储，生成`filename.heapsnapshot`文件。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型   | 必填 | 说明                                                      |
| -------- | ------ | ---- |---------------------------------------------------------|
| filename | string | 是   | 用户自定义的虚拟机堆转储文件名，将在应用的`files`目录下生成以该参数命名的heapsnapshot文件。string长度的最大值为128。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.dumpHeapData("heap-20220216");
```

## hidebug.getAppVMMemoryInfo<sup>12+</sup>

getAppVMMemoryInfo(): VMMemoryInfo

获取VM内存相关信息。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型         | 说明                                    |
| -------------| --------------------------------------- |
| [VMMemoryInfo](#vmmemoryinfo12) | 返回VM内存信息。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let vmMemory: hidebug.VMMemoryInfo = hidebug.getAppVMMemoryInfo();
console.info(`totalHeap = ${vmMemory.totalHeap}, heapUsed = ${vmMemory.heapUsed},` +
  `allArraySize = ${vmMemory.allArraySize}` );
```

## hidebug.getAppVMObjectUsedSize<sup>21+</sup>

getAppVMObjectUsedSize(): bigint

获取当前虚拟机中ArkTS对象所占用的内存大小。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型     | 说明                           |
|--------|------------------------------|
| bigint | 当前虚拟机中ArkTS对象所占用的内存大小，单位为KB。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

console.info(`getAppVMObjectUsedSize = ${hidebug.getAppVMObjectUsedSize()}`);
```

## hidebug.getAppThreadCpuUsage<sup>12+</sup>

getAppThreadCpuUsage(): ThreadCpuUsage[]

获取应用线程CPU使用情况。

> **注意**：
>
> 由于该接口涉及跨进程通信，耗时较长，为了避免引入性能问题，建议不要在主线程中直接调用该接口。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型             | 说明                                                        |
| -----------------| ------------------------------------------------------------|
| [ThreadCpuUsage](#threadcpuusage12)[] | 返回当前应用进程下所有ThreadCpuUsage数组。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let appThreadCpuUsage: hidebug.ThreadCpuUsage[] = hidebug.getAppThreadCpuUsage();
for (let i = 0; i < appThreadCpuUsage.length; i++) {
  console.info(`threadId=${appThreadCpuUsage[i].threadId}, cpuUsage=${appThreadCpuUsage[i].cpuUsage}`);
}
```

## hidebug.startAppTraceCapture<sup>12+</sup>

startAppTraceCapture(tags: number[], flag: TraceFlag, limitSize: number): string

该接口补充了[hitrace](../../dfx/hitrace.md)功能，开发者可通过该接口完成指定范围的trace自动化采集。由于该接口中trace采集过程中消耗的性能与需要采集的范围成正相关，建议开发者在使用该接口前，通过hitrace命令抓取应用的trace日志，从中筛选出所需trace采集的关键范围，以提高该接口性能。

`startAppTraceCapture()`方法的调用需要与'[stopAppTraceCapture()](#hidebugstopapptracecapture12)'方法的调用一一对应，重复开启trace采集将导致接口调用异常，由于trace采集过程中会消耗较多性能，开发者应在完成采集后及时关闭。

应用调用startAppTraceCapture接口启动采集trace，当采集的trace大小超过了limitSize，系统将自动调用stopAppTraceCapture接口停止采集。因此limitSize大小设置不当，将导致生成trace数据不足，无法满足故障分析。所以要求开发者根据实际情况，评估limitSize大小。

评估方法：limitSize = 预期trace采集时长 * trace单位流量。

预期trace采集时长：开发者根据分析的故障场景自行决定，单位秒。

trace单位流量：应用每秒产生的trace大小，系统推荐值为300KB/s，建议开发者采用自身应用的实测值，单位KB/s。

trace单位流量实测方法：limitSize设置为最大值500M，调用startAppTraceCapture接口，在应用上操作N秒后，调用stopAppTraceCapture停止采集，然后查看trace大小S（KB）。那么trace单位流量 = S/N（KB/s）。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型     | 必填 | 说明                                 |
| -------- | ------   | ---- |------------------------------------|
| tags     | number[] | 是   | trace范围，详情请见[tags](#tags12)。   |
| flag     | TraceFlag| 是   | 详情请见[TraceFlag](#traceflag12)。        |
| limitSize| number   | 是   | 开启trace文件大小限制，单位为Byte，取值范围（0, 500MB]。超出范围时返回错误码401。 |

**返回值**：

| 类型             | 说明            |
| -----------------|---------------|
| string           | 返回trace文件名路径（接口返回真实物理路径，若应用内需要访问，请参考[应用沙箱路径和真实物理路径的对应关系](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)进行路径转换）。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)与[HiDebug Trace错误码](errorcode-hiviewdfx-hidebug-trace.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small. 2.The parameter is not within the enumeration type. 3.The parameter type error or parameter order error. |
| 11400102 | Capture trace already enabled.                                         |
| 11400103 | No write permission on the file.                                |
| 11400104 | Abnormal trace status.                                 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tags: number[] = [hidebug.tags.ABILITY_MANAGER, hidebug.tags.ARKUI];
let flag: hidebug.TraceFlag = hidebug.TraceFlag.MAIN_THREAD;
let limitSize: number = 1024 * 1024;

try {
  let fileName: string = hidebug.startAppTraceCapture(tags, flag, limitSize);
  console.info(`fileName = ${fileName}`);
  // code block
  // ...
  // code block
  hidebug.stopAppTraceCapture();
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.stopAppTraceCapture<sup>12+</sup>

stopAppTraceCapture(): void

停止应用trace采集。调用前，需先调用'[startAppTraceCapture()](#hidebugstartapptracecapture12)'方法开始采集。关闭前未开启或重复关闭会导致接口异常。

调用startAppTraceCapture接口，如果没有合理传入limitSize参数，生成trace的大小大于传入的limitSize大小，系统内部会自动调用stopAppTraceCapture，再次手动调用stopAppTraceCapture就会抛出错误码11400105。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**错误码**：

以下错误码的详细介绍请参见[HiDebug Trace错误码](errorcode-hiviewdfx-hidebug-trace.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | The status of the trace is abnormal.                                |
| 11400105 | No capture trace running.                                       |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

let tags: number[] = [hidebug.tags.ABILITY_MANAGER, hidebug.tags.ARKUI];
let flag: hidebug.TraceFlag = hidebug.TraceFlag.MAIN_THREAD;
let limitSize: number = 1024 * 1024;
try {
  let fileName: string = hidebug.startAppTraceCapture(tags, flag, limitSize);
  console.info(`fileName = ${fileName}`);
  // code block
  // ...
  // code block
  hidebug.stopAppTraceCapture();
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.requestTrace<sup>24+</sup>

requestTrace(config: RequestTraceConfig): Promise&lt;string&gt;

获取当前进程的trace信息，包含应用tag、图像窗口tag、cpu调度和binder内核信息。使用Promise异步回调。

采集trace返回的.sys文件在目录下最多存储3份，数量大于等于3份时再次调用接口会抛出错误码11400120。

接口不支持在[输入法应用](../../inputmethod/ime-kit-intro.md)中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型     | 必填 | 说明                                 |
| -------- | ------   | ---- |------------------------------------|
| config   | [RequestTraceConfig](#requesttraceconfig24) | 是 | trace采集配置信息。 |

**返回值**：

| 类型             | 说明            |
| -----------------|---------------|
| Promise&lt;string&gt; | Promise对象，返回以.sys作为后缀的trace文件的应用沙箱路径。 |

**错误码**：

以下错误码的详细介绍请参见[HiDebug Trace错误码](errorcode-hiviewdfx-hidebug-trace.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | Remote service exception.                                         |
| 11400120 | Trace storage limit reached.                                |
| 11400302 | Resource unavailable.                                 |

**示例**：

```ts
import { hidebug, hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  hidebug.requestTrace({
    identifier: "trace_name",
    bufferSizeKb: 1024,
    durationMs: 1000,
    reserved: 0,
  }).then((tracePath: string) => {
    hilog.info(0x0000, 'hidebug', `tracePath: ${tracePath}`)
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'hidebug', `error code: ${err.code}, message: ${err.message}`)
  })
} catch (error) {
  hilog.error(0x0000, 'hidebug', `error code: ${(error as BusinessError).code}, message: ${(error as BusinessError).message}`)
}
```

## hidebug.getAppMemoryLimit<sup>12+</sup>

getAppMemoryLimit(): MemoryLimit

获取应用程序进程的内存限制。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型  | 说明                      |
| ------ | -------------------------- |
| [MemoryLimit](#memorylimit12) | 应用程序进程内存限制。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let appMemoryLimit:hidebug.MemoryLimit = hidebug.getAppMemoryLimit();
console.info(`rssLimit: ${appMemoryLimit.rssLimit}, vssLimit: ${appMemoryLimit.vssLimit},` +
  `vmHeapLimit: ${appMemoryLimit.vmHeapLimit}, vmTotalHeapSize: ${appMemoryLimit.vmTotalHeapSize}`);
```

## hidebug.getSystemCpuUsage<sup>12+</sup>

getSystemCpuUsage(): number

获取系统的CPU资源占用情况。

> **注意**：
>
> 由于该接口涉及跨进程通信，耗时较长，为了避免引入性能问题，建议不要在主线程中直接调用该接口。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型     | 说明          |
|--------|-------------|
| number | 系统CPU资源占用情况。如占用率为50%，则返回0.5。 |

**错误码**：

以下错误码的详细介绍请参见[HiDebug CpuUsage错误码](errorcode-hiviewdfx-hidebug-cpuusage.md)。

| 错误码ID | 错误信息                                            |
| ------- |-------------------------------------------------|
| 11400104 | The status of the system CPU usage is abnormal. |

**示例**：
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

setAppResourceLimit(type: string, value: number, enableDebugLog: boolean): void

设置应用的文件描述符数量、线程数量、JS内存或Native内存资源限制。

主要应用场景在于构造内存泄漏故障，参见[订阅资源泄漏事件（ArkTS）](../../dfx/hiappevent-watcher-resourceleak-events-arkts.md)、[订阅资源泄漏事件（C/C++）](../../dfx/hiappevent-watcher-resourceleak-events-ndk.md)。

> **注意**：
>
> 打开设置中的开发者选项后，在开发者选项列表中找到“系统资源泄漏日志”并启用，重启设备后接口生效。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型   | 必填 | 说明                                                                                                                                                                      |
| -------- | ------ | ---- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| type | string |  是  | 泄漏资源类型，共四种：<br/>- pss_memory（native内存）<br/>- js_heap（js堆内存）<br/>- fd（文件描述符）<br/>- thread（线程）                                                                            |
| value | number |  是  | 对应泄漏资源类型的最大值，范围：<br/>- pss_memory类型：`[1024, 4 * 1024 * 1024]`（单位：KB）<br/>- js_heap类型：`[85, 95]`（分配给JS堆内存上限的85%~95%）<br/>- fd类型：`[10, 10000]`<br/>- thread类型：`[1, 1000]`。超出范围会导致功能失效。 |
| enableDebugLog | boolean |  是  | 是否启用外部调试日志。外部调试日志请仅在灰度版本（正式版本发布之前，先向一小部分用户推出的测试版本）中启用，因为收集调试日志会占用大量的cpu资源和内存资源，可能会引起应用流畅性问题。<br/>true：启用外部调试日志。<br/>false：禁用外部调试日志。                                     |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)与[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 401 | Invalid argument, Possible causes:1.The limit parameter is too small. 2.The parameter is not in the specified type. 3.The parameter type error or parameter order error.  |
| 11400104 | Set limit failed due to remote exception. |

**示例**：

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

> **注意**：
>
> 由于读取/proc/{pid}/smaps_rollup耗时较长，推荐使用异步接口[hidebug.getAppNativeMemInfoAsync](#hidebuggetappnativememinfoasync20)，以避免应用丢帧或卡顿。
>
> 推荐使用[hidebug.getRssInfo](#hidebuggetrssinfo24)接口获取应用的rss使用信息

**返回值**：

| 类型  | 说明                      |
| ------ | -------------------------- |
| [NativeMemInfo](#nativememinfo12) | 应用进程内存信息。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let nativeMemInfo: hidebug.NativeMemInfo = hidebug.getAppNativeMemInfo();
console.info(`pss: ${nativeMemInfo.pss}, vss: ${nativeMemInfo.vss}, rss: ${nativeMemInfo.rss}, ` +
  `sharedDirty: ${nativeMemInfo.sharedDirty}, privateDirty: ${nativeMemInfo.privateDirty}, ` +
  `sharedClean: ${nativeMemInfo.sharedClean}, privateClean: ${nativeMemInfo.privateClean}`);
```

## hidebug.getAppNativeMemInfoAsync<sup>20+</sup>

getAppNativeMemInfoAsync(): Promise&lt;NativeMemInfo&gt;

读取/proc/{pid}/smaps_rollup和/proc/{pid}/statm节点的数据以获取应用进程内存信息，使用Promise异步回调。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型                                               | 说明                    |
|--------------------------------------------------| --------------------- |
| Promise&lt;[NativeMemInfo](#nativememinfo12)&gt; | promise对象，返回应用进程内存信息。 |

**示例**：

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

> **注意**：
>
> 由于读取 `/proc/{pid}/smaps_rollup` 比较耗时，建议不在主线程中使用该接口。可以通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程，以避免应用卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名                     | 类型      | 必填 | 说明                                                                                                     |
|-------------------------|---------|----|--------------------------------------------------------------------------------------------------------|
| forceRefresh         | boolean | 否  | 是否需要无视缓存有效性，强制更新缓存值。默认值：false。</br>true：直接获取当前内存数据并更新缓存值。</br>false：缓存有效时，直接返回缓存值，缓存失效时获取当前内存数据并更新缓存值。 |

**返回值**：

| 类型  | 说明                      |
| ------ | -------------------------- |
| [NativeMemInfo](#nativememinfo12) | 应用进程内存信息。 |

**示例**：

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

**返回值**：

| 类型  | 说明                      |
| ------ | -------------------------- |
| [SystemMemInfo](#systemmeminfo12) | 系统内存信息。 |

**示例**：

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

**返回值**：

| 类型                    | 说明       |
|-----------------------|----------|
| [GcStats](#gcstats12) | 系统GC统计信息。 |

**示例**：

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

**参数**：

| 参数名   | 类型   | 必填 | 说明          |
| -------- | ------ | ---- |-------------|
| item | string | 是   | 所需统计信息的类型。可获取的统计信息类型如下：<br/>"ark.gc.gc-count"：当前线程的GC次数。<br/>"ark.gc.gc-time"：当前线程触发的GC总耗时，以ms为单位。<br/>"ark.gc.gc-bytes-allocated"：当前线程Ark虚拟机已分配的内存大小，以B为单位。<br/>"ark.gc.gc-bytes-freed"：当前线程GC成功回收的内存，以B为单位。<br/> "ark.gc.fullgc-longtime-count "：当前线程超长fullGC次数。 |

**返回值**：

| 类型     | 说明                        |
|--------|---------------------------|
| number | 系统GC统计信息，根据传入的参数，返回相应的信息。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                                                       |
| ------- |------------------------------------------------------------------------------------------------------------|
| 401 | Possible causes:1. Invalid parameter, a string parameter required. 2. Invalid parameter, unknown property. |

**示例**：

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
| rssLimit    | bigint |  否  | 否  | 应用程序进程可用的物理内存限制，以KB为单位，实际当前系统未对进程可用物理内存做限制，但是进程的可用物理内存仍然不会超过设备的实际最大可用物理内存，当前设备的物理内存使用情况可通过[hidebug.getSystemMemInfo](#hidebuggetsystemmeminfo12)获取。     |
| vssLimit  | bigint |  否  | 否  | 进程的虚拟内存限制，以KB为单位。       |
| vmHeapLimit | bigint |  否  | 否  | 当前线程的 JS VM 堆大小限制，以KB为单位。 |
| vmTotalHeapSize | bigint |  否  | 否  | 当前进程的 JS 堆内存大小限制，以KB为单位。  |

## VMMemoryInfo<sup>12+</sup>

VM内存信息。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称               | 类型    | 只读 | 可选 | 说明                                |
| -------------------| ------- | ---|----| ---------------------------------- |
| totalHeap          | bigint  | 否  | 否  | 表示当前虚拟机的堆总大小，以KB为单位。     |
| heapUsed           | bigint  | 否  | 否  | 表示当前虚拟机使用的堆大小，以KB为单位。    |
| allArraySize       | bigint  | 否  | 否  | 表示当前虚拟机的所有数组对象大小，以KB为单位。 |

## ThreadCpuUsage<sup>12+</sup>

线程的CPU使用情况。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称               | 类型    | 只读 | 可选 | 说明                                |
| -------------------| ------- |----|----| ----------------------------------- |
| threadId           | number  | 否  | 否  | 线程号。      |
| cpuUsage           | number  | 否  | 否  | 线程CPU使用率。 |

## tags<sup>12+</sup>

### 常量

支持trace使用场景的标签，用户可通过[hitrace](../../dfx/hitrace.md)抓取指定标签的trace内容。

> **注意**：
>
> 以下标签实际值由系统定义，可能随版本升级而发生改变，为避免升级后出现兼容性问题，在生产中应直接使用标签名称而非标签数值。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

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

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 类型      | 说明                          |
| -----------| ---------------------------- |
| Record&lt;string, number&gt;     | 用于存储GC统计信息的键值对。包含以下键值信息：<br/>"ark.gc.gc-count"：当前线程的GC次数。<br/>"ark.gc.gc-time"：当前线程触发的GC总耗时，以ms为单位。<br/>"ark.gc.gc-bytes-allocated"：当前线程Ark虚拟机已分配的内存大小，以B为单位。<br/>"ark.gc.gc-bytes-freed"：当前线程GC成功回收的内存，以B为单位。<br/> "ark.gc.fullgc-longtime-count "：当前线程超长fullGC次数。    |

## JsRawHeapTrimLevel<sup>20+</sup>

转储堆快照的裁剪级别的枚举。

TRIM_LEVEL_2相比TRIM_LEVEL_1，裁剪时间更长。冻屏的阈值为6秒。使用TRIM_LEVEL_1时，不会达到该阈值；切换至TRIM_LEVEL_2时，裁剪时间可能会超过6秒，触发APP_FREEZE（冻屏事件），导致应用被系统终止，此时回退至TRIM_LEVEL_1级别进行裁剪。

推荐优先使用TRIM_LEVEL_1确保应用稳定，仅在需要更彻底裁剪时尝试TRIM_LEVEL_2。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称         | 值   | 说明                                                         |
| ------------ | ---- | ------------------------------------------------------------ |
| TRIM_LEVEL_1 | 0    | LEVEL 1级别裁剪，主要裁剪字符串。                       |
| TRIM_LEVEL_2 | 1    | LEVEL 2级别裁剪，在TRIM_LEVEL_1的基础上，精简了对象地址标识的大小，从8个字节减少到4个字节。 |

## RssInfo<sup>24+</sup>

描述应用进程的物理内存信息。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称      | 类型   | 只读  | 可选 | 说明                                              |
| --------- | ------ | ---- |---- |-------------------------------------------------|
| rss  | bigint |  否  |   否  |实际占用的物理内存大小（Resident Set Size），包含匿名页、文件映射页和共享内存页，以KB为单位，计算方式：/proc/{pid}/status: VmRss。      |
| swapRss  | bigint |  否  |   否  |换出到交换分区的匿名私有页总大小，以KB为单位，计算方式：/proc/{pid}/status: VmSwap      |

## RequestTraceConfig<sup>24+</sup>

提供trace采集的参数选项。

**模型约束**：此接口仅可在Stage模型下使用。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称      | 类型                    | 只读 | 可选 | 说明                                                         |
| --------- | ----------------------- | ---- | ---- | ------------------------------------------------------------ |
| identifier   | string | 否 | 否 | 采集trace输出的文件名前缀。文件名前缀只取字符串前20个字符，超过部分将抛弃。前20个字符只包含大小写字母和下划线，若不符合则默认为空字符串。 |
| bufferSizeKb | number | 否 | 否 | trace文件的缓存大小，以KB为单位。数值为32位无符号整型数字，超出有效范围将导致数值溢出。取值范围为[1024, 15360]，传入参数超过取值范围，参数将被设置为最近的边界值。 |
| durationMs   | number | 否 | 否 | trace采集时长，以ms为单位。数值为32位无符号整型数字，超出有效范围将导致数值溢出。取值范围为[1000, 15000]，传入参数超过取值范围，参数将被设置为最近的边界值。 |
| reserved     | number | 否 | 否 | 预留字段，可以设置为0。 |

## hidebug.isDebugState<sup>12+</sup>

isDebugState(): boolean

获取应用进程的调试状态。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型  | 说明                                                   |
| ------ |------------------------------------------------------|
| boolean | 应用进程的Ark层或Native层是否处于调试状态。true：处于调试状态。false：未处于调试状态。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

console.info(`isDebugState = ${hidebug.isDebugState()}`)
```

## hidebug.getGraphicsMemory<sup>14+</sup>

getGraphicsMemory(): Promise&lt;number&gt;

获取应用显存总大小（gl + graph），使用Promise异步回调。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型                    | 说明                         |
|-----------------------|----------------------------|
| Promise&lt;number&gt; | promise对象，返回应用显存总大小，单位为KB。 |

**错误码**：

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | Failed to get the application memory due to a remote exception. |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

hidebug.getGraphicsMemory().then((ret: number) => {
  console.info(`graphicsMemory: ${ret}`)
}).catch((error: BusinessError) => {
  console.error(`error code: ${error.code}, error msg: ${error.message}`);
})
```

## hidebug.getGraphicsMemorySync<sup>14+</sup>

getGraphicsMemorySync(): number

使用同步方式获取应用显存总大小（gl + graph）。

> **注意**：
>
> 由于该接口涉及多次跨进程通信，其耗时可能达到秒级。为了避免引入性能问题，建议不要在主线程调用该接口，推荐使用异步接口`getGraphicsMemory`。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型  | 说明             |
| ------ |----------------|
| number | 应用显存总大小，单位为KB。 |

**错误码**：

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | Failed to get the application memory due to a remote exception. |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  console.info(`graphicsMemory: ${hidebug.getGraphicsMemorySync()}`)
} catch (error) {
  console.error(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);
}
```

## hidebug.getGraphicsMemorySummary<sup>21+</sup>

getGraphicsMemorySummary(interval?: number): Promise&lt;GraphicsMemorySummary&gt;

获取应用显存数据，使用Promise进行异步回调。

**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名 | 类型        | 必填 | 说明                                                                                                          |
| ------ | --------- |---|-------------------------------------------------------------------------------------------------------------|
| interval  | number | 否 | 显存数据缓存值有效时间，单位为秒。默认值：300。取值范围为[2-3600]。若传入值超出取值范围时，将使用默认值。<br/>当显存数据缓存值存在时间超过该值时，获取最新显存数据并更新缓存值；否则，直接获取缓存值。 |

**返回值**：

| 类型                                                               | 说明                  |
|------------------------------------------------------------------|---------------------|
| Promise&lt;[GraphicsMemorySummary](#graphicsmemorysummary21)&gt; | promise对象，返回应用显存数据。 |

**错误码**：

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------------------------- |
| 11400104 | Failed to get the application memory due to a remote exception. |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

hidebug.getGraphicsMemorySummary().then((ret: hidebug.GraphicsMemorySummary) => {
  console.info(`get graphicsMemory gl: ${ret.gl} graph: ${ret.graph}.`)
}).catch((error: BusinessError) => {
  console.error(`error code: ${error.code}, error msg: ${error.message}.`);
})
```

## hidebug.dumpJsRawHeapData<sup>18+</sup>

dumpJsRawHeapData(needGC?: boolean): Promise&lt;string&gt;

为当前线程转储虚拟机的原始堆快照，并生成的rawheap格式文件，使用Promise异步回调完成。该文件可通过[rawheap-translator工具](../../tools/rawheap-translator.md)转化为heapsnapshot格式文件进行解析。

> **注意**：
>
> 系统通过该接口转储快照会消耗大量资源，因此严格限制了调用频率和次数。处理完生成的文件后，请立即删除。
>
> 建议在开发者模式下调用该接口，可免除调用配额限制，当设置的开发者选项开关打开并重启设备后即可生效。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名                     | 类型      | 必填 | 说明                                          |
|-------------------------|---------|----|---------------------------------------------|
| needGC         | boolean | 否  | 转储堆快照前是否需要GC。true：需要GC。false：不需GC。默认值：true。 |

**返回值**：

| 类型  | 说明                                                                                                   |
| ------ |------------------------------------------------------------------------------------------------------|
| Promise&lt;string&gt; | Promise对象，返回生成的快照文件路径（[应用沙箱内路径](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)）。 |

**错误码**：

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

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';
hidebug.dumpJsRawHeapData().then((filePath: string) => {
  console.info(`dumpJsRawHeapData success and generated file path is ${filePath}`)
}).catch((error: BusinessError) => {
  console.error(`error code: ${error.code}, error msg: ${error.message}`);
})
```

## hidebug.dumpJsRawHeapData<sup>24+</sup>

dumpJsRawHeapData(needGC: boolean, needClean: boolean): Promise&lt;string&gt;

为当前线程转储虚拟机的原始堆快照，并支持清除nodeId缓存。生成的文件为rawheap格式，使用Promise异步回调完成。该文件可通过[rawheap-translator工具](../../tools/rawheap-translator.md)转化为heapsnapshot格式文件进行解析。

> **注意**：
>
> 系统通过该接口转储快照会消耗大量资源，因此严格限制了调用频率和次数。处理完生成的文件后，请立即删除。
>
> 建议在开发者模式下调用该接口，可免除调用配额限制，当设置的开发者选项开关打开并重启设备后即可生效。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**参数**：

| 参数名                     | 类型      | 必填 | 说明                                          |
|-------------------------|---------|----|---------------------------------------------|
| needGC         | boolean | 是  | 转储堆快照前是否需要GC。true：需要GC；false：不需要GC。 |
| needClean      | boolean | 是  | 转储堆快照前是否需要清除nodeId。true：需要清除；false：不需要清除。|

**返回值**：

| 类型  | 说明                                                                                                   |
| ------ |------------------------------------------------------------------------------------------------------|
| Promise&lt;string&gt; | Promise对象，返回生成的快照文件路径（[应用沙箱内路径](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)）。 |

**错误码**：

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

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

hidebug.dumpJsRawHeapData(true, true).then((filePath: string) => {
  console.info(`dumpJsRawHeapData success and generated file path is ${filePath}`);
}).catch((error: BusinessError) => {
  console.error(`error code: ${error.code}, error msg: ${error.message}`);
})
```

## hidebug.dumpJsRawHeapData

dumpJsRawHeapData(needGC: boolean, needClean: boolean, processDump: boolean): Promise&lt;Array&lt;string&gt;&gt;

为当前线程或其所属进程生成虚拟机的原始堆快照，并支持清除nodeId缓存，生成的文件为rawheap格式。使用Promise异步回调。文件可通过[rawheap-translator工具](../../tools/rawheap-translator.md)转换为heapsnapshot格式文件进行解析。
> **注意**：
>
> 系统通过该接口转储快照会消耗大量资源，因此严格限制了调用频率和次数。处理完生成的文件后，请立即删除。
>
> 建议在开发者模式下调用该接口，可免除调用配额限制，当设置的开发者选项开关打开并重启设备后即可生效。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**原子化服务API**：从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名                     | 类型      | 必填 | 说明                                          |
|-------------------------|---------|----|---------------------------------------------|
| needGC         | boolean | 是  | 转储堆快照前是否需要GC。true：需要GC；false：不需要GC。|
| needClean      | boolean | 是  | 转储堆快照前是否需要清除nodeId。true：需要清除；false：不需要清除。|
| processDump      | boolean | 是  | 是否转储当前线程所属进程的原始堆快照。true：转储当前线程所属进程的原始堆快照。|

**返回值**：

| 类型  | 说明                                                                                                   |
| ------ |------------------------------------------------------------------------------------------------------|
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回生成的快照文件路径数组（[应用沙箱内路径](../../file-management/app-sandbox-directory.md#应用沙箱路径和真实物理路径的对应关系)）。 |

**错误码**：

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

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

hidebug.dumpJsRawHeapData(true, true, true).then((filePathArray: Array<string>) => {
  console.info(`dumpJsRawHeapData success and generated file path is ${JSON.stringify(filePathArray)}`);
}).catch((error: BusinessError) => {
  console.error(`error code: ${error.code}, error msg: ${error.message}`);
})
```

## hidebug.enableGwpAsanGrayscale<sup>20+</sup>

enableGwpAsanGrayscale(options?: GwpAsanOptions, duration?: number): void

使能GWP-ASan，用于检测堆内存使用中的非法行为。

该接口主要用于动态配置并启用GWP-ASan，以适配应用自定义的GWP-ASan检测策略。配置在应用重新启动后生效。

更多关于GWP-ASan的说明，请参见[使用GWP-ASan检测内存错误](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-gwpasan-detection)。

> **说明**：
> 
> 1. 若设备运行期间通过本接口设置的GWP-ASan应用数量超过配额限制，调用该接口将会失败并抛出错误码。请使用try-catch捕获异常，以避免应用异常退出。
> 2. 设备重启后，本接口设置的GWP-ASan参数将会失效。
> 3. 由于该接口涉及跨进程通信，耗时较长，为了避免引入性能问题，建议不要在主线程中直接调用该接口。可以通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程，以避免应用卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名   | 类型   | 必填 | 说明   |
|---------|---------|--------|-----|
| options | [GwpAsanOptions](#gwpasanoptions20) | 否 | GWP-ASan配置项。未设置时，使用默认参数。|
| duration | number | 否 | GWP-ASan持续时间，单位为天，默认值为7。需传入大于0的正整数。 |

**错误码**：

以下错误码的详细介绍请参见[HiDebug错误码](errorcode-hiviewdfx-hidebug.md)。

| 错误码ID    | 错误信息 |
|----------| ----------------------------------------------------------------- |
| 11400114 | The number of GWP-ASAN applications of this device overflowed after last boot. |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { taskpool } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

@Concurrent
function enableGwpAsanTask(): void {
  let options: hidebug.GwpAsanOptions = {
    alwaysEnabled: true,
    sampleRate: 2500,
    maxSimutaneousAllocations: 5000,
  };
  let duration: number = 4;
  hidebug.enableGwpAsanGrayscale(options, duration);
}

taskpool.execute(enableGwpAsanTask).then(() => {
  console.info(`Succeeded in enabling GWP-ASan.`);
}).catch((error: BusinessError) => {
  const err: BusinessError = error as BusinessError;
  console.error(`Failed to enable GWP-ASan. Code: ${err.code}, message: ${err.message}`);
})
```
## GwpAsanOptions<sup>20+</sup>
GWP-ASan配置项。可用于配置是否使能、采样频率，以及最大分配的插槽数。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称         | 类型  | 只读  | 可选 | 说明 |
|--------------|------|-------|-------|-----|
|alwaysEnabled | boolean | 否  | 是 | true：100%使能GWP-ASan。<br/>false：1/128概率使能GWP-ASan。<br/> 默认值：false。|
|sampleRate    |number| 否  |是|GWP-ASan采样频率，默认值为2500，需要传入大于0的正整数，若传入小数则向上取整。<br/> 1/sampleRate的概率对分配的内存进行采样。<br/> 建议值：>=1000，过小会显著影响性能。|
|maxSimutaneousAllocations|number|否|是|最大分配的插槽数，默认值为1000，需要传入大于0的正整数，若传入小数则向上取整。<br/>当插槽用尽时，新分配的内存将不再受监控。<br/>释放已使用的内存后，其占用的插槽将自动复用，以便于后续内存的监控。<br/> 建议值：<=20000，过大会可能导致VMA超限崩溃。|
|isRecover<sup>24+</sup>|boolean|否|是|用于控制应用以100%概率开启GWP-ASan时，是否以可恢复模式运行。<br/>true：当GWP-ASan以100%概率开启时，应用以可恢复模式运行。在该模式下，系统检测到地址越界故障后，避免因检测机制本身导致进程崩溃；但对于已造成非法内存访问的错误，应用仍可能发生崩溃。<br/>false：当GWP-ASan以100%概率开启时，应用以不可恢复模式运行。<br/>默认值：false。<br/>注意：该参数只在“以100%概率开启GWP-ASan”场景下生效；1/128概率开启场景下默认为可恢复，不受isRecover控制。<br>**模型约束**：此接口仅可在Stage模型下使用。|

## hidebug.disableGwpAsanGrayscale<sup>20+</sup>
disableGwpAsanGrayscale(): void

停止使能GWP-ASan。调用该接口将取消自定义配置，恢复默认参数[GwpAsanOptions](#gwpasanoptions20)。

> **说明**：
> 
> 由于该接口涉及跨进程通信，耗时较长，为了避免引入性能问题，建议不要在主线程中直接调用该接口。可以通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程，以避免应用卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { taskpool } from '@kit.ArkTS';

@Concurrent
function disableGwpAsanTask(): void {
  hidebug.disableGwpAsanGrayscale();
}
taskpool.execute(disableGwpAsanTask).then(() => {
  console.info(`Disable GWP-ASan succeeded.`);
})
```

## hidebug.getGwpAsanGrayscaleState<sup>20+</sup>
getGwpAsanGrayscaleState(): number

获取当前GWP-ASan剩余使能天数。

> **说明**：
> 
> 由于该接口涉及跨进程通信，耗时较长，为了避免引入性能问题，建议不要在主线程中直接调用该接口。可以通过[@ohos.taskpool](../apis-arkts/js-apis-taskpool.md)或[@ohos.worker](../apis-arkts/js-apis-worker.md)开启异步线程，以避免应用卡顿。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**返回值**：

| 类型 | 说明 |
|-----------|-------------|
| number    |获取当前GWP-ASan剩余使能天数。若当前未使能，返回值0。|

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';
import { taskpool } from '@kit.ArkTS';

@Concurrent
function getGwpAsanStateTask(): number {
  return hidebug.getGwpAsanGrayscaleState();
}
taskpool.execute(getGwpAsanStateTask).then((remainDays: Object) => {
  console.info(`GWP-ASan remain days: ${remainDays as number}.`);
})
```

## hidebug.setJsRawHeapTrimLevel<sup>20+</sup>

setJsRawHeapTrimLevel(level: JsRawHeapTrimLevel): void

设置当前进程转储虚拟机原始堆快照的裁剪级别。使用该接口并传入参数TRIM_LEVEL_2，可以有效减少堆快照的文件大小。

> **注意**：
>
> 默认裁剪级别是TRIM_LEVEL_1。如果设置了TRIM_LEVEL_2裁剪，需使用API version 20之后的[rawheap-translator](../../tools/rawheap-translator.md)工具才能将.rawheap文件转换为.heapsnapshot文件，否则可能导致转换失败。
>
> 该接口影响[dumpJsRawHeapData](#hidebugdumpjsrawheapdata18)的结果。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名 | 类型                                        | 必填 | 说明                   |
| ------ | ------------------------------------------- | ---- | ---------------------- |
| level  | [JsRawHeapTrimLevel](#jsrawheaptrimlevel20) | 是   | 转储堆快照的裁剪级别，默认为TRIM_LEVEL_1。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.setJsRawHeapTrimLevel(hidebug.JsRawHeapTrimLevel.TRIM_LEVEL_2);
```

## GraphicsMemorySummary<sup>21+</sup>

描述应用显存数据，包括gl和graph部分。

**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

| 名称      | 类型     | 只读  | 可选 | 说明                                                                              |
| --------- |--------| ---- |---- |---------------------------------------------------------------------------------|
| gl  | number |  否  |   否  | gl显存大小，RenderService渲染进程加载所需资源占用的内存，例如图片、纹理等，以KB为单位。 |
| graph  | number |  否  |   否  | graph显存大小，进程统计的DMA内存占用，包括直接通过接口申请的DMA buffer和通过allocator_host申请的DMA buffer，以KB为单位。 |

## hidebug.setProcDumpInSharedOOM<sup>24+</sup>

setProcDumpInSharedOOM(enable: boolean): void

将转储的堆快照由线程级改为进程级。

> **注意**：
>
> 要想转储进程级的堆快照，调用该接口并传参true、进程OOM时发生的是SharedHeap OOM，两个条件缺一不可。
>
> 该接口不影响其他场景下转储的堆快照内容。如：不会影响[dumpJsRawHeapData](#hidebugdumpjsrawheapdata18)的结果。
>
> 该接口在应用的生命周期内可被多次调用，但仅最后一次调用的执行结果会生效。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

**参数**：

| 参数名         | 类型  | 必填 | 说明 |
|--------------|------|------|------|
| enable | boolean | 是 | 当进程发生SharedHeap OOM时，系统将依据该进程在其生命周期中最后一次调用该接口所记录的信息，转储相应级别的堆快照。<br/>true：进程级。<br/>false：线程级。<br/> 默认值：false。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

hidebug.setProcDumpInSharedOOM(true);
```

## hidebug.getRssInfo<sup>24+</sup>

getRssInfo(): RssInfo

获取应用程序进程的物理内存使用信息。读取/proc/{pid}/status节点的数据。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.HiviewDFX.HiProfiler.HiDebug

> **注意**：
>
> 读取/proc/{pid}/status耗时很短，与[hidebug.getAppNativeMemInfo](#hidebuggetappnativememinfo12)接口中获取的`rss`值相比存在一点误差，但该接口更加轻量，为避免应用丢帧或卡顿推荐使用该接口。

**返回值**：

| 类型  | 说明                      |
| ------ | -------------------------- |
| [RssInfo](#rssinfo24) | 应用进程的物理内存信息。 |

**示例**：

```ts
import { hidebug } from '@kit.PerformanceAnalysisKit';

let rssInfo: hidebug.RssInfo = hidebug.getRssInfo();
console.info(`rss: ${rssInfo.rss}, swapRss: ${rssInfo.swapRss}`);
```