# Wi-Fi Subsystem ChangeLog


## cl.wifi.1 Migration of System APIs and APIs in API Version 9 to the New @ohos.wifiManager.d.ts
**@ohos.wifi.d.ts** does not allow for throwing error codes, which is required by API version 9 and the system APIs. Therefore, all system APIs and APIs in API version 9 of **@ohos.wifi.d.ts** are migrated to the newly added **@ohos.wifiManager.d.ts**, and error code description is also added.

Import **@ohos.wifiManager.d.ts**, so that system APIs and APIs in API version 9 of the Wi-Fi subsystem can be used.

import wifiManager from '@ohos.wifiManager';


**Change Impacts**

System APIs and APIs in API version 9 are affected. Import **@ohos.wifiManager** to make sure that system APIs and APIs in API version 9 of the Wi-Fi subsystem can be used.

import wifiManager from '@ohos.wifiManager';

Other APIs are not affected.


**Key API/Component Changes**

| Class| Type | Declaration                                                    | Change Type                                                    |
| ---- | --------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| wifi | namespace | declare namespace wifi                                       | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function enableWifi(): void                                  | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value type to void.  |
| wifi | method    | function disableWifi(): void                                 | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value type to void.  |
| wifi | method    | function scan(): void                                        | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value type to void.  |
| wifi | method    | function getScanResults(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt; | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed **getScanInfos** to **getScanResults**.|
| wifi | method    | function getScanResults(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed **getScanInfos** to **getScanResults**.|
| wifi | method    | function getScanResultsSync(): &nbsp;Array&lt;[WifiScanInfo]&gt; | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function addCandidateConfig(config: WifiDeviceConfig): Promise&lt;number&gt; | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function removeCandidateConfig(networkId: number): Promise&lt;void&gt; | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function removeCandidateConfig(networkId: number, callback: AsyncCallback&lt;void&gt;): void | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function addUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt; | Deleted this API in API version 9.                                    |
| wifi | method    | function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void | Deleted this API in API version 9.                                    |
| wifi | method    | function removeUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt; | Deleted this API in API version 9.                                    |
| wifi | method    | function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void | Deleted this API in API version 9.                                    |
| wifi | method    | function getCandidateConfigs(): &nbsp;Array&lt;[WifiDeviceConfig]&gt; | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function connectToCandidateConfig(networkId: number): void   | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function connectToNetwork(networkId: number): void           | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function connectToDevice(config: WifiDeviceConfig): void     | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function disconnect(): void                                  | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function reassociate(): void                                 | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function reconnect(): void                                   | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function disableNetwork(netId: number): void                 | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function removeAllNetwork(): void                            | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function removeDevice(id: number): void                      | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function enableHotspot(): void                               | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function disableHotspot(): void                              | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function setHotspotConfig(config: HotspotConfig): void       | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function getP2pLocalDevice(): Promise&lt;WifiP2pDevice&gt;   | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function getP2pLocalDevice(callback: AsyncCallback&lt;WifiP2pDevice&gt;): void | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function getP2pGroups(): Promise&lt;Array&lt;WifiP2pGroupInfo&gt;&gt; | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function getP2pGroups(callback: AsyncCallback&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;): void | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | method    | function createGroup(config: WifiP2PConfig): void            | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function removeGroup(): void                                 | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function p2pConnect(config: WifiP2PConfig): void             | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function p2pCancelConnect(): void                            | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function startDiscoverDevices(): void                        | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function stopDiscoverDevices(): void                         | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function deletePersistentGroup(netId: number): void          | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | method    | function setDeviceName(devName: string): void                | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and changed the return value to **void**.|
| wifi | interface | export interface WifiEapConfig                               | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | enum      | export enum EapMethod                                        | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | enum      | export enum Phase2Method                                     | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | interface | export interface WifiDeviceConfig                            | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and added the **eapConfig** parameter.|
| wifi | interface | export interface IpConfig                                    | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and added the **prefixLength** parameter.|
| wifi | interface | export interface WifiInfoElem                                | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | enum      | export enum WifiChannelWidth                                 | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**.                  |
| wifi | interface | export interface WifiScanInfo                                | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and added the following three parameters: **centerFrequency0**, **centerFrequency1**, and **infoElems**.|
| wifi | enum      | export enum WifiSecurityType                                 | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and added four encryption types. |
| wifi | interface | export interface WifiLinkedInfo                              | Migrated this API in API version 9 to **@ohos.wifiManager.d.ts**, and added the **MacType** parameter. |


**(Optional) Adaptation Guide**

The following uses **getLinkedInfo** as an example to show how it is called in the new version:

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

## cl.wifiext.1 Migration of System APIs and APIs in API Version 9 to the New @ohos.wifiManagerExt.d.ts

**@ohos.wifiext.d.ts** does not allow for throwing error codes, which is required by API version 9 and the system API. Therefore, all system APIs and APIs in API version 9 of **@ohos.wifiext.d.ts** are migrated to the newly added **@ohos.wifiManagerExt.d.ts**, and error code description is also added.

Import **@ohos.wifiManagerExt.d.ts**, so that system APIs and APIs in API version 9 of the Wi-Fi subsystem can be used.

import wifiManagerExt from '@ohos.wifiManagerExt';


**Change Impacts**

System APIs and APIs in API version 9 are affected. Import **@ohos.wifiManagerExt**, so that system APIs and APIs in API version 9 of the Wi-Fi subsystem can be used together with the Wi-Fi manager.

import wifiManagerExt from '@ohos.wifiManagerExt';

Other APIs are not affected.
