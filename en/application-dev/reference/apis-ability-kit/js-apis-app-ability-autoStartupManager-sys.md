# @ohos.app.ability.autoStartupManager (autoStartupManager) (System API)

The **autoStartupManager** module provides APIs for listening for auto-startup status changes of application components and setting application components to automatically start upon system boot.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { autoStartupManager } from '@kit.AbilityKit';
```

## on

on(type: 'systemAutoStartup', callback: AutoStartupCallback): void

Subscribes to auto-startup status change events of an application component.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| type | string | Yes   | Event type. The value is fixed at **systemAutoStartup**, which can be called only by system applications.|
| callback  | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md)   | Yes   | Callback used for subscription.     |

**Example**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';

try {
  autoStartupManager.on('systemAutoStartup', {
    onAutoStartupOn(data: common.AutoStartupInfo) {
      console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
    },
    onAutoStartupOff(data: common.AutoStartupInfo) {
      console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
    }
  });
} catch (err) {
  console.info('===> autostartupmanager on throw err: ' + JSON.stringify(err));
}
```

## off

off(type: 'systemAutoStartup', callback?: AutoStartupCallback): void

Unsubscribes from auto-startup status change events of an application component.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| type | string              | Yes   | Event type. The value is fixed at **systemAutoStartup**, which can be called only by system applications.|
| callback | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md)   | No| Callback used for unsubscription.|

**Example**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';

try {
  autoStartupManager.off('systemAutoStartup', {
    onAutoStartupOn(data: common.AutoStartupInfo) {
      console.info('===> autostartupmanager onAutoStartupOn data: ' + JSON.stringify(data));
    },
    onAutoStartupOff(data: common.AutoStartupInfo) {
      console.info('===> autostartupmanager onAutoStartupOff data: ' + JSON.stringify(data));
    }
  });
} catch (err) {
  console.info('===> autostartupmanager off throw err: ' + JSON.stringify(err));
}
```

## setApplicationAutoStartup

setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

Sets an application component to automatically start upon system boot. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | Yes   | Information about the target application component.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 16000004 | Failed to start the invisible ability.           |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import { autoStartupManager } from '@kit.AbilityKit';

try {
  autoStartupManager.setApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }, (err, data) => {
    console.info('====> setApplicationAutoStartup: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
  });
} catch (err) {
  console.info('====> setApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## setApplicationAutoStartup

setApplicationAutoStartup(info: AutoStartupInfo): Promise\<void\>

Sets an application component to automatically start upon system boot. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type           | Mandatory| Description                        |
| ------ | --------------- | ---- | ---------------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | Yes  | Information about the target application component.|

**Return value**

| Type         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 16000004 | Failed to start the invisible ability.           |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.setApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then((data: void) => {
    console.info('====> setApplicationAutoStartup data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.info('====> setApplicationAutoStartup err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.info('====> setApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## cancelApplicationAutoStartup

cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

Cancels the auto-startup setting for an application component. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | Yes| Information about the target application component.|
| callback | AsyncCallback\<void\> | Yes   | Callback used to return the result. If the cancellation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 16000004 | Failed to start the invisible ability.           |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import { autoStartupManager } from '@kit.AbilityKit';

try {
  autoStartupManager.cancelApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }, (err, data) => {
    console.info('====> cancelApplicationAutoStartup err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
  });
} catch (err) {
  console.info('====> cancelApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## cancelApplicationAutoStartup

cancelApplicationAutoStartup(info: AutoStartupInfo): Promise\<void\>

Cancels the auto-startup setting for an application component. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | Yes| Information about the target application component.|

**Return value**

| Type         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 16000004 | Failed to start the invisible ability.           |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.cancelApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then((data: void) => {
    console.info('====> cancelApplicationAutoStartup data: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.info('====> cancelApplicationAutoStartup err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.info('====> cancelApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## queryAllAutoStartupApplications

queryAllAutoStartupApplications(callback: AsyncCallback\<Array\<AutoStartupInfo\>\>): void

Obtains information about all auto-startup application components. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>\> | Yes   | Callback used to return the result. If the information is obtained, **err** is **undefined** and **data** is **Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>**; otherwise, **err** is an error object.     |

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import { autoStartupManager } from '@kit.AbilityKit';

try {
  autoStartupManager.queryAllAutoStartupApplications((err, data) => {
    console.info('====> queryAllAutoStartupApplications err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
  });
} catch (err) {
  console.info('====> queryAllAutoStartupApplications throw err: ' + JSON.stringify(err));
}
```

## queryAllAutoStartupApplications

 queryAllAutoStartupApplications(): Promise\<Array\<AutoStartupInfo\>\>

Obtains information about all auto-startup application components. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>\> | Promise used to return the information obtained.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.queryAllAutoStartupApplications().then((autoStartupInfo: common.AutoStartupInfo[]) => {
    console.info('====> queryAllAutoStartupApplications data: ' + JSON.stringify(autoStartupInfo));
  }).catch((err: BusinessError) => {
    console.info('====> queryAllAutoStartupApplications err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.info('====> queryAllAutoStartupApplications throw err: ' + JSON.stringify(err));
}
```
