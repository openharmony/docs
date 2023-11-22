# @ohos.wifiManager    
该模块主要提供WLAN基础功能、P2P（peer-to-peer）功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wifiManager from '@ohos.wifiManager'    
```  
    
## isWifiActive    
查询WLAN是否已使能。  
 **调用形式：**     
- isWifiActive(): boolean  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:已使能，false:未使能。 |  
    
    
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
		let isWifiActive = wifiManager.isWifiActive();  
		console.info("isWifiActive:" + isWifiActive);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## scan<sup>(deprecated)</sup>    
启动WLAN扫描。  
 **调用形式：**     
- scan(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: wifiManager.startScan。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
    
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
		wifiManager.scan();  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getScanResults<sup>(deprecated)</sup>    
获取扫描结果，使用Promise异步回调。  
 **调用形式：**     
- getScanResults(): Promise\<Array\<WifiScanInfo>>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: wifiManager.getScanInfoList。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<WifiScanInfo>> | Promise对象。返回扫描到的热点列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    wifiManager.getScanResults((err, result) => {      if (err) {          console.error("get scan info error");          return;      }        let len = result.length;      console.log("wifi received scan info: " + len);      for (let i = 0; i < len; ++i) {          console.info("ssid: " + result[i].ssid);          console.info("bssid: " + result[i].bssid);          console.info("capabilities: " + result[i].capabilities);          console.info("securityType: " + result[i].securityType);          console.info("rssi: " + result[i].rssi);          console.info("band: " + result[i].band);          console.info("frequency: " + result[i].frequency);          console.info("channelWidth: " + result[i].channelWidth);          console.info("timestamp: " + result[i].timestamp);      }  });    wifiManager.getScanResults().then(result => {      let len = result.length;      console.log("wifi received scan info: " + len);      for (let i = 0; i < len; ++i) {          console.info("ssid: " + result[i].ssid);          console.info("bssid: " + result[i].bssid);          console.info("capabilities: " + result[i].capabilities);          console.info("securityType: " + result[i].securityType);          console.info("rssi: " + result[i].rssi);          console.info("band: " + result[i].band);          console.info("frequency: " + result[i].frequency);          console.info("channelWidth: " + result[i].channelWidth);          console.info("timestamp: " + result[i].timestamp);      }  });    
```    
  
    
## getScanResults<sup>(deprecated)</sup>    
获取扫描结果，使用同步方式返回结果。  
 **调用形式：**     
- getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: wifiManager.getScanInfoList。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<WifiScanInfo>> | true | 回调函数。当成功时，err为0，data为扫描到的热点；否则err为非0值，data为空。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
## getScanResultsSync<sup>(deprecated)</sup>    
获取扫描结果，使用同步方式返回结果。  
 **调用形式：**     
- getScanResultsSync(): Array\<WifiScanInfo>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: wifiManager.getScanInfoList。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WifiScanInfo> | 扫描结果数组。 |  
    
    
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
		let scanInfoList = wifiManager.getScanResultsSync();  
		console.info("scanInfoList:" + JSON.stringify(scanInfoList));  
		let len = scanInfoList.length;  
        console.log("wifi received scan info: " + len);  
		if(len > 0){  
			for (let i = 0; i < len; ++i) {  
				console.info("ssid: " + scanInfoList[i].ssid);  
				console.info("bssid: " + scanInfoList[i].bssid);  
				console.info("capabilities: " + scanInfoList[i].capabilities);  
				console.info("securityType: " + scanInfoList[i].securityType);  
				console.info("rssi: " + scanInfoList[i].rssi);  
				console.info("band: " + scanInfoList[i].band);  
				console.info("frequency: " + scanInfoList[i].frequency);  
				console.info("channelWidth: " + scanInfoList[i].channelWidth);  
				console.info("timestamp: " + scanInfoList[i].timestamp);  
			}  
		}	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getScanInfoList<sup>(10+)</sup>    
获取扫描结果。  
 **调用形式：**     
- getScanInfoList(): Array\<WifiScanInfo>  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WifiScanInfo> | 返回扫描到的热点列表。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的bssid为真实设备地址，否则为随机设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2501000 |  |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let scanInfoList = wifiManager.getScanInfoList();  
		console.info("scanInfoList:" + JSON.stringify(scanInfoList));  
		let len = scanInfoList.length;  
        console.log("wifi received scan info: " + len);  
		if(len > 0){  
			for (let i = 0; i < len; ++i) {  
				console.info("ssid: " + scanInfoList[i].ssid);  
				console.info("bssid: " + scanInfoList[i].bssid);  
				console.info("capabilities: " + scanInfoList[i].capabilities);  
				console.info("securityType: " + scanInfoList[i].securityType);  
				console.info("rssi: " + scanInfoList[i].rssi);  
				console.info("band: " + scanInfoList[i].band);  
				console.info("frequency: " + scanInfoList[i].frequency);  
				console.info("channelWidth: " + scanInfoList[i].channelWidth);  
				console.info("timestamp: " + scanInfoList[i].timestamp);  
			}  
		}	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## addCandidateConfig    
添加候选网络配置，使用Promise异步回调。  
 **调用形式：**     
    
