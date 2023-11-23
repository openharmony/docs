# @ohos.wifi    
该模块主要提供WLAN基础功能、P2P（peer-to-peer）功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wifi from '@ohos.wifi'    
```  
    
## enableWifi<sup>(deprecated)</sup>    
使能WLAN。  
 **调用形式：**     
- enableWifi(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.enableWifi。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.enableWifi();  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## disableWifi<sup>(deprecated)</sup>    
去使能WLAN。  
 **调用形式：**     
- disableWifi(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.disableWifi。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.disableWifi();  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## addDeviceConfig<sup>(deprecated)</sup>    
添加网络配置，使用Promise异步回调。  
 **调用形式：**     
- addDeviceConfig(config: WifiDeviceConfig): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.addDeviceConfig。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiDeviceConfig | true | WLAN配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象。返回添加的网络配置ID，如果值为-1表示添加失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let config:wifi.WifiDeviceConfig = {  
		ssid : "****",  
		bssid:  "****",  
		preSharedKey: "****",  
		isHiddenSsid: false,  
		securityType: 0,  
		creatorUid: 0,  
		disableReason: 0,  
		netId: 0,  
		randomMacType: 0,  
		randomMacAddr:  "****",  
		ipType: 0,  
		staticIp: {  
			ipAddress: 0,  
			gateway: 0,  
			dnsServers: [],  
			domains: []  
		}  
	}  
	wifi.addDeviceConfig(config).then(result => {  
		console.info("result:" + JSON.stringify(result));  
	});	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## addDeviceConfig<sup>(deprecated)</sup>  
 **调用形式：**     
- addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.addDeviceConfig。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiDeviceConfig | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true |  |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let config:wifi.WifiDeviceConfig = {  
		ssid : "****",  
		bssid:  "****",  
		preSharedKey: "****",  
		isHiddenSsid: false,  
		securityType: 0,  
		creatorUid: 0,  
		disableReason: 0,  
		netId: 0,  
		randomMacType: 0,  
		randomMacAddr:  "****",  
		ipType: 0,  
		staticIp: {  
			ipAddress: 0,  
			gateway: 0,  
			dnsServers: [],  
			domains: []  
		}  
	}  
	wifi.addDeviceConfig(config,(error,result) => {  
		console.info("result:" + JSON.stringify(result));  
	});	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## connectToNetwork<sup>(deprecated)</sup>    
连接到指定网络。  
 **调用形式：**     
- connectToNetwork(networkId: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.connectToNetwork。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| networkId<sup>(deprecated)</sup> | number | true | 待连接的网络配置ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let networkId = 0;  
	wifi.connectToNetwork(networkId);  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## connectToDevice<sup>(deprecated)</sup>    
连接到指定网络。  
 **调用形式：**     
- connectToDevice(config: WifiDeviceConfig): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.connectToDevice。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiDeviceConfig | true | WLAN配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let config:wifi.WifiDeviceConfig = {  
		ssid : "****",  
		bssid:  "****",  
		preSharedKey: "****",  
		isHiddenSsid: false,  
		securityType: 3,  
		creatorUid: 0,  
		disableReason: 0,  
		netId: 0,  
		randomMacType: 0,  
		randomMacAddr:  "****",  
		ipType: 0,  
		staticIp: {  
		ipAddress: 0,  
			gateway: 0,  
			dnsServers: [],  
			domains: []  
		}  
	}  
	wifi.connectToDevice(config);  
			  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## disconnect<sup>(deprecated)</sup>    
断开连接的网络。  
 **调用形式：**     
- disconnect(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.disconnect。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.disconnect();  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getSupportedFeatures<sup>(deprecated)</sup>    
查询设备支持的特性。  
 **调用形式：**     
- getSupportedFeatures(): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getSupportedFeatures。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 支持的特性值。 |  
    
## getDeviceMacAddress<sup>(deprecated)</sup>    
获取设备的MAC地址。  
 **调用形式：**     
- getDeviceMacAddress(): string[]  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getDeviceMacAddress。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_LOCAL_MAC and ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string[] | MAC地址。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let ret = wifi.getDeviceMacAddress();  
	console.info("deviceMacAddress:" + JSON.stringify(ret));  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## reassociate<sup>(deprecated)</sup>    
重新关联网络。  
 **调用形式：**     
- reassociate(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.reassociate。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.reassociate();  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## reconnect<sup>(deprecated)</sup>    
重新连接网络。  
 **调用形式：**     
- reconnect(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.reconnect。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.reconnect();  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getDeviceConfigs<sup>(deprecated)</sup>    
获取网络配置。  
 **调用形式：**     
- getDeviceConfigs(): Array\<WifiDeviceConfig>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getDeviceConfigs。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.GET_WIFI_CONFIG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WifiDeviceConfig> | 网络配置信息的数组。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let configs = wifi.getDeviceConfigs();  
	console.info("configs:" + JSON.stringify(configs));  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## updateNetwork<sup>(deprecated)</sup>    
更新网络配置。  
 **调用形式：**     
- updateNetwork(config: WifiDeviceConfig): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.updateDeviceConfig。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiDeviceConfig | true | WLAN配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回更新的网络配置ID，如果值为-1表示更新失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let config:wifi.WifiDeviceConfig = {  
		ssid : "****",  
		bssid:  "****",  
		preSharedKey: "****",  
		isHiddenSsid: false,  
		securityType: 3,  
		creatorUid: 0,  
		disableReason: 0,  
		netId: 0,  
		randomMacType: 0,  
		randomMacAddr:  "****",  
		ipType: 0,  
		staticIp: {  
			ipAddress: 0,  
			gateway: 0,  
			dnsServers: [],  
			domains: []  
		}  
	}  
	let ret = wifi.updateNetwork(config);  
	console.error("ret:" + ret);		  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## disableNetwork<sup>(deprecated)</sup>    
去使能网络配置。  
 **调用形式：**     
- disableNetwork(netId: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.disableDeviceConfig。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| netId<sup>(deprecated)</sup> | number | true | 网络配置ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let netId = 0;  
	wifi.disableNetwork(netId);		  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## removeAllNetwork<sup>(deprecated)</sup>    
移除所有网络配置。  
 **调用形式：**     
- removeAllNetwork(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.removeAllDeviceConfigs。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.removeAllNetwork();		  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## removeDevice<sup>(deprecated)</sup>    
移除指定的网络配置。  
 **调用形式：**     
- removeDevice(id: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.removeDeviceConfig。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id<sup>(deprecated)</sup> | number | true | 网络配置ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let id = 0;  
	wifi.removeDevice(id);		  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## enableHotspot<sup>(deprecated)</sup>    
使能热点。  
 **调用形式：**     
- enableHotspot(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.enableHotspot。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.enableHotspot();	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## disableHotspot<sup>(deprecated)</sup>    
去使能热点。  
 **调用形式：**     
- disableHotspot(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.disableHotspot。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.disableHotspot();	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## isHotspotDualBandSupported<sup>(deprecated)</sup>    
热点是否支持双频。  
 **调用形式：**     
- isHotspotDualBandSupported(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.isHotspotDualBandSupported。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.MANAGE_WIFI_HOTSPOT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | rue:支持，false:不支持。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let ret = wifi.isHotspotDualBandSupported();  
	console.info("result:" + ret);		  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## isHotspotActive<sup>(deprecated)</sup>    
热点是否已使能。  
 **调用形式：**     
- isHotspotActive(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.isHotspotActive。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:已使能，false:未使能。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let ret = wifi.isHotspotActive();  
	console.info("result:" + ret);		  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## setHotspotConfig<sup>(deprecated)</sup>    
设置热点配置信息。  
 **调用形式：**     
- setHotspotConfig(config: HotspotConfig): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.setHotspotConfig。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | HotspotConfig | true | 热点配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let config:wifi.HotspotConfig = {  
		ssid: "****",  
		securityType: 3,  
		band: 0,  
		preSharedKey: "****",  
		maxConn: 0  
	}  
	let ret = wifi.setHotspotConfig(config);  
	console.info("result:" + ret);		  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getHotspotConfig<sup>(deprecated)</sup>    
获取热点配置信息。  
 **调用形式：**     
- getHotspotConfig(): HotspotConfig  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getHotspotConfig。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| HotspotConfig | 热点的配置信息。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let config = wifi.getHotspotConfig();  
	console.info("result:" + JSON.stringify(config));		  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getStations<sup>(deprecated)</sup>    
获取连接的设备。  
 **调用形式：**     
- getStations(): Array\<StationInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getHotspotStations。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.MANAGE_WIFI_HOTSPOT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<StationInfo> | 连接的设备数组。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let stations = wifi.getStations();  
	console.info("result:" + JSON.stringify(stations));		  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## deletePersistentGroup<sup>(deprecated)</sup>    
删除永久组。  
 **调用形式：**     
- deletePersistentGroup(netId: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.deletePersistentP2pGroup。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| netId<sup>(deprecated)</sup> | number | true | 组的ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作执行成功，操作执行失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let netId = 0;  
	wifi.deletePersistentGroup(netId);	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## setDeviceName<sup>(deprecated)</sup>    
设置设备名称。  
 **调用形式：**     
- setDeviceName(devName: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.setP2pDeviceName。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| devName<sup>(deprecated)</sup> | string | true | 设备名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作成功，false:操作失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let name = "****";  
	wifi.setDeviceName(name);	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## on('streamChange')<sup>(deprecated)</sup>    
注册WIFI流更改事件。  
 **调用形式：**     
- on(type: 'streamChange', callback: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:streamChange。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"streamChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | true | 状态改变回调函数，返回0:无，1：向下，2：向上，3：双向。 |  
    
## off('streamChange')<sup>(deprecated)</sup>    
取消注册WIFI流更改事件。  
 **调用形式：**     
- off(type: 'streamChange', callback?: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:streamChange。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"streamChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | false | 状态改变回调函数，返回0:无，1：向下，2：向上，3：双向。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvStreamChangeFunc = (result:number) => {    console.info("Receive stream change event: " + result);}  
// Register eventwifi.on("streamChange", recvStreamChangeFunc);  
// Unregister eventwifi.off("streamChange", recvStreamChangeFunc);    
```    
  
    
## on('hotspotStaJoin')<sup>(deprecated)</sup>    
注册wifi热点sta加入事件。  
 **调用形式：**     
