# ApplicationContext (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

ApplicationContext模块继承自[Context](js-apis-inner-application-context.md)，提供开发者应用级别的上下文的能力，包括提供注册及取消注册应用内组件生命周期的监听接口。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[ApplicationContext](js-apis-inner-application-applicationContext.md)。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## 使用说明

在使用ApplicationContext的功能前，需要通过context的实例获取。

## ApplicationContext.preloadUIExtensionAbility<sup>12+</sup>

preloadUIExtensionAbility(want: Want): Promise\<void\>

预加载指定UIExtensionAbility实例。使用Promise异步回调。

被预加载的UIExtensionAbility实例会执行到UIExtensionAbility的onCreate生命周期，然后等待被当前应用正式加载。

支持多次预加载UIExtensionAbility实例，每次正式加载时，会使一个预加载的UIExtensionAbility实例从onCreate继续完成UIExtensionAbility的生命周期。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.PRELOAD_UI_EXTENSION_ABILITY

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数**：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | 是 | 预加载UIExtensionAbility的want信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201     | The application does not have permission to call the interface. |
| 202     | The application is not system-app, can not use system-api. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    // 构造预加载UIExtensionAbility的want参数
    let want: Want = {
      bundleName: 'com.ohos.uiextensionprovider',
      abilityName: 'UIExtensionProvider',
      moduleName: 'entry',
      parameters: {
        // 与UIExtensionAbility在module.json5中"type"字段配置一致
        'ability.want.params.uiExtensionType': 'sys/commonUI'
      }
    };
    try {
      // 获取ApplicationContext实例
      let applicationContext = this.context.getApplicationContext();
      // 预加载UIExtensionAbility
      applicationContext.preloadUIExtensionAbility(want)
        .then(() => {
          // 预加载成功处理
          console.info('preloadUIExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // 预加载失败处理
          console.error('preloadUIExtensionAbility failed');
        });
    } catch (err) {
      // 处理入参错误异常
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`preloadUIExtensionAbility failed. code: ${code}, msg: ${message}`);
    }
  }
}
```
## ApplicationContext.registerAbilityLifecycleCallback<sup>(deprecated)</sup>

registerAbilityLifecycleCallback(abilityLifecycleCallback: AbilityLifecycleCallback): number

注册监听应用内UIAbility的生命周期。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[ApplicationContext.on('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextonabilitylifecycle)替代。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| abilityLifecycleCallback | [AbilityLifecycleCallback](js-apis-app-ability-abilityLifecycleCallback.md) | 是   | UIAbility生命周期变化时触发的回调方法。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 返回此次注册的callbackID，该ID用于在[ApplicationContext.unregisterAbilityLifecycleCallback](#applicationcontextunregisterabilitylifecyclecallbackdeprecated)方法中取消注册对应的callback。 |

**示例：**

```ts
import { UIAbility, AbilityLifecycleCallback } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let lifecycleId: number;

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.info('MyAbility onCreate');
    let AbilityLifecycleCallback: AbilityLifecycleCallback = {
      onAbilityCreate(ability) {
        console.info(`AbilityLifecycleCallback onAbilityCreate ability: ${ability}`);
      },
      onWindowStageCreate(ability, windowStage) {
        console.info(`AbilityLifecycleCallback onWindowStageCreate ability: ${ability}`);
        console.info(`AbilityLifecycleCallback onWindowStageCreate windowStage: ${windowStage}`);
      },
      onWindowStageActive(ability, windowStage) {
        console.info(`AbilityLifecycleCallback onWindowStageActive ability: ${ability}`);
        console.info(`AbilityLifecycleCallback onWindowStageActive windowStage: ${windowStage}`);
      },
      onWindowStageInactive(ability, windowStage) {
        console.info(`AbilityLifecycleCallback onWindowStageInactive ability: ${ability}`);
        console.info(`AbilityLifecycleCallback onWindowStageInactive windowStage: ${windowStage}`);
      },
      onWindowStageDestroy(ability, windowStage) {
        console.info(`AbilityLifecycleCallback onWindowStageDestroy ability: ${ability}`);
        console.info(`AbilityLifecycleCallback onWindowStageDestroy windowStage: ${windowStage}`);
      },
      onAbilityDestroy(ability) {
        console.info(`AbilityLifecycleCallback onAbilityDestroy ability: ${ability}`);
      },
      onAbilityForeground(ability) {
        console.info(`AbilityLifecycleCallback onAbilityForeground ability: ${ability}`);
      },
      onAbilityBackground(ability) {
        console.info(`AbilityLifecycleCallback onAbilityBackground ability: ${ability}`);
      },
      onAbilityContinue(ability) {
        console.info(`AbilityLifecycleCallback onAbilityContinue ability: ${ability}`);
      }
    }
    // 1.通过context属性获取applicationContext
    // 获取ApplicationContext实例
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2.通过applicationContext注册监听应用内生命周期
      lifecycleId = applicationContext.registerAbilityLifecycleCallback(AbilityLifecycleCallback);
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error msg: ${(paramError as BusinessError).message}`);
    }
    console.info(`registerAbilityLifecycleCallback lifecycleId: ${lifecycleId}`);
  }
}
```

