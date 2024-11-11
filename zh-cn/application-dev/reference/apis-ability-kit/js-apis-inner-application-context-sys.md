# Context (系统接口)

Context模块提供了ability或application的上下文的能力，包括访问特定应用程序的资源等。

> **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。
>  - 本模块接口为系统接口。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## Context.createBundleContext<sup>(deprecated)</sup>

createBundleContext(bundleName: string): Context

根据Bundle名称创建安装包的上下文。

**说明：**
>
> stage模型多module的情况下可能发生资源id冲突的情况，建议使用[application.createModuleContext](./js-apis-app-ability-application-sys.md#applicationcreatemodulecontext12)替代。
>
> 从 API Version 12 开始废弃，建议使用[application.createBundleContext](./js-apis-app-ability-application-sys.md#applicationcreatebundlecontext12)替代。

**系统接口**：此接口为系统接口。

**需要权限**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | 是    | Bundle名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Context | 安装包的上下文。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let bundleContext: common.Context;
    try {
      bundleContext = this.context.createBundleContext('com.example.test');
    } catch (error) {
      console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

## Context.createModuleContext<sup>(deprecated)</sup>

createModuleContext(bundleName: string, moduleName: string): Context

根据Bundle名称和模块名称创建上下文。

**说明：**
>
> 从 API Version 12 开始废弃，建议使用[application.createModuleContext](./js-apis-app-ability-application-sys.md#applicationcreatemodulecontext12)替代。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | 是    | Bundle名称。 |
| moduleName | string | 是    | 模块名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Context | 模块的上下文。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let moduleContext: common.Context;
    try {
      moduleContext = this.context.createModuleContext('com.example.test', 'entry');
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

## Context.createModuleResourceManager<sup>11+</sup>

createModuleResourceManager(bundleName: string, moduleName: string): resmgr.ResourceManager

为指定Moudle创建资源管理对象。

**系统接口**：此接口为系统接口。

**需要权限**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | 是    | Bundle名称。 |
| moduleName | string | 是    | 模块名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| resmgr.ResourceManager | 资源管理对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let ModuleResourceManager: resourceManager.ResourceManager;
    try {
      ModuleResourceManager = this.context.createModuleResourceManager('com.example.test', 'entry');
    } catch (error) {
      console.error(`createModuleResourceManager failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```
## Context.createSystemHspModuleResourceManager<sup>12+</sup>

createSystemHspModuleResourceManager(bundleName: string, moduleName: string): resmgr.ResourceManager

创建系统级HSP的某个模块的资源管理对象。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型     | 必填   | 说明   |
| -------- |--------| ---- |------|
| bundleName | string | 是    | 包名。  |
| moduleName | string | 是    | 模块名。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16400001 | The specified ability does not exist. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    this.context.createSystemHspModuleResourceManager("com.example.myapplication", "library");
  }
}
```
