# Location Service Development

## Overview

People take their mobile devices wherever they go. Mobile devices have become a necessity in people's daily routines, whether it be for looking at the weather forecast, browsing news, hailing a taxi, navigating, or recording data from a workout. All these activities are so much associated with the location services on mobile devices.

With the location awareness capability offered by OpenHarmony, mobile devices will be able to obtain real-time, accurate location data. Building location awareness into your application can also lead to a better contextual experience for application users.

Your application can call location-specific APIs to obtain the location information of a mobile device for offering location-based services such as drive navigation and motion track recording.

### Service Introduction

Location awareness helps determine where a mobile device locates. The location subsystem identifies the location of a mobile device with its coordinates, and uses location technologies such as Global Navigation Satellite System (GNSS) and network positioning (for example, base station positioning or WLAN/Bluetooth positioning) to provide diverse location-based services.

These advanced location technologies make it possible to obtain the accurate location of the mobile device, regardless of whether it is indoors or outdoors.

- **Coordinate**

  A coordinate describes a location on the earth using the longitude and latitude in reference to the World Geodetic Coordinate System 1984.

- **GNSS positioning**

  GNSS positioning locates a mobile device by using the location algorithm offered by the device chip to compute the location information provided by the Global Navigation Satellite System, for example, GPS, GLONASS, BeiDou, and Galileo. Whichever positioning system will be used during the location process depends on a hardware capability of the device.

- **Base station positioning**

  Base station positioning estimates the current location of a mobile device based on the location of the resident base station in reference to the neighboring base stations. This technology provides only a low accuracy and requires access to the cellular network.

- **WLAN or Bluetooth positioning**
  
  WLAN or Bluetooth positioning estimates the current location of a mobile device based on the locations of WLANs and Bluetooth devices that can be discovered by the device. The location accuracy of this technology depends on the distribution of fixed WLAN access points (APs) and Bluetooth devices around the device. A high density of WLAN APs and Bluetooth devices can produce a more accurate location result than base station positioning. This technology also requires access to the network.

### Working Principles

Location awareness is offered by the system as a basic service for applications. Depending on the service scenario, an application needs to initiate a location request to the system and stop the location request when the service scenario ends. In this process, the system reports the location information to the application on a real-time basis.

### Constraints

Your application can use the location function only after the user has granted the required permission and turned on the location function. If the location function is off, the system will not provide the location service for any application.

Since the location information is considered sensitive, your application still needs to obtain the location access permission from the user even if the user has turned on the location function. The system will provide the location service for your application only after it has been granted the permission to access the device location information.


## Applying for Location Permissions

### When to Use

Before using system basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user.

The system provides the following location permissions:

- ohos.permission.LOCATION: used to obtain location accurate to meters.

- ohos.permission.APPROXIMATELY\_LOCATION: used to obtain location accurate to 5 kilometers.

- ohos.permission.LOCATION\_IN\_BACKGROUND: used to obtain location while the application is running at the background.

If your application needs to access the device location information, it must first apply for required permissions.

**Table 1** Ways to apply for location permissions

| Target API Level| Location Permission| Permission Application Result| Location Accuracy|
| -------- | -------- | -------- | -------- |
| Earlier than 9| ohos.permission.LOCATION | Successful| Location accurate to meters.|
| 9 and later| ohos.permission.LOCATION | Failed| No location obtained.|
| 9 and later| ohos.permission.APPROXIMATELY_LOCATION | Successful| Location accurate to 5 kilometers.|
| 9 and later| ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION| Successful| Location accurate to meters.|

If your application needs to access the device location information when running in the background, it must be configured to be able to run in the background and be granted the **ohos.permission.LOCATION_IN_BACKGROUND** permission. In this way, the system continues to report device location information after your application moves to the background.

You can declare the required permission in your application's configuration file. For details, see [Access Control (Permission) Development](../security/accesstoken-guidelines.md).

For details about the permissions required for each API of the location service, see [Geolocation Manager](../reference/apis/js-apis-geoLocationManager.md).

### How to Develop

You can declare the required permission in your application's configuration file. For details, see [Access Control (Permission) Development](../security/accesstoken-guidelines.md).


## Obtaining Device Location Information

### When to Use

You can call location-related APIs in OpenHarmony to obtain the real-time location or last known location of a mobile device.

