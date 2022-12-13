# @ohos.wifi (WLAN)

该模块主要提供WLAN基础功能、P2P（peer-to-peer）功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
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


## wifi.isWifiActive

isWifiActive(): boolean

查询WLAN是否已使能。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已使能，&nbsp;false:未使能。 |


## wifi.scan

scan(): boolean

启动WLAN扫描。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:扫描操作执行成功，&nbsp;false:扫描操作执行失败。 |


## wifi.getScanInfos

getScanInfos(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt;

获取扫描结果，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 (ohos.permission.GET_WIFI_PEERS_MAC 或 ohos.permission.LOCATION)

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&nbsp;&gt; | Promise对象。返回扫描到的热点列表。 |


## wifi.getScanInfos

getScanInfos(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void

获取扫描结果，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 (ohos.permission.GET_WIFI_PEERS_MAC 或 ohos.permission.LOCATION)

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&gt; | 是 | 回调函数。当成功时，err为0，data为扫描到的热点；否则err为非0值，data为空。 |

**示例：**
  ```js
  import wifi from '@ohos.wifi';
  
  wifi.getScanInfos((err, result) => {
      if (err) {
          console.error("get scan info error");
          return;
      }
  
      var len = Object.keys(result).length;
      console.log("wifi received scan info: " + len);
      for (var i = 0; i < len; ++i) {
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
      var len = Object.keys(result).length;
      console.log("wifi received scan info: " + len);
      for (var i = 0; i < len; ++i) {
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
| ssid | string | 是 | 否 | 热点的SSID，编码格式为UTF-8。 |
| bssid | string | 是 | 否 | 热点的BSSID。 |
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


## wifi.getScanInfosSync<sup>9+</sup>

getScanInfosSync(): &nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;

获取扫描结果，使用同步方式返回结果。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 (ohos.permission.GET_WIFI_PEERS_MAC 或 ohos.permission.LOCATION)

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | &nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt; | 扫描结果数组。 |


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

## WifiDeviceConfig

WLAN配置信息。

**系统能力：** SystemCapability.Communication.WiFi.STA


| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，编码格式为UTF-8。 |
| bssid | string | 是 | 否 | 热点的BSSID。 |
| preSharedKey | string | 是 | 否 | 热点的密钥。 |
| isHiddenSsid | boolean | 是 | 否 | 是否是隐藏网络。 |
| securityType | [WifiSecurityType](#wifisecuritytype) | 是 | 否 | 加密类型。 |
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


## wifi.connectToDevice

connectToDevice(config: WifiDeviceConfig): boolean

连接到指定网络。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.SET_WIFI_INFO 和 ohos.permission.SET_WIFI_CONFIG 和 ohos.permissio.MANAGE_WIFI_CONNECTION，仅系统应用可用。

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
  ```js
  import wifi from '@ohos.wifi';
  
  wifi.getLinkedInfo((err, data) => {
      if (err) {
          console.error("get linked info error");
          return;
      }
      console.info("get wifi linked info: " + JSON.stringify(data));
  });
  
  wifi.getLinkedInfo().then(data => {
      console.info("get wifi linked info: " + JSON.stringify(data));
  }).catch(error => {
      console.info("get linked info error");
  });
  ```


## WifiLinkedInfo

提供WLAN连接的相关信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，编码格式为UTF-8。 |
| bssid | string | 是 | 否 | 热点的BSSID。 |
| networkId | number | 是 | 否 | 网络配置ID。 <br /> **系统接口：** 此接口为系统接口。 |
| rssi | number | 是 | 否 | 热点的信号强度(dBm)。 |
| band | number | 是 | 否 | WLAN接入点的频段。 |
| linkSpeed | number | 是 | 否 | WLAN接入点的速度。 |
| frequency | number | 是 | 否 | WLAN接入点的频率。 |
| isHidden | boolean | 是 | 否 | WLAN接入点是否是隐藏网络。 |
| isRestricted | boolean | 是 | 否 | WLAN接入点是否限制数据量。 |
| chload | number | 是 | 否 | 连接负载，值越大表示负载约高。 <br /> **系统接口：** 此接口为系统接口。 |
| snr | number | 是 | 否 | 信噪比。 <br /> **系统接口：** 此接口为系统接口。 |
| macAddress | string | 是 | 否 | 设备的MAC地址。 |
| ipAddress | number | 是 | 否 | WLAN连接的IP地址。 |
| suppState | [SuppState](#suppstate) | 是 | 否 | 请求状态。 <br /> **系统接口：** 此接口为系统接口。 |
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


## wifi.isConnected<sup>7+</sup>

isConnected(): boolean

查询WLAN是否已连接。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已连接，&nbsp;false:未连接。 |


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


## wifi.getIpInfo<sup>7+</sup>

getIpInfo(): IpInfo

获取IP信息。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | [IpInfo](#ipinfo7) | IP信息。 |


## IpInfo<sup>7+</sup>

IP信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

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


## HotspotConfig<sup>7+</sup>

热点配置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，编码格式为UTF-8。 |
| securityType | [WifiSecurityType](#wifisecuritytype) | 是 | 否 | 加密类型。 |
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


## StationInfo<sup>7+</sup>

接入的设备信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| name | string | 是 | 否 | 设备名称。 |
| macAddress | string | 是 | 否 | MAC地址。 |
| ipAddress | string | 是 | 否 | IP地址。 |


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
  ```js
  import wifi from '@ohos.wifi';
  
  var recvP2pConnectionChangeFunc = result => {
      console.info("p2p connection change receive event: " + JSON.stringify(result));
      wifi.getP2pLinkedInfo((err, data) => {
          if (err) {
              console.error('failed to get getP2pLinkedInfo: ' + JSON.stringify(err));
              return;
          }
          console.info("get getP2pLinkedInfo: " + JSON.stringify(data));
      });
  }
  wifi.on("p2pConnectionChange", recvP2pConnectionChangeFunc);
  
  var recvP2pDeviceChangeFunc = result => {
      console.info("p2p device change receive event: " + JSON.stringify(result));
  }
  wifi.on("p2pDeviceChange", recvP2pDeviceChangeFunc);
  
  var recvP2pPeerDeviceChangeFunc = result => {
      console.info("p2p peer device change receive event: " + JSON.stringify(result));
      wifi.getP2pPeerDevices((err, data) => {
          if (err) {
              console.error('failed to get peer devices: ' + JSON.stringify(err));
              return;
          }
          console.info("get peer devices: " + JSON.stringify(data));
          var len = Object.keys(data).length;
          for (var i = 0; i < len; ++i) {
              if (data[i].deviceName === "my_test_device") {
                  console.info("p2p connect to test device: " + data[i].deviceAddress);
                  var config = {
                      "deviceAddress":data[i].deviceAddress,
                      "netId":-2,
                      "passphrase":"",
                      "groupName":"",
                      "goBand":0,
                  }
                  wifi.p2pConnect(config);
              }
          }
      });
  }
  wifi.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
  
  var recvP2pPersistentGroupChangeFunc = () => {
      console.info("p2p persistent group change receive event");
  
      wifi.getCurrentGroup((err, data) => {
          if (err) {
              console.error('failed to get current group: ' + JSON.stringify(err));
              return;
          }
          console.info("get current group: " + JSON.stringify(data));
      });
  }
  wifi.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
  
  setTimeout(function() {wifi.off("p2pConnectionChange", recvP2pConnectionChangeFunc);}, 125 * 1000);
  setTimeout(function() {wifi.off("p2pDeviceChange", recvP2pDeviceChangeFunc);}, 125 * 1000);
  setTimeout(function() {wifi.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);}, 125 * 1000);
  setTimeout(function() {wifi.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);}, 125 * 1000);
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


