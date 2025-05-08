# @ohos.hiTraceChain (分布式跟踪)

本模块提供了端侧业务流程调用链跟踪的打点能力，包括业务流程跟踪的启动、结束、信息埋点等能力。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { hiTraceChain } from '@kit.PerformanceAnalysisKit';
```

## HiTraceFlag

跟踪标志组合类型枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiTrace。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DEFAULT           | 0      | 缺省标志。       |
| INCLUDE_ASYNC     | 1      | 异步调用标志。启动跟踪时，缺省只跟踪同步调用。设置该标志，同时跟踪同步、异步调用。   |
| DONOT_CREATE_SPAN | 1 << 1 | 无分支标志。启动跟踪时，在同步、异步调用时缺省自动创建分支信息。设置该标志，指示不创建分支。     |
| TP_INFO           | 1 << 2 | 埋点标志。启动跟踪式时，缺省不进行埋点。调试场景下设置该标志，在同步、异步调用的收发侧自动埋点，输出埋点信息和时间戳。收发埋点按照client、server分为[client send（CS）、server receive（SR）、server send（SS）、client receive（CR）](#hitracetracepointtype)四类信息。一次同步调用输出CS/SR/SS/CR，一次异步调用输出CS/SR/SS三个埋点信息。       |
| NO_BE_INFO        | 1 << 3 | 无起始结束标志。启动跟踪时，缺省打印启动及结束跟踪信息。设置该标志，指示不打印启动及结束跟踪信息。 |
| DISABLE_LOG       | 1 << 4 | 日志关联标志。设置该标志，指示隐藏日志中的跟踪信息。  |
| FAILURE_TRIGGER   | 1 << 5 | 故障触发标志。预置标志，暂时没有作用。  |
| D2D_TP_INFO       | 1 << 6 | 设备间埋点标志。TP_INFO的一个子集，设置该标志，只进行设备间的调用埋点。 |

## HiTraceTracepointType

跟踪埋点类型枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiTrace。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| CS       | 0 | 客户端发送类型，标识client侧的发送埋点。        |
| CR       | 1 | 客户端接收类型，标识client侧的接收埋点。        |
| SS       | 2 | 服务端发送类型，标识server侧的发送埋点。        |
| SR       | 3 | 服务端接收类型，标识server侧的接收埋点。        |
| GENERAL  | 4 | 一般类型，标识CS、CR、SS、SR四种场景之外的埋点。|

## HiTraceCommunicationMode

跟踪通信类型枚举。

**系统能力**：以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiTrace。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DEFAULT  | 0 | 缺省通信类型。    |
| THREAD   | 1 | 线程间通信类型。  |
| PROCESS  | 2 | 进程间通信类型。  |
| DEVICE   | 3 | 设备间通信类型。  |

## HiTraceId

此接口为HiTraceId对象接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.HiviewDFX.HiTrace。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| chainId      | bigint | 是 | 跟踪链标识。   |
| spanId      | number | 否 | 分支标识。     |
| parentSpanId | number | 否 | 父分支标识。   |
| flags        | number | 否 | 跟踪标志组合。 |

## hiTraceChain.begin

begin(name: string, flags?: number): HiTraceId

开始跟踪，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name  | string | 是 | 跟踪业务名。 |
| flags | number | 否 | 跟踪标志组合，具体可参考[HiTraceFlag](#hitraceflag)。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [HiTraceId](#hitraceid) | HiTraceId实例。 |

**示例：**

```ts
// 开启跟踪，跟踪标志是INCLUDE_ASYNC与DONOT_CREATE_SPAN的并集。
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
// 若干业务逻辑完成后，结束跟踪。
hiTraceChain.end(traceId);
```

## hiTraceChain.end

end(id: HiTraceId): void

结束跟踪，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| id | [HiTraceId](#hitraceid) | 是 | HiTraceId实例。 |

**示例：**

```ts
// 开启跟踪，跟踪标志是DEFAULT。
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// 若干业务逻辑完成后，结束跟踪。
hiTraceChain.end(traceId);
```

## hiTraceChain.getId

getId(): HiTraceId

获取跟踪标识，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [HiTraceId](#hitraceid) | HiTraceId实例。 |

**示例：**

```ts
// 开启跟踪，跟踪标志是DEFAULT。
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// 若干业务逻辑完成后，获取当前跟踪标识。
let curTraceId = hiTraceChain.getId();
// 同一跟踪链获取的跟踪标识的chainId一定相同。
if (curTraceId.chainId != traceId.chainId) {
// 基于异常场景的处理逻辑。
}
// 若干业务逻辑完成后，结束跟踪。
hiTraceChain.end(traceId);
```

## hiTraceChain.setId

setId(id: HiTraceId): void

设置跟踪标识，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| id | [HiTraceId](#hitraceid) | 是 | HiTraceId实例。 |

**示例：**

```ts
// 获取当前跟踪链中的跟踪标识。
let traceId = hiTraceChain.getId();
// 将获取的跟踪标识设置为当前traceId。
hiTraceChain.setId(traceId);
```

## hiTraceChain.clearId

clearId(): void

清除跟踪标识，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**示例：**

```ts
// 业务开始前，尝试清除跟踪标识。
hiTraceChain.clearId();
// 开启跟踪，跟踪标志是DEFAULT。
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// 若干业务逻辑完成后，结束跟踪。
hiTraceChain.end(traceId);
```

## hiTraceChain.createSpan

createSpan(): HiTraceId

创建跟踪分支，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [HiTraceId](#hitraceid) | HiTraceId实例。 |

**示例：**

```ts
// 开启跟踪，跟踪标志是DEFAULT。
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// 若干业务逻辑完成后，创建跟踪分支。
let spanTraceId = hiTraceChain.createSpan();
// 同一跟踪链的跟踪标识的chainId一定相同。
if (spanTraceId.chainId != traceId.chainId) {
// 基于异常场景的处理逻辑。
}
//业务结束，关闭跟踪。
hiTraceChain.end(traceId);
```

## hiTraceChain.tracepoint

tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void

信息埋点，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mode | [HiTraceCommunicationMode](#hitracecommunicationmode) | 是 | 信息埋点需要指定的跟踪通信模式。 |
| type | [HiTraceTracepointType](#hitracetracepointtype)| 是 | 信息埋点需要指定的跟踪埋点类型。 |
| id   | [HiTraceId](#hitraceid) | 是 | 实施信息埋点操作的HiTraceId实例。 |
| msg  | string | 否 | 信息埋点操作传入的trace说明信息。 |

**示例：**

```ts
// 开启跟踪，跟踪标志是INCLUDE_ASYNC与DONOT_CREATE_SPAN的并集。
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
// 若干业务逻辑完成后，触发信息埋点操作。
hiTraceChain.tracepoint(hiTraceChain.HiTraceCommunicationMode.THREAD, hiTraceChain.HiTraceTracepointType.SS, traceId, "Just a example");
//业务结束，关闭跟踪。
hiTraceChain.end(traceId);
```

## hiTraceChain.isValid

isValid(id: HiTraceId): boolean

判断HiTraceId对象是否有效，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| id  | [HiTraceId](#hitraceid) | 是 | 需要判断是否有效的HiTraceId实例。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回true表示HiTraceId有效，否则无效。 |

**示例：**

```ts
// 开启跟踪，跟踪标志是DEFAULT。
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// traceIdIsvalid为true
let traceIdIsvalid = hiTraceChain.isValid(traceId);
if (traceIdIsvalid) {
// 基于跟踪标识合法性校验成功的场景的处理逻辑。
}
//业务结束，关闭跟踪。
hiTraceChain.end(traceId);
```

## hiTraceChain.isFlagEnabled

isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean

判断HiTraceId对象中指定的跟踪标志是否已置位，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| id  | [HiTraceId](#hitraceid) | 是 | 需要判断指定跟踪标志是否置位的HiTraceId实例。 |
| flag | [HiTraceFlag](#hitraceflag) | 是 | 指定的跟踪标志。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回true标识HiTraceId已置位指定的flag，否则没有置位。 |

**示例：**

```ts
// 开启跟踪，跟踪标志是INCLUDE_ASYNC。
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
// enabledIncludeAsyncFlag为true。
let enabledIncludeAsyncFlag = hiTraceChain.isFlagEnabled(traceId, hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
if (enabledIncludeAsyncFlag) {
// 基于INCLUDE_ASYNC跟踪标志已设置场景的处理逻辑。
}
//业务结束，关闭跟踪。
hiTraceChain.end(traceId);
```

## hiTraceChain.enableFlag

enableFlag(id: HiTraceId, flag: HiTraceFlag): void

置位HiTraceId对象中指定的跟踪标志，同步接口。

**系统能力**：SystemCapability.HiviewDFX.HiTrace

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| id  | [HiTraceId](#hitraceid) | 是 | 需要置位指定跟踪标志的HiTraceId实例。 |
| flag | [HiTraceFlag](#hitraceflag) | 是 | 指定的跟踪标志。 |

**示例：**

```ts
// 开启跟踪，跟踪标志是INCLUDE_ASYNC。
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
// enabledDoNotCreateSpanFlag为false。
let enabledDoNotCreateSpanFlag = hiTraceChain.isFlagEnabled(traceId, hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
// 设置DONOT_CREATE_SPAN跟踪标志。
hiTraceChain.enableFlag(traceId, hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
// enabledDoNotCreateSpanFlag为true。
enabledDoNotCreateSpanFlag = hiTraceChain.isFlagEnabled(traceId, hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
if (enabledDoNotCreateSpanFlag) {
// 基于DONOT_CREATE_SPAN跟踪标志已设置场景的处理逻辑。
}
//业务结束，关闭跟踪。
hiTraceChain.end(traceId);
```
