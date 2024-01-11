# @ohos.app.ability.childProcessManager (childProcessManager)

The **childProcessManager** module provides the child process management capability. Currently, it provides APIs to start the child process and is available only for tablets.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import childProcessManager from '@ohos.app.ability.childProcessManager';
```

## childProcessManager.StartMode

Enumerates the child process start modes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                      | Value                            | Description                             |
| --------                     |  -----------------               |  -----------------               |
| SELF_FORK |  0   | The child process is forked from the application process. Binder IPC cannot be called in such a child process. Otherwise, the child process will crash.|
| APP_SPAWN_FORK |  1   | The child process is forked from AppSpawn. Such a child process does not inherit the parent process resources. It does not have application context and therefore does not support API calls that depend on application context.|

## childProcessManager.startChildProcess

startChildProcess(srcEntry: string, startMode: StartMode): Promise&lt;number&gt;;

Creates a child process and invokes the entrypoint method of the child process. This API uses a promise to return the result. A PID is returned once the child process is created. However, this does not mean that the child process is started. It is started only when the entrypoint method of the child process is successfully invoked. This API cannot be called by a child process to create its child process.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | Yes| Relative path of the source file of the child process. (The source file must be stored in **src/main**. For details, see the sample code below.) Currently, source files can be stored only in modules of the entry type.|
  | startMode | [StartMode](#childprocessmanagerstartmode) | Yes| Start mode of the child process.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the PID of the child process.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. |
| 16000062  | The number of child process exceeds upper bound. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
// Create the child process class DemoProcess.ts in src/main/ets/process of the entry module.
import ChildProcess from '@ohos.app.ability.ChildProcess';

export default class DemoProcess extends ChildProcess {
  onStart() {
    console.log("DemoProcess OnStart() called");
  }
}
```

```ts
// Call childProcessManager.startChildProcess to start the child process.
import childProcessManager from '@ohos.app.ability.childProcessManager';
import DemoProcess from '../process/DemoProcess';
import { BusinessError } from '@ohos.base';

try {
  DemoProcess.toString(); // Call any API of the DemoProcess class to prevent the code from being directly optimized by the compiler because it is not being referenced.
  childProcessManager.startChildProcess("./ets/process/DemoProcess.ts", childProcessManager.StartMode.SELF_FORK)
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

startChildProcess(srcEntry: string, startMode: StartMode, callback: AsyncCallback&lt;number&gt;): void;

Creates a child process and invokes the entrypoint method of the child process. This API uses an asynchronous callback to return the result. A PID is returned once the child process is created. However, this does not mean that the child process is started. It is started only when the entrypoint method of the child process is successfully invoked. This API cannot be called by a child process to create its child process.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | Yes| Relative path of the source file of the child process. (The source file must be stored in **src/main**. For details, see the sample code below.) Currently, source files can be stored only in modules of the entry type.|
  | startMode | [StartMode](#childprocessmanagerstartmode) | Yes| Start mode of the child process.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the PID of the child process.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. |
| 16000062  | The number of child process exceeds upper bound. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
// Create the child process class DemoProcess.ts in src/main/ets/process of the entry module.
import ChildProcess from '@ohos.app.ability.ChildProcess';

export default class DemoProcess extends ChildProcess {
  onStart() {
    console.log("DemoProcess OnStart() called");
  }
}
```

```ts
// Call childProcessManager.startChildProcess to start the child process.
import childProcessManager from '@ohos.app.ability.childProcessManager';
import DemoProcess from '../process/DemoProcess';
import { BusinessError } from '@ohos.base';

try {
  DemoProcess.toString(); // Call any API of the DemoProcess class to prevent the code from being directly optimized by the compiler because it is not being referenced.
  childProcessManager.startChildProcess("./ets/process/DemoProcess.ts", childProcessManager.StartMode.SELF_FORK, (err, data) => {
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
