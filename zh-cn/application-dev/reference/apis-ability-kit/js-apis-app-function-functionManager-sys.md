# @ohos.app.function.functionManager (Function管理)(系统接口)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

Function是定义在应用包中的一个业务逻辑单元，可以接收大模型提供的结构化数据来完成应用定义的功能，例如查询实时天气信息、打开指定应用页面等。

本模块提供Function的管理和调用能力，可以查询可用的Function信息、调用指定的Function执行业务逻辑。

> **说明：**
>
> 本模块接口为系统接口。

**起始版本：** 26.0.0

## 导入模块

```ts
import { functionManager } from '@kit.AbilityKit';
```

## InvokeOptions

Function调用的可选参数。包含Function调用时的应用上下文信息。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

| 名称       | 类型 | 必填 | 说明 |
| ---------- | ---- | --- | ------------------ |
| context | [Context](js-apis-inner-application-context.md) | 否 | 执行Function调用时的应用上下文信息。<br>**说明**：目前仅支持[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) |

## InvokeResult

Function调用的结果。包含Function调用成功时返回的数据，调用失败时的错误码和错误信息。

**起始版本：** 26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

| 名称          | 类型     | 只读 | 必填 | 说明 |
| ------------- | ------- | ---- | ---  |----------------- |
| success      | boolean  | 是   | 是   | 调用是否成功（业务逻辑层面）。true：调用成功，data字段包含返回数据；false：调用失败，errorCode和errorMsg字段包含错误信息。 |
| data    | any  | 是   | 否   | 调用成功时返回的数据，类型遵循Function定义的返回值类型。仅在success为true时有值。默认值：undefined。 |
| errorCode     | number  | 是   | 否   | 调用失败时的错误码。仅在success为false时有值。默认值：undefined。 |
| errorMsg  | string  | 是   | 否   | 调用失败时的错误描述。仅在success为false时有值。默认值：undefined。 |


## functionManager.queryFunctions

queryFunctions(): Promise\<Array\<FunctionInfo>>

查询所有可用的Function信息，使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_FUNCTION

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**返回值：**

| 类型                               | 说明                       |
| ---------------------------------- | -------------------------- |
| Promise\<Array\<[FunctionInfo](js-apis-inner-application-FunctionInfo-sys.md#functioninfo)>> | Promise对象，返回可用Function的信息列表，包含命名空间、名称、版本、描述、输入输出模式等。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 35600050 | System Error. 1. Connect to system service failed; 2. System service failed to communicate with dependency module. |

**示例：**

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

根据Function命名空间和Function名称调用指定的Function，使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.ACCESS_FUNCTION

**系统能力：** SystemCapability.Ability.AgentRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| functionNamespace | string | 是 | 目标Function的命名空间，与functionName共同确定唯一的Function。 |
| functionName | string | 是 | 目标Function的名称，与functionNamespace共同确定唯一的Function。 |
| args | Record\<string, Object\> | 是 | 符合Function提供方定义格式的输入参数。 |
| options | [InvokeOptions](#invokeoptions) | 否 | Function调用的可选参数。默认值：详见[InvokeOptions](#invokeoptions)的具体属性默认值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<[InvokeResult](#invokeresult)\> | Promise对象。返回Function调用的结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 35600050 | System Error. 1. Failed to connect to the system service; 2. The system service failed to communicate with the dependent module. |
| 35600060 | The function does not exist. |
| 35600061 | The function execute failed. |
| 35600062 | The function execute timeout. |

**示例：**

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
