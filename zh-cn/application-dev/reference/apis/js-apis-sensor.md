# 传感器

## 模块说明

sensor模块提供订阅传感器数据基本能力，包括订阅、取消订阅传感器数据，获取传感器列表，以及通用的传感器算法接口如通过气压值计算海拔高度、通过旋转矩阵计算设备方向等。

传感器是指用于侦测环境中所发生事件或变化，并将此消息发送至其他电子设备（如中央处理器）的设备，通常由敏感组件和转换组件组成。传感器是实现物联网智能化的重要基石，为实现全场景智慧化战略，支撑“1+8+N”产品需求，需要构筑统一的传感器管理框架，达到为各产品/业务提供低时延、低功耗的感知数据的目的。根据用途可分为以下六大类：

- 运动类：加速度、陀螺仪、重力、线性加速度传感器等
- 姿态类：旋转矢量、方向传感器等
- 环境类：磁力计、气压、湿度传感器等
- 光线类：环境光、接近光、色温传感器等
- 健康类：心率、心跳传感器等
- 其它：霍尔传感器、手握传感器等

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import sensor from '@ohos.sensor';
```

## sensor.on

### ACCELEROMETER

on(type:  SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback&lt;AccelerometerResponse&gt;,options?: Options): void

监听加速度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**需要权限**：ohos.permission.ACCELEROMETER ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER。 |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | 是    | 注册加速度传感器的回调函数，上报的数据类型为AccelerometerResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
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

监听线性加速度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**需要权限**：ohos.permission.ACCELEROMETER ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的线性加速度传感器类型为SENSOR_TYPE_ID_LINEAR_ACCELERATION。 |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | 是    | 注册线性加速度传感器的回调函数，上报的数据类型为LinearAccelerometerResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
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

监听未校准加速度计传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**需要权限**：ohos.permission.ACCELEROMETER ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的未校准加速度计传感器类型为SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED。 |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | 是    | 注册未校准加速度计传感器的回调函数，上报的数据类型为AccelerometerUncalibratedResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
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

监听重力传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                    |
| -------- | ---------------------------------------- | ---- | ------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的重力传感器类型为SENSOR_TYPE_ID_GRAVITY。   |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | 是    | 注册重力传感器的回调函数，上报的数据类型为GravityResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。        |

**示例：** 
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

监听陀螺仪传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**需要权限**：ohos.permission.GYROSCOPE ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE。   |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | 是    | 注册陀螺仪传感器的回调函数，上报的数据类型为GyroscopeResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
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

监听未校准陀螺仪传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**需要权限**：ohos.permission.GYROSCOPE ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的未校准陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED。 |
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | 是    | 注册未校准陀螺仪传感器的回调函数，上报的数据类型为GyroscopeUncalibratedResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率。                           |

**示例：** 
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

监听大幅动作传感器数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的大幅动作传感器类型为SENSOR_TYPE_ID_SIGNIFICANT_MOTION。 |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | 是    | 注册有效运动传感器的回调函数，上报的数据类型为SignificantMotionResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION,function(data){
      console.info('Scalar data: ' + data.scalar);
  },
      {interval: 10000000}
  );
  ```

### PEDOMETER_DETECTION

on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback&lt;PedometerDetectionResponse&gt;, options?: Options): void

监听计步检测传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的计步检测传感器类型为SENSOR_TYPE_ID_PEDOMETER_DETECTION。 |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | 是    | 注册计步检测传感器的回调函数，上报的数据类型为PedometerDetectionResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,function(data){
      console.info('Scalar data: ' + data.scalar);
  },
      {interval: 10000000}
  );
  ```

### PEDOMETER

on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback&lt;PedometerResponse&gt;, options?: Options): void

监听计步传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**需要权限**：ohos.permission.ACTIVITY_MOTION 

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的计步传感器类型为SENSOR_TYPE_ID_PEDOMETER。   |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | 是    | 注册计步传感器的回调函数，上报的数据类型为PedometerResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。          |

**示例：** 
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER,function(data){
      console.info('Steps: ' + data.steps);
  },
      {interval: 10000000}
  );
  ```

### AMBIENT_TEMPERATURE

on(type:SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:Callback&lt;AmbientTemperatureResponse&gt;,  options?: Options): void

监听环境温度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的环境温度传感器类型为SENSOR_TYPE_ID_AMBIENT_TEMPERATURE。 |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | 是    | 注册环境温度传感器的回调函数，上报的数据类型为AmbientTemperatureResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,function(data){
      console.info('Temperature: ' + data.temperature);
  },
      {interval: 10000000}
  );
  ```

### MAGNETIC_FIELD

on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;,options?: Options): void

监听磁场传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD。 |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | 是    | 注册磁场传感器的回调函数，上报的数据类型为MagneticFieldResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
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

监听未校准磁场传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的未校准磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED。 |
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | 是    | 注册未校准磁场传感器的回调函数，上报的数据类型为MagneticFieldUncalibratedResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
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

监听接近光传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的接近光传感器类型为SENSOR_TYPE_ID_PROXIMITY。   |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | 是    | 注册接近光传感器的回调函数，上报的数据类型为ProximityResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY,function(data){
      console.info('Distance: ' + data.distance);
  },
      {interval: 10000000}
  );
  ```

### HUMIDITY

on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback&lt;HumidityResponse&gt;,options?: Options): void

监听湿度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                     |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的湿度传感器类型为SENSOR_TYPE_ID_HUMIDITY。   |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | 是    | 注册湿度传感器的回调函数，上报的数据类型为HumidityResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。         |

**示例：** 
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY,function(data){
      console.info('Humidity: ' + data.humidity);
  },
      {interval: 10000000}
  );
  ```

### BAROMETER

on(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback&lt;BarometerResponse&gt;,options?: Options): void

监听气压计传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的气压计传感器类型为SENSOR_TYPE_ID_BAROMETER。   |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | 是    | 注册气压计传感器的回调函数，上报的数据类型为BarometerResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER,function(data){
      console.info('Atmospheric pressure: ' + data.pressure);
  },
      {interval: 10000000}
  );
  ```

