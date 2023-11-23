# @ohos.request    
request部件主要给应用提供上传下载文件、后台传输代理的基础能力。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import request from '@ohos.request'    
```  
    
## Filter<sup>(10+)</sup>    
过滤条件。  
 **系统能力:**  SystemCapability.Request.FileTransferAgent    
### 属性    
 **系统能力:**  SystemCapability.Request.FileTransferAgent    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| bundle<sup>(10+)</sup> | string | false | false | 指定应用程序的包名，仅对系统应用开放。<br/>**系统接口**：此接口为系统接口。 |  
    
## TaskInfo<sup>(10+)</sup>    
查询结果的任务信息数据结构，提供普通查询和系统查询，两种字段的可见范围不同。  
 **系统能力:**  SystemCapability.Request.FileTransferAgent    
### 属性    
 **系统能力:**  SystemCapability.Request.FileTransferAgent    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uid<sup>(10+)</sup> | string | true | false | 应用程序的UID，仅用于系统查询。<br/>**系统接口**：此接口为系统接口。 |  
| bundle<sup>(10+)</sup> | string | true | false | 应用程序的包名，仅用于系统查询。<br/>**系统接口**：此接口为系统接口。 |  
    
## query<sup>(10+)</sup>    
根据任务id查询任务的详细信息。  
 **调用形式：**     
    
- query(id: string, callback: AsyncCallback\<TaskInfo>): void    
起始版本： 10    
- query(id: string): Promise\<TaskInfo>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Request.FileTransferAgent  
 **需要权限：** ohos.permission.DOWNLOAD_SESSION_MANAGER or ohos.permission.UPLOAD_SESSION_MANAGER    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | string | true | 任务id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回任务详细信息。 |  
| Promise<TaskInfo> | Promise对象。返回任务详细信息的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 13400003 | task service ability error. |  
| 21900006 | task not found error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
request.agent.query("123456", (err: BusinessError, taskInfo: request.agent.TaskInfo) => {    if (err) {      console.error(`Failed to query a upload task, Code: ${err.code}, message: ${err.message}`);      return;    }    console.info(`Succeeded in querying a upload task. result: ${taskInfo.uid}`);  });    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
request.agent.query("123456").then((taskInfo: request.agent.TaskInfo) => {    console.info(`Succeeded in querying a upload task. result: ${taskInfo.uid}`);  }).catch((err: BusinessError) => {    console.error(`Failed to query a upload task, Code: ${err.code}, message: ${err.message}`);  });    
```    
  
