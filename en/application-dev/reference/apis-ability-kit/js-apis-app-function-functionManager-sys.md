# @ohos.app.function.functionManager (Function Management) (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=f63c64a7c430538c229749177771a77e4028e6cd translatedAt=2026-08-13T13:20:26.977Z pushedAt=2026-08-17T03:13:53.839Z -->

A Function is a business logic unit defined in an app package. It can receive structured data provided by a large model to complete app-defined functions, such as querying real-time weather information and opening a specified app page.

This module provides Function management and invocation capabilities. You can query available Function information and invoke a specified Function to execute business logic.

> **NOTE**
>
> The APIs of this module are system APIs.

**Since**: 26.0.0

## Modules to Import

```ts
import { functionManager } from '@kit.AbilityKit';
```

## InvokeOptions

Optional parameters for Function invocation. Contains the app context information for Function invocation.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name | Type | Mandatory | Description |
| ---------- | ---- | --- | ------------------ |
| context | [Context](js-apis-inner-application-context.md) | No | App context information for Function invocation.<br>**Note:** Currently, only [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) is supported. |

## InvokeResult

Result of a Function call. Contains the data returned when the Function call succeeds, and the error code and error message when the call fails.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability:** SystemCapability.Ability.AgentRuntime.Core

| Name          | Type     | Read-only | Mandatory | Description |
| ------------- | ------- | ---- | ---  |----------------- |
| success      | boolean  | Yes   | Yes   | Whether the call succeeds (at the business logic level). true: Call Succeeded, and the data field contains the returned data; false: Call Failed, and the errorCode and errorMsg fields contain the error information. |
| data    | any  | Yes   | No   | Data returned when the call succeeds. The type follows the return value type defined by the Function. Has value only when success is true. Default value: undefined. |
| errorCode     | number  | Yes   | No   | Error code when the call fails. Has value only when success is false. Default value: undefined. |
| errorMsg  | string  | Yes   | No   | Error description when the call fails. Has value only when success is false. Default value: undefined. |

## functionManager.queryFunctions

queryFunctions(): Promise\<Array\<FunctionInfo>>

Queries all available Function information. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.ACCESS_FUNCTION

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Return value**

| Type                               | Description                       |
| ---------------------------------- | -------------------------- |
| Promise\<Array\<[FunctionInfo](js-apis-inner-application-FunctionInfo-sys.md#functioninfo)>> | Promise used to return the list of available Function information, including namespace, name, version, description, input/output mode, and so on. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**Example**

```ts
import { UIAbility, AbilityConstant, Want, common, functionManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  async onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      let functions:common.FunctionInfo[] = await functionManager.queryFunctions();
      hilog.info(0x0000, 'testTag', `queryFunctions success, functions: ${JSON.stringify(functions)}`);
    } catch (error) {
      hilog.error(0x0000, 'testTag', `queryFunctions failed, error: ${JSON.stringify(error)}`);
    }
  }
}
```

## functionManager.invokeFunction

invokeFunction(functionNamespace: string, functionName: string, args: Record\<string, Object\>, options?: InvokeOptions): Promise\<InvokeResult\>

Invokes the specified Function based on the Function namespace and Function name. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions:** ohos.permission.ACCESS_FUNCTION

**System capability:** SystemCapability.Ability.AgentRuntime.Core

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| functionNamespace | string | Yes | Namespace of the target Function. Together with **functionName**, it uniquely identifies a Function. |
| functionName | string | Yes | Name of the target Function. Together with **functionNamespace**, it uniquely identifies a Function. |
| args | Record\<string, Object\> | Yes | Input parameters that comply with the format defined by the Function provider. |
| options | [InvokeOptions](#invokeoptions) | No | Optional parameters for invoking the Function. Default value: For details, see the default values of the specific properties in [InvokeOptions](#invokeoptions). |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise\<[InvokeResult](#invokeresult)\> | Promise used to return the result of the Function invocation. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 35600050 | System Error. 1. Failed to connect to the system service; 2. The system service failed to communicate with the dependent module. |
| 35600060 | The function does not exist. |
| 35600061 | The function execute failed. |
| 35600062 | The function execute timeout. |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit'
import { JSON } from '@kit.ArkTS';
import { functionManager } from '@kit.AbilityKit'

const LOG_TAG = 'testTag';
const LOG_DOMAIN = 0x00;

@Entry
@Component
struct Index {
  build() {
    Column() {
      Button() {
        Text('invokeFunction test')
      }
      .fontSize(36)
      .onClick(async () => {
        try {
          let funcRet = await functionManager.invokeFunction('com.test.demo', 'functionName', {}, {
            context: this.getUIContext().getHostContext()
          });
          if (funcRet.success) {
            hilog.info(LOG_DOMAIN, LOG_TAG, 'invokeFunction success: ' + JSON.stringify(funcRet));
          } else {
            hilog.info(LOG_DOMAIN, LOG_TAG, 'invokeFunction failed: ' + JSON.stringify(funcRet));
          }
        } catch (e) {
          hilog.info(LOG_DOMAIN, LOG_TAG, 'invokeFunction error: ' + JSON.stringify(e));
        }
      })
    }
    .height('100%')
    .width('100%')
  }
}
```