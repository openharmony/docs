# @ohos.wifi    
该模块主要提供WLAN基础功能、P2P（peer-to-peer）功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wifi from '@ohos.wifi'    
```  
    
## isWifiActive<sup>(deprecated)</sup>    
查询WLAN是否已使能。  
 **调用形式：**     
- isWifiActive(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.isWifiActive。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:已使能，false:未使能。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let isWifiActive = wifi.isWifiActive();  
	console.info("isWifiActive:" + isWifiActive);  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## scan<sup>(deprecated)</sup>    
启动WLAN扫描。  
 **调用形式：**     
- scan(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.scan。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:扫描操作执行成功，false:扫描操作执行失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.scan();  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getScanInfos<sup>(deprecated)</sup>    
获取扫描结果，使用Promise异步回调。  
 **调用形式：**     
- getScanInfos(): Promise\<Array\<WifiScanInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getScanInfoList。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or ohos.permission.LOCATION)    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<WifiScanInfo>> | Promise对象。返回扫描到的热点列表。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';wifi.getScanInfos().then(result => {    let len = result.length;    console.log("wifi received scan info: " + len);    for (let i = 0; i < len; ++i) {        console.info("ssid: " + result[i].ssid);        console.info("bssid: " + result[i].bssid);        console.info("capabilities: " + result[i].capabilities);        console.info("securityType: " + result[i].securityType);        console.info("rssi: " + result[i].rssi);        console.info("band: " + result[i].band);        console.info("frequency: " + result[i].frequency);        console.info("channelWidth: " + result[i].channelWidth);        console.info("timestamp: " + result[i].timestamp);    }});    
```    
  
    
## getScanInfos<sup>(deprecated)</sup>    
获取扫描结果，使用callback异步回调。  
 **调用形式：**     
- getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getScanInfoList。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or ohos.permission.LOCATION)    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<WifiScanInfo>> | true | 回调函数。当成功时，err为0，data为扫描到的热点；否则err为非0值，data为空。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
wifi.getScanInfos((err, result) => {    if (err) {        console.error("get scan info error");        return;    }  
    let len = result.length;    console.log("wifi received scan info: " + len);    for (let i = 0; i < len; ++i) {        console.info("ssid: " + result[i].ssid);        console.info("bssid: " + result[i].bssid);        console.info("capabilities: " + result[i].capabilities);        console.info("securityType: " + result[i].securityType);        console.info("rssi: " + result[i].rssi);        console.info("band: " + result[i].band);        console.info("frequency: " + result[i].frequency);        console.info("channelWidth: " + result[i].channelWidth);        console.info("timestamp: " + result[i].timestamp);    }});    
