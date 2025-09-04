# Functions
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { avSession } from '@kit.AVSessionKit';
```

## avSession.createAVSession<sup>10+</sup>

createAVSession(context: Context, tag: string, type: AVSessionType): Promise\<AVSession>

创建会话对象，一个应用进程仅允许存在一个会话，重复创建会失败，结果通过Promise异步回调方式返回。

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
| Promise<[AVSession](arkts-apis-avsession-AVSession.md)\> | Promise对象。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。|

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
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
            console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
            }).catch((err: BusinessError) => {
            console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
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

创建会话对象，一个应用程序仅允许存在一个会话，重复创建会失败，结果通过callback异步回调方式返回。

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| context| [Context](../apis-ability-kit/js-apis-inner-app-context.md) | 是| 需要使用UIAbilityContext，用于系统获取应用组件的相关信息。     |
| tag      | string                                  | 是   | 会话的自定义名称。                                           |
| type     | [AVSessionType](arkts-apis-avsession-t.md#avsessiontype10)         | 是   | 会话类型。                               |
| callback | AsyncCallback<[AVSession](arkts-apis-avsession-AVSession.md)\> | 是   | 回调函数。回调返回会话实例对象，可用于获取会话ID，以及设置元数据、播放状态，发送按键事件等操作。 |

**错误码：**

以下错误码的详细介绍请参见[媒体会话管理错误码](errorcode-avsession.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 |  parameter check failed. 1.Mandatory parameters are left unspecified. 2.Parameter verification failed. |
| 6600101  | Session service exception. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
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

          avSession.createAVSession(context, tag, "audio", async (err: BusinessError, data: avSession.AVSession) => {
            if (err) {
              console.error(`CreateAVSession BusinessError: code: ${err.code}, message: ${err.message}`);
            } else {
              currentAVSession = data;
              sessionId = currentAVSession.sessionId;
              console.info(`CreateAVSession : SUCCESS : sessionId = ${sessionId}`);
            }
          });
        })
    }
    .width('100%')
    .height('100%')
  }
}
```
