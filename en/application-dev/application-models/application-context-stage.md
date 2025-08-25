# Context (Stage Model)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @li-weifeng2; @xuzhihao666-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## Overview

[Context](../reference/apis-ability-kit/js-apis-inner-application-context.md) serves as the context environment for objects within an application. It provides basic information about the application, for example, [resourceManager](../reference/apis-localization-kit/js-apis-resource-manager.md) (resource management), [applicationInfo](../reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md) (current application information), and [area](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode) (file partitions).

## Comparison of Different Context Types

Both [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) components and various derived classes of [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) components have their own context classes. These include the base class Context, [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md), [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md), [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md), <!--Del-->[ServiceExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md), <!--DelEnd-->and [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md). For details about their relationships, see [Inheritance and Holding Relationships of Different Context Types](../reference/apis-ability-kit/js-apis-inner-application-context.md#inheritance-and-holding-relationships-of-different-context-types).

The following table describes how to obtain different types of context and their usage scenarios.

> **NOTE**
>
> Different types of context possess distinct capabilities and cannot be substituted for or forcibly converted into one another. For example, [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) is bound to the [setFontSizeScale](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetfontsizescale13) API, which is not available in [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md). Therefore, even if you forcibly convert UIAbilityContext to ApplicationContext, you will not be able to call the **setFontSizeScale** API.

**Table 1** Different context types

| Context Type| Description| Acquisition Method| Usage Scenario|
| -------- | -------- | -------- | -------- |
| [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) | Global context of an application, providing application-level information and capabilities.| - From API version 14 onwards, you can directly call [getApplicationContext](../reference/apis-ability-kit/js-apis-app-ability-application.md#applicationgetapplicationcontext14) to obtain it.<br>- In versions earlier than API version 14, you can obtain it by calling [getApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-context.md#getapplicationcontext) of a Context instance.| - [Obtain basic information about the current application](#obtaining-basic-information).<br>- [Obtain application file paths](#obtaining-application-file-paths).<br>- [Obtain and modifying encryption levels](#obtaining-and-modifying-encryption-levels).<br>- [Register a listener for application foreground/background changes](#listening-for-application-foregroundbackground-changes).|
| [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md) | Context of a module, providing module-level information and capabilities.| - To obtain the context of the current AbilityStage, you can directly access the [context](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#properties) property of the AbilityStage instance.<br> - To obtain the context of another module in the same application, you can call [createModuleContext](../reference/apis-ability-kit/js-apis-app-ability-application.md#applicationcreatemodulecontext12).| - Obtain basic information about the current module.<br>- [Obtain module file paths](#obtaining-application-file-paths).|
| [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | Context of a UIAbility, providing external information and capabilities of the UIAbility.| - You can directly access the [context](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#properties) property through a UIAbility instance.<br>- To load a UI component instance in the window of a UIAbility, call [getHostContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12) of the UIContext.| - Obtain basic information about the current UIAbility.<br>- Start other applications or atomic services, and connect to or disconnect from ServiceExtensionAbility components created by system applications.<br>- Destroy the current UIAbility.|
| [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md) | Context of an ExtensionAbility. Each type of ExtensionContext provides different information and capabilities.| Directly access the context property through an ExtensionAbility instance.| The capabilities provided by the context corresponding to different types of ExtensionAbility vary. For example, [InputMethodExtensionContext](../reference/apis-ime-kit/js-apis-inputmethod-extension-context.md) mainly provides the following capabilities:<br>- Obtain the basic information about the InputMethodExtensionAbility.<br>- Destroy the current input method.|
| [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md) | Context of a UI instance of ArkUI, providing capabilities related to UI operations. It is not directly related to the other types of context mentioned above.| - To obtain the UI context within a UI component, directly call [getHostContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12).<br>- If a Window instance exists, call [getUIContext](../reference/apis-arkui/arkts-apis-window-Window.md#getuicontext10) provided by the Window instance.| Use it for UI-related operations in the UI instance, for example:<br>- Obtain the font of the current UI instance.<br>- Display different types of dialog boxes.<br>- Set the UI avoid mode when the soft keyboard is displayed.|

## Acquisition of Context

If you need to obtain application resources, application paths, or use the methods provided by Context to implement operations such as application redirection, environment variable setting, data clearing, and permission obtaining, you need to obtain the corresponding context. This section describes how to obtain different types of context and where to use it.

### Obtaining ApplicationContext (Global Application Context)

[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) provides capabilities such as listening for lifecycle changes of application components within the application, system memory changes, system environment changes, setting application language, setting application color mode, clearing application data, and revoking permissions granted by the user. It can be obtained in [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md), [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md), and [AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md).

  ```ts
  import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      let applicationContext = this.context.getApplicationContext();
      //...
    }
  }
  ```

### Obtains AbilityStageContext (Module-Level Context)

Compared with the base class Context, [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md) additionally provides information such as [HapModuleInfo](../reference/apis-ability-kit/js-apis-bundleManager-hapModuleInfo.md) and [Configuration](../reference/apis-ability-kit/js-apis-app-ability-configuration.md).

  ```ts
  import { AbilityStage } from '@kit.AbilityKit';

  export default class MyAbilityStage extends AbilityStage {
    onCreate(): void {
      let abilityStageContext = this.context;
      //...
    }
  }
  ```

### Obtaining Context of Another Module in the Current Application (Module-Level Context)

Call [createModuleContext](../reference/apis-ability-kit/js-apis-app-ability-application.md#applicationcreatemodulecontext12) to obtain the context of another module in the current application. After obtaining the context, you can obtain the resource information of that module.

  ```ts
  import { common, application } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let storageEventCall = new LocalStorage();

  @Entry(storageEventCall)
  @Component
  struct Page_Context {
    private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

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
                    this.getUIContext().getPromptAction().showToast({
                      message: ('Context obtained')
                    });
                  }
                })
                .catch((err: BusinessError) => {
                  console.error(`CreateModuleContext failed, err code:${err.code}, err msg: ${err.message}`);
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

### Obtaining UIAbilityContext (Context Corresponding to the UIAbility)

The [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) class has its own context, which is an instance of the [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) class. The [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) class has attributes such as **abilityInfo** and **currentHapModuleInfo**. UIAbilityContext can be used to obtain the UIAbility configuration information, such as the code path, bundle name, ability name, and environment status required by the application. It can also be used to obtain methods to operate the UIAbility instance, such as [startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability), [connectServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability), and [terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself).

If you need to obtain the context of the current ability in the page, you can call [getHostContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12) in [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md) to obtain the UIAbilityContext or [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md) associated with the current page.

- You can use **this.context** to obtain the context of a UIAbility instance.
  
  ```ts
  import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      // Obtain the context of the UIAbility instance.
      let context = this.context;
      // ...
    }
  }
  ```
  
- Import the context module and define the **context** variable in the component.
  
  ```ts
  import { common, Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Page_EventHub {
    private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

    startAbilityTest(): void {
      let want: Want = {
        // Want parameter information.
      };
      this.context.startAbility(want);
    }

    // UI page display.
    build() {
      // ...
    }
  }
  ```

  You can also define variables after importing the context module but before using [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).

  
  ```ts
  import { common, Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Page_UIAbilityComponentsBasicUsage {
    startAbilityTest(): void {
      let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
      let want: Want = {
        // Want parameter information.
      };
      context.startAbility(want);
    }

    // UI page display.
    build() {
      // ...
    }
  }
  ```

- To stop the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) instance after the service is not needed, call [terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself).

  ```ts
  import { common } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct Page_UIAbilityComponentsBasicUsage {
    // UI page display.
    build() {
      Column() {
        //...
        Button('FuncAbilityB')
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            try {
              context.terminateSelf((err: BusinessError) => {
                if (err.code) {
                  // Process service logic errors.
                  console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}.`);
                  return;
                }
                // Carry out normal service processing.
                console.info(`terminateSelf succeed.`);
              });
            } catch (err) {
              // Capture the synchronization parameter error.
              let code = (err as BusinessError).code;
              let message = (err as BusinessError).message;
              console.error(`terminateSelf failed, code is ${code}, message is ${message}.`);
            }
          })
      }
    }
  }
  ```

### Obtaining ExtensionAbilityContext (Component-Level Context)

Obtain a scenario-specific [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md). For example, FormExtensionContext, which inherits from ExtensionContext, provides APIs related to widget services.

```ts
import { FormExtensionAbility, formBindingData } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    let formExtensionContext = this.context;
    // ...
    let dataObj1: Record<string, string> = {
      'temperature': '11c',
      'time': '11:00'
    };
    let obj1: formBindingData.FormBindingData = formBindingData.createFormBindingData(dataObj1);
    return obj1;
  }
}
```


## Typical Usage Scenarios of Context


This topic describes how to use the context in the following scenarios:

- [Obtaining Basic Information](#obtaining-basic-information)
- [Obtaining Application File Paths](#obtaining-application-file-paths)
- [Obtaining and Modifying Encryption Levels](#obtaining-and-modifying-encryption-levels)
- [Listening for Application Foreground/Background Changes](#listening-for-application-foregroundbackground-changes)
- [Listening for UIAbility Lifecycle Changes](#listening-for-uiability-lifecycle-changes)

### Obtaining Basic Information

Different types of Context classes, which inherit from [Context](../reference/apis-ability-kit/js-apis-inner-application-context.md), default to inheriting the parent class's methods and properties, as well as having their own independent methods and properties.

You can obtain basic information about the current application, module, UIAbility, or ExtensionAbility through the context property (such as the resource manager object and application information). Below is an example of acquiring information for the UIAbility.

If you need to obtain resource objects across packages, see [Accessing Resources](../quick-start/resource-categories-and-access.md#accessing-resources).

  ```ts
  import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      // Obtain a resource manager.
      let resourceManager = this.context.getApplicationContext().resourceManager;
      // Obtain application information.
      let applicationInfo = this.context.getApplicationContext().applicationInfo;
      //...
    }
  }
  ```

### Obtaining Application File Paths

The [base class Context](../reference/apis-ability-kit/js-apis-inner-application-context.md) provides the capability of obtaining application file paths. [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md), [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md), [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md), and [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md) inherit this capability. However, the specific paths retrieved can differ based on the type of the context used.

- [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md): This context provides access to the application-level file path, which is used to store global application information. Files in this path are removed when the application is uninstalled.
- [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md), [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md), and [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md): These contexts provide access to [module-level](../quick-start/application-package-overview.md) file paths. Files in these paths are removed when the corresponding [HAP](../quick-start/hap-package.md) or [HSP](../quick-start/in-app-hsp.md) module is uninstalled. Uninstalling an HAP or HSP module does not affect files under the application-level path unless all HAP and HSP modules of the application are uninstalled.

  - UIAbilityContext: This context can be used to obtain the file paths of the module containing the UIAbility.
  - ExtensionContext: This context can be used to obtain the file paths of the module containing the ExtensionAbility.
  - AbilityStageContext: Given that AbilityStageContext is initialized earlier than UIAbilityContext and ExtensionContext, it is typically used to obtain file paths within the AbilityStage.

>**NOTE**
>
> The application file paths are a type of application sandbox paths. For details, see [Application Sandbox Directory](../file-management/app-sandbox-directory.md).

  **Table 1** Description of application file paths obtained by different types of contexts
| Name| Description| Path Obtained by ApplicationContext| Path Obtained by AbilityStageContext, UIAbilityContext, and ExtensionContext|
| -------- | -------- | -------- | -------- |
| bundleCodeDir | Bundle code directory.| \<Path prefix>/el1/bundle| \<Path prefix>/el1/bundle|
| cacheDir | Cache directory.| \<Path prefix>/\<Encryption level>/base/cache| \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/cache|
| filesDir | File directory.| \<Path prefix>/\<Encryption level>/base/files| \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/files|
| preferencesDir | Preferences directory.| \<Path prefix>/\<Encryption level>/base/preferences| \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/preferences|
| tempDir | Temporary directory.| \<Path prefix>/\<Encryption level>/base/temp| \<Path prefix>/\<Encryption level>/base/**haps/\<module-name>**/temp|
| databaseDir | Database directory.| \<Path prefix>/\<Encryption level>/database| \<Path prefix>/\<Encryption level>/database/**\<module-name>**|
| distributedFilesDir | Distributed file directory.| \<Path prefix>/el2/distributedFiles| \<Path prefix>/el2/distributedFiles/|
| resourceDir<sup>11+<sup> | Resource directory.<br>**NOTE**<br> You are required to manually create the **resfile** directory in **\<module-name>\resource**.| N/A| \<Path prefix>/el1/bundle/**\<module-name>**/resources/resfile|
| cloudFileDir<sup>12+</sup> | Cloud file directory.| \<Path prefix>/el2/cloud| \<Path prefix>/el2/cloud/|

This section uses ApplicationContext to obtain **cacheDir** and **filesDir** as an example to describe how to obtain the application cache directory and application file directory, and how to use these paths to create and read/write files.

- **Obtaining the Application Cache Directory**

  ```ts
  import { common } from '@kit.AbilityKit';

  const TAG: string = '[Page_Context]';
  const DOMAIN_NUMBER: number = 0xFF00;

  @Entry
  @Component
  struct Index {
    @State message: string = 'Hello World';
    private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

    build() {
      Row() {
        Column() {
          Text(this.message)
          // ...
          Button() {
            Text('create file')
              // ...
              .onClick(() => {
                let applicationContext = this.context.getApplicationContext();
                // Obtain the application cache directory.
                let cacheDir = applicationContext.cacheDir;
              })
          }
          // ...
        }
        // ...
      }
      // ...
    }
  }
  ```

- **Obtaining the Application File Directory**
  
  ```ts
  import { common } from '@kit.AbilityKit';
  import { buffer } from '@kit.ArkTS';
  import { fileIo, ReadOptions } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  const TAG: string = '[Page_Context]';
  const DOMAIN_NUMBER: number = 0xFF00;

  @Entry
  @Component
  struct Index {
    @State message: string = 'Hello World';
    private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

    build() {
      Row() {
        Column() {
          Text(this.message)
          // ...
          Button() {
            Text('create file')
              // ...
              .onClick(() => {
                let applicationContext = this.context.getApplicationContext();
                // Obtain the application file path.
                let filesDir = applicationContext.filesDir;
                hilog.info(DOMAIN_NUMBER, TAG, `filePath: ${filesDir}`);
                // Create and open the file if it does not exist. Open the file if it already exists.
                let file = fileIo.openSync(filesDir + '/test.txt', fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
                // Write data to the file.
                let writeLen = fileIo.writeSync(file.fd, "Try to write str.");
                hilog.info(DOMAIN_NUMBER, TAG, `The length of str is: ${writeLen}`);
                // Create an ArrayBuffer object with a size of 1024 bytes to store the data read from the file.
                let arrayBuffer = new ArrayBuffer(1024);
                // Set the offset and length to read.
                let readOptions: ReadOptions = {
                  offset: 0,
                  length: arrayBuffer.byteLength
                };
                // Read the file content to the ArrayBuffer object and return the number of bytes that are actually read.
                let readLen = fileIo.readSync(file.fd, arrayBuffer, readOptions);
                // Convert the ArrayBuffer object into a Buffer object and output it as a string.
                let buf = buffer.from(arrayBuffer, 0, readLen);
                hilog.info(DOMAIN_NUMBER, TAG, `the content of file: ${buf.toString()}`);
                // Close the file.
                fileIo.closeSync(file);
              })
          }
          // ...
        }
        // ...
      }
      // ...
    }
  }
  ```

### Obtaining and Modifying Encryption Levels

Encrypting application files enhances data security by preventing files from unauthorized access. Different application files require different levels of protection.

In practice, you need to select a proper encryption level based on scenario-specific requirements to protect application data security. The proper use of EL1 and the EL2 can efficiently improve the security. For details about the permissions required for a specific encryption level, see [AreaMode](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode) in [ContextConstant](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md).

- EL1: For private files, such as alarms and wallpapers, the application can place them in a directory with the device-level encryption (EL1) to ensure that they can be accessed before the user enters the password.
- EL2: For sensitive files, such as personal privacy data, the application can place them in a directory with the user-level encryption (EL2).
- EL3: For step recording, file download, or music playback that needs to read, write, and create files when the screen is locked, the application can place these files in EL3.
- EL4: For files that are related to user security information and do not need to be read, written, or created when the screen is locked, the application can place them in EL4.
- EL5: By default, sensitive user privacy files cannot be read or written on the lock screen. If such files need to be read or written on the lock screen, you can call [acquireAccess](../reference/apis-ability-kit/js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess) to apply for reading or writing files before the screen is locked or create new files that can be read and written after the screen is locked. It is more appropriate to place these files in EL5.

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

@Entry
@Component
struct Page_Context {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

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
            if (this.context.area === contextConstant.AreaMode.EL2) { // Obtain the encryption level.
              this.context.area = contextConstant.AreaMode.EL1; // Change the encryption level.
              this.getUIContext().getPromptAction().showToast({
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
            if (this.context.area === contextConstant.AreaMode.EL1) { // Obtain the encryption level.
              this.context.area = contextConstant.AreaMode.EL2; // Change the encryption level.
              this.getUIContext().getPromptAction().showToast({
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

### Listening for Application Foreground/Background Changes

You can use the capabilities of [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) to listen for changes in the application's foreground and background state. When the application switches between foreground and background, corresponding callback functions can be triggered to execute methods that depend on the foreground/background state or to collect data on the frequency of application state changes.

The following uses [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) as an example.

```ts
import { UIAbility, ApplicationStateChangeCallback } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class LifecycleAbility extends UIAbility {
  onCreate() {
    let applicationStateChangeCallback: ApplicationStateChangeCallback = {
      onApplicationForeground() {
        console.info('applicationStateChangeCallback onApplicationForeground');
      },
      onApplicationBackground() {
        console.info('applicationStateChangeCallback onApplicationBackground');
      }
    }

    // 1. Obtain an applicationContext object.
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2. Use applicationContext.on() to subscribe to the 'applicationStateChange' event.
      applicationContext.on('applicationStateChange', applicationStateChangeCallback);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.log('Register applicationStateChangeCallback');
  }
}
```

### Listening for UIAbility Lifecycle Changes

You can use [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) to listen for lifecycle changes of a UIAbility. When the lifecycle of a [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) changes, for example, a UIAbility is created, brought to the foreground, sent to the background, or destroyed, corresponding callback functions are invoked. In this way, the methods that depend on the UIAbility lifecycle can be executed, and the dwell time and access frequency of a specified page can be collected.

Each time the callback is registered, a listener lifecycle ID is returned, with the value incremented by 1 each time. When the number of listeners exceeds the upper limit (2^63-1), **-1** is returned. The following uses [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) as an example.

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