### HALL

on(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback&lt;HallResponse&gt;, options?: Options): void

监听霍尔传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的霍尔传感器类型为SENSOR_TYPE_ID_HALL。         |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | 是    | 注册霍尔传感器的回调函数，上报的数据类型为&nbsp;HallResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HALL,function(data){
      console.info('Status: ' + data.status);
  },
      {interval: 10000000}
  );
  ```

### AMBIENT_LIGHT

on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;, options?: Options): void

监听环境光传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的环境光传感器类型为SENSOR_TYPE_ID_AMBIENT_LIGHT。 |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | 是    | 注册环境光传感器的回调函数，上报的数据类型为LightResponse。     |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
  ```js
  sensor.on(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT,function(data){
      console.info(' Illumination: ' + data.intensity);
  },
      {interval: 10000000}
  );
  ```

### ORIENTATION

on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback&lt;OrientationResponse&gt;, options?: Options): void

监听方向传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的方向传感器类型为SENSOR_TYPE_ID_ORIENTATION   |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | 是    | 注册方向传感器的回调函数，上报的数据类型为OrientationResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
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

监听心率传感器数据变化一次。

**需要权限**：ohos.permission.READ_HEALTH_DATA 

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的心率传感器类型为SENSOR_TYPE_ID_HEART_RATE。   |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | 是    | 注册一次心率传感器的回调函数，上报的数据类型为HeartRateResponse。 |

**示例：** 

```js
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE,function(data){
    console.info("Heart rate: " + data.heartRate);
},
    {interval: 10000000}
);
```

### ROTATION_VECTOR

on(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,callback: Callback&lt;RotationVectorResponse&gt;,options?: Options): void

监听旋转矢量传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的旋转矢量传感器类型为SENSOR_TYPE_ID_ROTATION_VECTOR。 |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | 是    | 注册旋转矢量传感器的回调函数，上报的数据类型为RotationVectorResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
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

监听佩戴检测传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要订阅的佩戴检测传感器类型为SENSOR_TYPE_ID_WEAR_DETECTION。 |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | 是    | 注册佩戴检测传感器的回调函数，上报的数据类型为WearDetectionResponse。 |
| options  | [Options](#options)                      | 否    | 可选参数列表，设置上报频率，默认值为200000000ns。           |

**示例：** 
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

监听加速度传感器的数据变化一次。

**需要权限**：ohos.permission.ACCELEROMETER ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER。   |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | 是    | 注册一次加速度传感器的回调函数，上报的数据类型为AccelerometerResponse。 |

**示例：** 
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

监听线性加速度传感器数据变化一次。

**需要权限**：ohos.permission.ACCELEROMETER ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 线性加速度传感器类型为SENSOR_TYPE_ID_LINEAR_ACCELERATION。 |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | 是    | 注册一次线性加速度传感器的回调函数，上报的数据类型为LinearAccelerometerResponse。 |

**示例：** 
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

监听未校准加速度传感器的数据变化一次。

**需要权限**：ohos.permission.ACCELEROMETER ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 未校准加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED。 |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | 是    | 注册一次未校准加速度传感器的回调函数，上报的数据类型为AccelerometerUncalibratedResponse。 |

**示例：** 
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

监听重力传感器的数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                      |
| -------- | ---------------------------------------- | ---- | --------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 重力传感器类型为SENSOR_TYPE_ID_GRAVITY。         |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | 是    | 注册一次重力传感器的回调函数，上报的数据类型为GravityResponse。 |

**示例：** 
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

监听陀螺仪传感器的数据变化一次。

**需要权限**：ohos.permission.GYROSCOPE ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE。       |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | 是    | 注册一次陀螺仪传感器的回调函数，上报的数据类型为GyroscopeResponse。 |

**示例：** 
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

监听未校准陀螺仪传感器的数据变化一次。

**需要权限**：ohos.permission.GYROSCOPE ，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 未校准陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED。 |
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | 是    | 注册一次未校准陀螺仪传感器的回调函数，上报的数据类型为GyroscopeUncalibratedResponse。 |

**示例：** 
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

监听有效运动传感器的数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 有效运动传感器类型为SENSOR_TYPE_ID_SIGNIFICANT_MOTION。 |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | 是    | 注册一次有效运动传感器的回调函数，上报的数据类型为SignificantMotionResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, function(data) {
      console.info('Scalar data: ' + data.scalar);
    }
  );
  ```

### PEDOMETER_DETECTION

once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION,callback: Callback&lt;PedometerDetectionResponse&gt;): void

监听计步检测传感器数据变化一次。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 计步检测传感器类型为SENSOR_TYPE_ID_PEDOMETER_DETECTION。 |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | 是    | 注册一次计步检测传感器的回调函数，上报的数据类型为PedometerDetectionResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, function(data) {
      console.info('Scalar data: ' + data.scalar);
    }
  );
  ```

### PEDOMETER

once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback&lt;PedometerResponse&gt;): void

监听计步器传感器数据变化一次。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 计步传感器类型为SENSOR_TYPE_ID_PEDOMETER。        |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | 是    | 注册一次计步传感器的回调函数，上报的数据类型为PedometerResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, function(data) {
      console.info('Steps: ' + data.steps);
    }
  );
  ```

### AMBIENT_TEMPERATURE

once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback: Callback&lt;AmbientTemperatureResponse&gt;): void

