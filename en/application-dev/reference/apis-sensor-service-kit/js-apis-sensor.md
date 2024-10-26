# @ohos.sensor (Sensor)

The **Sensor** module provides APIs for obtaining the sensor list and subscribing to sensor data. It also provides some common sensor algorithms.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { sensor } from '@kit.SensorServiceKit';
```
## sensor.on

### ACCELEROMETER<sup>9+</sup>

on(type: SensorId.ACCELEROMETER, callback: Callback&lt;AccelerometerResponse&gt;, options?: Options): void

Subscribes to data of the acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).ACCELEROMETER                         | Yes  | Sensor type. The value is fixed at **SensorId.ACCELEROMETER**.             |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is an **AccelerometerResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes** 

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.ACCELEROMETER, (data: sensor.AccelerometerResponse) => {
    console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.ACCELEROMETER);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### ACCELEROMETER_UNCALIBRATED<sup>9+</sup>

on(type: SensorId.ACCELEROMETER_UNCALIBRATED, callback: Callback&lt;AccelerometerUncalibratedResponse&gt;, options?: Options): void

Subscribes to data of the uncalibrated acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ACCELEROMETER_UNCALIBRATED            | Yes  | Sensor type. The value is fixed at **SensorId.ACCELEROMETER_UNCALIBRATED**. |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes  | Callback used to report the sensor data, which is an **AccelerometerUncalibratedResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Error codes**  

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, (data: sensor.AccelerometerUncalibratedResponse) => {
    console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
    console.info('Succeeded in invoking on. X-coordinate bias: ' + data.biasX);
    console.info('Succeeded in invoking on. Y-coordinate bias: ' + data.biasY);
    console.info('Succeeded in invoking on. Z-coordinate bias: ' + data.biasZ);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.ACCELEROMETER_UNCALIBRATED);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### AMBIENT_LIGHT<sup>9+</sup>

on(type: SensorId.AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;, options?: Options): void

Subscribes to data of the ambient light sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                       |
| -------- | ----------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).AMBIENT_LIGHT            | Yes  | Sensor type. The value is fixed at **SensorId.AMBIENT_LIGHT**.             |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **LightResponse** object.        |
| options  | [Options](#options)                             | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.AMBIENT_LIGHT, (data: sensor.LightResponse) => {
    console.info('Succeeded in getting the ambient light intensity: ' + data.intensity);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.AMBIENT_LIGHT);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

###  AMBIENT_TEMPERATURE<sup>9+</sup>

on(type: SensorId.AMBIENT_TEMPERATURE, callback: Callback&lt;AmbientTemperatureResponse&gt;, options?: Options): void

Subscribes to data of the ambient temperature sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).AMBIENT_TEMPERATURE                   | Yes  | Sensor type. The value is fixed at **SensorId.AMBIENT_TEMPERATURE**.        |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes  | Callback used to report the sensor data, which is an **AmbientTemperatureResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.AMBIENT_TEMPERATURE, (data: sensor.AmbientTemperatureResponse) => {
    console.info('Succeeded in invoking on. Temperature: ' + data.temperature);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.AMBIENT_TEMPERATURE);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### BAROMETER<sup>9+</sup>

on(type: SensorId.BAROMETER, callback: Callback&lt;BarometerResponse&gt;, options?: Options): void

Subscribes to data of the barometer sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).BAROMETER                        | Yes  | Sensor type. The value is fixed at **SensorId.BAROMETER**.                 |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **BarometerResponse** object.    |
| options  | [Options](#options)                                     | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.BAROMETER, (data: sensor.BarometerResponse) => {
    console.info('Succeeded in invoking on. Atmospheric pressure: ' + data.pressure);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.BAROMETER);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

###  GRAVITY<sup>9+</sup>

on(type: SensorId.GRAVITY, callback: Callback&lt;GravityResponse&gt;, options?: Options): void

Subscribes to data of the gravity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                               | Mandatory| Description                                                       |
| -------- | --------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).GRAVITY                      | Yes  | Sensor type. The value is fixed at **SensorId.GRAVITY**.                   |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **GravityResponse** object.      |
| options  | [Options](#options)                                 | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.GRAVITY, (data: sensor.GravityResponse) => {
    console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.GRAVITY);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

###  GYROSCOPE<sup>9+</sup>

on(type: SensorId.GYROSCOPE, callback: Callback&lt;GyroscopeResponse&gt;, options?: Options): void

Subscribes to data of the gyroscope sensor.

**Required permissions**: ohos.permission.GYROSCOPE

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).GYROSCOPE                        | Yes  | Sensor type. The value is fixed at **SensorId.GYROSCOPE**.                 |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes  | Callback used to report the sensor data, which is a **GyroscopeResponse** object.    |
| options  | [Options](#options)                                     | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.GYROSCOPE, (data: sensor.GyroscopeResponse) => {
    console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.GYROSCOPE);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

###  GYROSCOPE_UNCALIBRATED<sup>9+</sup>

on(type: SensorId.GYROSCOPE_UNCALIBRATED, callback: Callback&lt;GyroscopeUncalibratedResponse&gt;,
      options?: Options): void

Subscribes to data of the uncalibrated gyroscope sensor.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor 

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).GYROSCOPE_UNCALIBRATED                | Yes  | Sensor type. The value is fixed at **SensorId.GYROSCOPE_UNCALIBRATED**.     |
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **GyroscopeUncalibratedResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.GYROSCOPE_UNCALIBRATED, (data: sensor.GyroscopeUncalibratedResponse) => {
    console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
    console.info('Succeeded in invoking on. X-coordinate bias: ' + data.biasX);
    console.info('Succeeded in invoking on. Y-coordinate bias: ' + data.biasY);
    console.info('Succeeded in invoking on. Z-coordinate bias: ' + data.biasZ);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.GYROSCOPE_UNCALIBRATED);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}

```

###  HALL<sup>9+</sup>

on(type: SensorId.HALL, callback: Callback&lt;HallResponse&gt;, options?: Options): void

Subscribes to data of the Hall effect sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                         | Mandatory| Description                                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).HALL                   | Yes  | Sensor type. The value is fixed at **SensorId.HALL**.                       |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **HallResponse** object.          |
| options  | [Options](#options)                           | No  | List of optional parameters. The default value is 200,000,000 ns. This parameter is used to set the data reporting frequency when Hall effect events are frequently triggered.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.HALL, (data: sensor.HallResponse) => {
    console.info('Succeeded in invoking on. Hall status: ' + data.status);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.HALL);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}

