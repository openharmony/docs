# AgentHostProxy

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=b33c416f2dabc1fc4149b71a7ef553e301b3c3cc translatedAt=2026-08-13T13:21:00.266Z pushedAt=2026-08-17T03:50:12.321Z -->

AgentHostProxy is used to send data or security authentication requests from the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) server to the client.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs of this module must be used in the main thread. They are not supported in subthreads such as Worker and TaskPool.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## AgentHostProxy

### sendData

sendData(data: string): void

Sends data from the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) server to the client.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type   | Mandatory | Description |
| ------ | ------ | ---- | ---- |
| data   | string | Yes   | Data to be sent to the client of [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md). |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message                     |
| -------- | ----------------------------|
| 35600002 | Failed to send the IPC message.  |

**Example**

```ts
import { common, AgentExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[AgentExtensionAbility] ';

export default class MyAgentExtensionAbility extends AgentExtensionAbility {
  // Handle data sending.
  onData(proxy: common.AgentHostProxy, data: string) {
    console.info(TAG + `onData ${data}`);
    try {
      // Send data to the client of AgentExtensionAbility.
      proxy.sendData('Hello Client');
    } catch (err) {
      let code = (err as BusinessError).code;
      let msg = (err as BusinessError).message;
      console.error(`${TAG} sendData failed, err code: ${code}, err msg: ${msg}.`);
    }
  }
}
```

### authorize

authorize(handshakeData: string): void

Sends a security authentication request from the [AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md) server to the client.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------------- | ------ | ---- | ---- |
| handshakeData | string | Yes | Security authentication data to be sent to the client. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| -------- | ----------------------------|
| 35600002 | Failed to send the IPC message. |

**Example**

```ts
import { common, AgentExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[AgentExtensionAbility] ';

export default class MyAgentExtensionAbility extends AgentExtensionAbility {
  // Handle security authentication.
  onAuth(proxy: common.AgentHostProxy, handshakeData: string) {
    console.info(TAG + `onAuth ${handshakeData}`);
    try {
      // Send the authentication data to the client of AgentExtensionAbility.
      proxy.authorize('handshake_token');
    } catch (err) {
      let code = (err as BusinessError).code;
      let msg = (err as BusinessError).message;
      console.error(`${TAG} authorize failed, err code: ${code}, err msg: ${msg}.`);
    }
  }
}
```