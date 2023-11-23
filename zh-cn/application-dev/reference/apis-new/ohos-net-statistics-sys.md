# @ohos.net.statistics    
流量管理模块，支持基于网卡/UID 的实时流量统计和历史流量统计查询能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import statistics from '@ohos.net.statistics'    
```  
    
## on('netStatsChange')    
订阅流量改变事件通知。  
 **调用形式：**     
    
- on(type: 'netStatsChange', callback: Callback\<{ iface: string, uid?: number }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.GET_NETWORK_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅流量改变事件通知。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 当流量有改变时触发回调函数。<br>iface：网卡名称。<br>uid：应用 uid |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
示例callback：  
  
  
```js    
import statistics from '@ohos.net.statistics';  
  
class IFace {  
  iface: string = ""  
  uid?: number = 0  
}  
statistics.on('netStatsChange', (data: IFace) => {  
  console.log('on netStatsChange' + JSON.stringify(data));  
});  
    
```    
  
    
## off('netStatsChange')    
取消订阅流量改变事件通知。  
 **调用形式：**     
    
- off(type: 'netStatsChange', callback?: Callback\<{ iface: string, uid?: number }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.GET_NETWORK_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注销订阅事件，固定为'netStatsChange'。               |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 当流量有改变时触发回调函数。<br>iface：网卡名称。<br>uid：应用 uid |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
    
 **示例代码：**   
示例callback：  
  
  
```js    
import statistics from '@ohos.net.statistics';  
  
class IFace {  
  iface: string = ""  
  uid?: number = 0  
}  
let callback: (data: IFace) => void = (data: IFace) => {  
    console.log("on netStatsChange, iFace:" + data.iface + " uid: " + data.uid);  
}  
statistics.on('netStatsChange', callback);  
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。  
statistics.off('netStatsChange', callback);  
statistics.off('netStatsChange');  
    
```    
  
    
## getTrafficStatsByIface    
获取指定网卡历史流量信息  
 **调用形式：**     
    
- getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void    
起始版本： 10    
- getTrafficStatsByIface(ifaceInfo: IfaceInfo): Promise\<NetStatsInfo>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.GET_NETWORK_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ifaceInfo | IfaceInfo | true | 指定查询的网卡信息，参见[IfaceInfo](#ifaceinfo10)。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。成功时 statsInfo 返回包含网卡历史流量信息，error 为 undefined，否则为错误对象 |  
| Promise<NetStatsInfo> | 以 Promise 形式返回获取结果,返回网卡历史流量信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2100001 | Invalid parameter value. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103017 | Read data from database failed. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import { BusinessError } from '@ohos.base';  
import statistics from '@ohos.net.statistics';  
  
let iFaceInfo: statistics.IfaceInfo  
  
statistics.getTrafficStatsByIface(iFaceInfo, (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {  
  console.log(JSON.stringify(error));  
  console.log(  
    "getTrafficStatsByIface bytes of received = " +  
    JSON.stringify(statsInfo.rxBytes)  
  );  
  console.log(  
    "getTrafficStatsByIface bytes of sent = " +  
    JSON.stringify(statsInfo.txBytes)  
  );  
  console.log(  
    "getTrafficStatsByIface packets of received = " +  
    JSON.stringify(statsInfo.rxPackets)  
  );  
  console.log(  
    "getTrafficStatsByIface packets of sent = " +  
    JSON.stringify(statsInfo.txPackets)  
  );  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics';  
let iFaceInfo: statistics.IfaceInfostatistics.getTrafficStatsByIface(iFaceInfo).then((statsInfo: statistics.NetStatsInfo) => {  console.log(    "getTrafficStatsByIface bytes of received = " +    JSON.stringify(statsInfo.rxBytes)  );  console.log(    "getTrafficStatsByIface bytes of sent = " +    JSON.stringify(statsInfo.txBytes)  );  console.log(    "getTrafficStatsByIface packets of received = " +    JSON.stringify(statsInfo.rxPackets)  );  console.log(    "getTrafficStatsByIface packets of sent = " +    JSON.stringify(statsInfo.txPackets)  );});    
```    
  
    
## getTrafficStatsByUid    
获取指定应用历史流量信息  
 **调用形式：**     
    
- getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void    
起始版本： 10    
- getTrafficStatsByUid(uidInfo: UidInfo): Promise\<NetStatsInfo>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core  
 **需要权限：** ohos.permission.GET_NETWORK_STATS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uidInfo | UidInfo | true | 指定查询的应用信息，参见[UidInfo](#uidinfo10)。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。成功时 statsInfo 返回包含应用历史流量信息，error 为 undefined，否则为错误对象 |  
| Promise<NetStatsInfo> | 以 Promise 形式返回获取结果,返回应用历史流量信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Non-system applications use system APIs. |  
| 2100001 | Invalid parameter value |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103017 | Read data from database failed. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import { BusinessError } from '@ohos.base';  
import statistics from '@ohos.net.statistics';  
  
let uidInfo: statistics.UidInfo  
uidInfo.uid = 20010037  
  
statistics.getTrafficStatsByUid(  
  uidInfo,  
  (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {  
    console.log(JSON.stringify(error));  
    console.log(  
      "getTrafficStatsByUid bytes of received = " +  
      JSON.stringify(statsInfo.rxBytes)  
    );  
    console.log(  
      "getTrafficStatsByUid bytes of sent = " +  
      JSON.stringify(statsInfo.txBytes)  
    );  
    console.log(  
      "getTrafficStatsByUid packets of received = " +  
      JSON.stringify(statsInfo.rxPackets)  
    );  
    console.log(  
      "getTrafficStatsByUid packets of sent = " +  
      JSON.stringify(statsInfo.txPackets)  
    );  
  }  
);  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics'  
let uidInfo: statistics.UidInfouidInfo.uid = 20010037  
statistics.getTrafficStatsByUid(uidInfo).then((statsInfo: statistics.NetStatsInfo) => {  console.log("getTrafficStatsByUid bytes of received = " + JSON.stringify(statsInfo.rxBytes));  console.log("getTrafficStatsByUid bytes of sent = " + JSON.stringify(statsInfo.txBytes));  console.log("getTrafficStatsByUid packets of received = " + JSON.stringify(statsInfo.rxPackets));  console.log("getTrafficStatsByUid packets of sent = " + JSON.stringify(statsInfo.txPackets));})    
```    
  
    
## IfaceInfo    
查询网卡历史流量参数信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| iface | string | false | true | 查询的网卡名。  |  
| startTime | number | false | true | 查询的开始时间(时间戳;单位：秒)。  |  
| endTime | number | false | true | 查询的结束时间(时间戳;单位：秒)。 |  
    
## UidInfo    
查询应用历史流量参数信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ifaceInfo | IfaceInfo | false | true |  需查询的网卡和时间参数信息 |  
| uid | number | false | true | 需查询的应用 uid |  
    
## NetStatsInfo    
获取的历史流量信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| rxBytes | number | false | true | 流量下行数据(单位:字节) |  
| txBytes | number | false | true | 流量上行数据(单位:字节) |  
| rxPackets | number | false | true | 流量下行包个数 |  
| txPackets | number | false | true | 流量上行包个数   。 |  
