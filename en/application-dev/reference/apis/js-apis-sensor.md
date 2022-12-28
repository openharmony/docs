# Sensor

The **Sensor** module provides APIs for obtaining the sensor list and subscribing to sensor data. It also provides some common sensor algorithms.

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import sensor from '@ohos.sensor';
```

## sensor.on<sup>9+</sup>

### ACCELEROMETER<sup>9+</sup>

on(type: SensorId.ACCELEROMETER, callback: Callback&lt;AccelerometerResponse&gt;,options?: Options): void

Subscribes to data of the acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).ACCELEROMETER                         | Yes  | Sensor type. The value is fixed at **SensorId.ACCELEROMETER**.             |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is an **AccelerometerResponse** object.|
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                        |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.ACCELEROMETER, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

### ACCELEROMETER_UNCALIBRATED<sup>9+</sup>

on(type: SensorId.ACCELEROMETER_UNCALIBRATED, callback: Callback&lt;AccelerometerUncalibratedResponse&gt;,options?: Options): void

Subscribes to data of the uncalibrated acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ACCELEROMETER_UNCALIBRATED            | Yes  | Sensor type. The value is fixed at **SensorId.ACCELEROMETER_UNCALIBRATED**. |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes  | Callback used to report the sensor data, which is an **AccelerometerUncalibratedResponse** object.|
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                         |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

### AMBIENT_LIGHT<sup>9+</sup>

on(type: SensorId.AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;, options?: Options): void

Subscribes to data of the ambient light sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                           | Mandatory| Description                                               |
| -------- | ----------------------------------------------- | ---- | --------------------------------------------------- |
| type     | [SensorId](#sensorid9).AMBIENT_LIGHT            | Yes  | Sensor type. The value is fixed at **SensorId.AMBIENT_LIGHT**.     |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **LightResponse** object.|
| options  | [Options](#options)                             | No  | Data reporting frequency. The default value is 200,000,000 ns.                |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.AMBIENT_LIGHT, function (data) {
        console.info('The ambient light intensity: ' + data.intensity);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

###  AMBIENT_TEMPERATURE<sup>9+</sup>

on(type: SensorId.AMBIENT_TEMPERATURE, callback: Callback&lt;AmbientTemperatureResponse&gt;,options?: Options): void

Subscribes to data of the ambient temperature sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).AMBIENT_TEMPERATURE                   | Yes  | Sensor type. The value is fixed at **SensorId.AMBIENT_TEMPERATURE**.        |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes  | Callback used to report the sensor data, which is an **AmbientTemperatureResponse** object.|
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                         |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.AMBIENT_TEMPERATURE, function (data) {
        console.info('Temperature: ' + data.temperature);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

### BAROMETER<sup>9+</sup>

on(type: SensorId.BAROMETER, callback: Callback&lt;BarometerResponse&gt;, options?: Options): void

Subscribes to data of the barometer sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).BAROMETER                        | Yes  | Sensor type. The value is fixed at **SensorId.BAROMETER**.             |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **BarometerResponse** object.|
| options  | [Options](#options)                                     | No  | Data reporting frequency. The default value is 200,000,000 ns.                    |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.BAROMETER, function (data) {
        console.info('Atmospheric pressure: ' + data.pressure);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

###  GRAVITY<sup>9+</sup>

on(type: SensorId.GRAVITY, callback: Callback&lt;GravityResponse&gt;,options?: Options): void

Subscribes to data of the gravity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                               | Mandatory| Description                                                 |
| -------- | --------------------------------------------------- | ---- | ----------------------------------------------------- |
| type     | [SensorId](#sensorid9).GRAVITY                      | Yes  | Sensor type. The value is fixed at **SensorId.GRAVITY**.             |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **GravityResponse** object.|
| options  | [Options](#options)                                 | No  | Data reporting frequency. The default value is 200,000,000 ns.                  |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.GRAVITY, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

###  GYROSCOPE<sup>9+</sup>

on(type: SensorId.GYROSCOPE, callback: Callback&lt;GyroscopeResponse&gt;,options?: Options): void

Subscribes to data of the gyroscope sensor.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).GYROSCOPE                        | Yes  | Sensor type. The value is fixed at **SensorId.GYROSCOPE**.             |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes  | Callback used to report the sensor data, which is a **GyroscopeResponse** object.|
| options  | [Options](#options)                                     | No  | Data reporting frequency. The default value is 200,000,000 ns.                    |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.GYROSCOPE, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                         |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.GYROSCOPE_UNCALIBRATED, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

###  HALL<sup>9+</sup>

on(type: SensorId.HALL, callback: Callback&lt;HallResponse&gt;, options?: Options): void

Subscribes to data of the Hall effect sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                         | Mandatory| Description                                              |
| -------- | --------------------------------------------- | ---- | -------------------------------------------------- |
| type     | [SensorId](#sensorid9).HALL                   | Yes  | Sensor type. The value is fixed at **SensorId.HALL**.             |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **HallResponse** object.|
| options  | [Options](#options)                           | No  | Data reporting frequency. The default value is 200,000,000 ns.               |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.HALL, function (data) {
        console.info('Hall status: ' + data.status);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

###   HEART_RATE<sup>9+</sup>

on(type: SensorId.HEART_RATE, callback: Callback&lt;HeartRateResponse&gt;,options?: Options): void

Subscribes to data of the heart rate sensor.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).HEART_RATE                       | Yes  | Sensor type. The value is fixed at **SensorId.HEART_RATE**.            |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **HeartRateResponse** object.|
| options  | [Options](#options)                                     | No  | Data reporting frequency. The default value is 200,000,000 ns.                    |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.HEART_RATE, function (data) {
        console.info('Heart rate: ' + data.heartRate);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

###  HUMIDITY<sup>9+</sup>

on(type: SensorId.HUMIDITY, callback: Callback&lt;HumidityResponse&gt;,options?: Options): void

Subscribes to data of the humidity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                  |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | [SensorId](#sensorid9).HUMIDITY                       | Yes  | Sensor type. The value is fixed at **SensorId.HUMIDITY**.             |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **HumidityResponse** object.|
| options  | [Options](#options)                                   | No  | Data reporting frequency. The default value is 200,000,000 ns.                   |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.HUMIDITY, function (data) {
        console.info('Humidity: ' + data.humidity);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                         |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.LINEAR_ACCELEROMETER, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

###  MAGNETIC_FIELD<sup>9+</sup>

on(type: SensorId.MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;,options?: Options): void

Subscribes to data of the magnetic field sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                       |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| type     | [SensorId](#sensorid9).MAGNETIC_FIELD                        | Yes  | Sensor type. The value is fixed at **SensorId.MAGNETIC_FIELD**.            |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **MagneticFieldResponse** object.|
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                        |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.MAGNETIC_FIELD, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                         |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

### ORIENTATION<sup>9+</sup>

on(type: SensorId.ORIENTATION, callback: Callback&lt;OrientationResponse&gt;,options?: Options): void

Subscribes to data of the orientation sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                     |
| -------- | ----------------------------------------------------------- | ---- | --------------------------------------------------------- |
| type     | [SensorId](#sensorid9).ORIENTATION                          | Yes  | Sensor type. The value is fixed at **SensorId.ORIENTATION**.             |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **OrientationResponse** object.|
| options  | [Options](#options)                                         | No  | Data reporting frequency. The default value is 200,000,000 ns.                      |

**Example**

```js
try {
    sensor.on(sensor.SensorId.ORIENTATION, function (data) {
        console.info('The device rotates at an angle around the Z axis: ' + data.alpha);
        console.info('The device rotates at an angle around the X axis: ' + data.beta);
        console.info('The device rotates at an angle around the Y axis: ' + data.gamma);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

### PEDOMETER<sup>9+</sup>

on(type: SensorId.PEDOMETER, callback: Callback&lt;PedometerResponse&gt;, options?: Options): void

Subscribes to data of the pedometer sensor.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).PEDOMETER                        | Yes  | Sensor type. The value is fixed at **SensorId.PEDOMETER**.             |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **PedometerResponse** object.|
| options  | [Options](#options)                                     | No  | Data reporting frequency. The default value is 200,000,000 ns.                    |

**Example**

```js
try {
    sensor.on(sensor.SensorId.PEDOMETER, function (data) {
        console.info('Step count: ' + data.steps);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                         |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.PEDOMETER_DETECTION, function (data) {
        console.info('Pedometer scalar: ' + data.scalar);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

### PROXIMITY<sup>9+</sup>

on(type: SensorId.PROXIMITY, callback: Callback&lt;ProximityResponse&gt;, options?: Options): void

Subscribes to data of the proximity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                   |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------- |
| type     | [SensorId](#sensorid9).PROXIMITY                        | Yes  | Sensor type. The value is fixed at **SensorId.PROXIMITY**.             |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes  | Callback used to report the sensor data, which is a **ProximityResponse** object.|
| options  | [Options](#options)                                     | No  | Data reporting frequency. The default value is 200,000,000 ns.                    |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.PROXIMITY, function (data) {
        console.info('Distance: ' + data.distance);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                         |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.ROTATION_VECTOR, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        console.info('Scalar quantity: ' + data.w);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                         |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.SIGNIFICANT_MOTION, function (data) {
        console.info('Scalar data: ' + data.scalar);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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
| options  | [Options](#options)                                          | No  | Data reporting frequency. The default value is 200,000,000 ns.                        |

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.on(sensor.SensorId.WEAR_DETECTION, function (data) {
        console.info('Wear status: ' + data.value);
    }, { interval: 10000000 });
} catch (err) {
    console.error('On fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.ACCELEROMETER, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.AMBIENT_LIGHT, function (data) {
        console.info('The ambient light intensity: ' + data.intensity);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.AMBIENT_TEMPERATURE, function (data) {
        console.info('Temperature: ' + data.temperature);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, function (data) {
        console.info('Atmospheric pressure: ' + data.pressure);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.GRAVITY, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.GYROSCOPE, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.GYROSCOPE_UNCALIBRATED, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.HALL, function (data) {
        console.info('Status: ' + data.status);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.HEART_RATE, function (data) {
        console.info('Heart rate: ' + data.heartRate);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.HUMIDITY, function (data) {
        console.info('Humidity: ' + data.humidity);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.LINEAR_ACCELEROMETER, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.MAGNETIC_FIELD, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        console.info('X-coordinate bias: ' + data.biasX);
        console.info('Y-coordinate bias: ' + data.biasY);
        console.info('Z-coordinate bias: ' + data.biasZ);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.ORIENTATION, function (data) {
        console.info('The device rotates at an angle around the X axis: ' + data.beta);
        console.info('The device rotates at an angle around the Y axis: ' + data.gamma);
        console.info('The device rotates at an angle around the Z axis: ' + data.alpha);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.PEDOMETER, function (data) {
        console.info('Step count: ' + data.steps);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.PEDOMETER_DETECTION, function (data) {
        console.info('Scalar data: ' + data.scalar);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.PROXIMITY, function (data) {
        console.info('Distance: ' + data.distance);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.ROTATION_VECTOR, function (data) {
        console.info('X-coordinate component: ' + data.x);
        console.info('Y-coordinate component: ' + data.y);
        console.info('Z-coordinate component: ' + data.z);
        console.info('Scalar quantity: ' + data.w);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.SIGNIFICANT_MOTION, function (data) {
        console.info('Scalar data: ' + data.scalar);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Error code**

For details about the following error codes, see [Sensor Error Codes](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.once(sensor.SensorId.WEAR_DETECTION, function (data) {
        console.info("Wear status: " + data.value);
    });
} catch (err) {
    console.error('Once fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

## sensor.off<sup>9+</sup>

### ACCELEROMETER<sup>9+</sup> 

off(type: SensorId.ACCELEROMETER, callback?: Callback&lt;AccelerometerResponse&gt;): void

Unsubscribes from data of the acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ACCELEROMETER                         | Yes  | Sensor type. The value is fixed at **SensorId.ACCELEROMETER**.              |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.ACCELEROMETER, callback1);
    sensor.on(sensor.SensorId.ACCELEROMETER, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.ACCELEROMETER, callback1);
    // Unsubscribe from all callbacks of the SensorId.ACCELEROMETER type.
    sensor.off(sensor.SensorId.ACCELEROMETER);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, callback1);
    sensor.on(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, callback1);
    // Unsubscribe from all callbacks of the SensorId.ACCELEROMETER_UNCALIBRATED type.
    sensor.off(sensor.SensorId.ACCELEROMETER_UNCALIBRATED);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.AMBIENT_LIGHT, callback1);
    sensor.on(sensor.SensorId.AMBIENT_LIGHT, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.AMBIENT_LIGHT, callback1);
    // Unsubscribe from all callbacks of the SensorId.AMBIENT_LIGHT type.
    sensor.off(sensor.SensorId.AMBIENT_LIGHT);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.AMBIENT_TEMPERATURE, callback1);
    sensor.on(sensor.SensorId.AMBIENT_TEMPERATURE, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.AMBIENT_TEMPERATURE, callback1);
    // Unsubscribe from all callbacks of the SensorId.AMBIENT_TEMPERATURE type.
    sensor.off(sensor.SensorId.AMBIENT_TEMPERATURE);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.BAROMETER, callback1);
    sensor.on(sensor.SensorId.BAROMETER, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.BAROMETER, callback1);
    // Unsubscribe from all callbacks of the SensorId.BAROMETER type.
    sensor.off(sensor.SensorId.BAROMETER);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.GRAVITY, callback1);
    sensor.on(sensor.SensorId.GRAVITY, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.GRAVITY, callback1);
    // Unsubscribe from all callbacks of the SensorId.GRAVITY type.
    sensor.off(sensor.SensorId.GRAVITY);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

### GYROSCOPE<sup>9+</sup> 

off(type: SensorId.GYROSCOPE, callback?: Callback&lt;GyroscopeResponse&gt;): void

Unsubscribes from data of the gyroscope sensor.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).GYROSCOPE                        | Yes  | Sensor type. The value is fixed at **SensorId.GYROSCOPE**.                  |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.GYROSCOPE, callback1);
    sensor.on(sensor.SensorId.GYROSCOPE, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.GYROSCOPE, callback1);
    // Unsubscribe from all callbacks of the SensorId.GYROSCOPE type.
    sensor.off(sensor.SensorId.GYROSCOPE);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.GYROSCOPE_UNCALIBRATED, callback1);
    sensor.on(sensor.SensorId.GYROSCOPE_UNCALIBRATED, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.GYROSCOPE_UNCALIBRATED, callback1);
    // Unsubscribe from all callbacks of the SensorId.GYROSCOPE_UNCALIBRATED type.
    sensor.off(sensor.SensorId.GYROSCOPE_UNCALIBRATED);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.HALL, callback1);
    sensor.on(sensor.SensorId.HALL, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.HALL, callback1);
    // Unsubscribe from all callbacks of the SensorId.HALL type.
    sensor.off(sensor.SensorId.HALL);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.HEART_RATE, callback1);
    sensor.on(sensor.SensorId.HEART_RATE, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.HEART_RATE, callback1);
    // Unsubscribe from all callbacks of the SensorId.HEART_RATE type.
    sensor.off(sensor.SensorId.HEART_RATE);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.HUMIDITY, callback1);
    sensor.on(sensor.SensorId.HUMIDITY, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.HUMIDITY, callback1);
    // Unsubscribe from all callbacks of the SensorId.HUMIDITY type.
    sensor.off(sensor.SensorId.HUMIDITY);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.LINEAR_ACCELEROMETER, callback1);
    sensor.on(sensor.SensorId.LINEAR_ACCELEROMETER, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.LINEAR_ACCELEROMETER, callback1);
    // Unsubscribe from all callbacks of the SensorId.LINEAR_ACCELEROMETER type.
    sensor.off(sensor.SensorId.LINEAR_ACCELEROMETER);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.MAGNETIC_FIELD, callback1);
    sensor.on(sensor.SensorId.MAGNETIC_FIELD, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.MAGNETIC_FIELD, callback1);
    // Unsubscribe from all callbacks of the SensorId.MAGNETIC_FIELD type.
    sensor.off(sensor.SensorId.MAGNETIC_FIELD);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback1);
    sensor.on(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback1);
    // Unsubscribe from all callbacks of the SensorId.MAGNETIC_FIELD_UNCALIBRATED type.
    sensor.off(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

### ORIENTATION<sup>9+</sup> 

off(type: SensorId.ORIENTATION, callback?: Callback&lt;OrientationResponse&gt;): void

Unsubscribes from data of the orientation sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | [SensorId](#sensorid9).ORIENTATION                          | Yes  | Sensor type. The value is fixed at **SensorId.ORIENTATION**.                |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | No  | Callback used for unsubscription. If this parameter is not specified, all callbacks of the specified sensor type are unsubscribed from.|

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.ORIENTATION, callback1);
    sensor.on(sensor.SensorId.ORIENTATION, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.ORIENTATION, callback1);
    // Unsubscribe from all callbacks of the SensorId.ORIENTATION type.
    sensor.off(sensor.SensorId.ORIENTATION);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.PEDOMETER, callback1);
    sensor.on(sensor.SensorId.PEDOMETER, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.PEDOMETER, callback1);
    // Unsubscribe from all callbacks of the SensorId.PEDOMETER type.
    sensor.off(sensor.SensorId.PEDOMETER);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.PEDOMETER_DETECTION, callback1);
    sensor.on(sensor.SensorId.PEDOMETER_DETECTION, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.PEDOMETER_DETECTION, callback1);
    // Unsubscribe from all callbacks of the SensorId.PEDOMETER_DETECTION type.
    sensor.off(sensor.SensorId.PEDOMETER_DETECTION);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.PROXIMITY, callback1);
    sensor.on(sensor.SensorId.PROXIMITY, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.PROXIMITY, callback1);
    // Unsubscribe from all callbacks of the SensorId.PROXIMITY type.
    sensor.off(sensor.SensorId.PROXIMITY);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.ROTATION_VECTOR, callback1);
    sensor.on(sensor.SensorId.ROTATION_VECTOR, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.ROTATION_VECTOR, callback1);
    // Unsubscribe from all callbacks of the SensorId.ROTATION_VECTOR type.
    sensor.off(sensor.SensorId.ROTATION_VECTOR);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.SIGNIFICANT_MOTION, callback1);
    sensor.on(sensor.SensorId.SIGNIFICANT_MOTION, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.SIGNIFICANT_MOTION, callback1);
    // Unsubscribe from all callbacks of the SensorId.SIGNIFICANT_MOTION type.
    sensor.off(sensor.SensorId.SIGNIFICANT_MOTION);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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

**Example**

```js
function callback1(data) {
    console.info('Callback1 data: ' + JSON.stringify(data));
}
function callback2(data) {
    console.info('Callback2 data: ' + JSON.stringify(data));
}
try {
    sensor.on(sensor.SensorId.WEAR_DETECTION, callback1);
    sensor.on(sensor.SensorId.WEAR_DETECTION, callback2);
    // Unsubscribe from callback1.
    sensor.off(sensor.SensorId.WEAR_DETECTION, callback1);
    // Unsubscribe from all callbacks of the SensorId.WEAR_DETECTION type.
    sensor.off(sensor.SensorId.WEAR_DETECTION);
} catch (err) {
    console.error('Off fail, errCode: ' + err.code + ' ,msg: ' + err.message);
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
| callback        | AsyncCallback&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Yes  | Callback used to return the geomagnetic field.                    |

**Error code**

For details about the following error codes, see [Error Codes of sensor.getGeomagneticInfo](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.getGeomagneticInfo({ latitude: 80, longitude: 0, altitude: 0 }, 1580486400000, function (err, data) {
        if (err) {
            console.error('Get geomagneticInfo failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        console.info("GeomagneticInfo x" + data.x);
        console.info("GeomagneticInfo y" + data.y);
        console.info("GeomagneticInfo z" + data.z);
        console.info("GeomagneticInfo geomagneticDip" + data.geomagneticDip);
        console.info("GeomagneticInfo deflectionAngle" + data.deflectionAngle);
        console.info("GeomagneticInfo levelIntensity" + data.levelIntensity);
        console.info("GeomagneticInfo totalIntensity" + data.totalIntensity);
    });
} catch (err) {
    console.error('Get geomagneticInfo failed. Error code: ' + err.code + '; message: ' + err.message);
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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getGeomagneticInfo](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    const promise = sensor.getGeomagneticInfo({ latitude: 80, longitude: 0, altitude: 0 }, 1580486400000);
    promise.then((data) => {
        console.info("GeomagneticInfo x" + data.x);
        console.info("GeomagneticInfo y" + data.y);
        console.info("GeomagneticInfo z" + data.z);
        console.info("GeomagneticInfo geomagneticDip" + data.geomagneticDip);
        console.info("GeomagneticInfo deflectionAngle" + data.deflectionAngle);
        console.info("GeomagneticInfo levelIntensity" + data.levelIntensity);
        console.info("GeomagneticInfo totalIntensity" + data.totalIntensity);
    }, (err)=>{
        console.error('Get geomagneticInfo failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Get geomagneticInfo. Error code: ' + err.code + '; message: ' + err.message);
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
| callback        | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the altitude, in meters.   |

**Error code**

For details about the following error codes, see [Error Codes of sensor.getDeviceAltitude](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let seaPressure = 1013.2;
    let currentPressure = 1500.0;
    sensor.getDeviceAltitude(seaPressure, currentPressure, function (err, data) {
        if (err) {
            console.error('Get altitude failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        console.info('altitude: ' + data);
    });
} catch (err) {
    console.error('Get altitude failed. Error code: ' + err.code + '; message: ' + err.message);
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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getDeviceAltitude](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let seaPressure = 1013.2;
    let currentPressure = 1500.0;
    const promise = sensor.getDeviceAltitude(seaPressure, currentPressure);
    promise.then((data) => {
        console.info('sensor_getDeviceAltitude_Promise success', data);
    }, (err) => {
        console.error('Get altitude failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Get altitude failed. Error code: ' + err.code + '; message: ' + err.message);
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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getInclination](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    // inclinationMatrix can be 3*3 or 4*4.
    let inclinationMatrix = [
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    ]
    sensor.getInclination(inclinationMatrix, function (err, data) {
        if (err) {
            console.error('Get inclination failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        console.info('Inclination: ' + data);
    })
} catch (err) {
    console.error('Get inclination failed. Error code: ' + err.code + '; message: ' + err.message);
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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getInclination](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    // inclinationMatrix can be 3*3 or 4*4.
    let inclinationMatrix = [
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    ]
    const promise = sensor.getInclination(inclinationMatrix);
    promise.then((data) => {
        console.info('Inclination: ' + data);
    }, (err) => {
        console.error('Get inclination failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Get inclination failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getAngleVariation<sup>9+</sup>

 getAngleVariation(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;,
        callback: AsyncCallback<Array&lt;number&gt;>): void

Obtains the angle change between two rotation matrices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name               | Type                                    | Mandatory| Description                             |
| --------------------- | ---------------------------------------- | ---- | --------------------------------- |
| currentRotationMatrix | Array&lt;number&gt;                      | Yes  | Current rotation matrix.               |
| preRotationMatrix     | Array&lt;number&gt;                      | Yes  | The other rotation matrix.                   |
| callback              | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the angle change around the z, x, and y axes.|

**Error code**

For details about the following error codes, see [Error Codes of sensor.getAngleVariation](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
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
    sensor.getAngleVariation(currentRotationMatrix, preRotationMatrix, function (err, data) {
        if (err) {
            console.error('Get angle variation failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        if (data.length < 3) {
            console.error("Get angle variation failed, length" + data.length);
        }
        console.info("Z: " + data[0]);
        console.info("X: " + data[1]);
        console.info("Y  : " + data[2]);
    })
} catch (err) {
    console.error('Get angle variation failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getAngleVariation<sup>9+</sup>

getAngleVariation(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;): Promise<Array&lt;number&gt;> 

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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getAngleVariation](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
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
    promise.then((data) => {
        if (data.length < 3) {
            console.error("Get angle variation failed, length" + data.length);
        }
        console.info("Z: " + data[0]);
        console.info("X: " + data[1]);
        console.info("Y  : " + data[2]);
    }, (err) => {
        console.error('Get angle variation failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Get angle variation failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getRotationMatrix<sup>9+</sup> 

getRotationMatrix(rotationVector: Array&lt;number&gt;, callback: AsyncCallback<Array&lt;number&gt;>): void

Obtains the rotation matrix from a rotation vector. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                    | Mandatory| Description          |
| -------------- | ---------------------------------------- | ---- | -------------- |
| rotationVector | Array&lt;number&gt;                      | Yes  | Rotation vector.|
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the rotation matrix.|

**Error code**

For details about the following error codes, see [Error Codes of sensor.getRotationMatrix](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];
    sensor.getRotationMatrix(rotationVector, function (err, data) {
        if (err) {
            console.error('Get rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        for (var i = 0; i < data.length; i++) {
            console.info('data[' + i + ']: ' + data[i]);
        }
    })
} catch (err) {
    console.error('Get rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getRotationMatrix<sup>9+</sup>

getRotationMatrix(rotationVector: Array&lt;number&gt;): Promise<Array<number&gt;> 

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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getRotationMatrix](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];
    const promise = sensor.getRotationMatrix(rotationVector);
    promise.then((data) => {
        for (var i = 0; i < data.length; i++) {
            console.info('data[' + i + ']: ' + data[i]);
        }
    }, (err) => {
        console.error('Get rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Get rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.transformRotationMatrix<sup>9+</sup> 

transformRotationMatrix(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions,
        callback: AsyncCallback<Array&lt;number&gt;>): void

Transforms a rotation vector based on the coordinate system. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name          | Type                                     | Mandatory| Description                  |
| ---------------- | ----------------------------------------- | ---- | ---------------------- |
| inRotationVector | Array&lt;number&gt;                       | Yes  | Rotation matrix.        |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes  | Rotation vector to transform.      |
| callback         | AsyncCallback&lt;Array&lt;number&gt;&gt;  | Yes  | Callback used to return the rotation vector after being transformed.|

**Error code**

For details about the following error codes, see [Error Codes of sensor.transformRotationMatrix](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let rotationMatrix = [
        1, 0, 0,
        0, 0.87, -0.50,
        0, 0.50, 0.87
    ];
    sensor.transformRotationMatrix(rotationMatrix, { x: 1, y: 3 }, function (err, data) {
        if (err) {
            console.error('Transform rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        for (var i = 0; i < data.length; i++) {
            console.info('data[' + i + '] = ' + data[i]);
        }
    })
} catch (err) {
    console.error('Transform rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.transformRotationMatrix<sup>9+</sup>

transformRotationMatrix(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions): Promise<Array&lt;number&gt;> 

Transforms a rotation vector based on the coordinate system. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name          | Type                                     | Mandatory| Description            |
| ---------------- | ----------------------------------------- | ---- | ---------------- |
| inRotationVector | Array&lt;number&gt;                       | Yes  | Rotation matrix.  |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes  | Rotation vector to transform.|

**Return value**

| Type                              | Description                  |
| ---------------------------------- | ---------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation vector after being transformed.|

**Error code**

For details about the following error codes, see [Error Codes of sensor.transformRotationMatrix](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let rotationMatrix = [
        1, 0, 0,
        0, 0.87, -0.50,
        0, 0.50, 0.87
    ];
    const promise = sensor.transformRotationMatrix(rotationMatrix, { x: 1, y: 3 });
    promise.then((data) => {
        for (var i = 0; i < data.length; i++) {
            console.info('data[' + i + ']: ' + data[i]);
        }
    }, (err) => {
        console.error('Transform rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Transform rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getQuaternion<sup>9+</sup> 

getQuaternion(rotationVector: Array&lt;number&gt;, callback: AsyncCallback<Array&lt;number&gt;>): void 

Obtains the quaternion from a rotation vector. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                    | Mandatory| Description          |
| -------------- | ---------------------------------------- | ---- | -------------- |
| rotationVector | Array&lt;number&gt;                      | Yes  | Rotation vector.|
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the quaternion.  |

**Error code**

For details about the following error codes, see [Error Codes of sensor.getQuaternion](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];
    sensor.getQuaternion(rotationVector, function (err, data) {
        if (err) {
            console.error('Get quaternion failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        for (var i = 0; i < data.length; i++) {
            console.info('data[' + i + ']: ' + data[i]);
        }
    })
} catch (err) {
    console.error('Get quaternion failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getQuaternion<sup>9+</sup>

getQuaternion(rotationVector: Array&lt;number&gt;): Promise<Array&lt;number&gt;> 

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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getQuaternion](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];
    const promise = sensor.getQuaternion(rotationVector);
    promise.then((data) => {
        for (var i = 0; i < data.length; i++) {
            console.info('data[' + i + ']: ' + data[i]);
        }
    }, (err) => {
        console.error('Get quaternion failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Get quaternion failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getOrientation<sup>9+</sup>

getOrientation(rotationMatrix: Array&lt;number&gt;, callback: AsyncCallback<Array&lt;number&gt;>): void 

Obtains the device direction based on the rotation matrix. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                    | Mandatory| Description                             |
| -------------- | ---------------------------------------- | ---- | --------------------------------- |
| rotationMatrix | Array&lt;number&gt;                      | Yes  | Rotation matrix.                   |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the rotation angle around the z, x, and y axes.|

**Error code**

For details about the following error codes, see [Error Codes of sensor.getOrientation](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let preRotationMatrix = [
        1, 0, 0,
        0, 0.87, -0.50,
        0, 0.50, 0.87
    ];
    sensor.getOrientation(preRotationMatrix, function (err, data) {
        if (err) {
            console.error('Get orientation failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        if (data.length < 3) {
            console.error("Get orientation failed, length" + data.length);
        }
        console.info("Z: " + data[0]);
        console.info("X: " + data[1]);
        console.info("Y  : " + data[2]);
    })
} catch (err) {
    console.error('Get orientation failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getOrientation<sup>9+</sup>

getOrientation(rotationMatrix: Array&lt;number&gt;): Promise<Array&lt;number&gt;> 

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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getOrientation](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let preRotationMatrix = [
        1, 0, 0,
        0, 0.87, -0.50,
        0, 0.50, 0.87
    ];
    const promise = sensor.getOrientation(preRotationMatrix);
    promise.then((data) => {
        for (var i = 0; i < data.length; i++) {
            console.info('data[' + i + ']: ' + data[i]);
        }
    }, (err) => {
        console.error('getOrientation failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('getOrientation failed. Error code: ' + err.code + '; message: ' + err.message);
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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getRotationMatrix](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let gravity = [-0.27775216, 0.5351276, 9.788099];
    let geomagnetic = [210.87253, -78.6096, -111.44444];
    sensor.getRotationMatrix(gravity, geomagnetic, function (err, data) => {
        if (err) {
            console.error('Get rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        console.info('RotationMatrix' + JSON.stringify(data));
    })
} catch (err) {
    console.error('Get rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getRotationMatrix<sup>9+</sup> 

getRotationMatrix(gravity: Array&lt;number&gt;, geomagnetic: Array&lt;number&gt;,): Promise&lt;RotationMatrixResponse&gt;

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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getRotationMatrix](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    let gravity = [-0.27775216, 0.5351276, 9.788099];
    let geomagnetic = [210.87253, -78.6096, -111.44444];
    const promise = sensor.getRotationMatrix(gravity, geomagnetic);
    promise.then((data) => {
        console.info('RotationMatrix' + JSON.stringify(data));
    }, (err) => {
        console.error('Get rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Get rotationMatrix failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getSensorList<sup>9+</sup>

getSensorList(callback: AsyncCallback<Array&lt;Sensor&gt;>): void

Obtains information about all sensors on the device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name  | Type                                          | Mandatory| Description            |
| -------- | ---------------------------------------------- | ---- | ---------------- |
| callback | AsyncCallback<Array&lt;[Sensor](#sensor9)&gt;> | Yes  | Callback used to return the sensor list.|

**Error code**

For details about the following error codes, see [Error Codes of sensor.getSensorList](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.getSensorList((err, data) => {
        if (err) {
            console.error('Get sensorList failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        for (var i = 0; i < data.length; i++) {
            console.info('data[' + i + ']: ' + JSON.stringify(data[i]));
        }
    });
} catch (err) {
    console.error('Get sensorList failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## sensor.getSensorList<sup>9+</sup>

 getSensorList(): Promise< Array&lt;Sensor&gt;>

Obtains information about all sensors on the device. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Return value**

| Name | Type                                    | Mandatory| Description            |
| ------- | ---------------------------------------- | ---- | ---------------- |
| promise | Promise<Array&lt;[Sensor](#sensor9)&gt;> | Yes  | Promise used to return the sensor list.|

**Error code**

For details about the following error codes, see [Error Codes of sensor.getSensorList](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.getSensorList().then((data) => {
        for (var i = 0; i < data.length; i++) {
            console.info('data[' + i + ']: ' + JSON.stringify(data[i]));
        }
    }, (err) => {
        console.error('Get sensorList failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Get sensorList failed. Error code: ' + err.code + '; message: ' + err.message);
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

**Error code**

For details about the following error codes, see [Error Codes of sensor.getSingleSensor](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.getSingleSensor(sensor.SensorId.ACCELEROMETER, (err, data) => {
        if (err) {
            console.error('Get singleSensor failed. Error code: ' + err.code + '; message: ' + err.message);
            return;
        }
        console.info('Sensor: ' + JSON.stringify(data));
    });
} catch (err) {
    console.error('Get singleSensor failed. Error code: ' + err.code + '; message: ' + err.message);
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

| Name | Type                             | Mandatory| Description            |
| ------- | --------------------------------- | ---- | ---------------- |
| promise | Promise&lt;[Sensor](#sensor9)&gt; | Yes  | Promise used to return the sensor information.|

**Error code**

For details about the following error codes, see [Error Codes of sensor.getSingleSensor](../errorcodes/errorcode-sensor.md).

| Error Code ID| Error Message          |
| -------- | ------------------ |
| 14500101 | Service exception. |

**Example**

```js
try {
    sensor.getSingleSensor(sensor.SensorId.ACCELEROMETER).then((data) => {
        console.info('Sensor: ' + JSON.stringify(data));
    }, (err) => {
        console.error('Get singleSensor failed. Error code: ' + err.code + '; message: ' + err.message);
    });
} catch (err) {
    console.error('Get singleSensor failed. Error code: ' + err.code + '; message: ' + err.message);
}
```

## SensorId<sup>9+</sup>

Enumerates the sensor types.

**System capability**: SystemCapability.Sensors.Sensor

| Name                       | Value  | Description                  |
| --------------------------- | ---- | ---------------------- |
| ACCELEROMETER               | 1    | Acceleration sensor.        |
| GYROSCOPE                   | 2    | Gyroscope sensor.        |
| AMBIENT_LIGHT               | 5    | Ambient light sensor.        |
| MAGNETIC_FIELD              | 6    | Magnetic field sensor.          |
| BAROMETER                   | 8    | Barometer sensor.        |
| HALL                        | 10   | Hall effect sensor.          |
| PROXIMITY                   | 12   | Proximity sensor.        |
| HUMIDITY                    | 13   | Humidity sensor.          |
| ORIENTATION                 | 256  | Orientation sensor.          |
| GRAVITY                     | 257  | Gravity sensor.          |
| LINEAR_ACCELEROMETER        | 258  | Linear acceleration sensor.    |
| ROTATION_VECTOR             | 259  | Rotation vector sensor.      |
| AMBIENT_TEMPERATURE         | 260  | Ambient temperature sensor.      |
| MAGNETIC_FIELD_UNCALIBRATED | 261  | Uncalibrated magnetic field sensor.    |
| GYROSCOPE_UNCALIBRATED      | 263  | Uncalibrated gyroscope sensor.  |
| SIGNIFICANT_MOTION          | 264  | Significant motion sensor.      |
| PEDOMETER_DETECTION         | 265  | Pedometer detection sensor.      |
| PEDOMETER                   | 266  | Pedometer sensor.          |
| HEART_RATE                  | 278  | Heart rate sensor.          |
| WEAR_DETECTION              | 280  | Wear detection sensor.      |
| ACCELEROMETER_UNCALIBRATED  | 281  | Uncalibrated acceleration sensor.|

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


## Response

Describes the timestamp of the sensor data.

**System capability**: SystemCapability.Sensors.Sensor

| Name     | Type  | Readable| Writable| Description                    |
| --------- | ------ | ---- | ---- | ------------------------ |
| timestamp | number | Yes  | Yes  | Timestamp when the sensor reports data.|

## Sensor<sup>9+</sup>

Describes the sensor information.

**System capability**: SystemCapability.Sensors.Sensor

| Name           | Type| Readable| Writable| Description                  |
| --------------- | -------- | ---------------------- | ---------------------- | ---------------------- |
| sensorName      | string   | Yes | Yes | Sensor name.          |
| venderName      | string   | Yes | Yes | Vendor of the sensor.        |
| firmwareVersion | string   | Yes | Yes | Firmware version of the sensor.      |
| hardwareVersion | string   | Yes | Yes | Hardware version of the sensor.      |
| sensorId        | number   | Yes | Yes | Sensor type ID.        |
| maxRange        | number   | Yes | Yes | Maximum measurement range of the sensor.|
| minSamplePeriod | number   | Yes | Yes | Minimum sampling period.  |
| maxSamplePeriod | number   | Yes | Yes | Maximum sampling period.  |
| precision       | number   | Yes | Yes | Precision of the sensor.          |
| power           | number   | Yes | Yes | Power of the sensor.          |

## AccelerometerResponse

Describes the acceleration sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type  | Readable| Writable| Description                                |
| ---- | ------ | ---- | ---- | ------------------------------------ |
| x    | number | Yes  | Yes  | Acceleration along the x-axis of the device, in m/s2.|
| y    | number | Yes  | Yes  | Acceleration along the y-axis of the device, in m/s2.|
| z    | number | Yes  | Yes  | Acceleration along the z-axis of the device, in m/s2.|


## LinearAccelerometerResponse

Describes the linear acceleration sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type  | Readable| Writable| Description                                    |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| x    | number | Yes  | Yes  | Linear acceleration along the x-axis of the device, in m/s2.|
| y    | number | Yes  | Yes  | Linear acceleration along the y-axis of the device, in m/s2.|
| z    | number | Yes  | Yes  | Linear acceleration along the z-axis of the device, in m/s2.|


## AccelerometerUncalibratedResponse

Describes the uncalibrated acceleration sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name | Type  | Readable| Writable| Description                                            |
| ----- | ------ | ---- | ---- | ------------------------------------------------ |
| x     | number | Yes  | Yes  | Uncalibrated acceleration along the x-axis of the device, in m/s2.      |
| y     | number | Yes  | Yes  | Uncalibrated acceleration along the y-axis of the device, in m/s2.      |
| z     | number | Yes  | Yes  | Uncalibrated acceleration along the z-axis of the device, in m/s2.      |
| biasX | number | Yes  | Yes  | Uncalibrated acceleration bias along the x-axis of the device, in m/s2.  |
| biasY | number | Yes  | Yes  | Uncalibrated acceleration bias along the y-axis of the device, in m/s2.|
| biasZ | number | Yes  | Yes  | Uncalibrated acceleration bias along the z-axis of the device, in m/s2.  |


## GravityResponse

Describes the gravity sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name| Type  | Readable| Writable| Description                                    |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| x    | number | Yes  | Yes  | Gravitational acceleration along the x-axis of the device, in m/s2.|
| y    | number | Yes  | Yes  | Gravitational acceleration along the y-axis of the device, in m/s2.|
| z    | number | Yes  | Yes  | Gravitational acceleration along the z-axis of the device, in m/s2.|


## OrientationResponse

Describes the orientation sensor data. It extends from [Response](#response).

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
| scalar | number | Yes  | Yes  | Intensity of a motion. This parameter specifies whether a device has a significant motion on three physical axes (X, Y, and Z). The value **0** means that the device does not have a significant motion, and **1** means the opposite.|


## ProximityResponse

Describes the proximity sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name    | Type  | Readable| Writable| Description                                                  |
| -------- | ------ | ---- | ---- | ------------------------------------------------------ |
| distance | number | Yes  | Yes  | Proximity between the visible object and the device monitor. The value **0** means the two are close to each other, and **1** means that they are far away from each other.|


## LightResponse

Describes the ambient light sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name     | Type  | Readable| Writable| Description                  |
| --------- | ------ | ---- | ---- | ---------------------- |
| intensity | number | Yes  | Yes  | Illumination, in lux.|


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


| Name    | Type  | Readable| Writable| Description                    |
| -------- | ------ | ---- | ---- | ------------------------ |
| pressure | number | Yes  | Yes  | Atmospheric pressure, in pascal.|


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

**System capability**: SystemCapability.Sensors.Sensor

| Name    | Type  | Readable| Writable| Description                                       |
| -------- | ------ | ---- | ---- | ------------------------------------------- |
| interval | number | Yes  | Yes  | Frequency at which a sensor reports data. The default value is 200,000,000 ns.|

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

Describes a geomagnetic response object. It extends from [Response](#response).

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

This API is deprecated since API version 9. You are advised to use [sensor.on.ACCELEROMETER](#accelerometer9) instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ACCELEROMETER       | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER**. |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes       | Callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```

### LINEAR_ACCELERATION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:Callback&lt;LinearAccelerometerResponse&gt;, options?: Options): void

Subscribes to data changes of the linear acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.LINEAR_ACCELEROMETER](#linear_accelerometer9) instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_LINEAR_ACCELERATION | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**. |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes       | Callback used to return the linear acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

### ACCELEROMETER_UNCALIBRATED<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback: Callback&lt;AccelerometerUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.ACCELEROMETER_UNCALIBRATED](#accelerometer_uncalibrated9) instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**. |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes       | Callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('X-coordinate bias: ' + data.biasX);
      console.info('Y-coordinate bias: ' + data.biasY);
      console.info('Z-coordinate bias: ' + data.biasZ);
  },
      {interval: 10000000}
  );
  ```

### GRAVITY<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback&lt;GravityResponse&gt;,options?: Options): void

Subscribes to data changes of the gravity sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.GRAVITY](#gravity9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                | Mandatory | Description                                                  |
| -------- | --------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_GRAVITY    | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GRAVITY**. |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | Yes       | Callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**. |
| options  | [Options](#options)                                 | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```

### GYROSCOPE<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback&lt;GyroscopeResponse&gt;, options?: Options): void

Subscribes to data changes of the gyroscope sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.GYROSCOPE](#gyroscope9) instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_GYROSCOPE      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE**. |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes       | Callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**. |
| options  | [Options](#options)                                     | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```

### GYROSCOPE_UNCALIBRATED<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback:Callback&lt;GyroscopeUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated gyroscope sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.GYROSCOPE_UNCALIBRATED](#gyroscope_uncalibrated9) instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**. |
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes       | Callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('X-coordinate bias: ' + data.biasX);
      console.info('Y-coordinate bias: ' + data.biasY);
      console.info('Z-coordinate bias: ' + data.biasZ);
  },
      {interval: 10000000}
  );
  ```

### SIGNIFICANT_MOTION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: Callback&lt;SignificantMotionResponse&gt;, options?: Options): void

Subscribes to data changes of the significant motion sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.SIGNIFICANT_MOTION](#significant_motion9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_SIGNIFICANT_MOTION  | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**. |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes       | Callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION,function(data){
      console.info('Scalar data: ' + data.scalar);
  },
      {interval: 10000000}
  );
  ```

### PEDOMETER_DETECTION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback&lt;PedometerDetectionResponse&gt;, options?: Options): void

Subscribes to data changes of the pedometer detection sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.PEDOMETER_DETECTION](#pedometer_detection9) instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_PEDOMETER_DETECTION | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**. |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | Yes       | Callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectionResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,function(data){
      console.info('Scalar data: ' + data.scalar);
  },
      {interval: 10000000}
  );
  ```

### PEDOMETER<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback&lt;PedometerResponse&gt;, options?: Options): void

Subscribes to data changes of the pedometer sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.PEDOMETER](#pedometer9) instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_PEDOMETER      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER**. |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes       | Callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**. |
| options  | [Options](#options)                                     | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER,function(data){
      console.info('Steps: ' + data.steps);
  },
      {interval: 10000000}
  );
  ```

### AMBIENT_TEMPERATURE<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:Callback&lt;AmbientTemperatureResponse&gt;,  options?: Options): void

Subscribes to data changes of the ambient temperature sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.AMBIENT_TEMPERATURE](#ambient_temperature9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**. |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes       | Callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,function(data){
      console.info('Temperature: ' + data.temperature);
  },
      {interval: 10000000}
  );

  ```

### MAGNETIC_FIELD<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;,options?: Options): void

Subscribes to data changes of the magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.MAGNETIC_FIELD](#magnetic_field9) instead. 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_MAGNETIC_FIELD      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**. |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes       | Callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );

  ```

### MAGNETIC_FIELD_UNCALIBRATED<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback: Callback&lt;MagneticFieldUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.MAGNETIC_FIELD_UNCALIBRATED](#magnetic_field_uncalibrated9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**. |
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes       | Callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('X-coordinate bias: ' + data.biasX);
      console.info('Y-coordinate bias: ' + data.biasY);
      console.info('Z-coordinate bias: ' + data.biasZ);
  },
      {interval: 10000000}
  );

  ```

### PROXIMITY<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback&lt;ProximityResponse&gt;,options?: Options): void

Subscribes to data changes of the proximity sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.PROXIMITY](#proximity9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_PROXIMITY      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PROXIMITY**. |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes       | Callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**. |
| options  | [Options](#options)                                     | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY,function(data){
      console.info('Distance: ' + data.distance);
  },
      {interval: 10000000}
  );

  ```

### HUMIDITY<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback&lt;HumidityResponse&gt;,options?: Options): void

Subscribes to data changes of the humidity sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.HUMIDITY](#humidity9) instead. 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                  | Mandatory | Description                                                  |
| -------- | ----------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_HUMIDITY     | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HUMIDITY**. |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes       | Callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**. |
| options  | [Options](#options)                                   | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY,function(data){
      console.info('Humidity: ' + data.humidity);
  },
      {interval: 10000000}
  );

  ```

### BAROMETER<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback&lt;BarometerResponse&gt;,options?: Options): void

Subscribes to data changes of the barometer sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.BAROMETER](#barometer9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_BAROMETER      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_BAROMETER**. |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes       | Callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**. |
| options  | [Options](#options)                                     | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER,function(data){
      console.info('Atmospheric pressure: ' + data.pressure);
  },
      {interval: 10000000}
  );

  ```

### HALL<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback&lt;HallResponse&gt;, options?: Options): void

Subscribes to data changes of the Hall effect sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.HALL](#hall9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                          | Mandatory | Description                                                  |
| -------- | --------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_HALL | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HALL**. |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | Yes       | Callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**. |
| options  | [Options](#options)                           | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HALL,function(data){
      console.info('Status: ' + data.status);
  },
      {interval: 10000000}
  );

  ```

### AMBIENT_LIGHT<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;, options?: Options): void

Subscribes to data changes of the ambient light sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.AMBIENT_LIGHT](#ambient_light9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                   | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_AMBIENT_LIGHT | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**. |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt;        | Yes       | Callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**. |
| options  | [Options](#options)                                    | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT,function(data){
      console.info(' Illumination: ' + data.intensity);
  },
      {interval: 10000000}
  );

  ```

### ORIENTATION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback&lt;OrientationResponse&gt;, options?: Options): void

Subscribes to data changes of the orientation sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.ORIENTATION](#orientation9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                        | Mandatory | Description                                                  |
| -------- | ----------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ORIENTATION        | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ORIENTATION**. |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes       | Callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**. |
| options  | [Options](#options)                                         | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION,function(data){
      console.info('The device rotates at an angle around the X axis: ' + data.beta);
      console.info('The device rotates at an angle around the Y axis: ' + data.gamma);
      console.info('The device rotates at an angle around the Z axis: ' + data.alpha);
  },
      {interval: 10000000}
  );

  ```

### HEART_RATE<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback&lt;HeartRateResponse&gt;, options?: Options): void

Subscribes to only one data change of the heart rate sensor.

This API is deprecated since API version 9. You are advised to use [sensor.on.HEART_RATE](#heart_rate9) instead.

**Required permissions**: ohos.permission.HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_HEART_RATE     | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HEART_RATE**. |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | Yes       | One-shot callback used to return the heart rate sensor data. The reported data type in the callback is **HeartRateResponse**. |

### ROTATION_VECTOR<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,callback: Callback&lt;RotationVectorResponse&gt;,options?: Options): void

Subscribes to data changes of the rotation vector sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.ROTATION_VECTOR](#rotation_vector9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ROTATION_VECTOR     | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**. |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes       | Callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('Scalar quantity: ' + data.w);
  },
      {interval: 10000000}
  );

  ```

### WEAR_DETECTION<sup>(deprecated)</sup>

on(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback&lt;WearDetectionResponse&gt;,options?: Options): void

Subscribes to data changes of the wear detection sensor. If this API is called multiple times for the same application, the last call takes effect.

This API is deprecated since API version 9. You are advised to use [sensor.on.WEAR_DETECTION](#wear_detection9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_WEAR_DETECTION      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_WEAR_DETECTION**. |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes       | Callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**. |
| options  | [Options](#options)                                          | No        | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns. |

**Example**

  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION,function(data){
      console.info('Wear status: ' + data.value);
  },
      {interval: 10000000}
  );

  ```

## sensor.once<sup>(deprecated)</sup>

### ACCELEROMETER<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback&lt;AccelerometerResponse&gt;): void

Subscribes to only one data change of the acceleration sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.ACCELEROMETER](#accelerometer9-1) instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ACCELEROMETER       | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER**. |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes       | One-shot callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );

  ```

### LINEAR_ACCELERATION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:Callback&lt;LinearAccelerometerResponse&gt;): void

Subscribes to only one data change of the linear acceleration sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.LINEAR_ACCELEROMETER](#linear_accelerometer9-1) instead.

**Required permissions**: ohos.permission.ACCELERATION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_LINEAR_ACCELERATION | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**. |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes       | One-shot callback used to return the linear acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**. |

### ACCELEROMETER_UNCALIBRATED<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback: Callback&lt;AccelerometerUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated acceleration sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.ACCELEROMETER_UNCALIBRATED](#accelerometer_uncalibrated9-1) instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**. |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes       | One-shot callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**. |

**Example**

  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('X-coordinate bias: ' + data.biasX);
      console.info('Y-coordinate bias: ' + data.biasY);
      console.info('Z-coordinate bias: ' + data.biasZ);
    }
  );

  ```

### GRAVITY<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback&lt;GravityResponse&gt;): void

Subscribes to only one data change of the gravity sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.GRAVITY](#gravity9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                | Mandatory | Description                                                  |
| -------- | --------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_GRAVITY    | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GRAVITY**. |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | Yes       | One-shot callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );

  ```

### GYROSCOPE<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback&lt;GyroscopeResponse&gt;): void

Subscribes to only one data change of the gyroscope sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.GYROSCOPE](#gyroscope9-1) instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_GYROSCOPE      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE**. |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes       | One-shot callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );

  ```

### GYROSCOPE_UNCALIBRATED<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback: Callback&lt;GyroscopeUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated gyroscope sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.GYROSCOPE_UNCALIBRATED](#gyroscope_uncalibrated9-1) instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**. |
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes       | One-shot callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('X-coordinate bias: ' + data.biasX);
      console.info('Y-coordinate bias: ' + data.biasY);
      console.info('Z-coordinate bias: ' + data.biasZ);
    }
  );

  ```

### SIGNIFICANT_MOTION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION,callback: Callback&lt;SignificantMotionResponse&gt;): void

Subscribes to only one data change of the significant motion sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.SIGNIFICANT_MOTION](#significant_motion9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_SIGNIFICANT_MOTION  | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**. |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes       | One-shot callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, function(data) {
      console.info('Scalar data: ' + data.scalar);
    }
  );

  ```

### PEDOMETER_DETECTION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,callback: Callback&lt;PedometerDetectionResponse&gt;): void

Subscribes to only one data change of the pedometer detection sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.PEDOMETER_DETECTION](#pedometer_detection9-1) instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_PEDOMETER_DETECTION | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**. |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | Yes       | One-shot callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectionResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, function(data) {
      console.info('Scalar data: ' + data.scalar);
    }
  );

  ```

### PEDOMETER<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback&lt;PedometerResponse&gt;): void

Subscribes to only one data change of the pedometer sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.PEDOMETER](#pedometer9-1) instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_PEDOMETER      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER**. |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes       | One-shot callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, function(data) {
      console.info('Steps: ' + data.steps);
    }
  );

  ```

### AMBIENT_TEMPERATURE<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback: Callback&lt;AmbientTemperatureResponse&gt;): void

Subscribes to only one data change of the ambient temperature sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.AMBIENT_TEMPERATURE](#ambient_temperature9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**. |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes       | One-shot callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, function(data) {
      console.info('Temperature: ' + data.temperature);
    }
  );

  ```

### MAGNETIC_FIELD<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;): void

Subscribes to only one data change of the magnetic field sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.MAGNETIC_FIELD](#magnetic_field9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_MAGNETIC_FIELD      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**. |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes       | One-shot callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );

  ```

### MAGNETIC_FIELD_UNCALIBRATED<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback: Callback&lt;MagneticFieldUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated magnetic field sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.MAGNETIC_FIELD_UNCALIBRATED](#magnetic_field_uncalibrated9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**. |
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes       | One-shot callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('X-coordinate bias: ' + data.biasX);
      console.info('Y-coordinate bias: ' + data.biasY);
      console.info('Z-coordinate bias: ' + data.biasZ);
    }
  );

  ```

### PROXIMITY<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback&lt;ProximityResponse&gt;): void

Subscribes to only one data change of the proximity sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.PROXIMITY](#proximity9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_PROXIMITY      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PROXIMITY**. |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes       | One-shot callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, function(data) {
      console.info('Distance: ' + data.distance);
    }
  );

  ```

### HUMIDITY<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback&lt;HumidityResponse&gt;): void

Subscribes to only one data change of the humidity sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.HUMIDITY](#humidity9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                  | Mandatory | Description                                                  |
| -------- | ----------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_HUMIDITY     | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HUMIDITY**. |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes       | One-shot callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, function(data) {
      console.info('Humidity: ' + data.humidity);
    }
  );

  ```

### BAROMETER<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback&lt;BarometerResponse&gt;): void

Subscribes to only one data change of the barometer sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.BAROMETER](#barometer9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_BAROMETER      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_BAROMETER**. |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes       | One-shot callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, function(data) {
      console.info('Atmospheric pressure: ' + data.pressure);
    }
  );

  ```

### HALL<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback&lt;HallResponse&gt;): void

Subscribes to only one data change of the Hall effect sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.HALL](#hall9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                          | Mandatory | Description                                                  |
| -------- | --------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_HALL | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HALL**. |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | Yes       | One-shot callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HALL, function(data) {
      console.info('Status: ' + data.status);
    }
  );

  ```

### AMBIENT_LIGHT<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;): void

Subscribes to only one data change of the ambient light sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.AMBIENT_LIGHT](#ambient_light9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                   | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_AMBIENT_LIGHT | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**. |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt;        | Yes       | One-shot callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, function(data) {
      console.info(' Illumination: ' + data.intensity);
    }
  );

  ```

### ORIENTATION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback&lt;OrientationResponse&gt;): void

Subscribes to only one data change of the orientation sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.ORIENTATION](#orientation9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                        | Mandatory | Description                                                  |
| -------- | ----------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ORIENTATION        | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ORIENTATION**. |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes       | One-shot callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, function(data) {
      console.info('The device rotates at an angle around the X axis: ' + data.beta);
      console.info('The device rotates at an angle around the Y axis: ' + data.gamma);
      console.info('The device rotates at an angle around the Z axis: ' + data.alpha);
    }
  );

  ```

### ROTATION_VECTOR<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: Callback&lt;RotationVectorResponse&gt;): void

Subscribes to only one data change of the rotation vector sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.ROTATION_VECTOR](#rotation_vector9-1) instead. 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ROTATION_VECTOR     | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**. |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes       | One-shot callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('Scalar quantity: ' + data.w);
    }
  );

  ```

### HEART_RATE<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback&lt;HeartRateResponse&gt;): void

Subscribes to only one data change of the heart rate sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.HEART_RATE](#heart_rate9-1) instead.

**Required permissions**: ohos.permission.HEART_RATE 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_HEART_RATE     | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HEART_RATE**. |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | Yes       | One-shot callback used to return the heart rate sensor data. The reported data type in the callback is **HeartRateResponse**. |

### WEAR_DETECTION<sup>(deprecated)</sup>

once(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback&lt;WearDetectionResponse&gt;): void

Subscribes to only one data change of the wear detection sensor.

This API is deprecated since API version 9. You are advised to use [sensor.once.WEAR_DETECTION](#wear_detection9-1) instead. 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_WEAR_DETECTION      | Yes       | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_WEAR_DETECTION**. |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes       | One-shot callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**. |

**Example**

  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, function(data) {
      console.info("Wear status: "+ data.value);
    }
  );

  ```

## sensor.off<sup>(deprecated)</sup>

### ACCELEROMETER<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback?: Callback&lt;AccelerometerResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.ACCELEROMETER](#accelerometer9-2) instead. 

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ACCELEROMETER       | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ACCELEROMETER**. |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | No        | Callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**. |

**Example**

```js
function callback(data) {
    console.info('x-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback);

```

### ACCELEROMETER_UNCALIBRATED<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback?: Callback&lt;AccelerometerUncalibratedResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.ACCELEROMETER_UNCALIBRATED](#accelerometer_uncalibrated9-2) instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**. |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | No        | Callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**. |

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
    console.info('X-coordinate bias: ' + data.biasX);
    console.info('Y-coordinate bias: ' + data.biasY);
    console.info('Z-coordinate bias: ' + data.biasZ);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback);

```

### AMBIENT_LIGHT<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback?: Callback&lt;LightResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.AMBIENT_LIGHT](#ambient_light9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                   | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_AMBIENT_LIGHT | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**. |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt;        | No        | Callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**. |

**Example**

```js
function callback(data) {
    console.info(' Illumination: ' + data.intensity);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback);

```

### AMBIENT_TEMPERATURE<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback?: Callback&lt;AmbientTemperatureResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.AMBIENT_TEMPERATURE](#ambient_temperature9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**. |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | No        | Callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**. |

**Example**

```js
function callback(data) {
     console.info('Temperature: ' + data.temperature);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback);

```

### BAROMETER<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback?: Callback&lt;BarometerResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.BAROMETER](#barometer9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_BAROMETER      | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_BAROMETER**. |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | No        | Callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**. |

**Example**

```js
function callback(data) {
     console.info('Atmospheric pressure: ' + data.pressure);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, callback);

```

### GRAVITY<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback?: Callback&lt;GravityResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.GRAVITY](#gravity9-2) instead. 

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                | Mandatory | Description                                                  |
| -------- | --------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_GRAVITY    | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_GRAVITY**. |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | No        | Callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**. |

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off( sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, callback);

```

### GYROSCOPE<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback?: Callback&lt;GyroscopeResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.GYROSCOPE](#gyroscope9-2) instead.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_GYROSCOPE      | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_GYROSCOPE**. |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | No        | Callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**. |

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback);

```

### GYROSCOPE_UNCALIBRATED<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback?: Callback&lt;GyroscopeUncalibratedResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.GYROSCOPE_UNCALIBRATED](#gyroscope_uncalibrated9-2) instead. 

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**. |
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | No        | Callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**. |

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback);

```

### HALL<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_HALL, callback?: Callback&lt;HallResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.HALL](#hall9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                          | Mandatory | Description                                                  |
| -------- | --------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_HALL | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_HALL**. |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | No        | Callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**. |

**Example**

```js
function callback(data) {
    console.info('Status: ' + data.status);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HALL, callback);

```

### HEART_RATE<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback?: Callback&lt;HeartRateResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.HEART_RATE](#heart_rate9-2) instead.

**Required permissions**: ohos.permission.HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_HEART_RATE     | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_HEART_RATE**. |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | No        | One-shot callback used to return the heart rate sensor data. The reported data type in the callback is **HeartRateResponse**. |

### HUMIDITY<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback?: Callback&lt;HumidityResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.HUMIDITY](#humidity9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                  | Mandatory | Description                                                  |
| -------- | ----------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_HUMIDITY     | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_HUMIDITY**. |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | No        | Callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**. |

**Example**

```js
function callback(data) {
    console.info('Humidity: ' + data.humidity);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, callback);

```

### LINEAR_ACCELERATION<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback?: Callback&lt;LinearAccelerometerResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.LINEAR_ACCELEROMETER](#linear_accelerometer9-2) instead.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_LINEAR_ACCELERATION | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**. |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | No        | Callback used to return the linear acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**. |

### MAGNETIC_FIELD<sup>(deprecated)</sup>

 off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback?: Callback&lt;MagneticFieldResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.MAGNETIC_FIELD](#magnetic_field9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name             | Type                                                         | Mandatory | Description                                                  |
| ---------------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type             | [SensorType](#sensortype).SENSOR_TYPE_ID_MAGNETIC_FIELD      | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**. |
| callbackcallback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | No        | Callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**. |

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback);

```

### MAGNETIC_FIELD_UNCALIBRATED<sup>(deprecated)</sup>

 off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback?: Callback&lt;MagneticFieldUncalibratedResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.MAGNETIC_FIELD_UNCALIBRATED](#magnetic_field_uncalibrated9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**. |
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | No        | Callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**. |

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
    console.info('X-coordinate bias: ' + data.biasX);
    console.info('Y-coordinate bias: ' + data.biasY);
    console.info('Z-coordinate bias: ' + data.biasZ);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback);

```

### ORIENTATION<sup>(deprecated)</sup>

 off(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback?: Callback&lt;OrientationResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.ORIENTATION](#orientation9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                        | Mandatory | Description                                                  |
| -------- | ----------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ORIENTATION        | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ORIENTATION**. |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | No        | Callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**. |

**Example**

```js
function callback(data) {
    console.info('The device rotates at an angle around the X axis: ' + data.beta);
    console.info('The device rotates at an angle around the Y axis: ' + data.gamma);
    console.info('The device rotates at an angle around the Z axis: ' + data.alpha);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, callback);

```

### PEDOMETER<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback?: Callback&lt;PedometerResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.PEDOMETER](#pedometer9-2) instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_PEDOMETER      | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_PEDOMETER**. |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | No        | Callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**. |

**Example**

```js
function callback(data) {
    console.info('Steps: ' + data.steps);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, callback);

```

### PEDOMETER_DETECTION<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback?: Callback&lt;PedometerDetectionResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.PEDOMETER_DETECTION](#pedometer_detection9-2) instead.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_PEDOMETER_DETECTION | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**. |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | No        | Callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectionResponse**. |

**Example**

```js
function callback(data) {
    console.info('Scalar data: ' + data.scalar);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback);

```

### PROXIMITY<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback?: Callback&lt;ProximityResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.PROXIMITY](#proximity9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                    | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------- | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_PROXIMITY      | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_PROXIMITY**. |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | No        | Callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**. |

**Example**

```js
function callback(data) {
    console.info('Distance: ' + data.distance);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, callback);

```

### ROTATION_VECTOR<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback?: Callback&lt;RotationVectorResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.ROTATION_VECTOR](#rotation_vector9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_ROTATION_VECTOR     | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**. |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | No        | Callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**. |

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
    console.info('Scalar quantity: ' + data.w);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback);

```

### SIGNIFICANT_MOTION<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback?: Callback&lt;SignificantMotionResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.SIGNIFICANT_MOTION](#significant_motion9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_SIGNIFICANT_MOTION  | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**. |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | No        | Callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**. |

**Example**

```js
function callback(data) {
    console.info('Scalar data: ' + data.scalar);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback);

```

### WEAR_DETECTION<sup>(deprecated)</sup>

off(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback?: Callback&lt;WearDetectionResponse&gt;): void

Unsubscribes from sensor data changes.

This API is deprecated since API version 9. You are advised to use [sensor.off.WEAR_DETECTION](#wear_detection9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                                         | Mandatory | Description                                                  |
| -------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| type     | [SensorType](#sensortype).SENSOR_TYPE_ID_WEAR_DETECTION      | Yes       | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_WEAR_DETECTION**. |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | No        | Callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**. |

**Example**

```js
function accCallback(data) {
    console.info('Wear status: ' + data.value);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, accCallback);

```

## sensor.transformCoordinateSystem<sup>(deprecated)</sup>

transformCoordinateSystem(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Rotates a rotation vector so that it can represent the coordinate system in different ways. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.transformRotationMatrix](#sensortransformrotationmatrix9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name             | Type                                      | Mandatory | Description                                                  |
| ---------------- | ----------------------------------------- | --------- | ------------------------------------------------------------ |
| inRotationVector | Array&lt;number&gt;                       | Yes       | Rotation vector to rotate.                                   |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes       | Direction of the coordinate system.                          |
| callback         | AsyncCallback&lt;Array&lt;number&gt;&gt;  | Yes       | Callback used to return the rotation vector after being rotated. |

**Example**

```js
sensor.transformCoordinateSystem([1, 0, 0, 0, 1, 0, 0, 0, 1], {x:2, y:3}, function(err, data) {
    if (err) {
        console.error("Operation failed. Error code: " + err.code + ", message: " + err.message);
        return;
    }
    console.info("Operation successed. Data obtained: " + data);
    for (var i=0; i < data.length; i++) {
        console.info("transformCoordinateSystem data[ " + i + "] = " + data[i]);
    }
 })

```

## sensor.transformCoordinateSystem<sup>(deprecated)</sup>

transformCoordinateSystem(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions): Promise&lt;Array&lt;number&gt;&gt;

Rotates a rotation vector so that it can represent the coordinate system in different ways. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.transformRotationMatrix](#sensortransformrotationmatrix9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name             | Type                                      | Mandatory | Description                         |
| ---------------- | ----------------------------------------- | --------- | ----------------------------------- |
| inRotationVector | Array&lt;number&gt;                       | Yes       | Rotation vector to rotate.          |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes       | Direction of the coordinate system. |

**Return value**

| Type                               | Description                                                  |
| ---------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation vector after being rotated. |

**Example**

```js
const promise = sensor.transformCoordinateSystem([1, 0, 0, 0, 1, 0, 0, 0, 1], {x:2, y:3});
    promise.then((data) => {
        console.info("Operation successed.");
        for (var i=0; i < data.length; i++) {
            console.info("transformCoordinateSystem data[ " + i + "] = " + data[i]);
        }
    }).catch((err) => {
           console.info("Operation failed");
})

```

## sensor.getGeomagneticField<sup>(deprecated)</sup>

getGeomagneticField(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback&lt;GeomagneticResponse&gt;): void

Obtains the geomagnetic field of a geographic location. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getGeomagneticInfo](#sensorgetgeomagneticinfo9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name            | Type                                                         | Mandatory | Description                                                  |
| --------------- | ------------------------------------------------------------ | --------- | ------------------------------------------------------------ |
| locationOptions | [LocationOptions](#locationoptions)                          | Yes       | Geographic location.                                         |
| timeMillis      | number                                                       | Yes       | Time for obtaining the magnetic declination, in milliseconds. |
| callback        | AsyncCallback&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Yes       | Callback used to return the geomagnetic field.               |

**Example**

```js
sensor.getGeomagneticField({latitude:80, longitude:0, altitude:0}, 1580486400000, function(err, data)  {
    if (err) {
        console.error('Operation failed. Error code: ' + err.code + '; message: ' + err.message);
        return;
    }
    console.info('sensor_getGeomagneticField_callback x: ' + data.x + ',y: ' + data.y + ',z: ' +
	             data.z + ',geomagneticDip: ' + data.geomagneticDip + ',deflectionAngle: ' + data.deflectionAngle +
		     ',levelIntensity: ' + data.levelIntensity + ',totalIntensity: ' + data.totalIntensity);
});

```

## sensor.getGeomagneticField<sup>(deprecated)</sup>

getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise&lt;GeomagneticResponse&gt;

Obtains the geomagnetic field of a geographic location. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getGeomagneticInfo](#sensorgetgeomagneticinfo9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name            | Type                                | Mandatory | Description                                                  |
| --------------- | ----------------------------------- | --------- | ------------------------------------------------------------ |
| locationOptions | [LocationOptions](#locationoptions) | Yes       | Geographic location.                                         |
| timeMillis      | number                              | Yes       | Time for obtaining the magnetic declination, in milliseconds. |

**Return value**

| Type                                                       | Description                                   |
| ---------------------------------------------------------- | --------------------------------------------- |
| Promise&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Promise used to return the geomagnetic field. |

**Example**

  ```js
  const promise = sensor.getGeomagneticField({latitude:80, longitude:0, altitude:0}, 1580486400000);
      promise.then((data) => {
          console.info('sensor_getGeomagneticField_promise x: ' + data.x + ',y: ' + data.y + ',z: ' +
  	             data.z + ',geomagneticDip: ' + data.geomagneticDip + ',deflectionAngle: ' + data.deflectionAngle +
  		     ',levelIntensity: ' + data.levelIntensity + ',totalIntensity: ' + data.totalIntensity);
      }).catch((reason) => {
          console.info('Operation failed.');
  })

  ```

## sensor.getAltitude<sup>(deprecated)</sup>

getAltitude(seaPressure: number, currentPressure: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the altitude at which the device is located based on the sea-level atmospheric pressure and the current atmospheric pressure. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getDeviceAltitude](#sensorgetdevicealtitude9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name            | Type                        | Mandatory | Description                                                  |
| --------------- | --------------------------- | --------- | ------------------------------------------------------------ |
| seaPressure     | number                      | Yes       | Sea-level atmospheric pressure, in hPa.                      |
| currentPressure | number                      | Yes       | Atmospheric pressure at the altitude where the device is located, in hPa. |
| callback        | AsyncCallback&lt;number&gt; | Yes       | Callback used to return the altitude, in meters.             |

**Example**

  ```js
  sensor.getAltitude(0, 200, function(err, data)  {
      if (err) {
          console.error(
  "Operation failed. Error code: " + err.code + ", message: " + err.message);
          return;
      }
          console.info("Successed to get getAltitude interface get data: " + data);
  });

  ```

## sensor.getAltitude<sup>(deprecated)</sup>

getAltitude(seaPressure: number, currentPressure: number): Promise&lt;number&gt;

Obtains the altitude at which the device is located based on the sea-level atmospheric pressure and the current atmospheric pressure. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getDeviceAltitude](#sensorgetdevicealtitude9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name            | Type   | Mandatory | Description                                                  |
| --------------- | ------ | --------- | ------------------------------------------------------------ |
| seaPressure     | number | Yes       | Sea-level atmospheric pressure, in hPa.                      |
| currentPressure | number | Yes       | Atmospheric pressure at the altitude where the device is located, in hPa. |

**Return value**

| Type                  | Description                                     |
| --------------------- | ----------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the altitude, in meters. |

**Example**

  ```js
  const promise = sensor.getAltitude(0, 200);
      promise.then((data) => {
          console.info(' sensor_getAltitude_Promise success', data);
      }).catch((err) => {
          console.error("Operation failed");
  })

  ```


## sensor.getGeomagneticDip<sup>(deprecated)</sup>

getGeomagneticDip(inclinationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;number&gt;): void

Obtains the magnetic dip based on the inclination matrix. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getInclination](#sensorgetinclination9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name              | Type                        | Mandatory | Description                                           |
| ----------------- | --------------------------- | --------- | ----------------------------------------------------- |
| inclinationMatrix | Array&lt;number&gt;         | Yes       | Inclination matrix.                                   |
| callback          | AsyncCallback&lt;number&gt; | Yes       | Callback used to return the magnetic dip, in radians. |

**Example**

  ```js
  sensor.getGeomagneticDip([1, 0, 0, 0, 1, 0, 0, 0, 1], function(err, data)  {
      if (err) {
          console.error('SensorJsAPI--->Failed to register data, error code is:' + err.code + ', message: ' + 
                        err.message);
          return;
      }
          console.info("Successed to get getGeomagneticDip interface get data: " + data);
  })

  ```

## sensor.getGeomagneticDip<sup>(deprecated)</sup>

getGeomagneticDip(inclinationMatrix: Array&lt;number&gt;): Promise&lt;number&gt;

Obtains the magnetic dip based on the inclination matrix. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getInclination](#sensorgetinclination9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name              | Type                | Mandatory | Description         |
| ----------------- | ------------------- | --------- | ------------------- |
| inclinationMatrix | Array&lt;number&gt; | Yes       | Inclination matrix. |

**Return value**

| Type                  | Description                                          |
| --------------------- | ---------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the magnetic dip, in radians. |

**Example**

  ```js
  const promise = sensor.getGeomagneticDip([1, 0, 0, 0, 1, 0, 0, 0, 1]);
      promise.then((data) => {
          console.info('getGeomagneticDip_promise successed', data);
      }).catch((err) => {
           console.error("Operation failed");
  })

  ```

## sensor. getAngleModify<sup>(deprecated)</sup>

getAngleModify(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the angle change between two rotation matrices. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getAngleVariation](#sensorgetanglevariation9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name                  | Type                                     | Mandatory | Description                                                  |
| --------------------- | ---------------------------------------- | --------- | ------------------------------------------------------------ |
| currentRotationMatrix | Array&lt;number&gt;                      | Yes       | Current rotation matrix.                                     |
| preRotationMatrix     | Array&lt;number&gt;                      | Yes       | The other rotation matrix.                                   |
| callback              | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes       | Callback used to return the angle change around the z, x, and y axes. |

**Example**

  ```js
  sensor. getAngleModify([1,0,0,0,1,0,0,0,1], [1, 0, 0, 0, 0.87, -0.50, 0, 0.50, 0.87], function(err, data)  {
      if (err) {
          console.error('Failed to register data, error code is: ' + err.code + ', message: ' + 
                        err.message);
          return;
      }
      for (var i=0; i < data.length; i++) {
          console.info("data[" + i + "]: " + data[i]);
      }
  })

  ```


## sensor. getAngleModify<sup>(deprecated)</sup>

getAngleModify(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Obtains the angle change between two rotation matrices. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getAngleVariation](#sensorgetanglevariation9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name                  | Type                | Mandatory | Description                |
| --------------------- | ------------------- | --------- | -------------------------- |
| currentRotationMatrix | Array&lt;number&gt; | Yes       | Current rotation matrix.   |
| preRotationMatrix     | Array&lt;number&gt; | Yes       | The other rotation matrix. |

**Return value**

| Type                               | Description                                                  |
| ---------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the angle change around the z, x, and y axes. |

**Example**

  ```js
  const promise = sensor.getAngleModify([1,0,0,0,1,0,0,0,1], [1,0,0,0,0.87,-0.50,0,0.50,0.87]);
      promise.then((data) => {
          console.info('getAngleModifiy_promise success');
          for (var i=0; i < data.length; i++) {
              console.info("data[" + i + "]: " + data[i]);
          }
      }).catch((reason) => {
          console.info("promise::catch", reason);
  })

  ```


## sensor.createRotationMatrix<sup>(deprecated)</sup>

createRotationMatrix(rotationVector: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Converts a rotation vector into a rotation matrix. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getRotationMatrix](#sensorgetrotationmatrix9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                                     | Mandatory | Description                                  |
| -------------- | ---------------------------------------- | --------- | -------------------------------------------- |
| rotationVector | Array&lt;number&gt;                      | Yes       | Rotation vector to convert.                  |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes       | Callback used to return the rotation matrix. |

**Example**

  ```js
  sensor.createRotationMatrix([0.20046076, 0.21907, 0.73978853, 0.60376877], function(err, data) {
      if (err) {
          console.error('SensorJsAPI--->Failed to register data, error code is: ' + err.code + ', message: ' + 
                        err.message);
          return;
      }
      for (var i=0; i < data.length; i++) {
          console.info("data[" + i + "]: " + data[i]);
      }
  })

  ```


## sensor.createRotationMatrix<sup>(deprecated)</sup>

createRotationMatrix(rotationVector: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Converts a rotation vector into a rotation matrix. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getRotationMatrix](#sensorgetrotationmatrix9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                | Mandatory | Description                 |
| -------------- | ------------------- | --------- | --------------------------- |
| rotationVector | Array&lt;number&gt; | Yes       | Rotation vector to convert. |

**Return value**

| Type                               | Description                                 |
| ---------------------------------- | ------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation matrix. |

**Example**

  ```js
  const promise = sensor.createRotationMatrix([0.20046076, 0.21907, 0.73978853, 0.60376877]);
      promise.then((data) => {
          console.info('createRotationMatrix_promise success');
          for (var i=0; i < data.length; i++) {
              console.info("data[" + i + "]: " + data[i]);
          }
      }).catch((reason) => {
          console.info("promise::catch", reason);
  })	

  ```


## sensor.createQuaternion<sup>(deprecated)</sup>

createQuaternion(rotationVector: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Converts a rotation vector into a quaternion. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getQuaternion](#sensorgetquaternion9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                                     | Mandatory | Description                             |
| -------------- | ---------------------------------------- | --------- | --------------------------------------- |
| rotationVector | Array&lt;number&gt;                      | Yes       | Rotation vector to convert.             |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes       | Callback used to return the quaternion. |

**Example**

  ```js
  sensor.createQuaternion([0.20046076, 0.21907, 0.73978853, 0.60376877], function(err, data)  {
      if (err) {
          console.error('SensorJsAPI--->Failed to register data, error code is: ' + err.code + ', message: ' + 
                        err.message);
          return;
      }
      for (var i=0; i < data.length; i++) {
          console.info("data[" + i + "]: " + data[i]);
      }
  })

  ```


## sensor.createQuaternion<sup>(deprecated)</sup>

createQuaternion(rotationVector: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Converts a rotation vector into a quaternion. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getQuaternion](#sensorgetquaternion9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                | Mandatory | Description                 |
| -------------- | ------------------- | --------- | --------------------------- |
| rotationVector | Array&lt;number&gt; | Yes       | Rotation vector to convert. |

**Return value**

| Type                               | Description                            |
| ---------------------------------- | -------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the quaternion. |

**Example**

  ```js
  const promise = sensor.createQuaternion([0.20046076, 0.21907, 0.73978853, 0.60376877]);
      promise.then((data) => {
          console.info('createQuaternion_promise successed');
          for (var i=0; i < data.length; i++) {
              console.info("data[" + i + "]: " + data[i]);
          }
      }).catch((err) => {
          console.info('promise failed');
  })

  ```


## sensor.getDirection<sup>(deprecated)</sup>

getDirection(rotationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the device direction based on the rotation matrix. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getOrientation](#sensorgetorientation9) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                                     | Mandatory | Description                                                  |
| -------------- | ---------------------------------------- | --------- | ------------------------------------------------------------ |
| rotationMatrix | Array&lt;number&gt;                      | Yes       | Rotation matrix.                                             |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes       | Callback used to return the rotation angle around the z, x, and y axes. |

**Example**

  ```js
  sensor.getDirection([1, 0, 0, 0, 1, 0, 0, 0, 1], function(err, data)  {
      if (err) {
          console.error('SensorJsAPI--->Failed to register data, error code is: ' + err.code + ', message: ' +
                        err.message);
          return;
      }
      console.info("SensorJsAPI--->Successed to get getDirection interface get data: " + data);
      for (var i = 1; i < data.length; i++) {
          console.info("sensor_getDirection_callback" + data[i]);
      }
  })

  ```


## sensor.getDirection<sup>(deprecated)</sup>

getDirection(rotationMatrix: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Obtains the device direction based on the rotation matrix. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getOrientation](#sensorgetorientation9-1) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                | Mandatory | Description      |
| -------------- | ------------------- | --------- | ---------------- |
| rotationMatrix | Array&lt;number&gt; | Yes       | Rotation matrix. |

**Return value**

| Type                               | Description                                                  |
| ---------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation angle around the z, x, and y axes. |

**Example**

  ```js
  const promise = sensor.getDirection([1, 0, 0, 0, 1, 0, 0, 0, 1]);
      promise.then((data) => {
          console.info('sensor_getAltitude_Promise success', data);
          for (var i = 1; i < data.length; i++) {
              console.info("sensor_getDirection_promise" + data[i]);
          }
      }).catch((err) => {
          console.info('promise failed');
  })
  ```


## sensor.createRotationMatrix<sup>(deprecated)</sup>

createRotationMatrix(gravity: Array&lt;number&gt;, geomagnetic: Array&lt;number&gt;, callback: AsyncCallback&lt;RotationMatrixResponse&gt;): void

Creates a rotation matrix based on the gravity vector and geomagnetic vector. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getRotationMatrix](#sensorgetrotationmatrix9-2) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                                         | Mandatory | Description                                  |
| ----------- | ------------------------------------------------------------ | --------- | -------------------------------------------- |
| gravity     | Array&lt;number&gt;                                          | Yes       | Gravity vector.                              |
| geomagnetic | Array&lt;number&gt;                                          | Yes       | Geomagnetic vector.                          |
| callback    | AsyncCallback&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | Yes       | Callback used to return the rotation matrix. |

**Example**

  ```js
  sensor.createRotationMatrix([-0.27775216, 0.5351276, 9.788099], [210.87253, -78.6096, -111.44444], function(err, data)  {
      if (err) {
          console.error('error code is: ' + err.code + ', message: ' + err.message);
          return;
      }
      console.info(JSON.stringify(data));
  })

  ```


## sensor.createRotationMatrix<sup>(deprecated)</sup>

createRotationMatrix(gravity: Array&lt;number&gt;, geomagnetic: Array&lt;number&gt;,): Promise&lt;RotationMatrixResponse&gt;

Creates a rotation matrix based on the gravity vector and geomagnetic vector. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [sensor.getRotationMatrix](#sensorgetrotationmatrix9-3) instead.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                | Mandatory | Description         |
| ----------- | ------------------- | --------- | ------------------- |
| gravity     | Array&lt;number&gt; | Yes       | Gravity vector.     |
| geomagnetic | Array&lt;number&gt; | Yes       | Geomagnetic vector. |

**Return value**

| Type                                                         | Description                                 |
| ------------------------------------------------------------ | ------------------------------------------- |
| Promise&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | Promise used to return the rotation matrix. |

**Example**

  ```js
  const promise = sensor.createRotationMatrix([-0.27775216, 0.5351276, 9.788099], [210.87253, -78.6096, -111.44444]);
      promise.then((data) => {
          console.info(JSON.stringify(data));
      }).catch((err) => {
          console.info('promise failed');
  })
  ```