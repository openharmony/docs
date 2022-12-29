# @ohos.process (获取进程相关的信息)

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import process from '@ohos.process';
```


## 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| egid | number | 是 | 否 | 进程的有效组标识。<br>**系统接口：** 此接口为系统接口。 <br>此接口仅用于对应用的测试。|
| euid | number | 是 | 否 | 进程的有效用户身份。<br>**系统接口：** 此接口为系统接口。<br>此接口仅用于对应用的测试。 |
| gid | number | 是 | 否 | 进程的组标识。<br>**系统接口：** 此接口为系统接口。<br>此接口仅用于对应用的测试。|
| uid | number | 是 | 否 | 进程的用户标识。 |
| groups | number[] | 是 | 否 | 带有补充组id的数组。<br>**系统接口：** 此接口为系统接口。<br>此接口仅用于对应用的测试。 |
| pid | number | 是 | 否 | 当前进程的pid。 |
| ppid | number | 是 | 否 | 当前进程的父进程的pid。<br>**系统接口：** 此接口为系统接口。<br>此接口仅用于对应用的测试。 |
| tid<sup>8+</sup> | number | 是 | 否 | 当前进程的tid。 |


## ProcessManager<sup>9+</sup>	

提供用于新增进程的抛异常接口。

### isAppUid<sup>9+</sup>

isAppUid(v: number): boolean

判断uid是否属于当前应用程序。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| v | number | 是 | 应用程序的uid。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回判断结果，如果返回true表示为应用程序的uid。|

**示例：**

```js
let pro = new process.ProcessManager();
let result = pro.isAppUid(688);
```


### getUidForName<sup>9+</sup>

getUidForName(v: string): number

通过进程名获取进程uid。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| v | string | 是 | 进程名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回进程uid。|

**示例：**

```js
let pro = new process.ProcessManager();
let pres = pro .getUidForName("tool");
```


### getThreadPriority<sup>9+</sup>

getThreadPriority(v: number): number

根据指定的tid获取线程优先级。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| v | number | 是 | 指定的线程tid。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回线程的优先级。 |

**示例：**

```js
let pro = new process.ProcessManager();
let tid = process.tid;
let pres = pro.getThreadPriority(tid);
```


### getSystemConfig<sup>9+</sup>

getSystemConfig(name: number): number

获取系统配置信息。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | number | 是 | 指定系统配置参数名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回系统配置信息。 |

**示例：**

```js
let pro = new process.ProcessManager();
let _SC_ARG_MAX = 0;
let pres = pro.getSystemConfig(_SC_ARG_MAX);
```


### getEnvironmentVar<sup>9+</sup>

getEnvironmentVar(name: string): string

用该方法获取环境变量对应的值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 环境变量名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回环境变量名对应的value。 |

**示例：**

```js
let pro = new process.ProcessManager();
let pres = pro.getEnvironmentVar("PATH");
```


### exit<sup>9+</sup>

exit(code: number): void

终止程序。

请谨慎使用此接口。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| code | number | 是 | 进程的退出码。 |

**示例：**

```js
let pro = new process.ProcessManager();
pro.exit(0);
```


### kill<sup>9+</sup>

kill(signal: number, pid: number): boolean

发送signal到指定的进程，结束指定进程。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pid | number | 是 | 进程的id。 |
| signal | number | 是 | 发送的信号。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 信号是否发送成功。 |

**示例：**

```js
let pro = new process.ProcessManager();
let pres = process.pid;
let result = pro.kill(28, pres);
```


## ChildProcess

主进程可以获取子进程的标准输入输出，以及发送信号和关闭子进程。

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| pid | number | 是 | 否 | 子进程的pid。<br>**系统接口：** 此接口为系统接口。<br>此接口仅用于对应用的测试。 |
| ppid | number | 是 | 否 | 子进程的父进程的pid。<br>**系统接口：** 此接口为系统接口。<br>此接口仅用于对应用的测试。 |
| exitCode | number | 是 | 否 | 子进程的退出码。<br>**系统接口：** 此接口为系统接口。 <br>此接口仅用于对应用的测试。|
| killed | boolean | 是 | 否 | 父进程给子进程发信号是否成功。<br>**系统接口：** 此接口为系统接口。<br>此接口仅用于对应用的测试。 |


### wait

wait(): Promise&lt;number&gt;

等待子进程运行结束，返回promise对象，其值为子进程的退出码。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | 异步返回子进程的退出码。 |

**示例：**

```js
let child = process.runCmd('ls');
let result = child.wait();
result.then(val=>{
    console.log("result = " + val);
})
```


### getOutput

getOutput(): Promise&lt;Uint8Array&gt;

获取子进程的标准输出。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Uint8Array&gt; | 异步返回标准输出的字节流。 |

**示例：**

```js
let child = process.runCmd('ls');
let result = child.wait();
child.getOutput().then(val=>{
    console.log("child.getOutput = " + val);
})
```


### getErrorOutput

getErrorOutput(): Promise&lt;Uint8Array&gt;

获取子进程的标准错误输出。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Uint8Array&gt; | 异步返回标准错误输出的字节流。 |

**示例：**

```js
let child = process.runCmd('madir test.text');
let result = child.wait();
child.getErrorOutput().then(val=>{
    console.log("child.getErrorOutput= " + val);
})
```


### close

close(): void

关闭正在运行的子进程。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
let child = process.runCmd('sleep 5; ls');
child.close();
```


### kill

kill(signal: number | string): void

用于发送信号给子进程，结束指定进程。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| signal | number&nbsp;\|&nbsp;string | 是 | 数字或字符串。 |

