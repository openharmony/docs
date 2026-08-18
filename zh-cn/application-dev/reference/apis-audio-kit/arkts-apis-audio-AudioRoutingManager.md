# Interface (AudioRoutingManager)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

AudioRoutingManager是音频系统中的设备路由管理模块。本模块提供音频设备路由管理能力，包括音频设备列表获取、设备连接状态变化监听、优先级设备获取等。当开发者需要在媒体录制、媒体播放等场景下进行音频设备路由选择时，使用本模块接口完成相关操作。

在使用AudioRoutingManager的接口之前，需先通过[getRoutingManager](arkts-apis-audio-AudioManager.md#getroutingmanager9)获取AudioRoutingManager实例。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 9开始支持。

## 导入模块

```ts
import { audio } from '@kit.AudioKit';
```

## getDevices<sup>9+</sup>

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

获取音频设备列表。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| ---------- | ------------------------------------------------------------ | ---- | -------------------- |
| deviceFlag | [DeviceFlag](arkts-apis-audio-e.md#deviceflag)                                    | 是   | 音频设备类型。     |
| callback   | AsyncCallback&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt; | 是   | 回调函数。当获取音频设备列表成功，err为undefined，data为获取到的音频设备列表；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err: BusinessError, audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`Failed to obtain the device list. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in obtaining the device list, deviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
});
```

## getDevices<sup>9+</sup>

getDevices(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;

获取音频设备列表。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| deviceFlag | [DeviceFlag](arkts-apis-audio-e.md#deviceflag) | 是   | 音频设备类型。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| Promise&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt; | Promise对象，返回音频设备列表。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Succeeded in obtaining the device list, deviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the device list. Code: ${err.code}, message: ${err.message}`);
});
```

## getDevicesSync<sup>10+</sup>

getDevicesSync(deviceFlag: DeviceFlag): AudioDeviceDescriptors

获取音频设备列表。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| deviceFlag | [DeviceFlag](arkts-apis-audio-e.md#deviceflag) | 是   | 音频设备类型。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | 返回音频设备列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioDeviceDescriptors = audioRoutingManager.getDevicesSync(audio.DeviceFlag.OUTPUT_DEVICES_FLAG);
  console.info(`Succeeded in obtaining the device list, deviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the device list. Code: ${error.code}, message: ${error.message}`);
}
```

## isMicBlockDetectionSupported<sup>13+</sup>

isMicBlockDetectionSupported(): Promise&lt;boolean&gt;

获取当前设备是否支持麦克风状态检测。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示支持；返回false表示不支持。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.isMicBlockDetectionSupported().then((value: boolean) => {
  console.info(`Succeeded in querying whether microphone block detection is supported, isSupported: ${value}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query whether microphone block detection is supported. Code: ${err.code}, message: ${err.message}`);
});
```

## on('micBlockStatusChanged')<sup>13+</sup>

on(type: 'micBlockStatusChanged', callback: Callback<DeviceBlockStatusInfo\>): void

监听麦克风堵塞状态变化事件。使用callback异步回调。

使用此功能前，请使用[isMicBlockDetectionSupported](#ismicblockdetectionsupported13)查询设备是否支持检测。应用在使用麦克风录音时，若麦克风堵塞状态发生变化，将触发该事件。目前此检测功能仅支持麦克风位于本地设备上。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | 是   | 事件回调类型，支持的事件为'micBlockStatusChanged'，当麦克风堵塞状态发生变化时，触发该事件。 |
| callback | Callback<[DeviceBlockStatusInfo](arkts-apis-audio-i.md#deviceblockstatusinfo13)\> | 是   | 回调函数，返回麦克风被堵塞状态和设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 在使用此功能之前，应先查询当前设备是否支持检测。
audioRoutingManager.isMicBlockDetectionSupported().then((value: boolean) => {
  console.info(`Succeeded in querying whether microphone block detection is supported, isSupported: ${value}.`);
  if (value) {
    audioRoutingManager.on('micBlockStatusChanged', (deviceBlockStatusInfo: audio.DeviceBlockStatusInfo) => {
      console.info(`MicBlockStatus changed, deviceBlockStatusInfo: ${JSON.stringify(deviceBlockStatusInfo)}.`);
    });
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to query whether microphone block detection is supported. Code: ${err.code}, message: ${err.message}`);
});
```

## off('micBlockStatusChanged')<sup>13+</sup>

off(type: 'micBlockStatusChanged', callback?: Callback<DeviceBlockStatusInfo\>): void

取消监听麦克风堵塞状态变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | 是   | 事件回调类型，支持的事件为'micBlockStatusChanged'。 |
| callback | Callback<[DeviceBlockStatusInfo](arkts-apis-audio-i.md#deviceblockstatusinfo13)\> | 否   | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('micBlockStatusChanged')](#onmicblockstatuschanged13)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRoutingManager.off('micBlockStatusChanged');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let micBlockStatusCallback = (deviceBlockStatusInfo: audio.DeviceBlockStatusInfo) => {
  console.info(`MicBlockStatus changed, deviceBlockStatusInfo: ${JSON.stringify(deviceBlockStatusInfo)}.`);
};

audioRoutingManager.on('micBlockStatusChanged', micBlockStatusCallback);

audioRoutingManager.off('micBlockStatusChanged', micBlockStatusCallback);
```

