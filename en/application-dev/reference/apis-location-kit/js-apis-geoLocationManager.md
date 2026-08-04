# @ohos.geoLocationManager (Geolocation Manager)

<!--Kit: Location Kit-->
<!--Subsystem: Location-->
<!--Owner: @liu-binjun-->
<!--Designer: @liu-binjun-->
<!--Tester: @mhy123456789-->
<!--Adviser: @RayShih-->
<!-- md-trans-meta sourceCommit=8b3eb1308c1f3ff0558fd037efb838f97c415f8c translatedAt=2026-07-31T06:44:44.625Z pushedAt=2026-07-31T07:55:12.080Z -->

The **geoLocationManager** module provides basic location services such as Global Navigation Satellite System (GNSS)-based positioning, network positioning (for example, base station positioning or WLAN/Bluetooth positioning), geofencing, as well as geocoding and reverse geocoding.

To use location services, turn on the Location switch on your device. If the switch is turned off while exception capture is disabled, the application may run into an error.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This module supports only the WGS-84 coordinate system.

## Applying for Permissions

<!--RP1-->

For details, see [Applying for Location Permissions (ArkTS)](../../device/location/location-permission-guidelines.md#how-to-develop).

<!--RP1End-->

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
| longitude | number | No| No| Longitude information. A positive value indicates east longitude, and a negative value indicates west longitude. The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported.|
| maxItems | number | No| Yes| Maximum number of location records to be returned. The specified value must be greater than or equal to **0**. A value smaller than **10** is recommended. The default value is **1**.|

## GeoCodeRequest

Defines a geocoding request.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | No| Yes| Language used for the location description. **zh** indicates Chinese, and **en** indicates English. The default language is obtained from **Language and region** in **Settings**.|
| country<sup>12+</sup> | string | No| Yes| Country information. The country code complies with the ISO 3166-1 alpha-2 standard. **CN** indicates China. The default language is obtained from **Language and region** in **Settings**.|
| description | string | No| No| Location information, for example, No. xx, xx Road, Pudong District, Shanghai. The value is a string of a maximum of 100 characters.|
| maxItems | number | No| Yes| Maximum number of location records to be returned. The specified value must be greater than or equal to **0**. A value smaller than **10** is recommended. The default value is **1**.|
| minLatitude | number | No| Yes| Minimum latitude. This parameter is used with **minLongitude**, **maxLatitude**, and **maxLongitude** to specify the latitude and longitude ranges. The value ranges from **-90** to **90**. Only the WGS84 coordinate system is supported. The default value is **0**. The following three parameters are mandatory if this parameter is specified.|
| minLongitude | number | No| Yes| Minimum longitude. The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported. The default value is **0**.|
| maxLatitude | number | No| Yes| Maximum latitude. The value ranges from **-90** to **90**. Only the WGS84 coordinate system is supported. The default value is **0**.|
| maxLongitude | number | No| Yes| Maximum longitude. The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported. The default value is **0**.|

## GeoAddress

Geocoding address information.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | No| Yes | Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from **-90** to **90**. Only the WGS84 coordinate system is supported.|
| longitude | number | No| Yes | Longitude information. A positive value indicates east longitude, and a negative value indicates west longitude. The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported.|
| locale | string | No| Yes | Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| placeName | string | No| Yes | Address information.|
| countryCode | string | No| Yes | Country code.|
| countryName | string | No| Yes| Country name.|
| administrativeArea | string | No| Yes| Level-1 administrative region, which is generally a province or state.|
| subAdministrativeArea | string | No| Yes| Level-2 administrative region, which is generally a city.|
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
| priority | [LocationRequestPriority](#locationrequestpriority) | No| Yes| Priority of the location request. This parameter is effective only when **scenario** is set to **UNSET**. If this parameter and **scenario** are both set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestPriority](#locationrequestpriority). The default value is **FIRST_FIX**.|
| scenario | [LocationRequestScenario](#locationrequestscenario) | No| Yes| Scenario of the location request. The **priority** parameter is effective only when this parameter is set to **UNSET**. If this parameter and **priority** are both set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestScenario](#locationrequestscenario). The default value is **UNSET**.|
| timeInterval | number | No| Yes|  Time interval at which location information is reported, in seconds.<br>The value is greater than or equal to 0.<br>The default value is the minimum interval allowed in the corresponding positioning mode.<br>The default value is 1s for GNSS positioning and 20s for network positioning.<br>If the value is less than the minimum interval, the minimum interval takes effect.<br>If the value is set to **0**, location information is directly reported without checking of the time interval.|
| distanceInterval | number | No| Yes| Distance interval at which location information is reported, in meters. The specified value must be greater than or equal to **0**. The default value is **0**. If this parameter is set to **0**, there is no limitation on the location reporting distance.|
| maxAccuracy | number | No| Yes|  Location accuracy requested by the application, in meters. This parameter is valid only when the precise location function is enabled (both the **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION** permissions are granted). It is invalid when the approximate location function is enabled (only the **ohos.permission.APPROXIMATELY\_LOCATION** permission is enabled).<br>When this parameter is effective, the system compares the [location](#location) information reported by the GNSS or network location service with the location information requested by the application. If the accuracy in the reported [location](#location) information is less than or equal to **maxAccuracy**, the system sends the reported location information to the application. Otherwise, the system discards the location information.<br>The value must be greater than or equal to **0**. The default value is **0**, indicating no limitation on the location accuracy.<br>If **scenario** is set to **NAVIGATION**, **TRAJECTORY_TRACKING**, or **CAR_HAILING** or **priority** is set to **ACCURACY**, you are advised to set **maxAccuracy** to a value greater than **10**.<br>If scenario is set to **DAILY_LIFE_SERVICE** or **NO_POWER** or **priority** is set to **LOW_POWER** or **FIRST_FIX**, you are advised to set **maxAccuracy** to a value greater than **100**.<br>|

## CurrentLocationRequest

Defines a location request.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | No| Yes| Priority of the location request. This parameter is effective only when **scenario** is set to **UNSET**. If this parameter and **scenario** are both set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestPriority](#locationrequestpriority). The default value is **FIRST_FIX**.|
| scenario | [LocationRequestScenario](#locationrequestscenario) | No| Yes| Scenario of the location request. The **priority** parameter is effective only when this parameter is set to **UNSET**. If this parameter and **priority** are both set to **UNSET**, the attempt to initiate a location request will fail. For details about the value range, see [LocationRequestScenario](#locationrequestscenario). The default value is **UNSET**.|
| maxAccuracy | number | No| Yes|  Location accuracy requested by the application, in meters. This parameter is valid only when the precise location function is enabled (both the **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION** permissions are granted). It is invalid when the approximate location function is enabled (only the **ohos.permission.APPROXIMATELY\_LOCATION** permission is enabled).<br>When this parameter is effective, the system compares the [location](#location) information reported by the GNSS or network location service with the location information requested by the application. If the accuracy in the reported [location](#location) information is less than or equal to **maxAccuracy**, the system sends the reported location information to the application. Otherwise, the system discards the location information.<br>The value must be greater than or equal to **0**. The default value is **0**, indicating no limitation on the location accuracy.<br>If **scenario** is set to **NAVIGATION**, **TRAJECTORY_TRACKING**, or **CAR_HAILING** or **priority** is set to **ACCURACY**, you are advised to set **maxAccuracy** to a value greater than **10**.<br>If scenario is set to **DAILY_LIFE_SERVICE** or **NO_POWER** or **priority** is set to **LOW_POWER** or **FIRST_FIX**, you are advised to set **maxAccuracy** to a value greater than **100**.|
| timeoutMs | number | No| Yes| Timeout duration, in milliseconds. The minimum value is **1000**. The default value is **5000**. The specified value must be greater than or equal to **1000**.|

## ContinuousLocationRequest<sup>12+</sup>

Defines a continuous location request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| interval | number | No| No| Time interval at which location information is reported, in seconds. The specified value must be greater than or equal to **0**. The default value is **1**. If this parameter is set to **0**, there is no limitation on the location reporting interval.|
| locationScenario | [UserActivityScenario](#useractivityscenario12) &#124; [PowerConsumptionScenario](#powerconsumptionscenario12) | No| No| Location scenario. For details, see [UserActivityScenario](#useractivityscenario12) and [PowerConsumptionScenario](#powerconsumptionscenario12).|
| sportsType | [SportsType](#sportstype18) | No | Yes | Sports mode. For the value range, see [SportsType](#sportstype18). This parameter is valid only when **locationScenario** is set to **UserActivityScenario.SPORT**. The default value is **0**, indicating that this parameter does not take effect.<br/>**Since:** 26.0.0 |
| needPoi<sup>19+ | boolean | No| Yes| Whether to obtain the Point of Interest (POI) near the current location. The value **true** means to obtain the POI near the current location, and the value false means the opposite. If this parameter is not set, the default value **false** is used.<br>This parameter is valid only when the precise location function is enabled (both the **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION** permissions are granted). It is invalid when the approximate location function is enabled (only the **ohos.permission.APPROXIMATELY\_LOCATION** permission is enabled).<br>**Atomic service API**: This API can be used in atomic services since API version 19.|

## SingleLocationRequest<sup>12+</sup>

Defines a single location request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| locatingPriority | [LocatingPriority](#locatingpriority12) | No| No| Priority of the location request. For details, see [LocatingPriority](#locatingpriority12).|
| locatingTimeoutMs | number | No| No| Timeout duration, in milliseconds. The minimum value is **1000**. The specified value must be greater than or equal to **1000**.|
| needPoi<sup>19+ | boolean | No| Yes| Whether to obtain the Point of Interest (POI) near the current location. The value **true** means to obtain the POI near the current location, and the value false means the opposite. If this parameter is not set, the default value **false** is used.<br>This parameter is valid only when the precise location function is enabled (both the **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION** permissions are granted). It is invalid when the approximate location function is enabled (only the **ohos.permission.APPROXIMATELY\_LOCATION** permission is enabled).<br>**Atomic service API**: This API can be used in atomic services since API version 19.|

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
| command | string | No| No | Extended command, which is a string with a maximum of 100 characters.|

## Location

Location information.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number| No| No| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude. The value ranges from **-90** to **90**. Only the WGS84 coordinate system is supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| longitude | number| No| No| Longitude information. A positive value indicates east longitude, and a negative value indicates west longitude. The value ranges from **-180** to **180**. Only the WGS84 coordinate system is supported.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| altitude | number | No| No| Location altitude, in meters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| accuracy | number | No| No| Location accuracy, in meters.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| speed | number | No| No|Speed, in m/s.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| timeStamp | number | No| No| Location timestamp in the UTC format, in milliseconds.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
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
| poi<sup>19+</PoiInfo> | [PoiInfo](#poiinfo19) | No| Yes| Defines the POI near the current location.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|
| isFromMock | boolean | No | Yes | **true**: The location information comes from the mock location function.<br/>**false**: The location information does not come from the mock location function.<br/>**Since:** 26.0.0<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0. |

## GeofenceTransition<sup>12+</sup>

Defines a geofence transition event.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| geofenceId | number| No| No| Geofence ID.|
| transitionEvent | [GeofenceTransitionEvent](#geofencetransitionevent12) | No| No| Geofence transition event.|
| beaconFence<sup>20+</sup> | [BeaconFence](#beaconfence20) | No| Yes| Beacon fence configuration. This parameter is used only for beacon fences.<br>This parameter is supported since API version 20.|

## GnssGeofenceRequest<sup>12+</sup>

Defines a GNSS geofence request.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| geofence | [Geofence](#geofence) | No| No| Geofence information, including the coordinates and radius of the circle center.|
| monitorTransitionEvents | Array&lt;[GeofenceTransitionEvent](#geofencetransitionevent12)&gt; | No| No| List of geofence transition events. The array can contain no more than three elements.|
| notifications | Array&lt;[NotificationRequest](../apis-notification-kit/js-apis-notification.md#notificationrequest)&gt; | No| Yes| List of notifications for geofence transition events.<br>The sequence of **monitorTransitionEvents** must correspond to that of **notifications**. For example, if **monitorTransitionEvents[0]** is **[GeofenceTransitionEvent](#geofencetransitionevent12).GEOFENCE_TRANSITION_EVENT_ENTER**, **notifications[0]** must be set to the notification that needs to be displayed when a user enters the geofence. The default value is an empty array.|
| geofenceTransitionCallback | AsyncCallback&lt;[GeofenceTransition](#geofencetransition12)&gt; | No| No| Callback used to receive geofence transition events.|
| loiterTimeMs<sup>23+</sup> | number | No| Yes| Dwell duration, in milliseconds. You need to pay attention to the **GEOFENCE_TRANSITION_DWELL** event. If the time the device takes to dwell in the polygon geofence reaches the value of this parameter, an **GEOFENCE_TRANSITION_DWELL** event is reported. The detection period of the dwell status is 10,000 ms. For example, if this parameter is set to **15000**, the dwell status is reported when the device dwells in the polygon geofence for more than 20,000 ms. If this parameter is set to **5000**, the dwell status is reported when the device dwells in the polygon geofence for more than 10,000 ms.|
| fenceExtensionAbilityName<sup>23+</sup> | string | No| Yes| Name of **FenceExtensionAbility**. For details, see [@ohos.app.ability.FenceExtensionAbility (FenceExtensionAbility)](js-apis-app-ability-FenceExtensionAbility.md). To start **FenceExtensionAbility** in the background, you need to apply for the background location permission by referring to the [guide of applying for location permissions](../../device/location/location-permission-guidelines.md#how-to-develop). |

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
| TRAJECTORY_TRACKING | 0x302 | Trajectory tracking.<br>This option is applicable when your application needs to record user trajectories, for example, the track recording function of sports applications.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| CAR_HAILING | 0x303 | Ride hailing.<br>This option is applicable when your application needs to obtain the current location of a user who is hailing a taxi.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
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
| CONSTELLATION_CATEGORY_UNKNOWN   | 0 | Unknown category. This is the default value.|
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
| NAVIGATION  | 0x401 | Navigation.<br>This option is applicable when your application needs to obtain the real-time location of a mobile device outdoors, such as navigation for driving or walking.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| SPORT  | 0x402 | Sport scenario.<br>This option is applicable when your application needs to record user trajectories, for example, the track recording function of sports applications.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high.|
| TRANSPORT   | 0x403 | Travel scenario.<br>This option is applicable to user travel scenarios, such as taxi hailing and public transportation.<br>This option mainly uses the GNSS positioning technology and therefore the power consumption is relatively high. |
| DAILY_LIFE_SERVICE   | 0x404 | Daily life services.<br>This option is applicable when your application only needs the approximate location in scenarios such as when the user is browsing news, shopping online, and ordering food.<br>It mainly uses the network positioning technology and therefore the power consumption is relatively low. |

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
| LOCATING_FAILED_DEFAULT   | -1 |  Default value.|
| LOCATING_FAILED_LOCATION_PERMISSION_DENIED   | -2 | Failed to verify the **ohos.permission.APPROXIMATELY_LOCATION** or **ohos.permission.LOCATION** permission.|
| LOCATING_FAILED_BACKGROUND_PERMISSION_DENIED    | -3 | Failed to verify the location permission when the application is running in the background. <!--RP3-->For details about how to apply for the location permission, see [Applying for Location Permissions (ArkTS)](../../device/location/location-permission-guidelines.md#how-to-develop).<!--RP3End--> |
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
| deviceId | string | No| No| Address of the device discovered, for example, XX:XX:XX:XX:XX:XX.|
| rssi | number | No| No| RSSI of the device discovered, in dBm.|
| data | ArrayBuffer | No| Yes| Advertising packets sent by the device.|
| deviceName | string | No| No| Name of the device detected.|
| connectable | boolean | No| No| Whether the discovered device is connectable. The value **true** means the discovered device is connectable, and the value **false** means the opposite.|

## Poi<sup>19+</sup>

Defines the POI.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | string | No| No| POI ID.|
| confidence | number | No| No| POI confidence. A higher confidence indicates that the user is closer to the POI. The value range is [0, 1].|
| name | string | No| No| POI name.|
| latitude | number | No| No| Latitude of the POI. The value ranges from **-90** to **90**.|
| longitude | number | No| No| Latitude of the POI. The value ranges from **-180** to **180**.|
| administrativeArea | string | No| No| Level-1 administrative region of the country where the POI is located, which is generally a province or state.|
| subAdministrativeArea | string | No| No| Level-2 administrative region of the country where the POI is located, which is generally a prefectural-level city.|
| locality | string | No| No| City where the POI is located.|
| subLocality | string | No| No| Sub-city where the POI is located, which is generally a district or county.|
| address | string | No| No| Detailed address of the POI.|
| additionalInfo | string | No | Yes | POI additional information. This string is in JSON format.<br />**Since:** 26.0.0<br/>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br/>**Model restriction:** This API can only be used in the stage model. |

## PoiInfo<sup>19+</sup>

Defines the POI information structure.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| poiArray | Array&lt;[Poi](#poi19)&gt; | No| No| POI list.|
| timestamp | number | No| No| Timestamp (UTC) when the POI is obtained, in milliseconds.|

## SportsType<sup>18+</sup>

Enumerates sports types.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| RUNNING   | 1 |  Running.|
| WALKING    | 2 | Walking.|
| CYCLING     | 3 | Cycling.|
| SKIING     | 4 | Indicates skiing.<br/>**Since:** 26.0.0 |

## BeaconFenceInfoType<sup>20+</sup>

Defines the beacon fence information type. Currently, only the device manufacturer data can be filtered.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Value| Description|
| -------- | -------- | -------- |
| BEACON_MANUFACTURE_DATA   | 1 |  Beacon device manufacturer data.|

## BeaconManufactureData<sup>20+</sup>

Defines the beacon device manufacturer data.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| manufactureId | number | No| No| Manufacturer ID.|
| manufactureData | ArrayBuffer | No| No| Manufacturer data. An example value can be [0x02,0x15,0x00...0xFF,0x11,0x22,0x33,0x44,0x55].|
| manufactureDataMask | ArrayBuffer | No| No| Manufacturer data mask. This parameter is used together with **manufactureData** for filtering manufacturer data. **0xFF** indicates full match, and **0x00** indicates fuzzy match. An example value can be [0xFF,0xFF,0xFF...0xFF,0xFF,0xFF,0xFF,0xFF,0xFF].|

## BeaconFence<sup>20+</sup>

Defines the beacon fence configuration.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| identifier | string | No| No| Beacon fence ID. The value can be customized, for example, **123** or **beaconName**.|
| beaconFenceInfoType | [BeaconFenceInfoType](#beaconfenceinfotype20) | No| No| Beacon fence type.|
| manufactureData | [BeaconManufactureData](#beaconmanufacturedata20) | No| Yes| Beacon manufacturer data.|

## BeaconFenceRequest<sup>20+</sup>

Defines a beacon fence request. Either **transitionCallback** or **fenceExtensionAbilityName** must be specified. If neither of them is specified, the parameter is invalid.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| beacon | [BeaconFence](#beaconfence20) | No| No| Beacon fence configuration.|
| transitionCallback | Callback&lt;[GeofenceTransition](#geofencetransition12)&gt; | No| Yes| Callback of the beacon fence transition event. The default value is **undefined**. Only foreground callback is supported.|
| fenceExtensionAbilityName | string | No| Yes| [FenceExtensionAbility](js-apis-app-ability-FenceExtensionAbility.md) name. The default value is an empty string.|

## MatchingWlanInfo

Defines the matched WLAN information struct.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| index | number | No | No | Index of the matched WLAN in **wlanBssidArray**. |
| ssid | string | No | No | SSID of the matched WLAN. |

## DistrictRequestParams

Represents the request parameters for obtaining district information.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Location.Location.Geocoder

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| locale | string | No | Yes | Language of the location description. The value **zh** indicates Chinese, and **en** indicates English. The default value is obtained from **Language and region** in Settings. |
| timeoutMs | number | No | Yes | Timeout duration, in milliseconds. The default value is **5000**. |

## DistrictInfo

Represents the district information.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Location.Location.Geocoder

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| locale | string | No | Yes | Language of the location description. The value **zh** indicates Chinese, and **en** indicates English. |
| countryCode | string | No | Yes | Country code. |
| countryName | string | No | Yes | Country name. |
| administrativeArea | string | No | Yes | First-level administrative region below the country, typically a province or state. |
| subAdministrativeArea | string | No | Yes | Second-level administrative region below the country, typically a city. |
| locality | string | No | Yes | City information, typically a city. |
| subLocality | string | No | Yes | Sub-city information, typically a district or county. |

## BluetoothSearchRequestParams

Represents the Bluetooth scan request parameters.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceIdArray | Array&lt;string&gt; | No | No | List of Bluetooth device addresses used to filter scan results. The length of a single string cannot exceed 64, and the length of the array cannot exceed 1000. A Bluetooth device is returned through the callback only when its address matches an element in this array. If an empty array (length 0) is passed in, no Bluetooth scan result is returned. The format of each element in the array is **XX:XX:XX:XX:XX:XX**. |
| rssiThreshold | number | No | Yes | RSSI threshold. Only devices with an RSSI greater than this threshold are scanned. The value ranges from -128 to 127. |

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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
  let requestInfo: geoLocationManager.LocationRequest = {
    'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX,
    'scenario': geoLocationManager.LocationRequestScenario.UNSET,
    'timeInterval': 1,
    'distanceInterval': 0,
    'maxAccuracy': 0
  };
  let locationChange = (location: geoLocationManager.Location): void => {
    console.info('locationChange: data: ' + JSON.stringify(location));
  };
  try {
    geoLocationManager.on('locationChange', requestInfo, locationChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }

  // Method 2: Use ContinuousLocationRequest as the input parameter.
  let request: geoLocationManager.ContinuousLocationRequest = {
    'interval': 1,
    'locationScenario': geoLocationManager.UserActivityScenario.NAVIGATION
  };
  let locationCallback = (location: geoLocationManager.Location): void => {
    console.info('locationCallback: data: ' + JSON.stringify(location));
  };
  try {
    geoLocationManager.on('locationChange', request, locationCallback);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.onLocationChange

onLocationChange(request: LocationRequest | ContinuousLocationRequest, callback: Callback\<Location\>): void

Subscribes to location change events and initiates a location request. This API uses an asynchronous callback to return the result.

**Since**: 26.0.0

**Permission required:** ohos.permission.APPROXIMATELY_LOCATION

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | request | [LocationRequest](#locationrequest) &#124; [ContinuousLocationRequest](#continuouslocationrequest12) | Yes | Location request parameters. |
  | callback | Callback&lt;[Location](#location)&gt; | Yes | Callback used to return the location information. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. Failed to call ${geoLocationManager.onLocationChange} due to limited device capabilities. |
| 3301000 | The location service is unavailable. |
| 3301100 | The location switch is off. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  // Method 1: Use LocationRequest as the input parameter.
  let requestInfo: geoLocationManager.LocationRequest = {
    'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX,
    'scenario': geoLocationManager.LocationRequestScenario.UNSET,
    'timeInterval': 1,
    'distanceInterval': 0,
    'maxAccuracy': 0
  };
  let locationChange = (location: geoLocationManager.Location): void => {
    console.info('locationChange: data: ' + JSON.stringify(location));
  };
  try {
    geoLocationManager.onLocationChange(requestInfo, locationChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }

  // Method 2: Use ContinuousLocationRequest as the input parameter.
  let request: geoLocationManager.ContinuousLocationRequest = {
    'interval': 1,
    'locationScenario': geoLocationManager.UserActivityScenario.NAVIGATION
  };
  let locationCallback = (location: geoLocationManager.Location): void => {
    console.info('locationCallback: data: ' + JSON.stringify(location));
  };
  try {
    geoLocationManager.onLocationChange(request, locationCallback);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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
  | callback | Callback&lt;[Location](#location)&gt; | No | Callback for the location event. This callback must be the same as the one passed in the **on** API. Otherwise, the unsubscription fails without returning any error code. If this parameter is not specified, all subscriptions of the current type are canceled. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locationChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let requestInfo: geoLocationManager.LocationRequest = {
    'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX,
    'scenario': geoLocationManager.LocationRequestScenario.UNSET,
    'timeInterval': 1,
    'distanceInterval': 0,
    'maxAccuracy': 0
  };
  let locationChange = (location: geoLocationManager.Location): void => {
    console.info('locationChange: data: ' + JSON.stringify(location));
  };
  try {
    geoLocationManager.on('locationChange', requestInfo, locationChange);
    geoLocationManager.off('locationChange', locationChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.offLocationChange

offLocationChange(callback?: Callback\<Location\>): void

Unsubscribes from location change events and deletes the corresponding location request.

Error code 401 is thrown when the callback passed in is different from that passed in the **onLocationChange** API.

**Since**: 26.0.0

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | Callback&lt;[Location](#location)&gt; | No | Callback to unregister. This callback must be the same as the one passed in the **onLocationChange** API. Otherwise, error code 401 is thrown. If this parameter is not specified, all subscriptions are canceled. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. Failed to call ${geoLocationManager.offLocationChange} due to limited device capabilities. |
| 3301000 | The location service is unavailable. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let requestInfo: geoLocationManager.LocationRequest = {
    'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX,
    'scenario': geoLocationManager.LocationRequestScenario.UNSET,
    'timeInterval': 1,
    'distanceInterval': 0,
    'maxAccuracy': 0
  };
  let locationChange = (location: geoLocationManager.Location): void => {
    console.info('locationChange: data: ' + JSON.stringify(location));
  };
  try {
    geoLocationManager.onLocationChange(requestInfo, locationChange);
    geoLocationManager.offLocationChange(locationChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('locationError')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let requestInfo: geoLocationManager.LocationRequest = {
    'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX,
    'scenario': geoLocationManager.LocationRequestScenario.UNSET,
    'timeInterval': 1,
    'distanceInterval': 0,
    'maxAccuracy': 0
  };
  let locationChange = (location: geoLocationManager.Location): void => {
    console.info('locationChange: data: ' + JSON.stringify(location));
  };
  try {
    geoLocationManager.on('locationChange', requestInfo, locationChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }

  let locationErrorChange = (errcode: geoLocationManager.LocationError): void => {
    console.info('locationErrorChange: data: ' + JSON.stringify(errcode));
  };
  try {
    geoLocationManager.on('locationError', locationErrorChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locationError')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let locationErrorChange = (errcode: geoLocationManager.LocationError): void => {
    console.info('locationErrorChange: data: ' + JSON.stringify(errcode));
  };
  try {
    geoLocationManager.on('locationError', locationErrorChange);
    geoLocationManager.off('locationError', locationErrorChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('locationEnabledChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let locationEnabledChange = (state: boolean): void => {
      console.info('locationEnabledChange: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:" + err.message);
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
  | callback | Callback&lt;boolean&gt; | No| Callback to unregister. The value **true** indicates that the location switch is enabled and the value **false** indicates the opposite. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('locationEnabledChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let locationEnabledChange = (state: boolean): void => {
      console.info('locationEnabledChange: state: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
      geoLocationManager.off('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.on('cachedGnssLocationsChange')

on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;): void

Subscribes to cached GNSS location report events. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) is returned. This API uses an asynchronous callback to return the result. Before calling this API, you are advised to call [geoLocationManager.isCachedGnssServiceSupported](#geolocationmanageriscachedgnssservicesupported) to check whether the corresponding capability is supported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **cachedGnssLocationsChange** indicates reporting of cached GNSS locations.|
  | request |  [CachedGnssLocationsRequest](#cachedgnsslocationsrequest) | Yes| Request for reporting cached GNSS location.|
  | callback | Callback&lt;Array&lt;[Location](#location)&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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

  let cachedLocationsCb = (locations: Array<geoLocationManager.Location>): void => {
    console.info('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  let requestInfo: geoLocationManager.CachedGnssLocationsRequest = {
    'reportingPeriodSec': 10,
    'wakeUpCacheQueueFull': true
  };
  try {
    if (geoLocationManager.isCachedGnssServiceSupported()) {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.off('cachedGnssLocationsChange')

off(type: 'cachedGnssLocationsChange', callback?: Callback&lt;Array&lt;Location&gt;&gt;): void

Unsubscribes from cached GNSS location report events. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) is returned. Before calling this API, you are advised to call [geoLocationManager.isCachedGnssServiceSupported](#geolocationmanageriscachedgnssservicesupported) to check whether the corresponding capability is supported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **cachedGnssLocationsChange** indicates reporting of cached GNSS locations.|
  | callback | Callback&lt;Array&lt;[Location](#location)&gt;&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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

  let cachedLocationsCb = (locations: Array<geoLocationManager.Location>): void => {
    console.info('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  let requestInfo: geoLocationManager.CachedGnssLocationsRequest = {
    'reportingPeriodSec': 10,
    'wakeUpCacheQueueFull': true
  };
  try {
    if (geoLocationManager.isCachedGnssServiceSupported()) {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
      geoLocationManager.off('cachedGnssLocationsChange');
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.on('satelliteStatusChange')

on(type: 'satelliteStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;): void

Subscribes to GNSS satellite status information report events. This API uses an asynchronous callback to return the result. Before calling this API, you are advised to call [geoLocationManager.isGnssServiceSupported](#geolocationmanagerisgnssservicesupported) to check whether the corresponding capability is supported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **satelliteStatusChange** indicates a GNSS satellite status change.|
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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

  let gnssStatusCb = (satelliteStatusInfo: geoLocationManager.SatelliteStatusInfo): void => {
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
    for (let i = 0;i < totalNumber; i++) {
      // Satellite ID.
      let satelliteId: number = satelliteIds[i];
      // Carrier-to-noise density ratio of the satellite whose ID is ${satelliteId}.
      let carrierToNoiseDensity: number = carrierToNoiseDensitys[i];
      // Altitude angle information of the satellite whose ID is ${satelliteId}.
      let altitude: number = altitudes[i];
      // Azimuth of the satellite whose ID is ${satelliteId}.
      let azimuth: number = azimuths[i];
      // Carrier frequency of the satellite whose ID is ${satelliteId}.
      let carrierFrequency: number = carrierFrequencies[i];
      if (satelliteConstellations != undefined) {
        // Constellation of the satellite whose ID is ${satelliteId}.
        let satelliteConstellation: geoLocationManager.SatelliteConstellationCategory = satelliteConstellations[i];
      }
      if (satelliteAdditionalInfos != undefined) {
        // Additional information about the satellite whose ID is ${satelliteId}, for example, use of the satellite in the latest location resolution and the availability of ephemeris data, almanac data, and carrier frequency information.
        let satelliteAdditionalInfo: number = satelliteAdditionalInfos[i];
      }
    }
  }

  try {
    if (geoLocationManager.isGnssServiceSupported()) {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.off('satelliteStatusChange')

off(type: 'satelliteStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;): void

Unsubscribes from GNSS satellite status information report events. Before calling this API, you are advised to call [geoLocationManager.isGnssServiceSupported](#geolocationmanagerisgnssservicesupported) to check whether the corresponding capability is supported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **satelliteStatusChange** indicates a GNSS satellite status change.|
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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

  let gnssStatusCb = (satelliteStatusInfo: geoLocationManager.SatelliteStatusInfo): void => {
    console.info('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  try {
    if (geoLocationManager.isGnssServiceSupported()) {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
      geoLocationManager.off('satelliteStatusChange', gnssStatusCb);
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.on('nmeaMessage')

on(type: 'nmeaMessage', callback: Callback&lt;string&gt;): void

Subscribes to GNSS NMEA information report events. This API uses an asynchronous callback to return the result. Before calling this API, you are advised to call [geoLocationManager.isGnssServiceSupported](#geolocationmanagerisgnssservicesupported) to check whether the corresponding capability is supported.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **nmeaMessage** indicates a GNSS NMEA message change.|
  | callback | Callback&lt;string&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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

  let nmeaCb = (str: string): void => {
    console.info('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
    if (geoLocationManager.isGnssServiceSupported()) {
      geoLocationManager.on('nmeaMessage', nmeaCb);
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.off('nmeaMessage')

off(type: 'nmeaMessage', callback?: Callback&lt;string&gt;): void

Unsubscribes from GNSS NMEA information report events. Before calling this API, you are advised to call [geoLocationManager.isGnssServiceSupported](#geolocationmanagerisgnssservicesupported) to check whether the corresponding capability is supported.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **nmeaMessage** indicates a GNSS NMEA message change.|
  | callback | Callback&lt;string&gt; | No| Callback to unregister. The callback must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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

  let nmeaCb = (str: string): void => {
    console.info('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
    if (geoLocationManager.isGnssServiceSupported()) {
      geoLocationManager.on('nmeaMessage', nmeaCb);
      geoLocationManager.off('nmeaMessage', nmeaCb);
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.on('gnssFenceStatusChange')

on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void

Adds a geofence and subscribes to geofence events. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) is returned. Before calling this API, you are advised to call [geoLocationManager.isGnssFenceServiceSupported](#geolocationmanagerisgnssfenceservicesupported) to check whether the corresponding capability is supported.

A single app can add a maximum of 100 geofences. If this limit is exceeded, the geofence with the shortest lifetime among the remaining geofences is removed.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **gnssFenceStatusChange** indicates a geofence status change.|
  | request |  [GeofenceRequest](#geofencerequest) | Yes| Geofencing request.|
  | want | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes| **WantAgent** used to receive geofence (entrance or exit) events.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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


  let wantAgentInfo: wantAgent.WantAgentInfo = {
    wants: [
      {
        bundleName: "com.example.myapplication",
        abilityName: "EntryAbility",
        action: "action1"
      }
    ],
    actionType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
  };

  wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let requestInfo: geoLocationManager.GeofenceRequest = {
      'scenario': 0x301,
      "geofence": { "latitude": 31.12, "longitude": 121.11, "radius": 100, "expiration": 10000 }
    };
    try {
      if (geoLocationManager.isGnssFenceServiceSupported()) {
        geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
      }
    } catch (err) {
      console.error("errCode:" + err.code + ", message:" + err.message);
    }
  });
  ```

## geoLocationManager.off('gnssFenceStatusChange')

off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void

Removes a geofence and unsubscribes from its events. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) is returned. Before calling this API, you are advised to call [geoLocationManager.isGnssFenceServiceSupported](#geolocationmanagerisgnssfenceservicesupported) to check whether the corresponding capability is supported.

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **gnssFenceStatusChange** indicates a geofence status change.|
  | request | [GeofenceRequest](#geofencerequest) | Yes| Geofencing request.|
  | want | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes| **WantAgent** used to receive geofence (entrance or exit) events.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('gnssFenceStatusChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |
|3301600 | Failed to operate the geofence.                                     |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { wantAgent } from '@kit.AbilityKit';


  let wantAgentInfo: wantAgent.WantAgentInfo = {
    wants: [
      {
        bundleName: "com.example.myapplication",
        abilityName: "EntryAbility",
        action: "action1",
      }
    ],
    actionType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
  };

  wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    let requestInfo: geoLocationManager.GeofenceRequest = {
      'scenario': 0x301,
      "geofence": { "latitude": 31.12, "longitude": 121.11, "radius": 100, "expiration": 10000 }
    };
    try {
      if (geoLocationManager.isGnssFenceServiceSupported()) {
        geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
        geoLocationManager.off('gnssFenceStatusChange', requestInfo, wantAgentObj);
      }
    } catch (err) {
      console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.on('countryCodeChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301500 | Failed to query the area information.                                       |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let callback = (code: geoLocationManager.CountryCode): void => {
    console.info('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
    geoLocationManager.on('countryCodeChange', callback);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('countryCodeChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301500 | Failed to query the area information.                                       |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let callback = (code: geoLocationManager.CountryCode): void => {
    console.info('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
    geoLocationManager.on('countryCodeChange', callback);
    geoLocationManager.off('countryCodeChange', callback);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
  let requestInfo: geoLocationManager.CurrentLocationRequest = {
    'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX,
    'scenario': geoLocationManager.LocationRequestScenario.UNSET,
    'maxAccuracy': 0
  };
  let locationChange = (err: BusinessError, location: geoLocationManager.Location): void => {
    if (err) {
      console.error('locationChange: err=' + JSON.stringify(err));
    }
    if (location) {
      console.info('locationChange: location=' + JSON.stringify(location));
    }
  };

  try {
    geoLocationManager.getCurrentLocation(requestInfo, locationChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }

  // Method 2: Use SingleLocationRequest as the input parameter.
  let request: geoLocationManager.SingleLocationRequest = {
    'locatingTimeoutMs': 10000,
    'locatingPriority': geoLocationManager.LocatingPriority.PRIORITY_ACCURACY
  };
  let locationCallback = (err: BusinessError, location: geoLocationManager.Location): void => {
    if (err) {
      console.error('locationChange: err=' + JSON.stringify(err));
    }
    if (location) {
      console.info('locationChange: location=' + JSON.stringify(location));
    }
  };

  try {
    geoLocationManager.getCurrentLocation(request, locationCallback);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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

  let locationChange = (err: BusinessError, location: geoLocationManager.Location) => {
    if (err) {
      console.error('locationChange: err=' + JSON.stringify(err));
    }
    if (location) {
      console.info('locationChange: location=' + JSON.stringify(location));
    }
  };

  try {
    geoLocationManager.getCurrentLocation(locationChange);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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
  | request | [CurrentLocationRequest](#currentlocationrequest) &#124; [SingleLocationRequest](#singlelocationrequest12) | No| Location request.<br>**SingleLocationRequest** is newly added in API version 12. If this parameter is not set, **CurrentLocationRequest** is used as the default value.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
  let requestInfo: geoLocationManager.CurrentLocationRequest = {
    'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX,
    'scenario': geoLocationManager.LocationRequestScenario.UNSET,
    'maxAccuracy': 0
  };
  try {
    geoLocationManager.getCurrentLocation(requestInfo).then((result) => {
      console.info('current location: ' + JSON.stringify(result));
    })
      .catch((error: BusinessError) => {
        console.error('promise, getCurrentLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }

  // Method 2: Use SingleLocationRequest as the input parameter.
  let request: geoLocationManager.SingleLocationRequest = {
    'locatingTimeoutMs': 10000,
    'locatingPriority': geoLocationManager.LocatingPriority.PRIORITY_ACCURACY
  };
  try {
    geoLocationManager.getCurrentLocation(request).then((result) => {
      console.info('current location: ' + JSON.stringify(result));
    })
      .catch((error: BusinessError) => {
        console.error('promise, getCurrentLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getAddressesFromLocation} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301300 | Reverse geocoding query failed.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let reverseGeocodeRequest: geoLocationManager.ReverseGeoCodeRequest = {
    "latitude": 31.12,
    "longitude": 121.11,
    "maxItems": 1
  };
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
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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

  let reverseGeocodeRequest: geoLocationManager.ReverseGeoCodeRequest = {
    "latitude": 31.12,
    "longitude": 121.11,
    "maxItems": 1
  };
  try {
    geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {
      console.info('getAddressesFromLocation: ' + JSON.stringify(data));
    })
      .catch((error: BusinessError) => {
        console.error('promise, getAddressesFromLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getAddressesFromLocationName} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |
|3301400 | Geocoding query failed.   |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let geocodeRequest: geoLocationManager.GeoCodeRequest = { "description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
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
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;

Converts geographic descriptions into coordinates through geocoding. This API uses a promise to return the result. 

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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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

  let geocodeRequest: geoLocationManager.GeoCodeRequest = { "description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  try {
    geoLocationManager.getAddressesFromLocationName(geocodeRequest).then((result) => {
      console.info('getAddressesFromLocationName: ' + JSON.stringify(result));
    })
      .catch((error: BusinessError) => {
        console.error('promise, getAddressesFromLocationName: error=' + JSON.stringify(error));
      });
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the number of cached GNSS locations. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) is returned. This API uses an asynchronous callback to return the result. Before calling this API, you are advised to call [geoLocationManager.isCachedGnssServiceSupported](#geolocationmanageriscachedgnssservicesupported) to check whether the corresponding capability is supported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
    if (geoLocationManager.isCachedGnssServiceSupported()) {
      geoLocationManager.getCachedGnssLocationsSize((err, size) => {
        if (err) {
          console.error('getCachedGnssLocationsSize: err=' + JSON.stringify(err));
        }
        if (size) {
          console.info('getCachedGnssLocationsSize: size=' + JSON.stringify(size));
        }
      });
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(): Promise&lt;number&gt;

Obtains the number of cached GNSS locations. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) is returned. This API uses a promise to return the result. Before calling this API, you are advised to call [geoLocationManager.isCachedGnssServiceSupported](#geolocationmanageriscachedgnssservicesupported) to check whether the corresponding capability is supported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
    if (geoLocationManager.isCachedGnssServiceSupported()) {
      geoLocationManager.getCachedGnssLocationsSize().then((result) => {
        console.info('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));
      })
        .catch((error: BusinessError) => {
          console.error('promise, getCachedGnssLocationsSize: error=' + JSON.stringify(error));
        });
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(callback: AsyncCallback&lt;void&gt;): void

Reads and clears all cached GNSS locations. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) is returned. This API uses an asynchronous callback to return the result. Before calling this API, you are advised to call [geoLocationManager.isCachedGnssServiceSupported](#geolocationmanageriscachedgnssservicesupported) to check whether the corresponding capability is supported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
    if (geoLocationManager.isCachedGnssServiceSupported()) {
      geoLocationManager.flushCachedGnssLocations((err) => {
        if (err) {
          console.error('flushCachedGnssLocations: err=' + JSON.stringify(err));
        }
      });
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(): Promise&lt;void&gt;

Reads and clears all cached GNSS locations. This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) is returned. This API uses a promise to return the result. Before calling this API, you are advised to call [geoLocationManager.isCachedGnssServiceSupported](#geolocationmanageriscachedgnssservicesupported) to check whether the corresponding capability is supported.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
    if (geoLocationManager.isCachedGnssServiceSupported()) {
      geoLocationManager.flushCachedGnssLocations().then(() => {
        console.info('promise, flushCachedGnssLocations success');
      })
        .catch((error: BusinessError) => {
          console.error('promise, flushCachedGnssLocations: error=' + JSON.stringify(error));
        });
    }
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.sendCommand} due to limited device capabilities.          |
|3301000 | The location service is unavailable.  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let requestInfo: geoLocationManager.LocationCommand = { 'scenario': 0x301, 'command': "command_1" };
  try {
    geoLocationManager.sendCommand(requestInfo, (err) => {
      if (err) {
        console.error('sendCommand: err=' + JSON.stringify(err));
      }
    });
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.sendCommand} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let requestInfo: geoLocationManager.LocationCommand = { 'scenario': 0x301, 'command': "command_1" };
  try {
    geoLocationManager.sendCommand(requestInfo).then(() => {
      console.info('promise, sendCommand success');
    })
      .catch((error: BusinessError) => {
        console.error('promise, sendCommand: error=' + JSON.stringify(error));
      });
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
      .catch((error: BusinessError) => {
        console.error('promise, getCountryCode: error=' + JSON.stringify(error));
      });
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.addGnssGeofence<sup>12+</sup>

addGnssGeofence(fenceRequest: GnssGeofenceRequest): Promise&lt;number&gt;

Adds a GNSS geofence and subscribes to geofence events. This API uses a promise to return the result. Before calling this API, you are advised to call [geoLocationManager.isGnssFenceServiceSupported](#geolocationmanagerisgnssfenceservicesupported) to check whether the corresponding capability is supported.

The application can pass a callback to [GnssGeofenceRequest](#gnssgeofencerequest12) to receive geofence transition events. It can also pass [NotificationRequest](../apis-notification-kit/js-apis-notification.md#notificationrequest) so that a notification is displayed when a geofence transition event occurs.

This API is supported only by certain GNSS chip models. If the required chip model is not available, error code 801 (Capability not supported) will be reported.

A single app can add a maximum of 100 geofences. If this limit is exceeded, the geofence with the shortest lifetime among the remaining geofences is removed.

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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
        text: 'Geofence Exit',
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
    // Specify the duration during which the device dwells in the geofence. This parameter is optional.
    loiterTimeMs: 10000,
    // Specify the name of FenceExtensionAbility to be started for the geofence callback. This parameter is optional.
    fenceExtensionAbilityName: "FenceExtensionAbility",
    // Specify the callback used to receive geofence transition events.
    geofenceTransitionCallback: (err: BusinessError, transition: geoLocationManager.GeofenceTransition) => {
      if (err) {
        console.error('geofenceTransitionCallback: err=' + JSON.stringify(err));
      }
      if (transition) {
        console.info("GeofenceTransition: %{public}s", JSON.stringify(transition));
      }
    }
  }
  try {
    if (geoLocationManager.isGnssFenceServiceSupported()) {
      // Add a geofence.
      geoLocationManager.addGnssGeofence(gnssGeofenceRequest).then((id) => {
        // Return the geofence ID after the geofence is added successfully.
        console.info("addGnssGeofence success, fence id: " + id);
        let fenceId = id;
      }).catch((err: BusinessError) => {
        console.error("addGnssGeofence failed, promise errCode:" + (err as BusinessError).code +
        ",errMessage:" + (err as BusinessError).message);
      });
    }
  } catch (error) {
    console.error("addGnssGeofence failed, err:" + JSON.stringify(error));
  }
  ```

## geoLocationManager.removeGnssGeofence<sup>12+</sup>

removeGnssGeofence(geofenceId: number): Promise&lt;void&gt;

Removes a GNSS geofence and unsubscribes from geofence events. This API uses a promise to return the result.

The GNSS geofence feature depends on the GNSS positioning chip (supported only by certain models). If the required chip model is not available, error code 801 (Capability not supported) is returned. Before calling this API, you are advised to call [geoLocationManager.isGnssFenceServiceSupported](#geolocationmanagerisgnssfenceservicesupported) to check whether the corresponding capability is supported.

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | geofenceId | number | Yes| GNSS geofence ID.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
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
    if (geoLocationManager.isGnssFenceServiceSupported()) {
      geoLocationManager.removeGnssGeofence(fenceId).then(() => {
        console.info("removeGnssGeofence success fenceId:" + fenceId);
      }).catch((error: BusinessError) => {
        console.error("removeGnssGeofence: error=" + JSON.stringify(error));
      });
    }
  } catch (error) {
    console.error("removeGnssGeofence: error=" + JSON.stringify(error));
  }
  ```

## geoLocationManager.getGeofenceSupportedCoordTypes<sup>12+</sup>

getGeofenceSupportedCoordTypes(): Array&lt;CoordinateSystemType&gt;

Obtains the list of coordinate systems supported by the geofence feature. Before calling this API, you are advised to call [geoLocationManager.isGnssFenceServiceSupported](#geolocationmanagerisgnssfenceservicesupported) to check whether the corresponding capability is supported.

**System capability**: SystemCapability.Location.Location.Geofence

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Array&lt;[CoordinateSystemType](#coordinatesystemtype12)&gt; | List of supported coordinate systems.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|801 | Capability not supported. Failed to call ${geoLocationManager.getGeofenceSupportedCoordTypes} due to limited device capabilities.          |
|3301000 | The location service is unavailable. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  try {
    if (geoLocationManager.isGnssFenceServiceSupported()) {
      let supportedCoordTypes: Array<geoLocationManager.CoordinateSystemType> = geoLocationManager.getGeofenceSupportedCoordTypes();
      console.info("getGeofenceSupportedCoordTypes return:" + JSON.stringify(supportedCoordTypes));
    }
  } catch (error) {
    console.error("getGeofenceSupportedCoordTypes: error=" + JSON.stringify(error));
  }
  ```

## geoLocationManager.getCurrentWifiBssidForLocating<sup>14+</sup>

getCurrentWifiBssidForLocating(): string

Obtains the Basic Service Set Identifier (BSSID) of the connected Wi-Fi access point (AP). If the device is not connected to a Wi-Fi network, error code **3301900** will be returned. You are advised to use the **try-catch** structure to capture exceptions according to the sample code.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Wi-Fi Bssid |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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
  } catch (error) {
    console.error("getCurrentWifiBssidForLocating: errCode" + error.code + ", errMessage" + error.message);
  }
  ```

## geoLocationManager.on('bluetoothScanResultChange')<sup>16+</sup>

on(type: 'bluetoothScanResultChange', callback: Callback&lt;BluetoothScanResult&gt;): void

Enables listening for Bluetooth scan information reporting events. This API uses an asynchronous callback to return the result.

<!--RP2--><!--RP2End-->

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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

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


  let callback = (result: geoLocationManager.BluetoothScanResult): void => {
    console.info('bluetoothScanResultChange: ' + JSON.stringify(result));
  };
  try {
    geoLocationManager.on('bluetoothScanResultChange', callback);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
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

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.off('bluetoothScanResultChange')} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let callback = (result: geoLocationManager.BluetoothScanResult): void => {
    console.info('bluetoothScanResultChange: ' + JSON.stringify(result));
  };
  try {
    geoLocationManager.on('bluetoothScanResultChange', callback);
    geoLocationManager.off('bluetoothScanResultChange', callback);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.isPoiServiceSupported<sup>20+</sup>

isPoiServiceSupported(): boolean

Queries whether the system supports the POI service.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | **true**: The POI service is supported.<br>**false**: The POI service is not supported.|

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  let poiServiceState = geoLocationManager.isPoiServiceSupported();
  console.info("poiServiceState:" + poiServiceState);
  ```

## geoLocationManager.getPoiInfo<sup>20+</sup>

getPoiInfo(): Promise&lt;PoiInfo&gt;

Obtains the POI near the current location. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[PoiInfo](#poiinfo19)&gt;| POI near the current location.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getPoiInfo} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.                                                 |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  try {
    if (geoLocationManager.isPoiServiceSupported()) {
      geoLocationManager.getPoiInfo().then((poiInfo) => {
        if (poiInfo !== undefined) {
          console.info("get PoiInfo:" + JSON.stringify(poiInfo));
        }
      })
    }
  } catch (error) {
    console.error("getPoiInfo errCode:" + error.code + ", errMessage:" + error.message);
  }
  ```

## geoLocationManager.getDistanceBetweenLocations<sup>20+</sup>

getDistanceBetweenLocations(location1: Location, location2: Location): number

Obtains the linear distance between two locations.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | location1 | [Location](#location) | Yes| Location 1.|
  | location2 | [Location](#location) | Yes| Location 2.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Linear distance between two locations, in meters.|

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  try {
    let location1: geoLocationManager.Location = {
      "latitude": 30.12,
      "longitude": 120.11,
      "altitude": 0,
      "accuracy": 0,
      "speed": 0,
      "timeStamp": 0,
      "direction": 0,
      "timeSinceBoot": 0,
      "additionSize": 0
    }
    let location2: geoLocationManager.Location = {
      "latitude": 30.12,
      "longitude": 120.11,
      "altitude": 0,
      "accuracy": 0,
      "speed": 0,
      "timeStamp": 0,
      "direction": 0,
      "timeSinceBoot": 0,
      "additionSize": 0
    }
    let distance = geoLocationManager.getDistanceBetweenLocations(location1, location2);
    console.info("distance:" + distance);
  } catch (error) {
    console.error("getDistanceBetweenLocations: errCode" + error.code + ", errMessage" + error.message);
  }
  ```

## geoLocationManager.addBeaconFence<sup>20+</sup>

addBeaconFence(fenceRequest: BeaconFenceRequest): Promise&lt;number&gt;

Adds a beacon fence and subscribes to beacon fence events. This API uses a promise to return the result.

A beacon fence refers to a virtual fence created through the cooperation of a Bluetooth beacon and a mobile phone application. When a user approaches or leaves a specific beacon, the mobile phone application receives a notification.

The application can pass a callback in [BeaconFenceRequest](#beaconfencerequest20) to receive beacon fence events. Alternatively, the application can pass a [FenceExtensionAbility](js-apis-app-ability-FenceExtensionAbility.md) name so that the system sends a notification when detecting a beacon fence event.

A single app can add a maximum of 10 beacon fences. If this limit is exceeded, adding a beacon fence fails and error code 3501601 is thrown.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | fenceRequest | [BeaconFenceRequest](#beaconfencerequest20) | Yes| Beacon fence request.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the beacon fence ID.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.addBeaconFence} due to limited device capabilities.          |
|3501100 | Failed to add a beacon fence because the location switch is off.                                           |
|3501101 | Failed to add a beacon fence because the bluetooth switch is off.                                                 |
|3501601 | The number of beacon fences exceeds the maximum. |
|3501603 | Duplicate beacon fence information. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    // The iBeacon protocol is used as an example. The format is as follows:
    // 01 byte    type = 0x02
    // 01 byte    len = 0x15 = 21
    // 16 byte    UUID
    // 02 byte    major
    // 02 byte    minor
    // 01 byte    tx power
    let manufactureDataBuffer: Uint8Array = new Uint8Array([0X02, 0X15, 0X00, 0X11, 0X22, 0X33, 0X44, 0X55,
      0X66, 0X77, 0X88, 0X99, 0XAA, 0XBB, 0XCC, 0XDD, 0XEE, 0XFF, 0X11, 0X22, 0X33, 0X44, 0X55]);
    let manufactureDataMaskBuffer: Uint8Array = new Uint8Array([0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
      0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF]);

    let manufactureData: geoLocationManager.BeaconManufactureData = {
      manufactureId: 0X004C,
      manufactureData: manufactureDataBuffer.buffer,
      manufactureDataMask: manufactureDataMaskBuffer.buffer
    };

    let beacon: geoLocationManager.BeaconFence = {
      identifier: "11",
      beaconFenceInfoType: geoLocationManager.BeaconFenceInfoType.BEACON_MANUFACTURE_DATA,
      manufactureData: manufactureData
    };

    let fenceRequest: geoLocationManager.BeaconFenceRequest = {
      beacon: beacon,
      transitionCallback: (transition: geoLocationManager.GeofenceTransition) => {
        if (transition) {
          console.info("GeofenceTransition: err" + JSON.stringify(transition));
        }
      },
      fenceExtensionAbilityName: "MyFenceExtensionAbility",
    };
    geoLocationManager.addBeaconFence(fenceRequest).then((id) => {
      console.info("addBeaconFence success, fence id:" + id);
    }).catch((err: BusinessError) => {
      console.error('promise, addBeaconFence: error=' + JSON.stringify(err));
    });
  } catch (error) {
    console.error("addBeaconFence: errCode" + error.code + ", errMessage" + error.message);
  }
  ```

## geoLocationManager.removeBeaconFence<sup>20+</sup>

removeBeaconFence(beaconFence?: BeaconFence): Promise&lt;void&gt;

Removes a beacon fence and unsubscribes from beacon fence events. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | beaconFence | [BeaconFence](#beaconfence20) | No| If **beaconFence** is passed, the specified beacon fence is deleted. If **beaconFence** is not passed, all beacon fences of the application are deleted.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.removeBeaconFence} due to limited device capabilities.          |
|3501602 | Failed to delete the fence due to incorrect beacon fence information. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let manufactureDataBuffer: Uint8Array = new Uint8Array([0X02, 0X15, 0X00, 0X11, 0X22, 0X33, 0X44, 0X55,
      0X66, 0X77, 0X88, 0X99, 0XAA, 0XBB, 0XCC, 0XDD, 0XEE, 0XFF, 0X11, 0X22, 0X33, 0X44, 0X55]);
    let manufactureDataMaskBuffer: Uint8Array = new Uint8Array([0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF,
      0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF, 0XFF]);

    let manufactureData: geoLocationManager.BeaconManufactureData = {
      manufactureId: 0X004C,
      manufactureData: manufactureDataBuffer.buffer,
      manufactureDataMask: manufactureDataMaskBuffer.buffer
    };

    let beacon: geoLocationManager.BeaconFence = {
      identifier: "11",
      beaconFenceInfoType: geoLocationManager.BeaconFenceInfoType.BEACON_MANUFACTURE_DATA,
      manufactureData: manufactureData
    };
    geoLocationManager.removeBeaconFence(beacon).then(() => {
      console.info("promise, removeBeaconFence success");
    })
      .catch((error: BusinessError) => {
        console.error("promise, removeBeaconFence: errCode" + error.code + ", errMessage" + error.message);
      });
  } catch (error) {
    console.error("removeBeaconFence: errCode" + error.code + ", errMessage" + error.message);
  }
  ```

## geoLocationManager.isBeaconFenceSupported<sup>20+</sup>

isBeaconFenceSupported(): boolean;

Checks whether the current device supports beacon fences.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Location.Location.Geofence

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | **true**: Beacon geofences are supported.<br>**false**: Beacon geofences are not supported.|

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  try {
    let isBeaconFenceSupported = geoLocationManager.isBeaconFenceSupported();
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.isWlanBssidMatched<sup>21+</sup>

isWlanBssidMatched(wlanBssidArray: Array&lt;string&gt;, rssiThreshold: number, needStartScan: boolean): Promise&lt;boolean&gt;

Checks whether a specified BSSID exists in the latest WLAN scan result. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 21.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | wlanBssidArray | Array&lt;string&gt; | Yes| List of BSSIDs to be matched. The length of a single string cannot exceed 64 characters, and the length of an array cannot exceed 1000 characters.|
  | rssiThreshold | number | Yes| RSSI threshold, in dBm. Only the BSSIDs whose RSSI is greater than the threshold are matched. The value range is [–10000, 10000].|
  | needStartScan | boolean | Yes| Whether to initiate a WLAN scan. If a WLAN scan needs to be initiated, set this parameter to **true**. If a WLAN scan does not need to be initiated and the latest WLAN scan result is used for matching, set this parameter to **false**.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the result. If any BSSID in **wlanBssidArray** exists in the scan result and the RSSI value is greater than **rssiThreshold**, **true** is returned. Otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.isWlanBssidMatched} due to limited device capabilities.          |
|3301100 | The location switch is off.                                           |
|3301800 | Failed to start WiFi scanning.                                        |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  try {
    let wlanBssidArray: Array<string> = ["02:1b:32:23:ea:91", "02:1b:32:23:ea:93"];
    let rssiThreshold: number = -70;
    let needStartScan: boolean = true;
    geoLocationManager.isWlanBssidMatched(wlanBssidArray, rssiThreshold, needStartScan).then((res) => {
      console.info("Wlan Bssid Matched Result:" + res);
    })
  } catch (error) {
    console.error("isWlanBssidMatched: errCode" + error.code + ", errMessage" + error.message);
  }
  ```

## geoLocationManager.isGnssServiceSupported

isGnssServiceSupported(): boolean

Checks whether the GNSS feature is supported.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

  | Type | Description |
  | -------- | -------- |
  | boolean | **true**: the GNSS feature is supported.<br/>**false**: the GNSS feature is not supported. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
|3301000 | The location service is unavailable. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let gnssServiceSupported = geoLocationManager.isGnssServiceSupported();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.isGnssFenceServiceSupported

isGnssFenceServiceSupported(): boolean

Checks whether the geofence feature is supported.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

  | Type | Description |
  | -------- | -------- |
  | boolean | **true**: The geofence feature is supported.<br/>**false**: The geofence feature is not supported. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
|3301000 | The location service is unavailable. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let gnssFenceServiceSupported = geoLocationManager.isGnssFenceServiceSupported();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.isCachedGnssServiceSupported

isCachedGnssServiceSupported(): boolean

Checks whether the GNSS batching feature is supported.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

  | Type | Description |
  | -------- | -------- |
  | boolean | **true**: The GNSS batching feature is supported.<br/>**false**: The GNSS batching feature is not supported. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
|3301000 | The location service is unavailable. |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  try {
      let cachedGnssServiceSupported = geoLocationManager.isCachedGnssServiceSupported();
  } catch (err) {
      console.error("errCode:" + err.code + ", message:"  + err.message);
  }
  ```

## geoLocationManager.getActiveGeoFences<sup>23+</sup>

getActiveGeoFences(): Promise&lt;Map&lt;number, Geofence&gt;&gt;

Queries the current valid geofence information. This API uses a promise to return the result. Before calling this API, you are advised to call [geoLocationManager.isGnssFenceServiceSupported](#geolocationmanagerisgnssfenceservicesupported) to check whether the corresponding capability is supported.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;Map&lt;number, [Geofence](#geofence)&gt;&gt; | Promise that returns the valid geofence information. The key in the Map is **fenceId**, and the value is the specific information about the corresponding geofence.|

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getActiveGeoFences} due to limited device capabilities.          |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  try {
    if (geoLocationManager.isGnssFenceServiceSupported()) {
      geoLocationManager.getActiveGeoFences().then((res) => {
        if (res) {
          console.info("fence num:" + res.size);
          for (const item of res) {
            console.info("data=" + JSON.stringify(item));
          }
        }
      })
        .catch((error: BusinessError) => {
          console.error('promise, getActiveGeoFences: error=' + JSON.stringify(error));
        });
    }
  } catch (error) {
    console.error("getActiveGeoFences: errCode" + error.code + ", errMessage" + error.message);
  }
  ```

## geoLocationManager.findMatchingWlan

findMatchingWlan(wlanBssidArray: Array&lt;string&gt;, rssiThreshold: number, needStartScan: boolean):Promise&lt;Array&lt;MatchingWlanInfo&gt;&gt;

Matches the WLAN scan results against the input WLAN BSSID list. If a match is found, the corresponding WLAN device information is returned. If no match is found, an empty array (length 0) is returned. This API uses a promise to return the result.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Permission required:** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | wlanBssidArray | Array&lt;string&gt; | Yes | List of BSSIDs to match. The length of a single string cannot exceed 64, and the length of the array cannot exceed 1000. |
  | rssiThreshold | number | Yes | RSSI threshold. Only BSSIDs with an RSSI greater than this threshold are matched. The value ranges from -10000 to 10000 (in dBm). |
  | needStartScan | boolean | Yes | Whether to initiate a WLAN scan. Set to **true** to initiate a WLAN scan. Set to **false** to use the most recent WLAN scan result for matching. |

**Return value**

  | Type | Description |
  | -------- | -------- |
  | Promise<Array<[MatchingWlanInfo](#matchingwlaninfo)>> | Promise used to return the result. If a match is found, the corresponding WLAN device information is returned. If no match is found, an empty array (length 0) is returned. Only the three devices with the strongest RSSI are returned. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.findMatchingWlan} due to limited device capabilities.          |
|3301100 | The location switch is off.                                           |
|3301800 | Failed to start WLAN scanning.                                        |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';

  try {
    let wlanBssidArray: Array<string> = ["02:1b:32:23:ea:91", "02:1b:32:23:ea:93"];
    let rssiThreshold: number = -70;
    let needStartScan: boolean = true;
    geoLocationManager.findMatchingWlan(wlanBssidArray, rssiThreshold, needStartScan).then((res) => {
      console.info("WLAN BSSID Matched Result: " + JSON.stringify(res));
    })
  } catch (error) {
    console.error("findMatchingWlan: errCode " + error.code + ", errMessage " + error.message);
  }
  ```

## geoLocationManager.getCurrentDistrict

getCurrentDistrict(params?: DistrictRequestParams): Promise&lt;DistrictInfo&gt;

Obtains the district information of the current device location. This API uses a promise to return the result.

**Since**: 26.0.0

**Permission required:** ohos.permission.APPROXIMATELY_LOCATION

**System capability:** SystemCapability.Location.Location.Geocoder

**Model restriction**: This API can be used only in the stage model.

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | request | [DistrictRequestParams](#districtrequestparams) | No | District information request parameters. |

**Return value**

  | Type | Description |
  | -------- | -------- |
  | Promise&lt;[DistrictInfo](#districtinfo)&gt; | Promise used to return the district information of the current device location. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getCurrentDistrict} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.  |
|3301500 | Failed to query the area information because the reverse geocoding server returns an error.  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  // Parameter configuration 1: Specify the language, country, and timeout duration.
  try {
    let params: geoLocationManager.DistrictRequestParams = {
      locale: "en",
      timeoutMs: 5000
    }
    geoLocationManager.getCurrentDistrict(params).then((res) => {
      if (res) {
        console.info("getCurrentDistrict result:" + res);
      }
    })
    .catch((error: BusinessError) => {
      console.error('promise, getCurrentDistrict: error=' + JSON.stringify(error));
    });
  } catch (error) {
    console.error("getCurrentDistrict: errCode" + error.code + ", errMessage" + error.message);
  }
  // Parameter configuration 2: Use default values.
  try {
    geoLocationManager.getCurrentDistrict().then((res) => {
      if (res) {
        console.info("getCurrentDistrict result:" + res);
      }
    })
    .catch((error: BusinessError) => {
      console.error('promise, getCurrentDistrict: error=' + JSON.stringify(error));
    });
  } catch (error) {
    console.error("getCurrentDistrict: errCode" + error.code + ", errMessage" + error.message);
  }
  ```

## geoLocationManager.getPostProcessingTrack

getPostProcessingTrack(sportsType: SportsType): Promise&lt;Array&lt;Location&gt;&gt;

Obtains the post-processing track for a specific sports mode based on the input [sportsType](#sportstype18). Before calling this API, you need to call [geoLocationManager.on('locationChange')](#geolocationmanageronlocationchange) and configure the correct sports mode in [SportsType](#sportstype18) in the [ContinuousLocationRequest](#continuouslocationrequest12) input parameter. Currently, only the skiing mode is supported. The recorded sports track is cleared after 24 hours.

**Since**: 26.0.0

**Permission required:** ohos.permission.LOCATION

**System capability:** SystemCapability.Location.Location.Gnss

**Model restriction**: This API can be used only in the stage model.

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | sportsType | [SportsType](#sportstype18) | No | Sports mode for which the post-processing track is to be obtained. Currently, only the skiing mode is supported. |

**Return value**

  | Type | Description |
  | -------- | -------- |
  | Promise&lt;Array&lt;[Location](#location)&gt;&gt; | Promise used to return the post-processing sports track. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 |
|801 | Capability not supported. Failed to call ${geoLocationManager.getPostProcessingTrack} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301100 | The location switch is off.  |
|3301200 | Failed to obtain the geographical location.  |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let request: geoLocationManager.ContinuousLocationRequest = {
    'interval': 1,
    'locationScenario': geoLocationManager.UserActivityScenario.SPORT,
    // Set the sports type to skiing.
    'sportsType': geoLocationManager.SportsType.SKIING,
  };

  let locationCallback = (location: geoLocationManager.Location): void => {
    console.info('locationCallback: data: ' + JSON.stringify(location));
  };

  let processTrackTask = (): void => {
    // Remove the location request first.
    geoLocationManager.off('locationChange', locationCallback);
    // Obtain the post-processing track.
    geoLocationManager.getPostProcessingTrack(geoLocationManager.SportsType.SKIING)
      .then((res) => {
        console.info('getPostProcessingTrack len: ' + JSON.stringify(res.length));
      }).catch((err: BusinessError) => {
        console.info('getPostProcessingTrack err: ' + JSON.stringify(err));
      })
  }

  try {
    // Initiate a skiing mode location request.
    geoLocationManager.on('locationChange', request, locationCallback);
    // After the track collection conditions are met, remove the location request and obtain the post-processing track. Here, the track collection requirement is set to be met after 30 minutes.
    let delayTaskTime = 30 * 60 * 1000;
    setTimeout(processTrackTask, delayTaskTime);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.startBluetoothSearch

startBluetoothSearch(request: BluetoothSearchRequestParams, callback: Callback&lt;BluetoothScanResult&gt;): void

Starts a Bluetooth scan and searches for the specified Bluetooth devices. The Bluetooth device information is returned through the callback only when the scanned Bluetooth device meets the conditions specified in the input parameter **BluetoothSearchRequestParams**.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**Permission required:** ohos.permission.APPROXIMATELY_LOCATION

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | request | [BluetoothSearchRequestParams](#bluetoothsearchrequestparams) | Yes | Bluetooth scan request parameters. |
  | callback | Callback&lt;[BluetoothScanResult](#bluetoothscanresult16)&gt; | Yes | Callback used to return the Bluetooth scan result. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
|201 | Permission verification failed. The application does not have the permission required to call the API.              | 
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                 | 
|801 | Capability not supported. Failed to call ${geoLocationManager.startBluetoothSearch} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |
|3301800 | Failed to start Bluetooth scanning.                                        |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  
  private callback = (bluetoothScanResult: geoLocationManager.BluetoothScanResult) => {
    if (bluetoothScanResult) {
      console.info('bluetoothScanResult: deviceId=' + bluetoothScanResult.deviceId);
        try {
          // You need to consider calling stopBluetoothSearch at an appropriate time to stop Bluetooth scanning to save power. This code is for reference only.
          geoLocationManager.stopBluetoothSearch(this.callback);
        } catch (err) {
          console.error("errCode:" + err.code + ", message:" + err.message);
        }
    }
  };
  let request: geoLocationManager.BluetoothSearchRequestParams = {
    'rssiThreshold': -=100,
    'deviceIdArray': ['98:56:07:E6:AA:46','4E:E6:D2:02:27:F9']
  };
  
  try {
    geoLocationManager.startBluetoothSearch(request, this.callback);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```

## geoLocationManager.stopBluetoothSearch

stopBluetoothSearch(callback?: Callback&lt;BluetoothScanResult&gt;): void

Stops the Bluetooth scan. The callback must be the same as the one passed in the **startBluetoothSearch** API. If this parameter is not specified, all subscriptions of the current type are canceled.

**Since**: 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Location.Location.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | callback | Callback&lt;[BluetoothScanResult](#bluetoothscanresult16)&gt; | No | Callback to unregister. This callback must be the same as the one passed in the **on** API. If this parameter is not specified, all subscriptions of the current type are canceled. |

**Error codes**

For details about the error codes, see [Location Kit Error Codes](errorcode-geoLocationManager.md).

| ID | Error Message |
| -------- | ---------------------------------------- |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.                               | 
|801 | Capability not supported. Failed to call ${geoLocationManager.stopBluetoothSearch} due to limited device capabilities.          |
|3301000 | The location service is unavailable.                                           |

**Example**

  ```ts
  import { geoLocationManager } from '@kit.LocationKit';
  
  let request: geoLocationManager.BluetoothSearchRequestParams = {
    'rssiThreshold': -100,
    'deviceIdArray': ['98:56:07:E6:AA:46','4E:E6:D2:02:27:F9']
  };
  let callback = (bluetoothScanResult: geoLocationManager.BluetoothScanResult) => {
    if (bluetoothScanResult) {
      console.info('bluetoothScanResult: deviceId=' + bluetoothScanResult.deviceId);
    }
  };
  try {
    geoLocationManager.startBluetoothSearch(request, callback);
    geoLocationManager.stopBluetoothSearch(callback);
  } catch (err) {
    console.error("errCode:" + err.code + ", message:" + err.message);
  }
  ```