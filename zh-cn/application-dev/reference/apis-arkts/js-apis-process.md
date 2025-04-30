# @ohos.process (获取进程相关的信息)

获取进程相关的信息，提供进程管理的相关功能。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { process } from '@kit.ArkTS';
```


## 属性

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称             | 类型   | 可读 | 可写 | 说明             |
| ---------------- | ------ | ---- | ---- | ---------------- |
| uid              | number | 是   | 否   | 进程的用户标识。 |
| pid              | number | 是   | 否   | 当前进程的pid。  |
| tid<sup>8+</sup> | number | 是   | 否   | 当前线程的tid。  |


## EventListener

type EventListener = (evt: Object) => void

用户存储的事件信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| evt   | Object | 是 | 用户事件。|

## process.isIsolatedProcess<sup>8+</sup>

isIsolatedProcess(): boolean

检查进程是否已被隔离。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                                    |
| ------- | ------------------------------------------------------- |
| boolean | 返回判断结果。如果进程被隔离则返回true，否则返回false。 |

**示例：**

```js
let result = process.isIsolatedProcess();
```


## process.is64Bit<sup>8+</sup>

is64Bit(): boolean

检查运行环境是否为64位。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                                        |
| ------- | ----------------------------------------------------------- |
| boolean | 返回判断结果。如果运行环境是64位则返回true，否则返回false。 |

**示例：**

```js
let result = process.is64Bit();
```


## process.getStartRealtime<sup>8+</sup>

getStartRealtime(): number

获取系统启动到进程启动的实时时间（以毫秒为单位）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                             |
| ------ | -------------------------------- |
| number | 返回经过的实时时间。单位：毫秒。 |

**示例：**

```js
let realtime = process.getStartRealtime();
```

## process.getPastCpuTime<sup>8+</sup>

getPastCpuTime(): number

获取进程启动到当前时间的CPU时间（以毫秒为单位）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                            |
| ------ | ------------------------------- |
| number | 返回经过的CPU时间。单位：毫秒。 |

**示例：**

```js
let result = process.getPastCpuTime();
```


## process.abort

abort(): void

该方法会导致进程立即退出并生成一个核心文件，谨慎使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
process.abort();
```


## process.uptime

uptime(): number

获取当前系统已运行的时间（以秒为单位）。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 当前系统已运行的时间。单位：秒。|

**示例：**

```js
let time = process.uptime();
```


## process.kill<sup>(deprecated)</sup>

kill(signal: number, pid: number): boolean