## on('deviceChange')<sup>9+</sup>

on(type: 'deviceChange', deviceFlag: DeviceFlag, callback: Callback<DeviceChangeAction\>): void

监听音频设备连接状态变化事件（当音频设备连接状态发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                      |
| :------- | :--------------------------------------------------- | :--- |:------------------------|
| type     | string                                               | 是   | 事件回调类型，支持的事件为'deviceChange'，当音频设备连接状态发生变化时，触发该事件。 |
| deviceFlag | [DeviceFlag](arkts-apis-audio-e.md#deviceflag)                                    | 是   | 音频设备类型。              |
| callback | Callback<[DeviceChangeAction](arkts-apis-audio-i.md#devicechangeaction)\> | 是   | 回调函数，返回设备更新详情。          |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioRoutingManager.on('deviceChange', audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (deviceChangeAction: audio.DeviceChangeAction) => {
  console.info(`Device changed, deviceChangeAction: ${JSON.stringify(deviceChangeAction)}.`);
});
```

## off('deviceChange')<sup>9+</sup>

off(type: 'deviceChange', callback?: Callback<DeviceChangeAction\>): void

取消监听音频设备连接状态变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | 是   | 事件回调类型，支持的事件为'deviceChange'。 |
| callback | Callback<[DeviceChangeAction](arkts-apis-audio-i.md#devicechangeaction)> | 否   | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('deviceChange')](#ondevicechange9)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRoutingManager.off('deviceChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let deviceChangeCallback = (deviceChangeAction: audio.DeviceChangeAction) => {
  console.info(`Device changed, deviceChangeAction: ${JSON.stringify(deviceChangeAction)}.`);
};

audioRoutingManager.on('deviceChange', audio.DeviceFlag.OUTPUT_DEVICES_FLAG, deviceChangeCallback);

audioRoutingManager.off('deviceChange', deviceChangeCallback);
```

## setCommunicationDevice<sup>9+</sup>

setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean, callback: AsyncCallback&lt;void&gt;): void

设置通信设备激活状态。使用callback异步回调。

该接口由于功能设计变化，将在后续版本废弃，不建议开发者使用。

推荐使用AVSession提供的[设备切换组件](../../media/avsession/using-switch-call-devices.md)，实现通话设备切换。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                      |
| ---------- | ------------------------------------- | ---- |-------------------------|
| deviceType | [CommunicationDeviceType](arkts-apis-audio-e.md#communicationdevicetype9) | 是   | 音频设备类型。                 |
| active     | boolean                               | 是   | 是否设置设备为激活状态。true表示激活，false表示未激活。 |
| callback   | AsyncCallback&lt;void&gt;             | 是   | 回调函数。当设置通信设备激活状态成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.setCommunicationDevice(audio.CommunicationDeviceType.SPEAKER, true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set the active status of the communication device. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the active status of the communication device.');
});
```

## getAvailableDevices<sup>12+</sup>

getAvailableDevices(deviceUsage: DeviceUsage): AudioDeviceDescriptors

获取音频可选设备列表。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名     | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| deviceUsage| [DeviceUsage](arkts-apis-audio-e.md#deviceusage12) | 是   | 音频设备类型（根据用途分类）。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | 返回音频可选设备列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let data: audio.AudioDeviceDescriptors = audioRoutingManager.getAvailableDevices(audio.DeviceUsage.MEDIA_OUTPUT_DEVICES);
  console.info(`Succeeded in obtaining available devices, audioDeviceDescriptors: ${JSON.stringify(data)}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain available devices. Code: ${error.code}, message: ${error.message}`);
}
```

