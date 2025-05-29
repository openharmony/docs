# ApplicationContext

ApplicationContext模块继承自[Context](js-apis-inner-application-context.md)，提供开发者应用级别的上下文的能力，包括提供注册及取消注册应用内组件生命周期的监听接口。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## 使用说明

在使用ApplicationContext的功能前，需要通过Context的实例获取。

## ApplicationContext.on('abilityLifecycle')

on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback): number

注册监听应用内生命周期。使用callback异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { UIAbility, AbilityLifecycleCallback } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
    try {
      // 2.通过applicationContext注册监听应用内生命周期
      lifecycleId = applicationContext.on('abilityLifecycle', AbilityLifecycleCallback);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.log(`registerAbilityLifecycleCallback lifecycleId: ${lifecycleId}`);
  }
}
```

## ApplicationContext.off('abilityLifecycle')

off(type: 'abilityLifecycle', callbackId: number,  callback: AsyncCallback\<void>): void

取消监听应用内生命周期。使用callback异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听应用内生命周期的ID。 |
| callback | AsyncCallback\<void> | 是   | 回调方法。当取消监听应用内生命周期成功，err为undefined，否则为错误对象。   |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let lifecycleId: number;

export default class EntryAbility extends UIAbility {
  onDestroy() {
    let applicationContext = this.context.getApplicationContext();
    console.log(`stage applicationContext: ${applicationContext}`);
    try {
      applicationContext.off('abilityLifecycle', lifecycleId, (error, data) => {
        if (error) {
          console.error(`unregisterAbilityLifecycleCallback fail, err: ${JSON.stringify(error)}`);
        } else {
          console.log(`unregisterAbilityLifecycleCallback success, data: ${JSON.stringify(data)}`);
        }
      });
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.off('abilityLifecycle')

off(type: 'abilityLifecycle', callbackId: number): Promise\<void>

取消监听应用内生命周期。使用Promise异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let lifecycleId: number;

export default class MyAbility extends UIAbility {
  onDestroy() {
    let applicationContext = this.context.getApplicationContext();
    console.log(`stage applicationContext: ${applicationContext}`);
    try {
      applicationContext.off('abilityLifecycle', lifecycleId);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.on('environment')

on(type: 'environment', callback: EnvironmentCallback): number

注册对系统环境变化的监听。使用callback异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { UIAbility, EnvironmentCallback } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let callbackId: number;

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate')
    let environmentCallback: EnvironmentCallback = {
      onConfigurationUpdated(config) {
        console.log(`onConfigurationUpdated config: ${JSON.stringify(config)}`);
      },
      onMemoryLevel(level) {
        console.log(`onMemoryLevel level: ${level}`);
      }
    };
    // 1.获取applicationContext
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2.通过applicationContext注册监听系统环境变化
      callbackId = applicationContext.on('environment', environmentCallback);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.log(`registerEnvironmentCallback callbackId: ${callbackId}`);
  }
}
```

## ApplicationContext.off('environment')

off(type: 'environment', callbackId: number,  callback: AsyncCallback\<void>): void

取消对系统环境变化的监听。使用callback异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | 是   | 取消监听事件的类型。 |
| callbackId    | number   | 是   | 注册监听系统环境变化的ID。   |
| callback | AsyncCallback\<void> | 是   | 回调方法。当取消对系统环境变化的监听成功，err为undefined，否则为错误对象。   |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let callbackId: number;