- on(type: 'hotspotStaJoin', callback: Callback\<StationInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:hotspotStaJoin。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"hotspotStaJoin"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<StationInfo> | true | 状态改变回调函数 |  
    
## off('hotspotStaJoin')<sup>(deprecated)</sup>    
取消注册wifi热点sta加入事件。  
 **调用形式：**     
- off(type: 'hotspotStaJoin', callback?: Callback\<StationInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:hotspotStaJoin。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"hotspotStaJoin"字符串 |  
| callback<sup>(deprecated)</sup> | Callback<StationInfo> | false | 状态改变回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvHotspotStaJoinFunc = (result:wifi.StationInfo) => {    console.info("Receive hotspot sta join event: " + result);}  
// Register eventwifi.on("hotspotStaJoin", recvHotspotStaJoinFunc);  
// Unregister eventwifi.off("hotspotStaJoin", recvHotspotStaJoinFunc);    
```    
  
    
## on('hotspotStaLeave')<sup>(deprecated)</sup>    
注册wifi热点sta离开事件。  
 **调用形式：**     
- on(type: 'hotspotStaLeave', callback: Callback\<StationInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:hotspotStaLeave。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"hotspotStaLeave"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<StationInfo> | true | 状态改变回调函数。 |  
    
## off('hotspotStaLeave')<sup>(deprecated)</sup>    
取消注册wifi热点sta离开事件。  
 **调用形式：**     
- off(type: 'hotspotStaLeave', callback?: Callback\<StationInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:hotspotStaLeave。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"hotspotStaLeave"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<StationInfo> | false | 状态改变回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvHotspotStaLeaveFunc = (result:wifi.StationInfo) => {    console.info("Receive hotspot sta leave event: " + result);}  
// Register eventwifi.on("hotspotStaLeave", recvHotspotStaLeaveFunc);  
// Unregister eventwifi.off("hotspotStaLeave", recvHotspotStaLeaveFunc);    
```    
  
    
## IpConfig<sup>(deprecated)</sup>    
IP配置信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.IpConfig替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
## HotspotConfig<sup>(deprecated)</sup>    
热点配置信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.HotspotConfig替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>热点的SSID，编码格式为UTF-8 |  
| securityType<sup>(deprecated)</sup> | WifiSecurityType | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>加密类型。 |  
| band<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>热点的带宽。1: 2.4G, 2: 5G, 3: 双模频段 |  
| preSharedKey<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>热点的密钥。 |  
| maxConn<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>最大设备连接数。 |  
    
## StationInfo<sup>(deprecated)</sup>    
接入的设备信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.StationInfo替代。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>设备名称。 |  
| macAddress<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>MAC地址。 |  
| ipAddress<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>IP地址。 |  
    
## IpType<sup>(deprecated)</sup>    
表示IP类型的枚举。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.IpType替代。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATIC<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>静态IP。 |  
| DHCP<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>通过DHCP获取。 |  
| UNKNOWN<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>未指定。 |  
    
## SuppState<sup>(deprecated)</sup>    
表示请求状态的枚举。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.SuppState替代。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DISCONNECTED<sup>(deprecated)</sup> | 0 | 从API version 6 开始支持，从API version 9 开始废弃。<br>已断开。 |  
| INTERFACE_DISABLED<sup>(deprecated)</sup> | 1 | 从API version 6 开始支持，从API version 9 开始废弃。<br>接口禁用。 |  
| INACTIVE<sup>(deprecated)</sup> | 2 | 从API version 6 开始支持，从API version 9 开始废弃。<br>未激活。 |  
| SCANNING<sup>(deprecated)</sup> | 3 | 从API version 6 开始支持，从API version 9 开始废弃。<br>扫描中。 |  
| AUTHENTICATING<sup>(deprecated)</sup> | 4 | 从API version 6 开始支持，从API version 9 开始废弃。<br>认证中。 |  
| ASSOCIATING<sup>(deprecated)</sup> | 5 | 从API version 6 开始支持，从API version 9 开始废弃。<br>关联中。 |  
| ASSOCIATED<sup>(deprecated)</sup> | 6 | 从API version 6 开始支持，从API version 9 开始废弃。<br>已关联。 |  
| FOUR_WAY_HANDSHAKE<sup>(deprecated)</sup> | 7 | 从API version 6 开始支持，从API version 9 开始废弃。<br>四次握手。 |  
| GROUP_HANDSHAKE<sup>(deprecated)</sup> | 8 | 从API version 6 开始支持，从API version 9 开始废弃。<br>组握手。 |  
| COMPLETED<sup>(deprecated)</sup> | 9 | 从API version 6 开始支持，从API version 9 开始废弃。<br>所有认证已完成。 |  
| UNINITIALIZED<sup>(deprecated)</sup> | 10 | 从API version 6 开始支持，从API version 9 开始废弃。<br>连接建立失败。 |  
| INVALID<sup>(deprecated)</sup> | 11 | 从API version 6 开始支持，从API version 9 开始废弃。<br>无效值。 |  
