# 使用HiTraceChain打点（C/C++）

## 简介

HiTraceChain是基于云计算分布式跟踪调用链思想，在端侧业务流程（涉及跨线程、跨进程、跨设备）中的一种轻量级实现。HiTraceChain在业务控制面流程中，生成和传递唯一跟踪标识，在业务流程中输出的各类信息中（包括应用事件、系统时间、日志等）记录该跟踪标识。在调试、问题定位过程中，开发者可以通过该唯一跟踪标识将本次业务流程端到端的各类信息快速关联起来。HiTraceChain为开发者提供业务流程调用链跟踪的维测接口，帮助开发者迅速获取指定业务流程调用链的运行日志，定位跨设备/跨进程/跨线程的故障问题。

## 接口说明

分布式跟踪接口由HiTraceChain模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis-performance-analysis-kit/_hitrace.md)。

| 方法 | 接口描述 |
| -------- | -------- |
| HiTraceId OH_HiTrace_BeginChain(const char *name, int flags) | 开始跟踪 |
| void OH_HiTrace_EndChain() | 停止跟踪 |
| HiTraceId OH_HiTrace_GetId() | 从当前线程TLS中获取跟踪标识 |
| void OH_HiTrace_SetId(const HiTraceId *id) | 将id设置为当前线程的跟踪id |
| void OH_HiTrace_ClearId(void) | 清除当前线程的跟踪ID并将其设置为无效 |
| HiTraceId OH_HiTrace_CreateSpan(void) | 根据当前线程的跟踪id创建一个新的span id |
| void OH_HiTrace_Tracepoint(HiTrace_Communication_Mode mode, HiTrace_Tracepoint_Type type, const HiTraceId *id, const char *fmt, ...) | 打印hitrace信息，包括跟踪ID信息 |
| void OH_HiTrace_InitId(HiTraceId *id) | 初始化HiTraceId结构体 |
| void OH_HiTrace_IdFromBytes(HiTraceId *id, const uint8_t *pIdArray, int len) | 根据字节数组创建跟踪HiTraceId结构体 |
| bool OH_HiTrace_IsIdValid(const HiTraceId *id) | 判断trace id是否有效 |
| bool OH_HiTrace_IsFlagEnabled(const HiTraceId *id, HiTrace_Flag flag) | 判断跟踪id是否启用了跟踪标志 |
| void OH_HiTrace_EnableFlag(const HiTraceId *id, HiTrace_Flag flag) | 启用跟踪ID的指定跟踪标志 |
| int OH_HiTrace_GetFlags(const HiTraceId *id) | 获取HiTraceId结构体中设置的的标志位 |
| void OH_HiTrace_SetFlags(HiTraceId *id, int flags) | 设置跟踪标志位到HiTraceId结构体中 |
| uint64_t OH_HiTrace_GetChainId(const HiTraceId *id) | 获取跟踪链ID |
| void OH_HiTrace_SetChainId(HiTraceId *id, uint64_t chainId) | 设置跟踪链ID到HiTraceId结构体中 |
| uint64_t OH_HiTrace_GetSpanId(const HiTraceId *id) | 获取当前HiTraceId结构体中的分支ID |
| void OH_HiTrace_SetSpanId(HiTraceId *id, uint64_t spanId) | 设置分支ID到HiTraceId结构体中 |
| uint64_t OH_HiTrace_GetParentSpanId(const HiTraceId *id) | 获取当前HiTraceId结构体中的父分支ID |
| void OH_HiTrace_SetParentSpanId(HiTraceId *id, uint64_t parentSpanId) | 设置父分支ID到HiTraceId结构体中 |
| int OH_HiTrace_IdToBytes(const HiTraceId* id, uint8_t* pIdArray, int len) | 将HiTraceId结构体转换为字节数组，用于缓存或者通信传递 |


## 开发示例

1. 在Deveco Studio新建Native C++应用，默认生成的项目中包含index.ets文件，在entry\src\main\cpp目录下会自动生成一个cpp文件（hello.cpp或napi_init.cpp，本示例以hello.cpp文件名为例）。index.ets代码如下，onClick中调用了testNapi的add函数，该函数在hello.cpp中定义。
    ```
    import hilog from '@ohos.hilog';
    import testNapi from 'libentry.so';

    @Entry
    @Component
    struct Index {
        @State message: string = 'Hello World';

        build() {
            Row() {
            Column() {
                Text(this.message)
                .fontSize(50)
                .fontWeight(FontWeight.Bold)
                .onClick(() => {
                    hilog.info(0x0000, 'testTag', 'Test NAPI 2 + 3 = %{public}d', testNapi.add(2, 3));
                })
            }
            .width('100%')
            }
            .height('100%')
        }
    }

2. 在CMakeLists.txt中新增libhitrace_ndk.z.so链接。

    ```
   // CMakeLists.txt
   # the minimum version of CMake.
   cmake_minimum_required(VERSION 3.4.1)
   project(MyApplication)
   
   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
   
   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)
   add_library(entry SHARED hello.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhitrace_ndk.z.so)
   ```

3. 在hello.cpp文件中引用hitrace头文件。

    ```c++
    #include "hitrace/trace.h"
    ```

4. 在hello.cpp的Add函数中，使用OH_HiTrace_BeginChain函数开启一个跟踪链，使用OH_HiTrace_EndChain关闭跟踪。

    ```c++
    #include "napi/native_api.h"
    #include "hitrace/trace.h"
    static napi_value Add(napi_env env, napi_callback_info info)
    {
        // 需要开启分布式跟踪的地方
        OH_HiTrace_BeginChain("hitraceTest", HITRACE_FLAG_DEFAULT);
        // 需要结束分布式跟踪的地方（此处为示例，开启点和结束点按实际需求放在需要的地方）
        OH_HiTrace_EndChain();
        size_t requireArgc = 2;
        size_t argc = 2;
        napi_value args[2] = {nullptr};

        napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);

        napi_valuetype valuetype0;
        napi_typeof(env, args[0], &valuetype0);

        napi_valuetype valuetype1;
        napi_typeof(env, args[1], &valuetype1);

        double value0;
        napi_get_value_double(env, args[0], &value0);

        double value1;
        napi_get_value_double(env, args[1], &value1);

        napi_value sum;
        napi_create_double(env, value0 + value1, &sum);

        return sum;

    }
    ```

5. 运行项目，会在设备上自动生成一个hap应用，点击hap上的“Hello World”文字，会调用hello.cpp中的add函数，查看hitrace日志，会出现如下信息：
    ```text
    11-02 15:13:28.922  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 0 0][dict]HiTraceBegin name:hitraceTest event flags:0x01.
    11-02 15:13:28.930  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 324c3a3 0][dict]HiTraceEnd.
   ```

