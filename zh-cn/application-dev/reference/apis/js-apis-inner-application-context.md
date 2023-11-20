# Context

Context模块提供了ability或application的上下文的能力，包括访问特定应用程序的资源等。

> **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import common from '@ohos.app.ability.common';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称          | 类型     | 只读   | 必填   | 说明      |
| ----------- | ------ | ---- | ---- | ------- |
| resourceManager     | resmgr.[ResourceManager](js-apis-resource-manager.md#resourcemanager) | 否    | 是    | 资源管理对象。   |
| applicationInfo | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | 否    | 是    | 当前应用程序的信息。 |
| cacheDir | string | 否    | 是    | 缓存目录。 |
| tempDir | string | 否    | 是    | 临时目录。 |
| filesDir | string | 否    | 是    | 文件目录。 |
| databaseDir | string | 否    | 是    | 数据库目录。 |
| preferencesDir | string | 否    | 是    | preferences目录。 |
| bundleCodeDir | string | 否    | 是    | 安装包目录。不能拼接路径访问资源文件，请使用[资源管理接口](js-apis-resource-manager.md)访问资源。 |
| distributedFilesDir | string | 是    | 是    | 分布式文件目录。 |
| eventHub | [EventHub](js-apis-inner-application-eventHub.md) | 否    | 是    | 事件中心，提供订阅、取消订阅、触发事件对象。 |
| area | contextConstant.[AreaMode](js-apis-app-ability-contextConstant.md) | 否    | 是    | 文件分区信息。 |

## Context.createBundleContext

createBundleContext(bundleName: string): Context

根据Bundle名称创建安装包的上下文。

**需要权限**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | 是    | Bundle名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Context | 安装包的上下文。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let bundleContext: common.Context;
    try {
      bundleContext = this.context.createBundleContext('com.example.test');
    } catch (error) {
      console.error(`createBundleContext failed, error.code: ${error.code}, error.message: ${error.message}`);
    }
  }
}
```

## Context.createModuleContext

createModuleContext(moduleName: string): Context

根据模块名创建上下文。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| moduleName | string | 是    | 模块名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Context | 模块的上下文。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let moduleContext: common.Context;
    try {
      moduleContext = this.context.createModuleContext('entry');
    } catch (error) {
      console.error('createModuleContext failed, error.code: ${error.code}, error.message: ${error.message}');
    }
  }
}
```

## Context.createModuleContext

createModuleContext(bundleName: string, moduleName: string): Context

根据Bundle名称和模块名称创建上下文。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | 是    | Bundle名称。 |
| moduleName | string | 是    | 模块名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Context | 模块的上下文。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let moduleContext: common.Context;
    try {
      moduleContext = this.context.createModuleContext('com.example.test', 'entry');
    } catch (error) {
      console.error('createModuleContext failed, error.code: ${error.code}, error.message: ${error.message}');
    }
  }
}
```

## Context.getApplicationContext

getApplicationContext(): ApplicationContext

获取本应用的应用上下文。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ApplicationContext](js-apis-inner-application-applicationContext.md) | 应用上下文Context。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let applicationContext: common.Context;
    try {
      applicationContext = this.context.getApplicationContext();
    } catch (error) {
      console.error('getApplicationContext failed, error.code: ${error.code}, error.message: ${error.message}');
    }
  }
}
```

## Context.getGroupDir<sup>10+</sup>

getGroupDir(dataGroupID: string): Promise\<string>

通过使用元服务应用中的Group ID获取对应的共享目录，使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| dataGroupID | string | 是    | 元服务应用项目创建时，系统会指定分配唯一Group ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<string> | 以Promise方式返回对应的共享目录。如果不存在则返回为空，仅支持应用el2加密级别。|

**错误码**：

以下错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

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
      console.error('getGroupDirContext failed, error.code: ${error.code}, error.message: ${error.message}');
    }
  }
}
```

## Context.getGroupDir<sup>10+</sup>

getGroupDir(dataGroupID: string, callback: AsyncCallback\<string>): void

通过使用元服务应用中的Group ID获取对应的共享目录，使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名       | 类型                     | 必填   | 说明            |
| -------- | ---------------------- | ---- | ------------- |
| dataGroupID | string | 是    | 元服务应用项目创建时，系统会指定分配唯一Group ID。 |
| callback | AsyncCallback\<string> | 是    | 以callback方式返回对应的共享目录。如果不存在则返回为空，仅支持应用el2加密级别。|

**错误码**：

以下错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let getGroupDirContext: common.Context = this.context;

    getGroupDirContext.getGroupDir("1", (err, data) => {
      if (err) {
        console.error(`getGroupDir faile, err: ${JSON.stringify(err)}`);
      } else {
        console.log(`getGroupDir result is: ${JSON.stringify(data)}`);
      }
    });
  }
}
```

