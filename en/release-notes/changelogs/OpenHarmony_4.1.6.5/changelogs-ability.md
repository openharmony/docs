# Ability Subsystem Changelog

## cl.ability.1 Auto Startup Related APIs in ApplicationContext Are Deleted

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


## cl.ability.2 Permission for Using AutoStartupInfo Is Changed

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


## cl.ability.3 Permission for Using AutoStartupCallback Is Changed
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
