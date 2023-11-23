# @ohos.telephony.observer    
本模块提供订阅管理功能，可以订阅/取消订阅的事件包括：网络状态变化、信号状态变化、通话状态变化、蜂窝数据链路连接状态、蜂窝数据业务的上下行数据流状态、SIM状态变化。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import observer from '@ohos.telephony.observer'    
```  
    
## on('cellInfoChange')<sup>(8+)</sup>    
订阅小区信息变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'cellInfoChange', callback: Callback\<Array\<CellInformation>>): void    
起始版本： 8    
- on(type: 'cellInfoChange', options: { slotId: number }, callback: Callback\<Array\<CellInformation>>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.StateRegistry  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 小区信息变化事件，固定为'cellInfoChange'。 |  
| options | { slotId: number } | true | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |  
    
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
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```null    
import radio from '@ohos.telephony.radio';  
  
class SlotId {  
    slotId: number = 0  
}  
let id: SlotId = {slotId: 0}  
observer.on('cellInfoChange', id, (data: Array<radio.CellInformation>) => {  
    console.log("on cellInfoChange, data:" + JSON.stringify(data));  
});  
    
```    
  
    
## off('cellInfoChange')<sup>(8+)</sup>    
取消订阅小区信息变化事件，使用callback方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'cellInfoChange', callback?: Callback\<Array\<CellInformation>>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Telephony.StateRegistry    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 小区信息变化事件，固定为'cellInfoChange'。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 8300001 | Invalid parameter value. |  
| 8300002 | Operation failed. Cannot connect to service |  
| 8300003 | System internal error. |  
| 8300999 | Unknown error code. |  
    
 **示例代码：**   
```null    
import radio from '@ohos.telephony.radio';  
let callback: (data: Array<radio.CellInformation>) => void = (data: Array<radio.CellInformation>) => {    console.log("on cellInfoChange, data:" + JSON.stringify(data));}observer.on('cellInfoChange', callback);// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。observer.off('cellInfoChange', callback);observer.off('cellInfoChange');    
```    
  
