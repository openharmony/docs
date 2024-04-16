# @ohos.batteryInfo (Battery Information) (System API)

The **batteryInfo** module provides APIs for querying the charger type, battery health status, and battery charging status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.batteryInfo (Battery Information)](js-apis-battery-info.md).


## Modules to Import

```js
import batteryInfo from '@ohos.batteryInfo';
```

## batteryInfo.setBatteryConfig<sup>11+</sup>

setBatteryConfig(sceneName: string, sceneValue: string): number

Sets the battery configuration based on the specified scenario.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Parameters**

| Name    | Type  | Mandatory| Description        |
| ---------- | ------ | ---- | ------------ |
| sceneName  | string | Yes  | Scenario name.|
| sceneValue | string | Yes  | Scenario value.|

**Return value**

| Type  | Description                                                      |
| ------ | ---------------------------------------------------------- |
| number | Operation result. The value **0** indicates that the operation is successful, and a non-zero value indicates the opposite.|

**Error codes**

For details about the error codes, see [Battery Information Error Codes](errorcode-battery-info.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | If connecting to the service failed. |

**Example**

  ```ts
  import batteryInfo from '@ohos.batteryInfo';

  let sceneName = 'xxx';
  let sceneValue = '0';
  let result = batteryInfo.setBatteryConfig(sceneName, sceneValue);

  console.info("The result is: " + result);
  ```

## batteryInfo.getBatteryConfig<sup>11+</sup>

getBatteryConfig(sceneName: string): string

Obtains the battery configuration based on the specified scenario.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Parameters**

| Name   | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ------------ |
| sceneName | string | Yes  | Scenario name.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| string | Operation result. The battery configuration is returned if the operation is successful. Otherwise, **""** is returned.|

**Error codes**

For details about the error codes, see [Battery Information Error Codes](errorcode-battery-info.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | If connecting to the service failed. |

**Example**

  ```ts
  import batteryInfo from '@ohos.batteryInfo';

  let sceneName = 'xxx';
  let result = batteryInfo.getBatteryConfig(sceneName);

  console.info("The result is: " + result);
  ```

## batteryInfo.isBatteryConfigSupported<sup>11+</sup>

isBatteryConfigSupported(sceneName: string): boolean

Checks whether the battery configuration is enabled based on the specified scenario.

**System API**: This is a system API.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

**Parameters**

| Name   | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ------------ |
| sceneName | string | Yes  | Scenario name.|

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Operation result. The value **true** indicates that the charging scenario is supported, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Battery Information Error Codes](errorcode-battery-info.md).

| ID  | Error Message   |
|---------|---------|
| 4900101 | If connecting to the service failed. |

**Example**

  ```ts
  import batteryInfo from '@ohos.batteryInfo';

  let sceneName = 'xxx';
  let result = batteryInfo.isBatteryConfigSupported(sceneName);

  console.info("The result is: " + result);
  ```

## BatteryConfig

Describes battery information.

**System capability**: SystemCapability.PowerManager.BatteryManager.Core

| Name     | Type       | Readable| Writable|  Description    |
| --------------- | ------------------- | ---- | ---- | ---------------------|
| estimatedRemainingChargeTime<sup>9+</sup> | number                                         | Yes  | No  | Estimated time for fully charging the current device, in unit of milliseconds. This is a system API.         |
| totalEnergy<sup>9+</sup>                  | number                                         | Yes  | No  | Total battery capacity of the device, in unit of mAh. This is a system API.  |
| nowCurrent<sup>9+</sup>                   | number                                         | Yes  | No  | Battery current of the device, in unit of mA. This is a system API.      |
| remainingEnergy<sup>9+</sup>              | number                                         | Yes  | No  | Remaining battery capacity of the device, in unit of mAh. This is a system API.|
