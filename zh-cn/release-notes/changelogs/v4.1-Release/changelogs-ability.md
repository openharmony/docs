# 元能力变更说明

## cl.ability.1 autoStartupManager自启动管理接口权限变更
**访问级别**

系统接口

**变更原因**

此前版本注册监听应用组件开机自启动状态变化、注销监听应用组件开机自启动状态变化、设置应用组件开机自启动、取消应用组件开机自启动及查询自启动应用组件信息接口对调用方只进行系统应用校验，未进行权限校验，存在安全风险，不符合OpenHarmony的API接口规范。

**变更影响**

影响接口调用权限，接口调用权限发生变更。
应用需要配置相应的权限，才可以正常使用。

**API Level**

11

**变更发生版本**

从Openharmony SDK OpenHarmony_4.1.5.5 开始

**变更的接口**
| 接口声明 | 变更前 | 变更后 |
| ------- | ----- | ------ |
| on(type: 'systemAutoStartup', callback: AutoStartupCallback)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| off(type: 'systemAutoStartup', callback: AutoStartupCallback)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| setApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| setApplicationAutoStartup(info: AutoStartupInfo)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| cancelApplicationAutoStartup(info: AutoStartupInfo, callback: AsyncCallback<void>)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| cancelApplicationAutoStartup(info: AutoStartupInfo)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| queryAllAutoStartupApplications(info: AutoStartupInfo, callback: AsyncCallback<void>)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |
| queryAllAutoStartupApplications(info: AutoStartupInfo)| 无权限管控 | 需要ohos.permission.MANAGE_APP_BOOT权限 |

**适配指导**

调用on、off、setApplicationAutoStartup方法(callback方式)、setApplicationAutoStartup方法(promise方式)、cancelApplicationAutoStartup方法(callback方式)、cancelApplicationAutoStartup方法(promise方式)、queryAllAutoStartupApplications方法(callback方式)、queryAllAutoStartupApplications方法(promise方式)接口时，需申请相应的权限才可正常使用。

## cl.ability.2 startAbilityByCall接口权限变更

**访问级别**

公开接口

**变更原因**

该接口为公开接口，与ohos.permission.ABILITY_BACKGROUND_COMMUNICATION权限级别不匹配，需要将接口权限修改为ohos.permission.DISTRIBUTED_DATASYNC权限，降低权限级别。

**变更影响**

影响接口调用权限，接口调用权限发生变更。
应用需要配置相应的权限，才可以正常使用。
变更后接口仅支持迁移场景下使用，后续将新增对应系统接口，支持更多场景使用。

**API Level**

9

**变更发生版本**

从Openharmony SDK OpenHarmony_4.1.6.1 开始

**变更的接口**

| 接口声明 | 变更前 | 变更后 |
| ------- | ----- | ------ |
| startAbilityByCall(want: Want): Promise<Caller> | 需要ohos.permission.ABILITY_BACKGROUND_COMMUNICATION权限 | 需要ohos.permission.DISTRIBUTED_DATASYNC权限 |

**适配指导**

业务申请并配置ohos.permission.DISTRIBUTED_DATASYNC权限，仅用于迁移场景使用。

## cl.ability.3 ApplicationContext开机自启动接口删除

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


## cl.ability.4 AutoStartupInfo接口使用权限变更

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


## cl.ability.5 AutoStartupCallback接口使用权限变更
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
