# @system.sensor (传感器)

sensor模块提供订阅传感器数据基本能力，主要包含查询传感器的列表、订阅/取消传感器的数据、执行控制命令等。

根据传感器的用途，可以将传感器分为六大类：运动类传感器、环境类传感器、方向类传感器、光线类传感器、健康类传感器、其他类传感器（如霍尔传感器），每一大类传感器包含不同类型的传感器，某种类型的传感器可能是单一的物理传感器，也可能是由多个物理传感器复合而成。


> **说明：**
>
> - 从API Version 8开始，该接口不再维护，推荐使用新接口[`@ohos.sensor`](js-apis-sensor.md)。
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 该功能使用需要对应硬件支持，仅支持真机调试。


## 导入模块


```
import sensor from '@system.sensor';
```

## sensor.subscribeAccelerometer

 subscribeAccelerometer(options: subscribeAccelerometerOptions): void

观察加速度数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**需要权限**：ohos.permission.ACCELEROMETER，该权限为系统权限

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                       |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| options | [subscribeAccelerometerOptions](#subscribeaccelerometeroptions) | 是   | 监听加速度传感器数据的回调函数的执行频率。 |

**示例：**

```ts
import sensor from '@system.sensor';
import { AccelerometerResponse, subscribeAccelerometerOptions } from '@system.sensor';

let accelerometerOptions: subscribeAccelerometerOptions = {
  interval: 'normal',
  success: (ret: AccelerometerResponse) => {
    console.info('Succeeded in subscribing. X-axis data: ' + ret.x);
    console.info('Succeeded in subscribing. Y-axis data: ' + ret.y);
    console.info('Succeeded in subscribing. Z-axis data: ' + ret.z);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
sensor.subscribeAccelerometer(accelerometerOptions);
```

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeAccelerometer

unsubscribeAccelerometer(): void

取消订阅加速度数据。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**需要权限**：ohos.permission.ACCELEROMETER，该权限为系统权限

**示例：**

```ts
sensor.unsubscribeAccelerometer();
```

## sensor.subscribeCompass

 subscribeCompass(options: SubscribeCompassOptions): void

订阅罗盘数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**参数：**

| 参数名  | 类型                                                | 必填 | 说明                             |
| ------- | --------------------------------------------------- | ---- | -------------------------------- |
| options | [SubscribeCompassOptions](#subscribecompassoptions) | 是   | 当罗盘传感器数据发生变化时调用。 |

**示例：**

```ts
import sensor from '@system.sensor';
import { CompassResponse, SubscribeCompassOptions } from '@system.sensor';

let subscribeCompassOptions: SubscribeCompassOptions = {
  success: (ret: CompassResponse) => {
    console.info('Succeeded in subscribing. Get data direction:' + ret.direction);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
sensor.subscribeCompass(subscribeCompassOptions);
```

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeCompass

unsubscribeCompass(): void

取消订阅罗盘。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**示例：**

```ts
sensor.unsubscribeCompass();
```

## sensor.subscribeProximity

 subscribeProximity(options: SubscribeProximityOptions): void

订阅距离感应数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                             |
| ------- | ------------------------------------------------------- | ---- | -------------------------------- |
| options | [SubscribeProximityOptions](#subscribeproximityoptions) | 是   | 当距离传感器数据发生变化时调用。 |

**示例：**

```ts
import sensor from '@system.sensor';
import { ProximityResponse, SubscribeProximityOptions } from '@system.sensor';

let subscribeProximityOptions: SubscribeProximityOptions = {
  success: (ret: ProximityResponse) => {
    console.info('Succeeded in subscribing. Get data distance:' + ret.distance);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
sensor.subscribeProximity(subscribeProximityOptions);
```

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeProximity

unsubscribeProximity(): void

取消订阅距离感应。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**示例：**

```ts
sensor.unsubscribeProximity();
```

## sensor.subscribeLight

 subscribeLight(options: SubscribeLightOptions): void

订阅环境光线感应数据变化。再次调用时，会覆盖前一次调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**参数：**

| 参数名  | 类型                                            | 必填 | 说明                               |
| ------- | ----------------------------------------------- | ---- | ---------------------------------- |
| options | [SubscribeLightOptions](#subscribelightoptions) | 是   | 当环境光传感器数据发生变化时调用。 |

**示例：**

```ts
import sensor from '@system.sensor';
import { LightResponse, SubscribeLightOptions } from '@system.sensor';

let subscribeLightOptions: SubscribeLightOptions = {
  success: (ret: LightResponse) => {
    console.info('Succeeded in subscribing. Get data intensity:' + ret.intensity);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
sensor.subscribeLight(subscribeLightOptions);
```

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeLight

unsubscribeLight(): void

取消订阅环境光线感应。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**示例：**

```ts
sensor.unsubscribeLight();
```

## sensor.subscribeStepCounter

 subscribeStepCounter(options: SubscribeStepCounterOptions): void

订阅计步传感器数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**需要权限**：ohos.permission.ACTIVITY_MOTION

**参数：**

| 参数名  | 类型                                                        | 必填 | 说明                                   |
| ------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| options | [SubscribeStepCounterOptions](#subscribestepcounteroptions) | 是   | 当步进计数器传感器数据发生变化时调用。 |

**示例：**

```ts
import sensor from '@system.sensor';
import { StepCounterResponse, SubscribeStepCounterOptions } from '@system.sensor';

let subscribeStepCounterOptions: SubscribeStepCounterOptions = {
  success: (ret: StepCounterResponse) => {
    console.info('Succeeded in subscribing. Get step value:' + ret.steps);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
sensor.subscribeStepCounter(subscribeStepCounterOptions);
```

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeStepCounter

unsubscribeStepCounter(): void

取消订阅计步传感器。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**需要权限**：ohos.permission.ACTIVITY_MOTION

**示例：**

```ts
sensor.unsubscribeStepCounter();
```


## sensor.subscribeBarometer

subscribeBarometer(options: SubscribeBarometerOptions): void

订阅气压计传感器数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                               |
| ------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| options | [SubscribeBarometerOptions](#subscribebarometeroptions) | 是   | 当气压计传感器数据发生变化时调用。 |

**示例：**

```ts
import sensor from '@system.sensor';
import { BarometerResponse, SubscribeBarometerOptions } from '@system.sensor';

let subscribeBarometerOptions: SubscribeBarometerOptions = {
  success: (ret: BarometerResponse) => {
    console.info('Succeeded in subscribing. Get data value:' + ret.pressure);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
sensor.subscribeBarometer(subscribeBarometerOptions);
```

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。


## sensor.unsubscribeBarometer

unsubscribeBarometer(): void

取消订阅气压计传感器。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**示例：**

```ts
sensor.unsubscribeBarometer();
```


## sensor.subscribeHeartRate

 subscribeHeartRate(options: SubscribeHeartRateOptions): void

订阅心率传感器数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**需要权限**：ohos.permission.READ_HEALTH_DATA

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                             |
| ------- | ------------------------------------------------------- | ---- | -------------------------------- |
| options | [SubscribeHeartRateOptions](#subscribeheartrateoptions) | 是   | 当心率传感器数据发生变化时调用。 |

**示例：**

```ts
import sensor from '@system.sensor';
import { HeartRateResponse, SubscribeHeartRateOptions } from '@system.sensor';

let subscribeHeartRateOptions: SubscribeHeartRateOptions = {
  success: (ret: HeartRateResponse) => {
    console.info('Succeeded in subscribing. Get heartrate value:' + ret.heartRate);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
sensor.subscribeHeartRate(subscribeHeartRateOptions);
```

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。


## sensor.unsubscribeHeartRate

unsubscribeHeartRate(): void

取消订阅心率传感器。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**需要权限**：ohos.permission.READ_HEALTH_DATA

**示例：**

```ts
sensor.unsubscribeHeartRate();
```

## sensor.subscribeOnBodyState

 subscribeOnBodyState(options: SubscribeOnBodyStateOptions): void

订阅设备佩戴状态。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**参数：**

| 参数名  | 类型                                                        | 必填 | 说明                   |
| ------- | ----------------------------------------------------------- | ---- | ---------------------- |
| options | [SubscribeOnBodyStateOptions](#subscribeonbodystateoptions) | 是   | 当穿着状态改变时调用。 |

**示例：**

```ts
import sensor from '@system.sensor';
import { OnBodyStateResponse, SubscribeOnBodyStateOptions } from '@system.sensor';

let subscribeOnBodyStateOptions: SubscribeOnBodyStateOptions = {
  success: (ret: OnBodyStateResponse) => {
    console.info('Succeeded in subscribing. Get on-body state value:' + ret.value);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
sensor.subscribeOnBodyState(subscribeOnBodyStateOptions);
```

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeOnBodyState

unsubscribeOnBodyState(): void

取消订阅设备佩戴状态。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**示例：**

```ts
sensor.unsubscribeOnBodyState();
```

## sensor.getOnBodyState

 getOnBodyState(options: GetOnBodyStateOptions): void

获取设备佩戴状态。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**参数：**

| 参数名  | 类型                                            | 必填 | 说明                       |
| ------- | ----------------------------------------------- | ---- | -------------------------- |
| options | [GetOnBodyStateOptions](#getonbodystateoptions) | 是   | 获取传感器磨损状态时调用。 |

**示例：**

```ts
import sensor from '@system.sensor';
import { OnBodyStateResponse, GetOnBodyStateOptions } from '@system.sensor';

let getOnBodyStateOptions: GetOnBodyStateOptions = {
  success: (ret: OnBodyStateResponse) => {
    console.info('Succeeded in subscribing. On body state: ' + ret.value);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
sensor.getOnBodyState(getOnBodyStateOptions);
```

## sensor.subscribeDeviceOrientation<sup>6+</sup>

 subscribeDeviceOrientation(options: SubscribeDeviceOrientationOptions): void

观察设备方向传感器数据变化。

针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效；针对同一个方法内，不支持多次调用。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                             |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| options | [SubscribeDeviceOrientationOptions](#subscribedeviceorientationoptions6) | 是   | 用于监听设备方向传感器数据的回调函数的执行频率。 |

**示例：**

```ts
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

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeDeviceOrientation<sup>6+</sup>

unsubscribeDeviceOrientation(): void

取消订阅设备方向传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**示例：**

```ts
sensor.unsubscribeDeviceOrientation();
```

## sensor.subscribeGyroscope<sup>6+</sup>

 subscribeGyroscope(options: SubscribeGyroscopeOptions): void

观察陀螺仪传感器数据变化。

针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效；针对同一个方法内，不支持多次调用。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**需要权限**：ohos.permission.GYROSCOPE，该权限为系统权限

**参数：**

| 参数名  | 类型                                                     | 必填 | 说明                                           |
| ------- | -------------------------------------------------------- | ---- | ---------------------------------------------- |
| options | [SubscribeGyroscopeOptions](#subscribegyroscopeoptions6) | 是   | 用于侦听陀螺仪传感器数据的回调函数的执行频率。 |

**示例：**

```ts
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

> **说明：**
> 建议在页面销毁时，即onDestroy回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeGyroscope<sup>6+</sup>

unsubscribeGyroscope(): void

取消订阅陀螺仪传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

**需要权限**：ohos.permission.GYROSCOPE，该权限为系统权限

**示例：**

```ts
sensor.unsubscribeGyroscope();
```

## subscribeAccelerometerOptions

用于监听加速度传感器数据的回调函数的执行频率。

**需要权限**：ohos.permission.ACCELEROMETER

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称     | 类型                                            | 必填 | 说明                                                         |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| interval | string                                          | 是   | 频率参数，加速度的回调函数执行频率。<br/>默认为normal，可选值有：<br/>game：极高的回调频率，20ms/次，适用于游戏。<br/>ui：较高的回调频率，60ms/次，适用于UI更新。<br/>normal：普通的回调频率，200ms/次，低功耗。 |
| success  | [AccelerometerResponse](#accelerometerresponse) | 是   | 感应到加速度数据变化后的回调函数。                           |
| fail     | Function                                        | 否   | 接口调用失败的回调函数。                                     |

## AccelerometerResponse 

感应到加速度数据变化后的回调函数。  

**需要权限**：ohos.permission.ACCELEROMETER

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称 | 类型   | 必填 | 说明          |
| ---- | ------ | ---- | ------------- |
| x    | number | 是   | x轴的加速度。 |
| y    | number | 是   | y轴的加速度。 |
| z    | number | 是   | z轴的加速度。 |

## SubscribeCompassOptions

当罗盘传感器数据发生变化时调用。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称    | 类型                                | 必填 | 说明                           |
| ------- | ----------------------------------- | ---- | ------------------------------ |
| success | [CompassResponse](#compassresponse) | 是   | 罗盘数据改变后触发的回调函数。 |
| fail    | Function                            | 否   | 接口调用失败的回调函数。       |

## CompassResponse 

罗盘数据改变后触发的回调函数。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称      | 类型   | 必填 | 说明                 |
| --------- | ------ | ---- | -------------------- |
| direction | number | 是   | 设备面对的方向度数。 |

## SubscribeProximityOptions

当距离传感器数据发生变化时调用。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称    | 类型                                    | 必填 | 说明                               |
| ------- | --------------------------------------- | ---- | ---------------------------------- |
| success | [ProximityResponse](#proximityresponse) | 是   | 距离感应数据改变后调用的回调函数。 |
| fail    | Function                                | 否   | 接口调用失败的回调函数。           |

## ProximityResponse 

距离感应数据改变后调用的回调函数。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称     | 类型   | 必填 | 说明                                       |
| -------- | ------ | ---- | ------------------------------------------ |
| distance | number | 是   | 可见物体相对于设备显示屏的接近或远离状态。 |

## SubscribeLightOptions

当环境光传感器数据发生变化时调用。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称    | 类型                            | 必填 | 说明                           |
| ------- | ------------------------------- | ---- | ------------------------------ |
| success | [LightResponse](#lightresponse) | 是   | 光线感应数据改变后的回调函数。 |
| fail    | Function                        | 否   | 接口调用失败的回调函数。       |

## LightResponse 

光线感应数据改变后的回调函数。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称      | 类型   | 必填 | 说明                  |
| --------- | ------ | ---- | --------------------- |
| intensity | number | 是   | 光线强度，单位为lux。 |

## SubscribeStepCounterOptions

当步进计数器传感器数据发生变化时调用。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称    | 类型                                        | 必填 | 说明                             |
| ------- | ------------------------------------------- | ---- | -------------------------------- |
| success | [StepCounterResponse](#stepcounterresponse) | 是   | 计步传感器数据改变后的回调函数。 |
| fail    | Function                                    | 否   | 接口调用失败的回调函数。         |

## StepCounterResponse 

计步传感器数据改变后的回调函数。

**需要权限**：ohos.permission.ACTIVITY_MOTION

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称  | 类型   | 必填 | 说明                             |
| ----- | ------ | ---- | -------------------------------- |
| steps | number | 是   | 计步传感器重启后累计记录的步数。 |

## SubscribeBarometerOptions

当气压计传感器数据发生变化时调用。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称    | 类型                                    | 必填 | 说明                             |
| ------- | --------------------------------------- | ---- | -------------------------------- |
| success | [BarometerResponse](#barometerresponse) | 是   | 气压计传感器数据改变后的回调函数。 |
| fail    | Function                                | 否   | 接口调用失败的回调函数。         |

## BarometerResponse 

气压计传感器数据改变后的回调函数。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称     | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| pressure | number | 是   | 气压值，单位：帕斯卡。 |

## SubscribeHeartRateOptions

当心率传感器数据发生变化时调用。

**需要权限**：ohos.permission.READ_HEALTH_DATA 

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称    | 类型                                    | 必填 | 说明                                            |
| ------- | --------------------------------------- | ---- | ----------------------------------------------- |
| success | [HeartRateResponse](#heartrateresponse) | 是   | 心率传感器数据改变后的回调函数，默认频率5s/次。 |
| fail    | Function                                | 否   | 接口调用失败的回调函数。                        |

## HeartRateResponse 

心率传感器数据改变后的回调函数，默认频率5s/次。

**需要权限**：ohos.permission.READ_HEALTH_DATA 

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称      | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | -------- |
| heartRate | number | 是   | 心率值。 |

## SubscribeOnBodyStateOptions

当穿着状态改变时调用。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称    | 类型                                        | 必填 | 说明                       |
| ------- | ------------------------------------------- | ---- | -------------------------- |
| success | [OnBodyStateResponse](#onbodystateresponse) | 是   | 穿戴状态改变后的回调函数。 |
| fail    | Function                                    | 否   | 接口调用失败的回调函数。   |

## OnBodyStateResponse 

传感器是否磨损。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称  | 类型    | 必填 | 说明         |
| ----- | ------- | ---- | ------------ |
| value | boolean | 是   | 是否已佩戴。 |

## GetOnBodyStateOptions

 获取传感器磨损状态时调用。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称     | 类型                                        | 必填 | 说明                     |
| -------- | ------------------------------------------- | ---- | ------------------------ |
| success  | [OnBodyStateResponse](#onbodystateresponse) | 是   | 接口调用成功的回调函数。 |
| fail     | Function                                    | 否   | 接口调用失败的回调函数。 |
| complete | Function                                    | 否   | 接口调用结束的回调函数。 |

## SubscribeDeviceOrientationOptions<sup>6+</sup>

用于监听设备方向传感器数据的回调函数的执行频率。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称     | 类型                                                     | 必填 | 说明                                                         |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| interval | string                                                   | 是   | 频率参数，设备方向传感器的回调函数执行频率。<br/>默认为normal，可选值有：<br/>-&nbsp;game：极高的回调频率，20ms/次，适用于游戏。<br/>-&nbsp;ui：较高的回调频率，60ms/次，适用于UI更新。<br/>-&nbsp;normal：普通的回调频率，200ms/次，低功耗。 |
| success  | [DeviceOrientationResponse](#deviceorientationresponse6) | 是   | 感应到设备方向传感器数据变化后的回调函数。                   |
| fail     | Function                                                 | 否   | 接口调用失败的回调函数。                                     |

## DeviceOrientationResponse<sup>6+</sup> 

感应到设备方向传感器数据变化后的回调函数。

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称  | 类型   | 必填 | 说明                                                         |
| ----- | ------ | ---- | ------------------------------------------------------------ |
| alpha | number | 是   | 当设备坐标&nbsp;X/Y&nbsp;和地球&nbsp;X/Y&nbsp;重合时，绕着&nbsp;Z&nbsp;轴转动的夹角为&nbsp;alpha。 |
| beta  | number | 是   | 当设备坐标&nbsp;Y/Z&nbsp;和地球&nbsp;Y/Z&nbsp;重合时，绕着&nbsp;X&nbsp;轴转动的夹角为&nbsp;beta。 |
| gamma | number | 是   | 当设备&nbsp;X/Z&nbsp;和地球&nbsp;X/Z&nbsp;重合时，绕着&nbsp;Y&nbsp;轴转动的夹角为&nbsp;gamma。 |

## SubscribeGyroscopeOptions<sup>6+</sup> 

用于侦听陀螺仪传感器数据的回调函数的执行频率。

**需要权限**：ohos.permission.GYROSCOPE

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称     | 类型                                     | 必填 | 说明                                                         |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| interval | string                                   | 是   | 频率参数，陀螺仪的回调函数执行频率。<br/>默认为normal，可选值有：<br/>game：极高的回调频率，20ms/次，适用于游戏。<br/>ui：较高的回调频率，60ms/次，适用于UI更新。<br/>normal：普通的回调频率，200ms/次，低功耗。 |
| success  | [GyroscopeResponse](#gyroscoperesponse6) | 是   | 感应到陀螺仪数据变化后的回调函数。                           |
| fail     | Function                                 | 否   | 接口调用失败的回调函数。                                     |

## GyroscopeResponse<sup>6+</sup> 

感应到陀螺仪传感器数据变化后的回调函数。

**需要权限**：ohos.permission.GYROSCOPE

**系统能力**：SystemCapability.Sensors.Sensor.Lite

| 名称 | 类型   | 必填 | 说明              |
| ---- | ------ | ---- | ----------------- |
| x    | number | 是   | x轴的旋转角速度。 |
| y    | number | 是   | y轴的旋转角速度。 |
| z    | number | 是   | z轴的旋转角速度。 |