# Lazy Import

With the continuous expansion of application features, the time required for cold start increases significantly. The main reason is that a large number of modules are loaded at the early stage of startup, and a large number of redundant files that are not actually executed exist. In this case, not only an initialization process of the application is delayed, but also invalid resource occupation is caused. Therefore, measures urgently need to be taken to simplify a loading process and eliminate unnecessary file execution, to optimize cold start performance and ensure smooth user experience.

> **Note**
> 
> - The lazy import is supported since API version 12.
>
> - To use the lazy import syntax on API version 12, you need to configure **"compatibleSdkVersionStage": "beta3"** in the project. Otherwise, the compilation fails. For details, see [DevEco Studio build-profile.json5 File Description](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-hvigor-build-profile-V5#section511142752919).


## **Functions and Features**

With the lazy import, unnecessary files are not loaded in the cold start phase until these files are required during application running, shortening the time required for cold start.

## Storage mode

You can use<!--Del-->[<!--DelEnd-->Trace<!--Del-->](../performance/common-trace-using-instructions.md)<!--DelEnd--> tools or logs to identify files that are not actually called during cold start. By analyzing the data, you can accurately locate the files that do not need to be pre-loaded in the startup phase, and add the **lazy** identifier for the invoking points of these files. Notice that subsequent synchronous loading may block the task execution. (If a task is clicked and lazy import is triggered, the files that are not loaded will be executed in cold start, which increases the time consumption. Therefore, you need to evaluate whether to use the **lazy** identifier.

> **NOTE**
>
> You are not advised to blindly add **lazy** identifiers, which also increases the identification overhead during building and running.
    
## Scenario Behavior Analysis

- Use lazy import.

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

- Reference lazy import and native import for the same module at the same time.

    ```typescript    
        // main.ets   
        import lazy { a } from "./mod1";    // "mod1" is not executed.
        import { c } from "./mod2";         // "mod2" is executed.
        import { c } from "./mod2";         // "mod1" is executed.
        
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
    
    If the keyword **lazy** is deleted from **main.ets** file, the execution sequence is as follows:
    
    ```typescript  
        mod1 a executed
        mod1 b executed
        mod2 c executed
        main executed
    ```

## Specifications

- Lazy import supports the following instructions:

| Syntax                              | ModuleRequest | ImportName  | LocalName   | Supported by API Version 12   |
| :--------------------------------- | :------------ | :---------- | :---------- | :------------------- |
| import lazy { x } from "mod";        | "mod"         | "x"         | "x"         | Yes                 |
| import lazy { x as v } from "mod";   | "mod"         | "x"         | "v"         | Yes.                 |

- The shared module is lazy imported or the dependency path contains the shared module.
    Lazy import still takes effect for the shared module. For details about the constraints, see [Shared Module Development](../arkts-utils/arkts-sendable-module.md).

### [Incorrect Example]

Build error is reported if use the following syntax:

```typescript
    export lazy var v;                  // The compiler reports an application compilation error.
    export lazy default function f(){}; // The compiler reports an application compilation error.
    export lazy default function(){};   // The compiler reports an application compilation error.
    export lazy default 42;             // The compiler reports an application compilation error.
    export lazy { x };                    // The compiler reports an application compilation error.
    export lazy { x as v };               // The compiler reports an application compilation error.
    export lazy { x } from "mod";         // The compiler reports an application compilation error.
    export lazy { x as v } from "mod";    // The compiler reports an application compilation error.
    export lazy * from "mod";           // The compiler reports an application compilation error.
    
    import lazy v from "mod";           // The compiler reports an application compilation error.
    import lazy * as ns from "mod";     // The compiler reports an application compilation error.

```

If the **type** keyword is added to the syntax, an error is reported.

```typescript    
    import lazy type { obj } from "./mod";    // Not supported. The compiler reports an application compilation error.
    import type lazy { obj } from "./mod";    // Not supported. The compiler reports an application compilation error.

```

### Syntax Not Recommended

- In the same ets file, not all the dependency modules that require the lazy import are added lazy identifiers.
    
    Incomplete labeling will cause lazy loading to fail and increase the overhead of identifying lazy loading.
    ```typescript
        // main.ets   
        import lazy { a } from "./mod1";    // Obtain the object a from "mod1" and add a lazy identifier.
        import { c } from "./mod2";
        import { b } from "./mod1";         // Obtain the attributes in "mod1". This syntax is not added a lazy identifier, so "mod1" is executed by default.
        
        // ...
    ```
- In the same ETS file, lazy loading variables are not used and exported again. Lazy loading variables cannot be exported by re-export.
    
    The variable c exported in this mode is not used in B.ets, and the B.ets file is not executed. When variable a is used in the A.ets file, the variable is not initialized and a JS exception is thrown.
    ```typescript
        // A.ets
        import { c } from "./B";
        console.info(c);

        // B.ets
        import lazy { a } from "./mod1";    // Obtain the object a from "mod1" and add a lazy identifier.
        export { c }

        // C.ets
        function c(){};
        export { c }
    ```
    The execution result is as follows:
    ```typescript
        ReferenceError: a is not initaliized
             at func_main_0 (A.ets:2:1)
    ```

    ```typescript
        // A_ns.ets
        import * as ns from "./B";
        console.info(ns.c);

        // B.ets
        import lazy { a } from "./mod1";    // Obtain the object a from "mod1" and add a lazy identifier.
        export { c }

        // C.ets
        function c(){};
        export { c }
    ```
    The execution result is as follows:
    ```typescript
    ReferenceError: module environment is undefined
        at func_main_0 (A_ns.js:2:1)
    ```

- Currently, lazy import cannot be executed in kit.

- Developers need to evaluate the impact of lazy loading.
    * Side-effects that do not depend on the module (such as initializing global variables and mounting globalThis)
    * When objects are exported, time required for the lazy import deteriorates corresponding features.
    * Bugs occur when the **lazy** identifier is used but the module is not executed.
