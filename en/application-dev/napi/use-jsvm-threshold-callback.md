# Using JSVM-API to Obtain Heap Snapshots and Monitor Heap Memory Thresholds

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @pennyatmosphere; @sunzibo-->
<!--Designer: @pennyatmosphere-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=21434ce8d323ecbd7d67463989a2ef075be92cec translatedAt=2026-08-12T06:37:04.231Z pushedAt=2026-08-12T11:04:52.356Z -->

## Overview

Starting from API version 26.0.0, JSVM-API provides core capabilities for heap memory management, including two key types of APIs: **obtaining raw heap snapshots** and **monitoring heap memory thresholds**:

- `OH_JSVM_TakeRawHeapSnapshot`: Obtains the raw heap snapshot (in binary format) of the current JS virtual machine (VM) and outputs it to a specified stream. It can be used for heap memory analysis, memory leak detection, debugging, and other scenarios.

- `OH_JSVM_SetHeapThresholdCallback`: Registers a heap memory threshold callback for a VM. The callback is automatically triggered when the heap memory usage reaches the specified threshold.

- `OH_JSVM_ClearHeapThresholdCallback`: Removes the registered heap memory threshold callback and releases related resources.

You can use these APIs to implement full lifecycle monitoring of heap memory, snapshot collection and analysis, helping optimize memory usage efficiency and troubleshoot memory-related issues.

## Basic Concepts

### Raw Heap Snapshot

JSVM-API provides the OH_JSVM_TakeRawHeapSnapshot interface for obtaining a raw heap snapshot of a VM. The raw heap snapshot stores the complete state of heap memory in a JSVM-specific binary format, which is bound to the specific VM implementation, and the data layout is not guaranteed to be stable across versions. The operation of obtaining a heap snapshot may briefly pause the app, and frequent calls will generate a large number of snapshot files, requiring developers to manage disk usage properly.

In addition, when snapshot data is obtained through a custom stream callback, it is **synchronously called** on the thread where the VM runs. Therefore, the callback function must avoid long blocking operations. If the callback returns `false`, the output stream will be terminated, and the snapshot generation process will also be immediately aborted.

### Heap Memory Threshold Callback

JSVM-API provides the OH_JSVM_SetHeapThresholdCallback interface to register a heap memory threshold callback function for a specified VM. A VM can have only **one** heap memory threshold callback registered at a time. The callback is uniquely identified by the combination of "threshold (in bytes) + callback function + user-defined data". When the callback is no longer needed, you must call OH_JSVM_ClearHeapThresholdCallback to unregister it.

These interfaces are not thread-safe and must be called on the thread where the VM runs. When heap memory usage reaches the specified threshold, the callback function is triggered and invoked synchronously on the same thread. Heap threshold checks are skipped during callback execution.

### Available APIs

| Name                              | Description                                                         |
| --------------------------------- | ------------------------------------------------------------------- |
| OH_JSVM_TakeRawHeapSnapshot       | Obtains the raw heap snapshot of a VM and outputs binary data through a stream callback. |
| OH_JSVM_SetHeapThresholdCallback  | Registers a heap memory threshold callback for a VM, which triggers custom logic when the threshold is reached. |
| OH_JSVM_ClearHeapThresholdCallback | Removes the registered heap memory threshold callback function from a VM. |

## Usage Example

For the JSVM-API interface development process, see [JSVM-API Development Process). This document only shows the C++ code related to the APIs.

### Sample Code for Specific Functions

This section provides sample code for the three functions: OH_JSVM_TakeRawHeapSnapshot, OH_JSVM_SetHeapThresholdCallback, and OH_JSVM_ClearHeapThresholdCallback. It covers core scenarios such as heap snapshot collection, heap threshold callback registration and removal, and edge cases (duplicate registration/removal and invalid parameters).

