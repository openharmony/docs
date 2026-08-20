# @ohos.multimedia.avsession (媒体会话管理)(系统接口)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester:@chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

媒体会话管理提供媒体播控相关功能的接口，目的是让应用接入播控中心。

该模块提供以下媒体会话相关的常用功能：

- [AVCastController](#avcastcontroller10): 投播控制器，可用于投播场景下，完成播放控制、远端播放状态监听、远端播放状态信息获取等操作。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.avsession (媒体会话管理)](arkts-apis-avsession.md)。

## 导入模块

```ts
import { avSession } from '@kit.AVSessionKit';
```

## 使用说明

本文档仅提供系统接口说明，以下接口的使用说明均需先创建实例，请参考公开接口[avSession.createAVSession](arkts-apis-avsession-f.md#avsessioncreateavsession10)的说明及示例，创建对应实例。

## avSession.getAllSessionDescriptors 

getAllSessionDescriptors(callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void 

获取所有设置过媒体信息且注册过控制回调的会话的描述符信息。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。 

**系统能力：** SystemCapability.Multimedia.AVSession.Manager 

**系统接口：** 该接口为系统接口。 

**参数：** 

| 参数名   | 类型                                                         | 必填 | 说明                                       | 
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ | 
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\>\>\> | 是   | 回调函数。返回所有会话描述的只读对象。 | 

**错误码：** 

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。 

| 错误码ID | 错误信息 | 
| -------- | ---------------------------------------- | 
| 201 | permission denied. | 
| 202 | Not System App. |
| 6600101  |Session service exception. | 

**示例：** 

```ts 
import { avSession } from '@kit.AVSessionKit';

@Entry 
@Component 
struct Index { 
  @State message: string = 'hello world'; 

  build() { 
    Column() { 
        Text(this.message) 
          .onClick(()=>{ 
            avSession.getAllSessionDescriptors((descriptors: avSession.AVSessionDescriptor[]) => { 
                console.info(`Succeeded in getting all session descriptors, length: ${descriptors.length}`); 
                if (descriptors.length > 0 ) { 
                    console.info(`Succeeded in getting session descriptor, isActive: ${descriptors[0].isActive}`); 
                    console.info(`Succeeded in getting session descriptor, type: ${descriptors[0].type}`); 
                    console.info(`Succeeded in getting session descriptor, sessionTag: ${descriptors[0].sessionTag}`); 
                } 
            }); 
          }) 
      } 
    .width('100%') 
    .height('100%') 
  } 
} 
```

## avSession.getSessionDescriptors<sup>22+</sup>

getSessionDescriptors(category: SessionCategory): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

根据不同的会话类别获取对应的会话描述。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名    | 类型                              | 必填 | 说明            |
| --------  | ----------------------------------| ---- |  ---------------|
| category  |  [SessionCategory](#sessioncategory22) |  是  | 指定会话的类别。|


**返回值：**

| 类型                                                                        | 说明                                   |
| --------------------------------------------------------------------------- | -------------------------------------- |
| Promise\<Array\<Readonly\<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\>\>\> | Promise对象。返回对应类别的会话描述的只读对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.getSessionDescriptors(avSession.SessionCategory.CATEGORY_ALL).then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`Succeeded in getting session descriptors, length: ${descriptors.length}`);
  if (descriptors.length > 0) {
    console.info(`Succeeded in getting session descriptor, isActive: ${descriptors[0].isActive}`);
    console.info(`Succeeded in getting session descriptor, type: ${descriptors[0].type}`);
    console.info(`Succeeded in getting session descriptor, sessionTag: ${descriptors[0].sessionTag}`);
  }
});
```

## avSession.getHistoricalSessionDescriptors<sup>10+</sup>

getHistoricalSessionDescriptors(maxSize?: number): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

获取所有已被销毁的会话相关描述。使用Promise异步回调。

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
| Promise\<Array\<Readonly\<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\>\>\> | Promise对象。返回所有会话描述的只读对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.getHistoricalSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
  console.info(`Succeeded in getting historical session descriptors, length: ${descriptors.length}`);
  if (descriptors.length > 0 && descriptors[0]) {
    console.info(`Succeeded in getting historical session descriptor, isActive: ${descriptors[0].isActive}`);
    console.info(`Succeeded in getting historical session descriptor, type: ${descriptors[0].type}`);
    console.info(`Succeeded in getting historical session descriptor, sessionTag: ${descriptors[0].sessionTag}`);
    console.info(`Succeeded in getting historical session descriptor, sessionId: ${descriptors[0].sessionId}`);
    console.info(`Succeeded in getting historical session descriptor, bundleName: ${descriptors[0].elementName.bundleName}`);
  }
});
```

## avSession.getHistoricalSessionDescriptors<sup>10+</sup>

getHistoricalSessionDescriptors(maxSize: number, callback: AsyncCallback\<Array\<Readonly\<AVSessionDescriptor>>>): void

获取所有已被销毁的会话相关描述。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                                            | 必填 | 说明                                                             |
| -------- | ------------------------------------------------------------------------------ | ---- |-----------------------------------------------------------------|
| maxSize  | number                                                                         | 是  | 指定获取描述符数量的最大值，可选范围是0-10。|
| callback | AsyncCallback<Array<Readonly<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\>\>\> | 是   | 回调函数。返回所有会话描述的只读对象。                              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 |  permission denied. |
| 202 |  Not System App.  |
| 401 |  parameter check failed. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  |Session service exception. |

**示例：**

```ts
avSession.getHistoricalSessionDescriptors(1, (descriptors: avSession.AVSessionDescriptor[]) => { 
    console.info(`Succeeded in getting historical session descriptors, length: ${descriptors.length}`); 
    if (descriptors.length > 0 ) { 
      console.info(`Succeeded in getting historical session descriptor, isActive: ${descriptors[0].isActive}`); 
      console.info(`Succeeded in getting historical session descriptor, type: ${descriptors[0].type}`); 
      console.info(`Succeeded in getting historical session descriptor, sessionTag: ${descriptors[0].sessionTag}`); 
      console.info(`Succeeded in getting historical session descriptor, sessionId: ${descriptors[0].sessionId}`); 
      console.info(`Succeeded in getting historical session descriptor, bundleName: ${descriptors[0].elementName.bundleName}`); 
    } 
});
```

## avSession.getHistoricalAVQueueInfos<sup>11+</sup>

getHistoricalAVQueueInfos(maxSize: number, maxAppSize: number): Promise\<Array\<Readonly\<AVQueueInfo>>>

根据指定数量限制获取历史播放歌单。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型    | 必填 | 说明                                                             |
| -------- | ------ | ---- | ---------------------------------------------------------------|
| maxSize  | number | 是   | 指定获取歌曲列表数量的最大值，与获取歌单数量无关。                     |
| maxAppSize | number | 是   | 指定获取歌曲列表所属应用数量的最大值，与获取歌单数量无关。             |

**返回值：**

| 类型                                                                        | 说明                                   |
| --------------------------------------------------------------------------- | ------------------------------------- |
| Promise\<Array\<Readonly\<[AVQueueInfo](#avqueueinfo11)\>\>\> | Promise对象。返回所有历史播放歌单的只读对象。                |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.getHistoricalAVQueueInfos(3, 5).then((avQueueInfos: avSession.AVQueueInfo[]) => {
  console.info(`Succeeded in getting historical AV queue infos, length: ${avQueueInfos.length}`);
});
```

## avSession.getHistoricalAVQueueInfos<sup>11+</sup>

getHistoricalAVQueueInfos(maxSize: number, maxAppSize: number, callback: AsyncCallback\<Array\<Readonly\<AVQueueInfo>>>): void;

根据指定数量限制获取历史播放歌单。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                                            | 必填 | 说明                                                             |
| -------- | ----------------------------------------------------------------------------- | ---- |---------------------------------------------------------------|
| maxSize  | number                                                                        | 是   | 指定获取歌曲列表数量的最大值。                      |
| maxAppSize | number                                                                      | 是   | 指定获取歌曲列表所属应用数量的最大值。               |
| callback | AsyncCallback<Array<Readonly<[AVQueueInfo](#avqueueinfo11)\>\>\> | 是   | 回调函数。返回所有历史播放歌单的只读对象。                              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  |Session service exception. |

**示例：**

```ts
avSession.getHistoricalAVQueueInfos(3, 5, (avQueueInfos: avSession.AVQueueInfo[]) => { 
    console.info(`Succeeded in getting historical AV queue infos, length: ${avQueueInfos.length}`); 
});
```

## avSession.createController 

createController(sessionId: string, callback: AsyncCallback\<AVSessionController>): void 

根据会话ID创建会话控制器。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。 

**系统能力：** SystemCapability.Multimedia.AVSession.Manager 

**系统接口：** 该接口为系统接口。 

**参数：** 

| 参数名    | 类型                                                        | 必填 | 说明                                                         | 
| --------- | ----------------------------------------------------------- | ---- |------------------------------------------------------------ | 
| sessionId | string                                                      | 是   | 会话ID。                                                     | 
| callback  | AsyncCallback<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\> | 是   | 回调函数。返回会话控制器实例，可查看会话ID，<br>并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。 

| 错误码ID | 错误信息 | 
| -------- | ---------------------------------------- | 
| 201 | permission denied. | 
| 202 | Not System App. | 
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. | 
| 6600101  | Session service exception. | 
| 6600102  | The session does not exist. | 

**示例：** 

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
        Text(this.message)
          .onClick(()=>{
            avSession.getAllSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
              console.info(`Succeeded in getting all session descriptors, length: ${descriptors.length}`);
              if (descriptors.length > 0) {
                avSession.createController(descriptors[0]?.sessionId, (avcontroller: avSession.AVSessionController) => { 
                  console.info('Succeeded in creating controller.'); 
                });
              }
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.castAudio

castAudio(session: SessionToken | 'all', audioDevices: Array<audio.AudioDeviceDescriptor>): Promise\<void>

投播会话到指定设备列表。使用Promise异步回调。

调用此接口之前，需要导入`ohos.multimedia.audio`模块获取AudioDeviceDescriptor的相关描述。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名        | 类型           | 必填 | 说明 |
| ------------ | -------------- |------|------|
| session      | [SessionToken](#sessiontoken) &#124; 'all' | 是   | 会话令牌。SessionToken表示单个token；字符串'all'指所有token。 |
| audioDevices | Array\<[audio.AudioDeviceDescriptor](../apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor)\> | 是   | 媒体设备列表。  |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当投播成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info('Promise returned to indicate that the device list is obtained.');
  if (audioDevices !== undefined) {
    avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors).then(() => {
      console.info('Succeeded in casting audio.');
    });
  }
});
```

