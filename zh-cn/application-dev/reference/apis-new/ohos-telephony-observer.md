# @ohos.telephony.observer    
本模块提供订阅管理功能，可以订阅/取消订阅的事件包括：网络状态变化、信号状态变化、通话状态变化、蜂窝数据链路连接状态、蜂窝数据业务的上下行数据流状态、SIM状态变化。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import observer from '@ohos.telephony.observer'    
```  
    
## on('networkStateChange')    
订阅指定卡槽位的网络状态变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'networkStateChange', callback: Callback\<NetworkState>): void    
起始版本： 6    
- on(type: 'networkStateChange', options: { slotId: number }, callback: Callback\<NetworkState>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry  
 **需要权限：** ohos.permission.GET_NETWORK_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 网络状态变化事件，参数固定为'networkStateChange'。 |  
| options | { slotId: number } | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参考radio的[NetworkState](js-apis-radio.md#networkstate) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
class SlotId {  
    slotId: number = 0  
}  
let id: SlotId = {slotId: 0}  
observer.on('networkStateChange', id, (data: observer.NetworkState) => {  
    console.log("on networkStateChange, data:" + JSON.stringify(data));  
});  
    
```    
  
    
## off('networkStateChange')    
取消订阅网络状态变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'networkStateChange', callback?: Callback\<NetworkState>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 网络状态变化事件，参数固定为'networkStateChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参考radio的[NetworkState](js-apis-radio.md#networkstate) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
let callback: (data: observer.NetworkState) => void = (data: observer.NetworkState) => {    console.log("on networkStateChange, data:" + JSON.stringify(data));}observer.on('networkStateChange', callback);// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。observer.off('networkStateChange', callback);observer.off('networkStateChange');    
```    
  
    
## on('signalInfoChange')    
订阅信号状态变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'signalInfoChange', callback: Callback\<Array\<SignalInformation>>): void    
起始版本： 6    
- on(type: 'signalInfoChange', options: { slotId: number }, callback: Callback\<Array\<SignalInformation>>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 信号状态变化事件，参数固定为'signalInfoChange'。 |  
| options | { slotId: number } | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  <br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参考radio的[SignalInformation](js-apis-radio.md#signalinformation)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import radio from '@ohos.telephony.radio';  
  
class SlotId {  
    slotId: number = 0  
}  
let id: SlotId = {slotId: 0}  
observer.on('signalInfoChange', id, (data: Array<radio.SignalInformation>) => {  
    console.log("on signalInfoChange, data:" + JSON.stringify(data));  
});  
    
```    
  
    
## off('signalInfoChange')    
取消订阅信号状态变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'signalInfoChange', callback?: Callback\<Array\<SignalInformation>>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | <span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">信号状态变化事件，参数固定为'signalInfoChange'。</span><br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。参考radio的[SignalInformation](js-apis-radio.md#signalinformation) |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import radio from '@ohos.telephony.radio';  
let callback: (data: Array<radio.SignalInformation>) => void = (data: Array<radio.SignalInformation>) => {    console.log("on signalInfoChange, data:" + JSON.stringify(data));}observer.on('signalInfoChange', callback);// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。observer.off('signalInfoChange', callback);observer.off('signalInfoChange');    
```    
  
    
## on('cellularDataConnectionStateChange')<sup>(7+)</sup>    
订阅蜂窝数据链路连接状态，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'cellularDataConnectionStateChange',     callback: Callback\<{ state: DataConnectState, network: RatType }>): void    
起始版本： 7    
- on(type: 'cellularDataConnectionStateChange', options: { slotId: number },     callback: Callback\<{ state: DataConnectState, network: RatType }>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 蜂窝数据链路连接状态事件，参数固定为'cellularDataConnectionStateChange'。 |  
| options | { slotId: number } | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参考data的[DataConnectState](js-apis-telephony-data.md#dataconnectstate)，radio的[RadioTechnology](js-apis-radio.md#radiotechnology)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import data from '@ohos.telephony.data';  
import radio from '@ohos.telephony.radio';  
  
class Value {  
    state: data.DataConnectState = data.DataConnectState.DATA_STATE_UNKNOWN  
    network: radio.RadioTechnology = radio.RadioTechnology.RADIO_TECHNOLOGY_UNKNOWN  
}  
class SlotId {  
    slotId: number = 0  
}  
let id: SlotId = {slotId: 0}  
observer.on('cellularDataConnectionStateChange', id, (value: Value) => {  
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);  
});  
    
```    
  
    
## off('cellularDataConnectionStateChange')<sup>(7+)</sup>    
移除订阅蜂窝数据链路连接状态，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'cellularDataConnectionStateChange',     callback?: Callback\<{ state: DataConnectState, network: RatType }>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 蜂窝数据链路连接状态事件，参数固定为'cellularDataConnectionStateChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参考data的[DataConnectState](js-apis-telephony-data.md#dataconnectstate)，radio的[RadioTechnology](js-apis-radio.md#radiotechnology)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import data from '@ohos.telephony.data';  
import radio from '@ohos.telephony.radio';  
  
