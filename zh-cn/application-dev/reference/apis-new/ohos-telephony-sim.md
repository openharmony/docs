# @ohos.telephony.sim    
SIM卡管理模块提供了SIM卡管理的基础能力，包括获取指定卡槽SIM卡的名称、号码、ISO国家码、归属PLMN号、服务提供商名称、SIM卡状态、卡类型、是否插卡、是否激活、锁状态，设置指定卡槽SIM卡显示的名称、号码、锁状态，激活、禁用指定卡槽SIM卡，更改Pin密码，以及解锁指定卡槽SIM卡密码、SIM卡密码的解锁密码等。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import sim from '@ohos.telephony.sim'    
```  
    
## isSimActive<sup>(7+)</sup>    
获取指定卡槽SIM卡是否激活。  
 **调用形式：**     
    
- isSimActive(slotId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- isSimActive(slotId: number): Promise\<boolean>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回指定卡槽是否激活，如果激活返回true。 |  
| Promise<boolean> | 以Promise形式返回指定卡槽是否激活，如果激活返回true。 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.isSimActive(0, (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.isSimActive(0).then((data: boolean) => {  
    console.log(`isSimActive success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`isSimActive failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## isSimActiveSync<sup>(10+)</sup>    
获取指定卡槽SIM卡是否激活。  
 **调用形式：**     
- isSimActiveSync(slotId: number): boolean  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回指定卡槽是否激活，如果激活返回true。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let isSimActive: boolean = sim.isSimActiveSync(0);  
console.log(`the sim is active:` + isSimActive);  
    
```    
  
    
## getDefaultVoiceSlotId<sup>(7+)</sup>    
获取默认语音业务的卡槽ID。  
 **调用形式：**     
    
