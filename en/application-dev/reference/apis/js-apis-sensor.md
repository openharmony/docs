# Sensor

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import sensor from '@ohos.sensor';
```

## sensor.on

### ACCELEROMETER

on(type:  SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback&lt;AccelerometerResponse&gt;,options?: Options): void

Subscribes to data changes of the acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**System capability**: SystemCapability.Sensors.Sensor


**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER**.|
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes   | Callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

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

### LINEAR_ACCELERATION

on(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:Callback&lt;LinearAccelerometerResponse&gt;, options?: Options): void

Subscribes to data changes of the linear acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**.|
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes   | Callback used to return the linear acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```

### ACCELEROMETER_UNCALIBRATED

on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback: Callback&lt;AccelerometerUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**.|
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes   | Callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

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

### GRAVITY

on(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback&lt;GravityResponse&gt;,options?: Options): void

Subscribes to data changes of the gravity sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GRAVITY**.  |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | Yes   | Callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.       |

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

### GYROSCOPE

on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback&lt;GyroscopeResponse&gt;, options?: Options): void

Subscribes to data changes of the gyroscope sensor. If this API is called multiple times for the same application, the last call takes effect.

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE**.  |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes   | Callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

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

### GYROSCOPE_UNCALIBRATED

on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback:Callback&lt;GyroscopeUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated gyroscope sensor. If this API is called multiple times for the same application, the last call takes effect.

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**.|
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes   | Callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data.                          |

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

### SIGNIFICANT_MOTION

on(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: Callback&lt;SignificantMotionResponse&gt;, options?: Options): void

Subscribes to data changes of the significant motion sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**.|
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes   | Callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION,function(data){
      console.info('Scalar data: ' + data.scalar);
  },
      {interval: 10000000}
  );
  ```

### PEDOMETER_DETECTION

on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback&lt;PedometerDetectionResponse&gt;, options?: Options): void

Subscribes to data changes of the pedometer detection sensor. If this API is called multiple times for the same application, the last call takes effect.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**.|
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | Yes   | Callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectionResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,function(data){
      console.info('Scalar data: ' + data.scalar);
  },
      {interval: 10000000}
  );
  ```

### PEDOMETER

on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback&lt;PedometerResponse&gt;, options?: Options): void

Subscribes to data changes of the pedometer sensor. If this API is called multiple times for the same application, the last call takes effect.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER**.  |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes   | Callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.         |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER,function(data){
      console.info('Steps: ' + data.steps);
  },
      {interval: 10000000}
  );
  ```

### AMBIENT_TEMPERATURE

on(type:SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:Callback&lt;AmbientTemperatureResponse&gt;,  options?: Options): void

Subscribes to data changes of the ambient temperature sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**.|
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes   | Callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,function(data){
      console.info('Temperature: ' + data.temperature);
  },
      {interval: 10000000}
  );
  ```

### MAGNETIC_FIELD

on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;,options?: Options): void

Subscribes to data changes of the magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**.|
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes   | Callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

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

### MAGNETIC_FIELD_UNCALIBRATED

on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback: Callback&lt;MagneticFieldUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**.|
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes   | Callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

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

### PROXIMITY

on(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback&lt;ProximityResponse&gt;,options?: Options): void

Subscribes to data changes of the proximity sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PROXIMITY**.  |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes   | Callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY,function(data){
      console.info('Distance: ' + data.distance);
  },
      {interval: 10000000}
  );
  ```

### HUMIDITY

on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback&lt;HumidityResponse&gt;,options?: Options): void

Subscribes to data changes of the humidity sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                    |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HUMIDITY**.  |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes   | Callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.        |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY,function(data){
      console.info('Humidity: ' + data.humidity);
  },
      {interval: 10000000}
  );
  ```

### BAROMETER

on(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback&lt;BarometerResponse&gt;,options?: Options): void

Subscribes to data changes of the barometer sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_BAROMETER**.  |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes   | Callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER,function(data){
      console.info('Atmospheric pressure: ' + data.pressure);
  },
      {interval: 10000000}
  );
  ```

### HALL

on(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback&lt;HallResponse&gt;, options?: Options): void

Subscribes to data changes of the Hall effect sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HALL**.        |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | Yes   | Callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HALL,function(data){
      console.info('Status: ' + data.status);
  },
      {interval: 10000000}
  );
  ```

### AMBIENT_LIGHT

on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;, options?: Options): void

Subscribes to data changes of the ambient light sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**.|
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | Yes   | Callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**.    |
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT,function(data){
      console.info(' Illumination: ' + data.intensity);
  },
      {interval: 10000000}
  );
  ```

### ORIENTATION

on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback&lt;OrientationResponse&gt;, options?: Options): void

Subscribes to data changes of the orientation sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ORIENTATION**.  |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes   | Callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

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

### HEART_RATE

on(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback&lt;HeartRateResponse&gt;, options?: Options): void

Subscribes to only one data change of the heart rate sensor.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HEART_RATE**.  |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | Yes   | One-shot callback used to return the heart rate sensor data. The reported data type in the callback is **HeartRateResponse**.|

**Example**

```js
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE,function(data){
    console.info("Heart rate: " + data.heartRate);
},
    {interval: 10000000}
);
```

### ROTATION_VECTOR

on(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,callback: Callback&lt;RotationVectorResponse&gt;,options?: Options): void

Subscribes to data changes of the rotation vector sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**.|
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes   | Callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

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

### WEAR_DETECTION

on(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback&lt;WearDetectionResponse&gt;,options?: Options): void

Subscribes to data changes of the wear detection sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_WEAR_DETECTION**.|
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes   | Callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**.|
| options  | [Options](#options)                      | No   | Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.          |

**Example**
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION,function(data){
      console.info('Wear status: ' + data.value);
  },
      {interval: 10000000}
  );
  ```

