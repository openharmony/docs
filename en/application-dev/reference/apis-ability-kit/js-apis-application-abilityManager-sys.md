# @ohos.application.abilityManager (AbilityManager) (System API)

The **AbilityManager** module provides APIs for obtaining, adding, and modifying ability running information and state information.

> **NOTE**
>
> The APIs of this module are supported since API version 8 and deprecated since API version 9. You are advised to use [@ohos.app.ability.abilityManager](js-apis-app-ability-abilityManager-sys.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```ts
import abilityManager from '@ohos.application.abilityManager';
```

## AbilityState

Enumerates the ability states.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

| Name| Value| Description| 
| -------- | -------- | -------- |
| INITIAL | 0 | The ability is in the initial state.| 
| FOREGROUND | 9 | The ability is running in the foreground. | 
| BACKGROUND | 10 | The ability is running in the background. | 
| FOREGROUNDING | 11 | The ability is being switched to the foreground. | 
| BACKGROUNDING | 12 | The ability is being switched to the background. | 

## updateConfiguration

updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void

Updates the configuration. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-application-configuration.md)   | Yes   | New configuration.|
| callback  | AsyncCallback\<void>                   | Yes   | Callback used to return the result. If the configuration is updated, **err** is undefined; otherwise, **err** is an error object.     |

**Example**

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

Updates the configuration. This API uses a promise to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-application-configuration.md)   | Yes   | New configuration.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<void> | Promise that returns no value.|

**Example**

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

Obtains the ability running information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo-sys.md)>>  | Yes   | Callback used to return the ability running information.     |

**Example**

```ts
import abilityManager from '@ohos.application.abilityManager';
import { BusinessError } from '@ohos.base';

abilityManager.getAbilityRunningInfos((err: BusinessError, data) => { 
    console.log(`getAbilityRunningInfos err: ${err}, data: ${JSON.stringify(data)}`);
});
```

## getAbilityRunningInfos

getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>

Obtains the ability running information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo-sys.md)>> | Promise used to return the ability running information.|

**Example**

```ts
import abilityManager from '@ohos.application.abilityManager';
import { BusinessError } from '@ohos.base';

abilityManager.getAbilityRunningInfos().then((data) => {
    console.log(`getAbilityRunningInfos  data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getAbilityRunningInfos err: ${JSON.stringify(err)}`);
});
```
