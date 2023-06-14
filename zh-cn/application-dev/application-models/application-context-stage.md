# 应用上下文Context


## 概述

[Context](../reference/apis/js-apis-inner-application-context.md)是应用中对象的上下文，其提供了应用的一些基础信息，例如resourceManager（资源管理）、applicationInfo（当前应用信息）、dir（应用文件路径）、area（文件分区）等，以及应用的一些基本方法，例如createBundleContext()、getApplicationContext()等。UIAbility组件和各种ExtensionAbility派生类组件都有各自不同的Context类。分别有基类Context、ApplicationContext、AbilityStageContext、UIAbilityContext、ExtensionContext、ServiceExtensionContext等Context。

- 各类Context的继承关系  
  ![context-inheritance](figures/context-inheritance.png)
  
- 各类Context的持有关系  
  ![context-holding](figures/context-holding.png)
  
- 各类Context的获取方式
  - 获取[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)。每个UIAbility中都包含了一个Context属性，提供操作应用组件、获取应用组件的配置信息等能力。
    
     ```ts
     import UIAbility from '@ohos.app.ability.UIAbility';
     export default class EntryAbility extends UIAbility {
       onCreate(want, launchParam) {
         let uiAbilityContext = this.context;
         ...
       }
     }
     ```
     
     > **说明：**
     >
     > 页面中获取UIAbility实例的上下文信息请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
  - 获取特定场景[ExtensionContext](../reference/apis/js-apis-inner-application-extensionContext.md)。以ServiceExtensionContext为例，表示后台服务的上下文环境，继承自ExtensionContext，提供后台服务相关的接口能力。
    
     ```ts
     import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
     export default class MyService extends ServiceExtensionAbility {
       onCreate(want) {
         let serviceExtensionContext = this.context;
         ...
       }
     }
     ```
  - 获取[AbilityStageContext](../reference/apis/js-apis-inner-application-abilityStageContext.md)。Module级别的Context，和基类Context相比，额外提供HapModuleInfo、Configuration等信息。
    
     ```ts
     import AbilityStage from '@ohos.app.ability.AbilityStage';
     export default class MyAbilityStage extends AbilityStage {
       onCreate() {
         let abilityStageContext = this.context;
         ...
       }
     }
     ```
  - 获取[ApplicationContext](../reference/apis/js-apis-inner-application-applicationContext.md)。应用级别的Context。ApplicationContext在基类Context的基础上提供了订阅应用内应用组件的生命周期的变化、订阅系统内存变化和订阅应用内系统环境的变化的能力，在UIAbility、ExtensionAbility、AbilityStage中均可以获取。
    
     ```ts
     import UIAbility from '@ohos.app.ability.UIAbility';
     export default class EntryAbility extends UIAbility {
       onCreate(want, launchParam) {
         let applicationContext = this.context.getApplicationContext();
         ...
       }
     }
     ```


## Context的典型使用场景


本章节通过如下典型场景来介绍Context的用法：


