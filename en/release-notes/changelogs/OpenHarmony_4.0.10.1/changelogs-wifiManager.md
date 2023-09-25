# Wi-Fi Subsystem Changelog

## cl.wifiManager.1 Change of the API Permissions

Involved APIs

| API|Permission Before Change|Permission After Change|
|----|--------|--------|
|**function** getCandidateConfigs(): Array<WifiDeviceConfig>; | The location permission is required.|The location permission is not required.|
|**function** getDeviceConfigs(): Array<WifiDeviceConfig>;| The location permission is required.| The location permission is not required.|
|**function** getStations(): Array<StationInfo>;| 1. The location permission is required. <br>2. The physical MAC address is returned.| 1. The location permission is not required. <br>2. A random MAC address is returned (the GET_PEER_MAC permission is required if a real MAC address is returned).|
| **function** getCurrentP2pGroup(): Promise<WifiP2pGroupInfo>;| The location permission is required.| The location permission is not required.|
| **function** getCurrentP2pGroup(callback: AsyncCallback<WifiP2pGroupInfo>): **void**; | The location permission is required.| The location permission is not required.|
| **function** getP2pPeerDevices(): Promise<WifiP2pDevice[]>;| 1. The location permission is required. <br>2. The physical MAC address is returned.| 1. The location permission is not required. <br>2. A random MAC address is returned (the GET_PEER_MAC permission is required if a real MAC address is returned).|
| **function** getP2pPeerDevices(callback: AsyncCallback<WifiP2pDevice[]>): **void**;| The location permission is required.| 1. The location permission is not required. <br>2. A random MAC address is returned (the GET_PEER_MAC permission is required if a real MAC address is returned).|
| **function** p2pConnect(config: WifiP2PConfig): **void**; | The location permission is required.| The location permission is not required.|
| **function** startDiscoverDevices(): **void**; | The location permission is required.| The location permission is not required.|
| **function** getP2pGroups(): Promise<Array<WifiP2pGroupInfo>>;| The location permission is required.| The location permission is not required.|
| **function** getP2pGroups(callback: AsyncCallback<Array<WifiP2pGroupInfo>>): **void**; | The location permission is required.| The location permission is not required.|
| **function** on(**type**: "p2pDeviceChange", callback: Callback<WifiP2pDevice>): **void**;| 1. The location permission is required. <br>2. The physical MAC address is returned.| 1. The location permission is not required. <br>2. A random MAC address is returned (the GET_PEER_MAC permission is required if a real MAC address is returned).|
| **function** off(**type**: "p2pDeviceChange", callback?: Callback<WifiP2pDevice>): **void**; | 1. The location permission is required. <br>2. The physical MAC address is returned.| 1. The location permission is not required. <br>2. A random MAC address is returned (the GET_PEER_MAC permission is required if a real MAC address is returned).|
| **function** on(**type**: "p2pPeerDeviceChange", callback: Callback<WifiP2pDevice[]>): **void**; | 1. The location permission is required. <br>2. The physical MAC address is returned.| 1. The location permission is not required. <br>2. A random MAC address is returned (the GET_PEER_MAC permission is required if a real MAC address is returned).|
| **function** off(**type**: "p2pPeerDeviceChange", callback?: Callback<WifiP2pDevice[]>): **void**;| 1. The location permission is required. <br>2. The physical MAC address is returned.| 1. The location permission is not required. <br>2. A random MAC address is returned (the GET_PEER_MAC permission is required if a real MAC address is returned).|

**Change Impact**
If your application is developed using the involved APIs of earlier versions, apply for the required permissions for the new APIs.

**Key API/Component Changes**
NA

**Adaptation Guide**
Apply for the required permissions for the involved APIs.


## cl.wifiManager.2 Change of the APIs Related to Wi-Fi Scan Capabilities

Deprecated **scan()**, **getScanResults()**, and **getScanResultsSync()**, and added new APIs to provide the related capabilities.

**Change Impact**
The following APIs are deprecated since API 10, without affecting the compatibility of developed applications. However, you are advised to use new APIs.

**Key API/Component Changes**
|Deprecated API|New API|Description|
| ------------- |-------------------------------------------------------- |-----------------------|
| **function** scan(): **void**; |**function** startScan(): **void**;| Use **startScan** to start Wi-Fi scan.|
| **function** getScanResults(): Promise<Array<WifiScanInfo>>;|**function** getScanInfoList(): Array<WifiScanInfo>;| Use **getScanInfoList** to obtain the scan result.|
| **function** getScanResults(callback: AsyncCallback<Array<WifiScanInfo>>): **void**;|**function** getScanInfoList(): Array<WifiScanInfo>; | Use **getScanInfoList** to obtain the scan result.|
| **function** getScanResultsSync(): Array<WifiScanInfo>; |**function** getScanInfoList(): Array<WifiScanInfo>; | Use **getScanInfoList** to obtain the scan result.|


**Adaptation Guide**
Use the new APIs.
