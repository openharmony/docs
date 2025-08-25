# @ohos.bytrace (性能打点)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

本模块提供了追踪进程轨迹。

> **说明：**
> - 从API Version 8开始，该接口不再维护，推荐使用新接口[`@ohos.hiTraceMeter`](js-apis-hitracemeter.md)。
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { bytrace } from '@kit.PerformanceAnalysisKit';
```

## bytrace.startTrace

startTrace(name: string, taskId: number, expectedTime?: number): void

标记一个时间片跟踪任务的开始。

> **说明：**
> 如果有多个相同name的任务需要追踪或者对同一个任务要追踪多次，并且这些跟踪任务会同时被执行，则每次调用startTrace的taskId必须不一致。如果具有相同name的跟踪任务是串行执行的，则taskId可以相同。在下面bytrace.finishTrace的示例中会举例说明。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 时间片跟踪任务名称 |
| taskId | number | 是 | 时间片跟踪任务id |
| expectedTime | number | 否 | 期望的耗时时间（单位：ms）。可选，默认为空 |


**示例：**

```js
bytrace.startTrace("myTestFunc", 1);
bytrace.startTrace("myTestFunc", 1, 5); // 从startTrace到finishTrace流程的期望耗时为5ms
```

## bytrace.finishTrace

finishTrace(name: string, taskId: number): void

标记一个时间片跟踪事件的结束。

> **说明：**<br>
> finishTrace的name和taskId必须与流程开始的startTrace对应参数值一致。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 时间片跟踪任务名称 |
| taskId | number | 是 | 时间片跟踪任务id |


**示例：**

```js
bytrace.finishTrace("myTestFunc", 1);
```

```
// 跟踪并行执行的同名任务
bytrace.startTrace("myTestFunc", 1);
// 业务流程...... 
bytrace.startTrace("myTestFunc", 2);  // 第二个跟踪任务开始，同时第一个同名跟踪任务还没结束，出现了并行执行，对应接口的taskId需要不同
// 业务流程...... 
bytrace.finishTrace("myTestFunc", 1);
// 业务流程...... 
bytrace.finishTrace("myTestFunc", 2);
```

```
// 跟踪串行执行的同名任务
bytrace.startTrace("myTestFunc", 1);
// 业务流程...... 
bytrace.finishTrace("myTestFunc", 1);  // 第一个跟踪任务结束
// 业务流程...... 
bytrace.startTrace("myTestFunc", 1);   // 第二个跟踪任务开始，同名跟踪任务串行执行
// 业务流程...... 
bytrace.finishTrace("myTestFunc", 1);
```

## bytrace.traceByValue

traceByValue(name: string, count: number): void

标记预追踪耗时任务的数值变量，该变量的数值会不断变化。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 数值变量的名称 |
| count | number | 是 | 数值变量的值 |

**示例：**

```js
let traceCount = 3;
bytrace.traceByValue("myTestCount", traceCount);
traceCount = 4;
bytrace.traceByValue("myTestCount", traceCount);
// 业务流程......
```
