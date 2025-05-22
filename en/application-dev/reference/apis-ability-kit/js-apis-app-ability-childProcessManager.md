# @ohos.app.ability.childProcessManager (childProcessManager)

The childProcessManager module provides the child process management capability. Currently, it provides APIs to start a child process and is valid only for 2-in-1 devices and tablets.

The created child process does not support the UI or the calling of context-related APIs.

A maximum of 512 child processes can be started through this module (non-SELF_FORK mode) and [ChildProcess](c-apis-ability-childprocess.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { childProcessManager } from '@kit.AbilityKit';
```

## StartMode

Enumerates the child process start modes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                      | Value                            | Description                             |
| --------                     |  -----------------               |  -----------------               |
| SELF_FORK |  0   | The child process is forked from the application process. Binder IPC cannot be called in such a child process. Otherwise, the child process will crash. Asynchronous ArkTS API calls are not supported.|
| APP_SPAWN_FORK |  1   | The child process is forked from AppSpawn. Such a child process does not inherit the parent process resources. It does not have application context and therefore does not support API calls that depend on application context.|

## childProcessManager.startChildProcess

startChildProcess(srcEntry: string, startMode: StartMode): Promise&lt;number&gt;

Creates a child process and invokes the entrypoint method of the child process. This API uses a promise to return the result.

A PID is returned once the child process is created. However, this does not mean that the child process is started. It is started only when [ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart) is successfully called. This API cannot be called by a child process to create its child process.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | Yes| Path of the source file of the child process relative to the root directory **src/main**. The source file can be stored only in the module of the entry type. For example, if the source file of a child process is **src/main/ets/process/DemoProcess.ets** in the entry module, then **srcEntry** is **./ets/process/DemoProcess.ets**.<br>In addition, ensure that the source file of the child process is referenced by other files to prevent it from being optimized by the build tool. (For details, see the sample code below.)|
  | startMode | [StartMode](#startmode) | Yes| Start mode of the child process.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the PID of the child process.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. |
| 16000062  | The number of child processes exceeds the upper limit. |

**Example**

```ts
// Create the child process class DemoProcess.ets in src/main/ets/process of the entry module.
// entry/src/main/ets/process/DemoProcess.ets
import { ChildProcess } from '@kit.AbilityKit';

export default class DemoProcess extends ChildProcess {
  onStart() {
    console.log("DemoProcess OnStart() called");
  }
}
```

<!--code_no_check-->
```ts
// Call childProcessManager.startChildProcess to start the child process.
// entry/src/main/ets/tool/Tool.ets
import { childProcessManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import DemoProcess from '../process/DemoProcess';

try {
  DemoProcess.toString(); // Call any API of the DemoProcess class to prevent the code from being directly optimized by the compiler because it is not being referenced.
  childProcessManager.startChildProcess("./ets/process/DemoProcess.ets", childProcessManager.StartMode.SELF_FORK)
    .then((data) => {
      console.log(`startChildProcess success, pid: ${data}`);
    }, (err: BusinessError) => {
      console.error(`startChildProcess error, errorCode: ${err.code}`);
    })
} catch (err) {
  console.error(`startChildProcess error, errorCode: ${(err as BusinessError).code}`);
}
```

## childProcessManager.startChildProcess

startChildProcess(srcEntry: string, startMode: StartMode, callback: AsyncCallback&lt;number&gt;): void

Creates a child process and invokes the entrypoint method of the child process. This API uses an asynchronous callback to return the result.

A PID is returned once the child process is created. However, this does not mean that the child process is started. It is started only when [ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart) is successfully called. This API cannot be called by a child process to create its child process.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | Yes| Path of the source file of the child process relative to the root directory **src/main**. The source file can be stored only in the module of the entry type. For example, if the source file of a child process is **src/main/ets/process/DemoProcess.ets** in the entry module, then **srcEntry** is **./ets/process/DemoProcess.ets**.<br>In addition, ensure that the source file of the child process is referenced by other files to prevent it from being optimized by the build tool. (For details, see the sample code below.)|
  | startMode | [StartMode](#startmode) | Yes| Start mode of the child process.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the subprocess is started, **err** is **undefined** and **data** is the PID of the child process. Otherwise, **data** is an error object.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. |
| 16000062  | The number of child processes exceeds the upper limit. |

**Example**

```ts
// Create the child process class DemoProcess.ets in src/main/ets/process of the entry module.
// entry/src/main/ets/process/DemoProcess.ets
import { ChildProcess } from '@kit.AbilityKit';

export default class DemoProcess extends ChildProcess {
  onStart() {
    console.log("DemoProcess OnStart() called");
  }
}
```

<!--code_no_check-->
```ts
// Call childProcessManager.startChildProcess to start the child process.
// entry/src/main/ets/tool/Tool.ets
import { childProcessManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import DemoProcess from '../process/DemoProcess';

try {
  DemoProcess.toString(); // Call any API of the DemoProcess class to prevent the code from being directly optimized by the compiler because it is not being referenced.
  childProcessManager.startChildProcess("./ets/process/DemoProcess.ets", childProcessManager.StartMode.SELF_FORK, (err, data) => {
    if (data) {
      console.log(`startChildProcess success, pid: ${data}`);
    } else {
      console.error(`startChildProcess error, errorCode: ${err.code}`);
    }
  });
} catch (err) {
  console.error(`startChildProcess error, errorCode: ${(err as BusinessError).code}`);
}
```

## childProcessManager.startArkChildProcess<sup>12+</sup>

startArkChildProcess(srcEntry: string, args: ChildProcessArgs, options?: ChildProcessOptions): Promise&lt;number&gt;

Creates a child process and invokes the entrypoint method of the child process. This API uses a promise to return the result.

The child process does not inherit the resources of the parent process. A PID is returned once the child process is created. However, this does not mean that the child process is started. It is started only when [ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart) is successfully called. This API cannot be called by a child process to create its child process.

The child process supports parameter transfer and asynchronous ArkTS API calls (except for some APIs that depend on application context). After [ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart) is called, the child process will not be automatically destroyed. Instead, you must call [process.abort](../apis-arkts/js-apis-process.md#processabort) to destroy the child process. After the main process is destroyed, the child processes are also destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | Yes| Path of the source file of the child process relative to the root directory **src/main**. The source file cannot be stored in the module of the HAR type. The value consists of a module name, a slash (/), and a file path. For example, if the child process file is **src/main/ets/process/DemoProcess.ets** in module1, then **srcEntry** is **module1/./ets/process/DemoProcess.ets**.<br>In addition, ensure that the source file of the child process is referenced by other files to prevent it from being optimized by the build tool. (For details, see the sample code below.)|
  | args | [ChildProcessArgs](js-apis-app-ability-childProcessArgs.md) | Yes| Parameters transferred to the child process.|
  | options | [ChildProcessOptions](js-apis-app-ability-childProcessOptions.md) | No| Startup configuration of the child process.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the PID of the child process.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 801 | Capability not supported. |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. The API cannot be called in a child process. |
| 16000062  | The number of child processes exceeds the upper limit. |

**Example**

Sample code for the child process:

```ts
// Create the child process class DemoProcess.ets in src/main/ets/process of module1.
// module1/src/main/ets/process/DemoProcess.ets
import { ChildProcess, ChildProcessArgs } from '@kit.AbilityKit';

export default class DemoProcess extends ChildProcess {

  onStart(args?: ChildProcessArgs) {
    let entryParams = args?.entryParams;
    let fd = args?.fds?.key1;
    // ..
  }
}
```

Sample code for the main process is provided below. For details about how to obtain the context in the example, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

<!--code_no_check-->
```ts
// Call childProcessManager.startArkChildProcess to start the child process.
// module1/src/main/ets/tool/Tool.ets
import { common, ChildProcessArgs, ChildProcessOptions, childProcessManager } from '@kit.AbilityKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import DemoProcess from '../process/DemoProcess';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Text('Click')
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            try {
              DemoProcess.toString(); // Call any API of the DemoProcess class to prevent the code from being directly optimized by the compiler because it is not being referenced.
              let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
              let path = context.filesDir + "/test.txt";
              let file = fileIo.openSync(path, fileIo.OpenMode.READ_ONLY | fileIo.OpenMode.CREATE);
              let args: ChildProcessArgs = {
                entryParams: "testParam",
                fds: {
                  "key1": file.fd
                }
              };
              let options: ChildProcessOptions = {
                isolationMode: false
              };
              childProcessManager.startArkChildProcess("module1/./ets/process/DemoProcess.ets", args, options)
                .then((pid) => {
                  console.info(`startChildProcess success, pid: ${pid}`);
                })
                .catch((err: BusinessError) => {
                  console.error(`startChildProcess business error, errorCode: ${err.code}, errorMsg:${err.message}`);
                })
            } catch (err) {
              console.error(`startChildProcess error, errorCode: ${err.code}, errorMsg:${err.message}`);
            }
          });
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## childProcessManager.startNativeChildProcess<sup>13+</sup>

startNativeChildProcess(entryPoint: string, args: ChildProcessArgs, options?: ChildProcessOptions): Promise&lt;number&gt;

Starts a native child process, loads the specified dynamic library file, and calls the entry function. This API uses a promise to return the result.

The child process does not inherit the resources of the parent process. A PID is returned once the child process is created. However, this does not mean that the entry function is successfully called, which depends on the execution result of the entry function of the child process. This API cannot be called by a child process to create its child process. It cannot be called to create a child process in an ArkTS basic runtime environment.

After the entry function is executed, the child process is automatically destroyed. After the main process is destroyed, the child processes are also destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | entryPoint | string | Yes| The symbol and entry function of the dynamic link library called in the child process are separated by a colon (:), for example, **libentry.so:Main**.|
  | args | [ChildProcessArgs](js-apis-app-ability-childProcessArgs.md) | Yes| Parameters transferred to the child process.|
  | options | [ChildProcessOptions](js-apis-app-ability-childProcessOptions.md) | No| Startup configuration of the child process.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the PID of the child process.|

**Error codes**

  For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. The API cannot be called in a child process. |
| 16000062  | The number of child processes exceeds the upper limit. |

**Example**

Sample code for the child process is provided below. For details, see [Native Child Process Development (C/C++) - Creating a Child Process That Supports Pass-by-Parameter](../../application-models/capi_nativechildprocess_development_guideline.md#creating-a-child-process-that-supports-pass-by-parameter).

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
    // Obtain the input FD list, corresponding to args.fds in ChildProcessArgs.
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

Sample code for the main process is provided below. For details about how to obtain the context in the example, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

```ts
// Main process:
// Call childProcessManager.startNativeChildProcess to start the child process.
import { common, ChildProcessArgs, ChildProcessOptions, childProcessManager } from '@kit.AbilityKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Text('Click')
          .fontSize(30)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            try {
              let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
              let path = context.filesDir + "/test.txt";
              let file = fileIo.openSync(path, fileIo.OpenMode.READ_ONLY | fileIo.OpenMode.CREATE);
              let args: ChildProcessArgs = {
                entryParams: "testParam",
                fds: {
                  "key1": file.fd
                }
              };
              let options: ChildProcessOptions = {
                isolationMode: false
              };
              childProcessManager.startNativeChildProcess("libentry.so:Main", args, options)
                .then((pid) => {
                  console.info(`startChildProcess success, pid: ${pid}`);
                })
                .catch((err: BusinessError) => {
                  console.error(`startChildProcess business error, errorCode: ${err.code}, errorMsg:${err.message}`);
                })
            } catch (err) {
              console.error(`startChildProcess error, errorCode: ${err.code}, errorMsg:${err.message}`);
            }
          });
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
