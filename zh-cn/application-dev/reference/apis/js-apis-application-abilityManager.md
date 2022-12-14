# @ohos.application.abilityManager (AbilityManager)

AbilityManager模块提供对Ability相关信息和状态信息进行获取、新增、修改等能力。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口均为系统接口，三方应用不支持调用。

## 导入模块

```ts
import AbilityManager from '@ohos.application.abilityManager'
```

## AbilityState

Ability的状态信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| INITIAL | 0 | 表示ability为initial状态。| 
| FOREGROUND | 9 | 表示ability为foreground状态。  | 
| BACKGROUND | 10 | 表示ability为background状态。  | 
| FOREGROUNDING | 11 | 表示ability为foregrounding状态。  | 
| BACKGROUNDING | 12 | 表示ability为backgrounding状态。  | 

## updateConfiguration

updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void

通过修改配置来更新配置（callback形式）。

**需要权限**: ohos.permission.UPDATE_CONFIGURATION

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core
 
**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-application-configuration.md)   | 是    | 新的配置项。 |
| callback  | AsyncCallback\<void>                   | 是    | 被指定的回调方法。      |

**示例**：

```ts
import abilitymanager from '@ohos.application.abilityManager';

var config = {
  language: 'chinese' 
}

abilitymanager.updateConfiguration(config, () => {
    console.log('------------ updateConfiguration -----------');
})
```

## updateConfiguration

updateConfiguration(config: Configuration): Promise\<void>

通过修改配置来更新配置（Promise形式）。

**需要权限**: ohos.permission.UPDATE_CONFIGURATION

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-application-configuration.md)   | 是    | 新的配置项。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<void> | 返回执行结果。 |

**示例**：

```ts
import abilitymanager from '@ohos.application.abilityManager';

var config = {
  language: 'chinese' 
}

abilitymanager.updateConfiguration(config).then(() => {
  console.log('updateConfiguration success');
}).catch((err) => {
  console.log('updateConfiguration fail');
})
```

## getAbilityRunningInfos

getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void

获取Ability运行相关信息（callback形式）。

**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<AbilityRunningInfo>>  | 是    | 被指定的回调方法。      |

**示例**：

```ts
import abilitymanager from '@ohos.application.abilityManager';

abilitymanager.getAbilityRunningInfos((err,data) => { 
    console.log("getAbilityRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```

## getAbilityRunningInfos

getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>

获取Ability运行相关信息（Promise形式）。

**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<Array\<AbilityRunningInfo>> | 返回执行结果。 |

**示例**：

```ts
import abilitymanager from '@ohos.application.abilityManager';
 
abilitymanager.getAbilityRunningInfos().then((data) => {
    console.log("getAbilityRunningInfos  data: " + JSON.stringify(data))
}).catch((err) => {
  console.log("getAbilityRunningInfos err: "  + err)
});
```

## getExtensionRunningInfos<sup>9+</sup>

getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void

获取关于运行扩展能力的信息（callback形式）。

**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | 是 | 获取消息数量的最大限制。 |
| callback  | AsyncCallback\<Array\<AbilityRunningInfo>>  | 是    | 被指定的回调方法。      |

**示例**：

```ts
import abilitymanager from '@ohos.application.abilityManager';

var upperLimit = 0;

abilitymanager.getExtensionRunningInfos(upperLimit, (err,data) => { 
    console.log("getExtensionRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```

## getExtensionRunningInfos<sup>9+</sup>

getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>

获取关于运行扩展能力的信息（Promise形式）。
 
**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | 是 | 获取消息数量的最大限制。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<Array\<AbilityRunningInfo>> | 返回执行结果。 |

**示例**：

```ts
import abilitymanager from '@ohos.application.abilityManager';

var upperLimit = 0;

abilitymanager.getExtensionRunningInfos(upperLimit).then((data) => {
  console.log("getAbilityRunningInfos data: " + JSON.stringify(data));
}).catch((err) => {
  console.log("getAbilityRunningInfos err: "  + err);
})
```

## getTopAbility<sup>9+</sup>

getTopAbility(callback: AsyncCallback\<ElementName>): void;

获取窗口焦点的ability接口（callback形式）。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<ElementName>  | 是    | 被指定的回调方法。      |

**示例**：

```ts
import abilitymanager from '@ohos.application.abilityManager';

abilitymanager.getTopAbility((err,data) => { 
    console.log("getTopAbility err: "  + err + " data: " + JSON.stringify(data));
});
```

## getTopAbility<sup>9+</sup>

getTopAbility(): Promise\<ElementName>;

获取窗口焦点的ability接口（Promise形式）。
 
**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<ElementName>| 返回执行结果。 |

**示例**：

```ts
import abilitymanager from '@ohos.application.abilityManager';

abilitymanager.getTopAbility().then((data) => {
  console.log("getTopAbility data: " + JSON.stringify(data));
}).catch((err) => {
  console.log("getTopAbility err: "  + err);
})
```