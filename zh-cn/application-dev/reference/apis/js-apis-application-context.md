# Context

Context模块提供开发者运行代码的上下文环境的能力，包括查询和设置应用信息、ResourceManager等信息。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 使用说明

通过AbilityContext等继承实现。

```js
import Ability from '@ohos.application.Ability'

class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let test = "com.example.test";
        let context = this.context.createBundleContext(test);
    }
}
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| resourceManager | resmgr.ResourceManager; | 是 | 否 | ResourceManager对象。 |
| applicationInfo | ApplicationInfo | 是 | 否 | 当前应用信息。 |
| cacheDir | string | 是 | 否 | 应用在内部存储上的缓存路径。 |
| tempDir | string | 是 | 否 | 应用的临时文件路径。 |
| filesDir | string | 是 | 否 | 应用在内部存储上的文件路径。 |
| databaseDir | string | 是 | 否 | 获取本地数据存储路径。 |
| bundleCodeDir | string | 是 | 否 | 应用安装路径。 |
| distributedFilesDir | string | 是 | 否 | 应用的分布式文件路径。 |
| eventHub | [EventHub](js-apis-eventhub.md) | 是 | 否 | 事件中心信息。|
| area | [AreaMode](#areamode) | 是 | 是 | 文件分区。|
| preferencesDir | string | 是 | 是 | 指示应用程序首选项目录。|

## Context.createBundleContext

createBundleContext(bundleName: string): Context;

创建指定应用上下文。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用bundle名。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Context | 对应创建应用的上下文context。 |

**示例：**

```js
import Ability from '@ohos.application.Ability'

class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let test = "com.example.test";
        let context = this.context.createBundleContext(test);
    }
}
```

## Context.createModuleContext

createModuleContext(moduleName: string): Context;

创建指定hap上下文。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | moduleName | string | 是 | 应用内hap名。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Context | 对应创建hap的上下文context。 |

**示例：**

```js
import Ability from '@ohos.application.Ability'

class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let moduleName = "module";
        let context = this.context.createModuleContext(moduleName);
    }
}
```

## Context.createModuleContext

createModuleContext(bundleName: string, moduleName: string): Context;

创建指定应用上下文。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用bundle名。 |
  | moduleName | string | 是 | 应用内hap名。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Context | 对应创建应用内hap的上下文context。 |

**示例：**

```js
import Ability from '@ohos.application.Ability'

class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let bundleName = "com.example.bundle";
        let moduleName = "module";
        let context = this.context.createModuleContext(bundleName, moduleName);
    }
}
```

## Context.getApplicationContext

getApplicationContext(): ApplicationContext;

获取当前applicationContext。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| ApplicationContext | 当前ApplicationContext对象信息。 |

**示例：**

```js
import Ability from '@ohos.application.Ability'

class MainAbility extends Ability {
    onWindowStageCreate(windowStage) {
        let applicationContext = this.context.getApplicationContext();
    }
}
```

## AreaMode

访问的文件分区，每个文件分区有对应自己的内容。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 变量            | 值    | 描述            |
| --------------- | ---- | --------------- |
| EL1             | 0    | 设备级加密区。   |
| EL2             | 1    | 用户凭据加密区。默认为EL2。 |
