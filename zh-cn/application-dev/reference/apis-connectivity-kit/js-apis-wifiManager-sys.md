# @ohos.wifiManager (WLAN)（系统接口）

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @qq_43802146-->
<!--Designer: @qq_43802146-->
<!--Tester: @furryfurry123-->
<!--Adviser: @zhang_yixin13-->
该模块主要提供WLAN基础功能、P2P（peer-to-peer）功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.wifiManager (WLAN)](js-apis-wifiManager.md)。

## 导入模块

```ts
import { wifiManager } from '@kit.ConnectivityKit';
```

## wifiManager.enableSemiWifi<sup>12+</sup>

enableSemiWifi(): void

使能WLAN半关闭（STA关闭，P2P、HML等功能可用），异步接口，需要通过注册"wifiStateChange"事件的回调来监听是否使能成功。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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

## wifiManager.setScanAlwaysAllowed<sup>10+</sup>

setScanAlwaysAllowed(isScanAlwaysAllowed: boolean): void

设置是否始终允许扫描。

- 该接口控制设备是否可以在WLAN开关关闭时支持热点扫描功能。
- 启用后即使WLAN开关关闭，系统仍可以扫描附近的WLAN热点。
- 主要用于支持网络发现和位置定位等场景。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG(仅系统应用可申请)

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| isScanAlwaysAllowed | boolean | 是 | 是否始终允许扫描。true:允许扫描，&nbsp;false:不允许扫描 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG(仅系统应用可申请)

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean| 是否始终允许扫描。 true 表示允许触发扫描，false表示在禁用wifi时不允许触发扫描。|

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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

## WifiDeviceConfig

WLAN配置信息。

**系统能力：** SystemCapability.Communication.WiFi.STA


| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| creatorUid | number | 否 | 是 | 创建用户的ID。 <br /> **系统接口：** 此接口为系统接口。 |
| disableReason | number | 否 | 是 | 禁用原因： <br /> -1 - 未知原因，0 - 未禁用，1 - 关联拒绝，2 - 认证失败 <br /> 3 - DHCP失败，4 - 暂时无互联网连接 <br /> 5 - 认证无凭据，6 - 永久无互联网连接 <br /> 7 - 由WIFI管理器禁用，8 - 由于密码错误禁用 <br /> 9 - 认证无订阅，10 - 私有EAP认证错误 <br /> 11 - 未找到网络，12 - 连续失败 <br /> 13 - 由系统禁用，14 - EAP-AKA认证失败 <br /> 15 - 解除关联原因，16 - 禁用网络选择最大值<br /> **系统接口：** 此接口为系统接口。 |
| randomMacType | number | 否 | 是 | MAC地址类型。0 - 随机MAC地址，1 - 设备MAC地址 <br /> **系统接口：** 此接口为系统接口。 |
| randomMacAddr | string | 否 | 是 | MAC地址。<br /> **系统接口：** 此接口为系统接口。 |
| ipType | [IpType](#iptype) | 否 | 是 | IP地址类型。 <br /> **系统接口：** 此接口为系统接口。 |
| staticIp | [IpConfig](#ipconfig) | 否 | 是 | 静态IP配置信息。 <br /> **系统接口：** 此接口为系统接口。 |
| proxyConfig<sup>10+</sup> | [WifiProxyConfig](#wifiproxyconfig10) | 否 | 是 | 代理配置。  <br /> **系统接口：** 此接口为系统接口。|
| configStatus<sup>12+</sup> | number | 否 | 是 | 返回当前网络是否允许参与选网。 <br />  1 - 允许参与选网，2 - 禁止参与 <br /> 3 - 永久禁止参与，4 - 未知 <br /> **系统接口：** 此接口为系统接口。|
| isAutoConnectAllowed<sup>17+</sup> | boolean | 否 | 是 | 是否允许自动连接。false:不允许，true:允许自动连接。<br /> **系统接口：** 此接口为系统接口。|
| isSecureWifi<sup>20+</sup> | boolean | 否 | 是 | 安全Wi-Fi检测。false:不是安全Wi-Fi，true:是安全Wi-Fi。<br /> **系统接口：** 此接口为系统接口。|

## IpType

表示IP类型的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA


| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| STATIC | 0 | 静态IP。 |
| DHCP | 1 | 通过DHCP获取。 |
| UNKNOWN | 2 | 未指定。 |


## IpConfig

IP配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | 否 | 否 | IP地址。 |
| gateway | number | 否 | 否 | 网关。 |
| prefixLength | number | 否 | 否 | 掩码。 |
| dnsServers | number[] | 否 | 否 | DNS服务器。 |
| domains | Array&lt;string&gt; | 否 | 否 | 域信息。 |


## WifiProxyConfig<sup>10+</sup>

Wifi 代理配置。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| proxyMethod | [ProxyMethod](#proxymethod10) | 否 | 是 | 代理方法。 |
| pacWebAddress | string | 否 | 是 | 自动配置代理的PAC web 地址。 |
| serverHostName | string | 否 | 是 | 手动配置代理的服务器主机名。 |
| serverPort | number | 否 | 是 | 手动配置代理的服务器端口。 |
| exclusionObjects | string | 否 | 是 | 手动配置代理的排除对象，对象用“,”分隔。|

## ProxyMethod<sup>10+</sup>

表示WiFi代理方法的枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| METHOD_NONE  | 0 | 不使用代理。 |
| METHOD_AUTO  | 1 | 使用自动配置的代理。 |
| METHOD_MANUAL  | 2 | 使用手动配置的代理。 |

## wifiManager.getDeviceConfig<sup>24+</sup>

getDeviceConfig(networkId: number): WifiDeviceConfig

根据网络ID获取单条网络配置。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG(仅系统应用可申请)

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| networkId | number | 是 | 待查询的网络配置ID。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [WifiDeviceConfig](#wifideviceconfig) | 指定网络ID的网络配置。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';

  try {
    let networkId = 0;
    let config = wifiManager.getDeviceConfig(networkId);
    console.info(`config: ${JSON.stringify(config)}`);    
  }catch(error){
    console.error(`failed: ${JSON.stringify(error)}`);
  }
```

## wifiManager.connectToDevice

connectToDevice(config: WifiDeviceConfig): void

连接到指定网络（如果当前已经连接到热点，请先使用disconnect（）接口断开连接）。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG（仅系统应用可申请） 和 ohos.permission.MANAGE_WIFI_CONNECTION（仅系统应用可申请）。

**系统能力：**
  SystemCapability.Communication.WiFi.STA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。如果bssidType未指定值，则bssidType默认为随机设备地址类型。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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

## WifiLinkedInfo

提供WLAN连接的相关信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| networkId | number | 否 | 否 | 网络配置ID。 <br /> **系统接口：** 此接口为系统接口。 |
| chload | number | 否 | 否 | 连接负载，值越大表示负载越高。 <br /> **系统接口：** 此接口为系统接口。 |
| snr | number | 否 | 否 | 信噪比，单位：dB。 <br /> **系统接口：** 此接口为系统接口。 |
| suppState | [SuppState](#suppstate) | 否 | 否 | 请求状态。 <br /> **系统接口：** 此接口为系统接口。 |
| isHiLinkProNetwork<sup>20+</sup> | boolean | 否 | 是 | 是否是HiLinkPro网络。true表示是HiLinkPro网络，false表示不是HiLinkPro网络。<br /> **系统接口：** 此接口为系统接口。 |
| wifiTxRxValid | boolean | 否 | 是 | **起始版本：** 26.0.0。用于指示Wi-Fi的发送（Tx, Transmitting）和接收（Rx, Receiving）功能是否都在正常工作。<br /> **系统接口：** 此接口为系统接口。 |

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


## wifiManager.getSupportedFeatures

getSupportedFeatures(): number

查询设备支持的特性。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.Core

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 支持的特性值。 |

**特性ID值枚举：**

| 枚举值 | 说明 |
| -------- | -------- |
| 0x0001 | 基础结构模式特性。 |
| 0x0002 | 5&nbsp;GHz带宽特性。 |
| 0x0004 | GAS/ANQP特性。 |
| 0x0008 | WiFi-Direct特性。 |
| 0x0010 | Soft&nbsp;AP特性。 |
| 0x0040 | Wi-Fi&nbsp;AWare组网特性。 |
| 0x8000 | AP&nbsp;STA共存特性。 |
| 0x8000000 | WPA3-Personal&nbsp;SAE特性。 |
| 0x10000000 | WPA3-Enterprise&nbsp;Suite-B。|
| 0x20000000 | 增强开放特性。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
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

  | 类型 | 说明 |
  | -------- | -------- |
  | [WifiDetailState](#wifidetailstate12) | Wifi枚举状态。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
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


## wifiManager.reassociate

reassociate(): void

重新关联网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
    console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.reconnect

reconnect(): void

重新连接网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
    console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.updateNetwork

updateNetwork(config: WifiDeviceConfig): number

更新网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG(仅系统应用可申请)

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN配置信息。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回更新的网络配置ID，如果值为-1表示更新失败。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.disableNetwork

disableNetwork(netId: number): void

去使能网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | netId | number | 是 | 网络配置ID。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error(`failed: ${JSON.stringify(error)}`);
}
```

## wifiManager.disableNetwork<sup>23+</sup>

disableNetwork(netId: number, blockDuration: number): void

禁用网络连接，将已连接的网络断开，且在设置的时间范围内无法自动回连。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| netId | number | 是 | 网络配置ID。 |
| blockDuration | number | 是 | 禁用网络时长，单位：秒。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
    let netId = 0;
    let blockDuration = 300;
    wifiManager.disableNetwork(netId, blockDuration);
  } catch (error) {
    console.error(`failed: ${JSON.stringify(error)}`);
  }
```

## wifiManager.removeAllNetwork

removeAllNetwork(): void

移除所有网络配置。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.get5GChannelList<sup>10+</sup>

get5GChannelList(): Array&lt;number&gt;

获取当前设备支持的5G信道列表。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG(仅系统应用可申请)

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | &nbsp;Array&lt;number&gt; | 设备支持的5G信道列表。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```
## wifiManager.getDisconnectedReason<sup>10+</sup>

getDisconnectedReason(): DisconnectedReason

获取最近一次断连原因。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG(仅系统应用可申请)

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [DisconnectedReason](#disconnectedreason-10) | 最近断开的原因 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

try {
  let disconnectedReason = wifiManager.getDisconnectedReason();  
    console.info("disconnectedReason:" + disconnectedReason);
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## DisconnectedReason <sup>10+</sup>

表示WLAN断开原因的枚举，用于诊断网络连接问题和优化连接策略。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DISC_REASON_DEFAULT  | 0 | 默认原因。 |
| DISC_REASON_WRONG_PWD  | 1 | 密码错误。 |
| DISC_REASON_CONNECTION_FULL  | 2 | 路由器的连接数已达到最大数量限制。 |

## wifiManager.startPortalCertification<sup>11+</sup>

startPortalCertification(): void

启动Portal认证流程，用于处理需要Web页面认证的公共WLAN网络（如酒店、机场、咖啡厅等场所的网络）。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.startWifiDetection<sup>21+</sup>

startWifiDetection(): void

发起WiFi网络探测。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID |错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed. |
| 2501001  | Wi-Fi STA disabled. |

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

try {
  wifiManager.startWifiDetection();
}catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.enableHiLinkHandshake<sup>12+</sup>

enableHiLinkHandshake(isHiLinkEnable: boolean, bssid: string, config: WifiDeviceConfig): void

设置是否使能hiLink。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| isHiLinkEnable | boolean | 是 | 是否使能hiLink。true:使能，&nbsp;false:去使能。 |
| bssid | string | 是 | 热点的mac地址，例如：00:11:22:33:44:55。 |
| config | [WifiDeviceConfig](#wifideviceconfig) | 是 | WLAN的配置信息。config.bssid必须和第二个参数bssid保持一致。如果bssidType未指定值，则bssidType默认为随机设备地址类型。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.factoryReset<sup>11+</sup>

factoryReset(): void

**系统接口：** 此接口为系统接口。

重置wifi相关配置并关闭WiFi。

**需要权限：** ohos.permission.SET_WIFI_INFO 和ohos.permission.SET_WIFI_CONFIG(仅系统应用可申请)

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```
## wifiManager.enableHotspot

enableHotspot(): void

使能热点，异步接口，是否打开成功需要注册并监听hotspotStateChange的回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
    console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.disableHotspot

disableHotspot(): void

去使能热点 ，异步接口，是否关闭成功需要注册并监听hotspotStateChange的回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.isHotspotDualBandSupported

isHotspotDualBandSupported(): boolean

检查当前设备的WLAN热点功能是否支持双频段（同时支持2.4GHz和5GHz频段）。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:支持，&nbsp;false:不支持。|

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.isOpenSoftApAllowed<sup>18+</sup>

isOpenSoftApAllowed(): boolean

检查在某些情况下是否能够操作WLAN热点。当飞行模式开启时，如果系统不支持SoftAP和STA共存，也不支持信号桥接，则无法操作热点开关。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:允许，&nbsp;false:不允许。|

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
}catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.setHotspotConfig

setHotspotConfig(config: HotspotConfig): void

设置WLAN热点的配置信息，包括SSID、加密方式、密码、带宽、信道、最大连接STA数量等。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG(仅系统应用可申请)

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config | [HotspotConfig](#hotspotconfig) | 是 | 热点配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## HotspotConfig

热点配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 否 | 否 | 热点的SSID，编码格式为UTF-8。 |
| securityType | [WifiSecurityType](js-apis-wifiManager.md#wifisecuritytype)| 否 | 否 | 加密类型。 |
| band | number | 否 | 否 | 热点的带宽。1: 2.4G, 2: 5G, 3: 双模频段 |
| channel<sup>10+</sup> | number | 否 | 是 | 热点的信道（2.4G：1~14,5G：7~196）。 |
| preSharedKey | string | 否 | 否 | 热点的密钥。 |
| maxConn | number | 否 | 否 | 最大设备连接数。 |
| ipAddress | string | 否 | 是 | DHCP服务器的IP地址。|

## wifiManager.getHotspotConfig

getHotspotConfig(): HotspotConfig

获取WLAN热点的配置信息，包括SSID、加密方式、密码、带宽、信道、最大连接STA数量等。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG(仅系统应用可申请)

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | [HotspotConfig](#hotspotconfig) | 热点的配置信息。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.getStations

getStations(): &nbsp;Array&lt;StationInfo&gt;

获取当前连接到本设备热点的所有设备信息列表。

**系统接口：** 此接口为系统接口。

**需要权限：**

API 9：ohos.permission.GET_WIFI_INFO、ohos.permission.LOCATION、ohos.permission.APPROXIMATELY_LOCATION 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

API 10起：ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| &nbsp;Array&lt;[StationInfo](#stationinfo)&gt; | 连接的设备数组。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的macAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
}catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## StationInfo

接入的设备信息。包含连接到WLAN网络的设备详细信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| name | string | 否 | 否 | 设备名称。 |
| macAddress | string | 否 | 否 | MAC地址。 |
| macAddressType<sup>10+</sup> | [DeviceAddressType](js-apis-wifiManager.md#deviceaddresstype10) | 否 | 是 | MAC地址类型。 |
| ipAddress | string | 否 | 否 | IP地址。 |

## wifiManager.addHotspotBlockList<sup>11+</sup>

addHotspotBlockList(stationInfo: StationInfo): void

将设备添加到热点的阻止连接设备列表中，列表中的设备将不能访问热点。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| stationInfo | [StationInfo](#stationinfo) | 是 | 将添加到热点的阻止列表中的设备。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.delHotspotBlockList<sup>11+</sup>

delHotspotBlockList(stationInfo: StationInfo): void

将设备从热点的阻止列表中删除。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| stationInfo | [StationInfo](#stationinfo) | 是 | 将从热点的阻止列表中删除的设备。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
 ```

## wifiManager.getHotspotBlockList<sup>11+</sup>

getHotspotBlockList(): Array&lt;StationInfo&gt;

获取当前WLAN热点的黑名单设备列表。该接口返回被热点拉黑的设备信息列表，仅在设备作为热点(AP)模式下有效。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_HOTSPOT，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| &nbsp;Array&lt;[StationInfo](#stationinfo)&gt; | 热点的阻止列表。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.deletePersistentGroup

deletePersistentGroup(netId: number): void

删除指定网络ID的永久WLAN组配置。该接口用于清除已保存的WLAN网络配置信息，使其不再自动连接。

- 根据网络ID删除之前与P2P设备建立的永久组信息，后续与该P2P设备进行P2P连接时需要重新进行P2P协商。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**


  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | netId | number | 是 | 组的ID。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
}catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```

## wifiManager.getP2pGroups

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
| Promise&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](js-apis-wifiManager.md#wifip2pgroupinfo)&gt;&nbsp;&gt; | Promise对象。表示所有群组信息。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

wifiManager.getP2pGroups((err: BusinessError, data:wifiManager.WifiP2pGroupInfo[]) => {
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


## wifiManager.getP2pGroups

getP2pGroups(callback: AsyncCallback&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;): void

获取创建的所有P2P群组信息，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：**

API 9：ohos.permission.GET_WIFI_INFO、ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](js-apis-wifiManager.md#wifip2pgroupinfo)&gt;&gt; | 是 | 回调函数。当操作成功时，err为0，data表示所有群组信息。如果err为非0，表示处理出现错误。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限，则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

## wifiManager.setDeviceName

setDeviceName(devName: string): void

设置设备名称。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | devName | string | 是 | 设备名称。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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
} catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```


## wifiManager.on('streamChange')

on(type: 'streamChange', callback: Callback&lt;number&gt;): void

注册WLAN流变更事件，在业务退出时，要调用off(type: 'streamChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"streamChange"字符串。 |
| callback | Callback&lt;number&gt; | 是 | 状态改变回调函数，返回0:无，1:向下，2:向上，3:双向。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('streamChange')

off(type: 'streamChange', callback?: Callback&lt;number&gt;): void

取消注册WIFI流变更事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_CONNECTION

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"streamChange"字符串。 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数，返回0:无，1:向下，2:向上，3:双向。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

let recvStreamChangeFunc = (result:number) => {
    console.info("Receive stream change event: " + result);
}

// Register event
wifiManager.on("streamChange", recvStreamChangeFunc);

// Unregister event
wifiManager.off("streamChange", recvStreamChangeFunc);

```

## wifiManager.on('deviceConfigChange')

on(type: 'deviceConfigChange', callback: Callback&lt;number&gt;): void

注册WLAN设备配置更改事件，在业务退出时，要调用off(type: 'deviceConfigChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"deviceConfigChange"字符串。 |
| callback | Callback&lt;number&gt; | 是 | 状态改变回调函数，返回值为 0: 添加配置。1: 更改配置。2: 删除配置。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('deviceConfigChange')

off(type: 'deviceConfigChange', callback?: Callback&lt;number&gt;): void

取消注册WLAN设备配置更改事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"deviceConfigChange"字符串。 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数，返回值为 0: 添加配置。1: 更改配置。2: 删除配置。|

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

let recvDeviceConfigChangeFunc = (result:number) => {
    console.info("Receive device config change event: " + result);
}

// Register event
wifiManager.on("deviceConfigChange", recvDeviceConfigChangeFunc);

// Unregister event
wifiManager.off("deviceConfigChange", recvDeviceConfigChangeFunc);

```

## wifiManager.on('hotspotStaJoin')

on(type: 'hotspotStaJoin', callback: Callback&lt;StationInfo&gt;): void

注册WLAN热点STA加入事件，在业务退出时，要调用off(type: 'hotspotStaJoin', callback?: Callback&lt;StationInfo&gt;)接口去掉之前的注册回调。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"hotspotStaJoin"字符串。 |
| callback | Callback&lt;[StationInfo](#stationinfo)&gt; | 是 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

## wifiManager.off('hotspotStaJoin')

off(type: 'hotspotStaJoin', callback?: Callback&lt;StationInfo&gt;): void

取消注册WLAN热点的STA加入事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"hotspotStaJoin"字符串。 |
| callback | Callback&lt;[StationInfo](#stationinfo)&gt; | 否 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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

## wifiManager.on('hotspotStaLeave')

on(type: 'hotspotStaLeave', callback: Callback&lt;StationInfo&gt;): void

注册WLAN热点STA离开事件，在业务退出时，要调用off(type: 'hotspotStaLeave', callback?: Callback&lt;StationInfo&gt;)接口去掉之前的注册回调。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStaLeave"字符串。 |
  | callback | Callback&lt;StationInfo&gt; | 是 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

## wifiManager.off('hotspotStaLeave')

off(type: 'hotspotStaLeave', callback?: Callback&lt;StationInfo&gt;): void

取消注册WLAN热点STA离开事件。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"hotspotStaLeave"字符串。 |
| callback | Callback&lt;StationInfo&gt; | 否 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
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

## WifiScanInfo

提供WLAN扫描的相关信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| isHiLinkProNetwork<sup>20+</sup> | boolean | 否 | 是 | 是否是HiLinkPro网络。true表示是HiLinkPro网络，false表示不是HiLinkPro网络。<br /> **系统接口：** 此接口为系统接口。 |

## wifiManager.isRandomMacDisabled<sup>21+</sup>

isRandomMacDisabled(): boolean

随机MAC地址是否被禁用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.GET_WIFI_CONFIG，仅系统应用可用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:禁用随机MAC地址; false:未禁用随机MAC地址。|

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed. |

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

try {
  let ret = wifiManager.isRandomMacDisabled();
  console.info("result:" + ret);
}catch (error) {
  console.error("failed:" + JSON.stringify(error));
}
```
## WifiCapability

wifi支持的能力。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.STA

**模型约束：** 此接口仅可在Stage模型下使用。


| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| WIFI_AUTO_ENABLE | 0 | wifi自动打开能力。 |


## wifiManager.setWifiCapability

setWifiCapability(capability: WifiCapability, enable: boolean): void

设置wifi能力。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用

**系统能力：** SystemCapability.Communication.WiFi.STA

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| capability | [WifiCapability](#wificapability) | 是 | wifi能力枚举。 |
| enable | boolean | 是 | 是否使能wifi能力，true表示使能，false表示不使能。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed. |

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

wifiManager.setWifiCapability(wifiManager.WifiCapability.WIFI_AUTO_ENABLE, true);

```

## wifiManager.getWifiCapability

getWifiCapability(capability: WifiCapability): boolean

获取wifi支持的能力。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.MANAGE_WIFI_CONNECTION，仅系统应用可用

**系统能力：** SystemCapability.Communication.WiFi.STA

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| capability | [WifiCapability](#wificapability)| 是 | wifi能力枚举。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:已使能，&nbsp;false:未使能。 |

**错误码：**

以下错误码的详细介绍请参见[Wi-Fi错误码](errorcode-wifi.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed. |

**示例：**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

let result = wifiManager.getWifiCapability(wifiManager.WifiCapability.WIFI_AUTO_ENABLE);
console.info("result:" + result);

```
