# @ohos.distributedDeviceManager    
本模块提供分布式设备管理能力。  
应用可调用接口实现如下功能：  
- 注册和解除注册设备上下线变化监听- 发现周边不可信设备- 认证和取消认证设备- 查询可信设备列表- 查询本地设备信息，包括设备名称，设备类型和设备标识等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedDeviceManager from '@ohos.distributedDeviceManager'    
```  
    
## DeviceBasicInfo    
分布式设备基本信息。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
### 属性    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId | string | false | true | 设备的唯一标识。 实际值为udid-hash与appid基于sha256方式进行加密后的值。 |  
| deviceName | string | false | true | 设备名称。 |  
| deviceType | string | false | true | 设备类型。 |  
| networkId | string | false | false | 设备网络标识。 |  
    
## DeviceStateChange    
表示设备状态。    
    
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNKNOWN | 0 | 设备物理上线，此时状态未知，在状态更改为可用之前，分布式业务无法使用。 |  
| AVAILABLE | 1 | 设备可用状态，表示设备间信息已在分布式数据中同步完成, 可以运行分布式业务。 |  
| UNAVAILABLE | 2 | 设备物理下线，此时状态未知。 |  
    
## createDeviceManager    
创建一个设备管理实例。设备管理实例是分布式设备管理方法的调用入口。用于获取可信设备和本地设备的相关信息。  
 **调用形式：**     
- createDeviceManager(bundleName: string): DeviceManager  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bundleName | string | true | 指示应用程序的Bundle名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DeviceManager | 返回设备管理器对象实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager'  
import { BusinessError } from '@ohos.base'  
  
try {  
  let dmInstance = deviceManager.createDeviceManager("ohos.samples.jshelloworld");  
} catch(err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("createDeviceManager errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
## releaseDeviceManager    
设备管理实例不再使用后，通过该方法释放DeviceManager实例。  
 **调用形式：**     
- releaseDeviceManager(deviceManager: DeviceManager): void  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceManager | DeviceManager | true | 设备管理器对象实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
import deviceManager from '@ohos.distributedDeviceManager'  
  
try {  
  let dmInstance = deviceManager.createDeviceManager("ohos.samples.jshelloworld");  
  deviceManager.releaseDeviceManager(dmInstance);  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("release device manager errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
## DeviceManager    
设备管理实例，用于获取可信设备和本地设备的相关信息。在调用DeviceManager的方法前，需要先通过createDeviceManager构建一个DeviceManager实例dmInstance。  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager    
### getAvailableDeviceListSync    
同步获取所有可信设备列表。  
 **调用形式：**     
- getAvailableDeviceListSync(): Array\<DeviceBasicInfo>  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<DeviceBasicInfo> | 返回可信设备列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager'  
import { BusinessError } from '@ohos.base'  
  
try {  
  let deviceInfoList: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getAvailableDeviceListSync errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getAvailableDeviceList    
获取所有可信设备列表  
 **调用形式：**     
    
- getAvailableDeviceList(callback: AsyncCallback\<Array\<DeviceBasicInfo>>): void    
起始版本： 10    
- getAvailableDeviceList(): Promise\<Array\<DeviceBasicInfo>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取所有可信设备列表的回调，返回设备信息。 |  
| Promise<Array<DeviceBasicInfo>> | Promise实例，用于获取异步返回结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager'  
import { BusinessError } from '@ohos.base'  
  
try {  
  dmInstance.getAvailableDeviceList((err: BusinessError, data: Array<deviceManager.DeviceBasicInfo>) => {  
    if (err) {  
      console.error("getAvailableDeviceList errCode:" + err.code + ",errMessage:" + err.message);  
      return;  
    }  
    console.log('get available device info: ' + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getAvailableDeviceList errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import deviceManager from '@ohos.distributedDeviceManager'  
import { BusinessError } from '@ohos.base'  
  
dmInstance.getAvailableDeviceList().then((data: Array<deviceManager.DeviceBasicInfo>) => {  
  console.log('get available device info: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.error("getAvailableDeviceList errCode:" + err.code + ",errMessage:" + err.message);  
});  
    
```    
  
    
### getLocalDeviceNetworkId    
获取本地设备网络标识。  
 **调用形式：**     
