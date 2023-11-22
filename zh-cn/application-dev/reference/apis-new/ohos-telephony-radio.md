# @ohos.telephony.radio    
网络搜索模块提供管理网络搜索的一些基础功能，包括获取当前接入的CS域和PS域无线接入技术、获取网络状态、获取当前选网模式、获取注册网络所在国家的ISO国家码、获取主卡所在卡槽的索引号、获取指定SIM卡槽对应的注册网络信号强度信息列表、获取运营商名称、获取设备的指定卡槽的IMEI、获取设备的指定卡槽的MEID、获取设备的指定卡槽的唯一设备ID，判断当前设备是否支持5G\(NR\)、判断主卡的Radio是否打开等。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import radio from '@ohos.telephony.radio'    
```  
    
## getRadioTech    
获取当前接入的CS域和PS域无线接入技术。  
 **调用形式：**     
    
- getRadioTech(slotId: number,     callback: AsyncCallback\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>): void    
起始版本： 6    
- getRadioTech(slotId: number): Promise\<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<{psRadioTech: RadioTechnology, csRadioTech: RadioTechnology}> | 以Promise形式返回获取当前接入的CS域和PS域技术。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
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
class Tech {  
    psRadioTech: radio.RadioTechnology = radio.RadioTechnology.RADIO_TECHNOLOGY_UNKNOWN;  
    csRadioTech: radio.RadioTechnology = radio.RadioTechnology.RADIO_TECHNOLOGY_UNKNOWN;  
}  
radio.getRadioTech(slotId, (err: BusinessError, data: Tech) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
class Tech {  
    psRadioTech: radio.RadioTechnology = radio.RadioTechnology.RADIO_TECHNOLOGY_UNKNOWN;  
    csRadioTech: radio.RadioTechnology = radio.RadioTechnology.RADIO_TECHNOLOGY_UNKNOWN;  
}  
radio.getRadioTech(slotId).then((data: Tech) => {  
    console.log(`getRadioTech success, data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getRadioTech failed, err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getNetworkState    
获取网络状态。  
 **调用形式：**     
    