## on('availableDeviceChange')<sup>12+</sup>

on(type: 'availableDeviceChange', deviceUsage: DeviceUsage, callback: Callback<DeviceChangeAction\>): void

监听音频可选设备连接状态变化事件（当音频可选设备连接状态发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string                                               | 是   | 事件回调类型，支持的事件为'availableDeviceChange'，当音频可选设备连接状态发生变化时，触发该事件。 |
| deviceUsage | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)                       | 是   | 音频设备类型（根据用途分类）。     |
| callback | Callback<[DeviceChangeAction](arkts-apis-audio-i.md#devicechangeaction)\> | 是   | 回调函数，返回设备更新详情。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioRoutingManager.on('availableDeviceChange', audio.DeviceUsage.MEDIA_OUTPUT_DEVICES, (deviceChangeAction: audio.DeviceChangeAction) => {
  console.info(`Available device changed, deviceChangeAction: ${JSON.stringify(deviceChangeAction)}.`);
});
```

## off('availableDeviceChange')<sup>12+</sup>

off(type: 'availableDeviceChange', callback?: Callback<DeviceChangeAction\>): void

取消监听音频可选设备连接状态变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                              | 是   | 事件回调类型，支持的事件为'availableDeviceChange'。 |
| callback | Callback<[DeviceChangeAction](arkts-apis-audio-i.md#devicechangeaction)> | 否   | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('availableDeviceChange')](#onavailabledevicechange12)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRoutingManager.off('availableDeviceChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let availableDeviceChangeCallback = (deviceChangeAction: audio.DeviceChangeAction) => {
  console.info(`Available device changed, deviceChangeAction: ${JSON.stringify(deviceChangeAction)}.`);
};

audioRoutingManager.on('availableDeviceChange', audio.DeviceUsage.MEDIA_OUTPUT_DEVICES, availableDeviceChangeCallback);

audioRoutingManager.off('availableDeviceChange', availableDeviceChangeCallback);
```

## setCommunicationDevice<sup>9+</sup>

setCommunicationDevice(deviceType: CommunicationDeviceType, active: boolean): Promise&lt;void&gt;

设置通信设备激活状态。使用Promise异步回调。

该接口由于功能设计变化，将在后续版本废弃，不建议开发者使用。

推荐开发者使用AVSession提供的[设备切换组件](../../media/avsession/using-switch-call-devices.md)，实现通话设备切换。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名     | 类型                                                   | 必填 | 说明               |
| ---------- | ----------------------------------------------------- | ---- | ------------------ |
| deviceType | [CommunicationDeviceType](arkts-apis-audio-e.md#communicationdevicetype9)  | 是   | 活跃音频设备类型。 |
| active     | boolean                                               | 是   | 是否设置设备为激活状态。true表示激活，false表示未激活。     |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.setCommunicationDevice(audio.CommunicationDeviceType.SPEAKER, true).then(() => {
  console.info('Succeeded in setting the active status of the communication device.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the active status of the communication device. Code: ${err.code}, message: ${err.message}`);
});
```

## isCommunicationDeviceActive<sup>9+</sup>

isCommunicationDeviceActive(deviceType: CommunicationDeviceType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定通信设备的激活状态。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名     | 类型                                                  | 必填 | 说明                     |
| ---------- | ---------------------------------------------------- | ---- | ------------------------ |
| deviceType | [CommunicationDeviceType](arkts-apis-audio-e.md#communicationdevicetype9) | 是   | 通信设备类型。 |
| callback   | AsyncCallback&lt;boolean&gt;                         | 是   | 回调函数。当获取指定通信设备的激活状态成功，err为undefined，data为true表示激活，false表示未激活；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.isCommunicationDeviceActive(audio.CommunicationDeviceType.SPEAKER, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to check whether the communication device is active. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in checking whether the communication device is active, isActive: ${value}.`);
});
```

## isCommunicationDeviceActive<sup>9+</sup>

isCommunicationDeviceActive(deviceType: CommunicationDeviceType): Promise&lt;boolean&gt;

获取指定通信设备的激活状态。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名     | 类型                                                  | 必填 | 说明               |
| ---------- | ---------------------------------------------------- | ---- | ------------------ |
| deviceType | [CommunicationDeviceType](arkts-apis-audio-e.md#communicationdevicetype9) | 是   | 活跃音频设备类型。 |

**返回值：**

| 类型                   | 说明                             |
| ---------------------- | ------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示设备已激活；返回false表示设备未激活。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRoutingManager.isCommunicationDeviceActive(audio.CommunicationDeviceType.SPEAKER).then((value: boolean) => {
  console.info(`Succeeded in checking whether the communication device is active, isActive: ${value}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether the communication device is active. Code: ${err.code}, message: ${err.message}`);
});
```

