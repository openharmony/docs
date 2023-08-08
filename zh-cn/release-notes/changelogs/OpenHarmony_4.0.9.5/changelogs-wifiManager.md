# 基础通信wifi子系统ChangeLog

# cl.wifi.1 获取WiFi扫描结果接口名变更
获取Wifi扫描结果的接口在API10 Beta1进行了改名，现恢复API9 release的命名。

**变更影响**

基于此前版本开发的应用，需适配变更js接口名称，否则会影响原有功能。

**关键的接口/组件变更**

- 涉及接口

  getScanInfoList(): Array<WifiScanInfo>;

- 变更前：

```js
getScanInfoList(): Array<WifiScanInfo>;
```

- 变更后：

```js
getScanResults(): Array<WifiScanInfo>;
getScanResultsSync(): Array<WifiScanInfo>;
```

**适配指导**

示例代码如下：
- 调用 getScanResults 异步接口：
```js
function getScanResultsPromise() {
  let methodName = `${tag} getScanResultsPromise`
  wifiManager.getScanResults((err, data) => {
    if (err) {
      showToastE(`${methodName} failed ${JSON.stringify(err)}`)
      return
    }
    if (data == null || data.length == 0) {
      showToast(`${methodName} end data is null`)
      return;
    }
  })
}
```
- 调用 getScanResultsSync 同步接口：
```js
function getScanResultsSync(): Array<wifiManager.WifiScanInfo> {
  let methodName = `${tag} getScanResultsSync`
  try {
    return wifiManager.getScanResultsSync();
  } catch (error) {
    showToastE(`${methodName} failed ${JSON.stringify(error)}`)
  }
  return Array();
}
```

# cl.wifi.2 WiFi P2P相关接口名变更
P2P相关接口在API10 Beta1进行了改名，现恢复API9 release的命名。

**变更影响**

基于此前版本开发的应用，需适配变更js接口名称，否则会影响原有功能。

**关键的接口/组件变更**

- 新增接口

| 接口声明 | 接口描述 |
|------|---------|
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

- 废弃接口

| 接口声明  |废弃说明                                                 |
| ------------- |-------------------------------------------------------- |
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
