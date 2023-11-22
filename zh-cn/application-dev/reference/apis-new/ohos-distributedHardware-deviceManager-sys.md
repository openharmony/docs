# @ohos.distributedHardware.deviceManager    
本模块能力已更新至新模块。建议使用新模块的接口进行开发，参见[@ohos.distributedDeviceManager](js-apis-distributedDeviceManager.md)。  
本模块提供分布式设备管理能力。  
系统应用可调用接口实现如下功能：。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import deviceManager from '@ohos.distributedHardware.deviceManager'    
```  
    
## DeviceInfo    
设备信息。> 从API version 11 开始废弃。建议使用[DeviceBasicInfo](js-apis-distributedDeviceManager.md#devicebasicinfo)替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
### 属性    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId | string | false | true | 设备的唯一标识。 |  
| deviceName | string | false | true | 设备名称。 |  
| deviceType | DeviceType | false | true | 设备类型。 |  
| networkId<sup>(8+)</sup> | string | false | true | 设备网络标识。 |  
| range<sup>(9+)</sup> | number | false | true | 发现设备的距离。 |  
| authForm<sup>(10+)</sup> | AuthForm | false | true | 设备认证类型 |  
    
## AuthForm<sup>(10+)</sup>    
表示设备认证类型的枚举类。    
    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INVALID_TYPE | -1 | 设备没有认证 |  
| PEER_TO_PEER | 0 | 无账号设备点对点认证 |  
| IDENTICAL_ACCOUNT | 1 | 设备同账号认证 |  
| ACROSS_ACCOUNT | 2 | 设备跨账号认证 |  
    
## DeviceType    
表示设备类型的枚举类。    
    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN_TYPE | 0 | 未知设备 |  
| SPEAKER | 0x0A | 智能音箱 |  
| PHONE | 0x0E | 手机 |  
| TABLET | 0x11 | 平板 |  
| WEARABLE | 0x6D | 智能穿戴 |  
| CAR | 0x83 | 车 |  
| TV | 0x9C | 智慧屏 |  
    
## DeviceStateChangeAction    
表示设备状态变化的枚举。    
    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ONLINE | 0 | 设备物理上线状态。 |  
| READY | 1 | 设备可用状态，表示设备间信息已在分布式数据中同步完成, 可以运行分布式业务。 |  
| OFFLINE | 2 | 设备物理下线状态。 |  
| CHANGE | 3 | 设备信息更改。 |  
    
## SubscribeInfo    
发现信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
### 属性    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| subscribeId | number | false | true | 发现标识，用于标识不同的发现周期。 |  
| mode | DiscoverMode | false | true | 发现模式。 |  
| medium | ExchangeMedium | false | true | 发现类型。 |  
| freq | ExchangeFreq | false | true | 发现频率。 |  
| isSameAccount | boolean | false | true | 是否同帐号。 |  
| isWakeRemote | boolean | false | true | 是否唤醒设备。 |  
| capability | SubscribeCap | false | true | 发现能力。 |  
    
## PublishInfo<sup>(9+)</sup>    
发布设备参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
### 属性    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| publishId<sup>(9+)</sup> | number | false | true | 发布设备标识，用于标识不同的发布周期。 |  
| mode<sup>(9+)</sup> | DiscoverMode | false | true | 发现模式。 |  
| freq<sup>(9+)</sup> | ExchangeFreq | false | true | 发现频率。 |  
| ranging<sup>(9+)</sup> | boolean | false | true | 发布的设备是否支持测距能力。 |  
    
## DiscoverMode    
表示发现模式的枚举。    
    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DISCOVER_MODE_PASSIVE | 0x55 | 被动模式。 |  
| DISCOVER_MODE_ACTIVE | 0xAA | 主动模式。 |  
    
## ExchangeMedium    
表示发现类型的枚举。    
    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| AUTO | 0 | 自动发现类型。 |  
| BLE | 1 | 蓝牙发现类型。 |  
| COAP | 2 | WiFi发现类型。 |  
| USB | 3 | USB发现类型。 |  
    
## ExchangeFreq    
表示发现频率的枚举。    
    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LOW | 0 | 低频率。 |  
| MID | 1 | 中频率。 |  
| HIGH | 2 | 高频率。 |  
| SUPER_HIGH | 3 | 超高频率。 |  
    
## SubscribeCap    
表示发现能力的枚举。    
    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUBSCRIBE_CAPABILITY_DDMP | 0 | DDMP能力，后续会被废弃。 |  
| SUBSCRIBE_CAPABILITY_OSD | 1 | OSD能力。 |  
    
## AuthParam    
认证参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
### 属性    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| authType | number | false | true | 认证类型。 |  
| extraInfo | { [key: string]: any } | false | true | 认证参数可扩展字段。可选，默认为undefined。 |  
    
## AuthInfo    
认证信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
### 属性    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| authType | number | false | true | 认证类型。 |  
| token | number | false | true | 认证Token。 |  
| extraInfo | { [key: string]: any } | false | true | 认证信息可扩展字段。可选，默认为undefined。 |  
    
## createDeviceManager  
 **调用形式：**     
    
- createDeviceManager(bundleName: string, callback: AsyncCallback\<DeviceManager>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
## DeviceManager    
设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
### release    
设备管理实例不再使用后，通过该方法释放DeviceManager实例。  
 **调用形式：**     
- release(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  dmInstance.release();  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("release errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getTrustedDeviceListSync    
同步获取所有可信设备列表。  
 **调用形式：**     
- getTrustedDeviceListSync(): Array\<DeviceInfo>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<DeviceInfo> | 返回可信设备列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
import { BusinessError } from '@ohos.base'  
  
try {  
  let deviceInfoList: Array<deviceManager.DeviceInfo> = dmInstance.getTrustedDeviceListSync();  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getTrustedDeviceListSync errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getTrustedDeviceListSync<sup>(10+)</sup>    
打开软总线系统端的心跳模式，让周围处于下线状态的可信设备快速上线，同时刷新已上线的可信设备列表。  
 **调用形式：**     
- getTrustedDeviceListSync(isRefresh: boolean): Array\<DeviceInfo>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isRefresh | boolean | true | 是否打开心跳模式，刷新可信列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<DeviceInfo> | 返回可信设备列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 201 |  |  
| 401 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
import { BusinessError } from '@ohos.base'  
  
try {  
  let deviceInfoList: Array<deviceManager.DeviceInfo> = dmInstance.getTrustedDeviceListSync(true);  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getTrustedDeviceListSync errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getTrustedDeviceList<sup>(8+)</sup>  
 **调用形式：**     
    
- getTrustedDeviceList(callback: AsyncCallback\<Array\<DeviceInfo>>): void    
起始版本： 8    
- getTrustedDeviceList(): Promise\<Array\<DeviceInfo>>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Array<DeviceInfo>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
    
### getLocalDeviceInfoSync<sup>(8+)</sup>    
同步获取本地设备信息。  
 **调用形式：**     
- getLocalDeviceInfoSync(): DeviceInfo  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DeviceInfo | 返回本地设备列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
import { BusinessError } from '@ohos.base'  
  
try {  
  let deviceInfo: deviceManager.DeviceInfo = dmInstance.getLocalDeviceInfoSync();  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getLocalDeviceInfoSync errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getLocalDeviceInfo<sup>(8+)</sup>  
 **调用形式：**     
    
- getLocalDeviceInfo(callback: AsyncCallback\<DeviceInfo>): void    
起始版本： 8    
- getLocalDeviceInfo(): Promise\<DeviceInfo>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<DeviceInfo> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  import { BusinessError } from '@ohos.base'  
  
  try {  
    let deviceInfo: deviceManager.DeviceInfo = dmInstance.getLocalDeviceInfoSync();  
  } catch (err) {  
    let e: BusinessError = err as BusinessError;  
    console.error("getLocalDeviceInfoSync errCode:" + e.code + ",errMessage:" + e.message);  
  }  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  import { BusinessError } from '@ohos.base'  
  
  dmInstance.getLocalDeviceInfo().then((data: deviceManager.DeviceInfo) => {  
    console.log('get local device info: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.error("getLocalDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);  
  });  
    
```    
  
    
### getDeviceInfo<sup>(10+)</sup>  
 **调用形式：**     
    
