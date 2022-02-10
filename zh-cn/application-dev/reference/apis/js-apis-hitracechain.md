# 分布式跟踪

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import hiTraceChain from '@ohos.hiTraceChain';
```

## 系统能力

SystemCapability.HiviewDFX.HiTrace

## HiTraceFlag

跟踪标志组合类型枚举。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| DEFAULT           | 0      | 缺省标志       |
| INCLUDE_ASYNC     | 1      | 异步调用标志   |
| DONOT_CREATE_SPAN | 1 << 1 | 无分支标志     |
| TP_INFO           | 1 << 2 | 埋点标志       |
| NO_BE_INFO        | 1 << 3 | 无起始结束标志 |
| DONOT_ENABLE_LOG  | 1 << 4 | 日志关联标志   |
| FAILURE_TRIGGER   | 1 << 5 | 故障触发标志   |
| D2D_TP_INFO       | 1 << 6 | 设备间埋点标志 |

## HiTraceTracePointType

跟踪埋点类型枚举。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| CS       | 0 | 客户端发送类型  |
| CR       | 1 | 客户端接收类型  |
| SS       | 2 | 服务端发送类型  |
| SR       | 3 | 服务端接收类型  |
| GENERAL  | 4 | 常规类型        |

## HiTraceCommunicationMode

跟踪通信类型枚举。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| DEFAULT  | 0 | 缺省方式        |
| THREAD   | 1 | 线程间通信类型  |
| PROCESS  | 2 | 进程间通信类型  |
| DEVICE   | 3 | 设备间通信类型  |

## HiTraceId

此接口为HiTraceId对象接口。

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| chainId      | bigint | 是 | 跟踪链标识。   |
| spandId      | number | 否 | 分支标识。     |
| parentSpanId | number | 否 | 父分支标识。   |
| flags        | number | 否 | 跟踪标志组合。 |

## hiTraceChain.begin

begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId

开始跟踪，同步接口。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | name  | string | 是 | 跟踪业务名。 |
  | flags | number | 是 | [跟踪标志组合](#hitraceflag)。 |
- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [HiTraceId](#hitraceid) | HiTraceId实例。 |

- 示例：
  ```
  let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
  ```

## hiTraceChain.end

end(id: HiTraceId): void

结束跟踪，同步接口。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | [HiTraceId](#hitraceid) | 是 | HiTraceId实例。 |

- 示例：
  ```
  let asyncTraceId = hiTraceChain.begin("business");
  // 若干业务逻辑完成后，结束跟踪。
  hiTraceChain.end(asyncTraceId);
  ```

## hiTraceChain.getId

getId(): HiTraceId

获取跟踪标识，同步接口。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [HiTraceId](#hitraceid) | HiTraceId实例。 |

- 示例：
  ```
  let traceId = hiTraceChain.begin("business");
  // 若干业务逻辑完成后，获取当前HiTraceId。
  let curTraceId = hiTraceChain.getId();
  ```

## hiTraceChain.setId

setId(id: HiTraceId): void

设置跟踪标识，同步接口。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | [HiTraceId](#hitraceid) | 是 | HiTraceId实例。 |

- 示例：
  ```
  let traceId = hiTraceChain.begin("business");
  // 若干业务逻辑完成后，设置当前HiTraceId。
  hiTraceChain.setId(asyncTraceId);
  ```

## hiTraceChain.clearId

clearId(): void

清除跟踪标识，同步接口。

- 示例：
  ```
  let traceId = hiTraceChain.begin("business");
  // 若干业务逻辑完成后，清除当前HiTraceId。
  hiTraceChain.clearId();
  ```

## hiTraceChain.createSpan

createSpan(): HiTraceId

创建跟踪分支，同步接口。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [HiTraceId](#hitraceid) | HiTraceId实例。 |

- 示例：
  ```
  let traceId = hiTraceChain.begin("business");
  // 若干业务逻辑完成后，创建跟踪分支。
  let spanTraceId = hiTraceChain.createSpan();
  ```

## hiTraceChain.tracepoint

tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracePointType, id: HiTraceId, msg?: string): void

信息埋点，同步接口。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | mode | [HiTraceCommunicationMode](#hitracecommunicationmode) | 是 | 信息埋点需要指定的跟踪通信模式。 |
  | type | [HiTraceTracePointType](#hitracetracepointtype)| 是 | 信息埋点需要指定的跟踪埋点类型。 |
  | id   | [HiTraceId](#hitraceid) | 是 | 实施信息埋点操作的HiTraceId实例。 |
  | msg  | string | 否 | 信息埋点操作传入的trace说明信息。 |

- 示例：
  ```
  let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
  // 若干业务逻辑完成后，触发信息埋点操作。
  hiTraceChain.tracepoint(hiTraceChain.HiTraceCommunicationMode.THREAD, hiTraceChain.HiTraceTracePointType.SS, asyncTraceId, "Just a example");
  ```

## hiTraceChain.isValid

isValid(id: HiTraceId): boolean

判断HiTraceId对象是否有效，同步接口。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id  | [HiTraceId](#hitraceid) | 是 | 需要判断是否有效的HiTraceId实例。 |
- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回true表示HiTraceId有效，否则无效。 |

- 示例：
  ```
  let traceId = hiTraceChain.begin("business");
  let traceIdIsvalid = hiTraceChain.isValid(traceId);
  ```

## hiTraceChain.isFlagEnabled

isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean

判断HiTraceId对象中指定的跟踪标志是否已置位，同步接口。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id  | [HiTraceId](#hitraceid) | 是 | 需要判断指定跟踪标志是否置位的HiTraceId实例。 |
  | flag | [HiTraceFlag](#hitraceflag) | 是 | 指定的跟踪标志。 |
- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回true标识HiTraceId已置位指定的flag，否则没有置位。 |
- 示例：
  ```
  let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
  // enabledDoNotCreateSpanFlag为true
  let enabledDoNotCreateSpanFlag = hiTraceChain.isFlagEnabled(asyncTraceId, hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
  ```

## hiTraceChain.enableFlag

enableFlag(id: HiTraceId, flag: HiTraceFlag): void

置位HiTraceId对象中指定的跟踪标志，同步接口。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id  | [HiTraceId](#hitraceid) | 是 | 需要置位指定跟踪标志的HiTraceId实例。 |
  | flag | [HiTraceFlag](#hitraceflag) | 是 | 指定的跟踪标志。 |

- 示例：
  ```
  let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
  hiTraceChain.enable(asyncTraceId, hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
  // enabledDoNotCreateSpanFlag为true
  let enabledDoNotCreateSpanFlag = hiTraceChain.isFlagEnabled(asyncTraceId, hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
  ```
