# Geolocation

Location services provide basic functions such as GNSS positioning, network positioning, geocoding, reverse geocoding, country code and geofencing.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import geolocation from '@ohos.geolocation';
```

## geolocation.on('locationChange')

on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;) : void

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
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  geolocation.on('locationChange', requestInfo, locationChange);
  ```


## geolocation.off('locationChange')

off(type: 'locationChange', callback?: Callback&lt;Location&gt;) : void

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
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  geolocation.on('locationChange', requestInfo, locationChange);
  geolocation.off('locationChange', locationChange);
  ```


## geolocation.on('locationServiceState')

on(type: 'locationServiceState', callback: Callback&lt;boolean&gt;) : void

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
  var locationServiceState = (state) => {
      console.log('locationServiceState: ' + JSON.stringify(state));
  }
  geolocation.on('locationServiceState', locationServiceState);
  ```


## geolocation.off('locationServiceState')

off(type: 'locationServiceState', callback?: Callback&lt;boolean&gt;) : void;

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
  var locationServiceState = (state) => {
      console.log('locationServiceState: state: ' + JSON.stringify(state));
  }
  geolocation.on('locationServiceState', locationServiceState);
  geolocation.off('locationServiceState', locationServiceState);
  ```


## geolocation.on('cachedGnssLocationsReporting')<sup>8+</sup>

on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;) : void;

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
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsReporting: locations: ' + JSON.stringify(locations));
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  geolocation.on('cachedGnssLocationsReporting', requestInfo, cachedLocationsCb);
  ```


## geolocation.off('cachedGnssLocationsReporting')<sup>8+</sup>

off(type: 'cachedGnssLocationsReporting', callback?: Callback&lt;Array&lt;Location&gt;&gt;) : void;

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
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsReporting: locations: ' + JSON.stringify(locations));
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  geolocation.on('cachedGnssLocationsReporting', requestInfo, cachedLocationsCb);
  geolocation.off('cachedGnssLocationsReporting');
  ```


## geolocation.on('gnssStatusChange')<sup>8+</sup>

on(type: 'gnssStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;) : void;

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
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('gnssStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  geolocation.on('gnssStatusChange', gnssStatusCb);
  ```


## geolocation.off('gnssStatusChange')<sup>8+</sup>

