# @ohos.wifiManager (WLAN)
The **wifiManager** module provides basic WLAN functionalities (such as wireless access, wireless encryption, and wireless roaming), basic peer-to-peer (P2P) services, and WLAN notification services. It allows applications to interact with other devices through WLAN.

> **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { wifiManager } from '@kit.ConnectivityKit';
```


## wifiManager.isWifiActive<sup>9+</sup>

isWifiActive(): boolean

Checks whether WLAN is enabled.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if WLAN is enabled; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let isWifiActive = wifiManager.isWifiActive();
		console.info("isWifiActive:" + isWifiActive);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.enableWifi<sup>15+</sup>

enableWifi(): void

Enable Wi-Fi.

**Required permissions** ohos.permission.SET_WIFI_INFO and (ohos.permission.MANAGE_WIFI_CONNECTION or ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION)

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.          |
| 801  | Capability not supported.|
| 2501000 | Operation failed.          |
| 2501003  | Operation failed because the service is being closed.|

**Example**

```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  try {
    wifiManager.enableWifi();
  }catch(error){
    console.error("failed:" + JSON.stringify(error));
  }
```

## wifiManager.scan<sup>9+</sup><sup>(deprecated)</sup>

scan(): void

Starts WLAN scanning. Note that WLAN must have been enabled.

> **NOTE**
> This API is supported since API version 9 and deprecated since API version 10. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.SET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**

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

Obtains the scan result. This API uses a promise to return the result.

> **NOTE**
> This API is supported since API version 9 and deprecated since API version 10. Use [wifiManager.getScanInfoList](#wifimanagergetscaninfolist10) instead.

**Required permissions**: ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))
ohos.permission.GET_WIFI_PEERS_MAC is available only for system applications.

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo9)&gt;&nbsp;&gt; | Promise used to return the hotspots detected.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.getScanResults<sup>9+</sup><sup>(deprecated)</sup>

getScanResults(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void

Obtains the scan result. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 9 and deprecated since API version 10. Use [wifiManager.getScanInfoList](#wifimanagergetscaninfolist10) instead.

**Required permissions**: ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))
ohos.permission.GET_WIFI_PEERS_MAC is available only for system applications.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo9)&gt;&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the detected hotspots. Otherwise, **err** is a non-zero value and **data** is empty.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
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

Obtains the scan result. This API returns the result synchronously.

> **NOTE**
> This API is supported since API version 9 and deprecated since API version 10. Use [wifiManager.getScanInfoList](#wifimanagergetscaninfolist10) instead.

**Required permissions**: ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))
ohos.permission.GET_WIFI_PEERS_MAC is available only for system applications.

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| &nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo9)&gt; | Scan result obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**

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

Obtains the scanning result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Array&lt;[WifiScanInfo](#wifiscaninfo9)&gt; | Hotspots detected. If the caller has the ohos.permission.GET_WIFI_PEERS_MAC permission (available only for system applications), **bssid** in the return value is a real device address. Otherwise, **bssid** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**

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

Represents WLAN hotspot information.

**System capability**: SystemCapability.Communication.WiFi.STA


| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| Service set identifier (SSID) of the hotspot, in UTF-8 format. The maximum length is 32 bytes.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| bssid | string | Yes| No| Basic service set identifier (BSSID) of the hotspot, for example, **00:11:22:33:44:55**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| bssidType<sup>10+</sup>| [DeviceAddressType](#deviceaddresstype10) | Yes| No| BSSID type of the hotspot.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| capabilities | string | Yes| No| Hotspot capabilities.|
| securityType | [WifiSecurityType](#wifisecuritytype9) | Yes| No| WLAN security type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| rssi | number | Yes| No| Received signal strength indicator (RSSI) of the hotspot, in dBm.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| band | number | Yes| No| Frequency band of the WLAN access point (AP). The value **1** indicates 2.4 GHz, and **2** indicates 5 GHz.|
| frequency | number | Yes| No| Frequency of the WLAN AP.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| channelWidth | number | Yes| No| Channel width of the WLAN AP. For details, see [WifiChannelWidth](#wifichannelwidth9).|
| centerFrequency0 | number | Yes| No| Center frequency of the hotspot.|
| centerFrequency1 | number | Yes| No| Center frequency of the hotspot. If the hotspot uses two non-overlapping WLAN channels, two center frequencies, namely **centerFrequency0** and **centerFrequency1**, are returned.|
| infoElems | Array&lt;[WifiInfoElem](#wifiinfoelem9)&gt; | Yes| No| Information elements.|
| timestamp | number | Yes| No| Timestamp.|
| supportedWifiCategory<sup>12+</sup> | [WifiCategory](#wificategory12) | Yes| No| Highest Wi-Fi category supported by the hotspot.|
| isHiLinkNetwork<sup>12+</sup> | boolean | Yes| No| Whether the hotspot supports HiLink. The value **true** indicates that the hotspot supports HiLink. The value **false** means the opposite.|

## DeviceAddressType<sup>10+</sup>

Enumerates the Wi-Fi device address (MAC/BSSID) types.

**System capability**: SystemCapability.Communication.WiFi.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| RANDOM_DEVICE_ADDRESS | 0 | Random device address.|
| REAL_DEVICE_ADDRESS | 1 | Read device address.|

## WifiSecurityType<sup>9+</sup>

Enumerates the WLAN security types.

**System capability**: SystemCapability.Communication.WiFi.Core


| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| WIFI_SEC_TYPE_INVALID | 0 | Invalid security type.|
| WIFI_SEC_TYPE_OPEN | 1 | Open security type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| WIFI_SEC_TYPE_WEP | 2 | Wired Equivalent Privacy (WEP). This type is not supported by the candidate network configuration (**addCandidateConfig**).|
| WIFI_SEC_TYPE_PSK | 3 | Pre-shared key (PSK).|
| WIFI_SEC_TYPE_SAE | 4 | Simultaneous Authentication of Equals (SAE).|
| WIFI_SEC_TYPE_EAP | 5 | Extensible Authentication Protocol (EAP).|
| WIFI_SEC_TYPE_EAP_SUITE_B | 6 | Suite B 192-bit encryption.|
| WIFI_SEC_TYPE_OWE | 7 | Opportunistic Wireless Encryption (OWE).|
| WIFI_SEC_TYPE_WAPI_CERT | 8 | WLAN Authentication and Privacy Infrastructure (WAPI) in certificate-based mode (WAPI-CERT).|
| WIFI_SEC_TYPE_WAPI_PSK | 9 | WAPI-PSK.|


## WifiBandType<sup>10+</sup>

Enumerates the Wi-Fi band types.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| WIFI_BAND_NONE | 0 | Invalid band type|
| WIFI_BAND_2G | 1 | 2.4 GHz|
| WIFI_BAND_5G | 2 | 5 GHz|
| WIFI_BAND_6G | 3 | 6 GHz|
| WIFI_BAND_60G | 4 | 60 GHz|

## WifiStandard<sup>10+</sup>

Enumerates the Wi-Fi standards.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| WIFI_STANDARD_UNDEFINED | 0 | Invalid Wi-Fi standard|
| WIFI_STANDARD_11A | 1 | 802.11a|
| WIFI_STANDARD_11B | 2 | 802.11b|
| WIFI_STANDARD_11G | 3 | 802.11g|
| WIFI_STANDARD_11N | 4 | 802.11n|
| WIFI_STANDARD_11AC | 5 | 802.11ac|
| WIFI_STANDARD_11AX | 6 | 802.11ax|
| WIFI_STANDARD_11AD | 7 | 802.11ad|

## WifiInfoElem<sup>9+</sup>

Represents a WLAN information element.

**System capability**: SystemCapability.Communication.WiFi.STA


| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| eid | number | Yes| No| ID of the information element.|
| content | Uint8Array | Yes| No| Content of the information element.|


## WifiChannelWidth<sup>9+</sup>

Enumerates the WLAN channel widths.

**System capability**: SystemCapability.Communication.WiFi.STA


| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| WIDTH_20MHZ | 0 | 20 MHz|
| WIDTH_40MHZ | 1 | 40 MHz|
| WIDTH_80MHZ | 2 | 80 MHz|
| WIDTH_160MHZ | 3 | 160 MHz|
| WIDTH_80MHZ_PLUS | 4 | 80 MHz<sup>+</sup>|
| WIDTH_INVALID | 5 | Invalid value|


## WifiDeviceConfig<sup>9+</sup>

Represents the WLAN configuration.

**System capability**: SystemCapability.Communication.WiFi.STA


| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| Service set identifier (SSID) of the hotspot, in UTF-8 format. The maximum length is 32 bytes.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| bssid | string | Yes| No| Basic service set identifier (BSSID) of the hotspot, for example, **00:11:22:33:44:55**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| bssidType<sup>10+</sup> | [DeviceAddressType](#deviceaddresstype10) | Yes| No| BSSID type of the hotspot.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| preSharedKey | string | Yes| No| PSK of the hotspot, which cannot exceed 64 bytes.<br>When **securityType** is **WIFI_SEC_TYPE_OPEN**, this parameter must be an empty string. When **securityType** is any other value, this parameter cannot be empty.<br>When **securityType** is **WIFI_SEC_TYPE_WEP**, the PSK must be of 5, 10, 13, 26, 16, or 32 bytes. If the PSK length is 10, 26, 16, or 32 bytes, the PSK must be a hexadecimal number.<br>When **securityType** is **WIFI_SEC_TYPE_SAE**, the minimum PSK length is 1 byte.<br>When **securityType** is **WIFI_SEC_TYPE_PSK**, the minimum PSK length is 8 bytes.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| isHiddenSsid | boolean | Yes| No| Whether the network is hidden.|
| securityType | [WifiSecurityType](#wifisecuritytype9)| Yes| No| Security type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| eapConfig<sup>10+</sup> | [WifiEapConfig](#wifieapconfig10) | Yes| No| EAP configuration. This parameter is mandatory only when **securityType** is **WIFI_SEC_TYPE_EAP**.|
| wapiConfig<sup>12+</sup> | [WifiWapiConfig](#wifiwapiconfig12) | Yes| No| WAPI configuration. This parameter is mandatory only when **securityType** is **WIFI_SEC_TYPE_WAPI_CERT** or** WIFI_SEC_TYPE_WAPI_PSK**.|

## WifiEapConfig<sup>10+</sup>

Represents EAP configuration information.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| eapMethod | [EapMethod](#eapmethod10) | Yes| No| EAP authentication method.|
| phase2Method | [Phase2Method](#phase2method10) | Yes| No| Phase 2 authentication method. This parameter is mandatory only when **eapMethod** is **EAP_PEAP** or **EAP_TTLS**.|
| identity | string | Yes| No| Identity Information. When **eapMethod** is **EAP_PEAP**, **EAP_TLS**, or **EAP_PWD**, this parameter cannot be empty.|
| anonymousIdentity | string | Yes| No| Anonymous identity. This parameter is not used currently.|
| password | string | Yes| No| Password. When **eapMethod** is **EAP_PEAP** or **EAP_PWD**, this parameter cannot be empty.|
| caCertAlias | string | Yes| No| CA certificate alias.|
| caPath | string | Yes| No| CA certificate path.|
| clientCertAlias | string | Yes| No| Client certificate alias.|
| certEntry | Uint8Array | Yes| Yes| CA certificate content. If **eapMethod** is **EAP_TLS** and this parameter is not specified, **clientCertAlias** cannot be empty.|
| certPassword | string | Yes| Yes| CA certificate password.|
| altSubjectMatch | string | Yes| No| A string to match the alternate subject.|
| domainSuffixMatch | string | Yes| No| A string to match the domain suffix.|
| realm | string | Yes| No| Realm for the passpoint credential.|
| plmn | string | Yes| No| Public land mobile network (PLMN) of the passpoint credential provider.|
| eapSubId | number | Yes| No| Sub-ID of the SIM card.|


## WifiWapiConfig<sup>12+</sup>

Represents WAPI configuration.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| wapiPskType | [WapiPskType](#wapipsktype12)| Yes| Yes| PSK type.|
| wapiAsCert | string | No| Yes| AS certificate.|
| wapiUserCert | string | No| Yes| User Certificate.|

## WapiPskType<sup>12+</sup>

Enumerates the WAPI authentication types.

**System capability**: SystemCapability.Communication.WiFi.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| WAPI_PSK_ASCII | 0 | ASCII.|
| WAPI_PSK_HEX | 1 | HEX.|

## EapMethod<sup>10+</sup>

Enumerates the EAP authentication methods.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| EAP_NONE | 0 | Not specified.|
| EAP_PEAP | 1 | PEAP.|
| EAP_TLS | 2 | TLS.|
| EAP_TTLS | 3 | TTLS.|
| EAP_PWD | 4 | Password.|
| EAP_SIM | 5 | SIM.|
| EAP_AKA | 6 | AKA.|
| EAP_AKA_PRIME | 7 | AKA Prime.|
| EAP_UNAUTH_TLS | 8 | UNAUTH TLS.|

## Phase2Method<sup>10+</sup>

Enumerates the Phase 2 authentication methods.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| PHASE2_NONE | 0 | Not specified.|
| PHASE2_PAP | 1 | PAP.|
| PHASE2_MSCHAP | 2 | MS-CHAP.|
| PHASE2_MSCHAPV2 | 3 | MS-CHAPv2.|
| PHASE2_GTC | 4 | GTC.|
| PHASE2_SIM | 5 | SIM.|
| PHASE2_AKA | 6 | AKA.|
| PHASE2_AKA_PRIME | 7 | AKA Prime.|

## WifiCategory<sup>12+</sup>

Represents the highest Wi-Fi type supported by a hotspot.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| DEFAULT | 1 | Default, that is, Wi-Fi types lower than Wi-Fi 6.|
| WIFI6 | 2 | Wi-Fi 6|
| WIFI6_PLUS | 3 | Wi-Fi 6+|

## wifiManager.addCandidateConfig<sup>9+</sup>

addCandidateConfig(config: WifiDeviceConfig): Promise&lt;number&gt;

Adds the candidate network configuration. This API uses a promise to return the result. Before using this API, ensure that WLAN is enabled.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig9) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the network configuration ID.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
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

Adds the configuration of a candidate network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig9) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the network configuration ID. If **data** is **-1**, the operation has failed. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
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

Removes the configuration of a candidate network. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | networkId | number | Yes| ID of the network configuration to remove.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**Example**

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

## wifiManager.removeDevice<sup>15+</sup>

removeDevice(id: number): void

Remove a Wi-Fi DeviceConfig with networkId.

**Required permissions**: ohos.permission.SET_WIFI_INFO and (ohos.permission.MANAGE_WIFI_CONNECTION or ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION)

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | id | number | Yes| ID of the network configuration to remove.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';
  
    try {
      let id = 0;
      wifiManager.removeDevice(id);
    }catch(error){
      console.error("failed:" + JSON.stringify(error));
    }
```

