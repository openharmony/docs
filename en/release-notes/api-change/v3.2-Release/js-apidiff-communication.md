| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function getState(): BluetoothState;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function getBtConnectionState(): ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function pairDevice(deviceId: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function cancelPairedDevice(deviceId: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function getRemoteDeviceName(deviceId: string): string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function getRemoteDeviceClass(deviceId: string): DeviceClass;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function enableBluetooth(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function disableBluetooth(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function getLocalName(): string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function getPairedDevices(): Array\<string>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function getProfileConnectionState(profileId: ProfileId): ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function setDevicePairingConfirmation(device: string, accept: boolean): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function setLocalName(name: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function setBluetoothScanMode(mode: ScanMode, duration: number): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function getBluetoothScanMode(): ScanMode;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function startBluetoothDiscovery(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function stopBluetoothDiscovery(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function on(type: "bondStateChange", callback: Callback\<BondStateParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function on(type: "stateChange", callback: Callback\<BluetoothState>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function off(type: "stateChange", callback?: Callback\<BluetoothState>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function sppCloseServerSocket(socket: number): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function sppCloseClientSocket(socket: number): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function sppWrite(clientSocket: number, data: ArrayBuffer): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: bluetoothManager<br>Method or attribute name: function getProfileInstance(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile \| HidHostProfile \| PanProfile;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BaseProfile|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BaseProfile<br>Method or attribute name: getConnectionDevices(): Array\<string>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BaseProfile<br>Method or attribute name: getDeviceState(device: string): ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: A2dpSourceProfile|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: A2dpSourceProfile<br>Method or attribute name: connect(device: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: A2dpSourceProfile<br>Method or attribute name: disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: A2dpSourceProfile<br>Method or attribute name: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: A2dpSourceProfile<br>Method or attribute name: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: A2dpSourceProfile<br>Method or attribute name: getPlayingState(device: string): PlayingState;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HandsFreeAudioGatewayProfile|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: connect(device: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HidHostProfile|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HidHostProfile<br>Method or attribute name: connect(device: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HidHostProfile<br>Method or attribute name: disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HidHostProfile<br>Method or attribute name: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: HidHostProfile<br>Method or attribute name: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PanProfile|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PanProfile<br>Method or attribute name: disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PanProfile<br>Method or attribute name: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PanProfile<br>Method or attribute name: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PanProfile<br>Method or attribute name: setTethering(enable: boolean): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PanProfile<br>Method or attribute name: isTetheringOn(): boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLE|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLE<br>Method or attribute name: function createGattServer(): GattServer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLE<br>Method or attribute name: function createGattClientDevice(deviceId: string): GattClientDevice;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLE<br>Method or attribute name: function getConnectedBLEDevices(): Array\<string>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLE<br>Method or attribute name: function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLE<br>Method or attribute name: function stopBLEScan(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLE<br>Method or attribute name: function on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLE<br>Method or attribute name: function off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: stopAdvertising(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: addService(service: GattService): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: removeService(serviceUuid: string): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: close(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: sendResponse(serverResponse: ServerResponse): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: on(type: "characteristicRead", callback: Callback\<CharacteristicReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: off(type: "characteristicRead", callback?: Callback\<CharacteristicReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: on(type: "descriptorRead", callback: Callback\<DescriptorReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: off(type: "descriptorRead", callback?: Callback\<DescriptorReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: on(type: "descriptorWrite", callback: Callback\<DescriptorWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattServer<br>Method or attribute name: off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: connect(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: disconnect(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: close(): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: getDeviceName(callback: AsyncCallback\<string>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: getDeviceName(): Promise\<string>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: getServices(callback: AsyncCallback\<Array\<GattService>>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: getServices(): Promise\<Array\<GattService>>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: writeCharacteristicValue(characteristic: BLECharacteristic): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: writeDescriptorValue(descriptor: BLEDescriptor): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: getRssiValue(callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: getRssiValue(): Promise\<number>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: setBLEMtuSize(mtu: number): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattClientDevice<br>Method or attribute name: off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattService|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattService<br>Method or attribute name: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattService<br>Method or attribute name: isPrimary: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattService<br>Method or attribute name: characteristics: Array\<BLECharacteristic>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: GattService<br>Method or attribute name: includeServices?: Array\<GattService>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLECharacteristic|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLECharacteristic<br>Method or attribute name: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLECharacteristic<br>Method or attribute name: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLECharacteristic<br>Method or attribute name: characteristicValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLECharacteristic<br>Method or attribute name: descriptors: Array\<BLEDescriptor>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLEDescriptor|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLEDescriptor<br>Method or attribute name: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLEDescriptor<br>Method or attribute name: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLEDescriptor<br>Method or attribute name: descriptorUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLEDescriptor<br>Method or attribute name: descriptorValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: NotifyCharacteristic|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: NotifyCharacteristic<br>Method or attribute name: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: NotifyCharacteristic<br>Method or attribute name: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: NotifyCharacteristic<br>Method or attribute name: characteristicValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: NotifyCharacteristic<br>Method or attribute name: confirm: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicReadRequest|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicReadRequest<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicReadRequest<br>Method or attribute name: transId: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicReadRequest<br>Method or attribute name: offset: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicReadRequest<br>Method or attribute name: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicReadRequest<br>Method or attribute name: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicWriteRequest|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicWriteRequest<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicWriteRequest<br>Method or attribute name: transId: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicWriteRequest<br>Method or attribute name: offset: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicWriteRequest<br>Method or attribute name: isPrep: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicWriteRequest<br>Method or attribute name: needRsp: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicWriteRequest<br>Method or attribute name: value: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicWriteRequest<br>Method or attribute name: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: CharacteristicWriteRequest<br>Method or attribute name: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorReadRequest|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorReadRequest<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorReadRequest<br>Method or attribute name: transId: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorReadRequest<br>Method or attribute name: offset: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorReadRequest<br>Method or attribute name: descriptorUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorReadRequest<br>Method or attribute name: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorReadRequest<br>Method or attribute name: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest<br>Method or attribute name: transId: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest<br>Method or attribute name: offset: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest<br>Method or attribute name: isPrep: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest<br>Method or attribute name: needRsp: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest<br>Method or attribute name: value: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest<br>Method or attribute name: descriptorUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest<br>Method or attribute name: characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DescriptorWriteRequest<br>Method or attribute name: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ServerResponse|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ServerResponse<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ServerResponse<br>Method or attribute name: transId: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ServerResponse<br>Method or attribute name: status: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ServerResponse<br>Method or attribute name: offset: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ServerResponse<br>Method or attribute name: value: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLEConnectChangedState|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLEConnectChangedState<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BLEConnectChangedState<br>Method or attribute name: state: ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanResult|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanResult<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanResult<br>Method or attribute name: rssi: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanResult<br>Method or attribute name: data: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: AdvertiseSetting|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: AdvertiseSetting<br>Method or attribute name: interval?: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: AdvertiseSetting<br>Method or attribute name: txPower?: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: AdvertiseSetting<br>Method or attribute name: connectable?: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: AdvertiseData|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: AdvertiseData<br>Method or attribute name: serviceUuids: Array\<string>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: AdvertiseData<br>Method or attribute name: manufactureData: Array\<ManufactureData>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: AdvertiseData<br>Method or attribute name: serviceData: Array\<ServiceData>;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ManufactureData|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ManufactureData<br>Method or attribute name: manufactureId: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ManufactureData<br>Method or attribute name: manufactureValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ServiceData|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ServiceData<br>Method or attribute name: serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ServiceData<br>Method or attribute name: serviceValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: deviceId?: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: name?: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: serviceUuid?: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: serviceUuidMask?: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: serviceSolicitationUuid?: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: serviceSolicitationUuidMask?: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: serviceData?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: serviceDataMask?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: manufactureId?: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: manufactureData?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanFilter<br>Method or attribute name: manufactureDataMask?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanOptions|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanOptions<br>Method or attribute name: interval?: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanOptions<br>Method or attribute name: dutyMode?: ScanDuty;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanOptions<br>Method or attribute name: matchMode?: MatchMode;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: SppOption|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: SppOption<br>Method or attribute name: uuid: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: SppOption<br>Method or attribute name: secure: boolean;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: SppOption<br>Method or attribute name: type: SppType;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinRequiredParam|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinRequiredParam<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PinRequiredParam<br>Method or attribute name: pinCode: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DeviceClass|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DeviceClass<br>Method or attribute name: majorClass: MajorClass;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DeviceClass<br>Method or attribute name: majorMinorClass: MajorMinorClass;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: DeviceClass<br>Method or attribute name: classOfDevice: number;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BondStateParam|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BondStateParam<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BondStateParam<br>Method or attribute name: state: BondState;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: StateChangeParam|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: StateChangeParam<br>Method or attribute name: deviceId: string;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: StateChangeParam<br>Method or attribute name: state: ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanDuty|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanDuty<br>Method or attribute name: SCAN_MODE_LOW_POWER = 0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanDuty<br>Method or attribute name: SCAN_MODE_BALANCED = 1|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanDuty<br>Method or attribute name: SCAN_MODE_LOW_LATENCY = 2|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MatchMode|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MatchMode<br>Method or attribute name: MATCH_MODE_AGGRESSIVE = 1|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MatchMode<br>Method or attribute name: MATCH_MODE_STICKY = 2|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileConnectionState|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileConnectionState<br>Method or attribute name: STATE_DISCONNECTED = 0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileConnectionState<br>Method or attribute name: STATE_CONNECTING = 1|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileConnectionState<br>Method or attribute name: STATE_CONNECTED = 2|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileConnectionState<br>Method or attribute name: STATE_DISCONNECTING = 3|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BluetoothState|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BluetoothState<br>Method or attribute name: STATE_OFF = 0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BluetoothState<br>Method or attribute name: STATE_TURNING_ON = 1|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BluetoothState<br>Method or attribute name: STATE_ON = 2|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BluetoothState<br>Method or attribute name: STATE_TURNING_OFF = 3|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BluetoothState<br>Method or attribute name: STATE_BLE_TURNING_ON = 4|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BluetoothState<br>Method or attribute name: STATE_BLE_ON = 5|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BluetoothState<br>Method or attribute name: STATE_BLE_TURNING_OFF = 6|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: SppType|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: SppType<br>Method or attribute name: SPP_RFCOMM|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanMode|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanMode<br>Method or attribute name: SCAN_MODE_NONE = 0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanMode<br>Method or attribute name: SCAN_MODE_CONNECTABLE = 1|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanMode<br>Method or attribute name: SCAN_MODE_GENERAL_DISCOVERABLE = 2|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanMode<br>Method or attribute name: SCAN_MODE_LIMITED_DISCOVERABLE = 3|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanMode<br>Method or attribute name: SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ScanMode<br>Method or attribute name: SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BondState|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BondState<br>Method or attribute name: BOND_STATE_INVALID = 0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BondState<br>Method or attribute name: BOND_STATE_BONDING = 1|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: BondState<br>Method or attribute name: BOND_STATE_BONDED = 2|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_MISC = 0x0000|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_COMPUTER = 0x0100|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_PHONE = 0x0200|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_NETWORKING = 0x0300|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_AUDIO_VIDEO = 0x0400|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_PERIPHERAL = 0x0500|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_IMAGING = 0x0600|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_WEARABLE = 0x0700|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_TOY = 0x0800|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_HEALTH = 0x0900|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorClass<br>Method or attribute name: MAJOR_UNCATEGORIZED = 0x1F00|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: COMPUTER_UNCATEGORIZED = 0x0100|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: COMPUTER_DESKTOP = 0x0104|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: COMPUTER_SERVER = 0x0108|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: COMPUTER_LAPTOP = 0x010C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: COMPUTER_HANDHELD_PC_PDA = 0x0110|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: COMPUTER_PALM_SIZE_PC_PDA = 0x0114|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: COMPUTER_WEARABLE = 0x0118|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: COMPUTER_TABLET = 0x011C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PHONE_UNCATEGORIZED = 0x0200|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PHONE_CELLULAR = 0x0204|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PHONE_CORDLESS = 0x0208|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PHONE_SMART = 0x020C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PHONE_MODEM_OR_GATEWAY = 0x0210|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PHONE_ISDN = 0x0214|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: NETWORK_FULLY_AVAILABLE = 0x0300|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: NETWORK_1_TO_17_UTILIZED = 0x0320|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: NETWORK_17_TO_33_UTILIZED = 0x0340|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: NETWORK_33_TO_50_UTILIZED = 0x0360|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: NETWORK_60_TO_67_UTILIZED = 0x0380|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: NETWORK_67_TO_83_UTILIZED = 0x03A0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: NETWORK_83_TO_99_UTILIZED = 0x03C0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: NETWORK_NO_SERVICE = 0x03E0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_UNCATEGORIZED = 0x0400|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_HANDSFREE = 0x0408|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_MICROPHONE = 0x0410|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_LOUDSPEAKER = 0x0414|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_HEADPHONES = 0x0418|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_CAR_AUDIO = 0x0420|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_SET_TOP_BOX = 0x0424|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_HIFI_AUDIO = 0x0428|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_VCR = 0x042C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_VIDEO_CAMERA = 0x0430|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_CAMCORDER = 0x0434|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_VIDEO_MONITOR = 0x0438|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_KEYBOARD = 0x0540|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_POINTING_DEVICE = 0x0580|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_KEYBOARD_POINTING = 0x05C0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_UNCATEGORIZED = 0x0500|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_JOYSTICK = 0x0504|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_GAMEPAD = 0x0508|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_REMOTE_CONTROL = 0x05C0|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_SENSING_DEVICE = 0x0510|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_DIGITIZER_TABLET = 0x0514|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_CARD_READER = 0x0518|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_DIGITAL_PEN = 0x051C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_SCANNER_RFID = 0x0520|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: PERIPHERAL_GESTURAL_INPUT = 0x0522|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: IMAGING_UNCATEGORIZED = 0x0600|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: IMAGING_DISPLAY = 0x0610|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: IMAGING_CAMERA = 0x0620|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: IMAGING_SCANNER = 0x0640|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: IMAGING_PRINTER = 0x0680|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: WEARABLE_UNCATEGORIZED = 0x0700|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: WEARABLE_WRIST_WATCH = 0x0704|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: WEARABLE_PAGER = 0x0708|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: WEARABLE_JACKET = 0x070C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: WEARABLE_HELMET = 0x0710|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: WEARABLE_GLASSES = 0x0714|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: TOY_UNCATEGORIZED = 0x0800|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: TOY_ROBOT = 0x0804|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: TOY_VEHICLE = 0x0808|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: TOY_DOLL_ACTION_FIGURE = 0x080C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: TOY_CONTROLLER = 0x0810|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: TOY_GAME = 0x0814|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_UNCATEGORIZED = 0x0900|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_BLOOD_PRESSURE = 0x0904|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_THERMOMETER = 0x0908|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_WEIGHING = 0x090C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_GLUCOSE = 0x0910|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_PULSE_OXIMETER = 0x0914|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_PULSE_RATE = 0x0918|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_DATA_DISPLAY = 0x091C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_STEP_COUNTER = 0x0920|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_PEAK_FLOW_MONITOR = 0x0928|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_MEDICATION_MONITOR = 0x092C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_KNEE_PROSTHESIS = 0x0930|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_ANKLE_PROSTHESIS = 0x0934|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_GENERIC_HEALTH_MANAGER = 0x0938|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: MajorMinorClass<br>Method or attribute name: HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PlayingState|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PlayingState<br>Method or attribute name: STATE_NOT_PLAYING|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: PlayingState<br>Method or attribute name: STATE_PLAYING|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileId|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileId<br>Method or attribute name: PROFILE_A2DP_SOURCE = 1|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileId<br>Method or attribute name: PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileId<br>Method or attribute name: PROFILE_HID_HOST = 6|@ohos.bluetoothManager.d.ts|
|Added|NA|Module name: ohos.bluetoothManager<br>Class name: ProfileId<br>Method or attribute name: PROFILE_PAN_NETWORK = 7|@ohos.bluetoothManager.d.ts|
|Added|NA|Class name: connectedTag<br>Method or attribute name: function initialize(): void;|@ohos.connectedTag.d.ts|
|Added|NA|Class name: connectedTag<br>Method or attribute name: function uninitialize(): void;|@ohos.connectedTag.d.ts|
|Added|NA|Class name: connectedTag<br>Method or attribute name: function read(): Promise\<number[]>;|@ohos.connectedTag.d.ts|
|Added|NA|Class name: connectedTag<br>Method or attribute name: function read(callback: AsyncCallback\<number[]>): void;|@ohos.connectedTag.d.ts|
|Added|NA|Class name: connectedTag<br>Method or attribute name: function write(data: number[]): Promise\<void>;|@ohos.connectedTag.d.ts|
|Added|NA|Class name: connectedTag<br>Method or attribute name: function write(data: number[], callback: AsyncCallback\<void>): void;|@ohos.connectedTag.d.ts|
|Added|NA|Class name: connection<br>Method or attribute name: function getDefaultNetSync(): NetHandle;|@ohos.net.connection.d.ts|
|Added|NA|Class name: connection<br>Method or attribute name: function isDefaultNetMetered(callback: AsyncCallback\<boolean>): void;|@ohos.net.connection.d.ts|
|Added|NA|Class name: connection<br>Method or attribute name: function isDefaultNetMetered(): Promise\<boolean>;|@ohos.net.connection.d.ts|
|Added|NA|Class name: connection<br>Method or attribute name: function getAppNet(callback: AsyncCallback\<NetHandle>): void;|@ohos.net.connection.d.ts|
|Added|NA|Class name: connection<br>Method or attribute name: function getAppNet(): Promise\<NetHandle>;|@ohos.net.connection.d.ts|
|Added|NA|Class name: connection<br>Method or attribute name: function setAppNet(netHandle: NetHandle, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|Added|NA|Class name: connection<br>Method or attribute name: function setAppNet(netHandle: NetHandle): Promise\<void>;|@ohos.net.connection.d.ts|
|Added|NA|Class name: NetHandle<br>Method or attribute name: bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|Added|NA|Class name: NetHandle<br>Method or attribute name: bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;|@ohos.net.connection.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function isIfaceActive(iface: string, callback: AsyncCallback\<number>): void;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function isIfaceActive(iface: string): Promise\<number>;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: ethernet<br>Method or attribute name: function getAllActiveIfaces(): Promise\<Array\<string>>;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: InterfaceConfiguration|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: InterfaceConfiguration<br>Method or attribute name: mode: IPSetMode;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: InterfaceConfiguration<br>Method or attribute name: ipAddr: string;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: InterfaceConfiguration<br>Method or attribute name: route: string;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: InterfaceConfiguration<br>Method or attribute name: gateway: string;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: InterfaceConfiguration<br>Method or attribute name: netMask: string;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: InterfaceConfiguration<br>Method or attribute name: dnsServers: string;|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: IPSetMode|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: IPSetMode<br>Method or attribute name: STATIC = 0|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.ethernet<br>Class name: IPSetMode<br>Method or attribute name: DHCP = 1|@ohos.net.ethernet.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequestOptions<br>Method or attribute name: expectDataType?: HttpDataType;|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpRequestOptions<br>Method or attribute name: expectDataType?: HttpDataType;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequestOptions<br>Method or attribute name: usingCache?: boolean;|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpRequestOptions<br>Method or attribute name: usingCache?: boolean;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequestOptions<br>Method or attribute name: priority?: number;|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpRequestOptions<br>Method or attribute name: priority?: number;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpRequestOptions<br>Method or attribute name: usingProtocol?: HttpProtocol;|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpRequestOptions<br>Method or attribute name: usingProtocol?: HttpProtocol;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpProtocol|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpProtocol<br>Method or attribute name: |@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpProtocol<br>Method or attribute name: HTTP1_1|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpProtocol<br>Method or attribute name: HTTP1_1|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpProtocol<br>Method or attribute name: HTTP2|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpProtocol<br>Method or attribute name: HTTP2|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpDataType|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpDataType<br>Method or attribute name: |@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpDataType<br>Method or attribute name: STRING|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpDataType<br>Method or attribute name: STRING|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpDataType<br>Method or attribute name: OBJECT = 1|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpDataType<br>Method or attribute name: OBJECT = 1|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpDataType<br>Method or attribute name: ARRAY_BUFFER = 2|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpDataType<br>Method or attribute name: ARRAY_BUFFER = 2|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpResponse<br>Method or attribute name: resultType: HttpDataType;|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpResponse<br>Method or attribute name: resultType: HttpDataType;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: http<br>Method or attribute name: function createHttpResponseCache(cacheSize?: number): HttpResponseCache;|@ohos.net.http.d.ts|
|Added|NA|Class name: http<br>Method or attribute name: function createHttpResponseCache(cacheSize?: number): HttpResponseCache;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpResponseCache|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpResponseCache<br>Method or attribute name: |@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpResponseCache<br>Method or attribute name: flush(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpResponseCache<br>Method or attribute name: flush(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpResponseCache<br>Method or attribute name: flush(): Promise\<void>;|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpResponseCache<br>Method or attribute name: flush(): Promise\<void>;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpResponseCache<br>Method or attribute name: delete(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpResponseCache<br>Method or attribute name: delete(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.http<br>Class name: HttpResponseCache<br>Method or attribute name: delete(): Promise\<void>;|@ohos.net.http.d.ts|
|Added|NA|Class name: HttpResponseCache<br>Method or attribute name: delete(): Promise\<void>;|@ohos.net.http.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function isSharingSupported(callback: AsyncCallback\<boolean>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function isSharingSupported(): Promise\<boolean>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function isSharing(callback: AsyncCallback\<boolean>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function isSharing(): Promise\<boolean>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function startSharing(type: SharingIfaceType): Promise\<void>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function stopSharing(type: SharingIfaceType): Promise\<void>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getStatsRxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getStatsRxBytes(): Promise\<number>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getStatsTxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getStatsTxBytes(): Promise\<number>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getStatsTotalBytes(callback: AsyncCallback\<number>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getStatsTotalBytes(): Promise\<number>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function on(type: 'sharingStateChange', callback: Callback\<boolean>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: sharing<br>Method or attribute name: function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: SharingIfaceState|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: SharingIfaceState<br>Method or attribute name: SHARING_NIC_SERVING = 1|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: SharingIfaceState<br>Method or attribute name: SHARING_NIC_CAN_SERVER = 2|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: SharingIfaceState<br>Method or attribute name: SHARING_NIC_ERROR = 3|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: SharingIfaceType|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: SharingIfaceType<br>Method or attribute name: SHARING_WIFI = 0|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: SharingIfaceType<br>Method or attribute name: SHARING_USB = 1|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.sharing<br>Class name: SharingIfaceType<br>Method or attribute name: SHARING_BLUETOOTH = 2|@ohos.net.sharing.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: socket<br>Method or attribute name: function constructTLSSocketInstance(): TLSSocket;|@ohos.net.socket.d.ts|
|Added|NA|Class name: socket<br>Method or attribute name: function constructTLSSocketInstance(): TLSSocket;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TCPExtraOptions<br>Method or attribute name: socketLinger?: {on: boolean, linger: number};|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: |@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: bind(address: NetAddress, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: bind(address: NetAddress, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: bind(address: NetAddress): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: bind(address: NetAddress): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getRemoteAddress(): Promise\<NetAddress>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getRemoteAddress(): Promise\<NetAddress>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getState(callback: AsyncCallback\<SocketStateBase>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getState(callback: AsyncCallback\<SocketStateBase>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getState(): Promise\<SocketStateBase>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getState(): Promise\<SocketStateBase>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: setExtraOptions(options: TCPExtraOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: setExtraOptions(options: TCPExtraOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: on(type: 'connect' \| 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: on(type: 'connect' \| 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: on(type: 'connect' \| 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: on(type: 'connect' \| 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: off(type: 'connect' \| 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: off(type: 'connect' \| 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: off(type: 'connect' \| 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: off(type: 'connect' \| 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getRemoteCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getRemoteCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getRemoteCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getRemoteCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getProtocol(callback: AsyncCallback\<string>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getProtocol(callback: AsyncCallback\<string>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getProtocol(): Promise\<string>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getProtocol(): Promise\<string>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getCipherSuite(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getCipherSuite(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getCipherSuite(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getCipherSuite(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: getSignatureAlgorithms(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: getSignatureAlgorithms(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: connect(options: TLSConnectOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: connect(options: TLSConnectOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: connect(options: TLSConnectOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: connect(options: TLSConnectOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: send(data: string, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: send(data: string, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: send(data: string): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: send(data: string): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: close(callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: close(callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSocket<br>Method or attribute name: close(): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSocket<br>Method or attribute name: close(): Promise\<void>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSecureOptions|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSecureOptions<br>Method or attribute name: |@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSecureOptions<br>Method or attribute name: ca: string \| Array\<string>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSecureOptions<br>Method or attribute name: ca: string \| Array\<string>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSecureOptions<br>Method or attribute name: cert?: string;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSecureOptions<br>Method or attribute name: cert?: string;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSecureOptions<br>Method or attribute name: key?: string;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSecureOptions<br>Method or attribute name: key?: string;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSecureOptions<br>Method or attribute name: password?: string;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSecureOptions<br>Method or attribute name: password?: string;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSecureOptions<br>Method or attribute name: protocols?: Protocol \| Array\<Protocol>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSecureOptions<br>Method or attribute name: protocols?: Protocol \| Array\<Protocol>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSecureOptions<br>Method or attribute name: useRemoteCipherPrefer?: boolean;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSecureOptions<br>Method or attribute name: useRemoteCipherPrefer?: boolean;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSecureOptions<br>Method or attribute name: signatureAlgorithms?: string;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSecureOptions<br>Method or attribute name: signatureAlgorithms?: string;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSSecureOptions<br>Method or attribute name: cipherSuite?: string;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSSecureOptions<br>Method or attribute name: cipherSuite?: string;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSConnectOptions|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSConnectOptions<br>Method or attribute name: |@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSConnectOptions<br>Method or attribute name: address: NetAddress;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSConnectOptions<br>Method or attribute name: address: NetAddress;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSConnectOptions<br>Method or attribute name: secureOptions: TLSSecureOptions;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSConnectOptions<br>Method or attribute name: secureOptions: TLSSecureOptions;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: TLSConnectOptions<br>Method or attribute name: ALPNProtocols?: Array\<string>;|@ohos.net.socket.d.ts|
|Added|NA|Class name: TLSConnectOptions<br>Method or attribute name: ALPNProtocols?: Array\<string>;|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: Protocol|@ohos.net.socket.d.ts|
|Added|NA|Class name: Protocol<br>Method or attribute name: |@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: Protocol<br>Method or attribute name: TLSv12 = "TLSv1.2"|@ohos.net.socket.d.ts|
|Added|NA|Class name: Protocol<br>Method or attribute name: TLSv12 = "TLSv1.2"|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.net.socket<br>Class name: Protocol<br>Method or attribute name: TLSv13 = "TLSv1.3"|@ohos.net.socket.d.ts|
|Added|NA|Class name: Protocol<br>Method or attribute name: TLSv13 = "TLSv1.3"|@ohos.net.socket.d.ts|
|Added|NA|Module name: ohos.nfc.cardEmulation<br>Class name: CardType|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: CardType<br>Method or attribute name: |@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Module name: ohos.nfc.cardEmulation<br>Class name: CardType<br>Method or attribute name: PAYMENT = "payment"|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: CardType<br>Method or attribute name: PAYMENT = "payment"|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Module name: ohos.nfc.cardEmulation<br>Class name: CardType<br>Method or attribute name: OTHER = "other"|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: CardType<br>Method or attribute name: OTHER = "other"|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: cardEmulation<br>Method or attribute name: function hasHceCapability(): boolean;|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: cardEmulation<br>Method or attribute name: function isDefaultService(elementName: ElementName, type: CardType): boolean;|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: HceService<br>Method or attribute name: start(elementName: ElementName, aidList: string[]): void|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: HceService<br>Method or attribute name: stop(elementName: ElementName): void|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: HceService<br>Method or attribute name: transmit(response: number[]): Promise\<void>;|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: HceService<br>Method or attribute name: transmit(response: number[], callback: AsyncCallback\<void>): void;|@ohos.nfc.cardEmulation.d.ts|
|Added|NA|Class name: nfcController<br>Method or attribute name: function enableNfc(): void|@ohos.nfc.controller.d.ts|
|Added|NA|Class name: nfcController<br>Method or attribute name: function disableNfc(): void|@ohos.nfc.controller.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: const NDEF_FORMATABLE = 7;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: TnfType|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TnfType<br>Method or attribute name: |@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: TnfType<br>Method or attribute name: TNF_EMPTY = 0x0|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TnfType<br>Method or attribute name: TNF_EMPTY = 0x0|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: TnfType<br>Method or attribute name: TNF_WELL_KNOWN = 0x1|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TnfType<br>Method or attribute name: TNF_WELL_KNOWN = 0x1|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: TnfType<br>Method or attribute name: TNF_MEDIA = 0x2|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TnfType<br>Method or attribute name: TNF_MEDIA = 0x2|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: TnfType<br>Method or attribute name: TNF_ABSOLUTE_URI = 0x3|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TnfType<br>Method or attribute name: TNF_ABSOLUTE_URI = 0x3|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: TnfType<br>Method or attribute name: TNF_EXT_APP = 0x4|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TnfType<br>Method or attribute name: TNF_EXT_APP = 0x4|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: TnfType<br>Method or attribute name: TNF_UNKNOWN = 0x5|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TnfType<br>Method or attribute name: TNF_UNKNOWN = 0x5|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: TnfType<br>Method or attribute name: TNF_UNCHANGED = 0x6|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TnfType<br>Method or attribute name: TNF_UNCHANGED = 0x6|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NfcForumType|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NfcForumType<br>Method or attribute name: |@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NfcForumType<br>Method or attribute name: NFC_FORUM_TYPE_1 = 1|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NfcForumType<br>Method or attribute name: NFC_FORUM_TYPE_1 = 1|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NfcForumType<br>Method or attribute name: NFC_FORUM_TYPE_2 = 2|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NfcForumType<br>Method or attribute name: NFC_FORUM_TYPE_2 = 2|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NfcForumType<br>Method or attribute name: NFC_FORUM_TYPE_3 = 3|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NfcForumType<br>Method or attribute name: NFC_FORUM_TYPE_3 = 3|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NfcForumType<br>Method or attribute name: NFC_FORUM_TYPE_4 = 4|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NfcForumType<br>Method or attribute name: NFC_FORUM_TYPE_4 = 4|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NfcForumType<br>Method or attribute name: MIFARE_CLASSIC = 101|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NfcForumType<br>Method or attribute name: MIFARE_CLASSIC = 101|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: const RTD_TEXT: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: const RTD_URI: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicType|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicType<br>Method or attribute name: |@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicType<br>Method or attribute name: TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicType<br>Method or attribute name: TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicType<br>Method or attribute name: TYPE_CLASSIC = 1|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicType<br>Method or attribute name: TYPE_CLASSIC = 1|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicType<br>Method or attribute name: TYPE_PLUS = 2|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicType<br>Method or attribute name: TYPE_PLUS = 2|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicType<br>Method or attribute name: TYPE_PRO = 3|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicType<br>Method or attribute name: TYPE_PRO = 3|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicSize|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicSize<br>Method or attribute name: |@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicSize<br>Method or attribute name: MC_SIZE_MINI = 320|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicSize<br>Method or attribute name: MC_SIZE_MINI = 320|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicSize<br>Method or attribute name: MC_SIZE_1K = 1024|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicSize<br>Method or attribute name: MC_SIZE_1K = 1024|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicSize<br>Method or attribute name: MC_SIZE_2K = 2048|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicSize<br>Method or attribute name: MC_SIZE_2K = 2048|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareClassicSize<br>Method or attribute name: MC_SIZE_4K = 4096|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareClassicSize<br>Method or attribute name: MC_SIZE_4K = 4096|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareUltralightType|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareUltralightType<br>Method or attribute name: |@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareUltralightType<br>Method or attribute name: TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareUltralightType<br>Method or attribute name: TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareUltralightType<br>Method or attribute name: TYPE_ULTRALIGHT = 1|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareUltralightType<br>Method or attribute name: TYPE_ULTRALIGHT = 1|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: MifareUltralightType<br>Method or attribute name: TYPE_ULTRALIGHT_C = 2|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: MifareUltralightType<br>Method or attribute name: TYPE_ULTRALIGHT_C = 2|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getNfcA(tagInfo: TagInfo): NfcATag|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getNfcB(tagInfo: TagInfo): NfcBTag|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getNfcF(tagInfo: TagInfo): NfcFTag|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getNfcV(tagInfo: TagInfo): NfcVTag|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getIsoDep(tagInfo: TagInfo): IsoDepTag|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getNdef(tagInfo: TagInfo): NdefTag|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getMifareClassic(tagInfo: TagInfo): MifareClassicTag|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getMifareUltralight(tagInfo: TagInfo): MifareUltralightTag|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getNdefFormatable(tagInfo: TagInfo): NdefFormatableTag|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: tag<br>Method or attribute name: function getTagInfo(want: Want): TagInfo|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TagInfo<br>Method or attribute name: uid: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TagInfo<br>Method or attribute name: technology: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TagInfo<br>Method or attribute name: extrasData: PacMap[];|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TagInfo<br>Method or attribute name: tagRfDiscId: number;|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: TagInfo<br>Method or attribute name: remoteTagService: rpc.RemoteObject;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NdefRecord|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NdefRecord<br>Method or attribute name: |@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NdefRecord<br>Method or attribute name: tnf: number;|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NdefRecord<br>Method or attribute name: tnf: number;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NdefRecord<br>Method or attribute name: rtdType: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NdefRecord<br>Method or attribute name: rtdType: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NdefRecord<br>Method or attribute name: id: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NdefRecord<br>Method or attribute name: id: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: NdefRecord<br>Method or attribute name: payload: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: NdefRecord<br>Method or attribute name: payload: number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: ndef|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: ndef<br>Method or attribute name: |@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: ndef<br>Method or attribute name: function makeUriRecord(uri: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: ndef<br>Method or attribute name: function makeUriRecord(uri: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: ndef<br>Method or attribute name: function makeTextRecord(text: string, locale: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: ndef<br>Method or attribute name: function makeTextRecord(text: string, locale: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: ndef<br>Method or attribute name: function makeMimeRecord(mimeType: string, mimeData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: ndef<br>Method or attribute name: function makeMimeRecord(mimeType: string, mimeData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: ndef<br>Method or attribute name: function makeExternalRecord(domainName: string, type: string, externalData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: ndef<br>Method or attribute name: function makeExternalRecord(domainName: string, type: string, externalData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: ndef<br>Method or attribute name: function createNdefMessage(data: number[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: ndef<br>Method or attribute name: function createNdefMessage(data: number[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: ndef<br>Method or attribute name: function createNdefMessage(ndefRecords: NdefRecord[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: ndef<br>Method or attribute name: function createNdefMessage(ndefRecords: NdefRecord[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.nfc.tag<br>Class name: ndef<br>Method or attribute name: function messageToBytes(ndefMessage: NdefMessage): number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Class name: ndef<br>Method or attribute name: function messageToBytes(ndefMessage: NdefMessage): number[];|@ohos.nfc.tag.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: |@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: CHECK_PARAM_ERROR = 401|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: CHECK_PARAM_ERROR = 401|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: OS_MMAP_ERROR = 1900001|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: OS_MMAP_ERROR = 1900001|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: OS_IOCTL_ERROR = 1900002|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: OS_IOCTL_ERROR = 1900002|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: WRITE_TO_ASHMEM_ERROR = 1900003|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: WRITE_TO_ASHMEM_ERROR = 1900003|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: READ_FROM_ASHMEM_ERROR = 1900004|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: READ_FROM_ASHMEM_ERROR = 1900004|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: ONLY_PROXY_OBJECT_PERMITTED_ERROR = 1900005|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: ONLY_PROXY_OBJECT_PERMITTED_ERROR = 1900005|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: ONLY_REMOTE_OBJECT_PERMITTED_ERROR = 1900006|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: ONLY_REMOTE_OBJECT_PERMITTED_ERROR = 1900006|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: COMMUNICATION_ERROR = 1900007|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: COMMUNICATION_ERROR = 1900007|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: PROXY_OR_REMOTE_OBJECT_INVALID_ERROR = 1900008|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: PROXY_OR_REMOTE_OBJECT_INVALID_ERROR = 1900008|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: WRITE_DATA_TO_MESSAGE_SEQUENCE_ERROR = 1900009|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: WRITE_DATA_TO_MESSAGE_SEQUENCE_ERROR = 1900009|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: READ_DATA_FROM_MESSAGE_SEQUENCE_ERROR = 1900010|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: READ_DATA_FROM_MESSAGE_SEQUENCE_ERROR = 1900010|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: PARCEL_MEMORY_ALLOC_ERROR = 1900011|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: PARCEL_MEMORY_ALLOC_ERROR = 1900011|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: CALL_JS_METHOD_ERROR = 1900012|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: CALL_JS_METHOD_ERROR = 1900012|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: ErrorCode<br>Method or attribute name: OS_DUP_ERROR = 1900013|@ohos.rpc.d.ts|
|Added|NA|Class name: ErrorCode<br>Method or attribute name: OS_DUP_ERROR = 1900013|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: |@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: static create(): MessageSequence;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: static create(): MessageSequence;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: reclaim(): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: reclaim(): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeRemoteObject(object: IRemoteObject): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeRemoteObject(object: IRemoteObject): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readRemoteObject(): IRemoteObject;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readRemoteObject(): IRemoteObject;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeInterfaceToken(token: string): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeInterfaceToken(token: string): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readInterfaceToken(): string;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readInterfaceToken(): string;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: getSize(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: getSize(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: getCapacity(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: getCapacity(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: setSize(size: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: setSize(size: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: setCapacity(size: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: setCapacity(size: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: getWritableBytes(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: getWritableBytes(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: getReadableBytes(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: getReadableBytes(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: getReadPosition(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: getReadPosition(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: getWritePosition(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: getWritePosition(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: rewindRead(pos: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: rewindRead(pos: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: rewindWrite(pos: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: rewindWrite(pos: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeNoException(): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeNoException(): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readException(): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readException(): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeByte(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeByte(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeShort(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeShort(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeInt(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeInt(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeLong(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeLong(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeFloat(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeFloat(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeDouble(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeDouble(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeBoolean(val: boolean): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeBoolean(val: boolean): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeChar(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeChar(val: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeString(val: string): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeString(val: string): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeParcelable(val: Parcelable): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeParcelable(val: Parcelable): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeByteArray(byteArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeByteArray(byteArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeShortArray(shortArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeShortArray(shortArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeIntArray(intArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeIntArray(intArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeLongArray(longArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeLongArray(longArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeFloatArray(floatArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeFloatArray(floatArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeDoubleArray(doubleArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeDoubleArray(doubleArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeBooleanArray(booleanArray: boolean[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeBooleanArray(booleanArray: boolean[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeCharArray(charArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeCharArray(charArray: number[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeStringArray(stringArray: string[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeStringArray(stringArray: string[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeRemoteObjectArray(objectArray: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeRemoteObjectArray(objectArray: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readByte(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readByte(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readShort(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readShort(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readInt(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readInt(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readLong(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readLong(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readFloat(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readFloat(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readDouble(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readDouble(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readBoolean(): boolean;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readBoolean(): boolean;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readChar(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readChar(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readString(): string;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readString(): string;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readParcelable(dataIn: Parcelable) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readParcelable(dataIn: Parcelable) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readByteArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readByteArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readByteArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readByteArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readShortArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readShortArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readShortArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readShortArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readIntArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readIntArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readIntArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readIntArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readLongArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readLongArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readLongArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readLongArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readFloatArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readFloatArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readFloatArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readFloatArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readDoubleArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readDoubleArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readDoubleArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readDoubleArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readBooleanArray(dataIn: boolean[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readBooleanArray(dataIn: boolean[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readBooleanArray(): boolean[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readBooleanArray(): boolean[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readCharArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readCharArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readCharArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readCharArray(): number[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readStringArray(dataIn: string[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readStringArray(dataIn: string[]) : void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readStringArray(): string[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readStringArray(): string[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readRemoteObjectArray(objects: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readRemoteObjectArray(objects: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readRemoteObjectArray(): IRemoteObject[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readRemoteObjectArray(): IRemoteObject[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: static closeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: static closeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: static dupFileDescriptor(fd: number) :number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: static dupFileDescriptor(fd: number) :number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: containFileDescriptors(): boolean;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: containFileDescriptors(): boolean;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readFileDescriptor(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readFileDescriptor(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeAshmem(ashmem: Ashmem): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeAshmem(ashmem: Ashmem): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readAshmem(): Ashmem;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readAshmem(): Ashmem;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: getRawDataCapacity(): number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: getRawDataCapacity(): number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: writeRawData(rawData: number[], size: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: writeRawData(rawData: number[], size: number): void;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: MessageSequence<br>Method or attribute name: readRawData(size: number): number[];|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageSequence<br>Method or attribute name: readRawData(size: number): number[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: Parcelable|@ohos.rpc.d.ts|
|Added|NA|Class name: Parcelable<br>Method or attribute name: |@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: Parcelable<br>Method or attribute name: marshalling(dataOut: MessageSequence): boolean;|@ohos.rpc.d.ts|
|Added|NA|Class name: Parcelable<br>Method or attribute name: marshalling(dataOut: MessageSequence): boolean;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: Parcelable<br>Method or attribute name: unmarshalling(dataIn: MessageSequence) : boolean;|@ohos.rpc.d.ts|
|Added|NA|Class name: Parcelable<br>Method or attribute name: unmarshalling(dataIn: MessageSequence) : boolean;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: RequestResult|@ohos.rpc.d.ts|
|Added|NA|Class name: RequestResult<br>Method or attribute name: |@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: RequestResult<br>Method or attribute name: errCode: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: RequestResult<br>Method or attribute name: errCode: number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: RequestResult<br>Method or attribute name: code: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: RequestResult<br>Method or attribute name: code: number;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: RequestResult<br>Method or attribute name: data: MessageSequence;|@ohos.rpc.d.ts|
|Added|NA|Class name: RequestResult<br>Method or attribute name: data: MessageSequence;|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.rpc<br>Class name: RequestResult<br>Method or attribute name: reply: MessageSequence;|@ohos.rpc.d.ts|
|Added|NA|Class name: RequestResult<br>Method or attribute name: reply: MessageSequence;|@ohos.rpc.d.ts|
|Added|NA|Class name: IRemoteObject<br>Method or attribute name: getLocalInterface(descriptor: string): IRemoteBroker;|@ohos.rpc.d.ts|
|Added|NA|Class name: IRemoteObject<br>Method or attribute name: sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise\<RequestResult>;|@ohos.rpc.d.ts|
|Added|NA|Class name: IRemoteObject<br>Method or attribute name: sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback\<RequestResult>): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: IRemoteObject<br>Method or attribute name: registerDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: IRemoteObject<br>Method or attribute name: unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: IRemoteObject<br>Method or attribute name: getDescriptor(): string;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageOption<br>Method or attribute name: TF_SYNC: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageOption<br>Method or attribute name: TF_ASYNC: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageOption<br>Method or attribute name: TF_ACCEPT_FDS: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageOption<br>Method or attribute name: TF_WAIT_TIME: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageOption<br>Method or attribute name: constructor(syncFlags?: number, waitTime?: number);|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageOption<br>Method or attribute name: constructor(async?: boolean);|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageOption<br>Method or attribute name: isAsync(): boolean;|@ohos.rpc.d.ts|
|Added|NA|Class name: MessageOption<br>Method or attribute name: setAsync(async: boolean): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteObject<br>Method or attribute name: getLocalInterface(descriptor: string): IRemoteBroker;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteObject<br>Method or attribute name: getDescriptor(): string;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteObject<br>Method or attribute name: onRemoteMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): boolean \| Promise\<boolean>;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteObject<br>Method or attribute name: sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise\<RequestResult>;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteObject<br>Method or attribute name: sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback\<RequestResult>): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteObject<br>Method or attribute name: modifyLocalInterface(localInterface: IRemoteBroker, descriptor: string): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: PING_TRANSACTION: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: DUMP_TRANSACTION: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: INTERFACE_TRANSACTION: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: MIN_TRANSACTION_ID: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: MAX_TRANSACTION_ID: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: getLocalInterface(interface: string): IRemoteBroker;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: registerDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: getDescriptor(): string;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise\<RequestResult>;|@ohos.rpc.d.ts|
|Added|NA|Class name: RemoteProxy<br>Method or attribute name: sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback\<RequestResult>): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: IPCSkeleton<br>Method or attribute name: static flushCmdBuffer(object: IRemoteObject): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: IPCSkeleton<br>Method or attribute name: static restoreCallingIdentity(identity: string): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: PROT_EXEC: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: PROT_NONE: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: PROT_READ: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: PROT_WRITE: number;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: static create(name: string, size: number): Ashmem;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: static create(ashmem: Ashmem): Ashmem;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: mapTypedAshmem(mapType: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: mapReadWriteAshmem(): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: mapReadonlyAshmem(): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: setProtectionType(protectionType: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: writeAshmem(buf: number[], size: number, offset: number): void;|@ohos.rpc.d.ts|
|Added|NA|Class name: Ashmem<br>Method or attribute name: readAshmem(size: number, offset: number): number[];|@ohos.rpc.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function enableWifi(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function disableWifi(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function isWifiActive(): boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function scan(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getScanResults(): Promise\<Array\<WifiScanInfo>>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getScanResultsSync(): Array\<WifiScanInfo>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function addDeviceConfig(config: WifiDeviceConfig): Promise\<number>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function addCandidateConfig(config: WifiDeviceConfig): Promise\<number>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function removeCandidateConfig(networkId: number): Promise\<void>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getCandidateConfigs(): Array\<WifiDeviceConfig>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function connectToCandidateConfig(networkId: number): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function connectToNetwork(networkId: number): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function connectToDevice(config: WifiDeviceConfig): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function disconnect(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getSignalLevel(rssi: number, band: number): number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getLinkedInfo(): Promise\<WifiLinkedInfo>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function isConnected(): boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getSupportedFeatures(): number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function isFeatureSupported(featureId: number): boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getDeviceMacAddress(): string[];|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getIpInfo(): IpInfo;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getCountryCode(): string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function reassociate(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function reconnect(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getDeviceConfigs(): Array\<WifiDeviceConfig>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function updateNetwork(config: WifiDeviceConfig): number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function disableNetwork(netId: number): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function removeAllNetwork(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function removeDevice(id: number): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function enableHotspot(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function disableHotspot(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function isHotspotDualBandSupported(): boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function isHotspotActive(): boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function setHotspotConfig(config: HotspotConfig): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getHotspotConfig(): HotspotConfig;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getStations(): Array\<StationInfo>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getP2pLocalDevice(): Promise\<WifiP2pDevice>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function createGroup(config: WifiP2PConfig): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function removeGroup(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function p2pConnect(config: WifiP2PConfig): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function p2pCancelConnect(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function startDiscoverDevices(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function stopDiscoverDevices(): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function deletePersistentGroup(netId: number): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function setDeviceName(devName: string): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "wifiStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "wifiStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "wifiConnectionChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "wifiConnectionChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "wifiScanStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "wifiScanStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "wifiRssiChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "wifiRssiChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "streamChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "streamChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "deviceConfigChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "deviceConfigChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "hotspotStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "hotspotStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "p2pStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "p2pStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function on(type: "p2pDiscoveryChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: wifiManager<br>Method or attribute name: function off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod<br>Method or attribute name: EAP_NONE|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod<br>Method or attribute name: EAP_PEAP|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod<br>Method or attribute name: EAP_TLS|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod<br>Method or attribute name: EAP_TTLS|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod<br>Method or attribute name: EAP_PWD|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod<br>Method or attribute name: EAP_SIM|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod<br>Method or attribute name: EAP_AKA|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod<br>Method or attribute name: EAP_AKA_PRIME|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: EapMethod<br>Method or attribute name: EAP_UNAUTH_TLS|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: Phase2Method|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: Phase2Method<br>Method or attribute name: PHASE2_NONE|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: Phase2Method<br>Method or attribute name: PHASE2_PAP|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: Phase2Method<br>Method or attribute name: PHASE2_MSCHAP|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: Phase2Method<br>Method or attribute name: PHASE2_MSCHAPV2|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: Phase2Method<br>Method or attribute name: PHASE2_GTC|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: Phase2Method<br>Method or attribute name: PHASE2_SIM|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: Phase2Method<br>Method or attribute name: PHASE2_AKA|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: Phase2Method<br>Method or attribute name: PHASE2_AKA_PRIME|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: eapMethod: EapMethod;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: phase2Method: Phase2Method;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: identity: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: anonymousIdentity: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: password: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: caCertAliases: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: caPath: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: clientCertAliases: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: certEntry: Uint8Array;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: certPassword: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: altSubjectMatch: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: domainSuffixMatch: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: realm: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: plmn: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiEapConfig<br>Method or attribute name: eapSubId: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: ssid: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: bssid?: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: preSharedKey: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: isHiddenSsid?: boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: securityType: WifiSecurityType;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: creatorUid?: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: disableReason?: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: netId?: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: randomMacType?: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: randomMacAddr?: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: ipType?: IpType;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: staticIp?: IpConfig;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiDeviceConfig<br>Method or attribute name: eapConfig?: WifiEapConfig;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpConfig|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpConfig<br>Method or attribute name: ipAddress: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpConfig<br>Method or attribute name: gateway: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpConfig<br>Method or attribute name: prefixLength: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpConfig<br>Method or attribute name: dnsServers: number[];|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpConfig<br>Method or attribute name: domains: Array\<string>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiInfoElem|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiInfoElem<br>Method or attribute name: eid: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiInfoElem<br>Method or attribute name: content: Uint8Array;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiChannelWidth|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiChannelWidth<br>Method or attribute name: WIDTH_20MHZ = 0|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiChannelWidth<br>Method or attribute name: WIDTH_40MHZ = 1|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiChannelWidth<br>Method or attribute name: WIDTH_80MHZ = 2|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiChannelWidth<br>Method or attribute name: WIDTH_160MHZ = 3|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiChannelWidth<br>Method or attribute name: WIDTH_80MHZ_PLUS = 4|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiChannelWidth<br>Method or attribute name: WIDTH_INVALID|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: ssid: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: bssid: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: capabilities: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: securityType: WifiSecurityType;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: rssi: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: band: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: frequency: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: channelWidth: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: centerFrequency0: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: centerFrequency1: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: infoElems: Array\<WifiInfoElem>;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiScanInfo<br>Method or attribute name: timestamp: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_INVALID = 0|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_OPEN = 1|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_WEP = 2|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_PSK = 3|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_SAE = 4|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_EAP = 5|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_EAP_SUITE_B = 6|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_OWE = 7|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_WAPI_CERT = 8|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiSecurityType<br>Method or attribute name: WIFI_SEC_TYPE_WAPI_PSK = 9|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: ssid: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: bssid: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: networkId: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: rssi: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: band: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: linkSpeed: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: frequency: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: isHidden: boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: isRestricted: boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: chload: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: snr: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: macType: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: macAddress: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: ipAddress: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: suppState: SuppState;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiLinkedInfo<br>Method or attribute name: connState: ConnState;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpInfo|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpInfo<br>Method or attribute name: ipAddress: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpInfo<br>Method or attribute name: gateway: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpInfo<br>Method or attribute name: netmask: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpInfo<br>Method or attribute name: primaryDns: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpInfo<br>Method or attribute name: secondDns: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpInfo<br>Method or attribute name: serverIp: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpInfo<br>Method or attribute name: leaseDuration: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: HotspotConfig|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: HotspotConfig<br>Method or attribute name: ssid: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: HotspotConfig<br>Method or attribute name: securityType: WifiSecurityType;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: HotspotConfig<br>Method or attribute name: band: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: HotspotConfig<br>Method or attribute name: preSharedKey: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: HotspotConfig<br>Method or attribute name: maxConn: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: StationInfo|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: StationInfo<br>Method or attribute name: name: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: StationInfo<br>Method or attribute name: macAddress: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: StationInfo<br>Method or attribute name: ipAddress: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpType|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpType<br>Method or attribute name: STATIC|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpType<br>Method or attribute name: DHCP|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: IpType<br>Method or attribute name: UNKNOWN|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: DISCONNECTED|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: INTERFACE_DISABLED|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: INACTIVE|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: SCANNING|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: AUTHENTICATING|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: ASSOCIATING|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: ASSOCIATED|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: FOUR_WAY_HANDSHAKE|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: GROUP_HANDSHAKE|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: COMPLETED|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: UNINITIALIZED|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: SuppState<br>Method or attribute name: INVALID|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: ConnState|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: ConnState<br>Method or attribute name: SCANNING|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: ConnState<br>Method or attribute name: CONNECTING|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: ConnState<br>Method or attribute name: AUTHENTICATING|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: ConnState<br>Method or attribute name: OBTAINING_IPADDR|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: ConnState<br>Method or attribute name: CONNECTED|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: ConnState<br>Method or attribute name: DISCONNECTING|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: ConnState<br>Method or attribute name: DISCONNECTED|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: ConnState<br>Method or attribute name: UNKNOWN|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pDevice|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pDevice<br>Method or attribute name: deviceName: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pDevice<br>Method or attribute name: deviceAddress: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pDevice<br>Method or attribute name: primaryDeviceType: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pDevice<br>Method or attribute name: deviceStatus: P2pDeviceStatus;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pDevice<br>Method or attribute name: groupCapabilities: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2PConfig|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2PConfig<br>Method or attribute name: deviceAddress: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2PConfig<br>Method or attribute name: netId: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2PConfig<br>Method or attribute name: passphrase: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2PConfig<br>Method or attribute name: groupName: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2PConfig<br>Method or attribute name: goBand: GroupOwnerBand;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo<br>Method or attribute name: isP2pGo: boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo<br>Method or attribute name: ownerInfo: WifiP2pDevice;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo<br>Method or attribute name: passphrase: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo<br>Method or attribute name: interface: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo<br>Method or attribute name: groupName: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo<br>Method or attribute name: networkId: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo<br>Method or attribute name: frequency: number;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo<br>Method or attribute name: clientDevices: WifiP2pDevice[];|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pGroupInfo<br>Method or attribute name: goIpAddress: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: P2pConnectState|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: P2pConnectState<br>Method or attribute name: DISCONNECTED = 0|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: P2pConnectState<br>Method or attribute name: CONNECTED = 1|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pLinkedInfo|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pLinkedInfo<br>Method or attribute name: connectState: P2pConnectState;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pLinkedInfo<br>Method or attribute name: isGroupOwner: boolean;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: WifiP2pLinkedInfo<br>Method or attribute name: groupOwnerAddr: string;|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: P2pDeviceStatus|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: P2pDeviceStatus<br>Method or attribute name: CONNECTED = 0|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: P2pDeviceStatus<br>Method or attribute name: INVITED = 1|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: P2pDeviceStatus<br>Method or attribute name: FAILED = 2|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: P2pDeviceStatus<br>Method or attribute name: AVAILABLE = 3|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: P2pDeviceStatus<br>Method or attribute name: UNAVAILABLE = 4|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: GroupOwnerBand|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: GroupOwnerBand<br>Method or attribute name: GO_BAND_AUTO = 0|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: GroupOwnerBand<br>Method or attribute name: GO_BAND_2GHZ = 1|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManager<br>Class name: GroupOwnerBand<br>Method or attribute name: GO_BAND_5GHZ = 2|@ohos.wifiManager.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: wifiManagerExt|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: wifiManagerExt<br>Method or attribute name: function enableHotspot(): void;|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: wifiManagerExt<br>Method or attribute name: function disableHotspot(): void;|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: wifiManagerExt<br>Method or attribute name: function getSupportedPowerMode(): Promise\<Array\<PowerMode>>;|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: wifiManagerExt<br>Method or attribute name: function getSupportedPowerMode(callback: AsyncCallback\<Array\<PowerMode>>): void;|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: wifiManagerExt<br>Method or attribute name: function getPowerMode (): Promise\<PowerMode>;|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: wifiManagerExt<br>Method or attribute name: function getPowerMode (callback: AsyncCallback\<PowerMode>): void;|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: wifiManagerExt<br>Method or attribute name: function setPowerMode(mode: PowerMode) : void|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: PowerMode|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: PowerMode<br>Method or attribute name: SLEEPING = 0|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: PowerMode<br>Method or attribute name: GENERAL = 1|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: ohos.wifiManagerExt<br>Class name: PowerMode<br>Method or attribute name: THROUGH_WALL = 2|@ohos.wifiManagerExt.d.ts|
|Added|NA|Module name: nfctech<br>Class name: IsoDepTag|nfctech.d.ts|
|Added|NA|Class name: IsoDepTag<br>Method or attribute name: |nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: IsoDepTag<br>Method or attribute name: getHistoricalBytes(): number[];|nfctech.d.ts|
|Added|NA|Class name: IsoDepTag<br>Method or attribute name: getHistoricalBytes(): number[];|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: IsoDepTag<br>Method or attribute name: getHiLayerResponse(): number[];|nfctech.d.ts|
|Added|NA|Class name: IsoDepTag<br>Method or attribute name: getHiLayerResponse(): number[];|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: IsoDepTag<br>Method or attribute name: isExtendedApduSupported(): Promise\<boolean>;|nfctech.d.ts|
|Added|NA|Class name: IsoDepTag<br>Method or attribute name: isExtendedApduSupported(): Promise\<boolean>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: IsoDepTag<br>Method or attribute name: isExtendedApduSupported(callback: AsyncCallback\<boolean>): void;|nfctech.d.ts|
|Added|NA|Class name: IsoDepTag<br>Method or attribute name: isExtendedApduSupported(callback: AsyncCallback\<boolean>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefMessage|nfctech.d.ts|
|Added|NA|Class name: NdefMessage<br>Method or attribute name: |nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefMessage<br>Method or attribute name: getNdefRecords(): tag.NdefRecord[];|nfctech.d.ts|
|Added|NA|Class name: NdefMessage<br>Method or attribute name: getNdefRecords(): tag.NdefRecord[];|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: |nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: getNdefTagType(): tag.NfcForumType;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: getNdefTagType(): tag.NfcForumType;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: getNdefMessage(): NdefMessage;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: getNdefMessage(): NdefMessage;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: isNdefWritable(): boolean;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: isNdefWritable(): boolean;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: readNdef(): Promise\<NdefMessage>;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: readNdef(): Promise\<NdefMessage>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: readNdef(callback: AsyncCallback\<NdefMessage>): void;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: readNdef(callback: AsyncCallback\<NdefMessage>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: writeNdef(msg: NdefMessage): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: writeNdef(msg: NdefMessage): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: writeNdef(msg: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: writeNdef(msg: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: canSetReadOnly(): boolean;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: canSetReadOnly(): boolean;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: setReadOnly(): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: setReadOnly(): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: setReadOnly(callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: setReadOnly(callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefTag<br>Method or attribute name: getNdefTagTypeString(type: tag.NfcForumType): string;|nfctech.d.ts|
|Added|NA|Class name: NdefTag<br>Method or attribute name: getNdefTagTypeString(type: tag.NfcForumType): string;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: |nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: readSingleBlock(blockIndex: number): Promise\<number[]>;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: readSingleBlock(blockIndex: number): Promise\<number[]>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: writeSingleBlock(blockIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: writeSingleBlock(blockIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: incrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: incrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: decrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: decrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: transferToBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: transferToBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: restoreFromBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: restoreFromBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: getSectorCount(): number;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: getSectorCount(): number;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: getBlockCountInSector(sectorIndex: number): number;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: getBlockCountInSector(sectorIndex: number): number;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: getType(): tag.MifareClassicType;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: getType(): tag.MifareClassicType;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: getTagSize(): number;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: getTagSize(): number;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: isEmulatedTag(): boolean;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: isEmulatedTag(): boolean;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: getBlockIndex(sectorIndex: number): number;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: getBlockIndex(sectorIndex: number): number;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareClassicTag<br>Method or attribute name: getSectorIndex(blockIndex: number): number;|nfctech.d.ts|
|Added|NA|Class name: MifareClassicTag<br>Method or attribute name: getSectorIndex(blockIndex: number): number;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareUltralightTag|nfctech.d.ts|
|Added|NA|Class name: MifareUltralightTag<br>Method or attribute name: |nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareUltralightTag<br>Method or attribute name: readMultiplePages(pageIndex: number): Promise\<number[]>;|nfctech.d.ts|
|Added|NA|Class name: MifareUltralightTag<br>Method or attribute name: readMultiplePages(pageIndex: number): Promise\<number[]>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareUltralightTag<br>Method or attribute name: readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|Added|NA|Class name: MifareUltralightTag<br>Method or attribute name: readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareUltralightTag<br>Method or attribute name: writeSinglePage(pageIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: MifareUltralightTag<br>Method or attribute name: writeSinglePage(pageIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareUltralightTag<br>Method or attribute name: writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: MifareUltralightTag<br>Method or attribute name: writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: MifareUltralightTag<br>Method or attribute name: getType(): tag.MifareUltralightType;|nfctech.d.ts|
|Added|NA|Class name: MifareUltralightTag<br>Method or attribute name: getType(): tag.MifareUltralightType;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefFormatableTag|nfctech.d.ts|
|Added|NA|Class name: NdefFormatableTag<br>Method or attribute name: |nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefFormatableTag<br>Method or attribute name: format(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: NdefFormatableTag<br>Method or attribute name: format(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefFormatableTag<br>Method or attribute name: format(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: NdefFormatableTag<br>Method or attribute name: format(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefFormatableTag<br>Method or attribute name: formatReadOnly(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|Added|NA|Class name: NdefFormatableTag<br>Method or attribute name: formatReadOnly(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|Added|NA|Module name: nfctech<br>Class name: NdefFormatableTag<br>Method or attribute name: formatReadOnly(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: NdefFormatableTag<br>Method or attribute name: formatReadOnly(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|Added|NA|Class name: TagSession<br>Method or attribute name: connect(): void;|tagSession.d.ts|
|Added|NA|Class name: TagSession<br>Method or attribute name: resetConnection(): void;|tagSession.d.ts|
|Added|NA|Class name: TagSession<br>Method or attribute name: isConnected(): boolean;|tagSession.d.ts|
|Added|NA|Class name: TagSession<br>Method or attribute name: setTimeout(timeout: number): void;|tagSession.d.ts|
|Added|NA|Class name: TagSession<br>Method or attribute name: getTimeout(): number;|tagSession.d.ts|
|Added|NA|Class name: TagSession<br>Method or attribute name: transmit(data: number[]): Promise\<number[]>;|tagSession.d.ts|
|Added|NA|Class name: TagSession<br>Method or attribute name: transmit(data: number[], callback: AsyncCallback\<number[]>): void;|tagSession.d.ts|
|Added|NA|Class name: TagSession<br>Method or attribute name: getMaxTransmitSize(): number;|tagSession.d.ts|
|Deleted|Module name: ohos.rpc<br>Class name: IRemoteObject|NA|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Deprecated version: N/A|Class name: bluetooth<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function getState(): BluetoothState;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function getState(): BluetoothState;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.getState     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function getBtConnectionState(): ProfileConnectionState;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function getBtConnectionState(): ProfileConnectionState;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.getBtConnectionState     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function pairDevice(deviceId: string): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function pairDevice(deviceId: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.pairDevice     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function cancelPairedDevice(deviceId: string): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function cancelPairedDevice(deviceId: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.cancelPairedDevice     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function getRemoteDeviceName(deviceId: string): string;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function getRemoteDeviceName(deviceId: string): string;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.getRemoteDeviceName     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.getRemoteDeviceClass     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function enableBluetooth(): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function enableBluetooth(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.enableBluetooth     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function disableBluetooth(): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function disableBluetooth(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.disableBluetooth     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function getLocalName(): string;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function getLocalName(): string;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.getLocalName     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function getPairedDevices(): Array\<string>;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function getPairedDevices(): Array\<string>;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.getPairedDevices     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function getProfileConnState(profileId: ProfileId): ProfileConnectionState;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function getProfileConnState(profileId: ProfileId): ProfileConnectionState;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.getProfileConnectionState     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function setDevicePairingConfirmation(device: string, accept: boolean): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function setDevicePairingConfirmation(device: string, accept: boolean): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.setDevicePairingConfirmation     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function setLocalName(name: string): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function setLocalName(name: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.setLocalName     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function setBluetoothScanMode(mode: ScanMode, duration: number): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function setBluetoothScanMode(mode: ScanMode, duration: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.setBluetoothScanMode     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function getBluetoothScanMode(): ScanMode;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function getBluetoothScanMode(): ScanMode;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.getBluetoothScanMode     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function startBluetoothDiscovery(): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function startBluetoothDiscovery(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.startBluetoothDiscovery     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function stopBluetoothDiscovery(): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function stopBluetoothDiscovery(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.stopBluetoothDiscovery     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function on(type: "bondStateChange", callback: Callback\<BondStateParam>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function on(type: "bondStateChange", callback: Callback\<BondStateParam>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function on(type: "stateChange", callback: Callback\<BluetoothState>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function on(type: "stateChange", callback: Callback\<BluetoothState>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function off(type: "stateChange", callback?: Callback\<BluetoothState>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function off(type: "stateChange", callback?: Callback\<BluetoothState>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.sppListen     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.sppAccept     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.sppConnect     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function sppCloseServerSocket(socket: number): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function sppCloseServerSocket(socket: number): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.sppCloseServerSocket     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function sppCloseClientSocket(socket: number): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function sppCloseClientSocket(socket: number): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.sppCloseClientSocket     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function sppWrite(clientSocket: number, data: ArrayBuffer): boolean;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function sppWrite(clientSocket: number, data: ArrayBuffer): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.sppWrite     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.on|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.off|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth<br>Method or attribute name: function getProfile(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile;<br>Deprecated version: N/A|Class name: bluetooth<br>Method or attribute name: function getProfile(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.getProfileInstance     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BaseProfile<br>Deprecated version: N/A|Class name: BaseProfile<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BaseProfile     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BaseProfile<br>Method or attribute name: getConnectionDevices(): Array\<string>;<br>Deprecated version: N/A|Class name: BaseProfile<br>Method or attribute name: getConnectionDevices(): Array\<string>;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BaseProfile|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BaseProfile<br>Method or attribute name: getDeviceState(device: string): ProfileConnectionState;<br>Deprecated version: N/A|Class name: BaseProfile<br>Method or attribute name: getDeviceState(device: string): ProfileConnectionState;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BaseProfile|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: A2dpSourceProfile<br>Deprecated version: N/A|Class name: A2dpSourceProfile<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: A2dpSourceProfile<br>Method or attribute name: connect(device: string): boolean;<br>Deprecated version: N/A|Class name: A2dpSourceProfile<br>Method or attribute name: connect(device: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: A2dpSourceProfile<br>Method or attribute name: disconnect(device: string): boolean;<br>Deprecated version: N/A|Class name: A2dpSourceProfile<br>Method or attribute name: disconnect(device: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: A2dpSourceProfile<br>Method or attribute name: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>Deprecated version: N/A|Class name: A2dpSourceProfile<br>Method or attribute name: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile.on|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: A2dpSourceProfile<br>Method or attribute name: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>Deprecated version: N/A|Class name: A2dpSourceProfile<br>Method or attribute name: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile.off|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: A2dpSourceProfile<br>Method or attribute name: getPlayingState(device: string): PlayingState;<br>Deprecated version: N/A|Class name: A2dpSourceProfile<br>Method or attribute name: getPlayingState(device: string): PlayingState;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: HandsFreeAudioGatewayProfile<br>Deprecated version: N/A|Class name: HandsFreeAudioGatewayProfile<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: connect(device: string): boolean;<br>Deprecated version: N/A|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: connect(device: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: disconnect(device: string): boolean;<br>Deprecated version: N/A|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: disconnect(device: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>Deprecated version: N/A|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile.on|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>Deprecated version: N/A|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile.off|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLE<br>Method or attribute name: function createGattServer(): GattServer;<br>Deprecated version: N/A|Class name: BLE<br>Method or attribute name: function createGattServer(): GattServer;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLE.createGattServer         |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLE<br>Method or attribute name: function createGattClientDevice(deviceId: string): GattClientDevice;<br>Deprecated version: N/A|Class name: BLE<br>Method or attribute name: function createGattClientDevice(deviceId: string): GattClientDevice;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLE.createGattClientDevice         |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLE<br>Method or attribute name: function getConnectedBLEDevices(): Array\<string>;<br>Deprecated version: N/A|Class name: BLE<br>Method or attribute name: function getConnectedBLEDevices(): Array\<string>;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLE.getConnectedBLEDevices         |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLE<br>Method or attribute name: function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>Deprecated version: N/A|Class name: BLE<br>Method or attribute name: function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLE.startBLEScan         |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLE<br>Method or attribute name: function stopBLEScan(): void;<br>Deprecated version: N/A|Class name: BLE<br>Method or attribute name: function stopBLEScan(): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLE.stopBLEScan         |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLE<br>Method or attribute name: function on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void;<br>Deprecated version: N/A|Class name: BLE<br>Method or attribute name: function on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLE.on|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLE<br>Method or attribute name: function off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void;<br>Deprecated version: N/A|Class name: BLE<br>Method or attribute name: function off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLE.off|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Deprecated version: N/A|Class name: GattServer<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: stopAdvertising(): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: stopAdvertising(): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: addService(service: GattService): boolean;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: addService(service: GattService): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: removeService(serviceUuid: string): boolean;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: removeService(serviceUuid: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: close(): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: close(): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: sendResponse(serverResponse: ServerResponse): boolean;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: sendResponse(serverResponse: ServerResponse): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: on(type: "characteristicRead", callback: Callback\<CharacteristicReadReq>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: on(type: "characteristicRead", callback: Callback\<CharacteristicReadReq>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: off(type: "characteristicRead", callback?: Callback\<CharacteristicReadReq>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: off(type: "characteristicRead", callback?: Callback\<CharacteristicReadReq>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteReq>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteReq>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteReq>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteReq>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: on(type: "descriptorRead", callback: Callback\<DescriptorReadReq>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: on(type: "descriptorRead", callback: Callback\<DescriptorReadReq>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: off(type: "descriptorRead", callback?: Callback\<DescriptorReadReq>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: off(type: "descriptorRead", callback?: Callback\<DescriptorReadReq>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteReq>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteReq>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattServer<br>Method or attribute name: off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>Deprecated version: N/A|Class name: GattServer<br>Method or attribute name: off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Deprecated version: N/A|Class name: GattClientDevice<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: connect(): boolean;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: connect(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: disconnect(): boolean;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: disconnect(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: close(): boolean;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: close(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: getDeviceName(callback: AsyncCallback\<string>): void;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: getDeviceName(callback: AsyncCallback\<string>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: getDeviceName(): Promise\<string>;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: getDeviceName(): Promise\<string>;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: getServices(): Promise\<Array\<GattService>>;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: getServices(): Promise\<Array\<GattService>>;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: writeCharacteristicValue(characteristic: BLECharacteristic): boolean;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: writeCharacteristicValue(characteristic: BLECharacteristic): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: writeDescriptorValue(descriptor: BLEDescriptor): boolean;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: writeDescriptorValue(descriptor: BLEDescriptor): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: getRssiValue(callback: AsyncCallback\<number>): void;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: getRssiValue(callback: AsyncCallback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: getRssiValue(): Promise\<number>;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: getRssiValue(): Promise\<number>;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: setBLEMtuSize(mtu: number): boolean;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: setBLEMtuSize(mtu: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattClientDevice<br>Method or attribute name: off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>Deprecated version: N/A|Class name: GattClientDevice<br>Method or attribute name: off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: GattService<br>Deprecated version: N/A|Class name: GattService<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.GattService     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLECharacteristic<br>Deprecated version: N/A|Class name: BLECharacteristic<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLECharacteristic     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLEDescriptor<br>Deprecated version: N/A|Class name: BLEDescriptor<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLEDescriptor     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: NotifyCharacteristic<br>Deprecated version: N/A|Class name: NotifyCharacteristic<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.NotifyCharacteristic     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: CharacteristicReadReq<br>Deprecated version: N/A|Class name: CharacteristicReadReq<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.CharacteristicReadRequest     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: CharacteristicWriteReq<br>Deprecated version: N/A|Class name: CharacteristicWriteReq<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: DescriptorReadReq<br>Deprecated version: N/A|Class name: DescriptorReadReq<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: DescriptorWriteReq<br>Deprecated version: N/A|Class name: DescriptorWriteReq<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ServerResponse<br>Deprecated version: N/A|Class name: ServerResponse<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ServerResponse     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BLEConnectChangedState<br>Deprecated version: N/A|Class name: BLEConnectChangedState<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BLEConnectChangedState     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ScanResult<br>Deprecated version: N/A|Class name: ScanResult<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ScanResult     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: AdvertiseSetting<br>Deprecated version: N/A|Class name: AdvertiseSetting<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.AdvertiseSetting     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: AdvertiseData<br>Deprecated version: N/A|Class name: AdvertiseData<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.AdvertiseData     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ManufactureData<br>Deprecated version: N/A|Class name: ManufactureData<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ManufactureData     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ServiceData<br>Deprecated version: N/A|Class name: ServiceData<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ServiceData     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ScanFilter<br>Deprecated version: N/A|Class name: ScanFilter<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ScanFilter     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ScanOptions<br>Deprecated version: N/A|Class name: ScanOptions<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ScanOptions     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: SppOption<br>Deprecated version: N/A|Class name: SppOption<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.SppOption     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: PinRequiredParam<br>Deprecated version: N/A|Class name: PinRequiredParam<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.PinRequiredParam     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: DeviceClass<br>Deprecated version: N/A|Class name: DeviceClass<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.DeviceClass     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BondStateParam<br>Deprecated version: N/A|Class name: BondStateParam<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BondStateParam     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ScanDuty<br>Deprecated version: N/A|Class name: ScanDuty<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ScanDuty     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: MatchMode<br>Deprecated version: N/A|Class name: MatchMode<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.MatchMode     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ProfileConnectionState<br>Deprecated version: N/A|Class name: ProfileConnectionState<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ProfileConnectionState     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BluetoothState<br>Deprecated version: N/A|Class name: BluetoothState<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BluetoothState     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: SppType<br>Deprecated version: N/A|Class name: SppType<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.SppType     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ScanMode<br>Deprecated version: N/A|Class name: ScanMode<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ScanMode     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: BondState<br>Deprecated version: N/A|Class name: BondState<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.BondState     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: MajorClass<br>Deprecated version: N/A|Class name: MajorClass<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.MajorClass     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: MajorMinorClass<br>Deprecated version: N/A|Class name: MajorMinorClass<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.MajorMinorClass     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: StateChangeParam<br>Deprecated version: N/A|Class name: StateChangeParam<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.StateChangeParam     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: PlayingState<br>Deprecated version: N/A|Class name: PlayingState<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.PlayingState     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: ProfileId<br>Deprecated version: N/A|Class name: ProfileId<br>Deprecated version: 9<br>Substitute API: ohos.bluetoothManager/bluetoothManager.ProfileId     |@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: connectedTag<br>Method or attribute name: function init(): boolean;<br>Deprecated version: N/A|Class name: connectedTag<br>Method or attribute name: function init(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|Deprecated version changed|Class name: connectedTag<br>Method or attribute name: function uninit(): boolean;<br>Deprecated version: N/A|Class name: connectedTag<br>Method or attribute name: function uninit(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|Deprecated version changed|Class name: connectedTag<br>Method or attribute name: function readNdefTag(): Promise\<string>;<br>Deprecated version: N/A|Class name: connectedTag<br>Method or attribute name: function readNdefTag(): Promise\<string>;<br>Deprecated version: 9<br>Substitute API: ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|Deprecated version changed|Class name: connectedTag<br>Method or attribute name: function readNdefTag(callback: AsyncCallback\<string>): void;<br>Deprecated version: N/A|Class name: connectedTag<br>Method or attribute name: function readNdefTag(callback: AsyncCallback\<string>): void;<br>Deprecated version: 9<br>Substitute API: ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|Deprecated version changed|Class name: connectedTag<br>Method or attribute name: function writeNdefTag(data: string): Promise\<void>;<br>Deprecated version: N/A|Class name: connectedTag<br>Method or attribute name: function writeNdefTag(data: string): Promise\<void>;<br>Deprecated version: 9<br>Substitute API: ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|Deprecated version changed|Class name: connectedTag<br>Method or attribute name: function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>Deprecated version: N/A|Class name: connectedTag<br>Method or attribute name: function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>Deprecated version: 9<br>Substitute API: ohos.connectedTag/connectedTag|@ohos.connectedTag.d.ts|
|Deprecated version changed|Class name: FeatureType<br>Deprecated version: N/A|Class name: FeatureType<br>Deprecated version: 9<br>Substitute API: ohos.nfc.cardEmulation/cardEmulation|@ohos.nfc.cardEmulation.d.ts|
|Deprecated version changed|Class name: cardEmulation<br>Method or attribute name: function isSupported(feature: number): boolean;<br>Deprecated version: N/A|Class name: cardEmulation<br>Method or attribute name: function isSupported(feature: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.nfc.cardEmulation/cardEmulation|@ohos.nfc.cardEmulation.d.ts|
|Deprecated version changed|Class name: HceService<br>Method or attribute name: startHCE(aidList: string[]): boolean;<br>Deprecated version: N/A|Class name: HceService<br>Method or attribute name: startHCE(aidList: string[]): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.nfc.cardEmulation/cardEmulation.HceService|@ohos.nfc.cardEmulation.d.ts|
|Deprecated version changed|Class name: HceService<br>Method or attribute name: stopHCE(): boolean;<br>Deprecated version: N/A|Class name: HceService<br>Method or attribute name: stopHCE(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.nfc.cardEmulation/cardEmulation.HceService|@ohos.nfc.cardEmulation.d.ts|
|Deprecated version changed|Class name: HceService<br>Method or attribute name: sendResponse(responseApdu: number[]): void;<br>Deprecated version: N/A|Class name: HceService<br>Method or attribute name: sendResponse(responseApdu: number[]): void;<br>Deprecated version: 9<br>Substitute API: ohos.nfc.cardEmulation/cardEmulation.HceService|@ohos.nfc.cardEmulation.d.ts|
|Deprecated version changed|Class name: nfcController<br>Method or attribute name: function isNfcAvailable(): boolean<br>Deprecated version: N/A|Class name: nfcController<br>Method or attribute name: function isNfcAvailable(): boolean<br>Deprecated version: 9<br>Substitute API: global|@ohos.nfc.controller.d.ts|
|Deprecated version changed|Class name: nfcController<br>Method or attribute name: function openNfc(): boolean<br>Deprecated version: N/A|Class name: nfcController<br>Method or attribute name: function openNfc(): boolean<br>Deprecated version: 9<br>Substitute API: @ohos.nfc.controller.nfcController|@ohos.nfc.controller.d.ts|
|Deprecated version changed|Class name: nfcController<br>Method or attribute name: function closeNfc(): boolean<br>Deprecated version: N/A|Class name: nfcController<br>Method or attribute name: function closeNfc(): boolean<br>Deprecated version: 9<br>Substitute API: @ohos.nfc.controller.nfcController|@ohos.nfc.controller.d.ts|
|Deprecated version changed|Class name: tag<br>Method or attribute name: function getNfcATag(tagInfo: TagInfo): NfcATag<br>Deprecated version: N/A|Class name: tag<br>Method or attribute name: function getNfcATag(tagInfo: TagInfo): NfcATag<br>Deprecated version: 9<br>Substitute API: ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|Deprecated version changed|Class name: tag<br>Method or attribute name: function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>Deprecated version: N/A|Class name: tag<br>Method or attribute name: function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>Deprecated version: 9<br>Substitute API: ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|Deprecated version changed|Class name: tag<br>Method or attribute name: function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>Deprecated version: N/A|Class name: tag<br>Method or attribute name: function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>Deprecated version: 9<br>Substitute API: ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|Deprecated version changed|Class name: tag<br>Method or attribute name: function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>Deprecated version: N/A|Class name: tag<br>Method or attribute name: function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>Deprecated version: 9<br>Substitute API: ohos.nfc.tag/tag|@ohos.nfc.tag.d.ts|
|Deprecated version changed|Class name: TagInfo<br>Method or attribute name: supportedProfiles: number[];<br>Deprecated version: N/A|Class name: TagInfo<br>Method or attribute name: supportedProfiles: number[];<br>Deprecated version: 9<br>Substitute API: ohos.nfc.tag/tag.TagInfo|@ohos.nfc.tag.d.ts|
|Deprecated version changed|Class name: MessageParcel<br>Deprecated version: N/A|Class name: MessageParcel<br>Deprecated version: 9<br>Substitute API: ohos.rpc.MessageSequence     |@ohos.rpc.d.ts|
|Deprecated version changed|Class name: Sequenceable<br>Deprecated version: N/A|Class name: Sequenceable<br>Deprecated version: 9<br>Substitute API: ohos.rpc.Parcelable     |@ohos.rpc.d.ts|
|Deprecated version changed|Class name: SendRequestResult<br>Deprecated version: N/A|Class name: SendRequestResult<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RequestResult     |@ohos.rpc.d.ts|
|Deprecated version changed|Class name: IRemoteObject<br>Method or attribute name: queryLocalInterface(descriptor: string): IRemoteBroker;<br>Deprecated version: N/A|Class name: IRemoteObject<br>Method or attribute name: queryLocalInterface(descriptor: string): IRemoteBroker;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: IRemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>Deprecated version: 8|Class name: IRemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: IRemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>Deprecated version: N/A|Class name: IRemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: IRemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>Deprecated version: N/A|Class name: IRemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: IRemoteObject<br>Method or attribute name: addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>Deprecated version: N/A|Class name: IRemoteObject<br>Method or attribute name: addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: IRemoteObject<br>Method or attribute name: removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>Deprecated version: N/A|Class name: IRemoteObject<br>Method or attribute name: removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: IRemoteObject<br>Method or attribute name: getInterfaceDescriptor(): string;<br>Deprecated version: N/A|Class name: IRemoteObject<br>Method or attribute name: getInterfaceDescriptor(): string;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.IRemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteObject<br>Method or attribute name: queryLocalInterface(descriptor: string): IRemoteBroker;<br>Deprecated version: N/A|Class name: RemoteObject<br>Method or attribute name: queryLocalInterface(descriptor: string): IRemoteBroker;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteObject<br>Method or attribute name: getInterfaceDescriptor(): string;<br>Deprecated version: N/A|Class name: RemoteObject<br>Method or attribute name: getInterfaceDescriptor(): string;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteObject<br>Method or attribute name: onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>Deprecated version: N/A|Class name: RemoteObject<br>Method or attribute name: onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>Deprecated version: N/A|Class name: RemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>Deprecated version: N/A|Class name: RemoteObject<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteObject<br>Method or attribute name: attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void;<br>Deprecated version: N/A|Class name: RemoteObject<br>Method or attribute name: attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteObject|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteProxy<br>Method or attribute name: queryLocalInterface(interface: string): IRemoteBroker;<br>Deprecated version: N/A|Class name: RemoteProxy<br>Method or attribute name: queryLocalInterface(interface: string): IRemoteBroker;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteProxy<br>Method or attribute name: addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>Deprecated version: N/A|Class name: RemoteProxy<br>Method or attribute name: addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteProxy<br>Method or attribute name: removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>Deprecated version: N/A|Class name: RemoteProxy<br>Method or attribute name: removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteProxy<br>Method or attribute name: getInterfaceDescriptor(): string;<br>Deprecated version: N/A|Class name: RemoteProxy<br>Method or attribute name: getInterfaceDescriptor(): string;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteProxy<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>Deprecated version: N/A|Class name: RemoteProxy<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: RemoteProxy<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>Deprecated version: N/A|Class name: RemoteProxy<br>Method or attribute name: sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.RemoteProxy|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: IPCSkeleton<br>Method or attribute name: static flushCommands(object: IRemoteObject): number;<br>Deprecated version: N/A|Class name: IPCSkeleton<br>Method or attribute name: static flushCommands(object: IRemoteObject): number;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.IPCSkeleton|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: IPCSkeleton<br>Method or attribute name: static setCallingIdentity(identity: string): boolean;<br>Deprecated version: N/A|Class name: IPCSkeleton<br>Method or attribute name: static setCallingIdentity(identity: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.IPCSkeleton|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: Ashmem<br>Method or attribute name: static createAshmem(name: string, size: number): Ashmem;<br>Deprecated version: N/A|Class name: Ashmem<br>Method or attribute name: static createAshmem(name: string, size: number): Ashmem;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: Ashmem<br>Method or attribute name: static createAshmemFromExisting(ashmem: Ashmem): Ashmem;<br>Deprecated version: N/A|Class name: Ashmem<br>Method or attribute name: static createAshmemFromExisting(ashmem: Ashmem): Ashmem;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: Ashmem<br>Method or attribute name: mapAshmem(mapType: number): boolean;<br>Deprecated version: N/A|Class name: Ashmem<br>Method or attribute name: mapAshmem(mapType: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: Ashmem<br>Method or attribute name: mapReadAndWriteAshmem(): boolean;<br>Deprecated version: N/A|Class name: Ashmem<br>Method or attribute name: mapReadAndWriteAshmem(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: Ashmem<br>Method or attribute name: mapReadOnlyAshmem(): boolean;<br>Deprecated version: N/A|Class name: Ashmem<br>Method or attribute name: mapReadOnlyAshmem(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: Ashmem<br>Method or attribute name: setProtection(protectionType: number): boolean;<br>Deprecated version: N/A|Class name: Ashmem<br>Method or attribute name: setProtection(protectionType: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: Ashmem<br>Method or attribute name: writeToAshmem(buf: number[], size: number, offset: number): boolean;<br>Deprecated version: N/A|Class name: Ashmem<br>Method or attribute name: writeToAshmem(buf: number[], size: number, offset: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: Ashmem<br>Method or attribute name: readFromAshmem(size: number, offset: number): number[];<br>Deprecated version: N/A|Class name: Ashmem<br>Method or attribute name: readFromAshmem(size: number, offset: number): number[];<br>Deprecated version: 9<br>Substitute API: ohos.rpc.Ashmem|@ohos.rpc.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function enableWifi(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function enableWifi(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.enableWifi     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function disableWifi(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function disableWifi(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.disableWifi     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function isWifiActive(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function isWifiActive(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.isWifiActive     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function scan(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function scan(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.scan     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getScanInfos(): Promise\<Array\<WifiScanInfo>>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getScanInfos(): Promise\<Array\<WifiScanInfo>>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getScanResults     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getScanResults     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function addDeviceConfig(config: WifiDeviceConfig): Promise\<number>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function addDeviceConfig(config: WifiDeviceConfig): Promise\<number>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.addDeviceConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.addDeviceConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.addCandidateConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.addCandidateConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.removeCandidateConfig      |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.removeCandidateConfig      |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function connectToNetwork(networkId: number): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function connectToNetwork(networkId: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.connectToNetwork     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function connectToDevice(config: WifiDeviceConfig): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function connectToDevice(config: WifiDeviceConfig): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.connectToDevice     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function disconnect(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function disconnect(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.disconnect     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getSignalLevel(rssi: number, band: number): number;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getSignalLevel(rssi: number, band: number): number;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getSignalLevel     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getLinkedInfo(): Promise\<WifiLinkedInfo>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getLinkedInfo(): Promise\<WifiLinkedInfo>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getLinkedInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getLinkedInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function isConnected(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function isConnected(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.isConnected     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getSupportedFeatures(): number;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getSupportedFeatures(): number;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getSupportedFeatures     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function isFeatureSupported(featureId: number): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function isFeatureSupported(featureId: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.isFeatureSupported     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getDeviceMacAddress(): string[];<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getDeviceMacAddress(): string[];<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getDeviceMacAddress     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getIpInfo(): IpInfo;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getIpInfo(): IpInfo;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getIpInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getCountryCode(): string;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getCountryCode(): string;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getCountryCode     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function reassociate(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function reassociate(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.reassociate     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function reconnect(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function reconnect(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.reconnect     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getDeviceConfigs     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function updateNetwork(config: WifiDeviceConfig): number;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function updateNetwork(config: WifiDeviceConfig): number;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.updateNetwork     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function disableNetwork(netId: number): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function disableNetwork(netId: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.disableNetwork     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function removeAllNetwork(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function removeAllNetwork(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.removeAllNetwork     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function removeDevice(id: number): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function removeDevice(id: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.removeDevice     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function enableHotspot(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function enableHotspot(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.enableHotspot     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function disableHotspot(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function disableHotspot(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.disableHotspot     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function isHotspotDualBandSupported(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function isHotspotDualBandSupported(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.isHotspotDualBandSupported     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function isHotspotActive(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function isHotspotActive(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.isHotspotActive     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function setHotspotConfig(config: HotspotConfig): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function setHotspotConfig(config: HotspotConfig): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.setHotspotConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getHotspotConfig(): HotspotConfig;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getHotspotConfig(): HotspotConfig;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getHotspotConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getStations(): Array\<StationInfo>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getStations(): Array\<StationInfo>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getStations     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getP2pLinkedInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getP2pLinkedInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getCurrentGroup     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getCurrentGroup     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getP2pPeerDevices     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.getP2pPeerDevices     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function createGroup(config: WifiP2PConfig): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function createGroup(config: WifiP2PConfig): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.createGroup     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function removeGroup(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function removeGroup(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.removeGroup     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function p2pConnect(config: WifiP2PConfig): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function p2pConnect(config: WifiP2PConfig): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.p2pConnect     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function p2pCancelConnect(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function p2pCancelConnect(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.p2pCancelConnect     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function startDiscoverDevices(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function startDiscoverDevices(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.startDiscoverDevices     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function stopDiscoverDevices(): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function stopDiscoverDevices(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.stopDiscoverDevices     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function deletePersistentGroup(netId: number): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function deletePersistentGroup(netId: number): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.deletePersistentGroup     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function setDeviceName(devName: string): boolean;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function setDeviceName(devName: string): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.setDeviceName     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "wifiStateChange", callback: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "wifiStateChange", callback: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "wifiStateChange", callback?: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "wifiStateChange", callback?: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "wifiConnectionChange", callback: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "wifiConnectionChange", callback: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "wifiConnectionChange", callback?: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "wifiConnectionChange", callback?: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "wifiScanStateChange", callback: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "wifiScanStateChange", callback: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "wifiScanStateChange", callback?: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "wifiScanStateChange", callback?: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "wifiRssiChange", callback: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "wifiRssiChange", callback: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "wifiRssiChange", callback?: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "wifiRssiChange", callback?: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "streamChange", callback: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "streamChange", callback: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "streamChange", callback?: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "streamChange", callback?: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "hotspotStateChange", callback: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "hotspotStateChange", callback: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "hotspotStateChange", callback?: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "hotspotStateChange", callback?: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "p2pStateChange", callback: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "p2pStateChange", callback: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "p2pStateChange", callback?: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "p2pStateChange", callback?: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function on(type: "p2pDiscoveryChange", callback: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function on(type: "p2pDiscoveryChange", callback: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.on|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifi<br>Method or attribute name: function off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void;<br>Deprecated version: N/A|Class name: wifi<br>Method or attribute name: function off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.off|@ohos.wifi.d.ts|
|Deprecated version changed|Class name: WifiDeviceConfig<br>Deprecated version: N/A|Class name: WifiDeviceConfig<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.WifiDeviceConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: IpConfig<br>Deprecated version: N/A|Class name: IpConfig<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.IpConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: WifiScanInfo<br>Deprecated version: N/A|Class name: WifiScanInfo<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.WifiScanInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: WifiSecurityType<br>Deprecated version: N/A|Class name: WifiSecurityType<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.WifiSecurityType     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: WifiLinkedInfo<br>Deprecated version: N/A|Class name: WifiLinkedInfo<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.WifiLinkedInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: IpInfo<br>Deprecated version: N/A|Class name: IpInfo<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.IpInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: HotspotConfig<br>Deprecated version: N/A|Class name: HotspotConfig<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.HotspotConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: StationInfo<br>Deprecated version: N/A|Class name: StationInfo<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.StationInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: IpType<br>Deprecated version: N/A|Class name: IpType<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.IpType     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: SuppState<br>Deprecated version: N/A|Class name: SuppState<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.SuppState     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: ConnState<br>Deprecated version: N/A|Class name: ConnState<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.ConnState     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: WifiP2pDevice<br>Deprecated version: N/A|Class name: WifiP2pDevice<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.WifiP2pDevice     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: WifiP2PConfig<br>Deprecated version: N/A|Class name: WifiP2PConfig<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.WifiP2PConfig     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: WifiP2pGroupInfo<br>Deprecated version: N/A|Class name: WifiP2pGroupInfo<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.WifiP2pGroupInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: P2pConnectState<br>Deprecated version: N/A|Class name: P2pConnectState<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.P2pConnectState     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: WifiP2pLinkedInfo<br>Deprecated version: N/A|Class name: WifiP2pLinkedInfo<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.WifiP2pLinkedInfo     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: P2pDeviceStatus<br>Deprecated version: N/A|Class name: P2pDeviceStatus<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.P2pDeviceStatus     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: GroupOwnerBand<br>Deprecated version: N/A|Class name: GroupOwnerBand<br>Deprecated version: 9<br>Substitute API: ohos.wifiManager/wifiManager.GroupOwnerBand     |@ohos.wifi.d.ts|
|Deprecated version changed|Class name: wifiext<br>Method or attribute name: function enableHotspot(): boolean;<br>Deprecated version: N/A|Class name: wifiext<br>Method or attribute name: function enableHotspot(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManagerExt/wifiManagerExt.enableHotspot     |@ohos.wifiext.d.ts|
|Deprecated version changed|Class name: wifiext<br>Method or attribute name: function disableHotspot(): boolean;<br>Deprecated version: N/A|Class name: wifiext<br>Method or attribute name: function disableHotspot(): boolean;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManagerExt/wifiManagerExt.disableHotspot      |@ohos.wifiext.d.ts|
|Deprecated version changed|Class name: wifiext<br>Method or attribute name: function getSupportedPowerModel(): Promise\<Array\<PowerModel>>;<br>Deprecated version: N/A|Class name: wifiext<br>Method or attribute name: function getSupportedPowerModel(): Promise\<Array\<PowerModel>>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManagerExt/wifiManagerExt.getSupportedPowerMode     |@ohos.wifiext.d.ts|
|Deprecated version changed|Class name: wifiext<br>Method or attribute name: function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>Deprecated version: N/A|Class name: wifiext<br>Method or attribute name: function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManagerExt/wifiManagerExt.getSupportedPowerMode     |@ohos.wifiext.d.ts|
|Deprecated version changed|Class name: wifiext<br>Method or attribute name: function getPowerModel (): Promise\<PowerModel>;<br>Deprecated version: N/A|Class name: wifiext<br>Method or attribute name: function getPowerModel (): Promise\<PowerModel>;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManagerExt/wifiManagerExt.getPowerMode     |@ohos.wifiext.d.ts|
|Deprecated version changed|Class name: wifiext<br>Method or attribute name: function getPowerModel (callback: AsyncCallback\<PowerModel>): void;<br>Deprecated version: N/A|Class name: wifiext<br>Method or attribute name: function getPowerModel (callback: AsyncCallback\<PowerModel>): void;<br>Deprecated version: 9<br>Substitute API: ohos.wifiManagerExt/wifiManagerExt.getPowerMode     |@ohos.wifiext.d.ts|
|Deprecated version changed|Class name: wifiext<br>Method or attribute name: function setPowerModel(model: PowerModel) : boolean<br>Deprecated version: N/A|Class name: wifiext<br>Method or attribute name: function setPowerModel(model: PowerModel) : boolean<br>Deprecated version: 9<br>Substitute API: ohos.wifiManagerExt/wifiManagerExt.setPowerMode     |@ohos.wifiext.d.ts|
|Deprecated version changed|Class name: PowerModel<br>Deprecated version: N/A|Class name: PowerModel<br>Deprecated version: 9<br>Substitute API: ohos.wifiManagerExt/wifiManagerExt.PowerMode     |@ohos.wifiext.d.ts|
|Deprecated version changed|Class name: TagSession<br>Method or attribute name: getTagInfo(): tag.TagInfo;<br>Deprecated version: N/A|Class name: TagSession<br>Method or attribute name: getTagInfo(): tag.TagInfo;<br>Deprecated version: 9<br>Substitute API: ohos.nfc.tag/tag|tagSession.d.ts|
|Deprecated version changed|Class name: TagSession<br>Method or attribute name: connectTag(): boolean;<br>Deprecated version: N/A|Class name: TagSession<br>Method or attribute name: connectTag(): boolean;<br>Deprecated version: 9<br>Substitute API: tagSession.TagSession|tagSession.d.ts|
|Deprecated version changed|Class name: TagSession<br>Method or attribute name: reset(): void;<br>Deprecated version: N/A|Class name: TagSession<br>Method or attribute name: reset(): void;<br>Deprecated version: 9<br>Substitute API: tagSession.TagSession|tagSession.d.ts|
|Deprecated version changed|Class name: TagSession<br>Method or attribute name: isTagConnected(): boolean;<br>Deprecated version: N/A|Class name: TagSession<br>Method or attribute name: isTagConnected(): boolean;<br>Deprecated version: 9<br>Substitute API: tagSession.TagSession|tagSession.d.ts|
|Deprecated version changed|Class name: TagSession<br>Method or attribute name: setSendDataTimeout(timeout: number): boolean;<br>Deprecated version: N/A|Class name: TagSession<br>Method or attribute name: setSendDataTimeout(timeout: number): boolean;<br>Deprecated version: 9<br>Substitute API: tagSession.TagSession|tagSession.d.ts|
|Deprecated version changed|Class name: TagSession<br>Method or attribute name: getSendDataTimeout(): number;<br>Deprecated version: N/A|Class name: TagSession<br>Method or attribute name: getSendDataTimeout(): number;<br>Deprecated version: 9<br>Substitute API: tagSession.TagSession|tagSession.d.ts|
|Deprecated version changed|Class name: TagSession<br>Method or attribute name: sendData(data: number[]): Promise\<number[]>;<br>Deprecated version: N/A|Class name: TagSession<br>Method or attribute name: sendData(data: number[]): Promise\<number[]>;<br>Deprecated version: 9<br>Substitute API: tagSession.TagSession|tagSession.d.ts|
|Deprecated version changed|Class name: TagSession<br>Method or attribute name: sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>Deprecated version: N/A|Class name: TagSession<br>Method or attribute name: sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>Deprecated version: 9<br>Substitute API: tagSession.TagSession|tagSession.d.ts|
|Deprecated version changed|Class name: TagSession<br>Method or attribute name: getMaxSendLength(): number;<br>Deprecated version: N/A|Class name: TagSession<br>Method or attribute name: getMaxSendLength(): number;<br>Deprecated version: 9<br>Substitute API: tagSession.TagSession|tagSession.d.ts|
|Initial version changed|Class name: A2dpSourceProfile<br>Method or attribute name: getPlayingState(device: string): PlayingState;<br>Initial version: N/A|Class name: A2dpSourceProfile<br>Method or attribute name: getPlayingState(device: string): PlayingState;<br>Initial version: 8|@ohos.bluetooth.d.ts|
|Initial version changed|Class name: ScanFilter<br>Initial version: 7|Class name: ScanFilter<br>Initial version: N/A|@ohos.bluetooth.d.ts|
|Initial version changed|Class name: ScanFilter<br>Method or attribute name: deviceId?: string;<br>Initial version: N/A|Class name: ScanFilter<br>Method or attribute name: deviceId?: string;<br>Initial version: 7|@ohos.bluetooth.d.ts|
|Initial version changed|Class name: ScanFilter<br>Method or attribute name: name?: string;<br>Initial version: N/A|Class name: ScanFilter<br>Method or attribute name: name?: string;<br>Initial version: 7|@ohos.bluetooth.d.ts|
|Initial version changed|Class name: ScanFilter<br>Method or attribute name: serviceUuid?: string;<br>Initial version: N/A|Class name: ScanFilter<br>Method or attribute name: serviceUuid?: string;<br>Initial version: 7|@ohos.bluetooth.d.ts|
|Initial version changed|Class name: ProfileId<br>Initial version: 8|Class name: ProfileId<br>Initial version: N/A|@ohos.bluetooth.d.ts|
|Initial version changed|Class name: ProfileId<br>Method or attribute name: PROFILE_A2DP_SOURCE = 1<br>Initial version: N/A|Class name: ProfileId<br>Method or attribute name: PROFILE_A2DP_SOURCE = 1<br>Initial version: 8|@ohos.bluetooth.d.ts|
|Initial version changed|Class name: ProfileId<br>Method or attribute name: PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4<br>Initial version: N/A|Class name: ProfileId<br>Method or attribute name: PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4<br>Initial version: 8|@ohos.bluetooth.d.ts|
|Initial version changed|Class name: FeatureType<br>Initial version: N/A|Class name: FeatureType<br>Initial version: 6|@ohos.nfc.cardEmulation.d.ts|
|Initial version changed|Class name: TagInfo<br>Method or attribute name: supportedProfiles: number[];<br>Initial version: N/A|Class name: TagInfo<br>Method or attribute name: supportedProfiles: number[];<br>Initial version: 7|@ohos.nfc.tag.d.ts|
|Permission changed|Class name: bluetooth<br>Method or attribute name: function startBluetoothDiscovery(): boolean;<br>Permission: ohos.permission.LOCATION|Class name: bluetooth<br>Method or attribute name: function startBluetoothDiscovery(): boolean;<br>Permission: ohos.permission.DISCOVER_BLUETOOTH and ohos.permission.LOCATION|@ohos.bluetooth.d.ts|
|Permission changed|Class name: A2dpSourceProfile<br>Method or attribute name: connect(device: string): boolean;<br>Permission: permission ohos.permission.DISCOVER_BLUETOOTH|Class name: A2dpSourceProfile<br>Method or attribute name: connect(device: string): boolean;<br>Permission: ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|Permission changed|Class name: A2dpSourceProfile<br>Method or attribute name: disconnect(device: string): boolean;<br>Permission: permission ohos.permission.DISCOVER_BLUETOOTH|Class name: A2dpSourceProfile<br>Method or attribute name: disconnect(device: string): boolean;<br>Permission: ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|Permission changed|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: connect(device: string): boolean;<br>Permission: permission ohos.permission.DISCOVER_BLUETOOTH|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: connect(device: string): boolean;<br>Permission: ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|Permission changed|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: disconnect(device: string): boolean;<br>Permission: permission ohos.permission.DISCOVER_BLUETOOTH|Class name: HandsFreeAudioGatewayProfile<br>Method or attribute name: disconnect(device: string): boolean;<br>Permission: ohos.permission.DISCOVER_BLUETOOTH|@ohos.bluetooth.d.ts|
|Permission changed|Class name: BLE<br>Method or attribute name: function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>Permission: ohos.permission.LOCATION|Class name: BLE<br>Method or attribute name: function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>Permission: ohos.permission.DISCOVER_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH and ohos.permission.LOCATION|@ohos.bluetooth.d.ts|
|Permission changed|Class name: connectedTag<br>Method or attribute name: function init(): boolean;<br>Permission: s ohos.permission.NFC_TAG|Class name: connectedTag<br>Method or attribute name: function init(): boolean;<br>Permission: ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|Permission changed|Class name: connectedTag<br>Method or attribute name: function uninit(): boolean;<br>Permission: s ohos.permission.NFC_TAG|Class name: connectedTag<br>Method or attribute name: function uninit(): boolean;<br>Permission: ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|Permission changed|Class name: connectedTag<br>Method or attribute name: function readNdefTag(): Promise\<string>;<br>Permission: s ohos.permission.NFC_TAG|Class name: connectedTag<br>Method or attribute name: function readNdefTag(): Promise\<string>;<br>Permission: ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|Permission changed|Class name: connectedTag<br>Method or attribute name: function readNdefTag(callback: AsyncCallback\<string>): void;<br>Permission: s ohos.permission.NFC_TAG|Class name: connectedTag<br>Method or attribute name: function readNdefTag(callback: AsyncCallback\<string>): void;<br>Permission: ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|Permission changed|Class name: connectedTag<br>Method or attribute name: function writeNdefTag(data: string): Promise\<void>;<br>Permission: s ohos.permission.NFC_TAG|Class name: connectedTag<br>Method or attribute name: function writeNdefTag(data: string): Promise\<void>;<br>Permission: ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|Permission changed|Class name: connectedTag<br>Method or attribute name: function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>Permission: s ohos.permission.NFC_TAG|Class name: connectedTag<br>Method or attribute name: function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>Permission: ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|Permission changed|Class name: connectedTag<br>Method or attribute name: function on(type: "notify", callback: Callback\<number>): void;<br>Permission: s ohos.permission.NFC_TAG|Class name: connectedTag<br>Method or attribute name: function on(type: "notify", callback: Callback\<number>): void;<br>Permission: ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|Permission changed|Class name: connectedTag<br>Method or attribute name: function off(type: "notify", callback?:Callback\<number>): void;<br>Permission: s ohos.permission.NFC_TAG|Class name: connectedTag<br>Method or attribute name: function off(type: "notify", callback?:Callback\<number>): void;<br>Permission: ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|Permission changed|Class name: connection<br>Method or attribute name: function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>Permission: ohos.permission.GET_NETWORK_INFO|Class name: connection<br>Method or attribute name: function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>Permission: ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|Permission changed|Class name: connection<br>Method or attribute name: function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>Permission: ohos.permission.GET_NETWORK_INFO|Class name: connection<br>Method or attribute name: function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>Permission: ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|Permission changed|Class name: NetHandle<br>Method or attribute name: getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>Permission: ohos.permission.GET_NETWORK_INFO|Class name: NetHandle<br>Method or attribute name: getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>Permission: ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|Permission changed|Class name: NetHandle<br>Method or attribute name: getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>Permission: ohos.permission.GET_NETWORK_INFO|Class name: NetHandle<br>Method or attribute name: getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>Permission: ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|Permission changed|Class name: NetHandle<br>Method or attribute name: getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>Permission: ohos.permission.GET_NETWORK_INFO|Class name: NetHandle<br>Method or attribute name: getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>Permission: ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|Permission changed|Class name: NetHandle<br>Method or attribute name: getAddressByName(host: string): Promise\<NetAddress>;<br>Permission: ohos.permission.GET_NETWORK_INFO|Class name: NetHandle<br>Method or attribute name: getAddressByName(host: string): Promise\<NetAddress>;<br>Permission: ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|Permission deleted|Class name: tag<br>Method or attribute name: function getNfcATag(tagInfo: TagInfo): NfcATag<br>Permission: ohos.permission.NFC_TAG|Class name: tag<br>Method or attribute name: function getNfcATag(tagInfo: TagInfo): NfcATag<br>Permission: N/A|@ohos.nfc.tag.d.ts|
|Permission deleted|Class name: tag<br>Method or attribute name: function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>Permission: ohos.permission.NFC_TAG|Class name: tag<br>Method or attribute name: function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>Permission: N/A|@ohos.nfc.tag.d.ts|
|Permission deleted|Class name: tag<br>Method or attribute name: function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>Permission: ohos.permission.NFC_TAG|Class name: tag<br>Method or attribute name: function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>Permission: N/A|@ohos.nfc.tag.d.ts|
|Permission deleted|Class name: tag<br>Method or attribute name: function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>Permission: ohos.permission.NFC_TAG|Class name: tag<br>Method or attribute name: function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>Permission: N/A|@ohos.nfc.tag.d.ts|
|Permission deleted|Class name: NfcATag<br>Method or attribute name: getSak(): number;<br>Permission: ohos.permission.NFC_TAG|Class name: NfcATag<br>Method or attribute name: getSak(): number;<br>Permission: N/A|nfctech.d.ts|
|Permission deleted|Class name: NfcATag<br>Method or attribute name: getAtqa(): number[];<br>Permission: ohos.permission.NFC_TAG|Class name: NfcATag<br>Method or attribute name: getAtqa(): number[];<br>Permission: N/A|nfctech.d.ts|
|Permission deleted|Class name: NfcBTag<br>Method or attribute name: getRespAppData(): number[];<br>Permission: ohos.permission.NFC_TAG|Class name: NfcBTag<br>Method or attribute name: getRespAppData(): number[];<br>Permission: N/A|nfctech.d.ts|
|Permission deleted|Class name: NfcBTag<br>Method or attribute name: getRespProtocol(): number[];<br>Permission: ohos.permission.NFC_TAG|Class name: NfcBTag<br>Method or attribute name: getRespProtocol(): number[];<br>Permission: N/A|nfctech.d.ts|
|Permission deleted|Class name: NfcFTag<br>Method or attribute name: getSystemCode(): number[];<br>Permission: ohos.permission.NFC_TAG|Class name: NfcFTag<br>Method or attribute name: getSystemCode(): number[];<br>Permission: N/A|nfctech.d.ts|
|Permission deleted|Class name: NfcFTag<br>Method or attribute name: getPmm(): number[];<br>Permission: ohos.permission.NFC_TAG|Class name: NfcFTag<br>Method or attribute name: getPmm(): number[];<br>Permission: N/A|nfctech.d.ts|
|Permission deleted|Class name: NfcVTag<br>Method or attribute name: getResponseFlags(): number;<br>Permission: ohos.permission.NFC_TAG|Class name: NfcVTag<br>Method or attribute name: getResponseFlags(): number;<br>Permission: N/A|nfctech.d.ts|
|Permission deleted|Class name: NfcVTag<br>Method or attribute name: getDsfId(): number;<br>Permission: ohos.permission.NFC_TAG|Class name: NfcVTag<br>Method or attribute name: getDsfId(): number;<br>Permission: N/A|nfctech.d.ts|
|Permission deleted|Class name: TagSession<br>Method or attribute name: isTagConnected(): boolean;<br>Permission: ohos.permission.NFC_TAG|Class name: TagSession<br>Method or attribute name: isTagConnected(): boolean;<br>Permission: N/A|tagSession.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getDefaultNet(): Promise\<NetHandle>;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getAllNets(): Promise\<Array\<NetHandle>>;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function hasDefaultNet(): Promise\<boolean>;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function enableAirplaneMode(): Promise\<void>;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function disableAirplaneMode(): Promise\<void>;<br>Error code: 201, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function reportNetConnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: connection<br>Method or attribute name: function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: NetConnection<br>Method or attribute name: register(callback: AsyncCallback\<void>): void;<br>Error code: 201, 2100002, 2100003, 2101008, 2101022|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: NetConnection<br>Method or attribute name: unregister(callback: AsyncCallback\<void>): void;<br>Error code: 2100002, 2100003, 2101007|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: NetHandle<br>Method or attribute name: getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: NetHandle<br>Method or attribute name: getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: NetHandle<br>Method or attribute name: getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: NetHandle<br>Method or attribute name: getAddressByName(host: string): Promise\<NetAddress>;<br>Error code: 201, 401, 2100001, 2100002, 2100003|@ohos.net.connection.d.ts|
|Error code added|NA|Class name: HttpRequest<br>Method or attribute name: request(url: string, callback: AsyncCallback\<HttpResponse>): void;<br>Error code: 401, 201, 2300001, 2300003, 2300005, 2300006, 2300007, 2300008, 2300009, 2300016, 2300018, 2300023, 2300025, 2300026, 2300027, 2300028, 2300047, 2300052, 2300055, 2300056, 2300058, 2300059, 2300060, 2300061, 2300063, 2300070, 2300073, 2300077, 2300078, 2300094, 2300999|@ohos.net.http.d.ts|
|Error code added|NA|Class name: HttpRequest<br>Method or attribute name: request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>Error code: 401, 201, 2300001, 2300003, 2300005, 2300006, 2300007, 2300008, 2300009, 2300016, 2300018, 2300023, 2300025, 2300026, 2300027, 2300028, 2300047, 2300052, 2300055, 2300056, 2300058, 2300059, 2300060, 2300061, 2300063, 2300070, 2300073, 2300077, 2300078, 2300094, 2300999|@ohos.net.http.d.ts|
|Error code added|NA|Class name: HttpRequest<br>Method or attribute name: request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>Error code: 401, 201, 2300001, 2300003, 2300005, 2300006, 2300007, 2300008, 2300009, 2300016, 2300018, 2300023, 2300025, 2300026, 2300027, 2300028, 2300047, 2300052, 2300055, 2300056, 2300058, 2300059, 2300060, 2300061, 2300063, 2300070, 2300073, 2300077, 2300078, 2300094, 2300999|@ohos.net.http.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: bind(address: NetAddress): Promise\<void>;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: send(options: UDPSendOptions, callback: AsyncCallback\<void>): void;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: send(options: UDPSendOptions): Promise\<void>;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: close(callback: AsyncCallback\<void>): void;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: close(): Promise\<void>;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: getState(callback: AsyncCallback\<SocketStateBase>): void;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: getState(): Promise\<SocketStateBase>;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void>): void;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: UDPSocket<br>Method or attribute name: setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: bind(address: NetAddress): Promise\<void>;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: connect(options: TCPConnectOptions, callback: AsyncCallback\<void>): void;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: connect(options: TCPConnectOptions): Promise\<void>;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: send(options: TCPSendOptions): Promise\<void>;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: close(callback: AsyncCallback\<void>): void;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: close(): Promise\<void>;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: getRemoteAddress(): Promise\<NetAddress>;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: getState(callback: AsyncCallback\<SocketStateBase>): void;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: getState(): Promise\<SocketStateBase>;<br>Error code: 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: TCPSocket<br>Method or attribute name: setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>Error code: 401, 201|@ohos.net.socket.d.ts|
|Error code added|NA|Class name: WebSocket<br>Method or attribute name: connect(url: string, callback: AsyncCallback\<boolean>): void;<br>Error code: 401, 201|@ohos.net.webSocket.d.ts|
|Error code added|NA|Class name: WebSocket<br>Method or attribute name: connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>Error code: 401, 201|@ohos.net.webSocket.d.ts|
|Error code added|NA|Class name: WebSocket<br>Method or attribute name: connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>Error code: 401, 201|@ohos.net.webSocket.d.ts|
|Error code added|NA|Class name: WebSocket<br>Method or attribute name: send(data: string \| ArrayBuffer, callback: AsyncCallback\<boolean>): void;<br>Error code: 401, 201|@ohos.net.webSocket.d.ts|
|Error code added|NA|Class name: WebSocket<br>Method or attribute name: send(data: string \| ArrayBuffer): Promise\<boolean>;<br>Error code: 401, 201|@ohos.net.webSocket.d.ts|
|Error code added|NA|Class name: WebSocket<br>Method or attribute name: close(callback: AsyncCallback\<boolean>): void;<br>Error code: 401, 201|@ohos.net.webSocket.d.ts|
|Error code added|NA|Class name: WebSocket<br>Method or attribute name: close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>Error code: 401, 201|@ohos.net.webSocket.d.ts|
|Error code added|NA|Class name: WebSocket<br>Method or attribute name: close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>Error code: 401, 201|@ohos.net.webSocket.d.ts|
|Permission added|Class name: connection<br>Method or attribute name: function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>Permission: N/A|Class name: connection<br>Method or attribute name: function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>Permission: ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|Permission added|Class name: connection<br>Method or attribute name: function hasDefaultNet(): Promise\<boolean>;<br>Permission: N/A|Class name: connection<br>Method or attribute name: function hasDefaultNet(): Promise\<boolean>;<br>Permission: ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|Permission added|Class name: connection<br>Method or attribute name: function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>Permission: N/A|Class name: connection<br>Method or attribute name: function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>Permission: ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|Permission added|Class name: connection<br>Method or attribute name: function enableAirplaneMode(): Promise\<void>;<br>Permission: N/A|Class name: connection<br>Method or attribute name: function enableAirplaneMode(): Promise\<void>;<br>Permission: ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|Permission added|Class name: connection<br>Method or attribute name: function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>Permission: N/A|Class name: connection<br>Method or attribute name: function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>Permission: ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|Permission added|Class name: connection<br>Method or attribute name: function disableAirplaneMode(): Promise\<void>;<br>Permission: N/A|Class name: connection<br>Method or attribute name: function disableAirplaneMode(): Promise\<void>;<br>Permission: ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|SysCap changed|Class name: cardEmulation<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: cardEmulation<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: FeatureType<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: FeatureType<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: FeatureType<br>Method or attribute name: HCE = 0<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: FeatureType<br>Method or attribute name: HCE = 0<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: FeatureType<br>Method or attribute name: UICC = 1<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: FeatureType<br>Method or attribute name: UICC = 1<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: FeatureType<br>Method or attribute name: ESE = 2<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: FeatureType<br>Method or attribute name: ESE = 2<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: cardEmulation<br>Method or attribute name: function isSupported(feature: number): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: cardEmulation<br>Method or attribute name: function isSupported(feature: number): boolean;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: HceService<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: HceService<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: HceService<br>Method or attribute name: startHCE(aidList: string[]): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: HceService<br>Method or attribute name: startHCE(aidList: string[]): boolean;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: HceService<br>Method or attribute name: stopHCE(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: HceService<br>Method or attribute name: stopHCE(): boolean;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: HceService<br>Method or attribute name: on(type: "hceCmd", callback: AsyncCallback\<number[]>): void;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: HceService<br>Method or attribute name: on(type: "hceCmd", callback: AsyncCallback\<number[]>): void;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: HceService<br>Method or attribute name: sendResponse(responseApdu: number[]): void;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: HceService<br>Method or attribute name: sendResponse(responseApdu: number[]): void;<br>SysCap:SystemCapability.Communication.NFC.CardEmulation|@ohos.nfc.cardEmulation.d.ts|
|SysCap changed|Class name: tag<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: const NFC_A = 1;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: const NFC_A = 1;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: const NFC_B = 2;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: const NFC_B = 2;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: const ISO_DEP = 3;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: const ISO_DEP = 3;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: const NFC_F = 4;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: const NFC_F = 4;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: const NFC_V = 5;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: const NFC_V = 5;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: const NDEF = 6;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: const NDEF = 6;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: const MIFARE_CLASSIC = 8;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: const MIFARE_CLASSIC = 8;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: const MIFARE_ULTRALIGHT = 9;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: const MIFARE_ULTRALIGHT = 9;<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: function getNfcATag(tagInfo: TagInfo): NfcATag<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: function getNfcATag(tagInfo: TagInfo): NfcATag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: tag<br>Method or attribute name: function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: tag<br>Method or attribute name: function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: TagInfo<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagInfo<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: TagInfo<br>Method or attribute name: supportedProfiles: number[];<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagInfo<br>Method or attribute name: supportedProfiles: number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|@ohos.nfc.tag.d.ts|
|SysCap changed|Class name: NfcATag<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcATag<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcATag<br>Method or attribute name: getSak(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcATag<br>Method or attribute name: getSak(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcATag<br>Method or attribute name: getAtqa(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcATag<br>Method or attribute name: getAtqa(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcBTag<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcBTag<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcBTag<br>Method or attribute name: getRespAppData(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcBTag<br>Method or attribute name: getRespAppData(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcBTag<br>Method or attribute name: getRespProtocol(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcBTag<br>Method or attribute name: getRespProtocol(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcFTag<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcFTag<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcFTag<br>Method or attribute name: getSystemCode(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcFTag<br>Method or attribute name: getSystemCode(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcFTag<br>Method or attribute name: getPmm(): number[];<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcFTag<br>Method or attribute name: getPmm(): number[];<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcVTag<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcVTag<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcVTag<br>Method or attribute name: getResponseFlags(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcVTag<br>Method or attribute name: getResponseFlags(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: NfcVTag<br>Method or attribute name: getDsfId(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: NfcVTag<br>Method or attribute name: getDsfId(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|nfctech.d.ts|
|SysCap changed|Class name: TagSession<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap changed|Class name: TagSession<br>Method or attribute name: getTagInfo(): tag.TagInfo;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>Method or attribute name: getTagInfo(): tag.TagInfo;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap changed|Class name: TagSession<br>Method or attribute name: connectTag(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>Method or attribute name: connectTag(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap changed|Class name: TagSession<br>Method or attribute name: reset(): void;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>Method or attribute name: reset(): void;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap changed|Class name: TagSession<br>Method or attribute name: isTagConnected(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>Method or attribute name: isTagConnected(): boolean;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap changed|Class name: TagSession<br>Method or attribute name: setSendDataTimeout(timeout: number): boolean;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>Method or attribute name: setSendDataTimeout(timeout: number): boolean;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap changed|Class name: TagSession<br>Method or attribute name: getSendDataTimeout(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>Method or attribute name: getSendDataTimeout(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap changed|Class name: TagSession<br>Method or attribute name: sendData(data: number[]): Promise\<number[]>;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>Method or attribute name: sendData(data: number[]): Promise\<number[]>;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap changed|Class name: TagSession<br>Method or attribute name: sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>Method or attribute name: sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
|SysCap changed|Class name: TagSession<br>Method or attribute name: getMaxSendLength(): number;<br>SysCap:SystemCapability.Communication.NFC.Core|Class name: TagSession<br>Method or attribute name: getMaxSendLength(): number;<br>SysCap:SystemCapability.Communication.NFC.Tag|tagSession.d.ts|
