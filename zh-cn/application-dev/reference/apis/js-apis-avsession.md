 # 媒体会话管理

媒体会话管理提供媒体播控相关功能的接口，目的是让应用接入播控中心。

该模块提供以下媒体会话相关的常用功能：
- [AVSession](#section652893) : 会话，可用于设置元数据、播放状态信息等操作。
- [AVSessionController](#section974602): 会话控制器，可用于查看会话ID，完成对会话发送命令及事件，获取会话元数据、播放状态信息等操作。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import avSession from '@ohos.multimedia.avsession';
```

## avSession.createAVSession

createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>

创建会话对象，一个Ability只能存在一个会话，重复创建会失败，结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                           |
| ------ | ------------------------------- | ---- | ------------------------------ |
| context| [Context](../../ability/context-userguide.md) | 是| 应用上下文，提供获取应用程序环境信息的能力。 |
| tag    | string                          | 是   | 会话的自定义名称。             |
| type   | [AVSessionType](#avsessiontype) | 是   | 会话类型，当前支持音频和视频。 |


**返回值：**

| 类型                              | 说明                                                         |
| --------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSession](#avsession)\> | Promise对象。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。|


**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility';

let session;
let tag = "createNewSession";
let type = "audio";
let context = featureAbility.getContext();

await avSession.createAVSession(context, tag, type).then((data) => {
    session = data;
    console.info(`CreateAVSession : SUCCESS : sessionId = ${session.sessionId}`);
}).catch((err) => {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.createAVSession

createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void

创建会话对象，一个Ability只能存在一个会话，重复创建会失败，结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context| [Context](../../ability/context-userguide.md) | 是| 应用上下文，提供获取应用程序环境信息的能力。     |
| tag      | string                                  | 是   | 会话的自定义名称。                                           |
| type     | [AVSessionType](#avsessiontype)         | 是   | 会话类型，当前支持音频和视频。                               |
| callback | AsyncCallback<[AVSession](#avsession)\> | 是   | 回调函数。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility';

let session;
let tag = "createNewSession";
let type = "audio";
let context = featureAbility.getContext();

avSession.createAVSession(context, tag, type, function (err, data) {
    if (err) {
        console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        session = data;
        console.info(`CreateAVSession : SUCCESS : sessionId = ${session.sessionId}`);
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
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```js
avSession.getAllSessionDescriptors().then((descriptors) => {
    console.info(`getAllSessionDescriptors : SUCCESS : descriptors.length : ${descriptors.length}`);
    if(descriptors.length > 0 ){
        console.info(`getAllSessionDescriptors : SUCCESS : descriptors[0].isActive : ${descriptors[0].isActive}`);
        console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].type : ${descriptors[0].type}`);
        console.info(`GetAllSessionDescriptors : SUCCESS : descriptors[0].sessionTag : ${descriptors[0].sessionTag}`);
    }
}).catch((err) => {
    console.info(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

## avSession.getAllSessionDescriptors

getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void

获取所有会话的相关描述。结果通过callback异步回调方式返回。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](#avsessiondescriptor)\>\>\> | 是   | 回调函数。返回所有会话描述的只读对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  |Session service exception |

**示例：**

```js
avSession.getAllSessionDescriptors(function (err, descriptors) {
    if (err) {
        console.info(`GetAllSessionDescriptors BusinessError: code: ${err.code}, message: ${err.message}`);
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
| Promise<[AVSessionController](#avsessioncontroller)\> | Promise对象。返回会话控制器实例，可查看会话ID，<br>并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。|

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility';

let session;
let tag = "createNewSession";
let type = "audio";
let context = featureAbility.getContext();

await avSession.createAVSession(context, tag, type).then((data) => {
    session = data;
    console.info(`CreateAVSession : SUCCESS : sessionId = ${session.sessionId}`);
}).catch((err) => {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
});

let controller;
await avSession.createController(session.sessionId).then((avcontroller) => {
    controller = avcontroller;
    console.info(`CreateController : SUCCESS : ${controller.sessionId}`);
}).catch((err) => {
    console.info(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
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
| callback  | AsyncCallback<[AVSessionController](#avsessioncontroller)\> | 是   | 回调函数。返回会话控制器实例，可查看会话ID，<br>并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
import featureAbility from '@ohos.ability.featureAbility';

let session;
let tag = "createNewSession";
let type = "audio";
let context = featureAbility.getContext();

await avSession.createAVSession(context, tag, type).then((data) => {
    session = data;
    console.info(`CreateAVSession : SUCCESS : sessionId = ${session.sessionId}`);
}).catch((err) => {
    console.info(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
});

let controller;
avSession.createController(session.sessionId, function (err, avcontroller) {
    if (err) {
        console.info(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        controller = avcontroller;
        console.info(`CreateController : SUCCESS : ${controller.sessionId}`);
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

| 参数名       | 类型                                                                                                                                                                 | 必填 | 说明                                                         |
| ------------ |--------------------------------------------------------------------------------------------------------------------------------------------------------------------| ---- | ------------------------------------------------------------ |
| session      | [SessionToken](#sessiontoken) &#124; 'all'                                                                                                                         | 是   | 会话令牌。SessionToken表示单个token；字符串`'all'`指所有token。 |
| audioDevices | Array\<[audio.AudioDeviceDescriptor](js-apis-audio.md#audiodevicedescriptor)\> | 是   | 媒体设备列表。                          |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当投播成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600104  | The remote session  connection failed |

**示例：**

```js
import audio from '@ohos.multimedia.audio';

let audioManager = audio.getAudioManager();
let audioDevices;
await audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
    audioDevices = data;
    console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err) => {
    console.info(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

avSession.castAudio('all', audioDevices).then(() => {
    console.info('CreateController : SUCCESS');
}).catch((err) => {
    console.info(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});
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
| audioDevices | Array\<[audio.AudioDeviceDescriptor](js-apis-audio.md#audiodevicedescriptor)\>   | 是   | 媒体设备列表。                       |
| callback     | AsyncCallback<void\>                       | 是   | 回调函数。当投播成功，err为undefined，否则返回错误对象。                        |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600104  | The remote session  connection failed |

**示例：**

```js
import audio from '@ohos.multimedia.audio';

let audioManager = audio.getAudioManager();
let audioDevices;
await audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
    audioDevices = data;
    console.info('Promise returned to indicate that the device list is obtained.');
}).catch((err) => {
    console.info(`GetDevices BusinessError: code: ${err.code}, message: ${err.message}`);
});

avSession.castAudio('all', audioDevices, function (err) {
    if (err) {
        console.info(`CastAudio BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('CastAudio : SUCCESS ');
    }
});
```

## avSession.on('sessionCreate' | 'sessionDestroy' | 'topSessionChange')

on(type: 'sessionCreate' | 'sessionDestroy' | 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void

会话的创建、销毁以及最新会话变更的监听事件。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持的事件包括：<br/>- `'sessionCreate'`：会话创建事件，检测到会话创建时触发。<br/>- `'sessionDestroy'`：会话销毁事件，检测到会话销毁时触发。 <br/>- `'topSessionChange'`：最新会话的变化事件，检测到最新的会话改变时触发。|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | 是   | 回调函数。参数为会话相关描述。                               |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```js
avSession.on('sessionCreate', (descriptor) => {
    console.info(`on sessionCreate : isActive : ${descriptor.isActive}`);
    console.info(`on sessionCreate : type : ${descriptor.type}`);
    console.info(`on sessionCreate : sessionTag : ${descriptor.sessionTag}`);
});

avSession.on('sessionDestroy', (descriptor) => {
    console.info(`on sessionDestroy : isActive : ${descriptor.isActive}`);
    console.info(`on sessionDestroy : type : ${descriptor.type}`);
    console.info(`on sessionDestroy : sessionTag : ${descriptor.sessionTag}`);
});

avSession.on('topSessionChange', (descriptor) => {
    console.info(`on topSessionChange : isActive : ${descriptor.isActive}`);
    console.info(`on topSessionChange : type : ${descriptor.type}`);
    console.info(`on topSessionChange : sessionTag : ${descriptor.sessionTag}`);
});
```

## avSession.off('sessionCreate' | 'sessionDestroy' | 'topSessionChange')

off(type: 'sessionCreate' | 'sessionDestroy' | 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void

取消会话相关事件监听，取消后，不再进行相关事件的监听。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持的事件为：<br/>- `'sessionCreate'`：会话创建事件，检测到会话创建时触发。<br/>- `'sessionDestroy'`：会话销毁事件，检测到会话销毁时触发。 <br/>- `'topSessionChange'`：最新会话的变化事件，检测到最新的会话改变时触发。|
| callback | (session: [AVSessionDescriptor](#avsessiondescriptor)) => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为会话相关描述，为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                               |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```js
avSession.off('sessionCreate');
avSession.off('sessionDestroy');
avSession.off('topSessionChange');
```

## avSession.on('sessionServiceDie')

on(type: 'sessionServiceDie', callback: () => void): void

监听会话的服务死亡事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持事件`'sessionServiceDie'`：会话服务死亡事件，检测到会话的服务死亡时触发。 |
| callback | callback: () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则返回错误对象。                                |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```js
avSession.on('sessionServiceDie', () => {
    console.info('on sessionServiceDie  : session is  Died ');
});
```

## avSession.off('sessionServiceDie')

off(type: 'sessionServiceDie', callback?: () => void): void

取消会话服务死亡监听，取消后，不再进行服务死亡监听。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                    | 必填  |      说明                                               |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | 是    | 事件回调类型，支持事件`'sessionServiceDie'`：会话服务死亡事件。|
| callback | callback: () => void   | 否    | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的服务死亡监听。            |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |

**示例：**

```js
avSession.off('sessionServiceDie');
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
| Promise<void\> | Promise对象。当事件发送成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600105  | Invalid session command |

**示例：**

```js

let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem],   ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event).then(() => {
    console.info('SendSystemAVKeyEvent Successfully');
}).catch((err) => {
    console.info(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});

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
| callback | AsyncCallback<void\>                                         | 是   | 回调函数。当事件发送成功，err为undefined，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600105  | Invalid session command |

**示例：**

```js
let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem],   ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event, function (err) {
    if (err) {
        console.info(`SendSystemAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('SendSystemAVKeyEvent : SUCCESS ');
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
| command | [AVControlCommand](#avcontrolcommand) | 是   | AVSession的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600105  | Invalid session command |
| 6600107  | Command or event overload |

**示例：**

```js
let cmd : avSession.AVControlCommandType = 'play';
// let cmd : avSession.AVControlCommandType = 'pause';
// let cmd : avSession.AVControlCommandType = 'stop';
// let cmd : avSession.AVControlCommandType = 'playNext';
// let cmd : avSession.AVControlCommandType = 'playPrevious';
// let cmd : avSession.AVControlCommandType = 'fastForward';
// let cmd : avSession.AVControlCommandType = 'rewind';
let avcommand = {command:cmd};
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
}).catch((err) => {
    console.info(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
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
| command  | [AVControlCommand](#avcontrolcommand) | 是   | AVSession的相关命令和命令相关参数。   |
| callback | AsyncCallback<void\>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600105  | Invalid session command |
| 6600107  | Command or event overload |

**示例：**

```js
let cmd : avSession.AVControlCommandType = 'play';
// let cmd : avSession.AVControlCommandType = 'pause';
// let cmd : avSession.AVControlCommandType = 'stop';
// let cmd : avSession.AVControlCommandType = 'playNext';
// let cmd : avSession.AVControlCommandType = 'playPrevious';
// let cmd : avSession.AVControlCommandType = 'fastForward';
// let cmd : avSession.AVControlCommandType = 'rewind';
let avcommand = {command:cmd};
// let cmd : avSession.AVControlCommandType = 'seek';
// let avcommand = {command:cmd, parameter:10};
// let cmd : avSession.AVControlCommandType = 'setSpeed';
// let avcommand = {command:cmd, parameter:2.6};
// let cmd : avSession.AVControlCommandType = 'setLoopMode';
// let avcommand = {command:cmd, parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let cmd : avSession.AVControlCommandType = 'toggleFavorite';
// let avcommand = {command:cmd, parameter:"false"};
avSession.sendSystemControlCommand(avcommand, function (err) {
    if (err) {
        console.info(`SendSystemControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('sendSystemControlCommand successfully');
    }
});
```

## AVSession<a name="section652893"></a>

调用[avSession.createAVSession](#avsessioncreateavsession)后，返回会话的实例，可以获得会话ID，完成设置元数据，播放状态信息等操作。

### 属性

**系统能力：** SystemCapability.Multimedia.AVSession.Core


| 名称      | 类型   | 可读 | 可写 | 说明                          |
| :-------- | :----- | :--- | :--- | :---------------------------- |
| sessionId | string | 是   | 否   | AVSession对象唯一的会话标识。 |


**示例：**
```js
let sessionId = session.sessionId;
```

### setAVMetadata

setAVMetadata(data: AVMetadata): Promise\<void>

设置会话元数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                      | 必填 | 说明         |
| ------ | ------------------------- | ---- | ------------ |
| data   | [AVMetadata](#avmetadata) | 是   | 会话元数据。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当元数据设置成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
let metadata  = {
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
session.setAVMetadata(metadata).then(() => {
    console.info('SetAVMetadata successfully');
}).catch((err) => {
    console.info(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVMetadata

setAVMetadata(data: AVMetadata, callback: AsyncCallback\<void>): void

设置会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                  |
| -------- | ------------------------- | ---- | ------------------------------------- |
| data     | [AVMetadata](#avmetadata) | 是   | 会话元数据。                          |
| callback | AsyncCallback<void\>      | 是   | 回调函数。当元数据设置成功，err为undefined，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
let metadata  = {
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
session.setAVMetadata(metadata, function (err) {
    if (err) {
        console.info(`SetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('SetAVMetadata successfully');
    }
});
```

### setAVPlaybackState

setAVPlaybackState(state: AVPlaybackState): Promise\<void>

设置会话播放状态。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                                | 必填 | 说明                                           |
| ------ | ----------------------------------- | ---- | ---------------------------------------------- |
| data   | [AVPlaybackState](#avplaybackstate) | 是   | 会话播放状态，包括状态、倍数、循环模式等信息。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当播放状态设置成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
let playbackState = {
    state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
    speed: 1.0,
    position:{elapsedTime:10, updateTime:(new Date()).getTime()},
    bufferedTime:1000,
    loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
    isFavorite:true,
};
session.setAVPlaybackState(playbackState).then(() => {
    console.info('SetAVPlaybackState successfully');
}).catch((err) => {
    console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### setAVPlaybackState

setAVPlaybackState(state: AVPlaybackState, callback: AsyncCallback\<void>): void

设置会话播放状态。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                | 必填 | 说明                                           |
| -------- | ----------------------------------- | ---- | ---------------------------------------------- |
| data     | [AVPlaybackState](#avplaybackstate) | 是   | 会话播放状态，包括状态、倍数、循环模式等信息。 |
| callback | AsyncCallback<void\>                | 是   | 回调函数。当播放状态设置成功，err为undefined，否则返回错误对象。          |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
let PlaybackState = {
    state:avSession.PlaybackState.PLAYBACK_STATE_PLAY,
    speed: 1.0,
    position:{elapsedTime:10, updateTime:(new Date()).getTime()},
    bufferedTime:1000,
    loopMode:avSession.LoopMode.LOOP_MODE_SINGLE,
    isFavorite:true,
};
session.setAVPlaybackState(PlaybackState, function (err) {
    if (err) {
        console.info(`SetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('SetAVPlaybackState successfully');
    }
});
```

### setLaunchAbility

setLaunchAbility(ability: WantAgent): Promise\<void>

设置一个WantAgent用于拉起会话的Ability。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                                        |
| ------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| ability | [WantAgent](js-apis-wantAgent.md) | 是   | 应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当Ability设置成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
import wantAgent from '@ohos.wantAgent';

//WantAgentInfo对象
let wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
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
    session.setLaunchAbility(agent).then(() => {
        console.info('SetLaunchAbility successfully');
    }).catch((err) => {
        console.info(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
    });
});
```

### setLaunchAbility

setLaunchAbility(ability: WantAgent, callback: AsyncCallback\<void>): void

设置一个WantAgent用于拉起会话的Ability。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                                        |
| -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| ability  | [WantAgent](js-apis-wantAgent.md) | 是   | 应用的相关属性信息，如bundleName，abilityName，deviceId等。 |
| callback | AsyncCallback<void\>              | 是   | 回调函数。当Ability设置成功，err为undefined，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
import wantAgent from '@ohos.wantAgent';

//WantAgentInfo对象
let wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
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
    session.setLaunchAbility(agent, function (err) {
        if (err) {
            console.info(`SetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
        } else {
            console.info('SetLaunchAbility successfully');
        }
    });
});
```

### getController

getController(): Promise\<AVSessionController>

获取本会话对应的控制器。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                 | 说明                          |
| ---------------------------------------------------- | ----------------------------- |
| Promise<[AVSessionController](#avsessioncontroller)> | Promise对象。返回会话控制器。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
let controller;
session.getController().then((avcontroller) => {
    controller = avcontroller;
    console.info(`GetController : SUCCESS : sessionid : ${controller.sessionId}`);
}).catch((err) => {
    console.info(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getController

getController(callback: AsyncCallback\<AVSessionController>): void

获取本会话相应的控制器。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                       |
| -------- | ----------------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVSessionController](#avsessioncontroller)\> | 是   | 回调函数。返回会话控制器。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
let controller;
session.getController(function (err, avcontroller) {
    if (err) {
        console.info(`GetController BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        controller = avcontroller;
        console.info(`GetController : SUCCESS : sessionid : ${controller.sessionId}`);
    }
});
```

### getOutputDevice

getOutputDevice(): Promise\<OutputDeviceInfo>

通过会话获取播放设备信息。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                           | 说明                              |
| ---------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo)> | Promise对象。返回播放设备信息。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.getOutputDevice().then((outputDeviceInfo) => {
    console.info(`GetOutputDevice : SUCCESS : isRemote : ${outputDeviceInfo.isRemote}`);
}).catch((err) => {
    console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getOutputDevice

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

通过会话获取播放设备相关信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                           |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo)\> | 是   | 回调函数，返回播放设备信息。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.getOutputDevice(function (err, outputDeviceInfo) {
    if (err) {
        console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetOutputDevice : SUCCESS : isRemote : ${outputDeviceInfo.isRemote}`);
    }
});
```

### activate

activate(): Promise\<void>

激活会话，激活后可正常使用会话。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当会话激活成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.activate().then(() => {
    console.info('Activate : SUCCESS ');
}).catch((err) => {
    console.info(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### activate

activate(callback: AsyncCallback\<void>): void

激活会话，激活后可正常使用会话。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当会话激活成功，err为undefined，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.activate(function (err) {
    if (err) {
        console.info(`Activate BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('Activate : SUCCESS ');
    }
});
```

### deactivate

deactivate(): Promise\<void>

禁用当前会话的功能，可通过[activate](#activate)恢复。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当禁用会话成功，无返回结果，否则返回错误对象。|

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.deactivate().then(() => {
    console.info('Deactivate : SUCCESS ');
}).catch((err) => {
    console.info(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### deactivate

deactivate(callback: AsyncCallback\<void>): void

禁用当前会话。结果通过callback异步回调方式返回。

禁用当前会话的功能，可通过[activate](#activate)恢复。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当禁用会话成功，err为undefined，否则返回错误对象。|

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.deactivate(function (err) {
    if (err) {
        console.info(`Deactivate BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('Deactivate : SUCCESS ');
    }
});
```

### destroy

destroy(): Promise\<void>

销毁当前会话，使当前会话完全失效。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当会话销毁成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.destroy().then(() => {
    console.info('Destroy : SUCCESS ');
}).catch((err) => {
    console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### destroy

destroy(callback: AsyncCallback\<void>): void

销毁当前会话，使当前会话完全失效。结果通过callback异步回调方式返回。


**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当会话销毁成功，err为undefined，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.destroy(function (err) {
    if (err) {
        console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('Destroy : SUCCESS ');
    }
});
```

### on('play'|'pause'|'stop'|'playNext'|'playPrevious'|'fastForward'|'rewind')

on(type: 'play'|'pause'|'stop'|'playNext'|'playPrevious'|'fastForward'|'rewind', callback: () => void): void

设置播放命令监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持的事件包括：`'play'`，`'pause'`，`'stop'`，` 'playNext'`，` 'playPrevious'`， `'fastForward'`，` 'rewind'`。<br/>当对应的播放命令被发送到会话时，触发该事件回调。 |
| callback | callback: () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。                                        |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.on('play', () => {
    console.info('on play entry');
});
session.on('pause', () => {
    console.info('on pause entry');
});
session.on('stop', () => {
    console.info('on stop entry');
});
session.on('playNext', () => {
    console.info('on playNext entry');
});
session.on('playPrevious', () => {
    console.info('on playPrevious entry');
});
session.on('fastForward', () => {
    console.info('on fastForward entry');
});
session.on('rewind', () => {
    console.info('on rewind entry');
});
```

### on('seek')

on(type: 'seek', callback: (time: number) => void): void

设置跳转节点监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 事件回调类型，支持事件`'seek'`：当跳转节点命令被发送到会话时，触发该事件。 |
| callback | (time: number) => void | 是   | 回调函数。参数time是时间节点，单位为毫秒。                   |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**
The session does not exist
```js
session.on('seek', (time) => {
    console.info(`on seek entry time : ${time}`);
});
```

### on('setSpeed')

on(type: 'setSpeed', callback: (speed: number) => void): void

设置播放速率的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | 是   | 事件回调类型，支持事件`'setSpeed'`：当设置播放速率的命令被发送到会话时，触发该事件。 |
| callback | (speed: number) => void | 是   | 回调函数。参数speed是播放倍速。                              |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.on('setSpeed', (speed) => {
    console.info(`on setSpeed speed : ${speed}`);
});
```

### on('setLoopMode')

on(type: 'setLoopMode', callback: (mode: LoopMode) => void): void

设置循环模式的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                                   | 必填 | 说明  |
| -------- | ------------------------------------- | ---- | ---- |
| type     | string                                | 是   | 事件回调类型，支持事件`'setLoopMode'`：当设置循环模式的命令被发送到会话时，触发该事件。 |
| callback | (mode: [LoopMode](#loopmode)) => void | 是   | 回调函数。参数mode是循环模式。                               |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.on('setLoopMode', (mode) => {
    console.info(`on setLoopMode mode : ${mode}`);
});
```

### on('toggleFavorite')

on(type: 'toggleFavorite', callback: (assetId: string) => void): void

设置是否收藏的监听事件

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                    | 是   | 事件回调类型，支持事件`'toggleFavorite'`：当是否收藏的命令被发送到会话时，触发该事件。 |
| callback | (assetId: string) => void | 是   | 回调函数。参数assetId是媒体ID。                              |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.on('toggleFavorite', (assetId) => {
    console.info(`on toggleFavorite mode : ${assetId}`);
});
```

### on('handleKeyEvent')

on(type: 'handleKeyEvent', callback: (event: KeyEvent) => void): void

设置按键事件的监听

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'handleKeyEvent'`：当按键事件被发送到会话时，触发该事件。 |
| callback | (event: [KeyEvent](js-apis-keyevent.md)) => void | 是   | 回调函数。参数event是按键事件。                              |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.on('handleKeyEvent', (event) => {
    console.info(`on handleKeyEvent event : ${event}`);
});
```

### on('outputDeviceChange')

on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void

设置播放设备变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | 是   | 事件回调类型，支持事件`'outputDeviceChange'`：当播放设备变化时，触发该事件。 |
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo)) => void | 是   | 回调函数。参数device是设备相关信息。                         |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.on('outputDeviceChange', (device) => {
    console.info(`on outputDeviceChange device isRemote : ${device.isRemote}`);
});
```

### off('play'|'pause'|'stop'|'playNext'|'playPrevious'|'fastForward'|'rewind')

off(type: 'play' | 'pause' | 'stop' | 'playNext' | 'playPrevious' | 'fastForward' | 'rewind', callback?: () => void): void

取消会话相关事件监听，关闭后，不再进行相关事件回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名    | 类型                  | 必填 | 说明                                                                                                                         |
| -------- | -------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| type     | string               | 是   | 关闭对应的监听事件，支持的事件包括：`'play'`，` 'pause'`，`'stop'`， `'playNext'`，` 'playPrevious'`， ` 'fastForward'`，` 'rewind'`。 |
| callback | callback: () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                            |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.off('play');
session.off('pause');
session.off('stop');
session.off('playNext');
session.off('playPrevious');
session.off('fastForward');
session.off('rewind');
```

### off('seek')

off(type: 'seek', callback?: (time: number) => void): void

取消监听跳转节点事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                          |
| -------- | ---------------------- | ---- | ----------------------------------------- |
| type     | string                 | 是   | 关闭对应的监听事件，支持关闭事件`'seek'`。       |
| callback | (time: number) => void | 否   | 回调函数，参数time是时间节点，单位为毫秒。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。        |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.off('seek');
```

### off('setSpeed')

off(type: 'setSpeed', callback?: (speed: number) => void): void

取消监听播放速率变化事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                           |
| -------- | ----------------------- | ---- | -------------------------------------------|
| type     | string                  | 是   | 关闭对应的监听事件，支持关闭事件`'setSpeed'`。    |
| callback | (speed: number) => void | 否   | 回调函数，参数speed是播放倍速。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.off('setSpeed');
```

### off('setLoopMode')

off(type: 'setLoopMode', callback?: (mode: LoopMode) => void): void

取消监听循环模式变化事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明     |
| -------- | ------------------------------------- | ---- | ----- |
| type     | string | 是   | 关闭对应的监听事件，支持关闭事件`'setLoopMode'`。|
| callback | (mode: [LoopMode](#loopmode)) => void | 否   | 回调函数，参数mode是循环模式。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.off('setLoopMode');
```

### off('toggleFavorite')

off(type: 'toggleFavorite', callback?: (assetId: string) => void): void

取消监听是否收藏的事件

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | -------------------------------------------------------- |
| type     | string                    | 是   | 关闭对应的监听事件，支持关闭事件`'toggleFavorite'`。            |
| callback | (assetId: string) => void | 否   | 回调函数，参数assetId是媒体ID。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                               |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.off('toggleFavorite');
```

### off('handleKeyEvent')

off(type: 'handleKeyEvent', callback?: (event: KeyEvent) => void): void

取消监听按键事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 关闭对应的监听事件，支持关闭事件`'handleKeyEvent'`。             |
| callback | (event: [KeyEvent](js-apis-keyevent.md)) => void | 否   | 回调函数，参数event是按键事件。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                              |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.off('handleKeyEvent');
```

### off('outputDeviceChange')

off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void

取消监听播放设备变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                      |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | 是   | 关闭对应的监听事件，支持关闭事件`'outputDeviceChange'`。     |
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo)) => void | 否   | 回调函数，参数device是设备相关信息。<br>当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                        |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |

**示例：**

```js
session.off('outputDeviceChange');
```



## AVSessionController<a name="section974602"></a>

调用[avSession.createController](#avsessioncreatecontroller)后，返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。

### 属性

**系统能力：** SystemCapability.Multimedia.AVSession.Core


| 名称      | 类型   | 可读 | 可写 | 说明                                    |
| :-------- | :----- | :--- | :--- | :-------------------------------------- |
| sessionId | string | 是   | 否   | AVSessionController对象唯一的会话标识。 |


**示例：**
```js
let sessionId;
await avSession.createController(session.sessionId).then((controller) => {
    sessionId = controller.sessionId;
}).catch((err) => {
    console.info(`CreateController BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVPlaybackState

getAVPlaybackState(): Promise\<AVPlaybackState>

获取当前会话播放状态相关信息。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                          | 说明                        |
| --------------------------------------------- | --------------------------- |
| Promise<[AVPlaybackState](#avplaybackstate)\> | Promise对象。返回播放状态对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**
```js
controller.getAVPlaybackState().then((playbackState) => {
    console.info(`GetAVPlaybackState : SUCCESS : state : ${playbackState.state}`);
}).catch((err) => {
    console.info(`GetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVPlaybackState

getAVPlaybackState(callback: AsyncCallback\<AVPlaybackState>): void

获取当前播放状态相关信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                         |
| -------- | --------------------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback<[AVPlaybackState](#avplaybackstate)\> | 是   | 回调函数，返回当前播放状态对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**
```js
controller.getAVPlaybackState(function (err, playbackState) {
    if (err) {
        console.info(`GetAVPlaybackState BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetAVPlaybackState : SUCCESS : state : ${playbackState.state}`);
    }
});
```

### getAVMetadata

getAVMetadata(): Promise\<AVMetadata>

获取会话元数据。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<[AVMetadata](#avmetadata)\> | Promise对象，返回会话元数据。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**
```js
controller.getAVMetadata().then((metadata) => {
    console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
}).catch((err) => {
    console.info(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getAVMetadata

getAVMetadata(callback: AsyncCallback\<AVMetadata>): void

获取会话元数据。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<[AVMetadata](#avmetadata)\> | 是   | 回调函数，返回会话元数据。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**
```js
controller.getAVMetadata(function (err, metadata) {
    if (err) {
        console.info(`GetAVMetadata BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetAVMetadata : SUCCESS : assetId : ${metadata.assetId}`);
    }
});
```

### getOutputDevice

getOutputDevice(): Promise\<OutputDeviceInfo>

获取播放设备信息。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                            | 说明                              |
| ----------------------------------------------- | --------------------------------- |
| Promise<[OutputDeviceInfo](#outputdeviceinfo)\> | Promise对象，返回播放设备信息。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**
```js
controller.getOutputDevice().then((deviceInfo) => {
    console.info(`GetOutputDevice : SUCCESS : isRemote : ${deviceInfo.isRemote}`);
}).catch((err) => {
    console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getOutputDevice

getOutputDevice(callback: AsyncCallback\<OutputDeviceInfo>): void

获取播放设备信息。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                           |
| -------- | ----------------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[OutputDeviceInfo](#outputdeviceinfo)\> | 是   | 回调函数，返回播放设备信息。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.getOutputDevice(function (err, deviceInfo) {
    if (err) {
        console.info(`GetOutputDevice BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetOutputDevice : SUCCESS : isRemote : ${deviceInfo.isRemote}`);
    }
});
```

### sendAVKeyEvent

sendAVKeyEvent(event: KeyEvent): Promise\<void>

发送按键事件到控制器对应的会话。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明       |
| ------ | ------------------------------------------------------------ | ---- | ---------- |
| event  | [KeyEvent](js-apis-keyevent.md) | 是   | 按键事件。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |
| 6600105  | Invalid session command |
| 6600106  | The session not active |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当事件发送成功，无返回结果，否则返回错误对象。 |

**示例：**

```js
let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {action:2, key:keyItem, keys:[keyItem]};

controller.sendAVKeyEvent(event).then(() => {
    console.info('SendAVKeyEvent Successfully');
}).catch((err) => {
    console.info(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendAVKeyEvent

sendAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

发送按键事件到会话。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明       |
| -------- | ------------------------------------------------------------ | ---- | ---------- |
| event    | [KeyEvent](js-apis-keyevent.md) | 是   | 按键事件。 |
| callback | AsyncCallback<void\>                                         | 是   | 回调函数。当事件发送成功，err为undefined，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |
| 6600105  | Invalid session command |
| 6600106  | The session not active |

**示例：**

```js
let keyItem = {code:0x49, pressedTime:2, deviceId:0};
let event = {action:2, key:keyItem, keys:[keyItem]};

controller.sendAVKeyEvent(event, function (err) {
    if (err) {
        console.info(`SendAVKeyEvent BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('SendAVKeyEvent Successfully');
    }
});
```

### getLaunchAbility

getLaunchAbility(): Promise\<WantAgent>

获取应用在会话中保存的WantAgent对象。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                        | 说明                                                         |
| ------------------------------------------- | ------------------------------------------------------------ |
| Promise<[WantAgent](js-apis-wantAgent.md)\> | Promise对象，返回在[setLaunchAbility](#setlaunchability)保存的对象，包括应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**

```js
import wantAgent from '@ohos.wantAgent';

controller.getLaunchAbility().then((agent) => {
    console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
}).catch((err) => {
    console.info(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getLaunchAbility

getLaunchAbility(callback: AsyncCallback\<WantAgent>): void

获取应用在会话中保存的WantAgent对象。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                                         |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<[WantAgent](js-apis-wantAgent.md)\> | 是   | 回调函数。返回在[setLaunchAbility](#setlaunchability)保存的对象，包括应用的相关属性信息，如bundleName，abilityName，deviceId等。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**

```js
import wantAgent from '@ohos.wantAgent';

controller.getLaunchAbility(function (err, agent) {
    if (err) {
        console.info(`GetLaunchAbility BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetLaunchAbility : SUCCESS : wantAgent : ${agent}`);
    }
});
```

### getRealPlaybackPositionSync

getRealPlaybackPositionSync(): number

获取当前播放位置。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 时间节点，毫秒数。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**

```js
let time = controller.getRealPlaybackPositionSync();
```

### isActive

isActive(): Promise\<boolean>

获取会话是否被激活。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise<boolean\> | Promise对象，返回会话是否为激活状态，true表示被激活，false表示禁用。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.isActive().then((isActive) => {
    console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
}).catch((err) => {
    console.info(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### isActive

isActive(callback: AsyncCallback\<boolean>): void

判断会话是否被激活。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<boolean\> | 是   | 回调函数，返回会话是否为激活状态，true表示被激活，false表示禁用。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.isActive(function (err, isActive) {
    if (err) {
        console.info(`IsActive BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`IsActive : SUCCESS : isactive : ${isActive}`);
    }
});
```

### destroy

destroy(): Promise\<void>

销毁当前控制器，销毁后当前控制器不可再用。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当控制器销毁成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.destroy().then(() => {
    console.info('Destroy : SUCCESS ');
}).catch((err) => {
    console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### destroy

destroy(callback: AsyncCallback\<void>): void

销毁当前控制器，销毁后当前控制器不可再用。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback<void\> | 是   | 回调函数。当控制器销毁成功，err为undefined，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.destroy(function (err) {
    if (err) {
        console.info(`Destroy BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('Destroy : SUCCESS ');
    }
});
```

### getValidCommands

getValidCommands(): Promise\<Array\<AVControlCommandType>>

获取会话支持的有效命令。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                                                         | 说明                              |
| ------------------------------------------------------------ | --------------------------------- |
| Promise<Array<[AVControlCommandType](#avcontrolcommandtype)\>\> | Promise对象。返回有效命令的集合。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.getValidCommands.then((validCommands) => {
    console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
}).catch((err) => {
    console.info(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### getValidCommands

getValidCommands(callback: AsyncCallback\<Array\<AVControlCommandType>>): void

获取会话支持的有效命令。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<[AVControlCommandType](#avcontrolcommandtype)\>\> | 是   | 回调函数，返回有效命令的集合。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.getValidCommands(function (err, validCommands) {
    if (err) {
        console.info(`GetValidCommands BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info(`GetValidCommands : SUCCESS : size : ${validCommands.length}`);
    }
});
```

### sendControlCommand

sendControlCommand(command: AVControlCommand): Promise\<void>

通过控制器发送命令到其对应的会话。结果通过Promise异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 名称    | 类型                                  | 必填 | 说明                           |
| ------- | ------------------------------------- | ---- | ------------------------------ |
| command | [AVControlCommand](#avcontrolcommand) | 是   | 会话的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 6600101  | Session service exception |
| 6600102  | The session does not exist |
| 6600103  | The session controller does not exist |
| 6600105  | Invalid session command |
| 6600106  | The session not active |
| 6600107  | Command or event overload |

**示例：**

```js
let avCommand = {command:'play'};
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
controller.sendControlCommand(avCommand).then(() => {
    console.info('SendControlCommand successfully');
}).catch((err) => {
    console.info(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
});
```

### sendControlCommand

sendControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

通过会话控制器发送命令到其对应的会话。结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                           |
| -------- | ------------------------------------- | ---- | ------------------------------ |
| command  | [AVControlCommand](#avcontrolcommand) | 是   | 会话的相关命令和命令相关参数。 |
| callback | AsyncCallback<void\>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。                     |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------- |
| 6600101  | Session service exception                |
| 6600102  | The session does not exist      |
| 6600103  | The session controller does not exist   |
| 6600105  | Invalid session command           |
| 6600106  | The session not active                |
| 6600107  | Command or event overload       |

**示例：**

```js
let avCommand = {command:'play'};
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
controller.sendControlCommand(avCommand, function (err) {
    if (err) {
        console.info(`SendControlCommand BusinessError: code: ${err.code}, message: ${err.message}`);
    } else {
        console.info('SendControlCommand successfully');
    }
});
```

### on('metadataChange')

on(type: 'metadataChange', filter: Array\<keyof AVMetadata> | 'all', callback: (data: AVMetadata) => void)

设置元数据变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'metadataChange'`：当元数据变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[AVMetadata](#avmetadata)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注元数据所有字段变化；Array<keyof&nbsp;[AVMetadata](#avmetadata)\> 表示关注Array中的字段变化。 |
| callback | (data: [AVMetadata](#avmetadata)) => void                    | 是   | 回调函数，参数data是变化后的元数据。                         |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.on('metadataChange', 'all', (metadata) => {
    console.info(`on metadataChange assetId : ${metadata.assetId}`);
});

let metaFilter = ['assetId', 'title', 'description'];
controller.on('metadataChange', metaFilter, (metadata) => {
    console.info(`on metadataChange assetId : ${metadata.assetId}`);
});
```

### on('playbackStateChange')

on(type: 'playbackStateChange', filter: Array\<keyof AVPlaybackState> | 'all', callback: (state: AVPlaybackState) => void)

设置播放状态变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'playbackStateChange'`：当播放状态变化时，触发该事件。 |
| filter   | Array\<keyof&nbsp;[AVPlaybackState](#avplaybackstate)\>&nbsp;&#124;&nbsp;'all' | 是   | 'all' 表示关注播放状态所有字段变化；Array<keyof&nbsp;[AVPlaybackState](#avplaybackstate)\> 表示关注Array中的字段变化。 |
| callback | (state: [AVPlaybackState](#avplaybackstate)) => void         | 是   | 回调函数，参数state是变化后的播放状态。                      |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.on('playbackStateChange', 'all', (playbackState) => {
    console.info(`on playbackStateChange state : ${playbackState.state}`);
});

let playbackFilter = ['state', 'speed', 'loopMode'];
controller.on('playbackStateChange', playbackFilter, (playbackState) => {
    console.info(`on playbackStateChange state : ${playbackState.state}`);
});
```

### on('sessionDestroy')

on(type: 'sessionDestroy', callback: () => void)

会话销毁的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                         |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | 是   | 事件回调类型，支持事件`'sessionDestroy'`：当检测到会话销毁时，触发该事件）。 |
| callback | () => void | 是   | 回调函数。当监听事件注册成功，err为undefined，否则为错误对象。                  |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.on('sessionDestroy', () => {
    console.info('on sessionDestroy : SUCCESS ');
});
```

### on('activeStateChange')

on(type: 'activeStateChange', callback: (isActive: boolean) => void)

会话的激活状态的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                      | 是   | 事件回调类型，支持事件`'activeStateChange'`：当检测到会话的激活状态发生改变时，触发该事件。 |
| callback | (isActive: boolean) => void | 是   | 回调函数。参数isActive表示会话是否被激活。true表示被激活，false表示禁用。                   |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------------- |
| 6600101  | Session service exception |
| 6600103  |The session controller does not exist |

**示例：**

```js
controller.on('activeStateChange', (isActive) => {
    console.info(`on activeStateChange : SUCCESS : isActive ${isActive}`);
});
```

### on('validCommandChange')

on(type: 'validCommandChange', callback: (commands: Array\<AVControlCommandType>) => void)

会话支持的有效命令变化监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件`'validCommandChange'`：当检测到会话的合法命令发生改变时，触发该事件。 |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype)\>) => void | 是   | 回调函数。参数commands是有效命令的集合。                     |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ------------------------------ |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.on('validCommandChange', (validCommands) => {
    console.info(`validCommandChange : SUCCESS : size : ${validCommands.size}`);
    console.info(`validCommandChange : SUCCESS : validCommands : ${validCommands.values()}`);
});
```

### on('outputDeviceChange')

on(type: 'outputDeviceChange', callback: (device: OutputDeviceInfo) => void): void

设置播放设备变化的监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                  | 是   | 事件回调类型，支持事件为`'outputDeviceChange'`：当播放设备变化时，触发该事件）。 |
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo)) => void | 是   | 回调函数，参数device是设备相关信息。                         |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ----------------------- |
| 6600101  | Session service exception |
| 6600103  | The session controller does not exist |

**示例：**

```js
controller.on('outputDeviceChange', (device) => {
    console.info(`on outputDeviceChange device isRemote : ${device.isRemote}`);
});
```

### off('metadataChange')

off(type: 'metadataChange', callback?: (data: AVMetadata) => void)

控制器取消监听元数据变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                               | 必填 | 说明                                                    |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------ |
| type     | string                                           | 是   | 取消对应的监听事件，支持事件`'metadataChange'`。         |
| callback | (data: [AVMetadata](#avmetadata)) => void        | 否   | 回调函数，参数data是变化后的元数据。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                         |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception |

**示例：**

```js
controller.off('metadataChange');
```

### off('playbackStateChange')

off(type: 'playbackStateChange', callback?: (state: AVPlaybackState) => void)

控制器取消监听播放状态变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'playbackStateChange'`。    |
| callback | (state: [AVPlaybackState](#avplaybackstate)) => void         | 否   | 回调函数，参数state是变化后的播放状态。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                      |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception |

**示例：**

```js
controller.off('playbackStateChange');
```

### off('sessionDestroy')

off(type: 'sessionDestroy', callback?: () => void)

控制器取消监听会话的销毁事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                      |
| -------- | ---------- | ---- | ----------------------------------------------------- |
| type     | string     | 是   | 取消对应的监听事件，支持事件`'sessionDestroy'`。         |
| callback | () => void | 否   | 回调函数。当监听事件取消成功，err为undefined，否则返回错误对象。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                                               |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception |

**示例：**

```js
controller.off('sessionDestroy');
```

### off('activeStateChange')

off(type: 'activeStateChange', callback?: (isActive: boolean) => void)

控制器取消监听会话激活状态变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                      |
| -------- | --------------------------- | ---- | ----------------------------------------------------- |
| type     | string                      | 是   | 取消对应的监听事件，支持事件`'activeStateChange'`。      |
| callback | (isActive: boolean) => void | 否   | 回调函数。参数isActive表示会话是否被激活。true表示被激活，false表示禁用。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                   |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 6600101  | Session service exception |

**示例：**

```js
controller.off('activeStateChange');
```

### off('validCommandChange')

off(type: 'validCommandChange', callback?: (commands: Array\<AVControlCommandType>) => void)

控制器取消监听会话有效命令变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                        |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 取消对应的监听事件，支持事件`'validCommandChange'`。         |
| callback | (commands: Array<[AVControlCommandType](#avcontrolcommandtype)\>) => void | 否   | 回调函数。参数commands是有效命令的集合。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。          |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID | 错误信息           |
| -------- | ---------------- |
| 6600101  | Session service exception |

**示例：**

```js
controller.off('validCommandChange');
```

### off('outputDeviceChange')

off(type: 'outputDeviceChange', callback?: (device: OutputDeviceInfo) => void): void

控制器取消监听分布式设备变化的事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                      |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                                  | 是   | 取消对应的监听事件，支持事件`'outputDeviceChange'`。      |
| callback | (device: [OutputDeviceInfo](#outputdeviceinfo)) => void | 否   | 回调函数，参数device是设备相关信息。<br>该参数为可选参数，若不填写该参数，则认为取消所有相关会话的事件监听。                         |

**错误码：**
以下错误码的详细介绍请参见[ohos.multimedia.avsession(多媒体会话)错误码](../errorcodes/errorcode-avsession.md)。

| 错误码ID  | 错误信息          |
| -------- | ---------------- |
| 6600101  | Session service exception |

**示例：**

```js
controller.off('outputDeviceChange');
```

## SessionToken

会话令牌的信息。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

| 名称      | 类型   | 必填 | 说明         |
| :-------- | :----- | :--- | :----------- |
| sessionId | string | 是   | 会话ID       |
| pid       | number | 是   | 会话的进程ID |
| uid       | number | 是   | 用户ID       |

## AVSessionType
当前会话支持的会话类型。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称  | 类型   | 说明 |
| ----- | ------ | ---- |
| audio | string | 音频 |
| video | string | 视频 |

## AVSessionDescriptor

会话的相关描述信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

| 名称         | 类型                                                         | 可读 | 可写 | 说明                                                |
| ------------ | ------------------------------------------------------------ | ---- | --------------------------------------------------- | --------------------------------------------------- |
| sessionId    | string                                                       | 是  | 否 | 会话ID                                              |
| type         | [AVSessionType](#avsessiontype)                              | 是   | 否  | 会话类型                                            |
| sessionTag   | string                                                       | 是   | 否  | 会话的自定义名称                                    |
| elementName  | [ElementName](js-apis-bundle-ElementName.md)                 | 是   | 否  | 会话所属应用的信息（包含bundleName、abilityName等） |
| isActive     | boolean                                                      | 是   | 否  | 会话是否被激活                                      |
| isTopSession | boolean                                                      | 是   | 否  | 会话是否为最新的会话                                |
| outputDevice | [OutputDeviceInfo](#outputdeviceinfo)                        | 是   | 否  | 分布式设备相关信息                                  |

## AVControlCommandType

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

## AVControlCommand

会话接受的命令的对象描述。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称      | 类型                                              | 必填 | 说明           |
| --------- | ------------------------------------------------- | ---- | -------------- |
| command   | [AVControlCommandType](#avcontrolcommandtype)     | 是   | 命令           |
| parameter | [LoopMode](#loopmode) &#124; string &#124; number | 否   | 命令对应的参数 |

## AVMetadata

媒体元数据的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称            | 类型                      | 必填 | 说明                                                                  |
| --------------- |-------------------------| ---- |---------------------------------------------------------------------|
| assetId         | string                  | 是   | 媒体ID。                                                               |
| title           | string                  | 否   | 标题。                                                                 |
| artist          | string                  | 否   | 艺术家。                                                                |
| author          | string                  | 否   | 专辑作者。                                                               |
| album           | string                  | 否   | 专辑名称。                                                               |
| writer          | string                  | 否   | 词作者。                                                                |
| composer        | string                  | 否   | 作曲者。                                                                |
| duration        | string                  | 否   | 媒体时长，单位毫秒（ms）。                                                  |
| mediaImage      | image.PixelMap &#124; string | 否   | 图片的像素数据或者图片路径地址(本地路径或网络路径)。                             |
| publishDate     | Date                    | 否   | 发行日期。                                                               |
| subtitle        | string                  | 否   | 子标题。                                                                |
| description     | string                  | 否   | 媒体描述。                                                               |
| lyric           | string                  | 否   | 歌词文件路径地址(本地路径或网络路径) |
| previousAssetId | string                  | 否   | 上一首媒体ID。                                                            |
| nextAssetId     | string                  | 否   | 下一首媒体ID。                                                            |

## AVPlaybackState

媒体播放状态的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称         | 类型                                  | 必填 | 说明     |
| ------------ | ------------------------------------- | ---- | ------- |
| state        | [PlaybackState](#playbackstate)       | 否   | 播放状态 |
| speed        | number                                | 否   | 播放倍速 |
| position     | [PlaybackPosition](#playbackposition) | 否   | 播放位置 |
| bufferedTime | number                                | 否   | 缓冲时间 |
| loopMode     | [LoopMode](#loopmode)                 | 否   | 循环模式 |
| isFavorite   | boolean                               | 否   | 是否收藏 |

## PlaybackPosition

媒体播放位置的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称        | 类型   | 必填 | 说明               |
| ----------- | ------ | ---- | ------------------ |
| elapsedTime | number | 是   | 已用时间，单位毫秒（ms）。 |
| updateTime  | number | 是   | 更新时间，单位毫秒（ms）。 |

## OutputDeviceInfo

播放设备的相关信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称       | 类型           | 必填 | 说明                   |
| ---------- | -------------- | ---- | ---------------------- |
| isRemote   | boolean        | 是   | 设备是否连接。         |
| audioDeviceId   | Array<number\> | 是   | 播放设备的ID集合。  |
| deviceName | Array<string\> | 是   | 播放设备的名称集合。    |

## PlaybackState

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


## LoopMode

表示媒体播放循环模式的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称               | 值   | 说明     |
| ------------------ | ---- | -------- |
| LOOP_MODE_SEQUENCE | 0    | 顺序播放 |
| LOOP_MODE_SINGLE   | 1    | 单曲循环 |
| LOOP_MODE_LIST     | 2    | 表单循环 |
| LOOP_MODE_SHUFFLE  | 3    | 随机播放 |

## AVSessionErrorCode

会话发生错误时的错误码。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                           | 值      | 说明                             |
| ------------------------------ | ------- | ------------------------------- |
| ERR_CODE_SERVICE_EXCEPTION     | 6600101 | Session service exception                |
| ERR_CODE_SESSION_NOT_EXIST     | 6600102 | The session does not exist      |
| ERR_CODE_CONTROLLER_NOT_EXIST  | 6600103 | The session controller does not exist   |
| ERR_CODE_REMOTE_CONNECTION_ERR | 6600104 | The remote session  connection failed         |
| ERR_CODE_COMMAND_INVALID       | 6600105 | Invalid session command           |
| ERR_CODE_SESSION_INACTIVE      | 6600106 | The session not active                |
| ERR_CODE_MESSAGE_OVERLOAD      | 6600107 | Command or event overload       |