# AgentExtensionConnectCallback (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

开发者可以通过AgentExtensionConnectCallback中提供的回调接口来接收服务端发送的数据和安全认证请求，以及感知AgentExtensionAbility服务端的断开连接操作。

> **说明：**
>
>  - 本模块首批接口从API version 24开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口均为系统接口。
>  - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## AgentExtensionConnectCallback

### onData

onData(data: string): void

接收来自AgentExtensionAbility服务端的数据的回调接口。

**原子化服务API**：从 API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | ------------ |
| data   | string | 是   | 接收到的来自AgentExtensionAbility服务端的数据。 |

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
      console.info(`onAuth, handshakeData: ${handshakeData}.`);
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

### onAuth

onAuth(handshakeData: string): void

接收来自AgentExtensionAbility服务端的安全认证的回调接口。

**原子化服务API**：从 API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名         | 类型   | 必填 | 说明           |
| -------------- | ------ | ---- | ------------ |
| handshakeData | string | 是   | 接收到的来自AgentExtensionAbility服务端的安全认证数据。 |

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
      console.info(`onAuth, handshakeData: ${handshakeData}.`);
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

### onDisconnect

onDisconnect(): void

与AgentExtensionAbility服务端断开连接时触发的回调接口。

**原子化服务API**：从 API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**系统接口**：此接口为系统接口。

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
      console.info(`onAuth, handshakeData: ${handshakeData}.`);
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
