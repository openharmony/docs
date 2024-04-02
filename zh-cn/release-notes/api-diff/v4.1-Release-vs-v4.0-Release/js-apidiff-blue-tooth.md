| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|syscap变更|类名：bluetooth；<br>API声明： namespace BLE<br>差异内容：NA|类名：bluetooth；<br>API声明： namespace BLE<br>差异内容：SystemCapability.Communication.Bluetooth.Core|api/@ohos.bluetooth.d.ts|
|syscap变更|类名：bluetoothManager；<br>API声明： namespace BLE<br>差异内容：NA|类名：bluetoothManager；<br>API声明： namespace BLE<br>差异内容：SystemCapability.Communication.Bluetooth.Core|api/@ohos.bluetoothManager.d.ts|
|syscap变更|类名：StartBLEScanOptions；<br>API声明：interval: number;<br>差异内容：NA|类名：StartBLEScanOptions；<br>API声明：interval: number;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：StartBLEScanOptions；<br>API声明：success: () => void;<br>差异内容：NA|类名：StartBLEScanOptions；<br>API声明：success: () => void;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：StartBLEScanOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：NA|类名：StartBLEScanOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：StartBLEScanOptions；<br>API声明：complete: () => void;<br>差异内容：NA|类名：StartBLEScanOptions；<br>API声明：complete: () => void;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：StopBLEScanOptions；<br>API声明：success: () => void;<br>差异内容：NA|类名：StopBLEScanOptions；<br>API声明：success: () => void;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：StopBLEScanOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：NA|类名：StopBLEScanOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：StopBLEScanOptions；<br>API声明：complete: () => void;<br>差异内容：NA|类名：StopBLEScanOptions；<br>API声明：complete: () => void;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：BluetoothDevice；<br>API声明：addrType: 'public' \| 'random';<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：addrType: 'public' \| 'random';<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：BluetoothDevice；<br>API声明：addr: string;<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：addr: string;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：BluetoothDevice；<br>API声明：rssi: number;<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：rssi: number;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：BluetoothDevice；<br>API声明：txpower: string;<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：txpower: string;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：BluetoothDevice；<br>API声明：data: string;<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：data: string;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：BLEFoundResponse；<br>API声明：devices: Array\<BluetoothDevice>;<br>差异内容：NA|类名：BLEFoundResponse；<br>API声明：devices: Array\<BluetoothDevice>;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：SubscribeBLEFoundOptions；<br>API声明：success: (data: BLEFoundResponse) => void;<br>差异内容：NA|类名：SubscribeBLEFoundOptions；<br>API声明：success: (data: BLEFoundResponse) => void;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|syscap变更|类名：SubscribeBLEFoundOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：NA|类名：SubscribeBLEFoundOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：SystemCapability.Communication.Bluetooth.Lite|api/@system.bluetooth.d.ts|
|API废弃版本变更|类名：bluetooth；<br>API声明： namespace BLE<br>差异内容：NA|类名：bluetooth；<br>API声明： namespace BLE<br>差异内容：9|api/@ohos.bluetooth.d.ts|
|API废弃版本变更|类名：bluetoothManager；<br>API声明： namespace BLE<br>差异内容：NA|类名：bluetoothManager；<br>API声明： namespace BLE<br>差异内容：10|api/@ohos.bluetoothManager.d.ts|
|新增API|NA|类名：ble；<br>API声明：function startAdvertising(advertisingParams: AdvertisingParams, callback: AsyncCallback\<number>): void;<br>差异内容：function startAdvertising(advertisingParams: AdvertisingParams, callback: AsyncCallback\<number>): void;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明：function startAdvertising(advertisingParams: AdvertisingParams): Promise\<number>;<br>差异内容：function startAdvertising(advertisingParams: AdvertisingParams): Promise\<number>;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明：function stopAdvertising(advertisingId: number, callback: AsyncCallback\<void>): void;<br>差异内容：function stopAdvertising(advertisingId: number, callback: AsyncCallback\<void>): void;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明：function stopAdvertising(advertisingId: number): Promise\<void>;<br>差异内容：function stopAdvertising(advertisingId: number): Promise\<void>;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：a2dp；<br>API声明： interface CodecInfo<br>差异内容： interface CodecInfo|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecInfo；<br>API声明：codecType: CodecType;<br>差异内容：codecType: CodecType;|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecInfo；<br>API声明：codecBitsPerSample: CodecBitsPerSample;<br>差异内容：codecBitsPerSample: CodecBitsPerSample;|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecInfo；<br>API声明：codecChannelMode: CodecChannelMode;<br>差异内容：codecChannelMode: CodecChannelMode;|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecInfo；<br>API声明：codecSampleRate: CodecSampleRate;<br>差异内容：codecSampleRate: CodecSampleRate;|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：a2dp；<br>API声明： enum CodecType<br>差异内容： enum CodecType|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecType；<br>API声明：CODEC_TYPE_INVALID = -1<br>差异内容：CODEC_TYPE_INVALID = -1|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecType；<br>API声明：CODEC_TYPE_SBC = 0<br>差异内容：CODEC_TYPE_SBC = 0|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecType；<br>API声明：CODEC_TYPE_AAC = 1<br>差异内容：CODEC_TYPE_AAC = 1|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecType；<br>API声明：CODEC_TYPE_L2HC = 2<br>差异内容：CODEC_TYPE_L2HC = 2|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：a2dp；<br>API声明： enum CodecChannelMode<br>差异内容： enum CodecChannelMode|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecChannelMode；<br>API声明：CODEC_CHANNEL_MODE_NONE = 0<br>差异内容：CODEC_CHANNEL_MODE_NONE = 0|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecChannelMode；<br>API声明：CODEC_CHANNEL_MODE_MONO = 1<br>差异内容：CODEC_CHANNEL_MODE_MONO = 1|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecChannelMode；<br>API声明：CODEC_CHANNEL_MODE_STEREO = 2<br>差异内容：CODEC_CHANNEL_MODE_STEREO = 2|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：a2dp；<br>API声明： enum CodecBitsPerSample<br>差异内容： enum CodecBitsPerSample|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecBitsPerSample；<br>API声明：CODEC_BITS_PER_SAMPLE_NONE = 0<br>差异内容：CODEC_BITS_PER_SAMPLE_NONE = 0|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecBitsPerSample；<br>API声明：CODEC_BITS_PER_SAMPLE_16 = 1<br>差异内容：CODEC_BITS_PER_SAMPLE_16 = 1|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecBitsPerSample；<br>API声明：CODEC_BITS_PER_SAMPLE_24 = 2<br>差异内容：CODEC_BITS_PER_SAMPLE_24 = 2|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecBitsPerSample；<br>API声明：CODEC_BITS_PER_SAMPLE_32 = 3<br>差异内容：CODEC_BITS_PER_SAMPLE_32 = 3|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：a2dp；<br>API声明： enum CodecSampleRate<br>差异内容： enum CodecSampleRate|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecSampleRate；<br>API声明：CODEC_SAMPLE_RATE_NONE = 0<br>差异内容：CODEC_SAMPLE_RATE_NONE = 0|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecSampleRate；<br>API声明：CODEC_SAMPLE_RATE_44100 = 1<br>差异内容：CODEC_SAMPLE_RATE_44100 = 1|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecSampleRate；<br>API声明：CODEC_SAMPLE_RATE_48000 = 2<br>差异内容：CODEC_SAMPLE_RATE_48000 = 2|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecSampleRate；<br>API声明：CODEC_SAMPLE_RATE_88200 = 3<br>差异内容：CODEC_SAMPLE_RATE_88200 = 3|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecSampleRate；<br>API声明：CODEC_SAMPLE_RATE_96000 = 4<br>差异内容：CODEC_SAMPLE_RATE_96000 = 4|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecSampleRate；<br>API声明：CODEC_SAMPLE_RATE_176400 = 5<br>差异内容：CODEC_SAMPLE_RATE_176400 = 5|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：CodecSampleRate；<br>API声明：CODEC_SAMPLE_RATE_192000 = 6<br>差异内容：CODEC_SAMPLE_RATE_192000 = 6|api/@ohos.bluetooth.a2dp.d.ts|
|新增API|NA|类名：ble；<br>API声明：function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams, callback: AsyncCallback\<void>): void;<br>差异内容：function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams, callback: AsyncCallback\<void>): void;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明：function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams): Promise\<void>;<br>差异内容：function enableAdvertising(advertisingEnableParams: AdvertisingEnableParams): Promise\<void>;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明：function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams, callback: AsyncCallback\<void>): void;<br>差异内容：function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams, callback: AsyncCallback\<void>): void;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明：function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams): Promise\<void>;<br>差异内容：function disableAdvertising(advertisingDisableParams: AdvertisingDisableParams): Promise\<void>;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明：function on(type: 'advertisingStateChange', callback: Callback\<AdvertisingStateChangeInfo>): void;<br>差异内容：function on(type: 'advertisingStateChange', callback: Callback\<AdvertisingStateChangeInfo>): void;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明：function off(type: 'advertisingStateChange', callback?: Callback\<AdvertisingStateChangeInfo>): void;<br>差异内容：function off(type: 'advertisingStateChange', callback?: Callback\<AdvertisingStateChangeInfo>): void;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明： interface AdvertisingParams<br>差异内容： interface AdvertisingParams|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingParams；<br>API声明：advertisingSettings: AdvertiseSetting;<br>差异内容：advertisingSettings: AdvertiseSetting;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingParams；<br>API声明：advertisingData: AdvertiseData;<br>差异内容：advertisingData: AdvertiseData;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingParams；<br>API声明：advertisingResponse?: AdvertiseData;<br>差异内容：advertisingResponse?: AdvertiseData;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingParams；<br>API声明：duration?: number;<br>差异内容：duration?: number;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明： interface AdvertisingEnableParams<br>差异内容： interface AdvertisingEnableParams|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingEnableParams；<br>API声明：advertisingId: number;<br>差异内容：advertisingId: number;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingEnableParams；<br>API声明：duration?: number;<br>差异内容：duration?: number;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明： interface AdvertisingDisableParams<br>差异内容： interface AdvertisingDisableParams|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingDisableParams；<br>API声明：advertisingId: number;<br>差异内容：advertisingId: number;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明： interface AdvertisingStateChangeInfo<br>差异内容： interface AdvertisingStateChangeInfo|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingStateChangeInfo；<br>API声明：advertisingId: number;<br>差异内容：advertisingId: number;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingStateChangeInfo；<br>API声明：state: AdvertisingState;<br>差异内容：state: AdvertisingState;|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：ble；<br>API声明： enum AdvertisingState<br>差异内容： enum AdvertisingState|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingState；<br>API声明：STARTED = 1<br>差异内容：STARTED = 1|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingState；<br>API声明：ENABLED = 2<br>差异内容：ENABLED = 2|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingState；<br>API声明：DISABLED = 3<br>差异内容：DISABLED = 3|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：AdvertisingState；<br>API声明：STOPPED = 4<br>差异内容：STOPPED = 4|api/@ohos.bluetooth.ble.d.ts|
|新增API|NA|类名：connection；<br>API声明：function getPairState(deviceId: string): BondState;<br>差异内容：function getPairState(deviceId: string): BondState;|api/@ohos.bluetooth.connection.d.ts|
|新增API|NA|类名：connection；<br>API声明：function isBluetoothDiscovering(): boolean;<br>差异内容：function isBluetoothDiscovering(): boolean;|api/@ohos.bluetooth.connection.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace map<br>差异内容： declare namespace map|api/@ohos.bluetooth.map.d.ts|
|新增API|NA|类名：map；<br>API声明：type BaseProfile = baseProfile.BaseProfile;<br>差异内容：type BaseProfile = baseProfile.BaseProfile;|api/@ohos.bluetooth.map.d.ts|
|新增API|NA|类名：map；<br>API声明：function createMapMseProfile(): MapMseProfile;<br>差异内容：function createMapMseProfile(): MapMseProfile;|api/@ohos.bluetooth.map.d.ts|
|新增API|NA|类名：map；<br>API声明： interface MapMseProfile<br>差异内容： interface MapMseProfile|api/@ohos.bluetooth.map.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace pbap<br>差异内容： declare namespace pbap|api/@ohos.bluetooth.pbap.d.ts|
|新增API|NA|类名：pbap；<br>API声明：type BaseProfile = baseProfile.BaseProfile;<br>差异内容：type BaseProfile = baseProfile.BaseProfile;|api/@ohos.bluetooth.pbap.d.ts|
|新增API|NA|类名：pbap；<br>API声明：function createPbapServerProfile(): PbapServerProfile;<br>差异内容：function createPbapServerProfile(): PbapServerProfile;|api/@ohos.bluetooth.pbap.d.ts|
|新增API|NA|类名：pbap；<br>API声明： interface PbapServerProfile<br>差异内容： interface PbapServerProfile|api/@ohos.bluetooth.pbap.d.ts|
|新增API|NA|类名：global；<br>API声明： declare namespace wearDetection<br>差异内容： declare namespace wearDetection|api/@ohos.bluetooth.wearDetection.d.ts|
|起始版本有变化|类名：bluetooth；<br>API声明： namespace BLE<br>差异内容：NA|类名：bluetooth；<br>API声明： namespace BLE<br>差异内容：7|api/@ohos.bluetooth.d.ts|
|起始版本有变化|类名：bluetoothManager；<br>API声明： namespace BLE<br>差异内容：NA|类名：bluetoothManager；<br>API声明： namespace BLE<br>差异内容：9|api/@ohos.bluetoothManager.d.ts|
|起始版本有变化|类名：StartBLEScanOptions；<br>API声明：interval: number;<br>差异内容：NA|类名：StartBLEScanOptions；<br>API声明：interval: number;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：StartBLEScanOptions；<br>API声明：success: () => void;<br>差异内容：NA|类名：StartBLEScanOptions；<br>API声明：success: () => void;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：StartBLEScanOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：NA|类名：StartBLEScanOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：StartBLEScanOptions；<br>API声明：complete: () => void;<br>差异内容：NA|类名：StartBLEScanOptions；<br>API声明：complete: () => void;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：StopBLEScanOptions；<br>API声明：success: () => void;<br>差异内容：NA|类名：StopBLEScanOptions；<br>API声明：success: () => void;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：StopBLEScanOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：NA|类名：StopBLEScanOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：StopBLEScanOptions；<br>API声明：complete: () => void;<br>差异内容：NA|类名：StopBLEScanOptions；<br>API声明：complete: () => void;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：BluetoothDevice；<br>API声明：addrType: 'public' \| 'random';<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：addrType: 'public' \| 'random';<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：BluetoothDevice；<br>API声明：addr: string;<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：addr: string;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：BluetoothDevice；<br>API声明：rssi: number;<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：rssi: number;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：BluetoothDevice；<br>API声明：txpower: string;<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：txpower: string;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：BluetoothDevice；<br>API声明：data: string;<br>差异内容：NA|类名：BluetoothDevice；<br>API声明：data: string;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：BLEFoundResponse；<br>API声明：devices: Array\<BluetoothDevice>;<br>差异内容：NA|类名：BLEFoundResponse；<br>API声明：devices: Array\<BluetoothDevice>;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：SubscribeBLEFoundOptions；<br>API声明：success: (data: BLEFoundResponse) => void;<br>差异内容：NA|类名：SubscribeBLEFoundOptions；<br>API声明：success: (data: BLEFoundResponse) => void;<br>差异内容：6|api/@system.bluetooth.d.ts|
|起始版本有变化|类名：SubscribeBLEFoundOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：NA|类名：SubscribeBLEFoundOptions；<br>API声明：fail: (data: string, code: number) => void;<br>差异内容：6|api/@system.bluetooth.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.a2dp.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.access.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.baseProfile.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.ble.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.connection.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.constant.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.hfp.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.hid.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.pan.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetooth.socket.d.ts|
|kit变更|NA|ConnectivityKit|api/@ohos.bluetoothManager.d.ts|
|kit变更|NA|ConnectivityKit|api/@system.bluetooth.d.ts|
