# 延迟加载（lazy import）

随着应用程序功能的不断扩展，冷启动所需的时间显著增长，主要是由于在启动初期加载了大量模块，其中存在大量未被实际执行的冗余文件。这种情形不仅拖延了应用的初始化过程，还造成了资源的无效占用，亟需采取措施精简加载流程，剔除非必需的文件执行，以优化冷启动性能，确保用户体验的流畅性。

> **说明：**
> 
> - 延迟加载特性在API12版本开始支持。
>
> - 开发者如需在API12上使用lazy import语法，需在工程中配置"compatibleSdkVersionStage": "beta3"，否则将无法通过编译。参考[DevEco Studio build-profile.json5配置文件说明](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-hvigor-build-profile-V5#section511142752919)。


## 功能特性

延迟加载特性可使待加载文件在冷启动阶段不被加载，直至应用程序实际运行过程中需要用到这些组件时，才按需同步加载相关文件，从而缩短应用冷启动耗时。

## 使用方式

开发者可以利用诸如<!--Del-->[<!--DelEnd-->Trace<!--Del-->](../performance/common-trace-using-instructions.md)<!--DelEnd-->工具或日志记录等手段，来识别冷启动期间未被实际调用的文件<!--RP1-->，分析方法可参考[延迟加载lazy-import使用指导](../performance/Lazy-Import-Instructions.md)<!--RP1End-->。通过对这些数据的分析，开发者能够精准地定位出启动阶段不必预先加载的文件列表。针对这些文件的调用点，可以直接增加lazy标识。但需要注意的是，后续执行的加载是同步加载，有可能会阻塞任务执行（如点击任务，触发了延迟加载，那么运行时会去执行冷启动未加载的文件，从而增加耗时），因此是否使用lazy需要开发者自行评估。

> **说明**：
>
> 不推荐开发者盲目增加lazy，同样会增大编译及运行时的识别开销。
    
## 场景行为解析

- 使用lazy-import延迟加载。

    ```typescript    
        // main.ets   
        import lazy { a } from "./mod1";    // "mod1" 未执行
        import { c } from "./mod2";         // "mod2" 执行
        
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
    
    执行结果为：
    
    ```typescript    
        mod2 executed
        main executed
    ```

- 同时对同一模块引用lazy-import与原生import。

    ```typescript    
        // main.ets   
        import lazy { a } from "./mod1";    // "mod1" 未执行
        import { c } from "./mod2";         // "mod2" 执行
        import { b } from "./mod1";         // "mod1" 执行
        
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

    执行结果为：
    
    ```typescript  
        mod2 c executed
        mod1 a executed
        mod1 b executed
        main executed
    ```
    
    如果在main.ets内删除lazy关键字，执行顺序为：
    
    ```typescript  
        mod1 a executed
        mod1 b executed
        mod2 c executed
        main executed
    ```

## 语法规格及起始支持版本

- lazy-import支持如下指令实现：

| 语法                                            | ModuleRequest  | ImportName | LocalName   | 开始支持的API版本 |
|:----------------------------------------------|:---------------|:-----------|:------------|:-----------|
| import lazy { x } from "mod";                 | "mod"          | "x"        | "x"         | API12      |
| import lazy { x as v } from "mod";            | "mod"          | "x"        | "v"         | API12      |
| import lazy x from "mod";                     | "mod"          | "default"  | "x"         | API16      |
| import lazy { KitClass } from "@kit.SomeKit"; | "@kit.SomeKit" | "KitClass" | "KitClass"  | API16      |

- 延迟加载共享模块或依赖路径内包含共享模块。
    延迟加载对于共享模块依旧生效，使用限制参考[共享模块开发指导](../arkts-utils/arkts-sendable-module.md)。

### 错误示例

以下写法将引起编译报错。

```typescript
    export lazy var v;                    // 编译器提示报错：应用编译报错
    export lazy default function f(){};   // 编译器提示报错：应用编译报错
    export lazy default function(){};     // 编译器提示报错：应用编译报错
    export lazy default 42;               // 编译器提示报错：应用编译报错
    export lazy { x };                    // 编译器提示报错：应用编译报错
    export lazy { x as v };               // 编译器提示报错：应用编译报错
    export lazy { x } from "mod";         // 编译器提示报错：应用编译报错
    export lazy { x as v } from "mod";    // 编译器提示报错：应用编译报错
    export lazy * from "mod";             // 编译器提示报错：应用编译报错

    import lazy * as ns from "mod";            // 编译器提示报错：应用编译报错
    import lazy KitClass from "@kit.SomeKit"   // 编译器提示报错：应用编译报错
    impott lazy * as MyKit from "@kit.SomeKit" // 编译器提示报错：应用编译报错
```

与type关键词同时使用将会导致报错。

```typescript    
    import lazy type { obj } from "./mod";    // 不支持，编译器、应用编译报错
    import type lazy { obj } from "./mod";    // 不支持，编译器、应用编译报错

```

### 不推荐用法 

- 在同一ets文件中，期待延迟加载的依赖模块标记不完全。
    
    标记不完全将导致延迟加载失效，并且增加识别延迟加载的开销。
    ```typescript
        // main.ets   
        import lazy { a } from "./mod1";    // 从"mod1"内获取a对象，标记为延迟加载
        import { c } from "./mod2";
        import { b } from "./mod1";         // 再次获取"mod1"内属性，未标记lazy，"mod1"默认执行
        
        // ...
    ```
- 在同一ets文件中，未使用懒加载变量并再次导出，不支持延迟加载变量被re-export导出。
    
    这种方式导出的变量c未在B.ets中使用，文件B.ets不触发执行。在文件A.ets中使用变量c时，该变量未初始化，抛js异常。
    ```typescript
        // A.ets
        import { c } from "./B";
        console.info(c);

        // B.ets
        import lazy { c } from "./C";    // 从"C"内获取c对象，标记为延迟加载
        export { c }

        // C.ets
        let c = "c";
        export { c }
    ```
    执行结果:
    ```typescript
        ReferenceError: c is not initaliized
             at func_main_0 (A.ets:2:13)
    ```

    ```typescript
        // A_ns.ets
        import * as ns from "./B";
        console.info(ns.c);

        // B.ets
        import lazy { c } from "./C";    // 从"C"内获取c对象，标记为延迟加载
        export { c }

        // C.ets
        let c = "c";
        export { c }
    ```
    执行结果:
    ```typescript
    ReferenceError: module environment is undefined
        at func_main_0 (A_ns.js:2:13)
    ```

- 开发者需要评估使用延迟加载存在的影响。
    * 不依赖该模块的执行的side-effect(如初始化全局变量，挂载globalThis等)。
    * 使用导出对象时，触发延迟加载的耗时导致对应特性的功能劣化。
    * 使用lazy特性导致模块未执行而导致的bug。

