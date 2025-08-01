# ArkGuard混淆常见问题
<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @zju-wyx-->
<!--SE: @xiao-peiyang; @dengxinyu-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 如何排查功能异常

### 排查功能异常步骤
1. 在`obfuscation-rules.txt`中配置`-disable-obfuscation`选项关闭混淆，确认问题是否由混淆引起。
2. 若确认开启混淆后功能出现异常，请先阅读文档，了解模块已配置的混淆规则的能力和需要配置白名单的语法场景，以确保应用功能正常。下文简要介绍默认开启的四项选项功能，详情请参阅对应选项的完整描述。
    1. [-enable-toplevel-obfuscation](source-obfuscation.md#-enable-toplevel-obfuscation)为顶层作用域名称混淆开关。

    2. [-enable-property-obfuscation](source-obfuscation.md#-enable-property-obfuscation)为属性混淆开关。配置白名单的主要场景包括网络数据访问、json字段访问、动态属性访问、调用so库接口等。需要使用[-keep-property-name](source-obfuscation.md#-keep-property-name)来保留指定的属性名称。

    3. [-enable-export-obfuscation](source-obfuscation.md#-enable-export-obfuscation)为导入/导出名称混淆。一般与`-enable-toplevel-obfuscation`和`-enable-property-obfuscation`选项配合使用。配置白名单的主要场景为模块对外接口不能混淆。需要使用[-keep-global-name](source-obfuscation.md#-keep-global-name)来保留指定的导出/导入名称。

    4. [-enable-filename-obfuscation](source-obfuscation.md#-enable-filename-obfuscation)为文件名混淆。配置白名单的主要场景为动态import或运行时直接加载的文件路径。需要使用[-keep-file-name](source-obfuscation.md#-keep-file-name)来保留这些文件路径及名称。
3. 参考以下典型报错案例，若遇到相似场景，可参照对应解决方法快速处理。
4. 若以下报错案例中未找到相似场景，建议依据各项配置功能正向定位（若不需要相应功能，可删除对应配置项）。
5. 应用运行时崩溃分析方法：
    1. 打开应用运行日志，或点击DevEco Studio中出现的Crash弹窗，找到运行时崩溃栈。
    2. 应用运行时异常栈中的行号为[编译产物](source-obfuscation-guide.md#查看混淆效果)的行号，方法名也可能为混淆后名称；因此排查时建议直接根据异常栈查看编译产物，进而分析哪些名称不能被混淆，然后将其配置到白名单中。
6. 应用在运行时未崩溃但出现功能异常（如白屏）的分析方法：
    1. 打开应用运行日志：选择HiLog，检索与功能异常直接相关的日志，定位问题发生的上下文。

    2. 定位异常代码段：分析日志，找到引发功能异常的代码块。

    3. 增强日志输出：在疑似异常的功能代码中，增加日志打印以检查数据是否正常。

    4. 分析并确定关键字段：通过分析新增的日志输出，判断数据异常是否由混淆导致。

    5. 配置白名单以保护关键字段：将混淆后对应用功能有直接影响的关键字段添加到白名单中。

### 排查非预期的混淆能力
若出现预期外的混淆效果，检查是否由于依赖的本地模块或三方库开启了某些混淆选项。

示例：
假设当前模块未配置`-compact`，但混淆的中间产物中代码都被压缩成一行，可按照以下步骤排查混淆选项：

1. 查看当前模块的oh-package.json5中的dependencies，此字段记录了当前模块的依赖信息。
2. 在依赖的模块/三方库中的混淆配置文件内检索"-compact"：
    * 在本地依赖的library中的consumer-rules.txt文件中检索"-compact"。
    * 在工程目录下的oh_modules文件夹中，对全部的obfuscation.txt文件检索"-compact"。

从`API19`开始，主模块默认不合并三方库的`obfuscation.txt`文件中的混淆选项，保留选项仍然有效。

> **说明**：
> 
> 三方库中的`consumer-rules.txt`不建议配置以下开关选项。这些选项在主模块开启混淆时会生效，可能导致意外的混淆效果，甚至应用运行时崩溃。如果发现三方库的`obfuscation.txt`文件中包含以下开关选项，建议联系发布该三方库的团队删除这些选项并重新打包发布。 
> -enable-property-obfuscation  
> -enable-string-property-obfuscation  
> -enable-toplevel-obfuscation  
> -remove-log  
> -compact

## 典型报错案例及解决方案

### 报错信息为：Error message: Cannot read property xxx of undefined

**问题现象**

混淆规则配置如下所示：

```
-enable-property-obfuscation
```

示例代码如下：

```ts
// 示例JSON文件结构（test.json）：
/*
{
  "jsonObj": {
    "jsonProperty": "value"
  }
}
*/

// 混淆前
import jsonData from "./testjson";
let jsonProp = jsonData.jsonObj.jsonProperty;

// 混淆后
import jsonData from "./test.json";
let jsonProp = jsonData.i.j;
```

**问题原因**

开启属性混淆后，源码会被混淆，但json文件不会。源码中通过`jsonData.i`访问属性时，由于属性名称已经被混淆，json数据中并不存在对应的字段，导致获取的值为`undefined`。

**解决方案**

将json文件中的字段配置到属性白名单中。示例如下：

```
-keep-property-name
jsonObj
jsonProperty
```

### 报错信息为：Error message: is not callable

**场景一：导出namespace中的方法时，该方法定义处被混淆，调用时未被混淆**

**问题现象**

混淆规则配置如下所示：

```
-enable-toplevel-obfuscation
-enable-export-obfuscation
```

示例代码如下：

```ts
// 混淆前
// export.ts
export namespace NS {
  export function foo() {}
}

// import.ts
import { NS } from './export';
NS.foo();
```

```ts
// 混淆后
// export.ts
export namespace i {
  export function j() {}
}

// import.ts
import { i } from './export';
i.foo();
```

**问题原因**

namespace中的foo属于export元素，当通过`NS.foo`调用时被视为属性。由于未开启`-enable-property-obfuscation`选项，导致foo在使用时未被混淆。

**解决方案**

方案一：开启`-enable-property-obfuscation`选项。

方案二：使用`-keep-global-name`选项将namespace中导出的方法配置到白名单中。示例如下：

```
-keep-global-name
foo
```

**场景二：动态导入某个类，类定义处被混淆，调用时未被混淆**

**问题现象**

混淆规则配置如下所示：

```
-enable-toplevel-obfuscation
-enable-export-obfuscation
```

示例代码如下：

```ts
// 混淆前
// utils.ts
export function add(a: number, b: number): number {
  return a + b;
}

// main.ts
async function loadAndUseAdd() {
  try {
    const mathUtils = await import('./utils');
    const result = mathUtils.add(2, 3);
  } catch (error) {
    console.error('Failure reason:', error);
  }
}

loadAndUseAdd();
```

```ts
// 混淆后
// utils.ts
export function c1(d1: number, e1: number): number {
    return d1 + e1;
}

// main.ts
async function i() {
    try {
        const a1 = await import("@normalized:N&&&entry/src/main/ets/pages/utils&");
        const b1 = a1.add(2, 3);
    }
    catch (z) {
        console.error('Failure reason:', z);
    }
}
i();
```

**问题原因**

函数add在定义时位于顶层作用域，但通过`.add`访问时被视为属性。由于未开启`-enable-property-obfuscation`选项，导致add被使用时未进行混淆。

**解决方案**

方案一：开启`-enable-property-obfuscation`选项。

方案二：使用`-keep-global-name`选项将add配置到白名单中。示例如下：

```
-keep-global-name
add
```

**场景三：调用so库的方法后导致crash**

**问题现象**

混淆规则配置如下所示：

```
-enable-property-obfuscation
-enable-export-obfuscation
```

示例代码如下：

```ts
// 混淆前
import { nativeNapi } from 'library.so';
nativeNapi.getAge();
```

```ts
// 混淆后
import { nativeNapi } from 'library.so';
nativeNapi.m();
```

**问题原因**

混淆工具仅支持`js/ts/ets`代码的混淆。so库中的方法定义在C++侧，因此这些方法在定义处不会被混淆，但在调用处会被混淆。

**解决方案**

将so库导出的方法配置到属性白名单中。示例如下：

```
-keep-property-name
getAge
```

### 报错信息为：'module1/file1' does not provide an export name 'x', which is imported by 'module2/file2'

**问题现象**

主模块和HSP模块的混淆规则配置如下所示：

```
-enable-toplevel-obfuscation
-enable-export-obfuscation
```

示例代码如下：

```ts
// 混淆前
// hsp模块
export function add() {}

// entry模块
import { add } from 'hsp';
add();
```

```ts
// 混淆后
// hsp模块
export function b() {}

// entry模块
import { n } from '@normalized:N&myhsp&&myhsp/Index&';
n();
```

**问题原因**

当同时开启`-enable-toplevel-obfuscation`和`-enable-export-obfuscation`选项时，主模块与被调用模块的混淆情况如下：

| 主模块 | 依赖模块 | 导入与导出的名称混淆情况 |
| ------- | ------- | ----------------------------|
| HAP/HSP | HSP     | HSP和主模块是独立编译的，混淆后名称会不一致，因此都需要配置白名单。 |
| HAP/HSP | 本地HAR | 本地HAR与主模块一起编译，混淆后名称一致。 |
| HAP/HSP | 三方库  | 三方库中导出的名称及其属性会被收集到白名单，因此导入和导出时都不会被混淆。 |

由于HAP和HSP模块是独立编译，因此混淆后导入和导出名称不一致，从而导致HAP引用HSP的方法时报错。

**解决方案**

将HSP模块导出的方法配置到`-keep-global-name`下，并且需要在HSP的`consumer-rules.txt`和`obfuscation-rules.txt`文件中都进行对应配置。示例如下：

```
// consumer-rules.txt
-keep-global-name
add

// obfuscation-rules.txt
-keep-global-name
add
```

## 应用运行后无crash信息，但功能异常的情况

### 使用Record<string, Object>作为对象的类型定义时，属性被混淆

**问题现象**

`parameters`的类型为`Record<string, Object>`。开启属性混淆后，`parameters`对象中的`linkSource`属性被混淆，导致功能异常。

示例代码如下：

```
// 混淆前
import { Want } from '@kit.AbilityKit';
let petalMapWant: Want = {
  bundleName: 'com.example.myapplication',
  uri: 'maps://',
  parameters: {
    linkSource: 'com.other.app'
  }
}
```

```
// 混淆后
import type Want from "@ohos:app.ability.Want";
let petalMapWant: Want = {
    bundleName: 'com.example.myapplication',
    uri: 'maps://',
    parameters: {
        i: 'com.other.app'
    }
};
```

**问题原因**

示例中`parameters`的类型为`Record<string, Object>`，这仅表示以字符串为键的对象的泛型定义，未详细描述其内部属性。因此，混淆工具无法识别对象内部哪些属性不应被混淆，导致`linkSource`被混淆后，引发功能异常。

**解决方案**

将混淆后会出现问题的属性名配置到属性白名单中，示例如下：

```
-keep-property-name
linkSource
```

### 跨文件调用某属性，该属性在一个文件中保留，在另一个文件中被混淆

**问题现象**

混淆规则配置如下所示：

```
-enable-property-obfuscation
-keep
./file1.ts
```

在`file2.ts`中导入`file1.ts`的接口。该接口包含一个对象类型的属性。此对象属性在`file1.ts`中被保留，但在`file2.ts`中被混淆，导致调用时出现功能异常。

示例代码如下：

```ts
// 混淆前
// file1.ts
export interface MyInfo {
  age: number;
  address: {
    city1: string;
  }
}

// file2.ts
import { MyInfo } from './file1';
const person: MyInfo = {
  age: 20,
  address: {
    city1: "shanghai"
  }
}
```

```ts
// 混淆后
// file1.ts
export interface MyInfo {
  age: number;
  address: {
    city1: string;
  }
}

// file2.ts
import { MyInfo } from './file1';
const person: MyInfo = {
  age: 20,
  address: {
    i: "shanghai"
  }
}
```

**问题原因**

使用`-keep`选项保留`file1.ts`文件时，该文件中的代码不会被混淆。导出属性（如address）所属类型内的属性不会自动加入白名单，因此在其他文件中使用时会被混淆。

**解决方案**

方案一：使用`interface`定义该属性的类型，并使用`export`进行导出，这样该属性将被自动加入到属性白名单中。示例如下：

```ts
// file1.ts
export interface AddressType {
  city1: string;
}
export interface MyInfo {
  age: number;
  address: AddressType;
}
```

方案二：使用`-keep-property-name`选项，将未直接导出的类型内的属性配置到属性白名单中。示例如下：

```
-keep-property-name
city1
```

### 未开启-enable-string-property-obfuscation，字符串字面量属性名却被混淆

**问题现象**

```
// 混淆前
person["age"] = 22;
```

```
// 混淆后
person["b"] = 22;
```

**问题原因**

主模块所依赖的其他模块中的`consumer-rules.txt`文件配置了`-enable-string-property-obfuscation`选项，主模块会合并该选项，导致字符串字面量属性名被混淆。

**解决方案**

从`API19`开始，主模块默认不会被三方库的混淆规则所影响，因此不会有这种情况。但如果API版本低于19，可参考以下两种解决方案。

方案一：确认依赖模块是否开启了字符串属性名混淆。若开启，会影响主模块，需将其关闭。参考[排查非预期的混淆能力](source-obfuscation-questions.md#排查非预期的混淆能力)。
方案二：若工程复杂无法找到开启了该混淆配置选项的模块，可以将属性名直接配置到白名单中。

### 数据库相关的字段被混淆后导致功能异常

**问题现象**

Hilog日志中报错信息为：`table Account has no column named a23 in 'INSERT INTO Account(a23)'`。

**问题原因**

混淆时代码中的SQL语句字段名称被混淆，但数据库中字段为原始名称，从而导致报错。

**解决方案** 

使用`-keep-property-name`选项将使用到的数据库字段配置到白名单。