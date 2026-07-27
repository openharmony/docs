# ApplicationContext (应用上下文)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

ApplicationContext作为应用上下文，继承自[Context](js-apis-inner-application-context.md)，提供了应用生命周期监听、进程管理、应用环境设置等应用级别的管控能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { common } from '@kit.AbilityKit';
```

## ApplicationContext.on('abilityLifecycle')

on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback): number

注册监听应用内UIAbility的生命周期。使用callback异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | string | 是   | 此类型表示应用内UIAbility的生命周期，固定为'abilityLifecycle'。 |
| callback | [AbilityLifecycleCallback](js-apis-app-ability-abilityLifecycleCallback.md) | 是   | UIAbility生命周期变化时触发的回调方法。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 返回此次注册的callbackID，该ID用于在[ApplicationContext.off('abilityLifecycle')](#applicationcontextoffabilitylifecycle)方法中取消注册对应的callback。 |

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
    console.info('MyAbility onCreate');
    let abilityLifecycleCallback: AbilityLifecycleCallback = {
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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2.通过applicationContext注册监听应用内生命周期
      lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error msg: ${(paramError as BusinessError).message}`);
    }
    console.info(`registerAbilityLifecycleCallback lifecycleId: ${lifecycleId}`);
  }
}
```

## ApplicationContext.off('abilityLifecycle')

off(type: 'abilityLifecycle', callbackId: number,  callback: AsyncCallback\<void>): void

取消监听应用内UIAbility的生命周期。使用callback异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | string | 是   | 此类型表示应用内UIAbility的生命周期，固定为'abilityLifecycle'。 |
| callbackId    | number   | 是   | 通过[ApplicationContext.on('abilityLifecycle')](#applicationcontextonabilitylifecycle)接口注册监听应用内UIAbility的生命周期时返回的ID。 |
| callback | AsyncCallback\<void> | 是   | 回调方法。当取消监听应用内UIAbility的生命周期成功，err为undefined，否则为错误对象。   |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    console.info(`stage applicationContext: ${applicationContext}`);
    try {
      // 取消监听应用内UIAbility生命周期
      applicationContext.off('abilityLifecycle', lifecycleId, (error, data) => {
        if (error) {
          console.error(`unregisterAbilityLifecycleCallback fail, err: ${JSON.stringify(error)}`);
        } else {
          console.info(`unregisterAbilityLifecycleCallback success, data: ${JSON.stringify(data)}`);
        }
      });
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error msg: ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.off('abilityLifecycle')

off(type: 'abilityLifecycle', callbackId: number): Promise\<void>

取消监听应用内UIAbility的生命周期。使用Promise异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | string | 是   | 此类型表示应用内UIAbility的生命周期，固定为'abilityLifecycle'。 |
| callbackId    | number   | 是   | 通过[ApplicationContext.on('abilityLifecycle')](#applicationcontextonabilitylifecycle)接口注册监听应用内UIAbility的生命周期时返回的ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象，无返回结果。 |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    console.info(`stage applicationContext: ${applicationContext}`);
    try {
      // 取消监听应用内UIAbility生命周期
      applicationContext.off('abilityLifecycle', lifecycleId);
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error msg: ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.on('environment')

on(type: 'environment', callback: EnvironmentCallback): number

注册对系统环境变化的监听。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> - 使用[onConfigurationUpdate](../apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)也可以实现对系统环境变量的监听。相较于Ability的[onConfigurationUpdate](../apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)接口，当前接口的使用场景更加灵活，不仅可以在应用组件中使用，还可以在页面中使用，但是支持订阅的环境变量与Ability的[onConfigurationUpdate](../apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate)接口存在差异，如不支持订阅direction、screenDensity、displayId，详见[Configuration](../apis-ability-kit/js-apis-app-ability-configuration.md#configuration)中各个环境变量的说明。
> - 当前接口在实际触发时存在一定限制。例如如果开发者通过[setLanguage](../apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetlanguage11)接口设置应用的语言，即便系统语言发生变化，系统也不再触发当前接口的[callback](js-apis-app-ability-environmentCallback.md)回调。详见[使用场景](../../application-models/subscribe-system-environment-variable-changes.md#使用场景)。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | string | 是   | 此类型表示系统环境变化，如系统深浅色发生变化，固定为'environment'。 |
| callback | [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) | 是   | 系统环境变化时触发的回调方法。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 返回此次注册的callbackID，该ID用于在[ApplicationContext.off('environment')](#applicationcontextoffenvironment)方法中取消注册对应的callback。 |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2.通过applicationContext注册监听系统环境变化
      callbackId = applicationContext.on('environment', environmentCallback);
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error msg: ${(paramError as BusinessError).message}`);
    }
    console.info(`registerEnvironmentCallback callbackId: ${callbackId}`);
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
| type | string | 是   | 此类型表示系统环境变化，如系统深浅色发生变化，固定为'environment'。 |
| callbackId    | number   | 是   | 通过[ApplicationContext.on('environment')](#applicationcontextonenvironment)接口注册监听系统环境变化时返回的ID。 |
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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 取消对系统环境变化的监听
      applicationContext.off('environment', callbackId, (error, data) => {
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

## ApplicationContext.off('environment')

off(type: 'environment', callbackId: number): Promise\<void\>

取消对系统环境变化的监听。使用Promise异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名         | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| type | string | 是   | 此类型表示系统环境变化，如系统深浅色发生变化，固定为'environment'。 |
| callbackId    | number   | 是   | 通过[ApplicationContext.on('environment')](#applicationcontextonenvironment)接口注册监听系统环境变化时返回的ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void> | Promise对象，无返回结果。 |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 取消对系统环境变化的监听
      applicationContext.off('environment', callbackId);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.on('applicationStateChange')<sup>10+</sup>

on(type: 'applicationStateChange', callback: ApplicationStateChangeCallback): void

注册对当前应用进程状态变化的监听。使用callback异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明             |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| type     | string                                   | 是   | 此类型表示当前应用进程状态变化，固定为'applicationStateChange'。 |
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | 是   | 当前应用进程状态变化时触发的回调方法。 |

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
    console.info('MyAbility onCreate');
    let applicationStateChangeCallback: ApplicationStateChangeCallback = {
      onApplicationForeground() {
        console.info('applicationStateChangeCallback onApplicationForeground');
      },
      onApplicationBackground() {
        console.info('applicationStateChangeCallback onApplicationBackground');
      }
    }

    // 1.获取applicationContext
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2.通过applicationContext注册当前应用进程状态监听
      applicationContext.on('applicationStateChange', applicationStateChangeCallback);
    } catch (paramError) {
      console.error(`error code: ${(paramError as BusinessError).code}, error msg: ${(paramError as BusinessError).message}`);
    }
    console.info('Register applicationStateChangeCallback');
  }
}
```

## ApplicationContext.off('applicationStateChange')<sup>10+</sup>

off(type: 'applicationStateChange', callback?: ApplicationStateChangeCallback): void

取消对当前应用进程状态变化的监听。使用callback异步回调。仅支持主线程调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| type   |  string                                   | 是   | 此类型表示当前应用进程状态变化，固定为'applicationStateChange'。 |
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | 否   | 回调函数。取值可以为使用[ApplicationContext.on('applicationStateChange')](#applicationcontextonapplicationstatechange10)方法定义的callback回调，也可以为空。<br/>-&nbsp;如果传入已定义的回调，则取消该监听。 <br/>-&nbsp;如果未传入参数，则取消所有已注册的该类型事件的监听。  |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 本例中的callback字段取值为ApplicationStateChangeCallback，需要替换为实际值。
      // 如果callback字段不传入参数，则取消所有已注册的该类型事件的监听。
      applicationContext.off('applicationStateChange', applicationStateChangeCallback);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.onSystemConfigurationUpdated<sup>24+</sup>

onSystemConfigurationUpdated(callback: systemConfiguration.UpdatedCallback): void

注册监听系统环境[Configuration](js-apis-app-ability-configuration.md#configuration)的变化。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> 应用自定义的设置不影响回调函数的触发。例如：应用自定义设置了深浅色模式，当系统深浅色模式变化后，注册的回调函数依然会触发。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| callback | [systemConfiguration.UpdatedCallback](js-apis-app-ability-systemConfiguration.md#updatedcallback) | 是   | 系统环境变化时触发的回调方法。 |

**示例：**

```ts
import { UIAbility, systemConfiguration, ConfigurationConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let callBack: systemConfiguration.UpdatedCallback = {
      onColorModeUpdated(colorMode: ConfigurationConstant.ColorMode) {
        console.info(`system configuration updated colormode:` + colorMode);
      },
      onFontSizeScaleUpdated(fontSizeScale: number) {
        console.info(`system configuration updated ability:` + fontSizeScale);
      },
      onFontWeightScaleUpdated(fontWeightScale: number) {
        console.info(`system configuration updated ability:` + fontWeightScale);
      },
      onLanguageUpdated(language: string) {
        console.info(`system configuration updated ability:` + language);
      },
      onFontIdUpdated(fontId: string) {
        console.info(`system configuration updated ability:` + fontId);
      },
      onMCCUpdated(mcc: string) {
        console.info(`system configuration updated ability:` + mcc);
      },
      onMNCUpdated(mnc: string) {
        console.info(`system configuration updated ability:` + mnc);
      },
      onHasPointerDeviceUpdated(hasPointerDevice: boolean) {
        console.info(`system configuration updated ability:` + hasPointerDevice);
      },
      onLocaleUpdated(locale: string) {
        console.info(`system configuration updated ability:` + locale);
      }
    }
    // 1.通过context属性获取applicationContext
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2.通过applicationContext注册监听
      applicationContext.onSystemConfigurationUpdated(callBack);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.info(`onSystemConfigurationUpdated finish`);
  }
}
```

## ApplicationContext.offSystemConfigurationUpdated<sup>24+</sup>

offSystemConfigurationUpdated(callback?: systemConfiguration.UpdatedCallback): void

取消监听系统环境[Configuration](js-apis-app-ability-configuration.md#configuration)的变化。仅支持主线程调用。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                   | 类型     | 必填 | 说明                           |
| ------------------------ | -------- | ---- | ------------------------------ |
| callback | [systemConfiguration.UpdatedCallback](js-apis-app-ability-systemConfiguration.md#updatedcallback) | 否   | 回调函数。取值可以为使用[ApplicationContext.onSystemConfigurationUpdated](#applicationcontextonsystemconfigurationupdated24)方法注册的callback回调，也可以为空。<br/>-&nbsp;如果传入已定义的回调，则取消该监听。 <br/>-&nbsp;如果未传入参数，则取消所有已注册的监听。|

**示例：**

```ts
import { UIAbility, systemConfiguration, ConfigurationConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let callBack: systemConfiguration.UpdatedCallback = {
      onColorModeUpdated(colorMode: ConfigurationConstant.ColorMode) {
        console.info(`system configuration updated colormode:` + colorMode);
      },
      onFontSizeScaleUpdated(fontSizeScale: number) {
        console.info(`system configuration updated ability:` + fontSizeScale);
      },
      onFontWeightScaleUpdated(fontWeightScale: number) {
        console.info(`system configuration updated ability:` + fontWeightScale);
      },
      onMCCUpdated(mcc: string) {
        console.info(`system configuration updated ability:` + mcc);
      },
      onMNCUpdated(mnc: string) {
        console.info(`system configuration updated ability:` + mnc);
      },
      onLanguageUpdated(language: string) {
        console.info(`system configuration updated ability:` + language);
      },
      onFontIdUpdated(fontId: string) {
        console.info(`system configuration updated ability:` + fontId);
      },
      onHasPointerDeviceUpdated(hasPointerDevice: boolean) {
        console.info(`system configuration updated ability:` + hasPointerDevice);
      },
      onLocaleUpdated(locale: string) {
        console.info(`system configuration updated ability:` + locale);
      }
    }
    // 1.通过context属性获取applicationContext
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2.通过applicationContext取消监听
      applicationContext.offSystemConfigurationUpdated(callBack);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.info(`offSystemConfigurationUpdated finish`);
  }
}
```

## ApplicationContext.getRunningProcessInformation

getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>

获取运行中的进程信息。使用Promise异步回调。

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 获取运行中的进程信息
    applicationContext.getRunningProcessInformation().then((data) => {
      console.info(`The process running information is: ${JSON.stringify(data)}`);
    }).catch((error: BusinessError) => {
      console.error(`error code: ${error.code}, error msg: ${error.message}`);
    });
  }
}
```

