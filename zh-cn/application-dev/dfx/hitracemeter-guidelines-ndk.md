# 使用HiTraceMeter跟踪性能（C/C++）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @kutcherzhou1; @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 简介

HiTraceMeter提供系统性能打点接口。开发者在关键代码位置调用这些API，能够有效跟踪进程轨迹，查看系统和应用性能。


## 接口说明

性能打点跟踪接口由HiTraceMeter模块提供，详细API请参考[Hitrace C API参考](../reference/apis-performance-analysis-kit/capi-trace-h.md)。

| 方法 | 接口描述 |
| -------- | -------- |
| void OH_HiTrace_StartTraceEx(HiTrace_Output_Level level, const char\* name, const char\* customArgs) | 开启一个同步时间片跟踪事件，分级控制跟踪输出。<br/>**说明**：从API version 19开始，支持该接口。 |
| void OH_HiTrace_FinishTraceEx(HiTrace_Output_Level level) | 结束一个同步时间片跟踪事件，分级控制跟踪输出。<br/>level必须与流程开始的OH_HiTrace_StartTraceEx()对应参数值保持一致。<br/>**说明**：从API version 19开始，支持该接口。 |
| void OH_HiTrace_StartAsyncTraceEx(HiTrace_Output_Level level, const char\* name, int32_t taskId, const char\* customCategory, const char\* customArgs) | 开启一个异步时间片跟踪事件，分级控制跟踪输出。<br/>taskId是trace中用来表示关联的ID，如果有多个name相同的任务并行执行，则开发者每次调用OH_HiTrace_StartAsyncTraceEx()时，传入的taskId需不同；如果具有相同name的任务是串行执行的，则taskId可以相同。<br/>**说明**：从API version 19开始，支持该接口。 |
| void OH_HiTrace_FinishAsyncTraceEx(HiTrace_Output_Level level, const char\* name, int32_t taskId) | 结束一个异步时间片跟踪事件，分级控制跟踪输出。<br/>level、name和taskId必须与流程开始的OH_HiTrace_StartAsyncTraceEx()对应参数值保持一致。<br/>**说明**：从API version 19开始，支持该接口。 |
| void OH_HiTrace_CountTraceEx(HiTrace_Output_Level level, const char\* name, int64_t count) | 整数跟踪事件，分级控制跟踪输出。<br/>name、count两个参数分别用来标记一个跟踪的整数变量名及整数值。<br/>**说明**：从API version 19开始，支持该接口。 |
| bool OH_HiTrace_IsTraceEnabled(void) | 判断当前是否开启应用trace捕获。<br/>使用hitrace命令行工具等方式开启采集时返回true，未开启采集或停止采集后返回false，此时调用HiTraceMeter性能跟踪打点接口无效。<br/>**说明**：从API version 19开始，支持该接口。 |

