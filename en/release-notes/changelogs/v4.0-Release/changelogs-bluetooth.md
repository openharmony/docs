# Bluetooth Changelog

## cl.bluetooth.1 Split of Bluetooth APIs by Profile

1. Split ArkTS APIs in corresponding .d.ts files.
2. Changed the interface permission to **ohos.permission.ACCESS_BLUETOOTH**. [Some APIs](#apis-requiring-dual-permission-verification) also require the **ohos.permission.MANAGE_BLUETOOTH** permission.

| Module| API Reference|
| -------- | ---------------------------- |
|@ohos.bluetooth.a2dp | [js-apis-bluetooth-a2dp.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-a2dp.md)   |
|@ohos.bluetooth.access | [js-apis-bluetooth-access.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-access.md)   |
|@ohos.bluetooth.baseProfile | [js-apis-bluetooth-baseProfile.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md)   |
|@ohos.bluetooth.ble | [js-apis-bluetooth-ble.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md)   |
|@ohos.bluetooth.connection | [js-apis-bluetooth-connection.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md)   |
|@ohos.bluetooth.constant | [js-apis-bluetooth-constant.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-constant.md)   |
|@ohos.bluetooth.hfp | [js-apis-bluetooth-hfp.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-hfp.md)   |
|@ohos.bluetooth.hid | [js-apis-bluetooth-hid.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-hid.md)   |
|@ohos.bluetooth.pan | [js-apis-bluetooth-pan.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-pan.md)   |
|@ohos.bluetooth.socket | [js-apis-bluetooth-socket.md](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md)   |


### APIs Requiring Dual-Permission Verification
| Module| API|
|------|---------|
|@ohos.bluetooth.baseProfile|[setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy, callback: AsyncCallback&lt;void&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilesetconnectionstrategy) |
|@ohos.bluetooth.baseProfile| [setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilesetconnectionstrategy-1) |
|@ohos.bluetooth.baseProfile| [getConnectionStrategy(deviceId: string, callback: AsyncCallback&lt;ConnectionStrategy&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstrategy)|
|@ohos.bluetooth.baseProfile| [getConnectionStrategy(deviceId: string): Promise&lt;ConnectionStrategy&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstrategy-1) |
|@ohos.bluetooth.connection| [pairCredibleDevice(deviceId: string, transport: BluetoothTransport, callback: AsyncCallback&lt;void&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpaircredibledevice)    |
|@ohos.bluetooth.connection| [pairCredibleDevice(deviceId: string, transport: BluetoothTransport): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpaircredibledevice-1)    |
|@ohos.bluetooth.connection| [setDevicePairingConfirmation(deviceId: string, accept: boolean): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetdevicepairingconfirmation)    |
|connect(hid profile) | [connect(deviceId: string): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-hid.md#connect)  |
|disconnect(hid profile) | [disconnect(deviceId: string): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-hid.md#disconnect)  |
|setTethering | [setTethering(enable: boolean): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-pan.md#settethering)  |

**Change Impact**

1. The module to import is changed.
2. After the permission change, only the **ohos.permission.ACCESS_BLUETOOTH** and **ohos.permission.MANAGE_BLUETOOTH** permissions are required.

**Key API/Component Changes**

| Before Change| After Change|
| -------- | ---------------------------- |
|bluetoothManager.enableBluetooth | [access.enableBluetooth](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-access.md#accessenablebluetooth)  |
|bluetoothManager.disableBluetooth | [access.disableBluetooth](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-access.md#accessdisablebluetooth)  |
|bluetoothManager.getLocalName | [connection.getLocalName](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetlocalname)  |
|bluetoothManager.getState | [access.getState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-access.md#accessgetstate)  |
|bluetoothManager.getBtConnectionState | [connection.getProfileConnectionState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetprofileconnectionstate)  |
|bluetoothManager.setLocalName | [connection.setLocalName](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetlocalname)  |
|bluetoothManager.pairDevice | [connection.pairDevice](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpairdevice)  |
|bluetoothManager.getProfileConnectionState | [connection.getProfileConnectionState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetprofileconnectionstate)  |
|bluetoothManager.cancelPairedDevice | [connection.cancelPairedDevice](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectioncancelpaireddevice)  |
|bluetoothManager.getRemoteDeviceName | [connection.getRemoteDeviceName](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetremotedevicename)  |
|bluetoothManager.getRemoteDeviceClass | [connection.getRemoteDeviceClass](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetremotedeviceclass)  |
|bluetoothManager.getPairedDevices | [connection.getPairedDevices](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetpaireddevices)  |
|bluetoothManager.setBluetoothScanMode | [connection.setBluetoothScanMode](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetbluetoothscanmode)  |
|bluetoothManager.getBluetoothScanMode | [connection.getBluetoothScanMode](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetbluetoothscanmode)  |
|bluetoothManager.startBluetoothDiscovery | [connection.startBluetoothDiscovery](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionstartbluetoothdiscovery)  |
|bluetoothManager.stopBluetoothDiscovery | [connection.stopBluetoothDiscovery](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionstopbluetoothdiscovery)  |
|bluetoothManager.setDevicePairingConfirmation | [connection.setDevicePairingConfirmation](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetdevicepairingconfirmation)  |
|bluetoothManager.on('bluetoothDeviceFind') | [connection.on('bluetoothDeviceFind')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiononbluetoothdevicefind)  |
|bluetoothManager.off('bluetoothDeviceFind') | [connection.off('bluetoothDeviceFind')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionoffbluetoothdevicefind)  |
|bluetoothManager.on('pinRequired') | [connection.on('pinRequired')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiononpinrequired)  |
|bluetoothManager.off('pinRequired') | [connection.off('pinRequired')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionoffpinrequired)  |
|bluetoothManager.on('bondStateChange') | [connection.on('bondStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiononbondstatechange)  |
|bluetoothManager.off('bondStateChange') | [connection.off('bondStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionoffbondstatechange)  |
|bluetoothManager.on('stateChange') | [access.on('stateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-access.md#accessonstatechange)  |
|bluetoothManager.off('stateChange') | [access.off('stateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-access.md#accessoffstatechange)  |
|bluetoothManager.sppListen | [socket.sppListen](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md#socketspplisten)  |
|bluetoothManager.sppAccept | [socket.sppAccept](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md#socketsppaccept)  |
|bluetoothManager.sppConnect | [socket.sppConnect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionoffbluetoothdevicefind)  |
|bluetoothManager.sppCloseServerSocket | [socket.sppCloseServerSocket](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md#socketsppcloseserversocket)  |
|bluetoothManager.sppCloseClientSocket | [socket.sppCloseClientSocket](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md#socketsppcloseclientsocket)  |
|bluetoothManager.sppWrite | [socket.sppWrite](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md#socketsppwrite)  |
|bluetoothManager.on('sppRead') | [socket.on('sppRead')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md#socketonsppread)  |
|bluetoothManager.off('sppRead') | [socket.off('sppRead')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md#socketoffsppread)  |
|bluetoothManager.getProfileInstance | Deprecated|
|createGattServer | [ble.createGattServer](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#blecreategattserver)  |
|createGattClientDevice | [ble.createGattClientDevice](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#blegetconnectedbledevices)  |
|getConnectedBLEDevices | [ble.getConnectedBLEDevices](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#blegetconnectedbledevices)  |
|startBLEScan | [ble.startBLEScan](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#blestartblescan)  |
|stopBLEScan | [ble.stopBLEScan](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#blestopblescan)  |
|on('BLEDeviceFind') | [ble.on('BLEDeviceFind')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#bleonbledevicefind)  |
|off('BLEDeviceFind') | [ble.off('BLEDeviceFind')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#bleoffbledevicefind)  |
|getConnectionDevices | [baseProfile.getConnectedDevices](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnecteddevices)  |
|getDeviceState | [baseProfile.getConnectionState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstate)  |
|A2dpSourceProfile | [A2dpSourceProfile](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-a2dp.md#a2dpsourceprofile)  |
|connect(a2dp profile) | [connect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-a2dp.md#connect)  |
|disconnect(a2dp profile) | [disconnect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-a2dp.md#disconnect)  |
|on('connectionStateChange') | [baseProfile.on('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)  |
|off('connectionStateChange') | [baseProfile.off('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange)  |
|getPlayingState | [getPlayingState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-a2dp.md#getplayingstate)  |
|HandsFreeAudioGatewayProfile | [HandsFreeAudioGatewayProfile](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-hfp.md#handsfreeaudiogatewayprofile)  |
|connect(hfp profile) | [connect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-hfp.md#connect)  |
|disconnect(hfp profile) | [disconnect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-hfp.md#disconnect)  |
|on('connectionStateChange')(hfp profile) | [baseProfile.on('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)  |
|off('connectionStateChange')(hfp profile) | [baseProfile.off('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange)  |
|connect(hid profile) | [connect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-hid.md#connect)  |
|disconnect(hid profile) | [disconnect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-hid.md#disconnect)  |
|on('connectionStateChange')(hid profile) | [baseProfile.on('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)  |
|off('connectionStateChange')(hid profile) | [baseProfile.off('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange)  |
|disconnect(pan profile) | [disconnect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-pan.md#disconnect)  |
|on('connectionStateChange')(pan profile) | [baseProfile.on('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)  |
|off('connectionStateChange')(pan profile) | [baseProfile.off('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange)  |
|setTethering | [setTethering](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-pan.md#settethering)  |
|isTetheringOn | [isTetheringOn](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-pan.md#istetheringon)  |
|startAdvertising | [ble.startAdvertising](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#blestartadvertising)  |
|stopAdvertising | [ble.stopAdvertising](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#blestopadvertising)  |
|addService | [addService](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#addservice)  |
|removeService | [removeService](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#removeservice)  |
|close | [close](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#close)  |
|notifyCharacteristicChanged | [notifyCharacteristicChanged](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#notifycharacteristicchanged)  |
|sendResponse | [sendResponse](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#sendresponse)  |
|on('characteristicRead') | [on('characteristicRead')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#oncharacteristicread)  |
|off('characteristicRead') | [off('characteristicRead')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#offcharacteristicread)  |
|on('characteristicWrite') | [on('characteristicWrite')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#oncharacteristicwrite)  |
|off('characteristicWrite') | [off('characteristicWrite')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#offcharacteristicwrite)  |
|on('descriptorRead') | [on('descriptorRead')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#ondescriptorread)  |
|off('descriptorRead') | [off('descriptorRead')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#offdescriptorread)  |
|on('descriptorWrite') | [on('descriptorWrite')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#ondescriptorwrite)  |
|off('descriptorWrite') | [off('descriptorWrite')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#offdescriptorwrite)  |
|on('connectStateChange') | [on('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#onconnectionstatechange)  |
|off('connectStateChange') | [off('connectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#offconnectionstatechange)  |
|connect | [connect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#connect)  |
|disconnect | [disconnect](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#disconnect)  |
|close | [close](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#close)  |
|getServices(callback) | [getServices](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#getservices)  |
|getServices(promise) | [getServices](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#getservices-1)  |
|readCharacteristicValue(callback) | [readCharacteristicValue](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#readcharacteristicvalue)  |
|readCharacteristicValue(promise) | [readCharacteristicValue](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#readcharacteristicvalue-1)  |
|readDescriptorValue(callback) | [readDescriptorValue](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#readdescriptorvalue)  |
|readDescriptorValue(promise) | [readDescriptorValue](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#readdescriptorvalue-1)  |
|writeCharacteristicValue(callback) | [writeCharacteristicValue](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#writecharacteristicvalue)  |
|writeDescriptorValue(promise) | [writeCharacteristicValue](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#writecharacteristicvalue-1)  |
|setBLEMtuSize | [setBLEMtuSize](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#setblemtusize)  |
|setNotifyCharacteristicChanged | [setCharacteristicChangeNotification](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#setcharacteristicchangenotification)  |
|on('BLECharacteristicChange') | [on('BLECharacteristicChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#onblecharacteristicchange)  |
|off('BLECharacteristicChange') | [off('BLECharacteristicChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#offblecharacteristicchange)  |
|on('BLEConnectionStateChange') | [on('BLEConnectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#onbleconnectionstatechange)  |
|off('BLEConnectionStateChange') | [off('BLEConnectionStateChange')](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#offbleconnectionstatechange)  |
|getDeviceName(callback) | [getDeviceName](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#getdevicename)  |
|getDeviceName(promise) | [getDeviceName](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#getdevicename-1)  |
|getRssiValue(callback) | [getRssiValue](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#getrssivalue)  |
|getRssiValue(promise) | [getRssiValue](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#getrssivalue-1)  |
|ScanMode | [ScanMode](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#scanmode)  |
|BondState | [BondState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#bondstate)  |
|SppOption | [SppOptions](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md#sppoptions)  |
|SppType | [SppType](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-socket.md#spptype)  |
|GattService | [GattService](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#gattservice)  |
|BLECharacteristic | [BLECharacteristic](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#blecharacteristic)  |
|BLEDescriptor | [BLEDescriptor](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#bledescriptor)  |
|NotifyCharacteristic | [NotifyCharacteristic](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#notifycharacteristic)  |
|CharacteristicReadRequest | [CharacteristicReadRequest](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#characteristicreadrequest)  |
|CharacteristicWriteRequest | [CharacteristicWriteRequest](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#characteristicwriterequest)  |
|DescriptorReadRequest | [DescriptorReadRequest](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#descriptorreadrequest)  |
|DescriptorWriteRequest | [DescriptorWriteRequest](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#descriptorwriterequest)  |
|ServerResponse | [ServerResponse](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#serverresponse)  |
|BLEConnectChangedState | [BLEConnectionChangeState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#bleconnectionchangestate)  |
|ProfileConnectionState | [ProfileConnectionState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-constant.md#profileconnectionstate)  |
|ScanFilter | [ScanFilter](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#scanfilter)  |
|ScanOptions | [ScanOptions](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#scanoptions)  |
|ScanDuty | [ScanDuty](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#scanduty)  |
|MatchMode | [MatchMode](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#matchmode)  |
|ScanResult | [ScanResult](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#scanresult)  |
|BluetoothState | [BluetoothState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-access.md#bluetoothstate)  |
|AdvertiseSetting | [AdvertiseSetting](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#advertisesetting)  |
|AdvertiseData | [AdvertiseData](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#advertisedata)  |
|ManufactureData | [ManufactureData](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#manufacturedata)  |
|ServiceData | [ServiceData](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#servicedata)  |
|PinRequiredParam | [PinRequiredParam](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#pinrequiredparam)  |
|BondStateParam | [BondStateParam](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#bondstateparam)  |
|StateChangeParam | [StateChangeParam](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#statechangeparam)  |
|DeviceClass | [DeviceClass](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#deviceclass)  |
|MajorClass | [MajorClass](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-constant.md#majorclass)  |
|MajorMinorClass | [MajorMinorClass](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-constant.md#majorminorclass)  |
|PlayingState | [PlayingState](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-a2dp.md#playingstate)  |
|ProfileId | [ProfileId](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-constant.md#profileid)  |


### Added APIs


| Module        |API                                                |
| ------------- |-------------------------------------------------------- |
|@ohos.bluetooth.connection| [pairCredibleDevice(deviceId: string, transport: BluetoothTransport, callback: AsyncCallback&lt;void&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpaircredibledevice)    |
|@ohos.bluetooth.connection| [pairCredibleDevice(deviceId: string, transport: BluetoothTransport): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpaircredibledevice-1)    |
|@ohos.bluetooth.connection| [getRemoteProfileUuids(deviceId: string, callback: AsyncCallback&lt;Array&lt;ProfileUuids&gt;&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetremoteprofileuuids)    |
|@ohos.bluetooth.connection| [getRemoteProfileUuids(deviceId: string): Promise&lt;Array&lt;ProfileUuids&gt;&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetremoteprofileuuids-1)    |
|@ohos.bluetooth.connection| [getLocalProfileUuids(callback: AsyncCallback&lt;Array&lt;ProfileUuids&gt;&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetlocalprofileuuids)    |
|@ohos.bluetooth.connection| [getLocalProfileUuids(): Promise&lt;Array&lt;ProfileUuids&gt;&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetlocalprofileuuids-1)    |
|@ohos.bluetooth.connection| [setDevicePinCode(deviceId: string, code: string, callback: AsyncCallback&lt;void&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetdevicepincode)    |
|@ohos.bluetooth.connection| [setDevicePinCode(deviceId: string, code: string): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetdevicepincode-1)    |
|@ohos.bluetooth.baseProfile| [setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy, callback: AsyncCallback&lt;void&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilesetconnectionstrategy)|
|@ohos.bluetooth.baseProfile| [setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilesetconnectionstrategy-1) |
|@ohos.bluetooth.baseProfile| [getConnectionStrategy(deviceId: string, callback: AsyncCallback&lt;ConnectionStrategy&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstrategy)|
|@ohos.bluetooth.baseProfile| [getConnectionStrategy(deviceId: string): Promise&lt;ConnectionStrategy&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstrategy-1) |
|@ohos.bluetooth.baseprofile|[ConnectionStrategy](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#connectionstrategy)|
|@ohos.bluetooth.ble|[properties](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#blecharacteristic)|
|@ohos.bluetooth.ble|[deviceName](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#scanresult)|
|@ohos.bluetooth.ble|[includeDeviceName](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#advertisedata)|
|@ohos.bluetooth.ble|[GattProperties](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#gattproperties)|
|@ohos.bluetooth.ble|[setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#setcharacteristicchangeindication)|
|@ohos.bluetooth.ble|[setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#setcharacteristicchangeindication-1)|
|@ohos.bluetooth.ble|[on(type: 'BLEMtuChange', callback: Callback&lt;number&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#onblemtuchange)|
|@ohos.bluetooth.ble|[off(type: 'BLEMtuChange', callback?: Callback&lt;number&gt;): void](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#offblemtuchange)|
|@ohos.bluetooth.connection|[pinType](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#pintype)|
|@ohos.bluetooth.connection|[BluetoothTransport](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-connection.md#bluetoothtransport)|
|@ohos.bluetooth.constant|[ProfileUuids](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-constant.md#profileuuids)|

### APIs Added with Promise

| Module        |API                                                |
| ------------- |-------------------------------------------------------- |
|@ohos.bluetooth.ble| [notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#notifycharacteristicchanged-1)    |
|@ohos.bluetooth.ble| [writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#writecharacteristicvalue-1)    |
|@ohos.bluetooth.ble| [writeDescriptorValue(descriptor: BLEDescriptor): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#writedescriptorvalue-1)    |
|@ohos.bluetooth.ble| [setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.0-Release/en/application-dev/reference/apis/js-apis-bluetooth-ble.md#setcharacteristicchangenotification-1)    |

**Adaptation Guide**

Determine the module to import based on the profile module. For some interfaces, multiple TS files need to be imported.

```js
//For example, getConnectionState() in @ohos.bluetooth.baseProfile.
import a2dp from '@ohos.bluetooth.a2dp';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let ret = a2dpSrc.getConnectionState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}

```