```

###   HEART_RATE<sup>9+</sup>

on(type: SensorId.HEART_RATE, callback: Callback&lt;HeartRateResponse&gt;, options?: Options): void

Subscribes to data of the heart rate sensor.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).HEART_RATE                       | Yes  | Sensor type. The value is fixed at **SensorId.HEART_RATE**.                |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **HeartRateResponse** object.    |
| options  | [Options](#options)                                     | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.HEART_RATE, (data: sensor.HeartRateResponse) => {
    console.info('Succeeded in invoking on. Heart rate: ' + data.heartRate);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.HEART_RATE);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

###  HUMIDITY<sup>9+</sup>

on(type: SensorId.HUMIDITY, callback: Callback&lt;HumidityResponse&gt;, options?: Options): void

Subscribes to data of the humidity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                       |
| -------- | ----------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).HUMIDITY                       | Yes  | Sensor type. The value is fixed at **SensorId.HUMIDITY**.                  |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **HumidityResponse** object.     |
| options  | [Options](#options)                                   | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.HUMIDITY, (data: sensor.HumidityResponse) => {
    console.info('Succeeded in invoking on. Humidity: ' + data.humidity);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.HUMIDITY);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

###   LINEAR_ACCELEROMETER<sup>9+</sup>

on(type: SensorId.LINEAR_ACCELEROMETER, callback: Callback&lt;LinearAccelerometerResponse&gt;,
        options?: Options): void

Subscribes to data of the linear acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).LINEAR_ACCELEROMETER                  | Yes  | Sensor type. The value is fixed at **SensorId.LINEAR_ACCELEROMETER**.       |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **LinearAccelerometerResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.LINEAR_ACCELEROMETER, (data: sensor.LinearAccelerometerResponse) => {
    console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.LINEAR_ACCELEROMETER);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

###  MAGNETIC_FIELD<sup>9+</sup>

on(type: SensorId.MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;, options?: Options): void

Subscribes to data of the magnetic field sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).MAGNETIC_FIELD                        | Yes  | Sensor type. The value is fixed at **SensorId.MAGNETIC_FIELD**.            |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **MagneticFieldResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.MAGNETIC_FIELD, (data: sensor.MagneticFieldResponse) => {
    console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.MAGNETIC_FIELD);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### MAGNETIC_FIELD_UNCALIBRATED<sup>9+</sup>

on(type: SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback: Callback&lt;MagneticFieldUncalibratedResponse&gt;, options?: Options): void

Subscribes to data of the uncalibrated magnetic field sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).MAGNETIC_FIELD_UNCALIBRATED           | Yes  | Sensor type. The value is fixed at **SensorId.MAGNETIC_FIELD_UNCALIBRATED**.|
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **MagneticFieldUncalibratedResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, (data: sensor.MagneticFieldUncalibratedResponse) => {
    console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
    console.info('Succeeded in invoking on. X-coordinate bias: ' + data.biasX);
    console.info('Succeeded in invoking on. Y-coordinate bias: ' + data.biasY);
    console.info('Succeeded in invoking on. Z-coordinate bias: ' + data.biasZ);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### ORIENTATION<sup>9+</sup>

on(type: SensorId.ORIENTATION, callback: Callback&lt;OrientationResponse&gt;, options?: Options): void

Subscribes to data of the orientation sensor.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                       |
| -------- | ----------------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).ORIENTATION                          | Yes  | Sensor type. The value is fixed at **SensorId.ORIENTATION**.               |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **OrientationResponse** object.  |
| options  | [Options](#options)                                         | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.ORIENTATION, (data: sensor.OrientationResponse) => {
    console.info('Succeeded in the device rotating at an angle around the Z axis: ' + data.alpha);
    console.info('Succeeded in the device rotating at an angle around the X axis: ' + data.beta);
    console.info('Succeeded in the device rotating at an angle around the Y axis: ' + data.gamma);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.ORIENTATION);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### PEDOMETER<sup>9+</sup>

on(type: SensorId.PEDOMETER, callback: Callback&lt;PedometerResponse&gt;, options?: Options): void

Subscribes to data of the pedometer sensor.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).PEDOMETER                        | Yes  | Sensor type. The value is fixed at **SensorId.PEDOMETER**.                 |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **PedometerResponse** object.    |
| options  | [Options](#options)                                     | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.PEDOMETER, (data: sensor.PedometerResponse) => {
    console.info('Succeeded in invoking on. Step count: ' + data.steps);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.PEDOMETER);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### PEDOMETER_DETECTION<sup>9+</sup>

on(type: SensorId.PEDOMETER_DETECTION, callback: Callback&lt;PedometerDetectionResponse&gt;,
        options?: Options): void

Subscribes to data of the pedometer detection sensor.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).PEDOMETER_DETECTION                   | Yes  | Sensor type. The value is fixed at **SensorId.PEDOMETER_DETECTION**.        |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **PedometerDetectionResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.PEDOMETER_DETECTION, (data: sensor.PedometerDetectionResponse) => {
    console.info('Succeeded in invoking on. Pedometer scalar: ' + data.scalar);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.PEDOMETER_DETECTION);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### PROXIMITY<sup>9+</sup>

on(type: SensorId.PROXIMITY, callback: Callback&lt;ProximityResponse&gt;, options?: Options): void

Subscribes to data of the proximity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).PROXIMITY                        | Yes  | Sensor type. The value is fixed at **SensorId.PROXIMITY**.                  |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **ProximityResponse** object.     |
| options  | [Options](#options)                                     | No  | List of optional parameters. The default value is 200,000,000 ns. This parameter is used to set the data reporting frequency when proximity sensor events are frequently triggered.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3.Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.PROXIMITY, (data: sensor.ProximityResponse) => {
    console.info('Succeeded in invoking on. Distance: ' + data.distance);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.PROXIMITY);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### ROTATION_VECTOR<sup>9+</sup>

on(type: SensorId.ROTATION_VECTOR, callback: Callback&lt;RotationVectorResponse&gt;,
        options?: Options): void

Subscribes to data of the rotation vector sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ROTATION_VECTOR                       | Yes  | Sensor type. The value is fixed at **SensorId.ROTATION_VECTOR**.            |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **RotationVectorResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3.Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.ROTATION_VECTOR, (data: sensor.RotationVectorResponse) => {
    console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
    console.info('Succeeded in invoking on. Scalar quantity: ' + data.w);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.ROTATION_VECTOR);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

### SIGNIFICANT_MOTION<sup>9+</sup>

on(type: SensorId.SIGNIFICANT_MOTION, callback: Callback&lt;SignificantMotionResponse&gt;,
        options?: Options): void

Subscribes to data of the significant motion sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).SIGNIFICANT_MOTION                    | Yes  | Sensor type. The value is fixed at **SensorId.SIGNIFICANT_MOTION**.         |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **SignificantMotionResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3.Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.SIGNIFICANT_MOTION, (data: sensor.SignificantMotionResponse) => {
    console.info('Succeeded in invoking on. Scalar data: ' + data.scalar);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.SIGNIFICANT_MOTION);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

###  WEAR_DETECTION<sup>9+</sup>

on(type: SensorId.WEAR_DETECTION, callback: Callback&lt;WearDetectionResponse&gt;,
        options?: Options): void

Subscribes to data of the wear detection sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).WEAR_DETECTION                        | Yes  | Sensor type. The value is fixed at **SensorId.WEAR_DETECTION**.            |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **WearDetectionResponse** object.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3.Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.on(sensor.SensorId.WEAR_DETECTION, (data: sensor.WearDetectionResponse) => {
    console.info('Succeeded in invoking on. Wear status: ' + data.value);
  }, { interval: 100000000 });
  setTimeout(() => {
    sensor.off(sensor.SensorId.WEAR_DETECTION);
  }, 500);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.once<sup>9+</sup>

### ACCELEROMETER<sup>9+</sup>

once(type: SensorId.ACCELEROMETER, callback: Callback&lt;AccelerometerResponse&gt;): void

Obtains data of the acceleration sensor once.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).ACCELEROMETER                         | Yes  | Sensor type. The value is fixed at **SensorId.ACCELEROMETER**.             |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is an **AccelerometerResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.ACCELEROMETER, (data: sensor.AccelerometerResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### ACCELEROMETER_UNCALIBRATED<sup>9+</sup>

once(type: SensorId.ACCELEROMETER_UNCALIBRATED, callback: Callback&lt;AccelerometerUncalibratedResponse&gt;): void

Obtains data of the uncalibrated acceleration sensor once.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ACCELEROMETER_UNCALIBRATED            | Yes  | Sensor type. The value is fixed at **SensorId.ACCELEROMETER_UNCALIBRATED**. |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes  | Callback used to report the sensor data, which is an **AccelerometerUncalibratedResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, (data: sensor.AccelerometerUncalibratedResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
    console.info('Succeeded in invoking once. X-coordinate bias: ' + data.biasX);
    console.info('Succeeded in invoking once. Y-coordinate bias: ' + data.biasY);
    console.info('Succeeded in invoking once. Z-coordinate bias: ' + data.biasZ);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### AMBIENT_LIGHT<sup>9+</sup>

once(type: SensorId.AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;): void

Obtains data of the ambient light sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                           | Mandatory| Description                                               |
| -------- | ----------------------------------------------- | ---- | --------------------------------------------------- |
| type     | [SensorId](#sensorid9).AMBIENT_LIGHT            | Yes  | Sensor type. The value is fixed at **SensorId.AMBIENT_LIGHT**.     |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **LightResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.AMBIENT_LIGHT, (data: sensor.LightResponse) => {
    console.info('Succeeded in invoking once. the ambient light intensity: ' + data.intensity);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### AMBIENT_TEMPERATURE<sup>9+</sup>

once(type: SensorId.AMBIENT_TEMPERATURE, callback: Callback&lt;AmbientTemperatureResponse&gt;): void

Obtains data of the temperature sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).AMBIENT_TEMPERATURE                   | Yes  | Sensor type. The value is fixed at **SensorId.AMBIENT_TEMPERATURE**.        |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes  | Callback used to report the sensor data, which is an **AmbientTemperatureResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.AMBIENT_TEMPERATURE, (data: sensor.AmbientTemperatureResponse) => {
    console.info('Succeeded in invoking once. Temperature: ' + data.temperature);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### BAROMETER<sup>9+</sup>

once(type: SensorId.BAROMETER, callback: Callback&lt;BarometerResponse&gt;): void

Obtains data of the barometer sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).BAROMETER                        | Yes  | Sensor type. The value is fixed at **SensorId.BAROMETER**.             |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **BarometerResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.BAROMETER, (data: sensor.BarometerResponse) => {
    console.info('Succeeded in invoking once. Atmospheric pressure: ' + data.pressure);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### GRAVITY<sup>9+</sup>

once(type: SensorId.GRAVITY, callback: Callback&lt;GravityResponse&gt;): void

Obtains data of the gravity sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                               | Mandatory| Description                                                 |
| -------- | --------------------------------------------------- | ---- | ----------------------------------------------------- |
| type     | [SensorId](#sensorid9).GRAVITY                      | Yes  | Sensor type. The value is fixed at **SensorId.GRAVITY**.             |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **GravityResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.GRAVITY, (data: sensor.GravityResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### GYROSCOPE<sup>9+</sup>

once(type: SensorId.GYROSCOPE, callback: Callback&lt;GyroscopeResponse&gt;): void

Obtains to data of the gyroscope sensor once.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).GYROSCOPE                        | Yes  | Sensor type. The value is fixed at **SensorId.GYROSCOPE**.             |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes  | Callback used to report the sensor data, which is a **GyroscopeResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.GYROSCOPE, (data: sensor.GyroscopeResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### GYROSCOPE_UNCALIBRATED<sup>9+</sup>

once(type: SensorId.GYROSCOPE_UNCALIBRATED, callback: Callback&lt;GyroscopeUncalibratedResponse&gt;): void

Obtains data of the uncalibrated gyroscope sensor once.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).GYROSCOPE_UNCALIBRATED                | Yes  | Sensor type. The value is fixed at **SensorId.GYROSCOPE_UNCALIBRATED**.     |
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **GyroscopeUncalibratedResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.GYROSCOPE_UNCALIBRATED, (data: sensor.GyroscopeUncalibratedResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
    console.info('Succeeded in invoking once. X-coordinate bias: ' + data.biasX);
    console.info('Succeeded in invoking once. Y-coordinate bias: ' + data.biasY);
    console.info('Succeeded in invoking once. Z-coordinate bias: ' + data.biasZ);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### HALL<sup>9+</sup>

once(type: SensorId.HALL, callback: Callback&lt;HallResponse&gt;): void

Obtains data of the Hall effect sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                         | Mandatory| Description                                              |
| -------- | --------------------------------------------- | ---- | -------------------------------------------------- |
| type     | [SensorId](#sensorid9).HALL                   | Yes  | Sensor type. The value is fixed at **SensorId.HALL**.             |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **HallResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.HALL, (data: sensor.HallResponse) => {
    console.info('Succeeded in invoking once. Status: ' + data.status);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### HEART_RATE<sup>9+</sup>

once(type: SensorId.HEART_RATE, callback: Callback&lt;HeartRateResponse&gt;): void

Obtains data of the heart rate sensor once.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).HEART_RATE                       | Yes  | Sensor type. The value is fixed at **SensorId.HEART_RATE**.            |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **HeartRateResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.HEART_RATE, (data: sensor.HeartRateResponse) => {
    console.info('Succeeded in invoking once. Heart rate: ' + data.heartRate);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### HUMIDITY<sup>9+</sup>

once(type: SensorId.HUMIDITY, callback: Callback&lt;HumidityResponse&gt;): void

Obtains data of the humidity sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                  |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | [SensorId](#sensorid9).HUMIDITY                       | Yes  | Sensor type. The value is fixed at **SensorId.HUMIDITY**.             |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **HumidityResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.HUMIDITY, (data: sensor.HumidityResponse) => {
    console.info('Succeeded in invoking once. Humidity: ' + data.humidity);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### LINEAR_ACCELEROMETER<sup>9+</sup>

once(type: SensorId.LINEAR_ACCELEROMETER, callback: Callback&lt;LinearAccelerometerResponse&gt;): void

Obtains data of the linear acceleration sensor once.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).LINEAR_ACCELEROMETER                  | Yes  | Sensor type. The value is fixed at **SensorId.LINEAR_ACCELEROMETER**.       |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **LinearAccelerometerResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.LINEAR_ACCELEROMETER, (data: sensor.LinearAccelerometerResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### MAGNETIC_FIELD<sup>9+</sup>

once(type: SensorId.MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;): void

Obtains data of the magnetic field sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).MAGNETIC_FIELD                        | Yes  | Sensor type. The value is fixed at **SensorId.MAGNETIC_FIELD**.            |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **MagneticFieldResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.MAGNETIC_FIELD, (data: sensor.MagneticFieldResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### MAGNETIC_FIELD_UNCALIBRATED<sup>9+</sup>

once(type: SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback: Callback&lt;MagneticFieldUncalibratedResponse&gt;): void

Obtains data of the uncalibrated magnetic field sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).MAGNETIC_FIELD_UNCALIBRATED           | Yes  | Sensor type. The value is fixed at **SensorId.MAGNETIC_FIELD_UNCALIBRATED**.|
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **MagneticFieldUncalibratedResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, (data: sensor.MagneticFieldUncalibratedResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
    console.info('Succeeded in invoking once. X-coordinate bias: ' + data.biasX);
    console.info('Succeeded in invoking once. Y-coordinate bias: ' + data.biasY);
    console.info('Succeeded in invoking once. Z-coordinate bias: ' + data.biasZ);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### ORIENTATION<sup>9+</sup>

once(type: SensorId.ORIENTATION, callback: Callback&lt;OrientationResponse&gt;): void

Obtains data of the orientation sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                     |
| -------- | ----------------------------------------------------------- | ---- | --------------------------------------------------------- |
| type     | [SensorId](#sensorid9).ORIENTATION                          | Yes  | Sensor type. The value is fixed at **SensorId.ORIENTATION**.             |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **OrientationResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.ORIENTATION, (data: sensor.OrientationResponse) => {
    console.info('Succeeded in the device rotating at an angle around the X axis: ' + data.beta);
    console.info('Succeeded in the device rotating at an angle around the Y axis: ' + data.gamma);
    console.info('Succeeded in the device rotating at an angle around the Z axis: ' + data.alpha);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### PEDOMETER<sup>9+</sup>

once(type: SensorId.PEDOMETER, callback: Callback&lt;PedometerResponse&gt;): void

Obtains data of the pedometer sensor once.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).PEDOMETER                        | Yes  | Sensor type. The value is fixed at **SensorId.PEDOMETER**.             |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **PedometerResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.PEDOMETER, (data: sensor.PedometerResponse) => {
    console.info('Succeeded in invoking once. Step count: ' + data.steps);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### PEDOMETER_DETECTION<sup>9+</sup>

once(type: SensorId.PEDOMETER_DETECTION, callback: Callback&lt;PedometerDetectionResponse&gt;): void

Obtains data of the pedometer sensor once.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).PEDOMETER_DETECTION                   | Yes  | Sensor type. The value is fixed at **SensorId.PEDOMETER_DETECTION**.        |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **PedometerDetectionResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.PEDOMETER_DETECTION, (data: sensor.PedometerDetectionResponse) => {
    console.info('Succeeded in invoking once. Scalar data: ' + data.scalar);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### PROXIMITY<sup>9+</sup>

once(type: SensorId.PROXIMITY, callback: Callback&lt;ProximityResponse&gt;): void

Obtains data of the proximity sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).PROXIMITY                        | Yes  | Sensor type. The value is fixed at **SensorId.PROXIMITY**.             |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **ProximityResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.PROXIMITY, (data: sensor.ProximityResponse) => {
    console.info('Succeeded in invoking once. Distance: ' + data.distance);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### ROTATION_VECTOR<sup>9+</sup>

once(type: SensorId.ROTATION_VECTOR, callback: Callback&lt;RotationVectorResponse&gt;): void

Obtains data of the rotation vector sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ROTATION_VECTOR                       | Yes  | Sensor type. The value is fixed at **SensorId.ROTATION_VECTOR**.            |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **RotationVectorResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.ROTATION_VECTOR, (data: sensor.RotationVectorResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
    console.info('Succeeded in invoking once. Scalar quantity: ' + data.w);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### SIGNIFICANT_MOTION<sup>9+</sup>

once(type: SensorId.SIGNIFICANT_MOTION, callback: Callback&lt;SignificantMotionResponse&gt;): void

Obtains data of the significant motion sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).SIGNIFICANT_MOTION                    | Yes  | Sensor type. The value is fixed at **SensorId.SIGNIFICANT_MOTION**.         |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **SignificantMotionResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.SIGNIFICANT_MOTION, (data: sensor.SignificantMotionResponse) => {
    console.info('Succeeded in invoking once. Scalar data: ' + data.scalar);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

### WEAR_DETECTION<sup>9+</sup>

once(type: SensorId.WEAR_DETECTION, callback: Callback&lt;WearDetectionResponse&gt;): void

Obtains data of the wear detection sensor once.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).WEAR_DETECTION                        | Yes  | Sensor type. The value is fixed at **SensorId.WEAR_DETECTION**.            |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **WearDetectionResponse** object.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.once(sensor.SensorId.WEAR_DETECTION, (data: sensor.WearDetectionResponse) => {
    console.info('Succeeded in invoking once. Wear status: ' + data.value);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.off

### ACCELEROMETER<sup>9+</sup> 

off(type: SensorId.ACCELEROMETER, callback?: Callback&lt;AccelerometerResponse&gt;): void

Unsubscribes from data of the acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ACCELEROMETER                         | Yes  | Sensor type. The value is fixed at **SensorId.ACCELEROMETER**.              |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
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
  sensor.on(sensor.SensorId.ACCELEROMETER, callback1);
  sensor.on(sensor.SensorId.ACCELEROMETER, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.ACCELEROMETER, callback1);
  // Unsubscribe from all callbacks of the SensorId.ACCELEROMETER type.
  sensor.off(sensor.SensorId.ACCELEROMETER);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### ACCELEROMETER_UNCALIBRATED<sup>9+</sup>  

off(type: SensorId.ACCELEROMETER_UNCALIBRATED, callback?: Callback&lt;AccelerometerUncalibratedResponse&gt;): void

Unsubscribes from data of the uncalibrated acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ACCELEROMETER_UNCALIBRATED            | Yes  | Sensor type. The value is fixed at **SensorId.ACCELEROMETER_UNCALIBRATED**. |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
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
  sensor.on(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, callback1);
  sensor.on(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, callback1);
  // Unsubscribe from all callbacks of the SensorId.ACCELEROMETER_UNCALIBRATED type.
  sensor.off(sensor.SensorId.ACCELEROMETER_UNCALIBRATED);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### AMBIENT_LIGHT<sup>9+</sup> 

off(type: SensorId.AMBIENT_LIGHT, callback?: Callback&lt;LightResponse&gt;): void

Unsubscribes from data of the ambient light sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).AMBIENT_LIGHT            | Yes  | Sensor type. The value is fixed at **SensorId.AMBIENT_LIGHT**.              |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.AMBIENT_LIGHT, callback1);
  sensor.on(sensor.SensorId.AMBIENT_LIGHT, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.AMBIENT_LIGHT, callback1);
  // Unsubscribe from all callbacks of the SensorId.AMBIENT_LIGHT type.
  sensor.off(sensor.SensorId.AMBIENT_LIGHT);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### AMBIENT_TEMPERATURE<sup>9+</sup> 

off(type: SensorId.AMBIENT_TEMPERATURE, callback?: Callback&lt;AmbientTemperatureResponse&gt;): void

Unsubscribes from data of the ambient temperature sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).AMBIENT_TEMPERATURE                   | Yes  | Sensor type. The value is fixed at **SensorId.AMBIENT_TEMPERATURE**.        |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.AMBIENT_TEMPERATURE, callback1);
  sensor.on(sensor.SensorId.AMBIENT_TEMPERATURE, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.AMBIENT_TEMPERATURE, callback1);
  // Unsubscribe from all callbacks of the SensorId.AMBIENT_TEMPERATURE type.
  sensor.off(sensor.SensorId.AMBIENT_TEMPERATURE);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### BAROMETER<sup>9+</sup>  

off(type: SensorId.BAROMETER, callback?: Callback&lt;BarometerResponse&gt;): void

Unsubscribes from data of the barometer sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).BAROMETER                        | Yes  | Sensor type. The value is fixed at **SensorId.BAROMETER**.                  |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
    sensor.on(sensor.SensorId.BAROMETER, callback1);
    sensor.on(sensor.SensorId.BAROMETER, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.BAROMETER, callback1);
    // Unsubscribe from all callbacks of the SensorId.BAROMETER type.
    sensor.off(sensor.SensorId.BAROMETER);
} catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### GRAVITY<sup>9+</sup> 

off(type: SensorId.GRAVITY, callback?: Callback&lt;GravityResponse&gt;): void

Unsubscribes from data of the gravity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                               | Mandatory| Description                                                        |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).GRAVITY                      | Yes  | Sensor type. The value is fixed at **SensorId.GRAVITY**.                    |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.GRAVITY, callback1);
  sensor.on(sensor.SensorId.GRAVITY, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.GRAVITY, callback1);
  // Unsubscribe from all callbacks of the SensorId.GRAVITY type.
  sensor.off(sensor.SensorId.GRAVITY);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}

```

### GYROSCOPE<sup>9+</sup> 

off(type: SensorId.GYROSCOPE, callback?: Callback&lt;GyroscopeResponse&gt;): void

Unsubscribes from data of the gyroscope sensor.

**Required permissions**: ohos.permission.GYROSCOPE

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).GYROSCOPE                        | Yes  | Sensor type. The value is fixed at **SensorId.GYROSCOPE**.                  |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
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
  sensor.on(sensor.SensorId.GYROSCOPE, callback1);
  sensor.on(sensor.SensorId.GYROSCOPE, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.GYROSCOPE, callback1);
  // Unsubscribe from all callbacks of the SensorId.GYROSCOPE type.
  sensor.off(sensor.SensorId.GYROSCOPE);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### GYROSCOPE_UNCALIBRATED<sup>9+</sup> 

off(type: SensorId.GYROSCOPE_UNCALIBRATED, callback?: Callback&lt;GyroscopeUncalibratedResponse&gt;): void

 Unsubscribes from data of the uncalibrated gyroscope sensor.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).GYROSCOPE_UNCALIBRATED                | Yes  | Sensor type. The value is fixed at **SensorId.GYROSCOPE_UNCALIBRATED**.     |
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
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
  sensor.on(sensor.SensorId.GYROSCOPE_UNCALIBRATED, callback1);
  sensor.on(sensor.SensorId.GYROSCOPE_UNCALIBRATED, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.GYROSCOPE_UNCALIBRATED, callback1);
  // Unsubscribe from all callbacks of the SensorId.GYROSCOPE_UNCALIBRATED type.
  sensor.off(sensor.SensorId.GYROSCOPE_UNCALIBRATED);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### HALL<sup>9+</sup> 

