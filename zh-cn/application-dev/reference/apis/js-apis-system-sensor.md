# @system.sensor (传感器)

## 模块说明

sensor模块提供订阅传感器数据基本能力，主要包含查询传感器的列表、订阅/取消传感器的数据、执行控制命令等。

根据传感器的用途，可以将传感器分为六大类：运动类传感器、环境类传感器、方向类传感器、光线类传感器、健康类传感器、其他类传感器（如霍尔传感器），每一大类传感器包含不同类型的传感器，某种类型的传感器可能是单一的物理传感器，也可能是由多个物理传感器复合而成。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> - 从API Version 8开始，该接口不再维护，推荐使用新接口[`@ohos.sensor`](js-apis-sensor.md)。
> - 本模块首批接口从API version 4开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 该功能使用需要对应硬件支持，仅支持真机调试。


## 导入模块


```
import sensor from '@system.sensor';
```

## 传感器错误码列表 

| 错误码  | 说明             |
| ---- | -------------- |
| 900  | 当前设备不支持相应的传感器。 |

## sensor.subscribeAccelerometer

subscribeAccelerometer(Object): void

观察加速度数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**需要权限**：ohos.permission.ACCELEROMETER，该权限为系统权限

**参数：**

| 参数名      | 类型       | 必填   | 说明                                       |
| -------- | -------- | ---- | ---------------------------------------- |
| interval | string   | 是    | 频率参数，加速度的回调函数执行频率。<br/>默认为normal，可选值有：<br/>-&nbsp;game：极高的回调频率，20ms/次，适用于游戏。<br/>-&nbsp;ui：较高的回调频率，60ms/次，适用于UI更新。<br/>-&nbsp;normal：普通的回调频率，200ms/次，低功耗。 |
| success  | Function | 是    | 感应到加速度数据变化后的回调函数。                        |
| fail     | Function | 否    | 接口调用失败的回调函数。                             |

success返回值：

| 参数名  | 类型     | 说明      |
| ---- | ------ | ------- |
| x    | number | x轴的加速度。 |
| y    | number | y轴的加速度。 |
| z    | number | z轴的加速度。 |

**示例：**

