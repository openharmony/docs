# @ohos.app.ability.scriptManager (Script Management)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @RuiChen_01-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e1df335f2763c581aa5314209b9b06278aa8397f translatedAt=2026-08-13T13:24:37.562Z pushedAt=2026-08-14T09:25:02.709Z -->

This module provides the capability to manage and organize script information, and supports reporting the execution results of ArkTS scripts in an app.

> **NOTE**
>
> - The ArkTS script of an app must be bound to an ability. Configure the corresponding ability in the [skillProfiles](../../quick-start/module-configuration-file.md#skillprofiles) of [module.json5](../../quick-start/module-configuration-file.md).
> - The script is exported through `export default class`. The first parameter of its entry function is fixed as [ArkTSScriptInfo](#arktsscriptinfo), which is used to receive the script context information passed by the system. Developers can add custom parameters after the first parameter.

**Since**: 26.0.0

## ExecuteResult

Defines the result of ArkTS script execution.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Name | Type | Read-only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| code | number | No | No | Result code. The value is an integer, and the default value is **0**. |
| result | Record\<string, Object> | No | Yes | Result of the script execution. |
| uris | Array\<string> | No | Yes | List of URIs to be authorized to the caller. |
| flags | number | No | Yes | Read/write permission of the URI, which is the same as the **flags** field of [Want](js-apis-app-ability-want.md). The value can be any of the following:<br>- [wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION](js-apis-app-ability-wantConstant.md#flags): read permission.<br>- [wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION](js-apis-app-ability-wantConstant.md#flags): write permission.<br>- A combination of the preceding two flags: both read and write permissions. |

## ArkTSScriptInfo

The first parameter of the ArkTS script entry function of an app, used to receive the script context information passed by the system.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| requestCode | string | Yes | No | Request code used to identify the current operation. |
| context | [Context](js-apis-inner-application-context.md) | Yes | No | Bound ability context. |

## scriptManager.completeArkTSScriptInApp

completeArkTSScriptInApp(context: Context, requestCode: string, result: ExecuteResult): Promise\<void>

Completes the ArkTS script execution of an app and reports the execution result. This API uses a promise to return the result.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | Yes | Ability context, used for temporary file authorization. |
| requestCode | string | Yes | Request code used to identify the current operation. |
| result | [ExecuteResult](#executeresult) | Yes | Execution result of the ArkTS script. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| ------- | -------------------------------- |
| 16000020 | The context is not ability context. |
| 16000003 | The specified ID does not exist. |
| 16000050 | Internal error. Possible causes: 1. Connect to system service failed; 2. Send restart message to system service failed; 3. System service failed to communicate with dependency module. |

**Example**

```ts
import { scriptManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class TotalTimeSkill {
  // The first parameter of the entry function must be scriptManager.ArkTSScriptInfo, and the subsequent parameters are customized by the developer.
  public async RemoteTotalTimeModel(arkTSScriptInfo: scriptManager.ArkTSScriptInfo, ...argv: string[]): Promise<void> {
    // Parse the parameters.
    const ruleId = argv[1] ? parseInt(argv[1], 10) : null;
    const childInfoStr = argv[2] || '{}'; 
    // Implement the user function and output the result data.
    let result: scriptManager.ExecuteResult = {
      code: 0,
      result: {
        'data': 'resultData'
      } as Record<string, Object>,
    };

    scriptManager.completeArkTSScriptInApp(
      arkTSScriptInfo.context, arkTSScriptInfo.requestCode, result)
      .then(() => {
        console.info('completeArkTSScriptInApp succeeded');
      })
      .catch((err: BusinessError) => {
        console.error(`completeArkTSScriptInApp failed, code: ${err.code}, message: ${err.message}`);
      });
  }
}
```