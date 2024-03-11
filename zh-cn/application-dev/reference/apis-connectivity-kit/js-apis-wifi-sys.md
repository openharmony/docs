# @ohos.wifi (WLAN)（系统接口）

该模块主要提供WLAN基础功能、P2P（peer-to-peer）功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.wifi (WLAN)](js-apis-wifi.md)
> 从API Version 9 开始，该接口不再维护，推荐使用[`@ohos.wifiManager (WLAN)`](js-apis-wifiManager-sys.md)等相关接口。


## 导入模块

```ts
import wifi from '@ohos.wifi';
```

## wifi.enableWifi

enableWifi(): boolean

使能WLAN。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。|

**示例：**

```ts
import wifi from '@ohos.wifi';

try {
	wifi.enableWifi();
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.disableWifi

disableWifi(): boolean

去使能WLAN。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。|

**示例：**

```ts
import wifi from '@ohos.wifi';

try {
	wifi.disableWifi();
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}

```


## wifi.addDeviceConfig

addDeviceConfig(config: WifiDeviceConfig): Promise&lt;number&gt;

添加网络配置，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise对象。返回添加的网络配置ID，如果值为-1表示添加失败。 |

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
	wifi.addDeviceConfig(config).then(result => {
		console.info("result:" + JSON.stringify(result));
	});	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## WifiDeviceConfig

WLAN配置信息。

**系统能力：** SystemCapability.Communication.WiFi.STA


| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| creatorUid | number | 是 | 否 | 创建用户的ID。 <br /> **系统接口：** 此接口为系统接口。 |
| disableReason | number | 是 | 否 | 禁用原因。 <br /> **系统接口：** 此接口为系统接口。 |
| netId | number | 是 | 否 | 分配的网络ID。 <br /> **系统接口：** 此接口为系统接口。 |
| randomMacType | number | 是 | 否 | 随机MAC类型。 <br /> **系统接口：** 此接口为系统接口。 |
| randomMacAddr | string | 是 | 否 | 随机MAC地址。 <br /> **系统接口：** 此接口为系统接口。 |
| ipType | [IpType](#iptype7) | 是 | 否 | IP地址类型。 <br /> **系统接口：** 此接口为系统接口。 |
| staticIp | [IpConfig](#ipconfig7) | 是 | 否 | 静态IP配置信息。 <br /> **系统接口：** 此接口为系统接口。 |


## IpType<sup>7+</sup>

表示IP类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA


| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| STATIC | 0 | 静态IP。 |
| DHCP | 1 | 通过DHCP获取。 |
| UNKNOWN | 2 | 未指定。 |


## IpConfig<sup>7+</sup>

IP配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | 是 | 否 | IP地址。 |
| gateway | number | 是 | 否 | 网关。 |
| dnsServers | number[] | 是 | 否 | DNS服务器。 |
| domains | Array&lt;string&gt; | 是 | 否 | 域信息。 |


## wifi.addDeviceConfig

addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void

添加网络配置，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。 |
  | callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。当操作成功时，err为0，data为添加的网络配置ID，如果data值为-1，表示添加失败。当error为非0，表示处理出现错误。 |

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
	wifi.addDeviceConfig(config,(error,result) => {
		console.info("result:" + JSON.stringify(result));
	});	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```


## wifi.connectToNetwork

connectToNetwork(networkId: number): boolean

连接到指定网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | networkId | number | 是 | 待连接的网络配置ID。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**

```ts
import wifi from '@ohos.wifi';

try {
	let networkId = 0;
	wifi.connectToNetwork(networkId);
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}	
```

## wifi.connectToDevice

connectToDevice(config: WifiDeviceConfig): boolean

连接到指定网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：**
  SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**
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

## wifi.disconnect

disconnect(): boolean

