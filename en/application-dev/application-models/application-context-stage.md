# Context (Stage Model)


## Overview

[Context](../reference/apis/js-apis-inner-application-context.md) is the context of an object in an application. It provides basic information about the application, for example, **resourceManager**, **applicationInfo**, **dir** (application development path), and **area** (encrypted area). It also provides basic methods such as **createBundleContext()** and **getApplicationContext()**. The UIAbility component and ExtensionAbility derived class components have their own **Context** classes, for example, the base class **Context**, **ApplicationContext**, **AbilityStageContext**, **UIAbilityContext**, **ExtensionContext**, and **ServiceExtensionContext**.

- The figure below illustrates the inheritance relationship of contexts.
  <img src="figures/context-inheritance.png" alt="context-inheritance" style="zoom: 50%;" />

- The figure below illustrates the holding relationship of contexts.
  <img src="figures/context-holding.png" alt="context-holding" style="zoom:50%;" />

- The following describes the information provided by different contexts.
  - [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md): Each UIAbility has the **Context** attribute, which provides APIs to operate the ability, obtain the ability configuration, and more.
    
     ```ts
     import UIAbility from '@ohos.app.ability.UIAbility';
     export default class EntryAbility extends UIAbility {
         onCreate(want, launchParam) {
             let uiAbilityContext = this.context;
             // ...
         }
     }
     ```
  - Scenario-specific [ExtensionContext](../reference/apis/js-apis-inner-application-extensionContext.md): For example, ServiceExtensionContext, inherited from ExtensionContext, provides APIs related to background services.
    
     ```ts
     import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
     export default class MyService extends ServiceExtensionAbility {
         onCreate(want) {
             let serviceExtensionContext = this.context;
             // ...
         }
     }
     ```
  - [AbilityStageContext](../reference/apis/js-apis-inner-application-abilityStageContext.md): module-level context. It provides **HapModuleInfo** and **Configuration** in addition to those provided by the base class **Context**.
    
     ```ts
     import AbilityStage from "@ohos.app.ability.AbilityStage";
     export default class MyAbilityStage extends AbilityStage {
         onCreate() {
             let abilityStageContext = this.context;
             // ...
         }
     }
     ```
  - [ApplicationContext](../reference/apis/js-apis-inner-application-applicationContext.md): application-level context. It provides APIs for subscribing to ability lifecycle changes, system memory changes, and system environment changes. The application-level context can be obtained from UIAbility, ExtensionAbility, and AbilityStage.
    
     ```ts
     import UIAbility from '@ohos.app.ability.UIAbility';
     export default class EntryAbility extends UIAbility {
         onCreate(want, launchParam) {
             let applicationContext = this.context.getApplicationContext();
             // ...
         }
     }
     ```


## Typical Usage Scenarios of Context


This topic describes how to use the context in the following scenarios:


