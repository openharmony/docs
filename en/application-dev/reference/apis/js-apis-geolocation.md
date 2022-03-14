# Geolocation - New


> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import geolocation from '@ohos.geolocation';
```


## Required Permissions

ohos.permission.LOCATION

ohos.permission.LOCATION_IN_BACKGROUND


## geolocation.on('locationChange')

on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;) : void

Registers a listener for location changes with a location request initiated.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**locationChange**&nbsp;indicates&nbsp;a&nbsp;location&nbsp;change&nbsp;event. | 
  | request | LocationRequest | Yes | Location&nbsp;request. | 
  | callback | Callback&lt;[Location](#location)&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;location&nbsp;change&nbsp;event. | 

- Example
  
  ```
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  geolocation.on('locationChange', requestInfo, locationChange);
  ```


## geolocation.off('locationChange')

off(type: 'locationChange', callback?: Callback&lt;Location&gt;) : void

Unregisters the listener for location changes with the corresponding location request deleted.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**locationChange**&nbsp;indicates&nbsp;a&nbsp;location&nbsp;change&nbsp;event. | 
  | callback | Callback&lt;[Location](#location)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;location&nbsp;change&nbsp;event. | 

- Example
  
  ```
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

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**locationServiceState**&nbsp;indicates&nbsp;a&nbsp;location&nbsp;service&nbsp;status&nbsp;change&nbsp;event. | 
  | callback | Callback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;location&nbsp;service&nbsp;status&nbsp;change&nbsp;event. | 

- Example
  
  ```
  var locationServiceState = (state) => {
      console.log('locationServiceState: ' + state);
  }
  geolocation.on('locationServiceState', locationServiceState);
  ```


## geolocation.off('locationServiceState')

off(type: 'locationServiceState', callback?: Callback&lt;boolean&gt;) : void;

Unregisters the listener for location service status change events.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**locationServiceState**&nbsp;indicates&nbsp;a&nbsp;location&nbsp;service&nbsp;status&nbsp;change&nbsp;event. | 
  | callback | Callback&lt;boolean&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;location&nbsp;service&nbsp;status&nbsp;change&nbsp;event. | 

- Example
  
  ```
  var locationServiceState = (state) => {
      console.log('locationServiceState: state: ' + state);
  }
  geolocation.on('locationServiceState', locationServiceState);
  geolocation.off('locationServiceState', locationServiceState);
  ```


## geolocation.on('cachedGnssLocationsReporting')

on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;) : void;

Registers a listener for cached GNSS location reports.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**cachedGnssLocationsReporting**&nbsp;indicates&nbsp;reporting&nbsp;of&nbsp;cached&nbsp;GNSS&nbsp;locations. | 
  | request | CachedGnssLocationsRequest | Yes | Request&nbsp;for&nbsp;reporting&nbsp;cached&nbsp;GNSS&nbsp;location. | 
  | callback | Callback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;cached&nbsp;GNSS&nbsp;locations. | 

- Example
  
  ```
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsReporting: locations: ' + locations);
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  geolocation.on('cachedGnssLocationsReporting', requestInfo, cachedLocationsCb);
  ```


## geolocation.off('cachedGnssLocationsReporting')

off(type: 'cachedGnssLocationsReporting', callback?: Callback&lt;Array&lt;Location&gt;&gt;) : void;

Unregisters the listener for cached GNSS location reports.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**cachedGnssLocationsReporting**&nbsp;indicates&nbsp;reporting&nbsp;of&nbsp;cached&nbsp;GNSS&nbsp;locations. | 
  | callback | Callback&lt;boolean&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;cached&nbsp;GNSS&nbsp;locations. | 

- Example
  
  ```
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsReporting: locations: ' + locations);
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  geolocation.on('cachedGnssLocationsReporting', requestInfo, cachedLocationsCb);
  geolocation.off('cachedGnssLocationsReporting');
  ```


## geolocation.on('gnssStatusChange')