断开连接的网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：**
  SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.disconnect();
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```


## WifiLinkedInfo

提供WLAN连接的相关信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| networkId | number | 是 | 否 | 网络配置ID。 <br /> **系统接口：** 此接口为系统接口。 |
| chload | number | 是 | 否 | 连接负载，值越大表示负载约高。 <br /> **系统接口：** 此接口为系统接口。 |
| snr | number | 是 | 否 | 信噪比。 <br /> **系统接口：** 此接口为系统接口。 |
| suppState | [SuppState](#suppstate) | 是 | 否 | 请求状态。 <br /> **系统接口：** 此接口为系统接口。 |


## SuppState

表示请求状态的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
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



## wifi.getSupportedFeatures<sup>7+</sup>

getSupportedFeatures(): number

查询设备支持的特性。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | number | 支持的特性值。 |

**特性ID值枚举：**

| 枚举值 | 说明 |
| -------- | -------- |
| 0x0001 | 基础结构模式特性。 |
| 0x0002 | 5&nbsp;GHz带宽特性。 |
| 0x0004 | GAS/ANQP特性。 |
| 0x0008 | Wifi-Direct特性。 |
| 0x0010 | Soft&nbsp;AP特性。 |
| 0x0040 | Wi-Fi&nbsp;AWare组网特性。 |
| 0x8000 | AP&nbsp;STA共存特性。 |
| 0x8000000 | WPA3-Personal&nbsp;SAE特性。 |
| 0x10000000 | WPA3-Enterprise&nbsp;Suite-B |
| 0x20000000 | 增强开放特性。 |




## wifi.getDeviceMacAddress<sup>7+</sup>

getDeviceMacAddress(): string[]

获取设备的MAC地址。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_LOCAL_MAC 和 ohos.permission.GET_WIFI_INFO，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | string[] | MAC地址。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let ret = wifi.getDeviceMacAddress();
	console.info("deviceMacAddress:" + JSON.stringify(ret));
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}

```


## wifi.reassociate<sup>7+</sup>

reassociate(): boolean

重新关联网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.reassociate();
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.reconnect<sup>7+</sup>

reconnect(): boolean

重新连接网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.reconnect();
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.getDeviceConfigs<sup>7+</sup>

getDeviceConfigs(): &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig)&gt;

获取网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION 和 ohos.permission.GET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig)&gt; | 网络配置信息的数组。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let configs = wifi.getDeviceConfigs();
	console.info("configs:" + JSON.stringify(configs));
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.updateNetwork<sup>7+</sup>

updateNetwork(config: WifiDeviceConfig): number

更新网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | number | 返回更新的网络配置ID，如果值为-1表示更新失败。 |

**示例：**
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

## wifi.disableNetwork<sup>7+</sup>

disableNetwork(netId: number): boolean

去使能网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | netId | number | 是 | 网络配置ID。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let netId = 0;
	wifi.disableNetwork(netId);		
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.removeAllNetwork<sup>7+</sup>

removeAllNetwork(): boolean

移除所有网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.removeAllNetwork();		
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.removeDevice<sup>7+</sup>

removeDevice(id: number): boolean

移除指定的网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | id | number | 是 | 网络配置ID。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let id = 0;
	wifi.removeDevice(id);		
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.enableHotspot<sup>7+</sup>

enableHotspot(): boolean

使能热点。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。|

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.enableHotspot();	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.disableHotspot<sup>7+</sup>

disableHotspot(): boolean

去使能热点。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。|

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.disableHotspot();	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.isHotspotDualBandSupported<sup>7+</sup>

isHotspotDualBandSupported(): boolean

热点是否支持双频。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:支持，&nbsp;false:不支持。|

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let ret = wifi.isHotspotDualBandSupported();
	console.info("result:" + ret);		
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.isHotspotActive<sup>7+</sup>

isHotspotActive(): boolean

热点是否已使能。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已使能，&nbsp;false:未使能。|

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let ret = wifi.isHotspotActive();
	console.info("result:" + ret);		
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.setHotspotConfig<sup>7+</sup>

setHotspotConfig(config: HotspotConfig): boolean

