# ApplicationContext

The **ApplicationContext** module provides application-level context. You can use the APIs of this module to register and deregister the ability lifecycle listener in an application.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Usage

Before calling any APIs in **ApplicationContext**, obtain an **ApplicationContext** instance through the **context** instance.

## ApplicationContext.on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback)

on(type: 'abilityLifecycle', callback: AbilityLifecycleCallback): **number**;

Registers a listener to monitor the ability lifecycle of the application.

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

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';

let lifecycleId: number;

export default class EntryAbility extends UIAbility {
    onCreate() {
        console.log('MyAbility onCreate');
        let AbilityLifecycleCallback: AbilityLifecycleCallback = {
            onAbilityCreate(ability) {
                console.log('AbilityLifecycleCallback onAbilityCreate ability: ${ability}');
            },
            onWindowStageCreate(ability, windowStage) {
                console.log('AbilityLifecycleCallback onWindowStageCreate ability: ${ability}');
                console.log('AbilityLifecycleCallback onWindowStageCreate windowStage: ${windowStage}');
            },
            onWindowStageActive(ability, windowStage) {
                console.log('AbilityLifecycleCallback onWindowStageActive ability: ${ability}');
                console.log('AbilityLifecycleCallback onWindowStageActive windowStage: ${windowStage}');
            },
            onWindowStageInactive(ability, windowStage) {
                console.log('AbilityLifecycleCallback onWindowStageInactive ability: ${ability}');
                console.log('AbilityLifecycleCallback onWindowStageInactive windowStage: ${windowStage}');
            },
            onWindowStageDestroy(ability, windowStage) {
                console.log('AbilityLifecycleCallback onWindowStageDestroy ability: ${ability}');
                console.log('AbilityLifecycleCallback onWindowStageDestroy windowStage: ${windowStage}');
            },
            onAbilityDestroy(ability) {
                console.log('AbilityLifecycleCallback onAbilityDestroy ability: ${ability}');
            },
            onAbilityForeground(ability) {
                console.log('AbilityLifecycleCallback onAbilityForeground ability: ${ability}');
            },
            onAbilityBackground(ability) {
                console.log('AbilityLifecycleCallback onAbilityBackground ability: ${ability}');
            },
            onAbilityContinue(ability) {
                console.log('AbilityLifecycleCallback onAbilityContinue ability: ${ability}');
            }
        }
        // 1. Obtain applicationContext through the context attribute.
        let applicationContext = this.context.getApplicationContext();
        // 2. Use applicationContext.on to subscribe to the 'abilityLifecycle' event.
        lifecycleId = applicationContext.on('abilityLifecycle', AbilityLifecycleCallback);
        console.log('registerAbilityLifecycleCallback lifecycleId: ${lifecycleId)}');
    }
}
```

## ApplicationContext.off(type: 'abilityLifecycle', callbackId: number, callback: AsyncCallback\<void>)

off(type: 'abilityLifecycle', callbackId: **number**,  callback: AsyncCallback<**void**>): **void**;

Deregisters the listener that monitors the ability lifecycle of the application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | Yes  | Event type.|
| callbackId    | number   | Yes  | ID of the listener to deregister.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.                  |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

let lifecycleId: number;

export default class EntryAbility extends UIAbility {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        console.log('stage applicationContext: ${applicationContext}');
        applicationContext.off('abilityLifecycle', lifecycleId, (error, data) => {
            if (error) {
                console.error('unregisterAbilityLifecycleCallback fail, err: ${JSON.stringify(error)}');    
            } else {
                console.log('unregisterAbilityLifecycleCallback success, data: ${JSON.stringify(data)}');
            }
        });
    }
}
```

## ApplicationContext.off(type: 'abilityLifecycle', callbackId: number)

off(type: 'abilityLifecycle', callbackId: number): Promise\<void>;

Deregisters the listener that monitors the ability lifecycle of the application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'abilityLifecycle' | Yes  | Event type.|
| callbackId    | number   | Yes  | ID of the listener to deregister.|

**Example**

```ts
import Ability from '@ohos.app.ability.UIAbility';

let lifecycleId: number;

export default class MyAbility extends Ability {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        console.log('stage applicationContext: ${applicationContext}');
        applicationContext.off('abilityLifecycle', lifecycleId);
    }
}
```

## ApplicationContext.on(type: 'environment', callback: EnvironmentCallback)

on(type: 'environment', callback: EnvironmentCallback): **number**;