## sensor.once

### ACCELEROMETER

once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback&lt;AccelerometerResponse&gt;): void

Subscribes to only one data change of the acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER**.  |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes   | One-shot callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER,function(data){
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```

### LINEAR_ACCELERATION

once(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:Callback&lt;LinearAccelerometerResponse&gt;): void

Subscribes to only one data change of the linear acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**.|
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes   | One-shot callback used to return the linear acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```

### ACCELEROMETER_UNCALIBRATED

once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback: Callback&lt;AccelerometerUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**.|
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes   | One-shot callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**.|

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

### GRAVITY

once(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback&lt;GravityResponse&gt;): void

Subscribes to only one data change of the gravity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                     |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GRAVITY**.        |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | Yes   | One-shot callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```

### GYROSCOPE

once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback&lt;GyroscopeResponse&gt;): void

Subscribes to only one data change of the gyroscope sensor.

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE**.      |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes   | One-shot callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```

### GYROSCOPE_UNCALIBRATED

once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback: Callback&lt;GyroscopeUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated gyroscope sensor.

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**.|
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes   | One-shot callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**.|

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

### SIGNIFICANT_MOTION

once(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION,callback: Callback&lt;SignificantMotionResponse&gt;): void

Subscribes to only one data change of the significant motion sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**.|
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes   | One-shot callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, function(data) {
      console.info('Scalar data: ' + data.scalar);
    }
  );
  ```

### PEDOMETER_DETECTION

once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,callback: Callback&lt;PedometerDetectionResponse&gt;): void

Subscribes to only one data change of the pedometer detection sensor.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**.|
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | Yes   | One-shot callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectionResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, function(data) {
      console.info('Scalar data: ' + data.scalar);
    }
  );
  ```

### PEDOMETER

once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback&lt;PedometerResponse&gt;): void

Subscribes to only one data change of the pedometer sensor.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER**.       |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes   | One-shot callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, function(data) {
      console.info('Steps: ' + data.steps);
    }
  );
  ```

### AMBIENT_TEMPERATURE

once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback: Callback&lt;AmbientTemperatureResponse&gt;): void

Subscribes to only one data change of the ambient temperature sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**.|
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes   | One-shot callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, function(data) {
      console.info('Temperature: ' + data.temperature);
    }
  );
  ```

### MAGNETIC_FIELD

once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;): void

Subscribes to only one data change of the magnetic field sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**.  |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes   | One-shot callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, function(data) {
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```

### MAGNETIC_FIELD_UNCALIBRATED

once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback: Callback&lt;MagneticFieldUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated magnetic field sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**.|
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes   | One-shot callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**.|

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

### PROXIMITY

once(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback&lt;ProximityResponse&gt;): void

Subscribes to only one data change of the proximity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PROXIMITY**.      |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes   | One-shot callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, function(data) {
      console.info('Distance: ' + data.distance);
    }
  );
  ```

### HUMIDITY

once(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback&lt;HumidityResponse&gt;): void

Subscribes to only one data change of the humidity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HUMIDITY**.        |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes   | One-shot callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, function(data) {
      console.info('Humidity: ' + data.humidity);
    }
  );
  ```

### BAROMETER

once(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback&lt;BarometerResponse&gt;): void

Subscribes to only one data change of the barometer sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_BAROMETER**.      |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes   | One-shot callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, function(data) {
      console.info('Atmospheric pressure: ' + data.pressure);
    }
  );
  ```

### HALL

once(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback&lt;HallResponse&gt;): void

Subscribes to only one data change of the Hall effect sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HALL**.        |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | Yes   | One-shot callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HALL, function(data) {
      console.info('Status: ' + data.status);
    }
  );
  ```

### AMBIENT_LIGHT

once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;): void

Subscribes to only one data change of the ambient light sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                    |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**.|
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | Yes   | One-shot callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, function(data) {
      console.info(' Illumination: ' + data.intensity);
    }
  );
  ```

### ORIENTATION

once(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback&lt;OrientationResponse&gt;): void

Subscribes to only one data change of the orientation sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ORIENTATION**.     |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes   | One-shot callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, function(data) {
      console.info('The device rotates at an angle around the X axis: ' + data.beta);
      console.info('The device rotates at an angle around the Y axis: ' + data.gamma);
      console.info('The device rotates at an angle around the Z axis: ' + data.alpha);
    }
  );
  ```

### ROTATION_VECTOR

once(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: Callback&lt;RotationVectorResponse&gt;): void

Subscribes to only one data change of the rotation vector sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**.|
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes   | One-shot callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**.|

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

### HEART_RATE

once(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback&lt;HeartRateResponse&gt;): void

Subscribes to only one data change of the heart rate sensor.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HEART_RATE**.      |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | Yes   | One-shot callback used to return the heart rate sensor data. The reported data type in the callback is **HeartRateResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, function(data) {
      console.info("Heart rate: " + data.heartRate);
    }
  );
  ```

