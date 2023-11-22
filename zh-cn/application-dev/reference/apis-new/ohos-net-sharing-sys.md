# @ohos.net.sharing    
网络共享管理分享设备已有网络给其他连接设备，支持 Wi-Fi 热点共享、蓝牙共享和 USB 共享，同时提供网络共享状态、共享流量查询功能。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import sharing from '@ohos.net.sharing'    
```  
    
## isSharingSupported    
判断是否支持网络共享  
 **调用形式：**     
    
- isSharingSupported(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isSharingSupported(): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回 true 代表支持网络共享。 |  
| Promise<boolean> | 以 Promise 形式返回是否支持共享结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
| 2202011 | Cannot get network sharing configuration. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing.isSharingSupported((error: BusinessError, data: boolean) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing  
  .isSharingSupported()  
  .then((data: boolean) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## isSharing    
获取当前网络共享状态  
 **调用形式：**     
    
- isSharing(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isSharing(): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回 true 代表网络共享中。 |  
| Promise<boolean> | 以 Promise 形式返回网络共享状态结果，返回 true 代表网络共享中。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
| 2202011 | Cannot get network sharing configuration. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing.isSharing((error: BusinessError, data: boolean) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing  
  .isSharing()  
  .then((data: boolean) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## startSharing    
开启指定类型共享  
 **调用形式：**     
    
- startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void    
起始版本： 9    
- startSharing(type: SharingIfaceType): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SharingIfaceType | true | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回开启网络共享结果。 |  
| Promise<void> | 以 Promise 形式返回开启共享执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
| 2202004 | Try to share an unavailable iface. |  
| 2202005 | WiFi sharing failed. |  
| 2202006 | Bluetooth sharing failed. |  
| 2202009 | Network share enable forwarding error. |  
| 2202011 | Cannot get network sharing configuration. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_WIFI = 0;  
sharing.startSharing(SHARING_WIFI, (error: BusinessError) => {  
  console.log(JSON.stringify(error));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```null    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_WIFI = 0;  
sharing  
  .startSharing(SHARING_WIFI)  
  .then(() => {  
    console.log('start wifi sharing successful');  
  })  
  .catch((error: BusinessError) => {  
    console.log('start wifi sharing failed');  
  });  
    
```    
  
    
## stopSharing    
关闭指定类型共享  
 **调用形式：**     
    
- stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void    
起始版本： 9    
- stopSharing(type: SharingIfaceType): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SharingIfaceType | true | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数,返回停止网络共享结果。 |  
| Promise<void> | 以 Promise 形式返回关闭共享执行结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
| 2202004 | Try to share an unavailable iface. |  
| 2202005 | WiFi sharing failed. |  
| 2202006 | Bluetooth sharing failed. |  
| 2202011 | Cannot get network sharing configuration. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_WIFI = 0;  
sharing.stopSharing(SHARING_WIFI, (error: BusinessError) => {  
  console.log(JSON.stringify(error));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_WIFI = 0;  
sharing  
  .stopSharing(SHARING_WIFI)  
  .then(() => {  
    console.log('stop wifi sharing successful');  
  })  
  .catch((error: BusinessError) => {  
    console.log('stop wifi sharing failed');  
  });  
    
```    
  
    
## getStatsRxBytes    
获取共享网络接收数据量  
 **调用形式：**     
    
