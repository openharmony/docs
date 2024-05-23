# Ability Subsystem Changelog

## cl.ability.1 Permission Changed for Calling autoStartupManager APIs
**Access Level**

System APIs

**Reason for the Change**

Permission verification is not performed when any of the following APIs is called: **on**, **off**, **setApplicationAutoStartup**, **cancelApplicationAutoStartup**, and **queryAllAutoStartupApplications**. Only system application verification is performed. This poses security risks.

**Change Impact**

The API calling permission is changed.

The APIs can be used only after the corresponding permission is configured.

**API Level**

11

**Change Since**

Openharmony SDK OpenHarmony_4.1.5.5

**Key API/Component Changes**
| API| Before Change| After Change|
| ------- | ----- | ------ |
| on(type: 'systemAutoStartup', callback: AutoStartupCallback)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| off(type: 'systemAutoStartup', callback: AutoStartupCallback)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| setApplicationAutoStartup(info: AutoStartupInfo)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| cancelApplicationAutoStartup(info: AutoStartupInfo)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| queryAllAutoStartupApplications(info: AutoStartupInfo, callback: AsyncCallback<void>)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|
| queryAllAutoStartupApplications(info: AutoStartupInfo)| No permission control| The **ohos.permission.MANAGE_APP_BOOT** permission is required.|

**Adaptation Guide**

Declare the corresponding permission before calling any of the following APIs: **on**, **off**, **setApplicationAutoStartup** (in both callback and promise modes), **cancelApplicationAutoStartup** (in both callback and promise modes), and **queryAllAutoStartupApplications** (in both callback and promise modes).

## cl.ability.2 Permission Changed for startAbilityByCall

**Access Level**

Public APIs

**Reason for the Change**

The **startAbilityByCall** API is a public API and does not match the **ohos.permission.ABILITY_BACKGROUND_COMMUNICATION** permission level. The permission level should be **ohos.permission.DISTRIBUTED_DATASYNC**.

**Change Impact**

The API calling permission is changed.

The APIs can be used only after the corresponding permission is configured.

After the change, the API can be used only in migration scenarios. The corresponding system API will be provided to support more scenarios.

**API Level**

9

**Change Since**

Openharmony SDK OpenHarmony_4.1.6.1

**Key API/Component Changes**

| API| Before Change| After Change|
| ------- | ----- | ------ |
| startAbilityByCall(want: Want): Promise\<Caller> | The **ohos.permission.ABILITY_BACKGROUND_COMMUNICATION** permission is required| The **ohos.permission.DISTRIBUTED_DATASYNC** permission is required.|

**Adaptation Guide**

Declare the **ohos.permission.DISTRIBUTED_DATASYNC** permission, and use the API only in migration scenarios.

## cl.ability.3 Auto Startup Related APIs in ApplicationContext Are Deleted

**Access Level**

Public API

**Reason for Change**

According to security and privacy requirements, APIs related to auto startup in **ApplicationContext** are deleted. Applications cannot proactively set the auto startup status.

**Change Impact**

This change is a non-compatible change. If your code uses the involved APIs, delete them.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

```js
  on(type: 'abilityAutoStartup', callback: AutoStartupCallback): void;
  off(type: 'abilityAutoStartup', callback?: AutoStartupCallback): void;
  setAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>): void;
  setAutoStartup(info: AutoStartupInfo): Promise<void>;
  cancelAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>): void;
  cancelAutoStartup(info: AutoStartupInfo): Promise<void>;
  isAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<boolean>): void;
  isAutoStartup(info: AutoStartupInfo): Promise<boolean>;
```

- Before change:

  ```js
     /**
     * Register the listener that watches for current application auto startup state.
     *
     * @param { 'abilityAutoStartup' } type - Indicates the type of event.
     * @param { AutoStartupCallback } callback - Auto startup callback.
     * @throws { BusinessError } 401 - The parameter check failed.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    on(type: 'abilityAutoStartup', callback: AutoStartupCallback): void;
  
    /**
     * Unregister listener that watches for current application auto startup state.
     *
     * @param { 'abilityAutoStartup' } type - Indicates the type of event.
     * @param { AutoStartupCallback } [callback] - Auto startup callback.
     * @throws { BusinessError } 401 - The parameter check failed.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    off(type: 'abilityAutoStartup', callback?: AutoStartupCallback): void;
  
    /**
     * Set current application auto startup state.
     *
     * @param { AutoStartupInfo } info - The application info.
     * @param { AsyncCallback<void> } callback - The callback of setAutoStartup.
     * @throws { BusinessError } 401 - The parameter check failed.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    setAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>): void;
  
    /**
     * Set current application auto startup state.
     *
     * @param { AutoStartupInfo } info - The application info.
     * @returns { Promise<void> } The promise returned by the function.
     * @throws { BusinessError } 401 - The parameter check failed.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    setAutoStartup(info: AutoStartupInfo): Promise<void>;
  
    /**
     * Cancel current application auto startup state.
     *
     * @param { AutoStartupInfo } info - The application info.
     * @param { AsyncCallback<void> } callback - The callback of cancelAutoStartup.
     * @throws { BusinessError } 401 - The parameter check failed.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    cancelAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>): void;
  
    /**
     * Cancel current application auto startup state.
     *
     * @param { AutoStartupInfo } info - The application info.
     * @returns { Promise<void> } The promise returned by the function.
     * @throws { BusinessError } 401 - The parameter check failed.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    cancelAutoStartup(info: AutoStartupInfo): Promise<void>;
  
    /**
     * Check if the current application is auto startup state.
     *
     * @param { AutoStartupInfo } info - The application info.
     * @param { AsyncCallback<boolean> } callback - The callback of isAutoStartup.
     * @throws { BusinessError } 401 - The parameter check failed.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    isAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<boolean>): void;
  
    /**
     * Check if the current application is auto startup state.
     *
     * @param { AutoStartupInfo } info - The application info.
     * @returns { Promise<boolean> } The promise returned by the function.
     * @throws { BusinessError } 401 - The parameter check failed.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    isAutoStartup(info: AutoStartupInfo): Promise<boolean>;
  ```

