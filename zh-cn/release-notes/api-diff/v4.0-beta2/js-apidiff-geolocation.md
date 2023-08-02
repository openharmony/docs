| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：geoLocationManager;<br>方法or属性：function on(type: 'locatingRequiredDataChange', config: LocatingRequiredDataConfig, callback: Callback\<Array\<LocatingRequiredData>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function off(type: 'locatingRequiredDataChange', callback?: Callback\<Array\<LocatingRequiredData>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getLocatingRequiredData(config: LocatingRequiredDataConfig): Promise\<Array\<LocatingRequiredData>>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocatingRequiredDataConfig;<br>方法or属性：type: LocatingRequiredDataType;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocatingRequiredDataConfig;<br>方法or属性：needStartScan: boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocatingRequiredDataConfig;<br>方法or属性：scanInterval?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocatingRequiredDataConfig;<br>方法or属性：scanTimeout?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocatingRequiredData;<br>方法or属性：wifiData?: WifiScanInfo;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocatingRequiredData;<br>方法or属性：bluetoothData?: BluetoothScanInfo;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：ssid: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：bssid: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：rssi: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：BluetoothScanInfo;<br>方法or属性：rssi: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：frequency: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：WifiScanInfo;<br>方法or属性：timestamp: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：BluetoothScanInfo;<br>方法or属性：timestamp: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：BluetoothScanInfo;<br>方法or属性：deviceName: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：BluetoothScanInfo;<br>方法or属性：macAddress: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocatingRequiredDataType;<br>方法or属性：WIFI = 1|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocatingRequiredDataType;<br>方法or属性：BLUETOOTH|@ohos.geoLocationManager.d.ts|