- [获取应用文件路径](#获取应用文件路径)
- [获取和修改加密分区](#获取和修改加密分区)
- [创建其他应用或其他Module的Context](#创建其他应用或其他module的context)
- [订阅进程内UIAbility生命周期变化](#订阅进程内uiability生命周期变化)


### 获取应用文件路径

[基类Context](../reference/apis/js-apis-inner-application-context.md)提供了获取应用文件路径的能力，ApplicationContext、AbilityStageContext、UIAbilityContext和ExtensionContext均继承该能力。应用文件路径属于应用沙箱路径，具体请参见[应用沙箱目录](../file-management/app-sandbox-directory.md)。

上述各类Context获取的应用文件路径有所不同。

- 通过ApplicationContext获取应用级别的应用文件路径，此路径是应用全局信息推荐的存放路径，这些文件会跟随应用的卸载而删除。

  | 属性 | 路径 |
  | -------- | -------- |
  | bundleCodeDir | <路径前缀>/el1/bundle/ |
  | cacheDir | <路径前缀>/<加密等级>/base/cache/ |
  | filesDir | <路径前缀>/<加密等级>/base/files/ |
  | preferencesDir | <路径前缀>/<加密等级>/base/preferences/ |
  | tempDir | <路径前缀>/<加密等级>/base/temp/ |
  | databaseDir | <路径前缀>/<加密等级>/database/ |
  | distributedFilesDir | <路径前缀>/el2/distributedFiles/ |

  示例代码如下所示。

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

- 通过AbilityStageContext、UIAbilityContext、ExtensionContext获取HAP级别的应用文件路径。此路径是HAP相关信息推荐的存放路径，这些文件会跟随HAP的卸载而删除，但不会影响应用级别路径的文件，除非该应用的HAP已全部卸载。

  | 属性 | 路径 |
  | -------- | -------- |
  | bundleCodeDir | <路径前缀>/el1/bundle/ |
  | cacheDir | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/cache/ |
  | filesDir | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/files/ |
  | preferencesDir | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/preferences/ |
  | tempDir | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/temp/ |
  | databaseDir | <路径前缀>/<加密等级>/database/**\<module-name>**/ |
  | distributedFilesDir | <路径前缀>/el2/distributedFiles/**\<module-name>**/ |

  示例代码如下所示。

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


### 获取和修改加密分区

应用文件加密是一种保护数据安全的方法，可以使得文件在未经授权访问的情况下得到保护。在不同的场景下，应用需要不同程度的文件保护。对于私有文件，如闹铃、壁纸等，应用需要将这些文件放到设备级加密分区（EL1）中，以保证在用户输入密码前就可以被访问；对于更敏感的文件，如个人隐私信息等，应用需要将这些文件放到更高级别的加密分区（EL2）中，以保证更高的安全性。

在实际应用中，开发者需要根据不同场景的需求选择合适的加密分区，从而保护应用数据的安全。通过合理使用EL1和EL2加密分区，可以有效提高应用数据的安全性。

> **说明：**
>
> - AreaMode.EL1：设备级加密区，设备开机后可访问的数据区。
>
> - AreaMode.EL2：用户级加密区，设备开机，首次输入密码后才能够访问的数据区。

要实现获取和设置当前加密分区，可以通过读写[Context](../reference/apis/js-apis-inner-application-context.md)的`area`属性来实现。

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import contextConstant from '@ohos.app.ability.contextConstant';

export default class EntryAbility extends UIAbility {
  onCreate(want, launchParam) {
    // 存储普通信息前，切换到EL1设备级加密
    if (this.context.area === contextConstant.AreaMode.EL2) { // 获取area
      this.context.area = contextConstant.AreaMode.EL1; // 修改area
    }
    // 存储普通信息

    // 存储敏感信息前，切换到EL2用户级加密
    if (this.context.area === contextConstant.AreaMode.EL1) { // 获取area
      this.context.area = contextConstant.AreaMode.EL2; // 修改area
    }
    // 存储敏感信息
  }
}
```


### 创建其他应用或其他Module的Context

基类Context提供创建其他应用或其他Module的Context的方法有[createBundleContext(bundleName: string)](../reference/apis/js-apis-inner-application-context.md#contextcreatebundlecontext)、[createModuleContext(moduleName: string)](../reference/apis/js-apis-inner-application-context.md#contextcreatemodulecontext)和[createModuleContext(bundleName: string, moduleName: string)](../reference/apis/js-apis-inner-application-context.md#contextcreatemodulecontext-1)接口，创建其他应用或者其他Module的Context，从而通过该Context获取相应的资源信息（例如获取其他Module的[获取应用文件路径](#获取应用文件路径)信息）。

- 调用`createBundleContext(bundleName:string)`方法，创建其他应用的Context信息。
  > **说明：**
  >
  > 当获取的是其他应用的Context时：
  >
  > - 申请`ohos.permission.GET_BUNDLE_INFO_PRIVILEGED`权限，配置方式请参见[配置文件权限声明](../security/accesstoken-guidelines.md#配置文件权限声明)。
  >
  > - 接口为系统接口，三方应用不支持调用。
  
  例如在桌面上显示的应用信息，包括应用名称和应用图标等，桌面应用可以通过调用上述的方法获取相应应用的Context信息从而获取到相应的应用名称、图标等资源信息。
  
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
  
- 调用`createModuleContext(bundleName:string, moduleName:string)`方法，获取指定应用指定Module的上下文信息。获取到指定应用指定Module的Context之后，即可获取到相应应用Module的资源信息。
  > **说明：**
  >
  > 当获取的是其他应用的指定Module的Context时：
  >
  > - 申请`ohos.permission.GET_BUNDLE_INFO_PRIVILEGED`权限，配置方式请参见[配置文件权限声明](../security/accesstoken-guidelines.md#配置文件权限声明)。
  >
  > - 接口为系统接口，三方应用不支持调用。
  
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
  
- 调用`createModuleContext(moduleName:string)`方法，获取本应用中其他Module的Context。获取到其他Module的Context之后，即可获取到相应Module的资源信息。
  
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


### 订阅进程内UIAbility生命周期变化

在应用内的DFX统计场景中，如需要统计对应页面停留时间和访问频率等信息，可以使用订阅进程内UIAbility生命周期变化功能。

通过[ApplicationContext](../reference/apis/js-apis-inner-application-applicationContext.md)提供的能力，可以订阅进程内UIAbility生命周期变化。当进程内的UIAbility生命周期变化时，如创建、可见/不可见、获焦/失焦、销毁等，会触发相应的回调函数。每次注册回调函数时，都会返回一个监听生命周期的ID，此ID会自增+1。当超过监听上限数量2^63-1时，会返回-1。以[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)中的使用为例进行说明。


```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

const TAG: string = '[Example].[Entry].[EntryAbility]';

export default class EntryAbility extends UIAbility {
  // 定义生命周期ID
  lifecycleId: number;

  onCreate(want, launchParam) {
    // 定义生命周期回调对象
    let abilityLifecycleCallback = {
      // 当UIAbility创建时被调用
      onAbilityCreate(uiAbility) {
        console.info(TAG, `onAbilityCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当窗口创建时被调用
      onWindowStageCreate(uiAbility, windowStage: window.WindowStage) {
        console.info(TAG, `onWindowStageCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        console.info(TAG, `onWindowStageCreate windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当窗口处于活动状态时被调用
      onWindowStageActive(uiAbility, windowStage: window.WindowStage) {
        console.info(TAG, `onWindowStageActive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        console.info(TAG, `onWindowStageActive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当窗口处于非活动状态时被调用
      onWindowStageInactive(uiAbility, windowStage: window.WindowStage) {
        console.info(TAG, `onWindowStageInactive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        console.info(TAG, `onWindowStageInactive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当窗口被销毁时被调用
      onWindowStageDestroy(uiAbility, windowStage: window.WindowStage) {
        console.info(TAG, `onWindowStageDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        console.info(TAG, `onWindowStageDestroy windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当UIAbility被销毁时被调用
      onAbilityDestroy(uiAbility) {
        console.info(TAG, `onAbilityDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当UIAbility从后台转到前台时触发回调
      onAbilityForeground(uiAbility) {
        console.info(TAG, `onAbilityForeground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当UIAbility从前台转到后台时触发回调
      onAbilityBackground(uiAbility) {
        console.info(TAG, `onAbilityBackground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当UIAbility迁移时被调用
      onAbilityContinue(uiAbility) {
        console.info(TAG, `onAbilityContinue uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      }
    }
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 注册应用内生命周期回调
    this.lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
    console.info(TAG, `register callback number: ${this.lifecycleId}`);
  }

  ...

  onDestroy() {
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 取消应用内生命周期回调
    applicationContext.off('abilityLifecycle', this.lifecycleId);
  }
}
```
