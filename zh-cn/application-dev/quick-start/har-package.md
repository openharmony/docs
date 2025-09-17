# HAR
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

HAR（Harmony Archive）是静态共享包，可以包含代码、C++库、资源和配置文件。通过HAR可以实现多个模块或多个工程共享ArkUI组件、资源等相关代码。

## 使用场景
- 支持应用内共享，也可以作为二方库（SDK）、三方库（SDK）发布后供其他应用使用。
- 作为二方库（SDK），发布到[OHPM私仓](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-ohpm-repo)，供公司内部其他应用使用。
- 作为三方库（SDK），发布到[OHPM中心仓](https://ohpm.openharmony.cn/#/cn/home)，供其他应用使用。

## 约束限制

- HAR不支持在设备上单独安装或运行，只能作为应用模块的依赖项被引用。
- HAR不支持在配置文件中声明[ExtensionAbility](../application-models/extensionability-overview.md)组件。从API version 14开始，支持在配置文件中声明[UIAbility](../application-models/uiability-overview.md)组件，配置UIAbility的方法参考[在模块中添加Ability](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-add-new-ability#section18658758104318)，拉起HAR中UIAbility的方式与[启动应用内的UIAbility](../application-models/uiability-intra-device-interaction.md)方法相同。
> **说明：**
>
> 如果使用[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability)接口拉起HAR中的UIAbility，接口参数中的moduleName取值需要为依赖该HAR的[HAP](hap-package.md)/[HSP](in-app-hsp.md)的moduleName。
- HAR不支持在配置文件中声明[pages](./module-configuration-file.md#pages标签)页面，但是可以包含pages页面，并通过[Navigation跳转](../ui/arkts-navigation-navigation.md#路由操作)的方式进行跳转。
- HAR不支持引用AppScope目录中的资源。在编译构建时，AppScope中的内容不会打包到HAR中，因此会导致HAR资源引用失败。
- 由于HSP仅支持应用内共享，如果HAR依赖了HSP，则该HAR文件仅支持应用内共享，不支持发布到二方仓或三方仓供其他应用使用，否则会导致编译失败。
- 多包（HAP/HSP）引用相同的HAR时，会造成多包间代码和资源的重复拷贝，从而导致应用包变大。
- HAR可以依赖其他HAR或者HSP，但不支持循环依赖，也不支持依赖传递。
- HAP引用HAR时，在编译构建过程中系统会自动合并两者的权限配置。因此开发者无需在HAP和HAR中重复申请相同权限。

> **说明：**
> 
> 循环依赖：例如有三个HAR，HAR-A、HAR-B和HAR-C，循环依赖指HAR-A依赖HAR-B，HAR-B依赖HAR-C，HAR-C又依赖HAR-A。
>
> 依赖传递：例如有三个HAR，HAR-A、HAR-B和HAR-C，依赖关系是HAR-A依赖HAR-B，HAR-B依赖HAR-C。不支持传递依赖指HAR-A可以使用HAR-B的方法和组件，但是HAR-A不能直接使用HAR-C的方法和组件。


## 创建
开发者可以通过DevEco Studio创建一个用于调用C++代码的HAR模块，创建过程中需要在Configure New Module界面中开启Enable native。详见[创建库模块](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-har#section643521083015)。


## 开发

介绍如何导出HAR的ArkUI组件、接口、资源，供其他应用或当前应用的其他模块引用。

Index.ets文件是HAR导出声明文件的入口，HAR需要导出的接口，统一在Index.ets文件中导出。Index.ets文件是DevEco Studio默认自动生成的，开发者也可以自定义，在模块的oh-package.json5文件中的main字段配置入口声明文件，配置如下所示：
```json
{
  "main": "Index.ets"
}
```
> **说明：**
>
> HAR在和宿主应用一起编译时，会把HAR的代码直接编译到宿主应用中，HAR包是一个编译中间态产物，不是最终的运行实体。运行时，HAR运行的身份信息是其宿主应用，系统会以宿主应用的版本做行为区分。如果需要在HAR中区分宿主应用的版本做不同的行为区分，可以调用[getBundleInfoForSelf](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口，获取宿主应用的targetVersion，然后根据不同的targetVersion，做不同的逻辑处理。

### 导出ArkUI组件
通过`export`导出ArkUI组件，示例如下：
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
### 导出类和方法
通过`export`导出类和方法，支持导出多个类和方法，示例如下所示：
```ts
// library/src/main/ets/test.ets
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
export { Log, func, func2 } from './src/main/ets/test';
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
- AppScope（仅Stage模型支持）。
- HAP包自身模块。
- 依赖的HAR模块，如果依赖的多个HAR之间有资源冲突，会按照工程oh-package.json5中dependencies下的依赖顺序进行覆盖，依赖顺序在前的优先级较高。例如下方示例中dayjs和lottie中包含同名文件时，会优先使用dayjs中的资源。
> **说明：**
> 
> 如果在AppScope、HAP模块或HAR模块的国际化目录中配置了资源，在相同的国际化限定词下，合并的优先级也遵循上述规则。同时，国际化限定词中配置的优先级高于在base中的配置。例如，在AppScope的base中配置了资源字段，在HAR模块的en_US中配置了同样的资源字段，则在en_US的使用场景中，会更优先使用HAR模块中配置的资源字段。
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

引用HAR前，需要先配置对HAR的依赖，详见[引用HAR文件和资源](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-har-import)。

### 引用HAR的ArkUI组件

HAR的依赖配置成功后，可以引用HAR的ArkUI组件。通过`import`引入HAR导出的ArkUI组件，示例如下所示：
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
### 引用HAR的类和方法
通过`import`引用HAR导出的类和方法，示例如下所示：
```ts
// entry/src/main/ets/pages/Index.ets
import { Log, func } from 'library';

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

      //引用HAR的ets类和方法
      Button($r('app.string.button'))
        .id('button')
        .height(48)
        .width('624px')
        .margin({ top: '4%' })
        .type(ButtonType.Capsule)
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

      //引用HAR的native方法
      Button($r('app.string.native_add'))
        .id('nativeAdd')
        .height(48)
        .width('624px')
        .margin({ top: '4%', bottom: '6%' })
        .type(ButtonType.Capsule)
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

HAR可以作为二方库和三方库提供给其他应用使用，如果需要对代码资产进行保护，建议[开启混淆](../arkts-utils/source-obfuscation-guide.md#开启源码混淆)。

[混淆能力](../arkts-utils/source-obfuscation.md)开启后，DevEco Studio在构建HAR时，会对代码进行编译、混淆及压缩处理，保护代码资产。

HAR模块原先默认开启混淆能力，会对API 10及以上的HAR模块，且编译模块为release时，自动进行简单的代码混淆；**从DevEco Studio 5.0.3.600开始，新建工程默认关闭代码混淆功能**，可以在HAR模块的build-profile.json5文件中的ruleOptions字段下的enable进行开启混淆，详情请见[代码混淆](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-build-obfuscation)，配置如下所示：

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
>在HAR中使用[Sendable](../arkts-utils/arkts-sendable.md)时，开启该配置。

> **使用限制**
>
> 在依赖TS HAR时，禁止引用TS HAR中的ArkUI组件。


HAR模块中arkts文件编译后，默认产物为js文件，想要将产物修改为ts文件，可以在HAR模块下的module.json5文件中将"metadata"字段下的"name"设置为“UseTsHar”，配置如下所示：
>
> **说明：**
>
> 从DevEco Studio NEXT Beta1（5.0.3.800）版本开始，默认构建字节码HAR，详情参考[构建HAR](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-har)。
>

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

详见[发布HAR](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-har-publish)。

## 相关实例

- [购物示例应用](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/Solutions/Shopping/OrangeShopping)