- [Obtaining the Application Development Path](#obtaining-the-application-development-path)
- [Obtaining and Modifying Encrypted Areas](#obtaining-and-modifying-encrypted-areas)
- [Creating Context of Another Application or Module](#creating-context-of-another-application-or-module)
- [Subscribing to Ability Lifecycle Changes in a Process](#subscribing-to-ability-lifecycle-changes-in-a-process)


### Obtaining the Application Development Path

The following table describes the application development paths obtained from context.

**Table 1** Application development paths

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| cacheDir | string | Yes| No| Cache directory of the application on the internal storage.<br>It is the content of **Storage** of an application under **Settings > Apps & services > Apps**.|
| tempDir | string | Yes| No| Temporary file directory of the application.<br>Files in this directory are deleted after the application is uninstalled.|
| filesDir | string | Yes| No| File directory of the application on the internal storage.<br>Files in this directory may be synchronized to other directories during application migration or backup.|
| databaseDir | string | Yes| No| Storage directory of the local database.|
| bundleCodeDir | string | Yes| No| Installation directory of the application on the internal storage.|
| distributedFilesDir | string | Yes| No| Storage directory of distributed application data files.|
| preferencesDir | string | Yes| Yes| Preferences directory of the application.|

The capability of obtaining the application development path is provided by the base class **Context**. This capability is also provided by **ApplicationContext**, **AbilityStageContext**, **UIAbilityContext**, and **ExtensionContext**. However, the paths obtained from different contexts may differ, as shown below.

**Figure 1** Application development paths obtained from context
<img src="figures/context-dir.png" alt="context-dir" style="zoom: 50%;" />

- Obtain the application-level path through **ApplicationContext**. It is recommended that global application information be stored in this path. Files stored in this path will be deleted only when the application is uninstalled.
    | Name| Path|
  | -------- | -------- |
  | bundleCodeDir | {Path prefix}/el1/bundle/|
  | cacheDir | {Path prefix}/{Encryption level}/base/cache/|
  | filesDir | {Path prefix}/{Encryption level}/base/files/|
  | preferencesDir | {Path prefix}/{Encryption level}/base/preferences/|
  | tempDir | {Path prefix}/{Encryption level}/base/temp/|
  | databaseDir | {Path prefix}/{Encryption level}/database/|
  | distributedFilesDir | {Path prefix}/el2/distributedFiles/|

- Obtain the HAP level path through **AbilityStageContext**, **UIAbilityContext**, and **ExtensionContext**. It is recommended that the HAP information be stored in this path. The file content stored in this path will be deleted when the HAP is uninstalled. The file content in the application-level path will be deleted only after all the HAPs of the application are uninstalled.
    | Name| Path|
  | -------- | -------- |
  | bundleCodeDir | {Path prefix}/el1/bundle/|
  | cacheDir | {Path prefix}/{Encryption level}/base/**haps/{moduleName}**/cache/|
  | filesDir | {Path prefix}/{Encryption level}/base/**haps/{moduleName}**/files/|
  | preferencesDir | {path prefix}/{encryption level}/base/**haps/{moduleName}**/preferences/|
  | tempDir | {Path prefix}/{Encryption level}/base/**haps/{moduleName}**/temp/|
  | databaseDir | {Path prefix}/{Encryption level}/database/**{moduleName}**/|
  | distributedFilesDir | {Path prefix}/el2/distributedFiles/**{moduleName}**/|

The sample code for obtaining the application development paths is as follows:


```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        let cacheDir = this.context.cacheDir;
        let tempDir = this.context.tempDir;
        let filesDir = this.context.filesDir;
        let databaseDir = this.context.databaseDir;
        let bundleCodeDir = this.context.bundleCodeDir;
        let distributedFilesDir = this.context.distributedFilesDir;
        let preferencesDir = this.context.preferencesDir;
        // ...
    }
}
```


### Obtaining and Modifying Encrypted Areas

You can read and write [the area attribute in the context](../reference/apis/js-apis-inner-application-context.md) to obtain and set an encrypted area. Two encryption levels are supported:

- AreaMode.EL1: device-level encryption area, which is accessible after the device is powered on.

- AreaMode.EL2: user-level encryption area, which is accessible only after the device is powered on and the password is entered (for the first time).

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
        // Before storing common information, switch the encryption level to EL1.
        if (this.context.area === 1) {// Obtain the area.
            this.context.area = 0; // Modify the area.
        }
        // Store common information.

        // Before storing sensitive information, switch the encryption level to EL2.
        if (this.context.area === 0) { // Obtain the area.
            this.context.area = 1;     // Modify the area.
        }
        // Store sensitive information.
    }
}
```


### Creating Context of Another Application or Module

The base class **Context** provides the [createBundleContext(bundleName:string)](../reference/apis/js-apis-inner-application-context.md#contextcreatebundlecontext), [createModuleContext(moduleName:string)](../reference/apis/js-apis-inner-application-context.md#contextcreatemodulecontext), and [createModuleContext(bundleName:string, moduleName:string)](../reference/apis/js-apis-inner-application-context.md#contextcreatemodulecontext-1) methods for creating the context of other applications or modules, so as to obtain the resource information, for example, [obtaining the application development paths](#obtaining-the-application-development-path) of other modules.

- Call **createBundleContext(bundleName:string)** to create the context of another application.
  > **NOTE**
  >
  > To obtain the context of another application:
  >
  > - Request the **ohos.permission.GET_BUNDLE_INFO_PRIVILEGED** permission. For details, see [Permission Application Guide](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).
  >
> - This is a system API and cannot be called by third-party applications.
  
  For example, application information displayed on the home screen includes the application name and icon. The home screen application calls the foregoing method to obtain the context information, so as to obtain the resource information including the application name and icon.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  
  export default class EntryAbility extends UIAbility {
      onCreate(want, launchParam) {
          let bundleName2 = "com.example.application";
          let context2 = this.context.createBundleContext(bundleName2);
          let label2 = context2.applicationInfo.label;
          // ...
      }
  }
```
  
- Call **createModuleContext(bundleName:string, moduleName:string)** to obtain the context of a specified module of another application. After obtaining the context, you can obtain the resource information of that module.
  > **NOTE**
  >
  > To obtain the context of a specified module of another application:
  >
  > - Request the **ohos.permission.GET_BUNDLE_INFO_PRIVILEGED** permission. For details, see [Permission Application Guide](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).
  >
> - This is a system API and cannot be called by third-party applications.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  
  export default class EntryAbility extends UIAbility {
      onCreate(want, launchParam) {
          let bundleName2 = "com.example.application";
          let moduleName2 = "module1";
          let context2 = this.context.createModuleContext(bundleName2, moduleName2);
          // ...
      }
  }
  ```
  
- Call **createModuleContext(moduleName:string)** to obtain the context of another module in the current application. After obtaining the context, you can obtain the resource information of that module.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  
  export default class EntryAbility extends UIAbility {
      onCreate(want, launchParam) {
          let moduleName2 = "module1";
          let context2 = this.context.createModuleContext(moduleName2);
          // ...
      }
  }
  ```


### Subscribing to Ability Lifecycle Changes in a Process

In the DFX statistics scenario of an application, if you need to collect statistics on the stay duration and access frequency of a page, you can subscribe to ability lifecycle changes.

When the ability lifecycle changes in a process, for example, being created or destroyed, becoming visible or invisible, or gaining or losing focus, the corresponding callback is triggered, and a listener ID is returned. The ID is incremented by 1 each time the listener is registered. When the number of listeners exceeds the upper limit (2^63-1), -1 is returned. The following uses [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md) as an example.


```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

const TAG: string = "[Example].[Entry].[EntryAbility]";

export default class EntryAbility extends UIAbility {
    lifecycleId: number;

    onCreate(want, launchParam) {
        let abilityLifecycleCallback = {
            onAbilityCreate(ability) {
                console.info(TAG, "onAbilityCreate ability:" + JSON.stringify(ability));
            },
            onWindowStageCreate(ability, windowStage) {
                console.info(TAG, "onWindowStageCreate ability:" + JSON.stringify(ability));
                console.info(TAG, "onWindowStageCreate windowStage:" + JSON.stringify(windowStage));
            },
            onWindowStageActive(ability, windowStage) {
                console.info(TAG, "onWindowStageActive ability:" + JSON.stringify(ability));
                console.info(TAG, "onWindowStageActive windowStage:" + JSON.stringify(windowStage));
            },
            onWindowStageInactive(ability, windowStage) {
                console.info(TAG, "onWindowStageInactive ability:" + JSON.stringify(ability));
                console.info(TAG, "onWindowStageInactive windowStage:" + JSON.stringify(windowStage));
            },
            onWindowStageDestroy(ability, windowStage) {
                console.info(TAG, "onWindowStageDestroy ability:" + JSON.stringify(ability));
                console.info(TAG, "onWindowStageDestroy windowStage:" + JSON.stringify(windowStage));
            },
            onAbilityDestroy(ability) {
                console.info(TAG, "onAbilityDestroy ability:" + JSON.stringify(ability));
            },
            onAbilityForeground(ability) {
                console.info(TAG, "onAbilityForeground ability:" + JSON.stringify(ability));
            },
            onAbilityBackground(ability) {
                console.info(TAG, "onAbilityBackground ability:" + JSON.stringify(ability));
            },
            onAbilityContinue(ability) {
                console.info(TAG, "onAbilityContinue ability:" + JSON.stringify(ability));
            }
        }
        // 1. Obtain the application context through the context attribute.
        let applicationContext = this.context.getApplicationContext();
        // 2. Register a listener for the lifecycle changes through the application context.
        this.lifecycleId = applicationContext.on("abilityLifecycle", abilityLifecycleCallback);
        console.info(TAG, "register callback number: " + JSON.stringify(this.lifecycleId));
    }

    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        applicationContext.off("abilityLifecycle", this.lifecycleId, (error, data) => {
            console.info(TAG, "unregister callback success, err: " + JSON.stringify(error));
        });
    }
}
```