off(type: 'gnssStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;) : void;

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
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('gnssStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  geolocation.on('gnssStatusChange', gnssStatusCb);
  geolocation.off('gnssStatusChange', gnssStatusCb);
  ```


## geolocation.on('nmeaMessageChange')<sup>8+</sup>

on(type: 'nmeaMessageChange', callback: Callback&lt;string&gt;) : void;

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
  var nmeaCb = (str) => {
      console.log('nmeaMessageChange: ' + JSON.stringify(str));
  }
  geolocation.on('nmeaMessageChange', nmeaCb );
  ```


## geolocation.off('nmeaMessageChange')<sup>8+</sup>

off(type: 'nmeaMessageChange', callback?: Callback&lt;string&gt;) : void;

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
  var nmeaCb = (str) => {
      console.log('nmeaMessageChange: ' + JSON.stringify(str));
  }
  geolocation.on('nmeaMessageChange', nmeaCb);
  geolocation.off('nmeaMessageChange', nmeaCb);
  ```


## geolocation.on('fenceStatusChange')<sup>8+</sup>

on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void;

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
              abilityName: "com.example.myapplication.MainAbility"
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
  });
  ```


## geolocation.off('fenceStatusChange')<sup>8+</sup>

off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void;

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
              abilityName: "com.example.myapplication.MainAbility"
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


## geolocation.on('countryCodeChange')<sup>9+</sup>

on(type: 'countryCodeChange', callback: Callback&lt;CountryCode&gt;) : void;

Subscribe to country code information reporting events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is "countrycodechange", which means subscribing to the submission of country code information. |
  | callback | Callback&lt;CountryCode&gt; | Yes | Callback is used to receive the country code information report. |


**Example**
  
  ```js
  var callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }
  geolocation.on('countryCodeChange', callback);
  ```


## geolocation.off('countryCodeChange')<sup>9+</sup>

off(type: 'countryCodeChange', callback?: Callback&lt;CountryCode&gt;) : void;

Unsubscribe from the country code to report events.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type. The value is "countrycodechange", which means unsubscribing to the submission of country code information. |
  | callback | Callback&lt;CountryCode&gt; | Yes | Callback is used to receive the country code information report. |


**Example**
  
  ```js
  var callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }
  geolocation.on('countryCodeChange', callback);
  geolocation.off('countryCodeChange', callback);
  ```


## geolocation.getCurrentLocation

getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;) : void


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

getCurrentLocation(request?: CurrentLocationRequest) : Promise&lt;Location&gt;


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
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  geolocation.getCurrentLocation(requestInfo).then((result) => {
      console.log('current location: ' + JSON.stringify(result));
  });
  ```


## geolocation.getLastLocation

getLastLocation(callback: AsyncCallback&lt;Location&gt;) : void

Obtains the previous location. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes| Callback used to return the previous location.|


**Example**
  
  ```js
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

getLastLocation() : Promise&lt;Location&gt;

Obtains the previous location. This API uses a promise to return the result. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | Promise used to return the previous location.|


**Example**
  
  ```js
  geolocation.getLastLocation().then((result) => {
      console.log('getLastLocation: result: ' + JSON.stringify(result));
  });
  ```


## geolocation.isLocationEnabled

isLocationEnabled(callback: AsyncCallback&lt;boolean&gt;) : void


Checks whether the location service is enabled. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the location service status.|

**Example**
  
  ```js
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

isLocationEnabled() : Promise&lt;boolean&gt;

Checks whether the location service is enabled. This API uses a promise to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the location service status.|

**Example**
  
  ```js
  geolocation.isLocationEnabled().then((result) => {
      console.log('promise, isLocationEnabled: ' + result);
  });
  ```


## geolocation.requestEnableLocation

requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;) : void


Requests to enable the location service. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the location service status.|

**Example**
  
  ```js
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

requestEnableLocation() : Promise&lt;boolean&gt;

Requests to enable the location service. This API uses a promise to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the location service status.|

**Example**
  
  ```js
  geolocation.requestEnableLocation().then((result) => {
      console.log('promise, requestEnableLocation: ' + JSON.stringify(result));
  });
  ```


## geolocation.enableLocation

enableLocation(callback: AsyncCallback&lt;boolean&gt;) : void;

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

enableLocation() : Promise&lt;boolean&gt;

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
  geolocation.enableLocation().then((result) => {
      console.log('promise, enableLocation: ' + JSON.stringify(result));
  });
  ```

## geolocation.disableLocation

disableLocation(callback: AsyncCallback&lt;boolean&gt;) : void;

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

disableLocation() : Promise&lt;boolean&gt;

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
  geolocation.disableLocation().then((result) => {
      console.log('promise, disableLocation: ' + JSON.stringify(result));
  });
  ```

## geolocation.isGeoServiceAvailable

isGeoServiceAvailable(callback: AsyncCallback&lt;boolean&gt;) : void

Checks whether the (reverse) geocoding service is available. This API uses an asynchronous callback to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the (reverse) geocoding service status.|

**Example**
  
  ```js
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

isGeoServiceAvailable() : Promise&lt;boolean&gt;

Checks whether the (reverse) geocoding service is available. This API uses a promise to return the result.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Geocoder

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the (reverse) geocoding service status.|

**Example**
  
  ```js
  geolocation.isGeoServiceAvailable().then((result) => {
      console.log('promise, isGeoServiceAvailable: ' + JSON.stringify(result));
  });
  ```


## geolocation.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;) : void

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

getAddressesFromLocation(request: ReverseGeoCodeRequest) : Promise&lt;Array&lt;GeoAddress&gt;&gt;;

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
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  geolocation.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {
      console.log('getAddressesFromLocation: ' + JSON.stringify(data));
  });
  ```


## geolocation.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;) : void

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

getAddressesFromLocationName(request: GeoCodeRequest) : Promise&lt;Array&lt;GeoAddress&gt;&gt;

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
  var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  geolocation.getAddressesFromLocationName(geocodeRequest).then((result) => {
      console.log('getAddressesFromLocationName: ' + JSON.stringify(result));
  });
  ```


## geolocation.getCachedGnssLocationsSize<sup>8+</sup>

getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;) : void;

Obtains the number of cached GNSS locations. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the number of cached GNSS locations. |

**Example**
  
  ```js
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

getCachedGnssLocationsSize() : Promise&lt;number&gt;;

Obtains the number of cached GNSS locations. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the number of cached GNSS locations.|

**Example**
  
  ```js
  geolocation.getCachedGnssLocationsSize().then((result) => {
      console.log('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));
  });
  ```


## geolocation.flushCachedGnssLocations<sup>8+</sup>

flushCachedGnssLocations(callback: AsyncCallback&lt;boolean&gt;) : void;

Obtains all cached GNSS locations and clears the GNSS cache queue. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the operation result.|

**Example**
  
  ```js
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

flushCachedGnssLocations() : Promise&lt;boolean&gt;;

Obtains all cached GNSS locations and clears the GNSS cache queue. 

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Gnss

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise used to return the operation result.|

**Example**
  
  ```js
  geolocation.flushCachedGnssLocations().then((result) => {
      console.log('promise, flushCachedGnssLocations: ' + JSON.stringify(result));
  });
  ```


## geolocation.sendCommand<sup>8+</sup>

sendCommand(command: LocationCommand, callback: AsyncCallback&lt;boolean&gt;) : void;

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

sendCommand(command: LocationCommand) : Promise&lt;boolean&gt;;

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
  var requestInfo = {'scenario': 0x301, 'command': "command_1"};
  geolocation.sendCommand(requestInfo).then((result) => {
      console.log('promise, sendCommand: ' + JSON.stringify(result));
  });
  ```


## geolocation.isLocationPrivacyConfirmed<sup>8+</sup>

isLocationPrivacyConfirmed(type : LocationPrivacyType, callback: AsyncCallback&lt;boolean&gt;) : void;

Checks whether a user agrees with the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | LocationPrivacyType | Yes| Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when enabling the location service.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result, which indicates whether the user agrees with the privacy statement.|

**Example**
  
  ```js
  geolocation.isLocationPrivacyConfirmed(1, (err, result) => {
      if (err) {
          console.log('isLocationPrivacyConfirmed: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('isLocationPrivacyConfirmed: result=' + JSON.stringify(result));
      }
  });
  ```


## geolocation.isLocationPrivacyConfirmed<sup>8+</sup>

isLocationPrivacyConfirmed(type : LocationPrivacyType,) : Promise&lt;boolean&gt;;

Checks whether a user agrees with the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | LocationPrivacyType | Yes| Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when enabling the location service.|

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Callback used to return the result, which indicates whether the user agrees with the privacy statement.|

**Example**
  
  ```js
  geolocation.isLocationPrivacyConfirmed(1).then((result) => {
      console.log('promise, isLocationPrivacyConfirmed: ' + JSON.stringify(result));
  });
  ```


## geolocation.setLocationPrivacyConfirmStatus<sup>8+</sup>

setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed: boolean, callback: AsyncCallback&lt;boolean&gt;) : void;

