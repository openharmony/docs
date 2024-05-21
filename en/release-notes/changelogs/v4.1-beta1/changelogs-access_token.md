# Access Token Changelog
## cl.access_token.1 Behavior Change of requestPermissionsFromUser()

**Access Level**

Public

**Reason for Change**

This change is a non-compatible change. According to security and privacy protection requirements, the [ohos.permission.APPROXIMATELY_LOCATION](../../../application-dev/security/permission-list.md#ohospermissionapproximately_location) permission must be requested together with the [ohos.permission.LOCATION_IN_BACKGROUND](../../../application-dev/security/permission-list.md#ohospermissionlocation_in_background) or [ohos.permission.LOCATION](../../../application-dev/security/permission-list.md#ohospermissionlocation) permission.

**Change Impact**

Before the change, when [requestPermissionsFromUser](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) is called to request location permissions, an authorization dialog box will be displayed in either of the following cases:

The [ohos.permission.LOCATION_IN_BACKGROUND](../../../application-dev/security/permission-list.md#ohospermissionlocation_in_background) permission is requested without the [ohos.permission.APPROXIMATELY_LOCATION](../../../application-dev/security/permission-list.md#ohospermissionapproximately_location) permission.

The [ohos.permission.LOCATION_IN_BACKGROUND](../../../application-dev/security/permission-list.md#ohospermissionlocation_in_background) and [ohos.permission.LOCATION](../../../application-dev/security/permission-list.md#ohospermissionlocation) permissions are requested without the [ohos.permission.APPROXIMATELY_LOCATION](../../../application-dev/security/permission-list.md#ohospermissionapproximately_location) permission.

After the change, no authorization dialog box will be displayed in the preceding two cases. The **ohos.permission.APPROXIMATELY_LOCATION** permission must be requested together with the **ohos.permission.LOCATION_IN_BACKGROUND** or **ohos.permission.LOCATION** permission.

**Change Since**

OpenHarmony SDK 4.1.1.5

**Key API/Component Changes**

The **ohos.permission.APPROXIMATELY_LOCATION** permission must also be requested when the **ohos.permission.LOCATION_IN_BACKGROUND** or **ohos.permission.LOCATION** permission is requested by using **requestPermissionsFromUser** in @ohos.abilityAccessCtrl.d.ts.

**Affected APIs**

| File| API|
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

**Adaptation Guide**

Refer to [requestPermissionsFromUser](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) when modifying **EntryAbility.ets** and importing **GlobalThis**.

```ts
    let context: common.UIAbilityContext = GlobalThis.getInstance().getContext('context');
    atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION', 'ohos.permission.LOCATION_IN_BACKGROUND']).then((data) => {
        console.info('data:' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        console.info('data:' + JSON.stringify(err));
    })
```

## cl.access_token.2 Change of the Value Returned by getPermissionUsedRecord

**Change Impact**

Before the change, the permission access record returned by [getPermissionUsedRecord](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-privacyManager.md#privacymanagergetpermissionusedrecord) includes the foreground and background status, access timestamp, and access duration.

After the change, the permission access record also includes **lockScreenStatus**, which is optional.

For details, see [UsedRecordDetail](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-privacyManager.md#usedrecorddetail).

**Adaptation Guide**

For details about the usage and interface description, see [getPermissionUsedRecord](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-privacyManager.md#privacymanagergetpermissionusedrecord).

For example, call **getPermissionUsedRecord** to obtain information about the permission usage and parse the **lockScreenStatus**.

Example:
```ts
import privacyManager from '@ohos.privacyManager';

try {
    privacyManager.getPermissionUsedRecord({
        flag:1
    }, (err, data) => {
        try {
            let record = data.bundleRecords[0].permissionRecords[0];
            let access = record.accessRecords;
            let reject = record.rejectRecords;
            for (let i = 0; i < access.length; i++) {
                let detail = access[i];
                console.log(`access record detail lockscreen status: ` + detail.lockScreenStatus);
            }
            for (let i = 0; i < reject.length; i++) {
                let detail = reject[i];
                console.log(`reject record detail lockscreen status: ` + detail.lockScreenStatus);
            }
        } catch(err) {
            console.log(`catch err->${JSON.stringify(err)}`);
        }
    })
} catch(err) {
    console.log(`catch err->${JSON.stringify(err)}`);
}
```

## cl.access_token.3 Behavior Change of requestPermissionsFromUser()

**Access Level**

Public

**Reason for Change**

This change is a non-compatible change. According to privacy protection requirements, the location permission is added with the **Allow only while in use** option, and the **ohos.permission.LOCATION_IN_BACKGROUND** permission cannot be granted separately in a dialog box.

**Change Impact**

The location permission is added with the **Allow only while in use** option, and the **ohos.permission.LOCATION_IN_BACKGROUND** permission cannot be granted separately in a dialog box. The following scenarios are involved:

a) The application applies for only the **ohos.permission.LOCATION_IN_BACKGROUND** permission (the **ohos.permission.LOCATION** permission has not been granted).

Before the change:<br>A dialog box will be displayed for granting the **ohos.permission.LOCATION_IN_BACKGROUND** permission.

After the change:<br>No dialog box will be displayed for granting the **ohos.permission.LOCATION_IN_BACKGROUND** permission. 

b) The application applies for only the **ohos.permission.LOCATION_IN_BACKGROUND** permission (the **ohos.permission.LOCATION** permission has been granted).

Before the change:<br>No dialog box will be displayed, but the **ohos.permission.LOCATION_IN_BACKGROUND** permission is granted when the **ohos.permission.LOCATION** permission is granted for the first time.

After the change:<br>No dialog box will be displayed for granting the **ohos.permission.LOCATION_IN_BACKGROUND** permission. 

c) The application requests both the **ohos.permission.LOCATION** and **ohos.permission.LOCATION_IN_BACKGROUND** permissions.

Before the change:<br>A dialog box containing **Allow** and **Deny** will be displayed for granting the two permissions.

After the change: A dialog box containing **Allow only while in use** and **Deny** will be displayed. If **Allow only while in use** is selected, only the **ohos.permission.LOCATION** permission is granted.

**Change Since**

OpenHarmony SDK 4.1.5.3

**Key API/Component Changes**

When an application calls **requestPermissionsFromUser** in @ohos.abilityAccessCtrl.d.ts to request location permissions, the background location permission cannot be granted in a dialog box.

**Affected APIs**

| File| API|
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

**Adaptation Guide**

For details about the sample code, see [requestPermissionsFromUser](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9).

<!--no_check-->