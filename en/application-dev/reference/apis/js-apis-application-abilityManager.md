# @ohos.application.abilityManager

The **AbilityManager** module provides APIs for obtaining, adding, and modifying ability running information and state information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```ts
import AbilityManager from '@ohos.application.abilityManager'
```

## AbilityState

Enumerates the ability states.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name| Value| Description| 
| -------- | -------- | -------- |
| INITIAL | 0 | The ability is in the initial state.| 
| FOREGROUND | 9 | The ability is in the foreground state. | 
| BACKGROUND | 10 | The ability is in the background state. | 
| FOREGROUNDING | 11 | The ability is in the foregrounding state. | 
| BACKGROUNDING | 12 | The ability is in the backgrounding state. | 

## updateConfiguration

updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void

Updates the configuration. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core
 
**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-application-configuration.md)   | Yes   | New configuration.|
| callback  | AsyncCallback\<void>                   | Yes   | Callback used to return the result.     |

**Example**

```ts
import abilitymanager from '@ohos.application.abilityManager';

var config = {
  language: 'chinese' 
}

abilitymanager.updateConfiguration(config, () => {
    console.log('------------ updateConfiguration -----------');
})
```

## updateConfiguration

updateConfiguration(config: Configuration): Promise\<void>

Updates the configuration. This API uses a promise to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-application-configuration.md)   | Yes   | New configuration.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import abilitymanager from '@ohos.application.abilityManager';

var config = {
  language: 'chinese' 
}

abilitymanager.updateConfiguration(config).then(() => {
  console.log('updateConfiguration success');
}).catch((err) => {
  console.log('updateConfiguration fail');
})
```

## getAbilityRunningInfos

getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void

Obtains the ability running information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<AbilityRunningInfo>>  | Yes   | Callback used to return the result.     |

**Example**

```ts
import abilitymanager from '@ohos.application.abilityManager';

abilitymanager.getAbilityRunningInfos((err,data) => { 
    console.log("getAbilityRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```

## getAbilityRunningInfos

getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>

Obtains the ability running information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<Array\<AbilityRunningInfo>> | Promise used to return the result.|

**Example**

```ts
import abilitymanager from '@ohos.application.abilityManager';
 
abilitymanager.getAbilityRunningInfos().then((data) => {
    console.log("getAbilityRunningInfos  data: " + JSON.stringify(data))
}).catch((err) => {
  console.log("getAbilityRunningInfos err: "  + err)
});
```

## getExtensionRunningInfos<sup>9+</sup>

getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void

Obtains the extension running information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | Yes| Maximum number of messages that can be obtained.|
| callback  | AsyncCallback\<Array\<AbilityRunningInfo>>  | Yes   | Callback used to return the result.     |

**Example**

```ts
import abilitymanager from '@ohos.application.abilityManager';

var upperLimit = 0;

abilitymanager.getExtensionRunningInfos(upperLimit, (err,data) => { 
    console.log("getExtensionRunningInfos err: "  + err + " data: " + JSON.stringify(data));
});
```

## getExtensionRunningInfos<sup>9+</sup>

getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>

Obtains the extension running information. This API uses a promise to return the result.
 
**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | Yes| Maximum number of messages that can be obtained.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<Array\<AbilityRunningInfo>> | Promise used to return the result.|

**Example**

```ts
import abilitymanager from '@ohos.application.abilityManager';

var upperLimit = 0;

abilitymanager.getExtensionRunningInfos(upperLimit).then((data) => {
  console.log("getAbilityRunningInfos data: " + JSON.stringify(data));
}).catch((err) => {
  console.log("getAbilityRunningInfos err: "  + err);
})
```

## getTopAbility<sup>9+</sup>

getTopAbility(callback: AsyncCallback\<ElementName>): void;

Obtains the top ability, which is the ability that has the window focus. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<ElementName>  | Yes   | Callback used to return the result.     |

**Example**

```ts
import abilitymanager from '@ohos.application.abilityManager';

abilitymanager.getTopAbility((err,data) => { 
    console.log("getTopAbility err: "  + err + " data: " + JSON.stringify(data));
});
```

## getTopAbility<sup>9+</sup>

getTopAbility(): Promise\<ElementName>;

Obtains the top ability, which is the ability that has the window focus. This API uses a promise to return the result.
 
**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<ElementName>| Promise used to return the result.|

**Example**

```ts
import abilitymanager from '@ohos.application.abilityManager';

abilitymanager.getTopAbility().then((data) => {
  console.log("getTopAbility data: " + JSON.stringify(data));
}).catch((err) => {
  console.log("getTopAbility err: "  + err);
})
```
