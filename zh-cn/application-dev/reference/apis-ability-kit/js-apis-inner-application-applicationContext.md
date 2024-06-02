# ApplicationContext

ApplicationContext模块继承自[Context](js-apis-inner-application-context.md)，提供开发者应用级别的的上下文的能力，包括提供注册及取消注册应用内组件生命周期的监听接口。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import common from '@ohos.app.ability.common';
```

## 使用说明

在使用ApplicationContext的功能前，需要通过context的实例获取。

## ApplicationContext.on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback)

on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback): number

注册监听应用内生命周期。使用callback异步回调。不支持多线程并发调用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | 'abilityLifecycle' | 是   | 监听事件的类型。 |
| callback | [AbilityLifecycleCallback](js-apis-app-ability-abilityLifecycleCallback.md) | 是   | 回调方法，返回注册监听事件的ID。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| number | 返回的此次注册监听生命周期的ID（每次注册该ID会自增+1，当超过监听上限数量2^63-1时，返回-1）。|

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

let lifecycleId: number;

export default class EntryAbility extends UIAbility {
    onCreate() {
        console.log('MyAbility onCreate');
        let AbilityLifecycleCallback: AbilityLifecycleCallback = {
            onAbilityCreate(ability) {
                console.log(`AbilityLifecycleCallback onAbilityCreate ability: ${ability}`);
            },
            onWindowStageCreate(ability, windowStage) {
                console.log(`AbilityLifecycleCallback onWindowStageCreate ability: ${ability}`);
                console.log(`AbilityLifecycleCallback onWindowStageCreate windowStage: ${windowStage}`);
            },
            onWindowStageActive(ability, windowStage) {
                console.log(`AbilityLifecycleCallback onWindowStageActive ability: ${ability}`);
                console.log(`AbilityLifecycleCallback onWindowStageActive windowStage: ${windowStage}`);
            },
            onWindowStageInactive(ability, windowStage) {
                console.log(`AbilityLifecycleCallback onWindowStageInactive ability: ${ability}`);
                console.log(`AbilityLifecycleCallback onWindowStageInactive windowStage: ${windowStage}`);
            },
            onWindowStageDestroy(ability, windowStage) {
                console.log(`AbilityLifecycleCallback onWindowStageDestroy ability: ${ability}`);
                console.log(`AbilityLifecycleCallback onWindowStageDestroy windowStage: ${windowStage}`);
            },
            onAbilityDestroy(ability) {
                console.log(`AbilityLifecycleCallback onAbilityDestroy ability: ${ability}`);
            },
            onAbilityForeground(ability) {
                console.log(`AbilityLifecycleCallback onAbilityForeground ability: ${ability}`);
            },
            onAbilityBackground(ability) {
                console.log(`AbilityLifecycleCallback onAbilityBackground ability: ${ability}`);
            },
            onAbilityContinue(ability) {
                console.log(`AbilityLifecycleCallback onAbilityContinue ability: ${ability}`);
            }
        }
        // 1.通过context属性获取applicationContext
        let applicationContext = this.context.getApplicationContext();
        // 2.通过applicationContext注册监听应用内生命周期
        lifecycleId = applicationContext.on('abilityLifecycle', AbilityLifecycleCallback);
        console.log(`registerAbilityLifecycleCallback lifecycleId: ${lifecycleId}`);
    }
}
```

## ApplicationContext.off(type: 'abilityLifecycle', callbackId: number, callback: AsyncCallback\<void>)

off(type: 'abilityLifecycle', callbackId: number,  callback: AsyncCallback\<void>): void

取消监听应用内生命周期。使用callback异步回调。不支持多线程并发调用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听应用内生命周期的ID。 |
| callback | AsyncCallback\<void> | 是   | 回调方法。当取消监听应用内生命周期成功，err为undefined，否则为错误对象。   |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

let lifecycleId: number;

export default class EntryAbility extends UIAbility {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        console.log(`stage applicationContext: ${applicationContext}`);
        applicationContext.off('abilityLifecycle', lifecycleId, (error, data) => {
            if (error) {
                console.error(`unregisterAbilityLifecycleCallback fail, err: ${JSON.stringify(error)}`);
            } else {
                console.log(`unregisterAbilityLifecycleCallback success, data: ${JSON.stringify(data)}`);
            }
        });
    }
}
```

## ApplicationContext.off(type: 'abilityLifecycle', callbackId: number)

off(type: 'abilityLifecycle', callbackId: number): Promise\<void>

取消监听应用内生命周期。使用Promise异步回调。不支持多线程并发调用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听应用内生命周期的ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import Ability from '@ohos.app.ability.UIAbility';

let lifecycleId: number;

export default class MyAbility extends Ability {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        console.log(`stage applicationContext: ${applicationContext}`);
        applicationContext.off('abilityLifecycle', lifecycleId);
    }
}
```

