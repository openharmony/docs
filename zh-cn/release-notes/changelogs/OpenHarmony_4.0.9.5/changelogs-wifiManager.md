# wifi子系统ChangeLog

### 1 新增接口声明
| 接口声明 | 接口描述 |
|------|---------|
| **function** getScanResults(): Array<WifiScanInfo>;         | 获取扫描列表，异步接口         |
| **function** getScanResultsSync(): Array<WifiScanInfo>;         | 获取扫描列表，同步接口         |
| **function** updateNetwork(config: WifiDeviceConfig): number; | 更新已经添加的热点配置信息     |
| **function** disableNetwork(netId: number): **void**;                | 去使能已经添加的热点配置     |
| **function** removeAllNetwork(): **void**;                | 删除所有的热点配置     |
| **function** removeDevice(id: number): **void**;                | 删除单个热点配置     |
| **function** getStations(): Array<StationInfo>;                        | 获取接入本热点的设备信息     |
| **function** createGroup(config: WifiP2PConfig): **void**;                | 创建P2P群组     |
| **function** removeGroup(): **void**;                | 删除P2P群组     |
| **function** startDiscoverDevices(): **void**;                | 启动P2P扫描     |
| **function** stopDiscoverDevices(): **void**;                | 停止P2P扫描     |
| **function** deletePersistentGroup(netId: number): **void**;                | 删除P2P永久组     |
| **function** setDeviceName(devName: string): **void**;                | 设置P2P设备名称     |

### 2 废弃接口


| 接口声明  |废弃说明                                                 |
| ------------- |-------------------------------------------------------- |
| **function** getScanInfoList(): Array<WifiScanInfo>;         | 获取扫描列表，同步接口         |
| **function** updateDeviceConfig(config: WifiDeviceConfig): number; | 更新已经添加的热点配置信息     |
| **function** disableDeviceConfig(networkId: number): **void**;                | 去使能已经添加的热点配置     |
| **function** removeAllDeviceConfigs(): **void**;                | 删除所有的热点配置     |
| **function** removeDeviceConfig(networkId: number): **void**;                | 删除单个热点配置     |
| **function** getHotspotStations(): Array<StationInfo>;                        | 获取接入本热点的设备信息     |
| **function** createP2pGroup(config: WifiP2PConfig): **void**;                | 创建P2P群组     |
| **function** removeP2pGroup(): **void**;                | 删除P2P群组     |
| **function** startDiscoverP2pDevices(): **void**;                | 启动P2P扫描     |
| **function** stopDiscoverP2pDevices(): **void**;                | 停止P2P扫描     |
| **function** deletePersistentP2pGroup(netId: number): **void**;                | 删除P2P永久组     |
| **function** setP2pDeviceName(devName: string): **void**;                | 设置P2P设备名称     |

### 3 变更接口声明
| 接口声明 | 接口描述 |
|------|---------|
| **function** setHotspotConfig(config: HotspotConfig): **void**;         | 设置热点配置，channel & ipAddress改为可选字段         |