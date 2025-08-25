# 使用HiTraceChain打点（C/C++）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 接口说明

分布式跟踪接口由HiTraceChain模块提供，详细API请参考[分布式跟踪C API](../reference/apis-performance-analysis-kit/capi-trace-h.md)。

下表所示的接口提供基本的分布式跟踪功能，ArkTS中也有相应的接口。

| 方法 | 接口描述 | 
| -------- | -------- |
| HiTraceId OH_HiTrace_BeginChain(const char \*name, int flags) | 开始跟踪，并返回创建的HiTraceId。 | 
| void OH_HiTrace_EndChain() | 停止跟踪。 | 
| HiTraceId OH_HiTrace_GetId() | 从当前线程TLS中获取跟踪标识。 | 
| void OH_HiTrace_SetId(const HiTraceId \*id) | 将当前线程TLS中的跟踪标识设置为id。 | 
| void OH_HiTrace_ClearId(void) | 清除当前线程的跟踪标识。 | 
| HiTraceId OH_HiTrace_CreateSpan(void) | 创建跟踪分支。创建一个HiTraceId，使用当前线程TLS中的chainId、spanId初始化HiTraceId的chainId、parentSpanId，并为HiTraceId生成一个新的spanId，返回该HiTraceId。 | 
| bool OH_HiTrace_IsIdValid(const HiTraceId \*id) | 判断HiTraceId是否有效。<br/>true：HiTraceId有效；false：HiTraceId无效。 | 
| bool OH_HiTrace_IsFlagEnabled(const HiTraceId \*id, HiTrace_Flag flag) | 判断HiTraceId中指定的跟踪标志是否已启用。<br/>true：指定的跟踪标志已启用；false：指定的跟踪标志未启用。 | 
| void OH_HiTrace_EnableFlag(const HiTraceId \*id, HiTrace_Flag flag) | 启用HiTraceId中指定的跟踪标志。 | 
| void OH_HiTrace_Tracepoint(HiTrace_Communication_Mode mode, HiTrace_Tracepoint_Type type, const HiTraceId \*id, const char \*fmt, ...) | HiTraceMeter跟踪信息埋点。 | 

下表所示的接口提供对HiTraceId的一些拓展操作，这些接口仅在C/C++中提供。

| 方法 | 接口描述 | 
| -------- | -------- |
| void OH_HiTrace_InitId(HiTraceId \*id) | 初始化HiTraceId。 | 
| int OH_HiTrace_GetFlags(const HiTraceId \*id) | 获取HiTraceId中设置的跟踪标志位。 | 
| void OH_HiTrace_SetFlags(HiTraceId \*id, int flags) | 设置跟踪标志位到HiTraceId中。 | 
| uint64_t OH_HiTrace_GetChainId(const HiTraceId \*id) | 获取HiTraceId中的跟踪链ID。 | 
| void OH_HiTrace_SetChainId(HiTraceId \*id, uint64_t chainId) | 设置跟踪链ID到HiTraceId中。 | 
| uint64_t OH_HiTrace_GetSpanId(const HiTraceId \*id) | 获取HiTraceId中的分支ID。 | 
| void OH_HiTrace_SetSpanId(HiTraceId \*id, uint64_t spanId) | 设置分支ID到HiTraceId中。 | 
| uint64_t OH_HiTrace_GetParentSpanId(const HiTraceId \*id) | 获取HiTraceId中的父分支ID。 | 
| void OH_HiTrace_SetParentSpanId(HiTraceId \*id, uint64_t parentSpanId) | 设置父分支ID到HiTraceId中。 | 
| int OH_HiTrace_IdToBytes(const HiTraceId\* id, uint8_t\* pIdArray, int len) | 将HiTraceId转换为字节数组，用于缓存或通信传递。 | 
| void OH_HiTrace_IdFromBytes(HiTraceId \*id, const uint8_t \*pIdArray, int len) | 根据字节数组创建HiTraceId。 | 


## 开发步骤

