# @ohos.app.ability.application (Application) (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zexin_c-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=3eb7d58aa53b6fa741fb6f554967ffe195cc4992 translatedAt=2026-08-18T15:25:55.670Z pushedAt=2026-08-19T01:20:13.443Z -->

You can use this module to create a [Context](../../application-models/application-context-stage.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { application } from '@kit.AbilityKit';
```

## application.createModuleContext

createModuleContext(context: Context, bundleName: string, moduleName: string): Promise\<Context>

Creates the context for a module. This API uses a promise to return the result.

> **NOTE**
>
> - Starting from API version 18, [Context](js-apis-inner-application-context.md#context) supports obtaining the process name (processName) of the current app. The **processName** property in the Context created by createModuleContext is the same as that in the input Context, and the other properties are obtained based on the input Context, bundleName, and moduleName.
>
> - Because creating a module context involves resource query and initialization, which takes a relatively long time, avoid calling createModuleContext frequently or multiple times to create multiple Context instances in scenarios with high requirements on app smoothness, so as not to affect user experience.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**Parameters**

| Name       | Type                                      | Mandatory  | Description            |
| --------- | ---------------------------------------- | ---- | -------------- |
| context | [Context](../../reference/apis-ability-kit/js-apis-inner-application-context.md) | Yes| Application context.|
| bundleName | string   | Yes    | Bundle name of the app. If the value is an empty string, the bundle name of the current app is used by default.|
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
      application.createModuleContext(this.context, 'bundlename', 'entry').then((data: common.Context)=>{
        moduleContext = data;
        console.info('createModuleContext success!');
      }).catch((error : BusinessError)=>{
        console.error(`createModuleContext failed, error.code: ${error.code}, error.message: ${error.message}`);
      })
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

## application.createBundleContext

createBundleContext(context: Context, bundleName: string): Promise\<Context>

Creates the context for an application. This API uses a promise to return the result.

> **NOTE**
>
> Starting from API version 18, [Context](js-apis-inner-application-context.md#context) supports obtaining the process name (processName) of the current app. The **processName** property in the Context created by createBundleContext is the same as that in the input Context, and the other properties are obtained based on the input Context and bundleName.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

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
      application.createBundleContext(this.context, 'bundlename').then((data: common.Context)=>{
        moduleContext = data;
        console.info('createBundleContext success!');
      }).catch((error : BusinessError)=>{
        console.error(`createBundleContext failed, error.code: ${error.code}, error.message: ${error.message}`);
      })
    } catch (error) {
      console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}

```

## application.createPluginModuleContextForHostBundle<sup>20+</sup>

createPluginModuleContextForHostBundle(context: Context, pluginBundleName: string, pluginModuleName: string, hostBundleName: string): Promise\<Context>

Creates the Context of the corresponding plugin based on the input Context, plugin bundle name, plugin module name, and the bundle name of the app that installs the plugin, to obtain the basic information of the plugin. This API uses a promise to return the result.

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
        .then((data: common.Context) => {
          moduleContext = data;
          console.info('createPluginModuleContextForHostBundle success!');
        })
        .catch((error: BusinessError) => {
          console.error(`createPluginModuleContextForHostBundle failed, error.code: ${error.code}, error.message: ${error.message}`);
        });
    } catch (error: BusinessError) {
      console.error(`createPluginModuleContextForHostBundle failed, error.code: ${error.code}, error.message: ${error.message}`);
    }
  }
}
```