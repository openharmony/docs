# Obtaining Device Location Information


## When to Use

You can call location-related APIs in OpenHarmony to obtain the real-time location or last known location of a mobile device.

Real-time location of the device is recommended for location-sensitive services. If you want to lower power consumption when the real-time location of the device is not needed, you may consider obtaining the last known location of the device.


## Available APIs

The following table describes APIs available for obtaining device location information.

  **Table 1** APIs for obtaining device location information

| API | Description |
| -------- | -------- |
| on(type:&nbsp;'locationChange',&nbsp;request:&nbsp;LocationRequest,&nbsp;callback:&nbsp;Callback&lt;Location&gt;)&nbsp;:&nbsp;void | Registers&nbsp;a&nbsp;listener&nbsp;for&nbsp;location&nbsp;changes&nbsp;with&nbsp;a&nbsp;location&nbsp;request&nbsp;initiated. |
| off(type:&nbsp;'locationChange',&nbsp;callback?:&nbsp;Callback&lt;Location&gt;)&nbsp;:&nbsp;void | Unregisters&nbsp;the&nbsp;listener&nbsp;for&nbsp;location&nbsp;changes&nbsp;with&nbsp;the&nbsp;corresponding&nbsp;location&nbsp;request&nbsp;deleted. |
| on(type:&nbsp;'locationServiceState',&nbsp;callback:&nbsp;Callback&lt;boolean&gt;)&nbsp;:&nbsp;void | Registers&nbsp;a&nbsp;listener&nbsp;for&nbsp;location&nbsp;service&nbsp;status&nbsp;change&nbsp;events. |
| off(type:&nbsp;'locationServiceState',&nbsp;callback:&nbsp;Callback&lt;boolean&gt;)&nbsp;:&nbsp;void | Unregisters&nbsp;the&nbsp;listener&nbsp;for&nbsp;location&nbsp;service&nbsp;status&nbsp;change&nbsp;events. |
| on(type:&nbsp;'cachedGnssLocationsReporting',&nbsp;request:&nbsp;CachedGnssLoactionsRequest,&nbsp;callback:&nbsp;Callback&lt;Array&lt;Location&gt;&gt;)&nbsp;:&nbsp;void; | Registers&nbsp;a&nbsp;listener&nbsp;for&nbsp;cached&nbsp;GNSS&nbsp;location&nbsp;reports. |
| off(type:&nbsp;'cachedGnssLocationsReporting',&nbsp;callback?:&nbsp;Callback&lt;Array&lt;Location&gt;&gt;)&nbsp;:&nbsp;void; | Unregisters&nbsp;the&nbsp;listener&nbsp;for&nbsp;cached&nbsp;GNSS&nbsp;location&nbsp;reports. |
| on(type:&nbsp;'gnssStatusChange',&nbsp;callback:&nbsp;Callback&lt;SatelliteStatusInfo&gt;)&nbsp;:&nbsp;void; | Registers&nbsp;a&nbsp;listener&nbsp;for&nbsp;satellite&nbsp;status&nbsp;change&nbsp;events. |
| off(type:&nbsp;'gnssStatusChange',&nbsp;callback?:&nbsp;Callback&lt;SatelliteStatusInfo&gt;)&nbsp;:&nbsp;void; | Unregisters&nbsp;the&nbsp;listener&nbsp;for&nbsp;satellite&nbsp;status&nbsp;change&nbsp;events. |
| on(type:&nbsp;'nmeaMessageChange',&nbsp;callback:&nbsp;Callback&lt;string&gt;)&nbsp;:&nbsp;void; | Registers&nbsp;a&nbsp;listener&nbsp;for&nbsp;GNSS&nbsp;NMEA&nbsp;message&nbsp;change&nbsp;events. |
| off(type:&nbsp;'nmeaMessageChange',&nbsp;callback?:&nbsp;Callback&lt;string&gt;)&nbsp;:&nbsp;void; | Unregisters&nbsp;the&nbsp;listener&nbsp;for&nbsp;GNSS&nbsp;NMEA&nbsp;message&nbsp;change&nbsp;events. |
| on(type:&nbsp;'fenceStatusChange',&nbsp;request:&nbsp;GeofenceRequest,&nbsp;want:&nbsp;WantAgent)&nbsp;:&nbsp;void; | Registers&nbsp;a&nbsp;listener&nbsp;for&nbsp;status&nbsp;change&nbsp;events&nbsp;of&nbsp;the&nbsp;specified&nbsp;geofence. |
| off(type:&nbsp;'fenceStatusChange',&nbsp;request:&nbsp;GeofenceRequest,&nbsp;want:&nbsp;WantAgent)&nbsp;:&nbsp;void; | Unregisters&nbsp;the&nbsp;listener&nbsp;for&nbsp;status&nbsp;change&nbsp;events&nbsp;of&nbsp;the&nbsp;specified&nbsp;geofence. |
| getCurrentLocation(request:&nbsp;CurrentLocationRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;Location&gt;)&nbsp;:&nbsp;void | Obtains&nbsp;the&nbsp;current&nbsp;location.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| getCurrentLocation(request?:&nbsp;CurrentLocationRequest)&nbsp;:&nbsp;Promise&lt;Location&gt; | Obtains&nbsp;the&nbsp;current&nbsp;location.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| getLastLocation(callback:&nbsp;AsyncCallback&lt;Location&gt;)&nbsp;:&nbsp;void | Obtains&nbsp;the&nbsp;previous&nbsp;location.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| getLastLocation()&nbsp;:&nbsp;Promise&lt;Location&gt; | Obtains&nbsp;the&nbsp;previous&nbsp;location.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| isLocationEnabled(callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void | Checks&nbsp;whether&nbsp;the&nbsp;location&nbsp;service&nbsp;is&nbsp;enabled.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| isLocationEnabled()&nbsp;:&nbsp;Promise&lt;boolean&gt; | Checks&nbsp;whether&nbsp;the&nbsp;location&nbsp;service&nbsp;is&nbsp;enabled.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| requestEnableLocation(callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void | Requests&nbsp;to&nbsp;enable&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| requestEnableLocation()&nbsp;:&nbsp;Promise&lt;boolean&gt; | Requests&nbsp;to&nbsp;enable&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| enableLocation(callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void | Enables&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| enableLocation()&nbsp;:&nbsp;Promise&lt;boolean&gt; | Enables&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| disableLocation(callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void | Disables&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| disableLocation()&nbsp;:&nbsp;Promise&lt;boolean&gt; | Disables&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| getCachedGnssLocationsSize(callback:&nbsp;AsyncCallback&lt;number&gt;)&nbsp;:&nbsp;void; | Obtains&nbsp;the&nbsp;number&nbsp;of&nbsp;cached&nbsp;GNSS&nbsp;locations.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| getCachedGnssLocationsSize()&nbsp;:&nbsp;Promise&lt;number&gt;; | Obtains&nbsp;the&nbsp;number&nbsp;of&nbsp;cached&nbsp;GNSS&nbsp;locations.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| flushCachedGnssLocations(callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void; | Obtains&nbsp;all&nbsp;cached&nbsp;GNSS&nbsp;locations&nbsp;and&nbsp;clears&nbsp;the&nbsp;GNSS&nbsp;cache&nbsp;queue.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| flushCachedGnssLocations()&nbsp;:&nbsp;Promise&lt;boolean&gt;; | Obtains&nbsp;all&nbsp;cached&nbsp;GNSS&nbsp;locations&nbsp;and&nbsp;clears&nbsp;the&nbsp;GNSS&nbsp;cache&nbsp;queue.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| sendCommand(command:&nbsp;LocationCommand,&nbsp;callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void; | Sends&nbsp;extended&nbsp;commands&nbsp;to&nbsp;the&nbsp;location&nbsp;subsystem.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| sendCommand(command:&nbsp;LocationCommand)&nbsp;:&nbsp;Promise&lt;boolean&gt;; | Sends&nbsp;extended&nbsp;commands&nbsp;to&nbsp;the&nbsp;location&nbsp;subsystem.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| isLocationPrivacyConfirmed(type&nbsp;:&nbsp;LocationPrivacyType,&nbsp;callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void; | Checks&nbsp;whether&nbsp;a&nbsp;user&nbsp;agrees&nbsp;with&nbsp;the&nbsp;privacy&nbsp;statement&nbsp;of&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| isLocationPrivacyConfirmed(type&nbsp;:&nbsp;LocationPrivacyType,)&nbsp;:&nbsp;Promise&lt;boolean&gt;; | Checks&nbsp;whether&nbsp;a&nbsp;user&nbsp;agrees&nbsp;with&nbsp;the&nbsp;privacy&nbsp;statement&nbsp;of&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| setLocationPrivacyConfirmStatus(type&nbsp;:&nbsp;LocationPrivacyType,&nbsp;isConfirmed&nbsp;:&nbsp;boolean,&nbsp;callback:&nbsp;AsyncCallback&lt;boolean&gt;)&nbsp;:&nbsp;void; | Sets&nbsp;the&nbsp;user&nbsp;confirmation&nbsp;status&nbsp;for&nbsp;the&nbsp;privacy&nbsp;statement&nbsp;of&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;an&nbsp;asynchronous&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |
| setLocationPrivacyConfirmStatus(type&nbsp;:&nbsp;LocationPrivacyType,&nbsp;isConfirmed&nbsp;:&nbsp;boolean)&nbsp;:&nbsp;Promise&lt;boolean&gt;; | Sets&nbsp;the&nbsp;user&nbsp;confirmation&nbsp;status&nbsp;for&nbsp;the&nbsp;privacy&nbsp;statement&nbsp;of&nbsp;the&nbsp;location&nbsp;service.&nbsp;This&nbsp;function&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. |


## How to Develop

To learn more about the APIs for obtaining device location information, see [Geolocation](../reference/apis/js-apis-geolocation.md).

1. Before using basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user. For details, see the following section.
     The system provides the following location permissions:
   - ohos.permission.LOCATION
   
   - ohos.permission.LOCATION_IN_BACKGROUND

   The **ohos.permission.LOCATION** permission is a must if your application needs to access the device location information.

   If your application needs to access the device location information when running on the background, it must be allowed to run on the background in the configuration file and also granted the **ohos.permission.LOCATION_IN_BACKGROUND** permission. In this way, the system continues to report device location information even when your application moves to the background.

   To allow your application to access device location information, you can declare the required permissions in the **config.json** file of your application. The sample code is as follows:

   
   ```
   {
       "module": {
           "reqPermissions": [
               "name": "ohos.permission.LOCATION",
               "reason": "$string:reason_description",
               "usedScene": {
                   "ability": ["com.myapplication.LocationAbility"],
                   "when": "inuse"
               }
           ]
       }
   }
   ```
   
   For details about the fields, see .

2. Import the **geolocation** module by which you can implement all APIs related to the basic location capabilities.
   
   ```
   import geolocation from '@ohos.geolocation';
   ```

3. Instantiate the **LocationRequest** object. This object provides APIs to notify the system of the location service type and the interval of reporting location information.
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
   
   | Use&nbsp;Case | Constant | Description |
   | -------- | -------- | -------- |
   | Navigation | NAVIGATION | Applicable&nbsp;when&nbsp;your&nbsp;application&nbsp;needs&nbsp;to&nbsp;obtain&nbsp;the&nbsp;real-time&nbsp;location&nbsp;of&nbsp;a&nbsp;mobile&nbsp;device&nbsp;outdoors,&nbsp;such&nbsp;as&nbsp;navigation&nbsp;for&nbsp;driving&nbsp;or&nbsp;walking.&nbsp;In&nbsp;this&nbsp;scenario,&nbsp;the&nbsp;GNSS&nbsp;positioning&nbsp;technology&nbsp;is&nbsp;mainly&nbsp;used&nbsp;to&nbsp;ensure&nbsp;the&nbsp;location&nbsp;accuracy.&nbsp;However,&nbsp;due&nbsp;to&nbsp;its&nbsp;limitations,&nbsp;the&nbsp;technology&nbsp;may&nbsp;be&nbsp;unable&nbsp;to&nbsp;provide&nbsp;the&nbsp;location&nbsp;service&nbsp;when&nbsp;navigation&nbsp;is&nbsp;just&nbsp;started&nbsp;or&nbsp;when&nbsp;the&nbsp;user&nbsp;moves&nbsp;into&nbsp;a&nbsp;shielded&nbsp;environment&nbsp;such&nbsp;as&nbsp;indoors&nbsp;or&nbsp;a&nbsp;garage.&nbsp;To&nbsp;resolve&nbsp;this&nbsp;issue,&nbsp;the&nbsp;system&nbsp;uses&nbsp;the&nbsp;network&nbsp;positioning&nbsp;technology&nbsp;as&nbsp;an&nbsp;alternative&nbsp;to&nbsp;provide&nbsp;the&nbsp;location&nbsp;service&nbsp;for&nbsp;your&nbsp;application&nbsp;until&nbsp;the&nbsp;GNSS&nbsp;can&nbsp;provide&nbsp;stable&nbsp;location&nbsp;results.&nbsp;This&nbsp;helps&nbsp;achieve&nbsp;a&nbsp;smooth&nbsp;navigation&nbsp;experience&nbsp;for&nbsp;users.<br/>By&nbsp;default,&nbsp;the&nbsp;system&nbsp;reports&nbsp;location&nbsp;results&nbsp;at&nbsp;a&nbsp;minimal&nbsp;interval&nbsp;of&nbsp;1s.&nbsp;To&nbsp;adopt&nbsp;this&nbsp;use&nbsp;case,&nbsp;you&nbsp;must&nbsp;declare&nbsp;the&nbsp;**ohos.permission.LOCATION**&nbsp;permission&nbsp;and&nbsp;obtain&nbsp;users'&nbsp;authorization. |
   | Trajectory&nbsp;tracking | TRAJECTORY_TRACKING | Applicable&nbsp;when&nbsp;your&nbsp;application&nbsp;needs&nbsp;to&nbsp;record&nbsp;user&nbsp;trajectories,&nbsp;for&nbsp;example,&nbsp;the&nbsp;track&nbsp;recording&nbsp;function&nbsp;of&nbsp;sports&nbsp;applications.&nbsp;In&nbsp;this&nbsp;scenario,&nbsp;the&nbsp;GNSS&nbsp;positioning&nbsp;technology&nbsp;is&nbsp;mainly&nbsp;used&nbsp;to&nbsp;ensure&nbsp;the&nbsp;location&nbsp;accuracy.<br/>By&nbsp;default,&nbsp;the&nbsp;system&nbsp;reports&nbsp;location&nbsp;results&nbsp;at&nbsp;a&nbsp;minimal&nbsp;interval&nbsp;of&nbsp;1s.&nbsp;To&nbsp;adopt&nbsp;this&nbsp;use&nbsp;case,&nbsp;you&nbsp;must&nbsp;declare&nbsp;the&nbsp;**ohos.permission.LOCATION**&nbsp;permission&nbsp;and&nbsp;obtain&nbsp;users'&nbsp;authorization. |
   | Ride&nbsp;hailing | CAR_HAILING | Applicable&nbsp;when&nbsp;your&nbsp;application&nbsp;needs&nbsp;to&nbsp;obtain&nbsp;the&nbsp;current&nbsp;location&nbsp;of&nbsp;a&nbsp;user&nbsp;who&nbsp;is&nbsp;hailing&nbsp;a&nbsp;taxi.<br/>By&nbsp;default,&nbsp;the&nbsp;system&nbsp;reports&nbsp;location&nbsp;results&nbsp;at&nbsp;a&nbsp;minimal&nbsp;interval&nbsp;of&nbsp;1s.&nbsp;To&nbsp;adopt&nbsp;this&nbsp;use&nbsp;case,&nbsp;you&nbsp;must&nbsp;declare&nbsp;the&nbsp;**ohos.permission.LOCATION**&nbsp;permission&nbsp;and&nbsp;obtain&nbsp;users'&nbsp;authorization. |
   | Life&nbsp;service | DAILY_LIFE_SERVICE | Applicable&nbsp;when&nbsp;your&nbsp;application&nbsp;only&nbsp;needs&nbsp;the&nbsp;approximate&nbsp;user&nbsp;location&nbsp;for&nbsp;recommendations&nbsp;and&nbsp;push&nbsp;notifications&nbsp;in&nbsp;scenarios&nbsp;such&nbsp;as&nbsp;when&nbsp;the&nbsp;user&nbsp;is&nbsp;browsing&nbsp;news,&nbsp;shopping&nbsp;online,&nbsp;and&nbsp;ordering&nbsp;food.<br/>By&nbsp;default,&nbsp;the&nbsp;system&nbsp;reports&nbsp;location&nbsp;results&nbsp;at&nbsp;a&nbsp;minimal&nbsp;interval&nbsp;of&nbsp;1s.&nbsp;To&nbsp;adopt&nbsp;this&nbsp;use&nbsp;case,&nbsp;you&nbsp;must&nbsp;declare&nbsp;the&nbsp;**ohos.permission.LOCATION**&nbsp;permission&nbsp;and&nbsp;obtain&nbsp;users'&nbsp;authorization. |
   | Power&nbsp;efficiency | NO_POWER | Applicable&nbsp;when&nbsp;your&nbsp;application&nbsp;does&nbsp;not&nbsp;proactively&nbsp;start&nbsp;the&nbsp;location&nbsp;service&nbsp;for&nbsp;a&nbsp;higher&nbsp;battery&nbsp;efficiency.&nbsp;When&nbsp;responding&nbsp;to&nbsp;another&nbsp;application&nbsp;requesting&nbsp;the&nbsp;same&nbsp;location&nbsp;service,&nbsp;the&nbsp;system&nbsp;marks&nbsp;a&nbsp;copy&nbsp;of&nbsp;the&nbsp;location&nbsp;result&nbsp;to&nbsp;your&nbsp;application.&nbsp;In&nbsp;this&nbsp;way,&nbsp;your&nbsp;application&nbsp;will&nbsp;not&nbsp;consume&nbsp;extra&nbsp;power&nbsp;for&nbsp;obtaining&nbsp;the&nbsp;user&nbsp;location.<br/>By&nbsp;default,&nbsp;the&nbsp;system&nbsp;reports&nbsp;location&nbsp;results&nbsp;at&nbsp;a&nbsp;minimal&nbsp;interval&nbsp;of&nbsp;1s.&nbsp;To&nbsp;adopt&nbsp;this&nbsp;use&nbsp;case,&nbsp;you&nbsp;must&nbsp;declare&nbsp;the&nbsp;**ohos.permission.LOCATION**&nbsp;permission&nbsp;and&nbsp;obtain&nbsp;users'&nbsp;authorization. |

     The following example instantiates the **RequestParam** object for navigation:
   
   ```
   var requestInfo = {'scenario': 0x301, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
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
   
   | Policy | Constant | Description |
   | -------- | -------- | -------- |
   | Location&nbsp;accuracy&nbsp;priority | ACCURACY | This&nbsp;policy&nbsp;mainly&nbsp;uses&nbsp;the&nbsp;GNSS&nbsp;positioning&nbsp;technology.&nbsp;In&nbsp;an&nbsp;open&nbsp;area,&nbsp;the&nbsp;technology&nbsp;can&nbsp;achieve&nbsp;the&nbsp;meter-level&nbsp;location&nbsp;accuracy,&nbsp;depending&nbsp;on&nbsp;the&nbsp;hardware&nbsp;performance&nbsp;of&nbsp;the&nbsp;device.&nbsp;However,&nbsp;in&nbsp;a&nbsp;shielded&nbsp;environment,&nbsp;the&nbsp;location&nbsp;accuracy&nbsp;may&nbsp;significantly&nbsp;decrease.<br/>To&nbsp;use&nbsp;this&nbsp;policy,&nbsp;you&nbsp;must&nbsp;declare&nbsp;the&nbsp;**ohos.permission.LOCATION**&nbsp;permission&nbsp;and&nbsp;obtain&nbsp;users'&nbsp;authorization. |
   | Fast&nbsp;location&nbsp;priority | FAST_FIRST_FIX | This&nbsp;policy&nbsp;uses&nbsp;the&nbsp;GNSS&nbsp;positioning,&nbsp;base&nbsp;station&nbsp;positioning,&nbsp;WLAN&nbsp;positioning,&nbsp;and&nbsp;Bluetooth&nbsp;positioning&nbsp;technologies&nbsp;simultaneously&nbsp;to&nbsp;obtain&nbsp;the&nbsp;device&nbsp;location&nbsp;in&nbsp;both&nbsp;the&nbsp;indoor&nbsp;and&nbsp;outdoor&nbsp;scenarios.&nbsp;When&nbsp;all&nbsp;positioning&nbsp;technologies&nbsp;provide&nbsp;a&nbsp;location&nbsp;result,&nbsp;the&nbsp;system&nbsp;provides&nbsp;the&nbsp;most&nbsp;accurate&nbsp;location&nbsp;result&nbsp;for&nbsp;your&nbsp;application.&nbsp;This&nbsp;policy&nbsp;can&nbsp;lead&nbsp;to&nbsp;significant&nbsp;hardware&nbsp;resource&nbsp;consumption&nbsp;and&nbsp;power&nbsp;consumption.<br/>To&nbsp;use&nbsp;this&nbsp;policy,&nbsp;you&nbsp;must&nbsp;declare&nbsp;the&nbsp;**ohos.permission.LOCATION**&nbsp;permission&nbsp;and&nbsp;obtain&nbsp;users'&nbsp;authorization. |
   | Power&nbsp;efficiency&nbsp;priority | LOW_POWER | This&nbsp;policy&nbsp;mainly&nbsp;uses&nbsp;the&nbsp;base&nbsp;station&nbsp;positioning,&nbsp;WLAN&nbsp;positioning,&nbsp;and&nbsp;Bluetooth&nbsp;positioning&nbsp;technologies&nbsp;to&nbsp;obtain&nbsp;device&nbsp;location&nbsp;in&nbsp;both&nbsp;indoor&nbsp;and&nbsp;outdoor&nbsp;scenarios.&nbsp;The&nbsp;location&nbsp;accuracy&nbsp;depends&nbsp;on&nbsp;the&nbsp;distribution&nbsp;of&nbsp;surrounding&nbsp;base&nbsp;stations,&nbsp;visible&nbsp;WLANs,&nbsp;and&nbsp;Bluetooth&nbsp;devices&nbsp;and&nbsp;therefore&nbsp;may&nbsp;fluctuate&nbsp;greatly.&nbsp;This&nbsp;policy&nbsp;is&nbsp;recommended&nbsp;and&nbsp;can&nbsp;reduce&nbsp;power&nbsp;consumption&nbsp;when&nbsp;your&nbsp;application&nbsp;does&nbsp;not&nbsp;require&nbsp;high&nbsp;location&nbsp;accuracy&nbsp;or&nbsp;when&nbsp;base&nbsp;stations,&nbsp;visible&nbsp;WLANs,&nbsp;and&nbsp;Bluetooth&nbsp;devices&nbsp;are&nbsp;densely&nbsp;distributed.<br/>To&nbsp;use&nbsp;this&nbsp;policy,&nbsp;you&nbsp;must&nbsp;declare&nbsp;at&nbsp;least&nbsp;the&nbsp;**ohos.permission.LOCATION**&nbsp;permission&nbsp;and&nbsp;obtain&nbsp;users'&nbsp;authorization. |

     The following example instantiates the **RequestParam** object for the location accuracy priority policy:
   
   ```
   var requestInfo = {'priority': 0x201, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

4. Instantiate the **Callback** object for the system to report location results.
     Your application needs to implement the callback interface defined by the system. When the system successfully obtains the real-time location of a device, it will report the location result to your application through the callback interface. Your application can implement the callback interface in such a way to complete your own service logic.
     
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
   geolocation.getLastLocation((data) => {
       console.log('getLastLocation: data: ' + JSON.stringify(data));
   });
   ```

   To call this method, your application needs to request the **ohos.permission.LOCATION** permission from the user.
