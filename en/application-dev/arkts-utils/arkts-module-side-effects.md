# Side Effects and Optimization of Module Loading
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @wangchen965-->
<!--Designer: @yao_dashuai-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

## Overview

When using [ArkTS modularization](module-principle.md), the process of loading and executing modules may introduce side effects. These side effects refer to additional behavior or state changes that occur when importing a module, beyond simply exporting functions or objects. Such behavior might affect other parts of the program, leading to unintended consequences such as unexpected top-level code execution, global state changes, prototype chain modifications, and undefined imported content.

## Scenarios and Optimization Methods for Side Effects

### Top-Level Code Execution in Modules

**Scenario of side effects**

When a module is imported, all top-level code within the module file is executed immediately, not just the exported parts. This means that even if only specific exports are needed, any code in the top-level scope will run, potentially causing side effects.

```typescript
// module.ets
console.info("Module loaded!"); // The code is executed immediately upon import, which may cause side effects.
export const data = 1;

// main.ets
import { data } from './module' // When data is imported, the console.info file in module.ets is executed and output is generated.
console.info("data is ", data);
```

The output is as follows:

```typescript
Module loaded!
1
```

**Side effects produced**

Even though only **data** is required, **console.info("Module loaded!")** still runs, causing the unexpected output of "Module loaded!" in addition to the value of **data**.

**Optimized methods**

Optimization method 1: Remove the top-level code and export only the required content to avoid unnecessary code execution.

```typescript
// module.ets
export const data = 1;

// main.ets
import { data } from './module'
console.info("data is ", data);
```

The output is as follows:

```typescript
1
```

Optimization method 2: Encapsulate code that may cause side effects within functions or methods, and execute the code only when needed, rather than upon module loading.

```typescript
// module.ets
export function initialize() {
    console.info("Module loaded!");
}
export const data = 1;

// main.ets
import { data } from './module'
console.info("data is ", data);
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
    console.info("data1 is ", data1);
    console.info("globalThis.someGlobalVar is ", globalThis.someGlobalVar); // The value of someGlobalVar is changed to 200 because the sideEffectModule module is loaded to main.ets.
}

// main.ets (entry point)
import { data1 } from "./module" // The value of the global variable someGlobalVar is changed to 100.
import { data2 } from "./sideEffectModule" // The value of the global variable someGlobalVar is changed to 200.
import { useGlobalVar } from './moduleUseGlobalVar'

useGlobalVar();
function maybeNotCalledAtAll() {
    console.info("data1 is ", data1);
    console.info("data2 is ", data2);
}
```

The output is as follows:

```text
data from module
200
```

**Side effects produced**

Modules directly change the value of the **global variable globalThis.someGlobalVar**, affecting other modules or code that depends on this variable.

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
    console.info("data1 is ", data1);
    changeGlobalVar(); // Execute the code when needed, not upon module loading.
    console.info("globalThis.someGlobalVar is ", globalThis.someGlobalVar);
}

// main.ets (entry point)
import { data1 } from "./module"
import { data2 } from "./sideEffectModule"
import { useGlobalVar } from './moduleUseGlobalVar'

useGlobalVar();
function maybeNotCalledAtAll() {
    console.info("data1 is ", data1);
    console.info("data2 is ", data2);
}
```

The output is as follows:

```text
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
    console.info("data is ", data);
}
```

The following content is displayed:

```text
test200
```

**Side effects produced**

Modules directly change the value of **SomeAppStorageVar** in AppStorage, affecting other modules or code that depends on this variable.

For more information on modifying ArkUI component state variables, see [State Management Overview](../ui/state-management/arkts-state-management-overview.md).

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
    console.info("data is ", data);
}
```

The following content is displayed:

```text
test100
```

### Modifying Built-in Global Variables or Prototype Chains (Modifying Object Prototypes or Built-in Methods Is Forbidden in ArkTS)

**Scenario of side effects**

To support modern JavaScript features in old browsers or runtime environments, third-party libraries or frameworks may modify built-in global objects or prototype chains. This can affect the execution of other code.

```typescript
// modifyPrototype.ts
export let data = "data from modifyPrototype"
Array.prototype.includes = function (value) {
    return this.indexOf(value) !== -1;
};

// main.ets
import { data } from "./modifyPrototype" // The prototype chain of the array is modified.
let arr = [1, 2, 3, 4];
console.info("arr.includes(1) = " + arr.includes(1)); // The Array.prototype.includes method in modifyPrototype.ts is called.
function maybeNotCalledAtAll() {
    console.info("data is ", data);
}
```

**Side effects produced**

Modifying built-in global objects or prototype chains may affect the execution of other code.

**Optimized methods**

When importing third-party libraries that may modify built-in global objects or prototype chains, ensure that the behavior of the third-party library is as expected.

### Circular Dependencies

**Scenario of side effects**

ArkTS modularization supports circular dependencies, where module A depends on module B, and module B depends on module A. In such cases, some imported modules may not be fully loaded, leading to abnormal behavior and unintended side effects during execution.

```typescript
// a.ets
import { b } from "./b"
console.info('Module A: ', b);
export const a = 'A';

// b.ets
import { a } from "./a"
console.info('Module B: ', a);
export const b = 'B';
```

The output is as follows:

```text
Error message: a is not initialized
Stacktrace:
    at func_main_0 (b.ets:2:27)
```

**Side effects produced**

Due to mutual dependencies between modules, the execution order of modules may result in undefined exports, affecting the logic flow of the code. The specific error message is "Variable name is not initialized."

**Optimized methods**