**Adaptation Guide**

Delete the involved APIs from your code.


## cl.ability.4 Permission for Using AutoStartupInfo Is Changed

**Access Level**

Public API

**Reason for Change**

After the APIs related to auto startup in **ApplicationContext** are deleted, **AutoStartupInfo** is not available for third-party applications and is changed to a system API.

**Change Impact**

This change is a non-compatible change. If your code uses the involved APIs, delete them.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

```js
  AutoStartupInfo {
    bundleName: string;
    moduleName?: string;
    abilityName: string;
    abilityTypeName?: string;
  }
```

- Before change:

  ```js
    /**
     * Bundle name
     *
     * @type { string }
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    bundleName: string;
  
    /**
     * Module name
     *
     * @type { ?string }
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    moduleName?: string;
  
    /**
     * Ability Name
     *
     * @type { string }
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    abilityName: string;
  
    /**
     * Ability Type Name
     *
     * @type { ?string }
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    abilityTypeName?: string;
  ```

- After change:

  ```js
    /**
     * Bundle name
     *
     * @type { string }
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @StageModelOnly
     * @since 11
     */
    bundleName: string;
  
    /**
     * Module name
     *
     * @type { ?string }
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @StageModelOnly
     * @since 11
     */
    moduleName?: string;
  
    /**
     * Ability Name
     *
     * @type { string }
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @StageModelOnly
     * @since 11
     */
    abilityName: string;
  
    /**
     * Ability Type Name
     *
     * @type { ?string }
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @StageModelOnly
     * @since 11
     */
    abilityTypeName?: string;
  ```

**Adaptation Guide**

Make sure the APIs are only invoked by system applications.

The code snippet is as follows:

```ts
import AutoStartupManager from '@ohos.app.ability.autoStartupManager';
import { BusinessError } from '@ohos.base';

try {
  AutoStartupManager.setApplicationAutoStartup({
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


## cl.ability.5 Permission for Using AutoStartupCallback Is Changed
**Access Level**

Public API

**Reason for Change**

After the APIs related to auto startup in **ApplicationContext** are deleted, **AutoStartupCallback** is not available for third-party applications and is changed to a system API.

**Change Impact**

This change is a non-compatible change. If your code uses the involved APIs, delete them.

**API Level**

11

**Change Since**

OpenHarmony SDK 4.1.6.5

**Key API/Component Changes**

- Involved API:

  ```js
    onAutoStartupOn(info: AutoStartupInfo): void;
    onAutoStartupOff(info: AutoStartupInfo): void;
  ```

- Before change:

  ```js
    /**
     * When the application's auto startup state is set to on, this function is called.
     *
     * @param { AutoStartupInfo } info - Auto startup info.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    onAutoStartupOn(info: AutoStartupInfo): void;
  
    /**
     * When the application's auto startup state is set to off, this function is called.
     *
     * @param { AutoStartupInfo } info - Auto startup info.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @StageModelOnly
     * @since 11
     */
    onAutoStartupOff(info: AutoStartupInfo): void;
  ```

- After change:

  ```js
    /**
     * When the application's auto startup state is set to on, this function is called.
     *
     * @param { AutoStartupInfo } info - Auto startup info.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @StageModelOnly
     * @since 11
     */
    onAutoStartupOn(info: AutoStartupInfo): void;
  
    /**
     * When the application's auto startup state is set to off, this function is called.
     *
     * @param { AutoStartupInfo } info - Auto startup info.
     * @syscap SystemCapability.Ability.AbilityRuntime.Core
     * @systemapi
     * @StageModelOnly
     * @since 11
     */
    onAutoStartupOff(info: AutoStartupInfo): void;
  ```

**Adaptation Guide**

Make sure the APIs are only invoked by system applications.

The code snippet is as follows:

```ts
import AutoStartupManager from '@ohos.app.ability.autoStartupManager';
import common from '@ohos.app.ability.common';

try {
  AutoStartupManager.on('systemAutoStartup', {
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
