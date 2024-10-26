# @ohos.app.ability.abilityManager (AbilityManager) (System API)

The AbilityManager module provides APIs for obtaining, adding, and updating ability running information and state information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## AbilityState

Enumerates the ability states. This enum can be used together with [AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo-sys.md) to return the ability state. 

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description| 
| -------- | -------- | -------- |
| INITIAL | 0 | The ability is in the initial state.| 
| FOCUS | 2 | The ability has the focus.|
| FOREGROUND | 9 | The ability is in the foreground state. | 
| BACKGROUND | 10 | The ability is in the background state. | 
| FOREGROUNDING | 11 | The ability is in the state of being switched to the foreground. | 
| BACKGROUNDING | 12 | The ability is in the state of being switched to the background. | 

## UserStatus<sup>12+</sup>

Enumerates the assertion result for different user operations.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| ASSERT_TERMINATE | 0 | Assertion result of the terminate operation.|
| ASSERT_CONTINUE | 1 | Assertion result of the continue operation.|
| ASSERT_RETRY | 2 | Assertion result of the retry operation.|

## updateConfiguration

updateConfiguration(config: Configuration, callback: AsyncCallback\<void>): void

Updates the configuration. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core
 
**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-app-ability-configuration.md)   | Yes   | New configuration. You only need to configure the items to be updated.|
| callback  | AsyncCallback\<void>                   | Yes   | Callback used to return the API call result. You can perform error handling or custom processing in it.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager, Configuration, ConfigurationConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const config: Configuration = {
  language: 'Zh-Hans',                 // Simplified Chinese.
  colorMode: ConfigurationConstant.ColorMode.COLOR_MODE_LIGHT,         // Light theme.
  direction: ConfigurationConstant.Direction.DIRECTION_VERTICAL,       // Vertical direction.
  screenDensity: ConfigurationConstant.ScreenDensity.SCREEN_DENSITY_SDPI,  // The screen pixel density is 'sdpi'.
  displayId: 1,                        // The application is displayed on the display with ID 1.
  hasPointerDevice: true,              // A pointer device is connected.
};