**C++ Code**

 <!-- @[oh_jsvm_take_raw_heap_snapshot](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmUsageGuide/JsvmAboutRawheap/entry/src/main/cpp/hello.cpp) -->    

 ``` C++
 #include <iostream>
 #include <fstream>
 #include <thread>
 #include <chrono>
 #include <unistd.h>
 #include <sys/types.h>
 #include "napi/native_api.h"
 #include "hilog/log.h"
 #include "ark_runtime/jsvm.h"
 
 #define LOG_DOMAIN 0x3200
 #define LOG_TAG "APP"
 
 static int g_aa = 0;
 
 static bool g_heapThresholdCalled = false;
 static uint64_t g_triggeredThreshold = 0;
 static void* g_callbackUserData = nullptr;
 static bool g_snapshotGenerated = false;
 
 static constexpr int SLEEP_TIME_MS = 100;
 static constexpr uint64_t THRESHOLD_SIZE = 1024 * 1024;
 static constexpr int TEST_DATA_VALUE = 0x12345678;
 
 bool SnapshotStreamCallback(const char* data, int size, void* streamData)
 {
     std::FILE* file = reinterpret_cast<std::FILE*>(streamData);
     if (file) {
         size_t written = std::fwrite(data, 1, size, file);
         return written == static_cast<size_t>(size);
     }
     return true;
 }
 
 void OnHeapThresholdReached(JSVM_VM vm, uint64_t threshold, void* data)
 {
     OH_LOG_INFO(LOG_APP, "== Heap threshold reached ==");
     OH_LOG_INFO(LOG_APP, "Threshold: %{public}lu bytes", threshold);
     OH_LOG_INFO(LOG_APP, "User data: %{public}d", *static_cast<int*>(data));
 
     g_heapThresholdCalled = true;
     g_triggeredThreshold = threshold;
     g_callbackUserData = data;
 
     if (!g_snapshotGenerated) {
         g_snapshotGenerated = true;
         pid_t pid = fork();
         if (pid < 0) {
             OH_LOG_ERROR(LOG_APP, "fork failed");
         } else if (pid == 0) {
             std::FILE* file = std::fopen(
                 "/data/storage/el2/base/temp/threshold.rawheap", "wb");
             OH_JSVM_TakeRawHeapSnapshot(vm, SnapshotStreamCallback, file);
             std::fflush(file);
             fclose(file);
             _exit(0);
         }
     }
 }
 
 static void ResetTestState()
 {
     g_heapThresholdCalled = false;
     g_triggeredThreshold = 0;
     g_callbackUserData = nullptr;
     g_snapshotGenerated = false;
 }
 
 static void TestSetHeapThresholdCallback(JSVM_VM vm, uint64_t threshold, int* testData)
 {
     JSVM_Status addStatus = OH_JSVM_SetHeapThresholdCallback(
         vm, threshold, OnHeapThresholdReached, testData);
     if (addStatus == JSVM_OK) {
         OH_LOG_INFO(LOG_APP, "Set heap threshold callback success");
     }
 
     JSVM_Status addRepeatStatus = OH_JSVM_SetHeapThresholdCallback(
         vm, threshold, OnHeapThresholdReached, testData);
     if (addRepeatStatus == JSVM_INVALID_ARG) {
         OH_LOG_INFO(LOG_APP, "Set repeated callback failed (expected)");
     }
 
     JSVM_Status addInvalidStatus = OH_JSVM_SetHeapThresholdCallback(
         vm, 0, OnHeapThresholdReached, testData);
     if (addInvalidStatus == JSVM_INVALID_ARG) {
         OH_LOG_INFO(LOG_APP, "Set callback with 0 threshold failed (expected)");
     }
 }
 
 static void TestClearHeapThresholdCallback(JSVM_VM vm, uint64_t threshold, int* testData)
 {
     JSVM_Status removeStatus = OH_JSVM_ClearHeapThresholdCallback(
         vm, threshold, OnHeapThresholdReached, testData);
     if (removeStatus == JSVM_OK) {
         OH_LOG_INFO(LOG_APP, "Clear heap threshold callback success");
     }
 
     JSVM_Status removeRepeatStatus = OH_JSVM_ClearHeapThresholdCallback(
         vm, threshold, OnHeapThresholdReached, testData);
     if (removeRepeatStatus == JSVM_INVALID_ARG) {
         OH_LOG_INFO(LOG_APP, "Clear repeated callback failed (expected)");
     }
 
     JSVM_Status removeMismatchStatus = OH_JSVM_ClearHeapThresholdCallback(
         vm, 999999, OnHeapThresholdReached, testData);
     if (removeMismatchStatus == JSVM_INVALID_ARG) {
         OH_LOG_INFO(LOG_APP, "Clear mismatch threshold callback failed (expected)");
     }
 }
 
 static void RunAllocScript(JSVM_Env env)
 {
     const char* allocJs = R"JS(
         var holder = [];
         for (let i = 0; i < 10000; i++) {
             holder.push(new Uint8Array(1024));
         }
     )JS";
 
     JSVM_Value jsSrc;
     JSVM_Value result1;
     JSVM_Script script;
     OH_JSVM_CreateStringUtf8(env, allocJs, JSVM_AUTO_LENGTH, &jsSrc);
     OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script);
     OH_JSVM_RunScript(env, script, &result1);
 }
 
 static bool CheckTestResult(uint64_t threshold, int* testData)
 {
     bool testSuccess = (g_heapThresholdCalled &&
                         g_triggeredThreshold == threshold &&
                         g_callbackUserData == testData &&
                         g_snapshotGenerated);
     if (testSuccess) {
         OH_LOG_INFO(LOG_APP, "Heap management test: SUCCESS");
     } else {
         OH_LOG_ERROR(LOG_APP, "Heap management test: FAILED");
     }
     return testSuccess;
 }
 
 static JSVM_Value HeapMgmtTest(JSVM_Env env, JSVM_CallbackInfo info)
 {
     ResetTestState();
 
     JSVM_VM vm;
     OH_JSVM_GetVM(env, &vm);
     int testData = TEST_DATA_VALUE;
     uint64_t threshold = THRESHOLD_SIZE;
 
     std::FILE* file = std::fopen(
         "/data/storage/el2/base/temp/take.rawheap", "wb");
     JSVM_Status snapshotStatus = OH_JSVM_TakeRawHeapSnapshot(
         vm, SnapshotStreamCallback, file);
     if (snapshotStatus == JSVM_INVALID_ARG) {
         OH_LOG_ERROR(LOG_APP, "Take raw heap snapshot failed (invalid arg)");
     }
 
     TestSetHeapThresholdCallback(vm, threshold, &testData);
     RunAllocScript(env);
 
     OH_JSVM_MemoryPressureNotification(env, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL);
     std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME_MS));
 
     TestClearHeapThresholdCallback(vm, threshold, &testData);
 
     bool testSuccess = CheckTestResult(threshold, &testData);
 
     JSVM_Value result;
     OH_JSVM_GetBoolean(env, testSuccess, &result);
     return result;
 }
 
 static JSVM_CallbackStruct param[] = {
     {.data = nullptr, .callback = HeapMgmtTest},
 };
 
 static JSVM_CallbackStruct* method = param;
 
 static JSVM_PropertyDescriptor descriptor[] = {
     {"heapMgmtTest", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
 };
 
 const char* SRC_CALL_NATIVE = R"JS(heapMgmtTest();)JS";
 ```