Real-time location of the device is recommended for location-sensitive services. If you want to lower power consumption when the real-time location of the device is not needed, you may consider obtaining the last known location of the device.

### Available APIs

The following table lists the APIs used to obtain the device location information. For details, see [Geolocation Manager](../reference/apis/js-apis-geoLocationManager.md).

**Table 2** APIs for obtaining device location information

| API| Description|
| -------- | -------- |
| on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;): void | Registers a listener for location changes with a location request initiated.|
| off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void | Unregisters the listener for location changes with the corresponding location request deleted.|
| getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;): void | Obtains the current location. This API uses an asynchronous callback to return the result. |
| getCurrentLocation(request?: CurrentLocationRequest): Promise&lt;Location&gt; | Obtains the current location. This API uses a promise to return the result. |
| getLastLocation(): Location | Obtains the last known device location.|

### How to Develop

1. Before using basic location capabilities, check whether your application has been granted the permission to access device location information. If not, your application first needs to apply for the required permission. For details, see [Applying for Location Permissions](#applying-for-location-permissions).

2. Import the **geoLocationManager** module by which you can implement all APIs related to the basic location capabilities.
   
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   ```

3. Instantiate the **LocationRequest** object. This object provides APIs to notify the system of the location service type and the interval of reporting location information.<br>
   **Method 1:**

   To better serve your needs for using APIs, the system has categorized APIs into different packages to match your common use cases of the location function. In this way, you can directly use the APIs specific to a certain use case, making application development much easier. The location service scenarios currently supported are described as follows.

   **Location service scenarios**
   
   - NAVIGATION<br>
   Applicable when your application needs to obtain the real-time location of a mobile device outdoors, such as navigation for driving or walking. <br>In this scenario, the GNSS positioning technology is mainly used to ensure the location accuracy. However, due to its limitations, the technology may be unable to provide the location service when navigation is just started or when the user moves into a shielded environment such as indoors or a garage. <br>To resolve this issue, the system uses the network positioning technology as an alternative to provide the location service for your application until the GNSS can provide stable location results. This helps achieve a smooth navigation experience for users. <br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.
   
   - TRAJECTORY\_TRACKING<br>
   Applicable when your application needs to record user trajectories, for example, the track recording function of sports applications. In this scenario, the GNSS positioning technology is mainly used to ensure the location accuracy. <br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.
   
   - CAR\_HAILING<br>
   Applicable when your application needs to obtain the current location of a user who is hailing a taxi. <br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.
   
   - DAILY\_LIFE\_SERVICE<br>
   Applicable when your application only needs the approximate user location for recommendations and push notifications in scenarios such as when the user is browsing news, shopping online, and ordering food. <br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.
   
   - NO\_POWER<br>
     Applicable when your application does not proactively start the location service for a higher battery efficiency. When responding to another application requesting the same location service, the system marks a copy of the location result to your application. In this way, your application will not consume extra power for obtaining the user location. <br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.
     
     
          ```ts
              export enum LocationRequestScenario {
                   UNSET = 0x300,
                   NAVIGATION,
                   TRAJECTORY_TRACKING,
                   CAR_HAILING,
                   DAILY_LIFE_SERVICE,
                   NO_POWER,
               }
          ```


Sample code for initializing **requestInfo** for navigation:

   ```ts
   let requestInfo = {'scenario': geoLocationManager.LocationRequestScenario.NAVIGATION, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

**Method 2:**

If the predefined use cases do not meet your needs, you can also use the basic location priority policies provided by the system.

   **Location priority policies**

   - ACCURACY<br>
      This policy mainly uses the GNSS positioning technology. In an open area, the technology can achieve the meter-level location accuracy, depending on the hardware performance of the device. However, in a shielded environment, the location accuracy may significantly decrease.

   - FIRST\_FIX<br>
      This policy uses the GNSS positioning, base station positioning, WLAN positioning, and Bluetooth positioning technologies simultaneously to obtain the device location in both the indoor and outdoor scenarios. When all positioning technologies provide a location result, the system provides the most accurate location result for your application. This policy can lead to significant hardware resource consumption and power consumption.

   - LOW\_POWER<br>
      This policy mainly uses the base station positioning, WLAN positioning, and Bluetooth positioning technologies to obtain device location in both indoor and outdoor scenarios. The location accuracy depends on the distribution of surrounding base stations, visible WLANs, and Bluetooth devices and therefore may fluctuate greatly. This policy is recommended and can reduce power consumption when your application does not require high location accuracy or when base stations, visible WLANs, and Bluetooth devices are densely distributed.
      
         ```ts
             export enum LocationRequestPriority {
                  UNSET = 0x200,
                  ACCURACY,
                  LOW_POWER,
                  FIRST_FIX,
              }
         ```

Sample code for initializing **requestInfo** for the location accuracy priority policy:

   ```ts
   let requestInfo = {'priority': geoLocationManager.LocationRequestPriority.ACCURACY, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

4. Instantiate the **Callback** object for the system to report location results.
     Your application needs to implement the callback defined by the system. When the system successfully obtains the real-time location of a device, it will report the location result to your application through the callback interface. Your application can implement the callback interface in such a way to complete your own service logic.
     
   ```ts
   let locationChange = (location) => {
       console.log('locationChanger: data: ' + JSON.stringify(location));
   };
   ```

5. Start obtaining the device location.
   
   ```ts
   geoLocationManager.on('locationChange', requestInfo, locationChange);
   ```

6. (Optional) Stop obtaining the device location.

   If your application no longer needs the device location, stop obtaining the device location to avoid high power consumption.

   ```ts
   geoLocationManager.off('locationChange', locationChange);
   ```

   If your application does not need the real-time device location, it can use the last known device location cached in the system instead.

   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   try {
       let location = geoLocationManager.getLastLocation();
   } catch (err) {
       console.error("errCode:" + err.code + ",errMessage:" + err.message);
   }
   ```


## Geocoding and Reverse Geocoding

### When to Use

Describing a location using coordinates is accurate, but neither intuitive nor user-friendly. To address this issue, the system provides your application the geocoding and reverse geocoding capabilities:

- Geocoding: converts geographic descriptions into specific coordinates.

- Reverse geocoding: converts coordinates into geographic descriptions.

The geocoding information describes a location using several attributes, including the country, administrative region, street, house number, and address, etc.

### Available APIs

The following table lists the APIs used for mutual conversion between coordinates and geographic descriptions. For details, see [Geolocation Manager](../reference/apis/js-apis-geoLocationManager.md).

**Table 3** APIs for geocoding and reverse geocoding conversion

| API| Description|
| -------- | -------- |
| isGeocoderAvailable(): boolean; | Obtains the (reverse) geocoding service status.|
| getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void | Converts coordinates into geographic descriptions through reverse geocoding. This API uses an asynchronous callback to return the result. |
| getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt; | Converts coordinates into geographic descriptions through reverse geocoding. This API uses a promise to return the result. |
| getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void | Converts geographic descriptions into coordinates through geocoding. This API uses an asynchronous callback to return the result. |
| getAddressesFromLocationName(request: GeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt; | Converts geographic descriptions into coordinates through geocoding. This API uses a promise to return the result. |

### How to Develop

> **NOTE**
>
> The **GeoConvert** instance needs to access backend services to obtain information. Therefore, before performing the following steps, ensure that your device is connected to the network.

1. Import the **geoLocationManager** module by which you can implement all APIs related to the geocoding and reverse geocoding conversion capabilities.
   
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   ```

2. Check whether the **geoCoder** service is available.
   
   Call **isGeoServiceAvailable** to check whether the **geoCoder** service is available. If the service is available, go to step 3.
   
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   try {
       let isAvailable = geoLocationManager.isGeocoderAvailable();
   } catch (err) {
       console.error("errCode:" + err.code + ",errMessage:" + err.message);
   }
   ```

3. Obtain the geocoding conversion result.
   - Call **getAddressesFromLocation** to convert coordinates into geographical location information.
     
      ```ts
      let reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
      try {
          geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
              if (err) {
                  console.log('getAddressesFromLocation err: ' + JSON.stringify(err));
              } else {
                  console.log('getAddressesFromLocation data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + err.code + ",errMessage:" + err.message);
      }
      ```

      The application can access the **GeoAddress** list that matches the specified coordinates for the corresponding geographic descriptions. For details, see [Geolocation Manager](../reference/apis/js-apis-geoLocationManager.md).
   - Call **getAddressesFromLocationName** to convert geographic descriptions into coordinates.
     
      ```ts
      let geocodeRequest = {"description": "No. xx, xx Road, Pudong District, Shanghai", "maxItems": 1};
      try {
          geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {
              if (err) {
                  console.log('getAddressesFromLocationName err: ' + JSON.stringify(err));
              } else {
                  console.log('getAddressesFromLocationName data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + err.code + ",errMessage:" + err.message);
      }
      ```

      The application can access the **GeoAddress** list that matches the specified geographic descriptions for the corresponding coordinates. For details, see [Geolocation Manager](../reference/apis/js-apis-geoLocationManager.md).
   
      To improve the accuracy of location results, you can set the longitude and latitude ranges in **GeoCodeRequest**.


## Geofencing

### When to Use

A geofence is a group of virtual bounds defining an area on the map. When a user device enters or leaves a geofence, or stays in a geofence, your app on the user device can automatically receive notifications and alarms.

Currently, only circular geofences are supported, and the geofencing function of the GNSS chip is required.

A typical application of geofencing is to create a geofence around an enterprise for targeted advertising. In different areas, you can provide differentiated promotions for mobile devices.

### Available APIs

The following table lists the APIs used for geofencing. For details, see [Geolocation Manager](../reference/apis/js-apis-geoLocationManager.md).

**Table 4** Geofencing APIs

| API| Description|
| -------- | -------- |
| on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void; | Registers a listener for status change events of the specified geofence.|
| off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void; | Unregisters the listener for status change events of the specified geofence.|

### How to Develop

1. Declare the **ohos.permission.APPROXIMATELY_LOCATION** permission. For details, see [Applying for Location Permissions](#applying-for-location-permissions).

2. Import the [geoLocationManager](../reference/apis/js-apis-geoLocationManager.md) and [wantAgent](../reference/apis/js-apis-app-ability-wantAgent.md) modules.
   
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   import wantAgent from '@ohos.app.ability.wantAgent';
   ```

3. Create a [WantAgentInfo](../reference/apis/js-apis-inner-wantAgent-wantAgentInfo.md) object.

   Scenario 1: Create a **WantAgentInfo** object for starting an ability. 

   ```ts
   let wantAgentObj = null; // Save the created WantAgent object for completing the trigger operations at a later time.
   
   // Set the operation type through operationType of the WantAgentInfo object.
   let wantAgentInfo = {
       wants: [
           {
               deviceId: '',
               bundleName: 'com.example.myapplication',
               abilityName: 'EntryAbility',
               action: '',
               entities: [],
               uri: '',
               parameters: {}
           }
       ],
       operationType: wantAgent.OperationType.START_ABILITY,
       requestCode: 0,
       wantAgentFlags:[wantAgent.WantAgentFlags.CONSTANT_FLAG]
   };
   ```

   Scenario 2: Create a **WantAgentInfo** object for publishing [common events](../application-models/common-event-overview.md).

   ```ts
   let wantAgentObj = null; // Save the created WantAgent object for completing the trigger operations at a later time.
   
   // Set the operation type through operationType of the WantAgentInfo object.
   let wantAgentInfo = {
       wants: [
           {
               action: "event_name", // Set the event name.
               parameters: {},
           }
       ],
       operationType: wantAgent.OperationType.SEND_COMMON_EVENT,
       requestCode: 0,
       wantAgentFlags: [wantAgent.WantAgentFlags.CONSTANT_FLAG],
   }
   ```

4. Call [getWantAgent()](../reference/apis/js-apis-app-ability-wantAgent.md#wantagentgetwantagent) to create a **WantAgent** object.

   After obtaining the **WantAgent** object, call the geofencing API to add a geofence.

   ```ts
   // Create a WantAgent object.
   wantAgent.getWantAgent(wantAgentInfo, (err, data) => {
       if (err) {
         console.error('getWantAgent err=' + JSON.stringify(err));
         return;
       }
       console.info('getWantAgent success');
       wantAgentObj = data;
       let requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
       try {
           geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
       } catch (err) {
           console.error("errCode:" + err.code + ",errMessage:" + err.message);
       }
   });
   ```

5. Have the system automatically trigger the action defined for the **WantAgent** object when a device enters or exits the geofence.