- getStatsRxBytes(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getStatsRxBytes(): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，number 代表数据量，单位：KB。 |  
| Promise<number> | 以 Promise 形式返回共享网络接收数据量，单位：KB。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing.getStatsRxBytes((error: BusinessError, data: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing  
  .getStatsRxBytes()  
  .then((data: number) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });<b></b><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
## getStatsTxBytes    
获取共享网络发送数据量  
 **调用形式：**     
    
- getStatsTxBytes(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getStatsTxBytes(): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | System internal error. |  
| Promise<number> | Promise 形式返回共享网络发送数据量，单位：KB。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing.getStatsTxBytes((error: BusinessError, data: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing  
  .getStatsTxBytes()  
  .then((data: number) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getStatsTotalBytes    
获取共享网络总数据量  
 **调用形式：**     
    
- getStatsTotalBytes(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getStatsTotalBytes(): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，number 代表数据量，单位：KB。 |  
| Promise<number> | 以 Promise 形式返回共享网络总数据量，单位：KB。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing.getStatsTotalBytes((error: BusinessError, data: number) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
sharing  
  .getStatsTotalBytes()  
  .then((data: number) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getSharingIfaces    
获取指定状态的网卡名称列表  
 **调用形式：**     
    
- getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| state | SharingIfaceState | true | 网络共享状态。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回指定状态的网卡名称列表。 |  
| Promise<Array<string>> | 以 Promise 形式返回指定状态网卡名称列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_BLUETOOTH = 2;  
sharing.getSharingIfaces(SHARING_BLUETOOTH, (error: BusinessError, data: string[]) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_BLUETOOTH = 2;  
sharing  
  .getSharingIfaces(SHARING_BLUETOOTH)  
  .then((data: string[]) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getSharingState    
获取指定类型网络共享状态  
 **调用形式：**     
    
- getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void    
起始版本： 9    
- getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SharingIfaceType | true | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回指定类型网络共享状态。 |  
| Promise<SharingIfaceState> | 回调函数，返回指定类型网络共享状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_WIFI = 0;  
sharing.getSharingState(SHARING_WIFI, (error: BusinessError, data: sharing.SharingIfaceState) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_WIFI = 0;  
sharing  
  .getSharingState(SHARING_WIFI)  
  .then((data: sharing.SharingIfaceState) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## getSharableRegexes    
获取指定类型网卡名称正则表达式列表  
 **调用形式：**     
    
- getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | SharingIfaceType | true | 共享类型，0：Wi-Fi 1：USB 2：BLUETOOTH。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回指定类型网卡名称正则表达式列表。 |  
| Promise<Array<string>> | 以 Promise 形式返回正则表达式列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
| 2200001 | Invalid parameter value. |  
| 2200002 | Operation failed. Cannot connect to service. |  
| 2200003 | System internal error. |  
    
 **示例代码1：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_WIFI = 0;  
sharing.getSharableRegexes(SHARING_WIFI, (error: BusinessError, data: string[]) => {  
  console.log(JSON.stringify(error));  
  console.log(JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例Promise：  
  
```js    
import sharing from '@ohos.net.sharing';  
import { BusinessError } from '@ohos.base';  
  
let SHARING_WIFI = 0;  
sharing  
  .getSharableRegexes(SHARING_WIFI)  
  .then((data: string[]) => {  
    console.log(JSON.stringify(data));  
  })  
  .catch((error: BusinessError) => {  
    console.log(JSON.stringify(error));  
  });  
    
```    
  
    
## on('sharingStateChange')    
注册网络共享状态变化事件，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'sharingStateChange', callback: Callback\<boolean>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回网络共享状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
    
 **示例代码：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
sharing.on('sharingStateChange', (data: boolean) => {  console.log('on sharingStateChange: ' + JSON.stringify(data));});    
```    
  
    
## off('sharingStateChange')    
注销网络共享状态变化事件，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'sharingStateChange', callback?: Callback\<boolean>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回网络共享状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
    
 **示例代码：**   
示例callback：  
  
  
```js    
import sharing from '@ohos.net.sharing';  
sharing.off('sharingStateChange', (data: boolean) => {  console.log(JSON.stringify(data));});    
```    
  
    
## on('interfaceSharingStateChange')    
注册网卡网络共享状态变化事件，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数,指定网卡共享状态变化时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
    
 **示例代码：**   
示例callback：  
  
  
```null    
import sharing from '@ohos.net.sharing';  
sharing.on('interfaceSharingStateChange', (data: object) => {  console.log('on interfaceSharingStateChange:' + JSON.stringify(data));});    
```    
  
    
## off('interfaceSharingStateChange')    
注销网卡网络共享状态变化事件，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，注销指定网卡共享状态变化通知。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
    
 **示例代码：**   
示例callback：  
```js    
import sharing from '@ohos.net.sharing';  
sharing.off('interfaceSharingStateChange', (data: object) => {  console.log(JSON.stringify(data));});    
```    
  
    
## on('sharingUpstreamChange')    
注册上行网络变化事件，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，上行网络变化时调用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
    
 **示例代码：**   
示例callback：  
```js    
import sharing from '@ohos.net.sharing';  
sharing.on('sharingUpstreamChange', (data: object) => {  console.log('on sharingUpstreamChange:' + JSON.stringify(data));});    
```    
  
    
## off('sharingUpstreamChange')    
注销上行网络变化事件，使用 callback 方式作为异步方法。  
 **调用形式：**     
    
- off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing  
 **需要权限：** ohos.permission.CONNECTIVITY_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件名称。       |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，注销上行网络变化事件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 | Permission denied. |  
| 202 | Non-system applications use system APIs. |  
| 401 | Parameter error. |  
    
 **示例代码：**   
示例callback：  
```null    
import sharing from '@ohos.net.sharing';  
sharing.off('sharingUpstreamChange', (data: object) => {  console.log(JSON.stringify(data));});    
```    
  
    
## SharingIfaceState    
网络共享状态。    
    
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SHARING_NIC_SERVING | 1 | 正在网络共享。  |  
| SHARING_NIC_CAN_SERVER | 2 | 可提供网络共享。 |  
| SHARING_NIC_ERROR | 3 | 网络共享错误。 |  
    
## SharingIfaceType    
网络共享类型。    
    
 **系统能力:**  SystemCapability.Communication.NetManager.NetSharing    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SHARING_WIFI | 0 | 网络共享类型 Wi-Fi。 |  
| SHARING_USB | 1 | 网络共享类型 USB。 |  
| SHARING_BLUETOOTH | 2 | 网络共享类型蓝牙。 |  
