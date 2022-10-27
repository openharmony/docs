# Obtaining Device Location Information


## When to Use

You can call location-related APIs in OpenHarmony to obtain the real-time location or last known location of a mobile device.

Real-time location of the device is recommended for location-sensitive services. If you want to lower power consumption when the real-time location of the device is not needed, you may consider obtaining the last known location of the device.


## Available APIs

The following table describes APIs available for obtaining device location information.

  **Table 1** APIs for obtaining device location information

| API                                                      | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;) : void | Registers a listener for location changes with a location request initiated.                          |
| off(type: 'locationChange', callback?: Callback&lt;Location&gt;) : void | Unregisters the listener for location changes with the corresponding location request deleted.                    |
| on(type: 'locationServiceState', callback: Callback&lt;boolean&gt;) : void | Registers a listener for location service status change events.                                      |
| off(type: 'locationServiceState', callback: Callback&lt;boolean&gt;) : void | Unregisters the listener for location service status change events.                                  |
| on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;) : void; | Registers a listener for cached GNSS location reports.                                      |
| off(type: 'cachedGnssLocationsReporting', callback?: Callback&lt;Array&lt;Location&gt;&gt;) : void; | Unregisters the listener for cached GNSS location reports.                                  |
| on(type: 'gnssStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;) : void; | Registers a listener for satellite status change events.                                  |
| off(type: 'gnssStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;) : void; | Unregisters the listener for satellite status change events.                              |
| on(type: 'nmeaMessageChange', callback: Callback&lt;string&gt;) : void; | Registers a listener for GNSS NMEA message change events.                                     |
| off(type: 'nmeaMessageChange', callback?: Callback&lt;string&gt;) : void; | Unregisters the listener for GNSS NMEA message change events.                                 |
| on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void; | Registers a listener for status change events of the specified geofence.                            |
| off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void; | Unregisters the listener for status change events of the specified geofence.                            |
| getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;) : void | Obtains the current location. This API uses an asynchronous callback to return the result.                 |
| getCurrentLocation(request?: CurrentLocationRequest) : Promise&lt;Location&gt; | Obtains the current location. This API uses a promise to return the result.                  |
| getLastLocation(callback: AsyncCallback&lt;Location&gt;) : void | Obtains the previous location. This API uses an asynchronous callback to return the result.              |
| getLastLocation() : Promise&lt;Location&gt;                  | Obtains the previous location. This API uses a promise to return the result.                |
| isLocationEnabled(callback: AsyncCallback&lt;boolean&gt;) : void | Checks whether the location service is enabled. This API uses an asynchronous callback to return the result.    |
| isLocationEnabled() : Promise&lt;boolean&gt;                 | Checks whether the location service is enabled. This API uses a promise to return the result.     |
| requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;) : void | Requests to enable the location service. This API uses an asynchronous callback to return the result.            |
| requestEnableLocation() : Promise&lt;boolean&gt;             | Requests to enable the location service. This API uses a promise to return the result.             |
| enableLocation(callback: AsyncCallback&lt;boolean&gt;) : void | Enables the location service. This API uses an asynchronous callback to return the result.                |
| enableLocation() : Promise&lt;boolean&gt;                    | Enables the location service. This API uses a promise to return the result.                 |
| disableLocation(callback: AsyncCallback&lt;boolean&gt;) : void | Disables the location service. This API uses an asynchronous callback to return the result.                |
| disableLocation() : Promise&lt;boolean&gt;                   | Disables the location service. This API uses a promise to return the result.                 |
| getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;) : void; | Obtains the number of cached GNSS locations. This API uses an asynchronous callback to return the result.      |
| getCachedGnssLocationsSize() : Promise&lt;number&gt;;        | Obtains the number of cached GNSS locations. This API uses a promise to return the result.       |
| flushCachedGnssLocations(callback: AsyncCallback&lt;boolean&gt;) : void; | Obtains all cached GNSS locations and clears the GNSS cache queue. This API uses an asynchronous callback to return the result.|
| flushCachedGnssLocations() : Promise&lt;boolean&gt;;         | Obtains all cached GNSS locations and clears the GNSS cache queue. This API uses a promise to return the result.|
| sendCommand(command: LocationCommand, callback: AsyncCallback&lt;boolean&gt;) : void; | Sends extended commands to the location subsystem. This API uses an asynchronous callback to return the result.|
| sendCommand(command: LocationCommand) : Promise&lt;boolean&gt;; | Sends extended commands to the location subsystem. This API uses a promise to return the result. |
| isLocationPrivacyConfirmed(type : LocationPrivacyType, callback: AsyncCallback&lt;boolean&gt;) : void; | Checks whether a user agrees with the privacy statement of the location service. This API uses an asynchronous callback to return the result.|
| isLocationPrivacyConfirmed(type : LocationPrivacyType,) : Promise&lt;boolean&gt;; | Checks whether a user agrees with the privacy statement of the location service. This API uses a promise to return the result.|
| setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean, callback: AsyncCallback&lt;boolean&gt;) : void; | Sets the user confirmation status for the privacy statement of the location service. This API uses an asynchronous callback to return the result.|
| setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean) : Promise&lt;boolean&gt;; | Sets the user confirmation status for the privacy statement of the location service. This API uses a promise to return the result.|


## How to Develop

To learn more about the APIs for obtaining device location information, see [Geolocation](../reference/apis/js-apis-geolocation.md).

