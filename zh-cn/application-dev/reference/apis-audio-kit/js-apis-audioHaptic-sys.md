# @ohos.multimedia.audioHaptic (音振协同)(系统接口)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

音振协同，表示在播放声音时，同步发起振动。可用于来电通知、消息提醒等场景。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { audioHaptic } from '@kit.AudioKit';
```

## AudioHapticPlayer

音振播放器，提供音振协同播放功能。在调用AudioHapticPlayer的接口前，需要先通过[createPlayer](./js-apis-audioHaptic.md#createplayer)创建实例。

### isHapticsIntensityAdjustmentSupported<sup>20+</sup>

isHapticsIntensityAdjustmentSupported(): boolean

查询设备是否可以调整振动幅度。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| boolean             | 设备是否可以调整振动幅度。true表示可以调整振动幅度，false表示不可以调整振动幅度。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息                              |
|---------|-----------------------------------|
| 202 | Caller is not a system application. |

**示例：**

```ts
const result: boolean = audioHapticPlayerInstance.isHapticsIntensityAdjustmentSupported();
```

### isHapticsRampSupported<sup>20+</sup>

isHapticsRampSupported(): boolean

查询设备是否可以设置振动渐变。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| boolean             | 设备是否可以设置振动渐变。true表示设备可以设置振动渐变，false表示设备不可以设置振动渐变。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID   | 错误信息                              |
|---------|-----------------------------------|
| 202 | Caller is not a system application. |

**示例：**

```ts
const result: boolean = audioHapticPlayerInstance.isHapticsRampSupported();
```

### enableHapticsInSilentMode<sup>20+</sup>

enableHapticsInSilentMode(enable: boolean): void

静音模式下，音振播放器可以振动。

> **注意：**
>
> 该方法必须在释放音振播放器前使用，不能在播放中调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数**

| 参数名  | 类型                                     | 必填| 说明                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| enable     | boolean                                | 是  | 是否在静音模式下开启振动。true表示在静音模式下开启振动，false表示在静音模式下不开启振动。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID  | 错误信息                             |
|---------|-----------------------------------|
| 202      | Caller is not a system application. |
| 5400102  | Operate not permit in current state. |

**示例：**

```ts
audioHapticPlayerInstance.enableHapticsInSilentMode(true);
```

### setHapticsIntensity<sup>20+</sup>

setHapticsIntensity(intensity: number): Promise&lt;void&gt;

设置音振播放器的振幅。使用Promise异步回调。

> **注意：**
>
>该方法需在音振播放器释放前调用，且单次播放过程中仅调用一次。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数**

| 参数名  | 类型                                     | 必填| 说明                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| intensity     | number                              | 是  | 取值范围为[0.00, 1.00]，其中1.00表示最大振幅（100%）。|

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&amp;lt;void&amp;gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息                              |
|---------|-----------------------------------|
| 202      | Caller is not a system application. |
| 801      | Function is not supported in current device. |
| 5400102  | Operate not permit in current state. |
| 5400108  | Parameter out of range. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioHapticPlayerInstance.setHapticsIntensity(0.5).then(() => {
  console.info('Promise returned to indicate that set intensity successfully.');
}).catch ((err: BusinessError) => {
  console.error(`Failed to set intensity. ${err}`);
});
```

### setHapticsRamp<sup>20+</sup>

setHapticsRamp(duration: number, startIntensity: number, endIntensity: number): Promise&lt;void&gt;

设置音振播放器渐变播放。使用Promise异步回调。

> **注意：**
>
>- 该方法需在音振协同播放器播放前后和销毁前使用。
>- 该方法仅能调用一次。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数**

| 参数名  | 类型                                     | 必填| 说明                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| duration | number                           | 是  | 渐变时间段，单位为毫秒（ms），值必须为整数，且不能小于100ms。 |
| startIntensity | number                     | 是  | 起始振动幅度，取值范围为[0.00, 1.00]，其中1.00表示最大振幅（100%）。|
| endIntensity   | number                     | 是  | 结束振动幅度，取值范围为[0.00, 1.00]，其中1.00表示最大振幅（100%）。|

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&amp;lt;void&amp;gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息                              |
|---------|-----------------------------------|
| 202      | Caller is not a system application. |
| 801      | Function is not supported in current device. |
| 5400102  | Operate not permit in current state. |
| 5400108  | Parameter out of range. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const duration = 10000;
const startIntensity = 0.5;
const endIntensity = 1;

audioHapticPlayerInstance.setHapticsRamp(duration, startIntensity, endIntensity).then(() => {
  console.info('Promise returned to indicate that set haptics ramp successfully.');
}).catch ((err: BusinessError) => {
  console.error(`Failed to set haptics ramp. ${err}`);
});
```