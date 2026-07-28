# ArkGuard混淆配置选项
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

从API version 10开始，ArkGuard提供混淆配置选项来控制混淆效果。开发者可在[obfuscation-rules.txt](./source-obfuscation-guide.md#混淆配置文件)文件中自定义这些选项。若开启混淆但未配置任何选项，则仅应用默认混淆效果，即混淆局部变量和参数名。

## 混淆选项汇总

| 功能 | 选项 | 起始API版本 |
| --- | --- | --- |
| 关闭混淆 | [`-disable-obfuscation`](#-disable-obfuscation) | 10 |
| 开启属性名称混淆 | [`-enable-property-obfuscation`](#-enable-property-obfuscation) | 10 |
| 开启字符串属性名称混淆 | [`-enable-string-property-obfuscation`](#-enable-string-property-obfuscation) | 10 |
| 开启顶层作用域名称混淆 | [`-enable-toplevel-obfuscation`](#-enable-toplevel-obfuscation) | 10 |
| 开启导入导出名称混淆 | [`-enable-export-obfuscation`](#-enable-export-obfuscation) | 10 |
| 开启文件名混淆 | [`-enable-filename-obfuscation`](#-enable-filename-obfuscation) | 10 |
| 代码压缩 | [`-compact`](#-compact) | 10 |
| 声明文件注释删除 | [`-remove-comments`](#-remove-comments) | 10 |
| 删除console.*语句 | [`-remove-log`](#-remove-log) | 10 |
| 名称缓存输出 | [`-print-namecache`](#-print-namecache) | 10 |
| 名称缓存复用 | [`-apply-namecache`](#-apply-namecache) | 10 |
| 输出未混淆名单 | [`-print-kept-names`](#-print-kept-names) | 18 |
| 缩减语言预置白名单 | [`-extra-options strip-language-default`](#-extra-options-strip-language-default) | 18 |
| 缩减系统预置白名单 | [`-extra-options strip-system-api-args`](#-extra-options-strip-system-api-args) | 18 |
| 不保留未参与编译模块名称 | [`-extra-options strip-not-compiled-module-name`](#-extra-options-strip-not-compiled-module-name) | 22 |
| 保留声明文件参数 | [`-keep-parameter-names`](#-keep-parameter-names) | 18 |
| 合并依赖模块选项 | [`-enable-lib-obfuscation-options`](#-enable-lib-obfuscation-options) | 18 |
| 通过注释在源码中标记白名单 | [`-use-keep-in-source`](#-use-keep-in-source) | 19 |
| 保留对象字面量属性名称 | [`-keep-object-props`](#-keep-object-props) | 23 |
| 删除指定的方法调用语句 | [`-remove-nosideeffects-calls`](#-remove-nosideeffects-calls) | 23 |

## -disable-obfuscation

关闭所有混淆。

配置该选项后，默认混淆（仅混淆局部变量及参数名）和其他已配置的混淆选项、保留选项将全部失效。

## -enable-property-obfuscation

> **说明**：
>
> 开启该选项后，在需要[手动配置白名单的场景中](./source-obfuscation-keep-options.md#-keep-property-name)，请将对应的属性名配置到白名单中。

配置该选项后，开启属性名称混淆，效果如下：

  <!-- @[optionExample_enablePropertyObfuscation1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
  
  ``` TypeScript
  // 混淆前：
  class TestA {
    static prop1: number = 0;
  }
  TestA.prop1;
  ```

  ``` TypeScript
  // 混淆后：
  class TestA {
    static i: number = 0;
  }
  TestA.i;
  ```

配置该选项后，所有属性名将被混淆，以下场景除外：

* 在未开启`-enable-export-obfuscation`选项的情况下，被`import/export`直接导入或导出的类或对象的属性名不会被混淆。例如，下面例子中的属性名`data1`不会被混淆。

  <!-- @[optionExample_enablePropertyObfuscation2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->  
  
  ``` TypeScript
  // ArkGuardAbility.ts
  export class MyClass01 {
    data1: string;
  }
  ```

* ArkUI组件中的属性名不会被混淆。例如，下面例子中的`message`和`data`不会被混淆。

  <!-- @[etsOptionExample_enablePropertyObfuscation1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ets) --> 
  
  ``` TypeScript
  // ArkGuardAbility.ets
  @Component struct MyExample {
    @State message: string = "hello";
    data: number[] = [];
    // ...
    build() {
    }
  }
  ```

* 被保留选项[-keep-property-name](./source-obfuscation-keep-options.md#-keep-property-name)指定的属性名不会被混淆。
* SDK API列表中的属性名不会被混淆。SDK API列表是构建时从SDK中自动提取出来的一个名称列表。其缓存文件为systemApiCache.json，路径为工程目录/build/default/cache/{...}/release/obfuscation。
* 字符串字面量属性名不会被混淆，并且与其同名的属性名也不会被混淆。例如，下面例子中的`exampleName`和`exampleAge`不会被混淆。

  <!-- @[optionExample_enableStringPropertyObfuscation1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->    
  
  ``` TypeScript
  // 混淆前：
  // ArkGuardAbility.ts
  let person = {"exampleName": "abc"};
  person["exampleAge"] = 22;
  ```
  
  <!-- @[optionExample_enablePropertyObfuscation3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
  
  ``` TypeScript
  let person1 = {exampleName: "aaa"};
  let name = person1.exampleName;
  ```
  
* 注解成员名不会被混淆。例如，下面例子中的`authorName`和`revision`不会被混淆。

  <!-- @[etsOptionExample_enablePropertyObfuscation2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ets) -->
  
  ``` TypeScript
  @interface MyAnnotation1 {
    authorName: string;
    revision: number = 1;
  }
  ```

## -enable-string-property-obfuscation

若要混淆字符串字面量属性名，需在已启用`-enable-property-obfuscation`的情况下使用。

  ```text
  -enable-property-obfuscation
  -enable-string-property-obfuscation
  ```

根据上述配置，`exampleName`和`exampleAge`的混淆效果如下：

  <!-- @[optionExample_enableStringPropertyObfuscation1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
  
  ``` TypeScript
  // 混淆前：
  // ArkGuardAbility.ts
  let person = {"exampleName": "abc"};
  person["exampleAge"] = 22;
  ```

  ``` TypeScript
  // 混淆后：
  // example.ts
  let person = {"a": "abc"};
  person["b"] = 22;
  ```

**使用该选项时，需要注意以下事项：**

1. 如果代码里面有字符串属性名包含特殊字符（除了`a-z、A-Z、0-9、_`之外的字符），例如`let obj = {"\n": 123, "": 4, " ": 5}`，建议不要开启`-enable-string-property-obfuscation`选项，因为可能无法通过[-keep-property-name](./source-obfuscation-keep-options.md#-keep-property-name)来保留这些名称。

2. SDK API的属性白名单中不包含声明文件中使用的字符串常量值，例如示例中的字符串'ohos.want.action.home'未包含在属性白名单中。

   <!-- @[optionExample_enableStringPropertyObfuscation2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) --> 
   
   ``` TypeScript
   // SDK API文件@ohos.app.ability.wantConstant片段：
   export enum Params {
     ACTION_HOME = 'ohos.want.action.home'
   }
   
   // 开发者源码示例：
   const obj1: Record<string, string> = {
     'ohos.want.action.home': 'value'
   }
   let params = obj1['ohos.want.action.home'];
   ```

   因此，在开启`-enable-string-property-obfuscation`选项后，如果希望保留代码中使用的SDK API字符串常量的属性不被混淆，例如obj['ohos.want.action.home']，可以使用[-keep-property-name](./source-obfuscation-keep-options.md#-keep-property-name)选项进行保留。

## -enable-toplevel-obfuscation

> **说明**：
>
> 开启该选项后，在需要[手动配置白名单的场景中](./source-obfuscation-keep-options.md#-keep-global-name)，请将对应的顶层作用域名称配置到白名单中。

开启顶层作用域名称混淆，效果如下：

  <!-- @[optionExample_enableToplevelObfuscation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
  
  ``` TypeScript
  // 混淆前：
  let count = 0;
  ```

  ``` TypeScript
  // 混淆后：
  let s = 0;
  ```

配置该选项后，所有顶层作用域的名称都会被混淆，以下场景除外：

* 在未开启`-enable-export-obfuscation`选项的情况下，被`import/export`直接导入或导出的名称不会被混淆。
* 当前文件找不到声明的名称不会被混淆。
* 被保留选项[-keep-global-name](./source-obfuscation-keep-options.md#-keep-global-name)指定的顶层作用域名称不会被混淆。
* SDK API列表中的顶层作用域名称不会被混淆。

## -enable-export-obfuscation

开启直接导入或导出的名称混淆，效果如下：

  <!-- @[optionExample_enableExportObfuscation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
  
  ``` TypeScript
  // 混淆前：
  namespace ns {
    export type customT = string;
  }
  ```

  ``` TypeScript
  // 混淆后：
  namespace ns {
    export type h = string;
  }
  ```

若仅配置该选项，那么只有非顶层作用域中导入或导出的名称会被混淆。**若想混淆顶层作用域中导入或导出的名称，需要在已配置`-enable-toplevel-obfuscation`的基础上使用；若想混淆导入或导出的属性名，需要在已配置`-enable-property-obfuscation`的基础上使用。** 开启此选项时，以下特殊场景不会被混淆：

* 远程HAR(真实路径在oh_modules中的包)中导出的名称和属性名不会被混淆。
* 被[ArkGuard混淆保留选项](./source-obfuscation-keep-options.md)指定的名称与属性名不会被混淆。
* SDK API列表中的名称不会被混淆。

## -enable-filename-obfuscation

> **说明**：
>
> 开启该选项后，在需要[手动配置白名单的场景中](./source-obfuscation-keep-options.md#-keep-file-name)，请将对应的文件夹/文件名称配置到白名单中。

开启文件/文件夹名称混淆，效果如下：

  <!-- @[testOptionExample_enableFilenameObfuscation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/FilenameObfuscationTest/FilenameObfuscationTest.ts) -->        
  
  ``` TypeScript
  // FilenameObfuscationTest/FilenameObfuscationTest.ts
  export function foo () {}
  ```

  <!-- @[optionExample_enableFilenameObfuscation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->    
  
  ``` TypeScript
  // ArkGuardAbility.ts
  // 混淆前：
  import * as m from '../FilenameObfuscationTest/FilenameObfuscationTest';
  import { foo } from '../FilenameObfuscationTest/FilenameObfuscationTest';
  // ...
  m.foo();
  foo();
  async function func1() {
    const modules = await import('../FilenameObfuscationTest/FilenameObfuscationTest');
    const result = modules.foo();
  }
  ```

  ``` TypeScript
  // example.ts
  // 混淆后：
  import * as m from "@normalized:N&&&entry/src/main/ets/c/d&";
  import { foo } from "@normalized:N&&&entry/src/main/ets/c/d&";
  m.foo();
  foo();
  async function func() {
      const f = await import("@normalized:N&&&entry/src/main/ets/c/d&");
      const g = f.foo();
  }
  ```

配置该选项后，所有文件和文件夹名称都将被混淆，以下场景除外：

* oh-package.json5文件中'main'、'types'字段配置的文件/文件夹名称不会被混淆。
* 模块内module.json5文件中'srcEntry'字段配置的文件/文件夹名称不会被混淆。
* 被[-keep-file-name](./source-obfuscation-keep-options.md#-keep-file-name)指定的文件/文件夹名称不会被混淆。
* 非ECMAScript模块引用方式（例如：`const module = require('./module')`）。
* 非路径引用方式，例如`import module from 'json5'`中的`json5`不会被混淆。

>**说明**：
>
>由于系统会在应用运行时加载某些指定的文件，针对这类文件，开发者需要手动在[-keep-file-name](./source-obfuscation-keep-options.md#-keep-file-name)选项中配置相应的白名单，防止指定文件被混淆，导致运行失败。
>
>编译入口、Ability组件、Worker多线程，这三种不能混淆的文件名在DevEco Studio 5.0.3.500及以上版本已被自动收集进白名单中，无需再手动配置，其它不能混淆文件名的场景仍需开发者手动配置。

## -compact

删除在代码中不参与语法结构、不影响程序运行的空格符和所有的换行符。

配置该选项后，所有代码会被压缩到一行。效果如下：

  <!-- @[optionExample_compact](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
  
  ``` TypeScript
  // 混淆前：
  class TestA {
    static prop1: number = 0;
  }
  TestA.prop1;
  ```

  ``` TypeScript
  // 混淆后：
  class TestA { static prop1: number = 0; } TestA.prop1;
  ```

>**说明**：
>
>release模式构建的应用堆栈信息仅包含代码行号，不包含列号，因此-compact功能开启后无法依据报错堆栈中的行号精确定位到源码中的具体语句位置。
>
>若希望对部分源码路径仍保留换行（便于对照报错栈行号阅读混淆中间产物），可在开启`-compact`的同时，使用[-keep-uncompact](./source-obfuscation-keep-options.md#-keep-uncompact)指定不参与压缩的源码路径。

## -remove-comments

删除编译生成的声明文件中的JSDoc注释，效果如下：

混淆前：
  <!-- @[optionExample_removeComments](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
  
  ``` TypeScript
  /**
   * @todo
   */
  declare let count1: number;
  ```

混淆后：
  ``` TypeScript
  declare let count: number;
  ```

使用[`-keep-comments`](./source-obfuscation-keep-options.md#-keep-comments)配置保留声明文件中的JSDoc注释。

>**说明**：
>
>编译生成的源码文件中的注释默认全部删除，不支持保留配置。

## -remove-log

删除对console.*语句的调用，要求console.*语句的返回值未被使用。效果如下：

  <!-- @[optionExample_removeLog1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
  
  ``` TypeScript
  // 混淆前：
  function add(a: number, b: number) {
    console.info("result", a + b);
    return a + b;
  }
  ```

  ``` TypeScript
  // 混淆后：
  function add(a: number, b: number) {
      return a + b;
  }
  ```

若配置该选项，以下场景中的console.*语句将被删除。

1. 文件顶层的调用。  

   <!-- @[optionExample_removeLog2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
   
   ``` TypeScript
   console.info("in tolevel");
   ```
2. 代码块中的调用。  

   <!-- @[optionExample_removeLog3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
   
   ``` TypeScript
   function foo1() {
     console.info('in block');
   }
   ```
3. module或namespace中的调用。  

   <!-- @[optionExample_removeLog4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->    
   
   ``` TypeScript
   // ArkGuardAbility.ts
   namespace ns {
     console.info('in ns');
   }
   ```
4. switch语句中的调用。  

   <!-- @[optionExample_removeLog5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
   
   ``` TypeScript
   function getDayName(day: number): string {
     switch (day) {
       case 1:
         console.info("Matched case 1: 星期一");
         return "星期一";
       case 2:
         console.info("Matched case 2: 星期二");
         return "星期二";
       default:
         console.error("No matching case for day:", day);
         return "无效的日期";
     }
   }
   ```

## -print-namecache

将名称缓存保存到指定的文件路径**filepath**中，名称缓存包含名称混淆前后的映射。其中，**filepath**为必选参数，支持相对路径和绝对路径，相对路径的起始位置为混淆配置文件的当前目录。**filepath**参数中的文件名请使用`.json`为后缀。

```text
-print-namecache
./customCache/nameCache.json
```

>**说明**：
>
>每次全量构建工程都会生成新的nameCache.json文件，因此发布新版本时需保存该文件的副本。

## -apply-namecache

复用指定的名称缓存文件**filepath**。**filepath**为必选参数，支持相对路径和绝对路径。相对路径的起始位置为混淆配置文件的当前目录。**filepath**参数中的文件名请以`.json`为后缀。

该选项适用于增量编译。开启后，名称将根据缓存文件映射进行混淆，新添加的第三方依赖库可能会导致混淆白名单发生改变，进而影响混淆结果。如果找不到对应的缓存，名称将被混淆为新的随机名称。

```text
-apply-namecache
./customCache/nameCache.json
```

默认情况下，DevEco Studio在临时缓存目录中保存缓存文件，并在增量编译时自动应用。

缓存目录：build/default/cache/{...}/release/obfuscation。

## -print-kept-names

该选项支持输出未混淆名单和全量白名单，并支持配置**filepath**。**filepath**为可选参数，仅支持相对路径。相对路径的起始位置为混淆配置文件的当前目录。**filepath**参数中的文件名请以`.json`为后缀。

从API version 18开始，支持输出未混淆名单和全量白名单。

当**filepath**参数缺省时，未混淆名单（keptNames.json）和全量白名单（whitelist.json）默认输出到缓存路径`build/default/cache/{...}/release/obfuscation`中。

若开发者配置了**filepath**参数，未混淆名单将输出到**filepath**参数指定的路径。

一次全量编译流程中收集到的白名单分为以下七种：

(1)'sdk'：表示系统api。

(2)'lang'：表示语言中的关键字。

(3)'conf'：表示用户配置的保留选项中的白名单。

(4)'struct'：表示ArkUI的struct中的属性。

(5)'exported'：表示被导出的名称及其属性。

(6)'strProp'：表示字符串属性。

(7)'enum'：表示enum中的成员。

其中，'sdk'类白名单单独输出到缓存路径`build/default/cache/{...}/release/obfuscation/`下的`systemApiCache.json`文件中，其他类型白名单则都输出到`whitelist.json`文件中。

未混淆名单（keptNames.json）中包含未混淆的名称及其原因。未混淆的原因包括：与SDK白名单重名、与语言白名单重名、与用户配置白名单重名、与结构体白名单重名、与导出白名单重名、与字符串属性白名单重名（未开启[字符串属性混淆](#-enable-string-property-obfuscation)的情况下）以及与枚举白名单重名。

**使用该选项时，需要注意以下事项：**

1. 在编译HAR模块且开启属性混淆的情况下，'enum'白名单将收集enum中的成员名称。

   <!-- @[optionExample_printKeptNames1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
   
   ``` TypeScript
   enum Test1 {
     member1,
     member2
   }
   ```
    
    enum白名单内容为['member1', 'member2']。这是由于历史版本的har模块的编译中间产物为js文件，在js文件中enum类型会转换为一个立即执行函数，而enum成员会被转化为一个字符串属性和一个字符串常量。因此，为了保证开启属性混淆的情况下功能正常，需要将enum成员名称收集为白名单。在编译新版字节码har模块时，此特性仍然被保留。

2. 在编译HAP/HSP/字节码HAR模块且开启属性混淆的情况下，当enum的成员被初始化时，'enum'白名单会收集初始化表达式中包含的变量名称。

   <!-- @[optionExample_printKeptNames2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->     
   
   ``` TypeScript
   // ArkGuardAbility.ts
   let outdoor = 1;
   enum Test2 {
     member1,
     member2 = outdoor + member1 + 2
   }
   ```

    其中，编译HAP/HSP模块时，enum白名单内容为['outdoor', 'member1']；编译字节码HAR模块时，enum白名单内容为['outdoor', 'member1', 'member2']。

## -extra-options strip-language-default

混淆的预置语言白名单中**默认包含了TypeScript的系统接口中关于DOM、WebWorker、ScriptHost等API的名称以及Web API的名称**。如果开发者源码中的属性与这部分名称重名，混淆工具会对这些属性进行保留。

如果开发者需要混淆这部分代码，需要配置`-extra-options strip-language-default`选项。

从API version 18开始，支持此选项。

开发者可通过以下方式确定混淆工具默认保留的API的具体减少范围：

开启`-print-kept-names`选项，对比开启和关闭`-extra-options strip-language-default`选项时，全量白名单（whitelist.json）中`lang`字段的内容差异，该差异即为预置语言白名单的具体减少范围。

## -extra-options strip-system-api-args

当前混淆的系统API白名单中**默认包含了系统API中的局部变量名称**，且系统API白名单默认对开发者源码中的局部变量生效。如果开发者源码中的属性与系统API中的局部变量重名或源码中的局部变量与系统API白名单重名，混淆工具会对这部分属性和局部变量名称进行保留。

需要混淆这部分代码时，配置`-extra-options strip-system-api-args`选项。

从API version 18开始，支持此选项。

系统API白名单文件（systemApiCache.json）的ReservedLocalNames、ReservedPropertyNames和ReservedGlobalNames字段可以查看系统API白名单的具体内容。系统API白名单文件位于模块目录下build/default/cache/{...}/release/obfuscation路径中，记录了SDK中的接口与属性名称，与其重名的源码不会被混淆。

开发者可通过以下方式确定系统白名单减少的具体范围：

通过对比开启和关闭`-extra-options strip-system-api-args`选项时系统API白名单文件（systemApiCache.json）中ReservedLocalNames和ReservedPropertyNames字段的内容差异，该差异即为系统白名单的具体减少范围，ReservedGlobalNames字段的内容不会产生变化。

## -extra-options strip-not-compiled-module-name

当前混淆的白名单中**默认包含了项目中所有的模块名称**。如果开发者源码中的文件名与模块名称重名，混淆工具会保留这些文件名。

开发者可通过配置`-extra-options strip-not-compiled-module-name`选项来混淆与未参与编译的模块同名的文件。

从API version 22开始，支持此选项。

开启该选项后，仅编译的模块及其直接和间接依赖的本地源码Har模块名称加入混淆白名单，其余模块名称不会被保留。

**使用-extra-options选项的方法如下**：

在混淆配置文件中添加`-extra-options`前缀和选项，且前缀与选项之间不能包含其他内容。支持开启单个选项或同时开启多个选项。

- 使用-extra-options前缀开启单个选项，有如下2种使用方式：

  ```text
  # 方式一
  -extra-options
  strip-language-default

  # 方式二
  -extra-options strip-language-default
  ```

- 使用-extra-options前缀同时开启多个选项，有如下5种使用方式：

  ```text
  # 方式一
  -extra-options strip-language-default, strip-system-api-args, strip-not-compiled-module-name

  # 方式二
  -extra-options strip-language-default strip-system-api-args strip-not-compiled-module-name

  # 方式三
  -extra-options
  strip-language-default strip-system-api-args strip-not-compiled-module-name

  # 方式四
  -extra-options
  strip-language-default
  strip-system-api-args
  strip-not-compiled-module-name

  # 方式五
  -extra-options strip-language-default
  -extra-options strip-system-api-args
  -extra-options strip-not-compiled-module-name
  ```

## -keep-parameter-names
从API version 18开始，支持保留声明文件中对外接口的参数名称。开启此选项后，有如下效果：
- 对于函数与类中成员方法，如果函数或方法名称没有被混淆，则保留其参数名称。
- 对于类的构造器，如果类名没有被混淆，则保留构造器中的参数名称。

**使用该选项时，需要注意以下事项：**

1. 对于非上述场景（如匿名函数）中的参数名称，无法通过此选项保留。

2. 源码文件中的参数名称仍然会被混淆，无法通过此选项保留。

## -enable-lib-obfuscation-options  
配置此开关后，依赖模块的混淆选项将被合并到当前编译模块的混淆配置中。

从API version 18开始，支持此选项。

混淆配置分为[混淆选项](#混淆选项汇总)和[保留选项](./source-obfuscation-keep-options.md)：
- **默认情况下**，生效的混淆配置为当前编译模块的混淆配置与依赖模块的保留选项的合并结果。  
- **启用该开关后**，生效的混淆配置为当前编译模块的混淆配置与依赖模块的混淆配置的合并结果。

混淆规则合并逻辑参考[混淆规则合并策略](./source-obfuscation.md#混淆规则合并策略)。

## -use-keep-in-source

从API version 19开始，支持在`.ts`和`.ets`源码中通过以下两种注释标记到白名单中，不支持在声明文件中使用。

`// @KeepSymbol`：用来标记需要保留的名称，通常写在代码上一行，表示该名称在编译时不会被混淆。

`// @KeepAsConsumer`：用来标记需要保留的名称，通常写在代码上一行，表示该名称在编译时不会被混淆。在HAR/HSP模块中，被@KeepAsConsumer标记的名称还会生成在obfuscation.txt中；在HAP模块中，@KeepAsConsumer和@KeepSymbol的效果相同。

> **说明**：
>
> 以上两种标记均为注释，不可去除"//"。

### 注释标记支持的语法场景

以下均以`// @KeepSymbol`为例，`// @KeepAsConsumer`支持的场景和`// @KeepSymbol`相同。

1. 类

    支持对类中的以下语法进行标记：

    - 类声明
    - 构造函数
    - 字段和方法

    <!-- @[optionExample_useKeepInSource1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->    
    
    ``` TypeScript
    // 保留类名和所有成员名
    // @KeepSymbol
    class MyClass02 {
      prop01: string = "prop"; // MyClass02和prop01不会被混淆
    }
    
    // 通过构造函数保留类名
    class MyClass03 {
      prop02: string = "prop";
      // @KeepSymbol
      constructor() {}; // MyClass03不会被混淆
    }
    
    // 保留类名和指定的字段名和方法，类中MyClass04，prop03_1，method03_2不会被混淆
    class MyClass04 {
      // @KeepSymbol
      prop03_1: string = "prop";
      prop03_2: number = 1;
      constructor() {};
    
      method03_1(): void {};
      // @KeepSymbol
      method03_2(): void {};
    }
    ```

2. 接口

    支持对接口中的以下语法进行标记：

    - 接口声明
    - 字段和方法

    <!-- @[optionExample_useKeepInSource2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->    
    
    ``` TypeScript
    // 保留接口名和所有成员名，MyInterface01，name01，foo01不会被混淆
    // @KeepSymbol
    interface MyInterface01 {
      name01: string;
      foo01(): void;
    }
    
    // 保留接口名和指定的字段和方法名，MyInterface02，name02不会被混淆
    interface MyInterface02 {
      // @KeepSymbol
      name02: string;
      foo02(): void;
    }
    ```

3. 枚举

    支持对枚举中的以下语法进行标记：

    - 枚举声明
    - 枚举成员

    <!-- @[optionExample_useKeepInSource3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->    
    
    ``` TypeScript
    // 保留枚举名和所有成员名，Color01，RED01，BLUE01不会被混淆
    // @KeepSymbol
    enum Color01 {
      RED01,
      BLUE01
    }
    
    // 保留枚举名指定的枚举成员名
    enum Color02 {
      RED02,
      // @KeepSymbol
      BLUE02 // Color02，BLUE02不会被混淆
    }
    ```

4. 函数

    支持对函数名进行标记。

    <!-- @[optionExample_useKeepInSource4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->    
    
    ``` TypeScript
    // 保留函数名，MyAdd不会被混淆
    // @KeepSymbol
    function MyAdd(a: number, b:number): number {
      return a + b;
    }
    ```

5. 命名空间

    支持对命名空间名称进行标记。

    <!-- @[optionExample_useKeepInSource5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->    
    
    ``` TypeScript
    // 保留命名空间名以及内部直接导出的成员名称，MyNameSpace以及foo不会被混淆
    // @KeepSymbol
    namespace MyNameSpace {
      export function foo(){};
      function bar(){};
    }
    ```

6. 全局变量

    支持全局变量的标记，不支持局部变量。

    <!-- @[optionExample_useKeepInSource6](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->     
    
    ``` TypeScript
    // 保留被标记的变量名，myVal不会被混淆
    // @KeepSymbol
    const myVal = 1;
    ```

7. 注解

    仅支持标记并保留注解声明。标记注解成员无效，注解成员本身不会被混淆。

    从API version 20开始，支持标记注解声明。

    <!-- @[etsOptionExample_useKeepInSource](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ets) -->    
    
    ``` TypeScript
    // 保留被标记的注解声明，MyAnnotation不会被混淆
    // @KeepSymbol
    @interface MyAnnotation2 {
      // 标记注解成员无效，authorName不会被收集到白名单
      // @KeepSymbol
      authorName: string;
      revision: number = 1;
    }
    ```

### 注释标记的白名单添加规则

被标记的名称根据以下规则添加到混淆白名单，被`// @KeepAsConsumer`保留的名称还会生成到[obfuscation.txt](./source-obfuscation-guide.md#混淆配置文件)文件中。

* 如果该名称位于顶层作用域或被直接导出，则会被添加到-keep-global-name中。

* 如果该名称被直接导出，还会被添加到-keep-property-name中。

* 如果该名称是属性，还会被添加到-keep-property-name中。

* 局部变量名不会被添加到白名单（不会被保留）。

  <!-- @[optionExample_useKeepInSource7](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->
  
  ``` TypeScript
  // @KeepAsConsumer
  export class MyClass05 {
    prop01: string = "prop";
  }
  ```

  上述示例中MyClass05会被添加到-keep-global-name和-keep-property-name中，`prop01`会被添加到-keep-property-name中，同时，该规则还会写入`obfuscation.txt`文件中。

### 注释标记不支持的语法场景

不支持字符串属性、数字属性以及计算属性。

<!-- @[optionExample_useKeepInSource8](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSCompilationToolchain/ArkGuardForSourceCodeObfuscation/ArkGuardObfuscationAbility/entry/src/main/ets/arkguardability/ArkGuardAbility.ts) -->    

``` TypeScript
// ArkGuardAbility.ts
const myMethodName = "myMethod";

// 11，aa，myMethod不会被收集到白名单中
class MyClass06 {
  // @KeepSymbol
  11:11;
  // @KeepSymbol
  'aa':'aa';
  // @KeepSymbol
  [myMethodName](){}
}

// RED不会被收集到白名单中
enum MyEnum {
  // @KeepSymbol
  'RED',
  BLUE
}
```

## -keep-object-props

从API version 23开始，支持使用-keep-object-props配置选项保留对象字面量中的属性名称和字符串属性名称。使用方法如下：

- 仅开启属性混淆（-enable-property-obfuscation）时，配置保留对象字面量（-keep-object-props）选项后，对象字面量中的属性名称会被收集到白名单中，不会被混淆。

- 同时开启属性混淆（-enable-property-obfuscation）和字符串属性混淆（-enable-string-property-obfuscation）时，配置保留对象字面量（-keep-object-props）选项后，对象字面量中的属性名称和字符串属性名称会被收集到白名单中，不会被混淆。  

>**说明**：
>
> 在开启属性混淆或者同时开启属性混淆和字符串属性混淆的情况下，-keep-object-props选项才会生效，否则该选项无效。

**支持的场景**

支持保留对象字面量的属性名称以及字符串属性名称。

```typescript
// example.ts
const propertyObj = {
    propertyKey1: 'value',
    propertyKey2: {
        propertyKey3: 'value'
    }
};
const stringPropertyObj = {
    'stringPropertyKey1': 'Alice',
    'stringPropertyKey2': {
        'stringPropertyKey3': 'additional data'
    }
};
```

1. 开启属性混淆时，如果配置了-keep-object-props选项，对于对象字面量中的属性名称，将不会被混淆。

   混淆配置选项文件obfuscation-rules.txt如下：
   ```text
   -keep-object-props
   -enable-property-obfuscation
   ```

   开启上述obfuscation-rules.txt配置文件的混淆选项后，示例代码中的属性名称propertyKey1、propertyKey2、propertyKey3将被收集到白名单中，不会被混淆。

2. 开启属性混淆和字符串属性混淆时，如果配置了-keep-object-props选项，对于对象字面量中的属性名称和字符串属性名称，将不会被混淆。

   混淆配置选项文件obfuscation-rules.txt如下：
   ```text
   -keep-object-props
   -enable-property-obfuscation
   -enable-string-property-obfuscation
   ```

   开启上述obfuscation-rules.txt配置文件的混淆选项后，示例代码中的属性名称propertyKey1、propertyKey2、propertyKey3以及字符串属性名称stringPropertyKey1、stringPropertyKey2、stringPropertyKey3将被收集到白名单中，不会被混淆。

**不支持的场景**

不支持非对象字面量的属性名场景。

```typescript
// example.ts
// -keep-object-props不生效场景：typeLiteral1、typeLiteral2、typeLiteral3、typeLiteral4、typeLiteral5均不为对象字面量中的属性，开启属性混淆或者同时开启属性混淆和字符串属性混淆的前提下，即使开启-keep-object-props选项也会被混淆。
interface TypeLiteralDemo {
  typeLiteral1: {
    typeLiteral2: number,
    'typeLiteral3': string
  },
  typeLiteral4: string,
  'typeLiteral5': string
}

// -keep-object-props不生效场景：Symbol.iterator、dynamic、Property均为复杂的计算属性，在开启属性混淆或者开启属性混淆和字符串属性混淆的前提下，开启-keep-object-props选项前后均不会被混淆。
const complexComputedPropertyObj = {
  [Symbol.iterator]: 'value',
  ["dynamic" + "Property"]: 'value'
}
```

## -remove-nosideeffects-calls
从API version 23开始，支持删除指定名称的方法调用，要求方法调用的返回值未被使用。该功能适用于删除自定义日志方法调用等场景。  

支持的方法调用方式有如下几种：  

1. 直接调用：method，匹配method()。
2. 点号调用：A.B，匹配A.B()。
3. 方括号调用：A["B"]，匹配A["B"]\(\)。
4. 嵌套调用：A.B["method"]，匹配A.B["method"]\(\)。
5. 通配符匹配：通过名称类通配符进行模式匹配，如*.log，匹配任意对象的log()。  

**使用该选项时，需要注意以下事项：**

1. 使用该选项在删除方法调用时不会分析其内部的副作用，需确保删除的方法调用不影响应用功能。

2. 配置项需与源码中实际调用处的完整名称一致，而非声明处的名称。

   例如，下面例子中的配置项`MyLog.debug`不是调用处的名称，`Log.debug()`不会被删除：  

   ```text
   // obfuscation-rules.txt或consumer-rules.txt：
   -remove-nosideeffects-calls
   MyLog.debug
   ```

   ``` TypeScript
   // a.ts
   export class MyLog {
     public static debug(message: string) {
       console.info(message);
     }
   }

   // b.ts
   import { MyLog as Log } from './a'

   Log.debug("this is alias"); 
   ```

3. 配置项间可用逗号、空格或换行的方式分隔。

在混淆配置文件obfuscation-rules.txt或consumer-rules.txt:

```text
-remove-nosideeffects-calls
logger
Log.debug*
example["log"].info
```

根据上述配置，在以下场景中的方法调用语句将被删除:  

1. 文件顶层的调用。

   ``` TypeScript
   function logger(msg: string) {
     console.info(msg);
   }

   logger("in top level"); // 经过混淆，该方法调用会被删除
   ```

2. 代码块的调用。

   ``` TypeScript
   class Log {
     public static debugBlock(msg: string) {
       console.info(msg);
     }
   }

   function foo() {
     Log.debugBlock("in block"); // 经过混淆，该方法调用会被删除
   }
   ```

3. module或namespace中的调用。

   ``` TypeScript
   // example.ts
   class Log {
     public static debugNamespace(msg: string) {
       console.info(msg);
     }
   }

   namespace ns {
     Log.debugNamespace("in namespace"); // 经过混淆，该方法调用会被删除
   }
   ```

4. switch语句中的调用。

   ``` TypeScript
   interface Logger {
     info: (msg: string, res?: number) => void;
   }

   const logFunc: Logger = {
     info: (msg: string, res?: number): void => {
       console.info(msg, res);
     }
   }

   const example: Record<string, Logger> = {
     ["log"]: logFunc
   }

   function getDayName(day: number): string {
     switch (day) {
       case 1:
         example["log"].info("Matched case 1: 星期一"); // 经过混淆，该方法调用会被删除
         return "星期一";
       case 2:
         example["log"].info("Matched case 2: 星期二"); // 经过混淆，该方法调用会被删除
         return "星期二";
       default:
         example["log"].info("No matching case for day:", day); // 经过混淆，该方法调用会被删除
         return "无效的日期";
     }
   }
   ```