## wifiManager.removeCandidateConfig<sup>9+</sup>

removeCandidateConfig(networkId: number, callback: AsyncCallback&lt;void&gt;): void

Removes the configuration of a candidate network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | networkId | number | Yes| ID of the network configuration to remove.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0**. If the operation fails, **error** is not **0**.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**Example**
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

Obtains candidate network configuration.

**Required permissions**:

API version 10 and later: ohos.permission.GET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig9)&gt; | Candidate network configuration obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.| 

**Example**

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

Connects to a candidate network added by the application. If the device is already connected to a hotspot, disconnect it from the hotspot first.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | networkId | number | Yes| ID of the candidate network configuration.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let networkId = 0; // Candidate network ID, which is generated when a candidate network is added. The value is obtained from WifiDeviceConfig.netId.
		wifiManager.connectToCandidateConfig(networkId);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
	
```
## wifiManager.addDeviceConfig<sup>9+</sup>

addDeviceConfig(config: WifiDeviceConfig): Promise&lt;number&gt;

Add Wi-Fi connection configuration to the device. The configuration will be updated when the configuration is added.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig9) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the network configuration ID.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';
	
	try {
		let config:wifiManager.WifiDeviceConfig = {
			ssid : "****",
			preSharedKey : "****",
			securityType : 0
		}
		wifiManager.addDeviceConfig(config).then(result => {
			console.info("result:" + JSON.stringify(result));
		}).catch((err:number) => {
			console.error("failed:" + JSON.stringify(err));
		});
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.addDeviceConfig<sup>15+</sup>

addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void

Add Wi-Fi connection configuration to the device. The configuration will be updated when the configuration is added.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Atomic service API**: This API can be used in atomic services since API version 15.

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig9) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the network configuration ID. If **data** is **-1**, the operation has failed. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed.|
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';
  
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

## wifiManager.getDeviceConfigs<sup>15+</sup>

getDeviceConfigs(): &nbsp;Array&lt;WifiDeviceConfig&gt;

Obtain the list of all existed Wi-Fi configurations

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig9)&gt; | network configuration obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.| 

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';
  
    try {
      let configs = wifiManager.getDeviceConfigs();
      console.info("configs:" + JSON.stringify(configs));
    }catch(error){
      console.error("failed:" + JSON.stringify(error));
    }

```

