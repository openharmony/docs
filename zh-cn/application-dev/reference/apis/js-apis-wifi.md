# WLAN

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import wifi from '@ohos.wifi';
```


## wifi.isWifiActive

isWifiActive(): boolean

查询WLAN是否已激活。

- 返回值：
  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已激活，&nbsp;false:未激活。 |


## wifi.scan

scan(): boolean

启动WLAN扫描。

- 返回值：
  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:扫描操作成功，&nbsp;false:扫描操作执行失败。 |


## wifi.getScanInfos

getScanInfos(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt;

获取扫描结果，使用promise方式作为异步方法。

- 返回值：
  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&nbsp;&gt; | 返回扫描到的热点列表。 |


## wifi.getScanInfos

getScanInfos(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void

获取扫描结果，使用callback方式作为异步方法。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&gt; | 是 | 扫描到的热点列表结果回调函数。 |

- 示例
  ```
  import wifi from '@ohos.wifi';
  
  wifi.getScanInfos(result => {
      var len = Object.keys(result).length;
      console.log("wifi received scan info call back: " + len);
      for (var i = 0; i < len; ++i) {
          console.info("ssid: " + result[i].ssid);
          console.info("bssid: " + result[i].bssid);
          console.info("securityType: " + result[i].securityType);
          console.info("rssi: " + result[i].rssi);
          console.info("band: " + result[i].band);
          console.info("frequency: " + result[i].frequency);
          console.info("timestamp: " + result[i].timestamp);
      }
  });
  
  wifi.getScanInfos().then(result => {
      var len = Object.keys(result).length;
      console.log("wifi received scan info promise: " + len);
      for (var i = 0; i < len; ++i) {
          console.info("ssid: " + result[i].ssid);
          console.info("bssid: " + result[i].bssid);
          console.info("securityType: " + result[i].securityType);
          console.info("rssi: " + result[i].rssi);
          console.info("band: " + result[i].band);
          console.info("frequency: " + result[i].frequency);
          console.info("timestamp: " + result[i].timestamp);
      }
  });
  ```


## WifiScanInfo

WLAN热点信息。

| **参数名** | **类型** | **读写属性** | **说明** |
| -------- | -------- | -------- | -------- |
| ssid | string | 只读 | 热点的SSID，编码格式为UTF-8。 |
| bssid | string | 只读 | 热点的BSSID。 |
| securityType | [WifiSecurityType](#wifisecuritytype) | 只读 | WLAN加密类型。 |
| rssi | number | 只读 | 热点的信号强度(dBm)。 |
| band | number | 只读 | WLAN接入点的频段。 |
| frequency | number | 只读 | WLAN接入点的频率。 |
| timestamp | number | 只读 | 时间戳。 |


## WifiSecurityType

表示加密类型的枚举。

| **名称** | **默认值** | **说明** |
| -------- | -------- | -------- |
| WIFI_SEC_TYPE_INVALID | 0 | 无效加密类型。 |
| WIFI_SEC_TYPE_OPEN | 1 | 开放加密类型。 |
| WIFI_SEC_TYPE_WEP | 2 | Wired&nbsp;Equivalent&nbsp;Privacy&nbsp;(WEP)加密类型。 |
| WIFI_SEC_TYPE_PSK | 3 | Pre-shared&nbsp;key&nbsp;(PSK)加密类型。 |
| WIFI_SEC_TYPE_SAE | 4 | Simultaneous&nbsp;Authentication&nbsp;of&nbsp;Equals&nbsp;(SAE)加密类型。 |


## wifi.getSignalLevel

getSignalLevel(rssi: number, band: number): number

查询WLAN信号强度。

- 参数：
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | rssi | number | 是 | 热点的信号强度(dBm)。 |
  | band | number | 是 | WLAN接入点的频段。 |

- 返回值：
  | **类型** | **说明** |
  | -------- | -------- |
  | number | 信号强度，取值范围为[0,&nbsp;4]。 |


## wifi.getIpInfo<sup>7+</sup>

getIpInfo(): IpInfo

获取IP信息。

- 返回值：
  | **类型** | **说明** |
  | -------- | -------- |
  | [IpInfo](#ipinfo) | 返回IP信息。 |


## IpInfo

IP信息。

| **参数名** | **类型** | **读写属性** | **说明** |
| -------- | -------- | -------- | -------- |
| ipAddress | number | 只读 | IP地址。 |
| gateway | number | 只读 | 网关。 |
| netmask | number | 只读 | 掩码。 |
| primaryDns | number | 只读 | 主DNS服务器IP地址。 |
| secondDns | number | 只读 | 备DNS服务器IP地址。 |
| serverIp | number | 只读 | DHCP服务端IP地址。 |
| leaseDuration | number | 只读 | IP地址租用时长。 |


## wifi.isConnected<sup>7+</sup>

isConnected(): boolean

查询WLAN是否已连接。

- 返回值：
  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已连接，&nbsp;false:未连接。 |


## wifi.getLinkedInfo<sup>7+</sup>

getLinkedInfo(): Promise&lt;WifiLinkedInfo&gt;

获取WLAN连接信息，使用promise方式作为异步方法。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[WifiLinkedInfo](#wifilinkedinfo)&gt; | 返回WLAN连接的相关信息。 |


## wifi.getLinkedInfo<sup>7+</sup>

getLinkedInfo(callback: AsyncCallback&lt;WifiLinkedInfo&gt;): void

获取WLAN连接信息，使用callback方式作为异步方法。

- 参数
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiLinkedInfo](#wifilinkedinfo)&gt; | 是 | 获取WLAN连接信息结果回调函数。 |

- 示例
  ```
  import wifi from '@ohos.wifi';
  
  wifi.getLinkedInfo(data => {
      console.info("get wifi linked info [callback]: " + JSON.stringify(data));
  });
  
  wifi.getLinkedInfo().then(data => {
      console.info("get wifi linked info [promise]: " + JSON.stringify(data));
  }).catch(error => {
      console.info("linked info promise then error");
  });
  ```


## WifiLinkedInfo

提供WLAN连接的相关信息。

| 参数名 | 类型 | 读写属性 | 说明 |
| -------- | -------- | -------- | -------- |
| ssid | string | 只读 | 热点的SSID，编码格式为UTF-8。 |
| bssid | string | 只读 | 热点的BSSID。 |
| rssi | number | 只读 | 热点的信号强度(dBm)。 |
| band | number | 只读 | WLAN接入点的频段。 |
| linkSpeed | number | 只读 | WLAN接入点的速度。 |
| frequency | number | 只读 | WLAN接入点的频率。 |
| isHidden | boolean | 只读 | WLAN接入点是否是隐藏网络。 |
| isRestricted | boolean | 只读 | WLAN接入点是否限制数据量。 |
| macAddress | string | 只读 | 设备的MAC地址。 |
| ipAddress | number | 只读 | WLAN连接的IP地址。 |
| connState | ConnState | 只读 | WLAN连接状态。 |


## ConnState

表示WLAN连接状态的枚举。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| SCANNING | 0 | 设备正在搜索可用的AP。 |
| CONNECTING | 1 | 正在建立WLAN连接。 |
| AUTHENTICATING | 2 | WLAN连接正在认证中。 |
| OBTAINING_IPADDR | 3 | 正在获取WLAN连接的IP地址。 |
| CONNECTED | 4 | WLAN连接已建立。 |
| DISCONNECTING | 5 | WLAN连接正在断开。 |
| DISCONNECTED | 6 | WLAN连接已断开。 |
| UNKNOWN | 7 | WLAN连接建立失败。 |


## wifi.getCountryCode<sup>7+</sup>

getCountryCode(): string

获取国家码信息。

- 返回值：
  | **类型** | **说明** |
  | -------- | -------- |
  | string | 国家码。 |


## wifi.isFeatureSupported<sup>7+</sup>

isFeatureSupported(featureId: number): boolean

判断设备是否支持相关WLAN特性。

- 参数：
  | **参数名** | **类型** | 必填 | **说明** |
  | -------- | -------- | -------- | -------- |
  | featureId | number | 是 | 特性ID值。 |

- 返回值：
  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:支持，&nbsp;false:不支持。 |

- 特性ID值枚举。
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


## wifi.on('wifiStateChange')<sup>7+</sup>

on(type: "wifiStateChange", callback: Callback&lt;number&gt;): void

注册WLAN状态改变事件。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiStateChange"字符串 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

- 状态改变事件的枚举。
  | **枚举值** | **说明** |
  | -------- | -------- |
  | 0 | 未激活。 |
  | 1 | 已激活。 |
  | 2 | 激活中。 |
  | 3 | 去激活中。 |


## wifi.off('wifiStateChange')<sup>7+</sup>

off(type: "wifiStateChange", callback?: Callback&lt;number&gt;): void

取消注册WLAN状态改变事件。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiStateChange"字符串 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |

- 示例
  ```
  import wifi from '@ohos.wifi';
  import { EventListener } from '@ohos.wifi';
  
  var WIFI_POWER_STATE = "wifiStateChange";
  var listener = new EventListener();
  
  var recvPowerNotifyFunc = result => {
      console.info("power state receive event: " + result);
  }
  
  // Register event
  listener.on(WIFI_POWER_STATE, recvPowerNotifyFunc);
  
  // Unregister event
  listener.off(WIFI_POWER_STATE, recvPowerNotifyFunc);
  ```


## wifi.on('wifiConnectionChange')<sup>7+</sup>

on(type: "wifiConnectionChange", callback: Callback&lt;number&gt;): void

注册WLAN连接状态改变事件。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiConnectionChange"字符串 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

- 连接状态改变事件的枚举。
  | **枚举值** | **说明** |
  | -------- | -------- |
  | 0 | 已断开。 |
  | 1 | 已连接。 |


## wifi.off('wifiConnectionChange')<sup>7+</sup>

off(type: "wifiConnectionChange", callback?: Callback&lt;number&gt;): void

取消注册WLAN连接状态改变事件。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiConnectionChange"字符串 |
  | callback | Callback&lt;number&gt; | 否 | 连接状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('wifiScanStateChange')<sup>7+</sup>

on(type: "wifiScanStateChange", callback: Callback&lt;number&gt;): void

注册扫描状态改变事件。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiScanStateChange"字符串 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

- 扫描状态改变事件的枚举。
  | **枚举值** | **说明** |
  | -------- | -------- |
  | 0 | 扫描失败。 |
  | 1 | 扫描成功。 |


## wifi.off('wifiScanStateChange')<sup>7+</sup>

off(type: "wifiScanStateChange", callback?: Callback&lt;number&gt;): void

取消注册扫描状态改变事件。

- 参数

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"wifiScanStateChange"字符串 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('wifiRssiChange')<sup>7+</sup>

on(type: "wifiRssiChange", callback: Callback&lt;number&gt;): void

注册RSSI状态改变事件。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiRssiChange"字符串 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数，返回以dBm为单位的RSSI值。 |


## wifi.off('wifiRssiChange')<sup>7+</sup>

off(type: "wifiRssiChange", callback?: Callback&lt;number&gt;): void

取消注册RSSI状态改变事件。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiRssiChange"字符串 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |


## wifi.on('hotspotStateChange')<sup>7+</sup>

on(type: "hotspotStateChange", callback: Callback&lt;number&gt;): void

注册热点状态改变事件。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStateChange"字符串 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

- 热点状态改变事件的枚举。
  | **枚举值** | **说明** |
  | -------- | -------- |
  | 0 | 未激活。 |
  | 1 | 已激活。 |
  | 2 | 激活中。 |
  | 3 | 去激活中。 |


## wifi.off('hotspotStateChange')<sup>7+</sup>

off(type: "hotspotStateChange", callback?: Callback&lt;number&gt;): void

取消注册热点状态改变事件。

- 参数
  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"hotspotStateChange"字符串 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将去注册该事件关联的所有回调函数。 |
