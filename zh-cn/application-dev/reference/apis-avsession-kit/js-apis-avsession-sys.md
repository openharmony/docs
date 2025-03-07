# @ohos.multimedia.avsession (媒体会话管理)(系统接口)

媒体会话管理提供媒体播控相关功能的接口，目的是让应用接入播控中心。

该模块提供以下媒体会话相关的常用功能：

- [AVCastController](#avcastcontroller10): 投播控制器，可用于投播场景下，完成播放控制、远端播放状态监听、远端播放状态信息获取等操作。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.avsession (媒体会话管理)](js-apis-avsession.md)。

## 导入模块

```ts
import { avSession } from '@kit.AVSessionKit';
```

## 使用说明

本文档仅提供系统接口说明，以下接口的使用说明均需先创建实例，请参考公开接口[avSession.createAVSession](js-apis-avsession.md#avsessioncreateavsession10)的说明及示例，创建对应实例。

## avSession.getAllSessionDescriptors

getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

获取所有设置过媒体信息且注册控制回调的会话的相关描述。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise\<Array\<Readonly\<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Promise对象。返回所有会话描述的只读对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getAllSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`getAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
  if (descriptors.length > 0 ) {
    console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
  }
}).catch((err: BusinessError) => {
  console.error(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.getAllSessionDescriptors

getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void

获取所有设置过媒体信息且注册控制回调的会话的相关描述。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | 是   | 回调函数。返回所有会话描述的只读对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 6600101  |Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getAllSessionDescriptors((err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {
  if (err) {
    console.error(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if (descriptors.length > 0 ) {
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
    }
  }
});
```

## avSession.getHistoricalSessionDescriptors<sup>10+</sup>

getHistoricalSessionDescriptors(maxSize?: number): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

获取所有已被销毁的会话相关描述。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                             |
| -------- | ------ | ---- | -----------------------------------------------------------------|
| maxSize  | number | 否   | 指定获取描述符数量的最大值，可选范围是0-10，不填则取默认值，默认值为3。|

**返回值：**

| 类型                                                                        | 说明                                   |
| --------------------------------------------------------------------------- | -------------------------------------- |
| Promise\<Array\<Readonly\<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Promise对象。返回所有会话描述的只读对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getHistoricalSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
  if (descriptors.length > 0 ) {
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionId : ${descriptors[0].sessionId}`);
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].elementName.bundleName : ${descriptors[0].elementName.bundleName}`);
  }
}).catch((err: BusinessError) => {
  console.error(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.getHistoricalSessionDescriptors<sup>10+</sup>

getHistoricalSessionDescriptors(maxSize: number, callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void

获取所有已被销毁的会话相关描述。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                                            | 必填 | 说明                                                             |
| -------- | ------------------------------------------------------------------------------ | ---- | -----------------------------------------------------------------|
| maxSize  | number                                                                         | 是  | 指定获取描述符数量的最大值，可选范围是0-10。|
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | 是   | 回调函数。返回所有会话描述的只读对象。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  |Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getHistoricalSessionDescriptors(1, (err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {
  if (err) {
    console.error(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if (descriptors.length > 0 ) {
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].sessionId : ${descriptors[0].sessionId}`);
      console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors[0].elementName.bundleName : ${descriptors[0].elementName.bundleName}`);
    }
  }
});
```

## avSession.getHistoricalAVQueueInfos<sup>11+</sup>

getHistoricalAVQueueInfos(maxSize: number, maxAppSize: number) : Promise\<Array\<Readonly\<AVQueueInfo>>>

获取全部的历史播放歌单。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                             |
| -------- | ------ | ---- | ---------------------------------------------------------------|
| maxSize  | number | 是   | 指定获取歌曲列表数量的最大值，暂与获取歌单数量无关。                     |
| maxAppSize | number | 是   | 指定获取歌曲列表所属应用数量的最大值，暂与获取歌单数量无关。             |

**返回值：**

| 类型                                                                        | 说明                                   |
| --------------------------------------------------------------------------- | ------------------------------------- |
| Promise\<Array\<Readonly\<[AVQueueInfo](#avqueueinfo11)\>\>\> | Promise对象。返回所有历史播放歌单的只读对象。                |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getHistoricalAVQueueInfos(3, 5).then((avQueueInfos: avSession.AVQueueInfo[]) => {
  console.info(`getHistoricalAVQueueInfos : SUCCESS : avQueueInfos.length : ${avQueueInfos.length}`);
}).catch((err: BusinessError) => {
  console.error(`getHistoricalAVQueueInfos BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.getHistoricalAVQueueInfos<sup>11+</sup>

getHistoricalAVQueueInfos(maxSize: number, maxAppSize: number, callback: AsyncCallback\<Array\<Readonly\<AVQueueInfo>>>): void;

获取全部的历史播放歌单。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                                            | 必填 | 说明                                                             |
| -------- | ----------------------------------------------------------------------------- | ---- | ---------------------------------------------------------------|
| maxSize  | number                                                                        | 是   | 指定获取歌曲列表数量的最大值，暂与获取歌单数量无关。                      |
| maxAppSize | number                                                                      | 是   | 指定获取歌曲列表所属应用数量的最大值，暂与获取歌单数量无关。               |
| callback | AsyncCallback<Array<Readonly<[AVQueueInfo](#avqueueinfo11)\>\>\> | 是   | 回调函数。返回所有历史播放歌单的只读对象。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  |Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getHistoricalAVQueueInfos(3, 5, (err: BusinessError, avQueueInfos: avSession.AVQueueInfo[]) => {
  if (err) {
    console.error(`getHistoricalAVQueueInfos BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getHistoricalAVQueueInfos : SUCCESS : avQueueInfos.length : ${avQueueInfos.length}`);
  }
});
```

## avSession.createController

createController(sessionId: string): Promise\<AVSessionController>

根据会话ID创建会话控制器，可以创建多个会话控制器。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | -------- |
| sessionId | string | 是   | 会话ID，如果提供 'default'，系统将创建一个默认控制器，用于控制系统默认会话。 |

**返回值：**

| 类型                                                  | 说明                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSessionController](js-apis-avsession.md#avsessioncontroller10)\> | Promise对象。返回会话控制器实例，可查看会话ID，<br>并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVcontroller: avSession.AVSessionController | undefined = undefined;
currentAvSession.createController(sessionId).then((avcontroller: avSession.AVSessionController) => {
  currentAVcontroller = avcontroller;
  console.info('CreateController : SUCCESS ');
}).catch((err: BusinessError) => {
  console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.createController

createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void

根据会话ID创建会话控制器，可以创建多个会话控制器。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| sessionId | string                                                      | 是   | 会话ID，如果提供 'default'，系统将创建一个默认控制器，用于控制系统默认会话。                                                     |
| callback  | AsyncCallback<[AVSessionController](js-apis-avsession.md#avsessioncontroller10)\> | 是   | 回调函数。返回会话控制器实例，可查看会话ID，<br>并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVcontroller: avSession.AVSessionController | undefined = undefined;
currentAvSession.createController(sessionId, (err: BusinessError, avcontroller: avSession.AVSessionController) => {
  if (err) {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVcontroller = avcontroller;
    console.info('CreateController : SUCCESS ');
  }
});
```

## avSession.castAudio

castAudio(session: SessionToken | 'all', audioDevices: Array<audio.AudioDeviceDescriptor>): Promise\<void>

投播会话到指定设备列表。结果通过Promise异步回调方式返回。

调用此接口之前，需要导入`ohos.multimedia.audio`模块获取AudioDeviceDescriptor的相关描述。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名        | 类型           | 必填 | 说明 |
| ------------ | -------------- |------|------|
| session      | [SessionToken](#sessiontoken) &#124; 'all' | 是   | 会话令牌。SessionToken表示单个token；字符串`'all'`指所有token。 |
| audioDevices | Array\<[audio.AudioDeviceDescriptor](../apis-audio-kit/js-apis-audio.md#audiodevicedescriptor)\> | 是   | 媒体设备列表。  |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当投播成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err: BusinessError) => {
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

if (audioDevices !== undefined) {
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors).then(() => {
    console.info('CreateController : SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}
```

## avSession.castAudio

castAudio(session: SessionToken | 'all', audioDevices: Array<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void

投播会话到指定设备列表。结果通过callback异步回调方式返回。

需要导入`ohos.multimedia.audio`模块获取AudioDeviceDescriptor的相关描述。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名       | 类型                                         | 必填 | 说明                                                         |
| ------------ |--------------------------------------------| ---- | ------------------------------------------------------------ |
| session      | [SessionToken](#sessiontoken) &#124; 'all' | 是   | 会话令牌。SessionToken表示单个token；字符串`'all'`指所有token。 |
| audioDevices | Array\<[audio.AudioDeviceDescriptor](../apis-audio-kit/js-apis-audio.md#audiodevicedescriptor)\>   | 是   | 媒体设备列表。 |
| callback     | AsyncCallback\<void>     | 是   | 回调函数。当投播成功，err为undefined，否则返回错误对象。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err: BusinessError) => {
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

if (audioDevices !== undefined) {
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors, (err: BusinessError) => {
    if (err) {
      console.error(`CastAudio BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('CastAudio : SUCCESS ');
    }
  });
}
```

## avSession.startAVPlayback<sup>11+</sup>

startAVPlayback(bundleName: string, assetId: string): Promise\<void>

启动媒体播放应用程序。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名        | 类型           | 必填 | 说明 |
| ------------ | -------------- |------|------|
| bundleName   | string         | 是   | 指定应用包名 |
| assetId      |string           | 是   | 指定媒体ID  |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

avSession.startAVPlayback("com.example.myapplication", "121278").then(() => {
  console.info('startAVPlayback : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`startAVPlayback BusinessError: code: ${err.code}, message: ${err.message}`);
});
```
## avSession.getDistributedSessionController<sup>16+</sup>

getDistributedSessionController(distributedSessionType: DistributedSessionType): Promise<Array\<AVSessionController>>

根据远端会话类型，获取远端分布式会话控制器。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                                                                      | 必填 | 说明      |
| --------- |-------------------------------------------------------------------------| ---- |---------|
| distributedSessionType | [DistributedSessionType](js-apis-avsession.md#distributedsessiontype16) | 是   | 远端会话类型。 |

**返回值：**

| 类型                                                                                 | 说明                                                                    |
|------------------------------------------------------------------------------------|-----------------------------------------------------------------------|
| Promise<Array<[AVSessionController](js-apis-avsession.md#avsessioncontroller10)\>> | Promise对象。返回对应类型的会话控制器实例列表，可查看会话ID，并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID   | 错误信息                                                                                                  |
|---------|-------------------------------------------------------------------------------------------------------|
| 201     | permission denied.                                                                                    |
| 202     | Not System App. Interface caller is not a system app.                                                                                       |
| 401     | parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101 | Session service exception.                                                                            |
| 6600109 | The remote connection is not established.                                                             |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.getDistributedSessionController(avSession.DistributedSessionType.TYPE_SESSION_REMOTE).then((sessionControllers: Array<avSession.AVSessionController>) => {
  console.info(`getDistributedSessionController : SUCCESS : sessionControllers.length : ${sessionControllers.length}`);
}).catch((err: BusinessError) => {
  console.error(`getDistributedSessionController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```


## SessionToken

会话令牌的信息。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

| 名称      | 类型   | 必填 | 说明         |
| :-------- | :----- | :--- | :----------- |
| sessionId | string | 是   | 会话ID       |
| pid       | number | 否   | 会话的进程ID |
| uid       | number | 否   | 用户ID       |

## avSession.on('sessionCreate')

on(type: 'sessionCreate', callback: (session: AVSessionDescriptor) => void): void

会话的创建监听事件。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 事件回调类型，支持的事件是'sessionCreate'`：会话创建事件，检测到会话创建时触发。|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | 是   | 回调函数。参数为会话相关描述。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.on('sessionCreate', (descriptor: avSession.AVSessionDescriptor) => {
  console.info(`on sessionCreate : isActive : ${descriptor.isActive}`);
  console.info(`on sessionCreate : type : ${descriptor.type}`);
  console.info(`on sessionCreate : sessionTag : ${descriptor.sessionTag}`);
});

```

## avSession.on('sessionDestroy')

on(type: 'sessionDestroy', callback: (session: AVSessionDescriptor) => void): void

会话的销毁监听事件。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型            | 必填 | 说明                                                         |
| -------- | ---------------| ---- | ------------------------------------------------------------ |
| type     | string         | 是   | 事件回调类型，支持的事件包括是`'sessionDestroy'`：会话销毁事件，检测到会话销毁时触发。|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | 是   | 回调函数。参数为会话相关描述。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.on('sessionDestroy', (descriptor: avSession.AVSessionDescriptor) => {
  console.info(`on sessionDestroy : isActive : ${descriptor.isActive}`);
  console.info(`on sessionDestroy : type : ${descriptor.type}`);
  console.info(`on sessionDestroy : sessionTag : ${descriptor.sessionTag}`);
});
```

## avSession.on('topSessionChange')

on(type: 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void

最新会话变更的监听事件。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | --------------------| ---- | ------------------------------------------------------------ |
| type     | string      | 是   | 事件回调类型，支持的事件包括是 `'topSessionChange'`：最新会话的变化事件，检测到最新的会话改变时触发。|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | 是   | 回调函数。参数为会话相关描述。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.on('topSessionChange', (descriptor: avSession.AVSessionDescriptor) => {
  console.info(`on topSessionChange : isActive : ${descriptor.isActive}`);
  console.info(`on topSessionChange : type : ${descriptor.type}`);
  console.info(`on topSessionChange : sessionTag : ${descriptor.sessionTag}`);
});
```

## avSession.off('sessionCreate')

off(type: 'sessionCreate', callback?: (session: AVSessionDescriptor) => void): void

取消会话创建事件监听，取消后，不再进行该事件的监听。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型       | 必填 | 说明       |
| -------- | ----------| ---- | ----------|
| type     | string    | 是   | 事件回调类型，支持的事件为：`'sessionCreate'`。|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为会话相关描述，为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                               |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.off('sessionCreate');
```

## avSession.off('sessionDestroy')

off(type: 'sessionDestroy', callback?: (session: AVSessionDescriptor) => void): void

取消会话销毁事件监听，取消后，不再进行该事件的监听。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型        | 必填 | 说明                      |
| -------- | -----------| ---- | -------------------------|
| type     | string     | 是   | 事件回调类型，支持的事件为`'sessionDestroy'`。|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为会话相关描述，为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。|

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.off('sessionDestroy');
```

## avSession.off('topSessionChange')

off(type: 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void

取消最新会话变更事件监听，取消后，不再进行该事件的监听。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型              | 必填 | 说明                        |
| -------- | -----------------| ---- | ---------------------------- |
| type     | string           | 是   | 事件回调类型，支持的事件为`'topSessionChange'`。|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为会话相关描述，为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.off('topSessionChange');
```

## avSession.on('sessionServiceDie')

on(type: 'sessionServiceDie', callback: () => void): void

监听会话的服务死亡事件。通知应用清理资源。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持事件`'sessionServiceDie'`：会话服务死亡事件，检测到会话的服务死亡时触发。 |
| callback | callback: () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则返回错误对象。                                |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.on('sessionServiceDie', () => {
  console.info('on sessionServiceDie  : session is  Died ');
});
```

## avSession.off('sessionServiceDie')

off(type: 'sessionServiceDie', callback?: () => void): void

取消会话服务死亡监听，取消后，不再进行服务死亡监听。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                    | 必填  |      说明                                               |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | 是    | 事件回调类型，支持事件`'sessionServiceDie'`：会话服务死亡事件。|
| callback | callback: () => void   | 否    | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的服务死亡监听。            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.off('sessionServiceDie');
```


## avSession.on('distributedSessionChange')

on(type: 'distributedSessionChange', distributedSessionType: DistributedSessionType, callback: Callback<Array\<AVSessionController>>): void

最新分布式远端会话变更的监听事件。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                                                  | 必填 | 说明                                                                       |
| -------- |-------------------------------------------------------------------------------------| ---- |--------------------------------------------------------------------------|
| type     | string                                                                              | 是   | 事件回调类型，支持的事件为 `'distributedSessionChange'`：最新远端分布式会话的变化事件，检测到最新的会话改变时触发。 |
| distributedSessionType     | [DistributedSessionType](js-apis-avsession.md#distributedsessiontype16)             | 是   | 远端会话类型。                                                                  |
| callback | Callback<Array<[AVSessionController](js-apis-avsession.md#avsessioncontroller10)\>> | 是   | 回调函数。参数为对应类型的会话控制器实例列表，可查看会话ID，并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。            |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID   | 错误信息                                                                                              |
|---------|---------------------------------------------------------------------------------------------------|
| 202     | Not System App. Interface caller is not a system app.                                                                                   |
| 401     | parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101 | Session service exception.                                                                        |

**示例：**

```ts
avSession.on('distributedSessionChange', avSession.DistributedSessionType.TYPE_SESSION_REMOTE, (sessionControllers: Array<avSession.AVSessionController>) => {
  console.info(`on distributedSessionChange size: ${sessionControllers.length}`);
});
```


## avSession.off('distributedSessionChange')

off(type: 'distributedSessionChange', distributedSessionType: DistributedSessionType, callback?: Callback<Array\<AVSessionController>>): void

取消最新分布式远端会话变更的监听事件，取消后，不再进行该事件的监听。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                                                  | 必填 | 说明                                                            |
| -------- |-------------------------------------------------------------------------------------|----|---------------------------------------------------------------|
| type     | string                                                                              | 是  | 事件回调类型，支持的事件为`'distributedSessionChange'`。                    |
| distributedSessionType     | [DistributedSessionType](js-apis-avsession.md#distributedsessiontype16)             | 是  | 远端会话类型。                                                       |
| callback | Callback<Array<[AVSessionController](js-apis-avsession.md#avsessioncontroller10)\>> | 否  | 回调函数。参数为对应类型的会话控制器实例列表，可查看会话ID，并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID   | 错误信息                                                                                              |
|---------|---------------------------------------------------------------------------------------------------|
| 202     | Not System App. Interface caller is not a system app.                                                                                   |
| 401     | parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101 | Session service exception.                                                                        |

**示例：**

```ts
avSession.off('distributedSessionChange', avSession.DistributedSessionType.TYPE_SESSION_REMOTE);
```

## avSession.sendSystemAVKeyEvent

sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

发送按键事件给置顶会话。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                  |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------- |
| event    | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | 是   | 按键事件。                            |
| callback | AsyncCallback\<void>                                         | 是   | 回调函数。当事件发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**示例：**

```ts
import { KeyEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event, (err: BusinessError) => {
  if (err) {
    console.error(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('SendSystemAVKeyEvent : SUCCESS ');
  }
});
```

## avSession.sendSystemAVKeyEvent

sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>

发送按键事件给置顶会话。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名 | 类型                            | 必填 | 说明       |
| ------ | ------------------------------- | ---- | ---------- |
| event  | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | 是   | 按键事件。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当事件发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**示例：**

```ts
import { KeyEvent } from '@kit.InputKit';
import { BusinessError } from '@kit.BasicServicesKit';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event).then(() => {
  console.info('SendSystemAVKeyEvent Successfully');
}).catch((err: BusinessError) => {
  console.error(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.sendSystemControlCommand

sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

发送控制命令给置顶会话。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| command  | [AVControlCommand](js-apis-avsession.md#avcontrolcommand10) | 是   | AVSession的相关命令和命令相关参数。   |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
let cmd : avSession.AVControlCommandType = 'play';
// let cmd : avSession.AVControlCommandType = 'pause';
// let cmd : avSession.AVControlCommandType = 'stop';
// let cmd : avSession.AVControlCommandType = 'playNext';
// let cmd : avSession.AVControlCommandType = 'playPrevious';
// let cmd : avSession.AVControlCommandType = 'fastForward';
// let cmd : avSession.AVControlCommandType = 'rewind';
let avcommand: avSession.AVControlCommand = {command:cmd};
// let cmd : avSession.AVControlCommandType = 'seek';
// let avcommand = {command:cmd, parameter:10};
// let cmd : avSession.AVControlCommandType = 'setSpeed';
// let avcommand = {command:cmd, parameter:2.6};
// let cmd : avSession.AVControlCommandType = 'setLoopMode';
// let avcommand = {command:cmd, parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let cmd : avSession.AVControlCommandType = 'toggleFavorite';
// let avcommand = {command:cmd, parameter:"false"};
avSession.sendSystemControlCommand(avcommand, (err) => {
  if (err) {
    console.error(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('sendSystemControlCommand successfully');
  }
});
```

## avSession.sendSystemControlCommand

sendSystemControlCommand(command: AVControlCommand): Promise\<void>

发送控制命令给置顶会话。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名  | 类型                                  | 必填 | 说明                                |
| ------- | ------------------------------------- | ---- | ----------------------------------- |
| command | [AVControlCommand](js-apis-avsession.md#avcontrolcommand10) | 是   | AVSession的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let cmd : avSession.AVControlCommandType = 'play';
// let cmd : avSession.AVControlCommandType = 'pause';
// let cmd : avSession.AVControlCommandType = 'stop';
// let cmd : avSession.AVControlCommandType = 'playNext';
// let cmd : avSession.AVControlCommandType = 'playPrevious';
// let cmd : avSession.AVControlCommandType = 'fastForward';
// let cmd : avSession.AVControlCommandType = 'rewind';
let avcommand: avSession.AVControlCommand = {command:cmd};
// let cmd : avSession.AVControlCommandType = 'seek';
// let avcommand = {command:cmd, parameter:10};
// let cmd : avSession.AVControlCommandType = 'setSpeed';
// let avcommand = {command:cmd, parameter:2.6};
// let cmd : avSession.AVControlCommandType = 'setLoopMode';
// let avcommand = {command:cmd, parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let cmd : avSession.AVControlCommandType = 'toggleFavorite';
// let avcommand = {command:cmd, parameter:"false"};
avSession.sendSystemControlCommand(avcommand).then(() => {
  console.info('SendSystemControlCommand successfully');
}).catch((err: BusinessError) => {
  console.error(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## ProtocolType<sup>10+</sup>

远端设备支持的协议类型。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| TYPE_CAST_PLUS_MIRROR      | 1    | Cast+的镜像模式 <br> **系统接口：** 该接口为系统接口。 |

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(callback: AsyncCallback\<void>): void

开始设备搜索发现。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功并开始搜索，err为undefined，否则返回错误对象。 |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.startCastDeviceDiscovery((err: BusinessError) => {
  if (err) {
    console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('startCastDeviceDiscovery successfully');
  }
});
```

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(filter: number, callback: AsyncCallback\<void>): void

指定过滤条件，开始设备搜索发现。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| filter | number | 是 | 进行设备发现的过滤条件，由ProtocolType的组合而成 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功并开始搜索，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filter = 2;
avSession.startCastDeviceDiscovery(filter, (err: BusinessError) => {
  if (err) {
    console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('startCastDeviceDiscovery successfully');
  }
});
```

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(filter?: number, drmSchemes?: Array\<string>): Promise\<void>

开始设备搜索发现。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| filter | number | 否 | 进行设备发现的过滤条件，由ProtocolType的组合而成 |
| drmSchemes | Array\<string> | 否 | 进行支持DRM资源播放的设备发现的过滤条件，由DRM uuid组合而成。 <br/>从API version 12开始支持该可选参数。|

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功并开始搜索，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let filter = 2;
let drmSchemes = ['3d5e6d35-9b9a-41e8-b843-dd3c6e72c42c'];
avSession.startCastDeviceDiscovery(filter, drmSchemes).then(() => {
  console.info('startCastDeviceDiscovery successfully');
}).catch((err: BusinessError) => {
  console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.stopCastDeviceDiscovery<sup>10+</sup>

stopCastDeviceDiscovery(callback: AsyncCallback\<void>): void

结束设备搜索发现。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当成功停止搜索，err为undefined，否则返回错误对象。 |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.stopCastDeviceDiscovery((err: BusinessError) => {
  if (err) {
    console.error(`stopCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('stopCastDeviceDiscovery successfully');
  }
});
```

## avSession.stopCastDeviceDiscovery<sup>10+</sup>

stopCastDeviceDiscovery(): Promise\<void>

结束设备搜索发现。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当成功停止搜索，无返回结果，否则返回错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.stopCastDeviceDiscovery().then(() => {
  console.info('stopCastDeviceDiscovery successfully');
}).catch((err: BusinessError) => {
  console.error(`stopCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.setDiscoverable<sup>10+</sup>

setDiscoverable(enable: boolean, callback: AsyncCallback\<void>): void

设置设备是否可被发现，用于投播接收端。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| enable | boolean | 是 | 是否允许本设备被发现. true: 允许被发现， false：不允许被发现 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.setDiscoverable(true, (err: BusinessError) => {
  if (err) {
    console.error(`setDiscoverable BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('setDiscoverable successfully');
  }
});
```

## avSession.setDiscoverable<sup>10+</sup>

setDiscoverable(enable: boolean): Promise\<void>

设置设备是否可被发现，用于投播接收端。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| enable | boolean | 是 | 是否允许本设备被发现. true: 允许被发现， false：不允许被发现 |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当设置成功，无返回结果，否则返回错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.setDiscoverable(true).then(() => {
  console.info('setDiscoverable successfully');
}).catch((err: BusinessError) => {
  console.error(`setDiscoverable BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.on('deviceAvailable')<sup>10+</sup>

on(type: 'deviceAvailable', callback: (device: OutputDeviceInfo) => void): void

设备发现回调监听。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持事件`'deviceAvailable'`，有设备被发现时触发回调。 |
| callback | (device: [OutputDeviceInfo](js-apis-avsession.md#outputdeviceinfo10)) => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则返回错误对象。                                |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
let castDevice: avSession.OutputDeviceInfo;
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {
  castDevice = device;
  console.info(`on deviceAvailable  : ${device} `);
});
```

## avSession.off('deviceAvailable')<sup>10+</sup>

off(type: 'deviceAvailable', callback?: (device: OutputDeviceInfo) => void): void

取消设备发现回调的监听。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                    | 必填  |      说明                                               |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | 是    | 事件回调类型，支持事件`'deviceAvailable'`：设备发现回调。|
| callback     | (device: [OutputDeviceInfo](js-apis-avsession.md#outputdeviceinfo10)) => void                 | 否    | 用于返回设备信息。|

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
avSession.off('deviceAvailable');
```

## avSession.on('deviceOffline')<sup>11+</sup>

on(type: 'deviceOffline', callback: (deviceId: string) => void): void

设备下线回调监听。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持事件`'deviceOffline'`，有设备下线时触发回调。 |
| callback | (deviceId: string) => void | 是   | 回调函数，参数deviceId是设备的ID。当监听事件注册成功，err为undefined，否则返回错误对象。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
let castDeviceId: string;
avSession.on('deviceOffline', (deviceId: string) => {
  castDeviceId = deviceId;
  console.info(`on deviceOffline  : ${deviceId} `);
});
```

## avSession.off('deviceOffline')<sup>11+</sup>

off(type: 'deviceOffline', callback?: (deviceId: string) => void): void

取消设备下线回调的监听。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                    | 必填  |      说明                                               |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | 是    | 事件回调类型，支持事件`'deviceOffline'`：设备下线回调。|
| callback | (deviceId: string) => void | 否   | 回调函数，参数deviceId是设备的ID。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。|

**错误码：**

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
avSession.off('deviceOffline');
```

## avSession.getAVCastController<sup>10+</sup>

getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void

设备建立连接后，获取投播控制器。结果通过callback异步回调方式返回。

此功能在本端和远端都可以使用，通过该接口可以获取一个相同的控制器，进行投播音频的播放控制。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| sessionId | string                    | 是   |用于指定要获取的投播控制器的sessionId |
| callback  | AsyncCallback<[AVCastController](#avcastcontroller10)\> | 是   | 回调函数，返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception |
| 6600102  | session does not exist |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // 供后续函数入参使用

let aVCastController: avSession.AVCastController;
avSession.getAVCastController(sessionId , (err: BusinessError, avcontroller: avSession.AVCastController) => {
  if (err) {
    console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    aVCastController = avcontroller;
    console.info('getAVCastController : SUCCESS ');
  }
});
```

## avSession.getAVCastController<sup>10+</sup>

getAVCastController(sessionId: string): Promise\<AVCastController>

设备建立连接后，获取投播控制器。结果通过Promise方式返回。

此功能在本端和远端都可以使用，通过该接口可以获取一个相同的控制器，进行投播音频的播放控制。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                       | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| sessionId | string                    | 是   |用于指定要获取的投播控制器的sessionId |

**返回值：**

| 类型                                                        | 说明             |
| --------- | ------------------------------------------------------------ |
| Promise<[AVCastController](#avcastcontroller10)\>  | Promise对象。返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | server exception |
| 6600102  | The session does not exist |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  // 供后续函数入参使用

let aVCastController: avSession.AVCastController;
avSession.getAVCastController(sessionId).then((avcontroller: avSession.AVCastController) => {
  aVCastController = avcontroller;
  console.info('getAVCastController : SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.startCasting<sup>10+</sup>

startCasting(session: SessionToken, device: OutputDeviceInfo, callback: AsyncCallback\<void>): void

启动投播。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | 是   | 会话令牌。SessionToken表示单个token。 |
| device | [OutputDeviceInfo](js-apis-avsession.md#outputdeviceinfo10)                        | 是   | 设备相关信息 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功并启动投播，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600108 | Device connection failed.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
let castDevice: avSession.OutputDeviceInfo | undefined = undefined;
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {
  castDevice = device;
  console.info(`on deviceAvailable  : ${device} `);
});
if (castDevice !== undefined) {
  avSession.startCasting(myToken, castDevice, (err: BusinessError) => {
    if (err) {
      console.error(`startCasting BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info('startCasting successfully');
    }
  });
}
```


## avSession.startCasting<sup>10+</sup>

startCasting(session: SessionToken, device: OutputDeviceInfo): Promise\<void>

启动投播。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | 是   | 会话令牌。SessionToken表示单个token。 |
| device | [OutputDeviceInfo](js-apis-avsession.md#outputdeviceinfo10)                        | 是   | 设备相关信息 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功并启动投播，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600108 | Device connection failed.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
let castDevice: avSession.OutputDeviceInfo | undefined = undefined;
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {
  castDevice = device;
  console.info(`on deviceAvailable  : ${device} `);
});
if (castDevice !== undefined) {
  avSession.startCasting(myToken, castDevice).then(() => {
    console.info('startCasting successfully');
  }).catch((err: BusinessError) => {
    console.error(`startCasting BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}
```

## avSession.stopCasting<sup>10+</sup>

stopCasting(session: SessionToken, callback: AsyncCallback\<void>): void

结束投播。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | 是   | 会话令牌。SessionToken表示单个token。 | 
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当成功结束投播，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken, (err: BusinessError) => {
  if (err) {
    console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('stopCasting successfully');
  }
});
```

## avSession.stopCasting<sup>10+</sup>

stopCasting(session: SessionToken): Promise\<void>

结束投播。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | 是   | 会话令牌。SessionToken表示单个token。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当成功结束投播，无返回结果，否则返回错误对象。 |

**错误码：**

错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken).then(() => {
  console.info('stopCasting successfully');
}).catch((err: BusinessError) => {
  console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.startDeviceLogging<sup>13+</sup>

startDeviceLogging(url: string, maxSize?: number): Promise\<void>

开始将设备日志写入文件。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| url | string                   | 是   | 目标文件描述符（打开文件的唯一标识）。 |
| maxSize | number                   | 否   | 写入最大日志大小（以KB为单位）。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当设备日志写入文件成功时，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 401        | Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

let file = await fileIo.open("filePath");
let url = file.fd.toString();
avSession.startDeviceLogging(url, 2048).then(() => {
  console.info('startDeviceLogging successfully');
}).catch((err: BusinessError) => {
  console.error(`startDeviceLogging BusinessError: code: ${err.code}, message: ${err.message}`);
})
```

## avSession.stopDeviceLogging<sup>13+</sup>

stopDeviceLogging(): Promise\<void>

停止当前设备日志写入。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当停止当前设备日志写入，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avSession.stopDeviceLogging().then(() => {
  console.info('stopCasting successfully');
}).catch((err: BusinessError) => {
  console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.on('deviceLogEvent')<sup>13+</sup>

on(type: 'deviceLogEvent', callback: Callback\<DeviceLogEventCode>): void

监听日志事件的回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'deviceLogEvent'`。 |
| callback | (callback: [DeviceLogEventCode](#devicelogeventcode13)) => void        | 是   | 回调函数，参数DeviceLogEventCode是当前设备日志返回值。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 401        | Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**示例：**

```ts
avSession.on('deviceLogEvent', (eventCode: avSession.DeviceLogEventCode) => {
  console.info(`on deviceLogEvent code : ${eventCode}`);
});
```

## avSession.off('deviceLogEvent')<sup>13+</sup>

off(type: 'deviceLogEvent', callback?: Callback\<DeviceLogEventCode>): void

取消监听日志事件的回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'deviceLogEvent'`。 |
| callback | (callback: [DeviceLogEventCode](#devicelogeventcode13)) => void        | 否  | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 401        | Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**示例：**

```ts
avSession.off('deviceLogEvent');
```

## AVCastController<sup>10+</sup>

在投播建立后，调用[avSession.getAVCastController](js-apis-avsession.md#getavcastcontroller10)后，返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。

### setDisplaySurface<sup>10+</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

设置播放的surfaceId，在投播sink端使用。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**返回值：**

| 类型                                          | 说明                        |
| --------------------------------------------- | --------------------------- |
| Promise\<void> | Promise对象。返回设置结果。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { media } from '@kit.MediaKit';
let surfaceID: string = '';
media.createAVRecorder().then((avRecorder) => {
  avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {
    if (err == null) {
      console.info('getInputSurface success');
      surfaceID = surfaceId;
    } else {
      console.error('getInputSurface failed and error is ' + err.message);
    }
  });
})
aVCastController.setDisplaySurface(surfaceID).then(() => {
  console.info('setDisplaySurface : SUCCESS');
});
```

### setDisplaySurface<sup>10+</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

设置播放的surfaceId，在投播sink端使用。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                         |
| -------- | --------------------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数，返回当前设置结果。 |
| surfaceId | string | 是   | 设置播放的surfaceId。 |


**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';
let surfaceID: string = '';
media.createAVRecorder().then((avRecorder) => {
  avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {
    if (err == null) {
      console.info('getInputSurface success');
      surfaceID = surfaceId;
    } else {
      console.error('getInputSurface failed and error is ' + err.message);
    }
  });
})
aVCastController.setDisplaySurface(surfaceID, (err: BusinessError) => {
  if (err) {
    console.error(`setDisplaySurface BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('setDisplaySurface : SUCCESS');
  }
});
```

### on('videoSizeChange')<sup>10+</sup>

on(type: 'videoSizeChange', callback: (width:number, height:number) => void): void

设置video尺寸更改监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string      | 是   | 事件回调类型，支持事件`'videoSizeChange'`：当video尺寸更改时，触发该事件。 |
| callback | (width:number, height:number) => void    | 是   | 回调函数，返回video的宽度和高度     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('videoSizeChange', (width: number, height: number) => {
  console.info(`width ：${width} `);
  console.info(`height：${height} `);
});
```

### off('videoSizeChange')<sup>10+</sup>

off(type: 'videoSizeChange'): void

取消设置video尺寸更改监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型     | 必填 | 说明      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string  | 是   | 取消对应的监听事件，支持事件`'videoSizeChange'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('videoSizeChange');
```

## AVMetadata<sup>10+</sup>

媒体元数据的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| avQueueName<sup>11+</sup>     | string                  | 否   | 歌单（歌曲列表）名称。<br/>此接口为系统接口。 |

## AVQueueInfo<sup>11+</sup>

歌单（歌曲列表）的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**系统接口：** 该接口为系统接口。

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------| ---- |--------------------------------------------------------------------- |
| bundleName      | string                  | 是   | 歌单所属应用包名。                                                        |
| avQueueName     | string                  | 是   | 歌单（歌曲列表）名称。                                                    |
| avQueueId       | string                  | 是   | 歌单（歌曲列表）唯一标识Id。                                               |
| avQueueImage    | image.PixelMap &#124; string |是   | 歌单（歌曲列表）封面图，图片的像素数据或者图片路径地址(本地路径或网络路径)。     |
| lastPlayedTime  | number                  | 否   | 歌单最后播放时间。                                                        |

## DeviceInfo<sup>10+</sup>

播放设备的相关信息。

| 名称       | 类型           | 必填 | 说明                   |
| ---------- | -------------- | ---- | ---------------------- |
| ipAddress | string | 否   | 播放设备的ip地址。<br/>此接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast     |
| providerId | number | 否   | 播放设备提供商。<br/>此接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast    |
| authenticationStatus<sup>11+</sup> | number | 否   | 播放设备是否可信。默认为0。0代表设备不可信，1代表设备可信。<br/>此接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast    |
| networkId<sup>13+</sup> | string | 否   | 播放设备的网络ID。 <br/>此接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast|

## AVSessionDescriptor

会话的相关描述信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

| 名称          | 类型              | 可读 | 可写 | 说明  |
| --------------| ---------------- | ---------------- | ---------------- |------|
| sessionId    | string    | 是 | 是  | 会话ID      |
| type         | [AVSessionType](js-apis-avsession.md#avsessiontype10)   | 是 | 是 | 会话类型    |
| sessionTag   | string             | 是 | 是 | 会话的自定义名称    |
| elementName  | [ElementName](../apis-ability-kit/js-apis-bundle-ElementName.md)  | 是 | 是 | 会话所属应用的信息（包含bundleName、abilityName等） |
| isActive     | boolean             | 是 | 是 | 会话是否被激活。<br>true：已被激活。 <br>false：没有被激活。                                      |
| isTopSession | boolean             | 是 | 是 | 会话是否为最新的会话。 <br>true：是最新的会话。<br>false：不是最新的会话。                |
| outputDevice | [OutputDeviceInfo](js-apis-avsession.md#outputdeviceinfo10)    | 是 | 是 | 分布式设备相关信息   |

## DeviceLogEventCode<sup>13+</sup>

设备日志事件返回值的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| DEVICE_LOG_FULL       | 1    | 日志已满。    |
| DEVICE_LOG_EXCEPTION       | 2    | 日写入异常。 |