# ApplicationContext (Application-level Context)

The ApplicationContext module inherits from [Context](js-apis-inner-application-context.md). It provides application-level context capabilities, including APIs for registering and unregistering the lifecycle of application components.

You can obtain the application-level context by calling [getApplicationContext](js-apis-app-ability-application.md#applicationgetapplicationcontext14).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## ApplicationContext.on('abilityLifecycle')

on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback): number

Registers a listener for the lifecycle of a UIAbility within the application. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                  | Type    | Mandatory| Description                          |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | 'abilityLifecycle' | Yes  | Event type. The value **'abilityLifecycle'** indicates the UIAbility lifecycle.|
| callback | [AbilityLifecycleCallback](js-apis-app-ability-abilityLifecycleCallback.md) | Yes  | Callback triggered when the UIAbility lifecycle changes.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | ID of the callback registered. (The ID is incremented by 1 each time such an event is registered. If it exceeds the upper limit of 2^63-1, **-1** is returned). This ID is used to unregister the corresponding callback in [ApplicationContext.off('abilityLifecycle')](#applicationcontextoffabilitylifecycle).|

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

Unregisters a listener for the lifecycle of a UIAbility within the application. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | Yes  | Event type. The value **'abilityLifecycle'** indicates the UIAbility lifecycle.|
| callbackId    | number   | Yes  | ID returned when the [ApplicationContext.on('abilityLifecycle')](#applicationcontextonabilitylifecycle) API is called to register a listener for the lifecycle of a UIAbility within the application.|
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

Unregisters a listener for the lifecycle of a UIAbility within the application. This API uses a promise to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | Yes  | Event type. The value **'abilityLifecycle'** indicates the UIAbility lifecycle.|
| callbackId    | number   | Yes  | ID returned when the [ApplicationContext.on('abilityLifecycle')](#applicationcontextonabilitylifecycle) API is called to register a listener for the lifecycle of a UIAbility within the application.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | that returns no value.|

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

> **NOTE**
>
> You can also use [onConfigurationUpdate](../apis-ability-kit/js-apis-app-ability-ability.md#abilityonconfigurationupdate) to listen for system environment changes. Unlike **onConfigurationUpdate**, this API offers greater flexibility. It can be used both within application components and pages.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                  | Type    | Mandatory| Description                          |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | 'environment' | Yes  | Event type. The value **'environment'** indicates that the system environment changes, for example, the system dark/light color mode changes.|
| callback | [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) | Yes  | Callback triggered when the system environment changes.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | ID of the callback registered. (The ID is incremented by 1 each time such an event is registered. If it exceeds the upper limit of 2^63-1, **-1** is returned). This ID is used to unregister the corresponding callback in [ApplicationContext.off('environment')](#applicationcontextoffenvironment).|

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

Unregisters the listener for system environment changes. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | Yes  | Event type. The value **'environment'** indicates that the system environment changes, for example, the system dark/light color mode changes.|
| callbackId    | number   | Yes  | ID returned when the [ApplicationContext.on('environment')](#applicationcontextonenvironment) API is called to register a listener for system environment changes.|
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

Unregisters the listener for system environment changes. This API uses a promise to return the result. It can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | Yes  | Event type. The value **'environment'** indicates that the system environment changes, for example, the system dark/light color mode changes.|
| callbackId    | number   | Yes  | ID returned when the [ApplicationContext.on('environment')](#applicationcontextonenvironment) API is called to register a listener for system environment changes.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | that returns no value.|

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
| type     | 'applicationStateChange'                                     | Yes  | Event type. The value **'applicationStateChange'** indicates the application foreground/background state change.|
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | Yes  | Callback triggered when the application is switched between the foreground and background.|

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
    console.log('Register applicationStateChangeCallback');
  }
}
```

## ApplicationContext.off('applicationStateChange')<sup>10+</sup>

off(type: 'applicationStateChange', callback?: ApplicationStateChangeCallback): void

Unregisters a listener for application foreground/background state changes. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

> **NOTE**
>
> A listener must have been registered by calling [ApplicationContext.on('applicationStateChange')](#applicationcontextonapplicationstatechange10).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| type   | 'applicationStateChange' | Yes  | Event type. The value **'applicationStateChange'** indicates the application foreground/background state change.|
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | No  | Callback used to return the result. The value can be a callback defined by [ApplicationContext.on('applicationStateChange')](#applicationcontextonapplicationstatechange10) or empty.<br>- If a defined callback is passed in, the listener for that callback is unregistered.<br>- If no value is passed in, all the listeners for the corresponding event are unregistered. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

Assume that [ApplicationContext.on('applicationStateChange')](#applicationcontextonapplicationstatechange10) is used to register a callback named **applicationStateChangeCallback**. The following example shows how to unregister the corresponding listener.

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
      // In this example, the callback field is set to applicationStateChangeCallback.
      // If no value is passed in for the callback field, all the listeners registered for the application foreground/background state change event are canceled.
      applicationContext.off('applicationStateChange', applicationStateChangeCallback);
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
        console.error(`getRunningProcessInformation failed, err: ${JSON.stringify(err)}`);
      } else {
        console.log(`The process running information is: ${JSON.stringify(data)}`);
      }
    })
  }
}
```

## ApplicationContext.killAllProcesses

killAllProcesses(): Promise\<void\>

Kills all processes of this application. The application will not execute the normal lifecycle when exiting. This API uses a promise to return the result. It can be called only by the main thread.

> **NOTE**
>
> This API is used to forcibly exit an application in abnormal scenarios. To exit an application properly, call [terminateSelf()](js-apis-inner-application-uiAbilityContext.md#terminateself-1).

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

## ApplicationContext.killAllProcesses<sup>14+</sup>

killAllProcesses(clearPageStack: boolean): Promise\<void\>

Kills all processes of this application. The application will not execute the normal lifecycle when exiting. This API uses a promise to return the result. It can be called only by the main thread.

> **NOTE**
>
> This API is used to forcibly exit an application in abnormal scenarios. To exit an application properly, call [terminateSelf()](js-apis-inner-application-uiAbilityContext.md#terminateself-1).

**Atomic service API**: This API can be used in atomic services since API version 14.

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
| 401 | If the input parameter is not valid parameter. |
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

Kills all processes of this application. The application will not execute the normal lifecycle when exiting. This API uses an asynchronous callback to return the result. It can be called only by the main thread.

> **NOTE**
>
> This API is used to forcibly exit an application in abnormal scenarios. To exit an application properly, call [terminateSelf()](js-apis-inner-application-uiAbilityContext.md#terminateself-1).

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

Sets the dark/light color mode for the application. This API can be called only by the main thread.

> **NOTE**
>
> Before calling this API, ensure that the window has been created and the page corresponding to the UIAbility has been loaded (using the [loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9) API in the [onWindowStageCreate()](js-apis-app-ability-uiAbility.md#onwindowstagecreate) lifecycle).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| colorMode | [ConfigurationConstant.ColorMode](js-apis-app-ability-configurationConstant.md#colormode) | Yes  | Dark/light color mode, which can be dark mode, light mode, or follow-system mode (default).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000011 | The context does not exist. |

**Example**

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
    });
    let applicationContext = this.context.getApplicationContext();
    applicationContext.setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_DARK);
  }
}
```

## ApplicationContext.setLanguage<sup>11+</sup>

setLanguage(language: string): void

Sets the language for the application. This API can be called only by the main thread.

> **NOTE**
>
> Before calling this API, ensure that the window has been created and the page corresponding to the UIAbility has been loaded (using the [loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9) API in the [onWindowStageCreate()](js-apis-app-ability-uiAbility.md#onwindowstagecreate) lifecycle).

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

Restarts the application and starts the specified UIAbility. The **onDestroy** callback is not triggered during the restart. This API can be called only by the main thread, and the application to restart must be active.

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
| 16000063 | The target to restart does not belong to the current application or is not a UIAbility. |
| 16000064 | Restart too frequently. Try again at least 3s later. |

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
| 16000071 | App clone is not supported. |

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
> Before calling this API, ensure that the window has been created and the page corresponding to the UIAbility has been loaded (using the [loadContent](../apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9) API in the [onWindowStageCreate()](js-apis-app-ability-uiAbility.md#onwindowstagecreate) lifecycle).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| font | string | Yes  | Font, which can be registered by calling [UIContext.registerFont](../apis-arkui/js-apis-arkui-UIContext.md#registerfont). |

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

Sets whether the current application's process can quickly start up after being cached. This API can be called only by the main thread.

This setting applies only to the current process instance and does not affect others. If the application process instance is terminated, the previously set state will not be preserved and must be reset.

> **NOTE**
> - This API takes effect only for 2-in-1 devices and phones.
> - This API only sets the application to be ready for quick startup after caching. It does not mean that quick startup will be triggered. Other conditions must be considered to determine whether to trigger quick startup.
> - To ensure that this API is effective before the process exits, it should be called as soon as possible. You are advised to call this API within the **onCreate()** callback of the [AbilityStage](../../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md).
> - If this API is called multiple times within the same process, the outcome of the final call is used. In cases where there are multiple AbilityStage instances, to achieve the desired result, this API must be called and configured with the same value in each AbilityStage.

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


## ApplicationContext.setFontSizeScale<sup>13+</sup>

setFontSizeScale(fontSizeScale: number): void

Sets the scale ratio for the font size of this application. This API can be called only by the main thread.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| fontSizeScale | number | Yes  | Font scale ratio. The value is a non-negative number. When the application's [fontSizeScale](../../quick-start/app-configuration-file.md#configuration) is set to **followSystem** and the value set here exceeds the value of [fontSizeMaxScale](../../quick-start/app-configuration-file.md#configuration), the value of [fontSizeMaxScale](../../quick-start/app-configuration-file.md#configuration) takes effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. |

**Example**

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

Obtains the unique instance ID of this application. This API can be called only by the main thread.

> **NOTE**
>
> This API takes effect only for 2-in-1 devices.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| string | Unique instance ID of the application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000078 | The multi-instance is not supported. |

**Example**

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

Obtains the unique instance IDs of all multi-instances of this application. This API uses a promise to return the result. It can be called only by the main thread.

> **NOTE**
>
> This API takes effect only for 2-in-1 devices.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| Promise\<Array\<string>> | Promise used to return the unique instance IDs of all multi-instances of the application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000078 | The multi-instance is not supported. |

**Example**

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
