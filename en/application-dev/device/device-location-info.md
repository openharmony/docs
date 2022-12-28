# Obtaining Device Location Information


## When to Use

You can call location-related APIs in OpenHarmony to obtain the real-time location or last known location of a mobile device.

Real-time location of the device is recommended for location-sensitive services. If you want to lower power consumption when the real-time location of the device is not needed, you may consider obtaining the last known location of the device.


## Available APIs

For details about the APIs used to obtain the device location information, see [Geolocation Manager](../reference/apis/js-apis-geoLocationManager.md).

## How to Develop

To learn more about the APIs for obtaining device location information, see [Geolocation](../reference/apis/js-apis-geoLocationManager.md).

1. Before using basic location capabilities, check whether your application has been granted the permission to access the device location information. If not, your application needs to obtain the permission from the user as described below.
     The system provides the following location permissions:
   - ohos.permission.LOCATION

   - ohos.permission.APPROXIMATELY_LOCATION
   
   - ohos.permission.LOCATION_IN_BACKGROUND

   If your application needs to access the device location information, it must first apply for required permissions. Specifically speaking:
   
   API versions earlier than 9: Apply for **ohos.permission.LOCATION**.
   
   API version 9 and later: Apply for **ohos.permission.APPROXIMATELY\_LOCATION**, or apply for **ohos.permission.APPROXIMATELY\_LOCATION** and **ohos.permission.LOCATION**. Note that **ohos.permission.LOCATION** cannot be applied for separately.
   
   | Target API Level| Location Permission| Permission Application Result| Location Accuracy|
   | -------- | -------- | -------- | -------- |
   | Earlier than 9| ohos.permission.LOCATION | Success| Location accurate to meters|
   | 9 and later| ohos.permission.LOCATION | Failure| No location obtained|
   | 9 and later| ohos.permission.APPROXIMATELY_LOCATION | Success| Location accurate to 5 kilometers|
   | 9 and later| ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION| Success| Location accurate to meters|

   If your application needs to access the device location information when running on the background, it must be configured to be able to run on the background and be granted the **ohos.permission.LOCATION_IN_BACKGROUND** permission. In this way, the system continues to report device location information after your application moves to the background.

   You can declare the required permission in your application's configuration file. For details, see [Access Control (Permission) Development](../security/accesstoken-guidelines.md).

2. Import the **geoLocationManager** module by which you can implement all APIs related to the basic location capabilities.
   
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   ```

3. Instantiate the **LocationRequest** object. This object provides APIs to notify the system of the location service type and the interval of reporting location information.<br>
   **Method 1:**

   To better serve your needs for using APIs, the system has categorized APIs into different packages to match your common use cases of the location function. In this way, you can directly use the APIs specific to a certain use case, making application development much easier. The following table lists the use cases currently supported.

   
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

   
     **Table 2** Common use cases of the location function
   
   | Use Case    | Constant           | Description                                                        |
   | ------------ | ------------------- | ------------------------------------------------------------ |
   | Navigation    | NAVIGATION          | Applicable when your application needs to obtain the real-time location of a mobile device outdoors, such as navigation for driving or walking. In this scenario, the GNSS positioning technology is mainly used to ensure the location accuracy. However, due to its limitations, the technology may be unable to provide the location service when navigation is just started or when the user moves into a shielded environment such as indoors or a garage. To resolve this issue, the system uses the network positioning technology as an alternative to provide the location service for your application until the GNSS can provide stable location results. This helps achieve a smooth navigation experience for users.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Trajectory tracking| TRAJECTORY_TRACKING | Applicable when your application needs to record user trajectories, for example, the track recording function of sports applications. In this scenario, the GNSS positioning technology is mainly used to ensure the location accuracy.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Ride hailing| CAR_HAILING         | Applicable when your application needs to obtain the current location of a user who is hailing a taxi.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Life service| DAILY_LIFE_SERVICE  | Applicable when your application only needs the approximate user location for recommendations and push notifications in scenarios such as when the user is browsing news, shopping online, and ordering food.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|
   | Power efficiency  | NO_POWER            | Applicable when your application does not proactively start the location service for a higher battery efficiency. When responding to another application requesting the same location service, the system marks a copy of the location result to your application. In this way, your application will not consume extra power for obtaining the user location.<br>By default, the system reports location results at a minimal interval of 1s. To adopt this use case, you must declare the **ohos.permission.LOCATION** permission and obtain users' authorization.|

     Sample code for initializing **requestInfo** for navigation:
   
   ```ts
   var requestInfo = {'scenario': geoLocationManager.LocationRequestScenario.NAVIGATION, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

   **Method 2:**

   If the predefined use cases do not meet your needs, you can also use the basic location priority policies provided by the system.

   
   ```ts
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
   
   ```ts
   var requestInfo = {'priority': geoLocationManager.LocationRequestPriority.ACCURACY, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

4. Instantiate the **Callback** object for the system to report location results.
     Your application needs to implement the callback defined by the system. When the system successfully obtains the real-time location of a device, it will report the location result to your application through the callback interface. Your application can implement the callback interface in such a way to complete your own service logic.
     
   ```ts
   var locationChange = (location) => {
       console.log('locationChanger: data: ' + JSON.stringify(location));
   };
   ```

5. Start device location.
   
   ```ts
   geoLocationManager.on('locationChange', requestInfo, locationChange);
   ```

6. (Optional) Stop device location.
   
   ```ts
   geoLocationManager.off('locationChange', locationChange);
   ```

If your application does not need the real-time device location, it can use the last known device location cached in the system instead.
     
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   try {
       var location = geoLocationManager.getLastLocation();
   } catch (err) {
       console.error("errCode:" + err.code + ",errMessage:" + err.message);
   }
   ```

   To call this method, your application needs to request the **ohos.permission.LOCATION** permission from the user.
