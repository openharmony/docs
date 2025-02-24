# Module Loading Side Effects and Optimization
## Overview
When using [ArkTS modularization](module-principle.md), the loading and execution of modules may cause side effects. Side effects refer to extra behavior or state changes in addition to exporting functions or objects during module import. These behaviors may affect other parts of the program and cause unexpected top-level code execution, global state changes, prototype chain modification, and undefined imported content.

## Scenarios and Optimization Methods of Side Effects Caused by ArkTS Modularization
### Executing the Top-level Code
**Scenario**

When a module is imported, the top-level code in the entire module file is executed immediately, not just the exported part. This means that even if you only want to use some of the exported content in the module, any code executed in the top-level scope will be run, resulting in side effects.
```typescript
// module.ets
console.log ("Module loaded!"); // The code is executed immediately after being imported, which may cause side effects.
export const data = 1;

// main.ets
import {data} from './module' // When data is imported, the console.log file in module.ets is executed and output is generated.
console.log(data);
```
The outputs are listed as follows:
```typescript
Module loaded!
1
```
**Side effects**

Even if only data is required, console.log ("Module loaded!") still runs. As a result, developers may expect that only the value of data is output, but "Module loaded!" is output, which affects the output content.

**Optimized mode**

Optimization method 1: Remove the top-level code and export only the required content to avoid unnecessary code execution.
```typescript
// module.ets
export const data = 1;

// main.ets
import { data } from  './module'
console.log(data);
```
The outputs are listed as follows:
```typescript
1
```
Optimization method 2: Place the code that may cause side effects in the function or method and execute the code only when necessary, instead of executing the code immediately when the module is loaded.
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
The outputs are listed as follows:
```typescript
1
```
### Modifying a global object
**Scenario**

The top-level code or imported module may directly operate global variables to change the global state and cause side effects.
```typescript
// module.ets
export let data1 = "data from module"
globalThis.someGlobalVar = 100; // The global state is changed.

// sideEffectModule.ets
export let data2 = "data from side effect module"
globalThis.someGlobalVar = 200; // The global state is changed.

// moduleUseGlobalVar.ets
import {data1} from './module' // The value of the global variable someGlobalVar may be expected to be 100.
export function useGlobalVar() {
    console.log(data1);
    console.log (globalThis.someGlobalVar); // The value of someGlobalVar is changed to 200 because the sideEffectModule module is loaded to main.ets.
}

// main.ets (execution entry)
import {data1} from ."/module" // Change the value of the global variable someGlobalVar to 100.
import {data2} from ."/sideEffectModule" // Change the value of the global variable someGlobalVar to 200.
import { useGlobalVar } from './moduleUseGlobalVar'

useGlobalVar();
function maybeNotCalledAtAll() {
    console.log(data1);
    console.log(data2);
}
```
The outputs are listed as follows:
```
data from module
200
```
**Side effects**

When a module is loaded, the value of the global variable globalThis.someGlobalVar is directly changed, affecting other modules or code that use the variable.

**Optimized mode**

Code that may cause side effects is placed inside a function or method and executed only when necessary, instead of being executed immediately when the module is loaded.
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
    changeGlobalVar (); // Execute the code when necessary instead of when the module is loaded.
    console.log(globalThis.someGlobalVar);
}

// main.ets (execution entry)
import { data1 } from "./module"
import { data2 } from "./sideEffectModule"
import { useGlobalVar } from './moduleUseGlobalVar'

useGlobalVar();
function maybeNotCalledAtAll() {
    console.log(data1);
    console.log(data2);
}
```
The outputs are listed as follows:
```
data from module
100
```
### Modifying State Variables of Application-level ArkUI Components
**Scenario**

The top-level code or imported module may directly modify the state variable information of the application-level ArkUI component, thereby changing the global state and causing side effects.
```typescript
// module.ets
export let data = "data from module"
AppStorage.setOrCreate ("SomeAppStorageVar," 200); // Modify the global UI state of the application.

// Index.ets
import {data} from ."/module" // Change SomeAppStorageVar in AppStorage to 200.

