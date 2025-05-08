# Environment：设备环境查询


开发者如果需要应用程序运行的设备的环境参数，以此来作出不同的场景判断，比如多语言，深浅色模式等，需要用到Environment设备环境查询。


Environment是ArkUI框架在应用程序启动时创建的单例对象。它为AppStorage提供了一系列描述应用程序运行状态的属性。Environment的所有属性都是不可变的（即应用不可写入），所有的属性都是简单类型。


Environment提供了读取系统某些环境变量的能力，具体见[Environment内置参数](#environment内置参数)，并将其值写入AppStorage里，所以开发者需要通过AppStorage才能获取环境变量的值。

在阅读本文档前，建议提前阅读：[AppStorage](./arkts-appstorage.md)。

## Environment内置参数

| 键 | 数据类型 | 描述                                      |
| ------------------ | ------------------ | ------------------ |
| accessibilityEnabled              | boolean                  | 获取无障碍屏幕读取是否启用。                 |
| colorMode              | ColorMode                  | 色彩模型类型：选项为ColorMode.LIGHT: 浅色，ColorMode.DARK: 深色。                 |
| fontScale              | number                  | 字体大小比例。开发者需要配置[configuration](../../quick-start/app-configuration-file.md#configuration标签)使fontScale跟随系统变化。                |
| fontWeightScale              | number                  | 字体粗细程度。                |
| layoutDirection              | LayoutDirection                  | 布局方向类型：包括LayoutDirection.LTR: 从左到右，LayoutDirection.RTL: 从右到左。                 |
| languageCode              | string                  | 当前系统语言值，取值必须为小写字母，例如zh。                 |


## 使用场景


### 从UI中访问Environment参数

- 使用Environment.envProp将设备运行的环境变量存入AppStorage中。

  ```ts
  // 将设备的语言code存入AppStorage，默认值为en
  Environment.envProp('languageCode', 'en');
  ```

- 可以使用\@StorageProp链接到Component中。

  ```ts
  @StorageProp('languageCode') lang: string = 'en';
  ```

设备环境到Component的更新链：Environment --&gt; AppStorage --&gt; Component。

> **说明：**
>
> \@StorageProp关联的环境参数可以在本地更改，但不能同步回AppStorage中，因为应用对环境变量参数是不可写的，只能在Environment中查询。


```ts
// 将设备languageCode存入AppStorage中
Environment.envProp('languageCode', 'en');

@Entry
@Component
struct Index {
  @StorageProp('languageCode') languageCode: string = 'en';

  build() {
    Row() {
      Column() {
        // 输出当前设备的languageCode
        Text(this.languageCode)
      }
    }
  }
}
```


### 应用逻辑使用Environment


```ts
// 使用Environment.envProp将设备运行languageCode存入AppStorage中；
Environment.envProp('languageCode', 'en');
// 从AppStorage获取单向绑定的languageCode的变量
const lang: SubscribedAbstractProperty<string> = AppStorage.prop('languageCode');

if (lang.get() === 'zh') {
  console.info('你好');
} else {
  console.info('Hello!');
}
```


## 限制条件


Environment和UIContext相关联，需要在[UIContext](../../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext)明确的时候才可以调用。可以通过在[runScopedTask](../../reference/apis-arkui/js-apis-arkui-UIContext.md#runscopedtask)里明确上下文。如果没有在UIContext明确的地方调用，将导致无法查询到设备环境数据。


```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index');
    let window = windowStage.getMainWindow()
    window.then(window => {
      let uicontext = window.getUIContext()
      uicontext.runScopedTask(() => {
        Environment.envProp('languageCode', 'en');
      })
    })
  }
}
```