export default class EntryAbility extends UIAbility {
  onDestroy() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.off('environment', callbackId, (error, data) => {
        if (error) {
          console.error(`unregisterEnvironmentCallback fail, err: ${JSON.stringify(error)}`);
        } else {
          console.log(`unregisterEnvironmentCallback success, data: ${JSON.stringify(data)}`);
        }
      });
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.off('environment')

off(type: 'environment', callbackId: number): Promise\<void\>

取消对系统环境变化的监听。使用Promise异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

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

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let callbackId: number;

export default class MyAbility extends UIAbility {
  onDestroy() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.off('environment', callbackId);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.on('applicationStateChange')<sup>10+</sup>

on(type: 'applicationStateChange', callback: ApplicationStateChangeCallback): void

注册对当前应用前后台变化的监听。使用callback异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明             |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| type     | 'applicationStateChange'                                     | 是   | 监听事件类型。 |
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | 是   | 回调函数。可以对应用从后台切换到前台，以及前台切换到后台分别定义回调。       |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

```ts
import { UIAbility, ApplicationStateChangeCallback } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
    try {
      // 2.通过applicationContext注册应用前后台状态监听
      applicationContext.on('applicationStateChange', applicationStateChangeCallback);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.log('Register applicationStateChangeCallback');
  }
}
```

## ApplicationContext.off('applicationStateChange')<sup>10+</sup>

off(type: 'applicationStateChange', callback?: ApplicationStateChangeCallback): void

取消对应用前后台切换事件的监听。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> 使用该接口前，需要先使用[ApplicationContext.on('applicationStateChange')](#applicationcontextonapplicationstatechange10)注册事件监听。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| type   | 'applicationStateChange' | 是   | 取消监听事件的类型。 |
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | 否   | 回调函数。取值可以为使用ApplicationContext.on('applicationStateChange')方法定义的callback回调，也可以为空。<br/>-&nbsp;如果传入已定义的回调，则取消该监听。 <br/>-&nbsp;如果未传入参数，则取消当前应用对所有前后台切换事件的监听。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**示例：**

假定已使用[ApplicationContext.on('applicationStateChange')](#applicationcontextonapplicationstatechange10)方法注册名为applicationStateChangeCallback回调，下面示例展示如何取消对应的事件监听。

```ts
import { UIAbility, ApplicationStateChangeCallback } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let applicationStateChangeCallback: ApplicationStateChangeCallback = {
  onApplicationForeground() {
    console.info('applicationStateChangeCallback onApplicationForeground');
  },
  onApplicationBackground() {
    console.info('applicationStateChangeCallback onApplicationBackground');
  }
};

export default class MyAbility extends UIAbility {
  onDestroy() {
    let applicationContext = this.context.getApplicationContext();
    try {
      // 本例中的callback字段取值为ApplicationStateChangeCallback，需要替换为实际值。
      // 如果callback字段不传入参数，则取消当前应用对所有前后台切换事件的监听。
      applicationContext.off('applicationStateChange', applicationStateChangeCallback);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.getRunningProcessInformation

getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>

获取有关运行进程的信息。使用Promise异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Promise对象，返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>>   | 是   | 回调函数，返回有关运行进程的信息。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

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

终止应用的所有进程，进程退出时不会正常走完应用生命周期。使用Promise异步回调。仅支持主线程调用。

> **说明：**
>
> 该接口用于应用异常场景中强制退出应用。如需正常退出应用，可以使用[terminateSelf()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself-1)接口。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    applicationContext.killAllProcesses();
  }
}
```

## ApplicationContext.killAllProcesses<sup>14+</sup>

killAllProcesses(clearPageStack: boolean): Promise\<void\>

终止应用的所有进程，进程退出时不会正常走完应用生命周期。使用Promise异步回调。仅支持主线程调用。

> **说明：**
>
> 该接口用于应用异常场景中强制退出应用。如需正常退出应用，可以使用[terminateSelf()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself-1)接口。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| clearPageStack | boolean | 是 | 表示是否清除页面堆栈。true表示清除，false表示不清除。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | If the input parameter is not valid parameter. |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

let isClearPageStack = false;

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    applicationContext.killAllProcesses(isClearPageStack);
  }
}
```

## ApplicationContext.killAllProcesses

killAllProcesses(callback: AsyncCallback\<void\>)

终止应用的所有进程，进程退出时不会正常走完应用生命周期。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> 该接口用于应用异常场景中强制退出应用。如需正常退出应用，可以使用[terminateSelf()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateself-1)接口。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<void\>   | 是   | 回调函数。当终止应用所在的进程成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

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

设置应用的颜色模式。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#colormode) | 是   | 设置颜色模式，包括：深色模式、浅色模式、不设置（跟随系统）。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { UIAbility, ConfigurationConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onCreate() {
    let applicationContext = this.context.getApplicationContext();
    applicationContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);
  }
}
```

## ApplicationContext.setLanguage<sup>11+</sup>

setLanguage(language: string): void

设置应用的语言。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| language | string | 是   | 设置语言，当前支持的语言列表可以通过[getSystemLanguages()](../apis-localization-kit/js-apis-i18n.md#getsystemlanguages9)获取。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |


**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onCreate() {
    let applicationContext = this.context.getApplicationContext();
    applicationContext.setLanguage('zh-cn');
  }
}
```

## ApplicationContext.clearUpApplicationData<sup>11+</sup>

clearUpApplicationData(): Promise\<void\>

清理应用本身的数据，同时撤销应用向用户申请的权限。使用Promise异步回调。仅支持主线程调用。

> **说明：**
>
> 该接口会停止应用进程，应用进程停止后，后续的所有回调都不会再触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    applicationContext.clearUpApplicationData();
  }
}
```

## ApplicationContext.clearUpApplicationData<sup>11+</sup>

clearUpApplicationData(callback: AsyncCallback\<void\>): void

清理应用本身的数据，同时撤销应用向用户申请的权限。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> 该接口会停止应用进程，应用进程停止后，后续的所有回调都不会再触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调方法。清理应用本身的数据成功时，error为undefined，否则返回错误对象。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

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

应用重启并拉起自身指定UIAbility。重启时不会收到onDestroy回调。仅支持主线程调用，且待重启的应用需要处于获焦状态。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的UIAbility的信息，Bundle名称不做校验。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000063 | The target to restart does not belong to the current application or is not a UIAbility. |
| 16000064 | Restart too frequently. Try again at least 3s later. |

**示例：**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onForeground() {
    let applicationContext = this.context.getApplicationContext();
    let want: Want = {
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

## ApplicationContext.getCurrentAppCloneIndex<sup>12+</sup>

getCurrentAppCloneIndex(): number

获取当前应用的分身索引。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 当前应用的分身索引。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000071 | App clone is not supported. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    try {
      let appCloneIndex = applicationContext.getCurrentAppCloneIndex();
    } catch (error) {
      console.error(`getCurrentAppCloneIndex fail, error: ${JSON.stringify(error)}`);
    }
  }
}
```

## ApplicationContext.setFont<sup>12+</sup>

setFont(font: string): void

设置应用的字体类型。仅支持主线程调用。

> **说明：**
>
> 当页面窗口创建完成后，才能调用该接口，即需要在[onWindowStageCreate()](js-apis-app-ability-uiAbility.md#uiabilityonwindowstagecreate)生命周期之后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| font | string | 是   | 设置字体类型，字体可以通过[UIContext.registerFont](../apis-arkui/js-apis-arkui-UIContext.md#registerfont)方法进行注册使用。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |


**示例：**

```ts
import { font } from '@kit.ArkUI';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  aboutToAppear() {
    this.getUIContext().getFont().registerFont({
      familyName: 'fontName',
      familySrc: $rawfile('font/medium.ttf')
    })

    this.context.getApplicationContext().setFont("fontName");
  }

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(50)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## ApplicationContext.setSupportedProcessCache<sup>12+</sup>

setSupportedProcessCache(isSupported : boolean): void

应用设置自身是否支持缓存后快速启动。仅支持主线程调用。

> **说明：**
>
> - 该接口仅表示应用自身是否为缓存后快速启动做好了准备，还需综合其他条件来判断最终是否为应用启用快速启动。
> - 该接口设置的缓存支持状态对单个应用进程实例生效，不同进程实例互不影响。应用进程实例销毁后，已设置的状态不保留，可以重新设置。
> - 如果需要支持缓存后快速启动，则需要在同一进程中所有[AbilityStage](../../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)的`onCreate()`生命周期中调用该接口、且入参均配置为“true”。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| isSupported | boolean | 是 | 表示应用是否支持缓存后快速启动。true表示支持，false表示不支持。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)、[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 801      | Capability not supported.|
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { AbilityStage, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyAbilityStage extends AbilityStage {
  onCreate() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.setSupportedProcessCache(true);
    } catch (error) {
      let code = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`setSupportedProcessCache fail, code: ${code}, msg: ${message}`);
    }
  }
}
```


## ApplicationContext.setFontSizeScale<sup>13+</sup>

setFontSizeScale(fontSizeScale: number): void

设置应用字体大小缩放比例。仅支持主线程调用。

**原子化服务API**：从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| fontSizeScale | number | 是   | 表示字体缩放比例，取值为非负数。当应用字体[跟随系统](../../quick-start/app-configuration-file.md#configuration标签)且该字段取值超过[fontSizeMaxScale](../../quick-start/app-configuration-file.md#configuration标签)取值时，实际生效值为[fontSizeMaxScale](../../quick-start/app-configuration-file.md#configuration标签)取值。|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        return;
      }
      let applicationContext = this.context.getApplicationContext();
      applicationContext.setFontSizeScale(2);
    });
  }
}
```


