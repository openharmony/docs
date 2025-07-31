# @ohos.distributedHardware.mechanicManager (机械体控制模块)(系统接口)

本模块提供与机械设备交互的能力，包括设备连接管理、控制和监控功能。

> **说明：**
>
> - 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.distributedHardware.mechanicManager (机械体控制模块)](js-apis-mechanicManager.md)。

## 导入模块

```js
import { mechanicManager } from '@kit.MechanicKit';
```

## mechanicManager.setUserOperation

setUserOperation(operation: Operation, mac: string, params: string): void

设置用户的连接或断开操作。

**需要权限**：ohos.permission.CONNECT_MECHANIC_HARDWARE

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| operation | [Operation](#operation) | 是 | 操作类型。 |
| mac | string | 是 | 机械体设备MAC地址。 |
| params | string | 是 | 操作参数。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 33300001 | Service exception. |

**示例：**

```ts
console.info('User operate');
mechanicManager.setUserOperation(mechanicManager.Operation.CONNECT, "58:51:9e:e7:79:6d", "operatingParams");
console.info('User operation was successful');
```

## mechanicManager.setCameraTrackingLayout

setCameraTrackingLayout(trackingLayout: CameraTrackingLayout): void

设置当前机械体设备摄像头跟踪布局。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| trackingLayout | [CameraTrackingLayout](js-apis-mechanicManager.md#cameratrackinglayout) | 是 | 摄像头跟踪布局。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |
| 33300003 | Feature not supported. |

**示例：**

```ts
console.info('Set layout');
mechanicManager.setCameraTrackingLayout(mechanicManager.CameraTrackingLayout.LEFT);
console.info('Set layout successful');
```

## mechanicManager.rotate

rotate(mechId: number, angles: RotationAngles, duration: number): Promise\<Result>

将机械体设备旋转到相对角度。使用Promise异步回调。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | 是 | 机械体设备ID。 |
| angles | [RotationAngles](#rotationangles) | 是 | 相对当前位置的旋转角度。 |
| duration | number | 是 | 旋转持续时间，单位：ms。 |

**返回值：**

| 类型                                        | 说明        |
| ------------------------------------------- | --------- |
| Promise\<[Result](#result)> | Promise对象，返回旋转执行结果。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**示例：**

```ts
console.info('Start rotate');
let degree: mechanicManager.RotationAngles = {
  yaw: 0.1 * Math.PI,
  roll: 0.0,
  pitch: 0.0
}
mechanicManager.rotate(0, degree, 500)
  .then((result: mechanicManager.Result) => {
    console.info(`'Rotate result:' ${result}`);
  });
console.info('End rotation');
```

## mechanicManager.rotateToEulerAngles

rotateToEulerAngles(mechId: number, angles: EulerAngles, duration: number): Promise\<Result>

将机械体设备旋转到绝对角度。使用Promise异步回调。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | 是 | 机械体设备ID。 |
| angles | [EulerAngles](#eulerangles) | 是 | 绝对角度。 |
| duration | number | 是 | 旋转持续时间，单位：ms。 |

**返回值：**

| 类型                                        | 说明        |
| ------------------------------------------- | --------- |
| Promise\<[Result](#result)> | Promise对象，返回旋转执行结果。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**示例：**

```ts
let degree: mechanicManager.EulerAngles = {
  yaw: 0.9 * Math.PI,
  roll: 0.9 * Math.PI,
  pitch: 0.9 * Math.PI
}
mechanicManager.rotateToEulerAngles(0, degree, 500)
  .then((result: mechanicManager.Result) => {
    console.info(`'Rotate result:' ${result}`);
  });
console.info('End rotation');
```

## mechanicManager.getMaxRotationTime

getMaxRotationTime(mechId: number): number

获取机械体设备的最大连续旋转持续时间。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | 是 | 机械体设备ID。 |

**返回值：**

| 类型                                        | 说明        |
| ------------------------------------------- | --------- |
| number | 最大旋转持续时间，单位：ms。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息  |
| -------- | -------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**示例：**

```ts
console.info('Query maximum rotation time');
let maxTime = mechanicManager.getMaxRotationTime(0);
console.info(`'Query maximum rotation time successful, maximum time:' ${maxTime}`);
```

## mechanicManager.getMaxRotationSpeed

getMaxRotationSpeed(mechId: number): RotationSpeed

获取机械设备的最大旋转速度。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | 是 | 机械体设备ID。 |

**返回值：**

| 类型                                        | 说明        |
| ------------------------------------------- | --------- |
| [RotationSpeed](#rotationspeed) | 最大旋转速度，仅返回速度的绝对值。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**示例：**

```ts
console.info('Query rotation speed');
let speedLimit: mechanicManager.RotationSpeed = mechanicManager.getMaxRotationSpeed(0);
console.info(`'Query rotation speed successful, speed limit information:' ${speedLimit}`);
```

## mechanicManager.rotateBySpeed

rotateBySpeed(mechId: number, speed: RotationSpeed, duration: number): Promise\<Result>

以指定速度旋转当前机械体设备。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | 是 | 机械体设备ID。 |
| speed | [RotationSpeed](#rotationspeed) | 是 | 指定旋转速度。最大旋转速度不超过getMaxRotationSpeed的返回值大小，如果超过最大速度，默认取最大值。 |
| duration | number | 是 | 旋转持续时间，单位：ms。最大时间不超过getMaxRotationTime的返回值大小，如果超过最大时间，默认取最大值。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**示例：**

```ts
console.info('Start rotate');
let degree: mechanicManager.RotationSpeed = {
  yawSpeed: 3 * Math.PI,
  rollSpeed: 3 * Math.PI,
  pitchSpeed: 3 * Math.PI
}
mechanicManager.rotateBySpeed(0, degree, 500)
  .then((result) => {
    console.info(`'Rotate result:' ${result}`);
  });
console.info('Rotate finish');
```

## mechanicManager.stopMoving

stopMoving(mechId: number): Promise\<void>

停止机械体设备的移动。使用Promise异步回调。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | 是 | 机械体设备ID。 |

**返回值：**

| 类型                                        | 说明        |
| ------------------------------------------- | --------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**示例：**

```ts
console.info('Stop moving');
mechanicManager.stopMoving(0)
  .then(() => {
    console.info('Get stop complete');
  });
console.info('Stop succeeded');
```

## mechanicManager.getCurrentAngles

getCurrentAngles(mechId: number): EulerAngles

获取指定机械体设备相对于初始位置的当前旋转角度。

> **说明：**
>
> 初始位置：机械设备初始化的位置，坐标为（0， 0， 0）。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | 是 | 机械体设备ID。 |

**返回值：**

| 类型                                        | 说明        |
| ------------------------------------------- | --------- |
| [EulerAngles](#eulerangles) | 机械体设备的当前旋转角度。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**示例：**

```ts
console.info('Query current location');
let currentAngles: mechanicManager.EulerAngles = mechanicManager.getCurrentAngles(0);
console.info(`'Query current location, location:' ${currentAngles}`);
```

## mechanicManager.getRotationLimits

getRotationLimits(mechId: number): RotationLimits

获取指定机械体设备相对于初始位置的最大旋转角度。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | 是 | 机械体设备ID。 |

**返回值：**

| 类型                                        | 说明        |
| ------------------------------------------- | --------- |
| [RotationLimits](#rotationlimits) | 最大旋转角度。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**示例：**

```ts
console.info('Query rotation limit information');
let degreeLimit: mechanicManager.RotationLimits = mechanicManager.getRotationLimits(0);
console.info(`'Query the rotation limit information successfully, limit information:' ${degreeLimit}`);
```

## mechanicManager.on('rotationAxesStatusChange')

on(type: 'rotationAxesStatusChange', callback: Callback\<RotationAxesStateChangeInfo>): void

注册旋转轴状态变化事件的回调监听。使用callback异步回调。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| type | 'rotationAxesStatusChange' | 是 | 注册监听事件的类型。取值为：'rotationAxesStatusChange'。 |
| callback | Callback\<[RotationAxesStateChangeInfo](#rotationaxesstatechangeinfo)> | 是 | 回调函数，返回机械体设备旋转轴状态变化信息。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |

**示例：**

```ts
console.info('Register Axis Status listener');
mechanicManager.on("rotationAxesStatusChange", (result: mechanicManager.RotationAxesStateChangeInfo) => {
  console.info(`'result:' ${result}`);
});
console.info('Successful registration');
```

## mechanicManager.off('rotationAxesStatusChange')

off(type: 'rotationAxesStatusChange', callback?: Callback\<RotationAxesStateChangeInfo>): void

取消注册旋转轴状态变化事件的回调监听。使用callback异步回调。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| type | 'rotationAxesStatusChange' | 是 | 取消注册监听事件的类型。取值为：'rotationAxesStatusChange'。 |
| callback | Callback\<[RotationAxesStateChangeInfo](#rotationaxesstatechangeinfo)> | 否 |  mechanicManager.off('rotationAxesStatusChange')注册的回调函数。不填时默认取消所有注册的回调函数。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |

**示例：**

```ts
console.info('Unregister Axis Status listener');
mechanicManager.off("rotationAxesStatusChange", (result: mechanicManager.RotationAxesStateChangeInfo) => {
  console.info(`'result:' ${result}`);
});
console.info('Unregister successfully');
```

## mechanicManager.getRotationAxesStatus

getRotationAxesStatus(mechId: number): RotationAxesStatus

获取当前机械体设备旋转轴的状态。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

**参数：**

| 参数名     | 类型                    | 必填 | 说明   |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | 是 | 机械体设备ID。 |

**返回值：**

| 类型                                        | 说明        |
| ------------------------------------------- | --------- |
| [RotationAxesStatus](#rotationaxesstatus) | 旋转轴状态。 |

**错误码：**

以下的错误码的详细介绍请参见[机械体控制模块错误码](errorcode-mechanic.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**示例：**

```ts
console.info('Query the rotation axis status');
let axisStatus: mechanicManager.RotationAxesStatus = mechanicManager.getRotationAxesStatus(0);
console.info(`'Query the rotation axis status successfully, axis state:' ${axisStatus}`);
```

## RotationAngles

相对当前位置的旋转角度。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

| 名称   | 类型 | 只读 | 可选 | 说明|
| ----- | ---- | ---- | --- | --- |
| yaw | number | 否 | 是 | 偏航角，范围为[-2\*Math.PI， 2\*Math.PI]，以弧度为单位。 |
| roll | number | 否 | 是 | 横滚角，范围为[-2\*Math.PI， 2\*Math.PI]，以弧度为单位。 |
| pitch | number | 否 | 是 | 俯仰角，范围为[-2\*Math.PI， 2\*Math.PI]，以弧度为单位。 |

## EulerAngles

相对于初始位置的绝对欧拉角。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

| 名称   | 类型 | 只读 | 可选 | 说明|
| ----- | ---- | ---- | --- | --- |
| yaw | number | 否 | 是 | 偏航角，范围为[-2\*Math.PI， 2\*Math.PI]，以弧度为单位。 |
| roll | number | 否 | 是 | 横滚角，范围为[-2\*Math.PI， 2\*Math.PI]，以弧度为单位。 |
| pitch | number | 否 | 是 | 俯仰角，范围为[-2\*Math.PI， 2\*Math.PI]，以弧度为单位。 |

## RotationSpeed

旋转速度。负值表示顺时针旋转，正值表示逆时针旋转。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

| 名称   | 类型 | 只读 | 可选 | 说明|
| ----- | ---- | ---- | --- | --- |
| yawSpeed | number | 否| 是 | 偏航速度，以弧度每秒为单位。 |
| rollSpeed | number | 否 | 是 | 横滚速度，以弧度每秒为单位。 |
| pitchSpeed | number | 否 | 是 | 俯仰速度，以弧度每秒为单位。 |

## RotationLimits

相对于初始位置的旋转角度限制。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

| 名称   | 类型 | 只读 | 可选 | 说明|
| ----- | ---- | ---- | --- | --- |
| negativeYawMax | number | 否 | 否 | 最大偏航旋转角度（负方向），范围为[-2\*Math.PI， 0]，以弧度为单位。如果值小于或等于 -2\*Math.PI，则没有限制。 |
| positiveYawMax | number | 否 | 否 | 最大偏航旋转角度（正方向），范围为[0， 2\*Math.PI]，以弧度为单位。如果值大于或等于 2\*Math.PI，则没有限制。 |
| negativeRollMax | number | 否 | 否 | 最大横滚旋转角度（负方向），范围为[-2\*Math.PI, 0]，以弧度为单位。如果值小于或等于 -2\*Math.PI，则没有限制。 |
| positiveRollMax | number | 否 | 否 | 最大横滚旋转角度（正方向），范围为[0， 2\*Math.PI]，以弧度为单位。如果值大于或等于 2\*Math.PI，则没有限制。 |
| negativePitchMax | number | 否 | 否 | 最大俯仰旋转角度（负方向），范围为[-2\*Math.PI， 0]，以弧度为单位。如果值小于或等于 -2\*Math.PI，则没有限制。 |
| positivePitchMax | number | 否 | 否 | 最大俯仰旋转角度（正方向），范围为[0， 2\*Math.PI]，以弧度为单位。如果值大于或等于 2\*Math.PI，则没有限制。 |

## RotationAxesStatus

旋转轴状态。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

| 名称   | 类型 | 只读 | 可选 | 说明|
| ----- | ---- | ---- | --- | --- |
| yawEnabled | boolean | 否 | 否 | 是否启用了偏航轴，true表示已启用，false表示已禁用。 |
| rollEnabled | boolean | 否 | 否 | 是否启用了横滚轴，true表示已启用，false表示已禁用。 |
| pitchEnabled | boolean | 否 | 否 | 是否启用了俯仰轴，true表示已启用，false表示已禁用。 |
| yawLimited | [RotationAxisLimited](#rotationaxislimited) | 否 | 是 | 偏航轴限位状态。 |
| rollLimited | [RotationAxisLimited](#rotationaxislimited) | 否 | 是 | 横滚轴限位状态。 |
| pitchLimited | [RotationAxisLimited](#rotationaxislimited) | 否 | 是 | 俯仰轴限位状态。 |

## RotationAxisLimited

旋转轴限位状态的枚举。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

| 名称         | 值  | 说明              |
| ----------- | ---- | --------------- |
| NOT_LIMITED | 0 | 无限制 |
| NEGATIVE_LIMITED | 1 | 负方向受限，可以向相反方向转动。 |
| POSITIVE_LIMITED | 2 | 正方向受限，可以向相反方向转动。 |

## RotationAxesStateChangeInfo

旋转轴状态变化信息。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

| 名称   | 类型 | 只读 | 可选 | 说明|
| ----- | ---- | ---- | --- | --- |
| mechId | number | 否 | 否 | 机械体设备ID。 |
| status | [RotationAxesStatus](#rotationaxesstatus)| 否 | 否 | 旋转轴状态。 |

## Operation

用户操作的枚举。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

| 名称         | 值  | 说明              |
| ----------- | ---- | --------------- |
| CONNECT | 0 | 连接。 |
| DISCONNECT | 1 | 断开。 |

## Result

旋转执行结果的枚举。

**系统能力**：SystemCapability.Mechanic.Core

**系统接口**：该接口为系统接口。

| 名称         | 值  | 说明              |
| ----------- | ---- | --------------- |
| COMPLETED | 0 | 执行完成。 |
| INTERRUPTED | 1 | 执行被打断。 |
| LIMITED | 2 | 执行受最大旋转角度限制。 |
| TIMEOUT | 3 | 执行超时。 |
| SYSTEM_ERROR | 100 | 系统错误。 |