std::thread不支持自动传递HiTraceId，开发示例展示了该场景下分布式跟踪的使用方法。开发者可参考[约束与限制](hitracechain-intro.md#约束与限制)，了解常见的支持与不支持HiTraceChain自动传递的机制。

1. 在DevEco Studio中新建工程，选择“Native C++”，工程的目录结构如下：

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

2. 在“entry &gt; src &gt; main &gt; cpp &gt; CMakeLists.txt”文件中新增libhitrace_ndk.z.so和libhilog_ndk.z.so动态链接库，完整的文件内容如下：

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

3. 编辑“entry &gt; src &gt; main &gt; cpp &gt; napi_init.cpp”文件，使用HiTraceChain跟踪多线程任务，完整的示例代码如下：

   ```cpp
   #include <thread>
   
   #include "hilog/log.h"
   #include "hitrace/trace.h"
   #include "napi/native_api.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   
   void Print2(HiTraceId id)
   {
       // 为当前线程设置HiTraceId
       OH_HiTrace_SetId(&id);
       // 生成分支标识spanId
       id = OH_HiTrace_CreateSpan();
       // 为当前线程设置带spanId的HiTraceId
       OH_HiTrace_SetId(&id);
       OH_LOG_INFO(LogType::LOG_APP, "Print2");
       // 结束当前线程分布式跟踪，功能同OH_HiTrace_EndChain()
       OH_HiTrace_ClearId();
       OH_LOG_INFO(LogType::LOG_APP, "Print2, HiTraceChain end");
   }

   void Print1(HiTraceId id)
   {
       // 为当前线程设置HiTraceId
       OH_HiTrace_SetId(&id);
       // 生成分支标识spanId
       id = OH_HiTrace_CreateSpan();
       // 为当前线程设置带spanId的HiTraceId
       OH_HiTrace_SetId(&id);
       OH_LOG_INFO(LogType::LOG_APP, "Print1");
       std::thread(Print2, OH_HiTrace_GetId()).detach();
       // 结束当前线程分布式跟踪
       OH_HiTrace_EndChain();
       OH_LOG_INFO(LogType::LOG_APP, "Print1, HiTraceChain end");
   }
   
   static napi_value Add(napi_env env, napi_callback_info info)
   {
       // 任务开始，开启分布式跟踪
       HiTraceId hiTraceId = OH_HiTrace_BeginChain("testTag: hiTraceChain begin", HiTrace_Flag::HITRACE_FLAG_DEFAULT);
       // 判断生成的hiTraceId是否有效，有效则输出一行hilog日志
       if (OH_HiTrace_IsIdValid(&hiTraceId)) {
           OH_LOG_INFO(LogType::LOG_APP, "HiTraceId is valid");
       }
       // 使能HITRACE_FLAG_INCLUDE_ASYNC标志位，表示会在系统支持的异步机制里自动传递HiTraceId
       OH_HiTrace_EnableFlag(&hiTraceId, HiTrace_Flag::HITRACE_FLAG_INCLUDE_ASYNC);
       // 判断hitraceId的HITRACE_FLAG_INCLUDE_ASYNC标志位是否已经使能，使能则把hiTraceId设置到当前线程TLS中
       if (OH_HiTrace_IsFlagEnabled(&hiTraceId, HiTrace_Flag::HITRACE_FLAG_INCLUDE_ASYNC)) {
           OH_HiTrace_SetId(&hiTraceId);
           OH_LOG_INFO(LogType::LOG_APP, "HITRACE_FLAG_INCLUDE_ASYNC is enabled");
       }
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
   
       // 创建线程执行打印任务，传递当前线程的HiTraceId
       std::thread(Print1, OH_HiTrace_GetId()).detach();
       // 任务结束，结束分布式跟踪
       OH_HiTrace_EndChain();
       OH_LOG_INFO(LogType::LOG_APP, "Add, HiTraceChain end");
   
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

   编辑“entry &gt; src &gt; main &gt; ets &gt; pages &gt; Index.ets”文件，在按钮点击事件里调用Add方法，完整的示例代码如下：

   ```ts
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import testNapi from 'libentry.so';
   
   const DOMAIN = 0x0000;
   
   @Entry
   @Component
   struct Index {
     @State message: string = "clickTime=0";
     @State clickTime: number = 0;
   
     build() {
       Row() {
         Column() {
           Button(this.message)
             .fontSize(20)
             .margin(5)
             .width(350)
             .height(60)
             .fontWeight(FontWeight.Bold)
             .onClick(() => {
               this.clickTime++;
               this.message = "clickTime=" + this.clickTime;
               hilog.info(DOMAIN, 'testTag', 'Test NAPI 2 + 3 = %{public}d', testNapi.add(2, 3));
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

4. 点击DevEco Studio界面中的运行按钮，运行应用工程。然后点击设备上“clickTime=0”按钮，触发业务逻辑。

5. 在DevEco Studio Log窗口查看分布式跟踪的相关信息。
   - 设备屏幕上按钮显示“clickTime=1”，表示已点击了按钮一次并触发业务逻辑。
   - 示例所有hilog打印均使用了“testTag”，因此可以使用“testTag”关键字过滤日志，查看该业务代码打印的hilog信息。

      ```txt
      06-05 21:26:01.006   9944-9944     C02D33/com.exa...tion/HiTraceC  com.examp...lication  I     [a92ab19ae90197d 0 0]HiTraceBegin name:testTag: hiTraceChain begin flags:0x00.
      06-05 21:26:01.006   9944-9944     A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab19ae90197d 0 0]HiTraceId is valid
      06-05 21:26:01.006   9944-9944     A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab19ae90197d 0 0]HITRACE_FLAG_INCLUDE_ASYNC is enabled
      06-05 21:26:01.007   9944-9944     A00000/com.exa...ation/testTag  com.examp...lication  I     Add, HiTraceChain end
      06-05 21:26:01.007   9944-9944     A00000/com.exa...ation/testTag  com.examp...lication  I     Test NAPI 2 + 3 = 5
      06-05 21:26:01.007   9944-13961    A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab19ae90197d 2544fdb 0]Print1
      06-05 21:26:01.007   9944-13961    A00000/com.exa...ation/testTag  com.examp...lication  I     Print1, HiTraceChain end
      06-05 21:26:01.008   9944-13962    A00000/com.exa...ation/testTag  com.examp...lication  I     [a92ab19ae90197d 236699a 2544fdb]Print2
      06-05 21:26:01.008   9944-13962    A00000/com.exa...ation/testTag  com.examp...lication  I     Print2, HiTraceChain end
      ```

   - hilog日志前附加的[chainId spanId parentSpanId]格式的信息即为HiTraceId信息，例如[a92ab19ae90197d 236699a 2544fdb]表示跟踪链标识chainId值为a92ab19ae90197d，分支标识spanId值为236699a，父分支标识parentSpanId值为2544fdb。
   - 通过手动传递HiTraceId，创建spanId，并将其设置到std::thread创建的子线程中，子线程中运行的Print1和Print2业务的hilog日志也携带上同主线程一致的跟踪标识“a92ab19ae90197d”。
   - 使用OH_HiTrace_EndChain或OH_HiTrace_ClearId结束分布式跟踪后，hilog打印信息不再携带HiTraceId信息。