try {
  abilityManager.updateConfiguration(config, (err: BusinessError) => {
    if (err) {
      console.error(`updateConfiguration fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log('updateConfiguration success.');
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## updateConfiguration

updateConfiguration(config: Configuration): Promise\<void>

Updates the configuration. This API uses a promise to return the result.

**System API**: This is a system API.

**Permission required**: ohos.permission.UPDATE_CONFIGURATION

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| config    | [Configuration](js-apis-app-ability-configuration.md)   | Yes   | New configuration. You only need to configure the items to be updated.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<void> | Promise used to return the API call result. You can perform error handling or custom processing in it.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager, Configuration, ConfigurationConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';;

const config: Configuration = {
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
  }).catch((err: BusinessError) => {
    console.error(`updateConfiguration fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## getAbilityRunningInfos

getAbilityRunningInfos(callback: AsyncCallback\<Array\<AbilityRunningInfo>>): void

Obtains the UIAbility running information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo-sys.md)>>  | Yes   | Callback used to return the API call result and the ability running information. You can perform error handling or custom processing in it.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.getAbilityRunningInfos((err: BusinessError, data: Array<abilityManager.AbilityRunningInfo>) => {
    if (err) {
      console.error(`getAbilityRunningInfos fail, error: ${JSON.stringify(err)}`);
    } else {
      console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## getAbilityRunningInfos

getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>

Obtains the UIAbility running information. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo-sys.md)>> | Promise used to return the API call result and the UIAbility running information. You can perform error handling or custom processing in it.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.getAbilityRunningInfos().then((data: Array<abilityManager.AbilityRunningInfo>) => {
    console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`getAbilityRunningInfos fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## getExtensionRunningInfos

getExtensionRunningInfos(upperLimit: number, callback: AsyncCallback\<Array\<ExtensionRunningInfo>>): void

Obtains the ExtensionAbility running information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | Yes| Maximum number of messages that can be obtained. The maximum value is 2<sup>31</sup>-1.|
| callback  | AsyncCallback\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo-sys.md)>>  | Yes   | Callback used to return the API call result and the ExtensionAbility running information. You can perform error handling or custom processing in it.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let upperLimit = 10;

try {
  abilityManager.getExtensionRunningInfos(upperLimit, (err: BusinessError, data: Array<abilityManager.ExtensionRunningInfo>) => {
    if (err) {
      console.error(`getExtensionRunningInfos fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`getExtensionRunningInfos success, data: ${JSON.stringify(data)}`);
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## getExtensionRunningInfos

getExtensionRunningInfos(upperLimit: number): Promise\<Array\<ExtensionRunningInfo>>

Obtains the ExtensionAbility running information. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| upperLimit | number                                   | Yes| Maximum number of messages that can be obtained. The maximum value is 2<sup>31</sup>-1.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<Array\<[ExtensionRunningInfo](js-apis-inner-application-extensionRunningInfo-sys.md)>> | Promise used to return the API call result and the ExtensionAbility running information. You can perform error handling or custom processing in it.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let upperLimit = 10;

try {
  abilityManager.getExtensionRunningInfos(upperLimit).then((data: Array<abilityManager.ExtensionRunningInfo>) => {
    console.log(`getExtensionRunningInfos success, data: ${JSON.stringify(data)}`);
  }).catch((err: BusinessError) => {
    console.error(`getExtensionRunningInfos fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## getTopAbility

getTopAbility(callback: AsyncCallback\<ElementName>): void

Obtains the top ability, which is the ability that has the window focus. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<[ElementName](js-apis-bundleManager-elementName.md)>  | Yes   | Callback used to return the API call result and the element name of the top ability. You can perform error handling or custom processing in it.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

abilityManager.getTopAbility((err: BusinessError, data) => {
  if (err) {
    console.error(`getTopAbility fail, err: ${JSON.stringify(err)}`);
  } else {
    console.log(`getTopAbility success, data: ${JSON.stringify(data)}`);
  }
});
```

## getTopAbility

getTopAbility(): Promise\<ElementName>

Obtains the top ability, which is the ability that has the window focus. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<[ElementName](js-apis-bundleManager-elementName.md)>| Promise used to return the API call result and the element name of the top ability. You can perform error handling or custom processing in it.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

abilityManager.getTopAbility().then((data) => {
  console.log(`getTopAbility success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getTopAbility fail, err: ${JSON.stringify(err)}`);
});
```

## acquireShareData<sup>10+</sup>

acquireShareData(missionId: number, callback: AsyncCallback\<Record\<string, Object>>): void

Called by a system dialog box to obtain shared data, which is set by the target UIAbility through **onShare()**. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| missionId | number                                   | Yes| Mission ID on the target application. The maximum value is 2<sup>31</sup>-1.|
| callback  | AsyncCallback\<Record\<string, Object>>  | Yes   | Callback used to return the API call result and the shared data. You can perform error handling or custom processing in it.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.acquireShareData(1, (err: BusinessError, wantParam: Record<string, Object>) => {
    if (err) {
      console.error(`acquireShareData fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`acquireShareData success, data: ${JSON.stringify(wantParam)}`);
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## acquireShareData<sup>10+</sup>

acquireShareData(missionId: number): Promise\<Record\<string, Object>>

Called by a system dialog box to obtain shared data, which is set by the target UIAbility through **onShare()**. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| missionId | number                                   | Yes| Mission ID on the target application. The maximum value is 2<sup>31</sup>-1.|

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise\<Record\<string, Object>>| Promise used to return the API call result and the shared data. You can perform error handling or custom processing in it.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.acquireShareData(1).then((wantParam: Record<string, Object>) => {
    console.log(`acquireShareData success, data: ${JSON.stringify(wantParam)}`);
  }).catch((err: BusinessError) => {
    console.error(`acquireShareData fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## notifySaveAsResult<sup>10+</sup>

notifySaveAsResult(parameter: AbilityResult, requestCode: number, callback: AsyncCallback\<void>): void

Used by the [Data Loss Prevention (DLP)](../apis-data-protection-kit/js-apis-dlppermission.md) management application to notify a sandbox application of the data saving result. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Information returned to the initiator UIAbility.|
| requestCode | number                                        | Yes| Request code passed in by the DLP management application.         |
| callback  | AsyncCallback<void\>                             | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.        |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let resultCode = 100;
// AbilityResult information returned to the initiator of the save-as behavior.
let abilityResult: common.AbilityResult = {
  want,
  resultCode
};
let requestCode = 1;
try {
  abilityManager.notifySaveAsResult(abilityResult, requestCode, (err: BusinessError) => {
    if (err && err.code != 0) {
      console.error(`notifySaveAsResult fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`notifySaveAsResult success`);
    }
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## notifySaveAsResult<sup>10+</sup>

notifySaveAsResult(parameter: AbilityResult, requestCode: number): Promise\<void>

Used by the [Data Loss Prevention (DLP)](../apis-data-protection-kit/js-apis-dlppermission.md) management application to notify a sandbox application of the data saving result. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes| Information returned to the initiator UIAbility.|
| requestCode | number                                        | Yes| Request code passed in by the DLP management application.         |

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| Promise<void\>| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager, Want, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let resultCode = 100;
// AbilityResult information returned to the initiator of the save-as behavior.
let abilityResult: common.AbilityResult = {
  want,
  resultCode
};
let requestCode = 1;
try {
  abilityManager.notifySaveAsResult(abilityResult, requestCode).then(() => {
    console.log(`notifySaveAsResult success`);
  }).catch((err: BusinessError) => {
    console.error(`notifySaveAsResult fail, err: ${JSON.stringify(err)}`);
  });
} catch (paramError) {
  let code: number = (paramError as BusinessError).code;
  let message: string = (paramError as BusinessError).message;
  console.error(`error.code: ${code}, error.message: ${message}`);
}
```

## abilityManager.on('abilityForegroundState')<sup>11+</sup>

on(type: 'abilityForegroundState', observer: AbilityForegroundStateObserver): void

Registers an observer to listen for ability start or exit events.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RUNNING_STATE_OBSERVER

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. It is fixed at **'abilityForegroundState'**.|
| observer | [AbilityForegroundStateObserver](js-apis-inner-application-abilityForegroundStateObserver-sys) | Yes| Observer used to listen for ability start or exit events.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer: abilityManager.AbilityForegroundStateObserver = {
  onAbilityStateChanged(abilityStateData) {
    console.log(`onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
};
try {
  abilityManager.on('abilityForegroundState', observer);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```

## abilityManager.off('abilityForegroundState')<sup>11+</sup>

off(type: 'abilityForegroundState', observer?: AbilityForegroundStateObserver): void

Unregisters the observer used to listen for ability start or exit events.

**System API**: This is a system API.

**Required permissions**: ohos.permission.RUNNING_STATE_OBSERVER

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. It is fixed at **'abilityForegroundState'**.|
| observer | [AbilityForegroundStateObserver](js-apis-inner-application-abilityForegroundStateObserver-sys) | No| Observer used to listen for ability start or exit events. If this parameter is not set, all observers associated with the specified event are deregistered. If this parameter is set, only the specified observer is deregistered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let observer_: abilityManager.AbilityForegroundStateObserver | undefined;
// 1. Register an observer to listen for ability start or exit events.
let observer: abilityManager.AbilityForegroundStateObserver = {
  onAbilityStateChanged(abilityStateData: abilityManager.AbilityStateData) {
    console.log(`onAbilityStateChanged: ${JSON.stringify(abilityStateData)}`);
  },
};
try {
  abilityManager.on('abilityForegroundState', observer);
  observer_ = observer;
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}

// 2. Deregister the observer.
try {
  abilityManager.off('abilityForegroundState',  observer_);
} catch (paramError) {
  let code = (paramError as BusinessError).code;
  let message = (paramError as BusinessError).message;
  console.error(`error: ${code}, ${message} `);
}
```

## abilityManager.getForegroundUIAbilities<sup>11+</sup>

getForegroundUIAbilities(callback: AsyncCallback\<Array\<AbilityStateData>>): void

Obtains the information about the UIAbilities of an application that is running in the foreground. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback\<Array\<[AbilityStateData](js-apis-inner-application-abilityStateData-sys.md)>>  | Yes|Callback used to return the API call result and the UIAbility information. You can perform error handling or custom processing in it.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

abilityManager.getForegroundUIAbilities((err: BusinessError, data: Array<abilityManager.AbilityStateData>) => {
  if (err) {
    console.error(`Get foreground ui abilities failed, error: ${JSON.stringify(err)}`);
  } else {
    console.log(`Get foreground ui abilities data is: ${JSON.stringify(data)}`);
  }
});
```

## abilityManager.getForegroundUIAbilities<sup>11+</sup>

getForegroundUIAbilities(): Promise\<Array\<AbilityStateData>>

Obtains the information about the UIAbilities of an application that is running in the foreground. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_RUNNING_INFO

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[AbilityStateData](js-apis-inner-application-abilityStateData-sys.md)>> | Promise used to return the API call result and the UIAbility information. You can perform error handling or custom processing in it.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

abilityManager.getForegroundUIAbilities().then((data: Array<abilityManager.AbilityStateData>) => {
  console.log(`Get foreground ui abilities data is: ${JSON.stringify(data)}`);
}).catch((error: BusinessError) => {
  console.error(`Get foreground ui abilities failed, error: ${JSON.stringify(error)}`);
});
```

## abilityManager.notifyDebugAssertResult<sup>12+</sup>

notifyDebugAssertResult(sessionId: string, status: UserStatus): Promise\<void>

Notifies the application of the assertion result. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.NOTIFY_DEBUG_ASSERT_RESULT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | -------- | -------- | -------- |
| sessionId | string | Yes| Session ID of the AssertFault.|
| status | [UserStatus](#userstatus12) | Yes| Assertion result of the user operation.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not System App. Interface caller is not a system app. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager, UIExtensionAbility, wantConstant, Want, UIExtensionContentSession } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UiExtAbility extends UIExtensionAbility {
  onSessionCreate(want: Want, session: UIExtensionContentSession): void {
    let sessionId: string = '';
    if (want.parameters) {
      sessionId = want.parameters[wantConstant.Params.ASSERT_FAULT_SESSION_ID] as string;
    }
    let status = abilityManager.UserStatus.ASSERT_TERMINATE;
    abilityManager.notifyDebugAssertResult(sessionId, status).then(() => {
      console.log('notifyDebugAssertResult success.');
    }).catch((err: BusinessError) => {
      console.error(`notifyDebugAssertResult failed, error: ${JSON.stringify(err)}`);
    });
  }
}
```

## abilityManager.isEmbeddedOpenAllowed<sup>12</sup>

isEmbeddedOpenAllowed(context: Context, appId: string): Promise\<boolean>

Checks whether the [EmbeddableUIAbility](js-apis-app-ability-embeddableUIAbility.md) can be started in embedded mode. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | -------- | -------- | -------- |
| context | [Context](js-apis-inner-application-context.md) | Yes| Context of the caller.|
| appId | string | Yes| Unique ID of the application, which is allocated by the cloud.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that embedded startup is allowed, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000050 | Internal error. |

**Example**

```ts
import { abilityManager, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let appId: string = '6918661953712445909';
    try {
      abilityManager.isEmbeddedOpenAllowed(this.context, appId).then((data) => {
        console.info(`isEmbeddedOpenAllowed data: ${JSON.stringify(data)}`);
      }).catch((err: BusinessError) => {
        console.error(`isEmbeddedOpenAllowed failed, code is ${err.code}, message is ${err.message}`);
      });
    } catch (err) {
      // Process input parameter errors.
      console.error(`param is invalid, code is ${err.code}, message is ${err.message}`);
    }
  }
}
```

## abilityManager.setResidentProcessEnabled<sup>12+</sup>

setResidentProcessEnabled(bundleName: string, enable: boolean): Promise\<void>

Enables or disables the resident process of an application.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | -------- | -------- | -------- |
| bundleName | string | Yes| Bundle name of the resident process.|
| enable | boolean | Yes| Whether to enable or disable the resident process. The value **true** means to enable the resident process, and **false** means to disable the resident process.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 202 | Not a system application. |
| 401 | Parameter error. Possible cause: 1.Non empty package name needs to be provided, 2.The second parameter needs to provide a Boolean type setting value |
| 16000050 | Internal error. |
| 16200006 | The caller application can only set the resident status of the configured process |

**Example**

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let residentProcessBundleName: string = 'com.xxx.xxxxxx';
  let enable: boolean = false;
  abilityManager.setResidentProcessEnabled(residentProcessBundleName, enable)
    .then(() => {
      console.log('setResidentProcessEnabled success.');
    })
    .catch((err: BusinessError) => {
      console.error(`setResidentProcessEnabled fail, err: ${JSON.stringify(err)}`);
    });
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`setResidentProcessEnabled failed, code is ${code}, message is ${message}`);
}
```