on(type: 'gnssStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;) : void;

Registers a listener for GNSS satellite status change events.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**gnssStatusChange**&nbsp;indicates&nbsp;a&nbsp;GNSS&nbsp;satellite&nbsp;status&nbsp;change. | 
  | callback | Callback&lt;SatelliteStatusInfo&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;GNSS&nbsp;satellite&nbsp;status&nbsp;changes. | 

- Example
  
  ```
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('gnssStatusChange: ' + satelliteStatusInfo);
  }
  geolocation.on('gnssStatusChange', gnssStatusCb);
  ```


## geolocation.off('gnssStatusChange')

off(type: 'gnssStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;) : void;

Unregisters the listener for GNSS satellite status change events.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**gnssStatusChange**&nbsp;indicates&nbsp;a&nbsp;GNSS&nbsp;satellite&nbsp;status&nbsp;change. | 
  | callback | Callback&lt;SatelliteStatusInfo&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;GNSS&nbsp;satellite&nbsp;status&nbsp;changes. | 

- Example
  
  ```
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('gnssStatusChange: ' + satelliteStatusInfo);
  }
  geolocation.on('gnssStatusChange', gnssStatusCb);
  geolocation.off('gnssStatusChange', gnssStatusCb);
  ```


## geolocation.on('nmeaMessageChange')

on(type: 'nmeaMessageChange', callback: Callback&lt;string&gt;) : void;

Registers a listener for GNSS NMEA message change events.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**nmeaMessageChange**&nbsp;indicates&nbsp;a&nbsp;GNSS&nbsp;NMEA&nbsp;message&nbsp;change. | 
  | callback | Callback&lt;string&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;GNSS&nbsp;NMEA&nbsp;message&nbsp;changes. | 

- Example
  
  ```
  var nmeaCb = (str) => {
      console.log('nmeaMessageChange: ' + str);
  }
  geolocation.on('nmeaMessageChange', nmeaCb );
  ```


## geolocation.off('nmeaMessageChange')

off(type: 'nmeaMessageChange', callback?: Callback&lt;string&gt;) : void;

Unregisters the listener for GNSS NMEA message change events.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**nmeaMessageChange**&nbsp;indicates&nbsp;a&nbsp;GNSS&nbsp;NMEA&nbsp;message&nbsp;change. | 
  | callback | Callback&lt;string&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;GNSS&nbsp;NMEA&nbsp;message&nbsp;changes. | 

- Example
  
  ```
  var nmeaCb = (str) => {
      console.log('nmeaMessageChange: ' + str);
  }
  geolocation.on('nmeaMessageChange', nmeaCb);
  geolocation.off('nmeaMessageChange', nmeaCb);
  ```


## geolocation.on('fenceStatusChange')

on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void;

Registers a listener for status change events of the specified geofence.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**fenceStatusChange**&nbsp;indicates&nbsp;a&nbsp;geofence&nbsp;status&nbsp;change. | 
  | request | GeofenceRequest | Yes | Geofencing&nbsp;request. | 
  | want | WantAgent | Yes | **WantAgent**&nbsp;used&nbsp;to&nbsp;return&nbsp;geofence&nbsp;(entrance&nbsp;or&nbsp;exit)&nbsp;events. | 

- Example
  
  ```
  import WantAgent from '@ohos.wantAgent';
  import { OperationType, WantAgentFlags } from '@ohos.wantagent';
  // WantAgent object
  var wantAgent;
  // getWantAgent callback
  function getWantAgentCallback(err, data) {
  	console.info("==========================>getWantAgentCallback=======================>");
      if (err.code == 0) {
  	wantAgent = data;
      } else {
          console.info('----getWantAgent failed!----');
      }
  }
  // WantAgentInfo object
  var wantAgentInfo = {
      wants: [
          {
              deviceId: "deviceId",
              bundleName: "com.neu.setResultOnAbilityResultTest1",
              abilityName: "com.example.test.MainAbility",
              action: "action1",
              entities: ["entity1"],
              type: "MIMETYPE",
              uri: "key={true,true,false}",
              parameters:
              {
                  mykey0: 2222,
                  mykey1: [1, 2, 3],
                  mykey2: "[1, 2, 3]",
                  mykey3: "ssssssssssssssssssssssssss",
                  mykey4: [false, true, false],
                  mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                  mykey6: true,
              }
          }
      ],
      operationType: OperationType.START_ABILITIES,
      requestCode: 0,
      wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
  }
  WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)
  var requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
  geolocation.on('fenceStatusChange', requestInfo, wantAgent);
  ```


## geolocation.off('fenceStatusChange')

off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void;

Unregisters the listener for status change events of the specified geofence.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**fenceStatusChange**&nbsp;indicates&nbsp;a&nbsp;geofence&nbsp;status&nbsp;change. | 
  | request | GeofenceRequest | Yes | Geofencing&nbsp;request. | 
  | want | WantAgent | Yes | **WantAgent**&nbsp;used&nbsp;to&nbsp;return&nbsp;geofence&nbsp;(entrance&nbsp;or&nbsp;exit)&nbsp;events. | 

- Example
  
  ```
  import WantAgent from '@ohos.wantAgent';
  import { OperationType, WantAgentFlags } from '@ohos.wantagent';
  // WantAgent object
  var wantAgent;
  // getWantAgent callback
  function getWantAgentCallback(err, data) {
  	console.info("==========================>getWantAgentCallback=======================>");
      if (err.code == 0) {
  	wantAgent = data;
      } else {
          console.info('----getWantAgent failed!----');
      }
  }
  // WantAgentInfo object
  var wantAgentInfo = {
      wants: [
          {
              deviceId: "deviceId",
              bundleName: "com.neu.setResultOnAbilityResultTest1",
              abilityName: "com.example.test.MainAbility",
              action: "action1",
              entities: ["entity1"],
              type: "MIMETYPE",
              uri: "key={true,true,false}",
              parameters:
              {
                  mykey0: 2222,
                  mykey1: [1, 2, 3],
                  mykey2: "[1, 2, 3]",
                  mykey3: "ssssssssssssssssssssssssss",
                  mykey4: [false, true, false],
                  mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                  mykey6: true,
              }
          }
      ],
      operationType: OperationType.START_ABILITIES,
      requestCode: 0,
      wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
  }
  WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)
  var requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
  geolocation.on('fenceStatusChange', requestInfo, wantAgent);
  geolocation.off('fenceStatusChange', requestInfo, wantAgent);
  ```


## geolocation.getCurrentLocation

getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;) : void


Obtains the current location. This method uses an asynchronous callback to return the result.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | No | Location&nbsp;request. | 
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;current&nbsp;location. | 

- Example
  
  ```
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  var locationChange = (err, location) => {
      console.log('locationChanger: ' + err + 'data: ' + location);
  };
  geolocation.getCurrentLocation(requestInfo, locationChange);
  geolocation.getCurrentLocation(locationChange);
  ```


## geolocation.getCurrentLocation

getCurrentLocation(request?: CurrentLocationRequest) : Promise&lt;Location&gt;


Obtains the current location. This method uses a promise to return the result.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | No | Location&nbsp;request. | 

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;current&nbsp;location. | 

- Example
  
  ```
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  locationEventListener.getCurrentLocation(requestInfo).then((result) => {
      console.log('current location: ' + JSON.stringify(result));
  });
  ```


## geolocation.getLastLocation

getLastLocation(callback: AsyncCallback&lt;Location&gt;) : void

Obtains the previous location. This method uses an asynchronous callback to return the result.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;previous&nbsp;location. | 

- Example
  
  ```
  geolocation.getLastLocation((err, data) => {
      console.log('getLastLocation: ' + err + " data: " + JSON.stringify(data));
  });
  ```


## geolocation.getLastLocation

getLastLocation() : Promise&lt;Location&gt;

Obtains the previous location. This method uses a promise to return the result.

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;previous&nbsp;location. | 

- Example
  
  ```
  geolocation.getLastLocation().then((result) => {
      console.log('getLastLocation: result: ' + JSON.stringify(result));
  });
  ```


## geolocation.isLocationEnabled

isLocationEnabled(callback: AsyncCallback&lt;boolean&gt;) : void


Checks whether the location service is enabled. This method uses an asynchronous callback to return the result.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;location&nbsp;service&nbsp;status. | 

- Example
  
  ```
  geolocation.isLocationEnabled((err, data) => {
      console.log('isLocationEnabled: ' + err + " data: " + data);
  });
  ```


## geolocation.isLocationEnabled

isLocationEnabled() : Promise&lt;boolean&gt;

Checks whether the location service is enabled. This method uses a promise to return the result.

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;location&nbsp;service&nbsp;status. | 

- Example
  
  ```
  geolocation.isLocationEnabled().then((result) => {
      console.log('promise, isLocationEnabled: ' + result);
  });
  ```


## geolocation.requestEnableLocation

requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;) : void


