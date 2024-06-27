# @ohos.wifi (WLAN) (System API)

The **WLAN** module provides basic wireless local area network (WLAN) functions, peer-to-peer (P2P) functions, and WLAN message notification services. It allows applications to communicate with other devices over WLAN.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.wifi (WLAN)](js-apis-wifi.md).
> The APIs of this module are no longer maintained since API version 9. You are advised to use [@ohos.wifiManager (WLAN)](js-apis-wifiManager-sys.md).


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
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the network configuration ID. If **data** is **-1**, the operation has failed. If **err** is not **0**, an error has occurred.|

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


## WifiLinkedInfo

Represents the WLAN connection information.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| networkId | number | Yes| No| Network configuration ID.<br>**System API**: This is a system API.|
| chload | number | Yes| No| Channel load. A larger value indicates a higher load.<br>**System API**: This is a system API.|
| snr | number | Yes| No| Signal-to-noise ratio (SNR).<br>**System API**: This is a system API.|
| suppState | [SuppState](#suppstate) | Yes| No| Supplicant state.<br>**System API**: This is a system API.|


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
| securityType | [WifiSecurityType](js-apis-wifi.md#wifisecuritytype) | Yes| No| Security type.|
| band | number | Yes| No| Hotspot band. The value **1** stands for 2.4 GHz, the value **2** for 5 GHz, and the value **3** for dual band.|
| preSharedKey | string | Yes| No| PSK of the hotspot.|
| maxConn | number | Yes| No| Maximum number of connections allowed.|


## wifi.getHotspotConfig<sup>7+</sup>

getHotspotConfig(): HotspotConfig

Obtains hotspot configuration.

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
| callback | Callback&lt;number&gt; | Yes| Callback used to return the Wi-Fi stream change, which can be any of the following values:<br>- **0**: No stream.<br>- **1**: Downward.<br>- **2**: Upward.<br>- **3**: Bidirectional. |

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
| callback | Callback&lt;number&gt; | No| Callback to unregister. The Wi-Fi stream change can be any of the following values:<br>- **0**: No stream.<br>- **1**: Downward.<br>- **2**: Upward.<br>- **3**: Bidirectional.|

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


## wifi.on('hotspotStaJoin')<sup>7+</sup>

on(type: "hotspotStaJoin", callback: Callback&lt;StationInfo&gt;): void

Subscribes to the event of an STA joining a Wi-Fi hotspot.

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

Unsubscribes from the event of an STA joining a Wi-Fi hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStaJoin**.|
| callback | Callback&lt;StationInfo&gt; | No| Callback to unregister.|

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

Subscribes to the event of an STA leaving a Wi-Fi hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStaLeave**.|
| callback | Callback&lt;StationInf]&gt; | Yes| Callback invoked when an STA is disconnected from a Wi-Fi hotspot.|

## wifi.off('hotspotStaLeave')<sup>7+</sup>

off(type: "hotspotStaLeave", callback?: Callback&lt;StationInfo&gt;): void

Unsubscribes from the event of an STA leaving a Wi-Fi hotspot.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStaLeave**.|
| callback | Callback&lt;StationInf]&gt; | No| Callback to unregister.|

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
