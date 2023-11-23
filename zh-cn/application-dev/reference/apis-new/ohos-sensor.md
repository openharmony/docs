# @ohos.sensor    
sensor模块提供了获取传感器数据的能力，包括获取传感器属性列表，订阅传感器数据，以及一些通用的传感器算法。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import sensor from '@ohos.sensor'    
```  
    
## SensorId<sup>(9+)</sup>    
表示当前支持订阅或取消订阅的传感器类型。    
    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ACCELEROMETER | 1 | 加速度传感器。 |  
| GYROSCOPE | 2 | 陀螺仪传感器。 |  
| AMBIENT_LIGHT | 5 |  环境光传感器。 |  
| MAGNETIC_FIELD | 6 | 磁场传感器。 |  
| BAROMETER | 8 | 气压计传感器。 |  
| HALL | 10 | 霍尔传感器。 |  
| PROXIMITY | 12 | 接近光传感器。 |  
| HUMIDITY | 13 | 湿度传感器。 |  
| ORIENTATION | 256 | 方向传感器。 |  
| GRAVITY | 257 | 重力传感器。 |  
| LINEAR_ACCELEROMETER | 258 | 线性加速度传感器。 |  
| ROTATION_VECTOR | 259 | 旋转矢量传感器。 |  
| AMBIENT_TEMPERATURE | 260 | 环境温度传感器。 |  
| MAGNETIC_FIELD_UNCALIBRATED | 261 | 未校准磁场传感器。 |  
| GYROSCOPE_UNCALIBRATED | 263 | 未校准陀螺仪传感器。 |  
| SIGNIFICANT_MOTION | 264 | 有效运动传感器。 |  
| PEDOMETER_DETECTION | 265 | 计步检测传感器。 |  
| PEDOMETER | 266 | 计步传感器。 |  
| HEART_RATE | 278 | 心率传感器。 |  
| WEAR_DETECTION | 280 | 佩戴检测传感器。 |  
| ACCELEROMETER_UNCALIBRATED | 281 | 未校准加速度计传感器。 |  
    
## on<sup>(9+)</sup>    
订阅加速度传感器数据。  
 **调用形式：**     
- on(type: SensorId.ACCELEROMETER, callback: Callback\<AccelerometerResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ACCELEROMETER | true | 传感器类型，该值固定为SensorId.ACCELEROMETER。 |  
| callback | Callback<AccelerometerResponse> | true | 回调函数，异步上报的传感器数据固定为AccelerometerResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅未校准加速度传感器数据。  
 **调用形式：**     
- on(type: SensorId.ACCELEROMETER_UNCALIBRATED, callback: Callback\<AccelerometerUncalibratedResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ACCELEROMETER_UNCALIBRATED | true | 传感器类型，该值固定为SensorId.ACCELEROMETER_UNCALIBRATED。 |  
| callback | Callback<AccelerometerUncalibratedResponse> | true | 回调函数，异步上报的传感器数据固定为AccelerometerUncalibratedResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅环境光传感器数据。  
 **调用形式：**     
- on(type: SensorId.AMBIENT_LIGHT, callback: Callback\<LightResponse>, options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.AMBIENT_LIGHT | true | 传感器类型，该值固定为SensorId.AMBIENT_LIGHT。 |  
| callback | Callback<LightResponse> | true | 回调函数，异步上报的传感器数据固定为LightResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.AMBIENT_LIGHT, (data: sensor.LightResponse) => {  
    console.info('Succeeded in getting the ambient light intensity: ' + data.intensity);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.AMBIENT_LIGHT);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅温度传感器数据。  
 **调用形式：**     
- on(type: SensorId.AMBIENT_TEMPERATURE, callback: Callback\<AmbientTemperatureResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.AMBIENT_TEMPERATURE | true | 传感器类型，该值固定为SensorId.AMBIENT_TEMPERATURE。 |  
| callback | Callback<AmbientTemperatureResponse> | true | 回调函数，异步上报的传感器数据固定为AmbientTemperatureResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.AMBIENT_TEMPERATURE, (data: sensor.AmbientTemperatureResponse) => {  
    console.info('Succeeded in invoking on. Temperature: ' + data.temperature);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.AMBIENT_TEMPERATURE);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅气压计传感器数据。  
 **调用形式：**     
- on(type: SensorId.BAROMETER, callback: Callback\<BarometerResponse>, options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.BAROMETER | true | 传感器类型，该值固定为SensorId.BAROMETER。  |  
| callback | Callback<BarometerResponse> | true | 回调函数，异步上报的传感器数据固定为BarometerResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.BAROMETER, (data: sensor.BarometerResponse) => {  
    console.info('Succeeded in invoking on. Atmospheric pressure: ' + data.pressure);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.BAROMETER);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
<span style="letter-spacing: 0px;">订阅重力传感器数据。</span>。  
 **调用形式：**     
- on(type: SensorId.GRAVITY, callback: Callback\<GravityResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.GRAVITY | true | 传感器类型，该值固定为SensorId.GRAVITY。 |  
| callback | Callback<GravityResponse> | true | 回调函数，异步上报的传感器数据固定为GravityResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅校准的陀螺仪传感器数据。  
 **调用形式：**     
- on(type: SensorId.GYROSCOPE, callback: Callback\<GyroscopeResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.GYROSCOPE | true | 传感器类型，该值固定为SensorId.GYROSCOPE。 |  
| callback | Callback<GyroscopeResponse> | true | 回调函数，异步上报的传感器数据固定为GyroscopeResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅未校准陀螺仪传感器数据。  
 **调用形式：**     
- on(type: SensorId.GYROSCOPE_UNCALIBRATED, callback: Callback\<GyroscopeUncalibratedResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.GYROSCOPE_UNCALIBRATED | true | 传感器类型，该值固定为SensorId.GYROSCOPE_UNCALIBRATED。 |  
| callback | Callback<GyroscopeUncalibratedResponse> | true | 回调函数，异步上报的传感器数据固定为GyroscopeUncalibratedResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅霍尔传感器数据。  
 **调用形式：**     
- on(type: SensorId.HALL, callback: Callback\<HallResponse>, options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.HALL | true | 传感器类型，该值固定为SensorId.HALL。 |  
| callback | Callback<HallResponse> | true | 回调函数，异步上报的传感器数据固定为HallResponse。 |  
| options | Options | false | 可选参数列表，默认值为200000000ns。当霍尔事件被触发的很频繁时，该参数用于限定事件上报的频率。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.HALL, (data: sensor.HallResponse) => {  
    console.info('Succeeded in invoking on. Hall status: ' + data.status);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.HALL);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅心率传感器数据。  
 **调用形式：**     
- on(type: SensorId.HEART_RATE, callback: Callback\<HeartRateResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.READ_HEALTH_DATA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.HEART_RATE | true | 传感器类型，该值固定为SensorId.HEART_RATE。 |  
| callback | Callback<HeartRateResponse> | true | 回调函数，异步上报的传感器数据固定为HeartRateResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.HEART_RATE, (data: sensor.HeartRateResponse) => {  
    console.info('Succeeded in invoking on. Heart rate: ' + data.heartRate);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.HEART_RATE);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅湿度传感器数据。  
 **调用形式：**     
- on(type: SensorId.HUMIDITY, callback: Callback\<HumidityResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.HUMIDITY | true | 传感器类型，该值固定为SensorId.HUMIDITY。 |  
| callback | Callback<HumidityResponse> | true | 回调函数，异步上报的传感器数据固定为HumidityResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.HUMIDITY, (data: sensor.HumidityResponse) => {  
    console.info('Succeeded in invoking on. Humidity: ' + data.humidity);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.HUMIDITY);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅线性加速度传感器数据。  
 **调用形式：**     
- on(type: SensorId.LINEAR_ACCELEROMETER, callback: Callback\<LinearAccelerometerResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.LINEAR_ACCELEROMETER | true | 传感器类型，该值固定为SensorId.LINEAR_ACCELEROMETER。 |  
| callback | Callback<LinearAccelerometerResponse> | true | 回调函数，异步上报的传感器数据固定为LinearAccelerometerResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅地磁传感器数据。  
 **调用形式：**     
- on(type: SensorId.MAGNETIC_FIELD, callback: Callback\<MagneticFieldResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.MAGNETIC_FIELD | true | 传感器类型，该值固定为SensorId.MAGNETIC_FIELD。 |  
| callback | Callback<MagneticFieldResponse> | true | 回调函数，异步上报的传感器数据固定为MagneticFieldResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅未校准地磁传感器数据。  
 **调用形式：**     
- on(type: SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback: Callback\<MagneticFieldUncalibratedResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.MAGNETIC_FIELD_UNCALIBRATED | true | 传感器类型，该值固定为SensorId.MAGNETIC_FIELD_UNCALIBRATED。 |  
| callback | Callback<MagneticFieldUncalibratedResponse> | true | 回调函数，异步上报的传感器数据固定为MagneticFieldUncalibratedResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅方向传感器数据。  
 **调用形式：**     
- on(type: SensorId.ORIENTATION, callback: Callback\<OrientationResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ORIENTATION | true | 传感器类型，该值固定为SensorId.ORIENTATION。 |  
| callback | Callback<OrientationResponse> | true | 回调函数，异步上报的传感器数据固定为OrientationResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅计步器传感器数据。  
 **调用形式：**     
- on(type: SensorId.PEDOMETER, callback: Callback\<PedometerResponse>, options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.PEDOMETER | true | 传感器类型，该值固定为SensorId.PEDOMETER。 |  
| callback | Callback<PedometerResponse> | true | 回调函数，异步上报的传感器数据固定为PedometerResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.PEDOMETER, (data: sensor.PedometerResponse) => {  
    console.info('Succeeded in invoking on. Step count: ' + data.steps);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.PEDOMETER);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅计步检测器传感器数据。  
 **调用形式：**     
- on(type: SensorId.PEDOMETER_DETECTION, callback: Callback\<PedometerDetectionResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.PEDOMETER_DETECTION | true | 传感器类型，该值固定为SensorId.PEDOMETER_DETECTION。 |  
| callback | Callback<PedometerDetectionResponse> | true | 回调函数，异步上报的传感器数据固定为PedometerDetectionResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.PEDOMETER_DETECTION, (data: sensor.PedometerDetectionResponse) => {  
    console.info('Succeeded in invoking on. Pedometer scalar: ' + data.scalar);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.PEDOMETER_DETECTION);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅接近光传感器数据。  
 **调用形式：**     
- on(type: SensorId.PROXIMITY, callback: Callback\<ProximityResponse>, options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.PROXIMITY | true | 传感器类型，该值固定为SensorId.PROXIMITY。 |  
| callback | Callback<ProximityResponse> | true | 回调函数，异步上报的传感器数据固定为ProximityResponse。 |  
| options | Options | false | 可选参数列表，默认值为200000000ns。当接近光事件被触发的很频繁时，该参数用于限定事件上报的频率。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.PROXIMITY, (data: sensor.ProximityResponse) => {  
    console.info('Succeeded in invoking on. Distance: ' + data.distance);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.PROXIMITY);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅旋转矢量传感器数据。  
 **调用形式：**     
- on(type: SensorId.ROTATION_VECTOR, callback: Callback\<RotationVectorResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ROTATION_VECTOR | true | 传感器类型，该值固定为SensorId.ROTATION_VECTOR。  |  
| callback | Callback<RotationVectorResponse> | true | 回调函数，异步上报的传感器数据固定为RotationVectorResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | ervice exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅大幅动作检测传感器数据。  
 **调用形式：**     
- on(type: SensorId.SIGNIFICANT_MOTION, callback: Callback\<SignificantMotionResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.SIGNIFICANT_MOTION | true | 传感器类型，该值固定为SensorId.SIGNIFICANT_MOTION。 |  
| callback | Callback<SignificantMotionResponse> | true | 回调函数，异步上报的传感器数据固定为SignificantMotionResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.SIGNIFICANT_MOTION, (data: sensor.SignificantMotionResponse) => {  
    console.info('Succeeded in invoking on. Scalar data: ' + data.scalar);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.SIGNIFICANT_MOTION);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(9+)</sup>    
订阅佩戴检测传感器数据。  
 **调用形式：**     
- on(type: SensorId.WEAR_DETECTION, callback: Callback\<WearDetectionResponse>,    options?: Options): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.WEAR_DETECTION | true | 传感器类型，该值固定为SensorId.WEAR_DETECTION。 |  
| callback | Callback<WearDetectionResponse> | true | 回调函数，异步上报的传感器数据固定为WearDetectionResponse。 |  
| options | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.on(sensor.SensorId.WEAR_DETECTION, (data: sensor.WearDetectionResponse) => {  
    console.info('Succeeded in invoking on. Wear status: ' + data.value);  
  }, { interval: 100000000 });  
  setTimeout(() => {  
    sensor.off(sensor.SensorId.WEAR_DETECTION);  
  }, 500);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke on. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次加速度传感器数据。  
 **调用形式：**     
- once(type: SensorId.ACCELEROMETER, callback: Callback\<AccelerometerResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ACCELEROMETER | true | 传感器类型，该值固定为SensorId.ACCELEROMETER。 |  
| callback | Callback<AccelerometerResponse> | true | 回调函数，异步上报的传感器数据固定为AccelerometerResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.ACCELEROMETER, (data: sensor.AccelerometerResponse) => {  
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次未校准加速度传感器数据。  
 **调用形式：**     
- once(type: SensorId.ACCELEROMETER_UNCALIBRATED, callback: Callback\<AccelerometerUncalibratedResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ACCELEROMETER_UNCALIBRATED | true | 传感器类型，该值固定为SensorId.ACCELEROMETER_UNCALIBRATED。 |  
| callback | Callback<AccelerometerUncalibratedResponse> | true | 回调函数，异步上报的传感器数据固定为AccelerometerUncalibratedResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次环境光传感器数据。  
 **调用形式：**     
- once(type: SensorId.AMBIENT_LIGHT, callback: Callback\<LightResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.AMBIENT_LIGHT | true | 传感器类型，该值固定为SensorId.AMBIENT_LIGHT。 |  
| callback | Callback<LightResponse> | true | 回调函数，异步上报的传感器数据固定为LightResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.AMBIENT_LIGHT, (data: sensor.LightResponse) => {  
    console.info('Succeeded in invoking once. the ambient light intensity: ' + data.intensity);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次温度传感器数据。  
 **调用形式：**     
- once(type: SensorId.AMBIENT_TEMPERATURE, callback: Callback\<AmbientTemperatureResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.AMBIENT_TEMPERATURE | true | 传感器类型，该值固定为SensorId.AMBIENT_TEMPERATURE。 |  
| callback | Callback<AmbientTemperatureResponse> | true | 回调函数，异步上报的传感器数据固定为AmbientTemperatureResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.AMBIENT_TEMPERATURE, (data: sensor.AmbientTemperatureResponse) => {  
    console.info('Succeeded in invoking once. Temperature: ' + data.temperature);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次气压计传感器数据。  
 **调用形式：**     
- once(type: SensorId.BAROMETER, callback: Callback\<BarometerResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.BAROMETER | true | 传感器类型，该值固定为SensorId.BAROMETER。 |  
| callback | Callback<BarometerResponse> | true | 回调函数，异步上报的传感器数据固定为BarometerResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.BAROMETER, (data: sensor.BarometerResponse) => {  
    console.info('Succeeded in invoking once. Atmospheric pressure: ' + data.pressure);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次重力传感器数据。  
 **调用形式：**     
- once(type: SensorId.GRAVITY, callback: Callback\<GravityResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.GRAVITY | true | 传感器类型，该值固定为SensorId.GRAVITY。 |  
| callback | Callback<GravityResponse> | true | 回调函数，异步上报的传感器数据固定为GravityResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.GRAVITY, (data: sensor.GravityResponse) => {  
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次陀螺仪传感器数据。  
 **调用形式：**     
- once(type: SensorId.GYROSCOPE, callback: Callback\<GyroscopeResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.GYROSCOPE | true | 传感器类型，该值固定为SensorId.GYROSCOPE。 |  
| callback | Callback<GyroscopeResponse> | true | 回调函数，异步上报的传感器数据固定为GyroscopeResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.GYROSCOPE, (data: sensor.GyroscopeResponse) => {  
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次未校准陀螺仪传感器数据。  
 **调用形式：**     
- once(type: SensorId.GYROSCOPE_UNCALIBRATED, callback: Callback\<GyroscopeUncalibratedResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.GYROSCOPE_UNCALIBRATED | true | 传感器类型，该值固定为SensorId.GYROSCOPE_UNCALIBRATED。 |  
| callback | Callback<GyroscopeUncalibratedResponse> | true | 回调函数，异步上报的传感器数据固定为GyroscopeUncalibratedResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次霍尔传感器数据。  
 **调用形式：**     
- once(type: SensorId.HALL, callback: Callback\<HallResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.HALL | true | 传感器类型，该值固定为SensorId.HALL。 |  
| callback | Callback<HallResponse> | true | 回调函数，异步上报的传感器数据固定为HallResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.HALL, (data: sensor.HallResponse) => {  
    console.info('Succeeded in invoking once. Status: ' + data.status);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次心率传感器数据。  
 **调用形式：**     
- once(type: SensorId.HEART_RATE, callback: Callback\<HeartRateResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.READ_HEALTH_DATA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.HEART_RATE | true | 传感器类型，该值固定为SensorId.HEART_RATE。 |  
| callback | Callback<HeartRateResponse> | true | 回调函数，异步上报的传感器数据固定为HeartRateResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.HEART_RATE, (data: sensor.HeartRateResponse) => {  
    console.info('Succeeded in invoking once. Heart rate: ' + data.heartRate);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次湿度传感器数据。  
 **调用形式：**     
- once(type: SensorId.HUMIDITY, callback: Callback\<HumidityResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.HUMIDITY | true | 传感器类型，该值固定为SensorId.HUMIDITY。 |  
| callback | Callback<HumidityResponse> | true | 回调函数，异步上报的传感器数据固定为HumidityResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.HUMIDITY, (data: sensor.HumidityResponse) => {  
    console.info('Succeeded in invoking once. Humidity: ' + data.humidity);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次线性加速度传感器数据。  
 **调用形式：**     
- once(type: SensorId.LINEAR_ACCELEROMETER, callback: Callback\<LinearAccelerometerResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.LINEAR_ACCELEROMETER | true | 传感器类型，该值固定为SensorId.LINEAR_ACCELEROMETER。 |  
| callback | Callback<LinearAccelerometerResponse> | true | 回调函数，异步上报的传感器数据固定为LinearAccelerometerResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.LINEAR_ACCELEROMETER, (data: sensor.LinearAccelerometerResponse) => {  
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次磁场传感器数据。  
 **调用形式：**     
- once(type: SensorId.MAGNETIC_FIELD, callback: Callback\<MagneticFieldResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.MAGNETIC_FIELD | true | 传感器类型，该值固定为SensorId.MAGNETIC_FIELD。  |  
| callback | Callback<MagneticFieldResponse> | true | 回调函数，异步上报的传感器数据固定为MagneticFieldResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.MAGNETIC_FIELD, (data: sensor.MagneticFieldResponse) => {  
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次未经校准的磁场传感器数据。  
 **调用形式：**     
- once(type: SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback: Callback\<MagneticFieldUncalibratedResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.MAGNETIC_FIELD_UNCALIBRATED | true | 传感器类型，该值固定为SensorId.MAGNETIC_FIELD_UNCALIBRATED。 |  
| callback | Callback<MagneticFieldUncalibratedResponse> | true | 回调函数，异步上报的传感器数据固定为MagneticFieldUncalibratedResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次方向传感器数据。  
 **调用形式：**     
- once(type: SensorId.ORIENTATION, callback: Callback\<OrientationResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ORIENTATION | true | 传感器类型，该值固定为SensorId.ORIENTATION。 |  
| callback | Callback<OrientationResponse> | true | 回调函数，异步上报的传感器数据固定为OrientationResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.ORIENTATION, (data: sensor.OrientationResponse) => {  
    console.info('Succeeded in the device rotating at an angle around the X axis: ' + data.beta);  
    console.info('Succeeded in the device rotating at an angle around the Y axis: ' + data.gamma);  
    console.info('Succeeded in the device rotating at an angle around the Z axis: ' + data.alpha);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次计步器传感器数据。  
 **调用形式：**     
- once(type: SensorId.PEDOMETER, callback: Callback\<PedometerResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.PEDOMETER | true | 传感器类型，该值固定为SensorId.PEDOMETER。 |  
| callback | Callback<PedometerResponse> | true | 回调函数，异步上报的传感器数据固定为PedometerResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.PEDOMETER, (data: sensor.PedometerResponse) => {  
    console.info('Succeeded in invoking once. Step count: ' + data.steps);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次计步检测器传感器数据。  
 **调用形式：**     
- once(type: SensorId.PEDOMETER_DETECTION, callback: Callback\<PedometerDetectionResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.PEDOMETER_DETECTION | true | 传感器类型，该值固定为SensorId.PEDOMETER_DETECTION。 |  
| callback | Callback<PedometerDetectionResponse> | true | 回调函数，异步上报的传感器数据固定为PedometerDetectionResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.PEDOMETER_DETECTION, (data: sensor.PedometerDetectionResponse) => {  
    console.info('Succeeded in invoking once. Scalar data: ' + data.scalar);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次接近光传感器数据。  
 **调用形式：**     
- once(type: SensorId.PROXIMITY, callback: Callback\<ProximityResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.PROXIMITY | true | 传感器类型，该值固定为SensorId.PROXIMITY。 |  
| callback | Callback<ProximityResponse> | true | 回调函数，异步上报的传感器数据固定为ProximityResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.PROXIMITY, (data: sensor.ProximityResponse) => {  
    console.info('Succeeded in invoking once. Distance: ' + data.distance);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
<span style="letter-spacing: 0px;">获取一次旋转矢量传感器数据。</span>  
 **调用形式：**     
- once(type: SensorId.ROTATION_VECTOR, callback: Callback\<RotationVectorResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ROTATION_VECTOR | true | 传感器类型，该值固定为SensorId.ROTATION_VECTOR。 |  
| callback | Callback<RotationVectorResponse> | true | 回调函数，异步上报的传感器数据固定为RotationVectorResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.ROTATION_VECTOR, (data: sensor.RotationVectorResponse) => {  
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
    console.info('Succeeded in invoking once. Scalar quantity: ' + data.w);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次大幅动作检测传感器数据。  
 **调用形式：**     
- once(type: SensorId.SIGNIFICANT_MOTION, callback: Callback\<SignificantMotionResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.SIGNIFICANT_MOTION | true | 传感器类型，该值固定为SensorId.SIGNIFICANT_MOTION。 |  
| callback | Callback<SignificantMotionResponse> | true | 回调函数，异步上报的传感器数据固定为SignificantMotionResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.SIGNIFICANT_MOTION, (data: sensor.SignificantMotionResponse) => {  
    console.info('Succeeded in invoking once. Scalar data: ' + data.scalar);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## once<sup>(9+)</sup>    
获取一次佩戴检测传感器数据。  
 **调用形式：**     
- once(type: SensorId.WEAR_DETECTION, callback: Callback\<WearDetectionResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.WEAR_DETECTION | true | 传感器类型，该值固定为SensorId.WEAR_DETECTION。 |  
| callback | Callback<WearDetectionResponse> | true | 回调函数，异步上报的传感器数据固定为WearDetectionResponse。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.once(sensor.SensorId.WEAR_DETECTION, (data: sensor.WearDetectionResponse) => {  
    console.info('Succeeded in invoking once. Wear status: ' + data.value);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke once. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅加速度传感器数据。  
 **调用形式：**     
- off(type: SensorId.ACCELEROMETER, callback?: Callback\<AccelerometerResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ACCELEROMETER | true | 传感器类型，该值固定为SensorId.ACCELEROMETER。 |  
| callback | Callback<AccelerometerResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.ACCELEROMETER, callback1);  
  sensor.on(sensor.SensorId.ACCELEROMETER, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.ACCELEROMETER, callback1);  
  // 取消SensorId.ACCELEROMETER类型的所有回调  
  sensor.off(sensor.SensorId.ACCELEROMETER);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅未校准加速度传感器数据。  
 **调用形式：**     
- off(type: SensorId.ACCELEROMETER_UNCALIBRATED, callback?: Callback\<AccelerometerUncalibratedResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ACCELEROMETER_UNCALIBRATED | true | 传感器类型，该值固定为SensorId.ACCELEROMETER_UNCALIBRATED。 |  
| callback | Callback<AccelerometerUncalibratedResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, callback1);  
  sensor.on(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.ACCELEROMETER_UNCALIBRATED, callback1);  
  // 取消注册SensorId.ACCELEROMETER_UNCALIBRATED类型的所有回调  
  sensor.off(sensor.SensorId.ACCELEROMETER_UNCALIBRATED);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅环境光传感器数据。  
 **调用形式：**     
- off(type: SensorId.AMBIENT_LIGHT, callback?: Callback\<LightResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.AMBIENT_LIGHT | true | 传感器类型，该值固定为SensorId.AMBIENT_LIGHT。 |  
| callback | Callback<LightResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.AMBIENT_LIGHT, callback1);  
  sensor.on(sensor.SensorId.AMBIENT_LIGHT, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.AMBIENT_LIGHT, callback1);  
  // 取消注册SensorId.AMBIENT_LIGHT  
  sensor.off(sensor.SensorId.AMBIENT_LIGHT);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅温度传感器数据。  
 **调用形式：**     
- off(type: SensorId.AMBIENT_TEMPERATURE, callback?: Callback\<AmbientTemperatureResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.AMBIENT_TEMPERATURE | true | 传感器类型，该值固定为SensorId.AMBIENT_TEMPERATURE。 |  
| callback | Callback<AmbientTemperatureResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.AMBIENT_TEMPERATURE, callback1);  
  sensor.on(sensor.SensorId.AMBIENT_TEMPERATURE, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.AMBIENT_TEMPERATURE, callback1);  
  // 取消注册SensorId.AMBIENT_TEMPERATURE的所有回调  
  sensor.off(sensor.SensorId.AMBIENT_TEMPERATURE);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅气压计传感器数据。  
 **调用形式：**     
- off(type: SensorId.BAROMETER, callback?: Callback\<BarometerResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.BAROMETER | true | 传感器类型，该值固定为SensorId.BAROMETER。 |  
| callback | Callback<BarometerResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
    console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
    console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
    sensor.on(sensor.SensorId.BAROMETER, callback1);  
    sensor.on(sensor.SensorId.BAROMETER, callback2);  
    // 仅取消callback1的注册  
    sensor.off(sensor.SensorId.BAROMETER, callback1);  
    // 取消注册SensorId.BAROMETER的所有回调  
    sensor.off(sensor.SensorId.BAROMETER);  
} catch (error) {  
    let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
    console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅重力传感器数据。  
 **调用形式：**     
- off(type: SensorId.GRAVITY, callback?: Callback\<GravityResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.GRAVITY | true | 传感器类型，该值固定为SensorId.GRAVITY。  |  
| callback | Callback<GravityResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.GRAVITY, callback1);  
  sensor.on(sensor.SensorId.GRAVITY, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.GRAVITY, callback1);  
  // 取消注册SensorId.GRAVITY的所有回调  
  sensor.off(sensor.SensorId.GRAVITY);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅陀螺仪传感器数据。  
 **调用形式：**     
- off(type: SensorId.GYROSCOPE, callback?: Callback\<GyroscopeResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.GYROSCOPE | true | 传感器类型，该值固定为SensorId.GYROSCOPE。 |  
| callback | Callback<GyroscopeResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.GYROSCOPE, callback1);  
  sensor.on(sensor.SensorId.GYROSCOPE, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.GYROSCOPE, callback1);  
  // 取消注册SensorId.GYROSCOPE的所有回调  
  sensor.off(sensor.SensorId.GYROSCOPE);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅未校准陀螺仪传感器数据。  
 **调用形式：**     
- off(type: SensorId.GYROSCOPE_UNCALIBRATED, callback?: Callback\<GyroscopeUncalibratedResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.GYROSCOPE_UNCALIBRATED | true | 传感器类型，该值固定为SensorId.GYROSCOPE_UNCALIBRATED |  
| callback | Callback<GyroscopeUncalibratedResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.GYROSCOPE_UNCALIBRATED, callback1);  
  sensor.on(sensor.SensorId.GYROSCOPE_UNCALIBRATED, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.GYROSCOPE_UNCALIBRATED, callback1);  
  // 取消注册SensorId.GYROSCOPE_UNCALIBRATED的所有回调  
  sensor.off(sensor.SensorId.GYROSCOPE_UNCALIBRATED);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅霍尔传感器数据。  
 **调用形式：**     
- off(type: SensorId.HALL, callback?: Callback\<HallResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.HALL | true | 传感器类型，该值固定为SensorId.HALL。 |  
| callback | Callback<HallResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.HALL, callback1);  
  sensor.on(sensor.SensorId.HALL, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.HALL, callback1);  
  // 取消注册SensorId.HALL的所有回调  
  sensor.off(sensor.SensorId.HALL);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅心率传感器数据。  
 **调用形式：**     
- off(type: SensorId.HEART_RATE, callback?: Callback\<HeartRateResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.READ_HEALTH_DATA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.HEART_RATE | true | 传感器类型，该值固定为SensorId.HEART_RATE。 |  
| callback | Callback<HeartRateResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.HEART_RATE, callback1);  
  sensor.on(sensor.SensorId.HEART_RATE, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.HEART_RATE, callback1);  
  // 取消注册SensorId.HEART_RATE的所有回调  
  sensor.off(sensor.SensorId.HEART_RATE);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅湿度传感器数据。  
 **调用形式：**     
- off(type: SensorId.HUMIDITY, callback?: Callback\<HumidityResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.HUMIDITY | true | 传感器类型，该值固定为SensorId.HUMIDITY。 |  
| callback | Callback<HumidityResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.HUMIDITY, callback1);  
  sensor.on(sensor.SensorId.HUMIDITY, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.HUMIDITY, callback1);  
  // 取消注册SensorId.HUMIDITY的所有回调  
  sensor.off(sensor.SensorId.HUMIDITY);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅线性加速度传感器数据。  
 **调用形式：**     
- off(type: SensorId.LINEAR_ACCELEROMETER, callback?: Callback\<LinearAccelerometerResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.LINEAR_ACCELEROMETER | true | 传感器类型，该值固定为SensorId.LINEAR_ACCELERATION。 |  
| callback | Callback<LinearAccelerometerResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.LINEAR_ACCELEROMETER, callback1);  
  sensor.on(sensor.SensorId.LINEAR_ACCELEROMETER, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.LINEAR_ACCELEROMETER, callback1);  
  // 取消注册SensorId.LINEAR_ACCELEROMETER的所有回调  
  sensor.off(sensor.SensorId.LINEAR_ACCELEROMETER);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅磁场传感器数据。  
 **调用形式：**     
- off(type: SensorId.MAGNETIC_FIELD, callback?: Callback\<MagneticFieldResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.MAGNETIC_FIELD | true | 传感器类型，该值固定为SensorId.MAGNETIC_FIELD。 |  
| callback | Callback<MagneticFieldResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.MAGNETIC_FIELD, callback1);  
  sensor.on(sensor.SensorId.MAGNETIC_FIELD, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.MAGNETIC_FIELD, callback1);  
  // 取消注册SensorId.MAGNETIC_FIELD的所有回调  
  sensor.off(sensor.SensorId.MAGNETIC_FIELD);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅未校准的磁场传感器数据。  
 **调用形式：**     
- off(type: SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback?: Callback\<MagneticFieldUncalibratedResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.MAGNETIC_FIELD_UNCALIBRATED | true | 传感器类型，该值固定为SensorId.MAGNETIC_FIELD_UNCALIBRATED。 |  
| callback | Callback<MagneticFieldUncalibratedResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback1);  
  sensor.on(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED, callback1);  
  // 取消注册SensorId.MAGNETIC_FIELD_UNCALIBRATED的所有回调  
  sensor.off(sensor.SensorId.MAGNETIC_FIELD_UNCALIBRATED);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅方向传感器数据。  
 **调用形式：**     
- off(type: SensorId.ORIENTATION, callback?: Callback\<OrientationResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ORIENTATION | true | 传感器类型，该值固定为SensorId.ORIENTATION。  |  
| callback | Callback<OrientationResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.ORIENTATION, callback1);  
  sensor.on(sensor.SensorId.ORIENTATION, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.ORIENTATION, callback1);  
  // 取消注册SensorId.ORIENTATION的所有回调  
  sensor.off(sensor.SensorId.ORIENTATION);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅计步器传感器数据。  
 **调用形式：**     
- off(type: SensorId.PEDOMETER, callback?: Callback\<PedometerResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.PEDOMETER | true | 传感器类型，该值固定为SensorId.PEDOMETER。 |  
| callback | Callback<PedometerResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.PEDOMETER, callback1);  
  sensor.on(sensor.SensorId.PEDOMETER, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.PEDOMETER, callback1);  
  // 取消注册SensorId.ORIENTATION的所有回调  
  sensor.off(sensor.SensorId.PEDOMETER);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅计步检测器传感器数据。  
 **调用形式：**     
- off(type: SensorId.PEDOMETER_DETECTION, callback?: Callback\<PedometerDetectionResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.PEDOMETER_DETECTION | true | 传感器类型，该值固定为SensorId.PEDOMETER_DETECTION。 |  
| callback | Callback<PedometerDetectionResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.PEDOMETER_DETECTION, callback1);  
  sensor.on(sensor.SensorId.PEDOMETER_DETECTION, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.PEDOMETER_DETECTION, callback1);  
  // 取消注册SensorId.PEDOMETER_DETECTION的所有回调  
  sensor.off(sensor.SensorId.PEDOMETER_DETECTION);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅接近光传感器数据。  
 **调用形式：**     
- off(type: SensorId.PROXIMITY, callback?: Callback\<ProximityResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.PROXIMITY | true | 传感器类型，该值固定为SensorId.PROXIMITY。 |  
| callback | Callback<ProximityResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.PROXIMITY, callback1);  
  sensor.on(sensor.SensorId.PROXIMITY, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.PROXIMITY, callback1);  
  // 取消注册SensorId.PROXIMITY的所有回调  
  sensor.off(sensor.SensorId.PROXIMITY);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅旋转矢量传感器数据。  
 **调用形式：**     
- off(type: SensorId.ROTATION_VECTOR, callback?: Callback\<RotationVectorResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.ROTATION_VECTOR | true | 传感器类型，该值固定为SensorId.ROTATION_VECTOR。 |  
| callback | Callback<RotationVectorResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```null    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.ROTATION_VECTOR, callback1);  
  sensor.on(sensor.SensorId.ROTATION_VECTOR, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.ROTATION_VECTOR, callback1);  
  // 取消注册SensorId.ROTATION_VECTOR的所有回调  
  sensor.off(sensor.SensorId.ROTATION_VECTOR);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消大幅动作检测传感器数据。  
 **调用形式：**     
