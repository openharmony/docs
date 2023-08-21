# Wi-Fi Subsystem Changelog

## 1 Permission Change

1. The location permission is not required if a random MAC is returned.
1. The GET_WIFI_PEERS_MAC permission is required if a real MAC address is returned.

| API| Permission|
| -------- | ---------------------------- |
|**function** getCandidateConfigs(): Array<WifiDeviceConfig>; | 1. The location permission is not required.|
|**function** getDeviceConfigs(): Array<WifiDeviceConfig>; | 1. The location permission is not required.|
|**function** getStations(): Array<StationInfo>; | 1. The location permission is not required. <br/>2. A random MAC address is returned (the GET_WIFI_PEERS_MAC permission is required if a real MAC address is returned). |
| **function** getCurrentP2pGroup(): Promise<WifiP2pGroupInfo>; | 1. The location permission is not required.|
| **function** getCurrentP2pGroup(callback: AsyncCallback<WifiP2pGroupInfo>): **void**; | 1. The location permission is not required.|
| **function** getP2pPeerDevices(): Promise<WifiP2pDevice[]>; | 1. The location permission is not required. <br/>2. A random MAC address is returned (the GET_WIFI_PEERS_MAC permission is required if a real MAC address is returned). |
| **function** getP2pPeerDevices(callback: AsyncCallback<WifiP2pDevice[]>): **void**; | 1. The location permission is not required. <br/>2. A random MAC address is returned (the GET_WIFI_PEERS_MAC permission is required if a real MAC address is returned). |
| **function** p2pConnect(config: WifiP2PConfig): **void**; | 1. The location permission is not required.|
| **function** startDiscoverDevices(): **void**; | 1. The location permission is not required.|
| **function** getP2pGroups(): Promise<Array<WifiP2pGroupInfo>>; | 1. The location permission is not required.|
| **function** getP2pGroups(callback: AsyncCallback<Array<WifiP2pGroupInfo>>): **void**; | 1. The location permission is not required.|
| **function** on(**type**: "p2pDeviceChange", callback: Callback<WifiP2pDevice>): **void**; | 1. The location permission is not required. <br/>2. A random MAC address is returned (the GET_WIFI_PEERS_MAC permission is required if a real MAC address is returned). |
| **function** off(**type**: "p2pDeviceChange", callback?: Callback<WifiP2pDevice>): **void**; | 1. The location permission is not required. <br/>2. A random MAC address is returned (the GET_WIFI_PEERS_MAC permission is required if a real MAC address is returned). |
| **function** on(**type**: "p2pPeerDeviceChange", callback: Callback<WifiP2pDevice[]>): **void**; | 1. The location permission is not required. <br/>2. A random MAC address is returned (the GET_WIFI_PEERS_MAC permission is required if a real MAC address is returned). |
| **function** off(**type**: "p2pPeerDeviceChange", callback?: Callback<WifiP2pDevice[]>): **void**; | 1. The location permission is not required. <br/>2. A random MAC address is returned (the GET_WIFI_PEERS_MAC permission is required if a real MAC address is returned). |


## 2 Added APIs
| API| Description|
|------|---------|
| **function** startScan(): **void**; | Starts a scan.|
| **function** getScanInfoList(): Array<WifiScanInfo>;         | Obtains the scan list.        |
| **function** setScanAlwaysAllowed(isScanAlwaysAllowed: boolean): **void**; | Sets whether to always allow Wi-Fi scanning.    |
| **function** getScanAlwaysAllowed(): boolean;                | Obtains the Wi-Fi scan settings on the background.    |
| **function** getIpv6Info(): Ipv6Info;                        | Obtains IPv6 address information.    |
| **function** isBandTypeSupported(bandType: WifiBandType): boolean; | Checks whether BandType is supported.|
| **function** get5GChannelList(): Array<**number**>;          | Obtains the 5G channel list.      |
| **function** getDisconnectedReason(): DisconnectedReason;    | Obtains the reason for network disconnection.    |

## 3 Deprecated APIs


| API |Description                                                |
| ------------- |-------------------------------------------------------- |
| **function** scan(): **void**; | Use **startScan** instead.|
| **function** getScanResults(): Promise<Array<WifiScanInfo>>; | Use **getScanInfoList** instead.|
| **function** getScanResults(callback: AsyncCallback<Array<WifiScanInfo>>): **void**; | Use **getScanInfoList** instead.|
| **function** getScanResultsSync(): Array<WifiScanInfo>;      | Use **getScanInfoList** instead.|