## ApplicationContext.getRunningProcessInformation

getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void

获取运行中的进程信息。使用callback异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>>   | 是   | 回调函数，用于获取运行进程信息。 |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 获取运行中的进程信息
    applicationContext.getRunningProcessInformation((err, data) => {
      if (err) {
        console.error(`getRunningProcessInformation failed, err: ${JSON.stringify(err)}`);
      } else {
        console.info(`The process running information is: ${JSON.stringify(data)}`);
      }
    })
  }
}
```

## ApplicationContext.killAllProcesses

killAllProcesses(): Promise\<void\>

终止应用的所有进程，进程退出时不会正常执行完整的应用生命周期流程。使用Promise异步回调。仅支持主线程调用。

> **说明：**
>
> 该接口用于应用异常场景中强制退出应用。如需正常退出应用，可以使用[terminateSelf()](js-apis-inner-application-uiAbilityContext.md#terminateself-1)接口。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象，无返回结果。 |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 终止应用的所有进程
    applicationContext.killAllProcesses();
  }
}
```

## ApplicationContext.killAllProcesses<sup>14+</sup>

killAllProcesses(clearPageStack: boolean): Promise\<void\>

终止应用的所有进程，进程退出时不会正常执行完整的应用生命周期流程。使用Promise异步回调。仅支持主线程调用。