发送信号到指定进程，结束该进程。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[kill<sup>9+</sup>](#kill9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| signal | number | 是   | 发送的信号。 |
| pid    | number | 是   | 进程的id。   |

**返回值：**

| 类型    | 说明 |
| ------- | -----------------------------------|
| boolean | 信号发送成功返回true，失败返回false。 |

**示例：**

```js
let pres = process.pid;
let result = process.kill(28, pres);
```


## process.exit<sup>(deprecated)</sup>

exit(code: number): void

终止程序。

请谨慎使用此接口。调用此接口后应用将退出。如果输入参数非0，可能会导致数据丢失或出现异常。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[exit<sup>9+</sup>](#exit9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| code   | number | 是   | 进程的退出码。 |

**示例：**

```js
process.exit(0);
```


## process.getUidForName<sup>(deprecated)</sup>

getUidForName(v: string): number

根据指定的用户名，从系统的用户数据库中获取该用户的uid。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getUidForName<sup>9+</sup>](#getuidforname9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| v      | string | 是   | 用户名。 |

**返回值：**

| 类型   | 说明          |
| ------ | ------------- |
| number | 返回用户uid。 |

**示例：**

```js
let pres = process.getUidForName("tool");
```


## process.getThreadPriority<sup>(deprecated)</sup>

getThreadPriority(v: number): number

根据指定的tid获取线程优先级。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getThreadPriority<sup>9+</sup>](#getthreadpriority9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| v      | number | 是   | 指定的线程tid。 |

**返回值：**

| 类型   | 说明                                             |
| ------ | ------------------------------------------------ |
| number | 返回线程的优先级。优先级顺序取决于当前操作系统。 |

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

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| v      | number | 是   | 应用程序的uid。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回判断结果。如果是应用程序的uid则返回true，否则返回false。 |

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

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| name   | number | 是   | 指定系统配置参数名。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回系统配置信息。 |

**示例：**

```js
let _SC_ARG_MAX = 0;
let pres = process.getSystemConfig(_SC_ARG_MAX);
```


## process.getEnvironmentVar<sup>(deprecated)</sup>

getEnvironmentVar(name: string): string

获取环境变量名对应的值。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[getEnvironmentVar<sup>9+</sup>](#getenvironmentvar9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| name   | string | 是   | 环境变量名。 |

**返回值：**

| 类型   | 说明                        |
| ------ | --------------------------- |
| string | 返回环境变量名对应的值。 |

**示例：**

```js
let pres = process.getEnvironmentVar("PATH");
```


## ProcessManager<sup>9+</sup>

提供用于新增进程的抛异常接口。

构造ProcessManager对象。

### isAppUid<sup>9+</sup>

isAppUid(v: number): boolean

判断uid是否属于当前应用程序。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| v      | number | 是   | 应用程序的uid。可通过process.uid获取。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回判断结果。如果是应用程序的uid则返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```js
let pro = new process.ProcessManager();
// uid通过process.uid获取
let pres = process.uid;
let result = pro.isAppUid(pres);
console.log("result: " + result); // result: true
```


### getUidForName<sup>9+</sup>

getUidForName(v: string): number

根据指定的用户名，从系统的用户数据库中获取该用户uid。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明     |
| ------ | ------ | ---- | -------- |
| v      | string | 是   | 用户名。 |

**返回值：**

| 类型   | 说明          |
| ------ | ------------- |
| number | 获取用户uid，如果用户不存在则返回-1。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```js
let pro = new process.ProcessManager();
let pres = pro.getUidForName("tool");
```


### getThreadPriority<sup>9+</sup>

getThreadPriority(v: number): number

根据指定的tid获取线程优先级。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| v      | number | 是   | 指定的线程tid。 |

**返回值：**

| 类型   | 说明                                             |
| ------ | ------------------------------------------------ |
| number | 返回线程的优先级。优先级顺序取决于当前操作系统。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```js
let pro = new process.ProcessManager();
let tid = process.tid;
let pres = pro.getThreadPriority(tid);
```


### getSystemConfig<sup>9+</sup>

getSystemConfig(name: number): number

获取系统配置信息。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| name   | number | 是   | 指定系统配置参数名。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回系统配置信息。如果配置不存在，返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```js
let pro = new process.ProcessManager();
let _SC_ARG_MAX = 0;
let pres = pro.getSystemConfig(_SC_ARG_MAX);
```


### getEnvironmentVar<sup>9+</sup>

getEnvironmentVar(name: string): string

获取环境变量对应的值。

> **说明：**
>
> 获取环境变量对应的值。如果环境变量不存在，返回undefined。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| name   | string | 是   | 环境变量名。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 返回环境变量名对应的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```js
let pro = new process.ProcessManager();
let pres = pro.getEnvironmentVar("PATH");
```


### exit<sup>9+</sup>

exit(code: number): void

终止程序。

请谨慎使用此接口，此接口调用后应用会退出，如果入参非0会产生数据丢失或者异常情况。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| code   | number | 是   | 进程的退出码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```js
let pro = new process.ProcessManager();
pro.exit(0);
```


### kill<sup>9+</sup>

kill(signal: number, pid: number): boolean

发送signal到指定的进程，结束指定进程。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| signal | number | 是   | 发送特定的信号给目标进程。 取值范围：1 <= signal <= 64。|
| pid    | number | 是   | 进程的id。   |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 信号是否发送成功。如果信号发送成功则返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```js
let pro = new process.ProcessManager();
let pres = process.pid;
let result = pro.kill(28, pres);
```