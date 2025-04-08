# 使用HiTraceMeter跟踪性能（C/C++）

## 简介

HiTraceMeter提供系统性能打点接口。开发者通过在关键代码位置调用HiTraceMeter接口提供的API接口，能够有效跟踪进程轨迹、查看系统性能。

## 基本概念

**HiTraceMeter Tag**：跟踪数据使用类别，称作HiTraceMeter Tag，一般每个软件子系统对应一个tag。[hitrace](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/dfx/hitrace.md)命令行工具采集跟踪数据时，只采集给定的tag类别选项指定的跟踪数据。应用中的HiTraceMeter打点的tag是HITRACE_TAG_APP，对应[hitrace](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/dfx/hitrace.md)命令`hitrace -l`列出的tag列表中的app。

## 实现原理

1. 应用程序通过HiTraceMeter函数接口进行打点，HiTraceMeter函数将跟踪数据通过内核sysfs文件接口输入到内核的ftrace数据缓冲区。
2. [hitrace](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/dfx/hitrace.md)命令行工具读取内核ftrace缓冲区中的跟踪数据，将跟踪数据输出到设备侧的文件中。

## 接口说明

性能打点跟踪接口由HiTraceMeter模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis-performance-analysis-kit/_hitrace.md)。

| 方法                                                         | 接口描述                   |
| ------------------------------------------------------------ | -------------------------- |
| void OH_HiTrace_StartTrace(const char* name)                 | 开启一个同步时间片跟踪事件 |
| void OH_HiTrace_FinishTrace()                                | 结束一个同步时间片跟踪事件 |
| void OH_HiTrace_StartAsyncTrace(const char* name, int32_t taskId) | 开启一个异步时间片跟踪事件 |
| void OH_HiTrace_FinishAsyncTrace(const char* name, int32_t taskId) | 结束一个异步时间片跟踪事件 |
| void OH_HiTrace_CountTrace(const char* name, int64_t count)  | 整数跟踪事件               |

> **注意：**
>
> 用户态tarce格式使用竖线 `|` 作为分隔符，所以通过HiTraceMeter接口传递的字符串类型参数应避免包含该字符，防止trace解析异常。

HiTraceMeter打点接口按功能/行为分类，主要分三类：同步时间片跟踪接口、异步时间片跟踪接口和整数跟踪接口。无论同步时间片跟踪接口还是异步时间片跟踪接口，接口本身都是同步接口，不是异步接口。HiTraceMeter打点接口可与[HiTraceChain](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/dfx/hitracechain-guidelines-arkts.md)一起使用，进行跨设备/跨进程/跨线程打点与分析。

- 同步时间片跟踪接口用于顺序执行的打点场景。
- 异步时间片跟踪接口用于在异步操作执行前进行开始打点，在异步操作完成后进行结束打点。异步跟踪的开始和结束由于不是顺序发生的，解析trace时需要通过name与taskId参数进行识别，name与taskId参数相同的异步跟踪开始与结束打点相匹配。
- 整数跟踪接口用于跟踪整数变量。

**参数解析**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | 是   | 要跟踪的数值变量名称。                                       |
| taskId | number | 是   | 用来表示关联的ID,如果有多个name相同的任务是并行执行的，则每次调用startTrace的taskId不同。 |
| count  | number | 是   | 变量的值。                                                   |

## 开发示例

在DevEco Studio中创建Native C++工程，使用HiTraceMeter NDK_C打点接口，以下为一个Native C++工程示例。

1. 新建一个Native C++工程，工程目录结构如下：

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

2. 在"CMakeLists.txt"文件末尾新增如下内容，添加libhitrace_ndk.z.so和libhilog_ndk.z.so动态链接库。

   ```cmake
   target_link_libraries(entry PUBLIC libhitrace_ndk.z.so libhilog_ndk.z.so)
   ```

3. 编辑"napi_init.cpp"文件，在Add函数中调用HiTraceMeter NDK_C的接口，进行性能打点跟踪， 示例代码如下：

   ```c++
   #include "hilog/log.h"
   #include "hitrace/trace.h"
   #include "napi/native_api.h"
   
   #undef LOG_TAG
   #define LOG_TAG "traceTest"
   
   static napi_value Add(napi_env env, napi_callback_info info)
   {
       // 第一个异步跟踪任务开始
       OH_HiTrace_StartAsyncTrace("myTestAsyncTrace", 1001);
       // 开始计数任务
       int64_t traceCount = 0;
       traceCount++;
       OH_HiTrace_CountTrace("myTestCountTrace", traceCount);
       // 业务流程
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1001");
   
       // 第二个异步跟踪任务开始，同时第一个跟踪的同名任务还没结束，出现了并行执行，对应接口的taskId需要不同
       OH_HiTrace_StartAsyncTrace("myTestAsyncTrace", 1002);
       // 开始计数任务
       traceCount++;
       OH_HiTrace_CountTrace("myTestCountTrace", traceCount);
       // 业务流程
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, taskId: 1002");
   
       // 结束taskId为1001的异步跟踪任务
       OH_HiTrace_FinishAsyncTrace("myTestAsyncTrace", 1001);
       // 结束taskId为1002的异步跟踪任务
       OH_HiTrace_FinishAsyncTrace("myTestAsyncTrace", 1002);
   
       // 开始同步跟踪任务
       OH_HiTrace_StartTrace("myTestSyncTrace");
       // 业务流程
       OH_LOG_INFO(LogType::LOG_APP, "myTraceTest running, synchronizing trace");
       // 结束同步跟踪任务
       OH_HiTrace_FinishTrace();
   
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
   
4. 在DevEco Studio Terminal窗口中执行如下命令，开启应用trace捕获：

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

5. 单击DevEco Studio界面上的运行按钮，启动应用，点击屏幕中间的字符串，执行包含HiTraceMeter打点的业务逻辑，然后执行如下命令抓取trace数据：

   ```shell
   $ hitrace --trace_dump | grep myTest
   ```

   成功抓取的trace数据如下所示：

   ```text
   <...>-21458   (-------) [009] .... 372404.331037: tracing_mark_write: S|21458|H:myTestAsyncTrace|1001
   <...>-21458   (-------) [009] .... 372404.331040: tracing_mark_write: C|21458|H:myTestCountTrace|1
   <...>-21458   (-------) [009] .... 372404.331083: tracing_mark_write: S|21458|H:myTestAsyncTrace|1002
   <...>-21458   (-------) [009] .... 372404.331085: tracing_mark_write: C|21458|H:myTestCountTrace|2
   <...>-21458   (-------) [009] .... 372404.331091: tracing_mark_write: F|21458|H:myTestAsyncTrace|1001
   <...>-21458   (-------) [009] .... 372404.331093: tracing_mark_write: F|21458|H:myTestAsyncTrace|1002
   <...>-21458   (-------) [009] .... 372404.331095: tracing_mark_write: B|21458|H:myTestSyncTrace 
   ```

6. 执行如下命令，结束应用trace捕获：

   ```shell
   $ hitrace --trace_finish
   ```
