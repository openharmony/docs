# @ohos.process    
获取进程相关的信息，提供进程管理的相关功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import process from '@ohos.process'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| uid | number |  |  |  
| pid | number |  |  |  
| tid<sup>(8+)</sup> | number |  |  |  
    
## ProcessManager<sup>(9+)</sup>    
提供用于新增进程的抛异常接口。  
 **系统能力:**  SystemCapability.Utils.Lang    
### isAppUid<sup>(9+)</sup>    
判断uid是否属于当前应用程序。  
 **调用形式：**     
- isAppUid(v: number): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| v | number | true | 应用程序的uid。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回判断结果，如果为应用程序的uid返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
let pro = new process.ProcessManager();let result = pro.isAppUid(688);    
```    
  
    
### getUidForName<sup>(9+)</sup>    
通过进程名获取进程uid。  
 **调用形式：**     
- getUidForName(v: string): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| v | string | true | 进程名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回进程uid。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
let pro = new process.ProcessManager();let pres = pro .getUidForName("tool");    
```    
  
    
### getThreadPriority<sup>(9+)</sup>    
根据指定的tid获取线程优先级。  
 **调用形式：**     
- getThreadPriority(v: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| v | number | true | 指定的线程tid。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回线程的优先级。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
let pro = new process.ProcessManager();let tid = process.tid;let pres = pro.getThreadPriority(tid);    
```    
  
    
### getSystemConfig<sup>(9+)</sup>    
获取系统配置信息。  
 **调用形式：**     
- getSystemConfig(name: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | number | true |  指定系统配置参数名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回系统配置信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
let pro = new process.ProcessManager();let _SC_ARG_MAX = 0;let pres = pro.getSystemConfig(_SC_ARG_MAX);    
```    
  
    
### getEnvironmentVar<sup>(9+)</sup>    
获取环境变量对应的值。  
 **调用形式：**     
- getEnvironmentVar(name: string): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 环境变量名。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回环境变量名对应的value。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
let pro = new process.ProcessManager();let pres = pro.getEnvironmentVar("PATH");    
```    
  
    
### exit<sup>(9+)</sup>    
终止程序。  
  
请谨慎使用此接口，此接口调用后应用会退出，如果入参非0会产生数据丢失或者异常情况。  
 **调用形式：**     
- exit(code: number): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code | number | true | 进程的退出码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
let pro = new process.ProcessManager();pro.exit(0)    
```    
  
    
### kill<sup>(9+)</sup>    
发送signal到指定的进程，结束指定进程。  
 **调用形式：**     
- kill(signal: number, pid: number): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| signal | number | true | 发送的信号。 |  
| pid | number | true | 进程的id。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 信号是否发送成功。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
let pro = new process.ProcessManager();let pres = process.pid;let result = pro.kill(28, pres);    
```    
  
    
## isIsolatedProcess<sup>(8+)</sup>    
判断进程是否被隔离。  
 **调用形式：**     
- isIsolatedProcess(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回判断结果，true表示进程被隔离，false表示未被隔离。 |  
    
 **示例代码：**   
```js    
let result = process.isIsolatedProcess();    
```    
  
    
## isAppUid<sup>(deprecated)</sup>    
判断uid是否属于应用程序。  
 **调用形式：**     
- isAppUid(v: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.process.ProcessManager.isAppUid。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| v<sup>(deprecated)</sup> | number | true | 应用程序的uid。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回判断结果，如果为应用程序的uid返回true，否则返回false |  
    
 **示例代码：**   
```js    
let result = process.isAppUid(688);    
```    
  
    
## is64Bit<sup>(8+)</sup>    
判断运行环境是否64位。  
 **调用形式：**     
- is64Bit(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回判断结果，如果为64位环境返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let result = process.is64Bit();    
```    
  
    
## getUidForName<sup>(deprecated)</sup>    
通过进程名获取进程uid。  
 **调用形式：**     
- getUidForName(v: string): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.process.ProcessManager.getUidForName。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| v<sup>(deprecated)</sup> | string | true | 进程名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回进程uid。 |  
    
 **示例代码：**   
```js    
let pres = process.getUidForName("tool")    
```    
  
    
## getThreadPriority<sup>(deprecated)</sup>    
根据指定的tid获取线程优先级。  
 **调用形式：**     
- getThreadPriority(v: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.process.ProcessManager.getThreadPriority。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| v<sup>(deprecated)</sup> | number | true | 指定的线程tid。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回线程的优先级。 |  
    
 **示例代码：**   
```js    
let tid = process.tid;let pres = process.getThreadPriority(tid)    
```    
  
    
## getStartRealtime<sup>(8+)</sup>    
获取从系统启动到进程启动所经过的实时时间（以毫秒为单位）。  
 **调用形式：**     
- getStartRealtime(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回经过的实时时间。单位：毫秒 |  
    
 **示例代码：**   
```js    
let realtime = process.getStartRealtime();    
```    
  
    
## getPastCpuTime<sup>(8+)</sup>    
获取进程启动到当前时间的CPU时间（以毫秒为单位）。  
 **调用形式：**     
- getPastCpuTime(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回经过的CPU时间。单位：毫秒 |  
    
 **示例代码：**   
```js    
let result = process.getPastCpuTime() ;    
```    
  
    
## getSystemConfig<sup>(deprecated)</sup>    
获取系统配置信息。  
 **调用形式：**     
- getSystemConfig(name: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.process.ProcessManager.getSystemConfig。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | number | true | 指定系统配置参数名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回系统配置信息。 |  
    
 **示例代码：**   
```js    
let _SC_ARG_MAX = 0let pres = process.getSystemConfig(_SC_ARG_MAX)    
```    
  
    
## getEnvironmentVar<sup>(deprecated)</sup>    
获取环境变量对应的值。  
 **调用形式：**     
- getEnvironmentVar(name: string): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.process.ProcessManager.getEnvironmentVar。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 环境变量名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回环境变量名对应的value。 |  
    
 **示例代码：**   
```js    
let pres = process.getEnvironmentVar("PATH"    
```    
  
    
## EventListener    
用户存储的事件。  
 **系统能力:**  SystemCapability.Utils.Lang    
## abort    
该方法会导致进程立即退出并生成一个核心文件，谨慎使用。  
 **调用形式：**     
- abort(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```js    
process.abort();    
```    
  
    
## exit<sup>(deprecated)</sup>    
终止程序。  
  
请谨慎使用此接口，此接口调用后应用会退出，如果入参非0会产生数据丢失或者异常情况。  
 **调用形式：**     
- exit(code: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.process.ProcessManager.exit。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 进程的退出码。 |  
    
 **示例代码：**   
```js    
let pro = new process.ProcessManager();pro.exit(0);    
```    
  
    
## uptime    
获取当前系统已运行的秒数。  
 **调用形式：**     
- uptime(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 当前系统已运行的秒数。 |  
    
 **示例代码：**   
```js    
let time = process.uptime();    
```    
  
    
## kill<sup>(deprecated)</sup>    
发送signal到指定的进程，结束指定进程。  
。  
 **调用形式：**     
- kill(signal: number, pid: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.process.ProcessManager.kill。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| signal<sup>(deprecated)</sup> | number | true | 发送的信号。 |  
| pid<sup>(deprecated)</sup> | number | true | 进程的id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 信号是否发送成功。 |  
    
 **示例代码：**   
```js    
let pro = new process.ProcessManager();let pres = process.pid;let result = pro.kill(28, pres);    
```    
  
