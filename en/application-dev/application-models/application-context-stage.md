# Context (Stage Model)


## Overview

[Context](../reference/apis/js-apis-inner-application-context.md) is the context of an object in an application. It provides basic information about the application, for example, **resourceManager**, **applicationInfo**, **dir** (application file path), and **area** (encryption level). It also provides basic methods such as **createBundleContext()** and **getApplicationContext()**. The UIAbility component and ExtensionAbility derived class components have their own **Context** classes, for example, the base class **Context**, **ApplicationContext**, **AbilityStageContext**, **UIAbilityContext**, **ExtensionContext**, and **ServiceExtensionContext**.

- The figure below illustrates the inheritance relationship of contexts. 

  ![context-inheritance](figures/context-inheritance.png)
  
- The figure below illustrates the holding relationship of contexts. 

  ![context-holding](figures/context-holding.png)
  
- The following describes the information provided by different contexts.
  - [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md): Each UIAbility has the **Context** attribute, which provides APIs to operate an application component, obtain the application component configuration, and more.
    
     ```ts
     import UIAbility from '@ohos.app.ability.UIAbility';
     export default class EntryAbility extends UIAbility {
       onCreate(want, launchParam) {
         let uiAbilityContext = this.context;
         ...
       }
     }
     ```
     
     > **NOTE**
     >
     > For details about how to obtain the context of a **UIAbility** instance on the page, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).
  - Scenario-specific [ExtensionContext](../reference/apis/js-apis-inner-application-extensionContext.md): For example, ServiceExtensionContext, inherited from ExtensionContext, provides APIs related to background services.
    
     ```ts
     import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
     export default class MyService extends ServiceExtensionAbility {
       onCreate(want) {
         let serviceExtensionContext = this.context;
         ...
       }
     }
     ```
  - [AbilityStageContext](../reference/apis/js-apis-inner-application-abilityStageContext.md): module-level context. It provides **HapModuleInfo** and **Configuration** in addition to those provided by the base class **Context**.
    
     ```ts
     import AbilityStage from '@ohos.app.ability.AbilityStage';
     export default class MyAbilityStage extends AbilityStage {
       onCreate() {
         let abilityStageContext = this.context;
         ...
       }
     }
     ```
  - [ApplicationContext](../reference/apis/js-apis-inner-application-applicationContext.md): application-level context. It provides APIs for subscribing to application component lifecycle changes, system memory changes, and system environment changes. The application-level context can be obtained from UIAbility, ExtensionAbility, and AbilityStage.
    
     ```ts
     import UIAbility from '@ohos.app.ability.UIAbility';
     export default class EntryAbility extends UIAbility {
       onCreate(want, launchParam) {
         let applicationContext = this.context.getApplicationContext();
         ...
       }
     }
     ```


## Typical Usage Scenarios of Context


This topic describes how to use the context in the following scenarios:


- [Obtaining Application File Paths](#obtaining-application-file-paths)
- [Obtaining and Modifying Encryption Levels](#obtaining-and-modifying-encryption-levels)
- [Creating Context of Another Application or Module](#creating-context-of-another-application-or-module)
- [Subscribing to UIAbility Lifecycle Changes in a Process](#subscribing-to-uiability-lifecycle-changes-in-a-process)


### Obtaining Application File Paths

The base class [Context](../reference/apis/js-apis-inner-application-context.md) provides the capability of obtaining application file paths. **ApplicationContext**, **AbilityStageContext**, **UIAbilityContext**, and **ExtensionContext** inherit this capability. The application file paths are a type of application sandbox paths. For details, see [Application Sandbox Directory](../file-management/app-sandbox-directory.md).

The application file paths obtained by the preceding contexts are different.

- The application file path obtained through **ApplicationContext** is at the application level. This path is recommended for storing global application information, and the files in the path will be deleted when the application is uninstalled.

  | Name| Path|
  | -------- | -------- |
  | bundleCodeDir | \<Path prefix>/el1/bundle/ |
  | cacheDir | \<Path prefix>/\<Encryption level>/base/cache/ |
  | filesDir | \<Path prefix>/\<Encryption level>/base/files/ |
  | preferencesDir | \<Path prefix>/\<Encryption level>/base/preferences/ |
  | tempDir | \<Path prefix>/\<Encryption level>/base/temp/ |
  | databaseDir | \<Path prefix>/\<Encryption level>/database/ |
  | distributedFilesDir | \<Path prefix>/el2/distributedFiles/ |

  The sample code is as follows:

    ```ts
    import UIAbility from '@ohos.app.ability.UIAbility';
    
    export default class EntryAbility extends UIAbility {
      onCreate(want, launchParam) {
        let applicationContext = this.context.getApplicationContext();
        let cacheDir = applicationContext.cacheDir;
        let tempDir = applicationContext.tempDir;
        let filesDir = applicationContext.filesDir;
        let databaseDir = applicationContext.databaseDir;
        let bundleCodeDir = applicationContext.bundleCodeDir;
        let distributedFilesDir = applicationContext.distributedFilesDir;
        let preferencesDir = applicationContext.preferencesDir;
        ...
      }
    }
    ```

- The application file path obtained through **AbilityStageContext**, **UIAbilityContext**, or **ExtensionContext** is at the HAP level. This path is recommended for storing HAP-related information, and the files in this path are deleted when the HAP is uninstalled. However, the deletion does not affect the files in the application-level path unless all HAPs of the application are uninstalled.

  | Name| Path|
  | -------- | -------- |
  | bundleCodeDir | \<Path prefix>/el1/bundle/ |
  | cacheDir | \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/cache/ |
  | filesDir | \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/files/ |
  | preferencesDir | \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/preferences/ |
  | tempDir | \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/temp/ |
  | databaseDir | \<Path prefix>/\<Encryption level>/database/**\<module-name>**/ |
  | distributedFilesDir | \<Path prefix>/el2/distributedFiles/**\<module-name>**/ |

  The sample code is as follows:

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
      ...
    }
  }
  ```


### Obtaining and Modifying Encryption Levels

Encrypting application files enhances data security by preventing files from unauthorized access. Different application files require different levels of protection. For private files, such as alarms and wallpapers, the application must place them in a directory with the device-level encryption (EL1) to ensure that they can be accessed before the user enters the password. For sensitive files, such as personal privacy data, the application must place them in a directory with the user-level encryption (EL2).

In practice, you need to select a proper encryption level based on scenario-specific requirements to protect application data security. The proper use of EL1 and the EL2 can efficiently improve the security.

> **NOTE**
>
> - AreaMode.EL1: device-level encryption. Directories with this encryption level are accessible after the device is powered on.
>
> - AreaMode.EL2: user-level encryption. Directories with this encryption level are accessible only after the device is powered on and the password is entered (for the first time).

You can obtain and set the encryption level by reading and writing the **area** attribute in [Context](../reference/apis/js-apis-inner-application-context.md).

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import contextConstant from '@ohos.app.ability.contextConstant';

export default class EntryAbility extends UIAbility {
  onCreate(want, launchParam) {
    // Before storing common information, switch the encryption level to EL1.
    if (this.context.area === contextConstant.AreaMode.EL2) { // Obtain the area.
      this.context.area = contextConstant.AreaMode.EL1; // Modify the area.
    }
    // Store common information.

    // Before storing sensitive information, switch the encryption level to EL2.
    if (this.context.area === contextConstant.AreaMode.EL1) { // Obtain the area.
      this.context.area = contextConstant.AreaMode.EL2; // Modify the area.
    }
    // Store sensitive information.
  }
}
```


### Creating Context of Another Application or Module

The base class **Context** provides [createBundleContext(bundleName:string)](../reference/apis/js-apis-inner-application-context.md#contextcreatebundlecontext), [createModuleContext(moduleName:string)](../reference/apis/js-apis-inner-application-context.md#contextcreatemodulecontext), and [createModuleContext(bundleName:string, moduleName:string)](../reference/apis/js-apis-inner-application-context.md#contextcreatemodulecontext-1) to create the context of other applications or modules, so as to obtain the resource information, for example, [obtaining application file paths](#obtaining-application-development-paths) of other modules.

- Call **createBundleContext(bundleName:string)** to create the context of another application.
  > **NOTE**
  >
  > To obtain the context of another application:
  >
  > - Request the **ohos.permission.GET_BUNDLE_INFO_PRIVILEGED** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).
  >
  > - This is a system API and cannot be called by third-party applications.
  
  For example, application information displayed on the home screen includes the application name and icon. The home screen application calls the foregoing method to obtain the context information, so as to obtain the resource information including the application name and icon.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  
  export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
      let bundleName2 = 'com.example.application';
      let context2 = this.context.createBundleContext(bundleName2);
      let label2 = context2.applicationInfo.label;
      ...
    }
  }
  ```
  
- Call **createModuleContext(bundleName:string, moduleName:string)** to obtain the context of a specified module of another application. After obtaining the context, you can obtain the resource information of that module.
  > **NOTE**
  >
  > To obtain the context of a specified module of another application:
  >
  > - Request the **ohos.permission.GET_BUNDLE_INFO_PRIVILEGED** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).
  >
  > - This is a system API and cannot be called by third-party applications.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  
  export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
      let bundleName2 = 'com.example.application';
      let moduleName2 = 'module1';
      let context2 = this.context.createModuleContext(bundleName2, moduleName2);
      ...
    }
  }
  ```
  
