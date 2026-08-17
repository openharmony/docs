# AgentCard

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=a9f9e0ba083e43e37b2825c7014b0a23a5613998 translatedAt=2026-08-13T13:21:00.367Z pushedAt=2026-08-17T03:42:28.505Z -->

AgentCard is the "business card" of an Agent, used to describe the capabilities and skills of the Agent. It is configured by the developer in the Agent configuration file agent_config.json.

An Agent is an AgentExtensionAbility instance. The developer can obtain the AgentCard of the current AgentExtensionAbility through the agentCard property in AgentExtensionContext.

> **NOTE**
>
> The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## AgentCard

Describes the basic information and capabilities of an agent.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name                  | Type                                                     | Read-Only | Optional | Description                                      |
| --------------------- | -------------------------------------------------------- | ---- | ---- | ------------------------------------------ |
| agentId | string | No | No | Unique identifier of the agent. Within the same app, agentId cannot be duplicated. |
| name                  | string                                                   | No   | No   | Name of the agent. It is generally used by the consumer to display the agent in the UI, for example, "Recipe Assistant" (recipe assistant). |
| description           | string                                                   | No   | No   | Description of the agent's functions. This description should clearly explain the core functions and purpose of the agent, helping users understand what the agent can do, for example, "helps users search for recipes, plan menus, and provide cooking suggestions". |
| type  | [agentConstant.AgentCardType](js-apis-app-agent-agentConstant.md#agentconstantagentcardtype) | No | Yes | Type of the AgentCard. <!--Del-->When the enum value of [agentConstant.AgentCardType](js-apis-app-agent-agentConstant-sys.md#agentconstantagentcardtype) is LOW_CODE, the corresponding app must be a system app; otherwise, the agent card cannot be registered, installed, or updated. <!--DelEnd-->If not specified, the default type is APP. <br>**Since:** 26.0.0 <br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0. |
| provider | [AgentProvider](#agentprovider) | No | Yes | Service provider information of the agent, including the provider's organization name and official website URL, used to identify the source and copyright information of the agent. |
| version | string | No | No | Version number of the agent. It follows the semantic versioning specification (for example, "1.0.0"), and the format is defined by the provider. The version number is used to identify the functional iteration and compatibility changes of the agent. |
| documentationUrl           | string                                                   | No   | Yes   | URL of the agent documentation. It provides detailed usage documentation, API descriptions, examples, and best practice guides for the agent, helping developers better integrate and use the agent. |
| capabilities             | [AgentCapabilities](#agentcapabilities)                                          | No   | Yes   | Set of optional capabilities supported by the agent. It defines other optional capabilities supported by the agent, such as streaming responses, push notifications, and status history queries. |
| defaultInputModes | Array\<string> | No | No | Set of input modes supported by the agent across all [AgentSkill](#agentskill) instances. It uses the MIME type format to define the supported input media types, for example, ["text/plain"] indicates plain text input, ["application/json"] indicates JSON structured data input, and ["image/png"] indicates image input. The inputModes at the [AgentSkill](#agentskill) level override this default setting. |
| defaultOutputModes           | Array\<string>                                                   | No   | No   | Set of output modes supported by the agent across all [AgentSkill](#agentskill) instances. It uses the MIME type format to define the supported output media types, for example, ["text/plain"] indicates plain text output, ["application/html"] indicates HTML format output, and ["application/json"] indicates JSON data output. The outputModes at the [AgentSkill](#agentskill) level override this default setting. |
| skills               | Array\<[AgentSkill](#agentskill)>                                           | No   | No   | Set of functions provided by the agent. It describes the specific functions or skills that the agent can perform, and each skill defines its specific purpose, tags, and usage examples. The agent must contain at least one skill. |
| iconUrl       | string                                                   | No   | No   | URL of the agent icon. It provides a visual identifier icon for the agent, used to display the agent in the UI and enhance its recognizability and user experience.<br>**Note:** The system does not verify the content of this field. The consumer must verify the validity and security of iconUrl. |
| category       | string                                                   | No   | No   | Category of the agent. It is used to classify and manage agents. Common categories include: "productivity", "entertainment", "education", "finance", and "health". |
| extension       | string                                                   | No   | Yes   | Extension configuration item of the agent. It is used to store custom extension configuration information, such as the agent's opening remarks and version protocol number, in JSON string format. |
| appInfo       | [AgentAppInfo](#agentappinfo)                                                   | No   | No   | Information about the app to which the agent belongs. It contains identifier information such as the bundle name, module name, and ability name of the app to which the agent belongs, used to locate and manage the AgentExtensionAbility instance. |

## AgentProvider

Represents the service provider of an Agent.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name               | Type    | Read-Only | Optional | Description                               |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| organization     | string  | No   | No   | Organization name of the Agent provider. Identifies the company, organization, or individual that develops or provides the Agent. |
| url     | string  | No   | No   | URL of the Agent provider's website or related documentation. Provides an HTTPS link to the provider's official website, product page, or related documentation for users to learn more or obtain support. |

## AgentCapabilities

Defines the optional capabilities supported by an agent.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name               | Type    | Read-only | Optional | Description                               |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| streaming     | boolean  | No   | Yes   | Whether the agent supports streaming responses.<br>true: supports SSE (Server-Sent Events) streaming responses, which can return partial results in real time.<br>false: does not support streaming and returns the complete result only once. After streaming responses are enabled, the client can use the stream method to obtain the real-time data stream. |
| pushNotifications     | boolean  | No   | Yes   | Whether the agent supports sending push notifications for asynchronous task updates.<br>true: supported. When the status of a long-running task changes (for example, task completion, failure, or progress update), the agent can proactively push notifications to the client.<br>false: not supported. The client needs to poll to query the task status. |
| stateTransitionHistory | boolean | No | Yes | Whether the agent supports viewing the task status change history.<br>true: supported. The client can query the complete status transition records of a task from creation to completion (for example, pending->running->completed).<br>false: status history query is not supported. |
| extendedAgentCard     | boolean  | No   | Yes   | Whether the agent supports providing an extended AgentCard during authentication.<br>true: supported. After authentication, the client can obtain an extended AgentCard that contains additional information (such as private configurations and advanced capabilities).<br>false: only the basic AgentCard is provided. |
| extension     | string  | No   | Yes   | Protocol extension supported by the agent. Used to store custom extension capability configurations in JSON string format. It can contain protocol-level extension parameters and custom fields, as agreed between the developer and the agent consumer. |

## AgentSkill

Represents the different capabilities or functions that an agent can perform.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name               | Type    | Read-Only | Optional | Description                               |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| id     | string  | No   | No   | Unique identifier of the AgentSkill, which must be unique within an AgentCard. A semantic naming format (such as "route-planner" or "recipe-search") is recommended for precisely specifying the skill to use in API calls. |
| name     | string  | No   | No   | Name of the AgentSkill. It is displayed in the UI, for example, "Route Planning" or "Recipe Search". |
| description     | string  | No   | No   | Detailed description of the AgentSkill. It should clearly explain the specific functions, applicable scenarios, and problems that the skill can solve, for example, "Help users plan travel routes between two points, providing multiple transportation options and real-time traffic information". |
| tags     | Array\<string>  | No   | No   | Keyword tags that describe the capabilities of the AgentSkill. They are used for skill classification, retrieval, and recommendation, for example, ["maps", "routing", "navigation"] or ["cooking", "recipe", "food"]. Tags should be concise and easy for users to understand and search. |
| examples     | Array\<string>  | No   | Yes   | Example prompts or usage scenarios that the AgentSkill can handle. Providing specific examples helps users understand how to use the skill, for example, ["Plan a route from Shanghai to Beijing"]. |
| inputModes     | Array\<string>  | No   | Yes   | Input modes supported by the AgentSkill. They are defined in MIME type format, for example, ["text/plain"]. If not set, the defaultInputModes at the AgentCard level are used. This field allows customizing input types for a specific skill, overriding the default settings. |
| outputModes     | Array\<string>  | No   | Yes   | Output modes supported by the AgentSkill. They are defined in MIME type format, for example, ["text/plain", "application/html", "video/mp4"]. If not set, the defaultOutputModes at the AgentCard level are used. This field allows customizing output types for a specific skill, overriding the default settings. |
| extension     | string  | No   | Yes   | Extension configuration item of the AgentSkill. It is used to store skill-level custom extension configurations in JSON string format, and can contain skill-specific parameters and configuration information. |

## AgentAppInfo

App information of the Agent.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 24.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name               | Type    | Read-only | Optional | Description                               |
| -------------------| ------- | ---- | ---- | ---------------------------------- |
| bundleName     | string  | No   | No   | Bundle name of the AgentExtensionAbility to which the Agent belongs. |
| moduleName     | string  | No   | No   | Module name of the AgentExtensionAbility to which the Agent belongs. |
| abilityName     | string  | No   | No   | Ability name of the AgentExtensionAbility to which the Agent belongs. |
| deviceTypes     | Array\<string>  | No   | Yes   | List of device types supported by the Agent. For the value range, see [deviceTypes](../../quick-start/module-configuration-file.md#devicetypes-tag). |
| minAppVersion     | string  | No   | Yes   | Minimum app version required for the Agent to run. Uses the semantic versioning format (for example, "1.0.0") to specify the minimum app version required to run the Agent. Apps with a version lower than this value cannot load and run the Agent correctly. |