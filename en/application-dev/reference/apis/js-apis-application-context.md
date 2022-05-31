# Context

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Provides the context for running code, including **applicationInfo** and **resourceManager**.

## Modules to Import
```
import AbilityContext from '@ohos.application.Ability';
```

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
| area | [AreaMode](#areamode) | Yes| Yes| Area in which the file to be access is located.| 


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
  import AbilityContext from '@ohos.application.Ability'
      class MainAbility extends AbilityContext {
          onWindowStageCreate(windowStage) {
              let test = "com.example.test";
              let context = this.context.createBundleContext(test);
      }
}

  ```


## Context.getApplicationContext

getApplicationContext(): ApplicationContext;

Obtains the context of this application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| ApplicationContext | Current application context.|

**Example**
    
  ```js
  // This part is mandatory.
  let applicationContext = this.context.getApplicationContext();
  ```


## AreaMode

Defines the area where the file to be access is located. Each area has its own content.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name           | Value   | Description           |
| --------------- | ---- | --------------- |
| EL1             | 0    | Device-level encryption area.  |
| EL2             | 1    | User credential encryption area. The default value is **EL2**.|