- Call **createModuleContext(moduleName:string)** to obtain the context of another module in the current application. After obtaining the context, you can obtain the resource information of that module.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  
  export default class EntryAbility extends UIAbility {
    onCreate(want, launchParam) {
      let moduleName2 = 'module1';
      let context2 = this.context.createModuleContext(moduleName2);
      ...
    }
  }
  ```


### Subscribing to UIAbility Lifecycle Changes in a Process

In the DFX statistics scenario of an application, if you need to collect statistics on the stay duration and access frequency of a page, you can subscribe to UIAbility lifecycle changes in a process.

[ApplicationContext](../reference/apis/js-apis-inner-application-applicationContext.md) provides APIs for subscribing to UIAbility lifecycle changes in a process. When the UIAbility lifecycle changes in a process, for example, being created or destroyed, becoming visible or invisible, or gaining or losing focus, the corresponding callback is triggered. Each time the callback is registered, a listener lifecycle ID is returned, with the value incremented by 1 each time. When the number of listeners exceeds the upper limit (2^63-1), **-1** is returned. The following uses [UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md) as an example.


```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

const TAG: string = '[Example].[Entry].[EntryAbility]';

export default class EntryAbility extends UIAbility {
  // Define a lifecycle ID.
  lifecycleId: number;

  onCreate(want, launchParam) {
    // Define a lifecycle callback object.
    let abilityLifecycleCallback = {
      // Called when a UIAbility is created.
      onAbilityCreate(uiAbility) {
        console.info(TAG, `onAbilityCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // Called when a window is created.
      onWindowStageCreate(uiAbility, windowStage: window.WindowStage) {
        console.info(TAG, `onWindowStageCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        console.info(TAG, `onWindowStageCreate windowStage: ${JSON.stringify(windowStage)}`);
      },
      // Called when the window becomes active.
      onWindowStageActive(uiAbility, windowStage: window.WindowStage) {
        console.info(TAG, `onWindowStageActive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        console.info(TAG, `onWindowStageActive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // Called when the window becomes inactive.
      onWindowStageInactive(uiAbility, windowStage: window.WindowStage) {
        console.info(TAG, `onWindowStageInactive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        console.info(TAG, `onWindowStageInactive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // Called when the window is destroyed.
      onWindowStageDestroy(uiAbility, windowStage: window.WindowStage) {
        console.info(TAG, `onWindowStageDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        console.info(TAG, `onWindowStageDestroy windowStage: ${JSON.stringify(windowStage)}`);
      },
      // Called when the UIAbility is destroyed.
      onAbilityDestroy(uiAbility) {
        console.info(TAG, `onAbilityDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // Called when the UIAbility is switched from the background to the foreground.
      onAbilityForeground(uiAbility) {
        console.info(TAG, `onAbilityForeground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // Called when the UIAbility is switched from the foreground to the background.
      onAbilityBackground(uiAbility) {
        console.info(TAG, `onAbilityBackground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // Called when UIAbility is continued on another device.
      onAbilityContinue(uiAbility) {
        console.info(TAG, `onAbilityContinue uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      }
    }
    // Obtain the application context.
    let applicationContext = this.context.getApplicationContext();
    // Register the application lifecycle callback.
    this.lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
    console.info(TAG, `register callback number: ${this.lifecycleId}`);
  }

  ...

  onDestroy() {
    // Obtain the application context.
    let applicationContext = this.context.getApplicationContext();
    // Deregister the application lifecycle callback.
    applicationContext.off('abilityLifecycle', this.lifecycleId);
  }
}
```
