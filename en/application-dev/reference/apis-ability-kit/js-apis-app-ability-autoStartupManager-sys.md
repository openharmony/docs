# @ohos.app.ability.autoStartupManager (autoStartupManager) (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhu-feimo; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The autoStartupManager module provides APIs to listen for auto-startup status changes of application components. You can use the APIs to get updates on these changes.

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

Registers a callback to listen for auto-startup status changes of an application component.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| type | string | Yes   | Event type. The value is fixed at **systemAutoStartup**, which can be called only by system applications.|
| callback  | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md)   | Yes   | Callback used for registration.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| -------- | -------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000050 | Internal error. |

**Example**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.on('systemAutoStartup', {
    onAutoStartupOn(data: common.AutoStartupInfo) {
      console.info(`autostartupmanager onAutoStartupOn, data: ${JSON.stringify(data)}.`);
    },
    onAutoStartupOff(data: common.AutoStartupInfo) {
      console.info(`autostartupmanager onAutoStartupOff, data: ${JSON.stringify(data)}.`);
    }
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`autostartupmanager on failed, err code: ${code}, err msg: ${msg}.`);
}
```

## off

off(type: 'systemAutoStartup', callback?: AutoStartupCallback): void

Unregisters the callback used to listen for auto-startup status changes of an application component.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| type | string              | Yes   | Event type. The value is fixed at **systemAutoStartup**, which can be called only by system applications.|
| callback | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback-sys.md)   | No| Callback used for unregistration.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| -------- | -------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000050 | Internal error. |

**Example**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.off('systemAutoStartup', {
    onAutoStartupOn(data: common.AutoStartupInfo) {
      console.info(`autostartupmanager onAutoStartupOn, data: ${JSON.stringify(data)}.`);
    },
    onAutoStartupOff(data: common.AutoStartupInfo) {
      console.info(`autostartupmanager onAutoStartupOff, data: ${JSON.stringify(data)}.`);
    }
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`autostartupmanager on failed, err code: ${code}, err msg: ${msg}.`);
}
```

## setApplicationAutoStartup

setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

Sets an application component to automatically start upon system boot. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Device behavior differences**
- Starting from API version 18, this API can be properly called on 2-in-1 devices and wearables. If it is called on other device types, error code 16000050 is returned.
- For versions earlier than API version 18, this API can be properly called only on 2-in-1 devices. If it is called on other device types, error code 16000050 is returned.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | Yes   | Information about the target application component.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000004 | Cannot start an invisible component.         |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

