# Geolocation Manager

The Geolocation Manager module provides location service management functions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Applying for Permissions

Before using basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user as described below.

The system provides the following location permissions:
- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

- ohos.permission.LOCATION_IN_BACKGROUND

If your application needs to access the device location information, it must first apply for required permissions. Specifically speaking:

- API versions earlier than 9: Apply for **ohos.permission.LOCATION**.

- API version 9 and later: Apply for **ohos.permission.APPROXIMATELY\_LOCATION**, or apply for **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION**. Note that **ohos.permission.LOCATION** cannot be applied for separately.

| API Version| Location Permission| Permission Application Result| Location Accuracy|
| -------- | -------- | -------- | -------- |
| Earlier than 9| ohos.permission.LOCATION | Success| Location accurate to meters|
| 9 and later| ohos.permission.LOCATION | Failure| No location obtained|
| 9 and later| ohos.permission.APPROXIMATELY_LOCATION | Success| Location accurate to 5 kilometers|
| 9 and later| ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION| Success| Location accurate to meters|

If your application needs to access the device location information when running in the background, it must be configured to be able to run in the background and be granted the **ohos.permission.LOCATION_IN_BACKGROUND** permission. In this way, the system continues to report device location information after your application moves to the background.

You can declare the required permission in your application's configuration file. For details, see [Access Control (Permission) Development](../../security/accesstoken-guidelines.md).


## Modules to Import

```ts
import geoLocationManager from '@ohos.geoLocationManager';
```


## geoLocationManager.on('locationChange')

on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;): void

