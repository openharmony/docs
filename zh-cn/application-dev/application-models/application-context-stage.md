# 应用上下文Context


## 概述

[Context](../reference/apis-ability-kit/js-apis-inner-application-context.md)是应用中对象的上下文，其提供了应用的一些基础信息，例如[resourceManager](../reference/apis-localization-kit/js-apis-resource-manager.md)（资源管理）、[applicationInfo](../reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md)（当前应用信息）、[dir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context-1)（应用文件路径）、[area](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode)（文件分区）等，以及应用的一些基本方法，例如<!--Del-->[createBundleContext()](../reference/apis-ability-kit/js-apis-app-ability-application-sys.md#applicationcreatebundlecontext12)、<!--DelEnd-->[getApplicationContext()](../reference/apis-ability-kit/js-apis-inner-application-context.md#getapplicationcontext)等。[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)组件和各种[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)派生类组件都有各自不同的Context类。分别有基类Context、[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)、[AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md)、[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)、[ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md)<!--Del-->、[ServiceExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md)<!--DelEnd-->等Context。各类Context的继承和持有关系详见[不同类型Context的继承和持有关系](../reference/apis-ability-kit/js-apis-inner-application-context.md#不同类型context的继承和持有关系)。

> **说明**
>
> [UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md)是指UI实例上下文，用于关联窗口与UI页面。与本文档中的应用上下文Context无直接关联，不存在继承或持有关系。

- 应用Context的获取方式
  - 获取[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。每个[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)中都包含了一个Context属性，提供操作应用组件、获取应用组件的配置信息等能力。

    ```ts
    import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        let uiAbilityContext = this.context;
        //...
      }
    }
    ```

     > **说明：**
     >
     > 页面中获取UIAbility实例的上下文信息请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
  - 获取特定场景[ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md)。以FormExtensionContext为例，表示卡片服务的上下文环境，继承自ExtensionContext，提供卡片服务相关的接口能力。

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
  - 获取[AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md)（Module级别的Context）。和基类Context相比，额外提供[HapModuleInfo](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md#属性)、[Configuration](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md#属性)等信息。

    ```ts
    import { AbilityStage } from '@kit.AbilityKit';

    export default class MyAbilityStage extends AbilityStage {
      onCreate(): void {
        let abilityStageContext = this.context;
        //...
      }
    }
    ```
  - 获取[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)（应用级别的Context）。ApplicationContext在基类Context的基础上提供了订阅应用内应用组件的生命周期的变化、订阅系统内存变化、订阅应用内系统环境变化、设置应用语言、设置应用颜色模式、清除应用自身数据的同时撤销应用向用户申请的权限等能力，在[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)、[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)、[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)中均可以获取。

    ```ts
    import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        let applicationContext = this.context.getApplicationContext();
        //...
      }
    }
    ```


## Context的典型使用场景


本章节通过如下典型场景来介绍Context的用法：

- [获取应用文件路径](#获取应用文件路径)
- [获取和修改加密分区](#获取和修改加密分区)
- [获取本应用中其他module的context](#获取本应用中其他module的context)
- [订阅进程内UIAbility生命周期变化](#订阅进程内uiability生命周期变化)


### 获取应用文件路径

[基类Context](../reference/apis-ability-kit/js-apis-inner-application-context.md)提供了获取应用文件路径的能力，[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)、[AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md)、[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)和[ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md)均继承该能力。不同类型的Context获取的路径可能存在差异。

- 通过[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)可以获取应用级的文件路径。该路径用于存放应用全局信息，路径下的文件会跟随应用的卸载而删除。
- 通过[AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md)、[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)、[ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md)，可以获取[Module](../quick-start/application-package-overview.md)级的文件路径。该路径用于存放Module相关信息，路径下的文件会跟随[HAP](../quick-start/hap-package.md)/[HSP](../quick-start/in-app-hsp.md)的卸载而删除。HAP/HSP的卸载不会影响应用级路径下的文件，除非该应用的HAP/HSP已全部卸载。

  - UIAbilityContext：可以获取UIAbility所在Module的文件路径。
  - ExtensionContext：可以获取ExtensionAbility所在Module的文件路径。
  - AbilityStageContext：由于AbilityStageContext创建时机早于UIAbilityContext和ExtensionContext，通常用于在AbilityStage中获取文件路径。

>**说明：**
>
> 应用文件路径属于应用沙箱路径，具体请参见[应用沙箱目录](../file-management/app-sandbox-directory.md)。

  **表1** 不同级别Context获取的应用文件路径说明
  | 属性 | 说明 | ApplicationContext获取的路径 | AbilityStageContext、UIAbilityContext、ExtensionContext获取的路径 |
  | -------- | -------- | -------- | -------- |
  | bundleCodeDir | 安装包目录。 | <路径前缀>/el1/bundle | <路径前缀>/el1/bundle |
  | cacheDir | 缓存目录。 | <路径前缀>/<加密等级>/base/cache | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/cache |
  | filesDir | 文件目录。 | <路径前缀>/<加密等级>/base/files | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/files |
  | preferencesDir | preferences目录。 | <路径前缀>/<加密等级>/base/preferences | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/preferences |
  | tempDir | 临时目录。 | <路径前缀>/<加密等级>/base/temp | <路径前缀>/<加密等级>/base/**haps/\<module-name>**/temp |
  | databaseDir | 数据库目录。 | <路径前缀>/<加密等级>/database | <路径前缀>/<加密等级>/database/**\<module-name>** |
  | distributedFilesDir | 分布式文件目录。 | <路径前缀>/el2/distributedFiles | <路径前缀>/el2/distributedFiles/ |
  | resourceDir<sup>11+<sup> | 资源目录。<br/>**说明：**<br/> 需要开发者手动在`\<module-name>\resource`路径下创建`resfile`目录。 | 不涉及 | <路径前缀>/el1/bundle/**\<module-name>**/resources/resfile |
  | cloudFileDir<sup>12+</sup> | 云文件目录。 | <路径前缀>/el2/cloud | <路径前缀>/el2/cloud/ |

  本节以使用ApplicationContext获取filesDir为例，介绍如何获取应用文件路径，并在对应文件路径下新建文件和读写文件。示例代码如下：

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
                // 获取应用文件路径
                let filesDir = applicationContext.filesDir;
                hilog.info(DOMAIN_NUMBER, TAG, `filePath: ${filesDir}`);
                // 文件不存在时创建并打开文件，文件存在时打开文件
                let file = fileIo.openSync(filesDir + '/test.txt', fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
                // 写入一段内容至文件
                let writeLen = fileIo.writeSync(file.fd, "Try to write str.");
                hilog.info(DOMAIN_NUMBER, TAG, `The length of str is: ${writeLen}`);
                // 创建一个大小为1024字节的ArrayBuffer对象，用于存储从文件中读取的数据
                let arrayBuffer = new ArrayBuffer(1024);
                // 设置读取的偏移量和长度
                let readOptions: ReadOptions = {
                  offset: 0,
                  length: arrayBuffer.byteLength
                };
                // 读取文件内容到ArrayBuffer对象中，并返回实际读取的字节数
                let readLen = fileIo.readSync(file.fd, arrayBuffer, readOptions);
                // 将ArrayBuffer对象转换为Buffer对象，并转换为字符串输出
                let buf = buffer.from(arrayBuffer, 0, readLen);
                hilog.info(DOMAIN_NUMBER, TAG, `the content of file: ${buf.toString()}`);
                // 关闭文件
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


### 获取和修改加密分区

应用文件加密是一种保护数据安全的方法，可以使得文件在未经授权访问的情况下得到保护。在不同的场景下，应用需要不同程度的文件保护。

在实际应用中，开发者需要根据不同场景的需求选择合适的加密分区，从而保护应用数据的安全。通过合理使用不同级别的加密分区，可以有效提高应用数据的安全性。关于不同分区的权限说明，详见[ContextConstant](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md)的[AreaMode](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode)。

- EL1：对于私有文件，如闹铃、壁纸等，应用可以将这些文件放到设备级加密分区（EL1）中，以保证在用户输入密码前就可以被访问。
- EL2：对于更敏感的文件，如个人隐私信息等，应用可以将这些文件放到更高级别的加密分区（EL2）中，以保证更高的安全性。
- EL3：对于应用中的记录步数、文件下载、音乐播放，需要在锁屏时读写和创建新文件，放在（EL3）的加密分区比较合适。
- EL4：对于用户安全信息相关的文件，锁屏时不需要读写文件、也不能创建文件，放在（EL4）的加密分区更合适。
- EL5：对于用户隐私敏感数据文件，锁屏后默认不可读写，如果锁屏后需要读写文件，则锁屏前可以调用[Access](../reference/apis-ability-kit/js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess)接口申请继续读写文件，或者锁屏后也需要创建新文件且可读写，放在（EL5）的应用级加密分区更合适。

要实现获取和设置当前加密分区，可以通过读写[Context](../reference/apis-ability-kit/js-apis-inner-application-context.md)的`area`属性来实现。

```ts
// EntryAbility.ets
import { UIAbility, contextConstant, AbilityConstant, Want } from '@kit.AbilityKit';

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

    // 存储敏感信息前，切换到EL5应用级加密
    this.context.area = contextConstant.AreaMode.EL5; // 切换area
    // 存储敏感信息
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
            // 存储普通信息前，切换到EL1设备级加密
            if (this.context.area === contextConstant.AreaMode.EL2) { // 获取area
              this.context.area = contextConstant.AreaMode.EL1; // 修改area
              this.getUIContext().getPromptAction().showToast({
                message: 'SwitchToEL1'
              });
            }
            // 存储普通信息
          })
        }
        //...
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            // 存储敏感信息前，切换到EL2用户级加密
            if (this.context.area === contextConstant.AreaMode.EL1) { // 获取area
              this.context.area = contextConstant.AreaMode.EL2; // 修改area
              this.getUIContext().getPromptAction().showToast({
                message: 'SwitchToEL2'
              });
            }
            // 存储敏感信息
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


### 获取本应用中其他Module的Context

调用[createModuleContext(context: Context, moduleName: string)](../reference/apis-ability-kit/js-apis-app-ability-application.md#applicationcreatemodulecontext12)方法，获取本应用中其他Module的Context。获取到其他Module的Context之后，即可获取到相应Module的资源信息。

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
                      message: ('成功获取Context')
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


### 订阅进程内UIAbility生命周期变化

在应用内的DFX统计场景中，如需要统计对应页面停留时间和访问频率等信息，可以使用订阅进程内[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)生命周期变化功能。

通过[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)提供的能力，可以订阅进程内UIAbility生命周期变化。当进程内的UIAbility生命周期变化时，如创建、可见/不可见、获焦/失焦、销毁等，会触发相应的回调函数。每次注册回调函数时，都会返回一个监听生命周期的ID，此ID会自增+1。当超过监听上限数量2^63-1时，会返回-1。以[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)中的使用为例进行说明。


```ts
import { AbilityConstant, AbilityLifecycleCallback, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import  { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[LifecycleAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class LifecycleAbility extends UIAbility {
  // 定义生命周期ID
  lifecycleId: number = -1;

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // 定义生命周期回调对象
    let abilityLifecycleCallback: AbilityLifecycleCallback = {
      // 当UIAbility创建时被调用
      onAbilityCreate(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当窗口创建时被调用
      onWindowStageCreate(uiAbility, windowStage: window.WindowStage) {
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageCreate uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageCreate windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当窗口处于活动状态时被调用
      onWindowStageActive(uiAbility, windowStage: window.WindowStage) {
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageActive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageActive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当窗口处于非活动状态时被调用
      onWindowStageInactive(uiAbility, windowStage: window.WindowStage) {
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageInactive uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageInactive windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当窗口被销毁时被调用
      onWindowStageDestroy(uiAbility, windowStage: window.WindowStage) {
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
        hilog.info(DOMAIN_NUMBER, TAG, `onWindowStageDestroy windowStage: ${JSON.stringify(windowStage)}`);
      },
      // 当UIAbility被销毁时被调用
      onAbilityDestroy(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityDestroy uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当UIAbility从后台转到前台时触发回调
      onAbilityForeground(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityForeground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当UIAbility从前台转到后台时触发回调
      onAbilityBackground(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityBackground uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      },
      // 当UIAbility迁移时被调用
      onAbilityContinue(uiAbility) {
        hilog.info(DOMAIN_NUMBER, TAG, `onAbilityContinue uiAbility.launchWant: ${JSON.stringify(uiAbility.launchWant)}`);
      }
    };
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 注册应用内生命周期回调
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
    // 获取应用上下文
    let applicationContext = this.context.getApplicationContext();
    try {
      // 取消应用内生命周期回调
      applicationContext.off('abilityLifecycle', this.lifecycleId);
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      hilog.error(DOMAIN_NUMBER, TAG, `Failed to unregister applicationContext. Code is ${code}, message is ${message}`);
    }
  }
}
```
