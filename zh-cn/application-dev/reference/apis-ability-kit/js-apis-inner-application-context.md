# Context

Context模块继承自[BaseContext](js-apis-inner-application-baseContext.md)，提供了ability或application的上下文的能力，包括访问特定应用程序的资源等。

> **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                  | 类型     | 只读   | 可选   | 说明                                                               |
|---------------------| ------ | ---- | ---- |------------------------------------------------------------------|
| resourceManager     | resmgr.[ResourceManager](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager) | 否    | 否    | 资源管理对象。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| applicationInfo     | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | 否    | 否    | 当前应用程序的信息。 <br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| cacheDir            | string | 否    | 否    | 缓存目录。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| tempDir             | string | 否    | 否    | 临时目录。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| resourceDir<sup>11+<sup>         | string | 否    | 否    | 资源目录。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| filesDir            | string | 否    | 否    | 文件目录。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| databaseDir         | string | 否    | 否    | 数据库目录。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| preferencesDir      | string | 否    | 否    | preferences目录。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| bundleCodeDir       | string | 否    | 否    | 安装包目录。不能拼接路径访问资源文件，请使用[资源管理接口](../apis-localization-kit/js-apis-resource-manager.md)访问资源。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| distributedFilesDir | string | 否    | 否    | 分布式文件目录。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| cloudFileDir<sup>12+</sup>        | string | 否    | 否    | 云文件目录。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。    |
| eventHub            | [EventHub](js-apis-inner-application-eventHub.md) | 否    | 否    | 事件中心，提供订阅、取消订阅、触发事件对象。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| area                | contextConstant.[AreaMode](js-apis-app-ability-contextConstant.md) | 否    | 否    | 文件分区信息。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| processName<sup>18+</sup> | string | 否   | 否 | 当前应用的进程名。<br/>**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。 |

## Context.createModuleContext<sup>(deprecated)</sup>

createModuleContext(moduleName: string): Context

根据模块名创建上下文。

> **说明：**
>
> 从 API Version 12 开始废弃，建议使用[application.createModuleContext](./js-apis-app-ability-application.md#applicationcreatemodulecontext12)替代。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
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
      moduleContext = this.context.createModuleContext('entry');
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

> 说明：仅支持获取本应用中其他Module的Context和应用内HSP的Context，不支持获取其他应用的Context。

## Context.getApplicationContext

getApplicationContext(): ApplicationContext

获取本应用的应用上下文。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ApplicationContext](js-apis-inner-application-applicationContext.md) | 应用上下文Context。 |

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
    let applicationContext: common.Context;
    try {
      applicationContext = this.context.getApplicationContext();
    } catch (error) {
      console.error(`getApplicationContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

## Context.getGroupDir<sup>10+</sup>

getGroupDir(dataGroupID: string): Promise\<string>

通过使用应用中的Group ID获取对应的共享目录，使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| dataGroupID | string | 是    | 原子化服务应用项目创建时，系统会指定分配唯一Group ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<string> | 以Promise方式返回对应的共享目录。如果不存在则返回为空，仅支持应用el2加密级别。|

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let groupId = "1";
    let getGroupDirContext: common.Context = this.context;
    try {
      getGroupDirContext.getGroupDir(groupId).then(data => {
        console.log("getGroupDir result:" + data);
      })
    } catch (error) {
      console.error(`getGroupDirContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

## Context.getGroupDir<sup>10+</sup>

getGroupDir(dataGroupID: string, callback: AsyncCallback\<string>): void

通过使用应用中的Group ID获取对应的共享目录，使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| dataGroupID | string | 是    | 原子化服务应用项目创建时，系统会指定分配唯一Group ID。 |
| callback | AsyncCallback\<string> | 是    | 以callback方式返回对应的共享目录。如果不存在则返回为空，仅支持应用el2加密级别。|

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let getGroupDirContext: common.Context = this.context;

    getGroupDirContext.getGroupDir("1", (err: BusinessError, data) => {
      if (err) {
        console.error(`getGroupDir faile, err: ${JSON.stringify(err)}`);
      } else {
        console.log(`getGroupDir result is: ${JSON.stringify(data)}`);
      }
    });
  }
}
```

## Context.createAreaModeContext<sup>18+</sup>

createAreaModeContext(areaMode: contextConstant.AreaMode): Context

当应用需要将不同类型的信息存放在不同目录下时，可以根据指定的数据加密级别创建应用上下文，以获取相应的路径。

**原子化服务API**：从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| areaMode | [contextConstant.AreaMode](js-apis-app-ability-contextConstant.md#areamode) | 是   | 指定的数据加密等级。 |

**返回值：**

| 类型    | 说明                   |
| ------- | ---------------------- |
| Context | 指定数据加密等级的上下文。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { common, UIAbility, contextConstant } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    let areaMode: contextConstant.AreaMode = contextConstant.AreaMode.EL2;
    let areaModeContext: common.Context;
    try {
      areaModeContext = this.context.createAreaModeContext(areaMode);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'createAreaModeContext error is:%{public}s', JSON.stringify(error));
    }
  }
}
```

## Context.createDisplayContext<sup>15+</sup>

createDisplayContext(displayId: number): Context

根据指定的物理屏幕ID创建应用上下文，以便于获取和使用其他带有屏幕信息（包括屏幕密度[ScreenDensity](../apis-localization-kit/js-apis-resource-manager.md#screendensity)和屏幕方向[Direction](../apis-localization-kit/js-apis-resource-manager.md#direction)）的应用上下文。

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| displayId | number | 是    | 物理屏幕ID。 |

**返回值：**

| 类型    | 说明                   |
| ------- | ---------------------- |
| [Context](#context) | 带有指定物理屏幕信息的上下文。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
    let displayContext: common.Context;
    try {
      displayContext = this.context.createDisplayContext(0);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'createDisplayContext error is:%{public}s', JSON.stringify(error));
    }
  }
}
```
