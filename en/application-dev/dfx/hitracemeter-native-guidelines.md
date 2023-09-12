# Development of Performance Tracing (Native)

## Overview

hiTraceMeter provides APIs for system performance tracing. You can call the APIs provided by the hiTraceMeter module in your own service logic to effectively track service processes and check the system performance.

> **NOTE**
> - This development guide is applicable only when you use Native APIs for application development. For details about APIs, see [API Reference](../reference/native-apis/_hitrace.md).
> - For details about how to use ArkTS APIs for application development, see [Development Guidelines](hitracemeter-guidelines.md) and [API Reference](../reference/apis/js-apis-hitracemeter.md).

## Available APIs

| API| Description|
| -------- | -------- |
| void OH_HiTrace_StartTrace(const char* name) | Starts a synchronous time slice trace.|
| void OH_HiTrace_FinishTrace() | Ends a synchronous time slice trace.|
| void OH_HiTrace_StartAsyncTrace(const char* name, int32_t taskId) | Starts an asynchronous time slice trace.|
| void OH_HiTrace_FinishAsyncTrace(const char* name, int32_t taskId) | Ends an asynchronous time slice trace.|
| void OH_HiTrace_CountTrace(const char* name, int64_t count) | Performs an integer trace.|

**Parameter Description**

| Name| Type| Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | No  | Name of the variable.|
| taskId | number | No  | ID used to indicate the association of APIs in a trace. If multiple traces with the same name need to be performed at the same time or a trace needs to be performed multiple times concurrently, different task IDs must be specified in **startTrace**.|
| count  | number | No  | Value of the variable. |

## Development Example

1. Add the link of **libhitrace_ndk.z.so** to **CMakeLists.txt**.
  ```
  target_link_libraries(entry PUBLIC libhitrace_ndk.z.so)
  ```
2. Reference the **hitrace** header file in the source file.
  ```c++
  #include "hitrace/trace.h"
  ```
3. Open the hdc shell and run the **hitrace --trace_begin app** command to enable the trace function.
  ```shell
  capturing trace...
  ```
4. Perform a performance trace. The following uses asynchronous trace as an example.
  ```c++
  OH_HiTrace_StartAsyncTrace("hitraceTest", 123);
  OH_HiTrace_FinishAsyncTrace("hitraceTest", 123);
  ```
5. Run the **hitrace --trace_dump | grep hitraceTest** command to view the trace result.
  ```shell
  <...>-2477    (-------) [001] ....   396.427165: tracing_mark_write: S|2477|H:hitraceTest 123
  <...>-2477    (-------) [001] ....   396.427196: tracing_mark_write: F|2477|H:hitraceTest 123
  ```
