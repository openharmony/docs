| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
| 新增 | NA   | 类名：ErrorCode; <br>方法or属性：CHECK_PARAM_ERROR = 401     | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：OS_MMAP_ERROR = 1900001    | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：OS_IOCTL_ERROR = 1900002   | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：WRITE_TO_ASHMEM_ERROR = 1900003 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：READ_FROM_ASHMEM_ERROR = 1900004 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：ONLY_PROXY_OBJECT_PERMITTED_ERROR = 1900005 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：ONLY_REMOTE_OBJECT_PERMITTED_ERROR = 1900006 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：COMMUNICATION_ERROR = 1900007 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：PROXY_OR_REMOTE_OBJECT_INVALID_ERROR = 1900008 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode;<br/> 方法or属性：WRITE_DATA_TO_MESSAGE_SEQUENCE_ERROR = 1900009 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：READ_DATA_FROM_MESSAGE_SEQUENCE_ERROR = 1900010 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：PARCEL_MEMORY_ALLOC_ERROR = 1900011 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode; <br/>方法or属性：CALL_JS_METHOD_ERROR = 1900012 | @ohos.rpc.d.ts |
| 新增 | NA   | 类名：ErrorCode;<br/> 方法or属性：OS_DUP_ERROR = 1900013     | @ohos.rpc.d.ts |
|新增|NA|类名：MessageSequence;<br>方法or属性：reclaim(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readRemoteObject(): IRemoteObject;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readInterfaceToken(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：getSize(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：getCapacity(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：getWritableBytes(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：getReadableBytes(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：getReadPosition(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：getWritePosition(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeNoException(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readException(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readByte(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readShort(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readInt(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readLong(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readFloat(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readDouble(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readBoolean(): boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readChar(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readString(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readByteArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readByteArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readShortArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readShortArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readIntArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readIntArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readLongArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readLongArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readFloatArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readFloatArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readDoubleArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readDoubleArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readBooleanArray(dataIn: boolean[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readBooleanArray(): boolean[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readCharArray(dataIn: number[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readCharArray(): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readStringArray(dataIn: string[]) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readStringArray(): string[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readRemoteObjectArray(objects: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readRemoteObjectArray(): IRemoteObject[];|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：static closeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：static dupFileDescriptor(fd: number) :number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：containFileDescriptors(): boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readFileDescriptor(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readAshmem(): Ashmem;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：getRawDataCapacity(): number;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readRawData(size: number): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：RequestResult;<br>方法or属性：errCode: number;|@ohos.rpc.d.ts|
|新增|NA|类名：RequestResult;<br>方法or属性：code: number;|@ohos.rpc.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getState(): BluetoothState;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getBtConnectionState(): ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function pairDevice(deviceId: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function cancelPairedDevice(deviceId: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceName(deviceId: string): string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function enableBluetooth(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function disableBluetooth(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getLocalName(): string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getPairedDevices(): Array\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getProfileConnectionState(profileId: ProfileId): ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function setDevicePairingConfirmation(device: string, accept: boolean): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function setLocalName(name: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function setBluetoothScanMode(mode: ScanMode, duration: number): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getBluetoothScanMode(): ScanMode;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function startBluetoothDiscovery(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function stopBluetoothDiscovery(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function on(type: "bondStateChange", callback: Callback\<BondStateParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function on(type: "stateChange", callback: Callback\<BluetoothState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function off(type: "stateChange", callback?: Callback\<BluetoothState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function sppCloseServerSocket(socket: number): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function sppCloseClientSocket(socket: number): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function sppWrite(clientSocket: number, data: ArrayBuffer): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：bluetoothManager;<br>方法or属性：function getProfileInstance(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile \| HidHostProfile \| PanProfile;|@ohos.bluetoothManager.d.ts|
| 新增 | NA   | 类名：MajorMinorClass; 方法or属性：COMPUTER_UNCATEGORIZED = 0x0100 | @ohos.bluetoothManager.d.ts     |
| 新增 | NA   | 类名：MajorMinorClass; <br>方法or属性：PHONE_UNCATEGORIZED = 0x0200 | @ohos.bluetoothManager.d.ts     |
| 新增 | NA   | 类名：MajorMinorClass;<br/>方法or属性：NETWORK_FULLY_AVAILABLE = 0x0300 | @ohos.bluetoothManager.d.ts     |
| 新增 | NA   | 类名：MajorMinorClass; <br/>方法or属性：AUDIO_VIDEO_UNCATEGORIZED = 0x0400 | @ohos.bluetoothManager.d.ts     |
| 新增 | NA   | 类名：MajorMinorClass; <br/>方法or属性：PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500 | @ohos.bluetoothManager.d.ts     |
| 新增 | NA   | 类名：MajorMinorClass; <br/>方法or属性：IMAGING_UNCATEGORIZED = 0x0600 | @ohos.bluetoothManager.d.ts     |
| 新增 | NA   | 类名：MajorMinorClass; <br/>方法or属性：WEARABLE_UNCATEGORIZED = 0x0700 | @ohos.bluetoothManager.d.ts     |
| 新增 | NA   | 类名：MajorMinorClass; <br/>方法or属性：TOY_UNCATEGORIZED = 0x0800 | @ohos.bluetoothManager.d.ts     |
| 新增 | NA   | 类名：MajorMinorClass; <br/>方法or属性：HEALTH_UNCATEGORIZED = 0x0900 | @ohos.bluetoothManager.d.ts     |
|新增|NA|类名：BaseProfile;<br>方法or属性：getConnectionDevices(): Array\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：getDeviceState(device: string): ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：A2dpSourceProfile;<br>方法or属性：connect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：connect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：HidHostProfile;<br>方法or属性：connect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：A2dpSourceProfile;<br>方法or属性：disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：HidHostProfile;<br>方法or属性：disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：PanProfile;<br>方法or属性：disconnect(device: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：A2dpSourceProfile;<br>方法or属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：HidHostProfile;<br>方法or属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：PanProfile;<br>方法or属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：A2dpSourceProfile;<br>方法or属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：HidHostProfile;<br>方法or属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：PanProfile;<br>方法or属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：A2dpSourceProfile;<br>方法or属性：getPlayingState(device: string): PlayingState;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：PanProfile;<br>方法or属性：setTethering(enable: boolean): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：PanProfile;<br>方法or属性：isTetheringOn(): boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLE;<br>方法or属性：function createGattServer(): GattServer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLE;<br>方法or属性：function createGattClientDevice(deviceId: string): GattClientDevice;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLE;<br>方法or属性：function getConnectedBLEDevices(): Array\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLE;<br>方法or属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLE;<br>方法or属性：function stopBLEScan(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLE;<br>方法or属性：function on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLE;<br>方法or属性：function off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：stopAdvertising(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：addService(service: GattService): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：removeService(serviceUuid: string): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：close(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：close(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：sendResponse(serverResponse: ServerResponse): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: "characteristicRead", callback: Callback\<CharacteristicReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: "descriptorRead", callback: Callback\<DescriptorReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: "descriptorWrite", callback: Callback\<DescriptorWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: "characteristicRead", callback?: Callback\<CharacteristicReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: "descriptorRead", callback?: Callback\<DescriptorReadRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteRequest>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：connect(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：disconnect(): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getDeviceName(callback: AsyncCallback\<string>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：writeCharacteristicValue(characteristic: BLECharacteristic): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：writeDescriptorValue(descriptor: BLEDescriptor): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getRssiValue(callback: AsyncCallback\<number>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：setBLEMtuSize(mtu: number): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattService;<br>方法or属性：serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLECharacteristic;<br>方法or属性：serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLEDescriptor;<br>方法or属性：serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：NotifyCharacteristic;<br>方法or属性：serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ServiceData;<br>方法or属性：serviceUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattService;<br>方法or属性：isPrimary: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattService;<br>方法or属性：characteristics: Array\<BLECharacteristic>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：GattService;<br>方法or属性：includeServices?: Array\<GattService>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLECharacteristic;<br>方法or属性：characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLEDescriptor;<br>方法or属性：characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：NotifyCharacteristic;<br>方法or属性：characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：characteristicUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLECharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：NotifyCharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLECharacteristic;<br>方法or属性：descriptors: Array\<BLEDescriptor>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLEDescriptor;<br>方法or属性：descriptorUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：descriptorUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：descriptorUuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLEDescriptor;<br>方法or属性：descriptorValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：NotifyCharacteristic;<br>方法or属性：confirm: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLEConnectChangedState;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanResult;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：PinRequiredParam;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BondStateParam;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：StateChangeParam;<br>方法or属性：deviceId: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：transId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：offset: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：isPrep: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：isPrep: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：needRsp: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：needRsp: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：value: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：value: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：value: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：status: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BLEConnectChangedState;<br>方法or属性：state: ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：StateChangeParam;<br>方法or属性：state: ProfileConnectionState;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanResult;<br>方法or属性：rssi: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanResult;<br>方法or属性：data: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：AdvertiseSetting;<br>方法or属性：interval?: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanOptions;<br>方法or属性：interval?: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：AdvertiseSetting;<br>方法or属性：txPower?: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：AdvertiseSetting;<br>方法or属性：connectable?: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：AdvertiseData;<br>方法or属性：serviceUuids: Array\<string>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：AdvertiseData;<br>方法or属性：manufactureData: Array\<ManufactureData>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：AdvertiseData;<br>方法or属性：serviceData: Array\<ServiceData>;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ManufactureData;<br>方法or属性：manufactureId: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ManufactureData;<br>方法or属性：manufactureValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ServiceData;<br>方法or属性：serviceValue: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：deviceId?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：name?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceUuid?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceUuidMask?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceSolicitationUuid?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceSolicitationUuidMask?: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceData?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceDataMask?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：manufactureId?: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：manufactureData?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：manufactureDataMask?: ArrayBuffer;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanOptions;<br>方法or属性：dutyMode?: ScanDuty;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanOptions;<br>方法or属性：matchMode?: MatchMode;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：SppOption;<br>方法or属性：uuid: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：SppOption;<br>方法or属性：secure: boolean;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：SppOption;<br>方法or属性：type: SppType;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：PinRequiredParam;<br>方法or属性：pinCode: string;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DeviceClass;<br>方法or属性：majorClass: MajorClass;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DeviceClass;<br>方法or属性：majorMinorClass: MajorMinorClass;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：DeviceClass;<br>方法or属性：classOfDevice: number;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BondStateParam;<br>方法or属性：state: BondState;|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_POWER = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanDuty;<br>方法or属性：SCAN_MODE_BALANCED = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_LATENCY = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MatchMode;<br>方法or属性：MATCH_MODE_AGGRESSIVE = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MatchMode;<br>方法or属性：MATCH_MODE_STICKY = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTED = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTING = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTED = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTING = 3|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_OFF = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_TURNING_ON = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_ON = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_TURNING_OFF = 3|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_ON = 4|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_BLE_ON = 5|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_OFF = 6|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：SppType;<br>方法or属性：SPP_RFCOMM|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_NONE = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_GENERAL_DISCOVERABLE = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_LIMITED_DISCOVERABLE = 3|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BondState;<br>方法or属性：BOND_STATE_INVALID = 0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BondState;<br>方法or属性：BOND_STATE_BONDING = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：BondState;<br>方法or属性：BOND_STATE_BONDED = 2|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_MISC = 0x0000|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_COMPUTER = 0x0100|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_PHONE = 0x0200|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_NETWORKING = 0x0300|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_AUDIO_VIDEO = 0x0400|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_PERIPHERAL = 0x0500|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_IMAGING = 0x0600|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_WEARABLE = 0x0700|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_TOY = 0x0800|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_HEALTH = 0x0900|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_UNCATEGORIZED = 0x1F00|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_DESKTOP = 0x0104|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_SERVER = 0x0108|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_LAPTOP = 0x010C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_HANDHELD_PC_PDA = 0x0110|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_PALM_SIZE_PC_PDA = 0x0114|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_WEARABLE = 0x0118|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_TABLET = 0x011C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_CELLULAR = 0x0204|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_CORDLESS = 0x0208|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_SMART = 0x020C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_MODEM_OR_GATEWAY = 0x0210|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_ISDN = 0x0214|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_1_TO_17_UTILIZED = 0x0320|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_17_TO_33_UTILIZED = 0x0340|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_33_TO_50_UTILIZED = 0x0360|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_60_TO_67_UTILIZED = 0x0380|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_67_TO_83_UTILIZED = 0x03A0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_83_TO_99_UTILIZED = 0x03C0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_NO_SERVICE = 0x03E0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HANDSFREE = 0x0408|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_MICROPHONE = 0x0410|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_LOUDSPEAKER = 0x0414|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HEADPHONES = 0x0418|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAR_AUDIO = 0x0420|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_SET_TOP_BOX = 0x0424|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HIFI_AUDIO = 0x0428|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VCR = 0x042C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CAMERA = 0x0430|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAMCORDER = 0x0434|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_MONITOR = 0x0438|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD = 0x0540|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_POINTING_DEVICE = 0x0580|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD_POINTING = 0x05C0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_UNCATEGORIZED = 0x0500|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_JOYSTICK = 0x0504|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GAMEPAD = 0x0508|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_REMOTE_CONTROL = 0x05C0|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SENSING_DEVICE = 0x0510|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITIZER_TABLET = 0x0514|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_CARD_READER = 0x0518|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITAL_PEN = 0x051C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SCANNER_RFID = 0x0520|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GESTURAL_INPUT = 0x0522|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：IMAGING_DISPLAY = 0x0610|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：IMAGING_CAMERA = 0x0620|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：IMAGING_SCANNER = 0x0640|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：IMAGING_PRINTER = 0x0680|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_WRIST_WATCH = 0x0704|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_PAGER = 0x0708|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_JACKET = 0x070C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_HELMET = 0x0710|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_GLASSES = 0x0714|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_ROBOT = 0x0804|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_VEHICLE = 0x0808|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_DOLL_ACTION_FIGURE = 0x080C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_CONTROLLER = 0x0810|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_GAME = 0x0814|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_BLOOD_PRESSURE = 0x0904|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_THERMOMETER = 0x0908|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_WEIGHING = 0x090C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_GLUCOSE = 0x0910|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_OXIMETER = 0x0914|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_RATE = 0x0918|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_DATA_DISPLAY = 0x091C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_STEP_COUNTER = 0x0920|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_PEAK_FLOW_MONITOR = 0x0928|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_MEDICATION_MONITOR = 0x092C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_KNEE_PROSTHESIS = 0x0930|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_ANKLE_PROSTHESIS = 0x0934|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_GENERIC_HEALTH_MANAGER = 0x0938|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：PlayingState;<br>方法or属性：STATE_NOT_PLAYING|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：PlayingState;<br>方法or属性：STATE_PLAYING|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileId;<br>方法or属性：PROFILE_A2DP_SOURCE = 1|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileId;<br>方法or属性：PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileId;<br>方法or属性：PROFILE_HID_HOST = 6|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：ProfileId;<br>方法or属性：PROFILE_PAN_NETWORK = 7|@ohos.bluetoothManager.d.ts|
|新增|NA|类名：connectedTag;<br>方法or属性：function initialize(): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag;<br>方法or属性：function uninitialize(): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag;<br>方法or属性：function read(): Promise\<number[]>;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag;<br>方法or属性：function read(callback: AsyncCallback\<number[]>): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag;<br>方法or属性：function write(data: number[]): Promise\<void>;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connectedTag;<br>方法or属性：function write(data: number[], callback: AsyncCallback\<void>): void;|@ohos.connectedTag.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getDefaultNetSync(): NetHandle;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function isDefaultNetMetered(callback: AsyncCallback\<boolean>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getAppNet(callback: AsyncCallback\<NetHandle>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getAppNet(): Promise\<NetHandle>;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function setAppNet(netHandle: NetHandle, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function setAppNet(netHandle: NetHandle): Promise\<void>;|@ohos.net.connection.d.ts|
|新增|NA|类名：NetHandle;<br>方法or属性：bindSocket(socketParam: TCPSocket \| UDPSocket, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：NetHandle;<br>方法or属性：bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;|@ohos.net.connection.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string, callback: AsyncCallback\<number>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：InterfaceConfiguration;<br>方法or属性：mode: IPSetMode;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：InterfaceConfiguration;<br>方法or属性：ipAddr: string;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：InterfaceConfiguration;<br>方法or属性：route: string;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：InterfaceConfiguration;<br>方法or属性：gateway: string;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：InterfaceConfiguration;<br>方法or属性：netMask: string;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：InterfaceConfiguration;<br>方法or属性：dnsServers: string;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：IPSetMode;<br>方法or属性：STATIC = 0|@ohos.net.ethernet.d.ts|
|新增|NA|类名：IPSetMode;<br>方法or属性：DHCP = 1|@ohos.net.ethernet.d.ts|
|新增|NA|类名：http;<br>方法or属性：function createHttpResponseCache(cacheSize?: number): HttpResponseCache;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions;<br>方法or属性：expectDataType?: HttpDataType;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions;<br>方法or属性：usingCache?: boolean;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions;<br>方法or属性：priority?: number;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions;<br>方法or属性：usingProtocol?: HttpProtocol;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpProtocol;<br>方法or属性：HTTP1_1|@ohos.net.http.d.ts|
|新增|NA|类名：HttpProtocol;<br>方法or属性：HTTP2|@ohos.net.http.d.ts|
|新增|NA|类名：HttpDataType;<br>方法or属性：STRING|@ohos.net.http.d.ts|
|新增|NA|类名：HttpDataType;<br>方法or属性：OBJECT = 1|@ohos.net.http.d.ts|
|新增|NA|类名：HttpDataType;<br>方法or属性：ARRAY_BUFFER = 2|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponse;<br>方法or属性：resultType: HttpDataType;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponseCache;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponseCache;<br>方法or属性：flush(): Promise\<void>;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponseCache;<br>方法or属性：delete(callback: AsyncCallback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpResponseCache;<br>方法or属性：delete(): Promise\<void>;|@ohos.net.http.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：type NetHandle = connection.NetHandle;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function isSharingSupported(callback: AsyncCallback\<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function isSharing(callback: AsyncCallback\<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getStatsRxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getStatsTxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getStatsTotalBytes(callback: AsyncCallback\<number>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function on(type: 'sharingStateChange', callback: Callback\<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：sharing;<br>方法or属性：function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;|@ohos.net.sharing.d.ts|
|新增|NA|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_SERVING = 1|@ohos.net.sharing.d.ts|
|新增|NA|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_CAN_SERVER = 2|@ohos.net.sharing.d.ts|
|新增|NA|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_ERROR = 3|@ohos.net.sharing.d.ts|
|新增|NA|类名：SharingIfaceType;<br>方法or属性：SHARING_WIFI = 0|@ohos.net.sharing.d.ts|
|新增|NA|类名：SharingIfaceType;<br>方法or属性：SHARING_USB = 1|@ohos.net.sharing.d.ts|
|新增|NA|类名：SharingIfaceType;<br>方法or属性：SHARING_BLUETOOTH = 2|@ohos.net.sharing.d.ts|
|新增|NA|类名：socket;<br>方法or属性：export type X509CertRawData = cert.EncodingBlob;|@ohos.net.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function constructTLSSocketInstance(): TLSSocket;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：on(type: 'message', callback: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：on(type: 'connect' \| 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：off(type: 'message', callback?: Callback\<{message: ArrayBuffer, remoteInfo: SocketRemoteInfo}>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：off(type: 'connect' \| 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getProtocol(callback: AsyncCallback\<string>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getProtocol(): Promise\<string>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getCipherSuite(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：send(data: string, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：send(data: string): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocket;<br>方法or属性：close(): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions;<br>方法or属性：ca: string \| Array\<string>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions;<br>方法or属性：cert?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions;<br>方法or属性：key?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions;<br>方法or属性：password?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions;<br>方法or属性：protocols?: Protocol \| Array\<Protocol>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions;<br>方法or属性：useRemoteCipherPrefer?: boolean;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions;<br>方法or属性：signatureAlgorithms?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSecureOptions;<br>方法or属性：cipherSuite?: string;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSConnectOptions;<br>方法or属性：address: NetAddress;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSConnectOptions;<br>方法or属性：secureOptions: TLSSecureOptions;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSConnectOptions;<br>方法or属性：ALPNProtocols?: Array\<string>;|@ohos.net.socket.d.ts|
|新增|NA|类名：Protocol;<br>方法or属性：TLSv12 = "TLSv1.2"|@ohos.net.socket.d.ts|
|新增|NA|类名：Protocol;<br>方法or属性：TLSv13 = "TLSv1.3"|@ohos.net.socket.d.ts|
|新增|NA|类名：cardEmulation;<br>方法or属性：function hasHceCapability(): boolean;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：cardEmulation;<br>方法or属性：function isDefaultService(elementName: ElementName, type: CardType): boolean;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：CardType;<br>方法or属性：PAYMENT = "payment"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：CardType;<br>方法or属性：OTHER = "other"|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService;<br>方法or属性：start(elementName: ElementName, aidList: string[]): void|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService;<br>方法or属性：stop(elementName: ElementName): void|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService;<br>方法or属性：transmit(response: number[]): Promise\<void>;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：HceService;<br>方法or属性：transmit(response: number[], callback: AsyncCallback\<void>): void;|@ohos.nfc.cardEmulation.d.ts|
|新增|NA|类名：nfcController;<br>方法or属性：function enableNfc(): void|@ohos.nfc.controller.d.ts|
|新增|NA|类名：nfcController;<br>方法or属性：function disableNfc(): void|@ohos.nfc.controller.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getNfcA(tagInfo: TagInfo): NfcATag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getNfcB(tagInfo: TagInfo): NfcBTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getNfcF(tagInfo: TagInfo): NfcFTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getNfcV(tagInfo: TagInfo): NfcVTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getIsoDep(tagInfo: TagInfo): IsoDepTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getNdef(tagInfo: TagInfo): NdefTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getMifareClassic(tagInfo: TagInfo): MifareClassicTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getMifareUltralight(tagInfo: TagInfo): MifareUltralightTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getNdefFormatable(tagInfo: TagInfo): NdefFormatableTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function getTagInfo(want: Want): TagInfo|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type NfcATag = _NfcATag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type NfcBTag = _NfcBTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type NfcFTag = _NfcFTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type NfcVTag = _NfcVTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type IsoDepTag = _IsoDepTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type NdefTag = _NdefTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type MifareClassicTag = _MifareClassicTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type MifareUltralightTag = _MifareUltralightTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type NdefFormatableTag = _NdefFormatableTag|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type NdefMessage = _NdefMessage|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：export type TagSession = _TagSession|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType;<br>方法or属性：TNF_EMPTY = 0x0|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType;<br>方法or属性：TNF_WELL_KNOWN = 0x1|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType;<br>方法or属性：TNF_MEDIA = 0x2|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType;<br>方法or属性：TNF_ABSOLUTE_URI = 0x3|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType;<br>方法or属性：TNF_EXT_APP = 0x4|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType;<br>方法or属性：TNF_UNKNOWN = 0x5|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TnfType;<br>方法or属性：TNF_UNCHANGED = 0x6|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType;<br>方法or属性：NFC_FORUM_TYPE_1 = 1|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType;<br>方法or属性：NFC_FORUM_TYPE_2 = 2|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType;<br>方法or属性：NFC_FORUM_TYPE_3 = 3|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType;<br>方法or属性：NFC_FORUM_TYPE_4 = 4|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NfcForumType;<br>方法or属性：MIFARE_CLASSIC = 101|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicType;<br>方法or属性：TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareUltralightType;<br>方法or属性：TYPE_UNKNOWN = 0|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicType;<br>方法or属性：TYPE_CLASSIC = 1|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicType;<br>方法or属性：TYPE_PLUS = 2|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicType;<br>方法or属性：TYPE_PRO = 3|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicSize;<br>方法or属性：MC_SIZE_MINI = 320|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicSize;<br>方法or属性：MC_SIZE_1K = 1024|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicSize;<br>方法or属性：MC_SIZE_2K = 2048|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareClassicSize;<br>方法or属性：MC_SIZE_4K = 4096|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareUltralightType;<br>方法or属性：TYPE_ULTRALIGHT = 1|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MifareUltralightType;<br>方法or属性：TYPE_ULTRALIGHT_C = 2|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo;<br>方法or属性：uid: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo;<br>方法or属性：technology: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo;<br>方法or属性：extrasData: PacMap[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo;<br>方法or属性：tagRfDiscId: number;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：TagInfo;<br>方法or属性：remoteTagService: rpc.RemoteObject;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NdefRecord;<br>方法or属性：tnf: number;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NdefRecord;<br>方法or属性：rtdType: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NdefRecord;<br>方法or属性：id: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：NdefRecord;<br>方法or属性：payload: number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef;<br>方法or属性：function makeUriRecord(uri: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef;<br>方法or属性：function makeTextRecord(text: string, locale: string): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef;<br>方法or属性：function makeMimeRecord(mimeType: string, mimeData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef;<br>方法or属性：function makeExternalRecord(domainName: string, type: string, externalData: number[]): NdefRecord;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef;<br>方法or属性：function createNdefMessage(data: number[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef;<br>方法or属性：function createNdefMessage(ndefRecords: NdefRecord[]): NdefMessage;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：ndef;<br>方法or属性：function messageToBytes(ndefMessage: NdefMessage): number[];|@ohos.nfc.tag.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：static create(): MessageSequence;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeRemoteObject(object: IRemoteObject): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeInterfaceToken(token: string): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：setSize(size: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：setCapacity(size: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：rewindRead(pos: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：rewindWrite(pos: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeByte(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeShort(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeInt(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeLong(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeFloat(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeDouble(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeBoolean(val: boolean): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeChar(val: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeString(val: string): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeParcelable(val: Parcelable): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeByteArray(byteArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeShortArray(shortArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeIntArray(intArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeLongArray(longArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeFloatArray(floatArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeDoubleArray(doubleArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeBooleanArray(booleanArray: boolean[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeCharArray(charArray: number[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeStringArray(stringArray: string[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeRemoteObjectArray(objectArray: IRemoteObject[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readParcelable(dataIn: Parcelable) : void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：readParcelableArray(parcelableArray: Parcelable[]): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeFileDescriptor(fd: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeAshmem(ashmem: Ashmem): void;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageSequence;<br>方法or属性：writeRawData(rawData: number[], size: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Parcelable;<br>方法or属性：marshalling(dataOut: MessageSequence): boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：Parcelable;<br>方法or属性：unmarshalling(dataIn: MessageSequence) : boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：RequestResult;<br>方法or属性：data: MessageSequence;|@ohos.rpc.d.ts|
|新增|NA|类名：RequestResult;<br>方法or属性：reply: MessageSequence;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject;<br>方法or属性：getLocalInterface(descriptor: string): IRemoteBroker;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject;<br>方法or属性：getLocalInterface(descriptor: string): IRemoteBroker;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject;<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise\<RequestResult>;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject;<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise\<RequestResult>;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy;<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise\<RequestResult>;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject;<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback\<RequestResult>): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject;<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback\<RequestResult>): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy;<br>方法or属性：sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback\<RequestResult>): void;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject;<br>方法or属性：registerDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy;<br>方法or属性：registerDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject;<br>方法or属性：unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy;<br>方法or属性：unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：IRemoteObject;<br>方法or属性：getDescriptor(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject;<br>方法or属性：getDescriptor(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy;<br>方法or属性：getDescriptor(): string;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption;<br>方法or属性：isAsync(): boolean;|@ohos.rpc.d.ts|
|新增|NA|类名：MessageOption;<br>方法or属性：setAsync(async: boolean): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject;<br>方法or属性：onRemoteMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): boolean \| Promise\<boolean>;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteObject;<br>方法or属性：modifyLocalInterface(localInterface: IRemoteBroker, descriptor: string): void;|@ohos.rpc.d.ts|
|新增|NA|类名：RemoteProxy;<br>方法or属性：getLocalInterface(interface: string): IRemoteBroker;|@ohos.rpc.d.ts|
|新增|NA|类名：IPCSkeleton;<br>方法or属性：static flushCmdBuffer(object: IRemoteObject): void;|@ohos.rpc.d.ts|
|新增|NA|类名：IPCSkeleton;<br>方法or属性：static restoreCallingIdentity(identity: string): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem;<br>方法or属性：static create(name: string, size: number): Ashmem;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem;<br>方法or属性：static create(ashmem: Ashmem): Ashmem;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem;<br>方法or属性：mapTypedAshmem(mapType: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem;<br>方法or属性：mapReadWriteAshmem(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem;<br>方法or属性：mapReadonlyAshmem(): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem;<br>方法or属性：setProtectionType(protectionType: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem;<br>方法or属性：writeAshmem(buf: number[], size: number, offset: number): void;|@ohos.rpc.d.ts|
|新增|NA|类名：Ashmem;<br>方法or属性：readAshmem(size: number, offset: number): number[];|@ohos.rpc.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function enableWifi(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function disableWifi(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function isWifiActive(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function scan(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getScanResults(): Promise\<Array\<WifiScanInfo>>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getScanResultsSync(): Array\<WifiScanInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig): Promise\<number>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig): Promise\<number>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number): Promise\<void>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getCandidateConfigs(): Array\<WifiDeviceConfig>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function connectToCandidateConfig(networkId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function connectToNetwork(networkId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function connectToDevice(config: WifiDeviceConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function disconnect(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getSignalLevel(rssi: number, band: number): number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getLinkedInfo(): Promise\<WifiLinkedInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function isConnected(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getSupportedFeatures(): number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function isFeatureSupported(featureId: number): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getDeviceMacAddress(): string[];|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getIpInfo(): IpInfo;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getCountryCode(): string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function reassociate(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function reconnect(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getDeviceConfigs(): Array\<WifiDeviceConfig>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function updateNetwork(config: WifiDeviceConfig): number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function disableNetwork(netId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function removeAllNetwork(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function removeDevice(id: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function enableHotspot(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function disableHotspot(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function isHotspotDualBandSupported(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function isHotspotActive(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function setHotspotConfig(config: HotspotConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getHotspotConfig(): HotspotConfig;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getStations(): Array\<StationInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(): Promise\<WifiP2pDevice>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function createGroup(config: WifiP2PConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function removeGroup(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function p2pConnect(config: WifiP2PConfig): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function p2pCancelConnect(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function startDiscoverDevices(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function stopDiscoverDevices(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function deletePersistentGroup(netId: number): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function setDeviceName(devName: string): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "wifiStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "wifiConnectionChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "wifiScanStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "wifiRssiChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "streamChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "deviceConfigChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "hotspotStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "p2pStateChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function on(type: "p2pDiscoveryChange", callback: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "wifiStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "wifiConnectionChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "wifiScanStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "wifiRssiChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "streamChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "deviceConfigChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "hotspotStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "p2pStateChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_NONE|@ohos.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_PEAP|@ohos.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_TLS|@ohos.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_TTLS|@ohos.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_PWD|@ohos.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_SIM|@ohos.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_AKA|@ohos.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_AKA_PRIME|@ohos.wifiManager.d.ts|
|新增|NA|类名：EapMethod;<br>方法or属性：EAP_UNAUTH_TLS|@ohos.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_NONE|@ohos.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_PAP|@ohos.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_MSCHAP|@ohos.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_MSCHAPV2|@ohos.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_GTC|@ohos.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_SIM|@ohos.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_AKA|@ohos.wifiManager.d.ts|
|新增|NA|类名：Phase2Method;<br>方法or属性：PHASE2_AKA_PRIME|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：eapMethod: EapMethod;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：phase2Method: Phase2Method;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：identity: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：anonymousIdentity: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：password: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：caCertAliases: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：caPath: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：clientCertAliases: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：certEntry: Uint8Array;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：certPassword: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：altSubjectMatch: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：domainSuffixMatch: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：realm: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：plmn: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：eapSubId: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：ssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：ssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：ssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：HotspotConfig;<br>方法or属性：ssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：bssid?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：preSharedKey: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：HotspotConfig;<br>方法or属性：preSharedKey: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：isHiddenSsid?: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：securityType: WifiSecurityType;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：securityType: WifiSecurityType;|@ohos.wifiManager.d.ts|
|新增|NA|类名：HotspotConfig;<br>方法or属性：securityType: WifiSecurityType;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：creatorUid?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：disableReason?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：netId?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：randomMacType?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：randomMacAddr?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：ipType?: IpType;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：staticIp?: IpConfig;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：eapConfig?: WifiEapConfig;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpConfig;<br>方法or属性：ipAddress: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：ipAddress: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpInfo;<br>方法or属性：ipAddress: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpConfig;<br>方法or属性：gateway: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpInfo;<br>方法or属性：gateway: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpConfig;<br>方法or属性：prefixLength: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpConfig;<br>方法or属性：dnsServers: number[];|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpConfig;<br>方法or属性：domains: Array\<string>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiInfoElem;<br>方法or属性：eid: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiInfoElem;<br>方法or属性：content: Uint8Array;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiChannelWidth;<br>方法or属性：WIDTH_20MHZ = 0|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiChannelWidth;<br>方法or属性：WIDTH_40MHZ = 1|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiChannelWidth;<br>方法or属性：WIDTH_80MHZ = 2|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiChannelWidth;<br>方法or属性：WIDTH_160MHZ = 3|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiChannelWidth;<br>方法or属性：WIDTH_80MHZ_PLUS = 4|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiChannelWidth;<br>方法or属性：WIDTH_INVALID|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：bssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：bssid: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：capabilities: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：rssi: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：rssi: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：band: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：band: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：HotspotConfig;<br>方法or属性：band: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：frequency: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：frequency: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pGroupInfo;<br>方法or属性：frequency: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：channelWidth: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：centerFrequency0: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：centerFrequency1: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：infoElems: Array\<WifiInfoElem>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：timestamp: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_INVALID = 0|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_OPEN = 1|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_WEP = 2|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_PSK = 3|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_SAE = 4|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_EAP = 5|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_EAP_SUITE_B = 6|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_OWE = 7|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_WAPI_CERT = 8|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_WAPI_PSK = 9|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：networkId: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pGroupInfo;<br>方法or属性：networkId: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：linkSpeed: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：isHidden: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：isRestricted: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：chload: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：snr: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：macType: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：macAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：StationInfo;<br>方法or属性：macAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：suppState: SuppState;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：connState: ConnState;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpInfo;<br>方法or属性：netmask: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpInfo;<br>方法or属性：primaryDns: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpInfo;<br>方法or属性：secondDns: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpInfo;<br>方法or属性：serverIp: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpInfo;<br>方法or属性：leaseDuration: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：HotspotConfig;<br>方法or属性：maxConn: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：StationInfo;<br>方法or属性：name: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：StationInfo;<br>方法or属性：ipAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpType;<br>方法or属性：STATIC|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpType;<br>方法or属性：DHCP|@ohos.wifiManager.d.ts|
|新增|NA|类名：IpType;<br>方法or属性：UNKNOWN|@ohos.wifiManager.d.ts|
|新增|NA|类名：ConnState;<br>方法or属性：UNKNOWN|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：DISCONNECTED|@ohos.wifiManager.d.ts|
|新增|NA|类名：ConnState;<br>方法or属性：DISCONNECTED|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：INTERFACE_DISABLED|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：INACTIVE|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：SCANNING|@ohos.wifiManager.d.ts|
|新增|NA|类名：ConnState;<br>方法or属性：SCANNING|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：AUTHENTICATING|@ohos.wifiManager.d.ts|
|新增|NA|类名：ConnState;<br>方法or属性：AUTHENTICATING|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：ASSOCIATING|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：ASSOCIATED|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：FOUR_WAY_HANDSHAKE|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：GROUP_HANDSHAKE|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：COMPLETED|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：UNINITIALIZED|@ohos.wifiManager.d.ts|
|新增|NA|类名：SuppState;<br>方法or属性：INVALID|@ohos.wifiManager.d.ts|
|新增|NA|类名：ConnState;<br>方法or属性：CONNECTING|@ohos.wifiManager.d.ts|
|新增|NA|类名：ConnState;<br>方法or属性：OBTAINING_IPADDR|@ohos.wifiManager.d.ts|
|新增|NA|类名：ConnState;<br>方法or属性：CONNECTED|@ohos.wifiManager.d.ts|
|新增|NA|类名：ConnState;<br>方法or属性：DISCONNECTING|@ohos.wifiManager.d.ts|
| 新增 | NA   | 类名：WifiP2PConfig; <br>方法or属性：passphrase: string; | @ohos.wifiManager.d.ts |
|新增|NA|类名：WifiP2pDevice;<br>方法or属性：deviceName: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pDevice;<br>方法or属性：deviceAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2PConfig;<br>方法or属性：deviceAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pDevice;<br>方法or属性：primaryDeviceType: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pDevice;<br>方法or属性：deviceStatus: P2pDeviceStatus;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pDevice;<br>方法or属性：groupCapabilities: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2PConfig;<br>方法or属性：netId: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pGroupInfo;<br>方法or属性：passphrase: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2PConfig;<br>方法or属性：groupName: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pGroupInfo;<br>方法or属性：groupName: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2PConfig;<br>方法or属性：goBand: GroupOwnerBand;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pGroupInfo;<br>方法or属性：isP2pGo: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pGroupInfo;<br>方法or属性：ownerInfo: WifiP2pDevice;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pGroupInfo;<br>方法or属性：interface: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pGroupInfo;<br>方法or属性：clientDevices: WifiP2pDevice[];|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pGroupInfo;<br>方法or属性：goIpAddress: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：P2pConnectState;<br>方法or属性：DISCONNECTED = 0|@ohos.wifiManager.d.ts|
|新增|NA|类名：P2pConnectState;<br>方法or属性：CONNECTED = 1|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pLinkedInfo;<br>方法or属性：connectState: P2pConnectState;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pLinkedInfo;<br>方法or属性：isGroupOwner: boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pLinkedInfo;<br>方法or属性：groupOwnerAddr: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：P2pDeviceStatus;<br>方法or属性：CONNECTED = 0|@ohos.wifiManager.d.ts|
|新增|NA|类名：P2pDeviceStatus;<br>方法or属性：INVITED = 1|@ohos.wifiManager.d.ts|
|新增|NA|类名：P2pDeviceStatus;<br>方法or属性：FAILED = 2|@ohos.wifiManager.d.ts|
|新增|NA|类名：P2pDeviceStatus;<br>方法or属性：AVAILABLE = 3|@ohos.wifiManager.d.ts|
|新增|NA|类名：P2pDeviceStatus;<br>方法or属性：UNAVAILABLE = 4|@ohos.wifiManager.d.ts|
|新增|NA|类名：GroupOwnerBand;<br>方法or属性：GO_BAND_AUTO = 0|@ohos.wifiManager.d.ts|
|新增|NA|类名：GroupOwnerBand;<br>方法or属性：GO_BAND_2GHZ = 1|@ohos.wifiManager.d.ts|
|新增|NA|类名：GroupOwnerBand;<br>方法or属性：GO_BAND_5GHZ = 2|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManagerExt;<br>方法or属性：function enableHotspot(): void;|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：wifiManagerExt;<br>方法or属性：function disableHotspot(): void;|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：wifiManagerExt;<br>方法or属性：function getSupportedPowerMode(): Promise\<Array\<PowerMode>>;|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：wifiManagerExt;<br>方法or属性：function getSupportedPowerMode(callback: AsyncCallback\<Array\<PowerMode>>): void;|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：wifiManagerExt;<br>方法or属性：function getPowerMode (): Promise\<PowerMode>;|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：wifiManagerExt;<br>方法or属性：function getPowerMode (callback: AsyncCallback\<PowerMode>): void;|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：wifiManagerExt;<br>方法or属性：function setPowerMode(mode: PowerMode) : void|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：PowerMode;<br>方法or属性：SLEEPING = 0|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：PowerMode;<br>方法or属性：GENERAL = 1|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：PowerMode;<br>方法or属性：THROUGH_WALL = 2|@ohos.wifiManagerExt.d.ts|
|新增|NA|类名：IsoDepTag;<br>方法or属性：getHistoricalBytes(): number[];|nfctech.d.ts|
|新增|NA|类名：IsoDepTag;<br>方法or属性：getHiLayerResponse(): number[];|nfctech.d.ts|
|新增|NA|类名：IsoDepTag;<br>方法or属性：isExtendedApduSupported(): Promise\<boolean>;|nfctech.d.ts|
|新增|NA|类名：IsoDepTag;<br>方法or属性：isExtendedApduSupported(callback: AsyncCallback\<boolean>): void;|nfctech.d.ts|
|新增|NA|类名：NdefMessage;<br>方法or属性：getNdefRecords(): tag.NdefRecord[];|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：getNdefTagType(): tag.NfcForumType;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：getNdefMessage(): NdefMessage;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：isNdefWritable(): boolean;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：readNdef(): Promise\<NdefMessage>;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：readNdef(callback: AsyncCallback\<NdefMessage>): void;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：writeNdef(msg: NdefMessage): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：writeNdef(msg: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：canSetReadOnly(): boolean;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：setReadOnly(): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：setReadOnly(callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：NdefTag;<br>方法or属性：getNdefTagTypeString(type: tag.NfcForumType): string;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：readSingleBlock(blockIndex: number): Promise\<number[]>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：writeSingleBlock(blockIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：incrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：decrementBlock(blockIndex: number, value: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：transferToBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：restoreFromBlock(blockIndex: number): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：getSectorCount(): number;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：getBlockCountInSector(sectorIndex: number): number;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：getType(): tag.MifareClassicType;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：getTagSize(): number;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：isEmulatedTag(): boolean;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：getBlockIndex(sectorIndex: number): number;|nfctech.d.ts|
|新增|NA|类名：MifareClassicTag;<br>方法or属性：getSectorIndex(blockIndex: number): number;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag;<br>方法or属性：readMultiplePages(pageIndex: number): Promise\<number[]>;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag;<br>方法or属性：readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag;<br>方法or属性：writeSinglePage(pageIndex: number, data: number[]): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag;<br>方法or属性：writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：MifareUltralightTag;<br>方法or属性：getType(): tag.MifareUltralightType;|nfctech.d.ts|
|新增|NA|类名：NdefFormatableTag;<br>方法or属性：format(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：NdefFormatableTag;<br>方法or属性：format(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：NdefFormatableTag;<br>方法or属性：formatReadOnly(message: NdefMessage): Promise\<void>;|nfctech.d.ts|
|新增|NA|类名：NdefFormatableTag;<br>方法or属性：formatReadOnly(message: NdefMessage, callback: AsyncCallback\<void>): void;|nfctech.d.ts|
|新增|NA|类名：TagSession;<br>方法or属性：connect(): void;|tagSession.d.ts|
|新增|NA|类名：TagSession;<br>方法or属性：resetConnection(): void;|tagSession.d.ts|
|新增|NA|类名：TagSession;<br>方法or属性：isConnected(): boolean;|tagSession.d.ts|
|新增|NA|类名：TagSession;<br>方法or属性：setTimeout(timeout: number): void;|tagSession.d.ts|
|新增|NA|类名：TagSession;<br>方法or属性：getTimeout(): number;|tagSession.d.ts|
|新增|NA|类名：TagSession;<br>方法or属性：transmit(data: number[]): Promise\<number[]>;|tagSession.d.ts|
|新增|NA|类名：TagSession;<br>方法or属性：transmit(data: number[], callback: AsyncCallback\<number[]>): void;|tagSession.d.ts|
|新增|NA|类名：TagSession;<br>方法or属性：getMaxTransmitSize(): number;|tagSession.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：declare bluetooth<br>旧版本信息：|类名：bluetooth;<br>方法or属性：declare bluetooth<br>新版本信息：9<br>代替接口： ohos.bluetoothManager|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function getState(): BluetoothState;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function getState(): BluetoothState;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.getState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function getBtConnectionState(): ProfileConnectionState;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function getBtConnectionState(): ProfileConnectionState;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.getBtConnectionState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function pairDevice(deviceId: string): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function pairDevice(deviceId: string): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.pairDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function cancelPairedDevice(deviceId: string): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function cancelPairedDevice(deviceId: string): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.cancelPairedDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function getRemoteDeviceName(deviceId: string): string;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function getRemoteDeviceName(deviceId: string): string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.getRemoteDeviceName|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.getRemoteDeviceClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function enableBluetooth(): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function enableBluetooth(): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.enableBluetooth|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function disableBluetooth(): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function disableBluetooth(): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.disableBluetooth|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function getLocalName(): string;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function getLocalName(): string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.getLocalName|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function getPairedDevices(): Array\<string>;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function getPairedDevices(): Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.getPairedDevices|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function getProfileConnState(profileId: ProfileId): ProfileConnectionState;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function getProfileConnState(profileId: ProfileId): ProfileConnectionState;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.getProfileConnectionState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function setDevicePairingConfirmation(device: string, accept: boolean): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function setDevicePairingConfirmation(device: string, accept: boolean): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.setDevicePairingConfirmation|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function setLocalName(name: string): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function setLocalName(name: string): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.setLocalName|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function setBluetoothScanMode(mode: ScanMode, duration: number): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function setBluetoothScanMode(mode: ScanMode, duration: number): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.setBluetoothScanMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function getBluetoothScanMode(): ScanMode;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function getBluetoothScanMode(): ScanMode;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.getBluetoothScanMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function startBluetoothDiscovery(): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function startBluetoothDiscovery(): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.startBluetoothDiscovery|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function stopBluetoothDiscovery(): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function stopBluetoothDiscovery(): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.stopBluetoothDiscovery|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function on(type: "bluetoothDeviceFind", callback: Callback\<Array\<string>>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.on#event:bluetoothDeviceFind|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function on(type: "bondStateChange", callback: Callback\<BondStateParam>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function on(type: "bondStateChange", callback: Callback\<BondStateParam>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.on#event:bondStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function on(type: "pinRequired", callback: Callback\<PinRequiredParam>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.on#event:pinRequired|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function on(type: "stateChange", callback: Callback\<BluetoothState>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function on(type: "stateChange", callback: Callback\<BluetoothState>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.on#event:stateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function on(type: "sppRead", clientSocket: number, callback: Callback\<ArrayBuffer>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.on#event:sppRead|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function off(type: "bluetoothDeviceFind", callback?: Callback\<Array\<string>>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.off#event:bluetoothDeviceFind|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function off(type: "bondStateChange", callback?: Callback\<BondStateParam>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.off#event:bondStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function off(type: "pinRequired", callback?: Callback\<PinRequiredParam>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.off#event:pinRequired|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function off(type: "stateChange", callback?: Callback\<BluetoothState>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function off(type: "stateChange", callback?: Callback\<BluetoothState>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.off#event:stateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function off(type: "sppRead", clientSocket: number, callback?: Callback\<ArrayBuffer>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.off#event:sppRead|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.sppListen|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.sppAccept|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.sppConnect|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function sppCloseServerSocket(socket: number): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function sppCloseServerSocket(socket: number): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.sppCloseServerSocket|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function sppCloseClientSocket(socket: number): void;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function sppCloseClientSocket(socket: number): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.sppCloseClientSocket|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function sppWrite(clientSocket: number, data: ArrayBuffer): boolean;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function sppWrite(clientSocket: number, data: ArrayBuffer): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.sppWrite|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：bluetooth;<br>方法or属性：function getProfile(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile;<br>旧版本信息：|类名：bluetooth;<br>方法or属性：function getProfile(profileId: ProfileId): A2dpSourceProfile \| HandsFreeAudioGatewayProfile;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.getProfileInstance|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BaseProfile;<br>方法or属性：interface BaseProfile<br>旧版本信息：|类名：BaseProfile;<br>方法or属性：interface BaseProfile<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BaseProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BaseProfile;<br>方法or属性：getConnectionDevices(): Array\<string>;<br>旧版本信息：|类名：BaseProfile;<br>方法or属性：getConnectionDevices(): Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BaseProfile#getConnectionDevices|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BaseProfile;<br>方法or属性：getDeviceState(device: string): ProfileConnectionState;<br>旧版本信息：|类名：BaseProfile;<br>方法or属性：getDeviceState(device: string): ProfileConnectionState;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BaseProfile#getDeviceState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：interface A2dpSourceProfile<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：interface A2dpSourceProfile<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：connect(device: string): boolean;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：connect(device: string): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile#connect|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：connect(device: string): boolean;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：connect(device: string): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile#connect|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：disconnect(device: string): boolean;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：disconnect(device: string): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile#disconnect|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：disconnect(device: string): boolean;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：disconnect(device: string): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile#disconnect|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile.on#event:connectionStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile.on#event:connectionStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile.off#event:connectionStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile.off#event:connectionStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：getPlayingState(device: string): PlayingState;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：getPlayingState(device: string): PlayingState;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile#getPlayingState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：interface HandsFreeAudioGatewayProfile<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：interface HandsFreeAudioGatewayProfile<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：BLE<br>旧版本信息：|类名：BLE;<br>方法or属性：BLE<br>新版本信息：9<br>代替接口： ohos.bluetoothManager|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function createGattServer(): GattServer;<br>旧版本信息：|类名：BLE;<br>方法or属性：function createGattServer(): GattServer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLE.createGattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function createGattClientDevice(deviceId: string): GattClientDevice;<br>旧版本信息：|类名：BLE;<br>方法or属性：function createGattClientDevice(deviceId: string): GattClientDevice;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLE.createGattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function getConnectedBLEDevices(): Array\<string>;<br>旧版本信息：|类名：BLE;<br>方法or属性：function getConnectedBLEDevices(): Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLE.getConnectedBLEDevices|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>旧版本信息：|类名：BLE;<br>方法or属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLE.startBLEScan|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function stopBLEScan(): void;<br>旧版本信息：|类名：BLE;<br>方法or属性：function stopBLEScan(): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLE.stopBLEScan|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void;<br>旧版本信息：|类名：BLE;<br>方法or属性：function on(type: "BLEDeviceFind", callback: Callback\<Array\<ScanResult>>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLE.on#event:BLEDeviceFind|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void;<br>旧版本信息：|类名：BLE;<br>方法or属性：function off(type: "BLEDeviceFind", callback?: Callback\<Array\<ScanResult>>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLE.off#event:BLEDeviceFind|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：interface GattServer<br>旧版本信息：|类名：GattServer;<br>方法or属性：interface GattServer<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#startAdvertising|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：stopAdvertising(): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：stopAdvertising(): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#stopAdvertising|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：addService(service: GattService): boolean;<br>旧版本信息：|类名：GattServer;<br>方法or属性：addService(service: GattService): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#addService|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：removeService(serviceUuid: string): boolean;<br>旧版本信息：|类名：GattServer;<br>方法or属性：removeService(serviceUuid: string): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#removeService|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：close(): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：close(): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#close|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean;<br>旧版本信息：|类名：GattServer;<br>方法or属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#notifyCharacteristicChanged|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：sendResponse(serverResponse: ServerResponse): boolean;<br>旧版本信息：|类名：GattServer;<br>方法or属性：sendResponse(serverResponse: ServerResponse): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#sendResponse|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: "characteristicRead", callback: Callback\<CharacteristicReadReq>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: "characteristicRead", callback: Callback\<CharacteristicReadReq>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#on#event:characteristicRead|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteReq>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: "characteristicWrite", callback: Callback\<CharacteristicWriteReq>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#on#event:characteristicWrite|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: "descriptorRead", callback: Callback\<DescriptorReadReq>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: "descriptorRead", callback: Callback\<DescriptorReadReq>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#on#event:descriptorRead|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#on#event:descriptorWrite|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: "connectStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#on#event:connectStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: "characteristicRead", callback?: Callback\<CharacteristicReadReq>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: "characteristicRead", callback?: Callback\<CharacteristicReadReq>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#off#event:characteristicRead|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteReq>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: "characteristicWrite", callback?: Callback\<CharacteristicWriteReq>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#off#event:characteristicWrite|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: "descriptorRead", callback?: Callback\<DescriptorReadReq>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: "descriptorRead", callback?: Callback\<DescriptorReadReq>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#off#event:descriptorRead|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteReq>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: "descriptorWrite", callback?: Callback\<DescriptorWriteReq>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#off#event:descriptorWrite|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: "connectStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattServer#off#event:connectStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：interface GattClientDevice<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：interface GattClientDevice<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：connect(): boolean;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：connect(): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#connect|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：disconnect(): boolean;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：disconnect(): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#disconnect|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：close(): boolean;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：close(): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#close|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getDeviceName(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getDeviceName(callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#getDeviceName|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#getServices|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#readCharacteristicValue|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#readDescriptorValue|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：writeCharacteristicValue(characteristic: BLECharacteristic): boolean;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：writeCharacteristicValue(characteristic: BLECharacteristic): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#writeCharacteristicValue|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：writeDescriptorValue(descriptor: BLEDescriptor): boolean;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：writeDescriptorValue(descriptor: BLEDescriptor): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#writeDescriptorValue|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getRssiValue(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getRssiValue(callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#getRssiValue|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：setBLEMtuSize(mtu: number): boolean;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：setBLEMtuSize(mtu: number): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#setBLEMtuSize|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#setNotifyCharacteristicChanged|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：on(type: "BLECharacteristicChange", callback: Callback\<BLECharacteristic>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#on#event:BLECharacteristicChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：on(type: "BLEConnectionStateChange", callback: Callback\<BLEConnectChangedState>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#on#event:BLEConnectionStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：off(type: "BLECharacteristicChange", callback?: Callback\<BLECharacteristic>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#off#event:BLECharacteristicChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：off(type: "BLEConnectionStateChange", callback?: Callback\<BLEConnectChangedState>): void;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattClientDevice#off#event:BLEConnectionStateChange|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：interface GattService<br>旧版本信息：|类名：GattService;<br>方法or属性：interface GattService<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattService|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：GattService;<br>方法or属性：serviceUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattService|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：serviceUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLECharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：serviceUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLEDescriptor|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：serviceUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.NotifyCharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicReadReq;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：CharacteristicReadReq;<br>方法or属性：serviceUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：CharacteristicWriteReq;<br>方法or属性：serviceUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorReadReq;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：DescriptorReadReq;<br>方法or属性：serviceUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：serviceUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServiceData;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：ServiceData;<br>方法or属性：serviceUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ServiceData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：isPrimary: boolean;<br>旧版本信息：|类名：GattService;<br>方法or属性：isPrimary: boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattService|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：characteristics: Array\<BLECharacteristic>;<br>旧版本信息：|类名：GattService;<br>方法or属性：characteristics: Array\<BLECharacteristic>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattService|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：includeServices?: Array\<GattService>;<br>旧版本信息：|类名：GattService;<br>方法or属性：includeServices?: Array\<GattService>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.GattService|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：interface BLECharacteristic<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：interface BLECharacteristic<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLECharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：characteristicUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLECharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：characteristicUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLEDescriptor|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：characteristicUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.NotifyCharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicReadReq;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：CharacteristicReadReq;<br>方法or属性：characteristicUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：CharacteristicWriteReq;<br>方法or属性：characteristicUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorReadReq;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：DescriptorReadReq;<br>方法or属性：characteristicUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：characteristicUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLECharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.NotifyCharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：descriptors: Array\<BLEDescriptor>;<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：descriptors: Array\<BLEDescriptor>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLECharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：interface BLEDescriptor<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：interface BLEDescriptor<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLEDescriptor|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：descriptorUuid: string;<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：descriptorUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLEDescriptor|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorReadReq;<br>方法or属性：descriptorUuid: string;<br>旧版本信息：|类名：DescriptorReadReq;<br>方法or属性：descriptorUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：descriptorUuid: string;<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：descriptorUuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：descriptorValue: ArrayBuffer;<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：descriptorValue: ArrayBuffer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLEDescriptor|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：interface NotifyCharacteristic<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：interface NotifyCharacteristic<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.NotifyCharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：confirm: boolean;<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：confirm: boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.NotifyCharacteristic|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicReadReq;<br>方法or属性：interface CharacteristicReadReq<br>旧版本信息：|类名：CharacteristicReadReq;<br>方法or属性：interface CharacteristicReadReq<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicReadReq;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：CharacteristicReadReq;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：CharacteristicWriteReq;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorReadReq;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：DescriptorReadReq;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ServerResponse|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEConnectChangedState;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：BLEConnectChangedState;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLEConnectChangedState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanResult;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：ScanResult;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanResult|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：PinRequiredParam;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：PinRequiredParam;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.PinRequiredParam|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BondStateParam;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：BondStateParam;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BondStateParam|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：StateChangeParam;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：StateChangeParam;<br>方法or属性：deviceId: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.StateChangeParam|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicReadReq;<br>方法or属性：transId: number;<br>旧版本信息：|类名：CharacteristicReadReq;<br>方法or属性：transId: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq;<br>方法or属性：transId: number;<br>旧版本信息：|类名：CharacteristicWriteReq;<br>方法or属性：transId: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorReadReq;<br>方法or属性：transId: number;<br>旧版本信息：|类名：DescriptorReadReq;<br>方法or属性：transId: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：transId: number;<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：transId: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：transId: number;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：transId: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ServerResponse|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicReadReq;<br>方法or属性：offset: number;<br>旧版本信息：|类名：CharacteristicReadReq;<br>方法or属性：offset: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq;<br>方法or属性：offset: number;<br>旧版本信息：|类名：CharacteristicWriteReq;<br>方法or属性：offset: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorReadReq;<br>方法or属性：offset: number;<br>旧版本信息：|类名：DescriptorReadReq;<br>方法or属性：offset: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：offset: number;<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：offset: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：offset: number;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：offset: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ServerResponse|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq;<br>方法or属性：interface CharacteristicWriteReq<br>旧版本信息：|类名：CharacteristicWriteReq;<br>方法or属性：interface CharacteristicWriteReq<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq;<br>方法or属性：isPrep: boolean;<br>旧版本信息：|类名：CharacteristicWriteReq;<br>方法or属性：isPrep: boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：isPrep: boolean;<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：isPrep: boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq;<br>方法or属性：needRsp: boolean;<br>旧版本信息：|类名：CharacteristicWriteReq;<br>方法or属性：needRsp: boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：needRsp: boolean;<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：needRsp: boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：CharacteristicWriteReq;<br>方法or属性：value: ArrayBuffer;<br>旧版本信息：|类名：CharacteristicWriteReq;<br>方法or属性：value: ArrayBuffer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：value: ArrayBuffer;<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：value: ArrayBuffer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：value: ArrayBuffer;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：value: ArrayBuffer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ServerResponse|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorReadReq;<br>方法or属性：interface DescriptorReadReq<br>旧版本信息：|类名：DescriptorReadReq;<br>方法or属性：interface DescriptorReadReq<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DescriptorWriteReq;<br>方法or属性：interface DescriptorWriteReq<br>旧版本信息：|类名：DescriptorWriteReq;<br>方法or属性：interface DescriptorWriteReq<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：interface ServerResponse<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：interface ServerResponse<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ServerResponse|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：status: number;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：status: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ServerResponse|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEConnectChangedState;<br>方法or属性：interface BLEConnectChangedState<br>旧版本信息：|类名：BLEConnectChangedState;<br>方法or属性：interface BLEConnectChangedState<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLEConnectChangedState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BLEConnectChangedState;<br>方法or属性：state: ProfileConnectionState;<br>旧版本信息：|类名：BLEConnectChangedState;<br>方法or属性：state: ProfileConnectionState;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BLEConnectChangedState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：StateChangeParam;<br>方法or属性：state: ProfileConnectionState;<br>旧版本信息：|类名：StateChangeParam;<br>方法or属性：state: ProfileConnectionState;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.StateChangeParam|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanResult;<br>方法or属性：interface ScanResult<br>旧版本信息：|类名：ScanResult;<br>方法or属性：interface ScanResult<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanResult|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanResult;<br>方法or属性：rssi: number;<br>旧版本信息：|类名：ScanResult;<br>方法or属性：rssi: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanResult|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanResult;<br>方法or属性：data: ArrayBuffer;<br>旧版本信息：|类名：ScanResult;<br>方法or属性：data: ArrayBuffer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanResult|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseSetting;<br>方法or属性：interface AdvertiseSetting<br>旧版本信息：|类名：AdvertiseSetting;<br>方法or属性：interface AdvertiseSetting<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.AdvertiseSetting|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseSetting;<br>方法or属性：interval?: number;<br>旧版本信息：|类名：AdvertiseSetting;<br>方法or属性：interval?: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.AdvertiseSetting|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanOptions;<br>方法or属性：interval?: number;<br>旧版本信息：|类名：ScanOptions;<br>方法or属性：interval?: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanOptions|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseSetting;<br>方法or属性：txPower?: number;<br>旧版本信息：|类名：AdvertiseSetting;<br>方法or属性：txPower?: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.AdvertiseSetting|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseSetting;<br>方法or属性：connectable?: boolean;<br>旧版本信息：|类名：AdvertiseSetting;<br>方法or属性：connectable?: boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.AdvertiseSetting|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseData;<br>方法or属性：interface AdvertiseData<br>旧版本信息：|类名：AdvertiseData;<br>方法or属性：interface AdvertiseData<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.AdvertiseData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseData;<br>方法or属性：serviceUuids: Array\<string>;<br>旧版本信息：|类名：AdvertiseData;<br>方法or属性：serviceUuids: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.AdvertiseData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseData;<br>方法or属性：manufactureData: Array\<ManufactureData>;<br>旧版本信息：|类名：AdvertiseData;<br>方法or属性：manufactureData: Array\<ManufactureData>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.AdvertiseData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：AdvertiseData;<br>方法or属性：serviceData: Array\<ServiceData>;<br>旧版本信息：|类名：AdvertiseData;<br>方法or属性：serviceData: Array\<ServiceData>;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.AdvertiseData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ManufactureData;<br>方法or属性：interface ManufactureData<br>旧版本信息：|类名：ManufactureData;<br>方法or属性：interface ManufactureData<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ManufactureData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ManufactureData;<br>方法or属性：manufactureId: number;<br>旧版本信息：|类名：ManufactureData;<br>方法or属性：manufactureId: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ManufactureData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ManufactureData;<br>方法or属性：manufactureValue: ArrayBuffer;<br>旧版本信息：|类名：ManufactureData;<br>方法or属性：manufactureValue: ArrayBuffer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ManufactureData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServiceData;<br>方法or属性：interface ServiceData<br>旧版本信息：|类名：ServiceData;<br>方法or属性：interface ServiceData<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ServiceData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ServiceData;<br>方法or属性：serviceValue: ArrayBuffer;<br>旧版本信息：|类名：ServiceData;<br>方法or属性：serviceValue: ArrayBuffer;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ServiceData|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：interface ScanFilter<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：interface ScanFilter<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanFilter|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：deviceId?: string;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：deviceId?: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanFilter|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：name?: string;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：name?: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanFilter|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：serviceUuid?: string;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：serviceUuid?: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanFilter|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanOptions;<br>方法or属性：interface ScanOptions<br>旧版本信息：|类名：ScanOptions;<br>方法or属性：interface ScanOptions<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanOptions|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanOptions;<br>方法or属性：dutyMode?: ScanDuty;<br>旧版本信息：|类名：ScanOptions;<br>方法or属性：dutyMode?: ScanDuty;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanOptions|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanOptions;<br>方法or属性：matchMode?: MatchMode;<br>旧版本信息：|类名：ScanOptions;<br>方法or属性：matchMode?: MatchMode;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanOptions|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：SppOption;<br>方法or属性：interface SppOption<br>旧版本信息：|类名：SppOption;<br>方法or属性：interface SppOption<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.SppOption|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：SppOption;<br>方法or属性：uuid: string;<br>旧版本信息：|类名：SppOption;<br>方法or属性：uuid: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.SppOption|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：SppOption;<br>方法or属性：secure: boolean;<br>旧版本信息：|类名：SppOption;<br>方法or属性：secure: boolean;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.SppOption|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：SppOption;<br>方法or属性：type: SppType;<br>旧版本信息：|类名：SppOption;<br>方法or属性：type: SppType;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.SppOption|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：PinRequiredParam;<br>方法or属性：interface PinRequiredParam<br>旧版本信息：|类名：PinRequiredParam;<br>方法or属性：interface PinRequiredParam<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.PinRequiredParam|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：PinRequiredParam;<br>方法or属性：pinCode: string;<br>旧版本信息：|类名：PinRequiredParam;<br>方法or属性：pinCode: string;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.PinRequiredParam|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DeviceClass;<br>方法or属性：interface DeviceClass<br>旧版本信息：|类名：DeviceClass;<br>方法or属性：interface DeviceClass<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DeviceClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DeviceClass;<br>方法or属性：majorClass: MajorClass;<br>旧版本信息：|类名：DeviceClass;<br>方法or属性：majorClass: MajorClass;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DeviceClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DeviceClass;<br>方法or属性：majorMinorClass: MajorMinorClass;<br>旧版本信息：|类名：DeviceClass;<br>方法or属性：majorMinorClass: MajorMinorClass;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DeviceClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：DeviceClass;<br>方法or属性：classOfDevice: number;<br>旧版本信息：|类名：DeviceClass;<br>方法or属性：classOfDevice: number;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.DeviceClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BondStateParam;<br>方法or属性：interface BondStateParam<br>旧版本信息：|类名：BondStateParam;<br>方法or属性：interface BondStateParam<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BondStateParam|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BondStateParam;<br>方法or属性：state: BondState;<br>旧版本信息：|类名：BondStateParam;<br>方法or属性：state: BondState;<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BondStateParam|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanDuty;<br>方法or属性：enum ScanDuty<br>旧版本信息：|类名：ScanDuty;<br>方法or属性：enum ScanDuty<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanDuty|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_POWER = 0<br>旧版本信息：|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_POWER = 0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanDuty|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanDuty;<br>方法or属性：SCAN_MODE_BALANCED = 1<br>旧版本信息：|类名：ScanDuty;<br>方法or属性：SCAN_MODE_BALANCED = 1<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanDuty|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_LATENCY = 2<br>旧版本信息：|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_LATENCY = 2<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanDuty|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MatchMode;<br>方法or属性：enum MatchMode<br>旧版本信息：|类名：MatchMode;<br>方法or属性：enum MatchMode<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MatchMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MatchMode;<br>方法or属性：MATCH_MODE_AGGRESSIVE = 1<br>旧版本信息：|类名：MatchMode;<br>方法or属性：MATCH_MODE_AGGRESSIVE = 1<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MatchMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MatchMode;<br>方法or属性：MATCH_MODE_STICKY = 2<br>旧版本信息：|类名：MatchMode;<br>方法or属性：MATCH_MODE_STICKY = 2<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MatchMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：enum ProfileConnectionState<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：enum ProfileConnectionState<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ProfileConnectionState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTED = 0<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTED = 0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ProfileConnectionState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTING = 1<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTING = 1<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ProfileConnectionState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTED = 2<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTED = 2<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ProfileConnectionState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTING = 3<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTING = 3<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ProfileConnectionState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：enum BluetoothState<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：enum BluetoothState<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BluetoothState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_OFF = 0<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_OFF = 0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BluetoothState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_TURNING_ON = 1<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_TURNING_ON = 1<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BluetoothState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_ON = 2<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_ON = 2<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BluetoothState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_TURNING_OFF = 3<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_TURNING_OFF = 3<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BluetoothState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_ON = 4<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_ON = 4<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BluetoothState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_BLE_ON = 5<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_BLE_ON = 5<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BluetoothState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_OFF = 6<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_OFF = 6<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BluetoothState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：SppType;<br>方法or属性：enum SppType<br>旧版本信息：|类名：SppType;<br>方法or属性：enum SppType<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.SppType|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：SppType;<br>方法or属性：SPP_RFCOMM<br>旧版本信息：|类名：SppType;<br>方法or属性：SPP_RFCOMM<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.SppType|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：enum ScanMode<br>旧版本信息：|类名：ScanMode;<br>方法or属性：enum ScanMode<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_NONE = 0<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_NONE = 0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE = 1<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE = 1<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_GENERAL_DISCOVERABLE = 2<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_GENERAL_DISCOVERABLE = 2<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_LIMITED_DISCOVERABLE = 3<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_LIMITED_DISCOVERABLE = 3<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ScanMode|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BondState;<br>方法or属性：enum BondState<br>旧版本信息：|类名：BondState;<br>方法or属性：enum BondState<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BondState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BondState;<br>方法or属性：BOND_STATE_INVALID = 0<br>旧版本信息：|类名：BondState;<br>方法or属性：BOND_STATE_INVALID = 0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BondState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BondState;<br>方法or属性：BOND_STATE_BONDING = 1<br>旧版本信息：|类名：BondState;<br>方法or属性：BOND_STATE_BONDING = 1<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BondState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：BondState;<br>方法or属性：BOND_STATE_BONDED = 2<br>旧版本信息：|类名：BondState;<br>方法or属性：BOND_STATE_BONDED = 2<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.BondState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：enum MajorClass<br>旧版本信息：|类名：MajorClass;<br>方法or属性：enum MajorClass<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_MISC = 0x0000<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_MISC = 0x0000<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_COMPUTER = 0x0100<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_COMPUTER = 0x0100<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_PHONE = 0x0200<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_PHONE = 0x0200<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_NETWORKING = 0x0300<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_NETWORKING = 0x0300<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_AUDIO_VIDEO = 0x0400<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_AUDIO_VIDEO = 0x0400<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_PERIPHERAL = 0x0500<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_PERIPHERAL = 0x0500<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_IMAGING = 0x0600<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_IMAGING = 0x0600<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_WEARABLE = 0x0700<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_WEARABLE = 0x0700<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_TOY = 0x0800<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_TOY = 0x0800<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_HEALTH = 0x0900<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_HEALTH = 0x0900<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_UNCATEGORIZED = 0x1F00<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_UNCATEGORIZED = 0x1F00<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：enum MajorMinorClass<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：enum MajorMinorClass<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_UNCATEGORIZED = 0x0100<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_UNCATEGORIZED = 0x0100<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_DESKTOP = 0x0104<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_DESKTOP = 0x0104<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_SERVER = 0x0108<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_SERVER = 0x0108<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_LAPTOP = 0x010C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_LAPTOP = 0x010C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_HANDHELD_PC_PDA = 0x0110<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_HANDHELD_PC_PDA = 0x0110<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_PALM_SIZE_PC_PDA = 0x0114<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_PALM_SIZE_PC_PDA = 0x0114<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_WEARABLE = 0x0118<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_WEARABLE = 0x0118<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_TABLET = 0x011C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_TABLET = 0x011C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_UNCATEGORIZED = 0x0200<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_UNCATEGORIZED = 0x0200<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_CELLULAR = 0x0204<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_CELLULAR = 0x0204<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_CORDLESS = 0x0208<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_CORDLESS = 0x0208<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_SMART = 0x020C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_SMART = 0x020C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_MODEM_OR_GATEWAY = 0x0210<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_MODEM_OR_GATEWAY = 0x0210<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_ISDN = 0x0214<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_ISDN = 0x0214<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_FULLY_AVAILABLE = 0x0300<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_FULLY_AVAILABLE = 0x0300<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_1_TO_17_UTILIZED = 0x0320<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_1_TO_17_UTILIZED = 0x0320<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_17_TO_33_UTILIZED = 0x0340<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_17_TO_33_UTILIZED = 0x0340<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_33_TO_50_UTILIZED = 0x0360<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_33_TO_50_UTILIZED = 0x0360<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_60_TO_67_UTILIZED = 0x0380<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_60_TO_67_UTILIZED = 0x0380<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_67_TO_83_UTILIZED = 0x03A0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_67_TO_83_UTILIZED = 0x03A0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_83_TO_99_UTILIZED = 0x03C0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_83_TO_99_UTILIZED = 0x03C0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_NO_SERVICE = 0x03E0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_NO_SERVICE = 0x03E0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_UNCATEGORIZED = 0x0400<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_UNCATEGORIZED = 0x0400<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HANDSFREE = 0x0408<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HANDSFREE = 0x0408<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_MICROPHONE = 0x0410<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_MICROPHONE = 0x0410<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_LOUDSPEAKER = 0x0414<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_LOUDSPEAKER = 0x0414<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HEADPHONES = 0x0418<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HEADPHONES = 0x0418<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAR_AUDIO = 0x0420<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAR_AUDIO = 0x0420<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_SET_TOP_BOX = 0x0424<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_SET_TOP_BOX = 0x0424<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HIFI_AUDIO = 0x0428<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HIFI_AUDIO = 0x0428<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VCR = 0x042C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VCR = 0x042C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CAMERA = 0x0430<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CAMERA = 0x0430<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAMCORDER = 0x0434<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAMCORDER = 0x0434<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_MONITOR = 0x0438<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_MONITOR = 0x0438<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD = 0x0540<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD = 0x0540<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_POINTING_DEVICE = 0x0580<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_POINTING_DEVICE = 0x0580<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD_POINTING = 0x05C0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD_POINTING = 0x05C0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_UNCATEGORIZED = 0x0500<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_UNCATEGORIZED = 0x0500<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_JOYSTICK = 0x0504<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_JOYSTICK = 0x0504<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GAMEPAD = 0x0508<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GAMEPAD = 0x0508<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_REMOTE_CONTROL = 0x05C0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_REMOTE_CONTROL = 0x05C0<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SENSING_DEVICE = 0x0510<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SENSING_DEVICE = 0x0510<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITIZER_TABLET = 0x0514<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITIZER_TABLET = 0x0514<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_CARD_READER = 0x0518<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_CARD_READER = 0x0518<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITAL_PEN = 0x051C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITAL_PEN = 0x051C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SCANNER_RFID = 0x0520<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SCANNER_RFID = 0x0520<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GESTURAL_INPUT = 0x0522<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GESTURAL_INPUT = 0x0522<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_UNCATEGORIZED = 0x0600<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_UNCATEGORIZED = 0x0600<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_DISPLAY = 0x0610<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_DISPLAY = 0x0610<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_CAMERA = 0x0620<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_CAMERA = 0x0620<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_SCANNER = 0x0640<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_SCANNER = 0x0640<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_PRINTER = 0x0680<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_PRINTER = 0x0680<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_UNCATEGORIZED = 0x0700<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_UNCATEGORIZED = 0x0700<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_WRIST_WATCH = 0x0704<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_WRIST_WATCH = 0x0704<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_PAGER = 0x0708<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_PAGER = 0x0708<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_JACKET = 0x070C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_JACKET = 0x070C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_HELMET = 0x0710<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_HELMET = 0x0710<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_GLASSES = 0x0714<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_GLASSES = 0x0714<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_UNCATEGORIZED = 0x0800<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_UNCATEGORIZED = 0x0800<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_ROBOT = 0x0804<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_ROBOT = 0x0804<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_VEHICLE = 0x0808<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_VEHICLE = 0x0808<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_DOLL_ACTION_FIGURE = 0x080C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_DOLL_ACTION_FIGURE = 0x080C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_CONTROLLER = 0x0810<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_CONTROLLER = 0x0810<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_GAME = 0x0814<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_GAME = 0x0814<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_UNCATEGORIZED = 0x0900<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_UNCATEGORIZED = 0x0900<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_BLOOD_PRESSURE = 0x0904<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_BLOOD_PRESSURE = 0x0904<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_THERMOMETER = 0x0908<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_THERMOMETER = 0x0908<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_WEIGHING = 0x090C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_WEIGHING = 0x090C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_GLUCOSE = 0x0910<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_GLUCOSE = 0x0910<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_OXIMETER = 0x0914<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_OXIMETER = 0x0914<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_RATE = 0x0918<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_RATE = 0x0918<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_DATA_DISPLAY = 0x091C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_DATA_DISPLAY = 0x091C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_STEP_COUNTER = 0x0920<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_STEP_COUNTER = 0x0920<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_PEAK_FLOW_MOITOR = 0x0928<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_PEAK_FLOW_MOITOR = 0x0928<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_MEDICATION_MONITOR = 0x092C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_MEDICATION_MONITOR = 0x092C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_KNEE_PROSTHESIS = 0x0930<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_KNEE_PROSTHESIS = 0x0930<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_ANKLE_PROSTHESIS = 0x0934<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_ANKLE_PROSTHESIS = 0x0934<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_GENERIC_HEALTH_MANAGER = 0x0938<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_GENERIC_HEALTH_MANAGER = 0x0938<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.MajorMinorClass|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：StateChangeParam;<br>方法or属性：interface StateChangeParam<br>旧版本信息：|类名：StateChangeParam;<br>方法or属性：interface StateChangeParam<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.StateChangeParam|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：PlayingState;<br>方法or属性：enum PlayingState<br>旧版本信息：|类名：PlayingState;<br>方法or属性：enum PlayingState<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.PlayingState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：PlayingState;<br>方法or属性：STATE_NOT_PLAYING<br>旧版本信息：|类名：PlayingState;<br>方法or属性：STATE_NOT_PLAYING<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.PlayingState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：PlayingState;<br>方法or属性：STATE_PLAYING<br>旧版本信息：|类名：PlayingState;<br>方法or属性：STATE_PLAYING<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.PlayingState|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileId;<br>方法or属性：enum ProfileId<br>旧版本信息：|类名：ProfileId;<br>方法or属性：enum ProfileId<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ProfileId|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileId;<br>方法or属性：PROFILE_A2DP_SOURCE = 1<br>旧版本信息：|类名：ProfileId;<br>方法or属性：PROFILE_A2DP_SOURCE = 1<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ProfileId|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：ProfileId;<br>方法or属性：PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4<br>旧版本信息：|类名：ProfileId;<br>方法or属性：PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4<br>新版本信息：9<br>代替接口： ohos.bluetoothManager/bluetoothManager.ProfileId|@ohos.bluetooth.d.ts|
|废弃版本有变化|类名：connectedTag;<br>方法or属性：function init(): boolean;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function init(): boolean;<br>新版本信息：9<br>代替接口： ohos.connectedTag/connectedTag#initialize|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag;<br>方法or属性：function uninit(): boolean;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function uninit(): boolean;<br>新版本信息：9<br>代替接口： ohos.connectedTag/connectedTag#uninitialize|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag;<br>方法or属性：function readNdefTag(): Promise\<string>;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function readNdefTag(): Promise\<string>;<br>新版本信息：9<br>代替接口： ohos.connectedTag/connectedTag#read|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag;<br>方法or属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.connectedTag/connectedTag#read|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string): Promise\<void>;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string): Promise\<void>;<br>新版本信息：9<br>代替接口： ohos.connectedTag/connectedTag#write|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.connectedTag/connectedTag#write|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：HttpRequest;<br>方法or属性：on(type: "headerReceive", callback: AsyncCallback\<Object>): void;<br>旧版本信息：on_headersReceive instead since 8.|类名：HttpRequest;<br>方法or属性：on(type: "headerReceive", callback: AsyncCallback\<Object>): void;<br>新版本信息：8<br>代替接口： on_headersReceive|@ohos.net.http.d.ts|
|废弃版本有变化|类名：HttpRequest;<br>方法or属性：off(type: "headerReceive", callback?: AsyncCallback\<Object>): void;<br>旧版本信息：off_headersReceive instead since 8.|类名：HttpRequest;<br>方法or属性：off(type: "headerReceive", callback?: AsyncCallback\<Object>): void;<br>新版本信息：8<br>代替接口： off_headersReceive|@ohos.net.http.d.ts|
|废弃版本有变化|类名：cardEmulation;<br>方法or属性：function isSupported(feature: number): boolean;<br>旧版本信息：|类名：cardEmulation;<br>方法or属性：function isSupported(feature: number): boolean;<br>新版本信息：9<br>代替接口： ohos.nfc.cardEmulation/cardEmulation#hasHceCapability|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：FeatureType;<br>方法or属性：enum FeatureType<br>旧版本信息：|类名：FeatureType;<br>方法or属性：enum FeatureType<br>新版本信息：9<br>代替接口： ohos.nfc.cardEmulation/cardEmulation#hasHceCapability|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：FeatureType;<br>方法or属性：HCE = 0<br>旧版本信息：|类名：FeatureType;<br>方法or属性：HCE = 0<br>新版本信息：9<br>代替接口： ohos.nfc.cardEmulation/cardEmulation#hasHceCapability|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：FeatureType;<br>方法or属性：UICC = 1<br>旧版本信息：|类名：FeatureType;<br>方法or属性：UICC = 1<br>新版本信息：9<br>代替接口： ohos.nfc.cardEmulation/cardEmulation#hasHceCapability|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：FeatureType;<br>方法or属性：ESE = 2<br>旧版本信息：|类名：FeatureType;<br>方法or属性：ESE = 2<br>新版本信息：9<br>代替接口： ohos.nfc.cardEmulation/cardEmulation#hasHceCapability|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：HceService;<br>方法or属性：startHCE(aidList: string[]): boolean;<br>旧版本信息：|类名：HceService;<br>方法or属性：startHCE(aidList: string[]): boolean;<br>新版本信息：9<br>代替接口： ohos.nfc.cardEmulation/cardEmulation.HceService#start|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：HceService;<br>方法or属性：stopHCE(): boolean;<br>旧版本信息：|类名：HceService;<br>方法or属性：stopHCE(): boolean;<br>新版本信息：9<br>代替接口： ohos.nfc.cardEmulation/cardEmulation.HceService#stop|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：HceService;<br>方法or属性：sendResponse(responseApdu: number[]): void;<br>旧版本信息：|类名：HceService;<br>方法or属性：sendResponse(responseApdu: number[]): void;<br>新版本信息：9<br>代替接口： ohos.nfc.cardEmulation/cardEmulation.HceService#transmit|@ohos.nfc.cardEmulation.d.ts|
|废弃版本有变化|类名：nfcController;<br>方法or属性：function isNfcAvailable(): boolean<br>旧版本信息：|类名：nfcController;<br>方法or属性：function isNfcAvailable(): boolean<br>新版本信息：9<br>代替接口： global#canIUse("SystemCapability.Communication.NFC.Core")|@ohos.nfc.controller.d.ts|
|废弃版本有变化|类名：nfcController;<br>方法or属性：function openNfc(): boolean<br>旧版本信息：|类名：nfcController;<br>方法or属性：function openNfc(): boolean<br>新版本信息：9<br>代替接口： @ohos.nfc.controller.nfcController#enableNfc|@ohos.nfc.controller.d.ts|
|废弃版本有变化|类名：nfcController;<br>方法or属性：function closeNfc(): boolean<br>旧版本信息：|类名：nfcController;<br>方法or属性：function closeNfc(): boolean<br>新版本信息：9<br>代替接口： @ohos.nfc.controller.nfcController#disableNfc|@ohos.nfc.controller.d.ts|
|废弃版本有变化|类名：tag;<br>方法or属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>旧版本信息：|类名：tag;<br>方法or属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>新版本信息：9<br>代替接口： ohos.nfc.tag/tag#getNfcA|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：tag;<br>方法or属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>旧版本信息：|类名：tag;<br>方法or属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>新版本信息：9<br>代替接口： ohos.nfc.tag/tag#getNfcB|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：tag;<br>方法or属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>旧版本信息：|类名：tag;<br>方法or属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>新版本信息：9<br>代替接口： ohos.nfc.tag/tag#getNfcF|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：tag;<br>方法or属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>旧版本信息：|类名：tag;<br>方法or属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>新版本信息：9<br>代替接口： ohos.nfc.tag/tag#getNfcV|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：TagInfo;<br>方法or属性：supportedProfiles: number[];<br>旧版本信息：|类名：TagInfo;<br>方法or属性：supportedProfiles: number[];<br>新版本信息：9<br>代替接口： ohos.nfc.tag/tag.TagInfo#technology|@ohos.nfc.tag.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：class MessageParcel<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：class MessageParcel<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：static create(): MessageParcel;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：static create(): MessageParcel;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：reclaim(): void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：reclaim(): void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeRemoteObject(object: IRemoteObject): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeRemoteObject(object: IRemoteObject): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readRemoteObject(): IRemoteObject;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readRemoteObject(): IRemoteObject;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeInterfaceToken(token: string): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeInterfaceToken(token: string): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readInterfaceToken(): string;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readInterfaceToken(): string;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：getSize(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：getSize(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：getCapacity(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：getCapacity(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：setSize(size: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：setSize(size: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：setCapacity(size: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：setCapacity(size: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：getWritableBytes(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：getWritableBytes(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：getReadableBytes(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：getReadableBytes(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：getReadPosition(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：getReadPosition(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：getWritePosition(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：getWritePosition(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：rewindRead(pos: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：rewindRead(pos: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：rewindWrite(pos: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：rewindWrite(pos: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeNoException(): void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeNoException(): void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readException(): void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readException(): void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeByte(val: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeByte(val: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeShort(val: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeShort(val: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeInt(val: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeInt(val: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeLong(val: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeLong(val: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeFloat(val: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeFloat(val: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeDouble(val: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeDouble(val: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeBoolean(val: boolean): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeBoolean(val: boolean): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeChar(val: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeChar(val: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeString(val: string): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeString(val: string): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeSequenceable(val: Sequenceable): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeSequenceable(val: Sequenceable): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeByteArray(byteArray: number[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeByteArray(byteArray: number[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeShortArray(shortArray: number[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeShortArray(shortArray: number[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeIntArray(intArray: number[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeIntArray(intArray: number[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeLongArray(longArray: number[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeLongArray(longArray: number[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeFloatArray(floatArray: number[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeFloatArray(floatArray: number[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeDoubleArray(doubleArray: number[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeDoubleArray(doubleArray: number[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeBooleanArray(booleanArray: boolean[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeBooleanArray(booleanArray: boolean[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeCharArray(charArray: number[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeCharArray(charArray: number[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeStringArray(stringArray: string[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeStringArray(stringArray: string[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readByte(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readByte(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readShort(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readShort(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readInt(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readInt(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readLong(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readLong(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readFloat(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readFloat(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readDouble(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readDouble(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readBoolean(): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readBoolean(): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readChar(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readChar(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readString(): string;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readString(): string;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readSequenceable(dataIn: Sequenceable) : boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readSequenceable(dataIn: Sequenceable) : boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readByteArray(dataIn: number[]) : void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readByteArray(dataIn: number[]) : void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readByteArray(): number[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readByteArray(): number[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readShortArray(dataIn: number[]) : void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readShortArray(dataIn: number[]) : void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readShortArray(): number[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readShortArray(): number[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readIntArray(dataIn: number[]) : void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readIntArray(dataIn: number[]) : void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readIntArray(): number[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readIntArray(): number[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readLongArray(dataIn: number[]) : void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readLongArray(dataIn: number[]) : void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readLongArray(): number[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readLongArray(): number[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readFloatArray(dataIn: number[]) : void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readFloatArray(dataIn: number[]) : void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readFloatArray(): number[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readFloatArray(): number[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readDoubleArray(dataIn: number[]) : void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readDoubleArray(dataIn: number[]) : void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readDoubleArray(): number[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readDoubleArray(): number[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readBooleanArray(dataIn: boolean[]) : void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readBooleanArray(dataIn: boolean[]) : void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readBooleanArray(): boolean[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readBooleanArray(): boolean[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readCharArray(dataIn: number[]) : void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readCharArray(dataIn: number[]) : void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readCharArray(): number[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readCharArray(): number[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readStringArray(dataIn: string[]) : void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readStringArray(dataIn: string[]) : void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readStringArray(): string[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readStringArray(): string[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readSequenceableArray(sequenceableArray: Sequenceable[]): void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readSequenceableArray(sequenceableArray: Sequenceable[]): void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readRemoteObjectArray(objects: IRemoteObject[]): void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readRemoteObjectArray(objects: IRemoteObject[]): void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readRemoteObjectArray(): IRemoteObject[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readRemoteObjectArray(): IRemoteObject[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：static closeFileDescriptor(fd: number): void;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：static closeFileDescriptor(fd: number): void;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：static dupFileDescriptor(fd: number) :number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：static dupFileDescriptor(fd: number) :number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：containFileDescriptors(): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：containFileDescriptors(): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeFileDescriptor(fd: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeFileDescriptor(fd: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readFileDescriptor(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readFileDescriptor(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeAshmem(ashmem: Ashmem): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeAshmem(ashmem: Ashmem): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readAshmem(): Ashmem;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readAshmem(): Ashmem;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：getRawDataCapacity(): number;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：getRawDataCapacity(): number;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：writeRawData(rawData: number[], size: number): boolean;<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：writeRawData(rawData: number[], size: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：MessageParcel;<br>方法or属性：readRawData(size: number): number[];<br>旧版本信息：|类名：MessageParcel;<br>方法or属性：readRawData(size: number): number[];<br>新版本信息：9<br>代替接口： ohos.rpc.MessageSequence|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Sequenceable;<br>方法or属性：interface Sequenceable<br>旧版本信息：|类名：Sequenceable;<br>方法or属性：interface Sequenceable<br>新版本信息：9<br>代替接口： ohos.rpc.Parcelable|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Sequenceable;<br>方法or属性：marshalling(dataOut: MessageParcel): boolean;<br>旧版本信息：|类名：Sequenceable;<br>方法or属性：marshalling(dataOut: MessageParcel): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.Parcelable|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Sequenceable;<br>方法or属性：unmarshalling(dataIn: MessageParcel) : boolean;<br>旧版本信息：|类名：Sequenceable;<br>方法or属性：unmarshalling(dataIn: MessageParcel) : boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.Parcelable|@ohos.rpc.d.ts|
|废弃版本有变化|类名：SendRequestResult;<br>方法or属性：interface SendRequestResult<br>旧版本信息：|类名：SendRequestResult;<br>方法or属性：interface SendRequestResult<br>新版本信息：9<br>代替接口： ohos.rpc.RequestResult|@ohos.rpc.d.ts|
|废弃版本有变化|类名：SendRequestResult;<br>方法or属性：errCode: number;<br>旧版本信息：|类名：SendRequestResult;<br>方法or属性：errCode: number;<br>新版本信息：9<br>代替接口： ohos.rpc.RequestResult|@ohos.rpc.d.ts|
|废弃版本有变化|类名：SendRequestResult;<br>方法or属性：code: number;<br>旧版本信息：|类名：SendRequestResult;<br>方法or属性：code: number;<br>新版本信息：9<br>代替接口： ohos.rpc.RequestResult|@ohos.rpc.d.ts|
|废弃版本有变化|类名：SendRequestResult;<br>方法or属性：data: MessageParcel;<br>旧版本信息：|类名：SendRequestResult;<br>方法or属性：data: MessageParcel;<br>新版本信息：9<br>代替接口： ohos.rpc.RequestResult|@ohos.rpc.d.ts|
|废弃版本有变化|类名：SendRequestResult;<br>方法or属性：reply: MessageParcel;<br>旧版本信息：|类名：SendRequestResult;<br>方法or属性：reply: MessageParcel;<br>新版本信息：9<br>代替接口： ohos.rpc.RequestResult|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject;<br>方法or属性：queryLocalInterface(descriptor: string): IRemoteBroker;<br>旧版本信息：|类名：IRemoteObject;<br>方法or属性：queryLocalInterface(descriptor: string): IRemoteBroker;<br>新版本信息：9<br>代替接口： ohos.rpc.IRemoteObject#getLocalInterface|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject;<br>方法or属性：queryLocalInterface(descriptor: string): IRemoteBroker;<br>旧版本信息：|类名：RemoteObject;<br>方法or属性：queryLocalInterface(descriptor: string): IRemoteBroker;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteObject#getLocalInterface|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>旧版本信息：8|类名：IRemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>新版本信息：9<br>代替接口：|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>旧版本信息：|类名：IRemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>新版本信息：9<br>代替接口： ohos.rpc.IRemoteObject#sendMessageRequest|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>旧版本信息：|类名：RemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteObject#sendMessageRequest|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>旧版本信息：|类名：RemoteProxy;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteProxy#sendMessageRequest|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>旧版本信息：|类名：IRemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>新版本信息：9<br>代替接口： ohos.rpc.IRemoteObject#sendMessageRequest|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>旧版本信息：|类名：RemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteObject#sendMessageRequest|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>旧版本信息：|类名：RemoteProxy;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteProxy#sendMessageRequest|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject;<br>方法or属性：addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>旧版本信息：|类名：IRemoteObject;<br>方法or属性：addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.IRemoteObject#registerDeathRecipient|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy;<br>方法or属性：addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>旧版本信息：|类名：RemoteProxy;<br>方法or属性：addDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteProxy#registerDeathRecipient|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject;<br>方法or属性：removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>旧版本信息：|类名：IRemoteObject;<br>方法or属性：removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.IRemoteObject#unregisterDeathRecipient|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy;<br>方法or属性：removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>旧版本信息：|类名：RemoteProxy;<br>方法or属性：removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteProxy#unregisterDeathRecipient|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IRemoteObject;<br>方法or属性：getInterfaceDescriptor(): string;<br>旧版本信息：|类名：IRemoteObject;<br>方法or属性：getInterfaceDescriptor(): string;<br>新版本信息：9<br>代替接口： ohos.rpc.IRemoteObject#getDescriptor|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject;<br>方法or属性：getInterfaceDescriptor(): string;<br>旧版本信息：|类名：RemoteObject;<br>方法or属性：getInterfaceDescriptor(): string;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteObject#getDescriptor|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy;<br>方法or属性：getInterfaceDescriptor(): string;<br>旧版本信息：|类名：RemoteProxy;<br>方法or属性：getInterfaceDescriptor(): string;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteProxy#getDescriptor|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject;<br>方法or属性：onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>旧版本信息：|类名：RemoteObject;<br>方法or属性：onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteObject#onRemoteMessageRequest|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteObject;<br>方法or属性：attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void;<br>旧版本信息：|类名：RemoteObject;<br>方法or属性：attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteObject#modifyLocalInterface|@ohos.rpc.d.ts|
|废弃版本有变化|类名：RemoteProxy;<br>方法or属性：queryLocalInterface(interface: string): IRemoteBroker;<br>旧版本信息：|类名：RemoteProxy;<br>方法or属性：queryLocalInterface(interface: string): IRemoteBroker;<br>新版本信息：9<br>代替接口： ohos.rpc.RemoteProxy#getLocalInterface|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IPCSkeleton;<br>方法or属性：static flushCommands(object: IRemoteObject): number;<br>旧版本信息：|类名：IPCSkeleton;<br>方法or属性：static flushCommands(object: IRemoteObject): number;<br>新版本信息：9<br>代替接口： ohos.rpc.IPCSkeleton#flushCmdBuffer|@ohos.rpc.d.ts|
|废弃版本有变化|类名：IPCSkeleton;<br>方法or属性：static setCallingIdentity(identity: string): boolean;<br>旧版本信息：|类名：IPCSkeleton;<br>方法or属性：static setCallingIdentity(identity: string): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.IPCSkeleton#restoreCallingIdentity|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem;<br>方法or属性：static createAshmem(name: string, size: number): Ashmem;<br>旧版本信息：|类名：Ashmem;<br>方法or属性：static createAshmem(name: string, size: number): Ashmem;<br>新版本信息：9<br>代替接口： ohos.rpc.Ashmem#create|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem;<br>方法or属性：static createAshmemFromExisting(ashmem: Ashmem): Ashmem;<br>旧版本信息：|类名：Ashmem;<br>方法or属性：static createAshmemFromExisting(ashmem: Ashmem): Ashmem;<br>新版本信息：9<br>代替接口： ohos.rpc.Ashmem#create|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem;<br>方法or属性：mapAshmem(mapType: number): boolean;<br>旧版本信息：|类名：Ashmem;<br>方法or属性：mapAshmem(mapType: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.Ashmem#mapTypedAshmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem;<br>方法or属性：mapReadAndWriteAshmem(): boolean;<br>旧版本信息：|类名：Ashmem;<br>方法or属性：mapReadAndWriteAshmem(): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.Ashmem#mapReadWriteAshmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem;<br>方法or属性：mapReadOnlyAshmem(): boolean;<br>旧版本信息：|类名：Ashmem;<br>方法or属性：mapReadOnlyAshmem(): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.Ashmem#mapReadonlyAshmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem;<br>方法or属性：setProtection(protectionType: number): boolean;<br>旧版本信息：|类名：Ashmem;<br>方法or属性：setProtection(protectionType: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.Ashmem#setProtectionType|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem;<br>方法or属性：writeToAshmem(buf: number[], size: number, offset: number): boolean;<br>旧版本信息：|类名：Ashmem;<br>方法or属性：writeToAshmem(buf: number[], size: number, offset: number): boolean;<br>新版本信息：9<br>代替接口： ohos.rpc.Ashmem#writeAshmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：Ashmem;<br>方法or属性：readFromAshmem(size: number, offset: number): number[];<br>旧版本信息：|类名：Ashmem;<br>方法or属性：readFromAshmem(size: number, offset: number): number[];<br>新版本信息：9<br>代替接口： ohos.rpc.Ashmem#readAshmem|@ohos.rpc.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function enableWifi(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function enableWifi(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.enableWifi|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function disableWifi(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function disableWifi(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.disableWifi|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function isWifiActive(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function isWifiActive(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.isWifiActive|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function scan(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function scan(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.scan|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getScanInfos(): Promise\<Array\<WifiScanInfo>>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getScanInfos(): Promise\<Array\<WifiScanInfo>>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getScanResults|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getScanResults|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig): Promise\<number>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.addDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.addDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.addCandidateConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.addCandidateConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.removeCandidateConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.removeCandidateConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function connectToNetwork(networkId: number): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function connectToNetwork(networkId: number): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.connectToNetwork|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function connectToDevice(config: WifiDeviceConfig): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function connectToDevice(config: WifiDeviceConfig): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.connectToDevice|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function disconnect(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function disconnect(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.disconnect|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getSignalLevel(rssi: number, band: number): number;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getSignalLevel(rssi: number, band: number): number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getSignalLevel|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getLinkedInfo(): Promise\<WifiLinkedInfo>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getLinkedInfo(): Promise\<WifiLinkedInfo>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function isConnected(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function isConnected(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.isConnected|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getSupportedFeatures(): number;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getSupportedFeatures(): number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getSupportedFeatures|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function isFeatureSupported(featureId: number): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function isFeatureSupported(featureId: number): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.isFeatureSupported|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getDeviceMacAddress(): string[];<br>旧版本信息：|类名：wifi;<br>方法or属性：function getDeviceMacAddress(): string[];<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getDeviceMacAddress|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getIpInfo(): IpInfo;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getIpInfo(): IpInfo;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getIpInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getCountryCode(): string;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getCountryCode(): string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getCountryCode|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function reassociate(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function reassociate(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.reassociate|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function reconnect(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function reconnect(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.reconnect|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getDeviceConfigs|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function updateNetwork(config: WifiDeviceConfig): number;<br>旧版本信息：|类名：wifi;<br>方法or属性：function updateNetwork(config: WifiDeviceConfig): number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.updateNetwork|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function disableNetwork(netId: number): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function disableNetwork(netId: number): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.disableNetwork|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function removeAllNetwork(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function removeAllNetwork(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.removeAllNetwork|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function removeDevice(id: number): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function removeDevice(id: number): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.removeDevice|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function enableHotspot(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function enableHotspot(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.enableHotspot|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function disableHotspot(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function disableHotspot(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.disableHotspot|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function isHotspotDualBandSupported(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function isHotspotDualBandSupported(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.isHotspotDualBandSupported|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function isHotspotActive(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function isHotspotActive(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.isHotspotActive|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function setHotspotConfig(config: HotspotConfig): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function setHotspotConfig(config: HotspotConfig): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.setHotspotConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getHotspotConfig(): HotspotConfig;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getHotspotConfig(): HotspotConfig;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getHotspotConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getStations(): Array\<StationInfo>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getStations(): Array\<StationInfo>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getStations|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getP2pLinkedInfo(): Promise\<WifiP2pLinkedInfo>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getP2pLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getP2pLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getCurrentGroup|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getCurrentGroup|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getP2pPeerDevices|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getP2pPeerDevices|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function createGroup(config: WifiP2PConfig): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function createGroup(config: WifiP2PConfig): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.createGroup|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function removeGroup(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function removeGroup(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.removeGroup|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function p2pConnect(config: WifiP2PConfig): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function p2pConnect(config: WifiP2PConfig): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.p2pConnect|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function p2pCancelConnect(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function p2pCancelConnect(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.p2pCancelConnect|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function startDiscoverDevices(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function startDiscoverDevices(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.startDiscoverDevices|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function stopDiscoverDevices(): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function stopDiscoverDevices(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.stopDiscoverDevices|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function deletePersistentGroup(netId: number): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function deletePersistentGroup(netId: number): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.deletePersistentGroup|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function setDeviceName(devName: string): boolean;<br>旧版本信息：|类名：wifi;<br>方法or属性：function setDeviceName(devName: string): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.setDeviceName|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "wifiStateChange", callback: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "wifiStateChange", callback: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:wifiStateChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "wifiConnectionChange", callback: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "wifiConnectionChange", callback: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:wifiConnectionChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "wifiScanStateChange", callback: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "wifiScanStateChange", callback: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:wifiScanStateChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "wifiRssiChange", callback: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "wifiRssiChange", callback: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:wifiRssiChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "streamChange", callback: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "streamChange", callback: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:streamChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "hotspotStateChange", callback: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "hotspotStateChange", callback: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:hotspotStateChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:hotspotStaJoin|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:hotspotStaLeave|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "p2pStateChange", callback: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "p2pStateChange", callback: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:p2pStateChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "p2pConnectionChange", callback: Callback\<WifiP2pLinkedInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:p2pConnectionChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "p2pDeviceChange", callback: Callback\<WifiP2pDevice>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:p2pDeviceChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "p2pPeerDeviceChange", callback: Callback\<WifiP2pDevice[]>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:p2pPeerDeviceChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "p2pPersistentGroupChange", callback: Callback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:p2pPersistentGroupChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function on(type: "p2pDiscoveryChange", callback: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function on(type: "p2pDiscoveryChange", callback: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.on#event:p2pDiscoveryChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "wifiStateChange", callback?: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "wifiStateChange", callback?: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:wifiStateChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "wifiConnectionChange", callback?: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "wifiConnectionChange", callback?: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:wifiConnectionChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "wifiScanStateChange", callback?: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "wifiScanStateChange", callback?: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:wifiScanStateChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "wifiRssiChange", callback?: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "wifiRssiChange", callback?: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:wifiRssiChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "streamChange", callback?: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "streamChange", callback?: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:streamChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "hotspotStateChange", callback?: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "hotspotStateChange", callback?: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:hotspotStateChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:hotspotStaJoin|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:hotspotStaLeave|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "p2pStateChange", callback?: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "p2pStateChange", callback?: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:p2pStateChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "p2pConnectionChange", callback?: Callback\<WifiP2pLinkedInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:p2pConnectionChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "p2pDeviceChange", callback?: Callback\<WifiP2pDevice>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:p2pDeviceChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "p2pPeerDeviceChange", callback?: Callback\<WifiP2pDevice[]>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:p2pPeerDeviceChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "p2pPersistentGroupChange", callback?: Callback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:p2pPersistentGroupChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function off(type: "p2pDiscoveryChange", callback?: Callback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.off#event:p2pDiscoveryChange|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：interface WifiDeviceConfig<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：interface WifiDeviceConfig<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：ssid: string;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：ssid: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：ssid: string;<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：ssid: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：ssid: string;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：ssid: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：HotspotConfig;<br>方法or属性：ssid: string;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：ssid: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.HotspotConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：bssid: string;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：bssid: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：bssid: string;<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：bssid: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：bssid: string;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：bssid: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：preSharedKey: string;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：preSharedKey: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：HotspotConfig;<br>方法or属性：preSharedKey: string;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：preSharedKey: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.HotspotConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：isHiddenSsid: boolean;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：isHiddenSsid: boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：securityType: WifiSecurityType;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：securityType: WifiSecurityType;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：securityType: WifiSecurityType;<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：securityType: WifiSecurityType;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：HotspotConfig;<br>方法or属性：securityType: WifiSecurityType;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：securityType: WifiSecurityType;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.HotspotConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：creatorUid: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：creatorUid: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：disableReason: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：disableReason: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：netId: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：netId: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2PConfig;<br>方法or属性：netId: number;<br>旧版本信息：|类名：WifiP2PConfig;<br>方法or属性：netId: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2PConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：randomMacType: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：randomMacType: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：randomMacAddr: string;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：randomMacAddr: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：ipType: IpType;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：ipType: IpType;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiDeviceConfig;<br>方法or属性：staticIp: IpConfig;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：staticIp: IpConfig;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpConfig;<br>方法or属性：interface IpConfig<br>旧版本信息：|类名：IpConfig;<br>方法or属性：interface IpConfig<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpConfig;<br>方法or属性：ipAddress: number;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：ipAddress: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：ipAddress: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：ipAddress: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpInfo;<br>方法or属性：ipAddress: number;<br>旧版本信息：|类名：IpInfo;<br>方法or属性：ipAddress: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpConfig;<br>方法or属性：gateway: number;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：gateway: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpInfo;<br>方法or属性：gateway: number;<br>旧版本信息：|类名：IpInfo;<br>方法or属性：gateway: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpConfig;<br>方法or属性：dnsServers: number[];<br>旧版本信息：|类名：IpConfig;<br>方法or属性：dnsServers: number[];<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpConfig;<br>方法or属性：domains: Array\<string>;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：domains: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：interface WifiScanInfo<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：interface WifiScanInfo<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：capabilities: string;<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：capabilities: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：rssi: number;<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：rssi: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：rssi: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：rssi: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：band: number;<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：band: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：band: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：band: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：HotspotConfig;<br>方法or属性：band: number;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：band: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.HotspotConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：frequency: number;<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：frequency: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：frequency: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：frequency: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：frequency: number;<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：frequency: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：channelWidth: number;<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：channelWidth: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiScanInfo;<br>方法or属性：timestamp: number;<br>旧版本信息：|类名：WifiScanInfo;<br>方法or属性：timestamp: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiScanInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiSecurityType;<br>方法or属性：enum WifiSecurityType<br>旧版本信息：|类名：WifiSecurityType;<br>方法or属性：enum WifiSecurityType<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiSecurityType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_INVALID = 0<br>旧版本信息：|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_INVALID = 0<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiSecurityType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_OPEN = 1<br>旧版本信息：|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_OPEN = 1<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiSecurityType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_WEP = 2<br>旧版本信息：|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_WEP = 2<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiSecurityType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_PSK = 3<br>旧版本信息：|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_PSK = 3<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiSecurityType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_SAE = 4<br>旧版本信息：|类名：WifiSecurityType;<br>方法or属性：WIFI_SEC_TYPE_SAE = 4<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiSecurityType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：interface WifiLinkedInfo<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：interface WifiLinkedInfo<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：networkId: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：networkId: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：networkId: number;<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：networkId: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：linkSpeed: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：linkSpeed: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：isHidden: boolean;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：isHidden: boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：isRestricted: boolean;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：isRestricted: boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：chload: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：chload: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：snr: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：snr: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：macAddress: string;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：macAddress: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：StationInfo;<br>方法or属性：macAddress: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：macAddress: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.StationInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：suppState: SuppState;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：suppState: SuppState;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiLinkedInfo;<br>方法or属性：connState: ConnState;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：connState: ConnState;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpInfo;<br>方法or属性：interface IpInfo<br>旧版本信息：|类名：IpInfo;<br>方法or属性：interface IpInfo<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpInfo;<br>方法or属性：netmask: number;<br>旧版本信息：|类名：IpInfo;<br>方法or属性：netmask: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpInfo;<br>方法or属性：primaryDns: number;<br>旧版本信息：|类名：IpInfo;<br>方法or属性：primaryDns: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpInfo;<br>方法or属性：secondDns: number;<br>旧版本信息：|类名：IpInfo;<br>方法or属性：secondDns: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpInfo;<br>方法or属性：serverIp: number;<br>旧版本信息：|类名：IpInfo;<br>方法or属性：serverIp: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpInfo;<br>方法or属性：leaseDuration: number;<br>旧版本信息：|类名：IpInfo;<br>方法or属性：leaseDuration: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：HotspotConfig;<br>方法or属性：interface HotspotConfig<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：interface HotspotConfig<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.HotspotConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：HotspotConfig;<br>方法or属性：maxConn: number;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：maxConn: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.HotspotConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：StationInfo;<br>方法or属性：interface StationInfo<br>旧版本信息：|类名：StationInfo;<br>方法or属性：interface StationInfo<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.StationInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：StationInfo;<br>方法or属性：name: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：name: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.StationInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：StationInfo;<br>方法or属性：ipAddress: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：ipAddress: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.StationInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpType;<br>方法or属性：enum IpType<br>旧版本信息：|类名：IpType;<br>方法or属性：enum IpType<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpType;<br>方法or属性：STATIC<br>旧版本信息：|类名：IpType;<br>方法or属性：STATIC<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpType;<br>方法or属性：DHCP<br>旧版本信息：|类名：IpType;<br>方法or属性：DHCP<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：IpType;<br>方法or属性：UNKNOWN<br>旧版本信息：|类名：IpType;<br>方法or属性：UNKNOWN<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.IpType|@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState;<br>方法or属性：UNKNOWN<br>旧版本信息：|类名：ConnState;<br>方法or属性：UNKNOWN<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.ConnState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：export enum SuppState<br>旧版本信息：|类名：SuppState;<br>方法or属性：export enum SuppState<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：DISCONNECTED<br>旧版本信息：|类名：SuppState;<br>方法or属性：DISCONNECTED<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState;<br>方法or属性：DISCONNECTED<br>旧版本信息：|类名：ConnState;<br>方法or属性：DISCONNECTED<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.ConnState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：INTERFACE_DISABLED<br>旧版本信息：|类名：SuppState;<br>方法or属性：INTERFACE_DISABLED<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：INACTIVE<br>旧版本信息：|类名：SuppState;<br>方法or属性：INACTIVE<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：SCANNING<br>旧版本信息：|类名：SuppState;<br>方法or属性：SCANNING<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState;<br>方法or属性：SCANNING<br>旧版本信息：|类名：ConnState;<br>方法or属性：SCANNING<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.ConnState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：AUTHENTICATING<br>旧版本信息：|类名：SuppState;<br>方法or属性：AUTHENTICATING<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState;<br>方法or属性：AUTHENTICATING<br>旧版本信息：|类名：ConnState;<br>方法or属性：AUTHENTICATING<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.ConnState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：ASSOCIATING<br>旧版本信息：|类名：SuppState;<br>方法or属性：ASSOCIATING<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：ASSOCIATED<br>旧版本信息：|类名：SuppState;<br>方法or属性：ASSOCIATED<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：FOUR_WAY_HANDSHAKE<br>旧版本信息：|类名：SuppState;<br>方法or属性：FOUR_WAY_HANDSHAKE<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：GROUP_HANDSHAKE<br>旧版本信息：|类名：SuppState;<br>方法or属性：GROUP_HANDSHAKE<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：COMPLETED<br>旧版本信息：|类名：SuppState;<br>方法or属性：COMPLETED<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：UNINITIALIZED<br>旧版本信息：|类名：SuppState;<br>方法or属性：UNINITIALIZED<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：SuppState;<br>方法or属性：INVALID<br>旧版本信息：|类名：SuppState;<br>方法or属性：INVALID<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.SuppState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState;<br>方法or属性：export enum ConnState<br>旧版本信息：|类名：ConnState;<br>方法or属性：export enum ConnState<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.ConnState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState;<br>方法or属性：CONNECTING<br>旧版本信息：|类名：ConnState;<br>方法or属性：CONNECTING<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.ConnState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState;<br>方法or属性：OBTAINING_IPADDR<br>旧版本信息：|类名：ConnState;<br>方法or属性：OBTAINING_IPADDR<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.ConnState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState;<br>方法or属性：CONNECTED<br>旧版本信息：|类名：ConnState;<br>方法or属性：CONNECTED<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.ConnState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：ConnState;<br>方法or属性：DISCONNECTING<br>旧版本信息：|类名：ConnState;<br>方法or属性：DISCONNECTING<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.ConnState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pDevice;<br>方法or属性：interface WifiP2pDevice<br>旧版本信息：|类名：WifiP2pDevice;<br>方法or属性：interface WifiP2pDevice<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pDevice|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pDevice;<br>方法or属性：deviceName: string;<br>旧版本信息：|类名：WifiP2pDevice;<br>方法or属性：deviceName: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pDevice|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pDevice;<br>方法or属性：deviceAddress: string;<br>旧版本信息：|类名：WifiP2pDevice;<br>方法or属性：deviceAddress: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pDevice|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2PConfig;<br>方法or属性：deviceAddress: string;<br>旧版本信息：|类名：WifiP2PConfig;<br>方法or属性：deviceAddress: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2PConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pDevice;<br>方法or属性：primaryDeviceType: string;<br>旧版本信息：|类名：WifiP2pDevice;<br>方法or属性：primaryDeviceType: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pDevice|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pDevice;<br>方法or属性：deviceStatus: P2pDeviceStatus;<br>旧版本信息：|类名：WifiP2pDevice;<br>方法or属性：deviceStatus: P2pDeviceStatus;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pDevice|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pDevice;<br>方法or属性：groupCapabilitys: number;<br>旧版本信息：|类名：WifiP2pDevice;<br>方法or属性：groupCapabilitys: number;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pDevice|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2PConfig;<br>方法or属性：interface WifiP2PConfig<br>旧版本信息：|类名：WifiP2PConfig;<br>方法or属性：interface WifiP2PConfig<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2PConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2PConfig;<br>方法or属性：passphrase: string;<br>旧版本信息：|类名：WifiP2PConfig;<br>方法or属性：passphrase: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2PConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：passphrase: string;<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：passphrase: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2PConfig;<br>方法or属性：groupName: string;<br>旧版本信息：|类名：WifiP2PConfig;<br>方法or属性：groupName: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2PConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：groupName: string;<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：groupName: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2PConfig;<br>方法or属性：goBand: GroupOwnerBand;<br>旧版本信息：|类名：WifiP2PConfig;<br>方法or属性：goBand: GroupOwnerBand;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2PConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：interface WifiP2pGroupInfo<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：interface WifiP2pGroupInfo<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：isP2pGo: boolean;<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：isP2pGo: boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：ownerInfo: WifiP2pDevice;<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：ownerInfo: WifiP2pDevice;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：interface: string;<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：interface: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：clientDevices: WifiP2pDevice[];<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：clientDevices: WifiP2pDevice[];<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pGroupInfo;<br>方法or属性：goIpAddress: string;<br>旧版本信息：|类名：WifiP2pGroupInfo;<br>方法or属性：goIpAddress: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pGroupInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pConnectState;<br>方法or属性：enum P2pConnectState<br>旧版本信息：|类名：P2pConnectState;<br>方法or属性：enum P2pConnectState<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.P2pConnectState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pConnectState;<br>方法or属性：DISCONNECTED = 0<br>旧版本信息：|类名：P2pConnectState;<br>方法or属性：DISCONNECTED = 0<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.P2pConnectState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pConnectState;<br>方法or属性：CONNECTED = 1<br>旧版本信息：|类名：P2pConnectState;<br>方法or属性：CONNECTED = 1<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.P2pConnectState|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pLinkedInfo;<br>方法or属性：interface WifiP2pLinkedInfo<br>旧版本信息：|类名：WifiP2pLinkedInfo;<br>方法or属性：interface WifiP2pLinkedInfo<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pLinkedInfo;<br>方法or属性：connectState: P2pConnectState;<br>旧版本信息：|类名：WifiP2pLinkedInfo;<br>方法or属性：connectState: P2pConnectState;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pLinkedInfo;<br>方法or属性：isGroupOwner: boolean;<br>旧版本信息：|类名：WifiP2pLinkedInfo;<br>方法or属性：isGroupOwner: boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：WifiP2pLinkedInfo;<br>方法or属性：groupOwnerAddr: string;<br>旧版本信息：|类名：WifiP2pLinkedInfo;<br>方法or属性：groupOwnerAddr: string;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.WifiP2pLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pDeviceStatus;<br>方法or属性：enum P2pDeviceStatus<br>旧版本信息：|类名：P2pDeviceStatus;<br>方法or属性：enum P2pDeviceStatus<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.P2pDeviceStatus|@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pDeviceStatus;<br>方法or属性：CONNECTED = 0<br>旧版本信息：|类名：P2pDeviceStatus;<br>方法or属性：CONNECTED = 0<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.P2pDeviceStatus|@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pDeviceStatus;<br>方法or属性：INVITED = 1<br>旧版本信息：|类名：P2pDeviceStatus;<br>方法or属性：INVITED = 1<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.P2pDeviceStatus|@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pDeviceStatus;<br>方法or属性：FAILED = 2<br>旧版本信息：|类名：P2pDeviceStatus;<br>方法or属性：FAILED = 2<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.P2pDeviceStatus|@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pDeviceStatus;<br>方法or属性：AVAILABLE = 3<br>旧版本信息：|类名：P2pDeviceStatus;<br>方法or属性：AVAILABLE = 3<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.P2pDeviceStatus|@ohos.wifi.d.ts|
|废弃版本有变化|类名：P2pDeviceStatus;<br>方法or属性：UNAVAILABLE = 4<br>旧版本信息：|类名：P2pDeviceStatus;<br>方法or属性：UNAVAILABLE = 4<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.P2pDeviceStatus|@ohos.wifi.d.ts|
|废弃版本有变化|类名：GroupOwnerBand;<br>方法or属性：enum GroupOwnerBand<br>旧版本信息：|类名：GroupOwnerBand;<br>方法or属性：enum GroupOwnerBand<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.GroupOwnerBand|@ohos.wifi.d.ts|
|废弃版本有变化|类名：GroupOwnerBand;<br>方法or属性：GO_BAND_AUTO = 0<br>旧版本信息：|类名：GroupOwnerBand;<br>方法or属性：GO_BAND_AUTO = 0<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.GroupOwnerBand|@ohos.wifi.d.ts|
|废弃版本有变化|类名：GroupOwnerBand;<br>方法or属性：GO_BAND_2GHZ = 1<br>旧版本信息：|类名：GroupOwnerBand;<br>方法or属性：GO_BAND_2GHZ = 1<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.GroupOwnerBand|@ohos.wifi.d.ts|
|废弃版本有变化|类名：GroupOwnerBand;<br>方法or属性：GO_BAND_5GHZ = 2<br>旧版本信息：|类名：GroupOwnerBand;<br>方法or属性：GO_BAND_5GHZ = 2<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.GroupOwnerBand|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifiext;<br>方法or属性：function enableHotspot(): boolean;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function enableHotspot(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.enableHotspot|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext;<br>方法or属性：function disableHotspot(): boolean;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function disableHotspot(): boolean;<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.disableHotspot|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext;<br>方法or属性：function getSupportedPowerModel(): Promise\<Array\<PowerModel>>;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function getSupportedPowerModel(): Promise\<Array\<PowerModel>>;<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.getSupportedPowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext;<br>方法or属性：function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.getSupportedPowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext;<br>方法or属性：function getPowerModel (): Promise\<PowerModel>;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function getPowerModel (): Promise\<PowerModel>;<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.getPowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext;<br>方法or属性：function getPowerModel (callback: AsyncCallback\<PowerModel>): void;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function getPowerModel (callback: AsyncCallback\<PowerModel>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.getPowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext;<br>方法or属性：function setPowerModel(model: PowerModel) : boolean<br>旧版本信息：|类名：wifiext;<br>方法or属性：function setPowerModel(model: PowerModel) : boolean<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.setPowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：PowerModel;<br>方法or属性：export enum PowerModel<br>旧版本信息：|类名：PowerModel;<br>方法or属性：export enum PowerModel<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.PowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：PowerModel;<br>方法or属性：SLEEPING = 0<br>旧版本信息：|类名：PowerModel;<br>方法or属性：SLEEPING = 0<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.PowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：PowerModel;<br>方法or属性：GENERAL = 1<br>旧版本信息：|类名：PowerModel;<br>方法or属性：GENERAL = 1<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.PowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：PowerModel;<br>方法or属性：THROUGH_WALL = 2<br>旧版本信息：|类名：PowerModel;<br>方法or属性：THROUGH_WALL = 2<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.PowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：TagSession;<br>方法or属性：getTagInfo(): tag.TagInfo;<br>旧版本信息：|类名：TagSession;<br>方法or属性：getTagInfo(): tag.TagInfo;<br>新版本信息：9<br>代替接口： ohos.nfc.tag/tag#getTagInfo|tagSession.d.ts|
|废弃版本有变化|类名：TagSession;<br>方法or属性：connectTag(): boolean;<br>旧版本信息：|类名：TagSession;<br>方法or属性：connectTag(): boolean;<br>新版本信息：9<br>代替接口： tagSession.TagSession#connect|tagSession.d.ts|
|废弃版本有变化|类名：TagSession;<br>方法or属性：reset(): void;<br>旧版本信息：|类名：TagSession;<br>方法or属性：reset(): void;<br>新版本信息：9<br>代替接口： tagSession.TagSession#resetConnection|tagSession.d.ts|
|废弃版本有变化|类名：TagSession;<br>方法or属性：isTagConnected(): boolean;<br>旧版本信息：|类名：TagSession;<br>方法or属性：isTagConnected(): boolean;<br>新版本信息：9<br>代替接口： tagSession.TagSession#isConnected|tagSession.d.ts|
|废弃版本有变化|类名：TagSession;<br>方法or属性：setSendDataTimeout(timeout: number): boolean;<br>旧版本信息：|类名：TagSession;<br>方法or属性：setSendDataTimeout(timeout: number): boolean;<br>新版本信息：9<br>代替接口： tagSession.TagSession#setTimeout|tagSession.d.ts|
|废弃版本有变化|类名：TagSession;<br>方法or属性：getSendDataTimeout(): number;<br>旧版本信息：|类名：TagSession;<br>方法or属性：getSendDataTimeout(): number;<br>新版本信息：9<br>代替接口： tagSession.TagSession#getTimeout|tagSession.d.ts|
|废弃版本有变化|类名：TagSession;<br>方法or属性：sendData(data: number[]): Promise\<number[]>;<br>旧版本信息：|类名：TagSession;<br>方法or属性：sendData(data: number[]): Promise\<number[]>;<br>新版本信息：9<br>代替接口： tagSession.TagSession#transmit|tagSession.d.ts|
|废弃版本有变化|类名：TagSession;<br>方法or属性：getMaxSendLength(): number;<br>旧版本信息：|类名：TagSession;<br>方法or属性：getMaxSendLength(): number;<br>新版本信息：9<br>代替接口： tagSession.TagSession#getMaxTransmitSize|tagSession.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle, callback: AsyncCallback\<ConnectionProperties>): void;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle, callback: AsyncCallback\<NetCapabilities>): void;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>新版本信息：201,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetConnection;<br>方法or属性：register(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NetConnection;<br>方法or属性：register(callback: AsyncCallback\<void>): void;<br>新版本信息：201,2100002,2100003,2101008,2101022|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetConnection;<br>方法or属性：unregister(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NetConnection;<br>方法or属性：unregister(callback: AsyncCallback\<void>): void;<br>新版本信息：2100002,2100003,2101007|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetHandle;<br>方法or属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：HttpRequest;<br>方法or属性：request(url: string, callback: AsyncCallback\<HttpResponse>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, callback: AsyncCallback\<HttpResponse>): void;<br>新版本信息：401,201,2300001,2300003,2300005,2300006,2300007,2300008,2300009,2300016,2300018,2300023,2300025,2300026,2300027,2300028,2300047,2300052,2300055,2300056,2300058,2300059,2300060,2300061,2300063,2300070,2300073,2300077,2300078,2300094,2300999|@ohos.net.http.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：connect(url: string, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer, callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：close(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：on(type: "descriptorWrite", callback: Callback\<DescriptorWriteReq>): void;<br>新版本信息：ohos.permission.USE_BLUETOOTH,ohos.permission.USE_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function init(): boolean;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function init(): boolean;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function uninit(): boolean;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function uninit(): boolean;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function readNdefTag(): Promise\<string>;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function readNdefTag(): Promise\<string>;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string): Promise\<void>;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string): Promise\<void>;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function on(type: "notify", callback: Callback\<number>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function on(type: "notify", callback: Callback\<number>): void;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function off(type: "notify", callback?:Callback\<number>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function off(type: "notify", callback?:Callback\<number>): void;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>旧版本信息：ohos.permission.GET_NETWORK_INFO|类名：connection;<br>方法or属性：function getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：ohos.permission.GET_NETWORK_INFO|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>旧版本信息：ohos.permission.GET_NETWORK_INFO|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string, callback: AsyncCallback\<Array\<NetAddress>>): void;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle;<br>方法or属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>旧版本信息：ohos.permission.GET_NETWORK_INFO|类名：NetHandle;<br>方法or属性：getAddressByName(host: string, callback: AsyncCallback\<NetAddress>): void;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：tag;<br>方法or属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>旧版本信息：ohos.permission.NFC_TAG|类名：tag;<br>方法or属性：function getNfcATag(tagInfo: TagInfo): NfcATag<br>新版本信息：|@ohos.nfc.tag.d.ts|
|权限有变化|类名：tag;<br>方法or属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>旧版本信息：ohos.permission.NFC_TAG|类名：tag;<br>方法or属性：function getNfcBTag(tagInfo: TagInfo): NfcBTag<br>新版本信息：|@ohos.nfc.tag.d.ts|
|权限有变化|类名：tag;<br>方法or属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>旧版本信息：ohos.permission.NFC_TAG|类名：tag;<br>方法or属性：function getNfcFTag(tagInfo: TagInfo): NfcFTag<br>新版本信息：|@ohos.nfc.tag.d.ts|
|权限有变化|类名：tag;<br>方法or属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>旧版本信息：ohos.permission.NFC_TAG|类名：tag;<br>方法or属性：function getNfcVTag(tagInfo: TagInfo): NfcVTag<br>新版本信息：|@ohos.nfc.tag.d.ts|
|权限有变化|类名：NfcATag;<br>方法or属性：getSak(): number;<br>旧版本信息：ohos.permission.NFC_TAG|类名：NfcATag;<br>方法or属性：getSak(): number;<br>新版本信息：|nfctech.d.ts|
|权限有变化|类名：NfcATag;<br>方法or属性：getAtqa(): number[];<br>旧版本信息：ohos.permission.NFC_TAG|类名：NfcATag;<br>方法or属性：getAtqa(): number[];<br>新版本信息：|nfctech.d.ts|
|权限有变化|类名：NfcBTag;<br>方法or属性：getRespAppData(): number[];<br>旧版本信息：ohos.permission.NFC_TAG|类名：NfcBTag;<br>方法or属性：getRespAppData(): number[];<br>新版本信息：|nfctech.d.ts|
|权限有变化|类名：NfcBTag;<br>方法or属性：getRespProtocol(): number[];<br>旧版本信息：ohos.permission.NFC_TAG|类名：NfcBTag;<br>方法or属性：getRespProtocol(): number[];<br>新版本信息：|nfctech.d.ts|
|权限有变化|类名：NfcFTag;<br>方法or属性：getSystemCode(): number[];<br>旧版本信息：ohos.permission.NFC_TAG|类名：NfcFTag;<br>方法or属性：getSystemCode(): number[];<br>新版本信息：|nfctech.d.ts|
|权限有变化|类名：NfcFTag;<br>方法or属性：getPmm(): number[];<br>旧版本信息：ohos.permission.NFC_TAG|类名：NfcFTag;<br>方法or属性：getPmm(): number[];<br>新版本信息：|nfctech.d.ts|
|权限有变化|类名：NfcVTag;<br>方法or属性：getResponseFlags(): number;<br>旧版本信息：ohos.permission.NFC_TAG|类名：NfcVTag;<br>方法or属性：getResponseFlags(): number;<br>新版本信息：|nfctech.d.ts|
|权限有变化|类名：NfcVTag;<br>方法or属性：getDsfId(): number;<br>旧版本信息：ohos.permission.NFC_TAG|类名：NfcVTag;<br>方法or属性：getDsfId(): number;<br>新版本信息：|nfctech.d.ts|
|权限有变化|类名：TagSession;<br>方法or属性：isTagConnected(): boolean;<br>旧版本信息：ohos.permission.NFC_TAG|类名：TagSession;<br>方法or属性：isTagConnected(): boolean;<br>新版本信息：|tagSession.d.ts|
|权限有变化|类名：TagSession;<br>方法or属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>旧版本信息：ohos.permission.NFC_TAG|类名：TagSession;<br>方法or属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>新版本信息：|tagSession.d.ts|
|函数有变化|类名：TCPExtraOptions;<br>方法or属性：socketLinger: {on: boolean, linger: number};|类名：TCPExtraOptions;<br>方法or属性：socketLinger?: {on: boolean, linger: number};|@ohos.net.socket.d.ts|
|函数有变化|类名：MessageOption;<br>方法or属性：TF_SYNC = 0;|类名：MessageOption;<br>方法or属性：TF_SYNC: number;|@ohos.rpc.d.ts|
|函数有变化|类名：MessageOption;<br>方法or属性：TF_ASYNC = 1;|类名：MessageOption;<br>方法or属性：TF_ASYNC: number;|@ohos.rpc.d.ts|
|函数有变化|类名：MessageOption;<br>方法or属性：TF_ACCEPT_FDS = 0x10;|类名：MessageOption;<br>方法or属性：TF_ACCEPT_FDS: number;|@ohos.rpc.d.ts|
|函数有变化|类名：MessageOption;<br>方法or属性：TF_WAIT_TIME  = 4;|类名：MessageOption;<br>方法or属性：TF_WAIT_TIME: number;|@ohos.rpc.d.ts|
|函数有变化|类名：MessageOption;<br>方法or属性：constructor(syncFlags?: number, waitTime = TF_WAIT_TIME);|类名：MessageOption;<br>方法or属性：constructor(syncFlags?: number, waitTime?: number);|@ohos.rpc.d.ts|
|函数有变化|类名：MessageOption;<br>方法or属性：constructor(syncFlags?: number, waitTime = TF_WAIT_TIME);|类名：MessageOption;<br>方法or属性：constructor(async?: boolean);|@ohos.rpc.d.ts|
|函数有变化|类名：RemoteProxy;<br>方法or属性：PING_TRANSACTION = ('_' \<\< 24) \| ('P' \<\< 16) \| ('N' \<\< 8) \| 'G';|类名：RemoteProxy;<br>方法or属性：PING_TRANSACTION: number;|@ohos.rpc.d.ts|
|函数有变化|类名：RemoteProxy;<br>方法or属性：DUMP_TRANSACTION = ('_' \<\< 24) \| ('D' \<\< 16) \| ('M' \<\< 8) \| 'P';|类名：RemoteProxy;<br>方法or属性：DUMP_TRANSACTION: number;|@ohos.rpc.d.ts|
|函数有变化|类名：RemoteProxy;<br>方法or属性：INTERFACE_TRANSACTION = ('_' \<\< 24) \| ('N' \<\< 16) \| ('T' \<\< 8) \| 'F';|类名：RemoteProxy;<br>方法or属性：INTERFACE_TRANSACTION: number;|@ohos.rpc.d.ts|
|函数有变化|类名：RemoteProxy;<br>方法or属性：MIN_TRANSACTION_ID = 0x1;|类名：RemoteProxy;<br>方法or属性：MIN_TRANSACTION_ID: number;|@ohos.rpc.d.ts|
|函数有变化|类名：RemoteProxy;<br>方法or属性：MAX_TRANSACTION_ID = 0x00FFFFFF;|类名：RemoteProxy;<br>方法or属性：MAX_TRANSACTION_ID: number;|@ohos.rpc.d.ts|
|函数有变化|类名：Ashmem;<br>方法or属性：PROT_EXEC = 4;|类名：Ashmem;<br>方法or属性：PROT_EXEC: number;|@ohos.rpc.d.ts|
|函数有变化|类名：Ashmem;<br>方法or属性：PROT_NONE = 0;|类名：Ashmem;<br>方法or属性：PROT_NONE: number;|@ohos.rpc.d.ts|
|函数有变化|类名：Ashmem;<br>方法or属性：PROT_READ = 1;|类名：Ashmem;<br>方法or属性：PROT_READ: number;|@ohos.rpc.d.ts|
|函数有变化|类名：Ashmem;<br>方法or属性：PROT_WRITE = 2;|类名：Ashmem;<br>方法or属性：PROT_WRITE: number;|@ohos.rpc.d.ts|