设置热点配置信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [HotspotConfig](#hotspotconfig7) | 是 | 热点配置信息。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**
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

## HotspotConfig<sup>7+</sup>

热点配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，编码格式为UTF-8。 |
| securityType | [WifiSecurityType](js-apis-wifi.md#wifisecuritytype) | 是 | 否 | 加密类型。 |
| band | number | 是 | 否 | 热点的带宽。1: 2.4G, 2: 5G, 3: 双模频段 |
| preSharedKey | string | 是 | 否 | 热点的密钥。 |
| maxConn | number | 是 | 否 | 最大设备连接数。 |


## wifi.getHotspotConfig<sup>7+</sup>

getHotspotConfig(): HotspotConfig

获取热点配置信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | [HotspotConfig](#hotspotconfig7) | 热点的配置信息。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let config = wifi.getHotspotConfig();
	console.info("result:" + JSON.stringify(config));		
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.getStations<sup>7+</sup>

getStations(): &nbsp;Array&lt;[StationInfo](#stationinfo7)&gt;

获取连接的设备。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | &nbsp;Array&lt;[StationInfo](#stationinfo7)&gt; | 连接的设备数组。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let stations = wifi.getStations();
	console.info("result:" + JSON.stringify(stations));		
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## StationInfo<sup>7+</sup>

接入的设备信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| name | string | 是 | 否 | 设备名称。 |
| macAddress | string | 是 | 否 | MAC地址。 |
| ipAddress | string | 是 | 否 | IP地址。 |


## wifi.deletePersistentGroup<sup>8+</sup>

deletePersistentGroup(netId: number): boolean

删除永久组。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**


  | **参数名** | **类型** | 必填 | **说明** |
  | -------- | -------- | -------- | -------- |
  | netId | number | 是 | 组的ID。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:操作执行成功，操作执行失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let netId = 0;
	wifi.deletePersistentGroup(netId);	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```


## wifi.setDeviceName<sup>8+</sup>

setDeviceName(devName: string): boolean

设置设备名称。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | devName | string | 是 | 设备名称。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:操作成功，&nbsp;false:操作失败。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

try {
	let name = "****";
	wifi.setDeviceName(name);	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.on('streamChange')<sup>7+</sup>

on(type: "streamChange", callback: Callback&lt;number&gt;): void

注册WIFI流更改事件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"streamChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数，返回0:无，1：向下，2：向上，3：双向。 |

## wifi.off('streamChange')<sup>7+</sup>

off(type: "streamChange", callback?: Callback&lt;number&gt;): void

取消注册WIFI流更改事件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"streamChange"字符串。 |
| callback | Callback&lt;number&gt; | 否| 状态改变回调函数，返回0:无，1：向下，2：向上，3：双向。 |

**示例：**
```ts
import wifi from '@ohos.wifi';

let recvStreamChangeFunc = (result:number) => {
    console.info("Receive stream change event: " + result);
}

// Register event
wifi.on("streamChange", recvStreamChangeFunc);

// Unregister event
wifi.off("streamChange", recvStreamChangeFunc);

```


## wifi.on('hotspotStaJoin')<sup>7+</sup>

on(type: "hotspotStaJoin", callback: Callback&lt;StationInfo&gt;): void

注册wifi热点sta加入事件。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStaJoin"字符串。 |
  | callback | Callback&lt;StationInfo&gt; | 是 | 状态改变回调函数。 |

## wifi.off('hotspotStaJoin')<sup>7+</sup>

off(type: "hotspotStaJoin", callback?: Callback&lt;StationInfo&gt;): void

取消注册wifi热点sta加入事件。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStaJoin"字符串。 |
  | callback | Callback&lt;StationInfo&gt; | 否 | 状态改变回调函数。 |

  **示例：**
```ts
import wifi from '@ohos.wifi';

let recvHotspotStaJoinFunc = (result:wifi.StationInfo) => {
    console.info("Receive hotspot sta join event: " + result);
}

// Register event
wifi.on("hotspotStaJoin", recvHotspotStaJoinFunc);

// Unregister event
wifi.off("hotspotStaJoin", recvHotspotStaJoinFunc);

```

## wifi.on('hotspotStaLeave')<sup>7+</sup>

on(type: "hotspotStaLeave", callback: Callback&lt;StationInfo&gt;): void

注册wifi热点sta离开事件。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStaLeave"字符串。 |
  | callback | Callback&lt;StationInf]&gt; | 是 | 状态改变回调函数。 |

## wifi.off('hotspotStaLeave')<sup>7+</sup>

off(type: "hotspotStaLeave", callback?: Callback&lt;StationInfo&gt;): void

取消注册wifi热点sta离开事件。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStaLeave"字符串。 |
  | callback | Callback&lt;StationInf]&gt; | 否 | 状态改变回调函数。 |

  **示例：**
```ts
import wifi from '@ohos.wifi';

let recvHotspotStaLeaveFunc = (result:wifi.StationInfo) => {
    console.info("Receive hotspot sta leave event: " + result);
}

// Register event
wifi.on("hotspotStaLeave", recvHotspotStaLeaveFunc);

// Unregister event
wifi.off("hotspotStaLeave", recvHotspotStaLeaveFunc);

```

