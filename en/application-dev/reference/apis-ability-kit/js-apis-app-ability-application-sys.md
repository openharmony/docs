#  @ohos.app.ability.application (Application) (System API)
You can use this module to create a [Context](../../application-models/application-context-stage.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { application } from '@kit.AbilityKit';
```
## application.createModuleContext<sup>12+</sup>

createModuleContext(context: Context, bundleName: string, moduleName: string): Promise\<Context>

Creates the context for a module.

> **NOTE**
>
> - Starting from API version 18, the context can obtain the [process name](js-apis-inner-application-context.md#context) of the current application. The **processName** property in the context created by **createModuleContext** is the same as the **processName** property in the input parameter **Context**. The values of other properties are obtained based on the input parameters **Context**, **bundleName**, and **moduleName**.
>
> - This API requires multiple bundle information queries and loads all resources of the specified module, which can be quite slow. To optimize performance, you are advised to cache the created context during the first use to prevent repeated calls for context creation.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| context | [Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md) | Yes| Application context.| 
| bundleName | string   | Yes   | Bundle name of the application. If an empty string is passed in, the current application is used by default.|
| moduleName | string | Yes| Module name.|

**Return value**

| Type              | Description               |
| ------------------ | ------------------- |
| Promise\<[Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md)> | Promise used to return the context created.|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message       |
| -------- | --------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api.|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
import { UIAbility, application, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    let moduleContext: common.Context;
    try {
      application.createModuleContext(this.context, 'bundlename', 'entry').then((data: Context)=>{
        moduleContext = data;
        console.info('createModuleContext success!');
      }).catch((error : BusinessError)=>{
        console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
      })
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

## application.createBundleContext<sup>12+</sup>

createBundleContext(context: Context, bundleName: string): Promise\<Context>

Creates the context for an application.

> **NOTE**
>
> Starting from API version 18, the context can obtain the [process name](js-apis-inner-application-context.md#context) of the current application. The **processName** property in the context created by **createBundleContext** is the same as the **processName** property in the input parameter **Context**. The values of other properties are obtained based on the input parameters **Context**, **bundleName**, and **moduleName**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| context | [Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md) | Yes| Application context.| 
| bundleName | string   | Yes   | Bundle name of the application.|

**Return value**

| Type              | Description               |
| ------------------ | ------------------- |
| Promise\<[Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md)> | Promise used to return the context created.|

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message       |
| -------- | --------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api.|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |


**Example**

```ts
import { UIAbility, application, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    let moduleContext: common.Context;
    try {
      application.createBundleContext(this.context, 'bundlename').then((data: Context)=>{
        moduleContext = data;
        console.info('createBundleContext success!');
      }).catch((error : BusinessError)=>{
        console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
      })
    } catch (error) {
      console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}

```
## application.createPluginModuleContextForHostBundle<sup>20+</sup>

createPluginModuleContextForHostBundle(context: Context, pluginBundleName: string, pluginModuleName: string, hostBundleName: string): Promise\<Context>

Creates the context for a plugin based on a given context, plugin bundle name, plugin module name, and application bundle name to obtain the basic information about the plugin. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| context | [Context](js-apis-inner-application-context.md) | Yes| Application context.|
| pluginBundleName | string | Yes| Bundle name of the plugin.|
| pluginModuleName | string | Yes| Module name of the plugin.|
| hostBundleName | string | Yes| Bundle name of the application for which the plugin is installed.|

**Return value**

| Type              | Description               |
| ------------------ | ------------------- |
| Promise\<[Context](js-apis-inner-application-context.md)> | Promise used to return the context created, in which the **processName** and **config** properties are the same as those of the input context.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 201      | Permission denied. |
| 202      | Permission denied, non-system app called system api. |

**Example**

```ts
import { AbilityConstant, UIAbility, application, common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    let moduleContext: common.Context;
    try {
      application.createPluginModuleContextForHostBundle(this.context, 'com.example.pluginBundleName', 'pluginModuleName', 'com.example.hostBundleName')
        .then((data: Context) => {
          moduleContext = data;
          console.info('createPluginModuleContextForHostBundle success!');
        })
        .catch((error: BusinessError) => {
          let code: number = (error as BusinessError).code;
          let message: string = (error as BusinessError).message;
          console.error(`createPluginModuleContextForHostBundle failed, error.code: ${code}, error.message: ${message}`);
        });
    } catch (error) {
      let code: number = (error as BusinessError).code;
      let message: string = (error as BusinessError).message;
      console.error(`createPluginModuleContextForHostBundle failed, error.code: ${code}, error.message: ${message}`);
    }
  }
}
```