### WEAR_DETECTION

once(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback&lt;WearDetectionResponse&gt;): void

Subscribes to only one data change of the wear detection sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_WEAR_DETECTION**.|
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes   | One-shot callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**.|

**Example**
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, function(data) {
      console.info("Wear status: "+ data.value);
    }
  );
  ```

## sensor.off

### ACCELEROMETER

off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback?: Callback&lt;AccelerometerResponse&gt;): void

Unsubscribes from sensor data changes.

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ACCELEROMETER**.|
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes   | Callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**.|

**Example**

```js
function callback(data) {
    console.info('x-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback);
```

### ACCELEROMETER_UNCALIBRATED

off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback?: Callback&lt;AccelerometerUncalibratedResponse&gt;): void

Unsubscribes from sensor data changes.

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**.|
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes   | Callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**.|

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

### AMBIENT_LIGHT

off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback?: Callback&lt;LightResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**.|
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | Yes   | Callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**.  |

**Example**

```js
function callback(data) {
    console.info(' Illumination: ' + data.intensity);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback);
```

### AMBIENT_TEMPERATURE

off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback?: Callback&lt;AmbientTemperatureResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**.|
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes   | Callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**.|

**Example**

```js
function callback(data) {
     console.info('Temperature: ' + data.temperature);
}
sensor.off( sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback);
```

### AMBIENT_TEMPERATURE

off(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback?: Callback&lt;BarometerResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_BAROMETER**.|
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes   | Callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**.|

**Example**

```js
function callback(data) {
     console.info('Atmospheric pressure: ' + data.pressure);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, callback);
```

### GRAVITY

off(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback?: Callback&lt;GravityResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_GRAVITY**.   |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | Yes   | Callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**.|

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off( sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, callback);
```

### GYROSCOPE

off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback?: Callback&lt;GyroscopeResponse&gt;): void

Unsubscribes from sensor data changes.

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_GYROSCOPE**.|
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes   | Callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**.|

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback);
```

### GYROSCOPE_UNCALIBRATED

off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback?: Callback&lt;GyroscopeUncalibratedResponse&gt;): void

Unsubscribes from sensor data changes.

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**.|
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes   | Callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**.|

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback);
```

### HALL

