# ArkGuard混淆常见问题

## 如何排查功能异常

### 排查功能异常步骤
1. 先在obfuscation-rules.txt配置-disable-obfuscation选项关闭混淆，确认问题是否由混淆引起。
2. 若确认是开启混淆后功能出现异常，请先阅读文档了解[-enable-property-obfuscation](source-obfuscation.md#-enable-property-obfuscation)、[-enable-toplevel-obfuscation](source-obfuscation.md#-enable-toplevel-obfuscation)、[-enable-filename-obfuscation](source-obfuscation.md#-enable-filename-obfuscation)、[-enable-export-obfuscation](source-obfuscation.md#-enable-export-obfuscation)等混淆规则的能力以及哪些语法场景需要配置白名单来保证应用功能正常。下文简要介绍默认开启的四项选项功能，细节还请阅读对应选项的完整描述。  
    1. [-enable-toplevel-obfuscation](source-obfuscation.md#-enable-toplevel-obfuscation)为顶层作用域名称混淆开关。
    2. [-enable-property-obfuscation](source-obfuscation.md#-enable-property-obfuscation)为属性混淆开关，配置白名单的主要场景包括网络数据访问、json字段访问、动态属性访问、调用so库接口等不能混淆的场景，需要使用[-keep-property-name](source-obfuscation.md#-keep-property-name)来保留指定的属性名称。
    3. [-enable-export-obfuscation](source-obfuscation.md#-enable-export-obfuscation)为导出名称混淆，一般与`-enable-toplevel-obfuscation`和`-enable-property-obfuscation`选项配合使用；配置白名单的主要场景为模块对外接口不能混淆，需要使用[-keep-global-name](source-obfuscation.md#-keep-global-name)来指定保留导出/导入名称。
    4. [-enable-filename-obfuscation](source-obfuscation.md#-enable-filename-obfuscation)为文件名混淆，配置白名单的主要场景为动态import或运行时直接加载的文件路径，需要使用[-keep-file-name](source-obfuscation.md#-keep-file-name)来保留这些文件路径及名称。
3. 参考常见报错案例，若遇到相似场景，可参照对应解决方法快速处理。
4. 若常见案例中未找到相似案例，建议依据各项配置功能正向定位（若不需要相应功能，可删除对应配置项）。
5. 应用运行时崩溃分析方法：
    1.打开应用运行日志，或点击DevEco Studio中出现的Crash弹窗，找到运行时崩溃栈。
    2.应用运行时崩溃栈中的行号为[编译产物](source-obfuscation-guide.md#查看混淆效果)的行号，方法名也可能为混淆后名称；因此排查时建议直接根据崩溃栈查看编译产物，进而分析哪些名称不能被混淆，然后将其配置到白名单中。
6. 应用在运行时未崩溃但出现功能异常（如白屏）的分析方法：：
    1.打开应用运行日志：选择HiLog，检索与功能异常直接相关的日志，定位问题发生的上下文。
    2.定位异常代码段：分析日志，找到导致功能异常的具体代码块。
    3.增强日志输出：在疑似异常的功能代码中，对处理的数据字段添加日志记录。
    4.分析并确定关键字段：通过分析新增的日志输出，判断数据异常是否由混淆引起。
    5.配置白名单以保护关键字段：将确认在混淆后对应用功能产生直接影响的关键字段添加到白名单中。

#### 排查非预期的混淆能力
若出现预期外的混淆效果，检查是否由于依赖的本地模块或三方库开启了某些混淆选项。

示例：
假设当前模块未配置`-compact`，但是混淆的中间产物中代码都被压缩成一行，可按照以下步骤排查混淆选项：

1. 查看当前模块的oh-package.json5中的dependencies，此字段记录了当前模块的依赖信息。
2. 在依赖的模块/三方库中的混淆配置文件内检索"-compact"：
    * 在本地依赖的library中的consumer-rules.txt文件中检索"-compact"。
    * 在工程目录下的oh_modules文件夹中，对全部的obfuscation.txt文件检索"-compact"。

> **说明**：
> 
> 三方库中的`consumer-rules.txt`不建议配置以下开关选项。这些选项在主模块开启混淆时会生效，可能导致意外的混淆效果，甚至应用运行时崩溃。如果发现三方库的`obfuscation.txt`文件中包含以下开关选项，建议联系发布该三方库的团队删除这些选项并重新打包发布。  
> -enable-property-obfuscation  
> -enable-string-property-obfuscation  
> -enable-toplevel-obfuscation  
> -remove-log  
> -compact

## 属性混淆的问题

### 数据库相关的字段，开启属性混淆时报错

**问题现象**

报错内容为：`table Account has no column named a23 in 'INSET INTO Account(a23)'`。

**问题原因**

代码里使用了数据库字段，混淆时该SQL语句中字段名称被混淆，但数据库中字段为原始名称，从而导致报错。

**解决方案** 

使用`-keep-property-name`选项将使用到的数据库字段配置到白名单。

### 使用Record<string, Object>作为对象的类型时，属性被混淆

**问题现象**

`parameters`的类型为`Record<string, Object>`，在开启属性混淆后，`parameters`对象中的属性`linkSource`被混淆，进而导致功能异常。示例如下：

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

在这个示例中，所创建的对象的内容需要传递给系统来加载某个页面，因此对象中的属性名称不能被混淆，否则会造成功能异常。示例中`parameters`的类型为`Record<string, Object>`，这只是一个表示以字符串为键的对象的泛型定义，并没有详细描述其内部结构和属性类型。因此，混淆工具无法识别该对象内部哪些属性不应被混淆，从而可能导致内部属性名`linkSource`被混淆。

**解决方案**

将混淆后会出现问题的属性名配置到属性白名单中，示例如下：

```
-keep-property-name
linkSource
```

### 跨文件调用某属性，该属性在一个文件中保留，在另一个文件中被混淆

**问题现象**

使用如下混淆配置：

```
-enable-property-obfuscation
-keep
./file1.ts
```

并且在`file2.ts`中导入`file1.ts`的接口。此时，接口中有属性的类型为对象类型，该对象类型的属性在`file1.ts`中被保留，在`file2.ts`中被混淆，从而导致调用时引发功能异常。示例如下：

```
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

```
// 混淆后
// file1.ts的代码被保留
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

使用`-keep`选项保留`file1.ts`文件时，该文件中的代码不会被混淆。导出属性（如address）所属类型内的属性不会自动收集到白名单中。因此，这些属性在其他文件中使用时会被混淆。

**解决方案**

方案一：使用`interface`定义该属性的类型，并使用`export`进行导出，这样该属性会被自动被收集到属性白名单中。示例如下：

```
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

主工程的依赖模块中开启了字符串属性名混淆，其混淆规则导出合并至主模块中。

**解决方案**

方案一：确认依赖模块是否开启了字符串属性名混淆。若开启，会影响主工程，需将其关闭。参考[排查非预期的混淆能力](source-obfuscation-questions.md#排查非预期的混淆能力)。  
方案二：若工程复杂无法找到开启了该混淆配置选项的模块，可以将属性名直接配置到白名单中。

## 导入导出名称不一致的问题

### 动态导入某个类，类的定义处被混淆，调用处未被混淆

**问题现象**

当不开启`-enable-property-obfuscation`，动态导入某个类时，类的定义处被混淆，调用处未被混淆，导致调用处报错。

```
// 混淆前
// file1.ts
export class Test1 {}
// file2.ts
let mytest = (await import('./file1')).Test1;
```

```
// 混淆后
// file1.ts
export class w1 {}
// file2.ts
let mytest = (await import('./file1')).Test1;
```

**问题原因**

导出的类 "Test1" 是一个顶层作用域名，当 "Test1" 被动态使用时，它是一个属性。因为没有开启`-enable-property-obfuscation`选项，所以名称混淆了，但属性没有混淆。

**解决方案**

使用`-keep-global-name`选项将 "Test1" 配置到白名单。

### 导出namespace中的方法时，该方法定义处被混淆，调用处未被混淆

**问题现象**

当未开启`-enable-property-obfuscation`选项，导出namespace中的方法时，该方法定义处被混淆，调用处未被混淆，导致调用处报错。

```
// 混淆前
//file1.ts
export namespace ns1 {
  export class person1 {}
}
//file2.ts
import {ns1} from './file1';
let person1 = new ns1.person1();
```

```
// 混淆后
//file1.ts
export namespace a3 {
  export class b2 {}
}
//file2.ts
import {a3} from './file1';
let person1 = new a3.person1();
```

**问题原因**

namespace里的 "person1" 属于export元素，当通过 "ns1.person1" 调用时，它被视为一个属性。由于未开`-enable-property-obfuscation`选项，导致在使用时未对其进行混淆。

**解决方案**

方案一：开启`-enable-property-obfuscation`选项。  
方案二：使用`-keep-global-name`选项将namespace中导出的方法添加到白名单。

## 模块间相互依赖的问题

### 主模块依赖HSP模块时，HSP模块导出接口被错误混淆问题

**问题现象**

主模块中，使用的HSP导出接口被错误混淆。

```
//混淆前
import { MyHspClass } from "myhsp";
new MyHspClass().myHspMethod();
```

```
//混淆后
import { t } from "@normalized:N&myhsp&&myhsp/Index&";
new t().a1();
```

**问题原因**

当开启-enable-export-obfuscation和-enable-toplevel-obfuscation时，主模块调用其他模块方法时涉及的方法名称混淆情况如下：

| 主模块 | 依赖模块 | 导入与导出的名称混淆情况 |
| ------- | ------- | ----------------------------|
| HAP/HSP | HSP     | HSP和主模块是独立编译的，混淆后名称会不一致，因此都需要配置白名单。 |
| HAP/HSP | 本地HAR | 本地HAR与主模块一起编译，混淆后名称一致。 |
| HAP/HSP | 三方库  | 三方库中导出的名称及其属性会被收集到白名单，因此导入和导出时都不会被混淆。 |

**解决方案**

为了确保其他模块能正常调用HSP模块的方法，需在混淆配置中添加白名单。主模块和HSP模块应保持相同的白名单配置，建议按以下步骤操作：

1. 在HSP模块的混淆配置文件（如 hsp-white-list.txt）中添加白名单。
2. 在依赖HSP的其他模块的混淆配置中，通过files字段引入该配置文件。
这样可以确保白名单配置的一致性，避免重复维护。配置方法参考下图：

![obfuscation-config](figures/obfuscation-config.png)

### HAP与HSP依赖相同的本地源码HAR模块，单例功能异常/接口调用失败

**问题现象**

* 若开启文件名混淆，将导致以下问题：
  * 问题一：单例功能异常问题。原因是HAP与HSP独立执行构建与混淆流程，本地源码HAR模块在HAP与HSP的包中可能会出现相同的文件名被混淆成不同文件名的情况。
  * 问题二：接口调用失败问题。原因是HAP与HSP独立执行构建与混淆流程，本地源码HAR模块在HAP与HSP的包中可能会出现不同的文件名被混淆成相同的文件名的情况。
* 若开启`-enable-export-obfuscation`和`-enable-toplevel-obfuscation`选项，在应用运行时会出现加载接口失败的问题。

**问题原因**

HAP与HSP独立执行构建与混淆流程，本地源码HAR模块中暴露的接口在HAP与HSP中被混淆成不同的名称。

**解决方案**

方案一：将HAP与HSP共同依赖的本地源码HAR改造为[字节码HAR](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-har#section16598338112415)，这样此HAR在被依赖时不会被二次混淆。    
方案二：将HAP与HSP共同依赖的本地源码HAR以[release模式构建打包](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-har#section19788284410)，这样此HAR在被依赖时，其文件名与对外接口不会被混淆。