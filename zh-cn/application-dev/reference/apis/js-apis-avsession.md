# @ohos.multimedia.avsession (媒体会话管理)

媒体会话管理提供媒体播控相关功能的接口，目的是让应用接入播控中心。

该模块提供以下媒体会话相关的常用功能：

- [AVSession](#avsession10) : 会话，可用于设置元数据、播放状态信息等操作。
- [AVSessionController](#avsessioncontroller10): 会话控制器，可用于查看会话ID，完成对会话发送命令及事件，获取会话元数据、播放状态信息等操作。
- [AVCastController](#avcastcontroller10): 投播控制器，可用于投播场景下，完成播放控制、远端播放状态监听、远端播放状态信息获取等操作。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import avSession from '@ohos.multimedia.avsession';
```

## avSession.createAVSession<sup>10+</sup>

createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>

创建会话对象，一个Ability只能存在一个会话，重复创建会失败，结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                           |
| ------ | ------------------------------- | ---- | ------------------------------ |
| context| [Context](js-apis-inner-app-context.md) | 是| 应用上下文，提供获取应用程序环境信息的能力。 |
| tag    | string                          | 是   | 会话的自定义名称。             |
| type   | [AVSessionType](#avsessiontype10) | 是   | 会话类型，当前支持音频和视频。 |

**返回值：**

| 类型                              | 说明                                                         |
| --------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSession](#avsession10)\> | Promise对象。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string;  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio").then((data: avSession.AVSession) => {
  currentAVSession = data;
  sessionId = currentAVSession.sessionId;
  console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
}).catch((err: BusinessError) => {
  console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.createAVSession<sup>10+</sup>

createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void

创建会话对象，一个Ability只能存在一个会话，重复创建会失败，结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context| [Context](js-apis-inner-app-context.md) | 是| 应用上下文，提供获取应用程序环境信息的能力。     |
| tag      | string                                  | 是   | 会话的自定义名称。                                           |
| type     | [AVSessionType](#avsessiontype10)         | 是   | 会话类型，当前支持音频和视频。                               |
| callback | AsyncCallback<[AVSession](#avsession10)\> | 是   | 回调函数。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string;  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    sessionId = currentAVSession.sessionId;
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});
```

## avSession.getAllSessionDescriptors

getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

获取所有会话的相关描述。结果通过Promise异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise\<Array\<Readonly\<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | Promise对象。返回所有会话描述的只读对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avSession.getAllSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`getAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
  if(descriptors.length > 0 ){
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

获取所有会话的相关描述。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | 是   | 回调函数。返回所有会话描述的只读对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  |Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avSession.getAllSessionDescriptors((err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {
  if (err) {
    console.error(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if(descriptors.length > 0 ){
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
    }
  }
});
```

## avSession.getHistoricalSessionDescriptors<sup>10+</sup>

getHistoricalSessionDescriptors(maxSize?: number): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

获取所有会话的相关描述。结果通过Promise异步回调方式返回。

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

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avSession.getHistoricalSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
  if(descriptors.length > 0 ){
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

获取所有会话的相关描述。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                                            | 必填 | 说明                                                             |
| -------- | ------------------------------------------------------------------------------ | ---- | -----------------------------------------------------------------|
| maxSize  | number                                                                         | 是   | 指定获取描述符数量的最大值，可选范围是0-10，不填则取默认值，默认值为3。|
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | 是   | 回调函数。返回所有会话描述的只读对象。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  |Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avSession.getHistoricalSessionDescriptors(1, (err: BusinessError, descriptors: avSession.AVSessionDescriptor[]) => {
  if (err) {
    console.error(`getHistoricalSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getHistoricalSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if(descriptors.length > 0 ){
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

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

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

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  |Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

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
| sessionId | string | 是   | 会话ID。 |

**返回值：**

| 类型                                                  | 说明                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSessionController](#avsessioncontroller10)\> | Promise对象。返回会话控制器实例，可查看会话ID，<br>并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let currentAVcontroller: avSession.AVSessionController | undefined = undefined;
avSession.createController(sessionId).then((avcontroller: avSession.AVSessionController) => {
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
| sessionId | string                                                      | 是   | 会话ID。                                                     |
| callback  | AsyncCallback<[AVSessionController](#avsessioncontroller10)\> | 是   | 回调函数。返回会话控制器实例，可查看会话ID，<br>并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let currentAVcontroller: avSession.AVSessionController | undefined = undefined;
avSession.createController(sessionId, (err: BusinessError, avcontroller: avSession.AVSessionController) => {
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
| audioDevices | Array\<[audio.AudioDeviceDescriptor](js-apis-audio.md#audiodevicedescriptor)\> | 是   | 媒体设备列表。  |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当投播成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info(`Promise returned to indicate that the device list is obtained.`);
}).catch((err: BusinessError) => {
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

if (audioDevices !== undefined) {
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors).then(() => {
    console.info(`CreateController : SUCCESS`);
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
| audioDevices | Array\<[audio.AudioDeviceDescriptor](js-apis-audio.md#audiodevicedescriptor)\>   | 是   | 媒体设备列表。 |
| callback     | AsyncCallback\<void>     | 是   | 回调函数。当投播成功，err为undefined，否则返回错误对象。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info(`Promise returned to indicate that the device list is obtained.`);
}).catch((err: BusinessError) => {
  console.error(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

if (audioDevices !== undefined) {
  avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors, (err: BusinessError) => {
    if (err) {
      console.error(`CastAudio BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`CastAudio : SUCCESS `);
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

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import audio from '@ohos.multimedia.audio';
import { BusinessError } from '@ohos.base';

avSession.startAVPlayback("com.example.myapplication", "121278").then(() => {
  console.info(`startAVPlayback : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`startAVPlayback BusinessError: code: ${err.code}, message: ${err.message}`);
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

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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

以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.off('topSessionChange');
```

## avSession.on('sessionServiceDie')

on(type: 'sessionServiceDie', callback: () => void): void

监听会话的服务死亡事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持事件`'sessionServiceDie'`：会话服务死亡事件，检测到会话的服务死亡时触发。 |
| callback | callback: () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则返回错误对象。                                |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.on('sessionServiceDie', () => {
  console.info(`on sessionServiceDie  : session is  Died `);
});
```

## avSession.off('sessionServiceDie')

off(type: 'sessionServiceDie', callback?: () => void): void

取消会话服务死亡监听，取消后，不再进行服务死亡监听。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**系统接口：** 该接口为系统接口

**参数：**

| 参数名    | 类型                    | 必填  |      说明                                               |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | 是    | 事件回调类型，支持事件`'sessionServiceDie'`：会话服务死亡事件。|
| callback | callback: () => void   | 否    | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的服务死亡监听。            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.off('sessionServiceDie');
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
| event    | [KeyEvent](js-apis-keyevent.md) | 是   | 按键事件。                            |
| callback | AsyncCallback\<void>                                         | 是   | 回调函数。当事件发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**示例：**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';
import { BusinessError } from '@ohos.base';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event, (err: BusinessError) => {
  if (err) {
    console.error(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SendSystemAVKeyEvent : SUCCESS `);
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
| event  | [KeyEvent](js-apis-keyevent.md) | 是   | 按键事件。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当事件发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**示例：**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';
import { BusinessError } from '@ohos.base';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event).then(() => {
  console.info(`SendSystemAVKeyEvent Successfully`);
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
| command  | [AVControlCommand](#avcontrolcommand10) | 是   | AVSession的相关命令和命令相关参数。   |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';

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
    console.info(`sendSystemControlCommand successfully`);
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
| command | [AVControlCommand](#avcontrolcommand10) | 是   | AVSession的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

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
  console.info(`SendSystemControlCommand successfully`);
}).catch((err: BusinessError) => {
  console.error(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## ProtocolType<sup>10+</sup>

远端设备支持的协议类型。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| TYPE_LOCAL      | 0    | 本地设备 <br> **系统接口：** 该接口为系统接口。 |
| TYPE_CAST_PLUS_MIRROR      | 1    | Cast+的镜像模式 <br> **系统接口：** 该接口为系统接口。 |
| TYPE_CAST_PLUS_STREAM<sup>11+</sup>      | 2    | Cast+的Stream模式 |

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
import { BusinessError } from '@ohos.base';

avSession.startCastDeviceDiscovery((err: BusinessError) => {
  if (err) {
    console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`startCastDeviceDiscovery successfully`);
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


**示例：**

```ts
import { BusinessError } from '@ohos.base';

let filter = 2;
avSession.startCastDeviceDiscovery(filter, (err: BusinessError) => {
  if (err) {
    console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`startCastDeviceDiscovery successfully`);
  }
});
```

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(filter?: number): Promise\<void>

开始设备搜索发现。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| filter | number | 否 | 进行设备发现的过滤条件，由ProtocolType的组合而成 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功并开始搜索，无返回结果，否则返回错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let filter = 2;
avSession.startCastDeviceDiscovery(filter).then(() => {
  console.info(`startCastDeviceDiscovery successfully`);
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
import { BusinessError } from '@ohos.base';

avSession.stopCastDeviceDiscovery((err: BusinessError) => {
  if (err) {
    console.error(`stopCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`stopCastDeviceDiscovery successfully`);
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
import { BusinessError } from '@ohos.base';

avSession.stopCastDeviceDiscovery().then(() => {
  console.info(`startCastDeviceDiscovery successfully`);
}).catch((err: BusinessError) => {
  console.error(`startCastDeviceDiscovery BusinessError: code: ${err.code}, message: ${err.message}`);
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


**示例：**

```ts
import { BusinessError } from '@ohos.base';

avSession.setDiscoverable(true, (err: BusinessError) => {
  if (err) {
    console.error(`setDiscoverable BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`setDiscoverable successfully`);
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

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当设置成功，无返回结果，否则返回错误对象。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avSession.setDiscoverable(true).then(() => {
  console.info(`setDiscoverable successfully`);
}).catch((err: BusinessError) => {
  console.error(`setDiscoverable BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.on('deviceAvailable')<sup>10+</sup>

on(type: 'deviceAvailable', callback: (device: OutputDeviceInfo) => void): void

设备发现回调监听。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持事件`'deviceAvailable'`，有设备被发现时触发回调。 |
| callback | (device: OutputDeviceInfo) => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则返回错误对象。                                |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';

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

**系统接口：** 该接口为系统接口

**参数：**

| 参数名    | 类型                    | 必填  |      说明                                               |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | 是    | 事件回调类型，支持事件`'deviceAvailable'`：设备发现回调。|

**示例：**

```ts
avSession.off('deviceAvailable');
```

## avSession.on('deviceOffline')<sup>11+</sup>

on(type: 'deviceOffline', callback: (deviceId: string) => void): void

设备下线回调监听。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持事件`'deviceOffline'`，有设备下线时触发回调。 |
| callback | (deviceId: string) => void | 是   | 回调函数，参数deviceId是设备的ID。当监听事件注册成功，err为undefined，否则返回错误对象。  |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';

let castDeviceId: string;
avSession.on('deviceOffline', (deviceId: string) => {
  castDeviceId = deviceId;
  console.info(`on deviceOffline  : ${deviceId} `);
});
```

## avSession.off('deviceOffline')<sup>11+</sup>

off(type: 'deviceOffline', callback?: (deviceId: string) => void): void

取消设备下线回调的监听。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口

**参数：**

| 参数名    | 类型                    | 必填  |      说明                                               |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | 是    | 事件回调类型，支持事件`'deviceOffline'`：设备下线回调。|
| callback | (deviceId: string) => void | 否   | 回调函数，参数deviceId是设备的ID。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。|

**示例：**

```ts
avSession.off('deviceOffline');
```

## avSession.getAVCastController<sup>10+</sup>

getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void

设备建立连接后，获取投播控制器。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统接口：** 该接口为系统接口

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| sessionId | string                    | 是   |用于指定要获取的投播控制器的sessionId |
| callback  | AsyncCallback<[AVCastController](#avcastcontroller10)\> | 是   | 回调函数，返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | session does not exist |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

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

getAVCastController(sessionId: string): Promise\<AVCastController>;

设备建立连接后，获取投播控制器。结果通过Promise方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统接口：** 该接口为系统接口

**参数：**

| 参数名    | 类型                       | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| sessionId | string                    | 是   |用于指定要获取的投播控制器的sessionId |

**返回值：**

| 类型                                                        | 说明             |
| --------- | ------------------------------------------------------------ |
| Promise<[AVCastController](#avcastcontroller10)\>  | Promise对象。返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | server exception |
| 6600102  | The session does not exist |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

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
| device | [OutputDeviceInfo](#outputdeviceinfo10)                        | 是   | 设备相关信息 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功并启动投播，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600108 | Device connecting failed.       |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

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
      console.info(`startCasting successfully`);
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
| device | [OutputDeviceInfo](#outputdeviceinfo10)                        | 是   | 设备相关信息 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功并启动投播，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600108 | Device connecting failed.       |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

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
    console.info(`startCasting successfully`);
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

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken, (err: BusinessError) => {
  if (err) {
    console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`stopCasting successfully`);
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

错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";  //供后续函数入参使用

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
    if (currentAVSession !== undefined) {
      sessionId = currentAVSession.sessionId;
    }
    console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
  }
});

let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken).then(() => {
  console.info(`stopCasting successfully`);
}).catch((err: BusinessError) => {
  console.error(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
});


```

## AVSessionType<sup>10+<sup>
当前会话支持的会话类型。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称  | 类型   | 说明 |
| ----- | ------ | ---- |
| audio | string | 音频 |
| video | string | 视频 |

## AVSession<sup>10+</sup>

调用[avSession.createAVSession](#avsessioncreateavsession10)后，返回会话的实例，可以获得会话ID，完成设置元数据，播放状态信息等操作。

### 属性

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型   | 可读 | 可写 | 说明                          |
| :-------- | :----- | :--- | :--- | :---------------------------- |
| sessionId | string | 是   | 否   | AVSession对象唯一的会话标识。 |
| sessionType<sup>10+</sup> | AVSessionType | 是   | 否   | AVSession会话类型。 |


**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';

let sessionId: string = currentAVSession.sessionId;
let sessionType: avSession.AVSessionType = currentAVSession.sessionType;
```

### setAVMetadata<sup>10+</sup>

setAVMetadata(data: AVMetadata): Promise\<void>

设置会话元数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| data   | [AVMetadata](#avmetadata10) | 是   | 会话元数据。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let metadata: avSession.AVMetadata = {
  assetId: "121278",
  title: "lose yourself",
  artist: "Eminem",
  author: "ST",
  album: "Slim shady",
  writer: "ST",
  composer: "ST",
  duration: 2222,
  mediaImage: "https://www.example.com/example.jpg",
  subtitle: "8 Mile",
  description: "Rap",
  lyric: "https://www.example.com/example.lrc",
  previousAssetId: "121277",
  nextAssetId: "121279",
};
currentAVSession.setAVMetadata(metadata).then(() => {
  console.info(`SetAVMetadata successfully`);
}).catch((err: BusinessError) => {
  console.error(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVMetadata<sup>10+</sup>

setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void

设置会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [AVMetadata](#avmetadata10) | 是   | 会话元数据。                          |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let metadata: avSession.AVMetadata = {
  assetId: "121278",
  title: "lose yourself",
  artist: "Eminem",
  author: "ST",
  album: "Slim shady",
  writer: "ST",
  composer: "ST",
  duration: 2222,
  mediaImage: "https://www.example.com/example.jpg",
  subtitle: "8 Mile",
  description: "Rap",
  lyric: "https://www.example.com/example.lrc",
  previousAssetId: "121277",
  nextAssetId: "121279",
};
currentAVSession.setAVMetadata(metadata, (err: BusinessError) => {
  if (err) {
    console.error(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SetAVMetadata successfully`);
  }
});
```

### setCallMetadata<sup>11+</sup>

setCallMetadata(data: CallMetadata): Promise\<void>

设置通话会话元数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| data   | [CallMetadata](#callmetadata11) | 是   | 通话会话元数据。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当通话元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let calldata: avSession.CallMetadata = {
  name: "xiaoming",
  phoneNumber: "111xxxxxxxx",
  avatar: "xxx.jpg",
};
currentAVSession.setCallMetadata(calldata).then(() => {
  console.info(`setCallMetadata successfully`);
}).catch((err: BusinessError) => {
  console.error(`setCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setCallMetadata<sup>11+</sup>

setCallMetadata(data: CallMetadata, callback: AsyncCallback\<void>): void

设置通话会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [CallMetadata](#callmetadata11) | 是   | 通话会话元数据。                          |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当通话元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let calldata: avSession.CallMetadata = {
  name: "xiaoming",
  phoneNumber: "111xxxxxxxx",
  avatar: "xxx.jpg",
};
currentAVSession.setCallMetadata(calldata, (err: BusinessError) => {
  if (err) {
    console.error(`setCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`setCallMetadata successfully`);
  }
});
```

### setAVCallState<sup>11+</sup>

setAVCallState(state: AVCallState): Promise\<void>

设置通话状态。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| state   | [AVCallState](#avcallstate11) | 是   | 通话会话元数据。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当通话元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let calldata: avSession.AVCallState = {
  state: avSession.AVCallState.CALL_STATE_ACTIVE ,
  muted: false
};
currentAVSession.setAVCallState(calldata).then(() => {
  console.info(`setAVCallState successfully`);
}).catch((err: BusinessError) => {
  console.error(`setAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVCallState<sup>11+</sup>

setAVCallState(state: AVCallState, callback: AsyncCallback\<void>): void

设置通话会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| state     | [AVCallState](#avcallstate11) | 是   | 通话会话元数据。                          |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当通话元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avcalldata: avSession.AVCallState = {
  state: avsession.CallState.CALL_STATE_ACTIVE,
  muted: false
};
currentAVSession.setAVCallState(avcalldata, (err: BusinessError) => {
  if (err) {
    console.error(`setAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`setAVCallState successfully`);
  }
});
```

### setAVPlaybackState<sup>10+</sup>

setAVPlaybackState(state: AVPlaybackState): Promise\<void>

设置会话播放状态。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                                | 必填 | 说明                                           |
| ------ | ----------------------------------- | ---- | ---------------------------------------------- |
| data   | [AVPlaybackState](#avplaybackstate10) | 是   | 会话播放状态，包括状态、倍数、循环模式等信息。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放状态设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let playbackState: avSession.AVPlaybackState = {
  state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
  speed: 1.0,
  position:{elapsedTime:10, updateTime:(new Date()).getTime()},
  bufferedTime:1000,
  loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
  isFavorite:true,
};
currentAVSession.setAVPlaybackState(playbackState).then(() => {
  console.info(`SetAVPlaybackState successfully`);
}).catch((err: BusinessError) => {
  console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVPlaybackState<sup>10+</sup>

setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void

设置会话播放状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                           |
| -------- | ----------------------------------- | ---- | ---------------------------------------------- |
| data     | [AVPlaybackState](#avplaybackstate10) | 是   | 会话播放状态，包括状态、倍数、循环模式等信息。 |
| callback | AsyncCallback\<void>                | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let PlaybackState: avSession.AVPlaybackState = {
  state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
  speed: 1.0,
  position:{elapsedTime:10, updateTime:(new Date()).getTime()},
  bufferedTime:1000,
  loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
  isFavorite:true,
};
currentAVSession.setAVPlaybackState(PlaybackState, (err: BusinessError) => {
  if (err) {
    console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SetAVPlaybackState successfully`);
  }
});
```

### setLaunchAbility<sup>10+</sup>

setLaunchAbility(ability: WantAgent): Promise\<void>

设置一个WantAgent用于拉起会话的Ability。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| ability | [WantAgent](js-apis-app-ability-wantAgent.md) | 是   | 应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当Ability设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import wantAgent from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
  wants: [
    {
      deviceId: "deviceId",
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility",
      action: "action1",
      entities: ["entity1"],
      type: "MIMETYPE",
      uri: "key={true,true,false}",
      parameters:
        {
          mykey0: 2222,
          mykey1: [1, 2, 3],
          mykey2: "[1, 2, 3]",
          mykey3: "ssssssssssssssssssssssssss",
          mykey4: [false, true, false],
          mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
          mykey6: true,
        }
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
  currentAVSession.setLaunchAbility(agent).then(() => {
    console.info(`SetLaunchAbility successfully`);
  }).catch((err: BusinessError) => {
    console.error(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
  });
});
```

### setLaunchAbility<sup>10+</sup>

setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void

设置一个WantAgent用于拉起会话的Ability。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                          | 必填 | 说明                                                         |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| ability  | [WantAgent](js-apis-app-ability-wantAgent.md) | 是   | 应用的相关属性信息，如bundleName，abilityName，deviceId等。  |
| callback | AsyncCallback\<void>                          | 是   | 回调函数。当Ability设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import wantAgent from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

//WantAgentInfo对象
let wantAgentInfo: wantAgent.WantAgentInfo = {
  wants: [
    {
      deviceId: "deviceId",
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility",
      action: "action1",
      entities: ["entity1"],
      type: "MIMETYPE",
      uri: "key={true,true,false}",
      parameters:
        {
          mykey0: 2222,
          mykey1: [1, 2, 3],
          mykey2: "[1, 2, 3]",
          mykey3: "ssssssssssssssssssssssssss",
          mykey4: [false, true, false],
          mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
          mykey6: true,
        }
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITIES,
  requestCode: 0,
  wantAgentFlags:[wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((agent) => {
  currentAVSession.setLaunchAbility(agent, (err: BusinessError) => {
    if (err) {
      console.error(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`SetLaunchAbility successfully`);
    }
  });
});
```

### dispatchSessionEvent<sup>10+</sup>

dispatchSessionEvent(event: string, args: {[key: string]: Object}): Promise\<void>

媒体提供方设置一个会话内自定义事件，包括事件名和键值对形式的事件内容, 结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| event | string | 是   | 需要设置的会话事件的名称 |
| args | {[key: string]: any} | 是   | 需要传递的会话事件键值对 |

> **说明：**
> 参数args支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md)。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当事件设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
let eventName = "dynamic_lyric";
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).dispatchSessionEvent(eventName, {lyric : "This is lyric"}).then(() => {
    console.info(`dispatchSessionEvent successfully`);
  }).catch((err: BusinessError) => {
    console.info(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
```

### dispatchSessionEvent<sup>10+</sup>

dispatchSessionEvent(event: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void

媒体提供方设置一个会话内自定义事件，包括事件名和键值对形式的事件内容, 结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| event | string | 是   | 需要设置的会话事件的名称 |
| args | {[key: string]: any} | 是   | 需要传递的会话事件键值对 |
| callback | AsyncCallback\<void>                          | 是   | 回调函数。当会话事件设置成功，err为undefined，否则返回错误对象。 |

> **说明：**

> 参数args支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md)。

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
let eventName: string = "dynamic_lyric";
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).dispatchSessionEvent(eventName, {lyric : "This is lyric"}, (err: BusinessError) => {
    if(err) {
      console.error(`dispatchSessionEvent BusinessError: code: ${err.code}, message: ${err.message}`);
    }
  })
}
```

### setAVQueueItems<sup>10+</sup>

setAVQueueItems(items: Array\<AVQueueItem>): Promise\<void>

设置媒体播放列表。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                 | 必填 | 说明                               |
| ------ | ------------------------------------ | ---- | ---------------------------------- |
| items  | Array<[AVQueueItem](#avqueueitem10)\> | 是   | 播放列表单项的队列，用以表示播放列表。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放列表设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import image from '@ohos.multimedia.image';
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@ohos.base';
import avSession from '@ohos.multimedia.avsession';

let value: Uint8Array | undefined = undefined;
let imageSource: image.ImageSource | undefined = undefined;
resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI').then((data) => {
  value = data;
});
if (value !== undefined) {
  imageSource = image.createImageSource((value as Uint8Array).buffer);
}
let imagePixel: image.PixelMap | undefined = undefined;
if (imageSource !== undefined) {
  (imageSource as image.ImageSource).createPixelMap({desiredSize:{width: 150, height: 150}}).then((data) => {
    imagePixel = data;
  }).catch((err: BusinessError) => {
    console.error(`createPixelMap BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}

let queueItemDescription_1: avSession.AVMediaDescription = {
  assetId: '001',
  title: 'music_name',
  subtitle: 'music_sub_name',
  description: 'music_description',
  mediaImage : imagePixel,
  extras: {extras:'any'}
};
let queueItem_1: avSession.AVQueueItem = {
  itemId: 1,
  description: queueItemDescription_1
};
let queueItemDescription_2: avSession.AVMediaDescription = {
  assetId: '002',
  title: 'music_name',
  subtitle: 'music_sub_name',
  description: 'music_description',
  mediaImage: imagePixel,
  extras: {extras:'any'}
};
let queueItem_2: avSession.AVQueueItem = {
  itemId: 2,
  description: queueItemDescription_2
};
let queueItemsArray: avSession.AVQueueItem[] = [queueItem_1, queueItem_2];
currentAVSession.setAVQueueItems(queueItemsArray).then(() => {
  console.info(`SetAVQueueItems successfully`);
}).catch((err: BusinessError) => {
  console.error(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVQueueItems<sup>10+</sup>

setAVQueueItems(items: Array\<AVQueueItem>, callback: AsyncCallback\<void>): void

设置媒体播放列表。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------ | ---- | ----------------------------------------------------------- |
| items    | Array<[AVQueueItem](#avqueueitem10)\> | 是   | 播放列表单项的队列，用以表示播放列表。                          |
| callback | AsyncCallback\<void>                 | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import image from '@ohos.multimedia.image';
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@ohos.base';
import avSession from '@ohos.multimedia.avsession';

let value: Uint8Array | undefined = undefined;
let imageSource: image.ImageSource | undefined = undefined;
resourceManager.getSystemResourceManager().getRawFileContent('IMAGE_URI').then((data) => {
  value = data;
});
if (value !== undefined) {
  imageSource = image.createImageSource((value as Uint8Array).buffer);
}
let imagePixel: image.PixelMap | undefined = undefined;
if (imageSource !== undefined) {
  (imageSource as image.ImageSource).createPixelMap({desiredSize:{width: 150, height: 150}}).then((data) => {
    imagePixel = data;
  }).catch((err: BusinessError) => {
    console.error(`createPixelMap BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
let queueItemDescription_1: avSession.AVMediaDescription = {
  assetId: '001',
  title: 'music_name',
  subtitle: 'music_sub_name',
  description: 'music_description',
  mediaImage : imagePixel,
  extras: {extras:'any'}
};
let queueItem_1: avSession.AVQueueItem = {
  itemId: 1,
  description: queueItemDescription_1
};
let queueItemDescription_2: avSession.AVMediaDescription = {
  assetId: '002',
  title: 'music_name',
  subtitle: 'music_sub_name',
  description: 'music_description',
  mediaImage: imagePixel,
  extras: {extras:'any'}
};
let queueItem_2: avSession.AVQueueItem = {
  itemId: 2,
  description: queueItemDescription_2
};
let queueItemsArray: avSession.AVQueueItem[] = [queueItem_1, queueItem_2];
currentAVSession.setAVQueueItems(queueItemsArray, (err: BusinessError) => {
  if (err) {
    console.error(`SetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SetAVQueueItems successfully`);
  }
});
```

### setAVQueueTitle<sup>10+</sup>

setAVQueueTitle(title: string): Promise\<void>

设置媒体播放列表名称。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| title  | string | 是   | 播放列表的名称。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放列表设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let queueTitle = 'QUEUE_TITLE';
currentAVSession.setAVQueueTitle(queueTitle).then(() => {
  console.info(`SetAVQueueTitle successfully`);
}).catch((err: BusinessError) => {
  console.error(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVQueueTitle<sup>10+</sup>

setAVQueueTitle(title: string, callback: AsyncCallback\<void>): void

设置媒体播放列表名称。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| title    | string                | 是   | 播放列表名称字段。                          |
| callback | AsyncCallback\<void>  | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let queueTitle = 'QUEUE_TITLE';
currentAVSession.setAVQueueTitle(queueTitle, (err: BusinessError) => {
  if (err) {
    console.info(`SetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.error(`SetAVQueueTitle successfully`);
  }
});
```

### setExtras<sup>10+</sup>

setExtras(extras: {[key: string]: Object}): Promise\<void>

媒体提供方设置键值对形式的自定义媒体数据包, 结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| extras | {[key: string]: Object} | 是   | 需要传递的自定义媒体数据包键值对 |

> **说明：**

> 参数extras支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md)。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当自定义媒体数据包设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).setExtras({extras : "This is custom media packet"}).then(() => {
    console.info(`setExtras successfully`);
  }).catch((err: BusinessError) => {
    console.info(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
```

### setExtras<sup>10+</sup>

setExtras(extras: {[key: string]: Object}, callback: AsyncCallback\<void>): void

媒体提供方设置键值对形式的自定义媒体数据包, 结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                                          | 必填 | 说明                                                        |
| ------- | --------------------------------------------- | ---- | ----------------------------------------------------------- |
| extras | {[key: string]: any} | 是   | 需要传递的自定义媒体数据包键值对 |
| callback | AsyncCallback\<void>                          | 是   | 回调函数。当自定义媒体数据包设置成功，err为undefined，否则返回错误对象。 |

> **说明：**

> 参数extras支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md)。

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).setExtras({extras : "This is custom media packet"}, (err: BusinessError) => {
    if(err) {
      console.error(`setExtras BusinessError: code: ${err.code}, message: ${err.message}`);
    }
  })
}
```

### getController<sup>10+</sup>

getController(): Promise\<AVSessionController>

获取本会话对应的控制器。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                 | 说明                          |
| ---------------------------------------------------- | ----------------------------- |
| Promise<[AVSessionController](#avsessioncontroller10)> | Promise对象。返回会话控制器。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let avsessionController: avSession.AVSessionController;
currentAVSession.getController().then((avcontroller: avSession.AVSessionController) => {
  avsessionController = avcontroller;
  console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);
}).catch((err: BusinessError) => {
  console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getController<sup>10+</sup>

getController(callback: AsyncCallback\<AVSessionController>): void

获取本会话相应的控制器。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                       |
| -------- | ----------------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVSessionController](#avsessioncontroller10)\> | 是   | 回调函数。返回会话控制器。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let avsessionController: avSession.AVSessionController;
currentAVSession.getController((err: BusinessError, avcontroller: avSession.AVSessionController) => {
  if (err) {
    console.error(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    avsessionController = avcontroller;
    console.info(`GetController : SUCCESS : sessionid : ${avsessionController.sessionId}`);
  }
});
```

### getAVCastController<sup>10+</sup>

getAVCastController(callback: AsyncCallback\<AVCastController>): void

设备建立连接后，获取投播控制器。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback<[AVCastController](#avcastcontroller10)\> | 是   | 回调函数，返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息                                  |
| -------- |---------------------------------------|
| 6600102  | The session does not exist.           |
| 6600110  | The remote connection does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let aVCastController: avSession.AVCastController;
currentAVSession.getAVCastController().then((avcontroller: avSession.AVCastController) => {
  aVCastController = avcontroller;
  console.info(`getAVCastController : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVCastController<sup>10+</sup>

getAVCastController(): Promise\<AVCastController>;

设备建立连接后，获取投播控制器。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise<[AVCastController](#avcastcontroller10)\>  | Promise对象。返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | --------------------------------------- |
| 6600102  | The session does not exist. |
| 6600110  | The remote connection does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let aVCastController: avSession.AVCastController;
currentAVSession.getAVCastController((err: BusinessError, avcontroller: avSession.AVCastController) => {
  if (err) {
    console.error(`getAVCastController BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    aVCastController = avcontroller;
    console.info(`getAVCastController : SUCCESS`);
  }
});
```

### getOutputDevice<sup>10+</sup>

getOutputDevice(): Promise\<OutputDeviceInfo>

通过会话获取播放设备信息。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                           | 说明                              |
| ---------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo10)> | Promise对象。返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.getOutputDevice().then((outputDeviceInfo: avSession.OutputDeviceInfo) => {
  console.info(`GetOutputDevice : SUCCESS : devices length : ${outputDeviceInfo.devices.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
})
```

### getOutputDevice<sup>10+</sup>

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

通过会话获取播放设备相关信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                           |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo10)\> | 是   | 回调函数，返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.getOutputDevice((err: BusinessError, outputDeviceInfo: avSession.OutputDeviceInfo) => {
  if (err) {
    console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetOutputDevice : SUCCESS : devices length : ${outputDeviceInfo.devices.length}`);
  }
});
```

### activate<sup>10+</sup>

activate(): Promise\<void>

激活会话，激活后可正常使用会话。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当会话激活成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.activate().then(() => {
  console.info(`Activate : SUCCESS `);
}).catch((err: BusinessError) => {
  console.error(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### activate<sup>10+</sup>

activate(callback: AsyncCallback\<void>): void

激活会话，激活后可正常使用会话。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当会话激活成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.activate((err: BusinessError) => {
  if (err) {
    console.error(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Activate : SUCCESS `);
  }
});
```

### deactivate<sup>10+</sup>

deactivate(): Promise\<void>

禁用当前会话的功能，可通过[activate](#activate10)恢复。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当禁用会话成功，无返回结果，否则返回错误对象。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.deactivate().then(() => {
  console.info(`Deactivate : SUCCESS `);
}).catch((err: BusinessError) => {
  console.error(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### deactivate<sup>10+</sup>

deactivate(callback: AsyncCallback\<void>): void

禁用当前会话。结果通过callback异步回调方式返回。

禁用当前会话的功能，可通过[activate](#activate10)恢复。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当禁用会话成功，err为undefined，否则返回错误对象。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.deactivate((err: BusinessError) => {
  if (err) {
    console.error(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Deactivate : SUCCESS `);
  }
});
```

### destroy<sup>10+</sup>

destroy(): Promise\<void>

销毁当前会话，使当前会话完全失效。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当会话销毁成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.destroy().then(() => {
  console.info(`Destroy : SUCCESS `);
}).catch((err: BusinessError) => {
  console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### destroy<sup>10+</sup>

destroy(callback: AsyncCallback\<void>): void

销毁当前会话，使当前会话完全失效。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当会话销毁成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.destroy((err: BusinessError) => {
  if (err) {
    console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Destroy : SUCCESS `);
  }
});
```

### on('play')<sup>10+</sup>

on(type: 'play', callback: () => void): void

设置播放命令监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件为`'play'`当播放命令被发送到会话时，触发该事件回调。 |
| callback | callback: () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。                                        |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('play', () => {
  console.info(`on play entry`);
});
```

### on('pause')<sup>10+</sup>

on(type: 'pause', callback: () => void): void

设置暂停命令监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件为`'pause'`，当暂停命令被发送到会话时，触发该事件回调。 |
| callback | callback: () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('pause', () => {
  console.info(`on pause entry`);
});
```

### on('stop')<sup>10+</sup>

on(type:'stop', callback: () => void): void

设置停止命令监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'stop'`，当停止命令被发送到会话时，触发该事件回调。 |
| callback | callback: () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('stop', () => {
  console.info(`on stop entry`);
});
```

### on('playNext')<sup>10+</sup>

on(type:'playNext', callback: () => void): void

设置播放下一首命令监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playNext'`，当播放下一首命令被发送到会话时，触发该事件回调。 |
| callback | callback: () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('playNext', () => {
  console.info(`on playNext entry`);
});
```

### on('playPrevious')<sup>10+</sup>

on(type:'playPrevious', callback: () => void): void

设置播放上一首命令监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playPrevious'`当播放上一首命令被发送到会话时，触发该事件回调。 |
| callback | callback: () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。       |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('playPrevious', () => {
  console.info(`on playPrevious entry`);
});
```

### on('fastForward')<sup>10+</sup>

on(type: 'fastForward', callback: (time?: number) => void): void

设置快进命令监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是 `'fastForward'`，当快进命令被发送到会话时，触发该事件回调。 |
| callback | callback: (time?: number) => void | 是   | 回调函数。参数time是时间节点，单位为秒。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('fastForward', (time?: number) => {
  console.info(`on fastForward entry`);
});
```

### on('rewind')<sup>10+</sup>

on(type:'rewind', callback: (time?: number) => void): void

设置快退命令监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'rewind'`，当快退命令被发送到会话时，触发该事件回调。 |
| callback | callback: (time?: number) => void | 是   | 回调函数。参数time是时间节点，单位为秒。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('rewind', (time?: number) => {
  console.info(`on rewind entry`);
});
```

### on('playFromAssetId')<sup>11+</sup>

on(type:'playFromAssetId', callback: (assetId: number) => void): void

设置媒体id播放监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件是`'playFromAssetId'`，当媒体id播放时，触发该事件回调。 |
| callback | callback: (assetId: number) => void | 是   | 回调函数。参数assetId是媒体id。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('playFromAssetId', (assetId: number) => {
  console.info(`on playFromAssetId entry`);
});
```

### off('playFromAssetId')<sup>11+</sup>

off(type: 'playFromAssetId', callback?: (assetId: number) => void): void

取消媒体id播放事件监听，关闭后，不再进行该事件回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'playFromAssetId'`。 |
| callback | callback: (assetId: number) => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playFromAssetId');
```

### on('seek')<sup>10+</sup>

on(type: 'seek', callback: (time: number) => void): void

设置跳转节点监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 事件回调类型，支持事件`'seek'`：当跳转节点命令被发送到会话时，触发该事件。 |
| callback | (time: number) => void | 是   | 回调函数。参数time是时间节点，单位为毫秒。                   |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('seek', (time: number) => {
  console.info(`on seek entry time : ${time}`);
});
```

### on('setSpeed')<sup>10+</sup>

on(type: 'setSpeed', callback: (speed: number) => void): void

设置播放速率的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | 是   | 事件回调类型，支持事件`'setSpeed'`：当设置播放速率的命令被发送到会话时，触发该事件。 |
| callback | (speed: number) => void | 是   | 回调函数。参数speed是播放倍速。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('setSpeed', (speed: number) => {
  console.info(`on setSpeed speed : ${speed}`);
});
```

### on('setLoopMode')<sup>10+</sup>

on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void

设置循环模式的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                   | 必填 | 说明  |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | 是   | 事件回调类型，支持事件`'setLoopMode'`：当设置循环模式的命令被发送到会话时，触发该事件。 |
| callback | (mode: [LoopMode](#loopmode10)) => void | 是   | 回调函数。参数mode是循环模式。                               |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('setLoopMode', (mode: avSession.LoopMode) => {
  console.info(`on setLoopMode mode : ${mode}`);
});
```

### on('toggleFavorite')<sup>10+</sup>

on(type: 'toggleFavorite', callback: (assetId: string) => void): void

设置是否收藏的监听事件

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                    | 是   | 事件回调类型，支持事件`'toggleFavorite'`：当是否收藏的命令被发送到会话时，触发该事件。 |
| callback | (assetId: string) => void | 是   | 回调函数。参数assetId是媒体ID。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('toggleFavorite', (assetId: string) => {
  console.info(`on toggleFavorite mode : ${assetId}`);
});
```

### on('skipToQueueItem')<sup>10+</sup>

on(type: 'skipToQueueItem', callback: (itemId: number) => void): void

设置播放列表其中某项被选中的监听事件，session端可以选择对这个单项歌曲进行播放。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                                                      |
| -------- | ------------------------ | ---- | ---------------------------------------------------------------------------------------- |
| type     | string                   | 是   | 事件回调类型，支持事件`'skipToQueueItem'`：当播放列表选中单项的命令被发送到会话时，触发该事件。 |
| callback | (itemId: number) => void | 是   | 回调函数。参数itemId是选中的播放列表项的ID。                                                |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('skipToQueueItem', (itemId: number) => {
  console.info(`on skipToQueueItem id : ${itemId}`);
});
```

### on('handleKeyEvent')<sup>10+</sup>

on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void

设置按键事件的监听

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'handleKeyEvent'`：当按键事件被发送到会话时，触发该事件。 |
| callback | (event: [KeyEvent](js-apis-keyevent.md)) => void | 是   | 回调函数。参数event是按键事件。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';

currentAVSession.on('handleKeyEvent', (event: keyEvent.KeyEvent) => {
  console.info(`on handleKeyEvent event : ${event}`);
});

```

### on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void

设置播放设备变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | 是   | 事件回调类型，支持事件`'outputDeviceChange'`：当播放设备变化时，触发该事件。 |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | 是   | 回调函数，参数device是设备相关信息。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {
  console.info(`on outputDeviceChange device : ${device}`);
});
```

### on('commonCommand')<sup>10+</sup>

on(type: 'commonCommand', callback: (command: string, args: {[key: string]: Object}) => void): void

设置自定义控制命令变化的监听器。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'commonCommand'`：当自定义控制命令变化时，触发该事件。 |
| callback | (commonCommand: string, args: {[key:string]: Object}) => void         | 是   | 回调函数，commonCommand为变化的自定义控制命令名，args为自定义控制命令的参数，参数内容与sendCommand方法设置的参数内容完全一致。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import avSession from '@ohos.multimedia.avsession';
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  (currentAVSession as avSession.AVSession).on('commonCommand', (commonCommand, args) => {
    console.info(`OnCommonCommand, the command is ${commonCommand}, args: ${JSON.stringify(args)}`);
  });
}
```

### off('play')<sup>10+</sup>

off(type: 'play', callback?: () => void): void

取消会话播放事件监听，关闭后，不再进行该事件回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'play'`|
| callback | callback: () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('play');
```

### off('pause')<sup>10+</sup>

off(type: 'pause', callback?: () => void): void

取消会话暂停事件监听，关闭后，不再进行该事件回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'pause'`。 |
| callback | callback: () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('pause');
```

### off('stop')<sup>10+</sup>

off(type: 'stop', callback?: () => void): void

取消会话停止事件监听，关闭后，不再进行该事件回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'stop'`。 |
| callback | callback: () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('stop');
```

### off('playNext')<sup>10+</sup>

off(type: 'playNext', callback?: () => void): void

取消会话播放下一首事件监听，关闭后，不再进行该事件回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是 `'playNext'`。 |
| callback | callback: () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playNext');
```

### off('playPrevious')<sup>10+</sup>

off(type: 'playPrevious', callback?: () => void): void

取消会话播放上一首事件监听，关闭后，不再进行该事件回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'playPrevious'`。 |
| callback | callback: () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('playPrevious');
```

### off('fastForward')<sup>10+</sup>

off(type: 'fastForward', callback?: () => void): void

取消会话快进事件监听，关闭后，不再进行该事件回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'fastForward'`。 |
| callback | callback: () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('fastForward');
```

### off('rewind')<sup>10+</sup>

off(type: 'rewind', callback?: () => void): void

取消会话快退事件监听，关闭后，不再进行该事件回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'rewind'`。 |
| callback | callback: () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('rewind');
```

### off('seek')<sup>10+</sup>

off(type: 'seek', callback?: (time: number) => void): void

取消监听跳转节点事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                          |
| -------- | ---------------------- | ---- | ----------------------------------------- |
| type     | string                 | 是   | 关闭对应的监听事件，支持关闭事件`'seek'`。       |
| callback | (time: number) => void | 否   | 回调函数，参数time是时间节点，单位为毫秒。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。        |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('seek');
```

### off('setSpeed')<sup>10+</sup>

off(type: 'setSpeed', callback?: (speed: number) => void): void

取消监听播放速率变化事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                           |
| -------- | ----------------------- | ---- | -------------------------------------------|
| type     | string                  | 是   | 关闭对应的监听事件，支持关闭事件`'setSpeed'`。    |
| callback | (speed: number) => void | 否   | 回调函数，参数speed是播放倍速。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('setSpeed');
```

### off('setLoopMode')<sup>10+</sup>

off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void

取消监听循环模式变化事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明     |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | 是   | 关闭对应的监听事件，支持关闭事件`'setLoopMode'`。|
| callback | (mode: [LoopMode](#loopmode10)) => void | 否   | 回调函数，参数mode是循环模式。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('setLoopMode');
```

### off('toggleFavorite')<sup>10+</sup>

off(type: 'toggleFavorite', callback?: (assetId: string) => void): void

取消监听是否收藏的事件

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | -------------------------------------------------------- |
| type     | string                    | 是   | 关闭对应的监听事件，支持关闭事件`'toggleFavorite'`。            |
| callback | (assetId: string) => void | 否   | 回调函数，参数assetId是媒体ID。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                               |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('toggleFavorite');
```

### off('skipToQueueItem')<sup>10+</sup>

off(type: 'skipToQueueItem', callback?: (itemId: number) => void): void

取消监听播放列表单项选中的事件

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                                                                                                                        |
| -------- | ------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- |
| type     | string                   | 是   | 关闭对应的监听事件，支持关闭事件`'skipToQueueItem'`。                                                                                                          |
| callback | (itemId: number) => void | 否   | 回调函数，参数itemId是播放列表单项ID。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('skipToQueueItem');
```

### off('handleKeyEvent')<sup>10+</sup>

off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void

取消监听按键事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 关闭对应的监听事件，支持关闭事件`'handleKeyEvent'`。             |
| callback | (event: [KeyEvent](js-apis-keyevent.md)) => void | 否   | 回调函数，参数event是按键事件。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                              |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('handleKeyEvent');
```

### off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void

取消监听播放设备变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                      |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | 是   | 关闭对应的监听事件，支持关闭事件`'outputDeviceChange'`。     |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | 否   | 回调函数，参数device是设备相关信息。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                        |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('outputDeviceChange');
```


### off('commonCommand')<sup>10+</sup>

off(type: 'commonCommand', callback?: (command: string, args: {[key:string]: Object}) => void): void

取消监听自定义控制命令的变化。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'commonCommand'`。    |
| callback | (command: string, args: {[key:string]: Object}) => void         | 否   | 回调函数，参数command是变化的自定义控制命令名，args为自定义控制命令的参数。<br>该参数为可选参数，若不填写该参数，则认为取消所有对command事件的监听。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('commonCommand');
```

### on('answer')<sup>11+</sup>

on(type: 'answer', callback: Callback\<void>): void;

设置通话接听的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'answer'`：当通话接听时，触发该事件。 |
| callback | Callback\<void>                                               | 是   | 回调函数                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('answer', () => {
  console.info(`on call answer`);
});
```

### off('answer')<sup>11+</sup>

off(type: 'answer', callback?: Callback\<void>): void;

取消通话接听事件的监听。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'answer'`。 |
| callback | Callback\<void>     | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('answer');
```

### on('hangUp')<sup>11+</sup>

on(type: 'hangUp', callback: Callback\<void>): void;

设置通话挂断的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'hangUp'`：当通话挂断时，触发该事件。 |
| callback | Callback\<void>                                               | 是   | 回调函数                                             |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('hangUp', () => {
  console.info(`on call hangUp`);
});
```

### off('hangUp')<sup>11+</sup>

off(type: 'hangUp', callback?: Callback\<void>): void;

取消通话挂断事件的监听。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'hangUp'`。 |
| callback | Callback\<void>      | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('hangUp');
```

### on('toggleCallMute')<sup>11+</sup>

on(type: 'toggleCallMute', callback: Callback\<void>): void;

设置通话静音的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'toggleCallMute'`：当通话静音或解除静音时，触发该事件。 |
| callback | Callback\<void>                                               | 是   | 回调函数                                             |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.on('toggleCallMute', () => {
  console.info(`on call toggleCallMute`);
});
```

### off('toggleCallMute')<sup>11+</sup>

off(type: 'toggleCallMute', callback?: Callback\<void>): void;

取消通话静音事件的监听。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件是`'toggleCallMute'`。 |
| callback | Callback\<void>    | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |

**示例：**

```ts
currentAVSession.off('toggleCallMute');
```
### stopCasting<sup>10+</sup>

stopCasting(callback: AsyncCallback\<void>): void

结束投播。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.stopCasting((err: BusinessError) => {
  if (err) {
    console.info(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`stopCasting successfully`);
  }
});
```

### stopCasting<sup>10+</sup>

stopCasting(): Promise\<void>

结束投播。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当成功结束投播，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

currentAVSession.stopCasting().then(() => {
  console.info(`stopCasting successfully`);
}).catch((err: BusinessError) => {
  console.info(`stopCasting BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getOutputDeviceSync<sup>10+</sup>

getOutputDeviceSync(): OutputDeviceInfo

使用同步方法获取当前输出设备信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                            | 说明                              |
| ----------------------------------------------- | --------------------------------- |
| [OutputDeviceInfo](#outputdeviceinfo10) | 当前输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID   | 错误信息 |
|---------| --------------------------------------- |
| 6600101 | Session service exception. |
| 6600102 | The session does not exist. |

**示例：**

```ts

try {
  let currentOutputDevice: avSession.OutputDeviceInfo = currentAVSession.getOutputDeviceSync();
} catch (err) {
  console.info(`getOutputDeviceSync error, error code: ${err.code}, error message: ${err.message}`);
}
```

## AVCastControlCommandType<sup>10+</sup>

投播控制器可传递的命令。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称           | 类型   | 说明         |
| -------------- | ------ | ------------ |
| play           | string | 播放         |
| pause          | string | 暂停         |
| stop           | string | 停止         |
| playNext       | string | 下一首       |
| playPrevious   | string | 上一首       |
| fastForward    | string | 快进         |
| rewind         | string | 快退         |
| seek           | numbder | 跳转某一节点 |
| setSpeed       | number | 设置播放倍速 |
| setLoopMode    | string | 设置循环模式 |
| toggleFavorite | string | 是否收藏     |
| setVolume      | number | 设置音量     |

## AVCastControlCommand<sup>10+</sup>

投播控制器接受的命令的对象描述。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称      | 类型                                              | 必填 | 说明           |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVCastControlCommandType](#avcastcontrolcommandtype10)     | 是   | 命令           |
| parameter | [LoopMode](#loopmode10) &#124; string &#124; number | 否   | 命令对应的参数 |

## AVCastController<sup>10+</sup>

在投播建立后，调用[avSession.getAVCastController](#getavcastcontroller10)后，返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。

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

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import media from '@ohos.multimedia.media';
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
  console.info(`setDisplaySurface : SUCCESS`);
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

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import media from '@ohos.multimedia.media';
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
    console.info(`setDisplaySurface BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`setDisplaySurface : SUCCESS`);
  }
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

获取当前的远端播放状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback<[[AVPlaybackState](#avplaybackstate10)\> | 是   | 回调函数，返回远端播放状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.getAVPlaybackState((err: BusinessError, state: avSession.AVPlaybackState) => {
  if (err) {
    console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getAVPlaybackState : SUCCESS`);
  }
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(): Promise\<AVPlaybackState>;

获取当前的远端播放状态。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise<[AVPlaybackState](#avplaybackstate10)\>  | Promise对象。返回远端播放状态。。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {
  console.info(`getAVPlaybackState : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVCastControlCommand): Promise\<void>

通过控制器发送命令到其对应的会话。结果通过Promise异步回调方式返回。


**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | [AVCastControlCommand](#avcastcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avCommand: avSession.AVCastControlCommand = {command:'play'};
// let avCommand = {command:'pause'};
// let avCommand = {command:'stop'};
// let avCommand = {command:'playNext'};
// let avCommand = {command:'playPrevious'};
// let avCommand = {command:'fastForward'};
// let avCommand = {command:'rewind'};
// let avCommand = {command:'seek', parameter:10};
aVCastController.sendControlCommand(avCommand).then(() => {
  console.info(`SendControlCommand successfully`);
}).catch((err: BusinessError) => {
  console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVCastControlCommand, callback: AsyncCallback\<void>): void

通过会话控制器发送命令到其对应的会话。结果通过callback异步回调方式返回。


**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| command  | [AVCastControlCommand](#avcastcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------- |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avCommand: avSession.AVCastControlCommand = {command:'play'};
// let avCommand = {command:'pause'};
// let avCommand = {command:'stop'};
// let avCommand = {command:'playNext'};
// let avCommand = {command:'playPrevious'};
// let avCommand = {command:'fastForward'};
// let avCommand = {command:'rewind'};
// let avCommand = {command:'seek', parameter:10};
aVCastController.sendControlCommand(avCommand, (err: BusinessError) => {
  if (err) {
    console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SendControlCommand successfully`);
  }
});
```

### prepare<sup>10+</sup>

prepare(item: AVQueueItem, callback: AsyncCallback\<void>): void

准备播放媒体资源，即进行播放资源的加载和缓冲。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |   

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

// 设置播放参数，开始播放
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};
// 准备播放，这个不会触发真正的播放，会进行加载和缓冲
aVCastController.prepare(playItem, (err: BusinessError) => {
  if (err) {
    console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`prepare successfully`);
  }
});
```


### prepare<sup>10+</sup>

prepare(item: AVQueueItem): Promise\<void>

准备播放媒体资源，即进行播放资源的加载和缓冲。结果通过Promise异步回调方式返回。


**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600109  | The remote connection is not established. |


**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

// 设置播放参数，开始播放
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};
// 准备播放，这个不会触发真正的播放，会进行加载和缓冲
aVCastController.prepare(playItem).then(() => {
  console.info(`prepare successfully`);
}).catch((err: BusinessError) => {
  console.error(`prepare BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### start<sup>10+</sup>

start(item: AVQueueItem, callback: AsyncCallback\<void>): void

启动播放某个媒体资源。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |   

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

// 设置播放参数，开始播放
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};

// 启动播放
aVCastController.start(playItem, (err: BusinessError) => {
  if (err) {
    console.error(`start BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`start successfully`);
  }
});
```

### start<sup>10+</sup>

start(item: AVQueueItem): Promise\<void>

启动播放某个媒体资源。结果通过Promise异步回调方式返回。


**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| item | [AVQueueItem](#avqueueitem10) | 是   | 播放列表中单项的相关属性。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600109  | The remote connection is not established. |


**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

// 设置播放参数，开始播放
let playItem: avSession.AVQueueItem = {
  itemId: 0,
  description: {
    assetId: '12345',
    mediaType: 'AUDIO',
    mediaUri: 'http://resource1_address',
    mediaSize: 12345,
    startPosition: 0,
    duration: 0,
    artist: 'mysong',
    albumTitle: 'song1_title',
    albumCoverUri: "http://resource1_album_address",
    lyricUri: "http://resource1_lyric_address",
    appName: 'MyMusic'
  }
};
// 启动播放
aVCastController.start(playItem).then(() => {
  console.info(`start successfully`);
}).catch((err: BusinessError) => {
  console.info(`start BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getCurrentItem<sup>10+</sup>

getCurrentItem(callback: AsyncCallback\<AVQueueItem>): void

获取当前投播的资源信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<[AVQueueItem](#avqueueitem10)>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.getCurrentItem((err: BusinessError, value: avSession.AVQueueItem) => {
  if (err) {
    console.error(`getCurrentItem BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getCurrentItem successfully`);
  }
});
```

### getCurrentItem<sup>10+</sup>

getCurrentItem(): Promise\<AVQueueItem>

获取当前投播的资源信息。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<[AVQueueItem](#avqueueitem10)> | Promise对象，返回当前的播放资源，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.getCurrentItem().then((value: avSession.AVQueueItem) => {
  console.info(`getCurrentItem successfully`);
}).catch((err: BusinessError) => {
  console.error(`getCurrentItem BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### release<sup>11+</sup>

release(callback: AsyncCallback\<void>): void

销毁当前controller，结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                                         |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void>       | 是   | 回调函数。当命令执行成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | -------------------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.release((err: BusinessError) => {
  if (err) {
    console.error(`release BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`release successfully`);
  }
});
```

### release<sup>11+</sup>

release(): Promise\<void>

销毁当前controller。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象，controller销毁成功，无结果返回，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

aVCastController.release().then(() => {
  console.info(`release successfully`);
}).catch((err: BusinessError) => {
  console.error(`release BusinessError: code: ${err.code}, message: ${err.message}`);
});

```

### on('playbackStateChange')<sup>10+</sup>

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void): void

设置播放状态变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playbackStateChange'`：当播放状态变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注播放状态所有字段变化；Array<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\> 表示关注Array中的字段变化。 |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void         | 是   | 回调函数，参数state是变化后的播放状态。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('playbackStateChange', 'all', (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});

let playbackFilter = ['state', 'speed', 'loopMode'];
aVCastController.on('playbackStateChange', playbackFilter, (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});
```

### off('playbackStateChange')<sup>10+</sup>

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void): void

媒体控制器取消监听播放状态变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playbackStateChange'`。    |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void         | 否   | 回调函数，参数state是变化后的播放状态。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('playbackStateChange');
```

### on('mediaItemChange')<sup>10+</sup>

on(type: 'mediaItemChange', callback: Callback\<AVQueueItem>): void

设置投播当前播放媒体内容的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'mediaItemChange'`：当播放的媒体内容变化时，触发该事件。 |
| callback | (state: [AVQueueItem](#avqueueitem10)) => void         | 是   | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('mediaItemChange', (item: avSession.AVQueueItem) => {
  console.info(`on mediaItemChange state : ${item.itemId}`);
});
```

### off('mediaItemChange')<sup>10+</sup>

off(type: 'mediaItemChange'): void

取消设置投播当前播放媒体内容的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'mediaItemChange'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('mediaItemChange');
```

### on('playNext')<sup>10+</sup>

on(type: 'playNext', callback: Callback\<void>): void

设置播放下一首资源的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playNext'`：当播放下一首状态变化时，触发该事件。 |
| callback | Callback\<void\>         | 是   | 回调函数                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('playNext', () => {
  console.info(`on playNext`);
});
```

### off('playNext')<sup>10+</sup>

off(type: 'playNext'): void

取消设置播放下一首资源的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playNext'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('playNext');
```

### on('playPrevious')<sup>10+</sup>

on(type: 'playPrevious', callback: Callback\<void>): void

设置播放上一首资源的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playPrevious'`：当播放上一首状态变化时，触发该事件。 |
| callback | Callback\<void\>         | 是   | 回调函数                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('playPrevious', () => {
  console.info(`on playPrevious`);
});
```

### off('playPrevious')<sup>10+</sup>

off(type: 'playPrevious'): void

取消设置播放上一首资源的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playPrevious'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('playPrevious');
```

### on('requestPlay')<sup>11+</sup>

on(type: 'requestPlay', callback: Callback\<AVQueueItem>): void

设置请求播放的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'requestPlay'`：当请求播放状态变化时，触发该事件。 |
| callback | (state: [AVQueueItem](#avqueueitem10)) => void               | 是   | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。当监听事件注册成功，err为undefined，否则返回错误对象。  | 

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('requestPlay', (item: avSession.AVQueueItem) => {
  console.info(`on requestPlay state : ${item.itemId}`);
});
```

### off('requestPlay')<sup>11+</sup>

off(type: 'requestPlay', callback?: Callback\<AVQueueItem>): void

取消设置请求播放的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------| ---- | ----------------------------------------------------- |
| type     | string                                                      | 是   | 取消对应的监听事件，支持事件`'requestPlay'`。    |
| callback | (state: [AVQueueItem](#avqueueitem10)) => void              | 否   | 回调函数，参数AVQueueItem是当前正在播放的媒体内容。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('requestPlay');
```

### on('endOfStream')<sup>11+</sup>

on(type: 'endOfStream', callback: Callback\<void>): void

设置播放结束的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | string                                                      | 是   | 事件回调类型，支持事件`'endOfStream'`：当资源播放结束时，触发该事件。 |
| callback | Callback\<void\>                                            | 是   | 回调函数。当监听事件注册成功，err为undefined，否则返回错误对象。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('endOfStream', () => {
  console.info(`on endOfStream`);
});
```

### off('endOfStream')<sup>11+</sup>

off(type: 'endOfStream', callback?: Callback\<void>): void

取消设置播放结束的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------| ---- | ----------------------------------------------------- |
| type     | string                                                      | 是   | 取消对应的监听事件，支持事件`'endOfStream'`。    |
| callback | Callback\<void\>                                            | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。   |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('endOfStream');
```

### on('seekDone')<sup>10+</sup>

on(type: 'seekDone', callback: Callback\<number>): void

设置seek结束的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'seekDone'`：当seek结束时，触发该事件。 |
| callback | Callback\<number\>         | 是   | 回调函数，返回seek后播放的位置                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.on('seekDone', (pos: number) => {
  console.info(`on seekDone pos：${pos} `);
});
```

### off('seekDone')<sup>10+</sup>

off(type: 'seekDone'): void

取消设置seek结束的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'seekDone'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('seekDone');
```

### on('validCommandChange')<sup>11+</sup>

on(type: 'validCommandChange', callback: Callback\<Array\<AVCastControlCommandType>>)

会话支持的有效命令变化监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'validCommandChange'`：当检测到会话的合法命令发生改变时，触发该事件。 |
| callback | Callback<Array<[AVCastControlCommandType](#avcastcontrolcommandtype10)\>\>   | 是   | 回调函数。参数commands是有效命令的集合。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
aVCastController.on('validCommandChange', (validCommands: avSession.AVCastControlCommandType[]) => {
  console.info(`validCommandChange : SUCCESS : size : ${validCommands.length}`);
  console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});
```

### off('validCommandChange')<sup>11+</sup>

off(type: 'validCommandChange', callback?: Callback\<Array\<AVCastControlCommandType>>)

媒体控制器取消监听会话有效命令变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'validCommandChange'`。         |
| callback | Callback<Array<[AVCastControlCommandType](#avcastcontrolcommandtype10)\>\> | 否   | 回调函数。参数commands是有效命令的集合。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
aVCastController.off('validCommandChange');
```

### on('videoSizeChange')<sup>10+</sup>

on(type: 'videoSizeChange', callback: (width:number, height:number) => void): void

设置video尺寸更改监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string      | 是   | 事件回调类型，支持事件`'videoSizeChange'`：当video尺寸更改时，触发该事件。 |
| callback | (width:number, height:number) => void    | 是   | 回调函数，返回video的宽度和高度     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
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

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型     | 必填 | 说明      |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string  | 是   | 取消对应的监听事件，支持事件`'videoSizeChange'`。    |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |

**示例：**

```ts
aVCastController.off('videoSizeChange');
```

### on('error')<sup>10+</sup>

on(type: 'error', callback: ErrorCallback): void

监听远端播放器的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'error'，用户操作和系统都会触发此事件。 |
| callback | function | 是   | 错误事件回调方法：远端播放过程中发生的错误，会提供错误码ID和错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 5400101  | No memory.            |
| 5400102  | Operation not allowed.   |
| 5400103  | I/O error.             |
| 5400104  | Time out.      |
| 5400105  | Service died.         |
| 5400106  | Unsupport format.     |
| 6600101  | Session service exception.     |

**示例：**

```ts
import { BusinessError } from '@ohos.base'

aVCastController.on('error', (error: BusinessError) => {
  console.error('error happened,and error message is :' + error.message)
  console.error('error happened,and error code is :' + error.code)
})
```

### off('error')<sup>10+</sup>

off(type: 'error'): void

取消监听播放的错误事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | 是   | 错误事件回调类型，取消注册的事件：'error' |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 5400101  | No memory.            |
| 5400102  | Operation not allowed.   |
| 5400103  | I/O error.             |
| 5400104  | Time out.      |
| 5400105  | Service died.         |
| 5400106  | Unsupport format.     |
| 6600101  | Session service exception.     |

**示例：**

```ts
aVCastController.off('error')
```

## ConnectionState<sup>10+</sup>

连接状态枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| STATE_CONNECTING      | 0    | 设备连接中    |
| STATE_CONNECTED      | 1    | 设备连接成功 |
| STATE_DISCONNECTED      | 6    | 设备断开连接 |

## AVMetadata<sup>10+</sup>

媒体元数据的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| assetId         | string                  | 是   | 媒体ID。                                                               |
| title           | string                  | 否   | 标题。                                                                 |
| artist          | string                  | 否   | 艺术家。                                                                |
| author          | string                  | 否   | 专辑作者。                                                               |
| avQueueName<sup>11+</sup>     | string                  | 否   | 歌单（歌曲列表）名称。<br/>此接口为系统接口。<br>  |
| avQueueId<sup>11+</sup>       | string                  | 否   | 歌单（歌曲列表）唯一标识Id。                                                               |
| avQueueImage<sup>11+</sup>    | image.PixelMap[image.PixelMap](js-apis-image.md#pixelmap7) &#124; string | 否   | 歌单（歌曲列表）封面图，图片的像素数据或者图片路径地址(本地路径或网络路径)。  |                       
| album           | string                  | 否   | 专辑名称。                                                               |
| writer          | string                  | 否   | 词作者。                                                                |
| composer        | string                  | 否   | 作曲者。                                                                |
| duration        | number                  | 否   | 媒体时长，单位毫秒（ms）。                                                  |
| mediaImage      | image.PixelMap &#124; string | 否   | 图片的像素数据或者图片路径地址(本地路径或网络路径)。                             |
| publishDate     | Date                    | 否   | 发行日期。                                                               |
| subtitle        | string                  | 否   | 子标题。                                                                |
| description     | string                  | 否   | 媒体描述。                                                               |
| lyric           | string                  | 否   | 歌词文件路径地址(本地路径或网络路径) |
| previousAssetId | string                  | 否   | 上一首媒体ID。                                                            |
| nextAssetId     | string                  | 否   | 下一首媒体ID。                                                            |
| filter<sup>11+</sup>        | number         | 否   | 当前session支持的协议，默认为TYPE_CAST_PLUS_STREAM。具体取值参考[ProtocolType](#protocoltype10)。                   |
| skipIntervals<sup>11+</sup>  | [SkipIntervals](#skipintervals11)        | 否   | 快进快退支持的时间间隔，默认为SECONDS_15，即15秒。                            |
|displayTags<sup>11+</sup>     | [DisplayTag](#displaytag11)                           | 否   | 媒体资源的金标类型。                                                          |

## AVQueueInfo<sup>11+</sup>

歌单（歌曲列表）的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**系统接口：** 该接口为系统接口

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------| ---- |--------------------------------------------------------------------- |
| bundleName      | string                  | 是   | 歌单所属应用包名。                                                        |
| avQueueName     | string                  | 是   | 歌单（歌曲列表）名称。                                                    |
| avQueueId       | string                  | 是   | 歌单（歌曲列表）唯一标识Id。                                               |
| avQueueImage    | image.PixelMap &#124; string |是   | 歌单（歌曲列表）封面图，图片的像素数据或者图片路径地址(本地路径或网络路径)。     |
| lastPlayedTime  | number                  | 否   | 歌单最后播放时间。                                                        |

## AVMediaDescription<sup>10+</sup>

播放列表媒体元数据的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                    | 必填  | 说明                     |
| ------------ | ----------------------- | ---- | ----------------------- |
| assetId      | string                  | 是   | 播放列表媒体ID。          |
| title        | string                  | 否   | 播放列表媒体标题。        |
| subtitle     | string                  | 否   | 播放列表媒体子标题。      |
| description  | string                  | 否   | 播放列表媒体描述的文本。   |
| mediaImage | image.PixelMap          | 否   | 播放列表媒体图片像素数据。 |
| extras       | {[key: string]: any}    | 否   | 播放列表媒体额外字段。     |
| mediaUri     | string                  | 否   | 播放列表媒体URI。         |
| mediaType     | string                  | 否   | 播放列表媒体类型。         |
| mediaSize     | number                  | 否   | 播放列表媒体的大小。         |
| albumTitle     | string                  | 否   | 播放列表媒体专辑标题。         |
| albumCoverUri     | string                  | 否   | 播放列表媒体专辑标题URI。    |
| lyricContent     | string                  | 否   | 播放列表媒体歌词内容。         |
| lyricUri     | string                  | 否   | 播放列表媒体歌词URI。         |
| artist     | string                  | 否   | 播放列表媒体专辑作者。         |
| fdSrc     | media.AVFileDescriptor        | 否   | 播放列表媒体本地文件的句柄。         |
| duration     | number                  | 否   | 播放列表媒体播放时长。         |
| startPosition     | number                  | 否   | 播放列表媒体起始播放位置。         |
| creditsPosition     | number                  | 否   | 播放列表媒体的片尾播放位置。         |
| appName     | string                  | 否   | 播放列表提供的应用的名字。         |

## AVQueueItem<sup>10+</sup>

播放列表中单项的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                                        | 必填 | 说明                        |
| ------------ | ------------------------------------------ | ---- | --------------------------- |
| itemId       | number                                     | 是   | 播放列表中单项的ID。          |
| description  | [AVMediaDescription](#avmediadescription10)  | 是   | 播放列表中单项的媒体元数据。   |

## AVPlaybackState<sup>10+</sup>

媒体播放状态的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                                  | 必填 | 说明     |
| ------------ | ------------------------------------- | ---- | ------- |
| state        | [PlaybackState](#playbackstate)       | 否   | 播放状态 |
| speed        | number                                | 否   | 播放倍速 |
| position     | [PlaybackPosition](#playbackposition) | 否   | 播放位置 |
| bufferedTime | number                                | 否   | 缓冲时间 |
| loopMode     | [LoopMode](#loopmode10)                 | 否   | 循环模式 |
| isFavorite   | boolean                               | 否   | 是否收藏 |
| activeItemId<sup>10+</sup> | number                  | 否   | 正在播放的媒体Id |
| volume<sup>10+</sup> | number                  | 否   | 正在播放的媒体音量 |
| extras<sup>10+</sup> | {[key: string]: Object}       | 否   | 自定义媒体数据 |
| maxVolume<sup>11+</sup> | number                    | 否   | 最大音量 |
| muted<sup>11+</sup>     | boolean                   | 否   | 当前静音状态，true表示静音 |
| videoWidth<sup>11+</sup>  | number                  | 否   | 媒体资源的视频宽度，单位为像素（px）。 |
| videoHeight<sup>11+</sup> |  number                 | 否   | 媒体资源的视频高度，单位为像素（px）。 |

## PlaybackPosition<sup>10+</sup>

媒体播放位置的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称        | 类型   | 必填 | 说明               |
| ----------- | ------ | ---- | ------------------ |
| elapsedTime | number | 是   | 已用时间，单位毫秒（ms）。 |
| updateTime  | number | 是   | 更新时间，单位毫秒（ms）。 |

## CallMetadata<sup>11+</sup>

通话会话元数据相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| name            | string                  | 否    | 来电人姓名（别名）。    |                                                                                                                      
| phoneNumber     | string                  | 否    | 来电电话号码            |                                                   
| avatar          | image.PixelMap[image.PixelMap](js-apis-image.md#pixelmap7)          | 否    | 来电人头像。            |                                                   

## AVCallState<sup>11+</sup>

通话状态相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------  | ---- |---------------------------------------------------------------------|
| state           | CallState[AVCallState](#avcallstate11)                 | 是    | 通话状态。      |                                                                                                                      
| muted           | boolean                   | 是    | 通话mic是否静音|                                                                  
 
## CallState<sup>11+</sup>

表示通话状态的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明      |
| --------------------------  | ---- | -------- |
| CALL_STATE_IDLE             | 0    | 空闲状态   |
| CALL_STATE_INCOMING         | 1    | 来电     |
| CALL_STATE_ACTIVE           | 2    | 接通     |
| CALL_STATE_DIALING          | 3    | 响铃     |
| CALL_STATE_WAITING          | 4    | 等待接通  |
| CALL_STATE_HOLDING          | 5    | 保持     |
| CALL_STATE_DISCONNECTING    | 6    | 挂断     |

## DisplayTag<sup>11+</sup>

枚举，表示当前媒体资源的金标，即应用媒体音源的特殊类型标识。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明           |
| --------------------------  | ---- | ------------ |
| TAG_AUDIO_VIVID             | 1    | AUDIO VIVID  |

## AVCastCategory<sup>10+</sup>

投播的类别枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| CATEGORY_LOCAL      | 0    | 本地播放，默认播放设备，声音从本机或者连接的蓝牙耳机设备出声。     |
| CATEGORY_REMOTE      | 1    | 远端播放，远端播放设备，声音从其他设备发出声音或者画面。  |

## DeviceType<sup>10+</sup>

播放设备的类型枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| DEVICE_TYPE_LOCAL      | 0    | 本地播放类型     |
| DEVICE_TYPE_BLUETOOTH      | 10   | 蓝牙设备  |
| DEVICE_TYPE_TV      | 2    | 电视 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast |
| DEVICE_TYPE_SMART_SPEAKER      | 3   | 音箱设备 <br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast |

## DeviceInfo<sup>10+</sup>

播放设备的相关信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称       | 类型           | 必填 | 说明                   |
| ---------- | -------------- | ---- | ---------------------- |
| castCategory   | AVCastCategory        | 是   | 投播的类别。         |
| deviceId   | string | 是   | 播放设备的ID。  |
| deviceName | string | 是   | 播放设备的名称。    |
| deviceType | DeviceType | 是   | 播放设备的类型。    |
| ipAddress | string | 否   | 播放设备的ip地址。<br/>此接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast     |
| providerId | number | 否   | 播放设备提供商。<br/>此接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast    |
| supportedProtocols<sup>11+</sup> | number | 否   | 播放设备支持的协议。默认为TYPE_LOCAL。具体取值参考[ProtocolType](#protocoltype10)。 **系统能力：** SystemCapability.Multimedia.AVSession.AVCast    |
| authenticationStatus<sup>11+</sup> | number | 否   | 播放设备是否可信。默认为0。0代表设备不可信，1代表设备可信。<br/>此接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast    |

## OutputDeviceInfo<sup>10+</sup>

播放设备的相关信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称       | 类型           | 必填 | 说明                   |
| ---------- | -------------- | ---- | ---------------------- |
| devices | Array\<DeviceInfo\> | 是   | 播放设备的集合。    |

## LoopMode<sup>10+</sup>

表示媒体播放循环模式的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称               | 值   | 说明     |
| ------------------ | ---- | -------- |
| LOOP_MODE_SEQUENCE | 0    | 顺序播放 |
| LOOP_MODE_SINGLE   | 1    | 单曲循环 |
| LOOP_MODE_LIST     | 2    | 表单循环 |
| LOOP_MODE_SHUFFLE  | 3    | 随机播放 |
| LOOP_MODE_CUSTOM<sup>11+</sup>   | 4    | 自定义播放  |

## PlaybackState<sup>10+</sup>

表示媒体播放状态的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| PLAYBACK_STATE_INITIAL      | 0    | 初始状态     |
| PLAYBACK_STATE_PREPARE      | 1    | 播放准备状态  |
| PLAYBACK_STATE_PLAY         | 2    | 正在播放     |
| PLAYBACK_STATE_PAUSE        | 3    | 暂停         |
| PLAYBACK_STATE_FAST_FORWARD | 4    | 快进         |
| PLAYBACK_STATE_REWIND       | 5    | 快退         |
| PLAYBACK_STATE_STOP         | 6    | 停止         |
| PLAYBACK_STATE_COMPLETED    | 7    | 播放完成     |
| PLAYBACK_STATE_RELEASED     | 8    | 释放         |
| PLAYBACK_STATE_ERROR        | 9    | 错误         |
| PLAYBACK_STATE_IDLE<sup>11+</sup>        | 10    | 空闲     |
| PLAYBACK_STATE_BUFFERING<sup>11+</sup>         | 11    | 缓冲   |

## AVSessionDescriptor

会话的相关描述信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

| 名称          | 类型              | 可读 | 可写 | 说明  |
| --------------| ---------------- |-----|-----|------|
| sessionId    | string    | 是  | 否 | 会话ID      |
| type         | [AVSessionType](#avsessiontype10)   | 是   | 否  | 会话类型    |
| sessionTag   | string             | 是   | 否  | 会话的自定义名称    |
| elementName  | [ElementName](js-apis-bundle-ElementName.md)  | 是   | 否  | 会话所属应用的信息（包含bundleName、abilityName等） |
| isActive     | boolean             | 是   | 否  | 会话是否被激活                                      |
| isTopSession | boolean             | 是   | 否  | 会话是否为最新的会话                                |
| outputDevice | [OutputDeviceInfo](#outputdeviceinfo10)    | 是   | 否  | 分布式设备相关信息   |

## AVSessionController<sup>10+</sup>

调用[avSession.createController](#avsessioncreatecontroller)后，返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。

### 属性

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型   | 可读 | 可写 | 说明                                    |
| :-------- | :----- | :--- | :--- | :-------------------------------------- |
| sessionId | string | 是   | 否   | AVSessionController对象唯一的会话标识。 |


**示例：**

```ts
import { BusinessError } from '@ohos.base';

let AVSessionController: avSession.AVSessionController;
avSession.createController(currentAVSession.sessionId).then((controller: avSession.AVSessionController) => {
  AVSessionController = controller;
}).catch((err: BusinessError) => {
  console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

获取当前的远端播放状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback<[[AVPlaybackState](#avplaybackstate10)\> | 是   | 回调函数，返回远端播放状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVPlaybackState((err: BusinessError, state: avSession.AVPlaybackState) => {
  if (err) {
    console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getAVPlaybackState : SUCCESS`);
  }
});
```

### getAVPlaybackState<sup>10+</sup>

getAVPlaybackState(): Promise\<AVPlaybackState>;

获取当前的远端播放状态。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| Promise<[AVPlaybackState](#avplaybackstate10)\>  | Promise对象。返回远端播放状态。  |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVPlaybackState().then((state: avSession.AVPlaybackState) => {
  console.info(`getAVPlaybackState : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`getAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVMetadata<sup>10+</sup>

getAVMetadata(): Promise\<AVMetadata>

获取会话元数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<[AVMetadata](#avmetadata10)\> | Promise对象，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVMetadata().then((metadata: avSession.AVMetadata) => {
  console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVMetadata<sup>10+</sup>

getAVMetadata(callback: AsyncCallback\<AVMetadata>): void

获取会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVMetadata](#avmetadata10)\> | 是   | 回调函数，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVMetadata((err: BusinessError, metadata: avSession.AVMetadata) => {
  if (err) {
    console.error(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
  }
});
```

### getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(): Promise\<string>

获取当前会话播放列表的名称。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型             | 说明                           |
| ---------------- | ----------------------------- |
| Promise<string\> | Promise对象。返回播放列表名称。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVQueueTitle().then((title: string) => {
  console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVQueueTitle<sup>10+</sup>

getAVQueueTitle(callback: AsyncCallback\<string>): void

获取当前播放列表的名称。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                      |
| -------- | ---------------------- | ---- | ------------------------- |
| callback | AsyncCallback<string\> | 是   | 回调函数，返回播放列表名称。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVQueueTitle((err: BusinessError, title: string) => {
  if (err) {
    console.error(`GetAVQueueTitle BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAVQueueTitle : SUCCESS : title : ${title}`);
  }
});
```

### getAVQueueItems<sup>10+</sup>

getAVQueueItems(): Promise\<Array\<AVQueueItem>>

获取当前会话播放列表相关信息。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                          | 说明                           |
| --------------------------------------------- | ----------------------------- |
| Promise<Array<[AVQueueItem](#avqueueitem10)\>\> | Promise对象。返回播放列表队列。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVQueueItems().then((items: avSession.AVQueueItem[]) => {
  console.info(`GetAVQueueItems : SUCCESS : length : ${items.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVQueueItems<sup>10+</sup>

getAVQueueItems(callback: AsyncCallback\<Array\<AVQueueItem>>): void

获取当前播放列表相关信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                      |
| -------- | --------------------------------------------------- | ---- | ------------------------- |
| callback | AsyncCallback<Array<[AVQueueItem](#avqueueitem10)\>\> | 是   | 回调函数，返回播放列表队列。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVQueueItems((err: BusinessError, items: avSession.AVQueueItem[]) => {
  if (err) {
    console.error(`GetAVQueueItems BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetAVQueueItems : SUCCESS : length : ${items.length}`);
  }
});
```

### skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number): Promise\<void>

设置指定播放列表单项的ID，发送给session端处理，session端可以选择对这个单项歌曲进行播放。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明                                        |
| ------ | ------- | ---- | ------------------------------------------- |
| itemId | number  | 是   | 播放列表单项的ID值，用以表示选中的播放列表单项。 |

**返回值：**

| 类型           | 说明                                                             |
| -------------- | --------------------------------------------------------------- |
| Promise\<void> | Promise对象。当播放列表单项ID设置成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let queueItemId = 0;
avsessionController.skipToQueueItem(queueItemId).then(() => {
  console.info(`SkipToQueueItem successfully`);
}).catch((err: BusinessError) => {
  console.error(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### skipToQueueItem<sup>10+</sup>

skipToQueueItem(itemId: number, callback: AsyncCallback\<void>): void

设置指定播放列表单项的ID，发送给session端处理，session端可以选择对这个单项歌曲进行播放。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                        |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| itemId   | number                | 是   | 播放列表单项的ID值，用以表示选中的播放列表单项。                |
| callback | AsyncCallback\<void>  | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let queueItemId = 0;
avsessionController.skipToQueueItem(queueItemId, (err: BusinessError) => {
  if (err) {
    console.error(`SkipToQueueItem BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SkipToQueueItem successfully`);
  }
});
```

### getOutputDevice<sup>10+</sup>

getOutputDevice(): Promise\<OutputDeviceInfo>

获取播放设备信息。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                            | 说明                              |
| ----------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo10)\> | Promise对象，返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 600101  | Session service exception. |
| 600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getOutputDevice().then((deviceInfo: avSession.OutputDeviceInfo) => {
  console.info(`GetOutputDevice : SUCCESS`);
}).catch((err: BusinessError) => {
  console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getOutputDevice<sup>10+</sup>

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

获取播放设备信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                           |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo10)\> | 是   | 回调函数，返回播放设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 600101  | Session service exception. |
| 600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getOutputDevice((err: BusinessError, deviceInfo: avSession.OutputDeviceInfo) => {
  if (err) {
    console.error(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetOutputDevice : SUCCESS`);
  }
});
```

### sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent): Promise\<void>

发送按键事件到控制器对应的会话。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明       |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| event  | [KeyEvent](js-apis-keyevent.md) | 是   | 按键事件。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 600101  | Session service exception. |
| 600102  | The session does not exist. |
| 600103  | The session controller does not exist. |
| 600105  | Invalid session command. |
| 600106  | The session is not activated. |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当事件发送成功，无返回结果，否则返回错误对象。 |

**示例：**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';
import { BusinessError } from '@ohos.base';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avsessionController.sendAVKeyEvent(event).then(() => {
  console.info(`SendAVKeyEvent Successfully`);
}).catch((err: BusinessError) => {
  console.error(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendAVKeyEvent<sup>10+</sup>

sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

发送按键事件到会话。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明       |
| -------- | ------------------------------------------------------------ | ---- | ---------- |
| event    | [KeyEvent](js-apis-keyevent.md) | 是   | 按键事件。 |
| callback | AsyncCallback\<void>                                         | 是   | 回调函数。当事件发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 600101  | Session service exception. |
| 600102  | The session does not exist. |
| 600103  | The session controller does not exist. |
| 600105  | Invalid session command. |
| 600106  | The session is not activated. |

**示例：**

```ts
import keyEvent from '@ohos.multimodalInput.keyEvent';
import { BusinessError } from '@ohos.base';

let keyItem: keyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: keyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avsessionController.sendAVKeyEvent(event, (err: BusinessError) => {
  if (err) {
    console.error(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`SendAVKeyEvent Successfully`);
  }
});
```

### getLaunchAbility<sup>10+</sup>

getLaunchAbility(): Promise\<WantAgent>

获取应用在会话中保存的WantAgent对象。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                    | 说明                                                         |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[WantAgent](js-apis-app-ability-wantAgent.md)\> | Promise对象，返回在[setLaunchAbility](#setlaunchability10)保存的对象，包括应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getLaunchAbility().then((agent: object) => {
  console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
}).catch((err: BusinessError) => {
  console.error(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getLaunchAbility<sup>10+</sup>

getLaunchAbility(callback: AsyncCallback\<WantAgent>): void

获取应用在会话中保存的WantAgent对象。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[WantAgent](js-apis-app-ability-wantAgent.md)\> | 是   | 回调函数。返回在[setLaunchAbility](#setlaunchability10)保存的对象，包括应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getLaunchAbility((err: BusinessError, agent: object) => {
  if (err) {
    console.error(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
  }
});
```

### getRealPlaybackPositionSync<sup>10+</sup>

getRealPlaybackPositionSync(): number

获取当前播放位置。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 时间节点，毫秒数。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
let time: number = avsessionController.getRealPlaybackPositionSync();
```

### isActive<sup>10+</sup>

isActive(): Promise\<boolean>

获取会话是否被激活。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise<boolean\> | Promise对象，返回会话是否为激活状态，true表示被激活，false表示禁用。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.isActive().then((isActive: boolean) => {
  console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
}).catch((err: BusinessError) => {
  console.error(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### isActive<sup>10+</sup>

isActive(callback: AsyncCallback\<boolean>): void

判断会话是否被激活。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<boolean\> | 是   | 回调函数，返回会话是否为激活状态，true表示被激活，false表示禁用。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.isActive((err: BusinessError, isActive: boolean) => {
  if (err) {
    console.error(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
  }
});
```

### destroy<sup>10+</sup>

destroy(): Promise\<void>

销毁当前控制器，销毁后当前控制器不可再用。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当控制器销毁成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.destroy().then(() => {
  console.info(`Destroy : SUCCESS `);
}).catch((err: BusinessError) => {
  console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### destroy<sup>10+</sup>

destroy(callback: AsyncCallback\<void>): void

销毁当前控制器，销毁后当前控制器不可再用。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当控制器销毁成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.destroy((err: BusinessError) => {
  if (err) {
    console.error(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`Destroy : SUCCESS `);
  }
});
```

### getValidCommands<sup>10+</sup>

getValidCommands(): Promise\<Array\<AVControlCommandType>>

获取会话支持的有效命令。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<Array<[AVControlCommandType](#avcontrolcommandtype10)\>\> | Promise对象。返回有效命令的集合。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getValidCommands().then((validCommands: avSession.AVControlCommandType[]) => {
  console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
}).catch((err: BusinessError) => {
  console.error(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getValidCommands<sup>10+</sup>

getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void

获取会话支持的有效命令。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<[AVControlCommandType](#avcontrolcommandtype10)\>\> | 是   | 回调函数，返回有效命令的集合。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getValidCommands((err: BusinessError, validCommands: avSession.AVControlCommandType[]) => {
  if (err) {
    console.error(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
  }
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVControlCommand): Promise\<void>

通过控制器发送命令到其对应的会话。结果通过Promise异步回调方式返回。

> **说明：**
>
> 媒体控制方在使用sendControlCommand命令前，需要确保控制对应的媒体会话注册了对应的监听，注册媒体会话相关监听的方法请参见接口[on'play'](#onplay10)、[on'pause'](#onpause10)等。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | [AVControlCommand](#avcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avCommand: avSession.AVControlCommand = {command:'play'};
// let avCommand = {command:'pause'};
// let avCommand = {command:'stop'};
// let avCommand = {command:'playNext'};
// let avCommand = {command:'playPrevious'};
// let avCommand = {command:'fastForward'};
// let avCommand = {command:'rewind'};
// let avCommand = {command:'seek', parameter:10};
// let avCommand = {command:'setSpeed', parameter:2.6};
// let avCommand = {command:'setLoopMode', parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let avCommand = {command:'toggleFavorite', parameter:"false"};
avsessionController.sendControlCommand(avCommand).then(() => {
  console.info(`SendControlCommand successfully`);
}).catch((err: BusinessError) => {
  console.error(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand<sup>10+</sup>

sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

通过会话控制器发送命令到其对应的会话。结果通过callback异步回调方式返回。

> **说明：**
>
> 媒体控制方在使用sendControlCommand命令前，需要确保控制对应的媒体会话注册了对应的监听，注册媒体会话相关监听的方法请参见接口[on'play'](#onplay10)、[on'pause'](#onpause10)等。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| command  | [AVControlCommand](#avcontrolcommand10) | 是   | 会话的相关命令和命令相关参数。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------- |
| 6600101  | Session service exception.                |
| 6600102  | The session does not exist.     |
| 6600103  | The session controller does not exist.   |
| 6600105  | Invalid session command.           |
| 6600106  | The session is not activated.                |
| 6600107  | Too many commands or events.      |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avCommand: avSession.AVControlCommand = {command:'play'};
// let avCommand = {command:'pause'};
// let avCommand = {command:'stop'};
// let avCommand = {command:'playNext'};
// let avCommand = {command:'playPrevious'};
// let avCommand = {command:'fastForward'};
// let avCommand = {command:'rewind'};
// let avCommand = {command:'seek', parameter:10};
// let avCommand = {command:'setSpeed', parameter:2.6};
// let avCommand = {command:'setLoopMode', parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let avCommand = {command:'toggleFavorite', parameter:"false"};
avsessionController.sendControlCommand(avCommand, (err: BusinessError) => {
  if (err) {
    console.info(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.error(`SendControlCommand successfully`);
  }
});
```

### sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}): Promise\<void>

通过会话控制器发送自定义控制命令到其对应的会话。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | string | 是   | 需要设置的自定义控制命令的名称 |
| args | {[key: string]: any} | 是   | 需要传递的控制命令键值对 |

> **说明：**
> 参数args支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md)。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600106  | The session is not activated. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);
let sessionId: string = "";
avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  sessionId = (currentAVSession as avSession.AVSession).sessionId;
  avSession.createController(sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

let commandName = "my_command";
if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}).then(() => {
    console.info(`SendCommonCommand successfully`);
  }).catch((err: BusinessError) => {
    console.info(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
  })
}
```

### sendCommonCommand<sup>10+</sup>

sendCommonCommand(command: string, args: {[key: string]: Object}, callback: AsyncCallback\<void>): void

通过会话控制器发送自定义命令到其对应的会话。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | string | 是   | 需要设置的自定义控制命令的名称 |
| args | {[key: string]: any} | 是   | 需要传递的控制命令键值对 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。                     |

> **说明：**
> 参数args支持的数据类型有：字符串、数字、布尔、对象、数组和文件描述符等，详细介绍请参见[@ohos.app.ability.Want(Want)](./js-apis-app-ability-want.md)。

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------- |
| 6600101  | Session service exception.                |
| 6600102  | The session does not exist.     |
| 6600103  | The session controller does not exist.   |
| 6600105  | Invalid session command.           |
| 6600106  | The session is not activated.                |
| 6600107  | Too many commands or events.      |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';
let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

let commandName = "my_command";
if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).sendCommonCommand(commandName, {command : "This is my command"}, (err: BusinessError) => {
    if(err) {
        console.info(`SendCommonCommand BusinessError: code: ${err.code}, message: ${err.message}`);
    }
  })
}
```

### getExtras<sup>10+</sup>

getExtras(): Promise\<{[key: string]: Object}>

获取媒体提供方设置的自定义媒体数据包。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<{[key: string]: Object}\>   | Promise对象，返回媒体提供方设置的自定义媒体数据包，数据包的内容与setExtras设置的内容完全一致。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).getExtras().then((extras) => {
    console.info(`getExtras : SUCCESS : ${extras}`);
  }).catch((err: BusinessError) => {
    console.info(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}
```

### getExtras<sup>10+</sup>

getExtras(callback: AsyncCallback\<{[key: string]: Object}>): void

获取媒体提供方设置的自定义媒体数据包,结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<{[key: string]: Object}\> | 是   | 回调函数，返回媒体提供方设置的自定义媒体数据包，数据包的内容与setExtras设置的内容完全一致。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |
| 6600105  | Invalid session command. |
| 6600107  | Too many commands or events. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).getExtras((err, extras) => {
    if (err) {
      console.error(`getExtras BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
      console.info(`getExtras : SUCCESS : ${extras}`);
    }
  });
}
```

### on('metadataChange')<sup>10+</sup>

on(type: 'metadataChange', filter: Array\<keyof AVMetadata> | 'all', callback: (data: AVMetadata) => void)

设置元数据变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'metadataChange'`：当元数据变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[AVMetadata](#avmetadata10)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注元数据所有字段变化；Array<keyof&nbsp;[AVMetadata](#avmetadata10)\> 表示关注Array中的字段变化。 |
| callback | (data: [AVMetadata](#avmetadata10)) => void                    | 是   | 回调函数，参数data是变化后的元数据。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('metadataChange', 'all', (metadata: avSession.AVMetadata) => {
  console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

avsessionController.on('metadataChange', ['assetId', 'title', 'description'], (metadata: avSession.AVMetadata) => {
  console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

```

### off('metadataChange')<sup>10+</sup>

off(type: 'metadataChange', callback?: (data: AVMetadata) => void)

媒体控制器取消监听元数据变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                                                    |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------ |
| type     | string                                           | 是   | 取消对应的监听事件，支持事件`'metadataChange'`。         |
| callback | (data: [AVMetadata](#avmetadata10)) => void        | 否   | 回调函数，参数data是变化后的元数据。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('metadataChange');
```

### on('playbackStateChange')<sup>10+</sup>

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void)

设置播放状态变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明      |
| --------| -----------|-----|------------|
| type     | string    | 是   | 事件回调类型，支持事件`'playbackStateChange'`：当播放状态变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注播放状态所有字段变化；Array<keyof&nbsp;[AVPlaybackState](#avplaybackstate10)\> 表示关注Array中的字段变化。 |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void       | 是   | 回调函数，参数state是变化后的播放状态。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('playbackStateChange', 'all', (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});

avsessionController.on('playbackStateChange', ['state', 'speed', 'loopMode'], (playbackState: avSession.AVPlaybackState) => {
  console.info(`on playbackStateChange state : ${playbackState.state}`);
});
```

### off('playbackStateChange')<sup>10+</sup>

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void)

媒体控制器取消监听播放状态变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playbackStateChange'`。    |
| callback | (state: [AVPlaybackState](#avplaybackstate10)) => void         | 否   | 回调函数，参数state是变化后的播放状态。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('playbackStateChange');
```

### on('callMetadataChange')<sup>11+</sup>

on(type: 'callMetadataChange', filter: Array\<keyof CallMetadata> | 'all', callback: Callback\<CallMetadata>): void;

设置通话元数据变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明      |
| --------| -----------|-----|------------|
| type     | string    | 是   | 事件回调类型，支持事件`'callMetadataChange'`：当通话元数据变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[CallMetadata](#callmetadata11)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注通话元数据所有字段变化；Array<keyof&nbsp;[CallMetadata](#callmetadata11)\> 表示关注Array中的字段变化。 |
| callback | Callback<[CallMetadata](#callmetadata11)\>\>   | 是   | 回调函数，参数callmetadata是变化后的通话元数据。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('callMetadataChange', 'all', (callmetadata: avSession.CallMetadata) => {
  console.info(`on callMetadataChange state : ${callmetadata.name}`);
});

avsessionController.on('callMetadataChange', ['name'], (callmetadata: avSession.CallMetadata) => {
  console.info(`on callMetadataChange state : ${callmetadata.state}`);
});
```

### off('callMetadataChange')<sup>11+</sup>

off(type: 'callMetadataChange', callback?: Callback\<CallMetadata>): void;

取消设置通话元数据变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'callMetadataChange'`。    |
| callback | Callback<[CallMetadata](#callmetadata11)\>       | 否   | 回调函数，参数calldata是变化后的通话原数据。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('callMetadataChange');
```

### on('callStateChange')<sup>11+</sup>

on(type: 'callStateChange', filter: Array\<keyof AVCallState> | 'all', callback: Callback\<AVCallState>): void;

设置通话状态变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明      |
| --------| -----------|-----|------------|
| type     | string    | 是   | 事件回调类型，支持事件`'callMetadataChange'`：当通话元数据变化时，触发该事件。 |
| filter   | Array<keyof&nbsp;[AVCallState](#avcallstate11)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注通话状态所有字段变化；Array<keyof&nbsp;[AVCallState](#avcallstate11)\> 表示关注Array中的字段变化。 |
| callback | Callback<[AVCallState](#avcallstate11)\>       | 是   | 回调函数，参数callstate是变化后的通话状态。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('callStateChange', 'all', (callstate: avSession.AVCallState) => {
  console.info(`on callStateChange state : ${callstate.state}`);
});

avsessionController.on('callStateChange', ['state'], (callstate: avSession.AVCallState) => {
  console.info(`on callStateChange state : ${callstate.state}`);
});
```

### off('callStateChange')<sup>11+</sup>

off(type: 'callStateChange', callback?: Callback\<AVCallState>): void;

取消设置通话状态变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'callMetadataChange'`。    |
| callback | Callback<[AVCallState](#avcallstate11)\>           | 否   | 回调函数，参数callstate是变化后的通话原数据。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('callMetadataChange');
```

### on('sessionDestroy')<sup>10+</sup>

on(type: 'sessionDestroy', callback: () => void)

会话销毁的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                         |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | 是   | 事件回调类型，支持事件`'sessionDestroy'`：当检测到会话销毁时，触发该事件）。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。                  |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('sessionDestroy', () => {
  console.info(`on sessionDestroy : SUCCESS `);
});
```

### off('sessionDestroy')<sup>10+</sup>

off(type: 'sessionDestroy', callback?: () => void)

媒体控制器取消监听会话的销毁事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                      |
| -------- | ---------- | ---- | ----------------------------------------------------- |
| type     | string     | 是   | 取消对应的监听事件，支持事件`'sessionDestroy'`。         |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                                               |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('sessionDestroy');
```

### on('activeStateChange')<sup>10+</sup>

on(type: 'activeStateChange', callback: (isActive: boolean) => void)

会话的激活状态的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                      | 是   | 事件回调类型，支持事件`'activeStateChange'`：当检测到会话的激活状态发生改变时，触发该事件。 |
| callback | (isActive: boolean) => void | 是   | 回调函数。参数isActive表示会话是否被激活。true表示被激活，false表示禁用。                   |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------- |
| 6600101  | Session service exception. |
| 6600103  |The session controller does not exist. |

**示例：**

```ts
avsessionController.on('activeStateChange', (isActive: boolean) => {
  console.info(`on activeStateChange : SUCCESS : isActive ${isActive}`);
});
```

### off('activeStateChange')<sup>10+</sup>

off(type: 'activeStateChange', callback?: (isActive: boolean) => void)

媒体控制器取消监听会话激活状态变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                      |
| -------- | --------------------------- | ---- | ----------------------------------------------------- |
| type     | string                      | 是   | 取消对应的监听事件，支持事件`'activeStateChange'`。      |
| callback | (isActive: boolean) => void | 否   | 回调函数。参数isActive表示会话是否被激活。true表示被激活，false表示禁用。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                   |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('activeStateChange');
```

### on('validCommandChange')<sup>10+</sup>

on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void)

会话支持的有效命令变化监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'validCommandChange'`：当检测到会话的合法命令发生改变时，触发该事件。 |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype10)\>) => void | 是   | 回调函数。参数commands是有效命令的集合。                     |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('validCommandChange', (validCommands: avSession.AVControlCommandType[]) => {
  console.info(`validCommandChange : SUCCESS : size : ${validCommands.length}`);
  console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});
```

### off('validCommandChange')<sup>10+</sup>

off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void)

媒体控制器取消监听会话有效命令变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'validCommandChange'`。         |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype10)\>) => void | 否   | 回调函数。参数commands是有效命令的集合。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('validCommandChange');
```

### on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: (state: ConnectionState, device: OutputDeviceInfo) => void): void

设置播放设备变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | 是   | 事件回调类型，支持事件为`'outputDeviceChange'`：当播放设备变化时，触发该事件）。 |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | 是   | 回调函数，参数device是设备相关信息。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('outputDeviceChange', (state: avSession.ConnectionState, device: avSession.OutputDeviceInfo) => {
  console.info(`on outputDeviceChange state: ${state}, device : ${device}`);
});
```

### off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: (state: ConnectionState, device: OutputDeviceInfo) => void): void

媒体控制器取消监听分布式设备变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                      |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | 是   | 取消对应的监听事件，支持事件`'outputDeviceChange'`。      |
| callback | (state: [ConnectionState](#connectionstate10), device: [OutputDeviceInfo](#outputdeviceinfo10)) => void | 否   | 回调函数，参数device是设备相关信息。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                         |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID  | 错误信息          |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('outputDeviceChange');
```

### on('sessionEvent')<sup>10+</sup>

on(type: 'sessionEvent', callback: (sessionEvent: string, args: {[key:string]: Object}) => void): void

媒体控制器设置会话自定义事件变化的监听器。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'sessionEvent'`：当会话事件变化时，触发该事件。 |
| callback | (sessionEvent: string, args: {[key:string]: object}) => void         | 是   | 回调函数，sessionEvent为变化的会话事件名，args为事件的参数。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).on('sessionEvent', (sessionEvent, args) => {
    console.info(`OnSessionEvent, sessionEvent is ${sessionEvent}, args: ${JSON.stringify(args)}`);
  });
}
```

### off('sessionEvent')<sup>10+</sup>

off(type: 'sessionEvent', callback?: (sessionEvent: string, args: {[key:string]: Object}) => void): void

媒体控制器取消监听会话事件的变化通知。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'sessionEvent'`。    |
| callback | (sessionEvent: string, args: {[key:string]: Object}) => void         | 否   | 回调函数，参数sessionEvent是变化的事件名，args为事件的参数。<br>该参数为可选参数，若不填写该参数，则认为取消所有对sessionEvent事件的监听。                      |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('sessionEvent');
```

### on('queueItemsChange')<sup>10+</sup>

on(type: 'queueItemsChange', callback: (items: Array<[AVQueueItem](#avqueueitem10)\>) => void): void

媒体控制器设置会话自定义播放列表变化的监听器。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明                                                                         |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| type     | string                                                | 是   | 事件回调类型，支持事件`'queueItemsChange'`：当session修改播放列表时，触发该事件。 |
| callback | (items: Array<[AVQueueItem](#avqueueitem10)\>) => void  | 是   | 回调函数，items为变化的播放列表。                            |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('queueItemsChange', (items: avSession.AVQueueItem[]) => {
  console.info(`OnQueueItemsChange, items length is ${items.length}`);
});
```

### off('queueItemsChange')<sup>10+</sup>

off(type: 'queueItemsChange', callback?: (items: Array<[AVQueueItem](#avqueueitem10)\>) => void): void

媒体控制器取消监听播放列表变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                                 | 必填 | 说明                                                                                                |
| -------- | ---------------------------------------------------- | ---- | --------------------------------------------------------------------------------------------------- |
| type     | string                                               | 是   | 取消对应的监听事件，支持事件`'queueItemsChange'`。                                                     |
| callback | (items: Array<[AVQueueItem](#avqueueitem10)\>) => void | 否   | 回调函数，参数items是变化的播放列表。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('queueItemsChange');
```

### on('queueTitleChange')<sup>10+</sup>

on(type: 'queueTitleChange', callback: (title: string) => void): void

媒体控制器设置会话自定义播放列表的名称变化的监听器。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                                             |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------- |
| type     | string                  | 是   | 事件回调类型，支持事件`'queueTitleChange'`：当session修改播放列表名称时，触发该事件。 |
| callback | (title: string) => void | 是   | 回调函数，title为变化的播放列表名称。                                |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.on('queueTitleChange', (title: string) => {
  console.info(`queueTitleChange, title is ${title}`);
});
```

### off('queueTitleChange')<sup>10+</sup>

off(type: 'queueTitleChange', callback?: (title: string) => void): void

媒体控制器取消监听播放列表名称变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------------------------------- |
| type     | string                  | 是   | 取消对应的监听事件，支持事件`'queueTitleChange'`。                                                         |
| callback | (title: string) => void | 否   | 回调函数，参数items是变化的播放列表名称。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('queueTitleChange');
```

### on('extrasChange')<sup>10+</sup>

on(type: 'extrasChange', callback: (extras: {[key:string]: Object}) => void): void

媒体控制器设置自定义媒体数据包事件变化的监听器。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'extrasChange'`：当媒体提供方设置自定义媒体数据包时，触发该事件。 |
| callback | (extras: {[key:string]: object}) => void         | 是   | 回调函数，extras为媒体提供方新设置的自定义媒体数据包，该自定义媒体数据包与dispatchSessionEvent方法设置的数据包完全一致。          |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import avSession from '@ohos.multimedia.avsession';
import { BusinessError } from '@ohos.base';

let avSessionController: avSession.AVSessionController | undefined = undefined;
let currentAVSession: avSession.AVSession | undefined = undefined;
let tag = "createNewSession";
let context: Context = getContext(this);

avSession.createAVSession(context, tag, "audio", (err: BusinessError, data: avSession.AVSession) => {
  if (err) {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    currentAVSession = data;
  }
});
if (currentAVSession !== undefined) {
  avSession.createController((currentAVSession as avSession.AVSession).sessionId).then((controller: avSession.AVSessionController) => {
    avSessionController = controller;
  }).catch((err: BusinessError) => {
    console.error(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
  });
}

if (avSessionController !== undefined) {
  (avSessionController as avSession.AVSessionController).on('extrasChange', (extras) => {
    console.info(`Caught extrasChange event,the new extra is: ${JSON.stringify(extras)}`);
  });
}
```

### off('extrasChange')<sup>10+</sup>

off(type: 'extrasChange', callback?: (extras: {[key:string]: Object}) => void): void

媒体控制器取消监听自定义媒体数据包变化事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------------------------------------------------------- |
| type     | string                  | 是   | 取消对应的监听事件，支持事件`'extrasChange'`。                                                         |
| callback | ({[key:string]: Object}) => void | 否   | 注册监听事件时的回调函数。<br>该参数为可选参数，若不填写该参数，则认为取消会话所有与此事件相关的监听。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------                       |
| 6600101  | Session service exception.             |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
avsessionController.off('extrasChange');
```

### getAVPlaybackStateSync<sup>10+</sup>

getAVPlaybackStateSync(): AVPlaybackState;

使用同步方法获取当前会话的播放状态。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                        | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| [AVPlaybackState](#avplaybackstate10)  | 当前会话的播放状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts

try {
  let playbackState: avsession.AVPlaybackState = avsessionController.getAVPlaybackStateSync();
} catch (err) {
  console.info(`getAVPlaybackStateSync error, error code: ${err.code}, error message: ${err.message}`);
}
```

### getAVMetadataSync<sup>10+</sup>

getAVMetadataSync(): AVMetadata

使用同步方法获取会话元数据。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| [AVMetadata](#avmetadata10) | 会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**
```ts

try {
  let metaData: avsession.AVMetadata = avsessionController.getAVMetadataSync();
} catch (err) {
  console.info(`getAVMetadataSync error, error code: ${err.code}, error message: ${err.message}`);
}
```

### getAVCallState<sup>11+</sup>

getAVCallState(): Promise\<AVCallState>

获取通话状态数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<[AVCallState](#avcallstate11)\> | Promise对象，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVCallState().then((callstate: avSession.AVCallState) => {
  console.info(`getAVCallState : SUCCESS : state : ${callstate.state}`);
}).catch((err: BusinessError) => {
  console.error(`getAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVCallState<sup>11+</sup>

getAVCallState(callback: AsyncCallback\<AVCallState>): void

获取通话状态数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVCallState](#avcallstate11)\> | 是   | 回调函数，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getAVCallState((err: BusinessError, callstate: avSession.AVCallState) => {
  if (err) {
    console.error(`getAVCallState BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getAVCallState : SUCCESS : state : ${callstate.state}`);
  }
});
```

### getCallMetadata<sup>11+</sup>

getCallMetadata(): Promise\<CallMetadata>

获取通话会话的元数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<[CallMetadata](#callmetadata11)\> | Promise对象，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getCallMetadata().then((calldata: avSession.CallMetadata) => {
  console.info(`getCallMetadata : SUCCESS : name : ${calldata.name}`);
}).catch((err: BusinessError) => {
  console.error(`getCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getCallMetadata<sup>11+</sup>

getCallMetadata(callback: AsyncCallback\<CallMetadata>): void

获取通话会话的元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[CallMetadata](#callmetadata11)\> | 是   | 回调函数，返回会话元数据。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

avsessionController.getCallMetadata((err: BusinessError, calldata: avSession.CallMetadata) => {
  if (err) {
    console.error(`getCallMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
  } else {
    console.info(`getCallMetadata : SUCCESS : name : ${calldata.name}`);
  }
});
```

### getAVQueueTitleSync<sup>10+</sup>

getAVQueueTitleSync(): string

使用同步方法获取当前会话播放列表的名称。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型             | 说明                           |
| ---------------- | ----------------------------- |
| string | 当前会话播放列表名称。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts

try {
  let currentQueueTitle: string = avsessionController.getAVQueueTitleSync();
} catch (err) {
  console.info(`getAVQueueTitleSync error, error code: ${err.code}, error message: ${err.message}`);
}
```

### getAVQueueItemsSync<sup>10+</sup>

getAVQueueItemsSync(): Array\<AVQueueItem\>

使用同步方法获取当前会话播放列表相关信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                          | 说明                           |
| --------------------------------------------- | ----------------------------- |
| Array<[AVQueueItem](#avqueueitem10)\> | 当前会话播放列表队列。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts

try {
  let currentQueueItems: Array<avsession.AVQueueItem> = avsessionController.getAVQueueItemsSync();
} catch (err) {
  console.info(`getAVQueueItemsSync error, error code: ${err.code}, error message: ${err.message}`);
}
```

### getOutputDeviceSync<sup>10+</sup>

getOutputDeviceSync(): OutputDeviceInfo

使用同步方法获取当前输出设备信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                            | 说明                              |
| ----------------------------------------------- | --------------------------------- |
| [OutputDeviceInfo](#outputdeviceinfo10) | 当前输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts

try {
  let currentOutputDevice: avSession.OutputDeviceInfo = avsessionController.getOutputDeviceSync();
} catch (err) {
  console.info(`getOutputDeviceSync error, error code: ${err.code}, error message: ${err.message}`);
}
```

### isActiveSync<sup>10+</sup>

isActiveSync(): boolean

使用同步方法判断会话是否被激活。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| boolean | 会话是否为激活状态，true表示被激活，false表示禁用。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts

try {
  let isActive: boolean = avsessionController.isActiveSync();
} catch (err) {
  console.info(`isActiveSync error, error code: ${err.code}, error message: ${err.message}`);
}
```

### getValidCommandsSync<sup>10+</sup>

getValidCommandsSync(): Array\<AVControlCommandType\>

使用同步方法获取会话支持的有效命令。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Array<[AVControlCommandType](#avcontrolcommandtype10)\> | 会话支持的有效命令的集合。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600103  | The session controller does not exist. |

**示例：**

```ts

try {
  let validCommands: Array<avSession.AVControlCommandType> = avsessionController.getValidCommandsSync();
} catch (err) {
  console.info(`getValidCommandsSync error, error code: ${err.code}, error message: ${err.message}`);
}
```

## AVControlCommandType<sup>10+</sup>

会话可传递的命令。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称           | 类型   | 说明         |
| -------------- | ------ | ------------ |
| play           | string | 播放         |
| pause          | string | 暂停         |
| stop           | string | 停止         |
| playNext       | string | 下一首       |
| playPrevious   | string | 上一首       |
| fastForward    | string | 快进         |
| rewind         | string | 快退         |
| seek           | string | 跳转某一节点 |
| setSpeed       | string | 设置播放倍速 |
| setLoopMode    | string | 设置循环模式 |
| toggleFavorite | string | 是否收藏     |

## AVControlCommand<sup>10+</sup>

会话接受的命令的对象描述。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型                                              | 必填 | 说明           |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVControlCommandType](#avcontrolcommandtype10)     | 是   | 命令           |
| parameter | [LoopMode](#loopmode10) &#124; string &#124; number | 否   | 命令对应的参数 |

## AVSessionErrorCode<sup>10+</sup>

会话发生错误时的错误码。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                                   | 值      | 说明                             |
| -------------------------------------- | ------- | ------------------------------- |
| ERR_CODE_SERVICE_EXCEPTION             | 6600101 | Session service exception.               |
| ERR_CODE_SESSION_NOT_EXIST             | 6600102 | The session does not exist.      |
| ERR_CODE_CONTROLLER_NOT_EXIST          | 6600103 | The session controller does not exist.   |
| ERR_CODE_REMOTE_CONNECTION_ERR         | 6600104 | The remote session  connection failed.         |
| ERR_CODE_COMMAND_INVALID               | 6600105 | Invalid session command.           |
| ERR_CODE_SESSION_INACTIVE              | 6600106 | The session is not activated.                |
| ERR_CODE_MESSAGE_OVERLOAD              | 6600107 | Too many commands or events.       |
| ERR_CODE_DEVICE_CONNECTION_FAILED      | 6600108 | Device connecting failed.       |
| ERR_CODE_REMOTE_CONNECTION_NOT_EXIST   | 6600109 | The remote connection is not established.       |

## SkipIntervals<sup>11+</sup>

表示session支持的快进快退时间间隔。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                   | 值 | 说明                     |
| ---------------------- | -- | ----------------------- |
| SECONDS_10             | 10 | 时间为10秒。             |
| SECONDS_15             | 15 | 时间为15秒。             |
| SECONDS_30             | 30 | 时间为30秒。             |
