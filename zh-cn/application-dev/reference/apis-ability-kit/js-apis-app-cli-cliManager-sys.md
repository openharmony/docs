# @ohos.app.cli.cliManager (CLI工具管理)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

本模块提供与系统命令行工具（CLI）的交互能力，可以查询工具信息、调用并执行CLI命令，以及管理会话。

**起始版本：** 26.0.0

> **说明：**
>
> 本模块接口为系统接口。

## 导入模块

```ts
import { cliManager } from '@kit.AbilityKit';
```

## ExecOptions

执行CLI工具的可选参数。可用于指定CLI工具后台运行、前台执行时长、超时时长。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

| 名称       | 类型 | 必填 | 说明 |
| ---------- | ---- | --- | ------------------ |
| background | boolean | 否 | 表示任务是否后台执行。<br/>true：后台执行，false：前台执行。<br/>默认值：false。 |
| yieldMs    | number | 否 | 任务前台执行时长。取值范围：0 ~ 1000 * timeout。默认值：0。 |
| timeout    | number | 否 | 任务执行超时时长。取值范围：0 ~ 1800。默认值：1800。 |

## ExecResult

CLI工具执行的结果。包含CLI工具的退出码、标准输出、标准错误输出、终止信号、是否超时及执行时长。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

| 名称          | 类型     | 只读 | 必填 | 说明 |
| ------------- | ------- | ---- | ---  |----------------- |
| exitCode      | number  | 是   | 否   | 工具的退出码。默认值：undefined。 |
| outputText    | string  | 是   | 否   | 工具的标准输出（stdout）。默认值：undefined。 |
| errorText     | string  | 是   | 否   | 工具的标准错误输出（stderr）。默认值：undefined。 |
| signalNumber  | number  | 是   | 否   | 工具的终止信号。默认值：undefined。 |
| timeOut       | boolean | 是   | 是   | 工具的执行是否超时。true表示超时，false表示未超时。 |
| executionTime | number  | 是   | 是   | 工具的执行时长。 |


## SessionStatus

执行CLI工具时，系统会为调用方和CLI工具建立一个会话，此字段描述会话状态。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

| 名称      | 值   | 说明                   |
| --------- | ---- | ---------------------- |
| RUNNING   | 'running' | 会话正在进行中。    |
| COMPLETED   | 'completed' | 会话已完成。    |
| FAILED    | 'failed' | 会话发生失败。    |


## CliSessionInfo

执行CLI工具时，系统会为调用方和CLI工具建立一个会话，此字段描述会话信息的格式。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

