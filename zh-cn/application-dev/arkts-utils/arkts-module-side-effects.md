# 模块加载副作用及优化
## 概述
当使用[ArkTS模块化](module-principle.md)时，模块的加载和执行可能会引发**副作用**。副作用指的是模块导入时除了导出功能或对象之外，额外的行为或状态变化，**这些行为可能影响程序的其他部分，并导致产生非预期的顶层代码执行、全局状态变化、原型链修改、导入内容未定义等问题**。

## ArkTS模块化导致副作用的场景及优化方式
### 模块执行顶层代码
**副作用产生场景**

模块在被导入时，整个模块文件中的顶层代码会立即执行，而不仅仅是导出的部分。这意味着，即使只想使用模块中的某些导出内容，但是任何在顶层作用域中执行的代码也会被运行，从而产生副作用。
```typescript
// module.ets
console.log("Module loaded!"); // 这段代码在导入时会立即执行，可能会导致副作用。
export const data = 1;

// main.ets
import { data } from  './module' // 导入时，module.ets中的console.log会执行，产生输出。
console.log(data);
```
输出内容：
```typescript
Module loaded!
1
```
**产生的副作用**

即使只需要data，console.log("Module loaded!") 仍会运行，导致开发者可能预期只输出data的值，但却额外输出了“Module loaded!”，**影响输出内容**。

**优化方式**

优化方式1：去除顶层代码，只导出需要的内容，避免不必要的代码执行。
```typescript
// module.ets
export const data = 1;

// main.ets
import { data } from  './module'
console.log(data);
```
输出内容：
```typescript
1
```
优化方式2：将可能引发副作用的代码放在函数或方法内部，只有在需要时再执行，而不是在模块加载时立即执行。
```typescript
// module.ets
export function initialize() {
    console.log("Module loaded!");
}
export const data = 1;

// main.ets
import { data } from  './module'
console.log(data);
```
输出内容：
```typescript
1
```
### 修改全局对象
**副作用产生场景**

顶层代码或导入的模块可能会直接**操作全局变量**，改变全局状态，引发副作用。
```typescript
// module.ets
export let data1 = "data from module"
globalThis.someGlobalVar = 100; // 改变了全局状态

// sideEffectModule.ets
export let data2 = "data from side effect module"
globalThis.someGlobalVar = 200; // 也变了全局状态

// moduleUseGlobalVar.ets
import { data1 } from './module' // 此时可能预期全局变量someGlobalVar的值为100
export function useGlobalVar() {
    console.log(data1);
    console.log(globalThis.someGlobalVar); // 此时由于main.ets中加载了sideEffectModule模块，someGlobalVar的值已经被改为200
}

// main.ets（执行入口）
import { data1 } from "./module" // 将全局变量someGlobalVar的值改为100
import { data2 } from "./sideEffectModule" // 又将全局变量someGlobalVar的值改为200
import { useGlobalVar } from './moduleUseGlobalVar'

useGlobalVar();
function maybeNotCalledAtAll() {
    console.log(data1);
    console.log(data2);
}
```
输出内容：
```
data from module
200
```
**产生的副作用**

模块加载时直接修改全局变量 `globalThis.someGlobalVar` 的值，**会影响其他依赖该变量的模块或代码**。

**优化方式**

将可能引发副作用的代码放在函数或方法内部，只有在需要时再执行，而不是在模块加载时立即执行。
```typescript
// module.ets
export let data1 = "data from module"
export function changeGlobalVar() {
    globalThis.someGlobalVar = 100;
}

// sideEffectModule.ets
export let data2 = "data from side effect module"
export function changeGlobalVar() {
    globalThis.someGlobalVar = 200;
}

// moduleUseGlobalVar.ets
import { data1, changeGlobalVar } from './module'
export function useGlobalVar() {
    console.log(data1);
    changeGlobalVar(); // 在需要的时候执行代码，而不是模块加载时执行。
    console.log(globalThis.someGlobalVar);
}

// main.ets（执行入口）
import { data1 } from "./module"
import { data2 } from "./sideEffectModule"
import { useGlobalVar } from './moduleUseGlobalVar'

useGlobalVar();
function maybeNotCalledAtAll() {
    console.log(data1);
    console.log(data2);
}
```
输出内容：
```
data from module
100
```
### 修改应用级ArkUI组件的状态变量信息
**副作用产生场景**

顶层代码或导入的模块可能会直接**修改应用级ArkUI组件的状态变量信息**，改变全局状态，引发副作用。
```typescript
// module.ets
export let data = "data from module"
AppStorage.setOrCreate("SomeAppStorageVar", 200); // 修改应用全局的UI状态

// Index.ets
import { data } from "./module" // 将AppStorage中的SomeAppStorageVar改为200

@Entry
@Component
struct Index {
    // 开发者可能预期该值为100，但是由于module模块导入，该值已经被修改为200，但开发者可能并不知道值已经被修改
    @StorageLink("SomeAppStorageVar") message: number = 100;
    build() {
        Row() {
            Column() {
                Text("test" + this.message)
                    .fontSize(50)
            }
            .width("100%")
        }
        .height("100%")
    }
}
function maybeNotCalledAtAll() {
    console.log(data);
}
```
显示内容：
```
test200
```
**产生的副作用**

