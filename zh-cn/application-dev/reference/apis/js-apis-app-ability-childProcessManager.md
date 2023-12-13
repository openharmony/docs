# @ohos.app.ability.childProcessManager (childProcessManager)

childProcessManager模块提供子进程管理能力，支持子进程启动操作。该模块仅平板类设备可用。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import childProcessManager from '@ohos.app.ability.childProcessManager';
```

## childProcessManager.StartMode

子进程启动模式枚举。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                       | 值                             | 说明                              |
| --------                     |  -----------------               |  -----------------               |
| SELF_FORK |  0   | 从App自身进程Fork子进程。以该模式启动的子进程中不能进行Binder IPC调用，会导致子进程Crash。 |
| APP_SPAWN_FORK |  1   | 从AppSpawn Fork子进程。以该模式启动的子进程不会继承父进程资源，且没有ApplicationContext，子进程中不支持依赖ApplicationContext的API调用。 |

## childProcessManager.startChildProcess

startChildProcess(srcEntry: string, startMode: StartMode): Promise&lt;number&gt;;

启动子进程，并调用子进程的入口方法，以Promise方式返回执行结果。创建子进程成功会返回子进程pid，但并不代表入口方法调用成功，具体结果以入口方法是否调用成功为准。子进程中不支持再次调用该方法创建子进程。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | 是 | 子进程源文件相对路径（源文件需要放在src/main中，详见下方示例代码）。目前只支持源文件放在entry类型的模块中。 |
  | startMode | [StartMode](#childprocessmanagerstartmode) | 是 | 子进程启动模式。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;number&gt; | 以Promise的形式返回子进程pid。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. |
| 16000062  | The number of child process exceeds upper bound. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

**示例：**

```ts
// 在entry模块的src/main/ets/process下创建DemoProcess.ts子进程类:
import ChildProcess from '@ohos.app.ability.ChildProcess';

export default class DemoProcess extends ChildProcess {
  onStart() {
    console.log("DemoProcess OnStart() called");
  }
}

// 使用childProcessManager.startChildProcess方法启动子进程:
import childProcessManager from '@ohos.app.ability.childProcessManager';
import DemoProcess from '../process/DemoProcess';

try {
  DemoProcess.toString(); // 这里要调用下DemoProcess类的任意方法，防止没有引用到而被构建工具优化掉
  childProcessManager.startChildProcess("./ets/process/DemoProcess.ts", childProcessManager.StartMode.SELF_FORK)
    .then((data) => {
      console.log(`startChildProcess success, pid: ${data}`);
    }, (err: BusinessError) => {
      console.error(`startChildProcess error, errorCode: ${err.code}`);
    })
} catch (err) {
  console.error(`startChildProcess error, errorCode: ${err.code}`);
}
```

## childProcessManager.startChildProcess

startChildProcess(srcEntry: string, startMode: StartMode, callback: AsyncCallback&lt;number&gt;): void;

启动子进程，并调用子进程的入口方法，以Callback方式返回执行结果。创建子进程成功会返回子进程pid，但并不代表入口方法调用成功，具体结果以入口方法是否调用成功为准。子进程中不支持再次调用该方法创建子进程。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | srcEntry | string | 是 | 子进程源文件相对路径（源文件需要放在src/main中，详见下方示例代码）。目前只支持源文件放在entry类型的模块中。 |
  | startMode | [StartMode](#childprocessmanagerstartmode) | 是 | 子进程启动模式。 |
  | callback | AsyncCallback&lt;number&gt; | 是 | 以callback的形式返回子进程pid。 |

**错误码**：

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000050 | Internal error. |
| 16000061  | Operation not supported. |
| 16000062  | The number of child process exceeds upper bound. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

**示例：**

```ts
// 在entry模块的src/main/ets/process下创建DemoProcess.ts子进程类:
import ChildProcess from '@ohos.app.ability.ChildProcess';

export default class DemoProcess extends ChildProcess {
  onStart() {
    console.log("DemoProcess OnStart() called");
  }
}

// 使用childProcessManager.startChildProcess方法启动子进程:
import childProcessManager from '@ohos.app.ability.childProcessManager';
import DemoProcess from '../process/DemoProcess';

try {
  DemoProcess.toString(); // 这里要调用下DemoProcess类的任意方法，防止没有引用到而被构建工具优化掉
  childProcessManager.startChildProcess("./ets/process/DemoProcess.ts", childProcessManager.StartMode.SELF_FORK, (err, data) => {
    if (data) {
      console.log(`startChildProcess success, pid: ${data}`);
    } else {
      console.error(`startChildProcess error, errorCode: ${err.code}`);
    }
  });
} catch (err) {
  console.error(`startChildProcess error, errorCode: ${err.code}`);
}
```