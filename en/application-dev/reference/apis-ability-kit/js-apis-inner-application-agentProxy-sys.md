# AgentProxy (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b33c416f2dabc1fc4149b71a7ef553e301b3c3cc translatedAt=2026-08-13T13:21:31.184Z pushedAt=2026-08-17T03:53:43.582Z -->

AgentProxy is used to send data or security authentication requests from the client to the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) server.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module are all system APIs.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs of this module must be used in the main thread. They cannot be used in child threads such as Worker and TaskPool.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## AgentProxy

### sendData

sendData(data: string): void

The client calls this API to send data to the AgentExtensionAbility server.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name | Type   | Mandatory | Description           |
| ------ | ------ | ---- | ------------ |
| data   | string | Yes  | Data to be sent to the AgentExtensionAbility server. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message                     |
| -------- | ----------------------------|
| 35600002 | Failed to send the IPC message. |

**Example**

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
        // Create a button for connecting to AgentExtension.
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

  // Function for custom connection to AgentExtension.
  myConnectAgentExtensionAbility() {
    let startWant: Want = {
      deviceId: '',
      bundleName: 'com.acts.myapplication',
      abilityName: 'AgentExtensionAbility'
    };

    try {
      let agentId: string = 'test';
      // Connect to AgentExtension.
      agentManager.connectAgentExtensionAbility(startWant, agentId, this.dataCallBack)
        .then((proxy: common.AgentProxy) => {
          console.info(TAG + `try to connectAgentExtensionAbility ${proxy}`);
          this.comProxy = proxy;
          try {
            console.info(`${TAG} sendData.`);
            // Send data to AgentExtension.
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

The client calls this API to send a security authentication request to the AgentExtensionAbility server.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name         | Type   | Mandatory | Description           |
| -------------- | ------ | ---- | ------------ |
| handshakeData | string | Yes  | Security authentication data to be sent to the AgentExtensionAbility server. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message                     |
| -------- | ----------------------------|
| 35600002 | Failed to send the IPC message. |

**Example**

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
        // Create a button for connecting to AgentExtension.
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

  // Custom function for connecting to AgentExtension.
  myConnectAgentExtensionAbility() {
    let startWant: Want = {
      deviceId: '',
      bundleName: 'com.acts.myapplication',
      abilityName: 'AgentExtensionAbility'
    };

    try {
      let agentId: string = 'test';
      // Connect to AgentExtension.
      agentManager.connectAgentExtensionAbility(startWant, agentId, this.dataCallBack)
        .then((proxy: common.AgentProxy) => {
          console.info(TAG + `try to connectAgentExtensionAbility ${proxy}`);
          this.comProxy = proxy;
          try {
            console.info(`${TAG} authorize.`);
            // Send authentication data to AgentExtension.
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