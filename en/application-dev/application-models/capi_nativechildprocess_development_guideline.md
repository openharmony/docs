# Native Child Process Development (C/C++)

You can create a child process in either of the following ways:
- [Creating a Child Process That Supports IPC Callback](#creating-a-child-process-that-supports-ipc-callback): Create a child process and establish an IPC channel between the parent and child processes. This method applies to scenarios where the parent and child processes require IPC. Its usage depends on [IPC Kit](../ipc/ipc-capi-development-guideline.md).
- [Creating a Child Process That Supports Pass-by-Parameter](#creating-a-child-process-that-supports-pass-by-parameter): Create a child process and pass the string and FD handle parameters to the child process. This method applies to scenarios where parameters need to be passed to child processes.


## Creating a Child Process That Supports IPC Callback

### When to Use

This topic describes how to create a native child process in the main process and establish an IPC channel between the main process and child process. It makes multi-process programming at the native layer easier.

### Available APIs

| Name                                                                                                                                                                                                                                                                                                                               | Description                                                                                   |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_createnativechildprocess) (const char *libName, [OH_Ability_OnNativeChildProcessStarted](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted) onProcessStarted) | Creates a child process, loads a specified dynamic link library, and returns the startup result asynchronously through a callback parameter. An independent thread is used to execute the callback function. When implementing the callback function, pay attention to thread synchronization issues and avoid performing time-consuming operations to prevent extended blocking.|

> **NOTE**
>
> This function is valid only for 2-in-1 devices.
>
> Since API version 15, a single process supports a maximum of 50 native child processes. In API version 14 and earlier versions, a single process supports only one native child process.

### How to Develop

This section describes how to use the C APIs provided by Ability Kit to create a native child process and establish an IPC channel between the main process and child process based on an existing native application development project.

**Linking Dynamic Libraries**

```txt
libipc_capi.so
libchild_process.so
```

**Including Header Files**

```c++
#include <IPCKit/ipc_kit.h>
#include <AbilityKit/native_child_process.h>
```

1. (Child process) Implement necessary export functions.

    In the child process, implement and export the functions **NativeChildProcess_OnConnect** and **NativeChildProcess_MainProc**. (It is assumed that the code file is named **ChildProcessSample.cpp**.) The **OHIPCRemoteStub** object returned by **NativeChildProcess_OnConnect** is responsible for IPC of the main process. For details, see [IPC Development (C/C++)](../ipc/ipc-capi-development-guideline.md).

    After the child process is started, **NativeChildProcess_OnConnect** is invoked to obtain an IPC stub object, and then **NativeChildProcess_MainProc** is called to transfer the control right of the main thread. After the second function is returned, the child process exits.

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

2. (Child process) Compile a dynamic link library.

    Modify the **CMakeList.txt** file, compile the file into a dynamic link library (named **libchildprocesssample.so** in this example), and add the dependency of the dynamic link library of IPC Kit.

    ```txt
    add_library(childprocesssample SHARED
        # Source code file that implements the necessary export functions
        ChildProcessSample.cpp
        
        # Other source code files
        # ...
    )

    target_link_libraries(childprocesssample PUBLIC
        # Add the dependency of the dynamic link library of IPC Kit.
        libipc_capi.so
        
        # Dependencies of other dynamic link libraries
        # ...
    )
    ```

3. (Main process) Implement the child process startup result callback.

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

    The second parameter **OHIPCRemoteProxy** in the callback function is used to establish an IPC channel with the **OHIPCRemoteStub** object returned by the **NativeChildProcess_OnConnect** method implemented by the child process. For details, see [IPC Development (C/C++)](../ipc/ipc-capi-development-guideline.md). When the **OHIPCRemoteProxy** object is no longer needed, call [OH_IPCRemoteProxy_Destroy](../reference/apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy) to release it.

4. (Main process) Start the native child process.

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

5. (Main process) Add build dependencies.

    Modify the **CMaklist.txt** file to add the dependencies. The following assumes that the main process is implemented in the library file named **libmainprocesssample.so**. (The implementation of the main process and child processes can be compiled to the same dynamic link library file.)

    ```txt
    target_link_libraries(mainprocesssample PUBLIC
        # Add dependencies of the dynamic link library of IPC Kit and Ability Kit.
        libipc_capi.so
        libchild_process.so
        
        # Dependencies of other dynamic link libraries
        # ...
    )
    ```

## Creating a Child Process That Supports Pass-by-Parameter

### When to Use

This section describes how to create a native child process and pass parameters to it.

### Available APIs

| Name                                                                                                                                                                                                                                                                                                                               | Description                                                                                   |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| [Ability_NativeChildProcess_ErrCode](../reference/apis-ability-kit/c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_StartNativeChildProcess](../reference/apis-ability-kit/c-apis-ability-childprocess.md#oh_ability_startnativechildprocess) (const char \*entry, [NativeChildProcess_Args](../reference/apis-ability-kit/c-apis-ability-childprocess.md#nativechildprocess_args) args, [NativeChildProcess_Options](../reference/apis-ability-kit/c-apis-ability-childprocess.md#nativechildprocess_options) options, int32_t *pid) | Starts a child process and returns its PID.|

### How to Develop


**Linking Dynamic Libraries**

```txt
libchild_process.so
```

**Including Header Files**

```c++
#include <AbilityKit/native_child_process.h>
```

1. (Child process) Implement necessary export functions.

    In the child process, implement and export the entry function [NativeChildProcess_Args](../reference/apis-ability-kit/c-apis-ability-childprocess.md#nativechildprocess_args). (It is assumed that the code file is named **ChildProcessSample.cpp**.) After the child process is started, the entry function is invoked. After the second function is returned, the child process exits.

    ```c++
    #include <AbilityKit/native_child_process.h>

    extern "C" {

    /**
     * Entry function of a child process, which implements the service logic of the child process.
     * The function name can be customized and is specified when the main process calls the OH_Ability_StartNativeChildProcess method. In this example, the function name is Main.
     * After the function is returned, the child process exits.
     */
    void Main(NativeChildProcess_Args args)
    {
        // Obtain the input entryPrams.
        char *entryParams = args.entryParams;
        // Obtain the input FD list.
        NativeChildProcess_Fd *current = args.fdList.head;
        while (current != nullptr) {
            char *fdName = current->fdName;
            int32_t fd = current->fd;
            current = current->next;
            // Service logic
        }
    }
    } // extern "C"
    ```

2. (Child process) Compile a dynamic link library.

    Modify the **CMakeList.txt** file, compile the file into a dynamic link library (named **libchildprocesssample.so** in this example), and add the dependency of the dynamic link library of Ability Kit.

    ```txt
    add_library(childprocesssample SHARED
        # Source code file that implements the necessary export functions
        ChildProcessSample.cpp
        
        # Other source code files
        # ...
    )

    target_link_libraries(childprocesssample PUBLIC
        # Add the dependency of the dynamic link library of Ability Kit.
        libchild_process.so

        # Dependencies of other dynamic link libraries
        # ...
    )
    ```

3. (Main process) Start the native child process.

    Call the API to start the native child process. The return value **NCP_NO_ERROR** indicates that the native child process is successfully started.

    ```c++
    #include <AbilityKit/native_child_process.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>

    void startNativeChildProcess()
    {
        // ...
        NativeChildProcess_Args args;
        // Set entryParams. The maximum amount of data that can be passed is 150 KB.
        args.entryParams = (char*)malloc(sizeof(char) * 10);
        (void)strcpy(args.entryParams, "testParam");

        // Insert a node to the head node of the linked list.
        args.fdList.head = (NativeChildProcess_Fd*)malloc(sizeof(NativeChildProcess_Fd));
        // FD keyword, which contains a maximum of 20 characters.
        args.fdList.head->fdName = (char*)malloc(sizeof(char) * 4);
        (void)strcpy(args.fdList.head->fdName, "fd1");
        // Obtain the FD logic.
        int32_t fd = open("/data/storage/el2/base/haps/entry/files/test.txt", O_RDWR | O_CREAT, 0644);
        args.fdList.head->fd = fd;
        // Insert only one FD record. You can insert a maximum of 16 FD records to the linked list as required.
        args.fdList.head->next = NULL;
        NativeChildProcess_Options options = {
            .isolationMode = NCP_ISOLATION_MODE_ISOLATED
        };

        // The first parameter libchildprocesssample.so:Main indicates the name of the dynamic link library file that implements the Main method of the child process and the name of the entry method.
        int32_t pid = -1;
        Ability_NativeChildProcess_ErrCode ret = OH_Ability_StartNativeChildProcess(
            "libchildprocesssample.so:Main", args, options, &pid);
        if (ret != NCP_NO_ERROR) {
            // Release the memory space in NativeChildProcess_Args to prevent memory leakage.
            // Exception handling when the child process is not started normally.
            // ...
        }

        // Other logic
        // ...

        // Release the memory space in NativeChildProcess_Args to prevent memory leakage.
    }
    ```

4. (Main process) Add build dependencies.

    Modify the **CMaklist.txt** file to add the dependencies. The following assumes that the main process is implemented in the library file named **libmainprocesssample.so**. (The implementation of the main process and child processes can be compiled to the same dynamic link library file.)

    ```txt
    target_link_libraries(mainprocesssample PUBLIC
        # Add the dependency of the dynamic link library of Ability Kit.
        libchild_process.so
        
        # Dependencies of other dynamic link libraries
        # ...
    )
    ```
