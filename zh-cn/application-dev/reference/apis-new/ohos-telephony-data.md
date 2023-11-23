# @ohos.telephony.data    
蜂窝数据提供了移动数据管理能力，包括获取、设置默认移动数据的SIM卡，获取蜂窝数据业务的上下行和分组交换域（PS域）的连接状态，以及检查蜂窝数据业务和漫游是否启用等。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import data from '@ohos.telephony.data'    
```  
    
## getDefaultCellularDataSlotId    
获取默认移动数据的SIM卡，  
 **调用形式：**     
    
- getDefaultCellularDataSlotId(callback: AsyncCallback\<number>): void    
起始版本： 7    
- getDefaultCellularDataSlotId(): Promise\<number>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CellularData    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br />0：卡槽1。<br />1：卡槽2。 |  
| Promise<number> | 以Promise形式返回获取默认移动数据的SIM卡。<br />0：卡槽1。<br />1：卡槽2。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.getDefaultCellularDataSlotId((err: BusinessError, data: number) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.getDefaultCellularDataSlotId().then((data: number) => {  
    console.log(`getDefaultCellularDataSlotId success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getDefaultCellularDataSlotId fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getDefaultCellularDataSlotIdSync<sup>(9+)</sup>    
获取默认移动数据的SIM卡。  
 **调用形式：**     
- getDefaultCellularDataSlotIdSync(): number  
  
 **系统能力:**  SystemCapability.Telephony.CellularData    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取默认移动数据的SIM卡。<br />0：卡槽1。<br />1：卡槽2。 |  
    
 **示例代码：**   
```ts    
import data from '@ohos.telephony.data';console.log("Result: "+ data.getDefaultCellularDataSlotIdSync())    
```    
  
    
## getCellularDataFlowType    
获取蜂窝数据业务的上下行状态  
 **调用形式：**     
    
- getCellularDataFlowType(callback: AsyncCallback\<DataFlowType>): void    
起始版本： 7    
- getCellularDataFlowType(): Promise\<DataFlowType>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CellularData    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<DataFlowType> | 以Promise形式返回获取蜂窝数据业务的上下行状态。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.getCellularDataFlowType((err: BusinessError, data: data.DataFlowType) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.getCellularDataFlowType().then((data: data.DataFlowType) => {  
    console.log(`test success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getCellularDataState    
获取分组交换域（PS域）的连接状态，  
 **调用形式：**     
    
- getCellularDataState(callback: AsyncCallback\<DataConnectState>): void    
起始版本： 7    
- getCellularDataState(): Promise\<DataConnectState>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CellularData    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<DataConnectState> | 以Promise形式返回获取PS域的连接状态。 |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.getCellularDataState((err: BusinessError, data: data.DataConnectState) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.getCellularDataState().then((data: data.DataConnectState) => {  
    console.log(`test success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## isCellularDataEnabled    
检查蜂窝数据业务是否启用  
 **调用形式：**     
    
- isCellularDataEnabled(callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- isCellularDataEnabled(): Promise\<boolean>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CellularData  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br />true：蜂窝数据业务已启用。<br />false：蜂窝数据业务已禁用。 |  
| Promise<boolean> | 以Promise形式返回检查蜂窝数据业务是否启用。<br />true：蜂窝数据业务已启用。<br />false：蜂窝数据业务已禁用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.isCellularDataEnabled((err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.isCellularDataEnabled().then((data: boolean) => {  
    console.log(`test success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## isCellularDataRoamingEnabled    
检查蜂窝数据业务是否启用漫游  
 **调用形式：**     
    
- isCellularDataRoamingEnabled(slotId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- isCellularDataRoamingEnabled(slotId: number): Promise\<boolean>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CellularData  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br />0：卡槽1。<br />1：卡槽2。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br />true：蜂窝数据业务已启用漫游。<br />false：蜂窝数据业务已禁用漫游。 |  
| Promise<boolean> | 以Promise形式返回检查蜂窝数据业务是否启用漫游。<br />true：蜂窝数据业务已启用漫游。<br />false：蜂窝数据业务已禁用漫游。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.isCellularDataRoamingEnabled(0, (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import data from '@ohos.telephony.data';  
import { BusinessError } from '@ohos.base';  
  
data.isCellularDataRoamingEnabled(0).then((data: boolean) => {  
    console.log(`test success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getDefaultCellularDataSimId<sup>(10+)</sup>    
获取默认移动数据的SIM卡ID。  
 **调用形式：**     
- getDefaultCellularDataSimId(): number  
  
 **系统能力:**  SystemCapability.Telephony.CellularData    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取默认移动数据的SIM卡ID。<br/>与SIM卡绑定，从1开始递增。 |  
    
 **示例代码：**   
```ts    
import data from '@ohos.telephony.data';console.log("Result: "+ data.getDefaultCellularDataSimId());    
```    
  
    
## DataFlowType    
描述蜂窝数据流类型。 。    
    
 **系统能力:**  SystemCapability.Telephony.CellularData    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DATA_FLOW_TYPE_NONE | 0 | 表示没有上行或下行数据。     |  
| DATA_FLOW_TYPE_DOWN | 1 |  表示只有下行数据。   |  
| DATA_FLOW_TYPE_UP | 2 |  表示只有上行数据。  |  
| DATA_FLOW_TYPE_UP_DOWN | 3 | 表示有上下行数据。   |  
| DATA_FLOW_TYPE_DORMANT | 4 | 表示没有上下行数据，底层链路处于休眠状态。 |  
    
## DataConnectState    
描述蜂窝数据链路连接状态。     
    
 **系统能力:**  SystemCapability.Telephony.CellularData    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DATA_STATE_UNKNOWN | -1 | 表示蜂窝数据链路未知 |  
| DATA_STATE_DISCONNECTED | 0 | 表示蜂窝数据链路断开。 |  
| DATA_STATE_CONNECTING | 1 | 表示正在连接蜂窝数据链路 |  
| DATA_STATE_CONNECTED | 2 | 表示蜂窝数据链路已连接。 |  
| DATA_STATE_SUSPENDED | 3 |  表示蜂窝数据链路被挂起。 |  