Registers a listener for system environment changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name                  | Type    | Mandatory| Description                          |
| ------------------------ | -------- | ---- | ------------------------------ |
| type | 'environment' | Yes  | Event type.|
| callback | [EnvironmentCallback](js-apis-app-ability-environmentCallback.md) | Yes  | Callback used to return the ID of the registered listener.|

**Return value**

| Type  | Description                          |
| ------ | ------------------------------ |
| number | ID of the registered listener. The ID is incremented by 1 each time the listener is registered. When the ID exceeds 2^63-1, **-1** is returned.|

**Example**

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
        // 1. Obtain an applicationContext object.
        let applicationContext = this.context.getApplicationContext();
        // 2. Use applicationContext.on() to subscribe to the 'environment' event.
        callbackId = applicationContext.on('environment', environmentCallback);
        console.log(`registerEnvironmentCallback callbackId: ${callbackId}`);
    }
}
```

## ApplicationContext.off(type: 'environment', callbackId: number, callback: AsyncCallback\<void>)

off(type: 'environment', callbackId: **number**,  callback: AsyncCallback<**void**>): **void**;

Deregisters the listener for system environment changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | Yes  | Event type.|
| callbackId    | number   | Yes  | ID of the listener to deregister.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.                 |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

let callbackId: number;

export default class EntryAbility extends UIAbility {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.off('environment', callbackId, (error, data) => {
            if (error) {
                console.error('unregisterEnvironmentCallback fail, err: ${JSON.stringify(error)}');
            } else {
                console.log('unregisterEnvironmentCallback success, data: ${JSON.stringify(data)}');
            }
        });
    }
}
```

## ApplicationContext.off(type: 'environment', callbackId: number)

off(type: 'environment', callbackId: **number**,  callback: AsyncCallback<**void**>): **void**;

Deregisters the listener for system environment changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name        | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| type | 'environment' | Yes  | Event type.|
| callbackId    | number   | Yes  | ID of the listener to deregister.  |

**Example**

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

on(type: 'applicationStateChange', callback: ApplicationStateChangeCallback): **void**;

Registers a listener for application foreground/background state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description            |
| -------- | ------------------------------------------------------------ | ---- | ---------------- |
| type     | string                                     | Yes  | Event type. The value is fixed at **'applicationStateChange'**, indicating that the application switches from the foreground to the background or vice versa.|
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | Yes  | Callback used to return the result.      |

**Example**

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

        // 1. Obtain an applicationContext object.
        let applicationContext = this.context.getApplicationContext();
        // 2. Use applicationContext.on() to subscribe to the 'applicationStateChange' event.
        applicationContext.on('applicationStateChange', applicationStateChangeCallback);
        console.log('Resgiter applicationStateChangeCallback');
    }
}
```

## ApplicationContext.off(type: 'applicationStateChange')<sup>10+</sup>

off(type: 'applicationStateChange', callback?: ApplicationStateChangeCallback):  **void**;

Deregisters all the listeners for application foreground/background state changes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type         | Mandatory| Description                |
| ------ | ------------- | ---- | -------------------- |
| type   | string | Yes  | Event type. The value is fixed at **'applicationStateChange'**, indicating that the application switches from the foreground to the background or vice versa.|
| callback | [ApplicationStateChangeCallback](js-apis-app-ability-applicationStateChangeCallback.md) | No  | Callback used to return the result.      |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.off('applicationStateChange');
    }
}
```

## ApplicationContext.getRunningProcessInformation<sup>9+</sup>

getRunningProcessInformation(): Promise\<Array\<ProcessInformation>>;

Obtains information about the running processes. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Promise used to return the API call result and the process running information. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

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

## ApplicationContext.getRunningProcessInformation<sup>9+</sup>

getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation>>): void;

Obtains information about the running processes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
|AsyncCallback\<Array\<[ProcessInformation](js-apis-inner-application-processInformation.md)>> | Callback used to return the API call result and the process running information. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

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

## ApplicationContext.killAllProcesses<sup>9+</sup>

killAllProcesses(): Promise\<void\>;

Kills all the processes where the application is located. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MyAbility extends UIAbility {
    onBackground() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.killAllProcesses();
    }
}
```

## ApplicationContext.killAllProcesses<sup>9+</sup>

killAllProcesses(callback: AsyncCallback\<void\>);

Kills all the processes where the application is located. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
|AsyncCallback\<void\> | Callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

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