## ApplicationContext.unregisterAbilityLifecycleCallback<sup>(deprecated)</sup>

unregisterAbilityLifecycleCallback(callbackId: number, callback: AsyncCallback\<void>): void

取消监听应用内UIAbility的生命周期。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[ApplicationContext.off('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextoffabilitylifecycle)替代。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callbackId    | number   | 是   | 通过[ApplicationContext.registerAbilityLifecycleCallback](#applicationcontextregisterabilitylifecyclecallbackdeprecated)接口注册监听应用内UIAbility的生命周期时返回的ID。 |
| callback | AsyncCallback\<void> | 是   | 回调方法。当取消监听应用内生命周期成功，err为undefined，否则为错误对象。   |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let lifecycleId: number;

export default class EntryAbility extends UIAbility {
  onDestroy() {
    // 获取ApplicationContext实例
    let applicationContext = this.context.getApplicationContext();
    console.info(`stage applicationContext: ${applicationContext}`);
    try {
      applicationContext.unregisterAbilityLifecycleCallback(lifecycleId, (error, data) => {
        if (error) {
          console.error(`unregisterAbilityLifecycleCallback fail, err: ${JSON.stringify(error)}`);
        } else {
          console.info(`unregisterAbilityLifecycleCallback success, data: ${JSON.stringify(data)}`);
        }
      });
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error message: ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.unregisterAbilityLifecycleCallback<sup>(deprecated)</sup>

unregisterAbilityLifecycleCallback(callbackId: number): Promise\<void>

取消监听应用内UIAbility的生命周期。使用Promise异步回调。仅支持主线程调用。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[ApplicationContext.off('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextoffabilitylifecycle)替代。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callbackId    | number   | 是   | 通过[ApplicationContext.registerAbilityLifecycleCallback](#applicationcontextregisterabilitylifecyclecallbackdeprecated)接口注册监听应用内UIAbility的生命周期时返回的ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象，无返回结果。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let lifecycleId: number;

export default class MyAbility extends UIAbility {
  onDestroy() {
    // 获取ApplicationContext实例
    let applicationContext = this.context.getApplicationContext();
    console.info(`stage applicationContext: ${applicationContext}`);
    try {
      applicationContext.unregisterAbilityLifecycleCallback(lifecycleId);
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error msg: ${(paramError as BusinessError).message}`);
    }
  }
}
```
## ApplicationContext.registerEnvironmentCallback<sup>(deprecated)</sup>

registerEnvironmentCallback(environmentCallback: EnvironmentCallback): number

注册对系统环境变化的监听。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> - 使用[onConfigurationUpdate](../apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)也可以实现对系统环境变量的监听。相较于Ability的[onConfigurationUpdate](../apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)接口，当前接口的使用场景更加灵活，不仅可以在应用组件中使用，还可以在页面中使用，但是支持订阅的环境变量与Ability的[onConfigurationUpdate](../apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)接口存在差异，如不支持订阅direction、screenDensity、displayId，详见[Configuration](../apis-ability-kit/js-apis-app-ability-configuration.md#configuration)中各个环境变量的说明。
> - 当前接口在实际触发时存在一定限制。例如如果开发者通过[setLanguage](../apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetlanguage11)接口设置应用的语言，即便系统语言发生变化，系统也不再触发当前接口的[environmentCallback](js-apis-app-ability-environmentCallback.md)回调。详见[使用场景](../../application-models/subscribe-system-environment-variable-changes.md#使用场景)。
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[ApplicationContext.on('environment')](js-apis-inner-application-applicationContext.md#applicationcontextonenvironment)替代。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| environmentCallback | [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) | 是   | 系统环境变化时触发的回调方法。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 返回此次注册的callbackID，该ID用于在[ApplicationContext.unregisterEnvironmentCallback](#applicationcontextunregisterenvironmentcallbackdeprecated)方法中取消注册对应的callback。 |

**示例：**

```ts
import { UIAbility, EnvironmentCallback } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let callbackId: number;

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.info('MyAbility onCreate')
    let environmentCallback: EnvironmentCallback = {
      onConfigurationUpdated(config) {
        console.info(`onConfigurationUpdated config: ${JSON.stringify(config)}`);
      },
      onMemoryLevel(level) {
        console.info(`onMemoryLevel level: ${level}`);
      }
    };
    // 1.获取applicationContext
    // 获取ApplicationContext实例
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2.通过applicationContext注册监听系统环境变化
      callbackId = applicationContext.registerEnvironmentCallback(environmentCallback);
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error msg: ${(paramError as BusinessError).message}`);
    }
    console.info(`registerEnvironmentCallback callbackId: ${callbackId}`);
  }
}
```

## ApplicationContext.unregisterEnvironmentCallback<sup>(deprecated)</sup>

unregisterEnvironmentCallback(callbackId: number, envcallback: AsyncCallback\<void>): void

取消对系统环境变化的监听。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[ApplicationContext.off('environment')](js-apis-inner-application-applicationContext.md#applicationcontextoffenvironment)替代。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名         | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callbackId    | number   | 是   | 通过[ApplicationContext.registerEnvironmentCallback](#applicationcontextregisterenvironmentcallbackdeprecated)接口注册监听系统环境变化时返回的ID。 |
| envcallback | AsyncCallback\<void> | 是   | 回调方法。当取消对系统环境变化的监听成功，err为undefined，否则为错误对象。   |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let callbackId: number;

export default class EntryAbility extends UIAbility {
  onDestroy() {
    // 获取ApplicationContext实例
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.unregisterEnvironmentCallback(callbackId, (error, data) => {
        if (error) {
          console.error(`unregisterEnvironmentCallback fail, err: ${JSON.stringify(error)}`);
        } else {
          console.info(`unregisterEnvironmentCallback success, data: ${JSON.stringify(data)}`);
        }
      });
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error msg: ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.unregisterEnvironmentCallback<sup>(deprecated)</sup>

unregisterEnvironmentCallback(callbackId: number): Promise\<void\>

取消对系统环境变化的监听。使用Promise异步回调。仅支持主线程调用。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[ApplicationContext.off('environment')](js-apis-inner-application-applicationContext.md#applicationcontextoffenvironment)替代。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名         | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callbackId    | number   | 是   | 通过[ApplicationContext.registerEnvironmentCallback](#applicationcontextregisterenvironmentcallbackdeprecated)接口注册监听系统环境变化时返回的ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象，无返回结果。 |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let callbackId: number;

export default class MyAbility extends UIAbility {
  onDestroy() {
    // 获取ApplicationContext实例
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.unregisterEnvironmentCallback(callbackId);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.getProcessRunningInformation<sup>(deprecated)</sup>

getProcessRunningInformation(): Promise\<Array\<ProcessInformation>>

获取运行中的进程信息。使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[ApplicationContext.getRunningProcessInformation](js-apis-inner-application-applicationContext.md#applicationcontextgetrunningprocessinformation)替代。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Promise对象，返回接口运行结果及有关运行进程的信息，可进行错误处理或其他自定义处理。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyAbility extends UIAbility {
  onForeground() {
    // 获取ApplicationContext实例
    let applicationContext = this.context.getApplicationContext();
    applicationContext.getProcessRunningInformation().then((data) => {
      console.info(`The process running information is: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
      console.error(`error code: ${error.code}, error msg: ${error.message}`);
    });
  }
}
```

## ApplicationContext.getProcessRunningInformation<sup>(deprecated)</sup>

getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void

获取运行中的进程信息。使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 10开始废弃，建议使用[ApplicationContext.getRunningProcessInformation](js-apis-inner-application-applicationContext.md#applicationcontextgetrunningprocessinformation)替代。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**系统接口**：此接口为系统接口。

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>>   | 是   | 回调函数，返回有关运行进程的信息。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onForeground() {
    // 获取ApplicationContext实例
    let applicationContext = this.context.getApplicationContext();
    applicationContext.getProcessRunningInformation((err, data) => {
      if (err) {
        console.error(`getProcessRunningInformation failed, err: ${JSON.stringify(err)}`);
      } else {
        console.info(`The process running information is: ${JSON.stringify(data)}`);
      }
    })
  }
}
```