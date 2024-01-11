# @ohos.sensor
sensor模块提供了获取传感器数据的能力，包括订阅和取消订阅传感器数据。
> **说明**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js  
import sensor from '@ohos.sensor'
```

## SensorId
表示当前支持订阅或取消订阅的传感器类型。

**系统能力：** SystemCapability.Sensors.Sensor

| 名称 | 值 | 说明 |
| --------| --------| --------|
| ACCELEROMETER | 1 | 加速度传感器。 |
| GYROSCOPE | 2 | 陀螺仪传感器。 |
| ORIENTATION | 256 | 方向传感器。 |

## sensor.on
**ACCELEROMETER**

on(type: SensorId.ACCELEROMETER, callback: Callback<[AccelerometerResponse](#accelerometerresponse)>, options?: Options): void

订阅加速度传感器数据。

**支持元服务的起始版本：** 11

**系统能力：** SystemCapability.Sensors.Sensor

**需要权限：** ohos.permission.ACCELEROMETER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------| --------| --------| --------|
| type | SensorId.ACCELEROMETER | 是 | 传感器类型，该值固定为SensorId.ACCELEROMETER。              |
| callback | Callback<[AccelerometerResponse](#accelerometerresponse)> | 是 | 回调函数，异步上报的传感器数据固定为AccelerometerResponse。 |
| options | Options | 否 | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |


 **错误码：**
| 错误信息 | 错误码ID | 说明 |
| --------| --------| --------|
| Permission denied | 201 | 权限校验失败。 |
| Parameter error | 401 | 参数错误。 |
| Service exception | 14500101 | 服务异常。 |

**示例代码：**

```ts  
import sensor from "@ohos.sensor";
import BusinessError from "@ohos.base";

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

**GYROSCOPE**