## ApplicationContext.getCurrentInstanceKey<sup>14+</sup>

getCurrentInstanceKey(): string

获取当前应用多实例的唯一实例标识。仅支持主线程调用。

> **说明：**
>
> 当前仅支持2in1设备。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| string | 返回当前应用多实例的唯一实例标识。|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000078 | The multi-instance is not supported. |

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyAbilityStage extends AbilityStage {
  onCreate() {
    let applicationContext = this.context.getApplicationContext();
    let currentInstanceKey = '';
    try {
      currentInstanceKey = applicationContext.getCurrentInstanceKey();
    } catch (error) {
      let code = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`getCurrentInstanceKey fail, code: ${code}, msg: ${message}`);
    }
    console.log(`currentInstanceKey: ${currentInstanceKey}`);
  }
}
```

## ApplicationContext.getAllRunningInstanceKeys<sup>14+</sup>

getAllRunningInstanceKeys(): Promise\<Array\<string>>;

获取应用的所有多实例的唯一实例标识。使用Promise异步回调。仅支持主线程调用。

> **说明：**
>
> 当前仅支持2in1设备。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| Promise\<Array\<string>> | Promise对象，返回应用的所有多实例的唯一实例标识。|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000078 | The multi-instance is not supported. |

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyAbilityStage extends AbilityStage {
  onCreate() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.getAllRunningInstanceKeys();
    } catch (error) {
      let code = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`getAllRunningInstanceKeys fail, code: ${code}, msg: ${message}`);
    }
  }
}
```