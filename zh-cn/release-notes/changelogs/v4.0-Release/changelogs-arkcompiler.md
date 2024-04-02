# ArkCompiler变更说明

## cl.ArkCompiler.1 ArkTS语法检查变更

为了推进ArkTS语法规则落地，在编译流程中添加ArkTS语法检查，对工程中的文件进行检查。并根据compatibleSdkVersion划分不同模式，根据模式判断是报warning还是error，以及是否阻塞编译。compatibleSdkVersion一般配置在build-profile.json5文件中。

具体规则可参考[从TypeScript到ArkTS的适配规则](../../../application-dev/quick-start/typescript-to-arkts-migration-guide.md)。

  - compatibleSdkVersion < 10 为兼容模式。在该模式下，对于违法ArkTS语法规则的代码，编译时报warning，不阻塞编译。
  - compatibleSdkVersion >= 10 为标准模式。在该模式下，对于违法ArkTS语法规则的代码，编译时报error，并阻塞编译。

**变更影响**

变更之前没有做ArkTS语法的检查，变更后对应用代码增加了ArkTS语法的检查，并根据工程的compatibleSdkVersion判断是报warning还是error，以及是否阻塞编译。

  - OpenHarmony SDK从4.0.10.3版本起，会开启编译告警。应用的工程进行编译时会对不符合ArkTS语法规则的代码给出warning告警，各模块可以根据告警信息进行适配，但并不阻塞编译。
  - OpenHarmony SDK在API version 10 Release时预计将以error告警来提示ArkTS语法不规则的代码，此时工程将无法编译。

**关键的接口/组件变更**

在编译流程中添加了ArkTS语法的检查。

**适配指导**

不符合ArkTS语法的文件需要进行适配修改，报错规则的具体说明和修改方式请参考[从TypeScript到ArkTS的适配规则](../../../application-dev/quick-start/typescript-to-arkts-migration-guide.md)。

若需要了解ArkTS语言请参考[ArkTS语言简介](../../../application-dev/quick-start/introduction-to-arkts.md)。

## cl.ArkCompiler.2 ArkTS语法检查工具变更

OpenHarmony SDK版本4.0.10.10/11相比4.0.10.8，ArkTS语法检查工具所涉及的规则有变更，以下规则涉及到的部分代码场景将报错。

> **说明： **
> 此变更仅为工具能力增强，使原先无法检查的语法规则可被工具检查覆盖，涉及的规则并非新增规则。

### 规则arkts-no-classes-as-obj

将导入的class作为变量使用，示例代码如下。

 ```ts
// module1.ets
export class C {}

// module2.ets
import { C } from './module1'

let c = C  // error: arkts-no-class-as-obj
 ```

**变更影响**

开发者需要适配代码，否则将导致编译失败。

**关键的接口/组件变更**

ArkTS语法检查工具变更。

**适配指导**

不符合ArkTS语法的文件需要进行适配修改，报错规则的具体说明和修改方式请参考[适配指导案例](../../../application-dev/quick-start/arkts-more-cases.md#arkts-no-classes-as-obj)。

### 规则arkts-strict-typing

将`X | undefined`类型赋值给.ets中`X`类型的实体，示例代码如下。

 ```ts
// module.ets
function foo(a: number) {
  return a + 1
}

function bar(x: number): number | undefined {
  return x > 0 ? x : undefined
}

foo(bar(-123))  // error: arkts-strict-typing
 ```

将`X | null`类型赋值给.ets中`X`类型的实体，示例代码如下。

 ```ts
// module.ets
function foo(a: number) {
  return a + 1
}

function bar(x: number): number | null {
  return x > 0 ? x : null
}

foo(bar(-123))  // error: arkts-strict-typing
 ```

**变更影响**

开发者需要适配代码，否则将导致编译失败。

**关键的接口/组件变更**

ArkTS语法检查工具变更。

**适配指导**

不符合ArkTS语法的文件需要进行适配修改，报错规则的具体说明和修改方式请参考[适配指导案例](../../../application-dev/quick-start/arkts-more-cases.md#arkts-strict-typingstrictmodeerror)。

### 规则arkts-no-ts-deps

在ts文件中`import`ets文件中的实体，示例代码如下。


 ```ts
// lib.ts
export class C {}


// module.ets
import { C } from './lib'
 ```

**变更影响**

开发者需要适配代码，否则将导致编译失败。

**关键的接口/组件变更**

ArkTS语法检查工具变更。

**适配指导**

不符合ArkTS语法的文件需要进行适配修改，报错规则的具体说明和修改方式请参考[适配指导案例](../../../application-dev/quick-start/arkts-more-cases.md#arkts-no-tsdeps)。

## cl.ArkCompiler.3 ArkTS语法规则变更

增加ArkTS语法规则等级，分为两个级别：错误（error）、警告（warning）。

- **错误**: 必须要遵从的约束。如果不遵从该约束，将会导致程序编译失败。 
- **警告**: 推荐遵从的约束。尽管现在违反该约束不会影响编译流程，但是在将来，违反该约束可能将会导致程序编译失败。

从4.0.10.11起，规则`arkts-no-definite-assignment`和`arkts-no-decorators-except-arkui`等级降为警告，不再阻塞工程编译，代码中使用`ESObject`会产生警告。

同时，ArkTS语法支持以下特性：

`tuple`、`keyof`、`for-of`、在数组场景下使用展开符、重导出、模块名以`.js`为后缀、`readonly`、`Encode`、`Decode`、`ParesHexOctet`、`Array.isArray`、`Object.entries`、`Object.keys`、`Object.values`、`Object.hasOwn`、`Object.hasOwnPropertyNames`、`Reflect.get`、`Reflect.set`、`Reflect.has`、`Reflect.ownKeys`、`Reflect.set`、`Symbol.iterator`、Utility类型中的`Required`和`Readonly`.

**变更影响**

开发者无需适配代码，无兼容性影响。
