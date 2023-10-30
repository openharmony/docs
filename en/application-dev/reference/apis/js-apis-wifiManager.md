# @ohos.wifiManager (WLAN)
The **WLAN** module provides basic wireless local area network (WLAN) functions, peer-to-peer (P2P) functions, and WLAN message notification services. It allows applications to communicate with devices over WLAN.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import wifiManager from '@ohos.wifiManager';
```

## wifiManager.enableWifi<sup>9+</sup>

enableWifi(): void

Enables WLAN. This API is an asynchronous interface. The **wifiStateChange** callback must be registered and listened for.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501003  | Failed to enable Wi-Fi.|

**Example**

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.enableWifi();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.disableWifi<sup>9+</sup>

disableWifi(): void

Disables WLAN. This API is an asynchronous interface. The **wifiStateChange** callback must be registered and listened for.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501004  | Failed to disable Wi-Fi.|

**Example**

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.disableWifi();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.isWifiActive<sup>9+</sup>

isWifiActive(): boolean

Checks whether WLAN is enabled.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if WLAN is enabled; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let isWifiActive = wifiManager.isWifiActive();
		console.info("isWifiActive:" + isWifiActive);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.scan<sup>9+</sup>

scan(): void

Starts a scan for WLAN.

**Required permissions**:

API version 9: ohos.permission.SET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.scan();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.startScan<sup>10+</sup>

startScan(): void

**System API**: This is a system API.

Starts a scan for WLAN.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.startScan();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```
## wifiManager.getScanResults<sup>9+</sup>

getScanResults(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt;

Obtains the scan result. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&nbsp;&gt; | Promise used to return the hotspots detected.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

## wifiManager.getScanResults<sup>9+</sup>

getScanResults(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void

Obtains the scan result. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the detected hotspots. Otherwise, **err** is a non-zero value and **data** is empty.|
| Array&lt;[WifiScanInfo](#wifiscaninfo)&gt; | Hotspots detected.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
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
  });
```

## wifiManager.getScanResultsSync<sup>9+</sup>

getScanResultsSync(): &nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;

Obtains the scan result. This API returns the result synchronously.

**Required permissions**: ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| &nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt; | Scan result obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

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

## wifiManager.getScanInfoList<sup>10+</sup>

getScanInfoList(): Array&lt;WifiScanInfo&gt;;

Obtains the scanning result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Array&lt;[WifiScanInfo](#wifiscaninfo)&gt; | Hotspots detected. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **bssid** in the return value is a real device address; otherwise, **bssid** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

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

## WifiScanInfo<sup>9+</sup>

Represents WLAN hotspot information.

**System capability**: SystemCapability.Communication.WiFi.STA


| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| Service set identifier (SSID) of the hotspot, in UTF-8 format.|
| bssid | string | Yes| No| Basic service set identifier (BSSID) of the hotspot.|
| bssidType<sup>10+</sup>| DeviceAddressType | Yes| No| BSSID type of the hotspot.|
| capabilities | string | Yes| No| Hotspot capabilities.|
| securityType | [WifiSecurityType](#wifisecuritytype) | Yes| No| WLAN security type.|
| rssi | number | Yes| No| Received signal strength indicator (RSSI) of the hotspot, in dBm.|
| band | number | Yes| No| Frequency band of the WLAN access point (AP).|
| frequency | number | Yes| No| Frequency of the WLAN AP.|
| channelWidth | number | Yes| No| Channel width of the WLAN AP.|
| centerFrequency0 | number | Yes| No| Center frequency of the hotspot.|
| centerFrequency1 | number | Yes| No| Center frequency of the hotspot. If the hotspot uses two non-overlapping WLAN channels, two center frequencies, namely **centerFrequency0** and **centerFrequency1**, are returned.|
| infoElems | Array&lt;[WifiInfoElem](#wifiinfoelem9)&gt; | Yes| No| Information elements.|
| timestamp | number | Yes| No| Timestamp.|

## DeviceAddressType <sup>10+</sup>

Enumerates the Wi-Fi device address (MAC/BSSID) types.

**System capability**: SystemCapability.Communication.WiFi.Core

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
| WIFI_SEC_TYPE_OPEN | 1 | Open security type.|
| WIFI_SEC_TYPE_WEP | 2 | Wired Equivalent Privacy (WEP).|
| WIFI_SEC_TYPE_PSK | 3 | Pre-shared key (PSK).|
| WIFI_SEC_TYPE_SAE | 4 | Simultaneous Authentication of Equals (SAE).|
| WIFI_SEC_TYPE_EAP<sup>9+</sup> | 5 | Extensible Authentication protocol (EAP).|
| WIFI_SEC_TYPE_EAP_SUITE_B<sup>9+</sup> | 6 | Suite B 192-bit encryption.|
| WIFI_SEC_TYPE_OWE<sup>9+</sup> | 7 | Opportunistic Wireless Encryption (OWE).|
| WIFI_SEC_TYPE_WAPI_CERT<sup>9+</sup> | 8 | WLAN Authentication and Privacy Infrastructure (WAPI) in certificate-based mode (WAPI-CERT).|
| WIFI_SEC_TYPE_WAPI_PSK<sup>9+</sup> | 9 | WAPI-PSK.|


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

## wifiManager.setScanAlwaysAllowed<sup>10+</sup>

setScanAlwaysAllowed(isScanAlwaysAllowed: boolean): void

Sets whether scan is always allowed.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| isScanAlwaysAllowed | boolean | Yes| Whether scan is always allowed.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let isScanAlwaysAllowed = true;
		wifiManager.setScanAlwaysAllowed(isScanAlwaysAllowed);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getScanAlwaysAllowed<sup>10+</sup>

getScanAlwaysAllowed(): boolean

Obtains whether scan is always allowed.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean| Whether scan is always allowed. The value **true** means scan is allowed; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let isScanAlwaysAllowed = wifiManager.getScanAlwaysAllowed();
		console.info("isScanAlwaysAllowed:" + isScanAlwaysAllowed);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.addDeviceConfig<sup>9+</sup>

addDeviceConfig(config: WifiDeviceConfig): Promise&lt;number&gt;

Adds network configuration. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the ID of the added network configuration. If **-1** is returned, the network configuration fails to be added.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let config:wifiManager.WifiDeviceConfig = {
			ssid : "****",
			preSharedKey : "****",
			securityType : 0
		}
		wifiManager.addDeviceConfig(config).then(result => {
			console.info("result:" + JSON.stringify(result));
		});	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## WifiDeviceConfig<sup>9+</sup>

Represents the WLAN configuration.

**System capability**: SystemCapability.Communication.WiFi.STA


| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| SSID of the hotspot, in UTF-8 format.|
| bssid | string | Yes| No| BSSID of the hotspot.|
| bssidType<sup>10+</sup> | DeviceAddressType | Yes| No| BSSID type of the hotspot.|
| preSharedKey | string | Yes| No| PSK of the hotspot.|
| isHiddenSsid | boolean | Yes| No| Whether the network is hidden.|
| securityType | [WifiSecurityType](#wifisecuritytype) | Yes| No| Security type.|
| creatorUid | number | Yes| No| ID of the creator.<br>**System API**: This is a system API.|
| disableReason | number | Yes| No| Reason for disabling WLAN.<br>**System API**: This is a system API.|
| netId | number | Yes| No| Network ID.<br>**System API**: This is a system API.|
| randomMacType | number | Yes| No| Type of the MAC address. <br>The value **0** indicates random MAC address, and **1** indicates device MAC address.<br>**System API**: This is a system API.|
| randomMacAddr | string | Yes| No| MAC address.<br>**System API**: This is a system API.|
| ipType | [IpType](#iptype9) | Yes| No| IP address type.<br>**System API**: This is a system API.|
| staticIp | [IpConfig](#ipconfig9) | Yes| No| Static IP address information.<br>**System API**: This is a system API.|
| eapConfig<sup>10+</sup> | [WifiEapConfig](#wifieapconfig10) | Yes| No| EAP configuration.|
| proxyConfig<sup>10+</sup> | WifiProxyConfig | Yes| No| Proxy configuration.<br>**System API**: This is a system API.|

## IpType<sup>9+</sup>

Enumerates the IP address types.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA


| Name| Value| Description|
| -------- | -------- | -------- |
| STATIC | 0 | Static IP address.|
| DHCP | 1 | IP address allocated by DHCP.|
| UNKNOWN | 2 | Not specified.|


## IpConfig<sup>9+</sup>

Represents IP configuration information.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | Yes| No| IP address.|
| gateway | number | Yes| No| Gateway.|
| prefixLength | number | Yes| No| Subnet mask.|
| dnsServers | number[] | Yes| No| Domain name server (DNS) information.|
| domains | Array&lt;string&gt; | Yes| No| Domain information.|


## WifiEapConfig<sup>10+</sup>

Represents EAP configuration information.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| eapMethod | [EapMethod](#eapmethod10) | Yes| No| EAP authentication method.|
| phase2Method | [Phase2Method](#phase2method10) | Yes| No| Phase 2 authentication method.|
| identity | string | Yes| No| Identity Information.|
| anonymousIdentity | string | Yes| No| Anonymous identity.|
| password | string | Yes| No| Password.|
| caCertAlias | string | Yes| No| CA certificate alias.|
| caPath | string | Yes| No| CA certificate path.|
| clientCertAlias | string | Yes| No| Client certificate alias.|
| certEntry | Uint8Array | Yes| Yes| CA certificate content.|
| certPassword | string | Yes| Yes| CA certificate password.|
| altSubjectMatch | string | Yes| No| A string to match the alternate subject.|
| domainSuffixMatch | string | Yes| No| A string to match the domain suffix.|
| realm | string | Yes| No| Realm for the passpoint credential.|
| plmn | string | Yes| No| Public land mobile network (PLMN) of the passpoint credential provider.|
| eapSubId | number | Yes| No| Sub-ID of the SIM card.|


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
| PHASE2_GTC | 4 | GTC .|
| PHASE2_SIM | 5 | SIM.|
| PHASE2_AKA | 6 | AKA.|
| PHASE2_AKA_PRIME | 7 | AKA Prime.|


## WifiProxyConfig <sup>10+</sup>

Represents the Wi-Fi proxy configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| proxyMethod | ProxyMethod | Yes| No| Proxy method.|
| pacWebAddress | string | Yes| No| PAC web address of the proxy automatically configured.|
| serverHostName | string | Yes| No| Server host name of the proxy manually configured.|
| serverPort | string | Yes| No| Server port of the proxy manually configured.|
| exclusionObjects | string | Yes| No| Excluded objects of the manually configured proxy. Multiple objects are separated by commas (,).|

## ProxyMethod<sup>10+</sup>

Enumerates the Wi-Fi proxy methods.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| METHOD_NONE  | 0 | No proxy.|
| METHOD_AUTO  | 1 | Use an automatically configured proxy.|
| METHOD_MANUAL  | 2 | Use a manually configured proxy.|

## wifiManager.addDeviceConfig<sup>9+</sup>

addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void

Adds network configuration. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the network configuration ID. If **data** is **-1**, the operation has failed. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```ts
	import wifiManager from '@ohos.wifiManager';

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

## wifiManager.addCandidateConfig<sup>9+</sup>

addCandidateConfig(config: WifiDeviceConfig): Promise&lt;number&gt;

Adds the configuration of a candidate network. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the network configuration ID.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
`````ts
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
`````

## wifiManager.addCandidateConfig<sup>9+</sup>

addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void

Adds the configuration of a candidate network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the network configuration ID. If **data** is **-1**, the operation has failed. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
`````ts
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
`````

## wifiManager.removeCandidateConfig<sup>9+</sup>

removeCandidateConfig(networkId: number): Promise&lt;void&gt;

Removes the configuration of a candidate network. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

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

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

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

## wifiManager.removeCandidateConfig<sup>9+</sup>

removeCandidateConfig(networkId: number, callback: AsyncCallback&lt;void&gt;): void

Removes the configuration of a candidate network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| networkId | number | Yes| ID of the network configuration to remove.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0**. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
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

## wifiManager.getCandidateConfigs<sup>9+</sup>

getCandidateConfigs(): &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig)&gt;