```
sensor.subscribeAccelerometer({
  interval: 'normal',
  success: function(ret) {
    console.log('X-axis data: ' + ret.x);
    console.log('Y-axis data: ' + ret.y);
    console.log('Z-axis data: ' + ret.z);
  },
  fail: function(data, code) {
    console.error('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeAccelerometer

unsubscribeAccelerometer(): void

取消订阅加速度数据。

**系统能力**：SystemCapability.Sensors.Sensor

**需要权限**：ohos.permission.ACCELEROMETER，该权限为系统权限

**示例：**

```
sensor.unsubscribeAccelerometer();
```

## sensor.subscribeCompass

subscribeCompass(Object): void

订阅罗盘数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：**

| 参数名     | 类型       | 必填   | 说明              |
| ------- | -------- | ---- | --------------- |
| success | Function | 是    | 罗盘数据改变后触发的回调函数。 |
| fail    | Function | 否    | 接口调用失败的回调函数。    |

success返回值：

| 参数名       | 类型     | 说明         |
| --------- | ------ | ---------- |
| direction | number | 设备面对的方向度数。 |

**示例：**

```
sensor.subscribeCompass({
  success: function(ret) {
    console.log('get data direction:' + ret.direction);
  },
  fail: function(data, code) {
    console.error('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeCompass

unsubscribeCompass(): void

取消订阅罗盘。

**系统能力**：SystemCapability.Sensors.Sensor

**示例：**

```
sensor.unsubscribeCompass();
```

## sensor.subscribeProximity

subscribeProximity(Object): void

订阅距离感应数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：**

| 参数名     | 类型       | 必填   | 说明                |
| ------- | -------- | ---- | ----------------- |
| success | Function | 是    | 距离感应数据改变后调用的回调函数。 |
| fail    | Function | 否    | 接口调用失败的回调函数。      |

success返回值：

| 参数名      | 类型     | 说明                    |
| -------- | ------ | --------------------- |
| distance | number | 可见物体相对于设备显示屏的接近或远离状态。 |

**示例：**

```
sensor.subscribeProximity({
  success: function(ret) {
    console.log('get data distance:' + ret.distance);
  },
  fail: function(data, code) {
    console.error('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeProximity

unsubscribeProximity(): void

取消订阅距离感应。

**系统能力**：SystemCapability.Sensors.Sensor

**示例：**

```
sensor.unsubscribeProximity();
```

## sensor.subscribeLight

sensor.subscribeLight(Object): void

订阅环境光线感应数据变化。再次调用时，会覆盖前一次调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：**

| 参数名     | 类型       | 必填   | 说明              |
| ------- | -------- | ---- | --------------- |
| success | Function | 是    | 光线感应数据改变后的回调函数。 |
| fail    | Function | 否    | 接口调用失败的回调函数。    |

success返回值：

| 参数名       | 类型     | 说明           |
| --------- | ------ | ------------ |
| intensity | number | 光线强度，单位为lux。 |

**示例：**

```
sensor.subscribeLight({
  success: function(ret) {
    console.log('get data intensity:' + ret.intensity);
  },
  fail: function(data, code) {
    console.error('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeLight

unsubscribeLight(): void

取消订阅环境光线感应。

**系统能力**：SystemCapability.Sensors.Sensor

**示例：**

```
sensor.unsubscribeLight();
```

## sensor.subscribeStepCounter

subscribeStepCounter(Object): void

订阅计步传感器数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**需要权限**：ohos.permission.ACTIVITY_MOTION

**参数：**

| 参数名     | 类型       | 必填   | 说明               |
| ------- | -------- | ---- | ---------------- |
| success | Function | 是    | 计步传感器数据改变后的回调函数。 |
| fail    | Function | 否    | 接口调用失败的回调函数。     |

success返回值：

| 参数名   | 类型     | 说明                    |
| ----- | ------ | --------------------- |
| steps | number | 计步传感器重启后累计记录的步数。<br/> |

**示例：**

```
sensor.subscribeStepCounter({
  success: function(ret) {
    console.log('get step value:' + ret.steps);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeStepCounter

unsubscribeStepCounter(): void

取消订阅计步传感器。

**系统能力**：SystemCapability.Sensors.Sensor

**需要权限**：ohos.permission.ACTIVITY_MOTION

**示例：**

```
sensor.unsubscribeStepCounter();
```


## sensor.subscribeBarometer

subscribeBarometer(Object): void

订阅气压传感器数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：**

| 参数名     | 类型       | 必填   | 说明               |
| ------- | -------- | ---- | ---------------- |
| success | Function | 是    | 气压传感器数据改变后的回调函数。 |
| fail    | Function | 否    | 接口调用失败的回调函数。     |

success返回值：

| 参数名      | 类型     | 说明          |
| -------- | ------ | ----------- |
| pressure | number | 气压值，单位：帕斯卡。 |

**示例：**

```
sensor.subscribeBarometer({
  success: function(ret) {
    console.log('get data value:' + ret.pressure);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。


## sensor.unsubscribeBarometer

unsubscribeBarometer(): void

取消订阅气压传感器。

**系统能力**：SystemCapability.Sensors.Sensor

**示例：**

```
sensor.unsubscribeBarometer();
```


## sensor.subscribeHeartRate

subscribeHeartRate(Object): void

订阅心率传感器数据变化。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**需要权限**：ohos.permission.READ_HEALTH_DATA

**参数：**

| 参数名     | 类型       | 必填   | 说明                        |
| ------- | -------- | ---- | ------------------------- |
| success | Function | 是    | 心率传感器数据改变后的回调函数，默认频率5s/次。 |
| fail    | Function | 否    | 接口调用失败的回调函数。              |

success返回值：

| 参数名       | 类型     | 说明   |
| --------- | ------ | ---- |
| heartRate | number | 心率值。 |

**示例：**

```
sensor.subscribeHeartRate({
  success: function(ret) {
    console.log('get heartrate value:' + ret.heartRate);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。


## sensor.unsubscribeHeartRate

unsubscribeHeartRate(): void

取消订阅心率。

**系统能力**：SystemCapability.Sensors.Sensor

**需要权限**：ohos.permission.READ_HEALTH_DATA

**示例：**

```
sensor.unsubscribeHeartRate();
```

## sensor.subscribeOnBodyState

subscribeOnBodyState(Object): void

订阅设备佩戴状态。针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：**

| 参数名     | 类型       | 必填   | 说明            |
| ------- | -------- | ---- | ------------- |
| success | Function | 是    | 穿戴状态改变后的回调函数。 |
| fail    | Function | 否    | 接口调用失败的回调函数。  |

success返回值：

| 参数名   | 类型      | 说明     |
| ----- | ------- | ------ |
| value | boolean | 是否已佩戴。 |

**示例：**

```
sensor.subscribeOnBodyState({
  success: function(ret) {
    console.log('get on-body state value:' + ret.value);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeOnBodyState

unsubscribeOnBodyState(): void

取消订阅设备佩戴状态。

**系统能力**：SystemCapability.Sensors.Sensor

**示例：**

```
sensor.unsubscribeOnBodyState();
```

## sensor.getOnBodyState

getOnBodyState(Object): void

获取设备佩戴状态。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：**

| 参数名      | 类型       | 必填   | 说明           |
| -------- | -------- | ---- | ------------ |
| success  | Function | 否    | 接口调用成功的回调函数。 |
| fail     | Function | 否    | 接口调用失败的回调函数。 |
| complete | Function | 否    | 接口调用结束的回调函数。 |

success返回值：

| 参数名   | 类型      | 说明     |
| ----- | ------- | ------ |
| value | boolean | 是否已佩戴。 |

**示例：**

```
sensor.getOnBodyState({
  success: function(ret) {
    console.log('on body state: ' + ret.value);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

## sensor.subscribeDeviceOrientation<sup>6+</sup>

subscribeDeviceOrientation(interval: string, success: (data: DeviceOrientationResponse), fail?: (data: string, code: number)): void

观察设备方向传感器数据变化。

针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效；针对同一个方法内，不支持多次调用。

**系统能力**：SystemCapability.Sensors.Sensor

**参数：**

| 参数名      | 类型       | 必填   | 说明                                       |
| -------- | -------- | ---- | ---------------------------------------- |
| interval | string   | 是    | 频率参数，设备方向传感器的回调函数执行频率。<br/>默认为normal，可选值有：<br/>-&nbsp;game：极高的回调频率，20ms/次，适用于游戏。<br/>-&nbsp;ui：较高的回调频率，60ms/次，适用于UI更新。<br/>-&nbsp;normal：普通的回调频率，200ms/次，低功耗。 |
| success  | Function | 是    | 感应到设备方向传感器数据变化后的回调函数。                    |
| fail     | Function | 否    | 接口调用失败的回调函数。                             |

 success返回值：
| 参数名   | 类型     | 说明                                       |
| ----- | ------ | ---------------------------------------- |
| alpha | number | 当设备坐标&nbsp;X/Y&nbsp;和地球&nbsp;X/Y&nbsp;重合时，绕着&nbsp;Z&nbsp;轴转动的夹角为&nbsp;alpha。 |
| beta  | number | 当设备坐标&nbsp;Y/Z&nbsp;和地球&nbsp;Y/Z&nbsp;重合时，绕着&nbsp;X&nbsp;轴转动的夹角为&nbsp;beta。 |
| gamma | number | 当设备&nbsp;X/Z&nbsp;和地球&nbsp;X/Z&nbsp;重合时，绕着&nbsp;Y&nbsp;轴转动的夹角为&nbsp;gamma。 |

**示例：**

```
sensor.subscribeDeviceOrientation({
  interval: 'normal',
  success: function(ret) {
    console.log('Alpha data: ' + ret.alpha);
    console.log('Beta data: ' + ret.beta);
    console.log('Gamma data: ' + ret.gamma);
  },
  fail: function(data, code) {
    console.error('Subscription failed. Code: ' + code + '; Data: ' + data);
  }
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeDeviceOrientation<sup>6+</sup>

unsubscribeDeviceOrientation(): void

取消订阅设备方向传感器数据。

**系统能力**：SystemCapability.Sensors.Sensor

**示例：**

```
sensor.unsubscribeDeviceOrientation();
```

## sensor.subscribeGyroscope<sup>6+</sup>

subscribeGyroscope(interval: string, success: (data: GyroscopeResponse), fail?: (data: string, code: number)): void

观察陀螺仪数据变化。

针对同一个应用，多次点击调用时，会覆盖前面的调用效果，即仅最后一次调用生效；针对同一个方法内，不支持多次调用。

**系统能力**：SystemCapability.Sensors.Sensor

**需要权限**：ohos.permission.GYROSCOPE，该权限为系统权限

**参数：**

| 参数名      | 类型       | 必填   | 说明                                       |
| -------- | -------- | ---- | ---------------------------------------- |
| interval | string   | 是    | 频率参数，陀螺仪的回调函数执行频率。<br/>默认为normal，可选值有：<br/>-&nbsp;game：极高的回调频率，20ms/次，适用于游戏。<br/>-&nbsp;ui：较高的回调频率，60ms/次，适用于UI更新。<br/>-&nbsp;normal：普通的回调频率，200ms/次，低功耗。 |
| success  | Function | 是    | 感应到陀螺仪数据变化后的回调函数。                        |
| fail     | Function | 否    | 接口调用失败的回调函数。                             |

success返回值：

| 参数名  | 类型     | 说明        |
| ---- | ------ | --------- |
| x    | number | x轴的旋转角速度。 |
| y    | number | y轴的旋转角速度。 |
| z    | number | z轴的旋转角速度。 |

**示例：**

```
sensor.subscribeGyroscope({
  interval: 'normal',
  success: function(ret) {
    console.log('X-axis data: ' + ret.x);
    console.log('Y-axis data: ' + ret.y);
    console.log('Z-axis data: ' + ret.z);
  },
  fail: function(data, code) {
    console.error('Subscription failed. Code: ' + code + '; data: ' + data);
  }
});
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 建议在页面销毁时，即onDestory回调中，取消数据订阅，避免不必要的性能开销。

## sensor.unsubscribeGyroscope<sup>6+</sup>

unsubscribeGyroscope(): void

取消订阅陀螺仪数据。

**系统能力**：SystemCapability.Sensors.Sensor

**需要权限**：ohos.permission.GYROSCOPE，该权限为系统权限

**示例：**

```
sensor.unsubscribeGyroscope();
```