## wifi.startDiscoverDevices<sup>8+</sup>

startDiscoverDevices(): boolean

开始发现设备。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:操作执行成功，&nbsp;false:操作执行失败。 |


## wifi.stopDiscoverDevices<sup>8+</sup>

stopDiscoverDevices(): boolean

停止发现设备。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | true:操作执行成功，操作执行失败。 |


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


## wifi.on('wifiStateChange')<sup>7+</sup>

on(type: "wifiStateChange", callback: Callback&lt;number&gt;): void

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

off(type: "wifiStateChange", callback?: Callback&lt;number&gt;): void

取消注册WLAN状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |

**示例：**
  ```js
  import wifi from '@ohos.wifi';
  
  var recvPowerNotifyFunc = result => {
      console.info("Receive power state change event: " + result);
  }
  
  // Register event
  wifi.on("wifiStateChange", recvPowerNotifyFunc);
  
  // Unregister event
  wifi.off("wifiStateChange", recvPowerNotifyFunc);
  ```


## wifi.on('wifiConnectionChange')<sup>7+</sup>

on(type: "wifiConnectionChange", callback: Callback&lt;number&gt;): void

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

off(type: "wifiConnectionChange", callback?: Callback&lt;number&gt;): void

取消注册WLAN连接状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiConnectionChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 连接状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('wifiScanStateChange')<sup>7+</sup>

