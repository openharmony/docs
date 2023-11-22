# @ohos.faultLogger    
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import FaultLogger from '@ohos.faultLogger'    
```  
    
## FaultType    
故障类型枚举。    
    
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.FaultLogger    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NO_SPECIFIC | 0 | 不区分故障类型 |  
| CPP_CRASH | 2 | C++程序故障类型 |  
| JS_CRASH | 3 | JS程序故障类型 |  
| APP_FREEZE | 4 | 应用程序卡死故障类型 |  
    
## querySelfFaultLog<sup>(deprecated)</sup>    
获取当前进程故障信息，该方法通过回调方式获取故障信息数组，故障信息数组内最多上报10份故障信息。  
 **调用形式：**     
- querySelfFaultLog(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.faultlogger/FaultLogger#query。  
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.FaultLogger    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| faultType<sup>(deprecated)</sup> | FaultType | true | 输入要查询的故障类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<FaultLogInfo>> | true | 回调函数，在回调函数中获取故障信息数组。<br/>-value拿到故障信息数组；value为undefined表示获取过程中出现异常，error返回错误提示字符串 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import faultLogger from '@ohos.faultLogger'  
import { BusinessError } from '@ohos.base'  
  
function queryFaultLogCallback(error: BusinessError, value: Array<faultLogger.FaultLogInfo>) {  
    if (error) {  
        console.info('error is ' + error);  
    } else {  
        console.info("value length is " + value.length);  
        let len: number = value.length;  
        for (let i = 0; i < len; i++) {  
            console.info("log: " + i);  
            console.info("Log pid: " + value[i].pid);  
            console.info("Log uid: " + value[i].uid);  
            console.info("Log type: " + value[i].type);  
            console.info("Log timestamp: " + value[i].timestamp);  
            console.info("Log reason: " + value[i].reason);  
            console.info("Log module: " + value[i].module);  
            console.info("Log summary: " + value[i].summary);  
            console.info("Log text: " + value[i].fullLog);  
        }  
    }  
}  
faultLogger.querySelfFaultLog(faultLogger.FaultType.JS_CRASH, queryFaultLogCallback);  
    
```    
  
    
## querySelfFaultLog<sup>(deprecated)</sup>    
获取当前进程故障信息，该方法通过Promise方式返回故障信息数组，故障信息数组内最多上报10份故障信息。  
 **调用形式：**     
- querySelfFaultLog(faultType: FaultType): Promise\<Array\<FaultLogInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.faultlogger/FaultLogger#query。  
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.FaultLogger    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| faultType<sup>(deprecated)</sup> | FaultType | true | 输入要查询的故障类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<FaultLogInfo>> | Promise实例，可以在其then()方法中获取故障信息实例，也可以使用await。 <br/>-value拿到故障信息数组；value为undefined表示获取过程中出现异常 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import faultLogger from '@ohos.faultLogger'  
async function getLog() {    let value: Array<faultLogger.FaultLogInfo> = await faultLogger.querySelfFaultLog(faultLogger.FaultType.JS_CRASH);    if (value) {        console.info("value length is " + value.length);        let len: number = value.length;        for (let i = 0; i < len; i++) {            console.info("log: " + i);            console.info("Log pid: " + value[i].pid);            console.info("Log uid: " + value[i].uid);            console.info("Log type: " + value[i].type);            console.info("Log timestamp: " + value[i].timestamp);            console.info("Log reason: " + value[i].reason);            console.info("Log module: " + value[i].module);            console.info("Log summary: " + value[i].summary);            console.info("Log text: " + value[i].fullLog);        }    }}    
```    
  
    
## query<sup>(9+)</sup>    
获取当前进程故障信息，故障信息数组内最多上报10份故障信息。  
 **调用形式：**     
    
- query(faultType: FaultType, callback: AsyncCallback\<Array\<FaultLogInfo>>): void    
起始版本： 9    
- query(faultType: FaultType): Promise\<Array\<FaultLogInfo>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.FaultLogger    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| faultType | FaultType | true | 输入要查询的故障类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，在回调函数中获取故障信息数组。<br/>-value拿到故障信息数组；value为undefined表示获取过程中出现异常，error返回错误提示字符串 |  
| Promise<Array<FaultLogInfo>> | Promise实例，可以在其then()方法中获取故障信息实例，也可以使用await。 <br/>-value拿到故障信息数组；value为undefined表示获取过程中出现异常 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 10600001 | The service is not started or is faulty |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import faultLogger from '@ohos.faultLogger'  
import { BusinessError } from '@ohos.base'  
  
function queryFaultLogCallback(error: BusinessError, value: Array<faultLogger.FaultLogInfo>) {  
    if (error) {  
        console.info('error is ' + error);  
    } else {  
        console.info("value length is " + value.length);  
        let len: number = value.length;  
        for (let i = 0; i < len; i++) {  
            console.info("log: " + i);  
            console.info("Log pid: " + value[i].pid);  
            console.info("Log uid: " + value[i].uid);  
            console.info("Log type: " + value[i].type);  
            console.info("Log timestamp: " + value[i].timestamp);  
            console.info("Log reason: " + value[i].reason);  
            console.info("Log module: " + value[i].module);  
            console.info("Log summary: " + value[i].summary);  
            console.info("Log text: " + value[i].fullLog);  
        }  
    }  
}  
try {  
    faultLogger.query(faultLogger.FaultType.JS_CRASH, queryFaultLogCallback);  
} catch (err) {  
    console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import faultLogger from '@ohos.faultLogger'  
import { BusinessError } from '@ohos.base'  
  
async function getLog() {  
    try {  
        let value: Array<faultLogger.FaultLogInfo> = await faultLogger.query(faultLogger.FaultType.JS_CRASH);  
        if (value) {  
            console.info("value length is " + value.length);  
            let len: number = value.length;  
            for (let i = 0; i < len; i++) {  
                console.info("log: " + i);  
                console.info("Log pid: " + value[i].pid);  
                console.info("Log uid: " + value[i].uid);  
                console.info("Log type: " + value[i].type);  
                console.info("Log timestamp: " + value[i].timestamp);  
                console.info("Log reason: " + value[i].reason);  
                console.info("Log module: " + value[i].module);  
                console.info("Log summary: " + value[i].summary);  
                console.info("Log text: " + value[i].fullLog);  
            }  
        }  
    } catch (err) {  
        console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);  
    }  
}  
    
```    
  
    
## FaultLogInfo    
故障信息数据结构，获取到的故障信息的数据结构。  
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.FaultLogger    
### 属性    
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.FaultLogger    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pid | number | false | true | 故障进程的进程id |  
| uid | number | false | true | 故障进程的用户id |  
| type | FaultType | false | true | 故障类型 |  
| timestamp | number | false | true | 日志生成时的秒级时间戳 |  
| reason | string | false | true | 发生故障的原因 |  
| module | string | false | true | 发生故障的模块 |  
| summary | string | false | true | 故障的概要 |  
| fullLog | string | false | true | 故障日志全文。 |  
