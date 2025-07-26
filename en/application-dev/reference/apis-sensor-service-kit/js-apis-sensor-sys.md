# @ohos.sensor (Sensor) (System API)

The **Sensor** module provides APIs for obtaining the sensor list and subscribing to sensor data. It also provides some common sensor algorithms.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.


## Modules to Import

```ts
import { sensor } from '@kit.SensorServiceKit';
```

## sensor.on

### COLOR<sup>10+</sup>

on(type: SensorId.COLOR, callback: Callback&lt;ColorResponse&gt;, options?: Options): void

Subscribes to data of the color sensor.

**System capability**: SystemCapability.Sensors.Sensor

**System API**: This is a system API.

**Parameters**

| Name  | Type                                             | Mandatory| Description                                                       |
| -------- | ------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).COLOR                      | Yes  | Sensor type. The value is fixed at **SensorId.COLOR**.                     |
| callback | Callback&lt;[ColorResponse](#colorresponse10)&gt; | Yes  | Callback used to report the sensor data, which is a **ColorResponse** object.        |
| options  | [Options](js-apis-sensor.md#options)              | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission check failed. A non-system application uses the system API. |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.Possible causes:1. Sensor hdf service exception;2. Sensor service ipc exception;3.Sensor data channel exception. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try{
  sensor.on(sensor.SensorId.COLOR, (data: sensor.ColorResponse) => {
    console.log('Succeeded in getting the intensity of light: ' + data.lightIntensity);
    console.log('Succeeded in getting the color temperature: ' + data.colorTemperature);
  }, { interval: 100000000 });
  setTimeout(() => {
        sensor.off(sensor.SensorId.COLOR);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### SAR<sup>10+</sup>

on(type: SensorId.SAR, callback: Callback&lt;SarResponse&gt;, options?: Options): void

Subscribes to data of the Sodium Adsorption Ratio (SAR) sensor.

**System capability**: SystemCapability.Sensors.Sensor

**System API**: This is a system API.

**Parameters**

| Name  | Type                                         | Mandatory| Description                                                       |
| -------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).SAR                    | Yes  | Sensor type. The value is fixed at **SensorId.SAR**.                       |
| callback | Callback&lt;[SarResponse](#sarresponse10)&gt; | Yes  | Callback used to report the sensor data, which is a **SarResponse** object.          |
| options  | [Options](js-apis-sensor.md#options)          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission check failed. A non-system application uses the system API. |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.Possible causes:1. Sensor hdf service exception;2. Sensor service ipc exception;3.Sensor data channel exception. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.SAR, (data: sensor.SarResponse) => {
    console.info('Succeeded in getting specific absorption rate : ' + data.absorptionRatio);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.SAR);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.off

### COLOR<sup>10+</sup>

off(type: SensorId.COLOR, callback?: Callback&lt;ColorResponse&gt;): void

Unsubscribes from data of the color sensor.

**System capability**: SystemCapability.Sensors.Sensor

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                    | Mandatory| Description                                                        |
| -------- |--------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).COLOR                           | Yes  | Sensor type. The value is fixed at **SensorId.COLOR**.                      |
| callback | Callback&lt;[ColorResponse](#colorresponse10)&gt;      | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission check failed. A non-system application uses the system API. |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

function callback1(data: object) {
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));
}

function callback2(data: object) {
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));
}

