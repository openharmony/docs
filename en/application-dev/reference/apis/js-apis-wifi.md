# @ohos.wifi (WLAN)

The **WLAN** module provides basic wireless local area network (WLAN) functions, peer-to-peer (P2P) functions, and WLAN message notification services. It allows applications to communicate with other devices over WLAN.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import wifi from '@ohos.wifi';
```

## wifi.enableWifi

enableWifi(): boolean

Enables WLAN.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

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

Disables WLAN.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```ts
import wifi from '@ohos.wifi';

try {
	wifi.disableWifi();
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}

```

## wifi.isWifiActive

isWifiActive(): boolean

Checks whether WLAN is enabled.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if WLAN is enabled; returns **false** otherwise.|

**Example**

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

Starts a scan for WLAN.

**Required permissions**: **ohos.permission.SET_WIFI_INFO** and **ohos.permission.LOCATION**

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

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

Obtains the scan result. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_PEERS_MAC (or ohos.permission.LOCATION)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
| Promise&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&nbsp;&gt; | Promise used to return the detected hotspots.|


## wifi.getScanInfos

getScanInfos(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void

Obtains the scan result. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_PEERS_MAC (or ohos.permission.LOCATION)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the detected hotspots. Otherwise, **err** is a non-zero value and **data** is empty.|

**Example**

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
| timestamp | number | Yes| No| Timestamp.|


## WifiSecurityType

Enumerates the WLAN security types.

**System capability**: SystemCapability.Communication.WiFi.Core


| **Name**| **Value**| **Description**|
| -------- | -------- | -------- |
| WIFI_SEC_TYPE_INVALID | 0 | Invalid security type.|
| WIFI_SEC_TYPE_OPEN | 1 | Open security type.|
| WIFI_SEC_TYPE_WEP | 2 | Wired Equivalent Privacy (WEP).|
| WIFI_SEC_TYPE_PSK | 3 | Pre-shared key (PSK).|
| WIFI_SEC_TYPE_SAE | 4 | Simultaneous Authentication of Equals (SAE).|


## wifi.addDeviceConfig

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
| Promise&lt;number&gt; | Promise used to return the WLAN configuration ID. If **-1** is returned, the network configuration fails to be added.|

  **Example**

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
| ipType | [IpType](#iptype7) | Yes| No| IP address type.<br>**System API**: This is a system API.|
| staticIp | [IpConfig](#ipconfig7) | Yes| No| Static IP address configuration.<br>**System API**: This is a system API.|


## IpType<sup>7+</sup>

Enumerates the IP address types.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA


| Name| Value| Description|
| -------- | -------- | -------- |
| STATIC | 0 | Static IP address.|
| DHCP | 1 | IP address allocated by DHCP.|
| UNKNOWN | 2 | Not specified.|


## IpConfig<sup>7+</sup>

Represents IP configuration information.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ipAddress | number | Yes| No| IP address.|
| gateway | number | Yes| No| Gateway.|
| dnsServers | number[] | Yes| No| Domain name server (DNS) information.|
| domains | Array&lt;string&gt; | Yes| No| Domain information.|


## wifi.addDeviceConfig

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

**Example**

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
## wifi.addUntrustedConfig<sup>7+</sup>

addUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt;

Adds the configuration of an untrusted network. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the operation is successful, **true** is returned; otherwise, **false** is returned.|

**Example**
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

Adds the configuration of an untrusted network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is **true**. If the operation fails, **data** is **false**. If **err** is not **0**, an error has occurred.|

**Example**
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

Removes the configuration of an untrusted network. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to remove.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the operation is successful, **true** is returned; otherwise, **false** is returned.|

**Example**

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

Removes the configuration of an untrusted network. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to remove.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is **true**. If the operation fails, **data** is **false**. If **err** is not **0**, an error has occurred.|

**Example**
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

## wifi.connectToNetwork

connectToNetwork(networkId: number): boolean

Connects to the specified network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | networkId | number | Yes| Network configuration ID.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

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

Connects to the specified network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO, ohos.permission.SET_WIFI_CONFIG, and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**:
  SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
| config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Disconnects the network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**:
  SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.disconnect();
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.getSignalLevel

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

**Example**
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

Obtains WLAN connection information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiLinkedInfo](#wifilinkedinfo)&gt; | Promise used to return the WLAN connection information.|


## wifi.getLinkedInfo

getLinkedInfo(callback: AsyncCallback&lt;WifiLinkedInfo&gt;): void

Obtains WLAN connection information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiLinkedInfo](#wifilinkedinfo)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the WLAN connection information obtained. If **err** is not **0**, an error has occurred.|

**Example**
```ts
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
}).catch((error:number) => {
    console.info("get linked info error");
});
```


## WifiLinkedInfo

Represents the WLAN connection information.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| SSID of the hotspot, in UTF-8 format.|
| bssid | string | Yes| No| BSSID of the hotspot.|
| networkId | number | Yes| No| Network configuration ID.<br>**System API**: This is a system API.|
| rssi | number | Yes| No| RSSI of the hotspot, in dBm.|
| band | number | Yes| No| Frequency band of the WLAN AP.|
| linkSpeed | number | Yes| No| Speed of the WLAN AP.|
| frequency | number | Yes| No| Frequency of the WLAN AP.|
| isHidden | boolean | Yes| No| Whether to hide the WLAN AP.|
| isRestricted | boolean | Yes| No| Whether to restrict data volume at the WLAN AP.|
| chload | number | Yes| No| Channel load. A larger value indicates a higher load.<br>**System API**: This is a system API.|
| snr | number | Yes| No| Signal-to-noise ratio (SNR).<br>**System API**: This is a system API.|
| macAddress | string | Yes| No| MAC address of the device.|
| ipAddress | number | Yes| No| IP address of the device that sets up the WLAN connection.|
| suppState | [SuppState](#suppstate) | Yes| No| Supplicant state.<br>**System API**: This is a system API.|
| connState | [ConnState](#connstate) | Yes| No| WLAN connection state.|


## ConnState

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


## SuppState

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


## wifi.isConnected<sup>7+</sup>

isConnected(): boolean

Checks whether the WLAN is connected.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the WLAN is connected; returns **false** otherwise.|


## wifi.getSupportedFeatures<sup>7+</sup>

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
| 0x0040 | Wi-Fi AWare|
| 0x8000 | WLAN AP/STA concurrency|
| 0x8000000 | WPA3 Personal (WPA-3 SAE)|
| 0x10000000 | WPA3-Enterprise Suite B |
| 0x20000000 | Enhanced open feature|


## wifi.isFeatureSupported<sup>7+</sup>

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

**Example**
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

## wifi.getDeviceMacAddress<sup>7+</sup>

getDeviceMacAddress(): string[]

Obtains the device MAC address.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_LOCAL_MAC and ohos.permission.GET_WIFI_INFO (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | string[] | MAC address obtained.|

**Example**
```ts
import wifi from '@ohos.wifi';

try {
	let ret = wifi.getDeviceMacAddress();
	console.info("deviceMacAddress:" + JSON.stringify(ret));
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}

```

## wifi.getIpInfo<sup>7+</sup>

getIpInfo(): IpInfo

Obtains IP information.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | [IpInfo](#ipinfo7) | IP information obtained.|

**Example**
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


## wifi.getCountryCode<sup>7+</sup>

getCountryCode(): string

Obtains the country code.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.Core

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | string | Country code obtained.|

**Example**
```ts
import wifi from '@ohos.wifi';

try {
	let code = wifi.getCountryCode();
	console.info("code:" + code);
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.reassociate<sup>7+</sup>

reassociate(): boolean

Re-associates with the network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Reconnects to the network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Obtains network configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig)&gt; | Array of network configuration obtained.|

**Example**
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

**Example**
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

Disables network configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | netId | number | Yes| ID of the network configuration to disable.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Removes the configuration of all networks.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Removes the specified network configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
| id | number | Yes| ID of the network configuration to remove.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Enables this hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Disables this hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Checks whether the hotspot supports dual band.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the feature is supported; returns **false** otherwise.|

**Example**
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

Checks whether this hotspot is active.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
| boolean | Returns **true** if the hotspot is active; returns **false** otherwise.|

**Example**
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

Sets hotspot configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [HotspotConfig](#hotspotconfig7) | Yes| Hotspot configuration to set.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Represents the hotspot configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| SSID of the hotspot, in UTF-8 format.|
| securityType | [WifiSecurityType](#wifisecuritytype) | Yes| No| Security type.|
| band | number | Yes| No| Hotspot band. The value **1** stands for 2.4 GHz, the value **2** for 5 GHz, and the value **3** for dual band.|
| preSharedKey | string | Yes| No| PSK of the hotspot.|
| maxConn | number | Yes| No| Maximum number of connections allowed.|


## wifi.getHotspotConfig<sup>7+</sup>

getHotspotConfig(): HotspotConfig

obtains hotspot configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | [HotspotConfig](#hotspotconfig7) | Hotspot configuration obtained.|

**Example**
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

Obtains information about the connected stations.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, and ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | &nbsp;Array&lt;[StationInfo](#stationinfo7)&gt; | Connected stations obtained.|

**Example**
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

Represents the station information.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| name | string | Yes| No| Device name.|
| macAddress | string | Yes| No| MAC address.|
| ipAddress | string | Yes| No| IP address.|


## wifi.getP2pLinkedInfo<sup>8+</sup>

getP2pLinkedInfo(): Promise&lt;WifiP2pLinkedInfo&gt;

Obtains P2P link information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
| Promise&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | Promise used to return the P2P link information obtained.|



## WifiP2pLinkedInfo<sup>8+</sup>

Represents the P2P link information.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| connectState | [P2pConnectState](#p2pconnectstate8) | Yes| No| P2P connection state.|
| isGroupOwner | boolean | Yes| No| Whether the device is the group owner.|
| groupOwnerAddr | string | Yes| No| MAC address of the group.


## P2pConnectState<sup>8+</sup>

Enumerates the P2P connection states.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Value| Description|
| -------- | -------- | -------- |
| DISCONNECTED | 0 | Disconnected.|
| CONNECTED | 1 | Connected.|


## wifi.getP2pLinkedInfo<sup>8+</sup>

getP2pLinkedInfo(callback: AsyncCallback&lt;WifiP2pLinkedInfo&gt;): void

Obtains P2P link information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the P2P link information. If **err** is not **0**, an error has occurred.|

**Example**
```ts
import wifi from '@ohos.wifi';

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

## wifi.getCurrentGroup<sup>8+</sup>

getCurrentGroup(): Promise&lt;WifiP2pGroupInfo&gt;

Obtains the current P2P group information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo8)&gt; | Promise used to return the P2P group information obtained.|


## wifi.getCurrentGroup<sup>8+</sup>

getCurrentGroup(callback: AsyncCallback&lt;WifiP2pGroupInfo&gt;): void

Obtains the current P2P group information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo8)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the group information obtained. If **err** is not **0**, an error has occurred.|

**Example**
```ts
import wifi from '@ohos.wifi';

wifi.getCurrentGroup((err, data) => {
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

Obtains the peer device list in the P2P connection. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | Promise used to return the peer device list.|


## wifi.getP2pPeerDevices<sup>8+</sup>

getP2pPeerDevices(callback: AsyncCallback&lt;WifiP2pDevice[]&gt;): void

Obtains the peer device list in the P2P connection. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **0** and **data** is the peer device list obtained. If **err** is not **0**, an error has occurred.|

**Example**
```ts
import wifi from '@ohos.wifi';

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

## WifiP2pDevice<sup>8+</sup>

Represents the P2P device information.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceName | string | Yes| No| Device name.|
| deviceAddress | string | Yes| No| MAC address of the device.|
| primaryDeviceType | string | Yes| No| Type of the primary device.|
| deviceStatus | [P2pDeviceStatus](#p2pdevicestatus8) | Yes| No| Device status.|
| groupCapabilitys | number | Yes| No| Group capabilities.|


## P2pDeviceStatus<sup>8+</sup>

Enumerates the P2P device states.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Value| Description|
| -------- | -------- | -------- |
| CONNECTED | 0 | Connected.|
| INVITED | 1 | Invited.|
| FAILED | 2 | Failed.|
| AVAILABLE | 3 | Available.|
| UNAVAILABLE | 4 | Unavailable.|


## wifi.createGroup<sup>8+</sup>

createGroup(config: WifiP2PConfig): boolean

Creates a P2P group.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| Mandatory| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiP2PConfig](#wifip2pconfig8) | Yes| Group configuration.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Represents P2P group configuration.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceAddress | string | Yes| No| Device address.|
| netId | number | Yes| No| Network ID. The value **-1** indicates a temporary group, and **-2** indicates a persistent group.|
| passphrase | string | Yes| No| Passphrase of the group.|
| groupName | string | Yes| No| Name of the group.|
| goBand | [GroupOwnerBand](#groupownerband8) | Yes| No| Frequency band of the group.|


## GroupOwnerBand<sup>8+</sup>

Enumerates the P2P group frequency bands.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Value| Description|
| -------- | -------- | -------- |
| GO_BAND_AUTO | 0 | Auto.|
| GO_BAND_2GHZ | 1 | 2 GHz.|
| GO_BAND_5GHZ | 2 | 5 GHz.|


## wifi.removeGroup<sup>8+</sup>

removeGroup(): boolean

Removes this P2P group.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Sets up a P2P connection.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**


  | **Name**| **Type**| Mandatory| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiP2PConfig](#wifip2pconfig8) | Yes| P2P group configuration.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


**Example**
```ts
import wifi from '@ohos.wifi';

let recvP2pConnectionChangeFunc = (result:wifi.WifiP2pLinkedInfo) => {
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

let recvP2pDeviceChangeFunc = (result:wifi.WifiP2pDevice) => {
    console.info("p2p device change receive event: " + JSON.stringify(result));
}
wifi.on("p2pDeviceChange", recvP2pDeviceChangeFunc);

let recvP2pPeerDeviceChangeFunc = (result:wifi.WifiP2pDevice[]) => {
    console.info("p2p peer device change receive event: " + JSON.stringify(result));
    wifi.getP2pPeerDevices((err, data) => {
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

    wifi.getCurrentGroup((err, data) => {
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

Cancels this P2P connection.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Starts to discover devices.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
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

Stops discovering devices.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
```ts
import wifi from '@ohos.wifi';

try {
	wifi.stopDiscoverDevices();	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.deletePersistentGroup<sup>8+</sup>

deletePersistentGroup(netId: number): boolean

Deletes a persistent group.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**


  | **Name**| **Type**| Mandatory| **Description**|
  | -------- | -------- | -------- | -------- |
  | netId | number | Yes| ID of the group to delete.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
```ts
import wifi from '@ohos.wifi';

try {
	let netId = 0;
	wifi.deletePersistentGroup(netId);	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## WifiP2pGroupInfo<sup>8+</sup>

Represents the P2P group information.

**System capability**: SystemCapability.Communication.WiFi.P2P

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| isP2pGo | boolean | Yes| No| Whether the device is the group owner.|
| ownerInfo | [WifiP2pDevice](#wifip2pdevice8) | Yes| No| Device information of the group.|
| passphrase | string | Yes| No| Passphrase of the group.|
| interface | string | Yes| No| Interface name.|
| groupName | string | Yes| No| Group name.|
| networkId | number | Yes| No| Network ID.|
| frequency | number | Yes| No| Frequency of the group.|
| clientDevices | [WifiP2pDevice[]](#wifip2pdevice8) | Yes| No| List of connected devices.|
| goIpAddress | string | Yes| No| IP address of the group.|


## wifi.setDeviceName<sup>8+</sup>

setDeviceName(devName: string): boolean

Sets the device name.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | devName | string | Yes| Device name to set.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
```ts
import wifi from '@ohos.wifi';

try {
	let name = "****";
	wifi.setDeviceName(name);	
}catch(error){
	console.error("failed:" + JSON.stringify(error));
}
```

## wifi.on('wifiStateChange')<sup>7+</sup>

on(type: "wifiStateChange", callback: Callback&lt;number&gt;): void

Subscribes to WLAN state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiStateChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback invoked to return the WLAN state.|

**WLAN states** 

| **Value**| **Description**|
| -------- | -------- |
| 0 | Deactivated|
| 1 | Activated|
| 2 | Activating|
| 3 | Deactivating|


## wifi.off('wifiStateChange')<sup>7+</sup>

off(type: "wifiStateChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the WLAN state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvPowerNotifyFunc = (result:number) => {
    console.info("Receive power state change event: " + result);
}

// Register an event.
wifi.on("wifiStateChange", recvPowerNotifyFunc);

// Unregister an event.
wifi.off("wifiStateChange", recvPowerNotifyFunc);
```


## wifi.on('wifiConnectionChange')<sup>7+</sup>

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


## wifi.off('wifiConnectionChange')<sup>7+</sup>

off(type: "wifiConnectionChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiConnectionChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the WLAN connection state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvWifiConnectionChangeFunc = (result:number) => {
    console.info("Receive wifi connection change event: " + result);
}

// Register an event.
wifi.on("wifiConnectionChange", recvWifiConnectionChangeFunc);

// Unregister an event.
wifi.off("wifiConnectionChange", recvWifiConnectionChangeFunc);
```

## wifi.on('wifiScanStateChange')<sup>7+</sup>

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


## wifi.off('wifiScanStateChange')<sup>7+</sup>

off(type: "wifiScanStateChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN scan state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiScanStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the WLAN scan state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvWifiScanStateChangeFunc = (result:number) => {
    console.info("Receive Wifi scan state change event: " + result);
}

// Register an event.
wifi.on("wifiScanStateChange", recvWifiScanStateChangeFunc);

// Unregister an event.
wifi.off("wifiScanStateChange", recvWifiScanStateChangeFunc);
```

## wifi.on('wifiRssiChange')<sup>7+</sup>

on(type: "wifiRssiChange", callback: Callback&lt;number&gt;): void

Subscribes to RSSI changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiRssiChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback invoked to return the RSSI, in dBm.|


## wifi.off('wifiRssiChange')<sup>7+</sup>

off(type: "wifiRssiChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from RSSI changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiRssiChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the RSSI change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvWifiRssiChangeFunc = (result:number) => {
    console.info("Receive wifi rssi change event: " + result);
}

// Register an event.
wifi.on("wifiRssiChange", recvWifiRssiChangeFunc);

// Unregister an event.
wifi.off("wifiRssiChange", recvWifiRssiChangeFunc);

```
## wifi.on('streamChange')<sup>7+</sup>

on(type: "streamChange", callback: Callback&lt;number&gt;): void

Subscribes to Wi-Fi stream changes.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **streamChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback invoked to return the Wi-Fi stream change, which can be any of the following values:<br>- **0**: No stream.<br>- **1**: Downward.<br>- **2**: Upward.<br>- **3**: Bidirectional. |

## wifi.off('streamChange')<sup>7+</sup>

off(type: "streamChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from Wi-Fi stream changes.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **streamChange**.|
| callback | Callback&lt;number&gt; | No| Callback for the Wi-Fi stream change, which can be any of the following values:<br>- **0**: No stream.<br>- **1**: Downward.<br>- **2**: Upward.<br>- **3**: Bidirectional.|

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

## wifi.on('hotspotStateChange')<sup>7+</sup>

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

**Example**
```ts
import wifi from '@ohos.wifi';

let recvHotspotStateChangeFunc = (result:number) => {
    console.info("Receive hotspot state change event: " + result);
}

// Register an event.
wifi.on("hotspotStateChange", recvHotspotStateChangeFunc);

// Unregister an event.
wifi.off("hotspotStateChange", recvHotspotStateChangeFunc);
```

## wifi.off('hotspotStateChange')<sup>7+</sup>

off(type: "hotspotStateChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from hotspot state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback for the hotspot state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

## wifi.on('hotspotStaJoin')<sup>7+</sup>

on(type: "hotspotStaJoin", callback: Callback&lt;StationInfo&gt;): void

Subscribes to the connection of an STA to a Wi-Fi hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStaJoin**.|
  | callback | Callback&lt;StationInfo&gt; | Yes| Callback invoked when an STA is connected to a Wi-Fi hotspot.|

## wifi.off('hotspotStaJoin')<sup>7+</sup>

off(type: "hotspotStaJoin", callback?: Callback&lt;StationInfo&gt;): void

Unsubscribes from the connection of an STA to a Wi-Fi hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStaJoin**.|
  | callback | Callback&lt;StationInfo&gt; | No| Callback for the connection of an STA to a Wi-Fi hotspot.|

  **Example**
```ts
import wifi from '@ohos.wifi';

let recvHotspotStaJoinFunc = (result:wifi.StationInfo) => {
    console.info("Receive hotspot sta join event: " + result);
}

// Register an event.
wifi.on("hotspotStaJoin", recvHotspotStaJoinFunc);

// Unregister an event.
wifi.off("hotspotStaJoin", recvHotspotStaJoinFunc);

```

## wifi.on('hotspotStaLeave')<sup>7+</sup>

on(type: "hotspotStaLeave", callback: Callback&lt;StationInfo&gt;): void

Subscribes to the disconnection of an STA from a Wi-Fi hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStaLeave**.|
  | callback | Callback&lt;StationInf]&gt; | Yes| Callback invoked when an STA is disconnected from a Wi-Fi hotspot.|

## wifi.off('hotspotStaLeave')<sup>9+</sup>

off(type: "hotspotStaLeave", callback?: Callback&lt;StationInfo&gt;): void

Unsubscribes from the disconnection of an STA from a Wi-Fi hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStaLeave**.|
  | callback | Callback&lt;StationInf]&gt; | No| Callback for the disconnection of an STA from a Wi-Fi hotspot.|

  **Example**
```ts
import wifi from '@ohos.wifi';

let recvHotspotStaLeaveFunc = (result:wifi.StationInfo) => {
    console.info("Receive hotspot sta leave event: " + result);
}

// Register an event.
wifi.on("hotspotStaLeave", recvHotspotStaLeaveFunc);

// Unregister an event.
wifi.off("hotspotStaLeave", recvHotspotStaLeaveFunc);

```

## wifi.on('p2pStateChange')<sup>8+</sup>

on(type: "p2pStateChange", callback: Callback&lt;number&gt;): void

Subscribes to P2P state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pStateChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback invoked to return the P2P state.|

**P2P states**

| **Value**| **Description**|
| -------- | -------- |
| 1 | Available|
| 2 | Opening|
| 3 | Opened|
| 4 | Closing|
| 5 | Closed|

## wifi.off('p2pStateChange')<sup>8+</sup>

off(type: "p2pStateChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from P2P state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback for the P2P state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvP2pStateChangeFunc = (result:number) => {
    console.info("Receive p2p state change event: " + result);
}

// Register an event.
wifi.on("p2pStateChange", recvP2pStateChangeFunc);

// Unregister an event.
wifi.off("p2pStateChange", recvP2pStateChangeFunc);
```

## wifi.on('p2pConnectionChange')<sup>8+</sup>

on(type: "p2pConnectionChange", callback: Callback&lt;WifiP2pLinkedInfo&gt;): void

Subscribes to P2P connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pConnectionChange**.|
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | Yes| Callback invoked to return the P2P connection state.|


## wifi.off('p2pConnectionChange')<sup>8+</sup>

off(type: "p2pConnectionChange", callback?: Callback&lt;WifiP2pLinkedInfo&gt;): void

Unsubscribes from P2P connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pConnectionChange**.|
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | No| Callback for the P2P connection state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvP2pConnectionChangeFunc = (result:wifi.WifiP2pLinkedInfo) => {
    console.info("Receive p2p connection change event: " + result);
}

// Register an event.
wifi.on("p2pConnectionChange", recvP2pConnectionChangeFunc);

// Unregister an event.
wifi.off("p2pConnectionChange", recvP2pConnectionChangeFunc);
```

## wifi.on('p2pDeviceChange')<sup>8+</sup>

on(type: "p2pDeviceChange", callback: Callback&lt;WifiP2pDevice&gt;): void

Subscribes to P2P device state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice8)&gt; | Yes| Callback invoked to return the P2P device state.|


## wifi.off('p2pDeviceChange')<sup>8+</sup>

off(type: "p2pDeviceChange", callback?: Callback&lt;WifiP2pDevice&gt;): void

Unsubscribes from P2P device state changes.

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice8)&gt; | No| Callback for the P2P device state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvP2pDeviceChangeFunc = (result:wifi.WifiP2pDevice) => {
    console.info("Receive p2p device change event: " + result);
}

// Register an event.
wifi.on("p2pDeviceChange", recvP2pDeviceChangeFunc);

// Unregister an event.
wifi.off("p2pDeviceChange", recvP2pDeviceChangeFunc);
```

## wifi.on('p2pPeerDeviceChange')<sup>8+</sup>

on(type: "p2pPeerDeviceChange", callback: Callback&lt;WifiP2pDevice[]&gt;): void

Subscribes to P2P peer device state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pPeerDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | Yes| Callback invoked to return the P2P peer device state.|


## wifi.off('p2pPeerDeviceChange')<sup>8+</sup>

off(type: "p2pPeerDeviceChange", callback?: Callback&lt;WifiP2pDevice[]&gt;): void

Unsubscribes from P2P peer device state changes.

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pPeerDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | No| Callback for the peer device state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvP2pPeerDeviceChangeFunc = (result:wifi.WifiP2pDevice[]) => {
    console.info("Receive p2p peer device change event: " + result);
}

// Register an event.
wifi.on("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);

// Unregister an event.
wifi.off("p2pPeerDeviceChange", recvP2pPeerDeviceChangeFunc);
```

## wifi.on('p2pPersistentGroupChange')<sup>8+</sup>

on(type: "p2pPersistentGroupChange", callback: Callback&lt;void&gt;): void

Subscribes to P2P persistent group state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pPersistentGroupChange**.|
  | callback | Callback&lt;void&gt; | Yes| Callback invoked to return the P2P persistent group state.|


## wifi.off('p2pPersistentGroupChange')<sup>8+</sup>

off(type: "p2pPersistentGroupChange", callback?: Callback&lt;void&gt;): void

Unsubscribes from P2P persistent group state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pPersistentGroupChange**.|
  | callback | Callback&lt;void&gt; | No| Callback for the P2P persistent group state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvP2pPersistentGroupChangeFunc = (result:void) => {
    console.info("Receive p2p persistent group change event: " + result);
}

// Register an event.
wifi.on("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);

// Unregister an event.
wifi.off("p2pPersistentGroupChange", recvP2pPersistentGroupChangeFunc);

```

## wifi.on('p2pDiscoveryChange')<sup>8+</sup>

on(type: "p2pDiscoveryChange", callback: Callback&lt;number&gt;): void

Subscribes to P2P device discovery state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDiscoveryChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback invoked to return the P2P device discovery state.|

**P2P discovered device states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Initial state.|
| 1 | Discovered.|


## wifi.off('p2pDiscoveryChange')<sup>8+</sup>

off(type: "p2pDiscoveryChange", callback?: Callback&lt;number&gt;): void

Unsubscribes from P2P device discovery state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDiscoveryChange**.|
  | callback | Callback&lt;number&gt; | No| Callback for the P2P device discovery state change. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
```ts
import wifi from '@ohos.wifi';

let recvP2pDiscoveryChangeFunc = (result:number) => {
    console.info("Receive p2p discovery change event: " + result);
}

// Register an event.
wifi.on("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);

// Unregister an event.
wifi.off("p2pDiscoveryChange", recvP2pDiscoveryChangeFunc);
```
