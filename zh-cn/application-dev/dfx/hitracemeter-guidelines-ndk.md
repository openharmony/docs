# 使用HiTraceMeter跟踪性能（C/C++）

HiTrace为开发者提供业务流程调用链跟踪的维测接口。该接口所提供的功能，可以帮助开发者迅速获取指定业务流程调用链的运行日志、定位跨设备/跨进程/跨线程的故障问题。

## 接口说明

性能打点跟踪接口由HiTraceMeter模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis-performance-analysis-kit/_hitrace.md)。

| 方法 | 接口描述 |
| -------- | -------- |
| void OH_HiTrace_StartTrace(const char* name) | 开启一个同步时间片跟踪事件 |
| void OH_HiTrace_FinishTrace() | 结束一个同步时间片跟踪事件 |
| void OH_HiTrace_StartAsyncTrace(const char* name, int32_t taskId) | 开启一个异步时间片跟踪事件 |
| void OH_HiTrace_FinishAsyncTrace(const char* name, int32_t taskId) | 结束一个异步时间片跟踪事件 |
| void OH_HiTrace_CountTrace(const char* name, int64_t count) | 整数跟踪事件 |

**参数解析**

| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | 是   | 要跟踪的数值变量名称。 |
| taskId | number | 是   | 用来表示关联的ID,如果有多个name相同的任务是并行执行的，则每次调用startTrace的taskId不同。 |
| count  | number | 是   | 变量的值。  |

## 开发示例

1. 在CMakeLists.txt中新增libhitrace_ndk.z.so链接。

    ```
    target_link_libraries(entry PUBLIC libhitrace_ndk.z.so)
    ```

2. 在源文件中引用hitrace头文件。

    ```c++
    #include "hitrace/trace.h"
    ```

3. 在需要打点的地方进行性能打点，以异步打点为例（示例代码为默认的hello.cpp的一部分，使用时只需要按照示例的使用方法将接口-参看接口说明，放在需要的地方即可）

    ```c++
    #include "napi/native_api.h"
    #include "hitrace/trace.h"
    static napi_value Add(napi_env env, napi_callback_info info)
    {
        // 需要开启异步时间片跟踪的地方
        OH_HiTrace_StartAsyncTrace("hitraceTest", 123);
        // 需要结束异步时间片跟踪的地方（此处为示例，开启点和结束点按实际需求放在需要的地方）
        OH_HiTrace_FinishAsyncTrace("hitraceTest", 123);
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

4. 将编译好的hap包推送到设备上安装，cmd窗口执行hdc shell连上设备后执行命令：hitrace --trace_begin app。
    
    ```shell
    capturing trace...
    ```

5. 设备上重复点击几次新安装的hap，然后在shell窗口dump trace查看结果，命令是：hitrace --trace_dump | grep hitraceTest。
    
    ```shell
    <...>-2477    (-------) [001] ....   396.427165: tracing_mark_write: S|2477|H:hitraceTest 123
    <...>-2477    (-------) [001] ....   396.427196: tracing_mark_write: F|2477|H:hitraceTest 123
    ```