on(type: "wifiScanStateChange", callback: Callback&lt;number&gt;): void

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

off(type: "wifiScanStateChange", callback?: Callback&lt;number&gt;): void

取消注册扫描状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"wifiScanStateChange"字符串。 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('wifiRssiChange')<sup>7+</sup>

on(type: "wifiRssiChange", callback: Callback&lt;number&gt;): void

注册RSSI状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiRssiChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数，返回以dBm为单位的RSSI值。 |


## wifi.off('wifiRssiChange')<sup>7+</sup>

off(type: "wifiRssiChange", callback?: Callback&lt;number&gt;): void

取消注册RSSI状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiRssiChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('hotspotStateChange')<sup>7+</sup>

on(type: "hotspotStateChange", callback: Callback&lt;number&gt;): void

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


## wifi.off('hotspotStateChange')<sup>7+</sup>

off(type: "hotspotStateChange", callback?: Callback&lt;number&gt;): void

取消注册热点状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('p2pStateChange')<sup>8+</sup>

on(type: "p2pStateChange", callback: Callback&lt;number&gt;): void

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

off(type: "p2pStateChange", callback?: Callback&lt;number&gt;): void

取消注册P2P开关状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


  ## wifi.on('p2pConnectionChange')<sup>8+</sup>

on(type: "p2pConnectionChange", callback: Callback&lt;WifiP2pLinkedInfo&gt;): void

注册P2P连接状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pConnectionChange"字符串。 |
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | 是 | 状态改变回调函数。 |


## wifi.off('p2pConnectionChange')<sup>8+</sup>

off(type: "p2pConnectionChange", callback?: Callback&lt;WifiP2pLinkedInfo&gt;): void

取消注册P2P连接状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pConnectionChange"字符串。 |
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('p2pDeviceChange')<sup>8+</sup>

on(type: "p2pDeviceChange", callback: Callback&lt;WifiP2pDevice&gt;): void

注册P2P设备状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice8)&gt; | 是 | 状态改变回调函数。 |


## wifi.off('p2pDeviceChange')<sup>8+</sup>

off(type: "p2pDeviceChange", callback?: Callback&lt;WifiP2pDevice&gt;): void

取消注册P2P设备状态改变事件。

**需要权限：** ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice8)&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('p2pPeerDeviceChange')<sup>8+</sup>

on(type: "p2pPeerDeviceChange", callback: Callback&lt;WifiP2pDevice[]&gt;): void

注册P2P对端设备状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pPeerDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | 是 | 状态改变回调函数。 |


## wifi.off('p2pPeerDeviceChange')<sup>8+</sup>

off(type: "p2pPeerDeviceChange", callback?: Callback&lt;WifiP2pDevice[]&gt;): void

取消注册P2P对端设备状态改变事件。

**需要权限：** ohos.permission.LOCATION

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pPeerDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('p2pPersistentGroupChange')<sup>8+</sup>

on(type: "p2pPersistentGroupChange", callback: Callback&lt;void&gt;): void

注册P2P永久组状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pPersistentGroupChange"字符串。 |
  | callback | Callback&lt;void&gt; | 是 | 状态改变回调函数。 |


## wifi.off('p2pPersistentGroupChange')<sup>8+</sup>

off(type: "p2pPersistentGroupChange", callback?: Callback&lt;void&gt;): void

取消注册P2P永久组状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pPersistentGroupChange"字符串。 |
  | callback | Callback&lt;void&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('p2pDiscoveryChange')<sup>8+</sup>

on(type: "p2pDiscoveryChange", callback: Callback&lt;number&gt;): void

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

off(type: "p2pDiscoveryChange", callback?: Callback&lt;number&gt;): void

取消注册发现设备状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDiscoveryChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |

