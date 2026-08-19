# @ohos.app.cli.cliManager (CLI Tool Management)(System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=54eb89bb8213d376e2609e03be264b38457e03e3 translatedAt=2026-08-13T13:18:59.864Z pushedAt=2026-08-17T02:21:54.492Z -->

This module provides the capability to interact with system command-line tools (CLIs), including querying tool information, invoking and executing CLI commands, and managing sessions.

**Since**: 26.0.0

> **NOTE**
>
> The APIs of this module are system APIs.

## Modules to Import

```ts
import { cliManager } from '@kit.AbilityKit';
```

## ExecOptions

Optional parameters for executing a CLI tool. They can be used to specify background execution, foreground execution duration, and timeout duration of the CLI tool.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

| Name       | Type    | Mandatory | Description |
| ---------- | ------- | --------- | ------------------ |
| background | boolean | No        | Whether the task is executed in the background.<br/>true: background execution; false: foreground execution.<br/>Default value: false. |
| yieldMs    | number  | No        | Foreground execution duration of the task. Value range: 0 to 1000 * timeout. Default value: 0. |
| timeout    | number  | No        | Timeout duration of task execution. Value range: 0 to 1800. Default value: 1800. |

## ExecResult

Represents the result of CLI tool execution, including the exit code, standard output, standard error output, termination signal, timeout status, and execution duration of the CLI tool.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

| Name          | Type     | Read-Only | Mandatory | Description |
| ------------- | ------- | ---- | ---  |----------------- |
| exitCode      | number  | No   | No   | Exit code of the tool. Default value: undefined. |
| outputText    | string  | No   | No   | Standard output (stdout) of the tool. Default value: undefined. |
| errorText     | string  | No   | No   | Standard error output (stderr) of the tool. Default value: undefined. |
| signalNumber  | number  | No   | No   | Termination signal of the tool. Default value: undefined. |
| timeOut       | boolean | No   | Yes  | Whether the tool execution times out. The value true indicates a timeout, and false indicates no timeout. |
| executionTime | number  | No   | Yes  | Execution duration of the tool. |

## SessionStatus

When a CLI tool is executed, the system creates a session between the caller and the CLI tool. This field describes the session status.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

| Name      | Value   | Description                   |
| --------- | ---- | ---------------------- |
| RUNNING   | 'running' | The session is in progress.    |
| COMPLETED   | 'completed' | The session is completed.    |
| FAILED    | 'failed' | The session has failed.    |

## CliSessionInfo

When a CLI tool is executed, the system creates a session between the caller and the CLI tool. This field describes the format of the session information.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

