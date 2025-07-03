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
import { Sensor } from '@kit.SensorServiceKit';
```

## Sensor.subscribeAccelerometer

 subscribeAccelerometer(options: subscribeAccelerometerOptions): void

Subscribes to data changes of the acceleration sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**Parameters**

| Name | Type                                                        | Mandatory| Description                                      |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| options | [subscribeAccelerometerOptions](#subscribeaccelerometeroptions) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, AccelerometerResponse, subscribeAccelerometerOptions } from '@kit.SensorServiceKit';

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
Sensor.subscribeAccelerometer(accelerometerOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.

## Sensor.unsubscribeAccelerometer

unsubscribeAccelerometer(): void

Unsubscribes from data changes of the acceleration sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Required permissions**: ohos.permission.ACCELEROMETER (a system permission)

**Example**

```ts
Sensor.unsubscribeAccelerometer();
```

## Sensor.subscribeCompass

 subscribeCompass(options: SubscribeCompassOptions): void

Subscribes to data changes of the compass sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Parameters**

| Name | Type                                               | Mandatory| Description                            |
| ------- | --------------------------------------------------- | ---- | -------------------------------- |
| options | [SubscribeCompassOptions](#subscribecompassoptions) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, CompassResponse, SubscribeCompassOptions } from '@kit.SensorServiceKit';

let subscribeCompassOptions: SubscribeCompassOptions = {
  success: (ret: CompassResponse) => {
    console.info('Succeeded in subscribing. Get data direction:' + ret.direction);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
Sensor.subscribeCompass(subscribeCompassOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.

## Sensor.unsubscribeCompass

unsubscribeCompass(): void

Unsubscribes from data changes of the compass sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Example**

```ts
Sensor.unsubscribeCompass();
```

## Sensor.subscribeProximity

 subscribeProximity(options: SubscribeProximityOptions): void

Subscribes to data changes of the proximity sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Parameters**

| Name | Type                                                   | Mandatory| Description                            |
| ------- | ------------------------------------------------------- | ---- | -------------------------------- |
| options | [SubscribeProximityOptions](#subscribeproximityoptions) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, ProximityResponse, SubscribeProximityOptions } from '@kit.SensorServiceKit';

let subscribeProximityOptions: SubscribeProximityOptions = {
  success: (ret: ProximityResponse) => {
    console.info('Succeeded in subscribing. Get data distance:' + ret.distance);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
Sensor.subscribeProximity(subscribeProximityOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.

## Sensor.unsubscribeProximity

unsubscribeProximity(): void

Unsubscribes from data changes of the proximity sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Example**

```ts
Sensor.unsubscribeProximity();
```

## Sensor.subscribeLight

 subscribeLight(options: SubscribeLightOptions): void

Subscribes to data changes of the ambient light sensor. If this API is called multiple times, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Parameters**

| Name | Type                                           | Mandatory| Description                              |
| ------- | ----------------------------------------------- | ---- | ---------------------------------- |
| options | [SubscribeLightOptions](#subscribelightoptions) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, LightResponse, SubscribeLightOptions } from '@kit.SensorServiceKit';

let subscribeLightOptions: SubscribeLightOptions = {
  success: (ret: LightResponse) => {
    console.info('Succeeded in subscribing. Get data intensity:' + ret.intensity);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
Sensor.subscribeLight(subscribeLightOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.

## Sensor.unsubscribeLight

unsubscribeLight(): void

Unsubscribes from data changes of the ambient light sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Example**

```ts
Sensor.unsubscribeLight();
```

## Sensor.subscribeStepCounter

 subscribeStepCounter(options: SubscribeStepCounterOptions): void

Subscribes to data changes of the step counter sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**Parameters**

| Name | Type                                                       | Mandatory| Description                                  |
| ------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| options | [SubscribeStepCounterOptions](#subscribestepcounteroptions) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, StepCounterResponse, SubscribeStepCounterOptions } from '@kit.SensorServiceKit';

let subscribeStepCounterOptions: SubscribeStepCounterOptions = {
  success: (ret: StepCounterResponse) => {
    console.info('Succeeded in subscribing. Get step value:' + ret.steps);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
Sensor.subscribeStepCounter(subscribeStepCounterOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.

## Sensor.unsubscribeStepCounter

unsubscribeStepCounter(): void

Unsubscribes from data changes of the step counter sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**Example**

```ts
Sensor.unsubscribeStepCounter();
```


## Sensor.subscribeBarometer

subscribeBarometer(options: SubscribeBarometerOptions): void

Subscribes to data changes of the barometer sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Parameters**

| Name | Type                                                   | Mandatory| Description                              |
| ------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| options | [SubscribeBarometerOptions](#subscribebarometeroptions) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, BarometerResponse, SubscribeBarometerOptions } from '@kit.SensorServiceKit';

let subscribeBarometerOptions: SubscribeBarometerOptions = {
  success: (ret: BarometerResponse) => {
    console.info('Succeeded in subscribing. Get data value:' + ret.pressure);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
Sensor.subscribeBarometer(subscribeBarometerOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.


## Sensor.unsubscribeBarometer

unsubscribeBarometer(): void

Unsubscribes from data changes of the barometer sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Example**

```ts
Sensor.unsubscribeBarometer();
```


## Sensor.subscribeHeartRate

 subscribeHeartRate(options: SubscribeHeartRateOptions): void

Subscribes to data changes of the heart rate sensor. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**Parameters**

| Name | Type                                                   | Mandatory| Description                            |
| ------- | ------------------------------------------------------- | ---- | -------------------------------- |
| options | [SubscribeHeartRateOptions](#subscribeheartrateoptions) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, HeartRateResponse, SubscribeHeartRateOptions } from '@kit.SensorServiceKit';

let subscribeHeartRateOptions: SubscribeHeartRateOptions = {
  success: (ret: HeartRateResponse) => {
    console.info('Succeeded in subscribing. Get heartrate value:' + ret.heartRate);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
Sensor.subscribeHeartRate(subscribeHeartRateOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.


## Sensor.unsubscribeHeartRate

unsubscribeHeartRate(): void

Unsubscribes from data changes of the heart rate sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**Example**

```ts
Sensor.unsubscribeHeartRate();
```

## Sensor.subscribeOnBodyState

 subscribeOnBodyState(options: SubscribeOnBodyStateOptions): void

Subscribes to wearing status changes of a wearable device. If this API is called multiple times for the same application, the last call takes effect.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Parameters**

| Name | Type                                                       | Mandatory| Description                  |
| ------- | ----------------------------------------------------------- | ---- | ---------------------- |
| options | [SubscribeOnBodyStateOptions](#subscribeonbodystateoptions) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, OnBodyStateResponse, SubscribeOnBodyStateOptions } from '@kit.SensorServiceKit';

let subscribeOnBodyStateOptions: SubscribeOnBodyStateOptions = {
  success: (ret: OnBodyStateResponse) => {
    console.info('Succeeded in subscribing. Get on-body state value:' + ret.value);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
Sensor.subscribeOnBodyState(subscribeOnBodyStateOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.

## Sensor.unsubscribeOnBodyState

unsubscribeOnBodyState(): void

Unsubscribes from wearing status changes of a wearable device.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Example**

```ts
Sensor.unsubscribeOnBodyState();
```

## Sensor.getOnBodyState

 getOnBodyState(options: GetOnBodyStateOptions): void

Obtains the wearing state of a wearable device.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Parameters**

| Name | Type                                           | Mandatory| Description                      |
| ------- | ----------------------------------------------- | ---- | -------------------------- |
| options | [GetOnBodyStateOptions](#getonbodystateoptions) | Yes  | Callback invoked when obtaining the wearing state of the device that accommodates the sensor.|

**Example**

```ts
import { Sensor, OnBodyStateResponse, GetOnBodyStateOptions } from '@kit.SensorServiceKit';

