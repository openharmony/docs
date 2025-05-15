# StdProcess (进程管理标准库)

提供系统进程信息查询及跨进程交互能力，支持环境变量管理、系统资源配置等高级操作。

> **说明：**
>
> ArkTS版本：该标准库接口仅适用于ArkTS1.2。

## process

进程控制核心类，提供进程信息查询接口。

### 属性

| 名称             | 类型   | 只读  | 可选 | 说明                 |
| ---------------- | ------ | ---- | ---- | ------------------ |
| uid              | number | 是   | 否   | 进程的用户标识。     |
| pid              | number | 是   | 否   | 当前进程的pid。      |
| tid              | number | 是   | 否   | 当前线程的tid。      |

### is64Bit

static is64Bit(): boolean

检查运行环境是否为64位。

**返回值：**

| 类型    | 说明                                                     |
| ------- | ------------------------------------------------------- |
| boolean | 返回判断结果。如果运行环境是64位则返回true，否则返回false。 |

**示例：**

```js
let result = StdProcess.process.is64Bit();
```

### getStartRealtime

static getStartRealtime(): number

获取系统启动到进程启动的实时时间（以毫秒为单位）。

**返回值：**

| 类型   | 说明                           |
| ------ | ----------------------------- |
| number | 返回经过的实时时间。单位：毫秒。 |

**示例：**

```js
let realtime = StdProcess.process.getStartRealtime();
```

### getPastCpuTime

static getPastCpuTime(): number

获取进程启动到当前时间的CPU时间（以毫秒为单位）。

**返回值：**

| 类型   | 说明                          |
| ------ | ----------------------------- |
| number | 返回经过的CPU时间。单位：毫秒。 |

**示例：**

```js
let result = StdProcess.process.getPastCpuTime();
```

### abort

static abort(): void

该方法会导致进程立即退出并生成一个核心文件，谨慎使用。

**示例：**

```js
StdProcess.process.abort();
```

### uptime

static uptime(): number

获取当前系统已运行的时间（以秒为单位）。

**返回值：**

| 类型   | 说明                          |
| ------ | ---------------------------- |
| number | 当前系统已运行的时间。单位：秒。|

**示例：**

```js
let time = StdProcess.process.uptime();
```

## ProcessManager

提供与系统进程进行交互的接口，用于获取进程特有和系统特有的信息。

### getUidForName

static getUidForName(v: string): number

根据指定的用户名，从系统的用户数据库中获取该用户uid。

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | ------- |
| v      | string | 是   | 用户名。 |

**返回值：**

| 类型   | 说明                               |
| ------ | --------------------------------- |
| number | 获取用户uid，如果用户不存在则返回-1。|

**示例：**

```js
let pres = StdProcess.ProcessManager.getUidForName("tool");
```

### getThreadPriority

static getThreadPriority(v: number): number

根据指定的tid获取线程优先级。

**参数：**

| 参数名 | 类型   | 必填 | 说明                            |
| ------ | ------ | ---- | ----------------------------- |
| v      | number | 是   | 指定的线程tid。大于等于0的整数。 |

**返回值：**

| 类型   | 说明                                          |
| ------ | -------------------------------------------- |
| number | 返回线程的优先级。优先级顺序取决于当前操作系统。 |

**示例：**

```js
let tid = StdProcess.process.tid;
let pres = StdProcess.ProcessManager.getThreadPriority(tid);
```

### getSystemConfig

static getSystemConfig(name: number): number

获取系统配置信息。

**参数：**

| 参数名  | 类型   | 必填  | 说明                          |
| ------ | ------ | ---- | ------------------------------ |
| name   | number | 是   | 指定系统配置参数名。大于0的整数。 |

**返回值：**

| 类型   | 说明                                    |
| ------ | -------------------------------------  |
| number | 返回系统配置信息。如果配置不存在，返回-1。 |

**示例：**

```js
let _SC_ARG_MAX = 0;
let pres = StdProcess.ProcessManager.getSystemConfig(_SC_ARG_MAX);
```

### getEnvironmentVar

static getEnvironmentVar(name: string): string

获取环境变量对应的值，如果值不存在，返回空字符串。

**参数：**

| 参数名 | 类型    | 必填 | 说明         |
| ------ | ------ | ---- | ----------- |
| name   | string | 是   | 环境变量名。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ----------------------- |
| string | 返回环境变量名对应的值。  |

**示例：**

```js
let pres = StdProcess.ProcessManager.getEnvironmentVar("PATH");
```

### exit

static exit(code: number): void

终止程序。

请谨慎使用此接口，此接口调用后应用会退出，如果入参非0会产生数据丢失或者异常情况。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | ------------- |
| code   | number | 是   | 进程的退出码。0~255的整数。 |

**示例：**

```js
StdProcess.ProcessManager.exit(0);
```

### kill

static kill(signal: number, pid: number): boolean

发送signal到指定的进程，结束指定进程。

**参数：**

| 参数名  | 类型   | 必填 | 说明                               |
| ------ | ------ | ---- | ---------------------------------- |
| signal | number | 是   | 发送特定的信号给目标进程。1~64的整数。|
| pid    | number | 是   | 进程的id。大于0的整数。              |

**返回值：**

| 类型    | 说明                                                      |
| ------- | -------------------------------------------------------- |
| boolean | 信号是否发送成功。如果信号发送成功则返回true，否则返回false。 |

**示例：**

```js
let pres = StdProcess.process.pid;
let result = StdProcess.ProcessManager.kill(28, pres);
```
