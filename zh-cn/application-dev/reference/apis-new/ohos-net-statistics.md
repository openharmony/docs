# @ohos.net.statistics    
流量管理模块，支持基于网卡/UID 的实时流量统计和历史流量统计查询能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import statistics from '@ohos.net.statistics'    
```  
    
## getIfaceRxBytes    
获取指定网卡实时下行流量  
 **调用形式：**     
    
- getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void    
起始版本： 10    
- getIfaceRxBytes(nic: string): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| nic | string | true | 指定查询的网卡名。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功获取网卡实时下行流量时，error 为 undefined，stats 为获取到的网卡实时下行流量(单位:字节)；否则为错误对象 |  
| Promise<number> | 以 Promise 形式返回获取结果。返回网卡实时下行流量(单位:字节)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103005 | Failed to read map. |  
| 2103011 | Failed to create map. |  
| 2103012 | Get iface name failed. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import { BusinessError } from '@ohos.base';  
import statistics from '@ohos.net.statistics';  
  
statistics.getIfaceRxBytes("wlan0", (error: BusinessError, stats: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(stats));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics';  
statistics.getIfaceRxBytes("wlan0").then((stats: number) => {  console.log(JSON.stringify(stats));});    
```    
  
    
## getIfaceTxBytes    
获取指定网卡实时上行流量  
 **调用形式：**     
    
- getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void    
起始版本： 10    
- getIfaceTxBytes(nic: string): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| nic | string | true | 指定查询的网卡名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功获取网卡实时上行流量时，error 为 undefined，stats 为获取到的网卡实时上行流量(单位:字节)；否则为错误对象 |  
| Promise<number> | 以 Promise 形式返回获取结果。返回网卡实时上行流量(单位:字节)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103005 | Failed to read map. |  
| 2103011 | Failed to create map. |  
| 2103012 | Get iface name failed. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import { BusinessError } from '@ohos.base';  
import statistics from '@ohos.net.statistics';  
  
statistics.getIfaceTxBytes("wlan0", (error: BusinessError, stats: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(stats));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics';  
statistics.getIfaceTxBytes("wlan0").then((stats: number) => {  console.log(JSON.stringify(stats));});    
```    
  
    
## getCellularRxBytes    
获取蜂窝实时下行流量  
 **调用形式：**     
    
- getCellularRxBytes(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getCellularRxBytes(): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功获取蜂窝实时下行流量时，error 为 undefined，stats 为获取到的蜂窝实时下行流量(单位:字节)；否则为错误对象 |  
| Promise<number> | 以 Promise 形式返回获取结果。返回蜂窝实时下行流量(单位:字节)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103005 | Failed to read map. |  
| 2103011 | Failed to create map. |  
| 2103012 | Get iface name failed. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import { BusinessError } from '@ohos.base';  
import statistics from '@ohos.net.statistics';  
  
statistics.getCellularRxBytes((error: BusinessError, stats: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(stats));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics';  
statistics.getCellularRxBytes().then((stats: number) => {  console.log(JSON.stringify(stats));});    
```    
  
    
## getCellularTxBytes    
获取蜂窝实时上行流量  
 **调用形式：**     
    
- getCellularTxBytes(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getCellularTxBytes(): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 调函数。当成功获取蜂窝实时上行流量时，error 为 undefined，stats 为获取到的蜂窝实时上行流量(单位:字节)；否则为错误对象 |  
| Promise<number> | 以 Promise 形式返回获取结果。返回蜂窝实时上行流量(单位:字节)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103005 | Failed to read map. |  
| 2103011 | Failed to create map. |  
| 2103012 | Get iface name failed. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import { BusinessError } from '@ohos.base';  
import statistics from '@ohos.net.statistics';  
  
statistics.getCellularTxBytes((error: BusinessError, stats: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(stats));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics';  
statistics.getCellularTxBytes().then((stats: number) => {  console.log(JSON.stringify(stats));});    
```    
  
    
## getAllRxBytes    
获取所有网卡实时下行流量  
 **调用形式：**     
    
- getAllRxBytes(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getAllRxBytes(): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功获取所有网卡实时下行流量，error 为 undefined，stats 为获取到的所有网卡实时下行流量(单位:字节)；否则为错误对象 |  
| Promise<number> | 以 Promise 形式返回获取结果。返回所有网卡实时下行流量(单位:字节)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103005 | Failed to read map. |  
| 2103011 | Failed to create map. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import statistics from '@ohos.net.statistics';  
import { BusinessError } from '@ohos.base';  
  
statistics.getAllRxBytes((error: BusinessError, stats: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(stats));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics';  
statistics.getCellularRxBytes().then((stats: number) => {  console.log(JSON.stringify(stats));});    
```    
  
    
## getAllTxBytes    
获取所有网卡实时上行流量  
 **调用形式：**     
    
- getAllTxBytes(callback: AsyncCallback\<number>): void    
起始版本： 10    
- getAllTxBytes(): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功获取所有网卡实时上行流量，error 为 undefined，stats 为获取到的所有网卡实时上行流量(单位:字节)；否则为错误对象 |  
| Promise<number> | 以 Promise 形式返回获取结果。返回所有网卡实时上行流量(单位:字节)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103005 | Failed to read map. |  
| 2103011 | Failed to create map. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import { BusinessError } from '@ohos.base';  
import statistics from '@ohos.net.statistics';  
  
statistics.getAllTxBytes((error: BusinessError, stats: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(stats));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics';  
statistics.getAllTxBytes().then((stats: number) => {  console.log(JSON.stringify(stats));});    
```    
  
    
## getUidRxBytes    
获取指定应用实时下行流量  
 **调用形式：**     
    
- getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void    
起始版本： 10    
- getUidRxBytes(uid: number): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | 指定查询的应用 uid。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功获取应用实时下行流量时，error 为 undefined，stats 为获取到的应用实时下行流量(单位:字节)；否则为错误对象 |  
| Promise<number> | 以  Promise 形式返回获取结果。返回指定应用实时下行流量(单位:字节)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103005 | Failed to read map. |  
| 2103011 | Failed to create map. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import { BusinessError } from '@ohos.base';  
import statistics from '@ohos.net.statistics';  
  
statistics.getUidRxBytes(20010038, (error: BusinessError, stats: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(stats));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics';  
statistics.getUidRxBytes(20010038).then((stats: number) => {  console.log(JSON.stringify(stats));});    
```    
  
    
## getUidTxBytes    
获取指定应用实时上行流量  
 **调用形式：**     
    
- getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void    
起始版本： 10    
- getUidTxBytes(uid: number): Promise\<number>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | 指定查询的应用 uid。      |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功获取应用实时上行流量时，error 为 undefined，stats 为获取到的应用实时上行流量(单位:字节)；否则为错误对象 |  
| Promise<number> | 以 Promise 形式返回获取结果。返回指定应用实时上行流量(单位:字节)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Parameter error. |  
| 2100002 | Operation failed. Cannot connect to service. |  
| 2100003 | System internal error. |  
| 2103005 | Failed to read map. |  
| 2103011 | Failed to create map. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import { BusinessError } from '@ohos.base';  
import statistics from '@ohos.net.statistics';  
  
statistics.getUidTxBytes(20010038, (error: BusinessError, stats: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(stats));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import statistics from '@ohos.net.statistics';  
statistics.getUidTxBytes(20010038).then((stats: number) => {  console.log(JSON.stringify(stats));});    
```    
  