let getOnBodyStateOptions: GetOnBodyStateOptions = {
  success: (ret: OnBodyStateResponse) => {
    console.info('Succeeded in subscribing. On body state: ' + ret.value);
  },
  fail: (data: string, code: number) => {
    console.error(`Failed to subscription. Code: ${code}, data: ${data}`);
  },
};
Sensor.getOnBodyState(getOnBodyStateOptions);
```

## Sensor.subscribeDeviceOrientation<sup>6+</sup>

 subscribeDeviceOrientation(options: SubscribeDeviceOrientationOptions): void

Subscribes to data changes of the device orientation sensor.

If this API is called multiple times for the same application, the last call takes effect. However, this API cannot be called multiple times in one click event.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Parameters**

| Name | Type                                                        | Mandatory| Description                                            |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| options | [SubscribeDeviceOrientationOptions](#subscribedeviceorientationoptions6) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, DeviceOrientationResponse, SubscribeDeviceOrientationOptions } from '@kit.SensorServiceKit';

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
Sensor.subscribeDeviceOrientation(subscribeDeviceOrientationOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.

## Sensor.unsubscribeDeviceOrientation<sup>6+</sup>

unsubscribeDeviceOrientation(): void

Unsubscribes from data changes of the device orientation sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Example**

```ts
Sensor.unsubscribeDeviceOrientation();
```

## Sensor.subscribeGyroscope<sup>6+</sup>

 subscribeGyroscope(options: SubscribeGyroscopeOptions): void

Subscribes to data changes of the gyroscope sensor.

If this API is called multiple times for the same application, the last call takes effect. However, this API cannot be called multiple times in one click event.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**Parameters**

| Name | Type                                                    | Mandatory| Description                                          |
| ------- | -------------------------------------------------------- | ---- | ---------------------------------------------- |
| options | [SubscribeGyroscopeOptions](#subscribegyroscopeoptions6) | Yes  | Type of data to return.|

**Example**

```ts
import { Sensor, GyroscopeResponse, SubscribeGyroscopeOptions } from '@kit.SensorServiceKit';

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
Sensor.subscribeGyroscope(subscribeGyroscopeOptions);
```

> **NOTE**
> To reduce performance overhead, you are advised to unsubscribe from the sensor data in the **onDestroy** callback.

## Sensor.unsubscribeGyroscope<sup>6+</sup>

unsubscribeGyroscope(): void

Unsubscribes from data changes of the gyroscope sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

**Required permissions**: ohos.permission.GYROSCOPE (a system permission)

**Example**

```ts
Sensor.unsubscribeGyroscope();
```

## subscribeAccelerometerOptions

Defines the type of data to return for a subscription to data changes of the acceleration sensor.

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name    | Type                                           | Mandatory| Description                                                        |
| -------- | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| interval | string                                          | Yes  | Execution frequency of the callback for returning the acceleration sensor data.<br>The default value is **normal**. The options are as follows:<br>- **game**: called at an interval of 20 ms, which is applicable to gaming scenarios.<br>- **ui**: called at an interval of 60 ms, which is applicable to UI updating scenarios.<br>- **normal**: called at an interval of 200 ms, which is applicable to power-saving scenarios.|
| success  | [AccelerometerResponse](#accelerometerresponse) | Yes  | Callback invoked when the acceleration sensor data changes.                          |
| fail     | Function                                        | No  | Callback invoked when an API call fails.                                    |

## AccelerometerResponse 

Defines the callback invoked when the acceleration sensor data changes. 

**Required permissions**: ohos.permission.ACCELEROMETER

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name| Type  | Mandatory| Description         |
| ---- | ------ | ---- | ------------- |
| x    | number | Yes  | Acceleration on the x-axis.|
| y    | number | Yes  | Acceleration on the y-axis.|
| z    | number | Yes  | Acceleration on the z-axis.|

## SubscribeCompassOptions

Defines the type of data to return for a subscription to data changes of the compass sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name   | Type                               | Mandatory| Description                          |
| ------- | ----------------------------------- | ---- | ------------------------------ |
| success | [CompassResponse](#compassresponse) | Yes  | Callback invoked when the compass sensor data changes.|
| fail    | Function                            | No  | Callback invoked when an API call fails.      |

## CompassResponse 

Defines a **CompassResponse** object.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name     | Type  | Mandatory| Description                |
| --------- | ------ | ---- | -------------------- |
| direction | number | Yes  | Direction of the device, in degrees.|

## SubscribeProximityOptions

Defines the type of data to return for a subscription to data changes of the proximity sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name   | Type                                   | Mandatory| Description                              |
| ------- | --------------------------------------- | ---- | ---------------------------------- |
| success | [ProximityResponse](#proximityresponse) | Yes  | Defines a **ProximityResponse** object.|
| fail    | Function                                | No  | Callback invoked when an API call fails.          |

## ProximityResponse 

Callback invoked when the proximity sensor data changes.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name    | Type  | Mandatory| Description                                      |
| -------- | ------ | ---- | ------------------------------------------ |
| distance | number | Yes  | Distance between a visible object and the device screen.|

## SubscribeLightOptions

Defines the type of data to return for a subscription to data changes of the ambient light sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name   | Type                           | Mandatory| Description                          |
| ------- | ------------------------------- | ---- | ------------------------------ |
| success | [LightResponse](#lightresponse) | Yes  | Callback invoked when the ambient light sensor data changes.|
| fail    | Function                        | No  | Callback invoked when an API call fails.      |

## LightResponse 

Defines a **LightResponse** object.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name     | Type  | Mandatory| Description                 |
| --------- | ------ | ---- | --------------------- |
| intensity | number | Yes  | Light intensity, in lux.|

## SubscribeStepCounterOptions

Defines the type of data to return for a subscription to data changes of the step counter sensor.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name   | Type                                       | Mandatory| Description                            |
| ------- | ------------------------------------------- | ---- | -------------------------------- |
| success | [StepCounterResponse](#stepcounterresponse) | Yes  | Defines a **StepCounterResponse** object.|
| fail    | Function                                    | No  | Callback invoked when an API call fails.        |

## StepCounterResponse 

Callback invoked when the step counter sensor data changes.

**Required permissions**: ohos.permission.ACTIVITY_MOTION

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name | Type  | Mandatory| Description                            |
| ----- | ------ | ---- | -------------------------------- |
| steps | number | Yes  | Number of counted steps after the sensor is restarted.|

## SubscribeBarometerOptions

Defines the type of data to return for a subscription to data changes of the barometer sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name   | Type                                   | Mandatory| Description                            |
| ------- | --------------------------------------- | ---- | -------------------------------- |
| success | [BarometerResponse](#barometerresponse) | Yes  | Callback invoked when the barometer sensor data changes.|
| fail    | Function                                | No  | Callback invoked when an API call fails.        |

## BarometerResponse 

Defines a **BarometerResponse** object.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name    | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| pressure | number | Yes  | Pressure, in pascal.|

## SubscribeHeartRateOptions

Defines the type of data to return for a subscription to data changes of the heart rate sensor.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name   | Type                                   | Mandatory| Description                                           |
| ------- | --------------------------------------- | ---- | ----------------------------------------------- |
| success | [HeartRateResponse](#heartrateresponse) | Yes  | Callback invoked when the heart rate sensor data changes. This callback is invoked every five seconds.|
| fail    | Function                                | No  | Callback invoked when an API call fails.                       |

## HeartRateResponse 

Defines a **HeartRateResponse** object.

**Required permissions**: ohos.permission.READ_HEALTH_DATA

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name     | Type  | Mandatory| Description    |
| --------- | ------ | ---- | -------- |
| heartRate | number | Yes  | Heart rate.|

## SubscribeOnBodyStateOptions

Defines the callback invoked upon change in the wearing state of the device that accommodates the sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name   | Type                                       | Mandatory| Description                      |
| ------- | ------------------------------------------- | ---- | -------------------------- |
| success | [OnBodyStateResponse](#onbodystateresponse) | Yes  | Callback invoked when obtaining the wearing state change of the device that accommodates the sensor.|
| fail    | Function                                    | No  | Callback invoked when an API call fails.  |

## OnBodyStateResponse 

Whether the device where the sensor is located is worn.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name | Type   | Mandatory| Description                                              |
| ----- | ------- | ---- | -------------------------------------------------- |
| value | boolean | Yes  | Boolean value indicating whether the device is worn. The value true indicates that the device is worn, and the value **false** indicates the opposite.|

## GetOnBodyStateOptions

 Defines the callback for obtaining the wearing state of the device that accommodates the sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name    | Type                                       | Mandatory| Description                    |
| -------- | ------------------------------------------- | ---- | ------------------------ |
| success  | [OnBodyStateResponse](#onbodystateresponse) | Yes  | Callback upon a successful API call.|
| fail     | Function                                    | No  | Callback invoked when an API call fails.|
| complete | Function                                    | No  | Callback invoked when the API call is complete.|

## SubscribeDeviceOrientationOptions<sup>6+</sup>

Defines the type of data to return for a subscription to data changes of the device orientation sensor.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name    | Type                                                    | Mandatory| Description                                                        |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| interval | string                                                   | Yes  | Interval at which the callback is invoked to return the device orientation sensor data.<br>The default value is **normal**. The options are as follows:<br>- **game**: called at an interval of 20 ms, which is applicable to gaming scenarios.<br>- **ui**: called at an interval of 60 ms, which is applicable to UI updating scenarios.<br>- **normal**: called at an interval of 200 ms, which is applicable to power-saving scenarios.|
| success  | [DeviceOrientationResponse](#deviceorientationresponse6) | Yes  | Callback invoked when the device orientation sensor data changes.                  |
| fail     | Function                                                 | No  | Callback invoked when an API call fails.                                    |

## DeviceOrientationResponse<sup>6+</sup> 

Defines a **DeviceOrientationResponse** object.

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name | Type  | Mandatory| Description                                                        |
| ----- | ------ | ---- | ------------------------------------------------------------ |
| alpha | number | Yes  | Rotation angle around the Z axis when the X/Y axis of the device coincides with the X/Y axis of the earth.|
| beta  | number | Yes  | Rotation angle around the X axis when the Y/Z axis of the device coincides with the Y/Z axis of the earth.|
| gamma | number | Yes  | Rotation angle around the Y axis when the X/Z axis of the device coincides with the X/Z axis of the earth.|

## SubscribeGyroscopeOptions<sup>6+</sup> 

Defines the type of data to return for a subscription to data changes of the gyroscope sensor.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name    | Type                                    | Mandatory| Description                                                        |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| interval | string                                   | Yes  | Interval at which the callback is invoked to return the gyroscope sensor data.<br>The default value is **normal**. The options are as follows:<br>- **game**: called at an interval of 20 ms, which is applicable to gaming scenarios.<br>- **ui**: called at an interval of 60 ms, which is applicable to UI updating scenarios.<br>- **normal**: called at an interval of 200 ms, which is applicable to power-saving scenarios.|
| success  | [GyroscopeResponse](#gyroscoperesponse6) | Yes  | Callback invoked when the gyroscope sensor data changes.                          |
| fail     | Function                                 | No  | Callback invoked when an API call fails.                                    |

## GyroscopeResponse<sup>6+</sup> 

Defines a **GyroscopeResponse** object.

**Required permissions**: ohos.permission.GYROSCOPE

**System capability**: SystemCapability.Sensors.Sensor.Lite

| Name| Type  | Mandatory| Description             |
| ---- | ------ | ---- | ----------------- |
| x    | number | Yes  | Rotation angular velocity of the X axis.|
| y    | number | Yes  | Rotation angular velocity of the Y axis.|
| z    | number | Yes  | Rotation angular velocity of the Z axis.|
