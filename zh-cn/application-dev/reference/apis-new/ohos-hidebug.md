# @ohos.hidebug    
使用hidebug，可以获取应用内存的使用情况，包括应用进程的静态堆内存（native heap）信息、应用进程内存占用PSS（Proportional Set Size）信息等；可以完成虚拟机内存切片导出，虚拟机CPU Profiling采集等操作。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import hidebug from '@ohos.hidebug'    
```  
    
## getNativeHeapSize    
获取本应用堆内存的总大小。  
 **调用形式：**     
- getNativeHeapSize(): bigint  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 返回本应用堆内存总大小，单位为Byte。 |  
    
 **示例代码：**   
```ts    
let nativeHeapSize: bigint = hidebug.getNativeHeapSize();    
```    
  
    
## getNativeHeapAllocatedSize    
获取本应用堆内存的已分配内存大小。  
 **调用形式：**     
- getNativeHeapAllocatedSize(): bigint  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 返回本应用堆内存的已分配内存，单位为Byte。 |  
    
 **示例代码：**   
```ts    
let nativeHeapAllocatedSize: bigint = hidebug.getNativeHeapAllocatedSize();    
```    
  
    
## getNativeHeapFreeSize    
获取本应用堆内存的空闲内存大小。  
 **调用形式：**     
- getNativeHeapFreeSize(): bigint  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 返回本应用堆内存的空闲内存，单位为Byte。 |  
    
 **示例代码：**   
```ts    
let nativeHeapFreeSize: bigint = hidebug.getNativeHeapFreeSize();    
```    
  
    
## getPss    
获取应用进程实际使用的物理内存大小。  
 **调用形式：**     
- getPss(): bigint  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 返回应用进程实际使用的物理内存大小，单位为kB。 |  
    
 **示例代码：**   
```ts    
let pss: bigint = hidebug.getPss();    
```    
  
    
## getSharedDirty    
获取进程的共享脏内存大小。  
 **调用形式：**     
- getSharedDirty(): bigint  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 返回进程的共享脏内存大小，单位为kB。 |  
    
 **示例代码：**   
```ts    
let sharedDirty: bigint = hidebug.getSharedDirty();    
```    
  
    
## getPrivateDirty<sup>(9+)</sup>    
获取进程的私有脏内存大小。  
 **调用形式：**     
- getPrivateDirty(): bigint  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| bigint | 返回进程的私有脏内存大小，单位为kB。 |  
    
 **示例代码：**   
```ts    
let privateDirty: bigint = hidebug.getPrivateDirty();    
```    
  
    
## getCpuUsage<sup>(9+)</sup>    
获取进程的CPU使用率。  
 **调用形式：**     
- getCpuUsage(): number  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取进程的CPU使用率。 |  
    
 **示例代码：**   
```ts    
let cpuUsage: number = hidebug.getCpuUsage();    
```    
  
    
## startProfiling<sup>(deprecated)</sup>    
启动虚拟机Profiling方法跟踪，`startProfiling()`方法的调用需要与`stopProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。  
 **调用形式：**     
