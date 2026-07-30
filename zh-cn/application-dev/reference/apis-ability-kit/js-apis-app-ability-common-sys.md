# @ohos.app.ability.common (Ability公共模块)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

开发者可以通过该模块引用Ability公共模块类。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.app.ability.common (Ability公共模块)](js-apis-app-ability-common.md)。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## ServiceExtensionContext

type ServiceExtensionContext = _ServiceExtensionContext.default

ServiceExtensionContext二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext-sys.md) | ServiceExtensionContext二级模块。 |

## AutoFillExtensionContext<sup>11+</sup>

type AutoFillExtensionContext = _AutoFillExtensionContext.default

AutoFillExtensionContext二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [AutoFillExtensionContext](js-apis-inner-application-autoFillExtensionContext-sys.md) | AutoFillExtensionContext二级模块。 |

## AutoStartupInfo<sup>11+</sup>

type AutoStartupInfo = _AutoStartupInfo

AutoStartupInfo二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | AutoStartupInfo二级模块。 |

## AutoStartupCallback<sup>11+</sup>

type AutoStartupCallback = _AutoStartupCallback

AutoStartupCallback二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md) | AutoStartupCallback二级模块。 |

## UIServiceExtensionContext<sup>14+</sup>

type UIServiceExtensionContext = _UIServiceExtensionContext.default

UIServiceExtensionContext二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [UIServiceExtensionContext](js-apis-inner-application-uiserviceExtensionContext-sys.md) | UIServiceExtensionContext二级模块。 |

## UIServiceHostProxy<sup>14+</sup>

type UIServiceHostProxy = _UIServiceHostProxy.default

UIServiceHostProxy二级模块。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md) | UIServiceHostProxy二级模块。 |

## AgentProxy<sup>24+</sup>

type AgentProxy = _AgentProxy

AgentProxy二级模块。

[AgentProxy](../apis-ability-kit/js-apis-inner-application-agentProxy-sys.md)用于从客户端向[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)服务端发送数据或安全认证请求。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AgentProxy](../apis-ability-kit/js-apis-inner-application-agentProxy-sys.md) | 用于从客户端向[AgentExtensionAbility](js-apis-app-agent-agentExtensionAbility.md)服务端发送数据或安全认证请求。 |

## AgentExtensionConnectCallback<sup>24+</sup>

type AgentExtensionConnectCallback = _AgentExtensionConnectCallback

AgentExtensionConnectCallback二级模块。

[AgentExtensionConnectCallback](../apis-ability-kit/js-apis-inner-application-agentExtensionConnectCallback-sys.md)中提供了回调接口给开发者来接收服务端发送的数据和安全认证请求，以及感知AgentExtensionAbility服务端的断开连接操作。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_AgentExtensionConnectCallback](../apis-ability-kit/js-apis-inner-application-agentExtensionConnectCallback-sys.md) | 提供回调接口给开发者来接收服务端发送的数据和安全认证请求，以及感知AgentExtensionAbility服务端的断开连接操作。 |

## ToolInfo

type ToolInfo = _ToolInfo

[ToolInfo](../apis-ability-kit/js-apis-inner-application-ToolInfo-sys.md#toolinfo)用于描述系统命令行工具（CLI）的基本信息。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_ToolInfo](../apis-ability-kit/js-apis-inner-application-ToolInfo-sys.md#toolinfo) | 用于描述系统命令行工具（CLI）的基本信息。 |

## ToolSummary

type ToolSummary = _ToolSummary

[ToolSummary](../apis-ability-kit/js-apis-inner-application-ToolInfo-sys.md#toolsummary)用于描述系统命令行工具（CLI）的摘要信息。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_ToolSummary](../apis-ability-kit/js-apis-inner-application-ToolInfo-sys.md#toolsummary) | 用于描述系统命令行工具（CLI）的摘要信息。 |

## CliToolEvent

type CliToolEvent = _CliToolEvent

[CliToolEvent](../apis-ability-kit/js-apis-inner-application-cliToolEvent-sys.md)用于描述CLI工具进程运行期间产生的会话事件信息。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_CliToolEvent](../apis-ability-kit/js-apis-inner-application-cliToolEvent-sys.md) | 用于描述CLI工具进程运行期间产生的会话事件信息。 |

## ToolEventCallback

type ToolEventCallback = _ToolEventCallback

[ToolEventCallback](../apis-ability-kit/js-apis-inner-application-toolEventCallback-sys.md)用于接收CLI工具进程运行期间产生的会话事件。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_ToolEventCallback](../apis-ability-kit/js-apis-inner-application-toolEventCallback-sys.md) | 用于接收CLI工具进程运行期间产生的会话事件。 |

## FunctionInfo

type FunctionInfo = _FunctionInfo

[FunctionInfo](../apis-ability-kit/js-apis-inner-application-FunctionInfo-sys.md#functioninfo)用于描述[Function](./js-apis-app-function-functionManager-sys.md)的基本信息。

**起始版本：** 26.0.0

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 类型 | 说明 |
| --- | --- |
| [_FunctionInfo](../apis-ability-kit/js-apis-inner-application-FunctionInfo-sys.md#functioninfo) | 用于描述Function的基本信息，包括Function命名空间、名称、版本、描述、输入输出模式等。 |

**示例：**

```ts
import { common } from '@kit.AbilityKit';

let uiAbilityContext: common.UIAbilityContext;
let abilityStageContext: common.AbilityStageContext;
let applicationContext: common.ApplicationContext;
let baseContext: common.BaseContext;
let context: common.Context;
let extensionContext: common.ExtensionContext;
let formExtensionContext: common.FormExtensionContext;
let vpnExtensionContext: common.VpnExtensionContext;
let eventHub: common.EventHub;
let pacMap: common.PacMap;
let abilityResult: common.AbilityResult;
let abilityStartCallback: common.AbilityStartCallback;
let connectOptions: common.ConnectOptions;
let autoFillExtensionContext: common.AutoFillExtensionContext;
let uiServiceExtensionContext: common.UIServiceExtensionContext;
let uiServiceHostProxy: common.UIServiceHostProxy;
let agentProxy: common.AgentProxy;
let agentExtensionConnectCallback: common.AgentExtensionConnectCallback;
let toolInfo: common.ToolInfo;
let toolSummary: common.ToolSummary;
let cliToolEvent: common.CliToolEvent;
let toolEventCallback: common.ToolEventCallback;
let functionInfo: common.FunctionInfo;
```
