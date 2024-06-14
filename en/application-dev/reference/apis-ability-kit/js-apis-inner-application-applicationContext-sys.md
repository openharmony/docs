# ApplicationContext (System API)

The ApplicationContext module, inherited from [Context](js-apis-inner-application-context.md), provides application-level context capabilities, including APIs for registering and deregistering the lifecycle of application components.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [ApplicationContext](js-apis-inner-application-applicationContext.md).

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Instructions

Before calling any APIs in **ApplicationContext**, obtain an **ApplicationContext** instance through the **context** instance.

## ApplicationContext.preloadUIExtensionAbility<sup>12+</sup>

preloadUIExtensionAbility(want: Want): Promise\<void\>

Preloads a **UIExtensionAbility** instance.

The preloaded **UIExtensionAbility** instance is sent to the **onCreate** lifecycle of the UIExtensionAbility and waits to be loaded by the current application.

A **UIExtensionAbility** instance can be preloaded for multiple times. Each time a preloaded **UIExtensionAbility** instance is loaded, the next preloaded **UIExtensionAbility** instance is sent to the **onCreate** lifecycle of the UIExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md)  | Yes| Want information of the UIExtensionAbility.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16200011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {

  onCreate() {
    let want: Want = {
      bundleName: 'com.ohos.uiextensionprovider',
      abilityName: 'UIExtensionProvider',
      moduleName: 'entry',
      parameters: {
        // The value must be the same as the value of type in the module.json5 file of the UIExtensionAbility.
        'ability.want.params.uiExtensionType': 'sys/commonUI'
      }
    };
    try {
        let applicationContext = this.context.getApplicationConext();
        applicationContext.preloadUIExtensionAbility(want)
        .then(() => {
          // Carry out normal service processing.
          console.info('preloadUIExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error('preloadUIExtensionAbility failed');
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error('preloadUIExtensionAbility failed');
    }
  }
}
```

## ApplicationContext.setSupportedProcessCache<sup>12+</sup>

setSupportedProcessCache(isSupported : boolean): void

Sets whether the application itself supports process cache, which enables quick startup after caching.

> **NOTE**
>
> The process cache support status set by this API takes effect for an instance with a single process. The status can be set multiple times for different process instances, and the settings do not affect each other. However, the status can be set only once for a process instance. After a process instance is destroyed, the status is not retained and can be reset.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_PROCESS_CACHE_STATE

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
| Name       | Type    | Mandatory| Description                      |
| ------------- | -------- | ---- | -------------------------- |
| isSupported | boolean | Yes| Whether process cache is supported. The value **true** means that process cache is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |
| 202 | Not system App. |
| 401 | The input parameter is not a valid parameter. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16000011 | The context does not exist. |
| 16000050 | Internal error. |
| 16000200 | The supported process cache state cannot be set more than once. |

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import type AbilityConstant from '@ohos.app.ability.AbilityConstant';
import type Want from '@ohos.app.ability.Want';

export default class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let applicationContext = this.context.getApplicationContext();
    try {
      applicationContext.setSupportedProcessCache(false);
    } catch (error) {
      console.error(`setSupportedProcessCache fail, error: ${JSON.stringify(error)}`);
    }
  }
}
```
