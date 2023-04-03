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
|新增|NA|类名：connectedTag<br>方法or属性：function initialize(): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function uninitialize(): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function read(): Promise\<number[]>;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function read(callback: AsyncCallback\<number[]>): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function write(data: number[]): Promise\<void>;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag<br>方法or属性：function write(data: number[], callback: AsyncCallback\<void>): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connection<br>方法or属性：function getDefaultNetSync(): NetHandle;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection<br>方法or属性：function isDefaultNetMetered(callback: AsyncCallback\<boolean>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection<br>方法or属性：function getAppNet(callback: AsyncCallback\<NetHandle>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection<br>方法or属性：function getAppNet(): Promise\<NetHandle>;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection<br>方法or属性：function setAppNet(netHandle: NetHandle, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection<br>方法or属性：function setAppNet(netHandle: NetHandle): Promise\<void>;|@ohos.net.connection.d.ts|
|新增|NA|类名：NetHandle<br>方法or属性：bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：NetHandle<br>方法or属性：bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;|@ohos.net.connection.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function isIfaceActive(iface: string, callback: AsyncCallback\<number>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function isIfaceActive(iface: string): Promise\<number>;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: ethernet<br>方法 or 属性: function getAllActiveIfaces(): Promise\<Array\<string>>;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: InterfaceConfiguration|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: InterfaceConfiguration<br>方法 or 属性: mode: IPSetMode;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: InterfaceConfiguration<br>方法 or 属性: ipAddr: string;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: InterfaceConfiguration<br>方法 or 属性: route: string;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: InterfaceConfiguration<br>方法 or 属性: gateway: string;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: InterfaceConfiguration<br>方法 or 属性: netMask: string;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: InterfaceConfiguration<br>方法 or 属性: dnsServers: string;|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: IPSetMode|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: IPSetMode<br>方法 or 属性: STATIC = 0|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.ethernet<br>类名: IPSetMode<br>方法 or 属性: DHCP = 1|@ohos.net.ethernet.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequestOptions<br>方法 or 属性：expectDataType?: HttpDataType;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions<br>方法or属性：expectDataType?: HttpDataType;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequestOptions<br>方法 or 属性：usingCache?: boolean;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions<br>方法or属性：usingCache?: boolean;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequestOptions<br>方法 or 属性：priority?: number;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions<br>方法or属性：priority?: number;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpRequestOptions<br>方法 or 属性：usingProtocol?: HttpProtocol;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions<br>方法or属性：usingProtocol?: HttpProtocol;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpProtocol|@ohos.net.http.d.ts|
|新增|NA|类名：HttpProtocol<br>方法or属性：|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpProtocol<br>方法 or 属性：HTTP1_1|@ohos.net.http.d.ts|
|新增|NA|类名：HttpProtocol<br>方法or属性：HTTP1_1|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpProtocol<br>方法 or 属性：HTTP2|@ohos.net.http.d.ts|
|新增|NA|类名：HttpProtocol<br>方法or属性：HTTP2|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpDataType|@ohos.net.http.d.ts|
|新增|NA|类名：HttpDataType<br>方法or属性：|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpDataType<br>方法 or 属性：STRING|@ohos.net.http.d.ts|
|新增|NA|类名：HttpDataType<br>方法or属性：STRING|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpDataType<br>方法 or 属性：OBJECT = 1|@ohos.net.http.d.ts|
|新增|NA|类名：HttpDataType<br>方法or属性：OBJECT = 1|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpDataType<br>方法 or 属性：ARRAY_BUFFER = 2|@ohos.net.http.d.ts|
|新增|NA|类名：HttpDataType<br>方法or属性：ARRAY_BUFFER = 2|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpResponse<br>方法 or 属性：resultType: HttpDataType;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponse<br>方法or属性：resultType: HttpDataType;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: http<br>方法 or 属性：function createHttpResponseCache(cacheSize?: number): HttpResponseCache;|@ohos.net.http.d.ts|
|新增|NA|类名：http<br>方法or属性：function createHttpResponseCache(cacheSize?: number): HttpResponseCache;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpResponseCache|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponseCache<br>方法or属性：|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpResponseCache<br>方法 or 属性：flush(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponseCache<br>方法or属性：flush(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpResponseCache<br>方法 or 属性：flush(): Promise\<void>;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponseCache<br>方法or属性：flush(): Promise\<void>;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpResponseCache<br>方法 or 属性：delete(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponseCache<br>方法or属性：delete(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.http<br>类名: HttpResponseCache<br>方法 or 属性：delete(): Promise\<void>;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponseCache<br>方法or属性：delete(): Promise\<void>;|@ohos.net.http.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function isSharingSupported(callback: AsyncCallback\<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function isSharingSupported(): Promise\<boolean>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function isSharing(callback: AsyncCallback\<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function isSharing(): Promise\<boolean>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function startSharing(type: SharingIfaceType): Promise\<void>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function stopSharing(type: SharingIfaceType): Promise\<void>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsRxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsRxBytes(): Promise\<number>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsTxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsTxBytes(): Promise\<number>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsTotalBytes(callback: AsyncCallback\<number>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getStatsTotalBytes(): Promise\<number>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function on(type: 'sharingStateChange', callback: Callback\<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: sharing<br>方法 or 属性: function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceState|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceState<br>方法 or 属性: SHARING_NIC_SERVING = 1|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceState<br>方法 or 属性: SHARING_NIC_CAN_SERVER = 2|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceState<br>方法 or 属性: SHARING_NIC_ERROR = 3|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceType|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceType<br>方法 or 属性: SHARING_WIFI = 0|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceType<br>方法 or 属性: SHARING_USB = 1|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.sharing<br>类名: SharingIfaceType<br>方法 or 属性: SHARING_BLUETOOTH = 2|@ohos.net.sharing.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: socket<br>方法 or 属性：function constructTLSSocketInstance(): TLSSocket;|@ohos.net.socket.d.ts|
|新增|NA|类名：socket<br>方法or属性：function constructTLSSocketInstance(): TLSSocket;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPExtraOptions<br>方法or属性：socketLinger?: {on: boolean, linger: number};|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：bind(address: NetAddress): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：bind(address: NetAddress): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getRemoteAddress(): Promise\<NetAddress>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getState(callback: AsyncCallback\<SocketStateBase>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getState(): Promise\<SocketStateBase>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getState(): Promise\<SocketStateBase>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：on(type: 'connect' \| 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：on(type: 'connect' \| 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：on(type: 'connect' \| 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：on(type: 'connect' \| 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：off(type: 'connect' \| 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：off(type: 'connect' \| 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：off(type: 'connect' \| 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：off(type: 'connect' \| 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getRemoteCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getRemoteCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getRemoteCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getProtocol(callback: AsyncCallback\<string>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getProtocol(callback: AsyncCallback\<string>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getProtocol(): Promise\<string>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getProtocol(): Promise\<string>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getCipherSuite(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getCipherSuite(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getCipherSuite(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：getSignatureAlgorithms(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：connect(options: TLSConnectOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：connect(options: TLSConnectOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：connect(options: TLSConnectOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：connect(options: TLSConnectOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：send(data: string, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：send(data: string, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：send(data: string): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：send(data: string): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：close(callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：close(callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSocket<br>方法 or 属性：close(): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket<br>方法or属性：close(): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSecureOptions|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSecureOptions<br>方法 or 属性：ca: string \| Array\<string>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：ca: string \| Array\<string>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSecureOptions<br>方法 or 属性：cert?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：cert?: string;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSecureOptions<br>方法 or 属性：key?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：key?: string;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSecureOptions<br>方法 or 属性：password?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：password?: string;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSecureOptions<br>方法 or 属性：protocols?: Protocol \| Array\<Protocol>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：protocols?: Protocol \| Array\<Protocol>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSecureOptions<br>方法 or 属性：useRemoteCipherPrefer?: boolean;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：useRemoteCipherPrefer?: boolean;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSecureOptions<br>方法 or 属性：signatureAlgorithms?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：signatureAlgorithms?: string;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSSecureOptions<br>方法 or 属性：cipherSuite?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions<br>方法or属性：cipherSuite?: string;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSConnectOptions|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSConnectOptions<br>方法or属性：|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSConnectOptions<br>方法 or 属性：address: NetAddress;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSConnectOptions<br>方法or属性：address: NetAddress;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSConnectOptions<br>方法 or 属性：secureOptions: TLSSecureOptions;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSConnectOptions<br>方法or属性：secureOptions: TLSSecureOptions;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: TLSConnectOptions<br>方法 or 属性：ALPNProtocols?: Array\<string>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSConnectOptions<br>方法or属性：ALPNProtocols?: Array\<string>;|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: Protocol|@ohos.net.socket.d.ts|
|新增|NA|类名：Protocol<br>方法or属性：|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: Protocol<br>方法 or 属性：TLSv12 = "TLSv1.2"|@ohos.net.socket.d.ts|
|新增|NA|类名：Protocol<br>方法or属性：TLSv12 = "TLSv1.2"|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.net.socket<br>类名: Protocol<br>方法 or 属性：TLSv13 = "TLSv1.3"|@ohos.net.socket.d.ts|
|新增|NA|类名：Protocol<br>方法or属性：TLSv13 = "TLSv1.3"|@ohos.net.socket.d.ts|
|新增|NA|模块名: ohos.nfc.cardEmulation<br>类名: CardType|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：CardType<br>方法or属性：|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|模块名: ohos.nfc.cardEmulation<br>类名: CardType<br>方法 or 属性：PAYMENT = "payment"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：CardType<br>方法or属性：PAYMENT = "payment"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|模块名: ohos.nfc.cardEmulation<br>类名: CardType<br>方法 or 属性：OTHER = "other"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：CardType<br>方法or属性：OTHER = "other"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：cardEmulation<br>方法or属性：function hasHceCapability(): boolean;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：cardEmulation<br>方法or属性：function isDefaultService(elementName: ElementName, type: CardType): boolean;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService<br>方法or属性：start(elementName: ElementName, aidList: string[]): void|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService<br>方法or属性：stop(elementName: ElementName): void|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService<br>方法or属性：transmit(response: number[]): Promise\<void>;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService<br>方法or属性：transmit(response: number[], callback: AsyncCallback\<void>): void;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：nfcController<br>方法or属性：function enableNfc(): void|@ohos.nfc.controller.d.ts|
|新增|NA|类名：nfcController<br>方法or属性：function disableNfc(): void|@ohos.nfc.controller.d.ts|
|新增|NA|类名：tag<br>方法or属性：const NDEF_FORMATABLE = 7;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: TnfType|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType<br>方法or属性：|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: TnfType<br>方法 or 属性：TNF_EMPTY = 0x0|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType<br>方法or属性：TNF_EMPTY = 0x0|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: TnfType<br>方法 or 属性：TNF_WELL_KNOWN = 0x1|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType<br>方法or属性：TNF_WELL_KNOWN = 0x1|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: TnfType<br>方法 or 属性：TNF_MEDIA = 0x2|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType<br>方法or属性：TNF_MEDIA = 0x2|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: TnfType<br>方法 or 属性：TNF_ABSOLUTE_URI = 0x3|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType<br>方法or属性：TNF_ABSOLUTE_URI = 0x3|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: TnfType<br>方法 or 属性：TNF_EXT_APP = 0x4|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType<br>方法or属性：TNF_EXT_APP = 0x4|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: TnfType<br>方法 or 属性：TNF_UNKNOWN = 0x5|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType<br>方法or属性：TNF_UNKNOWN = 0x5|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: TnfType<br>方法 or 属性：TNF_UNCHANGED = 0x6|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType<br>方法or属性：TNF_UNCHANGED = 0x6|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NfcForumType|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType<br>方法or属性：|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NfcForumType<br>方法 or 属性：NFC_FORUM_TYPE_1 = 1|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType<br>方法or属性：NFC_FORUM_TYPE_1 = 1|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NfcForumType<br>方法 or 属性：NFC_FORUM_TYPE_2 = 2|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType<br>方法or属性：NFC_FORUM_TYPE_2 = 2|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NfcForumType<br>方法 or 属性：NFC_FORUM_TYPE_3 = 3|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType<br>方法or属性：NFC_FORUM_TYPE_3 = 3|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NfcForumType<br>方法 or 属性：NFC_FORUM_TYPE_4 = 4|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType<br>方法or属性：NFC_FORUM_TYPE_4 = 4|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NfcForumType<br>方法 or 属性：MIFARE_CLASSIC = 101|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType<br>方法or属性：MIFARE_CLASSIC = 101|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：const RTD_TEXT: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：const RTD_URI: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicType|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicType<br>方法or属性：|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicType<br>方法 or 属性：TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicType<br>方法or属性：TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicType<br>方法 or 属性：TYPE_CLASSIC = 1|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicType<br>方法or属性：TYPE_CLASSIC = 1|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicType<br>方法 or 属性：TYPE_PLUS = 2|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicType<br>方法or属性：TYPE_PLUS = 2|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicType<br>方法 or 属性：TYPE_PRO = 3|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicType<br>方法or属性：TYPE_PRO = 3|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicSize|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicSize<br>方法or属性：|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicSize<br>方法 or 属性：MC_SIZE_MINI = 320|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicSize<br>方法or属性：MC_SIZE_MINI = 320|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicSize<br>方法 or 属性：MC_SIZE_1K = 1024|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicSize<br>方法or属性：MC_SIZE_1K = 1024|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicSize<br>方法 or 属性：MC_SIZE_2K = 2048|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicSize<br>方法or属性：MC_SIZE_2K = 2048|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareClassicSize<br>方法 or 属性：MC_SIZE_4K = 4096|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicSize<br>方法or属性：MC_SIZE_4K = 4096|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareUltralightType|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareUltralightType<br>方法or属性：|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareUltralightType<br>方法 or 属性：TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareUltralightType<br>方法or属性：TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareUltralightType<br>方法 or 属性：TYPE_ULTRALIGHT = 1|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareUltralightType<br>方法or属性：TYPE_ULTRALIGHT = 1|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: MifareUltralightType<br>方法 or 属性：TYPE_ULTRALIGHT_C = 2|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareUltralightType<br>方法or属性：TYPE_ULTRALIGHT_C = 2|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNfcA(tagInfo: TagInfo): NfcATag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNfcB(tagInfo: TagInfo): NfcBTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNfcF(tagInfo: TagInfo): NfcFTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNfcV(tagInfo: TagInfo): NfcVTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getIsoDep(tagInfo: TagInfo): IsoDepTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNdef(tagInfo: TagInfo): NdefTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getMifareClassic(tagInfo: TagInfo): MifareClassicTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getMifareUltralight(tagInfo: TagInfo): MifareUltralightTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getNdefFormatable(tagInfo: TagInfo): NdefFormatableTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag<br>方法or属性：function getTagInfo(want: Want): TagInfo|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo<br>方法or属性：uid: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo<br>方法or属性：technology: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo<br>方法or属性：extrasData: PacMap[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo<br>方法or属性：tagRfDiscId: number;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo<br>方法or属性：remoteTagService: rpc.RemoteObject;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NdefRecord|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NdefRecord<br>方法or属性：|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NdefRecord<br>方法 or 属性：tnf: number;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NdefRecord<br>方法or属性：tnf: number;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NdefRecord<br>方法 or 属性：rtdType: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NdefRecord<br>方法or属性：rtdType: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NdefRecord<br>方法 or 属性：id: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NdefRecord<br>方法or属性：id: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: NdefRecord<br>方法 or 属性：payload: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NdefRecord<br>方法or属性：payload: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: ndef|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef<br>方法or属性：|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: ndef<br>方法 or 属性：function makeUriRecord(uri: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef<br>方法or属性：function makeUriRecord(uri: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: ndef<br>方法 or 属性：function makeTextRecord(text: string, locale: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef<br>方法or属性：function makeTextRecord(text: string, locale: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: ndef<br>方法 or 属性：function makeMimeRecord(mimeType: string, mimeData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef<br>方法or属性：function makeMimeRecord(mimeType: string, mimeData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: ndef<br>方法 or 属性：function makeExternalRecord(domainName: string, type: string, externalData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef<br>方法or属性：function makeExternalRecord(domainName: string, type: string, externalData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: ndef<br>方法 or 属性：function createNdefMessage(data: number[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef<br>方法or属性：function createNdefMessage(data: number[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: ndef<br>方法 or 属性：function createNdefMessage(ndefRecords: NdefRecord[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef<br>方法or属性：function createNdefMessage(ndefRecords: NdefRecord[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.nfc.tag<br>类名: ndef<br>方法 or 属性：function messageToBytes(ndefMessage: NdefMessage): number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef<br>方法or属性：function messageToBytes(ndefMessage: NdefMessage): number[];|@ohos.nfc.tag.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：CHECK_PARAM_ERROR = 401|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：CHECK_PARAM_ERROR = 401|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：OS_MMAP_ERROR = 1900001|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：OS_MMAP_ERROR = 1900001|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：OS_IOCTL_ERROR = 1900002|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：OS_IOCTL_ERROR = 1900002|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：WRITE_TO_ASHMEM_ERROR = 1900003|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：WRITE_TO_ASHMEM_ERROR = 1900003|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：READ_FROM_ASHMEM_ERROR = 1900004|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：READ_FROM_ASHMEM_ERROR = 1900004|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：ONLY_PROXY_OBJECT_PERMITTED_ERROR = 1900005|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：ONLY_PROXY_OBJECT_PERMITTED_ERROR = 1900005|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：ONLY_REMOTE_OBJECT_PERMITTED_ERROR = 1900006|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：ONLY_REMOTE_OBJECT_PERMITTED_ERROR = 1900006|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：COMMUNICATION_ERROR = 1900007|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：COMMUNICATION_ERROR = 1900007|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：PROXY_OR_REMOTE_OBJECT_INVALID_ERROR = 1900008|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：PROXY_OR_REMOTE_OBJECT_INVALID_ERROR = 1900008|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：WRITE_DATA_TO_MESSAGE_SEQUENCE_ERROR = 1900009|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：WRITE_DATA_TO_MESSAGE_SEQUENCE_ERROR = 1900009|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：READ_DATA_FROM_MESSAGE_SEQUENCE_ERROR = 1900010|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：READ_DATA_FROM_MESSAGE_SEQUENCE_ERROR = 1900010|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：PARCEL_MEMORY_ALLOC_ERROR = 1900011|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：PARCEL_MEMORY_ALLOC_ERROR = 1900011|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：CALL_JS_METHOD_ERROR = 1900012|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：CALL_JS_METHOD_ERROR = 1900012|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: ErrorCode<br>方法 or 属性：OS_DUP_ERROR = 1900013|@ohos.rpc.d.ts|
|新增|NA|类名：ErrorCode<br>方法or属性：OS_DUP_ERROR = 1900013|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：static create(): MessageSequence;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：static create(): MessageSequence;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：reclaim(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：reclaim(): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeRemoteObject(object: IRemoteObject): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeRemoteObject(object: IRemoteObject): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readRemoteObject(): IRemoteObject;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readRemoteObject(): IRemoteObject;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeInterfaceToken(token: string): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeInterfaceToken(token: string): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readInterfaceToken(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readInterfaceToken(): string;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：getSize(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：getSize(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：getCapacity(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：getCapacity(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：setSize(size: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：setSize(size: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：setCapacity(size: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：setCapacity(size: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：getWritableBytes(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：getWritableBytes(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：getReadableBytes(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：getReadableBytes(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：getReadPosition(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：getReadPosition(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：getWritePosition(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：getWritePosition(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：rewindRead(pos: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：rewindRead(pos: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：rewindWrite(pos: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：rewindWrite(pos: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeNoException(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeNoException(): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readException(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readException(): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeByte(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeByte(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeShort(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeShort(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeInt(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeInt(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeLong(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeLong(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeFloat(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeFloat(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeDouble(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeDouble(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeBoolean(val: boolean): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeBoolean(val: boolean): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeChar(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeChar(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeString(val: string): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeString(val: string): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeParcelable(val: Parcelable): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeParcelable(val: Parcelable): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeByteArray(byteArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeByteArray(byteArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeShortArray(shortArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeShortArray(shortArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeIntArray(intArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeIntArray(intArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeLongArray(longArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeLongArray(longArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeFloatArray(floatArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeFloatArray(floatArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeDoubleArray(doubleArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeDoubleArray(doubleArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeBooleanArray(booleanArray: boolean[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeBooleanArray(booleanArray: boolean[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeCharArray(charArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeCharArray(charArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeStringArray(stringArray: string[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeStringArray(stringArray: string[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeRemoteObjectArray(objectArray: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeRemoteObjectArray(objectArray: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readByte(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readByte(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readShort(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readShort(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readInt(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readInt(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readLong(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readLong(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readFloat(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readFloat(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readDouble(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readDouble(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readBoolean(): boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readBoolean(): boolean;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readChar(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readChar(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readString(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readString(): string;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readParcelable(dataIn: Parcelable) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readParcelable(dataIn: Parcelable) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readByteArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readByteArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readByteArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readByteArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readShortArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readShortArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readShortArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readShortArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readIntArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readIntArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readIntArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readIntArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readLongArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readLongArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readLongArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readLongArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readFloatArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readFloatArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readFloatArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readFloatArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readDoubleArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readDoubleArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readDoubleArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readDoubleArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readBooleanArray(dataIn: boolean[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readBooleanArray(dataIn: boolean[]) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readBooleanArray(): boolean[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readBooleanArray(): boolean[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readCharArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readCharArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readCharArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readCharArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readStringArray(dataIn: string[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readStringArray(dataIn: string[]) : void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readStringArray(): string[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readStringArray(): string[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readRemoteObjectArray(objects: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readRemoteObjectArray(objects: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readRemoteObjectArray(): IRemoteObject[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readRemoteObjectArray(): IRemoteObject[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：static closeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：static closeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：static dupFileDescriptor(fd: number) :number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：static dupFileDescriptor(fd: number) :number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：containFileDescriptors(): boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：containFileDescriptors(): boolean;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readFileDescriptor(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readFileDescriptor(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeAshmem(ashmem: Ashmem): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeAshmem(ashmem: Ashmem): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readAshmem(): Ashmem;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readAshmem(): Ashmem;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：getRawDataCapacity(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：getRawDataCapacity(): number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：writeRawData(rawData: number[], size: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：writeRawData(rawData: number[], size: number): void;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: MessageSequence<br>方法 or 属性：readRawData(size: number): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence<br>方法or属性：readRawData(size: number): number[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: Parcelable|@ohos.rpc.d.ts|
|新增|NA|类名：Parcelable<br>方法or属性：|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: Parcelable<br>方法 or 属性：marshalling(dataOut: MessageSequence): boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：Parcelable<br>方法or属性：marshalling(dataOut: MessageSequence): boolean;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: Parcelable<br>方法 or 属性：unmarshalling(dataIn: MessageSequence) : boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：Parcelable<br>方法or属性：unmarshalling(dataIn: MessageSequence) : boolean;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: RequestResult|@ohos.rpc.d.ts|
|新增|NA|类名：RequestResult<br>方法or属性：|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: RequestResult<br>方法 or 属性：errCode: number;|@ohos.rpc.d.ts|
|新增|NA|类名：RequestResult<br>方法or属性：errCode: number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: RequestResult<br>方法 or 属性：code: number;|@ohos.rpc.d.ts|
|新增|NA|类名：RequestResult<br>方法or属性：code: number;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: RequestResult<br>方法 or 属性：data: MessageSequence;|@ohos.rpc.d.ts|
|新增|NA|类名：RequestResult<br>方法or属性：data: MessageSequence;|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.rpc<br>类名: RequestResult<br>方法 or 属性：reply: MessageSequence;|@ohos.rpc.d.ts|
|新增|NA|类名：RequestResult<br>方法or属性：reply: MessageSequence;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject<br>方法or属性：getLocalInterface(descriptor: string): IRemoteBroker;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise\<RequestResult>;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback\<RequestResult>): void;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject<br>方法or属性：registerDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject<br>方法or属性：unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject<br>方法or属性：getDescriptor(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption<br>方法or属性：TF_SYNC: number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption<br>方法or属性：TF_ASYNC: number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption<br>方法or属性：TF_ACCEPT_FDS: number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption<br>方法or属性：TF_WAIT_TIME: number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption<br>方法or属性：constructor(syncFlags?: number, waitTime?: number);|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption<br>方法or属性：constructor(async?: boolean);|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption<br>方法or属性：isAsync(): boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption<br>方法or属性：setAsync(async: boolean): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject<br>方法or属性：getLocalInterface(descriptor: string): IRemoteBroker;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject<br>方法or属性：getDescriptor(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject<br>方法or属性：onRemoteMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): boolean \| Promise\<boolean>;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise\<RequestResult>;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback\<RequestResult>): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject<br>方法or属性：modifyLocalInterface(localInterface: IRemoteBroker, descriptor: string): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：PING_TRANSACTION: number;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：DUMP_TRANSACTION: number;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：INTERFACE_TRANSACTION: number;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：MIN_TRANSACTION_ID: number;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：MAX_TRANSACTION_ID: number;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：getLocalInterface(interface: string): IRemoteBroker;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：registerDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：getDescriptor(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise\<RequestResult>;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback\<RequestResult>): void;|@ohos.rpc.d.ts|
|新增|NA|类名：IPCSkeleton<br>方法or属性：static flushCmdBuffer(object: IRemoteObject): void;|@ohos.rpc.d.ts|
|新增|NA|类名：IPCSkeleton<br>方法or属性：static restoreCallingIdentity(identity: string): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：PROT_EXEC: number;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：PROT_NONE: number;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：PROT_READ: number;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：PROT_WRITE: number;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：static create(name: string, size: number): Ashmem;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：static create(ashmem: Ashmem): Ashmem;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：mapTypedAshmem(mapType: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：mapReadWriteAshmem(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：mapReadonlyAshmem(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：setProtectionType(protectionType: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：writeAshmem(buf: number[], size: number, offset: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem<br>方法or属性：readAshmem(size: number, offset: number): number[];|@ohos.rpc.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function enableWifi(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function disableWifi(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function isWifiActive(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function scan(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getScanResults(): Promise\<Array\<WifiScanInfo>>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getScanResultsSync(): Array\<WifiScanInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function addDeviceConfig(config: WifiDeviceConfig): Promise\<number>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function addCandidateConfig(config: WifiDeviceConfig): Promise\<number>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function removeCandidateConfig(networkId: number): Promise\<void>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getCandidateConfigs(): Array\<WifiDeviceConfig>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function connectToCandidateConfig(networkId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function connectToNetwork(networkId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function connectToDevice(config: WifiDeviceConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function disconnect(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getSignalLevel(rssi: number, band: number): number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getLinkedInfo(): Promise\<WifiLinkedInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function isConnected(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getSupportedFeatures(): number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function isFeatureSupported(featureId: number): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getDeviceMacAddress(): string[];|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getIpInfo(): IpInfo;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getCountryCode(): string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function reassociate(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function reconnect(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getDeviceConfigs(): Array\<WifiDeviceConfig>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function updateNetwork(config: WifiDeviceConfig): number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function disableNetwork(netId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function removeAllNetwork(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function removeDevice(id: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function enableHotspot(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function disableHotspot(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function isHotspotDualBandSupported(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function isHotspotActive(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function setHotspotConfig(config: HotspotConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getHotspotConfig(): HotspotConfig;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getStations(): Array\<StationInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getP2pLocalDevice(): Promise\<WifiP2pDevice>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function createGroup(config: WifiP2PConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function removeGroup(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function p2pConnect(config: WifiP2PConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function p2pCancelConnect(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function startDiscoverDevices(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function stopDiscoverDevices(): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function deletePersistentGroup(netId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function setDeviceName(devName: string): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "wifiStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "wifiStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "wifiConnectionChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "wifiConnectionChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "wifiScanStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "wifiScanStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "wifiRssiChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "wifiRssiChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "streamChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "streamChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "deviceConfigChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "deviceConfigChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "hotspotStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "hotspotStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "p2pStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "p2pStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function on(type: "p2pDiscoveryChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: wifiManager<br>方法 or 属性: function off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_NONE|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_PEAP|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_TLS|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_TTLS|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_PWD|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_SIM|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_AKA|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_AKA_PRIME|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: EapMethod<br>方法 or 属性: EAP_UNAUTH_TLS|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: Phase2Method|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_NONE|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_PAP|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_MSCHAP|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_MSCHAPV2|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_GTC|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_SIM|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_AKA|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: Phase2Method<br>方法 or 属性: PHASE2_AKA_PRIME|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: eapMethod: EapMethod;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: phase2Method: Phase2Method;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: identity: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: anonymousIdentity: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: password: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: caCertAliases: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: caPath: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: clientCertAliases: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: certEntry: Uint8Array;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: certPassword: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: altSubjectMatch: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: domainSuffixMatch: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: realm: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: plmn: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiEapConfig<br>方法 or 属性: eapSubId: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: ssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: bssid?: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: preSharedKey: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: isHiddenSsid?: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: securityType: WifiSecurityType;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: creatorUid?: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: disableReason?: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: netId?: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: randomMacType?: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: randomMacAddr?: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: ipType?: IpType;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: staticIp?: IpConfig;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiDeviceConfig<br>方法 or 属性: eapConfig?: WifiEapConfig;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpConfig|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpConfig<br>方法 or 属性: ipAddress: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpConfig<br>方法 or 属性: gateway: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpConfig<br>方法 or 属性: prefixLength: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpConfig<br>方法 or 属性: dnsServers: number[];|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpConfig<br>方法 or 属性: domains: Array\<string>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiInfoElem|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiInfoElem<br>方法 or 属性: eid: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiInfoElem<br>方法 or 属性: content: Uint8Array;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiChannelWidth|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiChannelWidth<br>方法 or 属性: WIDTH_20MHZ = 0|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiChannelWidth<br>方法 or 属性: WIDTH_40MHZ = 1|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiChannelWidth<br>方法 or 属性: WIDTH_80MHZ = 2|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiChannelWidth<br>方法 or 属性: WIDTH_160MHZ = 3|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiChannelWidth<br>方法 or 属性: WIDTH_80MHZ_PLUS = 4|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiChannelWidth<br>方法 or 属性: WIDTH_INVALID|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: ssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: bssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: capabilities: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: securityType: WifiSecurityType;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: rssi: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: band: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: frequency: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: channelWidth: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: centerFrequency0: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: centerFrequency1: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: infoElems: Array\<WifiInfoElem>;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiScanInfo<br>方法 or 属性: timestamp: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_INVALID = 0|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_OPEN = 1|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_WEP = 2|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_PSK = 3|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_SAE = 4|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_EAP = 5|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_EAP_SUITE_B = 6|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_OWE = 7|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_WAPI_CERT = 8|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiSecurityType<br>方法 or 属性: WIFI_SEC_TYPE_WAPI_PSK = 9|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: ssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: bssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: networkId: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: rssi: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: band: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: linkSpeed: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: frequency: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: isHidden: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: isRestricted: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: chload: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: snr: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: macType: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: macAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: ipAddress: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: suppState: SuppState;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiLinkedInfo<br>方法 or 属性: connState: ConnState;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpInfo|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpInfo<br>方法 or 属性: ipAddress: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpInfo<br>方法 or 属性: gateway: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpInfo<br>方法 or 属性: netmask: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpInfo<br>方法 or 属性: primaryDns: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpInfo<br>方法 or 属性: secondDns: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpInfo<br>方法 or 属性: serverIp: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpInfo<br>方法 or 属性: leaseDuration: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: HotspotConfig|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: HotspotConfig<br>方法 or 属性: ssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: HotspotConfig<br>方法 or 属性: securityType: WifiSecurityType;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: HotspotConfig<br>方法 or 属性: band: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: HotspotConfig<br>方法 or 属性: preSharedKey: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: HotspotConfig<br>方法 or 属性: maxConn: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: StationInfo|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: StationInfo<br>方法 or 属性: name: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: StationInfo<br>方法 or 属性: macAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: StationInfo<br>方法 or 属性: ipAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpType|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpType<br>方法 or 属性: STATIC|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpType<br>方法 or 属性: DHCP|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: IpType<br>方法 or 属性: UNKNOWN|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: DISCONNECTED|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: INTERFACE_DISABLED|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: INACTIVE|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: SCANNING|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: AUTHENTICATING|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: ASSOCIATING|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: ASSOCIATED|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: FOUR_WAY_HANDSHAKE|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: GROUP_HANDSHAKE|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: COMPLETED|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: UNINITIALIZED|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: SuppState<br>方法 or 属性: INVALID|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: ConnState|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: ConnState<br>方法 or 属性: SCANNING|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: ConnState<br>方法 or 属性: CONNECTING|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: ConnState<br>方法 or 属性: AUTHENTICATING|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: ConnState<br>方法 or 属性: OBTAINING_IPADDR|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: ConnState<br>方法 or 属性: CONNECTED|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: ConnState<br>方法 or 属性: DISCONNECTING|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: ConnState<br>方法 or 属性: DISCONNECTED|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: ConnState<br>方法 or 属性: UNKNOWN|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pDevice|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pDevice<br>方法 or 属性: deviceName: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pDevice<br>方法 or 属性: deviceAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pDevice<br>方法 or 属性: primaryDeviceType: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pDevice<br>方法 or 属性: deviceStatus: P2pDeviceStatus;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pDevice<br>方法 or 属性: groupCapabilities: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2PConfig|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2PConfig<br>方法 or 属性: deviceAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2PConfig<br>方法 or 属性: netId: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2PConfig<br>方法 or 属性: passphrase: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2PConfig<br>方法 or 属性: groupName: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2PConfig<br>方法 or 属性: goBand: GroupOwnerBand;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo<br>方法 or 属性: isP2pGo: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo<br>方法 or 属性: ownerInfo: WifiP2pDevice;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo<br>方法 or 属性: passphrase: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo<br>方法 or 属性: interface: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo<br>方法 or 属性: groupName: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo<br>方法 or 属性: networkId: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo<br>方法 or 属性: frequency: number;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo<br>方法 or 属性: clientDevices: WifiP2pDevice[];|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pGroupInfo<br>方法 or 属性: goIpAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: P2pConnectState|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: P2pConnectState<br>方法 or 属性: DISCONNECTED = 0|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: P2pConnectState<br>方法 or 属性: CONNECTED = 1|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pLinkedInfo|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pLinkedInfo<br>方法 or 属性: connectState: P2pConnectState;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pLinkedInfo<br>方法 or 属性: isGroupOwner: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: WifiP2pLinkedInfo<br>方法 or 属性: groupOwnerAddr: string;|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: P2pDeviceStatus|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: P2pDeviceStatus<br>方法 or 属性: CONNECTED = 0|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: P2pDeviceStatus<br>方法 or 属性: INVITED = 1|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: P2pDeviceStatus<br>方法 or 属性: FAILED = 2|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: P2pDeviceStatus<br>方法 or 属性: AVAILABLE = 3|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: P2pDeviceStatus<br>方法 or 属性: UNAVAILABLE = 4|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: GroupOwnerBand|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: GroupOwnerBand<br>方法 or 属性: GO_BAND_AUTO = 0|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: GroupOwnerBand<br>方法 or 属性: GO_BAND_2GHZ = 1|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManager<br>类名: GroupOwnerBand<br>方法 or 属性: GO_BAND_5GHZ = 2|@ohos.wifiManager.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: wifiManagerExt|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: wifiManagerExt<br>方法 or 属性: function enableHotspot(): void;|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: wifiManagerExt<br>方法 or 属性: function disableHotspot(): void;|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: wifiManagerExt<br>方法 or 属性: function getSupportedPowerMode(): Promise\<Array\<PowerMode>>;|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: wifiManagerExt<br>方法 or 属性: function getSupportedPowerMode(callback: AsyncCallback\<Array\<PowerMode>>): void;|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: wifiManagerExt<br>方法 or 属性: function getPowerMode (): Promise\<PowerMode>;|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: wifiManagerExt<br>方法 or 属性: function getPowerMode (callback: AsyncCallback\<PowerMode>): void;|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: wifiManagerExt<br>方法 or 属性: function setPowerMode(mode: PowerMode) : void|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: PowerMode|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: PowerMode<br>方法 or 属性: SLEEPING = 0|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: PowerMode<br>方法 or 属性: GENERAL = 1|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: ohos.wifiManagerExt<br>类名: PowerMode<br>方法 or 属性: THROUGH_WALL = 2|@ohos.wifiManagerExt.d.ts|
|新增|NA|模块名: nfctech<br>类名: IsoDepTag|nfctech.d.ts|
|新增|NA|类名：IsoDepTag<br>方法or属性：|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: IsoDepTag<br>方法 or 属性：getHistoricalBytes(): number[];|nfctech.d.ts|
|新增|NA|类名：IsoDepTag<br>方法or属性：getHistoricalBytes(): number[];|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: IsoDepTag<br>方法 or 属性：getHiLayerResponse(): number[];|nfctech.d.ts|
|新增|NA|类名：IsoDepTag<br>方法or属性：getHiLayerResponse(): number[];|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: IsoDepTag<br>方法 or 属性：isExtendedApduSupported(): Promise\<boolean>;|nfctech.d.ts|
|新增|NA|类名：IsoDepTag<br>方法or属性：isExtendedApduSupported(): Promise\<boolean>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: IsoDepTag<br>方法 or 属性：isExtendedApduSupported(callback: AsyncCallback\<boolean>): void;|nfctech.d.ts|
|新增|NA|类名：IsoDepTag<br>方法or属性：isExtendedApduSupported(callback: AsyncCallback\<boolean>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefMessage|nfctech.d.ts|
|新增|NA|类名：NdefMessage<br>方法or属性：|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefMessage<br>方法 or 属性：getNdefRecords(): tag.NdefRecord[];|nfctech.d.ts|
|新增|NA|类名：NdefMessage<br>方法or属性：getNdefRecords(): tag.NdefRecord[];|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：getNdefTagType(): tag.NfcForumType;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：getNdefTagType(): tag.NfcForumType;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：getNdefMessage(): NdefMessage;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：getNdefMessage(): NdefMessage;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：isNdefWritable(): boolean;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：isNdefWritable(): boolean;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：readNdef(): Promise\<NdefMessage>;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：readNdef(): Promise\<NdefMessage>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：readNdef(callback: AsyncCallback\<NdefMessage>): void;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：readNdef(callback: AsyncCallback\<NdefMessage>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：writeNdef(msg: NdefMessage): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：writeNdef(msg: NdefMessage): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：writeNdef(msg: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：writeNdef(msg: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：canSetReadOnly(): boolean;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：canSetReadOnly(): boolean;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：setReadOnly(): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：setReadOnly(): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：setReadOnly(callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：setReadOnly(callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefTag<br>方法 or 属性：getNdefTagTypeString(type: tag.NfcForumType): string;|nfctech.d.ts|
|新增|NA|类名：NdefTag<br>方法or属性：getNdefTagTypeString(type: tag.NfcForumType): string;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：readSingleBlock(blockIndex: number): Promise\<number[]>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：readSingleBlock(blockIndex: number): Promise\<number[]>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：writeSingleBlock(blockIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：writeSingleBlock(blockIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：incrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：incrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：decrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：decrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：transferToBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：transferToBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：restoreFromBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：restoreFromBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：getSectorCount(): number;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：getSectorCount(): number;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：getBlockCountInSector(sectorIndex: number): number;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：getBlockCountInSector(sectorIndex: number): number;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：getType(): tag.MifareClassicType;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：getType(): tag.MifareClassicType;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：getTagSize(): number;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：getTagSize(): number;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：isEmulatedTag(): boolean;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：isEmulatedTag(): boolean;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：getBlockIndex(sectorIndex: number): number;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：getBlockIndex(sectorIndex: number): number;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareClassicTag<br>方法 or 属性：getSectorIndex(blockIndex: number): number;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag<br>方法or属性：getSectorIndex(blockIndex: number): number;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareUltralightTag|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag<br>方法or属性：|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareUltralightTag<br>方法 or 属性：readMultiplePages(pageIndex: number): Promise\<number[]>;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag<br>方法or属性：readMultiplePages(pageIndex: number): Promise\<number[]>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareUltralightTag<br>方法 or 属性：readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag<br>方法or属性：readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareUltralightTag<br>方法 or 属性：writeSinglePage(pageIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag<br>方法or属性：writeSinglePage(pageIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareUltralightTag<br>方法 or 属性：writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag<br>方法or属性：writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: MifareUltralightTag<br>方法 or 属性：getType(): tag.MifareUltralightType;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag<br>方法or属性：getType(): tag.MifareUltralightType;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefFormatableTag|nfctech.d.ts|
|新增|NA|类名：NdefFormatableTag<br>方法or属性：|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefFormatableTag<br>方法 or 属性：format(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：NdefFormatableTag<br>方法or属性：format(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefFormatableTag<br>方法 or 属性：format(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：NdefFormatableTag<br>方法or属性：format(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefFormatableTag<br>方法 or 属性：formatReadOnly(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：NdefFormatableTag<br>方法or属性：formatReadOnly(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|新增|NA|模块名: nfctech<br>类名: NdefFormatableTag<br>方法 or 属性：formatReadOnly(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：NdefFormatableTag<br>方法or属性：formatReadOnly(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：connect(): void;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：resetConnection(): void;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：isConnected(): boolean;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：setTimeout(timeout: number): void;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：getTimeout(): number;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：transmit(data: number[]): Promise\<number[]>;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：transmit(data: number[], callback: AsyncCallback\<number[]>): void;|tagSession.d.ts|
|新增|NA|类名：TagSession<br>方法or属性：getMaxTransmitSize(): number;|tagSession.d.ts|
|删除|模块名：ohos.rpc<br>类名:IRemoteObject|NA|@ohos.rpc.d.ts|
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
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function init(): boolean;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function init(): boolean;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function uninit(): boolean;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function uninit(): boolean;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function readNdefTag(): Promise\<string>;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function readNdefTag(): Promise\<string>;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string): Promise\<void>;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string): Promise\<void>;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>废弃版本：N/A|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：FeatureType<br>废弃版本：N/A|类名：FeatureType<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：cardEmulation<br>方法 or 属性：function isSupported(feature: number): boolean;<br>废弃版本：N/A|类名：cardEmulation<br>方法 or 属性：function isSupported(feature: number): boolean;<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：HceService<br>方法 or 属性：startHCE(aidList: string[]): boolean;<br>废弃版本：N/A|类名：HceService<br>方法 or 属性：startHCE(aidList: string[]): boolean;<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation.HceService|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：HceService<br>方法 or 属性：stopHCE(): boolean;<br>废弃版本：N/A|类名：HceService<br>方法 or 属性：stopHCE(): boolean;<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation.HceService|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：HceService<br>方法 or 属性：sendResponse(responseApdu: number[]): void;<br>废弃版本：N/A|类名：HceService<br>方法 or 属性：sendResponse(responseApdu: number[]): void;<br>废弃版本：9<br>代替接口：ohos.nfc.cardEmulation/cardEmulation.HceService|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：nfcController<br>方法 or 属性：function isNfcAvailable(): boolean<br>废弃版本：N/A|类名：nfcController<br>方法 or 属性：function isNfcAvailable(): boolean<br>废弃版本：9<br>代替接口：global|@ohos.nfc.controller.d.ts|
|废弃版本有变化|类名：nfcController<br>方法 or 属性：function openNfc(): boolean<br>废弃版本：N/A|类名：nfcController<br>方法 or 属性：function openNfc(): boolean<br>废弃版本：9<br>代替接口：@ohos.nfc.controller.nfcController|@ohos.nfc.controller.d.ts|
|废弃版本有变化|类名：nfcController<br>方法 or 属性：function closeNfc(): boolean<br>废弃版本：N/A|类名：nfcController<br>方法 or 属性：function closeNfc(): boolean<br>废弃版本：9<br>代替接口：@ohos.nfc.controller.nfcController|@ohos.nfc.controller.d.ts|
|废弃版本有变化|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>废弃版本：N/A|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>废弃版本：N/A|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>废弃版本：N/A|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>废弃版本：N/A|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：TagInfo<br>方法 or 属性：supportedProfiles: number[];<br>废弃版本：N/A|类名：TagInfo<br>方法 or 属性：supportedProfiles: number[];<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag.TagInfo|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：MessageParcel<br>废弃版本：N/A|类名：MessageParcel<br>废弃版本：9<br>代替接口：ohos.rpc.MessageSequence     |@ohos.rpc.d.ts|
|废弃版本有变化|类名：Sequenceable<br>废弃版本：N/A|类名：Sequenceable<br>废弃版本：9<br>代替接口：ohos.rpc.Parcelable     |@ohos.rpc.d.ts|
|废弃版本有变化|类名：SendRequestResult<br>废弃版本：N/A|类名：SendRequestResult<br>废弃版本：9<br>代替接口：ohos.rpc.RequestResult     |@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject<br>方法 or 属性：queryLocalInterface(descriptor: string): IRemoteBroker;<br>废弃版本：N/A|类名：IRemoteObject<br>方法 or 属性：queryLocalInterface(descriptor: string): IRemoteBroker;<br>废弃版本：9<br>代替接口：ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>废弃版本：8|类名：IRemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>废弃版本：9<br>代替接口：N/A|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>废弃版本：N/A|类名：IRemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>废弃版本：9<br>代替接口：ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>废弃版本：N/A|类名：IRemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>废弃版本：9<br>代替接口：ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject<br>方法 or 属性：addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>废弃版本：N/A|类名：IRemoteObject<br>方法 or 属性：addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject<br>方法 or 属性：removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>废弃版本：N/A|类名：IRemoteObject<br>方法 or 属性：removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject<br>方法 or 属性：getInterfaceDescriptor(): string;<br>废弃版本：N/A|类名：IRemoteObject<br>方法 or 属性：getInterfaceDescriptor(): string;<br>废弃版本：9<br>代替接口：ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject<br>方法 or 属性：queryLocalInterface(descriptor: string): IRemoteBroker;<br>废弃版本：N/A|类名：RemoteObject<br>方法 or 属性：queryLocalInterface(descriptor: string): IRemoteBroker;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject<br>方法 or 属性：getInterfaceDescriptor(): string;<br>废弃版本：N/A|类名：RemoteObject<br>方法 or 属性：getInterfaceDescriptor(): string;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject<br>方法 or 属性：onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>废弃版本：N/A|类名：RemoteObject<br>方法 or 属性：onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>废弃版本：N/A|类名：RemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>废弃版本：N/A|类名：RemoteObject<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject<br>方法 or 属性：attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void;<br>废弃版本：N/A|类名：RemoteObject<br>方法 or 属性：attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy<br>方法 or 属性：queryLocalInterface(interface: string): IRemoteBroker;<br>废弃版本：N/A|类名：RemoteProxy<br>方法 or 属性：queryLocalInterface(interface: string): IRemoteBroker;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy<br>方法 or 属性：addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>废弃版本：N/A|类名：RemoteProxy<br>方法 or 属性：addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy<br>方法 or 属性：removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>废弃版本：N/A|类名：RemoteProxy<br>方法 or 属性：removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy<br>方法 or 属性：getInterfaceDescriptor(): string;<br>废弃版本：N/A|类名：RemoteProxy<br>方法 or 属性：getInterfaceDescriptor(): string;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>废弃版本：N/A|类名：RemoteProxy<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>废弃版本：N/A|类名：RemoteProxy<br>方法 or 属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>废弃版本：9<br>代替接口：ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IPCSkeleton<br>方法 or 属性：static flushCommands(object: IRemoteObject): number;<br>废弃版本：N/A|类名：IPCSkeleton<br>方法 or 属性：static flushCommands(object: IRemoteObject): number;<br>废弃版本：9<br>代替接口：ohos.rpc.IPCSkeleton|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IPCSkeleton<br>方法 or 属性：static setCallingIdentity(identity: string): boolean;<br>废弃版本：N/A|类名：IPCSkeleton<br>方法 or 属性：static setCallingIdentity(identity: string): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.IPCSkeleton|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem<br>方法 or 属性：static createAshmem(name: string, size: number): Ashmem;<br>废弃版本：N/A|类名：Ashmem<br>方法 or 属性：static createAshmem(name: string, size: number): Ashmem;<br>废弃版本：9<br>代替接口：ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem<br>方法 or 属性：static createAshmemFromExisting(ashmem: Ashmem): Ashmem;<br>废弃版本：N/A|类名：Ashmem<br>方法 or 属性：static createAshmemFromExisting(ashmem: Ashmem): Ashmem;<br>废弃版本：9<br>代替接口：ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem<br>方法 or 属性：mapAshmem(mapType: number): boolean;<br>废弃版本：N/A|类名：Ashmem<br>方法 or 属性：mapAshmem(mapType: number): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem<br>方法 or 属性：mapReadAndWriteAshmem(): boolean;<br>废弃版本：N/A|类名：Ashmem<br>方法 or 属性：mapReadAndWriteAshmem(): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem<br>方法 or 属性：mapReadOnlyAshmem(): boolean;<br>废弃版本：N/A|类名：Ashmem<br>方法 or 属性：mapReadOnlyAshmem(): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem<br>方法 or 属性：setProtection(protectionType: number): boolean;<br>废弃版本：N/A|类名：Ashmem<br>方法 or 属性：setProtection(protectionType: number): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem<br>方法 or 属性：writeToAshmem(buf: number[], size: number, offset: number): boolean;<br>废弃版本：N/A|类名：Ashmem<br>方法 or 属性：writeToAshmem(buf: number[], size: number, offset: number): boolean;<br>废弃版本：9<br>代替接口：ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem<br>方法 or 属性：readFromAshmem(size: number, offset: number): number[];<br>废弃版本：N/A|类名：Ashmem<br>方法 or 属性：readFromAshmem(size: number, offset: number): number[];<br>废弃版本：9<br>代替接口：ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function enableWifi(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function enableWifi(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.enableWifi     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function disableWifi(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function disableWifi(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.disableWifi     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function isWifiActive(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function isWifiActive(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.isWifiActive     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function scan(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function scan(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.scan     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getScanInfos(): Promise\<Array\<WifiScanInfo>>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getScanInfos(): Promise\<Array\<WifiScanInfo>>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getScanResults     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getScanResults     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function addDeviceConfig(config: WifiDeviceConfig): Promise\<number>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function addDeviceConfig(config: WifiDeviceConfig): Promise\<number>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.addDeviceConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.addDeviceConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.addCandidateConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.addCandidateConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.removeCandidateConfig      |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.removeCandidateConfig      |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function connectToNetwork(networkId: number): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function connectToNetwork(networkId: number): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.connectToNetwork     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function connectToDevice(config: WifiDeviceConfig): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function connectToDevice(config: WifiDeviceConfig): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.connectToDevice     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function disconnect(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function disconnect(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.disconnect     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getSignalLevel(rssi: number, band: number): number;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getSignalLevel(rssi: number, band: number): number;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getSignalLevel     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getLinkedInfo(): Promise\<WifiLinkedInfo>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getLinkedInfo(): Promise\<WifiLinkedInfo>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getLinkedInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getLinkedInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function isConnected(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function isConnected(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.isConnected     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getSupportedFeatures(): number;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getSupportedFeatures(): number;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getSupportedFeatures     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function isFeatureSupported(featureId: number): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function isFeatureSupported(featureId: number): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.isFeatureSupported     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getDeviceMacAddress(): string[];<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getDeviceMacAddress(): string[];<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getDeviceMacAddress     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getIpInfo(): IpInfo;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getIpInfo(): IpInfo;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getIpInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getCountryCode(): string;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getCountryCode(): string;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getCountryCode     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function reassociate(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function reassociate(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.reassociate     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function reconnect(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function reconnect(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.reconnect     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getDeviceConfigs     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function updateNetwork(config: WifiDeviceConfig): number;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function updateNetwork(config: WifiDeviceConfig): number;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.updateNetwork     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function disableNetwork(netId: number): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function disableNetwork(netId: number): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.disableNetwork     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function removeAllNetwork(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function removeAllNetwork(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.removeAllNetwork     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function removeDevice(id: number): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function removeDevice(id: number): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.removeDevice     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function enableHotspot(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function enableHotspot(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.enableHotspot     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function disableHotspot(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function disableHotspot(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.disableHotspot     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function isHotspotDualBandSupported(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function isHotspotDualBandSupported(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.isHotspotDualBandSupported     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function isHotspotActive(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function isHotspotActive(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.isHotspotActive     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function setHotspotConfig(config: HotspotConfig): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function setHotspotConfig(config: HotspotConfig): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.setHotspotConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getHotspotConfig(): HotspotConfig;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getHotspotConfig(): HotspotConfig;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getHotspotConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getStations(): Array\<StationInfo>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getStations(): Array\<StationInfo>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getStations     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getP2pLinkedInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getP2pLinkedInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getCurrentGroup     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getCurrentGroup     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getP2pPeerDevices     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.getP2pPeerDevices     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function createGroup(config: WifiP2PConfig): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function createGroup(config: WifiP2PConfig): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.createGroup     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function removeGroup(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function removeGroup(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.removeGroup     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function p2pConnect(config: WifiP2PConfig): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function p2pConnect(config: WifiP2PConfig): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.p2pConnect     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function p2pCancelConnect(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function p2pCancelConnect(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.p2pCancelConnect     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function startDiscoverDevices(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function startDiscoverDevices(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.startDiscoverDevices     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function stopDiscoverDevices(): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function stopDiscoverDevices(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.stopDiscoverDevices     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function deletePersistentGroup(netId: number): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function deletePersistentGroup(netId: number): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.deletePersistentGroup     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function setDeviceName(devName: string): boolean;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function setDeviceName(devName: string): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.setDeviceName     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "wifiStateChange", callback: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "wifiStateChange", callback: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "wifiStateChange", callback?: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "wifiStateChange", callback?: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "wifiConnectionChange", callback: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "wifiConnectionChange", callback: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "wifiConnectionChange", callback?: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "wifiConnectionChange", callback?: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "wifiScanStateChange", callback: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "wifiScanStateChange", callback: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "wifiScanStateChange", callback?: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "wifiScanStateChange", callback?: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "wifiRssiChange", callback: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "wifiRssiChange", callback: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "wifiRssiChange", callback?: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "wifiRssiChange", callback?: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "streamChange", callback: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "streamChange", callback: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "streamChange", callback?: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "streamChange", callback?: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "hotspotStateChange", callback: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "hotspotStateChange", callback: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "hotspotStateChange", callback?: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "hotspotStateChange", callback?: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "p2pStateChange", callback: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "p2pStateChange", callback: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "p2pStateChange", callback?: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "p2pStateChange", callback?: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function on(type: "p2pDiscoveryChange", callback: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function on(type: "p2pDiscoveryChange", callback: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi<br>方法 or 属性：function off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void;<br>废弃版本：N/A|类名：wifi<br>方法 or 属性：function off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig<br>废弃版本：N/A|类名：WifiDeviceConfig<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.WifiDeviceConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpConfig<br>废弃版本：N/A|类名：IpConfig<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.IpConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo<br>废弃版本：N/A|类名：WifiScanInfo<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.WifiScanInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiSecurityType<br>废弃版本：N/A|类名：WifiSecurityType<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.WifiSecurityType     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo<br>废弃版本：N/A|类名：WifiLinkedInfo<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.WifiLinkedInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpInfo<br>废弃版本：N/A|类名：IpInfo<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.IpInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：HotspotConfig<br>废弃版本：N/A|类名：HotspotConfig<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.HotspotConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：StationInfo<br>废弃版本：N/A|类名：StationInfo<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.StationInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpType<br>废弃版本：N/A|类名：IpType<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.IpType     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState<br>废弃版本：N/A|类名：SuppState<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.SuppState     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState<br>废弃版本：N/A|类名：ConnState<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.ConnState     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pDevice<br>废弃版本：N/A|类名：WifiP2pDevice<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.WifiP2pDevice     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2PConfig<br>废弃版本：N/A|类名：WifiP2PConfig<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.WifiP2PConfig     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo<br>废弃版本：N/A|类名：WifiP2pGroupInfo<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.WifiP2pGroupInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pConnectState<br>废弃版本：N/A|类名：P2pConnectState<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.P2pConnectState     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pLinkedInfo<br>废弃版本：N/A|类名：WifiP2pLinkedInfo<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.WifiP2pLinkedInfo     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pDeviceStatus<br>废弃版本：N/A|类名：P2pDeviceStatus<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.P2pDeviceStatus     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：GroupOwnerBand<br>废弃版本：N/A|类名：GroupOwnerBand<br>废弃版本：9<br>代替接口：ohos.wifiManager/wifiManager.GroupOwnerBand     |@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifiext<br>方法 or 属性：function enableHotspot(): boolean;<br>废弃版本：N/A|类名：wifiext<br>方法 or 属性：function enableHotspot(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManagerExt/wifiManagerExt.enableHotspot     |@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext<br>方法 or 属性：function disableHotspot(): boolean;<br>废弃版本：N/A|类名：wifiext<br>方法 or 属性：function disableHotspot(): boolean;<br>废弃版本：9<br>代替接口：ohos.wifiManagerExt/wifiManagerExt.disableHotspot      |@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext<br>方法 or 属性：function getSupportedPowerModel(): Promise\<Array\<PowerModel>>;<br>废弃版本：N/A|类名：wifiext<br>方法 or 属性：function getSupportedPowerModel(): Promise\<Array\<PowerModel>>;<br>废弃版本：9<br>代替接口：ohos.wifiManagerExt/wifiManagerExt.getSupportedPowerMode     |@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext<br>方法 or 属性：function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>废弃版本：N/A|类名：wifiext<br>方法 or 属性：function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManagerExt/wifiManagerExt.getSupportedPowerMode     |@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext<br>方法 or 属性：function getPowerModel (): Promise\<PowerModel>;<br>废弃版本：N/A|类名：wifiext<br>方法 or 属性：function getPowerModel (): Promise\<PowerModel>;<br>废弃版本：9<br>代替接口：ohos.wifiManagerExt/wifiManagerExt.getPowerMode     |@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext<br>方法 or 属性：function getPowerModel (callback: AsyncCallback\<PowerModel>): void;<br>废弃版本：N/A|类名：wifiext<br>方法 or 属性：function getPowerModel (callback: AsyncCallback\<PowerModel>): void;<br>废弃版本：9<br>代替接口：ohos.wifiManagerExt/wifiManagerExt.getPowerMode     |@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext<br>方法 or 属性：function setPowerModel(model: PowerModel) : boolean<br>废弃版本：N/A|类名：wifiext<br>方法 or 属性：function setPowerModel(model: PowerModel) : boolean<br>废弃版本：9<br>代替接口：ohos.wifiManagerExt/wifiManagerExt.setPowerMode     |@ohos.wifiext.d.ts|
|废弃版本有变化|类名：PowerModel<br>废弃版本：N/A|类名：PowerModel<br>废弃版本：9<br>代替接口：ohos.wifiManagerExt/wifiManagerExt.PowerMode     |@ohos.wifiext.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：getTagInfo(): tag.TagInfo;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：getTagInfo(): tag.TagInfo;<br>废弃版本：9<br>代替接口：ohos.nfc.tag/tag|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：connectTag(): boolean;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：connectTag(): boolean;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：reset(): void;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：reset(): void;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：setSendDataTimeout(timeout: number): boolean;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：setSendDataTimeout(timeout: number): boolean;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：getSendDataTimeout(): number;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：getSendDataTimeout(): number;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：sendData(data: number[]): Promise\<number[]>;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：sendData(data: number[]): Promise\<number[]>;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|废弃版本有变化|类名：TagSession<br>方法 or 属性：getMaxSendLength(): number;<br>废弃版本：N/A|类名：TagSession<br>方法 or 属性：getMaxSendLength(): number;<br>废弃版本：9<br>代替接口：tagSession.TagSession|tagSession.d.ts|
|起始版本有变化|类名：A2dpSourceProfile<br>方法 or 属性：getPlayingState(device: string): PlayingState;<br>起始版本：N/A|类名：A2dpSourceProfile<br>方法 or 属性：getPlayingState(device: string): PlayingState;<br>起始版本：8|@ohos.bluetooth.d.ts|
|起始版本有变化|类名：ScanFilter<br>起始版本：7|类名：ScanFilter<br>起始版本：N/A|@ohos.bluetooth.d.ts|
|起始版本有变化|类名：ScanFilter<br>方法 or 属性：deviceId?: string;<br>起始版本：N/A|类名：ScanFilter<br>方法 or 属性：deviceId?: string;<br>起始版本：7|@ohos.bluetooth.d.ts|
|起始版本有变化|类名：ScanFilter<br>方法 or 属性：name?: string;<br>起始版本：N/A|类名：ScanFilter<br>方法 or 属性：name?: string;<br>起始版本：7|@ohos.bluetooth.d.ts|
|起始版本有变化|类名：ScanFilter<br>方法 or 属性：serviceUuid?: string;<br>起始版本：N/A|类名：ScanFilter<br>方法 or 属性：serviceUuid?: string;<br>起始版本：7|@ohos.bluetooth.d.ts|
|起始版本有变化|类名：ProfileId<br>起始版本：8|类名：ProfileId<br>起始版本：N/A|@ohos.bluetooth.d.ts|
|起始版本有变化|类名：ProfileId<br>方法 or 属性：PROFILE_A2DP_SOURCE = 1<br>起始版本：N/A|类名：ProfileId<br>方法 or 属性：PROFILE_A2DP_SOURCE = 1<br>起始版本：8|@ohos.bluetooth.d.ts|
|起始版本有变化|类名：ProfileId<br>方法 or 属性：PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4<br>起始版本：N/A|类名：ProfileId<br>方法 or 属性：PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4<br>起始版本：8|@ohos.bluetooth.d.ts|
|起始版本有变化|类名：FeatureType<br>起始版本：N/A|类名：FeatureType<br>起始版本：6|@ohos.nfc.cardEmulation.d.ts|
|起始版本有变化|类名：TagInfo<br>方法 or 属性：supportedProfiles: number[];<br>起始版本：N/A|类名：TagInfo<br>方法 or 属性：supportedProfiles: number[];<br>起始版本：7|@ohos.nfc.tag.d.ts|
|权限有变化|类名：bluetooth<br>方法 or 属性：function startBluetoothDiscovery(): boolean;<br>权限:ohos.permission.LOCATION|类名：bluetooth<br>方法 or 属性：function startBluetoothDiscovery(): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH and ohos.permission.LOCATION|@ohos.bluetooth.d.ts|
|权限有变化|类名：A2dpSourceProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：A2dpSourceProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：A2dpSourceProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：A2dpSourceProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：connect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:permission ohos.permission.DISCOVER_BLUETOOTH|类名：HandsFreeAudioGatewayProfile<br>方法 or 属性：disconnect(device: string): boolean;<br>权限:ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：BLE<br>方法 or 属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>权限:ohos.permission.LOCATION|类名：BLE<br>方法 or 属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>权限:ohos.permission.DISCOVER_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH and ohos.permission.LOCATION|@ohos.bluetooth.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function init(): boolean;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function init(): boolean;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function uninit(): boolean;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function uninit(): boolean;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function readNdefTag(): Promise\<string>;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function readNdefTag(): Promise\<string>;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string): Promise\<void>;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string): Promise\<void>;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function on(type: "notify", callback: Callback\<number>): void;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function on(type: "notify", callback: Callback\<number>): void;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag<br>方法 or 属性：function off(type: "notify", callback?:Callback\<number>): void;<br>权限:s ohos.permission.NFC_TAG|类名：connectedTag<br>方法 or 属性：function off(type: "notify", callback?:Callback\<number>): void;<br>权限:ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connection<br>方法 or 属性：function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：connection<br>方法 or 属性：function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：connection<br>方法 or 属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：connection<br>方法 or 属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string): Promise\<NetAddress>;<br>权限:ohos.permission.GET_NETWORK_INFO|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string): Promise\<NetAddress>;<br>权限:ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|删除(权限)|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>权限:ohos.permission.NFC_TAG|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>权限:N/A|@ohos.nfc.tag.d.ts|
|删除(权限)|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>权限:ohos.permission.NFC_TAG|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>权限:N/A|@ohos.nfc.tag.d.ts|
|删除(权限)|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>权限:ohos.permission.NFC_TAG|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>权限:N/A|@ohos.nfc.tag.d.ts|
|删除(权限)|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>权限:ohos.permission.NFC_TAG|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>权限:N/A|@ohos.nfc.tag.d.ts|
|删除(权限)|类名：NfcATag<br>方法 or 属性：getSak(): number;<br>权限:ohos.permission.NFC_TAG|类名：NfcATag<br>方法 or 属性：getSak(): number;<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcATag<br>方法 or 属性：getAtqa(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcATag<br>方法 or 属性：getAtqa(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcBTag<br>方法 or 属性：getRespAppData(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcBTag<br>方法 or 属性：getRespAppData(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcBTag<br>方法 or 属性：getRespProtocol(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcBTag<br>方法 or 属性：getRespProtocol(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcFTag<br>方法 or 属性：getSystemCode(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcFTag<br>方法 or 属性：getSystemCode(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcFTag<br>方法 or 属性：getPmm(): number[];<br>权限:ohos.permission.NFC_TAG|类名：NfcFTag<br>方法 or 属性：getPmm(): number[];<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcVTag<br>方法 or 属性：getResponseFlags(): number;<br>权限:ohos.permission.NFC_TAG|类名：NfcVTag<br>方法 or 属性：getResponseFlags(): number;<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：NfcVTag<br>方法 or 属性：getDsfId(): number;<br>权限:ohos.permission.NFC_TAG|类名：NfcVTag<br>方法 or 属性：getDsfId(): number;<br>权限:N/A|nfctech.d.ts|
|删除(权限)|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>权限:ohos.permission.NFC_TAG|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>权限:N/A|tagSession.d.ts|
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
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：NetHandle<br>方法 or 属性：getAddressByName(host: string): Promise\<NetAddress>;<br>错误码内容: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|新增(错误码)|NA|类名：HttpRequest<br>方法 or 属性：request(url: string, callback: AsyncCallback\<HttpResponse>): void;<br>错误码内容: 401, 201, 2300001, 2300003, 2300005, 2300006, 2300007, 2300008, 2300009, 2300016, 2300018, 2300023, 2300025, 2300026, 2300027, 2300028, 2300047, 2300052, 2300055, 2300056, 2300058, 2300059, 2300060, 2300061, 2300063, 2300070, 2300073, 2300077, 2300078, 2300094, 2300999|@ohos.net.http.d.ts|
|新增(错误码)|NA|类名：HttpRequest<br>方法 or 属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>错误码内容: 401, 201, 2300001, 2300003, 2300005, 2300006, 2300007, 2300008, 2300009, 2300016, 2300018, 2300023, 2300025, 2300026, 2300027, 2300028, 2300047, 2300052, 2300055, 2300056, 2300058, 2300059, 2300060, 2300061, 2300063, 2300070, 2300073, 2300077, 2300078, 2300094, 2300999|@ohos.net.http.d.ts|
|新增(错误码)|NA|类名：HttpRequest<br>方法 or 属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>错误码内容: 401, 201, 2300001, 2300003, 2300005, 2300006, 2300007, 2300008, 2300009, 2300016, 2300018, 2300023, 2300025, 2300026, 2300027, 2300028, 2300047, 2300052, 2300055, 2300056, 2300058, 2300059, 2300060, 2300061, 2300063, 2300070, 2300073, 2300077, 2300078, 2300094, 2300999|@ohos.net.http.d.ts|
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
|新增(权限)|类名：connection<br>方法 or 属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>权限:N/A|类名：connection<br>方法 or 属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>权限:ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function hasDefaultNet(): Promise\<boolean>;<br>权限:N/A|类名：connection<br>方法 or 属性：function hasDefaultNet(): Promise\<boolean>;<br>权限:ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：connection<br>方法 or 属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function enableAirplaneMode(): Promise\<void>;<br>权限:N/A|类名：connection<br>方法 or 属性：function enableAirplaneMode(): Promise\<void>;<br>权限:ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>权限:N/A|类名：connection<br>方法 or 属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>权限:ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|新增(权限)|类名：connection<br>方法 or 属性：function disableAirplaneMode(): Promise\<void>;<br>权限:N/A|类名：connection<br>方法 or 属性：function disableAirplaneMode(): Promise\<void>;<br>权限:ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|SysCap有变化|类名：cardEmulation<br>SysCap:SystemCapability.Communication.NFC.Core|类名：cardEmulation<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：FeatureType<br>SysCap:SystemCapability.Communication.NFC.Core|类名：FeatureType<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：FeatureType<br>方法 or 属性：HCE = 0<br>SysCap:SystemCapability.Communication.NFC.Core|类名：FeatureType<br>方法 or 属性：HCE = 0<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：FeatureType<br>方法 or 属性：UICC = 1<br>SysCap:SystemCapability.Communication.NFC.Core|类名：FeatureType<br>方法 or 属性：UICC = 1<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：FeatureType<br>方法 or 属性：ESE = 2<br>SysCap:SystemCapability.Communication.NFC.Core|类名：FeatureType<br>方法 or 属性：ESE = 2<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：cardEmulation<br>方法 or 属性：function isSupported(feature: number): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：cardEmulation<br>方法 or 属性：function isSupported(feature: number): boolean;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：HceService<br>SysCap:SystemCapability.Communication.NFC.Core|类名：HceService<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：HceService<br>方法 or 属性：startHCE(aidList: string[]): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：HceService<br>方法 or 属性：startHCE(aidList: string[]): boolean;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：HceService<br>方法 or 属性：stopHCE(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：HceService<br>方法 or 属性：stopHCE(): boolean;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：HceService<br>方法 or 属性：on(type: "hceCmd", callback: AsyncCallback\<number[]>): void;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：HceService<br>方法 or 属性：on(type: "hceCmd", callback: AsyncCallback\<number[]>): void;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：HceService<br>方法 or 属性：sendResponse(responseApdu: number[]): void;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：HceService<br>方法 or 属性：sendResponse(responseApdu: number[]): void;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap有变化|类名：tag<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：const NFC_A = 1;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：const NFC_A = 1;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：const NFC_B = 2;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：const NFC_B = 2;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：const ISO_DEP = 3;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：const ISO_DEP = 3;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：const NFC_F = 4;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：const NFC_F = 4;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：const NFC_V = 5;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：const NFC_V = 5;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：const NDEF = 6;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：const NDEF = 6;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：const MIFARE_CLASSIC = 8;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：const MIFARE_CLASSIC = 8;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：const MIFARE_ULTRALIGHT = 9;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：const MIFARE_ULTRALIGHT = 9;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>SysCap:SystemCapability.Communication.NFC.Core|类名：tag<br>方法 or 属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：TagInfo<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagInfo<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：TagInfo<br>方法 or 属性：supportedProfiles: number[];<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagInfo<br>方法 or 属性：supportedProfiles: number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap有变化|类名：NfcATag<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcATag<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcATag<br>方法 or 属性：getSak(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcATag<br>方法 or 属性：getSak(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcATag<br>方法 or 属性：getAtqa(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcATag<br>方法 or 属性：getAtqa(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcBTag<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcBTag<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcBTag<br>方法 or 属性：getRespAppData(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcBTag<br>方法 or 属性：getRespAppData(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcBTag<br>方法 or 属性：getRespProtocol(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcBTag<br>方法 or 属性：getRespProtocol(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcFTag<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcFTag<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcFTag<br>方法 or 属性：getSystemCode(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcFTag<br>方法 or 属性：getSystemCode(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcFTag<br>方法 or 属性：getPmm(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcFTag<br>方法 or 属性：getPmm(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcVTag<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcVTag<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcVTag<br>方法 or 属性：getResponseFlags(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcVTag<br>方法 or 属性：getResponseFlags(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：NfcVTag<br>方法 or 属性：getDsfId(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：NfcVTag<br>方法 or 属性：getDsfId(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap有变化|类名：TagSession<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap有变化|类名：TagSession<br>方法 or 属性：getTagInfo(): tag.TagInfo;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>方法 or 属性：getTagInfo(): tag.TagInfo;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap有变化|类名：TagSession<br>方法 or 属性：connectTag(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>方法 or 属性：connectTag(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap有变化|类名：TagSession<br>方法 or 属性：reset(): void;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>方法 or 属性：reset(): void;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap有变化|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>方法 or 属性：isTagConnected(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap有变化|类名：TagSession<br>方法 or 属性：setSendDataTimeout(timeout: number): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>方法 or 属性：setSendDataTimeout(timeout: number): boolean;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap有变化|类名：TagSession<br>方法 or 属性：getSendDataTimeout(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>方法 or 属性：getSendDataTimeout(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap有变化|类名：TagSession<br>方法 or 属性：sendData(data: number[]): Promise\<number[]>;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>方法 or 属性：sendData(data: number[]): Promise\<number[]>;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap有变化|类名：TagSession<br>方法 or 属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>方法 or 属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap有变化|类名：TagSession<br>方法 or 属性：getMaxSendLength(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|类名：TagSession<br>方法 or 属性：getMaxSendLength(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
