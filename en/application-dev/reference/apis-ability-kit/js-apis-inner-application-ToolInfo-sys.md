# ToolInfo (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @dsz2025-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=cd0e4aa0316245772a6f67d8089a8d0793a146b7 translatedAt=2026-08-13T13:22:33.380Z pushedAt=2026-08-17T07:21:56.446Z -->

ToolInfo describes the basic information about a system command-line tool (CLI), including the tool name, version, description, executable path, input/output mode, and so on.

**Since**: 26.0.0

> **NOTE**
>
> The APIs of this module are system APIs.

## Modules to Import

```ts
import { ToolInfo, ToolSummary, SubCommandInfo } from '@kit.AbilityKit';
```

## ToolInfo

Describes the basic information about a CLI tool.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name               | Type                                                   | Read-Only | Optional | Description                                                         |
| ------------------ | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name               | string                                                 | Yes   | No   | Name of the CLI tool, used to uniquely identify a CLI tool in the system.        |
| version            | string                                                 | Yes   | No   | Version number of the CLI tool. It follows the Semantic Versioning specification (for example, "1.0.0"), and the format is defined by the provider. The version number is used to identify the feature iterations and compatibility changes of the tool. |
| description        | string                                                 | Yes   | No   | Functional description of the CLI tool. The description should clearly explain the core functions and purposes of the tool, helping users understand what the tool can do. |
| executablePath     | string                                                 | Yes   | No   | Executable file path of the CLI tool. It must be an absolute path.                    |
| requirePermissions | Array\<string>                                         | Yes   | Yes  | List of permissions required by the CLI tool. All permission items must be unique strings.        |
| inputSchema        | Record<string, Object>     | Yes   | No   | Input schema definition of the CLI tool. It uses the JSON Schema format to define the structure and types of input parameters, describing the input data format accepted by the tool. |
| outputSchema       | Record<string, Object>     | Yes   | No   | Output schema definition of the CLI tool. It uses the JSON Schema format to define the structure and types of output data, describing the output data format returned by the tool. |
| eventTypes         | Array\<string>                                         | Yes   | Yes  | List of custom event types supported by the CLI tool. All event types must be unique strings. |
| eventSchemas       | Record<string, Record<string, Object>> | Yes   | Yes  | Schema definitions of custom events. They are stored as key-value pairs, where the key is the event type and the value is the JSON Schema definition of the event. |
| hasSubCommand      | boolean                                                | Yes   | Yes  | Whether the tool supports subcommands. The value true indicates that the tool supports subcommands, and false indicates that it does not. |
| subcommands        | Record<string, [SubCommandInfo](#subcommandinfo)>       | Yes   | Yes  | List of subcommand information. It is stored as key-value pairs, where the key is the subcommand name and the value is the detailed information about the subcommand. |
| isLockScreenExecutionAllowed        | boolean       | Yes   | Yes  | Whether the tool supports execution in the lock screen state. The value true indicates that the tool supports execution in the lock screen state, and false indicates that it does not. |

## ToolSummary

Describes the summary information of a CLI tool.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name        | Type   | Read-Only | Optional | Description                                                         |
| ----------- | ------ | --------- | -------- | ------------------------------------------------------------ |
| name        | string | Yes       | No       | Name of the CLI tool.                                              |
| version     | string | Yes       | No       | Version number of the CLI tool. It follows the Semantic Versioning specification (for example, "1.0.0"), and the format is defined by the provider. |
| description | string | Yes       | No       | Description of the CLI tool.                                          |

## SubCommandInfo

Describes the information about a CLI tool subcommand.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name               | Type                                                   | Read-Only | Optional | Description                                                  |
| ------------------ | ------------------------------------------------------ | --------- | -------- | ------------------------------------------------------------ |
| description        | string                                                 | Yes       | No       | Description of the subcommand. It should clearly state the specific function and usage scenario of the subcommand. |
| requirePermissions | Array\<string>                                         | Yes       | Yes      | List of permissions required by the subcommand. All permission items must be unique strings. |
| inputSchema        | Record<string, Object>  | Yes       | No       | Input schema definition of the subcommand. Defines the structure and type of the input parameters in JSON Schema format. |
| outputSchema       | Record<string, Object>  | Yes       | No       | Output schema definition of the subcommand. Defines the structure and type of the output data in JSON Schema format. |
| eventTypes         | Array\<string>                                         | Yes       | Yes      | List of custom event types supported by the subcommand. All event types must be unique strings. |
| eventSchemas       | Record<string, Record<string, Object>> | Yes       | Yes      | Schema definition of the custom events of the subcommand. Stored as key-value pairs, where the key is the event type and the value is the JSON Schema definition of the event. |