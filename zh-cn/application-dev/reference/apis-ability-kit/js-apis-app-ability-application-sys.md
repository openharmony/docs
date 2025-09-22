#  @ohos.app.ability.application (Application)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

开发者可以通过该模块创建[Context](../../application-models/application-context-stage.md)。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { application } from '@kit.AbilityKit';
```
## application.createModuleContext<sup>12+</sup>

createModuleContext(context: Context, bundleName: string, moduleName: string): Promise\<Context>

根据入参Context创建相应模块的Context。使用Promise异步回调。

> **说明：**
>
> - 从API version 18开始，Context支持获取当前应用的进程名[processName](js-apis-inner-application-context.md#context)。createModuleContext创建的Context中的processName属性与入参Context中的processName属性一致，其他属性根据入参Context、bundleName和moduleName获得相应的属性值。
>
> - 该接口需要多次查询包信息、加载指定Module的全部资源，耗时较长。建议首次使用该接口时缓存创建的Context，以避免重复调用该接口创建Context。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| context | [Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md) | 是 | 表示应用上下文。 | 
| bundleName | string   | 是    | 表示应用包名。取值为空字符串时，默认为当前应用。|
| moduleName | string | 是 | 表示应用模块名。 |

**返回值：**

| 类型               | 说明                |
| ------------------ | ------------------- |
| Promise\<[Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md)> | Promise对象。返回创建的Context。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api.|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { UIAbility, application, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    let moduleContext: common.Context;
    try {
      application.createModuleContext(this.context, 'bundlename', 'entry').then((data: Context)=>{
        moduleContext = data;
        console.info('createModuleContext success!');
      }).catch((error : BusinessError)=>{
        console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
      })
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

## application.createBundleContext<sup>12+</sup>

createBundleContext(context: Context, bundleName: string): Promise\<Context>

根据入参Context创建相应应用的Context。使用Promise异步回调。

> **说明：**
>
> 从API version 18开始，Context支持获取当前应用的进程名[processName](js-apis-inner-application-context.md#context)。createBundleContext创建的Context中的processName属性与入参Context中的processName属性一致，其他属性根据入参Context、bundleName和moduleName获得相应的属性值。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| context | [Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md) | 是 | 表示应用上下文。 | 
| bundleName | string   | 是    | 表示应用包名。 |

**返回值：**

| 类型               | 说明                |
| ------------------ | ------------------- |
| Promise\<[Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md)> | Promise对象。返回创建的Context。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api.|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |


**示例：**

```ts
import { UIAbility, application, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    let moduleContext: common.Context;
    try {
      application.createBundleContext(this.context, 'bundlename').then((data: Context)=>{
        moduleContext = data;
        console.info('createBundleContext success!');
      }).catch((error : BusinessError)=>{
        console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
      })
    } catch (error) {
      console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}

```
## application.createPluginModuleContextForHostBundle<sup>20+</sup>

createPluginModuleContextForHostBundle(context: Context, pluginBundleName: string, pluginModuleName: string, hostBundleName: string): Promise\<Context>

根据入参Context、插件包名和插件模块名和应用包名，创建对应插件的Context，用于获取插件的基本信息。使用Promise异步回调。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口：** 此接口为系统接口。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| context | [Context](js-apis-inner-application-context.md) | 是 | 表示应用上下文。 |
| pluginBundleName | string | 是 | 表示应用的插件包名。 |
| pluginModuleName | string | 是 | 表示应用的插件模块名。 |
| hostBundleName | string | 是 | 表示安装插件的应用包名。 |

**返回值：**

| 类型               | 说明                |
| ------------------ | ------------------- |
| Promise\<[Context](js-apis-inner-application-context.md)> | Promise对象。返回创建的Context，返回的Context中的属性processName和config与入参Context中的属性processName和config的值相同。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 201      | Permission denied. |
| 202      | Permission denied, non-system app called system api. |

**示例：**

```ts
import { AbilityConstant, UIAbility, application, common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    let moduleContext: common.Context;
    try {
      application.createPluginModuleContextForHostBundle(this.context, 'com.example.pluginBundleName', 'pluginModuleName', 'com.example.hostBundleName')
        .then((data: Context) => {
          moduleContext = data;
          console.info('createPluginModuleContextForHostBundle success!');
        })
        .catch((error: BusinessError) => {
          let code: number = (error as BusinessError).code;
          let message: string = (error as BusinessError).message;
          console.error(`createPluginModuleContextForHostBundle failed, error.code: ${code}, error.message: ${message}`);
        });
    } catch (error) {
      let code: number = (error as BusinessError).code;
      let message: string = (error as BusinessError).message;
      console.error(`createPluginModuleContextForHostBundle failed, error.code: ${code}, error.message: ${message}`);
    }
  }
}
```