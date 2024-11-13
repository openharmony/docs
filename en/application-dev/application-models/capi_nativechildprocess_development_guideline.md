# Native Child Process Development (C/C++)

>**NOTE**
>
> The initial APIs of this module are supported since API version 12. They depend on [IPC Kit](../ipc/ipc-capi-development-guideline.md).

## When to Use

This topic describes how to create a native child process in the main process and establish an IPC channel between the main process and child process. It makes multi-process programming at the native layer easier.

## Available APIs

| Name                                                                                                                                                                                                                                                                                                                               | Description                                                                                   |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_createnativechildprocess) (const char *libName, [OH_Ability_OnNativeChildProcessStarted](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted) onProcessStarted) | Creates a child process, loads a specified dynamic link library, and returns the startup result asynchronously through a callback parameter. An independent thread is used to execute the callback function. When implementing the callback function, pay attention to thread synchronization issues and avoid performing time-consuming operations to prevent extended blocking.|

> **NOTE**
>
> Currently, only 2-in-1 devices are supported, and only one native child process can be started for a process.

## How to Develop

This section describes how to use the C APIs provided by Ability Kit to create a native child process and establish an IPC channel between the main process and child process based on an existing native application development project.

**Dynamic Link Libraries**

```txt
libipc_capi.so
libchild_process.so
```

**Header Files**

```c++
#include <IPCKit/ipc_kit.h>
#include <AbilityKit/native_child_process.h>
```

### 1. Child Process - Implementing Necessary Export Functions

In the child process, implement and export the functions **NativeChildProcess_OnConnect** and **NativeChildProcess_MainProc**. (It is assumed that the code file is named **ChildProcessSample.cpp**.) The **OHIPCRemoteStub** object returned by **NativeChildProcess_OnConnect** is responsible for IPC of the main process. For details, see [IPC Development (C/C++)](../ipc/ipc-capi-development-guideline.md). After the child process is started, **NativeChildProcess_OnConnect** is invoked to obtain an IPC stub object, and then **NativeChildProcess_MainProc** is called to transfer the control right of the main thread. After the second function is returned, the child process exits.

```c++
#include <IPCKit/ipc_kit.h>

extern "C" {

OHIPCRemoteStub* NativeChildProcess_OnConnect()
{
    // ipcRemoteStub points to the IPC stub object implemented by the child process. The object is used to receive and respond to IPC messages from the main process.
    // The child process controls its lifecycle according to the service logic.
    return ipcRemoteStub;
}

void NativeChildProcess_MainProc()
{
    // Equivalent to the Main function of the child process. It implements the service logic of the child process.
    // ...
    // After the function is returned, the child process exits.
}
  
} // extern "C"
```

### 2. Child Process - Compiled as a Dynamic Link Library

Modify the **CMakeList.txt** file, compile the file into a dynamic link library (named **libchildprocesssample.so** in this example), and add the dependency of the IPC dynamic link library.

```txt
add_library(childprocesssample SHARED
    # Source code file that implements the necessary export functions
    ChildProcessSample.cpp
    
    # Other source code files
    # ...
)

target_link_libraries(childprocesssample PUBLIC
    # Add the dependency of the IPC dynamic link library.
    libipc_capi.so
    
    # Dependencies of other dynamic link libraries
    # ...
)
```

### 3. Main Process - Implementing the Child Process Startup Result Callback

```c++
#include <IPCKit/ipc_kit.h>

static void OnNativeChildProcessStarted(int errCode, OHIPCRemoteProxy *remoteProxy)
{
    if (errCode != NCP_NO_ERROR) {
	    // Exception handling when the child process is not started normally.
	    // ...
	    return;
    }

    // Save the remoteProxy object for IPC with the child process based on the APIs provided by IPC Kit.
    // You are advised to transfer time-consuming operations to an independent thread to avoid blocking the callback thread for a long time.
    // When the IPC object is no longer needed, call OH_IPCRemoteProxy_Destroy to release it.
    // ...
}
```

The second parameter **OHIPCRemoteProxy** in the callback function is used to establish an IPC channel with the **OHIPCRemoteStub** object returned by the **NativeChildProcess_OnConnect** method implemented by the child process. For details, see [IPC Development (C/C++)](../ipc/ipc-capi-development-guideline.md). When the **OHIPCRemoteProxy** object is no longer needed, call [OH_IPCRemoteProxy_Destory](../reference/apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy) to release it.

### 4. Main Process - Starting the Native Child Process

Call the API to start the native child process. Note that the return value **NCP_NO_ERROR** only indicates that the native child process startup logic is successfully called. The actual startup result is asynchronously notified through the callback function specified in the second parameter. **A child process can be created only in the main process.**

```c++
#include <AbilityKit/native_child_process.h>

// The first parameter libchildprocesssample.so is the name of the dynamic link library that implements the necessary export functions of the child process.
int32_t ret = OH_Ability_CreateNativeChildProcess("libchildprocesssample.so", OnNativeChildProcessStarted);
if (ret != NCP_NO_ERROR) {
    // Exception handling when the child process is not started normally.
    // ...
}
```

### 5. Main Process - Adding Build Dependencies

Modify the **CMaklist.txt** file to add the dependencies. The following assumes that the main process is implemented in the library file named **libmainprocesssample.so**. (The implementation of the main process and child processes can be compiled to the same dynamic link library file.)

```txt
target_link_libraries(mainprocesssample PUBLIC
    # Add dependencies of the IPC and ability dynamic link library.
    libipc_capi.so
    libchild_process.so
    
    # Dependencies of other dynamic link libraries
    # ...
)
```
