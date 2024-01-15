# 程序访问子系统变更说明
## cl.access_token.1 requestPermissionsFromUser申请位置权限时行为变更

**访问级别**

公开接口

**变更原因**

根据安全隐私要求，地理位置支持使用期间允许的管控能力。位置权限申请使用时，禁止通过弹窗形式授予后台位置权限；

应用如需使用后台位置权限，需要在设置界面由用户手动授予，具体授权方式请参考下文【适配指导】

**变更影响**

涉及权限：

前台位置权限（用于管控应用前台获取位置信息行为）：

精确位置权限：[ohos.permission.LOCATION](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/AccessToken/permissions-for-all.md#ohospermissionlocation)：允许应用获取设备精确位置信息；需要先申请模糊位置权限才可申请此权限。

模糊位置权限：[ohos.permission.APPROXIMATELY_LOCATION](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/AccessToken/permissions-for-all.md#ohospermissionapproximately_location)：允许应用获取设备模糊位置信息。

后台位置权限（用于管控应用后台获取位置信息行为）：

[ohos.permission.LOCATION_IN_BACKGROUND](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/AccessToken/permissions-for-all.md#ohospermissionlocation_in_background)：允许应用在后台运行时获取设备位置信息；需要先申请前台位置权限后，才可申请此权限。

具体受影响的弹窗场景见下文：

a) 应用仅申请后台位置权限（前台位置权限未弹窗申请）

变更前：弹出弹窗，点击允许可授予后台位置权限

变更后：不弹窗，不授予后台位置权限

b) 应用仅申请后台位置权限（前台位置权限已授予）

变更前：不弹窗，后台位置权限在第一次授予前台位置权限时同时授予

变更后：不弹窗，不授予后台位置权限

c) 应用同时申请前台位置和后台位置权限

变更前：弹窗展示允许和拒绝选项，选择允许则授予前台位置+后台位置权限

变更后：

API 10及以前：弹窗展示使用期间允许和拒绝选项，选择使用期间允许，仅授予前台位置权限;

API 11及以后：不弹窗，不授予前台位置和后台位置权限

**API level**

9

**变更发生版本**

从OpenHarmony SDK 4.1.5.3开始。

**变更的接口/组件**

@ohos.abilityAccessCtrl.d.ts中[requestPermissionsFromUser](../../../application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)接口

**可能影响接口**