Requests to enable the location service. This method uses an asynchronous callback to return the result.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;location&nbsp;service&nbsp;status. | 

- Example
  
  ```
  geolocation.requestEnableLocation((err, data) => {
      console.log('requestEnableLocation: ' + err + " data: " + data);
  });
  ```


## geolocation.requestEnableLocation

requestEnableLocation() : Promise&lt;boolean&gt;

Requests to enable the location service. This method uses a promise to return the result.

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;location&nbsp;service&nbsp;status. | 

- Example
  
  ```
  geolocation.requestEnableLocation().then((result) => {
      console.log('promise, requestEnableLocation: ' + result);
  });
  ```


## geolocation.isGeoServiceAvailable

isGeoServiceAvailable(callback: AsyncCallback&lt;boolean&gt;) : void

Checks whether the (reverse) geocoding service is available. This method uses an asynchronous callback to return the result.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;(reverse)&nbsp;geocoding&nbsp;service&nbsp;status. | 

- Example
  
  ```
  geolocation.isGeoServiceAvailable((err, data) => {
      console.log('isGeoServiceAvailable: ' + err + " data: " + data);
  });
  ```


## geolocation.isGeoServiceAvailable

isGeoServiceAvailable() : Promise&lt;boolean&gt;

Checks whether the (reverse) geocoding service is available. This method uses a promise to return the result.

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;(reverse)&nbsp;geocoding&nbsp;service&nbsp;status. | 

- Example
  
  ```
  geolocation.isGeoServiceAvailable().then((result) => {
      console.log('promise, isGeoServiceAvailable: ' + result);
  });
  ```



