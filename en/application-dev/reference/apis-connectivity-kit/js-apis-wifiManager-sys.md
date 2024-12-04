# @ohos.wifiManager (WLAN) (System API)
The **WLAN** module provides basic wireless local area network (WLAN) functions, peer-to-peer (P2P) functions, and WLAN message notification services. It allows applications to communicate with devices over WLAN.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.wifiManager (WLAN)](js-apis-wifiManager.md).

## Modules to Import

```ts
import { wifiManager } from '@kit.ConnectivityKit';
```

## wifiManager.enableWifi<sup>9+</sup>

enableWifi(): void

Enables WLAN. This is an asynchronous API. You need to register a callback for the **wifiStateChange** event to check whether WLAN is successfully enabled.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          | 
| 2501000  | Operation failed.|
| 2501003  | Failed for wifi is closing. |

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.enableWifi();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.disableWifi<sup>9+</sup>

disableWifi(): void

Disables WLAN. This is an asynchronous API. You need to register a callback for the **wifiStateChange** event to check whether WLAN is successfully disabled.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501004  | Failed for wifi is opening. |

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.disableWifi();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.enableSemiWifi<sup>12+</sup>

enableSemiWifi(): void

Enables WLAN partially, that is, enables P2P and Huawei Magneto Link (HML) while disabling STA. You need to register a callback for the **wifiStateChange** event to return the operation result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          | 
| 2501000  | Operation failed.|
| 2501004  | Failed for wifi is opening. |

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.enableSemiWifi();
	} catch(error) {
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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.startScan();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
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

Obtains whether scan is always allowed.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean| Whether scan is always allowed. The value **true** means scan is allowed; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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
| config | [WifiDeviceConfig](#wifideviceconfig9) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the ID of the added network configuration. If **-1** is returned, the network configuration fails to be added.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

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

## WifiDeviceConfig<sup>9+</sup>

Represents the WLAN configuration.

**System capability**: SystemCapability.Communication.WiFi.STA


| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| creatorUid | number | Yes| No| ID of the creator.<br> **System API**: This is a system API.|
| disableReason | number | Yes| No| Reason for disabling WLAN.<br> **System API**: This is a system API.|
| netId | number | Yes| No| Network ID.<br> **System API**: This is a system API.|
| randomMacType | number | Yes| No| MAC address type. <br>The value **0** indicates random MAC address, and **1** indicates device MAC address.<br> **System API**: This is a system API.|
| randomMacAddr | string | Yes| No| MAC address.<br> **System API**: This is a system API.|
| ipType | [IpType](#iptype9) | Yes| No| IP address type.<br> **System API**: This is a system API.|
| staticIp | [IpConfig](#ipconfig9) | Yes| No| Static IP address information.<br> **System API**: This is a system API.|
| proxyConfig<sup>10+</sup> | [WifiProxyConfig](#wifiproxyconfig10) | Yes| No| Proxy configuration.<br> **System API**: This is a system API.|

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


## WifiProxyConfig<sup>10+</sup>

Represents the Wi-Fi proxy configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| proxyMethod | ProxyMethod | Yes| No| Proxy method.|
| pacWebAddress | string | Yes| No| PAC web address of the proxy automatically configured.|
| serverHostName | string | Yes| No| Server host name of the proxy manually configured.|
| serverPort | number | Yes| No| Server port of the proxy manually configured.|
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
| config | [WifiDeviceConfig](#wifideviceconfig9) | Yes| WLAN configuration to add. The default **bssidType** is random device address.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **0** and **data** is the network configuration ID. If **data** is **-1**, the operation has failed. If the operation fails, **error** is not **0**.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

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
| config | [WifiDeviceConfig](#wifideviceconfig9) | Yes| Configuration of the WLAN to connect. The default **bssidType** is random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
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

## wifiManager.disconnect<sup>9+</sup>

disconnect(): void

Disconnects the network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**:
  SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.disconnect();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```


## WifiLinkedInfo<sup>9+</sup>

Represents the WLAN connection information.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| networkId | number | Yes| No| Network configuration ID.<br> **System API**: This is a system API.|
| chload | number | Yes| No| Channel load. A larger value indicates a higher load.<br> **System API**: This is a system API.|
| snr | number | Yes| No| Signal-to-noise ratio (SNR).<br> **System API**: This is a system API.|
| suppState | [SuppState](#suppstate9) | Yes| No| Supplicant state.<br> **System API**: This is a system API.|



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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2401000  | Operation failed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.getSupportedFeatures();
		console.info("supportedFeatures:" + ret);
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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.getDeviceMacAddress();
		console.info("deviceMacAddress:" + JSON.stringify(ret));
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}

```

## wifiManager.getWifiDetailState<sup>12+</sup>

getWifiDetailState(): WifiDetailState

Obtains the Wi-Fi state.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | WifiDetailState | Wi-Fi state obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let ret = wifiManager.getWifiDetailState();
		console.info("wifiDetailState:" + ret);
	} catch(error) {
		console.error("failed:" + JSON.stringify(error));
	}

```

## WifiDetailState<sup>12+</sup>

Enumerates Wi-Fi states.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.WiFi.STA

| Name| Value| Description|
| -------- | -------- | -------- |
| UNKNOWN | -1 | Unidentified.|
| INACTIVE | 0 | Inactive.|
| ACTIVATED | 1 | Activated.|
| ACTIVATING | 2 | Activating.|
| DEACTIVATING | 3 | Deactivating|
| SEMI_ACTIVATING | 4 | Partially activating.|
| SEMI_ACTIVE | 5 | partially activated.|


## wifiManager.reassociate<sup>9+</sup>

reassociate(): void

Re-associates with the network.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|
| 2501001  | Wifi is closed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.reconnect();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getDeviceConfigs<sup>9+</sup>

getDeviceConfigs(): &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig9)&gt;

Obtains network configuration.

**System API**: This is a system API.

**Required permissions**:

API version 9: ohos.permission.GET_WIFI_INFO, ohos.permission.LOCATION, ohos.permission.APPROXIMATELY_LOCATION, and ohos.permission.GET_WIFI_CONFIG

API version 10 and later: ohos.permission.GET_WIFI_INFO and ohos.permission.GET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | &nbsp;Array&lt;[WifiDeviceConfig](#wifideviceconfig9)&gt; | Array of network configuration obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
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

## wifiManager.updateNetwork<sup>9+</sup>

updateNetwork(config: WifiDeviceConfig): number

Updates network configuration.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#wifideviceconfig9) | Yes| New WLAN configuration.|

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | number | ID of the updated network configuration. The value **-1** indicates that the operation has failed.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| [DisconnectedReason](#disconnectedreason-10) | Returns the reason of the latest disconnection obtained.|

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

## wifiManager.startPortalCertification<sup>11+</sup>

startPortalCertification(): void

**System API**: This is a system API.

Starts portal certification.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.startPortalCertification();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.enableHiLinkHandshake<sup>12+</sup>

enableHiLinkHandshake(isHiLinkEnable: boolean, bssid: string, config: WifiDeviceConfig): void

**System API**: This is a system API.

Enables or disables HiLink.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| isHiLinkEnable | boolean | Yes| Whether to enable hiLink. The value **true** means to enable HiLink; the value **false** means the opposite.|
| bssid | string | Yes| MAC address of the hotspot, for example, **00:11:22:33:44:55**.|
| config | [WifiDeviceConfig](#wifideviceconfig9) | Yes| WLAN configuration information. The value of **config.bssid** must be the same as that of the second parameter **bssid**. The default **bssidType** is random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';
	// You can obtain config data by using getScanInfoList, which can be used only when WifiScanInfo.isHiLinkNetwork is true.
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
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.factoryReset<sup>11+</sup>

factoryReset(): void

**System API**: This is a system API.

Resets Wi-Fi configurations.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.SET_WIFI_CONFIG

**System capability**: SystemCapability.Communication.WiFi.STA

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		wifiManager.factoryReset();
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```
## wifiManager.enableHotspot<sup>9+</sup>

enableHotspot(): void

Enables this hotspot. This API is an asynchronous interface. The **hotspotStateChange** callback must be registered and listened for.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
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
| securityType | [WifiSecurityType](js-apis-wifiManager.md#wifisecuritytype9)| Yes| Yes| Security type.|
| band | number | Yes| Yes| Hotspot band. The value **1** stands for 2.4 GHz, the value **2** for 5 GHz, and the value **3** for dual band.|
| channel<sup>10+</sup> | number | Yes| Yes| Hotspot channel (channels 1 to 14 for 2.4 GHz, and channels 7 to 196 for 5 GHz)|
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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let config = wifiManager.getHotspotConfig();
		console.info("result:" + JSON.stringify(config));		
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getStations<sup>9+</sup>

getStations(): &nbsp;Array&lt;StationInfo&gt;

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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
| macAddressType<sup>10+</sup> | [DeviceAddressType](js-apis-wifiManager.md#deviceaddresstype10) | Yes| No| MAC address type.|
| ipAddress | string | Yes| No| IP address.|

## wifiManager.addHotspotBlockList<sup>11+</sup>

addHotspotBlockList(stationInfo: StationInfo)

Adds a device to the list of blocked devices of the hotspot. Devices in the list cannot access the hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| stationInfo | [StationInfo](#stationinfo9) | Yes| Device to add.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let config:wifiManager.StationInfo = {
			name : "testSsid",
			macAddress : "11:22:33:44:55:66",
			ipAddress : "192.168.1.111"
		}
		// The device can be added to the block list only after the hotspot is enabled.
		wifiManager.addHotspotBlockList(config);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.delHotspotBlockList<sup>11+</sup>

delHotspotBlockList(stationInfo: StationInfo)

Delets a device from the list of blocked devices of the hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| stationInfo | [StationInfo](#stationinfo9) | Yes| Device to delete.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Incorrect parameter types.<br>2. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let config:wifiManager.StationInfo = {
			name : "testSsid",
			macAddress : "11:22:33:44:55:66",
			ipAddress : "192.168.1.111"
		}
		wifiManager.delHotspotBlockList(config);
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```

## wifiManager.getHotspotBlockList<sup>11+</sup>

getHotspotBlockList(): Array&lt;StationInfo&gt;

Obtains the list of blocked devices of the hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.MANAGE_WIFI_HOTSPOT (available only to system applications)

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| &nbsp;Array&lt;[StationInfo](#stationinfo9)&gt; | List of blocked devices obtained.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
  | -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**

```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let data = wifiManager.getHotspotBlockList();
		console.info("result:" + JSON.stringify(data));
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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1.Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

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
| Promise&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](js-apis-wifiManager.md#wifip2pgroupinfo9)&gt;&nbsp;&gt; | Promise used to return the group information obtained. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	wifiManager.getP2pGroups((err, data:wifiManager.WifiP2pGroupInfo) => {
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
| callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiP2pGroupInfo](js-apis-wifiManager.md#wifip2pgroupinfo9)&gt;&gt; | Yes| Callback used to return the result. If the operation is successful, **error** is **0** and **data** is the group information obtained. If the operation fails, **error** is not **0**. If the application has the **ohos.permission.GET_WIFI_PEERS_MAC** permission, **deviceAddress** in the return value is a real device address; otherwise, **deviceAddress** is a random device address.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

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

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types. 3. Parameter verification failed. |
| 801 | Capability not supported.          |
| 2801000  | Operation failed. |

**Example**
```ts
	import { wifiManager } from '@kit.ConnectivityKit';

	try {
		let name = "****";
		wifiManager.setDeviceName(name);	
	}catch(error){
		console.error("failed:" + JSON.stringify(error));
	}
```


## wifiManager.on('streamChange')<sup>9+</sup>

on(type: 'streamChange', callback: Callback&lt;number&gt;): void

Subscribes to Wi-Fi stream changes. When the service exits, call off(type: 'streamChange', callback?: Callback&lt;number&gt;) to unregister the callback registered.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **streamChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the Wi-Fi stream change, which can be any of the following values:<br>- **0**: No stream.<br>- **1**: Downward.<br>- **2**: Upward.<br>- **3**: Bidirectional.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('streamChange')<sup>9+</sup>

off(type: 'streamChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from Wi-Fi stream changes.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_CONNECTION

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **streamChange**.|
| callback | Callback&lt;number&gt; | No| Callback to unregister. The stream change can be any of the following values:<br>- **0**: No stream.<br>- **1**: Downward.<br>- **2**: Upward.<br>- **3**: Bidirectional.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
import { wifi } from '@kit.ConnectivityKit';

let recvStreamChangeFunc = (result:number) => {
    console.info("Receive stream change event: " + result);
}

// Register an event.
wifi.on("streamChange", recvStreamChangeFunc);

// Unregister an event.
wifi.off("streamChange", recvStreamChangeFunc);

```
## wifiManager.on('deviceConfigChange')<sup>9+</sup>

on(type: 'deviceConfigChange', callback: Callback&lt;number&gt;): void

Subscribes to Wi-Fi device configuration changes. When the service exits, call off(type: 'deviceConfigChange', callback?: Callback&lt;number&gt;) to unregister the callback registered.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **deviceConfigChange**.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the device configuration change, which can be any of the following values:<br>- **0**: device configuration added.<br>- **1**: device configuration changed.<br>- **2**: device configuration deleted.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

## wifiManager.off('deviceConfigChange')<sup>9+</sup>

off(type: 'deviceConfigChange', callback?: Callback&lt;number&gt;): void

Unsubscribes from Wi-Fi device configuration changes.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **deviceConfigChange**.|
| callback | Callback&lt;number&gt; | No| Callback to unregister. The device configuration change can be any of the following values:<br>- **0**: device configuration added.<br>- **1**: device configuration changed.<br>- **2**: device configuration deleted.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2501000  | Operation failed.|

**Example**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

let recvDeviceConfigChangeFunc = (result:number) => {
    console.info("Receive device config change event: " + result);
}

// Register an event.
wifi.on("deviceConfigChange", recvDeviceConfigChangeFunc);

// Unregister an event.
wifi.off("deviceConfigChange", recvDeviceConfigChangeFunc);

```

## wifiManager.on('hotspotStaJoin')<sup>9+</sup>

on(type: 'hotspotStaJoin', callback: Callback&lt;StationInfo&gt;): void

Subscribes to the event of an STA joining a Wi-Fi hotspot. When the service exits, call off(type: 'hotspotStaJoin', callback?: Callback&lt;StationInfo&gt;) to unregister the callback registered.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStaJoin**.|
| callback | Callback&lt;StationInfo&gt; | Yes| Callback used to return the event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

## wifiManager.off('hotspotStaJoin')<sup>9+</sup>

off(type: 'hotspotStaJoin', callback?: Callback&lt;StationInfo&gt;): void

Unsubscribes from the event of an STA joining a Wi-Fi hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStaJoin**.|
| callback | Callback&lt;StationInfo&gt; | No| Callback to unregister.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

let recvHotspotStaJoinFunc = (result:wifiManager.StationInfo) => {
    console.info("Receive hotspot sta join event: " + result);
}

// Register an event.
wifiManager.on("hotspotStaJoin", recvHotspotStaJoinFunc);

// Unregister an event.
wifiManager.off("hotspotStaJoin", recvHotspotStaJoinFunc);

```

## wifiManager.on('hotspotStaLeave')<sup>9+</sup>

on(type: 'hotspotStaLeave', callback: Callback&lt;StationInfo&gt;): void

Subscribes to the event of an STA leaving a Wi-Fi hotspot. When the service exits, call off(type: 'hotspotStaLeave', callback?: Callback&lt;StationInfo&gt;) to unregister the callback registered.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type, which has a fixed value of **hotspotStaLeave**.|
  | callback | Callback&lt;StationInf]&gt; | Yes| Callback used to return the event.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

## wifiManager.off('hotspotStaLeave')<sup>9+</sup>

off(type: 'hotspotStaLeave', callback?: Callback&lt;StationInfo&gt;): void

Unsubscribes from the event of an STA leaving a Wi-Fi hotspot.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_WIFI_HOTSPOT

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type, which has a fixed value of **hotspotStaLeave**.|
| callback | Callback&lt;StationInf]&gt; | No| Callback to unregister.|

**Error codes**

For details about the error codes, see [Wi-Fi Error Codes](errorcode-wifi.md).

| **ID**| **Error Message**|
| -------- | -------- |
| 201 | Permission denied.                 |
| 202 | System API is not allowed called by Non-system application. |
| 401 | Invalid parameters. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801 | Capability not supported.          |
| 2601000  | Operation failed. |

**Example**
```ts
import { wifiManager } from '@kit.ConnectivityKit';

let recvHotspotStaLeaveFunc = (result:wifiManager.StationInfo) => {
    console.info("Receive hotspot sta leave event: " + result);
}

// Register an event.
wifiManager.on("hotspotStaLeave", recvHotspotStaLeaveFunc);

// Unregister an event.
wifiManager.off("hotspotStaLeave", recvHotspotStaLeaveFunc);

```
