# @ohos.process (获取进程相关的信息)

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import process from '@ohos.process';
```


## 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| uid | number | 是 | 否 | 进程的用户标识。 |
| pid | number | 是 | 否 | 当前进程的pid。 |
| tid<sup>8+</sup> | number | 是 | 否 | 当前线程的tid。 |


## EventListener

系统能力： SystemCapability.Utils.Lang

| 名称 | 说明 |
| -------- | -------- |
| EventListener&nbsp;=&nbsp;(evt: &nbsp;Object)&nbsp;=&gt;&nbsp;void | 用户存储的事件。 |


## process.isIsolatedProcess<sup>8+</sup>

isIsolatedProcess(): boolean

判断进程是否被隔离。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回判断结果，true表示进程被隔离，false表示未被隔离。|

**示例：**

```js
let result = process.isIsolatedProcess();
```


## process.is64Bit<sup>8+</sup>

is64Bit(): boolean

判断运行环境是否64位。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回判断结果，如果为64位环境返回true，否则返回false。|

**示例：**

```js
let result = process.is64Bit();
```


## process.getStartRealtime<sup>8+</sup>

getStartRealtime(): number

获取从系统启动到进程启动所经过的实时时间（以毫秒为单位）。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回经过的实时时间。单位：毫秒|

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
| number | 返回经过的CPU时间。单位：毫秒|

**示例：**

```js
let result = process.getPastCpuTime() ;
```


## process.abort

abort(): void

该方法会导致进程立即退出并生成一个核心文件，谨慎使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
process.abort();
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


## process.kill<sup>(deprecated)</sup>

kill(signal: number, pid: number): boolean

发送signal到指定的进程，结束指定进程。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[kill<sup>9+</sup>](#kill9)替代。

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


## process.exit<sup>(deprecated)</sup>

exit(code: number): void

终止程序。

请谨慎使用此接口，此接口调用后应用会退出，如果入参非0会产生数据丢失或者异常情况。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[exit<sup>9+</sup>](#exit9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| code | number | 是 | 进程的退出码。 |

**示例：**

```js
process.exit(0);
```


## process.getUidForName<sup>(deprecated)</sup>

getUidForName(v: string): number

通过进程名获取进程uid。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getUidForName<sup>9+</sup>](#getuidforname9)替代。

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


## process.getThreadPriority<sup>(deprecated)</sup>

getThreadPriority(v: number): number

根据指定的tid获取线程优先级。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getThreadPriority<sup>9+</sup>](#getthreadpriority9)替代。

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


## process.isAppUid<sup>(deprecated)</sup>

isAppUid(v: number): boolean

判断uid是否属于应用程序。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[isAppUid<sup>9+</sup>](#isappuid9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| v | number | 是 | 应用程序的uid。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回判断结果，如果为应用程序的uid返回true，否则返回false。|

**示例：**

```js
let result = process.isAppUid(688);
```


## process.getSystemConfig<sup>(deprecated)</sup>

getSystemConfig(name: number): number

获取系统配置信息。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getSystemConfig<sup>9+</sup>](#getsystemconfig9)替代。

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


## process.getEnvironmentVar<sup>(deprecated)</sup>

getEnvironmentVar(name: string): string

获取环境变量对应的值。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getEnvironmentVar<sup>9+</sup>](#getenvironmentvar9)替代。

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


## ProcessManager<sup>9+</sup>	

提供用于新增进程的抛异常接口。

通过自身的构造来获取ProcessManager对象。

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
| boolean | 返回判断结果，如果为应用程序的uid返回true，否则返回false。|

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

获取环境变量对应的值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 环境变量名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回环境变量名对应的值。 |

**示例：**

```js
let pro = new process.ProcessManager();
let pres = pro.getEnvironmentVar("PATH");
```


### exit<sup>9+</sup>

exit(code: number): void

终止程序。

请谨慎使用此接口，此接口调用后应用会退出，如果入参非0会产生数据丢失或者异常情况。

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