监听环境温度传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 环境温度传感器类型为SENSOR_TYPE_ID_AMBIENT_TEMPERATURE。 |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | 是    | 注册一次环境温度传感器的回调函数，上报的数据类型为AmbientTemperatureResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, function(data) {
      console.info('Temperature: ' + data.temperature);
    }
  );
  ```

### MAGNETIC_FIELD

once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback&lt;MagneticFieldResponse&gt;): void

监听磁场传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD。   |
| callback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | 是    | 注册一次磁场传感器的回调函数，上报的数据类型为MagneticFieldResponse。 |

**示例：** 
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

监听未校准磁场传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 未校准磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED。 |
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | 是    | 注册一次未校准磁场传感器的回调函数，上报的数据类型为MagneticFieldUncalibratedResponse。 |

**示例：** 
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

监听接近光传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 接近光传感器类型为SENSOR_TYPE_ID_PROXIMITY。       |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | 是    | 注册一次接近光传感器的回调函数，上报的数据类型为ProximityResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, function(data) {
      console.info('Distance: ' + data.distance);
    }
  );
  ```

### HUMIDITY

once(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback&lt;HumidityResponse&gt;): void

监听湿度传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 湿度传感器类型为SENSOR_TYPE_ID_HUMIDITY。         |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | 是    | 注册一次湿度传感器的回调函数，上报的数据类型为HumidityResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, function(data) {
      console.info('Humidity: ' + data.humidity);
    }
  );
  ```

### BAROMETER

once(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback&lt;BarometerResponse&gt;): void

监听气压计传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 气压计传感器类型为SENSOR_TYPE_ID_BAROMETER。       |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | 是    | 注册一次气压计传感器的回调函数，上报的数据类型为BarometerResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, function(data) {
      console.info('Atmospheric pressure: ' + data.pressure);
    }
  );
  ```

### HALL

once(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback&lt;HallResponse&gt;): void

监听霍尔传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| type     | [SensorType](#sensortype)                | 是    | 霍尔传感器类型为SENSOR_TYPE_ID_HALL。         |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | 是    | 注册一次霍尔传感器的回调函数，上报的数据类型为HallResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HALL, function(data) {
      console.info('Status: ' + data.status);
    }
  );
  ```

### AMBIENT_LIGHT

once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback&lt;LightResponse&gt;): void

监听环境光传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                     |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 环境光传感器类型为SENSOR_TYPE_ID_AMBIENT_LIGHT。 |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | 是    | 注册一次环境光传感器的回调函数，上报的数据类型为LightResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, function(data) {
      console.info(' Illumination: ' + data.intensity);
    }
  );
  ```

### ORIENTATION

once(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback&lt;OrientationResponse&gt;): void

监听方向传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 方向传感器类型为SENSOR_TYPE_ID_ORIENTATION。      |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | 是    | 注册一次方向传感器的回调函数，上报的数据类型为OrientationResponse。 |

**示例：** 
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

监听旋转矢量传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 旋转矢量传感器类型为SENSOR_TYPE_ID_ROTATION_VECTOR。 |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | 是    | 注册一次旋转矢量传感器的回调函数，上报的数据类型为RotationVectorResponse。 |

**示例：** 
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

监听心率传感器数据变化一次。

**需要权限**：ohos.permission.READ_HEALTH_DATA 

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 心率传感器类型为SENSOR_TYPE_ID_HEART_RATE。       |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | 是    | 注册一次心率传感器的回调函数，上报的数据类型为HeartRateResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, function(data) {
      console.info("Heart rate: " + data.heartRate);
    }
  );
  ```

### WEAR_DETECTION

once(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback&lt;WearDetectionResponse&gt;): void

监听佩戴检测传感器数据变化一次。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 佩戴检测传感器类型为SENSOR_TYPE_ID_WEAR_DETECTION。 |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | 是    | 注册一次穿戴检测传感器的回调函数，上报的数据类型为WearDetectionResponse。 |

**示例：** 
  ```js
  sensor.once(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, function(data) {
      console.info("Wear status: "+ data.value);
    }
  );
  ```

## sensor.off

### ACCELEROMETER

off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback?: Callback&lt;AccelerometerResponse&gt;): void

取消订阅传感器数据。

**需要权限**：ohos.permission.ACCELEROMETER, 该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER。 |
| callback | Callback&lt;[AccelerometerResponse](#accelerometerresponse)&gt; | 是    | 取消注册加速度传感器的回调函数，上报的数据类型为AccelerometerResponse。 |

**示例：** 

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

取消订阅传感器数据。

**需要权限**：ohos.permission.ACCELEROMETER, 该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的未校准加速度计传感器类型为SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED。 |
| callback | Callback&lt;[AccelerometerUncalibratedResponse](#accelerometeruncalibratedresponse)&gt; | 是    | 取消注册未校准加速度计传感器的回调函数，上报的数据类型为AccelerometerUncalibratedResponse。 |

**示例：** 

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

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的环境光传感器类型为SENSOR_TYPE_ID_AMBIENT_LIGHT。 |
| callback | Callback&lt;[LightResponse](#lightresponse)&gt; | 是    | 取消注册环境光传感器的回调函数，上报的数据类型为LightResponse。   |

**示例：** 

```js
function callback(data) {
    console.info(' Illumination: ' + data.intensity);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback);
```

### AMBIENT_TEMPERATURE

off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback?: Callback&lt;AmbientTemperatureResponse&gt;): void

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的环境温度传感器类型为SENSOR_TYPE_ID_AMBIENT_TEMPERATURE。 |
| callback | Callback&lt;[AmbientTemperatureResponse](#ambienttemperatureresponse)&gt; | 是    | 取消注册环境温度传感器的回调函数，上报的数据类型为AmbientTemperatureResponse。 |

**示例：** 

```js
function callback(data) {
     console.info('Temperature: ' + data.temperature);
}
sensor.off( sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback);
```

### AMBIENT_TEMPERATURE

off(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback?: Callback&lt;BarometerResponse&gt;): void

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的气压计传感器类型为SENSOR_TYPE_ID_BAROMETER。 |
| callback | Callback&lt;[BarometerResponse](#barometerresponse)&gt; | 是    | 取消注册气压计传感器的回调函数，上报的数据类型为BarometerResponse。 |

**示例：** 

```js
function callback(data) {
     console.info('Atmospheric pressure: ' + data.pressure);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, callback);
