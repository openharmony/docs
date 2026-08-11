# TSC错误码介绍
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @jokerxd-liu-->
<!--Designer: @huyunhui1; @liyancheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

TSC（TypeScript Compiler）的错误码以`105`开头，是TSC编译流程中的报错提示，会在编辑器、控制台或日志文件中显示输出错误码和相对应的报错描述。

## 10505001 TSC原生报错

TSC原生报错：以`001`结尾，是TSC检查中已有的原生报错规则。在TSC的编译流程中，常见的TSC原生报错原因包括：关键字或符号的缺失、多个默认导出、赋值类型与接收类型不一致、js文件接口声明缺失等。这些问题通常是未按照[ArkTS语言规范](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/introduction-to-arkts)编写代码导致的，开发者可以根据报错描述修改代码。

### 关键字或符号的缺失

**错误示例场景：**

```typescript
declare type Color = 'red;
```

**错误信息**

Unterminated string literal.

**错误描述**

字符串字面量未正确终止。

**可能原因**

字符串字面量没有在预期的位置正确终止，常见原因包括：缺少结束引号（单引号或双引号）；引号类型不匹配，例如以单引号开始但以双引号结束；字符串中包含与界定符相同的引号字符但未进行转义。

**处理步骤**

为修复字符串字面量未终止的错误，补全代码块中缺失的结束引号，修改后代码如下：

```typescript
declare type Color = 'red';
```

### 多个默认导出

**错误示例场景：**

```typescript
let config = { key: 'value' };
let logger = { log: () => {} };
export default config;
export default logger;
```

**错误信息**

A module cannot have multiple default exports.

**错误描述**

一个模块不能有多个默认导出。

**可能原因**

一个模块中定义了多个默认导出。

**处理步骤**

为修复模块存在多个默认导出的错误，删除多余的默认导出，修改后代码如下：

```typescript
export default config;
```

### 赋值类型与接收类型不一致

**错误示例场景：**

```typescript
let count: number = 1;
let amount: string = '2';
count = amount;
```

**错误信息**

Type 'string' is not assignable to type 'number'.

**错误描述**

类型 'string' 不能赋值给类型 'number'。

**可能原因**

将一个变量的值赋给另一个不同类型的变量时，会发生类型不匹配错误。

**处理步骤**

为修复类型不一致的错误，需要确保赋值类型与接收类型一致，如将变量`amount`的类型从`string`修改为`number`，修改后代码如下：

```typescript
let count: number = 1;
let amount: number = 2;
count = amount;
```

### js文件接口声明缺失

**错误示例场景：**

har1包中有js文件，存在导出接口：
```javascript
// har1 src/main/ets/FileJs.js
export let fileJs = 1;
```
har2包引用har1包中该接口：
```typescript
import { fileJs } from 'har1/src/main/ets/FileJs';
```

**错误信息**

Cannot find module ${moduleName} or its corresponding type declarations.

**错误描述**

找不到模块或其对应的类型声明文件，导致该模块无法被正常导入。

**可能原因**

[字节码HAR](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-har#section16598338112415)中包含js文件，而js文件在编译时TSC不会为其生成对应的.d.ts声明文件，因此依赖该模块的外部模块无法解析其类型声明，从而触发导入失败。

**处理步骤**

若HAR包中的js文件需要提供对外导出功能，开发者需要：

1.在js文件同级目录中手动编写对应的.d.ts声明文件，并随HAR包一起编译发布，示例如下：
```typescript
// har1's src/main/ets/FileJs.d.ts
export declare let fileJs: number;
```
2.在har1包顶层的Index.ets文件中增加export导出语句，示例如下：
```typescript
export { fileJs } from './src/main/ets/FileJs';
```
3.在har2包中引用har1包中该接口，示例如下：
```typescript
import { fileJs } from 'har1/src/main/ets/FileJs';
```