```    
  
    
## addUntrustedConfig<sup>(deprecated)</sup>    
添加不可信网络配置，使用Promise异步回调。  
 **调用形式：**     
- addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.addCandidateConfig。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiDeviceConfig | true | WLAN配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。表示操作结果，true: 成功， false: 失败。 |  
    
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
	wifi.addUntrustedConfig(config).then(result => {  
		console.info("result:" + JSON.stringify(result));  
	});	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## addUntrustedConfig<sup>(deprecated)</sup>    
添加不可信网络配置，使用callback异步回调。  
 **调用形式：**     
- addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.addCandidateConfig。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiDeviceConfig | true | WLAN配置信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。当操作成功时，err为0，data表示操作结果，true |  
    
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
	wifi.addUntrustedConfig(config,(error,result) => {  
		console.info("result:" + JSON.stringify(result));  
	});	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## removeUntrustedConfig<sup>(deprecated)</sup>    
移除不可信网络配置，使用Promise异步回调。  
 **调用形式：**     
- removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.removeCandidateConfig。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiDeviceConfig | true | WLAN配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。表示操作结果，true: 成功， false: 失败。 |  
    
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
	wifi.removeUntrustedConfig(config).then(result => {  
		console.info("result:" + JSON.stringify(result));  
	});	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## removeUntrustedConfig<sup>(deprecated)</sup>    
移除不可信网络配置，使用callback异步回调。  
 **调用形式：**     
- removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.removeCandidateConfig。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiDeviceConfig | true | WLAN配置信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。当操作成功时，err为0，data表示操作结果，true: 成功， false: 失败。如果error为非0，表示处理出现错误。 |  
    
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
	wifi.removeUntrustedConfig(config,(error,result) => {  
	console.info("result:" + JSON.stringify(result));  
	});	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getSignalLevel<sup>(deprecated)</sup>    
查询WLAN信号强度。  
 **调用形式：**     
- getSignalLevel(rssi: number, band: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getSignalLevel。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rssi<sup>(deprecated)</sup> | number | true | 热点的信号强度(dBm)。 |  
| band<sup>(deprecated)</sup> | number | true | WLAN接入点的频段。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 信号强度，取值范围为[0,4]。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let rssi = 0;  
	let band = 0;  
	let level = wifi.getSignalLevel(rssi,band);  
	console.info("level:" + JSON.stringify(level));  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getLinkedInfo<sup>(deprecated)</sup>    
获取WLAN连接信息，使用Promise异步回调。  
 **调用形式：**     
- getLinkedInfo(): Promise\<WifiLinkedInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getLinkedInfo。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<WifiLinkedInfo> | Promise对象。表示WLAN连接信息。 |  
    
 **示例代码：**   
```null    
mport wifi from '@ohos.wifi';wifi.getLinkedInfo().then(data => {    console.info("get wifi linked info: " + JSON.stringify(data));}).catch((error:number) => {    console.info("get linked info error");});    
```    
  
    
## getLinkedInfo<sup>(deprecated)</sup>    
获取WLAN连接信息，使用callback异步回调。  
 **调用形式：**     
- getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getLinkedInfo。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<WifiLinkedInfo> | true | 回调函数。当获取成功时，err为0，data表示WLAN连接信息。如果error为非0，表示处理出现错误。 |  
    
 **示例代码：**   
```null    
import wifi from '@ohos.wifi';  
wifi.getLinkedInfo((err, data) => {    if (err) {        console.error("get linked info error");        return;    }    console.info("get wifi linked info: " + JSON.stringify(data));});    
```    
  
    
## isConnected<sup>(deprecated)</sup>    
查询WLAN是否已连接。  
 **调用形式：**     
- isConnected(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.isConnected。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:已连接，false:未连接。 |  
    
## isFeatureSupported<sup>(deprecated)</sup>    
判断设备是否支持相关WLAN特性。  
 **调用形式：**     
- isFeatureSupported(featureId: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.isFeatureSupported。  
 **系统能力:**  SystemCapability.Communication.WiFi.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| featureId<sup>(deprecated)</sup> | number | true | 特性ID值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:支持，false:不支持。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let featureId = 0;  
	let ret = wifi.isFeatureSupported(featureId);  
	console.info("isFeatureSupported:" + ret);  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getIpInfo<sup>(deprecated)</sup>    
获取IP信息。  
 **调用形式：**     
- getIpInfo(): IpInfo  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getIpInfo。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IpInfo | IP信息。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let info = wifi.getIpInfo();  
	console.info("info:" + JSON.stringify(info));  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getCountryCode<sup>(deprecated)</sup>    
获取国家码信息。  
 **调用形式：**     
- getCountryCode(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getCountryCode。  
 **系统能力:**  SystemCapability.Communication.WiFi.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 国家码。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let code = wifi.getCountryCode();  
	console.info("code:" + code);  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## getP2pLinkedInfo<sup>(deprecated)</sup>    
获取P2P连接信息，使用Promise异步回调。  
 **调用形式：**     
- getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getP2pLinkedInfo。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<WifiP2pLinkedInfo> | Promise对象。表示P2P连接信息。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';wifi.getP2pLinkedInfo().then(data => {console.info("get wifi p2p linked info: " + JSON.stringify(data));});    
```    
  
    
## getP2pLinkedInfo<sup>(deprecated)</sup>  
 **调用形式：**     
- getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getP2pLinkedInfo。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<WifiP2pLinkedInfo> | true |  |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
wifi.getP2pLinkedInfo((err, data) => {   if (err) {       console.error("get p2p linked info error");       return;   }console.info("get wifi p2p linked info: " + JSON.stringify(data));});    
```    
  
    
## getCurrentGroup<sup>(deprecated)</sup>    
获取P2P当前组信息，使用Promise异步回调。  
 **调用形式：**     
- getCurrentGroup(): Promise\<WifiP2pGroupInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getCurrentGroup。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<WifiP2pGroupInfo> | Promise对象。表示当前组信息。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';wifi.getCurrentGroup().then(data => {console.info("get current P2P group: " + JSON.stringify(data));});    
```    
  
    
## getCurrentGroup<sup>(deprecated)</sup>    
获取P2P当前组信息，使用callback异步回调。  
 **调用形式：**     
- getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getCurrentGroup。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<WifiP2pGroupInfo> | true | 回调函数。当操作成功时，err为0，data表示当前组信息。如果error为非0，表示处理出现错误。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
wifi.getCurrentGroup((err, data) => {   if (err) {       console.error("get current P2P group error");       return;   }console.info("get current P2P group: " + JSON.stringify(data));});    
```    
  
    
## getP2pPeerDevices<sup>(deprecated)</sup>    
获取P2P对端设备列表信息，使用Promise异步回调。  
 **调用形式：**     
- getP2pPeerDevices(): Promise\<WifiP2pDevice[]>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getP2pPeerDevices。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<WifiP2pDevice[]> | Promise对象。表示对端设备列表信息。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';wifi.getP2pPeerDevices().then(data => {console.info("get P2P peer devices: " + JSON.stringify(data));});    
```    
  
    
## getP2pPeerDevices<sup>(deprecated)</sup>    
获取P2P对端设备列表信息，使用callback异步回调。  
 **调用形式：**     
- getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.getP2pPeerDevices。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<WifiP2pDevice[]> | true | 回调函数。当操作成功时，err为0，data表示对端设备列表信息。如果error为非0，表示处理出现错误。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
wifi.getP2pPeerDevices((err, data) => {   if (err) {       console.error("get P2P peer devices error");       return;   }console.info("get P2P peer devices: " + JSON.stringify(data));});    
```    
  
    
## createGroup<sup>(deprecated)</sup>    
创建群组。  
 **调用形式：**     
- createGroup(config: WifiP2PConfig): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.createP2pGroup。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiP2PConfig | true | 群组配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:创建群组操作执行成功，false:创建群组操作执行失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	let config:wifi.WifiP2PConfig = {  
		deviceAddress: "****",  
		netId: 0,  
		passphrase: "*****",  
		groupName: "****",  
		goBand: 0  
	}  
	wifi.createGroup(config);	  
	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## removeGroup<sup>(deprecated)</sup>    
移除群组。  
 **调用形式：**     
- removeGroup(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.removeP2pGroup。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | rue:操作执行成功，false:操作执行失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.removeGroup();	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## p2pConnect<sup>(deprecated)</sup>    
执行P2P连接。  
 **调用形式：**     
- p2pConnect(config: WifiP2PConfig): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.p2pConnect。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config<sup>(deprecated)</sup> | WifiP2PConfig | true | 连接配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作执行成功，false:操作执行失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvP2pConnectionChangeFunc = (result:wifi.WifiP2pLinkedInfo) => {    console.info("p2p connection change receive event: " + JSON.stringify(result));    wifi.getP2pLinkedInfo((err, data) => {        if (err) {            console.error('failed to get getP2pLinkedInfo: ' + JSON.stringify(err));            return;        }        console.info("get getP2pLinkedInfo: " + JSON.stringify(data));    });}wifi.on("p2pConnectionChange", recvP2pConnectionChangeFunc);  
let recvP2pDeviceChangeFunc = (result:wifi.WifiP2pDevice) => {    console.info("p2p device change receive event: " + JSON.stringify(result));}wifi.on("p2pDeviceChange", recvP2pDeviceChangeFunc);  
let recvP2pPeerDeviceChangeFunc = (result:wifi.WifiP2pDevice[]) => {    console.info("p2p peer device change receive event: " + JSON.stringify(result));    wifi.getP2pPeerDevices((err, data) => {        if (err) {            console.error('failed to get peer devices: ' + JSON.stringify(err));            return;        }        console.info("get peer devices: " + JSON.stringify(data));        let len = data.length;        for (let i = 0; i < len; ++i) {            if (data[i].deviceName === "my_test_device") {                console.info("p2p connect to test device: " + data[i].deviceAddress);                let config:wifi.WifiP2PConfig = {                    deviceAddress:data[i].deviceAddress,                    netId:-2,                    passphrase:"",                    groupName:"",                    goBand:0,                }                wifi.p2pConnect(config);            }        }    });}wifi.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);  
let recvP2pPersistentGroupChangeFunc = () => {    console.info("p2p persistent group change receive event");  
    wifi.getCurrentGroup((err, data) => {        if (err) {            console.error('failed to get current group: ' + JSON.stringify(err));            return;        }        console.info("get current group: " + JSON.stringify(data));    });}wifi.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);  
setTimeout(() => {wifi.off("p2pConnectionChange", recvP2pConnectionChangeFunc);}, 125 * 1000);setTimeout(() => {wifi.off("p2pDeviceChange", recvP2pDeviceChangeFunc);}, 125 * 1000);setTimeout(() => {wifi.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);}, 125 * 1000);setTimeout(() => {wifi.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);}, 125 * 1000);console.info("start discover devices -> " + wifi.startDiscoverDevices());    
```    
  
    
## p2pCancelConnect<sup>(deprecated)</sup>    
取消P2P连接。  
 **调用形式：**     
