# Lazy Import

As applications evolve with more features, the time required for cold start increases significantly. The main reason is that numerous modules that are not actually executed are loaded during the initial startup. This not only prolongs application initialization but also leads to invalid resource utilization. To address this, it is crucial to streamline the loading process by eliminating non-essential file executions to optimize cold start performance and ensure a smooth user experience.

> **NOTE**
> 
> - The lazy import feature is supported since API version 12.
>
> - To use the lazy import syntax on API version 12, you must configure **"compatibleSdkVersionStage": "beta3"** in the project. Otherwise, the compilation fails. For details, see [Project-level build-profile.json5 File](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-hvigor-build-profile-V5#section511142752919).
> - For projects with API versions later than 12, you can directly use the **lazy import** syntax without any other configuration.


## Features

The lazy import feature prevents files from being loaded during the cold start phase. Instead, they are loaded on demand as the program runs, which helps to reduce cold start time.

## Usage

You can use <!--Del-->[<!--DelEnd-->Trace<!--Del-->](../performance/common-trace-using-instructions.md)<!--DelEnd--> or logs to identify files that are not actually called during cold start.<!--RP1--> For details about the analysis method, see [Lazy Import](../performance/Lazy-Import-Instructions.md).<!--RP1End--> By analyzing the data, you can accurately identify the list of files that do not need to be preloaded during startup and add **lazy** tags at the call points of these files. However, it is important to note that subsequent loading is synchronous and may block task execution. (For example, if a click task triggers a lazy import, the runtime will execute the files not loaded during the cold start, thereby increasing latency.) Therefore, you need to evaluate whether to use the **lazy** flag.

> **NOTE**
>
> You are not advised to blindly add **lazy** flags, as this can also increase the overhead of identification during compilation and runtime.

## Scenario Behavior Analysis

- Use lazy-import for deferred loading.

    ```typescript    
        // main.ets   
        import lazy { a } from "./mod1";    // "mod1" is not executed.
        import { c } from "./mod2";         // "mod2" is executed.
        
        // ...
        
        console.info("main executed");
        while (false) {
            let xx = a;
        }
        
        // mod1.ets
        export let a = "mod1 executed"
        console.info(a);
        
        // mod2.ets
        export let c = "mod2 executed"
        console.info(c);

    ```
    
    The execution result is as follows:
    
    ```typescript    
        mod2 executed
        main executed
    ```

- Use both lazy-import and native import for the same module.

    ```typescript    
        // main.ets   
        import lazy { a } from "./mod1";    // "mod1" is not executed.
        import { c } from "./mod2";         // "mod2" is executed.
        import { b } from "./mod1";         // "mod1" is executed.
        
        // ...
        
        console.info("main executed");
        while (false) {
            let xx = a;
        }
        
        // mod1.ets
        export let a = "mod1 a executed"
        console.info(a);
        
        export let b = "mod1 b executed"
        console.info(b);
        
        // mod2.ets
        export let c = "mod2 c executed"
        console.info(c);

    ```

    The execution result is as follows:
    
    ```typescript  
        mod2 c executed
        mod1 a executed
        mod1 b executed
        main executed
    ```
    
    If the keyword **lazy** is deleted from the **main.ets** file, the execution sequence is as follows:
    
    ```typescript  
        mod1 a executed
        mod1 b executed
        mod2 c executed
        main executed
    ```

## Syntax Specifications and Supported Versions

- The lazy import feature supports the following syntax:

| Syntax                                           | ModuleRequest  | ImportName | LocalName   | Supported API Version|
|:----------------------------------------------|:---------------|:-----------|:------------|:-----------|
| import lazy { x } from "mod";                 | "mod"          | "x"        | "x"         | API 12      |
| import lazy { x as v } from "mod";            | "mod"          | "x"        | "v"         | API 12      |
| import lazy x from "mod";                     | "mod"          | "default"  | "x"         | API 18      |
| import lazy { KitClass } from "@kit.SomeKit"; | "@kit.SomeKit" | "KitClass" | "KitClass"  | API 18      |

- Lazy importing of shared modules or modules within a dependency path that includes shared modules
    Lazy import remains effective for shared modules. For details about the constraints, see [Shared Module](../arkts-utils/arkts-sendable-module.md).

### Incorrect Example

The following syntax will cause compilation errors:

```typescript
    export lazy var v;                    // The compiler reports an application compilation error.
    export lazy default function f(){};   // The compiler reports an application compilation error.
    export lazy default function(){};     // The compiler reports an application compilation error.
    export lazy default 42;               // The compiler reports an application compilation error.
    export lazy { x };                    // The compiler reports an application compilation error.
    export lazy { x as v };               // The compiler reports an application compilation error.
    export lazy { x } from "mod";         // The compiler reports an application compilation error.
    export lazy { x as v } from "mod";    // The compiler reports an application compilation error.
    export lazy * from "mod";             // The compiler reports an application compilation error.

    import lazy * as ns from "mod";            // The compiler reports an application compilation error.
    import lazy KitClass from "@kit.SomeKit"   // The compiler reports an application compilation error.
    impott lazy * as MyKit from "@kit.SomeKit" // The compiler reports an application compilation error.
```

If the **type** keyword is added to the syntax, a compilation error is reported.

```typescript    
    import lazy type { obj } from "./mod";    // Not supported. The compiler reports an application compilation error.
    import type lazy { obj } from "./mod";    // Not supported. The compiler reports an application compilation error.

```

### Syntax Not Recommended

- In the same .ets file, the expected lazy-loaded dependency modules are not fully marked.
    
    Incomplete marking will cause lazy loading to fail and increase the overhead of identifying lazy-loaded modules.
    ```typescript
        // main.ets   
        import lazy { a } from "./mod1";    // Obtain the object a from "mod1" and add the lazy flag.
        import { c } from "./mod2";
        import { b } from "./mod1";         // Obtain the attributes in "mod1". This syntax is not added with the lazy flag, so "mod1" is executed by default.
        
        // ...
    ```
- In the same.ets file, re-exporting unused lazy-loaded variables is not supported. To identify and resolve such issues, you can enable the **reExportCheckMode** switch in the project-level **build-profile.json5** file to perform a scan and check.
    ```typescript
        // build-profile.json5
        "arkOptions":{
            "reExportCheckMode":"compatible"
        }
    ```

    > **NOTE**
    >
    > - For the following scenario, whether to intercept and report errors during compilation: Variables imported using lazy import are re-exported within the same file.
    > - **noCheck** (default value): No check is performed, and no error is reported.
    > - **compatible**: A warning is reported.
    > - **strict**: An error is reported.
    > - This field is supported since DevEco Studio 5.0.13.200.

    The variable **c** is not used in **B.ets**, so **B.ets** does not trigger execution. When **c** is used in **A.ets**, it is not initialized, resulting in a JavaScript exception.
    ```typescript
        // A.ets
        import { c } from "./B";
        console.info(c);

        // B.ets
        import lazy { c } from "./C";    // Obtain the object c from "C" and add the lazy flag.
        export { c }

        // C.ets
        let c = "c";
        export { c }
    ```
    Result:
    ```typescript
        ReferenceError: c is not initialized
             at func_main_0 (A.ets:2:13)
    ```

    ```typescript
        // A_ns.ets
        import * as ns from "./B";
        console.info(ns.c);

        // B.ets
        import lazy { c } from "./C";    // Obtain the object c from "C" and add the lazy flag.
        export { c }

        // C.ets
        let c = "c";
        export { c }
    ```
    Result:
    ```typescript
    ReferenceError: module environment is undefined
        at func_main_0 (A_ns.js:2:13)
    ```

- You need to evaluate the possible impact of lazy imports.

  - Side effects that are independent of the module's execution (such as initializing global variables and mounting **globalThis**). For details, see [Side Effects and Optimization of Module Loading](./arkts-module-side-effects.md).
  - Negative impact on the functionality of features due to the delay caused by triggering lazy imports when using exported objects.
  - Using the lazy import feature can cause modules to not execute, thereby triggering bugs.

<!--no_check-->