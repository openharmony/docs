# @ohos.geoLocationManager (Geolocation Manager)

The **geoLocationManager** module provides basic location services such as Global Navigation Satellite System (GNSS)-based positioning, network positioning (for example, base station positioning or WLAN/Bluetooth positioning), geofencing, as well as geocoding and reverse geocoding.

To use location services, turn on the Location switch on your device. If the switch is turned off while exception capture is disabled, the application may run into an error.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module supports only the WGS-84 coordinate system.

## Applying for Permissions

For details, see [Applying for Location Permissions](../../device/location/location-guidelines.md#applying-for-location-permissions).


## Modules to Import

```ts
import { geoLocationManager } from '@kit.LocationKit';
```


## ReverseGeoCodeRequest

Defines a reverse geocoding request.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | No| Yes| Language used for the location description. **zh** indicates Chinese, and **en** indicates English. The default language is obtained from **Language and region** in **Settings**.|
| country<sup>12+</sup> | string | No| Yes| Country information. The country code complies with the ISO 3166-1 alpha-2 standard. **CN** indicates China. The default language is obtained from **Language and region** in **Settings**.|
| latitude | number | No| No| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from **-90** to **90**. Only the WGS84 coordinate system is supported.|
| longitude | number | No| No| Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude . The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported.|
| maxItems | number | No| Yes| Maximum number of location records to be returned. The specified value must be greater than or equal to **0**. A value smaller than **10** is recommended. The default value is **1**.|


## GeoCodeRequest

Defines a reverse geocoding request.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | No| Yes| Language used for the location description. **zh** indicates Chinese, and **en** indicates English. The default language is obtained from **Language and region** in **Settings**.|
| country<sup>12+</sup> | string | No| Yes| Country information. The country code complies with the ISO 3166-1 alpha-2 standard. **CN** indicates China. The default language is obtained from **Language and region** in **Settings**.|
| description | string | No| No| Location description, for example, **No. xx, xx Road, Pudong New District, Shanghai**.|
| maxItems | number | No| Yes| Maximum number of location records to be returned. The specified value must be greater than or equal to **0**. A value smaller than **10** is recommended. The default value is **1**.|
| minLatitude | number | No| Yes| Minimum latitude. This parameter is used with **minLongitude**, **maxLatitude**, and **maxLongitude** to specify the latitude and longitude ranges. The value ranges from **-90** to **90**. Only the WGS84 coordinate system is supported. The following three parameters are mandatory is this parameter is specified.|
| minLongitude | number | No| Yes| Minimum longitude. The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported.|
| maxLatitude | number | No| Yes| Maximum latitude. The value ranges from **-90** to **90**. Only the WGS84 coordinate system is supported.|
| maxLongitude | number | No| Yes| Maximum longitude. The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported.|


## GeoAddress

Geocoding address information.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | No| Yes | Latitude information. A positive value indicates a north latitude, and a negative value indicates a south latitude. The value ranges from **-90** to **90**. Only the WGS84 coordinate system is supported.|
| longitude | number | No| Yes | Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude . The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported.|
| locale | string | No| Yes | Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| placeName | string | No| Yes | Address information.|
| countryCode | string | No| Yes | Country code.|
| countryName | string | No| Yes| Country name.|
| administrativeArea | string | No| Yes| Level-1 administrative region, which is generally is a province or state.|
| subAdministrativeArea | string | No| Yes| Level-2 administrative region, which is generally is a city.|
| locality | string | No| Yes| Locality information, which is usually a city.|
| subLocality | string | No| Yes| Sub-locality information, which is usually a district or county.|
| roadName | string | No| Yes| Road name.|
| subRoadName | string | No| Yes| Auxiliary road information.|
| premises | string | No| Yes| House information.|
| postalCode | string | No| Yes| Postal code.|
| phoneNumber | string | No| Yes| Phone number.|
| addressUrl | string | No| Yes| Website URL.|
| descriptions | Array&lt;string&gt; | No| Yes| Additional description. It contains **cityCode** (the array subscript is **0**) and **adminCode** (the array subscript is **1**), for example, **["025","320114001"]**.|
| descriptionsSize | number | No| Yes| Total number of additional descriptions. The specified value must be greater than or equal to **0**. A value smaller than **10** is recommended.|


## LocationRequest

Defines a location request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | No| Yes| Priority of the location request. This parameter is effective only when **scenario** is set to **UNSET**. If this parameter and **scenario** are set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestPriority](#locationrequestpriority).|
| scenario | [LocationRequestScenario](#locationrequestscenario) | No| Yes| Scenario of the location request. The **priority** parameter is effective only when this parameter is set to **UNSET**. If this parameter and **priority** are set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestScenario](#locationrequestscenario).|
| timeInterval | number | No| Yes|  Time interval at which location information is reported, in seconds.<br>The value is greater than or equal to 0.<br>The default value is the minimum interval allowed in the corresponding positioning mode.<br>The default value is 1s for GNSS positioning and 20s for network positioning.<br>If the value is less than the minimum interval, the minimum interval takes effect.<br>If the value is set to **0**, location information is directly reported without checking of the time interval.|
| distanceInterval | number | No| Yes| Distance interval at which location information is reported, in meters. The specified value must be greater than or equal to **0**. The default value is **0**. If this parameter is set to **0**, there is no limitation on the location reporting distance.|
| maxAccuracy | number | No| Yes|  Location accuracy requested by the application, in meters. This parameter is valid only when the precise location function is enabled (both the **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION** permissions are granted). It is invalid when the approximate location function is enabled (only the **ohos.permission.APPROXIMATELY\_LOCATION** permission is enabled).<br>When this parameter is effective, the system compares the [location](#location) information reported by the GNSS or network location service with the location information requested by the application. If the accuracy in the reported [location](#location) information is less than or equal to **maxAccuracy**, the system sends the reported location information to the application. Otherwise, the system discards the location information.<br>The value must be greater than or equal to **0**. The default value is **0**, indicating no limitation on the location accuracy.<br>If **scenario** is set to **NAVIGATION**, **TRAJECTORY_TRACKING**, or **CAR_HAILING** or **priority** is set to **ACCURACY**, you are advised to set **maxAccuracy** to a value greater than **10**.<br>If scenario is set to **DAILY_LIFE_SERVICE** or **NO_POWER** or **priority** is set to **LOW_POWER** or **FIRST_FIX**, you are advised to set **maxAccuracy** to a value greater than **100**.<br>|


## CurrentLocationRequest

Defines a location request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | No| Yes| Priority of the location request. This parameter is effective only when **scenario** is set to **UNSET**. If this parameter and **scenario** are set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestPriority](#locationrequestpriority).|
| scenario | [LocationRequestScenario](#locationrequestscenario) | No| Yes| Scenario of the location request. The **priority** parameter is effective only when this parameter is set to **UNSET**. If this parameter and **priority** are set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestScenario](#locationrequestscenario).|
| maxAccuracy | number | No| Yes|  Location accuracy requested by the application, in meters. This parameter is valid only when the precise location function is enabled (both the **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION** permissions are granted). It is invalid when the approximate location function is enabled (only the **ohos.permission.APPROXIMATELY\_LOCATION** permission is enabled).<br>When this parameter is effective, the system compares the [location](#location) information reported by the GNSS or network location service with the location information requested by the application. If the accuracy in the reported [location](#location) information is less than or equal to **maxAccuracy**, the system sends the reported location information to the application. Otherwise, the system discards the location information.<br>The value must be greater than or equal to **0**. The default value is **0**, indicating no limitation on the location accuracy.<br>If **scenario** is set to **NAVIGATION**, **TRAJECTORY_TRACKING**, or **CAR_HAILING** or **priority** is set to **ACCURACY**, you are advised to set **maxAccuracy** to a value greater than **10**.<br>If scenario is set to **DAILY_LIFE_SERVICE** or **NO_POWER** or **priority** is set to **LOW_POWER** or **FIRST_FIX**, you are advised to set **maxAccuracy** to a value greater than **100**.|
| timeoutMs | number | No| Yes| Timeout duration, in milliseconds. The minimum value is **1000**. The specified value must be greater than or equal to **1000**.|


## ContinuousLocationRequest<sup>12+</sup>

Defines a continuous location request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| interval | number | No| No| Time interval at which location information is reported, in seconds. The specified value must be greater than or equal to **0**. The default value is **1**. If this parameter is set to **0**, there is no limitation on the location reporting interval.|
| locationScenario | [UserActivityScenario](#useractivityscenario12) &#124; [PowerConsumptionScenario](#powerconsumptionscenario12) | No| No| Location scenario. For details, see [UserActivityScenario](#useractivityscenario12) and [PowerConsumptionScenario](#powerconsumptionscenario12).|
| sportsType<sup>18+</sup> | [SportsType](#sportstype18) | No| Yes| Sports type.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|


## SingleLocationRequest<sup>12+</sup>

Defines a single location request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| locatingPriority | [LocatingPriority](#locatingpriority12) | No| No| Priority of the location request. For details, see [LocatingPriority](#locatingpriority12).|
| locatingTimeoutMs | number | No| No| Timeout duration, in milliseconds. The minimum value is **1000**. The specified value must be greater than or equal to **1000**.|


## SatelliteStatusInfo

Defines the satellite status information.

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| satellitesNumber | number | No| No| Number of satellites. The specified value must be greater than or equal to **0**.|
| satelliteIds | Array&lt;number&gt; | No| No| Array of satellite IDs. The specified value must be greater than or equal to **0**.|
| carrierToNoiseDensitys | Array&lt;number&gt; | No| No| Carrier-to-noise density ratio, that is, **cn0**. The specified value must be greater than **0**.|
| altitudes | Array&lt;number&gt; | No| No| Satellite altitude angle information. The value ranges from **-90** to **90**, in degrees.|
| azimuths | Array&lt;number&gt; | No| No| Azimuth information. The value ranges from **0** to **360**, in degrees.|
| carrierFrequencies | Array&lt;number&gt; | No| No| Carrier frequency, in Hz. The specified value must be greater than or equal to **0**.|
| satelliteConstellation<sup>12+</sup> | Array&lt;[SatelliteConstellationCategory](#satelliteconstellationcategory12)&gt; | No| Yes| Satellite constellation type.|
| satelliteAdditionalInfo<sup>12+</sup> | Array&lt;number&gt; | No| Yes| Additional satellite information.<br>Each bit has a different meaning. For details, see [SatelliteAdditionalInfo](#satelliteadditionalinfo12).|


## CachedGnssLocationsRequest

Defines a request for reporting cached GNSS locations.

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| reportingPeriodSec | number | No| No| Interval for reporting the cached GNSS locations, in milliseconds. The specified value must be greater than **0**.|
| wakeUpCacheQueueFull | boolean | No| No | **true**: reports the cached GNSS locations to the application when the cache queue is full.<br>**false**: discards the cached GNSS locations when the cache queue is full.|


## Geofence

Defines a GNSS geofence. Currently, only circular geofences are supported.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | No| No|Latitude information. The value ranges from **-90** to **90**.|
| longitude | number | No|No| Longitude information. The value ranges from **-180** to **180**.|
| coordinateSystemType<sup>12+</sup> | [CoordinateSystemType](#coordinatesystemtype12) | No|Yes| Coordinate system of the circle center of a geofence.<br>The application needs to call [getGeofenceSupportedCoordTypes](#geolocationmanagergetgeofencesupportedcoordtypes12) to query the supported coordinate systems and then pass in the correct coordinates of the circle center.|
| radius | number | No|No| Radius of a circular geofence, in meters. The specified value must be greater than **0**.|
| expiration | number | No|No| Expiration period of a geofence, in milliseconds. The specified value must be greater than **0**.|


## GeofenceRequest

Defines a geofence request.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| scenario | [LocationRequestScenario](#locationrequestscenario) | No| No |  Location scenario.|
| geofence |  [Geofence](#geofence)| No| No |  Geofence information.|


## LocationCommand

Defines a location command.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| scenario | [LocationRequestScenario](#locationrequestscenario)  | No| No | Location scenario.|
| command | string | No| No | Extended command, in the string format.|


## Location

Location information.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number| No| No| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from **-90** to **90**. Only the WGS84 coordinate system is supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| longitude | number| No| No| Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude . The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| altitude | number | No| No| Location altitude, in meters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| accuracy | number | No| No| Location accuracy, in meters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| speed | number | No| No|Speed, in m/s.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| timeStamp | number | No| No| Location timestamp in the UTC format.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| direction | number | No| No| Direction information. The value ranges from **0** to **360**, in degrees.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| timeSinceBoot | number | No| No| Timestamp when the location is successfully obtained. The value is the duration from the time when the device is booted to the time when the location is obtained, in nanoseconds.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| additions | Array&lt;string&gt;| No| Yes| Additional description.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| additionSize | number| No| Yes| Number of additional descriptions. The specified value must be greater than or equal to **0**.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| additionsMap<sup>12+</sup> | Map&lt;string, string&gt;| No| Yes| Additional description. The content and sequence are the same as those of **additions**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| altitudeAccuracy<sup>12+</sup> |number | No| Yes| Height accuracy, in meters.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| speedAccuracy<sup>12+</sup> | number| No| Yes| Speed accuracy, in meters per second.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| directionAccuracy<sup>12+</sup> | number| No| Yes| Direction accuracy. The value ranges from **0** to **360**, in degrees.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| uncertaintyOfTimeSinceBoot<sup>12+</sup> | number| No| Yes| Uncertainty of the location timestamp.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| sourceType<sup>12+</sup> | [LocationSourceType](#locationsourcetype12) | No| Yes| Source of the location result.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|


## GeofenceTransition<sup>12+</sup>

Defines a geofence transition event.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| geofenceId | number| No| No| Geofence ID.|
| transitionEvent | [GeofenceTransitionEvent](#geofencetransitionevent12) | No| No| Geofence transition event.|


## GnssGeofenceRequest<sup>12+</sup>

Defines a GNSS geofence request.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| geofence | [Geofence](#geofence) | No| No| Geofence information, including the coordinates and radius of the circle center.|
| monitorTransitionEvents | Array&lt;[GeofenceTransitionEvent](#geofencetransitionevent12)&gt; | No| No| List of geofence transition events.|
| notifications | Array&lt;[NotificationRequest](../apis-notification-kit/js-apis-notification.md#notificationrequest)&gt; | No| Yes| List of notifications for geofence transition events.<br>The sequence of **monitorTransitionEvents** must correspond to that of **notifications**. For example, if **monitorTransitionEvents[0]** is **[GeofenceTransitionEvent](#geofencetransitionevent12).GEOFENCE_TRANSITION_EVENT_ENTER**, **notifications[0]** must be set to the notification that needs to be displayed when a user enters the geofence.|
| geofenceTransitionCallback | AsyncCallback&lt;[GeofenceTransition](#geofencetransition12)&gt; | No| No| Callback used to receive geofence transition events.|


## CountryCode

Defines the country code information.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| country | string | No| No| Country code.|
| type |  [CountryCodeType](#countrycodetype) | No| No| Country code source.|


## LocationRequestPriority

Sets the priority of a location request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| UNSET | 0x200 | Priority unspecified.<br>If this option is used, [LocationRequestPriority](#locationrequestpriority) is invalid.|
| ACCURACY | 0x201 | Location accuracy.<br>The location accuracy priority mainly uses the GNSS positioning technology. The system uses the network positioning technology as an alternative to provide the location service for your application until the GNSS can provide stable location results. During the continuous location process, the network positioning technology is used if the GNSS location result cannot be obtained within 30 seconds. This policy can lead to significant hardware resource consumption and power consumption.|
| LOW_POWER | 0x202 | Power efficiency.<br>This policy uses only the network positioning technology to obtain device location in both indoor and outdoor scenarios. The location accuracy depends on the distribution of surrounding base stations, visible WLANs, and Bluetooth devices and therefore may fluctuate greatly. This policy is recommended and can reduce power consumption if a high location accuracy is not required.|
| FIRST_FIX | 0x203 | Fast location preferred. Use this option if you want to obtain a location as fast as possible.<br>This policy uses the GNSS positioning and network positioning technologies simultaneously to obtain the device location in both the indoor and outdoor scenarios. When all positioning technologies provide a location result, the system provides the most accurate location result for your application. It can lead to significant hardware resource consumption and power consumption.|


## LocationRequestScenario

Defines the location scenario in a location request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

> **NOTE**
>
> If a single location or continuous location is initiated in the NAVIGATION, TRAJECTORY_TRACKING, or CAR_HAILING scenario, the system uses the network positioning technology as an alternative to provide the location service for your application until the GNSS can provide stable location results. During the continuous location process, the network positioning technology is used if the GNSS location result cannot be obtained within 30 seconds.

| Name| Value| Description|
| -------- | -------- | -------- |
| UNSET | 0x300 | Scenario unspecified.<br>If this option is used, [LocationRequestScenario](#locationrequestscenario) is invalid.|
| NAVIGATION | 0x301 | Navigation.<br>This option is applicable when your application needs to obtain the real-time location of a mobile device outdoors, such as navigation for driving or walking.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| TRAJECTORY_TRACKING | 0x302 | Trajectory tracking.<br>This option is applicable when your application needs to record user trajectories, for example, the track recording function of sports applications.<br>It mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| CAR_HAILING | 0x303 | Ride hailing.<br>This option is applicable when your application needs to obtain the current location of a user who is hailing a taxi.<br>It mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
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


## PowerConsumptionScenario<sup>12+</sup>

Enumerates power consumption scenarios in a location request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| HIGH_POWER_CONSUMPTION  | 0x601 | High power consumption.<br>The mode mainly uses the GNSS positioning technology. The system uses the network positioning technology as an alternative to provide the location service for your application until the GNSS can provide stable location results. During the continuous location process, the network positioning technology is used if the GNSS location result cannot be obtained within 30 seconds. This policy can lead to significant hardware resource consumption and power consumption.|
| LOW_POWER_CONSUMPTION  | 0x602 | Low power consumption.<br>This mode is applicable when your application only needs the approximate location in scenarios such as when the user is browsing news, shopping online, and ordering food.<br>It mainly uses the network positioning technology and therefore the power consumption is relatively low.|
| NO_POWER_CONSUMPTION   | 0x603 | No power consumption.<br>Your application does not proactively start the location service. When responding to another application requesting the same location service, the system marks a copy of the location result to your application.  |


## UserActivityScenario<sup>12+</sup>

Enumerates user activity scenarios in a location request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Location.Location.Core

> **NOTE**
>
> If a single location or continuous location is initiated in the NAVIGATION, SPORT, or TRANSPORT scenario, the system uses the network positioning technology as an alternative to provide the location service for your application until the GNSS can provide stable location results. During the continuous location process, the network positioning technology is used if the GNSS location result cannot be obtained within 30 seconds.

| Name| Value| Description|
| -------- | -------- | -------- |
| NAVIGATION  | 0x401 | Navigation scenario.<br>This option is applicable when your application needs to obtain the real-time location of a mobile device outdoors, such as navigation for driving or walking.<br>It mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| SPORT  | 0x402 | Sport scenario.<br>This option is applicable when your application needs to record user trajectories, for example, the track recording function of sports applications.<br>It mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| TRANSPORT   | 0x403 | Travel scenario.<br>This option is applicable to user travel scenarios, such as taxi hailing and public transportation.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high. |
| DAILY_LIFE_SERVICE   | 0x404 | Daily life service scenario.<br>This option is applicable when your application only needs the approximate location in scenarios such as when the user is browsing news, shopping online, and ordering food.<br>It mainly uses the network positioning technology and therefore the power consumption is relatively low. |


## LocatingPriority<sup>12+</sup>

Enumerates priority types in a single location request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| PRIORITY_ACCURACY  | 0x501 | Location accuracy.<br>This policy uses both the GNSS positioning and network positioning technologies and provides the most accurate location result within the specified period of time, which is the smaller one between [SingleLocationRequest](#singlelocationrequest12).locatingTimeoutMs and 30 seconds.<br>This policy can lead to significant hardware resource consumption and power consumption. |
| PRIORITY_LOCATING_SPEED  | 0x502 | Fast location preferred. Use this policy if you want to obtain a location as fast as possible.<br>This policy uses the GNSS positioning and network positioning technologies simultaneously to obtain the device location in both the indoor and outdoor scenarios and provides the first obtained location result to your application. This policy can lead to significant hardware resource consumption and power consumption.|


## LocationError<sup>12+</sup>

Enumerates error codes in a continuous location request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| LOCATING_FAILED_DEFAULT   | -1 |  Unknown type. This is the default value.|
| LOCATING_FAILED_LOCATION_PERMISSION_DENIED   | -2 | Failed to verify the **ohos.permission.APPROXIMATELY_LOCATION** or **ohos.permission.LOCATION** permission.|
| LOCATING_FAILED_BACKGROUND_PERMISSION_DENIED    | -3 | Failed to verify the location permission when the application is running in the background. For details about how to apply for the location permission, see [Applying for Location Permissions](../../device/location/location-guidelines.md#applying-for-location-permissions).|
| LOCATING_FAILED_LOCATION_SWITCH_OFF    | -4 | Location switch turned off.|
| LOCATING_FAILED_INTERNET_ACCESS_FAILURE    | -5 | Network access denied.|


## LocationSourceType<sup>12+</sup>

Defines the source of the location result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| GNSS   | 1 |  GNSS positioning technology.|
| NETWORK    | 2 | Network positioning technology.|
| INDOOR     | 3 | Indoor high-precision positioning technology.|
| RTK     | 4 | Outdoor high-precision positioning technology.|


## BluetoothScanResult<sup>16+</sup>

Defines the Bluetooth scan result.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes| No| Address of the device discovered, for example, XX:XX:XX:XX:XX:XX.|
| rssi | number | Yes| No| RSSI of the device.|
| data | ArrayBuffer | Yes| Yes| Advertising packets sent by the device.|
| deviceName | string | Yes| No| Name of the device detected.|
| connectable | boolean | Yes| No| Whether the discovered device is connectable. The value **true** means the discovered device is connectable, and the value **false** means the opposite.|


## SportsType<sup>18+</sup>

Enumerates sports types.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| RUNNING   | 1 |  Running.|
| WALKING    | 2 | Walking.|
| CYCLING     | 3 | Cycling.|


## geoLocationManager.on('locationChange')

on(type: 'locationChange', request: LocationRequest | ContinuousLocationRequest, callback: Callback&lt;Location&gt;): void

Subscribes to location change events with a location request initiated. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationChange** indicates a location change.|
  | request |  [LocationRequest](#locationrequest) &#124; [ContinuousLocationRequest](#continuouslocationrequest12) | Yes| Location request.<br>**ContinuousLocationRequest** is newly added in API version 12.|
  | callback | Callback&lt;[Location](#location)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('locationChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  // Method 1: Use LocationRequest as the input parameter.
  let requestInfo:geoLocationManager.LocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET, 'timeInterval': 1, 'distanceInterval': 0, 'maxAccuracy': 0};
  let locationChange = (location:geoLocationManager.Location):void => {
      console.info('locationChanger: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', requestInfo, locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }

  // Method 2: Use ContinuousLocationRequest as the input parameter.
  let request:geoLocationManager.ContinuousLocationRequest = {'interval': 1, 'locationScenario': geoLocationManager.UserActivityScenario.NAVIGATION};
  let locationCallback = (location:geoLocationManager.Location):void => {
      console.info('locationCallback: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', request, locationCallback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.off('locationChange')

off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void

Unregisters the listener for location change events with the corresponding location request deleted.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationChange** indicates a location change.|
  | callback | Callback&lt;[Location](#location)&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locationChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let requestInfo:geoLocationManager.LocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET, 'timeInterval': 1, 'distanceInterval': 0, 'maxAccuracy': 0};
  let locationChange = (location:geoLocationManager.Location):void => {
    console.info('locationChanger: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', requestInfo, locationChange);
      geoLocationManager.off('locationChange', locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.on('locationError')<sup>12+</sup>

on(type: 'locationError', callback: Callback&lt;LocationError&gt;): void

Registers a listener for error codes generated during continuous location. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. To subscribe to error codes generated during continuous location, set the value to **locationError**.|
  | callback | Callback&lt;[LocationError](#locationerror12)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('locationError')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let requestInfo:geoLocationManager.LocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET, 'timeInterval': 1, 'distanceInterval': 0, 'maxAccuracy': 0};
  let locationChange = (location:geoLocationManager.Location):void => {
      console.info('locationChanger: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', requestInfo, locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }

  let locationErrorChange = (errcode: geoLocationManager.LocationError):void => {
    console.info('locationErrorChange: data: ' + JSON.stringify(errcode));
  };
  try {
    geoLocationManager.on('locationError', locationErrorChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  
  ```


## geoLocationManager.off('locationError')<sup>12+</sup>

off(type: 'locationError', callback?: Callback&lt;LocationError&gt;): void

Unregisters the listener for error codes generated during continuous location.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. To subscribe to error codes generated during continuous location, set the value to **locationError**.|
  | callback | Callback&lt;[LocationError](#locationerror12)&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locationError')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let locationErrorChange = (errcode: geoLocationManager.LocationError):void => {
    console.info('locationErrorChange: data: ' + JSON.stringify(errcode));
  };
  try {
    geoLocationManager.on('locationError', locationErrorChange);
    geoLocationManager.off('locationError', locationErrorChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:"  + err.message);
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
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('locationEnabledChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let locationEnabledChange = (state:boolean):void => {
      console.info('locationEnabledChange: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.off('locationEnabledChange')

off(type: 'locationEnabledChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from location service status change events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationEnabledChange** indicates a location service status change.|
  | callback | Callback&lt;boolean&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locationEnabledChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let locationEnabledChange = (state:boolean):void => {
      console.info('locationEnabledChange: state: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
      geoLocationManager.off('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.on('cachedGnssLocationsChange')

on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;): void

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('cachedGnssLocationsChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let cachedLocationsCb = (locations:Array<geoLocationManager.Location>):void => {
      console.info('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  let requestInfo:geoLocationManager.CachedGnssLocationsRequest = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  try {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.off('cachedGnssLocationsChange')

off(type: 'cachedGnssLocationsChange', callback?: Callback&lt;Array&lt;Location&gt;&gt;): void

Unsubscribes from cached GNSS location reports. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **cachedGnssLocationsChange** indicates reporting of cached GNSS locations.|
  | callback | Callback&lt;Array&lt;[Location](#location)&gt;&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('cachedGnssLocationsChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let cachedLocationsCb = (locations:Array<geoLocationManager.Location>):void => {
      console.info('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  let requestInfo:geoLocationManager.CachedGnssLocationsRequest = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  try {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
      geoLocationManager.off('cachedGnssLocationsChange');
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.on('satelliteStatusChange')

on(type: 'satelliteStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;): void

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('satelliteStatusChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let gnssStatusCb = (satelliteStatusInfo:geoLocationManager.SatelliteStatusInfo):void => {
      console.info('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
      // Number of satellites.
      let totalNumber: number = satelliteStatusInfo.satellitesNumber;
      let satelliteIds: Array<number> = satelliteStatusInfo.satelliteIds;
      let carrierToNoiseDensitys: Array<number> = satelliteStatusInfo.carrierToNoiseDensitys;
      let altitudes: Array<number> = satelliteStatusInfo.altitudes;
      let azimuths: Array<number> = satelliteStatusInfo.azimuths;
      let carrierFrequencies: Array<number> = satelliteStatusInfo.carrierFrequencies;
      let satelliteConstellations: Array<geoLocationManager.SatelliteConstellationCategory> | undefined = satelliteStatusInfo.satelliteConstellation;
      let satelliteAdditionalInfos: Array<number> | undefined = satelliteStatusInfo.satelliteAdditionalInfo;
      for (let i = 0;i < totalNumber;i++) {
        // Satellite ID.
        let satelliteId: Number = satelliteIds[i];
        // Carrier-to-noise density ratio of the satellite whose ID is ${satelliteId}.
        let carrierToNoiseDensity: Number = carrierToNoiseDensitys[i];
        // Altitude angle information of the satellite whose ID is ${satelliteId}.
        let altitude: Number = altitudes[i];
        // Azimuth of the satellite whose ID is ${satelliteId}.
        let azimuth: Number = azimuths[i];
        // Carrier frequency of the satellite whose ID is ${satelliteId}.
        let carrierFrequencie: Number = carrierFrequencies[i];
        if (satelliteConstellations != undefined) {
          // Constellation of the satellite whose ID is ${satelliteId}.
          let satelliteConstellation: geoLocationManager.SatelliteConstellationCategory = satelliteConstellations[i];
        }
        if (satelliteAdditionalInfos != undefined) {
          // Additional information about the satellite whose ID is ${satelliteId}, for example, use of the satellite in the latest location resolution and the availability of ephemeris data, almanac data, and carrier frequency information.
          let satelliteAdditionalInfo: Number = satelliteAdditionalInfos[i];
        }
      }
  }

  try {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.off('satelliteStatusChange')

off(type: 'satelliteStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;): void

Unsubscribes from GNSS satellite status change events.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **satelliteStatusChange** indicates a GNSS satellite status change.|
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('satelliteStatusChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |


**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let gnssStatusCb = (satelliteStatusInfo:geoLocationManager.SatelliteStatusInfo):void => {
      console.info('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  try {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
      geoLocationManager.off('satelliteStatusChange', gnssStatusCb);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.on('nmeaMessage')

on(type: 'nmeaMessage', callback: Callback&lt;string&gt;): void

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('nmeaMessage')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |


**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let nmeaCb = (str:string):void => {
      console.info('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
      geoLocationManager.on('nmeaMessage', nmeaCb );
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.off('nmeaMessage')

off(type: 'nmeaMessage', callback?: Callback&lt;string&gt;): void

Unsubscribes from GNSS NMEA message change events.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **nmeaMessage** indicates a GNSS NMEA message change.|
  | callback | Callback&lt;string&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('nmeaMessage')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |


**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let nmeaCb = (str:string):void => {
      console.info('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
      geoLocationManager.on('nmeaMessage', nmeaCb);
      geoLocationManager.off('nmeaMessage', nmeaCb);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.on('gnssFenceStatusChange')

on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('gnssFenceStatusChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |
|3301600 | Failed to operate the geofence.                                     |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { wantAgent } from '@kit.AbilityKit';


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
        console.error("errCode:" + err.code + ", message:"  + err.message);
    }
  });
  ```


## geoLocationManager.off('gnssFenceStatusChange')

off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('gnssFenceStatusChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |
|3301600 | Failed to operate the geofence.                                     |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { wantAgent } from '@kit.AbilityKit';

  
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
        console.error("errCode:" + err.code + ", message:"  + err.message);
    }
  });
  ```


## geoLocationManager.on('countryCodeChange')

on(type: 'countryCodeChange', callback: Callback&lt;CountryCode&gt;): void

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
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('countryCodeChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301500 | Failed to query the area information.                                       |


**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let callback = (code:geoLocationManager.CountryCode):void => {
      console.info('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
      geoLocationManager.on('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.off('countryCodeChange')

off(type: 'countryCodeChange', callback?: Callback&lt;CountryCode&gt;): void

Unsubscribes from country code change events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **countryCodeChange** indicates a country code change.|
  | callback | Callback&lt;[CountryCode](#countrycode)&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('countryCodeChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301500 | Failed to query the area information.                                       |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let callback = (code:geoLocationManager.CountryCode):void => {
      console.info('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
      geoLocationManager.on('countryCodeChange', callback);
      geoLocationManager.off('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.getCurrentLocation

getCurrentLocation(request: CurrentLocationRequest | SingleLocationRequest, callback: AsyncCallback&lt;Location&gt;): void

Obtains the current position. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) &#124;  [SingleLocationRequest](#singlelocationrequest12) | Yes| Location request.<br>**SingleLocationRequest** is newly added in API version 12.|
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getCurrentLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  // Method 1: Use CurrentLocationRequest as the input parameter.
  let requestInfo:geoLocationManager.CurrentLocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET,'maxAccuracy': 0};
  let locationChange = (err:BusinessError, location:geoLocationManager.Location):void => {
      if (err) {
          console.error('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.info('locationChanger: location=' + JSON.stringify(location));
      }
  };

  try {
      geoLocationManager.getCurrentLocation(requestInfo, locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  
  // Method 2: Use SingleLocationRequest as the input parameter.
  let request:geoLocationManager.SingleLocationRequest = {'locatingTimeoutMs': 10000, 'locatingPriority': geoLocationManager.LocatingPriority.PRIORITY_ACCURACY};
  let locationCallback = (err:BusinessError, location:geoLocationManager.Location):void => {
      if (err) {
          console.error('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.info('locationChanger: location=' + JSON.stringify(location));
      }
  };

  try {
      geoLocationManager.getCurrentLocation(request, locationCallback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.getCurrentLocation

getCurrentLocation(callback: AsyncCallback&lt;Location&gt;): void

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getCurrentLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let locationChange = (err:BusinessError, location:geoLocationManager.Location) => {
      if (err) {
          console.error('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.info('locationChanger: location=' + JSON.stringify(location));
      }
  };

  try {
      geoLocationManager.getCurrentLocation(locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.getCurrentLocation

getCurrentLocation(request?: CurrentLocationRequest | SingleLocationRequest): Promise&lt;Location&gt;

Obtains the current position. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) &#124; [SingleLocationRequest](#singlelocationrequest12) | No| Location request.<br>**SingleLocationRequest** is newly added in API version 12.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getCurrentLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Method 1: Use CurrentLocationRequest as the input parameter.
  let requestInfo:geoLocationManager.CurrentLocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET,'maxAccuracy': 0};
  try {
      geoLocationManager.getCurrentLocation(requestInfo).then((result) => {
          console.info('current location: ' + JSON.stringify(result));
      })  
      .catch((error:BusinessError) => {
          console.error('promise, getCurrentLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  
  // Method 2: Use SingleLocationRequest as the input parameter.
  let request:geoLocationManager.SingleLocationRequest = {'locatingTimeoutMs': 10000, 'locatingPriority': geoLocationManager.LocatingPriority.PRIORITY_ACCURACY};
  try {
      geoLocationManager.getCurrentLocation(request).then((result) => {
          console.info('current location: ' + JSON.stringify(result));
      })  
      .catch((error:BusinessError) => {
          console.error('promise, getCurrentLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getLastLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable. |
|3301100 | The location switch is off.  |
|3301200 |Failed to obtain the geographical location.  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let location = geoLocationManager.getLastLocation();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
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
|801 | Capability not supported. Failed to call ${geoLocationManager.isLocationEnabled} due to limited device capabilities.          |
|3301000 | The location service is unavailable. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let locationEnabled = geoLocationManager.isLocationEnabled();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
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
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getAddressesFromLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301300 | Reverse geocoding query failed.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let reverseGeocodeRequest:geoLocationManager.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
          if (err) {
              console.error('getAddressesFromLocation: err=' + JSON.stringify(err));
          }
          if (data) {
              console.info('getAddressesFromLocation: data=' + JSON.stringify(data));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;

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
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getAddressesFromLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301300 | Reverse geocoding query failed.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let reverseGeocodeRequest:geoLocationManager.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {
          console.info('getAddressesFromLocation: ' + JSON.stringify(data));
      })
      .catch((error:BusinessError) => {
          console.error('promise, getAddressesFromLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
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
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getAddressesFromLocationName} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301400 | Geocoding query failed.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let geocodeRequest:geoLocationManager.GeoCodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {
          if (err) {
              console.error('getAddressesFromLocationName: err=' + JSON.stringify(err));
          }
          if (data) {
              console.info('getAddressesFromLocationName: data=' + JSON.stringify(data));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
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
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getAddressesFromLocationName} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301400 | Geocoding query failed.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let geocodeRequest:geoLocationManager.GeoCodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocationName(geocodeRequest).then((result) => {
          console.info('getAddressesFromLocationName: ' + JSON.stringify(result));
      })
      .catch((error:BusinessError) => {
          console.error('promise, getAddressesFromLocationName: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.isGeocoderAvailable

isGeocoderAvailable(): boolean

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
|801 | Capability not supported. Failed to call ${geoLocationManager.isGeocoderAvailable} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let isAvailable = geoLocationManager.isGeocoderAvailable();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;): void

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getCachedGnssLocationsSize} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301100 | The location switch is off.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.getCachedGnssLocationsSize((err, size) => {
          if (err) {
              console.error('getCachedGnssLocationsSize: err=' + JSON.stringify(err));
          }
          if (size) {
              console.info('getCachedGnssLocationsSize: size=' + JSON.stringify(size));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(): Promise&lt;number&gt;

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getCachedGnssLocationsSize} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301100 | The location switch is off.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  try {
      geoLocationManager.getCachedGnssLocationsSize().then((result) => {
          console.info('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));
      }) 
      .catch((error:BusinessError) => {
          console.error('promise, getCachedGnssLocationsSize: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(callback: AsyncCallback&lt;void&gt;): void

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.flushCachedGnssLocations} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301100 | The location switch is off.   |
|3301200 | Failed to obtain the geographical location.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.flushCachedGnssLocations((err) => {
          if (err) {
              console.error('flushCachedGnssLocations: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(): Promise&lt;void&gt;

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.flushCachedGnssLocations} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301100 | The location switch is off.   |
|3301200 | Failed to obtain the geographical location.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  try {
      geoLocationManager.flushCachedGnssLocations().then(() => {
          console.info('promise, flushCachedGnssLocations success');
      })
      .catch((error:BusinessError) => {
          console.error('promise, flushCachedGnssLocations: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.sendCommand

sendCommand(command: LocationCommand, callback: AsyncCallback&lt;void&gt;): void

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
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.sendCommand} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  let requestInfo:geoLocationManager.LocationCommand = {'scenario': 0x301, 'command': "command_1"};
  try {
      geoLocationManager.sendCommand(requestInfo, (err) => {
          if (err) {
              console.error('sendCommand: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.sendCommand

sendCommand(command: LocationCommand): Promise&lt;void&gt;

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
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.sendCommand} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  let requestInfo:geoLocationManager.LocationCommand = {'scenario': 0x301, 'command': "command_1"};
  try {
      geoLocationManager.sendCommand(requestInfo).then(() => {
          console.info('promise, sendCommand success');
      })  
      .catch((error:BusinessError) => {
          console.error('promise, sendCommand: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.getCountryCode

getCountryCode(callback: AsyncCallback&lt;CountryCode&gt;): void

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
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getCountryCode} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301500 | Failed to query the area information.|

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      geoLocationManager.getCountryCode((err, result) => {
          if (err) {
              console.error('getCountryCode: err=' + JSON.stringify(err));
          }
          if (result) {
              console.info('getCountryCode: result=' + JSON.stringify(result));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```


## geoLocationManager.getCountryCode

getCountryCode(): Promise&lt;CountryCode&gt;

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
|801 | Capability not supported. Failed to call ${geoLocationManager.getCountryCode} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301500 | Failed to query the area information.|

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  try {
      geoLocationManager.getCountryCode()
      .then((result) => {
          console.info('promise, getCountryCode: result=' + JSON.stringify(result));
      })
      .catch((error:BusinessError) => {
          console.error('promise, getCountryCode: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.addGnssGeofence<sup>12+</sup>

addGnssGeofence(fenceRequest: GnssGeofenceRequest): Promise&lt;number&gt;

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.addGnssGeofence} due to limited device capabilities.          |
|3301000 | The location service is unavailable.|
|3301100  | The location switch is off.|
|3301601   | The number of geofences exceeds the maximum.|

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { notificationManager } from '@kit.NotificationKit';
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
    geofenceTransitionCallback: (err : BusinessError, transition : geoLocationManager.GeofenceTransition) => {
      if (err) {
        console.error('geofenceTransitionCallback: err=' + JSON.stringify(err));
      }
      if (transition) {
        console.info("GeofenceTransition: %{public}s", JSON.stringify(transition));
    }
    }
  }
  try {
    // Add a geofence.
    geoLocationManager.addGnssGeofence(gnssGeofenceRequest).then((id) => {
      // Obtain the geofence ID after the geofence is successfully added.
      console.info("addGnssGeofence success, fence id: " + id);
      let fenceId = id;
    }).catch((err: BusinessError) => {
      console.error("addGnssGeofence failed, promise errCode:" + (err as BusinessError).code + 
        ",errMessage:" + (err as BusinessError).message);
    });
  } catch(error) {
      console.error("addGnssGeofence failed, err:" + JSON.stringify(error));
  }
  ```
  

## geoLocationManager.removeGnssGeofence<sup>12+</sup>

removeGnssGeofence(geofenceId: number): Promise&lt;void&gt;

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
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.removeGnssGeofence} due to limited device capabilities.          |
|3301000 | The location service is unavailable. |
|3301602 | Failed to delete a geofence due to an incorrect ID. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  // fenceId is obtained after geoLocationManager.addGnssGeofence is successfully executed.
  let fenceId = 1;
  try {
    geoLocationManager.removeGnssGeofence(fenceId).then(() => {
      console.info("removeGnssGeofence success fenceId:" + fenceId);
    }).catch((error : BusinessError) => {
      console.error("removeGnssGeofence: error=" + JSON.stringify(error));
    });
  } catch(error) {
    console.error("removeGnssGeofence: error=" + JSON.stringify(error));
  }
  ```


## geoLocationManager.getGeofenceSupportedCoordTypes<sup>12+</sup>

getGeofenceSupportedCoordTypes(): Array&lt;CoordinateSystemType&gt;

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
|801 | Capability not supported. Failed to call ${geoLocationManager.getGeofenceSupportedCoordTypes} due to limited device capabilities.          |
|3301000 | The location service is unavailable. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
    let supportedCoordTypes: Array<geoLocationManager.CoordinateSystemType> = geoLocationManager.getGeofenceSupportedCoordTypes();
    console.info("getGeofenceSupportedCoordTypes return:" + JSON.stringify(supportedCoordTypes));
  } catch(error) {
    console.error("getGeofenceSupportedCoordTypes: error=" + JSON.stringify(error));
  }
  ```


## geoLocationManager.getCurrentWifiBssidForLocating<sup>14+</sup>

getCurrentWifiBssidForLocating(): string

Obtains the Basic Service Set Identifier (BSSID) of the connected Wi-Fi access point (AP).

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Wi-Fi Bssid |

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getCurrentWifiBssidForLocating()} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |
|3301900 | Failed to obtain the BSSID of the Wi-Fi hotspot. The Wi-Fi network is not connected. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
    let bssid: string = geoLocationManager.getCurrentWifiBssidForLocating();
    console.info("get wifi bssid:" + bssid);
  } catch(error) {
    console.error("getCurrentWifiBssidForLocating: errCode" + error.code + ", errMessage" + error.message);
  }
  ```


## geoLocationManager.on('bluetoothScanResultChange')<sup>16+</sup>

on(type: 'bluetoothScanResultChange', callback: Callback&lt;BluetoothScanResult&gt;): void

Enables listening for Bluetooth scan information reporting events. This API uses an asynchronous callback to return the result.

This API starts a Bluetooth scan. To avoid high power consumption, you need to call [geoLocationManager.off('bluetoothScanResultChange')](#geolocationmanageroffbluetoothscanresultchange16) to stop Bluetooth scan at a proper time.

Currently, only BLE device scanning is supported.

**Required permissions**: ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **bluetoothScanResultChange** indicates the Bluetooth scan information reporting event.|
  | callback | Callback&lt;[BluetoothScanResult](#bluetoothscanresult16)&gt; | Yes| Callback used to return the Bluetooth scan information.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('bluetoothScanResultChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';


  let callback = (result: geoLocationManager.BluetoothScanResult):void => {
      console.info('bluetoothScanResultChange: ' + JSON.stringify(result));
  };
  try {
      geoLocationManager.on('bluetoothScanResultChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }

  ```


## geoLocationManager.off('bluetoothScanResultChange')<sup>16+</sup>

off(type: 'bluetoothScanResultChange', callback?: Callback&lt;BluetoothScanResult&gt;): void

Disables listening for Bluetooth scan information reporting events.

**Required permissions**: ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **bluetoothScanResultChange** indicates the Bluetooth scan information reporting event.|
  | callback | Callback&lt;[BluetoothScanResult](#bluetoothscanresult16)&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Error Codes]](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('bluetoothScanResultChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let callback = (result: geoLocationManager.BluetoothScanResult):void => {
      console.info('bluetoothScanResultChange: ' + JSON.stringify(result));
  };
  try {
      geoLocationManager.on('bluetoothScanResultChange', callback);
      geoLocationManager.off('bluetoothScanResultChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```