- off(type: SensorId.SIGNIFICANT_MOTION, callback?: Callback\<SignificantMotionResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.SIGNIFICANT_MOTION | true | 传感器类型，该值固定为SensorId.SIGNIFICANT_MOTION。 |  
| callback | Callback<SignificantMotionResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.SIGNIFICANT_MOTION, callback1);  
  sensor.on(sensor.SensorId.SIGNIFICANT_MOTION, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.SIGNIFICANT_MOTION, callback1);  
  // 取消注册SensorId.SIGNIFICANT_MOTION的所有回调  
  sensor.off(sensor.SensorId.SIGNIFICANT_MOTION);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## off<sup>(9+)</sup>    
取消订阅佩戴检测传感器数据。  
 **调用形式：**     
- off(type: SensorId.WEAR_DETECTION, callback?: Callback\<WearDetectionResponse>): void  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId.WEAR_DETECTION | true | 传感器类型，该值固定为SensorId.WEAR_DETECTION。 |  
| callback | Callback<WearDetectionResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
function callback1(data: object) {  
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(data));  
}  
  
function callback2(data: object) {  
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(data));  
}  
  
try {  
  sensor.on(sensor.SensorId.WEAR_DETECTION, callback1);  
  sensor.on(sensor.SensorId.WEAR_DETECTION, callback2);  
  // 仅取消callback1的注册  
  sensor.off(sensor.SensorId.WEAR_DETECTION, callback1);  
  // 取消注册SensorId.WEAR_DETECTION的所有回调  
  sensor.off(sensor.SensorId.WEAR_DETECTION);  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to invoke off. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## on<sup>(deprecated)</sup>    
监听加速度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback\<AccelerometerResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ACCELEROMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ACCELEROMETER | true | 要订阅的加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER。 |  
| callback<sup>(deprecated)</sup> | Callback<AccelerometerResponse> | true | 注册加速度传感器的回调函数，上报的数据类型为AccelerometerResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, (data: sensor.AccelerometerResponse) => {  
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
监听未校准加速度计传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback: Callback\<AccelerometerUncalibratedResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ACCELEROMETER_UNCALIBRATED。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | true | 要订阅的未校准加速度计传感器类型为SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED。 |  
| callback<sup>(deprecated)</sup> | Callback<AccelerometerUncalibratedResponse> | true | 注册未校准加速度计传感器的回调函数，上报的数据类型为AccelerometerUncalibratedResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
## on<sup>(deprecated)</sup>    
监听环境光传感器的数据变化。如果多次调用该接口，仅最后一次调用生效  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback\<LightResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#AMBIENT_LIGHT。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT | true | 要订阅的环境光传感器类型为SENSOR_TYPE_ID_AMBIENT_LIGHT。 |  
| callback<sup>(deprecated)</sup> | Callback<LightResponse> | true | 注册环境光传感器的回调函数，上报的数据类型为LightResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
## on<sup>(deprecated)</sup>    
监听环境温度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback: Callback\<AmbientTemperatureResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#AMBIENT_TEMPERATURE。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | true | 要订阅的环境温度传感器类型为SENSOR_TYPE_ID_AMBIENT_TEMPERATURE。 |  
| callback<sup>(deprecated)</sup> | Callback<AmbientTemperatureResponse> | true | 注册环境温度传感器的回调函数，上报的数据类型为AmbientTemperatureResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
## on<sup>(deprecated)</sup>    
监听气压计传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback\<BarometerResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#BAROMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_BAROMETER | true | 要订阅的气压计传感器类型为SENSOR_TYPE_ID_BAROMETER。 |  
| callback<sup>(deprecated)</sup> | Callback<BarometerResponse> | true | 注册气压计传感器的回调函数，上报的数据类型为BarometerResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
## on<sup>(deprecated)</sup>    
监听重力传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback\<GravityResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#GRAVITY。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_GRAVITY | true | 要订阅的重力传感器类型为SENSOR_TYPE_ID_GRAVITY。 |  
| callback<sup>(deprecated)</sup> | Callback<GravityResponse> | true | 注册重力传感器的回调函数，上报的数据类型为GravityResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
## on<sup>(deprecated)</sup>    
监听陀螺仪传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback\<GyroscopeResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#GYROSCOPE。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_GYROSCOPE | true | 要订阅的陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE。 |  
| callback<sup>(deprecated)</sup> | Callback<GyroscopeResponse> | true | 注册陀螺仪传感器的回调函数，上报的数据类型为GyroscopeResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
## on<sup>(deprecated)</sup>    
监听未校准陀螺仪传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback: Callback\<GyroscopeUncalibratedResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#GYROSCOPE_UNCALIBRATED。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | true | 要订阅的未校准陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED。 |  
| callback<sup>(deprecated)</sup> | Callback<GyroscopeUncalibratedResponse> | true | 注册未校准陀螺仪传感器的回调函数，上报的数据类型为GyroscopeUncalibratedResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
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
  
    
## on<sup>(deprecated)</sup>    
监听霍尔传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback\<HallResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#HALL。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_HALL | true | 要订阅的霍尔传感器类型为SENSOR_TYPE_ID_HALL。 |  
| callback<sup>(deprecated)</sup> | Callback<HallResponse> | true | 注册霍尔传感器的回调函数，上报的数据类型为HallResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，默认值为200000000ns。当霍尔事件被触发的很频繁时，该参数用于限定事件上报的频率。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HALL, (data: sensor.HallResponse) => {  
  console.info('Succeeded in invoking on. Status: ' + data.status);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
监听心率传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback\<HeartRateResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#HEART_RATE。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.HEALTH_DATA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_HEART_RATE | true | 要订阅的心率传感器类型为SENSOR_TYPE_ID_HEART_RATE。 |  
| callback<sup>(deprecated)</sup> | Callback<HeartRateResponse> | true | 注册心率传感器的回调函数，上报的数据类型为HeartRateResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
## on<sup>(deprecated)</sup>    
监听湿度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback\<HumidityResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#HUMIDITY。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_HUMIDITY | true | 要订阅的湿度传感器类型为SENSOR_TYPE_ID_HUMIDITY。 |  
| callback<sup>(deprecated)</sup> | Callback<HumidityResponse> | true | 注册湿度传感器的回调函数，上报的数据类型为HumidityResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, (data: sensor.HumidityResponse) => {  
  console.info('Succeeded in invoking on. Humidity: ' + data.humidity);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
监听线性加速度传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback: Callback\<LinearAccelerometerResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#LINEAR_ACCELEROMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION | true | 要订阅的线性加速度传感器类型为SENSOR_TYPE_ID_LINEAR_ACCELERATION。 |  
| callback<sup>(deprecated)</sup> | Callback<LinearAccelerometerResponse> | true | 注册线性加速度传感器的回调函数，上报的数据类型为LinearAccelerometerResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
## on<sup>(deprecated)</sup>    
监听磁场传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback\<MagneticFieldResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#MAGNETIC_FIELD。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD | true | 要订阅的磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD。 |  
| callback<sup>(deprecated)</sup> | Callback<MagneticFieldResponse> | true | 注册磁场传感器的回调函数，上报的数据类型为MagneticFieldResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, (data: sensor.MagneticFieldResponse) => {  
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
监听未校准磁场传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback: Callback\<MagneticFieldUncalibratedResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#MAGNETIC_FIELD_UNCALIBRATED。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | true | 要订阅的未校准磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED。 |  
| callback<sup>(deprecated)</sup> | Callback<MagneticFieldUncalibratedResponse> | true | 注册未校准磁场传感器的回调函数，上报的数据类型为MagneticFieldUncalibratedResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
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
  
    
## on<sup>(deprecated)</sup>    
监听方向传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback\<OrientationResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ORIENTATION。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ORIENTATION | true | 要订阅的方向传感器类型为SENSOR_TYPE_ID_ORIENTATION |  
| callback<sup>(deprecated)</sup> | Callback<OrientationResponse> | true | 注册方向传感器的回调函数，上报的数据类型为OrientationResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, (data: sensor.OrientationResponse) => {  
  console.info('Succeeded in the device rotating at an angle around the X axis: ' + data.beta);  
  console.info('Succeeded in the device rotating at an angle around the Y axis: ' + data.gamma);  
  console.info('Succeeded in the device rotating at an angle around the Z axis: ' + data.alpha);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
监听计步传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback\<PedometerResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#PEDOMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_PEDOMETER | true | 要订阅的计步传感器类型为SENSOR_TYPE_ID_PEDOMETER。 |  
| callback<sup>(deprecated)</sup> | Callback<PedometerResponse> | true | 注册计步传感器的回调函数，上报的数据类型为PedometerResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, (data: sensor.PedometerResponse) => {  
  console.info('Succeeded in invoking on. Steps: ' + data.steps);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
监听计步检测传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback\<PedometerDetectionResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#PEDOMETER_DETECTION。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION | true | 要订阅的计步检测传感器类型为SENSOR_TYPE_ID_PEDOMETER_DETECTION。 |  
| callback<sup>(deprecated)</sup> | Callback<PedometerDetectionResponse> | true | 注册计步检测传感器的回调函数，上报的数据类型为PedometerDetectionResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, (data: sensor.PedometerDetectionResponse) => {  
  console.info('Succeeded in invoking on. Scalar data: ' + data.scalar);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
监听接近光传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback\<ProximityResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#PROXIMITY。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_PROXIMITY | true | 要订阅的接近光传感器类型为SENSOR_TYPE_ID_PROXIMITY。 |  
| callback<sup>(deprecated)</sup> | Callback<ProximityResponse> | true | 注册接近光传感器的回调函数，上报的数据类型为ProximityResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，默认值为200000000ns。当接近光事件被触发的很频繁时，该参数用于限定事件上报的频率。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, (data: sensor.ProximityResponse) => {  
  console.info('Succeeded in invoking on. Distance: ' + data.distance);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
<span style="letter-spacing: 0px;">监听旋转矢量传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。</span>。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: Callback\<RotationVectorResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ROTATION_VECTOR。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR | true | 要订阅的旋转矢量传感器类型为SENSOR_TYPE_ID_ROTATION_VECTOR。 |  
| callback<sup>(deprecated)</sup> | Callback<RotationVectorResponse> | true | 注册旋转矢量传感器的回调函数，上报的数据类型为RotationVectorResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, (data: sensor.RotationVectorResponse) => {  
  console.info('Succeeded in invoking on. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking on. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking on. Z-coordinate component: ' + data.z);  
  console.info('Succeeded in invoking on. Scalar quantity: ' + data.w);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
监听大幅动作传感器数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: Callback\<SignificantMotionResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#SIGNIFICANT_MOTION。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION | true | 要订阅的大幅动作传感器类型为SENSOR_TYPE_ID_SIGNIFICANT_MOTION。 |  
| callback<sup>(deprecated)</sup> | Callback<SignificantMotionResponse> | true | 注册有效运动传感器的回调函数，上报的数据类型为SignificantMotionResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, (data: sensor.SignificantMotionResponse) => {  
  console.info('Succeeded in invoking on. Scalar data: ' + data.scalar);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## on<sup>(deprecated)</sup>    
监听所佩戴的检测传感器的数据变化。如果多次调用该接口，仅最后一次调用生效。  
 **调用形式：**     
- on(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback\<WearDetectionResponse>,    options?: Options): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#WEAR_DETECTION。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_WEAR_DETECTION | true | 要订阅的佩戴检测传感器类型为SENSOR_TYPE_ID_WEAR_DETECTION。 |  
| callback<sup>(deprecated)</sup> | Callback<WearDetectionResponse> | true | 注册佩戴检测传感器的回调函数，上报的数据类型为WearDetectionResponse。 |  
| options<sup>(deprecated)</sup> | Options | false | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.on(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, (data: sensor.WearDetectionResponse) => {  
  console.info('Succeeded in invoking on. Wear status: ' + data.value);  
},  
  { interval: 100000000 }  
);    
```    
  
    
## once<sup>(deprecated)</sup>    
监听加速度传感器的数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback\<AccelerometerResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ACCELEROMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ACCELEROMETER | true | 加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER。 |  
| callback<sup>(deprecated)</sup> | Callback<AccelerometerResponse> | true | 注册一次加速度传感器的回调函数，上报的数据类型为AccelerometerResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, (data: sensor.AccelerometerResponse) => {  
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听未校准加速度传感器的数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback: Callback\<AccelerometerUncalibratedResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ACCELEROMETER_UNCALIBRATED。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | true | 未校准加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED。 |  
| callback<sup>(deprecated)</sup> | Callback<AccelerometerUncalibratedResponse> | true | 注册一次未校准加速度传感器的回调函数，上报的数据类型为AccelerometerUncalibratedResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, (data: sensor.AccelerometerUncalibratedResponse) => {  
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
  console.info('Succeeded in invoking once. X-coordinate bias: ' + data.biasX);  
  console.info('Succeeded in invoking once. Y-coordinate bias: ' + data.biasY);  
  console.info('Succeeded in invoking once. Z-coordinate bias: ' + data.biasZ);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听环境光传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback\<LightResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#AMBIENT_LIGHT。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT | true | 环境光传感器类型为SENSOR_TYPE_ID_AMBIENT_LIGHT。 |  
| callback<sup>(deprecated)</sup> | Callback<LightResponse> | true | 注册一次环境光传感器的回调函数，上报的数据类型为LightResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, (data: sensor.LightResponse) => {  
  console.info('Succeeded in invoking once. invoking once. Illumination: ' + data.intensity);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听环境温度传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback: Callback\<AmbientTemperatureResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#AMBIENT_TEMPERATURE。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | true | 环境温度传感器类型为SENSOR_TYPE_ID_AMBIENT_TEMPERATURE。 |  
| callback<sup>(deprecated)</sup> | Callback<AmbientTemperatureResponse> | true | 注册一次环境温度传感器的回调函数，上报的数据类型为AmbientTemperatureResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, (data: sensor.AmbientTemperatureResponse) => {  
  console.info('Succeeded in invoking once. Temperature: ' + data.temperature);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听气压计传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback\<BarometerResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#BAROMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_BAROMETER | true | 气压计传感器类型为SENSOR_TYPE_ID_BAROMETER。 |  
| callback<sup>(deprecated)</sup> | Callback<BarometerResponse> | true | 注册一次气压计传感器的回调函数，上报的数据类型为BarometerResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, (data: sensor.BarometerResponse) => {  
  console.info('Succeeded in invoking once. Atmospheric pressure: ' + data.pressure);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听重力传感器的数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback\<GravityResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#GRAVITY。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_GRAVITY | true | 重力传感器类型为SENSOR_TYPE_ID_GRAVITY。 |  
| callback<sup>(deprecated)</sup> | Callback<GravityResponse> | true | 注册一次重力传感器的回调函数，上报的数据类型为GravityResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, (data: sensor.GravityResponse) => {  
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
  });    
```    
  
    
## once<sup>(deprecated)</sup>    
监听陀螺仪传感器的数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback\<GyroscopeResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#GYROSCOPE。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_GYROSCOPE | true | 陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE。 |  
| callback<sup>(deprecated)</sup> | Callback<GyroscopeResponse> | true | 注册一次陀螺仪传感器的回调函数，上报的数据类型为GyroscopeResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, (data: sensor.GyroscopeResponse) => {  
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听未校准陀螺仪传感器的数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback: Callback\<GyroscopeUncalibratedResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#GYROSCOPE_UNCALIBRATED。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | true | 未校准陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED。 |  
| callback<sup>(deprecated)</sup> | Callback<GyroscopeUncalibratedResponse> | true | 注册一次未校准陀螺仪传感器的回调函数，上报的数据类型为GyroscopeUncalibratedResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, (data: sensor.GyroscopeUncalibratedResponse) => {  
    console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
    console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
    console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
    console.info('Succeeded in invoking once. X-coordinate bias: ' + data.biasX);  
    console.info('Succeeded in invoking once. Y-coordinate bias: ' + data.biasY);  
    console.info('Succeeded in invoking once. Z-coordinate bias: ' + data.biasZ);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听霍尔传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback\<HallResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#HALL。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_HALL | true | 霍尔传感器类型为SENSOR_TYPE_ID_HALL。 |  
| callback<sup>(deprecated)</sup> | Callback<HallResponse> | true | 注册一次霍尔传感器的回调函数，上报的数据类型为HallResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HALL, (data: sensor.HallResponse) => {  
  console.info('Succeeded in invoking once. Status: ' + data.status);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听心率传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback\<HeartRateResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#HEART_RATE。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.HEART_RATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_HEART_RATE | true | 心率传感器类型为SENSOR_TYPE_ID_HEART_RATE。 |  
| callback<sup>(deprecated)</sup> | Callback<HeartRateResponse> | true | 注册一次心率传感器的回调函数，上报的数据类型为HeartRateResponse。 |  
    
## once<sup>(deprecated)</sup>    
监听湿度传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback\<HumidityResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#HUMIDITY。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_HUMIDITY | true | 湿度传感器类型为SENSOR_TYPE_ID_HUMIDITY。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<HumidityResponse> | true | 注册一次湿度传感器的回调函数，上报的数据类型为HumidityResponse。<br/> |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, (data: sensor.HumidityResponse) => {  
  console.info('Succeeded in invoking once. Humidity: ' + data.humidity);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听线性加速度传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback: Callback\<LinearAccelerometerResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#LINEAR_ACCELEROMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELERATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION | true | 线性加速度传感器类型为SENSOR_TYPE_ID_LINEAR_ACCELERATION。 |  
| callback<sup>(deprecated)</sup> | Callback<LinearAccelerometerResponse> | true | 注册一次线性加速度传感器的回调函数，上报的数据类型为LinearAccelerometerResponse。 |  
    
## once<sup>(deprecated)</sup>    
监听磁场传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback\<MagneticFieldResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#MAGNETIC_FIELD。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD | true | 磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD。 |  
| callback<sup>(deprecated)</sup> | Callback<MagneticFieldResponse> | true | 注册一次磁场传感器的回调函数，上报的数据类型为MagneticFieldResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, (data: sensor.MagneticFieldResponse) => {  
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听未校准磁场传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback: Callback\<MagneticFieldUncalibratedResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#MAGNETIC_FIELD_UNCALIBRATED。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | true | 未校准磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED。 |  
| callback<sup>(deprecated)</sup> | Callback<MagneticFieldUncalibratedResponse> | true | 注册一次未校准磁场传感器的回调函数，上报的数据类型为MagneticFieldUncalibratedResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, (data: sensor.MagneticFieldUncalibratedResponse) => {  
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
  console.info('Succeeded in invoking once. X-coordinate bias: ' + data.biasX);  
  console.info('Succeeded in invoking once. Y-coordinate bias: ' + data.biasY);  
  console.info('Succeeded in invoking once. Z-coordinate bias: ' + data.biasZ);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听方向传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback\<OrientationResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ORIENTATION。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ORIENTATION | true | 方向传感器类型为SENSOR_TYPE_ID_ORIENTATION。 |  
| callback<sup>(deprecated)</sup> | Callback<OrientationResponse> | true | 注册一次方向传感器的回调函数，上报的数据类型为OrientationResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, (data: sensor.OrientationResponse) => {  
  console.info('Succeeded in invoking the device rotateing at an angle around the X axis: ' + data.beta);  
  console.info('Succeeded in invoking the device rotateing at an angle around the Y axis: ' + data.gamma);  
  console.info('Succeeded in invoking the device rotateing at an angle around the Z axis: ' + data.alpha);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听计步检测传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback\<PedometerResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#PEDOMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_PEDOMETER | true | 计步检测传感器类型为SENSOR_TYPE_ID_PEDOMETER_DETECTION。 |  
| callback<sup>(deprecated)</sup> | Callback<PedometerResponse> | true | 注册一次计步检测传感器的回调函数，上报的数据类型为PedometerDetectionResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, (data: sensor.PedometerResponse) => {  
  console.info('Succeeded in invoking once. Steps: ' + data.steps);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听计步检测传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback\<PedometerDetectionResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#PEDOMETER_DETECTION。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION | true | 计步检测传感器类型为SENSOR_TYPE_ID_PEDOMETER_DETECTION。 |  
| callback<sup>(deprecated)</sup> | Callback<PedometerDetectionResponse> | true | 注册一次计步检测传感器的回调函数，上报的数据类型为PedometerDetectionResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, (data: sensor.PedometerDetectionResponse) => {  
  console.info('Succeeded in invoking once. Scalar data: ' + data.scalar);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听接近光传感器数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback\<ProximityResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#PROXIMITY。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_PROXIMITY | true | 接近光传感器类型为SENSOR_TYPE_ID_PROXIMITY。 |  
| callback<sup>(deprecated)</sup> | Callback<ProximityResponse> | true | 注册一次接近光传感器的回调函数，上报的数据类型为ProximityResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, (data: sensor.ProximityResponse) => {  
  console.info('Succeeded in invoking once. Distance: ' + data.distance);  
}  
);    
```    
  
    
## once<sup>(deprecated)</sup>    
<span style="letter-spacing: 0px;">监听旋转矢量传感器数据变化一次。</span>。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: Callback\<RotationVectorResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ROTATION_VECTOR。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR | true | 旋转矢量传感器类型为SENSOR_TYPE_ID_ROTATION_VECTOR。 |  
| callback<sup>(deprecated)</sup> | Callback<RotationVectorResponse> | true | 注册一次旋转矢量传感器的回调函数，上报的数据类型为RotationVectorResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, (data: sensor.RotationVectorResponse) => {  
  console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);  
  console.info('Succeeded in invoking once. Scalar quantity: ' + data.w);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听有效运动传感器的数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: Callback\<SignificantMotionResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#SIGNIFICANT_MOTION。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION | true | 有效运动传感器类型为SENSOR_TYPE_ID_SIGNIFICANT_MOTION。 |  
| callback<sup>(deprecated)</sup> | Callback<SignificantMotionResponse> | true | 注册一次有效运动传感器的回调函数，上报的数据类型为SignificantMotionResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, (data: sensor.SignificantMotionResponse) => {  
  console.info('Succeeded in invoking once. Scalar data: ' + data.scalar);  
});    
```    
  
    
## once<sup>(deprecated)</sup>    
监听所佩戴的检测传感器的数据变化一次。  
 **调用形式：**     
- once(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback\<WearDetectionResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#WEAR_DETECTION。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_WEAR_DETECTION | true | 佩戴检测传感器类型为SENSOR_TYPE_ID_WEAR_DETECTION。 |  
| callback<sup>(deprecated)</sup> | Callback<WearDetectionResponse> | true | 注册一次穿戴检测传感器的回调函数，上报的数据类型为WearDetectionResponse。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
sensor.once(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, (data: sensor.WearDetectionResponse) => {  
  console.info("Succeeded in invoking once. Wear status: " + data.value);  
});    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback?: Callback\<AccelerometerResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ACCELEROMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ACCELEROMETER | true | 要取消订阅的加速度传感器类型为SENSOR_TYPE_ID_ACCELEROMETER。 |  
| callback<sup>(deprecated)</sup> | Callback<AccelerometerResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.AccelerometerResponse) {  
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,    callback?: Callback\<AccelerometerUncalibratedResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ACCELEROMETER_UNCALIBRATED。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED | true | 要取消订阅的未校准加速度计传感器类型为SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED。 |  
| callback<sup>(deprecated)</sup> | Callback<AccelerometerUncalibratedResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
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
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback?: Callback\<LightResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#AMBIENT_LIGHT。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT | true | 要取消订阅的环境光传感器类型为SENSOR_TYPE_ID_AMBIENT_LIGHT。 |  
| callback<sup>(deprecated)</sup> | Callback<LightResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.LightResponse) {  
  console.info('Succeeded in invoking off. Illumination: ' + data.intensity);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback?: Callback\<AmbientTemperatureResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#AMBIENT_TEMPERATURE。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE | true | 要取消订阅的环境温度传感器类型为SENSOR_TYPE_ID_AMBIENT_TEMPERATU<br/> |  
| callback<sup>(deprecated)</sup> | Callback<AmbientTemperatureResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。<br/> |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.AmbientTemperatureResponse) {  
  console.info('Succeeded in invoking off. Temperature: ' + data.temperature);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback?: Callback\<BarometerResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#BAROMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_BAROMETER | true | 要取消订阅的气压计传感器类型为SENSOR_TYPE_ID_BAROMETER。 |  
| callback<sup>(deprecated)</sup> | Callback<BarometerResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.BarometerResponse) {  
  console.info('Succeeded in invoking off. Atmospheric pressure: ' + data.pressure);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_BAROMETER, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback?: Callback\<GravityResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#GRAVITY。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_GRAVITY | true | 要取消订阅的重力传感器类型为SENSOR_TYPE_ID_GRAVITY。 |  
| callback<sup>(deprecated)</sup> | Callback<GravityResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.GravityResponse) {  
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GRAVITY, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback?: Callback\<GyroscopeResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#GYROSCOPE。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_GYROSCOPE | true | 要取消订阅的陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE。 |  
| callback<sup>(deprecated)</sup> | Callback<GyroscopeResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.GyroscopeResponse) {  
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback?: Callback\<GyroscopeUncalibratedResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#GYROSCOPE_UNCALIBRATED。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED | true | 要取消订阅的未校准陀螺仪传感器类型为SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED。 |  
| callback<sup>(deprecated)</sup> | Callback<GyroscopeUncalibratedResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.GyroscopeUncalibratedResponse) {  
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_HALL, callback?: Callback\<HallResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#HALL。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_HALL | true | 要取消订阅的霍尔传感器类型为SENSOR_TYPE_ID_HALL。 |  
| callback<sup>(deprecated)</sup> | Callback<HallResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.HallResponse) {  
  console.info('Succeeded in invoking off. Status: ' + data.status);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HALL, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback?: Callback\<HeartRateResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#HEART_RATE。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.HEALTH_DATA    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_HEART_RATE | true | 要取消订阅的心率传感器类型为SENSOR_TYPE_ID_HEART_RATE。 |  
| callback<sup>(deprecated)</sup> | Callback<HeartRateResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.HeartRateResponse) {  
  console.info('Succeeded in invoking off. Humidity: ' + data.heartRate);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HEART_RATE, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback?: Callback\<HumidityResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#HUMIDITY。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_HUMIDITY | true | 要取消订阅的湿度传感器类型为SENSOR_TYPE_ID_HUMIDITY。 |  
| callback<sup>(deprecated)</sup> | Callback<HumidityResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.HumidityResponse) {  
  console.info('Succeeded in invoking off. Humidity: ' + data.humidity);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_HUMIDITY, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback?: Callback\<LinearAccelerometerResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#LINEAR_ACCELEROMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACCELEROMETER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION | true | 要取消订阅的线性加速度传感器类型为SENSOR_TYPE_ID_LINEAR_ACCELERATION。 |  
| callback<sup>(deprecated)</sup> | Callback<LinearAccelerometerResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.LinearAccelerometerResponse) {  
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback?: Callback\<MagneticFieldResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#MAGNETIC_FIELD。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD | true | 要取消订阅的磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD。 |  
| callback<sup>(deprecated)</sup> | Callback<MagneticFieldResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.MagneticFieldResponse) {  
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback?: Callback\<MagneticFieldUncalibratedResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#MAGNETIC_FIELD_UNCALIBRATED。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED | true | 要取消订阅的未校准磁场传感器类型为SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED。 |  
| callback<sup>(deprecated)</sup> | Callback<MagneticFieldUncalibratedResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
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
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback?: Callback\<OrientationResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ORIENTATION。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ORIENTATION | true | 要取消订阅的方向传感器类型为SENSOR_TYPE_ID_ORIENTATION |  
| callback<sup>(deprecated)</sup> | Callback<OrientationResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.OrientationResponse) {  
  console.info('Succeeded in invoking off. The device rotates at an angle around the X axis: ' + data.beta);  
  console.info('Succeeded in invoking off. The device rotates at an angle around the Y axis: ' + data.gamma);  
  console.info('Succeeded in invoking off. The device rotates at an angle around the Z axis: ' + data.alpha);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ORIENTATION, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback?: Callback\<PedometerResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#PEDOMETER。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_PEDOMETER | true | 要取消订阅的计步传感器类型为SENSOR_TYPE_ID_PEDOMETER。 |  
| callback<sup>(deprecated)</sup> | Callback<PedometerResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.PedometerResponse) {  
  console.info('Succeeded in invoking off. Steps: ' + data.steps);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback?: Callback\<PedometerDetectionResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#PEDOMETER_DETECTION。  
 **系统能力:**  SystemCapability.Sensors.Sensor  
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION | true | 要取消订阅的计步检测传感器类型为SENSOR_TYPE_ID_PEDOMETER_DETECTION。 |  
| callback<sup>(deprecated)</sup> | Callback<PedometerDetectionResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.PedometerDetectionResponse) {  
  console.info('Succeeded in invoking off. Scalar data: ' + data.scalar);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback?: Callback\<ProximityResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#PROXIMITY。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_PROXIMITY | true | 要取消订阅的接近光传感器类型为SENSOR_TYPE_ID_PROXIMITY。 |  
| callback<sup>(deprecated)</sup> | Callback<ProximityResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.ProximityResponse) {  
  console.info('Succeeded in invoking off. Distance: ' + data.distance);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_PROXIMITY, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback?: Callback\<RotationVectorResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#ROTATION_VECTOR。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR | true | 要取消订阅的旋转矢量传感器类型为SENSOR_TYPE_ID_ROTATION_VECTOR。 |  
| callback<sup>(deprecated)</sup> | Callback<RotationVectorResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.RotationVectorResponse) {  
  console.info('Succeeded in invoking off. X-coordinate component: ' + data.x);  
  console.info('Succeeded in invoking off. Y-coordinate component: ' + data.y);  
  console.info('Succeeded in invoking off. Z-coordinate component: ' + data.z);  
  console.info('Succeeded in invoking off. Scalar quantity: ' + data.w);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback?: Callback\<SignificantMotionResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#SIGNIFICANT_MOTION。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION | true | 要取消订阅的大幅动作传感器类型为SENSOR_TYPE_ID_SIGNIFICANT_MOTION。 |  
| callback<sup>(deprecated)</sup> | Callback<SignificantMotionResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function callback(data: sensor.SignificantMotionResponse) {  
  console.info('Succeeded in invoking off. Scalar data: ' + data.scalar);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback);    
```    
  
    
## off<sup>(deprecated)</sup>    
取消订阅传感器数据。  
 **调用形式：**     
- off(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback?: Callback\<WearDetectionResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor.SensorId#WEAR_DETECTION。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | SensorType.SENSOR_TYPE_ID_WEAR_DETECTION | true | 要取消订阅的佩戴检测传感器类型为SENSOR_TYPE_ID_WEAR_DETECTION。 |  
| callback<sup>(deprecated)</sup> | Callback<WearDetectionResponse> | false | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
  
function accCallback(data: sensor.WearDetectionResponse) {  
  console.info('Succeeded in invoking off. Wear status: ' + data.value);  
}  
  
sensor.off(sensor.SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, accCallback);    
```    
  
    
## Sensor<sup>(9+)</sup>    
指示传感器信息。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| sensorName<sup>(9+)</sup> | string | false | true | 传感器名称。 |  
| vendorName<sup>(9+)</sup> | string | false | true | 传感器供应商。 |  
| firmwareVersion<sup>(9+)</sup> | string | false | true | 传感器固件版本。 |  
| hardwareVersion<sup>(9+)</sup> | string | false | true | 传感器硬件版本。 |  
| sensorId<sup>(9+)</sup> | number | false | true | 传感器类型id。 |  
| maxRange<sup>(9+)</sup> | number | false | true | 传感器测量范围的最大值。 |  
| minSamplePeriod<sup>(9+)</sup> | number | false | true | 允许的最小采样周期。 |  
| maxSamplePeriod<sup>(9+)</sup> | number | false | true | 允许的最大采样周期。 |  
| precision<sup>(9+)</sup> | number | false | true | 传感器精度。 |  
| power<sup>(9+)</sup> | number | false | true | 传感器功率的估计值，单位：mA。 |  
    
## getSingleSensor<sup>(9+)</sup>    
获取指定传感器类型的属性信息。  
 **调用形式：**     
    
- getSingleSensor(type: SensorId, callback: AsyncCallback\<Sensor>): void    
起始版本： 9    
- getSingleSensor(type: SensorId): Promise\<Sensor>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SensorId | true | 指定传感器类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回指定传感器的属性信息。 |  
| Promise<Sensor> | 使用异步方式返回传感器信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback<span style="letter-spacing: 0px;">）：</span>  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
try {  
  sensor.getSingleSensor(sensor.SensorId.ACCELEROMETER, (err: BusinessError.BusinessError, data: sensor.Sensor) => {  
    if (err) {  
      console.error(`Failed to get singleSensor. Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in getting sensor: ' + JSON.stringify(data));  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get singleSensor. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
try {  
  sensor.getSingleSensor(sensor.SensorId.ACCELEROMETER).then((data: sensor.Sensor) => {  
    console.info('Succeeded in getting sensor: ' + JSON.stringify(data));  
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to get singleSensor . Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get singleSensor . Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## getSensorList<sup>(9+)</sup>    
获取设备上的所有传感器信息  
 **调用形式：**     
    
- getSensorList(callback: AsyncCallback\<Array\<Sensor>>): void    
起始版本： 9    
- getSensorList(): Promise\<Array\<Sensor>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回传感器属性列表。 |  
| Promise<Array<Sensor>> | Promise对象，使用异步方式返回传感器属性列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
try {  
  sensor.getSensorList((err: BusinessError.BusinessError, data: Array<sensor.Sensor>) => {  
    if (err) {  
      console.error(`Failed to get sensorList. Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    for (let i = 0; i < data.length; i++) {  
      console.info('Succeeded in getting data[' + i + ']: ' + JSON.stringify(data[i]));  
    }  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get sensorList. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）：  
  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
try {  
  sensor.getSensorList().then((data: Array<sensor.Sensor>) => {  
    for (let i = 0; i < data.length; i++) {  
      console.info('Succeeded in getting data[' + i + ']: ' + JSON.stringify(data[i]));  
    }  
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to get sensorList. Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get sensorList. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## GeomagneticResponse    
设置地磁响应对象。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 地磁场的北分量。 |  
| y | number | false | true | 地磁场的东分量。 |  
| z | number | false | true | 地磁场的垂直分量。 |  
| geomagneticDip | number | false | true | 地磁倾角，即地球磁场线与水平面的夹角。 |  
| deflectionAngle | number | false | true | 地磁偏角，即地磁北方向与正北方向在水平面上的角度。 |  
| levelIntensity | number | false | true | 地磁场的水平强度。 |  
| totalIntensity | number | false | true | 地磁场的总强度。 |  
    
## LocationOptions    
指示地理位置。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| latitude | number | false | true | 纬度。 |  
| longitude | number | false | true | 经度。 |  
| altitude | number | false | true | 海拔高度。 |  
    
## getGeomagneticField<sup>(deprecated)</sup>    
获取地球上特定位置的地磁场。<span style="letter-spacing: 0px;">获取地球上特定位置的地磁场，使用callback异步方式返回结果。</span>。  
 **调用形式：**     
- getGeomagneticField(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback\<GeomagneticResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getGeomagneticInfo。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locationOptions<sup>(deprecated)</sup> | LocationOptions | true | 地理位置。 |  
| timeMillis<sup>(deprecated)</sup> | number | true | 表示获取磁偏角的时间，单位为毫秒。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<GeomagneticResponse> | true | 异步返回磁场信息。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
sensor.getGeomagneticField({ latitude: 80, longitude: 0, altitude: 0 }, 1580486400000,   
                           (err: BusinessError.BusinessError, data: sensor.GeomagneticResponse) => {  
  if (err) {  
    console.error(`Failed to operate. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in getting sensor_getGeomagneticField_callback x: ' + data.x + ',y: ' + data.y + ',z: ' +  
  data.z + ',geomagneticDip: ' + data.geomagneticDip + ',deflectionAngle: ' + data.deflectionAngle +  
  ',levelIntensity: ' + data.levelIntensity + ',totalIntensity: ' + data.totalIntensity);  
});    
```    
  
    
## getGeomagneticField<sup>(deprecated)</sup>    
获取地球上特定位置的地磁场，使用Promise异步方式返回结果。  
 **调用形式：**     
- getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise\<GeomagneticResponse>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getGeomagneticInfo。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locationOptions<sup>(deprecated)</sup> | LocationOptions | true | 地理位置。 |  
| timeMillis<sup>(deprecated)</sup> | number | true | 表示获取磁偏角的时间，单位为毫秒。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<GeomagneticResponse> | 使用异步方式返回磁场信息。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
const promise = sensor.getGeomagneticField({ latitude: 80, longitude: 0, altitude: 0 }, 1580486400000);  
promise.then((data: sensor.GeomagneticResponse) => {  
  console.info('Succeeded in getting sensor_getGeomagneticField_promise x: ' + data.x + ',y: ' + data.y + ',z: ' +  
  data.z + ',geomagneticDip: ' + data.geomagneticDip + ',deflectionAngle: ' + data.deflectionAngle +  
  ',levelIntensity: ' + data.levelIntensity + ',totalIntensity: ' + data.totalIntensity);  
}).catch((reason: BusinessError.BusinessError) => {  
  console.error(`Failed to operate.`);  
})    
```    
  
    
## getGeomagneticInfo<sup>(9+)</sup>    
获取某时刻地球上特定位置的地磁场信息  
 **调用形式：**     
    
- getGeomagneticInfo(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback\<GeomagneticResponse>): void    
起始版本： 9    
- getGeomagneticInfo(locationOptions: LocationOptions, timeMillis: number): Promise\<GeomagneticResponse>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| locationOptions | LocationOptions | true | 地理位置，包括经度、纬度和海拔高度。 |  
| timeMillis | number | true | 获取磁偏角的时间，unix时间戳，单位毫秒。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回地磁场信息。 |  
| Promise<GeomagneticResponse> | Promise对象，使用异步方式返回地磁场信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  sensor.getGeomagneticInfo({ latitude: 80, longitude: 0, altitude: 0 }, 1580486400000,  
      (err: BusinessError.BusinessError, data: sensor.GeomagneticResponse) => {  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get geomagneticInfo. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to get geomagneticInfo. Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get geomagneticInfo. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## getAltitude<sup>(deprecated)</sup>    
根据气压值获取设备所在的海拔高度，使用Callback异步方式返回结果。  
 **调用形式：**     
- getAltitude(seaPressure: number, currentPressure: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getDeviceAltitude。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| seaPressure<sup>(deprecated)</sup> | number | true | 表示海平面气压值，单位为hPa。 |  
| currentPressure<sup>(deprecated)</sup> | number | true | 表示设备所在高度的气压值，单位为hPa。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步返回设备所在的海拔高度，单位为米。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
sensor.getAltitude(0, 200, (err: BusinessError.BusinessError, data: number) => {  
  if (err) {  
    console.error(`Failed to operate. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info("Succeeded in getting getAltitude interface get data: " + data);  
});    
```    
  
    
## getAltitude<sup>(deprecated)</sup>    
<span style="letter-spacing: 0px;">根据气压值获取设备所在的海拔高度，使用Promise异步方式返回结果。</span>。  
 **调用形式：**     
- getAltitude(seaPressure: number, currentPressure: number): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getDeviceAltitude。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| seaPressure<sup>(deprecated)</sup> | number | true | 表示海平面气压值，单位为hPa。 |  
| currentPressure<sup>(deprecated)</sup> | number | true | 表示设备所在高度的气压值，单位为hPa。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 使用异步方式返回设备所在的海拔高度（单位：米）。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
const promise = sensor.getAltitude(0, 200);  
promise.then((data: number) => {  
  console.info('Succeeded in getting sensor_getAltitude_Promise success', data);  
}).catch((err: BusinessError.BusinessError) => {  
  console.error(`Failed to operate.`);  
})    
```    
  
    
## getDeviceAltitude<sup>(9+)</sup>    
根据气压值获取海拔高度  
 **调用形式：**     
    
- getDeviceAltitude(seaPressure: number, currentPressure: number, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getDeviceAltitude(seaPressure: number, currentPressure: number): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| seaPressure | number | true | 海平面气压值，单位为hPa。 |  
| currentPressure | number | true | 指定的气压值，单位为hPa。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回指定的气压值对应的海拔高度，单位为米。 |  
| Promise<number> | Promise对象，使用异步方式返回指定的气压值对应的海拔高度，单位为米。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  let seaPressure = 1013.2;  
  let currentPressure = 1500.0;  
  sensor.getDeviceAltitude(seaPressure, currentPressure, (err: BusinessError.BusinessError, data: number) => {  
    if (err) {  
      console.error(`Failed to get altitude. Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in getting altitude: ' + data);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get altitude. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  let seaPressure = 1013.2;  
  let currentPressure = 1500.0;  
  const promise = sensor.getDeviceAltitude(seaPressure, currentPressure);  
  promise.then((data: number) => {  
    console.info('Succeeded in getting sensor_getDeviceAltitude_Promise', data);  
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to get altitude. Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get altitude. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## getGeomagneticDip<sup>(deprecated)</sup>    
根据倾斜矩阵计算地磁倾斜角，使用Callback异步方式返回结果。  
 **调用形式：**     
- getGeomagneticDip(inclinationMatrix: Array\<number>, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getInclination。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inclinationMatrix<sup>(deprecated)</sup> | Array<number> | true | 表示倾斜矩阵。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 异步返回地磁倾斜角，单位为弧度。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
sensor.getGeomagneticDip([1, 0, 0, 0, 1, 0, 0, 0, 1], (err: BusinessError.BusinessError, data: number) => {  
  if (err) {  
    console.error(`Failed to register data. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info("Succeeded in getting getGeomagneticDip interface get data: " + data);  
})    
```    
  
    
## getGeomagneticDip<sup>(deprecated)</sup>    
根据倾斜矩阵计算地磁倾斜角，使用Promise异步方式返回结果。  
 **调用形式：**     
- getGeomagneticDip(inclinationMatrix: Array\<number>): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getInclination。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inclinationMatrix<sup>(deprecated)</sup> | Array<number> | true | 表示倾斜矩阵。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 使用异步方式返回地磁倾斜角，单位为弧度。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
const promise = sensor.getGeomagneticDip([1, 0, 0, 0, 1, 0, 0, 0, 1]);  
promise.then((data: number) => {  
  console.info('Succeeded in get GeomagneticDip_promise', data);  
}).catch((err: BusinessError.BusinessError) => {  
  console.error(`Failed to operate.`);  
})    
```    
  
    
## getInclination<sup>(9+)</sup>    
根据倾斜矩阵计算地磁倾角。  
 **调用形式：**     
    
- getInclination(inclinationMatrix: Array\<number>, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getInclination(inclinationMatrix: Array\<number>): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inclinationMatrix | Array<number> | true | 倾斜矩阵。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回地磁倾角，单位为弧度。 |  
| Promise<number> | Promise对象，使用异步方式返回地磁倾斜角，单位为弧度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  // inclinationMatrix可以为3*3，或者4*4  
  let inclinationMatrix = [  
    1, 0, 0,  
    0, 1, 0,  
    0, 0, 1  
  ]  
  sensor.getInclination(inclinationMatrix, (err: BusinessError.BusinessError, data: number) => {  
    if (err) {  
      console.error(`Failed to get inclination. Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in getting inclination: ' + data);  
  })  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get inclination. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  // inclinationMatrix可以为3*3，或者4*4  
  let inclinationMatrix = [  
    1, 0, 0,  
    0, 1, 0,  
    0, 0, 1  
  ]  
  const promise = sensor.getInclination(inclinationMatrix);  
  promise.then((data: number) => {  
    console.info('Succeeded in getting inclination: ' + data);  
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to get inclination. Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get inclination. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## getAngleModify<sup>(deprecated)</sup>    
获取两个旋转矩阵之间的角度变化，使用Callback异步方式返回结果。  
 **调用形式：**     
- getAngleModify(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>,    callback: AsyncCallback\<Array\<number>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getAngleVariation。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| currentRotationMatrix<sup>(deprecated)</sup> | Array<number> | true | 表示当前旋转矩阵。 |  
| preRotationMatrix<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矩阵。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<number>> | true | 异步返回z、x、y轴方向的旋转角度变化。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
sensor.getAngleModify([1, 0, 0, 0, 1, 0, 0, 0, 1], [1, 0, 0, 0, 0.87, -0.50, 0, 0.50, 0.87],  
                      (err: BusinessError.BusinessError, data: Array<number>) => {  
  if (err) {  
    console.error(`Failed to register data. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  for (let i = 0; i < data.length; i++) {  
    console.info("data[" + i + "]: " + data[i]);  
  }  
})    
```    
  
    
## getAngleModify<sup>(deprecated)</sup>    
获取两个旋转矩阵之间的角度变化，使用Promise异步方式返回结果。  
 **调用形式：**     
- getAngleModify(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>): Promise\<Array\<number>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getAngleVariation。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| currentRotationMatrix<sup>(deprecated)</sup> | Array<number> | true | 表示当前旋转矩阵。 |  
| preRotationMatrix<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矩阵。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<number>> | 使用异步方式返回z、x、y轴方向的旋转角度变化。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
const promise = sensor.getAngleModify([1, 0, 0, 0, 1, 0, 0, 0, 1], [1, 0, 0, 0, 0.87, -0.50, 0, 0.50, 0.87]);  
promise.then((data: Array<number>) => {  
  console.info('Succeeded in getting AngleModify_promise.');  
  for (let i = 0; i < data.length; i++) {  
    console.info("Succeeded in getting data[" + i + "]: " + data[i]);  
  }  
}).catch((reason: BusinessError.BusinessError) => {  
  let e: BusinessError.BusinessError = reason as BusinessError.BusinessError;  
  console.info("Succeeded in getting promise::catch", e);  
})    
```    
  
    
## getAngleVariation<sup>(9+)</sup>    
计算两个旋转矩阵之间的角度变化，  
 **调用形式：**     
    
- getAngleVariation(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>,    callback: AsyncCallback\<Array\<number>>): void    
起始版本： 9    
- getAngleVariation(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>): Promise\<Array\<number>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| currentRotationMatrix | Array<number> | true | 当前旋转矩阵。 |  
| preRotationMatrix | Array<number> | true | 相对旋转矩阵。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回绕z、x、y轴方向的旋转角度。 |  
| Promise<Array<number>> | Promise对象，使用异步方式返回绕z、x、y轴方向的旋转角度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  // 旋转矩阵可以为3*3，或者4*4  
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
  sensor.getAngleVariation(currentRotationMatrix, preRotationMatrix, (err: BusinessError.BusinessError, data: Array<number>) => {  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get angle variation. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  // 旋转矩阵可以为3*3，或者4*4  
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
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to get angle variation. Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get angle variation. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## createRotationMatrix<sup>(deprecated)</sup>    
将旋转矢量转换为旋转矩阵，使用Callback异步方式返回结果。  
 **调用形式：**     
- createRotationMatrix(rotationVector: Array\<number>, callback: AsyncCallback\<Array\<number>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getRotationMatrix。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotationVector<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矢量。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<number>> | true | 异步返回旋转矩阵。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
sensor.createRotationMatrix([0.20046076, 0.21907, 0.73978853, 0.60376877],  
                            (err: BusinessError.BusinessError, data: Array<number>) => {  
  if (err) {  
    console.error(`Failed to register data. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  for (let i = 0; i < data.length; i++) {  
    console.info("Succeeded in getting data[" + i + "]: " + data[i]);  
  }  
})    
```    
  
    
## createRotationMatrix<sup>(deprecated)</sup>    
将旋转矢量转换为旋转矩阵，使用Promise异步方式返回结果。  
 **调用形式：**     
- createRotationMatrix(rotationVector: Array\<number>): Promise\<Array\<number>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getRotationMatrix。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotationVector<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矢量。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<number>> | 使用异步方式返回旋转矩阵。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
const promise = sensor.createRotationMatrix([0.20046076, 0.21907, 0.73978853, 0.60376877]);  
promise.then((data: Array<number>) => {  
 console.info('Succeeded in getting createRotationMatrix_promise');  
 for (let i = 0; i < data.length; i++) {  
   console.info("data[" + i + "]: " + data[i]);  
 }  
}).catch((reason: BusinessError.BusinessError) => {  
 console.info("Succeeded in getting promise::catch", reason);  
})    
```    
  
    
## getRotationMatrix<sup>(9+)</sup>    
根据重力矢量和地磁矢量计算旋转矩阵  
 **调用形式：**     
    
- getRotationMatrix(rotationVector: Array\<number>, callback: AsyncCallback\<Array\<number>>): void    
起始版本： 9    
- getRotationMatrix(rotationVector: Array\<number>): Promise\<Array\<number>>    
起始版本： 9    
- getRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>, callback: AsyncCallback\<RotationMatrixResponse>): void    
起始版本： 9    
- getRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>): Promise\<RotationMatrixResponse>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotationVector | Array<number> | true | 旋转矢量。 |  
| gravity | Array<number> | true | 重力矢量。 |  
| geomagnetic | Array<number> | true | 地磁矢量。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回3*3旋转矩阵。 |  
| Promise<Array<number>> | Promise对象，使用异步方式返回旋转矩阵。 |  
| Promise<RotationMatrixResponse> | Promise对象，使用异步方式返回旋转矩阵。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback）：参数为：rotationVector  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];  
  sensor.getRotationMatrix(rotationVector, (err: BusinessError.BusinessError, data: Array<number>) => {  
    if (err) {  
      console.error(`Failed to get rotationMatrix. Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    for (let i = 0; i < data.length; i++) {  
      console.info('Succeeded in getting data[' + i + ']: ' + data[i]);  
    }  
  })  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get rotationMatrix. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）：参数为：gravity、geomagnetic  
  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
try {  
  let gravity = [-0.27775216, 0.5351276, 9.788099];  
  let geomagnetic = [210.87253, -78.6096, -111.44444];  
  sensor.getRotationMatrix(gravity, geomagnetic, (err: BusinessError.BusinessError, data: sensor.RotationMatrixResponse) => {  
    if (err) {  
      console.error(`Failed to get rotationMatrix. Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    console.info('Succeeded in getting rotationMatrix' + JSON.stringify(data));  
  })  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get rotationMatrix. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码3：**   
示例（Promise）：参数为：rotationVector  
  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];  
  const promise = sensor.getRotationMatrix(rotationVector);  
  promise.then((data: Array<number>) => {  
    for (let i = 0; i < data.length; i++) {  
      console.info('Succeeded in getting data[' + i + ']: ' + data[i]);  
    }  
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to get rotationMatrix. Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get rotationMatrix. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码4：**   
示例（Promise）：参数为：gravity、geomagnetic  
  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
try {  
  let gravity = [-0.27775216, 0.5351276, 9.788099];  
  let geomagnetic = [210.87253, -78.6096, -111.44444];  
  const promise = sensor.getRotationMatrix(gravity, geomagnetic);  
  promise.then((data: sensor.RotationMatrixResponse) => {  
    console.info('Succeeded in getting rotationMatrix' + JSON.stringify(data));  
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to get rotationMatrix. Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get rotationMatrix. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## CoordinatesOptions    
设置坐标选项对象。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | x坐标方向。 |  
| y | number | false | true | y坐标方向。 |  
    
## transformCoordinateSystem<sup>(deprecated)</sup>    
旋转提供的旋转矩阵，使其可以以不同的方式表示坐标系，使用Callback异步方式返回结果。  
 **调用形式：**     
- transformCoordinateSystem(inRotationVector: Array\<number>, coordinates: CoordinatesOptions,    callback: AsyncCallback\<Array\<number>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#transformRotationMatrix。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inRotationVector<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矩阵。 |  
| coordinates<sup>(deprecated)</sup> | CoordinatesOptions | true | 表示坐标系方向。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<number>> | true | 异步返回转换后的旋转矩阵。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
sensor.transformCoordinateSystem([1, 0, 0, 0, 1, 0, 0, 0, 1], { x: 2, y: 3 },   
                                 (err: BusinessError.BusinessError, data: Array<number>) => {  
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
  
    
## transformCoordinateSystem<sup>(deprecated)</sup>    
旋转提供的旋转矩阵，使其可以以不同的方式表示坐标系，使用Promise异步方式返回结果。  
 **调用形式：**     
- transformCoordinateSystem(inRotationVector: Array\<number>, coordinates: CoordinatesOptions): Promise\<Array\<number>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#transformRotationMatrix。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inRotationVector<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矩阵。 |  
| coordinates<sup>(deprecated)</sup> | CoordinatesOptions | true | 表示坐标系方向。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<number>> | 使用异步方式返回转换后的旋转矩阵。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
const promise = sensor.transformCoordinateSystem([1, 0, 0, 0, 1, 0, 0, 0, 1], { x: 2, y: 3 });  
promise.then((data: Array<number>) => {  
  console.info("Succeeded in starting Operation");  
  for (let i = 0; i < data.length; i++) {  
    console.info("Succeeded in getting transformCoordinateSystem data[ " + i + "] = " + data[i]);  
  }  
}).catch((err: BusinessError.BusinessError) => {  
  console.error(`Failed to operate.`);  
})    
```    
  
    
## transformRotationMatrix<sup>(9+)</sup>    
根据指定坐标系映射旋转矩阵  
 **调用形式：**     
    
- transformRotationMatrix(inRotationVector: Array\<number>, coordinates: CoordinatesOptions,    callback: AsyncCallback\<Array\<number>>): void    
起始版本： 9    
- transformRotationMatrix(inRotationVector: Array\<number>, coordinates: CoordinatesOptions): Promise\<Array\<number>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inRotationVector | Array<number> | true | 旋转矩阵。 |  
| coordinates | CoordinatesOptions | true | 指定坐标系方向。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回映射后的旋转矩阵。 |  
| Promise<Array<number>> | Promise对象，使用异步方式返回转换后的旋转矩阵。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  let rotationMatrix = [  
    1, 0, 0,  
    0, 0.87, -0.50,  
    0, 0.50, 0.87  
  ];  
  sensor.transformRotationMatrix(rotationMatrix, { x: 1, y: 3 }, (err: BusinessError.BusinessError, data: Array<number>) => {  
    if (err) {  
      console.error(`Failed to transform rotationMatrix. Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    for (let i = 0; i < data.length; i++) {  
      console.info('Succeeded in getting data[' + i + '] = ' + data[i]);  
    }  
  })  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to transform rotationMatrix. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
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
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to transform rotationMatrix. Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to transform rotationMatrix. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## createQuaternion<sup>(deprecated)</sup>    
将旋转矢量转换为四元数，使用Callback异步方式返回结果。  
 **调用形式：**     
- createQuaternion(rotationVector: Array\<number>, callback: AsyncCallback\<Array\<number>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getQuaternion。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotationVector<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矢量。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<number>> | true | v |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
sensor.createQuaternion([0.20046076, 0.21907, 0.73978853, 0.60376877],  
                        (err: BusinessError.BusinessError, data: Array<number>) => {  
  if (err) {  
    console.error(`Failed to register data. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  for (let i = 0; i < data.length; i++) {  
    console.info("Succeeded in getting data[" + i + "]: " + data[i]);  
  }  
})    
```    
  
    
## createQuaternion<sup>(deprecated)</sup>    
将旋转矢量转换为四元数，使用Promise异步方式返回结果。  
 **调用形式：**     
- createQuaternion(rotationVector: Array\<number>): Promise\<Array\<number>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getQuaternion。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotationVector<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矢量。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<number>> | 使用异步方式返回四元数。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
const promise = sensor.createQuaternion([0.20046076, 0.21907, 0.73978853, 0.60376877]);  
promise.then((data: Array<number>) => {  
  console.info('Succeeded in getting createQuaternion_promise');  
  for (let i = 0; i < data.length; i++) {  
    console.info("data[" + i + "]: " + data[i]);  
  }  
}).catch((err: BusinessError.BusinessError) => {  
  console.info(`Failed to get promise.`);  
})    
```    
  
    
## getQuaternion<sup>(9+)</sup>    
根据旋转向量计算归一化四元数  
 **调用形式：**     
    
- getQuaternion(rotationVector: Array\<number>, callback: AsyncCallback\<Array\<number>>): void    
起始版本： 9    
- getQuaternion(rotationVector: Array\<number>): Promise\<Array\<number>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotationVector | Array<number> | true | 旋转矢量。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回归一化四元数。 |  
| Promise<Array<number>> | Promise，使用异步方式对象返归一化回四元数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];  
  sensor.getQuaternion(rotationVector, (err: BusinessError.BusinessError, data: Array<number>) => {  
    if (err) {  
      console.error(`Failed to get quaternion. Code: ${err.code}, message: ${err.message}`);  
      return;  
    }  
    for (let i = 0; i < data.length; i++) {  
      console.info('Succeeded in getting data[' + i + ']: ' + data[i]);  
    }  
  })  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get quaternion. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
    let rotationVector = [0.20046076, 0.21907, 0.73978853, 0.60376877];  
    const promise = sensor.getQuaternion(rotationVector);  
    promise.then((data: Array<number>) => {  
        for (let i = 0; i < data.length; i++) {  
            console.info('Succeeded in getting data[' + i + ']: ' + data[i]);  
        }  
    }, (err: BusinessError.BusinessError) => {  
        console.error(`Failed to get quaternion. Code: ${err.code}, message: ${err.message}`);  
    });  
} catch (error) {  
    let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
    console.error(`Failed to get quaternion. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## getDirection<sup>(deprecated)</sup>    
根据旋转矩阵计算设备的方向，使用Callback异步方式返回结果。  
 **调用形式：**     
- getDirection(rotationMatrix: Array\<number>, callback: AsyncCallback\<Array\<number>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getOrientation。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotationMatrix<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矩阵。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<number>> | true | 异步返回围绕z、x、y轴方向的旋转角度。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
sensor.getDirection([1, 0, 0, 0, 1, 0, 0, 0, 1], (err: BusinessError.BusinessError, data: Array<number>) => {  
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
  
    
## getDirection<sup>(deprecated)</sup>    
根据旋转矩阵计算设备的方向，使用Promise异步方式返回结果。  
 **调用形式：**     
- getDirection(rotationMatrix: Array\<number>): Promise\<Array\<number>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getOrientation。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotationMatrix<sup>(deprecated)</sup> | Array<number> | true | 表示旋转矩阵。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<number>> | 使用异步方式返回围绕z、x、y轴方向的旋转角度。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
const promise = sensor.getDirection([1, 0, 0, 0, 1, 0, 0, 0, 1]);  
promise.then((data: Array<number>) => {  
  console.info('Succeeded in getting sensor_getAltitude_Promise', data);  
  for (let i = 1; i < data.length; i++) {  
    console.info("Succeeded in getting sensor_getDirection_promise" + data[i]);  
  }  
}).catch((err: BusinessError.BusinessError) => {  
  console.info(`Failed to get promise.`);  
})    
```    
  
    
## getOrientation<sup>(9+)</sup>    
根据旋转矩阵计算设备方向  
 **调用形式：**     
    
- getOrientation(rotationMatrix: Array\<number>, callback: AsyncCallback\<Array\<number>>): void    
起始版本： 9    
- getOrientation(rotationMatrix: Array\<number>): Promise\<Array\<number>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rotationMatrix | Array<number> | true | 旋转矩阵。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，异步返回围绕z、x、y轴方向的旋转角度。 |  
| Promise<Array<number>> | Promise对象，使用异步方式返回围绕z、x、y轴方向的旋转角度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 14500101 | Service exception. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import sensor from "@ohos.sensor"  
import BusinessError from "@ohos.base"  
  
try {  
  let preRotationMatrix = [  
    1, 0, 0,  
    0, 0.87, -0.50,  
    0, 0.50, 0.87  
  ];  
  sensor.getOrientation(preRotationMatrix, (err: BusinessError.BusinessError, data: Array<number>) => {  
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
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to get orientation. Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
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
  }, (err: BusinessError.BusinessError) => {  
    console.error(`Failed to getOrientatin. Code: ${err.code}, message: ${err.message}`);  
  });  
} catch (error) {  
  let e: BusinessError.BusinessError = error as BusinessError.BusinessError;  
  console.error(`Failed to getOrientatin Code: ${e.code}, message: ${e.message}`);  
}  
    
```    
  
    
## RotationMatrixResponse    
设置旋转矩阵响应对象。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| rotation | Array<number> | false | true | 旋转矩阵。 |  
| inclination | Array<number> | false | true | 倾斜矩阵。 |  
    
## createRotationMatrix<sup>(deprecated)</sup>    
根据重力矢量和地磁矢量计算旋转矩阵，使用Callback异步方式返回结果。  
 **调用形式：**     
- createRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>, callback: AsyncCallback\<RotationMatrixResponse>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getRotationMatrix。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| gravity<sup>(deprecated)</sup> | Array<number> | true | 表示重力向量。 |  
| geomagnetic<sup>(deprecated)</sup> | Array<number> | true | 表示地磁矢量。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<RotationMatrixResponse> | true | 异步返回旋转矩阵。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
sensor.createRotationMatrix([-0.27775216, 0.5351276, 9.788099], [210.87253, -78.6096, -111.44444],   
                            (err: BusinessError.BusinessError, data: sensor.RotationMatrixResponse) => {  
  if (err) {  
    console.error(`Failed to get create rotationMatrix. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info(JSON.stringify(data));  
})    
```    
  
    
## createRotationMatrix<sup>(deprecated)</sup>    
根据重力矢量和地磁矢量计算旋转矩阵，使用Promise异步方式返回结果。  
 **调用形式：**     
- createRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>,): Promise\<RotationMatrixResponse>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: sensor#getRotationMatrix。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| gravity<sup>(deprecated)</sup> | Array<number> | true | 表示重力向量。 |  
| geomagnetic<sup>(deprecated)</sup> | Array<number> | true | 表示地磁矢量。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<RotationMatrixResponse> | 使用异步方式返回旋转矩阵。 |  
    
 **示例代码：**   
示例：  
```ts    
import sensor from '@ohos.sensor';  
import BusinessError from '@ohos.base';  
  
const promise = sensor.createRotationMatrix([-0.27775216, 0.5351276, 9.788099], [210.87253, -78.6096, -111.44444]);  
promise.then((data: sensor.RotationMatrixResponse) => {  
  console.info(JSON.stringify(data));  
}).catch((err: BusinessError.BusinessError) => {  
  console.info(`Failed to get promise.`);  
})    
```    
  
    
## Options    
设置传感器上报频率。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| interval | number | false | false | 表示传感器的上报频率，默认值为200000000ns。 |  
    
## SensorType<sup>(deprecated)</sup>    
表示要订阅或取消订阅的传感器类型。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用sensor.SensorId替代。    
    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SENSOR_TYPE_ID_ACCELEROMETER<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。<br>加速度传感器。 |  
| SENSOR_TYPE_ID_GYROSCOPE<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。<br>陀螺仪传感器。 |  
| SENSOR_TYPE_ID_AMBIENT_LIGHT<sup>(deprecated)</sup> | 5 | 从API version 8 开始支持，从API version 9 开始废弃。<br>环境光传感器。 |  
| SENSOR_TYPE_ID_MAGNETIC_FIELD<sup>(deprecated)</sup> | 6 | 从API version 8 开始支持，从API version 9 开始废弃。<br>磁场传感器。 |  
| SENSOR_TYPE_ID_BAROMETER<sup>(deprecated)</sup> | 8 | 从API version 8 开始支持，从API version 9 开始废弃。<br>气压计传感器。 |  
| SENSOR_TYPE_ID_HALL<sup>(deprecated)</sup> | 10 | 从API version 8 开始支持，从API version 9 开始废弃。<br>霍尔传感器。 |  
| SENSOR_TYPE_ID_PROXIMITY<sup>(deprecated)</sup> | 12 | 从API version 8 开始支持，从API version 9 开始废弃。<br>接近光传感器。 |  
| SENSOR_TYPE_ID_HUMIDITY<sup>(deprecated)</sup> | 13 | 从API version 8 开始支持，从API version 9 开始废弃。<br>湿度传感器。 |  
| SENSOR_TYPE_ID_ORIENTATION<sup>(deprecated)</sup> | 256 | 从API version 8 开始支持，从API version 9 开始废弃。<br>方向传感器。 |  
| SENSOR_TYPE_ID_GRAVITY<sup>(deprecated)</sup> | 257 | 从API version 8 开始支持，从API version 9 开始废弃。<br>重力传感器。 |  
| SENSOR_TYPE_ID_LINEAR_ACCELERATION<sup>(deprecated)</sup> | 258 | 从API version 8 开始支持，从API version 9 开始废弃。<br>线性加速度传感器。 |  
| SENSOR_TYPE_ID_ROTATION_VECTOR<sup>(deprecated)</sup> | 259 | 从API version 8 开始支持，从API version 9 开始废弃。<br>旋转矢量传感器。 |  
| SENSOR_TYPE_ID_AMBIENT_TEMPERATURE<sup>(deprecated)</sup> | 260 | 从API version 8 开始支持，从API version 9 开始废弃。<br>环境温度传感器。 |  
| SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED<sup>(deprecated)</sup> | 261 | 从API version 8 开始支持，从API version 9 开始废弃。<br>未校准磁场传感器。 |  
| SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED<sup>(deprecated)</sup> | 263 | 从API version 8 开始支持，从API version 9 开始废弃。<br>未校准陀螺仪传感器。 |  
| SENSOR_TYPE_ID_SIGNIFICANT_MOTION<sup>(deprecated)</sup> | 264 | 从API version 8 开始支持，从API version 9 开始废弃。<br>有效运动传感器。 |  
| SENSOR_TYPE_ID_PEDOMETER_DETECTION<sup>(deprecated)</sup> | 265 | 从API version 8 开始支持，从API version 9 开始废弃。<br>计步检测传感器。 |  
| SENSOR_TYPE_ID_PEDOMETER<sup>(deprecated)</sup> | 266 | 从API version 8 开始支持，从API version 9 开始废弃。<br>计步传感器。 |  
| SENSOR_TYPE_ID_HEART_RATE<sup>(deprecated)</sup> | 278 | 从API version 8 开始支持，从API version 9 开始废弃。<br>心率传感器。 |  
| SENSOR_TYPE_ID_WEAR_DETECTION<sup>(deprecated)</sup> | 280 | 从API version 8 开始支持，从API version 9 开始废弃。<br>佩戴检测传感器。 |  
| SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED<sup>(deprecated)</sup> | 281 | 从API version 8 开始支持，从API version 9 开始废弃。<br>未校准加速度计传感器。 |  
    
## Response    
传感器数据的时间戳。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| timestamp | number | false | true | 传感器数据上报的时间戳。 |  
    
## AccelerometerResponse    
加速度传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 施加在设备x轴的加速度，单位 : m/s²。 |  
| y | number | false | true | 施加在设备y轴的加速度，单位 : m/s²。 |  
| z | number | false | true | 施加在设备z轴的加速度，单位 : m/s²。 |  
    
## LinearAccelerometerResponse    
线性加速度传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 施加在设备x轴的线性加速度，单位 : m/s²。 |  
| y | number | false | true | 施加在设备y轴的线性加速度，单位 : m/s²。 |  
| z | number | false | true | 施加在设备z轴的线性加速度，单位 : m/s²。 |  
    
## AccelerometerUncalibratedResponse    
未校准加速度计传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 施加在设备x轴未校准的加速度，单位 : m/s²。 |  
| y | number | false | true | 施加在设备y轴未校准的加速度，单位 : m/s²。 |  
| z | number | false | true | 施加在设备z轴未校准的加速度，单位 : m/s²。 |  
| biasX | number | false | true | 施加在设备x轴未校准的加速度偏量，单位 : m/s²。 |  
| biasY | number | false | true | 施加在设备上y轴未校准的加速度偏量，单位 : m/s²。 |  
| biasZ | number | false | true | 施加在设备z轴未校准的加速度偏量，单位 : m/s²。 |  
    
## GravityResponse    
重力传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 施加在设备x轴的重力加速度，单位 : m/s²。 |  
| y | number | false | true | 施加在设备y轴的重力加速度，单位 : m/s²。 |  
| z | number | false | true | 施加在设备z轴的重力加速度，单位 : m/s²。 |  
    
## OrientationResponse    
方向传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| alpha | number | false | true | 设备围绕Z轴的旋转角度，单位：度。 |  
| beta | number | false | true | 设备围绕X轴的旋转角度，单位：度。 |  
| gamma | number | false | true | 设备围绕Y轴的旋转角度，单位：度。 |  
    
## RotationVectorResponse    
旋转矢量传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 旋转矢量x轴分量。 |  
| y | number | false | true | 旋转矢量y轴分量。 |  
| z | number | false | true | 旋转矢量z轴分量。 |  
| w | number | false | true | 标量。 |  
    
## GyroscopeResponse    
陀螺仪传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 设备x轴的旋转角速度，单位rad/s。 |  
| y | number | false | true | 设备y轴的旋转角速度，单位rad/s。 |  
| z | number | false | true | 设备z轴的旋转角速度，单位rad/s。 |  
    
## GyroscopeUncalibratedResponse    
未校准陀螺仪传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | 设备x轴未校准的旋转角速度，单位rad/s。 |  
| y | number | false | true | 设备y轴未校准的旋转角速度，单位rad/s。 |  
| z | number | false | true | 设备z轴未校准的旋转角速度，单位rad/s。 |  
| biasX | number | false | true | 设备x轴未校准的旋转角速度偏量，单位rad/s。 |  
| biasY | number | false | true | 设备y轴未校准的旋转角速度偏量，单位rad/s。 |  
| biasZ | number | false | true | 设备z轴未校准的旋转角速度偏量，单位rad/s。 |  
    
## SignificantMotionResponse    
有效运动传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| scalar | number | false | true | 表示剧烈运动程度。测量三个物理轴（x、y和z）上，设备是否存在大幅度运动；若存在大幅度运动则数据上报为1。 |  
    
## ProximityResponse    
接近光传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| distance | number | false | true | 可见物体与设备显示器的接近程度。0表示接近，大于0表示远离。 |  
    
## LightResponse    
<span style="letter-spacing: 0px;">环境光传感器数据，继承于[Response](#response)。</span>。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| intensity | number | false | true | 光强（单位：勒克斯）。 |  
    
## HallResponse    
霍尔传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| status | number | false | true | 显示霍尔状态。测量设备周围是否存在磁力吸引，0表示没有，大于0表示有。 |  
    
## MagneticFieldResponse    
磁场传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | x轴环境磁场强度，单位 : μT。 |  
| y | number | false | true | y轴环境磁场强度，单位 : μT。 |  
| z | number | false | true | z轴环境磁场强度，单位 : μT。 |  
    
## MagneticFieldUncalibratedResponse    
未校准磁场传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | number | false | true | x轴未校准环境磁场强度，单位 : μT。 |  
| y | number | false | true | y轴未校准环境磁场强度，单位 : μT。 |  
| z | number | false | true | z轴未校准环境磁场强度，单位 : μT。 |  
| biasX | number | false | true | x轴未校准环境磁场强度偏量，单位 : μT。 |  
| biasY | number | false | true | y轴未校准环境磁场强度偏量，单位 : μT。 |  
| biasZ | number | false | true | z轴未校准环境磁场强度偏量，单位 : μT。 |  
    
## PedometerResponse    
计步传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| steps | number | false | true | 用户的行走步数。 |  
    
## HumidityResponse    
湿度传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| humidity | number | false | true | 湿度值。测量环境的相对湿度，以百分比(%)表示。 |  
    
## PedometerDetectionResponse    
计步检测传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| scalar | number | false | true | 计步器检测。检测用户的计步动作，如果取值为1则代表用户产生了计步行走的动作，取值为0则代表用户没有发生运动。 |  
    
## AmbientTemperatureResponse    
温度传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| temperature | number | false | true | 环境温度（单位：摄氏度）。 |  
    
## BarometerResponse    
气压计传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pressure | number | false | true | 压力值（单位：百帕）。 |  
    
## HeartRateResponse    
心率传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| heartRate | number | false | true | 心率值。测量用户的心率数值，单位：bpm。 |  
    
## WearDetectionResponse    
佩戴检测传感器数据，继承于[Response](#response)。  
 **系统能力:**  SystemCapability.Sensors.Sensor    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value | number | false | true | 表示设备是否被穿戴（1表示已穿戴，0表示未穿戴）。 |  
