# ApplicationContext

The ApplicationContext module, inherited from [Context](js-apis-inner-application-context.md), provides application-level context capabilities, including APIs for registering and deregistering the lifecycle of application components.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## Usage

Before calling any APIs in **ApplicationContext**, obtain an **ApplicationContext** instance through the **context** instance.

## ApplicationContext.on('abilityLifecycle')

on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback): number

Registers a listener to monitor the ability lifecycle of the application. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                  | Type    | Mandatory| Description                          |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | 'abilityLifecycle' | Yes  | Event type.|
| callback | [AbilityLifecycleCallback](js-apis-app-ability-abilityLifecycleCallback.md) | Yes  | Callback used to return the ID of the registered listener.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| number | ID of the registered listener. The ID is incremented by 1 each time the listener is registered. When the ID exceeds 2^63-1, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

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
    // 1. Obtain applicationContext through the context property.
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2. Use applicationContext.on() to subscribe to the 'abilityLifecycle' event.
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

Deregisters the listener that monitors the ability lifecycle of the application. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | Yes  | Event type.|
| callbackId    | number   | Yes  | ID of the listener to deregister.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the deregistration is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

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

Deregisters the listener that monitors the ability lifecycle of the application. This API uses a promise to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | Yes  | Event type.|
| callbackId    | number   | Yes  | ID of the listener to deregister.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

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

Registers a listener for system environment changes. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                  | Type    | Mandatory| Description                          |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | 'environment' | Yes  | Event type.|
| callback | [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) | Yes  | Callback used to return the system environment changes.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| number | ID of the registered listener. The ID is incremented by 1 each time the listener is registered. When the ID exceeds 2^63-1, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

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
    // 1. Obtain an applicationContext object.
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2. Use applicationContext.on() to subscribe to the 'environment' event.
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

Deregisters the listener for system environment changes. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | Yes  | Event type.|
| callbackId    | number   | Yes  | ID of the listener to deregister.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the deregistration is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

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

Deregisters the listener for system environment changes. This API uses a promise to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | Yes  | Event type.|
| callbackId    | number   | Yes  | ID of the listener to deregister.  |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

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

Registers a listener for application foreground/background state changes. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description            |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| type     | 'applicationStateChange'                                     | Yes  | Event type.|
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | Yes  | Callback used to return the result. You can define a callback for switching from the background to the foreground and a callback for switching from the foreground to the background.      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

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

    // 1. Obtain an applicationContext object.
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2. Use applicationContext.on() to subscribe to the 'applicationStateChange' event.
      applicationContext.on('applicationStateChange', applicationStateChangeCallback);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.log('Resgiter applicationStateChangeCallback');
  }
}
```

## ApplicationContext.off('applicationStateChange')<sup>10+</sup>

off(type: 'applicationStateChange', callback?: ApplicationStateChangeCallback): void

Deregisters all the listeners for application foreground/background state changes. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| type   | 'applicationStateChange' | Yes  | Event type.|
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | No  | Callback used to return the result. You can define a callback for switching from the background to the foreground and a callback for switching from the foreground to the background.      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyAbility extends UIAbility {
  onDestroy() {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.off('applicationStateChange');
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```

## ApplicationContext.getRunningProcessInformation

getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>

Obtains information about the running processes. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Promise used to return the API call result and the process running information. You can perform error handling or custom processing in this callback.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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

Obtains information about the running processes. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>>   | Yes  | Callback used to return the information about the running processes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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

Kills all the processes where the application is located. This API uses a promise to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onBackground() {
    let applicationContext = this.context.getApplicationContext();
    applicationContext.killAllProcesses();
  }
}
```

## ApplicationContext.killAllProcesses<sup>13+</sup>

killAllProcesses(clearPageStack: boolean): Promise\<void\>

Kills all the processes where the application is located. This API uses a promise to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| clearPageStack | boolean | Yes| Whether to clear the page stack. The value **true** means to clear the page stack, and **false** means the opposite.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**Example**

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

Kills all the processes where the application is located. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| callback    | AsyncCallback\<void\>   | Yes  | Callback used to return the result. If all the processes are killed, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**Example**

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

Sets the color mode for the application. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#configurationconstantcolormode) | Yes  | Target color mode, including dark mode, light mode, and system theme mode (no setting).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**Example**

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

Sets the language for the application. This API can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| language | string | Yes  | Target language. The list of supported languages can be obtained by calling [getSystemLanguages()](../apis-localization-kit/js-apis-i18n.md#getsystemlanguages9). |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |


**Example**

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

Clears up the application data and revokes the permissions that the application has requested from users. This API uses a promise to return the result. It can be called only by the main thread.

> **NOTE**
>
> This API stops the application process. After the application process is stopped, all subsequent callbacks will not be triggered.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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

Clears up the application data and revokes the permissions that the application has requested from users. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

> **NOTE**
>
> This API stops the application process. After the application process is stopped, all subsequent callbacks will not be triggered.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the application data is cleared up, **error** is **undefined**; otherwise, **error** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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

Restarts the application and starts the specified UIAbility. The **onDestroy** callback is not triggered during the restart. It can be called only by the main thread, and the application to restart must be active.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the UIAbility to start. No verification is performed on the bundle name passed in.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000063 | The target to restart does not belong to the current app or is not a UIAbility. |
| 16000064 | Restart too frequently. Try again at least 10s later. |

**Example**

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

Obtains the index of the current application clone.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| number | Index of the current application clone.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000071 | The MultiAppMode is not {@link APP_CLONE}. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

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

Sets the font for this application. This API can be called only by the main thread.

> **NOTE**
>
> This API can be called only after a page window is created. That is, this API must be called after the lifecycle callback [onWindowStageCreate()](js-apis-app-ability-uiAbility.md#uiabilityonwindowstagecreate).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| font | string | Yes  | Font, which can be registered by calling [font.registerFont](../apis-arkui/js-apis-font.md#fontregisterfont). |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |


**Example**

```ts
import { font } from '@kit.ArkUI';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  aboutToAppear() {
    font.registerFont({
      familyName: 'fontName',
      familySrc: $rawfile('font/medium.ttf')
    })

    getContext().getApplicationContext().setFont("fontName");
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

Sets whether the application itself supports process cache, which enables quick startup after caching. It can be called only by the main thread.

> **NOTE**
>
> - This API only sets the application to be ready for quick startup after caching. It does not mean that quick startup will be triggered. Other conditions must be considered to determine whether to trigger quick startup.
> - The process cache support status takes effect for a single application process instance. The setting does not affect other process instances. After a process instance is destroyed, the status is not retained and can be reset.
> - To support process cache, you must call this API, with **true** passed in, in the **onCreate()** lifecycle of all [AbilityStages](../../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) in the same process.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| isSupported | boolean | Yes| Whether process cache is supported. The value **true** means that process cache is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 801      | Capability not supported.|
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

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