## avSession.castAudio

castAudio(session: SessionToken | 'all', audioDevices: Array<audio.AudioDeviceDescriptor>, callback: AsyncCallback\<void>): void

投播会话到指定设备列表。使用callback异步回调。

需要导入`ohos.multimedia.audio`模块获取AudioDeviceDescriptor的相关描述。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名       | 类型                                         | 必填 | 说明                                                         |
| ------------ |--------------------------------------------| ---- | ------------------------------------------------------------ |
| session      | [SessionToken](#sessiontoken) &#124; 'all' | 是   | 会话令牌。SessionToken表示单个token；字符串'all'指所有token。 |
| audioDevices | Array\<[audio.AudioDeviceDescriptor](../apis-audio-kit/arkts-apis-audio-i.md#audiodevicedescriptor)\>   | 是   | 媒体设备列表。 |
| callback     | AsyncCallback\<void>     | 是   | 回调函数。当投播成功，err为undefined，否则返回错误对象。      |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600102  | The session does not exist. |
| 6600104  | The remote session connection failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioRoutingManager = audioManager.getRoutingManager();
let audioDevices: audio.AudioDeviceDescriptors | undefined = undefined;
audioRoutingManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data) => {
  audioDevices = data;
  console.info('Promise returned to indicate that the device list is obtained.');
  if (audioDevices !== undefined) {
    avSession.castAudio('all', audioDevices as audio.AudioDeviceDescriptors, () => {
        console.info('Succeeded in casting audio.');
    });
  }
});
```

## avSession.startAVPlayback<sup>11+</sup>

startAVPlayback(bundleName: string, assetId: string): Promise\<void>

启动媒体播放应用程序。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名        | 类型           | 必填 | 说明 |
| ------------ | -------------- |------|------|
| bundleName   | string         | 是   | 指定应用包名。 |
| assetId      |string           | 是   | 指定媒体ID。  |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当播放成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

avSession.startAVPlayback("com.example.myapplication", "121278").then(() => {
  console.info('Succeeded in starting AV playback.');
});
```

