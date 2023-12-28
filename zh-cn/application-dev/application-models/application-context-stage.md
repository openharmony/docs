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
     import type AbilityConstant from '@ohos.app.ability.AbilityConstant';
     import type Want from '@ohos.app.ability.Want';
     export default class EntryAbility extends UIAbility {
       onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
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
     import Want from '@ohos.app.ability.Want';
     export default class MyService extends ServiceExtensionAbility {
       onCreate(want: Want) {
         let serviceExtensionContext = this.context;
         ...
       }
     }
     ```
  - 获取[AbilityStageContext](../reference/apis/js-apis-inner-application-abilityStageContext.md)。Module级别的Context，和基类Context相比，额外提供HapModuleInfo、Configuration等信息。
    
     ```ts
     import AbilityStage from '@ohos.app.ability.AbilityStage';
     export default class MyAbilityStage extends AbilityStage {
       onCreate(): void {
         let abilityStageContext = this.context;
         ...
       }
     }
     ```
  - 获取[ApplicationContext](../reference/apis/js-apis-inner-application-applicationContext.md)。应用级别的Context。ApplicationContext在基类Context的基础上提供了订阅应用内应用组件的生命周期的变化、订阅系统内存变化和订阅应用内系统环境的变化的能力，在UIAbility、ExtensionAbility、AbilityStage中均可以获取。
    
     ```ts
     import UIAbility from '@ohos.app.ability.UIAbility';
     import type AbilityConstant from '@ohos.app.ability.AbilityConstant';
     import type Want from '@ohos.app.ability.Want';
     export default class EntryAbility extends UIAbility {
       onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
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
  | bundleCodeDir | <路径前缀>/el1/bundle |
  | cacheDir | <路径前缀>/<加密等级>/base/cache |
  | filesDir | <路径前缀>/<加密等级>/base/files |
  | preferencesDir | <路径前缀>/<加密等级>/base/preferences |
  | tempDir | <路径前缀>/<加密等级>/base/temp |
  | databaseDir | <路径前缀>/<加密等级>/database |
  | distributedFilesDir | <路径前缀>/el2/distributedFiles |

  示例代码如下所示。

  ```ts
  import common from '@ohos.app.ability.common';
  import hilog from '@ohos.hilog';
  import promptAction from '@ohos.promptAction'
  
  const TAG: string = '[Page_Context]';
  const DOMAIN_NUMBER: number = 0xFF00;
  @Entry
  @Component
  struct Page_Context {
  
    private context = getContext(this) as common.UIAbilityContext;
  
    build() {
      ...
      Button(){
        .onClick(() => {
          let applicationContext = this.context.getApplicationContext();
          let cacheDir = applicationContext.cacheDir;
          let tempDir = applicationContext.tempDir;
          let filesDir = applicationContext.filesDir;
          let databaseDir = applicationContext.databaseDir;
          let bundleCodeDir = applicationContext.bundleCodeDir;
          let distributedFilesDir = applicationContext.distributedFilesDir;
          let preferencesDir = applicationContext.preferencesDir;
          // 获取应用文件路径
          let filePath = tempDir + 'test.txt';
          hilog.info(DOMAIN_NUMBER, TAG, `filePath: ${filePath}`);
          if (filePath !== null) {
            promptAction.showToast({
            message: filePath
            });
          }
        })
      }
    }
  }
  ```

- 通过AbilityStageContext、UIAbilityContext、ExtensionContext获取HAP级别的应用文件路径。此路径是HAP相关信息推荐的存放路径，这些文件会跟随HAP的卸载而删除，但不会影响应用级别路径的文件，除非该应用的HAP已全部卸载。

  | 属性 | 路径 |
  | -------- | -------- |
  | bundleCodeDir | <路径前缀>/el1/bundle |
  | cacheDir | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/cache |
  | filesDir | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/files |
  | preferencesDir | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/preferences |
  | tempDir | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/temp |
  | databaseDir | <路径前缀>/<加密等级>/database/**\<module-name>** |
  | distributedFilesDir | <路径前缀>/el2/distributedFiles/**\<module-name>** |

  示例代码如下所示。

  ```ts
  import common from '@ohos.app.ability.common';
  import hilog from '@ohos.hilog';
  import promptAction from '@ohos.promptAction'
  
  const TAG: string = '[Page_Context]';
  const DOMAIN_NUMBER: number = 0xFF00;
  @Entry
  @Component
  struct Page_Context {
  
    private context = getContext(this) as common.UIAbilityContext;
  
    build() {
      ...
      Button(){
        .onClick(() => {
          let cacheDir = this.context.cacheDir;
          let tempDir = this.context.tempDir;
          let filesDir = this.context.filesDir;
          let databaseDir = this.context.databaseDir;
          let bundleCodeDir = this.context.bundleCodeDir;
          let distributedFilesDir = this.context.distributedFilesDir;
          let preferencesDir = this.context.preferencesDir;
          // 获取应用文件路径
          let filePath = tempDir + 'test.txt';
          hilog.info(DOMAIN_NUMBER, TAG, `filePath: ${filePath}`);
          if (filePath !== null) {
            promptAction.showToast({
              message: filePath
            });
          }
        })
      }
    }
  }
  ```


### 获取和修改加密分区

应用文件加密是一种保护数据安全的方法，可以使得文件在未经授权访问的情况下得到保护。在不同的场景下，应用需要不同程度的文件保护。

在实际应用中，开发者需要根据不同场景的需求选择合适的加密分区，从而保护应用数据的安全。通过合理使用不同级别的加密分区，可以有效提高应用数据的安全性。关于不同分区的权限说明，详见[ContextConstant](../reference/apis/js-apis-app-ability-contextConstant.md)的AreaMode。

<ul>
<li>EL1：对于私有文件，如闹铃、壁纸等，应用可以将这些文件放到设备级加密分区（EL1）中，以保证在用户输入密码前就可以被访问。</li>
<li>EL2：对于更敏感的文件，如个人隐私信息等，应用可以将这些文件放到更高级别的加密分区（EL2）中，以保证更高的安全性。</li>
<li>EL3：对于应用中的记录步数、文件下载、音乐播放，需要在锁屏时读写和创建新文件，放在（EL3）的加密分区比较合适。</li>
<li>EL4：对于用户安全信息相关的文件，锁屏时不需要读写文件、也不能创建文件，放在（EL4）的加密分区更合适。</li>
</ul>

要实现获取和设置当前加密分区，可以通过读写[Context](../reference/apis/js-apis-inner-application-context.md)的`area`属性来实现。
```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import contextConstant from '@ohos.app.ability.contextConstant';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // 存储普通信息前，切换到EL1设备级加密
    this.context.area = contextConstant.AreaMode.EL1; // 切换area
    // 存储普通信息

    // 存储敏感信息前，切换到EL2用户级加密
    this.context.area = contextConstant.AreaMode.EL2; // 切换area
    // 存储敏感信息

    // 存储敏感信息前，切换到EL3用户级加密
    this.context.area = contextConstant.AreaMode.EL3; // 切换area
    // 存储敏感信息

    // 存储敏感信息前，切换到EL4用户级加密
    this.context.area = contextConstant.AreaMode.EL4; // 切换area
    // 存储敏感信息
  }
}
```
```ts
import contextConstant from '@ohos.app.ability.contextConstant';
import common from '@ohos.app.ability.common';
import hilog from '@ohos.hilog';
import promptAction from '@ohos.promptAction'

const TAG: string = '[Page_Context]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Page_Context {

  private context = getContext(this) as common.UIAbilityContext;

  build() {
    ...
    Button(){
      .onClick(() => {
        // 存储普通信息前，切换到EL1设备级加密
        if (this.context.area === contextConstant.AreaMode.EL2) { // 获取area
          this.context.area = contextConstant.AreaMode.EL1; // 修改area
          promptAction.showToast({
            message: $r('app.string.SwitchToEL1')
          });
        }
        // 存储普通信息
      })
    }
    
    ...

    Button(){
      .onClick(() => {
        // 存储敏感信息前，切换到EL2用户级加密
        if (this.context.area === contextConstant.AreaMode.EL1) { // 获取area
          this.context.area = contextConstant.AreaMode.EL2; // 修改area
          promptAction.showToast({
            message: $r('app.string.SwitchToEL2')
          });
        }
        // 存储敏感信息
      })
    }
    
    ...
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
  > - 申请`ohos.permission.GET_BUNDLE_INFO_PRIVILEGED`权限，配置方式请参见[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级的应用申请权限)。
  >
  > - 接口为系统接口，三方应用不支持调用。
  
  例如在桌面上显示的应用信息，包括应用名称和应用图标等，桌面应用可以通过调用上述的方法获取相应应用的Context信息从而获取到相应的应用名称、图标等资源信息。
  
  ```ts
  let bundleName2 = 'com.samples.stagemodelabilityinteraction';
  let bundleContext = this.context.createBundleContext(bundleName2);
  let label2 = bundleContext.applicationInfo.label;
  if (bundleContext && label2 !== null) {
    promptAction.showToast({
      message: ('成功获取Context')
    });
  }
  ```
  
- 调用`createModuleContext(bundleName:string, moduleName:string)`方法，获取指定应用指定Module的上下文信息。获取到指定应用指定Module的Context之后，即可获取到相应应用Module的资源信息。
  > **说明：**
  >
  > 当获取的是其他应用的指定Module的Context时：
  >
  > - 申请`ohos.permission.GET_BUNDLE_INFO_PRIVILEGED`权限，配置方式请参见[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级的应用申请权限)。
  >
  > - 接口为系统接口，三方应用不支持调用。
  
  ```ts
  let bundleName2 : string = 'com.samples.stagemodelabilityinteraction';
  let moduleName2 : string  = 'entry';
  let moduleContext = this.context.createModuleContext(bundleName2, moduleName2);
  if (moduleContext !== null) {
    promptAction.showToast({
      message: ('成功获取Context')
    });
  }
  ```
  
- 调用`createModuleContext(moduleName:string)`方法，获取本应用中其他Module的Context。获取到其他Module的Context之后，即可获取到相应Module的资源信息。
  
  ```ts
  let moduleName2 = 'entry';
  let moduleContext = this.context.createModuleContext(moduleName2);
  if (moduleContext !== null) {
    promptAction.showToast({
      message: ('成功获取Context')
    });
  }
  ```


### 订阅进程内UIAbility生命周期变化

在应用内的DFX统计场景中，如需要统计对应页面停留时间和访问频率等信息，可以使用订阅进程内UIAbility生命周期变化功能。

通过[ApplicationContext](../reference/apis/js-apis-inner-application-applicationContext.md)提供的能力，可以订阅进程内UIAbility生命周期变化。当进程内的UIAbility生命周期变化时，如创建、可见/不可见、获焦/失焦、销毁等，会触发相应的回调函数。每次注册回调函数时，都会返回一个监听生命周期的ID，此ID会自增+1。当超过监听上限数量2^63-1时，会返回-1。以[UIAbilityContext](../reference/apis/js-apis-inner-application-uiAbilityContext.md)中的使用为例进行说明。


```ts
import type AbilityConstant from '@ohos.app.ability.AbilityConstant';
import type AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';
import Logger from '../utils/Logger';
import UIAbility from '@ohos.app.ability.UIAbility';
import type Want from '@ohos.app.ability.Want';
import type window from '@ohos.window';

const TAG: string = '[LifecycleAbility]';

export default class LifecycleAbility extends UIAbility {
  // 定义生命周期ID
  lifecycleId: number = -1;

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // 定义生命周期回调对象
    let abilityLifecycleCallback: AbilityLifecycleCallback = {
      // 当UIAbility创建时被调用
      onAbilityCreate(uiAbility) {
        Logger.info(TAG, `onAbilityCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当窗口创建时被调用
      onWindowStageCreate(uiAbility, windowStage: window.WindowStage) {
        Logger.info(TAG, `onWindowStageCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        Logger.info(TAG, `onWindowStageCreate windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当窗口处于活动状态时被调用
      onWindowStageActive(uiAbility, windowStage: window.WindowStage) {
        Logger.info(TAG, `onWindowStageActive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        Logger.info(TAG, `onWindowStageActive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当窗口处于非活动状态时被调用
      onWindowStageInactive(uiAbility, windowStage: window.WindowStage) {
        Logger.info(TAG, `onWindowStageInactive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        Logger.info(TAG, `onWindowStageInactive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当窗口被销毁时被调用
      onWindowStageDestroy(uiAbility, windowStage: window.WindowStage) {
        Logger.info(TAG, `onWindowStageDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        Logger.info(TAG, `onWindowStageDestroy windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当UIAbility被销毁时被调用
      onAbilityDestroy(uiAbility) {
        Logger.info(TAG, `onAbilityDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当UIAbility从后台转到前台时触发回调
      onAbilityForeground(uiAbility) {
        Logger.info(TAG, `onAbilityForeground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当UIAbility从前台转到后台时触发回调
      onAbilityBackground(uiAbility) {
        Logger.info(TAG, `onAbilityBackground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当UIAbility迁移时被调用
      onAbilityContinue(uiAbility) {
        Logger.info(TAG, `onAbilityContinue uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      }
    };
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 注册应用内生命周期回调
    this.lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
    Logger.info(TAG, `register callback number: ${this.lifecycleId}`);
  }

  ...

  onDestroy() : void {
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    // 取消应用内生命周期回调
    applicationContext.off('abilityLifecycle', this.lifecycleId);
  }
};
```
