# 基础通信子系统WiFi ChangeLog

## cl.location.1 位置服务权限变更

从API9开始，增加ohos.permission.APPROXIMATELY_LOCATION，表示模糊位置权限。

如果应用开发者使用的API版本大于等于9，则需要同时申请ohos.permission.LOCATION和ohos.permission.APPROXIMATELY_LOCATION，单独申请ohos.permission.LOCATION会失败。

**变更影响**

如果是存量应用（使用的API版本小于9），则无影响。如果使用的API版本大于等于9，位置服务权限申请方式有变更，详情如下：

应用在使用系统能力前，需要检查是否已经获取用户授权访问设备位置信息。如未获得授权，可以向用户申请需要的位置权限，申请方式请参考下文。

系统提供的定位权限有：

- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

- ohos.permission.LOCATION_IN_BACKGROUND

访问设备的位置信息，必须申请权限，并且获得用户授权。

API9之前的版本，申请ohos.permission.LOCATION即可。

API9及之后的版本，需要申请ohos.permission.APPROXIMATELY_LOCATION或者同时申请ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION；无法单独申请ohos.permission.LOCATION。

| 使用的API版本 | 申请位置权限 | 申请结果 | 位置的精确度 |
| -------- | -------- | -------- | -------- |
| 小于9 | ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |
| 大于等于9 | ohos.permission.LOCATION | 失败 | 无法获取位置。 |
| 大于等于9 | ohos.permission.APPROXIMATELY_LOCATION | 成功 | 获取到模糊位置，精确度为5公里。 |
| 大于等于9 | ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |

如果应用在后台运行时也需要访问设备位置，除需要将应用声明为允许后台运行外，还必须申请ohos.permission.LOCATION_IN_BACKGROUND权限，这样应用在切入后台之后，系统可以继续上报位置信息。

开发者可以在应用配置文件中声明所需要的权限，具体可参考[授权申请指导](../../../application-dev/security/accesstoken-guidelines.md)。

**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 | 
|  -- | -- | -- | -- |
|wifiManager| method | function scan(): void; | 权限变更为ohos.permission.SET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function getScanResults(): Promise&lt;Array&lt;WifiScanInfo&gt;&gt;; | 权限变更为ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION)) | 
|wifiManager| method | function getScanResults(callback: AsyncCallback&lt;Array&lt;WifiScanInfo&gt;&gt;): void; | 权限变更为ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION)) | 
|wifiManager| method | function getScanResultsSync(): Array&lt;WifiScanInfo&gt;; | 权限变更为ohos.permission.GET_WIFI_INFO and (ohos.permission.GET_WIFI_PEERS_MAC or (ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION)) | 
|wifiManager| method | function getCandidateConfigs(): Array&lt;WifiDeviceConfig&gt;; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function getDeviceConfigs(): Array&lt;WifiDeviceConfig&gt;; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.GET_WIFI_CONFIG | 
|wifiManager| method | function getStations(): Array&lt;StationInfo&gt;; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.MANAGE_WIFI_HOTSPOT | 
|wifiManager| method | function getCurrentGroup(): Promise&lt;WifiP2pGroupInfo&gt;; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function getCurrentGroup(callback: AsyncCallback&lt;WifiP2pGroupInfo&gt;): void; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function getP2pPeerDevices(): Promise&lt;WifiP2pDevice[]&gt;; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function getP2pPeerDevices(callback: AsyncCallback&lt;WifiP2pDevice[]&gt;): void; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function p2pConnect(config: WifiP2PConfig): void; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function startDiscoverDevices(): void; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function getP2pGroups(): Promise&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function getP2pGroups(callback: AsyncCallback&lt;Array&lt;WifiP2pGroupInfo&gt;&gt;): void; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function on(type: "p2pDeviceChange", callback: Callback&lt;WifiP2pDevice&gt;): void; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function off(type: "p2pDeviceChange", callback?: Callback&lt;WifiP2pDevice&gt;): void; | 权限变更为ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function on(type: "p2pPeerDeviceChange", callback: Callback&lt;WifiP2pDevice[]&gt;): void; | 权限变更为ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 
|wifiManager| method | function off(type: "p2pPeerDeviceChange", callback?: Callback&lt;WifiP2pDevice[]&gt;): void; | 权限变更为ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION | 