# Thermal Manager

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The Thermal Manager module provides APIs for listening to the device thermal status.


## Modules to Import

```
import thermal from '@ohos.thermal';
```


## ThermalLevel

Represents the thermal level.

| Name        | Default Value  | Description                                      |
| ---------- | ---- | ---------------------------------------- |
| COOL       | 0    | The device is cool, and services are not restricted.<br>**System capability:** SystemCapability.PowerManager.ThermalManager|
| NORMAL     | 1    | The device is operational but is not cool. You need to pay attention to its heating.<br>**System capability:** SystemCapability.PowerManager.ThermalManager|
| WARM       | 2    | The device is warm. You need to stop or delay some imperceptible services.<br>**System capability:** SystemCapability.PowerManager.ThermalManager|
| HOT        | 3    | The device is heating up. You need to stop all imperceptible services and downgrade or reduce the load of other services.<br>**System capability:** SystemCapability.PowerManager.ThermalManager|
| OVERHEATED | 4    | The device is overheated. You need to stop all imperceptible services and downgrade or reduce the load of major services.<br>**System capability:** SystemCapability.PowerManager.ThermalManager|
| WARNING    | 5    | The device is overheated and is about to enter the emergency state. You need to stop all imperceptible services and downgrade major services to the maximum extent.<br>**System capability:** SystemCapability.PowerManager.ThermalManager|
| EMERGENCY  | 6    | The device has entered the emergency state. You need to stop all services except those for the emergency help purposes.<br>**System capability:** SystemCapability.PowerManager.ThermalManager|


## thermal.subscribeThermalLevel

subscribeThermalLevel(callback: AsyncCallback&lt;ThermalLevel&gt;): void

Subscribes to thermal level changes.

**System capability:** SystemCapability.PowerManager.ThermalManager

**Parameters**

| Name     | Type                               | Mandatory  | Description                                      |
| -------- | --------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;ThermalLevel&gt; | Yes   | Callback used to obtain the return value.<br>Return value: thermal level|

**Example**

```
var lev = 0;
thermal.subscribeThermalLevel((lev) => {
    console.info("Thermal level is: " + lev);
})
```

## thermal.unsubscribeThermalLevel

unsubscribeThermalLevel(callback?: AsyncCallback\<void>): void

Unsubscribes from thermal level changes.

**System capability:** SystemCapability.PowerManager.ThermalManager

**Parameters**

| Name     | Type                       | Mandatory  | Description                   |
| -------- | ------------------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;void&gt; | No  | Callback without a return value.|

**Example**

```
thermal.unsubscribeThermalLevel(() => {
    console.info("Unsubscribe completed.");
});
```

## thermal.getThermalLevel

getThermalLevel(): ThermalLevel

Obtains the current thermal level.

**System capability:** SystemCapability.PowerManager.ThermalManager

**Return value**:

| Type          | Description    |
| ------------ | ------ |
| ThermalLevel | Thermal level obtained.|

**Example**

```
var lev = thermal.getThermalLevel();
console.info("Thermal level is: " + lev);
```
