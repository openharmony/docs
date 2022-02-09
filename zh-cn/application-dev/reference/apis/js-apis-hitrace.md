# 分布式跟踪

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import hitrace from '@ohos.hitrace';
```

## 权限

无

## hitrace.HiTraceFlag

跟踪标志组合类型枚举

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

## hitrace.HiTraceTracePointType

跟踪埋点类型枚举

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| CS       | 0 | 客户端发送类型  |
| CR       | 1 | 客户端接收类型  |
| SS       | 2 | 服务端发送类型  |
| SR       | 3 | 服务端接收类型  |
| GENERAL  | 4 | 常规类型        |

## hitrace.HiTraceCommunicationMode

跟踪通信类型枚举

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| DEFAULT  | 0 | 缺省方式        |
| THREAD   | 1 | 线程间通信类型  |
| PROCESS  | 2 | 进程间通信类型  |
| DEVICE   | 3 | 设备间通信类型  |

## hitrace.HiTraceId

此接口为HiTraceId对象接口

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| chainId      | bigint | 是 | 跟踪链标识。   |
| spandId      | number | 否 | 分支标识。     |
| parentSpanId | number | 否 | 父分支标识。   |
| flags        | number | 否 | 跟踪标志组合。 |

## hitrace.begin

begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId

跟踪开始同步接口

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | name  | string | 是 | 跟踪业务名。 |
  | flags | number | 是 | [跟踪标志组合](#hitracehitraceflag)。 |
- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [HiTraceId](#hitracehitraceid) | HiTraceId实例。 |

- 示例：
  ```
  let asyncTraceId = hitrace.begin("business", hitrace.HiTraceFlag.INCLUDE_ASYNC | hitrace.HiTraceFlag.DONOT_CREATE_SPAN);
  ```

## hitrace.end

end(id: HiTraceId): void

跟踪结束同步接口

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | [HiTraceId](#hitracehitraceid) | 是 | HiTraceId实例。 |

- 示例：
  ```
  let asyncTraceId = hitrace.begin("business");
  ...
  hitrace.end(asyncTraceId);
  ```

## hitrace.getId

getId(): HiTraceId

获取跟踪标识同步接口

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [HiTraceId](#hitracehitraceid) | HiTraceId实例。 |

- 示例：
  ```
  let traceId = hitrace.begin("business");
  ...
  let curTraceId = hitrace.getId();
  ...
  ```

## hitrace.setId

setId(id: HiTraceId): void

设置跟踪标识同步接口

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id | [HiTraceId](#hitracehitraceid) | 是 | HiTraceId实例。 |

- 示例：
  ```
  let traceId = hitrace.begin("business");
  ...
  hitrace.setId(asyncTraceId);
  ...
  ```

## hitrace.clearId

clearId(): void

清除跟踪标识同步接口

- 示例：
  ```
  let traceId = hitrace.begin("business");
  ...
  hitrace.clearId();
  ...
  ```

## hitrace.createSpan

createSpan(): HiTraceId

创建跟踪分支同步接口

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | [HiTraceId](#hitracehitraceid) | HiTraceId实例。 |

- 示例：
  ```
  let traceId = hitrace.begin("business");
  ...
  let spanTraceId = hitrace.createSpan();
  ...
  ```

## hitrace.tracepoint

tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracePointType, id: HiTraceId, msg?: string): void

信息埋点同步接口

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | mode | [HiTraceCommunicationMode](#hitracehitracecommunicationmode) | 是 | 信息埋点需要指定的跟踪通信模式。 |
  | type | [HiTraceTracePointType](#hitracehitracetracepointtype)| 是 | 信息埋点需要指定的跟踪埋点类型。 |
  | id   | [HiTraceId](#hitracehitraceid) | 是 | 实施信息埋点操作的HiTraceId实例。 |
  | msg  | string | 否 | 信息埋点操作传入的trace说明信息。 |

- 示例：
  ```
  let asyncTraceId = hitrace.begin("business", hitrace.HiTraceFlag.INCLUDE_ASYNC | hitrace.HiTraceFlag.DONOT_CREATE_SPAN);
  ...
  hitrace.tracepoint(hitrace.HiTraceCommunicationMode.THREAD, hitrace.HiTraceTracePointType.SS, asyncTraceId, "Just a example");
  ```

## hitrace.isValid

isValid(id: HiTraceId): boolean

判断HiTraceId对象是否有效同步接口

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id  | [HiTraceId](#hitracehitraceid) | 是 | 需要判断是否有效的HiTraceId实例。 |
- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 判断HiTraceId是否有效的结果。 |

- 示例：
  ```
  let traceId = hitrace.begin("business");
  ...
  let traceIdIsvalid = hitrace.isValid(traceId);
  ```

## hitrace.isFlagEnabled

isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean

判断HiTraceId对象中指定的跟踪标志是否置位同步接口

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id  | [HiTraceId](#hitracehitraceid) | 是 | 需要判断指定跟踪标志是否置位的HiTraceId实例。 |
  | flag | [HiTraceFlag](#hitracehitraceflag) | 是 | 指定的跟踪标志。 |

- 示例：
  ```
  let asyncTraceId = hitrace.begin("business", hitrace.HiTraceFlag.INCLUDE_ASYNC);
  ...
  // enabledDoNotCreateSpanFlag为true
  let enabledDoNotCreateSpanFlag = hitrace.isFlagEnabled(asyncTraceId, hitrace.HiTraceFlag.INCLUDE_ASYNC);
  ```

## hitrace.enableFlag

enableFlag(id: HiTraceId, flag: HiTraceFlag): void

置位HiTraceId对象中指定的跟踪标志同步接口

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | id  | [HiTraceId](#hitracehitraceid) | 是 | 需要置位指定跟踪标志的HiTraceId实例。 |
  | flag | [HiTraceFlag](#hitracehitraceflag) | 是 | 指定的跟踪标志。 |

- 示例：
  ```
  let asyncTraceId = hitrace.begin("business", hitrace.HiTraceFlag.INCLUDE_ASYNC);
  hitrace.enable(asyncTraceId, hitrace.HiTraceFlag.DONOT_CREATE_SPAN);
  // enabledDoNotCreateSpanFlag为true
  let enabledDoNotCreateSpanFlag = hitrace.isFlagEnabled(asyncTraceId, hitrace.HiTraceFlag.DONOT_CREATE_SPAN);
  ```
