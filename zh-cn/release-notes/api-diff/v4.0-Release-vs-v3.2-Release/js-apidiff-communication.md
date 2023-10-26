| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：WifiEapConfig;<br>方法or属性：caCertAliases: string;|NA|@ohos.wifiManager.d.ts|
|删除|类名：WifiEapConfig;<br>方法or属性：clientCertAliases: string;|NA|@ohos.wifiManager.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：close(callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：close(callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：close(): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：close(): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：getState(): Promise\<SocketStateBase>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getState(): Promise\<SocketStateBase>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getRemoteCertificate(callback: AsyncCallback\<X509CertRawData>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getProtocol(callback: AsyncCallback\<string>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：getProtocol(): Promise\<string>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getCipherSuite(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：send(data: string, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：send(data: string): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：a2dp;<br>方法or属性：type BaseProfile = baseProfile.BaseProfile;|@ohos.bluetooth.a2dp.d.ts|
|新增|NA|类名：a2dp;<br>方法or属性：function createA2dpSrcProfile(): A2dpSourceProfile;|@ohos.bluetooth.a2dp.d.ts|
|新增|NA|类名：A2dpSourceProfile;<br>方法or属性：connect(deviceId: string): void;|@ohos.bluetooth.a2dp.d.ts|
|新增|NA|类名：A2dpSourceProfile;<br>方法or属性：disconnect(deviceId: string): void;|@ohos.bluetooth.a2dp.d.ts|
|新增|NA|类名：A2dpSourceProfile;<br>方法or属性：getPlayingState(deviceId: string): PlayingState;|@ohos.bluetooth.a2dp.d.ts|
|新增|NA|类名：PlayingState;<br>方法or属性：STATE_NOT_PLAYING|@ohos.bluetooth.a2dp.d.ts|
|新增|NA|类名：PlayingState;<br>方法or属性：STATE_PLAYING|@ohos.bluetooth.a2dp.d.ts|
|新增|NA|类名：access;<br>方法or属性：function enableBluetooth(): void;|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：access;<br>方法or属性：function disableBluetooth(): void;|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：access;<br>方法or属性：function getState(): BluetoothState;|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：access;<br>方法or属性：function on(type: 'stateChange', callback: Callback\<BluetoothState>): void;|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：access;<br>方法or属性：function off(type: 'stateChange', callback?: Callback\<BluetoothState>): void;|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_OFF = 0|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_TURNING_ON = 1|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_ON = 2|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_TURNING_OFF = 3|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_ON = 4|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_BLE_ON = 5|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_OFF = 6|@ohos.bluetooth.access.d.ts|
|新增|NA|类名：baseProfile;<br>方法or属性：type ProfileConnectionState = constant.ProfileConnectionState;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：ConnectionStrategy;<br>方法or属性：CONNECTION_STRATEGY_UNSUPPORTED = 0|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：ConnectionStrategy;<br>方法or属性：CONNECTION_STRATEGY_ALLOWED = 1|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：ConnectionStrategy;<br>方法or属性：CONNECTION_STRATEGY_FORBIDDEN = 2|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：StateChangeParam;<br>方法or属性：deviceId: string;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：StateChangeParam;<br>方法or属性：state: ProfileConnectionState;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy): Promise\<void>;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy, callback: AsyncCallback\<void>): void;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：getConnectionStrategy(deviceId: string, callback: AsyncCallback\<ConnectionStrategy>): void;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：getConnectionStrategy(deviceId: string): Promise\<ConnectionStrategy>;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：getConnectedDevices(): Array\<string>;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：getConnectionState(deviceId: string): ProfileConnectionState;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：BaseProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;|@ohos.bluetooth.baseProfile.d.ts|
|新增|NA|类名：ble;<br>方法or属性：type ProfileConnectionState = constant.ProfileConnectionState;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ble;<br>方法or属性：function createGattServer(): GattServer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ble;<br>方法or属性：function createGattClientDevice(deviceId: string): GattClientDevice;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ble;<br>方法or属性：function getConnectedBLEDevices(): Array\<string>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ble;<br>方法or属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ble;<br>方法or属性：function stopBLEScan(): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ble;<br>方法or属性：function startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ble;<br>方法or属性：function stopAdvertising(): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ble;<br>方法or属性：function on(type: 'BLEDeviceFind', callback: Callback\<Array\<ScanResult>>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ble;<br>方法or属性：function off(type: 'BLEDeviceFind', callback?: Callback\<Array\<ScanResult>>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：addService(service: GattService): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：removeService(serviceUuid: string): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：close(): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：close(): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：notifyCharacteristicChanged(<br><br>      deviceId: string,<br><br>      notifyCharacteristic: NotifyCharacteristic,<br><br>      callback: AsyncCallback\<void><br><br>    ): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): Promise\<void>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：sendResponse(serverResponse: ServerResponse): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: 'characteristicRead', callback: Callback\<CharacteristicReadRequest>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: 'characteristicWrite', callback: Callback\<CharacteristicWriteRequest>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: 'descriptorRead', callback: Callback\<DescriptorReadRequest>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteRequest>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<BLEConnectionChangeState>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：on(type: 'BLEMtuChange', callback: Callback\<number>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：on(type: 'BLEMtuChange', callback: Callback\<number>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: 'characteristicRead', callback?: Callback\<CharacteristicReadRequest>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: 'characteristicWrite', callback?: Callback\<CharacteristicWriteRequest>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: 'descriptorRead', callback?: Callback\<DescriptorReadRequest>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: 'descriptorWrite', callback?: Callback\<DescriptorWriteRequest>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<BLEConnectionChangeState>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattServer;<br>方法or属性：off(type: 'BLEMtuChange', callback?: Callback\<number>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：off(type: 'BLEMtuChange', callback?: Callback\<number>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：connect(): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：disconnect(): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getDeviceName(callback: AsyncCallback\<string>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：writeCharacteristicValue(<br><br>      characteristic: BLECharacteristic,<br><br>      writeType: GattWriteType,<br><br>      callback: AsyncCallback\<void><br><br>    ): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：writeCharacteristicValue(characteristic: BLECharacteristic, writeType: GattWriteType): Promise\<void>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：writeDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<void>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：writeDescriptorValue(descriptor: BLEDescriptor): Promise\<void>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getRssiValue(callback: AsyncCallback\<number>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：setBLEMtuSize(mtu: number): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：setCharacteristicChangeNotification(<br><br>      characteristic: BLECharacteristic,<br><br>      enable: boolean,<br><br>      callback: AsyncCallback\<void><br><br>    ): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：setCharacteristicChangeNotification(characteristic: BLECharacteristic, enable: boolean): Promise\<void>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：setCharacteristicChangeIndication(<br><br>      characteristic: BLECharacteristic,<br><br>      enable: boolean,<br><br>      callback: AsyncCallback\<void><br><br>    ): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：setCharacteristicChangeIndication(characteristic: BLECharacteristic, enable: boolean): Promise\<void>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：on(type: 'BLECharacteristicChange', callback: Callback\<BLECharacteristic>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：on(type: 'BLEConnectionStateChange', callback: Callback\<BLEConnectionChangeState>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：off(type: 'BLECharacteristicChange', callback?: Callback\<BLECharacteristic>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattClientDevice;<br>方法or属性：off(type: 'BLEConnectionStateChange', callback?: Callback\<BLEConnectionChangeState>): void;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattService;<br>方法or属性：serviceUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLECharacteristic;<br>方法or属性：serviceUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLEDescriptor;<br>方法or属性：serviceUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：NotifyCharacteristic;<br>方法or属性：serviceUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：serviceUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：serviceUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：serviceUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：serviceUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ServiceData;<br>方法or属性：serviceUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattService;<br>方法or属性：isPrimary: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattService;<br>方法or属性：characteristics: Array\<BLECharacteristic>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattService;<br>方法or属性：includeServices?: Array\<GattService>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLECharacteristic;<br>方法or属性：characteristicUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLEDescriptor;<br>方法or属性：characteristicUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：NotifyCharacteristic;<br>方法or属性：characteristicUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：characteristicUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：characteristicUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：characteristicUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：characteristicUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLECharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：NotifyCharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLECharacteristic;<br>方法or属性：descriptors: Array\<BLEDescriptor>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLECharacteristic;<br>方法or属性：properties?: GattProperties;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLEDescriptor;<br>方法or属性：descriptorUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：descriptorUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：descriptorUuid: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLEDescriptor;<br>方法or属性：descriptorValue: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：NotifyCharacteristic;<br>方法or属性：confirm: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：deviceId: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：deviceId: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：deviceId: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：deviceId: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：deviceId: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLEConnectionChangeState;<br>方法or属性：deviceId: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanResult;<br>方法or属性：deviceId: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：transId: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：transId: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：transId: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：transId: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：transId: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicReadRequest;<br>方法or属性：offset: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：offset: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorReadRequest;<br>方法or属性：offset: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：offset: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：offset: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：isPrepared: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：isPrepared: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：needRsp: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：needRsp: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：CharacteristicWriteRequest;<br>方法or属性：value: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：DescriptorWriteRequest;<br>方法or属性：value: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：value: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ServerResponse;<br>方法or属性：status: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：BLEConnectionChangeState;<br>方法or属性：state: ProfileConnectionState;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanResult;<br>方法or属性：rssi: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanResult;<br>方法or属性：data: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanResult;<br>方法or属性：deviceName: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanResult;<br>方法or属性：connectable: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：AdvertiseSetting;<br>方法or属性：interval?: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanOptions;<br>方法or属性：interval?: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：AdvertiseSetting;<br>方法or属性：txPower?: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：AdvertiseSetting;<br>方法or属性：connectable?: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：AdvertiseData;<br>方法or属性：serviceUuids: Array\<string>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：AdvertiseData;<br>方法or属性：manufactureData: Array\<ManufactureData>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：AdvertiseData;<br>方法or属性：serviceData: Array\<ServiceData>;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：AdvertiseData;<br>方法or属性：includeDeviceName?: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ManufactureData;<br>方法or属性：manufactureId: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ManufactureData;<br>方法or属性：manufactureValue: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ServiceData;<br>方法or属性：serviceValue: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：deviceId?: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：name?: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceUuid?: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceUuidMask?: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceSolicitationUuid?: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceSolicitationUuidMask?: string;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceData?: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：serviceDataMask?: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：manufactureId?: number;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：manufactureData?: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanFilter;<br>方法or属性：manufactureDataMask?: ArrayBuffer;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanOptions;<br>方法or属性：dutyMode?: ScanDuty;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanOptions;<br>方法or属性：matchMode?: MatchMode;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattProperties;<br>方法or属性：write?: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattProperties;<br>方法or属性：writeNoResponse?: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattProperties;<br>方法or属性：read?: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattProperties;<br>方法or属性：notify?: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattProperties;<br>方法or属性：indicate?: boolean;|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattWriteType;<br>方法or属性：WRITE = 1|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：GattWriteType;<br>方法or属性：WRITE_NO_RESPONSE = 2|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_POWER = 0|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanDuty;<br>方法or属性：SCAN_MODE_BALANCED = 1|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_LATENCY = 2|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：MatchMode;<br>方法or属性：MATCH_MODE_AGGRESSIVE = 1|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：MatchMode;<br>方法or属性：MATCH_MODE_STICKY = 2|@ohos.bluetooth.ble.d.ts|
|新增|NA|类名：connection;<br>方法or属性：type ProfileConnectionState = constant.ProfileConnectionState;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：type ProfileId = constant.ProfileId;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：type ProfileUuids = constant.ProfileUuids;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：type MajorClass = constant.MajorClass;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：type MajorMinorClass = constant.MajorMinorClass;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getProfileConnectionState(profileId?: ProfileId): ProfileConnectionState;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function pairDevice(deviceId: string, callback: AsyncCallback\<void>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function pairDevice(deviceId: string): Promise\<void>;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function pairCredibleDevice(deviceId: string, transport: BluetoothTransport, callback: AsyncCallback\<void>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function pairCredibleDevice(deviceId: string, transport: BluetoothTransport): Promise\<void>;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function cancelPairedDevice(deviceId: string, callback: AsyncCallback\<void>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function cancelPairedDevice(deviceId: string): Promise\<void>;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function cancelPairingDevice(deviceId: string, callback: AsyncCallback\<void>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function cancelPairingDevice(deviceId: string): Promise\<void>;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getRemoteDeviceName(deviceId: string): string;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getLocalName(): string;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getPairedDevices(): Array\<string>;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function setDevicePairingConfirmation(deviceId: string, accept: boolean): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function setDevicePinCode(deviceId: string, code: string, callback: AsyncCallback\<void>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function setDevicePinCode(deviceId: string, code: string): Promise\<void>;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function setLocalName(name: string): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function setBluetoothScanMode(mode: ScanMode, duration: number): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getBluetoothScanMode(): ScanMode;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function startBluetoothDiscovery(): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function stopBluetoothDiscovery(): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getLocalProfileUuids(callback: AsyncCallback\<Array\<ProfileUuids>>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getLocalProfileUuids(): Promise\<Array\<ProfileUuids>>;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getRemoteProfileUuids(deviceId: string, callback: AsyncCallback\<Array\<ProfileUuids>>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getRemoteProfileUuids(deviceId: string): Promise\<Array\<ProfileUuids>>;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function on(type: 'bluetoothDeviceFind', callback: Callback\<Array\<string>>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function on(type: 'bondStateChange', callback: Callback\<BondStateParam>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function on(type: 'pinRequired', callback: Callback\<PinRequiredParam>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function off(type: 'bluetoothDeviceFind', callback?: Callback\<Array\<string>>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function off(type: 'bondStateChange', callback?: Callback\<BondStateParam>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function off(type: 'pinRequired', callback?: Callback\<PinRequiredParam>): void;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：BondStateParam;<br>方法or属性：deviceId: string;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinRequiredParam;<br>方法or属性：deviceId: string;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：BondStateParam;<br>方法or属性：state: BondState;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinRequiredParam;<br>方法or属性：pinCode: string;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinRequiredParam;<br>方法or属性：pinType: PinType;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：DeviceClass;<br>方法or属性：majorClass: MajorClass;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：DeviceClass;<br>方法or属性：majorMinorClass: MajorMinorClass;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：DeviceClass;<br>方法or属性：classOfDevice: number;|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：BluetoothTransport;<br>方法or属性：TRANSPORT_BR_EDR = 0|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：BluetoothTransport;<br>方法or属性：TRANSPORT_LE = 1|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_NONE = 0|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE = 1|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_GENERAL_DISCOVERABLE = 2|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_LIMITED_DISCOVERABLE = 3|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：BondState;<br>方法or属性：BOND_STATE_INVALID = 0|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：BondState;<br>方法or属性：BOND_STATE_BONDING = 1|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：BondState;<br>方法or属性：BOND_STATE_BONDED = 2|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinType;<br>方法or属性：PIN_TYPE_ENTER_PIN_CODE = 0|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinType;<br>方法or属性：PIN_TYPE_ENTER_PASSKEY = 1|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinType;<br>方法or属性：PIN_TYPE_CONFIRM_PASSKEY = 2|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinType;<br>方法or属性：PIN_TYPE_NO_PASSKEY_CONSENT = 3|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinType;<br>方法or属性：PIN_TYPE_NOTIFY_PASSKEY = 4|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinType;<br>方法or属性：PIN_TYPE_DISPLAY_PIN_CODE = 5|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinType;<br>方法or属性：PIN_TYPE_OOB_CONSENT = 6|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：PinType;<br>方法or属性：PIN_TYPE_PIN_16_DIGITS = 7|@ohos.bluetooth.connection.d.ts|
|新增|NA|类名：ProfileId;<br>方法or属性：PROFILE_A2DP_SOURCE = 1|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileId;<br>方法or属性：PROFILE_HANDSFREE_AUDIO_GATEWAY = 4|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileId;<br>方法or属性：PROFILE_HID_HOST = 6|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileId;<br>方法or属性：PROFILE_PAN_NETWORK = 7|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HFP_AG = '0000111F-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HFP_HF = '0000111E-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HSP_AG = '00001112-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HSP_HS = '00001108-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_A2DP_SRC = '0000110A-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_A2DP_SINK = '0000110B-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_AVRCP_CT = '0000110E-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_AVRCP_TG = '0000110C-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HID = '00001124-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileUuids;<br>方法or属性：PROFILE_UUID_HOGP = '00001812-0000-1000-8000-00805F9B34FB'|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTED = 0|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTING = 1|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTED = 2|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTING = 3|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_MISC = 0x0000|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_COMPUTER = 0x0100|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_PHONE = 0x0200|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_NETWORKING = 0x0300|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_AUDIO_VIDEO = 0x0400|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_PERIPHERAL = 0x0500|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_IMAGING = 0x0600|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_WEARABLE = 0x0700|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_TOY = 0x0800|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_HEALTH = 0x0900|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorClass;<br>方法or属性：MAJOR_UNCATEGORIZED = 0x1F00|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_UNCATEGORIZED = 0x0100|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_DESKTOP = 0x0104|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_SERVER = 0x0108|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_LAPTOP = 0x010C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_HANDHELD_PC_PDA = 0x0110|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_PALM_SIZE_PC_PDA = 0x0114|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_WEARABLE = 0x0118|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：COMPUTER_TABLET = 0x011C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_UNCATEGORIZED = 0x0200|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_CELLULAR = 0x0204|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_CORDLESS = 0x0208|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_SMART = 0x020C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_MODEM_OR_GATEWAY = 0x0210|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PHONE_ISDN = 0x0214|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_FULLY_AVAILABLE = 0x0300|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_1_TO_17_UTILIZED = 0x0320|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_17_TO_33_UTILIZED = 0x0340|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_33_TO_50_UTILIZED = 0x0360|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_60_TO_67_UTILIZED = 0x0380|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_67_TO_83_UTILIZED = 0x03A0|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_83_TO_99_UTILIZED = 0x03C0|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：NETWORK_NO_SERVICE = 0x03E0|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_UNCATEGORIZED = 0x0400|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HANDSFREE = 0x0408|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_MICROPHONE = 0x0410|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_LOUDSPEAKER = 0x0414|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HEADPHONES = 0x0418|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAR_AUDIO = 0x0420|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_SET_TOP_BOX = 0x0424|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HIFI_AUDIO = 0x0428|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VCR = 0x042C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CAMERA = 0x0430|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAMCORDER = 0x0434|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_MONITOR = 0x0438|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD = 0x0540|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_POINTING_DEVICE = 0x0580|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD_POINTING = 0x05C0|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_UNCATEGORIZED = 0x0500|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_JOYSTICK = 0x0504|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GAMEPAD = 0x0508|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_REMOTE_CONTROL = 0x05C0|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SENSING_DEVICE = 0x0510|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITIZER_TABLET = 0x0514|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_CARD_READER = 0x0518|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITAL_PEN = 0x051C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SCANNER_RFID = 0x0520|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GESTURAL_INPUT = 0x0522|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：IMAGING_UNCATEGORIZED = 0x0600|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：IMAGING_DISPLAY = 0x0610|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：IMAGING_CAMERA = 0x0620|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：IMAGING_SCANNER = 0x0640|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：IMAGING_PRINTER = 0x0680|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_UNCATEGORIZED = 0x0700|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_WRIST_WATCH = 0x0704|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_PAGER = 0x0708|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_JACKET = 0x070C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_HELMET = 0x0710|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：WEARABLE_GLASSES = 0x0714|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_UNCATEGORIZED = 0x0800|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_ROBOT = 0x0804|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_VEHICLE = 0x0808|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_DOLL_ACTION_FIGURE = 0x080C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_CONTROLLER = 0x0810|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：TOY_GAME = 0x0814|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_UNCATEGORIZED = 0x0900|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_BLOOD_PRESSURE = 0x0904|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_THERMOMETER = 0x0908|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_WEIGHING = 0x090C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_GLUCOSE = 0x0910|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_OXIMETER = 0x0914|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_RATE = 0x0918|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_DATA_DISPLAY = 0x091C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_STEP_COUNTER = 0x0920|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_PEAK_FLOW_MONITOR = 0x0928|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_MEDICATION_MONITOR = 0x092C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_KNEE_PROSTHESIS = 0x0930|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_ANKLE_PROSTHESIS = 0x0934|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_GENERIC_HEALTH_MANAGER = 0x0938|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：MajorMinorClass;<br>方法or属性：HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C|@ohos.bluetooth.constant.d.ts|
|新增|NA|类名：hfp;<br>方法or属性：type BaseProfile = baseProfile.BaseProfile;|@ohos.bluetooth.hfp.d.ts|
|新增|NA|类名：hfp;<br>方法or属性：function createHfpAgProfile(): HandsFreeAudioGatewayProfile;|@ohos.bluetooth.hfp.d.ts|
|新增|NA|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：connect(deviceId: string): void;|@ohos.bluetooth.hfp.d.ts|
|新增|NA|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：disconnect(deviceId: string): void;|@ohos.bluetooth.hfp.d.ts|
|新增|NA|类名：hid;<br>方法or属性：type BaseProfile = baseProfile.BaseProfile;|@ohos.bluetooth.hid.d.ts|
|新增|NA|类名：hid;<br>方法or属性：function createHidHostProfile(): HidHostProfile;|@ohos.bluetooth.hid.d.ts|
|新增|NA|类名：HidHostProfile;<br>方法or属性：connect(deviceId: string): void;|@ohos.bluetooth.hid.d.ts|
|新增|NA|类名：HidHostProfile;<br>方法or属性：disconnect(deviceId: string): void;|@ohos.bluetooth.hid.d.ts|
|新增|NA|类名：pan;<br>方法or属性：type BaseProfile = baseProfile.BaseProfile;|@ohos.bluetooth.pan.d.ts|
|新增|NA|类名：pan;<br>方法or属性：function createPanProfile(): PanProfile;|@ohos.bluetooth.pan.d.ts|
|新增|NA|类名：PanProfile;<br>方法or属性：disconnect(deviceId: string): void;|@ohos.bluetooth.pan.d.ts|
|新增|NA|类名：PanProfile;<br>方法or属性：setTethering(enable: boolean): void;|@ohos.bluetooth.pan.d.ts|
|新增|NA|类名：PanProfile;<br>方法or属性：isTetheringOn(): boolean;|@ohos.bluetooth.pan.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function sppListen(name: string, options: SppOptions, callback: AsyncCallback\<number>): void;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function sppConnect(deviceId: string, options: SppOptions, callback: AsyncCallback\<number>): void;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function sppCloseServerSocket(socket: number): void;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function sppCloseClientSocket(socket: number): void;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function sppWrite(clientSocket: number, data: ArrayBuffer): void;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function on(type: 'sppRead', clientSocket: number, callback: Callback\<ArrayBuffer>): void;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function off(type: 'sppRead', clientSocket: number, callback?: Callback\<ArrayBuffer>): void;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：SppOptions;<br>方法or属性：uuid: string;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：SppOptions;<br>方法or属性：secure: boolean;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：SppOptions;<br>方法or属性：type: SppType;|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：SppType;<br>方法or属性：SPP_RFCOMM|@ohos.bluetooth.socket.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getAllNetsSync(): Array\<NetHandle>;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getConnectionPropertiesSync(netHandle: NetHandle): ConnectionProperties;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getNetCapabilitiesSync(netHandle: NetHandle): NetCapabilities;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function isDefaultNetMeteredSync(): boolean;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function hasDefaultNetSync(): boolean;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getAppNetSync(): NetHandle;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getDefaultHttpProxy(callback: AsyncCallback\<HttpProxy>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getDefaultHttpProxy(): Promise\<HttpProxy>;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getGlobalHttpProxy(callback: AsyncCallback\<HttpProxy>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function getGlobalHttpProxy(): Promise\<HttpProxy>;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function setGlobalHttpProxy(httpProxy: HttpProxy, callback: AsyncCallback\<void>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：connection;<br>方法or属性：function setGlobalHttpProxy(httpProxy: HttpProxy): Promise\<void>;|@ohos.net.connection.d.ts|
|新增|NA|类名：NetConnection;<br>方法or属性：on(type: 'netCapabilitiesChange', callback: Callback\<NetCapabilityInfo>): void;|@ohos.net.connection.d.ts|
|新增|NA|类名：NetCapabilityInfo;<br>方法or属性：netHandle: NetHandle;|@ohos.net.connection.d.ts|
|新增|NA|类名：NetCapabilityInfo;<br>方法or属性：netCap: NetCapabilities;|@ohos.net.connection.d.ts|
|新增|NA|类名：HttpProxy;<br>方法or属性：host: string;|@ohos.net.connection.d.ts|
|新增|NA|类名：HttpProxy;<br>方法or属性：port: number;|@ohos.net.connection.d.ts|
|新增|NA|类名：HttpProxy;<br>方法or属性：exclusionList: Array\<string>;|@ohos.net.connection.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：type HttpProxy = connection.HttpProxy;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function on(type: 'interfaceStateChange', callback: Callback\<{ iface: string, active: boolean }>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：ethernet;<br>方法or属性：function off(type: 'interfaceStateChange', callback?: Callback\<{ iface: string, active: boolean }>): void;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：InterfaceConfiguration;<br>方法or属性：httpProxy?: HttpProxy;|@ohos.net.ethernet.d.ts|
|新增|NA|类名：http;<br>方法or属性：type HttpProxy = connection.HttpProxy;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions;<br>方法or属性：usingProxy?: boolean \| HttpProxy;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequestOptions;<br>方法or属性：caPath?: string;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequest;<br>方法or属性：requestInStream(url: string, callback: AsyncCallback\<number>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequest;<br>方法or属性：requestInStream(url: string, options: HttpRequestOptions, callback: AsyncCallback\<number>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequest;<br>方法or属性：requestInStream(url: string, options?: HttpRequestOptions): Promise\<number>;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequest;<br>方法or属性：on(type: "dataReceive", callback: Callback\<ArrayBuffer>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequest;<br>方法or属性：on(type: "dataEnd", callback: Callback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequest;<br>方法or属性：on(type: 'dataReceiveProgress', callback: Callback\<{ receiveSize: number, totalSize: number }>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequest;<br>方法or属性：off(type: "dataReceive", callback?: Callback\<ArrayBuffer>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequest;<br>方法or属性：off(type: "dataEnd", callback?: Callback\<void>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：HttpRequest;<br>方法or属性：off(type: 'dataReceiveProgress', callback?: Callback\<{ receiveSize: number, totalSize: number }>): void;|@ohos.net.http.d.ts|
|新增|NA|类名：mdns;<br>方法or属性：function addLocalService(context: Context, serviceInfo: LocalServiceInfo,<br>    callback: AsyncCallback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：mdns;<br>方法or属性：function addLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>;|@ohos.net.mdns.d.ts|
|新增|NA|类名：mdns;<br>方法or属性：function removeLocalService(context: Context, serviceInfo: LocalServiceInfo,<br>    callback: AsyncCallback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：mdns;<br>方法or属性：function removeLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>;|@ohos.net.mdns.d.ts|
|新增|NA|类名：mdns;<br>方法or属性：function createDiscoveryService(context: Context, serviceType: string): DiscoveryService;|@ohos.net.mdns.d.ts|
|新增|NA|类名：mdns;<br>方法or属性：function resolveLocalService(context: Context, serviceInfo: LocalServiceInfo,<br>    callback: AsyncCallback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：mdns;<br>方法or属性：function resolveLocalService(context: Context, serviceInfo: LocalServiceInfo): Promise\<LocalServiceInfo>;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：on(type: 'discoveryStart', callback: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：on(type: 'discoveryStop', callback: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：on(type: 'serviceFound', callback: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：on(type: 'serviceLost', callback: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：off(type: 'discoveryStart', callback?: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：off(type: 'discoveryStop', callback?: Callback\<{ serviceInfo: LocalServiceInfo, errorCode?: MdnsError }>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：off(type: 'serviceFound', callback?: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：off(type: 'serviceLost', callback?: Callback\<LocalServiceInfo>): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：startSearchingMDNS(): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：DiscoveryService;<br>方法or属性：stopSearchingMDNS(): void;|@ohos.net.mdns.d.ts|
|新增|NA|类名：LocalServiceInfo;<br>方法or属性：serviceType: string;|@ohos.net.mdns.d.ts|
|新增|NA|类名：LocalServiceInfo;<br>方法or属性：serviceName: string;|@ohos.net.mdns.d.ts|
|新增|NA|类名：LocalServiceInfo;<br>方法or属性：port?: number;|@ohos.net.mdns.d.ts|
|新增|NA|类名：LocalServiceInfo;<br>方法or属性：host?: NetAddress;|@ohos.net.mdns.d.ts|
|新增|NA|类名：LocalServiceInfo;<br>方法or属性：serviceAttribute?: Array\<ServiceAttribute>;|@ohos.net.mdns.d.ts|
|新增|NA|类名：ServiceAttribute;<br>方法or属性：key: string;|@ohos.net.mdns.d.ts|
|新增|NA|类名：ServiceAttribute;<br>方法or属性：value: Array\<number>;|@ohos.net.mdns.d.ts|
|新增|NA|类名：MdnsError;<br>方法or属性：INTERNAL_ERROR = 0|@ohos.net.mdns.d.ts|
|新增|NA|类名：MdnsError;<br>方法or属性：ALREADY_ACTIVE = 1|@ohos.net.mdns.d.ts|
|新增|NA|类名：MdnsError;<br>方法or属性：MAX_LIMIT = 2|@ohos.net.mdns.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setBackgroundAllowed(isAllowed: boolean, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setBackgroundAllowed(isAllowed: boolean): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isBackgroundAllowed(callback: AsyncCallback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isBackgroundAllowed(): Promise\<boolean>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getBackgroundPolicyByUid(uid: number): Promise\<NetBackgroundPolicy>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setPolicyByUid(uid: number, policy: NetUidPolicy): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getPolicyByUid(uid: number): Promise\<NetUidPolicy>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getUidsByPolicy(policy: NetUidPolicy): Promise\<Array\<number>>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isUidNetAllowed(uid: number, isMetered: boolean): Promise\<boolean>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function isUidNetAllowed(uid: number, iface: string): Promise\<boolean>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getNetQuotaPolicies(): Promise\<Array\<NetQuotaPolicy>>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getDeviceIdleTrustlist(callback: AsyncCallback\<Array\<number>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getDeviceIdleTrustlist(): Promise\<Array\<number>>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getPowerSaveTrustlist(callback: AsyncCallback\<Array\<number>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function getPowerSaveTrustlist(): Promise\<Array\<number>>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function resetPolicies(simId: string, callback: AsyncCallback\<void>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function resetPolicies(simId: string): Promise\<void>;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netUidPolicyChange', callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netUidRuleChange', callback: Callback\<{ uid: number, rule: NetUidRule }>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netMeteredIfacesChange', callback: Callback\<Array\<string>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netQuotaPolicyChange', callback: Callback\<Array\<NetQuotaPolicy>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function on(type: 'netBackgroundPolicyChange', callback: Callback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netUidPolicyChange', callback?: Callback\<{ uid: number, policy: NetUidPolicy }>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netUidRuleChange', callback?: Callback\<{ uid: number, rule: NetUidRule }>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netMeteredIfacesChange', callback?: Callback\<Array\<string>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netQuotaPolicyChange', callback?: Callback\<Array\<NetQuotaPolicy>>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：policy;<br>方法or属性：function off(type: 'netBackgroundPolicyChange', callback?: Callback\<boolean>): void;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetBackgroundPolicy;<br>方法or属性：NET_BACKGROUND_POLICY_NONE = 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetBackgroundPolicy;<br>方法or属性：NET_BACKGROUND_POLICY_ENABLE = 1|@ohos.net.policy.d.ts|
|新增|NA|类名：NetBackgroundPolicy;<br>方法or属性：NET_BACKGROUND_POLICY_DISABLE = 2|@ohos.net.policy.d.ts|
|新增|NA|类名：NetBackgroundPolicy;<br>方法or属性：NET_BACKGROUND_POLICY_TRUSTLIST = 3|@ohos.net.policy.d.ts|
|新增|NA|类名：NetQuotaPolicy;<br>方法or属性：networkMatchRule: NetworkMatchRule;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetQuotaPolicy;<br>方法or属性：quotaPolicy: QuotaPolicy;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：periodDuration: string;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：warningBytes: number;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：limitBytes: number;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：metered: boolean;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：limitAction: LimitAction;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：lastWarningRemind?: number;|@ohos.net.policy.d.ts|
|新增|NA|类名：QuotaPolicy;<br>方法or属性：lastLimitRemind?: number;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetworkMatchRule;<br>方法or属性：netType: NetBearType;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetworkMatchRule;<br>方法or属性：identity: string;|@ohos.net.policy.d.ts|
|新增|NA|类名：NetworkMatchRule;<br>方法or属性：simId: string;|@ohos.net.policy.d.ts|
|新增|NA|类名：LimitAction;<br>方法or属性：LIMIT_ACTION_NONE = -1|@ohos.net.policy.d.ts|
|新增|NA|类名：LimitAction;<br>方法or属性：LIMIT_ACTION_ACCESS_DISABLED = 0|@ohos.net.policy.d.ts|
|新增|NA|类名：LimitAction;<br>方法or属性：LIMIT_ACTION_ALERT_ONLY = 1|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_NONE = 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_ALLOW_METERED_FOREGROUND = 1 \<\< 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_ALLOW_METERED = 1 \<\< 1|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_REJECT_METERED = 1 \<\< 2|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_ALLOW_ALL = 1 \<\< 5|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidRule;<br>方法or属性：NET_RULE_REJECT_ALL = 1 \<\< 6|@ohos.net.policy.d.ts|
|新增|NA|类名：RemindType;<br>方法or属性：REMIND_TYPE_WARNING = 1|@ohos.net.policy.d.ts|
|新增|NA|类名：RemindType;<br>方法or属性：REMIND_TYPE_LIMIT = 2|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidPolicy;<br>方法or属性：NET_POLICY_NONE = 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidPolicy;<br>方法or属性：NET_POLICY_ALLOW_METERED_BACKGROUND = 1 \<\< 0|@ohos.net.policy.d.ts|
|新增|NA|类名：NetUidPolicy;<br>方法or属性：NET_POLICY_REJECT_METERED_BACKGROUND = 1 \<\< 1|@ohos.net.policy.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function constructTCPSocketServerInstance(): TCPSocketServer;|@ohos.net.socket.d.ts|
|新增|NA|类名：socket;<br>方法or属性：function constructTLSSocketServerInstance(): TLSSocketServer;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocket;<br>方法or属性：getSocketFd(callback: AsyncCallback\<number>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocket;<br>方法or属性：getSocketFd(): Promise\<number>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：clientId: number;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：clientId: number;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：on(type: 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：on(type: 'close', callback: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketConnection;<br>方法or属性：off(type: 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketConnection;<br>方法or属性：off(type: 'close', callback?: Callback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：listen(address: NetAddress, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：listen(address: NetAddress): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：on(type: 'connect', callback: Callback\<TCPSocketConnection>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TCPSocketServer;<br>方法or属性：off(type: 'connect', callback?: Callback\<TCPSocketConnection>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：listen(options: TLSConnectOptions, callback: AsyncCallback\<void>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：listen(options: TLSConnectOptions): Promise\<void>;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：on(type: 'connect', callback: Callback\<TLSSocketConnection>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：TLSSocketServer;<br>方法or属性：off(type: 'connect', callback?: Callback\<TLSSocketConnection>): void;|@ohos.net.socket.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getIfaceRxBytes(nic: string): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getIfaceTxBytes(nic: string): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getCellularRxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getCellularRxBytes(): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getCellularTxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getCellularTxBytes(): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getAllRxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getAllRxBytes(): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getAllTxBytes(callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getAllTxBytes(): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getUidRxBytes(uid: number): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getUidTxBytes(uid: number): Promise\<number>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function on(type: 'netStatsChange', callback: Callback\<{ iface: string, uid?: number }>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function off(type: 'netStatsChange', callback?: Callback\<{ iface: string, uid?: number }>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getTrafficStatsByIface(ifaceInfo: IfaceInfo): Promise\<NetStatsInfo>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void;|@ohos.net.statistics.d.ts|
|新增|NA|类名：statistics;<br>方法or属性：function getTrafficStatsByUid(uidInfo: UidInfo): Promise\<NetStatsInfo>;|@ohos.net.statistics.d.ts|
|新增|NA|类名：IfaceInfo;<br>方法or属性：iface: string;|@ohos.net.statistics.d.ts|
|新增|NA|类名：IfaceInfo;<br>方法or属性：startTime: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：IfaceInfo;<br>方法or属性：endTime: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：UidInfo;<br>方法or属性：ifaceInfo: IfaceInfo;|@ohos.net.statistics.d.ts|
|新增|NA|类名：UidInfo;<br>方法or属性：uid: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：NetStatsInfo;<br>方法or属性：rxBytes: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：NetStatsInfo;<br>方法or属性：txBytes: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：NetStatsInfo;<br>方法or属性：rxPackets: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：NetStatsInfo;<br>方法or属性：txPackets: number;|@ohos.net.statistics.d.ts|
|新增|NA|类名：vpn;<br>方法or属性：function createVpnConnection(context: AbilityContext): VpnConnection;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：setUp(config: VpnConfig, callback: AsyncCallback\<number>): void;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：setUp(config: VpnConfig): Promise\<number>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：protect(socketFd: number, callback: AsyncCallback\<void>): void;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：protect(socketFd: number): Promise\<void>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：destroy(callback: AsyncCallback\<void>): void;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConnection;<br>方法or属性：destroy(): Promise\<void>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：addresses: Array\<LinkAddress>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：routes?: Array\<RouteInfo>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：dnsAddresses?: Array\<string>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：searchDomains?: Array\<string>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：mtu?: number;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：isIPv4Accepted?: boolean;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：isIPv6Accepted?: boolean;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：isLegacy?: boolean;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：isBlocking?: boolean;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：trustedApplications?: Array\<string>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：VpnConfig;<br>方法or属性：blockedApplications?: Array\<string>;|@ohos.net.vpn.d.ts|
|新增|NA|类名：CloseResult;<br>方法or属性：code: number;|@ohos.net.webSocket.d.ts|
|新增|NA|类名：CloseResult;<br>方法or属性：reason: string;|@ohos.net.webSocket.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function registerForegroundDispatch(<br>    elementName: ElementName,<br>    discTech: number[],<br>    callback: AsyncCallback\<TagInfo><br>  ): void;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：tag;<br>方法or属性：function unregisterForegroundDispatch(elementName: ElementName): void;|@ohos.nfc.tag.d.ts|
|新增|NA|类名：omapi;<br>方法or属性：function newSEService(type: 'serviceState', callback: Callback\<ServiceState>): SEService;|@ohos.secureElement.d.ts|
|新增|NA|类名：SEService;<br>方法or属性：getReaders(): Reader[];|@ohos.secureElement.d.ts|
|新增|NA|类名：SEService;<br>方法or属性：isConnected(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|类名：SEService;<br>方法or属性：shutdown(): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：SEService;<br>方法or属性：getVersion(): string;|@ohos.secureElement.d.ts|
|新增|NA|类名：Reader;<br>方法or属性：getName(): string;|@ohos.secureElement.d.ts|
|新增|NA|类名：Reader;<br>方法or属性：isSecureElementPresent(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|类名：Reader;<br>方法or属性：openSession(): Session;|@ohos.secureElement.d.ts|
|新增|NA|类名：Reader;<br>方法or属性：closeSessions(): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：getReader(): Reader;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：getATR(): number[];|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：close(): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：Channel;<br>方法or属性：close(): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：isClosed(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|类名：Channel;<br>方法or属性：isClosed(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：closeChannels(): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：openBasicChannel(aid: number[]): Promise\<Channel>;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：openBasicChannel(aid: number[], callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：openBasicChannel(aid: number[], p2: number): Promise\<Channel>;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：openBasicChannel(aid: number[], p2: number, callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：openLogicalChannel(aid: number[]): Promise\<Channel>;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：openLogicalChannel(aid: number[], callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：openLogicalChannel(aid: number[], p2: number): Promise\<Channel>;|@ohos.secureElement.d.ts|
|新增|NA|类名：Session;<br>方法or属性：openLogicalChannel(aid: number[], p2: number, callback: AsyncCallback\<Channel>): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：Channel;<br>方法or属性：getSession(): Session;|@ohos.secureElement.d.ts|
|新增|NA|类名：Channel;<br>方法or属性：isBasicChannel(): boolean;|@ohos.secureElement.d.ts|
|新增|NA|类名：Channel;<br>方法or属性：getSelectResponse(): number[];|@ohos.secureElement.d.ts|
|新增|NA|类名：Channel;<br>方法or属性：transmit(command: number[]): Promise\<number[]>;|@ohos.secureElement.d.ts|
|新增|NA|类名：Channel;<br>方法or属性：transmit(command: number[], callback: AsyncCallback\<number[]>): void;|@ohos.secureElement.d.ts|
|新增|NA|类名：ServiceState;<br>方法or属性：DISCONNECTED = 0|@ohos.secureElement.d.ts|
|新增|NA|类名：ServiceState;<br>方法or属性：CONNECTED = 1|@ohos.secureElement.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function startScan(): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getScanInfoList(): Array\<WifiScanInfo>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function setScanAlwaysAllowed(isScanAlwaysAllowed: boolean): void;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getScanAlwaysAllowed(): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getIpv6Info(): Ipv6Info;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function isBandTypeSupported(bandType: WifiBandType): boolean;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function get5GChannelList(): Array\<number>;|@ohos.wifiManager.d.ts|
|新增|NA|类名：wifiManager;<br>方法or属性：function getDisconnectedReason(): DisconnectedReason;|@ohos.wifiManager.d.ts|
|新增|NA|类名：DeviceAddressType;<br>方法or属性：RANDOM_DEVICE_ADDRESS|@ohos.wifiManager.d.ts|
|新增|NA|类名：DeviceAddressType;<br>方法or属性：REAL_DEVICE_ADDRESS|@ohos.wifiManager.d.ts|
|新增|NA|类名：DisconnectedReason;<br>方法or属性：DISC_REASON_DEFAULT = 0|@ohos.wifiManager.d.ts|
|新增|NA|类名：DisconnectedReason;<br>方法or属性：DISC_REASON_WRONG_PWD = 1|@ohos.wifiManager.d.ts|
|新增|NA|类名：DisconnectedReason;<br>方法or属性：DISC_REASON_CONNECTION_FULL = 2|@ohos.wifiManager.d.ts|
|新增|NA|类名：ProxyMethod;<br>方法or属性：METHOD_NONE = 0|@ohos.wifiManager.d.ts|
|新增|NA|类名：ProxyMethod;<br>方法or属性：METHOD_AUTO = 1|@ohos.wifiManager.d.ts|
|新增|NA|类名：ProxyMethod;<br>方法or属性：METHOD_MANUAL = 2|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：proxyMethod?: ProxyMethod;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：pacWebAddress?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：serverHostName?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：serverPort?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiProxyConfig;<br>方法or属性：exclusionObjects?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：caCertAlias: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiEapConfig;<br>方法or属性：clientCertAlias: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：bssidType?: DeviceAddressType;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiDeviceConfig;<br>方法or属性：proxyConfig?: WifiProxyConfig;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：bssidType: DeviceAddressType;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiBandType;<br>方法or属性：WIFI_BAND_NONE|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiBandType;<br>方法or属性：WIFI_BAND_2G|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiBandType;<br>方法or属性：WIFI_BAND_5G|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiBandType;<br>方法or属性：WIFI_BAND_6G|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiBandType;<br>方法or属性：WIFI_BAND_60G|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiStandard;<br>方法or属性：WIFI_STANDARD_UNDEFINED|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiStandard;<br>方法or属性：WIFI_STANDARD_11A|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiStandard;<br>方法or属性：WIFI_STANDARD_11B|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiStandard;<br>方法or属性：WIFI_STANDARD_11G|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiStandard;<br>方法or属性：WIFI_STANDARD_11N|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiStandard;<br>方法or属性：WIFI_STANDARD_11AC|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiStandard;<br>方法or属性：WIFI_STANDARD_11AX|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiStandard;<br>方法or属性：WIFI_STANDARD_11AD|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：rxLinkSpeed: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：maxSupportedTxLinkSpeed: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：maxSupportedRxLinkSpeed: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：channelWidth: WifiChannelWidth;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiLinkedInfo;<br>方法or属性：wifiStandard: WifiStandard;|@ohos.wifiManager.d.ts|
|新增|NA|类名：Ipv6Info;<br>方法or属性：linkIpv6Address: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：Ipv6Info;<br>方法or属性：globalIpv6Address: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：Ipv6Info;<br>方法or属性：randomGlobalIpv6Address: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：Ipv6Info;<br>方法or属性：gateway: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：Ipv6Info;<br>方法or属性：netmask: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：Ipv6Info;<br>方法or属性：primaryDNS: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：Ipv6Info;<br>方法or属性：secondDNS: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：HotspotConfig;<br>方法or属性：channel?: number;|@ohos.wifiManager.d.ts|
|新增|NA|类名：HotspotConfig;<br>方法or属性：ipAddress?: string;|@ohos.wifiManager.d.ts|
|新增|NA|类名：StationInfo;<br>方法or属性：macAddressType?: DeviceAddressType;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2pDevice;<br>方法or属性：deviceAddressType?: DeviceAddressType;|@ohos.wifiManager.d.ts|
|新增|NA|类名：WifiP2PConfig;<br>方法or属性：deviceAddressType?: DeviceAddressType;|@ohos.wifiManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：declare bluetoothManager<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：declare bluetoothManager<br>新版本信息：10<br>代替接口：|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function getState(): BluetoothState;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function getState(): BluetoothState;<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access#getState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function getBtConnectionState(): ProfileConnectionState;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function getBtConnectionState(): ProfileConnectionState;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#getProfileConnectionState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function pairDevice(deviceId: string): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function pairDevice(deviceId: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#pairDevice|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function cancelPairedDevice(deviceId: string): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function cancelPairedDevice(deviceId: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#cancelPairedDevice|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceName(deviceId: string): string;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceName(deviceId: string): string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#getRemoteDeviceName|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#getRemoteDeviceClass|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function enableBluetooth(): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function enableBluetooth(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access#enableBluetooth|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function disableBluetooth(): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function disableBluetooth(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access#disableBluetooth|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function getLocalName(): string;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function getLocalName(): string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#getLocalName|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function getPairedDevices(): Array\<string>;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function getPairedDevices(): Array\<string>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#getPairedDevices|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function getProfileConnectionState(profileId: ProfileId): ProfileConnectionState;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function getProfileConnectionState(profileId: ProfileId): ProfileConnectionState;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#getProfileConnectionState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function setDevicePairingConfirmation(device: string, accept: boolean): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function setDevicePairingConfirmation(device: string, accept: boolean): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#setDevicePairingConfirmation|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function setLocalName(name: string): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function setLocalName(name: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#setLocalName|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function setBluetoothScanMode(mode: ScanMode, duration: number): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function setBluetoothScanMode(mode: ScanMode, duration: number): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#setBluetoothScanMode|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function getBluetoothScanMode(): ScanMode;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function getBluetoothScanMode(): ScanMode;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#getBluetoothScanMode|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function startBluetoothDiscovery(): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function startBluetoothDiscovery(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#startBluetoothDiscovery|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function stopBluetoothDiscovery(): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function stopBluetoothDiscovery(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection#stopBluetoothDiscovery|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function on(type: 'bluetoothDeviceFind', callback: Callback\<Array\<string>>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function on(type: 'bluetoothDeviceFind', callback: Callback\<Array\<string>>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.on#event:bluetoothDeviceFind|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function on(type: 'bondStateChange', callback: Callback\<BondStateParam>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function on(type: 'bondStateChange', callback: Callback\<BondStateParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.on#event:bondStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function on(type: 'pinRequired', callback: Callback\<PinRequiredParam>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function on(type: 'pinRequired', callback: Callback\<PinRequiredParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.on#event:pinRequired|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function on(type: 'stateChange', callback: Callback\<BluetoothState>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function on(type: 'stateChange', callback: Callback\<BluetoothState>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.on#event:stateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function on(type: 'sppRead', clientSocket: number, callback: Callback\<ArrayBuffer>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function on(type: 'sppRead', clientSocket: number, callback: Callback\<ArrayBuffer>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket.on#event:sppRead|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function off(type: 'bluetoothDeviceFind', callback?: Callback\<Array\<string>>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function off(type: 'bluetoothDeviceFind', callback?: Callback\<Array\<string>>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.off#event:bluetoothDeviceFind|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function off(type: 'bondStateChange', callback?: Callback\<BondStateParam>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function off(type: 'bondStateChange', callback?: Callback\<BondStateParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.off#event:bondStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function off(type: 'pinRequired', callback?: Callback\<PinRequiredParam>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function off(type: 'pinRequired', callback?: Callback\<PinRequiredParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.off#event:pinRequired|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function off(type: 'stateChange', callback?: Callback\<BluetoothState>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function off(type: 'stateChange', callback?: Callback\<BluetoothState>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.off#event:stateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function off(type: 'sppRead', clientSocket: number, callback?: Callback\<ArrayBuffer>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function off(type: 'sppRead', clientSocket: number, callback?: Callback\<ArrayBuffer>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket.off#event:sppRead|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket#sppListen|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket#sppAccept|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket#sppConnect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function sppCloseServerSocket(socket: number): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function sppCloseServerSocket(socket: number): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket#sppCloseServerSocket|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function sppCloseClientSocket(socket: number): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function sppCloseClientSocket(socket: number): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket#sppCloseClientSocket|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function sppWrite(clientSocket: number, data: ArrayBuffer): void;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function sppWrite(clientSocket: number, data: ArrayBuffer): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket#sppWrite|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：bluetoothManager;<br>方法or属性：function getProfileInstance(<br><br>    profileId: ProfileId<br><br>  ): A2dpSourceProfile \| HandsFreeAudioGatewayProfile \| HidHostProfile \| PanProfile;<br>旧版本信息：|类名：bluetoothManager;<br>方法or属性：function getProfileInstance(<br><br>    profileId: ProfileId<br><br>  ): A2dpSourceProfile \| HandsFreeAudioGatewayProfile \| HidHostProfile \| PanProfile;<br>新版本信息：10<br>代替接口：|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BaseProfile;<br>方法or属性：interface BaseProfile<br>旧版本信息：|类名：BaseProfile;<br>方法or属性：interface BaseProfile<br>新版本信息：10<br>代替接口： ohos.bluetooth.baseProfile/baseProfile.BaseProfile|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BaseProfile;<br>方法or属性：getConnectionDevices(): Array\<string>;<br>旧版本信息：|类名：BaseProfile;<br>方法or属性：getConnectionDevices(): Array\<string>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.baseProfile/baseProfile#getConnectedDevices|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BaseProfile;<br>方法or属性：getDeviceState(device: string): ProfileConnectionState;<br>旧版本信息：|类名：BaseProfile;<br>方法or属性：getDeviceState(device: string): ProfileConnectionState;<br>新版本信息：10<br>代替接口： ohos.bluetooth.baseProfile/baseProfile#getConnectionState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：interface A2dpSourceProfile<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：interface A2dpSourceProfile<br>新版本信息：10<br>代替接口： ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：connect(device: string): void;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：connect(device: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile#connect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：connect(device: string): void;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：connect(device: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile#connect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HidHostProfile;<br>方法or属性：connect(device: string): void;<br>旧版本信息：|类名：HidHostProfile;<br>方法or属性：connect(device: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.hid/hid.HidHostProfile#connect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：disconnect(device: string): void;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：disconnect(device: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile#disconnect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：disconnect(device: string): void;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：disconnect(device: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile#disconnect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HidHostProfile;<br>方法or属性：disconnect(device: string): void;<br>旧版本信息：|类名：HidHostProfile;<br>方法or属性：disconnect(device: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.hid/hid.HidHostProfile#disconnect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PanProfile;<br>方法or属性：disconnect(device: string): void;<br>旧版本信息：|类名：PanProfile;<br>方法or属性：disconnect(device: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.pan/pan.PanProfile#disconnect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile.on#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile.on#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HidHostProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HidHostProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.hid/hid.HidHostProfile.on#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PanProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：PanProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.pan/pan.PanProfile.on#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile.off#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile.off#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HidHostProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HidHostProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.hid/hid.HidHostProfile.off#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PanProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：PanProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.pan/pan.PanProfile.off#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：A2dpSourceProfile;<br>方法or属性：getPlayingState(device: string): PlayingState;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：getPlayingState(device: string): PlayingState;<br>新版本信息：10<br>代替接口： ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile#getPlayingState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：interface HandsFreeAudioGatewayProfile<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：interface HandsFreeAudioGatewayProfile<br>新版本信息：10<br>代替接口： ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：HidHostProfile;<br>方法or属性：interface HidHostProfile<br>旧版本信息：|类名：HidHostProfile;<br>方法or属性：interface HidHostProfile<br>新版本信息：10<br>代替接口： ohos.bluetooth.hid/hid.HidHostProfile|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PanProfile;<br>方法or属性：interface PanProfile<br>旧版本信息：|类名：PanProfile;<br>方法or属性：interface PanProfile<br>新版本信息：10<br>代替接口： ohos.bluetooth.pan/pan.PanProfile|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PanProfile;<br>方法or属性：setTethering(enable: boolean): void;<br>旧版本信息：|类名：PanProfile;<br>方法or属性：setTethering(enable: boolean): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.pan/pan.PanProfile#setTethering|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PanProfile;<br>方法or属性：isTetheringOn(): boolean;<br>旧版本信息：|类名：PanProfile;<br>方法or属性：isTetheringOn(): boolean;<br>新版本信息：10<br>代替接口： ohos.bluetooth.pan/pan.PanProfile#isTetheringOn|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：BLE<br>旧版本信息：|类名：BLE;<br>方法or属性：BLE<br>新版本信息：10<br>代替接口：|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function createGattServer(): GattServer;<br>旧版本信息：|类名：BLE;<br>方法or属性：function createGattServer(): GattServer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble#createGattServer|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function createGattClientDevice(deviceId: string): GattClientDevice;<br>旧版本信息：|类名：BLE;<br>方法or属性：function createGattClientDevice(deviceId: string): GattClientDevice;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble#createGattClientDevice|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function getConnectedBLEDevices(): Array\<string>;<br>旧版本信息：|类名：BLE;<br>方法or属性：function getConnectedBLEDevices(): Array\<string>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble#getConnectedBLEDevices|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>旧版本信息：|类名：BLE;<br>方法or属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble#startBLEScan|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function stopBLEScan(): void;<br>旧版本信息：|类名：BLE;<br>方法or属性：function stopBLEScan(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble#stopBLEScan|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function on(type: 'BLEDeviceFind', callback: Callback\<Array\<ScanResult>>): void;<br>旧版本信息：|类名：BLE;<br>方法or属性：function on(type: 'BLEDeviceFind', callback: Callback\<Array\<ScanResult>>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.on#event:BLEDeviceFind|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLE;<br>方法or属性：function off(type: 'BLEDeviceFind', callback?: Callback\<Array\<ScanResult>>): void;<br>旧版本信息：|类名：BLE;<br>方法or属性：function off(type: 'BLEDeviceFind', callback?: Callback\<Array\<ScanResult>>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.off#event:BLEDeviceFind|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：interface GattServer<br>旧版本信息：|类名：GattServer;<br>方法or属性：interface GattServer<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble#startAdvertising|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：stopAdvertising(): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：stopAdvertising(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble#stopAdvertising|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：addService(service: GattService): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：addService(service: GattService): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer#addService|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：removeService(serviceUuid: string): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：removeService(serviceUuid: string): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer#removeService|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：close(): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：close(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer#close|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：close(): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：close(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#close|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer#notifyCharacteristicChanged|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：sendResponse(serverResponse: ServerResponse): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：sendResponse(serverResponse: ServerResponse): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer#sendResponse|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: 'characteristicRead', callback: Callback\<CharacteristicReadRequest>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: 'characteristicRead', callback: Callback\<CharacteristicReadRequest>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.on#event:characteristicRead|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: 'characteristicWrite', callback: Callback\<CharacteristicWriteRequest>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: 'characteristicWrite', callback: Callback\<CharacteristicWriteRequest>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.on#event:characteristicWrite|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: 'descriptorRead', callback: Callback\<DescriptorReadRequest>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: 'descriptorRead', callback: Callback\<DescriptorReadRequest>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.on#event:descriptorRead|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteRequest>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteRequest>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.on#event:descriptorWrite|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：on(type: 'connectStateChange', callback: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：on(type: 'connectStateChange', callback: Callback\<BLEConnectChangedState>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.on#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: 'characteristicRead', callback?: Callback\<CharacteristicReadRequest>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: 'characteristicRead', callback?: Callback\<CharacteristicReadRequest>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.off#event:characteristicRead|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: 'characteristicWrite', callback?: Callback\<CharacteristicWriteRequest>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: 'characteristicWrite', callback?: Callback\<CharacteristicWriteRequest>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.off#event:characteristicWrite|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: 'descriptorRead', callback?: Callback\<DescriptorReadRequest>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: 'descriptorRead', callback?: Callback\<DescriptorReadRequest>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.off#event:descriptorRead|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: 'descriptorWrite', callback?: Callback\<DescriptorWriteRequest>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: 'descriptorWrite', callback?: Callback\<DescriptorWriteRequest>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.off#event:descriptorWrite|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattServer;<br>方法or属性：off(type: 'connectStateChange', callback?: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：|类名：GattServer;<br>方法or属性：off(type: 'connectStateChange', callback?: Callback\<BLEConnectChangedState>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattServer.off#event:connectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：interface GattClientDevice<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：interface GattClientDevice<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：connect(): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：connect(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#connect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：disconnect(): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：disconnect(): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#disconnect|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getDeviceName(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getDeviceName(callback: AsyncCallback\<string>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#getDeviceName|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#getDeviceName|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#getServices|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#getServices|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#readCharacteristicValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#readCharacteristicValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#readDescriptorValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#readDescriptorValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：writeCharacteristicValue(characteristic: BLECharacteristic): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：writeCharacteristicValue(characteristic: BLECharacteristic): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#writeCharacteristicValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：writeDescriptorValue(descriptor: BLEDescriptor): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：writeDescriptorValue(descriptor: BLEDescriptor): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#writeDescriptorValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getRssiValue(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getRssiValue(callback: AsyncCallback\<number>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#getRssiValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#getRssiValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：setBLEMtuSize(mtu: number): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：setBLEMtuSize(mtu: number): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#setBLEMtuSize|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice#setCharacteristicChangeNotification|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：on(type: 'BLECharacteristicChange', callback: Callback\<BLECharacteristic>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：on(type: 'BLECharacteristicChange', callback: Callback\<BLECharacteristic>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice.on#event:BLECharacteristicChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：on(type: 'BLEConnectionStateChange', callback: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：on(type: 'BLEConnectionStateChange', callback: Callback\<BLEConnectChangedState>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice.on#event:BLEConnectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：off(type: 'BLECharacteristicChange', callback?: Callback\<BLECharacteristic>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：off(type: 'BLECharacteristicChange', callback?: Callback\<BLECharacteristic>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice.off#event:BLECharacteristicChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattClientDevice;<br>方法or属性：off(type: 'BLEConnectionStateChange', callback?: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：off(type: 'BLEConnectionStateChange', callback?: Callback\<BLEConnectChangedState>): void;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattClientDevice.off#event:BLEConnectionStateChange|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：interface GattService<br>旧版本信息：|类名：GattService;<br>方法or属性：interface GattService<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattService|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：GattService;<br>方法or属性：serviceUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattService#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：serviceUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLECharacteristic#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：serviceUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLEDescriptor#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：serviceUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.NotifyCharacteristic#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicReadRequest;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：CharacteristicReadRequest;<br>方法or属性：serviceUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicReadRequest#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicWriteRequest;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：CharacteristicWriteRequest;<br>方法or属性：serviceUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicWriteRequest#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorReadRequest;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：DescriptorReadRequest;<br>方法or属性：serviceUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorReadRequest#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：serviceUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ServiceData;<br>方法or属性：serviceUuid: string;<br>旧版本信息：|类名：ServiceData;<br>方法or属性：serviceUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ServiceData#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：isPrimary: boolean;<br>旧版本信息：|类名：GattService;<br>方法or属性：isPrimary: boolean;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattService#isPrimary|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：characteristics: Array\<BLECharacteristic>;<br>旧版本信息：|类名：GattService;<br>方法or属性：characteristics: Array\<BLECharacteristic>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattService#characteristics|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：GattService;<br>方法or属性：includeServices?: Array\<GattService>;<br>旧版本信息：|类名：GattService;<br>方法or属性：includeServices?: Array\<GattService>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.GattService#includeServices|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：interface BLECharacteristic<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：interface BLECharacteristic<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLECharacteristic|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：characteristicUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLECharacteristic#characteristicUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：characteristicUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLEDescriptor#characteristicUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：characteristicUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.NotifyCharacteristic#characteristicUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicReadRequest;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：CharacteristicReadRequest;<br>方法or属性：characteristicUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicReadRequest#characteristicUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicWriteRequest;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：CharacteristicWriteRequest;<br>方法or属性：characteristicUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicWriteRequest#characteristicUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorReadRequest;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：DescriptorReadRequest;<br>方法or属性：characteristicUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorReadRequest#characteristicUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：characteristicUuid: string;<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：characteristicUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest#characteristicUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLECharacteristic#characteristicValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：characteristicValue: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.NotifyCharacteristic#characteristicValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLECharacteristic;<br>方法or属性：descriptors: Array\<BLEDescriptor>;<br>旧版本信息：|类名：BLECharacteristic;<br>方法or属性：descriptors: Array\<BLEDescriptor>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLECharacteristic#descriptors|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：interface BLEDescriptor<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：interface BLEDescriptor<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLEDescriptor|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：descriptorUuid: string;<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：descriptorUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLEDescriptor#descriptorUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorReadRequest;<br>方法or属性：descriptorUuid: string;<br>旧版本信息：|类名：DescriptorReadRequest;<br>方法or属性：descriptorUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorReadRequest#descriptorUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：descriptorUuid: string;<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：descriptorUuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest#descriptorUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLEDescriptor;<br>方法or属性：descriptorValue: ArrayBuffer;<br>旧版本信息：|类名：BLEDescriptor;<br>方法or属性：descriptorValue: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLEDescriptor#descriptorValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：interface NotifyCharacteristic<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：interface NotifyCharacteristic<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.NotifyCharacteristic|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：NotifyCharacteristic;<br>方法or属性：confirm: boolean;<br>旧版本信息：|类名：NotifyCharacteristic;<br>方法or属性：confirm: boolean;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.NotifyCharacteristic#confirm|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicReadRequest;<br>方法or属性：interface CharacteristicReadRequest<br>旧版本信息：|类名：CharacteristicReadRequest;<br>方法or属性：interface CharacteristicReadRequest<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicReadRequest|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicReadRequest;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：CharacteristicReadRequest;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicReadRequest#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicWriteRequest;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：CharacteristicWriteRequest;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicWriteRequest#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorReadRequest;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：DescriptorReadRequest;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorReadRequest#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ServerResponse#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLEConnectChangedState;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：BLEConnectChangedState;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLEConnectionChangeState#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanResult;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：ScanResult;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanResult#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PinRequiredParam;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：PinRequiredParam;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.PinRequiredParam#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BondStateParam;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：BondStateParam;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.BondStateParam#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：StateChangeParam;<br>方法or属性：deviceId: string;<br>旧版本信息：|类名：StateChangeParam;<br>方法or属性：deviceId: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.baseProfile/baseProfile.StateChangeParam#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicReadRequest;<br>方法or属性：transId: number;<br>旧版本信息：|类名：CharacteristicReadRequest;<br>方法or属性：transId: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicReadRequest#transId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicWriteRequest;<br>方法or属性：transId: number;<br>旧版本信息：|类名：CharacteristicWriteRequest;<br>方法or属性：transId: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicWriteRequest#transId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorReadRequest;<br>方法or属性：transId: number;<br>旧版本信息：|类名：DescriptorReadRequest;<br>方法or属性：transId: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorReadRequest#transId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：transId: number;<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：transId: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest#transId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：transId: number;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：transId: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ServerResponse#transId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicReadRequest;<br>方法or属性：offset: number;<br>旧版本信息：|类名：CharacteristicReadRequest;<br>方法or属性：offset: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicReadRequest#offset|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicWriteRequest;<br>方法or属性：offset: number;<br>旧版本信息：|类名：CharacteristicWriteRequest;<br>方法or属性：offset: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicWriteRequest#offset|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorReadRequest;<br>方法or属性：offset: number;<br>旧版本信息：|类名：DescriptorReadRequest;<br>方法or属性：offset: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorReadRequest#offset|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：offset: number;<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：offset: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest#offset|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：offset: number;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：offset: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ServerResponse#offset|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicWriteRequest;<br>方法or属性：interface CharacteristicWriteRequest<br>旧版本信息：|类名：CharacteristicWriteRequest;<br>方法or属性：interface CharacteristicWriteRequest<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicWriteRequest|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicWriteRequest;<br>方法or属性：isPrep: boolean;<br>旧版本信息：|类名：CharacteristicWriteRequest;<br>方法or属性：isPrep: boolean;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicWriteRequest#isPrepared|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：isPrep: boolean;<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：isPrep: boolean;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest#isPrepared|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicWriteRequest;<br>方法or属性：needRsp: boolean;<br>旧版本信息：|类名：CharacteristicWriteRequest;<br>方法or属性：needRsp: boolean;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicWriteRequest#needRsp|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：needRsp: boolean;<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：needRsp: boolean;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest#needRsp|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：CharacteristicWriteRequest;<br>方法or属性：value: ArrayBuffer;<br>旧版本信息：|类名：CharacteristicWriteRequest;<br>方法or属性：value: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.CharacteristicWriteRequest#value|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：value: ArrayBuffer;<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：value: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest#value|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：value: ArrayBuffer;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：value: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ServerResponse#value|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorReadRequest;<br>方法or属性：interface DescriptorReadRequest<br>旧版本信息：|类名：DescriptorReadRequest;<br>方法or属性：interface DescriptorReadRequest<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorReadRequest|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DescriptorWriteRequest;<br>方法or属性：interface DescriptorWriteRequest<br>旧版本信息：|类名：DescriptorWriteRequest;<br>方法or属性：interface DescriptorWriteRequest<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.DescriptorWriteRequest|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：interface ServerResponse<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：interface ServerResponse<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ServerResponse|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ServerResponse;<br>方法or属性：status: number;<br>旧版本信息：|类名：ServerResponse;<br>方法or属性：status: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ServerResponse#status|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLEConnectChangedState;<br>方法or属性：interface BLEConnectChangedState<br>旧版本信息：|类名：BLEConnectChangedState;<br>方法or属性：interface BLEConnectChangedState<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLEConnectionChangeState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BLEConnectChangedState;<br>方法or属性：state: ProfileConnectionState;<br>旧版本信息：|类名：BLEConnectChangedState;<br>方法or属性：state: ProfileConnectionState;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.BLEConnectionChangeState#state|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：StateChangeParam;<br>方法or属性：state: ProfileConnectionState;<br>旧版本信息：|类名：StateChangeParam;<br>方法or属性：state: ProfileConnectionState;<br>新版本信息：10<br>代替接口： ohos.bluetooth.baseProfile/baseProfile.StateChangeParam#state|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanResult;<br>方法or属性：interface ScanResult<br>旧版本信息：|类名：ScanResult;<br>方法or属性：interface ScanResult<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanResult|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanResult;<br>方法or属性：rssi: number;<br>旧版本信息：|类名：ScanResult;<br>方法or属性：rssi: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanResult#rssi|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanResult;<br>方法or属性：data: ArrayBuffer;<br>旧版本信息：|类名：ScanResult;<br>方法or属性：data: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanResult#data|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：AdvertiseSetting;<br>方法or属性：interface AdvertiseSetting<br>旧版本信息：|类名：AdvertiseSetting;<br>方法or属性：interface AdvertiseSetting<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.AdvertiseSetting|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：AdvertiseSetting;<br>方法or属性：interval?: number;<br>旧版本信息：|类名：AdvertiseSetting;<br>方法or属性：interval?: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.AdvertiseSetting#interval|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanOptions;<br>方法or属性：interval?: number;<br>旧版本信息：|类名：ScanOptions;<br>方法or属性：interval?: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanOptions#interval|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：AdvertiseSetting;<br>方法or属性：txPower?: number;<br>旧版本信息：|类名：AdvertiseSetting;<br>方法or属性：txPower?: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.AdvertiseSetting#txPower|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：AdvertiseSetting;<br>方法or属性：connectable?: boolean;<br>旧版本信息：|类名：AdvertiseSetting;<br>方法or属性：connectable?: boolean;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.AdvertiseSetting#connectable|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：AdvertiseData;<br>方法or属性：interface AdvertiseData<br>旧版本信息：|类名：AdvertiseData;<br>方法or属性：interface AdvertiseData<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.AdvertiseData|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：AdvertiseData;<br>方法or属性：serviceUuids: Array\<string>;<br>旧版本信息：|类名：AdvertiseData;<br>方法or属性：serviceUuids: Array\<string>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.AdvertiseData#serviceUuids|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：AdvertiseData;<br>方法or属性：manufactureData: Array\<ManufactureData>;<br>旧版本信息：|类名：AdvertiseData;<br>方法or属性：manufactureData: Array\<ManufactureData>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.AdvertiseData#manufactureData|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：AdvertiseData;<br>方法or属性：serviceData: Array\<ServiceData>;<br>旧版本信息：|类名：AdvertiseData;<br>方法or属性：serviceData: Array\<ServiceData>;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.AdvertiseData#serviceData|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ManufactureData;<br>方法or属性：interface ManufactureData<br>旧版本信息：|类名：ManufactureData;<br>方法or属性：interface ManufactureData<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ManufactureData|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ManufactureData;<br>方法or属性：manufactureId: number;<br>旧版本信息：|类名：ManufactureData;<br>方法or属性：manufactureId: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ManufactureData#manufactureId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ManufactureData;<br>方法or属性：manufactureValue: ArrayBuffer;<br>旧版本信息：|类名：ManufactureData;<br>方法or属性：manufactureValue: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ManufactureData#manufactureValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ServiceData;<br>方法or属性：interface ServiceData<br>旧版本信息：|类名：ServiceData;<br>方法or属性：interface ServiceData<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ServiceData|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ServiceData;<br>方法or属性：serviceValue: ArrayBuffer;<br>旧版本信息：|类名：ServiceData;<br>方法or属性：serviceValue: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ServiceData#serviceValue|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：interface ScanFilter<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：interface ScanFilter<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：deviceId?: string;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：deviceId?: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#deviceId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：name?: string;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：name?: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#name|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：serviceUuid?: string;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：serviceUuid?: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#serviceUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：serviceUuidMask?: string;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：serviceUuidMask?: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#serviceUuidMask|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：serviceSolicitationUuid?: string;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：serviceSolicitationUuid?: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#serviceSolicitationUuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：serviceSolicitationUuidMask?: string;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：serviceSolicitationUuidMask?: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#serviceSolicitationUuidMask|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：serviceData?: ArrayBuffer;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：serviceData?: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#serviceData|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：serviceDataMask?: ArrayBuffer;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：serviceDataMask?: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#serviceDataMask|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：manufactureId?: number;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：manufactureId?: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#manufactureId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：manufactureData?: ArrayBuffer;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：manufactureData?: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#manufactureData|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanFilter;<br>方法or属性：manufactureDataMask?: ArrayBuffer;<br>旧版本信息：|类名：ScanFilter;<br>方法or属性：manufactureDataMask?: ArrayBuffer;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanFilter#manufactureDataMask|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanOptions;<br>方法or属性：interface ScanOptions<br>旧版本信息：|类名：ScanOptions;<br>方法or属性：interface ScanOptions<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanOptions|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanOptions;<br>方法or属性：dutyMode?: ScanDuty;<br>旧版本信息：|类名：ScanOptions;<br>方法or属性：dutyMode?: ScanDuty;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanOptions#dutyMode|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanOptions;<br>方法or属性：matchMode?: MatchMode;<br>旧版本信息：|类名：ScanOptions;<br>方法or属性：matchMode?: MatchMode;<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanOptions#matchMode|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：SppOption;<br>方法or属性：interface SppOption<br>旧版本信息：|类名：SppOption;<br>方法or属性：interface SppOption<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket.SppOptions|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：SppOption;<br>方法or属性：uuid: string;<br>旧版本信息：|类名：SppOption;<br>方法or属性：uuid: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket.SppOptions#uuid|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：SppOption;<br>方法or属性：secure: boolean;<br>旧版本信息：|类名：SppOption;<br>方法or属性：secure: boolean;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket.SppOptions#secure|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：SppOption;<br>方法or属性：type: SppType;<br>旧版本信息：|类名：SppOption;<br>方法or属性：type: SppType;<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket.SppOptions#type|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PinRequiredParam;<br>方法or属性：interface PinRequiredParam<br>旧版本信息：|类名：PinRequiredParam;<br>方法or属性：interface PinRequiredParam<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.PinRequiredParam|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PinRequiredParam;<br>方法or属性：pinCode: string;<br>旧版本信息：|类名：PinRequiredParam;<br>方法or属性：pinCode: string;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.PinRequiredParam#pinCode|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DeviceClass;<br>方法or属性：interface DeviceClass<br>旧版本信息：|类名：DeviceClass;<br>方法or属性：interface DeviceClass<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.DeviceClass|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DeviceClass;<br>方法or属性：majorClass: MajorClass;<br>旧版本信息：|类名：DeviceClass;<br>方法or属性：majorClass: MajorClass;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.DeviceClass#majorClass|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DeviceClass;<br>方法or属性：majorMinorClass: MajorMinorClass;<br>旧版本信息：|类名：DeviceClass;<br>方法or属性：majorMinorClass: MajorMinorClass;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.DeviceClass#majorMinorClass|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：DeviceClass;<br>方法or属性：classOfDevice: number;<br>旧版本信息：|类名：DeviceClass;<br>方法or属性：classOfDevice: number;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.DeviceClass#classOfDevice|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BondStateParam;<br>方法or属性：interface BondStateParam<br>旧版本信息：|类名：BondStateParam;<br>方法or属性：interface BondStateParam<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.BondStateParam|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BondStateParam;<br>方法or属性：state: BondState;<br>旧版本信息：|类名：BondStateParam;<br>方法or属性：state: BondState;<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.BondStateParam#state|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：StateChangeParam;<br>方法or属性：interface StateChangeParam<br>旧版本信息：|类名：StateChangeParam;<br>方法or属性：interface StateChangeParam<br>新版本信息：10<br>代替接口： ohos.bluetooth.baseProfile/baseProfile.StateChangeParam|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanDuty;<br>方法or属性：enum ScanDuty<br>旧版本信息：|类名：ScanDuty;<br>方法or属性：enum ScanDuty<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanDuty|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_POWER = 0<br>旧版本信息：|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_POWER = 0<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanDuty#SCAN_MODE_LOW_POWER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanDuty;<br>方法or属性：SCAN_MODE_BALANCED = 1<br>旧版本信息：|类名：ScanDuty;<br>方法or属性：SCAN_MODE_BALANCED = 1<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanDuty#SCAN_MODE_BALANCED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_LATENCY = 2<br>旧版本信息：|类名：ScanDuty;<br>方法or属性：SCAN_MODE_LOW_LATENCY = 2<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.ScanDuty#SCAN_MODE_LOW_LATENCY|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MatchMode;<br>方法or属性：enum MatchMode<br>旧版本信息：|类名：MatchMode;<br>方法or属性：enum MatchMode<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.MatchMode|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MatchMode;<br>方法or属性：MATCH_MODE_AGGRESSIVE = 1<br>旧版本信息：|类名：MatchMode;<br>方法or属性：MATCH_MODE_AGGRESSIVE = 1<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.MatchMode#MATCH_MODE_AGGRESSIVE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MatchMode;<br>方法or属性：MATCH_MODE_STICKY = 2<br>旧版本信息：|类名：MatchMode;<br>方法or属性：MATCH_MODE_STICKY = 2<br>新版本信息：10<br>代替接口： ohos.bluetooth.ble/ble.MatchMode#MATCH_MODE_STICKY|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：enum ProfileConnectionState<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：enum ProfileConnectionState<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileConnectionState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTED = 0<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTED = 0<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileConnectionState#STATE_DISCONNECTED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTING = 1<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTING = 1<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileConnectionState#STATE_CONNECTING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTED = 2<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：STATE_CONNECTED = 2<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileConnectionState#STATE_CONNECTED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTING = 3<br>旧版本信息：|类名：ProfileConnectionState;<br>方法or属性：STATE_DISCONNECTING = 3<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileConnectionState#STATE_DISCONNECTING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：enum BluetoothState<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：enum BluetoothState<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.BluetoothState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_OFF = 0<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_OFF = 0<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.BluetoothState#STATE_OFF|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_TURNING_ON = 1<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_TURNING_ON = 1<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.BluetoothState#STATE_TURNING_ON|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_ON = 2<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_ON = 2<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.BluetoothState#STATE_ON|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_TURNING_OFF = 3<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_TURNING_OFF = 3<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.BluetoothState#STATE_TURNING_OFF|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_ON = 4<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_ON = 4<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.BluetoothState#STATE_BLE_TURNING_ON|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_BLE_ON = 5<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_BLE_ON = 5<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.BluetoothState#STATE_BLE_ON|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_OFF = 6<br>旧版本信息：|类名：BluetoothState;<br>方法or属性：STATE_BLE_TURNING_OFF = 6<br>新版本信息：10<br>代替接口： ohos.bluetooth.access/access.BluetoothState#STATE_BLE_TURNING_OFF|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：SppType;<br>方法or属性：enum SppType<br>旧版本信息：|类名：SppType;<br>方法or属性：enum SppType<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket.SppType|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：SppType;<br>方法or属性：SPP_RFCOMM<br>旧版本信息：|类名：SppType;<br>方法or属性：SPP_RFCOMM<br>新版本信息：10<br>代替接口： ohos.bluetooth.socket/socket.SppType#SPP_RFCOMM|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：enum ScanMode<br>旧版本信息：|类名：ScanMode;<br>方法or属性：enum ScanMode<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.ScanMode|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_NONE = 0<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_NONE = 0<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_NONE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE = 1<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE = 1<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_CONNECTABLE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_GENERAL_DISCOVERABLE = 2<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_GENERAL_DISCOVERABLE = 2<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_GENERAL_DISCOVERABLE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_LIMITED_DISCOVERABLE = 3<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_LIMITED_DISCOVERABLE = 3<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_LIMITED_DISCOVERABLE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE = 4<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5<br>旧版本信息：|类名：ScanMode;<br>方法or属性：SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE = 5<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BondState;<br>方法or属性：enum BondState<br>旧版本信息：|类名：BondState;<br>方法or属性：enum BondState<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.BondState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BondState;<br>方法or属性：BOND_STATE_INVALID = 0<br>旧版本信息：|类名：BondState;<br>方法or属性：BOND_STATE_INVALID = 0<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.BondState#BOND_STATE_INVALID|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BondState;<br>方法or属性：BOND_STATE_BONDING = 1<br>旧版本信息：|类名：BondState;<br>方法or属性：BOND_STATE_BONDING = 1<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.BondState#BOND_STATE_BONDING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：BondState;<br>方法or属性：BOND_STATE_BONDED = 2<br>旧版本信息：|类名：BondState;<br>方法or属性：BOND_STATE_BONDED = 2<br>新版本信息：10<br>代替接口： ohos.bluetooth.connection/connection.BondState#BOND_STATE_BONDED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：enum MajorClass<br>旧版本信息：|类名：MajorClass;<br>方法or属性：enum MajorClass<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_MISC = 0x0000<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_MISC = 0x0000<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_MISC|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_COMPUTER = 0x0100<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_COMPUTER = 0x0100<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_COMPUTER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_PHONE = 0x0200<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_PHONE = 0x0200<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_PHONE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_NETWORKING = 0x0300<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_NETWORKING = 0x0300<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_NETWORKING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_AUDIO_VIDEO = 0x0400<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_AUDIO_VIDEO = 0x0400<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_AUDIO_VIDEO|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_PERIPHERAL = 0x0500<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_PERIPHERAL = 0x0500<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_PERIPHERAL|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_IMAGING = 0x0600<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_IMAGING = 0x0600<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_IMAGING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_WEARABLE = 0x0700<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_WEARABLE = 0x0700<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_WEARABLE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_TOY = 0x0800<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_TOY = 0x0800<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_TOY|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_HEALTH = 0x0900<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_HEALTH = 0x0900<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_HEALTH|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorClass;<br>方法or属性：MAJOR_UNCATEGORIZED = 0x1F00<br>旧版本信息：|类名：MajorClass;<br>方法or属性：MAJOR_UNCATEGORIZED = 0x1F00<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorClass#MAJOR_UNCATEGORIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：enum MajorMinorClass<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：enum MajorMinorClass<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_UNCATEGORIZED = 0x0100<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_UNCATEGORIZED = 0x0100<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_UNCATEGORIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_DESKTOP = 0x0104<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_DESKTOP = 0x0104<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_DESKTOP|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_SERVER = 0x0108<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_SERVER = 0x0108<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_SERVER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_LAPTOP = 0x010C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_LAPTOP = 0x010C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_LAPTOP|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_HANDHELD_PC_PDA = 0x0110<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_HANDHELD_PC_PDA = 0x0110<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_HANDHELD_PC_PDA|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_PALM_SIZE_PC_PDA = 0x0114<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_PALM_SIZE_PC_PDA = 0x0114<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_PALM_SIZE_PC_PDA|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_WEARABLE = 0x0118<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_WEARABLE = 0x0118<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_WEARABLE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：COMPUTER_TABLET = 0x011C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：COMPUTER_TABLET = 0x011C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_TABLET|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_UNCATEGORIZED = 0x0200<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_UNCATEGORIZED = 0x0200<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_UNCATEGORIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_CELLULAR = 0x0204<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_CELLULAR = 0x0204<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_CELLULAR|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_CORDLESS = 0x0208<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_CORDLESS = 0x0208<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_CORDLESS|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_SMART = 0x020C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_SMART = 0x020C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_SMART|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_MODEM_OR_GATEWAY = 0x0210<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_MODEM_OR_GATEWAY = 0x0210<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_MODEM_OR_GATEWAY|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PHONE_ISDN = 0x0214<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PHONE_ISDN = 0x0214<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_ISDN|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_FULLY_AVAILABLE = 0x0300<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_FULLY_AVAILABLE = 0x0300<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_FULLY_AVAILABLE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_1_TO_17_UTILIZED = 0x0320<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_1_TO_17_UTILIZED = 0x0320<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_1_TO_17_UTILIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_17_TO_33_UTILIZED = 0x0340<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_17_TO_33_UTILIZED = 0x0340<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_17_TO_33_UTILIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_33_TO_50_UTILIZED = 0x0360<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_33_TO_50_UTILIZED = 0x0360<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_33_TO_50_UTILIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_60_TO_67_UTILIZED = 0x0380<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_60_TO_67_UTILIZED = 0x0380<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_60_TO_67_UTILIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_67_TO_83_UTILIZED = 0x03A0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_67_TO_83_UTILIZED = 0x03A0<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_67_TO_83_UTILIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_83_TO_99_UTILIZED = 0x03C0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_83_TO_99_UTILIZED = 0x03C0<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_83_TO_99_UTILIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：NETWORK_NO_SERVICE = 0x03E0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：NETWORK_NO_SERVICE = 0x03E0<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_NO_SERVICE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_UNCATEGORIZED = 0x0400<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_UNCATEGORIZED = 0x0400<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_UNCATEGORIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_WEARABLE_HEADSET = 0x0404<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_WEARABLE_HEADSET|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HANDSFREE = 0x0408<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HANDSFREE = 0x0408<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_HANDSFREE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_MICROPHONE = 0x0410<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_MICROPHONE = 0x0410<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_MICROPHONE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_LOUDSPEAKER = 0x0414<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_LOUDSPEAKER = 0x0414<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_LOUDSPEAKER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HEADPHONES = 0x0418<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HEADPHONES = 0x0418<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_HEADPHONES|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_PORTABLE_AUDIO = 0x041C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_PORTABLE_AUDIO|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAR_AUDIO = 0x0420<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAR_AUDIO = 0x0420<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_CAR_AUDIO|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_SET_TOP_BOX = 0x0424<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_SET_TOP_BOX = 0x0424<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_SET_TOP_BOX|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HIFI_AUDIO = 0x0428<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_HIFI_AUDIO = 0x0428<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_HIFI_AUDIO|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VCR = 0x042C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VCR = 0x042C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VCR|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CAMERA = 0x0430<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CAMERA = 0x0430<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_CAMERA|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAMCORDER = 0x0434<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_CAMCORDER = 0x0434<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_CAMCORDER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_MONITOR = 0x0438<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_MONITOR = 0x0438<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_MONITOR|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER = 0x043C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_CONFERENCING = 0x0440<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_CONFERENCING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：AUDIO_VIDEO_VIDEO_GAMING_TOY = 0x0448<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_GAMING_TOY|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_NON_KEYBOARD_NON_POINTING = 0x0500<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_NON_KEYBOARD_NON_POINTING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD = 0x0540<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD = 0x0540<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_KEYBOARD|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_POINTING_DEVICE = 0x0580<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_POINTING_DEVICE = 0x0580<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_POINTING_DEVICE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD_POINTING = 0x05C0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_KEYBOARD_POINTING = 0x05C0<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_KEYBOARD_POINTING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_UNCATEGORIZED = 0x0500<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_UNCATEGORIZED = 0x0500<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_UNCATEGORIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_JOYSTICK = 0x0504<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_JOYSTICK = 0x0504<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_JOYSTICK|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GAMEPAD = 0x0508<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GAMEPAD = 0x0508<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_GAMEPAD|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_REMOTE_CONTROL = 0x05C0<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_REMOTE_CONTROL = 0x05C0<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_REMOTE_CONTROL|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SENSING_DEVICE = 0x0510<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SENSING_DEVICE = 0x0510<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_SENSING_DEVICE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITIZER_TABLET = 0x0514<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITIZER_TABLET = 0x0514<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_DIGITIZER_TABLET|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_CARD_READER = 0x0518<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_CARD_READER = 0x0518<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_CARD_READER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITAL_PEN = 0x051C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_DIGITAL_PEN = 0x051C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_DIGITAL_PEN|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SCANNER_RFID = 0x0520<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_SCANNER_RFID = 0x0520<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_SCANNER_RFID|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GESTURAL_INPUT = 0x0522<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：PERIPHERAL_GESTURAL_INPUT = 0x0522<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_GESTURAL_INPUT|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_UNCATEGORIZED = 0x0600<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_UNCATEGORIZED = 0x0600<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_UNCATEGORIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_DISPLAY = 0x0610<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_DISPLAY = 0x0610<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_DISPLAY|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_CAMERA = 0x0620<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_CAMERA = 0x0620<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_CAMERA|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_SCANNER = 0x0640<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_SCANNER = 0x0640<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_SCANNER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：IMAGING_PRINTER = 0x0680<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：IMAGING_PRINTER = 0x0680<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_PRINTER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_UNCATEGORIZED = 0x0700<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_UNCATEGORIZED = 0x0700<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_UNCATEGORIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_WRIST_WATCH = 0x0704<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_WRIST_WATCH = 0x0704<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_WRIST_WATCH|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_PAGER = 0x0708<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_PAGER = 0x0708<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_PAGER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_JACKET = 0x070C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_JACKET = 0x070C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_JACKET|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_HELMET = 0x0710<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_HELMET = 0x0710<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_HELMET|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：WEARABLE_GLASSES = 0x0714<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：WEARABLE_GLASSES = 0x0714<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_GLASSES|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_UNCATEGORIZED = 0x0800<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_UNCATEGORIZED = 0x0800<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#TOY_UNCATEGORIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_ROBOT = 0x0804<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_ROBOT = 0x0804<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#TOY_ROBOT|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_VEHICLE = 0x0808<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_VEHICLE = 0x0808<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#TOY_VEHICLE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_DOLL_ACTION_FIGURE = 0x080C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_DOLL_ACTION_FIGURE = 0x080C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#TOY_DOLL_ACTION_FIGURE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_CONTROLLER = 0x0810<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_CONTROLLER = 0x0810<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#TOY_CONTROLLER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：TOY_GAME = 0x0814<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：TOY_GAME = 0x0814<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#TOY_GAME|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_UNCATEGORIZED = 0x0900<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_UNCATEGORIZED = 0x0900<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_UNCATEGORIZED|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_BLOOD_PRESSURE = 0x0904<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_BLOOD_PRESSURE = 0x0904<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_BLOOD_PRESSURE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_THERMOMETER = 0x0908<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_THERMOMETER = 0x0908<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_THERMOMETER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_WEIGHING = 0x090C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_WEIGHING = 0x090C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_WEIGHING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_GLUCOSE = 0x0910<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_GLUCOSE = 0x0910<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_GLUCOSE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_OXIMETER = 0x0914<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_OXIMETER = 0x0914<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_PULSE_OXIMETER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_RATE = 0x0918<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_PULSE_RATE = 0x0918<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_PULSE_RATE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_DATA_DISPLAY = 0x091C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_DATA_DISPLAY = 0x091C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_DATA_DISPLAY|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_STEP_COUNTER = 0x0920<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_STEP_COUNTER = 0x0920<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_STEP_COUNTER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_BODY_COMPOSITION_ANALYZER = 0x0924<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_BODY_COMPOSITION_ANALYZER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_PEAK_FLOW_MONITOR = 0x0928<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_PEAK_FLOW_MONITOR = 0x0928<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_PEAK_FLOW_MONITOR|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_MEDICATION_MONITOR = 0x092C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_MEDICATION_MONITOR = 0x092C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_MEDICATION_MONITOR|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_KNEE_PROSTHESIS = 0x0930<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_KNEE_PROSTHESIS = 0x0930<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_KNEE_PROSTHESIS|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_ANKLE_PROSTHESIS = 0x0934<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_ANKLE_PROSTHESIS = 0x0934<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_ANKLE_PROSTHESIS|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_GENERIC_HEALTH_MANAGER = 0x0938<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_GENERIC_HEALTH_MANAGER = 0x0938<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_GENERIC_HEALTH_MANAGER|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：MajorMinorClass;<br>方法or属性：HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C<br>旧版本信息：|类名：MajorMinorClass;<br>方法or属性：HEALTH_PERSONAL_MOBILITY_DEVICE = 0x093C<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_PERSONAL_MOBILITY_DEVICE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PlayingState;<br>方法or属性：enum PlayingState<br>旧版本信息：|类名：PlayingState;<br>方法or属性：enum PlayingState<br>新版本信息：10<br>代替接口： ohos.bluetooth.a2dp/a2dp.PlayingState|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PlayingState;<br>方法or属性：STATE_NOT_PLAYING<br>旧版本信息：|类名：PlayingState;<br>方法or属性：STATE_NOT_PLAYING<br>新版本信息：10<br>代替接口： ohos.bluetooth.a2dp/a2dp.PlayingState#STATE_NOT_PLAYING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：PlayingState;<br>方法or属性：STATE_PLAYING<br>旧版本信息：|类名：PlayingState;<br>方法or属性：STATE_PLAYING<br>新版本信息：10<br>代替接口： ohos.bluetooth.a2dp/a2dp.PlayingState#STATE_PLAYING|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileId;<br>方法or属性：enum ProfileId<br>旧版本信息：|类名：ProfileId;<br>方法or属性：enum ProfileId<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileId|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileId;<br>方法or属性：PROFILE_A2DP_SOURCE = 1<br>旧版本信息：|类名：ProfileId;<br>方法or属性：PROFILE_A2DP_SOURCE = 1<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileId#PROFILE_A2DP_SOURCE|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileId;<br>方法or属性：PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4<br>旧版本信息：|类名：ProfileId;<br>方法or属性：PROFILE_HANDS_FREE_AUDIO_GATEWAY = 4<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileId#PROFILE_HANDSFREE_AUDIO_GATEWAY|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileId;<br>方法or属性：PROFILE_HID_HOST = 6<br>旧版本信息：|类名：ProfileId;<br>方法or属性：PROFILE_HID_HOST = 6<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileId#PROFILE_HID_HOST|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：ProfileId;<br>方法or属性：PROFILE_PAN_NETWORK = 7<br>旧版本信息：|类名：ProfileId;<br>方法or属性：PROFILE_PAN_NETWORK = 7<br>新版本信息：10<br>代替接口： ohos.bluetooth.constant/constant.ProfileId#PROFILE_PAN_NETWORK|@ohos.bluetoothManager.d.ts|
|废弃版本有变化|类名：connectedTag;<br>方法or属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.connectedTag/connectedTag#read|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： ohos.connectedTag/connectedTag#write|@ohos.connectedTag.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getScanInfoList|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.addDeviceConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.addCandidateConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.removeCandidateConfig|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getP2pLinkedInfo|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getCurrentGroup|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifi;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManager/wifiManager.getP2pPeerDevices|@ohos.wifi.d.ts|
|废弃版本有变化|类名：wifiext;<br>方法or属性：function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.getSupportedPowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiext;<br>方法or属性：function getPowerModel(callback: AsyncCallback\<PowerModel>): void;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function getPowerModel(callback: AsyncCallback\<PowerModel>): void;<br>新版本信息：9<br>代替接口： ohos.wifiManagerExt/wifiManagerExt.getPowerMode|@ohos.wifiext.d.ts|
|废弃版本有变化|类名：wifiManager;<br>方法or属性：function scan(): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function scan(): void;<br>新版本信息：10<br>代替接口： wifiManager.startScan|@ohos.wifiManager.d.ts|
|废弃版本有变化|类名：wifiManager;<br>方法or属性：function getScanResults(): Promise\<Array\<WifiScanInfo>>;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getScanResults(): Promise\<Array\<WifiScanInfo>>;<br>新版本信息：10<br>代替接口： wifiManager.getScanInfoList|@ohos.wifiManager.d.ts|
|废弃版本有变化|类名：wifiManager;<br>方法or属性：function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>新版本信息：10<br>代替接口： wifiManager.getScanInfoList|@ohos.wifiManager.d.ts|
|废弃版本有变化|类名：wifiManager;<br>方法or属性：function getScanResultsSync(): Array\<WifiScanInfo>;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getScanResultsSync(): Array\<WifiScanInfo>;<br>新版本信息：10<br>代替接口： wifiManager.getScanInfoList|@ohos.wifiManager.d.ts|
|废弃版本有变化|类名：wifiManagerExt;<br>方法or属性：function enableHotspot(): void;<br>旧版本信息：|类名：wifiManagerExt;<br>方法or属性：function enableHotspot(): void;<br>新版本信息：10<br>代替接口：|@ohos.wifiManagerExt.d.ts|
|废弃版本有变化|类名：wifiManagerExt;<br>方法or属性：function disableHotspot(): void;<br>旧版本信息：|类名：wifiManagerExt;<br>方法or属性：function disableHotspot(): void;<br>新版本信息：10<br>代替接口：|@ohos.wifiManagerExt.d.ts|
|废弃版本有变化|类名：wifiManagerExt;<br>方法or属性：function setPowerMode(mode: PowerMode): void;<br>旧版本信息：|类名：wifiManagerExt;<br>方法or属性：function setPowerMode(mode: PowerMode): void;<br>新版本信息：10<br>代替接口：|@ohos.wifiManagerExt.d.ts|
|废弃版本有变化|类名：TagSession;<br>方法or属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：TagSession;<br>方法or属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>新版本信息：9<br>代替接口： tagSession.TagSession#transmit|tagSession.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>新版本信息：201,401,801,2900001,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>新版本信息：201,401,801,2900001,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>新版本信息：201,401,801,2900001,2901000,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>新版本信息：201,401,801,2900001,2901000,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>新版本信息：201,401,801,2900099|@ohos.bluetoothManager.d.ts|
|新增(错误码)|类名：connectedTag;<br>方法or属性：function read(callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function read(callback: AsyncCallback\<number[]>): void;<br>新版本信息：201,801,3200101|@ohos.connectedTag.d.ts|
|新增(错误码)|类名：connectedTag;<br>方法or属性：function write(data: number[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function write(data: number[], callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,801,3200101|@ohos.connectedTag.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>新版本信息：201,202,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>新版本信息：201,202,401,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetHandle;<br>方法or属性：bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：bindSocket(socketParam: TCPSocket \| UDPSocket): Promise\<void>;<br>新版本信息：401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：NetHandle;<br>方法or属性：getAddressByName(host: string): Promise\<NetAddress>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressByName(host: string): Promise\<NetAddress>;<br>新版本信息：201,401,2100001,2100002,2100003|@ohos.net.connection.d.ts|
|新增(错误码)|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201005|@ohos.net.ethernet.d.ts|
|新增(错误码)|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201004,2201005,2201006,2201007|@ohos.net.ethernet.d.ts|
|新增(错误码)|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201005|@ohos.net.ethernet.d.ts|
|新增(错误码)|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>新版本信息：201,202,2200002,2200003|@ohos.net.ethernet.d.ts|
|新增(错误码)|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>新版本信息：401,201,2300001,2300003,2300005,2300006,2300007,2300008,2300009,2300016,2300018,2300023,2300025,2300026,2300027,2300028,2300047,2300052,2300055,2300056,2300058,2300059,2300060,2300061,2300063,2300070,2300073,2300077,2300078,2300094,2300999|@ohos.net.http.d.ts|
|新增(错误码)|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>新版本信息：401,201,2300001,2300003,2300005,2300006,2300007,2300008,2300009,2300016,2300018,2300023,2300025,2300026,2300027,2300028,2300047,2300052,2300055,2300056,2300058,2300059,2300060,2300061,2300063,2300070,2300073,2300077,2300078,2300094,2300999|@ohos.net.http.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>新版本信息：201,202,2200002,2200003,2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>新版本信息：201,202,2200002,2200003,2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2202004,2202005,2202006,2202009,2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：201,202,401,2200001,2200002,2200003,2202004,2202005,2202006,2202011|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：401,201,2303198,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：401,2303501,2303505,2303506,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：2303188,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>新版本信息：201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>新版本信息：2303188,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>新版本信息：401,201|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>新版本信息：401,2303188,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;<br>新版本信息：2303501,2303504,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;<br>新版本信息：2303501,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getProtocol(): Promise\<string>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getProtocol(): Promise\<string>;<br>新版本信息：2303501,2303505,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;<br>新版本信息：2303501,2303502,2303505,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;<br>新版本信息：2303501,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions): Promise\<void>;<br>新版本信息：401,2303104,2303109,2303111,2303188,2303191,2303198,2303199,2303210,2303501,2303502,2303503,2303505,2303506,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：TLSSocket;<br>方法or属性：send(data: string): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：send(data: string): Promise\<void>;<br>新版本信息：401,2303501,2303503,2303505,2303506,2300002|@ohos.net.socket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>新版本信息：401,201|@ohos.net.webSocket.d.ts|
|新增(错误码)|类名：HceService;<br>方法or属性：transmit(response: number[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：HceService;<br>方法or属性：transmit(response: number[], callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,801,3100301|@ohos.nfc.cardEmulation.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>新版本信息：201,801,2501000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,801,2501000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：201,401,801,2501000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,801,2501000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>新版本信息：201,202,801,2501000,2501001|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>新版本信息：201,801,2801000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>新版本信息：201,801,2801000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>新版本信息：201,801,2801000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>新版本信息：201,801,2801000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>新版本信息：201,202,801,2801000|@ohos.wifiManager.d.ts|
|新增(错误码)|类名：wifiManagerExt;<br>方法or属性：function getSupportedPowerMode(callback: AsyncCallback\<Array\<PowerMode>>): void;<br>旧版本信息：|类名：wifiManagerExt;<br>方法or属性：function getSupportedPowerMode(callback: AsyncCallback\<Array\<PowerMode>>): void;<br>新版本信息：201,801,2701000|@ohos.wifiManagerExt.d.ts|
|新增(错误码)|类名：wifiManagerExt;<br>方法or属性：function getPowerMode(callback: AsyncCallback\<PowerMode>): void;<br>旧版本信息：|类名：wifiManagerExt;<br>方法or属性：function getPowerMode(callback: AsyncCallback\<PowerMode>): void;<br>新版本信息：201,801,2701000|@ohos.wifiManagerExt.d.ts|
|新增(错误码)|类名：IsoDepTag;<br>方法or属性：isExtendedApduSupported(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：IsoDepTag;<br>方法or属性：isExtendedApduSupported(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：NdefTag;<br>方法or属性：readNdef(callback: AsyncCallback\<NdefMessage>): void;<br>旧版本信息：|类名：NdefTag;<br>方法or属性：readNdef(callback: AsyncCallback\<NdefMessage>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：NdefTag;<br>方法or属性：writeNdef(msg: NdefMessage, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NdefTag;<br>方法or属性：writeNdef(msg: NdefMessage, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：NdefTag;<br>方法or属性：setReadOnly(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NdefTag;<br>方法or属性：setReadOnly(callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：MifareClassicTag;<br>方法or属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：MifareClassicTag;<br>方法or属性：readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：MifareClassicTag;<br>方法or属性：writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：MifareClassicTag;<br>方法or属性：incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：MifareClassicTag;<br>方法or属性：decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：MifareClassicTag;<br>方法or属性：transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：MifareClassicTag;<br>方法or属性：restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：MifareUltralightTag;<br>方法or属性：readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：MifareUltralightTag;<br>方法or属性：readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：MifareUltralightTag;<br>方法or属性：writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareUltralightTag;<br>方法or属性：writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：NdefFormatableTag;<br>方法or属性：format(message: NdefMessage, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NdefFormatableTag;<br>方法or属性：format(message: NdefMessage, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：NdefFormatableTag;<br>方法or属性：formatReadOnly(message: NdefMessage, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NdefFormatableTag;<br>方法or属性：formatReadOnly(message: NdefMessage, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,3100201|nfctech.d.ts|
|新增(错误码)|类名：TagSession;<br>方法or属性：transmit(data: number[], callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：TagSession;<br>方法or属性：transmit(data: number[], callback: AsyncCallback\<number[]>): void;<br>新版本信息：201,401,801,3100201|tagSession.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function getDefaultNet(callback: AsyncCallback\<NetHandle>): void;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getDefaultNetSync(): NetHandle;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function getDefaultNetSync(): NetHandle;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function getAllNets(callback: AsyncCallback\<Array\<NetHandle>>): void;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function isDefaultNetMetered(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function isDefaultNetMetered(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function enableAirplaneMode(callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>旧版本信息：201,2100002,2100003|类名：connection;<br>方法or属性：function disableAirplaneMode(callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getAppNet(callback: AsyncCallback\<NetHandle>): void;<br>旧版本信息：2100002,2100003|类名：connection;<br>方法or属性：function getAppNet(callback: AsyncCallback\<NetHandle>): void;<br>新版本信息：401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：connection;<br>方法or属性：function getAppNet(): Promise\<NetHandle>;<br>旧版本信息：2100002,2100003|类名：connection;<br>方法or属性：function getAppNet(): Promise\<NetHandle>;<br>新版本信息：401,2100002,2100003|@ohos.net.connection.d.ts|
|错误码有变化|类名：NetConnection;<br>方法or属性：register(callback: AsyncCallback\<void>): void;<br>旧版本信息：201,2100002,2100003,2101008,2101022|类名：NetConnection;<br>方法or属性：register(callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,2100002,2100003,2101008,2101022|@ohos.net.connection.d.ts|
|错误码有变化|类名：NetConnection;<br>方法or属性：unregister(callback: AsyncCallback\<void>): void;<br>旧版本信息：2100002,2100003,2101007|类名：NetConnection;<br>方法or属性：unregister(callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,2100002,2100003,2101007|@ohos.net.connection.d.ts|
|错误码有变化|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2201005|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string, callback: AsyncCallback\<InterfaceConfiguration>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201005|@ohos.net.ethernet.d.ts|
|错误码有变化|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2201004,2201005,2201006,2201007|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201004,2201005,2201006,2201007|@ohos.net.ethernet.d.ts|
|错误码有变化|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string, callback: AsyncCallback\<number>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2201005|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string, callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2201005|@ohos.net.ethernet.d.ts|
|错误码有变化|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：201,2200002,2200003|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：201,202,2200002,2200003|@ohos.net.ethernet.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function isSharingSupported(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：201,2200002,2200003,2202011|类名：sharing;<br>方法or属性：function isSharingSupported(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,202,2200002,2200003,2202011|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function isSharing(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：201,2200002,2200003,2202011|类名：sharing;<br>方法or属性：function isSharing(callback: AsyncCallback\<boolean>): void;<br>新版本信息：201,202,2200002,2200003,2202011|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2202004,2202005,2202006,2202009,2202011|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2202004,2202005,2202006,2202009,2202011|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,2200001,2200002,2200003,2202004,2202005,2202006,2202011|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003,2202004,2202005,2202006,2202011|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getStatsRxBytes(callback: AsyncCallback\<number>): void;<br>旧版本信息：201,2200002,2200003|类名：sharing;<br>方法or属性：function getStatsRxBytes(callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getStatsTxBytes(callback: AsyncCallback\<number>): void;<br>旧版本信息：201,2200002,2200003|类名：sharing;<br>方法or属性：function getStatsTxBytes(callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getStatsTotalBytes(callback: AsyncCallback\<number>): void;<br>旧版本信息：201,2200002,2200003|类名：sharing;<br>方法or属性：function getStatsTotalBytes(callback: AsyncCallback\<number>): void;<br>新版本信息：201,202,401,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：201,401,2200001,2200002,2200003|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;<br>旧版本信息：201,401,2200001,2200002,2200003|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：201,401,2200001,2200002,2200003|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：201,202,401,2200001,2200002,2200003|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function on(type: 'sharingStateChange', callback: Callback\<boolean>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function on(type: 'sharingStateChange', callback: Callback\<boolean>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function off(type: 'sharingStateChange', callback?: Callback\<boolean>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state: SharingIfaceState }>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：sharing;<br>方法or属性：function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;<br>旧版本信息：201,401|类名：sharing;<br>方法or属性：function off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void;<br>新版本信息：201,202,401|@ohos.net.sharing.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：readException(): void;<br>旧版本信息：Throws|类名：MessageParcel;<br>方法or属性：readException(): void;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeByte(val: number): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeByte(val: number): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeShort(val: number): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeShort(val: number): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeInt(val: number): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeInt(val: number): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeLong(val: number): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeLong(val: number): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeFloat(val: number): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeFloat(val: number): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeDouble(val: number): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeDouble(val: number): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeBoolean(val: boolean): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeBoolean(val: boolean): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeChar(val: number): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeChar(val: number): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeString(val: string): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeString(val: string): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeSequenceable(val: Sequenceable): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeSequenceable(val: Sequenceable): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeByteArray(byteArray: number[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeByteArray(byteArray: number[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeShortArray(shortArray: number[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeShortArray(shortArray: number[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeIntArray(intArray: number[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeIntArray(intArray: number[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeLongArray(longArray: number[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeLongArray(longArray: number[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeFloatArray(floatArray: number[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeFloatArray(floatArray: number[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeDoubleArray(doubleArray: number[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeDoubleArray(doubleArray: number[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeBooleanArray(booleanArray: boolean[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeBooleanArray(booleanArray: boolean[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeCharArray(charArray: number[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeCharArray(charArray: number[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeStringArray(stringArray: string[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeStringArray(stringArray: string[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：readByteArray(dataIn: number[]): void;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：readByteArray(dataIn: number[]): void;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：readIntArray(dataIn: number[]): void;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：readIntArray(dataIn: number[]): void;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：readLongArray(dataIn: number[]): void;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：readLongArray(dataIn: number[]): void;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：readFloatArray(dataIn: number[]): void;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：readFloatArray(dataIn: number[]): void;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：readDoubleArray(dataIn: number[]): void;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：readDoubleArray(dataIn: number[]): void;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：readBooleanArray(dataIn: boolean[]): void;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：readBooleanArray(dataIn: boolean[]): void;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：readCharArray(dataIn: number[]): void;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：readCharArray(dataIn: number[]): void;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageParcel;<br>方法or属性：readStringArray(dataIn: string[]): void;<br>旧版本信息：ParcelException|类名：MessageParcel;<br>方法or属性：readStringArray(dataIn: string[]): void;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：MessageSequence;<br>方法or属性：readStringArray(dataIn: string[]): void;<br>旧版本信息：ParcelException,401,1900010|类名：MessageSequence;<br>方法or属性：readStringArray(dataIn: string[]): void;<br>新版本信息：401,1900010|@ohos.rpc.d.ts|
|错误码有变化|类名：Sequenceable;<br>方法or属性：marshalling(dataOut: MessageParcel): boolean;<br>旧版本信息：ParcelException|类名：Sequenceable;<br>方法or属性：marshalling(dataOut: MessageParcel): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：Sequenceable;<br>方法or属性：unmarshalling(dataIn: MessageParcel): boolean;<br>旧版本信息：ParcelException|类名：Sequenceable;<br>方法or属性：unmarshalling(dataIn: MessageParcel): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：Parcelable;<br>方法or属性：marshalling(dataOut: MessageSequence): boolean;<br>旧版本信息：ParcelException|类名：Parcelable;<br>方法or属性：marshalling(dataOut: MessageSequence): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：Parcelable;<br>方法or属性：unmarshalling(dataIn: MessageSequence): boolean;<br>旧版本信息：ParcelException|类名：Parcelable;<br>方法or属性：unmarshalling(dataIn: MessageSequence): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：IRemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>旧版本信息：RemoteException|类名：IRemoteObject;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：RemoteProxy;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>旧版本信息：RemoteException|类名：RemoteProxy;<br>方法or属性：sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：IRemoteObject;<br>方法or属性：sendRequest(<br><br>      code: number,<br><br>      data: MessageParcel,<br><br>      reply: MessageParcel,<br><br>      options: MessageOption<br><br>    ): Promise\<SendRequestResult>;<br>旧版本信息：Throws|类名：IRemoteObject;<br>方法or属性：sendRequest(<br><br>      code: number,<br><br>      data: MessageParcel,<br><br>      reply: MessageParcel,<br><br>      options: MessageOption<br><br>    ): Promise\<SendRequestResult>;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：RemoteObject;<br>方法or属性：sendRequest(<br><br>      code: number,<br><br>      data: MessageParcel,<br><br>      reply: MessageParcel,<br><br>      options: MessageOption<br><br>    ): Promise\<SendRequestResult>;<br>旧版本信息：Throws|类名：RemoteObject;<br>方法or属性：sendRequest(<br><br>      code: number,<br><br>      data: MessageParcel,<br><br>      reply: MessageParcel,<br><br>      options: MessageOption<br><br>    ): Promise\<SendRequestResult>;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：RemoteProxy;<br>方法or属性：sendRequest(<br><br>      code: number,<br><br>      data: MessageParcel,<br><br>      reply: MessageParcel,<br><br>      options: MessageOption<br><br>    ): Promise\<SendRequestResult>;<br>旧版本信息：Throws|类名：RemoteProxy;<br>方法or属性：sendRequest(<br><br>      code: number,<br><br>      data: MessageParcel,<br><br>      reply: MessageParcel,<br><br>      options: MessageOption<br><br>    ): Promise\<SendRequestResult>;<br>新版本信息：|@ohos.rpc.d.ts|
|错误码有变化|类名：RemoteObject;<br>方法or属性：onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>旧版本信息：RemoteException|类名：RemoteObject;<br>方法or属性：onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean;<br>新版本信息：|@ohos.rpc.d.ts|
|访问级别有变化|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.connection.d.ts|
|访问级别有变化|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.connection.d.ts|
|访问级别有变化|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：mode: IPSetMode;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：mode: IPSetMode;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：ipAddr: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：ipAddr: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：route: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：route: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：gateway: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：gateway: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：netMask: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：netMask: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：InterfaceConfiguration;<br>方法or属性：dnsServers: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：dnsServers: string;<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：IPSetMode;<br>方法or属性：STATIC = 0<br>旧版本信息：|类名：IPSetMode;<br>方法or属性：STATIC = 0<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：IPSetMode;<br>方法or属性：DHCP = 1<br>旧版本信息：|类名：IPSetMode;<br>方法or属性：DHCP = 1<br>新版本信息：systemapi|@ohos.net.ethernet.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_SERVING = 1<br>旧版本信息：|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_SERVING = 1<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_CAN_SERVER = 2<br>旧版本信息：|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_CAN_SERVER = 2<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_ERROR = 3<br>旧版本信息：|类名：SharingIfaceState;<br>方法or属性：SHARING_NIC_ERROR = 3<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceType;<br>方法or属性：SHARING_WIFI = 0<br>旧版本信息：|类名：SharingIfaceType;<br>方法or属性：SHARING_WIFI = 0<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceType;<br>方法or属性：SHARING_USB = 1<br>旧版本信息：|类名：SharingIfaceType;<br>方法or属性：SHARING_USB = 1<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：SharingIfaceType;<br>方法or属性：SHARING_BLUETOOTH = 2<br>旧版本信息：|类名：SharingIfaceType;<br>方法or属性：SHARING_BLUETOOTH = 2<br>新版本信息：systemapi|@ohos.net.sharing.d.ts|
|访问级别有变化|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：ssid: string;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：ssid: string;<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：securityType: WifiSecurityType;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：securityType: WifiSecurityType;<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：band: number;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：band: number;<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：preSharedKey: string;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：preSharedKey: string;<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：maxConn: number;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：maxConn: number;<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：StationInfo;<br>方法or属性：name: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：name: string;<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：StationInfo;<br>方法or属性：macAddress: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：macAddress: string;<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：StationInfo;<br>方法or属性：ipAddress: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：ipAddress: string;<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：IpType;<br>方法or属性：STATIC<br>旧版本信息：|类名：IpType;<br>方法or属性：STATIC<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：IpType;<br>方法or属性：DHCP<br>旧版本信息：|类名：IpType;<br>方法or属性：DHCP<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：IpType;<br>方法or属性：UNKNOWN<br>旧版本信息：|类名：IpType;<br>方法or属性：UNKNOWN<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：DISCONNECTED<br>旧版本信息：|类名：SuppState;<br>方法or属性：DISCONNECTED<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：INTERFACE_DISABLED<br>旧版本信息：|类名：SuppState;<br>方法or属性：INTERFACE_DISABLED<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：INACTIVE<br>旧版本信息：|类名：SuppState;<br>方法or属性：INACTIVE<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：SCANNING<br>旧版本信息：|类名：SuppState;<br>方法or属性：SCANNING<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：AUTHENTICATING<br>旧版本信息：|类名：SuppState;<br>方法or属性：AUTHENTICATING<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：ASSOCIATING<br>旧版本信息：|类名：SuppState;<br>方法or属性：ASSOCIATING<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：ASSOCIATED<br>旧版本信息：|类名：SuppState;<br>方法or属性：ASSOCIATED<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：FOUR_WAY_HANDSHAKE<br>旧版本信息：|类名：SuppState;<br>方法or属性：FOUR_WAY_HANDSHAKE<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：GROUP_HANDSHAKE<br>旧版本信息：|类名：SuppState;<br>方法or属性：GROUP_HANDSHAKE<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：COMPLETED<br>旧版本信息：|类名：SuppState;<br>方法or属性：COMPLETED<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：UNINITIALIZED<br>旧版本信息：|类名：SuppState;<br>方法or属性：UNINITIALIZED<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：INVALID<br>旧版本信息：|类名：SuppState;<br>方法or属性：INVALID<br>新版本信息：systemapi|@ohos.wifi.d.ts|
|访问级别有变化|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：EapMethod;<br>方法or属性：enum EapMethod<br>旧版本信息：systemapi|类名：EapMethod;<br>方法or属性：enum EapMethod<br>新版本信息：|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：Phase2Method;<br>方法or属性：enum Phase2Method<br>旧版本信息：systemapi|类名：Phase2Method;<br>方法or属性：enum Phase2Method<br>新版本信息：|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiEapConfig;<br>方法or属性：interface WifiEapConfig<br>旧版本信息：systemapi|类名：WifiEapConfig;<br>方法or属性：interface WifiEapConfig<br>新版本信息：|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：creatorUid?: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：creatorUid?: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：disableReason?: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：disableReason?: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：netId?: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：netId?: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：randomMacType?: number;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：randomMacType?: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：randomMacAddr?: string;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：randomMacAddr?: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：ipType?: IpType;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：ipType?: IpType;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：staticIp?: IpConfig;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：staticIp?: IpConfig;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiDeviceConfig;<br>方法or属性：eapConfig?: WifiEapConfig;<br>旧版本信息：systemapi|类名：WifiDeviceConfig;<br>方法or属性：eapConfig?: WifiEapConfig;<br>新版本信息：|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：ipAddress: number;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：ipAddress: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：gateway: number;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：gateway: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：prefixLength: number;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：prefixLength: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：dnsServers: number[];<br>旧版本信息：|类名：IpConfig;<br>方法or属性：dnsServers: number[];<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpConfig;<br>方法or属性：domains: Array\<string>;<br>旧版本信息：|类名：IpConfig;<br>方法or属性：domains: Array\<string>;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiLinkedInfo;<br>方法or属性：networkId: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：networkId: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiLinkedInfo;<br>方法or属性：chload: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：chload: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiLinkedInfo;<br>方法or属性：snr: number;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：snr: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：WifiLinkedInfo;<br>方法or属性：suppState: SuppState;<br>旧版本信息：|类名：WifiLinkedInfo;<br>方法or属性：suppState: SuppState;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：ssid: string;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：ssid: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：securityType: WifiSecurityType;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：securityType: WifiSecurityType;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：band: number;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：band: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：preSharedKey: string;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：preSharedKey: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：HotspotConfig;<br>方法or属性：maxConn: number;<br>旧版本信息：|类名：HotspotConfig;<br>方法or属性：maxConn: number;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：StationInfo;<br>方法or属性：name: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：name: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：StationInfo;<br>方法or属性：macAddress: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：macAddress: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：StationInfo;<br>方法or属性：ipAddress: string;<br>旧版本信息：|类名：StationInfo;<br>方法or属性：ipAddress: string;<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpType;<br>方法or属性：STATIC<br>旧版本信息：|类名：IpType;<br>方法or属性：STATIC<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpType;<br>方法or属性：DHCP<br>旧版本信息：|类名：IpType;<br>方法or属性：DHCP<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：IpType;<br>方法or属性：UNKNOWN<br>旧版本信息：|类名：IpType;<br>方法or属性：UNKNOWN<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：DISCONNECTED<br>旧版本信息：|类名：SuppState;<br>方法or属性：DISCONNECTED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：INTERFACE_DISABLED<br>旧版本信息：|类名：SuppState;<br>方法or属性：INTERFACE_DISABLED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：INACTIVE<br>旧版本信息：|类名：SuppState;<br>方法or属性：INACTIVE<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：SCANNING<br>旧版本信息：|类名：SuppState;<br>方法or属性：SCANNING<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：AUTHENTICATING<br>旧版本信息：|类名：SuppState;<br>方法or属性：AUTHENTICATING<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：ASSOCIATING<br>旧版本信息：|类名：SuppState;<br>方法or属性：ASSOCIATING<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：ASSOCIATED<br>旧版本信息：|类名：SuppState;<br>方法or属性：ASSOCIATED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：FOUR_WAY_HANDSHAKE<br>旧版本信息：|类名：SuppState;<br>方法or属性：FOUR_WAY_HANDSHAKE<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：GROUP_HANDSHAKE<br>旧版本信息：|类名：SuppState;<br>方法or属性：GROUP_HANDSHAKE<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：COMPLETED<br>旧版本信息：|类名：SuppState;<br>方法or属性：COMPLETED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：UNINITIALIZED<br>旧版本信息：|类名：SuppState;<br>方法or属性：UNINITIALIZED<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|访问级别有变化|类名：SuppState;<br>方法or属性：INVALID<br>旧版本信息：|类名：SuppState;<br>方法or属性：INVALID<br>新版本信息：systemapi|@ohos.wifiManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteReq>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH,ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteReq>): void;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>新版本信息：ohos.permission.USE_BLUETOOTH|@ohos.bluetooth.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function getState(): BluetoothState;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function getState(): BluetoothState;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function getBtConnectionState(): ProfileConnectionState;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function getBtConnectionState(): ProfileConnectionState;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function pairDevice(deviceId: string): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function pairDevice(deviceId: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function cancelPairedDevice(deviceId: string): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function cancelPairedDevice(deviceId: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceName(deviceId: string): string;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceName(deviceId: string): string;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function getRemoteDeviceClass(deviceId: string): DeviceClass;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function enableBluetooth(): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function enableBluetooth(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function disableBluetooth(): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function disableBluetooth(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function getLocalName(): string;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function getLocalName(): string;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function getPairedDevices(): Array\<string>;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function getPairedDevices(): Array\<string>;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function getProfileConnectionState(profileId: ProfileId): ProfileConnectionState;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function getProfileConnectionState(profileId: ProfileId): ProfileConnectionState;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function setDevicePairingConfirmation(device: string, accept: boolean): void;<br>旧版本信息：ohos.permission.MANAGE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function setDevicePairingConfirmation(device: string, accept: boolean): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH,ohos.permission.MANAGE_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function setLocalName(name: string): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function setLocalName(name: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function setBluetoothScanMode(mode: ScanMode, duration: number): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function setBluetoothScanMode(mode: ScanMode, duration: number): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function getBluetoothScanMode(): ScanMode;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function getBluetoothScanMode(): ScanMode;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function startBluetoothDiscovery(): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH,ohos.permission.LOCATION,ohos.permission.APPROXIMATELY_LOCATION|类名：bluetoothManager;<br>方法or属性：function startBluetoothDiscovery(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function stopBluetoothDiscovery(): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function stopBluetoothDiscovery(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function on(type: 'bluetoothDeviceFind', callback: Callback\<Array\<string>>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function on(type: 'bluetoothDeviceFind', callback: Callback\<Array\<string>>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function on(type: 'bondStateChange', callback: Callback\<BondStateParam>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function on(type: 'bondStateChange', callback: Callback\<BondStateParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function on(type: 'pinRequired', callback: Callback\<PinRequiredParam>): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function on(type: 'pinRequired', callback: Callback\<PinRequiredParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function on(type: 'stateChange', callback: Callback\<BluetoothState>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function on(type: 'stateChange', callback: Callback\<BluetoothState>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function off(type: 'bluetoothDeviceFind', callback?: Callback\<Array\<string>>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function off(type: 'bluetoothDeviceFind', callback?: Callback\<Array\<string>>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function off(type: 'bondStateChange', callback?: Callback\<BondStateParam>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function off(type: 'bondStateChange', callback?: Callback\<BondStateParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function off(type: 'pinRequired', callback?: Callback\<PinRequiredParam>): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function off(type: 'pinRequired', callback?: Callback\<PinRequiredParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function off(type: 'stateChange', callback?: Callback\<BluetoothState>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function off(type: 'stateChange', callback?: Callback\<BluetoothState>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：bluetoothManager;<br>方法or属性：function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：bluetoothManager;<br>方法or属性：function sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：BaseProfile;<br>方法or属性：getConnectionDevices(): Array\<string>;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：BaseProfile;<br>方法or属性：getConnectionDevices(): Array\<string>;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：BaseProfile;<br>方法or属性：getDeviceState(device: string): ProfileConnectionState;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：BaseProfile;<br>方法or属性：getDeviceState(device: string): ProfileConnectionState;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：A2dpSourceProfile;<br>方法or属性：connect(device: string): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：A2dpSourceProfile;<br>方法or属性：connect(device: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：connect(device: string): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：connect(device: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：HidHostProfile;<br>方法or属性：connect(device: string): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：HidHostProfile;<br>方法or属性：connect(device: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH,ohos.permission.MANAGE_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：A2dpSourceProfile;<br>方法or属性：disconnect(device: string): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：A2dpSourceProfile;<br>方法or属性：disconnect(device: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：disconnect(device: string): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：disconnect(device: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：HidHostProfile;<br>方法or属性：disconnect(device: string): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：HidHostProfile;<br>方法or属性：disconnect(device: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH,ohos.permission.MANAGE_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：PanProfile;<br>方法or属性：disconnect(device: string): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：PanProfile;<br>方法or属性：disconnect(device: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：A2dpSourceProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：HidHostProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HidHostProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：PanProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：PanProfile;<br>方法or属性：on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：A2dpSourceProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HandsFreeAudioGatewayProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：HidHostProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：HidHostProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：PanProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>旧版本信息：|类名：PanProfile;<br>方法or属性：off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：A2dpSourceProfile;<br>方法or属性：getPlayingState(device: string): PlayingState;<br>旧版本信息：|类名：A2dpSourceProfile;<br>方法or属性：getPlayingState(device: string): PlayingState;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：PanProfile;<br>方法or属性：setTethering(enable: boolean): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：PanProfile;<br>方法or属性：setTethering(enable: boolean): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH,ohos.permission.MANAGE_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：PanProfile;<br>方法or属性：isTetheringOn(): boolean;<br>旧版本信息：|类名：PanProfile;<br>方法or属性：isTetheringOn(): boolean;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：BLE;<br>方法or属性：function getConnectedBLEDevices(): Array\<string>;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：BLE;<br>方法or属性：function getConnectedBLEDevices(): Array\<string>;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：BLE;<br>方法or属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH,ohos.permission.MANAGE_BLUETOOTH,ohos.permission.LOCATION,ohos.permission.APPROXIMATELY_LOCATION|类名：BLE;<br>方法or属性：function startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：BLE;<br>方法or属性：function stopBLEScan(): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：BLE;<br>方法or属性：function stopBLEScan(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：BLE;<br>方法or属性：function on(type: 'BLEDeviceFind', callback: Callback\<Array\<ScanResult>>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：BLE;<br>方法or属性：function on(type: 'BLEDeviceFind', callback: Callback\<Array\<ScanResult>>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：BLE;<br>方法or属性：function off(type: 'BLEDeviceFind', callback?: Callback\<Array\<ScanResult>>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：BLE;<br>方法or属性：function off(type: 'BLEDeviceFind', callback?: Callback\<Array\<ScanResult>>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：GattServer;<br>方法or属性：startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：stopAdvertising(): void;<br>旧版本信息：ohos.permission.DISCOVER_BLUETOOTH|类名：GattServer;<br>方法or属性：stopAdvertising(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：addService(service: GattService): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：addService(service: GattService): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：removeService(serviceUuid: string): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：removeService(serviceUuid: string): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：close(): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：close(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：close(): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：close(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：sendResponse(serverResponse: ServerResponse): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：sendResponse(serverResponse: ServerResponse): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：on(type: 'characteristicRead', callback: Callback\<CharacteristicReadRequest>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：on(type: 'characteristicRead', callback: Callback\<CharacteristicReadRequest>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：on(type: 'characteristicWrite', callback: Callback\<CharacteristicWriteRequest>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：on(type: 'characteristicWrite', callback: Callback\<CharacteristicWriteRequest>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：on(type: 'descriptorRead', callback: Callback\<DescriptorReadRequest>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：on(type: 'descriptorRead', callback: Callback\<DescriptorReadRequest>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteRequest>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteRequest>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：on(type: 'connectStateChange', callback: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：on(type: 'connectStateChange', callback: Callback\<BLEConnectChangedState>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：off(type: 'characteristicRead', callback?: Callback\<CharacteristicReadRequest>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：off(type: 'characteristicRead', callback?: Callback\<CharacteristicReadRequest>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：off(type: 'characteristicWrite', callback?: Callback\<CharacteristicWriteRequest>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：off(type: 'characteristicWrite', callback?: Callback\<CharacteristicWriteRequest>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：off(type: 'descriptorRead', callback?: Callback\<DescriptorReadRequest>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：off(type: 'descriptorRead', callback?: Callback\<DescriptorReadRequest>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：off(type: 'descriptorWrite', callback?: Callback\<DescriptorWriteRequest>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：off(type: 'descriptorWrite', callback?: Callback\<DescriptorWriteRequest>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattServer;<br>方法or属性：off(type: 'connectStateChange', callback?: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattServer;<br>方法or属性：off(type: 'connectStateChange', callback?: Callback\<BLEConnectChangedState>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：connect(): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：connect(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：disconnect(): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：disconnect(): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getDeviceName(callback: AsyncCallback\<string>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：getDeviceName(callback: AsyncCallback\<string>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getDeviceName(): Promise\<string>;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：getServices(callback: AsyncCallback\<Array\<GattService>>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getServices(): Promise\<Array\<GattService>>;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：writeCharacteristicValue(characteristic: BLECharacteristic): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：writeCharacteristicValue(characteristic: BLECharacteristic): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：writeDescriptorValue(descriptor: BLEDescriptor): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：writeDescriptorValue(descriptor: BLEDescriptor): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getRssiValue(callback: AsyncCallback\<number>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：getRssiValue(callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>旧版本信息：|类名：GattClientDevice;<br>方法or属性：getRssiValue(): Promise\<number>;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：setBLEMtuSize(mtu: number): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：setBLEMtuSize(mtu: number): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：on(type: 'BLECharacteristicChange', callback: Callback\<BLECharacteristic>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：on(type: 'BLECharacteristicChange', callback: Callback\<BLECharacteristic>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：on(type: 'BLEConnectionStateChange', callback: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：on(type: 'BLEConnectionStateChange', callback: Callback\<BLEConnectChangedState>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：off(type: 'BLECharacteristicChange', callback?: Callback\<BLECharacteristic>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：off(type: 'BLECharacteristicChange', callback?: Callback\<BLECharacteristic>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：GattClientDevice;<br>方法or属性：off(type: 'BLEConnectionStateChange', callback?: Callback\<BLEConnectChangedState>): void;<br>旧版本信息：ohos.permission.USE_BLUETOOTH|类名：GattClientDevice;<br>方法or属性：off(type: 'BLEConnectionStateChange', callback?: Callback\<BLEConnectChangedState>): void;<br>新版本信息：ohos.permission.ACCESS_BLUETOOTH|@ohos.bluetoothManager.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function readNdefTag(callback: AsyncCallback\<string>): void;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function read(callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function read(callback: AsyncCallback\<number[]>): void;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function writeNdefTag(data: string, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connectedTag;<br>方法or属性：function write(data: number[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function write(data: number[], callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.connectedTag.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getDefaultNet(): Promise\<NetHandle>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAllNets(): Promise\<Array\<NetHandle>>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getConnectionProperties(netHandle: NetHandle): Promise\<ConnectionProperties>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getNetCapabilities(netHandle: NetHandle): Promise\<NetCapabilities>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function isDefaultNetMetered(): Promise\<boolean>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function enableAirplaneMode(): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function disableAirplaneMode(): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetConnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO,ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>旧版本信息：|类名：connection;<br>方法or属性：function reportNetDisconnected(netHandle: NetHandle): Promise\<void>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO,ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：|类名：connection;<br>方法or属性：function getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressesByName(host: string): Promise\<Array\<NetAddress>>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：NetHandle;<br>方法or属性：getAddressByName(host: string): Promise\<NetAddress>;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：getAddressByName(host: string): Promise\<NetAddress>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.connection.d.ts|
|权限有变化|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getIfaceConfig(iface: string): Promise\<InterfaceConfiguration>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.ethernet.d.ts|
|权限有变化|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function setIfaceConfig(iface: string, ic: InterfaceConfiguration): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.ethernet.d.ts|
|权限有变化|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function isIfaceActive(iface: string): Promise\<number>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.ethernet.d.ts|
|权限有变化|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>旧版本信息：|类名：ethernet;<br>方法or属性：function getAllActiveIfaces(): Promise\<Array\<string>>;<br>新版本信息：ohos.permission.GET_NETWORK_INFO|@ohos.net.ethernet.d.ts|
|权限有变化|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.http.d.ts|
|权限有变化|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.http.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharingSupported(): Promise\<boolean>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function isSharing(): Promise\<boolean>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function startSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function stopSharing(type: SharingIfaceType): Promise\<void>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsRxBytes(): Promise\<number>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTxBytes(): Promise\<number>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getStatsTotalBytes(): Promise\<number>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>旧版本信息：|类名：sharing;<br>方法or属性：function getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>;<br>新版本信息：ohos.permission.CONNECTIVITY_INTERNAL|@ohos.net.sharing.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.socket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>新版本信息：ohos.permission.INTERNET|@ohos.net.webSocket.d.ts|
|权限有变化|类名：HceService;<br>方法or属性：transmit(response: number[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：HceService;<br>方法or属性：transmit(response: number[], callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_CARD_EMULATION|@ohos.nfc.cardEmulation.d.ts|
|权限有变化|类名：TagInfo;<br>方法or属性：uid: number[];<br>旧版本信息：|类名：TagInfo;<br>方法or属性：uid: number[];<br>新版本信息：ohos.permission.NFC_TAG|@ohos.nfc.tag.d.ts|
|权限有变化|类名：TagInfo;<br>方法or属性：technology: number[];<br>旧版本信息：|类名：TagInfo;<br>方法or属性：technology: number[];<br>新版本信息：ohos.permission.NFC_TAG|@ohos.nfc.tag.d.ts|
|权限有变化|类名：TagInfo;<br>方法or属性：extrasData: PacMap[];<br>旧版本信息：|类名：TagInfo;<br>方法or属性：extrasData: PacMap[];<br>新版本信息：ohos.permission.NFC_TAG|@ohos.nfc.tag.d.ts|
|权限有变化|类名：TagInfo;<br>方法or属性：tagRfDiscId: number;<br>旧版本信息：|类名：TagInfo;<br>方法or属性：tagRfDiscId: number;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.nfc.tag.d.ts|
|权限有变化|类名：TagInfo;<br>方法or属性：remoteTagService: rpc.RemoteObject;<br>旧版本信息：|类名：TagInfo;<br>方法or属性：remoteTagService: rpc.RemoteObject;<br>新版本信息：ohos.permission.NFC_TAG|@ohos.nfc.tag.d.ts|
|权限有变化|类名：TagInfo;<br>方法or属性：supportedProfiles: number[];<br>旧版本信息：|类名：TagInfo;<br>方法or属性：supportedProfiles: number[];<br>新版本信息：ohos.permission.NFC_TAG|@ohos.nfc.tag.d.ts|
|权限有变化|类名：wifi;<br>方法or属性：function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getScanInfos(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.GET_WIFI_PEERS_MAC,ohos.permission.LOCATION|@ohos.wifi.d.ts|
|权限有变化|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO,ohos.permission.SET_WIFI_CONFIG|@ohos.wifi.d.ts|
|权限有变化|类名：wifi;<br>方法or属性：function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO|@ohos.wifi.d.ts|
|权限有变化|类名：wifi;<br>方法or属性：function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO|@ohos.wifi.d.ts|
|权限有变化|类名：wifi;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifi.d.ts|
|权限有变化|类名：wifi;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifi.d.ts|
|权限有变化|类名：wifi;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|@ohos.wifi.d.ts|
|权限有变化|类名：wifi;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>旧版本信息：|类名：wifi;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|@ohos.wifi.d.ts|
|权限有变化|类名：wifiext;<br>方法or属性：function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiext.d.ts|
|权限有变化|类名：wifiext;<br>方法or属性：function getPowerModel(callback: AsyncCallback\<PowerModel>): void;<br>旧版本信息：|类名：wifiext;<br>方法or属性：function getPowerModel(callback: AsyncCallback\<PowerModel>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiext.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function scan(): void;<br>旧版本信息：ohos.permission.SET_WIFI_INFO,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function scan(): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO,ohos.permission.LOCATION,ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getScanResults(): Promise\<Array\<WifiScanInfo>>;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.GET_WIFI_PEERS_MAC,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function getScanResults(): Promise\<Array\<WifiScanInfo>>;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.GET_WIFI_PEERS_MAC,ohos.permission.LOCATION,ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getScanResults(callback: AsyncCallback\<Array\<WifiScanInfo>>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.GET_WIFI_PEERS_MAC,ohos.permission.LOCATION,ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getScanResultsSync(): Array\<WifiScanInfo>;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.GET_WIFI_PEERS_MAC,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function getScanResultsSync(): Array\<WifiScanInfo>;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.GET_WIFI_PEERS_MAC,ohos.permission.LOCATION,ohos.permission.APPROXIMATELY_LOCATION|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addDeviceConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO,ohos.permission.SET_WIFI_CONFIG|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function addCandidateConfig(config: WifiDeviceConfig, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function removeCandidateConfig(networkId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.SET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getCandidateConfigs(): Array\<WifiDeviceConfig>;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function getCandidateConfigs(): Array\<WifiDeviceConfig>;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION,ohos.permission.GET_WIFI_CONFIG|类名：wifiManager;<br>方法or属性：function getDeviceConfigs(): Array\<WifiDeviceConfig>;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.GET_WIFI_CONFIG|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getStations(): Array\<StationInfo>;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION,ohos.permission.MANAGE_WIFI_HOTSPOT|类名：wifiManager;<br>方法or属性：function getStations(): Array\<StationInfo>;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.MANAGE_WIFI_HOTSPOT|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pLinkedInfo(callback: AsyncCallback\<WifiP2pLinkedInfo>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function getCurrentGroup(): Promise\<WifiP2pGroupInfo>;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getCurrentGroup(callback: AsyncCallback\<WifiP2pGroupInfo>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(): Promise\<WifiP2pDevice[]>;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pPeerDevices(callback: AsyncCallback\<WifiP2pDevice[]>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pLocalDevice(callback: AsyncCallback\<WifiP2pDevice>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.GET_WIFI_CONFIG|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function p2pConnect(config: WifiP2PConfig): void;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function p2pConnect(config: WifiP2PConfig): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function startDiscoverDevices(): void;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function startDiscoverDevices(): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function getP2pGroups(): Promise\<Array\<WifiP2pGroupInfo>>;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>旧版本信息：|类名：wifiManager;<br>方法or属性：function getP2pGroups(callback: AsyncCallback\<Array\<WifiP2pGroupInfo>>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function on(type: 'p2pDeviceChange', callback: Callback\<WifiP2pDevice>): void;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function on(type: 'p2pDeviceChange', callback: Callback\<WifiP2pDevice>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function on(type: 'p2pPeerDeviceChange', callback: Callback\<WifiP2pDevice[]>): void;<br>旧版本信息：ohos.permission.GET_WIFI_INFO,ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function on(type: 'p2pPeerDeviceChange', callback: Callback\<WifiP2pDevice[]>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function off(type: 'p2pDeviceChange', callback?: Callback\<WifiP2pDevice>): void;<br>旧版本信息：ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function off(type: 'p2pDeviceChange', callback?: Callback\<WifiP2pDevice>): void;<br>新版本信息：|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManager;<br>方法or属性：function off(type: 'p2pPeerDeviceChange', callback?: Callback\<WifiP2pDevice[]>): void;<br>旧版本信息：ohos.permission.LOCATION|类名：wifiManager;<br>方法or属性：function off(type: 'p2pPeerDeviceChange', callback?: Callback\<WifiP2pDevice[]>): void;<br>新版本信息：|@ohos.wifiManager.d.ts|
|权限有变化|类名：wifiManagerExt;<br>方法or属性：function getSupportedPowerMode(callback: AsyncCallback\<Array\<PowerMode>>): void;<br>旧版本信息：|类名：wifiManagerExt;<br>方法or属性：function getSupportedPowerMode(callback: AsyncCallback\<Array\<PowerMode>>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManagerExt.d.ts|
|权限有变化|类名：wifiManagerExt;<br>方法or属性：function getPowerMode(callback: AsyncCallback\<PowerMode>): void;<br>旧版本信息：|类名：wifiManagerExt;<br>方法or属性：function getPowerMode(callback: AsyncCallback\<PowerMode>): void;<br>新版本信息：ohos.permission.GET_WIFI_INFO|@ohos.wifiManagerExt.d.ts|
|权限有变化|类名：IsoDepTag;<br>方法or属性：isExtendedApduSupported(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：IsoDepTag;<br>方法or属性：isExtendedApduSupported(callback: AsyncCallback\<boolean>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：NdefTag;<br>方法or属性：readNdef(callback: AsyncCallback\<NdefMessage>): void;<br>旧版本信息：|类名：NdefTag;<br>方法or属性：readNdef(callback: AsyncCallback\<NdefMessage>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：NdefTag;<br>方法or属性：writeNdef(msg: NdefMessage, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NdefTag;<br>方法or属性：writeNdef(msg: NdefMessage, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：NdefTag;<br>方法or属性：setReadOnly(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NdefTag;<br>方法or属性：setReadOnly(callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：MifareClassicTag;<br>方法or属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：MifareClassicTag;<br>方法or属性：readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：MifareClassicTag;<br>方法or属性：writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：MifareClassicTag;<br>方法or属性：incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：MifareClassicTag;<br>方法or属性：decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：MifareClassicTag;<br>方法or属性：transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：MifareClassicTag;<br>方法or属性：restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareClassicTag;<br>方法or属性：restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：MifareUltralightTag;<br>方法or属性：readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：MifareUltralightTag;<br>方法or属性：readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：MifareUltralightTag;<br>方法or属性：writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：MifareUltralightTag;<br>方法or属性：writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：NdefFormatableTag;<br>方法or属性：format(message: NdefMessage, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NdefFormatableTag;<br>方法or属性：format(message: NdefMessage, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：NdefFormatableTag;<br>方法or属性：formatReadOnly(message: NdefMessage, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NdefFormatableTag;<br>方法or属性：formatReadOnly(message: NdefMessage, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.NFC_TAG|nfctech.d.ts|
|权限有变化|类名：TagSession;<br>方法or属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：TagSession;<br>方法or属性：sendData(data: number[], callback: AsyncCallback\<number[]>): void;<br>新版本信息：ohos.permission.NFC_TAG|tagSession.d.ts|
|权限有变化|类名：TagSession;<br>方法or属性：transmit(data: number[], callback: AsyncCallback\<number[]>): void;<br>旧版本信息：|类名：TagSession;<br>方法or属性：transmit(data: number[], callback: AsyncCallback\<number[]>): void;<br>新版本信息：ohos.permission.NFC_TAG|tagSession.d.ts|
|type有变化|类名：connectedTag;<br>方法or属性：function on(type: 'notify', callback: Callback\<number>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function on(type: 'notify', callback: Callback\<number>): void;<br>新版本信息：|@ohos.connectedTag.d.ts|
|type有变化|类名：connectedTag;<br>方法or属性：function off(type: 'notify', callback?: Callback\<number>): void;<br>旧版本信息：|类名：connectedTag;<br>方法or属性：function off(type: 'notify', callback?: Callback\<number>): void;<br>新版本信息：|@ohos.connectedTag.d.ts|
|type有变化|类名：NetSpecifier;<br>方法or属性：netCapabilities: NetCapabilities;<br>旧版本信息：|类名：NetSpecifier;<br>方法or属性：netCapabilities: NetCapabilities;<br>新版本信息：NetCapabilities|@ohos.net.connection.d.ts|
|type有变化|类名：NetSpecifier;<br>方法or属性：bearerPrivateIdentifier?: string;<br>旧版本信息：|类名：NetSpecifier;<br>方法or属性：bearerPrivateIdentifier?: string;<br>新版本信息：?string|@ohos.net.connection.d.ts|
|type有变化|类名：NetHandle;<br>方法or属性：netId: number;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：netId: number;<br>新版本信息：number|@ohos.net.connection.d.ts|
|type有变化|类名：NetCapabilities;<br>方法or属性：linkUpBandwidthKbps?: number;<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：linkUpBandwidthKbps?: number;<br>新版本信息：?number|@ohos.net.connection.d.ts|
|type有变化|类名：NetCapabilities;<br>方法or属性：linkDownBandwidthKbps?: number;<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：linkDownBandwidthKbps?: number;<br>新版本信息：?number|@ohos.net.connection.d.ts|
|type有变化|类名：NetCapabilities;<br>方法or属性：networkCap?: Array\<NetCap>;<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：networkCap?: Array\<NetCap>;<br>新版本信息：?Array\<NetCap>|@ohos.net.connection.d.ts|
|type有变化|类名：NetCapabilities;<br>方法or属性：bearerTypes: Array\<NetBearType>;<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：bearerTypes: Array\<NetBearType>;<br>新版本信息：Array\<NetBearType>|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：interfaceName: string;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：interfaceName: string;<br>新版本信息：string|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：domains: string;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：domains: string;<br>新版本信息：string|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：linkAddresses: Array\<LinkAddress>;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：linkAddresses: Array\<LinkAddress>;<br>新版本信息：Array\<LinkAddress>|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：dnses: Array\<NetAddress>;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：dnses: Array\<NetAddress>;<br>新版本信息：Array\<NetAddress>|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：routes: Array\<RouteInfo>;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：routes: Array\<RouteInfo>;<br>新版本信息：Array\<RouteInfo>|@ohos.net.connection.d.ts|
|type有变化|类名：ConnectionProperties;<br>方法or属性：mtu: number;<br>旧版本信息：|类名：ConnectionProperties;<br>方法or属性：mtu: number;<br>新版本信息：number|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：interface: string;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：interface: string;<br>新版本信息：string|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：destination: LinkAddress;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：destination: LinkAddress;<br>新版本信息：LinkAddress|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：gateway: NetAddress;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：gateway: NetAddress;<br>新版本信息：NetAddress|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：hasGateway: boolean;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：hasGateway: boolean;<br>新版本信息：boolean|@ohos.net.connection.d.ts|
|type有变化|类名：RouteInfo;<br>方法or属性：isDefaultRoute: boolean;<br>旧版本信息：|类名：RouteInfo;<br>方法or属性：isDefaultRoute: boolean;<br>新版本信息：boolean|@ohos.net.connection.d.ts|
|type有变化|类名：LinkAddress;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：LinkAddress;<br>方法or属性：address: NetAddress;<br>新版本信息：NetAddress|@ohos.net.connection.d.ts|
|type有变化|类名：LinkAddress;<br>方法or属性：prefixLength: number;<br>旧版本信息：|类名：LinkAddress;<br>方法or属性：prefixLength: number;<br>新版本信息：number|@ohos.net.connection.d.ts|
|type有变化|类名：NetAddress;<br>方法or属性：address: string;<br>旧版本信息：|类名：NetAddress;<br>方法or属性：address: string;<br>新版本信息：string|@ohos.net.connection.d.ts|
|type有变化|类名：NetAddress;<br>方法or属性：family?: number;<br>旧版本信息：|类名：NetAddress;<br>方法or属性：family?: number;<br>新版本信息：?number|@ohos.net.connection.d.ts|
|type有变化|类名：NetAddress;<br>方法or属性：port?: number;<br>旧版本信息：|类名：NetAddress;<br>方法or属性：port?: number;<br>新版本信息：?number|@ohos.net.connection.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：mode: IPSetMode;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：mode: IPSetMode;<br>新版本信息：IPSetMode|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：ipAddr: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：ipAddr: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：route: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：route: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：gateway: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：gateway: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：netMask: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：netMask: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：InterfaceConfiguration;<br>方法or属性：dnsServers: string;<br>旧版本信息：|类名：InterfaceConfiguration;<br>方法or属性：dnsServers: string;<br>新版本信息：string|@ohos.net.ethernet.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：method?: RequestMethod;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：method?: RequestMethod;<br>新版本信息：?RequestMethod|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：extraData?: string \| Object \| ArrayBuffer;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：extraData?: string \| Object \| ArrayBuffer;<br>新版本信息：?string \| Object \| ArrayBuffer|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：expectDataType?: HttpDataType;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：expectDataType?: HttpDataType;<br>新版本信息：?HttpDataType|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：usingCache?: boolean;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：usingCache?: boolean;<br>新版本信息：?boolean|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：priority?: number;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：priority?: number;<br>新版本信息：?number|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：header?: Object;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：header?: Object;<br>新版本信息：?Object|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：readTimeout?: number;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：readTimeout?: number;<br>新版本信息：?number|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：connectTimeout?: number;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：connectTimeout?: number;<br>新版本信息：?number|@ohos.net.http.d.ts|
|type有变化|类名：HttpRequestOptions;<br>方法or属性：usingProtocol?: HttpProtocol;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：usingProtocol?: HttpProtocol;<br>新版本信息：?HttpProtocol|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：result: string \| Object \| ArrayBuffer;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：result: string \| Object \| ArrayBuffer;<br>新版本信息：string \| Object \| ArrayBuffer|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：resultType: HttpDataType;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：resultType: HttpDataType;<br>新版本信息：HttpDataType|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：responseCode: ResponseCode \| number;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：responseCode: ResponseCode \| number;<br>新版本信息：ResponseCode \| number|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：header: Object;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：header: Object;<br>新版本信息：Object|@ohos.net.http.d.ts|
|type有变化|类名：HttpResponse;<br>方法or属性：cookies: string;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：cookies: string;<br>新版本信息：string|@ohos.net.http.d.ts|
|type有变化|类名：UDPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>旧版本信息：|类名：UDPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>新版本信息：string \| ArrayBuffer|@ohos.net.socket.d.ts|
|type有变化|类名：TCPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>旧版本信息：|类名：TCPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>新版本信息：string \| ArrayBuffer|@ohos.net.socket.d.ts|
|type有变化|类名：UDPSendOptions;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：UDPSendOptions;<br>方法or属性：address: NetAddress;<br>新版本信息：NetAddress|@ohos.net.socket.d.ts|
|type有变化|类名：TCPConnectOptions;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：TCPConnectOptions;<br>方法or属性：address: NetAddress;<br>新版本信息：NetAddress|@ohos.net.socket.d.ts|
|type有变化|类名：TLSConnectOptions;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：address: NetAddress;<br>新版本信息：NetAddress|@ohos.net.socket.d.ts|
|type有变化|类名：ExtraOptionsBase;<br>方法or属性：receiveBufferSize?: number;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：receiveBufferSize?: number;<br>新版本信息：?number|@ohos.net.socket.d.ts|
|type有变化|类名：ExtraOptionsBase;<br>方法or属性：sendBufferSize?: number;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：sendBufferSize?: number;<br>新版本信息：?number|@ohos.net.socket.d.ts|
|type有变化|类名：ExtraOptionsBase;<br>方法or属性：reuseAddress?: boolean;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：reuseAddress?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：ExtraOptionsBase;<br>方法or属性：socketTimeout?: number;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：socketTimeout?: number;<br>新版本信息：?number|@ohos.net.socket.d.ts|
|type有变化|类名：UDPExtraOptions;<br>方法or属性：broadcast?: boolean;<br>旧版本信息：|类名：UDPExtraOptions;<br>方法or属性：broadcast?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：SocketStateBase;<br>方法or属性：isBound: boolean;<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：isBound: boolean;<br>新版本信息：boolean|@ohos.net.socket.d.ts|
|type有变化|类名：SocketStateBase;<br>方法or属性：isClose: boolean;<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：isClose: boolean;<br>新版本信息：boolean|@ohos.net.socket.d.ts|
|type有变化|类名：SocketStateBase;<br>方法or属性：isConnected: boolean;<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：isConnected: boolean;<br>新版本信息：boolean|@ohos.net.socket.d.ts|
|type有变化|类名：SocketRemoteInfo;<br>方法or属性：address: string;<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：address: string;<br>新版本信息：string|@ohos.net.socket.d.ts|
|type有变化|类名：SocketRemoteInfo;<br>方法or属性：family: 'IPv4' \| 'IPv6';<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：family: 'IPv4' \| 'IPv6';<br>新版本信息：'IPv4' \| 'IPv6'|@ohos.net.socket.d.ts|
|type有变化|类名：SocketRemoteInfo;<br>方法or属性：port: number;<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：port: number;<br>新版本信息：number|@ohos.net.socket.d.ts|
|type有变化|类名：SocketRemoteInfo;<br>方法or属性：size: number;<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：size: number;<br>新版本信息：number|@ohos.net.socket.d.ts|
|type有变化|类名：TCPConnectOptions;<br>方法or属性：timeout?: number;<br>旧版本信息：|类名：TCPConnectOptions;<br>方法or属性：timeout?: number;<br>新版本信息：?number|@ohos.net.socket.d.ts|
|type有变化|类名：TCPSendOptions;<br>方法or属性：encoding?: string;<br>旧版本信息：|类名：TCPSendOptions;<br>方法or属性：encoding?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TCPExtraOptions;<br>方法or属性：keepAlive?: boolean;<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：keepAlive?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：TCPExtraOptions;<br>方法or属性：OOBInline?: boolean;<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：OOBInline?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：TCPExtraOptions;<br>方法or属性：TCPNoDelay?: boolean;<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：TCPNoDelay?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：TCPExtraOptions;<br>方法or属性：socketLinger?: { on: boolean, linger: number };<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：socketLinger?: { on: boolean, linger: number };<br>新版本信息：?object|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：ca: string \| Array\<string>;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：ca: string \| Array\<string>;<br>新版本信息：string \| Array\<string>|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：cert?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：cert?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：key?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：key?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：password?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：password?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：protocols?: Protocol \| Array\<Protocol>;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：protocols?: Protocol \| Array\<Protocol>;<br>新版本信息：?Protocol \| Array\<Protocol>|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：useRemoteCipherPrefer?: boolean;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：useRemoteCipherPrefer?: boolean;<br>新版本信息：?boolean|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：signatureAlgorithms?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：signatureAlgorithms?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSSecureOptions;<br>方法or属性：cipherSuite?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：cipherSuite?: string;<br>新版本信息：?string|@ohos.net.socket.d.ts|
|type有变化|类名：TLSConnectOptions;<br>方法or属性：secureOptions: TLSSecureOptions;<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：secureOptions: TLSSecureOptions;<br>新版本信息：TLSSecureOptions|@ohos.net.socket.d.ts|
|type有变化|类名：TLSConnectOptions;<br>方法or属性：ALPNProtocols?: Array\<string>;<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：ALPNProtocols?: Array\<string>;<br>新版本信息：?Array\<string>|@ohos.net.socket.d.ts|
|type有变化|类名：WebSocketRequestOptions;<br>方法or属性：header?: Object;<br>旧版本信息：|类名：WebSocketRequestOptions;<br>方法or属性：header?: Object;<br>新版本信息：?Object|@ohos.net.webSocket.d.ts|
|type有变化|类名：WebSocketCloseOptions;<br>方法or属性：code?: number;<br>旧版本信息：|类名：WebSocketCloseOptions;<br>方法or属性：code?: number;<br>新版本信息：?number|@ohos.net.webSocket.d.ts|
|type有变化|类名：WebSocketCloseOptions;<br>方法or属性：reason?: string;<br>旧版本信息：|类名：WebSocketCloseOptions;<br>方法or属性：reason?: string;<br>新版本信息：?string|@ohos.net.webSocket.d.ts|
|type有变化|类名：WifiEapConfig;<br>方法or属性：eapSubId: number;<br>旧版本信息：|类名：WifiEapConfig;<br>方法or属性：eapSubId: number;<br>新版本信息：number|@ohos.wifiManager.d.ts|
|type有变化|类名：WifiDeviceConfig;<br>方法or属性：eapConfig?: WifiEapConfig;<br>旧版本信息：|类名：WifiDeviceConfig;<br>方法or属性：eapConfig?: WifiEapConfig;<br>新版本信息：?WifiEapConfig|@ohos.wifiManager.d.ts|
|type有变化|类名：NetworkResponse;<br>方法or属性：type: string;<br>旧版本信息：|类名：NetworkResponse;<br>方法or属性：type: string;<br>新版本信息：string|@system.network.d.ts|
|type有变化|类名：NetworkResponse;<br>方法or属性：metered: boolean;<br>旧版本信息：|类名：NetworkResponse;<br>方法or属性：metered: boolean;<br>新版本信息：boolean|@system.network.d.ts|
|函数有变化|类名：WebSocket;<br>方法or属性：on(type: 'close', callback: AsyncCallback\<{ code: number, reason: string }>): void;|类名：WebSocket;<br>方法or属性：on(type: 'close', callback: AsyncCallback\<CloseResult>): void;|@ohos.net.webSocket.d.ts|
|函数有变化|类名：WebSocket;<br>方法or属性：off(type: 'close', callback?: AsyncCallback\<{ code: number, reason: string }>): void;|类名：WebSocket;<br>方法or属性：off(type: 'close', callback?: AsyncCallback\<CloseResult>): void;|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：connection;<br>方法or属性：declare connection<br>旧版本信息：|类名：connection;<br>方法or属性：declare connection<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：connection;<br>方法or属性：function createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection;<br>旧版本信息：|类名：connection;<br>方法or属性：function createNetConnection(netSpecifier?: NetSpecifier, timeout?: number): NetConnection;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>旧版本信息：|类名：connection;<br>方法or属性：function hasDefaultNet(): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetConnection;<br>方法or属性：export interface NetConnection<br>旧版本信息：|类名：NetConnection;<br>方法or属性：export interface NetConnection<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetConnection;<br>方法or属性：on(type: 'netAvailable', callback: Callback\<NetHandle>): void;<br>旧版本信息：|类名：NetConnection;<br>方法or属性：on(type: 'netAvailable', callback: Callback\<NetHandle>): void;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetConnection;<br>方法or属性：on(type: 'netLost', callback: Callback\<NetHandle>): void;<br>旧版本信息：|类名：NetConnection;<br>方法or属性：on(type: 'netLost', callback: Callback\<NetHandle>): void;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetConnection;<br>方法or属性：on(type: 'netUnavailable', callback: Callback\<void>): void;<br>旧版本信息：|类名：NetConnection;<br>方法or属性：on(type: 'netUnavailable', callback: Callback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetConnection;<br>方法or属性：register(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NetConnection;<br>方法or属性：register(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetConnection;<br>方法or属性：unregister(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：NetConnection;<br>方法or属性：unregister(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetHandle;<br>方法or属性：export interface NetHandle<br>旧版本信息：|类名：NetHandle;<br>方法or属性：export interface NetHandle<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetHandle;<br>方法or属性：netId: number;<br>旧版本信息：|类名：NetHandle;<br>方法or属性：netId: number;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetCapabilities;<br>方法or属性：export interface NetCapabilities<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：export interface NetCapabilities<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetCapabilities;<br>方法or属性：bearerTypes: Array\<NetBearType>;<br>旧版本信息：|类名：NetCapabilities;<br>方法or属性：bearerTypes: Array\<NetBearType>;<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetBearType;<br>方法or属性：export enum NetBearType<br>旧版本信息：|类名：NetBearType;<br>方法or属性：export enum NetBearType<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetBearType;<br>方法or属性：BEARER_CELLULAR = 0<br>旧版本信息：|类名：NetBearType;<br>方法or属性：BEARER_CELLULAR = 0<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：NetBearType;<br>方法or属性：BEARER_WIFI = 1<br>旧版本信息：|类名：NetBearType;<br>方法or属性：BEARER_WIFI = 1<br>新版本信息：crossplatform|@ohos.net.connection.d.ts|
|跨平台能力有变化|类名：http;<br>方法or属性：declare http<br>旧版本信息：|类名：http;<br>方法or属性：declare http<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：http;<br>方法or属性：function createHttp(): HttpRequest;<br>旧版本信息：|类名：http;<br>方法or属性：function createHttp(): HttpRequest;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：http;<br>方法or属性：function createHttpResponseCache(cacheSize?: number): HttpResponseCache;<br>旧版本信息：|类名：http;<br>方法or属性：function createHttpResponseCache(cacheSize?: number): HttpResponseCache;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：export interface HttpRequestOptions<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：export interface HttpRequestOptions<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：method?: RequestMethod;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：method?: RequestMethod;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：extraData?: string \| Object \| ArrayBuffer;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：extraData?: string \| Object \| ArrayBuffer;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：expectDataType?: HttpDataType;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：expectDataType?: HttpDataType;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：usingCache?: boolean;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：usingCache?: boolean;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：priority?: number;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：priority?: number;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：header?: Object;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：header?: Object;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：readTimeout?: number;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：readTimeout?: number;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：connectTimeout?: number;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：connectTimeout?: number;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequestOptions;<br>方法or属性：usingProtocol?: HttpProtocol;<br>旧版本信息：|类名：HttpRequestOptions;<br>方法or属性：usingProtocol?: HttpProtocol;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequest;<br>方法or属性：export interface HttpRequest<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：export interface HttpRequest<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequest;<br>方法or属性：request(url: string, callback: AsyncCallback\<HttpResponse>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, callback: AsyncCallback\<HttpResponse>): void;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options: HttpRequestOptions, callback: AsyncCallback\<HttpResponse>): void;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：request(url: string, options?: HttpRequestOptions): Promise\<HttpResponse>;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequest;<br>方法or属性：destroy(): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：destroy(): void;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequest;<br>方法or属性：on(type: "headersReceive", callback: Callback\<Object>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：on(type: "headersReceive", callback: Callback\<Object>): void;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequest;<br>方法or属性：off(type: "headersReceive", callback?: Callback\<Object>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：off(type: "headersReceive", callback?: Callback\<Object>): void;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpRequest;<br>方法or属性：once(type: "headersReceive", callback: Callback\<Object>): void;<br>旧版本信息：|类名：HttpRequest;<br>方法or属性：once(type: "headersReceive", callback: Callback\<Object>): void;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：RequestMethod;<br>方法or属性：export enum RequestMethod<br>旧版本信息：|类名：RequestMethod;<br>方法or属性：export enum RequestMethod<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：RequestMethod;<br>方法or属性：OPTIONS = "OPTIONS"<br>旧版本信息：|类名：RequestMethod;<br>方法or属性：OPTIONS = "OPTIONS"<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：RequestMethod;<br>方法or属性：GET = "GET"<br>旧版本信息：|类名：RequestMethod;<br>方法or属性：GET = "GET"<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：RequestMethod;<br>方法or属性：HEAD = "HEAD"<br>旧版本信息：|类名：RequestMethod;<br>方法or属性：HEAD = "HEAD"<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：RequestMethod;<br>方法or属性：POST = "POST"<br>旧版本信息：|类名：RequestMethod;<br>方法or属性：POST = "POST"<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：RequestMethod;<br>方法or属性：PUT = "PUT"<br>旧版本信息：|类名：RequestMethod;<br>方法or属性：PUT = "PUT"<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：RequestMethod;<br>方法or属性：DELETE = "DELETE"<br>旧版本信息：|类名：RequestMethod;<br>方法or属性：DELETE = "DELETE"<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：RequestMethod;<br>方法or属性：TRACE = "TRACE"<br>旧版本信息：|类名：RequestMethod;<br>方法or属性：TRACE = "TRACE"<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：RequestMethod;<br>方法or属性：CONNECT = "CONNECT"<br>旧版本信息：|类名：RequestMethod;<br>方法or属性：CONNECT = "CONNECT"<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：export enum ResponseCode<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：export enum ResponseCode<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：OK = 200<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：OK = 200<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：CREATED<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：CREATED<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：ACCEPTED<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：ACCEPTED<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：NOT_AUTHORITATIVE<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：NOT_AUTHORITATIVE<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：NO_CONTENT<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：NO_CONTENT<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：RESET<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：RESET<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：PARTIAL<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：PARTIAL<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：MULT_CHOICE = 300<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：MULT_CHOICE = 300<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：MOVED_PERM<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：MOVED_PERM<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：MOVED_TEMP<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：MOVED_TEMP<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：SEE_OTHER<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：SEE_OTHER<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：NOT_MODIFIED<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：NOT_MODIFIED<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：USE_PROXY<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：USE_PROXY<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：BAD_REQUEST = 400<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：BAD_REQUEST = 400<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：UNAUTHORIZED<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：UNAUTHORIZED<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：PAYMENT_REQUIRED<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：PAYMENT_REQUIRED<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：FORBIDDEN<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：FORBIDDEN<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：NOT_FOUND<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：NOT_FOUND<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：BAD_METHOD<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：BAD_METHOD<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：NOT_ACCEPTABLE<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：NOT_ACCEPTABLE<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：PROXY_AUTH<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：PROXY_AUTH<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：CLIENT_TIMEOUT<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：CLIENT_TIMEOUT<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：CONFLICT<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：CONFLICT<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：GONE<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：GONE<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：LENGTH_REQUIRED<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：LENGTH_REQUIRED<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：PRECON_FAILED<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：PRECON_FAILED<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：ENTITY_TOO_LARGE<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：ENTITY_TOO_LARGE<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：REQ_TOO_LONG<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：REQ_TOO_LONG<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：UNSUPPORTED_TYPE<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：UNSUPPORTED_TYPE<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：INTERNAL_ERROR = 500<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：INTERNAL_ERROR = 500<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：NOT_IMPLEMENTED<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：NOT_IMPLEMENTED<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：BAD_GATEWAY<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：BAD_GATEWAY<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：UNAVAILABLE<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：UNAVAILABLE<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：GATEWAY_TIMEOUT<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：GATEWAY_TIMEOUT<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：ResponseCode;<br>方法or属性：VERSION<br>旧版本信息：|类名：ResponseCode;<br>方法or属性：VERSION<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpProtocol;<br>方法or属性：export enum HttpProtocol<br>旧版本信息：|类名：HttpProtocol;<br>方法or属性：export enum HttpProtocol<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpProtocol;<br>方法or属性：HTTP1_1<br>旧版本信息：|类名：HttpProtocol;<br>方法or属性：HTTP1_1<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpProtocol;<br>方法or属性：HTTP2<br>旧版本信息：|类名：HttpProtocol;<br>方法or属性：HTTP2<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpDataType;<br>方法or属性：export enum HttpDataType<br>旧版本信息：|类名：HttpDataType;<br>方法or属性：export enum HttpDataType<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpDataType;<br>方法or属性：STRING<br>旧版本信息：|类名：HttpDataType;<br>方法or属性：STRING<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpDataType;<br>方法or属性：OBJECT = 1<br>旧版本信息：|类名：HttpDataType;<br>方法or属性：OBJECT = 1<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpDataType;<br>方法or属性：ARRAY_BUFFER = 2<br>旧版本信息：|类名：HttpDataType;<br>方法or属性：ARRAY_BUFFER = 2<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponse;<br>方法or属性：export interface HttpResponse<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：export interface HttpResponse<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponse;<br>方法or属性：result: string \| Object \| ArrayBuffer;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：result: string \| Object \| ArrayBuffer;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponse;<br>方法or属性：resultType: HttpDataType;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：resultType: HttpDataType;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponse;<br>方法or属性：responseCode: ResponseCode \| number;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：responseCode: ResponseCode \| number;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponse;<br>方法or属性：header: Object;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：header: Object;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponse;<br>方法or属性：cookies: string;<br>旧版本信息：|类名：HttpResponse;<br>方法or属性：cookies: string;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponseCache;<br>方法or属性：export interface HttpResponseCache<br>旧版本信息：|类名：HttpResponseCache;<br>方法or属性：export interface HttpResponseCache<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponseCache;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：HttpResponseCache;<br>方法or属性：flush(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponseCache;<br>方法or属性：flush(): Promise\<void>;<br>旧版本信息：|类名：HttpResponseCache;<br>方法or属性：flush(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponseCache;<br>方法or属性：delete(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：HttpResponseCache;<br>方法or属性：delete(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：HttpResponseCache;<br>方法or属性：delete(): Promise\<void>;<br>旧版本信息：|类名：HttpResponseCache;<br>方法or属性：delete(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.http.d.ts|
|跨平台能力有变化|类名：socket;<br>方法or属性：declare socket<br>旧版本信息：|类名：socket;<br>方法or属性：declare socket<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：socket;<br>方法or属性：export type X509CertRawData = cert.EncodingBlob;<br>旧版本信息：|类名：socket;<br>方法or属性：export type X509CertRawData = cert.EncodingBlob;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：socket;<br>方法or属性：function constructUDPSocketInstance(): UDPSocket;<br>旧版本信息：|类名：socket;<br>方法or属性：function constructUDPSocketInstance(): UDPSocket;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：socket;<br>方法or属性：function constructTCPSocketInstance(): TCPSocket;<br>旧版本信息：|类名：socket;<br>方法or属性：function constructTCPSocketInstance(): TCPSocket;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：socket;<br>方法or属性：function constructTLSSocketInstance(): TLSSocket;<br>旧版本信息：|类名：socket;<br>方法or属性：function constructTLSSocketInstance(): TLSSocket;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSendOptions;<br>方法or属性：export interface UDPSendOptions<br>旧版本信息：|类名：UDPSendOptions;<br>方法or属性：export interface UDPSendOptions<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>旧版本信息：|类名：UDPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>旧版本信息：|类名：TCPSendOptions;<br>方法or属性：data: string \| ArrayBuffer;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSendOptions;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：UDPSendOptions;<br>方法or属性：address: NetAddress;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPConnectOptions;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：TCPConnectOptions;<br>方法or属性：address: NetAddress;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSConnectOptions;<br>方法or属性：address: NetAddress;<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：address: NetAddress;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：ExtraOptionsBase;<br>方法or属性：export interface ExtraOptionsBase<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：export interface ExtraOptionsBase<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：ExtraOptionsBase;<br>方法or属性：receiveBufferSize?: number;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：receiveBufferSize?: number;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：ExtraOptionsBase;<br>方法or属性：sendBufferSize?: number;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：sendBufferSize?: number;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：ExtraOptionsBase;<br>方法or属性：reuseAddress?: boolean;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：reuseAddress?: boolean;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：ExtraOptionsBase;<br>方法or属性：socketTimeout?: number;<br>旧版本信息：|类名：ExtraOptionsBase;<br>方法or属性：socketTimeout?: number;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPExtraOptions;<br>方法or属性：export interface UDPExtraOptions<br>旧版本信息：|类名：UDPExtraOptions;<br>方法or属性：export interface UDPExtraOptions<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPExtraOptions;<br>方法or属性：broadcast?: boolean;<br>旧版本信息：|类名：UDPExtraOptions;<br>方法or属性：broadcast?: boolean;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：SocketStateBase;<br>方法or属性：export interface SocketStateBase<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：export interface SocketStateBase<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：SocketStateBase;<br>方法or属性：isBound: boolean;<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：isBound: boolean;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：SocketStateBase;<br>方法or属性：isClose: boolean;<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：isClose: boolean;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：SocketStateBase;<br>方法or属性：isConnected: boolean;<br>旧版本信息：|类名：SocketStateBase;<br>方法or属性：isConnected: boolean;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：SocketRemoteInfo;<br>方法or属性：export interface SocketRemoteInfo<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：export interface SocketRemoteInfo<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：SocketRemoteInfo;<br>方法or属性：address: string;<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：address: string;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：SocketRemoteInfo;<br>方法or属性：family: 'IPv4' \| 'IPv6';<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：family: 'IPv4' \| 'IPv6';<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：SocketRemoteInfo;<br>方法or属性：port: number;<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：port: number;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：SocketRemoteInfo;<br>方法or属性：size: number;<br>旧版本信息：|类名：SocketRemoteInfo;<br>方法or属性：size: number;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：export interface UDPSocket<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：export interface UDPSocket<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：bind(address: NetAddress): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：send(options: UDPSendOptions): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：close(callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：close(): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：close(): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getState(callback: AsyncCallback\<SocketStateBase>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getState(): Promise\<SocketStateBase>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：setExtraOptions(options: UDPExtraOptions): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：on(type: 'message', callback: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：on(type: 'listening' \| 'close', callback: Callback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：on(type: 'listening' \| 'close', callback: Callback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：off(type: 'message', callback?: Callback\<{ message: ArrayBuffer, remoteInfo: SocketRemoteInfo }>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：off(type: 'listening' \| 'close', callback?: Callback\<void>): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：off(type: 'listening' \| 'close', callback?: Callback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：UDPSocket;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;<br>旧版本信息：|类名：UDPSocket;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPConnectOptions;<br>方法or属性：export interface TCPConnectOptions<br>旧版本信息：|类名：TCPConnectOptions;<br>方法or属性：export interface TCPConnectOptions<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPConnectOptions;<br>方法or属性：timeout?: number;<br>旧版本信息：|类名：TCPConnectOptions;<br>方法or属性：timeout?: number;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSendOptions;<br>方法or属性：export interface TCPSendOptions<br>旧版本信息：|类名：TCPSendOptions;<br>方法or属性：export interface TCPSendOptions<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSendOptions;<br>方法or属性：encoding?: string;<br>旧版本信息：|类名：TCPSendOptions;<br>方法or属性：encoding?: string;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPExtraOptions;<br>方法or属性：export interface TCPExtraOptions<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：export interface TCPExtraOptions<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPExtraOptions;<br>方法or属性：keepAlive?: boolean;<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：keepAlive?: boolean;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPExtraOptions;<br>方法or属性：OOBInline?: boolean;<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：OOBInline?: boolean;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPExtraOptions;<br>方法or属性：TCPNoDelay?: boolean;<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：TCPNoDelay?: boolean;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPExtraOptions;<br>方法or属性：socketLinger?: { on: boolean, linger: number };<br>旧版本信息：|类名：TCPExtraOptions;<br>方法or属性：socketLinger?: { on: boolean, linger: number };<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：export interface TCPSocket<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：export interface TCPSocket<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：connect(options: TCPConnectOptions): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：send(options: TCPSendOptions): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getRemoteAddress(callback: AsyncCallback\<NetAddress>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getRemoteAddress(): Promise\<NetAddress>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：setExtraOptions(options: TCPExtraOptions): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：on(type: 'connect' \| 'close', callback: Callback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：on(type: 'connect' \| 'close', callback: Callback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：on(type: 'connect' \| 'close', callback: Callback\<void>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：on(type: 'connect' \| 'close', callback: Callback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TCPSocket;<br>方法or属性：off(type: 'connect' \| 'close', callback?: Callback\<void>): void;<br>旧版本信息：|类名：TCPSocket;<br>方法or属性：off(type: 'connect' \| 'close', callback?: Callback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：off(type: 'connect' \| 'close', callback?: Callback\<void>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：off(type: 'connect' \| 'close', callback?: Callback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：export interface TLSSocket<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：export interface TLSSocket<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getCertificate(callback: AsyncCallback\<X509CertRawData>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getCertificate(callback: AsyncCallback\<X509CertRawData>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getCertificate(): Promise\<X509CertRawData>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(callback: AsyncCallback\<X509CertRawData>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(callback: AsyncCallback\<X509CertRawData>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getRemoteCertificate(): Promise\<X509CertRawData>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getProtocol(callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getProtocol(callback: AsyncCallback\<string>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getProtocol(): Promise\<string>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getProtocol(): Promise\<string>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getCipherSuite(callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getCipherSuite(callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getCipherSuite(): Promise\<Array\<string>>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(callback: AsyncCallback\<Array\<string>>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：getSignatureAlgorithms(): Promise\<Array\<string>>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：connect(options: TLSConnectOptions): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：send(data: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：send(data: string, callback: AsyncCallback\<void>): void;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSocket;<br>方法or属性：send(data: string): Promise\<void>;<br>旧版本信息：|类名：TLSSocket;<br>方法or属性：send(data: string): Promise\<void>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSecureOptions;<br>方法or属性：export interface TLSSecureOptions<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：export interface TLSSecureOptions<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSecureOptions;<br>方法or属性：ca: string \| Array\<string>;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：ca: string \| Array\<string>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSecureOptions;<br>方法or属性：cert?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：cert?: string;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSecureOptions;<br>方法or属性：key?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：key?: string;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSecureOptions;<br>方法or属性：password?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：password?: string;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSecureOptions;<br>方法or属性：protocols?: Protocol \| Array\<Protocol>;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：protocols?: Protocol \| Array\<Protocol>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSecureOptions;<br>方法or属性：useRemoteCipherPrefer?: boolean;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：useRemoteCipherPrefer?: boolean;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSecureOptions;<br>方法or属性：signatureAlgorithms?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：signatureAlgorithms?: string;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSSecureOptions;<br>方法or属性：cipherSuite?: string;<br>旧版本信息：|类名：TLSSecureOptions;<br>方法or属性：cipherSuite?: string;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSConnectOptions;<br>方法or属性：export interface TLSConnectOptions<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：export interface TLSConnectOptions<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSConnectOptions;<br>方法or属性：secureOptions: TLSSecureOptions;<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：secureOptions: TLSSecureOptions;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：TLSConnectOptions;<br>方法or属性：ALPNProtocols?: Array\<string>;<br>旧版本信息：|类名：TLSConnectOptions;<br>方法or属性：ALPNProtocols?: Array\<string>;<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：Protocol;<br>方法or属性：export enum Protocol<br>旧版本信息：|类名：Protocol;<br>方法or属性：export enum Protocol<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：Protocol;<br>方法or属性：TLSv12 = "TLSv1.2"<br>旧版本信息：|类名：Protocol;<br>方法or属性：TLSv12 = "TLSv1.2"<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：Protocol;<br>方法or属性：TLSv13 = "TLSv1.3"<br>旧版本信息：|类名：Protocol;<br>方法or属性：TLSv13 = "TLSv1.3"<br>新版本信息：crossplatform|@ohos.net.socket.d.ts|
|跨平台能力有变化|类名：webSocket;<br>方法or属性：declare webSocket<br>旧版本信息：|类名：webSocket;<br>方法or属性：declare webSocket<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：webSocket;<br>方法or属性：function createWebSocket(): WebSocket;<br>旧版本信息：|类名：webSocket;<br>方法or属性：function createWebSocket(): WebSocket;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocketRequestOptions;<br>方法or属性：export interface WebSocketRequestOptions<br>旧版本信息：|类名：WebSocketRequestOptions;<br>方法or属性：export interface WebSocketRequestOptions<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocketRequestOptions;<br>方法or属性：header?: Object;<br>旧版本信息：|类名：WebSocketRequestOptions;<br>方法or属性：header?: Object;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocketCloseOptions;<br>方法or属性：export interface WebSocketCloseOptions<br>旧版本信息：|类名：WebSocketCloseOptions;<br>方法or属性：export interface WebSocketCloseOptions<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocketCloseOptions;<br>方法or属性：code?: number;<br>旧版本信息：|类名：WebSocketCloseOptions;<br>方法or属性：code?: number;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocketCloseOptions;<br>方法or属性：reason?: string;<br>旧版本信息：|类名：WebSocketCloseOptions;<br>方法or属性：reason?: string;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：export interface WebSocket<br>旧版本信息：|类名：WebSocket;<br>方法or属性：export interface WebSocket<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：connect(url: string, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options: WebSocketRequestOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：connect(url: string, options?: WebSocketRequestOptions): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer, callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：send(data: string \| ArrayBuffer): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：close(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options: WebSocketCloseOptions, callback: AsyncCallback\<boolean>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：close(options?: WebSocketCloseOptions): Promise\<boolean>;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：on(type: 'open', callback: AsyncCallback\<Object>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：on(type: 'open', callback: AsyncCallback\<Object>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：on(type: 'message', callback: AsyncCallback\<string \| ArrayBuffer>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：on(type: 'message', callback: AsyncCallback\<string \| ArrayBuffer>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：on(type: 'close', callback: AsyncCallback\<CloseResult>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：on(type: 'close', callback: AsyncCallback\<CloseResult>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：on(type: 'error', callback: ErrorCallback): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：off(type: 'open', callback?: AsyncCallback\<Object>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：off(type: 'open', callback?: AsyncCallback\<Object>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：off(type: 'message', callback?: AsyncCallback\<string \| ArrayBuffer>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：off(type: 'message', callback?: AsyncCallback\<string \| ArrayBuffer>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：off(type: 'close', callback?: AsyncCallback\<CloseResult>): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：off(type: 'close', callback?: AsyncCallback\<CloseResult>): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
|跨平台能力有变化|类名：WebSocket;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;<br>旧版本信息：|类名：WebSocket;<br>方法or属性：off(type: 'error', callback?: ErrorCallback): void;<br>新版本信息：crossplatform|@ohos.net.webSocket.d.ts|