## isCommunicationDeviceActiveSync<sup>10+</sup>

isCommunicationDeviceActiveSync(deviceType: CommunicationDeviceType): boolean

获取指定通信设备的激活状态。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Communication

**参数：**

| 参数名     | 类型                                                  | 必填 | 说明               |
| ---------- | ---------------------------------------------------- | ---- | ------------------ |
| deviceType | [CommunicationDeviceType](arkts-apis-audio-e.md#communicationdevicetype9) | 是   | 活跃音频设备类型。 |

**返回值：**

| 类型                   | 说明                             |
| ---------------------- | ------------------------------- |
| boolean | 设备是否处于激活状态。true表示处于激活状态，false表示处于未激活状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: boolean = audioRoutingManager.isCommunicationDeviceActiveSync(audio.CommunicationDeviceType.SPEAKER);
  console.info(`Succeeded in checking whether the communication device is active, isActive: ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to check whether the communication device is active. Code: ${error.code}, message: ${error.message}`);
}
```

## getPreferOutputDeviceForRendererInfo<sup>10+</sup>

getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

根据音频信息，返回优先级最高的输出设备。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| rendererInfo                | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)                     | 是   | 音频渲染器信息。             |
| callback                    | AsyncCallback&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt;  | 是   | 回调函数。当获取优先级最高的输出设备成功，err为undefined，data为获取到的优先级最高的输出设备信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息                                           |
| ------- |--------------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback. |
| 6800301 | System error. Return by callback.                |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
  rendererFlags: 0 // 音频渲染器标志。
};

audioRoutingManager.getPreferOutputDeviceForRendererInfo(rendererInfo, (err: BusinessError, audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`Failed to obtain the preferred output device for renderer info. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in obtaining the preferred output device for renderer info, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
});
```

## getPreferOutputDeviceForRendererInfo<sup>10+</sup>
getPreferOutputDeviceForRendererInfo(rendererInfo: AudioRendererInfo): Promise&lt;AudioDeviceDescriptors&gt;

根据音频信息，返回优先级最高的输出设备。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| rendererInfo          | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)                     | 是   | 音频渲染器信息。            |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt;   | Promise对象，返回优先级最高的输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息                                          |
| ------- |-------------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |
| 6800301 | System error. Return by promise.                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
  rendererFlags: 0 // 音频渲染器标志。
};

audioRoutingManager.getPreferOutputDeviceForRendererInfo(rendererInfo).then((audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Succeeded in obtaining the preferred output device for renderer info, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the preferred output device for renderer info. Code: ${err.code}, message: ${err.message}`);
});
```

## getPreferredOutputDeviceForRendererInfoSync<sup>10+</sup>
getPreferredOutputDeviceForRendererInfoSync(rendererInfo: AudioRendererInfo): AudioDeviceDescriptors

根据音频信息，返回优先级最高的输出设备。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| rendererInfo          | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)                     | 是   | 音频渲染器信息。            |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)   | 返回优先级最高的输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息                     |
| ------- |--------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
  rendererFlags: 0 // 音频渲染器标志。
};

try {
  let audioDeviceDescriptors = audioRoutingManager.getPreferredOutputDeviceForRendererInfoSync(rendererInfo);
  console.info(`Succeeded in obtaining the preferred output device for renderer info, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the preferred output device for renderer info. Code: ${error.code}, message: ${error.message}`);
}
```