## geolocation.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;) : void

Converts coordinates into geographic description through reverse geocoding. This method uses an asynchronous callback to return the result.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes | Reverse&nbsp;geocoding&nbsp;request. | 
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;reverse&nbsp;geocoding&nbsp;result. | 

- Example
  
  ```
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  geolocation.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
      console.log('getAddressesFromLocation: ' + err + " data: " + JSON.stringify(data));
  });
  ```


## geolocation.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest) : Promise&lt;Array&lt;GeoAddress&gt;&gt;;

Converts coordinates into geographic description through reverse geocoding. This method uses a promise to return the result.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | Yes | Reverse&nbsp;geocoding&nbsp;request. | 

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;reverse&nbsp;geocoding&nbsp;result. | 

- Example
  
  ```
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  geolocation.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {
      console.log('getAddressesFromLocation: ' + JSON.stringify(data));
  });
  ```


## geolocation.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;) : void

Converts geographic description into coordinates through geocoding. This method uses an asynchronous callback to return the result.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | Yes | Geocoding&nbsp;request. | 
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;geocoding&nbsp;result. | 

- Example
  
  ```
  var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  geolocation.getAddressesFromLocationName(geocodeRequest, (err, data) => {
      console.log('getAddressesFromLocationName: ' + err + " data: " + JSON.stringify(data));
  });
  ```


## geolocation.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest) : Promise&lt;Array&lt;GeoAddress&gt;&gt;

Converts geographic description into coordinates through geocoding. This method uses a promise to return the result.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | Yes | Geocoding&nbsp;request. | 

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;geocoding&nbsp;result. | 

- Example
  
  ```
  var geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
  geolocation.getAddressesFromLocationName(geocodeRequest).then((result) => {
      console.log('getAddressesFromLocationName: ' + JSON.stringify(result));
  });
  ```



## geolocation.getCachedGnssLocationsSize

getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;) : void;

Obtains the number of cached GNSS locations.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;number&nbsp;of&nbsp;cached&nbsp;GNSS&nbsp;locations. | 

- Example
  
  ```
  geolocation.getCachedGnssLocationsSize((err, size) => {
      console.log('getCachedGnssLocationsSize: err:' + err + " size: " + size);
  });
  ```


## geolocation.getCachedGnssLocationsSize

getCachedGnssLocationsSize() : Promise&lt;number&gt;;

Obtains the number of cached GNSS locations.

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;number&nbsp;of&nbsp;cached&nbsp;GNSS&nbsp;locations. | 

- Example
  
  ```
  geolocation.getCachedGnssLocationsSize().then((result) => {
      console.log('promise, getCachedGnssLocationsSize: ' + result);
  });
  ```


## geolocation.flushCachedGnssLocations

flushCachedGnssLocations(callback: AsyncCallback&lt;boolean&gt;) : void;

Obtains all cached GNSS locations and clears the GNSS cache queue.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;operation&nbsp;result. | 

- Example
  
  ```
  geolocation.flushCachedGnssLocations((err, result) => {
      console.log('flushCachedGnssLocations: err:' + err + " result: " + result);
  });
  ```


## geolocation.flushCachedGnssLocations

flushCachedGnssLocations() : Promise&lt;boolean&gt;;

Obtains all cached GNSS locations and clears the GNSS cache queue.

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;operation&nbsp;result. | 

- Example
  
  ```
  geolocation.flushCachedGnssLocations().then((result) => {
      console.log('promise, flushCachedGnssLocations: ' + result);
  });
  ```


## geolocation.sendCommand

sendCommand(command: LocationCommand, callback: AsyncCallback&lt;boolean&gt;) : void;

Sends an extended command to the location subsystem. This function can only be called by system applications.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | command | LocationCommand | Yes | Extended&nbsp;command&nbsp;(string)&nbsp;to&nbsp;be&nbsp;sent. | 
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;operation&nbsp;result. | 

- Example
  
  ```
  var requestInfo = {'scenario': 0x301, 'command': "command_1"};
  geolocation.sendCommand(requestInfo, (err, result) => {
      console.log('sendCommand: err:' + err + " result: " + result);
  });
  ```


## geolocation.sendCommand

sendCommand(command: LocationCommand) : Promise&lt;boolean&gt;;

Sends extended commands to the location subsystem. This function can only be called by system applications.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | command | LocationCommand | Yes | Extended&nbsp;command&nbsp;(string)&nbsp;to&nbsp;be&nbsp;sent. | 

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;operation&nbsp;result. | 

- Example
  
  ```
  var requestInfo = {'scenario': 0x301, 'command': "command_1"};
  geolocation.sendCommand(requestInfo).then((result) => {
      console.log('promise, sendCommand: ' + result);
  });
  ```


## geolocation.isLocationPrivacyConfirmed

