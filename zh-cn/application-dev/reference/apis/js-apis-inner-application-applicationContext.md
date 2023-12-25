# ApplicationContext

ApplicationContext模块提供开发者应用级别的的上下文的能力，包括提供注册及取消注册应用内组件生命周期的监听接口。

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

on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback): **number**

注册监听应用内生命周期

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

off(type: 'abilityLifecycle', callbackId: **number**,  callback: AsyncCallback\<void>): void

取消监听应用内生命周期

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听应用内生命周期的ID。 |
| callback | AsyncCallback\<void> | 是   | 回调方法。                   |

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

取消监听应用内生命周期

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听应用内生命周期的ID。 |

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

on(type: 'environment', callback: EnvironmentCallback): **number**

注册对系统环境变化的监听。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | 'environment' | 是   | 监听事件的类型。 |
| callback | [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) | 是   | 回调方法，返回注册监听事件的ID。 |

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| number | 返回的此次注册监听系统环境变化的ID（每次注册该ID会自增+1，当超过监听上限数量2^63-1时，返回-1）。|

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
                console.log('onMemoryLevel level: ${level}');
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

off(type: 'environment', callbackId: **number**,  callback: AsyncCallback\<void>): void

取消对系统环境变化的监听。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听系统环境变化的ID。   |
| callback | AsyncCallback\<void> | 是   | 回调方法。                  |

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

off(type: 'environment', callbackId: **number**): Prominse\<void\>

取消对系统环境变化的监听。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听系统环境变化的ID。   |

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

注册对当前应用前后台变化的监听。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明             |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| type     | string                                     | 是   | 监听事件类型，必须为'applicationStateChange'。 |
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | 是   | 对于该事件监听的回调方法，可以对应用从后台切换到前台，以及前台切换到后台分别定义回调。       |

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

## ApplicationContext.off(type: 'applicationStateChange')<sup>10+</sup>

off(type: 'applicationStateChange', callback?: ApplicationStateChangeCallback): void

取消当前应用注册的前后台变化的全部监听。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| type   | string | 是   | 取消监听事件的类型,必须为'applicationStateChange'。 |
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | 否   | 对于该事件监听的回调方法，可以对应用从后台切换到前台，以及前台切换到后台分别定义回调。       |

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

获取有关运行进程的信息。以Promise形式返回。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | 以Promise方式返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

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

获取有关运行进程的信息。以Callback形式返回。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>>   | 是   | 获取有关运行进程的信息的回调。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

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

杀死应用所在的进程。以Promise形式返回。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | 以Promise方式返回杀死应用所在的进程结果。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

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

killAllProcesses(callback: AsyncCallback\<void\>): void

杀死应用所在的进程。以Callback形式返回。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<void\>   | 是   | 以callback方式返回杀死应用所在的进程结果。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

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

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| colorMode | [ConfigurationConstant.ColorMode](../apis/js-apis-app-ability-configurationConstant.md) | 是   | 设置颜色模式，包括：深色模式、浅色模式、不设置（跟随系统） |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 401 | If the input parameter is not valid parameter. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

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

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| language | string | 是   | 设置语言，当前支持的语言列表可以通过@ohos.i18n.d.ts中的static getSystemLanguage(): Array<string>;获取  |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 401 | If the input parameter is not valid parameter. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

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

清理应用本身的数据。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | 无返回结果的Promise对象。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

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

清理应用本身的数据。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调方法。清理应用本身的数据成功时，err为undefined，否则返回错误对象。  |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

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

## ApplicationContext.on<sup>11+</sup>

on(type: 'abilityAutoStartup', callback: AutoStartupCallback): void

应用注册对自身开机自启动状态变化的监听。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                                            |
| -------- | ------------------- | ---- | ----------------------------------------------- |
| type     | string              | 是   | 注册监听事件的类型,必须为"abilityAutoStartup"。 |
| callback | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback.md) | 是   | 注册监听应用开机自启动状态变化的回调对象。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.on('abilityAutoStartup', {
        onAutoStartupOn(data) {
          console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
        },
        onAutoStartupOff(data) {
          console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
        }
      });
    } catch (err) {
      console.info('===> autostartupmanager on throw err: ' + JSON.stringify(err));
    }
  }
}
```

## ApplicationContext.off<sup>11+</sup>

off(type: 'abilityAutoStartup', callback?: AutoStartupCallback): void

应用注销对自身开机自启动状态变化的监听。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                                            |
| -------- | ------------------- | ---- | ----------------------------------------------- |
| type     | string              | 是   | 注册监听事件的类型,必须为"abilityAutoStartup"。 |
| callback | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback.md) | 否   | 注销监听应用开机自启动状态变化的回调对象。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.off('abilityAutoStartup', {
        onAutoStartupOn(data) {
          console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
        },
        onAutoStartupOff(data) {
          console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
        }
      });
    } catch (err) {
      console.info('===> autostartupmanager off throw err: ' + JSON.stringify(err));
    }
  }
}
```

