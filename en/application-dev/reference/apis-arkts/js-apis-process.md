# @ohos.process (Obtaining Process Information)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

The **process** module provides process management APIs, for example, APIs for obtaining process information.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { process } from '@kit.ArkTS';
```


## Properties

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

| Name            | Type  | Read-Only| Optional| Description            |
| ---------------- | ------ | ---- | ---- | ---------------- |
| uid              | number | Yes  | No  | User identifier (UID) of the process.|
| pid              | number | Yes  | No  | Process ID (PID) of the process. |
| tid<sup>8+</sup> | number | Yes  | No  | Thread ID (TID) of the thread. |


## EventListener

type EventListener = (evt: Object) => void

Event to store.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| evt   | Object | Yes| Event.|

## process.isIsolatedProcess<sup>8+</sup>

isIsolatedProcess(): boolean

Checks whether this process is isolated.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                                   |
| ------- | ------------------------------------------------------- |
| boolean | Check result. The value **true** is returned if the process is isolated; otherwise, **false** is returned.|

**Example**

```js
let result = process.isIsolatedProcess();
```


## process.is64Bit<sup>8+</sup>

is64Bit(): boolean

Checks whether this process is running in a 64-bit environment.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                                       |
| ------- | ----------------------------------------------------------- |
| boolean | Check result. The value **true** is returned if the process is running in a 64-bit environment; otherwise, **false** is returned.|

**Example**

```js
let result = process.is64Bit();
```


## process.getStartRealtime<sup>8+</sup>

getStartRealtime(): number

Obtains the duration (excluding the system sleep time), in milliseconds, from the time the system starts to the time the process starts.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                            |
| ------ | -------------------------------- |
| number | Duration obtained, in milliseconds.|

**Example**

```js
let realtime = process.getStartRealtime();
```

## process.getPastCpuTime<sup>8+</sup>

getPastCpuTime(): number

Obtains the CPU time (in milliseconds) from the time the process starts to the current time.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                           |
| ------ | ------------------------------- |
| number | CPU time obtained, in milliseconds.|

**Example**

```js
let result = process.getPastCpuTime();
```


## process.abort

abort(): void

Aborts a process and generates a core file. This method will cause a process to exit immediately. Exercise caution when using this method.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
process.abort();
```


## process.uptime

uptime(): number

Obtains the running time of the current system, in seconds.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| number | Running time of the system, in seconds.|

**Example**

```js
let time = process.uptime();
```


## process.kill<sup>(deprecated)</sup>

kill(signal: number, pid: number): boolean

