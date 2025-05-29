# @ohos.wifi (WLAN)

The **WLAN** module provides basic wireless local area network (WLAN) functions, peer-to-peer (P2P) functions, and WLAN message notification services. It allows applications to communicate with other devices over WLAN.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module are no longer maintained since API version 9. You are advised to use [@ohos.wifiManager (WLAN)](js-apis-wifiManager.md).


## Modules to Import

```ts
import wifi from '@ohos.wifi';
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

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION or ohos.permission.GET_WIFI_PEERS_MAC (
available only for system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | Promise&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&nbsp;&gt; | Promise used to return the detected hotspots.|


## wifi.getScanInfos

getScanInfos(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void

Obtains the scan result. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION or ohos.permission.GET_WIFI_PEERS_MAC (
available only for system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the detected hotspots. Otherwise, **err** is a non-zero value and **data** is empty.|

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
| ssid | string | Yes| No| Service set identifier (SSID) of the hotspot, in UTF-8 format. The maximum length is 32 bytes.|
| bssid | string | Yes| No| Basic service set identifier (BSSID) of the hotspot, for example, **00:11:22:33:44:55**.|
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



## WifiDeviceConfig

Represents the WLAN configuration.

**System capability**: SystemCapability.Communication.WiFi.STA


| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| ssid | string | Yes| No| Service set identifier (SSID) of the hotspot, in UTF-8 format. The maximum length is 32 bytes.|
| bssid | string | Yes| No| Hotspot BSSID, for example, **00:11:22:33:44:55**.|
| preSharedKey | string | Yes| No| PSK of the hotspot. The maximum length is 64 bytes.|
| isHiddenSsid | boolean | Yes| No| Whether the network is hidden.|
| securityType | [WifiSecurityType](#wifisecuritytype) | Yes| No| Security type.|



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
  | Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the operation is successful; the value **false** means the opposite.|

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
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is **true**. If the operation fails, **data** is **false**. If **err** is not **0**, an error has occurred.|

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
  | config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the operation is successful; the value **false** means the opposite.|

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
  | config | [WifiDeviceConfig](#wifideviceconfig) | Yes| WLAN configuration to add.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is **true**. If the operation fails, **data** is **false**. If **err** is not **0**, an error has occurred.|

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
  | callback | AsyncCallback&lt;[WifiLinkedInfo](#wifilinkedinfo)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the WLAN connection information obtained. If **err** is not **0**, an error has occurred.|

**Example**
```ts
import wifi from '@ohos.wifi';