| Name      | Type | Read-only | Mandatory | Description |
| --------- | ---- | ---- | --- | ------------------ |
| sessionId  | string | No | Yes | Session ID. |
| toolName  | string | No | Yes | Tool name. |
| status  | [SessionStatus](#sessionstatus) | No | Yes | Session status. |
| result  | [ExecResult](#execresult) | No | No | Tool execution result. Default value: undefined. |

## cliManager.queryToolSummaries

queryToolSummaries(): Promise\<Array\<ToolSummary>>

Queries the summary information of all CLI tools. The summary information contains only the name, version, and description fields. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.QUERY_CLI_TOOL

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Return value**

| Type                               | Description                       |
| ---------------------------------- | -------------------------- |
| Promise\<Array\<[ToolSummary](js-apis-inner-application-ToolInfo-sys.md#toolsummary)>> | Promise used to return the tool summary information list. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.QUERY_CLI_TOOL". |
| 202      | Not system application. Interface caller is not a system app. |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { cliManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cliManager.queryToolSummaries().then((toolSummaries) => {
    console.info('queryToolSummaries success, count: ' + toolSummaries.length);
    for (const summary of toolSummaries) {
      console.info('Tool name: ' + summary.name + ', version: ' + summary.version);
    }
  }).catch((error: BusinessError) => {
    console.error('queryToolSummaries failed, error: ' + error.message);
  });
} catch (error) {
  console.error('queryToolSummaries failed, error: ' + JSON.stringify(error));
}
```

## cliManager.queryTools

queryTools(): Promise\<Array\<ToolInfo>>

Queries the detailed information of all CLI tools. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.QUERY_CLI_TOOL

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Return value**

| Type                               | Description                       |
| ---------------------------------- | -------------------------- |
| Promise\<Array\<[ToolInfo](js-apis-inner-application-ToolInfo-sys.md#toolinfo)>> | Promise used to return the list of detailed tool information. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.QUERY_CLI_TOOL". |
| 202      | Not system application. Interface caller is not a system app. |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { cliManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  cliManager.queryTools().then((toolInfos) => {
    console.info('queryTools success, count: ' + toolInfos.length);
    for (const toolInfo of toolInfos) {
      console.info('Tool name: ' + toolInfo.name + ', version: ' + toolInfo.version);
    }
  }).catch((error: BusinessError) => {
    console.error('queryTools failed, error: ' + error.message);
  });
} catch (error) {
  console.error('queryTools failed, error: ' + JSON.stringify(error));
}
```

## cliManager.getToolInfoByName

getToolInfoByName(toolName: string): Promise\<ToolInfo>

Obtains the detailed information of a single tool by tool name. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.QUERY_CLI_TOOL

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name     | Type   | Mandatory | Description                     |
| -------- | ------ | --------- | ------------------------------- |
| toolName | string | Yes       | Name of the target tool. |

**Return value**

| Type                                                         | Description                                        |
| ------------------------------------------------------------ | -------------------------------------------------- |
| Promise\<[ToolInfo](js-apis-inner-application-ToolInfo-sys.md#toolinfo)> | Promise used to return the detailed information about the tool. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID       | Error Message                                                |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.QUERY_CLI_TOOL". |
| 202      | Not system application. Interface caller is not a system app. |
| 35600030 | No tool with the specified name exists.                      |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { cliManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let toolName = 'example_tool';
try {
  cliManager.getToolInfoByName(toolName).then((toolInfo) => {
    console.info('getToolInfoByName success, name: ' + toolInfo.name);
  }).catch((error: BusinessError) => {
    console.error('getToolInfoByName failed, error: ' + error.message);
  });
} catch (error) {
  console.error('getToolInfoByName failed, error: ' + JSON.stringify(error));
}
```

## cliManager.execTool

execTool(toolName: string, subCommand: string, args: Record\<string, Object\>, challenge: string, execOptions?: ExecOptions): Promise\<CliSessionInfo\>

Executes a CLI command and returns the session information. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.EXEC_CLI_TOOL

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| toolName | string | Yes | Name of the CLI tool. |
| subCommand | string | Yes | Name of the subcommand of the CLI tool. If there is no subcommand, pass an empty string. |
| args | Record\<string, Object\> | Yes | Parameters for command execution. |
| challenge | string | Yes | Authorization result generated by [generateCliAuthResult](js-apis-abilityAccessCtrl-sys.md). |
| execOptions | [ExecOptions](#execoptions) | No | Optional parameters for command execution. Default value: For details, see the default values of the specific properties in [ExecOptions](#execoptions). |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise\<[CliSessionInfo](#clisessioninfo)\> | Promise used to return the session information. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| ------- | -------------------------------- |
| 201 | Permission denied, interface caller does not have permission "ohos.permission.EXEC_CLI_TOOL". |
| 202 | Not system application. Interface caller is not a system app. |
| 35600030 | No tool with the specified name exists. |
| 35600031 | Maximum number of processes has been reached. |
| 35600050  | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { abilityAccessCtrl, cliManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';

try {
const atManager = abilityAccessCtrl.createAtManager();
let CLI_DEMO: abilityAccessCtrl.CliInfo = {
    cliName: 'ohos-timer',
    subCliName: '',
};
const authInfoList: Array<abilityAccessCtrl.CliAuthInfo> = [{
    cliInfo: CLI_DEMO,
    permissionNames: ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION'],
    authorizationResults: [true, true],
}];
let tokenId = rpc.IPCSkeleton.getCallingTokenId();
let agentId : string = '1001';
atManager.generateCliAuthResult(tokenId, agentId, authInfoList).then(async (result) => {
    console.info(`generateCliAuthResult result=${JSON.stringify(result)}`);

    let command: string = "ohos-timer";
    let curArgs: Record<string, Object> = {
    "duration": 10,
    }
    let subCommand: string = '';
    let challenge: string = result.authResults[0];
    let curSessionInfo: cliManager.CliSessionInfo = await cliManager.execTool(command, subCommand, curArgs, challenge);
    console.info(`execTool result=${JSON.stringify(curSessionInfo)}`);
}).catch((error: BusinessError) => {
    console.error(`execTool error, code: ${error.code}, message: ${error.message}`);
});
} catch (error) {
const err = error as BusinessError;
console.error(`execTool error, code: ${err.code}, message: ${err.message}`);
}
```

## cliManager.subscribeSession

subscribeSession(sessionId: string, callback: ToolEventCallback): Promise\<void>

Subscribes to the events of a specified CLI tool session. During the session, the standard output, standard error, exit, or error events generated by the CLI tool are returned through the callback.

> **NOTE**
>
> The session is limited to the creating process: only the process that calls `execTool` to create the session can call this API. Even if other processes obtain the `sessionId`, calling this API throws error code 201 (Permission denied).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.EXEC_CLI_TOOL

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name      | Type                                      | Mandatory | Description                         |
| --------- | ----------------------------------------- | --------- | ----------------------------------- |
| sessionId | string                                    | Yes       | Session ID of the target CLI tool process. |
| callback  | [ToolEventCallback](js-apis-inner-application-toolEventCallback-sys.md) | Yes       | Callback invoked when a CLI tool session event occurs. |

**Return value**

| Type           | Description                         |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID       | Error Message                                                |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.EXEC_CLI_TOOL". |
| 202      | Not system application. Interface caller is not a system app. |
| 35600032 | The session does not exist.                                  |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { cliManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let sessionId = 'example_session_id';
let callback: common.ToolEventCallback = {
  onEvent: (event: common.CliToolEvent) => {
    console.info('subscribeSession event type: ' + event.toolEventType + ', data: ' + event.data);
  }
};

try {
  cliManager.subscribeSession(sessionId, callback).then(() => {
    console.info('subscribeSession success.');
  }).catch((error: BusinessError) => {
    console.error('subscribeSession failed, error: ' + error.message);
  });
} catch (error) {
  console.error('subscribeSession failed, error: ' + JSON.stringify(error));
}
```

## cliManager.clearSession

clearSession(sessionId: string): Promise\<void>

Closes the specified CLI tool session and forcibly terminates the corresponding tool process.

> **NOTE**
>
> The session is limited to creating process management: only the process that created the session by calling `execTool` can call this API. If another process calls this API even after obtaining the `sessionId`, error code 201 (Permission denied) is thrown.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.EXEC_CLI_TOOL

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name      | Type   | Mandatory | Description                          |
| --------- | ------ | --------- | ------------------------------------ |
| sessionId | string | Yes       | Session ID of the target CLI tool process. |

**Return value**

| Type           | Description                     |
| -------------- | ------------------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID       | Error Message                                                |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.EXEC_CLI_TOOL". |
| 202      | Not system application. Interface caller is not a system app. |
| 35600032 | The session does not exist.                                  |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { cliManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let sessionId = 'example_session_id';
try {
  cliManager.clearSession(sessionId).then(() => {
    console.info('clearSession success.');
  }).catch((error: BusinessError) => {
    console.error('clearSession failed, error: ' + error.message);
  });
} catch (error) {
  console.error('clearSession failed, error: ' + JSON.stringify(error));
}
```

## cliManager.querySession

querySession(sessionId: string): Promise\<CliSessionInfo>

Queries the status and execution result of a specified CLI tool session.

> **NOTE**
>
> A session can be managed only by the process that created it: only the process that called `execTool` to create the session can call this API. If any other process obtains the `sessionId` and calls this API, error code 201 (Permission denied) is thrown.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.EXEC_CLI_TOOL

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name      | Type   | Mandatory | Description                              |
| --------- | ------ | --------- | ---------------------------------------- |
| sessionId | string | Yes       | Session ID of the target CLI tool process. |

**Return value**

| Type                                      | Description                              |
| ----------------------------------------- | ---------------------------------------- |
| Promise\<[CliSessionInfo](#clisessioninfo)> | Promise used to return the CLI tool session information. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID       | Error Message                                               |
| -------- | ----------------------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.EXEC_CLI_TOOL". |
| 202      | Not system application. Interface caller is not a system app. |
| 35600032 | The session does not exist.                                  |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { cliManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let sessionId = 'example_session_id';
try {
  cliManager.querySession(sessionId).then((sessionInfo) => {
    console.info('querySession success, status: ' + sessionInfo.status);
  }).catch((error: BusinessError) => {
    console.error('querySession failed, error: ' + error.message);
  });
} catch (error) {
  console.error('querySession failed, error: ' + JSON.stringify(error));
}
```

## ExecCmdOptions

Optional parameters for executing a shell command. They can be used to specify the working directory, environment variables, background execution, foreground execution duration, timeout duration, security policy, and event callback.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AgentRuntime.Core

| Name       | Type | Mandatory | Description |
| ---------- | ---- | --- | ------------------ |
| workDir    | string | No | Working directory for command execution. If this parameter is not passed or is empty, the root directory is used. |
| env        | Record\<string, string\> | No | Environment variables for command execution. |
| background | boolean | No | Whether the command is executed in the background.<br/>**true**: background execution; **false**: foreground execution.<br/>Default value: **false**. |
| yieldMs    | number | No | Foreground execution duration of the command, in milliseconds. Value range: 0 to 1000 * timeout. Default value: 0. |
| timeout    | number | No | Timeout duration for command execution, in seconds. Value range: 0 to 1800. Default value: 1800. The value 0 indicates no timeout. |
| policy     | string | No | Security policy, in JSON string format. |
| callback   | [ToolEventCallback](js-apis-inner-application-toolEventCallback-sys.md) | No | Event callback used to receive tool events. If this parameter is provided, session events are automatically subscribed to. |

## cliManager.execCmd

execCmd(cmd: string, execCmdOptions?: ExecCmdOptions): Promise\<CliSessionInfo\>

Executes a shell command and returns the session information. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.EXEC_CLI_TOOL

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| cmd | string | Yes | Shell command to execute. |
| execCmdOptions | [ExecCmdOptions](#execcmdoptions) | No | Optional parameters for command execution. Default value: For details, see the default values of the specific properties in [ExecCmdOptions](#execcmdoptions). |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise\<[CliSessionInfo](#clisessioninfo)\> | Promise used to return the session information. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 35600031 | Maximum number of processes has been reached. |
| 35600050  | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { cliManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          try {
            let cmd: string = 'ls -l';
            let options: cliManager.ExecCmdOptions = {
              background: false,
              timeout: 60,
              env: {
                "CLAW_TEST_OK": "ok",
                "CUSTOM_FLAG": "1",
                "PATH": "/data/local/tmp/claw-extra-bin",
                "BAD-KEY": "invalid-key-test"
              },
              workDir: "/system/bin",
            };
            cliManager.execCmd(cmd, options).then((sessionInfo) => {
              console.info('execCmd success, sessionId: ' + sessionInfo.sessionId +
                ', status: ' + sessionInfo.status);
            }).catch((error: BusinessError) => {
              console.error('execCmd failed, error: ' + error.message);
            });
          } catch (error) {
            console.error('execCmd failed, error: ' + JSON.stringify(error));
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## cliManager.sendMessage

sendMessage(sessionId: string, message: string): Promise\<void>

Sends a message to the process corresponding to the specified CLI tool session.

> **NOTE**
>
> The session is limited to the creating process: only the process that calls `execTool` to create the session can call this API. Even if other processes obtain the `sessionId`, calling this API throws error code 201 (Permission denied).

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.EXEC_CLI_TOOL

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name      | Type   | Mandatory | Description                                  |
| --------- | ------ | --------- | -------------------------------------------- |
| sessionId | string | Yes       | Session ID of the target CLI tool process.   |
| message   | string | Yes       | Message to send. The maximum length is 10240. Error code 401 is thrown if the maximum length is exceeded. |

**Return value**

| Type           | Description      |
| -------------- | ---------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID       | Error Message                                                |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.EXEC_CLI_TOOL". |
| 202      | Not system application. Interface caller is not a system app. |
| 35600032 | The session does not exist.                                  |
| 35600033 | Failed to write message to tool.                             |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { cliManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let sessionId = 'example_session_id';
let message = 'example message';
try {
  cliManager.sendMessage(sessionId, message).then(() => {
    console.info('sendMessage success.');
  }).catch((error: BusinessError) => {
    console.error('sendMessage failed, error: ' + error.message);
  });
} catch (error) {
  console.error('sendMessage failed, error: ' + JSON.stringify(error));
}
```