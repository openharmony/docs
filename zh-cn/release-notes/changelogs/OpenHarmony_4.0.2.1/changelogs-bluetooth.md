# 蓝牙服务子系统ChangeLog

## cl.bluetooth.1 接口迁移到新增的@ohos.bluetoothManager.d.ts

@ohos.bluetooth.d.ts接口不支持抛出错误码，而API9以及SystemAPI都需要支持错误码抛出，为了支持该功能，把@ohos.bluetooth.d.ts中所有接口，迁移到新增的@ohos.bluetoothManager.d.ts中，并增加错误码描述。

后续需要import @ohos.bluetoothManager才能使用蓝牙服务的接口：

  ```ts
  import bluetoothManager from '@ohos.bluetoothManager';
  ```


**变更影响**

对API9以及SystemAPI接口的使用有影响，需要import @ohos.bluetoothManager来使用抛错误码的接口：

  ```ts
  import bluetoothManager from '@ohos.bluetoothManager';
  ```

**关键的接口/组件变更**

| 类名 | 旧接口 | 新接口 | 变更类型 |
| -- | -- | -- | -- |
| bluetooth | function getState(): BluetoothState | function getState(): BluetoothState | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | method | function getBtConnectionState(): ProfileConnectionState;  | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function pairDevice(deviceId: string): boolean | function pairDevice(deviceId: string): void | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void |
| bluetooth | function cancelPairedDevice(deviceId: string): boolean | function cancelPairedDevice(deviceId: string): void | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void |
| bluetooth | function getRemoteDeviceName(deviceId: string): string | function getRemoteDeviceName(deviceId: string): string| API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function getRemoteDeviceClass(deviceId: string): DeviceClass | function getRemoteDeviceClass(deviceId: string): DeviceClass | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function enableBluetooth(): boolean | function enableBluetooth(): void | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void |
| bluetooth | function disableBluetooth(): boolean | function disableBluetooth(): void | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void |
| bluetooth | function getLocalName(): string | function getLocalName(): string | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function getPairedDevices(): Array&lt;string&gt;; | function getPairedDevices(): Array&lt;string&gt;; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function getProfileConnState(profileId: ProfileId): ProfileConnectionState | function getProfileConnectionState(profileId: ProfileId): ProfileConnectionState | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口名修改为getProfileConnectionState |
| bluetooth | function setDevicePairingConfirmation(device: string, accept: boolean): boolean | function setDevicePairingConfirmation(device: string, accept: boolean): void | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void |
| bluetooth | function setLocalName(name: string): boolean; | function setLocalName(name: string): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void |
| bluetooth | function setBluetoothScanMode(mode: ScanMode, duration: number): boolean | function setBluetoothScanMode(mode: ScanMode, duration: number): void | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void |
| bluetooth | function getBluetoothScanMode(): ScanMod | function getBluetoothScanMode(): ScanMode | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function startBluetoothDiscovery(): boolean | function startBluetoothDiscovery(): void | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，新加权限ohos.permission.APPROXIMATELY_LOCATION，接口返回值改为void |
| bluetooth | function stopBluetoothDiscovery(): boolean; | function stopBluetoothDiscovery(): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void |
| bluetooth | function on(type: "bluetoothDeviceFind", callback: Callback&lt;Array&lt;string&gt;&gt;): void; | function on(type: "bluetoothDeviceFind", callback: Callback&lt;Array&lt;string&gt;&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function off(type: "bluetoothDeviceFind", callback?: Callback&lt;Array&lt;string&gt;&gt;): void; | function off(type: "bluetoothDeviceFind", callback?: Callback&lt;Array&lt;string&gt;&gt;): void;  | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function on(type: "bondStateChange", callback: Callback&lt;BondStateParam&gt;): void; | function on(type: "bondStateChange", callback: Callbackk&lt;BondStateParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function off(type: "bondStateChange", callback?: Callback&lt;BondStateParam&gt;): void; | function off(type: "bondStateChange", callback?: Callback&lt;BondStateParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function on(type: "pinRequired", callback: Callback&lt;PinRequiredParam&gt;): void; | function on(type: "pinRequired", callback: Callback&lt;PinRequiredParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function off(type: "pinRequired", callback?: Callback&lt;PinRequiredParam&gt;): void; | function off(type: "pinRequired", callback?: Callback&lt;PinRequiredParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function on(type: "stateChange", callback: Callback&lt;BluetoothState&gt;): void; | function on(type: "stateChange", callback: Callback&lt;BluetoothState&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function off(type: "stateChange", callback?: Callback&lt;BluetoothState&gt;): void; | function off(type: "stateChange", callback?: Callback&lt;BluetoothState&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function sppListen(name: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void; | function sppListen(name: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void; | function sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function sppConnect(device: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void; | function sppConnect(device: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function sppCloseServerSocket(socket: number): void; | function sppCloseServerSocket(socket: number): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function sppCloseClientSocket(socket: number): void; | function sppCloseClientSocket(socket: number): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function sppWrite(clientSocket: number, data: ArrayBuffer): boolean; | function sppWrite(clientSocket: number, data: ArrayBuffer): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void |
| bluetooth | function on(type: "sppRead", clientSocket: number, callback: Callback&lt;ArrayBuffer&gt;): void; | function on(type: "sppRead", clientSocket: number, callback: Callback&lt;ArrayBuffer&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts。 |
| bluetooth | function off(type: "sppRead", clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void; | function off(type: "sppRead", clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void; |  API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| bluetooth | function getProfile(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile; | function getProfileInstance(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile | HidHostProfile | PanProfile; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口名修改为getProfileInstance |
| bluetooth | function getProfileInst(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile | HidHostProfile | PanProfile; | function getProfileInstance(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile | HidHostProfile | PanProfile; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口名修改为getProfileInstance  |
| BaseProfile | getConnectionDevices(): Array&lt;string&gt;; | getConnectionDevices(): Array&lt;string&gt;; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| BaseProfile | getDeviceState(device: string): ProfileConnectionState; | getDeviceState(device: string): ProfileConnectionState; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| A2dpSourceProfile | connect(device: string): boolean; | connect(device: string): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| A2dpSourceProfile | disconnect(device: string): boolean; | disconnect(device: string): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| A2dpSourceProfile | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| A2dpSourceProfile | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| A2dpSourceProfile | getPlayingState(device: string): PlayingState; | getPlayingState(device: string): PlayingState; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| HandsFreeAudioGatewayProfile | connect(device: string): boolean; | connect(device: string): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| HandsFreeAudioGatewayProfile | disconnect(device: string): boolean; | disconnect(device: string): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts ，接口返回值改为void |
| HandsFreeAudioGatewayProfile | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| HandsFreeAudioGatewayProfile | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| HidHostProfile | connect(device: string): boolean; | connect(device: string): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| HidHostProfile | disconnect(device: string): boolean; | disconnect(device: string): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| HidHostProfile | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| HidHostProfile | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| PanProfile | disconnect(device: string): boolean; | disconnect(device: string): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| PanProfile | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| PanProfile | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| PanProfile | setTethering(enable: boolean): void; | setTethering(enable: boolean): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| PanProfile | isTetheringOn(): boolean; | isTetheringOn(): boolean; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| BLE | function createGattServer(): GattServer; | function createGattServer(): GattServer; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| BLE | function createGattClientDevice(deviceId: string): GattClientDevice; | function createGattClientDevice(deviceId: string): GattClientDevice; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| BLE | function getConnectedBLEDevices(): Array&lt;string&gt;; | function getConnectedBLEDevices(): Array&lt;string&gt;; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| BLE | function startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void; | function startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，新加权限ohos.permission.APPROXIMATELY_LOCATION  |
| BLE | function stopBLEScan(): void; | function stopBLEScan(): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| BLE | mefunction on(type: "BLEDeviceFind", callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void;thod | function on(type: "BLEDeviceFind", callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| BLE | function off(type: "BLEDeviceFind", callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void; | function off(type: "BLEDeviceFind", callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts |
| GattServer | startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void; | startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | stopAdvertising(): void; | stopAdvertising(): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | addService(service: GattService): boolean; | addService(service: GattService): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattServer | removeService(serviceUuid: string): boolean; | removeService(serviceUuid: string): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattServer | close(): void; | close(): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts
| GattServer | notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean; | notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattServer | sendResponse(serverResponse: ServerResponse): boolean; | sendResponse(serverResponse: ServerResponse): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattServer | on(type: "characteristicRead", callback: Callback&lt;CharacteristicReadReq&gt;): void; | on(type: "characteristicRead", callback: Callback&lt;CharacteristicReadRequest&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | off(type: "characteristicRead", callback?: Callback&lt;CharacteristicReadReq&gt;): void; | off(type: "characteristicRead", callback?: Callback&lt;CharacteristicReadRequest&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | on(type: "characteristicWrite", callback: Callback&lt;CharacteristicWriteReq&gt;): void; | on(type: "characteristicWrite", callback: Callback&lt;CharacteristicWriteRequest&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | off(type: "characteristicWrite", callback?: Callback&lt;CharacteristicWriteReq&gt;): void; | off(type: "characteristicWrite", callback?: Callback&lt;CharacteristicWriteRequest&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | on(type: "descriptorRead", callback: Callback&lt;DescriptorReadReq&gt;): void; | on(type: "descriptorRead", callback: Callback&lt;DescriptorReadRequest&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | off(type: "descriptorRead", callback?: Callback&lt;DescriptorReadReq&gt;): void; | off(type: "descriptorRead", callback?: Callback&lt;DescriptorReadRequest&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | on(type: "descriptorWrite", callback: Callback&lt;DescriptorWriteReq&gt;): void; | on(type: "descriptorWrite", callback: Callback&lt;DescriptorWriteRequest&gt;): void;| API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | off(type: "descriptorWrite", callback?: Callback&lt;DescriptorWriteReq&gt;): void; | off(type: "descriptorWrite", callback?: Callback&lt;DescriptorWriteRequest&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | on(type: "connectStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void; | on(type: "connectStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void;| API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattServer | off(type: "connectStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void; | off(type: "connectStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | connect(): boolean; | connect(): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattClientDevice | disconnect(): boolean; | disconnect(): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattClientDevice | close(): boolean; | close(): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattClientDevice | getDeviceName(callback: AsyncCallback&lt;string&gt;): void; | getDeviceName(callback: AsyncCallback&lt;string&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | getDeviceName(): Promise&lt;string&gt;; | getDeviceName(): Promise&lt;string&gt;; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void; | getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | getServices(): Promise&lt;Array&lt;GattService&gt;&gt;; | getServices(): Promise&lt;Array&lt;GattService&gt;&gt;; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void; | readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;; | readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void; | readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;; | readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | writeCharacteristicValue(characteristic: BLECharacteristic): boolean; | writeCharacteristicValue(characteristic: BLECharacteristic): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattClientDevice | writeDescriptorValue(descriptor: BLEDescriptor): boolean; | writeDescriptorValue(descriptor: BLEDescriptor): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattClientDevice | getRssiValue(callback: AsyncCallback&lt;number&gt;): void; | getRssiValue(callback: AsyncCallback&lt;number&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | getRssiValue(): Promise&lt;number&gt;; | getRssiValue(): Promise&lt;number&gt;; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | setBLEMtuSize(mtu: number): boolean; | setBLEMtuSize(mtu: number): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattClientDevice | setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean; | setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts，接口返回值改为void  |
| GattClientDevice | on(type: "BLECharacteristicChange", callback: Callback&lt;BLECharacteristic&gt;): void; | on(type: "BLECharacteristicChange", callback: Callback&lt;BLECharacteristic&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | off(type: "BLECharacteristicChange", callback?: Callback&lt;BLECharacteristic&gt;): void; | off(type: "BLECharacteristicChange", callback?: Callback&lt;BLECharacteristic&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | on(type: "BLEConnectionStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void; | on(type: "BLEConnectionStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| GattClientDevice | off(type: "BLEConnectionStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void; | off(type: "BLEConnectionStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void; | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | GattService | GattService | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | BLECharacteristic | BLECharacteristic | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | BLEDescriptor | BLEDescriptor | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | NotifyCharacteristic | NotifyCharacteristic | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | CharacteristicReadReq | CharacteristicReadRequest | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | CharacteristicWriteReq | CharacteristicWriteRequest | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | DescriptorReadRe | DescriptorReadRequest | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | DescriptorWriteReq | DescriptorWriteRequest | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ServerResponse | ServerResponse | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | BLEConnectChangedState | BLEConnectChangedState | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ScanResult | ScanResult | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | AdvertiseSetting | AdvertiseSetting | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | AdvertiseData | AdvertiseData | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ManufactureData | ManufactureData | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ServiceData | ServiceData | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ScanFilter | ScanFilter | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ScanOptions | ScanOptions | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | SppOption | SppOption | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | PinRequiredParam | PinRequiredParam | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | DeviceClass | DeviceClass | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | BondStateParam | BondStateParam | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | StateChangeParam | StateChangeParam | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ScanDuty | ScanDuty | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | MatchMode | MatchMode | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ProfileConnectionState | ProfileConnectionState | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | BluetoothState | BluetoothState | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | SppType | SppType | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ScanMode | ScanMode | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | BondState | BondState | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | MajorClass | MajorClass | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | MajorMinorClass | MajorMinorClass | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | PlayingState | PlayingState | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |
| bluetooth | ProfileId | ProfileId | API9接口变更，迁移到@ohos.bluetoothManager.d.ts  |



**适配指导（可选，不涉及则可以删除）**

以enableLocation为例，在新版本上需要使用如下方式进行调用：

  ```ts
  import bluetoothManager from '@ohos.bluetoothManager';
  try {
      var state = bluetoothManager.getState();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```
