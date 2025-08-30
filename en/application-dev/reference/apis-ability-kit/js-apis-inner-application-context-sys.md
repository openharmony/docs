# Context (System API)

The Context module provides context for abilities or applications. It allows access to application-specific resources.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## Context

### createBundleContext<sup>(deprecated)</sup>

createBundleContext(bundleName: string): Context

Creates the context based on the bundle name.

> **NOTE**
>
> If there are multiple modules in the stage model, resource ID conflicts may occur. You are advised to use [application.createModuleContext](./js-apis-app-ability-application-sys.md#applicationcreatemodulecontext12) instead.
>
> This API is deprecated since API version 12. You are advised to use [application.createBundleContext](./js-apis-app-ability-application-sys.md#applicationcreatebundlecontext12) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | Yes   | Bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Context | Context created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let bundleContext: common.Context;
    try {
      bundleContext = this.context.createBundleContext('com.example.test');
    } catch (error) {
      console.error(`createBundleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

### createModuleContext<sup>(deprecated)</sup>

createModuleContext(bundleName: string, moduleName: string): Context

Creates the context based on the bundle name and module name.

> **NOTE**
>
> This API is deprecated since API version 12. You are advised to use [application.createModuleContext](./js-apis-app-ability-application-sys.md#applicationcreatemodulecontext12) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | Yes   | Bundle name.|
| moduleName | string | Yes   | Module name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Context | Context created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
import { common, UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let moduleContext: common.Context;
    try {
      moduleContext = this.context.createModuleContext('com.example.test', 'entry');
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```

### createModuleResourceManager<sup>11+</sup>

createModuleResourceManager(bundleName: string, moduleName: string): resmgr.ResourceManager

Creates a resource management object for a module.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | Yes   | Bundle name.|
| moduleName | string | Yes   | Module name.|

**Return value**

| Type| Description|
| -------- | -------- |
| [resmgr.ResourceManager](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager) | Object for resource management.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 201 | Permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let ModuleResourceManager: resourceManager.ResourceManager;
    try {
      ModuleResourceManager = this.context.createModuleResourceManager('com.example.test', 'entry');
    } catch (error) {
      console.error(`createModuleResourceManager failed, error.code: ${(error as BusinessError).code}, error.message: ${(error as BusinessError).message}`);
    }
  }
}
```
### createSystemHspModuleResourceManager<sup>12+</sup>

createSystemHspModuleResourceManager(bundleName: string, moduleName: string): resmgr.ResourceManager

Creates a [resource manager](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager) for an OEM-preset [system-level HSP](../../quick-start/application-package-glossary.md#system-level-hsp).

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type    | Mandatory  | Description  |
| -------- |--------| ---- |------|
| bundleName | string | Yes   | Bundle name. |
| moduleName | string | Yes   | Module name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16400001 | The input bundleName is not a system HSP. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    this.context.createSystemHspModuleResourceManager("com.example.myapplication", "library");
  }
}
```