- startProfiling(filename: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.hidebug/hidebug.startJsCpuProfiling。  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filename<sup>(deprecated)</sup> | string | true | 用户自定义的profiling文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.json`文件。 |  
    
 **示例代码：**   
```ts    
hidebug.startProfiling("cpuprofiler-20220216");  
// code block  
// ...  
// code block  
hidebug.stopProfiling();    
```    
  
    
## stopProfiling<sup>(deprecated)</sup>    
停止虚拟机Profiling方法跟踪，`stopProfiling()`方法的调用需要与`startProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。  
 **调用形式：**     
- stopProfiling(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.hidebug/hidebug.stopJsCpuProfiling。  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **示例代码：**   
```ts    
hidebug.startProfiling("cpuprofiler-20220216");  
// code block  
// ...  
// code block  
hidebug.stopProfiling();    
```    
  
    
## dumpHeapData<sup>(deprecated)</sup>    
虚拟机堆导出。  
 **调用形式：**     
- dumpHeapData(filename: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.hidebug/hidebug.dumpJsHeapData。  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filename<sup>(deprecated)</sup> | string | true | 用户自定义的虚拟机堆文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.heapsnapshot`文件。 |  
    
 **示例代码：**   
```ts    
hidebug.dumpHeapData("heap-20220216");    
```    
  
    
## startJsCpuProfiling<sup>(9+)</sup>    
启动虚拟机Profiling方法跟踪，`startJsCpuProfiling()`方法的调用需要与`stopJsCpuProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。  
 **调用形式：**     
- startJsCpuProfiling(filename: string): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filename | string | true | 用户自定义的profiling文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.json`文件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | the parameter check failed |  
    
 **示例代码：**   
```ts    
import hidebug from '@ohos.hidebug'  
import { BusinessError } from '@ohos.base'  
  
try {  
  hidebug.startJsCpuProfiling("cpu_profiling");  
  // ...  
  hidebug.stopJsCpuProfiling();  
} catch (error) {  
  console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);  
}  
    
```    
  
    
## stopJsCpuProfiling<sup>(9+)</sup>    
停止虚拟机Profiling方法跟踪，`startJsCpuProfiling()`方法的调用需要与`stopJsCpuProfiling()`方法的调用一一对应，先开启后关闭，严禁使用`start->start->stop`，`start->stop->stop`，`start->start->stop->stop`等类似的顺序调用。  
 **调用形式：**     
- stopJsCpuProfiling(): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **示例代码：**   
```ts    
import hidebug from '@ohos.hidebug'  
import { BusinessError } from '@ohos.base'  
  
try {  
  hidebug.startJsCpuProfiling("cpu_profiling");  
  // ...  
  hidebug.stopJsCpuProfiling();  
} catch (error) {  
  console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);  
}  
    
```    
  
    
## dumpJsHeapData<sup>(9+)</sup>    
虚拟机堆导出。  
 **调用形式：**     
- dumpJsHeapData(filename: string): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filename | string | true | 用户自定义的虚拟机堆文件名，根据传入的`filename`，将在应用的`files`目录生成`filename.heapsnapshot`文件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | the parameter check failed |  
    
 **示例代码：**   
```ts    
import hidebug from '@ohos.hidebug'  
import { BusinessError } from '@ohos.base'  
  
try {  
  hidebug.dumpJsHeapData("heapData");  
} catch (error) {  
  console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);  
}  
    
```    
  
    
## getServiceDump<sup>(9+)</sup>    
获取系统服务信息。  
 **调用形式：**     
- getServiceDump(serviceid: number, fd: number, args: Array\<string>): void  
  
 **系统能力:**  SystemCapability.HiviewDFX.HiProfiler.HiDebug  
 **需要权限：** ohos.permission.DUMP    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serviceid | number | true | 基于该用户输入的service id获取系统服务信息。 |  
| fd | number | true | 文件描述符，该接口会往该fd中写入数据。 |  
| args | Array<string> | true | 系统服务的Dump接口所对应的参数列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | the parameter check failed |  
| 11400101 | the service id is invalid |  
    
 **示例代码：**   
```ts    
import UIAbility from '@ohos.app.ability.UIAbility';  
import fs from '@ohos.file.fs'  
import hidebug from '@ohos.hidebug'  
import common from '@ohos.app.ability.common'  
import { BusinessError } from '@ohos.base'  
  
export default class HidebugTest extends UIAbility {  
  public testfunc() {  
    let applicationContext: common.Context | null = null;  
    try {  
      applicationContext = this.context.getApplicationContext();  
    } catch (error) {  
      console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);  
    }  
  
    let filesDir: string = applicationContext!.filesDir;  
    let path: string = filesDir + "/serviceInfo.txt";  
    console.info("output path: " + path);  
    let file = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
    let serviceId: number = 10;  
    let args: Array<string> = new Array("allInfo");  
  
    try {  
      hidebug.getServiceDump(serviceId, file.fd, args);  
    } catch (error) {  
      console.info(`error code: ${(error as BusinessError).code}, error msg: ${(error as BusinessError).message}`);  
    }  
    fs.closeSync(file);  
  }  
}  
  
let t = new HidebugTest();  
t.testfunc();  
    
```    
  