Registers a listener for location changes with a location request initiated. The location result is reported through [LocationRequest](#locationrequest).

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationChange** indicates a location change event.|
  | request |  [LocationRequest](#locationrequest) | Yes| Location request.|
  | callback | Callback&lt;[Location](#location)&gt; | Yes| Callback used to return the location change event.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', requestInfo, locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  
  ```


## geoLocationManager.off('locationChange')

off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void

Unregisters the listener for location changes with the corresponding location request deleted.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationChange** indicates a location change event.|
  | callback | Callback&lt;[Location](#location)&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', requestInfo, locationChange);
      geoLocationManager.off('locationChange', locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('locationEnabledChange')

on(type: 'locationEnabledChange', callback: Callback&lt;boolean&gt;): void

Registers a listener for location service status change events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationEnabledChange** indicates a location service status change event.|
  | callback | Callback&lt;boolean&gt; | Yes| Callback used to return the location service status change event.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var locationEnabledChange = (state) => {
      console.log('locationEnabledChange: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('locationEnabledChange')

off(type: 'locationEnabledChange', callback?: Callback&lt;boolean&gt;): void;

Unregisters the listener for location service status change events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationEnabledChange** indicates a location service status change event.|
  | callback | Callback&lt;boolean&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var locationEnabledChange = (state) => {
      console.log('locationEnabledChange: state: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
      geoLocationManager.off('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('cachedGnssLocationsChange')

on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;): void;

Registers a listener for cached GNSS location reports.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **cachedGnssLocationsChange** indicates reporting of cached GNSS locations.|
  | request |  [CachedGnssLocationsRequest](#cachedgnsslocationsrequest) | Yes| Request for reporting cached GNSS location.|
  | callback | Callback&lt;boolean&gt; | Yes| Callback used to return cached GNSS locations.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  try {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('cachedGnssLocationsChange')

off(type: 'cachedGnssLocationsChange', callback?: Callback&lt;Array&lt;Location&gt;&gt;): void;

Unregisters the listener for cached GNSS location reports.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **cachedGnssLocationsChange** indicates reporting of cached GNSS locations.|
  | callback | Callback&lt;boolean&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  try {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
      geoLocationManager.off('cachedGnssLocationsChange');
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('satelliteStatusChange')

on(type: 'satelliteStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;): void;

Registers a listener for GNSS satellite status change events.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **satelliteStatusChange** indicates a GNSS satellite status change event.|
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | Yes| Callback used to return GNSS satellite status changes.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }

  try {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('satelliteStatusChange')

off(type: 'satelliteStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;): void;

Unregisters the listener for GNSS satellite status change events.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **satelliteStatusChange** indicates a GNSS satellite status change event.|
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |


**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  try {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
      geoLocationManager.off('satelliteStatusChange', gnssStatusCb);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('nmeaMessage')

on(type: 'nmeaMessage', callback: Callback&lt;string&gt;): void;

Registers a listener for GNSS NMEA message change events.

**Permission required**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **nmeaMessage** indicates a GNSS NMEA message change event.|
  | callback | Callback&lt;string&gt; | Yes| Callback used to return GNSS NMEA message changes.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |


**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var nmeaCb = (str) => {
      console.log('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
      geoLocationManager.on('nmeaMessage', nmeaCb );
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('nmeaMessage')

off(type: 'nmeaMessage', callback?: Callback&lt;string&gt;): void;

Unregisters the listener for GNSS NMEA message change events.

**Permission required**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **nmeaMessage** indicates a GNSS NMEA message change event.|
  | callback | Callback&lt;string&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |


**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var nmeaCb = (str) => {
      console.log('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
      geoLocationManager.on('nmeaMessage', nmeaCb);
      geoLocationManager.off('nmeaMessage', nmeaCb);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('gnssFenceStatusChange')

on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

Registers a listener for status change events of the specified geofence.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **gnssFenceStatusChange** indicates a geofence status change event.|
  | request |  [GeofenceRequest](#geofencerequest) | Yes| Geofencing request.|
  | want | WantAgent | Yes| **WantAgent** used to return geofence (entrance or exit) events.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301600 | Failed to operate the geofence.                                     |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import wantAgent from '@ohos.wantAgent';
  
  let wantAgentInfo = {
      wants: [
          {
              bundleName: "com.example.myapplication",
              abilityName: "com.example.myapplication.MainAbility",
              action: "action1",
          }
      ],
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
  };
  
  wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    var requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
    try {
        geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
    } catch (err) {
        console.error("errCode:" + err.code + ",errMessage:" + err.message);
    }
  });
  ```


## geoLocationManager.off('gnssFenceStatusChange')

off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

Unregisters the listener for status change events of the specified geofence.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **gnssFenceStatusChange** indicates a geofence status change event.|
  | request | [GeofenceRequest](#geofencerequest) | Yes| Geofencing request.|
  | want | WantAgent | Yes| **WantAgent** used to return geofence (entrance or exit) events.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301600 | Failed to operate the geofence.                                     |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import wantAgent from '@ohos.wantAgent';
  
  let wantAgentInfo = {
      wants: [
          {
              bundleName: "com.example.myapplication",
              abilityName: "com.example.myapplication.MainAbility",
              action: "action1",
          }
      ],
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
  };
  
  wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    var requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
    try {
        geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
        geoLocationManager.off('gnssFenceStatusChange', requestInfo, wantAgentObj);
    } catch (err) {
        console.error("errCode:" + err.code + ",errMessage:" + err.message);
    }
  });
  ```


## geoLocationManager.on('countryCodeChange')

on(type: 'countryCodeChange', callback: Callback&lt;CountryCode&gt;): void;

Registers a listener for country code change events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **countryCodeChange** indicates a country code change event.|
  | callback | Callback&lt;[CountryCode](#countrycode)&gt; | Yes| Callback used to return the country code change event.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301500 | Failed to query the area information.                                       |


**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
      geoLocationManager.on('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('countryCodeChange')

off(type: 'countryCodeChange', callback?: Callback&lt;CountryCode&gt;): void;

Unregisters the listener for country code change events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **countryCodeChange** indicates a country code change event.|
  | callback | Callback&lt;[CountryCode](#countrycode)&gt; | No| Callback to unregister. If this parameter is not specified, all callbacks of the specified event type are unregistered.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301500 | Failed to query the area information.                                       |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
      geoLocationManager.on('countryCodeChange', callback);
      geoLocationManager.off('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```



## geoLocationManager.getCurrentLocation

getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;): void

Obtains the current location. This API uses an asynchronous callback to return the result. 

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | Yes| Location request.|
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes| Callback used to return the current location.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  var locationChange = (err, location) => {
      if (err) {
          console.log('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.log('locationChanger: location=' + JSON.stringify(location));
      }
  };

  try {
      geoLocationManager.getCurrentLocation(requestInfo, locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## geoLocationManager.getCurrentLocation

getCurrentLocation(callback: AsyncCallback&lt;Location&gt;): void;

Obtains the current location. This API uses an asynchronous callback to return the result. 

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes| Callback used to return the current location.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var locationChange = (err, location) => {
      if (err) {
          console.log('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.log('locationChanger: location=' + JSON.stringify(location));
      }
  };

  try {
      geoLocationManager.getCurrentLocation(locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## geoLocationManager.getCurrentLocation

getCurrentLocation(request?: CurrentLocationRequest): Promise&lt;Location&gt;

Obtains the current location. This API uses a promise to return the result. 

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | No| Location request.|

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Promise&lt;[Location](#location)&gt;  | [Location](#location) | NA | Promise used to return the current location.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  try {
      geoLocationManager.getCurrentLocation(requestInfo).then((result) => {
          console.log('current location: ' + JSON.stringify(result));
      })  
      .catch((error) => {
          console.log('promise, getCurrentLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getLastLocation

getLastLocation(): Location

Obtains the last location.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Location  | [Location](#location) | NA | Location information.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |
|3301100 | The location switch is off.  |
|3301200 |Failed to obtain the geographical location.  |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      var location = geoLocationManager.getLastLocation();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.isLocationEnabled

isLocationEnabled(): boolean

Checks whether the location service is enabled.

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | boolean  | boolean | NA | Result indicating whether the location service is enabled.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      var locationEnabled = geoLocationManager.isLocationEnabled();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.requestEnableLocation

requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;): void

Requests to enable the location service. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. The value **true** indicates that the user agrees to enable the location service, and the value **false** indicates the opposite.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |
|3301700 | No response to the request.  |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.requestEnableLocation((err, data) => {
          if (err) {
              console.log('requestEnableLocation: err=' + JSON.stringify(err));
          }
          if (data) {
              console.log('requestEnableLocation: data=' + JSON.stringify(data));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.requestEnableLocation

requestEnableLocation(): Promise&lt;boolean&gt;

Requests to enable the location service. This API uses a promise to return the result.

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Promise&lt;boolean&gt;  | boolean | NA | Promise used to return the result. The value **true** indicates that the user agrees to enable the location service, and the value **false** indicates the opposite.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |
|3301700 | No response to the request.  |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.requestEnableLocation().then((result) => {
          console.log('promise, requestEnableLocation: ' + JSON.stringify(result));
      })  
      .catch((error) => {
          console.log('promise, requestEnableLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.enableLocation

enableLocation(callback: AsyncCallback&lt;void&gt;): void;

Enables the location service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the error message.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.enableLocation((err, data) => {
          if (err) {
              console.log('enableLocation: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.enableLocation

enableLocation(): Promise&lt;void&gt;

Enables the location service. This API uses a promise to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Promise&lt;void&gt;  | void | NA | Promise used to return the error message.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.enableLocation().then((result) => {
          console.log('promise, enableLocation succeed');
      })
      .catch((error) => {
          console.log('promise, enableLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## geoLocationManager.disableLocation

disableLocation(): void;

Disables the location service.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.disableLocation();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```



## geoLocationManager.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

Converts coordinates into geographic description through reverse geocoding. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes| Reverse geocoding request.|
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Yes| Callback used to return the reverse geocoding result.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301300 | Reverse geocoding query failed.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
          if (err) {
              console.log('getAddressesFromLocation: err=' + JSON.stringify(err));
          }
          if (data) {
              console.log('getAddressesFromLocation: data=' + JSON.stringify(data));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;;

Converts coordinates into geographic description through reverse geocoding. This API uses a promise to return the result. 

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes| Reverse geocoding request.|

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt;  | Array&lt;[GeoAddress](#geoaddress)&gt; | NA | Promise used to return the reverse geocoding result.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301300 | Reverse geocoding query failed.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {
          console.log('getAddressesFromLocation: ' + JSON.stringify(data));
      })
      .catch((error) => {
          console.log('promise, getAddressesFromLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

Converts geographic description into coordinates through geocoding. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | Yes| Geocoding request.|
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Yes| Callback used to return the geocoding result.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301400 | Geocoding query failed.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {
          if (err) {
              console.log('getAddressesFromLocationName: err=' + JSON.stringify(err));
          }
          if (data) {
              console.log('getAddressesFromLocationName: data=' + JSON.stringify(data));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;

Converts geographic description into coordinates through geocoding. This API uses a promise to return the result. 

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | Yes| Geocoding request.|

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt;  | Array&lt;[GeoAddress](#geoaddress)&gt; | NA | Promise used to return the geocoding result.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301400 | Geocoding query failed.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocationName(geocodeRequest).then((result) => {
          console.log('getAddressesFromLocationName: ' + JSON.stringify(result));
      })
      .catch((error) => {
          console.log('promise, getAddressesFromLocationName: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## geoLocationManager.isGeocoderAvailable

isGeocoderAvailable(): boolean;

Obtains the (reverse) geocoding service status.

**System capability**: SystemCapability.Location.Location.Geocoder

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | boolean  | boolean | NA | Result indicating whether the (reverse) geocoding service is available.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      var isAvailable = geoLocationManager.isGeocoderAvailable();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;): void;

Obtains the number of cached GNSS locations. 

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the number of cached GNSS locations. |

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.getCachedGnssLocationsSize((err, size) => {
          if (err) {
              console.log('getCachedGnssLocationsSize: err=' + JSON.stringify(err));
          }
          if (size) {
              console.log('getCachedGnssLocationsSize: size=' + JSON.stringify(size));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(): Promise&lt;number&gt;;

Obtains the number of cached GNSS locations. 

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Promise&lt;number&gt;  | number | NA | Promise used to return the number of cached GNSS locations.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.getCachedGnssLocationsSize().then((result) => {
          console.log('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));
      }) 
      .catch((error) => {
          console.log('promise, getCachedGnssLocationsSize: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(callback: AsyncCallback&lt;void&gt;): void;

Obtains all cached GNSS locations and clears the GNSS cache queue. 

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the error message.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |
|3301200 | Failed to obtain the geographical location.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.flushCachedGnssLocations((err, result) => {
          if (err) {
              console.log('flushCachedGnssLocations: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(): Promise&lt;void&gt;;

Obtains all cached GNSS locations and clears the GNSS cache queue. 

**Permission required**: ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Promise&lt;void&gt;  | void | NA | Promise used to return the error code.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |
|3301200 | Failed to obtain the geographical location.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.flushCachedGnssLocations().then((result) => {
          console.log('promise, flushCachedGnssLocations success');
      })
      .catch((error) => {
          console.log('promise, flushCachedGnssLocations: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.sendCommand

sendCommand(command: LocationCommand, callback: AsyncCallback&lt;void&gt;): void;

Sends an extended command to the location subsystem. 

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | command |  [LocationCommand](#locationcommand) | Yes| Extended command (string) to be sent.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the error code.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'scenario': 0x301, 'command': "command_1"};
  try {
      geoLocationManager.sendCommand(requestInfo, (err, result) => {
          if (err) {
              console.log('sendCommand: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.sendCommand

sendCommand(command: LocationCommand): Promise&lt;void&gt;;

Sends an extended command to the location subsystem. 

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | command | [LocationCommand](#locationcommand) | Yes| Extended command (string) to be sent.|

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Promise&lt;void&gt;  | void | NA | Promise used to return the error code.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'scenario': 0x301, 'command': "command_1"};
  try {
      geoLocationManager.sendCommand(requestInfo).then((result) => {
          console.log('promise, sendCommand success');
      })  
      .catch((error) => {
          console.log('promise, sendCommand: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getCountryCode

getCountryCode(callback: AsyncCallback&lt;CountryCode&gt;): void;

Obtains the current country code.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[CountryCode](#countrycode)&gt; | Yes| Callback used to return the country code.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301500 | Failed to query the area information.|

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.getCountryCode((err, result) => {
          if (err) {
              console.log('getCountryCode: err=' + JSON.stringify(err));
          }
          if (result) {
              console.log('getCountryCode: result=' + JSON.stringify(result));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getCountryCode

getCountryCode(): Promise&lt;CountryCode&gt;;

Obtains the current country code.

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | Promise&lt;[CountryCode](#countrycode)&gt; | [CountryCode](#countrycode) | NA | Promise used to return the country code.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301500 | Failed to query the area information.|

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.getCountryCode()
      .then((result) => {
          console.log('promise, getCountryCode: result=' + JSON.stringify(result));
      })
      .catch((error) => {
          console.log('promise, getCountryCode: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.enableLocationMock

enableLocationMock(): void;

Enables the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.enableLocationMock();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.disableLocationMock

disableLocationMock(): void;

Disables the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.disableLocationMock();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.setMockedLocations

setMockedLocations(config: LocationMockConfig): void;

Sets the mock location information. The mock locations will be reported at the interval specified in this API.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | config |  [LocationMockConfig](#locationmockconfig) | Yes| Mock location information, including the interval for reporting the mock locations and the array of the mock locations.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var locations = [
      {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}
  ];
  var config = {"timeInterval": 5, "locations": locations};
  try {
      geoLocationManager.setMockedLocations(config);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.enableReverseGeocodingMock

enableReverseGeocodingMock(): void;

Enables the mock reverse geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.enableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.disableReverseGeocodingMock

disableReverseGeocodingMock(): void;

Disables the mock geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.disableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.setReverseGeocodingMockInfo

setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;): void;

Sets information of the mock reverse geocoding function, including the mapping between a location and geographical name. If the location is contained in the configurations during reverse geocoding query, the corresponding geographical name will be returned.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | mockInfos | Array&lt;[ReverseGeocodingMockInfo](#reversegeocodingmockinfo)&gt; | Yes| Array of information of the mock reverse geocoding function, including a location and a geographical name.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var mockInfos = [
      {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1, "isFromMock": true}},
  ];
  try {
      geoLocationManager.setReverseGeocodingMockInfo(mockInfos);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.isLocationPrivacyConfirmed

isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean;

Checks whether a user agrees with the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type |  [LocationPrivacyType](#locationprivacytype)| Yes| Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when the location service is enabled.|

**Return value**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | boolean  | boolean | NA | Callback used to return the result, which indicates whether the user agrees with the privacy statement.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      var isConfirmed = geoLocationManager.isLocationPrivacyConfirmed(1);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.setLocationPrivacyConfirmStatus

setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void;

Sets the user confirmation status for the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | [LocationPrivacyType](#locationprivacytype) | Yes| Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when the location service is enabled.|
  | isConfirmed | boolean | Yes| Callback used to return the result, which indicates whether the user agrees with the privacy statement.|

**Error codes**

For details about the following error codes, see [Location Error Codes](../errorcodes/errorcode-geoLocationManager.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**Example**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.setLocationPrivacyConfirmStatus(1, true);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## LocationRequestPriority

Sets the priority of the location request.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| UNSET | 0x200 | Priority unspecified.|
| ACCURACY | 0x201 | Location accuracy.|
| LOW_POWER | 0x202 | Power efficiency.|
| FIRST_FIX | 0x203 | Fast location. Use this option if you want to obtain a location as fast as possible.|


## LocationRequestScenario

  Sets the scenario of the location request.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| UNSET | 0x300 | Scenario unspecified.|
| NAVIGATION | 0x301 | Navigation.|
| TRAJECTORY_TRACKING | 0x302 | Trajectory tracking.|
| CAR_HAILING | 0x303 | Ride hailing.|
| DAILY_LIFE_SERVICE | 0x304 | Daily life services.|
| NO_POWER | 0x305 | Power efficiency. Your application does not proactively start the location service. When responding to another application requesting the same location service, the system marks a copy of the location result to your application. In this way, your application will not consume extra power for obtaining the user location.|


## ReverseGeoCodeRequest

Defines a reverse geocoding request.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | Yes| Yes| Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| latitude | number | Yes| Yes| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude.|
| longitude | number | Yes| Yes| Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude .|
| maxItems | number | Yes| Yes| Maximum number of location records to be returned.|


## GeoCodeRequest

Defines a geocoding request.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| locale | string | Yes| Yes| Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| description | string | Yes| Yes| Location description, for example, **No. xx, xx Road, Pudong New District, Shanghai**.|
| maxItems | number | Yes| Yes| Maximum number of location records to be returned.|
| minLatitude | number | Yes| Yes| Minimum latitude. This parameter is used with **minLongitude**, **maxLatitude**, and **maxLongitude** to specify the latitude and longitude ranges.|
| minLongitude | number | Yes| Yes| Minimum longitude.|
| maxLatitude | number | Yes| Yes| Maximum latitude.|
| maxLongitude | number | Yes| Yes| Maximum longitude.|


## GeoAddress

Defines a geographic location.

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | Yes| No | Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude.|
| longitude | number | Yes| No | Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude .|
| locale | string | Yes| No | Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| placeName | string | Yes| No | Landmark of the location.|
| countryCode | string | Yes| No | Country code.|
| countryName | string| Yes| No| Country name.|
| administrativeArea | string | Yes| No| Administrative region name.|
| subAdministrativeArea | string | Yes| No| Sub-administrative region name.|
| locality | string | Yes| No| Locality information.|
| subLocality | string | Yes| No| Sub-locality information.|
| roadName | string | Yes| No|Road name.|
| subRoadName | string | Yes| No| Auxiliary road information.|
| premises | string| Yes| No|House information.|
| postalCode | string | Yes| No| Postal code.|
| phoneNumber | string | Yes| No| Phone number.|
| addressUrl | string | Yes| No| Website URL.|
| descriptions | Array&lt;string&gt; | Yes| No| Additional descriptions.|
| descriptionsSize | number | Yes| No| Total number of additional descriptions.|
| isFromMock | Boolean | Yes| No| Whether the geographical name is from the mock reverse geocoding function.|


## LocationRequest

Defines a location request.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | Yes| Yes| Priority of the location request.|
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes| Yes| Scenario of the location request.|
| timeInterval | number | Yes| Yes| Time interval at which location information is reported.|
| distanceInterval | number | Yes| Yes| Distance interval at which location information is reported.|
| maxAccuracy | number | Yes| Yes| Location accuracy. This parameter is valid only when the precise location function is enabled, and is invalid when the approximate location function is enabled.|


## CurrentLocationRequest

Defines the current location request.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | Yes| Yes| Priority of the location request.|
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes| Yes| Scenario of the location request.|
| maxAccuracy | number | Yes| Yes| Location accuracy, in meters. This parameter is valid only when the precise location function is enabled, and is invalid when the approximate location function is enabled.|
| timeoutMs | number | Yes| Yes| Timeout duration, in milliseconds. The minimum value is **1000**.|


## SatelliteStatusInfo

Defines the satellite status information.

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| satellitesNumber | number | Yes| No| Number of satellites.|
| satelliteIds | Array&lt;number&gt; | Yes| No| Array of satellite IDs.|
| carrierToNoiseDensitys | Array&lt;number&gt; | Yes| No| Carrier-to-noise density ratio, that is, **cn0**.|
| altitudes | Array&lt;number&gt; | Yes| No| Altitude information.|
| azimuths | Array&lt;number&gt; | Yes| No| Azimuth information.|
| carrierFrequencies | Array&lt;number&gt; | Yes| No| Carrier frequency.|


## CachedGnssLocationsRequest

Represents a request for reporting cached GNSS locations.

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| reportingPeriodSec | number | Yes| Yes| Interval for reporting the cached GNSS locations, in milliseconds.|
| wakeUpCacheQueueFull | boolean | Yes| Yes | **true**: reports the cached GNSS locations to the application when the cache queue is full.<br>**false**: discards the cached GNSS locations when the cache queue is full.|


## Geofence

Defines a GNSS geofence. Currently, only circular geofences are supported.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | Yes| Yes|Latitude information.|
| longitude | number | Yes|Yes| Longitude information.|
| radius | number | Yes|Yes| Radius of a circular geofence.|
| expiration | number | Yes|Yes| Expiration period of a geofence, in milliseconds.|


## GeofenceRequest

Represents a GNSS geofencing request.

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes| Yes |  Location scenario.|
| geofence |  [Geofence](#geofence)| Yes| Yes |  Geofence information.|


## LocationPrivacyType

Defines the privacy statement type.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| OTHERS | 0 | Other scenarios.|
| STARTUP | 1 | Privacy statement displayed in the startup wizard.|
| CORE_LOCATION | 2 | Privacy statement displayed when enabling the location service.|


## LocationCommand

Defines an extended command.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| scenario | [LocationRequestScenario](#locationrequestscenario)  | Yes| Yes | Location scenario.|
| command | string | Yes| Yes | Extended command, in the string format.|


## Location

Defines a location.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| latitude | number| Yes| No| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude.|
| longitude | number| Yes| No| Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude .|
| altitude | number | Yes| No| Location altitude, in meters.|
| accuracy | number | Yes| No| Location accuracy, in meters.|
| speed | number | Yes| No|Speed, in m/s.|
| timeStamp | number | Yes| No| Location timestamp in the UTC format.|
| direction | number | Yes| No| Direction information.|
| timeSinceBoot | number | Yes| No| Location timestamp since boot.|
| additions | Array&lt;string&gt; | Yes| No| Additional description.|
| additionSize | number | Yes| No| Number of additional descriptions.|
| isFromMock | Boolean | Yes| No| Whether the location information is from the mock location function.|


## ReverseGeocodingMockInfo

Represents information of the mock reverse geocoding function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| location |  [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes| Yes| Latitude and longitude information.|
| geoAddress |  [GeoAddress](#geoaddress) | Yes| Yes|Geographical name.|


## LocationMockConfig

Represents the information of the mock location function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| timeInterval | number | Yes| Yes| Interval at which mock locations are reported, in seconds.|
| locations | Array&lt;Location&gt; | Yes| Yes| Array of mocked locations.|


## CountryCode

Represents country code information.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Readable|Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| country | string | Yes| No| Country code.|
| type |  [CountryCodeType](#countrycodetype) | Yes| No| Country code source.|


## CountryCodeType

Represents the country code source type.

**System capability**: SystemCapability.Location.Location.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| COUNTRY_CODE_FROM_LOCALE | 1 | Country code obtained from the language configuration of the globalization module.|
| COUNTRY_CODE_FROM_SIM | 2 | Country code obtained from the SIM card.|
| COUNTRY_CODE_FROM_LOCATION | 3 | Country code obtained using the reverse geocoding function based on the user's location information.|
| COUNTRY_CODE_FROM_NETWORK | 4 | Country code obtained from the cellular network registration information.|
