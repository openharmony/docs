# Access Token Changelog
## cl.access_token.1 Behavior Change When Location Permission Is Requested by requestPermissionsFromUser

**Access Level**

Public

**Reason for Change**

According to privacy protection requirements, the location permission is added with the **Allow only while in use** option, and the **ohos.permission.LOCATION_IN_BACKGROUND** permission cannot be granted separately in a dialog box.

If an application requires **ohos.permission.LOCATION_IN_BACKGROUND**, the permission must be granted by the user in **Settings**. For details, see **Adaptation Guide**.

**Change Impact**

Involved permissions:

- Foreground location permissions (used to control the behavior of a foreground application to obtain location information):
  - [ohos.permission.LOCATION](../../../application-dev/security/AccessToken/permissions-for-all.md#ohospermissionlocation): allows an application to obtain the precise location information of a device. This permission can be requested only after the ohos.permission.APPROXIMATELY_LOCATION permission is available.
  - [ohos.permission.APPROXIMATELY_LOCATION](../../../application-dev/security/AccessToken/permissions-for-all.md#ohospermissionapproximately_location): allows an application to obtain approximate location information of a device.

- Background location permission (used to control the behavior of a background application to obtain location information):

  [ohos.permission.LOCATION_IN_BACKGROUND](../../../application-dev/security/AccessToken/permissions-for-all.md#ohospermissionlocation_in_background): allows an application running in the background to obtain device location information. This permission can be requested only after the foreground location permissions are available.

The following scenarios are involved:

a) The application requests only the background location permission (without the foreground location permissions).

Before the change:<br>A dialog box will be displayed for granting the **ohos.permission.LOCATION_IN_BACKGROUND** permission.

After the change:<br>The **ohos.permission.LOCATION_IN_BACKGROUND** permission cannot be granted by the user in a dialog box.

b) The application requests only the background location permission (with the foreground location permissions available).

Before the change:<br>The **ohos.permission.LOCATION_IN_BACKGROUND** permission is granted when the **ohos.permission.LOCATION** permission is granted for the first time.

After the change:<br>The **ohos.permission.LOCATION_IN_BACKGROUND** permission cannot be granted by the user in a dialog box.

c) The application requests both the foreground and background location permissions.

Before the change:<br>A dialog box containing **Allow** and **Deny** will be displayed for granting the permissions.

After the change:

API 10 and earlier: A dialog box containing **Allow only while in use** and **Deny** will be displayed. If **Allow only while in use** is selected, only the **ohos.permission.LOCATION** permission is granted.

API 11 and later: No dialog box will be displayed for granting the foreground and background location permissions.

**API level**

9

**Change Since**

OpenHarmony SDK 4.1.5.3

**Key API/Component Changes**

[requestPermissionsFromUser](../../../application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) in @ohos.abilityAccessCtrl.d.ts

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

1. Request the foreground and background location permissions for your application using **requestPermissionsFromUser**.

    a) Check whether the application requires the background location permission. If yes, request the foreground location permissions first.

        Change:
        atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION', 'ohos.permission.LOCATION_IN_BACKGROUND'], ......)
        To:
        atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION'], ......)
        
        Or change:
        atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION_IN_BACKGROUND'], ......)
        To:
        <br>atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION'], ......).

    b) After the user has granted the foreground location permissions, a dialog box is displayed, informing the user to grant the background location permission in **Settings**.

    c) The user selects **Always allow** on the **Settings** screen to grant the background location permission.

2. Request only the background location permission for your application using **requestPermissionsFromUser**.

    a) Check whether the application requires the background location permission. If yes, request the foreground location permissions in a dialog box first.

        Change:
        atManager.requestPermissionsFromUser(context, ['ohos.permission.LOCATION_IN_BACKGROUND'], ......)
    To:
        atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION', 'ohos.permission.LOCATION'], ......)
        
    Or change:
        atManager.requestPermissionsFromUser(context, ['ohos.permission.LOCATION_IN_BACKGROUND'], ......)
        To:
        atManager.requestPermissionsFromUser(context, ['ohos.permission.APPROXIMATELY_LOCATION'], ......).
    
    b) See the steps in case 1.

For details about the sample code, see [**requestPermissionsFromUser**](../../../application-dev/reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9).
