# @ohos.resourceschedule.systemload (System Load Level Management)

The **systemload** module allows the system to determine the system load level based on the current temperature, load, and scenario, and notifies registered applications of level changes, if any.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import { systemLoad } from '@kit.BasicServicesKit';
```

## systemLoad.on('systemLoadChange')

on(type: 'systemLoadChange', callback: Callback\<SystemLoadLevel>): void

Enables listening for system load level changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.SystemLoad

**Parameters**

| Name      | Type                         | Mandatory  | Description                                      |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| type | string                      | Yes   | Change type. This parameter has a fixed value of **systemLoadChange**.                              |
| callback  | AsyncCallback&lt;[SystemLoadLevel](#systemloadlevel)&gt; | Yes   | Callback used to return the system load level.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible cause: 1. Callback parameter error; 2. Register a exist callback type; 3. Parameter verification failed. |

**Example**

```ts
import { systemLoad } from '@kit.BasicServicesKit';

function onSystemLoadChange(res: systemLoad.SystemLoadLevel) {
    console.log(`system load changed, current level ` + res);
}

try {
    systemLoad.on('systemLoadChange', onSystemLoadChange);
    console.log(`register systemload callback succeeded. `);
} catch (err) {
    console.error(`register systemload callback failed: ` + JSON.stringify(err));
}
```

## systemLoad.off('systemLoadChange')

off(type: 'systemLoadChange', callback?: Callback\<SystemLoadLevel>): void

Disables listening for system load level changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.SystemLoad

**Parameters**

| Name      | Type                         | Mandatory  | Description                                      |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| type | string                      | Yes   | Change type. This parameter has a fixed value of **systemLoadChange**.                              |
| callback  | AsyncCallback&lt;[SystemLoadLevel](#systemloadlevel)&gt; | No   | Callback used to return the system load level.|
**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible cause: 1. Callback parameter error; 2. Register a exist callback type; 3. Parameter verification failed. |

**Example**

```ts
import { systemLoad } from '@kit.BasicServicesKit';

function onSystemLoadChange(res: systemLoad.SystemLoadLevel) {
    console.log(`system load changed, current level ` + res);
}

try {
    systemLoad.off('systemLoadChange', onSystemLoadChange);
    console.log(`unregister systemload callback succeeded:. `);
} catch (err) {
    console.error(`unregister systemload callback failed: ` + JSON.stringify(err));
}
```

## systemLoad.getLevel

getLevel(): Promise&lt;[SystemLoadLevel](#systemloadlevel)&gt;

Obtains the system load level. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.SystemLoad

**Return value**

| Type                   | Description                                      |
| --------------------- | ---------------------------------------- |
| Promise&lt;[SystemLoadLevel](#systemloadlevel)&gt; | Promise used to return the system load level.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { systemLoad } from '@kit.BasicServicesKit';

systemLoad.getLevel().then((res: systemLoad.SystemLoadLevel) => {
    console.log(`getLevel promise succeeded. result: ` + JSON.stringify(res));
}).catch((err: BusinessError) => {
    console.error(`getLevel promise failed. code is ${err.code} message is ${err.message}`);
})
```

## SystemLoadLevel

Enumerates system load levels.

**System capability**: SystemCapability.ResourceSchedule.SystemLoad

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| LOW          | 0    | The device temperature and load are low.                 |
| NORMAL       | 1    | The device temperature and load are normal but are approaching the medium range. You need to downgrade or reduce the load of imperceptible services.                 |
| MEDIUM       | 2    | One or more device temperature or load items are slightly high, or the device temperature is in the medium range but the load is high. You need to stop or delay some imperceptible services.                   |
| HIGH         | 3    | The device temperature and load are relatively high. You need to stop all imperceptible services and downgrade or reduce the load of non-critical services.                 |
| OVERHEATED   | 4    | The device temperature and load are high, and the device is overheated. You need to stop all imperceptible services and downgrade or reduce the load of major foreground services.                 |
| WARNING     | 5    | The device is overheated or heavily loaded and is about to enter the Warning state. You need to stop all imperceptible services and downgrade major foreground services to the maximum extent.                |
| EMERGENCY    | 6    | The device is overheated or significantly heavy loaded and is about to enter the Emergency state. You need to stop all services except those for fundamental use.       |
| ESCAPE      | 7    | The device is overheated or extremely heavy loaded and is about to enter the Escape state. You need to stop all services and take necessary emergency measures such as data backup.       |
