# Context

The **Context** module provides context for abilities or applications. It allows access to application-specific resources.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name         | Type    | Readable  | Writable  | Description     |
| ----------- | ------ | ---- | ---- | ------- |
| resourceManager     | resmgr.[ResourceManager](js-apis-resource-manager.md) | Yes   | No   | Object for resource management.  |
| applicationInfo | [ApplicationInfo](js-apis-bundle-ApplicationInfo.md) | Yes   | No   | Application information.|
| cacheDir | string | Yes   | No   | Cache directory.|
| tempDir | string | Yes   | No   | Temporary directory.|
| filesDir | string | Yes   | No   | File directory.|
| databaseDir | string | Yes   | No   | Database directory.|
| preferencesDir | string | Yes   | No   | Preferences directory.|
| bundleCodeDir | string | Yes   | No   | Bundle code directory.|
| distributedFilesDir | string | Yes   | No   | Distributed file directory.|
| eventHub | [EventHub](js-apis-inner-application-eventHub.md) | Yes   | No   | Event hub that implements event subscription, unsubscription, and triggering.|
| area | contextConstant.[AreaMode](js-apis-app-ability-contextConstant.md) | Yes   | No   | Area in which the file to be access is located.|

## Context.createBundleContext

createBundleContext(bundleName: string): Context;

Creates the context based on the bundle name.

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

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
let bundleContext;
try {
    bundleContext = this.context.createBundleContext('com.example.test');
} catch (error) {
    console.log('createBundleContext failed, error.code: ' + JSON.stringify(error.code) +
        ' error.message: ' + JSON.stringify(error.message));
}
```

## Context.createModuleContext

createModuleContext(moduleName: string): Context;

Creates the context based on the module name.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| moduleName | string | Yes   | Module name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Context | Context created.|

**Error codes**

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
let moduleContext;
try {
    moduleContext = this.context.createModuleContext('entry');
} catch (error) {
    console.log('createModuleContext failed, error.code: ' + JSON.stringify(error.code) +
        ' error.message: ' + JSON.stringify(error.message));
}
```

createModuleContext(bundleName: string, moduleName: string): Context;

Creates the context based on the bundle name and module name.

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

| ID| Error Message|
| ------- | -------------------------------- |
| 401 | If the input parameter is not valid parameter. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
let moduleContext;
try {
    moduleContext = this.context.createModuleContext('com.example.test', 'entry');
} catch (error) {
    console.log('createModuleContext failed, error.code: ' + JSON.stringify(error.code) +
        ' error.message: ' + JSON.stringify(error.message));
}
```

## Context.getApplicationContext

getApplicationContext(): ApplicationContext;

Obtains the context of this application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [ApplicationContext](js-apis-inner-application-applicationContext.md) | Application context obtained.|

**Example**

```ts
let applicationContext;
try {
    applicationContext = this.context.getApplicationContext();
} catch (error) {
    console.log('getApplicationContext failed, error.code: ' + JSON.stringify(error.code) +
        ' error.message: ' + JSON.stringify(error.message));
}
```
