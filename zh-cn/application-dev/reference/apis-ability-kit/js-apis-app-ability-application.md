#  @ohos.app.ability.application (应用工具类)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @li-weifeng2024-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

开发者可以通过该模块管理和获取应用的上下文[Context](../../application-models/application-context-stage.md)，以及控制应用进程的状态。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { application } from '@kit.AbilityKit';
```

## application.createModuleContext<sup>12+</sup>

createModuleContext(context: Context, moduleName: string): Promise\<Context>

创建指定模块的上下文。创建出的模块上下文中[resourceManager.Configuration](../apis-localization-kit/js-apis-resource-manager.md#configuration)资源继承自入参上下文，便于开发者获取[跨HAP/HSP包应用资源](../../quick-start/resource-categories-and-access.md#跨haphsp包应用资源)。使用Promise异步回调。

**原子化服务API**：从API version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| context | [Context](js-apis-inner-application-context.md) | 是 | 表示应用上下文。 |
| moduleName | string | 是 | 表示应用模块名。 |

**返回值：**

| 类型               | 说明                |
| ------------------ | ------------------- |
| Promise\<[Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md)> | Promise对象。返回创建的Context。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { AbilityConstant, UIAbility, application, common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    let moduleContext: common.Context;
    try {
      application.createModuleContext(this.context, 'entry').then((data: Context) => {
        moduleContext = data;
        console.info('createModuleContext success!');
      }).catch((error: BusinessError) => {
        let code: number = (error as BusinessError).code;
        let message: string = (error as BusinessError).message;
        console.error(`createModuleContext failed, error.code: ${code}, error.message: ${message}`);
      });
    } catch (error) {
      let code: number = (error as BusinessError).code;
      let message: string = (error as BusinessError).message;
      console.error(`createModuleContext failed, error.code: ${code}, error.message: ${message}`);
    }
  }
}
```

## application.getApplicationContext<sup>14+</sup>

getApplicationContext(): ApplicationContext

获取应用上下文。开发者使用该接口时，无需依赖Context基类。重复调用会生成新的ApplicationContext对象。

**原子化服务API**：从API version 14开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                                         | 说明                |
| ------------------------------------------------------------ | ------------------- |
| [ApplicationContext](js-apis-inner-application-applicationContext.md) | 应用上下文。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 16000050 | Internal error. |

**示例：**

```ts
import { AbilityConstant, UIAbility, application, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    try {
      let applicationContext = application.getApplicationContext();
    } catch (error) {
      let code: number = (error as BusinessError).code;
      let message: string = (error as BusinessError).message;
      console.error(`getApplicationContext failed, error.code: ${code}, error.message: ${message}`);
    }
  }
}
```

## application.createPluginModuleContext<sup>19+</sup>

createPluginModuleContext(context: Context, pluginBundleName: string, pluginModuleName: string): Promise\<Context>

根据入参Context、指定的插件包名和插件模块名，创建本应用下插件的Context，用于获取插件的基本信息。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| context | [Context](js-apis-inner-application-context.md) | 是 | 表示应用上下文。 |
| pluginBundleName | string | 是 | 表示应用的插件包名。 |
| pluginModuleName | string | 是 | 表示应用的插件模块名。 |

**返回值：**

| 类型               | 说明                |
| ------------------ | ------------------- |
| Promise\<[Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md)> | Promise对象。返回创建的Context。 |

**示例：**

```ts
import { AbilityConstant, UIAbility, application, common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    let moduleContext: common.Context;
    try {
      application.createPluginModuleContext(this.context, 'com.example.pluginBundleName', 'pluginModuleName')
        .then((data: Context) => {
          moduleContext = data;
          console.info('createPluginModuleContext success!');
        })
        .catch((error: BusinessError) => {
          let code: number = (error as BusinessError).code;
          let message: string = (error as BusinessError).message;
          console.error(`createPluginModuleContext failed, error.code: ${code}, error.message: ${message}`);
        });
    } catch (error) {
      let code: number = (error as BusinessError).code;
      let message: string = (error as BusinessError).message;
      console.error(`createPluginModuleContext failed, error.code: ${code}, error.message: ${message}`);
    }
  }
}
```

## application.promoteCurrentToCandidateMasterProcess<sup>20+</sup>

promoteCurrentToCandidateMasterProcess(insertToHead: boolean): Promise\<void>

