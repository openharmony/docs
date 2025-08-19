# ApplicationContext (System API)

The ApplicationContext module inherits from [Context](js-apis-inner-application-context.md). It provides application-level context capabilities, including APIs for registering and deregistering the lifecycle of application components.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [ApplicationContext](js-apis-inner-application-applicationContext.md).

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## Instructions

Before calling any APIs in ApplicationContext, obtain an ApplicationContext instance through the context instance.

## ApplicationContext.preloadUIExtensionAbility<sup>12+</sup>

preloadUIExtensionAbility(want: Want): Promise\<void\>

Preloads a UIExtensionAbility instance.
The preloaded UIExtensionAbility instance is sent to the **onCreate** lifecycle of the UIExtensionAbility and waits to be loaded by the current application. A UIExtensionAbility instance can be preloaded for multiple times. Each time a preloaded UIExtensionAbility instance is loaded, the next preloaded UIExtensionAbility instance is sent to the **onCreate** lifecycle of the UIExtensionAbility.

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
| 201     | The application does not have permission to call the interface. |
| 202     | The application is not system-app, can not use system-api. |
| 401     | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16200011 | The context does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
      let applicationContext = this.context.getApplicationContext();
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
      console.error(`preloadUIExtensionAbility failed. code: ${code}, msg: ${message}`);
    }
  }
}
```
