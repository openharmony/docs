# @ohos.geoLocationManager (Geolocation Manager)

The **geoLocationManager** module provides location services such as Global Navigation Satellite System (GNSS)-based positioning, network positioning, geofencing, as well as geocoding and reverse geocoding.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module supports only the WGS-84 coordinate system.

## Applying for Permissions

For details, see For details, see [Applying for Location Permissions](../../device/location/location-guidelines.md#applying-for-location-permissions).


## Modules to Import

```ts
import geoLocationManager from '@ohos.geoLocationManager';
```


## ReverseGeoCodeRequest

Defines a reverse geocoding request.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | Yes| Yes| Language used for the location description. **zh** indicates Chinese, and **en** indicates English. The default language is obtained from **Language and region** in **Settings**.|
| latitude | number | Yes| Yes| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from **-90** to **90**.|
| longitude | number | Yes| Yes| Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude . The value ranges from **-180** to **180**.|
| maxItems | number | Yes| Yes| Maximum number of location records to be returned. The specified value must be greater than or equal to **0**. A value smaller than **10** is recommended. The default value is **1**.|


## GeoCodeRequest

Defines a reverse geocoding request.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | Yes| Yes| Language used for the location description. **zh** indicates Chinese, and **en** indicates English. The default language is obtained from **Language and region** in **Settings**.|
| description | string | Yes| Yes| Location description, for example, **No. xx, xx Road, Pudong New District, Shanghai**.|
| maxItems | number | Yes| Yes| Maximum number of location records to be returned. The specified value must be greater than or equal to **0**. A value smaller than **10** is recommended. The default value is **1**.|
| minLatitude | number | Yes| Yes| Minimum latitude. This parameter is used with **minLongitude**, **maxLatitude**, and **maxLongitude** to specify the latitude and longitude ranges. The value ranges from **-90** to **90**.|
| minLongitude | number | Yes| Yes| Minimum longitude. The value ranges from **-180** to **180**.|
| maxLatitude | number | Yes| Yes| Maximum latitude. The value ranges from **-90** to **90**.|
| maxLongitude | number | Yes| Yes| Maximum longitude. The value ranges from **-180** to **180**.|


## GeoAddress

Geocoding address information.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | Yes| No | Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from **-90** to **90**.|
| longitude | number | Yes| No | Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude . The value ranges from **-180** to **180**.|
| locale | string | Yes| No | Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| placeName | string | Yes| No | Landmark of the location.|
| countryCode | string | Yes| No | Country code.|
| countryName | string | Yes| No| Country name.|
| administrativeArea | string | Yes| No| Level-1 administrative region, which is generally is a province or state.|
| subAdministrativeArea | string | Yes| No| Level-2 administrative region, which is generally is a city.|
| locality | string | Yes| No| Locality information, which is usually a city.|
| subLocality | string | Yes| No| Sub-locality information, which is usually a district or county.|
| roadName | string | Yes| No| Road name.|
| subRoadName | string | Yes| No| Auxiliary road information.|
| premises | string | Yes| No| House information.|
| postalCode | string | Yes| No| Postal code.|
| phoneNumber | string | Yes| No| Phone number.|
| addressUrl | string | Yes| No| Website URL.|
| descriptions | Array&lt;string&gt; | Yes| No| Additional description. It contains **cityCode** (the array subscript is **0**) and **adminCode** (the array subscript is **1**), for example, **["025","320114001"]**.|
| descriptionsSize | number | Yes| No| Total number of additional descriptions. The specified value must be greater than or equal to **0**. A value smaller than **10** is recommended.|


## LocationRequest

Defines a location request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | Yes| Yes| Priority of the location request. This parameter is effective only when **scenario** is set to **UNSET**. If this parameter and **scenario** are set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestPriority](#locationrequestpriority).|
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes| Yes| Scenario of the location request. The **priority** parameter is effective only when this parameter is set to **UNSET**. If this parameter and **priority** are set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestScenario](#locationrequestscenario).|
| timeInterval | number | Yes| Yes| Time interval at which location information is reported, in seconds. The specified value must be greater than or equal to **0**. The default value is **1**. If this parameter is set to **0**, there is no restriction on the location reporting interval.|
| distanceInterval | number | Yes| Yes| Distance interval at which location information is reported, in meters. The specified value must be greater than or equal to **0**. The default value is **0**. If this parameter is set to **0**, there is no restriction on the location reporting distance.|
| maxAccuracy | number | No| Yes|  Location accuracy, in meters.<br>This parameter is valid only when the precise location function is enabled (both the ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION permissions are granted). This parameter is valid only when the precise location function is enabled (both the **ohos.permission.APPROXIMATELY_LOCATION** and **ohos.permission.LOCATION** permissions are granted), and is invalid when the approximate location function is enabled (only the **ohos.permission.APPROXIMATELY_LOCATION** permission is enabled).<br>The specified value must be greater than or equal to **0**. The default value is **0**.<br>If **scenario** is set to **NAVIGATION**, **TRAJECTORY_TRACKING**, or **CAR_HAILING** or **priority** is set to **ACCURACY**, you are advised to set **maxAccuracy** to a value greater than **10**.<br>If scenario is set to **DAILY_LIFE_SERVICE** or **NO_POWER** or **priority** is set to **LOW_POWER** or **FIRST_FIX**, you are advised to set **maxAccuracy** to a value greater than **100**.|


## CurrentLocationRequest

Defines a location request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | Yes| Yes| Priority of the location request. This parameter is effective only when **scenario** is set to **UNSET**. If this parameter and **scenario** are set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestPriority](#locationrequestpriority).|
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes| Yes| Scenario of the location request. The **priority** parameter is effective only when this parameter is set to **UNSET**. If this parameter and **priority** are set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestScenario](#locationrequestscenario).|
| maxAccuracy | number | Yes| Yes|  Location accuracy, in meters.<br>This parameter is valid only when the precise location function is enabled (both the ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION permissions are granted). This parameter is valid only when the precise location function is enabled (both the **ohos.permission.APPROXIMATELY_LOCATION** and **ohos.permission.LOCATION** permissions are granted), and is invalid when the approximate location function is enabled (only the **ohos.permission.APPROXIMATELY_LOCATION** permission is enabled).<br>The specified value must be greater than or equal to **0**. The default value is **0**.<br>If **scenario** is set to **NAVIGATION**, **TRAJECTORY_TRACKING**, or **CAR_HAILING** or **priority** is set to **ACCURACY**, you are advised to set **maxAccuracy** to a value greater than **10**.<br>If scenario is set to **DAILY_LIFE_SERVICE** or **NO_POWER** or **priority** is set to **LOW_POWER** or **FIRST_FIX**, you are advised to set **maxAccuracy** to a value greater than **100**.|
| timeoutMs | number | Yes| Yes| Timeout duration, in milliseconds. The minimum value is **1000**. The specified value must be greater than or equal to **1000**.|


## SatelliteStatusInfo

Defines the satellite status information.

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| satellitesNumber | number | Yes| No| Number of satellites. The specified value must be greater than or equal to **0**.|
| satelliteIds | Array&lt;number&gt; | Yes| No| Array of satellite IDs. The specified value must be greater than or equal to **0**.|
| carrierToNoiseDensitys | Array&lt;number&gt; | Yes| No| Carrier-to-noise density ratio, that is, **cn0**. The specified value must be greater than **0**.|
| altitudes | Array&lt;number&gt; | Yes| No| Satellite altitude angle information. The value ranges from **-90** to **90**, in degrees.|
| azimuths | Array&lt;number&gt; | Yes| No| Azimuth information. The value ranges from **0** to **360**, in degrees.|
| carrierFrequencies | Array&lt;number&gt; | Yes| No| Carrier frequency, in Hz. The specified value must be greater than or equal to **0**.|
| satelliteConstellation<sup>12+</sup> | Array&lt;[SatelliteConstellationCategory](#satelliteconstellationcategory12)&gt; | Yes| No| Satellite constellation type.|
| satelliteAdditionalInfo<sup>12+</sup> | Array&lt;number&gt; | Yes| No| Additional satellite information.<br>Each bit has a different meaning. For details, see [SatelliteAdditionalInfo](#satelliteadditionalinfo12).|


## CachedGnssLocationsRequest

Defines a request for reporting cached GNSS locations.

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| reportingPeriodSec | number | Yes| Yes| Interval for reporting the cached GNSS locations, in milliseconds. The specified value must be greater than **0**.|
| wakeUpCacheQueueFull | boolean | Yes| Yes | **true**: reports the cached GNSS locations to the application when the cache queue is full.<br>**false**: discards the cached GNSS locations when the cache queue is full.|


## Geofence

Defines a GNSS geofence. Currently, only circular geofences are supported.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | Yes| Yes|Latitude information. The value ranges from **-90** to **90**.|
| longitude | number | Yes|Yes| Longitude information. The value ranges from **-180** to **180**.|
| coordinateSystemType<sup>12+</sup> | [CoordinateSystemType](#coordinatesystemtype12) | Yes|Yes| Coordinate system of the circle center of a geofence.<br>The application needs to call [getGeofenceSupportedCoordTypes](#geolocationmanagergetgeofencesupportedcoordtypes12) to query the supported coordinate systems and then pass in the correct coordinates of the circle center.|
| radius | number | Yes|Yes| Radius of a circular geofence, in meters. The specified value must be greater than **0**.|
| expiration | number | Yes|Yes| Expiration period of a geofence, in milliseconds. The specified value must be greater than **0**.|


## GeofenceRequest

Defines a geofence request.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes| Yes |  Location scenario.|
| geofence |  [Geofence](#geofence)| Yes| Yes |  Geofence information.|


## LocationCommand

Defines a location command.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| scenario | [LocationRequestScenario](#locationrequestscenario)  | Yes| Yes | Location scenario.|
| command | string | Yes| Yes | Extended command, in the string format.|


## Location

Location information.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number| Yes| No| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from **-90** to **90**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| longitude | number| Yes| No| Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude . The value ranges from **-180** to **180**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| altitude | number | Yes| No| Location altitude, in meters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| accuracy | number | Yes| No| Location accuracy, in meters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| speed | number | Yes| No|Speed, in m/s.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| timeStamp | number | Yes| No| Location timestamp in the UTC format.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| direction | number | Yes| No| Direction information. The value ranges from **0** to **360**, in degrees.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| timeSinceBoot | number | Yes| No| Location timestamp since boot.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| additions | Array&lt;string&gt;| Yes| No| Additional description.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| additionSize | number| Yes| No| Number of additional descriptions. The specified value must be greater than or equal to **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.| 


## GeofenceTransition<sup>12+</sup>

Defines a geofence transition event.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| geofenceId | number| Yes| No| Geofence ID.|
| transitionEvent | [GeofenceTransitionEvent](#geofencetransitionevent12) | Yes| No| Geofence transition event.|


## GnssGeofenceRequest<sup>12+</sup>

Defines a GNSS geofence request.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| geofence | [Geofence](#geofence) | Yes| No| Geofence information, including the coordinates and radius of the circle center.|
| monitorTransitionEvents | Array&lt;[GeofenceTransitionEvent](#geofencetransitionevent12)&gt; | Yes| No| List of geofence transition events.|
| notifications | Array&lt;[NotificationRequest](../apis-notification-kit/js-apis-notification.md#notificationrequest)&gt; | Yes| No| List of notifications for geofence transition events.|
| geofenceTransitionCallback | AsyncCallback&lt;[GeofenceTransition](#geofencetransition12)&gt; | Yes| No| Callback used to receive geofence transition events.|


## CountryCode

Defines the country code information.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| country | string | Yes| No| Country code.|
| type |  [CountryCodeType](#countrycodetype) | Yes| No| Country code source.|

## LocationRequestPriority

Sets the priority of a location request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| UNSET | 0x200 | Priority unspecified.<br>If this option is used, [LocationRequestPriority](#locationrequestpriority) is invalid.|
| ACCURACY | 0x201 | Location accuracy.<br>This policy mainly uses the GNSS positioning technology. It uses the network positioning technology only if the GNSS location result is not obtained within the specified period of time. This policy can lead to significant hardware resource consumption and power consumption.|
| LOW_POWER | 0x202 | Power efficiency.<br>This policy mainly uses the network positioning technology to obtain device location in both indoor and outdoor scenarios. The location accuracy depends on the distribution of surrounding base stations, visible WLANs, and Bluetooth devices and therefore may fluctuate greatly. This policy is recommended and can reduce power consumption if a high location accuracy is not required.|
| FIRST_FIX | 0x203 | Fast location preferred. Use this option if you want to obtain a location as fast as possible.<br>This policy uses the GNSS positioning and network positioning technologies simultaneously to obtain the device location in both the indoor and outdoor scenarios. When all positioning technologies provide a location result, the system provides the most accurate location result for your application. It can lead to significant hardware resource consumption and power consumption.|


## LocationRequestScenario

Defines the location scenario in a location request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| UNSET | 0x300 | Scenario unspecified.<br>If this option is used, [LocationRequestScenario](#locationrequestscenario) is invalid.|
| NAVIGATION | 0x301 | Navigation.<br>This option is applicable when your application needs to obtain the real-time location of a mobile device outdoors, such as navigation for driving or walking.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| TRAJECTORY_TRACKING | 0x302 | Trajectory tracking.<br>This option is applicable when your application needs to record user trajectories, for example, the track recording function of sports applications.<br>It mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| CAR_HAILING | 0x303 | Ride hailing.<br>This option is applicable when your application needs to obtain the current location of a user who is hailing a taxi.<br>It mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.<br>Before the GNSS can provide stable location results, the system uses the network positioning technology (for example, base station positioning or WLAN/Bluetooth positioning) as an alternative to provide the location service when the user moves into a shielded environment, such as indoors or a garage, in the navigation, trajectory tracking, or car hailing scenario.|
| DAILY_LIFE_SERVICE | 0x304 | Daily life services.<br>This option is applicable when your application only needs the approximate location in scenarios such as when the user is browsing news, shopping online, and ordering food.<br>It mainly uses the network positioning technology and therefore the power consumption is relatively low.|
| NO_POWER | 0x305 | Power efficiency. Your application does not proactively start the location service. When responding to another application requesting the same location service, the system marks a copy of the location result to your application. In this way, your application will not consume extra power for obtaining the user location.|

## CountryCodeType

Defines the country code source type.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| COUNTRY_CODE_FROM_LOCALE | 1 | Country code obtained from the language configuration of the globalization module.|
| COUNTRY_CODE_FROM_SIM | 2 | Country code obtained from the SIM card.|
| COUNTRY_CODE_FROM_LOCATION | 3 | Country code obtained using the reverse geocoding function based on the user's location information.|
| COUNTRY_CODE_FROM_NETWORK | 4 | Country code obtained from the cellular network registration information.|


## CoordinateSystemType<sup>12+</sup>

Enumerates coordinate system types.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Value| Description|
| -------- | -------- | -------- |
| WGS84 | 1 | World Geodetic System 1984, a coordinate system established for the use of the GPS.|
| GCJ02 | 2 | GCJ-02, a coordinate system for the geographic information system developed by the State Bureau of Surveying and Mapping of China.|


## GeofenceTransitionEvent<sup>12+</sup>

Defines a geofence transition event.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Value| Description|
| -------- | -------- | -------- |
| GEOFENCE_TRANSITION_EVENT_ENTER  | 1 | Event indicating that a device moves into a geofence.|
| GEOFENCE_TRANSITION_EVENT_EXIT  | 2 | Event indicating that a device moves out of a geofence.|
| GEOFENCE_TRANSITION_EVENT_DWELL   | 4 | Event indicating that a device stays in a geofence for more than 10s.|


## SatelliteConstellationCategory<sup>12+</sup>

Enumerates satellite constellation types.

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Value| Description|
| -------- | -------- | -------- |
| CONSTELLATION_CATEGORY_UNKNOWN   | 0 | Unknown type. This is the default value.|
| CONSTELLATION_CATEGORY_GPS   | 1 | Global positioning system (GPS), a high-precision radio navigation positioning system made up of artificial earth satellites launched by the United States.|
| CONSTELLATION_CATEGORY_SBAS    | 2 | Satellite-based augmentation system (SBAS), which supports wide-area or regional augmentation through the use of geostationary (GEO) satellites for broadcasting augmentation information, such as ephemeris error, satellite clock difference, and ionospheric delay, to users. It enhances the accuracy, integrity, and availability of basic global navigation satellite systems.|
| CONSTELLATION_CATEGORY_GLONASS    | 3 | Global navigation satellite system (GLONASS), a Russia space-based satellite navigation system that provides a global coverage positioning service similar to the GPS.|
| CONSTELLATION_CATEGORY_QZSS    | 4 | Quasi-Zenith satellite system (QZSS), a regional navigation satellite system developed by Japan to enhance and augment GPS coverage over Japan's territory.|
| CONSTELLATION_CATEGORY_BEIDOU     | 5 | Beidou navigation satellite system (BNSS), a global satellite navigation system developed by China.|
| CONSTELLATION_CATEGORY_GALILEO     | 6 | Galileo satellite navigation system (GALILEO), a global satellite navigation and positioning system developed and established by the European Union.|
| CONSTELLATION_CATEGORY_IRNSS     | 7 | Indian regional navigation satellite system (IRNSS), an independent regional satellite navigation system developed and operated by India.|


## SatelliteAdditionalInfo<sup>12+</sup>

Enumerates the types of additional satellite information.

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Value| Description|
| -------- | -------- | -------- |
| SATELLITES_ADDITIONAL_INFO_NULL  | 0 | No additional information. This is the default value.|
| SATELLITES_ADDITIONAL_INFO_EPHEMERIS_DATA_EXIST  | 1 | Ephemeris data.|
| SATELLITES_ADDITIONAL_INFO_ALMANAC_DATA_EXIST   | 2 | Almanac data.|
| SATELLITES_ADDITIONAL_INFO_USED_IN_FIX   | 4 | Use of the satellite in the latest location resolution.|
| SATELLITES_ADDITIONAL_INFO_CARRIER_FREQUENCY_EXIST   | 8 | Presence of carrier frequencies on the satellite.|


## geoLocationManager.on('locationChange')

on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;): void

Subscribes to location change events with a location request initiated. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationChange** indicates a location change.|
  | request |  [LocationRequest](#locationrequest) | Yes| Location request.|
  | callback | Callback&lt;[Location](#location)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let requestInfo:geoLocationManager.LocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET, 'timeInterval': 1, 'distanceInterval': 0, 'maxAccuracy': 0};
  let locationChange = (location:geoLocationManager.Location):void => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', requestInfo, locationChange);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  
  ```


## geoLocationManager.off('locationChange')

off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void

Unsubscribes from location change events with the corresponding location request deleted.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationChange** indicates a location change.|
  | callback | Callback&lt;[Location](#location)&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let requestInfo:geoLocationManager.LocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET, 'timeInterval': 1, 'distanceInterval': 0, 'maxAccuracy': 0};
  let locationChange = (location:geoLocationManager.Location):void => {
    console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', requestInfo, locationChange);
      geoLocationManager.off('locationChange', locationChange);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.on('locationEnabledChange')

on(type: 'locationEnabledChange', callback: Callback&lt;boolean&gt;): void

Subscribes to location service status change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationEnabledChange** indicates a location service status change.|
  | callback | Callback&lt;boolean&gt; | Yes| Callback used to return the result. The value **true** indicates that the location switch is enabled and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let locationEnabledChange = (state:boolean):void => {
      console.log('locationEnabledChange: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.off('locationEnabledChange')

off(type: 'locationEnabledChange', callback?: Callback&lt;boolean&gt;): void;

Unsubscribes from location service status change events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationEnabledChange** indicates a location service status change.|
  | callback | Callback&lt;boolean&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let locationEnabledChange = (state:boolean):void => {
      console.log('locationEnabledChange: state: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
      geoLocationManager.off('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.on('cachedGnssLocationsChange')

on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;): void;

Subscribes to cached GNSS location reports. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **cachedGnssLocationsChange** indicates reporting of cached GNSS locations.|
  | request |  [CachedGnssLocationsRequest](#cachedgnsslocationsrequest) | Yes| Request for reporting cached GNSS location.|
  | callback | Callback&lt;Array&lt;[Location](#location)&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let cachedLocationsCb = (locations:Array<geoLocationManager.Location>):void => {
      console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  let requestInfo:geoLocationManager.CachedGnssLocationsRequest = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  try {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.off('cachedGnssLocationsChange')

off(type: 'cachedGnssLocationsChange', callback?: Callback&lt;Array&lt;Location&gt;&gt;): void;

Unsubscribes from cached GNSS location reports. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **cachedGnssLocationsChange** indicates reporting of cached GNSS locations.|
  | callback | Callback&lt;Array&lt;[Location](#location)&gt;&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let cachedLocationsCb = (locations:Array<geoLocationManager.Location>):void => {
      console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  let requestInfo:geoLocationManager.CachedGnssLocationsRequest = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  try {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
      geoLocationManager.off('cachedGnssLocationsChange');
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.on('satelliteStatusChange')

on(type: 'satelliteStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;): void;

Subscribes to GNSS satellite status change events. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **satelliteStatusChange** indicates a GNSS satellite status change.|
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let gnssStatusCb = (satelliteStatusInfo:geoLocationManager.SatelliteStatusInfo):void => {
      console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }

  try {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.off('satelliteStatusChange')

off(type: 'satelliteStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;): void;

Unsubscribes from GNSS satellite status change events.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **satelliteStatusChange** indicates a GNSS satellite status change.|
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |


**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let gnssStatusCb = (satelliteStatusInfo:geoLocationManager.SatelliteStatusInfo):void => {
      console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  try {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
      geoLocationManager.off('satelliteStatusChange', gnssStatusCb);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.on('nmeaMessage')

on(type: 'nmeaMessage', callback: Callback&lt;string&gt;): void;

Subscribes to GNSS NMEA message change events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **nmeaMessage** indicates a GNSS NMEA message change.|
  | callback | Callback&lt;string&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |


**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let nmeaCb = (str:string):void => {
      console.log('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
      geoLocationManager.on('nmeaMessage', nmeaCb );
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.off('nmeaMessage')

off(type: 'nmeaMessage', callback?: Callback&lt;string&gt;): void;

Unsubscribes from GNSS NMEA message change events.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **nmeaMessage** indicates a GNSS NMEA message change.|
  | callback | Callback&lt;string&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |


**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let nmeaCb = (str:string):void => {
      console.log('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
      geoLocationManager.on('nmeaMessage', nmeaCb);
      geoLocationManager.off('nmeaMessage', nmeaCb);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.on('gnssFenceStatusChange')

on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

Subscribes to status change events of the specified geofence. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **gnssFenceStatusChange** indicates a geofence status change.|
  | request |  [GeofenceRequest](#geofencerequest) | Yes| Geofencing request.|
  | want | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes| **WantAgent** used to receive geofence (entrance or exit) events.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301600 | Failed to operate the geofence.                                     |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import wantAgent from '@ohos.app.ability.wantAgent';
  import BusinessError from "@ohos.base";

  let wantAgentInfo:wantAgent.WantAgentInfo = {
      wants: [
          {
              bundleName: "com.example.myapplication",
              abilityName: "EntryAbility",
              action: "action1"
          }
      ],
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
  };
  
  wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let requestInfo:geoLocationManager.GeofenceRequest = {'scenario': 0x301, "geofence": {"latitude": 31.12, "longitude": 121.11, "radius": 100, "expiration": 10000}};
    try {
        geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
    } catch (err) {
        console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
    }
  });
  ```


## geoLocationManager.off('gnssFenceStatusChange')

off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

Unsubscribes from status change events of the specified geofence. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **gnssFenceStatusChange** indicates a geofence status change.|
  | request | [GeofenceRequest](#geofencerequest) | Yes| Geofencing request.|
  | want | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes| **WantAgent** used to receive geofence (entrance or exit) events.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301600 | Failed to operate the geofence.                                     |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import wantAgent from '@ohos.app.ability.wantAgent';
  import BusinessError from "@ohos.base";
  
  let wantAgentInfo:wantAgent.WantAgentInfo = {
      wants: [
          {
              bundleName: "com.example.myapplication",
              abilityName: "EntryAbility",
              action: "action1",
          }
      ],
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
  };
  
  wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let requestInfo:geoLocationManager.GeofenceRequest = {'scenario': 0x301, "geofence": {"latitude": 31.12, "longitude": 121.11, "radius": 100, "expiration": 10000}};;
    try {
        geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
        geoLocationManager.off('gnssFenceStatusChange', requestInfo, wantAgentObj);
    } catch (err) {
        console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
    }
  });
  ```


## geoLocationManager.on('countryCodeChange')

on(type: 'countryCodeChange', callback: Callback&lt;CountryCode&gt;): void;

Subscribes to country code change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **countryCodeChange** indicates a country code change.|
  | callback | Callback&lt;[CountryCode](#countrycode)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301500 | Failed to query the area information.                                       |


**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let callback = (code:geoLocationManager.CountryCode):void => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
      geoLocationManager.on('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.off('countryCodeChange')

off(type: 'countryCodeChange', callback?: Callback&lt;CountryCode&gt;): void;

Unsubscribes from country code change events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **countryCodeChange** indicates a country code change.|
  | callback | Callback&lt;[CountryCode](#countrycode)&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301500 | Failed to query the area information.                                       |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let callback = (code:geoLocationManager.CountryCode):void => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
      geoLocationManager.on('countryCodeChange', callback);
      geoLocationManager.off('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getCurrentLocation

getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;): void

Obtains the current position. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | Yes| Location request.|
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let requestInfo:geoLocationManager.CurrentLocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET,'maxAccuracy': 0};
  let locationChange = (err:BusinessError.BusinessError, location:geoLocationManager.Location):void => {
      if (err) {
          console.error('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.log('locationChanger: location=' + JSON.stringify(location));
      }
  };

  try {
      geoLocationManager.getCurrentLocation(requestInfo, locationChange);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```

## geoLocationManager.getCurrentLocation

getCurrentLocation(callback: AsyncCallback&lt;Location&gt;): void;

Obtains the current position. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let locationChange = (err:BusinessError.BusinessError, location:geoLocationManager.Location) => {
      if (err) {
          console.error('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.log('locationChanger: location=' + JSON.stringify(location));
      }
  };

  try {
      geoLocationManager.getCurrentLocation(locationChange);
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```

## geoLocationManager.getCurrentLocation

getCurrentLocation(request?: CurrentLocationRequest): Promise&lt;Location&gt;

Obtains the current position. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | No| Location request.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let requestInfo:geoLocationManager.CurrentLocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET,'maxAccuracy': 0};
  try {
      geoLocationManager.getCurrentLocation(requestInfo).then((result) => {
          console.log('current location: ' + JSON.stringify(result));
      })  
      .catch((error:BusinessError.BusinessError) => {
          console.error('promise, getCurrentLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getLastLocation

getLastLocation(): Location

Obtains the last location.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [Location](#location) | Location information.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |
|3301100 | The location switch is off.  |
|3301200 |Failed to obtain the geographical location.  |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      let location = geoLocationManager.getLastLocation();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.isLocationEnabled

isLocationEnabled(): boolean

Checks whether the location service is enabled.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | **true**: The location switch is enabled.<br>**false**: The location switch is disabled.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      let locationEnabled = geoLocationManager.isLocationEnabled();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

Converts coordinates into geographic descriptions through reverse geocoding. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes| Reverse geocoding request.|
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301300 | Reverse geocoding query failed.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let reverseGeocodeRequest:geoLocationManager.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
          if (err) {
              console.error('getAddressesFromLocation: err=' + JSON.stringify(err));
          }
          if (data) {
              console.log('getAddressesFromLocation: data=' + JSON.stringify(data));
          }
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;;

Converts coordinates into geographic descriptions through reverse geocoding. This API uses a promise to return the result. 

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes| Reverse geocoding request.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301300 | Reverse geocoding query failed.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let reverseGeocodeRequest:geoLocationManager.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {
          console.log('getAddressesFromLocation: ' + JSON.stringify(data));
      })
      .catch((error:BusinessError.BusinessError) => {
          console.error('promise, getAddressesFromLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

Converts geographic descriptions into coordinates through geocoding. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | Yes| Geocoding request.|
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301400 | Geocoding query failed.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let geocodeRequest:geoLocationManager.GeoCodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {
          if (err) {
              console.error('getAddressesFromLocationName: err=' + JSON.stringify(err));
          }
          if (data) {
              console.log('getAddressesFromLocationName: data=' + JSON.stringify(data));
          }
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;

Converts geographic descriptions into coordinates through geocoding. This API uses an a promise to return the result. 

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | Yes| Geocoding request.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301400 | Geocoding query failed.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let geocodeRequest:geoLocationManager.GeoCodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocationName(geocodeRequest).then((result) => {
          console.log('getAddressesFromLocationName: ' + JSON.stringify(result));
      })
      .catch((error:BusinessError.BusinessError) => {
          console.error('promise, getAddressesFromLocationName: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```

## geoLocationManager.isGeocoderAvailable

isGeocoderAvailable(): boolean;

Checks whether the geocoding and reverse geocoding services are available.

**System capability**: SystemCapability.Location.Location.Geocoder

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | **true**: The geocoding and reverse geocoding services are available.<br>**false**: The geocoding and reverse geocoding services are unavailable.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      let isAvailable = geoLocationManager.isGeocoderAvailable();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;): void;

Obtains the number of cached GNSS locations. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.getCachedGnssLocationsSize((err, size) => {
          if (err) {
              console.error('getCachedGnssLocationsSize: err=' + JSON.stringify(err));
          }
          if (size) {
              console.log('getCachedGnssLocationsSize: size=' + JSON.stringify(size));
          }
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(): Promise&lt;number&gt;;

Obtains the number of cached GNSS locations. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported. This API uses a promise to return the result.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.getCachedGnssLocationsSize().then((result) => {
          console.log('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));
      }) 
      .catch((error:BusinessError.BusinessError) => {
          console.error('promise, getCachedGnssLocationsSize: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(callback: AsyncCallback&lt;void&gt;): void;

Obtains all cached GNSS locations and clears the GNSS cache queue. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |
|3301200 | Failed to obtain the geographical location.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.flushCachedGnssLocations((err) => {
          if (err) {
              console.error('flushCachedGnssLocations: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(): Promise&lt;void&gt;;

Obtains all cached GNSS locations and clears the GNSS cache queue. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported. This API uses a promise to return the result.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |
|3301200 | Failed to obtain the geographical location.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.flushCachedGnssLocations().then(() => {
          console.log('promise, flushCachedGnssLocations success');
      })
      .catch((error:BusinessError.BusinessError) => {
          console.error('promise, flushCachedGnssLocations: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.sendCommand

sendCommand(command: LocationCommand, callback: AsyncCallback&lt;void&gt;): void;

Sends an extended command to the location subsystem. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | command |  [LocationCommand](#locationcommand) | Yes| Extended command (string) to be sent.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let requestInfo:geoLocationManager.LocationCommand = {'scenario': 0x301, 'command': "command_1"};
  try {
      geoLocationManager.sendCommand(requestInfo, (err) => {
          if (err) {
              console.error('sendCommand: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.sendCommand

sendCommand(command: LocationCommand): Promise&lt;void&gt;;

Sends an extended command to the location subsystem. This API uses a promise to return the result.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | command | [LocationCommand](#locationcommand) | Yes| Extended command (string) to be sent.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  let requestInfo:geoLocationManager.LocationCommand = {'scenario': 0x301, 'command': "command_1"};
  try {
      geoLocationManager.sendCommand(requestInfo).then(() => {
          console.log('promise, sendCommand success');
      })  
      .catch((error:BusinessError.BusinessError) => {
          console.error('promise, sendCommand: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getCountryCode

getCountryCode(callback: AsyncCallback&lt;CountryCode&gt;): void;

Obtains the current country code. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[CountryCode](#countrycode)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301500 | Failed to query the area information.|

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.getCountryCode((err, result) => {
          if (err) {
              console.error('getCountryCode: err=' + JSON.stringify(err));
          }
          if (result) {
              console.log('getCountryCode: result=' + JSON.stringify(result));
          }
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```


## geoLocationManager.getCountryCode

getCountryCode(): Promise&lt;CountryCode&gt;;

Obtains the current country code. This API uses a promise to return the result.

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[CountryCode](#countrycode)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301500 | Failed to query the area information.|

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
      geoLocationManager.getCountryCode()
      .then((result) => {
          console.log('promise, getCountryCode: result=' + JSON.stringify(result));
      })
      .catch((error:BusinessError.BusinessError) => {
          console.error('promise, getCountryCode: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```

## geoLocationManager.addGnssGeofence<sup>12+</sup>

addGnssGeofence(fenceRequest: GnssGeofenceRequest): Promise&lt;number&gt;;

Adds a GNSS geofence and subscribes to geofence transition events. This API uses a promise to return the result.

The application can pass a callback to [GnssGeofenceRequest](#gnssgeofencerequest12) to receive geofence transition events. It can also pass [NotificationRequest](../apis-notification-kit/js-apis-notification.md#notificationrequest) so that a notification is displayed when a geofence transition event occurs.

This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | fenceRequest | [GnssGeofenceRequest](#gnssgeofencerequest12) | Yes| Geofence request.<br>It includes the geofence information, list of geofence transition events and notifications, and callback used to receive geofence transition events.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable. |
|3301100  | The location switch is off.|
|3301601   | The number of geofences exceeds the maximum.|

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  // Create a geofence.
  let geofence: geoLocationManager.Geofence = {
    "latitude": 34.12, "longitude": 124.11, "radius": 10000.0, "expiration": 10000.0
  }
  // Specify the types of geofence transition events to listen for. Geofence entry and exit events are used as an example.
  let transitionStatusList: Array<geoLocationManager.GeofenceTransitionEvent> = [
    geoLocationManager.GeofenceTransitionEvent.GEOFENCE_TRANSITION_EVENT_ENTER,
    geoLocationManager.GeofenceTransitionEvent.GEOFENCE_TRANSITION_EVENT_EXIT,
  ];
  // Create a notification object for GEOFENCE_TRANSITION_EVENT_ENTER.
  let notificationRequest1: notificationManager.NotificationRequest = {
    id: 1,
    content: {
      notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
      normal: {
        title: "Geofence Notification",
        text: "Geofence Entry",
        additionalText: ""
      }
    }
  };
  // Create a notification object for GEOFENCE_TRANSITION_EVENT_EXIT.
  let notificationRequest2: notificationManager.NotificationRequest = {
    id: 2,
    content: {
      notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
      normal: {
        title: "Geofence Notification",
        text:'Geofence Exit',
        additionalText: ""
      }
    }
  };
  // Save the created notification objects to Array in the same sequence as in transitionStatusList.
  let notificationRequestList: Array<notificationManager.NotificationRequest> =
    [notificationRequest1, notificationRequest2];
  // Construct a gnssGeofenceRequest object.
  let gnssGeofenceRequest: geoLocationManager.GnssGeofenceRequest = {
    // Geofence attributes, including the circle center and radius.
    geofence: geofence,
    // Specify the types of geofence transition events to listen for.
    monitorTransitionEvents: transitionStatusList,
    // Specify the notification objects for geofence transition events. This parameter is optional.
    notifications: notificationRequestList,
    // Specify the callback used to receive geofence transition events.
    geofenceTransitionCallback: (err : BusinessError.BusinessError, transition : geoLocationManager.GeofenceTransition) => {
      if (err) {
        console.error('geofenceTransitionCallback: err=' + JSON.stringify(err));
      }
      if (transition) {
        console.log("GeofenceTransition: %{public}s", JSON.stringify(transition));
    }
    }
  }
  try {
    // Add a geofence.
    await geoLocationManager.addGnssGeofence(gnssGeofenceRequest).then((id) => {
      // Obtain the geofence ID after the geofence is successfully added.
      console.log("addGnssGeofence success, fence id: " + id);
      let fenceId = id;
    }).catch((err: BusinessError.BusinessError) => {
      console.error("addGnssGeofence failed, promise errCode:" + (err as BusinessError.BusinessError).code + 
        ",errMessage:" + (err as BusinessError.BusinessError).message);
    });
  } catch(error: BusinessError.BusinessError) {
      console.error("addGnssGeofence failed, err:" + JSON.stringify(error));
  }
  ```
  

## geoLocationManager.removeGnssGeofence<sup>12+</sup>

removeGnssGeofence(geofenceId: number): Promise&lt;void&gt;;

Removes a GNSS geofence and unsubscribes from geofence transition events. This API uses a promise to return the result.

This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | geofenceId | number | Yes| GNSS geofence ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that that returns no value.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |
|3301602 | Failed to delete a geofence due to an incorrect ID. |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  // fenceId is obtained after geoLocationManager.addGnssGeofence is successfully executed.
  let fenceId = 1;
  try {
    await geoLocationManager.removeGnssGeofence(fenceId).then(() => {
      console.log("removeGnssGeofence success fenceId:" + fenceId);
    }).catch((error : BusinessError.BusinessError) => {
      console.error("removeGnssGeofence: error=" + JSON.stringify(error));
    });
  } catch(error: BusinessError.BusinessError) {
    console.error("removeGnssGeofence: error=" + JSON.stringify(error));
  }
  ```


## geoLocationManager.getGeofenceSupportedCoordTypes<sup>12+</sup>

getGeofenceSupportedCoordTypes(): Array&lt;CoordinateSystemType&gt;;

Obtains the list of supported coordinate systems.

**System capability**: SystemCapability.Location.Location.Geofence

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Array&lt;[CoordinateSystemType](#coordinatesystemtype12)&gt; | List of supported coordinate systems.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |

**Example**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import BusinessError from "@ohos.base";
  try {
    let supportedCoordTypes: Array<geoLocationManager.CoordinateSystemType> = geoLocationManager.getGeofenceSupportedCoordTypes();
    console.log("getGeofenceSupportedCoordTypes return:" + JSON.stringify(supportedCoordTypes));
  } catch(error : BusinessError.BusinessError) {
    console.error("getGeofenceSupportedCoordTypes: error=" + JSON.stringify(error));
  }
  ```