## ApplicationContext.on(type: 'environment', callback: EnvironmentCallback)

on(type: 'environment', callback: EnvironmentCallback): number

注册对系统环境变化的监听。使用callback异步回调。不支持多线程并发调用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | 'environment' | 是   | 监听事件的类型。 |
| callback | [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) | 是   | 回调方法，提供应用上下文ApplicationContext对系统环境变量监听回调的能力。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| number | 返回的此次注册监听系统环境变化的ID（每次注册该ID会自增+1，当超过监听上限数量2^63-1时，返回-1）。|

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import EnvironmentCallback from '@ohos.app.ability.EnvironmentCallback';

let callbackId: number;

export default class EntryAbility extends UIAbility {
    onCreate() {
        console.log('MyAbility onCreate')
        let environmentCallback: EnvironmentCallback = {
            onConfigurationUpdated(config){
                console.log(`onConfigurationUpdated config: ${JSON.stringify(config)}`);
            },
            onMemoryLevel(level){
                console.log(`onMemoryLevel level: ${level}`);
            }
        };
        // 1.获取applicationContext
        let applicationContext = this.context.getApplicationContext();
        // 2.通过applicationContext注册监听系统环境变化
        callbackId = applicationContext.on('environment', environmentCallback);
        console.log(`registerEnvironmentCallback callbackId: ${callbackId}`);
    }
}
```

## ApplicationContext.off(type: 'environment', callbackId: number, callback: AsyncCallback\<void>)

off(type: 'environment', callbackId: number,  callback: AsyncCallback\<void>): void

取消对系统环境变化的监听。使用callback异步回调。不支持多线程并发调用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听系统环境变化的ID。   |
| callback | AsyncCallback\<void> | 是   | 回调方法。当取消对系统环境变化的监听成功，err为undefined，否则为错误对象。   |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

let callbackId: number;

export default class EntryAbility extends UIAbility {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.off('environment', callbackId, (error, data) => {
            if (error) {
                console.error(`unregisterEnvironmentCallback fail, err: ${JSON.stringify(error)}`);
            } else {
                console.log(`unregisterEnvironmentCallback success, data: ${JSON.stringify(data)}`);
            }
        });
    }
}
```

## ApplicationContext.off(type: 'environment', callbackId: number)

off(type: 'environment', callbackId: number): Promise\<void\>

取消对系统环境变化的监听。使用Promise异步回调。不支持多线程并发调用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听系统环境变化的ID。   |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import Ability from '@ohos.app.ability.UIAbility';

let callbackId: number;

export default class MyAbility extends Ability {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.off('environment', callbackId);
    }
}
```

## ApplicationContext.on(type: 'applicationStateChange', callback: ApplicationStateChangeCallback)<sup>10+</sup>

on(type: 'applicationStateChange', callback: ApplicationStateChangeCallback): void

注册对当前应用前后台变化的监听。使用callback异步回调。不支持多线程并发调用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明             |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| type     | 'applicationStateChange'                                     | 是   | 监听事件类型。 |
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | 是   | 回调函数。可以对应用从后台切换到前台，以及前台切换到后台分别定义回调。       |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import ApplicationStateChangeCallback from '@ohos.app.ability.ApplicationStateChangeCallback';

export default class MyAbility extends UIAbility {
    onCreate() {
        console.log('MyAbility onCreate');
        let applicationStateChangeCallback: ApplicationStateChangeCallback = {
            onApplicationForeground() {
                console.info('applicationStateChangeCallback onApplicationForeground');
            },
            onApplicationBackground() {
                console.info('applicationStateChangeCallback onApplicationBackground');
            }
        }

        // 1.获取applicationContext
        let applicationContext = this.context.getApplicationContext();
        // 2.通过applicationContext注册应用前后台状态监听
        applicationContext.on('applicationStateChange', applicationStateChangeCallback);
        console.log('Resgiter applicationStateChangeCallback');
    }
}
```

## ApplicationContext.off(type: 'applicationStateChange', callback?: ApplicationStateChangeCallback)<sup>10+</sup>

off(type: 'applicationStateChange', callback?: ApplicationStateChangeCallback): void

