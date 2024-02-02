# 元能力子系统变更说明

## cl.ability.1 ApplicationContext开机自启动接口删除

**访问级别**

公开接口。

**变更原因**

根据安全隐私要求，删除ApplicationContext开机自启动接口，应用无法主动申请和设置自启状态。

**变更影响**

该变更为非兼容性变更。基于此前版本开发的应用，需删除ApplicationContext开机自启动接口使用，变更前的接口已经不能正常使用，否则会影响原有功能。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

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

- 变更前：

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

**适配指导**

该类接口下线后，应用已无法使用该类接口。


## cl.ability.2 AutoStartupInfo接口使用权限变更

**访问级别**

公开接口。

**变更原因**

ApplicationContext开机自启动接口删除后，AutoStartupInfo接口无三方应用使用场景，变更为系统接口。

**变更影响**

该变更为非兼容性变更。基于此前版本开发的应用，需删除AutoStartupInfo接口使用，变更前的接口已经不能正常使用，否则会影响原有功能。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

```js
  AutoStartupInfo {
    bundleName: string;
    moduleName?: string;
    abilityName: string;
    abilityTypeName?: string;
  }
```

- 变更前：

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

- 变更后：

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

**适配指导**

该接口变更为系统接口后，三方应用无法使用。
系统应用可正常使用。
示例代码如下：

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


## cl.ability.3 AutoStartupCallback接口使用权限变更
**访问级别**

公开接口。

**变更原因**

ApplicationContext开机自启动接口删除后，AutoStartupCallback接口无三方应用使用场景，变更为系统接口。

**变更影响**

该变更为非兼容性变更。基于此前版本开发的应用，需删除AutoStartupCallback接口使用，变更前的接口已经不能正常使用，否则会影响原有功能。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

- 涉及接口

```js
  onAutoStartupOn(info: AutoStartupInfo): void;
  onAutoStartupOff(info: AutoStartupInfo): void;
```

- 变更前：

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

- 变更后：

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

**适配指导**

该接口变更为系统接口后，三方应用已无法使用。
系统应用可正常使用。
示例代码如下：

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