1. Before using basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user as described below.
     The system provides the following location permissions:
   - ohos.permission.LOCATION
   
   - ohos.permission.LOCATION_IN_BACKGROUND

   The **ohos.permission.LOCATION** permission is a must if your application needs to access the device location information.

   If your application needs to access the device location information when running on the background, it must be configured to be able to run on the background and be granted the **ohos.permission.LOCATION_IN_BACKGROUND** permission. In this way, the system continues to report device location information after your application moves to the background.

   You can declare the required permission in your application's configuration file. For details, see [Access Control (Permission) Development](../security/accesstoken-guidelines.md).

2. Import the **geolocation** module by which you can implement all APIs related to the basic location capabilities.
   
   ```
   import geolocation from '@ohos.geolocation';
   ```

3. Instantiate the **LocationRequest** object. This object provides APIs to notify the system of the location service type and the interval of reporting location information.<br>
   **Method 1:**

   To better serve your needs for using APIs, the system has categorized APIs into different packages to match your common use cases of the location function. In this way, you can directly use the APIs specific to a certain use case, making application development much easier. The following table lists the use cases currently supported.

   
   ```
       export enum LocationRequestScenario {
            UNSET = 0x300,
            NAVIGATION,
            TRAJECTORY_TRACKING,
            CAR_HAILING,
            DAILY_LIFE_SERVICE,
            NO_POWER,
        }
   ```

   
     **Table 2** Common use cases of the location function
   
   | Use Case    | Constant           | Description                                                        |
   | ------------ | ------------------- | ------------------------------------------------------------ |
   | Navigation    | NAVIGATION          | Applicable when your application needs to obtain the real-time location of a mobile device outdoors, such as navigation for driving or walking. In this scenario, the GNSS positioning technology is mainly used to ensure the location accuracy. However, due to its limitations, the technology may be unable to provide the location service when navigation is just started or when the user moves into a shielded environment such as indoors or a garage. To resolve this issue, the system uses the network positioning technology as an alternative to provide the location service for your application until the GNSS can provide stable location results. This helps achieve a smooth navigation experience for users.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Trajectory tracking| TRAJECTORY_TRACKING | Applicable when your application needs to record user trajectories, for example, the track recording function of sports applications. In this scenario, the GNSS positioning technology is mainly used to ensure the location accuracy.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Ride hailing| CAR_HAILING         | Applicable when your application needs to obtain the current location of a user who is hailing a taxi.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Life service| DAILY_LIFE_SERVICE  | Applicable when your application only needs the approximate user location for recommendations and push notifications in scenarios such as when the user is browsing news, shopping online, and ordering food.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Power efficiency  | NO_POWER            | Applicable when your application does not proactively start the location service for a higher battery efficiency. When responding to another application requesting the same location service, the system marks a copy of the location result to your application. In this way, your application will not consume extra power for obtaining the user location.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|

     Sample code for initializing **requestInfo** for navigation:
   
   ```
   var requestInfo = {'scenario': geolocation.LocationRequestScenario.NAVIGATION, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

   **Method 2:**

   If the predefined use cases do not meet your needs, you can also use the basic location priority policies provided by the system.

   
   ```
       export enum LocationRequestPriority {
            UNSET = 0x200,
            ACCURACY,
            LOW_POWER,
            FIRST_FIX,
        }
   ```

   
     **Table 3** Location priority policies
   
   | Policy          | Constant      | Description                                                        |
   | ------------------ | -------------- | ------------------------------------------------------------ |
   | Location accuracy priority  | ACCURACY       | This policy mainly uses the GNSS positioning technology. In an open area, the technology can achieve the meter-level location accuracy, depending on the hardware performance of the device. However, in a shielded environment, the location accuracy may significantly decrease.<br>To use this policy, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Fast location priority  | FAST_FIRST_FIX | This policy uses the GNSS positioning, base station positioning, WLAN positioning, and Bluetooth positioning technologies simultaneously to obtain the device location in both the indoor and outdoor scenarios. When all positioning technologies provide a location result, the system provides the most accurate location result for your application. This policy can lead to significant hardware resource consumption and power consumption.<br>To use this policy, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Power efficiency priority| LOW_POWER      | This policy mainly uses the base station positioning, WLAN positioning, and Bluetooth positioning technologies to obtain device location in both indoor and outdoor scenarios. The location accuracy depends on the distribution of surrounding base stations, visible WLANs, and Bluetooth devices and therefore may fluctuate greatly. This policy is recommended and can reduce power consumption when your application does not require high location accuracy or when base stations, visible WLANs, and Bluetooth devices are densely distributed.<br>To use this policy, you must declare at least the **ohos.permission.LOCATION** permission and obtain users' authorization.|

     Sample code for initializing **requestInfo** for the location accuracy priority policy:
   
   ```
   var requestInfo = {'priority': geolocation.LocationRequestPriority.ACCURACY, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

4. Instantiate the **Callback** object for the system to report location results.
     Your application needs to implement the callback defined by the system. When the system successfully obtains the real-time location of a device, it will report the location result to your application through the callback interface. Your application can implement the callback interface in such a way to complete your own service logic.
     
   ```
   var locationChange = (location) => {
       console.log('locationChanger: data: ' + JSON.stringify(location));
   };
   ```

5. Start device location.
   
   ```
   geolocation.on('locationChange', requestInfo, locationChange);
   ```

6. (Optional) Stop device location.
   
   ```
   geolocation.off('locationChange', locationChange);
   ```

If your application does not need the real-time device location, it can use the last known device location cached in the system instead.
     
   ```
   geolocation.getLastLocation((err, data) => {
       if (err) {
           console.log('getLastLocation: err: ' + JSON.stringify(err));
       } else {
           console.log('getLastLocation: data: ' + JSON.stringify(data));
       }
   });
   ```

   To call this method, your application needs to request the **ohos.permission.LOCATION** permission from the user.
