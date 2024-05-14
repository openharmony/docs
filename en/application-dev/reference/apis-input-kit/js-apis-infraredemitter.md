# @ohos.multimodalInput.infraredEmitter (IR Management)

The **infraredEmitter** module generates IR signals of the specified frequency and size, and queries the frequency range supported by the device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import infraredEmitter from '@ohos.multimodalInput.infraredEmitter';
```

## infraredEmitter.transmitInfrared 

transmitInfrared(infraredFrequency: number, pattern: Array&lt;number&gt;): void

Generates IR signals at the specified frequency and level.

**System capability**: SystemCapability.MultimodalInput.Input.InfraredEmitter

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| infraredFrequency | number             | Yes   | IR frequency, in Hz.|
| pattern | Array&lt;number&gt; | Yes   | IR level signal, in μs. The number of arrays must be an even number. For example, [100,200,300,400] indicates that 100 μs is a high-level signal, 200 μs is a low-level signal, 300 μs is a high-level signal, and 400 μs is a low-level signal.|

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

**System capability**: SystemCapability.MultimodalInput.Input.InfraredEmitter

**Return value**

| Parameter                 | Description                 |
| ------------------- | ------------------- |
| Array&lt;[InfraredFrequency](#infraredfrequency)&gt; | Frequency range, including multiple groups of maximum and minimum frequencies.|

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