@Entry
@Component
struct Index {
    // The expected value is 100. However, the value has been changed to 200 due to module import. However, the developer may not know that the value has been changed.
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
Display
```
test200
```
**Side effects**

When a module is loaded, the value of SomeAppStorageVar in AppStorage is changed, affecting other modules or code that use the variable.

The state variables of the ArkUI component can be modified through some application-level APIs. For details, see [ArkUI State Management](../quick-start/arkts-state-management-overview.md).

**Optimized mode**

Code that may cause side effects is placed inside a function or method and executed only when necessary, instead of being executed immediately when the module is loaded.
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
Display
```
test100
```
### Modifying Built-in Global Variables or Prototype Chains (Modifying Object Prototypes or Built-in Methods in ArkTS Is Forbidden)
**Scenario**

Some third-party libraries or frameworks may modify built-in global objects or prototype chains to support modern JavaScript features in older browsers or runtime environments. This may affect the running of other code.
```typescript
// modifyPrototype.ts
export let data = "data from modifyPrototype"
Array.prototype.includes = function (value) {
    return this.indexOf(value) !== -1;
};

// main.ets
import {data} from ."/modifyPrototype" // The prototype chain of the array is modified.
let arr = [1, 2, 3, 4];
console.log (arr.includes (1)); // The Array.prototype.includes method in modifyPrototype.ts is called.
function maybeNotCalledAtAll() {
    console.log(data);
}
```
**Side effects**

Modifying a built-in global object or prototype chain affects the running of other code.

**Optimized mode**

When importing a third-party library that may modify the built-in global object or prototype chain, ensure that the behavior of the third-party library meets the expectation.
### Circular Dependency

**Scenario**

ArkTS modularization supports circular dependency. That is, module A depends on module B, and module B depends on module A. In this case, some imported modules may not be completely loaded. As a result, some code behaves abnormally during execution, causing unexpected side effects.
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
The outputs are listed as follows:
```
Error message: a is not initialized
Stacktrace:
    at func_main_0 (b.ets:2:27)
```
**Side effects**

Modules are dependent on each other. The execution sequence of modules may cause the exported content to be empty or undefined, affecting the logic flow of the code.

**Optimized mode**

Avoid circular dependency between modules and ensure that the module loading sequence is clear and controllable to avoid unexpected side effects. [@security/no-cycle](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide_no-cycle-V5) can be used to assist in circular dependency check.
### Lazy Import Changes the Module Execution Sequence and Leads to Undefined Global Variables
**Scenario**

[Lazy Import](arkts-lazy-import.md) prevents the modules to be loaded from being loaded in the cold start phase. The modules are loaded as required only when they are required during the running of the application, in this way, the time required for cold startup of the application is shortened. However, this also changes the execution sequence of the modules.
```typescript
// module.ets
export let data = "data from module"
globalThis.someGlobalVar = 100;

// moduleUseGlobalVar.ets
import lazy { data } from "./module"
console.log (globalThis.someGlobalVar); // The module is not executed due to the lazy feature. The value of someGlobalVar is undefined.
console.log (data); // Variables of the module are used. When the module is executed, the value of someGlobalVar changes to 100.
```
The outputs are listed as follows:
```
undefined
data from module
```
**Side effects**

The lazy import feature is used. As a result, the corresponding module is executed when the module variable is used, and the modification of some global variables in the module is delayed. As a result, the running result may not meet the expectation.

**Optimized mode**

Code that may cause side effects is placed inside a function or method and executed only when necessary, instead of being executed immediately when the module is loaded.
```typescript
// module.ets
export let data = "data from module"
export function initialize() {
    globalThis.someGlobalVar = 100; // Delay the execution until the function is called.
}

// moduleUseGlobalVar.ets
import lazy { data, initialize } from "./module"
initialize (); // Execute the initialization function to initialize someGlobalVar.
console.log (globalThis.someGlobalVar); // The value of someGlobalVar must be the expected value.
console.log(data);
```
The outputs are listed as follows:
```
100
data from module
```
