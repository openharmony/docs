# @ohos.app.ability.abilityManager (AbilityManager)

AbilityManager模块提供获取、新增、修改Ability相关信息和状态信息进行的能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口均为系统接口，三方应用不支持调用。

## 导入模块

```ts
import abilityManager from '@ohos.app.ability.abilityManager'
```

## AbilityState

Ability的状态，该类型为枚举，可配合[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)返回Abiltiy的状态。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**: 此枚举类型为系统接口内部定义，三方应用不支持调用。

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| INITIAL | 0 | 表示ability为初始化状态。| 
| FOREGROUND | 9 | 表示ability为前台状态。  | 
| BACKGROUND | 10 | 表示ability为后台状态。  | 
| FOREGROUNDING | 11 | 表示ability为前台调度中状态。  | 
| BACKGROUNDING | 12 | 表示ability为后台调度中状态。  | 

## updateConfiguration

updateConfiguration(config: [Configuration](js-apis-app-ability-configuration.md), callback: AsyncCallback\<void>): void

通过传入修改的配置项来更新配置（callback形式）。

**需要权限**: ohos.permission.UPDATE_CONFIGURATION

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core
 
**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-app-ability-configuration.md)   | 是    | 新的配置项，仅需配置需要更新的项。 |
| callback  | AsyncCallback\<void>                   | 是    | 以回调方式返回接口运行结果，可进行错误处理或其他自定义处理。      |

**示例**：

```ts
var config = {
  language: 'Zh-Hans',
  colorMode: COLOR_MODE_LIGHT,
  direction: DIRECTION_VERTICAL,
  screenDensity: SCREEN_DENSITY_SDPI,
  displayId: 1,
  hasPointerDevice: true,
}

try {
    abilityManager.updateConfiguration(config, (err) => {
        if (err.code != 0) {
            console.log("updateConfiguration fail, err: " + JSON.stringify(err));
        } else {
            console.log("updateConfiguration success.");
        }
    })
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code) +
        ' error.message: ' + JSON.stringify(paramError.message));
}
```

## updateConfiguration

updateConfiguration(config: [Configuration](js-apis-app-ability-configuration.md)): Promise\<void>

通过修改配置来更新配置（Promise形式）。

**需要权限**: ohos.permission.UPDATE_CONFIGURATION

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-app-ability-configuration.md)   | 是    | 新的配置项，仅需配置需要更新的项。 |

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<void> | 以Promise方式返回接口运行结果息，可进行错误处理或其他自定义处理。 |

**示例**：

```ts
var config = {
  language: 'Zh-Hans',
  colorMode: COLOR_MODE_LIGHT,
  direction: DIRECTION_VERTICAL,
  screenDensity: SCREEN_DENSITY_SDPI,
  displayId: 1,
  hasPointerDevice: true,
}

try {
    abilityManager.updateConfiguration(config).then(() => {
        console.log('updateConfiguration success.');
    }).catch((err) => {
        console.log('updateConfiguration fail, err: ' + JSON.stringify(err));
    })
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code) +
        ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getAbilityRunningInfos

getAbilityRunningInfos(callback: AsyncCallback\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>>): void

获取Ability运行相关信息（callback形式）。

**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>>  | 是    | 以回调方式返回接口运行结果及运行中的ability信息，可进行错误处理或其他自定义处理。      |

**示例**：

```ts
try {
    abilityManager.getAbilityRunningInfos((err,data) => {
        if (err.code != 0) {
            console.log("getAbilityRunningInfos fail, error: " + JSON.stringify(err));
        } else {
            console.log("getAbilityRunningInfos success, data: " + JSON.stringify(data));
        }
    });
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code) +
        ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getAbilityRunningInfos

getAbilityRunningInfos(): Promise\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>>

获取Ability运行相关信息（Promise形式）。

**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>> | 以Promise方式返回接口运行结果及运行中的ability信息，可进行错误处理或其他自定义处理。 |

**示例**：

```ts
try {
    abilityManager.getAbilityRunningInfos().then((data) => {
        console.log("getAbilityRunningInfos success, data: " + JSON.stringify(data))
    }).catch((err) => {
        console.log("getAbilityRunningInfos fail, err: "  + JSON.stringify(err));
    });
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code) +
        ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getExtensionRunningInfos

getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo.md)>>): void

获取关于运行扩展能力的信息（callback形式）。

**需要权限**: ohos.permission.GET_RUNNING_INFO

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | 是 | 获取消息数量的最大限制。 |
| callback  | AsyncCallback\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo.md)>>  | 是    | 以回调方式返回接口运行结果及运行中的extension信息，可进行错误处理或其他自定义处理。      |

**示例**：

```ts
var upperLimit = 0;

try {
    abilityManager.getExtensionRunningInfos(upperLimit, (err,data) => { 
        if (err.code != 0) {
            console.log("getExtensionRunningInfos fail, err: " + JSON.stringify(err));
        } else {
            console.log("getExtensionRunningInfos success, data: " + JSON.stringify(data));
        }
    });
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code) +
        ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getExtensionRunningInfos

getExtensionRunningInfos(upperLimit: number): Promise\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo.md)>>

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
| Promise\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo.md)>> | 以Promise方式返回接口运行结果及运行中的extension信息，可进行错误处理或其他自定义处理。 |

**示例**：

```ts
var upperLimit = 0;

try {
    abilityManager.getExtensionRunningInfos(upperLimit).then((data) => {
        console.log("getExtensionRunningInfos success, data: " + JSON.stringify(data));
    }).catch((err) => {
        console.log("getExtensionRunningInfos fail, err: "  + JSON.stringify(err));
    })
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code) +
        ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getTopAbility<sup>9+</sup>

getTopAbility(callback: AsyncCallback\<[ElementName](js-apis-bundleManager-elementName.md)>): void;

获取窗口焦点的ability接口（callback形式）。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<[ElementName](js-apis-bundleManager-elementName.md)>  | 是    | 以回调方式返回接口运行结果及应用名，可进行错误处理或其他自定义处理。      |

**示例**：

```ts
abilityManager.getTopAbility((err,data) => { 
    if (err.code != 0) {
        console.log("getTopAbility fail, err: " + JSON.stringify(err));
    } else {
        console.log("getTopAbility success, data: " + JSON.stringify(data));
    }
});
```

## getTopAbility

getTopAbility(): Promise\<[ElementName](js-apis-bundleManager-elementName.md)>;

获取窗口焦点的ability接口（Promise形式）。
 
**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<[ElementName](js-apis-bundleManager-elementName.md)>| 以Promise方式返回接口运行结果及应用名，可进行错误处理或其他自定义处理。 |

**示例**：

```ts
abilityManager.getTopAbility().then((data) => {
    console.log("getTopAbility success, data: " + JSON.stringify(data));
}).catch((err) => {
    console.log("getTopAbility fail, err: "  + JSON.stringify(err));
})
```