# @system.sensor    
sensor模块提供订阅传感器数据基本能力，主要包含查询传感器的列表、订阅/取消传感器的数据、执行控制命令等。根据传感器的用途，可以将传感器分为六大类：运动类传感器、环境类传感器、方向类传感器、光线类传感器、健康类传感器、其他类传感器（如霍尔传感器），每一大类传感器包含不同类型的传感器，某种类型的传感器可能是单一的物理传感器，也可能是由多个物理传感器复合而成。  
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import sensor from '@system.sensor';  
    
```  
    
## AccelerometerResponse<sup>(deprecated)</sup>    
感应到加速度数据变化后的回调函数。。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#AccelerometerResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **需要权限：** ohos.permission.ACCELEROMETER    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>x轴的加速度。 |  
| y<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>y轴的加速度。 |  
| z<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>z轴的加速度。 |  
    
## subscribeAccelerometerOptions<sup>(deprecated)</sup>    
用于监听加速度传感器数据的回调函数的执行频率。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#ACCELEROMETER替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **需要权限：** ohos.permission.ACCELEROMETER    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| interval<sup>(deprecated)</sup> | string | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>频率参数，加速度的回调函数执行频率。 默认为normal，可选值有： - game：极高的回调频率，20ms/次，适用于游戏。 - ui：较高的回调频率，60ms/次，适用于UI更新。 - normal：普通的回调频率，200ms/次，低功耗。 |  
| success<sup>(deprecated)</sup> | (data: AccelerometerResponse) => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>感应到加速度数据变化后的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## CompassResponse<sup>(deprecated)</sup>    
罗盘数据改变后触发的回调函数。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#MagneticFieldResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| direction<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>设备面对的方向度数。 |  
    
## SubscribeCompassOptions<sup>(deprecated)</sup>    
当罗盘传感器数据发生变化时调用。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#MAGNETIC_FIELD替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: CompassResponse) => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>罗盘数据改变后触发的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## ProximityResponse<sup>(deprecated)</sup>    
距离感应数据改变后调用的回调函数。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#ProximityResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| distance<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>可见物体相对于设备显示屏的接近或远离状态。 |  
    
## SubscribeProximityOptions<sup>(deprecated)</sup>    
当距离传感器数据发生变化时调用。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#PROXIMITY替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: ProximityResponse) => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>距离感应数据改变后调用的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## LightResponse<sup>(deprecated)</sup>    
光线感应数据改变后的回调函数。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#LightResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| intensity<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>光线强度，单位为lux。 |  
    
## SubscribeLightOptions<sup>(deprecated)</sup>    
当环境光传感器数据发生变化时调用。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#AMBIENT_LIGHT替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: LightResponse) => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>光线感应数据改变后的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## StepCounterResponse<sup>(deprecated)</sup>    
计步传感器数据改变后的回调函数。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#PedometerResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| steps<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>计步传感器重启后累计记录的步数。 |  
    
## SubscribeStepCounterOptions<sup>(deprecated)</sup>    
当步进计数器传感器数据发生变化时调用。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/SensorId#PEDOMETER替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **需要权限：** ohos.permission.ACTIVITY_MOTION    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: StepCounterResponse) => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>计步传感器数据改变后的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## BarometerResponse<sup>(deprecated)</sup>    
气压计传感器数据改变后的回调函数。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#BarometerResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pressure<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>气压值，单位：帕斯卡。 |  
    
## SubscribeBarometerOptions<sup>(deprecated)</sup>    
当气压计传感器数据发生变化时调用。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#BAROMETER替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: BarometerResponse) => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>气压计传感器数据改变后的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## HeartRateResponse<sup>(deprecated)</sup>    
心率传感器数据改变后的回调函数，默认频率5s/次。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#HeartRateResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **需要权限：** ohos.permission.READ_HEALTH_DATA    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| heartRate<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>心率值。 |  
    
## SubscribeHeartRateOptions<sup>(deprecated)</sup>    
当心率传感器数据发生变化时调用。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#HEART_RATE替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **需要权限：** ohos.permission.READ_HEALTH_DATA    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: HeartRateResponse) => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>心率传感器数据改变后的回调函数，默认频率5s/次。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## OnBodyStateResponse<sup>(deprecated)</sup>    
传感器是否磨损。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#WearDetectionResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value<sup>(deprecated)</sup> | boolean | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>是否已佩戴。 |  
    
## SubscribeOnBodyStateOptions<sup>(deprecated)</sup>    
当穿着状态改变时调用。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#WEAR_DETECTION替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: OnBodyStateResponse) => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>穿戴状态改变后的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## GetOnBodyStateOptions<sup>(deprecated)</sup>    
获取传感器磨损状态时调用。    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#WEAR_DETECTION替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: OnBodyStateResponse) => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用成功的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用结束的回调函数。 |  
    
## DeviceOrientationResponse<sup>(deprecated)</sup>    
感应到设备方向传感器数据变化后的回调函数。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#OrientationResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| alpha<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>当设备坐标X/Y和地球X/Y重合时，绕着Z轴转动的夹角为alpha。 |  
| beta<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>当设备坐标Y/Z和地球Y/Z重合时，绕着X轴转动的夹角为beta。 |  
| gamma<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>当设备X/Z和地球X/Z重合时，绕着Y轴转动的夹角为gamma。 |  
    
## SubscribeDeviceOrientationOptions<sup>(deprecated)</sup>    
用于监听设备方向传感器数据的回调函数的执行频率。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#ORIENTATION替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| interval<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>频率参数，设备方向传感器的回调函数执行频率。<br/>默认为normal，可选值有：<br/>-game：极高的回调频率，20ms/次，适用于游戏。<br/>-ui：较高的回调频率，60ms/次，适用于UI更新。<br/>-normal：普通的回调频率，200ms/次，低功耗。 |  
| success<sup>(deprecated)</sup> | (data: DeviceOrientationResponse) => void | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>感应到设备方向传感器数据变化后的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 6 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## GyroscopeResponse<sup>(deprecated)</sup>    
感应到陀螺仪传感器数据变化后的回调函数。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor#GyroscopeResponse替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **需要权限：** ohos.permission.GYROSCOPE    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>x轴的旋转角速度。 |  
| y<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>y轴的旋转角速度。 |  
| z<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>z轴的旋转角速度。 |  
    
## SubscribeGyroscopeOptions<sup>(deprecated)</sup>    
用于侦听陀螺仪传感器数据的回调函数的执行频率。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor.SensorId#GYROSCOPE替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### 属性    
 **需要权限：** ohos.permission.GYROSCOPE    
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| interval<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>频率参数，陀螺仪的回调函数执行频率。<br/>默认为normal，可选值有：<br/>-game：极高的回调频率，20ms/次，适用于游戏。<br/>-ui：较高的回调频率，60ms/次，适用于UI更新。<br/>-normal：普通的回调频率，200ms/次，低功耗。 |  
| success<sup>(deprecated)</sup> | (data: GyroscopeResponse) => void | false | true | 从API version 6 开始支持，从API version 8 开始废弃。<br>感应到陀螺仪数据变化后的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 6 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
    
## Sensor<sup>(deprecated)</sup>    
sensor模块提供订阅传感器数据基本能力，主要包含查询传感器的列表、订阅/取消传感器的数据、执行控制命令等。根据传感器的用途，可以将传感器分为六大类：运动类传感器、环境类传感器、方向类传感器、光线类传感器、健康类传感器、其他类传感器（如霍尔传感器），每一大类传感器包含不同类型的传感器，某种类型的传感器可能是单一的物理传感器，也可能是由多个物理传感器复合而成。    
从API version 6 开始支持，从API version 8 开始废弃。建议使用ohos.sensor/sensor替代。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
### subscribeDeviceOrientation<sup>(deprecated)</sup>    
观察设备方向传感器数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效；针对同一个方法内，不支持多次调用。  
 **调用形式：**     
- static subscribeDeviceOrientation(options: SubscribeDeviceOrientationOptions): void  
  
 **废弃说明：** 从API version 8 开始废弃。替代接口: ohos.sensor/sensor.SensorId#ORIENTATION。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | SubscribeDeviceOrientationOptions | true | 用于监听设备方向传感器数据的回调函数的执行频率。 |  
    
 **示例代码：**   
```js    
import sensor from '@system.sensor';  
import { DeviceOrientationResponse, SubscribeDeviceOrientationOptions } from '@system.sensor';  
  