- p2pCancelConnect(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.p2pCancelConnect。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作执行成功，false:操作执行失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.p2pCancelConnect();	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## startDiscoverDevices<sup>(deprecated)</sup>    
开始发现设备。  
 **调用形式：**     
- startDiscoverDevices(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.startDiscoverP2pDevices。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:操作执行成功，false:操作执行失败。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.startDiscoverDevices();	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## stopDiscoverDevices<sup>(deprecated)</sup>  
 **调用形式：**     
- stopDiscoverDevices(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.stopDiscoverP2pDevices。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
  
try {  
	wifi.stopDiscoverDevices();	  
}catch(error){  
	console.error("failed:" + JSON.stringify(error));  
}  
    
```    
  
    
## on('wifiStateChange')<sup>(deprecated)</sup>    
注册WLAN状态改变事件。  
 **调用形式：**     
- on(type: 'wifiStateChange', callback: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:wifiStateChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"wifiStateChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | true | 状态改变回调函数。 |  
    
## off('wifiStateChange')<sup>(deprecated)</sup>    
取消注册WLAN状态改变事件。  
 **调用形式：**     
- off(type: 'wifiStateChange', callback?: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:wifiStateChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"wifiStateChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvPowerNotifyFunc = (result:number) => {    console.info("Receive power state change event: " + result);}  
// Register eventwifi.on("wifiStateChange", recvPowerNotifyFunc);  
// Unregister eventwifi.off("wifiStateChange", recvPowerNotifyFunc);    
```    
  
    
## on('wifiConnectionChange')<sup>(deprecated)</sup>    
注册WLAN连接状态改变事件。  
 **调用形式：**     
- on(type: 'wifiConnectionChange', callback: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:wifiConnectionChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 定填"wifiConnectionChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | true | 状态改变回调函数。 |  
    
## off('wifiConnectionChange')<sup>(deprecated)</sup>    
取消注册WLAN连接状态改变事件。  
 **调用形式：**     
- off(type: 'wifiConnectionChange', callback?: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:wifiConnectionChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"wifiConnectionChange"字符串 |  
| callback<sup>(deprecated)</sup> | Callback<number> | false | 连接状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvWifiConnectionChangeFunc = (result:number) => {    console.info("Receive wifi connection change event: " + result);}  
// Register eventwifi.on("wifiConnectionChange", recvWifiConnectionChangeFunc);  
// Unregister eventwifi.off("wifiConnectionChange", recvWifiConnectionChangeFunc);    
```    
  
    
## on('wifiScanStateChange')<sup>(deprecated)</sup>    
注册扫描状态改变事件。  
 **调用形式：**     
- on(type: 'wifiScanStateChange', callback: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:wifiScanStateChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"wifiScanStateChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | true | 状态改变回调函数。 |  
    
## off('wifiScanStateChange')<sup>(deprecated)</sup>    
取消注册扫描状态改变事件。  
 **调用形式：**     
- off(type: 'wifiScanStateChange', callback?: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:wifiScanStateChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"wifiScanStateChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvWifiScanStateChangeFunc = (result:number) => {    console.info("Receive Wifi scan state change event: " + result);}  
// Register eventwifi.on("wifiScanStateChange", recvWifiScanStateChangeFunc);  
// Unregister eventwifi.off("wifiScanStateChange", recvWifiScanStateChangeFunc);    
```    
  
    
## on('wifiRssiChange')<sup>(deprecated)</sup>    
注册RSSI状态改变事件。  
 **调用形式：**     
- on(type: 'wifiRssiChange', callback: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:wifiRssiChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"wifiRssiChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | true | 状态改变回调函数，返回以dBm为单位的RSSI值。 |  
    
## off('wifiRssiChange')<sup>(deprecated)</sup>    
取消注册RSSI状态改变事件。  
 **调用形式：**     
- off(type: 'wifiRssiChange', callback?: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:wifiRssiChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"wifiRssiChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvWifiRssiChangeFunc = (result:number) => {    console.info("Receive wifi rssi change event: " + result);}  
// Register eventwifi.on("wifiRssiChange", recvWifiRssiChangeFunc);  
// Unregister eventwifi.off("wifiRssiChange", recvWifiRssiChangeFunc);    
```    
  
    
## on('hotspotStateChange')<sup>(deprecated)</sup>    
注册热点状态改变事件。  
 **调用形式：**     
- on(type: 'hotspotStateChange', callback: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:hotspotStateChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"hotspotStateChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | true | 状态改变回调函数。 |  
    
## off('hotspotStateChange')<sup>(deprecated)</sup>    
取消注册热点状态改变事件。  
 **调用形式：**     
- off(type: 'hotspotStateChange', callback?: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:hotspotStateChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"hotspotStateChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvHotspotStateChangeFunc = (result:number) => {    console.info("Receive hotspot state change event: " + result);}  
// Register eventwifi.on("hotspotStateChange", recvHotspotStateChangeFunc);  
// Unregister eventwifi.off("hotspotStateChange", recvHotspotStateChangeFunc);    
```    
  
    
## on('p2pStateChange')<sup>(deprecated)</sup>    
注册P2P开关状态改变事件。  
 **调用形式：**     
- on(type: 'p2pStateChange', callback: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:p2pStateChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pStateChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | true | 状态改变回调函数。 |  
    
## off('p2pStateChange')<sup>(deprecated)</sup>    
取消注册P2P开关状态改变事件。  
 **调用形式：**     
- off(type: 'p2pStateChange', callback?: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:p2pStateChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pStateChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvP2pStateChangeFunc = (result:number) => {    console.info("Receive p2p state change event: " + result);}  
// Register eventwifi.on("p2pStateChange", recvP2pStateChangeFunc);  
// Unregister eventwifi.off("p2pStateChange", recvP2pStateChangeFunc);    
```    
  
    
## on('p2pConnectionChange')<sup>(deprecated)</sup>    
注册P2P连接状态改变事件。  
 **调用形式：**     
- on(type: 'p2pConnectionChange', callback: Callback\<WifiP2pLinkedInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:p2pConnectionChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pConnectionChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<WifiP2pLinkedInfo> | true | 状态改变回调函数。 |  
    
## off('p2pConnectionChange')<sup>(deprecated)</sup>    
取消注册P2P连接状态改变事件。  
 **调用形式：**     
- off(type: 'p2pConnectionChange', callback?: Callback\<WifiP2pLinkedInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:p2pConnectionChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pConnectionChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<WifiP2pLinkedInfo> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvP2pConnectionChangeFunc = (result:wifi.WifiP2pLinkedInfo) => {    console.info("Receive p2p connection change event: " + result);}  
// Register eventwifi.on("p2pConnectionChange", recvP2pConnectionChangeFunc);  
// Unregister eventwifi.off("p2pConnectionChange", recvP2pConnectionChangeFunc);    
```    
  
    
## on('p2pDeviceChange')<sup>(deprecated)</sup>    
注册P2P设备状态改变事件。  
 **调用形式：**     
- on(type: 'p2pDeviceChange', callback: Callback\<WifiP2pDevice>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:p2pDeviceChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pDeviceChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<WifiP2pDevice> | true | 状态改变回调函数。 |  
    
## off('p2pDeviceChange')<sup>(deprecated)</sup>    
取消注册P2P设备状态改变事件。  
 **调用形式：**     
- off(type: 'p2pDeviceChange', callback?: Callback\<WifiP2pDevice>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:p2pDeviceChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pDeviceChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<WifiP2pDevice> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvP2pDeviceChangeFunc = (result:wifi.WifiP2pDevice) => {    console.info("Receive p2p device change event: " + result);}  
// Register eventwifi.on("p2pDeviceChange", recvP2pDeviceChangeFunc);  
// Unregister eventwifi.off("p2pDeviceChange", recvP2pDeviceChangeFunc);    
```    
  
    
## on('p2pPeerDeviceChange')<sup>(deprecated)</sup>    
注册P2P对端设备状态改变事件。  
 **调用形式：**     
- on(type: 'p2pPeerDeviceChange', callback: Callback\<WifiP2pDevice[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:p2pPeerDeviceChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pPeerDeviceChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<WifiP2pDevice[]> | true | 状态改变回调函数。 |  
    
## off('p2pPeerDeviceChange')<sup>(deprecated)</sup>    
取消注册P2P对端设备状态改变事件。  
 **调用形式：**     
- off(type: 'p2pPeerDeviceChange', callback?: Callback\<WifiP2pDevice[]>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:p2pPeerDeviceChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pPeerDeviceChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<WifiP2pDevice[]> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvP2pPeerDeviceChangeFunc = (result:wifi.WifiP2pDevice[]) => {    console.info("Receive p2p peer device change event: " + result);}  
// Register eventwifi.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);  
// Unregister eventwifi.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);    
```    
  
    
## on('p2pPersistentGroupChange')<sup>(deprecated)</sup>    
注册P2P永久组状态改变事件。  
 **调用形式：**     
- on(type: 'p2pPersistentGroupChange', callback: Callback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:p2pPersistentGroupChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pPersistentGroupChange"字符串 |  
| callback<sup>(deprecated)</sup> | Callback<void> | true | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
## off('p2pPersistentGroupChange')<sup>(deprecated)</sup>    
取消注册P2P永久组状态改变事件。  
 **调用形式：**     
- off(type: 'p2pPersistentGroupChange', callback?: Callback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:p2pPersistentGroupChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pPersistentGroupChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<void> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvP2pPersistentGroupChangeFunc = (result:void) => {    console.info("Receive p2p persistent group change event: " + result);}  
// Register eventwifi.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);  
// Unregister eventwifi.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);    
```    
  
    
## on('p2pDiscoveryChange')<sup>(deprecated)</sup>    
注册发现设备状态改变事件。  
 **调用形式：**     
- on(type: 'p2pDiscoveryChange', callback: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.on#event:p2pDiscoveryChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pDiscoveryChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | true | 状态改变回调函数。 |  
    
## off('p2pDiscoveryChange')<sup>(deprecated)</sup>    
取消注册发现设备状态改变事件。  
 **调用形式：**     
- off(type: 'p2pDiscoveryChange', callback?: Callback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManager/wifiManager.off#event:p2pDiscoveryChange。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 固定填"p2pDiscoveryChange"字符串。 |  
| callback<sup>(deprecated)</sup> | Callback<number> | false | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
 **示例代码：**   
```ts    
import wifi from '@ohos.wifi';  
let recvP2pDiscoveryChangeFunc = (result:number) => {    console.info("Receive p2p discovery change event: " + result);}  
// Register eventwifi.on("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);  
// Unregister eventwifi.off("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);    
```    
  
    
## WifiDeviceConfig<sup>(deprecated)</sup>    
WLAN配置信息。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.WifiDeviceConfig替代。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点的SSID，编码格式为UTF-8。 |  
| bssid<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点的BSSID。 |  
| preSharedKey<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点的密钥。 |  
| isHiddenSsid<sup>(deprecated)</sup> | boolean | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>是否是隐藏网络。 |  
| securityType<sup>(deprecated)</sup> | WifiSecurityType | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>加密类型。 |  
| creatorUid<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>创建用户的ID。 <br /> **系统接口：** 此接口为系统接口。 |  
| disableReason<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>禁用原因。 <br /> **系统接口：** 此接口为系统接口。 |  
| netId<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>分配的网络ID。 <br /> **系统接口：** 此接口为系统接口。 |  
| randomMacType<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>随机MAC类型。 <br /> **系统接口：** 此接口为系统接口。 |  
| randomMacAddr<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>随机MAC地址。 <br /> **系统接口：** 此接口为系统接口。 |  
| ipType<sup>(deprecated)</sup> | IpType | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>IP地址类型。 <br /> **系统接口：** 此接口为系统接口。 |  
| staticIp<sup>(deprecated)</sup> | IpConfig | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>静态IP配置信息。 <br /> **系统接口：** 此接口为系统接口。 |  
    
## WifiScanInfo<sup>(deprecated)</sup>    
WLAN热点信息。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.WifiScanInfo替代。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点的SSID，编码格式为UTF-8。 |  
| bssid<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点的BSSID。 |  
| capabilities<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点能力。 |  
| securityType<sup>(deprecated)</sup> | WifiSecurityType | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN加密类型。 |  
| rssi<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点的信号强度(dBm)。 |  
| band<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN接入点的频段。 |  
| frequency<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN接入点的频率。 |  
| channelWidth<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN接入点的带宽。 |  
| timestamp<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>时间戳。 |  
    
## WifiSecurityType<sup>(deprecated)</sup>    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.WifiSecurityType替代。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WIFI_SEC_TYPE_INVALID<sup>(deprecated)</sup> | 0 | 从API version 6 开始支持，从API version 9 开始废弃。<br>无效加密类型。 |  
| WIFI_SEC_TYPE_OPEN<sup>(deprecated)</sup> | 1 | 从API version 6 开始支持，从API version 9 开始废弃。<br>开放加密类型。 |  
| WIFI_SEC_TYPE_WEP<sup>(deprecated)</sup> | 2 | 从API version 6 开始支持，从API version 9 开始废弃。<br>WiredEquivalentPrivacy(WEP)加密类型。 |  
| WIFI_SEC_TYPE_PSK<sup>(deprecated)</sup> | 3 | 从API version 6 开始支持，从API version 9 开始废弃。<br>Pre-sharedkey(PSK)加密类型。 |  
| WIFI_SEC_TYPE_SAE<sup>(deprecated)</sup> | 4 | 从API version 6 开始支持，从API version 9 开始废弃。<br>imultaneousAuthenticationofEquals(SAE)加密类型。 |  
    
## WifiLinkedInfo<sup>(deprecated)</sup>    
提供WLAN连接的相关信息。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.WifiLinkedInfo替代。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点的SSID，编码格式为UTF-8。 |  
| bssid<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点的BSSID。 |  
| networkId<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>网络配置ID。 <br /> **系统接口：** 此接口为系统接口。 |  
| rssi<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>热点的信号强度(dBm)。 |  
| band<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN接入点的频段。 |  
| linkSpeed<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN接入点的速度。 |  
| frequency<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN接入点的频率。 |  
| isHidden<sup>(deprecated)</sup> | boolean | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN接入点是否是隐藏网络。 |  
| isRestricted<sup>(deprecated)</sup> | boolean | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN接入点是否限制数据量。 |  
| chload<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>连接负载，值越大表示负载约高。 <br /> **系统接口：** 此接口为系统接口。 |  
| snr<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>信噪比。 <br /> **系统接口：** 此接口为系统接口。 |  
| macAddress<sup>(deprecated)</sup> | string | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>设备的MAC地址。 |  
| ipAddress<sup>(deprecated)</sup> | number | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN连接的IP地址。 |  
| suppState<sup>(deprecated)</sup> | SuppState | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>请求状态。 <br /> **系统接口：** 此接口为系统接口。 |  
| connState<sup>(deprecated)</sup> | ConnState | false | true | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN连接状态。 |  
    
## IpInfo<sup>(deprecated)</sup>    
IP信息。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.IpInfo替代。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ipAddress<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>IP地址。 |  
| gateway<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>网关。 |  
| netmask<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>掩码。 |  
| primaryDns<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>主DNS服务器IP地址。 |  
| secondDns<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>备DNS服务器IP地址。 |  
| serverIp<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>DHCP服务端IP地址。 |  
| leaseDuration<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>IP地址租用时长。 |  
    
## ConnState<sup>(deprecated)</sup>    
表示WLAN连接状态的枚举。    
从API version 6 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.ConnState替代。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SCANNING<sup>(deprecated)</sup> | 0 | 从API version 6 开始支持，从API version 9 开始废弃。<br>设备正在搜索可用的AP。 |  
| CONNECTING<sup>(deprecated)</sup> | 1 | 从API version 6 开始支持，从API version 9 开始废弃。<br>正在建立WLAN连接。 |  
| AUTHENTICATING<sup>(deprecated)</sup> | 2 | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN连接正在认证中。 |  
| OBTAINING_IPADDR<sup>(deprecated)</sup> | 3 | 从API version 6 开始支持，从API version 9 开始废弃。<br>正在获取WLAN连接的IP地址。 |  
| CONNECTED<sup>(deprecated)</sup> | 4 | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN连接已建立。 |  
| DISCONNECTING<sup>(deprecated)</sup> | 5 | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN连接正在断开。 |  
| DISCONNECTED<sup>(deprecated)</sup> | 6 | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN连接已断开。 |  
| UNKNOWN<sup>(deprecated)</sup> | 7 | 从API version 6 开始支持，从API version 9 开始废弃。<br>WLAN连接建立失败。 |  
    
## WifiP2pDevice<sup>(deprecated)</sup>    
表示P2P设备信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.WifiP2pDevice替代。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备名称。 |  
| deviceAddress<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备MAC地址。 |  
| primaryDeviceType<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>主设备类型。 |  
| deviceStatus<sup>(deprecated)</sup> | P2pDeviceStatus | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备状态。 |  
| groupCapabilitys<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组能力。 |  
    
## WifiP2PConfig<sup>(deprecated)</sup>    
表示P2P配置信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.WifiP2PConfig替代。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceAddress<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>设备地址。 |  
| netId<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>网络ID。创建群组时-1表示创建临时组，-2表示创建永久组。 |  
| passphrase<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组密钥。 |  
| groupName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组名称。 |  
| goBand<sup>(deprecated)</sup> | GroupOwnerBand | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组带宽。 |  
    
## WifiP2pGroupInfo<sup>(deprecated)</sup>    
表示P2P群组相关信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.WifiP2pGroupInfo替代。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isP2pGo<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>是否是群主。 |  
| ownerInfo<sup>(deprecated)</sup> | WifiP2pDevice | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组的设备信息。 |  
| passphrase<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组密钥。 |  
| interface<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>接口名称。 |  
| groupName<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组名称。 |  
| networkId<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>网络ID。 |  
| frequency<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组的频率。 |  
| clientDevices<sup>(deprecated)</sup> | WifiP2pDevice[] | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>接入的设备列表信息。 |  
| goIpAddress<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组IP地址。 |  
    
## P2pConnectState<sup>(deprecated)</sup>    
表示P2P连接状态的枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.P2pConnectState替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DISCONNECTED | 0 | 断开状态。 |  
| CONNECTED | 1 | 连接状态。 |  
    
## WifiP2pLinkedInfo<sup>(deprecated)</sup>    
提供WLAN连接的相关信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.WifiP2pLinkedInfo替代。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| connectState<sup>(deprecated)</sup> | P2pConnectState | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>P2P连接状态。 |  
| isGroupOwner<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>是否是群主。 |  
| groupOwnerAddr<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>群组MAC地址。 |  
    
## P2pDeviceStatus<sup>(deprecated)</sup>    
表示设备状态的枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.P2pDeviceStatus替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CONNECTED | 0 | 连接状态。 |  
| INVITED | 1 | 邀请状态。 |  
| FAILED | 2 | 失败状态。 |  
| AVAILABLE | 3 | 可用状态。 |  
| UNAVAILABLE | 4 | 不可用状态。 |  
    
## GroupOwnerBand<sup>(deprecated)</sup>    
表示群组带宽的枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManager/wifiManager.GroupOwnerBand替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| GO_BAND_AUTO | 0 | 自动模式。 |  
| GO_BAND_2GHZ | 1 | 2GHZ。 |  
| GO_BAND_5GHZ | 2 | 5GHZ。 |  
