# OpenHarmony JS和TS三方组件使用指导
## OpenHarmony JS和TS三方组件介绍

OpenHarmony JS和TS三方组件使用的是OpenHarmony静态共享包，即HAR(Harmony Archive)，可以包含js/ts代码、c++库、资源和配置文件。通过HAR，可以实现多个模块或者多个工程共享ArkUI组件、资源等相关代码。HAR不同于HAP，不能独立安装运行在设备上，只能作为应用模块的依赖项被引用。



## 查找OpenHarmony JS和TS三方组件

1. 关注Gitee官网OpenHarmony-TPC[三方组件资源汇总](https://gitee.com/openharmony-tpc/tpc_resource)项目，根据目录索引即可找到对应分类下的具体组件。



2. 访问[OpenHarmony三方库中心仓](https://ohpm.openharmony.cn/)，搜索需要的三方组件。



## 安装并使用OpenHarmony JS和TS语言的三方组件

引用三方HAR，包括从仓库进行安装和从本地库模块中进行安装两种方式。   

**引用仓库安装的HAR**

引用ohpm仓中的HAR，首先需要设置三方HAR的仓库信息，DevEco Studio默认仓库地址是"https://repo.harmonyos.com/ohpm/"，如果您想设置自定义仓库，请在DevEco Studio的Terminal窗口执行如下命令进行设置（执行命令前，请确保将DevEco Studio中ohpm安装地址配置在“环境变量-系统变量-PATH”中）：
```
ohpm config set registry=your_registry1,your_registry2
```
说明：ohpm支持多个仓库地址，采用英文逗号分隔。
然后通过如下两种方式设置三方包依赖信息：
   -  方式一：在Terminal窗口中，执行如下命令安装三方包，DevEco Studio会自动在工程的oh-package.json5中自动添加三方包依赖。
```
ohpm install @ohos/lottie
```
   - 方式二：在工程的oh-package.json5中设置三方包依赖，配置示例如下：
```
"dependencies": { "@ohos/lottie": "^2.0.0"}
```
依赖设置完成后，需要执行ohpm install命令安装依赖包，依赖包会存储在工程的oh_modules目录下。
```
ohpm install
```

**引用本地库模块的文件和资源**

- 方式一：在Terminal窗口中，执行如下命令进行安装，并会在oh-package5.json中自动添加依赖。
```
ohpm install ../library
```
- 方式二：在工程的oh-package.json5中设置三方包依赖，配置示例如下：
```
"dependencies": {
   "library": "file:../library"
}
```
依赖设置完成后，需要执行ohpm install命令安装依赖包，依赖包会存储在工程的oh_modules目录下。
```
ohpm install
```

> **说明：**
>
> 在引用OpenHarmony HAR时，请注意以下事项
>- 当前只支持在模块和工程下的oh-package.json5文件中声明dependencies依赖，才会被当做OpenHarmony依赖使用，并在编译构建过程中进行相应的处理。
>- 引用的模块的compileSdkVersion不能低于其依赖的OpenHarmony ohpm三方包（可在oh_modules目录下，找到引用的ohpm包的src > main > module.json5 中查看）。



### 引用OpenHarmony HAR hml页面  
在JS工程范式中，组件功能由hml承载，开发者可以在JS工程的hml页面通过<element>标签来引入OpenHarmony HAR中的共享hml页面，示例如下：
```
<element name="comp" src="library/src/main/js/components/index/index.hml"></element>
```
其中，library为OpenHarmony HAR的包名，hml页面的路径为OpenHarmony HAR中的相对路径。  
随后便可以通过设置的name来使用该element元素，以引用OpenHarmony HAR中的hml页面，示例如下：
```typescript
<element name="comp" src="library/src/main/js/components/index/index.hml"></element>

<div class="container">
   <comp></comp>
   <text class="title">
      {{ $t('strings.hello') }} {{ title }}
   </text>
</div>
```
### 引用OpenHarmony HAR ArkTS页面   
ArkTS是TypeScript的扩展，因此导出和引入的语法与TypeScript一致。在OpenHarmony ohpm模块中，可以通过export导出ArkTS页面，示例如下：
```typescript
// library/src/main/ets/components/mainpage/MainPage.ets
@Entry
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
      } .height('100%') 
   }
}
```
然后在其它模块中通过import引入导出的ArkTS页面，示例如下所示：
```typescript
// entry/MainAbility/pages/index.ets

import { MainPage } from "library"
@Entry
@Component
struct Index {
   @State message: string = 'Hello World' 
   build() { 
      Column() { 
         MainPage() 
         Row() { 
            Text(this.message)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
         }
         .width('100%')
      } 
      .height('10%') 
   }
}
```
引用OpenHarmony HAR内ts/js方法ts/js方法的导出和引用，与ArkTS页面的引用相同，即在OpenHarmony ohpm模块中，可以通过export导出ts/js方法，示例如下所示：
```typescript
// library/index.js
export function func() {
   return "[ohpm] func1";
}
```
然后在其它的ts/js页面中，通过import引入导出的ts/js方法，示例如下所示：
```typescript
// entry/src/main/js/MainAbility/pages/index/index.js
import {func} from "library"
export default {
   data: {
      title: ""
   },
   onInit() {
      this.title = func();
   }
}
```
引用OpenHarmony HAR内资源支持在OpenHarmony ohpm模块和依赖OpenHarmony ohpm的模块中引用OpenHarmony ohpm模块内的资源。例如在OpenHarmony ohpm模块的scr/main/resources里添加字符串资源（在string.json中定义，name：hello_ohpm）和图片资源（icon_ohpm.png）。然后在Entry模块中引用该字符串资源和图片资源的示例如下：
当前暂不支持类Web范式引用i18n文件中的国际化资源。
```typescript
// entry/src/main/ets/MainAbility/pages/index.ets
@Entry
@Component
struct Index {
   @State message: string = 'Hello World'
   build() {
      Column() {
         Row() {
            Text($r("app.string.hello_ohpm")) // 字符串资源
              .fontSize(40)
              .fontWeight(FontWeight.Bold)
         }
         .width('50%')
         Image($r("app.media.icon_ohpm")) // 图片资源
      }
      .height('100%')
   }
}
```
在编译构建HAP中，DevEco Studio会从HAP模块及依赖的模块中收集资源文件，如果不同模块的相同限定词目录下的资源文件出现重名冲突时，DevEco Studio会按照以下优先级进行覆盖（优先级由高到低）：
- AppScope（仅API 9的Stage模型支持）
- HAP包自身模块
- 依赖的OpenHarmonyHarmony ohpm模块