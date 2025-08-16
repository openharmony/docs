# 使用HiCollie监控函数执行时间超长问题（C/C++）

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 简介

任务执行超时指要监控的业务代码逻辑执行时长超过业务逻辑预期时间。本文面向开发者介绍HiCollie模块对外提供函数执行时间超长的检测能力。

## 接口说明

| 接口名 | 描述 |
| -------- | -------- |
| OH_HiCollie_SetTimer | 注册定时器，用于检测函数或代码块执行是否超过自定义时间。<br/>结合OH_HiCollie_CancelTimer接口配套使用，应在调用耗时的函数之前使用。<br/>说明：从API version 18开始，支持该接口。 |
| OH_HiCollie_CancelTimer | 取消定时器。<br/>结合OH_HiCollie_SetTimer接口配套使用，执行函数或代码块后使用，OH_HiCollie_CancelTimer通过id将该任务取消；<br/>若未在自定义时间内取消，则执行回调函数，在特定自定义超时动作下，生成故障日志。<br/>说明：从API version 18开始，支持该接口。 |

- API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiCollie](../reference/apis-performance-analysis-kit/capi-hicollie-h.md)。

- 函数执行时间超长故障日志以syswarning-开头，生成在“设备/data/log/faultlog/faultlogger/”路径下。文件名格式为“syswarning-应用包名-应用UID-秒级时间.log”。

## 开发步骤

下文将展示如何在应用内增加一个按钮，并单击该按钮以调用HiCollie Ndk接口。

1. 新建Native C++工程，目录结构如下：

   ```yml
   entry:
     src:
       main:
         cpp:
           types:
             libentry:
               - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
         ets:
           entryability:
             - EntryAbility.ts
           pages:
             - Index.ets
   ```

2. 编辑“CMakeLists.txt”文件，添加源文件及动态库。

   ```cmake
   # 依赖动态库libhilog_ndk.z.so（日志输出），libohhicollie.so（HiCollie对外检测接口）
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. 编辑“napi_init.cpp”文件，导入依赖头文件、定义LOG_TAG与测试方法以及注册TestHiCollieTimerNdk为ArkTS接口。

   ```c++
   #include "napi/native_api.h"
   #include "hicollie/hicollie.h"
   #include "hilog/log.h"
   
   #include <unistd.h>
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   
   //定义回调函数
   void CallBack(void*)
   {
     OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimerNdk CallBack");  // 回调函数中打印日志
   }
   
   static napi_value TestHiCollieTimerNdk(napi_env env, napi_callback_info info)
   {
     int id;
     HiCollie_SetTimerParam param = {"testTimer", 1, CallBack, nullptr, HiCollie_Flag::HICOLLIE_FLAG_LOG};  // 设置HiCollieTimer 参数（Timer任务名，超时时间，回调函数，回调函数参数，超时发生后行为）
     HiCollie_ErrorCode errorCode = OH_HiCollie_SetTimer(param, &id);  // 注册HiCollieTimer函数执行时长超时检测一次性任务
     if (errorCode == HICOLLIE_SUCCESS) {  // HiCollieTimer任务注册成功
       OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimer taskId: %{public}d", id); // 打印任务id
       sleep(2);  // 模拟执行耗时函数，在这里简单的将线程阻塞2s
       OH_HiCollie_CancelTimer(id);  // 根据id取消已注册任务
     }
     return nullptr;
   }
   
   EXTERN_C_START
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "TestHiCollieTimerNdk", nullptr, TestHiCollieTimerNdk, nullptr, nullptr, nullptr, napi_default, nullptr }      // 将TestHiCollieTimerNdk注册为ArkTS接口
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

4. 编辑“index.d.ts”文件，定义ArkTS接口。

   ```ts
   export const TestHiCollieTimerNdk: () => void;
   ```

5. 编辑“Index.ets”文件。

   ```ts
   import testNapi from 'libentry.so';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World';
   
     build() {
       Row() {
         Column() {
           Button("TestHiCollieTimerNdk")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.TestHiCollieTimerNdk);  //添加点击事件，触发testHiCollieTimerNdk方法。
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. 点击DevEco Studio界面中的运行按钮，运行应用工程。

7. 在DevEco Studio的底部，切换到“Log->HiLog”窗口，设置日志的过滤条件为“testTag”。

   （1）点击“testHiCollieTimerNdk”按钮执行程序，日志窗口打印任务id。

   ```
   .../testTag ... HiCollieTimer taskId: x
   ```

   （2）等待2s后，执行回调函数，日志窗口打印。

   ```
   .../testTag ... HiCollieTimerNdk CallBack
   ```

   获取故障文件信息相关内容可参考[订阅任务执行超时事件（C/C++）](hiappevent-watcher-apphicollie-events-ndk.md) 订阅获取。
