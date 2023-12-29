# @ohos.app.ability.autoStartupManager (autoStartupManager)

The **autoStartupManager** module provides APIs for listening for auto-startup status changes of application components and setting application components to automatically start upon system boot.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module are system APIs and cannot be called by third-party applications.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import AutoStartupManager from '@ohos.app.ability.autoStartupManager';
```

## on

on(type: 'systemAutoStartup', callback: AutoStartupCallback): void

Subscribes to auto-startup status change events of an application component.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| type | string | Yes   | Event type. The value is fixed at **systemAutoStartup**, which can be called only by system applications. |
| callback  | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback.md)   | Yes   | Callback used for the subscription.     |

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';

let autoStartupCallback = {
  onAutoStartupOn(data) {
    console.info('===> onAutoStartupOn data: ' + JSON.stringify(data));
  },
  onAutoStartupOff(data) {
    console.info('===> onAutoStartupOff data: ' + JSON.stringify(data));
  }
}

try {
  AutoStartupManager.on('systemAutoStartup', autoStartupCallback);
} catch (err) {
  console.info('====> autostartupmanager on throw err: ' + JSON.stringify(err));
}
```

## off

off(type: 'systemAutoStartup', callback?: AutoStartupCallback): void

Unsubscribes from auto-startup status change events of an application component.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| type | string              | Yes   | Event type. The value is fixed at **systemAutoStartup**, which can be called only by system applications. |
| callback | [AutoStartupCallback](js-apis-inner-application-autoStartupCallback.md)   | No| Callback that has been registered to listen for auto-startup status changes.|

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';

let autoStartupCallback = {
  onAutoStartupOn(data) {
    console.info('===> onAutoStartupOn data: ' + JSON.stringify(data));
  },
  onAutoStartupOff(data) {
    console.info('===> onAutoStartupOff data: ' + JSON.stringify(data));
  }
}

try {
  AutoStartupManager.off('systemAutoStartup', autoStartupCallback);
} catch (err) {
  console.info('====> autostartupmanager off throw err: ' + JSON.stringify(err));
}
```

## setApplicationAutoStartup

setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

Sets an application component to automatically start upon system boot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md) | Yes   | Information about the target application component.|
| callback | AsyncCallback\<void\> | Yes| Callback used to return the result. If the setting is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';

try {
  AutoStartupManager.setApplicationAutoStartup({
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

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type           | Mandatory| Description                        |
| ------ | --------------- | ---- | ---------------------------- |
| info   | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md) | Yes  | Information about the target application component.|

**Return value**

| Type         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';

try {
  AutoStartupManager.setApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then((data) => {
    console.info('====> setApplicationAutoStartup data: ' + JSON.stringify(data));
  }).catch((err) => {
    console.info('====> setApplicationAutoStartup err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.info('====> setApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## cancelApplicationAutoStartup

cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback\<void\>): void

Cancels the auto-startup setting for an application component. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md)   | Yes| Information about the target application component.|
| callback | AsyncCallback\<void\> | Yes   | Callback used to return the result. If the cancellation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';

try {
  AutoStartupManager.cancelApplicationAutoStartup({
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

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| info | [AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md)   | Yes| Information about the target application component.|

**Return value**

| Type         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';

try {
  AutoStartupManager.cancelApplicationAutoStartup({
    bundleName: 'com.example.autostartupapp',
    abilityName: 'EntryAbility'
  }).then((data) => {
    console.info('====> cancelApplicationAutoStartup data: ' + JSON.stringify(data));
  }).catch((err) => {
    console.info('====> cancelApplicationAutoStartup err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.info('====> cancelApplicationAutoStartup throw err: ' + JSON.stringify(err));
}
```

## queryAllAutoStartupApplications

queryAllAutoStartupApplications(callback: AsyncCallback\<Array\<AutoStartupInfo\>\>): void

Obtains information about all auto-startup application components. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| callback  | AsyncCallback\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md)\>\> | Yes   | Callback used to return the result. If the information is obtained, **err** is **undefined** and **data** is an array of **<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md)\>** objects; otherwise, **err** is an error object.     |

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';

try {
  AutoStartupManager.queryAllAutoStartupApplications((err, data) => {
    console.info('====> queryAllAutoStartupApplications err: ' + JSON.stringify(err) + ' data: ' + JSON.stringify(data));
  });
} catch (err) {
  console.info('====> queryAllAutoStartupApplications throw err: ' + JSON.stringify(err));
}
```

## queryAllAutoStartupApplications

 queryAllAutoStartupApplications(): Promise\<Array\<AutoStartupInfo\>\>

Obtains information about all auto-startup application components. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[AutoStartupInfo](js-apis-inner-application-autoStartupInfo.md)\>\> | Promise used to return the information obtained.|

**Example**

```ts
import AutoStartupManager from '@ohos.app.ability.AutoStartupManager';

try {
  AutoStartupManager.queryAllAutoStartupApplications().then((data) => {
    console.info('====> queryAllAutoStartupApplications OK');
  }).catch((err) => {
    console.info('====> queryAllAutoStartupApplications err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.info('====> queryAllAutoStartupApplications throw err: ' + JSON.stringify(err));
}
```
