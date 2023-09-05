# wifi子系统ChangeLog

## cl.wifiManager.1 接口权限变更，修改为文件内对应的接口权限变更。

1- 涉及接口

| 接口声明 |变更前权限 |变更后权限 |
|----|--------|--------|
|**function** getCandidateConfigs(): Array<WifiDeviceConfig>; | 1.需要位置权限 |1.取消位置权限 |
|**function** getDeviceConfigs(): Array<WifiDeviceConfig>;| 1.需要位置权限 | 1.取消位置权限 |
|**function** getStations(): Array<StationInfo>;| 1.需要位置权限 2.返回物理MAC | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** getCurrentP2pGroup(): Promise<WifiP2pGroupInfo>;| 1.需要位置权限 | 1.取消位置权限 |
| **function** getCurrentP2pGroup(callback: AsyncCallback<WifiP2pGroupInfo>): **void**; | 1.需要位置权限| 1.取消位置权限 |
| **function** getP2pPeerDevices(): Promise<WifiP2pDevice[]>;| 1.需要位置权限 2.返回物理MAC | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** getP2pPeerDevices(callback: AsyncCallback<WifiP2pDevice[]>): **void**;| 1.需要位置权限 | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** p2pConnect(config: WifiP2PConfig): **void**; | 1.需要位置权限| 1.取消位置权限 |
| **function** startDiscoverDevices(): **void**; | 1.需要位置权限| 1.取消位置权限 |
| **function** getP2pGroups(): Promise<Array<WifiP2pGroupInfo>>;| 1.需要位置权限 | 1.取消位置权限 |
| **function** getP2pGroups(callback: AsyncCallback<Array<WifiP2pGroupInfo>>): **void**; | 1.需要位置权限| 1.取消位置权限 |
| **function** on(**type**: "p2pDeviceChange", callback: Callback<WifiP2pDevice>): **void**;| 1.需要位置权限 2.返回物理MAC | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** off(**type**: "p2pDeviceChange", callback?: Callback<WifiP2pDevice>): **void**; | 1.需要位置权限 2.返回物理MAC| 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** on(**type**: "p2pPeerDeviceChange", callback: Callback<WifiP2pDevice[]>): **void**; | 1.需要位置权限 2.返回物理MAC | 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |
| **function** off(**type**: "p2pPeerDeviceChange", callback?: Callback<WifiP2pDevice[]>): **void**;| 1.需要位置权限 2.返回物理MAC| 1.取消位置权限;2.返回随机MAC(GET_PEER_MAC权限返回真实MAC) |

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了上述接口的，需要改为使用变更后的权限。

**关键的接口/组件变更**<br>
无

**适配指导**<br>
权限重新适配


## cl.wifiManager.2 修改接口**function** scan(): **void** 为 **function** startScan(): **void**;

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了上述的scan，需要改为使用startScan接口。

**关键的接口/组件变更**<br>
无

**适配指导**<br>
由scan需要改为使用startScan接口。


## cl.wifiManager.3 修改接口getScanResults(): Promise<Array<WifiScanInfo>> 为 **function** getScanInfoList(): Array<WifiScanInfo>;
	
**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了上述的getScanResults，需要改为使用getScanInfoList接口。

**关键的接口/组件变更**<br>
无

**适配指导**<br>
由getScanResults需要改为使用getScanInfoList接口。


## cl.wifiManager.4 修改接口function** getScanResults(callback: AsyncCallback<Array<WifiScanInfo>>): **void**; 为 **function** getScanInfoList(): Array<WifiScanInfo>;
	
**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了上述的getScanResults，需要改为使用getScanInfoList接口。

**关键的接口/组件变更**<br>
无

**适配指导**<br>
由getScanResults需要改为使用getScanInfoList接口。


## cl.wifiManager.5 修改接口**function** getScanResultsSync(): Array<WifiScanInfo>; 为 **function** getScanInfoList(): Array<WifiScanInfo>;

**变更影响**<br>
使用之前已发布的API 9各beta版本且使用到了上述的getScanResultsSync，需要改为使用getScanInfoList接口。

**关键的接口/组件变更**<br>
无

**适配指导**<br>
由getScanResultsSync需要改为使用getScanInfoList接口。


## cl.wifiManager.6 新增接口声明

| 接口声明 | 接口描述 |
|------|---------|
| **function** setScanAlwaysAllowed(isScanAlwaysAllowed: boolean): **void**; | 设置后台扫描开关     |
| **function** getScanAlwaysAllowed(): boolean;                | 获取后台扫描开关     |
| **function** getIpv6Info(): Ipv6Info;                        | 获取ipv6地址信息     |
| **function** isBandTypeSupported(bandType: WifiBandType): boolean; | 判断是否支持BandType |
| **function** get5GChannelList(): Array<**number**>;          | 获取5G信道列表       |
| **function** getDisconnectedReason(): DisconnectedReason;    | 获取网络断开原因     |

**变更影响**<br>
使用之前已发布的API 无影响。

**关键的接口/组件变更**<br>
无

**适配指导**<br>
无需适配