> **说明：**
>
> 该接口用于应用异常场景中强制退出应用。如需正常退出应用，可以使用[terminateSelf()](js-apis-inner-application-uiAbilityContext.md#terminateself-1)接口。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| clearPageStack | boolean | 是 | 表示是否清除页面堆栈。true表示清除，false表示不清除。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象，无返回结果。 |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 终止应用的所有进程,并清除页面堆栈
    applicationContext.killAllProcesses(isClearPageStack);
  }
}
```

## ApplicationContext.killAllProcesses

killAllProcesses(callback: AsyncCallback\<void\>): void

终止应用的所有进程，进程退出时不会正常执行完整的应用生命周期流程。使用callback异步回调。仅支持主线程调用。

> **说明：**
>
> 该接口用于应用异常场景中强制退出应用。如需正常退出应用，可以使用[terminateSelf()](js-apis-inner-application-uiAbilityContext.md#terminateself-1)接口。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<void\>   | 是   | 回调函数。当终止应用的所有进程成功时，err为undefined，否则为错误对象。 |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 终止应用的所有进程
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

设置应用的深浅色模式。仅支持主线程调用。

> **说明：**
>
> 调用该接口前，需要确保窗口已完成创建、且UIAbility对应的页面已完成加载，即在[onWindowStageCreate()](js-apis-app-ability-uiAbility.md#onwindowstagecreate)生命周期中通过[loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9)方法加载页面之后调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#colormode) | 是   | 深浅色模式，包括：深色模式、浅色模式、未设置颜色模式（默认）。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { UIAbility, ConfigurationConstant } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info("Ability onWindowStageCreate");
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        console.error(`Failed to load the content. Code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info(`Succeeded in loading the content. Data: ${JSON.stringify(data)}`);
      // 获取应用上下文
      let applicationContext = this.context.getApplicationContext();
      // 设置应用为深色模式
      applicationContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);
    });
  }
}
```

## ApplicationContext.setLanguage<sup>11+</sup>

setLanguage(language: string): void

设置应用的语言。仅支持主线程调用。

> **说明：**
>
> 调用该接口前，需要确保窗口已完成创建、且UIAbility对应的页面已完成加载，即在[onWindowStageCreate()](js-apis-app-ability-uiAbility.md#onwindowstagecreate)生命周期中通过[loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9)方法加载页面之后调用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| language | string | 是   | 设置语言，当前支持的语言列表可以通过[getSystemLanguages()](../apis-localization-kit/js-apis-i18n.md#getsystemlanguages9)获取。  |

**错误码**：

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    console.info("Ability onWindowStageCreate");
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        console.error(`Failed to load the content. Code: ${err.code}, message: ${err.message}`);
        return;
      }
      console.info(`Succeeded in loading the content. Data: ${JSON.stringify(data)}`);
    });
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 设置应用语言为中文
    applicationContext.setLanguage('zh-cn');
  }
}
```

