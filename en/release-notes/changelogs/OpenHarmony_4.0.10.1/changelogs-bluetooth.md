# Bluetooth Subsystem Changelog

## cl.bluetooth.1 Split of Bluetooth APIs by Profile

1. Split ArkTS APIs in corresponding .d.ts files.
2. Changed the interface permission to **ohos.permission.ACCESS_BLUETOOTH**. [Some APIs](#apis-requiring-dual-permission-verification) also require the **ohos.permission.MANAGE_BLUETOOTH** permission.

| Module| API Reference|
| -------- | ---------------------------- |
|@ohos.bluetooth.a2dp | [js-apis-bluetooth-a2dp.md](../../../application-dev/reference/apis/js-apis-bluetooth-a2dp.md)   |
|@ohos.bluetooth.access | [js-apis-bluetooth-access.md](../../../application-dev/reference/apis/js-apis-bluetooth-access.md)   |
|@ohos.bluetooth.baseProfile | [js-apis-bluetooth-baseProfile.md](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md)   |
|@ohos.bluetooth.ble | [js-apis-bluetooth-ble.md](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md)   |
|@ohos.bluetooth.connection | [js-apis-bluetooth-connection.md](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md)   |
|@ohos.bluetooth.constant | [js-apis-bluetooth-constant.md](../../../application-dev/reference/apis/js-apis-bluetooth-constant.md)   |
|@ohos.bluetooth.hfp | [js-apis-bluetooth-hfp.md](../../../application-dev/reference/apis/js-apis-bluetooth-hfp.md)   |
|@ohos.bluetooth.hid | [js-apis-bluetooth-hid.md](../../../application-dev/reference/apis/js-apis-bluetooth-hid.md)   |
|@ohos.bluetooth.pan | [js-apis-bluetooth-pan.md](../../../application-dev/reference/apis/js-apis-bluetooth-pan.md)   |
|@ohos.bluetooth.socket | [js-apis-bluetooth-socket.md](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md)   |


### APIs Requiring Dual-Permission Verification
| Module| API Declaration|
|------|---------|
|@ohos.bluetooth.baseProfile|[setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy, callback: AsyncCallback&lt;void&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilesetconnectionstrategy) |
|@ohos.bluetooth.baseProfile| [setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilesetconnectionstrategy-1) |
|@ohos.bluetooth.baseProfile| [getConnectionStrategy(deviceId: string, callback: AsyncCallback&lt;ConnectionStrategy&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstrategy)|
|@ohos.bluetooth.baseProfile| [getConnectionStrategy(deviceId: string): Promise&lt;ConnectionStrategy&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstrategy-1) |
|@ohos.bluetooth.connection| [pairCredibleDevice(deviceId: string, transport: BluetoothTransport, callback: AsyncCallback&lt;void&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpaircredibledevice)    |
|@ohos.bluetooth.connection| [pairCredibleDevice(deviceId: string, transport: BluetoothTransport): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpaircredibledevice-1)    |
|@ohos.bluetooth.connection| [setDevicePairingConfirmation(deviceId: string, accept: boolean): void](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetdevicepairingconfirmation)    |
|connect(hid profile) | [connect(deviceId: string): void](../../../application-dev/reference/apis/js-apis-bluetooth-hid.md#connect)  |
|disconnect(hid profile) | [disconnect(deviceId: string): void](../../../application-dev/reference/apis/js-apis-bluetooth-hid.md#disconnect)  |
|setTethering | [setTethering(enable: boolean): void](../../../application-dev/reference/apis/js-apis-bluetooth-pan.md#settethering)  |

**Change Impact**

1. The module to import is changed.
2. After the permission change, you only need to pay attention to the **ohos.permission.ACCESS_BLUETOOTH** and **ohos.permission.MANAGE_BLUETOOTH** permissions.

**Key API/Component Changes**

| Before Change| After Change|
| -------- | ---------------------------- |
|bluetoothManager.enableBluetooth | [access.enableBluetooth](../../../application-dev/reference/apis/js-apis-bluetooth-access.md#accessenablebluetooth)  |
|bluetoothManager.disableBluetooth | [access.disableBluetooth](../../../application-dev/reference/apis/js-apis-bluetooth-access.md#accessdisablebluetooth)  |
|bluetoothManager.getLocalName | [connection.getLocalName](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetlocalname)  |
|bluetoothManager.getState | [access.getState](../../../application-dev/reference/apis/js-apis-bluetooth-access.md#accessgetstate)  |
|bluetoothManager.getBtConnectionState | [connection.getProfileConnectionState](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetprofileconnectionstate)  |
|bluetoothManager.setLocalName | [connection.setLocalName](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetlocalname)  |
|bluetoothManager.pairDevice | [connection.pairDevice](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpairdevice)  |
|bluetoothManager.getProfileConnectionState | [connection.getProfileConnectionState](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetprofileconnectionstate)  |
|bluetoothManager.cancelPairedDevice | [connection.cancelPairedDevice](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectioncancelpaireddevice)  |
|bluetoothManager.getRemoteDeviceName | [connection.getRemoteDeviceName](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetremotedevicename)  |
|bluetoothManager.getRemoteDeviceClass | [connection.getRemoteDeviceClass](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetremotedeviceclass)  |
|bluetoothManager.getPairedDevices | [connection.getPairedDevices](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetpaireddevices)  |
|bluetoothManager.setBluetoothScanMode | [connection.setBluetoothScanMode](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetbluetoothscanmode)  |
|bluetoothManager.getBluetoothScanMode | [connection.getBluetoothScanMode](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetbluetoothscanmode)  |
|bluetoothManager.startBluetoothDiscovery | [connection.startBluetoothDiscovery](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionstartbluetoothdiscovery)  |
|bluetoothManager.stopBluetoothDiscovery | [connection.stopBluetoothDiscovery](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionstopbluetoothdiscovery)  |
|bluetoothManager.setDevicePairingConfirmation | [connection.setDevicePairingConfirmation](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetdevicepairingconfirmation)  |
|bluetoothManager.on('bluetoothDeviceFind') | [connection.on('bluetoothDeviceFind')](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiononbluetoothdevicefind)  |
|bluetoothManager.off('bluetoothDeviceFind') | [connection.off('bluetoothDeviceFind')](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionoffbluetoothdevicefind)  |
|bluetoothManager.on('pinRequired') | [connection.on('pinRequired')](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiononpinrequired)  |
|bluetoothManager.off('pinRequired') | [connection.off('pinRequired')](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionoffpinrequired)  |
|bluetoothManager.on('bondStateChange') | [connection.on('bondStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiononbondstatechange)  |
|bluetoothManager.off('bondStateChange') | [connection.off('bondStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionoffbondstatechange)  |
|bluetoothManager.on('stateChange') | [access.on('stateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-access.md#accessonstatechange)  |
|bluetoothManager.off('stateChange') | [access.off('stateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-access.md#accessoffstatechange)  |
|bluetoothManager.sppListen | [socket.sppListen](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md#socketspplisten)  |
|bluetoothManager.sppAccept | [socket.sppAccept](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md#socketsppaccept)  |
|bluetoothManager.sppConnect | [socket.sppConnect](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionoffbluetoothdevicefind)  |
|bluetoothManager.sppCloseServerSocket | [socket.sppCloseServerSocket](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md#socketsppcloseserversocket)  |
|bluetoothManager.sppCloseClientSocket | [socket.sppCloseClientSocket](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md#socketsppcloseclientsocket)  |
|bluetoothManager.sppWrite | [socket.sppWrite](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md#socketsppwrite)  |
|bluetoothManager.on('sppRead') | [socket.on('sppRead')](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md#socketonsppread)  |
|bluetoothManager.off('sppRead') | [socket.off('sppRead')](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md#socketoffsppread)  |
|bluetoothManager.getProfileInstance | Deprecated|
|createGattServer | [ble.createGattServer](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#blecreategattserver)  |
|createGattClientDevice | [ble.createGattClientDevice](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#blegetconnectedbledevices)  |
|getConnectedBLEDevices | [ble.getConnectedBLEDevices](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#blegetconnectedbledevices)  |
|startBLEScan | [ble.startBLEScan](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#blestartblescan)  |
|stopBLEScan | [ble.stopBLEScan](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#blestopblescan)  |
|on('BLEDeviceFind') | [ble.on('BLEDeviceFind')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#bleonbledevicefind)  |
|off('BLEDeviceFind') | [ble.off('BLEDeviceFind')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#bleoffbledevicefind)  |
|getConnectionDevices | [baseProfile.getConnectedDevices](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnecteddevices)  |
|getDeviceState | [baseProfile.getConnectionState](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstate)  |
|A2dpSourceProfile | [A2dpSourceProfile](../../../application-dev/reference/apis/js-apis-bluetooth-a2dp.md#a2dpsourceprofile)  |
|connect(a2dp profile) | [connect](../../../application-dev/reference/apis/js-apis-bluetooth-a2dp.md#connect)  |
|disconnect(a2dp profile) | [disconnect](../../../application-dev/reference/apis/js-apis-bluetooth-a2dp.md#disconnect)  |
|on('connectionStateChange') | [baseProfile.on('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)  |
|off('connectionStateChange') | [baseProfile.off('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange)  |
|getPlayingState | [getPlayingState](../../../application-dev/reference/apis/js-apis-bluetooth-a2dp.md#getplayingstate)  |
|HandsFreeAudioGatewayProfile | [HandsFreeAudioGatewayProfile](../../../application-dev/reference/apis/js-apis-bluetooth-hfp.md#handsfreeaudiogatewayprofile)  |
|connect(hfp profile) | [connect](../../../application-dev/reference/apis/js-apis-bluetooth-hfp.md#connect)  |
|disconnect(hfp profile) | [disconnect](../../../application-dev/reference/apis/js-apis-bluetooth-hfp.md#disconnect)  |
|on('connectionStateChange')(hfp profile) | [baseProfile.on('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)  |
|off('connectionStateChange')(hfp profile) | [baseProfile.off('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange)  |
|connect(hid profile) | [connect](../../../application-dev/reference/apis/js-apis-bluetooth-hid.md#connect)  |
|disconnect(hid profile) | [disconnect](../../../application-dev/reference/apis/js-apis-bluetooth-hid.md#disconnect)  |
|on('connectionStateChange')(hid profile) | [baseProfile.on('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)  |
|off('connectionStateChange')(hid profile) | [baseProfile.off('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange)  |
|disconnect(pan profile) | [disconnect](../../../application-dev/reference/apis/js-apis-bluetooth-pan.md#disconnect)  |
|on('connectionStateChange')(pan profile) | [baseProfile.on('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange)  |
|off('connectionStateChange')(pan profile) | [baseProfile.off('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange)  |
|setTethering | [setTethering](../../../application-dev/reference/apis/js-apis-bluetooth-pan.md#settethering)  |
|isTetheringOn | [isTetheringOn](../../../application-dev/reference/apis/js-apis-bluetooth-pan.md#istetheringon)  |
|startAdvertising | [ble.startAdvertising](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#blestartadvertising)  |
|stopAdvertising | [ble.stopAdvertising](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#blestopadvertising)  |
|addService | [addService](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#addservice)  |
|removeService | [removeService](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#removeservice)  |
|close | [close](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#close)  |
|notifyCharacteristicChanged | [notifyCharacteristicChanged](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#notifycharacteristicchanged)  |
|sendResponse | [sendResponse](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#sendresponse)  |
|on('characteristicRead') | [on('characteristicRead')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#oncharacteristicread)  |
|off('characteristicRead') | [off('characteristicRead')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#offcharacteristicread)  |
|on('characteristicWrite') | [on('characteristicWrite')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#oncharacteristicwrite)  |
|off('characteristicWrite') | [off('characteristicWrite')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#offcharacteristicwrite)  |
|on('descriptorRead') | [on('descriptorRead')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#ondescriptorread)  |
|off('descriptorRead') | [off('descriptorRead')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#offdescriptorread)  |
|on('descriptorWrite') | [on('descriptorWrite')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#ondescriptorwrite)  |
|off('descriptorWrite') | [off('descriptorWrite')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#offdescriptorwrite)  |
|on('connectStateChange') | [on('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#onconnectionstatechange)  |
|off('connectStateChange') | [off('connectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#offconnectionstatechange)  |
|connect | [connect](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#connect)  |
|disconnect | [disconnect](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#disconnect)  |
|close | [close](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#close)  |
|getServices(callback) | [getServices](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#getservices)  |
|getServices(promise) | [getServices](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#getservices-1)  |
|readCharacteristicValue(callback) | [readCharacteristicValue](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#readcharacteristicvalue)  |
|readCharacteristicValue(promise) | [readCharacteristicValue](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#readcharacteristicvalue-1)  |
|readDescriptorValue(callback) | [readDescriptorValue](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#readdescriptorvalue)  |
|readDescriptorValue(promise) | [readDescriptorValue](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#readdescriptorvalue-1)  |
|writeCharacteristicValue(callback) | [writeCharacteristicValue](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#writecharacteristicvalue)  |
|writeDescriptorValue(promise) | [writeCharacteristicValue](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#writecharacteristicvalue-1)  |
|setBLEMtuSize | [setBLEMtuSize](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#setblemtusize)  |
|setNotifyCharacteristicChanged | [setCharacteristicChangeNotification](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#setcharacteristicchangenotification)  |
|on('BLECharacteristicChange') | [on('BLECharacteristicChange')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#onblecharacteristicchange)  |
|off('BLECharacteristicChange') | [off('BLECharacteristicChange')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#offblecharacteristicchange)  |
|on('BLEConnectionStateChange') | [on('BLEConnectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#onbleconnectionstatechange)  |
|off('BLEConnectionStateChange') | [off('BLEConnectionStateChange')](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#offbleconnectionstatechange)  |
|getDeviceName(callback) | [getDeviceName](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#getdevicename)  |
|getDeviceName(promise) | [getDeviceName](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#getdevicename-1)  |
|getRssiValue(callback) | [getRssiValue](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#getrssivalue)  |
|getRssiValue(promise) | [getRssiValue](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#getrssivalue-1)  |
|ScanMode | [ScanMode](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#scanmode)  |
|BondState | [BondState](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#bondstate)  |
|SppOption | [SppOptions](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md#sppoptions)  |
|SppType | [SppType](../../../application-dev/reference/apis/js-apis-bluetooth-socket.md#spptype)  |
|GattService | [GattService](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#gattservice)  |
|BLECharacteristic | [BLECharacteristic](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#blecharacteristic)  |
|BLEDescriptor | [BLEDescriptor](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#bledescriptor)  |
|NotifyCharacteristic | [NotifyCharacteristic](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#notifycharacteristic)  |
|CharacteristicReadRequest | [CharacteristicReadRequest](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#characteristicreadrequest)  |
|CharacteristicWriteRequest | [CharacteristicWriteRequest](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#characteristicwriterequest)  |
|DescriptorReadRequest | [DescriptorReadRequest](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#descriptorreadrequest)  |
|DescriptorWriteRequest | [DescriptorWriteRequest](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#descriptorwriterequest)  |
|ServerResponse | [ServerResponse](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#serverresponse)  |
|BLEConnectChangedState | [BLEConnectionChangeState](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#bleconnectionchangestate)  |
|ProfileConnectionState | [ProfileConnectionState](../../../application-dev/reference/apis/js-apis-bluetooth-constant.md#profileconnectionstate)  |
|ScanFilter | [ScanFilter](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#scanfilter)  |
|ScanOptions | [ScanOptions](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#scanoptions)  |
|ScanDuty | [ScanDuty](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#scanduty)  |
|MatchMode | [MatchMode](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#matchmode)  |
|ScanResult | [ScanResult](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#scanresult)  |
|BluetoothState | [BluetoothState](../../../application-dev/reference/apis/js-apis-bluetooth-access.md#bluetoothstate)  |
|AdvertiseSetting | [AdvertiseSetting](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#advertisesetting)  |
|AdvertiseData | [AdvertiseData](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#advertisedata)  |
|ManufactureData | [ManufactureData](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#manufacturedata)  |
|ServiceData | [ServiceData](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#servicedata)  |
|PinRequiredParam | [PinRequiredParam](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#pinrequiredparam)  |
|BondStateParam | [BondStateParam](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#bondstateparam)  |
|StateChangeParam | [StateChangeParam](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#statechangeparam)  |
|DeviceClass | [DeviceClass](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#deviceclass)  |
|MajorClass | [MajorClass](../../../application-dev/reference/apis/js-apis-bluetooth-constant.md#majorclass)  |
|MajorMinorClass | [MajorMinorClass](../../../application-dev/reference/apis/js-apis-bluetooth-constant.md#majorminorclass)  |
|PlayingState | [PlayingState](../../../application-dev/reference/apis/js-apis-bluetooth-a2dp.md#playingstate)  |
|ProfileId | [ProfileId](../../../application-dev/reference/apis/js-apis-bluetooth-constant.md#profileid)  |


### Added APIs


| Module        |API                                                |
| ------------- |-------------------------------------------------------- |
|@ohos.bluetooth.connection| [pairCredibleDevice(deviceId: string, transport: BluetoothTransport, callback: AsyncCallback&lt;void&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpaircredibledevice)    |
|@ohos.bluetooth.connection| [pairCredibleDevice(deviceId: string, transport: BluetoothTransport): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionpaircredibledevice-1)    |
|@ohos.bluetooth.connection| [getRemoteProfileUuids(deviceId: string, callback: AsyncCallback&lt;Array&lt;ProfileUuids&gt;&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetremoteprofileuuids)    |
|@ohos.bluetooth.connection| [getRemoteProfileUuids(deviceId: string): Promise&lt;Array&lt;ProfileUuids&gt;&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetremoteprofileuuids-1)    |
|@ohos.bluetooth.connection| [getLocalProfileUuids(callback: AsyncCallback&lt;Array&lt;ProfileUuids&gt;&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetlocalprofileuuids)    |
|@ohos.bluetooth.connection| [getLocalProfileUuids(): Promise&lt;Array&lt;ProfileUuids&gt;&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectiongetlocalprofileuuids-1)    |
|@ohos.bluetooth.connection| [setDevicePinCode(deviceId: string, code: string, callback: AsyncCallback&lt;void&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetdevicepincode)    |
|@ohos.bluetooth.connection| [setDevicePinCode(deviceId: string, code: string): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#connectionsetdevicepincode-1)    |
|@ohos.bluetooth.baseProfile| [setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy, callback: AsyncCallback&lt;void&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilesetconnectionstrategy)|
|@ohos.bluetooth.baseProfile| [setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilesetconnectionstrategy-1) |
|@ohos.bluetooth.baseProfile| [getConnectionStrategy(deviceId: string, callback: AsyncCallback&lt;ConnectionStrategy&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstrategy)|
|@ohos.bluetooth.baseProfile| [getConnectionStrategy(deviceId: string): Promise&lt;ConnectionStrategy&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstrategy-1) |
|@ohos.bluetooth.baseprofile|[ConnectionStrategy](../../../application-dev/reference/apis/js-apis-bluetooth-baseProfile.md#connectionstrategy)|
|@ohos.bluetooth.ble|[properties](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#blecharacteristic)|
|@ohos.bluetooth.ble|[deviceName](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#scanresult)|
|@ohos.bluetooth.ble|[includeDeviceName](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#advertisedata)|
|@ohos.bluetooth.ble|[GattProperties](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#gattproperties)|
|@ohos.bluetooth.ble|[setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean, callback: AsyncCallback&lt;void&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#setcharacteristicchangeindication)|
|@ohos.bluetooth.ble|[setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#setcharacteristicchangeindication-1)|
|@ohos.bluetooth.ble|[on(type: 'BLEMtuChange', callback: Callback&lt;number&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#onblemtuchange)|
|@ohos.bluetooth.ble|[off(type: 'BLEMtuChange', callback?: Callback&lt;number&gt;): void](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#offblemtuchange)|
|@ohos.bluetooth.connection|[pinType](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#pintype)|
|@ohos.bluetooth.connection|[BluetoothTransport](../../../application-dev/reference/apis/js-apis-bluetooth-connection.md#bluetoothtransport)|
|@ohos.bluetooth.constant|[ProfileUuids](../../../application-dev/reference/apis/js-apis-bluetooth-constant.md#profileuuids)|

### APIs Added with Promise

| Module        |API                                                |
| ------------- |-------------------------------------------------------- |
|@ohos.bluetooth.ble| [notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#notifycharacteristicchanged-1)    |
|@ohos.bluetooth.ble| [writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#writecharacteristicvalue-1)    |
|@ohos.bluetooth.ble| [writeDescriptorValue(descriptor: BLEDescriptor): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#writedescriptorvalue-1)    |
|@ohos.bluetooth.ble| [setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean): Promise&lt;void&gt;](../../../application-dev/reference/apis/js-apis-bluetooth-ble.md#setcharacteristicchangenotification-1)    |

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
