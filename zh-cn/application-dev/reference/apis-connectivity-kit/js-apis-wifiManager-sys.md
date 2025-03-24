# @ohos.wifiManager (WLAN)（系统接口）
该模块主要提供WLAN基础功能、P2P（peer-to-peer）功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.wifiManager (WLAN)](js-apis-wifiManager.md)。

## 导入模块

```ts
import { wifiManager } from '@kit.ConnectivityKit';
```

## wifiManager.disableWifi<sup>9+</sup>

disableWifi(): void

去使能WLAN，异步接口，需要通过注册"wifiStateChange"事件的回调来监听是否关闭成功。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501004  | Operation failed because the service is being opened. |

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.disableWifi();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.enableSemiWifi<sup>12+</sup>

enableSemiWifi(): void

使能WLAN半关闭（STA关闭、其他P2p、Hml可用），异步接口，需要通过注册"wifiStateChange"事件的回调来监听是否使能成功。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION  仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          | 
| 2501000  | Operation failed.|
| 2501004  | Operation failed because the service is being opened. |

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.enableSemiWifi();
	} catch(error) {
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.startScan<sup>10+</sup>

startScan(): void

**系统接口：** 此接口为系统接口。

启动WLAN扫描。

**需要权限：** ohos.permission.SET_WIFI_INFO 和ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.startScan();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.setScanAlwaysAllowed<sup>10+</sup>

setScanAlwaysAllowed(isScanAlwaysAllowed: boolean): void

设置是否始终允许扫描。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| isScanAlwaysAllowed | boolean | 是 | 是否始终允许扫描。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
  | -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let isScanAlwaysAllowed = true;
		wifiManager.setScanAlwaysAllowed(isScanAlwaysAllowed);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getScanAlwaysAllowed<sup>10+</sup>

getScanAlwaysAllowed(): boolean

获取是否始终允许扫描。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| boolean| 是否始终允许扫描。 true 表示允许触发扫描，false表示在禁用wifi时不允许触发扫描。|

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let isScanAlwaysAllowed = wifiManager.getScanAlwaysAllowed();
		console.info("isScanAlwaysAllowed:" + isScanAlwaysAllowed);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## WifiDeviceConfig<sup>9+</sup>

WLAN配置信息。

**系统能力：** SystemCapability.Communication.WiFi.STA


| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| creatorUid | number | 是 | 否 | 创建用户的ID。 <br /> **系统接口：** 此接口为系统接口。 |
| disableReason | number | 是 | 否 | 禁用原因： <br /> -1 - 未知原因，0 - 未禁用，1 - 关联拒绝，2 - 认证失败 <br /> 3 - DHCP失败，4 - 暂时无互联网连接 <br /> 5 - 认证无凭据，6 - 永久无互联网连接 <br /> 7 - 由WIFI管理器禁用，8 - 由于密码错误禁用 <br /> 9 - 认证无订阅，10 - 私有EAP认证错误 <br /> 11 - 未找到网络，12 - 连续失败 <br /> 13 - 由系统禁用，14 - EAP-AKA认证失败 <br /> 15 - 解除关联原因，16 - 禁用网络选择最大值<br /> **系统接口：** 此接口为系统接口。 |
| netId | number | 是 | 否 | 分配的网络ID。 <br /> **系统接口：** 此接口为系统接口。 |
| randomMacType | number | 是 | 否 | MAC地址类型。0 - 随机MAC地址，1 - 设备MAC地址 <br /> **系统接口：** 此接口为系统接口。 |
| randomMacAddr | string | 是 | 否 | MAC地址。<br /> **系统接口：** 此接口为系统接口。 |
| ipType | [IpType](#iptype9) | 是 | 否 | IP地址类型。 <br /> **系统接口：** 此接口为系统接口。 |
| staticIp | [IpConfig](#ipconfig9) | 是 | 否 | 静态IP配置信息。 <br /> **系统接口：** 此接口为系统接口。 |
| proxyConfig<sup>10+</sup> | [WifiProxyConfig](#wifiproxyconfig10) | 是 | 否 | 代理配置。  <br /> **系统接口：** 此接口为系统接口。|
| configStatus<sup>12+</sup> | number | 是 | 否 | 返回当前网络是否允许参与选网。 <br />  1 - 允许参与选网，2 - 禁止参与 <br /> 3 - 永久禁止参与，4 - 未知 <br /> **系统接口：** 此接口为系统接口。|

## IpType<sup>9+</sup>

表示IP类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA


| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| STATIC | 0 | 静态IP。 |
| DHCP | 1 | 通过DHCP获取。 |
| UNKNOWN | 2 | 未指定。 |


## IpConfig<sup>9+</sup>

IP配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | 是 | 否 | IP地址。 |
| gateway | number | 是 | 否 | 网关。 |
| prefixLength | number | 是 | 否 | 掩码。 |
| dnsServers | number[] | 是 | 否 | DNS服务器。 |
| domains | Array&lt;string&gt; | 是 | 否 | 域信息。 |


## WifiProxyConfig<sup>10+</sup>

Wifi 代理配置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| proxyMethod | ProxyMethod | 是 | 否 | 代理方法。 |
| pacWebAddress | string | 是 | 否 | 自动配置代理的PAC web 地址。 |
| serverHostName | string | 是 | 否 | 手动配置代理的服务器主机名。 |
| serverPort | number | 是 | 否 | 手动配置代理的服务器端口。 |
| exclusionObjects | string | 是 | 否 | 手动配置代理的排除对象，对象用“,”分隔。|

## ProxyMethod<sup>10+</sup>

表示WiFi代理方法的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| METHOD_NONE  | 0 | 不使用代理。 |
| METHOD_AUTO  | 1 | 使用自动配置的代理。 |
| METHOD_MANUAL  | 2 | 使用手动配置的代理。 |

## wifiManager.connectToDevice<sup>9+</sup>

connectToDevice(config: WifiDeviceConfig): void

连接到指定网络（如果当前已经连接到热点，请先使用disconnect（）接口断开连接）。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：**
  SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig9) | 是 | WLAN配置信息。如果bssidType未指定值，则bssidType默认为随机设备地址类型。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

## WifiLinkedInfo<sup>9+</sup>

提供WLAN连接的相关信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| networkId | number | 是 | 否 | 网络配置ID。 <br /> **系统接口：** 此接口为系统接口。 |
| chload | number | 是 | 否 | 连接负载，值越大表示负载约高。 <br /> **系统接口：** 此接口为系统接口。 |
| snr | number | 是 | 否 | 信噪比。 <br /> **系统接口：** 此接口为系统接口。 |
| suppState | [SuppState](#suppstate9) | 是 | 否 | 请求状态。 <br /> **系统接口：** 此接口为系统接口。 |



## SuppState<sup>9+</sup>

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


## wifiManager.getSupportedFeatures<sup>9+</sup>

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
| 0x10000000 | WPA3-Enterprise&nbsp;Suite-B。|
| 0x20000000 | 增强开放特性。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2401000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.getSupportedFeatures();
		console.info("supportedFeatures:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```


## wifiManager.getDeviceMacAddress<sup>15+</sup>

getDeviceMacAddress(): string[]

获取设备的MAC地址。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_LOCAL_MAC 和 ohos.permission.GET_WIFI_INFO，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | string[] | MAC地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.getDeviceMacAddress();
		console.info("deviceMacAddress:" + JSON.stringify(ret));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifiManager.getWifiDetailState<sup>12+</sup>

getWifiDetailState(): WifiDetailState

获取Wifi开关详细状态。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | [WifiDetailState](#wifidetailstate12) | Wifi枚举状态。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.getWifiDetailState();
		console.info("wifiDetailState:" + ret);
	} catch(error) {
		console.error("failed:" + JSON.stringify(error));
	}

```

## WifiDetailState<sup>12+</sup>

表示Wifi开关状态的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| UNKNOWN | -1 | 未指定。 |
| INACTIVE | 0 | 已关闭。 |
| ACTIVATED | 1 | 已激活。 |
| ACTIVATING | 2 | 激活中。 |
| DEACTIVATING | 3 | 关闭中。 |
| SEMI_ACTIVATING | 4 | 半关闭中。 |
| SEMI_ACTIVE | 5 | 已半关闭。 |


## wifiManager.reassociate<sup>9+</sup>

reassociate(): void

重新关联网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.reassociate();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.reconnect<sup>9+</sup>

reconnect(): void

重新连接网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.reconnect();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.updateNetwork<sup>9+</sup>

updateNetwork(config: WifiDeviceConfig): number

更新网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig9) | 是 | WLAN配置信息。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | number | 返回更新的网络配置ID，如果值为-1表示更新失败。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

## wifiManager.disableNetwork<sup>9+</sup>

disableNetwork(netId: number): void

去使能网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | netId | number | 是 | 网络配置ID。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let netId = 0;
		wifiManager.disableNetwork(netId);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.removeAllNetwork<sup>9+</sup>

removeAllNetwork(): void

移除所有网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.removeAllNetwork();		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.get5GChannelList<sup>10+</sup>

get5GChannelList(): Array&lt;number&gt;

获取当前设备支持的5G信道列表。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | &nbsp;Array&lt;number&gt; | 设备支持的5G信道列表。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let channelList = wifiManager.get5GChannelList();
		console.info("channelList:" + JSON.stringify(channelList));		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```
## wifiManager.getDisconnectedReason<sup>10+</sup>

getDisconnectedReason(): DisconnectedReason

获取最近一次断连原因。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| [DisconnectedReason](#disconnectedreason-10) | 最近断开的原因 |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let disconnectedReason = wifiManager.getDisconnectedReason();	
        console.info("disconnectedReason:" + disconnectedReason);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## DisconnectedReason <sup>10+</sup>

表示wifi断开原因的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DISC_REASON_DEFAULT  | 0 | 默认原因。 |
| DISC_REASON_WRONG_PWD  | 1 | 密码错误。 |
| DISC_REASON_CONNECTION_FULL  | 2 | 路由器的连接数已达到最大数量限制。 |

## wifiManager.startPortalCertification<sup>11+</sup>

startPortalCertification(): void

**系统接口：** 此接口为系统接口。

启动portal认证。

**需要权限：** ohos.permission.SET_WIFI_INFO 和ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.startPortalCertification();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.enableHiLinkHandshake<sup>12+</sup>

enableHiLinkHandshake(isHiLinkEnable: boolean, bssid: string, config: WifiDeviceConfig): void

**系统接口：** 此接口为系统接口。

设置是否使能hiLink。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| isHiLinkEnable | boolean | 是 | 是否使能hiLink。true:使能，&nbsp;false:去使能。 |
| bssid | string | 是 | 热点的mac地址，例如：00:11:22:33:44:55。 |
| config | [WifiDeviceConfig](#wifideviceconfig9) | 是 | WLAN的配置信息。config.bssid必须和第二个参数bssid保持一致。如果bssidType未指定值，则bssidType默认为随机设备地址类型。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';
	// config数据可以通过getScanInfoList接口获取，只有WifiScanInfo.isHiLinkNetwork为true的热点，才能正常使用该接口
	let config:wifiManager.WifiDeviceConfig = {
		ssid : "****",
		preSharedKey : "****",
		securityType : 0,
		bssid : "38:37:8b:80:bf:cc",
		bssidType : 1,
		isHiddenSsid : false
	}	
	try {
		wifiManager.enableHiLinkHandshake(true, config.bssid, config);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.factoryReset<sup>11+</sup>

factoryReset(): void

**系统接口：** 此接口为系统接口。

重置wifi相关配置。

**需要权限：** ohos.permission.SET_WIFI_INFO 和ohos.permission.SET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.factoryReset();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```
## wifiManager.enableHotspot<sup>9+</sup>

enableHotspot(): void

使能热点，异步接口，是否打开成功需要注册并监听hotspotStateChange的回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.enableHotspot();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.disableHotspot<sup>9+</sup>

disableHotspot(): void

去使能热点 ，异步接口，是否关闭成功需要注册并监听hotspotStateChange的回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.disableHotspot();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.isHotspotDualBandSupported<sup>9+</sup>

isHotspotDualBandSupported(): boolean

热点是否支持双频。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:支持，&nbsp;false:不支持。|

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.isHotspotDualBandSupported();
		console.info("result:" + ret);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.isOpenSoftApAllowed<sup>18+</sup>

isOpenSoftApAllowed(): boolean

热点是否支持双频。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:允许，&nbsp;false:不允许。|

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.isOpenSoftApAllowed();
		console.info("result:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.setHotspotConfig<sup>9+</sup>

setHotspotConfig(config: HotspotConfig): void

设置热点配置信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | config | [HotspotConfig](#hotspotconfig9) | 是 | 热点配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

## HotspotConfig<sup>9+</sup>

热点配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 是 | 热点的SSID，编码格式为UTF-8。 |
| securityType | [WifiSecurityType](js-apis-wifiManager.md#wifisecuritytype9)| 是 | 是 | 加密类型。 |
| band | number | 是 | 是 | 热点的带宽。1: 2.4G, 2: 5G, 3: 双模频段 |
| channel<sup>10+</sup> | number | 是 | 是 | 热点的信道（2.4G：1~14,5G：7~196）。 |
| preSharedKey | string | 是 | 是 | 热点的密钥。 |
| maxConn | number | 是 | 是 | 最大设备连接数。 |

## wifiManager.getHotspotConfig<sup>9+</sup>

getHotspotConfig(): HotspotConfig

获取热点配置信息。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | [HotspotConfig](#hotspotconfig9) | 热点的配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let config = wifiManager.getHotspotConfig();
		console.info("result:" + JSON.stringify(config));		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getStations<sup>9+</sup>

getStations(): &nbsp;Array&lt;StationInfo&gt;

获取连接的设备。

**系统接口：** 此接口为系统接口。

**需要权限：**

API 9：ohos.permission.GET_WIFI_INFO、ohos.permission.LOCATION、ohos.permission.APPROXIMATELY_LOCATION 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

API 10起：ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| &nbsp;Array&lt;[StationInfo](#stationinfo9)&gt; | 连接的设备数组。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的macAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let stations = wifiManager.getStations();
		console.info("result:" + JSON.stringify(stations));		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## StationInfo<sup>9+</sup>

接入的设备信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| name | string | 是 | 否 | 设备名称。 |
| macAddress | string | 是 | 否 | MAC地址。 |
| macAddressType<sup>10+</sup> | [DeviceAddressType](js-apis-wifiManager.md#deviceaddresstype10) | 是 | 否 | MAC地址类型。 |
| ipAddress | string | 是 | 否 | IP地址。 |

## wifiManager.addHotspotBlockList<sup>11+</sup>

addHotspotBlockList(stationInfo: StationInfo)

将设备添加到热点的阻止连接设备列表中，列表中的设备将不能访问热点。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| stationInfo | [StationInfo](#stationinfo9) | 是 | 将添加到热点的阻止列表中的设备。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let config:wifiManager.StationInfo = {
			name : "testSsid",
			macAddress : "11:22:33:44:55:66",
			ipAddress : "192.168.1.111"
		}
		// 热点开启后，才能正常将设备添加到连接阻止列表中
		wifiManager.addHotspotBlockList(config);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.delHotspotBlockList<sup>11+</sup>

delHotspotBlockList(stationInfo: StationInfo)

将设备从热点的阻止列表中删除。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| stationInfo | [StationInfo](#stationinfo9) | 是 | 将从热点的阻止列表中删除的设备。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let config:wifiManager.StationInfo = {
			name : "testSsid",
			macAddress : "11:22:33:44:55:66",
			ipAddress : "192.168.1.111"
		}
		wifiManager.delHotspotBlockList(config);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getHotspotBlockList<sup>11+</sup>

getHotspotBlockList(): Array&lt;StationInfo&gt;

获取热点的阻止列表。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| &nbsp;Array&lt;[StationInfo](#stationinfo9)&gt; | 热点的阻止列表。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
  | -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let data = wifiManager.getHotspotBlockList();
		console.info("result:" + JSON.stringify(data));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.deletePersistentGroup<sup>9+</sup>

deletePersistentGroup(netId: number): void

删除永久组。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**


  | **参数名** | **类型** | 必填 | **说明** |
  | -------- | -------- | -------- | -------- |
  | netId | number | 是 | 组的ID。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1.Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let netId = 0;
		wifiManager.deletePersistentGroup(netId);	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getP2pGroups<sup>9+</sup>

getP2pGroups(): Promise&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;

获取创建的所有P2P群组信息，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：**

API 9：ohos.permission.GET_WIFI_INFO、ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](js-apis-wifiManager.md#wifip2pgroupinfo9)&gt;&nbsp;&gt; | Promise对象。表示所有群组信息。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	wifiManager.getP2pGroups((err, data:wifiManager.WifiP2pGroupInfo) => {
    if (err) {
        console.error("get P2P groups error");
        return;
    }
		console.info("get P2P groups: " + JSON.stringify(data));
	});

	wifiManager.getP2pGroups().then(data => {
		console.info("get P2P groups: " + JSON.stringify(data));
	});
	
```


## wifiManager.getP2pGroups<sup>9+</sup>

getP2pGroups(callback: AsyncCallback&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;): void

获取创建的所有P2P群组信息，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限：**

API 9：ohos.permission.GET_WIFI_INFO、ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](js-apis-wifiManager.md#wifip2pgroupinfo9)&gt;&gt; | 是 | 回调函数。当操作成功时，err为0，data表示所有群组信息。如果error为非0，表示处理出现错误。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

## wifiManager.setDeviceName<sup>9+</sup>

setDeviceName(devName: string): void

设置设备名称。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | devName | string | 是 | 设备名称。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let name = "****";
		wifiManager.setDeviceName(name);	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```


## wifiManager.on('streamChange')<sup>9+</sup>

on(type: 'streamChange', callback: Callback&lt;number&gt;): void

注册WIFI流变更事件，在业务退出时，要调用off(type: 'streamChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"streamChange"字符串。 |
| callback | Callback&lt;number&gt; | 是 | 状态改变回调函数，返回0:无，1：向下，2：向上，3：双向。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('streamChange')<sup>9+</sup>

off(type: 'streamChange', callback?: Callback&lt;number&gt;): void

取消注册WIFI流变更事件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"streamChange"字符串。 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数，返回0:无，1：向下，2：向上，3：双向。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
import { wifi } from '@kit.ConnectivityKit';

let recvStreamChangeFunc = (result:number) => {
    console.info("Receive stream change event: " + result);
}

// Register event
wifi.on("streamChange", recvStreamChangeFunc);

// Unregister event
wifi.off("streamChange", recvStreamChangeFunc);

```
## wifiManager.on('deviceConfigChange')<sup>9+</sup>

on(type: 'deviceConfigChange', callback: Callback&lt;number&gt;): void

注册WIFI设备配置更改事件，在业务退出时，要调用off(type: 'deviceConfigChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"deviceConfigChange"字符串。 |
| callback | Callback&lt;number&gt; | 是 | 状态改变回调函数，返回值为 0: 添加配置。1: 更改配置。2: 删除配置。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('deviceConfigChange')<sup>9+</sup>

off(type: 'deviceConfigChange', callback?: Callback&lt;number&gt;): void

取消注册WIFI设备配置更改事件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"deviceConfigChange"字符串。 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数，返回值为 0: 添加配置。1: 更改配置。2: 删除配置。|

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

let recvDeviceConfigChangeFunc = (result:number) => {
    console.info("Receive device config change event: " + result);
}

// Register event
wifi.on("deviceConfigChange", recvDeviceConfigChangeFunc);

// Unregister event
wifi.off("deviceConfigChange", recvDeviceConfigChangeFunc);

```

## wifiManager.on('hotspotStaJoin')<sup>9+</sup>

on(type: 'hotspotStaJoin', callback: Callback&lt;StationInfo&gt;): void

注册wifi热点sta加入事件，在业务退出时，要调用off(type: 'hotspotStaJoin', callback?: Callback&lt;StationInfo&gt;)接口去掉之前的注册回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"hotspotStaJoin"字符串。 |
| callback | Callback&lt;StationInfo&gt; | 是 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

## wifiManager.off('hotspotStaJoin')<sup>9+</sup>

off(type: 'hotspotStaJoin', callback?: Callback&lt;StationInfo&gt;): void

取消注册wifi热点sta加入事件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"hotspotStaJoin"字符串。 |
| callback | Callback&lt;StationInfo&gt; | 否 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

let recvHotspotStaJoinFunc = (result:wifiManager.StationInfo) => {
    console.info("Receive hotspot sta join event: " + result);
}

// Register event
wifiManager.on("hotspotStaJoin", recvHotspotStaJoinFunc);

// Unregister event
wifiManager.off("hotspotStaJoin", recvHotspotStaJoinFunc);

```

## wifiManager.on('hotspotStaLeave')<sup>9+</sup>

on(type: 'hotspotStaLeave', callback: Callback&lt;StationInfo&gt;): void

注册wifi热点sta离开事件，在业务退出时，要调用off(type: 'hotspotStaLeave', callback?: Callback&lt;StationInfo&gt;)接口去掉之前的注册回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStaLeave"字符串。 |
  | callback | Callback&lt;StationInf]&gt; | 是 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

## wifiManager.off('hotspotStaLeave')<sup>9+</sup>

off(type: 'hotspotStaLeave', callback?: Callback&lt;StationInfo&gt;): void

取消注册wifi热点sta离开事件。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"hotspotStaLeave"字符串。 |
| callback | Callback&lt;StationInf]&gt; | 否 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

let recvHotspotStaLeaveFunc = (result:wifiManager.StationInfo) => {
    console.info("Receive hotspot sta leave event: " + result);
}

// Register event
wifiManager.on("hotspotStaLeave", recvHotspotStaLeaveFunc);

// Unregister event
wifiManager.off("hotspotStaLeave", recvHotspotStaLeaveFunc);

```