```

### GRAVITY

off(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback?: Callback&lt;GravityResponse&gt;): void

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的重力传感器类型为SENSOR_TYPE_ID_GRAVITY。    |
| callback | Callback&lt;[GravityResponse](#gravityresponse)&gt; | 是    | 取消注册注册重力传感器的回调函数，上报的数据类型为GravityResponse。 |

**示例：** 

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

取消订阅传感器数据。

**需要权限**：ohos.permission.GYROSCOPE, 该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE。 |
| callback | Callback&lt;[GyroscopeResponse](#gyroscoperesponse)&gt; | 是    | 取消注册陀螺仪传感器的回调函数，上报的数据类型为GyroscopeResponse。 |

**示例：** 

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

取消订阅传感器数据。

**需要权限**：ohos.permission.GYROSCOPE, 该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的未校准陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED。 |
| callback | Callback&lt;[GyroscopeUncalibratedResponse](#gyroscopeuncalibratedresponse)&gt; | 是    | 取消注册未校准陀螺仪传感器的回调函数，上报的数据类型为GyroscopeUncalibratedResponse。 |

**示例：** 

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

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的霍尔传感器类型为SENSOR_TYPE_ID_HALL。       |
| callback | Callback&lt;[HallResponse](#hallresponse)&gt; | 是    | 取消注册霍尔传感器的回调函数，上报的数据类型为&nbsp;HallResponse。 |

**示例：** 

```js
function callback(data) {
    console.info('Status: ' + data.status);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HALL, callback);
```

### HEART_RATE

off(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback?: Callback&lt;HeartRateResponse&gt;): void

取消订阅传感器数据。

**需要权限**：ohos.permission.READ_HEALTH_DATA

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)[SensorType](#sensortype) | 是    | 要取消订阅的心率传感器类型为SENSOR_TYPE_ID_HEART_RATE。 |
| callback | Callback&lt;[HeartRateResponse](#heartrateresponse)&gt; | 是    | 取消注册一次心率传感器的回调函数，上报的数据类型为HeartRateResponse。 |

**示例：** 

```js
function callback(data) {
    console.info("Heart rate: " + data.heartRate);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, callback);
```

### HUMIDITY

off(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback?: Callback&lt;HumidityResponse&gt;): void

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的湿度传感器类型为SENSOR_TYPE_ID_HUMIDITY。   |
| callback | Callback&lt;[HumidityResponse](#humidityresponse)&gt; | 是    | 取消注册湿度传感器的回调函数，上报的数据类型为HumidityResponse。 |

**示例：** 

```js
function callback(data) {
    console.info('Humidity: ' + data.humidity);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, callback);
```

### LINEAR_ACCELERATION

off(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback?: Callback&lt;LinearAccelerometerResponse&gt;): void

取消订阅传感器数据。

**需要权限**：ohos.permission.ACCELEROMETER，该权限为系统权限

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的线性加速度传感器类型为SENSOR_TYPE_ID_LINEAR_ACCELERATION。 |
| callback | Callback&lt;[LinearAccelerometerResponse](#linearaccelerometerresponse)&gt; | 是    | 取消注册性加速度传感器的回调函数，上报的数据类型为LinearAccelerometerResponse。 |

**示例：** 

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

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名              | 类型                                       | 必填   | 说明                                       |
| ---------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type             | [SensorType](#sensortype)                | 是    | 要取消订阅的磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD。 |
| callbackcallback | Callback&lt;[MagneticFieldResponse](#magneticfieldresponse)&gt; | 是    | 取消注册磁场传感器的回调函数，上报的数据类型为MagneticFieldResponse。 |

**示例：** 

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

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的未校准磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED。 |
| callback | Callback&lt;[MagneticFieldUncalibratedResponse](#magneticfielduncalibratedresponse)&gt; | 是    | 取消注册未校准磁场传感器的回调函数，上报的数据类型为MagneticFieldUncalibratedResponse。 |

**示例：** 

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

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的方向传感器类型为SENSOR_TYPE_ID_ORIENTATION |
| callback | Callback&lt;[OrientationResponse](#orientationresponse)&gt; | 是    | 取消注册方向传感器的回调函数，上报的数据类型为OrientationResponse。 |

**示例：** 

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

取消订阅传感器数据。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的计步传感器类型为SENSOR_TYPE_ID_PEDOMETER。  |
| callback | Callback&lt;[PedometerResponse](#pedometerresponse)&gt; | 是    | 取消注册计步传感器的回调函数，上报的数据类型为PedometerResponse。 |

**示例：** 

```js
function callback(data) {
    console.info('Steps: ' + data.steps);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, callback);
```

### PEDOMETER_DETECTION

off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback?: Callback&lt;PedometerDetectionResponse&gt;): void

取消订阅传感器数据。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的计步检测传感器类型为SENSOR_TYPE_ID_PEDOMETER_DETECTION。 |
| callback | Callback&lt;[PedometerDetectionResponse](#pedometerdetectionresponse)&gt; | 是    | 取消注册计步检测传感器的回调函数，上报的数据类型为PedometerDetectionResponse。 |

**示例：** 

```js
function callback(data) {
    console.info('Scalar data: ' + data.scalar);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback);
```

### PROXIMITY

off(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback?: Callback&lt;ProximityResponse&gt;): void

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的接近光传感器类型为SENSOR_TYPE_ID_PROXIMITY。 |
| callback | Callback&lt;[ProximityResponse](#proximityresponse)&gt; | 是    | 取消注册接近光传感器的回调函数，上报的数据类型为ProximityResponse。 |

**示例：** 

```js
function callback(data) {
    console.info('Distance: ' + data.distance);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, callback);
