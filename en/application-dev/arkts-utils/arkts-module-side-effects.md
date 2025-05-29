# Side Effects and Optimization of Module Loading
## Overview
When using [ArkTS modularization](module-principle.md), the process of loading and executing modules may introduce side effects. These side effects refer to additional behavior or state changes that occur when importing a module, beyond simply exporting functions or objects. Such behavior might affect other parts of the program, leading to unintended consequences such as unexpected top-level code execution, global state changes, prototype chain modifications, and undefined imported content.

## Scenarios and Optimization Methods for Side Effects
### Top-Level Code Execution in Modules
**Scenario of Side Effects**

When a module is imported, all top-level code within the module file is executed immediately, not just the exported parts. This means that even if only specific exports are needed, any code in the top-level scope will run, potentially causing side effects.
```typescript
// module.ets
console.log("Module loaded!"); // The code is executed immediately upon import, which may cause side effects.
export const data = 1;

// main.ets
import { data } from  './module' // When data is imported, the console.log file in module.ets is executed and output is generated.
console.log(data);
```
The output is as follows:
```typescript
Module loaded!
1
```
**Side effects produced**

Even though only **data** is required, **console.log("Module loaded!")** still runs, causing the unexpected output of "Module loaded!" in addition to the value of **data**.

**Optimized methods**

Optimization method 1: Remove the top-level code and export only the required content to avoid unnecessary code execution.
```typescript
// module.ets
export const data = 1;

// main.ets
import { data } from  './module'
console.log(data);
```
The output is as follows:
```typescript
1
```
Optimization method 2: Encapsulate code that may cause side effects within functions or methods, and execute the code only when needed, rather than upon module loading.
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
The output is as follows:
```typescript
1
```
### Modifying Global Objects
**Scenario of side effects**

The top-level code or imported modules may directly manipulate global variables, thereby changing the global state and causing side effects.
```typescript
// module.ets
export let data1 = "data from module"
globalThis.someGlobalVar = 100; // The global state is changed.

// sideEffectModule.ets
export let data2 = "data from side effect module"
globalThis.someGlobalVar = 200; // The global state is changed.

// moduleUseGlobalVar.ets
import { data1 } from './module' // The expected value of the global variable someGlobalVar is 100.
export function useGlobalVar() {
    console.log(data1);
    console.log(globalThis.someGlobalVar); // The value of someGlobalVar is changed to 200 because the sideEffectModule module is loaded to main.ets.
}

// main.ets (entry point)
import { data1 } from "./module" // The value of the global variable someGlobalVar is changed to 100.
import { data2 } from "./sideEffectModule" // The value of the global variable someGlobalVar is changed to 200.
import { useGlobalVar } from './moduleUseGlobalVar'

useGlobalVar();
function maybeNotCalledAtAll() {
    console.log(data1);
    console.log(data2);
}
```
The output is as follows:
```
data from module
200
```
**Side effects produced**

Modules directly change the value of the **global variable globalThis.someGlobalVar**, affecting other modules or code that use this variable.

**Optimized methods**

Encapsulate code that may cause side effects within functions or methods, and execute the code only when needed, rather than upon module loading.
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
    changeGlobalVar(); // Execute the code when needed, not upon module loading.
    console.log(globalThis.someGlobalVar);
}

// main.ets (entry point)
import { data1 } from "./module"
import { data2 } from "./sideEffectModule"
import { useGlobalVar } from './moduleUseGlobalVar'

useGlobalVar();
function maybeNotCalledAtAll() {
    console.log(data1);
    console.log(data2);
}
```
The output is as follows:
```
data from module
100
```
### Modifying State Variables of Application-level ArkUI Components
**Scenario of side effects**

The top-level code or imported modules may directly modify the state variables of application-level ArkUI components, thereby changing the global state and causing side effects.
```typescript
// module.ets
export let data = "data from module"
AppStorage.setOrCreate("SomeAppStorageVar", 200); // The global UI state of the application is changed.

