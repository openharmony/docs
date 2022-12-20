# Distributed Call Chain Tracing

This module implements call chain tracing throughout a service process. It provides functions such as starting and stopping call chain tracing and configuring trace points.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import hiTraceChain from '@ohos.hiTraceChain';
```


## HiTraceFlag

Enumerates trace flag types.

**System capability**: SystemCapability.HiviewDFX.HiTrace

| Name | Value | Description |
| -------- | -------- | -------- |
| DEFAULT           | 0      | Default flag. |
| INCLUDE_ASYNC     | 1      | Asynchronous call flag. By default, only synchronous calls are traced. If this flag is set, both synchronous and asynchronous calls will be traced. |
| DONOT_CREATE_SPAN | 1 << 1 | No span flag. By default, a span is automatically created during tracing of synchronous and asynchronous calls. If this flag is set, no span will be created. |
| TP_INFO           | 1 << 2 | Trace point flag. By default, no trace point is added when tracing is enabled. This flag is used for debugging. If this flag is set, trace points will be automatically added on the TX and RX sides of synchronous and asynchronous calls to output trace point and timestamp information. Trace points are classified into four types: [CS, SR, SS, and CR](#hitracetracepointtype). For a synchronous call, the output trace points are CS, SR, SS, and CR; for an asynchronous call, the output trace points are CS, SR, and SS. |
| NO_BE_INFO        | 1 << 3 | No begin/end flag. By default, information about the start and end of the trace task is printed. If this flag is set, information about the start and end of the trace task will not be printed. |
| DISABLE_LOG       | 1 << 4 | Log association flag. If this flag is set, information about the trace task will not be printed. |
| FAILURE_TRIGGER   | 1 << 5 | Failure trigger flag. This flag is reserved for future use. |
| D2D_TP_INFO       | 1 << 6 | Device-to-device trace point flag. It is a subset of **TP_INFO**. If this flag is set, trace points are added only for call chain tracing between devices. |

## HiTraceTracepointType

Enumerates trace point types.

**System capability**: SystemCapability.HiviewDFX.HiTrace

| Name| Value | Description |
| -------- | -------- | -------- |
| CS       | 0 | Client Send (CS) trace point. |
| CR       | 1 | Client Receive (CS) trace point. |
| SS       | 2 | Server Send (SS) trace point. |
| SR       | 3 | Server Receive (SR) trace point. |
| GENERAL  | 4 | General trace points except CS, CR, SS, and SR. |

## HiTraceCommunicationMode

Enumerates communication modes.

**System capability**: SystemCapability.HiviewDFX.HiTrace

| Name| Value | Description |
| -------- | -------- | -------- |
| DEFAULT  | 0 | Default communication mode. |
| THREAD   | 1 | Inter-thread communication. |
| PROCESS  | 2 | Inter-process communication. |
| DEVICE   | 3 | Inter-device communication. |

## HiTraceId

Defines a **HiTraceId** object.

**System capability**: SystemCapability.HiviewDFX.HiTrace

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| chainId      | bigint | Yes| Call chain ID. |
| spanId      | number | No| Span ID. |
| parentSpanId | number | No| Parent span ID. |
| flags        | number | No| Trace flag combination. |

## hiTraceChain.begin

begin(name: string, flags?: number): HiTraceId

Starts call chain tracing. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name  | string | Yes| Traced service name. |
| flags | number | No| Trace flag combination. For details, see [HiTraceFlag](#hitraceflag). |

**Return value**

| Type | Description |
| -------- | -------- |
| [HiTraceId](#hitraceid) | **HiTraceId** instance. |

**Example**

```js
let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
```

## hiTraceChain.end

end(id: HiTraceId): void

Stops call chain tracing. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| id | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance. |

**Example**

```js
let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// End the call chain tracing after the service logic is executed for several times.
hiTraceChain.end(asyncTraceId);
```

## hiTraceChain.getId

getId(): HiTraceId

Obtains the trace ID. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Return value**

| Type | Description |
| -------- | -------- |
| [HiTraceId](#hitraceid) | **HiTraceId** instance. |

**Example**

```js
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// Obtain the current trace ID after the service logic is executed for several times.
let curTraceId = hiTraceChain.getId();
```

## hiTraceChain.setId

setId(id: HiTraceId): void

Sets a trace ID. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| id | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance. |

**Example**

```js
let asyncTraceId;
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// Set the current trace ID after the service logic is executed for several times.
hiTraceChain.setId(asyncTraceId);
```

## hiTraceChain.clearId

clearId(): void

Clears the trace ID. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Example**

```js
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// Clear the current trace ID after the service logic is executed for several times.
hiTraceChain.clearId();
```

## hiTraceChain.createSpan

createSpan(): HiTraceId

Creates a trace span. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Return value**

| Type | Description |
| -------- | -------- |
| [HiTraceId](#hitraceid) | **HiTraceId** instance. |

**Example**

```js
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
// Create a trace span after the service logic is executed for several times.
let spanTraceId = hiTraceChain.createSpan();
```

## hiTraceChain.tracepoint

tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void

Triggers a trace point. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| mode | [HiTraceCommunicationMode](#hitracecommunicationmode) | Yes| Communication mode for the trace point. |
| type | [HiTraceTracepointType](#hitracetracepointtype)| Yes| Trace point type. |
| id   | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance for trace point triggering. |
| msg  | string | No| Trace description passed for trace point triggering. |

**Example**

```js
let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
// Trigger the trace point after the service logic is executed for several times.
hiTraceChain.tracepoint(hiTraceChain.HiTraceCommunicationMode.THREAD, hiTraceChain.HiTraceTracepointType.SS, asyncTraceId, "Just a example");
```

## hiTraceChain.isValid

isValid(id: HiTraceId): boolean

Checks whether a **HiTraceId** instance is valid. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| id  | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance. |

**Return value**

| Type | Description |
| -------- | -------- |
| boolean | Returns **true** if the **HiTraceId** instance is valid; returns **false** otherwise. |

**Example**

```js
let traceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.DEFAULT);
let traceIdIsvalid = hiTraceChain.isValid(traceId);
```

## hiTraceChain.isFlagEnabled

isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean

Checks whether the specified trace flag in the **HiTraceId** instance is enabled. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| id  | [HiTraceId](#hitraceid) | Yes | **HiTraceId** instance. |
| flag | [HiTraceFlag](#hitraceflag) | Yes | Specified trace flag. |

**Return value**

| Type | Description |
| -------- | -------- |
| boolean | Returns **true** if the specified trace flag in the **HiTraceId** instance is enabled; returns **false** otherwise. |

**Example**

```js
let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
// The value of enabledDoNotCreateSpanFlag is true.
let enabledDoNotCreateSpanFlag = hiTraceChain.isFlagEnabled(asyncTraceId, hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
```

## hiTraceChain.enableFlag

enableFlag(id: HiTraceId, flag: HiTraceFlag): void

Enables the specified trace flag in the **HiTraceId** instance. This API works in synchronous manner.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| id | [HiTraceId](#hitraceid) | Yes | **HiTraceId** instance. |
| flag | [HiTraceFlag](#hitraceflag) | Yes | Specified trace flag. |

**Example**

```js
let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
hiTraceChain.enableFlag(asyncTraceId, hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
// The value of enabledDoNotCreateSpanFlag is true.
let enabledDoNotCreateSpanFlag = hiTraceChain.isFlagEnabled(asyncTraceId, hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
```
