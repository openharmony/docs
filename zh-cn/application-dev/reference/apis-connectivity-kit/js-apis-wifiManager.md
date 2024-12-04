# @ohos.wifiManager (WLAN)
该模块主要提供WLAN基础功能（无线接入、无线加密、无线漫游等）、P2P（peer-to-peer）服务的基础功能和WLAN消息通知的相应服务，让应用可以通过WLAN和其他设备互联互通。

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { wifiManager } from '@kit.ConnectivityKit';
```


## wifiManager.isWifiActive<sup>9+</sup>

isWifiActive(): boolean

查询WLAN开关是否已使能。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已使能，&nbsp;false:未使能。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let isWifiActive = wifiManager.isWifiActive();
		console.info("isWifiActive:" + isWifiActive);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.scan<sup>9+</sup><sup>(deprecated)</sup>

scan(): void

启动WLAN扫描，使用前先使能WLAN。

> **说明：**
> 从 API version 9开始支持，从API version 10开始废弃。替代接口仅向系统应用开放。

**需要权限：** ohos.permission.SET_WIFI_INFO、ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力：** SystemCapability.Communication.WiFi.STA

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.scan();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```


## wifiManager.getScanResults<sup>9+</sup><sup>(deprecated)</sup>

getScanResults(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt;

获取扫描结果，使用Promise异步回调。

> **说明：**
> 从 API version 9开始支持，从API version 10开始废弃。建议使用[wifiManager.getScanInfoList](#wifimanagergetscaninfolist10)代替。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 (ohos.permission.GET_WIFI_PEERS_MAC 或(ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION))
ohos.permission.GET_WIFI_PEERS_MAC权限仅系统应用可申请。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| Promise&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo9)&gt;&nbsp;&gt; | Promise对象。返回扫描到的热点列表。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.getScanResults<sup>9+</sup><sup>(deprecated)</sup>

getScanResults(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void

获取扫描结果，使用callback异步回调。

> **说明：**
> 从 API version 9开始支持，从API version 10开始废弃。建议使用[wifiManager.getScanInfoList](#wifimanagergetscaninfolist10)代替。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 (ohos.permission.GET_WIFI_PEERS_MAC 或 (ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION))
ohos.permission.GET_WIFI_PEERS_MAC权限仅系统应用可申请。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo9)&gt;&gt; | 是 | 回调函数。当成功时，err为0，data为扫描到的热点；否则err为非0值，data为空。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  wifiManager.getScanResults((err, result) => {
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
  
  wifiManager.getScanResults().then(result => {
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
  }).catch((err:number) => {
      console.error("failed:" + JSON.stringify(err));
  });
```

## wifiManager.getScanResultsSync<sup>9+</sup><sup>(deprecated)</sup>

getScanResultsSync(): &nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo9)&gt;

获取扫描结果，使用同步方式返回结果。

> **说明：**
> 从 API version 9开始支持，从API version 10开始废弃。建议使用[wifiManager.getScanInfoList](#wifimanagergetscaninfolist10)代替。

**需要权限：** ohos.permission.GET_WIFI_INFO 和 (ohos.permission.GET_WIFI_PEERS_MAC 或 (ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION))
ohos.permission.GET_WIFI_PEERS_MAC权限仅系统应用可申请。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| &nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo9)&gt; | 扫描结果数组。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

## wifiManager.getScanInfoList<sup>10+</sup>

getScanInfoList(): Array&lt;WifiScanInfo&gt;

获取扫描结果。

**需要权限：** ohos.permission.GET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| Array&lt;[WifiScanInfo](#wifiscaninfo9)&gt; | 返回扫描到的热点列表。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限（仅系统应用可申请），则返回结果中的bssid为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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
				console.info("supportedWifiCategory: " + scanInfoList[i].supportedWifiCategory);
				console.info("isHiLinkNetwork: " + scanInfoList[i].isHiLinkNetwork);
			}
		}	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
	
```

## WifiScanInfo<sup>9+</sup>

WLAN热点信息。

**系统能力：** SystemCapability.Communication.WiFi.STA


| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，最大长度为32字节，编码格式为UTF-8。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| bssid | string | 是 | 否 | 热点的BSSID，例如：00:11:22:33:44:55。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| bssidType<sup>10+</sup>| [DeviceAddressType](#deviceaddresstype10) | 是 | 否 | 热点的BSSID类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| capabilities | string | 是 | 否 | 热点能力。 |
| securityType | [WifiSecurityType](#wifisecuritytype9) | 是 | 否 | WLAN加密类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| rssi | number | 是 | 否 | 热点的信号强度(dBm)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| band | number | 是 | 否 | WLAN接入点的频段，1表示2.4GHZ；2表示5GHZ。 |
| frequency | number | 是 | 否 | WLAN接入点的频率。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| channelWidth | number | 是 | 否 | WLAN接入点的带宽，具体定义参见[WifiChannelWidth](#wifichannelwidth9)。 |
| centerFrequency0 | number | 是 | 否 | 热点的中心频率。 |
| centerFrequency1 | number | 是 | 否 | 热点的中心频率。如果热点使用两个不重叠的WLAN信道，则返回两个中心频率，分别用centerFrequency0和centerFrequency1表示。 |
| infoElems | Array&lt;[WifiInfoElem](#wifiinfoelem9)&gt; | 是 | 否 | 信息元素。 |
| timestamp | number | 是 | 否 | 时间戳。 |
| supportedWifiCategory<sup>12+</sup> | [WifiCategory](#wificategory12) | 是 | 否 | 热点支持的最高Wi-Fi级别。 |
| isHiLinkNetwork<sup>12+</sup> | boolean | 是 | 否| 热点是否支持hiLink，true:支持，&nbsp;false:不支持。 |

## DeviceAddressType<sup>10+</sup>

Wi-Fi 设备地址（MAC/bssid）类型。

**系统能力：** SystemCapability.Communication.WiFi.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| RANDOM_DEVICE_ADDRESS | 0 | 随机设备地址。 |
| REAL_DEVICE_ADDRESS | 1 | 真实设备地址。 |

## WifiSecurityType<sup>9+</sup>

表示加密类型的枚举。

**系统能力：** SystemCapability.Communication.WiFi.Core


| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| WIFI_SEC_TYPE_INVALID | 0 | 无效加密类型。 |
| WIFI_SEC_TYPE_OPEN | 1 | 开放加密类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| WIFI_SEC_TYPE_WEP | 2 | Wired&nbsp;Equivalent&nbsp;Privacy&nbsp;(WEP)加密类型。候选网络(添加网络配置信息)配置不支持该加密类型。 |
| WIFI_SEC_TYPE_PSK | 3 | Pre-shared&nbsp;key&nbsp;(PSK)加密类型。 |
| WIFI_SEC_TYPE_SAE | 4 | Simultaneous&nbsp;Authentication&nbsp;of&nbsp;Equals&nbsp;(SAE)加密类型。 |
| WIFI_SEC_TYPE_EAP | 5 | EAP authentication (EAP)加密类型。 |
| WIFI_SEC_TYPE_EAP_SUITE_B | 6 | Suite-B 192位加密类型。 |
| WIFI_SEC_TYPE_OWE | 7 | Opportunistic&nbsp; Wireless&nbsp; Encryption&nbsp;(OWE)机会性无线加密类型。 |
| WIFI_SEC_TYPE_WAPI_CERT | 8 | WAPI-Cert加密类型。 |
| WIFI_SEC_TYPE_WAPI_PSK | 9 | WAPI-PSK加密类型。 |


## WifiBandType<sup>10+</sup>

表示WIFI频段类型的枚举。

**系统能力：** SystemCapability.Communication.WiFi.STA

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| WIFI_BAND_NONE | 0 | 无效频段类型。 |
| WIFI_BAND_2G | 1 | 2.4G频段类型。 |
| WIFI_BAND_5G | 2 | 5G频段类型。 |
| WIFI_BAND_6G | 3 | 6G频段类型。 |
| WIFI_BAND_60G | 4 | 60G频段类型。 |

## WifiStandard<sup>10+</sup>

表示WIFI标准的枚举。

**系统能力：** SystemCapability.Communication.WiFi.STA

| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| WIFI_STANDARD_UNDEFINED | 0 | 无效WIFI标准类型。 |
| WIFI_STANDARD_11A | 1 | 802.11a WiFi标准类型。 |
| WIFI_STANDARD_11B | 2 | 802.11b WiFi标准类型。 |
| WIFI_STANDARD_11G | 3 | 802.11g WiFi标准类型。 |
| WIFI_STANDARD_11N | 4 | 802.11n WiFi标准类型。 |
| WIFI_STANDARD_11AC | 5 | 802.11ac WiFi标准类型。 |
| WIFI_STANDARD_11AX | 6 | 802.11ax WiFi标准类型。 |
| WIFI_STANDARD_11AD | 7 | 802.11ad WiFi标准类型。 |

## WifiInfoElem<sup>9+</sup>

WLAN热点信息。

**系统能力：** SystemCapability.Communication.WiFi.STA


| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| eid | number | 是 | 否 | 元素ID。 |
| content | Uint8Array | 是 | 否 | 元素内容。 |


## WifiChannelWidth<sup>9+</sup>

表示带宽类型的枚举。

**系统能力：** SystemCapability.Communication.WiFi.STA


| **名称** | **值** | **说明** |
| -------- | -------- | -------- |
| WIDTH_20MHZ | 0 | 20MHZ。 |
| WIDTH_40MHZ | 1 | 40MHZ。 |
| WIDTH_80MHZ | 2 | 80MHZ。 |
| WIDTH_160MHZ | 3 | 160MHZ。 |
| WIDTH_80MHZ_PLUS | 4 | 80MHZ<sup>+</sup>。 |
| WIDTH_INVALID | 5 | 无效值 |


## WifiDeviceConfig<sup>9+</sup>

WLAN配置信息。

**系统能力：** SystemCapability.Communication.WiFi.STA


| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，最大长度为32字节，编码格式为UTF-8。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| bssid | string | 是 | 否 | 热点的BSSID，例如：00:11:22:33:44:55。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| bssidType<sup>10+</sup> | [DeviceAddressType](#deviceaddresstype10) | 是 | 否 | 热点的BSSID类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| preSharedKey | string | 是 | 否 | 热点的密钥，最大长度为64字节。<br>当securityType为WIFI_SEC_TYPE_OPEN时该字段需为空串，其他加密类型不能为空串。<br>当securityType为WIFI_SEC_TYPE_WEP时，该字段长度只允许为5、10、13、26、16和32字节其中之一，并且当字段长度为偶数时，该字段必须为纯十六进制数字构成。<br>当securityType为WIFI_SEC_TYPE_SAE时，该字段最小长度为1字节。<br>当securityType为WIFI_SEC_TYPE_PSK时，该字段最小长度为8字节。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| isHiddenSsid | boolean | 是 | 否 | 是否是隐藏网络。 |
| securityType | [WifiSecurityType](#wifisecuritytype9)| 是 | 否 | 加密类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| eapConfig<sup>10+</sup> | [WifiEapConfig](#wifieapconfig10) | 是 | 否 | 可扩展身份验证协议配置。只有securityType为WIFI_SEC_TYPE_EAP时需要填写。 |
| wapiConfig<sup>12+</sup> | [WifiWapiConfig](#wifiwapiconfig12) | 是 | 否 | WAPI身份验证协议配置。只有securityType为WIFI_SEC_TYPE_WAPI_CERT或WIFI_SEC_TYPE_WAPI_PSK时需要填写。 |

## WifiEapConfig<sup>10+</sup>

可扩展身份验证协议配置信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| eapMethod | [EapMethod](#eapmethod10) | 是 | 否 | EAP认证方式。 |
| phase2Method | [Phase2Method](#phase2method10) | 是 | 否 | 第二阶段认证方式。只有eapMethod为EAP_PEAP或EAP_TTLS时需要填写。 |
| identity | string | 是 | 否 | 身份信息。当eapMethod为EAP_PEAP、EAP_TLS或EAP_PWD时，该字段不能为空串。 |
| anonymousIdentity | string | 是 | 否 | 匿名身份。暂未使用。 |
| password | string | 是 | 否 | 密码。当eapMethod为EAP_PEAP或EAP_PWD时，该字段不能为空串。 |
| caCertAlias | string | 是 | 否 | CA 证书别名。 |
| caPath | string | 是 | 否 | CA 证书路径。 |
| clientCertAlias | string | 是 | 否 | 客户端证书别名。 |
| certEntry | Uint8Array | 是 | 是 | CA 证书内容。当eapMethod为EAP_TLS时，如果该字段为空，则clientCertAlias不能为空。 |
| certPassword | string | 是 | 是 | CA证书密码。 |
| altSubjectMatch | string | 是 | 否 | 替代主题匹配。 |
| domainSuffixMatch | string | 是 | 否 | 域后缀匹配。 |
| realm | string | 是 | 否 | 通行证凭证的领域。 |
| plmn | string | 是 | 否 | 公共陆地移动网的直通凭证提供商。 |
| eapSubId | number | 是 | 否 | SIM卡的子ID。 |


## WifiWapiConfig<sup>12+</sup>

WAPI身份验证协议配置。

**系统能力：** SystemCapability.Communication.WiFi.STA

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| wapiPskType | [WapiPskType](#wapipsktype12)| 是 | 是 | 加密类型。 |
| wapiAsCert | string | 否 | 是 | As证书。 |
| wapiUserCert | string | 否 | 是 | 用户证书。 |

## WapiPskType<sup>12+</sup>

WAPI认证方式的枚举。

**系统能力：** SystemCapability.Communication.WiFi.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| WAPI_PSK_ASCII | 0 | ASCII类型。 |
| WAPI_PSK_HEX | 1 | HEX类型。 |

## EapMethod<sup>10+</sup>

表示EAP认证方式的枚举。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| EAP_NONE | 0 | 不指定。 |
| EAP_PEAP | 1 | PEAP类型。 |
| EAP_TLS | 2 | TLS类型。 |
| EAP_TTLS | 3 | TTLS类型。 |
| EAP_PWD | 4 | PWD类型。 |
| EAP_SIM | 5 | SIM类型。 |
| EAP_AKA | 6 | AKA类型。 |
| EAP_AKA_PRIME | 7 | AKA Prime类型。 |
| EAP_UNAUTH_TLS | 8 | UNAUTH TLS类型。 |

## Phase2Method<sup>10+</sup>

表示第二阶段认证方式的枚举。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| PHASE2_NONE | 0 | 不指定。 |
| PHASE2_PAP | 1 | PAP类型。 |
| PHASE2_MSCHAP | 2 | MSCHAP类型。 |
| PHASE2_MSCHAPV2 | 3 | MSCHAPV2类型。 |
| PHASE2_GTC | 4 | GTC类型。 |
| PHASE2_SIM | 5 | SIM类型。 |
| PHASE2_AKA | 6 | AKA类型。 |
| PHASE2_AKA_PRIME | 7 | AKA Prime类型。 |

## WifiCategory<sup>12+</sup>

表示热点支持的最高wifi类别。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DEFAULT | 1 | Default。Wifi6以下的wifi类别。 |
| WIFI6 | 2 | Wifi6。 |
| WIFI6_PLUS | 3 | Wifi6+。 |

## wifiManager.addCandidateConfig<sup>9+</sup>

addCandidateConfig(config: WifiDeviceConfig): Promise&lt;number&gt;

添加候选网络配置，使用Promise异步回调，使用前先使能WLAN。

**需要权限：** ohos.permission.SET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig9) | 是 | WLAN配置信息。如果bssidType未指定值，则bssidType默认为随机设备地址类型。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise对象。表示网络配置ID。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
`````ts
	import { wifiManager } from '@kit.ConnectivityKit';
	
	try {
		let config:wifiManager.WifiDeviceConfig = {
			ssid : "****",
			preSharedKey : "****",
			securityType : 0
		}
		wifiManager.addCandidateConfig(config).then(result => {
			console.info("result:" + JSON.stringify(result));
		}).catch((err:number) => {
			console.error("failed:" + JSON.stringify(err));
		});
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
`````

## wifiManager.addCandidateConfig<sup>9+</sup>

addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void

添加候选网络配置，使用callback异步回调。

**需要权限：** ohos.permission.SET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig9) | 是 | WLAN配置信息。如果bssidType未指定值，则bssidType默认为随机设备地址类型。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调函数。当操作成功时，err为0，data为添加的网络配置ID，如果data值为-1，表示添加失败。如果操作出现错误，err为非0值。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
`````ts
	import { wifiManager } from '@kit.ConnectivityKit';

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
`````

## wifiManager.removeCandidateConfig<sup>9+</sup>

removeCandidateConfig(networkId: number): Promise&lt;void&gt;

移除候选网络配置，使用Promise异步回调。

**需要权限：** ohos.permission.SET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | networkId | number | 是 | 网络配置ID。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let networkId = 0;
		wifiManager.removeCandidateConfig(networkId).then(result => {
			console.info("result:" + JSON.stringify(result));
		}).catch((err:number) => {
			console.error("failed:" + JSON.stringify(err));
		});
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.removeCandidateConfig<sup>9+</sup>

removeCandidateConfig(networkId: number, callback: AsyncCallback&lt;void&gt;): void

移除候选网络配置，使用callback异步回调。

**需要权限：** ohos.permission.SET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | networkId | number | 是 | 网络配置ID。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当操作成功时，err为0。如果error为非0，表示处理出现错误。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let networkId = 0;
		wifiManager.removeCandidateConfig(networkId,(error,result) => {
		console.info("result:" + JSON.stringify(result));
		});	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getCandidateConfigs<sup>9+</sup>

getCandidateConfigs(): &nbsp;Array&lt;WifiDeviceConfig&gt;

获取候选网络配置。

**需要权限：**

API 10起：ohos.permission.GET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig9)&gt; | 候选网络配置数组。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.| 

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

## wifiManager.connectToCandidateConfig<sup>9+</sup>

connectToCandidateConfig(networkId: number): void

应用使用该接口连接到自己添加的候选网络（如果当前已经连接到热点，需要先断开连接）。

**需要权限：** ohos.permission.SET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | networkId | number | 是 | 候选网络配置的ID。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let networkId = 0; // 实际的候选网络ID，在添加候选网络时生成，取自WifiDeviceConfig.netId
		wifiManager.connectToCandidateConfig(networkId);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
	
```


## wifiManager.getSignalLevel<sup>9+</sup>

getSignalLevel(rssi: number, band: number): number

查询WLAN信号强度。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | rssi | number | 是 | 热点的信号强度(dBm)。 |
  | band | number | 是 | WLAN接入点的频段，1表示2.4GHZ；2表示5GHZ。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | number | 信号强度，取值范围为[0,&nbsp;4]。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let rssi = 0;
		let band = 0;
		let level = wifiManager.getSignalLevel(rssi,band);
		console.info("level:" + JSON.stringify(level));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifiManager.getLinkedInfo<sup>9+</sup>

getLinkedInfo(): Promise&lt;WifiLinkedInfo&gt;

获取WLAN连接信息，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 。 

当macType是1 - 设备MAC地址时，获取 macAddress 还需申请ohos.permission.GET_WIFI_LOCAL_MAC权限（该权限仅系统应用可申请），无该权限时，macAddress 返回空字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[WifiLinkedInfo](#wifilinkedinfo9)&gt; | Promise对象。表示WLAN连接信息。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

## wifiManager.getLinkedInfo<sup>9+</sup>

getLinkedInfo(callback: AsyncCallback&lt;WifiLinkedInfo&gt;): void

获取WLAN连接信息，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO 。 

当macType是1 - 设备MAC地址时，获取 macAddress 还需申请ohos.permission.GET_WIFI_LOCAL_MAC权限（该权限仅系统应用可申请），无该权限时，macAddress 返回空字符串。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiLinkedInfo](#wifilinkedinfo9)&gt; | 是 | 回调函数。当获取成功时，err为0，data表示WLAN连接信息。如果err为非0，表示处理出现错误。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  wifiManager.getLinkedInfo((err, data:wifiManager.WifiLinkedInfo) => {
      if (err) {
          console.error("get linked info error");
          return;
      }
      console.info("get wifi linked info: " + JSON.stringify(data));
  });
  
  wifiManager.getLinkedInfo().then(data => {
      console.info("get wifi linked info: " + JSON.stringify(data));
  }).catch((error:number) => {
      console.info("get linked info error");
  });
```


## WifiLinkedInfo<sup>9+</sup>

提供WLAN连接的相关信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | 是 | 否 | 热点的SSID，编码格式为UTF-8。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| bssid | string | 是 | 否 | 热点的BSSID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| rssi | number | 是 | 否 | 热点的信号强度(dBm)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| band | number | 是 | 否 | WLAN接入点的频段，1表示2.4GHZ；2表示5GHZ。 |
| linkSpeed | number | 是 | 否 | WLAN接入点的上行速度，单位Mbps/s。 |
| rxLinkSpeed<sup>10+</sup> | number | 是 | 否 | WLAN接入点的下行速度，单位Mbps/s。 |
| maxSupportedTxLinkSpeed<sup>10+</sup> | number | 是 | 否 | 当前支持的最大上行速率，单位Mbps/s。 |
| maxSupportedRxLinkSpeed<sup>10+</sup> | number | 是 | 否 | 当前支持的最大下行速率，单位Mbps/s。 |
| frequency | number | 是 | 否 | WLAN接入点的频率。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| isHidden | boolean | 是 | 否 | WLAN接入点是否是隐藏网络。 |
| isRestricted | boolean | 是 | 否 | WLAN接入点是否限制数据量。 |
| macType | number | 是 | 否 | MAC地址类型。0 - 随机MAC地址，1 - 设备MAC地址。 |
| macAddress | string | 是 | 否 | 设备的MAC地址。 |
| ipAddress | number | 是 | 否 | WLAN连接的IP地址(wifi连接信息和关于本机里的状态信息可以查看)。 |
| connState | [ConnState](#connstate9) | 是 | 否 | WLAN连接状态。 |
| channelWidth<sup>10+</sup> | [WifiChannelWidth](#wifichannelwidth9) | 是 | 否 | 当前连接热点的信道带宽。 |
| wifiStandard<sup>10+</sup> | [WifiStandard](#wifistandard10) | 是 | 否 | 当前连接热点的Wi-Fi标准。 |
| supportedWifiCategory<sup>12+</sup> | [WifiCategory](#wificategory12) | 是 | 否 | 热点支持的最高Wi-Fi级别。 |
| isHiLinkNetwork<sup>12+</sup> | boolean | 是 | 否| 热点是否支持hilink，true:支持，&nbsp;false:不支持。 |

## ConnState<sup>9+</sup>

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


## wifiManager.isConnected<sup>9+</sup>

isConnected(): boolean

查询WLAN是否已连接。

**需要权限：** ohos.permission.GET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:已连接，&nbsp;false:未连接。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.isConnected();
		console.info("isConnected:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```


## wifiManager.isFeatureSupported<sup>9+</sup>

isFeatureSupported(featureId: number): boolean

判断设备是否支持相关WLAN特性。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.Core

**参数：**

  | **参数名** | **类型** | 必填 | **说明** |
  | -------- | -------- | -------- | -------- |
  | featureId | number | 是 | 特性ID值。 |

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

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:支持，&nbsp;false:不支持。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
  | -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2401000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let featureId = 0;
		let ret = wifiManager.isFeatureSupported(featureId);
		console.info("isFeatureSupported:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```


## wifiManager.getIpInfo<sup>9+</sup>

getIpInfo(): IpInfo

获取IPV4信息。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | [IpInfo](#ipinfo9) | IP信息。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let info = wifiManager.getIpInfo();
		console.info("info:" + JSON.stringify(info));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## IpInfo<sup>9+</sup>

IPV4信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | 是 | 否 | IP地址。 |
| gateway | number | 是 | 否 | 网关。 |
| netmask | number | 是 | 否 | 掩码。 |
| primaryDns | number | 是 | 否 | 主DNS服务器IP地址。 |
| secondDns | number | 是 | 否 | 备DNS服务器IP地址。 |
| serverIp | number | 是 | 否 | DHCP服务端IP地址。 |
| leaseDuration | number | 是 | 否 | IP地址租用时长，单位：秒。 |


## wifiManager.getIpv6Info<sup>10+</sup>

getIpv6Info(): Ipv6Info

获取IPV6信息。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| [Ipv6Info](#ipv6info10) | Ipv6信息。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let info = wifiManager.getIpv6Info();
		console.info("info:" + JSON.stringify(info));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```
## Ipv6Info<sup>10+</sup>

Ipv6信息。

**系统能力：** SystemCapability.Communication.WiFi.STA

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| linkIpv6Address | string | 是 | 否 | 链路Ipv6地址。 |
| globalIpv6Address | string | 是 | 否 | 全局Ipv6地址。 |
| randomGlobalIpv6Address | string | 是 | 否 | 随机全局Ipv6地址。 预留字段，暂不支持。|
| uniqueIpv6Address<sup>12+</sup> | string | 是 | 否 | 唯一本地Ipv6地址。 |
| randomUniqueIpv6Address<sup>12+</sup> | string | 是 | 否 | 随机唯一本地Ipv6地址。 |
| gateway | string | 是 | 否 | 网关。 |
| netmask | string | 是 | 否 | 网络掩码。 |
| primaryDNS | string | 是 | 否 | 主DNS服务器Ipv6地址。 |
| secondDNS | string | 是 | 否 | 备DNS服务器Ipv6地址。 |


## wifiManager.getCountryCode<sup>9+</sup>

getCountryCode(): string

获取国家码信息。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.Core

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | string | 国家码。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2401000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let code = wifiManager.getCountryCode();
		console.info("code:" + code);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```




## wifiManager.isBandTypeSupported<sup>10+</sup>

isBandTypeSupported(bandType: WifiBandType): boolean

判断当前频段是否支持。

**需要权限：** ohos.permission.GET_WIFI_INFO。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | bandType | [WifiBandType](#wifibandtype10) | 是 | Wifi 频段类型。 |

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:支持，&nbsp;false:不支持。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let type = 0;
		let isBandTypeSupported = wifiManager.isBandTypeSupported(type);
		console.info("isBandTypeSupported:" + isBandTypeSupported);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```


## wifiManager.isMeteredHotspot<sup>11+</sup>

isMeteredHotspot(): boolean

查询设备当前连接的wifi是否是手机热点。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**返回值：**

  | **类型** | **说明** |
  | -------- | -------- |
  | boolean | true:是手机热点，&nbsp;false:不是手机热点。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**示例：**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let isMeteredHotspot = wifiManager.isMeteredHotspot();
		console.info("isMeteredHotspot:" + isMeteredHotspot);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```



## wifiManager.getP2pLinkedInfo<sup>9+</sup>

getP2pLinkedInfo(): Promise&lt;WifiP2pLinkedInfo&gt;

获取P2P连接信息，使用Promise异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

获取 groupOwnerAddr 还需申请ohos.permission.GET_WIFI_LOCAL_MAC权限（该权限仅系统应用可申请），无该权限时，groupOwnerAddr 返回全零地址。

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | Promise对象。表示P2P连接信息。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |


## wifiManager.getP2pLinkedInfo<sup>9+</sup>

getP2pLinkedInfo(callback: AsyncCallback&lt;WifiP2pLinkedInfo&gt;): void

获取P2P连接信息，使用callback异步回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

获取 groupOwnerAddr 还需申请ohos.permission.GET_WIFI_LOCAL_MAC权限（该权限仅系统应用可申请），无该权限时，groupOwnerAddr 返回全零地址。

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示P2P连接信息。如果err为非0，表示处理出现错误。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | P2P module error. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	wifiManager.getP2pLinkedInfo((err, data:wifiManager.WifiP2pLinkedInfo) => {
    if (err) {
        console.error("get p2p linked info error");
        return;
    }
		console.info("get wifi p2p linked info: " + JSON.stringify(data));
	});

	wifiManager.getP2pLinkedInfo().then(data => {
		console.info("get wifi p2p linked info: " + JSON.stringify(data));
	});
```


## WifiP2pLinkedInfo<sup>9+</sup>

提供WLAN连接的相关信息。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| connectState | [P2pConnectState](#p2pconnectstate9) | 是 | 否 | P2P连接状态。 |
| isGroupOwner | boolean | 是 | 否 | 是否为GO。 |
| groupOwnerAddr | string | 是 | 否 | 群组IP地址。 


## P2pConnectState<sup>9+</sup>

表示P2P连接状态的枚举。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| DISCONNECTED | 0 | 断开状态。 |
| CONNECTED | 1 | 连接状态。 |

## wifiManager.getCurrentGroup<sup>9+</sup>

getCurrentGroup(): Promise&lt;WifiP2pGroupInfo&gt;

获取P2P当前组信息，使用Promise异步回调。

**需要权限：**

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt; | Promise对象。表示当前组信息。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限（仅系统应用可申请），则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.getCurrentGroup<sup>9+</sup>

getCurrentGroup(callback: AsyncCallback&lt;WifiP2pGroupInfo&gt;): void

获取P2P当前组信息，使用callback异步回调。

**需要权限：**

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示当前组信息。如果error为非0，表示处理出现错误。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限（仅系统应用可申请），则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | P2P module error. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';
	// p2p已经建组或者连接成功，才能正常获取到当前组信息
	wifiManager.getCurrentGroup((err, data:wifiManager.WifiP2pGroupInfo) => {
    if (err) {
        console.error("get current P2P group error");
        return;
    }
		console.info("get current P2P group: " + JSON.stringify(data));
	});

	wifiManager.getCurrentGroup().then(data => {
		console.info("get current P2P group: " + JSON.stringify(data));
	});
```

## wifiManager.getP2pPeerDevices<sup>9+</sup>

getP2pPeerDevices(): Promise&lt;WifiP2pDevice[]&gt;

获取P2P对端设备列表信息，使用Promise异步回调。

**需要权限：**

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Promise对象。表示对端设备列表信息。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限（仅系统应用可申请），则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.getP2pPeerDevices<sup>9+</sup>

getP2pPeerDevices(callback: AsyncCallback&lt;WifiP2pDevice[]&gt;): void

获取P2P对端设备列表信息，使用callback异步回调。

**需要权限：**

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示对端设备列表信息。如果err为非0，表示处理出现错误。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限（仅系统应用可申请），则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | P2P module error. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';
	// p2p发现阶段完成，才能正常获取到对端设备列表信息
	wifiManager.getP2pPeerDevices((err, data:wifiManager.WifiP2pDevice) => {
    if (err) {
        console.error("get P2P peer devices error");
        return;
    }
		console.info("get P2P peer devices: " + JSON.stringify(data));
	});

	wifiManager.getP2pPeerDevices().then(data => {
		console.info("get P2P peer devices: " + JSON.stringify(data));
	});
```

## WifiP2pDevice<sup>9+</sup>

表示P2P设备信息。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceName | string | 是 | 否 | 设备名称。 |
| deviceAddress | string | 是 | 否 | 设备MAC地址。 |
| deviceAddressType<sup>10+</sup> | [DeviceAddressType](#deviceaddresstype10) | 是 | 否 | 设备MAC地址类型。 |
| primaryDeviceType | string | 是 | 否 | 主设备类型。 |
| deviceStatus | [P2pDeviceStatus](#p2pdevicestatus9) | 是 | 否 | 设备状态。 |
| groupCapabilities | number | 是 | 否 | 群组能力。 |


## P2pDeviceStatus<sup>9+</sup>

表示设备状态的枚举。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| CONNECTED | 0 | 连接状态。 |
| INVITED | 1 | 邀请状态。 |
| FAILED | 2 | 失败状态。 |
| AVAILABLE | 3 | 可用状态。 |
| UNAVAILABLE | 4 | 不可用状态。 |


## wifiManager.getP2pLocalDevice<sup>9+</sup>

getP2pLocalDevice(): Promise&lt;WifiP2pDevice&gt;

获取P2P本端设备信息，使用Promise异步回调。

**需要权限：** 

API 11起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | Promise对象。表示本端设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.getP2pLocalDevice<sup>9+</sup>

getP2pLocalDevice(callback: AsyncCallback&lt;WifiP2pDevice&gt;): void

获取P2P本端设备信息，使用callback异步回调。

**需要权限：**

API 11起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | 是 | 回调函数。当操作成功时，err为0，data表示本端设备信息。如果error为非0，表示处理出现错误。 |

**错误码：**

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | P2P module error. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';
	// p2p已经建组或者连接成功，才能正常获取到本端设备信息
	wifiManager.getP2pLocalDevice((err, data:wifiManager.WifiP2pDevice) => {
    if (err) {
        console.error("get P2P local device error");
        return;
    }
		console.info("get P2P local device: " + JSON.stringify(data));
	});

	wifiManager.getP2pLocalDevice().then(data => {
		console.info("get P2P local device: " + JSON.stringify(data));
	});
```

## wifiManager.createGroup<sup>9+</sup>

createGroup(config: WifiP2PConfig): void

创建群组。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| **参数名** | **类型** | 必填 | **说明** |
| -------- | -------- | -------- | -------- |
| config | [WifiP2PConfig](#wifip2pconfig9) | 是 | 群组配置信息。如果DeviceAddressType未指定值，则DeviceAddressType默认为随机设备地址类型。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

## WifiP2PConfig<sup>9+</sup>

表示P2P配置信息。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceAddress | string | 是 | 否 | 设备地址。 |
| deviceAddressType<sup>10+</sup>| [DeviceAddressType](#deviceaddresstype10) | 是 | 否 | 设备地址类型。 |
| netId | number | 是 | 否 | 网络ID。创建群组时-1表示创建临时组，-2表示创建永久组。 |
| passphrase | string | 是 | 否 | 群组密钥。 |
| groupName | string | 是 | 否 | 群组名称。 |
| goBand | [GroupOwnerBand](#groupownerband9) | 是 | 否 | 群组带宽。 |


## GroupOwnerBand<sup>9+</sup>

表示群组带宽的枚举。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| GO_BAND_AUTO | 0 | 自动模式。 |
| GO_BAND_2GHZ | 1 | 2.4GHZ。 |
| GO_BAND_5GHZ | 2 | 5GHZ。 |


## wifiManager.removeGroup<sup>9+</sup>

removeGroup(): void

移除群组。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.removeGroup();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.p2pConnect<sup>9+</sup>

p2pConnect(config: WifiP2PConfig): void

执行P2P连接。

**需要权限：**

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| **参数名** | **类型** | 必填 | **说明** |
| -------- | -------- | -------- | -------- |
| config | [WifiP2PConfig](#wifip2pconfig9) | 是 | 连接配置信息。如果DeviceAddressType未指定值，则DeviceAddressType默认为随机设备地址类型。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pConnectionChangeFunc = (result:wifiManager.WifiP2pLinkedInfo) => {
      console.info("p2p connection change receive event: " + JSON.stringify(result));
      wifiManager.getP2pLinkedInfo((err, data:wifiManager.WifiP2pLinkedInfo) => {
          if (err) {
              console.error('failed to get getP2pLinkedInfo: ' + JSON.stringify(err));
              return;
          }
          console.info("get getP2pLinkedInfo: " + JSON.stringify(data));
      });
  }
  wifiManager.on("p2pConnectionChange", recvP2pConnectionChangeFunc);
  
  let recvP2pDeviceChangeFunc = (result:wifiManager.WifiP2pDevice) => {
      console.info("p2p device change receive event: " + JSON.stringify(result));
  }
  wifiManager.on("p2pDeviceChange", recvP2pDeviceChangeFunc);
  
  let recvP2pPeerDeviceChangeFunc = (result:wifiManager.WifiP2pDevice[]) => {
      console.info("p2p peer device change receive event: " + JSON.stringify(result));
      wifiManager.getP2pPeerDevices((err, data:wifiManager.WifiP2pDevice) => {
          if (err) {
              console.error('failed to get peer devices: ' + JSON.stringify(err));
              return;
          }
          console.info("get peer devices: " + JSON.stringify(data));
          let len = data.length;
          for (let i = 0; i < len; ++i) {
              if (data[i].deviceName === "my_test_device") {
                  console.info("p2p connect to test device: " + data[i].deviceAddress);
                  let config:wifiManager.WifiP2PConfig = {
                      deviceAddress:data[i].deviceAddress,
                      netId:-2,
                      passphrase:"",
                      groupName:"",
                      goBand:0,
                  }
                  wifiManager.p2pConnect(config);
              }
          }
      });
  }
  wifiManager.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
  
  let recvP2pPersistentGroupChangeFunc = () => {
      console.info("p2p persistent group change receive event");
  
      wifiManager.getCurrentGroup((err, data:wifiManager.WifiP2pGroupInfo) => {
          if (err) {
              console.error('failed to get current group: ' + JSON.stringify(err));
              return;
          }
          console.info("get current group: " + JSON.stringify(data));
      });
  }
  wifiManager.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
  
  setTimeout(() => {wifiManager.off("p2pConnectionChange", recvP2pConnectionChangeFunc);}, 125 * 1000);
  setTimeout(() =>  {wifiManager.off("p2pDeviceChange", recvP2pDeviceChangeFunc);}, 125 * 1000);
  setTimeout(() =>  {wifiManager.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);}, 125 * 1000);
  setTimeout(() =>  {wifiManager.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);}, 125 * 1000);
  console.info("start discover devices -> " + wifiManager.startDiscoverDevices());
```

## wifiManager.p2pCancelConnect<sup>9+</sup>

p2pCancelConnect(): void

在P2P连接过程中，取消P2P连接。

**需要权限：** ohos.permission.GET_WIFI_INFO 

**系统能力：** SystemCapability.Communication.WiFi.P2P

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.p2pCancelConnect();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.startDiscoverDevices<sup>9+</sup>

startDiscoverDevices(): void

开始发现设备。

**需要权限：**

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.startDiscoverDevices();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.stopDiscoverDevices<sup>9+</sup>

stopDiscoverDevices(): void

停止发现设备。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**示例：**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.stopDiscoverDevices();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## WifiP2pGroupInfo<sup>9+</sup>

表示P2P群组相关信息。

**系统能力：** SystemCapability.Communication.WiFi.P2P

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| isP2pGo | boolean | 是 | 否 | 是否是群主。 |
| ownerInfo | [WifiP2pDevice](#wifip2pdevice9) | 是 | 否 | 群组的设备信息。 |
| passphrase | string | 是 | 否 | 群组密钥。 |
| interface | string | 是 | 否 | 接口名称。 |
| groupName | string | 是 | 否 | 群组名称。 |
| networkId | number | 是 | 否 | 网络ID。 |
| frequency | number | 是 | 否 | 群组的频率。 |
| clientDevices | [WifiP2pDevice[]](#wifip2pdevice9) | 是 | 否 | 接入的设备列表信息。 |
| goIpAddress | string | 是 | 否 | 群组IP地址。 |


## wifiManager.on('wifiStateChange')<sup>9+</sup>

on(type: 'wifiStateChange', callback: Callback&lt;number&gt;): void

注册WLAN状态改变事件，在业务退出时，要调用off(type: 'wifiStateChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**状态改变事件的枚举：**

| **枚举值** | **说明** |
| -------- | -------- |
| 0 | 未激活。 |
| 1 | 已激活。 |
| 2 | 激活中。 |
| 3 | 去激活中。 |


## wifiManager.off('wifiStateChange')<sup>9+</sup>

off(type: 'wifiStateChange', callback?: Callback&lt;number&gt;): void

取消注册WLAN状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvPowerNotifyFunc = (result:number) => {
      console.info("Receive power state change event: " + result);
  }
  
  // Register event
  wifiManager.on("wifiStateChange", recvPowerNotifyFunc);
  
  // Unregister event
  wifiManager.off("wifiStateChange", recvPowerNotifyFunc);
```


## wifiManager.on('wifiConnectionChange')<sup>9+</sup>

on(type: 'wifiConnectionChange', callback: Callback&lt;number&gt;): void

注册WLAN连接状态改变事件，在业务退出时，要调用off(type: 'wifiConnectionChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('wifiConnectionChange')<sup>9+</sup>

off(type: 'wifiConnectionChange', callback?: Callback&lt;number&gt;): void

取消注册WLAN连接状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiConnectionChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 连接状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvWifiConnectionChangeFunc = (result:number) => {
      console.info("Receive wifi connection change event: " + result);
  }
  
  // Register event
  wifiManager.on("wifiConnectionChange", recvWifiConnectionChangeFunc);
  
  // Unregister event
  wifiManager.off("wifiConnectionChange", recvWifiConnectionChangeFunc);
```

## wifiManager.on('wifiScanStateChange')<sup>9+</sup>

on(type: 'wifiScanStateChange', callback: Callback&lt;number&gt;): void

注册扫描状态改变事件，在业务退出时，要调用off(type: 'wifiScanStateChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('wifiScanStateChange')<sup>9+</sup>

off(type: 'wifiScanStateChange', callback?: Callback&lt;number&gt;): void

取消注册扫描状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"wifiScanStateChange"字符串。 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvWifiScanStateChangeFunc = (result:number) => {
      console.info("Receive Wifi scan state change event: " + result);
  }
  
  // Register event
  wifiManager.on("wifiScanStateChange", recvWifiScanStateChangeFunc);
  
  // Unregister event
  wifiManager.off("wifiScanStateChange", recvWifiScanStateChangeFunc);
```

## wifiManager.on('wifiRssiChange')<sup>9+</sup>

on(type: 'wifiRssiChange', callback: Callback&lt;number&gt;): void

注册RSSI状态改变事件，在业务退出时，要调用off(type: 'wifiRssiChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"wifiRssiChange"字符串。 |
  | callback | Callback&lt;number&gt; | 是 | 状态改变回调函数，返回以dBm为单位的RSSI值。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('wifiRssiChange')<sup>9+</sup>

off(type: 'wifiRssiChange', callback?: Callback&lt;number&gt;): void

取消注册RSSI状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.STA

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"wifiRssiChange"字符串。 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvWifiRssiChangeFunc = (result:number) => {
      console.info("Receive wifi rssi change event: " + result);
  }
  
  // Register event
  wifiManager.on("wifiRssiChange", recvWifiRssiChangeFunc);
  
  // Unregister event
  wifiManager.off("wifiRssiChange", recvWifiRssiChangeFunc);
```
 
## wifiManager.on('hotspotStateChange')<sup>9+</sup>

on(type: 'hotspotStateChange', callback: Callback&lt;number&gt;): void

注册热点状态改变事件，在业务退出时，要调用off(type: 'hotspotStateChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。

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

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

## wifiManager.off('hotspotStateChange')<sup>9+</sup>

off(type: 'hotspotStateChange', callback?: Callback&lt;number&gt;): void

取消注册热点状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.AP.Core

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"hotspotStateChange"字符串。 |
| callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvHotspotStateChangeFunc = (result:number) => {
      console.info("Receive hotspot state change event: " + result);
  }
  
  // Register event
  wifiManager.on("hotspotStateChange", recvHotspotStateChangeFunc);
  
  // Unregister event
  wifiManager.off("hotspotStateChange", recvHotspotStateChangeFunc);
```


## wifiManager.on('p2pStateChange')<sup>9+</sup>

on(type: 'p2pStateChange', callback: Callback&lt;number&gt;): void

注册P2P开关状态改变事件，在业务退出时，要调用off(type: 'p2pStateChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"p2pStateChange"字符串。 |
| callback | Callback&lt;number&gt; | 是 | 状态改变回调函数。 |

** P2P状态改变事件的枚举：**

| **枚举值** | **说明** |
| -------- | -------- |
| 1 | 空闲。 |
| 2 | 打开中。 |
| 3 | 已打开。 |
| 4 | 关闭中。 |
| 5 | 已关闭。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pStateChange')<sup>9+</sup>

off(type: 'p2pStateChange', callback?: Callback&lt;number&gt;): void

取消注册P2P开关状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pStateChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pStateChangeFunc = (result:number) => {
      console.info("Receive p2p state change event: " + result);
  }
  
  // Register event
  wifiManager.on("p2pStateChange", recvP2pStateChangeFunc);
  
  // Unregister event
  wifiManager.off("p2pStateChange", recvP2pStateChangeFunc);
```

## wifiManager.on('p2pConnectionChange')<sup>9+</sup>

on(type: 'p2pConnectionChange', callback: Callback&lt;WifiP2pLinkedInfo&gt;): void

注册P2P连接状态改变事件，在业务退出时，要调用off(type: 'p2pConnectionChange', callback?: Callback&lt;WifiP2pLinkedInfo&gt;)接口去掉之前的注册回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pConnectionChange"字符串。 |
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | 是 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pConnectionChange')<sup>9+</sup>

off(type: 'p2pConnectionChange', callback?: Callback&lt;WifiP2pLinkedInfo&gt;): void

取消注册P2P连接状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pConnectionChange"字符串。 |
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pConnectionChangeFunc = (result:wifiManager.WifiP2pLinkedInfo) => {
      console.info("Receive p2p connection change event: " + result);
  }
  
  // Register event
  wifiManager.on("p2pConnectionChange", recvP2pConnectionChangeFunc);
  
  // Unregister event
  wifiManager.off("p2pConnectionChange", recvP2pConnectionChangeFunc);
```

## wifiManager.on('p2pDeviceChange')<sup>9+</sup>

on(type: 'p2pDeviceChange', callback: Callback&lt;WifiP2pDevice&gt;): void

注册P2P设备状态改变事件，在业务退出时，要调用off(type: 'p2pDeviceChange', callback?: Callback&lt;WifiP2pDevice&gt;)接口去掉之前的注册回调。

**需要权限：**

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | 是 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pDeviceChange')<sup>9+</sup>

off(type: 'p2pDeviceChange', callback?: Callback&lt;WifiP2pDevice&gt;): void

取消注册P2P设备状态改变事件。

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDeviceChange"字符串。 |
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pDeviceChangeFunc = (result:wifiManager.WifiP2pDevice) => {
      console.info("Receive p2p device change event: " + result);
  }
  
  // Register event
  wifiManager.on("p2pDeviceChange", recvP2pDeviceChangeFunc);
  
  // Unregister event
  wifiManager.off("p2pDeviceChange", recvP2pDeviceChangeFunc);
```

## wifiManager.on('p2pPeerDeviceChange')<sup>9+</sup>

on(type: 'p2pPeerDeviceChange', callback: Callback&lt;WifiP2pDevice[]&gt;): void

注册P2P对端设备状态改变事件，在业务退出时，要调用off(type: 'p2pPeerDeviceChange', callback?: Callback&lt;WifiP2pDevice[]&gt;)接口去掉之前的注册回调。

**需要权限：**

API 10起：ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"p2pPeerDeviceChange"字符串。 |
| callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | 是 | 状态改变回调函数。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限（仅系统应用可申请），则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pPeerDeviceChange')<sup>9+</sup>

off(type: 'p2pPeerDeviceChange', callback?: Callback&lt;WifiP2pDevice[]&gt;): void

取消注册P2P对端设备状态改变事件。

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"p2pPeerDeviceChange"字符串。 |
| callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。如果应用申请了ohos.permission.GET_WIFI_PEERS_MAC权限（仅系统应用可申请），则返回结果中的deviceAddress为真实设备地址，否则为随机设备地址。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pPeerDeviceChangeFunc = (result:wifiManager.WifiP2pDevice[]) => {
      console.info("Receive p2p peer device change event: " + result);
  }
  
  // Register event
  wifiManager.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
  
  // Unregister event
  wifiManager.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
```

## wifiManager.on('p2pPersistentGroupChange')<sup>9+</sup>

on(type: 'p2pPersistentGroupChange', callback: Callback&lt;void&gt;): void

注册P2P永久组状态改变事件，在业务退出时，要调用off(type: 'p2pPersistentGroupChange', callback?: Callback&lt;void&gt;)接口去掉之前的注册回调。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pPersistentGroupChange"字符串。 |
  | callback | Callback&lt;void&gt; | 是 | 状态改变回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pPersistentGroupChange')<sup>9+</sup>

off(type: 'p2pPersistentGroupChange', callback?: Callback&lt;void&gt;): void

取消注册P2P永久组状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 固定填"p2pPersistentGroupChange"字符串。 |
| callback | Callback&lt;void&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pPersistentGroupChangeFunc = (result:void) => {
      console.info("Receive p2p persistent group change event: " + result);
  }
  
  // Register event
  wifiManager.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
  
  // Unregister event
  wifiManager.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
```

## wifiManager.on('p2pDiscoveryChange')<sup>9+</sup>

on(type: 'p2pDiscoveryChange', callback: Callback&lt;number&gt;): void

注册发现设备状态改变事件，在业务退出时，要调用off(type: 'p2pDiscoveryChange', callback?: Callback&lt;number&gt;)接口去掉之前的注册回调。

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

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pDiscoveryChange')<sup>9+</sup>

off(type: 'p2pDiscoveryChange', callback?: Callback&lt;number&gt;): void

取消注册发现设备状态改变事件。

**需要权限：** ohos.permission.GET_WIFI_INFO

**系统能力：** SystemCapability.Communication.WiFi.P2P

**参数：**

  | **参数名** | **类型** | **必填** | **说明** |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 固定填"p2pDiscoveryChange"字符串。 |
  | callback | Callback&lt;number&gt; | 否 | 状态改变回调函数。如果callback不填，将取消注册该事件关联的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[WIFI错误码](errorcode-wifi.md)。

| **错误码ID** | **错误信息** |
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**示例：**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pDiscoveryChangeFunc = (result:number) => {
      console.info("Receive p2p discovery change event: " + result);
  }
  
  // Register event
  wifiManager.on("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
  
  // Unregister event
  wifiManager.off("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
```