## ApplicationContext.setAutoStartup<sup>11+</sup>

setAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

应用设置为开机自启动。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                       |
| -------- | ------------------- | ---- | -------------------------- |
| info     | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md)     | 是   | 设置开机自启动的应用组件信息。 |
| callback | AsyncCallback\<void\> | 是   | 回调函数。当设置为开机自启动成功，err为undefined，否则为错误对象。   |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.setAutoStartup({
        bundleName: 'com.example.autostartupapp',
        abilityName: 'EntryAbility'
      }, (err, data) => {
        console.info('====> err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
      });
    } catch (err) {
      console.info('===> autostartupmanager setAutoStartup throw err: ' + JSON.stringify(err));
    }
  }
}
```

## ApplicationContext.setAutoStartup<sup>11+</sup>

setAutoStartup(info: AutoStartupInfo): Promise\<void\>

应用设置为开机自启动。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型            | 必填 | 说明                       |
| ------ | --------------- | ---- | -------------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md) | 是   | 设置开机自启动的应用组件信息。 |

**返回值：**

| 类型            | 说明                                        |
| --------------- | ------------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.setAutoStartup({
        bundleName: 'com.example.autostartupapp',
        abilityName: 'EntryAbility'
      }).then((data) => {
        console.info('====> setAutoStartup data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
        console.info('====> setAutoStartup err: ' + JSON.stringify(err));
      });
    } catch (err) {
      console.info('===> autostartupmanager setAutoStartup throw err: ' + JSON.stringify(err));
    }
  }
}
```

## ApplicationContext.cancelAutoStartup<sup>11+</sup>

cancelAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

应用取消开机自启动。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                       |
| -------- | ------------------- | ---- | -------------------------- |
| info     | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md)     | 是   | 取消开机自启动的应用组件信息。 |
| callback | AsyncCallback\<void\> | 是   | 回调函数。当取消开机自启动成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.cancelAutoStartup({
        bundleName: 'com.example.autostartupapp',
        abilityName: 'EntryAbility'
      }, (err, data) => {
        console.info('====> err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
      });
    } catch (err) {
      console.info('===> autostartupmanager cancelAutoStartup throw err: ' + JSON.stringify(err));
    }
  }
}
```

## ApplicationContext.cancelAutoStartup<sup>11+</sup>

cancelAutoStartup(info: AutoStartupInfo): Promise\<void\>

应用取消开机自启动。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型            | 必填 | 说明                       |
| ------ | --------------- | ---- | -------------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md) | 是   | 取消开机自启动的应用组件信息。 |

**返回值：**

| 类型            | 说明                                        |
| --------------- | ------------------------------------------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.cancelAutoStartup({
        bundleName: 'com.example.autostartupapp',
        abilityName: 'EntryAbility'
      }).then((data) => {
          console.info('====> cancelAutoStartup data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
          console.info('====> cancelAutoStartup err: ' + JSON.stringify(err));
      });
    } catch (err) {
      console.info('===> autostartupmanager cancelAutoStartup throw err: ' + JSON.stringify(err));
    }
  }
}
```

## ApplicationContext.isAutoStartup<sup>11+</sup>

isAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<boolean\>): void

应用查询自身组件是否开机自启动。使用callback异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                       |
| -------- | ---------------------- | ---- | -------------------------- |
| info     | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md)        | 是   | 查询是否开机启动的应用自身组件的信息。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。返回true表示查询的应用组件是开机自启动；返回false表示查询的应用组件不是开机自启动。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.isAutoStartup({
        bundleName: 'com.example.autostartupapp',
        abilityName: 'EntryAbility'
      }, (err, data) => {
        console.info('====> err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
      });
    } catch (err) {
      console.info('===> autostartupmanager isAutoStartup throw err: ' + JSON.stringify(err));
    }
  }
}
```

## ApplicationContext.isAutoStartup<sup>11+</sup>

isAutoStartup(info: AutoStartupInfo): Promise\<boolean\>

应用查询自身组件是否开机自启动。使用Promise异步回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型            | 必填 | 说明                       |
| ------ | --------------- | ---- | -------------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md) | 是   | 查询是否开机启动的应用自身组件的信息。 |

**返回值：**

| 类型             | 说明                                        |
| ---------------- | ------------------------------------------- |
| Promise\<boolean\> | Promise对象。返回true表示查询的应用组件是开机自启动；返回false表示查询的应用组件不是开机自启动。 |

**示例：**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.isAutoStartup({
        bundleName: 'com.example.autostartupapp',
        abilityName: 'EntryAbility'
      }).then((data) => {
        console.info('====> isAutoStartup data: ' + JSON.stringify(data));
      }).catch((err: BusinessError) => {
        console.info('====> isAutoStartup err: ' + JSON.stringify(err));
      });
    } catch (err) {
      console.info('===> autostartupmanager isAutoStartup throw err: ' + JSON.stringify(err));
    }
  }
}
```