on(type: SensorId.GYROSCOPE, callback: Callback<[GyroscopeResponse](#gyroscoperesponse)>, options?: Options): void

订阅校准的陀螺仪传感器数据。

**支持元服务的起始版本：** 11

**系统能力:**  SystemCapability.Sensors.Sensor

**需要权限：** ohos.permission.GYROSCOPE

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------| --------| --------| --------|
| type | SensorId.GYROSCOPE | 是 | 传感器类型，该值固定为SensorId.GYROSCOPE。                  |
| callback | Callback<[GyroscopeResponse](#gyroscoperesponse)> | 是 | 回调函数，异步上报的传感器数据固定为GyroscopeResponse。     |
| options | Options | 否 | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |

 **错误码：**

| 错误信息          | 错误码ID | 说明           |
| ----------------- | -------- | -------------- |
| Permission denied | 201      | 权限校验失败。 |
| Parameter error   | 401      | 参数错误。     |
| Service exception | 14500101 | 服务异常。     |

**示例代码：**

```ts  
import sensor from "@ohos.sensor";
import BusinessError from "@ohos.base";

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

**ORIENTATION**

on(type: SensorId.ORIENTATION, callback: Callback<[OrientationResponse](#orientationresponse)>, options?: Options): void

**支持元服务的起始版本：** 11

**系统能力：** SystemCapability.Sensors.Sensor

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------| --------| --------| --------|
| type | SensorId.ORIENTATION | 是 | 传感器类型，该值固定为SensorId.ORIENTATION。 |
| callback | Callback<[OrientationResponse](#orientationresponse)> | 是 | 回调函数，异步上报的传感器数据固定为OrientationResponse。 |
| options | Options | 否 | 可选参数列表，用于设置传感器上报频率，默认值为200000000ns。 |

 **错误码：**

| 错误信息          | 错误码ID | 说明           |
| ----------------- | -------- | -------------- |
| Permission denied | 201      | 权限校验失败。 |
| Parameter error   | 401      | 参数错误。     |
| Service exception | 14500101 | 服务异常。     |

 **示例代码：**
```ts  
import sensor from "@ohos.sensor";
import BusinessError from "@ohos.base";

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


## off
**ACCELEROMETER**

off(type: SensorId.ACCELEROMETER, callback?: Callback<[AccelerometerResponse](#accelerometerResponse)>): void

取消订阅加速度传感器数据。

**支持元服务的起始版本：** 11

**系统能力：** SystemCapability.Sensors.Sensor

**需要权限：** ohos.permission.ACCELEROMETER

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------| --------| --------| --------|
| type | SensorId.ACCELEROMETER | 是 | 传感器类型，该值固定为SensorId.ACCELEROMETER。 |
| callback | Callback<[AccelerometerResponse](#accelerometerResponse)> | 否 | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |

 **错误码：**

| 错误信息          | 错误码ID | 说明           |
| ----------------- | -------- | -------------- |
| Permission denied | 201      | 权限校验失败。 |
| Parameter error   | 401      | 参数错误。     |
| Service exception | 14500101 | 服务异常。     |

 **示例代码：**
```ts  
import sensor from "@ohos.sensor";
import BusinessError from "@ohos.base";

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

**GYROSCOPE**

off(type: SensorId.GYROSCOPE, callback?: Callback<[GyroscopeResponse](#gyroscopeResponse)>): void

取消订阅陀螺仪传感器数据。

**支持元服务的起始版本：** 11

**系统能力：** SystemCapability.Sensors.Sensor

**需要权限：** ohos.permission.GYROSCOPE

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------| --------| --------| --------|
| type | SensorId.GYROSCOPE | 是 | 传感器类型，该值固定为SensorId.GYROSCOPE。 |
| callback | Callback<[GyroscopeResponse](#gyroscopeResponse)> | 否 | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |

 **错误码：**

| 错误信息          | 错误码ID | 说明           |
| ----------------- | -------- | -------------- |
| Permission denied | 201      | 权限校验失败。 |
| Parameter error   | 401      | 参数错误。     |
| Service exception | 14500101 | 服务异常。     |

 **示例代码：**
```ts  
import sensor from "@ohos.sensor";
import BusinessError from "@ohos.base";

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

**ORIENTATION**

off(type: SensorId.ORIENTATION, callback?: Callback<[OrientationResponse](#orientationresponse)>): void

取消订阅方向传感器数据。

**支持元服务的起始版本：** 11

**系统能力：** SystemCapability.Sensors.Sensor

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------| --------| --------| --------|
| type | SensorId.ORIENTATION | 是 | 传感器类型，该值固定为SensorId.ORIENTATION。                 |
| callback | Callback<[OrientationResponse](#orientationresponse)> | 否 | 需要取消订阅的回调函数，若无此参数，则取消订阅当前类型的所有回调函数。 |

 **错误码：**

| 错误信息          | 错误码ID | 说明           |
| ----------------- | -------- | -------------- |
| Permission denied | 201      | 权限校验失败。 |
| Parameter error   | 401      | 参数错误。     |
| Service exception | 14500101 | 服务异常。     |

 **示例代码：**

```ts  
import sensor from "@ohos.sensor";
import BusinessError from "@ohos.base";

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


## Options
设置传感器上报频率。

**系统能力：**SystemCapability.Sensors.Sensor

| 名称 | 类型 | 只读 | 必填 | 说明 |
| --------| --------| --------| --------| --------|
| interval | number\|[SensorFrequency](#sensorfrequency) | 是 | 是 | 表示传感器的上报频率，默认值为200000000ns。该属性有最小值和最大值的限制，由硬件支持的上报频率决定。 |

## SensorFrequency
**系统能力：** SystemCapability.Sensors.Sensor

| 名称 | 类型 | 可读 | 可写 | 说明 |
| --------| --------| --------| --------| --------|
| game | string | 是 | 否 | 用于指定传感器上报频率，频率值为20000000ns，该频率被设置在硬件支持的频率范围内时会生效。 |
| ui | string | 是 | 否 | 用于指定传感器上报频率，频率值为60000000ns，该频率被设置在硬件支持的频率范围内时会生效。 |
| normal | string | 是 | 否 | 用于指定传感器上报频率，频率值为200000000ns，该频率被设置在硬件支持的频率范围内时会生效。 |

## SensorAccuracy
传感器数据的精度。

**系统能力：** SystemCapability.Sensors.Sensor

| 名称 | 值 | 说明 |
| --------| --------| --------|
| ACCURACY_UNRELIABLE | 0 | 传感器数据不可信。 |
| ACCURACY_LOW | 1 | 传感器低挡位精度。 |
| ACCURACY_MEDIUM | 2 | 传感器中挡位精度。 |
| ACCURACY_HIGH | 3 | 传感器高挡位精度。 |

## Response
传感器数据的时间戳。

**系统能力：** SystemCapability.Sensors.Sensor

| 名称 | 类型 | 只读 | 必填 | 说明 |
| --------| --------| --------| --------| --------|
| timestamp | number | 是 | 是 | 传感器数据上报的时间戳。 |
| accuracy | SensorAccuracy | 是 | 否 | 传感器数据上报的精度挡位值。 |

## AccelerometerResponse
加速度传感器数据，继承于[Response](#response)。

**系统能力：** SystemCapability.Sensors.Sensor

| 名称 | 类型 | 只读 | 必填 | 说明 |
| --------| --------| --------| --------| --------|
| x | number | 是 | 是 | 施加在设备x轴的加速度，单位 : m/s²。 |
| y | number | 是 | 是 | 施加在设备y轴的加速度，单位 : m/s²。 |
| z | number | 是 | 是 | 施加在设备z轴的加速度，单位 : m/s²。 |

## OrientationResponse
方向传感器数据，继承于[Response](#response)。

**系统能力：** SystemCapability.Sensors.Sensor

| 名称 | 类型 | 只读 | 必填 | 说明 |
| --------| --------| --------| --------| --------|
| alpha | number | 是 | 是 | 设备围绕Z轴的旋转角度，单位：度。 |
| beta | number | 是 | 是 | 设备围绕X轴的旋转角度，单位：度。 |
| gamma | number | 是 | 是 | 设备围绕Y轴的旋转角度，单位：度。 |

## GyroscopeResponse
陀螺仪传感器数据，继承于[Response](#response)。

**系统能力：** SystemCapability.Sensors.Sensor

| 名称 | 类型 | 只读 | 必填 | 说明 |
| --------| --------| --------| --------| --------|
| x | number | 是 | 是 | 设备x轴的旋转角速度，单位rad/s。 |
| y | number | 是 | 是 | 设备y轴的旋转角速度，单位rad/s。 |
| z | number | 是 | 是 | 设备z轴的旋转角速度，单位rad/s。 |