- getDefaultVoiceSlotId(callback: AsyncCallback\<number>): void    
起始版本： 7    
- getDefaultVoiceSlotId(): Promise\<number>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br />- 0：卡槽1<br />- 1：卡槽2<br />- -1：未设置或服务不可用 |  
| Promise<number> | 以Promise形式返回默认语音业务的卡槽ID。<br />- 0：卡槽1<br />- 1：卡槽2<br />- -1：未设置或服务不可用 |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getDefaultVoiceSlotId((err: BusinessError, data: number) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getDefaultVoiceSlotId().then((data: number) => {  
    console.log(`getDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## hasOperatorPrivileges<sup>(7+)</sup>    
检查应用（调用者）是否已被授予运营商权限。  
 **调用形式：**     
    
- hasOperatorPrivileges(slotId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- hasOperatorPrivileges(slotId: number): Promise\<boolean>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br />- 0：卡槽1<br />- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 返回检查应用（调用者）是否已被授予运营商权限。 |  
| Promise<boolean> | 以Promise形式返回检查应用（调用者）是否已被授予运营商权限。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.hasOperatorPrivileges(0, (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.hasOperatorPrivileges(0).then((data: boolean) => {  
    console.log(`hasOperatorPrivileges success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`hasOperatorPrivileges failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getISOCountryCodeForSim    
获取指定卡槽SIM卡的ISO国家码。  
 **调用形式：**     
    
- getISOCountryCodeForSim(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 6    
- getISOCountryCodeForSim(slotId: number): Promise\<string>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回获取指定卡槽SIM卡的ISO国家码，例如：CN（中国）。 |  
| Promise<string> | 以Promise形式返回获取指定卡槽SIM卡的ISO国家码，例如：CN（中国）。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getISOCountryCodeForSim(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getISOCountryCodeForSim(0).then((data: string) => {  
    console.log(`getISOCountryCodeForSim success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getISOCountryCodeForSim failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getISOCountryCodeForSimSync<sup>(10+)</sup>    
获取指定卡槽SIM卡的ISO国家码。  
 **调用形式：**     
- getISOCountryCodeForSimSync(slotId: number): string  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回获取指定卡槽SIM卡的ISO国家码，例如：CN（中国）。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let countryCode: string = sim.getISOCountryCodeForSimSync(0);  
console.log(`the country ISO is:` + countryCode);  
    
```    
  
    
## getSimOperatorNumeric    
获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号。  
 **调用形式：**     
    
- getSimOperatorNumeric(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 6    
- getSimOperatorNumeric(slotId: number): Promise\<string>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回指定卡槽SIM卡的归属PLMN号。 |  
| Promise<string> | 以Promise形式返回获取指定卡槽SIM卡的归属PLMN号。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimOperatorNumeric(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimOperatorNumeric(0).then((data: string) => {  
    console.log(`getSimOperatorNumeric success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getSimOperatorNumeric failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSimOperatorNumericSync<sup>(10+)</sup>    
获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号。  
 **调用形式：**     
- getSimOperatorNumericSync(slotId: number): string  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回获取指定卡槽SIM卡的归属PLMN号。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let numeric: string = sim.getSimOperatorNumericSync(0);  
console.log(`the sim operator numeric is:` + numeric);  
    
```    
  
    
## getSimSpn    
获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN）。  
 **调用形式：**     
    
- getSimSpn(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 6    
- getSimSpn(slotId: number): Promise\<string>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回指定卡槽SIM卡的SPN。 |  
| Promise<string> | 以Promise形式返回获取指定卡槽SIM卡的SPN。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimSpn(0, (err: BusinessError, data: string) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimSpn(0).then((data: string) => {  
    console.log(`getSimSpn success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getSimSpn failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSimSpnSync<sup>(10+)</sup>    
获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN）。  
 **调用形式：**     
- getSimSpnSync(slotId: number): string  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回获取指定卡槽SIM卡的SPN。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let spn: string = sim.getSimSpnSync(0);  
console.log(`the sim card spn is:` + spn);  
    
```    
  
    
## getSimState    
获取指定卡槽的SIM卡状态。  
 **调用形式：**     
    
- getSimState(slotId: number, callback: AsyncCallback\<SimState>): void    
起始版本： 6    
- getSimState(slotId: number): Promise\<SimState>    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参考[SimState](#simstate)。 |  
| Promise<SimState> | 以Promise形式返回获取指定卡槽的SIM卡状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimState(0, (err: BusinessError, data: sim.SimState) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimState(0).then((data: sim.SimState) => {  
    console.log(`getSimState success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getSimState failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getSimStateSync<sup>(10+)</sup>    
获取指定卡槽的SIM卡状态。  
 **调用形式：**     
- getSimStateSync(slotId: number): SimState  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| SimState | 返回获取指定卡槽的SIM卡状态。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let simState: sim.SimState = sim.getSimStateSync(0);  
console.log(`The sim state is:` + simState);  
    
```    
  
    
## getCardType<sup>(7+)</sup>    
获取指定卡槽SIM卡的卡类型。  
 **调用形式：**     
    
- getCardType(slotId: number, callback: AsyncCallback\<CardType>): void    
起始版本： 7    
- getCardType(slotId: number): Promise\<CardType>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<CardType> | 以Promise形式返回指定卡槽SIM卡的卡类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getCardType(0, (err: BusinessError, data: sim.CardType) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getCardType(0).then((data: sim.CardType) => {  
    console.log(`getCardType success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getCardType failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getCardTypeSync<sup>(10+)</sup>    
获取指定卡槽SIM卡的卡类型。  
 **调用形式：**     
- getCardTypeSync(slotId: number): CardType  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| CardType | 返回指定卡槽SIM卡的卡类型。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let cardType: sim.CardType = sim.getCardTypeSync(0);  
console.log(`the card type is:` + cardType);  
    
```    
  
    
## getMaxSimCount<sup>(7+)</sup>    
获取卡槽数量。  
 **调用形式：**     
- getMaxSimCount(): number  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 卡槽数量。 |  
    
 **示例代码：**   
```ts    
import sim from '@ohos.telephony.sim';console.log("Result: "+ sim.getMaxSimCount());    
```    
  
    
## hasSimCard<sup>(7+)</sup>    
获取指定卡槽SIM卡是否插卡。  
 **调用形式：**     
    
- hasSimCard(slotId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 7    
- hasSimCard(slotId: number): Promise\<boolean>    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | <span style="letter-spacing: 0px;">卡槽ID。</span>。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调返回指定卡槽是否插卡，如果插卡返回true。 |  
| Promise<boolean> | 以Promise形式返回指定卡槽是否插卡，如果插卡返回true。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.hasSimCard(0, (err: BusinessError, data: boolean) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.hasSimCard(0).then((data: boolean) => {  
    console.log(`hasSimCard success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`hasSimCard failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## hasSimCardSync<sup>(10+)</sup>    
获取指定卡槽SIM卡是否插卡。  
 **调用形式：**     
- hasSimCardSync(slotId: number): boolean  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回指定卡槽是否插卡，如果插卡返回true。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let hasSimCard: boolean = sim.hasSimCardSync(0);  
console.log(`has sim card: ` + hasSimCard);  
    
```    
  
    
## getSimAccountInfo<sup>(10+)</sup>    
获取SIM卡帐户信息。  
 **调用形式：**     
    
- getSimAccountInfo(slotId: number, callback: AsyncCallback\<IccAccountInfo>): void    
起始版本： 10    
- getSimAccountInfo(slotId: number): Promise\<IccAccountInfo>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回指定卡槽SIM卡的帐户信息。 |  
| Promise<IccAccountInfo> | 以Promise形式返回指定卡槽SIM卡的帐户信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301002 | SIM card operation error. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimAccountInfo(0, (err:BusinessError , data: sim.IccAccountInfo) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getSimAccountInfo(0).then((data: sim.IccAccountInfo) => {  
    console.log(`getSimAccountInfo success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getSimAccountInfo failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getActiveSimAccountInfoList<sup>(10+)</sup>    
获取激活SIM卡帐户信息列表。  
 **调用形式：**     
    
- getActiveSimAccountInfoList(callback: AsyncCallback\<Array\<IccAccountInfo>>): void    
起始版本： 10    
- getActiveSimAccountInfoList(): Promise\<Array\<IccAccountInfo>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Telephony.CoreService  
 **需要权限：** ohos.permission.GET_TELEPHONY_STATE    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回激活SIM卡帐户信息列表。 |  
| Promise<Array<IccAccountInfo>> | 以Promise形式返回激活卡槽SIM卡的帐户信息列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getActiveSimAccountInfoList((err: BusinessError, data: Array<sim.IccAccountInfo>) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getActiveSimAccountInfoList().then((data: Array<sim.IccAccountInfo>) => {  
    console.log(`getActiveSimAccountInfoList success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getActiveSimAccountInfoList failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## getOpKey<sup>(9+)</sup>    
获取指定卡槽中SIM卡的opkey。  
 **调用形式：**     
    
- getOpKey(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 9    
- getOpKey(slotId: number): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回指定卡槽中SIM卡的opkey。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 801 |  |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
try {  
    sim.getOpKey(0, (err: BusinessError, data: string) => {  
    if (err) {  
      console.log("getOpKey failed, err: " + JSON.stringify(err));  
    } else {  
      console.log('getOpKey successfully, data: ' + JSON.stringify(data));  
    }  
  });  
} catch (err) {  
  console.log("getOpKey err: " + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
try {  
    let data: Promise<string> = sim.getOpKey(0);  
    console.log(`getOpKey success, promise: data->${JSON.stringify(data)}`);  
} catch (error) {  
    console.log(`getOpKey failed, promise: err->${JSON.stringify(error)}`);  
}  
    
```    
  
    
## getOpKeySync<sup>(10+)</sup>    
获取指定卡槽中SIM卡的opkey。  
 **调用形式：**     
- getOpKeySync(slotId: number): string  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回指定卡槽中SIM卡的opkey。 |  
    
 **示例代码：**   
```ts    
import sim from '@ohos.telephony.sim';  
let data: string = sim.getOpKeySync(0);console.log(`getOpKey success, promise: data->${JSON.stringify(data)}`);    
```    
  
    
## getOpName<sup>(9+)</sup>    
获取指定卡槽中SIM卡的OpName。  
 **调用形式：**     
    
- getOpName(slotId: number, callback: AsyncCallback\<string>): void    
起始版本： 9    
- getOpName(slotId: number): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
| Promise<string> | 以Promise形式返回指定卡槽中SIM卡的OpName。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 801 |  |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
try {  
    sim.getOpName(0, (err: BusinessError, data: string) => {  
    if (err) {  
      console.log("getOpName failed, err: " + JSON.stringify(err));  
    } else {  
      console.log('getOpName successfully, data: ' + JSON.stringify(data));  
    }  
  });  
} catch (err) {  
  console.log("getOpName err: " + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
try {  
    let data: Promise<string> = sim.getOpName(0);  
    console.log(`getOpName success, promise: data->${JSON.stringify(data)}`);  
} catch (error) {  
    console.log(`getOpName failed, promise: err->${JSON.stringify(error)}`);  
}  
    
```    
  
    
## getOpNameSync<sup>(10+)</sup>    
获取指定卡槽中SIM卡的OpName。  
 **调用形式：**     
- getOpNameSync(slotId: number): string  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| slotId | number | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回指定卡槽中SIM卡的OpName。 |  
    
 **示例代码：**   
```ts    
import sim from '@ohos.telephony.sim';  
let data: string = sim.getOpNameSync(0);console.log(`getOpName success, promise: data->${JSON.stringify(data)}`);    
```    
  
    
## getDefaultVoiceSimId<sup>(10+)</sup>    
获取默认语音业务的SIM卡ID。  
 **调用形式：**     
    
- getDefaultVoiceSimId(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getDefaultVoiceSimId(): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Telephony.CoreService    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。<br/>与SIM卡绑定，从1开始递增。 |  
| Promise<number> | 以Promise形式返回默认语音业务的SIM卡ID。<br/>与SIM卡绑定，从1开始递增。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service. |  
| 8300003 | System internal error. |  
| 8300004 | Do not have sim card. |  
| 8300999 | Unknown error code. |  
| 8301001 | SIM card is not activated. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
sim.getDefaultVoiceSimId((err: BusinessError, data: number) => {  
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
import { BusinessError } from '@ohos.base';  
import sim from '@ohos.telephony.sim';  
  
let promise = sim.getDefaultVoiceSimId();  
promise.then((data: number) => {  
    console.log(`getDefaultVoiceSimId success, promise: data->${JSON.stringify(data)}`);  
}).catch((err: BusinessError) => {  
    console.log(`getDefaultVoiceSimId failed, promise: err->${JSON.stringify(err)}`);  
});  
    
```    
  
    
## IccAccountInfo<sup>(10+)</sup>    
Icc帐户信息。  
 **系统能力:**  SystemCapability.Telephony.CoreService    
### 属性    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| simId<sup>(10+)</sup> | number | false | true | SIM卡ID。 |  
| slotIndex<sup>(10+)</sup> | number | false | true | 卡槽ID。 |  
| isEsim<sup>(10+)</sup> | boolean | false | true | 标记卡是否是eSim。 |  
| isActive<sup>(10+)</sup> | boolean | false | true | 卡是否被激活。 |  
| iccId<sup>(10+)</sup> | string | false | true | ICCID号码。 |  
| showName<sup>(10+)</sup> | string | false | true | SIM卡显示名称。 |  
| showNumber<sup>(10+)</sup> | string | false | true | SIM卡显示号码。 |  
    
## CardType<sup>(7+)</sup>    
卡类型。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN_CARD | -1 | 未知类型。 |  
| SINGLE_MODE_SIM_CARD | 10 | 单SIM卡。 |  
| SINGLE_MODE_USIM_CARD | 20 | 单USIM卡。 |  
| SINGLE_MODE_RUIM_CARD | 30 | 单RUIM卡。 |  
| DUAL_MODE_CG_CARD | 40 | 双卡模式C+G。 |  
| CT_NATIONAL_ROAMING_CARD | 41 | 中国电信内部漫游卡。 |  
| CU_DUAL_MODE_CARD | 42 | 中国联通双模卡。 |  
| DUAL_MODE_TELECOM_LTE_CARD | 43 | 双模式电信LTE卡。 |  
| DUAL_MODE_UG_CARD | 50 | 双模式UG卡。 |  
| SINGLE_MODE_ISIM_CARD<sup>(8+)</sup> | 60 | 单一ISIM卡类型。 |  
    
## SimState    
SIM卡状态。    
    
 **系统能力:**  SystemCapability.Telephony.CoreService    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SIM_STATE_UNKNOWN | 0 | SIM卡状态未知，即无法获取准确的状态。 |  
| SIM_STATE_NOT_PRESENT | 1 | 表示SIM卡处于not present状态，即卡槽中没有插入SIM卡。 |  
| SIM_STATE_LOCKED | 2 | 表示SIM卡处于locked状态，即SIM卡被PIN、PUK或网络锁锁定。 |  
| SIM_STATE_NOT_READY | 3 | 表示SIM卡处于not ready状态，即SIM卡在位但无法正常工作。 |  
| SIM_STATE_READY | 4 | 表示SIM卡处于ready状态，即SIM卡在位且工作正常。 |  
| SIM_STATE_LOADED | 5 | 表示SIM卡处于loaded状态，即SIM卡在位且所有卡文件加载完毕。 |  
