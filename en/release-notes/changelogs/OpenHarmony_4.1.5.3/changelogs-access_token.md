# Access Token Changelog
## cl.access_token.1 Behavior Change When Location Permission Is Requested by requestPermissionsFromUser

**Access Level**

Public

**Reason for Change**

According to privacy protection requirements, the location permission is added with the **Allow only while in use** option. When the location permission is required, the **ohos.permission.LOCATION_IN_BACKGROUND** permission cannot be granted in a dialog box.

**Change Impact**

This change is a non-compatible change. The location permission is added with the **Allow only while in use** option. When the location permission is required, the **ohos.permission.LOCATION_IN_BACKGROUND** permission cannot be granted in a dialog box. 

The following scenarios are involved:

- The application applies for only the **ohos.permission.LOCATION_IN_BACKGROUND** permission (the **ohos.permission.LOCATION** permission has not been granted).

  Before the change: 

  A dialog box will be displayed for granting the **ohos.permission.LOCATION_IN_BACKGROUND** permission.

  After the change: 

  No dialog box will be displayed for granting the **ohos.permission.LOCATION_IN_BACKGROUND** permission. 

- The application applies for only the **ohos.permission.LOCATION_IN_BACKGROUND** permission (the **ohos.permission.LOCATION** permission has been granted).

  Before the change: 

  No dialog box will be displayed, but the **ohos.permission.LOCATION_IN_BACKGROUND** permission is granted when the **ohos.permission.LOCATION** permission is granted for the first time.

  After the change: 

  No dialog box will be displayed for granting the **ohos.permission.LOCATION_IN_BACKGROUND** permission. 

- The application applies for both the **ohos.permission.LOCATION** and **ohos.permission.LOCATION_IN_BACKGROUND** permissions.

  Before the change: 

  A dialog box containing **Allow** and **Deny** will be displayed for granting the two permissions.

  After the change:

  - API version 10 and earlier: A dialog box containing **Allow only while in use** and **Deny** will be displayed. If **Allow only while in use** is selected, only the **ohos.permission.LOCATION** permission is granted.
  - API version 11 and later: No dialog box will be displayed.

**API Level**

9

**Change Since**

OpenHarmony SDK 4.1.5.3

**Key API/Component Changes**

**requestPermissionsFromUser** in @ohos.abilityAccessCtrl.d.ts

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

For details about the sample code, see [**requestPermissionsFromUser**](../../../application-dev/reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9).
