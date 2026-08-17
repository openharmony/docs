# Environment：设备环境查询
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

如果开发者需要获取应用程序运行设备的环境参数（如多语言、深浅色模式等）以进行不同的场景判断，可以使用Environment设备环境查询。

Environment是ArkUI框架在应用程序启动时创建的单例对象，为[AppStorage](./arkts-appstorage.md)提供应用程序运行状态的属性。所有属性都是不可变的简单类型。

Environment提供了读取系统环境变量并将其值写入AppStorage的功能。开发者需要通过AppStorage获取环境变量的值。详细信息请参阅 [Environment 内置参数](#environment内置参数)。

在阅读本文档前，建议提前阅读：[AppStorage](./arkts-appstorage.md)。

## Environment内置参数

| 键 | 数据类型 | 描述                                      |
| ------------------ | ------------------ | ------------------ |
| accessibilityEnabled              | string                  | 是否启用无障碍屏幕阅读。'true'表示启用，'false'表示不启用。|
| colorMode              | [ColorMode](../../reference/apis-arkui/arkui-ts/ts-state-management-environment-variables.md#colormode)                  | 色彩模式类型。<br>- ColorMode.LIGHT：浅色。<br>- ColorMode.DARK：深色。                 |
| fontScale              | number                  | 字体大小比例。开发者需要配置configuration，设置fontSizeScale为"followSystem"，具体配置步骤可参考[configuration](../../quick-start/app-configuration-file.md#configuration标签)使fontScale跟随系统变化。<br>默认值跟随系统默认参数。                |
| fontWeightScale              | number                  | 字体粗细缩放比例。在不同的系统或者机型中，fontWeightScale的取值范围可能会有所不同。<br>默认值跟随系统默认参数。                |
| layoutDirection              | [LayoutDirection](../../reference/apis-arkui/arkui-ts/ts-state-management-environment-variables.md#layoutdirection)                  | 布局方向类型：<br>- LayoutDirection.LTR：从左到右。<br>- LayoutDirection.RTL：从右到左。                 |
| languageCode              | string                  | 当前系统语言值，取值必须为小写字母（例如：zh）。<br>默认值跟随系统默认参数。                 |

## 限制条件

Environment和[UIContext](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md)相关联，需要在UIContext明确的时候才可以调用Environment的接口，可以通过在[runScopedTask](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#runscopedtask)里调用明确上下文。如果不是在UIContext明确的地方调用，将导致无法查询到设备环境数据。
  <!-- @[limiting_condition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvironmentProject/entry/src/main/ets/entryability/EntryAbilityDemo.ets) -->   
  
  ``` TypeScript
  import { UIAbility } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  
  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      windowStage.loadContent('pages/Index');
      let mainWindow = windowStage.getMainWindow();
      mainWindow.then(mainWindowInstance => {
        let uiContext = mainWindowInstance.getUIContext();
        // Environment在UIContext.runScopedTask里调用明确上下文
        uiContext.runScopedTask(() => {
          Environment.envProp('languageCode', 'en');
        });
      });
    }
  }
  ```

## 使用场景

### 从UI中访问Environment参数

- 使用Environment.[envProp](../../reference/apis-arkui/arkui-ts/ts-state-management.md#envprop10)将设备运行的环境变量存入AppStorage中。

  <!-- @[showfirst_details](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvironmentProject/entry/src/main/ets/pages/ShowDetails.ets) --> 
  
  ``` TypeScript
  // 将设备的languageCode存入AppStorage，默认值为en
  Environment.envProp('languageCode', 'en');
  ```

- 在自定义组件中通过[@StorageProp](./arkts-appstorage.md#storageprop)获取languageCode的值。

  <!-- @[showsecond_details](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvironmentProject/entry/src/main/ets/pages/ShowDetails.ets) --> 
  
  ``` TypeScript
  @StorageProp('languageCode') lang: string = 'en';
  ```

设备环境到Component的更新链：Environment --&gt; AppStorage --&gt; Component。

> **说明：**
>
> 应用无法修改环境变量参数，因此使用@StorageProp获取。这样即使在组件内修改，也不会同步回AppStorage中，影响其他组件处获取环境变量的结果。
  <!-- @[ui_Environment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvironmentProject/entry/src/main/ets/pages/UiEnvironment.ets) -->  
  
  ``` TypeScript
  // 将设备languageCode存入AppStorage中
  Environment.envProp('languageCode', 'en');
  
  @Entry
  @Component
  struct UiEnvironment {
    @StorageProp('languageCode') languageCode: string = 'en';
  
    build() {
      Row() {
        Column() {
          // 输出当前设备的languageCode
          Text(this.languageCode)
            .fontSize(20)
            .margin(10)
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

  ![environment-ui](figures/environment-ui.png)

### 应用逻辑使用Environment
  <!-- @[applied_logic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvironmentProject/entry/src/main/ets/pages/AppliedLogic.ets) --> 
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const DOMAIN = 0x0001;
  const TAG = 'environmentalProject';
  
  // 使用Environment.envProp将设备运行languageCode存入AppStorage中
  Environment.envProp('languageCode', 'en');
  // 从AppStorage获取单向绑定的languageCode的变量
  const lang: SubscribedAbstractProperty<string> = AppStorage.prop('languageCode');
  
  if (lang.get() === 'zh') {
    // 请将$r('app.string.AppliedLogic_Hello')替换为实际资源文件，在本示例中该资源文件的value值为"你好"
    hilog.info(DOMAIN, TAG, `${$r('app.string.AppliedLogic_Hello')}`);
  } else {
    hilog.info(DOMAIN, TAG, 'Hello!');
  }
  ```