## avSession.getDistributedSessionController<sup>18+</sup>

getDistributedSessionController(distributedSessionType: DistributedSessionType): Promise<Array\<AVSessionController>>

根据远端会话类型，获取远端分布式会话控制器。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                                                                      | 必填 | 说明      |
| --------- |-------------------------------------------------------------------------| ---- |---------|
| distributedSessionType | [DistributedSessionType](#distributedsessiontype18) | 是   | 远端会话类型。 |

**返回值：**

| 类型                                                                                 | 说明                                                                    |
|------------------------------------------------------------------------------------|-----------------------------------------------------------------------|
| Promise<Array<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\>> | Promise对象。返回对应类型的会话控制器实例列表，可查看会话ID，并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID   | 错误信息                                                                                                  |
|---------|-------------------------------------------------------------------------------------------------------|
| 201     | permission denied.                                                                                    |
| 202     | Not System App. |
| 6600101 | Session service exception.                                                                            |
| 6600109 | The remote connection is not established.                                                             |

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

avSession.getDistributedSessionController(avSession.DistributedSessionType.TYPE_SESSION_REMOTE).then((sessionControllers: Array<avSession.AVSessionController>) => {
  console.info(`Succeeded in getting distributed session controller, length: ${sessionControllers.length}`);
});
```


## SessionToken

会话令牌的信息。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

| 名称      | 类型   | 只读 | 可选 | 说明         |
| :-------- | :----- | :--- |:--- | :----------- |
| sessionId | string | 否 | 否   | 会话ID。       |
| pid       | number | 否  | 是 | 会话的进程ID。 |
| uid       | number | 否   | 是| 用户ID。       |

## avSession.on('sessionCreate') 

on(type: 'sessionCreate', callback: (session: AVSessionDescriptor) => void): void 

会话的创建事件监听。 使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager 

**系统接口：** 此接口为系统接口。 

**参数：** 
 
| 参数名    | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | 是   | 事件回调类型，支持的事件是'sessionCreate'：会话创建事件，检测到会话创建时触发。|
| callback | (session: [AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)) => void | 是   | 回调函数。参数为会话相关描述。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。 

| 错误码ID | 错误信息 | 
| -------- | ---------------------------------------- | 
| 202 | Not System App. | 
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. | 
| 6600101  | Session service exception. | 

 **示例：** 
```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
        Text(this.message)
          .onClick(()=>{
            avSession.on('sessionCreate', (descriptor: avSession.AVSessionDescriptor) => {
              console.info(`on sessionCreate : isActive : ${descriptor.isActive}`);
              console.info(`on sessionCreate : type : ${descriptor.type}`);
              console.info(`on sessionCreate : sessionTag : ${descriptor.sessionTag}`);
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}

```

## avSession.on('sessionDestroy') 

on(type: 'sessionDestroy', callback: (session: AVSessionDescriptor) => void): void 

会话的销毁事件监听。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager 

**系统接口：** 此接口为系统接口。 

**参数：** 

| 参数名   | 类型            | 必填 | 说明                                                         |
| -------- | ---------------| ---- | ------------------------------------------------------------ |
| type     | string         | 是   | 事件回调类型，支持的事件是'sessionDestroy'：会话销毁事件，检测到会话销毁时触发。|
| callback | (session: [AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)) => void | 是   | 回调函数。参数为会话相关描述。 |

 **错误码：** 

 以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。 
 
 | 错误码ID | 错误信息 | 
 | -------- | ---------------------------------------- | 
 | 202 | Not System App. | 
 | 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. | 
 | 6600101  | Session service exception. | 
 
**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
        Text(this.message)
          .onClick(()=>{
            avSession.on('sessionDestroy', (descriptor: avSession.AVSessionDescriptor) => {
              console.info(`on sessionDestroy : ${descriptor.sessionId}`);
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}
```
 
## avSession.on('topSessionChange') 

on(type: 'topSessionChange', callback: (session: AVSessionDescriptor) => void): void 

最新播放会话变更的事件监听。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager 

**系统接口：** 此接口为系统接口。 

**参数：** 

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | --------------------| ---- | ------------------------------------------------------------ |
| type     | string      | 是   | 事件回调类型，支持的事件是 'topSessionChange'：最新播放会话的变化事件，检测到最新的会话改变时触发。|
| callback | (session: [AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)) => void | 是   | 回调函数。参数为会话相关描述。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。 

| 错误码ID | 错误信息 | 
| -------- | ---------------------------------------- | 
| 202 | Not System App. | 
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. | 
| 6600101  | Session service exception. | 

**示例：** 

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
        Text(this.message)
          .onClick(()=>{
            avSession.on('topSessionChange', (descriptor: avSession.AVSessionDescriptor) => {
              console.info(`on topSessionChange : isActive : ${descriptor.isActive}`);
              console.info(`on topSessionChange : type : ${descriptor.type}`);
              console.info(`on topSessionChange : sessionTag : ${descriptor.sessionTag}`);
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.off('sessionCreate') 

off(type: 'sessionCreate', callback?: (session: AVSessionDescriptor) => void): void 

注销会话创建事件监听。注销后，不再接收该事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager 

**系统接口：** 此接口为系统接口。 

 **参数：**

| 参数名   | 类型       | 必填 | 说明       |
| -------- | ----------| ---- | ----------|
| type     | string    | 是   | 事件回调类型，支持的事件为：'sessionCreate'。|
| callback | (session: [AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)) => void | 否   | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。                               |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。 

| 错误码ID | 错误信息 | 
| -------- | ---------------------------------------- | 
| 202 | Not System App. | 
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. | 
| 6600101  | Session service exception. | 

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
        Text(this.message)
          .onClick(()=>{
            avSession.on('sessionCreate', (descriptor: avSession.AVSessionDescriptor) => {
            });
            avSession.off('sessionCreate');
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.off('sessionDestroy') 

off(type: 'sessionDestroy', callback?: (session: AVSessionDescriptor) => void): void 

注销会话销毁事件监听。注销后，不再监听该事件。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager 

**系统接口：** 此接口为系统接口。 

**参数：**

| 参数名   | 类型        | 必填 | 说明                      |
| -------- | -----------| ---- | -------------------------|
| type     | string     | 是   | 事件回调类型，支持的事件为'sessionDestroy'。|
| callback | (session: [AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)) => void | 否   | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。|

**错误码：** 

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。 

| 错误码ID | 错误信息 | 
| -------- | ---------------------------------------- | 
| 202 | Not System App. | 
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. | 
| 6600101  | Session service exception. | 

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
        Text(this.message)
          .onClick(()=>{
            avSession.on('sessionDestroy', (descriptor: avSession.AVSessionDescriptor) => {
            });
            avSession.off('sessionDestroy');
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.off('topSessionChange') 

off(type: 'topSessionChange', callback?: (session: AVSessionDescriptor) => void): void 

注销最新播放会话变更事件监听。注销后，不再进行该事件的监听。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager 

**系统接口：** 此接口为系统接口。 

**参数：**

| 参数名   | 类型              | 必填 | 说明                        |
| -------- | -----------------| ---- | ---------------------------- |
| type     | string           | 是   | 事件回调类型，支持的事件为'topSessionChange'。|
| callback | (session: [AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)) => void | 否   | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。 |

**错误码：** 

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。 

| 错误码ID | 错误信息 | 
| -------- | ---------------------------------------- | 
| 202 | Not System App. | 
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. | 
| 6600101  | Session service exception. | 

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
        Text(this.message)
          .onClick(()=>{
            avSession.on('topSessionChange', (descriptor: avSession.AVSessionDescriptor) => {
            });
            avSession.off('topSessionChange');
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.on('sessionServiceDie')

on(type: 'sessionServiceDie', callback: () => void): void

监听会话的服务死亡事件。通知应用清理资源。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 事件回调类型，支持事件'sessionServiceDie'：会话服务死亡事件，检测到会话的服务死亡时触发。 |
| callback | callback: () => void | 是   | 回调函数，当会话服务死亡时触发回调。                                |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.on('sessionServiceDie', () => {
  console.info('on sessionServiceDie : session is dead ');
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
| type     | string                 | 是    | 事件回调类型，支持事件'sessionServiceDie'：会话服务死亡事件。|
| callback | callback: () => void   | 否    | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avSession.off('sessionServiceDie');
```


## avSession.on('distributedSessionChange')<sup>18+</sup>

on(type: 'distributedSessionChange', distributedSessionType: DistributedSessionType, callback: Callback<Array\<AVSessionController>>): void

最新分布式远端会话变更的监听事件。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                                                  | 必填 | 说明                                                                       |
| -------- |-------------------------------------------------------------------------------------| ---- |--------------------------------------------------------------------------|
| type     | string                                                                              | 是   | 事件回调类型，支持的事件为 'distributedSessionChange'：最新远端分布式会话的变化事件，检测到最新的会话改变时触发。 |
| distributedSessionType     | [DistributedSessionType](#distributedsessiontype18)             | 是   | 远端会话类型。                                                                  |
| callback | Callback<Array<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\>> | 是   | 回调函数。参数为对应类型的会话控制器实例列表，可查看会话ID，并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID   | 错误信息                                                                                              |
|---------|---------------------------------------------------------------------------------------------------|
| 202     | Not System App. |
| 6600101 | Session service exception.                                                                        |

**示例：**

```ts
avSession.on('distributedSessionChange', avSession.DistributedSessionType.TYPE_SESSION_REMOTE, (sessionControllers: Array<avSession.AVSessionController>) => {
  console.info(`on distributedSessionChange size: ${sessionControllers.length}`);
});
```


## avSession.off('distributedSessionChange')<sup>18+</sup>

off(type: 'distributedSessionChange', distributedSessionType: DistributedSessionType, callback?: Callback<Array\<AVSessionController>>): void

取消最新分布式远端会话变更的监听事件，取消后，不再进行该事件的监听。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                                                  | 必填 | 说明                                                            |
| -------- |-------------------------------------------------------------------------------------|----|---------------------------------------------------------------|
| type     | string                                                                              | 是  | 事件回调类型，支持的事件为'distributedSessionChange'。                    |
| distributedSessionType     | [DistributedSessionType](#distributedsessiontype18)             | 是  | 远端会话类型。                                                       |
| callback | Callback<Array<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\>> | 否  | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID   | 错误信息                                                                                              |
|---------|---------------------------------------------------------------------------------------------------|
| 202     | Not System App. |
| 6600101 | Session service exception.                                                                        |

**示例：**

```ts
avSession.off('distributedSessionChange', avSession.DistributedSessionType.TYPE_SESSION_REMOTE);
```

## avSession.sendSystemAVKeyEvent

sendSystemAVKeyEvent(event: KeyEvent, callback: AsyncCallback\<void>): void

发送按键事件给置顶会话。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                  |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------- |
| event    | [KeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent) | 是   | 按键事件。                            |
| callback | AsyncCallback\<void>                                         | 是   | 回调函数。当事件发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**示例：**

```ts
import { KeyEvent } from '@kit.InputKit';

let keyItem: KeyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: KeyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event, () => {
    console.info('Succeeded in sending system AV key event.');
});
```

## avSession.sendSystemAVKeyEvent

sendSystemAVKeyEvent(event: KeyEvent): Promise\<void>

发送按键事件给置顶会话。使用Promise异步回调。

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

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600105  | Invalid session command. |

**示例：**

```ts
import { KeyEvent } from '@kit.InputKit';

let keyItem: KeyEvent.Key = {code:0x49, pressedTime:2, deviceId:0};
let event: KeyEvent.KeyEvent = {id:1, deviceId:0, actionTime:1, screenId:1, windowId:1, action:2, key:keyItem, unicodeChar:0, keys:[keyItem], ctrlKey:false, altKey:false, shiftKey:false, logoKey:false, fnKey:false, capsLock:false, numLock:false, scrollLock:false};

avSession.sendSystemAVKeyEvent(event).then(() => {
  console.info('Succeeded in sending system AV key event.');
});
```

## avSession.sendSystemControlCommand

sendSystemControlCommand(command: AVControlCommand, callback: AsyncCallback\<void>): void

发送控制命令给置顶会话。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| command  | [AVControlCommand](arkts-apis-avsession-i.md#avcontrolcommand10) | 是   | AVSession的相关命令和命令相关参数。   |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
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
// let cmd: avSession.AVControlCommandType = 'seek';
// let avcommand = {command:cmd, parameter:10};
// let cmd : avSession.AVControlCommandType = 'setSpeed';
// let avcommand = {command:cmd, parameter:2.6};
// let cmd : avSession.AVControlCommandType = 'setLoopMode';
// let avcommand = {command:cmd, parameter:avSession.LoopMode.LOOP_MODE_SINGLE};
// let cmd : avSession.AVControlCommandType = 'toggleFavorite';
// let avcommand = {command:cmd, parameter:"false"};
avSession.sendSystemControlCommand(avcommand, () => {
    console.info('Succeeded in sending system control command.');
});
```

## avSession.sendSystemControlCommand

sendSystemControlCommand(command: AVControlCommand): Promise\<void>

发送控制命令给置顶会话。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名  | 类型                                  | 必填 | 说明                                |
| ------- | ------------------------------------- | ---- | ----------------------------------- |
| command | [AVControlCommand](arkts-apis-avsession-i.md#avcontrolcommand10) | 是   | AVSession的相关命令和命令相关参数。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
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
avSession.sendSystemControlCommand(avcommand).then(() => {
  console.info('Succeeded in sending system control command.');
});
```

## ProtocolType<sup>10+</sup>

远端设备支持的协议类型。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| TYPE_CAST_PLUS_MIRROR      | 1    | Cast+的镜像模式。 <br> **系统接口：** 该接口为系统接口。 |

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(callback: AsyncCallback\<void>): void

开始设备搜索发现。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功并开始搜索，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |

**示例：**

```ts

avSession.startCastDeviceDiscovery(() => {
    console.info('Succeeded in starting cast device discovery.');
});
```

## DistributedSessionType<sup>18+</sup>

表示远端分布式设备支持的会话类型枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Message

**系统接口：** 该接口为系统接口。

| 名称                                     | 值 | 说明                        |
|----------------------------------------|---|---------------------------|
| TYPE_SESSION_REMOTE      | 0 | 远端设备会话。 |
| TYPE_SESSION_MIGRATE_IN  | 1 | 迁移至本端的设备会话。 |
| TYPE_SESSION_MIGRATE_OUT | 2 | 迁移至远端的设备会话。 |

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(filter: number, callback: AsyncCallback\<void>): void

指定过滤条件，开始设备搜索发现。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| filter | number | 是 | 进行设备发现的过滤条件，由ProtocolType通过按位或运算组合而成。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功并开始搜索，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**示例：**

```ts

let filter = 2;
avSession.startCastDeviceDiscovery(filter, () => {
    console.info('Succeeded in starting cast device discovery.');
});
```

## avSession.startCastDeviceDiscovery<sup>10+</sup>

startCastDeviceDiscovery(filter?: number, drmSchemes?: Array\<string>): Promise\<void>

开始设备搜索发现。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| filter | number | 否 | 进行设备发现的过滤条件，由ProtocolType通过按位或运算组合而成。 |
| drmSchemes | Array\<string> | 否 | 进行支持DRM资源播放的设备发现的过滤条件，由DRM uuid组合而成。 <br/>从API version 12开始支持该可选参数。|

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功并开始搜索，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**示例：**

```ts

let filter = 2;
let drmSchemes = ['3d5e6d35-9b9a-41e8-b843-dd3c6e72c42c'];
avSession.startCastDeviceDiscovery(filter, drmSchemes).then(() => {
  console.info('Succeeded in starting cast device discovery.');
});
```

## avSession.stopCastDeviceDiscovery<sup>10+</sup>

stopCastDeviceDiscovery(callback: AsyncCallback\<void>): void

结束设备搜索发现。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当成功停止搜索，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |

**示例：**

```ts

avSession.stopCastDeviceDiscovery(() => {
    console.info('Succeeded in stopping cast device discovery.');
});
```

## avSession.stopCastDeviceDiscovery<sup>10+</sup>

stopCastDeviceDiscovery(): Promise\<void>

结束设备搜索发现。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当成功停止搜索，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |

**示例：**

```ts

avSession.stopCastDeviceDiscovery().then(() => {
  console.info('Succeeded in stopping cast device discovery.');
});
```

## avSession.setDiscoverable<sup>10+</sup>

setDiscoverable(enable: boolean, callback: AsyncCallback\<void>): void

设置设备是否可被发现，用于投播接收端。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| enable | boolean | 是 | 是否允许本设备被发现。true表示允许被发现，false表示不允许被发现。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当设置成功，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**示例：**

```ts

avSession.setDiscoverable(true, () => {
    console.info('Succeeded in setting discoverable.');
});
```

## avSession.setDiscoverable<sup>10+</sup>

setDiscoverable(enable: boolean): Promise\<void>

设置设备是否可被发现，用于投播接收端。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| enable | boolean | 是 | 是否允许本设备被发现。true表示允许被发现，false表示不允许被发现。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |

**示例：**

```ts

avSession.setDiscoverable(true).then(() => {
  console.info('Succeeded in setting discoverable.');
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
| type     | string               | 是   | 事件回调类型，支持事件'deviceAvailable'，有设备被发现时触发回调。 |
| callback | (device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void | 是   | 回调函数，参数device是可用设备信息。                                |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
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
| type     | string                 | 是    | 事件回调类型，支持事件'deviceAvailable'：设备发现回调。|
| callback     | (device: [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)) => void                 | 否    | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
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
| type     | string               | 是   | 事件回调类型，支持事件'deviceOffline'，有设备下线时触发回调。 |
| callback | (deviceId: string) => void | 是   | 回调函数，参数deviceId是设备的ID。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
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

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                    | 必填  |      说明                                               |
| ------   | ---------------------- | ---- | ------------------------------------------------------- |
| type     | string                 | 是    | 事件回调类型，支持事件'deviceOffline'：设备下线回调。|
| callback | (deviceId: string) => void | 否   | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。其中参数deviceId是设备的ID。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
avSession.off('deviceOffline');
```

## avSession.getAVCastController<sup>10+</sup>

getAVCastController(sessionId: string, callback: AsyncCallback\<AVCastController>): void

设备建立连接后，获取投播控制器。使用callback异步回调。

此功能在本端和远端都可以使用，通过该接口可以获取一个相同的控制器，进行投播音频的播放控制。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名    | 类型                                                        | 必填 | 说明                                                         |
| --------- | ----------------------------------------------------------- | ---- |------------------------------------------------------------ |
| sessionId | string                    | 是   |用于指定要获取的投播控制器的sessionId。 |
| callback  | AsyncCallback<[AVCastController](#avcastcontroller10)\> | 是   | 回调函数，返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception |
| 6600102  | session does not exist |

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          // 获取当前系统中所有session的描述符。
          let descriptors = await AVSessionManager.getAllSessionDescriptors();
          if (descriptors.length === 0) {
            console.error(`No session in system, can not create controller.`);
            return;
          }
          // 取目标session的sessionId创建controller。
          let sessionId = descriptors[0].sessionId;

          let avCastController: avSession.AVCastController;
          avSession.getAVCastController(sessionId, (avcontroller: avSession.AVCastController) => {
            avCastController = avcontroller;
            console.info('Succeeded in getting AV cast controller.');
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
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
| sessionId | string                    | 是   |用于指定要获取的投播控制器的sessionId。 |

**返回值：**

| 类型                                                        | 说明             |
| --------- | ------------------------------------------------------------ |
| Promise<[AVCastController](#avcastcontroller10)\>  | Promise对象。返回投播控制器实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | server exception |
| 6600102  | The session does not exist |

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(async () => {
          // 获取当前系统中所有session的描述符。
          let descriptors = await AVSessionManager.getAllSessionDescriptors();
          if (descriptors.length === 0) {
            console.error(`No session in system, can not create controller.`);
            return;
          }
          // 取目标session的sessionId创建controller。
          let sessionId = descriptors[0].sessionId;

          let avCastController: avSession.AVCastController;
          avSession.getAVCastController(sessionId).then((avcontroller: avSession.AVCastController) => {
            avCastController = avcontroller;
            console.info('Succeeded in getting AV cast controller.');
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.startCasting<sup>10+</sup>

startCasting(session: SessionToken, device: OutputDeviceInfo, callback: AsyncCallback\<void>): void

启动投播。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | 是   | 会话令牌。SessionToken表示单个token。 |
| device | [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)                        | 是   | 设备相关信息。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当命令发送成功并启动投播，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600108 | Device connection failed.       |

**示例：**

```ts

let sessionId = 'xxx'; // sessionId需要通过avSession.createAVSession创建会话后获取。
let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
let castDevice: avSession.OutputDeviceInfo | undefined = undefined;
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {
  castDevice = device;
  console.info(`on deviceAvailable  : ${device} `);
  if (castDevice !== undefined) {
    avSession.startCasting(myToken, castDevice, () => {
        console.info('Succeeded in starting casting.');
    });
  }
});
```


## avSession.startCasting<sup>10+</sup>

startCasting(session: SessionToken, device: OutputDeviceInfo): Promise\<void>

启动投播。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES，仅系统应用可用。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | 是   | 会话令牌。SessionToken表示单个token。 |
| device | [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)                        | 是   | 设备相关信息。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当命令发送成功并启动投播，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600101  | Session service exception. |
| 6600108 | Device connection failed.       |

**示例：**

```ts

let sessionId = 'xxx'; // sessionId需要通过avSession.createAVSession创建会话后获取。
let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
let castDevice: avSession.OutputDeviceInfo | undefined = undefined;
avSession.on('deviceAvailable', (device: avSession.OutputDeviceInfo) => {
  castDevice = device;
  console.info(`on deviceAvailable  : ${device} `);
  if (castDevice !== undefined) {
    avSession.startCasting(myToken, castDevice).then(() => {
      console.info('Succeeded in starting casting.');
    });
  }
});
```

## avSession.stopCasting<sup>10+</sup>

stopCasting(session: SessionToken, callback: AsyncCallback\<void>): void

结束投播。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| session      | [SessionToken](#sessiontoken) | 是   | 会话令牌。SessionToken表示单个token。 |
| callback | AsyncCallback\<void>                  | 是   | 回调函数。当成功结束投播，err为undefined，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts

let sessionId = 'xxx'; // sessionId需要通过avSession.createAVSession创建会话后获取。
let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken, () => {
    console.info('Succeeded in stopping casting.');
});
```

## avSession.stopCasting<sup>10+</sup>

stopCasting(session: SessionToken): Promise\<void>

结束投播。使用Promise异步回调。

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

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts

let sessionId = 'xxx'; // sessionId需要通过avSession.createAVSession创建会话后获取。
let myToken: avSession.SessionToken = {
  sessionId: sessionId,
}
avSession.stopCasting(myToken).then(() => {
  console.info('Succeeded in stopping casting.');
});
```

## avSession.startDeviceLogging<sup>13+</sup>

startDeviceLogging(url: string, maxSize?: number): Promise\<void>

开始将设备日志写入文件。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                  |
| -------- | ------------------------------------- | ---- | ------------------------------------- |
| url | string                   | 是   | 目标文件描述符（打开文件的唯一标识）。 |
| maxSize | number                   | 否   | 写入最大日志大小（以kB为单位）。 |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当设备日志写入文件成功时，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 401        | Parameter check failed. 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**示例：**

```ts
import { fileIo } from '@kit.CoreFileKit';

async function startDeviceLogging() {
  let file = await fileIo.open("filePath");
  let url = file.fd.toString();
  avSession.startDeviceLogging(url, 2048).then(() => {
    console.info('Succeeded in starting device logging.');
  });
}
```

## avSession.stopDeviceLogging<sup>13+</sup>

stopDeviceLogging(): Promise\<void>

停止当前设备日志写入。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。当停止当前设备日志写入，无返回结果，否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202        | Not System App. |
| 6600101    | Session service exception. |
| 6600102    | The session does not exist. |

**示例：**

```ts
avSession.stopDeviceLogging().then(() => {
  console.info('Succeeded in stopping device logging.');
});
```

## avSession.on('deviceLogEvent')<sup>13+</sup>

on(type: 'deviceLogEvent', callback: Callback\<DeviceLogEventCode>): void

监听日志事件的回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- |------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件'deviceLogEvent'。 |
| callback | (callback: [DeviceLogEventCode](#devicelogeventcode13)) => void        | 是   | 回调函数，参数DeviceLogEventCode是当前设备日志返回值。                      |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

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
| -------- | ------------------------------------------------------------ | ---- |------------------------------------------------------------ |
| type     | string                                                       | 是   | 需要取消的监听事件类型，当前支持的事件类型为'deviceLogEvent'。 |
| callback | (callback: [DeviceLogEventCode](#devicelogeventcode13)) => void        | 否  | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。            |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。。

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

## DeviceState<sup>20+</sup>

投播设备的连接状态。

**系统接口：** 该接口为系统接口。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

| 名称            | 类型   | 只读 |  可选 | 说明         |
| :------------- | :----- | :--- | :--- | :----------- |
| deviceId       | string | 是   | 否    | 投播设备ID。       |
| deviceState    | number | 是   | 否    | 投播设备连接状态码。 |
| reasonCode     | number | 是   | 否    | 投播设备连接错误码。 |
| radarErrorCode | number | 是   | 否    | 系统雷达错误码。 |

## avSession.on('deviceStateChanged')<sup>20+</sup>

on(type: 'deviceStateChanged', callback: Callback\<DeviceState\>): void

投播设备连接状态的回调函数。

**系统接口：** 该接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                          | 必填  | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- |------------------------------------------------------------ |
| type     | string                                                       | 是   | 事件回调类型，支持事件'deviceStateChanged'，投播设备连接状态发生变化时触发回调。 |
| callback | (callback: [DeviceState](#devicestate20)) => void            | 是   | 回调函数，参数DeviceState包含投播设备ID、连接状态码、连接错误码和系统雷达错误码。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201        | Permission denied. |
| 202        | Not System App. |

**示例：**

```ts
avSession.on('deviceStateChanged', (state: avSession.DeviceState) => {
  console.info(`on deviceStateChanged state, deviceId=${state.deviceId}, connect status=${state.deviceState},
    reasonCode=${state.reasonCode}, radarErrorCode=${state.radarErrorCode}`)
})
```

## avSession.off('deviceStateChanged')<sup>20+</sup>

off(type: 'deviceStateChanged', callback?: Callback\<DeviceState>): void

取消投播设备连接状态的监听。

**系统接口：** 该接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**参数：**

| 参数名   | 类型                                                          | 必填  | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | 是   | 需要取消的监听事件类型，当前支持的事件类型为'deviceStateChanged'，投播设备连接状态变化的回调。 |
| callback | (callback: [DeviceState](#devicestate20)) => void            | 否   | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201        | Permission denied. |
| 202        | Not System App. |

**示例：**

```ts
avSession.off('deviceStateChanged');
```

## AVCastController<sup>10+</sup>

投播建立后，调用[avSession.getAVCastController](arkts-apis-avsession-AVSession.md#getavcastcontroller10)可返回会话控制器实例。控制器可查看会话ID，并可完成对会话发送命令及事件，获取会话元数据，播放状态信息等操作。

### setDisplaySurface<sup>10+</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

设置播放的surfaceId，在投播sink端使用。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                         |
| -------- | --------------------------------------------------- | ---- | ---------------------------- |
| surfaceId | string | 是   | 设置播放的surfaceId。 |

**返回值：**

| 类型                                          | 说明                        |
| --------------------------------------------- | --------------------------- |
| Promise\<void> | Promise对象。返回设置结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { media } from '@kit.MediaKit';

let surfaceID: string = '';
media.createAVRecorder().then((avRecorder) => {
  avRecorder.getInputSurface((surfaceId: string) => {
    console.info('Succeeded in getting input surface.');
    surfaceID = surfaceId;
    if (surfaceID) {
      // 需先通过avSession.getAVCastController获取avCastController实例。
      avCastController.setDisplaySurface(surfaceID).then(() => {
        console.info('Succeeded in setting display surface.');
      });
    }
  });
})
```

### setDisplaySurface<sup>10+</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

设置播放的surfaceId，在投播sink端使用。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                         |
| -------- | --------------------------------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数，返回当前设置结果。 |
| surfaceId | string | 是   | 设置播放的surfaceId。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202 | Not System App. |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600109  | The remote connection is not established. |

**示例：**

```ts
import { media } from '@kit.MediaKit';

let surfaceID: string = '';
media.createAVRecorder().then((avRecorder) => {
  avRecorder.getInputSurface((surfaceId: string) => {
    console.info('Succeeded in getting input surface.');
    surfaceID = surfaceId;
    if (surfaceID) {
      // 需先通过avSession.getAVCastController获取avCastController实例。
      avCastController.setDisplaySurface(surfaceID, () => {
          console.info('Succeeded in setting display surface.');
      });
    }
  });
})
```

### on('videoSizeChange')<sup>12+</sup>

on(type: 'videoSizeChange', callback: (width:number, height:number) => void): void

设置video尺寸更改监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- |---- |
| type     | string      | 是   | 事件回调类型，支持事件'videoSizeChange'：当video尺寸更改时，触发该事件。 |
| callback | (width:number, height:number) => void    | 是   | 回调函数，返回video的宽度和高度。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
// 需先通过avSession.getAVCastController获取avCastController实例。
avCastController.on('videoSizeChange', (width: number, height: number) => {
  console.info(`width ：${width} `);
  console.info(`height：${height} `);
});
```

### off('videoSizeChange')<sup>12+</sup>

off(type: 'videoSizeChange'): void

取消设置video尺寸更改监听事件。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

**参数：**

| 参数名   | 类型     | 必填 | 说明      |
| -------- | ------------------------------------------------------------ | ---- |---- |
| type     | string  | 是   | 需要取消的监听事件类型，当前支持的事件类型为'videoSizeChange'。    |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 6600101  | Session service exception. |

**示例：**

```ts
avCastController.off('videoSizeChange');
```

## avSession.onActiveSessionChanged<sup>23+</sup>

function onActiveSessionChanged(callback: Callback<Array\<AVSessionDescriptor>>): void

允许在系统控制入口显示的会话变更的监听事件。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | --------------------| ---- | ------------------------------------------------------------ |
| callback | Callback\<Array\<[AVSessionDescriptor](#avsessiondescriptor)\>\> | 是   | 回调函数。参数为允许在系统控制入口显示的会话信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 |  Not System App. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(() => {
          avSession.onActiveSessionChanged((descs: Array<avSession.AVSessionDescriptor>) => {
            descs.forEach((desc, index) => {
              console.info(`=== 会话 ${index + 1}/${descs.length} ===`);
              console.info(`on onActiveSessionChanged : isActive : ${desc.isActive}`);
              console.info(`on onActiveSessionChanged : type : ${desc.type}`);
              console.info(`on onActiveSessionChanged : sessionTag : ${desc.sessionTag}`);
            });
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.offActiveSessionChanged<sup>23+</sup>

function offActiveSessionChanged(callback?: Callback<Array\<AVSessionDescriptor>>): void

取消允许在系统控制入口显示的会话变更事件监听，取消后将不再对该事件进行监听。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | --------------------| ---- | ------------------------------------------------------------ |
| callback | Callback\<Array\<[AVSessionDescriptor](#avsessiondescriptor)\>\> | 否   | 回调函数，参数为允许在系统控制入口显示的会话信息列表。<br>该参数为可选参数，若不填写该参数，则认为取消所有允许在系统控制入口显示的会话变更事件监听。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
| 202 |  Not System App. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(() => {
          avSession.onActiveSessionChanged((descriptors: Array<avSession.AVSessionDescriptor>) => {
          });
          avSession.offActiveSessionChanged();
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## AVQueueInfo<sup>11+</sup>

歌单（歌曲列表）的相关属性。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**系统接口：** 该接口为系统接口。

| 名称            | 类型                      | 只读 | 可选 | 说明                                                                  |
| --------------- |-------------------------| ---- |-------|-------------------------------------------------------------- |
| bundleName      | string                  | 否 | 否   | 歌单所属应用包名。                                                        |
| avQueueName     | string                  | 否 | 否   | 歌单（歌曲列表）名称。                                                    |
| avQueueId       | string                  | 否 | 否   | 歌单（歌曲列表）唯一标识Id。                                               |
| avQueueImage    | image.PixelMap &#124; string |否 | 否   | 歌单（歌曲列表）封面图，图片的像素数据或者图片路径地址（本地路径或网络路径）。     |
| lastPlayedTime  | number                  | 否 |是  | 歌单最后播放时间。单位为毫秒（ms）。参考基准：Unix时间戳。                                                        |

## DeviceInfo<sup>10+</sup>

播放设备的相关信息。

| 名称       | 类型           | 只读 | 可选 | 说明                   |
| ---------- | -------------- | ---- | ----|------------------ |
| ipAddress | string | 否 | 是  | 播放设备的IP地址。<br/>**系统接口：** 该接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast     |
| providerId | number | 否    | 是 | 播放设备提供商。<br/>**系统接口：** 该接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast    |
| authenticationStatus<sup>11+</sup> | number | 否  | 是 | 播放设备是否可信。默认为0。0代表设备不可信，1代表设备可信。<br/>**系统接口：** 该接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast    |
| networkId<sup>13+</sup> | string | 否  |是 | 播放设备的网络ID。<br/>**系统接口：** 该接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast|
|isLegacy<sup>13+</sup> | boolean | 否 | 是 | 表示当前设备是否为旧版设备。 true表示是，false表示不是。 <br/>**系统接口：** 该接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.AVCast     |
|mediumTypes<sup>13+</sup>| number | 否  | 是  |用于发现设备的介质类型。<br>1：蓝牙低功耗（BLE），用于蓝牙设备的发现和链接。 <br> 2：受限应用协议（COAP），用于局域网内的设备发现。<br/>**系统接口：** 该接口为系统接口。<br> **系统能力：**  SystemCapability.Multimedia.AVSession.AVCast        |

## AVSessionDescriptor

会话的相关描述信息。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

| 名称          | 类型              | 只读 | 可选 | 说明  |
| --------------| ---------------- | ---------------- | ---------------- |------|
| outputDevice | [OutputDeviceInfo](arkts-apis-avsession-i.md#outputdeviceinfo10)    | 否 | 否 | 分布式设备相关信息。<br/>**系统接口：** 该接口为系统接口。<br> **系统能力：** SystemCapability.Multimedia.AVSession.Manager        |

## DeviceLogEventCode<sup>13+</sup>

设备日志事件返回值的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.AVCast

**系统接口：** 该接口为系统接口。

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| DEVICE_LOG_FULL       | 1    | 日志已满。    |
| DEVICE_LOG_EXCEPTION       | 2    | 日志写入异常。 |

## SessionCategory<sup>22+</sup>

表示不同场景会话类别的枚举。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**系统接口：** 此接口为系统接口。

| 名称                |  值  | 说明         |
| --------------------| ---- | ----------- |
| CATEGORY_ACTIVE     |  1   | 允许在系统控制入口显示的会话类别。 |
| CATEGORY_NOT_ACTIVE |  2   | 禁止在系统控制入口显示的会话类别。 |
| CATEGORY_ALL        |  3   | 所有会话类别。 |

## ConnectionState

表示连接状态的枚举，仅包含系统接口部分。完整枚举定义请参见[ConnectionState](arkts-apis-avsession-e.md#connectionstate10)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| STATE_AUTHENTICATING      | 10    | 与远端设备连接认证中。 |
| STATE_MIRROR_TO_STREAM      | 11    | 从镜像模式切换到音视频投播。 |
| STATE_STREAM_TO_MIRROR      | 12    | 从音视频投播切换到镜像模式。 |

## ExtraKey

表示定义在不同场景中使用的额外键的枚举，仅包含系统接口部分。完整枚举定义请参见[ExtraKey](arkts-apis-avsession-e.md#extrakey)。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

| 名称                        | 值   | 说明         |
| --------------------------- | ---- | ----------- |
| LIVE_VIEW_HIDDEN_WHEN_KEYGUARD      | 'hw_live_view_hidden_when_keyguard'    | 作为[setExtras](arkts-apis-avsession-AVSession.md#setextras10)接口传入的键，值传入bool类型列表，用于通知系统在锁屏时是否隐藏实况窗卡片。 |