## wifiManager.connectToNetwork<sup>15+</sup>

connectToNetwork(networkId: number): void

Connect to Wi-Fi hotspot by networkId.

**Required permissions**: ohos.permission.MANAGE_WIFI_CONNECTION or ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | networkId | number | Yes| ID of the candidate network configuration.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';
  
    try {
      let networkId = 0;
      wifiManager.connectToNetwork(networkId);
    }catch(error){
      console.error("failed:" + JSON.stringify(error));
    }
	
```

## wifiManager.getSignalLevel<sup>9+</sup>

getSignalLevel(rssi: number, band: number): number

Obtains the WLAN signal level.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | rssi | number | Yes| RSSI of the hotspot, in dBm.|
  | band | number | Yes| Frequency band of the WLAN AP. The value **1** indicates 2.4 GHz, and **2** indicates 5 GHz.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | number | Signal level obtained. The value range is [0, 4].|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
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

Obtains WLAN connection information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

If **macType** to be obtained is **1** (device MAC address), the caller must have the **ohos.permission.GET_WIFI_LOCAL_MAC** permission, which is available only for system applications. Without this permission, a random MAC address is returned in **macAddress**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiLinkedInfo](#wifilinkedinfo9)&gt; | Promise used to return the WLAN connection information.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

## wifiManager.getLinkedInfo<sup>9+</sup>

getLinkedInfo(callback: AsyncCallback&lt;WifiLinkedInfo&gt;): void

Obtains WLAN connection information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

If **macType** to be obtained is **1** (device MAC address), the caller must have the **ohos.permission.GET_WIFI_LOCAL_MAC** permission, which is available only for system applications. Without this permission, a random MAC address is returned in **macAddress**.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiLinkedInfo](#wifilinkedinfo9)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the WLAN connection information obtained. If the operation fails, **err** is not **0**.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**Example**
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

## wifiManager.getLinkedInfoSync<sup>16+</sup>

getLinkedInfoSync(): WifiLinkedInfo;

Obtains the WLAN connection information. This API returns the result synchronously.

**Required permissions**: ohos.permission.GET_WIFI_INFO

If **macType** to be obtained is **1** (device MAC address), the caller must have the **ohos.permission.GET_WIFI_LOCAL_MAC** permission, which is available only for system applications. Without this permission, a random MAC address is returned in **macAddress**.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [WifiLinkedInfo](#wifilinkedinfo9) | return the WLAN connection information.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  try {
    let linkInfo = wifiManager.getLinkedInfoSync();
    console.info("get linked info:" + JSON.stringify(linkInfo));
  } catch(error) {
    console.error("get linked info failed:" + JSON.stringify(error));
  }
```