isLocationPrivacyConfirmed(type : LocationPrivacyType, callback: AsyncCallback&lt;boolean&gt;) : void;

Checks whether a user agrees with the privacy statement of the location service. This function can only be called by system applications.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | LocationPrivacyType | Yes | Privacy&nbsp;statement&nbsp;type,&nbsp;for&nbsp;example,&nbsp;privacy&nbsp;statement&nbsp;displayed&nbsp;in&nbsp;the&nbsp;startup&nbsp;wizard&nbsp;or&nbsp;privacy&nbsp;statement&nbsp;displayed&nbsp;when&nbsp;enabling&nbsp;the&nbsp;location&nbsp;service. | 
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result,&nbsp;which&nbsp;indicates&nbsp;whether&nbsp;the&nbsp;user&nbsp;agrees&nbsp;with&nbsp;the&nbsp;privacy&nbsp;statement. | 

- Example
  
  ```
  geolocation.isLocationPrivacyConfirmed(1, (err, result) => {
      console.log('isLocationPrivacyConfirmed: err:' + err + " result: " + result);
  });
  ```


## geolocation.isLocationPrivacyConfirmed

isLocationPrivacyConfirmed(type : LocationPrivacyType,) : Promise&lt;boolean&gt;;

Checks whether a user agrees with the privacy statement of the location service. This function can only be called by system applications.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | LocationPrivacyType | Yes | Privacy&nbsp;statement&nbsp;type,&nbsp;for&nbsp;example,&nbsp;privacy&nbsp;statement&nbsp;displayed&nbsp;in&nbsp;the&nbsp;startup&nbsp;wizard&nbsp;or&nbsp;privacy&nbsp;statement&nbsp;displayed&nbsp;when&nbsp;enabling&nbsp;the&nbsp;location&nbsp;service. | 

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result,&nbsp;which&nbsp;indicates&nbsp;whether&nbsp;the&nbsp;user&nbsp;agrees&nbsp;with&nbsp;the&nbsp;privacy&nbsp;statement. | 

- Example
  
  ```
  geolocation.isLocationPrivacyConfirmed(1).then((result) => {
      console.log('promise, isLocationPrivacyConfirmed: ' + result);
  });
  ```


## geolocation.setLocationPrivacyConfirmStatus

setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed: boolean, callback: AsyncCallback&lt;boolean&gt;) : void;

Sets the user confirmation status for the privacy statement of the location service. This function can only be called by system applications.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | LocationPrivacyType | Yes | Privacy&nbsp;statement&nbsp;type,&nbsp;for&nbsp;example,&nbsp;privacy&nbsp;statement&nbsp;displayed&nbsp;in&nbsp;the&nbsp;startup&nbsp;wizard&nbsp;or&nbsp;privacy&nbsp;statement&nbsp;displayed&nbsp;when&nbsp;enabling&nbsp;the&nbsp;location&nbsp;service. | 
  | isConfirmed | boolean | Yes | Whether&nbsp;the&nbsp;user&nbsp;agrees&nbsp;with&nbsp;the&nbsp;privacy&nbsp;statement&nbsp;of&nbsp;the&nbsp;location&nbsp;service. | 
  | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;operation&nbsp;result. | 

- Example
  
  ```
  geolocation.setLocationPrivacyConfirmStatus(1, true, (err, result) => {
      console.log('isLocationPrivacyConfirmed: err:' + err + " result: " + result);
  });
  ```


## geolocation.setLocationPrivacyConfirmStatus

setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean) : Promise&lt;boolean&gt;;

Sets the user confirmation status for the privacy statement of the location service. This function can only be called by system applications.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | type | LocationPrivacyType | Yes | Privacy&nbsp;statement&nbsp;type,&nbsp;for&nbsp;example,&nbsp;privacy&nbsp;statement&nbsp;displayed&nbsp;in&nbsp;the&nbsp;startup&nbsp;wizard&nbsp;or&nbsp;privacy&nbsp;statement&nbsp;displayed&nbsp;when&nbsp;enabling&nbsp;the&nbsp;location&nbsp;service. | 
  | isConfirmed | boolean | Yes | Whether&nbsp;the&nbsp;user&nbsp;agrees&nbsp;with&nbsp;the&nbsp;privacy&nbsp;statement&nbsp;of&nbsp;the&nbsp;location&nbsp;service. | 

- Return values
    | Name | Description | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;operation&nbsp;result. | 

- Example
  
  ```
  geolocation.setLocationPrivacyConfirmStatus(1, true).then((result) => {
      console.log('promise, setLocationPrivacyConfirmStatus: ' + result);
  });
  ```



## LocationRequestPriority

Sets the priority of the location request.

  | Name | Default&nbsp;Value | Description | 