off(type: SensorType.SENSOR_TYPE_ID_HALL, callback?: Callback&lt;HallResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_HALL**.      |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | Yes   | Callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**.|

**Example**

```js
function callback(data) {
    console.info('Status: ' + data.status);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HALL, callback);
```

### HEART_RATE

off(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback?: Callback&lt;HeartRateResponse&gt;): void

Unsubscribes from sensor data changes.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)[SensorType](#sensortype) | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_HEART_RATE**.|
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | Yes   | One-shot callback used to return the heart rate sensor data. The reported data type in the callback is **HeartRateResponse**.|

**Example**

```js
function callback(data) {
    console.info("Heart rate: " + data.heartRate);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, callback);
```

### HUMIDITY

off(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback?: Callback&lt;HumidityResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_HUMIDITY**.  |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes   | Callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**.|

**Example**

```js
function callback(data) {
    console.info('Humidity: ' + data.humidity);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, callback);
```

### LINEAR_ACCELERATION

off(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback?: Callback&lt;LinearAccelerometerResponse&gt;): void

Unsubscribes from sensor data changes.

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**.|
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes   | Callback used to return the acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**.|

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback);
```

### MAGNETIC_FIELD

 off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback?: Callback&lt;MagneticFieldResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name             | Type                                      | Mandatory  | Description                                      |
| ---------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type             | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**.|
| callbackcallback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes   | Callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**.|

**Example**

```js
function callback(data) {
    console.info('X-coordinate component: ' + data.x);
    console.info('Y-coordinate component: ' + data.y);
    console.info('Z-coordinate component: ' + data.z);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback);
```

### MAGNETIC_FIELD_UNCALIBRATED

 off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback?: Callback&lt;MagneticFieldUncalibratedResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**.|
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes   | Callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**.|

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

### ORIENTATION

 off(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback?: Callback&lt;OrientationResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ORIENTATION**.|
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes   | Callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**.|

**Example**

```js
function callback(data) {
    console.info('The device rotates at an angle around the X axis: ' + data.beta);
    console.info('The device rotates at an angle around the Y axis: ' + data.gamma);
    console.info('The device rotates at an angle around the Z axis: ' + data.alpha);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, callback);
```

### PEDOMETER

off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback?: Callback&lt;PedometerResponse&gt;): void

Unsubscribes from sensor data changes.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_PEDOMETER**. |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes   | Callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**.|

**Example**

```js
function callback(data) {
    console.info('Steps: ' + data.steps);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, callback);
```

### PEDOMETER_DETECTION

off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback?: Callback&lt;PedometerDetectionResponse&gt;): void

Unsubscribes from sensor data changes.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**.|
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | Yes   | Callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectionResponse**.|

**Example**

```js
function callback(data) {
    console.info('Scalar data: ' + data.scalar);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback);
```

### PROXIMITY

off(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback?: Callback&lt;ProximityResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_PROXIMITY**.|
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes   | Callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**.|

**Example**

```js
function callback(data) {
    console.info('Distance: ' + data.distance);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, callback);
```

### ROTATION_VECTOR

off(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback?: Callback&lt;RotationVectorResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**.|
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes   | Callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**.|

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

### SIGNIFICANT_MOTION

off(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback?: Callback&lt;SignificantMotionResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**.|
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes   | Callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**.|

**Example**

```js
function callback(data) {
    console.info('Scalar data: ' + data.scalar);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback);
```

### WEAR_DETECTION

off(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback?: Callback&lt;WearDetectionResponse&gt;): void

Unsubscribes from sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | Yes   | Type of the sensor to unsubscribe from, which is **SENSOR_TYPE_ID_WEAR_DETECTION**.|
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes   | Callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**.|

**Example**

```js
function accCallback(data) {
    console.info('Wear status: ' + data.value);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, accCallback);
```

## sensor.transformCoordinateSystem

transformCoordinateSystem(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Rotates a rotation vector so that it can represent the coordinate system in different ways. This API uses a callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name             | Type                                      | Mandatory  | Description         |
| ---------------- | ---------------------------------------- | ---- | ----------- |
| inRotationVector | Array&lt;number&gt;                      | Yes   | Rotation vector to rotate.    |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes   | Direction of the coordinate system.   |
| callback         | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes   | Callback used to return the rotation vector after being rotated.|

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
## sensor.transformCoordinateSystem

transformCoordinateSystem(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions): Promise&lt;Array&lt;number&gt;&gt;

Rotates a rotation vector so that it can represent the coordinate system in different ways. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name             | Type                                      | Mandatory  | Description      |
| ---------------- | ---------------------------------------- | ---- | -------- |
| inRotationVector | Array&lt;number&gt;                      | Yes   | Rotation vector to rotate. |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | Yes   | Direction of the coordinate system.|

**Return value**

| Type                                | Description         |
| ---------------------------------- | ----------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation vector after being rotated.|

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

## sensor.getGeomagneticField

getGeomagneticField(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback&lt;GeomagneticResponse&gt;): void

Obtains the geomagnetic field of a geographic location. This API uses a callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name            | Type                                      | Mandatory  | Description               |
| --------------- | ---------------------------------------- | ---- | ----------------- |
| locationOptions | [LocationOptions](#locationoptions)      | Yes   | Geographic location.            |
| timeMillis      | number                                   | Yes   | Time for obtaining the magnetic declination, in milliseconds.|
| callback        | AsyncCallback&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Yes   | Callback used to return the geomagnetic field.          |

**Example**
```js
sensor.getGeomagneticField({latitude:80, longitude:0, altitude:0}, 1580486400000, function(err, data)  {
    if (err) {
        console.error('Operation failed. Error code: ' + err.code + '; message: ' + err.message);
        return;
    }
    console.info('sensor_getGeomagneticField_promise x: ' + data.x + ',y: ' + data.y + ',z: ' +
	             data.z + ',geomagneticDip: ' + data.geomagneticDip + ',deflectionAngle: ' + data.deflectionAngle +
		     ',levelIntensity: ' + data.levelIntensity + ',totalIntensity: ' + data.totalIntensity);
});
```
## sensor.getGeomagneticField

getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise&lt;GeomagneticResponse&gt;

Obtains the geomagnetic field of a geographic location. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**
| Name            | Type                                 | Mandatory  | Description               |
| --------------- | ----------------------------------- | ---- | ----------------- |
| locationOptions | [LocationOptions](#locationoptions) | Yes   | Geographic location.            |
| timeMillis      | number                              | Yes   | Time for obtaining the magnetic declination, in milliseconds.|

**Return value**
| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Promise used to return the geomagnetic field.|

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

## sensor.getAltitude

getAltitude(seaPressure: number, currentPressure: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the altitude at which the device is located based on the sea-level atmospheric pressure and the current atmospheric pressure. This API uses a callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name            | Type                         | Mandatory  | Description                  |
| --------------- | --------------------------- | ---- | -------------------- |
| seaPressure     | number                      | Yes   | Sea-level atmospheric pressure, in hPa.    |
| currentPressure | number                      | Yes   | Atmospheric pressure at the altitude where the device is located, in hPa.|
| callback        | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the altitude, in meters.   |

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

## sensor.getAltitude

getAltitude(seaPressure: number, currentPressure: number): Promise&lt;number&gt;

Obtains the altitude at which the device is located based on the sea-level atmospheric pressure and the current atmospheric pressure. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name            | Type    | Mandatory  | Description                  |
| --------------- | ------ | ---- | -------------------- |
| seaPressure     | number | Yes   | Sea-level atmospheric pressure, in hPa.    |
| currentPressure | number | Yes   | Atmospheric pressure at the altitude where the device is located, in hPa.|

**Return value**

| Type                   | Description                |
| --------------------- | ------------------ |
| Promise&lt;number&gt; | Promise used to return the altitude, in meters.|

**Example**

  ```js
  const promise = sensor.getAltitude(0, 200);
      promise.then((data) => {
          console.info(' sensor_getAltitude_Promise success', data);
      }).catch((err) => {
          console.error("Operation failed");
  })
  ```


## sensor.getGeomagneticDip

getGeomagneticDip(inclinationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;number&gt;): void

Obtains the magnetic dip based on the inclination matrix. This API uses a callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name              | Type                         | Mandatory  | Description            |
| ----------------- | --------------------------- | ---- | -------------- |
| inclinationMatrix | Array&lt;number&gt;         | Yes   | Inclination matrix.       |
| callback          | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the magnetic dip, in radians.|

**Example**

  ```js
  sensor.getGeomagneticDip([1, 0, 0, 0, 1, 0, 0, 0, 1], function(err, data)  {
      if (err) {
          console.error('SensorJsAPI--->Failed to register data, error code is: ' + err.code + ', message: ' + 
                        err.message);
          return;
      }
          console.info("Successed to get getGeomagneticDip interface get data: " + data);
  })
  ```

## sensor.getGeomagneticDip

getGeomagneticDip(inclinationMatrix: Array&lt;number&gt;): Promise&lt;number&gt;

Obtains the magnetic dip based on the inclination matrix. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name              | Type                 | Mandatory  | Description     |
| ----------------- | ------------------- | ---- | ------- |
| inclinationMatrix | Array&lt;number&gt; | Yes   | Inclination matrix.|

**Return value**

| Type                   | Description            |
| --------------------- | -------------- |
| Promise&lt;number&gt; | Promise used to return the magnetic dip, in radians.|

**Example**

  ```js
  const promise = sensor.getGeomagneticDip([1, 0, 0, 0, 1, 0, 0, 0, 1]);
      promise.then((data) => {
          console.info(' getGeomagneticDip_promise successed', data);
      }).catch((err) => {
           console.error("Operation failed");
  })
  ```

## sensor. getAngleModify

getAngleModify(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the angle change between two rotation matrices. This API uses a callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name                  | Type                                      | Mandatory  | Description                |
| --------------------- | ---------------------------------------- | ---- | ------------------ |
| currentRotationMatrix | Array&lt;number&gt;                      | Yes   | Current rotation matrix.         |
| preRotationMatrix     | Array&lt;number&gt;                      | Yes   | The other rotation matrix.           |
| callback              | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes   | Callback used to return the angle change around the z, x, and y axes.|

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


## sensor. getAngleModify

getAngleModify(currentRotationMatrix: Array&lt;number&gt;, preRotationMatrix: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Obtains the angle change between two rotation matrices. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name                  | Type                 | Mandatory  | Description       |
| --------------------- | ------------------- | ---- | --------- |
| currentRotationMatrix | Array&lt;number&gt; | Yes   | Current rotation matrix.|
| preRotationMatrix     | Array&lt;number&gt; | Yes   | Rotation matrix.  |

**Return value**

| Type                                | Description                |
| ---------------------------------- | ------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the angle change around the z, x, and y axes.|

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


## sensor.createRotationMatrix

createRotationMatrix(rotationVector: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Converts a rotation vector into a rotation matrix. This API uses a callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                                      | Mandatory  | Description     |
| -------------- | ---------------------------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt;                      | Yes   | Rotation vector to convert.|
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes   | Callback used to return the rotation matrix.|

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


## sensor.createRotationMatrix

createRotationMatrix(rotationVector: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Converts a rotation vector into a rotation matrix. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                 | Mandatory  | Description     |
| -------------- | ------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt; | Yes   | Rotation vector to convert.|

**Return value**

| Type                                | Description     |
| ---------------------------------- | ------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation matrix.|

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


## sensor.createQuaternion

createQuaternion(rotationVector: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Converts a rotation vector into a quaternion. This API uses a callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                                      | Mandatory  | Description     |
| -------------- | ---------------------------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt;                      | Yes   | Rotation vector to convert.|
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes   | Callback used to return the quaternion. |

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


## sensor.createQuaternion

createQuaternion(rotationVector: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Converts a rotation vector into a quaternion. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                 | Mandatory  | Description     |
| -------------- | ------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt; | Yes   | Rotation vector to convert.|

**Return value**

| Type                                | Description    |
| ---------------------------------- | ------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the quaternion.|

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


## sensor.getDirection

getDirection(rotationMatrix: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains the device direction based on the rotation matrix. This API uses a callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                                      | Mandatory  | Description                |
| -------------- | ---------------------------------------- | ---- | ------------------ |
| rotationMatrix | Array&lt;number&gt;                      | Yes   | Rotation matrix.           |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes   | Callback used to return the rotation angle around the z, x, and y axes.|

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


## sensor.getDirection

getDirection(rotationMatrix: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Obtains the device direction based on the rotation matrix. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name           | Type                 | Mandatory  | Description     |
| -------------- | ------------------- | ---- | ------- |
| rotationMatrix | Array&lt;number&gt; | Yes   | Rotation matrix.|

**Return value**

| Type                                | Description                |
| ---------------------------------- | ------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the rotation angle around the z, x, and y axes.|

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


## sensor.createRotationMatrix

createRotationMatrix(gravity: Array&lt;number&gt;, geomagnetic: Array&lt;number&gt;, callback: AsyncCallback&lt;RotationMatrixResponse&gt;): void

Creates a rotation matrix based on the gravity vector and geomagnetic vector. This API uses a callback to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                                      | Mandatory  | Description     |
| ----------- | ---------------------------------------- | ---- | ------- |
| gravity     | Array&lt;number&gt;                      | Yes   | Gravity vector.|
| geomagnetic | Array&lt;number&gt;                      | Yes   | Geomagnetic vector.|
| callback    | AsyncCallback&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | Yes   | Callback used to return the rotation matrix.|

**Example**

  ```js
  sensor.createRotationMatrix([-0.27775216, 0.5351276, 9.788099], [210.87253, -78.6096, -111.44444], function(err, data)  {
      if (err) {
          console.error('SensorJsAPI--->Failed to register data, error code is: ' + err.code + ', message: ' +
                        err.message);
          return;
      }
      for (var i=0; i < data.length; i++) {
          console.info("data[" + i + "]: " + data[i])
      }
  })
  ```


## sensor.createRotationMatrix

createRotationMatrix(gravity: Array&lt;number&gt;, geomagnetic: Array&lt;number&gt;,): Promise&lt;RotationMatrixResponse&gt;

Creates a rotation matrix based on the gravity vector and geomagnetic vector. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name        | Type                 | Mandatory  | Description     |
| ----------- | ------------------- | ---- | ------- |
| gravity     | Array&lt;number&gt; | Yes   | Gravity vector.|
| geomagnetic | Array&lt;number&gt; | Yes   | Geomagnetic vector.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | Promise used to return the rotation matrix.|

**Example**

  ```js
  const promise = sensor.createRotationMatrix([-0.27775216, 0.5351276, 9.788099], [210.87253, -78.6096, -111.44444]);
      promise.then((data) => {
          console.info('createRotationMatrix_promise successed');
          for (var i=0; i < data.length; i++) {
              console.info("data[" + i + "]: " + data[i]);
          }
      }).catch((err) => {
          console.info('promise failed');
  })
  ```


## SensorType

Enumerates the sensor types.

**System capability**: SystemCapability.Sensors.Sensor


| Name                                      | Default Value | Description         |
| ---------------------------------------- | ---- | ----------- |
| SENSOR_TYPE_ID_ACCELEROMETER             | 1    | Acceleration sensor.    |
| SENSOR_TYPE_ID_GYROSCOPE                 | 2    | Gyroscope sensor.    |
| SENSOR_TYPE_ID_AMBIENT_LIGHT             | 5    | Ambient light sensor.    |
| SENSOR_TYPE_ID_MAGNETIC_FIELD            | 6    | Magnetic field sensor.     |
| SENSOR_TYPE_ID_BAROMETER                 | 8    | Barometer sensor.    |
| SENSOR_TYPE_ID_HALL                      | 10   | Hall effect sensor.     |
| SENSOR_TYPE_ID_PROXIMITY                 | 12   | Proximity sensor.    |
| SENSOR_TYPE_ID_HUMIDITY                  | 13   | Humidity sensor.     |
| SENSOR_TYPE_ID_ORIENTATION               | 256  | Orientation sensor.     |
| SENSOR_TYPE_ID_GRAVITY                   | 257  | Gravity sensor.     |
| SENSOR_TYPE_ID_LINEAR_ACCELERATION       | 258  | Linear acceleration sensor.  |
| SENSOR_TYPE_ID_ROTATION_VECTOR           | 259  | Rotation vector sensor.   |
| SENSOR_TYPE_ID_AMBIENT_TEMPERATURE       | 260  | Ambient temperature sensor.   |
| SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | 261  | Uncalibrated magnetic field sensor.  |
| SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED    | 263  | Uncalibrated gyroscope sensor. |
| SENSOR_TYPE_ID_SIGNIFICANT_MOTION        | 264  | Significant motion sensor.   |
| SENSOR_TYPE_ID_PEDOMETER_DETECTION       | 265  | Pedometer detection sensor.   |
| SENSOR_TYPE_ID_PEDOMETER                 | 266  | Pedometer sensor.     |
| SENSOR_TYPE_ID_HEART_RATE                | 278  | Heart rate sensor.     |
| SENSOR_TYPE_ID_WEAR_DETECTION            | 280  | Wear detection sensor.   |
| SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | 281  | Uncalibrated acceleration sensor.|


## Response

Describes the timestamp of the sensor data.

**System capability**: SystemCapability.Sensors.Sensor

| Name       | Type  | Readable  | Writable  | Description          |
| --------- | ------ | ---- | ---- | ------------ |
| timestamp | number | Yes   | Yes   | Timestamp when the sensor reports data.|


## AccelerometerResponse

Describes the acceleration sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name  | Type  | Readable  | Writable  | Description                    |
| ---- | ------ | ---- | ---- | ---------------------- |
| x    | number | Yes   | Yes   | Acceleration along the x-axis of the device, in m/s2.|
| y    | number | Yes   | Yes   | Acceleration along the y-axis of the device, in m/s2.|
| z    | number | Yes   | Yes   | Acceleration along the z-axis of the device, in m/s2.|


## LinearAccelerometerResponse

Describes the linear acceleration sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name  | Type  | Readable  | Writable  | Description                      |
| ---- | ------ | ---- | ---- | ------------------------ |
| x    | number | Yes   | Yes   | Linear acceleration along the x-axis of the device, in m/s2.|
| y    | number | Yes   | Yes   | Linear acceleration along the y-axis of the device, in m/s2.|
| z    | number | Yes   | Yes   | Linear acceleration along the z-axis of the device, in m/s2.|


## AccelerometerUncalibratedResponse

Describes the uncalibrated acceleration sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name   | Type  | Readable  | Writable  | Description                          |
| ----- | ------ | ---- | ---- | ---------------------------- |
| x     | number | Yes   | Yes   | Uncalibrated acceleration along the x-axis of the device, in m/s2.   |
| y     | number | Yes   | Yes   | Uncalibrated acceleration along the y-axis of the device, in m/s2.   |
| z     | number | Yes   | Yes   | Uncalibrated acceleration along the z-axis of the device, in m/s2.   |
| biasX | number | Yes   | Yes   | Uncalibrated acceleration bias along the x-axis of the device, in m/s2. |
| biasY | number | Yes   | Yes   | Uncalibrated acceleration bias along the y-axis of the device, in m/s2.|
| biasZ | number | Yes   | Yes   | Uncalibrated acceleration bias along the z-axis of the device, in m/s2. |


## GravityResponse

Describes the gravity sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name  | Type  | Readable  | Writable  | Description                      |
| ---- | ------ | ---- | ---- | ------------------------ |
| x    | number | Yes   | Yes   | Gravitational acceleration along the x-axis of the device, in m/s2.|
| y    | number | Yes   | Yes   | Gravitational acceleration along the y-axis of the device, in m/s2.|
| z    | number | Yes   | Yes   | Gravitational acceleration along the z-axis of the device, in m/s2.|


## OrientationResponse

Describes the orientation sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name   | Type  | Readable  | Writable  | Description                      |
| ----- | ------ | ---- | ---- | ------------------------ |
| alpha | number | Yes   | Yes   | Rotation angle of the device around the z-axis, in rad.|
| beta  | number | Yes   | Yes   | Rotation angle of the device around the x-axis, in rad. |
| gamma | number | Yes   | Yes   | Rotation angle of the device around the y-axis, in rad. |


## RotationVectorResponse

Describes the rotation vector sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name  | Type  | Readable  | Writable  | Description       |
| ---- | ------ | ---- | ---- | --------- |
| x    | number | Yes   | Yes   | X-component of the rotation vector.|
| y    | number | Yes   | Yes   | Y-component of the rotation vector.|
| z    | number | Yes   | Yes   | Z-component of the rotation vector.|
| w    | number | Yes   | Yes   | Scalar.      |


## GyroscopeResponse

Describes the gyroscope sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name  | Type  | Readable  | Writable  | Description                 |
| ---- | ------ | ---- | ---- | ------------------- |
| x    | number | Yes   | Yes   | Angular velocity of rotation around the x-axis of the device, in rad/s.|
| y    | number | Yes   | Yes   | Angular velocity of rotation around the y-axis of the device, in rad/s.|
| z    | number | Yes   | Yes   | Angular velocity of rotation around the z-axis of the device, in rad/s.|


## GyroscopeUncalibratedResponse

Describes the uncalibrated gyroscope sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name   | Type  | Readable  | Writable  | Description                      |
| ----- | ------ | ---- | ---- | ------------------------ |
| x     | number | Yes   | Yes   | Uncalibrated angular velocity of rotation around the x-axis of the device, in rad/s.  |
| y     | number | Yes   | Yes   | Uncalibrated angular velocity of rotation around the y-axis of the device, in rad/s.  |
| z     | number | Yes   | Yes   | Uncalibrated angular velocity of rotation around the z-axis of the device, in rad/s.  |
| biasX | number | Yes   | Yes   | Uncalibrated angular velocity bias of rotation around the x-axis of the device, in rad/s.|
| biasY | number | Yes   | Yes   | Uncalibrated angular velocity bias of rotation around the y-axis of the device, in rad/s.|
| biasZ | number | Yes   | Yes   | Uncalibrated angular velocity bias of rotation around the z-axis of the device, in rad/s.|


## SignificantMotionResponse

Describes the significant motion sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name    | Type  | Readable  | Writable  | Description                                      |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| scalar | number | Yes   | Yes   | Intensity of a motion. This parameter specifies whether a device has a significant motion on three physical axes (X, Y, and Z). The value **0** means that the device does not have a significant motion, and **1** means the opposite.|


## ProximityResponse

Describes the proximity sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name      | Type  | Readable  | Writable  | Description                          |
| -------- | ------ | ---- | ---- | ---------------------------- |
| distance | number | Yes   | Yes   | Proximity between the visible object and the device monitor. The value **0** means the two are close to each other, and **1** means that they are far away from each other.|


## LightResponse

Describes the ambient light sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name       | Type  | Readable  | Writable  | Description         |
| --------- | ------ | ---- | ---- | ----------- |
| intensity | number | Yes   | Yes   | Illumination, in lux.|


## HallResponse

Describes the Hall effect sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name    | Type  | Readable  | Writable  | Description                               |
| ------ | ------ | ---- | ---- | --------------------------------- |
| status | number | Yes   | Yes   | Hall effect sensor status. This parameter specifies whether a magnetic field exists around a device. The value **0** means that a magnetic field exists around the device, and **1** means the opposite.|


## MagneticFieldResponse

Describes the magnetic field sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name  | Type  | Readable  | Writable  | Description                |
| ---- | ------ | ---- | ---- | ------------------ |
| x    | number | Yes   | Yes   | Magnetic field strength on the x-axis, in μT. |
| y    | number | Yes   | Yes   | Magnetic field strength on the y-axis, in μT. |
| z    | number | Yes   | Yes   | Magnetic field strength on the z-axis, in μT.|


## MagneticFieldUncalibratedResponse

Describes the uncalibrated magnetic field sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name   | Type  | Readable  | Writable  | Description                    |
| ----- | ------ | ---- | ---- | ---------------------- |
| x     | number | Yes   | Yes   | Uncalibrated magnetic field strength on the x-axis, in μT.  |
| y     | number | Yes   | Yes   | Uncalibrated magnetic field strength on the y-axis, in μT.  |
| z     | number | Yes   | Yes   | Uncalibrated magnetic field strength on the z-axis, in μT.  |
| biasX | number | Yes   | Yes   | Bias of the uncalibrated magnetic field strength on the x-axis, in μT.|
| biasY | number | Yes   | Yes   | Bias of the uncalibrated magnetic field strength on the y-axis, in μT.|
| biasZ | number | Yes   | Yes   | Bias of the uncalibrated magnetic field strength on the z-axis, in μT.|


## PedometerResponse

Describes the pedometer sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name   | Type  | Readable  | Writable  | Description      |
| ----- | ------ | ---- | ---- | -------- |
| steps | number | Yes   | Yes   | Number of steps a user has walked.|


## HumidityResponse

Describes the humidity sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name      | Type  | Readable  | Writable  | Description                                  |
| -------- | ------ | ---- | ---- | ------------------------------------ |
| humidity | number | Yes   | Yes   | Ambient relative humidity, in a percentage (%).|


## PedometerDetectionResponse

Describes the pedometer detection sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name    | Type  | Readable  | Writable  | Description                                      |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| scalar | number | Yes   | Yes   | Pedometer detection. This parameter specifies whether a user takes a step. The value **0** means that the user does not take a step, and **1** means that the user takes a step.|


## AmbientTemperatureResponse

Describes the ambient temperature sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name         | Type  | Readable  | Writable  | Description           |
| ----------- | ------ | ---- | ---- | ------------- |
| temperature | number | Yes   | Yes   | Ambient temperature, in degree Celsius.|


## BarometerResponse

Describes the barometer sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name      | Type  | Readable  | Writable  | Description          |
| -------- | ------ | ---- | ---- | ------------ |
| pressure | number | Yes   | Yes   | Atmospheric pressure, in pascal.|


## HeartRateResponse

Describes the heart rate sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name       | Type  | Readable  | Writable  | Description                   |
| --------- | ------ | ---- | ---- | --------------------- |
| heartRate | number | Yes   | Yes   | Heart rate, in beats per minute (bpm).|


## WearDetectionResponse

Describes the wear detection sensor data. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor


| Name   | Type  | Readable  | Writable  | Description                       |
| ----- | ------ | ---- | ---- | ------------------------- |
| value | number | Yes   | Yes   | Whether the device is being worn. The value **1** means that the device is being worn, and **0** means the opposite.|


## Options

Describes the sensor data reporting frequency.

**System capability**: SystemCapability.Sensors.Sensor

| Name      | Type  | Description                         |
| -------- | ------ | --------------------------- |
| interval | number | Frequency at which a sensor reports data. The default value is 200,000,000 ns.|

## RotationMatrixResponse

Describes the response for setting the rotation matrix.

**System capability**: SystemCapability.Sensors.Sensor

| Name         | Type               | Readable  | Writable  | Description   |
| ----------- | ------------------- | ---- | ---- | ----- |
| rotation    | Array&lt;number&gt; | Yes   | Yes   | Rotation matrix.|
| inclination | Array&lt;number&gt; | Yes   | Yes   | Inclination matrix.|


## CoordinatesOptions

Describes the coordinate options.

**System capability**: SystemCapability.Sensors.Sensor

| Name  | Type  | Readable  | Writable  | Description    |
| ---- | ------ | ---- | ---- | ------ |
| x    | number | Yes   | Yes   | X coordinate direction.|
| y    | number | Yes   | Yes   | Y coordinate direction.|


## GeomagneticResponse

Describes a geomagnetic response object. It extends from [Response](#response).

**System capability**: SystemCapability.Sensors.Sensor

| Name             | Type  | Readable  | Writable  | Description                       |
| --------------- | ------ | ---- | ---- | ------------------------- |
| x               | number | Yes   | Yes   | North component of the geomagnetic field.                 |
| y               | number | Yes   | Yes   | East component of the geomagnetic field.                 |
| z               | number | Yes   | Yes   | Vertical component of the geomagnetic field.                |
| geomagneticDip  | number | Yes   | Yes   | Magnetic dip, also called magnetic inclination, which is the angle measured from the horizontal plane to the magnetic field vector.      |
| deflectionAngle | number | Yes   | Yes   | Magnetic declination, which is the angle between true north (geographic north) and the magnetic north (the horizontal component of the field).|
| levelIntensity  | number | Yes   | Yes   | Horizontal intensity of the magnetic field vector field.                |
| totalIntensity  | number | Yes   | Yes   | Total intensity of the magnetic field vector.                 |

## LocationOptions

Describes the geographical location.

**System capability**: SystemCapability.Sensors.Sensor

| Name       | Type  | Readable  | Writable  | Description   |
| --------- | ------ | ---- | ---- | ----- |
| latitude  | number | Yes   | Yes   | Latitude.  |
| longitude | number | Yes   | Yes   | Longitude.  |
| altitude  | number | Yes   | Yes   | Altitude.|
