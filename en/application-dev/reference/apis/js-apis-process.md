# Obtaining Process Information

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import process from '@ohos.process';
```


## Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| egid | number | Yes| No| Effective group identifier (EGID) of a process. This is a system API and cannot be called by third-party applications.|
| euid | number | Yes| No| Effective user identifier (EUID) of a process. This is a system API and cannot be called by third-party applications.|
| gid | number | Yes| No| Group identifier (GID) of a process. This is a system API and cannot be called by third-party applications.|
| uid | number | Yes| No| User identifier (UID) of a process.|
| groups | number[] | Yes| No| Array with supplementary group IDs. This is a system API and cannot be called by third-party applications.|
| pid | number | Yes| No| Process ID (PID) of a process.|
| ppid | number | Yes| No| Parent process ID (PPID) of a process. This is a system API and cannot be called by third-party applications.|
| tid<sup>8+</sup> | number | Yes| No| Thread ID (TID) of a process.|


## ProcessManager<sup>9+</sup>	

Provides APIs for throwing exceptions during the addition of a process.

### process.isAppUid<sup>9+</sup>

isAppUid(v: number): boolean

Checks whether a UID belongs to this application.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| v | number | Yes| UID.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the UID is the application's UID; returns **false** otherwise.|

**Example**

```js
let pro = new process.ProcessManager();
let result = pro.isAppUid(688);
```


### process.getUidForName<sup>9+</sup>

getUidForName(v: string): number

Obtains the process UID based on the process name.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| v | string | Yes| Name of a process.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Process UID.|

**Example**

```js
let pro = new process.ProcessManager();
let pres = pro .getUidForName("tool");
```


### process.getThreadPriority<sup>9+</sup>

getThreadPriority(v: number): number

Obtains the thread priority based on the specified TID.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| v | number | Yes| TID.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Priority of the thread.|

**Example**

```js
let pro = new process.ProcessManager();
let tid = process.tid;
let pres = pro.getThreadPriority(tid);
```


### process.getSystemConfig<sup>9+</sup>

getSystemConfig(name: number): number

Obtains the system configuration.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | number | Yes| System configuration parameter name.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | System configuration obtained.|

**Example**

```js
let pro = new process.ProcessManager();
let _SC_ARG_MAX = 0;
let pres = pro.getSystemConfig(_SC_ARG_MAX);
```


### process.getEnvironmentVar<sup>9+</sup>

getEnvironmentVar(name: string): string

Obtains the value of an environment variable.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Environment variable name.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Value of the environment variable.|

**Example**

```js
let pro = new process.ProcessManager();
let pres = pro.getEnvironmentVar("PATH");
```


### process.exit<sup>9+</sup>

exit(code: number): void

Terminates this process.

Exercise caution when using this API.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| code | number | Yes| Exit code of the process.|

**Example**

```js
let pro = new process.ProcessManager();
pro.exit(0);
```


### process.kill<sup>9+</sup>

kill(signal: number, pid: number): boolean

Sends a signal to the specified process to terminate it.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pid | number | Yes| PID of the process, to which the signal will be sent.|
| signal | number | Yes| Signal to send.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the signal is sent successfully; returns **false** otherwise.|

**Example**

```js
let pro = new process.ProcessManager();
let pres = process.pid;
let result = pro.kill(28, pres);
```


## ChildProcess

Allows a process to obtain the standard input and output of its child processes, send signals, and close its child processes.

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| pid | number | Yes| No| PID of the child process. This is a system API and cannot be called by third-party applications.|
| ppid | number | Yes| No| PPID of the child process. This is a system API and cannot be called by third-party applications.|
| exitCode | number | Yes| No| Exit code of the child process. This is a system API and cannot be called by third-party applications.|
| killed | boolean | Yes| No| Whether the parent process successfully sends a signal to the child process to terminate it. This is a system API and cannot be called by third-party applications.|


### wait

wait(): Promise&lt;number&gt;

Waits until the child process ends. This method uses a promise to return the exit code of the child process.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the exit code of the child process.|

**Example**

```js
let child = process.runCmd('ls');
let result = child.wait();
result.then(val=>{
    console.log("result = " + val);
})
```


### getOutput

getOutput(): Promise&lt;Uint8Array&gt;

Obtains the standard output of the child process.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the standard output in a Uint8Array.|

**Example**

```js
let child = process.runCmd('ls');
let result = child.wait();
child.getOutput().then(val=>{
    console.log("child.getOutput = " + val);
})
```


### getErrorOutput

getErrorOutput(): Promise&lt;Uint8Array&gt;

Obtains the standard error output of the child process.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the standard error output in a Uint8Array.|

**Example**

```js
let child = process.runCmd('madir test.text');
let result = child.wait();
child.getErrorOutput().then(val=>{
    console.log("child.getErrorOutput= " + val);
})
```


### close

close(): void

Closes the child process in running.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
let child = process.runCmd('sleep 5; ls');
child.close();
```


### kill

kill(signal: number | string): void

Sends a signal to the specified child process to terminate it.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| signal | number&nbsp;\|&nbsp;string | Yes| Number or string to send.|

**Example**

```js
let child = process.runCmd('sleep 5; ls');
child.kill(9);
```


## process.isIsolatedProcess<sup>8+</sup>