| -------- | -------- | -------- |
| UNSET | 0x200 | Priority&nbsp;unspecified. | 
| ACCURACY | 0x201 | Location&nbsp;accuracy. | 
| LOW_POWER | 0x202 | Power&nbsp;efficiency. | 
| FIRST_FIX | 0x203 | Fast&nbsp;location.&nbsp;Use&nbsp;this&nbsp;option&nbsp;if&nbsp;you&nbsp;want&nbsp;to&nbsp;obtain&nbsp;a&nbsp;location&nbsp;as&nbsp;fast&nbsp;as&nbsp;possible. | 


## LocationRequestScenario

  Sets the scenario of the location request.
  | Name | Default&nbsp;Value | Description | 
| -------- | -------- | -------- |
| UNSET | 0x300 | Scenario&nbsp;unspecified. | 
| NAVIGATION | 0x301 | Navigation. | 
| TRAJECTORY_TRACKING | 0x302 | Trajectory&nbsp;tracking. | 
| CAR_HAILING | 0x303 | Ride&nbsp;hailing. | 
| DAILY_LIFE_SERVICE | 0x304 | Daily&nbsp;life&nbsp;services. | 
| NO_POWER | 0x305 | Power&nbsp;efficiency.&nbsp;Your&nbsp;application&nbsp;does&nbsp;not&nbsp;proactively&nbsp;start&nbsp;the&nbsp;location&nbsp;service.&nbsp;When&nbsp;responding&nbsp;to&nbsp;another&nbsp;application&nbsp;requesting&nbsp;the&nbsp;same&nbsp;location&nbsp;service,&nbsp;the&nbsp;system&nbsp;marks&nbsp;a&nbsp;copy&nbsp;of&nbsp;the&nbsp;location&nbsp;result&nbsp;to&nbsp;your&nbsp;application.&nbsp;In&nbsp;this&nbsp;way,&nbsp;your&nbsp;application&nbsp;will&nbsp;not&nbsp;consume&nbsp;extra&nbsp;power&nbsp;for&nbsp;obtaining&nbsp;the&nbsp;user&nbsp;location. | 


## GeoLocationErrorCode

Enumerates error codes of the location service.

  | Name | Default&nbsp;Value | Description | 
| -------- | -------- | -------- |
| INPUT_PARAMS_ERROR | 101 | Incorrect&nbsp;input&nbsp;parameters. | 
| REVERSE_GEOCODE_ERROR | 102 | Failed&nbsp;to&nbsp;call&nbsp;the&nbsp;reverse&nbsp;geocoding&nbsp;API. | 
| GEOCODE_ERROR | 103 | Failed&nbsp;to&nbsp;call&nbsp;the&nbsp;geocoding&nbsp;API. | 
| LOCATOR_ERROR | 104 | Failed&nbsp;to&nbsp;obtain&nbsp;the&nbsp;location. | 
| LOCATION_SWITCH_ERROR | 105 | Failed&nbsp;to&nbsp;change&nbsp;the&nbsp;location&nbsp;service&nbsp;switch. | 
| LAST_KNOWN_LOCATION_ERROR | 106 | Failed&nbsp;to&nbsp;obtain&nbsp;the&nbsp;previous&nbsp;location. | 
| LOCATION_REQUEST_TIMEOUT_ERROR | 107 | Failed&nbsp;to&nbsp;obtain&nbsp;the&nbsp;location&nbsp;within&nbsp;the&nbsp;specified&nbsp;time. | 


## ReverseGeoCodeRequest

Defines a reverse geocoding request.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| locale | string | No | Language&nbsp;used&nbsp;for&nbsp;the&nbsp;location&nbsp;description.&nbsp;**zh**&nbsp;indicates&nbsp;Chinese,&nbsp;and&nbsp;**en**&nbsp;indicates&nbsp;English. | 
| latitude | number | Yes | Latitude&nbsp;information.&nbsp;A&nbsp;positive&nbsp;value&nbsp;indicates&nbsp;north&nbsp;latitude,&nbsp;and&nbsp;a&nbsp;negative&nbsp;value&nbsp;indicates&nbsp;south&nbsp;latitude. | 
| longitude | number | Yes | Longitude&nbsp;information.&nbsp;A&nbsp;positive&nbsp;value&nbsp;indicates&nbsp;east&nbsp;longitude&nbsp;,&nbsp;and&nbsp;a&nbsp;negative&nbsp;value&nbsp;indicates&nbsp;west&nbsp;longitude&nbsp;. | 
| maxItems | number | No | Maximum&nbsp;number&nbsp;of&nbsp;location&nbsp;records&nbsp;to&nbsp;be&nbsp;returned. | 


## GeoCodeRequest