try {
  sensor.on(sensor.SensorId.COLOR, callback1);
  sensor.on(sensor.SensorId.COLOR, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.COLOR, callback1);
  // Unsubscribe from all callbacks of the SensorId.COLOR type.
  sensor.off(sensor.SensorId.COLOR);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### COLOR<sup>19+</sup>

off(type: SensorId.COLOR, sensorInfoParam?: SensorInfoParam, callback?: Callback&lt;ColorResponse&gt;): void

Unsubscribes from data of the color sensor.

**System capability**: SystemCapability.Sensors.Sensor

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                    | Mandatory| Description                                                        |
| -------- |--------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).COLOR                           | Yes  | Sensor type. The value is fixed at **SensorId.COLOR**.                      |
| sensorInfoParam | [SensorInfoParam](#sensorinfoparam19) |  No| Sensor parameters, including **deviceId** and **sensorIndex**.|
| callback | Callback&lt;[ColorResponse](#colorresponse10)&gt;      | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission check failed. A non-system application uses the system API. |
| 14500101 | Service exception.Possible causes:1. Sensor hdf service exception;2. Sensor service ipc exception;3.Sensor data channel exception. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

enum Ret { OK, Failed = -1 }

// Sensor callback
const sensorCallback = (response: sensor.ColorResponse) => {
  console.log(`callback response: ${JSON.stringify(response)}`);
}
// Sensor type
const sensorType = sensor.SensorId.COLOR;
const sensorInfoParam: sensor.SensorInfoParam = {};

function sensorSubscribe(): Ret {
  let ret: Ret = Ret.OK;
  try {
    // Query all sensors.
    const sensorList: sensor.Sensor[] = sensor.getSensorListSync();
    if (!sensorList.length) {
      return Ret.Failed;
    }
    // Obtain the target sensor based on the actual service logic.
    const targetSensor: sensor.Sensor = sensorList[0];
    sensorInfoParam.deviceId = targetSensor.deviceId ?? -1;
    sensorInfoParam.sensorIndex = targetSensor.sensorIndex ?? -1;
    // Subscribe to sensor events.
    sensor.on(sensorType, sensorCallback, { sensorInfoParam });
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`Failed to invoke sensor.on. Code: ${e.code}, message: ${e.message}`);
    ret = Ret.Failed;
  }
  return ret;
}

function sensorUnsubscribe(): Ret {
  let ret: Ret = Ret.OK;
  try {
    sensor.off(sensorType, sensorInfoParam, sensorCallback);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`Failed to invoke sensor.off. Code: ${e.code}, message: ${e.message}`);
    ret = Ret.Failed;
  }
  return ret;
}
```

### SAR<sup>10+</sup>

off(type: SensorId.SAR, callback?: Callback&lt;SarResponse&gt;): void

Unsubscribes from data of the SAR sensor.

**System capability**: SystemCapability.Sensors.Sensor

**System API**: This is a system API.

**Parameters**

| Name  | Type                                         | Mandatory| Description                                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).SAR                    | Yes  | Sensor type. The value is fixed at **SensorId.SAR**.                        |
| callback | Callback&lt;[SarResponse](#sarresponse10)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission check failed. A non-system application uses the system API. |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

function callback1(data: object) {
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));
}

function callback2(data: object) {
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));
}

try {
  sensor.on(sensor.SensorId.SAR, callback1);
  sensor.on(sensor.SensorId.SAR, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.SAR, callback1);
  // Unsubscribe from all callbacks of the SensorId.SAR type.
  sensor.off(sensor.SensorId.SAR);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### SAR<sup>19+</sup>

off(type: SensorId.SAR, sensorInfoParam?: SensorInfoParam, callback?: Callback&lt;SarResponse&gt;): void

Unsubscribes from data of the SAR sensor.

**System capability**: SystemCapability.Sensors.Sensor

**System API**: This is a system API.

**Parameters**

| Name  | Type                                         | Mandatory| Description                                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).SAR                    | Yes  | Sensor type. The value is fixed at **SensorId.SAR**.                        |
| sensorInfoParam | [SensorInfoParam](#sensorinfoparam19) |  No| Sensor parameters, including **deviceId** and **sensorIndex**.|
| callback | Callback&lt;[SarResponse](#sarresponse10)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                                                                                   |
| -------- |-----------------------------------------------------------------------------------------------------------------------------------------|
| 202      | Permission check failed. A non-system application uses the system API.                                                                  |
| 14500101 | Service exception.Possible causes:1. Sensor hdf service exception;2. Sensor service ipc exception;3.Sensor data channel exception. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

enum Ret { OK, Failed = -1 }

// Sensor callback
const sensorCallback = (response: sensor.SarResponse) => {
  console.log(`callback response: ${JSON.stringify(response)}`);
}
// Sensor type
const sensorType = sensor.SensorId.SAR;
const sensorInfoParam: sensor.SensorInfoParam = {};

function sensorSubscribe(): Ret {
  let ret: Ret = Ret.OK;
  try {
    // Query all sensors.
    const sensorList: sensor.Sensor[] = sensor.getSensorListSync();
    if (!sensorList.length) {
      return Ret.Failed;
    }
    // Obtain the target sensor based on the actual service logic.
    const targetSensor: sensor.Sensor = sensorList[0];
    sensorInfoParam.deviceId = targetSensor.deviceId ?? -1;
    sensorInfoParam.sensorIndex = targetSensor.sensorIndex ?? -1;
    // Subscribe to sensor events.
    sensor.on(sensorType, sensorCallback, { sensorInfoParam });
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`Failed to invoke sensor.on. Code: ${e.code}, message: ${e.message}`);
    ret = Ret.Failed;
  }
  return ret;
}

function sensorUnsubscribe(): Ret {
  let ret: Ret = Ret.OK;
  try {
    sensor.off(sensorType, sensorInfoParam, sensorCallback);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`Failed to invoke sensor.off. Code: ${e.code}, message: ${e.message}`);
    ret = Ret.Failed;
  }
  return ret;
}
```

## SensorId<sup>9+</sup>

Enumerates the sensor types.

**System capability**: SystemCapability.Sensors.Sensor

| Name               | Value  | Description                                           |
| ------------------- | ---- | ----------------------------------------------- |
| COLOR<sup>10+</sup> | 14   | Color sensor.<br>System API: This is a system API.    |
| SAR<sup>10+</sup>   | 15   | Sodium Adsorption Ratio (SAR) sensor.<br>System API: This is a system API.|

## ColorResponse<sup>10+</sup>

Describes the color sensor data. It extends from [Response](js-apis-sensor.md#response).

**System capability**: SystemCapability.Sensors.Sensor

**System API**: This is a system API.


| Name            | Type  | Read-Only| Optional| Description                         |
| ---------------- | ------ | ---- | ---- | ----------------------------- |
| lightIntensity   | number | Yes  | Yes  | Intensity of light, in lux.|
| colorTemperature | number | Yes  | Yes  | Color temperature, in Kelvin.    |

## SarResponse<sup>10+ </sup>

Describes the SAR sensor data. It extends from [Response](js-apis-sensor.md#response).

**System capability**: SystemCapability.Sensors.Sensor

**System API**: This is a system API.


| Name           | Type  | Read-Only| Optional| Description                           |
| --------------- | ------ | ---- | ---- | ------------------------------- |
| absorptionRatio | number | Yes  | Yes  | Absorption ratio, in W/kg.|


## SensorInfoParam<sup>19+</sup>

Defines sensor parameters.

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type                  | Mandatory| Description                     |
| ------ | ---------------------- | ---- |-------------------------|
| deviceId   | number | No  | Device ID. The default value is **-1**, which indicates the local device.    |
| sensorIndex   | number | No  | Sensor index. The default value is **0**, which indicates the default sensor on the device.|