| 名称      | 类型 | 只读 | 必填 | 说明 |
| --------- | ---- | ---- | --- | ------------------ |
| sessionId  | string | 是 | 是 | 会话id。 |
| toolName  | string | 是 | 是 | 工具名称。 |
| status  | [SessionStatus](#sessionstatus) | 是 | 是 | 会话状态。 |
| result  | [ExecResult](#execresult) | 是 | 否 | 工具执行结果。默认值：undefined。 |

## cliManager.queryToolSummaries

queryToolSummaries(): Promise\<Array\<ToolSummary>>

查询所有CLI工具的摘要信息。摘要信息仅包含名称、版本和描述字段，使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.QUERY_CLI_TOOL

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**返回值：**

| 类型                               | 说明                       |
| ---------------------------------- | -------------------------- |
| Promise\<Array\<[ToolSummary](js-apis-inner-application-ToolInfo-sys.md#toolsummary)>> | Promise对象，返回工具摘要信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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

查询所有CLI工具的详细信息，使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.QUERY_CLI_TOOL

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**返回值：**

| 类型                               | 说明                       |
| ---------------------------------- | -------------------------- |
| Promise\<Array\<[ToolInfo](js-apis-inner-application-ToolInfo-sys.md#toolinfo)>> | Promise对象，返回工具详细信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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

根据工具名称获取单个工具的详细信息，使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.QUERY_CLI_TOOL

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ------------------ |
| toolName | string | 是   | 目标工具的名称。 |

**返回值：**

| 类型                                         | 说明                               |
| -------------------------------------------- | ---------------------------------- |
| Promise\<[ToolInfo](js-apis-inner-application-ToolInfo-sys.md#toolinfo)> | Promise对象，返回工具的详细信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 35600030 | No tool with the specified name exists.                      |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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

执行CLI命令，返回会话信息。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.EXEC_CLI_TOOL

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| toolName | string | 是 | CLI工具名称。 |
| subCommand | string | 是 | CLI工具子命令名称。如果没有子命令则填空串。 |
| args | Record\<string, Object\> | 是 | 命令执行的参数。 |
| challenge | string | 是 | 使用[generateCliAuthResult](js-apis-abilityAccessCtrl-sys.md#generatecliauthresult)接口生成的授权结果。 |
| execOptions | [ExecOptions](#execoptions) | 否 | 执行命令的可选参数。默认值：详见[ExecOptions](#execoptions)的具体属性默认值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<[CliSessionInfo](#clisessioninfo)\> | Promise对象。返回会话信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 35600030 | No tool with the specified name exists. |
| 35600031 | Maximum number of processes has been reached. |
| 35600050  | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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
    permissionNames: ['ohos.permission.APPROXIMATELY_LOCATION', "ohos.permission.LOCATION"],
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

订阅指定CLI工具会话的事件。会话运行期间，CLI工具产生的标准输出、标准错误、退出或错误事件通过回调返回。

> **说明：**
>
> 会话仅限创建进程管理：只有调用`execTool`创建该会话的进程可以调用本接口。其他进程即使获取到`sessionId`，调用本接口也会抛出错误码201（Permission denied）。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.EXEC_CLI_TOOL

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名    | 类型                                      | 必填 | 说明                         |
| --------- | ----------------------------------------- | ---- | ---------------------------- |
| sessionId | string                                    | 是   | 目标CLI工具进程的会话ID。    |
| callback  | [ToolEventCallback](js-apis-inner-application-toolEventCallback-sys.md) | 是   | CLI工具会话事件的回调函数。  |

**返回值：**

| 类型           | 说明                                 |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 35600032 | The session does not exist.                                  |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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

关闭指定CLI工具会话，并强制结束对应的工具进程。

> **说明：**
>
> 会话仅限创建进程管理：只有调用`execTool`创建该会话的进程可以调用本接口。其他进程即使获取到`sessionId`，调用本接口也会抛出错误码201（Permission denied）。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.EXEC_CLI_TOOL

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                      |
| --------- | ------ | ---- | ------------------------- |
| sessionId | string | 是   | 目标CLI工具进程的会话ID。 |

**返回值：**

| 类型           | 说明                     |
| -------------- | ------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 35600032 | The session does not exist.                                  |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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

查询指定CLI工具会话的状态和执行结果。

> **说明：**
>
> 会话仅限创建进程管理：只有调用`execTool`创建该会话的进程可以调用本接口。其他进程即使获取到`sessionId`，调用本接口也会抛出错误码201（Permission denied）。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.EXEC_CLI_TOOL

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                      |
| --------- | ------ | ---- | ------------------------- |
| sessionId | string | 是   | 目标CLI工具进程的会话ID。 |

**返回值：**

| 类型                                      | 说明                               |
| ----------------------------------------- | ---------------------------------- |
| Promise\<[CliSessionInfo](#clisessioninfo)> | Promise对象，返回CLI工具会话信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 35600032 | The session does not exist.                                  |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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

执行Shell命令的可选参数。可用于指定工作目录、环境变量、后台运行、前台执行时长、超时时长、安全策略及事件回调。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

| 名称       | 类型 | 必填 | 说明 |
| ---------- | ---- | --- | ------------------ |
| workDir    | string | 否 | 命令执行的工作目录，如果不传或传空，则为根目录。 |
| env        | Record\<string, string\> | 否 | 命令执行的环境变量。 |
| background | boolean | 否 | 表示命令是否后台执行。<br/>true：后台执行，false：前台执行。<br/>默认值：false。 |
| yieldMs    | number | 否 | 命令前台执行时长，单位为毫秒。取值范围：0 ~ 1000 * timeout，默认值：0。 |
| timeout    | number | 否 | 命令执行超时时长，单位为秒。取值范围：0 ~ 1800。默认值：1800，传0表示不会超时。 |
| policy     | string | 否 | 安全策略，参数格式为JSON字符串。 |
| callback   | [ToolEventCallback](js-apis-inner-application-toolEventCallback-sys.md) | 否 | 事件回调函数，用于接收工具事件。若提供该参数，将自动订阅会话事件。 |

## cliManager.execCmd

execCmd(cmd: string, execCmdOptions?: ExecCmdOptions): Promise\<CliSessionInfo\>

执行Shell命令，返回会话信息。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.EXEC_CLI_TOOL

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| cmd | string | 是 | 要执行的Shell命令。 |
| execCmdOptions | [ExecCmdOptions](#execcmdoptions) | 否 | 执行命令的可选参数。默认值：详见[ExecCmdOptions](#execcmdoptions)的具体属性默认值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<[CliSessionInfo](#clisessioninfo)\> | Promise对象。返回会话信息。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 35600031 | Maximum number of processes has been reached. |
| 35600050  | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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

向指定CLI工具会话对应的进程发送消息。

> **说明：**
>
> 会话仅限创建进程管理：只有调用`execTool`创建该会话的进程可以调用本接口。其他进程即使获取到`sessionId`，调用本接口也会抛出错误码201（Permission denied）。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.EXEC_CLI_TOOL

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                                  |
| --------- | ------ | ---- | ------------------------------------- |
| sessionId | string | 是   | 目标CLI工具进程的会话ID。             |
| message   | string | 是   | 要发送的消息，最大长度为10240。超过最大长度时抛出错误码401。 |

**返回值：**

| 类型           | 说明                     |
| -------------- | ------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 35600032 | The session does not exist.                                  |
| 35600033 | Failed to write message to tool.                             |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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