开发者可以调用该接口将当前进程放入[备选主控进程](../../application-models/ability-terminology.md#candidatemasterprocess备选主控进程)链表。使用Promise异步回调。

当[主控进程](../../application-models/ability-terminology.md#masterprocess主控进程)销毁后，再次启动配置了isolationProcess为true的UIAbility/UIExtensionAbility组件时，系统会根据是否存在备选主控进程执行相应操作。

- 如果存在备选主控进程，系统会将备选主控进程链表首节点的进程设置为主控进程，触发[onNewProcessRequest](js-apis-app-ability-abilityStage.md#onnewprocessrequest11)回调。
- 如果不存在备选主控进程，系统会根据组件类型执行相应的操作。
	- 对于UIAbility组件，系统将创建新的空进程作为主控进程。
	- 对于UIExtensionAbility组件，系统会优先复用已有的UIExtensionAbility进程作为新的主控进程，无可用进程时则创建新的空进程作为主控进程。

<!--Del-->
> **说明：**
>
> 当前仅支持sys/commonUI类型的UIExtensionAbility组件在[module.json5配置文件](../../quick-start/module-configuration-file.md)中配置isolationProcess字段为true。
<!--DelEnd-->

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口在PC/2in1、Tablet中可正常调用，在其他设备类型中返回801错误码。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| insertToHead | boolean | 是 | 表示是否将当前进程放入备选主控进程链表的表头。true表示放入表头，false表示放入表尾。|

**返回值：**

| 类型               | 说明                |
| ------------------ | ------------------- |
|Promise\<void> | Promise对象。无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](./errorcode-ability.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 801 | Capability not supported.|
| 16000115 | The current process is not running a component configured with "isolationProcess" and cannot be set as a candidate master process. |


**示例：**

```ts
import { AbilityConstant, UIAbility, application, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    try {
      application.promoteCurrentToCandidateMasterProcess(true)
        .then(() => {
          console.info('promote succeed');
        })
        .catch((err: BusinessError) => {
          console.error(`promote failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (error) {
      let code: number = (error as BusinessError).code;
      let message: string = (error as BusinessError).message;
      console.error(`promoteCurrentToCandidateMasterProcess failed, error.code: ${code}, error.message: ${message}`);
    }
  }
}
```

## application.demoteCurrentFromCandidateMasterProcess<sup>20+</sup>

demoteCurrentFromCandidateMasterProcess(): Promise\<void>

撤销当前进程的备选主控进程资格。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口在PC/2in1、Tablet中可正常调用，在其他设备类型中返回801错误码。

**返回值：**

| 类型               | 说明                |
| ------------------ | ------------------- |
|Promise\<void> | Promise对象。无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 801 | Capability not supported.|
| 16000116 | The current process is already a master process and does not support cancellation. |
| 16000117 | The current process is not a candidate master process and does not support cancellation. |

**示例：**

```ts
import { AbilityConstant, UIAbility, application, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    try {
      application.demoteCurrentFromCandidateMasterProcess()
        .then(() => {
          console.info('demote succeed');
        })
        .catch((err: BusinessError) => {
          console.error(`demote failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (error) {
      let code: number = (error as BusinessError).code;
      let message: string = (error as BusinessError).message;
      console.error(`demoteCurrentFromCandidateMasterProcess failed, error.code: ${code}, error.message: ${message}`);
    }
  }
}
```

## application.exitMasterProcessRole<sup>21+</sup>

exitMasterProcessRole(): Promise\<void>

放弃当前进程的[主控进程](../../application-models/ability-terminology.md#masterprocess主控进程)身份。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异：** 该接口仅在2in1、Tablet设备中可正常调用，在其他设备中返回801错误码。

**返回值：**

| 类型               | 说明                |
| ------------------ | ------------------- |
|Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码说明文档](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 801 | Capability not supported.|
| 16000118 | Not a master process. |
| 16000119 | Cannot exit because there is an unfinished onNewProcessRequest. |

**示例：**

```ts
import { AbilityConstant, UIAbility, application, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    try {
      application.exitMasterProcessRole()
        .then(() => {
          console.info('exitMasterProcessRole succeed');
        })
        .catch((err: BusinessError) => {
          console.error(`exitMasterProcessRole failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (error) {
      let code: number = (error as BusinessError).code;
      let message: string = (error as BusinessError).message;
      console.error(`exitMasterProcessRole failed, error.code: ${code}, error.message: ${message}`);
    }
  }
}
```