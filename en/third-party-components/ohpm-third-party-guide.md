# Using Third-Party JavaScript and TypeScript Components
## Overview

OpenHarmony uses a third-party JavaScript or TypeScript component in the form of a Harmony Archive (HAR), which is a static shared package that can contain JavaScript or TypeScript code, C++ libraries, resources, and configuration files. The HAR enables modules and projects to share code related to ArkUI components, resources, and more. Unlike a Harmony Ability Package (HAP), a HAR cannot be independently installed on a device. Instead, it can be referenced only as the dependency of an application module.

## Searching for a Third-Party JavaScript or TypeScript Component

1. Access the [OpenHarmony-TPC/tpc_resource](https://gitee.com/openharmony-tpc/tpc_resource) repository, and find the desired component based on the directory index.

2. Access the [OpenHarmony Third-Party Libraries](https://ohpm.openharmony.cn/#/en/home) website, and search for the required third-party component.

## Installing and Using a Third-Party JavaScript or TypeScript Component

You can reference a third-party HAR from the ohpm repository or the local repository module.  

**Referencing an HAR Installed in the ohpm Repository**

To reference an HAR in the ohpm repository, set the repository information of the third-party HAR. The default repository address on DevEco Studio is "https://repo.harmonyos.com/ohpm/". To use a custom repository address, ensure that the ohpm installation address on DevEco Studio is configured in **Environment Variables > System Variables > PATH**, and then run the following command in the **Terminal** window of DevEco Studio:
```
ohpm config set registry=your_registry1,your_registry2
```
Note: You can configure multiple repository addresses, separated by commas (,).
Then use either of the following methods to set the third-party HAR as a dependency:
   - Method 1: In the **Terminal** window, run the following command to install the third-party HAR. DevEco Studio will automatically add the HAR as a dependency to the **oh-package.json5** file of the project.

     ```
     ohpm install @ohos/lottie
     ```

   - Method 2: Set the third-party HAR as a dependency in the **oh-package.json5** file of the project. The following is a configuration example:

     ```
     "dependencies": { "@ohos/lottie": "^2.0.0"}
     ```

After the dependency is set, run the **ohpm install** command to install the HAR, which will be stored in the **oh_modules** directory of the project.
```
ohpm install
```

**Referencing Files and Resources of the Local Repository Module**

- Method 1: In the **Terminal** window, run the following command to install the third-party HAR. DevEco Studio will automatically add the HAR as a dependency to the **oh-package5.json** file of the project.

  ```
  ohpm install ../library
  ```

- Method 2: Set the third-party HAR as a dependency in the **oh-package.json5** file of the project. The following is a configuration example:

  ```
  "dependencies": {
     "library": "file:../library"
  }
  ```

After the dependency is set, run the **ohpm install** command to install the HAR, which will be stored in the **oh_modules** directory of the project.
```
ohpm install
```

> **NOTE**
>
> Pay attention to the following points when referencing an HAR:
>- Only the dependencies declared in **dependencies** of the **oh-package.json5** file in the module and project are used as OpenHarmony dependencies and processed during compilation and building.
>- The **compileSdkVersion** of the referenced module cannot be earlier than that of the OpenHarmony ohpm third-party package on which the referenced module depends. You can view the version in the **src** > **main** > **module.json5** file of the referenced ohpm package in the **oh_modules** directory.

### Referencing an HAR HML Page 
In a JavaScript project paradigm, component functions are configured in HML files. To reference an HML page in an HAR, first import the page through the **<element>** tag in the HML file of the project. The sample code is as follows:
```
<element name="comp" src="library/src/main/js/components/index/index.hml"></element>
```
In the preceding example, **library** indicates the name of the HAR, and the path of the HML page is the relative path in the HAR. 
You can then reference the HML page based on the set element name. The sample code is as follows:
```typescript
<element name="comp" src="library/src/main/js/components/index/index.hml"></element>

<div class="container">
   <comp></comp>
   <text class="title">
      {{ $t('strings.hello') }} {{ title }}
   </text>
</div>
```
### Referencing an HAR ArkTS Page  
ArkTS is an extension of TypeScript. Therefore, the export and import syntax of ArkTS is the same as that of TypeScript. In the OpenHarmony ohpm module, use **export** to export an ArkTS page. The sample code is as follows:
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
Import the exported ArkTS page in other modules. The following is an example:
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
The procedure for referencing JavaScript/TypeScript methods in the HAR is the same as that for referencing ArkTS pages. In the OpenHarmony ohpm module, export the methods through **export**. The sample code is as follows:
```typescript
// library/index.js
export function func() {
   return "[ohpm] func1";
}
```
On other JavaScript/TypeScript pages, use **import** to import the exported methods. The sample code is as follows:
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
Resources in an OpenHarmony ohpm module can be referenced in another OpenHarmony ohpm module and modules that depend on the OpenHarmony ohpm module. For example, you can add string resources (defined in **string.json**, **name: hello_ohpm** in this example) and image resources (**icon_ohpm.png** in this example) to **scr/main/resources** of the OpenHarmony ohpm module, and then reference the string and image resources in the entry module, as shown below:
Currently, referencing resources in **i18n** files is not supported for the JavaScript-based web-like development paradigm.
```typescript
// entry/src/main/ets/MainAbility/pages/index.ets
@Entry
@Component
struct Index {
   @State message: string = 'Hello World'
   build() {
      Column() {
         Row() {
            Text($r("app.string.hello_ohpm")) // String resource.
              .fontSize(40)
              .fontWeight(FontWeight.Bold)
         }
         .width('50%')
         Image($r("app.media.icon_ohpm")) // Image resource.
      }
      .height('100%')
   }
}
```
During compilation and building of a HAP, DevEco Studio collects resource files from the HAP module and its dependent modules. If the resource files of different modules in the same qualifiers directory have the same name, DevEco Studio overwrites the resource files based on the following priorities (in descending order):
- AppScope (supported only by the stage model of API version 9)
- Modules in the HAP file
- Dependent OpenHarmony ohpm modules
