# 使用HiCollie监控函数执行时间超长问题（C/C++）

HiCollie模块对外提供函数执行时间超长的检测机制。

## 接口说明

| 接口名                          | 描述                              |
| ------------------------------  | --------------------------------- |
| OH_HiCollie_SetTimer | 启动函数执行时长检测定时器。调用耗时的函数或代码块之前，应该使用此函数。          |
| OH_HiCollie_CancelTimer | 取消函数执行时长检测定时器。调用耗时的函数或代码块之后，应该使用此函数。       |

> **说明：**
>
> 函数执行超时故障日志：
> 1. APP_HICOLLIE-进程号-时间.log，生成在“设备/data/log/eventlog/”路径下；
> 2. syswarning-应用包名-应用UID-秒级时间，生成在”设备/data/log/faultlog/faultlogger/”路径下。

API接口的具体使用说明（参数使用限制、具体取值范围等）请参考[HiCollie](../reference/apis-performance-analysis-kit/_hi_collie.md)。

## 开发步骤

下文将展示如何在应用内增加一个按钮，并单击该按钮以调用HiCollie Ndk接口。

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

2. 编辑"CMakeLists.txt"文件，添加源文件及动态库：

   ```cmake
   # 依赖动态库libhilog_ndk.z.so(日志输出)，libohhicollie.so（HiCollie对外检测接口）
   target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so libohhicollie.so)
   ```

3. 编辑"napi_init.cpp"文件，导入依赖的文件，并定义LOG_TAG及测试方法：

   ```c++
    #include "napi/native_api.h"
    #include "hicollie/hicollie.h"
    #include "hilog/log.h"

    #include <unistd.h>

    #undef LOG_TAG
    #define LOG_TAG "testTag"

    //定义回调函数
    void CallBack(void* callBackParam)
    {
      int* num = reinterpret_cast<int*> (callBackParam);
      OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimerNdk callBackParam: %{public}d", *num);  // 回调函数中打印日志
      delete num;
    }

    static napi_value TestHiCollieTimerNdk(napi_env env, napi_callback_info info)
    {
      int id;
      int* callBackParam = new int(2024);
      HiCollie_SetTimerParam param = {"testTimer", 1, CallBack, callBackParam, HiCollie_Flag::HICOLLIE_FLAG_LOG};  // 设置HiCollieTimer 参数（Timer任务名，超时时间，回调函数，回调函数参数，超时发生后行为）
      HiCollie_ErrorCode errorCode = OH_HiCollie_SetTimer(param, &id);  // 注册HiCollieTimer函数执行时长超时检测一次性任务
      if (errorCode == HICOLLIE_SUCCESS) {  // HiCollieTiimer任务注册成功
        OH_LOG_INFO(LogType::LOG_APP, "HiCollieTimer taskId: %{public}d", id); // 打印任务id
        sleep(2);  // 模拟执行耗时函数，在这里简单的将线程阻塞2s
        OH_HiCollie_CancelTimer(id);  // 根据id取消已注册任务
      }
      delete callBackParam;
      return 0;
    }
   ```

4. 将TestHiCollieTimerNdk注册为ArkTS接口：

   编辑"napi_init.cpp"文件，将TestHiCollieTimerNdk注册为ArkTS接口：

   ```c++
    static napi_value Init(napi_env env, napi_value exports)
    {
        napi_property_descriptor desc[] = {
            { "testHiCollieTimerNdk", nullptr, TestHiCollieTimerNdk, nullptr, nullptr, nullptr, napi_default, nullptr }
        };
        napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
        return exports;
    }
   ```

   编辑"index.d.ts"文件，定义ArkTS接口：

   ```typescript
   export const testHiCollieTimerNdk: () => void;
   ```

5. 编辑"Index.ets"文件：

   ```ts
   import testNapi from 'libentry.so'
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'Hello World'
   
     build() {
       Row() {
         Column() {
           Button("testHiCollieTimerNdk")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
             .onClick(testNapi.testHiCollieTimerNdk);  //添加点击事件，触发testHiCollieTimerNdk方法。
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

6. 点击IDE界面中的运行按钮，运行应用工程。

7. 在DevEco Studio的底部，切换到“Log”窗口，设置日志的过滤条件为“testTag”；
   
   点击“testHiCollieTimerNdk”按钮执行程序，此时日志窗口打印任务id；等待2s后，日志窗口打印回调函数内容；
   
   生成函数执行超时故障文件：data/log/eventlog/APP_HICOLLIE-进程号-时间.log 及 syswarning-应用包名-应用UID-秒级时间。
