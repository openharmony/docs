# Wi-Fi Subsystem Changelog

# cl.wifi.1 Change of the Name of the API for Obtaining Wi-Fi Scan Result
The name of the API for obtaining Wi-Fi scan result is changed in API version 10 Beta1 and then changed to the names used in API version 9 release.

**Change Impact**

The JS API name needs to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.

**Key API/Component Changes**

- Involved API:

  getScanInfoList(): Array<WifiScanInfo>;

- Before change:

```js
getScanInfoList(): Array<WifiScanInfo>;
```

- After change:

```js
getScanResults(): Array<WifiScanInfo>;
getScanResultsSync(): Array<WifiScanInfo>;
```

**Adaptation Guide**

Example:
- Call **getScanResults**.
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
- Call **getScanResultsSync**.
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

# cl.wifi.2 Change of Wi-Fi P2P APIs
The names of P2P APIs are changed in API version 10 Beta1 and then changed to the names used in API version 9 release.

**Change Impact**

The JS API name needs to be adapted for applications developed based on earlier versions. Otherwise, relevant functions will be affected.

**Key API/Component Changes**

- Added APIs

| API| Description|
|------|---------|
| **function** updateNetwork(config: WifiDeviceConfig): number; | Updates the added hotspot configuration information.    |
| **function** disableNetwork(netId: number): **void**;                | Disables the added hotspot configuration.    |
| **function** removeAllNetwork(): **void**;                | Deletes all hotspot configurations.    |
| **function** removeDevice(id: number): **void**;                | Deletes configuration of a single hotspot.    |
| **function** getStations(): Array<StationInfo>;                        | Obtains information about devices connected to this hotspot.    |
| **function** createGroup(config: WifiP2PConfig): **void**;                | Creates a P2P group.    |
| **function** removeGroup(): **void**;                | Removes a P2P group.    |
| **function** startDiscoverDevices(): **void**;                | Starts P2P scan.    |
| **function** stopDiscoverDevices(): **void**;                | Stops P2P scan.    |
| **function** deletePersistentGroup(netId: number): **void**;                | Deletes the persistent P2P group with a specified network ID.    |
| **function** setDeviceName(devName: string): **void**;                | Sets the P2P device name.    |

- Deprecated APIs

| API |Description                                                |
| ------------- |-------------------------------------------------------- |
| **function** updateDeviceConfig(config: WifiDeviceConfig): number; | Updates the added hotspot configuration information.    |
| **function** disableDeviceConfig(networkId: number): **void**;                | Disables the added hotspot configuration.    |
| **function** removeAllDeviceConfigs(): **void**;                | Deletes all hotspot configurations.    |
| **function** removeDeviceConfig(networkId: number): **void**;                | Deletes configuration of a single hotspot.    |
| **function** getHotspotStations(): Array<StationInfo>;                        | Obtains information about devices connected to this hotspot.    |
| **function** createP2pGroup(config: WifiP2PConfig): **void**;                | Creates a P2P group.    |
| **function** removeP2pGroup(): **void**;                | Removes a P2P group.    |
| **function** startDiscoverP2pDevices(): **void**;                | Starts P2P scan.    |
| **function** stopDiscoverP2pDevices(): **void**;                | Stops P2P scan.    |
| **function** deletePersistentP2pGroup(netId: number): **void**;                | Deletes the persistent P2P group with a specified network ID.    |
| **function** setP2pDeviceName(devName: string): **void**;                | Sets the P2P device name.    |
