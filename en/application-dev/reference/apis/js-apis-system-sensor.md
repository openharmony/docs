# Sensor

The **Sensor** module provides APIs for querying the sensor list, subscribing to or unsubscribing from sensor data, and executing control commands.

The sensors are classified into the following categories based on their functions: motion, environment, orientation, light, body, and other categories (such as Hall effect sensors). Each category includes different sensor types. A sensor type may be a single hardware sensor or a composite of multiple hardware sensors.


> **NOTE**
>
> - The APIs of this module are no longer maintained since API version 8. You are advised to use [`@ohos.sensor`](js-apis-sensor.md) instead.
> - The initial APIs of this module are supported since API version 4. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This module requires hardware support and can only be debugged on real devices.


## Modules to Import


```
import sensor from '@system.sensor';
```

## Error Codes

| Error Code | Description                              |
| ---------- | ---------------------------------------- |
| 900        | The current device does not support the corresponding sensor. |

## sensor.subscribeAccelerometer

subscribeAccelerometer(Object): void

Subscribes to data changes of the acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**Parameters**

| Name     | Type     | Mandatory | Description                              |
| -------- | -------- | --------- | ---------------------------------------- |
| interval | string   | Yes       | Execution frequency of the callback for returning the acceleration sensor data.<br>The default value is **normal**. The options are as follows:<br>- **game**: called at an interval of 20 ms, which is applicable to gaming scenarios.<br>- **ui**: called at an interval of 60 ms, which is applicable to UI updating scenarios.<br>- **normal**: called at an interval of 200 ms, which is applicable to power-saving scenarios. |
| success  | Function | Yes       | Called when the acceleration sensor data changes. |
| fail     | Function | No        | Callback upon failure.                   |

Return values of the success callback

| Name | Type   | Description                 |
| ---- | ------ | --------------------------- |
| x    | number | Acceleration on the x-axis. |
| y    | number | Acceleration on the y-axis. |
| z    | number | Acceleration on the z-axis. |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeAccelerometer

unsubscribeAccelerometer(): void

Unsubscribes from data changes of the acceleration sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**Example**

```
sensor.unsubscribeAccelerometer();
```

## sensor.subscribeCompass

subscribeCompass(Object): void

Subscribes to data changes of the compass sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name    | Type     | Mandatory | Description                              |
| ------- | -------- | --------- | ---------------------------------------- |
| success | Function | Yes       | Called when the compass sensor data changes. |
| fail    | Function | No        | Callback upon failure.                   |

Return values of the success callback

| Name      | Type   | Description                          |
| --------- | ------ | ------------------------------------ |
| direction | number | Direction of the device, in degrees. |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeCompass

unsubscribeCompass(): void

Unsubscribes from data changes of the compass sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```
sensor.unsubscribeCompass();
```

## sensor.subscribeProximity

subscribeProximity(Object): void

Subscribes to data changes of the proximity sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name    | Type     | Mandatory | Description                              |
| ------- | -------- | --------- | ---------------------------------------- |
| success | Function | Yes       | Called when the proximity sensor data changes. |
| fail    | Function | No        | Callback upon failure.                   |

Return values of the success callback

| Name     | Type   | Description                              |
| -------- | ------ | ---------------------------------------- |
| distance | number | Distance between a visible object and the device screen. |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeProximity

unsubscribeProximity(): void

Unsubscribes from data changes of the proximity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```
sensor.unsubscribeProximity();
```

## sensor.subscribeLight

sensor.subscribeLight(Object): void

Subscribes to data changes of the ambient light sensor. If this API is called multiple times, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name    | Type     | Mandatory | Description                              |
| ------- | -------- | --------- | ---------------------------------------- |
| success | Function | Yes       | Called when the ambient light sensor data changes |
| fail    | Function | No        | Callback upon failure.                   |

Return values of the success callback

| Name      | Type   | Description              |
| --------- | ------ | ------------------------ |
| intensity | number | Light intensity, in lux. |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeLight

unsubscribeLight(): void

Unsubscribes from data changes of the ambient light sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```
sensor.unsubscribeLight();
```

## sensor.subscribeStepCounter

subscribeStepCounter(Object): void

Subscribes to data changes of the step counter sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**Parameters**

| Name    | Type     | Mandatory | Description                              |
| ------- | -------- | --------- | ---------------------------------------- |
| success | Function | Yes       | Called when the step counter sensor data changes. |
| fail    | Function | No        | Callback upon failure.                   |

Return values of the success callback

| Name  | Type   | Description                              |
| ----- | ------ | ---------------------------------------- |
| steps | number | Number of counted steps after the sensor is restarted.<br> |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeStepCounter

unsubscribeStepCounter(): void

Unsubscribes from data changes of the step counter sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**Example**

```
sensor.unsubscribeStepCounter();
```


## sensor.subscribeBarometer

subscribeBarometer(Object): void

Subscribes to data changes of the barometer sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name    | Type     | Mandatory | Description                              |
| ------- | -------- | --------- | ---------------------------------------- |
| success | Function | Yes       | Called when the barometer sensor data changes. |
| fail    | Function | No        | Callback upon failure.                   |

Return values of the success callback

| Name     | Type   | Description          |
| -------- | ------ | -------------------- |
| pressure | number | Pressure, in pascal. |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.


