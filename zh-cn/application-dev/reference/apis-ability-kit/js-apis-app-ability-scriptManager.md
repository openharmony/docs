# @ohos.app.ability.scriptManager (脚本管理)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @RuiChen_01-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

本模块提供管理和组织脚本信息的能力，支持应用的ArkTS脚本执行结果上报。

> **说明：**
>
> - 应用的ArkTS脚本需要绑定一个Ability，在[module.json5](../../quick-start/module-configuration-file.md)的[skillProfiles标签](../../quick-start/module-configuration-file.md#skillprofiles标签)中配置对应的Ability。
> - 脚本通过export default class导出，其入口函数的第一个参数固定为[ArkTSScriptInfo](#arktsscriptinfo)，用于接收系统传递的脚本上下文信息，开发者可在第一个参数后添加自定义参数。

## 导入模块

```ts
import { scriptManager } from '@kit.AbilityKit';
```

**起始版本：** 26.0.0

## ExecuteResult

ArkTS脚本执行结果。

**起始版本：** 26.0.0

**原子化服务API**：从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| code | number | 否 | 否 | 表示结果码。取值范围为整数，默认值为0。 |
| result | Record\<string, Object> | 否 | 是 | 表示脚本执行结果。 |
| uris | Array\<string> | 否 | 是 | 表示需要授权给调用方的URI列表。 |
| flags | number | 否 | 是 | 表示URI的读写权限，与[Want](js-apis-app-ability-want.md)的flags字段含义一致。取值范围如下：<br>- [wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION](js-apis-app-ability-wantConstant.md#flags)：读权限。<br>- [wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION](js-apis-app-ability-wantConstant.md#flags)：写权限。<br>- 以上两个标志的组合：同时授权读写权限。 |

## ArkTSScriptInfo

应用的ArkTS脚本入口函数的第一个参数，用于接收系统传递的脚本上下文信息。

**起始版本：** 26.0.0

**原子化服务API**：从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| requestCode | string | 是 | 否 | 用于标识当前操作的请求码。 |
| context | [Context](js-apis-inner-application-context.md) | 是 | 否 | 绑定的Ability上下文。 |

## scriptManager.completeArkTSScriptInApp

completeArkTSScriptInApp(context: Context, requestCode: string, result: ExecuteResult): Promise\<void>

完成应用的ArkTS脚本执行，上报执行结果。使用Promise异步回调。

**起始版本：** 26.0.0

**原子化服务API**：从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AgentRuntime.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | 是 | Ability上下文，用于临时文件授权。 |
| requestCode | string | 是 | 用于标识当前操作的请求码。 |
| result | [ExecuteResult](#executeresult) | 是 | ArkTS脚本的执行结果。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 16000020 | The context is not ability context. |
| 16000003 | The specified ID does not exist. |
| 16000050 | Internal error. Possible causes: 1. Connect to system service failed; 2. Send restart message to system service failed; 3. System service failed to communicate with dependency module. |

**示例：**

```ts
import { scriptManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class TotalTimeSkill {
  // 入口函数第一个参数必须为scriptManager.ArkTSScriptInfo，后续参数为开发者自定义
  public async RemoteTotalTimeModel(arkTSScriptInfo: scriptManager.ArkTSScriptInfo, ...argv: string[]): Promise<void> {
    // 参数解析
    const ruleId = argv[1] ? parseInt(argv[1], 10) : null;
    const childInfoStr = argv[2] || '{}'; 
    // 实现用户功能 输出结果data
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
