# WLAN

> **NOTE**<br>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import wifi from '@ohos.wifi';
```

## wifi.isWifiActive

isWifiActive(): boolean

Checks whether the WLAN is activated.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**
  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the WLAN is activated; returns **false** otherwise.|


## wifi.scan

scan(): boolean

Starts a scan for WLAN.

**Required permissions**: ohos.permission.SET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**
  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the scan is successful; returns **false** otherwise.|


## wifi.getScanInfos

getScanInfos(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt;

Obtains the scan result. This method uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO, ohos.permission.GET_WIFI_PEERS_MAC, or ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**
  | **Type**| **Description**|
  | -------- | -------- |
  | Promise&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&nbsp;&gt; | Promise used to return the scan result, which is a list of hotspots detected.|


## wifi.getScanInfos

getScanInfos(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void

Obtains the scan result. This method uses an asynchronous callback to return the result.

**Required permissions**: at least one of ohos.permission.GET_WIFI_INFO, ohos.permission.GET_WIFI_PEERS_MAC, and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;&nbsp;Array&lt;[WifiScanInfo](#wifiscaninfo)&gt;&gt; | Yes| Callback invoked to return the result, which is a list of hotspots detected.|

**Example**
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

Represents WLAN hotspot information.

| **Name**| **Type**| **Readable/Writable**| **Description**|
| -------- | -------- | -------- | -------- |
| ssid | string | Read only| Hotspot service set identifier (SSID), in UTF-8 format.|
| bssid | string | Read only| Basic service set identifier (BSSID) of the hotspot.|
| capabilities | string | Read only| Hotspot capabilities.|
| securityType | [WifiSecurityType](#WifiSecurityType) | Read only| WLAN security type.|
| rssi | number | Read only| Signal strength of the hotspot, in dBm.|
| band | number | Read only| Frequency band of the WLAN access point (AP).|
| frequency | number | Read only| Frequency of the WLAN AP.|
| channelWidth | number | Read only| Bandwidth of the WLAN AP.|
| timestamp | number | Read only| Timestamp.|


## WifiSecurityType

Enumerates the WLAN security types.

| **Name**| **Default Value**| **Description**|
| -------- | -------- | -------- |
| WIFI_SEC_TYPE_INVALID | 0 | Invalid security type|
| WIFI_SEC_TYPE_OPEN | 1 | Open security type|
| WIFI_SEC_TYPE_WEP | 2 | Wired Equivalent Privacy (WEP)|
| WIFI_SEC_TYPE_PSK | 3 | Pre-shared key (PSK)|
| WIFI_SEC_TYPE_SAE | 4 | Simultaneous Authentication of Equals (SAE)|


## wifi.addUntrustedConfig<sup>7+</sup>

addUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt;

Adds untrusted WLAN configuration. This method uses a promise to return the result.

**Required permissions**:
  ohos.permission.SET_WIFI_INFO

**System capability**:
  SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#WifiDeviceConfig) | Yes| WLAN configuration to add.|

**Return value**
  | **Type**| **Description**|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the operation result. The value **true** indicates that the operation is successful; **false** indicates the opposite.|

## WifiDeviceConfig

Represents the WLAN configuration.

| **Name**| **Type**| **Readable/Writable**| **Description**|
| -------- | -------- | -------- | -------- |
| ssid | string | Read only| Hotspot SSID, in UTF-8 format.|
| bssid | string | Read only| BSSID of the hotspot.|
| preSharedKey | string | Read only| Private key of the hotspot.|
| isHiddenSsid | boolean | Read only| Whether to hide the network.|
| securityType | [WifiSecurityType](#WifiSecurityType) | Read only| Security type|


## wifi.addUntrustedConfig<sup>7+</sup>

addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void

Adds untrusted WLAN configuration. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#WifiDeviceConfig) | Yes| WLAN configuration to add.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Promise used to return the operation result. The value **true** indicates that the operation is successful; **false** indicates the opposite.|


## wifi.removeUntrustedConfig<sup>7+</sup>

removeUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt;

Removes untrusted WLAN configuration. This method uses a promise to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#WifiDeviceConfig) | Yes| WLAN configuration to remove.|

**Return value**
  | **Type**| **Description**|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the operation result. The value **true** indicates that the operation is successful; **false** indicates the opposite.|


## wifi.removeUntrustedConfig<sup>7+</sup>

removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void

Removes untrusted WLAN configuration. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiDeviceConfig](#WifiDeviceConfig) | Yes| WLAN configuration to remove.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Promise used to return the operation result. The value **true** indicates that the operation is successful; **false** indicates the opposite.|


## wifi.getSignalLevel

getSignalLevel(rssi: number, band: number): number

Obtains the WLAN signal strength.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | rssi | number | Yes| Signal strength of the hotspot, in dBm.|
  | band | number | Yes| Frequency band of the WLAN AP.|

**Return value**
  | **Type**| **Description**|
  | -------- | -------- |
  | number | Signal strength obtained. The value range is [0,&nbsp;4].|


## wifi.getLinkedInfo

getLinkedInfo(): Promise&lt;WifiLinkedInfo&gt;

Obtains WLAN connection information. This method uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiLinkedInfo](#WifiLinkedInfo)&gt; | Promise used to return the WLAN connection information obtained.|


## wifi.getLinkedInfo

getLinkedInfo(callback: AsyncCallback&lt;WifiLinkedInfo&gt;): void

Obtains WLAN connection information. This method uses a callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiLinkedInfo](#WifiLinkedInfo)&gt; | Yes| Callback invoked to return the WLAN connection information obtained.|

**Example**
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

Represents the WLAN connection information.

| Name| Type| Readable/Writable| Description|
| -------- | -------- | -------- | -------- |
| ssid | string | Read only| Hotspot SSID, in UTF-8 format.|
| bssid | string | Read only| BSSID of the hotspot.|
| rssi | number | Read only| Signal strength of the hotspot, in dBm.|
| band | number | Read only| Frequency band of the WLAN AP.|
| linkSpeed | number | Read only| Speed of the WLAN AP.|
| frequency | number | Read only| Frequency of the WLAN AP.|
| isHidden | boolean | Read only| Whether the WLAN AP is hidden.|
| isRestricted | boolean | Read only| Whether to restrict data volume at the WLAN AP.|
| macAddress | string | Read only| MAC address of the device.|
| ipAddress | number | Read only| IP address of the device that sets up the WLAN connection.|
| connState | [ConnState](#ConnState) | Read only| WLAN connection state.|


## ConnState

Enumerates the WLAN connection states.

| Name| Default Value| Description|
| -------- | -------- | -------- |
| SCANNING | 0 | The device is scanning for available APs.|
| CONNECTING | 1 | A WLAN connection is being established.|
| AUTHENTICATING | 2 | An authentication is being performed for a WLAN connection.|
| OBTAINING_IPADDR | 3 | The IP address of the WLAN connection is being acquired.|
| CONNECTED | 4 | A WLAN connection is established.|
| DISCONNECTING | 5 | The WLAN connection is being disconnected.|
| DISCONNECTED | 6 | The WLAN connection is disconnected.|
| UNKNOWN | 7 | Failed to set up a WLAN connection.|


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

**Feature IDs**

| Value| Description|
| -------- | -------- |
| 0x0001 | WLAN infrastructure mode|
| 0x0002 | 5 GHz bandwidth|
| 0x0004 | Generic Advertisement Service (GAS)/Access Network Query Protocol (ANQP) feature|
| 0x0008 | Wi-Fi Direct|
| 0x0010 | SoftAP|
| 0x0040 | Wi-Fi AWare|
| 0x8000 | WLAN AP/STA concurrency|
| 0x8000000 | WPA3 Personal (WPA-3 SAE)|
| 0x10000000 | WPA3-Enterprise&nbsp;Suite-B |
| 0x20000000 | Enhanced open feature|


## wifi.getIpInfo<sup>7+</sup>

getIpInfo(): IpInfo

Obtains IP information.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Return value**
  | **Type**| **Description**|
  | -------- | -------- |
  | [IpInfo](#IpInfo) | IP information obtained.|


## IpInfo<sup>7+</sup>

Represents IP information.

| **Name**| **Type**| **Readable/Writable**| **Description**|
| -------- | -------- | -------- | -------- |
| ipAddress | number | Read only| IP address|
| gateway | number | Read only| Gateway|
| netmask | number | Read only| Subnet mask|
| primaryDns | number | Read only| IP address of the preferred DNS server|
| secondDns | number | Read only| IP address of the alternate DNS server|
| serverIp | number | Read only| IP address of the DHCP server|
| leaseDuration | number | Read only| Lease duration of the IP address|


## wifi.getCountryCode<sup>7+</sup>

getCountryCode(): string

Obtains the country code.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.Core

**Return value**
  | **Type**| **Description**|
  | -------- | -------- |
  | string | Country code obtained.|


## wifi.getP2pLinkedInfo<sup>8+</sup>

getP2pLinkedInfo(): Promise&lt;WifiP2pLinkedInfo&gt;

Obtains peer-to-peer (P2P) connection information. This method uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiP2pLinkedInfo](#WifiP2pLinkedInfo)&gt; | Promise used to return the P2P connection information obtained.|


## wifi.getP2pLinkedInfo<sup>8+</sup>

getP2pLinkedInfo(callback: AsyncCallback&lt;WifiP2pLinkedInfo&gt;): void

Obtains P2P connection information. This method uses a callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pLinkedInfo](#WifiP2pLinkedInfo)&gt; | Yes| Callback used to return the P2P connection information obtained.|


## WifiP2pLinkedInfo<sup>8+</sup>

Represents the WLAN connection information.

| Name| Type| Readable/Writable| Description|
| -------- | -------- | -------- | -------- |
| connectState | [P2pConnectState](#P2pConnectState) | Read only| P2P connection state.|
| isGroupOwner | boolean | Read only| Whether it is a group.|
| groupOwnerAddr | string | Read only| MAC address of the group.|


## P2pConnectState<sup>8+</sup>

Enumerates the P2P connection states.

| Name| Default Value| Description|
| -------- | -------- | -------- |
| DISCONNECTED | 0 | Disconnected|
| CONNECTED | 1 | Connected|


## wifi.getCurrentGroup<sup>8+</sup>

getCurrentGroup(): Promise&lt;WifiP2pGroupInfo&gt;

Obtains the current P2P group information. This method uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiP2pGroupInfo](#WifiP2pGroupInfo)&gt; | Promise used to return the P2P group information obtained.|


## wifi.getCurrentGroup<sup>8+</sup>

getCurrentGroup(callback: AsyncCallback&lt;WifiP2pGroupInfo&gt;): void

Obtains the P2P group information. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pGroupInfo](#WifiP2pGroupInfo)&gt; | Yes| Callback used to return the P2P group information obtained.|


## WifiP2pGroupInfo<sup>8+</sup>

Represents the P2P group information.

| Name| Type| Readable/Writable| Description|
| -------- | -------- | -------- | -------- |
| isP2pGo | boolean | Read only| Whether it is a group.|
| ownerInfo | [WifiP2pDevice](#WifiP2pDevice) | Read only| Device information of the group.|
| passphrase | string | Read only| Private key of the group.|
| interface | string | Read only| Interface name.|
| groupName | string | Read only| Group name.|
| networkId | number | Read only| Network ID.|
| frequency | number | Read only| Frequency of the group.|
| clientDevices | [WifiP2pDevice[]](#WifiP2pDevice) | Read only| List of connected devices.|
| goIpAddress | string | Read only| IP address of the group.|

## WifiP2pDevice<sup>8+</sup>

Represents the P2P device information.

| Name| Type| Readable/Writable| Description|
| -------- | -------- | -------- | -------- |
| deviceName | string | Read only| Device name.|
| deviceAddress | string | Read only| MAC address of the device.|
| primaryDeviceType | string | Read only| Type of the primary device.|
| deviceStatus | [P2pDeviceStatus](#P2pDeviceStatus) | Read only| Device status.|
| groupCapabilitys | number | Read only| Group capabilities.|

## P2pDeviceStatus<sup>8+</sup>

Enumerates the device states.

| Name| Default Value| Description|
| -------- | -------- | -------- |
| CONNECTED | 0 | Connected|
| INVITED | 1 | Invited|
| FAILED | 2 | Failed|
| AVAILABLE | 3 | Available|
| UNAVAILABLE | 4 | Unavailable|


## wifi.getP2pPeerDevices<sup>8+</sup>

getP2pPeerDevices(): Promise&lt;WifiP2pDevice[]&gt;

Obtains the list of peer devices in a P2P connection. This method uses a promise to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[WifiP2pDevice[]](#WifiP2pDevice)&gt; | Promise used to return the peer device list obtained.|


## wifi.getP2pPeerDevices<sup>8+</sup>

getP2pPeerDevices(callback: AsyncCallback&lt;WifiP2pDevice[]&gt;): void

Obtains the list of peer devices in a P2P connection. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[WifiP2pDevice[]](#WifiP2pDevice)&gt; | Yes| Callback used to return the peer device list obtained.|


## wifi.createGroup<sup>8+</sup>

createGroup(config: WifiP2PConfig): boolean;

Creates a P2P group.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| Mandatory| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiP2PConfig](#WifiP2PConfig) | Yes| Group configuration.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

## WifiP2PConfig<sup>8+</sup>

Represents P2P configuration.

| Name| Type| Readable/Writable| Description|
| -------- | -------- | -------- | -------- |
| deviceAddress | string | Read only| Device address.|
| netId | number | Read only| Network ID. The value **-1** indicates that a temporary group, and **-2** indicates that a persistent group.|
| passphrase | string | Read only| Private key of the group.|
| groupName | string | Read only| Name of the group.|
| goBand | [GroupOwnerBand](#GroupOwnerBand) | Read only| Bandwidth of the group.|


## GroupOwnerBand<sup>8+</sup>

Enumerates the P2P group bandwidths.

| Name| Default Value| Description|
| -------- | -------- | -------- |
| GO_BAND_AUTO | 0 | Auto|
| GO_BAND_2GHZ | 1 | 2 GHz|
| GO_BAND_5GHZ | 2 | 5 GHz|

## wifi.removeGroup<sup>8+</sup>

removeGroup(): boolean;

Removes a P2P group.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**
  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


## wifi.p2pConnect<sup>8+</sup>

p2pConnect(config: WifiP2PConfig): boolean;

Sets up a P2P connection.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**

  | **Name**| **Type**| Mandatory| **Description**|
  | -------- | -------- | -------- | -------- |
  | config | [WifiP2PConfig](#WifiP2PConfig) | Yes| Connection configuration.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


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
  
  var recvP2pPersistentGroupChangeFunc = result => {
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

p2pCancelConnect(): boolean;

Cancels this P2P connection.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**
  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


## wifi.startDiscoverDevices<sup>8+</sup>

startDiscoverDevices(): boolean;

Starts to discover devices.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**
  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


## wifi.stopDiscoverDevices<sup>8+</sup>

stopDiscoverDevices(): boolean;

Stops discovering devices.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Return value**
  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


## wifi.on('wifiStateChange')<sup>7+</sup>

on(type: "wifiStateChange", callback: Callback&lt;number&gt;): void

Registers the WLAN state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **wifiStateChange**.|
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

Unregisters the WLAN state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **wifiStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback used to return the WLAN state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**
  ```js
  import wifi from '@ohos.wifi';
  
  var WIFI_POWER_STATE = "wifiStateChange";
  var recvPowerNotifyFunc = result => {
      console.info("Receive power state change event: " + result);
  }
  
  // Register event
  wifi.on(WIFI_POWER_STATE, recvPowerNotifyFunc);
  
  // Unregister event
  wifi.off(WIFI_POWER_STATE, recvPowerNotifyFunc);
  ```


## wifi.on('wifiConnectionChange')<sup>7+</sup>

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
| 0 | Disconnected|
| 1 | Connected|


## wifi.off('wifiConnectionChange')<sup>7+</sup>

off(type: "wifiConnectionChange", callback?: Callback&lt;number&gt;): void

Unregisters the WLAN connection state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **wifiConnectionChange**.|
  | callback | Callback&lt;number&gt; | No| Callback used to return the WLAN connection state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|


## wifi.on('wifiScanStateChange')<sup>7+</sup>

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
| 0 | Scan failed|
| 1 | Scan successful|


## wifi.off('wifiScanStateChange')<sup>7+</sup>

off(type: "wifiScanStateChange", callback?: Callback&lt;number&gt;): void

Unregisters the WLAN scan state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **wifiScanStateChange**.|
| callback | Callback&lt;number&gt; | No| Callback used to return the WLAN scan state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|


## wifi.on('wifiRssiChange')<sup>7+</sup>

on(type: "wifiRssiChange", callback: Callback&lt;number&gt;): void

Registers the RSSI change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **wifiRssiChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback invoked to return the RSSI, in dBm.|


## wifi.off('wifiRssiChange')<sup>7+</sup>

off(type: "wifiRssiChange", callback?: Callback&lt;number&gt;): void

Unregisters the RSSI change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.STA

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **wifiRssiChange**.|
  | callback | Callback&lt;number&gt; | No| Callback used to return the RSSI, in dBm. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|


## wifi.on('hotspotStateChange')<sup>7+</sup>

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


## wifi.off('hotspotStateChange')<sup>7+</sup>

off(type: "hotspotStateChange", callback?: Callback&lt;number&gt;): void

Unregisters the hotspot state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.AP.Core

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **hotspotStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback used to return the hotspot state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|


## wifi.on('p2pStateChange')<sup>8+</sup>

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

## wifi.off('p2pStateChange')<sup>8+</sup>

off(type: "p2pStateChange", callback?: Callback&lt;number&gt;): void

Unregisters the P2P state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pStateChange**.|
  | callback | Callback&lt;number&gt; | No| Callback used to return the P2P state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|


  ## wifi.on('p2pConnectionChange')<sup>8+</sup>

on(type: "p2pConnectionChange", callback: Callback&lt;WifiP2pLinkedInfo&gt;): void

Registers the P2P connection state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pConnectionChange**.|
  | callback | Callback&lt;[WifiP2pLinkedInfo](#WifiP2pLinkedInfo)&gt; | Yes| Callback invoked to return the P2P connection state.|


## wifi.off('p2pConnectionChange')<sup>8+</sup>

off(type: "p2pConnectionChange", callback?: Callback&lt;WifiP2pLinkedInfo&gt;): void

Unregisters the P2P connection state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pConnectionChange**.|
  | callback | Callback&lt;[WifiP2pLinkedInfo](#WifiP2pLinkedInfo)&gt; | No| Callback used to return the P2P connection state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|


## wifi.on('p2pDeviceChange')<sup>8+</sup>

on(type: "p2pDeviceChange", callback: Callback&lt;WifiP2pDevice&gt;): void

Registers the P2P device state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice](#WifiP2pDevice)&gt; | Yes| Callback invoked to return the P2P device state.|


## wifi.off('p2pDeviceChange')<sup>8+</sup>

off(type: "p2pDeviceChange", callback?: Callback&lt;WifiP2pDevice&gt;): void

Unregisters the P2P device state change events.

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice](#WifiP2pDevice)&gt; | No| Callback used to return the P2P device state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|


## wifi.on('p2pPeerDeviceChange')<sup>8+</sup>

on(type: "p2pPeerDeviceChange", callback: Callback&lt;WifiP2pDevice[]&gt;): void

Registers the P2P peer device state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pPeerDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice[]](#WifiP2pDevice)&gt; | Yes| Callback invoked to return the P2P peer device state.|


## wifi.off('p2pPeerDeviceChange')<sup>8+</sup>

off(type: "p2pPeerDeviceChange", callback?: Callback&lt;WifiP2pDevice[]&gt;): void

Unregisters the P2P peer device state change events.

**Required permissions**: ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pPeerDeviceChange**.|
  | callback | Callback&lt;[WifiP2pDevice[]](#WifiP2pDevice)&gt; | No| Callback used to return the P2P peer device state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|


## wifi.on('p2pPersistentGroupChange')<sup>8+</sup>

on(type: "p2pPersistentGroupChange", callback: Callback&lt;void&gt;): void

Registers the P2P persistent group state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pPersistentGroupChange**.|
  | callback | Callback&lt;void&gt; | Yes| Callback invoked to return the P2P persistent group state.|


## wifi.off('p2pPersistentGroupChange')<sup>8+</sup>

off(type: "p2pPersistentGroupChange", callback?: Callback&lt;void&gt;): void

Unregisters the P2P persistent group state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pPersistentGroupChange**.|
  | callback | Callback&lt;void&gt; | No| Callback used to return the P2P persistent group state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|


## wifi.on('p2pDiscoveryChange')<sup>8+</sup>

on(type: "p2pDiscoveryChange", callback: Callback&lt;number&gt;): void

Registers the P2P discovered device state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pDiscoveryChange**.|
  | callback | Callback&lt;number&gt; | Yes| Callback invoked to return the state of the P2P discovered device.|

**P2P discovered device states**

| **Value**| **Description**|
| -------- | -------- |
| 0 | Initial state|
| 1 | Discovered|


## wifi.off('p2pDiscoveryChange')<sup>8+</sup>

off(type: "p2pDiscoveryChange", callback?: Callback&lt;number&gt;): void

Unregisters the P2P discovered device state change events.

**Required permissions**: ohos.permission.GET_WIFI_INFO

**System capability**: SystemCapability.Communication.WiFi.P2P

**Parameters**
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is **p2pDiscoveryChange**.|
  | callback | Callback&lt;number&gt; | No| Callback used to return the state of the P2P discovered device. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|