**Example**

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.setApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }, (err: BusinessError) => {
    if (err) {
      console.error(`setApplicationAutoStartup failed, err code: ${err.code}, err msg: ${err.message}.`);
      return;
    }
    console.info(`setApplicationAutoStartup success.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`setApplicationAutoStartup failed, err code: ${code}, err msg: ${msg}.`);
}
```

## setApplicationAutoStartup

setApplicationAutoStartup(info: AutoStartupInfo): Promise\<void\>

Sets an application component to automatically start upon system boot. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Device behavior differences**
- Starting from API version 18, this API can be properly called on 2-in-1 devices and wearables. If it is called on other device types, error code 16000050 is returned.
- For versions earlier than API version 18, this API can be properly called only on 2-in-1 devices. If it is called on other device types, error code 16000050 is returned.

**Parameters**

| Name| Type           | Mandatory| Description                        |
| ------ | --------------- | ---- | ---------------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md) | Yes  | Information about the target application component.|

**Return value**

| Type         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000004 | Cannot start an invisible component.         |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

**Example**

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.setApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then((data: void) => {
    console.info(`setApplicationAutoStartup success.`);
  }).catch((err: BusinessError) => {
    console.error(`setApplicationAutoStartup failed, err code: ${err.code}, err msg: ${err.message}.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`setApplicationAutoStartup failed, err code: ${code}, err msg: ${msg}.`);
}
```

## cancelApplicationAutoStartup

cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

Cancels the auto-startup setting for an application component. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Device behavior differences**
- Starting from API version 18, this API can be properly called on 2-in-1 devices and wearables. If it is called on other device types, error code 16000050 is returned.
- For versions earlier than API version 18, this API can be properly called only on 2-in-1 devices. If it is called on other device types, error code 16000050 is returned.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | Yes| Information about the target application component.|
| callback | AsyncCallback\<void\> | Yes   | Callback used to return the result. If the cancellation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000004 | Cannot start an invisible component.         |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

**Example**

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.cancelApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }, (err: BusinessError) => {
    if (err) {
      console.error(`cancelApplicationAutoStartup failed, err code: ${err.code}, msg: ${err.message}.`);
      return;
    }
    console.info(`cancelApplicationAutoStartup success.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`cancelApplicationAutoStartup failed, err code: ${code}, err msg: ${msg}.`);
}
```

## cancelApplicationAutoStartup

cancelApplicationAutoStartup(info: AutoStartupInfo): Promise\<void\>

Cancels the auto-startup setting for an application component. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Device behavior differences**
- Starting from API version 18, this API can be properly called on 2-in-1 devices and wearables. If it is called on other device types, error code 16000050 is returned.
- For versions earlier than API version 18, this API can be properly called only on 2-in-1 devices. If it is called on other device types, error code 16000050 is returned.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)   | Yes| Information about the target application component.|

**Return value**

| Type         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000004 | Cannot start an invisible component.         |
| 16000013 | The application is controlled by EDM.        |
| 16000050 | Internal error.                              |

**Example**

```ts
import { autoStartupManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.cancelApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then(() => {
    console.info(`cancelApplicationAutoStartup success.`);
  }).catch((err: BusinessError) => {
    console.error(`cancelApplicationAutoStartup failed, err code: ${err.code}, msg: ${err.message}.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`cancelApplicationAutoStartup failed, err code: ${code}, err msg: ${msg}.`);
}
```

## queryAllAutoStartupApplications

queryAllAutoStartupApplications(callback: AsyncCallback\<Array\<AutoStartupInfo\>\>): void

Obtains information about all auto-startup application components. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Device behavior differences**
- Starting from API version 18, this API can be properly called on 2-in-1 devices and wearables. If it is called on other device types, error code 16000050 is returned.
- For versions earlier than API version 18, this API can be properly called only on 2-in-1 devices. If it is called on other device types, error code 16000050 is returned.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>\> | Yes   | Callback used to return the result. If the information is obtained, **err** is **undefined** and **data** is **Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>**; otherwise, **err** is an error object.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000050 | Internal error. |

**Example**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.queryAllAutoStartupApplications((err, data: common.AutoStartupInfo[]) => {
    if (err) {
      console.error(`queryAllAutoStartupApplications failed, err code: ${err.code}, err msg: ${err.message}.`);
      return;
    }
    console.info(`queryAllAutoStartupApplications success, data: ${JSON.stringify(data)}.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`queryAllAutoStartupApplications failed, err code: ${code}, err msg: ${msg}.`);
}
```

## queryAllAutoStartupApplications

 queryAllAutoStartupApplications(): Promise\<Array\<AutoStartupInfo\>\>

Obtains information about all auto-startup application components. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_APP_BOOT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Device behavior differences**
- Starting from API version 18, this API can be properly called on 2-in-1 devices and wearables. If it is called on other device types, error code 16000050 is returned.
- For versions earlier than API version 18, this API can be properly called only on 2-in-1 devices. If it is called on other device types, error code 16000050 is returned.

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo-sys.md)\>\> | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied, interface caller does not have permission "ohos.permission.MANAGE_APP_BOOT". |
| 202      | Permission denied, non-system app called system api. |
| 401      | The parameter check failed. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 16000050 | Internal error. |

**Example**

```ts
import { autoStartupManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  autoStartupManager.queryAllAutoStartupApplications().then((data: common.AutoStartupInfo[]) => {
    console.info(`queryAllAutoStartupApplications success, data: ${JSON.stringify(data)}.`);
  }).catch((err: BusinessError) => {
    console.error(`queryAllAutoStartupApplications failed, err code: ${err.code}, err msg: ${err.message}.`);
  });
} catch (err) {
  let code = (err as BusinessError).code;
  let msg = (err as BusinessError).message;
  console.error(`queryAllAutoStartupApplications failed, err code: ${code}, err msg: ${msg}.`);
}
```