模块加载时直接修改AppStorage中SomeAppStorageVar的值，**会影响其他依赖该变量的模块或代码**。

ArkUI组件的状态变量信息可以通过一些应用级接口修改，详见[ArkUI状态管理接口文档](../ui/state-management/arkts-state-management-overview.md)。

**优化方式**

将可能引发副作用的代码放在函数或方法内部，只有在需要时再执行，而不是在模块加载时立即执行。
```typescript
// module.ets
export let data = "data from module"
export function initialize() {
    AppStorage.setOrCreate("SomeAppStorageVar", 200);
}

// Index.ets
import { data } from "./module"

@Entry
@Component
struct Index {
    @StorageLink("SomeAppStorageVar") message: number = 100;
    build() {
        Row() {
            Column() {
                Text("test" + this.message)
                    .fontSize(50)
            }
            .width("100%")
        }
        .height("100%")
    }
}
function maybeNotCalledAtAll() {
    console.log(data);
}
```
显示内容：
```
test100
```
### 修改内置全局变量或原型链（ArkTS内禁止修改对象原型与内置方法）
**副作用产生场景**

为支持现代JavaScript特性在旧浏览器或运行环境中运行，第三方库或框架可能修改内置的全局对象或原型链，这会影响其他代码的执行。
```typescript
// modifyPrototype.ts
export let data = "data from modifyPrototype"
Array.prototype.includes = function (value) {
    return this.indexOf(value) !== -1;
};

// main.ets
import { data } from "./modifyPrototype" // 此时修改了Array的原型链
let arr = [1, 2, 3, 4];
console.log("arr.includes(1) = " + arr.includes(1)); // 此时调用的是modifyPrototype.ts中的Array.prototype.includes方法
function maybeNotCalledAtAll() {
    console.log(data);
}
```
**产生的副作用**

修改内置的全局对象或原型链，影响其他代码运行。

**优化方式**

导入可能会修改内置的全局对象或原型链的第三方库时，确认该第三方库的行为是符合预期的。
### 循环依赖

**副作用产生场景**

ArkTS模块化支持循环依赖，即模块A依赖模块B，同时模块B又依赖模块A。在这种情况下，某些导入的模块可能尚未完全加载，从而导致部分代码在执行时行为异常，产生意外的副作用。
```typescript
// a.ets
import { b } from "./b"
console.log('Module A: ', b);
export const a = 'A';

// b.ets
import { a } from "./a"
console.log('Module B: ', a);
export const b = 'B';
```
输出内容：
```
Error message: a is not initialized
Stacktrace:
    at func_main_0 (b.ets:2:27)
```
**产生的副作用**

由于模块间相互依赖，模块的执行顺序可能导致导出的内容为空或未定义，影响代码的逻辑流。

**优化方式**

尽量避免模块间的循环依赖，确保模块的加载顺序是明确和可控的，以避免产生意外的副作用。[@security/no-cycle循环依赖检查工具](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide_no-cycle) 可以辅助检查循环依赖。
### 延迟加载（lazy import）改变模块执行顺序，可能导致预期的全局变量未定义
**副作用产生场景**

[延迟加载](arkts-lazy-import.md)特性可使待加载模块在冷启动阶段不被加载，直至应用程序实际运行过程中需要用到这些模块时，才按需同步加载相关模块，从而缩短应用冷启动耗时。但这也同时会改变模块的执行顺序。
```typescript
// module.ets
export let data = "data from module"
globalThis.someGlobalVar = 100;

// moduleUseGlobalVar.ets
import lazy { data } from "./module"
console.log(globalThis.someGlobalVar); // 此时由于lazy特性，module模块还未执行，someGlobalVar的值为undefined
console.log(data); // 使用到module模块的变量，此时module模块执行，someGlobalVar的值变为100
```
输出内容：
```
undefined
data from module
```
**产生的副作用**

由于使用到延迟加载（lazy import）特性，会导致模块变量在使用到时再执行对应的模块，模块中的一些全局变量修改行为也会延迟，可能会导致运行结果不符合预期。

**优化方式**

将可能引发副作用的代码放在函数或方法内部，只有在需要时再执行，而不是在模块加载时立即执行。
```typescript
// module.ets
export let data = "data from module"
export function initialize() {
    globalThis.someGlobalVar = 100; // 延迟到函数调用时执行
}

// moduleUseGlobalVar.ets
import lazy { data, initialize } from "./module"
initialize(); // 执行初始化函数，初始化someGlobalVar
console.log(globalThis.someGlobalVar); // 此时someGlobalVar一定为预期的值
console.log(data);
```
输出内容：
```
100
data from module
```