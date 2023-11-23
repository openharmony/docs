# @ohos.wifiManager    
该模块主要提供WLAN基础功能、P2P（peer-to-peer）功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wifiManager from '@ohos.wifiManager'    
```  
    
## enableWifi    
使能WLAN，异步接口，是否打开成功需要注册并监听wifiStateChange的回调。  
 **调用形式：**     
- enableWifi(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
| 2501003 | Failed to enable Wi-Fi. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.enableWifi();  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## disableWifi    
去使能WLAN，异步接口，是否关闭成功需要注册并监听wifiStateChange的回调。  
 **调用形式：**     
- disableWifi(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
| 2501004 | Failed to disable Wi-Fi. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.disableWifi();  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## startScan<sup>(10+)</sup>    
启动WLAN扫描。  
 **调用形式：**     
- startScan(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.startScan();  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## setScanAlwaysAllowed<sup>(10+)</sup>    
设置是否始终允许扫描。  
 **调用形式：**     
- setScanAlwaysAllowed(isScanAlwaysAllowed: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isScanAlwaysAllowed | boolean | true | 是否始终允许扫描。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let isScanAlwaysAllowed = true;  
		wifiManager.setScanAlwaysAllowed(isScanAlwaysAllowed);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getScanAlwaysAllowed<sup>(10+)</sup>    
获取是否始终允许扫描。  
 **调用形式：**     
- getScanAlwaysAllowed(): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否始终允许扫描。 true 表示允许触发扫描，false表示在禁用wifi时不允许触发扫描 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let isScanAlwaysAllowed = wifiManager.getScanAlwaysAllowed();  
		console.info("isScanAlwaysAllowed:" + isScanAlwaysAllowed);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## addDeviceConfig    
添加网络配置，使用Promise异步回调。  
 **调用形式：**     
    
- addDeviceConfig(config: WifiDeviceConfig): Promise\<number>    
起始版本： 9    
- addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | WifiDeviceConfig | true | WLAN配置信息。如果bssidType未指定值，则bssidType默认为随机设备地址类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<number> | Promise对象。返回添加的网络配置ID，如果值为-1表示添加失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let config:wifiManager.WifiDeviceConfig = {  
			ssid : "****",  
			preSharedKey : "****",  
			securityType : 0  
		}  
		wifiManager.addDeviceConfig(config).then(result => {  
			console.info("result:" + JSON.stringify(result));  
		});	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let config:wifiManager.WifiDeviceConfig = {  
			ssid : "****",  
			preSharedKey : "****",  
			securityType : 0  
		}  
		wifiManager.addDeviceConfig(config,(error,result) => {  
			console.info("result:" + JSON.stringify(result));  
		});	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## connectToNetwork    
连接到指定网络（如果当前已经连接到热点，请先使用disconnet（）接口断开连接）。  
 **调用形式：**     
- connectToNetwork(networkId: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| networkId | number | true | 待连接的网络配置ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed |  
| 2501001 | Wifi is closed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let networkId = 0;  
		wifiManager.connectToNetwork(networkId);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## connectToDevice    
连接到指定网络（如果当前已经连接到热点，请先使用disconnet（）接口断开连接）。  
 **调用形式：**     
- connectToDevice(config: WifiDeviceConfig): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | WifiDeviceConfig | true | WLAN配置信息。如果bssidType未指定值，则bssidType默认为随机设备地址类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
| 2501001 | Wifi is closed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let config:wifiManager.WifiDeviceConfig = {  
			ssid : "****",  
			preSharedKey : "****",  
			securityType : 3  
		}  
		wifiManager.connectToDevice(config);  
				  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## disconnect    
断开连接的网络。  
 **调用形式：**     
- disconnect(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.disconnect();  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getSupportedFeatures    
查询设备支持的特性。  
 **调用形式：**     
- getSupportedFeatures(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 支持的特性值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2401000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let ret = wifiManager.getSupportedFeatures();  
		console.info("supportedFeatures:" + ret);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getDeviceMacAddress    
获取设备的MAC地址。  
 **调用形式：**     
- getDeviceMacAddress(): string[]  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_LOCAL_MAC and ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string[] | MAC地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed |  
| 2501001 | wifi is closed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let ret = wifiManager.getDeviceMacAddress();  
		console.info("deviceMacAddress:" + JSON.stringify(ret));  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## reassociate    
重新关联网络。  
 **调用形式：**     
- reassociate(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
| 2501001 | Wifi is closed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.reassociate();  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## reconnect    
重新连接网络。  
 **调用形式：**     
- reconnect(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
| 2501001 | Wifi is closed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.reconnect();  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getDeviceConfigs    
获取网络配置。  
 **调用形式：**     
- getDeviceConfigs(): Array\<WifiDeviceConfig>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.GET_WIFI_CONFIG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WifiDeviceConfig> | 网络配置信息的数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let configs = wifiManager.getDeviceConfigs();  
		console.info("configs:" + JSON.stringify(configs));  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getDeviceConfigs<sup>(10+)</sup>  
 **调用形式：**     
- getDeviceConfigs(): Array\<WifiDeviceConfig>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WifiDeviceConfig> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 |  |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let configs = wifiManager.getDeviceConfigs();  
		console.info("configs:" + JSON.stringify(configs));  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## updateNetwork    
更新网络配置。  
 **调用形式：**     
- updateNetwork(config: WifiDeviceConfig): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | WifiDeviceConfig | true | WLAN配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回更新的网络配置ID，如果值为-1表示更新失败。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let config:wifiManager.WifiDeviceConfig = {  
			ssid : "****",  
			preSharedKey : "****",  
			securityType : 3  
		}  
		let ret = wifiManager.updateNetwork(config);  
		console.info("ret:" + ret);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## disableNetwork    
去使能网络配置。  
 **调用形式：**     
- disableNetwork(netId: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| netId | number | true | 网络配置ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let netId = 0;  
		wifiManager.disableNetwork(netId);		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## removeAllNetwork    
移除所有网络配置。  
 **调用形式：**     
- removeAllNetwork(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.removeAllNetwork();		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## removeDevice    
移除指定的网络配置。  
 **调用形式：**     
- removeDevice(id: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | number | true | 网络配置ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
mport wifiManager from '@ohos.wifiManager';  
  
	try {  
		let id = 0;  
		wifiManager.removeDevice(id);		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## get5GChannelList<sup>(10+)</sup>    
获取当前设备支持的5G信道列表。  
 **调用形式：**     
- get5GChannelList(): Array\<number>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<number> | 设备支持的5G信道列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let channelList = wifiManager.get5GChannelList();  
		console.info("channelList:" + JSON.stringify(channelList));		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getDisconnectedReason<sup>(10+)</sup>    
获取最近一次断连原因。  
 **调用形式：**     
- getDisconnectedReason(): DisconnectedReason  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DisconnectedReason | 最近断开的原因 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let disconnectedReason = wifiManager.getDisconnectedReason();	  
        console.info("disconnectedReason:" + disconnectedReason);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## enableHotspot    
使能热点，异步接口，是否打开成功需要注册并监听hotspotStateChange的回调。  
 **调用形式：**     
- enableHotspot(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.enableHotspot();	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## disableHotspot    
去使能热点 ，异步接口，是否关闭成功需要注册并监听hotspotStateChange的回调。  
 **调用形式：**     
- disableHotspot(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.disableHotspot();	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## isHotspotDualBandSupported    
热点是否支持双频。  
 **调用形式：**     
- isHotspotDualBandSupported(): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.MANAGE_WIFI_HOTSPOT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:支持，false:不支持. |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let ret = wifiManager.isHotspotDualBandSupported();  
		console.info("result:" + ret);		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## isHotspotActive    
热点是否已使能。  
 **调用形式：**     
- isHotspotActive(): boolean  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:已使能，false:未使能. |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let ret = wifiManager.isHotspotActive();  
		console.info("result:" + ret);		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## setHotspotConfig    
设置热点配置信息。  
 **调用形式：**     
- setHotspotConfig(config: HotspotConfig): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | HotspotConfig | true | 热点配置信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let config:wifiManager.HotspotConfig = {  
			ssid: "****",  
			securityType: 3,  
			band: 0,  
			channel: 0,  
			preSharedKey: "****",  
			maxConn: 0  
		}  
		let ret = wifiManager.setHotspotConfig(config);  
		console.info("result:" + ret);		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getHotspotConfig    
获取热点配置信息。  
 **调用形式：**     
- getHotspotConfig(): HotspotConfig  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| HotspotConfig | 热点的配置信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let config = wifiManager.getHotspotConfig();  
		console.info("result:" + JSON.stringify(config));		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getStations    
获取连接的设备。  
 **调用形式：**     
- getStations(): Array\<StationInfo>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.MANAGE_WIFI_HOTSPOT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<StationInfo> | 连接的设备数组。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的macAddress为真实设备地址，否则为随机设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let stations = wifiManager.getStations();  
		console.info("result:" + JSON.stringify(stations));		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getStations<sup>(10+)</sup>  
 **调用形式：**     
- getStations(): Array\<StationInfo>  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.MANAGE_WIFI_HOTSPOT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<StationInfo> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2601000 |  |  
    
## deletePersistentGroup    
删除永久组。  
 **调用形式：**     
- deletePersistentGroup(netId: number): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| netId | number | true | 组的ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let netId = 0;  
		wifiManager.deletePersistentGroup(netId);	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getP2pGroups    
获取创建的所有P2P群组信息，使用Promise异步回调。  
 **调用形式：**     
    
- getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>    
起始版本： 9    
- getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>    
起始版本： 10    
- getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void    
起始版本： 9    
- getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Array<WifiP2pGroupInfo>> | GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
wifiManager.getP2pGroups((err, data) => {    if (err) {        console.error("get P2P groups error");        return;    }console.info("get P2P groups: " + JSON.stringify(data));});  
wifiManager.getP2pGroups().then(data => {console.info("get P2P groups: " + JSON.stringify(data));});    
```    
  
    
## setDeviceName    
设置设备名称。  
 **调用形式：**     