## ApplicationContext.clearUpApplicationData<sup>11+</sup>

clearUpApplicationData(): Promise\<void\>

清理当前应用的应用文件路径下的所有数据，同时撤销应用向用户申请的权限。使用Promise异步回调。仅支持主线程调用。


> **说明：**
> 
> 应用文件路径详见[应用文件目录信息](../../file-management/app-sandbox-directory.md#应用文件目录与应用文件路径)。图中仅标识了el1~el2目录下的应用文件路径，其他文件加密类型目录下的应用文件路径可以参考el1。
>
> 该接口会停止应用进程，应用进程停止后，后续的所有回调都不会再触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<void\> | Promise对象，无返回结果。 |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 清理当前应用的应用文件路径下的所有数据
    applicationContext.clearUpApplicationData();
  }
}
```

## ApplicationContext.clearUpApplicationData<sup>11+</sup>

clearUpApplicationData(callback: AsyncCallback\<void\>): void

清理当前应用的应用文件路径下的所有数据，同时撤销应用向用户申请的权限。使用callback异步回调。仅支持主线程调用。


> **说明：**
> 
> 应用文件路径详见[应用文件目录信息](../../file-management/app-sandbox-directory.md#应用文件目录与应用文件路径)。图中仅标识了el1~el2目录下的应用文件路径，其他文件加密类型目录下的应用文件路径可以参考el1。
>
> 该接口会停止应用进程，应用进程停止后，后续的所有回调都不会再触发。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调方法。当清理当前应用的应用文件路径下的所有数据，同时撤销应用向用户申请的权限成功时，error为undefined，否则返回错误对象。  |

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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 清理当前应用的应用文件路径下的所有数据
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

应用重启并拉起自身指定UIAbility。仅支持主线程调用，且待重启的应用需要处于获焦状态。

> **说明：**
>
> 通过该接口重启应用时，不会触发应用中Ability的onDestroy生命周期回调。
>
> 在原子化服务调用本接口成功后的3秒内，再次调用本接口、[restartSelfAtomicService()](js-apis-app-ability-abilityManager.md#abilitymanagerrestartselfatomicservice20)或[UIAbilityContext.restartApp()](js-apis-inner-application-uiAbilityContext.md#restartapp22)接口中的任一接口，系统将返回错误码16000064。
>
> 在应用调用本接口成功后的3秒内，若再次调用本接口或[UIAbilityContext.restartApp()](js-apis-inner-application-uiAbilityContext.md#restartapp22)接口中的任一接口，系统将返回错误码16000064。


**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的UIAbility信息。系统仅校验abilityName字段的有效性，不校验bundleName字段。 |

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
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common, Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @State message: string = 'restartApp';
  private context = this.getUIContext().getHostContext()?.getApplicationContext() as common.ApplicationContext;

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          let want: Want = {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility'
          };
          if (this.context) {
            try {
              // 重启应用并拉起指定UIAbility
              this.context.restartApp(want);
            } catch (err) {
              hilog.error(0x0000, 'testTag', `restart failed: ${err.code}, ${err.message}`);
            }
          } else {
            hilog.error(0x0000, 'testTag', "%{public}s", 'AppContext is null');
          }
        })
    }
    .height('100%')
    .width('100%')
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
| 16000071 | The MultiAppMode is not App_CLONE. |

以上错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onBackground() {
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 获取当前应用的分身索引
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
> 调用该接口前，需要确保窗口已完成创建、且UIAbility对应的页面已完成加载，即在[onWindowStageCreate()](js-apis-app-ability-uiAbility.md#onwindowstagecreate)生命周期中通过[loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9)方法加载页面之后调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明                 |
| ------ | ------------- | ---- | -------------------- |
| font | string | 是   | 设置字体类型，字体可以通过[UIContext.registerFont](../apis-arkui/arkts-apis-uicontext-font.md#registerfont)方法进行注册使用。  |

**错误码**：

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |


**示例：**

```ts
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  aboutToAppear() {
    this.getUIContext().getFont().registerFont({
      familyName: 'fontName',
      familySrc: $rawfile('font/medium.ttf')  // 'font/medium.ttf'仅作为示例，实际使用时请替换为真实的字体资源文件。
    });

    // 设置应用使用注册的自定义字体
    this.context.getApplicationContext().setFont('fontName');
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

设置当前应用进程是否支持进程资源的缓存，便于应用再次启动时复用缓存的进程资源。仅支持主线程调用。

该接口仅对单个进程实例生效，不同进程实例互不影响。应用进程实例销毁后，已设置的状态不保留，需要重新设置。

> **说明：**
> - 该接口仅表示应用自身是否为缓存后快速启动做好了准备，还需综合其他条件来判断最终是否为应用启用快速启动。
> - 为了确保该接口在进程退出前生效，调用时机应尽量提前。建议在[AbilityStage](../../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)的`onCreate()`中调用该接口。
> - 在同一进程多次调用该接口时，会以最后一次调用的结果为准。当存在多个AbilityStage时，为了确保结果符合预期，需要在各个AbilityStage中分别调用该接口并配置相同的取值。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口仅在Phone和2in1设备中可正常调用，在其他设备中返回801错误码。

**参数：**
| 参数名        | 类型     | 必填 | 说明                       |
| ------------- | -------- | ---- | -------------------------- |
| isSupported | boolean | 是 | 表示应用是否支持进程资源的缓存。true表示支持，false表示不支持。 |

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

export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 设置当前应用进程支持进程资源的缓存
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
      // 获取应用上下文
      let applicationContext = this.context.getApplicationContext();
      // 设置应用字体大小缩放比例
      applicationContext.setFontSizeScale(2);
    });
  }
}
```


## ApplicationContext.getCurrentInstanceKey<sup>14+</sup>

getCurrentInstanceKey(): string

获取当前应用多实例的唯一实例标识。仅支持主线程调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口仅在2in1设备中可正常调用，在其他设备中返回16000078错误码。

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

export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    let currentInstanceKey = '';
    try {
      // 获取当前应用多实例的唯一实例标识
      currentInstanceKey = applicationContext.getCurrentInstanceKey();
    } catch (error) {
      let code = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`getCurrentInstanceKey fail, code: ${code}, msg: ${message}`);
    }
    console.info(`currentInstanceKey: ${currentInstanceKey}`);
  }
}
```

