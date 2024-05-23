| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|SysCap changed|Class name: bluetooth;<br>API declaration:  namespace BLE<br>Differences: NA|Class name: bluetooth;<br>API declaration:  namespace BLE<br>Differences: SystemCapability.Communication.Bluetooth.Core|api/@ohos.bluetooth.d.ts|
|SysCap changed|Class name: bluetoothManager;<br>API declaration:  namespace BLE<br>Differences: NA|Class name: bluetoothManager;<br>API declaration:  namespace BLE<br>Differences: SystemCapability.Communication.Bluetooth.Core|api/@ohos.bluetoothManager.d.ts|
|SysCap changed|Class name: StartBLEScanOptions;<br>API declaration: interval: number;<br>Differences: NA|Class name: StartBLEScanOptions;<br>API declaration: interval: number;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: StartBLEScanOptions;<br>API declaration: success: () => void;<br>Differences: NA|Class name: StartBLEScanOptions;<br>API declaration: success: () => void;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: StartBLEScanOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: NA|Class name: StartBLEScanOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: StartBLEScanOptions;<br>API declaration: complete: () => void;<br>Differences: NA|Class name: StartBLEScanOptions;<br>API declaration: complete: () => void;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: StopBLEScanOptions;<br>API declaration: success: () => void;<br>Differences: NA|Class name: StopBLEScanOptions;<br>API declaration: success: () => void;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: StopBLEScanOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: NA|Class name: StopBLEScanOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: StopBLEScanOptions;<br>API declaration: complete: () => void;<br>Differences: NA|Class name: StopBLEScanOptions;<br>API declaration: complete: () => void;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: BluetoothDevice;<br>API declaration: addrType: 'public' \| 'random';<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: addrType: 'public' \| 'random';<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: BluetoothDevice;<br>API declaration: addr: string;<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: addr: string;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: BluetoothDevice;<br>API declaration: rssi: number;<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: rssi: number;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: BluetoothDevice;<br>API declaration: txpower: string;<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: txpower: string;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: BluetoothDevice;<br>API declaration: data: string;<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: data: string;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: BLEFoundResponse;<br>API declaration: devices: Array\<BluetoothDevice>;<br>Differences: NA|Class name: BLEFoundResponse;<br>API declaration: devices: Array\<BluetoothDevice>;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: SubscribeBLEFoundOptions;<br>API declaration: success: (data: BLEFoundResponse) => void;<br>Differences: NA|Class name: SubscribeBLEFoundOptions;<br>API declaration: success: (data: BLEFoundResponse) => void;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|SysCap changed|Class name: SubscribeBLEFoundOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: NA|Class name: SubscribeBLEFoundOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetooth;<br>API declaration:  namespace BLE<br>Differences: NA|Class name: bluetooth;<br>API declaration:  namespace BLE<br>Differences: 9|api/@ohos.bluetooth.d.ts|
|Deprecated version changed|Class name: bluetoothManager;<br>API declaration:  namespace BLE<br>Differences: NA|Class name: bluetoothManager;<br>API declaration:  namespace BLE<br>Differences: 10|api/@ohos.bluetoothManager.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function startAdvertising(advertisingParams: AdvertisingParams, callback: AsyncCallback\<number>): void;<br>Differences: function startAdvertising(advertisingParams: AdvertisingParams, callback: AsyncCallback\<number>): void;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function startAdvertising(advertisingParams: AdvertisingParams): Promise\<number>;<br>Differences: function startAdvertising(advertisingParams: AdvertisingParams): Promise\<number>;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function stopAdvertising(advertisingId: number, callback: AsyncCallback\<void>): void;<br>Differences: function stopAdvertising(advertisingId: number, callback: AsyncCallback\<void>): void;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function stopAdvertising(advertisingId: number): Promise\<void>;<br>Differences: function stopAdvertising(advertisingId: number): Promise\<void>;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: a2dp;<br>API declaration:  interface CodecInfo<br>Differences:  interface CodecInfo|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecInfo;<br>API declaration: codecType: CodecType;<br>Differences: codecType: CodecType;|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecInfo;<br>API declaration: codecBitsPerSample: CodecBitsPerSample;<br>Differences: codecBitsPerSample: CodecBitsPerSample;|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecInfo;<br>API declaration: codecChannelMode: CodecChannelMode;<br>Differences: codecChannelMode: CodecChannelMode;|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecInfo;<br>API declaration: codecSampleRate: CodecSampleRate;<br>Differences: codecSampleRate: CodecSampleRate;|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: a2dp;<br>API declaration:  enum CodecType<br>Differences:  enum CodecType|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecType;<br>API declaration: CODEC_TYPE_INVALID = -1<br>Differences: CODEC_TYPE_INVALID = -1|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecType;<br>API declaration: CODEC_TYPE_SBC = 0<br>Differences: CODEC_TYPE_SBC = 0|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecType;<br>API declaration: CODEC_TYPE_AAC = 1<br>Differences: CODEC_TYPE_AAC = 1|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecType;<br>API declaration: CODEC_TYPE_L2HC = 2<br>Differences: CODEC_TYPE_L2HC = 2|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: a2dp;<br>API declaration:  enum CodecChannelMode<br>Differences:  enum CodecChannelMode|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecChannelMode;<br>API declaration: CODEC_CHANNEL_MODE_NONE = 0<br>Differences: CODEC_CHANNEL_MODE_NONE = 0|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecChannelMode;<br>API declaration: CODEC_CHANNEL_MODE_MONO = 1<br>Differences: CODEC_CHANNEL_MODE_MONO = 1|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecChannelMode;<br>API declaration: CODEC_CHANNEL_MODE_STEREO = 2<br>Differences: CODEC_CHANNEL_MODE_STEREO = 2|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: a2dp;<br>API declaration:  enum CodecBitsPerSample<br>Differences:  enum CodecBitsPerSample|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecBitsPerSample;<br>API declaration: CODEC_BITS_PER_SAMPLE_NONE = 0<br>Differences: CODEC_BITS_PER_SAMPLE_NONE = 0|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecBitsPerSample;<br>API declaration: CODEC_BITS_PER_SAMPLE_16 = 1<br>Differences: CODEC_BITS_PER_SAMPLE_16 = 1|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecBitsPerSample;<br>API declaration: CODEC_BITS_PER_SAMPLE_24 = 2<br>Differences: CODEC_BITS_PER_SAMPLE_24 = 2|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecBitsPerSample;<br>API declaration: CODEC_BITS_PER_SAMPLE_32 = 3<br>Differences: CODEC_BITS_PER_SAMPLE_32 = 3|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: a2dp;<br>API declaration:  enum CodecSampleRate<br>Differences:  enum CodecSampleRate|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecSampleRate;<br>API declaration: CODEC_SAMPLE_RATE_NONE = 0<br>Differences: CODEC_SAMPLE_RATE_NONE = 0|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecSampleRate;<br>API declaration: CODEC_SAMPLE_RATE_44100 = 1<br>Differences: CODEC_SAMPLE_RATE_44100 = 1|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecSampleRate;<br>API declaration: CODEC_SAMPLE_RATE_48000 = 2<br>Differences: CODEC_SAMPLE_RATE_48000 = 2|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecSampleRate;<br>API declaration: CODEC_SAMPLE_RATE_88200 = 3<br>Differences: CODEC_SAMPLE_RATE_88200 = 3|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecSampleRate;<br>API declaration: CODEC_SAMPLE_RATE_96000 = 4<br>Differences: CODEC_SAMPLE_RATE_96000 = 4|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecSampleRate;<br>API declaration: CODEC_SAMPLE_RATE_176400 = 5<br>Differences: CODEC_SAMPLE_RATE_176400 = 5|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: CodecSampleRate;<br>API declaration: CODEC_SAMPLE_RATE_192000 = 6<br>Differences: CODEC_SAMPLE_RATE_192000 = 6|api/@ohos.bluetooth.a2dp.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams, callback: AsyncCallback\<void>): void;<br>Differences: function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams, callback: AsyncCallback\<void>): void;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams): Promise\<void>;<br>Differences: function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams): Promise\<void>;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams, callback: AsyncCallback\<void>): void;<br>Differences: function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams, callback: AsyncCallback\<void>): void;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams): Promise\<void>;<br>Differences: function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams): Promise\<void>;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function on(type: 'advertisingStateChange', callback: Callback\<AdvertisingStateChangeInfo>): void;<br>Differences: function on(type: 'advertisingStateChange', callback: Callback\<AdvertisingStateChangeInfo>): void;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration: function off(type: 'advertisingStateChange', callback?: Callback\<AdvertisingStateChangeInfo>): void;<br>Differences: function off(type: 'advertisingStateChange', callback?: Callback\<AdvertisingStateChangeInfo>): void;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration:  interface AdvertisingParams<br>Differences:  interface AdvertisingParams|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingParams;<br>API declaration: advertisingSettings: AdvertiseSetting;<br>Differences: advertisingSettings: AdvertiseSetting;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingParams;<br>API declaration: advertisingData: AdvertiseData;<br>Differences: advertisingData: AdvertiseData;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingParams;<br>API declaration: advertisingResponse?: AdvertiseData;<br>Differences: advertisingResponse?: AdvertiseData;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingParams;<br>API declaration: duration?: number;<br>Differences: duration?: number;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration:  interface AdvertisingEnableParams<br>Differences:  interface AdvertisingEnableParams|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingEnableParams;<br>API declaration: advertisingId: number;<br>Differences: advertisingId: number;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingEnableParams;<br>API declaration: duration?: number;<br>Differences: duration?: number;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration:  interface AdvertisingDisableParams<br>Differences:  interface AdvertisingDisableParams|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingDisableParams;<br>API declaration: advertisingId: number;<br>Differences: advertisingId: number;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration:  interface AdvertisingStateChangeInfo<br>Differences:  interface AdvertisingStateChangeInfo|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingStateChangeInfo;<br>API declaration: advertisingId: number;<br>Differences: advertisingId: number;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingStateChangeInfo;<br>API declaration: state: AdvertisingState;<br>Differences: state: AdvertisingState;|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: ble;<br>API declaration:  enum AdvertisingState<br>Differences:  enum AdvertisingState|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingState;<br>API declaration: STARTED = 1<br>Differences: STARTED = 1|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingState;<br>API declaration: ENABLED = 2<br>Differences: ENABLED = 2|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingState;<br>API declaration: DISABLED = 3<br>Differences: DISABLED = 3|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: AdvertisingState;<br>API declaration: STOPPED = 4<br>Differences: STOPPED = 4|api/@ohos.bluetooth.ble.d.ts|
|API added|NA|Class name: connection;<br>API declaration: function getPairState(deviceId: string): BondState;<br>Differences: function getPairState(deviceId: string): BondState;|api/@ohos.bluetooth.connection.d.ts|
|API added|NA|Class name: connection;<br>API declaration: function isBluetoothDiscovering(): boolean;<br>Differences: function isBluetoothDiscovering(): boolean;|api/@ohos.bluetooth.connection.d.ts|
|API added|NA|Class name: global;<br>API declaration:  declare namespace map<br>Differences:  declare namespace map|api/@ohos.bluetooth.map.d.ts|
|API added|NA|Class name: map;<br>API declaration: type BaseProfile = baseProfile.BaseProfile;<br>Differences: type BaseProfile = baseProfile.BaseProfile;|api/@ohos.bluetooth.map.d.ts|
|API added|NA|Class name: map;<br>API declaration: function createMapMseProfile(): MapMseProfile;<br>Differences: function createMapMseProfile(): MapMseProfile;|api/@ohos.bluetooth.map.d.ts|
|API added|NA|Class name: map;<br>API declaration:  interface MapMseProfile<br>Differences:  interface MapMseProfile|api/@ohos.bluetooth.map.d.ts|
|API added|NA|Class name: global;<br>API declaration:  declare namespace pbap<br>Differences:  declare namespace pbap|api/@ohos.bluetooth.pbap.d.ts|
|API added|NA|Class name: pbap;<br>API declaration: type BaseProfile = baseProfile.BaseProfile;<br>Differences: type BaseProfile = baseProfile.BaseProfile;|api/@ohos.bluetooth.pbap.d.ts|
|API added|NA|Class name: pbap;<br>API declaration: function createPbapServerProfile(): PbapServerProfile;<br>Differences: function createPbapServerProfile(): PbapServerProfile;|api/@ohos.bluetooth.pbap.d.ts|
|API added|NA|Class name: pbap;<br>API declaration:  interface PbapServerProfile<br>Differences:  interface PbapServerProfile|api/@ohos.bluetooth.pbap.d.ts|
|API added|NA|Class name: global;<br>API declaration:  declare namespace wearDetection<br>Differences:  declare namespace wearDetection|api/@ohos.bluetooth.wearDetection.d.ts|
|Initial version changed|Class name: bluetooth;<br>API declaration:  namespace BLE<br>Differences: NA|Class name: bluetooth;<br>API declaration:  namespace BLE<br>Differences: 7|api/@ohos.bluetooth.d.ts|
|Initial version changed|Class name: bluetoothManager;<br>API declaration:  namespace BLE<br>Differences: NA|Class name: bluetoothManager;<br>API declaration:  namespace BLE<br>Differences: 9|api/@ohos.bluetoothManager.d.ts|
|Initial version changed|Class name: StartBLEScanOptions;<br>API declaration: interval: number;<br>Differences: NA|Class name: StartBLEScanOptions;<br>API declaration: interval: number;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: StartBLEScanOptions;<br>API declaration: success: () => void;<br>Differences: NA|Class name: StartBLEScanOptions;<br>API declaration: success: () => void;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: StartBLEScanOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: NA|Class name: StartBLEScanOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: StartBLEScanOptions;<br>API declaration: complete: () => void;<br>Differences: NA|Class name: StartBLEScanOptions;<br>API declaration: complete: () => void;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: StopBLEScanOptions;<br>API declaration: success: () => void;<br>Differences: NA|Class name: StopBLEScanOptions;<br>API declaration: success: () => void;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: StopBLEScanOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: NA|Class name: StopBLEScanOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: StopBLEScanOptions;<br>API declaration: complete: () => void;<br>Differences: NA|Class name: StopBLEScanOptions;<br>API declaration: complete: () => void;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: BluetoothDevice;<br>API declaration: addrType: 'public' \| 'random';<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: addrType: 'public' \| 'random';<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: BluetoothDevice;<br>API declaration: addr: string;<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: addr: string;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: BluetoothDevice;<br>API declaration: rssi: number;<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: rssi: number;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: BluetoothDevice;<br>API declaration: txpower: string;<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: txpower: string;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: BluetoothDevice;<br>API declaration: data: string;<br>Differences: NA|Class name: BluetoothDevice;<br>API declaration: data: string;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: BLEFoundResponse;<br>API declaration: devices: Array\<BluetoothDevice>;<br>Differences: NA|Class name: BLEFoundResponse;<br>API declaration: devices: Array\<BluetoothDevice>;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: SubscribeBLEFoundOptions;<br>API declaration: success: (data: BLEFoundResponse) => void;<br>Differences: NA|Class name: SubscribeBLEFoundOptions;<br>API declaration: success: (data: BLEFoundResponse) => void;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Initial version changed|Class name: SubscribeBLEFoundOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: NA|Class name: SubscribeBLEFoundOptions;<br>API declaration: fail: (data: string, code: number) => void;<br>Differences: 6|api/@system.bluetooth.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.a2dp.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.access.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.baseProfile.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.ble.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.connection.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.constant.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.hfp.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.hid.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.pan.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetooth.socket.d.ts|
|Kit changed|NA|ConnectivityKit|api/@ohos.bluetoothManager.d.ts|
|Kit changed|NA|ConnectivityKit|api/@system.bluetooth.d.ts|
