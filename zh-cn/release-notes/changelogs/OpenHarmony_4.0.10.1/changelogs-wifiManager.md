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
使用之前已发布的API版本且使用到了上述接口的，需要改为使用变更后的权限。

**关键的接口/组件变更**<br>
无

**适配指导**<br>
权限重新适配


## cl.wifiManager.2 扫描wifi能力的接口废弃与新增
  
因为优化扫描接口scan(),getScanResults(),getScanResultsSync(),对原接口废弃,推荐使用新的接口进行应用开发.

**变更影响**<br>
如下接口从API 10开始废弃，废弃不影响已开发应用的兼容性，但建议改为使用新的替代接口。

**关键的接口/组件变更**<br>
|废弃接口 |对应新增接口 |功能说明|
| ------------- |-------------------------------------------------------- |-----------------------|
| **function** scan(): **void**; |**function** startScan(): **void**;| 使用startScan接口启动扫描 |
| **function** getScanResults(): Promise<Array<WifiScanInfo>>;|**function** getScanInfoList(): Array<WifiScanInfo>;| 使用getScanInfoList获取扫描列表 |
| **function** getScanResults(callback: AsyncCallback<Array<WifiScanInfo>>): **void**;|**function** getScanInfoList(): Array<WifiScanInfo>; | 使用getScanInfoList获取扫描列表 |
| **function** getScanResultsSync(): Array<WifiScanInfo>; |**function** getScanInfoList(): Array<WifiScanInfo>; | 使用getScanInfoList获取扫描列表 |


**适配指导**<br>
应用中使用废弃接口的，建议升级API 10以后修改为对应的新增接口。







