# 使用HiDebug获取调试信息（C/C++）

本模块可用于应用进程的内存、CPU、GPU等相关数据的获取，开启进程trace采集等。由于该模块的接口大多比较耗费性能，接口调用较为耗时，且基于HiDebug模块定义，该模块内的接口仅建议在应用调试，调优阶段使用。若需要在其他场景使用时，请认真评估所需调用的接口对应用性能的影响。

## 接口说明
| 接口名                          | 描述                              |
| ------------------------------- | --------------------------------- |
| OH_HiDebug_GetSystemCpuUsage    | 获取系统的CPU资源占用情况百分比。 |
| OH_HiDebug_GetAppCpuUsage       | 获取进程的CPU使用率百分比。       |
| OH_HiDebug_GetAppThreadCpuUsage | 获取应用所有线程CPU使用情况。     |
| OH_HiDebug_FreeThreadCpuUsage   | 释放线程数据结构。                |
| OH_HiDebug_GetSystemMemInfo     | 获取系统内存信息。                |
| OH_HiDebug_GetAppNativeMemInfo  | 获取应用程序进程的内存信息。      |
| OH_HiDebug_GetAppMemoryLimit    | 获取应用程序进程的内存限制。      |
| OH_HiDebug_StartAppTraceCapture | 启动应用trace采集。               |
| OH_HiDebug_StopAppTraceCapture  | 停止应用trace采集。               |
| OH_HiDebug_GetGraphicsMemory    | 获取应用显存大小。          |

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiDebug](../reference/apis-performance-analysis-kit/_hi_debug.md)。

## 开发步骤
下文将展示如何在应用内增加一个按钮，并单击该按钮以调用HiDebug Ndk接口。

1. 新建Native C++工程，目录结构如下：

   ```yml
   entry:
     src:
       main:
         cpp:
           - types:
               libentry:
                 - index.d.ts
           - CMakeLists.txt
           - napi_init.cpp
         ets:
           - entryability:
               - EntryAbility.ts
           - pages:
               - Index.ets
   ```

2. 编辑"CMakeLists.txt"文件，添加库依赖：

   ```cmake
   # 新增动态库依赖libhiappevent_ndk.z.so和libhilog_ndk.z.so(日志输出)
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhidebug.so)
   ```

3. 编辑"napi_init.cpp"文件，导入依赖的文件，并定义LOG_TAG及测试方法：

   本示例中以OH_HiDebug_GetSystemCpuUsage接口为例，调用该接口并输出返回值，其他接口请参考[HiDebug](../reference/apis-performance-analysis-kit/_hi_debug.md)。

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hidebug/hidebug.h"
   
   #undef LOG_TAG
   #define LOG_TAG "testTag"
   
   static napi_value TestHiDebugNdk(napi_env env, napi_callback_info info)
   {
       double cpuUsage = OH_HiDebug_GetSystemCpuUsage();
       OH_LOG_INFO(LogType::LOG_APP, "GetSystemCpuUsage: %{public}f", cpuUsage);
       return 0;
   }
   ```

4. 将TestHiDebugNdk注册为ArkTS接口：

   编辑"napi_init.cpp"文件，将TestHiDebugNdk注册为ArkTS接口：

   ```c++
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "testHiDebugNdk", nullptr, TestHiDebugNdk, nullptr, nullptr, nullptr, napi_default, nullptr }
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }
   ```

   编辑"index.d.ts"文件，定义ArkTS接口：

   ```typescript
   export const testHiDebugNdk: () => void;
   ```

5. 编辑"Index.ets"文件，给文本Text组件添加一个点击事件，示例代码如下：

   ```ts
   import testNapi from 'libentry.so'
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'
   
     build() {
       Row() {
         Column() {
           Text(this.message)
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.testHiDebugNdk);//添加点击事件，触发testHiDebugNdk方法。
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. 点击DevEco Studio界面中的运行按钮，运行应用工程，点击"Hello world"文本。

7. 在DevEco Studio的底部，切换到“Log”窗口，设置日志的过滤条件为“testTag”。

   此时窗口将显示通过OH_HiDebug_GetSystemCpuUsage()接口获取的CPU使用率的相关日志。

   ```Text
   09-10 09:40:26.755 17221-17221/com.example.myapplication I A00000/testTag: GetSystemCpuUsage: 0.083904
   ```