## sensor.unsubscribeBarometer

unsubscribeBarometer(): void

Unsubscribes from data changes of the barometer sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```
sensor.unsubscribeBarometer();
```


## sensor.subscribeHeartRate

subscribeHeartRate(Object): void

Subscribes to data changes of the heart rate sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**Parameters**

| Name    | Type     | Mandatory | Description                              |
| ------- | -------- | --------- | ---------------------------------------- |
| success | Function | Yes       | Called when the heart rate sensor data changes. This callback is invoked every five seconds. |
| fail    | Function | No        | Callback upon failure.                   |

Return values of the success callback

| Name      | Type   | Description |
| --------- | ------ | ----------- |
| heartRate | number | Heart rate. |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.


## sensor.unsubscribeHeartRate

unsubscribeHeartRate(): void

Unsubscribes from data changes of the heart rate sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**Example**

```
sensor.unsubscribeHeartRate();
```

## sensor.subscribeOnBodyState

subscribeOnBodyState(Object): void

Subscribes to changes of the wearing state of a wearable device. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name    | Type     | Mandatory | Description                            |
| ------- | -------- | --------- | -------------------------------------- |
| success | Function | Yes       | Called when the wearing state changes. |
| fail    | Function | No        | Callback upon failure.                 |

Return values of the success callback

| Name  | Type    | Description                          |
| ----- | ------- | ------------------------------------ |
| value | boolean | Whether the wearable device is worn. |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeOnBodyState

unsubscribeOnBodyState(): void

Unsubscribes from changes of the wearing state of a wearable device.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```
sensor.unsubscribeOnBodyState();
```

## sensor.getOnBodyState

getOnBodyState(Object): void

Obtains the wearing state of a wearable device.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type     | Mandatory | Description                            |
| -------- | -------- | --------- | -------------------------------------- |
| success  | Function | No        | Callback upon success.                 |
| fail     | Function | No        | Callback upon failure.                 |
| complete | Function | No        | Called when the execution is complete. |

Return values of the success callback

| Name  | Type    | Description                          |
| ----- | ------- | ------------------------------------ |
| value | boolean | Whether the wearable device is worn. |

**Example**

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

Subscribes to data changes of the device orientation sensor.

If this API is called multiple times for the same application, the last call takes effect. However, this API cannot be called multiple times in one click event.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name     | Type     | Mandatory | Description                              |
| -------- | -------- | --------- | ---------------------------------------- |
| interval | string   | Yes       | Interval at which the callback is invoked to return the device orientation sensor data.<br>The default value is **normal**. The options are as follows:<br>- **game**: called at an interval of 20 ms, which is applicable to gaming scenarios.<br>- **ui**: called at an interval of 60 ms, which is applicable to UI updating scenarios.<br>- **normal**: called at an interval of 200 ms, which is applicable to power-saving scenarios. |
| success  | Function | Yes       | Called when the device orientation sensor data changes. |
| fail     | Function | No        | Callback upon failure.                   |

 Return values of the success callback
| Name  | Type   | Description                              |
| ----- | ------ | ---------------------------------------- |
| alpha | number | Rotation angle around the Z axis when the X/Y axis of the device coincides with the X/Y axis of the earth. |
| beta  | number | Rotation angle around the X axis when the Y/Z axis of the device coincides with the Y/Z axis of the earth. |
| gamma | number | Rotation angle around the Y axis when the X/Z axis of the device coincides with the X/Z axis of the earth. |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeDeviceOrientation<sup>6+</sup>

unsubscribeDeviceOrientation(): void

Unsubscribes from data changes of the device orientation sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```
sensor.unsubscribeDeviceOrientation();
```

## sensor.subscribeGyroscope<sup>6+</sup>

subscribeGyroscope(interval: string, success: (data: GyroscopeResponse), fail?: (data: string, code: number)): void

Subscribes to data changes of the gyroscope sensor.

If this API is called multiple times for the same application, the last call takes effect. However, this API cannot be called multiple times in one click event.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**Parameters**

| Name     | Type     | Mandatory | Description                              |
| -------- | -------- | --------- | ---------------------------------------- |
| interval | string   | Yes       | Interval at which the callback is invoked to return the gyroscope sensor data.<br>The default value is **normal**. The options are as follows:<br>- **game**: called at an interval of 20 ms, which is applicable to gaming scenarios.<br>- **ui**: called at an interval of 60 ms, which is applicable to UI updating scenarios.<br>- **normal**: called at an interval of 200 ms, which is applicable to power-saving scenarios. |
| success  | Function | Yes       | Called when the gyroscope sensor data changes. |
| fail     | Function | No        | Callback upon failure.                   |

Return values of the success callback

| Name | Type   | Description                              |
| ---- | ------ | ---------------------------------------- |
| x    | number | Rotation angular velocity of the X axis. |
| y    | number | Rotation angular velocity of the Y axis. |
| z    | number | Rotation angular velocity of the Z axis. |

**Example**

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

> **NOTE**
>
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeGyroscope<sup>6+</sup>

unsubscribeGyroscope(): void

Unsubscribes from data changes of the gyroscope sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**Example**

```
sensor.unsubscribeGyroscope();
```
