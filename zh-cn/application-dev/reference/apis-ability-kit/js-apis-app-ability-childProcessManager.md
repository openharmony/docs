# @ohos.app.ability.childProcessManager (childProcessManager)

childProcessManager模块提供子进程管理能力，支持子进程启动操作。当前仅支持2in1、tablet设备。

创建的子进程不支持UI界面，也不支持Context相关的接口调用。通过此模块（非SELF_FORK模式）和[ChildProcess](c-apis-ability-childprocess.md)启动的子进程总数最大为512个。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { childProcessManager } from '@kit.AbilityKit';
```

## StartMode

子进程启动模式枚举。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                       | 值                             | 说明                              |
| --------                     |  -----------------               |  -----------------               |
| SELF_FORK |  0   | 从App自身进程Fork子进程。以该模式启动的子进程中不能进行Binder IPC调用，会导致子进程Crash。不支持异步ArkTS API调用。 |
| APP_SPAWN_FORK |  1   | 从AppSpawn Fork子进程。以该模式启动的子进程不会继承父进程资源，且没有ApplicationContext，子进程中不支持依赖ApplicationContext的API调用。 |

## childProcessManager.startChildProcess

startChildProcess(srcEntry: string, startMode: StartMode): Promise&lt;number&gt;

启动子进程，并调用子进程的入口方法。使用Promise异步回调。

创建子进程成功会返回子进程pid，但并不代表入口方法调用成功，具体结果以[ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart)方法是否调用成功为准。子进程中不支持再次创建子进程。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | 是 | 子进程源文件路径，只支持源文件放在entry类型的模块中，以src/main为根目录。例如子进程文件在entry模块下src/main/ets/process/DemoProcess.ets，则srcEntry为"./ets/process/DemoProcess.ets"。<br/>另外，需要确保子进程源文件被其它文件引用到，防止被构建工具优化掉。（详见下方示例代码） |
  | startMode | [StartMode](#startmode) | 是 | 子进程启动模式。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise对象，返回子进程pid。 |

**错误码**：

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. |
| 16000062  | The number of child processes exceeds the upper limit. |

**示例：**

```ts
// 在entry模块的src/main/ets/process下创建DemoProcess.ets子进程类:
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
// 使用childProcessManager.startChildProcess方法启动子进程:
// entry/src/main/ets/tool/Tool.ets
import { childProcessManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import DemoProcess from '../process/DemoProcess';

try {
  DemoProcess.toString(); // 这里要调用下DemoProcess类的任意方法，防止没有引用到而被构建工具优化掉
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

启动子进程，并调用子进程的入口方法。使用callback异步回调。

创建子进程成功会返回子进程pid，但并不代表入口方法调用成功，具体结果以[ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart)方法是否调用成功为准。子进程中不支持再次创建子进程。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | 是 | 子进程源文件路径，只支持源文件放在entry类型的模块中，以src/main为根目录。例如子进程文件在entry模块下src/main/ets/process/DemoProcess.ets，则srcEntry为"./ets/process/DemoProcess.ets"。<br/>另外，需要确保子进程源文件被其它文件引用到，防止被构建工具优化掉。（详见下方示例代码） |
  | startMode | [StartMode](#startmode) | 是 | 子进程启动模式。 |
  | callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。当子进程启动成功，err为undefined，data为获取到的子进程pid；否则为错误对象。 |

**错误码**：

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. |
| 16000062  | The number of child processes exceeds the upper limit. |

**示例：**

```ts
// 在entry模块的src/main/ets/process下创建DemoProcess.ets子进程类:
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
// 使用childProcessManager.startChildProcess方法启动子进程:
// entry/src/main/ets/tool/Tool.ets
import { childProcessManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import DemoProcess from '../process/DemoProcess';

try {
  DemoProcess.toString(); // 这里要调用下DemoProcess类的任意方法，防止没有引用到而被构建工具优化掉
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

启动子进程，并调用子进程的入口方法。使用Promise异步回调。

子进程不会继承父进程资源。创建子进程成功会返回子进程pid，但并不代表入口方法调用成功，具体结果以[ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart)方法是否调用成功为准。子进程中不支持再次创建子进程。

子进程支持传参和异步ArkTS API调用（部分依赖ApplicationContext的API除外）。[ChildProcess.onStart](js-apis-app-ability-childProcess.md#childprocessonstart)方法执行完后子进程不会自动销毁，需要子进程调用[process.abort](../apis-arkts/js-apis-process.md#processabort)销毁。主进程销毁后子进程也会一并销毁。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | 是 | 子进程源文件路径，不支持源文件放在HAR类型的模块中。由“模块名” + “/” + “文件路径”组成，文件路径以src/main为根目录。例如子进程文件在module1模块下src/main/ets/process/DemoProcess.ets，则srcEntry为"module1/./ets/process/DemoProcess.ets"。<br/>另外，需要确保子进程源文件被其它文件引用到，防止被构建工具优化掉。（详见下方示例代码） |
  | args | [ChildProcessArgs](js-apis-app-ability-childProcessArgs.md) | 是 | 传递到子进程的参数。 |
  | options | [ChildProcessOptions](js-apis-app-ability-childProcessOptions.md) | 否 | 子进程的启动配置选项。|

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise对象，返回子进程pid。 |

**错误码**：

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 801 | Capability not supported. |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. The API cannot be called in a child process. |
| 16000062  | The number of child processes exceeds the upper limit. |

**示例：**

子进程部分：

```ts
// 在module1模块的src/main/ets/process下创建DemoProcess.ets子进程类:
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

主进程部分，示例中的context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)：

<!--code_no_check-->
```ts
// 使用childProcessManager.startArkChildProcess方法启动子进程:
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
              DemoProcess.toString(); // 这里要调用下DemoProcess类的任意方法，防止没有引用到而被构建工具优化掉
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

启动Native子进程，加载参数中指定的动态链接库文件并调用入口函数。使用Promise异步回调。

子进程不会继承父进程资源。创建子进程成功会返回子进程pid，但并不代表入口函数调用成功，具体结果以子进程的入口函数是否调用成功为准。子进程中不支持再次创建子进程，且不支持创建ArkTS基础运行时环境。

入口函数执行完后子进程会自动销毁。主进程销毁后子进程也会一并销毁。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | entryPoint | string | 是 | 子进程中调用动态库的符号和入口函数，中间用“:”隔开（例如“libentry.so:Main”)。 |
  | args | [ChildProcessArgs](js-apis-app-ability-childProcessArgs.md) | 是 | 传递到子进程的参数。 |
  | options | [ChildProcessOptions](js-apis-app-ability-childProcessOptions.md) | 否 | 子进程的启动配置选项。|

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise对象，返回子进程pid。 |

**错误码**：

  以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. The API cannot be called in a child process. |
| 16000062  | The number of child processes exceeds the upper limit. |

**示例：**

子进程部分，详见[Native子进程开发指导（C/C++）- 创建支持参数传递的子进程](../../application-models/capi_nativechildprocess_development_guideline.md#创建支持参数传递的子进程)：

```c++
#include <AbilityKit/native_child_process.h>

extern "C" {

/**
 * 子进程的入口函数，实现子进程的业务逻辑
 * 函数名称可以自定义，在主进程调用OH_Ability_StartNativeChildProcess方法时指定，此示例中为Main
 * 函数返回后子进程退出
 */
void Main(NativeChildProcess_Args args)
{
    // 获取传入的entryPrams
    char *entryParams = args.entryParams;
    // 获取传入的fd列表，对应ChildProcessArgs中的args.fds
    NativeChildProcess_Fd *current = args.fdList.head;
    while (current != nullptr) {
        char *fdName = current->fdName;
        int32_t fd = current->fd;
        current = current->next;
        // 业务逻辑..
    }
}
} // extern "C"
```

主进程部分，示例中的context的获取方式请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)：

```ts
// 主进程：
// 使用childProcessManager.startNativeChildProcess方法启动子进程:
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