off(type: SensorId.HALL, callback?: Callback&lt;HallResponse&gt;): void

Unsubscribes from data of the Hall effect sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                         | Mandatory| Description                                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).HALL                   | Yes  | Sensor type. The value is fixed at **SensorId.HALL**.                       |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.HALL, callback1);
  sensor.on(sensor.SensorId.HALL, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.HALL, callback1);
  // Unsubscribe from all callbacks of the SensorId.HALL type.
  sensor.off(sensor.SensorId.HALL);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### HEART_RATE<sup>9+</sup> 

off(type: SensorId.HEART_RATE, callback?: Callback&lt;HeartRateResponse&gt;): void

Unsubscribes from data of the heart rate sensor.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).HEART_RATE                       | Yes  | Sensor type. The value is fixed at **SensorId.HEART_RATE**.                 |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
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
  sensor.on(sensor.SensorId.HEART_RATE, callback1);
  sensor.on(sensor.SensorId.HEART_RATE, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.HEART_RATE, callback1);
  // Unsubscribe from all callbacks of the SensorId.HEART_RATE type.
  sensor.off(sensor.SensorId.HEART_RATE);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### HUMIDITY<sup>9+</sup> 

off(type: SensorId.HUMIDITY, callback?: Callback&lt;HumidityResponse&gt;): void

Unsubscribes from data of the humidity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).HUMIDITY                       | Yes  | Sensor type. The value is fixed at **SensorId.HUMIDITY**.                   |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.HUMIDITY, callback1);
  sensor.on(sensor.SensorId.HUMIDITY, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.HUMIDITY, callback1);
  // Unsubscribe from all callbacks of the SensorId.HUMIDITY type.
  sensor.off(sensor.SensorId.HUMIDITY);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### LINEAR_ACCELEROMETER<sup>9+</sup> 

off(type: SensorId.LINEAR_ACCELEROMETER, callback?: Callback&lt;LinearAccelerometerResponse&gt;): void

Unsubscribes from data of the linear acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).LINEAR_ACCELEROMETER                  | Yes  | Sensor type. The value is fixed at **SensorId.LINEAR_ACCELERATION**.        |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
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
  sensor.on(sensor.SensorId.LINEAR_ACCELEROMETER, callback1);
  sensor.on(sensor.SensorId.LINEAR_ACCELEROMETER, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.LINEAR_ACCELEROMETER, callback1);
  // Unsubscribe from all callbacks of the SensorId.LINEAR_ACCELEROMETER type.
  sensor.off(sensor.SensorId.LINEAR_ACCELEROMETER);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### MAGNETIC_FIELD<sup>9+</sup> 

off(type: SensorId.MAGNETIC_FIELD, callback?: Callback&lt;MagneticFieldResponse&gt;): void

Unsubscribes from data of the magnetic field sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).MAGNETIC_FIELD                        | Yes  | Sensor type. The value is fixed at **SensorId.MAGNETIC_FIELD**.             |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.MAGNETIC_FIELD, callback1);
  sensor.on(sensor.SensorId.MAGNETIC_FIELD, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.MAGNETIC_FIELD, callback1);
  // Unsubscribe from all callbacks of the SensorId.MAGNETIC_FIELD type.
  sensor.off(sensor.SensorId.MAGNETIC_FIELD);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### MAGNETIC_FIELD_UNCALIBRATED<sup>9+</sup> 

off(type: SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback?: Callback&lt;MagneticFieldUncalibratedResponse&gt;): void

Unsubscribes from data of the uncalibrated magnetic field sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).MAGNETIC_FIELD_UNCALIBRATED           | Yes  | Sensor type. The value is fixed at **SensorId.MAGNETIC_FIELD_UNCALIBRATED**.|
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback1);
  sensor.on(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback1);
  // Unsubscribe from all callbacks of the SensorId.MAGNETIC_FIELD_UNCALIBRATED type.
  sensor.off(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### ORIENTATION<sup>9+</sup> 

off(type: SensorId.ORIENTATION, callback?: Callback&lt;OrientationResponse&gt;): void

Unsubscribes from data of the orientation sensor.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ORIENTATION                          | Yes  | Sensor type. The value is fixed at **SensorId.ORIENTATION**.                |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.ORIENTATION, callback1);
  sensor.on(sensor.SensorId.ORIENTATION, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.ORIENTATION, callback1);
  // Unsubscribe from all callbacks of the SensorId.ORIENTATION type.
  sensor.off(sensor.SensorId.ORIENTATION);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### PEDOMETER<sup>9+</sup>

off(type: SensorId.PEDOMETER, callback?: Callback&lt;PedometerResponse&gt;): void

Unsubscribes from data of the pedometer sensor.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).PEDOMETER                        | Yes  | Sensor type. The value is fixed at **SensorId.PEDOMETER**.                  |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
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
  sensor.on(sensor.SensorId.PEDOMETER, callback1);
  sensor.on(sensor.SensorId.PEDOMETER, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.PEDOMETER, callback1);
  // Unsubscribe from all callbacks of the SensorId.ORIENTATION type.
  sensor.off(sensor.SensorId.PEDOMETER);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### PEDOMETER_DETECTION<sup>9+</sup> 

off(type: SensorId.PEDOMETER_DETECTION, callback?: Callback&lt;PedometerDetectionResponse&gt;): void

Unsubscribes from data of the pedometer detection sensor.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).PEDOMETER_DETECTION                   | Yes  | Sensor type. The value is fixed at **SensorId.PEDOMETER_DETECTION**.        |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
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
  sensor.on(sensor.SensorId.PEDOMETER_DETECTION, callback1);
  sensor.on(sensor.SensorId.PEDOMETER_DETECTION, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.PEDOMETER_DETECTION, callback1);
  // Unsubscribe from all callbacks of the SensorId.PEDOMETER_DETECTION type.
  sensor.off(sensor.SensorId.PEDOMETER_DETECTION);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### PROXIMITY<sup>9+</sup>  

off(type: SensorId.PROXIMITY, callback?: Callback&lt;ProximityResponse&gt;): void

Unsubscribes from data of the proximity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).PROXIMITY                        | Yes  | Sensor type. The value is fixed at **SensorId.PROXIMITY**.                  |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.PROXIMITY, callback1);
  sensor.on(sensor.SensorId.PROXIMITY, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.PROXIMITY, callback1);
  // Unsubscribe from all callbacks of the SensorId.PROXIMITY type.
  sensor.off(sensor.SensorId.PROXIMITY);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### ROTATION_VECTOR<sup>9+</sup> 

off(type: SensorId.ROTATION_VECTOR, callback?: Callback&lt;RotationVectorResponse&gt;): void

Unsubscribes from data of the rotation vector sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ROTATION_VECTOR                       | Yes  | Sensor type. The value is fixed at **SensorId.ROTATION_VECTOR**.            |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.ROTATION_VECTOR, callback1);
  sensor.on(sensor.SensorId.ROTATION_VECTOR, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.ROTATION_VECTOR, callback1);
  // Unsubscribe from all callbacks of the SensorId.ROTATION_VECTOR type.
  sensor.off(sensor.SensorId.ROTATION_VECTOR);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### SIGNIFICANT_MOTION<sup>9+</sup> 

off(type: SensorId.SIGNIFICANT_MOTION, callback?: Callback&lt;SignificantMotionResponse&gt;): void

Unsubscribes from data of the significant motion sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).SIGNIFICANT_MOTION                    | Yes  | Sensor type. The value is fixed at **SensorId.SIGNIFICANT_MOTION**.         |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.SIGNIFICANT_MOTION, callback1);
  sensor.on(sensor.SensorId.SIGNIFICANT_MOTION, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.SIGNIFICANT_MOTION, callback1);
  // Unsubscribe from all callbacks of the SensorId.SIGNIFICANT_MOTION type.
  sensor.off(sensor.SensorId.SIGNIFICANT_MOTION);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

### WEAR_DETECTION<sup>9+</sup> 

off(type: SensorId.WEAR_DETECTION, callback?: Callback&lt;WearDetectionResponse&gt;): void

Unsubscribes from data of the wear detection sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).WEAR_DETECTION                        | Yes  | Sensor type. The value is fixed at **SensorId.WEAR_DETECTION**.             |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
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
  sensor.on(sensor.SensorId.WEAR_DETECTION, callback1);
  sensor.on(sensor.SensorId.WEAR_DETECTION, callback2);
  // Unsubscribe from callback1.
  sensor.off(sensor.SensorId.WEAR_DETECTION, callback1);
  // Unsubscribe from all callbacks of the SensorId.WEAR_DETECTION type.
  sensor.off(sensor.SensorId.WEAR_DETECTION);
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getGeomagneticInfo<sup>9+</sup> 

getGeomagneticInfo(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback&lt;GeomagneticResponse&gt;): void