## ApplicationContext.getAllRunningInstanceKeys<sup>14+</sup>

getAllRunningInstanceKeys(): Promise\<Array\<string>>;

获取应用的所有多实例的唯一实例标识。使用Promise异步回调。仅支持主线程调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**设备行为差异**：该接口仅在PC/2in1设备中可正常调用。

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

export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 获取应用的所有多实例的唯一实例标识
      applicationContext.getAllRunningInstanceKeys();
    } catch (error) {
      let code = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`getAllRunningInstanceKeys fail, code: ${code}, msg: ${message}`);
    }
  }
}
```

## ApplicationContext.getAllWindowStages<sup>23+</sup>

getAllWindowStages(): Promise\<Array\<window.WindowStage>>

获取应用当前进程内的所有WindowStage对象。使用Promise异步回调。仅支持主线程调用。

该接口主要用于包含多个UIAbility的应用进行多窗口管理，例如管理多个WindowStage的状态、同一应用的多个窗口间的状态或数据同步等。

 **原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型   | 说明                           |
| ------ | ------------------------------ |
| Promise\<Array\<[window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md)>> | Promise对象，返回应用当前进程内的所有WindowStage对象。|

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 获取应用当前进程内的所有WindowStage对象
      applicationContext.getAllWindowStages().then((data: window.WindowStage[]) => {
        let windowStage: window.WindowStage[] = data;
        console.info(`WindowStages size ${windowStage.length}`);
      }).catch((error: BusinessError) => {
        console.error(`getAllWindowStages error, code: ${error.code}, error msg: ${error.message}`);
      });
    } catch (error) {
      let code = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`getAllWindowStages fail, code: ${code}, msg: ${message}`);
    }
  }
}
```

