# Context

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Provides the context for running code, including **applicationInfo** and **resourceManager**.


## Usage


You must extend **AbilityContext** to implement this module.


## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| resourceManager | ResourceManager | Yes| No| **ResourceManager** object.|
| applicationInfo | ApplicationInfo | Yes| No| Information about the application.|
| cacheDir | string | Yes| No| Cache directory of the application on the internal storage.|
| tempDir | string | Yes| No| Temporary file directory of the application.|
| filesDir | string | Yes| No| File directory of the application on the internal storage.|
| databaseDir | string | Yes| No| Storage directory of local data.|
| storageDir | string | Yes| No| Storage directory of lightweight data.|
| bundleCodeDir | string | Yes| No| Application installation path.|
| distributedFilesDir | string | Yes| No| Storage directory of distributed application data files.|
| eventHub | [EventHub](js-apis-eventhub.md) | Yes| No| Event hub information.|


## Context.createBundleContext

createBundleContext(bundleName: string): Context;

Creates an application context.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Application bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Context | Context of the application created.|

**Example**
    
  ```js
  let test = "com.example.test";
  let context = this.context.createBundleContext(test);
  ```


## Context.getApplicationContext

getApplicationContext(): Context;

Obtains the context of this application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Context | Context obtained.|

**Example**
    
  ```js
  // This part is mandatory.
  let context = this.context.getApplicationContext();
  ```
