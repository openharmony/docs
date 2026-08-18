# @ohos.app.agent.AgentExtensionAbility

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=249c9154cca3bfd8d247bc281ba57ee999bfbe43 translatedAt=2026-08-13T13:18:06.745Z pushedAt=2026-08-17T01:25:08.904Z -->

AgentExtensionAbility inherits from [ExtensionAbility](js-apis-app-ability-extensionAbility.md) and provides agent extension capabilities, including lifecycle callback APIs for creating, destroying, connecting, and disconnecting an agent service, as well as callback APIs for receiving data sent by the client and for security authentication.

In this document, the provider of the AgentExtensionAbility component is referred to as the server, and the user of the AgentExtensionAbility component is referred to as the client.

> **NOTE**
>
> The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module are not supported in [har](../../quick-start/har-package.md) packages.

## Modules to Import

```ts
import { AgentExtensionAbility } from '@kit.AbilityKit';
```

## Lifecycle

**Figure 1** AgentExtensionAbility lifecycle


- **onCreate**

  When an AgentExtensionAbility instance is created, the system invokes this callback. You can perform initialization logic in this callback, such as defining variables and loading resources.

- **onConnect**

  Called when the client is successfully connected to the AgentExtensionAbility.

- **onDisconnect**

  Called when the client is disconnected from the AgentExtensionAbility.

- **onDestroy**

Called when the AgentExtensionAbility is destroyed.

## AgentExtensionAbility

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| context | [AgentExtensionContext](js-apis-inner-application-agentExtensionContext.md) | No | No | Context of AgentExtensionAbility, inherited from [ExtensionContext](js-apis-inner-application-extensionContext.md). |

### onCreate

onCreate(want: Want): void

Called when the AgentExtensionAbility instance is created. Developers can perform initialization logic (such as defining variables and loading resources) in this callback.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes | [Want](js-apis-app-ability-want.md) type information related to the current AgentExtensionAbility, including the ability name, bundle name, and so on. |

**Example**

```ts
import { AgentExtensionAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[AppServiceExtAbility]';

export default class AgentExt extends AgentExtensionAbility {
  // Create the AgentExtensionAbility.
  onCreate(want: Want) {
    hilog.info(0x0000, TAG, `onCreate, want: ${want.abilityName}, bundlename: ${want.bundleName}`);
  }
}
```

### onConnect

onConnect(want: Want, proxy: AgentHostProxy): void

Called when a client is successfully connected to the AgentExtensionAbility.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes | [Want](js-apis-app-ability-want.md) type information related to the current AgentExtensionAbility, including the ability name, bundle name, and so on. |
| proxy | [AgentHostProxy](js-apis-inner-application-agentHostProxy.md) | Yes | [AgentHostProxy](js-apis-inner-application-agentHostProxy.md) object used to communicate with the client. |

**Example**

```ts
import { AgentExtensionAbility, Want, common} from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[AgentExtensionAbility]';

export default class AgentExt extends AgentExtensionAbility {
  onConnect(want: Want, proxy: common.AgentHostProxy){
    hilog.info(0x0000, TAG, `onConnect, want: ${want.abilityName}, bundlename: ${want.bundleName}`);
  }
}
```

### onDisconnect

onDisconnect(want: Want, proxy: AgentHostProxy): void

Called when the client is disconnected from the AgentExtensionAbility.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| Yes | [Want](js-apis-app-ability-want.md) type information related to the current AgentExtensionAbility, including the ability name, bundle name, and so on. |
| proxy |[AgentHostProxy](js-apis-inner-application-agentHostProxy.md)| Yes | [AgentHostProxy](js-apis-inner-application-agentHostProxy.md) object used to communicate with the client. |

**Example**

```ts
import { AgentExtensionAbility, Want, common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[AgentExtensionAbility]';

export default class AgentExt extends AgentExtensionAbility {
  onDisconnect(want: Want, proxy: common.AgentHostProxy) {
    hilog.info(0x0000, TAG, `onDisconnect, want: ${want.abilityName}, bundlename: ${want.bundleName}`);
  }
}
```

### onData

onData(proxy: AgentHostProxy, data: string): void

Called when the AgentExtensionAbility receives data sent by the client. The server can send data to the client through [AgentHostProxy.sendData](js-apis-inner-application-agentHostProxy.md#senddata) in this callback.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| proxy | [AgentHostProxy](js-apis-inner-application-agentHostProxy.md) | Yes | [AgentHostProxy](js-apis-inner-application-agentHostProxy.md) object used to communicate with the client. |
| data | string | Yes | Data received. |

**Example**

```ts
import { AgentExtensionAbility, common} from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[AgentExtensionAbility]';

export default class AgentExt extends AgentExtensionAbility {
  onData(proxy : common.AgentHostProxy, data : string ){
    hilog.info(0x0000, TAG, `onData, data: ${data}`);
  }
}
```

### onAuth

onAuth(proxy: AgentHostProxy, handshakeData: string): void

Called when the AgentExtensionAbility receives a security authentication request from the client. The server can process the received security authentication request in this callback and send a security authentication request to the client through [AgentHostProxy.authorize](js-apis-inner-application-agentHostProxy.md#authorize).

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| proxy | [AgentHostProxy](js-apis-inner-application-agentHostProxy.md) | Yes | [AgentHostProxy](js-apis-inner-application-agentHostProxy.md) object, used to send security authentication requests to the client. |
| handshakeData | string | Yes | Security authentication data received. |

**Example**

```ts
import { AgentExtensionAbility, common} from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[AgentExtensionAbility]';

export default class AgentExt extends AgentExtensionAbility {
  onAuth(proxy : common.AgentHostProxy, handshakeData : string ){
    hilog.info(0x0000, TAG, `onAuth, handshakeData: ${handshakeData}`);
  }
}
```

### onDestroy

onDestroy(): void

Called when the AgentExtensionAbility is destroyed.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Example**

```ts
import { AgentExtensionAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[AgentExtensionAbility]';

export default class AgentExt extends AgentExtensionAbility {
  onDestroy() {
    hilog.info(0x0000, TAG, `onDestroy`);
  }
}
```