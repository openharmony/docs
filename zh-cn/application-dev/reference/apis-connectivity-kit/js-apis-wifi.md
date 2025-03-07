# @ohos.wifi (WLAN)

该模块主要提供WLAN基础功能、P2P（peer-to-peer）功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API Version 9 开始，该接口不再维护，推荐使用[`@ohos.wifiManager (WLAN)`](js-apis-wifiManager.md)等相关接口。


## 导入模块

```ts
import wifi from '@ohos.wifi';
```


## wifi.isWifiActive

isWifiActive(): boolean

查询WLAN是否已使能。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已使能，&nbsp;false:未使能。 |

**示例：**

```ts
import wifi from '@ohos.wifi';

try {
	let isWifiActive = wifi.isWifiActive();
	console.info("isWifiActive:" + isWifiActive);
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.scan

scan(): boolean

启动WLAN扫描。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:扫描操作执行成功，&nbsp;false:扫描操作执行失败。 |

**示例：**

```ts
import wifi from '@ohos.wifi';

try {
	wifi.scan();
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.getScanInfos

getScanInfos(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt;

获取扫描结果，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 (ohos.permission.GET_WIFI_PEERS_MAC 或 ohos.permission.LOCATION)
ohos.permission.GET_WIFI_PEERS_MAC权限仅系统应用可申请。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&nbsp;&gt; | Promise对象。返回扫描到的热点列表。 |


## wifi.getScanInfos

getScanInfos(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void

获取扫描结果，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 (ohos.permission.GET_WIFI_PEERS_MAC 或 ohos.permission.LOCATION)
ohos.permission.GET_WIFI_PEERS_MAC权限仅系统应用可申请。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&gt; | 是 | 回调函数。当成功时，err为0，data为扫描到的热点；否则err为非0值，data为空。 |

**示例：**

```ts
import wifi from '@ohos.wifi';

wifi.getScanInfos((err, result) => {
    if (err) {
        console.error("get scan info error");
        return;
    }

    let len = result.length;
    console.log("wifi received scan info: " + len);
    for (let i = 0; i < len; ++i) {
        console.info("ssid: " + result[i].ssid);
        console.info("bssid: " + result[i].bssid);
        console.info("capabilities: " + result[i].capabilities);
        console.info("securityType: " + result[i].securityType);
        console.info("rssi: " + result[i].rssi);
        console.info("band: " + result[i].band);
        console.info("frequency: " + result[i].frequency);
        console.info("channelWidth: " + result[i].channelWidth);
        console.info("timestamp: " + result[i].timestamp);
    }
});

wifi.getScanInfos().then(result => {
    let len = result.length;
    console.log("wifi received scan info: " + len);
    for (let i = 0; i < len; ++i) {
        console.info("ssid: " + result[i].ssid);
        console.info("bssid: " + result[i].bssid);
        console.info("capabilities: " + result[i].capabilities);
        console.info("securityType: " + result[i].securityType);
        console.info("rssi: " + result[i].rssi);
        console.info("band: " + result[i].band);
        console.info("frequency: " + result[i].frequency);
        console.info("channelWidth: " + result[i].channelWidth);
        console.info("timestamp: " + result[i].timestamp);
    }
});
```


## WifiScanInfo

WLAN热点信息。

**系统能力：** SystemCapability.Communication.WiFi.STA


| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，最大长度为32字节，编码格式为UTF-8。 |
| bssid | string | 是 | 否 | 热点的BSSID，例如：00:11:22:33:44:55。 |
| capabilities | string | 是 | 否 | 热点能力。 |
| securityType | [WifiSecurityType](#wifisecuritytype) | 是 | 否 | WLAN加密类型。 |
| rssi | number | 是 | 否 | 热点的信号强度(dBm)。 |
| band | number | 是 | 否 | WLAN接入点的频段。 |
| frequency | number | 是 | 否 | WLAN接入点的频率。 |
| channelWidth | number | 是 | 否 | WLAN接入点的带宽。 |
| timestamp | number | 是 | 否 | 时间戳。 |


## WifiSecurityType

表示加密类型的枚举。

**系统能力：** SystemCapability.Communication.WiFi.Core


| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| WIFI_SEC_TYPE_INVALID | 0 | 无效加密类型。 |
| WIFI_SEC_TYPE_OPEN | 1 | 开放加密类型。 |
| WIFI_SEC_TYPE_WEP | 2 | Wired&nbsp;Equivalent&nbsp;Privacy&nbsp;(WEP)加密类型。 |
| WIFI_SEC_TYPE_PSK | 3 | Pre-shared&nbsp;key&nbsp;(PSK)加密类型。 |
| WIFI_SEC_TYPE_SAE | 4 | Simultaneous&nbsp;Authentication&nbsp;of&nbsp;Equals&nbsp;(SAE)加密类型。 |



## WifiDeviceConfig

WLAN配置信息。

**系统能力：** SystemCapability.Communication.WiFi.STA


| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，最大长度为32字节，编码格式为UTF-8。 |
| bssid | string | 是 | 否 | 热点的BSSID，例如：00:11:22:33:44:55。 |
| preSharedKey | string | 是 | 否 | 热点的密钥，最大长度为64字节。 |
| isHiddenSsid | boolean | 是 | 否 | 是否是隐藏网络。 |
| securityType | [WifiSecurityType](#wifisecuritytype) | 是 | 否 | 加密类型。 |



## wifi.addUntrustedConfig<sup>7+</sup>

addUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt;

添加不可信网络配置，使用Promise异步回调。

**需要权限：** ohos.permission.SET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。表示操作结果，true: 成功， false: 失败。 |

**示例：**
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

## wifi.addUntrustedConfig<sup>7+</sup>

addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void

添加不可信网络配置，使用callback异步回调。

**需要权限：** ohos.permission.SET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。 |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当操作成功时，err为0，data表示操作结果，true: 成功， false: 失败。如果error为非0，表示处理出现错误。 |

**示例：**
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

## wifi.removeUntrustedConfig<sup>7+</sup>

removeUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt;

移除不可信网络配置，使用Promise异步回调。

**需要权限：** ohos.permission.SET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise对象。表示操作结果，true: 成功， false: 失败。 |

**示例：**

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


## wifi.removeUntrustedConfig<sup>7+</sup>

removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void

移除不可信网络配置，使用callback异步回调。

**需要权限：** ohos.permission.SET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。 |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数。当操作成功时，err为0，data表示操作结果，true: 成功， false: 失败。如果error为非0，表示处理出现错误。 |

**示例：**
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


## wifi.getSignalLevel

getSignalLevel(rssi: number, band: number): number

查询WLAN信号强度。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | rssi | number | 是 | 热点的信号强度(dBm)。 |
  | band | number | 是 | WLAN接入点的频段。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | number | 信号强度，取值范围为[0,&nbsp;4]。 |

**示例：**
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

## wifi.getLinkedInfo

getLinkedInfo(): Promise&lt;WifiLinkedInfo&gt;

获取WLAN连接信息，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[WifiLinkedInfo](#wifilinkedinfo)&gt; | Promise对象。表示WLAN连接信息。 |


## wifi.getLinkedInfo

getLinkedInfo(callback: AsyncCallback&lt;WifiLinkedInfo&gt;): void

获取WLAN连接信息，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiLinkedInfo](#wifilinkedinfo)&gt; | 是 | 回调函数。当获取成功时，err为0，data表示WLAN连接信息。如果error为非0，表示处理出现错误。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

wifi.getLinkedInfo((err, data:wifi.WifiLinkedInfo) => {
    if (err) {
        console.error("get linked info error");
        return;
    }
    console.info("get wifi linked info: " + JSON.stringify(data));
});

wifi.getLinkedInfo().then(data => {
    console.info("get wifi linked info: " + JSON.stringify(data));
}).catch((error:number) => {
    console.info("get linked info error");
});
```


## WifiLinkedInfo

提供WLAN连接的相关信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，最大长度为32字节，编码格式为UTF-8。 |
| bssid | string | 是 | 否 | 热点的BSSID，例如：00:11:22:33:44:55。 |
| rssi | number | 是 | 否 | 热点的信号强度(dBm)。 |
| band | number | 是 | 否 | WLAN接入点的频段。 |
| linkSpeed | number | 是 | 否 | WLAN接入点的速度。 |
| frequency | number | 是 | 否 | WLAN接入点的频率。 |
| isHidden | boolean | 是 | 否 | WLAN接入点是否是隐藏网络。 |
| isRestricted | boolean | 是 | 否 | WLAN接入点是否限制数据量。 |
| macAddress | string | 是 | 否 | 设备的MAC地址。 |
| ipAddress | number | 是 | 否 | WLAN连接的IP地址。 |
| connState | [ConnState](#connstate) | 是 | 否 | WLAN连接状态。 |


## ConnState

表示WLAN连接状态的枚举。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| SCANNING | 0 | 设备正在搜索可用的AP。 |
| CONNECTING | 1 | 正在建立WLAN连接。 |
| AUTHENTICATING | 2 | WLAN连接正在认证中。 |
| OBTAINING_IPADDR | 3 | 正在获取WLAN连接的IP地址。 |
| CONNECTED | 4 | WLAN连接已建立。 |
| DISCONNECTING | 5 | WLAN连接正在断开。 |
| DISCONNECTED | 6 | WLAN连接已断开。 |
| UNKNOWN | 7 | WLAN连接建立失败。 |


## wifi.isConnected<sup>7+</sup>

isConnected(): boolean

查询WLAN是否已连接。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已连接，&nbsp;false:未连接。 |



## wifi.isFeatureSupported<sup>7+</sup>

isFeatureSupported(featureId: number): boolean

判断设备是否支持相关WLAN特性。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.Core

**参数：**


  | **参数名** | **类型** | 必填 | **说明** |
  | -------- | -------- | -------- | -------- |
  | featureId | number | 是 | 特性ID值。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:支持，&nbsp;false:不支持。 |

**示例：**
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


## wifi.getIpInfo<sup>7+</sup>

getIpInfo(): IpInfo

获取IP信息。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | [IpInfo](#ipinfo7) | IP信息。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let info = wifi.getIpInfo();
	console.info("info:" + JSON.stringify(info));
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## IpInfo<sup>7+</sup>

IP信息。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | 是 | 否 | IP地址。 |
| gateway | number | 是 | 否 | 网关。 |
| netmask | number | 是 | 否 | 掩码。 |
| primaryDns | number | 是 | 否 | 主DNS服务器IP地址。 |
| secondDns | number | 是 | 否 | 备DNS服务器IP地址。 |
| serverIp | number | 是 | 否 | DHCP服务端IP地址。 |
| leaseDuration | number | 是 | 否 | IP地址租用时长。 |


## wifi.getCountryCode<sup>7+</sup>

getCountryCode(): string

获取国家码信息。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | string | 国家码。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let code = wifi.getCountryCode();
	console.info("code:" + code);
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```


## wifi.getP2pLinkedInfo<sup>8+</sup>

getP2pLinkedInfo(): Promise&lt;WifiP2pLinkedInfo&gt;

获取P2P连接信息，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | Promise对象。表示P2P连接信息。 |



## WifiP2pLinkedInfo<sup>8+</sup>

提供WLAN连接的相关信息。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| connectState | [P2pConnectState](#p2pconnectstate8) | 是 | 否 | P2P连接状态。 |
| isGroupOwner | boolean | 是 | 否 | 是否是群主。 |
| groupOwnerAddr | string | 是 | 否 | 群组MAC地址。 


## P2pConnectState<sup>8+</sup>

表示P2P连接状态的枚举。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DISCONNECTED | 0 | 断开状态。 |
| CONNECTED | 1 | 连接状态。 |


## wifi.getP2pLinkedInfo<sup>8+</sup>

getP2pLinkedInfo(callback: AsyncCallback&lt;WifiP2pLinkedInfo&gt;): void

获取P2P连接信息，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示P2P连接信息。如果error为非0，表示处理出现错误。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

wifi.getP2pLinkedInfo((err, data:wifi.WifiP2pLinkedInfo) => {
   if (err) {
       console.error("get p2p linked info error");
       return;
   }
	console.info("get wifi p2p linked info: " + JSON.stringify(data));
});

wifi.getP2pLinkedInfo().then(data => {
	console.info("get wifi p2p linked info: " + JSON.stringify(data));
});
```

## wifi.getCurrentGroup<sup>8+</sup>

getCurrentGroup(): Promise&lt;WifiP2pGroupInfo&gt;

获取P2P当前组信息，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo8)&gt; | Promise对象。表示当前组信息。 |


## wifi.getCurrentGroup<sup>8+</sup>

getCurrentGroup(callback: AsyncCallback&lt;WifiP2pGroupInfo&gt;): void

获取P2P当前组信息，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo8)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示当前组信息。如果error为非0，表示处理出现错误。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

wifi.getCurrentGroup((err, data:wifi.WifiP2pGroupInfo) => {
   if (err) {
       console.error("get current P2P group error");
       return;
   }
	console.info("get current P2P group: " + JSON.stringify(data));
});

wifi.getCurrentGroup().then(data => {
	console.info("get current P2P group: " + JSON.stringify(data));
});
```

## wifi.getP2pPeerDevices<sup>8+</sup>

getP2pPeerDevices(): Promise&lt;WifiP2pDevice[]&gt;

获取P2P对端设备列表信息，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | Promise对象。表示对端设备列表信息。 |


## wifi.getP2pPeerDevices<sup>8+</sup>

getP2pPeerDevices(callback: AsyncCallback&lt;WifiP2pDevice[]&gt;): void

获取P2P对端设备列表信息，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示对端设备列表信息。如果error为非0，表示处理出现错误。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

wifi.getP2pPeerDevices((err, data:wifi.WifiP2pDevice) => {
   if (err) {
       console.error("get P2P peer devices error");
       return;
   }
	console.info("get P2P peer devices: " + JSON.stringify(data));
});

wifi.getP2pPeerDevices().then(data => {
	console.info("get P2P peer devices: " + JSON.stringify(data));
});
```

## WifiP2pDevice<sup>8+</sup>

表示P2P设备信息。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceName | string | 是 | 否 | 设备名称。 |
| deviceAddress | string | 是 | 否 | 设备MAC地址。 |
| primaryDeviceType | string | 是 | 否 | 主设备类型。 |
| deviceStatus | [P2pDeviceStatus](#p2pdevicestatus8) | 是 | 否 | 设备状态。 |
| groupCapabilitys | number | 是 | 否 | 群组能力。 |


## P2pDeviceStatus<sup>8+</sup>

表示设备状态的枚举。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| CONNECTED | 0 | 连接状态。 |
| INVITED | 1 | 邀请状态。 |
| FAILED | 2 | 失败状态。 |
| AVAILABLE | 3 | 可用状态。 |
| UNAVAILABLE | 4 | 不可用状态。 |


## wifi.createGroup<sup>8+</sup>

createGroup(config: WifiP2PConfig): boolean

创建群组。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | 必填 | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiP2PConfig](#wifip2pconfig8) | 是 | 群组配置信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:创建群组操作执行成功，&nbsp;false:创建群组操作执行失败。 |

**示例：**
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

## WifiP2PConfig<sup>8+</sup>

表示P2P配置信息。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceAddress | string | 是 | 否 | 设备地址。 |
| netId | number | 是 | 否 | 网络ID。创建群组时-1表示创建临时组，-2表示创建永久组。 |
| passphrase | string | 是 | 否 | 群组密钥。 |
| groupName | string | 是 | 否 | 群组名称。 |
| goBand | [GroupOwnerBand](#groupownerband8) | 是 | 否 | 群组带宽。 |


## GroupOwnerBand<sup>8+</sup>

表示群组带宽的枚举。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| GO_BAND_AUTO | 0 | 自动模式。 |
| GO_BAND_2GHZ | 1 | 2GHZ。 |
| GO_BAND_5GHZ | 2 | 5GHZ。 |


## wifi.removeGroup<sup>8+</sup>

removeGroup(): boolean

移除群组。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:操作执行成功，&nbsp;false:操作执行失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.removeGroup();	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.p2pConnect<sup>8+</sup>

p2pConnect(config: WifiP2PConfig): boolean

执行P2P连接。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**


  | **参数名** | **类型** | 必填 | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiP2PConfig](#wifip2pconfig8) | 是 | 连接配置信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:操作执行成功，&nbsp;false:操作执行失败。 |


**示例：**
```ts
import wifi from '@ohos.wifi';

let recvP2pConnectionChangeFunc = (result:wifi.WifiP2pLinkedInfo) => {
    console.info("p2p connection change receive event: " + JSON.stringify(result));
    wifi.getP2pLinkedInfo((err, data:wifi.WifiP2pLinkedInfo) => {
        if (err) {
            console.error('failed to get getP2pLinkedInfo: ' + JSON.stringify(err));
            return;
        }
        console.info("get getP2pLinkedInfo: " + JSON.stringify(data));
    });
}
wifi.on("p2pConnectionChange", recvP2pConnectionChangeFunc);

let recvP2pDeviceChangeFunc = (result:wifi.WifiP2pDevice) => {
    console.info("p2p device change receive event: " + JSON.stringify(result));
}
wifi.on("p2pDeviceChange", recvP2pDeviceChangeFunc);

let recvP2pPeerDeviceChangeFunc = (result:wifi.WifiP2pDevice[]) => {
    console.info("p2p peer device change receive event: " + JSON.stringify(result));
    wifi.getP2pPeerDevices((err, data:wifi.WifiP2pDevice) => {
        if (err) {
            console.error('failed to get peer devices: ' + JSON.stringify(err));
            return;
        }
        console.info("get peer devices: " + JSON.stringify(data));
        let len = data.length;
        for (let i = 0; i < len; ++i) {
            if (data[i].deviceName === "my_test_device") {
                console.info("p2p connect to test device: " + data[i].deviceAddress);
                let config:wifi.WifiP2PConfig = {
                    deviceAddress:data[i].deviceAddress,
                    netId:-2,
                    passphrase:"",
                    groupName:"",
                    goBand:0,
                }
                wifi.p2pConnect(config);
            }
        }
    });
}
wifi.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);

let recvP2pPersistentGroupChangeFunc = () => {
    console.info("p2p persistent group change receive event");

    wifi.getCurrentGroup((err, data:wifi.WifiP2pGroupInfo) => {
        if (err) {
            console.error('failed to get current group: ' + JSON.stringify(err));
            return;
        }
        console.info("get current group: " + JSON.stringify(data));
    });
}
wifi.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);

setTimeout(() => {wifi.off("p2pConnectionChange", recvP2pConnectionChangeFunc);}, 125 * 1000);
setTimeout(() => {wifi.off("p2pDeviceChange", recvP2pDeviceChangeFunc);}, 125 * 1000);
setTimeout(() => {wifi.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);}, 125 * 1000);
setTimeout(() => {wifi.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);}, 125 * 1000);
console.info("start discover devices -> " + wifi.startDiscoverDevices());
```

## wifi.p2pCancelConnect<sup>8+</sup>

p2pCancelConnect(): boolean

取消P2P连接。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:操作执行成功，&nbsp;false:操作执行失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.p2pCancelConnect();	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.startDiscoverDevices<sup>8+</sup>

startDiscoverDevices(): boolean

开始发现设备。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:操作执行成功，&nbsp;false:操作执行失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.startDiscoverDevices();	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.stopDiscoverDevices<sup>8+</sup>

stopDiscoverDevices(): boolean

停止发现设备。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:操作执行成功 flase:操作执行失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.stopDiscoverDevices();	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## WifiP2pGroupInfo<sup>8+</sup>

表示P2P群组相关信息。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| isP2pGo | boolean | 是 | 否 | 是否是群主。 |
| ownerInfo | [WifiP2pDevice](#wifip2pdevice8) | 是 | 否 | 群组的设备信息。 |
| passphrase | string | 是 | 否 | 群组密钥。 |
| interface | string | 是 | 否 | 接口名称。 |
| groupName | string | 是 | 否 | 群组名称。 |
| networkId | number | 是 | 否 | 网络ID。 |
| frequency | number | 是 | 否 | 群组的频率。 |
| clientDevices | [WifiP2pDevice[]](#wifip2pdevice8) | 是 | 否 | 接入的设备列表信息。 |
| goIpAddress | string | 是 | 否 | 群组IP地址。 |



## wifi.on('wifiStateChange')<sup>7+</sup>

on(type: 'wifiStateChange', callback: Callback&lt;number&gt;): void

注册WLAN状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

**状态改变事件的枚举：**

| **枚举值** | **说明** |
| -------- | -------- |
| 0 | 未激活。 |
| 1 | 已激活。 |
| 2 | 激活中。 |
| 3 | 去激活中。 |


## wifi.off('wifiStateChange')<sup>7+</sup>

off(type: 'wifiStateChange', callback?: Callback&lt;number&gt;): void

取消注册WLAN状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvPowerNotifyFunc = (result:number) => {
    console.info("Receive power state change event: " + result);
}

// Register event
wifi.on("wifiStateChange", recvPowerNotifyFunc);

// Unregister event
wifi.off("wifiStateChange", recvPowerNotifyFunc);
```


## wifi.on('wifiConnectionChange')<sup>7+</sup>

on(type: 'wifiConnectionChange', callback: Callback&lt;number&gt;): void

注册WLAN连接状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiConnectionChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

**连接状态改变事件的枚举：**

| **枚举值** | **说明** |
| -------- | -------- |
| 0 | 已断开。 |
| 1 | 已连接。 |


## wifi.off('wifiConnectionChange')<sup>7+</sup>

off(type: 'wifiConnectionChange', callback?: Callback&lt;number&gt;): void

取消注册WLAN连接状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiConnectionChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 连接状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvWifiConnectionChangeFunc = (result:number) => {
    console.info("Receive wifi connection change event: " + result);
}

// Register event
wifi.on("wifiConnectionChange", recvWifiConnectionChangeFunc);

// Unregister event
wifi.off("wifiConnectionChange", recvWifiConnectionChangeFunc);
```

## wifi.on('wifiScanStateChange')<sup>7+</sup>

on(type: 'wifiScanStateChange', callback: Callback&lt;number&gt;): void

注册扫描状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiScanStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

**扫描状态改变事件的枚举：**

| **枚举值** | **说明** |
| -------- | -------- |
| 0 | 扫描失败。 |
| 1 | 扫描成功。 |


## wifi.off('wifiScanStateChange')<sup>7+</sup>

off(type: 'wifiScanStateChange', callback?: Callback&lt;number&gt;): void

取消注册扫描状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"wifiScanStateChange"字符串。 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvWifiScanStateChangeFunc = (result:number) => {
    console.info("Receive Wifi scan state change event: " + result);
}

// Register event
wifi.on("wifiScanStateChange", recvWifiScanStateChangeFunc);

// Unregister event
wifi.off("wifiScanStateChange", recvWifiScanStateChangeFunc);
```

## wifi.on('wifiRssiChange')<sup>7+</sup>

on(type: 'wifiRssiChange', callback: Callback&lt;number&gt;): void

注册RSSI状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiRssiChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数，返回以dBm为单位的RSSI值。 |


## wifi.off('wifiRssiChange')<sup>7+</sup>

off(type: 'wifiRssiChange', callback?: Callback&lt;number&gt;): void

取消注册RSSI状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiRssiChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvWifiRssiChangeFunc = (result:number) => {
    console.info("Receive wifi rssi change event: " + result);
}

// Register event
wifi.on("wifiRssiChange", recvWifiRssiChangeFunc);

// Unregister event
wifi.off("wifiRssiChange", recvWifiRssiChangeFunc);

```


## wifi.on('hotspotStateChange')<sup>7+</sup>

on(type: 'hotspotStateChange', callback: Callback&lt;number&gt;): void

注册热点状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

**热点状态改变事件的枚举：**

| **枚举值** | **说明** |
| -------- | -------- |
| 0 | 未激活。 |
| 1 | 已激活。 |
| 2 | 激活中。 |
| 3 | 去激活中。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvHotspotStateChangeFunc = (result:number) => {
    console.info("Receive hotspot state change event: " + result);
}

// Register event
wifi.on("hotspotStateChange", recvHotspotStateChangeFunc);

// Unregister event
wifi.off("hotspotStateChange", recvHotspotStateChangeFunc);
```

## wifi.off('hotspotStateChange')<sup>7+</sup>

off(type: 'hotspotStateChange', callback?: Callback&lt;number&gt;): void

取消注册热点状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |



## wifi.on('p2pStateChange')<sup>8+</sup>

on(type: 'p2pStateChange', callback: Callback&lt;number&gt;): void

注册P2P开关状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

**P2P状态改变事件的枚举：**

| **枚举值** | **说明** |
| -------- | -------- |
| 1 | 空闲。 |
| 2 | 打开中。 |
| 3 | 已打开。 |
| 4 | 关闭中。 |
| 5 | 已关闭。 |

## wifi.off('p2pStateChange')<sup>8+</sup>

off(type: 'p2pStateChange', callback?: Callback&lt;number&gt;): void

取消注册P2P开关状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvP2pStateChangeFunc = (result:number) => {
    console.info("Receive p2p state change event: " + result);
}

// Register event
wifi.on("p2pStateChange", recvP2pStateChangeFunc);

// Unregister event
wifi.off("p2pStateChange", recvP2pStateChangeFunc);
```

## wifi.on('p2pConnectionChange')<sup>8+</sup>

on(type: 'p2pConnectionChange', callback: Callback&lt;WifiP2pLinkedInfo&gt;): void

注册P2P连接状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pConnectionChange"字符串。 |
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | 是 | 状态改变回调函数。 |


## wifi.off('p2pConnectionChange')<sup>8+</sup>

off(type: 'p2pConnectionChange', callback?: Callback&lt;WifiP2pLinkedInfo&gt;): void

取消注册P2P连接状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pConnectionChange"字符串。 |
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvP2pConnectionChangeFunc = (result:wifi.WifiP2pLinkedInfo) => {
    console.info("Receive p2p connection change event: " + result);
}

// Register event
wifi.on("p2pConnectionChange", recvP2pConnectionChangeFunc);

// Unregister event
wifi.off("p2pConnectionChange", recvP2pConnectionChangeFunc);
```

## wifi.on('p2pDeviceChange')<sup>8+</sup>

on(type: 'p2pDeviceChange', callback: Callback&lt;WifiP2pDevice&gt;): void

注册P2P设备状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice8)&gt; | 是 | 状态改变回调函数。 |


## wifi.off('p2pDeviceChange')<sup>8+</sup>

off(type: 'p2pDeviceChange', callback?: Callback&lt;WifiP2pDevice&gt;): void

取消注册P2P设备状态改变事件。

**需要权限：** ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice8)&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvP2pDeviceChangeFunc = (result:wifi.WifiP2pDevice) => {
    console.info("Receive p2p device change event: " + result);
}

// Register event
wifi.on("p2pDeviceChange", recvP2pDeviceChangeFunc);

// Unregister event
wifi.off("p2pDeviceChange", recvP2pDeviceChangeFunc);
```

## wifi.on('p2pPeerDeviceChange')<sup>8+</sup>

on(type: 'p2pPeerDeviceChange', callback: Callback&lt;WifiP2pDevice[]&gt;): void

注册P2P对端设备状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pPeerDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | 是 | 状态改变回调函数。 |


## wifi.off('p2pPeerDeviceChange')<sup>8+</sup>

off(type: 'p2pPeerDeviceChange', callback?: Callback&lt;WifiP2pDevice[]&gt;): void

取消注册P2P对端设备状态改变事件。

**需要权限：** ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pPeerDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvP2pPeerDeviceChangeFunc = (result:wifi.WifiP2pDevice[]) => {
    console.info("Receive p2p peer device change event: " + result);
}

// Register event
wifi.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);

// Unregister event
wifi.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
```

## wifi.on('p2pPersistentGroupChange')<sup>8+</sup>

on(type: 'p2pPersistentGroupChange', callback: Callback&lt;void&gt;): void

注册P2P永久组状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pPersistentGroupChange"字符串。 |
  | callback | Callback&lt;void&gt; | 是 | 状态改变回调函数。 |


## wifi.off('p2pPersistentGroupChange')<sup>8+</sup>

off(type: 'p2pPersistentGroupChange', callback?: Callback&lt;void&gt;): void

取消注册P2P永久组状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pPersistentGroupChange"字符串。 |
  | callback | Callback&lt;void&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvP2pPersistentGroupChangeFunc = (result:void) => {
    console.info("Receive p2p persistent group change event: " + result);
}

// Register event
wifi.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);

// Unregister event
wifi.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);

```

## wifi.on('p2pDiscoveryChange')<sup>8+</sup>

on(type: 'p2pDiscoveryChange', callback: Callback&lt;number&gt;): void

注册发现设备状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDiscoveryChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

**发现设备状态改变事件的枚举：**

| **枚举值** | **说明** |
| -------- | -------- |
| 0 | 初始状态。 |
| 1 | 发现成功。 |


## wifi.off('p2pDiscoveryChange')<sup>8+</sup>

off(type: 'p2pDiscoveryChange', callback?: Callback&lt;number&gt;): void

取消注册发现设备状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDiscoveryChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvP2pDiscoveryChangeFunc = (result:number) => {
    console.info("Receive p2p discovery change event: " + result);
}

// Register event
wifi.on("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);

// Unregister event
wifi.off("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
```