# Geolocation

Location services provide basic functions such as GNSS positioning, network positioning, geocoding, reverse geocoding, country code and geofencing.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import geolocation from '@ohos.geolocation';
```

## geolocation.on('locationChange')

on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;): void

Registers a listener for location changes with a location request initiated.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationChange** indicates a location change event.|
  | request | LocationRequest | Yes| Location request.|
  | callback | Callback&lt;[Location](#location)&gt; | Yes| Callback used to return the location change event.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  geolocation.on('locationChange', requestInfo, locationChange);
  ```


## geolocation.off('locationChange')

off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void

Unregisters the listener for location changes with the corresponding location request deleted.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationChange** indicates a location change event.|
  | callback | Callback&lt;[Location](#location)&gt; | No| Callback used to return the location change event.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  geolocation.on('locationChange', requestInfo, locationChange);
  geolocation.off('locationChange', locationChange);
  ```


## geolocation.on('locationServiceState')

on(type: 'locationServiceState', callback: Callback&lt;boolean&gt;): void

Registers a listener for location service status change events.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationServiceState** indicates a location service status change event.|
  | callback | Callback&lt;boolean&gt; | Yes| Callback used to return the location service status change event.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var locationServiceState = (state) => {
      console.log('locationServiceState: ' + JSON.stringify(state));
  }
  geolocation.on('locationServiceState', locationServiceState);
  ```


## geolocation.off('locationServiceState')

off(type: 'locationServiceState', callback?: Callback&lt;boolean&gt;): void;

Unregisters the listener for location service status change events.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **locationServiceState** indicates a location service status change event.|
  | callback | Callback&lt;boolean&gt; | No| Callback used to return the location service status change event.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var locationServiceState = (state) => {
      console.log('locationServiceState: state: ' + JSON.stringify(state));
  }
  geolocation.on('locationServiceState', locationServiceState);
  geolocation.off('locationServiceState', locationServiceState);
  ```


## geolocation.on('cachedGnssLocationsReporting')<sup>8+</sup>

on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;): void;

Registers a listener for cached GNSS location reports.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **cachedGnssLocationsReporting** indicates reporting of cached GNSS locations.|
  | request | CachedGnssLocationsRequest | Yes| Request for reporting cached GNSS location.|
  | callback | Callback&lt;boolean&gt; | Yes| Callback used to return cached GNSS locations.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsReporting: locations: ' + JSON.stringify(locations));
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  geolocation.on('cachedGnssLocationsReporting', requestInfo, cachedLocationsCb);
  ```


## geolocation.off('cachedGnssLocationsReporting')<sup>8+</sup>

off(type: 'cachedGnssLocationsReporting', callback?: Callback&lt;Array&lt;Location&gt;&gt;): void;

Unregisters the listener for cached GNSS location reports.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **cachedGnssLocationsReporting** indicates reporting of cached GNSS locations.|
  | callback | Callback&lt;boolean&gt; | No| Callback used to return cached GNSS locations.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsReporting: locations: ' + JSON.stringify(locations));
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  geolocation.on('cachedGnssLocationsReporting', requestInfo, cachedLocationsCb);
  geolocation.off('cachedGnssLocationsReporting');
  ```


## geolocation.on('gnssStatusChange')<sup>8+</sup>

on(type: 'gnssStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;): void;

Registers a listener for GNSS satellite status change events.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **gnssStatusChange** indicates a GNSS satellite status change.|
  | callback | Callback&lt;SatelliteStatusInfo&gt; | Yes| Callback used to return GNSS satellite status changes.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('gnssStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  geolocation.on('gnssStatusChange', gnssStatusCb);
  ```


## geolocation.off('gnssStatusChange')<sup>8+</sup>

off(type: 'gnssStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;): void;

Unregisters the listener for GNSS satellite status change events.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **gnssStatusChange** indicates a GNSS satellite status change.|
  | callback | Callback&lt;SatelliteStatusInfo&gt; | No| Callback used to return GNSS satellite status changes.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('gnssStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  geolocation.on('gnssStatusChange', gnssStatusCb);
  geolocation.off('gnssStatusChange', gnssStatusCb);
  ```


## geolocation.on('nmeaMessageChange')<sup>8+</sup>

on(type: 'nmeaMessageChange', callback: Callback&lt;string&gt;): void;

Registers a listener for GNSS NMEA message change events.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **nmeaMessageChange** indicates a GNSS NMEA message change.|
  | callback | Callback&lt;string&gt; | Yes| Callback used to return GNSS NMEA message changes.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var nmeaCb = (str) => {
      console.log('nmeaMessageChange: ' + JSON.stringify(str));
  }
  geolocation.on('nmeaMessageChange', nmeaCb );
  ```


## geolocation.off('nmeaMessageChange')<sup>8+</sup>

off(type: 'nmeaMessageChange', callback?: Callback&lt;string&gt;): void;

Unregisters the listener for GNSS NMEA message change events.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **nmeaMessageChange** indicates a GNSS NMEA message change.|
  | callback | Callback&lt;string&gt; | No| Callback used to return GNSS NMEA message changes.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var nmeaCb = (str) => {
      console.log('nmeaMessageChange: ' + JSON.stringify(str));
  }
  geolocation.on('nmeaMessageChange', nmeaCb);
  geolocation.off('nmeaMessageChange', nmeaCb);
  ```


## geolocation.on('fenceStatusChange')<sup>8+</sup>

on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

Registers a listener for status change events of the specified geofence.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **fenceStatusChange** indicates a geofence status change.|
  | request | GeofenceRequest | Yes| Geofencing request.|
  | want | WantAgent | Yes| **WantAgent** used to return geofence (entrance or exit) events.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
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
    geolocation.on('fenceStatusChange', requestInfo, wantAgentObj);
  });
  ```


## geolocation.off('fenceStatusChange')<sup>8+</sup>

off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

Unregisters the listener for status change events of the specified geofence.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value **fenceStatusChange** indicates a geofence status change.|
  | request | GeofenceRequest | Yes| Geofencing request.|
  | want | WantAgent | Yes| **WantAgent** used to return geofence (entrance or exit) events.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
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
    geolocation.on('fenceStatusChange', requestInfo, wantAgentObj);
    geolocation.off('fenceStatusChange', requestInfo, wantAgentObj);
  });
  ```


## geolocation.getCurrentLocation

getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;): void


Obtains the current location. This API uses an asynchronous callback to return the result. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | No| Location request.|
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes| Callback used to return the current location.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  var locationChange = (err, location) => {
      if (err) {
          console.log('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.log('locationChanger: location=' + JSON.stringify(location));
      }
  };
  geolocation.getCurrentLocation(requestInfo, locationChange);
  geolocation.getCurrentLocation(locationChange);
  ```


## geolocation.getCurrentLocation

getCurrentLocation(request?: CurrentLocationRequest): Promise&lt;Location&gt;


Obtains the current location. This API uses a promise to return the result. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | No| Location request.|

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | Promise used to return the current location.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  geolocation.getCurrentLocation(requestInfo).then((result) => {
      console.log('current location: ' + JSON.stringify(result));
  });
  ```


## geolocation.getLastLocation

getLastLocation(callback: AsyncCallback&lt;Location&gt;): void

Obtains the previous location. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes| Callback used to return the previous location.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.getLastLocation((err, data) => {
      if (err) {
          console.log('getLastLocation: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('getLastLocation: data=' + JSON.stringify(data));
      }
  });
  ```


## geolocation.getLastLocation

getLastLocation(): Promise&lt;Location&gt;

Obtains the previous location. This API uses a promise to return the result. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | Promise used to return the previous location.|


**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.getLastLocation().then((result) => {
      console.log('getLastLocation: result: ' + JSON.stringify(result));
  });
  ```


## geolocation.isLocationEnabled

isLocationEnabled(callback: AsyncCallback&lt;boolean&gt;): void


Checks whether the location service is enabled. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the location service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.isLocationEnabled((err, data) => {
      if (err) {
          console.log('isLocationEnabled: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('isLocationEnabled: data=' + JSON.stringify(data));
      }
  });
  ```


## geolocation.isLocationEnabled

isLocationEnabled(): Promise&lt;boolean&gt;

Checks whether the location service is enabled. This API uses a promise to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the location service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.isLocationEnabled().then((result) => {
      console.log('promise, isLocationEnabled: ' + JSON.stringify(result));
  });
  ```


## geolocation.requestEnableLocation

requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;): void


Requests to enable the location service. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the location service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.requestEnableLocation((err, data) => {
      if (err) {
          console.log('requestEnableLocation: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('requestEnableLocation: data=' + JSON.stringify(data));
      }
  });
  ```


## geolocation.requestEnableLocation

requestEnableLocation(): Promise&lt;boolean&gt;

Requests to enable the location service. This API uses a promise to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the location service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.requestEnableLocation().then((result) => {
      console.log('promise, requestEnableLocation: ' + JSON.stringify(result));
  });
  ```


## geolocation.enableLocation

enableLocation(callback: AsyncCallback&lt;boolean&gt;): void;

Enables the location service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Permission required**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the location service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.enableLocation((err, data) => {
      if (err) {
          console.log('enableLocation: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('enableLocation: data=' + JSON.stringify(data));
      }
  });
  ```


## geolocation.enableLocation

enableLocation(): Promise&lt;boolean&gt;

Enables the location service. This API uses a promise to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Permission required**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the location service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.enableLocation().then((result) => {
      console.log('promise, enableLocation: ' + JSON.stringify(result));
  });
  ```

## geolocation.disableLocation

disableLocation(callback: AsyncCallback&lt;boolean&gt;): void;

Disables the location service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Permission required**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the location service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.disableLocation((err, data) => {
      if (err) {
          console.log('disableLocation: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('disableLocation: data=' + JSON.stringify(data));
      }
  });
  ```


## geolocation.disableLocation

disableLocation(): Promise&lt;boolean&gt;

Disables the location service. This API uses a promise to return the result.

**System API**: This is a system API and cannot be called by third-party applications.

**Permission required**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the location service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.disableLocation().then((result) => {
      console.log('promise, disableLocation: ' + JSON.stringify(result));
  });
  ```

## geolocation.isGeoServiceAvailable

isGeoServiceAvailable(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the (reverse) geocoding service is available. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the (reverse) geocoding service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.isGeoServiceAvailable((err, data) => {
      if (err) {
          console.log('isGeoServiceAvailable: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('isGeoServiceAvailable: data=' + JSON.stringify(data));
      }
  });
  ```


## geolocation.isGeoServiceAvailable

isGeoServiceAvailable(): Promise&lt;boolean&gt;

Checks whether the (reverse) geocoding service is available. This API uses a promise to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the (reverse) geocoding service status.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.isGeoServiceAvailable().then((result) => {
      console.log('promise, isGeoServiceAvailable: ' + JSON.stringify(result));
  });
  ```


## geolocation.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

Converts coordinates into geographic description through reverse geocoding. This API uses an asynchronous callback to return the result. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes| Reverse geocoding request.|
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Yes| Callback used to return the reverse geocoding result.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  geolocation.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
      if (err) {
          console.log('getAddressesFromLocation: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('getAddressesFromLocation: data=' + JSON.stringify(data));
      }
  });
  ```


## geolocation.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;;

Converts coordinates into geographic description through reverse geocoding. This API uses a promise to return the result. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes| Reverse geocoding request.|

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Promise used to return the reverse geocoding result.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  geolocation.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {
      console.log('getAddressesFromLocation: ' + JSON.stringify(data));
  });
  ```


## geolocation.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

Converts geographic description into coordinates through geocoding. This API uses an asynchronous callback to return the result. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | Yes| Geocoding request.|
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Yes| Callback used to return the geocoding result.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  geolocation.getAddressesFromLocationName(geocodeRequest, (err, data) => {
      if (err) {
          console.log('getAddressesFromLocationName: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('getAddressesFromLocationName: data=' + JSON.stringify(data));
      }
  });
  ```


