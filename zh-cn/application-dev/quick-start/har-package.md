# HAR
HAR（Harmony Archive）是静态共享包，可以包含代码、C++库、资源和配置文件。通过HAR可以实现多个模块或多个工程共享ArkUI组件、资源等相关代码。HAR不同于HAP，不能独立安装运行在设备上，只能作为应用模块的依赖项被引用。

## 创建HAR模块
通过DevEco Studio创建一个HAR模块，创建方式可[参考](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/creating_har_api9-0000001518082393-V3#section143510369612)。HAR模块默认不开启混淆能力，开启混淆能力，需要把HAR模块的build-profile.json5文件中的artifactType字段设置为obfuscation，配置如下所示：

```json
{
  "apiType": "stageMode",
  "buildOption": {
      "artifactType": "obfuscation"
  }
}
```
artifactType字段有以下两种取值，默认缺省为original。
- original：不混淆。
- obfuscation：混淆，目前仅支持uglify混淆。

需要对代码资产进行保护时，建议开启混淆能力，混淆能力开启后，DevEco Studio在构建HAR时，会对代码进行编译、混淆及压缩处理，保护代码资产。
注意：artifactType字段设置为obfuscation时，apiType字段必须设置为stageMode，因为Stage模型才支持混淆。

## HAR开发注意事项
- HAR不支持在配置文件中声明abilities、extensionAbilities组件。
- HAR不支持在配置文件中声明pages页面。
- HAR不支持在build-profile.json5文件的buildOption中配置worker。
- FA模型与Stage模型的HAR不支持相互引用。
- Stage模型的HAR，不能引用AppScope内的内容。在编译构建时APPScope中的内容不会打包到HAR中，导致HAR资源引用失败。

## 导出HAR的ArkUI组件、接口、资源
index.ets文件是HAR导出声明文件的入口，HAR需要导出的接口，统一在index.ets文件中导出。index.ets文件是DevEco Studio默认自动生成的，用户也可以自定义，在模块的oh-package.json5文件中的main字段配置入口声明文件，配置如下所示：
```json
{
  "main": "index.ets"
}
```
### 导出ArkUI组件
ArkUI组件的导出方式与ts的导出方式一致，通过`export`导出ArkUI组件，示例如下：
```js
// library/src/main/ets/components/MainPage/MainPage.ets
@Component
export struct MainPage {
  @State message: string = 'Hello World'
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
HAR对外暴露的接口，在index.ets导出文件中声明如下所示：
```js
// library/index.ets
export { MainPage } from './src/main/ets/components/MainPage/MainPage'
```
### 导出ts类和方法
通过`export`导出ts类和方法，支持导出多个ts类和方法，示例如下所示：
```js
// library/src/main/ts/test.ets
export class Log {
    static info(msg) {
        console.info(msg);
    }
}

export function func() {
  return "har func";
}

export function func2() {
  return "har func2";
}
```
HAR对外暴露的接口，在index.ets导出文件中声明如下所示：
```js
// library/index.ets
export { Log } from './src/main/ts/test'
export { func } from './src/main/ts/test'
export { func2 } from './src/main/ts/test'
```
### 资源
HAR模块编译打包时会把资源打包到HAR中。在编译构建HAP时，DevEco Studio会从HAP模块及依赖的模块中收集资源文件，如果不同模块下的资源文件出现重名冲突时，DevEco Studio会按照以下优先级进行覆盖（优先级由高到低）：
- AppScope（仅API9的Stage模型支持）。
- HAP包自身模块。
- 依赖的HAR模块，如果依赖的多个HAR之间有资源冲突，会按照依赖顺序进行覆盖（依赖顺序在前的优先级较高）。

## 引用HAR的ArkUI组件、接口、资源
引用HAR前，需要先配置对HAR的依赖，配置方式可[参考](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/creating_har_api9-0000001518082393-V3#section611662614153)。

### 引用HAR的ArkUI组件

HAR的依赖配置成功后，可以引用HAR的ArkUI组件。ArkUI组件的导入方式与ts的导入方式一致，通过`import`引入HAR导出的ArkUI组件，示例如下所示：
```js
// entry/src/main/ets/pages/index.ets
import { MainPage } from "library"

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  build() {
    Row() {
      // 引用HAR的ArkUI组件
      MainPage()
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
### 引用HAR的类和方法
通过`import`引用HAR导出的ts类和方法，示例如下所示：
```js
// entry/src/main/ets/pages/index.ets
import { Log } from "library"
import { func } from "library"

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button('Button')
          .onClick(()=>{
            // 引用HAR的类和方法
            Log.info("har msg");
            func();
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
### 引用HAR的资源
通过`$r`引用HAR中的资源，例如在HAR模块的`src/main/resources`里添加字符串资源（在string.json中定义，name：hello_har）和图片资源（icon_har.png），然后在Entry模块中引用该字符串和图片资源的示例如下所示：
```js
// entry/src/main/ets/pages/index.ets
@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        // 引用HAR的字符串资源
        Text($r("app.string.hello_har"))
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        // 引用HAR的图片资源
        Image($r("app.media.icon_har"))
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 发布HAR

发布HAR可[参考](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/creating_har_api9-0000001518082393-V3#section1213451811512)。
