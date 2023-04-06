| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function getState(): BluetoothState;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function getBtConnectionState(): ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function pairDevice(deviceId: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function cancelPairedDevice(deviceId: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function getRemoteDeviceName(deviceId: string): string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function getRemoteDeviceClass(deviceId: string): DeviceClass;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function enableBluetooth(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function disableBluetooth(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function getLocalName(): string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function getPairedDevices(): Array\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function getProfileConnectionState(profileId: ProfileId): ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function setDevicePairingConfirmation(device: string, accept: boolean): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function setLocalName(name: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function setBluetoothScanMode(mode: ScanMode, duration: number): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function getBluetoothScanMode(): ScanMode;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function startBluetoothDiscovery(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function stopBluetoothDiscovery(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function on(type: "bondStateChange", callback: Callback\<BondStateParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function on(type: "stateChange", callback: Callback\<BluetoothState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function off(type: "stateChange", callback?: Callback\<BluetoothState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function sppCloseServerSocket(socket: number): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function sppCloseClientSocket(socket: number): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function sppWrite(clientSocket: number, data: ArrayBuffer): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: bluetoothManager<br>方法 or 属性: function getProfileInstance(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile \| HidHostProfile \| PanProfile;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BaseProfile|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BaseProfile<br>方法 or 属性: getConnectionDevices(): Array\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BaseProfile<br>方法 or 属性: getDeviceState(device: string): ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: A2dpSourceProfile|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: A2dpSourceProfile<br>方法 or 属性: connect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: A2dpSourceProfile<br>方法 or 属性: disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: A2dpSourceProfile<br>方法 or 属性: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: A2dpSourceProfile<br>方法 or 属性: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: A2dpSourceProfile<br>方法 or 属性: getPlayingState(device: string): PlayingState;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HandsFreeAudioGatewayProfile|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HandsFreeAudioGatewayProfile<br>方法 or 属性: connect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HandsFreeAudioGatewayProfile<br>方法 or 属性: disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HandsFreeAudioGatewayProfile<br>方法 or 属性: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HandsFreeAudioGatewayProfile<br>方法 or 属性: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HidHostProfile|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HidHostProfile<br>方法 or 属性: connect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HidHostProfile<br>方法 or 属性: disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HidHostProfile<br>方法 or 属性: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: HidHostProfile<br>方法 or 属性: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PanProfile|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PanProfile<br>方法 or 属性: disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PanProfile<br>方法 or 属性: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PanProfile<br>方法 or 属性: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PanProfile<br>方法 or 属性: setTethering(enable: boolean): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PanProfile<br>方法 or 属性: isTetheringOn(): boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLE|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLE<br>方法 or 属性: function createGattServer(): GattServer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLE<br>方法 or 属性: function createGattClientDevice(deviceId: string): GattClientDevice;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLE<br>方法 or 属性: function getConnectedBLEDevices(): Array\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLE<br>方法 or 属性: function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLE<br>方法 or 属性: function stopBLEScan(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLE<br>方法 or 属性: function on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLE<br>方法 or 属性: function off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: stopAdvertising(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: addService(service: GattService): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: removeService(serviceUuid: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: close(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: sendResponse(serverResponse: ServerResponse): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: on(type: "characteristicRead", callback: Callback\<CharacteristicReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: off(type: "characteristicRead", callback?: Callback\<CharacteristicReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: on(type: "descriptorRead", callback: Callback\<DescriptorReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: off(type: "descriptorRead", callback?: Callback\<DescriptorReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: on(type: "descriptorWrite", callback: Callback\<DescriptorWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattServer<br>方法 or 属性: off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: connect(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: disconnect(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: close(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: getDeviceName(callback: AsyncCallback\<string>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: getDeviceName(): Promise\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: getServices(callback: AsyncCallback\<Array\<GattService>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: getServices(): Promise\<Array\<GattService>>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: writeCharacteristicValue(characteristic: BLECharacteristic): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: writeDescriptorValue(descriptor: BLEDescriptor): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: getRssiValue(callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: getRssiValue(): Promise\<number>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: setBLEMtuSize(mtu: number): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattClientDevice<br>方法 or 属性: off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattService|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattService<br>方法 or 属性: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattService<br>方法 or 属性: isPrimary: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattService<br>方法 or 属性: characteristics: Array\<BLECharacteristic>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: GattService<br>方法 or 属性: includeServices?: Array\<GattService>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLECharacteristic|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLECharacteristic<br>方法 or 属性: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLECharacteristic<br>方法 or 属性: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLECharacteristic<br>方法 or 属性: characteristicValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLECharacteristic<br>方法 or 属性: descriptors: Array\<BLEDescriptor>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLEDescriptor|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLEDescriptor<br>方法 or 属性: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLEDescriptor<br>方法 or 属性: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLEDescriptor<br>方法 or 属性: descriptorUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLEDescriptor<br>方法 or 属性: descriptorValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: NotifyCharacteristic|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: NotifyCharacteristic<br>方法 or 属性: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: NotifyCharacteristic<br>方法 or 属性: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: NotifyCharacteristic<br>方法 or 属性: characteristicValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: NotifyCharacteristic<br>方法 or 属性: confirm: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicReadRequest|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicReadRequest<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicReadRequest<br>方法 or 属性: transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicReadRequest<br>方法 or 属性: offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicReadRequest<br>方法 or 属性: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicReadRequest<br>方法 or 属性: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicWriteRequest|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicWriteRequest<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicWriteRequest<br>方法 or 属性: transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicWriteRequest<br>方法 or 属性: offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicWriteRequest<br>方法 or 属性: isPrep: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicWriteRequest<br>方法 or 属性: needRsp: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicWriteRequest<br>方法 or 属性: value: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicWriteRequest<br>方法 or 属性: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: CharacteristicWriteRequest<br>方法 or 属性: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorReadRequest|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorReadRequest<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorReadRequest<br>方法 or 属性: transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorReadRequest<br>方法 or 属性: offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorReadRequest<br>方法 or 属性: descriptorUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorReadRequest<br>方法 or 属性: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorReadRequest<br>方法 or 属性: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest<br>方法 or 属性: transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest<br>方法 or 属性: offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest<br>方法 or 属性: isPrep: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest<br>方法 or 属性: needRsp: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest<br>方法 or 属性: value: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest<br>方法 or 属性: descriptorUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest<br>方法 or 属性: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DescriptorWriteRequest<br>方法 or 属性: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ServerResponse|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ServerResponse<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ServerResponse<br>方法 or 属性: transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ServerResponse<br>方法 or 属性: status: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ServerResponse<br>方法 or 属性: offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ServerResponse<br>方法 or 属性: value: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLEConnectChangedState|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLEConnectChangedState<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BLEConnectChangedState<br>方法 or 属性: state: ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanResult|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanResult<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanResult<br>方法 or 属性: rssi: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanResult<br>方法 or 属性: data: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: AdvertiseSetting|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: AdvertiseSetting<br>方法 or 属性: interval?: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: AdvertiseSetting<br>方法 or 属性: txPower?: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: AdvertiseSetting<br>方法 or 属性: connectable?: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: AdvertiseData|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: AdvertiseData<br>方法 or 属性: serviceUuids: Array\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: AdvertiseData<br>方法 or 属性: manufactureData: Array\<ManufactureData>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: AdvertiseData<br>方法 or 属性: serviceData: Array\<ServiceData>;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ManufactureData|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ManufactureData<br>方法 or 属性: manufactureId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ManufactureData<br>方法 or 属性: manufactureValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ServiceData|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ServiceData<br>方法 or 属性: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ServiceData<br>方法 or 属性: serviceValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: deviceId?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: name?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: serviceUuid?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: serviceUuidMask?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: serviceSolicitationUuid?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: serviceSolicitationUuidMask?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: serviceData?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: serviceDataMask?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: manufactureId?: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: manufactureData?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanFilter<br>方法 or 属性: manufactureDataMask?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanOptions|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanOptions<br>方法 or 属性: interval?: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanOptions<br>方法 or 属性: dutyMode?: ScanDuty;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanOptions<br>方法 or 属性: matchMode?: MatchMode;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: SppOption|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: SppOption<br>方法 or 属性: uuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: SppOption<br>方法 or 属性: secure: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: SppOption<br>方法 or 属性: type: SppType;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinRequiredParam|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinRequiredParam<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PinRequiredParam<br>方法 or 属性: pinCode: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DeviceClass|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DeviceClass<br>方法 or 属性: majorClass: MajorClass;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DeviceClass<br>方法 or 属性: majorMinorClass: MajorMinorClass;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: DeviceClass<br>方法 or 属性: classOfDevice: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BondStateParam|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BondStateParam<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BondStateParam<br>方法 or 属性: state: BondState;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: StateChangeParam|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: StateChangeParam<br>方法 or 属性: deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: StateChangeParam<br>方法 or 属性: state: ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanDuty|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanDuty<br>方法 or 属性: SCAN_MODE_LOW_POWER = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanDuty<br>方法 or 属性: SCAN_MODE_BALANCED = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanDuty<br>方法 or 属性: SCAN_MODE_LOW_LATENCY = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MatchMode|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MatchMode<br>方法 or 属性: MATCH_MODE_AGGRESSIVE = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MatchMode<br>方法 or 属性: MATCH_MODE_STICKY = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileConnectionState|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileConnectionState<br>方法 or 属性: STATE_DISCONNECTED = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileConnectionState<br>方法 or 属性: STATE_CONNECTING = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileConnectionState<br>方法 or 属性: STATE_CONNECTED = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileConnectionState<br>方法 or 属性: STATE_DISCONNECTING = 3|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BluetoothState|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BluetoothState<br>方法 or 属性: STATE_OFF = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BluetoothState<br>方法 or 属性: STATE_TURNING_ON = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BluetoothState<br>方法 or 属性: STATE_ON = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BluetoothState<br>方法 or 属性: STATE_TURNING_OFF = 3|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BluetoothState<br>方法 or 属性: STATE_BLE_TURNING_ON = 4|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BluetoothState<br>方法 or 属性: STATE_BLE_ON = 5|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BluetoothState<br>方法 or 属性: STATE_BLE_TURNING_OFF = 6|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: SppType|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: SppType<br>方法 or 属性: SPP_RFCOMM|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanMode|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanMode<br>方法 or 属性: SCAN_MODE_NONE = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanMode<br>方法 or 属性: SCAN_MODE_CONNECTABLE = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanMode<br>方法 or 属性: SCAN_MODE_GENERAL_DISCOVERABLE = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanMode<br>方法 or 属性: SCAN_MODE_LIMITED_DISCOVERABLE = 3|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanMode<br>方法 or 属性: SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ScanMode<br>方法 or 属性: SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BondState|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BondState<br>方法 or 属性: BOND_STATE_INVALID = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BondState<br>方法 or 属性: BOND_STATE_BONDING = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: BondState<br>方法 or 属性: BOND_STATE_BONDED = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_MISC = 0x0000|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_COMPUTER = 0x0100|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_PHONE = 0x0200|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_NETWORKING = 0x0300|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_AUDIO_VIDEO = 0x0400|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_PERIPHERAL = 0x0500|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_IMAGING = 0x0600|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_WEARABLE = 0x0700|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_TOY = 0x0800|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_HEALTH = 0x0900|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorClass<br>方法 or 属性: MAJOR_UNCATEGORIZED = 0x1F00|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: COMPUTER_UNCATEGORIZED = 0x0100|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: COMPUTER_DESKTOP = 0x0104|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: COMPUTER_SERVER = 0x0108|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: COMPUTER_LAPTOP = 0x010C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: COMPUTER_HANDHELD_PC_PDA = 0x0110|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: COMPUTER_PALM_SIZE_PC_PDA = 0x0114|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: COMPUTER_WEARABLE = 0x0118|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: COMPUTER_TABLET = 0x011C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PHONE_UNCATEGORIZED = 0x0200|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PHONE_CELLULAR = 0x0204|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PHONE_CORDLESS = 0x0208|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PHONE_SMART = 0x020C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PHONE_MODEM_OR_GATEWAY = 0x0210|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PHONE_ISDN = 0x0214|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: NETWORK_FULLY_AVAILABLE = 0x0300|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: NETWORK_1_TO_17_UTILIZED = 0x0320|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: NETWORK_17_TO_33_UTILIZED = 0x0340|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: NETWORK_33_TO_50_UTILIZED = 0x0360|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: NETWORK_60_TO_67_UTILIZED = 0x0380|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: NETWORK_67_TO_83_UTILIZED = 0x03A0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: NETWORK_83_TO_99_UTILIZED = 0x03C0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: NETWORK_NO_SERVICE = 0x03E0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_UNCATEGORIZED = 0x0400|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_HANDSFREE = 0x0408|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_MICROPHONE = 0x0410|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_LOUDSPEAKER = 0x0414|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_HEADPHONES = 0x0418|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_CAR_AUDIO = 0x0420|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_SET_TOP_BOX = 0x0424|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_HIFI_AUDIO = 0x0428|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_VCR = 0x042C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_VIDEO_CAMERA = 0x0430|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_CAMCORDER = 0x0434|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_VIDEO_MONITOR = 0x0438|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_KEYBOARD = 0x0540|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_POINTING_DEVICE = 0x0580|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_KEYBOARD_POINTING = 0x05C0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_UNCATEGORIZED = 0x0500|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_JOYSTICK = 0x0504|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_GAMEPAD = 0x0508|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_REMOTE_CONTROL = 0x05C0|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_SENSING_DEVICE = 0x0510|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_DIGITIZER_TABLET = 0x0514|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_CARD_READER = 0x0518|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_DIGITAL_PEN = 0x051C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_SCANNER_RFID = 0x0520|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: PERIPHERAL_GESTURAL_INPUT = 0x0522|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: IMAGING_UNCATEGORIZED = 0x0600|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: IMAGING_DISPLAY = 0x0610|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: IMAGING_CAMERA = 0x0620|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: IMAGING_SCANNER = 0x0640|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: IMAGING_PRINTER = 0x0680|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: WEARABLE_UNCATEGORIZED = 0x0700|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: WEARABLE_WRIST_WATCH = 0x0704|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: WEARABLE_PAGER = 0x0708|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: WEARABLE_JACKET = 0x070C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: WEARABLE_HELMET = 0x0710|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: WEARABLE_GLASSES = 0x0714|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: TOY_UNCATEGORIZED = 0x0800|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: TOY_ROBOT = 0x0804|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: TOY_VEHICLE = 0x0808|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: TOY_DOLL_ACTION_FIGURE = 0x080C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: TOY_CONTROLLER = 0x0810|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: TOY_GAME = 0x0814|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_UNCATEGORIZED = 0x0900|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_BLOOD_PRESSURE = 0x0904|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_THERMOMETER = 0x0908|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_WEIGHING = 0x090C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_GLUCOSE = 0x0910|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_PULSE_OXIMETER = 0x0914|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_PULSE_RATE = 0x0918|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_DATA_DISPLAY = 0x091C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_STEP_COUNTER = 0x0920|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_PEAK_FLOW_MONITOR = 0x0928|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_MEDICATION_MONITOR = 0x092C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_KNEE_PROSTHESIS = 0x0930|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_ANKLE_PROSTHESIS = 0x0934|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_GENERIC_HEALTH_MANAGER = 0x0938|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: MajorMinorClass<br>方法 or 属性: HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PlayingState|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PlayingState<br>方法 or 属性: STATE_NOT_PLAYING|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: PlayingState<br>方法 or 属性: STATE_PLAYING|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileId|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileId<br>方法 or 属性: PROFILE_A2DP_SOURCE = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileId<br>方法 or 属性: PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileId<br>方法 or 属性: PROFILE_HID_HOST = 6|@ohos.bluetoothManager.d.ts|
|新增|NA|模块名: ohos.bluetoothManager<br>类名: ProfileId<br>方法 or 属性: PROFILE_PAN_NETWORK = 7|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：connection<br>方法or属性：function getAppNet(callback: AsyncCallback\<NetHandle>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection<br>方法or属性：function getAppNet(): Promise\<NetHandle>;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection<br>方法or属性：function setAppNet(netHandle: NetHandle, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection<br>方法or属性：function setAppNet(netHandle: NetHandle): Promise\<void>;|@ohos.net.connection.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：password?: string;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性：certEntry: Uint8Array;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig<br>方法or属性：certEntry: Uint8Array;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性：certPassword: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig<br>方法or属性：certPassword: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：bssid?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：isHiddenSsid?: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：creatorUid?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：disableReason?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：netId?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：randomMacType?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：randomMacAddr?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：ipType?: IpType;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：staticIp?: IpConfig;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig<br>方法or属性：eapConfig?: WifiEapConfig;|@ohos.wifiManager.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:bluetooth<br>方法 or 属性:function getProfileInst(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile \| HidHostProfile \| PanProfile;|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: HidHostProfile|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: HidHostProfile<br>方法 or 属性：connect(device: string): boolean;|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: HidHostProfile<br>方法 or 属性：disconnect(device: string): boolean;|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: HidHostProfile<br>方法 or 属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: HidHostProfile<br>方法 or 属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: PanProfile|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: PanProfile<br>方法 or 属性：disconnect(device: string): boolean;|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: PanProfile<br>方法 or 属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: PanProfile<br>方法 or 属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: PanProfile<br>方法 or 属性：setTethering(enable: boolean): void;|NA|@ohos.bluetooth.d.ts|
|删除|模块名: ohos.bluetooth<br>类名: PanProfile<br>方法 or 属性：isTetheringOn(): boolean;|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ScanFilter<br>方法 or 属性:serviceUuidMask?: string;|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ScanFilter<br>方法 or 属性:serviceSolicitationUuid?: string;|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ScanFilter<br>方法 or 属性:serviceSolicitationUuidMask?: string;|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ScanFilter<br>方法 or 属性:serviceData?: ArrayBuffer;|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ScanFilter<br>方法 or 属性:serviceDataMask?: ArrayBuffer;|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ScanFilter<br>方法 or 属性:manufactureId?: number;|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ScanFilter<br>方法 or 属性:manufactureData?: ArrayBuffer;|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ScanFilter<br>方法 or 属性:manufactureDataMask?: ArrayBuffer;|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ProfileId<br>方法 or 属性:PROFILE_HID_HOST = 6|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.bluetooth<br>类名:ProfileId<br>方法 or 属性:PROFILE_PAN_NETWORK = 7|NA|@ohos.bluetooth.d.ts|
|删除|模块名：ohos.net.socket<br>类名:TLSSecureOptions<br>方法 or 属性:passwd?: string;|NA|@ohos.net.socket.d.ts|
|废弃版本有变化|类名：bluetooth<br>废弃版本：N/A|类名：bluetooth<br>废弃版本：9<br>代替接口：ohos.bluetoothManager |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function getState(): BluetoothState;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function getState(): BluetoothState;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.getState     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function getBtConnectionState(): ProfileConnectionState;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function getBtConnectionState(): ProfileConnectionState;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.getBtConnectionState     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function pairDevice(deviceId: string): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function pairDevice(deviceId: string): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.pairDevice     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function cancelPairedDevice(deviceId: string): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function cancelPairedDevice(deviceId: string): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.cancelPairedDevice     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function getRemoteDeviceName(deviceId: string): string;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function getRemoteDeviceName(deviceId: string): string;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.getRemoteDeviceName     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.getRemoteDeviceClass     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function enableBluetooth(): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function enableBluetooth(): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.enableBluetooth     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function disableBluetooth(): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function disableBluetooth(): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.disableBluetooth     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function getLocalName(): string;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function getLocalName(): string;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.getLocalName     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function getPairedDevices(): Array\<string>;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function getPairedDevices(): Array\<string>;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.getPairedDevices     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function getProfileConnState(profileId: ProfileId): ProfileConnectionState;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function getProfileConnState(profileId: ProfileId): ProfileConnectionState;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.getProfileConnectionState     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function setDevicePairingConfirmation(device: string, accept: boolean): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function setDevicePairingConfirmation(device: string, accept: boolean): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.setDevicePairingConfirmation     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function setLocalName(name: string): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function setLocalName(name: string): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.setLocalName     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function setBluetoothScanMode(mode: ScanMode, duration: number): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function setBluetoothScanMode(mode: ScanMode, duration: number): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.setBluetoothScanMode     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function getBluetoothScanMode(): ScanMode;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function getBluetoothScanMode(): ScanMode;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.getBluetoothScanMode     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function startBluetoothDiscovery(): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function startBluetoothDiscovery(): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.startBluetoothDiscovery     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function stopBluetoothDiscovery(): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function stopBluetoothDiscovery(): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.stopBluetoothDiscovery     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function on(type: "bondStateChange", callback: Callback\<BondStateParam>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function on(type: "bondStateChange", callback: Callback\<BondStateParam>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function on(type: "stateChange", callback: Callback\<BluetoothState>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function on(type: "stateChange", callback: Callback\<BluetoothState>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function off(type: "stateChange", callback?: Callback\<BluetoothState>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function off(type: "stateChange", callback?: Callback\<BluetoothState>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.sppListen     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.sppAccept     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.sppConnect     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function sppCloseServerSocket(socket: number): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function sppCloseServerSocket(socket: number): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.sppCloseServerSocket     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function sppCloseClientSocket(socket: number): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function sppCloseClientSocket(socket: number): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.sppCloseClientSocket     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function sppWrite(clientSocket: number, data: ArrayBuffer): boolean;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function sppWrite(clientSocket: number, data: ArrayBuffer): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.sppWrite     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth<br>方法 or 属性：function getProfile(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile;<br>废弃版本：N/A|类名：bluetooth<br>方法 or 属性：function getProfile(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.getProfileInstance     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BaseProfile<br>废弃版本：N/A|类名：BaseProfile<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BaseProfile     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BaseProfile<br>方法 or 属性：getConnectionDevices(): Array\<string>;<br>废弃版本：N/A|类名：BaseProfile<br>方法 or 属性：getConnectionDevices(): Array\<string>;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BaseProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BaseProfile<br>方法 or 属性：getDeviceState(device: string): ProfileConnectionState;<br>废弃版本：N/A|类名：BaseProfile<br>方法 or 属性：getDeviceState(device: string): ProfileConnectionState;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BaseProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile<br>废弃版本：N/A|类名：A2dpSourceProfile<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile<br>方法 or 属性：connect(device: string): boolean;<br>废弃版本：N/A|类名：A2dpSourceProfile<br>方法 or 属性：connect(device: string): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>废弃版本：N/A|类名：A2dpSourceProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile<br>方法 or 属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>废弃版本：N/A|类名：A2dpSourceProfile<br>方法 or 属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile.on|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile<br>方法 or 属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>废弃版本：N/A|类名：A2dpSourceProfile<br>方法 or 属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile.off|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile<br>方法 or 属性：getPlayingState(device: string): PlayingState;<br>废弃版本：N/A|类名：A2dpSourceProfile<br>方法 or 属性：getPlayingState(device: string): PlayingState;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile<br>废弃版本：N/A|类名：HandsFreeAudioGatewayProfile<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：connect(device: string): boolean;<br>废弃版本：N/A|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：connect(device: string): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>废弃版本：N/A|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>废弃版本：N/A|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile.on|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>废弃版本：N/A|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile.off|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE<br>方法 or 属性：function createGattServer(): GattServer;<br>废弃版本：N/A|类名：BLE<br>方法 or 属性：function createGattServer(): GattServer;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLE.createGattServer         |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE<br>方法 or 属性：function createGattClientDevice(deviceId: string): GattClientDevice;<br>废弃版本：N/A|类名：BLE<br>方法 or 属性：function createGattClientDevice(deviceId: string): GattClientDevice;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLE.createGattClientDevice         |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE<br>方法 or 属性：function getConnectedBLEDevices(): Array\<string>;<br>废弃版本：N/A|类名：BLE<br>方法 or 属性：function getConnectedBLEDevices(): Array\<string>;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLE.getConnectedBLEDevices         |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE<br>方法 or 属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>废弃版本：N/A|类名：BLE<br>方法 or 属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLE.startBLEScan         |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE<br>方法 or 属性：function stopBLEScan(): void;<br>废弃版本：N/A|类名：BLE<br>方法 or 属性：function stopBLEScan(): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLE.stopBLEScan         |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE<br>方法 or 属性：function on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void;<br>废弃版本：N/A|类名：BLE<br>方法 or 属性：function on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLE.on|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE<br>方法 or 属性：function off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void;<br>废弃版本：N/A|类名：BLE<br>方法 or 属性：function off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLE.off|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>废弃版本：N/A|类名：GattServer<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：stopAdvertising(): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：stopAdvertising(): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：addService(service: GattService): boolean;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：addService(service: GattService): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：removeService(serviceUuid: string): boolean;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：removeService(serviceUuid: string): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：close(): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：close(): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：sendResponse(serverResponse: ServerResponse): boolean;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：sendResponse(serverResponse: ServerResponse): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：on(type: "characteristicRead", callback: Callback\<CharacteristicReadReq>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：on(type: "characteristicRead", callback: Callback\<CharacteristicReadReq>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：off(type: "characteristicRead", callback?: Callback\<CharacteristicReadReq>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：off(type: "characteristicRead", callback?: Callback\<CharacteristicReadReq>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteReq>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteReq>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteReq>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteReq>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：on(type: "descriptorRead", callback: Callback\<DescriptorReadReq>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：on(type: "descriptorRead", callback: Callback\<DescriptorReadReq>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：off(type: "descriptorRead", callback?: Callback\<DescriptorReadReq>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：off(type: "descriptorRead", callback?: Callback\<DescriptorReadReq>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteReq>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteReq>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer<br>方法 or 属性：off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>废弃版本：N/A|类名：GattServer<br>方法 or 属性：off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>废弃版本：N/A|类名：GattClientDevice<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：connect(): boolean;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：connect(): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：disconnect(): boolean;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：disconnect(): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：close(): boolean;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：close(): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：getDeviceName(callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：getDeviceName(callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：getDeviceName(): Promise\<string>;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：getDeviceName(): Promise\<string>;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：getServices(): Promise\<Array\<GattService>>;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：getServices(): Promise\<Array\<GattService>>;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：writeCharacteristicValue(characteristic: BLECharacteristic): boolean;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：writeCharacteristicValue(characteristic: BLECharacteristic): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：writeDescriptorValue(descriptor: BLEDescriptor): boolean;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：writeDescriptorValue(descriptor: BLEDescriptor): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：getRssiValue(callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：getRssiValue(callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：getRssiValue(): Promise\<number>;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：getRssiValue(): Promise\<number>;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：setBLEMtuSize(mtu: number): boolean;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：setBLEMtuSize(mtu: number): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice<br>方法 or 属性：off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>废弃版本：N/A|类名：GattClientDevice<br>方法 or 属性：off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattService<br>废弃版本：N/A|类名：GattService<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.GattService     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLECharacteristic<br>废弃版本：N/A|类名：BLECharacteristic<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLECharacteristic     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEDescriptor<br>废弃版本：N/A|类名：BLEDescriptor<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLEDescriptor     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic<br>废弃版本：N/A|类名：NotifyCharacteristic<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.NotifyCharacteristic     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicReadReq<br>废弃版本：N/A|类名：CharacteristicReadReq<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.CharacteristicReadRequest     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq<br>废弃版本：N/A|类名：CharacteristicWriteReq<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorReadReq<br>废弃版本：N/A|类名：DescriptorReadReq<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq<br>废弃版本：N/A|类名：DescriptorWriteReq<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServerResponse<br>废弃版本：N/A|类名：ServerResponse<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ServerResponse     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEConnectChangedState<br>废弃版本：N/A|类名：BLEConnectChangedState<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BLEConnectChangedState     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanResult<br>废弃版本：N/A|类名：ScanResult<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ScanResult     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseSetting<br>废弃版本：N/A|类名：AdvertiseSetting<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.AdvertiseSetting     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseData<br>废弃版本：N/A|类名：AdvertiseData<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.AdvertiseData     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ManufactureData<br>废弃版本：N/A|类名：ManufactureData<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ManufactureData     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServiceData<br>废弃版本：N/A|类名：ServiceData<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ServiceData     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanFilter<br>废弃版本：N/A|类名：ScanFilter<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ScanFilter     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanOptions<br>废弃版本：N/A|类名：ScanOptions<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ScanOptions     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：SppOption<br>废弃版本：N/A|类名：SppOption<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.SppOption     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：PinRequiredParam<br>废弃版本：N/A|类名：PinRequiredParam<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.PinRequiredParam     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DeviceClass<br>废弃版本：N/A|类名：DeviceClass<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.DeviceClass     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BondStateParam<br>废弃版本：N/A|类名：BondStateParam<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BondStateParam     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanDuty<br>废弃版本：N/A|类名：ScanDuty<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ScanDuty     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MatchMode<br>废弃版本：N/A|类名：MatchMode<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.MatchMode     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileConnectionState<br>废弃版本：N/A|类名：ProfileConnectionState<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ProfileConnectionState     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BluetoothState<br>废弃版本：N/A|类名：BluetoothState<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BluetoothState     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：SppType<br>废弃版本：N/A|类名：SppType<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.SppType     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanMode<br>废弃版本：N/A|类名：ScanMode<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ScanMode     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BondState<br>废弃版本：N/A|类名：BondState<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.BondState     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass<br>废弃版本：N/A|类名：MajorClass<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.MajorClass     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass<br>废弃版本：N/A|类名：MajorMinorClass<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.MajorMinorClass     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：StateChangeParam<br>废弃版本：N/A|类名：StateChangeParam<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.StateChangeParam     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：PlayingState<br>废弃版本：N/A|类名：PlayingState<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.PlayingState     |@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileId<br>废弃版本：N/A|类名：ProfileId<br>废弃版本：9<br>代替接口：ohos.bluetoothManager/bluetoothManager.ProfileId     |@ohos.bluetooth.d.ts|
|权限有变化|类名：connection<br>方法 or 属性：function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：connection<br>方法 or 属性：function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：connection<br>方法 or 属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：connection<br>方法 or 属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string): Promise\<NetAddress>;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string): Promise\<NetAddress>;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getDefaultNet(): Promise\<NetHandle>;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function hasDefaultNet(): Promise\<boolean>;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function enableAirplaneMode(): Promise\<void>;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function disableAirplaneMode(): Promise\<void>;<br>错误码内容: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function reportNetConnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：connection<br>方法 or 属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetConnection<br>方法 or 属性：register(callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 2100002, 2100003, 2101008, 2101022|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetConnection<br>方法 or 属性：unregister(callback: AsyncCallback\<void>): void;<br>错误码内容: 2100002, 2100003, 2101007|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;<br>错误码内容: 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string): Promise\<NetAddress>;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：ethernet<br>方法 or 属性：function getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2201005|@ohos.net.ethernet.d.ts|
|新增(错误码)|NA|类名：ethernet<br>方法 or 属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2201005|@ohos.net.ethernet.d.ts|
|新增(错误码)|NA|类名：ethernet<br>方法 or 属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2201004, 2201005, 2201006, 2201007|@ohos.net.ethernet.d.ts|
|新增(错误码)|NA|类名：ethernet<br>方法 or 属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2201004, 2201005, 2201006, 2201007|@ohos.net.ethernet.d.ts|
|新增(错误码)|NA|类名：ethernet<br>方法 or 属性：function isIfaceActive(iface: string, callback: AsyncCallback\<number>): void;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2201005|@ohos.net.ethernet.d.ts|
|新增(错误码)|NA|类名：ethernet<br>方法 or 属性：function isIfaceActive(iface: string): Promise\<number>;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2201005|@ohos.net.ethernet.d.ts|
|新增(错误码)|NA|类名：ethernet<br>方法 or 属性：function getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void;<br>错误码内容: 201, 2200002, 2200003|@ohos.net.ethernet.d.ts|
|新增(错误码)|NA|类名：ethernet<br>方法 or 属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>错误码内容: 201, 2200002, 2200003|@ohos.net.ethernet.d.ts|
|新增(错误码)|NA|类名：HttpRequest<br>方法 or 属性：request(url: string, callback: AsyncCallback\<HttpResponse>): void;<br>错误码内容: 401, 201, 2300001, 2300003, 2300005, 2300006, 2300007, 2300008, 2300009, 2300016, 2300018, 2300023, 2300025, 2300026, 2300027, 2300028, 2300047, 2300052, 2300055, 2300056, 2300058, 2300059, 2300060, 2300061, 2300063, 2300070, 2300073, 2300077, 2300078, 2300094, 2300999|@ohos.net.http.d.ts|
|新增(错误码)|NA|类名：HttpRequest<br>方法 or 属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>错误码内容: 401, 201, 2300001, 2300003, 2300005, 2300006, 2300007, 2300008, 2300009, 2300016, 2300018, 2300023, 2300025, 2300026, 2300027, 2300028, 2300047, 2300052, 2300055, 2300056, 2300058, 2300059, 2300060, 2300061, 2300063, 2300070, 2300073, 2300077, 2300078, 2300094, 2300999|@ohos.net.http.d.ts|
|新增(错误码)|NA|类名：HttpRequest<br>方法 or 属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>错误码内容: 401, 201, 2300001, 2300003, 2300005, 2300006, 2300007, 2300008, 2300009, 2300016, 2300018, 2300023, 2300025, 2300026, 2300027, 2300028, 2300047, 2300052, 2300055, 2300056, 2300058, 2300059, 2300060, 2300061, 2300063, 2300070, 2300073, 2300077, 2300078, 2300094, 2300999|@ohos.net.http.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function isSharingSupported(callback: AsyncCallback\<boolean>): void;<br>错误码内容: 201, 2200002, 2200003, 2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function isSharingSupported(): Promise\<boolean>;<br>错误码内容: 201, 2200002, 2200003, 2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function isSharing(callback: AsyncCallback\<boolean>): void;<br>错误码内容: 201, 2200002, 2200003, 2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function isSharing(): Promise\<boolean>;<br>错误码内容: 201, 2200002, 2200003, 2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2202004, 2202005, 2202006, 2202009, 2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2202004, 2202005, 2202006, 2202009, 2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2202004, 2202005, 2202006, 2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003, 2202004, 2202005, 2202006, 2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getStatsRxBytes(callback: AsyncCallback\<number>): void;<br>错误码内容: 201, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getStatsRxBytes(): Promise\<number>;<br>错误码内容: 201, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getStatsTxBytes(callback: AsyncCallback\<number>): void;<br>错误码内容: 201, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getStatsTxBytes(): Promise\<number>;<br>错误码内容: 201, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getStatsTotalBytes(callback: AsyncCallback\<number>): void;<br>错误码内容: 201, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getStatsTotalBytes(): Promise\<number>;<br>错误码内容: 201, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>错误码内容: 201, 401, 2200001, 2200002, 2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function on(type: 'sharingStateChange', callback: Callback\<boolean>): void;<br>错误码内容: 201, 401|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;<br>错误码内容: 201, 401|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>错误码内容: 201, 401|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>错误码内容: 201, 401|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;<br>错误码内容: 201, 401|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：sharing<br>方法 or 属性：function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;<br>错误码内容: 201, 401|@ohos.net.sharing.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：bind(address: NetAddress): Promise\<void>;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：send(options: UDPSendOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：send(options: UDPSendOptions): Promise\<void>;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：close(callback: AsyncCallback\<void>): void;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：close(): Promise\<void>;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：getState(): Promise\<SocketStateBase>;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：UDPSocket<br>方法 or 属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：bind(address: NetAddress): Promise\<void>;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：connect(options: TCPConnectOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：connect(options: TCPConnectOptions): Promise\<void>;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：send(options: TCPSendOptions): Promise\<void>;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：close(callback: AsyncCallback\<void>): void;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：close(): Promise\<void>;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：getRemoteAddress(): Promise\<NetAddress>;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：getState(): Promise\<SocketStateBase>;<br>错误码内容: 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：TCPSocket<br>方法 or 属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>错误码内容: 401, 201|@ohos.net.socket.d.ts|
|新增(错误码)|NA|类名：WebSocket<br>方法 or 属性：connect(url: string, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 201|@ohos.net.webSocket.d.ts|
|新增(错误码)|NA|类名：WebSocket<br>方法 or 属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 201|@ohos.net.webSocket.d.ts|
|新增(错误码)|NA|类名：WebSocket<br>方法 or 属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>错误码内容: 401, 201|@ohos.net.webSocket.d.ts|
|新增(错误码)|NA|类名：WebSocket<br>方法 or 属性：send(data: string \| ArrayBuffer, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 201|@ohos.net.webSocket.d.ts|
|新增(错误码)|NA|类名：WebSocket<br>方法 or 属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>错误码内容: 401, 201|@ohos.net.webSocket.d.ts|
|新增(错误码)|NA|类名：WebSocket<br>方法 or 属性：close(callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 201|@ohos.net.webSocket.d.ts|
|新增(错误码)|NA|类名：WebSocket<br>方法 or 属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>错误码内容: 401, 201|@ohos.net.webSocket.d.ts|
|新增(错误码)|NA|类名：WebSocket<br>方法 or 属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>错误码内容: 401, 201|@ohos.net.webSocket.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：connection<br>方法 or 属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function enableAirplaneMode(): Promise\<void>;<br>权限:N/A|类名：connection<br>方法 or 属性：function enableAirplaneMode(): Promise\<void>;<br>权限:ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：connection<br>方法 or 属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function disableAirplaneMode(): Promise\<void>;<br>权限:N/A|类名：connection<br>方法 or 属性：function disableAirplaneMode(): Promise\<void>;<br>权限:ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|函数有变化|类名：RemoteProxy<br>方法 or 属性：unregisterDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>|类名：RemoteProxy<br>方法 or 属性：unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void;<br>|@ohos.rpc.d.ts|