- getDeviceInfo(networkId: string, callback: AsyncCallback\<DeviceInfo>): void    
起始版本： 10    
- getDeviceInfo(networkId: string): Promise\<DeviceInfo>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| networkId | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<DeviceInfo> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  import { BusinessError } from '@ohos.base'  
  
  try {  
    // 设备网络标识，可以从可信设备列表中获取  
    let networkId = "xxxxxxx"  
    dmInstance.getDeviceInfo(networkId, (err: BusinessError, data: deviceManager.DeviceInfo) => {  
    if (err) {  
      console.error("getDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);  
      return;  
    }  
      console.log('get device info: ' + JSON.stringify(data));  
    });  
  } catch (err) {  
    let e: BusinessError = err as BusinessError;  
    console.error("getDeviceInfo errCode:" + e.code + ",errMessage:" + e.message);  
  }  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
  import { BusinessError } from '@ohos.base'  
  
  // 设备网络标识，可以从可信设备列表中获取  
  let networkId = "xxxxxxx"  
  dmInstance.getDeviceInfo(networkId).then((data: deviceManager.DeviceInfo) => {  
    console.log('get device info: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.error("getDeviceInfo errCode:" + err.code + ",errMessage:" + err.message);  
  });  
    
```    
  
    
### startDeviceDiscovery<sup>(8+)</sup>    
发现周边设备。发现状态持续两分钟，超过两分钟，会停止发现，最大发现数量99个。  
 **调用形式：**     
- startDeviceDiscovery(subscribeInfo: SubscribeInfo): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscribeInfo | SubscribeInfo | true | 发现信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 201 |  |  
| 11600104 | Discovery invalid. |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```null    
import { BusinessError } from '@ohos.base'  
  
interface SubscribeInfo {  
  subscribeId: number,  
  mode: number, // 主动模式  
  medium: number,  // 自动发现类型，同时支持多种发现类型  
  freq: number,    // 高频率  
  isSameAccount: boolean,  
  isWakeRemote: boolean,  
  capability: number  
};  
  
// 生成发现标识，随机数确保每次调用发现接口的标识不一致  
let subscribeId = Math.floor(Math.random() * 10000 + 1000);  
let subscribeInfo: SubscribeInfo = {  
  subscribeId: subscribeId,  
  mode: 0xAA, // 主动模式  
  medium: 0,  // 自动发现类型，同时支持多种发现类型  
  freq: 2,    // 高频率  
  isSameAccount: false,  
  isWakeRemote: false,  
  capability: 1  
};  
try {  
  dmInstance.startDeviceDiscovery(subscribeInfo); // 当有设备发现时，通过deviceFound回调通知给应用程序  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("startDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### startDeviceDiscovery<sup>(9+)</sup>    
发现周边设备。发现状态持续两分钟，超过两分钟，会停止发现，最大发现数量99个。  
 **调用形式：**     
- startDeviceDiscovery(subscribeInfo: SubscribeInfo, filterOptions?: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscribeInfo | SubscribeInfo | true | 发现信息。 |  
| filterOptions | string | false | 发现设备过滤信息。可选，默认为undefined，发现未上线设备。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 201 |  |  
| 11600104 | Discovery invalid. |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
interface Filters {  
  type: string,  
  value: number  
}  
  
interface FilterOptions {  
  filter_op: string, // 可选, 默认"OR"  
  filters: Filters[]  
  }  
  
interface SubscribeInfo {  
  subscribeId: number,  
  mode: number, // 主动模式  
  medium: number,  // 自动发现类型，同时支持多种发现类型  
  freq: number,    // 高频率  
  isSameAccount: boolean,  
  isWakeRemote: boolean,  
  capability: number  
}  
  
// 生成发现标识，随机数确保每次调用发现接口的标识不一致  
let subscribeId = Math.floor(Math.random() * 10000 + 1000);  
let subscribeInfo: SubscribeInfo = {  
  subscribeId: subscribeId,  
  mode: 0xAA, // 主动模式  
  medium: 0,  // 自动发现类型，同时支持多种发现类型  
  freq: 2,    // 高频率  
  isSameAccount: false,  
  isWakeRemote: false,  
  capability: 1  
};  
  
let filters: Filters[] = [  
  {  
      type: "range",  
      value: 50 // 需过滤发现设备的距离，单位(cm)  
  }  
]  
  
let filterOptions: FilterOptions = {  
  filter_op: "OR", // 可选, 默认"OR"  
  filters: filters  
};  
try {  
  dmInstance.startDeviceDiscovery(subscribeInfo, JSON.stringify(filterOptions)); // 当有设备发现时，通过deviceFound回调通知给应用程序  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("startDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### stopDeviceDiscovery    
停止发现周边设备。  
 **调用形式：**     
- stopDeviceDiscovery(subscribeId: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| subscribeId | number | true | 发现标识。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  // stopDeviceDiscovery和startDeviceDiscovery需配对使用，入参需要和startDeviceDiscovery接口传入的subscribeId值相等  
  let subscribeId = 12345;  
  dmInstance.stopDeviceDiscovery(subscribeId);  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("stopDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### publishDeviceDiscovery<sup>(9+)</sup>    
发布设备发现。发布状态持续两分钟，超过两分钟会停止发布。  
 **调用形式：**     
- publishDeviceDiscovery(publishInfo: PublishInfo): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| publishInfo | PublishInfo | true | 发布设备发现信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 201 |  |  
| 11600105 | Failed to execute the function. |  
| 11600101 | Publish invalid. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
interface PublishInfo {  
  publishId: number,  
  mode: number, // 主动模式  
  freq: number,    // 高频率  
  ranging: boolean  // 支持发现时测距  
};  
  
// 生成发布标识，随机数确保每次调用发布接口的标识不一致  
let publishId = Math.floor(Math.random() * 10000 + 1000);  
let publishInfo: PublishInfo = {  
  publishId: publishId,  
  mode: 0xAA, // 主动模式  
  freq: 2,    // 高频率  
  ranging: true  // 支持发现时测距  
};  
  
try {  
  dmInstance.publishDeviceDiscovery(publishInfo); // 当有发布结果时，通过回调通知给应用程序  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("publishDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### unPublishDeviceDiscovery<sup>(9+)</sup>    
停止发布设备发现。  
 **调用形式：**     
- unPublishDeviceDiscovery(publishId: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| publishId | number | true | 发布标识。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  // unPublishDeviceDiscovery和publishDeviceDiscovery配对使用，入参需要和publishDeviceDiscovery接口传入的publishId值相等  
  let publishId = 12345;  
  dmInstance.unPublishDeviceDiscovery(publishId);  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("unPublishDeviceDiscovery errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### authenticateDevice  
 **调用形式：**     
    
- authenticateDevice(       deviceInfo: DeviceInfo,       authParam: AuthParam,       callback: AsyncCallback\<{ deviceId: string, pinToken?: number }>     ): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceInfo | DeviceInfo | true |  |  
| authParam | AuthParam | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
  class Data {  
    deviceId: string = ""  
    pinToken?: number = 0  
  }  
  
  interface DeviceInfo {  
    deviceId: string,  
    deviceName: string  
    deviceType: number,  
    networkId: string,  
    range: number  
  };  
  
  interface ExtraInfo {  
    targetPkgName: string,  
    appName: string,  
    appDescription: string,  
    business: string  
  }  
  
  interface AuthParam {  
    authType: number,// 认证类型： 1 - 无帐号PIN码认证  
    extraInfo: ExtraInfo  
  }  
  
  // 认证的设备信息，可以从发现的结果中获取  
  let deviceInfo: deviceManager.DeviceInfo = {  
    deviceId: "XXXXXXXX",  
    deviceName: "",  
    deviceType: 0x0E,  
    networkId: "xxxxxxx",  
    range: 0,  
    authForm: 0  
  };  
  let extraInfo: ExtraInfo = {  
    targetPkgName: 'ohos.samples.xxx',  
    appName: 'xxx',  
    appDescription: 'xxx',  
    business: '0'  
  }  
  let authParam: AuthParam = {  
    authType: 1,// 认证类型： 1 - 无帐号PIN码认证  
    extraInfo: extraInfo  
  }  
  
  try {  
    dmInstance.authenticateDevice(deviceInfo, authParam, (err: BusinessError, data: Data) => {  
      if (err) {  
          console.error("authenticateDevice errCode:" + err.code + ",errMessage:" + err.message);  
          return;  
      }  
      console.info("authenticateDevice result:" + JSON.stringify(data));  
      let token = data.pinToken;  
    });  
  } catch (err) {  
    let e: BusinessError = err as BusinessError;  
    console.error("authenticateDevice errCode:" + e.code + ",errMessage:" + e.message);  
  }  
    
```    
  
    
### unAuthenticateDevice<sup>(8+)</sup>    
解除认证设备。  
 **调用形式：**     
- unAuthenticateDevice(deviceInfo: DeviceInfo): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceInfo | DeviceInfo | true | 设备信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
interface DeviceInfo {  
  deviceId: string,  
  deviceName: string,  
  deviceType: number,  
  networkId: string,  
  range: number  
}  
  
try {  
  let deviceInfo: deviceManager.DeviceInfo = {  
    deviceId: "XXXXXXXX",  
    deviceName: "",  
    deviceType: 0x0E,  
    networkId: "xxxxxxx",  
    range: 0,  
    authForm: 0  
  };  
  dmInstance.unAuthenticateDevice(deviceInfo);  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("unAuthenticateDevice errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### verifyAuthInfo  
 **调用形式：**     
    
- verifyAuthInfo(authInfo: AuthInfo, callback: AsyncCallback\<{ deviceId: string, level: number }>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| authInfo | AuthInfo | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
  interface ExtraInfo {  
    authType: number,  
    token: number  
  }  
  
  interface AuthInfo {  
    authType: number,  
    token: number,  
    extraInfo: ExtraInfo  
  }  
  
  class Data {  
    deviceId: string = ""  
    level: number = 0  
  }  
  
  let extraInfo: ExtraInfo = {  
    authType: 0,  
    token: 0  
  }  
  
  let authInfo: AuthInfo = {  
    authType: 1,  
    token: 123456,  
    extraInfo: extraInfo  
  }  
  try {  
    dmInstance.verifyAuthInfo(authInfo, (err: BusinessError, data: Data) => {  
      if (err) {  
          console.error("verifyAuthInfo errCode:" + err.code + ",errMessage:" + err.message);  
          return;  
    }  
    console.info("verifyAuthInfo result:" + JSON.stringify(data));  
    });  
  } catch (err) {  
    let e: BusinessError = err as BusinessError;  
    console.error("verifyAuthInfo errCode:" + e.code + ",errMessage:" + e.message);  
  }  
    
```    
  
    
### setUserOperation<sup>(9+)</sup>    
设置用户ui操作行为。  
 **调用形式：**     
- setUserOperation(operateAction: number, params: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| operateAction | number | true | 用户操作动作。 |  
| params | string | true | 表示用户的输入参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
| 201 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  /*  
    operateAction = 0 - 允许授权  
    operateAction = 1 - 取消授权  
    operateAction = 2 - 授权框用户操作超时  
    operateAction = 3 - 取消pin码框展示  
    operateAction = 4 - 取消pin码输入框展示  
    operateAction = 5 - pin码输入框确定操作  
  */  
  let operation = 0;  
  dmInstance.setUserOperation(operation, "extra")  
  } catch (err) {  
    let e: BusinessError = err as BusinessError;  
    console.error("setUserOperation errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### requestCredentialRegisterInfo<sup>(10+)</sup>  
 **调用形式：**     
    
- requestCredentialRegisterInfo(requestInfo: string, callback: AsyncCallback\<{ registerInfo: string }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| requestInfo | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
interface CredentialInfo {  
  version: string,  
  userId: string  
}  
  
class Data {  
  registerInfo: string = ""  
}  
  
let credentialInfo: CredentialInfo = {  
  version: "1.2.3",  
  userId: "123"  
}  
try {  
  var jsonCredentialInfo = JSON.stringify(credentialInfo)  
  dmInstance.requestCredentialRegisterInfo(jsonCredentialInfo, (err: BusinessError, data: Data) => {  
    if (data) {  
        console.info("requestCredentialRegisterInfo result:" + JSON.stringify(data));  
    } else {  
        console.info("requestCredentialRegisterInfo result: data is null");  
    }  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("requestCredentialRegisterInfo err:" + e.code + "," + e.message);  
}  
    
```    
  
    
### importCredential<sup>(10+)</sup>  
 **调用形式：**     
    
- importCredential(credentialInfo: string, callback: AsyncCallback\<{ resultInfo: string }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| credentialInfo | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  resultInfo: string = ""  
}  
  
interface CredentialData {  
  credentialType: number,  
  credentialId: string,  
  serverPk: string,  
  pkInfoSignature : string,  
  pkInfo: string,  
  authCode: string,  
  peerDeviceId: string  
}  
  
interface CredentialInfo {  
  processType: number,  
  authType: number,  
  userId: string,  
  deviceId: string,  
  version: string,  
  devicePk : string,  
  credentialData : CredentialData  
}  
  
let credentialData: CredentialData = {  
  credentialType: 2,  
  credentialId: "102",  
  serverPk: "3059301306072A8648CE3D020106082A8648CE3D03",  
  pkInfoSignature : "30440220490BCB4F822004C9A76AB8D97F80041FC0E",  
  pkInfo: "",  
  authCode: "",  
  peerDeviceId: ""  
}  
  
  
let credentialInfo: CredentialInfo = {  
  processType: 1,  
  authType: 1,  
  userId: "123",  
  deviceId: "aaa",  
  version: "1.2.3",  
  devicePk : "0000",  
  credentialData : credentialData  
}  
  
try {  
  var jsonCredentialInfo = JSON.stringify(credentialInfo)  
  dmInstance.importCredential(jsonCredentialInfo, (err: BusinessError, data: Data) => {  
    if (data) {  
        console.info("importCredential result:" + JSON.stringify(data));  
    } else {  
        console.info("importCredential result: data is null");  
    }  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("importCredential err:" + e.code + "," + e.message);  
}  
    
```    
  
    
### deleteCredential<sup>(10+)</sup>  
 **调用形式：**     
    
- deleteCredential(queryInfo: string, callback: AsyncCallback\<{ resultInfo: string }>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| queryInfo | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  resultInfo: string = ""  
}  
  
interface QueryInfo {  
  processType: number,  
  authType: number,  
  userId: string  
}  
  
let queryInfo: QueryInfo = {  
  processType: 1,  
  authType: 1,  
  userId: "123"  
}  
  
try {  
  var jsonQueryInfo = JSON.stringify(queryInfo)  
  dmInstance.deleteCredential(jsonQueryInfo, (err: BusinessError, data: Data) => {  
    if (data) {  
        console.info("deleteCredential result:" + JSON.stringify(data));  
    } else {  
        console.info("deleteCredential result: data is null");  
    }  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("deleteCredential err:" + e.code + "," + e.message);  
}  
    
```    
  
    
### on('uiStateChange')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'uiStateChange', callback: Callback\<{ param: string }>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  param: string = ""  
}  
  
interface TmpStr {  
  verifyFailed: boolean  
}  
  
try {  
  dmInstance.on('uiStateChange', (data: Data) => {  
  console.log("uiStateChange executed, dialog closed" + JSON.stringify(data))  
  let tmpStr: TmpStr = JSON.parse(data.param)  
  let isShow = tmpStr.verifyFailed  
  console.log("uiStateChange executed, dialog closed" + isShow)  
});  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("uiStateChange errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('uiStateChange')<sup>(9+)</sup>  
 **调用形式：**     
    
- off(type: 'uiStateChange', callback?: Callback\<{ param: string }>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  dmInstance.off('uiStateChange');  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("uiStateChange errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('deviceStateChange')  
 **调用形式：**     
    
- on(type: 'deviceStateChange', callback: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
import { BusinessError } from '@ohos.base'  
  
class Data {  
  action: deviceManager.DeviceStateChangeAction = 0  
  device: deviceManager.DeviceInfo = {  
    deviceId: "",  
    deviceName: "",  
    deviceType: 0,  
    networkId: "",  
    range: 0,  
    authForm:0,  
  }  
}  
  
try {  
  dmInstance.on('deviceStateChange', (data: Data) => {  
    console.info("deviceStateChange on:" + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("deviceStateChange errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('deviceStateChange')  
 **调用形式：**     
    
- off(type: 'deviceStateChange', callback?: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
import { BusinessError } from '@ohos.base'  
  
class Data {  
  action: deviceManager.DeviceStateChangeAction = 0  
  device: deviceManager.DeviceInfo = {  
    deviceId: "",  
    deviceName: "",  
    deviceType: 0,  
    networkId: "",  
    range: 0,  
    authForm:0,  
  }  
}  
  
try {  
  dmInstance.off('deviceStateChange', (data: Data) => {  
    console.info('deviceStateChange' + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("deviceStateChange errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('deviceFound')  
 **调用形式：**     
    
- on(type: 'deviceFound', callback: Callback\<{ subscribeId: number, device: DeviceInfo }>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
import { BusinessError } from '@ohos.base'  
  
class Data {  
  subscribeId: number = 0  
  device: deviceManager.DeviceInfo = {  
    deviceId: "",  
    deviceName: "",  
    deviceType: 0,  
    networkId: "",  
    range: 0,  
    authForm:0,  
  }  
}  
  
try {  
  dmInstance.on('deviceFound', (data: Data) => {  
    console.info("deviceFound:" + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("deviceFound errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('deviceFound')  
 **调用形式：**     
    
- off(type: 'deviceFound', callback?: Callback\<{ subscribeId: number, device: DeviceInfo }>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import deviceManager from '@ohos.distributedHardware.deviceManager';  
import { BusinessError } from '@ohos.base'  
  
class Data {  
  subscribeId: number = 0  
  device: deviceManager.DeviceInfo = {  
    deviceId: "",  
    deviceName: "",  
    deviceType: 0,  
    networkId: "",  
    range: 0,  
    authForm:0,  
  }  
}  
  
try {  
  dmInstance.off('deviceFound', (data: Data) => {  
    console.info('deviceFound' + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("deviceFound errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('discoverFail')  
 **调用形式：**     
    
- on(type: 'discoverFail', callback: Callback\<{ subscribeId: number, reason: number }>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
### off('discoverFail')  
 **调用形式：**     
    
- off(type: 'discoverFail', callback?: Callback\<{ subscribeId: number, reason: number }>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
### on('publishSuccess')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'publishSuccess', callback: Callback\<{ publishId: number }>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  subscribeId: number = 0  
  reason: number = 0  
}  
  
try {  
  dmInstance.on('discoverFail', (data: Data) => {  
      console.info("discoverFail on:" + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("discoverFail errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('publishSuccess')<sup>(9+)</sup>  
 **调用形式：**     
    
- off(type: 'publishSuccess', callback?: Callback\<{ publishId: number }>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  subscribeId: number = 0  
  reason: number = 0  
}  
  
try {  
  dmInstance.off('discoverFail', (data: Data) => {  
    console.info('discoverFail' + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("discoverFail errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('publishFail')<sup>(9+)</sup>  
 **调用形式：**     
    
- on(type: 'publishFail', callback: Callback\<{ publishId: number, reason: number }>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  publishId: number = 0  
}  
  
try {  
  dmInstance.on('publishSuccess', (data: Data) => {  
    console.info("publishSuccess:" + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("publishSuccess errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('publishFail')<sup>(9+)</sup>  
 **调用形式：**     
    
- off(type: 'publishFail', callback?: Callback\<{ publishId: number, reason: number }>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  publishId: number = 0  
}  
  
try {  
  dmInstance.off('publishSuccess', (data: Data) => {  
    console.info('publishSuccess' + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("publishSuccess errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('serviceDie')  
 **调用形式：**     
    
- on(type: 'serviceDie', callback: () => void): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  publishId: number = 0  
  reason: number = 0  
}  
  
try {  
  dmInstance.on('publishFail', (data: Data) => {  
    console.info("publishFail on:" + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("publishFail errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('serviceDie')  
 **调用形式：**     
    
- off(type: 'serviceDie', callback?: () => void): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.ACCESS_SERVICE_DM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  dmInstance.off("serviceDie", () => {  
    console.info("serviceDie off");  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("serviceDie errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
