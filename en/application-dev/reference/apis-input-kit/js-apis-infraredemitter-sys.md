# @ohos.multimodalInput.infraredEmitter (IR Management) (System API)

The **infraredEmitter** module generates IR signals of the specified frequency and size, and queries the frequency range supported by the device.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import { infraredEmitter } from '@kit.InputKit';
```

## infraredEmitter.transmitInfrared 

transmitInfrared(infraredFrequency: number, pattern: Array&lt;number&gt;): void

Generates IR signals at the specified frequency and level.

**Required permissions**: ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

**System capability**: SystemCapability.MultimodalInput.Input.InfraredEmitter

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| infraredFrequency | number             | Yes   | IR frequency, in Hz.|
| pattern | Array&lt;number&gt; | Yes   | IR level signal, in μs. The number of arrays must be an even number. For example, in [100, 200, 300, 400], 100 μs is a high level signal, 200 μs is a low level signal, 300 μs is a high level signal, and 400 μs is a low level signal. The number of arrays must be in the range of [0, 500).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.2.Incorrect parameter types.3.Parameter verification failed. |

**Example**

```js
try {
  infraredEmitter.transmitInfrared(38000, [100, 200, 300, 400]);
} catch (error) {
  console.log(`transmitInfrared failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

## infraredEmitter.getInfraredFrequencies

getInfraredFrequencies(): Array&lt;InfraredFrequency&gt;

Queries the frequency range of IR signals supported by the mobile phone.

**Required permissions**: ohos.permission.MANAGE_INPUT_INFRARED_EMITTER

**System capability**: SystemCapability.MultimodalInput.Input.InfraredEmitter

**Return value**

| Parameter                 | Description                 |
| ------------------- | ------------------- |
| Array&lt;[InfraredFrequency](#infraredfrequency)&gt; | Frequency range, including multiple groups of maximum and minimum frequencies.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message         |
| -------- | ----------------- |
| 201 | Permission denied. |
| 202 | Not system application. |

**Example**

```js
try {
  let frequencies = infraredEmitter.getInfraredFrequencies();
  console.log(`frequencies: ${JSON.stringify(frequencies)}`);
} catch (error) {
  console.log(`Get infrared frequencies failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
```

##  InfraredFrequency

Defines the frequency range of IR signals.

**System capability**: SystemCapability.MultimodalInput.Input.InfraredEmitter

| Name                              | Type| Mandatory  | Description |
| -------------------------------- | ---- | ------ | ------ |
| max                       | number | Yes| Maximum frequency, in Hz.|
| min                          | number | Yes | Minimum frequency, in Hz.|