## ApplicationContext.enableDelayedProcessExit

enableDelayedProcessExit(): Promise\<void>

启用当前进程延迟退出功能，使用Promise异步回调。仅支持主线程调用。

在正常情况下，应用进程中最后一个UIAbility退出后，进程将退出。调用此接口，在最后一个UIAbility退出后，进程将延迟10秒退出。如果在当前进程的10秒内启动该进程的新UIAbility，进程将不再退出。

**起始版本**：26.0.0

**原子化服务API**：从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.                                    |
| 16000050 | Internal error. Possible causes: Fail to connect system service. |
| 16000150 | The current process has no UIAbility, and this API cannot be called. |

**示例：**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    try {
      // 启用当前进程延迟退出功能
      this.context.getApplicationContext().enableDelayedProcessExit().then(() => {
        console.info('enableDelayedProcessExit succeed');
      }).catch((error: BusinessError) => {
        console.error(`enableDelayedProcessExit error, code: ${error.code}, error msg: ${error.message}`);
      });
    } catch(error) {
      console.error('enableDelayedProcessExit failed. Code=%{public}d, Message=%{public}s', error.code, error.message);
    }
  }
}
```

## ApplicationContext.disableDelayedProcessExit

disableDelayedProcessExit(): Promise\<void>

禁用当前进程延迟退出功能，使用Promise异步回调。仅支持主线程调用。

调用此API将会取消[ApplicationContext.enableDelayedProcessExit](#applicationcontextenabledelayedprocessexit)的作用。

**起始版本**：26.0.0

**原子化服务API**：从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.                                    |
| 16000050 | Internal error. Possible causes: Fail to connect system service. |
| 16000150 | The current process has no UIAbility, and this API cannot be called. |

**示例：**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    try {
      // 禁用当前进程延迟退出功能
      this.context.getApplicationContext().disableDelayedProcessExit().then(() => {
        console.info('disableDelayedProcessExit succeed');
      }).catch((error: BusinessError) => {
        console.error(`disableDelayedProcessExit error, code: ${error.code}, error msg: ${error.message}`);
      });
    } catch(error) {
      console.error('disableDelayedProcessExit failed. Code=%{public}d, Message=%{public}s', error.code, error.message);
    }
  }
}
```