class Value {  
    state: data.DataConnectState = data.DataConnectState.DATA_STATE_UNKNOWN  
    network: radio.RadioTechnology = radio.RadioTechnology.RADIO_TECHNOLOGY_UNKNOWN  
}  
let callback: (value: Value) => void = (value: Value) => {  
    console.log("on cellularDataConnectionStateChange, state:" + value.state + ", network:" + value.network);  
}  
observer.on('cellularDataConnectionStateChange', callback);  
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。  
observer.off('cellularDataConnectionStateChange', callback);  
observer.off('cellularDataConnectionStateChange');  
    
```    
  
    
## on('cellularDataFlowChange')<sup>(7+)</sup>    
订阅蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'cellularDataFlowChange', callback: Callback\<DataFlowType>): void    
起始版本： 7    
- on(type: 'cellularDataFlowChange', options: { slotId: number }, callback: Callback\<DataFlowType>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 蜂窝数据业务的上下行数据流状态状态事件，参数固定为'cellularDataFlowChange'。 |  
| options | { slotId: number } | true | 槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参考data的[DataFlowType](js-apis-telephony-data.md#dataflowtype)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import data from '@ohos.telephony.data';  
  
class SlotId {  
    slotId: number = 0  
}  
let id: SlotId = {slotId: 0}  
observer.on('cellularDataFlowChange', id, (data: data.DataFlowType) => {  
    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));  
});  
    
```    
  
    
## off('cellularDataFlowChange')<sup>(7+)</sup>    
移除订阅蜂窝数据业务的上下行数据流状态，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'cellularDataFlowChange', callback?: Callback\<DataFlowType>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 蜂窝数据业务的上下行数据流状态状态事件，参数固定为'cellularDataFlowChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参考data的[DataFlowType](js-apis-telephony-data.md#dataflowtype)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import data from '@ohos.telephony.data';  
let callback: (data: data.DataFlowType) => void = (data: data.DataFlowType) => {    console.log("on cellularDataFlowChange, data:" + JSON.stringify(data));}observer.on('cellularDataFlowChange', callback);// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。observer.off('cellularDataFlowChange', callback);observer.off('cellularDataFlowChange');    
```    
  
    
## on('callStateChange')    
订阅通话状态变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'callStateChange', callback: Callback\<{ state: CallState, number: string }>): void    
起始版本： 6    
- on(type: 'callStateChange', options: { slotId: number }, callback: Callback\<{ state: CallState, number: string }>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 通话状态变化事件，参数固定为'callStateChange'。 |  
| options | { slotId: number } | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参考call的[CallState](js-apis-call.md#callstate)<br />number：电话号码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import call from '@ohos.telephony.call';  
  
class Value {  
    state: call.CallState = call.CallState.CALL_STATE_UNKNOWN  
    number: string = ""  
}  
class SlotId {  
    slotId: number = 0  
}  
let id: SlotId = {slotId: 0}  
observer.on('callStateChange', id, (value: Value) => {  
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);  
});  
    
```    
  
    
## off('callStateChange')    
取消订阅通话状态变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'callStateChange', callback?: Callback\<{ state: CallState, number: string }>): void    
起始版本： 6  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 通话状态变化事件，参数固定为'callStateChange'。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，参考call的[CallState](js-apis-call.md#callstate)<br />number：电话号码 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
import call from '@ohos.telephony.call';  
  
class Value {  
    state: call.CallState = call.CallState.CALL_STATE_UNKNOWN  
    number: string = ""  
}  
let callback: (value: Value) => void = (value: Value) => {  
    console.log("on callStateChange, state:" + value.state + ", number:" + value.number);  
}  
observer.on('callStateChange', callback);  
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。  
observer.off('callStateChange', callback);  
observer.off('callStateChange');  
    
```    
  
    
## on('simStateChange')<sup>(7+)</sup>    
订阅sim状态更改事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'simStateChange', callback: Callback\<SimStateData>): void    
起始版本： 7    
- on(type: 'simStateChange', options: { slotId: number }, callback: Callback\<SimStateData>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | sim状态更改事件，参数固定为'simStateChange'。 |  
| options | { slotId: number } | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
class SlotId {  
    slotId: number = 0  
}  
let id: SlotId = {slotId: 0}  
observer.on('simStateChange', id, (data: observer.SimStateData) => {  
    console.log("on simStateChange, data:" + JSON.stringify(data));  
});  
    
```    
  
    
## off('simStateChange')<sup>(7+)</sup>    
移除订阅sim状态更改事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'simStateChange', callback?: Callback\<SimStateData>): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | sim状态更改事件，参数固定为'simStateChange'。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
let callback: (data: observer.SimStateData) => void = (data: observer.SimStateData) => {    console.log("on simStateChange, data:" + JSON.stringify(data));}observer.on('simStateChange', callback);// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。observer.off('simStateChange', callback);observer.off('simStateChange');    
```    
  
    
## on('iccAccountInfoChange')<sup>(10+)</sup>    
订阅卡帐户变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'iccAccountInfoChange', callback: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 卡帐户变化事件，参数固定为'iccAccountInfoChange'。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
observer.on('iccAccountInfoChange', () => {    console.log("on iccAccountInfoChange success");});    
```    
  
    
## off('iccAccountInfoChange')<sup>(10+)</sup>    
移除订阅卡帐户变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'iccAccountInfoChange', callback?: Callback\<void>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 卡帐户变化事件，参数固定为'iccAccountInfoChange'。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```ts    
let callback: () => void = () => {    console.log("on iccAccountInfoChange success");}observer.on('iccAccountInfoChange', callback);// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。observer.off('iccAccountInfoChange', callback);observer.off('iccAccountInfoChange');    
```    
  
    
## SimStateData<sup>(7+)</sup>    
SIM卡类型和状态。  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
### 属性    
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(7+)</sup> | CardType | false | true | SIM卡类型。 |  
| state<sup>(7+)</sup> | SimState | false | true | SIM卡状态。 |  
| reason<sup>(8+)</sup> | LockReason | false | true | SIM卡锁类型。 |  
    
## LockReason<sup>(8+)</sup>    
SIM卡锁类型。    
    
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SIM_NONE | 0 | 无锁。  |  
| SIM_PIN | 1 | PIN锁。 |  
| SIM_PUK | 2 |  PUK锁。 |  
| SIM_PN_PIN | 3 |  网络PIN锁。 |  
| SIM_PN_PUK | 4 | 网络PUK锁。 |  
| SIM_PU_PIN | 5 | 子网PIN锁。  |  
| SIM_PU_PUK | 6 | 子网PUK锁。 |  
| SIM_PP_PIN | 7 | 服务提供商PIN锁。 |  
| SIM_PP_PUK | 8 | 服务提供商PUK锁。 |  
| SIM_PC_PIN | 9 | 组织PIN锁。 |  
| SIM_PC_PUK | 10 | 组织PUK锁。 |  
| SIM_SIM_PIN | 11 | SIM PIN锁。   |  
| SIM_SIM_PUK | 12 | SIM PUK锁。  |  