> **注意：**
>
> [用户态trace格式](hitracemeter-view.md#用户态trace格式说明)使用竖线 | 作为分隔符，所以通过HiTraceMeter接口传递的字符串类型参数应避免包含该字符，以防止trace解析异常。


### 接口分类

HiTraceMeter打点接口主要分为三类：同步时间片跟踪接口、异步时间片跟踪接口和整数跟踪接口。HiTraceMeter接口实现均为同步，同步和异步针对的是被跟踪的业务。同步业务使用同步时间片跟踪接口，异步业务使用异步时间片跟踪接口。HiTraceMeter打点接口可与[HiTraceChain](hitracechain-guidelines-ndk.md)一起使用，进行跨设备、跨进程或跨线程的打点关联与分析。


### 接口使用场景


- 同步时间片跟踪接口
  用于顺序执行的打点场景，需按序成对使用OH_HiTrace_StartTraceEx()接口和OH_HiTrace_FinishTraceEx()接口，否则会导致trace文件在smartperf等可视化工具上显示异常。

- 异步时间片跟踪接口
  在异步操作执行前调用OH_HiTrace_StartAsyncTraceEx()接口进行开始打点，在异步操作完成后调用OH_HiTrace_FinishAsyncTraceEx()接口进行结束打点。  
  解析trace时，通过name和taskId参数识别不同的异步跟踪。所以这两个接口必须按序成对使用，并传入相同的name和taskId。  
  不同的异步流程中应使用不同的name和taskId，但在异步跟踪流程不会同时发生的情况下，可以使用相同的name和taskId。  
  调用错误会导致trace文件在smartperf等可视化工具上显示异常。

- 整数跟踪接口
  用于跟踪整数变量。整数值变动时调用OH_HiTrace_CountTraceEx()接口，可在smartperf的泳道图中观察变动情况。由于从开始采集到首次打点存在时间差，这段时间的数值无法查看。


### 参数解析


| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| level | enum | 跟踪输出级别，低于系统阈值的跟踪将不会被输出。<br/>log版本阈值为HITRACE_LEVEL_INFO，nolog版本阈值为HITRACE_LEVEL_COMMERCIAL。 |
| name | const char\* | 要跟踪的任务名称或整数变量名称。 |
| taskId | int32_t | 用来表示关联的ID，如果有多个name相同的任务并行执行，则开发者每次调用OH_HiTrace_StartAsyncTraceEx()时，传入的taskId需不同。 |
| count | int64_t | 整数变量的值。 |
| customCategory | const char\* | 自定义聚类名称，用于聚合同一类异步跟踪打点。<br/>若不需要聚类，可传入一个空字符串。 |
| customArgs | const char\* | 自定义键值对，若有多组键值对，使用逗号进行分隔，例"key1=value1,key2=value2"。<br/>若不需要该参数，可传入一个空字符串。 |


> **说明：**
>
> [用户态trace](hitracemeter-view.md#用户态trace格式说明)总长度限制为512字符，超过部分将会被截断。建议name、customCategory和customArgs三个字段的总长度不超过420字符，以避免trace被截断。


## 开发步骤

以下为一个使用HiTraceMeter打点接口的Native C++应用示例。


### 步骤一：创建项目


1. 在DevEco Studio中新建工程，选择“Native C++”，工程的目录结构如下。

   ```text
   ├── entry
   │   ├── src
   │       ├── main
   │       │   ├── cpp
   │       │   │   ├── CMakeLists.txt
   │       │   │   ├── napi_init.cpp
   │       │   │   └── types
   │       │   │       └── libentry
   │       │   │           ├── Index.d.ts
   │       │   │           └── oh-package.json5
   │       │   ├── ets
   │       │   │   ├── entryability
   │       │   │   │   └── EntryAbility.ets
   │       │   │   ├── entrybackupability
   │       │   │   │   └── EntryBackupAbility.ets
   │       │   │   └── pages
   │       │   │       └── Index.ets
   ```

2. 在“entry &gt; src &gt; main &gt; cpp &gt; CMakeLists.txt”文件中新增libhitrace_ndk.z.so和libhilog_ndk.z.so动态链接库，完整的文件内容如下。

   ```cmake
   # the minimum version of CMake.
   cmake_minimum_required(VERSION 3.5.0)
   project(HiTraceChainTest03)
   
   set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
   
   if(DEFINED PACKAGE_FIND_FILE)
       include(${PACKAGE_FIND_FILE})
   endif()
   
   include_directories(${NATIVERENDER_ROOT_PATH}
                       ${NATIVERENDER_ROOT_PATH}/include)
   
   add_library(entry SHARED napi_init.cpp)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhitrace_ndk.z.so libhilog_ndk.z.so)
   ```

3. 编辑“entry &gt; src &gt; main &gt; cpp &gt; napi_init.cpp”文件，在Add函数中调用HiTraceMeter NDK_C接口进行性能打点跟踪，完整的示例代码如下。

   ```c++
   #include <cstdio>
   #include <cstring>
   
   #include "hilog/log.h"
   #include "hitrace/trace.h"
   #include "napi/native_api.h"
   
   #undef LOG_TAG
   #define LOG_TAG "traceTest"
   
   static napi_value Add(napi_env env, napi_callback_info info)
   {
       // 第一个异步跟踪任务开始
       OH_HiTrace_StartAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1001, "categoryTest", "key=value");
       // 开始计数任务
       int64_t traceCount = 0;
       traceCount++;
       OH_HiTrace_CountTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestCountTrace", traceCount);
       // 业务流程
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1001");
   
       // 第二个异步跟踪任务开始，同时第一个跟踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同
       OH_HiTrace_StartAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1002, "categoryTest", "key=value");
       // 开始计数任务
       traceCount++;
       OH_HiTrace_CountTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestCountTrace", traceCount);
       // 业务流程
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1002");
   
       // 结束taskId为1001的异步跟踪任务
       OH_HiTrace_FinishAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1001);
       // 结束taskId为1002的异步跟踪任务
       OH_HiTrace_FinishAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1002);
   
       // 开始同步跟踪任务
       OH_HiTrace_StartTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestSyncTrace", "key=value");
       // 业务流程
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, synchronizing trace");
       // 结束同步跟踪任务
       OH_HiTrace_FinishTraceEx(HITRACE_LEVEL_COMMERCIAL);
   
       // 若通过HiTraceMeter性能打点接口传递的参数的生成过程比较复杂，此时可以通过isTraceEnabled判断当前是否开启应用trace捕获，
       // 在未开启应用trace捕获时，避免该部分性能损耗
       if (OH_HiTrace_IsTraceEnabled()) {
           char customArgs[128] = "key0=value0";
           for (int index = 1; index < 10; index++) {
               char buffer[16];
               snprintf(buffer, sizeof(buffer), ",key%d=value%d", index, index);
               strncat(customArgs, buffer, sizeof(customArgs) - strlen(customArgs) - 1);
           }
           OH_HiTrace_StartAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1003, "categoryTest", customArgs);
           OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1003");
           OH_HiTrace_FinishAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "myTestAsyncTrace", 1003);
       } else {
           OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, trace is not enabled");
       }
   
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
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "add", nullptr, Add, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   EXTERN_C_END
   
   static napi_module demoModule = {
       .nm_version = 1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "entry",
       .nm_priv = ((void*)0),
       .reserved = { 0 },
   };
   
   extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
   {
       napi_module_register(&demoModule);
   }
   ```


### 步骤二：采集trace信息并查看

1. 在DevEco Studio Terminal窗口中执行如下命令，开启应用trace捕获。

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

2. 单击DevEco Studio界面上的运行按钮，启动应用。点击应用界面的“Hello World”文本，执行包含HiTraceMeter打点的业务逻辑。然后执行如下命令抓取trace数据，并使用“myTest”关键字过滤trace数据（示例打点接口传递的name字段前缀均为“myTest”）。

   ```shell
   $ hitrace --trace_dump | grep myTest
   ```

   成功抓取的trace数据如下所示。

   ```text
   <...>-49837   (-------) [002] .... 349137.708093: tracing_mark_write: S|49837|H:myTestAsyncTrace|1001|M62|categoryTest|key=value
   <...>-49837   (-------) [002] .... 349137.708103: tracing_mark_write: C|49837|H:myTestCountTrace|1|M62
   <...>-49837   (-------) [002] .... 349137.708201: tracing_mark_write: S|49837|H:myTestAsyncTrace|1002|M62|categoryTest|key=value
   <...>-49837   (-------) [002] .... 349137.708209: tracing_mark_write: C|49837|H:myTestCountTrace|2|M62
   <...>-49837   (-------) [002] .... 349137.708239: tracing_mark_write: F|49837|H:myTestAsyncTrace|1001|M62
   <...>-49837   (-------) [002] .... 349137.708246: tracing_mark_write: F|49837|H:myTestAsyncTrace|1002|M62
   <...>-49837   (-------) [002] .... 349137.708252: tracing_mark_write: B|49837|H:myTestSyncTrace|M62|key=value
   <...>-49837   (-------) [002] .... 349137.708301: tracing_mark_write: S|49837|H:myTestAsyncTrace|1003|M62|categoryTest|key0=value0,key1=value1,key2=value2,key3=value3,key4=value4,key5=value5,key6=value6,key7=value7,key8=value8,key9=value9
   <...>-49837   (-------) [002] .... 349137.708323: tracing_mark_write: F|49837|H:myTestAsyncTrace|1003|M62
   ```


### 步骤三：停止采集trace

1. 执行以下命令，结束应用trace捕获。

   ```shell
   $ hitrace --trace_finish
   ```

2. 再次点击应用界面的“Hello World”文本，此时应用trace捕获已关闭，OH_HiTrace_IsTraceEnabled()接口返回false。在DevEco Studio Log窗口使用关键字“not enabled”进行过滤，会打印如下日志。

   ```text
   myTraceTest running, trace is not enabled
   ```

   > **说明：**
   >
   > log版本在使用hitrace --trace_finish命令停止采集后会自动拉起快照模式，打开应用trace捕获，此时OH_HiTrace_IsTraceEnabled()接口返回true，不会打印上述日志。