Sets the user confirmation status for the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | LocationPrivacyType | Yes| Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when enabling the location service.|
  | isConfirmed | boolean | Yes| Callback used to return the result, which indicates whether the user agrees with the privacy statement.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the operation result.|

**Example**
  
  ```js
  geolocation.setLocationPrivacyConfirmStatus(1, true, (err, result) => {
      if (err) {
          console.log('setLocationPrivacyConfirmStatus: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('setLocationPrivacyConfirmStatus: result=' + JSON.stringify(result));
      }
  });
  ```


## geolocation.setLocationPrivacyConfirmStatus<sup>8+</sup>

setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean) : Promise&lt;boolean&gt;;

Sets the user confirmation status for the privacy statement of the location service. This API can only be called by system applications.

**System API**: This is a system API and cannot be called by third-party applications.

**Permission required**: ohos.permission.LOCATION

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | type | LocationPrivacyType | Yes| Privacy statement type, for example, privacy statement displayed in the startup wizard or privacy statement displayed when enabling the location service.|
  | isConfirmed | boolean | Yes| Callback used to return the result, which indicates whether the user agrees with the privacy statement.|

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Callback used to return the operation result.|

**Example**
  
  ```js
  geolocation.setLocationPrivacyConfirmStatus(1, true).then((result) => {
      console.log('promise, setLocationPrivacyConfirmStatus: ' + JSON.stringify(result));
  });
  ```


## geolocation.getCountryCode<sup>9+</sup>

