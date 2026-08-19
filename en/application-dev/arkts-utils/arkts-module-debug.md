# Modularization Debugging Tools

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @yao_dashuai-->
<!--Designer: @yao_dashuai-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=8f600946c32961530dbc1a2657e44e724c33ffe4 translatedAt=2026-08-18T01:32:46.485Z pushedAt=2026-08-18T09:35:38.404Z -->

The ArkTS runtime provides a variety of modularization debugging tools to help developers quickly locate and resolve modularization-related issues.

| Tool Name | Main Function | Applicable Scenarios | API Version |
|---------|---------|---------|---------|
| [Module Loading Trace Debugging Tool](#module-loading-trace-debugging-tool)| Detects circular dependencies and records module loading paths | Circular dependency issues, module loading path analysis |26.0.0|
| [Modular Trace Instrumentation Tool](#modular-trace-instrumentation-tool) | Analyzes module performance and collects usage statistics | Performance analysis, performance optimization |26.0.0|

## Module Loading Trace Debugging Tool

When an app crashes due to an exception during the module loading phase, or when developers want to obtain the module call trace, they can use this feature to quickly locate the problematic module and its call path. It is especially suitable for fault diagnosis in multi-level nested import scenarios.

### Enabling and Disabling

Enabling the tool: When a JsCrash or CppCrash occurs during the module loading phase of an app, you can enable this feature. Once enabled, the crash log records the complete module loading trace, helping you locate the source of the problem.

```bash
# Enable the module loading trace debugging feature.
hdc shell param set persist.ark.properties 0x40000105c
```

Disabling the tool: This feature continuously records module loading information, which incurs a certain runtime performance overhead. Therefore, after the issue is located and fixed, disable it immediately to avoid affecting the normal running performance of the app.

```bash
# Disable the module loading trace debugging feature.
hdc shell param set persist.ark.properties 0x0000105c
```

### Stack Data Format

After the module loading trace debugging feature is enabled, the module loading trace information is displayed in JsCrash and CppCrash crash logs.

**JsCrash log example:**

After the module loading trace debugging feature is enabled, the `ModuleImportStack` field is added to the JsCrash crash log.

```text
...
Stacktrace:
    at anonymous entry (entry/src/main/ets/pages/Index.ets:7:13)
HybridStack:
...
AsyncStack:
...
ModuleImportStack:
#0 entry/src/main/ets/pages/Index.ets
#1 entry/src/main/ets/utils/Helper.ets
#2 entry/src/main/ets/core/Core.ets

HiLog:
...
```

**CppCrash log example:**

After the Module Loading Trace Debugging feature is enabled, the module call chain is displayed in the LastFatalMessage field of the CppCrash crash log.

```text
...
LastFatalMessage:Failed to load &entry/src/main/ets/pages/A&, the dependency import call stack is as follows
#0 &entry/src/main/ets/pages/A&
#1 &entry/src/main/ets/pages/Index&
Fault thread info:
...
```

> **NOTE**
> 
> The Module Loading Trace Debugging feature prints a maximum of 64 KB of content. For scenarios with deep nesting, CppCrash and JsCrash omit the intermediate stack frames.

```text
ModuleImportStack:
#000 entry/src/main/ets/pages/Index.ets
#001 entry/src/main/ets/utils/Helper.ets
...
#999 entry/src/main/ets/deep/Module99.ets
```

### Using JsCrash to Trace the Module Loading Path

To quickly locate the module import chain that causes a problem, developers can throw a JsError at the top level of the problematic module. For example, after throwing an exception at the top level of module B, developers can view the module loading chain when they enable the tool and reproduce the scenario.

```js
// entry/src/main/ets/pages/Index.ets
import { A } from './A'

A()
```

```js
// entry/src/main/ets/pages/A.ets
import { b } from "./B"

export function A(){
  return b + 2;
}
```

```js
// entry/src/main/ets/pages/B.ets
// Throw the exception at the top level, not inside a function.
throw new Error("ModuleImportStack test")
export const b = 1;
```

Example output:

```text
ModuleImportStack:
#0 &entry/src/main/ets/pages/B&
#1 &entry/src/main/ets/pages/A&
#2 &entry/src/main/ets/pages/Index&
```

### Tracing the ETS Import Source of a Shared Object (.so) Module

To quickly locate the loading trace of the shared object (.so) module that causes the problem, developers can throw a CppCrash in the napi_init of the problematic .so module. For example, dereference a null pointer in napi_init.cpp to trigger a CppCrash. After enabling the tool and reproducing the scenario, developers can see from which ETS file the libentry.so module is imported.

```js
// entry/src/main/ets/pages/Index.ets
import { a } from './A'
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;
hilog.info(DOMAIN, 'testTag', 'ModuleImportStack test a = %{public}d', a);
```

```js
// entry/src/main/ets/pages/A.ets
import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';

const DOMAIN = 0x0000;
hilog.info(DOMAIN, 'testTag', 'Test NAPI 2 + 3 = %{public}d', testNapi.add(2, 3));
export const a = 1;
```

```cpp
// entry/src/main/cpp/napi_init.cpp
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr }
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    // Throw a null pointer to trigger CppCrash in the file where the call trace needs to be known.
    int *p = nullptr;
    *p = 42;
    return exports;
}
EXTERN_C_END
```

Example output:

```text
LastFatalMessage:Failed to load &entry/src/main/ets/pages/A&, the dependency import call stack is as follows
#0 &entry/src/main/ets/pages/A&
#1 &entry/src/main/ets/pages/Index&
```  

## Modular Trace Instrumentation Tool

Developers can use this switch when they need to analyze the performance of file loading scenarios.

### How to Use

Enabling and disabling the tool: When an app needs to analyze file loading performance, you can enable this feature. After it is enabled, the captured trace data displays modular instrumentation, which helps analyze performance issues. This feature continuously instruments modules and causes a certain performance overhead at runtime. Therefore, you can disable it after capturing the trace to avoid affecting the normal running performance of the app.

```bash
# Enable the modular instrumentation feature.
hdc shell param set persist.ark.properties 0x100105c
# Disable the modular instrumentation feature.
hdc shell param set persist.ark.properties 0x000105c
```

Use HiSmartPerf to capture traces:  

> **NOTE**
>
> HiSmartPerf is a standalone performance tuning tool used to collect system, CPU, and GPU performance data during a test period. It presents the data through a visual interface, making it easier for developers to analyze the runtime performance of the app under development and identify the causes, so that they can perform in-depth performance optimization and make the app run more smoothly.
>
> For a complete introduction to HiSmartPerf, see the guide: [HiSmartPerf].

1. Enter CPU Trace.

   Open the HiSmartPerf tool and go to the CPU Trace page for game performance analysis. Although the page is titled game performance analysis, the analysis scenarios are not limited to game scenarios.
  

2. Configure the collection duration and start collection.

   After collection is complete, you will be prompted to transfer the file back. Please wait patiently if the file is large.


3. Open the trace file and select the app to view.


### Trace File Analysis

The instantiated files and shared object (.so) modules are under SourceTextModule::Instantiate.


The executed files and shared object (.so) modules are under SourceTextModule::Evaluate.


After you select the area to analyze, a table is generated below. You can use the table data to optimize the performance of files that take a long time.
