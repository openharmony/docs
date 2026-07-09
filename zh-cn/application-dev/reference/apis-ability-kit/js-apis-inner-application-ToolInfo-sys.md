# ToolInfo (系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @dsz2025-->
<!--Adviser: @HelloCrease-->

ToolInfo用于描述系统命令行工具（CLI）的基本信息，包括工具名称、版本、描述、可执行路径、输入输出模式等。

**起始版本：** 26.0.0

> **说明：**
>
> 本模块接口为系统接口。

## 导入模块

```ts
import { ToolInfo, ToolSummary, SubCommandInfo } from '@kit.AbilityKit';
```

## ToolInfo

描述CLI工具的基本信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

| 名称               | 类型                                                   | 只读 | 可选 | 说明                                                         |
| ------------------ | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name               | string                                                 | 是   | 否   | CLI工具的名称，用于在系统中唯一标识一个CLI工具。        |
| version            | string                                                 | 是   | 否   | CLI工具的版本号。遵循语义化版本规范（如"1.0.0"），格式由提供商定义。版本号用于标识工具的功能迭代和兼容性变化。 |
| description        | string                                                 | 是   | 否   | CLI工具的功能描述。该描述应清晰说明工具的核心功能和用途，帮助用户理解工具能做什么。 |
| executablePath     | string                                                 | 是   | 否   | CLI工具的可执行文件路径。必须是绝对路径。                    |
| requirePermissions | Array\<string>                                         | 是   | 是   | CLI工具所需的权限列表。所有权限项必须为唯一的字符串。        |
| inputSchema        | Record<string, Object>     | 是   | 否   | CLI工具的输入模式定义。使用JSON Schema格式定义输入参数的结构和类型，用于描述工具接受的输入数据格式。 |
| outputSchema       | Record<string, Object>     | 是   | 否   | CLI工具的输出模式定义。使用JSON Schema格式定义输出数据的结构和类型，用于描述工具返回的输出数据格式。 |
| eventTypes         | Array\<string>                                         | 是   | 是   | CLI工具支持的自定义事件类型列表。所有事件类型必须为唯一的字符串。 |
| eventSchemas       | Record<string, Record<string, Object>> | 是   | 是   | 自定义事件的模式定义。以键值对形式存储，键为事件类型，值为该事件的JSON Schema定义。 |
| hasSubCommand      | boolean                                                | 是   | 是   | 指示该工具是否支持子命令。true表示工具支持子命令，false表示不支持子命令。 |
| subcommands        | Record<string, [SubCommandInfo](#subcommandinfo)>       | 是   | 是   | 子命令信息列表。以键值对形式存储，键为子命令名称，值为子命令的详细信息。 |
| isLockScreenExecutionAllowed        | boolean       | 是   | 是   | 指示该工具是否支持在锁屏状态下执行。true表示工具支持在锁屏状态下执行，false表示工具不支持在锁屏状态下执行。 |

## ToolSummary

描述CLI工具的摘要信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

| 名称        | 类型   | 只读 | 可选 | 说明                                                         |
| ----------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| name        | string | 是   | 否   | CLI工具的名称。                                              |
| version     | string | 是   | 否   | CLI工具的版本号。遵循语义化版本规范（如"1.0.0"），格式由提供商定义。 |
| description | string | 是   | 否   | CLI工具的功能描述。                                          |

## SubCommandInfo

描述CLI工具子命令的信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

| 名称               | 类型                                                   | 只读 | 可选 | 说明                                                         |
| ------------------ | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| description        | string                                                 | 是   | 否   | 子命令的描述。应清晰说明该子命令的具体功能和使用场景。       |
| requirePermissions | Array\<string>                                         | 是   | 是   | 子命令所需的权限列表。所有权限项必须为唯一的字符串。         |
| inputSchema        | Record<string, Object>  | 是   | 否   | 子命令的输入模式定义。使用JSON Schema格式定义输入参数的结构和类型。 |
| outputSchema       | Record<string, Object>  | 是   | 否   | 子命令的输出模式定义。使用JSON Schema格式定义输出数据的结构和类型。 |
| eventTypes         | Array\<string>                                         | 是   | 是   | 子命令支持的自定义事件类型列表。所有事件类型必须为唯一的字符串。 |
| eventSchemas       | Record<string, Record<string, Object>> | 是   | 是   | 子命令自定义事件的模式定义。以键值对形式存储，键为事件类型，值为该事件的JSON Schema定义。 |