wifi.getLinkedInfo((err, data:wifi.WifiLinkedInfo) => {
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
| ssid | string | Yes| No| Service set identifier (SSID) of the hotspot, in UTF-8 format. The maximum length is 32 bytes.|
| bssid | string | Yes| No| Hotspot BSSID, for example, **00:11:22:33:44:55**.|
| rssi | number | Yes| No| Received signal strength indicator (RSSI) of the hotspot, in dBm.|
| band | number | Yes| No| Frequency band of the WLAN AP.|
| linkSpeed | number | Yes| No| Speed of the WLAN AP.|
| frequency | number | Yes| No| Frequency of the WLAN AP.|
| isHidden | boolean | Yes| No| Whether to hide the WLAN AP.|
| isRestricted | boolean | Yes| No| Whether to restrict data volume at the WLAN AP.|
| macAddress | string | Yes| No| MAC address of the device.|
| ipAddress | number | Yes| No| IP address of the device that sets up the WLAN connection.|
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


## wifi.isConnected<sup>7+</sup>

isConnected(): boolean

Checks whether the WLAN is connected.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the WLAN is connected; returns **false** otherwise.|



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

**System capability**: SystemCapability.Communication.WiFi.AP.Core

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


## wifi.getP2pLinkedInfo<sup>8+</sup>

getP2pLinkedInfo(): Promise&lt;WifiP2pLinkedInfo&gt;

Obtains P2P link information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | Promise used to return the P2P link information.|



## WifiP2pLinkedInfo<sup>8+</sup>

Represents the P2P link information obtained.

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
  | callback | AsyncCallback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the P2P link information. If **err** is not **0**, an error has occurred.|

**Example**
```ts
import wifi from '@ohos.wifi';

wifi.getP2pLinkedInfo((err, data:wifi.WifiP2pLinkedInfo) => {
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
  | callback | AsyncCallback&lt;[WifiP2pGroupInfo](#wifip2pgroupinfo8)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the group information obtained. If **err** is not **0**, an error has occurred.|

**Example**
```ts
import wifi from '@ohos.wifi';

wifi.getCurrentGroup((err, data:wifi.WifiP2pGroupInfo) => {
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
  | callback | AsyncCallback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the peer device list obtained. If **err** is not **0**, an error has occurred.|

**Example**
```ts
import wifi from '@ohos.wifi';

wifi.getP2pPeerDevices((err, data:wifi.WifiP2pDevice) => {
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
| groupName | string | Yes| No| Group name.|
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
    wifi.getP2pLinkedInfo((err, data:wifi.WifiP2pLinkedInfo) => {
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
    wifi.getP2pPeerDevices((err, data:wifi.WifiP2pDevice) => {
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

    wifi.getCurrentGroup((err, data:wifi.WifiP2pGroupInfo) => {
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



## wifi.on('wifiStateChange')<sup>7+</sup>

on(type: 'wifiStateChange', callback: Callback&lt;number&gt;): void

Subscribes to WLAN state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiStateChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback used to return the WLAN state.|

**WLAN states** 

| **Value**| **Description**|
| -------- | -------- |
| 0 | Deactivated|
| 1 | Activated|
| 2 | Activating|
| 3 | Deactivating|


## wifi.off('wifiStateChange')<sup>7+</sup>

off(type: 'wifiStateChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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

on(type: 'wifiConnectionChange', callback: Callback&lt;number&gt;): void

Subscribes to WLAN connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

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


## wifi.off('wifiConnectionChange')<sup>7+</sup>

off(type: 'wifiConnectionChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiConnectionChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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

on(type: 'wifiScanStateChange', callback: Callback&lt;number&gt;): void

Subscribes to WLAN scan state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

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


## wifi.off('wifiScanStateChange')<sup>7+</sup>

off(type: 'wifiScanStateChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from WLAN scan state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **wifiScanStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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

on(type: 'wifiRssiChange', callback: Callback&lt;number&gt;): void

Subscribes to RSSI changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiRssiChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback used to return the RSSI, in dBm.|


## wifi.off('wifiRssiChange')<sup>7+</sup>

off(type: 'wifiRssiChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from RSSI changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **wifiRssiChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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


## wifi.on('hotspotStateChange')<sup>7+</sup>

on(type: 'hotspotStateChange', callback: Callback&lt;number&gt;): void

Subscribes to hotspot state changes.

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

off(type: 'hotspotStateChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from hotspot state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|



## wifi.on('p2pStateChange')<sup>8+</sup>

on(type: 'p2pStateChange', callback: Callback&lt;number&gt;): void

Subscribes to P2P state changes.

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

## wifi.off('p2pStateChange')<sup>8+</sup>

off(type: 'p2pStateChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from P2P state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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

on(type: 'p2pConnectionChange', callback: Callback&lt;WifiP2pLinkedInfo&gt;): void

Subscribes to P2P connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pConnectionChange**.|
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | Yes| Callback used to return the P2P connection state.|


## wifi.off('p2pConnectionChange')<sup>8+</sup>

off(type: 'p2pConnectionChange', callback?: Callback&lt;WifiP2pLinkedInfo&gt;): void

Unsubscribes from P2P connection state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pConnectionChange**.|
  | callback | Callback&lt;[WifiP2pLinkedInfo](#wifip2plinkedinfo8)&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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

on(type: 'p2pDeviceChange', callback: Callback&lt;WifiP2pDevice&gt;): void

Subscribes to P2P device state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice8)&gt; | Yes| Callback used to return the P2P device state.|


## wifi.off('p2pDeviceChange')<sup>8+</sup>

off(type: 'p2pDeviceChange', callback?: Callback&lt;WifiP2pDevice&gt;): void

Unsubscribes from P2P device state changes.

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice](#wifip2pdevice8)&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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

on(type: 'p2pPeerDeviceChange', callback: Callback&lt;WifiP2pDevice[]&gt;): void

Subscribes to P2P peer device state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pPeerDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | Yes| Callback used to return the P2P peer device state.|


## wifi.off('p2pPeerDeviceChange')<sup>8+</sup>

off(type: 'p2pPeerDeviceChange', callback?: Callback&lt;WifiP2pDevice[]&gt;): void

Unsubscribes from P2P peer device state changes.

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pPeerDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice[]](#wifip2pdevice8)&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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

on(type: 'p2pPersistentGroupChange', callback: Callback&lt;void&gt;): void

Subscribes to P2P persistent group state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pPersistentGroupChange**.|
  | callback | Callback&lt;void&gt; | Yes| Callback used to return the P2P persistent group state.|


## wifi.off('p2pPersistentGroupChange')<sup>8+</sup>

off(type: 'p2pPersistentGroupChange', callback?: Callback&lt;void&gt;): void

Unsubscribes from P2P persistent group state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pPersistentGroupChange**.|
  | callback | Callback&lt;void&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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

on(type: 'p2pDiscoveryChange', callback: Callback&lt;number&gt;): void

Subscribes to P2P device discovery state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDiscoveryChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback used to return the P2P device discovery state.|

**P2P discovered device states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Initial state.|
| 1 | Discovered.|


## wifi.off('p2pDiscoveryChange')<sup>8+</sup>

off(type: 'p2pDiscoveryChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from P2P device discovery state changes.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **p2pDiscoveryChange**.|
  | callback | Callback&lt;number&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified event will be unregistered.|

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