## WifiLinkedInfo<sup>9+</sup>

Represents the WLAN connection information.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| SSID of the hotspot, in UTF-8 format.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| bssid | string | Yes| No| BSSID of the hotspot.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| rssi | number | Yes| No| Received signal strength indicator (RSSI) of the hotspot, in dBm.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| band | number | Yes| No| Frequency band of the WLAN AP. The value **1** indicates 2.4 GHz, and **2** indicates 5 GHz.|
| linkSpeed | number | Yes| No| Uplink speed of the WLAN AP, in Mbps/s.|
| rxLinkSpeed<sup>10+</sup> | number | Yes| No| Downlink speed of the WLAN AP, in Mbps/s.|
| maxSupportedTxLinkSpeed<sup>10+</sup> | number | Yes| No| Maximum uplink speed supported, in Mbps/s.|
| maxSupportedRxLinkSpeed<sup>10+</sup> | number | Yes| No| Maximum downlink speed supported, in Mbps/s.|
| frequency | number | Yes| No| Frequency of the WLAN AP.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| isHidden | boolean | Yes| No| Whether to hide the WLAN AP.|
| isRestricted | boolean | Yes| No| Whether to restrict data volume at the WLAN AP.|
| macType | number | Yes| No| MAC address type. <br>The value **0** indicates random MAC address, and **1** indicates device MAC address.|
| macAddress | string | Yes| No| MAC address of the device.|
| ipAddress | number | Yes| No| IP address of the device that sets up the WLAN connection (the Wi-Fi connection information and the status information of the local device can be viewed.)|
| connState | [ConnState](#connstate9) | Yes| No| WLAN connection state.|
| channelWidth<sup>10+</sup> | [WifiChannelWidth](#wifichannelwidth9) | Yes| No| Channel bandwidth of the connected hotspot.|
| wifiStandard<sup>10+</sup> | [WifiStandard](#wifistandard10) | Yes| No| Wi-Fi standard used by the connected hotspot.|
| supportedWifiCategory<sup>12+</sup> | [WifiCategory](#wificategory12) | Yes| No| Highest Wi-Fi category supported by the hotspot.|
| isHiLinkNetwork<sup>12+</sup> | boolean | Yes| No| Whether the hotspot supports HiLink. The value **true** indicates that the hotspot supports HiLink. The value **false** means the opposite.|

## ConnState<sup>9+</sup>

Enumerates the WLAN connection states.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| SCANNING | 0 | The device is scanning for available APs.|
| CONNECTING | 1 | A WLAN connection is being established.|
| AUTHENTICATING | 2 | An authentication is being performed for a WLAN connection.|
| OBTAINING_IPADDR | 3 | The IP address of the WLAN connection is being acquired.|
| CONNECTED | 4 | A WLAN connection is established.|
| DISCONNECTING | 5 | The WLAN connection is being disconnected.|
| DISCONNECTED | 6 | The WLAN connection is disconnected.|
| UNKNOWN | 7 | Failed to set up the WLAN connection.|


## wifiManager.isConnected<sup>9+</sup>

isConnected(): boolean

Checks whether WLAN is connected.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if WLAN is connected; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.isConnected();
		console.info("isConnected:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```


## wifiManager.disconnect<sup>15+</sup>

disconnect(): void

Disconnect the WLAN.

**Required permissions**: ohos.permission.SET_WIFI_INFO and (ohos.permission.MANAGE_WIFI_CONNECTION or
   ohos.permission.MANAGE_ENTERPRISE_WIFI_CONNECTION)

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.disconnect();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```


## wifiManager.isFeatureSupported<sup>9+</sup>

isFeatureSupported(featureId: number): boolean

Checks whether the device supports the specified WLAN feature.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.Core

**Parameters**

  | **Name**| **Type**| Mandatory| **Description**|
  | -------- | -------- | -------- | -------- |
  | featureId | number | Yes| Feature ID.|

**Feature IDs**

| Value| Description|
| -------- | -------- |
| 0x0001 | WLAN infrastructure mode|
| 0x0002 | 5 GHz feature|
| 0x0004 | Generic Advertisement Service (GAS)/Access Network Query Protocol (ANQP) feature|
| 0x0008 | Wi-Fi Direct|
| 0x0010 | SoftAP|
| 0x0040 | Wi-Fi Aware|
| 0x8000 | WLAN AP/STA concurrency|
| 0x8000000 | WPA3 Personal (WPA-3 SAE)|
| 0x10000000 | WPA3-Enterprise Suite B |
| 0x20000000 | Enhanced open feature| 

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the feature is supported; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
  | -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2401000  | Operation failed.|

**Example**
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

Obtains IPv4 information.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | [IpInfo](#ipinfo9) | IP information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
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

Represents IPv4 information.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | Yes| No| IP address.|
| gateway | number | Yes| No| Gateway.|
| netmask | number | Yes| No| Subnet mask.|
| primaryDns | number | Yes| No| IP address of the preferred DNS server.|
| secondDns | number | Yes| No| IP address of the alternate DNS server.|
| serverIp | number | Yes| No| IP address of the DHCP server.|
| leaseDuration | number | Yes| No| Lease duration of the IP address, in seconds.|


## wifiManager.getIpv6Info<sup>10+</sup>

getIpv6Info(): Ipv6Info

Obtains IPv6 information.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| [Ipv6Info](#ipv6info10) | IPv6 information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
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

Represents the IPv6 information.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| linkIpv6Address | string | Yes| No| IPv6 address of the link.|
| globalIpv6Address | string | Yes| No| Global IPv6 address.|
| randomGlobalIpv6Address | string | Yes| No| Random global IPv6 address. This parameter is reserved.|
| uniqueIpv6Address<sup>12+</sup> | string | Yes| No| Unique local address (ULA) in IPv6 format.|
| randomUniqueIpv6Address<sup>12+</sup> | string | Yes| No| Random unique local address (RULA) in IPv6 format.|
| gateway | string | Yes| No| Gateway.|
| netmask | string | Yes| No| Subnet mask.|
| primaryDNS | string | Yes| No| IPv6 address of the preferred DNS server.|
| secondDNS | string | Yes| No| IPv6 address of the alternate DNS server.|

## wifiManager.getCountryCode<sup>9+</sup>

getCountryCode(): string

Obtains the country code.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.Core

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | string | Country code obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2401000  | Operation failed.|

**Example**
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

Checks whether the current frequency band is supported.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | bandType | [WifiBandType](#wifibandtype10) | Yes| Wi-Fi band type.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the feature is supported; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
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

Checks whether the Wi-Fi network connected to the device is a smartphone hotspot.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the Wi-Fi network connected is a smartphone hotspot; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wi-Fi STA disabled. |

**Example**

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

Obtains P2P connection information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

To obtain **groupOwnerAddr**, the caller must also have the ohos.permission.GET_WIFI_LOCAL_MAC permission, which is available only for system applications. Without this permission, an all-zero address is returned in **groupOwnerAddr**.

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | Promise used to return the P2P connection information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |


## wifiManager.getP2pLinkedInfo<sup>9+</sup>

getP2pLinkedInfo(callback: AsyncCallback&lt;WifiP2pLinkedInfo&gt;): void

Obtains P2P link information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

To obtain **groupOwnerAddr**, the caller must also have the ohos.permission.GET_WIFI_LOCAL_MAC permission, which is available only for system applications. Without this permission, an all-zero address is returned in **groupOwnerAddr**.

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the P2P link information. If the operation fails, **err** is not **0**.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**Example**
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

Represents the P2P link information.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| connectState | [P2pConnectState](#p2pconnectstate9) | Yes| No| P2P connection state.|
| isGroupOwner | boolean | Yes| No| Whether it is the group owner (GO).|
| groupOwnerAddr | string | Yes| No| IP address of the group.| 


## P2pConnectState<sup>9+</sup>

Enumerates the P2P connection states.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Value| Description|
| -------- | -------- | -------- |
| DISCONNECTED | 0 | Disconnected.|
| CONNECTED | 1 | Connected.|

## wifiManager.getCurrentGroup<sup>9+</sup>

getCurrentGroup(): Promise&lt;WifiP2pGroupInfo&gt;

Obtains the current P2P group information. This API uses a promise to return the result.

**Required permissions**:

API version 10 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt; | Promise used to return the P2P group information obtained. If the caller has the ohos.permission.GET_WIFI_PEERS_MAC permission (available only for system applications), **deviceAddress** in the return value is a real device address. Otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.getCurrentGroup<sup>9+</sup>

getCurrentGroup(callback: AsyncCallback&lt;WifiP2pGroupInfo&gt;): void

Obtains the current P2P group information. This API uses an asynchronous callback to return the result.

**Required permissions**:

API version 10 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the group information obtained. If the operation fails, **error** is not **0**. If the caller has the ohos.permission.GET_WIFI_PEERS_MAC permission (available only for system applications), **deviceAddress** in the return value is a real device address. Otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';
	// The current group information can be obtained only after the P2P group is created or the connection is successful.
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

Obtains the peer device list in the P2P connection. This API uses a promise to return the result.

**Required permissions**:

API version 10 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Promise used to return the peer device list. If the caller has the ohos.permission.GET_WIFI_PEERS_MAC permission (available only for system applications), **deviceAddress** in the return value is a real device address. Otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.getP2pPeerDevices<sup>9+</sup>

getP2pPeerDevices(callback: AsyncCallback&lt;WifiP2pDevice[]&gt;): void

Obtains the peer device list in the P2P connection. This API uses an asynchronous callback to return the result.

**Required permissions**:

API version 10 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the peer device list obtained. If the operation fails, **err** is not **0**. If the caller has the ohos.permission.GET_WIFI_PEERS_MAC permission (available only for system applications), **deviceAddress** in the return value is a real device address. Otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';
	// The peer device list can be obtained only after the P2P discovery is complete.
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

Represents the P2P device information.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceName | string | Yes| No| Device name.|
| deviceAddress | string | Yes| No| MAC address of the device.|
| deviceAddressType<sup>10+</sup> | [DeviceAddressType](#deviceaddresstype10) | Yes| No| MAC address type of the device.|
| primaryDeviceType | string | Yes| No| Type of the primary device.|
| deviceStatus | [P2pDeviceStatus](#p2pdevicestatus9) | Yes| No| Device status.|
| groupCapabilities | number | Yes| No| Group capabilities.|


## P2pDeviceStatus<sup>9+</sup>

Enumerates the P2P device states.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Value| Description|
| -------- | -------- | -------- |
| CONNECTED | 0 | Connected.|
| INVITED | 1 | Invited.|
| FAILED | 2 | Failed.|
| AVAILABLE | 3 | Available.|
| UNAVAILABLE | 4 | Unavailable.|


## wifiManager.getP2pLocalDevice<sup>9+</sup>

getP2pLocalDevice(): Promise&lt;WifiP2pDevice&gt;

Obtains the local device information in the P2P connection. This API uses a promise to return the result.

**Required permissions**:

API version 11 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | Promise used to return the local device information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.getP2pLocalDevice<sup>9+</sup>

getP2pLocalDevice(callback: AsyncCallback&lt;WifiP2pDevice&gt;): void

Obtains the local device information in the P2P connection. This API uses an asynchronous callback to return the result.

**Required permissions**:

API version 11 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the local device information obtained. If the operation fails, **error** is not **0**.|

**Error codes**

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';
	// The local device information can be obtained only after a P2P group is created or the connection is successful.
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

Creates a P2P group.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| Mandatory| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiP2PConfig](#wifip2pconfig9) | Yes| Group configuration. The default **DeviceAddressType** is random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**Example**
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

Represents P2P group configuration.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceAddress | string | Yes| No| Device address.|
| deviceAddressType<sup>10+</sup>| [DeviceAddressType](#deviceaddresstype10) | Yes| No| Device address type.|
| netId | number | Yes| No| Network ID. The value **-1** indicates a temporary group, and **-2** indicates a persistent group.|
| passphrase | string | Yes| No| Passphrase of the group.|
| groupName | string | Yes| No| Name of the group.|
| goBand | [GroupOwnerBand](#groupownerband9) | Yes| No| Frequency band of the group.|


## GroupOwnerBand<sup>9+</sup>

Enumerates the P2P group frequency bands.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Value| Description|
| -------- | -------- | -------- |
| GO_BAND_AUTO | 0 | Auto.|
| GO_BAND_2GHZ | 1 | 2.4 GHz.|
| GO_BAND_5GHZ | 2 | 5 GHz.|


## wifiManager.removeGroup<sup>9+</sup>

removeGroup(): void

Removes this P2P group.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**Example**
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

Sets up a P2P connection.

**Required permissions**:

API version 10 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| Mandatory| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiP2PConfig](#wifip2pconfig9) | Yes| P2P group configuration. The default **DeviceAddressType** is random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**Example**
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

Cancels the P2P connection being set up.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**Example**
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

Starts to discover devices.

**Required permissions**:

API version 10 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**Example**
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

Stops discovering devices.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |
| 2801001  | Wi-Fi STA disabled. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.stopDiscoverDevices();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```



## WifiP2pGroupInfo<sup>9+</sup>

Represents the P2P group information.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| isP2pGo | boolean | Yes| No| Whether the device is the group owner.|
| ownerInfo | [WifiP2pDevice](#wifip2pdevice9) | Yes| No| Device information of the group.|
| passphrase | string | Yes| No| Passphrase of the group.|
| interface | string | Yes| No| Interface name.|
| groupName | string | Yes| No| Group name.|
| networkId | number | Yes| No| Network ID.|
| frequency | number | Yes| No| Frequency of the group.|
| clientDevices | [WifiP2pDevice[]](#wifip2pdevice9) | Yes| No| List of connected devices.|
| goIpAddress | string | Yes| No| IP address of the group.|


## wifiManager.on('wifiStateChange')<sup>9+</sup>

on(type: 'wifiStateChange', callback: Callback&lt;number&gt;): void

Subscribes to WLAN state changes. When the service exits, call off(type: 'wifiStateChange', callback?: Callback&lt;number&gt;) to unregister the callback registered.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiStateChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback used to return the WLAN state.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**WLAN states** 

| **Value**| **Description**|
| -------- | -------- |
| 0 | Deactivated|
| 1 | Activated|
| 2 | Activating|
| 3 | Deactivating|


## wifiManager.off('wifiStateChange')<sup>9+</sup>

off(type: 'wifiStateChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvPowerNotifyFunc = (result:number) => {
      console.info("Receive power state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("wifiStateChange", recvPowerNotifyFunc);
  
  // Unregister an event.
  wifiManager.off("wifiStateChange", recvPowerNotifyFunc);
```


## wifiManager.on('wifiConnectionChange')<sup>9+</sup>

on(type: 'wifiConnectionChange', callback: Callback&lt;number&gt;): void

Subscribes to WLAN connection state changes. When the service exits, call off(type: 'wifiConnectionChange', callback?: Callback&lt;number&gt;) to unregister the callback registered.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiConnectionChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback used to return the WLAN connection state.|

**WLAN connection states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Disconnected.|
| 1 | Connected.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('wifiConnectionChange')<sup>9+</sup>

off(type: 'wifiConnectionChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiConnectionChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvWifiConnectionChangeFunc = (result:number) => {
      console.info("Receive wifi connection change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("wifiConnectionChange", recvWifiConnectionChangeFunc);
  
  // Unregister an event.
  wifiManager.off("wifiConnectionChange", recvWifiConnectionChangeFunc);
```

## wifiManager.on('wifiScanStateChange')<sup>9+</sup>

on(type: 'wifiScanStateChange', callback: Callback&lt;number&gt;): void

Subscribes to WLAN scan state changes. When the service exits, call off(type: 'wifiScanStateChange', callback?: Callback&lt;number&gt;) to unregister the callback registered.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiScanStateChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback used to return the WLAN scan state.|

**WLAN scan states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Scan failed.|
| 1 | Scan successful.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('wifiScanStateChange')<sup>9+</sup>

off(type: 'wifiScanStateChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN scan state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiScanStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvWifiScanStateChangeFunc = (result:number) => {
      console.info("Receive Wifi scan state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("wifiScanStateChange", recvWifiScanStateChangeFunc);
  
  // Unregister an event.
  wifiManager.off("wifiScanStateChange", recvWifiScanStateChangeFunc);
```

## wifiManager.on('wifiRssiChange')<sup>9+</sup>

on(type: 'wifiRssiChange', callback: Callback&lt;number&gt;): void

Subscribes to RSSI changes. When the service exits, call off(type: 'wifiRssiChange', callback?: Callback&lt;number&gt;) to unregister the callback registered.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiRssiChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback used to return the RSSI, in dBm.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('wifiRssiChange')<sup>9+</sup>

off(type: 'wifiRssiChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from RSSI changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiRssiChange**.|
| callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvWifiRssiChangeFunc = (result:number) => {
      console.info("Receive wifi rssi change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("wifiRssiChange", recvWifiRssiChangeFunc);
  
  // Unregister an event.
  wifiManager.off("wifiRssiChange", recvWifiRssiChangeFunc);
```
 
## wifiManager.on('hotspotStateChange')<sup>9+</sup>

on(type: 'hotspotStateChange', callback: Callback&lt;number&gt;): void

Subscribes to hotspot state changes. When the service exits, call off(type: 'hotspotStateChange', callback?: Callback&lt;number&gt;) to unregister the callback registered.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStateChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the hotspot state.|

**Hotspot states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Deactivated|
| 1 | Activated|
| 2 | Activating|
| 3 | Deactivating|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

## wifiManager.off('hotspotStateChange')<sup>9+</sup>

off(type: 'hotspotStateChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from hotspot state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvHotspotStateChangeFunc = (result:number) => {
      console.info("Receive hotspot state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("hotspotStateChange", recvHotspotStateChangeFunc);
  
  // Unregister an event.
  wifiManager.off("hotspotStateChange", recvHotspotStateChangeFunc);
```


## wifiManager.on('p2pStateChange')<sup>9+</sup>

on(type: 'p2pStateChange', callback: Callback&lt;number&gt;): void

Subscribes to P2P state changes. When the service exits, call off(type: 'p2pStateChange', callback?: Callback&lt;number&gt;) to unregister the callback registered.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pStateChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the P2P state.|

**P2P states**

| **Value**| **Description**|
| -------- | -------- |
| 1 | Available|
| 2 | Opening|
| 3 | Opened|
| 4 | Closing|
| 5 | Closed|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pStateChange')<sup>9+</sup>

off(type: 'p2pStateChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from P2P state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pStateChangeFunc = (result:number) => {
      console.info("Receive p2p state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pStateChange", recvP2pStateChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pStateChange", recvP2pStateChangeFunc);
```

## wifiManager.on('p2pConnectionChange')<sup>9+</sup>

on(type: 'p2pConnectionChange', callback: Callback&lt;WifiP2pLinkedInfo&gt;): void

Subscribes to P2P connection state changes. When the service exits, call off(type: 'p2pConnectionChange', callback?: Callback&lt;WifiP2pLinkedInfo&gt;) to unregister the callback registered.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pConnectionChange**.|
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | Yes| Callback used to return the WLAN state.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pConnectionChange')<sup>9+</sup>

off(type: 'p2pConnectionChange', callback?: Callback&lt;WifiP2pLinkedInfo&gt;): void

Unsubscribes from P2P connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pConnectionChange**.|
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pConnectionChangeFunc = (result:wifiManager.WifiP2pLinkedInfo) => {
      console.info("Receive p2p connection change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pConnectionChange", recvP2pConnectionChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pConnectionChange", recvP2pConnectionChangeFunc);
```

## wifiManager.on('p2pDeviceChange')<sup>9+</sup>

on(type: 'p2pDeviceChange', callback: Callback&lt;WifiP2pDevice&gt;): void

Subscribes to P2P device status changes. When the service exits, call off(type: 'p2pDeviceChange', callback?: Callback&lt;WifiP2pDevice&gt;) to unregister the callback registered.

**Required permissions**:

API version 10 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | Yes| Callback used to return the WLAN state.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pDeviceChange')<sup>9+</sup>

off(type: 'p2pDeviceChange', callback?: Callback&lt;WifiP2pDevice&gt;): void

Unsubscribes from P2P device state changes.

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201<sup>10+</sup> | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pDeviceChangeFunc = (result:wifiManager.WifiP2pDevice) => {
      console.info("Receive p2p device change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pDeviceChange", recvP2pDeviceChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pDeviceChange", recvP2pDeviceChangeFunc);
```

## wifiManager.on('p2pPeerDeviceChange')<sup>9+</sup>

on(type: 'p2pPeerDeviceChange', callback: Callback&lt;WifiP2pDevice[]&gt;): void

Subscribes to P2P peer device status changes. When the service exits, call off(type: 'p2pPeerDeviceChange', callback?: Callback&lt;WifiP2pDevice[]&gt;) to unregister the callback registered.

**Required permissions**:

API version 10 and later: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pPeerDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Yes| Callback used to return the peer device status. If the caller has the ohos.permission.GET_WIFI_PEERS_MAC permission (available only for system applications), **deviceAddress** in the return value is a real device address. Otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pPeerDeviceChange')<sup>9+</sup>

off(type: 'p2pPeerDeviceChange', callback?: Callback&lt;WifiP2pDevice[]&gt;): void

Unsubscribes from P2P peer device state changes.

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pPeerDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event. If the caller has the ohos.permission.GET_WIFI_PEERS_MAC permission (available only for system applications), **deviceAddress** in the return value is a real device address. Otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201<sup>10+</sup> | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pPeerDeviceChangeFunc = (result:wifiManager.WifiP2pDevice[]) => {
      console.info("Receive p2p peer device change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
```

## wifiManager.on('p2pPersistentGroupChange')<sup>9+</sup>

on(type: 'p2pPersistentGroupChange', callback: Callback&lt;void&gt;): void

Subscribes to P2P persistent group changes. When the service exits, call off(type: 'p2pPersistentGroupChange', callback?: Callback&lt;void&gt;) to unregister the callback registered.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pPersistentGroupChange**.|
  | callback | Callback&lt;void&gt; | Yes| Callback used to return the WLAN state.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pPersistentGroupChange')<sup>9+</sup>

off(type: 'p2pPersistentGroupChange', callback?: Callback&lt;void&gt;): void

Unsubscribes from P2P persistent group state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pPersistentGroupChange**.|
| callback | Callback&lt;void&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pPersistentGroupChangeFunc = (result:void) => {
      console.info("Receive p2p persistent group change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
```

## wifiManager.on('p2pDiscoveryChange')<sup>9+</sup>

on(type: 'p2pDiscoveryChange', callback: Callback&lt;number&gt;): void

Subscribes to P2P device discovery changes. When the service exits, call off(type: 'p2pDiscoveryChange', callback?: Callback&lt;number&gt;) to unregister the callback registered.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDiscoveryChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback used to return the P2P device discovery change.|

**P2P discovered device states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Initial state.|
| 1 | Discovered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

## wifiManager.off('p2pDiscoveryChange')<sup>9+</sup>

off(type: 'p2pDiscoveryChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from P2P device discovery state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDiscoveryChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | ---------------------------- |
| 201 | Permission denied.                 |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
  import { wifiManager } from '@kit.ConnectivityKit';
  
  let recvP2pDiscoveryChangeFunc = (result:number) => {
      console.info("Receive p2p discovery change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
```
