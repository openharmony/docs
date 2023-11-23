# @ohos.logLibrary    
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import logLibrary from '@ohos.logLibrary'    
```  
    
## LogEntry    
日志文件对象接口。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.LogLibrary    
### 属性    
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.LogLibrary    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 文件名称。 |  
| mtime | number | false | true | 上次修改该文件的时间，表示距1970年1月1日0时0分0秒的秒数。 |  
| size | number | false | true | 文件大小，以字节为单位。 |  
    
## list    
以同步方法查询指定类型的日志文件列表，接收string类型的对象作为参数，返回指定类型日志的文件列表信息。  
 **调用形式：**     
- list(logType: string): LogEntry[]  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.LogLibrary  
 **需要权限：** ohos.permission.READ_HIVIEW_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| logType | string | true | 日志类型字符串，例如“HILOG”, "FAULTLOG", "BETACLUB", "REMOTELOG"等。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| LogEntry[] | 日志文件对象的数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied |  
| 202 | Permission denied, non-system app called system api. |  
| 401 | Invalid argument. |  
    
 **示例代码：**   
```js    
import logLibrary from '@ohos.logLibrary';  
  
try {  
    let logObj = logLibrary.list('HILOG');  
    // do something here.  
} catch (error) {  
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);  
}  
    
```    
  
    
## copy    
拷贝指定日志类型的指定文件到目标应用目录下  
 **调用形式：**     
    
- copy(logType: string, logName: string, dest: string): Promise\<void>    
起始版本： 10    
- copy(logType: string, logName: string, dest: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.LogLibrary  
 **需要权限：** ohos.permission.READ_HIVIEW_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| logType | string | true | 日志类型字符串，例如“HILOG”, "FAULTLOG", "BETACLUB", "REMOTELOG"等。 |  
| logName | string | true | 日志文件名称。 |  
| dest | string | true | 目标目录，需填入相对目录名称。传入dest字串后，日志文件将保存到应用缓存路径下的"hiview/*dest*"文件夹，即"../cache/hiview/*dest*"。可填入多层目录。<br>如果传入空字串，将保存到根目录下，即应用缓存路径下的hiview文件夹。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | Promise实例，可以在其then()、catch()方法中分别对拷贝成功、拷贝异常的回调进行处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Permission denied, non-system app called system api. |  
| 401 | Invalid argument. |  
| 21300001 | Source file does not exists. |  
    
 **示例代码1：**   
示例代码（callback）：  
```js    
import logLibrary from '@ohos.logLibrary';  
  
try {  
    logLibrary.copy('HILOG', 'hiapplogcat-1.zip', 'dir1', (error, val) => {  
        if (val === undefined) {  
            // copy failed.  
        } else {  
            // copy success.  
        }  
    });  
} catch (error) {  
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```js    
import logLibrary from '@ohos.logLibrary';  
import { BusinessError } from '@ohos.base';  
  
try {  
    logLibrary.copy('HILOG', 'hiapplogcat-1.zip', ''  
    ).then(  
        (val) => {  
            // do something here.  
        }  
    ).catch(  
        (err: BusinessError) => {  
            // do something here.  
        }  
    )  
} catch (error) {  
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);  
}  
    
```    
  
    
## move    
移动指定日志类型的指定文件到目标应用目录下  
 **调用形式：**     
    
- move(logType: string, logName: string, dest: string): Promise\<void>    
起始版本： 10    
- move(logType: string, logName: string, dest: string, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.LogLibrary  
 **需要权限：** ohos.permission.WRITE_HIVIEW_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| logType | string | true | 日志类型字符串，例如"FAULTLOG", "BETACLUB", "REMOTELOG"等。 |  
| logName | string | true | 日志文件名称。 |  
| dest | string | true | 目标目录，需填入相对目录名称。传入dest字串后，日志文件将保存到应用缓存路径下的"hiview/*dest*"文件夹，即"../cache/hiview/*dest*"。可填入多层目录。<br>如果传入空字串，将保存到根目录下，即应用缓存路径下的hiview文件夹。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> | Promise实例，可以在其then()、catch()方法中分别对移动成功、移动异常的回调进行处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Permission denied, non-system app called system api. |  
| 401 | Invalid argument. |  
| 21300001 | Source file does not exists. |  
    
 **示例代码1：**   
示例代码（callback）：  
```null    
import logLibrary from '@ohos.logLibrary';  
  
try {  
    logLibrary.move('FAULTLOG', 'fault_log_test.zip', 'dir1/dir2', (error, val) => {  
        if (val === undefined) {  
            // move failed.  
        } else {  
            // move success.  
        }  
    });  
} catch (error) {  
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);  
}  
    
```    
  
    
 **示例代码2：**   
示例代码（promise）：  
```null    
import logLibrary from '@ohos.logLibrary';  
import { BusinessError } from '@ohos.base';  
  
try {  
    logLibrary.move('FAULTLOG', 'fault_log_test.zip', ''  
    ).then(  
        (val) => {  
            // do something here.  
        }  
    ).catch(  
        (err: BusinessError) => {  
            // do something here.  
        }  
    )  
} catch (error) {  
    console.error(`error code: ${error?.code}, error msg: ${error?.message}`);  
}  
    
```    
  
    
## remove    
以同步方法删除指定日志类型的指定文件。  
 **调用形式：**     
- remove(logType: string, logName: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.HiviewDFX.Hiview.LogLibrary  
 **需要权限：** ohos.permission.WRITE_HIVIEW_SYSTEM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| logType | string | true | 日志类型字符串，例如"FAULTLOG", "BETACLUB", "REMOTELOG"等。 |  
| logName | string | true | 日志文件名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Permission denied, non-system app called system api. |  
| 401 | Invalid argument. |  
| 21300001 | Source file does not exists. |  
    
 **示例代码：**   
```null    
import logLibrary from '@ohos.logLibrary';  
  
try {  
  logLibrary.remove('FAULTLOG', 'fault_log_test.zip');  
} catch (error) {  
  console.error(`error code: ${error?.code}, error msg: ${error?.message}`);  
}  
    
```    
  