## ApplicationContext.startSelfUIAbility

startSelfUIAbility(want: Want): Promise\<void>

当前进程延迟退出期间，在当前进程启动一个自身UIAbility，启动成功后，当前进程不再退出。

**起始版本**：26.0.0

**原子化服务API**：从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型                                | 必填 | 说明                                        |
| ------ | ----------------------------------- | ---- | ------------------------------------------- |
| want   | [Want](js-apis-app-ability-want.md) | 是   | Want类型参数，传入需要启动的UIAbility信息。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 801      | Capability not supported.                                    |
| 16000001 | The specified ability does not exist.                        |
| 16000008 | The crowdtesting application expires.                        |
| 16000009 | An ability cannot be started or stopped in Wukong mode.      |
| 16000050 | Internal error. Possible causes: Fail to connect system service. |
| 16000122 | The target component is blocked by the system module and does not support startup. |
| 16000123 | Implicit startup is not supported.                           |
| 16000124 | Starting a remote UIAbility is not supported.                |
| 16000125 | Starting a plugin UIAbility is not supported.                |
| 16000130 | The UIAbility does not belong to the caller.                 |
| 16000161 | Delayed process exit is not pending in the current process, and this API cannot be called. |
| 16000162 | The current process still has another UIAbility, and this API cannot be called. |

**示例：**

```ts
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = '延迟启动';
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Button(this.message)
      .fontSize(50)
      .align(Alignment.Center)
      .onClick(() => {
        try {
          const newWant: Want = {
            bundleName: 'com.example.myapplication',
            abilityName: 'EntryAbility',
            parameters: {
              'pageName': 'IndexNew'  // 标记启动主页面
            }
          };
          // 获取应用上下文
          let applicationContext = this.context.getApplicationContext();
          // 在延迟退出期间启动主界面
          this.context.terminateSelf().then(() => {
            // 设置延时2000 ms以确保主应用完全退出后再调用startSelfUIAbility接口。
            setTimeout(() => {
              applicationContext.getApplicationContext().startSelfUIAbility(newWant).then(() => {
                hilog.info(0x0000, 'testTag', '启动主界面成功');
              }).catch((error: BusinessError) => {
                hilog.error(0x0000, 'testTag', `启动主界面失败, code: ${error.code}, error msg: ${error.message}`);
              });
            }, 2000);
          });
        } catch (error) {
          hilog.error(0x0000, 'testTag', `启动主界面失败, code: ${error.code}, error msg: ${error.message}`);
        }
      });
  }
}
```

## ApplicationContext.getUIAbilityByInstanceId

getUIAbilityByInstanceId(instanceId: string): UIAbility

在多实例场景中，根据实例ID获取特定的UIAbility实例。仅支持主线程调用。

**起始版本：** 26.0.0

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| instanceId | string | 是 | UIAbility的实例ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [UIAbility](js-apis-app-ability-uiAbility.md) | 返回与instanceId对应的UIAbility实例。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000003 | The id does not exist. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. System service failed to communicate with dependency module. |

**示例：**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      let instanceId = 'xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx';
      // 根据实例ID获取UIAbility实例
      let uiAbility = applicationContext.getUIAbilityByInstanceId(instanceId);
      console.info(`getUIAbilityByInstanceId succeed, ability: ${uiAbility}`);
    } catch (error) {
      let code = (error as BusinessError).code;
      let message = (error as BusinessError).message;
      console.error(`getUIAbilityByInstanceId fail, code: ${code}, message: ${message}`);
    }
  }
}
```
