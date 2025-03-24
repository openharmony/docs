# 使用HiTraceMeter跟踪性能（C/C++）

## 简介

HiTraceMeter提供系统性能打点接口。开发者通过在关键代码位置调用HiTraceMeter接口提供的API接口，能够有效跟踪进程轨迹、查看系统性能。

## 基本概念

**HiTraceMeter Tag**：跟踪数据使用类别，称作HiTraceMeter Tag，一般每个软件子系统对应一个tag。[hitrace](hitrace.md)命令行工具采集跟踪数据时，只采集给定的tag类别选项指定的跟踪数据。应用中的HiTraceMeter打点的tag是HITRACE_TAG_APP，对应[hitrace](hitrace.md)命令`hitrace -l`列出的tag列表中的app。

## 实现原理

1. 应用程序通过HiTraceMeter函数接口进行打点，HiTraceMeter函数将跟踪数据通过内核sysfs文件接口输入到内核的ftrace数据缓冲区。
2. [hitrace](hitrace.md)命令行工具读取内核ftrace缓冲区中的跟踪数据，将文本格式的跟踪数据输出到设备侧的文件中。

## 接口说明

性能打点跟踪接口由HiTraceMeter模块提供，详细API请参考[性能打点跟踪API参考](../reference/apis-performance-analysis-kit/_hitrace.md)。

| 方法                                                         | 接口描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| void OH_HiTrace_StartTraceEx(HiTrace_Output_Level level, const char* name, const char* customArgs) | 开启一个同步时间片跟踪事件，分级控制跟踪输出。               |
| void OH_HiTrace_FinishTraceEx(HiTrace_Output_Level level)    | 结束一个同步时间片跟踪事件，分级控制跟踪输出。level必须与流程开始的OH_HiTrace_StartTraceEx对应参数值保持一致。 |
| void OH_HiTrace_StartAsyncTraceEx(HiTrace_Output_Level level, const char* name, int32_t taskId, const char* customCategory, const char* customArgs) | 开启一个异步时间片跟踪事件，分级控制跟踪输出。taskId是trace中用来表示关联的ID，如果有多个name相同的任务并行执行，则开发者每次调用OH_HiTrace_StartAsyncTraceEx时传入的taskId需不同；如果具有相同name的任务是串行执行的，则taskId可以相同。 |
| void OH_HiTrace_FinishAsyncTraceEx(HiTrace_Output_Level level, const char* name, int32_t taskId) | 结束一个异步时间片跟踪事件，分级控制跟踪输出。level、name和taskId必须与流程开始的OH_HiTrace_StartAsyncTraceEx对应参数值保持一致。 |
| void OH_HiTrace_CountTraceEx(HiTrace_Output_Level level, const char* name, int64_t count) | 整数跟踪事件，分级控制跟踪输出。用来标记一个预跟踪的整数变量，该变量的数值会不断变化。 |
| bool OH_HiTrace_IsTraceEnabled(void)                         | 判断当前是否开启应用trace捕获。应用trace捕获未开启时，HiTraceMeter性能跟踪打点无效。 |

HiTraceMeter打点接口按功能/行为分类，主要分三类：同步时间片跟踪接口、异步时间片跟踪接口和整数跟踪接口。无论同步时间片跟踪接口还是异步时间片跟踪接口，接口本身都是同步接口，不是异步接口。HiTraceMeter打点接口可与[HiTraceChain](./hitracechain-guidelines-ndk.md)一起使用，进行跨设备/跨进程/跨线程打点与分析。

- 同步时间片跟踪接口用于顺序执行的打点场景。
- 异步时间片跟踪接口用于在异步操作执行前进行开始打点，在异步操作完成后进行结束打点。异步跟踪的开始和结束由于不是顺序发生的，解析trace时需要通过name与taskId参数进行识别，name与taskId参数相同的异步跟踪开始与结束打点相匹配。
- 整数跟踪接口用于跟踪整数变量。

**参数解析**

| 参数名         | 类型        | 说明                                                         |
| -------------- | ----------- | ------------------------------------------------------------ |
| level          | enum        | 跟踪输出级别，低于系统阈值的跟踪将不会被输出。<br>log版本阈值为HITRACE_LEVEL_INFO，nolog版本阈值为HITRACE_LEVEL_COMMERCIAL。 |
| name           | const char* | 要跟踪的任务名称或整数变量名称。该字段长度限制320字符，超过的部分将会被截断。 |
| taskId         | int32_t     | 用来表示关联的ID，如果有多个name相同的任务是并行执行的，则开发者每次调用OH_HiTrace_StartAsyncTraceEx时传入的taskId需不同。 |
| count          | int64_t     | 整数变量的值。                                               |
| customCategory | const char* | 自定义聚类名称，用于聚合同一类异步跟踪打点。该字段长度限制64字符，超过的部分将会被截断。<br>若不需要聚类，可传入一个空字符串。 |
| customArgs     | const char* | 自定义键值对，若有多组键值对，使用逗号进行分隔，例"key1=value1,key2=value2"。<br>跟踪输出总长度限制512字符，若name和customCategory参数占用过多字符，可能导致customArgs被截断。<br>若不需要该参数，可传入一个空字符串。 |

## 开发示例

以下为一个使用HiTraceMeter打点接口的NDK C/C++程序示例，该示例中使用了异步跟踪打点接口OH_HiTrace_StartAsyncTraceEx和OH_HiTrace_FinishAsyncTraceEx。

1. 在CMakeLists.txt中新增libhitrace_ndk.z.so链接。

   ```
   target_link_libraries(entry PUBLIC libhitrace_ndk.z.so)
   ```

2. 在源文件中引用hitrace头文件。

   ```c++
   #include "hitrace/trace.h"
   ```

3. 在需要打点的地方进行性能打点，以异步打点为例（示例代码为默认的hello.cpp的一部分，使用时只需要按照示例的使用方法将性能打点接口放在需要的地方即可）。

   ```c++
   #include "napi/native_api.h"
   #include "hitrace/trace.h"
   static napi_value Add(napi_env env, napi_callback_info info)
   {
       // 需要开启异步时间片跟踪的地方
       OH_HiTrace_StartAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "hitraceTest", 123, "categoryTest", "key=value");
       // 需要结束异步时间片跟踪的地方（此处为示例，开启点和结束点按实际需求放在需要的地方）
       OH_HiTrace_FinishAsyncTraceEx(HITRACE_LEVEL_COMMERCIAL, "hitraceTest", 123);
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

4. 将编译好的hap包推送到设备上安装，cmd窗口执行hdc shell连接设备，执行如下命令开启应用trace捕获：

   ```shell
   $ hitrace --trace_begin app
   ```

5. 启动应用，执行自己的业务调用逻辑（包含HiTraceMeter打点接口），然后在shell窗口dump trace查看结果，命令如下：

   ```shell
   $ hitrace --trace_dump | grep hitraceTest
   $ hitrace --trace_finish
   ```

   抓取trace成功的数据如下所示：

   ```text
   <...>-26889   (-------) [001] ....  3100.023070: tracing_mark_write: S|26889|H:hitraceTest|123|M62|categoryTest|key=value
   <...>-26889   (-------) [001] ....  3100.023080: tracing_mark_write: F|26889|H:hitraceTest|123|M62
   ```