let subscribeDeviceOrientationOptions: SubscribeDeviceOrientationOptions = {  
  interval: 'normal',  
  success: (ret: DeviceOrientationResponse) => {  
    console.info('Succeeded in subscribing. Alpha data: ' + ret.alpha);  
    console.info('Succeeded in subscribing. Beta data: ' + ret.beta);  
    console.info('Succeeded in subscribing. Gamma data: ' + ret.gamma);  
  },  
  fail: (data: string, code: number) => {  
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);  
  }  
};  
sensor.subscribeDeviceOrientation(subscribeDeviceOrientationOptions);  
    
```    
  
    
### unsubscribeDeviceOrientation<sup>(deprecated)</sup>  
 **调用形式：**     
- static unsubscribeDeviceOrientation(): void  
  
 **废弃说明：** 从API version 8 开始废弃。替代接口: ohos.sensor/sensor.SensorId#ORIENTATION。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite    
 **示例代码：**   
```js    
sensor.unsubscribeDeviceOrientation();    
```    
  
    
### subscribeGyroscope<sup>(deprecated)</sup>    
观察陀螺仪传感器数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效；针对同一个方法内，不支持多次调用。  
 **调用形式：**     
- static subscribeGyroscope(options: SubscribeGyroscopeOptions): void  
  
 **废弃说明：** 从API version 8 开始废弃。替代接口: ohos.sensor/sensor.SensorId#GYROSCOPE。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite  
 **需要权限：** ohos.permission.GYROSCOPE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | SubscribeGyroscopeOptions | true | 用于侦听陀螺仪传感器数据的回调函数的执行频率。 |  
    
 **示例代码：**   
```js    
import sensor from '@system.sensor';  
import { GyroscopeResponse, SubscribeGyroscopeOptions } from '@system.sensor';  
  
let subscribeGyroscopeOptions: SubscribeGyroscopeOptions = {  
  interval: 'normal',  
  success: (ret: GyroscopeResponse) => {  
    console.info('Succeeded in subscribing. X-axis data: ' + ret.x);  
    console.info('Succeeded in subscribing. Y-axis data: ' + ret.y);  
    console.info('Succeeded in subscribing. Z-axis data: ' + ret.z);  
  },  
  fail: (data: string, code: number) => {  
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);  
  }  
};  
sensor.subscribeGyroscope(subscribeGyroscopeOptions);  
    
```    
  
    
### unsubscribeGyroscope<sup>(deprecated)</sup>  
 **调用形式：**     
- static unsubscribeGyroscope(): void  
  
 **废弃说明：** 从API version 8 开始废弃。替代接口: ohos.sensor/sensor.SensorId#GYROSCOPE。  
 **系统能力:**  SystemCapability.Sensors.Sensor.Lite  
 **需要权限：** ohos.permission.GYROSCOPE    
 **示例代码：**   
```ts    
sensor.unsubscribeGyroscope();    
```    
  
