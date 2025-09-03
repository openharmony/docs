# @ohos.app.ability.childProcessManager (Child Process Management)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The childProcessManager module provides the child process management capability. Currently, it provides APIs to create and start a child process

The created child process will exit when the parent process exits and cannot run independently.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Constraints

- The APIs of this module work only for 2-in-1 devices and tablets.

- The child processes created through the APIs of this module have the following restrictions:
  - The created child process does not support the creation of UIs. 
  - The created child process does not support API calls that depend on the Context module (including the APIs of the Context module and the APIs that use the Context instance as an input parameter). 
  - The created child process does not support the creation of its own child process. 
  
- A maximum of 512 child processes can be started by using the APIs of this module and the APIs defined in [native_child_process.h](capi-native-child-process-h.md) (as long as system resources are sufficient). The child processes started by [startChildProcess](#childprocessmanagerstartchildprocess) in SELF_FORK mode are not counted.

## Modules to Import

```ts
import { childProcessManager } from '@kit.AbilityKit';
```

## StartMode

Enumerates the child process start modes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                      | Value                            | Description                             |
| --------                     |  -----------------               |  -----------------               |
| SELF_FORK |  0   | The child process is forked from the application process. The child process started in this mode inherits the resources of the parent process and cannot use Binder IPC to communicate with other processes. Otherwise, the child process will crash.|
| APP_SPAWN_FORK |  1   | The child process is forked from AppSpawn. The child process started in this mode does not inherit the resources of the parent process and can use Binder IPC to communicate with other processes.|

## childProcessManager.startChildProcess

startChildProcess(srcEntry: string, startMode: StartMode): Promise&lt;number&gt;

Starts an [ArkTS child process](../../application-models/ability-terminology.md#arkts-child-process). This API uses a promise to return the result.


> **NOTE**
> 
> If the child process is created successfully, its PID is returned, and its [ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart) function is executed. Once the function is done, the child process is automatically destroyed.
>
> The child process started by calling this API does not support asynchronous ArkTS API calls. It supports only synchronous ArkTS API calls.

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

Starts an [ArkTS child process](../../application-models/ability-terminology.md#arkts-child-process). This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> If the child process is created successfully, its PID is returned, and its [ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart) function is executed. Once the function is done, the child process is automatically destroyed.
>
> The child process started by calling this API does not support asynchronous ArkTS API calls. It supports only synchronous ArkTS API calls.

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

Starts an [ArkTS child process](../../application-models/ability-terminology.md#arkts-child-process). This API uses a promise to return the result.


> **NOTE**
>
> The child process started by calling this API does not inherit the resources of the parent process. If the child process is created successfully, its PID is returned, and its [ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart) function is executed. After the function is done, the child process is not automatically destroyed. Instead, it must be destroyed by calling [process.abort](../apis-arkts/js-apis-process.md#processabort). After the process that calls this API is destroyed, the created child process is also destroyed.


**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | Yes| Path of the source file of the child process relative to the root directory **src/main**. The source file cannot be stored in the module of the HAR type. The value consists of a module name, a slash (/), and a file path. For example, if the child process file is **src/main/ets/process/DemoProcess.ets** in module1, then **srcEntry** is **module1/ets/process/DemoProcess.ets**.<br>In addition, ensure that the source file of the child process is referenced by other files to prevent it from being optimized by the build tool. (For details, see the sample code below.)|
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
| 16000061  | Operation not supported. |
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
              childProcessManager.startArkChildProcess("module1/ets/process/DemoProcess.ets", args, options)
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

Starts a [native child process](../../application-models/ability-terminology.md#native-child-process). This API uses a promise to return the result.

> **NOTE**
> 
> The child process started by calling this API does not inherit the resources of the parent process. After the child process is created, its PID is returned, the dynamic link library file specified in the parameters is loaded, and the entry function of the child process is executed. Once the entry function is done, the child process is automatically destroyed. After the process that calls this API is destroyed, the created child process is also destroyed.

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
| 16000061  | Operation not supported. |
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
