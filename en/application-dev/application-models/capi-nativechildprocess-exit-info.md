# Obtaining Exit Information of Native Child Processes
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## When to Use

Starting from API version 20, parent processes can register a callback function to monitor child processes and obtain their abnormal exit information, facilitating further optimizations by the parent process. The child processes to be monitored must be created by calling [OH_Ability_StartNativeChildProcess](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_startnativechildprocess) or [startNativeChildProcess](../reference/apis-ability-kit/js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13).

## Available APIs

| Name                                                                                                                                                                                                                                                                                                                               | Description                                                                                   |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| [Ability_NativeChildProcess_ErrCode](../reference/apis-ability-kit/capi-native-child-process-h.md#ability_nativechildprocess_errcode) [OH_Ability_RegisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_registernativechildprocessexitcallback) ([OH_Ability_OnNativeChildProcessExit](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_onnativechildprocessexit) onProcessExit) | Registers a callback function for detecting abnormal exit of a native child process.|
| [Ability_NativeChildProcess_ErrCode](../reference/apis-ability-kit/capi-native-child-process-h.md#ability_nativechildprocess_errcode) [OH_Ability_UnregisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_unregisternativechildprocessexitcallback) ([OH_Ability_OnNativeChildProcessExit](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_onnativechildprocessexit) onProcessExit) | Unregisters the callback function used for detecting abnormal exit of a native child process.|

## How to Develop


**Linking Dynamic Libraries**

```txt
libchild_process.so
```

**Including Header Files**

```c++
#include <AbilityKit/native_child_process.h>
```

1. (Main process) Register and unregister the callback for abnormal exit of native child processes.

    Call [OH_Ability_RegisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_registernativechildprocessexitcallback) to register a callback for detecting child process exits. If the return value is **NCP_NO_ERROR**, the registration is successful.
    Call [OH_Ability_UnregisterNativeChildProcessExitCallback](../reference/apis-ability-kit/capi-native-child-process-h.md#oh_ability_unregisternativechildprocessexitcallback) to unregister the callback used for detecting child process exits. If the return value is **NCP_NO_ERROR**, the unregistration is successful.

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

2. (Main process) Add build dependencies.

    Modify the **CMaklist.txt** file to add the dependencies. The following assumes that the main process is implemented in the library file named **libmainprocesssample.so**. (The implementation of the main process and child processes can be compiled to the same dynamic link library file.)

    ```txt
    target_link_libraries(mainprocesssample PUBLIC
        # Add the dependency of the dynamic link library of Ability Kit.
        libchild_process.so
        
        # Dependencies of other dynamic link libraries
        # ...
    )
    ```
