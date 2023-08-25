| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: geoLocationManager;<br>Method or attribute name: function on(type: 'locatingRequiredDataChange', config: LocatingRequiredDataConfig, callback: Callback\<Array\<LocatingRequiredData>>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: geoLocationManager;<br>Method or attribute name: function off(type: 'locatingRequiredDataChange', callback?: Callback\<Array\<LocatingRequiredData>>): void;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: geoLocationManager;<br>Method or attribute name: function getLocatingRequiredData(config: LocatingRequiredDataConfig): Promise\<Array\<LocatingRequiredData>>;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: LocatingRequiredDataConfig;<br>Method or attribute name: type: LocatingRequiredDataType;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: LocatingRequiredDataConfig;<br>Method or attribute name: needStartScan: boolean;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: LocatingRequiredDataConfig;<br>Method or attribute name: scanInterval?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: LocatingRequiredDataConfig;<br>Method or attribute name: scanTimeout?: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: LocatingRequiredData;<br>Method or attribute name: wifiData?: WifiScanInfo;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: LocatingRequiredData;<br>Method or attribute name: bluetoothData?: BluetoothScanInfo;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: WifiScanInfo;<br>Method or attribute name: ssid: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: WifiScanInfo;<br>Method or attribute name: bssid: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: WifiScanInfo;<br>Method or attribute name: rssi: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: BluetoothScanInfo;<br>Method or attribute name: rssi: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: WifiScanInfo;<br>Method or attribute name: frequency: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: WifiScanInfo;<br>Method or attribute name: timestamp: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: BluetoothScanInfo;<br>Method or attribute name: timestamp: number;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: BluetoothScanInfo;<br>Method or attribute name: deviceName: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: BluetoothScanInfo;<br>Method or attribute name: macAddress: string;|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: LocatingRequiredDataType;<br>Method or attribute name: WIFI = 1|@ohos.geoLocationManager.d.ts|
|Added|NA|Class name: LocatingRequiredDataType;<br>Method or attribute name: BLUETOOTH|@ohos.geoLocationManager.d.ts|
