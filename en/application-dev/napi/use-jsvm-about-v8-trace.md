# Using HiSmartPerf to Collect V8 Trace Data
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## Overview

V8 trace is a tool provided by the V8 engine for analyzing and debugging the execution process of JavaScript code. It records and outputs detailed information about code execution, including function calls, execution time, and memory usage, helping developers understand code performance, diagnose potential problems, and optimize code.

Currently, HiSmartPerf has been interconnected with the trace points of the compile, runtime, builtin, and JS_Execution types in V8. You can directly view the information about these types of events in HiSmartPerf.

## Usage

### Default State
In V8, whether to collect trace data is controlled by the web.debug.rcs switch. By default, this switch is disabled. In the web scenario, the "RCS is off" log is printed in the hilog.

### Collecting V8 Trace Information
1. To collect V8 trace data, enable web.debug.rcs before starting the web scenario. Before starting the web scenario, run the following command:

``` shell
hdc shell setenforce 0
hdc shell param set web.debug.rcs true
```
2. In the web scenario, "RCS is on" is displayed in the hilog file.
3. Use the hitrace tool to capture traces in the corresponding scenario. For details about how to use the hitrace tool, see the [hitrace](../dfx/hitrace.md) user guide.
4. Use the HiSmartPerf tool to parse the captured trace. The trace points with the prefix RCS_ are the trace points connected to HiSmartPerf in V8.
5. To view the trace data of compile, runtime, builtin, and JS_Execution, use the following keywords to filter the data:
- compile: RCS_v8.compile
- runtime: RCS_V8.Runtime
- Builtin: RCS_v8.runtime_V8.Builtin
- JS_Execution: RCS_JS_Execution
