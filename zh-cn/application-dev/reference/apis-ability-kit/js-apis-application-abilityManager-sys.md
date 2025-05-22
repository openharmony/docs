# @ohos.application.abilityManager (AbilityManager)(系统接口)

AbilityManager模块提供对Ability相关信息和状态信息进行获取、新增、修改等能力。

> **说明：**
>
> 本模块首批接口从API version 8开始支持，从API version 9废弃，替换模块为[@ohos.app.ability.abilityManager](js-apis-app-ability-abilityManager-sys.md)。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口均为系统接口，三方应用不支持调用。

## 导入模块

```ts
import abilityManager from '@ohos.application.abilityManager';
```

## AbilityState

Ability的状态信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| INITIAL | 0 | 表示Ability为初始化状态。| 
| FOREGROUND | 9 | 表示Ability处于前台。  | 
| BACKGROUND | 10 | 表示Ability处于后台。  | 
| FOREGROUNDING | 11 | 表示Ability处于前台调度中。  | 
| BACKGROUNDING | 12 | 表示Ability处于后台调度中。  | 

## updateConfiguration

updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void

通过修改配置来更新配置。使用callback异步回调。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-application-configuration.md)   | 是    | 新的配置项。 |
| callback  | AsyncCallback\<void>                   | 是    | 回调函数，当通过修改配置来更新配置成功，err为undefined，否则为错误对象。      |

**示例**：

```ts
import abilityManager from '@ohos.application.abilityManager';
import { Configuration } from '@ohos.application.Configuration';

let config: Configuration = {
  language: 'chinese' 
};

abilityManager.updateConfiguration(config, () => {
    console.log('------------ updateConfiguration -----------');
});
```

## updateConfiguration

updateConfiguration(config: Configuration): Promise\<void>

通过修改配置来更新配置。使用Promise异步回调。

**需要权限**：ohos.permission.UPDATE_CONFIGURATION

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-application-configuration.md)   | 是    | 新的配置项。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例**：

```ts
import abilityManager from '@ohos.application.abilityManager';
import { Configuration } from '@ohos.application.Configuration';
import { BusinessError } from '@ohos.base';

let config: Configuration = {
  language: 'chinese' 
};

abilityManager.updateConfiguration(config).then(() => {
  console.log('updateConfiguration success');
}).catch((err: BusinessError) => {
  console.error('updateConfiguration fail');
});
```

## getAbilityRunningInfos

getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void

获取Ability运行相关信息。使用callback异步回调。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>>  | 是    | 回调函数，返回Ability运行相关信息。      |

**示例**：

```ts
import abilityManager from '@ohos.application.abilityManager';
import { BusinessError } from '@ohos.base';

abilityManager.getAbilityRunningInfos((err: BusinessError, data) => { 
    console.log(`getAbilityRunningInfos err: ${err}, data: ${JSON.stringify(data)}`);
});
```

## getAbilityRunningInfos

getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>

获取Ability运行相关信息。使用Promise异步回调。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>> | Promise对象，返回Ability运行相关信息。 |

**示例**：

```ts
import abilityManager from '@ohos.application.abilityManager';
import { BusinessError } from '@ohos.base';

abilityManager.getAbilityRunningInfos().then((data) => {
    console.log(`getAbilityRunningInfos  data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getAbilityRunningInfos err: ${JSON.stringify(err)}`);
});
```