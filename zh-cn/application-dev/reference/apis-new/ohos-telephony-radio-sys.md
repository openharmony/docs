# @ohos.telephony.radio    
网络搜索模块提供管理网络搜索的一些基础功能，包括获取当前接入的CS域和PS域无线接入技术、获取网络状态、获取当前选网模式、获取注册网络所在国家的ISO国家码、获取主卡所在卡槽的索引号、获取指定SIM卡槽对应的注册网络信号强度信息列表、获取运营商名称、获取设备的指定卡槽的IMEI、获取设备的指定卡槽的MEID、获取设备的指定卡槽的唯一设备ID，判断当前设备是否支持5G\(NR\)、判断主卡的Radio是否打开等。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import radio from '@ohos.telephony.radio'    
```  
    
## sendUpdateCellLocationRequest<sup>(8+)</sup>    
发送更新小区位置请求。  
 **调用形式：**     
    
- sendUpdateCellLocationRequest(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 8    
- sendUpdateCellLocationRequest(slotId?: number): Promise\<void>    
起始版本： 8    
- sendUpdateCellLocationRequest(callback: AsyncCallback\<void>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.sendUpdateCellLocationRequest(slotId, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.sendUpdateCellLocationRequest(slotId).then(() => {  
    console.log(`sendUpdateCellLocationRequest success.`);  
}).catch((err: BusinessError) => {  
    console.log(`sendUpdateCellLocationRequest failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getCellInformation<sup>(8+)</sup>    
获取小区信息。  
 **调用形式：**     
    
