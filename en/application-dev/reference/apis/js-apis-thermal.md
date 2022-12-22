# Thermal Manager

This module provides thermal level-related callback and query APIs to obtain the information required for thermal control.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import thermal from '@ohos.thermal';
```

## thermal.registerThermalLevelCallback<sup>9+</sup>

registerThermalLevelCallback(callback: Callback&lt;ThermalLevel&gt;): void

Subscribes to thermal level changes.

**System capability:** SystemCapability.PowerManager.ThermalManager

**Parameters**

| Name  | Type                        | Mandatory| Description                          |
| -------- | ---------------------------- | ---- | ------------------------------ |
| callback | Callback&lt;ThermalLevel&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Thermal Manager Error Codes](../errorcodes/errorcode-thermal.md).

| Code  | Error Message   |
|---------|---------|
| 4800101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    thermal.registerThermalLevelCallback(level => {
        console.info('thermal level is: ' + level);
    });
    console.info('register thermal level callback success.');
} catch(err) {
    console.error('register thermal level callback failed, err: ' + err);
}
```

## thermal.unregisterThermalLevelCallback<sup>9+</sup>

unregisterThermalLevelCallback(callback?: Callback\<void>): void

Unsubscribes from thermal level changes.

**System capability:** SystemCapability.PowerManager.ThermalManager

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | ---------------------------------------------- |
| callback | Callback&lt;void&gt; | No  | Callback used to return the result. No value is returned. If this parameter is not set, this API unsubscribes from all callbacks.|

**Error codes**

For details about the error codes, see [Thermal Manager Error Codes](../errorcodes/errorcode-thermal.md).

| Code  | Error Message   |
|---------|---------|
| 4800101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    thermal.unregisterThermalLevelCallback(() => {
        console.info('unsubscribe thermal level success.');
    });
    console.info('unregister thermal level callback success.');
} catch(err) {
    console.error('unregister thermal level callback failed, err: ' + err);
}
```

## thermal.getLevel<sup>9+</sup>

getLevel(): ThermalLevel

Obtains the current thermal level.

**System capability:** SystemCapability.PowerManager.ThermalManager

**Return value**

| Type        | Description        |
| ------------ | ------------ |
| ThermalLevel | Thermal level obtained.|

**Error codes**

For details about the error codes, see [Thermal Manager Error Codes](../errorcodes/errorcode-thermal.md).

| Code  | Error Message   |
|---------|---------|
| 4800101 | Operation failed. Cannot connect to service.|

**Example**

```js
try {
    var level = thermal.getLevel();
    console.info('thermal level is: ' + level);
} catch(err) {
    console.error('get thermal level failed, err: ' + err);
}
```

## thermal.subscribeThermalLevel<sup>(deprecated)</sup>

subscribeThermalLevel(callback: AsyncCallback&lt;ThermalLevel&gt;): void

> This API is deprecated since API version 9. You are advised to use [thermal.registerThermalLevelCallback](#thermalregisterthermallevelcallback9) instead.

Subscribes to thermal level changes.

**System capability:** SystemCapability.PowerManager.ThermalManager

**Parameters**

| Name  | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;ThermalLevel&gt; | Yes  | Callback used to return the result. The return value contains only one parameter, that is, thermal level. If an alarm is generated, you can use `// @ts-ignore` to suppress the alarm.|

**Example**

```js
thermal.subscribeThermalLevel((level) => {
    console.info('thermal level is: ' + level);
});
```

## thermal.unsubscribeThermalLevel<sup>(deprecated)</sup>

unsubscribeThermalLevel(callback?: AsyncCallback\<void>): void

> This API is deprecated since API version 9. You are advised to use [thermal.unregisterThermalLevelCallback](#thermalunregisterthermallevelcallback9) instead.

Unsubscribes from thermal level changes.

**System capability:** SystemCapability.PowerManager.ThermalManager

**Parameters**

| Name  | Type                     | Mandatory| Description                                          |
| -------- | ------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;void&gt; | No  | Callback used to return the result. No value is returned. If this parameter is not set, this API unsubscribes from all callbacks.|

**Example**

```js
thermal.unsubscribeThermalLevel(() => {
    console.info('unsubscribe thermal level success.');
});
```

## thermal.getThermalLevel<sup>(deprecated)</sup>

getThermalLevel(): ThermalLevel

> This API is deprecated since API version 9. You are advised to use [thermal.getLevel](#thermalgetlevel9) instead.

Obtains the current thermal level.

**System capability:** SystemCapability.PowerManager.ThermalManager

**Return value**

| Type          | Description    |
| ------------ | ------ |
| ThermalLevel | Thermal level obtained.|

**Example**

```js
var level = thermal.getThermalLevel();
console.info('thermal level is: ' + level);
```

## ThermalLevel

Represents the thermal level.

**System capability:** SystemCapability.PowerManager.ThermalManager

| Name      | Value  | Description                                                        |
| ---------- | ---- | ------------------------------------------------------------ |
| COOL       | 0    | The device is cool, and services are not restricted.            |
| NORMAL     | 1    | The device is operational but is not cool. You need to pay attention to its heating.|
| WARM       | 2    | The device is warm. You need to stop or delay some imperceptible services.|
| HOT        | 3    | The device is heating up. You need to stop all imperceptible services and downgrade or reduce the load of other services.|
| OVERHEATED | 4    | The device is overheated. You need to stop all imperceptible services and downgrade or reduce the load of major services.|
| WARNING    | 5    | The device is overheated and is about to enter the emergency state. You need to stop all imperceptible services and downgrade major services to the maximum extent.|
| EMERGENCY  | 6    | The device has entered the emergency state. You need to stop all services except those for the emergency help purposes.|
