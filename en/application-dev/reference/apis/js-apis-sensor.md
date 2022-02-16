# Sensor

> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import sensor from '@ohos.sensor';
```


## Required Permissions

To use the pedometer sensor, you must declare the **ohos.permission.ACTIVITY_MOTION** permission.

To use the heart rate sensor, you must declare the **ohos.permission.READ_HEALTH_DATA** permission.

To use the acceleration sensor, you must declare the **ohos.permission.ACCELEROMETER** permission.

To use the gyroscope sensor, you must declare the **ohos.permission.GYROSCOPE** permission.


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER)

on(type:  sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: AsyncCallback&lt;AccelerometerResponse&gt;,options?: Options): void


Subscribes to data changes of the acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.


- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER**.|
  | callback | AsyncCallback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes| Callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION)

on(type:sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:AsyncCallback&lt;LinearAccelerometerResponse&gt;, options?: Options): void

Subscribes to data changes of the linear acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**.|
  | callback | AsyncCallback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes| Callback used to return the linear acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELEROMETER,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED)

on(type:sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback:AsyncCallback&lt;AccelerometerUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**.|
  | callback | AsyncCallback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes| Callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
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


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY)

on(type: sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, callback: AsyncCallback&lt;GravityResponse&gt;,options?: Options): void

Subscribes to data changes of the gravity sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GRAVITY**.|
  | callback | AsyncCallback&lt;[GravityResponse](#gravityresponse)&gt; | Yes| Callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE)

on(type: sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: AsyncCallback&lt;GyroscopeResponse&gt;, options?: Options): void

Subscribes to data changes of the gyroscope sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE**.|
  | callback | AsyncCallback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes| Callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED)

on(type:sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback:AsyncCallback&lt;GyroscopeUncalibratedResponse&gt;, options?: Options): void

Subscribes to data changes of the uncalibrated gyroscope sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**.|
  | callback | AsyncCallback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes| Callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
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


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION)

on(type: sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: AsyncCallback&lt;SignificantMotionResponse&gt;, options?: Options): void

Subscribes to data changes of the significant motion sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**.|
  | callback | AsyncCallback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes| Callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Scalar data: ' + data.scalar);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION)

on(type: sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: AsyncCallback&lt;PedometerDetectResponse&gt;, options?: Options): void

Subscribes to data changes of the pedometer detection sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**.|
  | callback | AsyncCallback&lt;[PedometerDetectResponse](#pedometerdetectresponse)&gt; | Yes| Callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Scalar data: ' + data.scalar);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER)

on(type: sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: AsyncCallback&lt;PedometerResponse&gt;, options?: Options): void

Subscribes to data changes of the pedometer sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER**.|
  | callback | AsyncCallback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes| Callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Steps: ' + data.steps);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE)

on(type:sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:AsyncCallback&lt;AmbientTemperatureResponse&gt;,  options?: Options): void

Subscribes to data changes of the ambient temperature sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**.|
  | callback | AsyncCallback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes| Callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Temperature: ' + data.temperature);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD)

on(type: sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: AsyncCallback&lt;MagneticFieldResponse&gt;,options?: Options): void

Subscribes to data changes of the magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**.|
  | callback | AsyncCallback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes| Callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED)

on(type:sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback:AsyncCallback&lt;MagneticFieldUncalibratedResponse&gt;, options: Options): void

Subscribes to data changes of the uncalibrated magnetic field sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**.|
  | callback | AsyncCallback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes| Callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
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


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY)

on(type:sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: AsyncCallback&lt;ProximityResponse&gt;,options?: Options): void

Subscribes to data changes of the proximity sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PROXIMITY**.|
  | callback | AsyncCallback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes| Callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Distance: ' + data.distance);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY)

on(type: sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: AsyncCallback&lt;HumidityResponse&gt;,options?: Options): void

Subscribes to data changes of the humidity sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HUMIDITY**.|
  | callback | AsyncCallback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes| Callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Humidity: ' + data.humidity);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER)

on(type:sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, callback: AsyncCallback&lt;BarometerResponse&gt;,options?: Options): void

Subscribes to data changes of the barometer sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_BAROMETER**.|
  | callback | AsyncCallback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes| Callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Atmospheric pressure: ' + data.pressure);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HALL)

on(type: sensor.SensorType.SENSOR_TYPE_ID_HALL, callback: AsyncCallback&lt;HallResponse&gt;, options?: Options): void

Subscribes to data changes of the Hall effect sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HALL**.|
  | callback | AsyncCallback&lt;[HallResponse](#hallresponse)&gt; | Yes| Callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HALL,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Status: ' + data.status);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT)

on(type:sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: AsyncCallback&lt;LightResponse&gt;, options?: Options): void

Subscribes to data changes of the ambient light sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**.|
  | callback | AsyncCallback&lt;[LightResponse](#lightresponse)&gt; | Yes| Callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info(' Illumination: ' + data.intensity);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION)

on(type: sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: AsyncCallback&lt;OrientationResponse&gt;, options?: Options): void

Subscribes to data changes of the orientation sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ORIENTATION**.|
  | callback | AsyncCallback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes| Callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR)

on(type:sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,callback:AsyncCallback&lt;RotationVectorResponse&gt;,options?: Options): void

Subscribes to data changes of the rotation vector sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**.|
  | callback | AsyncCallback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes| Callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
  },
      {interval: 10000000}
  );
  ```


