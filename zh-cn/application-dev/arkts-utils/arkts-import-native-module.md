# 静态方式加载native模块
<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yao_dashuai-->
<!--SE: @yao_dashuai-->
<!--TSE: @kirl75;@zsw_zhushiwei-->

在ES6(ECMAScript 6.0)模块设计中，使用import语法加载其他文件导出的内容是ECMA规范所定义的语法规则。为支持开发者使用该功能导入native模块（so）导出的内容，ArkTS进行了相关适配，并提供了以下几种支持写法。

## 直接导入
在native模块的index.d.ts文件中导出，并在文件内直接导入。

### 具名导入
```ts
// libentry.so对应的index.d.ts
export const add: (a: number, b: number) => number;
```
```ts
// test.ets
import { add } from 'libentry.so'
add(2, 3);
```

### 默认导入
```ts
// libentry.so对应的index.d.ts
export const add: (a: number, b: number) => number;
```
```ts
// test.ets
import entry from 'libentry.so'
entry.add(2, 3);
```

### 命名空间导入
```ts
// libentry.so对应的index.d.ts
export const add: (a: number, b: number) => number;
```
```ts
// test.ets
import * as entry from 'libentry.so'
entry.add(2, 3);
```

## 间接导入

### 转为具名变量导出再导入
```ts
// libentry.so对应的index.d.ts
export const add: (a: number, b: number) => number;
```
```ts
// test1.ets
// 将libentry.so的API封装后导出
import { add } from 'libentry.so';
export { add };
```
```ts
// test2.ets
// 从中间模块导入API
import { add } from './test1';
const result = add(2, 3);
```

### 转为命名空间导出再导入
```ts
// libentry.so对应的index.d.ts
export const add: (a: number, b: number) => number;
```
```ts
// test1.ets
export * from 'libentry.so'
```
```ts
// test2.ets
import { add } from './test1'
add(2, 3);
```
> **注意：** 
> 
> 不支持native模块导出和导入同时使用命名空间。

**反例：** 
```ts
// test1.ets
export * from 'libentry.so'
```
```ts
// test2.ets
import * as add from './test1'
// 无法获取add对象
```

## 动态导入

### 直接导入
```ts
// libentry.so对应的index.d.ts
export const add: (a: number, b: number) => number;
```
```ts
// test.ets
import('libentry.so').then((entry:ESObject) => {
    entry.default.add(2, 3);
})
```
### 间接导入
```ts
// test1.ets
import add from 'libentry.so'
export { add }

// test2.ets
import('./test1').then((ns:ESObject) => {
    ns.add.add(2, 3);
})
```

> **注意：** 
> 
> 不支持动态加载时，导出文件使用命名空间。

**反例：** 
```ts
// test1.ets
export * from 'libentry.so'
```
```ts
// test2.ets
import('./test1').then((ns:ESObject) => {
    // 无法获取ns对象
})
```