**Execution Result**

The following result is output in the log, and the binary snapshot files `take.rawheap` and `threshold.rawheap` are generated:

```cpp
Set heap threshold callback success
Set repeated callback failed (expected)
Set callback with 0 threshold failed (expected)
== Heap threshold reached ==
Threshold: 1048576 bytes
User data: 305419896
Clear heap threshold callback success
Clear repeated callback failed (expected)
Clear mismatch threshold callback failed (expected)
Heap management test: SUCCESS
```

## Special Notes

1. `OH_JSVM_TakeRawHeapSnapshot`

   - If `vm` or `stream` is NULL, `JSVM_INVALID_ARG` is returned. In all other scenarios, `JSVM_OK` is returned.

   - The snapshot stream callback must avoid prolonged blocking; otherwise, the VM thread will be blocked.

   - Frequent calls generate a large number of binary files. Collect snapshots on demand and clean them up in a timely manner.

2. `OH_JSVM_SetHeapThresholdCallback`

   - The threshold must satisfy `0 < threshold ≤ heapSizeLimit` (where `heapSizeLimit` is from `JSVM_HeapStatistics`); otherwise, `JSVM_INVALID_ARG` is returned.

   - If the `vm` or `callback` parameter is NULL, `JSVM_INVALID_ARG` is returned.

   - If a callback is already registered for the VM, registering it again returns `JSVM_INVALID_ARG`.

   - This API is not thread-safe and **must** be called on the thread where the VM is running.

   - Threshold checking occurs during GC, and the callback is invoked synchronously on the same thread. Threshold checking is skipped while the callback is executing to avoid recursive triggering. If the heap usage remains at or above the threshold after the callback returns, the callback will be triggered again at the next GC without requiring re-registration.

3. `OH_JSVM_ClearHeapThresholdCallback`

   - If the `vm` or `callback` parameter is NULL, or if the (threshold + callback + user data) does not match the registered information, `JSVM_INVALID_ARG` is returned.

   - This API is not thread-safe and **must** be called on the thread where the VM is running.

   - During callback execution, the callback can remove itself and register a new threshold callback (provided that the parameters are valid).