- getLocalDeviceNetworkId(): string  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回本地设备网络标识。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  let deviceNetworkId: string = dmInstance.getLocalDeviceNetworkId();  
  console.log('local device networkId: ' + JSON.stringify(deviceNetworkId));  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getLocalDeviceNetworkId errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getLocalDeviceName    
获取本地设备名称。  
 **调用形式：**     
- getLocalDeviceName(): string  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回本地设备名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  let deviceName: string = dmInstance.getLocalDeviceName();  
  console.log('local device name: ' + JSON.stringify(deviceName));  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getLocalDeviceName errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getLocalDeviceType    
获取本地设备类型。  
 **调用形式：**     
- getLocalDeviceType(): number  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回本地设备类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  let deviceType: number = dmInstance.getLocalDeviceType();  
  console.log('local device type: ' + JSON.stringify(deviceType));  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getLocalDeviceType errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getLocalDeviceId    
获取本地设备id。  
 **调用形式：**     
- getLocalDeviceId(): string  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回本地设备id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  let deviceId: string = dmInstance.getLocalDeviceId();  
  console.log('local device id: ' + JSON.stringify(deviceId));  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getLocalDeviceId errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getDeviceName    
通过指定设备的网络标识获取该设备名称。  
 **调用形式：**     
- getDeviceName(networkId: string): string  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| networkId | string | true | 设备的网络标识。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回指定设备名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  // 设备网络标识，可以从可信设备列表中获取  
  let networkId = "xxxxxxx"  
  let deviceName: string = dmInstance.getDeviceName(networkId);  
  console.log('device name: ' + JSON.stringify(deviceName));   
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getDeviceName errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### getDeviceType    
通过指定设备的网络标识获取该设备类型。  
 **调用形式：**     