Obtains candidate network configuration.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig)&gt; | Candidate network configuration obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

`````ts
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
	
`````

## wifiManager.connectToCandidateConfig<sup>9+</sup>

connectToCandidateConfig(networkId: number): void

Connects to a candidate network added by the application. If the device is already connected to a hotspot, disconnect it from the hotspot first.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| networkId | number | Yes| ID of the candidate network configuration.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
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

## wifiManager.connectToNetwork<sup>9+</sup>

connectToNetwork(networkId: number): void

Connects to the specified network. If the device is already connected to a hotspot, use **disconnect()** to disconnect it from the hotspot first.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| networkId | number | Yes| Network configuration ID.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**

```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let networkId = 0;
		wifiManager.connectToNetwork(networkId);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}	
```

## wifiManager.connectToDevice<sup>9+</sup>

connectToDevice(config: WifiDeviceConfig): void

Connects to the specified network. If the device is already connected to a hotspot, use **disconnect()** to disconnect it from the hotspot first.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO, ohos.permission.SET_WIFI_CONFIG, and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**:
  SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| Configuration of the WLAN to connect. The default **bssidType** is random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

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

## wifiManager.disconnect<sup>9+</sup>

disconnect(): void

Disconnects the network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**:
  SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.disconnect();
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
| band | number | Yes| Frequency band of the WLAN AP.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| number | Signal level obtained. The value range is [0, 4].|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
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

## wifiManager.getLinkedInfo<sup>9+</sup>

getLinkedInfo(): Promise&lt;WifiLinkedInfo&gt;

