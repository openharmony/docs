# Communication Subsystem - WiFi Changelog


## cl.wifi.1 Moving System APIs and APIs of Version 9 to @ohos.wifiManager.d.ts
Moved all system APIs and APIs of version 9 from **@ohos.wifi.d.ts** to the newly added **@ohos.wifiManager.d.ts**, and added error code descriptions. The **@ohos.wifi.d.ts** APIs do not support error code handling.

To use these APIs, import the **@ohos.wifiManager.d.ts** module as follows:

import wifiManager from '@ohos.wifiManager';


**Change Impact**

System APIs and APIs of version 9 are affected. To use these APIs, import **@ohos.wifiManager** as follows:

import wifiManager from '@ohos.wifiManager';

Other APIs are not affected.


**Key API/Component Changes**

| Class| API Type| Declaration| Change Type|
| -- | -- | -- | -- |
| wifi | namespace | declare namespace wifi | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function enableWifi(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function disableWifi(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function scan(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function getScanResults(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt; | Changed from **getScanInfos** to **getScanResults** and moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function getScanResults(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void | Changed from **getScanInfos** to **getScanResults** and moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function getScanResultsSync(): &nbsp;Array&lt;[WifiScanInfo]&gt; | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function addCandidateConfig(config: WifiDeviceConfig): Promise&lt;number&gt; | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function removeCandidateConfig(networkId: number): Promise&lt;void&gt; | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function removeCandidateConfig(networkId: number, callback: AsyncCallback&lt;void&gt;): void | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function addUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt; | Deleted this API in API version 9.|
| wifi | method | function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void | Deleted|
| wifi | method | function removeUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt; | Deleted|
| wifi | method | function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void | Deleted|
| wifi | method | function getCandidateConfigs(): &nbsp;Array&lt;[WifiDeviceConfig]&gt; | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function connectToCandidateConfig(networkId: number): void | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function connectToNetwork(networkId: number): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function connectToDevice(config: WifiDeviceConfig): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function disconnect(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function reassociate(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function reconnect(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function disableNetwork(netId: number): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function removeAllNetwork(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function removeDevice(id: number): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function enableHotspot(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function disableHotspot(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function setHotspotConfig(config: HotspotConfig): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function getP2pLocalDevice(): Promise&lt;WifiP2pDevice&gt; | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function getP2pLocalDevice(callback: AsyncCallback&lt;WifiP2pDevice&gt;): void | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function getP2pGroups(): Promise&lt;Array&lt;WifiP2pGroupInfo&gt;&gt; | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function getP2pGroups(callback: AsyncCallback&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;): void | Moved to **@ohos.wifiManager.d.ts**|
| wifi | method | function createGroup(config: WifiP2PConfig): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function removeGroup(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function p2pConnect(config: WifiP2PConfig): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function p2pCancelConnect(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function startDiscoverDevices(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function stopDiscoverDevices(): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function deletePersistentGroup(netId: number): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | method | function setDeviceName(devName: string): void | Moved to **@ohos.wifiManager.d.ts**, with the return value changed to **void**|
| wifi | interface | export interface WifiEapConfig | Moved to **@ohos.wifiManager.d.ts**|
| wifi | enum | export enum EapMethod | Moved to **@ohos.wifiManager.d.ts**|
| wifi | enum | export enum Phase2Method | Moved to **@ohos.wifiManager.d.ts**|
| wifi | interface | export interface WifiDeviceConfig | Added with the **eapConfig** parameter and moved to **@ohos.wifiManager.d.ts**|
| wifi | interface | export interface IpConfig | Added with the **prefixLength** parameter and moved to **@ohos.wifiManager.d.ts**|
| wifi | interface | export interface WifiInfoElem | Moved to **@ohos.wifiManager.d.ts**|
| wifi | enum | export enum WifiChannelWidth | Moved to **@ohos.wifiManager.d.ts**|
| wifi | interface | export interface WifiScanInfo | Added with the **centerFrequency0**, **centerFrequency1**, and **infoElems** parameters and moved to **@ohos.wifiManager.d.ts**|
| wifi | enum | export enum WifiSecurityType | Added with four encryption types and moved to **@ohos.wifiManager.d.ts**|
| wifi | interface | export interface WifiLinkedInfo | Added with the **MacType** parameter and moved to **@ohos.wifiManager.d.ts**|


**(Optional) Adaptation Guide**

The following uses **getLinkedInfo** as an example:

```
import wifiManager from '@ohos.wifiManager'

wifiManager.getLinkedInfo((err, data) => {
    if (err) {
        console.error("get linked info error");
        return;
    }
    console.info("get linked info: " + JSON.stringify(data));
});

wifiManager.getLinkedInfo().then(data => {
    console.info("get linked info: " + JSON.stringify(data));
}).catch(error => {
    console.info("get linked info error");
});

```

## cl.wifiext.1 Change of System APIs and APIs of Version 9

Moved all system APIs and APIs of version 9 from **@ohos.wifiext.d.ts** to the newly added **@ohos.wifiManagerExt.d.ts**, and added error code descriptions.

To use these APIs, import the **@ohos.wifiManagerExt.d.ts** module as follows:

import wifiManagerExt from '@ohos.wifiManagerExt';


**Change Impact**

System APIs and APIs of version 9 are affected. Import **@ohos.wifiManagerExt** and use it together with **wifiManager**.

import wifiManagerExt from '@ohos.wifiManagerExt';

Other APIs are not affected.