getCountryCode(callback: AsyncCallback&lt;CountryCode&gt;) : void;

Query the current country code.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;CountryCode&gt; | Yes | Callback is used to receive the country code. |

**Example**: 
  
  ```js
  geolocation.getCountryCode((err, result) => {
      if (err) {
          console.log('getCountryCode: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('getCountryCode: result=' + JSON.stringify(result));
      }
  });
  ```


## geolocation.getCountryCode<sup>9+</sup>

getCountryCode() : Promise&lt;CountryCode&gt;;

Query the current country code.

**System capability**: SystemCapability.Location.Location.Core

**Parameters**

None

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;CountryCode&gt; | return country code. |

**Example**:
  
  ```js
  geolocation.getCountryCode()
  .then((result) => {
      console.log('promise, getCountryCode: result=' + JSON.stringify(result));
  })
  .catch((error) => {
      console.log('promise, getCountryCode: error=' + JSON.stringify(error));
  });
  ```


## geolocation.enableLocationMock<sup>9+</sup>

enableLocationMock(scenario?: LocationRequestScenario, callback: AsyncCallback&lt;void&gt;) : void;

Enable the position simulation function of a scene, and only one scene can be enabled at the same time.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | scenario | LocationRequestScenario | No | Indicates under what scenario the position simulation function is enabled. |
  | callback | AsyncCallback&lt;void&gt; | Yes | It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message. |

**Example**: 
  
  ```js
  var request = {"scenario": 0x0301};
  geolocation.enableLocationMock(request, (err, result) => {
      if (err) {
          console.log('enableLocationMock: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('enableLocationMock: result=' + JSON.stringify(result));
      }
  });
  ```

## geolocation.enableLocationMock<sup>9+</sup>

enableLocationMock(scenario?: LocationRequestScenario) : Promise&lt;void&gt;;

Enable the position simulation function of a scene, and only one scene can be enabled at the same time.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | scenario | LocationRequestScenario | No | Indicates which scene's position simulation function is enabled. If this parameter is not carried, it means that the position simulation function of all scenes is enabled. |


**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message.  |

**Example**: 
  
  ```js
  var request = {"scenario": 0x0301};
  geolocation.enableLocationMock(request)
  .then((result) => {
      if (result) {
        console.log('promise, enableLocationMock: result=' + JSON.stringify(result));
      }
  })
  .catch((error) => {
      if (error) {
        console.log('promise, enableLocationMock: error=' + JSON.stringify(error));
      }
  });
  ```


## geolocation.disableLocationMock<sup>9+</sup>

disableLocationMock(scenario?: LocationRequestScenario, callback: AsyncCallback&lt;void&gt;) : void;

To disable the position simulation function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | scenario | LocationRequestScenario | No | Indicates to disable the position simulation function of a scene. If this parameter is not carried, it means to disable the position simulation function of all scenes. |
  | callback | AsyncCallback&lt;void&gt; | Yes | It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message. |

**Example**: 
  
  ```js
  var request = {"scenario": 0x0301};
  geolocation.disableLocationMock(request, (err, result) => {
      if (err) {
          console.log('disableLocationMock: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('disableLocationMock: result=' + JSON.stringify(result));
      }
  });
  ```


## geolocation.disableLocationMock<sup>9+</sup>

disableLocationMock(scenario?: LocationRequestScenario) : Promise&lt;void&gt;;

To disable the position simulation function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | scenario | LocationRequestScenario | No | Indicates to disable the position simulation function of a scene. If this parameter is not carried, it means to disable the position simulation function of all scenes. |

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | It is used to receive the execution result. If the execution is successful, it will return nullptr, otherwise it will return an error message |

**Example**: 
  
  ```js
  var request = {"scenario": 0x0301};
  geolocation.disableLocationMock(request)
  .then((result) => {
      if (result) {
        console.log('promise, disableLocationMock: result=' + JSON.stringify(result));
      }
  })
  .catch((error) => {
      if (error) {
        console.log('promise, disableLocationMock: error=' + JSON.stringify(error));
      }
  });
  ```


## geolocation.setMockedLocations<sup>9+</sup>

setMockedLocations(config: LocationMockConfig, callback: AsyncCallback&lt;void&gt;) : void;