Defines a geocoding request.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| locale | string | No | Language&nbsp;used&nbsp;for&nbsp;the&nbsp;location&nbsp;description.&nbsp;**zh**&nbsp;indicates&nbsp;Chinese,&nbsp;and&nbsp;**en**&nbsp;indicates&nbsp;English. | 
| description | number | Yes | Location&nbsp;description,&nbsp;for&nbsp;example,&nbsp;**No.&nbsp;xx,&nbsp;xx&nbsp;Road,&nbsp;Pudong&nbsp;New&nbsp;District,&nbsp;Shanghai**. | 
| maxItems | number | No | Maximum&nbsp;number&nbsp;of&nbsp;location&nbsp;records&nbsp;to&nbsp;be&nbsp;returned. | 
| minLatitude | number | No | Minimum&nbsp;latitude.&nbsp;This&nbsp;parameter&nbsp;is&nbsp;used&nbsp;with&nbsp;**minLongitude**,&nbsp;**maxLatitude**,&nbsp;and&nbsp;**maxLongitude**&nbsp;to&nbsp;specify&nbsp;the&nbsp;latitude&nbsp;and&nbsp;longitude&nbsp;ranges. | 
| minLongitude | number | No | Minimum&nbsp;longitude. | 
| maxLatitude | number | No | Maximum&nbsp;latitude. | 
| maxLongitude | number | No | Maximum&nbsp;longitude. | 


## GeoAddress

Defines a geographic location.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| latitude | number | No | Latitude&nbsp;information.&nbsp;A&nbsp;positive&nbsp;value&nbsp;indicates&nbsp;north&nbsp;latitude,&nbsp;and&nbsp;a&nbsp;negative&nbsp;value&nbsp;indicates&nbsp;south&nbsp;latitude. | 
| longitude | number | No | Longitude&nbsp;information.&nbsp;A&nbsp;positive&nbsp;value&nbsp;indicates&nbsp;east&nbsp;longitude&nbsp;,&nbsp;and&nbsp;a&nbsp;negative&nbsp;value&nbsp;indicates&nbsp;west&nbsp;longitude&nbsp;. | 
| locale | string | No | Language&nbsp;used&nbsp;for&nbsp;the&nbsp;location&nbsp;description.&nbsp;**zh**&nbsp;indicates&nbsp;Chinese,&nbsp;and&nbsp;**en**&nbsp;indicates&nbsp;English. | 
| placeName | string | No | Landmark&nbsp;of&nbsp;the&nbsp;location. | 
| countryCode | string | No | Country&nbsp;code. | 
| countryName | string | No | Country&nbsp;name. | 
| administrativeArea | string | No | Administrative&nbsp;region&nbsp;name. | 
| subAdministrativeArea | string | No | Sub-administrative&nbsp;region&nbsp;name. | 
| locality | string | No | Locality&nbsp;information. | 
| subLocality | string | No | Sub-locality&nbsp;information. | 
| roadName | string | No | Road&nbsp;name. | 
| subRoadName | string | No | Auxiliary&nbsp;road&nbsp;information. | 
| premises | string | No | House&nbsp;information. | 
| postalCode | string | No | Postal&nbsp;code. | 
| phoneNumber | string | No | Phone&nbsp;number. | 
| addressUrl | string | No | Website&nbsp;URL. | 
| descriptions | Array&lt;string&gt; | No | Additional&nbsp;description. | 
| descriptionsSize | number | No | Total&nbsp;number&nbsp;of&nbsp;additional&nbsp;descriptions. | 


## LocationRequest

