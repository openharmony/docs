# @ohos.app.agent.AgentExtensionAbility (智能体扩展组件)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

AgentExtensionAbility继承自[ExtensionAbility](js-apis-app-ability-extensionAbility.md)，提供智能体扩展能力。本模块提供了[LOW_CODE](js-apis-app-agent-agentConstant-sys.md#agentconstantagentcardtype)类型的Agent被调用时的回调接口，用于执行初始化操作（如从云端下载资源、加载配置等）。

**起始版本**：26.0.0

> **说明：**
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)。

## 导入模块

```ts
import { AgentExtensionAbility } from '@kit.AbilityKit';
```

## AgentExtensionAbility

### onAgentInvoked

onAgentInvoked(agentId: string): void

当[LOW_CODE](js-apis-app-agent-agentConstant-sys.md#agentconstantagentcardtype)类型的Agent被成功调用时触发，用于执行初始化操作（如从云端下载资源、加载配置等）。

**起始版本**：26.0.0

**系统接口**：此接口为系统接口。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| agentId | string | 是 | 低代码类型的Agent的ID。 |

**示例：**

```ts
import { AgentExtensionAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[AgentExtensionAbility]';

export default class AgentExt extends AgentExtensionAbility {
  onAgentInvoked(agentId: string) {
    hilog.info(0x0000, TAG, `onAgentInvoked, agentId: ${agentId}`);
  }
}
```

