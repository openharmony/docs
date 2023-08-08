# wifi子系统ChangeLog

## 1 权限变更。

1. 接口新增返回随机mac，取消位置权限。
1. 返回真实mac需要GET_PEER_MAC权限。

| 接口声明 | 权限变更说明 |
| -------- | ---------------------------- |
|**function** getCandidateConfigs(): Array<WifiDeviceConfig>; | 1.取消位置权限 |
|**function** getDeviceConfigs(): Array<WifiDeviceConfig>; | 1.取消位置权限 |
|**function** getStations(): Array<StationInfo>; | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** getCurrentP2pGroup(): Promise<WifiP2pGroupInfo>; | 1.取消位置权限 |
| **function** getCurrentP2pGroup(callback: AsyncCallback<WifiP2pGroupInfo>): **void**; | 1.取消位置权限 |
| **function** getP2pPeerDevices(): Promise<WifiP2pDevice[]>; | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** getP2pPeerDevices(callback: AsyncCallback<WifiP2pDevice[]>): **void**; | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** p2pConnect(config: WifiP2PConfig): **void**; | 1.取消位置权限 |
| **function** startDiscoverDevices(): **void**; | 1.取消位置权限 |
| **function** getP2pGroups(): Promise<Array<WifiP2pGroupInfo>>; | 1.取消位置权限 |
| **function** getP2pGroups(callback: AsyncCallback<Array<WifiP2pGroupInfo>>): **void**; | 1.取消位置权限 |
| **function** on(**type**: "p2pDeviceChange", callback: Callback<WifiP2pDevice>): **void**; | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** off(**type**: "p2pDeviceChange", callback?: Callback<WifiP2pDevice>): **void**; | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** on(**type**: "p2pPeerDeviceChange", callback: Callback<WifiP2pDevice[]>): **void**; | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** off(**type**: "p2pPeerDeviceChange", callback?: Callback<WifiP2pDevice[]>): **void**; | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |


### 2 新增接口声明
| 接口声明 | 接口描述 |
|------|---------|
| **function** startScan(): **void**; | 启动扫描 |
| **function** getScanInfoList(): Array<WifiScanInfo>;         | 获取扫描列表         |
| **function** setScanAlwaysAllowed(isScanAlwaysAllowed: boolean): **void**; | 设置后台扫描开关     |
| **function** getScanAlwaysAllowed(): boolean;                | 获取后台扫描开关     |
| **function** getIpv6Info(): Ipv6Info;                        | 获取ipv6地址信息     |
| **function** isBandTypeSupported(bandType: WifiBandType): boolean; | 判断是否支持BandType |
| **function** get5GChannelList(): Array<**number**>;          | 获取5G信道列表       |
| **function** getDisconnectedReason(): DisconnectedReason;    | 获取网络断开原因     |

### 3 废弃接口


| 接口声明  |废弃说明                                                 |
| ------------- |-------------------------------------------------------- |
| **function** scan(): **void**; | 使用startScan接口启动扫描 |
| **function** getScanResults(): Promise<Array<WifiScanInfo>>; | 使用getScanInfoList获取扫描列表 |
| **function** getScanResults(callback: AsyncCallback<Array<WifiScanInfo>>): **void**; | 使用getScanInfoList获取扫描列表 |
| **function** getScanResultsSync(): Array<WifiScanInfo>;      | 使用getScanInfoList获取扫描列表 |
