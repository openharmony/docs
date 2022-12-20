# Context

The **Context** module provides context for abilities or applications. It allows access to application-specific resources, as well as permission requests and verification.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name         | Type    | Readable  | Writable  | Description     |
| ----------- | ------ | ---- | ---- | ------- |
| resourceManager     | resmgr.ResourceManager | Yes   | No   | Object for resource management.  |
| applicationInfo | ApplicationInfo | Yes   | No   | Application information.|
| cacheDir | string | Yes   | No   | Cache directory.|
| tempDir | string | Yes   | No   | Temporary directory.|
| filesDir | string | Yes   | No   | File directory.|
| databaseDir | string | Yes   | No   | Database directory.|
| preferencesDir | string | Yes   | No   | Preferences directory.|
| bundleCodeDir | string | Yes   | No   | Bundle code directory.|
| distributedFilesDir | string | Yes   | No   | Distributed file directory.|
| eventHub | string | Yes   | No   | Event hub that implements event subscription, unsubscription, and triggering.|
| area | [AreaMode](#areamode) | Yes   | No   | Area in which the file to be access is located.|


## Context.createBundleContext

createBundleContext(bundleName: string): Context;

Creates the context based on the bundle name.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | Yes   | Bundle name of the application.|

**Return value**

| Type| Description|
| -------- | -------- |
| Context | Context created.|

**Example**

```ts
let bundleContext = this.context.createBundleContext("com.example.test");
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

**Example**

```ts
let moduleContext = this.context.createModuleContext("entry");
```

createModuleContext(bundleName: string, moduleName: string): Context;

Creates the context based on the bundle name and module name.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| bundleName | string | Yes   | Bundle name of the application.|
| moduleName | string | Yes   | Module name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Context | Context created.|

**Example**

```ts
let moduleContext = this.context.createModuleContext("com.example.test", "entry");
```

## Context.getApplicationContext

getApplicationContext(): ApplicationContext;

Obtains the application context.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Context | Application context obtained.|

**Example**

```ts
let applicationContext = this.context.getApplicationContext();
```

## AreaMode

Enumerates the areas in which the file to be access can be located.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description| 
| -------- | -------- | -------- |
| EL1 | 0 | Device-level encryption area.| 
| EL2 | 1 | User credential encryption area.| 