## on('preferOutputDeviceChangeForRendererInfo')<sup>10+</sup>

on(type: 'preferOutputDeviceChangeForRendererInfo', rendererInfo: AudioRendererInfo, callback: Callback<AudioDeviceDescriptors\>): void

监听最高优先级输出设备变化事件（当最高优先级输出设备发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                      |
| :------- | :--------------------------------------------------- | :--- |:--------------------------------------------------------|
| type     | string | 是   | 事件回调类型，支持的事件为'preferOutputDeviceChangeForRendererInfo'，当最高优先级输出设备发生变化时，触发该事件。|
| rendererInfo  | [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)        | 是   | 音频渲染器信息。                                                |
| callback | Callback<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)\> | 是   | 回调函数，返回优先级最高的输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
let rendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
  rendererFlags: 0 // 音频渲染器标志。
};

audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', rendererInfo, (audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Preferred output device changed, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
});
```

## off('preferOutputDeviceChangeForRendererInfo')<sup>10+</sup>

off(type: 'preferOutputDeviceChangeForRendererInfo', callback?: Callback<AudioDeviceDescriptors\>): void

取消监听最高优先级输出音频设备变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'preferOutputDeviceChangeForRendererInfo'。 |
| callback | Callback<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | 否   | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('preferOutputDeviceChangeForRendererInfo')](#onpreferoutputdevicechangeforrendererinfo10)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
// 当订阅了多个该事件的监听时，可通过 audioRoutingManager.off('preferOutputDeviceChangeForRendererInfo'); 取消该事件的所有监听。
let preferOutputDeviceChangeForRendererInfoCallback = (audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Preferred output device changed, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
};
let rendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
  rendererFlags: 0 // 音频渲染器标志。
};

audioRoutingManager.on('preferOutputDeviceChangeForRendererInfo', rendererInfo, preferOutputDeviceChangeForRendererInfoCallback);

audioRoutingManager.off('preferOutputDeviceChangeForRendererInfo', preferOutputDeviceChangeForRendererInfoCallback);
```

## getPreferredInputDeviceForCapturerInfo<sup>10+</sup>

getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

根据音频信息，返回优先级最高的输入设备。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| capturerInfo                | [AudioCapturerInfo](arkts-apis-audio-i.md#audiocapturerinfo8)                     | 是   | 音频采集器信息。             |
| callback                    | AsyncCallback&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt;  | 是   | 回调函数。当获取优先级最高的输入设备成功，err为undefined，data为获取到的优先级最高的输入设备信息；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.|
| 6800301 | System error. Return by callback. |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型：Mic音频源。根据业务场景配置，参考SourceType。
  capturerFlags: 0 // 音频采集器标志。
};

