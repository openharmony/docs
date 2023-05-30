# @system.sensor (Sensor)

The **Sensor** module provides APIs for querying the sensor list, subscribing to or unsubscribing from sensor data, and executing control commands.

The sensors are classified into the following categories based on their functions: motion, environment, orientation, light, body, and other categories (such as Hall effect sensors). Each category includes different sensor types. A sensor type may be a single hardware sensor or a composite of multiple hardware sensors.


> **NOTE**
>
> - The APIs of this module are no longer maintained since API version 8. You are advised to use [`@ohos.sensor`](js-apis-sensor.md) instead.
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This module requires hardware support and can only be debugged on real devices.


## Modules to Import


```
import sensor from '@system.sensor';
```

## sensor.subscribeAccelerometer

 subscribeAccelerometer(options: subscribeAccelerometerOptions): void

Subscribes to data changes of the acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**Parameters**

| Name | Type                                                        | Mandatory| Description                                      |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| options | [subscribeAccelerometerOptions](#subscribeaccelerometeroptions) | Yes  | Type of data to return.|

**Example**

```js
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
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeAccelerometer

unsubscribeAccelerometer(): void

Unsubscribes from data changes of the acceleration sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**Example**

```js
sensor.unsubscribeAccelerometer();
```

## sensor.subscribeCompass

 subscribeCompass(options: SubscribeCompassOptions): void

Subscribes to data changes of the compass sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name | Type                                               | Mandatory| Description                            |
| ------- | --------------------------------------------------- | ---- | -------------------------------- |
| options | [SubscribeCompassOptions](#subscribecompassoptions) | Yes  | Type of data to return.|

**Example**

```js
sensor.subscribeCompass({
  success: function(ret) {
    console.log('Get data direction:' + ret.direction);
  },
  fail: function(data, code) {
    console.error('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeCompass

unsubscribeCompass(): void

Unsubscribes from data changes of the compass sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```js
sensor.unsubscribeCompass();
```

## sensor.subscribeProximity

 subscribeProximity(options: SubscribeProximityOptions): void

Subscribes to data changes of the proximity sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name | Type                                                   | Mandatory| Description                            |
| ------- | ------------------------------------------------------- | ---- | -------------------------------- |
| options | [SubscribeProximityOptions](#subscribeproximityoptions) | Yes  | Type of data to return.|

**Example**

```js
sensor.subscribeProximity({
  success: function(ret) {
    console.log('Get data distance:' + ret.distance);
  },
  fail: function(data, code) {
    console.error('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeProximity

unsubscribeProximity(): void

Unsubscribes from data changes of the proximity sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```js
sensor.unsubscribeProximity();
```

## sensor.subscribeLight

 subscribeLight(options: SubscribeLightOptions): void

Subscribes to data changes of the ambient light sensor. If this API is called multiple times, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name | Type                                           | Mandatory| Description                              |
| ------- | ----------------------------------------------- | ---- | ---------------------------------- |
| options | [SubscribeLightOptions](#subscribelightoptions) | Yes  | Type of data to return.|

**Example**

```js
sensor.subscribeLight({
  success: function(ret) {
    console.log('Get data intensity:' + ret.intensity);
  },
  fail: function(data, code) {
    console.error('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeLight

unsubscribeLight(): void

Unsubscribes from data changes of the ambient light sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```js
sensor.unsubscribeLight();
```

## sensor.subscribeStepCounter

 subscribeStepCounter(options: SubscribeStepCounterOptions): void

Subscribes to data changes of the step counter sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**Parameters**

| Name | Type                                                       | Mandatory| Description                                  |
| ------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| options | [SubscribeStepCounterOptions](#subscribestepcounteroptions) | Yes  | Type of data to return.|

**Example**

```js
sensor.subscribeStepCounter({
  success: function(ret) {
    console.log('Get step value:' + ret.steps);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeStepCounter

unsubscribeStepCounter(): void

Unsubscribes from data changes of the step counter sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**Example**

```js
sensor.unsubscribeStepCounter();
```


## sensor.subscribeBarometer

subscribeBarometer(options: SubscribeBarometerOptions): void

Subscribes to data changes of the barometer sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name | Type                                                   | Mandatory| Description                              |
| ------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| options | [SubscribeBarometerOptions](#subscribebarometeroptions) | Yes  | Type of data to return.|

**Example**

```js
sensor.subscribeBarometer({
  success: function(ret) {
    console.log('Get data value:' + ret.pressure);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.


## sensor.unsubscribeBarometer

unsubscribeBarometer(): void

Unsubscribes from data changes of the barometer sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```js
sensor.unsubscribeBarometer();
```


## sensor.subscribeHeartRate

 subscribeHeartRate(options: SubscribeHeartRateOptions): void

Subscribes to data changes of the heart rate sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**Parameters**

| Name | Type                                                   | Mandatory| Description                            |
| ------- | ------------------------------------------------------- | ---- | -------------------------------- |
| options | [SubscribeHeartRateOptions](#subscribeheartrateoptions) | Yes  | Type of data to return.|

**Example**

```js
sensor.subscribeHeartRate({
  success: function(ret) {
    console.log('Get heartrate value:' + ret.heartRate);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.


## sensor.unsubscribeHeartRate

unsubscribeHeartRate(): void

Unsubscribes from data changes of the heart rate sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**Example**

```js
sensor.unsubscribeHeartRate();
```

## sensor.subscribeOnBodyState

 subscribeOnBodyState(options: SubscribeOnBodyStateOptions): void

Subscribes to changes of the wearing state of a wearable device. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name | Type                                                       | Mandatory| Description                  |
| ------- | ----------------------------------------------------------- | ---- | ---------------------- |
| options | [SubscribeOnBodyStateOptions](#subscribeonbodystateoptions) | Yes  | Type of data to return.|

**Example**

```js
sensor.subscribeOnBodyState({
  success: function(ret) {
    console.log('Get on-body state value:' + ret.value);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeOnBodyState

unsubscribeOnBodyState(): void

Unsubscribes from changes of the wearing state of a wearable device.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```js
sensor.unsubscribeOnBodyState();
```

## sensor.getOnBodyState

 getOnBodyState(options: GetOnBodyStateOptions): void

Obtains the wearing state of a wearable device.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name | Type                                           | Mandatory| Description                      |
| ------- | ----------------------------------------------- | ---- | -------------------------- |
| options | [GetOnBodyStateOptions](#getonbodystateoptions) | Yes  | Type of data to return.|

**Example**

```js
sensor.getOnBodyState({
  success: function(ret) {
    console.log('On body state: ' + ret.value);
  },
  fail: function(data, code) {
    console.log('Subscription failed. Code: ' + code + '; Data: ' + data);
  },
});
```

## sensor.subscribeDeviceOrientation<sup>6+</sup>

 subscribeDeviceOrientation(options: SubscribeDeviceOrientationOptions): void

Subscribes to data changes of the device orientation sensor.

If this API is called multiple times for the same application, the last call takes effect. However, this API cannot be called multiple times in one click event.

**System capability**: SystemCapability.Sensors.Sensor

**Parameters**

| Name | Type                                                        | Mandatory| Description                                            |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| options | [SubscribeDeviceOrientationOptions](#subscribedeviceorientationoptions) | Yes  | Type of data to return.|

**Example**

```js
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
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeDeviceOrientation<sup>6+</sup>

unsubscribeDeviceOrientation(): void

Unsubscribes from data changes of the device orientation sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Example**

```js
sensor.unsubscribeDeviceOrientation();
```

## sensor.subscribeGyroscope<sup>6+</sup>

 subscribeGyroscope(options: SubscribeGyroscopeOptions): void

Subscribes to data changes of the gyroscope sensor.

If this API is called multiple times for the same application, the last call takes effect. However, this API cannot be called multiple times in one click event.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**Parameters**

| Name | Type                                                   | Mandatory| Description                                          |
| ------- | ------------------------------------------------------- | ---- | ---------------------------------------------- |
| options | [SubscribeGyroscopeOptions](#subscribegyroscopeoptions) | Yes  | Type of data to return.|

**Example**

```js
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
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestory** callback.

## sensor.unsubscribeGyroscope<sup>6+</sup>

unsubscribeGyroscope(): void

Unsubscribes from data changes of the gyroscope sensor.

**System capability**: SystemCapability.Sensors.Sensor

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**Example**

```js
sensor.unsubscribeGyroscope();
```

## subscribeAccelerometerOptions

Defines the type of data to return for a subscription to the acceleration sensor data.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

| Name    | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| interval | string                                          | Yes  | Execution frequency of the callback for returning the acceleration sensor data. The default value is **normal**. The options are as follows: - **game**: called at an interval of 20 ms, which is applicable to gaming scenarios. - **ui**: called at an interval of 60 ms, which is applicable to UI updating scenarios. - **normal**: called at an interval of 200 ms, which is applicable to power-saving scenarios.|
| success  | [AccelerometerResponse](#accelerometerresponse) | Yes  | Called when the acceleration sensor data changes.                          |
| fail     | Function                                        | No  | Callback upon an API call failure.                                    |

## AccelerometerResponse 

Defines the type of data to include in an **AccelerometerResponse** object. 

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor

| Name| Type  | Mandatory| Description         |
| ---- | ------ | ---- | ------------- |
| x    | number | Yes  | Acceleration on the x-axis.|
| y    | number | Yes  | Acceleration on the y-axis.|
| z    | number | Yes  | Acceleration on the z-axis.|

## SubscribeCompassOptions

Defines the type of data to return for a subscription to the compass sensor data.

**System capability**: SystemCapability.Sensors.Sensor

| Name   | Type                               | Mandatory| Description                          |
| ------- | ----------------------------------- | ---- | ------------------------------ |
| success | [CompassResponse](#compassresponse) | Yes  | Called when the compass sensor data changes.|
| fail    | Function                            | No  | Callback upon an API call failure.      |

## CompassResponse 

Defines the type of data to include in a **CompassResponse** object.

**System capability**: SystemCapability.Sensors.Sensor

| Name     | Type  | Mandatory| Description                |
| --------- | ------ | ---- | -------------------- |
| direction | number | Yes  | Direction of the device, in degrees.|

## SubscribeProximityOptions

Defines the type of data to return for a subscription to the proximity sensor data.

**System capability**: SystemCapability.Sensors.Sensor

| Name   | Type                                   | Mandatory| Description                              |
| ------- | --------------------------------------- | ---- | ---------------------------------- |
| success | [ProximityResponse](#proximityresponse) | Yes  | Called when the proximity sensor data changes.|
| fail    | Function                                | No  | Callback upon an API call failure.          |

## ProximityResponse 

Defines the type of data to include in a **ProximityResponse** object.

**System capability**: SystemCapability.Sensors.Sensor

| Name    | Type  | Mandatory| Description                                      |
| -------- | ------ | ---- | ------------------------------------------ |
| distance | number | Yes  | Distance between a visible object and the device screen.|

## SubscribeLightOptions

Defines the type of data to return for a subscription to the ambient light sensor data.

**System capability**: SystemCapability.Sensors.Sensor

| Name   | Type                           | Mandatory| Description                          |
| ------- | ------------------------------- | ---- | ------------------------------ |
| success | [LightResponse](#lightresponse) | Yes  | Called when the ambient light sensor data changes|
| fail    | Function                        | No  | Callback upon an API call failure.      |

## LightResponse 

Defines the type of data to include in a **LightResponse** object.

**System capability**: SystemCapability.Sensors.Sensor

| Name     | Type  | Mandatory| Description                 |
| --------- | ------ | ---- | --------------------- |
| intensity | number | Yes  | Light intensity, in lux.|

## SubscribeStepCounterOptions

Defines the type of data to return for a subscription to the step counter sensor data.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

| Name   | Type                                       | Mandatory| Description                            |
| ------- | ------------------------------------------- | ---- | -------------------------------- |
| success | [StepCounterResponse](#stepcounterresponse) | Yes  | Called when the step counter sensor data changes.|
| fail    | Function                                    | No  | Callback upon an API call failure.        |

## StepCounterResponse 

Defines the type of data to include in a **StepCounterResponse** object.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor

| Name | Type  | Mandatory| Description                            |
| ----- | ------ | ---- | -------------------------------- |
| steps | number | Yes  | Number of counted steps after the sensor is restarted.|

## SubscribeBarometerOptions

Defines the type of data to return for a subscription to the barometer sensor data.

**System capability**: SystemCapability.Sensors.Sensor

| Name   | Type                                   | Mandatory| Description                            |
| ------- | --------------------------------------- | ---- | -------------------------------- |
| success | [BarometerResponse](#barometerresponse) | Yes  | Called when the barometer sensor data changes.|
| fail    | Function                                | No  | Callback upon an API call failure.        |

## BarometerResponse 

Defines the type of data to include in a **BarometerResponse** object.

**System capability**: SystemCapability.Sensors.Sensor

| Name    | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| pressure | number | Yes  | Pressure, in pascal.|

## SubscribeHeartRateOptions

Defines the type of data to return for a subscription to the heart rate sensor data.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

| Name   | Type                                   | Mandatory| Description                                           |
| ------- | --------------------------------------- | ---- | ----------------------------------------------- |
| success | [HeartRateResponse](#heartrateresponse) | Yes  | Called when the heart rate sensor data changes. This callback is invoked every five seconds.|
| fail    | Function                                | No  | Callback upon an API call failure.                       |

## HeartRateResponse 

Defines the type of data to include in a **HeartRateResponse** object.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor

| Name     | Type  | Mandatory| Description    |
| --------- | ------ | ---- | -------- |
| heartRate | number | Yes  | Heart rate.|

## SubscribeOnBodyStateOptions

Defines the type of data to return for a subscription to the wearing state changes.

**System capability**: SystemCapability.Sensors.Sensor

| Name   | Type                                       | Mandatory| Description                      |
| ------- | ------------------------------------------- | ---- | -------------------------- |
| success | [OnBodyStateResponse](#onbodystateresponse) | Yes  | Called when the wearing state changes.|
| fail    | Function                                    | No  | Callback upon an API call failure.  |

## OnBodyStateResponse 

Defines the wearing state.

**System capability**: SystemCapability.Sensors.Sensor

| Name | Type   | Mandatory| Description        |
| ----- | ------- | ---- | ------------ |
| value | boolean | Yes  | Whether the wearable device is worn.|

## GetOnBodyStateOptions

 Defines the type of data to return for obtaining the wearing state.

**System capability**: SystemCapability.Sensors.Sensor

| Name    | Type                                       | Mandatory| Description                    |
| -------- | ------------------------------------------- | ---- | ------------------------ |
| success  | [OnBodyStateResponse](#onbodystateresponse) | Yes  | Callback upon a successful API call.|
| fail     | Function                                    | No  | Callback upon an API call failure.|
| complete | Function                                    | No  | Called when the API call is complete.|

## SubscribeDeviceOrientationOptions<sup>6+</sup>

Defines the type of data to return for a subscription to the device orientation sensor data.

**System capability**: SystemCapability.Sensors.Sensor

| Name    | Type                                                   | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| interval | string                                                  | Yes  | Interval at which the callback is invoked to return the device orientation sensor data.<br>The default value is **normal**. The options are as follows:<br>- **game**: called at an interval of 20 ms, which is applicable to gaming scenarios.<br>- **ui**: called at an interval of 60 ms, which is applicable to UI updating scenarios.<br>- **normal**: called at an interval of 200 ms, which is applicable to power-saving scenarios.|
| success  | [DeviceOrientationResponse](#deviceorientationresponse) | Yes  | Called when the device orientation sensor data changes.                  |
| fail     | Function                                                | No  | Callback upon an API call failure.                                    |

## DeviceOrientationResponse<sup>6+</sup> 

Defines the type of data to include in a **DeviceOrientationResponse** object.

**System capability**: SystemCapability.Sensors.Sensor

| Name | Type  | Mandatory| Description                                                        |
| ----- | ------ | ---- | ------------------------------------------------------------ |
| alpha | number | Yes  | Rotation angle around the Z axis when the X/Y axis of the device coincides with the X/Y axis of the earth.|
| beta  | number | Yes  | Rotation angle around the X axis when the Y/Z axis of the device coincides with the Y/Z axis of the earth.|
| gamma | number | Yes  | Rotation angle around the Y axis when the X/Z axis of the device coincides with the X/Z axis of the earth.|

## SubscribeGyroscopeOptions<sup>6+</sup> 

Defines the type of data to return for a subscription to the gyroscope sensor data.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

| Name    | Type                                   | Mandatory| Description                                                        |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| interval | string                                  | Yes  | Interval at which the callback is invoked to return the gyroscope sensor data.<br>The default value is **normal**. The options are as follows:<br>- **game**: called at an interval of 20 ms, which is applicable to gaming scenarios.<br>- **ui**: called at an interval of 60 ms, which is applicable to UI updating scenarios.<br>- **normal**: called at an interval of 200 ms, which is applicable to power-saving scenarios.|
| success  | [GyroscopeResponse](#gyroscoperesponse) | Yes  | Called when the gyroscope sensor data changes.                          |
| fail     | Function                                | No  | Callback upon an API call failure.                                    |

## GyroscopeResponse<sup>6+</sup> 

Defines the type of data to include in a **GyroscopeResponse** object.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor

| Name| Type  | Mandatory| Description             |
| ---- | ------ | ---- | ----------------- |
| x    | number | Yes  | Rotation angular velocity of the X axis.|
| y    | number | Yes  | Rotation angular velocity of the Y axis.|
| z    | number | Yes  | Rotation angular velocity of the Z axis.|
