# @ohos.app.ability.abilityManager (AbilityManager)

The **AbilityManager** module provides APIs for obtaining, adding, and updating ability running information and state information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```ts
import abilityManager from '@ohos.app.ability.abilityManager';
```

## AbilityState

Enumerates the ability states. This enum can be used together with [AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md) to return the ability state.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This enum is an internal definition of a system API and cannot be called by third-party applications.

| Name| Value| Description| 
| -------- | -------- | -------- |
| INITIAL | 0 | The ability is in the initial state.| 
| FOCUS | 2 | The ability has the focus. |
| FOREGROUND | 9 | The ability is in the foreground state. | 
| BACKGROUND | 10 | The ability is in the background state. | 
| FOREGROUNDING | 11 | The ability is in the state of being switched to the foreground. | 
| BACKGROUNDING | 12 | The ability is in the state of being switched to the background.  | 

## updateConfiguration

updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void

Updates the configuration. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core
 
**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-app-ability-configuration.md)   | Yes   | New configuration. You only need to configure the items to be updated.|
| callback  | AsyncCallback\<void>                   | Yes   | Callback used to return the API call result. You can perform error handling or custom processing in this callback.     |

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';
import ConfigurationConstant from '@ohos.app.ability.ConfigurationConstant';

const config = {
  language: 'Zh-Hans',                 // Simplified Chinese.
  colorMode: ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT,         // Light theme.
  direction: ConfigurationConstant.Direction.DIRECTION_VERTICAL,       // Vertical direction.
  screenDensity: ConfigurationConstant.ScreenDensity.SCREEN_DENSITY_SDPI,  // The screen pixel density is 'sdpi'.
  displayId: 1,                        // The application is displayed on the display with ID 1.
  hasPointerDevice: true,              // A pointer device is connected.
};

try {
    abilityManager.updateConfiguration(config, (err) => {
        if (err.code !== 0) {
            console.log('updateConfiguration fail, err: ' + JSON.stringify(err));
        } else {
            console.log('updateConfiguration success.');
        }
    });
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code)
        + ' error.message: ' + JSON.stringify(paramError.message));
}
```

## updateConfiguration

updateConfiguration(config: Configuration): Promise\<void>

Updates the configuration. This API uses a promise to return the result.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-app-ability-configuration.md)   | Yes   | New configuration. You only need to configure the items to be updated.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<void> | Promise used to return the API call result. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';
import ConfigurationConstant from '@ohos.app.ability.ConfigurationConstant';

const config = {
  language: 'Zh-Hans',                 // Simplified Chinese.
  colorMode: ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT,         // Light theme.
  direction: ConfigurationConstant.Direction.DIRECTION_VERTICAL,       // Vertical direction.
  screenDensity: ConfigurationConstant.ScreenDensity.SCREEN_DENSITY_SDPI,  // The screen pixel density is 'sdpi'.
  displayId: 1,                        // The application is displayed on the display with ID 1.
  hasPointerDevice: true,              // A pointer device is connected.
};

try {
    abilityManager.updateConfiguration(config).then(() => {
        console.log('updateConfiguration success.');
    }).catch((err) => {
        console.log('updateConfiguration fail, err: ' + JSON.stringify(err));
    });
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code)
        + ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getAbilityRunningInfos

getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void

Obtains the UIAbility running information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>>  | Yes   | Callback used to return the API call result and the UIAbility running information. You can perform error handling or custom processing in this callback.     |

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';

try {
    abilityManager.getAbilityRunningInfos((err, data) => {
        if (err.code !== 0) {
            console.log('getAbilityRunningInfos fail, error: ' + JSON.stringify(err));
        } else {
            console.log('getAbilityRunningInfos success, data: ' + JSON.stringify(data));
        }
    });
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code)
        + ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getAbilityRunningInfos

getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>

Obtains the UIAbility running information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>> | Promise used to return the API call result and the UIAbility running information. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';

try {
    abilityManager.getAbilityRunningInfos().then((data) => {
        console.log('getAbilityRunningInfos success, data: ' + JSON.stringify(data));
    }).catch((err) => {
        console.log('getAbilityRunningInfos fail, err: '  + JSON.stringify(err));
    });
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code)
        + ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getExtensionRunningInfos

getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void

Obtains the ExtensionAbility running information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | Yes| Maximum number of messages that can be obtained. The maximum value is 2<sup>31</sup>-1.|
| callback  | AsyncCallback\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo.md)>>  | Yes   | Callback used to return the API call result and the ExtensionAbility running information. You can perform error handling or custom processing in this callback.     |

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';

let upperLimit = 10;

try {
    abilityManager.getExtensionRunningInfos(upperLimit, (err, data) => { 
        if (err.code !== 0) {
            console.log('getExtensionRunningInfos fail, err: ' + JSON.stringify(err));
        } else {
            console.log('getExtensionRunningInfos success, data: ' + JSON.stringify(data));
        }
    });
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code)
        + ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getExtensionRunningInfos

getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>

Obtains the ExtensionAbility running information. This API uses a promise to return the result.
 
**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | Yes| Maximum number of messages that can be obtained. The maximum value is 2<sup>31</sup>-1.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo.md)>> | Promise used to return the API call result and the ExtensionAbility running information. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';

let upperLimit = 10;

try {
    abilityManager.getExtensionRunningInfos(upperLimit).then((data) => {
        console.log('getExtensionRunningInfos success, data: ' + JSON.stringify(data));
    }).catch((err) => {
        console.log('getExtensionRunningInfos fail, err: '  + JSON.stringify(err));
    });
} catch (paramError) {
    console.log('error.code: ' + JSON.stringify(paramError.code)
        + ' error.message: ' + JSON.stringify(paramError.message));
}
```

## getTopAbility<sup>9+</sup>

getTopAbility(callback: AsyncCallback\<ElementName>): void;

Obtains the top ability, which is the ability that has the window focus. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<[ElementName](js-apis-bundleManager-elementName.md)>  | Yes   | Callback used to return the API call result and the element name of the top ability. You can perform error handling or custom processing in this callback.     |

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';

abilityManager.getTopAbility((err, data) => { 
    if (err.code !== 0) {
        console.log('getTopAbility fail, err: ' + JSON.stringify(err));
    } else {
        console.log('getTopAbility success, data: ' + JSON.stringify(data));
    }
});
```

## getTopAbility

getTopAbility(): Promise\<ElementName>;

Obtains the top ability, which is the ability that has the window focus. This API uses a promise to return the result.
 
**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<[ElementName](js-apis-bundleManager-elementName.md)>| Promise used to return the API call result and the element name of the top ability. You can perform error handling or custom processing in this callback.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
import abilityManager from '@ohos.app.ability.abilityManager';

abilityManager.getTopAbility().then((data) => {
    console.log('getTopAbility success, data: ' + JSON.stringify(data));
}).catch((err) => {
    console.log('getTopAbility fail, err: '  + JSON.stringify(err));
});
```
