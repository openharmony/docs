# Functions
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { avSession } from '@kit.AVSessionKit';
```

## avSession.createAVSession<sup>10+</sup>

createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>

创建会话对象，一个应用进程仅允许存在一个会话，重复创建会失败，使用Promise异步回调。

> **说明：**
> 
> 在业务执行阶段需要保持AVSession对象存活，避免后台管控静音、设备选择异常、通知/锁屏/胶囊播控卡片显示异常等情况。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                           |
| ------ | ------------------------------- | ---- | ------------------------------ |
| context| [Context](../apis-ability-kit/js-apis-inner-app-context.md) | 是| 需要使用UIAbilityContext，用于系统获取应用组件的相关信息。 |
| tag    | string                          | 是   | 会话的自定义名称。             |
| type   | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10) | 是   | 会话类型。 |

**返回值：**

| 类型                              | 说明                                                         |
| --------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSession](arkts-apis-avsession-AVSession.md)\> | Promise对象。返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
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
            let currentAVSession: avSession.AVSession;
            let tag = "createNewSession";
            let context: Context = this.getUIContext().getHostContext() as Context;
            let sessionId: string;  // 供后续函数入参使用。

            avSession.createAVSession(context, tag, "audio").then(async (data: avSession.AVSession) => {
            currentAVSession = data;
            sessionId = currentAVSession.sessionId;
            console.info(`Succeeded in creating AV session, sessionId: ${sessionId}`);
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.createAVSession<sup>10+</sup>

createAVSession(context: Context, tag: string, type: AVSessionType, callback: AsyncCallback\<AVSession>): void

创建会话对象，一个应用进程仅允许存在一个会话，重复创建会失败，使用callback异步回调。

> **说明：**
> 
> 在业务执行阶段需要保持AVSession对象存活，避免后台管控静音、设备选择异常、通知/锁屏/胶囊播控卡片显示异常等情况。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context| [Context](../apis-ability-kit/js-apis-inner-app-context.md) | 是| 需要使用UIAbilityContext，用于系统获取应用组件的相关信息。     |
| tag      | string                                  | 是   | 会话的自定义名称。                                           |
| type     | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10)         | 是   | 会话类型。                               |
| callback | AsyncCallback<[AVSession](arkts-apis-avsession-AVSession.md)\> | 是   | 回调函数。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'hello world';

  build() {
    Column() {
      Text(this.message)
        .onClick(()=>{
          let currentAVSession: avSession.AVSession;
          let tag = "createNewSession";
          let context: Context = this.getUIContext().getHostContext() as Context;
          let sessionId: string;  // 供后续函数入参使用。

          avSession.createAVSession(context, tag, "audio", async (err:BusinessError, data: avSession.AVSession) => {
              if (err) {
                console.error(`Failed to create AV session, error code: ${err.code}, error message: ${err.message}`);
                return;
              }
              currentAVSession = data;
              sessionId = currentAVSession.sessionId;
              console.info(`Succeeded in creating AV session, sessionId: ${sessionId}`);
            });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.getAVSession<sup>22+</sup>

getAVSession(context: Context): Promise\<AVSession>

获取会话对象。使用Promise异步回调。

该接口可将当前进程已创建过的会话对象返回，如果没有创建过会话对象，该接口调用会失败并抛出异常。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                           |
| ------ | ------------------------------- | ---- | ------------------------------ |
| context| [Context](../apis-ability-kit/js-apis-inner-app-context.md) | 是| 需要使用UIAbilityContext，用于系统获取应用组件的相关信息。 |

**返回值：**

| 类型                              | 说明                                                         |
| --------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSession](arkts-apis-avsession-AVSession.md)\> | Promise对象。返回会话实例对象，可用于获取会话ID、设置元数据及播放状态、发送按键事件等操作。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
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
            let currentAVSession: avSession.AVSession;
            let context: Context = this.getUIContext().getHostContext() as Context;
            let sessionId: string;  // 供后续函数入参使用。
            let sessionTag: string;

            avSession.getAVSession(context).then(async (data: avSession.AVSession) => {
              currentAVSession = data;
              sessionId = currentAVSession.sessionId;
              sessionTag = currentAVSession.sessionTag;
              console.info(`Succeeded in getting AV session, sessionId: ${sessionId}, sessionTag: ${sessionTag}`);
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.getAllSessionDescriptors<sup>23+</sup>

getAllSessionDescriptors(): Promise\<Array\<Readonly\<AVSessionDescriptor>>>

获取所有设置过媒体信息且注册过控制回调的会话的描述符信息。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES 或 ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC
系统应用可以从ohos.permission.MANAGE_MEDIA_RESOURCES或ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC两个权限中选择一个进行申请，普通应用仅允许申请ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC受限权限。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise\<Array\<Readonly\<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\>\>\> | Promise对象。返回所有会话描述的只读对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
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
            avSession.getAllSessionDescriptors().then((descriptors: avSession.AVSessionDescriptor[]) => {
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

## avSession.createController<sup>23+</sup>

createController(sessionId: string): Promise\<AVSessionController>

根据会话ID创建会话控制器。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES 或 ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC
系统应用可以从ohos.permission.MANAGE_MEDIA_RESOURCES或ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC两个权限中选择一个进行申请，普通应用仅允许申请ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC受限权限。

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**参数：**

| 参数名    | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | -------- |
| sessionId | string | 是   | 会话ID。 |

**返回值：**

| 类型                                                  | 说明                                                         |
| ----------------------------------------------------- | ------------------------------------------------------------ |
| Promise<[AVSessionController](arkts-apis-avsession-AVSessionController.md)\> | Promise对象。返回会话控制器实例，可查看会话ID，<br>并完成对会话发送命令及事件，获取元数据、播放状态信息等操作。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
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
              if (descriptors.length > 0 ) {
                avSession.createController(descriptors[0]?.sessionId).then((avcontroller: avSession.AVSessionController) => {
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

## avSession.onSessionCreate<sup>23+</sup>

onSessionCreate(callback: Callback\<AVSessionDescriptor>): void

监听会话创建事件。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**参数：**

| 参数名    | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| callback | Callback\<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\> | 是   | 回调函数。参数为会话相关描述。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
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
            avSession.onSessionCreate((descriptor: avSession.AVSessionDescriptor) => {
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

## avSession.onSessionDestroy<sup>23+</sup>

onSessionDestroy(callback: Callback\<AVSessionDescriptor>): void

监听会话的销毁事件。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**参数：**

| 参数名   | 类型            | 必填 | 说明                                                         |
| -------- | ---------------| ---- | ------------------------------------------------------------ |
| callback | Callback\<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\> | 是   | 回调函数。参数为会话相关描述。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied.|
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
            avSession.onSessionDestroy((descriptor: avSession.AVSessionDescriptor) => {
              console.info(`on sessionDestroy : ${descriptor.sessionId}`);
            });
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.onTopSessionChange<sup>23+</sup>

onTopSessionChange(callback: Callback\<AVSessionDescriptor>): void

监听最新播放会话变更的事件。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | --------------------| ---- | ------------------------------------------------------------ |
| callback | Callback\<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\> | 是   | 回调函数。参数为会话相关描述。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
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
            avSession.onTopSessionChange((descriptor: avSession.AVSessionDescriptor) => {
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

## avSession.offSessionCreate<sup>23+</sup>

offSessionCreate(callback?: Callback\<AVSessionDescriptor>): void

注销会话创建事件监听。注销后，不再接收该事件。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**参数：**

| 参数名   | 类型       | 必填 | 说明       |
| -------- | ----------| ---- | ----------|
| callback | Callback\<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\> | 否   | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
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
            avSession.onSessionCreate((descriptor: avSession.AVSessionDescriptor) => {
            });
            avSession.offSessionCreate();
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.offSessionDestroy<sup>23+</sup>

offSessionDestroy(callback?: Callback\<AVSessionDescriptor>): void

注销会话销毁事件监听。注销后，不再监听该事件。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**参数：**

| 参数名   | 类型        | 必填 | 说明                      |
| -------- | -----------| ---- | -------------------------|
| callback | Callback\<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\> | 否   | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
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
            avSession.onSessionDestroy((descriptor: avSession.AVSessionDescriptor) => {
            });
            avSession.offSessionDestroy();
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.offTopSessionChange<sup>23+</sup>

offTopSessionChange(callback?: Callback\<AVSessionDescriptor>): void

注销最新播放会话变更事件监听。注销后，不再进行该事件的监听。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES_FOR_PUBLIC

**系统能力：** SystemCapability.Multimedia.AVSession.Manager

**参数：**

| 参数名   | 类型              | 必填 | 说明                        |
| -------- | -----------------| ---- | ---------------------------- |
| callback | Callback\<[AVSessionDescriptor](arkts-apis-avsession-i.md#avsessiondescriptor23)\> | 否   | 需要取消的回调函数，与on接口注册时的回调函数保持一致。如果不填写该参数，则取消所有已注册的回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | permission denied. |
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
            avSession.offTopSessionChange((descriptor: avSession.AVSessionDescriptor) => {
            });
            avSession.offTopSessionChange();
          })
      }
    .width('100%')
    .height('100%')
  }
}
```

## avSession.isDesktopLyricSupported<sup>23+</sup>

isDesktopLyricSupported(): Promise\<boolean>

设备是否支持桌面歌词功能。使用Promise异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**返回值：**

| 类型                       | 说明                               |
|----------------------------|-----------------------------------|
| Promise\<boolean> | Promise对象。返回true表示设备支持桌面歌词功能；返回false表示设备不支持桌面歌词功能。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID   | 错误信息                                             |
|---------|--------------------------------------------------------|
| 6600101 | Session service exception.                             |

**示例：**

```ts
import { avSession } from '@kit.AVSessionKit';

avSession.isDesktopLyricSupported().then((isSupported: boolean) => {
  console.info(`Succeeded in checking desktop lyric supported: ${isSupported}`);
});
```