**示例：**

```js
let child = process.runCmd('sleep 5; ls');
child.kill(9);
```


## process.isIsolatedProcess<sup>8+</sup>

isIsolatedProcess(): boolean

判断进程是否被隔离。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回判断结果，如果返回true表示进程被隔离。 |

**示例：**

```js
let result = process.isIsolatedProcess();
```


## process.isAppUid<sup>8+</sup>

isAppUid(v: number): boolean

判断uid是否属于应用程序。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| v | number | 是 | 应用程序的uid。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回判断结果，如果返回true表示为应用程序的uid。|

**示例：**

```js
let result = process.isAppUid(688);
```


## process.is64Bit<sup>8+</sup>

is64Bit(): boolean

判断运行环境是否64位。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回判断结果，如果返回true表示为64位环境。 |

**示例：**

```js
let result = process.is64Bit();
```


## process.getUidForName<sup>8+</sup>

getUidForName(v: string): number

通过进程名获取进程uid。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| v | string | 是 | 进程名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回进程uid。|

**示例：**

```js
let pres = process.getUidForName("tool")
```


## process.getThreadPriority<sup>8+</sup>

getThreadPriority(v: number): number

根据指定的tid获取线程优先级。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| v | number | 是 | 指定的线程tid。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回线程的优先级。 |

**示例：**

```js
let tid = process.tid;
let pres = process.getThreadPriority(tid);
```


## process.getStartRealtime<sup>8+</sup>

getStartRealtime(): number

获取从系统启动到进程启动所经过的实时时间（以毫秒为单位）。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回经过的实时时间。|

**示例：**

```js
let realtime = process.getStartRealtime();
```

## process.getPastCpuTime<sup>8+</sup>

getPastCpuTime(): number

获取进程启动到当前时间的CPU时间（以毫秒为单位）。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回经过的CPU时间。 |

**示例：**

```js
let result = process.getPastCpuTime() ;
```


## process.getSystemConfig<sup>8+</sup>

getSystemConfig(name: number): number

获取系统配置信息。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | number | 是 | 指定系统配置参数名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回系统配置信息。 |

**示例：**

```js
let _SC_ARG_MAX = 0
let pres = process.getSystemConfig(_SC_ARG_MAX)
```


## process.getEnvironmentVar<sup>8+</sup>

getEnvironmentVar(name: string): string

用该方法获取环境变量对应的值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 环境变量名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回环境变量名对应的value。 |

**示例：**

```js
let pres = process.getEnvironmentVar("PATH")
```


## process.runCmd

runCmd(command: string, options?: { timeout?: number, killSignal?: number | string, maxBuffer?: number }): ChildProcess

通过runcmd可以fork一个新的进程来运行一段shell，并返回ChildProcess对象。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| command | string | 是 | shell命令。 |
| options | Object | 否 | 相关选项参数。 |

**表1** options

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| timeout | number | 否 | 子进程运行的ms数，当子进程运行时间超出此时间，则父进程发送killSignal信号给子进程。timeout默认为0。 |
| killSignal | number&nbsp;\|&nbsp;string | 否 | 子进程运行时间超出timeout时，父进程发送killSignal&nbsp;信号给子进程。killSignal&nbsp;默认为'SIGTERM'。 |
| maxBuffer | number | 否 | 子进程标准输入输出的最大缓冲区大小，当超出此大小时则终止子进程。maxBuffer默认1024\*1024。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ChildProcess](#childprocess) | 子进程对象。 |

**示例：**

```js
let child = process.runCmd('ls', { maxBuffer : 2 });
let result = child.wait();
child.getOutput.then(val=>{
    console.log("child.getOutput = " + val);
})
```


## process.abort

abort(): void

该方法会导致进程立即退出并生成一个核心文件，谨慎使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
process.abort();
```


## process.on

on(type: string, listener: EventListener): void

存储用户所触发的事件。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 存储事件的type。 |
| listener | EventListener | 是 | 回调的事件。 |

**表2** EventListener

| 名称 | 说明 |
| -------- | -------- |
| EventListener&nbsp;=&nbsp;(evt: &nbsp;Object)&nbsp;=&gt;&nbsp;void | 用户存储的事件。 |

**示例：**

```js
process.on("data", (e)=>{
    console.log("data callback");
})
```


## process.off

off(type: string): boolean

删除用户存储的事件。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 删除事件的type。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 事件是否删除成功。 |

**示例：**

```js
process.on("data", (e)=>{
    console.log("data callback");
})
let result = process.off("data");
```


## process.exit

exit(code: number): void

终止程序。

请谨慎使用此接口。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| code | number | 是 | 进程的退出码。 |

**示例：**

```js
process.exit(0);
```


## process.cwd

cwd(): string

用该方法获取进程的工作目录。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
let path = process.cwd();
```


## process.chdir

chdir(dir: string): void

更改进程的当前工作目录。

**系统接口：** 此接口为系统接口。

此接口仅用于对应用的测试。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| dir | string | 是 | 路径。 |

**示例：**

```js
process.chdir('/system');
```


## process.uptime

uptime(): number

获取当前系统已运行的秒数。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 当前系统已运行的秒数。 |

**示例：**

```js
let time = process.uptime();
```


## process.kill

kill(signal: number, pid: number): boolean

发送signal到指定的进程，结束指定进程。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| pid | number | 是 | 进程的id。 |
| signal | number | 是 | 发送的信号。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 信号是否发送成功。 |

**示例：**

```js
let pres = process.pid
let result = process.kill(28, pres)
```