Defines a location request.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | No | Priority&nbsp;of&nbsp;the&nbsp;location&nbsp;request. | 
| scenario | [LocationRequestScenario](#locationrequestscenario) | Yes | Scenario&nbsp;of&nbsp;the&nbsp;location&nbsp;request. | 
| timeInterval | number | No | Time&nbsp;interval&nbsp;at&nbsp;which&nbsp;location&nbsp;information&nbsp;is&nbsp;reported. | 
| distanceInterval | number | No | Distance&nbsp;interval&nbsp;at&nbsp;which&nbsp;location&nbsp;information&nbsp;is&nbsp;reported. | 
| maxAccuracy | number | No | Location&nbsp;accuracy. | 


## CurrentLocationRequest

Defines the current location request.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | No | Priority&nbsp;of&nbsp;the&nbsp;location&nbsp;request. | 
| scenario | [LocationRequestScenario](#locationrequestscenario) | No | Scenario&nbsp;of&nbsp;the&nbsp;location&nbsp;request. | 
| maxAccuracy | number | No | Location&nbsp;accuracy,&nbsp;in&nbsp;meters. | 
| timeoutMs | number | No | Timeout&nbsp;duration,&nbsp;in&nbsp;milliseconds.&nbsp;The&nbsp;minimum&nbsp;value&nbsp;is&nbsp;**1000**. | 


## SatelliteStatusInfo

Defines the satellite status information.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| satellitesNumber | number | Yes | Number&nbsp;of&nbsp;satellites. | 
| satelliteIds | Array&lt;number&gt; | Yes | Array&nbsp;of&nbsp;satellite&nbsp;IDs. | 
| carrierToNoiseDensitys | Array&lt;number&gt; | Yes | Carrier-to-noise&nbsp;density&nbsp;ratio,&nbsp;that&nbsp;is,&nbsp;cn0. | 
| altitudes | Array&lt;number&gt; | Yes | Altitude&nbsp;information. | 
| azimuths | Array&lt;number&gt; | Yes | Azimuth&nbsp;information. | 
| carrierFrequencies | Array&lt;number&gt; | Yes | Carrier&nbsp;frequency. | 


## CachedGnssLocationsRequest

Represents a request for reporting cached GNSS locations.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| reportingPeriodSec | number | Yes | Interval&nbsp;for&nbsp;reporting&nbsp;the&nbsp;cached&nbsp;GNSS&nbsp;locations,&nbsp;in&nbsp;milliseconds. | 
| wakeUpCacheQueueFull | boolean | Yes | **true**:&nbsp;reports&nbsp;the&nbsp;cached&nbsp;GNSS&nbsp;locations&nbsp;to&nbsp;the&nbsp;application&nbsp;when&nbsp;the&nbsp;cache&nbsp;queue&nbsp;is&nbsp;full.<br/>**false**:&nbsp;discards&nbsp;the&nbsp;cached&nbsp;GNSS&nbsp;locations&nbsp;when&nbsp;the&nbsp;cache&nbsp;queue&nbsp;is&nbsp;full. | 


## Geofence

Defines a GNSS geofence. Currently, only circular geofences are supported.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| latitude | number | Yes | Latitude&nbsp;information. | 
| longitude | number | Yes | Longitude&nbsp;information. | 
| radius | number | Yes | Radius&nbsp;of&nbsp;a&nbsp;circular&nbsp;geofence. | 
| expiration | number | Yes | Expiration&nbsp;period&nbsp;of&nbsp;a&nbsp;geofence,&nbsp;in&nbsp;milliseconds. | 


## GeofenceRequest

Represents a GNSS geofencing request.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| priority | LocationRequestPriority | Yes | Priority&nbsp;of&nbsp;the&nbsp;location&nbsp;information. | 
| scenario | LocationRequestScenario | Yes | Location&nbsp;scenario. | 
| geofence | Geofence | Yes | Geofence&nbsp;information. | 


## LocationPrivacyType

Defines the privacy statement type.

  | Name | Default&nbsp;Value | Description | 
| -------- | -------- | -------- |
| OTHERS | 0 | Other&nbsp;scenarios. | 
| STARTUP | 1 | Privacy&nbsp;statement&nbsp;displayed&nbsp;in&nbsp;the&nbsp;startup&nbsp;wizard. | 
| CORE_LOCATION | 2 | Privacy&nbsp;statement&nbsp;displayed&nbsp;when&nbsp;enabling&nbsp;the&nbsp;location&nbsp;service. | 


## LocationCommand

Defines an extended command.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| scenario | LocationRequestScenario | Yes | Location&nbsp;scenario. | 
| command | string | Yes | Extended&nbsp;command,&nbsp;in&nbsp;the&nbsp;string&nbsp;format. | 


## Location

Defines a location.

  | Name | Type | Mandatory | Description | 
| -------- | -------- | -------- | -------- |
| latitude | number | Yes | Latitude&nbsp;information.&nbsp;A&nbsp;positive&nbsp;value&nbsp;indicates&nbsp;north&nbsp;latitude,&nbsp;and&nbsp;a&nbsp;negative&nbsp;value&nbsp;indicates&nbsp;south&nbsp;latitude. | 
| longitude | number | Yes | Longitude&nbsp;information.&nbsp;A&nbsp;positive&nbsp;value&nbsp;indicates&nbsp;east&nbsp;longitude&nbsp;,&nbsp;and&nbsp;a&nbsp;negative&nbsp;value&nbsp;indicates&nbsp;west&nbsp;longitude&nbsp;. | 
| altitude | number | Yes | Location&nbsp;altitude,&nbsp;in&nbsp;meters. | 
| accuracy | number | Yes | Location&nbsp;accuracy,&nbsp;in&nbsp;meters. | 
| speed | number | Yes | Speed,&nbsp;in&nbsp;m/s. | 
| timeStamp | number | Yes | Location&nbsp;timestamp&nbsp;in&nbsp;the&nbsp;UTC&nbsp;format. | 
| direction | number | Yes | Direction&nbsp;information. | 
| timeSinceBoot | number | Yes | Location&nbsp;timestamp&nbsp;since&nbsp;boot. | 
| additions | Array&lt;string&gt; | No | Additional&nbsp;description. | 
| additionSize | number | No | Number&nbsp;of&nbsp;additional&nbsp;descriptions. | 