- getNetworkState(slotId: number, callback: AsyncCallback\<NetworkState>): void    
起始版本： 6    
- getNetworkState(slotId?: number): Promise\<NetworkState>    
起始版本： 6    
- getNetworkState(callback: AsyncCallback\<NetworkState>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<NetworkState> | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
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
radio.getNetworkState(slotId, (err: BusinessError, data: radio.NetworkState) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getNetworkState(slotId).then((data: radio.NetworkState) => {  
    console.log(`getNetworkState success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getNetworkState failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getNetworkSelectionMode    
获取当前选网模式。  
 **调用形式：**     
    
- getNetworkSelectionMode(slotId: number, callback: AsyncCallback\<NetworkSelectionMode>): void    
起始版本： 6    
- getNetworkSelectionMode(slotId: number): Promise\<NetworkSelectionMode>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<NetworkSelectionMode> | 以Promise形式返回当前选网模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
radio.getNetworkSelectionMode(slotId, (err: BusinessError, data: radio.NetworkSelectionMode) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getNetworkSelectionMode(slotId).then((data: radio.NetworkSelectionMode) => {  
    console.log(`getNetworkSelectionMode success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getNetworkSelectionMode failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getISOCountryCodeForNetwork<sup>(7+)</sup>    
获取注册网络所在国家的ISO国家码。  
 **调用形式：**     
    
- getISOCountryCodeForNetwork(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 7    
- getISOCountryCodeForNetwork(slotId: number): Promise\<string>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回国家码，例如：CN（中国）。 |  
| Promise<string> | 以Promise形式返回注册网络所在国家的ISO国家码，例如CN（中国）。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Invalid parameter value. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getISOCountryCodeForNetwork(slotId, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getNetworkSelectionMode(slotId).then((data: radio.NetworkSelectionMode) => {  
    console.log(`getNetworkSelectionMode success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getNetworkSelectionMode failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getISOCountryCodeForNetworkSync<sup>(10+)</sup>    
获取注册网络所在国家的ISO国家码。  
 **调用形式：**     
- getISOCountryCodeForNetworkSync(slotId: number): string  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回注册网络所在国家的ISO国家码，例如CN（中国）。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let countryISO: string = radio.getISOCountryCodeForNetworkSync(slotId);  
console.log(`the country ISO is:` + countryISO);  
    
```    
  
    
## getPrimarySlotId<sup>(7+)</sup>    
获取主卡所在卡槽的索引号。  
 **调用形式：**     
    
- getPrimarySlotId(callback: AsyncCallback\<number>): void    
起始版本： 7    
- getPrimarySlotId(): Promise\<number>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数 |  
| Promise<number> | 以Promise形式返回获取设备主卡所在卡槽的索引号的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
radio.getPrimarySlotId((err: BusinessError, data: number) => {  
   console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
radio.getPrimarySlotId().then((data: number) => {  
    console.log(`getPrimarySlotId success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getPrimarySlotId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSignalInformation<sup>(7+)</sup>    
获取指定SIM卡槽对应的注册网络信号强度信息列表。  
 **调用形式：**     
    
- getSignalInformation(slotId: number, callback: AsyncCallback\<Array\<SignalInformation>>): void    
起始版本： 7    
- getSignalInformation(slotId: number): Promise\<Array\<SignalInformation>>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回[SignalInformation](#signalinformation)对象的数组。 |  
| Promise<Array<SignalInformation>> | 以Promise形式返回网络信号强度[SignalInformation](#signalinformation)对象的数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
radio.getSignalInformation(slotId, (err: BusinessError, data: Array<radio.SignalInformation>) => {  
   console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getSignalInformation(slotId).then((data: Array<radio.SignalInformation>) => {  
    console.log(`getSignalInformation success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`getSignalInformation failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSignalInformationSync<sup>(10+)</sup>    
获取指定SIM卡槽对应的注册网络信号强度信息列表。  
 **调用形式：**     
- getSignalInformationSync(slotId: number): Array\<SignalInformation>  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<SignalInformation> | 返回网络信号强度[SignalInformation](#signalinformation)对象的数组。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let signalInfo: Array<radio.SignalInformation> = radio.getSignalInformationSync(slotId);  
console.log(`signal information size is:` + signalInfo.length);  
    
```    
  
    
## isNrSupported<sup>(deprecated)</sup>    
判断当前设备是否支持5G\(NR\)。  
 **调用形式：**     
- isNrSupported(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: telephony.radio#isNRSupported。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | - true：支持<br/>- false：不支持 |  
    
 **示例代码：**   
```ts    
let result: boolean = radio.isNrSupported();  
console.log("Result: "+ result);    
```    
  
    
## isNrSupported<sup>(deprecated)</sup>    
判断当前设备是否支持5G\(NR\)。  
 **调用形式：**     
- isNrSupported(slotId: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: telephony.radio#isNRSupported。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId<sup>(deprecated)</sup> | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | - true：支持<br/>- false：不支持 |  
    
 **示例代码：**   
```ts    
let slotId: number = 0;  
let result: boolean = radio.isNrSupported(slotId);  
console.log("Result: "+ result);    
```    
  
    
## isNRSupported<sup>(9+)</sup>    
判断当前设备是否支持5G\(NR\)。  
 **调用形式：**     
- isNRSupported(): boolean  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | - true：支持<br/>- false：不支持 |  
    
 **示例代码：**   
```ts    
let result: boolean = radio.isNRSupported();  
console.log("Result: "+ result);    
```    
  
    
## isNRSupported<sup>(9+)</sup>  
 **调用形式：**     
- isNRSupported(slotId: number): boolean  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | - true：支持<br/>- false：不支持 |  
    
 **示例代码：**   
```ts    
let slotId: number = 0;  
let result: boolean = radio.isNRSupported(slotId);  
console.log("Result: "+ result);    
```    
  
    
## isRadioOn<sup>(7+)</sup>    
判断主卡的Radio是否打开。  
 **调用形式：**     
    
- isRadioOn(slotId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- isRadioOn(slotId?: number): Promise\<boolean>    
起始版本： 7    
- isRadioOn(callback: AsyncCallback\<boolean>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br/>- true：Radio打开<br/>- false：Radio关闭 |  
| Promise<boolean> | 以Promise形式返回判断Radio是否打开的结果。<br/>- true：Radio打开<br/>- false：Radio关闭 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
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
radio.isRadioOn(slotId, (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.isRadioOn(slotId).then((data: boolean) => {  
    console.log(`isRadioOn success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.error(`isRadioOn failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getOperatorName<sup>(7+)</sup>    
获取运营商名称。  
 **调用形式：**     
    
- getOperatorName(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 7    
- getOperatorName(slotId: number): Promise\<string>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回运营商名称，例如：中国移动。 |  
| Promise<string> | 以Promise形式返回运营商名称，例如：中国移动。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
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
radio.getOperatorName(slotId, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
radio.getOperatorName(slotId).then((data: string) => {  
    console.log(`getOperatorName success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getOperatorName failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getOperatorNameSync<sup>(10+)</sup>    
获取运营商名称。  
 **调用形式：**     
- getOperatorNameSync(slotId: number): string  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回运营商名称，例如：中国移动。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
let slotId: number = 0;  
let operatorName: string = radio.getOperatorNameSync(slotId);  
console.log(`operator name is:` + operatorName);  
    
```    
  
    
## RadioTechnology    
无线接入技术。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| RADIO_TECHNOLOGY_UNKNOWN | 0 | 未知无线接入技术（RAT）。 |  
| RADIO_TECHNOLOGY_GSM | 1 | 无线接入技术GSM（Global System For Mobile Communication）。 |  
| RADIO_TECHNOLOGY_1XRTT | 2 | 无线接入技术1XRTT（Single-Carrier Radio Transmission Technology）。 |  
| RADIO_TECHNOLOGY_WCDMA | 3 | 无线接入技术WCDMA（Wideband Code Division Multiple Access）。 |  
| RADIO_TECHNOLOGY_HSPA | 4 | 无线接入技术HSPA（High Speed Packet Access）。 |  
| RADIO_TECHNOLOGY_HSPAP | 5 | 无线接入技术HSPAP（High Speed packet access (HSPA+) ）。 |  
| RADIO_TECHNOLOGY_TD_SCDMA | 6 | 无线接入技术TDSCDMA（TimeDivision-Synchronous Code Division Multiple Access）。 |  
| RADIO_TECHNOLOGY_EVDO | 7 | 无线接入技术EVDO（Evolution Data Only）。 |  
| RADIO_TECHNOLOGY_EHRPD | 8 | 无线接入技术EHRPD（Evolved High Rate Package Data）。 |  
| RADIO_TECHNOLOGY_LTE | 9 | 无线接入技术LTE（Long Term Evolution）。 |  
| RADIO_TECHNOLOGY_LTE_CA | 10 | 无线接入技术LTE_CA（Long Term Evolution_Carrier Aggregation）。 |  
| RADIO_TECHNOLOGY_IWLAN | 11 | 无线接入技术IWLAN（Industrial Wireless LAN）。 |  
| RADIO_TECHNOLOGY_NR | 12 | 无线接入技术NR（New Radio）。 |  
    
## SignalInformation    
网络信号强度信息对象。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| signalType | NetworkType | false | true | 网络信号强度类型。 |  
| signalLevel | number | false | true | 网络信号强度等级。 |  
| dBm<sup>(9+)</sup> | number | false | true | 网络信号强度。 |  
    
## NetworkType    
网络类型。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NETWORK_TYPE_UNKNOWN | 0 | 未知网络类型。 |  
| NETWORK_TYPE_GSM | 1 | 网络类型为GSM（Global System For Mobile Communication）。 |  
| NETWORK_TYPE_CDMA | 2 | 网络类型为CDMA（Code Division Multiple Access）。 |  
| NETWORK_TYPE_WCDMA | 3 | 网络类型为WCDMA（Wideband Code Division Multiple Access）。 |  
| NETWORK_TYPE_TDSCDMA | 4 | 网络类型为TDSCDMA（TimeDivision-Synchronous Code Division Multiple Access）。 |  
| NETWORK_TYPE_LTE | 5 | 网络类型为LTE（Long Term Evolution）。 |  
| NETWORK_TYPE_NR | 6 | 网络类型为5G NR（New Radio）。 |  
    
## NetworkState    
网络注册状态。  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| longOperatorName | string | false | true | 注册网络的长运营商名称。 |  
| shortOperatorName | string | false | true | 注册网络的短运营商名称。 |  
| plmnNumeric | string | false | true | 注册网络的PLMN码。 |  
| isRoaming | boolean | false | true | 是否处于漫游状态。 |  
| regState | RegState | false | true | 设备的网络注册状态。 |  
| cfgTech<sup>(8+)</sup> | RadioTechnology | false | true | 设备的无线接入技术。 |  
| nsaState | NsaState | false | true | 设备的NSA网络注册状态。 |  
| isCaActive | boolean | false | true | CA的状态。 |  
| isEmergency | boolean | false | true | 此设备是否只允许拨打紧急呼叫。 |  
    
## RegState    
网络注册状态。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| REG_STATE_NO_SERVICE | 0 | 设备不能使用任何服务，包括数据业务、短信、通话等。 |  
| REG_STATE_IN_SERVICE | 1 | 设备可以正常使用服务，包括数据业务、短信、通话等。 |  
| REG_STATE_EMERGENCY_CALL_ONLY | 2 | 设备只能使用紧急呼叫业务。 |  
| REG_STATE_POWER_OFF | 3 |  蜂窝无线电已关闭，modem下电，无法和网侧进行通信。 |  
    
## NsaState    
非独立组网状态。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NSA_STATE_NOT_SUPPORT | 1 | 设备在不支持NSA的LTE小区下处于空闲状态或连接状态。 |  
| NSA_STATE_NO_DETECT | 2 | 在支持NSA但不支持NR覆盖检测的LTE小区下，设备处于空闲状态。 |  
| NSA_STATE_CONNECTED_DETECT | 3 | 设备在LTE小区下连接到LTE网络支持NSA和NR覆盖检测。 |  
| NSA_STATE_IDLE_DETECT | 4 | 支持NSA和NR覆盖检测的LTE小区下设备处于空闲状态。 |  
| NSA_STATE_DUAL_CONNECTED | 5 | 设备在支持NSA的LTE小区下连接到LTE + NR网络。 |  
| NSA_STATE_SA_ATTACHED | 6 | 设备在5GC附着时在NG-RAN小区下空闲或连接到NG-RAN小区。 |  
    
## CellInformation<sup>(8+)</sup>    
小区信息。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| networkType<sup>(8+)</sup> | NetworkType | false | true | 获取服务单元的网络类型。 |  
| signalInformation<sup>(8+)</sup> | SignalInformation | false | true | 信号信息。 |  
    
## NetworkSelectionMode    
选网模式。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NETWORK_SELECTION_UNKNOWN | 0 | 未知选网模式。 |  
| NETWORK_SELECTION_AUTOMATIC | 1 | 自动选网模式。 |  
| NETWORK_SELECTION_MANUAL | 2 | 手动选网模式。 |  
