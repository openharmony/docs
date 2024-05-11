# 使用HiTraceMeter跟踪性能（C/C++）

HiTrace为开发者提供业务流程调用链跟踪的维测接口。该接口所提供的功能，可以帮助开发者迅速获取指定业务流程调用链的运行日志、定位跨设备/跨进程/跨线程的故障问题。

## 接口说明

性能打点跟踪接口由HiTraceMeter模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis-performance-analysis-kit/_hitrace.md)。

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

**参数解析**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | 是   | 要跟踪的数值变量名称。 |
| id | HiTraceId | 是   | 用来当前线程的HitraceId。 |
| mode  | HiTrace_Communication_Mode | 是   | 通信模式。  |
| type  | HiTrace_Tracepoint_Type | 是   | 打点类型。  |
| fmt  | string | 是   | 打点信息。  |
| pIdArray  | int | 是   | 创建HitraceId的字节数组。  |
| len  | int | 是   | 创建HitraceId的字节数组长度。  |
| flag  | HiTrace_Flag | 是   | 用来跟踪的flag。  |
| flags  | int | 是   | 用来跟踪的flag。  |
| chainId  | int | 是   | 跟踪id。  |
| spanId  | int | 是   | 分支id。  |
| parentSpanId  | int | 是   | 分支id。  |

## 开发示例

1. 在CMakeLists.txt中新增libhitrace_ndk.z.so链接。

    ```
    target_link_libraries(entry PUBLIC libhitrace_ndk.z.so)
    ```

2. 在源文件中引用hitrace头文件。

    ```c++
    #include "hitrace/trace.h"
    ```

3. 在需要打点的地方进行打点（示例代码为默认的napi_init.cpp的一部分，使用时只需要按照示例的使用方法将接口-参看接口说明，放在需要的地方即可）

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

4. 将编译好的hap包推送到设备上安装，点击设备上的hap应用。在Log窗口查看分布式跟踪的相关信息，使用“Hitrace”过滤属于hap应用的日志信息。
    ```text
    11-02 15:13:28.922  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 0 0][dict]HiTraceBegin name:hitraceTest event flags:0x01.
    11-02 15:13:28.930  21519-21519  C02D03/HiTraceC                  com.example.hitracechaintest     I  [a92ab94c18e1341 324c3a3 0][dict]HiTraceEnd.
   ```