- addCandidateConfig(config: WifiDeviceConfig): Promise\<number>    
起始版本： 9    
- addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | WifiDeviceConfig | true | WLAN配置信息。如果bssidType未指定值，则bssidType默认为随机设备地址类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<number> | Promise对象。表示网络配置ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
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
		wifiManager.addCandidateConfig(config).then(result => {  
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
		wifiManager.addCandidateConfig(config,(error,result) => {  
			console.info("result:" + JSON.stringify(result));  
		});	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## removeCandidateConfig    
移除候选网络配置，使用Promise异步回调。  
 **调用形式：**     
    
- removeCandidateConfig(networkId: number): Promise\<void>    
起始版本： 9    
- removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| networkId | number | true | 网络配置ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当操作成功时，err为0。如果error为非0，表示处理出现错误。 |  
| Promise<void> | Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码1：**   
示例(Promise):  
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let networkId = 0;  
		wifiManager.removeCandidateConfig(networkId).then(result => {  
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
		let networkId = 0;  
		wifiManager.removeCandidateConfig(networkId,(error,result) => {  
		console.info("result:" + JSON.stringify(result));  
		});	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getCandidateConfigs    
获取候选网络配置。  
 **调用形式：**     
- getCandidateConfigs(): Array\<WifiDeviceConfig>  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WifiDeviceConfig> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2501000 |  |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let configs = wifiManager.getCandidateConfigs();  
		console.info("configs:" + JSON.stringify(configs));  
		let len = configs.length;  
        console.log("result len: " + len);  
		if(len > 0){  
			for (let i = 0; i < len; ++i) {  
				console.info("ssid: " + configs[i].ssid);  
				console.info("bssid: " + configs[i].bssid);  
			}  
		}	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getCandidateConfigs<sup>(10+)</sup>  
 **调用形式：**     
- getCandidateConfigs(): Array\<WifiDeviceConfig>  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WifiDeviceConfig> | 候选网络配置数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
## connectToCandidateConfig    
应用使用该接口连接到自己添加的候选网络（如果当前已经连接到热点，需要先断开连接）。  
 **调用形式：**     
- connectToCandidateConfig(networkId: number): void  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.SET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| networkId | number | true | 候选网络配置的ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
| 2501001 | Wifi is closed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let networkId = 0;  
		let ret = wifiManager.connectToCandidateConfig(networkId);  
		console.info("result:" + ret);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getSignalLevel    
查询WLAN信号强度。  
 **调用形式：**     
- getSignalLevel(rssi: number, band: number): number  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rssi | number | true | 热点的信号强度(dBm)。 |  
| band | number | true | WLAN接入点的频段。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 信号强度，取值范围为[0,4] |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let rssi = 0;  
		let band = 0;  
		let level = wifiManager.getSignalLevel(rssi,band);  
		console.info("level:" + JSON.stringify(level));  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getLinkedInfo    
获取WLAN连接信息，使用Promise异步回调。  
 **调用形式：**     
    
- getLinkedInfo(): Promise\<WifiLinkedInfo>    
起始版本： 9    
- getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取成功时，err为0，data表示WLAN连接信息。如果error为非0，表示处理出现错误。 |  
| Promise<WifiLinkedInfo> | Promise对象。表示WLAN连接信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
| 2501001 | Wifi is closed. |  
    
 **示例代码：**   
示例(callback):  
```ts    
import wifiManager from '@ohos.wifiManager';    wifiManager.getLinkedInfo((err, data) => {      if (err) {          console.error("get linked info error");          return;      }      console.info("get wifi linked info: " + JSON.stringify(data));  });    wifiManager.getLinkedInfo().then(data => {      console.info("get wifi linked info: " + JSON.stringify(data));  }).catch((error:number) => {      console.info("get linked info error");  });    
```    
  
    
## isConnected    
查询WLAN是否已连接。  
 **调用形式：**     
- isConnected(): boolean  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:已连接，false:未连接。 |  
    
    
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
		let ret = wifiManager.isConnected();  
		console.info("isConnected:" + ret);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## isFeatureSupported    
判断设备是否支持相关WLAN特性。  
 **调用形式：**     
- isFeatureSupported(featureId: number): boolean  
  
 **系统能力:**  SystemCapability.Communication.WiFi.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| featureId | number | true | 特性ID值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | rue:支持，false:不支持。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2401000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let featureId = 0;  
		let ret = wifiManager.isFeatureSupported(featureId);  
		console.info("isFeatureSupported:" + ret);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getIpInfo    
获取IP信息。  
 **调用形式：**     
- getIpInfo(): IpInfo  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IpInfo | IP信息。 |  
    
    
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
		let info = wifiManager.getIpInfo();  
		console.info("info:" + JSON.stringify(info));  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getIpv6Info<sup>(10+)</sup>    
获取IP信息。  
 **调用形式：**     
- getIpv6Info(): Ipv6Info  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Ipv6Info | Ipv6信息。 |  
    
    
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
		let info = wifiManager.getIpv6Info();  
		console.info("info:" + JSON.stringify(info));  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getCountryCode    
获取国家码信息。  
 **调用形式：**     
- getCountryCode(): string  
  
 **系统能力:**  SystemCapability.Communication.WiFi.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 国家码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2401000 | peration failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let code = wifiManager.getCountryCode();  
		console.info("code:" + code);  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## isBandTypeSupported<sup>(10+)</sup>    
判断当前频段是否支持。  
 **调用形式：**     
- isBandTypeSupported(bandType: WifiBandType): boolean  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bandType | WifiBandType | true | Wifi 频段类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true:支持，false:不支持。 |  
    
    
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
		let type = 0;  
		let isBandTypeSupported = wifiManager.isBandTypeSupported(type);  
		console.info("isBandTypeSupported:" + isBandTypeSupported);		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## getP2pLinkedInfo    
获取P2P连接信息，使用Promise异步回调。  
 **调用形式：**     
    
- getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>    
起始版本： 9    
- getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<WifiP2pLinkedInfo> | Promise对象。表示P2P连接信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
示例(Promise):  
```ts    
import wifiManager from '@ohos.wifiManager';  
wifiManager.getP2pLinkedInfo((err, data) => {    if (err) {        console.error("get p2p linked info error");        return;    }console.info("get wifi p2p linked info: " + JSON.stringify(data));});  
wifiManager.getP2pLinkedInfo().then(data => {console.info("get wifi p2p linked info: " + JSON.stringify(data));});    
```    
  
    
## getCurrentGroup    
获取P2P当前组信息，使用Promise异步回调。  
 **调用形式：**     
    
- getCurrentGroup(): Promise\<WifiP2pGroupInfo>    
起始版本： 9    
- getCurrentGroup(): Promise\<WifiP2pGroupInfo>    
起始版本： 10    
- getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void    
起始版本： 9    
- getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |  
| Promise<WifiP2pGroupInfo> | GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
示例(callback):  
```ts    
import wifiManager from '@ohos.wifiManager';  
wifiManager.getCurrentGroup((err, data) => {    if (err) {        console.error("get current P2P group error");        return;    }console.info("get current P2P group: " + JSON.stringify(data));});  
wifiManager.getCurrentGroup().then(data => {console.info("get current P2P group: " + JSON.stringify(data));});    
```    
  
    
## getP2pPeerDevices    
获取P2P对端设备列表信息，使用Promise异步回调。  
 **调用形式：**     
    
- getP2pPeerDevices(): Promise\<WifiP2pDevice[]>    
起始版本： 9    
- getP2pPeerDevices(): Promise\<WifiP2pDevice[]>    
起始版本： 10    
- getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void    
起始版本： 9    
- getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当操作成功时，err为0，data表示对端设备列表信息。如果error为非0，表示处理出现错误。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |  
| Promise<WifiP2pDevice[]> | Promise对象。表示对端设备列表信息。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
wifiManager.getP2pPeerDevices((err, data) => {    if (err) {        console.error("get P2P peer devices error");        return;    }console.info("get P2P peer devices: " + JSON.stringify(data));});  
wifiManager.getP2pPeerDevices().then(data => {console.info("get P2P peer devices: " + JSON.stringify(data));});    
```    
  
    
## getP2pLocalDevice    
获取P2P本端设备信息，使用Promise异步回调。  
 **调用形式：**     
    
- getP2pLocalDevice(): Promise\<WifiP2pDevice>    
起始版本： 9    
- getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当操作成功时，err为0，data表示本端设备信息。如果error为非0，表示处理出现错误。 |  
| Promise<WifiP2pDevice> | Promise对象。表示本端设备信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
wifiManager.getP2pLocalDevice((err, data) => {    if (err) {        console.error("get P2P local device error");        return;    }console.info("get P2P local device: " + JSON.stringify(data));});  
wifiManager.getP2pLocalDevice().then(data => {console.info("get P2P local device: " + JSON.stringify(data));});    
```    
  
    
## createGroup    
创建群组。  
 **调用形式：**     
- createGroup(config: WifiP2PConfig): void  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | WifiP2PConfig | true | 群组配置信息。如果DeviceAddressType未指定值，则DeviceAddressType默认为随机设备地址类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		let config:wifiManager.WifiP2PConfig = {  
			deviceAddress: "****",  
			netId: 0,  
			passphrase: "*****",  
			groupName: "****",  
			goBand: 0  
		}  
		wifiManager.createGroup(config);	  
		  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## removeGroup    
移除群组。  
 **调用形式：**     
- removeGroup(): void  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.removeGroup();	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## p2pConnect    
执行P2P连接。  
 **调用形式：**     
- p2pConnect(config: WifiP2PConfig): void  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | WifiP2PConfig | true | 连接配置信息。如果DeviceAddressType未指定值，则DeviceAddressType默认为随机设备地址类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvP2pConnectionChangeFunc = (result:wifiManager.WifiP2pLinkedInfo) => {      console.info("p2p connection change receive event: " + JSON.stringify(result));      wifiManager.getP2pLinkedInfo((err, data) => {          if (err) {              console.error('failed to get getP2pLinkedInfo: ' + JSON.stringify(err));              return;          }          console.info("get getP2pLinkedInfo: " + JSON.stringify(data));      });  }  wifiManager.on("p2pConnectionChange", recvP2pConnectionChangeFunc);    let recvP2pDeviceChangeFunc = (result:wifiManager.WifiP2pDevice) => {      console.info("p2p device change receive event: " + JSON.stringify(result));  }  wifiManager.on("p2pDeviceChange", recvP2pDeviceChangeFunc);    let recvP2pPeerDeviceChangeFunc = (result:wifiManager.WifiP2pDevice[]) => {      console.info("p2p peer device change receive event: " + JSON.stringify(result));      wifiManager.getP2pPeerDevices((err, data) => {          if (err) {              console.error('failed to get peer devices: ' + JSON.stringify(err));              return;          }          console.info("get peer devices: " + JSON.stringify(data));          let len = data.length;          for (let i = 0; i < len; ++i) {              if (data[i].deviceName === "my_test_device") {                  console.info("p2p connect to test device: " + data[i].deviceAddress);                  let config:wifiManager.WifiP2PConfig = {                      deviceAddress:data[i].deviceAddress,                      netId:-2,                      passphrase:"",                      groupName:"",                      goBand:0,                  }                  wifiManager.p2pConnect(config);              }          }      });  }  wifiManager.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);    let recvP2pPersistentGroupChangeFunc = () => {      console.info("p2p persistent group change receive event");        wifiManager.getCurrentGroup((err, data) => {          if (err) {              console.error('failed to get current group: ' + JSON.stringify(err));              return;          }          console.info("get current group: " + JSON.stringify(data));      });  }  wifiManager.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);    setTimeout(() => {wifiManager.off("p2pConnectionChange", recvP2pConnectionChangeFunc);}, 125 * 1000);  setTimeout(() =>  {wifiManager.off("p2pDeviceChange", recvP2pDeviceChangeFunc);}, 125 * 1000);  setTimeout(() =>  {wifiManager.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);}, 125 * 1000);  setTimeout(() =>  {wifiManager.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);}, 125 * 1000);  console.info("start discover devices -> " + wifiManager.startDiscoverDevices());    
```    
  
    
## p2pConnect<sup>(10+)</sup>  
 **调用形式：**     
- p2pConnect(config: WifiP2PConfig): void  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| config | WifiP2PConfig | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 |  |  
    
## p2pCancelConnect    
取消P2P连接。  
 **调用形式：**     
- p2pCancelConnect(): void  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.p2pCancelConnect();	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## startDiscoverDevices    
开始发现设备。  
 **调用形式：**     
- startDiscoverDevices(): void  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.startDiscoverDevices();	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## startDiscoverDevices<sup>(10+)</sup>  
 **调用形式：**     
- startDiscoverDevices(): void  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2801000 |  |  
    
## stopDiscoverDevices    
停止发现设备。  
 **调用形式：**     
- stopDiscoverDevices(): void  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';  
  
	try {  
		wifiManager.stopDiscoverDevices();	  
	}catch(error){  
		console.error("failed:" + JSON.stringify(error));  
	}  
    
```    
  
    
## on('wifiStateChange')    
注册WLAN状态改变事件。  
 **调用形式：**     
    