Obtains WLAN connection information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_LOCAL_MAC (if **macAddress** needs to be obtained; otherwise, **macAddress** is an empty string.)

 **System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[WifiLinkedInfo](#wifilinkedinfo)&gt; | Promise used to return the WLAN connection information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

## wifiManager.getLinkedInfo<sup>9+</sup>

getLinkedInfo(callback: AsyncCallback&lt;WifiLinkedInfo&gt;): void

Obtains WLAN connection information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_LOCAL_MAC (if **macAddress** needs to be obtained; otherwise, **macAddress** is an empty string.)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiLinkedInfo](#wifilinkedinfo)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the WLAN connection information obtained. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  wifiManager.getLinkedInfo((err, data) => {
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

Represents the WLAN connection information.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| SSID of the hotspot, in UTF-8 format.|
| bssid | string | Yes| No| BSSID of the hotspot.|
| networkId | number | Yes| No| Network configuration ID.<br>**System API**: This is a system API.|
| rssi | number | Yes| No| RSSI of the hotspot, in dBm.|
| band | number | Yes| No| Band of the WLAN AP.|
| linkSpeed | number | Yes| No| Uplink speed of the WLAN AP.|
| rxLinkSpeed<sup>10+</sup> | number | Yes| No| Downlink speed of the WLAN AP.|
| maxSupportedTxLinkSpeed<sup>10+</sup> | number | Yes| No| Maximum uplink speed supported.|
| maxSupportedRxLinkSpeed<sup>10+</sup> | number | Yes| No| Maximum uplink speed supported.|
| frequency | number | Yes| No| Frequency of the WLAN AP.|
| isHidden | boolean | Yes| No| Whether to hide the WLAN AP.|
| isRestricted | boolean | Yes| No| Whether to restrict data volume at the WLAN AP.|
| chload | number | Yes| No| Channel load. A larger value indicates a higher load.<br>**System API**: This is a system API.|
| snr | number | Yes| No| Signal-to-noise ratio (SNR).<br>**System API**: This is a system API.|
| macType | number | Yes| No| MAC address type. <br>The value **0** indicates random MAC address, and **1** indicates device MAC address.|
| macAddress | string | Yes| No| MAC address of the device.|
| ipAddress | number | Yes| No| IP address of the device that sets up the WLAN connection.|
| suppState | [SuppState](#suppstate) | Yes| No| Supplicant state.<br>**System API**: This is a system API.|
| connState | [ConnState](#connstate) | Yes| No| WLAN connection state.|
| channelWidth<sup>10+</sup> | [WifiChannelWidth](#wifichannelwidth) | Yes| No| Channel bandwidth of the connected hotspot.|
| wifiStandard<sup>10+</sup> | [WifiStandard](#wifistandard) | Yes| No| Wi-Fi standard used by the connected hotspot.|

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


## SuppState<sup>9+</sup>

Enumerates the supplicant states.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| DISCONNECTED | 0 | The supplicant is disconnected from the AP.|
| INTERFACE_DISABLED | 1 | The network interface is disabled.|
| INACTIVE | 2 | The supplicant is inactive.|
| SCANNING | 3 | The supplicant is scanning for a WLAN connection.|
| AUTHENTICATING | 4 | The supplicant is being authenticated.|
| ASSOCIATING | 5 | The supplicant is being associated with an AP.|
| ASSOCIATED | 6 | The supplicant is associated with an AP.|
| FOUR_WAY_HANDSHAKE | 7 | A four-way handshake is being performed for the supplicant.|
| GROUP_HANDSHAKE | 8 | A group handshake is being performed for the supplicant.|
| COMPLETED | 9 | The authentication is complete.|
| UNINITIALIZED | 10 | The supplicant failed to set up the connection.|
| INVALID | 11 | Invalid value.|

## wifiManager.isConnected<sup>9+</sup>

isConnected(): boolean

Checks whether the WLAN is connected.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the WLAN is connected; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let ret = wifiManager.isConnected();
		console.info("isConnected:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifiManager.getSupportedFeatures<sup>9+</sup>

getSupportedFeatures(): number

Obtains the features supported by this device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| number | Feature value. |

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

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2401000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let ret = wifiManager.getSupportedFeatures();
		console.info("supportedFeatures:" + ret);
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

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the feature is supported; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2401000  | Operation failed.|

**Example**
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

## wifiManager.getDeviceMacAddress<sup>9+</sup>

getDeviceMacAddress(): string[]

Obtains the device MAC address.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_LOCAL_MAC and ohos.permission.GET_WIFI_INFO (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| string[] | MAC address obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501001  | wifi is closed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let ret = wifiManager.getDeviceMacAddress();
		console.info("deviceMacAddress:" + JSON.stringify(ret));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifiManager.getIpInfo<sup>9+</sup>

getIpInfo(): IpInfo

Obtains IP information.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| [IpInfo](#ipinfo9) | IP information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let info = wifiManager.getIpInfo();
		console.info("info:" + JSON.stringify(info));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## IpInfo<sup>9+</sup>

Represents IP information.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | Yes| No| IP address.|
| gateway | number | Yes| No| Gateway.|
| netmask | number | Yes| No| Subnet mask.|
| primaryDns | number | Yes| No| IP address of the preferred DNS server.|
| secondDns | number | Yes| No| IP address of the alternate DNS server.|
| serverIp | number | Yes| No| IP address of the DHCP server.|
| leaseDuration | number | Yes| No| Lease duration of the IP address.|


## wifiManager.getIpv6Info<sup>10+</sup>

getIpv6Info(): Ipv6Info

Obtains IP information.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Ipv6Info | IPv6 information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let info = wifiManager.getIpv6Info();
		console.info("info:" + JSON.stringify(info));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```
## Ipv6Info <sup>10+</sup>

Represents the IPv6 information.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| linkIpv6Address | string | Yes| No| IPv6 address of the link.|
| globalIpv6Address | string | Yes| No| Global IPv6 address.|
| randomGlobalIpv6Address | string | Yes| No| Random global IPv6 address.|
| gateway | string | Yes| No| Gateway IP address.|
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

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2401000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let code = wifiManager.getCountryCode();
		console.info("code:" + code);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.reassociate<sup>9+</sup>

reassociate(): void

Re-associates with the network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.reassociate();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.reconnect<sup>9+</sup>

reconnect(): void

Reconnects to the network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.reconnect();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getDeviceConfigs<sup>9+</sup>

getDeviceConfigs(): &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig)&gt;

Obtains network configuration.

**System API**: This is a system API.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, ohos.permission.APPROXIMATELY_LOCATION, and ohos.permission.GET_WIFI_CONFIG

API version 10 and later: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig)&gt; | Array of network configuration obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let configs = wifiManager.getDeviceConfigs();
		console.info("configs:" + JSON.stringify(configs));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.updateNetwork<sup>9+</sup>

updateNetwork(config: WifiDeviceConfig): number

Updates network configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| New WLAN configuration.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| number | ID of the updated network configuration. The value **-1** indicates that the operation has failed.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

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

Disables network configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| netId | number | Yes| ID of the network configuration to disable.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let netId = 0;
		wifiManager.disableNetwork(netId);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.removeAllNetwork<sup>9+</sup>

removeAllNetwork(): void

Removes the configuration of all networks.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.removeAllNetwork();		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.removeDevice<sup>9+</sup>

removeDevice(id: number): void

Removes the specified network configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| id | number | Yes| ID of the network configuration to remove.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let id = 0;
		wifiManager.removeDevice(id);		
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
| bandType | WifiBandType | Yes| Wi-Fi band type.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the feature is supported; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
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

## wifiManager.get5GChannelList<sup>10+</sup>

get5GChannelList(): Array&lt;number&gt;

Obtains the list of 5 GHz channels supported by this device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| &nbsp;Array&lt;number&gt; | List of 5 GHz channels supported by the device.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let channelList = wifiManager.get5GChannelList();
		console.info("channelList:" + JSON.stringify(channelList));		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```
## wifiManager.getDisconnectedReason<sup>10+</sup>

getDisconnectedReason(): DisconnectedReason

Obtains the reason of the latest disconnection.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| DisconnectedReason | Returns the reason of the latest disconnection obtained.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let disconnectedReason = wifiManager.getDisconnectedReason();	
        console.info("disconnectedReason:" + disconnectedReason);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## DisconnectedReason <sup>10+</sup>

Enumerates the Wi-Fi disconnection reasons.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| DISC_REASON_DEFAULT  | 0 | Default reason.|
| DISC_REASON_WRONG_PWD  | 1 | Incorrect password.|
| DISC_REASON_CONNECTION_FULL  | 2 | The number of connections to the router has reached the limit.|

## wifiManager.enableHotspot<sup>9+</sup>

enableHotspot(): void

Enables this hotspot. This API is an asynchronous interface. The **hotspotStateChange** callback must be registered and listened for.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.enableHotspot();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.disableHotspot<sup>9+</sup>

disableHotspot(): void

Disables this hotspot. This API is an asynchronous interface. The **hotspotStateChange** callback must be registered and listened for.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.disableHotspot();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.isHotspotDualBandSupported<sup>9+</sup>

isHotspotDualBandSupported(): boolean

Checks whether the hotspot supports dual band.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the hotspot supports dual band; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let ret = wifiManager.isHotspotDualBandSupported();
		console.info("result:" + ret);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.isHotspotActive<sup>9+</sup>

isHotspotActive(): boolean

Checks whether this hotspot is active.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the hotspot is active; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let ret = wifiManager.isHotspotActive();
		console.info("result:" + ret);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.setHotspotConfig<sup>9+</sup>

setHotspotConfig(config: HotspotConfig): void

Sets hotspot configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [HotspotConfig](#hotspotconfig9) | Yes| Hotspot configuration to set.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

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

Represents the hotspot configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| Yes| SSID of the hotspot, in UTF-8 format.|
| securityType | [WifiSecurityType](#wifisecuritytype) | Yes| Yes| Security type.|
| band | number | Yes| Yes| Hotspot band. The value **1** stands for 2.4 GHz, the value **2** for 5 GHz, and the value **3** for dual band.|
| channel<sup>10+</sup> | number | Yes| Yes| Hotspot channel (2.4 GHz: 1 to 14; 5 GHz: 7 to 196; Dual-band: not supported currently) |
| preSharedKey | string | Yes| Yes| PSK of the hotspot.|
| maxConn | number | Yes| Yes| Maximum number of connections allowed.|

## wifiManager.getHotspotConfig<sup>9+</sup>

getHotspotConfig(): HotspotConfig

Obtains hotspot configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| [HotspotConfig](#hotspotconfig9) | Hotspot configuration obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let config = wifiManager.getHotspotConfig();
		console.info("result:" + JSON.stringify(config));		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getStations<sup>9+</sup>

getStations(): &nbsp;Array&lt;[StationInfo](#stationinfo9)&gt;

Obtains information about the connected stations.

**System API**: This is a system API.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, ohos.permission.APPROXIMATELY_LOCATION, and ohos.permission.MANAGE_WIFI_HOTSPOT (for system applications only)

API version 10 and later: ohos.permission.GET_WIFI_INFO and ohos.permission.MANAGE_WIFI_HOTSPOT (for system applications only)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| &nbsp;Array&lt;[StationInfo](#stationinfo9)&gt; | Connected stations obtained. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **macAddress** in the return value is a real MAC address; otherwise, **macAddress** is a random MAC address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let stations = wifiManager.getStations();
		console.info("result:" + JSON.stringify(stations));		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## StationInfo<sup>9+</sup>

Represents the station information.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| name | string | Yes| No| Device name.|
| macAddress | string | Yes| No| MAC address.|
| macAddressType<sup>10+</sup> | DeviceAddressType | Yes| No| MAC address type.|
| ipAddress | string | Yes| No| IP address.|


## wifiManager.getP2pLinkedInfo<sup>9+</sup>

getP2pLinkedInfo(): Promise&lt;WifiP2pLinkedInfo&gt;

Obtains P2P link information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | Promise used to return the P2P link information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	wifiManager.getP2pLinkedInfo((err, data) => {
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
| isGroupOwner | boolean | Yes| No| Whether the device is the group owner.|
| groupOwnerAddr | string | Yes| No| MAC address of the group.


## P2pConnectState<sup>9+</sup>

Enumerates the P2P connection states.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Value| Description|
| -------- | -------- | -------- |
| DISCONNECTED | 0 | Disconnected.|
| CONNECTED | 1 | Connected.|


## wifiManager.getP2pLinkedInfo<sup>9+</sup>

getP2pLinkedInfo(callback: AsyncCallback&lt;WifiP2pLinkedInfo&gt;): void

Obtains P2P link information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the P2P link information. If **err** is not **0**, an error has occurred.|


## wifiManager.getCurrentGroup<sup>9+</sup>

getCurrentGroup(): Promise&lt;WifiP2pGroupInfo&gt;

Obtains the current P2P group information. This API uses a promise to return the result.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt; | Promise used to return the P2P group information obtained. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.getCurrentGroup<sup>9+</sup>

getCurrentGroup(callback: AsyncCallback&lt;WifiP2pGroupInfo&gt;): void

Obtains the current P2P group information. This API uses an asynchronous callback to return the result.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the group information obtained. If **err** is not **0**, an error has occurred. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	wifiManager.getCurrentGroup((err, data) => {
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

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Promise used to return the peer device list. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.getP2pPeerDevices<sup>9+</sup>

getP2pPeerDevices(callback: AsyncCallback&lt;WifiP2pDevice[]&gt;): void

Obtains the peer device list in the P2P connection. This API uses an asynchronous callback to return the result.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the peer device list obtained. If **err** is not **0**, an error has occurred. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	wifiManager.getP2pPeerDevices((err, data) => {
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
| deviceAddressType<sup>10+</sup> | DeviceAddressType | Yes| No| MAC address type of the device.|
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

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | Promise used to return the local device information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.getP2pLocalDevice<sup>9+</sup>

getP2pLocalDevice(callback: AsyncCallback&lt;WifiP2pDevice&gt;): void

Obtains the local device information in the P2P connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the local device information obtained. If **err** is not **0**, an error has occurred.|

**Error codes**

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	wifiManager.getP2pLocalDevice((err, data) => {
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

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
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

## WifiP2PConfig<sup>9+</sup>

Represents P2P group configuration.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceAddress | string | Yes| No| Device address.|
| deviceAddressType<sup>10+</sup>| DeviceAddressType | Yes| No| Device address type.|
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
| GO_BAND_2GHZ | 1 | 2 GHz.|
| GO_BAND_5GHZ | 2 | 5 GHz.|


## wifiManager.removeGroup<sup>9+</sup>

removeGroup(): void

Removes this P2P group.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

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

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| Mandatory| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiP2PConfig](#wifip2pconfig9) | Yes| P2P group configuration. The default **DeviceAddressType** is random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvP2pConnectionChangeFunc = (result:wifiManager.WifiP2pLinkedInfo) => {
      console.info("p2p connection change receive event: " + JSON.stringify(result));
      wifiManager.getP2pLinkedInfo((err, data) => {
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
      wifiManager.getP2pPeerDevices((err, data) => {
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
  
      wifiManager.getCurrentGroup((err, data) => {
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

Cancels this P2P connection.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

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

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

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

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		wifiManager.stopDiscoverDevices();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.deletePersistentGroup<sup>9+</sup>

deletePersistentGroup(netId: number): void

Deletes a persistent group.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**


| **Name**| **Type**| Mandatory| **Description**|
| -------- | -------- | -------- | -------- |
| netId | number | Yes| ID of the group to delete.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let netId = 0;
		wifiManager.deletePersistentGroup(netId);	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getP2pGroups<sup>9+</sup>

getP2pGroups(): Promise&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;

Obtains information about all P2P groups. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt;&nbsp;&gt; | Promise used to return the group information obtained. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	wifiManager.getP2pGroups((err, data) => {
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


## wifiManager.getP2pGroups<sup>9+</sup>

getP2pGroups(callback: AsyncCallback&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;): void

Obtains information about all P2P groups. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt;&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the group information obtained. If **err** is not **0**, an error has occurred. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.setDeviceName<sup>9+</sup>

setDeviceName(devName: string): void

Sets the device name.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| devName | string | Yes| Device name to set.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
	import wifiManager from '@ohos.wifiManager';

	try {
		let name = "****";
		wifiManager.setDeviceName(name);	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.on('wifiStateChange')<sup>9+</sup>

on(type: "wifiStateChange", callback: Callback&lt;number&gt;): void

Subscribes to WLAN state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiStateChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the WLAN state.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**WLAN states** 

| **Value**| **Description**|
| -------- | -------- |
| 0 | Deactivated|
| 1 | Activated|
| 2 | Activating|
| 3 | Deactivating|


## wifiManager.off('wifiStateChange')<sup>9+</sup>

off(type: "wifiStateChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the WLAN state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvPowerNotifyFunc = (result:number) => {
      console.info("Receive power state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("wifiStateChange", recvPowerNotifyFunc);
  
  // Unregister an event.
  wifiManager.off("wifiStateChange", recvPowerNotifyFunc);
```


## wifiManager.on('wifiConnectionChange')<sup>9+</sup>

on(type: "wifiConnectionChange", callback: Callback&lt;number&gt;): void

Subscribes to WLAN connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiConnectionChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the WLAN connection state.|

**WLAN connection states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Disconnected.|
| 1 | Connected.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

## wifiManager.off('wifiConnectionChange')<sup>9+</sup>

off(type: "wifiConnectionChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiConnectionChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the WLAN connection state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvWifiConnectionChangeFunc = (result:number) => {
      console.info("Receive wifi connection change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("wifiConnectionChange", recvWifiConnectionChangeFunc);
  
  // Unregister an event.
  wifiManager.off("wifiConnectionChange", recvWifiConnectionChangeFunc);
```

## wifiManager.on('wifiScanStateChange')<sup>9+</sup>

on(type: "wifiScanStateChange", callback: Callback&lt;number&gt;): void

Subscribes to WLAN scan state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiScanStateChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the WLAN scan state.|

**WLAN scan states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Scan failed.|
| 1 | Scan successful.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

## wifiManager.off('wifiScanStateChange')<sup>9+</sup>

off(type: "wifiScanStateChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN scan state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiScanStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the WLAN scan state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvWifiScanStateChangeFunc = (result:number) => {
      console.info("Receive Wifi scan state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("wifiScanStateChange", recvWifiScanStateChangeFunc);
  
  // Unregister an event.
  wifiManager.off("wifiScanStateChange", recvWifiScanStateChangeFunc);
```

## wifiManager.on('wifiRssiChange')<sup>9+</sup>

on(type: "wifiRssiChange", callback: Callback&lt;number&gt;): void

Subscribes to RSSI changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiRssiChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the RSSI, in dBm.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

## wifiManager.off('wifiRssiChange')<sup>9+</sup>

off(type: "wifiRssiChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from RSSI changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiRssiChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the RSSI change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvWifiRssiChangeFunc = (result:number) => {
      console.info("Receive wifi rssi change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("wifiRssiChange", recvWifiRssiChangeFunc);
  
  // Unregister an event.
  wifiManager.off("wifiRssiChange", recvWifiRssiChangeFunc);
```
 ## wifiManager.on('streamChange')<sup>9+</sup>

on(type: "streamChange", callback: Callback&lt;number&gt;): void

Subscribes to Wi-Fi stream changes. This API is not supported in the current version, and error code 801 will be thrown.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **streamChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the stream change, which can be any of the following values:<br>- **0**: No stream.<br>- **1**: Downward.<br>- **2**: Upward.<br>- **3**: Bidirectional.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

## wifiManager.off('streamChange')<sup>9+</sup>

off(type: "streamChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from Wi-Fi stream changes. This API is not supported in the current version, and error code 801 will be thrown.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **streamChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the stream change, which can be any of the following values:<br>- **0**: No stream.<br>- **1**: Downward.<br>- **2**: Upward.<br>- **3**: Bidirectional.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvStreamChangeFunc = (result:number) => {
    console.info("Receive stream change event: " + result);
}

// Register an event.
wifi.on("streamChange", recvStreamChangeFunc);

// Unregister an event.
wifi.off("streamChange", recvStreamChangeFunc);

```
## wifiManager.on('deviceConfigChange')<sup>9+</sup>

on(type: "deviceConfigChange", callback: Callback&lt;number&gt;): void

Subscribes to Wi-Fi device configuration changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **deviceConfigChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the device configuration change, which can be any of the following values:<br>- **0**: device configuration added.<br>- **1**: device configuration changed.<br>- **2**: device configuration deleted.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

## wifiManager.off('deviceConfigChange')<sup>9+</sup>

off(type: "deviceConfigChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from Wi-Fi device configuration changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **deviceConfigChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback for the device configuration change, which can be any of the following values:<br>- **0**: device configuration added.<br>- **1**: device configuration changed.<br>- **2**: device configuration deleted.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
import wifi from '@ohos.wifiManager';

let recvDeviceConfigChangeFunc = (result:number) => {
    console.info("Receive device config change event: " + result);
}

// Register an event.
wifi.on("deviceConfigChange", recvDeviceConfigChangeFunc);

// Unregister an event.
wifi.off("deviceConfigChange", recvDeviceConfigChangeFunc);

```

## wifiManager.on('hotspotStateChange')<sup>9+</sup>

on(type: "hotspotStateChange", callback: Callback&lt;number&gt;): void

Subscribes to hotspot state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStateChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the hotspot state.|

**Hotspot states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Deactivated|
| 1 | Activated|
| 2 | Activating|
| 3 | Deactivating|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

## wifiManager.off('hotspotStateChange')<sup>9+</sup>

off(type: "hotspotStateChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from hotspot state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the hotspot state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvHotspotStateChangeFunc = (result:number) => {
      console.info("Receive hotspot state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("hotspotStateChange", recvHotspotStateChangeFunc);
  
  // Unregister an event.
  wifiManager.off("hotspotStateChange", recvHotspotStateChangeFunc);
```

## wifiManager.on('hotspotStaJoin')<sup>9+</sup>

on(type: "hotspotStaJoin", callback: Callback&lt;StationInfo&gt;): void

Subscribes to the connection of an STA to a Wi-Fi hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStaJoin**.|
| callback | Callback&lt;StationInfo&gt; | No| Callback invoked immediately after an STA is connected to a Wi-Fi hotspot.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

## wifiManager.off('hotspotStaJoin')<sup>9+</sup>

off(type: "hotspotStaJoin", callback?: Callback&lt;StationInfo&gt;): void

Unsubscribes from the connection of an STA to a Wi-Fi hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStaJoin**.|
| callback | Callback&lt;StationInfo&gt; | No| Callback for the connection of an STA to a Wi-Fi hotspot.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```ts
import wifiManager from '@ohos.wifiManager';

let recvHotspotStaJoinFunc = (result:wifiManager.StationInfo) => {
    console.info("Receive hotspot sta join event: " + result);
}

// Register an event.
wifiManager.on("hotspotStaJoin", recvHotspotStaJoinFunc);

// Unregister an event.
wifiManager.off("hotspotStaJoin", recvHotspotStaJoinFunc);

```

## wifiManager.on('hotspotStaLeave')<sup>9+</sup>

on(type: "hotspotStaLeave", callback: Callback&lt;StationInfo&gt;): void

Subscribes to the disconnection of an STA from a Wi-Fi hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStaLeave**.|
| callback | Callback&lt;StationInf]&gt; | No| Callback invoked immediately after an STA is disconnected from a Wi-Fi hotspot.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

## wifiManager.off('hotspotStaLeave')<sup>7+</sup>

off(type: "hotspotStaLeave", callback?: Callback&lt;StationInfo&gt;): void

Unsubscribes from the disconnection of an STA from a Wi-Fi hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStaLeave**.|
| callback | Callback&lt;StationInf]&gt; | Yes| Callback for the disconnection of an STA from a Wi-Fi hotspot.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```ts
import wifiManager from '@ohos.wifiManager';

let recvHotspotStaLeaveFunc = (result:wifiManager.StationInfo) => {
    console.info("Receive hotspot sta leave event: " + result);
}

// Register an event.
wifiManager.on("hotspotStaLeave", recvHotspotStaLeaveFunc);

// Unregister an event.
wifiManager.off("hotspotStaLeave", recvHotspotStaLeaveFunc);

```

## wifiManager.on('p2pStateChange')<sup>9+</sup>

on(type: "p2pStateChange", callback: Callback&lt;number&gt;): void

Subscribes to P2P state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pStateChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the P2P state change.|

**P2P states**

| **Value**| **Description**|
| -------- | -------- |
| 1 | Available|
| 2 | Opening|
| 3 | Opened|
| 4 | Closing|
| 5 | Closed|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.off('p2pStateChange')<sup>9+</sup>

off(type: "p2pStateChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from P2P state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the P2P state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvP2pStateChangeFunc = (result:number) => {
      console.info("Receive p2p state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pStateChange", recvP2pStateChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pStateChange", recvP2pStateChangeFunc);
```

## wifiManager.on('p2pConnectionChange')<sup>9+</sup>

on(type: "p2pConnectionChange", callback: Callback&lt;WifiP2pLinkedInfo&gt;): void

Subscribes to P2P connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pConnectionChange**.|
| callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | Yes| Callback invoked to return the P2P connection state change.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.off('p2pConnectionChange')<sup>9+</sup>

off(type: "p2pConnectionChange", callback?: Callback&lt;WifiP2pLinkedInfo&gt;): void

Unsubscribes from P2P connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pConnectionChange**.|
| callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | No| Callback for the P2P connection state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvP2pConnectionChangeFunc = (result:wifiManager.WifiP2pLinkedInfo) => {
      console.info("Receive p2p connection change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pConnectionChange", recvP2pConnectionChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pConnectionChange", recvP2pConnectionChangeFunc);
```

## wifiManager.on('p2pDeviceChange')<sup>9+</sup>

on(type: "p2pDeviceChange", callback: Callback&lt;WifiP2pDevice&gt;): void

Subscribes to P2P device state changes.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | Yes| Callback invoked to return the device state change.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.off('p2pDeviceChange')<sup>9+</sup>

off(type: "p2pDeviceChange", callback?: Callback&lt;WifiP2pDevice&gt;): void

Unsubscribes from P2P device state changes.

**Required permissions**:

API version 9: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later: No permission is required.

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | No| Callback for the P2P device state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvP2pDeviceChangeFunc = (result:wifiManager.WifiP2pDevice) => {
      console.info("Receive p2p device change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pDeviceChange", recvP2pDeviceChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pDeviceChange", recvP2pDeviceChangeFunc);
```

## wifiManager.on('p2pPeerDeviceChange')<sup>9+</sup>

on(type: "p2pPeerDeviceChange", callback: Callback&lt;WifiP2pDevice[]&gt;): void

Subscribes to P2P peer device state changes.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later : ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pPeerDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Yes| Callback invoked to return the P2P peer device state change. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.off('p2pPeerDeviceChange')<sup>9+</sup>

off(type: "p2pPeerDeviceChange", callback?: Callback&lt;WifiP2pDevice[]&gt;): void

Unsubscribes from P2P peer device state changes.

**Required permissions**:

API version 9: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

API version 10 and later: No permission is required.

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pPeerDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | No| Callback for the P2P peer device state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvP2pPeerDeviceChangeFunc = (result:wifiManager.WifiP2pDevice[]) => {
      console.info("Receive p2p peer device change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
```

## wifiManager.on('p2pPersistentGroupChange')<sup>9+</sup>

on(type: "p2pPersistentGroupChange", callback: Callback&lt;void&gt;): void

Subscribes to P2P persistent group state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pPersistentGroupChange**.|
| callback | Callback&lt;void&gt; | Yes| Callback invoked to return the P2P persistent group state change.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.off('p2pPersistentGroupChange')<sup>9+</sup>

off(type: "p2pPersistentGroupChange", callback?: Callback&lt;void&gt;): void

Unsubscribes from P2P persistent group state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pPersistentGroupChange**.|
| callback | Callback&lt;void&gt; | No| Callback for the P2P persistent group state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvP2pPersistentGroupChangeFunc = (result:void) => {
      console.info("Receive p2p persistent group change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
```

## wifiManager.on('p2pDiscoveryChange')<sup>9+</sup>

on(type: "p2pDiscoveryChange", callback: Callback&lt;number&gt;): void

Subscribes to P2P device discovery state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pDiscoveryChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the P2P device discovery state change.|

**P2P discovered device states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Initial state.|
| 1 | Discovered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifiManager.off('p2pDiscoveryChange')<sup>9+</sup>

off(type: "p2pDiscoveryChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from P2P device discovery state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **p2pDiscoveryChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the P2P device discovery state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```ts
  import wifiManager from '@ohos.wifiManager';
  
  let recvP2pDiscoveryChangeFunc = (result:number) => {
      console.info("Receive p2p discovery change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
```