audioRoutingManager.getPreferredInputDeviceForCapturerInfo(capturerInfo, (err: BusinessError, audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`Failed to obtain the preferred input device for capturer info. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in obtaining the preferred input device for capturer info, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
});
```

## getPreferredInputDeviceForCapturerInfo<sup>10+</sup>

getPreferredInputDeviceForCapturerInfo(capturerInfo: AudioCapturerInfo): Promise&lt;AudioDeviceDescriptors&gt;

根据音频信息，返回优先级最高的输入设备。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| capturerInfo          | [AudioCapturerInfo](arkts-apis-audio-i.md#audiocapturerinfo8)                     | 是   | 音频采集器信息。            |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| Promise&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt;   | Promise对象，返回优先级最高的输入设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |
| 6800301 | System error. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型：Mic音频源。根据业务场景配置，参考SourceType。
  capturerFlags: 0 // 音频采集器标志。
};

audioRoutingManager.getPreferredInputDeviceForCapturerInfo(capturerInfo).then((audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Succeeded in obtaining the preferred input device for capturer info, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the preferred input device for capturer info. Code: ${err.code}, message: ${err.message}`);
});
```

## getPreferredInputDeviceForCapturerInfoSync<sup>10+</sup>

getPreferredInputDeviceForCapturerInfoSync(capturerInfo: AudioCapturerInfo): AudioDeviceDescriptors

根据音频信息，返回优先级最高的输入设备。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                 | 类型                                                         | 必填 | 说明                      |
| ----------------------| ------------------------------------------------------------ | ---- | ------------------------- |
| capturerInfo          | [AudioCapturerInfo](arkts-apis-audio-i.md#audiocapturerinfo8)                     | 是   | 音频采集器信息。            |

**返回值：**

| 类型                  | 说明                         |
| --------------------- | --------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)   | 返回优先级最高的输入设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型：Mic音频源。根据业务场景配置，参考SourceType。
  capturerFlags: 0 // 音频采集器标志。
};

try {
  let audioDeviceDescriptors = audioRoutingManager.getPreferredInputDeviceForCapturerInfoSync(capturerInfo);
  console.info(`Succeeded in obtaining the preferred input device for capturer info, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the preferred input device for capturer info. Code: ${error.code}, message: ${error.message}`);
}
```

## on('preferredInputDeviceChangeForCapturerInfo')<sup>10+</sup>

on(type: 'preferredInputDeviceChangeForCapturerInfo', capturerInfo: AudioCapturerInfo, callback: Callback<AudioDeviceDescriptors\>): void

监听最高优先级输入设备变化事件（当最高优先级输入设备发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string | 是   | 事件回调类型，支持的事件为'preferredInputDeviceChangeForCapturerInfo'，当最高优先级输入设备发生变化时，触发该事件。 |
| capturerInfo  | [AudioCapturerInfo](arkts-apis-audio-i.md#audiocapturerinfo8)        | 是   | 音频采集器信息。              |
| callback | Callback<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)\> | 是   | 回调函数，返回优先级最高的输入设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型：Mic音频源。根据业务场景配置，参考SourceType。
  capturerFlags: 0 // 音频采集器标志。
};

audioRoutingManager.on('preferredInputDeviceChangeForCapturerInfo', capturerInfo, (audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Preferred input device changed, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
});
```

## off('preferredInputDeviceChangeForCapturerInfo')<sup>10+</sup>

off(type: 'preferredInputDeviceChangeForCapturerInfo', callback?: Callback<AudioDeviceDescriptors\>): void

取消监听最高优先级输入音频设备变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'preferredInputDeviceChangeForCapturerInfo'。 |
| callback | Callback<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | 否   | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('preferredInputDeviceChangeForCapturerInfo')](#onpreferredinputdevicechangeforcapturerinfo10)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
// 当订阅了多个该事件的监听时，可通过 audioRoutingManager.off('preferredInputDeviceChangeForCapturerInfo'); 取消该事件的所有监听。
let preferredInputDeviceChangeForCapturerInfoCallback = (audioDeviceDescriptors: audio.AudioDeviceDescriptors) => {
  console.info(`Preferred input device changed, audioDeviceDescriptors: ${JSON.stringify(audioDeviceDescriptors)}.`);
};
let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型：Mic音频源。根据业务场景配置，参考SourceType。
  capturerFlags: 0 // 音频采集器标志。
};

audioRoutingManager.on('preferredInputDeviceChangeForCapturerInfo', capturerInfo, preferredInputDeviceChangeForCapturerInfoCallback);

audioRoutingManager.off('preferredInputDeviceChangeForCapturerInfo', preferredInputDeviceChangeForCapturerInfoCallback);
```

## declareDeviceTypesCompatibility

declareDeviceTypesCompatibility(deviceTypes: DeviceTypeArray): void

声明应用需要兼容的设备类型。

> **说明：**
>
> 对于API version 20及以上版本新增的设备类型，应用调用获取设备的相关接口时（例如[getAvailableDevices](arkts-apis-audio-AudioSessionManager.md#getavailabledevices21)），默认返回的设备类型为匿名类型。如需获取具体设备类型，需先调用该方法进行设备类型兼容声明。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名                       | 类型                                                         | 必填 | 说明                      |
| --------------------------- | ------------------------------------------------------------ | ---- | ------------------------- |
| deviceTypes | [DeviceTypeArray](arkts-apis-audio-t.md#devicetypearray) | 是   | [DeviceType](arkts-apis-audio-e.md#devicetype)数组。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed, the param deviceTypes contains value that is invalid enum or is not device type introduced in API 20 onwards. |

**示例：**

```ts
let deviceTypes = [
  audio.DeviceType.NEARLINK
];

audioRoutingManager.declareDeviceTypesCompatibility(deviceTypes);
```