- on(type: 'wifiStateChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"wifiStateChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
## off('wifiStateChange')    
取消注册WLAN状态改变事件。  
 **调用形式：**     
    
- off(type: 'wifiStateChange', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"wifiStateChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvPowerNotifyFunc = (result:number) => {      console.info("Receive power state change event: " + result);  }    // Register event  wifiManager.on("wifiStateChange", recvPowerNotifyFunc);    // Unregister event  wifiManager.off("wifiStateChange", recvPowerNotifyFunc);    
```    
  
    
## on('wifiConnectionChange')    
注册WLAN连接状态改变事件。  
 **调用形式：**     
    
- on(type: 'wifiConnectionChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"wifiConnectionChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
## off('wifiConnectionChange')    
取消注册WLAN连接状态改变事件。  
 **调用形式：**     
    
- off(type: 'wifiConnectionChange', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"wifiConnectionChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 连接状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | peration failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvWifiConnectionChangeFunc = (result:number) => {      console.info("Receive wifi connection change event: " + result);  }    // Register event  wifiManager.on("wifiConnectionChange", recvWifiConnectionChangeFunc);    // Unregister event  wifiManager.off("wifiConnectionChange", recvWifiConnectionChangeFunc);    
```    
  
    
## on('wifiScanStateChange')    
注册扫描状态改变事件。  
 **调用形式：**     
    
- on(type: 'wifiScanStateChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"wifiScanStateChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
## off('wifiScanStateChange')  
 **调用形式：**     
    
- off(type: 'wifiScanStateChange', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"wifiScanStateChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 |  |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvWifiScanStateChangeFunc = (result:number) => {      console.info("Receive Wifi scan state change event: " + result);  }    // Register event  wifiManager.on("wifiScanStateChange", recvWifiScanStateChangeFunc);    // Unregister event  wifiManager.off("wifiScanStateChange", recvWifiScanStateChangeFunc);    
```    
  
    
## on('wifiRssiChange')    
注册RSSI状态改变事件。  
 **调用形式：**     
    
- on(type: 'wifiRssiChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"wifiRssiChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数，返回以dBm为单位的RSSI值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
## off('wifiRssiChange')    
取消注册RSSI状态改变事件。  
 **调用形式：**     
    
- off(type: 'wifiRssiChange', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.STA  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"wifiRssiChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2501000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvWifiRssiChangeFunc = (result:number) => {      console.info("Receive wifi rssi change event: " + result);  }    // Register event  wifiManager.on("wifiRssiChange", recvWifiRssiChangeFunc);    // Unregister event  wifiManager.off("wifiRssiChange", recvWifiRssiChangeFunc);    
```    
  
    
## on('hotspotStateChange')    
注册热点状态改变事件。  
 **调用形式：**     
    
- on(type: 'hotspotStateChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"hotspotStateChange"字符串。 |  
    
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
| 2601000 | peration failed. |  
    
## off('hotspotStateChange')    
取消注册热点状态改变事件。  
 **调用形式：**     
    
- off(type: 'hotspotStateChange', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Core  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"hotspotStateChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
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
import wifiManager from '@ohos.wifiManager';    let recvHotspotStateChangeFunc = (result:number) => {      console.info("Receive hotspot state change event: " + result);  }    // Register event  wifiManager.on("hotspotStateChange", recvHotspotStateChangeFunc);    // Unregister event  wifiManager.off("hotspotStateChange", recvHotspotStateChangeFunc);    
```    
  
    
## on('p2pStateChange')    
注册P2P开关状态改变事件。  
 **调用形式：**     
    
- on(type: 'p2pStateChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pStateChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 |  |  
    
## off('p2pStateChange')    
取消注册P2P开关状态改变事件。  
 **调用形式：**     
    
- off(type: 'p2pStateChange', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pStateChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvP2pStateChangeFunc = (result:number) => {      console.info("Receive p2p state change event: " + result);  }    // Register event  wifiManager.on("p2pStateChange", recvP2pStateChangeFunc);    // Unregister event  wifiManager.off("p2pStateChange", recvP2pStateChangeFunc);    
```    
  
    
## on('p2pConnectionChange')    
注册P2P连接状态改变事件。  
 **调用形式：**     
    
- on(type: 'p2pConnectionChange', callback: Callback\<WifiP2pLinkedInfo>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pConnectionChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | eration failed. |  
    
## off('p2pConnectionChange')    
取消注册P2P连接状态改变事件。  
 **调用形式：**     
    
- off(type: 'p2pConnectionChange', callback?: Callback\<WifiP2pLinkedInfo>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pConnectionChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvP2pConnectionChangeFunc = (result:wifiManager.WifiP2pLinkedInfo) => {      console.info("Receive p2p connection change event: " + result);  }    // Register event  wifiManager.on("p2pConnectionChange", recvP2pConnectionChangeFunc);    // Unregister event  wifiManager.off("p2pConnectionChange", recvP2pConnectionChangeFunc);    
```    
  
    
## on('p2pDeviceChange')    
注册P2P设备状态改变事件。  
 **调用形式：**     
    
- on(type: 'p2pDeviceChange', callback: Callback\<WifiP2pDevice>): void    
起始版本： 9    
- on(type: 'p2pDeviceChange', callback: Callback\<WifiP2pDevice>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pDeviceChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
## off('p2pDeviceChange')    
取消注册P2P设备状态改变事件。  
 **调用形式：**     
    
- off(type: 'p2pDeviceChange', callback?: Callback\<WifiP2pDevice>): void    
起始版本： 9    
- off(type: 'p2pDeviceChange', callback?: Callback\<WifiP2pDevice>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pDeviceChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvP2pDeviceChangeFunc = (result:wifiManager.WifiP2pDevice) => {      console.info("Receive p2p device change event: " + result);  }    // Register event  wifiManager.on("p2pDeviceChange", recvP2pDeviceChangeFunc);    // Unregister event  wifiManager.off("p2pDeviceChange", recvP2pDeviceChangeFunc);    
```    
  
    
## on('p2pPeerDeviceChange')    
注册P2P对端设备状态改变事件。  
 **调用形式：**     
    
- on(type: 'p2pPeerDeviceChange', callback: Callback\<WifiP2pDevice[]>): void    
起始版本： 9    
- on(type: 'p2pPeerDeviceChange', callback: Callback\<WifiP2pDevice[]>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pPeerDeviceChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
## off('p2pPeerDeviceChange')    
取消注册P2P对端设备状态改变事件。  
 **调用形式：**     
    
- off(type: 'p2pPeerDeviceChange', callback?: Callback\<WifiP2pDevice[]>): void    
起始版本： 9    
- off(type: 'p2pPeerDeviceChange', callback?: Callback\<WifiP2pDevice[]>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pPeerDeviceChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvP2pPeerDeviceChangeFunc = (result:wifiManager.WifiP2pDevice[]) => {      console.info("Receive p2p peer device change event: " + result);  }    // Register event  wifiManager.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);    // Unregister event  wifiManager.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);    
```    
  
    
## on('p2pPersistentGroupChange')    
注册P2P永久组状态改变事件。  
 **调用形式：**     
    
- on(type: 'p2pPersistentGroupChange', callback: Callback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pPersistentGroupChange"字符串 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
## off('p2pPersistentGroupChange')    
取消注册P2P永久组状态改变事件。  
 **调用形式：**     
    
- off(type: 'p2pPersistentGroupChange', callback?: Callback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pPersistentGroupChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvP2pPersistentGroupChangeFunc = (result:void) => {      console.info("Receive p2p persistent group change event: " + result);  }    // Register event  wifiManager.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);    // Unregister event  wifiManager.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);    
```    
  
    
## on('p2pDiscoveryChange')    
注册发现设备状态改变事件。  
 **调用形式：**     
    
- on(type: 'p2pDiscoveryChange', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pDiscoveryChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
## off('p2pDiscoveryChange')    
取消注册发现设备状态改变事件。  
 **调用形式：**     
    
- off(type: 'p2pDiscoveryChange', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 固定填"p2pDiscoveryChange"字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2801000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManager from '@ohos.wifiManager';    let recvP2pDiscoveryChangeFunc = (result:number) => {      console.info("Receive p2p discovery change event: " + result);  }    // Register event  wifiManager.on("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);    // Unregister event  wifiManager.off("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);    
```    
  
    
## DeviceAddressType<sup>(10+)</sup>    
wifi 设备地址（mac/bssid）类型。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| RANDOM_DEVICE_ADDRESS | 0 | 随机设备地址。 |  
| REAL_DEVICE_ADDRESS | 1 | | REAL_DEVICE_ADDRESS | 1 | 真实设备地址。 | |  
    
## EapMethod<sup>(10+)</sup>    
表示EAP认证方式的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| EAP_NONE | 0 | 不指定。 |  
| EAP_PEAP | 1 | PEAP类型。 |  
| EAP_TLS | 2 | TLS类型。 |  
| EAP_TTLS | 3 | TTLS类型。 |  
| EAP_PWD | 4 | PWD类型。 |  
| EAP_SIM | 5 | SIM类型。 |  
| EAP_AKA | 6 | AKA类型。 |  
| EAP_AKA_PRIME | 7 | AKA Prime类型。 |  
| EAP_UNAUTH_TLS | 8 | UNAUTH TLS类型 |  
    
## Phase2Method<sup>(10+)</sup>    
表示第二阶段认证方式的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PHASE2_NONE | 0 | 不指定。 |  
| PHASE2_PAP | 1 | PAP类型。 |  
| PHASE2_MSCHAP | 2 | MSCHAP类型。 |  
| PHASE2_MSCHAPV2 | 3 | MSCHAPV2类型。 |  
| PHASE2_GTC | 4 | GTC类型。 |  
| PHASE2_SIM | 5 | SIM类型。 |  
| PHASE2_AKA | 6 | AKA类型。 |  
| PHASE2_AKA_PRIME | 7 | AKA Prime类型。 |  
    
## WifiEapConfig<sup>(10+)</sup>    
可扩展身份验证协议配置信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| eapMethod<sup>(10+)</sup> | EapMethod | false | true | EAP认证方式。 |  
| phase2Method<sup>(10+)</sup> | Phase2Method | false | true | 第二阶段认证方式。 |  
| identity<sup>(10+)</sup> | string | false | true | 身份信息。 |  
| anonymousIdentity<sup>(10+)</sup> | string | false | true | 匿名身份。 |  
| password<sup>(10+)</sup> | string | false | true | 密码。 |  
| caCertAlias<sup>(10+)</sup> | string | false | true | CA 证书别名。 |  
| caPath<sup>(10+)</sup> | string | false | true | CA 证书路径。 |  
| clientCertAlias<sup>(10+)</sup> | string | false | true | 客户端证书别名。 |  
| certEntry<sup>(10+)</sup> | Uint8Array | false | true | CA 证书内容。 |  
| certPassword<sup>(10+)</sup> | string | false | true | CA证书密码。 |  
| altSubjectMatch<sup>(10+)</sup> | string | false | true | 替代主题匹配。 |  
| domainSuffixMatch<sup>(10+)</sup> | string | false | true | 域后缀匹配。 |  
| realm<sup>(10+)</sup> | string | false | true | 通行证凭证的领域。 |  
| plmn<sup>(10+)</sup> | string | false | true | 公共陆地移动网的直通凭证提供商。 |  
| eapSubId<sup>(10+)</sup> | number | false | true | SIM卡的子ID。 |  
    
## WifiDeviceConfig    
WLAN配置信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid | string | false | true | 热点的SSID，编码格式为UTF-8。 |  
| bssid | string | false | false | 热点的BSSID。 |  
| bssidType<sup>(10+)</sup> | DeviceAddressType | false | false | 热点的BSSID类型。 |  
| preSharedKey | string | false | true | 热点的密钥。 |  
| isHiddenSsid | boolean | false | false | 是否是隐藏网络。 |  
| securityType | WifiSecurityType | false | true | 加密类型。 |  
| eapConfig<sup>(10+)</sup> | WifiEapConfig | false | false | 可扩展身份验证协议配置。 |  
    
## WifiInfoElem    
WLAN热点信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| eid | number | false | true | 元素ID。 |  
| content | Uint8Array | false | true | 元素内容。 |  
    
## WifiChannelWidth    
表示带宽类型的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WIDTH_20MHZ | 0 | 20MHZ。 |  
| WIDTH_40MHZ | 1 | 40MHZ。 |  
| WIDTH_80MHZ | 2 | 80MHZ。 |  
| WIDTH_160MHZ | 3 | 160MHZ。 |  
| WIDTH_80MHZ_PLUS | 4 | 80MHZ<sup>+</sup>。 |  
| WIDTH_INVALID | 5 | 无效值 |  
    
## WifiScanInfo    
WLAN热点信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid | string | false | true | 热点的SSID，编码格式为UTF-8。 |  
| bssid | string | false | true | 热点的BSSID。 |  
| bssidType<sup>(10+)</sup> | DeviceAddressType | false | true | 热点的BSSID类型。 |  
| capabilities | string | false | true | 热点能力。 |  
| securityType | WifiSecurityType | false | true | WLAN加密类型。 |  
| rssi | number | false | true | 热点的信号强度(dBm)。 |  
| band | number | false | true | WLAN接入点的频段。 |  
| frequency | number | false | true | WLAN接入点的频率。 |  
| channelWidth | number | false | true | WLAN接入点的带宽。 |  
| centerFrequency0 | number | false | true | 热点的中心频率。 |  
| centerFrequency1 | number | false | true | 热点的中心频率。如果热点使用两个不重叠的WLAN信道，则返回两个中心频率，分别用centerFrequency0和centerFrequency1表示。 |  
| infoElems | Array<WifiInfoElem> | false | true | 信息元素。 |  
| timestamp | number | false | true | 时间戳。 |  
    
## WifiSecurityType    
表示加密类型的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WIFI_SEC_TYPE_INVALID | 0 | 无效加密类型。 |  
| WIFI_SEC_TYPE_OPEN | 1 | 开放加密类型。 |  
| WIFI_SEC_TYPE_WEP | 2 | WiredEquivalentPrivacy(WEP)加密类型。 |  
| WIFI_SEC_TYPE_PSK | 3 | Pre-sharedkey(PSK)加密类型。 |  
| WIFI_SEC_TYPE_SAE | 4 | SimultaneousAuthenticationofEquals(SAE)加密类型。 |  
| WIFI_SEC_TYPE_EAP | 5 | EAP加密类型。 |  
| WIFI_SEC_TYPE_EAP_SUITE_B | 6 | Suite-B 192位加密类型。 |  
| WIFI_SEC_TYPE_OWE | 7 | 机会性无线加密类型。 |  
| WIFI_SEC_TYPE_WAPI_CERT | 8 | WAPI-Cert加密类型。 |  
| WIFI_SEC_TYPE_WAPI_PSK | 9 | WAPI-PSK加密类型。 |  
    
## WifiBandType<sup>(10+)</sup>    
表示WIFI频段类型的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WIFI_BAND_NONE | 0 | 无效频段类型。 |  
| WIFI_BAND_2G | 1 | 2.4G频段类型。 |  
| WIFI_BAND_5G | 2 | 5G频段类型。 |  
| WIFI_BAND_6G | 3 | 6G频段类型。 |  
| WIFI_BAND_60G | 4 | 60G频段类型。 |  
    
## WifiStandard<sup>(10+)</sup>    
表示WIFI标准的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WIFI_STANDARD_UNDEFINED | 0 | 无效WIFI标准类型。 |  
| WIFI_STANDARD_11A | 1 | 802.11a WiFi标准类型。 |  
| WIFI_STANDARD_11B | 2 | 802.11b WiFi标准类型。 |  
| WIFI_STANDARD_11G | 3 | 802.11g WiFi标准类型。 |  
| WIFI_STANDARD_11N | 4 | 802.11n WiFi标准类型。 |  
| WIFI_STANDARD_11AC | 5 | 802.11ac WiFi标准类型。 |  
| WIFI_STANDARD_11AX | 6 | 802.11ax WiFi标准类型。 |  
| WIFI_STANDARD_11AD | 7 | 802.11ad WiFi标准类型。 |  
    
## WifiLinkedInfo    
提供WLAN连接的相关信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ssid | string | false | true | 热点的SSID，编码格式为UTF-8。 |  
| bssid | string | false | true | 热点的BSSID。 |  
| rssi | number | false | true | 热点的信号强度(dBm) |  
| band | number | false | true | WLAN接入点的频段。 |  
| linkSpeed | number | false | true | WLAN接入点的上行速度。 |  
| rxLinkSpeed<sup>(10+)</sup> | number | false | true | WLAN接入点的下行速度。 |  
| maxSupportedTxLinkSpeed<sup>(10+)</sup> | number | false | true | 当前支持的最大上行速率。 |  
| maxSupportedRxLinkSpeed<sup>(10+)</sup> | number | false | true | 当前支持的最大下行速率。 |  
| frequency | number | false | true | WLAN接入点的频率。 |  
| isHidden | boolean | false | true | WLAN接入点是否是隐藏网络。 |  
| isRestricted | boolean | false | true | WLAN接入点是否限制数据量。 |  
| macType | number | false | true | MAC地址类型。0 - 随机MAC地址，1 - 设备MAC地址。 |  
| macAddress | string | false | true | 设备的MAC地址。 |  
| ipAddress | number | false | true | WLAN连接的IP地址。 |  
| connState | ConnState | false | true | WLAN连接状态。 |  
| channelWidth<sup>(10+)</sup> | WifiChannelWidth | false | true | 当前连接热点的信道带宽。 |  
| wifiStandard<sup>(10+)</sup> | WifiStandard | false | true | 当前连接热点的WiFi标准。 |  
    
## IpInfo    
IP信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| ipAddress | number | false | true | IP地址。 |  
| gateway | number | false | true | 网关。 |  
| netmask | number | false | true | 掩码。 |  
| primaryDns | number | false | true | 主DNS服务器IP地址。 |  
| secondDns | number | false | true | 备DNS服务器IP地址。 |  
| serverIp | number | false | true | DHCP服务端IP地址。 |  
| leaseDuration | number | false | true | IP地址租用时长。 |  
    
## Ipv6Info<sup>(10+)</sup>    
Ipv6信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| linkIpv6Address<sup>(10+)</sup> | string | false | true | 链路Ipv6地址。 |  
| globalIpv6Address<sup>(10+)</sup> | string | false | true | 全局Ipv6地址。 |  
| randomGlobalIpv6Address<sup>(10+)</sup> | string | false | true | 随机全局Ipv6地址。 |  
| gateway<sup>(10+)</sup> | string | false | true | 网关。 |  
| netmask<sup>(10+)</sup> | string | false | true | 网络掩码。 |  
| primaryDNS<sup>(10+)</sup> | string | false | true | 主DNS服务器Ipv6地址。 |  
| secondDNS<sup>(10+)</sup> | string | false | true | 备DNS服务器Ipv6地址。 |  
    
## ConnState    
表示WLAN连接状态的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.STA    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SCANNING | 0 | 设备正在搜索可用的AP。 |  
| CONNECTING | 1 | 正在建立WLAN连接。 |  
| AUTHENTICATING | 2 | WLAN连接正在认证中。 |  
| OBTAINING_IPADDR | 3 | 正在获取WLAN连接的IP地址。 |  
| CONNECTED | 4 | WLAN连接已建立。 |  
| DISCONNECTING | 5 | WLAN连接正在断开。 |  
| DISCONNECTED | 6 | WLAN连接已断开。 |  
| UNKNOWN | 7 | WLAN连接建立失败。 |  
    
## WifiP2pDevice    
表示P2P设备信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceName | string | false | true | 设备名称。 |  
| deviceAddress | string | false | true | 设备MAC地址。 |  
| deviceAddressType<sup>(10+)</sup> | DeviceAddressType | false | false | 设备MAC地址类型。 |  
| primaryDeviceType | string | false | true | 主设备类型。 |  
| deviceStatus | P2pDeviceStatus | false | true | | deviceStatus | [P2pDeviceStatus](#p2pdevicestatus9) | 是 | 否 | 设备状态。 | |  
| groupCapabilities | number | false | true | 群组能力。 |  
    
## WifiP2PConfig    
表示P2P配置信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceAddress | string | false | true | 设备地址。 |  
| deviceAddressType<sup>(10+)</sup> | DeviceAddressType | false | false | 设备地址类型。 |  
| netId | number | false | true | 网络ID。创建群组时-1表示创建临时组，-2表示创建永久组。 |  
| passphrase | string | false | true | 群组密钥。 |  
| groupName | string | false | true | 群组名称。 |  
| goBand | GroupOwnerBand | false | true | 群组带宽。 |  
    
## WifiP2pGroupInfo    
表示P2P群组相关信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isP2pGo | boolean | false | true | 是否是群主。 |  
| ownerInfo | WifiP2pDevice | false | true | 群组的设备信息。 |  
| passphrase | string | false | true | 群组密钥。 |  
| interface | string | false | true | 接口名称。 |  
| groupName | string | false | true | 群组名称。 |  
| networkId | number | false | true | 网络ID。 |  
| frequency | number | false | true | 群组的频率。 |  
| clientDevices | WifiP2pDevice[] | false | true | 接入的设备列表信息。 |  
| goIpAddress | string | false | true | 群组IP地址。 |  
    
## P2pConnectState    
表示P2P连接状态的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DISCONNECTED | 0 | 断开状态。 |  
| CONNECTED | 1 | 连接状态。 |  
    
## WifiP2pLinkedInfo    
提供WLAN连接的相关信息。  
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
### 属性    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| connectState | P2pConnectState | false | true | P2P连接状态。 |  
| isGroupOwner | boolean | false | true | 是否是群主。 |  
| groupOwnerAddr | string | false | true | 是否是群主。 |  
    
## P2pDeviceStatus    
表示设备状态的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CONNECTED | 0 | 连接状态。 |  
| INVITED | 1 | 邀请状态。 |  
| FAILED | 2 | 失败状态。 |  
| AVAILABLE | 3 | 可用状态。 |  
| UNAVAILABLE | 4 | 不可用状态。 |  
    
## GroupOwnerBand    
表示群组带宽的枚举。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.P2P    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| GO_BAND_AUTO | 0 | 自动模式。 |  
| GO_BAND_2GHZ | 1 | 2GHZ。 |  
| GO_BAND_5GHZ | 2 | 5GHZ。 |  
