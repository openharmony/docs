# Bluetooth Subsystem ChangeLog

## cl.bluetooth.1 API Migration to @ohos.bluetoothManager.d.ts

**@ohos.bluetooth.d.ts** does not allow for throwing error codes, which is required by API version 9 and system APIs. Therefore, all APIs of **@ohos.bluetooth.d.ts** are migrated to the newly added **@ohos.bluetoothManager.d.ts**, and error code description is also added.

To use Bluetooth APIs, import **@ohos.bluetoothManager**.

  ```ts
  import bluetoothManager from '@ohos.bluetoothManager';
  ```


**Change Impacts**

System APIs and APIs in API version 9 are affected. Import **@ohos.bluetoothManager** to use APIs that can throw error codes.

  ```ts
  import bluetoothManager from '@ohos.bluetoothManager';
  ```

**Key API/Component Changes**

| Class                        | Original API                                                      | New API                                                      | Change Type                                                    |
| ---------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| bluetooth                    | function getState(): BluetoothState                          | function getState(): BluetoothState                          | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | method                                                       | function getBtConnectionState(): ProfileConnectionState;     | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function pairDevice(deviceId: string): boolean               | function pairDevice(deviceId: string): void                  | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| bluetooth                    | function cancelPairedDevice(deviceId: string): boolean       | function cancelPairedDevice(deviceId: string): void          | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| bluetooth                    | function getRemoteDeviceName(deviceId: string): string       | function getRemoteDeviceName(deviceId: string): string       | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function getRemoteDeviceClass(deviceId: string): DeviceClass | function getRemoteDeviceClass(deviceId: string): DeviceClass | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function enableBluetooth(): boolean                          | function enableBluetooth(): void                             | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| bluetooth                    | function disableBluetooth(): boolean                         | function disableBluetooth(): void                            | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| bluetooth                    | function getLocalName(): string                              | function getLocalName(): string                              | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function getPairedDevices(): Array&lt;string&gt;;            | function getPairedDevices(): Array&lt;string&gt;;            | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function getProfileConnState(profileId: ProfileId): ProfileConnectionState | function getProfileConnectionState(profileId: ProfileId): ProfileConnectionState | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the API name to **getProfileConnectionState**.|
| bluetooth                    | function setDevicePairingConfirmation(device: string, accept: boolean): boolean | function setDevicePairingConfirmation(device: string, accept: boolean): void | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| bluetooth                    | function setLocalName(name: string): boolean;                | function setLocalName(name: string): void;                   | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| bluetooth                    | function setBluetoothScanMode(mode: ScanMode, duration: number): boolean | function setBluetoothScanMode(mode: ScanMode, duration: number): void | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| bluetooth                    | function getBluetoothScanMode(): ScanMod                     | function getBluetoothScanMode(): ScanMode                    | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function startBluetoothDiscovery(): boolean                  | function startBluetoothDiscovery(): void                     | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**, added the **ohos.permission.APPROXIMATELY_LOCATION** permission, and changed the return value to **void**.|
| bluetooth                    | function stopBluetoothDiscovery(): boolean;                  | function stopBluetoothDiscovery(): void;                     | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| bluetooth                    | function on(type: "bluetoothDeviceFind", callback: Callback&lt;Array&lt;string&gt;&gt;): void; | function on(type: "bluetoothDeviceFind", callback: Callback&lt;Array&lt;string&gt;&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function off(type: "bluetoothDeviceFind", callback?: Callback&lt;Array&lt;string&gt;&gt;): void; | function off(type: "bluetoothDeviceFind", callback?: Callback&lt;Array&lt;string&gt;&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function on(type: "bondStateChange", callback: Callback&lt;BondStateParam&gt;): void; | function on(type: "bondStateChange", callback: Callbackk&lt;BondStateParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function off(type: "bondStateChange", callback?: Callback&lt;BondStateParam&gt;): void; | function off(type: "bondStateChange", callback?: Callback&lt;BondStateParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function on(type: "pinRequired", callback: Callback&lt;PinRequiredParam&gt;): void; | function on(type: "pinRequired", callback: Callback&lt;PinRequiredParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function off(type: "pinRequired", callback?: Callback&lt;PinRequiredParam&gt;): void; | function off(type: "pinRequired", callback?: Callback&lt;PinRequiredParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function on(type: "stateChange", callback: Callback&lt;BluetoothState&gt;): void; | function on(type: "stateChange", callback: Callback&lt;BluetoothState&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function off(type: "stateChange", callback?: Callback&lt;BluetoothState&gt;): void; | function off(type: "stateChange", callback?: Callback&lt;BluetoothState&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function sppListen(name: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void; | function sppListen(name: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void; | function sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function sppConnect(device: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void; | function sppConnect(device: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function sppCloseServerSocket(socket: number): void;         | function sppCloseServerSocket(socket: number): void;         | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function sppCloseClientSocket(socket: number): void;         | function sppCloseClientSocket(socket: number): void;         | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function sppWrite(clientSocket: number, data: ArrayBuffer): boolean; | function sppWrite(clientSocket: number, data: ArrayBuffer): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| bluetooth                    | function on(type: "sppRead", clientSocket: number, callback: Callback&lt;ArrayBuffer&gt;): void; | function on(type: "sppRead", clientSocket: number, callback: Callback&lt;ArrayBuffer&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.           |
| bluetooth                    | function off(type: "sppRead", clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void; | function off(type: "sppRead", clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| bluetooth                    | function getProfile(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile;                                | function getProfileInstance(profileId: ProfileId): A2dpSourceProfile |
| bluetooth                    | function getProfileInst(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile                                 | HidHostProfile                                               |
| BaseProfile                  | getConnectionDevices(): Array&lt;string&gt;;                 | getConnectionDevices(): Array&lt;string&gt;;                 | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| BaseProfile                  | getDeviceState(device: string): ProfileConnectionState;      | getDeviceState(device: string): ProfileConnectionState;      | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| A2dpSourceProfile            | connect(device: string): boolean;                            | connect(device: string): void;                               | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| A2dpSourceProfile            | disconnect(device: string): boolean;                         | disconnect(device: string): void;                            | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| A2dpSourceProfile            | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| A2dpSourceProfile            | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| A2dpSourceProfile            | getPlayingState(device: string): PlayingState;               | getPlayingState(device: string): PlayingState;               | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| HandsFreeAudioGatewayProfile | connect(device: string): boolean;                            | connect(device: string): void;                               | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| HandsFreeAudioGatewayProfile | disconnect(device: string): boolean;                         | disconnect(device: string): void;                            | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| HandsFreeAudioGatewayProfile | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| HandsFreeAudioGatewayProfile | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| HidHostProfile               | connect(device: string): boolean;                            | connect(device: string): void;                               | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| HidHostProfile               | disconnect(device: string): boolean;                         | disconnect(device: string): void;                            | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| HidHostProfile               | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| HidHostProfile               | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| PanProfile                   | disconnect(device: string): boolean;                         | disconnect(device: string): void;                            | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| PanProfile                   | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | on(type: "connectionStateChange", callback: Callback&lt;StateChangeParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| PanProfile                   | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | off(type: "connectionStateChange", callback?: Callback&lt;StateChangeParam&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| PanProfile                   | setTethering(enable: boolean): void;                         | setTethering(enable: boolean): void;                         | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| PanProfile                   | isTetheringOn(): boolean;                                    | isTetheringOn(): boolean;                                    | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| BLE                          | function createGattServer(): GattServer;                     | function createGattServer(): GattServer;                     | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| BLE                          | function createGattClientDevice(deviceId: string): GattClientDevice; | function createGattClientDevice(deviceId: string): GattClientDevice; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| BLE                          | function getConnectedBLEDevices(): Array&lt;string&gt;;      | function getConnectedBLEDevices(): Array&lt;string&gt;;      | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| BLE                          | function startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void; | function startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and added the **ohos.permission.APPROXIMATELY_LOCATION** permission.|
| BLE                          | function stopBLEScan(): void;                                | function stopBLEScan(): void;                                | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| BLE                          | mefunction on(type: "BLEDeviceFind", callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void;thod | function on(type: "BLEDeviceFind", callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| BLE                          | function off(type: "BLEDeviceFind", callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void; | function off(type: "BLEDeviceFind", callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| GattServer                   | startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void; | startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| GattServer                   | stopAdvertising(): void;                                     | stopAdvertising(): void;                                     | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.             |
| GattServer                   | addService(service: GattService): boolean;                   | addService(service: GattService): void;                      | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| GattServer                   | removeService(serviceUuid: string): boolean;                 | removeService(serviceUuid: string): void;                    | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**.|
| GattServer | close(): void; | close(): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**.
| GattServer | notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean; | notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**. |
| GattServer | sendResponse(serverResponse: ServerResponse): boolean; | sendResponse(serverResponse: ServerResponse): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**. |
| GattServer | on(type: "characteristicRead", callback: Callback&lt;CharacteristicReadReq&gt;): void; | on(type: "characteristicRead", callback: Callback&lt;CharacteristicReadRequest&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattServer | off(type: "characteristicRead", callback?: Callback&lt;CharacteristicReadReq&gt;): void; | off(type: "characteristicRead", callback?: Callback&lt;CharacteristicReadRequest&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattServer | on(type: "characteristicWrite", callback: Callback&lt;CharacteristicWriteReq&gt;): void; | on(type: "characteristicWrite", callback: Callback&lt;CharacteristicWriteRequest&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattServer | off(type: "characteristicWrite", callback?: Callback&lt;CharacteristicWriteReq&gt;): void; | off(type: "characteristicWrite", callback?: Callback&lt;CharacteristicWriteRequest&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattServer | on(type: "descriptorRead", callback: Callback&lt;DescriptorReadReq&gt;): void; | on(type: "descriptorRead", callback: Callback&lt;DescriptorReadRequest&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattServer | off(type: "descriptorRead", callback?: Callback&lt;DescriptorReadReq&gt;): void; | off(type: "descriptorRead", callback?: Callback&lt;DescriptorReadRequest&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattServer | on(type: "descriptorWrite", callback: Callback&lt;DescriptorWriteReq&gt;): void; | on(type: "descriptorWrite", callback: Callback&lt;DescriptorWriteRequest&gt;): void;| Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattServer | off(type: "descriptorWrite", callback?: Callback&lt;DescriptorWriteReq&gt;): void; | off(type: "descriptorWrite", callback?: Callback&lt;DescriptorWriteRequest&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattServer | on(type: "connectStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void; | on(type: "connectStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void;| Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattServer | off(type: "connectStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void; | off(type: "connectStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | connect(): boolean; | connect(): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**. |
| GattClientDevice | disconnect(): boolean; | disconnect(): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**. |
| GattClientDevice | close(): boolean; | close(): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**. |
| GattClientDevice | getDeviceName(callback: AsyncCallback&lt;string&gt;): void; | getDeviceName(callback: AsyncCallback&lt;string&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | getDeviceName(): Promise&lt;string&gt;; | getDeviceName(): Promise&lt;string&gt;; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void; | getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | getServices(): Promise&lt;Array&lt;GattService&gt;&gt;; | getServices(): Promise&lt;Array&lt;GattService&gt;&gt;; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void; | readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;; | readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void; | readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;; | readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | writeCharacteristicValue(characteristic: BLECharacteristic): boolean; | writeCharacteristicValue(characteristic: BLECharacteristic): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**. |
| GattClientDevice | writeDescriptorValue(descriptor: BLEDescriptor): boolean; | writeDescriptorValue(descriptor: BLEDescriptor): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**. |
| GattClientDevice | getRssiValue(callback: AsyncCallback&lt;number&gt;): void; | getRssiValue(callback: AsyncCallback&lt;number&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | getRssiValue(): Promise&lt;number&gt;; | getRssiValue(): Promise&lt;number&gt;; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | setBLEMtuSize(mtu: number): boolean; | setBLEMtuSize(mtu: number): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**. |
| GattClientDevice | setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean; | setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts** and changed the return value to **void**. |
| GattClientDevice | on(type: "BLECharacteristicChange", callback: Callback&lt;BLECharacteristic&gt;): void; | on(type: "BLECharacteristicChange", callback: Callback&lt;BLECharacteristic&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | off(type: "BLECharacteristicChange", callback?: Callback&lt;BLECharacteristic&gt;): void; | off(type: "BLECharacteristicChange", callback?: Callback&lt;BLECharacteristic&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | on(type: "BLEConnectionStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void; | on(type: "BLEConnectionStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| GattClientDevice | off(type: "BLEConnectionStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void; | off(type: "BLEConnectionStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void; | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | GattService | GattService | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | BLECharacteristic | BLECharacteristic | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | BLEDescriptor | BLEDescriptor | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | NotifyCharacteristic | NotifyCharacteristic | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | CharacteristicReadReq | CharacteristicReadRequest | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | CharacteristicWriteReq | CharacteristicWriteRequest | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | DescriptorReadRe | DescriptorReadRequest | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | DescriptorWriteReq | DescriptorWriteRequest | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ServerResponse | ServerResponse | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | BLEConnectChangedState | BLEConnectChangedState | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ScanResult | ScanResult | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | AdvertiseSetting | AdvertiseSetting | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | AdvertiseData | AdvertiseData | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ManufactureData | ManufactureData | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ServiceData | ServiceData | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ScanFilter | ScanFilter | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ScanOptions | ScanOptions | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | SppOption | SppOption | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | PinRequiredParam | PinRequiredParam | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | DeviceClass | DeviceClass | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | BondStateParam | BondStateParam | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | StateChangeParam | StateChangeParam | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ScanDuty | ScanDuty | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | MatchMode | MatchMode | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ProfileConnectionState | ProfileConnectionState | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | BluetoothState | BluetoothState | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | SppType | SppType | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ScanMode | ScanMode | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | BondState | BondState | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | MajorClass | MajorClass | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | MajorMinorClass | MajorMinorClass | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | PlayingState | PlayingState | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |
| bluetooth | ProfileId | ProfileId | Migrated this API in API version 9 to **@ohos.bluetoothManager.d.ts**. |



**(Optional) Adaptation Guide**

The following uses **enableLocation** as an example to show how it is called in the new version:

  ```ts
  import bluetoothManager from '@ohos.bluetoothManager';
  try {
      var state = bluetoothManager.getState();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```
