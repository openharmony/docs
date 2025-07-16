# 应用上下文Context


## 概述

[Context](../reference/apis-ability-kit/js-apis-inner-application-context.md)是应用中对象的上下文，其提供了应用的一些基础信息，例如[resourceManager](../reference/apis-localization-kit/js-apis-resource-manager.md)（资源管理）、[applicationInfo](../reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md)（当前应用信息）、[dir](../reference/apis-ability-kit/js-apis-inner-application-context.md#context)（应用文件路径）、[area](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode)（文件分区）等。

## 不同类型Context的对比

[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)组件和各种[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)派生类组件都有各自不同的Context类。分别有基类Context、[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)、[AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md)、[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)、[ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md)<!--Del-->、[ServiceExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md)<!--DelEnd-->等Context。各类Context的继承和持有关系详见[不同类型Context的继承和持有关系](../reference/apis-ability-kit/js-apis-inner-application-context.md#不同类型context的继承和持有关系)。

不同类型Context的获取方式与使用场景说明，如下表所示。

> **说明：**
>
> 不同类型的Context具有不同的能力，不可相互替代或强行转换。例如，[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)绑定了[setFontSizeScale](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextsetfontsizescale13)方法，但[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)中没有此方法。因此，即使将UIAbilityContext强行转换为ApplicationContext，也无法调用setFontSizeScale方法。

   **表1** 不同类型Context的说明

  | Context类型 | 说明 | 获取方式 | 使用场景 |
  | -------- | -------- | -------- | -------- |
  | [ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md) | 应用的全局上下文，提供应用级别的信息和能力。| - 从API version 14开始，可以直接使用[getApplicationContext](../reference/apis-ability-kit/js-apis-app-ability-application.md#applicationgetapplicationcontext14)获取。<br>- API version 14以前版本，只能使用其他Context实例的[getApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-context.md#getapplicationcontext)方法获取。 | - [获取当前应用的基本信息](#获取基本信息)。<br>- [获取应用级别的文件路径](#获取应用文件路径)。<br>- [获取和修改加密分区](#获取和修改加密分区)。<br>- [注册生命周期监听](#监听应用前后台变化)。 |
  | [AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md) | 模块级别的上下文，提供模块级别的信息和能力。| - 如果需要获取当前AbilityStage的Context，可以直接通过AbilityStage实例获取[context](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#属性)属性。<br> - 如果需要获取同一应用中其他Module的Context，可以通过[createModuleContext](../reference/apis-ability-kit/js-apis-app-ability-application.md#applicationcreatemodulecontext12)方法。 | - 获取当前模块的基本信息。<br>- [获取模块的文件路径](#获取应用文件路径)。|
  | [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | UIAbility组件对应的上下文，提供UIAbility对外的信息和能力。| - 通过UIAbility实例直接获取[context](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#属性)属性。<br>- 在UIAbility的窗口中加载的UI组件实例，需要使用UIContext的[getHostContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#gethostcontext12)方法。 | - 获取当前UIAbility基本信息。<br>- 启动其他应用或原子化服务、连接/断连系统应用创建的ServiceExtensionAbility等。<br>- 销毁自身的UIAbility。 |
  | [ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md) | ExtensionAbility组件对应的上下文，每种类型的ExtensionContext提供不同的信息和能力。| 通过ExtensionAbility实例直接获取Context属性。 | 不同类型的ExtensionAbility对应的Context提供的能力不同。以输入法上下文[InputMethodExtensionContext](../reference/apis-ime-kit/js-apis-inputmethod-extension-context.md)为例，主要提供如下能力：<br>- 获取InputMethodExtensionAbility的基本信息。<br>- 销毁当前输入法。|
| [UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md) | ArkUI的UI实例上下文，提供UI操作相关的能力。与上述其他类型的Context无直接关系。 | - 在UI组件内获取UIContext，直接使用[getHostContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#gethostcontext12)方法。<br>- 在存在Window实例的情况下，使用Window提供的[getUIContext](../reference/apis-arkui/arkts-apis-window-Window.md#getuicontext10)方法。 | 主要用于UI实例中UI相关操作，例如：<br>- 获取当前UI实例的字体。<br>- 显示不同类型的弹框。<br>- 设置软键盘弹出时UI避让模式。 |

## Context的获取方式

开发者如果需要通过Context获取应用资源、应用路径等信息，或者使用Context提供的方法来实现应用跳转、设置环境变量、清理数据、获取权限等操作，需要先获取对应的Context。本节分别介绍不同类型Context的获取方式与使用场景。

### 获取ApplicationContext（应用的全局上下文）

[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)在基类Context的基础上提供了监听应用内应用组件的生命周期的变化、监听系统内存变化、监听应用内系统环境变化、设置应用语言、设置应用颜色模式、清除应用自身数据的同时撤销应用向用户申请的权限等能力，在[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)、[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)、[AbilityStage](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md)中均可以获取。

  ```ts
  import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      let applicationContext = this.context.getApplicationContext();
      //...
    }
  }
  ```

### 获取AbilityStageContext（模块级别的上下文）

[AbilityStageContext](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md)和基类Context相比，额外提供[HapModuleInfo](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md#属性)、[Configuration](../reference/apis-ability-kit/js-apis-inner-application-abilityStageContext.md#属性)等信息。

  ```ts
  import { AbilityStage } from '@kit.AbilityKit';

  export default class MyAbilityStage extends AbilityStage {
    onCreate(): void {
      let abilityStageContext = this.context;
      //...
    }
  }
  ```

### 获取本应用中其他Module的Context（模块级别的上下文）

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

### 获取UIAbilityContext（UIAbility组件对应的上下文）

[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)类拥有自身的上下文信息，该信息为[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)类的实例，[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)类拥有abilityInfo、currentHapModuleInfo等属性。通过UIAbilityContext可以获取UIAbility的相关配置信息，如包代码路径、Bundle名称、Ability名称和应用程序需要的环境状态等属性信息，以及可以获取操作UIAbility实例的方法（如[startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability)、[connectServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability)、[terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself)等）。
如果需要在页面中获得当前Ability的Context，可使用[UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md)中的[getHostContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#gethostcontext12)接口获取当前页面关联的UIAbilityContext或[ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md)。

- 在UIAbility中可以通过`this.context`获取UIAbility实例的上下文信息。
  
  ```ts
  import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      // 获取UIAbility实例的上下文
      let context = this.context;
      // ...
    }
  }
  ```
  
- 在页面中获取UIAbility实例的上下文信息，包括导入依赖资源context模块和在组件中定义一个context变量两个部分。
  
  ```ts
  import { common, Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Page_EventHub {
    private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

    startAbilityTest(): void {
      let want: Want = {
        // Want参数信息
      };
      this.context.startAbility(want);
    }

    // 页面展示
    build() {
      // ...
    }
  }
  ```

  也可以在导入依赖资源context模块后，在具体使用[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)前进行变量定义。

  
  ```ts
  import { common, Want } from '@kit.AbilityKit';

  @Entry
  @Component
  struct Page_UIAbilityComponentsBasicUsage {
    startAbilityTest(): void {
      let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
      let want: Want = {
        // Want参数信息
      };
      context.startAbility(want);
    }

    // 页面展示
    build() {
      // ...
    }
  }
  ```

- 当业务完成后，开发者如果想要终止当前[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)实例，可以通过调用[terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself)方法实现。

  ```ts
  import { common } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct Page_UIAbilityComponentsBasicUsage {
    // 页面展示
    build() {
      Column() {
        //...
        Button('FuncAbilityB')
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            try {
              context.terminateSelf((err: BusinessError) => {
                if (err.code) {
                  // 处理业务逻辑错误
                  console.error(`terminateSelf failed, code is ${err.code}, message is ${err.message}.`);
                  return;
                }
                // 执行正常业务
                console.info(`terminateSelf succeed.`);
              });
            } catch (err) {
              // 捕获同步的参数错误
              let code = (err as BusinessError).code;
              let message = (err as BusinessError).message;
              console.error(`terminateSelf failed, code is ${code}, message is ${message}.`);
            }
          })
      }
    }
  }
  ```

### 获取ExtensionAbilityContext (组件级的Context)

获取特定场景[ExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-extensionContext.md)。以FormExtensionContext为例，表示卡片服务的上下文环境，继承自ExtensionContext，提供卡片服务相关的接口能力。

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
  

## Context的典型使用场景


本章节通过以下具体场景来介绍Context的用法：

- [获取基本信息](#获取基本信息)
- [获取应用文件路径](#获取应用文件路径)
- [获取和修改加密分区](#获取和修改加密分区)
- [监听应用前后台变化](#监听应用前后台变化)
- [监听UIAbility生命周期变化](#监听uiability生命周期变化)

### 获取基本信息

继承自[Context](../reference/apis-ability-kit/js-apis-inner-application-context.md)的不同类型Context，默认会继承父类的方法和属性，还会拥有自己独立的方法与属性。

通过Context属性可以获取当前应用、模块、UIAbility或ExtensionAbility的基本信息（例如资源管理对象、应用程序信息等），下面以UIAbility的信息获取为例：

如果需要跨包获取资源对象，可以参考[资源访问](../quick-start/resource-categories-and-access.md#资源访问)。

  ```ts
  import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

  export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      // 获取ResourceManager（资源管理）
      let resourceManager = this.context.getApplicationContext().resourceManager;
      // 获取applicationInfo（当前应用信息）
      let applicationInfo = this.context.getApplicationContext().applicationInfo;
      //...
    }
  }
  ```

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

本节以使用ApplicationContext获取cacheDir和filesDir为例，分别介绍如何获取应用缓存目录，以及如何获取应用文件目录，并用于新建文件和读写文件。

- **获取应用缓存目录**

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
                // 获取应用缓存路径
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

- **获取应用文件目录**
  
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

在实际应用中，开发者需要根据不同场景的需求选择合适的加密分区，从而保护应用数据的安全。通过合理使用不同级别的加密分区，可以有效提升应用数据的安全性。关于不同分区的权限说明，详见[ContextConstant](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md)的[AreaMode](../reference/apis-ability-kit/js-apis-app-ability-contextConstant.md#areamode)。

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

### 监听应用前后台变化
  
开发者可以使用[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)的相关能力，监听应用的前后台变化。当应用前后台切换时，可以收到相应回调函数的通知，从而执行一些依赖前后台的方法，或者进行应用前后台切换频率等数据统计。

以[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)中的使用为例进行说明。

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

    // 1.获取applicationContext
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2.通过applicationContext注册应用前后台状态监听
      applicationContext.on('applicationStateChange', applicationStateChangeCallback);
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.log('Register applicationStateChangeCallback');
  }
}
```

### 监听UIAbility生命周期变化

开发者可以通过[ApplicationContext](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md)监听UIAbility生命周期变化。当[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)生命周期变化时，如UIAbility创建、切换至前台、切换至后台、销毁等情况，UIAbility会收到相应回调函数的通知，从而执行依赖UIAbility生命周期的方法，也可以统计指定页面停留时间和访问频率等信息。

每次注册回调函数时，都会返回一个监听生命周期的ID，此ID会自增1。当超过监听上限数量2^63-1时，会返回-1。以[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)中的使用为例进行说明。

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