- getCellInformation(slotId: number, callback: AsyncCallback\<Array\<CellInformation>>): void    
起始版本： 8    
- getCellInformation(slotId?: number): Promise\<Array\<CellInformation>>    
起始版本： 8    
- getCellInformation(callback: AsyncCallback\<Array\<CellInformation>>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<Array<CellInformation>> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getCellInformation(slotId, (err: BusinessError, data: Array<radio.CellInformation>) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getCellInformation(slotId).then((data: Array<radio.CellInformation>) => {  
    console.log(`getCellInformation success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getCellInformation failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setNetworkSelectionMode    
设置网络选择模式。  
 **调用形式：**     
    
- setNetworkSelectionMode(options: NetworkSelectionModeOptions, callback: AsyncCallback\<void>): void    
起始版本： 6    
- setNetworkSelectionMode(options: NetworkSelectionModeOptions): Promise\<void>    
起始版本： 6  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | NetworkSelectionModeOptions | true | 网络选择模式选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let networkInformation: radio.NetworkInformation = {  
    operatorName: "中国移动",  
    operatorNumeric: "898600",  
    state: radio.NetworkInformationState.NETWORK_AVAILABLE,  
    radioTech: "CS"  
}  
let networkSelectionModeOptions: radio.NetworkSelectionModeOptions = {  
    slotId: 0,  
    selectMode: radio.NetworkSelectionMode.NETWORK_SELECTION_AUTOMATIC,  
    networkInformation: networkInformation,  
    resumeSelection: true  
}  
radio.setNetworkSelectionMode(networkSelectionModeOptions, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let networkInformation: radio.NetworkInformation = {  
    operatorName: "中国移动",  
    operatorNumeric: "898600",  
    state: radio.NetworkInformationState.NETWORK_AVAILABLE,  
    radioTech: "CS"  
}  
let networkSelectionModeOptions: radio.NetworkSelectionModeOptions = {  
    slotId: 0,  
    selectMode: radio.NetworkSelectionMode.NETWORK_SELECTION_AUTOMATIC,  
    networkInformation: networkInformation,  
    resumeSelection: true  
}  
radio.setNetworkSelectionMode(networkSelectionModeOptions).then(() => {  
    console.log(`setNetworkSelectionMode success.`);  
}).catch((err: BusinessError) => {  
    console.log(`setNetworkSelectionMode failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getNetworkSearchInformation    
获取网络搜索信息。  
 **调用形式：**     
    
- getNetworkSearchInformation(slotId: number, callback: AsyncCallback\<NetworkSearchResult>): void    
起始版本： 6    
- getNetworkSearchInformation(slotId: number): Promise\<NetworkSearchResult>    
起始版本： 6  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<NetworkSearchResult> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
radio.getNetworkSearchInformation(0, (err: BusinessError, data: radio.NetworkSearchResult) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
radio.getNetworkSearchInformation(0).then((data: radio.NetworkSearchResult) => {  
    console.log(`getNetworkSearchInformation success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getNetworkSearchInformation failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getNrOptionMode<sup>(deprecated)</sup>    
获取Nr选项模式 。使用callback异步回调。  
 **调用形式：**     
- getNrOptionMode(slotId: number, callback: AsyncCallback\<NrOptionMode>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: telephony.radio#getNROptionMode。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId<sup>(deprecated)</sup> | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<NrOptionMode> | true | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getNrOptionMode(slotId, (err: BusinessError, data: radio.NrOptionMode) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
## getNrOptionMode<sup>(deprecated)</sup>    
获取Nr选项模式 。使用Promise异步回调。  
 **调用形式：**     
- getNrOptionMode(slotId?: number): Promise\<NrOptionMode>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: telephony.radio#getNROptionMode。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId<sup>(deprecated)</sup> | number | false | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<NrOptionMode> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getNrOptionMode(slotId).then((data: radio.NrOptionMode) => {  
    console.log(`getNrOptionMode success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getNrOptionMode failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getNrOptionMode<sup>(deprecated)</sup>    
获取Nr选项模式 。使用callback异步回调。  
 **调用形式：**     
- getNrOptionMode(callback: AsyncCallback\<NrOptionMode>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: telephony.radio#getNROptionMode。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<NrOptionMode> | true | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
radio.getNrOptionMode((err: BusinessError, data: radio.NrOptionMode) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
## getIMEI<sup>(8+)</sup>    
获取设备的指定卡槽的IMEI。  
 **调用形式：**     
    
- getIMEI(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 8    
- getIMEI(slotId?: number): Promise\<string>    
起始版本： 8    
- getIMEI(callback: AsyncCallback\<string>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，如果IMEI不存在，则返回空字符串。 |  
| Promise<string> | 以Promise形式异步返回IMEI；如果IMEI不存在，则返回空字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getIMEI(slotId, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getIMEI(slotId).then((data: string) => {  
    console.log(`getIMEI success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getIMEI failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getMEID<sup>(8+)</sup>    
获取设备的指定卡槽的MEID。  
 **调用形式：**     
    
- getMEID(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 8    
- getMEID(slotId?: number): Promise\<string>    
起始版本： 8    
- getMEID(callback: AsyncCallback\<string>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回设备的指定卡槽的MEID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getMEID(slotId, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getMEID(slotId).then((data: string) => {  
    console.log(`getMEID success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getMEID failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getUniqueDeviceId<sup>(8+)</sup>    
获取设备的指定卡槽的唯一设备ID。  
 **调用形式：**     
    
- getUniqueDeviceId(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 8    
- getUniqueDeviceId(slotId?: number): Promise\<string>    
起始版本： 8    
- getUniqueDeviceId(callback: AsyncCallback\<string>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回设备的指定卡槽的唯一设备ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getUniqueDeviceId(slotId, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getUniqueDeviceId(slotId).then((data: string) => {  
    console.log(`getUniqueDeviceId success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getUniqueDeviceId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setPrimarySlotId<sup>(8+)</sup>    
设置主卡所在卡槽的索引号。  
 **调用形式：**     
    
- setPrimarySlotId(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setPrimarySlotId(slotId: number): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式异步返回设置结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.setPrimarySlotId(slotId, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.setPrimarySlotId(slotId).then(() => {  
    console.log(`setPrimarySlotId success.`);  
}).catch((err: BusinessError) => {  
    console.log(`setPrimarySlotId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## turnOnRadio<sup>(7+)</sup>    
打开Radio。  
 **调用形式：**     
    
- turnOnRadio(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- turnOnRadio(slotId?: number): Promise\<void>    
起始版本： 7    
- turnOnRadio(callback: AsyncCallback\<void>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.turnOnRadio(slotId, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.turnOnRadio(slotId).then(() => {  
    console.log(`turnOnRadio success.`);  
}).catch((err: BusinessError) => {  
    console.error(`turnOnRadio failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## turnOffRadio<sup>(7+)</sup>    
关闭Radio。  
 **调用形式：**     
    
- turnOffRadio(slotId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- turnOffRadio(slotId?: number): Promise\<void>    
起始版本： 7    
- turnOffRadio(callback: AsyncCallback\<void>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.turnOffRadio(slotId, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.turnOffRadio(slotId).then(() => {  
    console.log(`turnOffRadio success.`);  
}).catch((err: BusinessError) => {  
    console.error(`turnOffRadio failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setPreferredNetwork<sup>(8+)</sup>    
设置首选网络。  
 **调用形式：**     
    
- setPreferredNetwork(slotId: number, networkMode: PreferredNetworkMode, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setPreferredNetwork(slotId: number, networkMode: PreferredNetworkMode): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| networkMode | PreferredNetworkMode | true | 设置首选网络模式。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let mode: radio.PreferredNetworkMode = radio.PreferredNetworkMode.PREFERRED_NETWORK_MODE_GSM;  
radio.setPreferredNetwork(slotId, mode, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let mode: radio.PreferredNetworkMode = radio.PreferredNetworkMode.PREFERRED_NETWORK_MODE_GSM;  
radio.setPreferredNetwork(slotId, mode).then(() => {  
    console.log(`setPreferredNetwork success.`);  
}).catch((err: BusinessError) => {  
    console.log(`setPreferredNetwork failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getPreferredNetwork<sup>(8+)</sup>    
获取首选网络。  
 **调用形式：**     
    
- getPreferredNetwork(slotId: number, callback: AsyncCallback\<PreferredNetworkMode>): void    
起始版本： 8    
- getPreferredNetwork(slotId: number): Promise\<PreferredNetworkMode>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<PreferredNetworkMode> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getPreferredNetwork(slotId, (err: BusinessError, data: radio.PreferredNetworkMode) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getPreferredNetwork(slotId).then((data: radio.PreferredNetworkMode) => {  
    console.log(`getPreferredNetwork success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getPreferredNetwork failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getImsRegInfo<sup>(9+)</sup>    
获取特定IMS服务类型的IMS注册状态信息。  
 **调用形式：**     
    
- getImsRegInfo(slotId: number, imsType: ImsServiceType, callback: AsyncCallback\<ImsRegInfo>): void    
起始版本： 9    
- getImsRegInfo(slotId: number, imsType: ImsServiceType): Promise\<ImsRegInfo>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2。 |  
| imsType | ImsServiceType | true | IMS服务类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<ImsRegInfo> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;  
radio.getImsRegInfo(slotId, mode, (err: BusinessError, data: radio.ImsRegInfo) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;  
radio.getImsRegInfo(slotId, mode).then((data: radio.ImsRegInfo) => {  
    console.log(`getImsRegInfo success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getImsRegInfo failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## on('imsRegStateChange')<sup>(9+)</sup>    
订阅imsRegStateChange事件，使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback: Callback\<ImsRegInfo>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 监听IMS注册状态的变化。 |  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| imsType | ImsServiceType | true | IMS服务类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;  
radio.on('imsRegStateChange', slotId, mode, (data: radio.ImsRegInfo) => {  
    console.log(`callback: data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
## off('imsRegStateChange')<sup>(9+)</sup>    
取消订阅imsRegStateChange事件，使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback?: Callback\<ImsRegInfo>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消监听IMS注册状态的变化。 |  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| imsType | ImsServiceType | true | IMS服务类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。不填该参数不影响取消订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;  
radio.off('imsRegStateChange', slotId, mode, (data: radio.ImsRegInfo) => {  
    console.log(`callback: data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
## getBasebandVersion<sup>(10+)</sup>    
获取设备的基带版本号。  
 **调用形式：**     
    
- getBasebandVersion(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getBasebandVersion(slotId: number): Promise\<string>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。获取的基带版本号。 |  
| Promise<string> | 以Promise形式返回设备的基带版本号。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getBasebandVersion(slotId, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getBasebandVersion(slotId).then((data: string) => {  
    console.log(`getBasebandVersion success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getBasebandVersion failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setNROptionMode<sup>(10+)</sup>    
设置Nr选项模式 。  
 **调用形式：**     
    
- setNROptionMode(slotId: number, mode: NROptionMode, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setNROptionMode(slotId: number, mode: NROptionMode): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| mode | NROptionMode | true | NR的选择模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let mode: radio.NROptionMode = radio.NROptionMode.NR_OPTION_NSA_ONLY;  
radio.setNROptionMode(slotId, mode, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let mode: radio.NROptionMode = radio.NROptionMode.NR_OPTION_NSA_ONLY;  
radio.setNROptionMode(slotId, mode).then(() => {  
    console.log(`setNROptionMode success`);  
}).catch((err: BusinessError) => {  
    console.error(`setNROptionMode failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getNROptionMode<sup>(10+)</sup>    
获取Nr选项模式 。  
 **调用形式：**     
    
- getNROptionMode(slotId: number, callback: AsyncCallback\<NROptionMode>): void    
起始版本： 10    
- getNROptionMode(slotId: number): Promise\<NROptionMode>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<NROptionMode> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getNROptionMode(slotId, (err: BusinessError, data: radio.NROptionMode) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getNROptionMode(slotId).then((data: radio.NROptionMode) => {  
    console.log(`getNROptionMode success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getNROptionMode failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## setNetworkCapability<sup>(10+)</sup>    
设置指定网络类型的开关状态。  
 **调用形式：**     
    
- setNetworkCapability(slotId: number, type: NetworkCapabilityType, state: NetworkCapabilityState,     callback: AsyncCallback\<void>): void    
起始版本： 10    
- setNetworkCapability(slotId: number, type: NetworkCapabilityType, state: NetworkCapabilityState): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.SET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| type | NetworkCapabilityType | true | 网络能力类型。 |  
| state | NetworkCapabilityState | true | 网络能力状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<void> | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;  
let state: radio.NetworkCapabilityState = radio.NetworkCapabilityState.SERVICE_CAPABILITY_ON;  
radio.setNetworkCapability(slotId, type, state, (err: BusinessError) => {  
    console.log(`callback: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;  
let state: radio.NetworkCapabilityState = radio.NetworkCapabilityState.SERVICE_CAPABILITY_ON;  
radio.setNetworkCapability(slotId, type, state).then(() => {  
    console.log(`setNetworkCapability success`);  
}).catch((err: BusinessError) => {  
    console.log(`setNetworkCapability failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getNetworkCapability<sup>(10+)</sup>    
获取指定网络类型的开关状态。  
 **调用形式：**     
    
- getNetworkCapability(slotId: number, type: NetworkCapabilityType,     callback: AsyncCallback\<NetworkCapabilityState>): void    
起始版本： 10    
- getNetworkCapability(slotId: number, type: NetworkCapabilityType): Promise\<NetworkCapabilityState>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| type | NetworkCapabilityType | true | 网络能力类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<NetworkCapabilityState> | 以Promise形式返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;  
radio.getNetworkCapability(slotId, type, (err: BusinessError, data: radio.NetworkCapabilityState) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;  
radio.getNetworkCapability(slotId, type).then((data: radio.NetworkCapabilityState) => {  
    console.log(`getNetworkCapability success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getNetworkCapability failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## PreferredNetworkMode<sup>(8+)</sup>    
首选网络模式。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PREFERRED_NETWORK_MODE_GSM | 1 | 首选GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_WCDMA | 2 | 首选WCDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE | 3 | 首选LTE网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE_WCDMA | 4 | 首选LTE WCDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE_WCDMA_GSM | 5 | 首选LTE WCDMA GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_WCDMA_GSM | 6 | 首选WCDMA GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_CDMA | 7 | 首选CDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_EVDO | 8 | 首选EVDO网络模式。 |  
| PREFERRED_NETWORK_MODE_EVDO_CDMA | 9 | 首选EVDO CDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_WCDMA_GSM_EVDO_CDMA | 10 | 首选WCDMA GSM EVDO CDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE_EVDO_CDMA | 11 | 首选LTE EVDO CDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE_WCDMA_GSM_EVDO_CDMA | 12 | 首选LTE WCDMA GSM EVDO CDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_TDSCDMA | 13 | 首选TDSCDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_TDSCDMA_GSM | 14 | 首选TDSCDMA GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_TDSCDMA_WCDMA | 15 | 首选TDSCDMA_WCDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_TDSCDMA_WCDMA_GSM | 16 | 首选TDSCDMA_WCDMA_GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA | 17 | 首选LTE TDSCDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_GSM | 18 | 首选LTE TDSCDMA GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_WCDMA | 19 | 首选LTE TDSCDMA WCDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_WCDMA_GSM | 20 | 首选LTE TDSCDMA WCDMA GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_TDSCDMA_WCDMA_GSM_EVDO_CDMA | 21 | 首选TDSCDMA WCDMA GSM EVDO CDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_WCDMA_GSM_EVDO_CDMA | 22 | 首选LTE TDSCDMA WCDMA GSM EVDO CDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_NR | 31 | 首选NR网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE | 32 | 首选NR LTE网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE_WCDMA | 33 | 首选NR LTE WCDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE_WCDMA_GSM | 34 | 首选NR LTE WCDMA GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE_EVDO_CDMA | 35 | 首选NR LTE EVDO CDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE_WCDMA_GSM_EVDO_CDMA | 36 | 首选NR LTE WCDMA GSM EVDO CDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA | 37 | 首选NR LTE TDSCDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_GSM | 38 | 首选NR LTE TDSCDMA GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_WCDMA | 39 | 首选NR LTE TDSCDMA WCDMA网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_WCDMA_GSM | 40 | 首选NR LTE TDSCDMA WCDMA GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_WCDMA_GSM_EVDO_CDMA | 41 | 首选NR LTE TDSCDMA WCDMA GSM网络模式。 |  
| PREFERRED_NETWORK_MODE_MAX_VALUE | 99 | 首选网络模式最大值。 |  
    
## CellInformation<sup>(8+)</sup>    
小区信息。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isCamped<sup>(8+)</sup> | boolean | false | true | 获取服务单元的状态。<br>**系统接口：** 此接口为系统接口。 |  
| timeStamp<sup>(8+)</sup> | number | false | true | 获取单元格信息时获取时间戳。<br>**系统接口：** 此接口为系统接口。 |  
| data<sup>(8+)</sup> | CdmaCellInformation \| GsmCellInformation \| LteCellInformation \| NrCellInformation\| TdscdmaCellInformation \| WcdmaCellInformation | false | true | Cdma小区信息 \|Gsm小区信息\|Lte小区信息\|Nr小区信息\|Tdscdma小区信息  <br>**系统接口：** 此接口为系统接口。 |  
    
## CdmaCellInformation<sup>(8+)</sup>    
CDMA小区信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| baseId<sup>(8+)</sup> | number | false | true | 基站Id。 |  
| latitude<sup>(8+)</sup> | number | false | true | 经度。 |  
| longitude<sup>(8+)</sup> | number | false | true | 纬度。 |  
| nid<sup>(8+)</sup> | number | false | true | 网络识别码。 |  
| sid<sup>(8+)</sup> | number | false | true | 系统识别码。 |  
    
## GsmCellInformation<sup>(8+)</sup>    
GSM小区信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| lac<sup>(8+)</sup> | number | false | true | 位置区编号。 |  
| cellId<sup>(8+)</sup> | number | false | true | 小区号。 |  
| arfcn<sup>(8+)</sup> | number | false | true | 绝对无线频率信道号。 |  
| bsic<sup>(8+)</sup> | number | false | true | 基站识别号。 |  
| mcc<sup>(8+)</sup> | string | false | true | 移动国家码。 |  
| mnc<sup>(8+)</sup> | string | false | true | 移动网号。 |  
    
## LteCellInformation<sup>(8+)</sup>    
LTE小区信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| cgi<sup>(8+)</sup> | number | false | true | 小区全球标识。 |  
| pci<sup>(8+)</sup> | number | false | true | 物理小区识别。 |  
| tac<sup>(8+)</sup> | number | false | true | 跟踪区域代码。 |  
| earfcn<sup>(8+)</sup> | number | false | true | 绝对无线频率信道号。 |  
| bandwidth<sup>(8+)</sup> | number | false | true | 带宽。 |  
| mcc<sup>(8+)</sup> | string | false | true | 移动国家码。 |  
| mnc<sup>(8+)</sup> | string | false | true | 移动网号。 |  
| isSupportEndc<sup>(8+)</sup> | boolean | false | true | 是否支持新无线电_双连接 |  
    
## NrCellInformation<sup>(8+)</sup>    
NR小区信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| nrArfcn<sup>(8+)</sup> | number | false | true | 5G频点号。 |  
| pci<sup>(8+)</sup> | number | false | true | 物理小区识别。 |  
| tac<sup>(8+)</sup> | number | false | true | 跟踪区域代码。 |  
| nci<sup>(8+)</sup> | number | false | true |  5G网络小区标识。 |  
| mcc<sup>(8+)</sup> | string | false | true | 移动国家码。 |  
| mnc<sup>(8+)</sup> | string | false | true | 移动网号。 |  
    
## TdscdmaCellInformation<sup>(8+)</sup>    
TD-SCDMA小区信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| lac<sup>(8+)</sup> | number | false | true | TD-SCDMA小区信息。 |  
| cellId<sup>(8+)</sup> | number | false | true | 小区号。 |  
| cpid<sup>(8+)</sup> | number | false | true | 小区参数Id。 |  
| uarfcn<sup>(8+)</sup> | number | false | true | 绝对射频号。 |  
| mcc<sup>(8+)</sup> | string | false | true | 移动国家码。 |  
| mnc<sup>(8+)</sup> | string | false | true | 移动网号。 |  
    
## WcdmaCellInformation<sup>(8+)</sup>    
WCDMA小区信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| lac<sup>(8+)</sup> | number | false | true | 位置区编号。 |  
| cellId<sup>(8+)</sup> | number | false | true | 小区号。 |  
| psc<sup>(8+)</sup> | number | false | true | 主扰码。 |  
| uarfcn<sup>(8+)</sup> | number | false | true | 绝对射频号。 |  
| mcc<sup>(8+)</sup> | string | false | true | 移动国家码。 |  
| mnc<sup>(8+)</sup> | string | false | true | 移动网号。 |  
    
## NrOptionMode<sup>(deprecated)</sup>    
NR的选择模式。    
从API version 8 开始支持，从API version 10 开始废弃。建议使用telephony.radio#NROptionMode替代。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NR_OPTION_UNKNOWN<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 10 开始废弃。<br>未知的NR选择模式。 |  
| NR_OPTION_NSA_ONLY<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 10 开始废弃。<br>仅非独立组网的NR选择模式。 |  
| NR_OPTION_SA_ONLY<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 10 开始废弃。<br>仅独立组网的NR选择模式。 |  
| NR_OPTION_NSA_AND_SA<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 10 开始废弃。<br>非独立组网和独立组网的NR选择模式。 |  
    
## NROptionMode<sup>(10+)</sup>    
NR的选择模式。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NR_OPTION_UNKNOWN | 0 | 未知的NR选择模式。 |  
| NR_OPTION_NSA_ONLY | 1 | 仅非独立组网的NR选择模式。 |  
| NR_OPTION_SA_ONLY | 2 | 仅独立组网的NR选择模式。 |  
| NR_OPTION_NSA_AND_SA | 3 | 非独立组网和独立组网的NR选择模式。 |  
    
## NetworkSearchResult    
网络搜索结果。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isNetworkSearchSuccess | boolean | false | true | 网络搜索成功。 |  
| networkSearchResult | Array<NetworkInformation> | false | true | 网络搜索结果。 |  
    
## NetworkInformation    
网络信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| operatorName | string | false | true | 运营商的名称。 |  
| operatorNumeric | string | false | true | 运营商数字。 |  
| state | NetworkInformationState | false | true | 网络信息状态。 |  
| radioTech | string | false | true | 无线电技术。 |  
    
## NetworkInformationState    
网络信息状态。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NETWORK_UNKNOWN | 0 | 网络状态未知。 |  
| NETWORK_AVAILABLE | 1 | 网络可用于注册。 |  
| NETWORK_CURRENT | 2 | 已在网络中注册。 |  
| NETWORK_FORBIDDEN | 3 | 网络无法注册。 |  
    
## NetworkSelectionModeOptions    
网络选择模式选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| slotId | number | false | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
| selectMode | NetworkSelectionMode | false | true | 网络选择模式。 |  
| networkInformation | NetworkInformation | false | true | 网络信息。 |  
| resumeSelection | boolean | false | true | 继续选择。 |  
    
## ImsRegState<sup>(9+)</sup>    
IMS注册状态。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| IMS_UNREGISTERED | 0 | 未注册。 |  
| IMS_REGISTERED | 1 | 已注册。 |  
    
## ImsRegTech<sup>(9+)</sup>    
IMS注册技术。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| REGISTRATION_TECH_NONE | 0 | 无注册技术。 |  
| REGISTRATION_TECH_LTE | 1 | LTE注册技术。 |  
| REGISTRATION_TECH_IWLAN | 2 | IWLAN注册技术。 |  
| REGISTRATION_TECH_NR | 3 | NR注册技术。 |  
    
## ImsRegInfo<sup>(9+)</sup>  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| imsRegState<sup>(9+)</sup> | ImsRegState | false | true |  |  
| imsRegTech<sup>(9+)</sup> | ImsRegTech | false | true |  |  
    
## ImsServiceType<sup>(9+)</sup>    
IMS服务类型。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_VOICE | 0 | 语音服务。 |  
| TYPE_VIDEO | 1 | 视频服务。 |  
| TYPE_UT | 2 | UT服务。 |  
| TYPE_SMS | 3 | 短讯服务。 |  
    
## NetworkCapabilityType<sup>(10+)</sup>    
网络能力类型。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SERVICE_TYPE_LTE | 0 | LTE服务类型。 |  
| SERVICE_TYPE_NR | 1 | NR服务类型。 |  
    
## NetworkCapabilityState<sup>(10+)</sup>    
网络能力开关状态。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SERVICE_CAPABILITY_OFF | 0 | 网络能力关闭。 |  
| SERVICE_CAPABILITY_ON | 1 | 网络能力打开。 |  