isIsolatedProcess(): boolean

Checks whether this process is isolated.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the process is isolated; returns **false** otherwise.|

**Example**

```js
let result = process.isIsolatedProcess();
```


## process.isAppUid<sup>8+</sup>

isAppUid(v: number): boolean

Checks whether a UID belongs to this application.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| v | number | Yes| UID.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the UID is the application's UID; returns **false** otherwise.|

**Example**

```js
let result = process.isAppUid(688);
```


## process.is64Bit<sup>8+</sup>

is64Bit(): boolean

Checks whether this process is running in a 64-bit environment.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the process is running in a 64-bit environment; returns **false** otherwise.|

**Example**

```js
let result = process.is64Bit();
```


## process.getUidForName<sup>8+</sup>

getUidForName(v: string): number

Obtains the process UID based on the process name.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| v | string | Yes| Name of a process.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Process UID.|

**Example**

```js
let pres = process.getUidForName("tool")
```


## process.getThreadPriority<sup>8+</sup>

getThreadPriority(v: number): number

Obtains the thread priority based on the specified TID.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| v | number | Yes| TID.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | Priority of the thread.|

**Example**

```js
let tid = process.tid;
let pres = process.getThreadPriority(tid);
```


## process.getStartRealtime<sup>8+</sup>

getStartRealtime(): number

Obtains the duration, in milliseconds, from the time the system starts to the time the process starts.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| number | Duration obtained.|

**Example**

```js
let realtime = process.getStartRealtime();
```

## process.getPastCpuTime<sup>8+</sup>

getPastCpuTime(): number

Obtains the CPU time (in milliseconds) from the time the process starts to the current time.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| number | CPU time obtained.|

**Example**

```js
let result = process.getPastCpuTime() ;
```


## process.getSystemConfig<sup>8+</sup>

getSystemConfig(name: number): number

Obtains the system configuration.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | number | Yes| System configuration parameter name.|

**Return value**

| Type| Description|
| -------- | -------- |
| number | System configuration obtained.|

**Example**

```js
let _SC_ARG_MAX = 0
let pres = process.getSystemConfig(_SC_ARG_MAX)
```


## process.getEnvironmentVar<sup>8+</sup>

getEnvironmentVar(name: string): string

Obtains the value of an environment variable.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Environment variable name.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Value of the environment variable.|

**Example**

```js
let pres = process.getEnvironmentVar("PATH")
```


## process.runCmd

runCmd(command: string, options?: { timeout?: number, killSignal?: number | string, maxBuffer?: number }): ChildProcess

Forks a new process to run a shell command and returns the **ChildProcess** object.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| command | string | Yes| Shell command to run.|
| options | Object | No| Related parameters.|

**Table 1** options

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| timeout | number | No| Maximum running time (in ms) of the child process. When the running time of the child process exceeds the value of this parameter, the parent process sends a **killSignal** to the child process to terminate it. The default value is **0**.|
| killSignal | number \| string | No| Signal sent to the child process when the running time of a child process exceeds the timeout period. The default value is **SIGTERM**.|
| maxBuffer | number | No| Maximum buffer size for the standard input and output of the child process. When the size is exceeded, the child process will be terminated. The default value is **1024 \* 1024**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [ChildProcess](#childprocess) | **ChildProcess** object.|

**Example**

```js
let child = process.runCmd('ls', { maxBuffer : 2 });
let result = child.wait();
child.getOutput.then(val=>{
    console.log("child.getOutput = " + val);
})
```


## process.abort

abort(): void

Aborts a process and generates a core file. This method will cause a process to exit immediately. Exercise caution when using this method.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
process.abort();
```


## process.on

on(type: string, listener: EventListener): void

Stores the events triggered by the user.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the events to store. |
| listener | EventListener | Yes| Callback invoked to return the event.|

**Table 2** EventListener

| Name| Description|
| -------- | -------- |
| EventListener&nbsp;=&nbsp;(evt: &nbsp;Object)&nbsp;=&gt;&nbsp;void | Event to store.|

**Example**

```js
process.on("data", (e)=>{
    console.log("data callback");
})
```


## process.off

off(type: string): boolean

Deletes the event stored by the user.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the event to delete.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the event is deleted; returns **false** otherwise.|

**Example**

```js
process.on("data", (e)=>{
    console.log("data callback");
})
let result = process.off("data");
```


## process.exit

exit(code: number): void

Terminates this process.

Exercise caution when using this API.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| code | number | Yes| Exit code of the process.|

**Example**

```js
process.exit(0);
```


## process.cwd

cwd(): string

Obtains the working directory of this process.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
let path = process.cwd();
```


## process.chdir

chdir(dir: string): void

Changes the working directory of this process.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| dir | string | Yes| Path|

**Example**

```js
process.chdir('/system');
```


## process.uptime

uptime(): number

Obtains the running time of this process.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| number | Running time of the process, in seconds.|

**Example**

```js
let time = process.uptime();
```


## process.kill

kill(signal: number, pid: number): boolean

Sends a signal to the specified process to terminate it.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pid | number | Yes| PID of the process, to which the signal will be sent.|
| signal | number | Yes| Signal to send.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the signal is sent successfully; returns **false** otherwise.|

**Example**

```js
let pres = process.pid
let result = process.kill(28, pres)
```