取消当前应用注册的前后台变化的全部监听。使用callback异步回调。不支持多线程并发调用。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| type   | 'applicationStateChange' | 是   | 取消监听事件的类型。 |
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | 否   | 回调函数。可以对应用从后台切换到前台，以及前台切换到后台分别定义回调。       |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.off('applicationStateChange');
    }
}
```

## ApplicationContext.getRunningProcessInformation

getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>

获取有关运行进程的信息。使用Promise异步回调。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Promise对象，返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';

export default class MyAbility extends UIAbility {
    onForeground() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.getRunningProcessInformation().then((data) => {
            console.log(`The process running information is: ${JSON.stringify(data)}`);
        }).catch((error: BusinessError) => {
            console.error(`error: ${JSON.stringify(error)}`);
        });
    }
}
```

## ApplicationContext.getRunningProcessInformation

getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void

获取有关运行进程的信息。使用callback异步回调。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>>   | 是   | 回调函数，返回有关运行进程的信息。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
    onForeground() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.getRunningProcessInformation((err, data) => {
            if (err) {
                console.error(`getRunningProcessInformation faile, err: ${JSON.stringify(err)}`);
            } else {
                console.log(`The process running information is: ${JSON.stringify(data)}`);
            }
        })
    }
}
```

## ApplicationContext.killAllProcesses

killAllProcesses(): Promise\<void\>

杀死应用所在的进程。使用Promise异步回调。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
    onBackground() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.killAllProcesses();
    }
}
```

## ApplicationContext.killAllProcesses

killAllProcesses(callback: AsyncCallback\<void\>)

杀死应用所在的进程。使用callback异步回调。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<void\>   | 是   | 回调函数。当杀死应用所在的进程成功，err为undefined，否则为错误对象。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
    onBackground() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.killAllProcesses(error => {
            if (error) {
                console.error(`killAllProcesses fail, error: ${JSON.stringify(error)}`);
            }
        });
    }
}
```
## ApplicationContext.setColorMode<sup>11+</sup>

setColorMode(colorMode: ConfigurationConstant.ColorMode): void

设置应用的颜色模式。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#configurationconstantcolormode) | 是   | 设置颜色模式，包括：深色模式、浅色模式、不设置（跟随系统）。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 401 | If the input parameter is not valid parameter. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import ConfigurationConstant from '@ohos.app.ability.ConfigurationConstant';

export default class MyAbility extends UIAbility {
  onCreate() {
    let applicationContext = this.context.getApplicationContext();
    applicationContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);
  }
}
```

## ApplicationContext.setLanguage<sup>11+</sup>

setLanguage(language: string): void

设置应用的语言。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| language | string | 是   | 设置语言，当前支持的语言列表可以通过@ohos.i18n.d.ts中的static getSystemLanguage(): Array<string>;获取。  |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
  onCreate() {
    let applicationContext = this.context.getApplicationContext();
    applicationContext.setLanguage('zh-cn');
  }
}
```

## ApplicationContext.clearUpApplicationData<sup>11+</sup>

clearUpApplicationData(): Promise\<void\>

清理应用本身的数据，同时撤销应用向用户申请的权限。使用Promise异步回调。

> **说明：**
>
> 该接口会停止应用进程，应用进程停止后，后续的所有回调都不会再触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
    onBackground() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.clearUpApplicationData();
    }
}
```

## ApplicationContext.clearUpApplicationData<sup>11+</sup>

clearUpApplicationData(callback: AsyncCallback\<void\>): void

清理应用本身的数据，同时撤销应用向用户申请的权限。使用callback异步回调。

> **说明：**
>
> 该接口会停止应用进程，应用进程停止后，后续的所有回调都不会再触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调方法。清理应用本身的数据成功时，error为undefined，否则返回错误对象。  |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
export default class MyAbility extends UIAbility {
    onBackground() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.clearUpApplicationData(error => {
            if (error) {
                console.error(`clearUpApplicationData fail, error: ${JSON.stringify(error)}`);
            }
        });
    }
}
```

## ApplicationContext.restartApp<sup>12+</sup>

restartApp(want: Want): void

应用重启并拉起自身指定UIAbility。重启时不会收到onDestroy回调。

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的UIAbility的信息，Bundle名称不做校验。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000050 | Internal error. |
| 16000063 | The target to restart does not belong to the current app or is not a UIAbility. |
| 16000064 | Restart too frequently. Try again at least 10s later. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    let want : Want = {
      bundleName: 'com.example.myapp',
      abilityName: 'EntryAbility'
    };
    try {
      applicationContext.restartApp(want);
    } catch (error) {
      console.error(`restartApp fail, error: ${JSON.stringify(error)}`);
    }
  }
}
```
