# 获取Native子进程退出信息
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## 场景介绍

从API version 20开始，支持父进程通过注册回调函数监听子进程，获取子进程异常退出信息，以便父进程做后续优化处理。这里支持监听的子进程必须为[OH_Ability_StartNativeChildProcess](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocess)或[startNativeChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13)接口创建的子进程。

## 接口说明

| 名称                                                                                                                                                                                                                                                                                                                                | 描述                                                                                    |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| [Ability_NativeChildProcess_ErrCode](../reference/apis-ability-kit/capi-native-child-process-h.md#ability_nativechildprocess_errcode) [OH_Ability_RegisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_registernativechildprocessexitcallback) ([OH_Ability_OnNativeChildProcessExit](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_onnativechildprocessexit) onProcessExit) | 注册子进程退出回调函数。 |
| [Ability_NativeChildProcess_ErrCode](../reference/apis-ability-kit/capi-native-child-process-h.md#ability_nativechildprocess_errcode) [OH_Ability_UnregisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_unregisternativechildprocessexitcallback) ([OH_Ability_OnNativeChildProcessExit](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_onnativechildprocessexit) onProcessExit) | 解注册子进程退出回调函数。 |

## 开发步骤


**动态库文件**

```txt
libchild_process.so
```

**头文件**

```c++
#include <AbilityKit/native_child_process.h>
```

1. 主进程-注册和解注册Native子进程异常退出回调。

    调用[OH_Ability_RegisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_registernativechildprocessexitcallback)注册Native子进程，如果返回值为NCP_NO_ERROR表示注册成功。
    调用[OH_Ability_UnregisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_unregisternativechildprocessexitcallback)解注册Native子进程，如果返回值为NCP_NO_ERROR表示解注册成功。

    ```c++
    #include <AbilityKit/native_child_process.h>
    void OnNativeChildProcessExit(int32_t pid, int32_t signal) {
        OH_LOG_INFO("pid: %{public}d, signal: %{public}d", pid, signal);
    }

    void RegisterNativeChildProcessExitCallback()
    {
        Ability_NativeChildProcess_ErrCode ret = OH_Ability_RegisterNativeChildProcessExitCallback(OnNativeChildProcessExit);
        if (ret != NCP_NO_ERROR) {
            OH_LOG_ERROR("register failed.");
        }
    }

    void UnregisterNativeChildProcessExitCallback()
    {
        Ability_NativeChildProcess_ErrCode ret = OH_Ability_UnregisterNativeChildProcessExitCallback(OnNativeChildProcessExit);
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
