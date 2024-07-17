# 懒加载import

应用功能持续增加，导致应用冷启动加载模块时间增加。实际冷启动过程中，执行了很多依赖到但未使用的文件，冗余文件耗时需要考虑优化。

# 功能特性

特性可使待加载文件在冷启动阶段不被加载，而在后续导出变量被真正使用时再去同步加载执行文件，缩短应用冷启动耗时。

# 使用方式

开发者可以通过[trace](../performance/common-trace-using-instructions.md)或者日志打印等方式，获取冷启动加载过程中未使用的文件，梳理出冷启动不需要加载的文件。对于这些文件的调用点，可以直接增加lazy标识。后续执行加载是同步加载，有可能会阻塞任务执行（如点击任务，触发了懒加载，那么运行时会去执行冷启动未加载的文件，从而产生耗时），是否使用lazy需要开发者自行评估。

> **说明**：
>
> 不推荐开发者盲目增加lazy，同样会增大编译及运行时的识别开销。

# 语法规格

lazy-import支持如下指令实现。

| 语法                               | ModuleRequest | ImportName  | LocalName   | 5.0是否支持lazy加载    |
| :--------------------------------- | :------------ | :---------- | :---------- | :------------------- |
| import lazy {x} from "mod";        | "mod"         | "x"         | "x"         | 支持                  |
| import lazy {x as v} from "mod";   | "mod"         | "x"         | "v"         | 支持                  |

## 错误示例

以下写法将引起编译报错。

```typescript
    export lazy var v;                  // 编译器提示报错：应用编译报错
    export lazy default function f(){}; // 编译器提示报错：应用编译报错
    export lazy default function(){};   // 编译器提示报错：应用编译报错
    export lazy default 42;             // 编译器提示报错：应用编译报错
    export lazy { x };                    // 编译器提示报错：应用编译报错
    export lazy { x as v };               // 编译器提示报错：应用编译报错
    export lazy { x } from "mod";         // 编译器提示报错：应用编译报错
    export lazy { x as v } from "mod";    // 编译器提示报错：应用编译报错
    export lazy * from "mod";           // 编译器提示报错：应用编译报错
    
    import lazy v from "mod";           // 编译器提示报错：应用编译报错
    import lazy * as ns from "mod";     // 编译器提示报错：应用编译报错

```

## 与type关键词同时使用的行为

```typescript    
    import lazy type { obj } from "./mod";    // 不支持，编译器、应用编译报错
    import type lazy { obj } from "./mod";    // 不支持，编译器、应用编译报错

```

## 不推荐用法 

- 延迟加载模块内使用TLA特性，TLA模块不会被延迟加载

    使用TLA功能的模块会被标记，并在初次遍历执行阶段加载。当lazy延迟加载的模块依赖路径内含有使用TLA模块时，延迟加载不能完全达成预期（TLA模块依旧会在初次遍历阶段执行）

- 在同一ets文件中，期待懒加载的依赖模块标记不完全
    
    标记不完全将导致延迟加载失效，并且增加识别lazy-import的开销
    ```typescript 
        // main.ets   
        import lazy { a } from "./mod1";    // 从"mod1"内获取a对象，标记为延迟加载
        import { c } from "./mod2";
        import { b } from "./mod1";         // 再次获取"mod1"内属性，未标记lazy，"mod1"默认执行
        
        // ...
    ```

- 延迟加载共享模块或依赖路径内包含共享模块

    延迟加载对于共享模块依旧生效，使用限制参考[共享模块开发指导](../arkts-utils/arkts-sendable-module.md)。
    
- 暂不支持lazy-import延迟加载kit

- 延迟加载存在的影响
    * 不依赖该模块的执行的side-effect
    * 使用导出对象时，触发延迟加载的耗时导致对应特性的功能劣化
    * 使用lazy特性导致模块未执行而导致的bug
    
    开发者需自行评估上述影响。
    
# 场景行为解析

- （1）使用lazy-import延迟加载

    ```typescript    
        // main.ets   
        import lazy { a } from "./mod1";    // "mod1" 未执行
        import { c } from "./mod2";         // "mod2" 执行
        
        // ...
        
        console.log("main executed");
        while (false) {
            let xx = a;
        }
        
        // mod1.ets
        export var a = "mod1 executed"
        console.log(a);

    ```
    
    执行结果为：
    
    ```typescript    
        main executed
    ```

- （2）同时对同一模块引用lazy-import与原生import

    ```typescript    
        // main.ets   
        import lazy { a } from "./mod1";    // "mod1" 未执行
        import { c } from "./mod2";         // "mod2" 执行
        import { b } from "./mod1";         // "mod1" 执行
        
        // ...
        
        console.log("main executed");
        while (false) {
            let xx = a;
        }
        
        // mod1.ets
        export var a = "mod1 executed"
        console.log(a);
        
        // mod1.ets
        export var b = "mod2 executed"
        console.log(b);

    ```

    执行结果为：
    
    ```typescript  
        mod2 executed
        mod1 executed
        main executed
    ```
    
    如果在mian.ets内删除lazy关键字，执行顺序为：
    
    ```typescript  
        mod1 executed
        mod2 executed
        main executed
    ```
