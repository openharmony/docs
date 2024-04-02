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
|权限有变化|类名：geolocation;<br>方法or属性：function getCurrentLocation(callback: AsyncCallback\<Location>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getCurrentLocation(callback: AsyncCallback\<Location>): void;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function getCurrentLocation(request?: CurrentLocationRequest): Promise\<Location>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getCurrentLocation(request?: CurrentLocationRequest): Promise\<Location>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function getLastLocation(): Promise\<Location>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getLastLocation(): Promise\<Location>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function isLocationEnabled(): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function isLocationEnabled(): Promise\<boolean>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function requestEnableLocation(): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function requestEnableLocation(): Promise\<boolean>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise\<Array\<GeoAddress>>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise\<Array\<GeoAddress>>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest): Promise\<Array\<GeoAddress>>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest): Promise\<Array\<GeoAddress>>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function isGeoServiceAvailable(): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function isGeoServiceAvailable(): Promise\<boolean>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function getCachedGnssLocationsSize(): Promise\<number>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getCachedGnssLocationsSize(): Promise\<number>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function flushCachedGnssLocations(): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function flushCachedGnssLocations(): Promise\<boolean>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：geolocation;<br>方法or属性：function sendCommand(command: LocationCommand): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function sendCommand(command: LocationCommand): Promise\<boolean>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：latitude?: number;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：latitude?: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：longitude?: number;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：longitude?: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：locale?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：locale?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：placeName?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：placeName?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：countryCode?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：countryCode?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：countryName?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：countryName?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：administrativeArea?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：administrativeArea?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：subAdministrativeArea?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：subAdministrativeArea?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：locality?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：locality?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：subLocality?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：subLocality?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：roadName?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：roadName?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：subRoadName?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：subRoadName?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：premises?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：premises?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：postalCode?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：postalCode?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：phoneNumber?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：phoneNumber?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：addressUrl?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：addressUrl?: string;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：descriptions?: Array\<string>;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：descriptions?: Array\<string>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoAddress;<br>方法or属性：descriptionsSize?: number;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：descriptionsSize?: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：latitude: number;<br>旧版本信息：|类名：Location;<br>方法or属性：latitude: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：longitude: number;<br>旧版本信息：|类名：Location;<br>方法or属性：longitude: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：altitude: number;<br>旧版本信息：|类名：Location;<br>方法or属性：altitude: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：accuracy: number;<br>旧版本信息：|类名：Location;<br>方法or属性：accuracy: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：speed: number;<br>旧版本信息：|类名：Location;<br>方法or属性：speed: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：timeStamp: number;<br>旧版本信息：|类名：Location;<br>方法or属性：timeStamp: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：direction: number;<br>旧版本信息：|类名：Location;<br>方法or属性：direction: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：timeSinceBoot: number;<br>旧版本信息：|类名：Location;<br>方法or属性：timeSinceBoot: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：additions?: Array\<string>;<br>旧版本信息：|类名：Location;<br>方法or属性：additions?: Array\<string>;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：Location;<br>方法or属性：additionSize?: number;<br>旧版本信息：|类名：Location;<br>方法or属性：additionSize?: number;<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoLocationErrorCode;<br>方法or属性：INPUT_PARAMS_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：INPUT_PARAMS_ERROR<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoLocationErrorCode;<br>方法or属性：REVERSE_GEOCODE_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：REVERSE_GEOCODE_ERROR<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoLocationErrorCode;<br>方法or属性：GEOCODE_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：GEOCODE_ERROR<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoLocationErrorCode;<br>方法or属性：LOCATOR_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：LOCATOR_ERROR<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoLocationErrorCode;<br>方法or属性：LOCATION_SWITCH_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：LOCATION_SWITCH_ERROR<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoLocationErrorCode;<br>方法or属性：LAST_KNOWN_LOCATION_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：LAST_KNOWN_LOCATION_ERROR<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
|权限有变化|类名：GeoLocationErrorCode;<br>方法or属性：LOCATION_REQUEST_TIMEOUT_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：LOCATION_REQUEST_TIMEOUT_ERROR<br>新版本信息：ohos.permission.LOCATION|@ohos.geolocation.d.ts|