- setDeviceName(devName: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| devName | string | true | 设备名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let name = "****";  
		wifiManager.setDeviceName(name);	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## on('streamChange')    
注册WIFI流变更事件，当前版本不支持，抛出通用错误码801。  
 **调用形式：**     
    
- on(type: 'streamChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"streamChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数，返回0:无，1：向下，2：向上，3：双向。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
## off('streamChange')    
取消注册WIFI流变更事件，当前版本不支持，抛出通用错误码801。  
 **调用形式：**     
    
- off(type: 'streamChange', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"streamChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数，返回0:无，1：向下，2：向上，3：双向。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | eration failed. |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvStreamChangeFunc = (result:number) => {    console.info("Receive stream change event: " + result);}  
// Register eventwifi.on("streamChange", recvStreamChangeFunc);  
// Unregister eventwifi.off("streamChange", recvStreamChangeFunc);    
```    
  
    
## on('deviceConfigChange')    
注册WIFI设备配置更改事件。  
 **调用形式：**     
    
- on(type: 'deviceConfigChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"streamChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数，返回0: 添加配置, 1: 更改配置, 2: 删除配置. |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 |  |  
    
## off('deviceConfigChange')    
取消注册WIFI设备配置更改事件。  
 **调用形式：**     
    
- off(type: 'deviceConfigChange', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"streamChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数，返回0: 添加配置, 1: 更改配置, 2: 删除配置. |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifiManager';  
let recvDeviceConfigChangeFunc = (result:number) => {    console.info("Receive device config change event: " + result);}  
// Register eventwifi.on("deviceConfigChange", recvDeviceConfigChangeFunc);  
// Unregister eventwifi.off("deviceConfigChange", recvDeviceConfigChangeFunc);    
```    
  
    
## on('hotspotStaJoin')    
注册wifi热点sta加入事件。  
 **调用形式：**     
    
- on(type: 'hotspotStaJoin', callback: Callback\<StationInfo>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 定填"hotspotStaJoin"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
## off('hotspotStaJoin')    
取消注册wifi热点sta加入事件。  
 **调用形式：**     
    
- off(type: 'hotspotStaJoin', callback?: Callback\<StationInfo>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"hotspotStaJoin"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
let recvHotspotStaJoinFunc = (result:wifiManager.StationInfo) => {    console.info("Receive hotspot sta join event: " + result);}  
// Register eventwifiManager.on("hotspotStaJoin", recvHotspotStaJoinFunc);  
// Unregister eventwifiManager.off("hotspotStaJoin", recvHotspotStaJoinFunc);    
```    
  
    
## on('hotspotStaLeave')    
注册wifi热点sta离开事件。  
 **调用形式：**     
    
- on(type: 'hotspotStaLeave', callback: Callback\<StationInfo>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"hotspotStaLeave"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
## off('hotspotStaLeave')    
取消注册wifi热点sta离开事件。  
 **调用形式：**     
    
- off(type: 'hotspotStaLeave', callback?: Callback\<StationInfo>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"hotspotStaLeave"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2601000 | Operation failed. |  
    
 **示例代码：**   
```ts    
mport wifiManager from '@ohos.wifiManager';  
let recvHotspotStaLeaveFunc = (result:wifiManager.StationInfo) => {    console.info("Receive hotspot sta leave event: " + result);}  
// Register eventwifiManager.on("hotspotStaLeave", recvHotspotStaLeaveFunc);  
// Unregister eventwifiManager.off("hotspotStaLeave", recvHotspotStaLeaveFunc);    
```    
  
    
## DisconnectedReason<sup>(10+)</sup>    
表示wifi断开原因的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DISC_REASON_DEFAULT | 0 | 默认原因。 |  
| DISC_REASON_WRONG_PWD | 1 | 密码错误。 |  
| DISC_REASON_CONNECTION_FULL | 2 | 路由器的连接数已达到最大数量限制。 |  
    
## ProxyMethod<sup>(10+)</sup>    
表示WiFi代理方法的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| METHOD_NONE | 0 | 不使用代理。 |  
| METHOD_AUTO | 1 | 使用自动配置的代理。 |  
| METHOD_MANUAL | 2 | 使用手动配置的代理。 |  
    
## WifiProxyConfig<sup>(10+)</sup>    
Wifi 代理配置。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| proxyMethod<sup>(10+)</sup> | ProxyMethod | false | false | 代理方法 |  
| pacWebAddress<sup>(10+)</sup> | string | false | false | 自动配置代理的PAC web 地址。 |  
| serverHostName<sup>(10+)</sup> | string | false | false | 手动配置代理的服务器主机名。 |  
| serverPort<sup>(10+)</sup> | number | false | false | 手动配置代理的服务器端口。 |  
| exclusionObjects<sup>(10+)</sup> | string | false | false | 手动配置代理的排除对象，对象用“,”分隔。 |  
    
## WifiDeviceConfig    
WLAN配置信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| creatorUid | number | false | false | 创建用户的ID。 <br /> **系统接口：** 此接口为系统接口。 |  
| disableReason | number | false | false | 禁用原因。 <br /> **系统接口：** 此接口为系统接口。 |  
| netId | number | false | false | 分配的网络ID。 <br /> **系统接口：** 此接口为系统接口。 |  
| randomMacType | number | false | false | MAC地址类型。0 - 随机MAC地址，1 - 设备MAC地址 <br /> **系统接口：** 此接口为系统接口。 |  
| randomMacAddr | string | false | false | MAC地址。<br /> **系统接口：** 此接口为系统接口。 |  
| ipType | IpType | false | false | IP地址类型。 <br /> **系统接口：** 此接口为系统接口。 |  
| staticIp | IpConfig | false | false | 静态IP配置信息。 <br /> **系统接口：** 此接口为系统接口。 |  
| proxyConfig<sup>(10+)</sup> | WifiProxyConfig | false | false | 代理配置。  <br /> **系统接口：** 此接口为系统接口。 |  
    
## IpConfig    
IP配置信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ipAddress | number | false | true | IP地址。 |  
| gateway | number | false | true | 网关。 |  
| prefixLength | number | false | true | 掩码。 |  
| dnsServers | number[] | false | true | DNS服务器。 |  
| domains | Array<string> | false | true | 域信息。 |  
    
## WifiLinkedInfo    
提供WLAN连接的相关信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| networkId | number | false | true | 网络配置ID。 <br /> **系统接口：** 此接口为系统接口。 |  
| chload | number | false | true | 连接负载，值越大表示负载约高。 <br /> **系统接口：** 此接口为系统接口 |  
| snr | number | false | true | 信噪比。 <br /> **系统接口：** 此接口为系统接口。 |  
| suppState | SuppState | false | true | 请求状态。 <br /> **系统接口：** 此接口为系统接口。 |  
    
## HotspotConfig    
热点配置信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid | string | false | true | 热点的SSID，编码格式为UTF-8 |  
| securityType | WifiSecurityType | false | true | 加密类型。 |  
| band | number | false | true | 热点的带宽。1: 2.4G, 2: 5G, 3: 双模频段 |  
| channel<sup>(10+)</sup> | number | false | false | 热点的信道（2.4G：1~14,5G：7~196，双模频段：暂不支持）。 |  
| preSharedKey | string | false | true | 热点的密钥。 |  
| maxConn | number | false | true | 最大设备连接数。 |  
| ipAddress<sup>(10+)</sup> | string | false | false |  |  
    
## StationInfo    
接入的设备信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 设备名称。 |  
| macAddress | string | false | true | MAC地址。 |  
| macAddressType<sup>(10+)</sup> | DeviceAddressType | false | false | MAC地址类型。 |  
| ipAddress | string | false | true | IP地址。 |  
    
## IpType    
表示IP类型的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATIC | 0 | 静态IP。 |  
| DHCP | 1 | 通过DHCP获取。 |  
| UNKNOWN | 2 | 未指定。 |  
    
## SuppState    
表示请求状态的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DISCONNECTED | 0 | 已断开。 |  
| INTERFACE_DISABLED | 1 | 接口禁用。 |  
| INACTIVE | 2 | 未激活。 |  
| SCANNING | 3 | 扫描中。 |  
| AUTHENTICATING | 4 | 认证中。 |  
| ASSOCIATING | 5 | 关联中。 |  
| ASSOCIATED | 6 | 已关联。 |  
| FOUR_WAY_HANDSHAKE | 7 | 四次握手。 |  
| GROUP_HANDSHAKE | 8 | 组握手。 |  
| COMPLETED | 9 | 所有认证已完成。 |  
| UNINITIALIZED | 10 | 连接建立失败。 |  
| INVALID | 11 | 无效值。 |  
