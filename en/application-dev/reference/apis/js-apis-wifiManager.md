# @ohos.wifiManager (WLAN)
The **WLAN** module provides basic wireless local area network (WLAN) functions, peer-to-peer (P2P) functions, and WLAN message notification services. It allows applications to communicate with other devices over WLAN.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import wifiManager from '@ohos.wifiManager';
```

## wifi.enableWifi<sup>9+</sup>

enableWifi(): void

Enables WLAN.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.enableWifi();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.disableWifi<sup>9+</sup>

disableWifi(): void

Disables WLAN.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.disableWifi();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.isWifiActive<sup>9+</sup>

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

```
	import wifi from '@ohos.wifiManager';

	try {
		let isActivate = wifiManager.isActivate();
		console.info("isActivate:" + isActivate);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.scan<sup>9+</sup>

scan(): void

Starts a scan for WLAN.

**Required permissions**: ohos.permission.SET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.scan();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.getScanInfoList<sup>9+</sup>

getScanInfoList(): Array&lt;WifiScanInfo&gt;;

Obtains the scan result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION))

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Array&lt;[WifiScanInfo](#wifiscaninfo)&gt; | Returns the hotspots detected.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```
	import wifi from '@ohos.wifiManager';

	try {
		let scanInfoList = wifiManager.getScanInfoList();
		console.info("scanInfoList:" + JSON.stringify(scanInfoList));
		let len = Object.keys(result).length;
        console.log("wifi received scan info: " + len);
		if(len > 0){
			for (var i = 0; i < len; ++i) {
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

## wifi.addDeviceConfig<sup>9+</sup>

addDeviceConfig(config: WifiDeviceConfig): Promise&lt;number&gt;

Adds network configuration. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add.|

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

```
	import wifi from '@ohos.wifiManager';

	try {
		let config = {
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
| preSharedKey | string | Yes| No| PSK of the hotspot.|
| isHiddenSsid | boolean | Yes| No| Whether the network is hidden.|
| securityType | [WifiSecurityType](#wifisecuritytype) | Yes| No| Security type.|
| creatorUid | number | Yes| No| ID of the creator.<br>**System API**: This is a system API.|
| disableReason | number | Yes| No| Reason for disabling WLAN.<br>**System API**: This is a system API.|
| netId | number | Yes| No| Network ID.<br>**System API**: This is a system API.|
| randomMacType | number | Yes| No| Random MAC type.<br>**System API**: This is a system API.|
| randomMacAddr | string | Yes| No| Random MAC address.<br>**System API**: This is a system API.|
| ipType | [IpType](#iptype9) | Yes| No| IP address type.<br>**System API**: This is a system API.|
| staticIp | [IpConfig](#ipconfig9) | Yes| No| Static IP address configuration.<br>**System API**: This is a system API.|
| eapConfig<sup>9+</sup> | [WifiEapConfig](#wifieapconfig9) | Yes| No| EAP configuration.<br>**System API**: This is a system API.|


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


## WifiEapConfig<sup>9+</sup>

Represents EAP configuration information.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| eapMethod | [EapMethod](#eapmethod9) | Yes| No| EAP authentication method.|
| phase2Method | [Phase2Method](#phase2method9) | Yes| No| Phase 2 authentication method.|
| identity | string | Yes| No| Identity Information.|
| anonymousIdentity | string | Yes| No| Anonymous identity.|
| password | string | Yes| No| Password.|
| caCertAliases | string | Yes| No| CA certificate alias.|
| caPath | string | Yes| No| CA certificate path.|
| clientCertAliases | string | Yes| No| Client certificate alias.|
| certEntry | Uint8Array | Yes| Yes| CA certificate content.|
| certPassword | string | Yes| Yes| CA certificate password.|
| altSubjectMatch | string | Yes| No| A string to match the alternate subject.|
| domainSuffixMatch | string | Yes| No| A string to match the domain suffix.|
| realm | string | Yes| No| Realm for the passpoint credential.|
| plmn | string | Yes| No| Public land mobile network (PLMN) of the passpoint credential provider.|
| eapSubId | number | Yes| No| Sub-ID of the SIM card.|


## EapMethod<sup>9+</sup>

Enumerates the EAP authentication methods.

**System API**: This is a system API.

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


## Phase2Method<sup>9+</sup>

Enumerates the Phase 2 authentication methods.

**System API**: This is a system API.

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


## wifi.addDeviceConfig<sup>9+</sup>

addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void

Adds network configuration. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the network configuration ID. If **data** is **-1**, the operation has failed. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**

```
	import wifi from '@ohos.wifiManager';

	try {
		let config = {
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

## wifi.addCandidateConfig<sup>9+</sup>

addCandidateConfig(config: WifiDeviceConfig): Promise&lt;number&gt;

Adds the configuration of a candidate network. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add.|

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
`````
	import wifi from '@ohos.wifiManager';

	try {
		let config = {
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

## wifi.addCandidateConfig<sup>9+</sup>

addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void

Adds the configuration of a candidate network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the network configuration ID. If **data** is **-1**, the operation has failed. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
`````
	import wifi from '@ohos.wifiManager';

	try {
		let config = {
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

## wifi.removeCandidateConfig<sup>9+</sup>

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

```
	import wifi from '@ohos.wifiManager';

	try {
		let networkId = 0;
		wifiManager.removeCandidateConfig(networkId).then(result => {
			console.info("result:" + JSON.stringify(result));
		});	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.removeCandidateConfig<sup>9+</sup>

removeCandidateConfig(networkId: number, callback: AsyncCallback&lt;void&gt;): void

Removes the configuration of a candidate network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| networkId | number | Yes| ID of the network configuration to remove.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result. If the operation is successful, the value of **err** is **0**. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		let networkId = 0;
		wifiManager.removeCandidateConfig(networkId,(error,result) => {
		console.info("result:" + JSON.stringify(result));
		});	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.getCandidateConfigs<sup>9+</sup>

getCandidateConfigs(): &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig)&gt;

Obtains candidate network configuration.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

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

`````
	import wifi from '@ohos.wifiManager';

	try {
		let configs = wifiManager.getCandidateConfigs();
		console.info("configs:" + JSON.stringify(configs));
		let len = Object.keys(configs).length;
        console.log("result len: " + len);
		if(len > 0){
			for (var i = 0; i < len; ++i) {
				console.info("ssid: " + configs[i].ssid);
				console.info("bssid: " + configs[i].bssid);
			}
		}	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
	
`````

## wifi.connectToCandidateConfig<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let networkId = 0;
		let ret = wifiManager.connectToCandidateConfig(networkId);
		console.info("result:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
	
```

## wifi.connectToNetwork<sup>9+</sup>

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

```
	import wifi from '@ohos.wifiManager';

	try {
		let networkId = 0;
		wifiManager.connectToNetwork(networkId);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}	
```

## wifi.connectToDevice<sup>9+</sup>

connectToDevice(config: WifiDeviceConfig): void

Connects to the specified network. If the device is already connected to a hotspot, use **disconnect()** to disconnect it from the hotspot first.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO, ohos.permission.SET_WIFI_CONFIG, and ohos.permissio.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**:
  SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| Configuration of the WLAN to connect. |

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		let config = {
			ssid : "****",
			preSharedKey : "****",
			securityType : 3
		}
		wifiManager.connectToDevice(config);
				
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.disconnect<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.disconnect();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.getSignalLevel<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let rssi = 0;
		let band = 0;
		let level = wifiManager.getSignalLevel(rssi,band);
		console.info("lelvel:" + JSON.stringify(lelvel));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifi.getLinkedInfo<sup>9+</sup>

getLinkedInfo(): Promise&lt;WifiLinkedInfo&gt;

Obtains WLAN connection information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

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

## wifi.getLinkedInfo<sup>9+</sup>

getLinkedInfo(callback: AsyncCallback&lt;WifiLinkedInfo&gt;): void

Obtains WLAN connection information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

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
  ```js
  import wifi from '@ohos.wifiManager';
  
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
| macType | number | Yes| No| MAC address type.|
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

## SuppState<sup>10+</sup>

Enumerates the Wi-Fi standards.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| WIFI_STANDARD_UNDEFINED | 0 | Undefined|
| WIFI_STANDARD_11A | 1 | 802.11a|
| WIFI_STANDARD_11B | 2 | 802.11b|
| WIFI_STANDARD_11G | 3 | 802.11g|
| WIFI_STANDARD_11N | 4 | 802.11n|
| WIFI_STANDARD_11AC | 5 | 802.11ac|
| WIFI_STANDARD_11AX | 6 | 802.11ax|
| WIFI_STANDARD_11AD | 7 | 802.11ad|


## wifi.isConnected<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let ret = wifiManager.isConnected();
		console.info("isConnected:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifi.getSupportedFeatures<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let ret = wifiManager.getSupportedFeatures();
		console.info("supportedFeatures:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifi.isFeatureSupported<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let featureId = 0;
		let ret = wifiManager.isFeatureSupported(featureId);
		console.info("isFeatureSupported:" + ret);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifi.getDeviceMacAddress<sup>9+</sup>

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

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		let ret = wifiManager.getDeviceMacAddress();
		console.info("deviceMacAddress:" + JSON.stringify(ret));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifi.getIpInfo<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

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


## wifi.getCountryCode<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let code = wifiManager.getCountryCode();
		console.info("code:" + code);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.reassociate<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.reassociate();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.reconnect<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.reconnect();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.getDeviceConfigs<sup>9+</sup>

getDeviceConfigs(): &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig)&gt;

Obtains network configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, ohos.permission.APPROXIMATELY_LOCATION, and ohos.permission.GET_WIFI_CONFIG

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let configs = wifiManager.getDeviceConfigs();
		console.info("configs:" + JSON.stringify(configs));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.updateDeviceConfig<sup>9+</sup>

updateDeviceConfig(config: WifiDeviceConfig): number

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let config = {
			ssid : "****",
			preSharedKey : "****",
			securityType : 3
		}
		let ret = wifiManager.updateDeviceConfig(config);
		console.error("ret:" + ret);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.disableDeviceConfig<sup>9+</sup>

disableDeviceConfig(networkId: number): void

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let netId = 0;
		wifiManager.disableDeviceConfig(netId);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.removeAllDeviceConfigs<sup>9+</sup>

removeAllDeviceConfigs(): void

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
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.removeAllDeviceConfigs();		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.removeDeviceConfig<sup>9+</sup>

removeDeviceConfig(networkId: number): void

Removes the specified network configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| networkId | number | Yes| ID of the network configuration to remove.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		let id = 0;
		wifiManager.removeDeviceConfig(id);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.isBandTypeSupported<sup>10+</sup>

isBandTypeSupported(bandType: WifiBandType): boolean

Checks whether the current frequency band is supported.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| bandType | WifiBandType | Yes| Wi-Fi band type.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		let type = 0;
		boolean isBandTypeSupported = wifiManager.isBandTypeSupported(type);
		console.info("isBandTypeSupported:" + isBandTypeSupported);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## WifiBandType <sup>10+</sup>

Enumerates the Wi-Fi band types.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| WIFI_BAND_NONE | 0 | Undefined|
| WIFI_BAND_2G | 1 | 2 GHz|
| WIFI_BAND_5G | 2 | 5 GHz|
| WIFI_BAND_6G | 3 | 6 GHz|
| WIFI_BAND_60G | 4 | 60 GHz|


## wifi.get5GChannelList<sup>10+</sup>

get5GChannelList(): Array&lt;number&gt;

Obtains the list of 5 GHz channels supported by this device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		let channelList = wifiManager.get5GChannelList();
		console.info("channelList:" + JSON.stringify(channelList));		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.enableHotspot<sup>9+</sup>

enableHotspot(): void

Enables this hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.enableHotspot();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.disableHotspot<sup>9+</sup>

disableHotspot(): void

Disables this hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.disableHotspot();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.isHotspotDualBandSupported<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let ret = wifiManager.isHotspotDualBandSupported();
		console.info("result:" + ret);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.isHotspotActive<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let ret = wifiManager.isHotspotActive();
		console.info("result:" + ret);		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.setHotspotConfig<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let config = {
			ssid: "****",
			securityType: 3,
			band: 0,
			channel: 0,
			preSharedKey: "****",
			maxConn: 0
		}
		let ret = wifiManager.setHotspotConfig();
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

## wifi.getHotspotConfig<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let config = wifiManager.getHotspotConfig();
		console.info("result:" + JSON.stringify(config));		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.getHotspotStations<sup>9+</sup>

getHotspotStations(): &nbsp;Array&lt;[StationInfo](#stationinfo9)&gt;

Obtains information about the connected stations.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, ohos.permission.APPROXIMATELY_LOCATION, and ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| &nbsp;Array&lt;[StationInfo](#stationinfo9)&gt; | Connected stations obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		let stations = wifiManager.getHotspotStations();
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
| ipAddress | string | Yes| No| IP address.|


## wifi.getP2pLinkedInfo<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	wifi.getP2pLinkedInfo((err, data) => {
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


## wifi.getP2pLinkedInfo<sup>9+</sup>

getP2pLinkedInfo(callback: AsyncCallback&lt;WifiP2pLinkedInfo&gt;): void

Obtains P2P link information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the P2P link information. If **err** is not **0**, an error has occurred.|


## wifi.getCurrentP2pGroup<sup>9+</sup>

getCurrentP2pGroup(): Promise&lt;WifiP2pGroupInfo&gt;

Obtains the current P2P group information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt; | Promise used to return the P2P group information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifi.getCurrentP2pGroup<sup>9+</sup>

getCurrentP2pGroup(callback: AsyncCallback&lt;WifiP2pGroupInfo&gt;): void

Obtains the current P2P group information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the group information obtained. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	wifi.getCurrentP2pGroup((err, data) => {
    if (err) {
        console.error("get current P2P group error");
        return;
    }
		console.info("get current P2P group: " + JSON.stringify(data));
	});

	wifi.getCurrentP2pGroup().then(data => {
		console.info("get current P2P group: " + JSON.stringify(data));
	});
```

## wifi.getP2pPeerDevices<sup>9+</sup>

getP2pPeerDevices(): Promise&lt;WifiP2pDevice[]&gt;

Obtains the peer device list in the P2P connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Promise used to return the peer device list.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifi.getP2pPeerDevices<sup>9+</sup>

getP2pPeerDevices(callback: AsyncCallback&lt;WifiP2pDevice[]&gt;): void

Obtains the peer device list in the P2P connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the peer device list obtained. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	wifi.getP2pPeerDevices((err, data) => {
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

## WifiP2pDevice<sup>9+</sup>

Represents the P2P device information.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceName | string | Yes| No| Device name.|
| deviceAddress | string | Yes| No| MAC address of the device.|
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


## wifi.getP2pLocalDevice<sup>9+</sup>

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

## wifi.getP2pLocalDevice<sup>9+</sup>

getP2pLocalDevice(callback: AsyncCallback&lt;WifiP2pDevice&gt;): void

Obtains the local device information in the P2P connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the local device information obtained. If **err** is not **0**, an error has occurred.|

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	wifiManager.getP2pLocalDevice((err, data) => {
    if (err) {
        console.error("get P2P local device error");
        return;
    }
		console.info("get P2P local device: " + JSON.stringify(data));
	});

	wifi.getP2pLocalDevice().then(data => {
		console.info("get P2P local device: " + JSON.stringify(data));
	});
```

## wifi.createP2pGroup<sup>9+</sup>

createP2pGroup(config: WifiP2PConfig): void

Creates a P2P group.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| Mandatory| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiP2PConfig](#wifip2pconfig9) | Yes| Group configuration.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		let config = {
			deviceAddress: "****",
			netId: 0,
			passphrase: "*****",
			groupName: "****",
			goBand: 0
		}
		wifiManager.createP2pGroup(config);	
		
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


## wifi.removeP2pGroup<sup>9+</sup>

removeP2pGroup(): void

Removes this P2P group.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.removeP2pGroup();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.p2pConnect<sup>9+</sup>

p2pConnect(config: WifiP2PConfig): void

Sets up a P2P connection.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| Mandatory| **Description**|
| -------- | -------- | -------- | -------- |
| config | [WifiP2PConfig](#wifip2pconfig9) | Yes| P2P group configuration.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
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
  console.info("start discover devices -> " + wifi.startP2pDiscoverDevices());
  ```

## wifi.p2pCancelConnect<sup>9+</sup>

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
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.p2pCancelConnect();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.startDiscoverP2pDevices<sup>9+</sup>

startDiscoverP2pDevices(): void

Starts to discover devices.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.startDiscoverP2pDevices();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.stopDiscoverP2pDevices<sup>9+</sup>

stopDiscoverP2pDevices(): void

Stops discovering devices.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	try {
		wifiManager.stopDiscoverP2pDevices();	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.deletePersistentP2pGroup<sup>9+</sup>

deletePersistentP2pGroup(netId: number): void

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let netId = 0;
		wifiManager.deletePersistentP2pGroup(netId);	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.getP2pGroups<sup>9+</sup>

getP2pGroups(): Promise&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;

Obtains information about all P2P groups. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt;&nbsp;&gt; | Promise used to return the group information obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
```
	import wifi from '@ohos.wifiManager';

	wifiManager.getP2pGroups((err, data) => {
    if (err) {
        console.error("get P2P groups error");
        return;
    }
		console.info("get P2P groups: " + JSON.stringify(data));
	});

	wifi.getP2pGroups().then(data => {
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


## wifi.getP2pGroups<sup>9+</sup>

getP2pGroups(callback: AsyncCallback&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;): void

Obtains information about all P2P groups. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo9)&gt;&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the group information obtained. If **err** is not **0**, an error has occurred.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifi.setP2pDeviceName<sup>9+</sup>

setP2pDeviceName(devName: string): void

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
```
	import wifi from '@ohos.wifiManager';

	try {
		let name = "****";
		wifiManager.setP2pDeviceName(netId);	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifi.on('wifiStateChange')<sup>9+</sup>

on(type: "wifiStateChange", callback: Callback&lt;number&gt;): void

Registers the WLAN state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **wifiStateChange**.|
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


## wifi.off('wifiStateChange')<sup>9+</sup>

off(type: "wifiStateChange", callback?: Callback&lt;number&gt;): void

Unregisters the WLAN state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **wifiStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the WLAN state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifi';
  
  var recvPowerNotifyFunc = result => {
      console.info("Receive power state change event: " + result);
  }
  
  // Register an event.
  wifi.on("wifiStateChange", recvPowerNotifyFunc);
  
  // Unregister an event.
  wifi.off("wifiStateChange", recvPowerNotifyFunc);
  ```


## wifi.on('wifiConnectionChange')<sup>9+</sup>

on(type: "wifiConnectionChange", callback: Callback&lt;number&gt;): void

Registers the WLAN connection state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **wifiConnectionChange**.|
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

## wifi.off('wifiConnectionChange')<sup>9+</sup>

off(type: "wifiConnectionChange", callback?: Callback&lt;number&gt;): void

Unregisters the WLAN connection state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **wifiConnectionChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the WLAN connection state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifi';
  
  var recvWifiConnectionChangeFunc = result => {
      console.info("Receive wifi connection change event: " + result);
  }
  
  // Register an event.
  wifi.on("wifiConnectionChange", recvWifiConnectionChangeFunc);
  
  // Unregister an event.
  wifi.off("wifiConnectionChange", recvWifiConnectionChangeFunc);
  ```

## wifi.on('wifiScanStateChange')<sup>9+</sup>

on(type: "wifiScanStateChange", callback: Callback&lt;number&gt;): void

Registers the WLAN scan state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **wifiScanStateChange**.|
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

## wifi.off('wifiScanStateChange')<sup>9+</sup>

off(type: "wifiScanStateChange", callback?: Callback&lt;number&gt;): void

Unregisters the WLAN scan state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **wifiScanStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the WLAN scan state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifi';
  
  var recvWifiScanStateChangeFunc = result => {
      console.info("Receive Wifi scan state change event: " + result);
  }
  
  // Register an event.
  wifi.on("wifiScanStateChange", recvWifiScanStateChangeFunc);
  
  // Unregister an event.
  wifi.off("wifiScanStateChange", recvWifiScanStateChangeFunc);
  ```

## wifi.on('wifiRssiChange')<sup>9+</sup>

on(type: "wifiRssiChange", callback: Callback&lt;number&gt;): void

Registers the RSSI change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **wifiRssiChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the RSSI, in dBm.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

## wifi.off('wifiRssiChange')<sup>9+</sup>

off(type: "wifiRssiChange", callback?: Callback&lt;number&gt;): void

Unregisters the RSSI change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **wifiRssiChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the RSSI change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2501000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifiManager';
  
  var recvWifiRssiChangeFunc = result => {
      console.info("Receive wifi rssi change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("wifiRssiChange", recvWifiRssiChangeFunc);
  
  // Unregister an event.
  wifiManager.off("wifiRssiChange", recvWifiRssiChangeFunc);
  ```

## wifi.on('hotspotStateChange')<sup>9+</sup>

on(type: "hotspotStateChange", callback: Callback&lt;number&gt;): void

Registers the hotspot state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **hotspotStateChange**.|
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

## wifi.off('hotspotStateChange')<sup>9+</sup>

off(type: "hotspotStateChange", callback?: Callback&lt;number&gt;): void

Unregisters the hotspot state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **hotspotStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the hotspot state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2601000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifiManager';
  
  var recvHotspotStateChangeFunc = result => {
      console.info("Receive hotspot state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("hotspotStateChange", recvHotspotStateChangeFunc);
  
  // Unregister an event.
  wifiManager.off("hotspotStateChange", recvHotspotStateChangeFunc);
  ```

## wifi.on('p2pStateChange')<sup>9+</sup>

on(type: "p2pStateChange", callback: Callback&lt;number&gt;): void

Registers the P2P state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pStateChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the P2P state.|

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

## wifi.off('p2pStateChange')<sup>9+</sup>

off(type: "p2pStateChange", callback?: Callback&lt;number&gt;): void

Unregisters the P2P state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the P2P state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifiManager';
  
  var recvP2pStateChangeFunc = result => {
      console.info("Receive p2p state change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pStateChange", recvP2pStateChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pStateChange", recvP2pStateChangeFunc);
  ```

  ## wifi.on('p2pConnectionChange')<sup>9+</sup>

on(type: "p2pConnectionChange", callback: Callback&lt;WifiP2pLinkedInfo&gt;): void

Registers the P2P connection state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pConnectionChange**.|
| callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | Yes| Callback invoked to return the P2P connection state.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifi.off('p2pConnectionChange')<sup>9+</sup>

off(type: "p2pConnectionChange", callback?: Callback&lt;WifiP2pLinkedInfo&gt;): void

Unregisters the P2P connection state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pConnectionChange**.|
| callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo9)&gt; | No| Callback for the P2P connection state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifiManager';
  
  var recvP2pConnectionChangeFunc = result => {
      console.info("Receive p2p connection change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pConnectionChange", recvP2pConnectionChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pConnectionChange", recvP2pConnectionChangeFunc);
  ```

## wifi.on('p2pDeviceChange')<sup>9+</sup>

on(type: "p2pDeviceChange", callback: Callback&lt;WifiP2pDevice&gt;): void

Registers the P2P device state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | Yes| Callback invoked to return the P2P device state.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifi.off('p2pDeviceChange')<sup>9+</sup>

off(type: "p2pDeviceChange", callback?: Callback&lt;WifiP2pDevice&gt;): void

Unregisters the P2P device state change events.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice9)&gt; | No| Callback for the P2P device state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifiManager';
  
  var recvP2pDeviceChangeFunc = result => {
      console.info("Receive recv p2p device change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pDeviceChange", recvP2pDeviceChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pDeviceChange", recvP2pDeviceChangeFunc);
  ```

## wifi.on('p2pPeerDeviceChange')<sup>9+</sup>

on(type: "p2pPeerDeviceChange", callback: Callback&lt;WifiP2pDevice[]&gt;): void

Registers the P2P peer device state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pPeerDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | Yes| Callback invoked to return the P2P peer device state.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifi.off('p2pPeerDeviceChange')<sup>9+</sup>

off(type: "p2pPeerDeviceChange", callback?: Callback&lt;WifiP2pDevice[]&gt;): void

Unregisters the P2P peer device state change events.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pPeerDeviceChange**.|
| callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice9)&gt; | No| Callback for the P2P peer device state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifiManager';
  
  var recvP2pPeerDeviceChangeFunc = result => {
      console.info("Receive recv p2p peer device change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
  ```

## wifi.on('p2pPersistentGroupChange')<sup>9+</sup>

on(type: "p2pPersistentGroupChange", callback: Callback&lt;void&gt;): void

Registers the P2P persistent group state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pPersistentGroupChange**.|
| callback | Callback&lt;void&gt; | Yes| Callback invoked to return the P2P persistent group state.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

## wifi.off('p2pPersistentGroupChange')<sup>9+</sup>

off(type: "p2pPersistentGroupChange", callback?: Callback&lt;void&gt;): void

Unregisters the P2P persistent group state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pPersistentGroupChange**.|
| callback | Callback&lt;void&gt; | No| Callback for the P2P persistent group state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifiManager';
  
  var recvP2pPersistentGroupChangeFunc = result => {
      console.info("Receive recv p2p persistent group change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);
  ```

## wifi.on('p2pDiscoveryChange')<sup>9+</sup>

on(type: "p2pDiscoveryChange", callback: Callback&lt;number&gt;): void

Registers the P2P device discovery state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pDiscoveryChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the P2P device discovery state.|

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

## wifi.off('p2pDiscoveryChange')<sup>9+</sup>

off(type: "p2pDiscoveryChange", callback?: Callback&lt;number&gt;): void

Unregisters the P2P device discovery state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **p2pDiscoveryChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the P2P device discovery state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](../errorcodes/errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 2801000  | Operation failed.|

**Example**
  ```js
  import wifi from '@ohos.wifiManager';
  
  var recvP2pDiscoveryChangeFunc = result => {
      console.info("Receive recv p2p discovery change event: " + result);
  }
  
  // Register an event.
  wifiManager.on("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
  
  // Unregister an event.
  wifiManager.off("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
  ```