Avoid circular dependencies between modules whenever possible, and ensure that the loading order of modules is clear and controllable to prevent unexpected side effects. You can use [@security/no-cycle](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide_no-cycle) when detecting circular dependencies.

### Lazy Import Changing the Module Execution Sequence and Leading to Undefined Global Variables

**Scenario of side effects**

The [Lazy Import](arkts-lazy-import.md) feature allows modules to be loaded on-demand during the application runtime, rather than during the cold start phase, thereby reducing the cold start time. However, this also changes the execution sequence of modules.

```typescript
// module.ets
export let data = "data from module"
globalThis.someGlobalVar = 100;

// moduleUseGlobalVar.ets
import lazy { data } from "./module"
console.info("globalThis.someGlobalVar", globalThis.someGlobalVar); // The module is not executed due to lazy import. The value of someGlobalVar is undefined.
console.info("data is ", data); // During the use of the variable, the module is executed and the value of someGlobalVar changes to 100.
```

The output is as follows:

```text
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
console.info("globalThis.someGlobalVar is ", globalThis.someGlobalVar); // someGlobalVar will have the expected value.
console.info("data is ", data);
```

The output is as follows:

```text
100
data from module
```

## Optimizing Performance with import Path Expansion

### Working Principle

In import statements, skipping intermediate dependency paths and directly importing the module corresponding to the variable is known as import path expansion.

The following example illustrates the principle of optimizing performance with import path expansion:

```typescript
// main.ets
import * as har from "har"
console.info("har.One is ", har.One); // The One variable is exported from har/src/main/ets/NumberString.ets.

// har/Index.ets
export * from "./src/main/ets/OtherModule1"
export * from "./src/main/ets/OtherModule2"
export * from "./src/main/ets/Utils"
console.info("har Index.ets execute.");

// har/src/main/ets/Utils.ets
export * from "./OtherModule3"
export * from "./OtherModule4"
export * from "./NumberString"
console.info("har Utils.ets execute.");

// har/src/main/ets/NumberString.ets
export const One: string = "1";
console.info("har NumberString.ets execute.");
```

1. If **main.ets** depends only on the NumberString module in the HAR, the import statement **import xxx from "har"** will cause all modules along the entire chain of the HAR to be parsed and executed, increasing the time spent on module parsing and execution. In the example above, the modules har/Index, OtherModule1, OtherModule2, Utils, OtherModule3, OtherModule4, and NumberString will all be parsed and executed.

2. During module parsing, a depth-first traversal approach is used to establish the binding relationships between variables. The **har.One** variable used in **main.ets** is exported from **har/src/main/ets/NumberString.ets**. However, due to the use of export *, establishing the binding relationships requires recursively matching variable names, which increases the time spent on module parsing.
In the example above, the **har/Index.ets** file is checked first. This file contains multiple export * statements, so it sequentially checks whether OtherModule1 and OtherModule2 export the **One** variable. Then, it finds the Utils module, which also has export * statements, so it continues to check OtherModule3 and OtherModule4, ultimately determining that the **One** variable is exported from the NumberString module.

Optimization methods: Modify the code as follows to skip intermediate dependency paths and directly import the module corresponding to the variable.

```typescript
// main.ets
import { One } from "har/src/main/ets/NumberString"
console.info("One is ", One);

// har/src/main/ets/NumberString.ets
export const One: string = "1";
console.info("har NumberString.ets execute.");
```

### Side Effects

**Scenario of side effects**

Import path expansion skips the execution of intermediate modules. If the service logic depends on the order of module execution, modifications might lead to service exceptions.

```typescript
// main.ets
import { serviceManager } from "har"

serviceManager.print();

// har/Index.ets
import { serviceManager } from "./src/main/ets/ServiceManager"

serviceManager.init();
export { serviceManager }

// har/src/main/ets/ServiceManager.ets
class ServiceManager {
    public inited: boolean = false;
    
    public init() {
        this.inited = true;
    }
    public print() {
        if (this.inited) {
            console.info("ServiceManager is inited.");
        } else {
            console.error("ServiceManager is not inited.");
        }
    }
}
export let serviceManager: ServiceManager = new ServiceManager();
```

The output at runtime is as follows:

```text
ServiceManager is inited.
```

If import path expansion is used, the code becomes:

```typescript
// main.ets
import { serviceManager } from "har/src/main/ets/ServiceManager"

serviceManager.print();

// har/src/main/ets/ServiceManager.ets
class ServiceManager {
    public inited: boolean = false;

    public init() {
        this.inited = true;
    }
    public print() {
        if (this.inited) {
            console.info("ServiceManager is inited.");
        } else {
            console.error("ServiceManager is not inited.");
        }
    }
}
export let serviceManager: ServiceManager = new ServiceManager();
```

The output at runtime is as follows:

```text
ServiceManager is not inited.
```

**Side effects produced**

The har/Index module contains top-level code for initializing ServiceManager. If import path expansion is performed in the main module, the har/Index module will not be executed, and ServiceManager will not be initialized, potentially leading to service exceptions.

**Optimized methods**

You need to check the impact of skipping the execution of the top-level code based on service requirements and make modifications accordingly.

For the example above, the following modifications can be made:

```typescript
// main.ets
import { serviceManager } from "har/src/main/ets/ServiceManager"

serviceManager.print();

// har/src/main/ets/ServiceManager.ets
class ServiceManager {
    public inited: boolean = false;

    public init() {
        this.inited = true;
    }
    public print() {
        if (this.inited) {
            console.info("ServiceManager is inited.");
        } else {
            console.error("ServiceManager is not inited.");
        }
    }
}
export let serviceManager: ServiceManager = new ServiceManager();
// Execute the corresponding logic in the exported module.
serviceManager.init();
```
