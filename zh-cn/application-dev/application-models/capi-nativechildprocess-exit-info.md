## 支持获取Native子进程退出信息

### 场景介绍

从API version 20开始，创建子进程后，需要做一些稳定性加固，如子进程异常退出后给用户提示，因此需要在创建子进程后获取子进程的异常退出信息。 **需要强调的是** ，这里能监听的子进程必须是[OH_Ability_StartNativeChildProcess](../application-models/capi_nativechildprocess_development_guideline.md#创建支持参数传递的子进程)或者通过[@ohos.app.ability.childProcessManager的startNativeChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13)创建的子进程。

### 接口说明

| 名称                                                                                                                                                                                                                                                                                                                                | 描述                                                                                    |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| [Ability_NativeChildProcess_ErrCode](../reference/apis-ability-kit/c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_RegisterNativeChildProcessExitCallback](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_registernativechildprocessexitcallback) ([OH_Ability_OnNativeChildProcessExit](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_onnativechildprocessexit) onProcessExit) | 注册子进程退出回调函数。 |
| [Ability_NativeChildProcess_ErrCode](../reference/apis-ability-kit/c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_UnregisterNativeChildProcessExitCallback](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_unregisternativechildprocessexitcallback) ([OH_Ability_OnNativeChildProcessExit](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_onnativechildprocessexit) onProcessExit) | 解注册子进程退出回调函数。 |

### 开发步骤


**动态库文件**

```txt
libchild_process.so
```

**头文件**

```c++
#include <AbilityKit/native_child_process.h>
```

1. 主进程-注册和解注册Native子进程异常退出回调。

    调用API注册Native子进程，返回值为NCP_NO_ERROR代表成功注册Native子进程退出回调。
    调用API解注册Native子进程，返回值为NCP_NO_ERROR代表成功解注册Native子进程退出回调。

    ```c++
    #include <AbilityKit/native_child_process.h>
    void OnNativeChildProcessExit(int32_t pid, int32_t signal) {
        OH_LOG_INFO("pid: %{public}d, signal: %{public}d", pid, signal);
    }

    void RegisterNativeChildProcessExitCallback()
    {
        Ability_NativeChildProcess_ErrCode ret = OH_Ability_RegisterNativeChildProcessExitCallback(OnNativeChidProcessExit);
        if (ret != NCP_NO_ERROR) {
            OH_LOG_ERROR("register failed.");
        }
    }

    void UnregisterNativeChildProcessExitCallback()
    {
        Ability_NativeChildProcess_ErrCode ret = OH_Ability_UnregisterNativeChildProcessExitCallback(OnNativeChidProcessExit);
        if (ret != NCP_NO_ERROR) {
            OH_LOG_ERROR("unregister failed.");
        }
    }
    ```

2. 主进程-添加编译依赖项。

    修改CMaklist.txt添加必要的依赖库，假设主进程所在的so名称为libmainprocesssample.so（主进程和子进程的实现也可以选择编译到同一个动态库文件）。

    ```txt
    target_link_libraries(mainprocesssample PUBLIC
        # 添加依赖的元能力动态库
        libchild_process.so
        
        # 其它依赖的动态库
        # ...
    )
    ```