## sensor.on(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION)

on(type: sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: AsyncCallback&lt;WearDetectionResponse&gt;,options?: Options): void

Subscribes to data changes of the wear detection sensor. If this API is called multiple times for the same application, the last call takes effect.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_WEAR_DETECTION**.|
  | callback | AsyncCallback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes| Callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**.|
  | options | [Options](#options) | No| Interval at which the callback is invoked to return the sensor data. The default value is 200,000,000 ns.|

- Example
  ```
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Wear status: ' + data.value);
  },
      {interval: 10000000}
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER)

once(type: sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: AsyncCallback&lt;AccelerometerResponse&gt;): void

Subscribes to only one data change of the acceleration sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER**.|
  | callback | AsyncCallback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | Yes| One-shot callback used to return the acceleration sensor data. The reported data type in the callback is **AccelerometerResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER,function(error,data){
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION)

once(type:sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:AsyncCallback&lt;LinearAccelerometerResponse&gt;): void

Subscribes to only one data change of the linear acceleration sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_LINEAR_ACCELERATION**.|
  | callback | AsyncCallback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | Yes| One-shot callback used to return the linear acceleration sensor data. The reported data type in the callback is **LinearAccelerometerResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED)

once(type:sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback:AsyncCallback&lt;AccelerometerUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated acceleration sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED**.|
  | callback | AsyncCallback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | Yes| One-shot callback used to return the uncalibrated acceleration sensor data. The reported data type in the callback is **AccelerometerUncalibratedResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('X-coordinate bias: ' + data.biasX);
      console.info('Y-coordinate bias: ' + data.biasY);
      console.info('Z-coordinate bias: ' + data.biasZ);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY)

once(type:sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, callback: AsyncCallback&lt;GravityResponse&gt;): void

Subscribes to only one data change of the gravity sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GRAVITY**.|
  | callback | AsyncCallback&lt;[GravityResponse](#gravityresponse)&gt; | Yes| One-shot callback used to return the gravity sensor data. The reported data type in the callback is **GravityResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE)

once(type: sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: AsyncCallback&lt;GyroscopeResponse&gt;): void

Subscribes to only one data change of the gyroscope sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE**.|
  | callback | AsyncCallback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | Yes| One-shot callback used to return the gyroscope sensor data. The reported data type in the callback is **GyroscopeResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED)

once(type:sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback:AsyncCallback&lt;GyroscopeUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated gyroscope sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED**.|
  | callback | AsyncCallback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | Yes| One-shot callback used to return the uncalibrated gyroscope sensor data. The reported data type in the callback is **GyroscopeUncalibratedResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('X-coordinate bias: ' + data.biasX);
      console.info('Y-coordinate bias: ' + data.biasY);
      console.info('Z-coordinate bias: ' + data.biasZ);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION)

once(type: sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION,callback:AsyncCallback&lt;SignificantMotionResponse&gt;): void

Subscribes to only one data change of the significant motion sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_SIGNIFICANT_MOTION**.|
  | callback | AsyncCallback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | Yes| One-shot callback used to return the significant motion sensor data. The reported data type in the callback is **SignificantMotionResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Scalar data: ' + data.scalar);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION)

once(type:sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,callback:AsyncCallback&lt;PedometerDetectResponse&gt;): void

Subscribes to only one data change of the pedometer detection sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER_DETECTION**.|
  | callback | AsyncCallback&lt;[PedometerDetectResponse](#pedometerdetectresponse)&gt; | Yes| One-shot callback used to return the pedometer detection sensor data. The reported data type in the callback is **PedometerDetectResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Scalar data: ' + data.scalar);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER)

once(type: sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: AsyncCallback&lt;PedometerResponse&gt;): void

Subscribes to only one data change of the pedometer sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PEDOMETER**.|
  | callback | AsyncCallback&lt;[PedometerResponse](#pedometerresponse)&gt; | Yes| One-shot callback used to return the pedometer sensor data. The reported data type in the callback is **PedometerResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Steps: ' + data.steps);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE)

once(type:sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:AsyncCallback&lt;AmbientTemperatureResponse&gt;): void

Subscribes to only one data change of the ambient temperature sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_TEMPERATURE**.|
  | callback | AsyncCallback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | Yes| One-shot callback used to return the ambient temperature sensor data. The reported data type in the callback is **AmbientTemperatureResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Temperature: ' + data.temperature);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD)

once(type: sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: AsyncCallback&lt;MagneticFieldResponse&gt;): void

Subscribes to only one data change of the magnetic field sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD**.|
  | callback | AsyncCallback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | Yes| One-shot callback used to return the magnetic field sensor data. The reported data type in the callback is **MagneticFieldResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED)

once(type:sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback:AsyncCallback&lt;MagneticFieldUncalibratedResponse&gt;): void

Subscribes to only one data change of the uncalibrated magnetic field sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED**.|
  | callback | AsyncCallback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | Yes| One-shot callback used to return the uncalibrated magnetic field sensor data. The reported data type in the callback is **MagneticFieldUncalibratedResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
      console.info('X-coordinate bias: ' + data.biasX);
      console.info('Y-coordinate bias: ' + data.biasY);
      console.info('Z-coordinate bias: ' + data.biasZ);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY)

once(type: sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: AsyncCallback&lt;ProximityResponse&gt;): void

Subscribes to only one data change of the proximity sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_PROXIMITY**.|
  | callback | AsyncCallback&lt;[ProximityResponse](#proximityresponse)&gt; | Yes| One-shot callback used to return the proximity sensor data. The reported data type in the callback is **ProximityResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Distance: ' + data.distance);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY)

once(type: sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: AsyncCallback&lt;HumidityResponse&gt;): void

Subscribes to only one data change of the humidity sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HUMIDITY**.|
  | callback | AsyncCallback&lt;[HumidityResponse](#humidityresponse)&gt; | Yes| One-shot callback used to return the humidity sensor data. The reported data type in the callback is **HumidityResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Humidity: ' + data.humidity);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER)

once(type: sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, callback: AsyncCallback&lt;BarometerResponse&gt;): void

Subscribes to only one data change of the barometer sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_BAROMETER**.|
  | callback | AsyncCallback&lt;[BarometerResponse](#barometerresponse)&gt; | Yes| One-shot callback used to return the barometer sensor data. The reported data type in the callback is **BarometerResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Atmospheric pressure: ' + data.pressure);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HALL)

once(type: sensor.SensorType.SENSOR_TYPE_ID_HALL, callback:   AsyncCallback&lt;HallResponse&gt;): void

Subscribes to only one data change of the Hall effect sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HALL**.|
  | callback | AsyncCallback&lt;[HallResponse](#hallresponse)&gt; | Yes| One-shot callback used to return the Hall effect sensor data. The reported data type in the callback is **HallResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HALL, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('Status: ' + data.status);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT)

once(type: sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: AsyncCallback&lt;LightResponse&gt;): void

Subscribes to only one data change of the ambient light sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_AMBIENT_LIGHT**.|
  | callback | AsyncCallback&lt;[LightResponse](#lightresponse)&gt; | Yes| One-shot callback used to return the ambient light sensor data. The reported data type in the callback is **LightResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info(' Illumination: ' + data.intensity);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION)

once(type: sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: AsyncCallback&lt;OrientationResponse&gt;): void

Subscribes to only one data change of the orientation sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ORIENTATION**.|
  | callback | AsyncCallback&lt;[OrientationResponse](#orientationresponse)&gt; | Yes| One-shot callback used to return the orientation sensor data. The reported data type in the callback is **OrientationResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR)

once(type: sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: AsyncCallback&lt;RotationVectorResponse&gt;): void

Subscribes to only one data change of the rotation vector sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_ROTATION_VECTOR**.|
  | callback | AsyncCallback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | Yes| One-shot callback used to return the rotation vector sensor data. The reported data type in the callback is **RotationVectorResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info('X-coordinate component: ' + data.x);
      console.info('Y-coordinate component: ' + data.y);
      console.info('Z-coordinate component: ' + data.z);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE)

once(type: sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: AsyncCallback&lt;HeartRateResponse&gt;): void

Subscribes to only one data change of the heart rate sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_HEART_RATE**.|
  | callback | AsyncCallback&lt;[HeartRateResponse](#heartrateresponse)&gt; | Yes| One-shot callback used to return the heart rate sensor data. The reported data type in the callback is **HeartRateResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, function(error, data) {
      if (error) {
          console.error("Subscription failed. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info("Heart rate: " + data.heartRate);
    }
  );
  ```


## sensor.once(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION)

once(type: sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: AsyncCallback&lt;WearDetectionResponse&gt;): void

Subscribes to only one data change of the wear detection sensor.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to subscribe to, which is **SENSOR_TYPE_ID_WEAR_DETECTION**.|
  | callback | AsyncCallback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | Yes| One-shot callback used to return the wear detection sensor data. The reported data type in the callback is **WearDetectionResponse**.|

- Example
  ```
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, function(error, data) {
      if (error) {
          console.error("Failed to register data, error code is" + error.code + ", message: " + error.message);
          return;
      }
      console.info("Wear status: "+ data.value);
    }
  );
  ```


## sensor.off

off(type: SensorType, callback?: AsyncCallback&lt;void&gt;): void

Unsubscribes from sensor data changes.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [SensorType](#sensortype) | Yes| Type of the sensor to unsubscribe from.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

- Example
  ```
  sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, function(error) {
      if (error) {
          console.error("Failed to unsubscribe from acceleration sensor data. Error code: " + error.code + "; message: " + error.message);
          return;
      }
      console.info("Succeeded in unsubscribing from acceleration sensor data.");
    }
  );
  
  ```


## sensor.getGeomagneticField

getGeomagneticField(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback&lt;GeomagneticResponse&gt;): void

Obtains the geomagnetic field of a geographic location. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | locationOptions | [LocationOptions](#locationoptions) | Yes| Geographic location.|
  | timeMillis | number | Yes| Time for obtaining the magnetic declination, in milliseconds.|
  | callback | AsyncCallback&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Yes| Callback used to return the geomagnetic field.|

- Example
  ```
  sensor.getGeomagneticField([80, 0, 0], {'timeMillis':1580486400000}, function(err, data)  {
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

Obtains the geomagnetic field of a geographic location. This method uses a callback to return the result.

- Parameters
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | locationOptions | [LocationOptions](#locationoptions) | Yes| Geographic location.|
  | timeMillis | number | Yes| Time for obtaining the magnetic declination, in milliseconds.|

- Return value
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | Callback used to return the geomagnetic field.|

- Example
  ```
  const promise = sensor.getGeomagneticField([80, 0, 0], {'timeMillis':1580486400000});
      promise.then((data) => {
          console.info('sensor_getGeomagneticField_promise x: ' + data.x + ',y: ' + data.y + ',z: ' +
  	             data.z + ',geomagneticDip: ' + data.geomagneticDip + ',deflectionAngle: ' + data.deflectionAngle +
  		     ',levelIntensity: ' + data.levelIntensity + ',totalIntensity: ' + data.totalIntensity);
      }).catch((reason) => {
          console.info('Operation failed.');
  })
  ```


## SensorType

Enumerates the sensor types.


| Name| Default Value| Description|
| -------- | -------- | -------- |
| SENSOR_TYPE_ID_ACCELEROMETER | 1 | Acceleration sensor.|
| SENSOR_TYPE_ID_GYROSCOPE | 2 | Gyroscope sensor.|
| SENSOR_TYPE_ID_AMBIENT_LIGHT | 5 | Ambient light sensor.|
| SENSOR_TYPE_ID_MAGNETIC_FIELD | 6 | Magnetic field sensor.|
| SENSOR_TYPE_ID_BAROMETER | 8 | Barometer sensor.|
| SENSOR_TYPE_ID_HALL | 10 | Hall effect sensor.|
| SENSOR_TYPE_ID_PROXIMITY | 12 | Proximity sensor.|
| SENSOR_TYPE_ID_HUMIDITY | 13 | Humidity sensor.|
| SENSOR_TYPE_ID_ORIENTATION | 256 | Orientation sensor.|
| SENSOR_TYPE_ID_GRAVITY | 257 | Gravity sensor.|
| SENSOR_TYPE_ID_LINEAR_ACCELERATION | 258 | Linear acceleration sensor.|
| SENSOR_TYPE_ID_ROTATION_VECTOR | 259 | Rotation vector sensor.|
| SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | 260 | Ambient temperature sensor.|
| SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | 261 | Uncalibrated magnetic field sensor.|
| SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | 263 | Uncalibrated gyroscope sensor.|
| SENSOR_TYPE_ID_SIGNIFICANT_MOTION | 264 | Significant motion sensor.|
| SENSOR_TYPE_ID_PEDOMETER_DETECTION | 265 | Pedometer detection sensor.|
| SENSOR_TYPE_ID_PEDOMETER | 266 | Pedometer sensor.|
| SENSOR_TYPE_ID_HEART_RATE | 278 | Heart rate sensor.|
| SENSOR_TYPE_ID_WEAR_DETECTION | 280 | Wear detection sensor.|
| SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | 281 | Uncalibrated acceleration sensor.|


## Response

Describes the timestamp of the sensor data.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| timestamp | number | Yes| Yes| Timestamp when the sensor reports data.|


## AccelerometerResponse

Describes the acceleration sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| Acceleration along the x-axis of the device, in m/s2.|
| y | number | Yes| Yes| Acceleration along the y-axis of the device, in m/s2.|
| z | number | Yes| Yes| Acceleration along the z-axis of the device, in m/s2.|


## LinearAccelerometerResponse

Describes the linear acceleration sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| Linear acceleration along the x-axis of the device, in m/s2.|
| y | number | Yes| Yes| Linear acceleration along the y-axis of the device, in m/s2.|
| z | number | Yes| Yes| Linear acceleration along the z-axis of the device, in m/s2.|


## AccelerometerUncalibratedResponse

Describes the uncalibrated acceleration sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| Uncalibrated acceleration along the x-axis of the device, in m/s2.|
| y | number | Yes| Yes| Uncalibrated acceleration along the y-axis of the device, in m/s2.|
| z | number | Yes| Yes| Uncalibrated acceleration along the z-axis of the device, in m/s2.|
| biasX | number | Yes| Yes| Uncalibrated acceleration bias along the x-axis of the device, in m/s2.|
| biasY | number | Yes| Yes| Uncalibrated acceleration bias along the y-axis of the device, in m/s2.|
| biasZ | number | Yes| Yes| Uncalibrated acceleration bias along the z-axis of the device, in m/s2.|


## GravityResponse

Describes the gravity sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| Gravitational acceleration along the x-axis of the device, in m/s2.|
| y | number | Yes| Yes| Gravitational acceleration along the y-axis of the device, in m/s2.|
| z | number | Yes| Yes| Gravitational acceleration along the z-axis of the device, in m/s2.|


## OrientationResponse

Describes the orientation sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| Rotation angle of the device around the x-axis, in rad.|
| y | number | Yes| Yes| Rotation angle of the device around the y-axis, in rad.|
| z | number | Yes| Yes| Rotation angle of the device around the z-axis, in rad.|


## RotationVectorResponse

Describes the rotation vector sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| X-component of the rotation vector.|
| y | number | Yes| Yes| Y-component of the rotation vector.|
| z | number | Yes| Yes| Z-component of the rotation vector.|


## GyroscopeResponse

Describes the gyroscope sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| Angular velocity of rotation around the x-axis of the device, in rad/s.|
| y | number | Yes| Yes| Angular velocity of rotation around the y-axis of the device, in rad/s.|
| z | number | Yes| Yes| Angular velocity of rotation around the z-axis of the device, in rad/s.|


## GyroscopeUncalibratedResponse

Describes the uncalibrated gyroscope sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| Uncalibrated angular velocity of rotation around the x-axis of the device, in rad/s.|
| y | number | Yes| Yes| Uncalibrated angular velocity of rotation around the y-axis of the device, in rad/s.|
| z | number | Yes| Yes| Uncalibrated angular velocity of rotation around the z-axis of the device, in rad/s.|
| biasX | number | Yes| Yes| Uncalibrated angular velocity bias of rotation around the x-axis of the device, in rad/s.|
| biasY | number | Yes| Yes| Uncalibrated angular velocity bias of rotation around the y-axis of the device, in rad/s.|
| biasZ | number | Yes| Yes| Uncalibrated angular velocity bias of rotation around the z-axis of the device, in rad/s.|


## SignificantMotionResponse

Describes the significant motion sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| scalar | number | Yes| Yes| Intensity of a motion. This parameter specifies whether a device has a significant motion on three physical axes (X, Y, and Z). The value **0** means that the device does not have a significant motion, and **1** means the opposite.|


## ProximityResponse

Describes the proximity sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| distance | number | Yes| Yes| Proximity between the visible object and the device monitor. The value **0** means the two are close to each other, and **1** means that they are far away from each other.|


## LightResponse

Describes the ambient light sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| intensity | number | Yes| Yes| Illumination, in lux.|


## HallResponse

Describes the Hall effect sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| status | number | Yes| Yes| Hall effect sensor status. This parameter specifies whether a magnetic field exists around a device. The value **0** means that a magnetic field exists around the device, and **1** means the opposite.|


## MagneticFieldResponse

Describes the magnetic field sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| Magnetic field strength on the x-axis, in μT.|
| y | number | Yes| Yes| Magnetic field strength on the y-axis, in μT.|
| z | number | Yes| Yes| Magnetic field strength on the z-axis, in μT.|


## MagneticFieldUncalibratedResponse

Describes the uncalibrated magnetic field sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| Uncalibrated magnetic field strength on the x-axis, in μT.|
| y | number | Yes| Yes| Uncalibrated magnetic field strength on the y-axis, in μT.|
| z | number | Yes| Yes| Uncalibrated magnetic field strength on the z-axis, in μT.|
| biasX | number | Yes| Yes| Bias of the uncalibrated magnetic field strength on the x-axis, in μT.|
| biasY | number | Yes| Yes| Bias of the uncalibrated magnetic field strength on the y-axis, in μT.|
| biasZ | number | Yes| Yes| Bias of the uncalibrated magnetic field strength on the z-axis, in μT.|


## PedometerResponse

Describes the pedometer sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| steps | number | Yes| Yes| Number of steps a user has walked.|


## HumidityResponse

Describes the humidity sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| humidity | number | Yes| Yes| Ambient relative humidity, in a percentage (%).|


## PedometerDetectResponse

Describes the pedometer detection sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| scalar | number | Yes| Yes| Pedometer detection. This parameter specifies whether a user takes a step. The value **0** means that the user does not take a step, and **1** means that the user takes a step.|


## AmbientTemperatureResponse

Describes the ambient temperature sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| temperature | number | Yes| Yes| Ambient temperature, in degree Celsius.|


## BarometerResponse

Describes the barometer sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| pressure | number | Yes| Yes| Atmospheric pressure, in pascal.|


## HeartRateResponse

Describes the heart rate sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| heartRate | number | Yes| Yes| Heart rate, in beats per minute (bpm).|


## WearDetectionResponse

Describes the wear detection sensor data. It extends from [Response](#response).


| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| value | number | Yes| Yes| Whether the device is being worn. The value **1** means that the device is being worn, and **0** means the opposite.|


## Options

Describes the sensor data reporting frequency.

| Name| Type| Description|
| -------- | -------- | -------- |
| interval | number | Frequency at which a sensor reports data. The default value is 200,000,000 ns.|


## GeomagneticResponse

Describes a geomagnetic response object. It extends from [Response](#response).

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| x | number | Yes| Yes| North component of the geomagnetic field.|
| y | number | Yes| Yes| East component of the geomagnetic field.|
| z | number | Yes| Yes| Vertical component of the geomagnetic field.|
| geomagneticDip | number | Yes| Yes| Magnetic dip, also called magnetic inclination, which is the angle measured from the horizontal plane to the magnetic field vector.|
| deflectionAngle | number | Yes| Yes| Magnetic declination, which is the angle between true north (geographic north) and the magnetic north (the horizontal component of the field).|
| levelIntensity | number | Yes| Yes| Horizontal intensity of the magnetic field vector field.|
| totalIntensity | number | Yes| Yes| Total intensity of the magnetic field vector.|


## LocationOptions

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | Yes| Yes| Latitude.|
| longitude | number | Yes| Yes| Longitude.|
| altitude | number | Yes| Yes| Altitude.|
