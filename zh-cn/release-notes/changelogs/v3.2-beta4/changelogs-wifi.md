# 基础通信WIFI子系统ChangeLog


## cl.wifi.1 系统API和API9接口迁移到新增的@ohos.wifiManager.d.ts
@ohos.wifi.d.ts接口不支持抛出错误码，而API9以及SystemAPI都需要支持错误码抛出，为支持该功能，将@ohos.wifi.d.ts中的所有SystemAPI以及API9接口迁移到新增的@ohos.wifiManager.d.ts当中，并添加错误码描述。

后续需要import @ohos.wifiManager.d.ts才能够使用wifi的系统API以及API9接口：

import wifiManager from '@ohos.wifiManager';


**变更影响**

仅对系统API以及API9所有接口的使用有影响，需要import @ohos.wifiManager才能使用wifi的系统API和API9接口

import wifiManager from '@ohos.wifiManager';

对于其他接口无影响


**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 |
| -- | -- | -- | -- |
| wifi | namespace | declare namespace wifi | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function enableWifi(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值改为void |
| wifi | method | function disableWifi(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值改为void |
| wifi | method | function scan(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值改为void |
| wifi | method | function getScanResults(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt; | API9接口变更，迁移到@ohos.wifiManager.d.ts，由getScanInfos修改为getScanResults |
| wifi | method | function getScanResults(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，由getScanInfos修改为getScanResults |
| wifi | method | function getScanResultsSync(): &nbsp;Array&lt;[WifiScanInfo]&gt; | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function addCandidateConfig(config: WifiDeviceConfig): Promise&lt;number&gt; | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;number&gt;): void | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function removeCandidateConfig(networkId: number): Promise&lt;void&gt; | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function removeCandidateConfig(networkId: number, callback: AsyncCallback&lt;void&gt;): void | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function addUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt; | API9接口变更，该接口删除 |
| wifi | method | function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void | API9接口变更，该接口删除 |
| wifi | method | function removeUntrustedConfig(config: WifiDeviceConfig): Promise&lt;boolean&gt; | API9接口变更，该接口删除 |
| wifi | method | function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback&lt;boolean&gt;): void | API9接口变更，该接口删除 |
| wifi | method | function getCandidateConfigs(): &nbsp;Array&lt;[WifiDeviceConfig]&gt; | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function connectToCandidateConfig(networkId: number): void | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function connectToNetwork(networkId: number): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function connectToDevice(config: WifiDeviceConfig): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function disconnect(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function reassociate(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function reconnect(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function disableNetwork(netId: number): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function removeAllNetwork(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function removeDevice(id: number): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function enableHotspot(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function disableHotspot(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function setHotspotConfig(config: HotspotConfig): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function getP2pLocalDevice(): Promise&lt;WifiP2pDevice&gt; | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function getP2pLocalDevice(callback: AsyncCallback&lt;WifiP2pDevice&gt;): void | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function getP2pGroups(): Promise&lt;Array&lt;WifiP2pGroupInfo&gt;&gt; | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function getP2pGroups(callback: AsyncCallback&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;): void | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | method | function createGroup(config: WifiP2PConfig): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function removeGroup(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function p2pConnect(config: WifiP2PConfig): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function p2pCancelConnect(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function startDiscoverDevices(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function stopDiscoverDevices(): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function deletePersistentGroup(netId: number): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | method | function setDeviceName(devName: string): void | API9接口变更，迁移到@ohos.wifiManager.d.ts，返回值修改为void |
| wifi | interface | export interface WifiEapConfig | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | enum | export enum EapMethod | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | enum | export enum Phase2Method | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | interface | export interface WifiDeviceConfig | API9接口变更，迁移到@ohos.wifiManager.d.ts，增加eapConfig参数 |
| wifi | interface | export interface IpConfig | API9接口变更，迁移到@ohos.wifiManager.d.ts，增加prefixLength参数 |
| wifi | interface | export interface WifiInfoElem | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | enum | export enum WifiChannelWidth | API9接口变更，迁移到@ohos.wifiManager.d.ts |
| wifi | interface | export interface WifiScanInfo | API9接口变更，迁移到@ohos.wifiManager.d.ts，增加centerFrequency0、centerFrequency1、infoElems三个参数 |
| wifi | enum | export enum WifiSecurityType | API9接口变更，迁移到@ohos.wifiManager.d.ts，增加4种加密类型 |
| wifi | interface | export interface WifiLinkedInfo | API9接口变更，迁移到@ohos.wifiManager.d.ts，增加MacType参数 |


**适配指导（可选，不涉及则可以删除）**

以getLinkedInfo为例，在新版本中需要使用如下方式进行调用：

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

## cl.wifiext.1 系统API和API9接口迁移到新增的@ohos.wifiManagerExt.d.ts

@ohos.wifiext.d.ts接口不支持抛出错误码，而API9以及SystemAPI都需要支持错误码抛出，为支持该功能，将@ohos.wifiext.d.ts中的所有SystemAPI以及API9接口迁移到新增的@ohos.wifiManagerExt.d.ts当中，并添加错误码描述

后续需要import @ohos.wifiManagerExt.d.ts才能够使用wifi的系统API以及API9接口：

import wifiManagerExt from '@ohos.wifiManagerExt';


**变更影响**

仅对系统API以及API9所有接口的使用有影响，需要import @ohos.wifiManagerExt才能使用wifi的系统API和API9接口，与wifiManager配套使用

import wifiManagerExt from '@ohos.wifiManagerExt';

对于其他接口无影响
