# AgentHostProxy

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

AgentHostProxy用于从[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)服务端向客户端发送数据或安全认证请求。

> **说明：**
>
>  - 本模块首批接口从API version 24开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。
>  - 本模块接口需要在主线程中使用，不支持在Worker、TaskPool等子线程中使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## AgentHostProxy

### sendData

sendData(data: string): void

从[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)服务端给客户端发送数据。

**原子化服务API**：从 API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明 |
| ------ | ------ | ---- | ---- |
| data   | string | 是   | 待发送到[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)客户端的数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                     |
| -------- | ----------------------------|
| 35600002 | Failed to send the IPC message.  |

**示例：**

```ts
import { common, AgentExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[AgentExtensionAbility] ';

export default class MyAgentExtensionAbility extends AgentExtensionAbility {
  // 数据发送处理
  onData(proxy: common.AgentHostProxy, data: string) {
    console.info(TAG + `onData ${data}`);
    try {
      // 发送数据到AgentExtensionAbility的客户端
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

从[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)服务端给客户端发送安全认证请求。

**原子化服务API**：从 API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名         | 类型   | 必填 | 说明 |
| -------------- | ------ | ---- | ---- |
| handshakeData | string | 是   | 待发送到客户端的安全认证数据。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                     |
| -------- | ----------------------------|
| 35600002 | Failed to send the IPC message. |

**示例：**

```ts
import { common, AgentExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[AgentExtensionAbility] ';

export default class MyAgentExtensionAbility extends AgentExtensionAbility {
  // 安全认证处理
  onAuth(proxy: common.AgentHostProxy, handshakeData: string) {
    console.info(TAG + `onAuth ${handshakeData}`);
    try {
      // 发送认证数据到AgentExtensionAbility的客户端
      proxy.authorize('handshake_token');
    } catch (err) {
      let code = (err as BusinessError).code;
      let msg = (err as BusinessError).message;
      console.error(`${TAG} authorize failed, err code: ${code}, err msg: ${msg}.`);
    }
  }
}
```
