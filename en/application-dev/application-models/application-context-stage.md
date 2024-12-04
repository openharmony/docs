# Context (Stage Model)


## Overview

[Context](../reference/apis-ability-kit/js-apis-inner-application-context.md) is the context of an object in an application. It provides basic information about the application, for example, [resourceManager](../reference/apis-localization-kit/js-apis-resource-manager.md), [applicationInfo](../reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md), [dir](../reference/apis-ability-kit/js-apis-inner-application-context.md#properties) (application file path), and [area](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode) (encryption level). It also provides basic methods such as **createBundleContext()** and [getApplicationContext()](../reference/apis-ability-kit/js-apis-inner-application-context.md#contextgetapplicationcontext). The [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) component and [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) derived class components have their own **Context** classes, for example, the base class **Context**, [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md), [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md), [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md), [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md), and ServiceExtensionContext.

- The figure below illustrates the inheritance relationship of contexts. 

  ![context-inheritance](figures/context-inheritance.png)
  
- The figure below illustrates the holding relationship of contexts. 

  ![context-holding](figures/context-holding.png)
  
- The following describes the information provided by different contexts.
  - [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md): Each [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) has the **Context** attribute, which provides APIs to operate an application component, obtain the application component configuration, and more.
    
    ```ts
    import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        let uiAbilityContext = this.context;
        //...
      }
    }
    ```
     
     > **NOTE**
     >
     > For details about how to obtain the context of a **UIAbility** instance on the page, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).
  - Scenario-specific [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md): For example, ServiceExtensionContext, inherited from ExtensionContext, provides APIs related to background services.
    
    ```ts
    import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

    export default class ServiceExtAbility extends ServiceExtensionAbility {
      onCreate(want: Want) {
        let serviceExtensionContext = this.context;
        //...
      }
    }
    ```
  - [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md): module-level context. It provides [HapModuleInfo](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md#properties) and [Configuration](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md#properties) in addition to those provided by the base class **Context**.
    
    ```ts
    import { AbilityStage } from '@kit.AbilityKit';

    export default class MyAbilityStage extends AbilityStage {
      onCreate(): void {
        let abilityStageContext = this.context;
        //...
      }
    }
    ```
  - [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md): application-level context. It provides APIs for subscribing to application component lifecycle changes, system memory changes, and system environment changes, setting the application language and color mode, clearing application data, and revoking permissions requested from users. It can be obtained from [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md), [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md), and [AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md).
    
    ```ts
    import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        let applicationContext = this.context.getApplicationContext();
        //...
      }
    }
    ```


## Typical Usage Scenarios of Context


This topic describes how to use the context in the following scenarios:

- [Obtaining Application File Paths](#obtaining-application-file-paths)
- [Obtaining and Modifying Encryption Levels](#obtaining-and-modifying-encryption-levels)
- [Obtaining the Context of Other Modules in the Current Application](#obtaining-the-context-of-other-modules-in-the-current-application)
- [Subscribing to UIAbility Lifecycle Changes in a Process](#subscribing-to-uiability-lifecycle-changes-in-a-process)


### Obtaining Application File Paths

The [base class Context](../reference/apis-ability-kit/js-apis-inner-application-context.md) provides the capability of obtaining application file paths. [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md), [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md), [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md), and [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md) inherit this capability. The application file paths are a type of application sandbox paths. For details, see [Application Sandbox Directory](../file-management/app-sandbox-directory.md).

The application file paths obtained by the preceding contexts are different.

- The application file path obtained through [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) is at the application level. This path is recommended for storing global application information, and the files in the path will be deleted when the application is uninstalled.

  | Name| Path|
  | -------- | -------- |
  | bundleCodeDir | \<Path prefix>/el1/bundle|
  | cacheDir | \<Path prefix>/\<Encryption level>/base/cache|
  | filesDir | \<Path prefix>/\<Encryption level>/base/files|
  | preferencesDir | \<Path prefix>/\<Encryption level>/base/preferences|
  | tempDir | \<Path prefix>/\<Encryption level>/base/temp|
  | databaseDir | \<Path prefix>/\<Encryption level>/database|
  | distributedFilesDir | \<Path prefix>/el2/distributedFiles|
  | cloudFileDir<sup>12+</sup> | \<Path prefix>/el2/cloud|

  The sample code is as follows:

  ```ts
  import { common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { promptAction } from '@kit.ArkUI';

  const TAG: string = '[Page_Context]';
  const DOMAIN_NUMBER: number = 0xFF00;

  @Entry
  @Component
  struct Page_Context {
    private context = getContext(this) as common.UIAbilityContext;

    build() {
      Column() {
        //...
        List({ initialIndex: 0 }) {
          ListItem() {
            Row() {
              //...
            }
            .onClick(() => {
              let applicationContext = this.context.getApplicationContext();
              let cacheDir = applicationContext.cacheDir;
              let tempDir = applicationContext.tempDir;
              let filesDir = applicationContext.filesDir;
              let databaseDir = applicationContext.databaseDir;
              let bundleCodeDir = applicationContext.bundleCodeDir;
              let distributedFilesDir = applicationContext.distributedFilesDir;
              let preferencesDir = applicationContext.preferencesDir;
              let cloudFileDir = applicationContext.cloudFileDir;
              // Obtain the application file path.
              let filePath = tempDir + 'test.txt';
              hilog.info(DOMAIN_NUMBER, TAG, `filePath: ${filePath}`);
              if (filePath !== null) {
                promptAction.showToast({
                  message: filePath
                });
              }
            })
          }
          //...
        }
        //...
      }
      //...
    }
  }
  ```

- The application file path obtained through [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md), [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md), and [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md) is at the [HAP](../quick-start/hap-package.md) level. This path is recommended for storing HAP-related information, and the files in this path are deleted when the HAP is uninstalled. However, the deletion does not affect the files in the application-level path unless all HAPs of the application are uninstalled.

  | Name| Path|
  | -------- | -------- |
  | bundleCodeDir | \<Path prefix>/el1/bundle|
  | cacheDir | \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/cache|
  | filesDir | \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/files|
  | preferencesDir | \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/preferences|
  | tempDir | \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/temp|
  | databaseDir | \<Path prefix>/\<Encryption level>/database/**\<module-name>**|
  | distributedFilesDir | \<Path prefix>/el2/distributedFiles/**\<module-name>**|
  | cloudFileDir<sup>12+</sup> | \<Path prefix>/el2/cloud/**\<module-name>**|

  The sample code is as follows:

  ```ts
  import { common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { promptAction } from '@kit.ArkUI';

  const TAG: string = '[Page_Context]';
  const DOMAIN_NUMBER: number = 0xFF00;

  @Entry
  @Component
  struct Page_Context {
    private context = getContext(this) as common.UIAbilityContext;

    build() {
      Column() {
        //...
        List({ initialIndex: 0 }) {
          ListItem() {
            Row() {
              //...
            }
            .onClick(() => {
              let cacheDir = this.context.cacheDir;
              let tempDir = this.context.tempDir;
              let filesDir = this.context.filesDir;
              let databaseDir = this.context.databaseDir;
              let bundleCodeDir = this.context.bundleCodeDir;
              let distributedFilesDir = this.context.distributedFilesDir;
              let preferencesDir = this.context.preferencesDir;
              let cloudFileDir = applicationContext.cloudFileDir;
              // Obtain the application file path.
              let filePath = tempDir + 'test.txt';
              hilog.info(DOMAIN_NUMBER, TAG, `filePath: ${filePath}`);
              if (filePath !== null) {
                promptAction.showToast({
                  message: filePath
                });
              }
            })
          }
          //...
        }
        //...
      }
      //...
    }
  }
  ```


### Obtaining and Modifying Encryption Levels

Encrypting application files enhances data security by preventing files from unauthorized access. Different application files require different levels of protection.

In practice, you need to select a proper encryption level based on scenario-specific requirements to protect application data security.  For details about the permissions required for a specific encryption level, see [AreaMode](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode) in [ContextConstant](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md).

- EL1: For private files, such as alarms and wallpapers, the application can place them in a directory with the device-level encryption (EL1) to ensure that they can be accessed before the user enters the password.
- EL2: For sensitive files, such as personal privacy data, the application can place them in a directory with the user-level encryption (EL2).
- EL3: For step recording, file download, or music playback that needs to read, write, and create files when the screen is locked, the application can place these files in EL3.
- EL4: For files that are related to user security information and do not need to be read, written, or created when the screen is locked, the application can place them in EL4.
- EL5: By default, sensitive user privacy files cannot be read or written on the lock screen. If such files need to be read or written on the lock screen, you can call [Access](../reference/apis-ability-kit/js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess) to apply for reading or writing files before the screen is locked or create new files that can be read and written after the screen is locked. It is more appropriate to place these files in EL5.

You can obtain and set the encryption level by reading and writing the **area** attribute in [Context](../reference/apis-ability-kit/js-apis-inner-application-context.md).

```ts
// EntryAbility.ets
import { UIAbility, contextConstant, AbilityConstant, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // Before storing common information, switch the encryption level to EL1.
    this.context.area = contextConstant.AreaMode.EL1; // Change the encryption level.
    // Store common information.

    // Before storing sensitive information, switch the encryption level to EL2.
    this.context.area = contextConstant.AreaMode.EL2; // Change the encryption level.
    // Store sensitive information.

    // Before storing sensitive information, switch the encryption level to EL3.
    this.context.area = contextConstant.AreaMode.EL3; // Change the encryption level.
    // Store sensitive information.

    // Before storing sensitive information, switch the encryption level to EL4.
    this.context.area = contextConstant.AreaMode.EL4; // Change the encryption level.
    // Store sensitive information.

    // Before storing sensitive information, switch the encryption level to EL5.
    this.context.area = contextConstant.AreaMode.EL5; // Change the encryption level.
    // Store sensitive information.
  }
}
```
```ts
// Index.ets
import { contextConstant, common } from '@kit.AbilityKit';
import { promptAction } from '@kit.ArkUI';

@Entry
@Component
struct Page_Context {
  private context = getContext(this) as common.UIAbilityContext;

  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        //...
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            // Before storing common information, switch the encryption level to EL1.
            if (this.context.area === contextConstant.AreaMode.EL2) { // Obtain the area.
              this.context.area = contextConstant.AreaMode.EL1; // Modify the area.
              promptAction.showToast({
                message: 'SwitchToEL1'
              });
            }
            // Store common information.
          })
        }
        //...
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            // Before storing sensitive information, switch the encryption level to EL2.
            if (this.context.area === contextConstant.AreaMode.EL1) { // Obtain the area.
              this.context.area = contextConstant.AreaMode.EL2; // Modify the area.
              promptAction.showToast({
                message: 'SwitchToEL2'
              });
            }
            // Store sensitive information.
          })
        }
        //...
      }
      //...
    }
    //...
  }
}
```


### Obtaining the Context of Other Modules in the Current Application

Call [createModuleContext(context: Context, moduleName: string)](../reference/apis-ability-kit/js-apis-app-ability-application.md#applicationcreatemodulecontext12) to obtain the context of another module in the current application. After obtaining the context, you can obtain the resource information of that module.
  
  ```ts
  import { common, application } from '@kit.AbilityKit';
  import { promptAction } from '@kit.ArkUI';
  import { BusinessError } from '@kit.BasicServicesKit';

  let storageEventCall = new LocalStorage();

  @Entry(storageEventCall)
  @Component
  struct Page_Context {
    private context = getContext(this) as common.UIAbilityContext;

    build() {
      Column() {
        //...
        List({ initialIndex: 0 }) {
          ListItem() {
            Row() {
              //...
            }
            .onClick(() => {
              let moduleName2: string = 'entry';
              application.createModuleContext(this.context, moduleName2)
                .then((data: common.Context) => {
                  console.info(`CreateModuleContext success, data: ${JSON.stringify(data)}`);
                  if (data !== null) {
                    promptAction.showToast({
                      message: ('Context obtained.')
                    });
                  }
                })
                .catch((err: BusinessError) => {
                  console.error(`CeateMudleContext failed, err code:${err.code}, err msg: ${err.message}`);
                });
            })
          }
          //...
        }
        //...
      }
      //...
    }
  }
  ```


### Subscribing to UIAbility Lifecycle Changes in a Process

In the DFX statistics scenario of an application, if you need to collect statistics on the stay duration and access frequency of a page, you can subscribe to [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) lifecycle changes in a process.

[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) provides APIs for subscribing to UIAbility lifecycle changes in a process. When the UIAbility lifecycle changes in a process, for example, being created or destroyed, becoming visible or invisible, or gaining or losing focus, the corresponding callback is triggered. Each time the callback is registered, a listener lifecycle ID is returned, with the value incremented by 1 each time. When the number of listeners exceeds the upper limit (2^63-1), **-1** is returned. The following uses [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) as an example.


```ts
import { AbilityConstant, AbilityLifecycleCallback, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import  { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[LifecycleAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class LifecycleAbility extends UIAbility {
  // Define a lifecycle ID.
  lifecycleId: number = -1;

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // Define a lifecycle callback object.
    let abilityLifecycleCallback: AbilityLifecycleCallback = {
      // Called when a UIAbility is created.
      onAbilityCreate(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // Called when a window is created.
      onWindowStageCreate(uiAbility, windowStage: window.WindowStage) {
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageCreate windowStage: ${JSON.stringify(windowStage)}`);
      },
      // Called when the window becomes active.
      onWindowStageActive(uiAbility, windowStage: window.WindowStage) {
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageActive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageActive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // Called when the window becomes inactive.
      onWindowStageInactive(uiAbility, windowStage: window.WindowStage) {
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageInactive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageInactive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // Called when the window is destroyed.
      onWindowStageDestroy(uiAbility, windowStage: window.WindowStage) {
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageDestroy windowStage: ${JSON.stringify(windowStage)}`);
      },
      // Called when the UIAbility is destroyed.
      onAbilityDestroy(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // Called when the UIAbility is switched from the background to the foreground.
      onAbilityForeground(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityForeground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // Called when the UIAbility is switched from the foreground to the background.
      onAbilityBackground(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityBackground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // Called when UIAbility is continued on another device.
      onAbilityContinue(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityContinue uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      }
    };
    // Obtain the application context.
    let applicationContext = this.context.getApplicationContext();
    try {
      // Register the application lifecycle callback.
      this.lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      hilog.error(DOMAIN_NUMBER, TAG, `Failed to register applicationContext. Code is ${code}, message is ${message}`);
    }

    hilog.info(DOMAIN_NUMBER, TAG, `register callback number: ${this.lifecycleId}`);
  }
  //...
  onDestroy(): void {
    // Obtain the application context.
    let applicationContext = this.context.getApplicationContext();
    try {
      // Deregister the application lifecycle callback.
      applicationContext.off('abilityLifecycle', this.lifecycleId);
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      hilog.error(DOMAIN_NUMBER, TAG, `Failed to unregister applicationContext. Code is ${code}, message is ${message}`);
    }
  }
}
```
