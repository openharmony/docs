# Distributed Call Chain Tracing

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import hiTraceChain from '@ohos.hiTraceChain';
```

## System Capabilities

SystemCapability.HiviewDFX.HiTrace

## HiTraceFlag

Enumerates trace flag types.

| Name| Default Value| Description|
| -------- | -------- | -------- |
| DEFAULT           | 0      | Default flag|
| INCLUDE_ASYNC     | 1      | Asynchronous call flag|
| DONOT_CREATE_SPAN | 1 << 1 | No span flag|
| TP_INFO           | 1 << 2 | Trace point flag|
| NO_BE_INFO        | 1 << 3 | No begin/end flag|
| DISABLE_LOG       | 1 << 4 | Log association flag|
| FAILURE_TRIGGER   | 1 << 5 | Failure trigger flag|
| D2D_TP_INFO       | 1 << 6 | Device-to-device trace point flag|

## HiTraceTracepointType

Enumerates trace point types.

| Name| Default Value| Description|
| -------- | -------- | -------- |
| CS       | 0 | Client Send|
| CR       | 1 | Client Receive|
| SS       | 2 | Server Send|
| SR       | 3 | Server Receive|
| GENERAL  | 4 | General|

## HiTraceCommunicationMode

Enumerates communication modes.

| Name| Default Value| Description|
| -------- | -------- | -------- |
| DEFAULT  | 0 | Default mode|
| THREAD   | 1 | Inter-thread communication|
| PROCESS  | 2 | Inter-process communication|
| DEVICE   | 3 | Inter-device communication|

## HiTraceId

Defines a **HiTraceId** object.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| chainId      | bigint | Yes| Call chain ID.|
| spanId      | number | No| Span ID.|
| parentSpanId | number | No| Parent span ID.|
| flags        | number | No| Trace flag combination.|

## hiTraceChain.begin

begin(name: string, flags: number = HiTraceFlag.DEFAULT): HiTraceId

Starts call chain tracing. This API works in synchronous manner.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name  | string | Yes| Traced service name.|
| flags | number | Yes| Trace flag combination. For details, see [HiTraceFlag](#hitraceflag).|

**Return value**

| Type| Description|
| -------- | -------- |
| [HiTraceId](#hitraceid) | **HiTraceId** instance.|

**Example**

```
let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
```

## hiTraceChain.end

end(id: HiTraceId): void

Stops call chain tracing. This API works in synchronous manner.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance.|

**Example**

```
let asyncTraceId = hiTraceChain.begin("business");
// End the call chain tracing after the service logic is executed for several times.
hiTraceChain.end(asyncTraceId);
```

## hiTraceChain.getId

getId(): HiTraceId

Obtains the trace ID. This API works in synchronous manner.

**Return value**

| Type| Description|
| -------- | -------- |
| [HiTraceId](#hitraceid) | **HiTraceId** instance.|

**Example**

```
let traceId = hiTraceChain.begin("business");
// Obtain the current trace ID after the service logic is executed for several times.
let curTraceId = hiTraceChain.getId();
```

## hiTraceChain.setId

setId(id: HiTraceId): void

Sets a trace ID. This API works in synchronous manner.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance.|

**Example**

```
let traceId = hiTraceChain.begin("business");
// Set the current trace ID after the service logic is executed for several times.
hiTraceChain.setId(asyncTraceId);
```

## hiTraceChain.clearId

clearId(): void

Clears the trace ID. This API works in synchronous manner.

**Example**

```
let traceId = hiTraceChain.begin("business");
// Clear the current trace ID after the service logic is executed for several times.
hiTraceChain.clearId();
```

## hiTraceChain.createSpan

createSpan(): HiTraceId

Creates a trace span. This API works in synchronous manner.

**Return value**

| Type| Description|
| -------- | -------- |
| [HiTraceId](#hitraceid) | **HiTraceId** instance.|

**Example**

```
let traceId = hiTraceChain.begin("business");
// Create a trace span after the service logic is executed for several times.
let spanTraceId = hiTraceChain.createSpan();
```

## hiTraceChain.tracepoint

tracepoint(mode: HiTraceCommunicationMode, type: HiTraceTracepointType, id: HiTraceId, msg?: string): void

Triggers a trace point. This API works in synchronous manner.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mode | [HiTraceCommunicationMode](#hitracecommunicationmode) | Yes| Communication mode for the trace point.|
| type | [HiTraceTracepointType](#hitracetracepointtype)| Yes| Trace point type.|
| id   | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance for trace point triggering.|
| msg  | string | No| Trace description passed for trace point triggering.|

**Example**

```
let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC | hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
// Trigger the trace point after the service logic is executed for several times.
hiTraceChain.tracepoint(hiTraceChain.HiTraceCommunicationMode.THREAD, hiTraceChain.HiTraceTracepointType.SS, asyncTraceId, "Just a example");
```

## hiTraceChain.isValid

isValid(id: HiTraceId): boolean

Checks whether a **HiTraceId** instance is valid. This API works in synchronous manner.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id  | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the **HiTraceId** instance is valid; returns **false** otherwise.|

**Example**

```
let traceId = hiTraceChain.begin("business");
let traceIdIsvalid = hiTraceChain.isValid(traceId);
```

## hiTraceChain.isFlagEnabled

isFlagEnabled(id: HiTraceId, flag: HiTraceFlag): boolean

Checks whether the specified trace flag in the **HiTraceId** instance is enabled. This API works in synchronous manner.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id  | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance.|
| flag | [HiTraceFlag](#hitraceflag) | Yes| Specified trace flag.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified trace flag in the **HiTraceId** instance is enabled; returns **false** otherwise.|

**Example**

```
let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
// The value of enabledDoNotCreateSpanFlag is true.
let enabledDoNotCreateSpanFlag = hiTraceChain.isFlagEnabled(asyncTraceId, hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
```

## hiTraceChain.enableFlag

enableFlag(id: HiTraceId, flag: HiTraceFlag): void

Enables the specified trace flag in the **HiTraceId** instance. This API works in synchronous manner.

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id  | [HiTraceId](#hitraceid) | Yes| **HiTraceId** instance.|
| flag | [HiTraceFlag](#hitraceflag) | Yes| Specified trace flag.|

**Example**

```
let asyncTraceId = hiTraceChain.begin("business", hiTraceChain.HiTraceFlag.INCLUDE_ASYNC);
hiTraceChain.enable(asyncTraceId, hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
// The value of enabledDoNotCreateSpanFlag is true.
let enabledDoNotCreateSpanFlag = hiTraceChain.isFlagEnabled(asyncTraceId, hiTraceChain.HiTraceFlag.DONOT_CREATE_SPAN);
```