- getDeviceType(networkId: string): number  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| networkId | string | true | 设备的网络标识。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定设备类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  // 设备网络标识，可以从可信设备列表中获取  
  let networkId = "xxxxxxx"  
  let deviceType: number = dmInstance.getDeviceType(networkId);  
  console.log('device type: ' + JSON.stringify(deviceType));   
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("getDeviceType errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### startDiscovering    
发现周边设备。发现状态持续两分钟，超过两分钟，会停止发现，最大发现数量99个。  
 **调用形式：**     
- startDiscovering(discoverParam: { [key: string]: Object }, filterOptions?: { [key: string]: Object }): void  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| discoverParam | { [key: string]: Object } | true | 发现标识。 标识发现的目标类型。<br>discoverTargetType: 发现目标默认为设备，值为1。 |  
| filterOptions | { [key: string]: Object } | false | 发现设备过滤信息。可选，默认为undefined，发现未上线设备。会携带以下key值：<br>availableStatus(0-1): 仅发现设备可信，值为0表示设备不可信。<br />-0: 设备离线，客户端需要通过调用bindTarget绑定设备。<br />-1: 设备已在线，客户可以进行连接。<br>discoverDistance(0-100): 发现距离本地一定距离内的设备，单位为cm。 <br>authenticationStatus(0-1): 根据不同的认证状态发现设备：<br />-0: 设备未认证。<br />-1：设备已认证。<br>authorizationType(0-2)：根据不同的授权类型发现设备：<br />-0: 根据临时协商的会话密钥认证的设备。<br />-1: 基于同账号密钥进行身份验证的设备。<br />-2: 基于不同账号凭据密钥认证的设备。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 11600104 | Failed to execute the function. |  
| 11600101 | Discovery repeats. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
interface DiscoverParam {  
  discoverTargetType: number  
}  
  
interface FilterOptions {  
  availableStatus: number,  
  discoverDistance: number,  
  authenticationStatus: number,  
  authorizationType: number  
}  
  
let discoverParam: Record<string, number> = {  
  'discoverTargetType': 1  
};  
let filterOptions: Record<string, number> = {  
  'availableStatus': 0  
};  
  
try {  
  dmInstance.startDiscovering(discoverParam, filterOptions); // 当有设备发现时，通过discoverSuccess回调通知给应用程序  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("startDiscovering errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### stopDiscovering    
停止发现周边设备。  
 **调用形式：**     
- stopDiscovering(): void  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 11600104 | Failed to execute the function. |  
| 11600101 | Stop discovery repeats. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  dmInstance.stopDiscovering();  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("stopDiscovering errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### bindTarget    
认证设备。  
 **调用形式：**     
    
- bindTarget(deviceId: string, bindParam: { [key: string]: Object }, callback: AsyncCallback\<{deviceId: string}>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 设备标识。 |  
| bindParam | { [key: string]: Object } | true | 认证参数。由开发者自行决定传入的键值对。默认会携带以下key值: <br>bindType 此值是绑定的类型。<br />-1 PIN码。<br />-2 二维码。<br />-3 NFC。 <br />-4 无交互。<br>targetPkgName 绑定目标的包名。<br>appName 尝试绑定目标的应用程序名称。<br>appOperation 应用程序要绑定目标的原因。<br>customDescription 操作的详细说明。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 认证结果回调 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
| 11600103 | Bind invalid. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  deviceId: string = ""  
}  
  
// 认证的设备信息，可以从发现的结果中获取  
let deviceId = "XXXXXXXX";  
let bindParam: Record<string, string | number> = {  
  bindType: 1, // 认证类型： 1 - 无帐号PIN码认证  
  targetPkgName: 'xxxx',  
  appName: 'xxxx',  
  appOperation: 'xxxx',  
  customDescription: 'xxxx'  
}  
  
try {  
  dmInstance.bindTarget(deviceId, bindParam, (err: BusinessError, data: Data) => {  
    if (err) {  
        console.error("bindTarget errCode:" + err.code + ",errMessage:" + err.message);  
        return;  
    }  
    console.info("bindTarget result:" + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("bindTarget errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### unbindTarget    
解除认证设备。  
 **调用形式：**     
- unbindTarget(deviceId: string): void  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 设备标识。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 201 |  |  
| 11600101 | Failed to execute the function. |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  let deviceId = "XXXXXXXX";  
  dmInstance.unbindTarget(deviceId);  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("unbindTarget errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('deviceStateChange')    
回复UI操作结果回调。  
 **调用形式：**     
    
- on(type: 'deviceStateChange', callback: Callback\<{ action: DeviceStateChange, device: DeviceBasicInfo }>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册的设备管理器 ui 状态回调，以便在状态改变时通知应用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示要注册的设备管理器 ui 状态回调，返回ui状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager'  
import { BusinessError } from '@ohos.base'  
  
class Data {  
  action: deviceManager.DeviceStateChange = 0  
  device: deviceManager.DeviceBasicInfo = {  
    deviceId: "",  
    deviceName: "",  
    deviceType: "",  
    networkId: "",  
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
取消回复UI操作结果回调。  
 **调用形式：**     
    
- off(type: 'deviceStateChange', callback?: Callback\<{ action: DeviceStateChange, device: DeviceBasicInfo }>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消注册的设备管理器 ui 状态回调。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示要取消注册的设备管理器 ui 状态，返回UI状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager'  
import { BusinessError } from '@ohos.base'  
  
class Data {  
  action: deviceManager.DeviceStateChange = 0  
  device: deviceManager.DeviceBasicInfo = {  
    deviceId: "",  
    deviceName: "",  
    deviceType: "",  
    networkId: "",  
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
  
    
### on('discoverSuccess')    
注册设备状态回调。  
 **调用形式：**     
    
- on(type: 'discoverSuccess', callback: Callback\<{ device: DeviceBasicInfo }>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册设备状态回调，固定为deviceStateChange。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示要注册的设备状态回调，返回设备状态和设备信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager'  
import { BusinessError } from '@ohos.base'  
  
class Data {  
  device: deviceManager.DeviceBasicInfo = {  
    deviceId: "",  
    deviceName: "",  
    deviceType: "",  
    networkId: "",  
  }  
}  
  
try {  
  dmInstance.on('discoverSuccess', (data: Data) => {  
    console.info("discoverSuccess:" + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("discoverSuccess errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('discoverSuccess')    
取消注册设备状态回调。  
 **调用形式：**     
    
- off(type: 'discoverSuccess', callback?: Callback\<{ device: DeviceBasicInfo }>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 根据应用程序的包名取消注册设备状态回调。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示要取消注册的设备状态回调，返回设备状态和设备信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import deviceManager from '@ohos.distributedDeviceManager'  
import { BusinessError } from '@ohos.base'  
  
class Data {  
  device: deviceManager.DeviceBasicInfo = {  
    deviceId: "",  
    deviceName: "",  
    deviceType: "",  
    networkId: "",  
  }  
}  
  
try {  
  dmInstance.off('discoverSuccess', (data: Data) => {  
    console.info('discoverSuccess' + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("discoverSuccess errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('deviceNameChange')    
注册发现设备成功回调监听。  
 **调用形式：**     
    
- on(type: 'deviceNameChange', callback: Callback\<{ deviceName: string }>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册设备发现回调，以便在发现周边设备时通知应用程序。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 注册设备发现的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```null    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  deviceName: string = ""  
}  
  
try {  
  dmInstance.on('deviceNameChange', (data: Data) => {  
      console.info("deviceNameChange on:" + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("deviceNameChange errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('deviceNameChange')    
取消注册设备发现成功回调。  
 **调用形式：**     
    
- off(type: 'deviceNameChange', callback?: Callback\<{ deviceName: string }>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消注册设备发现回调。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示要取消注册的设备发现回调，返回设备状态和设备信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  deviceName: string = ""  
}  
  
try {  
  dmInstance.off('deviceNameChange', (data: Data) => {  
    console.info('deviceNameChange' + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("deviceNameChange errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('discoverFailure')    
注册设备名称变更回调监听。  
 **调用形式：**     
    
- on(type: 'discoverFailure', callback: Callback\<{ reason: number }>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册设备名称改变回调，以便在设备名称改变时通知应用程序。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 注册设备名称改变的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  reason: number = 0  
}  
  
try {  
  dmInstance.on('discoverFailure', (data: Data) => {  
      console.info("discoverFailure on:" + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("discoverFailure errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('discoverFailure')    
取消注册设备名称变更回调监听。  
 **调用形式：**     
    
- off(type: 'discoverFailure', callback?: Callback\<{ reason: number }>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消注册设备名称改变回调。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示要取消注册设备名称改变的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
class Data {  
  reason: number = 0  
}  
  
try {  
  dmInstance.off('discoverFailure', (data: Data) => {  
    console.info('discoverFailure' + JSON.stringify(data));  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("discoverFailure errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### on('serviceDie')    
注册设备发现失败回调监听。  
 **调用形式：**     
    
- on(type: 'serviceDie', callback?: Callback\<{}>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 注册设备发现失败回调，以便在发现周边设备失败时通知应用程序。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 注册设备发现失败的回调方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
import { BusinessError } from '@ohos.base'  
  
try {  
  dmInstance.on("serviceDie", () => {  
    console.info("serviceDie on");  
  });  
} catch (err) {  
  let e: BusinessError = err as BusinessError;  
  console.error("serviceDie errCode:" + e.code + ",errMessage:" + e.message);  
}  
    
```    
  
    
### off('serviceDie')    
取消注册设备发现失败回调。  
 **调用形式：**     
    
- off(type: 'serviceDie', callback?: Callback\<{}>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedHardware.DeviceManager  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消注册设备发现失败回调。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示要取消注册的设备发现失败回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码：**   
示例：  
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
  
