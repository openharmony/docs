# 延迟加载（lazy import）

随着应用程序功能的扩展，冷启动时间显著增加，主要是因为启动初期加载了大量未被实际执行的模块。这种情形不仅延长了应用的初始化时间，还浪费了资源。亟需精简加载流程，剔除非必需的文件执行，优化冷启动性能，确保用户体验流畅。

> **说明：**
> 
> - 延迟加载特性在API 12版本开始支持。
>
> - 开发者如需在API 12上使用lazy import语法，需在工程中配置"compatibleSdkVersionStage": "beta3"，否则将无法通过编译。参考[DevEco Studio build-profile.json5配置文件说明](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-hvigor-build-profile-V5#section511142752919)。
> - 针对API version大于12的工程，开发者可直接使用lazy import语法，无需再进行其他配置。


## 功能特性

延迟加载特性使文件在冷启动阶段不被加载，而是在程序运行时按需加载，从而缩短冷启动时间。

## 使用方式

开发者可以利用诸如<!--Del-->[<!--DelEnd-->Trace<!--Del-->](../performance/common-trace-using-instructions.md)<!--DelEnd-->工具或日志记录等手段，识别冷启动期间未被实际调用的文件<!--RP1-->，分析方法可参考[延迟加载lazy-import使用指导](../performance/Lazy-Import-Instructions.md)<!--RP1End-->。通过对这些数据的分析，开发者可以精准定位启动阶段不必预先加载的文件列表，并在这些文件的调用点增加lazy标识。但需要注意，后续执行的加载是同步加载，可能阻塞任务执行（如单击任务，触发了延迟加载，那么运行时会去执行冷启动未加载的文件，从而增加耗时），因此是否使用lazy需要开发者自行评估。

> **说明：**
>
> 不建议盲目增加lazy，这会增加编译和运行时的识别开销。
    
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
    
如果在main.ets内删除lazy关键字，执行顺序如下：
    
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
| import lazy { x } from "mod";                 | "mod"          | "x"        | "x"         | API 12      |
| import lazy { x as v } from "mod";            | "mod"          | "x"        | "v"         | API 12      |
| import lazy x from "mod";                     | "mod"          | "default"  | "x"         | API 18      |
| import lazy { KitClass } from "@kit.SomeKit"; | "@kit.SomeKit" | "KitClass" | "KitClass"  | API 18      |

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

与type关键词同时使用会导致编译报错。

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
- 在同一ets文件中，未使用懒加载变量并再次导出，不支持延迟加载变量被re-export导出，可以通过打开工程级build-profile.json5文件中的reExportCheckMode开关进行扫描排查。
```typescript
// build-profile.json5
"arkOptions":{
    "reExportCheckMode":"compatible"
}
```

> **说明：**
>
> - 针对以下场景，编译时是否进行拦截报错：使用lazy import导入的变量，在同文件中被再次导出。
> - noCheck（缺省默认值）：不检查，不报错。
> - compatible：兼容模式，报Warning。
> - strict：严格模式，报Error。
> - 该字段从DevEco Studio 5.0.13.200版本开始支持。

这种方式导出的变量c未在B.ets中使用，因此B.ets不触发执行。在A.ets中使用变量c时，该变量未初始化，会抛出JavaScript异常。
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
执行结果：
```typescript
ReferenceError: c is not initialized
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
执行结果：
```typescript
ReferenceError: module environment is undefined
    at func_main_0 (A_ns.js:2:13)
```

### 开发者应评估使用延迟加载可能产生的影响

- 不依赖该模块执行的副作用（如初始化全局变量，挂载globalThis等）。可参考：[模块加载副作用及优化](./arkts-module-side-effects.md)。
- 使用导出对象时，触发延迟加载的耗时导致对应特性的功能劣化。
- 使用lazy特性导致模块未执行，从而引发bug。

