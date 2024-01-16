# HAR
HAR（Harmony Archive）是静态共享包，可以包含代码、C++库、资源和配置文件。通过HAR可以实现多个模块或多个工程共享ArkUI组件、资源等相关代码。

## 使用场景
- 作为二方库，发布到[OHPM](https://ohpm.openharmony.cn/)私仓，供公司内部其他应用使用。
- 作为三方库，发布到[OHPM](https://ohpm.openharmony.cn/)中心仓，供其他应用使用。

## 约束限制

- HAR不支持在设备上单独安装/运行，只能作为应用模块的依赖项被引用。
- HAR不支持在配置文件中声明[UIAbility](./module-configuration-file.md#abilities标签)组件与[ExtensionAbility](./module-configuration-file.md#extensionabilities标签)组件。
- HAR不支持在配置文件中声明[pages](./module-configuration-file.md#pages标签)页面，但是可以包含pages页面，并通过[命名路由](../ui/arkts-routing.md#命名路由)的方式进行跳转。
- HAR不支持引用AppScope目录中的资源。在编译构建时，AppScope中的内容不会打包到HAR中，导致HAR资源引用失败。
- HAR可以依赖其他HAR，但不支持循环依赖，也不支持依赖传递。

## 创建
通过DevEco Studio创建一个HAR模块，详见[创建库模块](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/creating_har_api9-0000001518082393-V3#section143510369612)。


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
在HAR中也可以包含C++编写的so。对于so中的native方法，HAR通过以下方式导出，以导出libnative.so的加法接口add为例：
```ts
// library/src/main/ets/utils/nativeTest.ts
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

### 资源
HAR模块编译打包时会把资源打包到HAR中。在编译构建HAP时，DevEco Studio会从HAP模块及依赖的模块中收集资源文件，如果不同模块下的资源文件出现重名冲突时，DevEco Studio会按照以下优先级进行覆盖（优先级由高到低）：
- AppScope（仅API9的Stage模型支持）。
- HAP包自身模块。
- 依赖的HAR模块，如果依赖的多个HAR之间有资源冲突，会按照依赖顺序进行覆盖（依赖顺序在前的优先级较高）。


## 使用

介绍如何配置HAR依赖，并引用HAR的ArkUI组件、接口、资源。

引用HAR前，需要先配置对HAR的依赖，详见[引用HAR文件和资源](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/creating_har_api9-0000001518082393-V3#section611662614153)。

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
> 仅Stage模型的ArkTS工程支持混淆。  
> HAR开启混淆后资源ID为-1，[ResourceManager](../reference/apis/js-apis-resource-manager.md)等通过ID获取资源的API不再生效。


对于API 10及以上版本，HAR模块默认开启混淆能力，可以在HAR模块的build-profile.json5文件中的ruleOptions字段下的enable进行设置，配置如下所示：

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

## 发布

详见[发布HAR](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/creating_har_api9-0000001518082393-V3#section1213451811512)。

## 相关实例

- [购物示例应用](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Solutions/Shopping/OrangeShopping)