```

### ROTATION_VECTOR

off(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback?: Callback&lt;RotationVectorResponse&gt;): void

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的旋转矢量传感器类型为SENSOR_TYPE_ID_ROTATION_VECTOR。 |
| callback | Callback&lt;[RotationVectorResponse](#rotationvectorresponse)&gt; | 是    | 取消注册旋转矢量传感器的回调函数，上报的数据类型为RotationVectorResponse。 |

**示例：** 

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

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的大幅动作传感器类型为SENSOR_TYPE_ID_SIGNIFICANT_MOTION。 |
| callback | Callback&lt;[SignificantMotionResponse](#significantmotionresponse)&gt; | 是    | 取消注册有效运动传感器的回调函数，上报的数据类型为SignificantMotionResponse。 |

**示例：** 

```js
function callback(data) {
    console.info('Scalar data: ' + data.scalar);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback);
```

### WEAR_DETECTION

off(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback?: Callback&lt;WearDetectionResponse&gt;): void

取消订阅传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | [SensorType](#sensortype)                | 是    | 要取消订阅的佩戴检测传感器类型为SENSOR_TYPE_ID_WEAR_DETECTION。 |
| callback | Callback&lt;[WearDetectionResponse](#weardetectionresponse)&gt; | 是    | 取消注册佩戴检测传感器的回调函数，上报的数据类型为WearDetectionResponse。 |

**示例：** 

```js
function accCallback(data) {
    console.info('Wear status: ' + data.value);
}
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, accCallback);
```

## sensor.transformCoordinateSystem

transformCoordinateSystem(inRotationVector: Array&lt;number&gt;, coordinates: CoordinatesOptions, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

旋转提供的旋转矩阵，使其可以以不同的方式表示坐标系。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名              | 类型                                       | 必填   | 说明          |
| ---------------- | ---------------------------------------- | ---- | ----------- |
| inRotationVector | Array&lt;number&gt;                      | 是    | 表示旋转矩阵。     |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | 是    | 表示坐标系方向。    |
| callback         | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是    | 返回转换后的旋转矩阵。 |

**示例：** 

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

旋转提供的旋转矩阵，使其可以以不同的方式表示坐标系。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名              | 类型                                       | 必填   | 说明       |
| ---------------- | ---------------------------------------- | ---- | -------- |
| inRotationVector | Array&lt;number&gt;                      | 是    | 表示旋转矩阵。  |
| coordinates      | [CoordinatesOptions](#coordinatesoptions) | 是    | 表示坐标系方向。 |

**返回值：** 

| 类型                                 | 说明          |
| ---------------------------------- | ----------- |
| Promise&lt;Array&lt;number&gt;&gt; | 返回转换后的旋转矩阵。 |

**示例：** 

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

获取地球上特定位置的地磁场。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名             | 类型                                       | 必填   | 说明                |
| --------------- | ---------------------------------------- | ---- | ----------------- |
| locationOptions | [LocationOptions](#locationoptions)      | 是    | 地理位置。             |
| timeMillis      | number                                   | 是    | 表示获取磁偏角的时间，单位为毫秒。 |
| callback        | AsyncCallback&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | 是    | 返回磁场信息。           |

**示例：** 
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

获取地球上特定位置的地磁场。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 
| 参数名             | 类型                                  | 必填   | 说明                |
| --------------- | ----------------------------------- | ---- | ----------------- |
| locationOptions | [LocationOptions](#locationoptions) | 是    | 地理位置。             |
| timeMillis      | number                              | 是    | 表示获取磁偏角的时间，单位为毫秒。 |

**返回值：** 
| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise&lt;[GeomagneticResponse](#geomagneticresponse)&gt; | 返回磁场信息。 |

**示例：** 
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

根据气压值获取设备所在的海拔高度。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名             | 类型                          | 必填   | 说明                   |
| --------------- | --------------------------- | ---- | -------------------- |
| seaPressure     | number                      | 是    | 表示海平面气压值，单位为hPa。     |
| currentPressure | number                      | 是    | 表示设备所在高度的气压值，单位为hPa。 |
| callback        | AsyncCallback&lt;number&gt; | 是    | 返回设备所在的海拔高度，单位为米。    |

**示例：** 

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

根据气压值获取设备所在的海拔高度。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名             | 类型     | 必填   | 说明                   |
| --------------- | ------ | ---- | -------------------- |
| seaPressure     | number | 是    | 表示海平面气压值，单位为hPa。     |
| currentPressure | number | 是    | 表示设备所在高度的气压值，单位为hPa。 |

**返回值：** 

| 类型                    | 说明                 |
| --------------------- | ------------------ |
| Promise&lt;number&gt; | 返回设备所在的海拔高度（单位：米）。 |

**示例：** 

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

根据倾斜矩阵计算地磁倾斜角。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名               | 类型                          | 必填   | 说明             |
| ----------------- | --------------------------- | ---- | -------------- |
| inclinationMatrix | Array&lt;number&gt;         | 是    | 表示倾斜矩阵。        |
| callback          | AsyncCallback&lt;number&gt; | 是    | 返回地磁倾斜角，单位为弧度。 |

**示例：** 

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

根据倾斜矩阵计算地磁倾斜角。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名               | 类型                  | 必填   | 说明      |
| ----------------- | ------------------- | ---- | ------- |
| inclinationMatrix | Array&lt;number&gt; | 是    | 表示倾斜矩阵。 |

**返回值：** 

| 类型                    | 说明             |
| --------------------- | -------------- |
| Promise&lt;number&gt; | 返回地磁倾斜角，单位为弧度。 |

**示例：** 

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

获取两个旋转矩阵之间的角度变化。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名                   | 类型                                       | 必填   | 说明                 |
| --------------------- | ---------------------------------------- | ---- | ------------------ |
| currentRotationMatrix | Array&lt;number&gt;                      | 是    | 表示当前旋转矩阵。          |
| preRotationMatrix     | Array&lt;number&gt;                      | 是    | 表示旋转矩阵。            |
| callback              | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是    | 返回z、x、y轴方向的旋转角度变化。 |

**示例：** 

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

获取两个旋转矩阵之间的角度变化。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名                   | 类型                  | 必填   | 说明        |
| --------------------- | ------------------- | ---- | --------- |
| currentRotationMatrix | Array&lt;number&gt; | 是    | 表示当前旋转矩阵。 |
| preRotationMatrix     | Array&lt;number&gt; | 是    | 表示旋转矩阵。   |

**返回值：** 

| 类型                                 | 说明                 |
| ---------------------------------- | ------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | 返回z、x、y轴方向的旋转角度变化。 |

**示例：** 

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

将旋转矢量转换为旋转矩阵。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名            | 类型                                       | 必填   | 说明      |
| -------------- | ---------------------------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt;                      | 是    | 表示旋转矢量。 |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是    | 返回旋转矩阵。 |

**示例：** 

  ```js
  sensor.createRotationMatrix([0.20046076, 0.21907, 0.73978853, 0.60376877], function(err, data) {
      if (err) {
          console.error('SensorJsAPI--->Failed to register data, error code is: ' + err.code + ', message: ' + 
                        err.message);
          return;
      }
      for (var i=0; i < data.rotation.length; i++) {
          console.info("data[" + i + "]: " + data[i]);
      }
  })
  ```


## sensor.createRotationMatrix

createRotationMatrix(rotationVector: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

将旋转矢量转换为旋转矩阵。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名            | 类型                  | 必填   | 说明      |
| -------------- | ------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt; | 是    | 表示旋转矢量。 |

**返回值：** 

| 类型                                 | 说明      |
| ---------------------------------- | ------- |
| Promise&lt;Array&lt;number&gt;&gt; | 返回旋转矩阵。 |

**示例：** 

  ```js
  const promise = sensor.createRotationMatrix([0.20046076, 0.21907, 0.73978853, 0.60376877]);
      promise.then((data) => {
          console.info('createRotationMatrix_promise success');
          for (var i=0; i < data.rotation.length; i++) {
              console.info("data[" + i + "]: " + data[i]);
          }
      }).catch((reason) => {
          console.info("promise::catch", reason);
  })	
  ```


## sensor.createQuaternion

createQuaternion(rotationVector: Array&lt;number&gt;, callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

将旋转矢量转换为四元数。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名            | 类型                                       | 必填   | 说明      |
| -------------- | ---------------------------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt;                      | 是    | 表示旋转矢量。 |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是    | 返回四元数。  |

**示例：** 

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

将旋转矢量转换为四元数。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名            | 类型                  | 必填   | 说明      |
| -------------- | ------------------- | ---- | ------- |
| rotationVector | Array&lt;number&gt; | 是    | 表示旋转矢量。 |

**返回值：** 

| 类型                                 | 说明     |
| ---------------------------------- | ------ |
| Promise&lt;Array&lt;number&gt;&gt; | 返回四元数。 |

**示例：** 

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

根据旋转矩阵计算设备的方向。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名            | 类型                                       | 必填   | 说明                 |
| -------------- | ---------------------------------------- | ---- | ------------------ |
| rotationMatrix | Array&lt;number&gt;                      | 是    | 表示旋转矩阵。            |
| callback       | AsyncCallback&lt;Array&lt;number&gt;&gt; | 是    | 返回围绕z、x、y轴方向的旋转角度。 |

**示例：** 

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

根据旋转矩阵计算设备的方向。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名            | 类型                  | 必填   | 说明      |
| -------------- | ------------------- | ---- | ------- |
| rotationMatrix | Array&lt;number&gt; | 是    | 表示旋转矩阵。 |

**返回值：** 

| 类型                                 | 说明                 |
| ---------------------------------- | ------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | 返回围绕z、x、y轴方向的旋转角度。 |

**示例：** 

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

根据重力矢量和地磁矢量计算旋转矩阵。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名         | 类型                                       | 必填   | 说明      |
| ----------- | ---------------------------------------- | ---- | ------- |
| gravity     | Array&lt;number&gt;                      | 是    | 表示重力向量。 |
| geomagnetic | Array&lt;number&gt;                      | 是    | 表示地磁矢量。 |
| callback    | AsyncCallback&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | 是    | 返回旋转矩阵。 |

**示例：** 

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

根据重力矢量和地磁矢量计算旋转矩阵。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：** 

| 参数名         | 类型                  | 必填   | 说明      |
| ----------- | ------------------- | ---- | ------- |
| gravity     | Array&lt;number&gt; | 是    | 表示重力向量。 |
| geomagnetic | Array&lt;number&gt; | 是    | 表示地磁矢量。 |

**返回值：** 

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise&lt;[RotationMatrixResponse](#rotationmatrixresponse)&gt; | 返回旋转矩阵。 |

**示例：** 

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

表示要订阅或取消订阅的传感器类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称                                       | 默认值  | 说明          |
| ---------------------------------------- | ---- | ----------- |
| SENSOR_TYPE_ID_ACCELEROMETER             | 1    | 加速度传感器。     |
| SENSOR_TYPE_ID_GYROSCOPE                 | 2    | 陀螺仪传感器。     |
| SENSOR_TYPE_ID_AMBIENT_LIGHT             | 5    | 环境光传感器。     |
| SENSOR_TYPE_ID_MAGNETIC_FIELD            | 6    | 磁场传感器。      |
| SENSOR_TYPE_ID_BAROMETER                 | 8    | 气压计传感器。     |
| SENSOR_TYPE_ID_HALL                      | 10   | 霍尔传感器。      |
| SENSOR_TYPE_ID_PROXIMITY                 | 12   | 接近光传感器。     |
| SENSOR_TYPE_ID_HUMIDITY                  | 13   | 湿度传感器。      |
| SENSOR_TYPE_ID_ORIENTATION               | 256  | 方向传感器。      |
| SENSOR_TYPE_ID_GRAVITY                   | 257  | 重力传感器。      |
| SENSOR_TYPE_ID_LINEAR_ACCELERATION       | 258  | 线性加速度传感器。   |
| SENSOR_TYPE_ID_ROTATION_VECTOR           | 259  | 旋转矢量传感器。    |
| SENSOR_TYPE_ID_AMBIENT_TEMPERATURE       | 260  | 环境温度传感器。    |
| SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | 261  | 未校准磁场传感器。   |
| SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED    | 263  | 未校准陀螺仪传感器。  |
| SENSOR_TYPE_ID_SIGNIFICANT_MOTION        | 264  | 有效运动传感器。    |
| SENSOR_TYPE_ID_PEDOMETER_DETECTION       | 265  | 计步检测传感器。    |
| SENSOR_TYPE_ID_PEDOMETER                 | 266  | 计步传感器。      |
| SENSOR_TYPE_ID_HEART_RATE                | 278  | 心率传感器。      |
| SENSOR_TYPE_ID_WEAR_DETECTION            | 280  | 佩戴检测传感器。    |
| SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | 281  | 未校准加速度计传感器。 |


## Response

传感器数据的时间戳。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称        | 参数类型   | 可读   | 可写   | 说明           |
| --------- | ------ | ---- | ---- | ------------ |
| timestamp | number | 是    | 是    | 传感器数据上报的时间戳。 |


## AccelerometerResponse

加速度传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称   | 参数类型   | 可读   | 可写   | 说明                     |
| ---- | ------ | ---- | ---- | ---------------------- |
| x    | number | 是    | 是    | 施加在设备x轴的加速度，单位 : m/s2。 |
| y    | number | 是    | 是    | 施加在设备y轴的加速度，单位 : m/s2。 |
| z    | number | 是    | 是    | 施加在设备z轴的加速度，单位 : m/s2。 |


## LinearAccelerometerResponse

线性加速度传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称   | 参数类型   | 可读   | 可写   | 说明                       |
| ---- | ------ | ---- | ---- | ------------------------ |
| x    | number | 是    | 是    | 施加在设备x轴的线性加速度，单位 : m/s2。 |
| y    | number | 是    | 是    | 施加在设备y轴的线性加速度，单位 : m/s2。 |
| z    | number | 是    | 是    | 施加在设备z轴的线性加速度，单位 : m/s2。 |


## AccelerometerUncalibratedResponse

未校准加速度计传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称    | 参数类型   | 可读   | 可写   | 说明                           |
| ----- | ------ | ---- | ---- | ---------------------------- |
| x     | number | 是    | 是    | 施加在设备x轴未校准的加速度，单位 : m/s2。    |
| y     | number | 是    | 是    | 施加在设备y轴未校准的加速度，单位 : m/s2。    |
| z     | number | 是    | 是    | 施加在设备z轴未校准的加速度，单位 : m/s2。    |
| biasX | number | 是    | 是    | 施加在设备x轴未校准的加速度偏量，单位 : m/s2。  |
| biasY | number | 是    | 是    | 施加在设备上y轴未校准的加速度偏量，单位 : m/s2。 |
| biasZ | number | 是    | 是    | 施加在设备z轴未校准的加速度偏量，单位 : m/s2。  |


## GravityResponse

重力传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称   | 参数类型   | 可读   | 可写   | 说明                       |
| ---- | ------ | ---- | ---- | ------------------------ |
| x    | number | 是    | 是    | 施加在设备x轴的重力加速度，单位 : m/s2。 |
| y    | number | 是    | 是    | 施加在设备y轴的重力加速度，单位 : m/s2。 |
| z    | number | 是    | 是    | 施加在设备z轴的重力加速度，单位 : m/s2。 |


## OrientationResponse

方向传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称    | 参数类型   | 可读   | 可写   | 说明                |
| ----- | ------ | ---- | ---- | ----------------- |
| alpha | number | 是    | 是    | 设备围绕Z轴的旋转角度，单位：度。 |
| beta  | number | 是    | 是    | 设备围绕X轴的旋转角度，单位：度。 |
| gamma | number | 是    | 是    | 设备围绕Y轴的旋转角度，单位：度。 |


## RotationVectorResponse

旋转矢量传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称   | 参数类型   | 可读   | 可写   | 说明        |
| ---- | ------ | ---- | ---- | --------- |
| x    | number | 是    | 是    | 旋转矢量x轴分量。 |
| y    | number | 是    | 是    | 旋转矢量y轴分量。 |
| z    | number | 是    | 是    | 旋转矢量z轴分量。 |
| w    | number | 是    | 是    | 标量。       |


## GyroscopeResponse

陀螺仪传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称   | 参数类型   | 可读   | 可写   | 说明                  |
| ---- | ------ | ---- | ---- | ------------------- |
| x    | number | 是    | 是    | 设备x轴的旋转角速度，单位rad/s。 |
| y    | number | 是    | 是    | 设备y轴的旋转角速度，单位rad/s。 |
| z    | number | 是    | 是    | 设备z轴的旋转角速度，单位rad/s。 |


## GyroscopeUncalibratedResponse

未校准陀螺仪传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称    | 参数类型   | 可读   | 可写   | 说明                       |
| ----- | ------ | ---- | ---- | ------------------------ |
| x     | number | 是    | 是    | 设备x轴未校准的旋转角速度，单位rad/s。   |
| y     | number | 是    | 是    | 设备y轴未校准的旋转角速度，单位rad/s。   |
| z     | number | 是    | 是    | 设备z轴未校准的旋转角速度，单位rad/s。   |
| biasX | number | 是    | 是    | 设备x轴未校准的旋转角速度偏量，单位rad/s。 |
| biasY | number | 是    | 是    | 设备y轴未校准的旋转角速度偏量，单位rad/s。 |
| biasZ | number | 是    | 是    | 设备z轴未校准的旋转角速度偏量，单位rad/s。 |


## SignificantMotionResponse

有效运动传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称     | 参数类型   | 可读   | 可写   | 说明                                       |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| scalar | number | 是    | 是    | 表示剧烈运动程度。测量三个物理轴（x、y&nbsp;和&nbsp;z）上，设备是否存在大幅度运动；如果取值为1则代表存在大幅度运动，取值为0则代表没有大幅度运动。 |


## ProximityResponse

接近光传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称       | 参数类型   | 可读   | 可写   | 说明                           |
| -------- | ------ | ---- | ---- | ---------------------------- |
| distance | number | 是    | 是    | 可见物体与设备显示器的接近程度。0表示接近，1表示远离。 |


## LightResponse

环境光传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称        | 参数类型   | 可读   | 可写   | 说明          |
| --------- | ------ | ---- | ---- | ----------- |
| intensity | number | 是    | 是    | 光强（单位：勒克斯）。 |


## HallResponse

霍尔传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称     | 参数类型   | 可读   | 可写   | 说明                                |
| ------ | ------ | ---- | ---- | --------------------------------- |
| status | number | 是    | 是    | 显示霍尔状态。测量设备周围是否存在磁力吸引，0表示有，1表示没有。 |


## MagneticFieldResponse

磁场传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称 | 参数类型 | 可读 | 可写 | 说明                         |
| ---- | -------- | ---- | ---- | ---------------------------- |
| x    | number   | 是   | 是   | x轴环境磁场强度，单位 : μT。 |
| y    | number   | 是   | 是   | y轴环境磁场强度，单位 : μT。 |
| z    | number   | 是   | 是   | z轴环境磁场强度，单位 : μT。 |


## MagneticFieldUncalibratedResponse

未校准磁场传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称    | 参数类型   | 可读   | 可写   | 说明                     |
| ----- | ------ | ---- | ---- | ---------------------- |
| x     | number | 是    | 是    | x轴未校准环境磁场强度，单位 : μT。   |
| y     | number | 是    | 是    | y轴未校准环境磁场强度，单位 : μT。   |
| z     | number | 是    | 是    | z轴未校准环境磁场强度，单位 : μT。   |
| biasX | number | 是    | 是    | x轴未校准环境磁场强度偏量，单位 : μT。 |
| biasY | number | 是    | 是    | y轴未校准环境磁场强度偏量，单位 : μT。 |
| biasZ | number | 是    | 是    | z轴未校准环境磁场强度偏量，单位 : μT。 |


## PedometerResponse

计步传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称    | 参数类型   | 可读   | 可写   | 说明       |
| ----- | ------ | ---- | ---- | -------- |
| steps | number | 是    | 是    | 用户的行走步数。 |


## HumidityResponse

湿度传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称       | 参数类型   | 可读   | 可写   | 说明                                   |
| -------- | ------ | ---- | ---- | ------------------------------------ |
| humidity | number | 是    | 是    | 湿度值。测量环境的相对湿度，以百分比&nbsp;(%)&nbsp;表示。 |


## PedometerDetectionResponse

计步检测传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称     | 参数类型   | 可读   | 可写   | 说明                                       |
| ------ | ------ | ---- | ---- | ---------------------------------------- |
| scalar | number | 是    | 是    | 计步器检测。检测用户的计步动作，如果取值为1则代表用户产生了计步行走的动作，取值为0则代表用户没有发生运动。 |


## AmbientTemperatureResponse

温度传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称          | 参数类型   | 可读   | 可写   | 说明            |
| ----------- | ------ | ---- | ---- | ------------- |
| temperature | number | 是    | 是    | 环境温度（单位：摄氏度）。 |


## BarometerResponse

气压计传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称       | 参数类型   | 可读   | 可写   | 说明           |
| -------- | ------ | ---- | ---- | ------------ |
| pressure | number | 是    | 是    | 压力值（单位：帕斯卡）。 |


## HeartRateResponse

心率传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称        | 参数类型   | 可读   | 可写   | 说明                    |
| --------- | ------ | ---- | ---- | --------------------- |
| heartRate | number | 是    | 是    | 心率值。测量用户的心率数值，单位：bpm。 |


## WearDetectionResponse

佩戴检测传感器数据，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor


| 名称    | 参数类型   | 可读   | 可写   | 说明                        |
| ----- | ------ | ---- | ---- | ------------------------- |
| value | number | 是    | 是    | 表示设备是否被穿戴（1表示已穿戴，0表示未穿戴）。 |


## Options

设置传感器上报频率。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称       | 参数类型   | 说明                          |
| -------- | ------ | --------------------------- |
| interval | number | 表示传感器的上报频率，默认值为200000000ns。 |

## RotationMatrixResponse

设置旋转矩阵响应对象。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称          | 参数类型                | 可读   | 可写   | 说明    |
| ----------- | ------------------- | ---- | ---- | ----- |
| rotation    | Array&lt;number&gt; | 是    | 是    | 旋转矩阵。 |
| inclination | Array&lt;number&gt; | 是    | 是    | 倾斜矩阵。 |


## CoordinatesOptions

设置坐标选项对象。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称   | 参数类型   | 可读   | 可写   | 说明     |
| ---- | ------ | ---- | ---- | ------ |
| x    | number | 是    | 是    | x坐标方向。 |
| y    | number | 是    | 是    | y坐标方向。 |


## GeomagneticResponse

设置地磁响应对象，继承于[Response](#response)。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称              | 参数类型   | 可读   | 可写   | 说明                        |
| --------------- | ------ | ---- | ---- | ------------------------- |
| x               | number | 是    | 是    | 地磁场的北分量。                  |
| y               | number | 是    | 是    | 地磁场的东分量。                  |
| z               | number | 是    | 是    | 地磁场的垂直分量。                 |
| geomagneticDip  | number | 是    | 是    | 地磁倾角，即地球磁场线与水平面的夹角。       |
| deflectionAngle | number | 是    | 是    | 地磁偏角，即地磁北方向与正北方向在水平面上的角度。 |
| levelIntensity  | number | 是    | 是    | 地磁场的水平强度。                 |
| totalIntensity  | number | 是    | 是    | 地磁场的总强度。                  |

## LocationOptions

指示地理位置。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.Sensor

| 名称        | 参数类型   | 可读   | 可写   | 说明    |
| --------- | ------ | ---- | ---- | ----- |
| latitude  | number | 是    | 是    | 纬度。   |
| longitude | number | 是    | 是    | 经度。   |
| altitude  | number | 是    | 是    | 海拔高度。 |