Obtains the geomagnetic field of a geographic location at a certain time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name         | Type                                                        | Mandatory| Description                              |
| --------------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| locationOptions | [LocationOptions](#locationoptions)                          | Yes  | Geographic location, including the longitude, latitude, and altitude.                        |
| timeMillis      | number                                                       | Yes  | Time when the magnetic declination is obtained. The value is a Unix timestamp, in ms.|
| callback        | AsyncCallback&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Yes  | Callback used to return the geomagnetic field.                |

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.getGeomagneticInfo({ latitude: 80, longitude: 0, altitude: 0 }, 1580486400000,
      (err: BusinessError, data: sensor.GeomagneticResponse) => {
    if (err) {
      console.error(`Failed to get geomagneticInfo. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info("Succeeded in getting geomagneticInfo x" + data.x);
    console.info("Succeeded in getting geomagneticInfo y" + data.y);
    console.info("Succeeded in getting geomagneticInfo z" + data.z);
    console.info("Succeeded in getting geomagneticInfo geomagneticDip" + data.geomagneticDip);
    console.info("Succeeded in getting geomagneticInfo deflectionAngle" + data.deflectionAngle);
    console.info("Succeeded in getting geomagneticInfo levelIntensity" + data.levelIntensity);
    console.info("Succeeded in getting geomagneticInfo totalIntensity" + data.totalIntensity);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get geomagneticInfo. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getGeomagneticInfo<sup>9+</sup> 

getGeomagneticInfo(locationOptions: LocationOptions, timeMillis: number): Promise&lt;GeomagneticResponse&gt;

Obtains the geomagnetic field of a geographic location at a certain time. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name         | Type                               | Mandatory| Description                              |
| --------------- | ----------------------------------- | ---- | ---------------------------------- |
| locationOptions | [LocationOptions](#locationoptions) | Yes  | Geographic location, including the longitude, latitude, and altitude.                        |
| timeMillis      | number                              | Yes  | Time when the magnetic declination is obtained. The value is a Unix timestamp, in ms.|

**Return value**

| Type                                                      | Description          |
| ---------------------------------------------------------- | -------------- |
| Promise&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Promise used to return the geomagnetic field.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  const promise = sensor.getGeomagneticInfo({ latitude: 80, longitude: 0, altitude: 0 }, 1580486400000);
  promise.then((data: sensor.GeomagneticResponse) => {
    console.info("Succeeded in getting geomagneticInfo x" + data.x);
    console.info("Succeeded in getting geomagneticInfo y" + data.y);
    console.info("Succeeded in getting geomagneticInfo z" + data.z);
    console.info("Succeeded in getting geomagneticInfo geomagneticDip" + data.geomagneticDip);
    console.info("Succeeded in getting geomagneticInfo deflectionAngle" + data.deflectionAngle);
    console.info("Succeeded in getting geomagneticInfo levelIntensity" + data.levelIntensity);
    console.info("Succeeded in getting geomagneticInfo totalIntensity" + data.totalIntensity);
  }, (err: BusinessError) => {
    console.error(`Failed to get geomagneticInfo. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get geomagneticInfo. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getDeviceAltitude<sup>9+</sup> 

getDeviceAltitude(seaPressure: number, currentPressure: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the altitude based on the atmospheric pressure. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name         | Type                       | Mandatory| Description                                 |
| --------------- | --------------------------- | ---- | ------------------------------------- |
| seaPressure     | number                      | Yes  | Sea-level atmospheric pressure, in hPa.        |
| currentPressure | number                      | Yes  | Specified atmospheric pressure, in hPa.|
| callback        | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the altitude, in meters. |

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let seaPressure = 1013.2;
  let currentPressure = 1500.0;
  sensor.getDeviceAltitude(seaPressure, currentPressure, (err: BusinessError, data: number) => {
    if (err) {
      console.error(`Failed to get altitude. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting altitude: ' + data);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get altitude. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getDeviceAltitude<sup>9+</sup> 

getDeviceAltitude(seaPressure: number, currentPressure: number): Promise&lt;number&gt;

Obtains the altitude based on the atmospheric pressure. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name         | Type  | Mandatory| Description                                 |
| --------------- | ------ | ---- | ------------------------------------- |
| seaPressure     | number | Yes  | Sea-level atmospheric pressure, in hPa.        |
| currentPressure | number | Yes  | Specified atmospheric pressure, in hPa.|

**Return value**

| Type                 | Description                                |
| --------------------- | ------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the altitude, in meters.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let seaPressure = 1013.2;
  let currentPressure = 1500.0;
  const promise = sensor.getDeviceAltitude(seaPressure, currentPressure);
  promise.then((data: number) => {
    console.info('Succeeded in getting sensor_getDeviceAltitude_Promise', data);
  }, (err: BusinessError) => {
    console.error(`Failed to get altitude. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get altitude. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getInclination<sup>9+</sup> 

getInclination(inclinationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;number&gt;): void

Obtains the magnetic dip based on the inclination matrix. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                       | Mandatory| Description                        |
| ----------------- | --------------------------- | ---- | ---------------------------- |
| inclinationMatrix | Array&lt;number&gt;         | Yes  | Inclination matrix.              |
| callback          | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the magnetic dip, in radians.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // inclinationMatrix can be 3*3 or 4*4.
  let inclinationMatrix = [
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
  ]
  sensor.getInclination(inclinationMatrix, (err: BusinessError, data: number) => {
    if (err) {
      console.error(`Failed to get inclination. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting inclination: ' + data);
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get inclination. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getInclination<sup>9+</sup> 

 getInclination(inclinationMatrix: Array&lt;number&gt;): Promise&lt;number&gt;

Obtains the magnetic dip based on the inclination matrix. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type               | Mandatory| Description          |
| ----------------- | ------------------- | ---- | -------------- |
| inclinationMatrix | Array&lt;number&gt; | Yes  | Inclination matrix.|

**Return value**

| Type                 | Description                        |
| --------------------- | ---------------------------- |
| Promise&lt;number&gt; | Promise used to return the magnetic dip, in radians.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // inclinationMatrix can be 3*3 or 4*4.
  let inclinationMatrix = [
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
  ]
  const promise = sensor.getInclination(inclinationMatrix);
  promise.then((data: number) => {
    console.info('Succeeded in getting inclination: ' + data);
  }, (err: BusinessError) => {
    console.error(`Failed to get inclination. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get inclination. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getAngleVariation<sup>9+</sup>

 getAngleVariation(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;,
        callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the angle change between two rotation matrices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name               | Type                                    | Mandatory| Description                             |
| --------------------- | ---------------------------------------- | ---- | --------------------------------- |
| currentRotationMatrix | Array&lt;number&gt;                      | Yes  | Current rotation matrix.               |
| preRotationMatrix     | Array&lt;number&gt;                      | Yes  | The other rotation matrix.                   |
| callback              | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the angle change around the z, x, and y axes.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // The rotation matrix can be 3*3 or 4*4.
  let currentRotationMatrix = [
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
  ];
  let preRotationMatrix = [
    1, 0, 0,
    0, 0.87, -0.50,
    0, 0.50, 0.87
  ];
  sensor.getAngleVariation(currentRotationMatrix, preRotationMatrix, (err: BusinessError, data: Array<number>) => {
    if (err) {
      console.error(`Failed to get angle variation. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    if (data.length < 3) {
      console.error("Failed to get angle variation, length" + data.length);
    }
    console.info("Z: " + data[0]);
    console.info("X: " + data[1]);
    console.info("Y  : " + data[2]);
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get angle variation. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getAngleVariation<sup>9+</sup>

getAngleVariation(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt; 

Obtains the angle change between two rotation matrices. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name               | Type               | Mandatory| Description              |
| --------------------- | ------------------- | ---- | ------------------ |
| currentRotationMatrix | Array&lt;number&gt; | Yes  | Current rotation matrix.|
| preRotationMatrix     | Array&lt;number&gt; | Yes  | The other rotation matrix.                 |

**Return value**

| Type                              | Description                             |
| ---------------------------------- | --------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the angle change around the z, x, and y axes.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // The rotation matrix can be 3*3 or 4*4.
  let currentRotationMatrix = [
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
  ];
  let preRotationMatrix = [
    1, 0, 0,
    0, 0.87, -0.50,
    0, 0.50, 0.87
  ];
  const promise = sensor.getAngleVariation(currentRotationMatrix, preRotationMatrix);
  promise.then((data: Array<number>) => {
    if (data.length < 3) {
      console.error("Failed to get angle variation, length" + data.length);
    }
    console.info("Z: " + data[0]);
    console.info("X: " + data[1]);
    console.info("Y  : " + data[2]);
  }, (err: BusinessError) => {
    console.error(`Failed to get angle variation. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get angle variation. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getRotationMatrix<sup>9+</sup> 

getRotationMatrix(rotationVector: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the rotation matrix from a rotation vector. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                    | Mandatory| Description          |
| -------------- | ---------------------------------------- | ---- | -------------- |
| rotationVector | Array&lt;number&gt;                      | Yes  | Rotation vector.|
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the rotation matrix.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];
  sensor.getRotationMatrix(rotationVector, (err: BusinessError, data: Array<number>) => {
    if (err) {
      console.error(`Failed to get rotationMatrix. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    for (let i = 0; i < data.length; i++) {
      console.info('Succeeded in getting data[' + i + ']: ' + data[i]);
    }
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get rotationMatrix. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getRotationMatrix<sup>9+</sup>

getRotationMatrix(rotationVector: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt; 

Obtains the rotation matrix from a rotation vector. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type               | Mandatory| Description          |
| -------------- | ------------------- | ---- | -------------- |
| rotationVector | Array&lt;number&gt; | Yes  | Rotation vector.|

**Return value**

| Type                              | Description          |
| ---------------------------------- | -------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation matrix.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];
  const promise = sensor.getRotationMatrix(rotationVector);
  promise.then((data: Array<number>) => {
    for (let i = 0; i < data.length; i++) {
      console.info('Succeeded in getting data[' + i + ']: ' + data[i]);
    }
  }, (err: BusinessError) => {
    console.error(`Failed to get rotationMatrix. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get rotationMatrix. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.transformRotationMatrix<sup>9+</sup> 

transformRotationMatrix(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions,
        callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Transforms a rotation vector based on the coordinate system. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name          | Type                                     | Mandatory| Description                  |
| ---------------- | ----------------------------------------- | ---- | ---------------------- |
| inRotationVector | Array&lt;number&gt;                       | Yes  | Rotation vector.        |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes  | Rotation vector to transform.      |
| callback         | AsyncCallback&lt;Array&lt;number&gt;&gt;  | Yes  | Callback used to return the rotation vector after being transformed.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rotationMatrix = [
    1, 0, 0,
    0, 0.87, -0.50,
    0, 0.50, 0.87
  ];
  sensor.transformRotationMatrix(rotationMatrix, { x: 1, y: 3 }, (err: BusinessError, data: Array<number>) => {
    if (err) {
      console.error(`Failed to transform rotationMatrix. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    for (let i = 0; i < data.length; i++) {
      console.info('Succeeded in getting data[' + i + '] = ' + data[i]);
    }
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to transform rotationMatrix. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.transformRotationMatrix<sup>9+</sup>

transformRotationMatrix(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions): Promise&lt;Array&lt;number&gt;&gt;

Transforms a rotation vector based on the coordinate system. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name          | Type                                     | Mandatory| Description            |
| ---------------- | ----------------------------------------- | ---- | ---------------- |
| inRotationVector | Array&lt;number&gt;                       | Yes  | Rotation vector.  |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes  | Rotation vector to transform.|

**Return value**

| Type                              | Description                  |
| ---------------------------------- | ---------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation vector after being transformed.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rotationMatrix = [
    1, 0, 0,
    0, 0.87, -0.50,
    0, 0.50, 0.87
  ];
  const promise = sensor.transformRotationMatrix(rotationMatrix, { x: 1, y: 3 });
  promise.then((data: Array<number>) => {
    for (let i = 0; i < data.length; i++) {
      console.info('Succeeded in getting data[' + i + ']: ' + data[i]);
    }
  }, (err: BusinessError) => {
    console.error(`Failed to transform rotationMatrix. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to transform rotationMatrix. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getQuaternion<sup>9+</sup> 

getQuaternion(rotationVector: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void 

Obtains the quaternion from a rotation vector. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                    | Mandatory| Description          |
| -------------- | ---------------------------------------- | ---- | -------------- |
| rotationVector | Array&lt;number&gt;                      | Yes  | Rotation vector.|
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the quaternion.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];
  sensor.getQuaternion(rotationVector, (err: BusinessError, data: Array<number>) => {
    if (err) {
      console.error(`Failed to get quaternion. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    for (let i = 0; i < data.length; i++) {
      console.info('Succeeded in getting data[' + i + ']: ' + data[i]);
    }
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get quaternion. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getQuaternion<sup>9+</sup>

getQuaternion(rotationVector: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Obtains the quaternion from a rotation vector. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type               | Mandatory| Description          |
| -------------- | ------------------- | ---- | -------------- |
| rotationVector | Array&lt;number&gt; | Yes  | Rotation vector.|

**Return value**

| Type                              | Description        |
| ---------------------------------- | ------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the quaternion.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];
    const promise = sensor.getQuaternion(rotationVector);
    promise.then((data: Array<number>) => {
        for (let i = 0; i < data.length; i++) {
            console.info('Succeeded in getting data[' + i + ']: ' + data[i]);
        }
    }, (err: BusinessError) => {
        console.error(`Failed to get quaternion. Code: ${err.code}, message: ${err.message}`);
    });
} catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`Failed to get quaternion. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getOrientation<sup>9+</sup>

getOrientation(rotationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void 

Obtains the device direction based on the rotation matrix. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                    | Mandatory| Description                             |
| -------------- | ---------------------------------------- | ---- | --------------------------------- |
| rotationMatrix | Array&lt;number&gt;                      | Yes  | Rotation matrix.                   |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the rotation angle around the z, x, and y axes.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let preRotationMatrix = [
    1, 0, 0,
    0, 0.87, -0.50,
    0, 0.50, 0.87
  ];
  sensor.getOrientation(preRotationMatrix, (err: BusinessError, data: Array<number>) => {
    if (err) {
      console.error(`Failed to get orientation. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    if (data.length < 3) {
      console.error("Failed to get orientation, length" + data.length);
    }
    console.info("Succeeded in getting data. Z: " + data[0]);
    console.info("Succeeded in getting data. X: " + data[1]);
    console.info("Succeeded in getting data. Y: " + data[2]);
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get orientation. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getOrientation<sup>9+</sup>

getOrientation(rotationMatrix: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Obtains the device direction based on the rotation matrix. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type               | Mandatory| Description          |
| -------------- | ------------------- | ---- | -------------- |
| rotationMatrix | Array&lt;number&gt; | Yes  | Rotation matrix.|

**Return value**

| Type                              | Description                             |
| ---------------------------------- | --------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation angle around the z, x, and y axes.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let preRotationMatrix = [
    1, 0, 0,
    0, 0.87, -0.50,
    0, 0.50, 0.87
  ];
  const promise = sensor.getOrientation(preRotationMatrix);
  promise.then((data: Array<number>) => {
    for (let i = 0; i < data.length; i++) {
      console.info('Succeeded in getting data[' + i + ']: ' + data[i]);
    }
  }, (err: BusinessError) => {
    console.error(`Failed to getOrientatin. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to getOrientatin Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getRotationMatrix<sup>9+</sup> 

getRotationMatrix(gravity: Array&lt;number&gt;, geomagnetic: Array&lt;number&gt;, callback: AsyncCallback&lt;RotationMatrixResponse&gt;): void 

Obtains the rotation matrix based on a gravity vector and geomagnetic vector. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                        | Mandatory| Description          |
| ----------- | ------------------------------------------------------------ | ---- | -------------- |
| gravity     | Array&lt;number&gt;                                          | Yes  | Gravity vector.|
| geomagnetic | Array&lt;number&gt;                                          | Yes  | Geomagnetic vector.|
| callback    | AsyncCallback&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | Yes  | Callback used to return the rotation matrix.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let gravity = [-0.27775216, 0.5351276, 9.788099];
  let geomagnetic = [210.87253, -78.6096, -111.44444];
  sensor.getRotationMatrix(gravity, geomagnetic, (err: BusinessError, data: sensor.RotationMatrixResponse) => {
    if (err) {
      console.error(`Failed to get rotationMatrix. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting rotationMatrix' + JSON.stringify(data));
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get rotationMatrix. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getRotationMatrix<sup>9+</sup> 

getRotationMatrix(gravity: Array&lt;number&gt;, geomagnetic: Array&lt;number&gt;): Promise&lt;RotationMatrixResponse&gt;

Obtains the rotation matrix based on a gravity vector and geomagnetic vector. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type               | Mandatory| Description          |
| ----------- | ------------------- | ---- | -------------- |
| gravity     | Array&lt;number&gt; | Yes  | Gravity vector.|
| geomagnetic | Array&lt;number&gt; | Yes  | Geomagnetic vector.|

**Return value**

| Type                                                        | Description          |
| ------------------------------------------------------------ | -------------- |
| Promise&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | Promise used to return the rotation matrix.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let gravity = [-0.27775216, 0.5351276, 9.788099];
  let geomagnetic = [210.87253, -78.6096, -111.44444];
  const promise = sensor.getRotationMatrix(gravity, geomagnetic);
  promise.then((data: sensor.RotationMatrixResponse) => {
    console.info('Succeeded in getting rotationMatrix' + JSON.stringify(data));
  }, (err: BusinessError) => {
    console.error(`Failed to get rotationMatrix. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get rotationMatrix. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getSensorList<sup>9+</sup>

getSensorList(callback: AsyncCallback&lt;Array&lt;Sensor&gt;&gt;): void

Obtains information about all sensors on the device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                          | Mandatory| Description            |
| -------- | ---------------------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;Array&lt;[Sensor](#sensor9)&gt;&gt; | Yes  | Callback used to return the sensor list.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.getSensorList((err: BusinessError, data: Array<sensor.Sensor>) => {
    if (err) {
      console.error(`Failed to get sensorList. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    for (let i = 0; i < data.length; i++) {
      console.info('Succeeded in getting data[' + i + ']: ' + JSON.stringify(data[i]));
    }
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get sensorList. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getSensorList<sup>9+</sup>

 getSensorList(): Promise&lt;Array&lt;Sensor&gt;&gt;

Obtains information about all sensors on the device. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Return value**

| Name | Type                                    | Mandatory| Description            |
| ------- | ---------------------------------------- | ---- | ---------------- |
| promise | Promise&lt;Array&lt;[Sensor](#sensor9)&gt;&gt; | Yes  | Promise used to return the sensor list.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.getSensorList().then((data: Array<sensor.Sensor>) => {
    for (let i = 0; i < data.length; i++) {
      console.info('Succeeded in getting data[' + i + ']: ' + JSON.stringify(data[i]));
    }
  }, (err: BusinessError) => {
    console.error(`Failed to get sensorList. Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get sensorList. Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getSensorListSync<sup>12+</sup>

getSensorListSync(): Array&lt;Sensor&gt;

Obtains information about all sensors on the device. This API returns the result synchronously.

**System capability**: SystemCapability.Sensors.Sensor

**Return value**

| Type                                   | Mandatory| Description                            |
| --------------------------------------- | ---- | -------------------------------- |
| &lt;Array&lt;[Sensor](#sensor9)&gt;&gt; | Yes  | List of sensor attributes.|

**Error codes**

For details about the following error codes, see [Sensor Error Codes](errorcode-sensor.md).

| ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let ret = sensor.getSensorListSync()
  for (let i = 0; i < ret.length; i++) {
    console.info('Succeeded in getting sensor: ' + JSON.stringify(ret[i]));
  }
} catch(error) {
    let e: BusinessError = error as BusinessError;
    console.error(`Failed to get singleSensor . Code: ${e.code}, message: ${e.message}`);
}
```

##  sensor.getSingleSensor<sup>9+</sup>

getSingleSensor(type: SensorId, callback: AsyncCallback&lt;Sensor&gt;): void

Obtains information about the sensor of a specific type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                   | Mandatory| Description            |
| -------- | --------------------------------------- | ---- | ---------------- |
| type     | [SensorId](#sensorid9)                  | Yes  | Sensor type.    |
| callback | AsyncCallback&lt;[Sensor](#sensor9)&gt; | Yes  | Callback used to return the sensor information.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |
| 14500102 | The sensor is not supported by the device.                   |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.getSingleSensor(sensor.SensorId.ACCELEROMETER, (err: BusinessError, data: sensor.Sensor) => {
    if (err) {
      console.error(`Failed to get singleSensor. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in getting sensor: ' + JSON.stringify(data));
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get singleSensor. Code: ${e.code}, message: ${e.message}`);
}
```

##  sensor.getSingleSensor<sup>9+</sup>

 getSingleSensor(type: SensorId): Promise&lt;Sensor&gt;

Obtains information about the sensor of a specific type. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name| Type                  | Mandatory| Description        |
| ------ | ---------------------- | ---- | ------------ |
| type   | [SensorId](#sensorid9) | Yes  | Sensor type.|

**Return value**

| Name | Type                             | Mandatory| Description                        |
| ------- | --------------------------------- | ---- | ---------------------------- |
| promise | Promise&lt;[Sensor](#sensor9)&gt; | Yes  | Promise used to return the sensor information.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |
| 14500102 | The sensor is not supported by the device.                   |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  sensor.getSingleSensor(sensor.SensorId.ACCELEROMETER).then((data: sensor.Sensor) => {
    console.info('Succeeded in getting sensor: ' + JSON.stringify(data));
  }, (err: BusinessError) => {
    console.error(`Failed to get singleSensor . Code: ${err.code}, message: ${err.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get singleSensor . Code: ${e.code}, message: ${e.message}`);
}
```

## sensor.getSingleSensorSync<sup>12+</sup>

getSingleSensorSync(type: SensorId): Sensor

Obtains information about the sensor of a specific type. This API returns the result synchronously.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name| Type                  | Mandatory| Description        |
| ------ | ---------------------- | ---- | ------------ |
| type   | [SensorId](#sensorid9) | Yes  | Sensor type.|

**Return value**

| Type  | Mandatory| Description                        |
| ------ | ---- | ---------------------------- |
| Sensor | Yes  | Sensor information.|

**Error codes**

For details about the error codes, see [Sensor Error Codes](errorcode-sensor.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14500101 | Service exception.                                           |
| 14500102 | The sensor is not supported by the device.                   |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let ret = sensor.getSingleSensorSync(sensor.SensorId.ACCELEROMETER);
  console.info('Succeeded in getting sensor: ' + JSON.stringify(ret));
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Failed to get singleSensor . Code: ${e.code}, message: ${e.message}`);
}
```

## SensorId<sup>9+</sup>

Enumerates the sensor types.

**System capability**: SystemCapability.Sensors.Sensor

| Name                       | Value  | Description                                                        |
| --------------------------- | ---- | ------------------------------------------------------------ |
| ACCELEROMETER               | 1    | Acceleration sensor.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GYROSCOPE                   | 2    | Gyroscope sensor.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AMBIENT_LIGHT               | 5    | Ambient light sensor.                                              |
| MAGNETIC_FIELD              | 6    | Magnetic field sensor.                                                |
| BAROMETER                   | 8    | Barometer sensor.                                              |
| HALL                        | 10   | Hall effect sensor.                                                |
| PROXIMITY                   | 12   | Proximity sensor.                                              |
| HUMIDITY                    | 13   | Humidity sensor.                                                |
| ORIENTATION                 | 256  | Orientation sensor.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| GRAVITY                     | 257  | Gravity sensor.                                                |
| LINEAR_ACCELEROMETER        | 258  | Linear acceleration sensor.                                          |
| ROTATION_VECTOR             | 259  | Rotation vector sensor.                                            |
| AMBIENT_TEMPERATURE         | 260  | Ambient temperature sensor.                                            |
| MAGNETIC_FIELD_UNCALIBRATED | 261  | Uncalibrated magnetic field sensor.                                          |
| GYROSCOPE_UNCALIBRATED      | 263  | Uncalibrated gyroscope sensor.                                        |
| SIGNIFICANT_MOTION          | 264  | Significant motion sensor.                                            |
| PEDOMETER_DETECTION         | 265  | Pedometer detection sensor.                                            |
| PEDOMETER                   | 266  | Pedometer sensor.                                                |
| HEART_RATE                  | 278  | Heart rate sensor.                                                |
| WEAR_DETECTION              | 280  | Wear detection sensor.                                            |
| ACCELEROMETER_UNCALIBRATED  | 281  | Uncalibrated acceleration sensor.                                      |

## SensorType<sup>(deprecated)</sup>

Enumerates the sensor types.

**System capability**: SystemCapability.Sensors.Sensor


| Name                                      | Value  | Description                  |
| ------------------------------------------ | ---- | ---------------------- |
| SENSOR_TYPE_ID_ACCELEROMETER               | 1    | Acceleration sensor.        |
| SENSOR_TYPE_ID_GYROSCOPE                   | 2    | Gyroscope sensor.        |
| SENSOR_TYPE_ID_AMBIENT_LIGHT               | 5    | Ambient light sensor.        |
| SENSOR_TYPE_ID_MAGNETIC_FIELD              | 6    | Magnetic field sensor.          |
| SENSOR_TYPE_ID_BAROMETER                   | 8    | Barometer sensor.        |
| SENSOR_TYPE_ID_HALL                        | 10   | Hall effect sensor.          |
| SENSOR_TYPE_ID_PROXIMITY                   | 12   | Proximity sensor.        |
| SENSOR_TYPE_ID_HUMIDITY                    | 13   | Humidity sensor.          |
| SENSOR_TYPE_ID_ORIENTATION                 | 256  | Orientation sensor.          |
| SENSOR_TYPE_ID_GRAVITY                     | 257  | Gravity sensor.          |
| SENSOR_TYPE_ID_LINEAR_ACCELERATION         | 258  | Linear acceleration sensor.    |
| SENSOR_TYPE_ID_ROTATION_VECTOR             | 259  | Rotation vector sensor.      |
| SENSOR_TYPE_ID_AMBIENT_TEMPERATURE         | 260  | Ambient temperature sensor.      |
| SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | 261  | Uncalibrated magnetic field sensor.    |
| SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED      | 263  | Uncalibrated gyroscope sensor.  |
| SENSOR_TYPE_ID_SIGNIFICANT_MOTION          | 264  | Significant motion sensor.      |
| SENSOR_TYPE_ID_PEDOMETER_DETECTION         | 265  | Pedometer detection sensor.      |
| SENSOR_TYPE_ID_PEDOMETER                   | 266  | Pedometer sensor.          |
| SENSOR_TYPE_ID_HEART_RATE                  | 278  | Heart rate sensor.          |
| SENSOR_TYPE_ID_WEAR_DETECTION              | 280  | Wear detection sensor.      |
| SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED  | 281  | Uncalibrated acceleration sensor.|

## SensorAccuracy<sup>11+</sup>

Enumerates the accuracy levels of sensor data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

| Name   | Value| Description                    |
| --------- | ---- | ------------------------ |
| ACCURACY_UNRELIABLE | 0   | The sensor data is unreliable.|
| ACCURACY_LOW | 1   | The sensor data is at a low accuracy level.|
| ACCURACY_MEDIUM | 2   | The sensor data is at a medium accuracy level.|
| ACCURACY_HIGH | 3   | The sensor data is at a high accuracy level.|

## Response

Describes the timestamp of the sensor data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

| Name     | Type  | Readable| Writable| Description                    |
| --------- | ------ | ---- | ---- | ------------------------ |
| timestamp | number | Yes  | Yes  | Timestamp when the sensor reports data.|
| accuracy<sup>11+</sup> | [SensorAccuracy](#sensoraccuracy11)<sup>11+</sup> | Yes  | No  | Accuracy of the sensor data.|

## Sensor<sup>9+</sup>

Describes the sensor information.

**System capability**: SystemCapability.Sensors.Sensor

| Name           | Type| Readable| Writable| Description                  |
| --------------- | -------- | ---------------------- | ---------------------- | ---------------------- |
| sensorName      | string   | Yes | No | Sensor name.           |
| vendorName      | string   | Yes | No | Vendor of the sensor.        |
| firmwareVersion | string   | Yes | No | Firmware version of the sensor.      |
| hardwareVersion | string   | Yes | No | Hardware version of the sensor.      |
| sensorId        | number   | Yes | No | Sensor type ID.        |
| maxRange        | number   | Yes | No | Maximum measurement range of the sensor.|
| minSamplePeriod | number   | Yes | No | Minimum sampling period.  |
| maxSamplePeriod | number   | Yes | No | Maximum sampling period.  |
| precision       | number   | Yes | No | Precision of the sensor.          |
| power           | number   | Yes | No | Estimated sensor power, in mA. |

## AccelerometerResponse

Describes the acceleration sensor data. It extends from [Response](#response).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type  | Readable| Writable| Description                                |
| ---- | ------ | ---- | ---- | ------------------------------------ |
| x    | number | Yes  | Yes  | Acceleration along the x-axis of the device, in m/s².|
| y    | number | Yes  | Yes  | Acceleration along the y-axis of the device, in m/s².|
| z    | number | Yes  | Yes  | Acceleration along the z-axis of the device, in m/s².|


## LinearAccelerometerResponse

Describes the linear acceleration sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type  | Readable| Writable| Description                                    |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| x    | number | Yes  | Yes  | Linear acceleration along the x-axis of the device, in m/s².|
| y    | number | Yes  | Yes  | Linear acceleration along the y-axis of the device, in m/s².|
| z    | number | Yes  | Yes  | Linear acceleration along the z-axis of the device, in m/s².|


## AccelerometerUncalibratedResponse

Describes the uncalibrated acceleration sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name | Type  | Readable| Writable| Description                                          |
| ----- | ------ | ---- | ---- | ---------------------------------------------- |
| x     | number | Yes  | Yes  | Uncalibrated acceleration along the x-axis of the device, in m/s².    |
| y     | number | Yes  | Yes  | Uncalibrated acceleration along the y-axis of the device, in m/s².    |
| z     | number | Yes  | Yes  | Uncalibrated acceleration along the z-axis of the device, in m/s².    |
| biasX | number | Yes  | Yes  | Uncalibrated acceleration bias along the x-axis of the device, in m/s².|
| biasY | number | Yes  | Yes  | Uncalibrated acceleration bias along the y-axis of the device, in m/s².|
| biasZ | number | Yes  | Yes  | Uncalibrated acceleration bias along the z-axis of the device, in m/s².|


## GravityResponse

Describes the gravity sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type  | Readable| Writable| Description                                    |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| x    | number | Yes  | Yes  | Gravitational acceleration along the x-axis of the device, in m/s².|
| y    | number | Yes  | Yes  | Gravitational acceleration along the y-axis of the device, in m/s².|
| z    | number | Yes  | Yes  | Gravitational acceleration along the z-axis of the device, in m/s².|


## OrientationResponse

Describes the orientation sensor data. It extends from [Response](#response).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor


| Name | Type  | Readable| Writable| Description                             |
| ----- | ------ | ---- | ---- | --------------------------------- |
| alpha | number | Yes  | Yes  | Rotation angle of the device around the z-axis, in degrees.|
| beta  | number | Yes  | Yes  | Rotation angle of the device around the x-axis, in degrees.|
| gamma | number | Yes  | Yes  | Rotation angle of the device around the y-axis, in degrees.|


## RotationVectorResponse

Describes the rotation vector sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type  | Readable| Writable| Description             |
| ---- | ------ | ---- | ---- | ----------------- |
| x    | number | Yes  | Yes  | X-component of the rotation vector.|
| y    | number | Yes  | Yes  | Y-component of the rotation vector.|
| z    | number | Yes  | Yes  | Z-component of the rotation vector.|
| w    | number | Yes  | Yes  | Scalar.           |


## GyroscopeResponse

Describes the gyroscope sensor data. It extends from [Response](#response).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type  | Readable| Writable| Description                            |
| ---- | ------ | ---- | ---- | -------------------------------- |
| x    | number | Yes  | Yes  | Angular velocity of rotation around the x-axis of the device, in rad/s.|
| y    | number | Yes  | Yes  | Angular velocity of rotation around the y-axis of the device, in rad/s.|
| z    | number | Yes  | Yes  | Angular velocity of rotation around the z-axis of the device, in rad/s.|


## GyroscopeUncalibratedResponse

Describes the uncalibrated gyroscope sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name | Type  | Readable| Writable| Description                                      |
| ----- | ------ | ---- | ---- | ------------------------------------------ |
| x     | number | Yes  | Yes  | Uncalibrated angular velocity of rotation around the x-axis of the device, in rad/s.    |
| y     | number | Yes  | Yes  | Uncalibrated angular velocity of rotation around the y-axis of the device, in rad/s.    |
| z     | number | Yes  | Yes  | Uncalibrated angular velocity of rotation around the z-axis of the device, in rad/s.    |
| biasX | number | Yes  | Yes  | Uncalibrated angular velocity bias of rotation around the x-axis of the device, in rad/s.|
| biasY | number | Yes  | Yes  | Uncalibrated angular velocity bias of rotation around the y-axis of the device, in rad/s.|
| biasZ | number | Yes  | Yes  | Uncalibrated angular velocity bias of rotation around the z-axis of the device, in rad/s.|


## SignificantMotionResponse

Describes the significant motion sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name  | Type  | Readable| Writable| Description                                                        |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| scalar | number | Yes  | Yes  | Intensity of a motion. This parameter specifies whether a device has a significant motion on three physical axes (X, Y, and Z). The value **1** is reported when the device has a significant motion.|


## ProximityResponse

Describes the proximity sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name    | Type  | Readable| Writable| Description                                                      |
| -------- | ------ | ---- | ---- | ---------------------------------------------------------- |
| distance | number | Yes  | Yes  | Proximity between the visible object and the device monitor. The value **0** means the two are close to each other, and a value greater than 0 means that they are far away from each other.|


## LightResponse

Describes the ambient light sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name                           | Type  | Readable| Writable| Description                                                        |
| ------------------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| intensity                       | number | Yes  | Yes  | Illumination, in lux.                                      |
| colorTemperature<sup>12+</sup>  | number | Yes  | Yes  | Color temperature, in Kelvin. This parameter is optional. If this parameter is not supported, **undefined** is returned. If this parameter is supported, a normal value is returned.|
| infraredLuminance<sup>12+</sup> | number | Yes  | Yes  | IR luminance, in cd/m2. This parameter is optional. If this parameter is not supported, **undefined** is returned. If this parameter is supported, a normal value is returned.|


## HallResponse

Describes the Hall effect sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name  | Type  | Readable| Writable| Description                                                        |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| status | number | Yes  | Yes  | Hall effect sensor status. This parameter specifies whether a magnetic field exists around a device. The value **0** means that a magnetic field does not exist, and a value greater than **0** means the opposite.|


## MagneticFieldResponse

Describes the magnetic field sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type  | Readable| Writable| Description                        |
| ---- | ------ | ---- | ---- | ---------------------------- |
| x    | number | Yes  | Yes  | Magnetic field strength on the x-axis, in μT.|
| y    | number | Yes  | Yes  | Magnetic field strength on the y-axis, in μT.|
| z    | number | Yes  | Yes  | Magnetic field strength on the z-axis, in μT.|


## MagneticFieldUncalibratedResponse

Describes the uncalibrated magnetic field sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name | Type  | Readable| Writable| Description                                  |
| ----- | ------ | ---- | ---- | -------------------------------------- |
| x     | number | Yes  | Yes  | Uncalibrated magnetic field strength on the x-axis, in μT.    |
| y     | number | Yes  | Yes  | Uncalibrated magnetic field strength on the y-axis, in μT.    |
| z     | number | Yes  | Yes  | Uncalibrated magnetic field strength on the z-axis, in μT.    |
| biasX | number | Yes  | Yes  | Bias of the uncalibrated magnetic field strength on the x-axis, in μT.|
| biasY | number | Yes  | Yes  | Bias of the uncalibrated magnetic field strength on the y-axis, in μT.|
| biasZ | number | Yes  | Yes  | Bias of the uncalibrated magnetic field strength on the z-axis, in μT.|


## PedometerResponse

Describes the pedometer sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name | Type  | Readable| Writable| Description            |
| ----- | ------ | ---- | ---- | ---------------- |
| steps | number | Yes  | Yes  | Number of steps a user has walked.|


## HumidityResponse

Describes the humidity sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name    | Type  | Readable| Writable| Description                                                     |
| -------- | ------ | ---- | ---- | --------------------------------------------------------- |
| humidity | number | Yes  | Yes  | Ambient relative humidity, in a percentage (%).|


## PedometerDetectionResponse

Describes the pedometer detection sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name  | Type  | Readable| Writable| Description                                                        |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| scalar | number | Yes  | Yes  | Pedometer detection. This parameter specifies whether a user takes a step. The value **0** means that the user does not take a step, and **1** means that the user takes a step.|


## AmbientTemperatureResponse

Describes the ambient temperature sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name       | Type  | Readable| Writable| Description                      |
| ----------- | ------ | ---- | ---- | -------------------------- |
| temperature | number | Yes  | Yes  | Ambient temperature, in degree Celsius.|


## BarometerResponse

Describes the barometer sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name    | Type  | Readable| Writable| Description                  |
| -------- | ------ | ---- | ---- | ---------------------- |
| pressure | number | Yes  | Yes  | Atmospheric pressure, in units of hPa.|


## HeartRateResponse

Describes the heart rate sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name     | Type  | Readable| Writable| Description                                   |
| --------- | ------ | ---- | ---- | --------------------------------------- |
| heartRate | number | Yes  | Yes  | Heart rate, in beats per minute (bpm).|


## WearDetectionResponse

Describes the wear detection sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name | Type  | Readable| Writable| Description                                            |
| ----- | ------ | ---- | ---- | ------------------------------------------------ |
| value | number | Yes  | Yes  | Whether the device is being worn. The value **1** means that the device is being worn, and **0** means the opposite.|


## Options

Describes the sensor data reporting frequency.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

| Name    | Type                                                       | Readable| Writable| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| interval | number\|[SensorFrequency](#sensorfrequency11)<sup>11+</sup> | Yes  | Yes  | Frequency at which a sensor reports data. The default value is 200,000,000 ns. The maximum and minimum values of this parameter are determined by the reporting frequency supported by the hardware. If the configured frequency is greater than the maximum value, the maximum value is used for data reporting. If the configured frequency is less than the minimum value, the minimum value is used for data reporting.|

## SensorFrequency<sup>11+</sup>

type SensorFrequency = 'game' | 'ui' | 'normal'

Defines the reporting frequency mode of the sensor.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.Sensor

| Type    | Description                                                        |
| -------- | ------------------------------------------------------------ |
| 'game'   | Game mode, which specifies a sensor data reporting frequency of 20,000,000 ns. This parameter takes effect only when the frequency is within the frequency range supported by the hardware.|
| 'ui'     | UI mode, which specifies a sensor data reporting frequency of 60,000,000 ns. This parameter takes effect only when the frequency is within the frequency range supported by the hardware.|
| 'normal' | Normal mode, which specifies a sensor data reporting frequency of 200,000,000 ns. This parameter takes effect only when the frequency is within the frequency range supported by the hardware.|

## RotationMatrixResponse

Describes the response for setting the rotation matrix.

**System capability**: SystemCapability.Sensors.Sensor

| Name       | Type               | Readable| Writable| Description      |
| ----------- | ------------------- | ---- | ---- | ---------- |
| rotation    | Array&lt;number&gt; | Yes  | Yes  | Rotation matrix.|
| inclination | Array&lt;number&gt; | Yes  | Yes  | Inclination matrix.|


## CoordinatesOptions

Describes the coordinate options.

**System capability**: SystemCapability.Sensors.Sensor

| Name| Type  | Readable| Writable| Description       |
| ---- | ------ | ---- | ---- | ----------- |
| x    | number | Yes  | Yes  | X coordinate direction.|
| y    | number | Yes  | Yes  | Y coordinate direction.|


## GeomagneticResponse

Describes a geomagnetic response object.

**System capability**: SystemCapability.Sensors.Sensor

| Name           | Type  | Readable| Writable| Description                                              |
| --------------- | ------ | ---- | ---- | -------------------------------------------------- |
| x               | number | Yes  | Yes  | North component of the geomagnetic field.                                  |
| y               | number | Yes  | Yes  | East component of the geomagnetic field.                                  |
| z               | number | Yes  | Yes  | Vertical component of the geomagnetic field.                                |
| geomagneticDip  | number | Yes  | Yes  | Magnetic dip, also called magnetic inclination, which is the angle measured from the horizontal plane to the magnetic field vector.            |
| deflectionAngle | number | Yes  | Yes  | Magnetic declination, which is the angle between true north (geographic north) and the magnetic north (the horizontal component of the field).|
| levelIntensity  | number | Yes  | Yes  | Horizontal intensity of the magnetic field vector field.                                |
| totalIntensity  | number | Yes  | Yes  | Total intensity of the magnetic field vector.                                  |

## LocationOptions

Describes the geographical location.

**System capability**: SystemCapability.Sensors.Sensor

| Name     | Type  | Readable| Writable| Description      |
| --------- | ------ | ---- | ---- | ---------- |
| latitude  | number | Yes  | Yes  | Latitude.    |
| longitude | number | Yes  | Yes  | Longitude.    |
| altitude  | number | Yes  | Yes  | Altitude.|

## sensor.on<sup>(deprecated)</sup>

### ACCELEROMETER<sup>(deprecated)</sup>

on(type:  SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback&lt;AccelerometerResponse&gt;,options?: Options): void

Subscribes to data changes of the acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.ACCELEROMETER](#accelerometer9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ACCELEROMETER | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER**.    |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes  | Callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, (data: sensor.AccelerometerResponse) => {
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
},
  { interval: 100000000 }
);
```

### LINEAR_ACCELERATION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:Callback&lt;LinearAccelerometerResponse&gt;, options?: Options): void

Subscribes to data changes of the linear acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.LINEAR_ACCELEROMETER](#linear_accelerometer9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_LINEAR_ACCELERATION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**.|
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes  | Callback used to return the linear acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

### ACCELEROMETER_UNCALIBRATED<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback: Callback&lt;AccelerometerUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.ACCELEROMETER_UNCALIBRATED](#accelerometer_uncalibrated9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**.|
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes  | Callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, (data: sensor.AccelerometerUncalibratedResponse) => {
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking on. X-coordinate bias: ' + data.biasX);
  console.info('Succeeded in invoking on. Y-coordinate bias: ' + data.biasY);
  console.info('Succeeded in invoking on. Z-coordinate bias: ' + data.biasZ);
},
  { interval: 100000000 }
);

```

### GRAVITY<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback&lt;GravityResponse&gt;,options?: Options): void

Subscribes to data changes of the gravity sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.GRAVITY](#gravity9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                       |
| -------- | ---------------------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_GRAVITY | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GRAVITY**.           |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt;        | Yes  | Callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**.|
| options  | [Options](#options)                                        | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, (data: sensor.GravityResponse) => {
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
},
  { interval: 100000000 }
);
```

### GYROSCOPE<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback&lt;GyroscopeResponse&gt;, options?: Options): void

Subscribes to data changes of the gyroscope sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.GYROSCOPE](#gyroscope9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_GYROSCOPE | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE**.        |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt;      | Yes  | Callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, (data: sensor.GyroscopeResponse) => {
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
},
  { interval: 100000000 }
);
```

### GYROSCOPE_UNCALIBRATED<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback:Callback&lt;GyroscopeUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated gyroscope sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.GYROSCOPE_UNCALIBRATED](#gyroscope_uncalibrated9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**.|
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes  | Callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, (data: sensor.GyroscopeUncalibratedResponse) => {
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking on. X-coordinate bias: ' + data.biasX);
  console.info('Succeeded in invoking on. Y-coordinate bias: ' + data.biasY);
  console.info('Succeeded in invoking on. Z-coordinate bias: ' + data.biasZ);
},
  { interval: 100000000 }
);
```

### SIGNIFICANT_MOTION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: Callback&lt;SignificantMotionResponse&gt;, options?: Options): void

Subscribes to data changes of the significant motion sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.SIGNIFICANT_MOTION](#significant_motion9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_SIGNIFICANT_MOTION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**.|
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes  | Callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, (data: sensor.SignificantMotionResponse) => {
  console.info('Succeeded in invoking on. Scalar data: ' + data.scalar);
},
  { interval: 100000000 }
);
```

### PEDOMETER_DETECTION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback&lt;PedometerDetectionResponse&gt;, options?: Options): void

Subscribes to data changes of the pedometer detection sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.PEDOMETER_DETECTION](#pedometer_detection9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_PEDOMETER_DETECTION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**.|
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | Yes  | Callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectionResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, (data: sensor.PedometerDetectionResponse) => {
  console.info('Succeeded in invoking on. Scalar data: ' + data.scalar);
},
  { interval: 100000000 }
);
```

### PEDOMETER<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback&lt;PedometerResponse&gt;, options?: Options): void

Subscribes to data changes of the pedometer sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.PEDOMETER](#pedometer9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_PEDOMETER | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER**.          |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt;      | Yes  | Callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, (data: sensor.PedometerResponse) => {
  console.info('Succeeded in invoking on. Steps: ' + data.steps);
},
  { interval: 100000000 }
);
```

### AMBIENT_TEMPERATURE<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:Callback&lt;AmbientTemperatureResponse&gt;,  options?: Options): void

Subscribes to data changes of the ambient temperature sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.AMBIENT_TEMPERATURE](#ambient_temperature9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**.|
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes  | Callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, (data: sensor.AmbientTemperatureResponse) => {
  console.info('Succeeded in invoking on. Temperature: ' + data.temperature);
},
  { interval: 100000000 }
);
```

### MAGNETIC_FIELD<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;,options?: Options): void

Subscribes to data changes of the magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.MAGNETIC_FIELD](#magnetic_field9)<sup>9+</sup> instead. 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_MAGNETIC_FIELD | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**.     |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes  | Callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, (data: sensor.MagneticFieldResponse) => {
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
},
  { interval: 100000000 }
);
```

### MAGNETIC_FIELD_UNCALIBRATED<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback: Callback&lt;MagneticFieldUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.MAGNETIC_FIELD_UNCALIBRATED](#magnetic_field_uncalibrated9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**.|
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes  | Callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, (data: sensor.MagneticFieldUncalibratedResponse) => {
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking on. X-coordinate bias: ' + data.biasX);
  console.info('Succeeded in invoking on. Y-coordinate bias: ' + data.biasY);
  console.info('Succeeded in invoking on. Z-coordinate bias: ' + data.biasZ);
},
  { interval: 100000000 }
);
```

### PROXIMITY<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback&lt;ProximityResponse&gt;,options?: Options): void

Subscribes to data changes of the proximity sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.PROXIMITY](#proximity9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_PROXIMITY | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PROXIMITY**.        |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt;      | Yes  | Callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. The default value is 200,000,000 ns. This parameter is used to set the data reporting frequency when proximity sensor events are frequently triggered.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, (data: sensor.ProximityResponse) => {
  console.info('Succeeded in invoking on. Distance: ' + data.distance);
},
  { interval: 100000000 }
);
```

### HUMIDITY<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback&lt;HumidityResponse&gt;,options?: Options): void

Subscribes to data changes of the humidity sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.HUMIDITY](#humidity9)<sup>9+</sup> instead. 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_HUMIDITY | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HUMIDITY**.           |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt;       | Yes  | Callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**.|
| options  | [Options](#options)                                         | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, (data: sensor.HumidityResponse) => {
  console.info('Succeeded in invoking on. Humidity: ' + data.humidity);
},
  { interval: 100000000 }
);
```

### BAROMETER<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback&lt;BarometerResponse&gt;,options?: Options): void

Subscribes to data changes of the barometer sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.BAROMETER](#barometer9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_BAROMETER | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_BAROMETER**.        |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt;      | Yes  | Callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, (data: sensor.BarometerResponse) => {
  console.info('Succeeded in invoking on. Atmospheric pressure: ' + data.pressure);
},
  { interval: 100000000 }
);
```

### HALL<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback&lt;HallResponse&gt;, options?: Options): void

Subscribes to data changes of the Hall effect sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.HALL](#hall9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_HALL | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HALL**.               |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt;           | Yes  | Callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**.|
| options  | [Options](#options)                                     | No  | List of optional parameters. The default value is 200,000,000 ns. This parameter is used to set the data reporting frequency when Hall effect events are frequently triggered.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HALL, (data: sensor.HallResponse) => {
  console.info('Succeeded in invoking on. Status: ' + data.status);
},
  { interval: 100000000 }
);
```

### AMBIENT_LIGHT<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;, options?: Options): void

Subscribes to data changes of the ambient light sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.AMBIENT_LIGHT](#ambient_light9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_AMBIENT_LIGHT | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**.   |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt;              | Yes  | Callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, (data: sensor.LightResponse) => {
  console.info('Succeeded in invoking on. Illumination: ' + data.intensity);
},
  { interval: 100000000 }
);
```

### ORIENTATION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback&lt;OrientationResponse&gt;, options?: Options): void

Subscribes to data changes of the orientation sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.ORIENTATION](#orientation9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ORIENTATION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ORIENTATION**.        |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt;  | Yes  | Callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, (data: sensor.OrientationResponse) => {
  console.info('Succeeded in the device rotating at an angle around the X axis: ' + data.beta);
  console.info('Succeeded in the device rotating at an angle around the Y axis: ' + data.gamma);
  console.info('Succeeded in the device rotating at an angle around the Z axis: ' + data.alpha);
},
  { interval: 100000000 }
);
```

### HEART_RATE<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback&lt;HeartRateResponse&gt;, options?: Options): void

Subscribes to data changes of the heart rate sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.HEART_RATE](#heart_rate9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_HEART_RATE | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HEART_RATE**.         |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt;      | Yes  | Callback used to return the heart rate sensor data. The reported data type in the callback is **HeartRateResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

### ROTATION_VECTOR<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,callback: Callback&lt;RotationVectorResponse&gt;,options?: Options): void

Subscribes to data changes of the rotation vector sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.ROTATION_VECTOR](#rotation_vector9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ROTATION_VECTOR | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**.|
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes  | Callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, (data: sensor.RotationVectorResponse) => {
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking on. Scalar quantity: ' + data.w);
},
  { interval: 100000000 }
);
```

### WEAR_DETECTION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback&lt;WearDetectionResponse&gt;,options?: Options): void

Subscribes to data changes of the wear detection sensor. If this API is called multiple times for the same application, the last call takes effect.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.on.WEAR_DETECTION](#wear_detection9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_WEAR_DETECTION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_WEAR_DETECTION**. |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes  | Callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**.|
| options  | [Options](#options)                                          | No  | List of optional parameters. This parameter is used to set the data reporting frequency. The default value is 200,000,000 ns. |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.on(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, (data: sensor.WearDetectionResponse) => {
  console.info('Succeeded in invoking on. Wear status: ' + data.value);
},
  { interval: 100000000 }
);
```

## sensor.once<sup>(deprecated)</sup>

### ACCELEROMETER<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback&lt;AccelerometerResponse&gt;): void

Subscribes to only one data change of the acceleration sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.ACCELEROMETER](#accelerometer9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ACCELEROMETER | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER**.            |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes  | One-shot callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, (data: sensor.AccelerometerResponse) => {
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
});
```

### LINEAR_ACCELERATION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:Callback&lt;LinearAccelerometerResponse&gt;): void

Subscribes to only one data change of the linear acceleration sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.LINEAR_ACCELEROMETER](#linear_accelerometer9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACCELERATION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_LINEAR_ACCELERATION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**.  |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes  | One-shot callback used to return the linear acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**.|

### ACCELEROMETER_UNCALIBRATED<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback: Callback&lt;AccelerometerUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated acceleration sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.ACCELEROMETER_UNCALIBRATED](#accelerometer_uncalibrated9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**.|
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes  | One-shot callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, (data: sensor.AccelerometerUncalibratedResponse) => {
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking once. X-coordinate bias: ' + data.biasX);
  console.info('Succeeded in invoking once. Y-coordinate bias: ' + data.biasY);
  console.info('Succeeded in invoking once. Z-coordinate bias: ' + data.biasZ);
});
```

### GRAVITY<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback&lt;GravityResponse&gt;): void

Subscribes to only one data change of the gravity sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.GRAVITY](#gravity9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_GRAVITY | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GRAVITY**.                    |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt;        | Yes  | One-shot callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, (data: sensor.GravityResponse) => {
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
  });
```

### GYROSCOPE<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback&lt;GyroscopeResponse&gt;): void

Subscribes to only one data change of the gyroscope sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.GYROSCOPE](#gyroscope9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_GYROSCOPE | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE**.                |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt;      | Yes  | One-shot callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, (data: sensor.GyroscopeResponse) => {
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
});
```

### GYROSCOPE_UNCALIBRATED<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback: Callback&lt;GyroscopeUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated gyroscope sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.GYROSCOPE_UNCALIBRATED](#gyroscope_uncalibrated9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**.|
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes  | One-shot callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**.|

**Example**


```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, (data: sensor.GyroscopeUncalibratedResponse) => {
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
    console.info('Succeeded in invoking once. X-coordinate bias: ' + data.biasX);
    console.info('Succeeded in invoking once. Y-coordinate bias: ' + data.biasY);
    console.info('Succeeded in invoking once. Z-coordinate bias: ' + data.biasZ);
});
```

### SIGNIFICANT_MOTION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION,callback: Callback&lt;SignificantMotionResponse&gt;): void

Subscribes to only one data change of the significant motion sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.SIGNIFICANT_MOTION](#significant_motion9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_SIGNIFICANT_MOTION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**.     |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes  | One-shot callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, (data: sensor.SignificantMotionResponse) => {
  console.info('Succeeded in invoking once. Scalar data: ' + data.scalar);
});
```

### PEDOMETER_DETECTION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,callback: Callback&lt;PedometerDetectionResponse&gt;): void

Subscribes to only one data change of the pedometer detection sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.PEDOMETER_DETECTION](#pedometer_detection9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_PEDOMETER_DETECTION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**.    |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | Yes  | One-shot callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectionResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, (data: sensor.PedometerDetectionResponse) => {
  console.info('Succeeded in invoking once. Scalar data: ' + data.scalar);
});
```

### PEDOMETER<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback&lt;PedometerResponse&gt;): void

Subscribes to only one data change of the pedometer sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.PEDOMETER](#pedometer9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_PEDOMETER | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER**.                  |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt;      | Yes  | One-shot callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, (data: sensor.PedometerResponse) => {
  console.info('Succeeded in invoking once. Steps: ' + data.steps);
});
```

### AMBIENT_TEMPERATURE<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback: Callback&lt;AmbientTemperatureResponse&gt;): void

Subscribes to only one data change of the ambient temperature sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.AMBIENT_TEMPERATURE](#ambient_temperature9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**.    |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes  | One-shot callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, (data: sensor.AmbientTemperatureResponse) => {
  console.info('Succeeded in invoking once. Temperature: ' + data.temperature);
});
```

### MAGNETIC_FIELD<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;): void

Subscribes to only one data change of the magnetic field sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.MAGNETIC_FIELD](#magnetic_field9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_MAGNETIC_FIELD | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**.             |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes  | One-shot callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, (data: sensor.MagneticFieldResponse) => {
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
});
```

### MAGNETIC_FIELD_UNCALIBRATED<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback: Callback&lt;MagneticFieldUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated magnetic field sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.MAGNETIC_FIELD_UNCALIBRATED](#magnetic_field_uncalibrated9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**.|
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes  | One-shot callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, (data: sensor.MagneticFieldUncalibratedResponse) => {
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking once. X-coordinate bias: ' + data.biasX);
  console.info('Succeeded in invoking once. Y-coordinate bias: ' + data.biasY);
  console.info('Succeeded in invoking once. Z-coordinate bias: ' + data.biasZ);
});
```

### PROXIMITY<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback&lt;ProximityResponse&gt;): void

Subscribes to only one data change of the proximity sensor.

> **NOTE** 
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.PROXIMITY](#proximity9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_PROXIMITY | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PROXIMITY**.                |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt;      | Yes  | One-shot callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, (data: sensor.ProximityResponse) => {
  console.info('Succeeded in invoking once. Distance: ' + data.distance);
}
);
```

### HUMIDITY<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback&lt;HumidityResponse&gt;): void

Subscribes to only one data change of the humidity sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.HUMIDITY](#humidity9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_HUMIDITY | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HUMIDITY**.                   |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt;       | Yes  | One-shot callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, (data: sensor.HumidityResponse) => {
  console.info('Succeeded in invoking once. Humidity: ' + data.humidity);
});
```

### BAROMETER<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback&lt;BarometerResponse&gt;): void

Subscribes to only one data change of the barometer sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.BAROMETER](#barometer9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_BAROMETER | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_BAROMETER**.                |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt;      | Yes  | One-shot callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, (data: sensor.BarometerResponse) => {
  console.info('Succeeded in invoking once. Atmospheric pressure: ' + data.pressure);
});
```

### HALL<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback&lt;HallResponse&gt;): void

Subscribes to only one data change of the Hall effect sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.HALL](#hall9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_HALL | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HALL**.                       |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt;           | Yes  | One-shot callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HALL, (data: sensor.HallResponse) => {
  console.info('Succeeded in invoking once. Status: ' + data.status);
});
```

### AMBIENT_LIGHT<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;): void

Subscribes to only one data change of the ambient light sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.AMBIENT_LIGHT](#ambient_light9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_AMBIENT_LIGHT | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**.            |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt;              | Yes  | One-shot callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, (data: sensor.LightResponse) => {
  console.info('Succeeded in invoking once. invoking once. Illumination: ' + data.intensity);
});
```

### ORIENTATION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback&lt;OrientationResponse&gt;): void

Subscribes to only one data change of the orientation sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.ORIENTATION](#orientation9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ORIENTATION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ORIENTATION**.                |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt;  | Yes  | One-shot callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, (data: sensor.OrientationResponse) => {
  console.info('Succeeded in invoking the device rotateing at an angle around the X axis: ' + data.beta);
  console.info('Succeeded in invoking the device rotateing at an angle around the Y axis: ' + data.gamma);
  console.info('Succeeded in invoking the device rotateing at an angle around the Z axis: ' + data.alpha);
});
```

### ROTATION_VECTOR<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: Callback&lt;RotationVectorResponse&gt;): void

Subscribes to only one data change of the rotation vector sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.ROTATION_VECTOR](#rotation_vector9-1)<sup>9+</sup> instead. 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ROTATION_VECTOR | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**.        |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes  | One-shot callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, (data: sensor.RotationVectorResponse) => {
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking once. Scalar quantity: ' + data.w);
});
```

### HEART_RATE<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback&lt;HeartRateResponse&gt;): void

Subscribes to only one data change of the heart rate sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.HEART_RATE](#heart_rate9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.HEART_RATE 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_HEART_RATE | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HEART_RATE**.                 |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt;      | Yes  | One-shot callback used to return the heart rate sensor data. The reported data type in the callback is **HeartRateResponse**.|

**Example**


```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, (data: sensor.HeartRateResponse) => {
  console.info("Succeeded in invoking once. Heart rate: " + data.heartRate);
});
```

### WEAR_DETECTION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback&lt;WearDetectionResponse&gt;): void

Subscribes to only one data change of the wear detection sensor.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.once.WEAR_DETECTION](#wear_detection9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_WEAR_DETECTION | Yes  | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_WEAR_DETECTION**.         |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes  | One-shot callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**.|

**Example**


```ts
import { sensor } from '@kit.SensorServiceKit';

sensor.once(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, (data: sensor.WearDetectionResponse) => {
  console.info("Succeeded in invoking once. Wear status: " + data.value);
});
```

## sensor.off<sup>(deprecated)</sup>

### ACCELEROMETER<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback?: Callback&lt;AccelerometerResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.ACCELEROMETER<sup>9+</sup>](#accelerometer9-2) instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ACCELEROMETER | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ACCELEROMETER**.|
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.AccelerometerResponse) {
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback);
```

### ACCELEROMETER_UNCALIBRATED<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback?: Callback&lt;AccelerometerUncalibratedResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.ACCELEROMETER_UNCALIBRATED](#accelerometer_uncalibrated9-2)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**.|
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.AccelerometerUncalibratedResponse) {
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking off. X-coordinate bias: ' + data.biasX);
  console.info('Succeeded in invoking off. Y-coordinate bias: ' + data.biasY);
  console.info('Succeeded in invoking off. Z-coordinate bias: ' + data.biasZ);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback);
```

### AMBIENT_LIGHT<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback?: Callback&lt;LightResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.AMBIENT_LIGHT](#ambient_light9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_AMBIENT_LIGHT | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**.|
| callback | Callback&lt;[LightResponse](#lightresponse)&gt;              | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.LightResponse) {
  console.info('Succeeded in invoking off. Illumination: ' + data.intensity);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback);
```

### AMBIENT_TEMPERATURE<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback?: Callback&lt;AmbientTemperatureResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.AMBIENT_TEMPERATURE](#ambient_temperature9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**.|
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.AmbientTemperatureResponse) {
  console.info('Succeeded in invoking off. Temperature: ' + data.temperature);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback);
```

### BAROMETER<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback?: Callback&lt;BarometerResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.BAROMETER](#barometer9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_BAROMETER | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_BAROMETER**.    |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt;      | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.BarometerResponse) {
  console.info('Succeeded in invoking off. Atmospheric pressure: ' + data.pressure);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, callback);
```

### GRAVITY<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback?: Callback&lt;GravityResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.GRAVITY](#gravity9-2)<sup>9+</sup> instead. 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_GRAVITY | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_GRAVITY**.        |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt;        | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.GravityResponse) {
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, callback);
```

### GYROSCOPE<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback?: Callback&lt;GyroscopeResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.GYROSCOPE](#gyroscope9-2)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_GYROSCOPE | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_GYROSCOPE**.    |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt;      | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.GyroscopeResponse) {
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback);
```

### GYROSCOPE_UNCALIBRATED<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback?: Callback&lt;GyroscopeUncalibratedResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.GYROSCOPE_UNCALIBRATED](#gyroscope_uncalibrated9-2)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**.|
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.GyroscopeUncalibratedResponse) {
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback);
```

### HALL<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_HALL, callback?: Callback&lt;HallResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.HALL](#hall9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_HALL | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_HALL**.           |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt;           | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.HallResponse) {
  console.info('Succeeded in invoking off. Status: ' + data.status);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HALL, callback);
```

### HEART_RATE<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback?: Callback&lt;HeartRateResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.HEART_RATE](#heart_rate9-2)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_HEART_RATE | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_HEART_RATE**.     |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt;      | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.HeartRateResponse) {
  console.info('Succeeded in invoking off. Humidity: ' + data.heartRate);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, callback);
```

### HUMIDITY<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback?: Callback&lt;HumidityResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.HUMIDITY](#humidity9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_HUMIDITY | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_HUMIDITY**.       |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt;       | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.HumidityResponse) {
  console.info('Succeeded in invoking off. Humidity: ' + data.humidity);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, callback);
```

### LINEAR_ACCELERATION<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback?: Callback&lt;LinearAccelerometerResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.LINEAR_ACCELEROMETER](#linear_accelerometer9-2)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_LINEAR_ACCELERATION | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**.|
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.LinearAccelerometerResponse) {
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback);
```

### MAGNETIC_FIELD<sup>(deprecated)</sup>

 off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback?: Callback&lt;MagneticFieldResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.MAGNETIC_FIELD](#magnetic_field9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_MAGNETIC_FIELD | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**. |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.MagneticFieldResponse) {
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback);
```

### MAGNETIC_FIELD_UNCALIBRATED<sup>(deprecated)</sup>

 off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback?: Callback&lt;MagneticFieldUncalibratedResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.MAGNETIC_FIELD_UNCALIBRATED](#magnetic_field_uncalibrated9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**.|
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.MagneticFieldUncalibratedResponse) {
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking off. X-coordinate bias: ' + data.biasX);
  console.info('Succeeded in invoking off. Y-coordinate bias: ' + data.biasY);
  console.info('Succeeded in invoking off. Z-coordinate bias: ' + data.biasZ);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback);
```

### ORIENTATION<sup>(deprecated)</sup>

 off(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback?: Callback&lt;OrientationResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.ORIENTATION](#orientation9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ORIENTATION | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ORIENTATION**.    |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt;  | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.OrientationResponse) {
  console.info('Succeeded in invoking off. The device rotates at an angle around the X axis: ' + data.beta);
  console.info('Succeeded in invoking off. The device rotates at an angle around the Y axis: ' + data.gamma);
  console.info('Succeeded in invoking off. The device rotates at an angle around the Z axis: ' + data.alpha);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, callback);
```

### PEDOMETER<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback?: Callback&lt;PedometerResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.PEDOMETER](#pedometer9-2)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_PEDOMETER | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_PEDOMETER**.      |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt;      | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.PedometerResponse) {
  console.info('Succeeded in invoking off. Steps: ' + data.steps);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, callback);
```

### PEDOMETER_DETECTION<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback?: Callback&lt;PedometerDetectionResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.PEDOMETER_DETECTION](#pedometer_detection9-2)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_PEDOMETER_DETECTION | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**.|
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.PedometerDetectionResponse) {
  console.info('Succeeded in invoking off. Scalar data: ' + data.scalar);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback);
```

### PROXIMITY<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback?: Callback&lt;ProximityResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.PROXIMITY](#proximity9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_PROXIMITY | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_PROXIMITY**.    |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt;      | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.ProximityResponse) {
  console.info('Succeeded in invoking off. Distance: ' + data.distance);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, callback);
```

### ROTATION_VECTOR<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback?: Callback&lt;RotationVectorResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.ROTATION_VECTOR](#rotation_vector9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_ROTATION_VECTOR | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**.|
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.RotationVectorResponse) {
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);
  console.info('Succeeded in invoking off. Scalar quantity: ' + data.w);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback);
```

### SIGNIFICANT_MOTION<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback?: Callback&lt;SignificantMotionResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.SIGNIFICANT_MOTION](#significant_motion9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_SIGNIFICANT_MOTION | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**.|
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function callback(data: sensor.SignificantMotionResponse) {
  console.info('Succeeded in invoking off. Scalar data: ' + data.scalar);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback);
```

### WEAR_DETECTION<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback?: Callback&lt;WearDetectionResponse&gt;): void

Unsubscribes from sensor data changes.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.off.WEAR_DETECTION](#wear_detection9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortypedeprecated).SENSOR_TYPE_ID_WEAR_DETECTION | Yes  | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_WEAR_DETECTION**.|
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';

function accCallback(data: sensor.WearDetectionResponse) {
  console.info('Succeeded in invoking off. Wear status: ' + data.value);
}

sensor.off(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, accCallback);
```

## sensor.transformCoordinateSystem<sup>(deprecated)</sup>

transformCoordinateSystem(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Rotates a rotation vector so that it can represent the coordinate system in different ways. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.transformRotationMatrix](#sensortransformrotationmatrix9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name          | Type                                     | Mandatory| Description                      |
| ---------------- | ----------------------------------------- | ---- | -------------------------- |
| inRotationVector | Array&lt;number&gt;                       | Yes  | Rotation vector to rotate.            |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes  | Direction of the coordinate system.          |
| callback         | AsyncCallback&lt;Array&lt;number&gt;&gt;  | Yes  | Callback used to return the rotation vector after being rotated.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

sensor.transformCoordinateSystem([1, 0, 0, 0, 1, 0, 0, 0, 1], { x: 2, y: 3 }, 
                                 (err: BusinessError, data: Array<number>) => {
  if (err) {
    console.error(`Failed to operate. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info("Succeeded in starting Operation. Data obtained: " + data);
  for (let i = 0; i < data.length; i++) {
    console.info("Succeeded in getting transformCoordinateSystem data[ " + i + "] = " + data[i]);
  }
})
```
## sensor.transformCoordinateSystem<sup>(deprecated)</sup>

transformCoordinateSystem(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions): Promise&lt;Array&lt;number&gt;&gt;

Rotates a rotation vector so that it can represent the coordinate system in different ways. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.transformRotationMatrix](#sensortransformrotationmatrix9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name             | Type                                      | Mandatory  | Description      |
| ---------------- | ---------------------------------------- | ---- | -------- |
| inRotationVector | Array&lt;number&gt;                      | Yes   | Rotation vector to rotate. |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes   | Direction of the coordinate system.|

**Return value**

| Type                              | Description                              |
| ---------------------------------- | ---------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation vector after being rotated.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

const promise = sensor.transformCoordinateSystem([1, 0, 0, 0, 1, 0, 0, 0, 1], { x: 2, y: 3 });
promise.then((data: Array<number>) => {
  console.info("Succeeded in starting Operation");
  for (let i = 0; i < data.length; i++) {
    console.info("Succeeded in getting transformCoordinateSystem data[ " + i + "] = " + data[i]);
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to operate.`);
})
```

## sensor.getGeomagneticField<sup>(deprecated)</sup>

getGeomagneticField(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback&lt;GeomagneticResponse&gt;): void

Obtains the geomagnetic field of a geographic location. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getGeomagneticInfo](#sensorgetgeomagneticinfo9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name         | Type                                                        | Mandatory| Description                              |
| --------------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| locationOptions | [LocationOptions](#locationoptions)                          | Yes  | Geographic location.                        |
| timeMillis      | number                                                       | Yes  | Time for obtaining the magnetic declination, in milliseconds.|
| callback        | AsyncCallback&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Yes  | Callback used to return the geomagnetic field.                |

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

sensor.getGeomagneticField({ latitude: 80, longitude: 0, altitude: 0 }, 1580486400000, 
                           (err: BusinessError, data: sensor.GeomagneticResponse) => {
  if (err) {
    console.error(`Failed to operate. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in getting sensor_getGeomagneticField_callback x: ' + data.x + ',y: ' + data.y + ',z: ' +
  data.z + ',geomagneticDip: ' + data.geomagneticDip + ',deflectionAngle: ' + data.deflectionAngle +
  ',levelIntensity: ' + data.levelIntensity + ',totalIntensity: ' + data.totalIntensity);
});
```
## sensor.getGeomagneticField<sup>(deprecated)</sup>

getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise&lt;GeomagneticResponse&gt;

Obtains the geomagnetic field of a geographic location. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getGeomagneticInfo](#sensorgetgeomagneticinfo9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name            | Type                                 | Mandatory  | Description               |
| --------------- | ----------------------------------- | ---- | ----------------- |
| locationOptions | [LocationOptions](#locationoptions) | Yes   | Geographic location.            |
| timeMillis      | number                              | Yes   | Time for obtaining the magnetic declination, in milliseconds.|

**Return value**
| Type                                                      | Description                      |
| ---------------------------------------------------------- | -------------------------- |
| Promise&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Promise used to return the geomagnetic field.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

const promise = sensor.getGeomagneticField({ latitude: 80, longitude: 0, altitude: 0 }, 1580486400000);
promise.then((data: sensor.GeomagneticResponse) => {
  console.info('Succeeded in getting sensor_getGeomagneticField_promise x: ' + data.x + ',y: ' + data.y + ',z: ' +
  data.z + ',geomagneticDip: ' + data.geomagneticDip + ',deflectionAngle: ' + data.deflectionAngle +
  ',levelIntensity: ' + data.levelIntensity + ',totalIntensity: ' + data.totalIntensity);
}).catch((reason: BusinessError) => {
  console.error(`Failed to operate.`);
})
```

## sensor.getAltitude<sup>(deprecated)</sup>

getAltitude(seaPressure: number, currentPressure: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the altitude at which the device is located based on the sea-level atmospheric pressure and the current atmospheric pressure. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getDeviceAltitude](#sensorgetdevicealtitude9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name         | Type                       | Mandatory| Description                                  |
| --------------- | --------------------------- | ---- | -------------------------------------- |
| seaPressure     | number                      | Yes  | Sea-level atmospheric pressure, in hPa.         |
| currentPressure | number                      | Yes  | Atmospheric pressure at the altitude where the device is located, in hPa. |
| callback        | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the altitude, in meters.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

sensor.getAltitude(0, 200, (err: BusinessError, data: number) => {
  if (err) {
    console.error(`Failed to operate. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info("Succeeded in getting getAltitude interface get data: " + data);
});
```

## sensor.getAltitude<sup>(deprecated)</sup>

getAltitude(seaPressure: number, currentPressure: number): Promise&lt;number&gt;

Obtains the altitude at which the device is located based on the sea-level atmospheric pressure and the current atmospheric pressure. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getDeviceAltitude](#sensorgetdevicealtitude9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name            | Type    | Mandatory  | Description                  |
| --------------- | ------ | ---- | -------------------- |
| seaPressure     | number | Yes   | Sea-level atmospheric pressure, in hPa.    |
| currentPressure | number | Yes   | Atmospheric pressure at the altitude where the device is located, in hPa.|

**Return value**

| Type                 | Description                                            |
| --------------------- | ------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the altitude, in meters.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

const promise = sensor.getAltitude(0, 200);
promise.then((data: number) => {
  console.info('Succeeded in getting sensor_getAltitude_Promise success', data);
}).catch((err: BusinessError) => {
  console.error(`Failed to operate.`);
})
```


## sensor.getGeomagneticDip<sup>(deprecated)</sup>

getGeomagneticDip(inclinationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;number&gt;): void

Obtains the magnetic dip based on the inclination matrix. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getInclination](#sensorgetinclination9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                       | Mandatory| Description                            |
| ----------------- | --------------------------- | ---- | -------------------------------- |
| inclinationMatrix | Array&lt;number&gt;         | Yes  | Inclination matrix.                  |
| callback          | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the magnetic dip, in radians.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

sensor.getGeomagneticDip([1, 0, 0, 0, 1, 0, 0, 0, 1], (err: BusinessError, data: number) => {
  if (err) {
    console.error(`Failed to register data. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info("Succeeded in getting getGeomagneticDip interface get data: " + data);
})
```

## sensor.getGeomagneticDip<sup>(deprecated)</sup>

getGeomagneticDip(inclinationMatrix: Array&lt;number&gt;): Promise&lt;number&gt;

Obtains the magnetic dip based on the inclination matrix. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getInclination](#sensorgetinclination9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name              | Type                 | Mandatory  | Description     |
| ----------------- | ------------------- | ---- | ------- |
| inclinationMatrix | Array&lt;number&gt; | Yes   | Inclination matrix.|

**Return value**

| Type                 | Description                                    |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the magnetic dip, in radians.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

const promise = sensor.getGeomagneticDip([1, 0, 0, 0, 1, 0, 0, 0, 1]);
promise.then((data: number) => {
  console.info('Succeeded in get GeomagneticDip_promise', data);
}).catch((err: BusinessError) => {
  console.error(`Failed to operate.`);
})
```

## sensor. getAngleModify<sup>(deprecated)</sup>

getAngleModify(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the angle change between two rotation matrices. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getAngleVariation](#sensorgetanglevariation9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name               | Type                                    | Mandatory| Description                                 |
| --------------------- | ---------------------------------------- | ---- | ------------------------------------- |
| currentRotationMatrix | Array&lt;number&gt;                      | Yes  | Current rotation matrix.                   |
| preRotationMatrix     | Array&lt;number&gt;                      | Yes  | Peer rotation matrix.                       |
| callback              | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the angle change around the z, x, and y axes.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

sensor.getAngleModify([1, 0, 0, 0, 1, 0, 0, 0, 1], [1, 0, 0, 0, 0.87, -0.50, 0, 0.50, 0.87],
                      (err: BusinessError, data: Array<number>) => {
  if (err) {
    console.error(`Failed to register data. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  for (let i = 0; i < data.length; i++) {
    console.info("data[" + i + "]: " + data[i]);
  }
})
```

## sensor. getAngleModify<sup>(deprecated)</sup>

getAngleModify(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Obtains the angle change between two rotation matrices. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getAngleVariation](#sensorgetanglevariation9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name                  | Type                 | Mandatory  | Description       |
| --------------------- | ------------------- | ---- | --------- |
| currentRotationMatrix | Array&lt;number&gt; | Yes   | Current rotation matrix.|
| preRotationMatrix     | Array&lt;number&gt; | Yes   | Peer rotation matrix.  |

**Return value**

| Type                              | Description                                         |
| ---------------------------------- | --------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the angle change around the z, x, and y axes.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

const promise = sensor.getAngleModify([1, 0, 0, 0, 1, 0, 0, 0, 1], [1, 0, 0, 0, 0.87, -0.50, 0, 0.50, 0.87]);
promise.then((data: Array<number>) => {
  console.info('Succeeded in getting AngleModify_promise.');
  for (let i = 0; i < data.length; i++) {
    console.info("Succeeded in getting data[" + i + "]: " + data[i]);
  }
}).catch((reason: BusinessError) => {
  let e: BusinessError = reason as BusinessError;
  console.info("Succeeded in getting promise::catch", e);
})
```

## sensor.createRotationMatrix<sup>(deprecated)</sup>

createRotationMatrix(rotationVector: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Converts a rotation vector into a rotation matrix. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getRotationMatrix](#sensorgetrotationmatrix9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                    | Mandatory| Description              |
| -------------- | ---------------------------------------- | ---- | ------------------ |
| rotationVector | Array&lt;number&gt;                      | Yes  | Rotation vector to convert.    |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the rotation matrix.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

sensor.createRotationMatrix([0.20046076, 0.21907, 0.73978853, 0.60376877],
                            (err: BusinessError, data: Array<number>) => {
  if (err) {
    console.error(`Failed to register data. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  for (let i = 0; i < data.length; i++) {
    console.info("Succeeded in getting data[" + i + "]: " + data[i]);
  }
})
```

## sensor.createRotationMatrix<sup>(deprecated)</sup>

createRotationMatrix(rotationVector: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Converts a rotation vector into a rotation matrix. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getRotationMatrix](#sensorgetrotationmatrix9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                 | Mandatory  | Description     |
| -------------- | ------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt; | Yes   | Rotation vector to convert.|

**Return value**

| Type                              | Description                      |
| ---------------------------------- | -------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation matrix.|

**Example**

 ```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

const promise = sensor.createRotationMatrix([0.20046076, 0.21907, 0.73978853, 0.60376877]);
promise.then((data: Array<number>) => {
  console.info('Succeeded in getting createRotationMatrix_promise');
  for (let i = 0; i < data.length; i++) {
    console.info("data[" + i + "]: " + data[i]);
  }
}).catch((reason: BusinessError) => {
  console.info("Succeeded in getting promise::catch", reason);
})
 ```

## sensor.createQuaternion<sup>(deprecated)</sup>

createQuaternion(rotationVector: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Converts a rotation vector into a quaternion. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getQuaternion](#sensorgetquaternion9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                    | Mandatory| Description            |
| -------------- | ---------------------------------------- | ---- | ---------------- |
| rotationVector | Array&lt;number&gt;                      | Yes  | Rotation vector to convert.  |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the quaternion.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

sensor.createQuaternion([0.20046076, 0.21907, 0.73978853, 0.60376877],
                        (err: BusinessError, data: Array<number>) => {
  if (err) {
    console.error(`Failed to register data. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  for (let i = 0; i < data.length; i++) {
    console.info("Succeeded in getting data[" + i + "]: " + data[i]);
  }
})
```

## sensor.createQuaternion<sup>(deprecated)</sup>

createQuaternion(rotationVector: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Converts a rotation vector into a quaternion. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getQuaternion](#sensorgetquaternion9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                 | Mandatory  | Description     |
| -------------- | ------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt; | Yes   | Rotation vector to convert.|

**Return value**

| Type                              | Description                    |
| ---------------------------------- | ------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the quaternion.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

const promise = sensor.createQuaternion([0.20046076, 0.21907, 0.73978853, 0.60376877]);
promise.then((data: Array<number>) => {
  console.info('Succeeded in getting createQuaternion_promise');
  for (let i = 0; i < data.length; i++) {
    console.info("data[" + i + "]: " + data[i]);
  }
}).catch((err: BusinessError) => {
  console.info(`Failed to get promise.`);
})
```

## sensor.getDirection<sup>(deprecated)</sup>

getDirection(rotationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the device direction based on the rotation matrix. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getOrientation](#sensorgetorientation9)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                    | Mandatory| Description                                 |
| -------------- | ---------------------------------------- | ---- | ------------------------------------- |
| rotationMatrix | Array&lt;number&gt;                      | Yes  | Peer rotation matrix.                       |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the rotation angle around the z, x, and y axes.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

sensor.getDirection([1, 0, 0, 0, 1, 0, 0, 0, 1], (err: BusinessError, data: Array<number>) => {
  if (err) {
    console.error(`Failed to register data. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info("Succeeded in getting getDirection interface get data: " + data);
  for (let i = 1; i < data.length; i++) {
    console.info("Succeeded in getting sensor_getDirection_callback" + data[i]);
  }
})
```

## sensor.getDirection<sup>(deprecated)</sup>

getDirection(rotationMatrix: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Obtains the device direction based on the rotation matrix. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getOrientation](#sensorgetorientation9-1)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                 | Mandatory  | Description     |
| -------------- | ------------------- | ---- | ------- |
| rotationMatrix | Array&lt;number&gt; | Yes   | Peer rotation matrix.|

**Return value**

| Type                              | Description                                         |
| ---------------------------------- | --------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation angle around the z, x, and y axes.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

const promise = sensor.getDirection([1, 0, 0, 0, 1, 0, 0, 0, 1]);
promise.then((data: Array<number>) => {
  console.info('Succeeded in getting sensor_getAltitude_Promise', data);
  for (let i = 1; i < data.length; i++) {
    console.info("Succeeded in getting sensor_getDirection_promise" + data[i]);
  }
}).catch((err: BusinessError) => {
  console.info(`Failed to get promise.`);
})
```

## sensor.createRotationMatrix<sup>(deprecated)</sup>

createRotationMatrix(gravity: Array&lt;number&gt;, geomagnetic: Array&lt;number&gt;, callback: AsyncCallback&lt;RotationMatrixResponse&gt;): void

Creates a rotation matrix based on the gravity vector and geomagnetic vector. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getRotationMatrix](#sensorgetrotationmatrix9-2)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                        | Mandatory| Description              |
| ----------- | ------------------------------------------------------------ | ---- | ------------------ |
| gravity     | Array&lt;number&gt;                                          | Yes  | Gravity vector.    |
| geomagnetic | Array&lt;number&gt;                                          | Yes  | Geomagnetic vector.    |
| callback    | AsyncCallback&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | Yes  | Callback used to return the rotation matrix.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

sensor.createRotationMatrix([-0.27775216, 0.5351276, 9.788099], [210.87253, -78.6096, -111.44444], 
                            (err: BusinessError, data: sensor.RotationMatrixResponse) => {
  if (err) {
    console.error(`Failed to get create rotationMatrix. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(JSON.stringify(data));
})
```

## sensor.createRotationMatrix<sup>(deprecated)</sup>

createRotationMatrix(gravity: Array&lt;number&gt;, geomagnetic: Array&lt;number&gt;): Promise&lt;RotationMatrixResponse&gt;

Creates a rotation matrix based on the gravity vector and geomagnetic vector. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [sensor.getRotationMatrix](#sensorgetrotationmatrix9-3)<sup>9+</sup> instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                 | Mandatory  | Description     |
| ----------- | ------------------- | ---- | ------- |
| gravity     | Array&lt;number&gt; | Yes   | Gravity vector.|
| geomagnetic | Array&lt;number&gt; | Yes   | Geomagnetic vector.|

**Return value**

| Type                                                        | Description                      |
| ------------------------------------------------------------ | -------------------------- |
| Promise&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | Promise used to return the rotation matrix.|

**Example**

```ts
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

const promise = sensor.createRotationMatrix([-0.27775216, 0.5351276, 9.788099], [210.87253, -78.6096, -111.44444]);
promise.then((data: sensor.RotationMatrixResponse) => {
  console.info(JSON.stringify(data));
}).catch((err: BusinessError) => {
  console.info(`Failed to get promise.`);
})
```