Set the simulated location information, and then report the simulated location at the time interval carried in the interface.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | config | LocationMockConfig | Yes | Indicates the configuration parameters of location simulation, including the time interval of simulation location reporting and the array of simulation locations. |
  | callback | AsyncCallback&lt;void&gt; | Yes | It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message. |

**Example**: 
  
  ```js
  var locations = [
      {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}
  ];
  var config = {"timeInterval": 5, "locations": locations};
  geolocation.setMockedLocations(config, (err, data) => {
      if (err) {
          console.log('setMockedLocations: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('setMockedLocations: data=' + JSON.stringify(data));
      }
  });
  ```

## geolocation.setMockedLocations<sup>9+</sup>

setMockedLocations(config: LocationMockConfig) : Promise&lt;void&gt;;

Set the simulated location information, and then report the simulated location at the time interval carried in the interface.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | config | LocationMockConfig | Yes | Indicates the configuration parameters of location simulation, including the time interval of simulation location reporting and the array of simulation locations. |

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message.  |

**Example**: 
  
  ```js
  var locations = [
      {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}
  ];
  var config = {"timeInterval": 5, "locations":locations};
  geolocation.setMockedLocations(config)
  .then((result) => {
      if (result) {
        console.log('promise, setMockedLocations: result=' + JSON.stringify(result));
      }
  })
  .catch((error) => {
      if (error) {
        console.log('promise, setMockedLocations: error=' + JSON.stringify(error));
      }
  });
  ```



## geolocation.enableReverseGeocodingMock<sup>9+</sup>

enableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;) : void;

Enable reverse geocoding simulation function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes | It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message. |

**Example**: 
  
  ```js
  geolocation.enableReverseGeocodingMock((err, data) => {
      if (err) {
          console.log('enableReverseGeocodingMock: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('enableReverseGeocodingMock: data=' + JSON.stringify(data));
      }
  });
  ```


## geolocation.enableReverseGeocodingMock<sup>9+</sup>

enableReverseGeocodingMock() : Promise&lt;void&gt;;

Enable reverse geocoding simulation function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**: 

None

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message. |

**Example**: 
  
  ```js
  geolocation.enableReverseGeocodingMock()
  .then((result) => {
      if (result) {
        console.log('promise, enableReverseGeocodingMock: result=' + JSON.stringify(result));
      }
  })
  .catch((error) => {
      if (error) {
        console.log('promise, enableReverseGeocodingMock: error=' + JSON.stringify(error));
      }
  });
  ```


## geolocation.disableReverseGeocodingMock<sup>9+</sup>

disableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;) : void;

Disable reverse geocoding simulation function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**:

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | Yes | It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message |

**Example**: 
  
  ```js
  geolocation.disableReverseGeocodingMock((err, result) => {
      if (err) {
          console.log('disableReverseGeocodingMock: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('disableReverseGeocodingMock: result=' + JSON.stringify(result));
      }
  });
  ```


## geolocation.disableReverseGeocodingMock<sup>9+</sup>

disableReverseGeocodingMock() : Promise&lt;void&gt;;

Disable reverse geocoding simulation function.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**: 

None

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; |  It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message. |

**Example**: 
  
  ```js
  geolocation.disableReverseGeocodingMock()
  .then((result) => {
      if (result) {
        console.log('promise, disableReverseGeocodingMock: result=' + JSON.stringify(result));
      }
  })
  .catch((error) => {
      if (error) {
        console.log('promise, disableReverseGeocodingMock: error=' + JSON.stringify(error));
      }
  });
  ```


## geolocation.setReverseGeocodingMockInfo<sup>9+</sup>

setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;, callback: AsyncCallback&lt;void&gt;) : void;

Set the configuration information of the reverse geocoding simulation function, including the corresponding relationship between location and place name. If the location information is in the configuration information during the subsequent reverse geocoding query, the corresponding place name will be returned.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | mockInfos | Array&lt;ReverseGeocodingMockInfo&gt; | Yes | An array of configuration parameters indicating the inverse geocoding simulation function. The configuration parameters of the inverse geocoding simulation function include a location and a place name. |
  | callback | AsyncCallback&lt;void&gt; | Yes | It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message. |

**Example**: 
  
  ```js
  var mockInfos = [
      {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1, "isFromMock": true}},
  ];
  geolocation.setReverseGeocodingMockInfo(mockInfos, (err, data) => {
      if (err) {
          console.log('promise, setReverseGeocodingMockInfo, err:' + JSON.stringify(err));
      } 
      if (data) {
          console.log('promise, setReverseGeocodingMockInfo, data:' + JSON.stringify(data));
      }
  });
  ```


