# @ohos.hiTraceMeter (性能打点)

本模块提供了跟踪进程轨迹，度量程序执行性能的打点能力。本模块打点的数据供hiTraceMeter工具分析使用。
详细开发流程请参考：[性能打点跟踪开发指导](../../dfx/hitracemeter-guidelines-arkts.md)。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import { hiTraceMeter } from '@kit.PerformanceAnalysisKit';
```


## hiTraceMeter.startTrace

startTrace(name: string, taskId: number): void

标记一个预跟踪耗时任务的开始。

如果有多个相同name的任务需要跟踪或者对同一个任务要跟踪多次，并且任务同时被执行，则每次调用startTrace的taskId不相同。

如果具有相同name的任务是串行执行的，则taskId可以相同。具体示例可参考[hiTraceMeter.finishTrace](#hitracemeterfinishtrace)中的示例。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 要跟踪的任务名称 |
| taskId | number | 是 | 任务id |

**示例：**

```js
hiTraceMeter.startTrace("myTestFunc", 1);
```


## hiTraceMeter.finishTrace

finishTrace(name: string, taskId: number): void

标记一个预跟踪耗时任务的结束。

finishTrace的name和taskId必须与流程开始的[startTrace](#hitracemeterstarttrace)对应参数值一致。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 要跟踪的任务名称 |
| taskId | number | 是 | 任务id。 |

**示例：**

```js
hiTraceMeter.finishTrace("myTestFunc", 1);
```

```js
// 跟踪并行执行的同名任务
hiTraceMeter.startTrace("myTestFunc", 1);
// 业务流程...... 
hiTraceMeter.startTrace("myTestFunc", 2);  // 第二个跟踪的任务开始，同时第一个跟踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同。
// 业务流程...... 
hiTraceMeter.finishTrace("myTestFunc", 1);
// 业务流程...... 
hiTraceMeter.finishTrace("myTestFunc", 2);
```

```js
// 跟踪串行执行的同名任务
hiTraceMeter.startTrace("myTestFunc", 1);
// 业务流程...... 
hiTraceMeter.finishTrace("myTestFunc", 1);  // 第一个跟踪的任务结束
// 业务流程...... 
hiTraceMeter.startTrace("myTestFunc", 1);   // 第二个跟踪的同名任务开始，同名的待跟踪任务串行执行。
// 业务流程...... 
hiTraceMeter.finishTrace("myTestFunc", 1);
```


## hiTraceMeter.traceByValue

traceByValue(name: string, count: number): void

用来标记一个预跟踪的数值变量，该变量的数值会不断变化。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 要跟踪的数值变量名称 |
| count | number | 是 | 变量的值 |

**示例：**
```js
let traceCount = 3;
hiTraceMeter.traceByValue("myTestCount", traceCount);
traceCount = 4;
hiTraceMeter.traceByValue("myTestCount", traceCount);
//业务流程......
```