// Index.ets
import { data } from "./module" // SomeAppStorageVar in AppStorage is changed to 200.

@Entry
@Component
struct Index {
    // The expected value is 100. However, the value has been changed to 200 due to module import.
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
The following content is displayed:
```
test200
```
**Side effects produced**

Modules directly change the value of **SomeAppStorageVar** in AppStorage, affecting other modules or code that use this variable.

For more information on modifying ArkUI component state variables, see [State Management Overview](../quick-start/arkts-state-management-overview.md).

**Optimized methods**

Encapsulate code that may cause side effects within functions or methods, and execute the code only when needed, rather than upon module loading.
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
The following content is displayed:
```
test100
```
### Modifying Built-in Global Variables or Prototype Chains (Modifying Object Prototypes or Built-in Methods Is Forbidden in ArkTS)
**Scenario of side effects**

Some third-party libraries or frameworks may modify built-in global objects or prototype chains to support modern JavaScript features in older browsers or runtime environments. This may affect the execution of other code.
```typescript
// modifyPrototype.ts
export let data = "data from modifyPrototype"
Array.prototype.includes = function (value) {
    return this.indexOf(value) !== -1;
};

// main.ets
import { data } from "./modifyPrototype" // The prototype chain of the array is modified.
let arr = [1, 2, 3, 4];
console.log("arr.includes(1) = " + arr.includes(1)); // The Array.prototype.includes method in modifyPrototype.ts is called.
function maybeNotCalledAtAll() {
    console.log(data);
}
```
**Side effects produced**

Modifying built-in global objects or prototype chains affects the execution of other code.

**Optimized methods**

When importing third-party libraries that may modify built-in global objects or prototype chains, ensure that the behavior of the third-party library is as expected.
### Circular Dependencies

**Scenario of side effects**

ArkTS modularization supports circular dependencies, where module A depends on module B, and module B depends on module A. In such cases, some imported modules may not be fully loaded, leading to abnormal behavior and unintended side effects during execution.
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
The output is as follows:
```
Error message: a is not initialized
Stacktrace:
    at func_main_0 (b.ets:2:27)
```
**Side effects produced**

Due to mutual dependencies between modules, the execution order of modules may result in undefined exports, affecting the logic flow of the code.

**Optimized methods**

Avoid circular dependencies between modules whenever possible, and ensure that the loading order of modules is clear and controllable to prevent unexpected side effects. You can use [@security/no-cycle](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide_no-cycle-V5) when detecting circular dependencies.
### Lazy Import Changing the Module Execution Sequence and Leading to Undefined Global Variables
**Scenario of side effects**

The [Lazy Import](arkts-lazy-import.md) feature allows modules to be loaded on-demand during the application runtime, rather than during the cold start phase, thereby reducing the cold start time. However, this also changes the execution sequence of modules.
```typescript
// module.ets
export let data = "data from module"
globalThis.someGlobalVar = 100;

// moduleUseGlobalVar.ets
import lazy { data } from "./module"
console.log(globalThis.someGlobalVar); // The module is not executed due to lazy import. The value of someGlobalVar is undefined.
console.log(data); // During the value of the variable, the module is executed and the value of someGlobalVar changes to 100.
```
The output is as follows:
```
undefined
data from module
```
**Side effects produced**

Using the lazy import feature delays the execution of modules until they are needed. Modifications to global variables within these modules are also delayed, potentially leading to unexpected results.

**Optimized methods**

Encapsulate code that may cause side effects within functions or methods, and execute the code only when needed, rather than upon module loading.
```typescript
// module.ets
export let data = "data from module"
export function initialize() {
    globalThis.someGlobalVar = 100; // Delay the execution until the function is called.
}

// moduleUseGlobalVar.ets
import lazy { data, initialize } from "./module"
initialize(); // Execute the initialization function to initialize someGlobalVar.
console.log(globalThis.someGlobalVar); // someGlobalVar will have the expected value.
console.log(data);
```
The output is as follows:
```
100
data from module
```