## geolocation.setReverseGeocodingMockInfo<sup>9+</sup>

setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;) : Promise&lt;void&gt;;

Set the configuration information of the reverse geocoding simulation function, including the corresponding relationship between location and place name. If the location information is in the configuration information during the subsequent reverse geocoding query, the corresponding place name will be returned.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | mockInfos | Array&lt;ReverseGeocodingMockInfo&gt; | Yes | An array of configuration parameters indicating the inverse geocoding simulation function. The configuration parameters of the inverse geocoding simulation function include a location and a place name. |

**Return value**

  | Name| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; |  It is used to receive the execution result. If the execution is successful, it will return nullptr. Otherwise, it will return an error message. |

**Example**: 
  
  ```js
  var mockInfos = [
      {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1, "isFromMock": true}},
  ];
  geolocation.setReverseGeocodingMockInfo(mockInfos)
  .then((result) => {
      if (result) {
        console.log('promise, setReverseGeocodingMockInfo: result=' + JSON.stringify(result));
      }
  })
  .catch((error) => {
      if (error) {
        console.log('promise, setReverseGeocodingMockInfo: error=' + JSON.stringify(error));
      }
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
| NOT_SUPPORTED<sup>9+</sup> | 100 | Indicates that the interface function is not supported. |
| INPUT_PARAMS_ERROR<sup>7+</sup> | 101 | Incorrect input parameters.|
| REVERSE_GEOCODE_ERROR<sup>7+</sup> | 102 | Failed to call the reverse geocoding API.|
| GEOCODE_ERROR<sup>7+</sup> | 103 | Failed to call the geocoding API.|
| LOCATOR_ERROR<sup>7+</sup> | 104 | Failed to obtain the location.|
| LOCATION_SWITCH_ERROR<sup>7+</sup> | 105 | Failed to change the location service switch.|
| LAST_KNOWN_LOCATION_ERROR<sup>7+</sup> | 106 | Failed to obtain the previous location.|
| LOCATION_REQUEST_TIMEOUT_ERROR<sup>7+</sup> | 107 | Failed to obtain the location within the specified time.|
| QUERY_COUNTRY_CODE_ERROR<sup>9+</sup> | 108 | Indicates that the country code query failed. |


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
| isFromMock<sup>9+</sup> | Boolean | No | Indicates whether the geographical name information comes from the reverse geocoding simulation function. |


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
| isFromMock<sup>9+</sup> | Boolean | No | Indicates whether the location information comes from the location simulation function. |


## ReverseGeocodingMockInfo<sup>9+</sup>

The configuration information of the reverse geocoding simulation function includes a location information and a place name information.

**System capability**:SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| location | ReverseGeoCodeRequest | Yes | Indicates longitude and latitude information. |
| geoAddress | GeoAddress | Yes | Represents a geographic location. |


## LocationMockConfig<sup>9+</sup>

The configuration parameters of the location simulation function include the time interval of the simulation position report and the array of simulation locations.

**System capability**: SystemCapability.Location.Location.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| timeInterval | number | Yes | Indicates the time interval of analog location reporting, in seconds. |
| locations | Array&lt;Location&gt; | Yes | Represents an array of mocked locations. |


## CountryCode<sup>9+</sup>

The country code information structure contains the country code string and the source information of the country code.

**System capability**: SystemCapability.Location.Location.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| country | string | Yes | Represents the country code string. |
| type | CountryCodeType | Yes | Indicates the source of country code information. |


## CountryCodeType<sup>9+</sup>

Country code source type.

**System capability**: SystemCapability.Location.Location.Core

| Name| Default Value| Description|
| -------- | -------- | -------- |
| COUNTRY_CODE_FROM_LOCALE | 1 | The country code obtained from the language configuration information of the globalization module. |
| COUNTRY_CODE_FROM_SIM | 2 | The country code obtained from the SIM card. |
| COUNTRY_CODE_FROM_LOCATION | 3 | Based on the user's location information, the country code is queried through reverse geocoding. |
| COUNTRY_CODE_FROM_NETWORK | 4 | The country code obtained from the cellular network registration information. |