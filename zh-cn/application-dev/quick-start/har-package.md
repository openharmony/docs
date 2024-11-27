# HAR
HAR（Harmony Archive）是静态共享包，可以包含代码、C++库、资源和配置文件。通过HAR可以实现多个模块或多个工程共享ArkUI组件、资源等相关代码。

## 使用场景
- 支持应用内共享，也可以发布后供其他应用使用。
- 作为二方库，发布到[OHPM私仓](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-ohpm-repo-V13)，供公司内部其他应用使用。
- 作为三方库，发布到[OHPM中心仓](https://ohpm.openharmony.cn/)，供其他应用使用。
- 多包（HAP/HSP）引用相同的HAR时，会造成多包间代码和资源的重复拷贝，从而导致应用包膨大。

## 约束限制

- HAR不支持在设备上单独安装/运行，只能作为应用模块的依赖项被引用。
- HAR不支持在配置文件中声明[UIAbility](../application-models/uiability-overview.md)组件与[ExtensionAbility](../application-models/extensionability-overview.md)组件。
- HAR不支持在配置文件中声明[pages](./module-configuration-file.md#pages标签)页面，但是可以包含pages页面，并通过[命名路由](../ui/arkts-routing.md#命名路由)的方式进行跳转。
- HAR不支持引用AppScope目录中的资源。在编译构建时，AppScope中的内容不会打包到HAR中，因此会导致HAR资源引用失败。
- HAR可以依赖其他HAR，但不支持循环依赖，也不支持依赖传递。

## 创建
通过DevEco Studio创建一个HAR模块，详见[创建库模块](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-har-V13#section643521083015)。


## 开发

介绍如何导出HAR的ArkUI组件、接口、资源，供其他应用或当前应用的其他模块引用。

Index.ets文件是HAR导出声明文件的入口，HAR需要导出的接口，统一在Index.ets文件中导出。Index.ets文件是DevEco Studio默认自动生成的，用户也可以自定义，在模块的oh-package.json5文件中的main字段配置入口声明文件，配置如下所示：
```json
{
  "main": "Index.ets"
}
```
### 导出ArkUI组件
ArkUI组件的导出方式与ts的导出方式一致，通过`export`导出ArkUI组件，示例如下：
```ts
// library/src/main/ets/components/mainpage/MainPage.ets
@Component
export struct MainPage {
  @State message: string = 'HAR MainPage';

  build() {
    Column() {
      Row() {
        Text(this.message)
          .fontSize(32)
          .fontWeight(FontWeight.Bold)
      }
      .margin({ top: '32px' })
      .height(56)
      .width('624px')

      Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center, alignContent: FlexAlign.Center }) {
        Column() {
          Image($r('app.media.pic_empty')).width('33%')
          Text($r('app.string.empty'))
            .fontSize(14)
            .fontColor($r('app.color.text_color'))
        }
      }.width('100%')
      .height('90%')
    }
    .width('100%')
    .height('100%')
    .backgroundColor($r('app.color.page_background'))
  }
}
```
HAR对外暴露的接口，在Index.ets导出文件中声明如下所示：
```ts
// library/Index.ets
export { MainPage } from './src/main/ets/components/mainpage/MainPage';
```
### 导出ts类和方法
通过`export`导出ts类和方法，支持导出多个ts类和方法，示例如下所示：
```ts
// library/src/main/ts/test.ets
export class Log {
    static info(msg: string) {
        console.info(msg);
    }
}

export function func() {
  return 'har func';
}

export function func2() {
  return 'har func2';
}
```
HAR对外暴露的接口，在Index.ets导出文件中声明如下所示：
```ts
// library/Index.ets
export { Log } from './src/main/ts/test';
export { func } from './src/main/ts/test';
export { func2 } from './src/main/ts/test';
```

### 导出native方法
在HAR中也可以包含C++编写的so。对于so中的native方法，HAR通过以下方式导出，以导出liblibrary.so的加法接口add为例：
```ts
// library/src/main/ets/utils/nativeTest.ets
import native from 'liblibrary.so';

export function nativeAdd(a: number, b: number): number {
  let result: number = native.add(a, b);
  return result;
}
```
HAR对外暴露的接口，在Index.ets导出文件中声明如下所示：
```ts
// library/Index.ets
export { nativeAdd } from './src/main/ets/utils/nativeTest';
```

### 导出资源
在编译构建HAP时，DevEco Studio会从HAP模块及依赖的模块中收集资源文件，如果不同模块下的资源文件出现重名冲突时，DevEco Studio会按照以下优先级进行覆盖（优先级由高到低）：
- AppScope（仅API9的Stage模型支持）。
- HAP包自身模块。
- 依赖的HAR模块，如果依赖的多个HAR之间有资源冲突，会按照工程oh-package.json5中dependencies下的依赖顺序进行覆盖，依赖顺序在前的优先级较高。例如下方示例中dayjs和lottie中包含同名文件时，会优先使用dayjs中的资源。
> **说明：**
> 
> 如果在AppScope/HAP模块/HAR模块的国际化目录中配置了资源，在相同的国际化限定词下，合并的优先级也遵循上述规则。同时，国际化限定词中配置的优先级高于在base中的配置。如：在AppScope的base中配置了资源字段，在HAR模块的en_US中配置了同样的资源字段，则在en_US的使用场景中，会更优先使用HAR模块中配置的资源字段。
```
// oh-package.json5
{
  "dependencies": {
    "dayjs": "^1.10.4",
    "lottie": "^2.0.0"
  }
}
```

## 使用

介绍如何配置HAR依赖，并引用HAR的ArkUI组件、接口、资源。

引用HAR前，需要先配置对HAR的依赖，详见[引用HAR文件和资源](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-har-import-V13)。

### 引用HAR的ArkUI组件

HAR的依赖配置成功后，可以引用HAR的ArkUI组件。ArkUI组件的导入方式与ts的导入方式一致，通过`import`引入HAR导出的ArkUI组件，示例如下所示：
```ts
// entry/src/main/ets/pages/IndexSec.ets
import { MainPage } from 'library';

@Entry
@Component
struct IndexSec {
  build() {
    Row() {
      // 引用HAR的ArkUI组件
      MainPage()
    }
    .height('100%')
  }
}
```
### 引用HAR的ts类和方法
通过`import`引用HAR导出的ts类和方法，示例如下所示：
```ts
// entry/src/main/ets/pages/Index.ets
import { Log } from 'library';
import { func } from 'library';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Column() {
      Text(this.message)
        .fontFamily('HarmonyHeiTi')
        .fontWeight(FontWeight.Bold)
        .fontSize(32)
        .fontWeight(700)
        .fontColor($r('app.color.text_color'))
        .textAlign(TextAlign.Start)
        .margin({ top: '32px' })
        .width('624px')

      //引用HAR的ts类和方法
      Button($r('app.string.button'))
        .id('button')
        .height(48)
        .width('624px')
        .margin({ top: '4%' })
        .type(ButtonType.Capsule)
        .fontFamily('HarmonyHeiTi')
        .borderRadius($r('sys.float.ohos_id_corner_radius_button'))
        .backgroundColor($r('app.color.button_background'))
        .fontColor($r('sys.color.ohos_id_color_foreground_contrary'))
        .fontSize($r('sys.float.ohos_id_text_size_button1'))
        .onClick(() => {
          // 引用HAR的类和方法
          Log.info('har msg');
          this.message = 'func return: ' + func();
        })
    }
    .width('100%')
    .backgroundColor($r('app.color.page_background'))
    .height('100%')
  }
}
```

### 引用HAR的native方法
通过`import`引用HAR导出的native方法，示例如下所示：
```ts
// entry/src/main/ets/pages/Index.ets
import { nativeAdd } from 'library';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Column() {
      Text(this.message)
        .fontFamily('HarmonyHeiTi')
        .fontWeight(FontWeight.Bold)
        .fontSize(32)
        .fontWeight(700)
        .fontColor($r('app.color.text_color'))
        .textAlign(TextAlign.Start)
        .margin({ top: '32px' })
        .width('624px')

      //引用HAR的native方法
      Button($r('app.string.native_add'))
        .id('nativeAdd')
        .height(48)
        .width('624px')
        .margin({ top: '4%', bottom: '6%' })
        .type(ButtonType.Capsule)
        .fontFamily('HarmonyHeiTi')
        .borderRadius($r('sys.float.ohos_id_corner_radius_button'))
        .backgroundColor($r('app.color.button_background'))
        .fontColor($r('sys.color.ohos_id_color_foreground_contrary'))
        .fontSize($r('sys.float.ohos_id_text_size_button1'))
        .onClick(() => {
          this.message = 'result: ' + nativeAdd(1, 2);
        })
    }
    .width('100%')
    .backgroundColor($r('app.color.page_background'))
    .height('100%')
  }
}
```

### 引用HAR的资源
通过`$r`引用HAR中的资源，例如在HAR模块的`src/main/resources`里添加字符串资源（在string.json中定义，name：hello_har）和图片资源（icon_har.png），然后在Entry模块中引用该字符串和图片资源的示例如下所示：
```ts
// entry/src/main/ets/pages/Index.ets
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    Column() {
      // 引用HAR的字符串资源
      Text($r('app.string.hello_har'))
        .id('stringHar')
        .fontFamily('HarmonyHeiTi')
        .fontColor($r('app.color.text_color'))
        .fontSize(24)
        .fontWeight(500)
        .margin({ top: '40%' })

      List() {
        ListItem() {
          // 引用HAR的图片资源
          Image($r('app.media.icon_har'))
            .id('iconHar')
            .borderRadius('48px')
        }
        .margin({ top: '5%' })
        .width('312px')
      }
      .alignListItem(ListItemAlign.Center)
    }
    .width('100%')
    .backgroundColor($r('app.color.page_background'))
    .height('100%')
  }
}
```
## 编译

HAR可以作为二方库和三方库提供给其他应用使用，如果需要对代码资产进行保护时，建议开启混淆能力。

混淆能力开启后，DevEco Studio在构建HAR时，会对代码进行编译、混淆及压缩处理，保护代码资产。

> **说明：**
> 
> 编译HAR时，如果没有开启混淆能力，编译后的产物是源码文件。<br/>
> 仅Stage模型的ArkTS工程支持混淆。  
> HAR开启混淆后资源ID为-1，[ResourceManager](../reference/apis-localization-kit/js-apis-resource-manager.md)等通过ID获取资源的API不再生效。

HAR模块原先默认开启混淆能力，会对API 10及以上的HAR模块，且编译模块为release时，自动进行简单的代码混淆；**从DevEco Studio 5.0.3.600开始，新建工程默认关闭代码混淆功能**，可以在HAR模块的build-profile.json5文件中的ruleOptions字段下的enable进行开启混淆，详情请见[代码混淆](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-build-obfuscation-V13)，配置如下所示：

  ```json
  {
    "apiType": "stageMode",
    "buildOption": {
    },
    "buildOptionSet": [
      {
        "name": "release",
        "arkOptions": {
          "obfuscation": {
            "ruleOptions": {
              "enable": true,
              "files": [
                "./obfuscation-rules.txt"
              ]
            },
            "consumerFiles": [
              "./consumer-rules.txt"
            ]
          }
        }
      },
    ],
    "targets": [
      {
        "name": "default"
      }
    ]
  }
  ```

### 编译生成TS文件

> **场景说明**
>
>在HAR中使用Sendable时，开启该配置。

> **使用限制**
>
>在依赖TS HAR时，禁止引用TS HAR中的ArkUI组件。

HAR模块中arkts文件编译后，默认产物为js文件，想要将产物修改为ts文件，可以在HAR模块下的module.json5文件中将"metadata"字段下的"name"设置为“UseTsHar”，配置如下所示：

  ```json
  {
    "module": {
      "name": "TsClosedHar",
      "type": "har",
      "deviceTypes": [
        "default",
        "tablet",
        "2in1"
      ],
      "metadata": [
        {
          "name": "UseTsHar",
          "value": "true"
        }
      ]
    }
  }
  ```

## 发布

详见[发布HAR](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V13/ide-har-publish-V13)。

## 相关实例

- [购物示例应用](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.1-Release/code/Solutions/Shopping/OrangeShopping)