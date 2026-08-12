# AgentProxy (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

AgentProxy用于从客户端向[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)服务端发送数据或安全认证请求。

> **说明：**
>
>  - 本模块首批接口从API version 24开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口均为系统接口。
>  - 本模块接口仅可在Stage模型下使用。
>  - 本模块接口需要在主线程中使用，不支持在Worker、TaskPool等子线程中使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## AgentProxy

### sendData
sendData(data: string): void

客户端调用此接口向AgentExtensionAbility服务端发送数据。

**原子化服务API**：从 API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | ------------ |
| data   | string | 是   | 待发送给AgentExtensionAbility服务端的数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                     |
| -------- | ----------------------------|
| 35600002 | Failed to send the IPC message. |

**示例：**

```ts
import { common, Want, agentManager} from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Extension] ';

@Entry
@Component
struct AgentExtensionAbility {
  comProxy: common.AgentProxy | null = null;
  dataCallBack: common.AgentExtensionConnectCallback = {
    onData: (data: string) => {
      console.info(`${TAG} dataCallBack received data: ${data}.`);
    },
    onAuth: (handshakeData: string): void => {
      console.info(`onAuth, data: ${handshakeData}.`);
    },
    onDisconnect: () => {
      console.info(`${TAG} dataCallBack onDisconnect.`);
      this.comProxy = null;
    }
  }

  build() {
    Scroll() {
      Column() {
        // 创建一个连接AgentExtension的按钮
        Button('connectAgentExtensionAbility', { type: ButtonType.Capsule, stateEffect: true })
          .margin({
            top: 5,
            left: 10,
            right: 10,
            bottom: 5
          })
          .alignRules({
            center: { anchor: '__container__', align: VerticalAlign.Center },
            middle: { anchor: '__container__', align: HorizontalAlign.Center }
          })
          .onClick(() => {
            this.myConnectAgentExtensionAbility()
          });
      }
      .width('100%')
    }
    .height('100%')
  }

  // 自定义连接AgentExtension的函数
  myConnectAgentExtensionAbility() {
    let startWant: Want = {
      deviceId: '',
      bundleName: 'com.acts.myapplication',
      abilityName: 'AgentExtensionAbility'
    };

    try {
      let agentId: string = 'test';
      // 连接AgentExtension
      agentManager.connectAgentExtensionAbility(startWant, agentId, this.dataCallBack)
        .then((proxy: common.AgentProxy) => {
          console.info(TAG + `try to connectAgentExtensionAbility ${proxy}`);
          this.comProxy = proxy;
          try {
            console.info(`${TAG} sendData.`);
            // 给AgentExtension发送数据
            this.comProxy.sendData('hello');
          } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error(`${TAG} sendData failed, code is ${code}, message is ${message}.`);
          }
        }).catch((err: Error) => {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error(`${TAG} connectAgentExtensionAbility failed, code is ${code}, message is ${message}.`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`${TAG} connectAgentExtensionAbility failed, code is ${code}, message is ${message}.`);
    }
  }
}
```

### authorize

authorize(handshakeData: string): void

客户端调用此接口向AgentExtensionAbility服务端发送安全认证请求。

**原子化服务API**：从 API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名         | 类型   | 必填 | 说明           |
| -------------- | ------ | ---- | ------------ |
| handshakeData | string | 是   | 待发送给AgentExtensionAbility服务端的安全认证数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                     |
| -------- | ----------------------------|
| 35600002 | Failed to send the IPC message. |

**示例：**

```ts
import { common, Want, agentManager} from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Extension] ';

@Entry
@Component
struct AgentExtensionAbility {
  comProxy: common.AgentProxy | null = null;
  dataCallBack: common.AgentExtensionConnectCallback = {
    onData: (data: string) => {
      console.info(`${TAG} dataCallBack received data: ${data}.`);
    },
    onAuth: (handshakeData: string): void => {
      console.info(`onAuth, data: ${handshakeData}.`);
    },
    onDisconnect: () => {
      console.info(`${TAG} dataCallBack onDisconnect.`);
      this.comProxy = null;
    }
  }

  build() {
    Scroll() {
      Column() {
        // 创建一个连接AgentExtension的按钮
        Button('connectAgentExtensionAbility', { type: ButtonType.Capsule, stateEffect: true })
          .margin({
            top: 5,
            left: 10,
            right: 10,
            bottom: 5
          })
          .alignRules({
            center: { anchor: '__container__', align: VerticalAlign.Center },
            middle: { anchor: '__container__', align: HorizontalAlign.Center }
          })
          .onClick(() => {
            this.myConnectAgentExtensionAbility()
          });
      }
      .width('100%')
    }
    .height('100%')
  }

  // 自定义连接AgentExtension的函数
  myConnectAgentExtensionAbility() {
    let startWant: Want = {
      deviceId: '',
      bundleName: 'com.acts.myapplication',
      abilityName: 'AgentExtensionAbility'
    };

    try {
      let agentId: string = 'test';
      // 连接AgentExtension
      agentManager.connectAgentExtensionAbility(startWant, agentId, this.dataCallBack)
        .then((proxy: common.AgentProxy) => {
          console.info(TAG + `try to connectAgentExtensionAbility ${proxy}`);
          this.comProxy = proxy;
          try {
            console.info(`${TAG} authorize.`);
            // 给AgentExtension发送认证数据
            this.comProxy.authorize('token');
          } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error(`${TAG} authorize failed, code is ${code}, message is ${message}.`);
          }
        }).catch((err: Error) => {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error(`${TAG} connectAgentExtensionAbility failed, code is ${code}, message is ${message}.`);
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`${TAG} connectAgentExtensionAbility failed, code is ${code}, message is ${message}.`);
    }
  }
}
```