| 文件 | 方法 |
| -------- | -------- |
| @ohos.geolocation.d.ts | geolocation.on('locationChange') |
| @ohos.geolocation.d.ts | geolocation.off('locationChange') |
| @ohos.geolocation.d.ts | geolocation.on('locationServiceState') |
| @ohos.geolocation.d.ts | geolocation.off('locationServiceState') |
| @ohos.geolocation.d.ts | geolocation.on('cachedGnssLocationsReporting') |
| @ohos.geolocation.d.ts | geolocation.off('cachedGnssLocationsReporting') |
| @ohos.geolocation.d.ts | geolocation.on('gnssStatusChange') |
| @ohos.geolocation.d.ts | geolocation.off('gnssStatusChange') |
| @ohos.geolocation.d.ts | geolocation.on('nmeaMessageChange') |
| @ohos.geolocation.d.ts | geolocation.off('nmeaMessageChange') |
| @ohos.geolocation.d.ts | geolocation.on('fenceStatusChange') |
| @ohos.geolocation.d.ts | geolocation.off('fenceStatusChange') |
| @ohos.geolocation.d.ts | geolocation.getCurrentLocation |
| @ohos.geolocation.d.ts | geolocation.getLastLocation |
| @ohos.geolocation.d.ts | geolocation.isLocationEnabled |
| @ohos.geolocation.d.ts | geolocation.requestEnableLocation |
| @ohos.geolocation.d.ts | geolocation.isGeoServiceAvailable |
| @ohos.geolocation.d.ts | geolocation.getAddressesFromLocation |
| @ohos.geolocation.d.ts | geolocation.getAddressesFromLocationName |
| @ohos.geolocation.d.ts | geolocation.getCachedGnssLocationsSize |
| @ohos.geolocation.d.ts | geolocation.flushCachedGnssLocations |
| @ohos.geolocation.d.ts | geolocation.sendCommand |
| @ohos.geolocation.d.ts | SatelliteStatusInfo |
| @ohos.geolocation.d.ts | CachedGnssLocationsRequest |
| @ohos.geolocation.d.ts | GeofenceRequest |
| @ohos.geolocation.d.ts | Geofence |
| @ohos.geolocation.d.ts | ReverseGeoCodeRequest |
| @ohos.geolocation.d.ts | GeoCodeRequest |
| @ohos.geolocation.d.ts | GeoAddress |
| @ohos.geolocation.d.ts | LocationRequest |
| @ohos.geolocation.d.ts | CurrentLocationRequest |
| @ohos.geolocation.d.ts | Location |
| @ohos.geoLocationManager.d.ts | geoLocationManager.on('nmeaMessage') |
| @ohos.geoLocationManager.d.ts | geoLocationManager.off('nmeaMessage') |
| @ohos.geoLocationManager.d.ts | geoLocationManager.on('locatingRequiredDataChange') |
| @ohos.geoLocationManager.d.ts | geoLocationManager.off('locatingRequiredDataChange') |
| @ohos.geoLocationManager.d.ts | geoLocationManager.getLocatingRequiredData |
| @ohos.bluetooth.d.ts | bluetooth.startBluetoothDiscovery |
| @ohos.bluetooth.d.ts | startBLEScan |
| @ohos.bluetoothManager.d.ts | bluetoothManager.startBluetoothDiscovery |
| @ohos.bluetoothManager.d.ts | startBLEScan |
| @ohos.telephony.observer.d.ts | observer.on('cellInfoChange') |
| @ohos.telephony.radio.d.ts | radio.sendUpdateCellLocationRequest |
| @ohos.telephony.radio.d.ts | radio.getCellInformation |
| @system.geolocation.d.ts | GetLocationOption |
| @system.geolocation.d.ts | SubscribeLocationOption |
| @system.geolocation.d.ts | geolocation.getLocation |
| @system.geolocation.d.ts | geolocation.subscribe |
| @system.geolocation.d.ts | geolocation.unsubscribe |
| @ohos.wifi.d.ts | wifi.scan |
| @ohos.wifi.d.ts | wifi.getScanInfos |
| @ohos.wifi.d.ts | wifi.getDeviceConfigs |
| @ohos.wifi.d.ts | wifi.getStations |
| @ohos.wifi.d.ts | wifi.getCurrentGroup |
| @ohos.wifi.d.ts | wifi.getP2pPeerDevices |
| @ohos.wifi.d.ts | wifi.p2pConnect |
| @ohos.wifi.d.ts | wifi.startDiscoverDevices |
| @ohos.wifi.d.ts | wifi.on('p2pDeviceChange') |
| @ohos.wifi.d.ts | wifi.off('p2pDeviceChange') |
| @ohos.wifi.d.ts | wifi.on('p2pPeerDeviceChange') |
| @ohos.wifi.d.ts | wifi.off('p2pPeerDeviceChange') |
| @ohos.wifiManager.d.ts | wifiManager.scan |
| @ohos.wifiManager.d.ts | wifiManager.getScanResults |
| @ohos.wifiManager.d.ts | wifiManager.getScanResultsSync |
| @ohos.wifiManager.d.ts | wifiManager.getCandidateConfigs |
| @ohos.wifiManager.d.ts | wifiManager.getDeviceConfigs |
| @ohos.wifiManager.d.ts | wifiManager.getStations |
| @ohos.wifiManager.d.ts | wifiManager.getCurrentGroup |
| @ohos.wifiManager.d.ts | wifiManager.getP2pPeerDevices |
| @ohos.wifiManager.d.ts | wifiManager.p2pConnect |
| @ohos.wifiManager.d.ts | wifiManager.startDiscoverDevices |
| @ohos.wifiManager.d.ts | wifiManager.getP2pGroups |
| @ohos.wifiManager.d.ts | wifiManager.on('p2pDeviceChange') |
| @ohos.wifiManager.d.ts | wifiManager.off('p2pDeviceChange') |
| @ohos.wifiManager.d.ts | wifiManager.on('p2pPeerDeviceChange') |
| @ohos.wifiManager.d.ts | wifiManager.off('p2pPeerDeviceChange') |

**适配指导**

1、应用在requestPermissionsFromUser接口中同时申请前台、后台位置权限

    a) 排查应用是否需要后台位置权限，如需要，将接口申请权限行为更改为单独申请前台位置权限

        由：atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION', 'ohos.permission.LOCATION_IN_BACKGROUND'], ......)
        更改为：atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION'], ......)

        或由：atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION_IN_BACKGROUND'], ......)
        更改为：atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION'], ......)

    b) 当用户点击弹窗授予前台位置权限后，应用通过弹窗、提示窗等形式告知用户前往设置界面

    c) 用户在设置界面选择【始终允许】选项，手动授予后台位置权限

2、应用仅在requestPermissionsFromUser接口中申请后台位置权限

    a) 排查应用是否需要后台位置权限，如需要，需要先弹窗申请前台位置权限（后台位置权限仅在前台位置权限生效情况下才能够使用）

        由：atManager.requestPermissionsFromUser(context, ['ohos.permission.LOCATION_IN_BACKGROUND'], ......)
        更改为：atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION'], ......)

        或由：atManager.requestPermissionsFromUser(context, ['ohos.permission.LOCATION_IN_BACKGROUND'], ......)
        更改为：atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION'], ......)

    b) 参考情况1

接口使用的示例代码可参考[requestPermissionsFromUser接口指导](../../../application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)