Sends a signal to a specified process to terminate it.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [kill<sup>9+</sup>](#kill9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| signal | number | Yes  | Signal to send.|
| pid    | number | Yes  | PID of the process, to which the signal will be sent.  |

**Return value**

| Type   | Description|
| ------- | -----------------------------------|
| boolean | If the signal is sent successfully, **true** is returned. Other, **false** is returned.|

**Example**

```js
let pres = process.pid;
let result = process.kill(28, pres);
```


## process.exit<sup>(deprecated)</sup>

exit(code: number): void

Terminates this process.

Exercise caution when using this API. After this API is called, the application exits. If the input parameter is not 0, data loss or exceptions may occur.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [exit<sup>9+</sup>](#exit9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| code   | number | Yes  | Exit code of the process.|

**Example**

```js
process.exit(0);
```


## process.getUidForName<sup>(deprecated)</sup>

getUidForName(v: string): number

Obtains the UID of a user from the user database of the system based on the specified user name.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getUidForName<sup>9+</sup>](#getuidforname9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| v      | string | Yes  | User name.|

**Return value**

| Type  | Description         |
| ------ | ------------- |
| number | UID of the user.|

**Example**

```js
let pres = process.getUidForName("tool");
```


## process.getThreadPriority<sup>(deprecated)</sup>

getThreadPriority(v: number): number

Obtains the thread priority based on the specified TID.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getThreadPriority<sup>9+</sup>](#getthreadpriority9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| v      | number | Yes  | TID.|

**Return value**

| Type  | Description                                            |
| ------ | ------------------------------------------------ |
| number | Priority of the thread. The priority depends on the operating system.|

**Example**

```js
let tid = process.tid;
let pres = process.getThreadPriority(tid);
```


## process.isAppUid<sup>(deprecated)</sup>

isAppUid(v: number): boolean

Checks whether a UID belongs to this application.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [isAppUid<sup>9+</sup>](#isappuid9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| v      | number | Yes  | UID.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Check result. The value **true** is returned if the UID belongs to the application; otherwise, **false** is returned.|

**Example**

```js
let result = process.isAppUid(688);
```


## process.getSystemConfig<sup>(deprecated)</sup>

getSystemConfig(name: number): number

Obtains the system configuration.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getSystemConfig<sup>9+</sup>](#getsystemconfig9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| name   | number | Yes  | System configuration parameter name.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | System configuration obtained.|

**Example**

```js
let _SC_ARG_MAX = 0;
let pres = process.getSystemConfig(_SC_ARG_MAX);
```


## process.getEnvironmentVar<sup>(deprecated)</sup>

getEnvironmentVar(name: string): string

Obtains the value of an environment variable.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getEnvironmentVar<sup>9+</sup>](#getenvironmentvar9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| name   | string | Yes  | Environment variable name.|

**Return value**

| Type  | Description                       |
| ------ | --------------------------- |
| string | Value of the environment variable.|

**Example**

```js
let pres = process.getEnvironmentVar("PATH");
```


## ProcessManager<sup>9+</sup>

Provides APIs for throwing exceptions during the addition of a process.

Construct a **ProcessManager** object.

### isAppUid<sup>9+</sup>

isAppUid(v: number): boolean

Checks whether a UID belongs to this application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| v      | number | Yes  | UID. which can be obtained by running **process.uid**.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Check result. The value **true** is returned if the UID belongs to the application; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```js
let pro = new process.ProcessManager();
// Use process.uid to obtain the UID.
let pres = process.uid;
let result = pro.isAppUid(pres);
console.info("result: " + result); // result: true
```


### getUidForName<sup>9+</sup>

getUidForName(v: string): number

Obtains the UID of a user from the user database of the system based on the specified user name.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description    |
| ------ | ------ | ---- | -------- |
| v      | string | Yes  | User name.|

**Return value**

| Type  | Description         |
| ------ | ------------- |
| number | UID of the user. If the user does not exist, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```js
let pro = new process.ProcessManager();
let pres = pro.getUidForName("tool");
```


### getThreadPriority<sup>9+</sup>

getThreadPriority(v: number): number

Obtains the thread priority based on the specified TID.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| v      | number | Yes  | TID.|

**Return value**

| Type  | Description                                            |
| ------ | ------------------------------------------------ |
| number | Priority of the thread. The priority depends on the operating system.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```js
let pro = new process.ProcessManager();
let tid = process.tid;
let pres = pro.getThreadPriority(tid);
```


### getSystemConfig<sup>9+</sup>

getSystemConfig(name: number): number

Obtains the system configuration.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| name   | number | Yes  | System configuration parameter name.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | System configuration obtained. If the configuration does not exist, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```js
let pro = new process.ProcessManager();
let _SC_ARG_MAX = 0;
let pres = pro.getSystemConfig(_SC_ARG_MAX);
```


### getEnvironmentVar<sup>9+</sup>

getEnvironmentVar(name: string): string

Obtains the value of an environment variable.

> **NOTE**
>
> Obtains the value of an environment variable. If the environment variable does not exist, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| name   | string | Yes  | Environment variable name.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Value of the environment variable.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```js
let pro = new process.ProcessManager();
let pres = pro.getEnvironmentVar("PATH");
```


### exit<sup>9+</sup>

exit(code: number): void

Terminates this process.

Exercise caution when using this API. After this API is called, the application exits. If the input parameter is not 0, data loss or exceptions may occur.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| code   | number | Yes  | Exit code of the process.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```js
let pro = new process.ProcessManager();
pro.exit(0);
```


### kill<sup>9+</sup>

kill(signal: number, pid: number): boolean

Sends a signal to the specified process to terminate it. Only the current process can be terminated.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| signal | number | Yes  | Signal to send. Value range: 1 <= signal <= 64.|
| pid    | number | Yes  | PID of the process, to which the signal will be sent.  |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Signal sending result. The value **true** is returned if the signal is sent successfully; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```js
let pro = new process.ProcessManager();
let pres = process.pid;
let result = pro.kill(28, pres);
```
