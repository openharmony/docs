# ArkCompiler子系统Changelog

## cl.ArkCompiler.1 ArkTS语法检查工具变更

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

## cl.ArkCompiler.2 ArkTS语法规则变更

增加ArkTS语法规则等级，分为两个级别：错误（error）、警告（warning）。

- **错误**: 必须要遵从的约束。如果不遵从该约束，将会导致程序编译失败。 
- **警告**: 推荐遵从的约束。尽管现在违反该约束不会影响编译流程，但是在将来，违反该约束可能将会导致程序编译失败。

从4.0.10.11起，规则`arkts-no-definite-assignment`和`arkts-no-decorators-except-arkui`等级降为警告，不再阻塞工程编译，代码中使用`ESObject`会产生警告。

同时，ArkTS语法支持以下特性：

`tuple`、`keyof`、`for-of`、在数组场景下使用展开符、重导出、模块名以`.js`为后缀、`readonly`、`Encode`、`Decode`、`ParesHexOctet`、`Array.isArray`、`Object.entries`、`Object.keys`、`Object.values`、`Object.hasOwn`、`Object.hasOwnPropertyNames`、`Reflect.get`、`Reflect.set`、`Reflect.has`、`Reflect.ownKeys`、`Reflect.set`、`Symbol.iterator`、Utility类型中的`Required`和`Readonly`.

**变更影响**

开发者无需适配代码，无兼容性影响。