## geolocation.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;

Converts geographic description into coordinates through geocoding. This API uses a promise to return the result. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | Yes| Geocoding request.|

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Callback used to return the geocoding result.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  geolocation.getAddressesFromLocationName(geocodeRequest).then((result) => {
      console.log('getAddressesFromLocationName: ' + JSON.stringify(result));
  });
  ```


## geolocation.getCachedGnssLocationsSize<sup>8+</sup>

getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;): void;

Obtains the number of cached GNSS locations. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the number of cached GNSS locations. |

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.getCachedGnssLocationsSize((err, size) => {
      if (err) {
          console.log('getCachedGnssLocationsSize: err=' + JSON.stringify(err));
      }
      if (size) {
          console.log('getCachedGnssLocationsSize: size=' + JSON.stringify(size));
      }
  });
  ```


## geolocation.getCachedGnssLocationsSize<sup>8+</sup>

getCachedGnssLocationsSize(): Promise&lt;number&gt;;

Obtains the number of cached GNSS locations. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the number of cached GNSS locations.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.getCachedGnssLocationsSize().then((result) => {
      console.log('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));
  });
  ```


## geolocation.flushCachedGnssLocations<sup>8+</sup>

flushCachedGnssLocations(callback: AsyncCallback&lt;boolean&gt;): void;

Obtains all cached GNSS locations and clears the GNSS cache queue. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the operation result.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.flushCachedGnssLocations((err, result) => {
      if (err) {
          console.log('flushCachedGnssLocations: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('flushCachedGnssLocations: result=' + JSON.stringify(result));
      }
  });
  ```


## geolocation.flushCachedGnssLocations<sup>8+</sup>

flushCachedGnssLocations(): Promise&lt;boolean&gt;;

Obtains all cached GNSS locations and clears the GNSS cache queue. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the operation result.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  geolocation.flushCachedGnssLocations().then((result) => {
      console.log('promise, flushCachedGnssLocations: ' + JSON.stringify(result));
  });
  ```


## geolocation.sendCommand<sup>8+</sup>

sendCommand(command: LocationCommand, callback: AsyncCallback&lt;boolean&gt;): void;

Sends an extended command to the location subsystem. This API can only be called by system applications.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | command | LocationCommand | Yes| Extended command (string) to be sent.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the operation result.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var requestInfo = {'scenario': 0x301, 'command': "command_1"};
  geolocation.sendCommand(requestInfo, (err, result) => {
      if (err) {
          console.log('sendCommand: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('sendCommand: result=' + JSON.stringify(result));
      }
  });
  ```


## geolocation.sendCommand<sup>8+</sup>

sendCommand(command: LocationCommand): Promise&lt;boolean&gt;;

Sends an extended command to the location subsystem. This API can only be called by system applications.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | command | LocationCommand | Yes| Extended command (string) to be sent.|

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Callback used to return the operation result.|

**Example**
  
  ```js
  import geolocation from '@ohos.geolocation';
  var requestInfo = {'scenario': 0x301, 'command': "command_1"};
  geolocation.sendCommand(requestInfo).then((result) => {
      console.log('promise, sendCommand: ' + JSON.stringify(result));
  });
  ```


## LocationRequestPriority

Sets the priority of the location request.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

| Name| Default Value| Description|
| -------- | -------- | -------- |
| UNSET | 0x200 | Priority unspecified.|
| ACCURACY | 0x201 | Location accuracy.|
| LOW_POWER | 0x202 | Power efficiency.|
| FIRST_FIX | 0x203 | Fast location. Use this option if you want to obtain a location as fast as possible.|


## LocationRequestScenario

  Sets the scenario of the location request.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

| Name| Default Value| Description|
| -------- | -------- | -------- |
| UNSET | 0x300 | Scenario unspecified.|
| NAVIGATION | 0x301 | Navigation.|
| TRAJECTORY_TRACKING | 0x302 | Trajectory tracking.|
| CAR_HAILING | 0x303 | Ride hailing.|
| DAILY_LIFE_SERVICE | 0x304 | Daily life services.|
| NO_POWER | 0x305 | Power efficiency. Your application does not proactively start the location service. When responding to another application requesting the same location service, the system marks a copy of the location result to your application. In this way, your application will not consume extra power for obtaining the user location.|


## GeoLocationErrorCode

Enumerates error codes of the location service.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

| Name| Default Value| Description|
| -------- | -------- | -------- |
| INPUT_PARAMS_ERROR<sup>7+</sup> | 101 | Incorrect input parameters.|
| REVERSE_GEOCODE_ERROR<sup>7+</sup> | 102 | Failed to call the reverse geocoding API.|
| GEOCODE_ERROR<sup>7+</sup> | 103 | Failed to call the geocoding API.|
| LOCATOR_ERROR<sup>7+</sup> | 104 | Failed to obtain the location.|
| LOCATION_SWITCH_ERROR<sup>7+</sup> | 105 | Failed to change the location service switch.|
| LAST_KNOWN_LOCATION_ERROR<sup>7+</sup> | 106 | Failed to obtain the previous location.|
| LOCATION_REQUEST_TIMEOUT_ERROR<sup>7+</sup> | 107 | Failed to obtain the location within the specified time.|


## ReverseGeoCodeRequest

Defines a reverse geocoding request.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| locale | string | No| Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| latitude | number | Yes| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude.|
| longitude | number | Yes| Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude .|
| maxItems | number | No| Maximum number of location records to be returned.|


## GeoCodeRequest

Defines a geocoding request.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| locale | string | No| Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| description | number | Yes| Location description, for example, No. xx, xx Road, Pudong New District, Shanghai.|
| maxItems | number | No| Maximum number of location records to be returned.|
| minLatitude | number | No| Minimum latitude. This parameter is used with minLongitude, maxLatitude, and maxLongitude to specify the latitude and longitude ranges.|
| minLongitude | number | No| Minimum longitude.|
| maxLatitude | number | No| Maximum latitude.|
| maxLongitude | number | No| Maximum longitude.|


## GeoAddress

Defines a geographic location.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| latitude<sup>7+</sup> | number | No| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude.|
| longitude<sup>7+</sup> | number | No| Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude .|
| locale<sup>7+</sup> | string | No| Language used for the location description. **zh** indicates Chinese, and **en** indicates English.|
| placeName<sup>7+</sup> | string | No| Landmark of the location.|
| countryCode<sup>7+</sup> | string | No| Country code.|
| countryName<sup>7+</sup> | string | No| Country name.|
| administrativeArea<sup>7+</sup> | string | No| Administrative region name.|
| subAdministrativeArea<sup>7+</sup> | string | No| Sub-administrative region name.|
| locality<sup>7+</sup> | string | No| Locality information. |
| subLocality<sup>7+</sup> | string | No| Sub-locality information. |
| roadName<sup>7+</sup> | string | No| Road name.|
| subRoadName<sup>7+</sup> | string | No| Auxiliary road information.|
| premises<sup>7+</sup> | string | No| House information.|
| postalCode<sup>7+</sup> | string | No| Postal code.|
| phoneNumber<sup>7+</sup> | string | No| Phone number.|
| addressUrl<sup>7+</sup> | string | No| Website URL.|
| descriptions<sup>7+</sup> | Array&lt;string&gt; | No| Additional description.|
| descriptionsSize<sup>7+</sup> | number | No| Total number of additional descriptions.|


## LocationRequest

Defines a location request.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | No| Priority of the location request.|
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes| Scenario of the location request.|
| timeInterval | number | No| Time interval at which location information is reported.|
| distanceInterval | number | No| Distance interval at which location information is reported.|
| maxAccuracy | number | No| Location accuracy.|


## CurrentLocationRequest

Defines the current location request.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | No| Priority of the location request.|
| scenario | [LocationRequestScenario](#locationrequestscenario) | No| Scenario of the location request.|
| maxAccuracy | number | No| Location accuracy, in meters.|
| timeoutMs | number | No| Timeout duration, in milliseconds. The minimum value is 1000.|


## SatelliteStatusInfo<sup>8+</sup>

Defines the satellite status information.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| satellitesNumber | number | Yes| Number of satellites.|
| satelliteIds | Array&lt;number&gt; | Yes| Array of satellite IDs.|
| carrierToNoiseDensitys | Array&lt;number&gt; | Yes| Carrier-to-noise density ratio, that is, **cn0**.|
| altitudes | Array&lt;number&gt; | Yes| Altitude information.|
| azimuths | Array&lt;number&gt; | Yes| Azimuth information.|
| carrierFrequencies | Array&lt;number&gt; | Yes| Carrier frequency.|


## CachedGnssLocationsRequest<sup>8+</sup>

Represents a request for reporting cached GNSS locations.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reportingPeriodSec | number | Yes| Interval for reporting the cached GNSS locations, in milliseconds.|
| wakeUpCacheQueueFull | boolean | Yes| **true**: reports the cached GNSS locations to the application when the cache queue is full.<br>**false**: discards the cached GNSS locations when the cache queue is full.|


## Geofence<sup>8+</sup>

Defines a GNSS geofence. Currently, only circular geofences are supported.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| latitude | number | Yes| Latitude information.|
| longitude | number | Yes| Longitude information.|
| radius | number | Yes| Radius of a circular geofence.|
| expiration | number | Yes| Expiration period of a geofence, in milliseconds.|


## GeofenceRequest<sup>8+</sup>

Represents a GNSS geofencing request.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geofence

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| priority | LocationRequestPriority | Yes| Priority of the location information.|
| scenario | LocationRequestScenario | Yes| Location scenario.|
| geofence | Geofence | Yes| Geofence information.|


## LocationPrivacyType<sup>8+</sup>

Defines the privacy statement type.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

| Name| Default Value| Description|
| -------- | -------- | -------- |
| OTHERS | 0 | Other scenarios.|
| STARTUP | 1 | Privacy statement displayed in the startup wizard.|
| CORE_LOCATION | 2 | Privacy statement displayed when enabling the location service.|


## LocationCommand<sup>8+</sup>

Defines an extended command.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| scenario | LocationRequestScenario | Yes| Location scenario.|
| command | string | Yes| Extended command, in the string format.|


## Location

Defines a location.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| latitude<sup>7+</sup> | number | Yes| Latitude information. A positive value indicates north latitude, and a negative value indicates south latitude.|
| longitude<sup>7+</sup> | number | Yes| Longitude information. A positive value indicates east longitude , and a negative value indicates west longitude .|
| altitude<sup>7+</sup> | number | Yes| Location altitude, in meters.|
| accuracy<sup>7+</sup> | number | Yes| Location accuracy, in meters.|
| speed<sup>7+</sup> | number | Yes| Speed, in m/s.|
| timeStamp<sup>7+</sup> | number | Yes| Location timestamp in the UTC format.|
| direction<sup>7+</sup> | number | Yes| Direction information.|
| timeSinceBoot<sup>7+</sup> | number | Yes| Location timestamp since boot.|
| additions<sup>7+</sup> | Array&lt;string&gt; | No| Additional information.|
| additionSize<sup>7+</sup> | number | No| Number of additional descriptions.|
