# 短时任务(C/C++)开发指导

## 场景介绍

应用退至后台一小段时间后，应用进程会被挂起，无法执行对应的任务。如果应用在后台仍需要执行耗时不长的任务，如状态保存等，可以通过本文申请短时任务，扩展应用在后台的运行时间。

## 接口说明

常用接口如下表所示。


| 接口名 | 描述 |
| -------- | -------- |
| int32_t OH_BackgroundTaskManager_RequestSuspendDelay(const char *reason, TransientTask_Callback callback, TransientTask_DelaySuspendInfo *info); | 申请短时任务。 |
| int32_t OH_BackgroundTaskManager_GetRemainingDelayTime(int32_t requestId, int32_t *delayTime); | 获取对应短时任务的剩余时间。 |
| int32_t OH_BackgroundTaskManager_CancelSuspendDelay(int32_t requestId); | 取消短时任务。 |

### 开发步骤

使用本文档涉及接口申请短时任务时，需先创建Native C++工程，在源文件中将相关接口封装，再在ArkTs层对封装的接口进行调用，使用hilog或者console.log等手段选择打印在控制台或者生成设备日志。

### 添加开发依赖

**添加动态链接库**

CMakeLists.txt中添加以下lib:

```txt
libace_napi.z.so
libtransient_task.so
```

**头文件**

```c
#include "napi/native_api.h"
#include "transient_task/transient_task_api.h"
```

### 构建工程

1、在源文件中编写调用该API的代码，并将结果封装成一个`napi_value`类型的值返回给 Node.js 环境。

```C

TransientTask_DelaySuspendInfo delaySuspendInfo;

static void callback(void)
{
  // 短时任务即将结束，业务在这里取消短时任务
  OH_BackgroundTaskManager_CancelSuspendDelay(delaySuspendInfo.requestId);
}

static napi_value RequestSuspendDelay(napi_env env, napi_callback_info info)
{
    napi_value result;
    int32_t res = OH_BackgroundTaskManager_RequestSuspendDelay("test", callback, &delaySuspendInfo);
    if (res == 0) {
      napi_create_int32(env, delaySuspendInfo.requestId, &result);
    } else {
      napi_create_int32(env, -1, &result);
    }
    return result;
}

static napi_value GetRemainingDelayTime(napi_env env, napi_callback_info info)
{
    napi_value result;
    int32_t delayTime = 0;
    int32_t res = OH_BackgroundTaskManager_GetRemainingDelayTime(delaySuspendInfo.requestId, &delayTime);
    if (res == 0) {
      napi_create_int32(env, delayTime, &result);
    } else {
      napi_create_int32(env, -1, &result);
    }
    return result;
}

static napi_value CancelSuspendDelay(napi_env env, napi_callback_info info)
{
    napi_value result;
    int32_t res = OH_BackgroundTaskManager_CancelSuspendDelay(delaySuspendInfo.requestId);
    napi_create_int32(env, res, &result);
    return result;
}

```

2、将通过napi封装好的`napi_value`类型对象初始化导出，通过外部函数接口，将以上两个函数暴露给JavaScript使用。

```C
EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"RequestSuspendDelay", nullptr, RequestSuspendDelay, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"GetRemainingDelayTime", nullptr, GetRemainingDelayTime, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"CancelSuspendDelay", nullptr, CancelSuspendDelay, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END
```

3、将上一步中初始化成功的对象通过`RegisterEntryModule`函数，使用`napi_module_register`函数将模块注册到 Node.js 中。

```C
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

4、在工程的index.d.ts文件中定义两个函数的类型。

- RequestSuspendDelay 函数不接受参数，返回一个数字类型的值。
- GetRemainingDelayTime 函数不接受参数，返回一个数字类型的值。

```ts
export const RequestSuspendDelay: () => number;
export const GetRemainingDelayTime: () => number;
export const CancelSuspendDelay: () => number;
```

5、在index.ets文件中对上述封装好的接口进行调用

```ts
import testTransientTask from 'libentry.so';

@Entry
@Component
struct Index {
  @State message: string = '';

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button('申请短时任务').onClick(event => {
          this.RequestSuspendDelay();
        })
        Button('获取剩余时间').onClick(event =>{
          this.GetRemainingDelayTime();
        })
        Button('取消短时任务').onClick(event =>{
          this.CancelSuspendDelay();
        })
      }
      .width('100%')
    }
    .height('100%')
  }

  RequestSuspendDelay() {
    let requestId = testTransientTask.RequestSuspendDelay();
    console.log("The return requestId is " + requestId);
  }

  GetRemainingDelayTime() {
    let time = testTransientTask.GetRemainingDelayTime();
    console.log("The time is " + time);
  }

  CancelSuspendDelay() {
    let ret = testTransientTask.CancelSuspendDelay();
    console.log("The ret is " + ret);
  }
}

```

6、配置`CMakeLists.txt`，本模块需要用到的共享库是`libtransient_task.so`，在工程自动生成的`CMakeLists.txt`中的`target_link_libraries`中添加此共享库。

经过以上步骤，整个工程的搭建已经完成，接下来就可以连接设备运行工程进行日志查看了。

## 测试步骤

1、连接设备，使用DevEco Studio打开搭建好的工程

2、运行工程

3、点击 `申请短时任务` 按钮，控制台会打印日志：
```
The return requestId is 1
```

4、点击 `获取剩余时间` 按钮，控制台会打印日志：

```
The return requestId is 18000
```
5、点击 `取消短时任务` 按钮，控制台会打印日志：

```
The ret is 0
```